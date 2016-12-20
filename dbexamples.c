#include <stdio.h>
#include <sys/types.h>
#include <limits.h>
#include <db.h>
#include <fcntl.h>
#include <string.h>


main() {
    DBT key, value;
	DB mydb;
	char strkey[32], strval[32];
	DBTYPE type = DB_BTREE;
	int flags, mode= O_CREAT | O_RDWR ;
    char str[64];
	int counter=0;

	strcpy(strkey,"book");
	strcpy(strval,"libro");

    key.data = strkey;
    value.data = strval;
	mydb = dbopen("mydata.db", mode, type, NULL);
	(*mydb.put)(key, value);

}
