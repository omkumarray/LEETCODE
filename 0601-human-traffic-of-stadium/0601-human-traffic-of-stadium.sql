/* Write your PL/SQL query statement below */
select 
    distinct id, to_char(visit_date, 'yyyy-mm-dd') as visit_date, people
from (
    select id, visit_date, people,
        prior id,
        connect_by_root id as r,
        level,
        sum(level) over (partition by connect_by_root id) as t
    from (
        select *
        from stadium
        where people >= 100
    )
    connect by id = prior id - 1
)
where t >= 6
order by 1