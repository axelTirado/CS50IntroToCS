select title from movies
join ratings  on movies.id = ratings.movie_id
join stars on movies.id = stars.movie_id
join people on stars.person_id = people.id
where name ="Chadwick Boseman"
order by rating
limit 5
