#include "head/transport.h"
#include "head/car.h"
#include "head/airplane.h"

void menu() {
    cout << "Меню:" << endl;
    cout << "1. Показать все транспортные средства" << endl;
    cout << "2. Добавить новое транспортное средство" << endl;
    cout << "3. Изменить характеристики" << endl;
    cout << "4. Определить новейшее транспортное средство" << endl;
    cout << "5. Выход" << endl;
    cout << "--------------------------------------------------------------------------" << endl;

}

int main() {
    vector<Transport*> transports;
    int choice;

    do {
        menu();
        cout << "Выберите действие: ";
        cin >> choice;
        cout << " " << endl;

        switch (choice) {
            case 1: { // показать весь транспорт
                if (transports.empty()) {
                    cout << "Список пуст!" << endl;
                } else {
                    for (auto& transport : transports) {
                    transport->show();
                    }
                }
                cout << "--------------------------------------------------------------------------" << endl;
                break;
            }
            case 2: { // добавить новый транспорт
                int type;
                cout << "Выберите тип нового транспорта (1 - Легковой автомобиль, 2 - Самолет): ";
                cin >> type;

                string name, brand;
                int year;
                cin.ignore();
                cout << "Введите наименование транспорта: ";
                getline(cin, name);
                cout << "Введите марку: ";
                getline(cin, brand);
                cout << "Введите год выпуска: ";
                cin >> year;

                if (type == 1) { // авто
                    int max_speed;
                    cout << "Введите максимальную скорость транспорта (км/ч): ";
                    cin >> max_speed;
                    transports.push_back(new Car(name, brand, year, max_speed));
                } else if (type == 2) { // самолет
                    int weight_transport;
                    cout << "Введите вес транспорта (тн): ";
                    cin >> weight_transport;
                    transports.push_back(new Airplane(name, brand, year, weight_transport));
                } else {
                    cout << "Неверно введено значение!" << endl;
                }
                cout << "--------------------------------------------------------------------------" << endl;
                break;
            }
            case 3: { // изменить характеристики
                size_t i;
                cout << "Введите индекс транспортного средства из списка (от 0 до " << transports.size()-1 << "): ";
                cin >> i;

                if (i >= transports.size()) {
                    cout << "Неверно введено значение!" << endl;
                    break;
                }

                if(dynamic_cast<Car*>(transports[i])) {
                    int new_speed;
                    cout << "Введите новую максимальную скорость транпсорта (км/ч): ";
                    cin >> new_speed;
                    dynamic_cast<Car*>(transports[i])->setSpeed(new_speed);
                } else if (dynamic_cast<Airplane*>(transports[i])) {
                    int new_weight_transport;
                    cout << "Введите новый вес транпсорта (тн): ";
                    cin >> new_weight_transport;
                    dynamic_cast<Airplane*>(transports[i])->setWeight(new_weight_transport);                   
                }
                cout << "--------------------------------------------------------------------------" << endl;
                break;
            }
            case 4: { // найти новейший транспорт
                Transport* newest = nullptr;
                int max_year = -1; // начальное значение для максимального года
                for (auto& transport : transports) {
                    if (transport->getYear() > max_year) {
                        max_year = transport->getYear();
                        newest = transport;
                    }
                }

                if (newest != nullptr) {
                    cout << "Новейший транспорт: " << endl;
                    cout << " " << endl;
                    newest->show();
                } else {
                    cout << "Неопределено!" << endl;
                }
                cout << "--------------------------------------------------------------------------" << endl;
                break;
            }
            case 5: // выход
                cout << "Заверешние работы программы..." << endl;
                break;
        }
    } while(choice != 5);  

    for (auto& transport : transports) {
        delete transport;
    }

    return 0;
}