#include <iostream>
#include <vector>
#include <string>

enum sex {male, female};

class Student{
public:
  std::string studentName;
  sex studentSex;
  int studentAge;
};

class Filter{
public:
  std::vector <Student *> filterResults;
  std::vector <Student *> filter_students(std::vector <Student *> filterVector, sex a, int x){
    int count;
    for(count = 0; count <filterVector.size(); count++){
      if (filterVector[count] -> studentSex == a && filterVector[count] -> studentAge < x){
        filterResults.push_back(filterVector[count]);
      }
    }
    return filterResults;
  }
};

//Output the names of the students meeting the filter parameters
void display(std::vector <Student *> students){
  int i;
  for(i = 0; i < students.size(); i++){
    std::cout << students[i] -> studentName << std::endl;
  }
}

int main(){
  int user_age;
  std::string user_sex;
  sex tmp;

  Student indexOne {"Anne", female, 27};
  Student indexTwo {"Jane", female, 21};
  Student indexThree {"John", male, 18};
  Student indexFour {"Joan", female, 23};
//  Put all students in one vector
  std::vector<Student *> studentList {&indexOne, &indexTwo, &indexThree, &indexFour};

  std::cout << "Enter age: " << std::endl;
  std::cin >> user_age;
  ERR:
  std::cout << "Enter sex: " << std::endl;
  std::cin >> user_sex;

  if(user_sex == "male"){
    tmp = male;
  }else if (user_sex == "female"){
    tmp = female;
  }else {
    std::cout << "Hmm...\n";
    goto ERR;
  }
    //  placeholder:
    //   tmp = male;
    // break;
    // case fem:
    //   tmp = female;
    // break;
    // default:
    //   std::cout << "Wrong input!";
    //   goto ERR;
    //

    // }


  // Testing testing 123
  Filter fl;
  display(fl.filter_students(studentList, tmp, user_age));

  return 0;
}
