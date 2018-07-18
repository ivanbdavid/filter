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

void ivans_main( std::vector<Student *> students ){
  int user_age;
  std::string user_sex;
  sex tmp;

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
  
  Filter fl;
  display(fl.filter_students(students, tmp, user_age));

}

/* IANS CODE BEGINS HERE 
 * is just to introduce the concept of "INTERFACES"
 * so instead of filter directly taking a "gender" and an "age" we can specify this as interfaces
 */

template <typename T>
class ISpecification{
public:

    virtual bool condition_is_fullfilled(T * t) = 0;
};

class AgeCondition : public ISpecification<Student>{
public:
    int innerAge;
    AgeCondition(int constructedAge) : innerAge{constructedAge} {}
    
    bool condition_is_fullfilled(Student *studentPointer) override {
      return (studentPointer->studentAge == innerAge);
    }
};

/*
  * the difference with this filter and the other one is that this filter 
  * takes any condition 
  * In short this code wont change easily, even if the number of things we are 
  * checking increase
  */
//template<typename U>
class FiterThatUsesInterfaces{
public:
  std::vector<Student *> successfulStudents;

  std::vector<Student *> interfaceFilter ( std::vector<Student *> allStudents, ISpecification<Student> &theCurrent){
     
     for (int i = 0; i < allStudents.size(); i++ ){
         if(theCurrent.condition_is_fullfilled(allStudents[i])){
            successfulStudents.push_back(allStudents[i]);
         }
     }

     return successfulStudents;
  }
};



void ians_main(std::vector<Student *> students){
  FiterThatUsesInterfaces iFilterWithThe;
  AgeCondition twentyseven(27);
  display(iFilterWithThe.interfaceFilter(students,twentyseven));  

} 

int main(){
  Student indexOne {"Anne", female, 27};
  Student indexTwo {"Jane", female, 21};
  Student indexThree {"John", male, 18};
  Student indexFour {"Joan", female, 23};
//  Put all students in one vector
  std::vector<Student *> studentList {&indexOne, &indexTwo, &indexThree, &indexFour};
  ivans_main(studentList);


  /* UNCOMMENT THIS AND COMMENT ivans_main TO SEE HOW IT WORKS*/
  // ians_main(studentList);

  // TOD0:(YOUR CHALLENGE) IMPLEMENT AN INTERFACE THAT FILTERS BASSED ON AGE 
  return 0;
}


