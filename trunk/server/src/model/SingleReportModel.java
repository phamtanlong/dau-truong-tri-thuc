/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package model;

import db.MySqlConnection_Rd;
import db.Utils.DataRow;
import db.Utils.DataTable;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.List;
import share.ShareConstants;

/**
 *
 * @author Mrkupi
 */
public final class SingleReportModel implements BaseModel{
    private List<UserModel> users;
    private static SingleReportModel inst;
    static
    {
        inst    =   new SingleReportModel();
    }
    
    public static SingleReportModel getInstance() {
        return inst;
    }
    
    private SingleReportModel() {
        getData();
    }

    @Override
    public void getData() {
        users           =   new ArrayList<>();
        
        DataTable dt    =   MySqlConnection_Rd.getInstance().selectCmdWhere(ShareConstants.TABLE_USER + ", " + ShareConstants.TABLE_SINGLERESULT, " USER.singleresultid = SINGLERESULT.singleresultid ", ShareConstants.USER_ID, ShareConstants.USER_NAME, 
                ShareConstants.USER_AVATAR, ShareConstants.USER_JEWELRY, ShareConstants.RESULT_WIN, ShareConstants.RESULT_LOSE, ShareConstants.RESULT_SCORE );
        if( dt != null && dt.size() > 0 ) {
            for( int i = 0; i < dt.size(); ++i ) {
                DataRow dr  =   dt.get( i );
                
                // Parse data to user
                UserModel userModel =   new UserModel();
                userModel.uid       =   dr.get( ShareConstants.USER_ID ).toString();
                userModel.name      =   dr.get( ShareConstants.USER_NAME ).toString();
                userModel.avatar    =   dr.get( ShareConstants.USER_AVATAR ).toString();
                userModel.jewelry   =   Integer.parseInt( dr.get( ShareConstants.USER_JEWELRY).toString() );
                userModel.singleResult.result.setWins( Integer.parseInt( dr.get(ShareConstants.RESULT_WIN).toString() ));
                userModel.singleResult.result.setLoses( Integer.parseInt( dr.get(ShareConstants.RESULT_LOSE).toString() ));
                userModel.singleResult.result.setScore( Integer.parseInt( dr.get(ShareConstants.RESULT_SCORE).toString() ));
                
                users.add(userModel);
            }
        }
        this.sort();
    }

    @Override
    public void parseData(Object data) {
    }

    @Override
    public String toData() {
        
        String dataStr      =   "";
        
        int nSize           =   users.size();
        List<UserModel> clone   =   new ArrayList<>(users);
        for( int i = 0; i < nSize; ++i ) {
            UserModel user       =   clone.get(i);
            String userStr;
            if( i < (nSize - 1) ) {
                userStr         =   String.format( "{ \"user\":\"%s\", \"order\":%s },", user.name, i );
            }
            else 
                userStr         =   String.format( "{ \"user\":\"%s\", \"order\":%s }", user.name, i );
            dataStr         +=  userStr;
        }
        
        dataStr             =   String.format( "{ \"list\":[ %s ]}", dataStr);
        
        return dataStr;
    }
    
    private void sort() {
        Collections.sort( users, new Comparator<UserModel>() {
            @Override 
            public int compare(UserModel um1, UserModel um2) {

                if(um1.singleResult.result.getScore() > um2.singleResult.result.getScore())
                    return -1;
                else if(um1.singleResult.result.getScore() < um2.singleResult.result.getScore())
                    return 1;
                else return 0;
            }
        });
    }
    
    synchronized public void addNewUser( UserModel userModel ) {
        this.users.add( userModel );
        this.sort();
    }
    
    synchronized public void updateUser( String userId, UserModel userModel ) {
        
        Boolean finded  =   false;
        for( int i = 0; i < this.users.size() && !finded; ++i ) {
            UserModel um    =   this.users.get(i);
            if( um.uid.equals( userId ) ) {
                finded  =   true;
                um.singleResult.result.setScore( userModel.singleResult.result.getScore() );
                um.singleResult.result.setWins( userModel.singleResult.result.getWins() );
                um.singleResult.result.setLoses( userModel.singleResult.result.getLoses() );
            }
        }
        
        // Re-sort leaderboard
        if( finded ) {
            this.sort();
        }
    }
}