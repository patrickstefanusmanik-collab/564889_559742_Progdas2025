#include <iostream>
#include <string>
using namespace std;

// ================= USER =================
class User {
public:
    void ViewJadwal() {
        cout << "\nJadwal Pilates:" << endl;
        cout << "Senin - Jumat : 08.00 - 21.00" << endl;
        cout << "Sabtu - Minggu: 09.00 - 18.00" << endl;
    }

    void ViewPelatih() {
        cout << "\nDaftar Pelatih:" << endl;
        for (int i = 1; i <= 6; i++) {
            cout << "Pelatih " << i << endl;
        }
    }
};

// ================= MEMBER =================
class Member {
public:
    string nik;

    Member(string n = "") {
        nik = n;
    }

    void createAppointment(int trainerId) {
        cout << "Janji dengan pelatih " << trainerId << " berhasil dibuat." << endl;
    }
};

// ================= ADMIN =================
class Admin {
public:
    string username;
};

// ================= UI =================
class UIController {
public:
    int getUserInput() {
        int choice;
        cout << "\n===== MENU =====" << endl;
        cout << "1. Lihat Jadwal" << endl;
        cout << "2. Lihat Pelatih" << endl;
        cout << "3. Buat Janji" << endl;
        cout << "4. Login Admin" << endl;
        cout << "99. Keluar" << endl;
        cout << "Pilih: ";
        cin >> choice;
        return choice;
    }

    void trainerSchedule() {
        cout << "\nJadwal Pelatih:" << endl;
        for (int i = 1; i <= 6; i++) {
            cout << "Pelatih " << i << " tersedia" << endl;
        }
    }
};

// ================= MAIN =================
int main() {
    UIController ui;
    User user;

    bool running = true;

    while (running) {
        int choice = ui.getUserInput();

        switch (choice) {
        case 1:
            user.ViewJadwal();
            break;

        case 2:
            user.ViewPelatih();
            break;

        case 3: {
            string nik;
            cout << "Masukkan NIK (contoh: 123): ";
            cin >> nik;

            if (nik != "123") {
                cout << "NIK tidak terdaftar." << endl;
                break;
            }

            ui.trainerSchedule();
            int trainerId;
            cout << "Pilih pelatih [1-6]: ";
            cin >> trainerId;

            Member m(nik);
            m.createAppointment(trainerId);
            break;
        }

        case 4: {
            string u, p;
            cout << "Username: ";
            cin >> u;
            cout << "Password: ";
            cin >> p;

            if (u == "admin" && p == "admin") {
                cout << "Login admin berhasil." << endl;
            } else {
                cout << "Login gagal." << endl;
            }
            break;
        }

        case 99:
            cout << "Keluar program." << endl;
            running = false;
            break;

        default:
            cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}

