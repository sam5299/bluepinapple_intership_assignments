-- mysql assignment by Suresh Sir

create database customerdb;

create table customer(cid int  NOT NULL AUTO_INCREMENT,customerName varchar(20) NOT NULL,contactAddress varchar(30),address varchar(30),city varchar(30),postalCode int NOT NULL,country varchar(30) NOT NULL,reward_points int DEFAULT 0,PRIMARY KEY(cid));

insert into customer(customerName,contactAddress,address,city,postalCode,country) VALUES ("Amir Khanna","PJN Street","Near flower garden","Mumbai",100101,'India');
insert into customer(customerName,contactAddress,address,city,postalCode,country) VALUES ("Adam","abc A 37 Street","skagon1","Mexico",1234,'America');
insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Shahid Afridi","MFA chauk","stadium road","Lahor",4453,"Pakisthan",120);
insert into customer(customerName,contactAddress,address,city,postalCode,country) VALUES ("Peter Johnson","John Florida garden","Central Library","Florida",4323,'US');
insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Anubhav Singh","sardar chauk","rto corner","Bhatinda",5454,"India",12);
insert into customer(customerName,contactAddress,address,city,postalCode,country) VALUES ("Josh","63 Redcliffe Way","townside west","Woolmere Green",6062,'UK');
insert into customer(customerName,contactAddress,address,city,postalCode,country) VALUES ("Sato Shiori","461-1094, Shisachosatomen","Martins shopping","Matsura-shi",6341,'Japan');
insert into customer(customerName,contactAddress,address,city,postalCode,country) VALUES ("Maruyama Shin","461-1094 passing way","historical way","Matsura-shi",6341,'Japan');
insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Kailas Khair","Ch. Shivaji Road","Near CST","Mumbai",00012,"India",50);
insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Saurabh Shukla","FC road","New post office","Pune",200005,"India",30);
insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Mahesh Devkar","Dhankawadi road","Near bust stop","Pune",200012,"India",79);
insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Abdul Rehman","shemana-a/1","baridhara, gulshan","Dhaka",0112,"Bangladesh",69);
insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Shakib al hasan","level #9, tejgaon, 1215","east tejtury bazar","Dhaka",1215,"Bangladesh",69);
insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Sir garry","42 Dokki Street","Misr Insurance Building","Giza",032012,"Egypt",08);
insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Andres Folainca"," Central Spine","Grand Mall 6th Of October","Giza",032013,"Egypt",98);
insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Sergeo Marcina"," Spresstrasse 27","Schleswig-Holstein","Giza",24811,"Germany",100);
insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Raquile Mario"," Fasanenstrasse 32","Hamburg","Giza",82532,"Germany",09);
insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Sofia Sentino","Rua Ônix 173","Goiás","Aparecida De Goiânia",74969,"Brazil",88);
insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Ben Adam","Christianslundsvej 43","Region Midtjylland","Gjern",8883,"Denmark",24);

select * from customer;

select * from customer where country="India";

select * from customer where country="India" and city="Pune";

select * from customer where city="Berlin" or city="Mumbai";

select * from customer where country="India" and (city="Pune" or city="Bhatinda");

select * from customer where NOT country="Pakisthan";

select * from customer where NOT country="India" and NOT country="Bangladesh";

select * from customer where country="India" and NOT (city="Mumbai" or city="Pune");

insert into customer(customerName,contactAddress,address,city,postalCode,country,reward_points) VALUES ("Cordinal", "tom b street","skagen 21","mexico",44321,"Mexico",32);

insert into customer(customerName,city,postalCode,country) VALUES ("Febonacii","New York",14008,"America");

UPDATE customer SET customerName="Alfred schem",country="Mexico" where cid=2;

ALTER TABLE customer CHANGE contactAddress contactName varchar(30);

UPDATE customer SET contactName="Joun" where country="Mexico";

DELETE from customer where customerName ="Shakib al hasan";

select count(*) from customer;

SELECT AVG(reward_points) FROM customer where country="India";

SELECT SUM(reward_points) FROM customer WHERE country="India";

SELECT country,count(*) FROM customer GROUP BY country ORDER BY country;

SELECT country,city,count(*) AS total_customer FROM customer GROUP BY city,country ORDER BY country;

SELECT country,COUNT(*) FROM customer GROUP BY country HAVING COUNT(*) >= 2;

CREATE TABLE employee(eid INT NOT NULL AUTO_INCREMENT, ename varchar(30) NOT NULL,salary INT,dept_id INT,PRIMARY KEY(eid));

CREATE TABLE department(dept_id int NOT NULL auto_increment,dept_name varchar(30) NOT NULL,primary key(dept_id));

INSERT INTO department(dept_name) VALUES ("Testing");

INSERT INTO department(dept_name) VALUES ("Developement");

INSERT INTO department(dept_name) VALUES ("Finanace");

INSERT INTO department(dept_name) VALUES ("Marketing");

INSERT INTO department(dept_name) VALUES ("Sales");

INSERT INTO department(dept_name) VALUES ("Quality Assurance");

INSERT INTO department(dept_name) VALUES ("HR");

INSERT INTO department(dept_name) VALUES ("Account");


INSERT INTO employee(ename,salary,dept_id) VALUES ("Sameer Shinde",27000,2);

INSERT INTO employee(ename,salary,dept_id) VALUES ("Rajat Mishra",35000,3);

INSERT INTO employee(ename,salary,dept_id) VALUES ("Balaji Rao",50000,6);

INSERT INTO employee(ename,salary,dept_id) VALUES ("Vishawajit Raman",25000,1);

INSERT INTO employee(ename,salary,dept_id) VALUES ("Jyoti Nikam",26000,1);

INSERT INTO employee(ename,salary,dept_id) VALUES ("Sharad More",18000,4);

INSERT INTO employee(ename,salary,dept_id) VALUES ("Pragyan",14000,5);

INSERT INTO employee(ename,salary) VALUES ("InterEmp",8000);

SELECT e.eid,e.ename,e.salary,d.dept_name FROM employee e INNER JOIN department d ON e.dept_id = d.dept_id;

SELECT e.eid,e.ename,e.salary,d.dept_name FROM employee e LEFT JOIN department d ON e.dept_id = d.dept_id;

SELECT e.eid,e.ename,e.salary,d.dept_name FROM employee e RIGHT JOIN department d ON e.dept_id = d.dept_id;

SELECT * from employee LEFT JOIN department on employee.dept_id = department.dept_id UNION select * from employee RIGHT JOIN department ON employee.dept_id = department.dept_id;

