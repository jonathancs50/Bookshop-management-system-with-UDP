# Bookshop Management System with UDP
A Qt-based bookshop management system with two apps: one for tracking transactions, adding books/customers, and storing history; the other listens for and receives XML transaction data via UDP. Transactions are also saved to a text file for recovery.

## Project Description
- Bookshop Management Application: This application allows a bookshop to maintain a record of transactions, including details of books sold and customer information. Users can add new books to the inventory, register new customers, and keep track of purchases. The transaction history is stored in a text file, enabling the application to be restored to its previous state after a restart.
  
- Transaction Receiver Application: This companion application continuously listens for incoming transaction records sent via UDP. The bookshop management application can transmit an XML version of its transaction history, ensuring that records are backed up or shared with other systems.




## How to Install and Run the Project

### Prerequisites
- **Qt Creator**: Ensure you have [Qt Creator](https://www.qt.io/download) installed.
- **Qt Framework**: Install the Qt framework (appropriate version) via the Qt Maintenance Tool or the Qt installer.
- **CMake**: Install [CMake](https://cmake.org/download) if it's not already installed.

### Installation Steps

1. **Clone the Repository**
   ```bash
   git clone https://github.com/jonathancs50/Bookshop-management-system-with-UDP.git
   cd Bookshop-management-system-with-UDP
   ```

2. **Open the Project in Qt Creator**
   - Launch Qt Creator.
   - Go to `File` > `Open File or Project...`.
   - Navigate to the project directory and open the `CMakeLists.txt` file for the desired application (e.g., `BookshopApp/CMakeLists.txt` or `TransactionReceiver/CMakeLists.txt`).

3. **Configure the Project**
   - Qt Creator will prompt you to configure the project with CMake. Select the appropriate build kits and click `Configure Project`.
   - Ensure all required modules and dependencies are installed. Qt Creator will handle CMake configuration if set up correctly.

4. **Build the Project**
   - Click the `Build` button (hammer icon) or go to `Build` > `Build All` to compile the project.
   - Resolve any build issues if they arise (e.g., missing dependencies or configuration errors).

5. **Run the Project**
   - Click the `Run` button (green play icon) or go to `Build` > `Run` to start the application.
   - For the Bookshop Management App, you can now add books, customers, and manage transactions.
   - The Transaction Receiver App should be started separately to listen for incoming transaction data.

### Notes
- Ensure both applications are running if you are testing the data transfer functionality.
- For detailed setup or troubleshooting, refer to the [Qt documentation](https://doc.qt.io/qt-5/gettingstarted.html) and the [CMake documentation](https://cmake.org/documentation/).

---
