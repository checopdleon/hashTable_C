/* !!!!!!!!!!  DO NOT DELETE  !!!!!!!!!!!
   Author: Checo Sergio Ponce De Leon, checopdleon@gmail.com
   Edits/Additions: n/a
   Course: Computer Architecture
   Project: #1 "Personnel Management System"
   Last Edit: Mar. 2, 2018
   !!!!!!!!!!  DO NOT DELETE  !!!!!!!!!!!
 */

#include <stdio.h>
#include <assert.h>

int main () {

  int input; // user input
  int emplNumb;  // element key
  int totalEmps; // totalElements
  char emplName[25]; // element data

  do {
    puts("\n\n *****  Personnel Management System Program  *****\n-------------------------------------------------\n");
    puts("Enter:\n0 - to end program\n1 - to show all employees\n2 - total employees\n3 - add employee\n4 - remove employee");
    /* 1 is originally 4
       2 is originally 3
       3 is originally 1
       4 is originally 2*/

    scanf("%d", &input);

    assert(input >= 0 && input <5);

    if (input == 1) {
      //      print();
      puts("main reads 1");  //  ********************
    }
    else if (input == 2) {
      puts("main reads 2");  //  ********************
      //      printf("Total Employees: %d\n", totalElements() );
    }
    else if (input == 3) {
      puts("ADDING EMPLOYEE\n----------------\nEnter employee-number followed by employee-name:\nex: 1 John Doe");
      scanf("%d %s", &emplNumb, emplName);
      puts("main reads 3"); // **********************
      //      add(emplNumb, emplName);
    }
    else if (input == 4) {
      puts("REMOVING EMPLOYEE\n------------------\nEnter employee number: ");
      scanf("%d", &emplNumb);
      puts("main reads 4");
      //      delete(emplNumb);
    }

  } while (input != 0);

}
