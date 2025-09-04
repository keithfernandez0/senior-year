## Module objectives: 
- By the end of the module:
	- Explain TCP/IP protocol attacks
	- Explain basics of IP addressing
	- Explain bin, oct, hex numbers
## Overview of TCP/IP
- **Protocol:** language used by computers to talk to each other
- **Transmission Control Protocol / Internet Protocol (TCP/IP):** combination of two protocols
	- Four distinct layers
		- Network
		- Internet
		- Transport
		- Application
## Application layer
- Protocols are the front-end to the lower-layer protocols in the TCP/IP stack
	- This layer is what you can see and touch
- Examples:
	- HTTPS
		- primary protocol to communicate over the web
	- FTP
		- allows file transfers across different OSs
	- SMTP
		- main protocol used to send email messages across the internet
	- SNMP
		- primary use for monitoring devices on a network
	- SSH
		- enables users to securely log on a remote server and issues commands
	- IRC
		- enables multiple users to communicate over the internet in forums
	- Telnet
		- enables users to insecurely log on to a remote server and issue command interactively
## Transport layer
- Encapsulates data into segments
	- Segments can use TCP or UDP to reach a destination host
		- TCP is **connection-oriented** --> the send doesn't send any day to the destination node until the destinate node acknowledges that it's listening the sender
- TCP **three-way handshake**:
	- **A** sends **B** a **SYN (synchronize)** packet
	- **B** replies with a **SYN-ACK** packet
	- **A** replies with an **ACK** (acknowledgement) packet
- Critical components of a TCP header:
	- TCP flags
	- Initial sequence number (ISN)
	- Source and destination port numbers
- Abused by hackers
	- To protect a network, you need to know the basic methods of hacking into networks
- TCP segment header composition:
	- Source port
	- Checksum
	- Reserved offset		
	- Destination port
	- Sequence number
	- Acknowledgment number (ACK)
	- Window
	- Urgent pointer
	- Options and padding
## TCP flags
-  Each flag occupies one bit of the TCP segment 
	- Can be set to 0 (off) or 1 (on) 
- Six flags of a TCP segment 
	- SYN flag: Synchronize flag signifies the beginning of a session 
	- ACK flag: Acknowledgment flag acknowledges a connection 
	- PSH flag: Push flag is used to deliver data directly to an application 
	- URG flag: Urgent flag signifies urgent data 
	- RST flag: Reset flag resets or drops a connection 
	- FIN flag: Finish flag signifies that the connection is finished 
## Initial sequence number
- ISN is 32 bits
	- Tracks packets received by a node
	- Allows reassembly of large packets that have been broken up into smaller packets
	- ISN is sent through steps one and two of the TCP three-way handshake
		- Sending node ISN is sent with SYN packet
		- Receiving node ISN is sent back to the sending node with SYN-ACK packet
## TCP ports
- TCP packets
	- Has two 16 bit fields
		- Contains source and destination port numbers
- Port 
	- Logical, not physical, component of a TCP connection
	- Can be assigned to a process that requires network connectivity
	- *Example: The HTTPS service uses port 443 by default.*
- Helps you stop or enable unnecessary services
	- The more services running on a server, the more ports are open for potential attack
- Only 1023 ports are considered well known
	- List of well known ports
		- Visit: www.iana.org
- Ports 20 and 21 
	- File Transfer Protocol (FTP)
	- Was the standard for moving or copying large files
		- Used today to a lesser extent because of the popularity of HTTP
	- Requires a logon name and password
	- More secure than Trivial File Transfer Protocol (TFTP)
- Ports 22
	- Secure Shell (SSH)
	- Uses encryption and authentication
		- To create a secure channel over an unsecure network
	- Used to secure logins, file transfers, and port forwarding 
	- FTP using SSH is known as SFTP
- Port 25
	- Simple Mail Transfer Protocol (SMTP)
		- Email servers listen in on this port
- Port 53 
	- Domain Name System (DNS)
		- Used to connect user to websites using URLs instead of IP addresses
		- Most networks require a DNS server
- Port 69 
	- Trivial File Transfer Protocol
		- Used for transferring router and backup router configurations
- Port 80
	- Hypertext Transfer Protocol (HTTP)
		- Used when connecting to a web server
- Port 143 
	- IMAP
	- Used by email client to retrieve email messages from a mail server over  aTCP / IP connection
- Port 443 
	- Secure HTTP (HTTPS)
		- Used when you connect to a web server
		- Typically reserved for secure connections
- Port 993
	- IMAP over SSL/TLS uses port 993 
	- Preferred over the unsecure IMAP, which uses port 143
- Port 110 
	- Post office protocol 3 (POP3)
		- Used for retrieving email messages from a mail server
- Port 119 
	- Network News Transfer Protocol 
		- Used to connect to a news server for use in newsgroups
- Port 135
	- Remote Procedure Call (RPC)
		- Critical for operation of MS Exchange Server and AD
- Port 139 
	- NetBIOS
		- Used by MS NetBIOS Session Service to share resources
- Port 143 
	- Internet Message Access Protocol 4 
		- IMAP4 uses this port to retrieve email
## User datagram protocol (UDP)
- Fast but unreliable delivery protocol
	- Operates on the transport layer
	- Used for its speed
		- Does not need to verify whether the receiver is listening or ready to accep the packets
	- UDP depends on higher layers of the TCP/IP stack to handle problems
	- Referred to as a **connectionless** protocol
## Internet layer
- Routes packets to a desination address
	- Uses a logical address (IP)
	- IP addressing packet delivery is connectionless
- **Internet control message protocol (ICMP)**
	- Sends messages related to network operations
	- Helps network professionals to troubleshoot network connectivity problems 
		- `ping` command
		- `traceroute` command 

| ICMP Type Code | Description                        |
| -------------- | ---------------------------------- |
| 0              | Echo reply                         |
| 3              | Destination unreachable            |
| 4              | Source quench                      |
| 5              | Redirect                           |
| 6              | Alternate host address             |
| 8              | Echo                               |
| 9              | Router advertisement               |
| 10             | Router solicitation                |
| 11             | Time exceeded                      |
| 12             | Parameter problem                  |
| 13             | Timestamp                          |
| 14             | Timestamp reply                    |
| 15             | Information request                |
| 16             | Information reply                  |
| 17             | Address mask Request               |
| 18             | Address Mask Reply                 |
| 19             | Reserved for security              |
| 20-29          | Reserved for robustness experiment |
| 30             | traceroute                         |
| 31             | datagram conversion error          |
| 32             | mobile host redirect               |
| 33             | IPv6 whereareyou                   |
| 34             | IPv6 iamhere                       |
| 35             | Mobile registration request        |
| 36             | Mobile registration reply          |
| 37             | domain name request                |
| 38             | domain name reply                  |
| 39             | skip                               |
| 40             | photuris                           |
| 41-225         | reserved                           |
