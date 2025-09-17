
#include<bits/stdc++.h>
using namespace std;

    struct Student{
        int roll;
        string name;
        string dept;
        float cgpa;
    };
    Student students[100];
    int countStudents = 0;
    const string FILE_NAME = "students.txt";
    /*Lowercase a string*/
    string toLowerCase(string str){
        for(char &c : str) c = tolower(c);
        return str;
    }
    /*Save all students to file*/
    void saveToFile(){
        ofstream myfile(FILE_NAME);
        for(int i = 0; i < countStudents; i++){
            myfile << students[i].roll << "|"
                   << students[i].name << "|"
                   << students[i].dept << "|"
                   << students[i].cgpa << "\n";
        }
        myfile.close();
    }
    /*loadfromfile*/
    void loadFromFile(){
        ifstream myreadfile(FILE_NAME);
        if(!myreadfile)return;
        countStudents = 0;
        string r , n , d , c;
        while(true){
            if(!getline(myreadfile , r , '|')) break;
            if(!getline(myreadfile , n , '|')) break;
            if(!getline(myreadfile , d , '|')) break;
            if(!getline(myreadfile , c )) break;
            Student s;
            s.roll = stoi(r);
            s.name = n;
            s.dept = d;
            s.cgpa = stof(c);
            students[countStudents++] = s;

        }
        myreadfile.close();
    }
    /*----ADD STUDENT----*/
    void addStudent(){
        if(countStudents >= 100){
            cout << "Can not add more Students\n";
            return;
        }
        Student s;
        cout << "Enter Roll : ";
        cin >> s.roll;
        cin.ignore();
        cout << "Enter Name : ";
       getline( cin , s.name);
        cout << "Enter Department : ";
        getline(cin , s.dept);
        cout << "Enter CGPA : ";
       cin >> s.cgpa;

        /*Check duplicate roll*/

        for(int i = 0; i<countStudents; i++){
            if(students[i].roll == s.roll){
                cout << "Roll Already Exists!\n";
                return;
            }
        }
        students[countStudents++] = s;
        saveToFile();
        cout << "Student Added.\n";

    }
    /*View Student*/
    void viewStudents(){
        if(countStudents == 0){
            cout << "No Records Found.\n";
            return;
        }
        cout << left << setw(10) << "Roll"
             << setw(15) << "Name"
             << setw(15) << "Dept"
             << setw(10) << "CGPA" <<"\n";
        cout << "-------------------------------------------------------\n";
        for(int i = 0; i < countStudents; i++){
            cout << left << setw(10)<< students[i].roll 
                 << setw(15) << students[i].name 
                 << setw(15) << students[i].dept 
                 << setw(10) << fixed << setprecision(2)<< students[i].cgpa
                 << "\n";
        }
    }
    
     /*Search By Roll*/
     void searchByRoll(){
        int roll;
        cout << "Enter Roll To Search: ";
        cin >> roll;
        for(int i = 0; i < countStudents; i++){
            if(students[i].roll == roll){
                cout << "Students Found!\n";
                cout << "Roll: " <<  students[i].roll
                     << "\nName: " << students[i].name
                     << "\nDept: " << students[i].dept
                     << "\nCGPA: " << students[i].cgpa <<"\n";
                     return;


            }
        }
        cout << "Students Not Found.\n";
     }
     /*Search by Name*/
     void searchByName(){
        string name;
        cin.ignore();
        cout << "Enter Name To Search: ";
        getline(cin , name);
        string searchName = toLowerCase(name);
        bool found = false;
        for(int i = 0; i < countStudents; i++){
            string studentName = toLowerCase(students[i].name);
            if(studentName.find(searchName) != string::npos){
                cout << "\nStudents Match Found!\n";
                cout << "Roll: "<< students[i].roll
                     << "\nName: "<< students[i].name
                     << "\nDept: "<< students[i].dept
                     << "\nCGPA: "<< students[i].cgpa << "\n";
                     found = true;

            }
        }
        if(!found){
            cout << "No Students Name Matches.\n";
        }
     }
     /*Search bt dept*/
     void searchByDept(){
        string dept;
        cin.ignore();
        cout << "Enter Department To Search: ";
        getline(cin , dept);
        string searchDept = toLowerCase(dept);
        bool found = false;
        for(int i = 0; i < countStudents; i++){
            string studentDept = toLowerCase(students[i].dept);
            if(studentDept.find(searchDept) != string::npos){
                cout <<"\nStudents Match Found!\n";
                cout << "Roll: "<< students[i].roll
                     << "\nName: "<< students[i].name
                     << "\nDept: "<< students[i].dept
                     << "\nCGPA: "<< students[i].cgpa << "\n";
                     found = true;
            }
        }
        if(!found){
            cout << "No Departments Match.\n";
        }
     }

   /*Update Students*/
   void updateStudent(){
    int roll;
    cout << "Enter Roll To Update: ";
    cin >> roll;
    cin.ignore();
    for(int i = 0; i < countStudents; i++){
        if(students[i].roll == roll){
            cout << "Enter New Roll: ";
            cin >> students[i].roll;
            cin.ignore();
            cout << "Enter New Name: ";
          getline( cin , students[i].name);
            cout << "Enter New Dept: ";
            getline(cin , students[i].dept);
            cout << "Enter New CGPA: ";
            cin >> students[i].cgpa;
            saveToFile();

            cout << "Record Updated.\n";
            return;
        }
    }
    cout << "Roll Not Found.\n";
   }
   /*Delete Student*/
   void deleteStudent(){
    int roll;
    cout << "Enter Roll To Delete: ";
    cin >> roll;
    for(int i = 0; i < countStudents; i++){
        if(students[i].roll == roll){
            for(int j = i; j < countStudents-1; j++){
                students[j] = students[j+1];

            }
            countStudents--;
            saveToFile();
            cout << "Record Deleted.\n";
            return;
        }
    }
    cout << "Roll Not Found.\n";
   }
   /*Sort by roll*/
   void sortByRoll(){
    for(int i = 0; i < countStudents-1; i++){
    for(int j = i+1; j < countStudents; j++){
    if(students[i].roll > students[j].roll){

    
    swap(students[i],students[j]);
   }
}
   }
   saveToFile();
   cout << "Students Sorted By Roll.\n";
}
/*Sort by cgpa*/
void sortByCGPA(){
    for(int i = 0; i < countStudents-1; i++){
        for(int j = i+1; j<countStudents; j++){
            if(students[i].cgpa > students[j].cgpa){
                swap(students[i],students[j]);
            }
        }
    }
    saveToFile();
    cout << "Students Sorted By CGPA.\n";
}
/*Merge*/
 void merge(Student arr[],int left, int mid, int right, string field , bool ascending){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    Student L[n1],R[n2];
    for(int i = 0; i < n1; i++) L[i] = arr[left+i];
    for(int j = 0; j < n2; j++) R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while(i < n1 && j < n2){
        if(field == "roll"){
            if(ascending){
                if(L[i].roll <= R[j].roll) arr[k++] = L[i++];
                else arr[k++] = R[j++];
            }else{
                if(L[i].roll >= R[j].roll) arr[k++] = L[i++];
                else arr[k++] = R[j++];
            }
        }
        else if(field == "cgpa"){
            if(ascending){
                if(L[i].cgpa <= R[j].cgpa) arr[k++] = L[i++];
                else arr[k++] = R[j++];
            }else{
                if(L[i].cgpa >= R[j].cgpa) arr[k++] = L[i++];
                else arr[k++] = R[j++];
            }
        }
        else if(field == "name"){
            if(ascending){
                if(L[i].name <= R[j].name) arr[k++] = L[i++];
                else arr[k++] = R[j++];
            }else{
                if(L[i].name >= R[j].name) arr[k++] = L[i++];
                else arr[k++] = R[j++];
            }
        }
       else if(field == "dept"){
            if(ascending){
                if(L[i].dept <= R[j].dept) arr[k++] = L[i++];
                else arr[k++] = R[j++];
            }else{
                if(L[i].dept >= R[j].dept) arr[k++] = L[i++];
                else arr[k++] = R[j++];
            }
        }

    }
    while(i < n1) arr[k++] = L[i++];
    while(j < n2) arr[k++] = R[j++];
 }
 /*Recursive  merge sort*/
 void mergeSort(Student arr[],int left,int right,string field, bool ascending){
    if(left < right){
        int mid = left + (right-left)/2;
        mergeSort(arr , left , mid , field , ascending);
        mergeSort(arr , mid + 1 , right , field , ascending);
        merge(arr , left , mid , right , field , ascending);

    }

 }
 /*wrapper function*/
      void sortStudents(string field , bool ascending){
        if(countStudents == 0){
            cout << "No Records Found.\n";
            return;
        }
        mergeSort(students , 0 , countStudents - 1 , field , ascending);
        saveToFile();
        cout << "Students Sorted by "<< field << " ";
        if(ascending){
            cout << "(Ascending) ";

        }else{
            cout << "(Descending) ";
        }
        cout << "Using Merge Sort.\n";
        viewStudents();
      }




    /*Main*/
    int main(){
        loadFromFile();
        while(true){
            cout << "\n==== Student Management System ====\n";
            cout << "1. Add Student\n";
            cout << "2. View Students\n";
            cout << "3. Search By Roll\n";
            cout << "4. Search By Name\n";
            cout << "5. Search By Department\n";
            cout << "6. Update Student\n";
            cout << "7. Delete Student\n";
            cout << "8. Sort By Roll (Ascending)\n";
            cout << "9. Sort By Roll (Descending)\n";
            cout << "10. Sort By CGPA (Ascending)\n";
            cout << "11. Sort By CGPA (Descending)\n";
            cout << "12. Sort By Name (A to Z)\n";
            cout << "13. Sort By Name (Z to A)\n";
            cout << "14. Sort By Department (A to Z)\n";
            cout << "15. Sort By Department (Z to A)\n";
            cout << "16. Exit\n";
            cout << "Enter Choice: ";
            int choice;
            cin >> choice;
            switch(choice){

            
      case 1: addStudent(); break;
      case 2: viewStudents(); break;
      case 3: searchByRoll(); break;
      case 4: searchByName(); break;
      case 5: searchByDept(); break;
      case 6: updateStudent(); break;
      case 7: deleteStudent(); break;
      case 8: sortStudents("roll", true); break;
      case 9: sortStudents("roll", false); break;
      case 10: sortStudents("cgpa", true); break;
      case 11: sortStudents("cgpa", false); break;
      case 12: sortStudents("name", true); break;
      case 13: sortStudents("name",false); break;
      case 14: sortStudents("dept",true); break;
      case 15: sortStudents("dept", false); break;
      case 16: cout <<"Bye!\n";

        return 0;

        default: cout << "Invalid Choice.\n";
            }
        }
    }














    