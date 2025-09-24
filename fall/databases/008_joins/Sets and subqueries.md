## SET
- Intersect, union, minus
- MYSQL does not support intersect
- MYSQL does not support minus, except
## INTERSECT
- records that exist in both db1 and db2
- `select branchNo from Staff intersect select branchno in (select branchno from Branch)`
## UNION
- Allows us to combine two or more result sets from multiple tables into a single result set
- Rules
	- The number of cols that appears in the SELECT statement must be equal or have the same dimension
- UNION operator eliminates duplicate rows from the result even if we do not use DISTINCT
- To keep dupes, use UNION ALL
## Subqueries
- SQL can have embedded select statements
- subselect can be used in where and having clauses from an outermost select, called a nested query or subquery
- subselects may also appear in insert, update, and delete statements
- Returns employees who locate within the USA
	```sql
SELECT lastname, firstname FROM employees WHERE officeCode in (SELECT officeCode FROM offices WHERE country='USA')
	  ```
- Subqueries with operands
	- ANY
		- must have comparison operator
- comparison operators
	- =
	- >
	- <
	- >=
	- <=
	- <>
	- !=
- EXISTS and NOT EXISTS
	- only used for subqueries
	- produces a simple true or false 
	- true if and only if there exists at least one row in the result returned by the subquery
	- false if subquery returns empty
## Cartesian products and joins
- form cartesian product of the tables named in the from clause
- if there is a where clause, apply the search condition to each row of the product table, retaining those rows that satisfy the condition
- for each remaining row, determine the value of each item in the select list to produce a single row in each result table
- Follow the correct sequence
	- SELECT
	- FROM
	- WHERE
	- GROUP BY
	- HAVING