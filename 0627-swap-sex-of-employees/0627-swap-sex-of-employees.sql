/* Write your PL/SQL query statement below */

UPDATE SALARY SET SEX = CASE WHEN sex = 'f' THEN 'm' ELSE 'f'
END ;