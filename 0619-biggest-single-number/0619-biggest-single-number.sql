/* Write your PL/SQL query statement below */
SELECT MAX(num) NUM
FROM (SELECT *
      FROM MYNUMBERS
      GROUP BY NUM
      HAVING COUNT(*) = 1  
    );
    