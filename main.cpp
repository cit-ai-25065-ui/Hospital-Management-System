#include <iostream>
#include <vector>
#include <string>
using namespace std;

// الصنف الأساسي
class Person {
protected:
    int id;
    string name;

public:
    Person(int i, string n) {
        id = i;
        name = n;
    }

    int getId() { return id; }
    string getName() { return name; }

    virtual void showInfo() {
        cout << "ID: " << id << " | Name: " << name;
    }

    virtual ~Person() {}
};

// المريض يرث من Person
class Patient : public Person {
private:
    string illness;

public:
    Patient(int i, string n, string ill) : Person(i, n) {
        illness = ill;
    }

    void showInfo() override {
        cout << "Patient - ";
        Person::showInfo();
        cout << " | Illness: " << illness << endl;
    }
};

// الطبيب يرث من Person
class Doctor : public Person {
private:
    string specialty;

public:
    Doctor(int i, string n, string spec) : Person(i, n) {
        specialty = spec;
    }

    void showInfo() override {
        cout << "Doctor - ";
        Person::showInfo();
        cout << " | Specialty: " << specialty << endl;
    }
};

// صنف المواعيد
class Appointment {
public:
    int patientId;
    int doctorId;
    string date;

    Appointment(int p, int d, string dt) {
        patientId = p;
        doctorId = d;
        date = dt;
    }

    void showAppointment() {
        cout << "Patient ID: " << patientId
             << " | Doctor ID: " << doctorId
             << " | Date: " << date << endl;
    }
};

// إدارة المستشفى
class Hospital {
private:
    vector<Patient> patients;
    vector<Doctor> doctors;
    vector<Appointment> appointments;
    int nextPatientId = 1;
    int nextDoctorId = 1;

public:
    Hospital() {
        cout << "Welcome to Hospital Management System!\n";
    }

    ~Hospital() {
        cout << "Program ended.\n";
    }

    void addPatient() {
        string name, illness;

        cout << "Enter patient name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter illness: ";
        getline(cin, illness);

        patients.push_back(Patient(nextPatientId, name, illness));
        cout << "Patient added. ID = " << nextPatientId << endl;
        nextPatientId++;
    }

    void addDoctor() {
        string name, specialty;

        cout << "Enter doctor name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter specialty: ";
        getline(cin, specialty);

        doctors.push_back(Doctor(nextDoctorId, name, specialty));
        cout << "Doctor added. ID = " << nextDoctorId << endl;
        nextDoctorId++;
    }

    void showPatients() {
        if (patients.empty()) {
            cout << "No patients yet.\n";
            return;
        }

        for (int i = 0; i < patients.size(); i++) {
            patients[i].showInfo();
        }
    }

    void showDoctors() {
        if (doctors.empty()) {
            cout << "No doctors yet.\n";
            return;
        }

        for (int i = 0; i < doctors.size(); i++) {
            doctors[i].showInfo();
        }
    }

    // البحث برقم المريض
    void searchPatient(int id) {
        for (int i = 0; i < patients.size(); i++) {
            if (patients[i].getId() == id) {
                patients[i].showInfo();
                return;
            }
        }
        cout << "Patient not found.\n";
    }

    // البحث باسم المريض: هذا مثال على Function Overloading
    void searchPatient(string name) {
        for (int i = 0; i < patients.size(); i++) {
            if (patients[i].getName() == name) {
                patients[i].showInfo();
                return;
            }
        }
        cout << "Patient not found.\n";
    }

    void bookAppointment() {
        if (patients.empty() || doctors.empty()) {
            cout << "Add a patient and a doctor first.\n";
            return;
        }

        int p, d;
        string date;

        cout << "Enter patient ID: ";
        cin >> p;
        cout << "Enter doctor ID: ";
        cin >> d;
        cout << "Enter date (e.g. 1-11-2026): ";
        cin >> date;

        appointments.push_back(Appointment(p, d, date));
        cout << "Appointment booked!\n";
    }

    void showAppointments() {
        if (appointments.empty()) {
            cout << "No appointments yet.\n";
            return;
        }

        for (int i = 0; i < appointments.size(); i++) {
            appointments[i].showAppointment();
        }
    }

    void menu() {
        int choice;

        do {
            cout << "\n===== HOSPITAL MENU =====\n";
            cout << "1. Add Patient\n";
            cout << "2. Show Patients\n";
            cout << "3. Add Doctor\n";
            cout << "4. Show Doctors\n";
            cout << "5. Search Patient by ID\n";
            cout << "6. Search Patient by Name\n";
            cout << "7. Book Appointment\n";
            cout << "8. Show Appointments\n";
            cout << "0. Exit\n";
            cout << "Choose: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addPatient();
                    break;
                case 2:
                    showPatients();
                    break;
                case 3:
                    addDoctor();
                    break;
                case 4:
                    showDoctors();
                    break;
                case 5: {
                    int id;
                    cout << "Enter patient ID: ";
                    cin >> id;
                    searchPatient(id);
                    break;
                }
                case 6: {
                    string name;
                    cout << "Enter patient name: ";
                    cin >> ws;
                    getline(cin, name);
                    searchPatient(name);
                    break;
                }
                case 7:
                    bookAppointment();
                    break;
                case 8:
                    showAppointments();
                    break;
                case 0:
                    cout << "Goodbye!\n";
                    break;
                default:
                    cout << "Invalid choice.\n";
            }
        } while (choice != 0);
    }
};

int main() {
    Hospital hospital;
    hospital.menu();
    return 0;
}
