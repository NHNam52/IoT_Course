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
    // doc  data tu database
    mysql_query(conn, "select * from sensors");
    res = mysql_store_result(conn); // luu data vao bien res
    // int num_column = mysql_num_fields(res);  // luu so cot table vao bien num_column
	while (row = mysql_fetch_row(res)) 
	{ 
	    printf("%s \t %s \t %s \n",row[0], row[1],row[2]);
	}        



    mysql_close(conn);

    return 0;
}