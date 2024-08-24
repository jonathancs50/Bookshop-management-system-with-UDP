# Bookshop Management System with UDP
A Qt-based bookshop management system with two apps: one for tracking transactions, adding books/customers, and storing history; the other listens for and receives XML transaction data via UDP. Transactions are also saved to a text file for recovery.

##Project Description
- Bookshop Management Application: This application allows a bookshop to maintain a record of transactions, including details of books sold and customer information. Users can add new books to the inventory, register new customers, and keep track of purchases. The transaction history is stored in a text file, enabling the application to be restored to its previous state after a restart.
-Transaction Receiver Application: This companion application continuously listens for incoming transaction records sent via UDP. The bookshop management application can transmit an XML version of its transaction history, ensuring that records are backed up or shared with other systems.
