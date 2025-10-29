## Objective
- Client-server architecture
- Advantages of DBMS
- Three-tier architecture for servers
---
## Client/Server
- Program relationship in which one program, the client, requests a service or resource from another program, the server
- Client and server must communicate, port numbers, protocols, etc.
- Example:
	- Webserver: google.com
	- Client: browser
	- httpd protocol, port 80 default
- A machine can be a server and a client at the same time
---
## Three-tier client-server
- Advantages
	- Thin client
	- Application maintenance centralized
	- Separates business logic from DB functions
---
## Middle-tier: application server and web server
- The application server or intermediate layer, is a web server between browser and the DB server
- It runs app. programs and sets business rules and functions such as login, take order, etc.
- Security functions
	- DB can be inside firewall and app. server is in DMZ
	- Integrity: only specific app. can access/modify the DB
---
# Web technology and DBMSs
## HTTP
- Protocol used to transfer Web pages thru internet
- based on request-response paradigm:
	- connection: client established connection with the web server
	- request: client sends request to web server
	- response: web server sends response (HTML doc) to client
	- close: closed by web server
---
## Uniform resource locators (URLs)
- defines where documents can be found
- urls consists of the following
	- protocol used for the connection
	- host name 
	- path name
- optionally
	- port through which connection to host should be made
	- file name, the content sent to the broswer
	- query string
---
## Web programming
- front end browser
	- GUI
	- Java, javascript, html, css, flash
- midde-end programs at web server
	- process, access data from DB
	- usually written in scripting lang.
	- PHP will be used
---
## Common Gateway Interface (CGI-bin)
- specifies where information between web server and a middle end is sent
	- web server only sends documents to where there is a listed destination
	- web server knows how to launch programs
	- web server sees the URL that points to a script, executes script and then sends back script output to the user's browser
	- users can interact with the web server via the cgi
- defines how scripts comm with web server
- designed to accept and return data
- advantages
	- defacto standard for interfacing web servers with external app.
	- simple
	- language independent
	- web server independence
	- wide usage
- disadvantages
	- comms between client and DB server must be thru web server
	- lack of efficiency and transaction support, difficult to validate user input
	- http never intended for long exchanges or interactivity
	- server has to generate new process thread for cgi script
---
## PHP arrays
- DB query results
	- 2D arrays
	- 1D represents rows of tables
	- 2D represents columns within a row
- Main types of array in PHP
	- numeric: index starts at zero
	- associative: pairs of key and its values
- PHP count() function: `count($result)`
---
