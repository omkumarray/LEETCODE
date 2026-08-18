/* Write your PL/SQL query statement below */
select name as results
from (
    select u.name,
        dense_rank() over(order by count(m.user_id) desc, u.name asc) as rnk
    from MovieRating m
    inner join Users u
    on m.user_id = u.user_id 
    group by u.name
) 
where rnk = 1
union all
select title as results
from (
    select mo.title,
        dense_rank() over(order by avg(mr.rating) desc, mo.title asc) as rnk
    from MovieRating mr
    inner join Movies mo
    on mr.movie_id = mo.movie_id 
    where to_char(mr.created_at, 'MM-YYYY') = '02-2020'
    group by mo.title
)
where rnk = 1;