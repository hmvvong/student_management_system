#include <iostream>
#include <vector>
using namespace std;

class Student{
    private:
    int rollno, age;
    string name;

    public:
    Student(int stdRollno, string stdName, int stdAge){
        rollno = stdRollno;
        name = stdName;
        age = stdAge;
    }

    void setRollno(int stdRollno){
        rollno = stdRollno;
    }

    int getRollno(){
        return rollno;
    }

    void setName(string stdName){
        name = stdName;
    }

    string getName(){
        return name;
    }

    void setAge(int stdAge){
        age = stdAge;
    }

    int getAge(){
        return age;
    }

    void displayStudent(){
        cout<<"Roll No: "<<rollno<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Age: "<<age<<endl;
    }
};

void updateStudent(vector<Student>& students){
    string sname;
    bool found = false;
    int choice;

    cout<<"\t\tEnter Name to Update Record: "<<endl;
    cin.ignore();
    getline(cin, sname);

    for(int i=0; i<students.size(); i++){
        if(students[i].getName() == sname){
            found = true;
            cout<<"\t\t---------Student Found---------"<<endl;
            cout<<"\t\t1. Update Rollno"<<endl;
            cout<<"\t\t2. Update Name"<<endl;
            cout<<"\t\t3. Update Age"<<endl;
            cout<<"\t\tEnter Your Choice"<<endl;
            cin>>choice;

            switch(choice){
                case 1: 
                    {int rno;
                    cout<<"\t\tEnter New Rollno: "<<endl;
                    cin>>rno;
                    students[i].setRollno(rno);
                    cout<<"\t\tStudent Update Successfully"<<endl;
                    break;}
                case 2: 
                    {string name;
                    cout<<"\t\tEnter New Name: "<<endl;
                    cin.ignore();
                    getline(cin, name);
                    students[i].setName(name);
                    cout<<"\t\tStudent Update Successfully"<<endl;
                    break;}
                case 3: 
                    {int age;
                    cout<<"\t\tEnter New Age: "<<endl;
                    cin>>age;
                    students[i].setAge(age);
                    cout<<"\t\tStudent Update Successfully"<<endl;
                    break;}
                default:
                    cout<<"\t\tInvalid Number"<<endl;
            }
        }
        if(!found){
            cout<<"\t\tRecord Not Found"<<endl;
            return;
        }
    }
}

void SearchStudent(vector<Student>& students){
    int rollno;
    cout<<"\t\tEnter Rollno: "<<endl;
    cin>>rollno;

    for(int i=0; i<students.size(); i++){
        if(students[i].getRollno() == rollno){
            cout<<"\t\t---------Student Found---------"<<endl;
            students[i].displayStudent();
            return;
        }
    }
}

void DisplayAllStudent(vector<Student>& students){
    if(students.empty()){
        cout<<"\t\tNo Student Found"<<endl;
        return;
    }
    for(int i=0; i<students.size(); i++){
        students[i].displayStudent();
        cout<<endl;
    }
}

//Create function to add new student
void addNewStudent(vector<Student> &students){
    int rollno, age;
    string name;

    cout<<"Enter Rollno: ";
    cin>>rollno;

    //check if student already exist
    for(int i=0; i<students.size(); i++){
        if(students[i].getRollno() == rollno){
            cout<<"\t\tStudent Already Exist"<<endl;
            return;
        }
    }
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter Age: "; 
    cin>>age;

    Student newStudent(rollno, name, age);
    students.push_back(newStudent);

    cout<<"Student Add Successfully"<<endl;



}

void deleteStudent(vector<Student>& students){
    string name;
    cout<<"\t\tEnter Name to Delete: "<<endl;
    cin.ignore();
    getline(cin, name);

    for(int i=0; i<students.size(); i++){
        if(students[i].getName() == name){
            students.erase(students.begin()+i);
            cout<<"\t\tStudent Revome Successfully"<<endl;
            return;
        }
    }
    cout<<"\t\tStudent Not Found"<<endl;
}

int main(){
    vector<Student> students;
    students.push_back(Student(1, "Allen", 20));

    char choice;
    do{
        system("cls");
        int op;
        cout<<"\t\t--------------------------------"<<endl;
        cout<<"\t\tStudent Management System"<<endl;
        cout<<"\t\t--------------------------------"<<endl;

        cout<<"\t\t1. Add New Student"<<endl;
        cout<<"\t\t2. Display All Students"<<endl;
        cout<<"\t\t3. Search Student"<<endl;
        cout<<"\t\t4. Update Student"<<endl;
        cout<<"\t\t5. Delete Student"<<endl;
        cout<<"\t\t6. Exit"<<endl;
        cout<<"\t\tEnter Your Choice"<<endl;
        cin>>op;

        switch(op){
            case 1: 
                addNewStudent(students);
                break;
            case 2:
                DisplayAllStudent(students);
                break;
            case 3:
                SearchStudent(students);
                break;
            case 4:
                updateStudent(students);
                break;
            case 5:
                deleteStudent(students);
                break;
            case 6:
                exit(1);
            default:
                cout<<"\t\tInvalid Number"<<endl;
        }
        cout<<"\t\tDo You Want to Continue? [Y/N]";
        cin>>choice;
    }while(choice == 'y' || choice == 'Y');

    return 0;
}

