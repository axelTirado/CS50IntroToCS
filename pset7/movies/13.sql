select distinct(name) from people
join stars on people.id = stars.person_id
join movies on stars.movie_id = movies.id
where title IN(select distinct(title) from people
join stars on people.id = stars.person_id
join movies on stars.movie_id = movies.id
where name = "Kevin Bacon" and birth = 1958) and name != "Kevin Bacon";