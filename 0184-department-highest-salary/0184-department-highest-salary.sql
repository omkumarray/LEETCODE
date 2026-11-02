# Write your MySQL query statement below
SELECT d1.name as Department,e1.name as Employee,e1.salary as Salary
 FROM Employee e1 LEFT JOIN Department d1 ON e1.departmentId=d1.id
WHERE (e1.departmentId,e1.salary) IN
(SELECT departmentId,MAX(salary) as S FROM Employee
GROUP BY departmentId
);