select title from people
join stars on people.id = stars.person_id
join movies on stars.movie_id = movies.id
where name = "Johnny Depp" and title IN(
select title FROM people
join stars on people.id = stars.person_id
join movies on stars.movie_id = movies.id
where name = "Helena Bonham Carter");