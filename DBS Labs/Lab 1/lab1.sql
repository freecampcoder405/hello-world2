SQL>  CREATE TABLE emp(
  2  emp_no number(5),
  3  emp_name varchar(15),
  4  emp_address varchar(40));

Table created.

SQL> insert into emp values(&emp_no,&emp_name,&emp_address);
Enter value for emp_no: 4
Enter value for emp_name: 'Ram'
Enter value for emp_address: 'Banglore'
old   1: insert into emp values(&emp_no,&emp_name,&emp_address)
new   1: insert into emp values(4,'Ram','Banglore')

1 row created.

SQL> insert into emp values(&emp_no,&emp_name,&emp_address);
Enter value for emp_no: 5
Enter value for emp_name: 'Joshua'
Enter value for emp_address: 'Manipal'
old   1: insert into emp values(&emp_no,&emp_name,&emp_address)
new   1: insert into emp values(5,'Joshua','Manipal')

1 row created.

SQL> insert into emp values(&emp_no,&emp_name,&emp_address);
Enter value for emp_no: 1
Enter value for emp_name: 'Mani'
Enter value for emp_address: 'Manipal'
old   1: insert into emp values(&emp_no,&emp_name,&emp_address)
new   1: insert into emp values(1,'Mani','Manipal')

1 row created.

SQL> insert into emp values(&emp_no,&emp_name,&emp_address);
Enter value for emp_no: 2
Enter value for emp_name: 'Sumit'
Enter value for emp_address: 'Mangalore'
old   1: insert into emp values(&emp_no,&emp_name,&emp_address)
new   1: insert into emp values(2,'Sumit','Mangalore')

1 row created.

SQL> insert into emp values(&emp_no,&emp_name,&emp_address);
Enter value for emp_no: 3
Enter value for emp_name: 'XAEX12'
Enter value for emp_address: 'Mangalore'
old   1: insert into emp values(&emp_no,&emp_name,&emp_address)
new   1: insert into emp values(3,'XAEX12','Mangalore')

1 row created.

SQL> SELECT emp_name FROM emp
  2  ;

EMP_NAME
---------------
Ram
Joshua
Mani
Sumit
XAEX12

SQL> SELECT * FROM emp WHERE emp_address='Manipal';

    EMP_NO EMP_NAME        EMP_ADDRESS
---------- --------------- ----------------------------------------
         5 Joshua          Manipal
         1 Mani            Manipal

SQL> ALTER TABLE emp ADD emp_salary number(7);

Table altered.

SQL> desc emp
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 EMP_NO                                             NUMBER(5)
 EMP_NAME                                           VARCHAR2(15)
 EMP_ADDRESS                                        VARCHAR2(40)
 EMP_SALARY                                         NUMBER(7)

SQL> UPDATE emp SET emp_salary=5000 WHERE emp_no IN (1,2,3);

3 rows updated.

SQL> UPDATE emp SET emp_salary=8000 WHERE emp_no IN (4,5);

2 rows updated.

SQL> DELETE FROM emp WHERE emp_address='Mangalore';

2 rows deleted.

SQL> select * from emp;

    EMP_NO EMP_NAME        EMP_ADDRESS                              EMP_SALARY
---------- --------------- ---------------------------------------- ----------
         4 Ram             Banglore                                       8000
         5 Joshua          Manipal                                        8000
         1 Mani            Manipal                                        5000


SQL> rename emp to emp1;

Table renamed.

SQL> desc emp
ERROR:
ORA-04043: object emp does not exist


SQL> desc emp1;
 Name                                      Null?    Type
 ----------------------------------------- -------- ----------------------------
 EMP_NO                                             NUMBER(5)
 EMP_NAME                                           VARCHAR2(15)
 EMP_ADDRESS                                        VARCHAR2(40)
 EMP_SALARY                                         NUMBER(7)

SQL> drop table emp1;

Table dropped.
