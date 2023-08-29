#include <mysql.h>
#include <math.h>

#include <stdio.h>

int main(void){
    // ket noi database
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    char *server = "localhost";
    char *user = "admin";
    char *password = "123456"; /* set me first */
    char *database = "Temp_db";

    conn = mysql_init(NULL);
    mysql_real_connect(conn,server,user,password,database,0,NULL,0); 
    // gui data xuong database
    int temp, humid;
    for (int i=0; i<20; i++){
        temp = rand()%21 + 30; // temp trong khoang (20,50)
        humid  = rand()%41 + 40;  // humid trong khoang (40,80)

        char sql[200];
        sprintf(sql,"insert into sensors(temp,humid) values (%d,%d)",temp, humid);
        // send SQL query 
        mysql_query(conn, sql);
    }
    mysql_close(conn);

    return 0;
}