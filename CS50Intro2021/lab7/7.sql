select avg(energy) from songs where id in (select id from artists where name = "Drake");