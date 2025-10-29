
## Objectives
- Evaluate functions of a DBMS
- Personnel involved in the DBMS environment
- Advantages and disadvantages of DBMS
---
## Examples of database applications
- Purchases from the supermarket
- Purchases with your credit card
---
## File based databases and processing
- Collection of application programs that perform services for the end users (ex: reports)
- Each program defines and manages its own data
- Example: MS Excel
---
## File-based processing of data
- Excel -- a file based data storage
	- Column, rows
	- Data types: integer. string, float
	- Cell variable: a1, b2, etc.
	- Cell functions: comparisions, computations, etc.
	- Programming: macros using VisualBasic
	- Worksheet
	- Table functions: search, replace, AVG, SUM, etc.
	- Security: can lock data at file level
	- Compare two data cells in two different worksheets
---
## Limitations of file-based approach
- Separation and isolation of data
	- Each program maintains its own set of data
	- Users of one program may be unaware of potentially useful data held by other programs
- Duplication of data
	- Same data is held by different programs
	- Wasted space and potentially different values and/or different formats for the same item
- Data dependence
	- File structure is defined in the rpogram code
- Incompatible file formats
	- Programs are written in different languages, cannot easily access each other's files
- Fixed queries/proliferation of application programs
	- Programs are written to satisfy particular functions
	- Any new requirement needs a new program
---
## Database approach
- Arose because:
	- Definition of data was embedded in application programs, rather than being stored separately and independently
	- No control over access and manipulation of data beyond that imposed by application programs
- Result
	- Database management system (DBMS)
---
## Databases
- Shared collection of logically related data with description, designed to meet the information needs of an organization
- System catalog (metadata) provides description of data to enable program-data independence
- Logically related data comprises entities, attributes, and relationships of an organization's information/
- A software system that enables users to define, create, maintain, and control access to the DB
- DB application program: a computer program that interacts with DB by issuing an appropriate request (SQL) to DBMS.
---
## Components of DBMS environment
- Machine
	- Hardware
		- Can range from a PC to a network of computers
	- Software
		- DBMS, operating system, network software, and also the application programs
- Bridge
	- Data
		- Used by the organization and a description of this data called the schema
- Human
	- Procedures
		- Instructions and rules that should be applied to the design and use of the databse and DBMS
	- People
		- Data administrator
		- Database administrator
		- Database designers (logical and physical)
		- Application programmers
		- End users (naive and sophisticated)
---
## Functions of a DBMS
- A user accesible catalogue
- Transaction support
- concurrency control services
- data storage, retrieval, and updates
- recovery services
- authorization services
- integrity services
- services to promote data independence
- utility services
---
## From Excel to a database
- A file --> a database
- A worksheet --> a table
- column --> attributes (age, name, gender, etc.)
- row --> records
- data type: integer, varchar, char, float, date, blob
- Working on multiple tables and databases at the same time 
	- Working --> join
- Programming: Structured Query Language (SQL)
	- Functions: comparisons, computation, etc
	- User and data access control
	- Data level (Data level manipulation language, DML): insert, delete, update
	- Table/structure level (data definition language, DDL): create, alter, drop
	- Privilege level (data control langyage, DCL): grant, revoke
- Macro --> stored procedure
- All these above functions need a powerful system
---
## Advantages of DBMSs
- Control of data redundancy
- data consistency
- more information from the same amount of data
- sharing of data
- improved data integrity
- improved security
- enforcement of standards
- economy of scale
- balance conflicting requirements
- improved data accessibility and responsiveness
- increased productivity
- improved maintenance through data independence
- increased concurrency
- improved backup and recovery services
---
## Disadvantages of DBMSs
- Why the below are disadvantages?
	- complexity
	-  size
	- cost of DBMS
	- additional hardware costs
	- costs of conversion
	- performance
	- higher impact of failure
