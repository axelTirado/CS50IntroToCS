select distinct name from people
join stars on people.id = stars.person_id
join movies on stars.movie_id = movies.id
Where title = "Toy Story"