## Alternative terminology for relational model
- a relation is a table
- a table is not necessarily a relation
---
## Basic SQL
- How does a user communicate with the database?
- SQL
	- Statements for data definitions, queries, and updates
	- Considered one of the major reasons for the commercial success of relational databases
- Each statement in SQL ends with a semicolon
- Different DBMSs might have different syntax
---
## Objectives
- Purpose and importance of SQL
- How to retrieve data from the database using `SELECT` and:
	- Use compound `WHERE` conditions
	- Sort query results with `ORDER BY` 
	- use aggregate functions
	- group data using `GROUP BY` and `HAVING`
- join tables together
	- perform set operations: `UNION`, `INTERSECT`, `EXCEPT`
	- how to update database using `INSERT`, `UPDATE`, `DELETE`
---
## SELECT statement with aggregates
- COUNT - returns number of values in column
- SUM - returns sum of values in col
- AVG - returns average
- MIN - returns smallest value
- MAX - returns highest value
- examples
	- MAX(salary), AVG(salary), COUNT(SID)

- Each operates on single cols
- COUNT, MIN, MAX apply to numeric and non-numeric 
- SUM, AVG are numeric only.
- `*` can be only used on COUNT()
- COUNT() counts all rows of a table, regardless of nulls or duplicate values
	- The result is different if count() on a col of NULLs
- Can use DISTINCT before col name to rid of dupes
- DISTINCT has no effect on MIN/MAX, but may effect SUM/AVG
- Aggregate functions can be used only in SELECT list and in HAVING clause
	- SELECT staffNo, COUNT(salary) FROM dreamhome.Staff;
	- SELECT COUNT(\*) AS myCount FROM dreamhome.PropertyForRent WHERE rent > 350;
---
## Restricted groupings - HAVING clause
- HAVING clause is designed for use with GROUP BY t restrict groups that appear in final result tab
- WHERE filters individual rows, whereas HAVING filters groups
- Column names in HAVING clause must also appear in the GROUP BY list or be contained within an aggregate function
```sql
SELECT branchNo, COUNT(staffNo) as myCount,
	  SUM(salary) as mySum
FROM dreamhome.Staff 
GROUP BY branchNo
HAVING COUNT(staffNo) > 1
ORDER BY branchNo;
  ```
---

