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