#Project Description

Description:
 ● Developing a C++ program that calculates the total resistance of an
 electrical circuit based on a user-provided string description. The electrical
 circuit will be described as One String, where the type of connection between
 resistors is represented by either 'S' (Series) or 'P' (Parallel).
 ● For example, the user input: S 1 2 3 e describes the following circuit:
 ![{80A03430-E877-4104-859C-52775756BE1B}](https://github.com/user-attachments/assets/159423ad-39f3-4c00-85a3-a4980e8b3c8a)
 
 ● Resistor value will be integer or float number.
 ● Types of electrical circuit :
 1- Series (will be represented as S or s )
 2- Parallel (will be represented as P or p )
 ● It is guaranteed that each connection will end by e (ex:S11e)

App Features:
 1. Enable users to input electrical circuit configurations using one string
 representation.
 (The input is one string only)
 2. TheCircuit Analyzer must handle electrical circuit that has up to
 12 resistors.
 3. TheCircuit Analyzer must handle 1 Parent type of electrical circuit with
 multiple childs connections, As we can replace 1 resistor value by a
 connection.
 (ex: P 1 2 S 1 1 e e Act as P 1 2 2 e )

 4. Error handling:

 --The Program checks the number of resistors,for **Series**
 connection it must have 1 resistor or more,for **Parallel** connection
 it must have 2 resistors or more,otherwise print error message “IncorrectInput”.

 --Program checks that the only accepted connection is S or P,
 otherwise print the error message “WrongDescription”.
 
 ● Different Test cases that program can handle:
 ![{EC978D30-724E-4C44-92FD-63403489B6F4}](https://github.com/user-attachments/assets/1139b053-c2a4-440d-b092-778b1cd7f09e)
