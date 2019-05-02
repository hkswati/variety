#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]){
  
  int a = atoi(argv[1]);
  int b  = atoi(argv[2]);
  printf("Initial value of a: %d\n", a);
  printf("Initial value of b: %d\n", b);
  a = a+b;
  b = a-b;
  a = a-b;
  printf("Swapped value of a: %d\n", a);
  printf("Swapped value of b: %d\n", b);
  
}



/*SQL queries:
SELECT COUNT(*)
FROM (SELECT userId, COUNT(userId) AS login_count
	  FROM 	i_user_login_logs
	  GROUP BY userId
	  HAVING login_count > 3);



SELECT username, emailaddress
FROM i_users
WHERE userId in (SELECT userId, MAX(login_count)
		 FROM (SELECT userId, COUNT(userId) AS login_count
	  		FROM 	i_user_login_logs
	  		GROUP BY userId));
*/              
              
