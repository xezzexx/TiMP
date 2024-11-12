#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip>

struct CallRecord {
    std::string lastName;     
    int duration;             
    double costPerMinute;     
};

void loadData(const std::string &filename, std::vector<CallRecord> &records) {
    std::ifstream file(filename); // чтение файла
    if (!file.is_open()) {
        std::cerr << "Ошибка при открытии файла!" << std::endl;
        return;
    }

    CallRecord record;
    while (file >> record.lastName >> record.duration >> record.costPerMinute) {
        records.push_back(record);
    }
    file.close();
    std::cout << "Данные успешно загружены из файла.\n";
}

void displayData(const std::vector<CallRecord> &records) {
    std::cout << std::left << std::setw(20) << "Фамилия" 
              << std::setw(20) << "Длительность (мин)" 
              << std::setw(20) << "Стоимость (руб/мин)" << std::endl;
    std::cout << std::string(60, '-') << std::endl;

    for (const auto &record : records) {
        std::cout << std::left << std::setw(20) << record.lastName 
                  << std::setw(20) << record.duration 
                  << std::setw(20) << std::fixed << std::setprecision(2) << record.costPerMinute
                  << std::endl;
    }
}

void editRecord(std::vector<CallRecord> &records, int index) {
    if (index < 0 || index >= records.size()) {
        std::cout << "Некорректный индекс." << std::endl;
        return;
    }
    std::cout << "Введите новую фамилию, длительность и стоимость за минуту: ";
    std::cin >> records[index].lastName >> records[index].duration >> records[index].costPerMinute;
    std::cout << "Запись обновлена." << std::endl;
}

double calculateTotalCost(const std::vector<CallRecord> &records) {
    double totalCost = 0.0;
    for (const auto &record : records) {
        totalCost += record.duration * record.costPerMinute;
    }
    return totalCost;
}

void saveData(const std::string &filename, const std::vector<CallRecord> &records) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Ошибка при сохранении файла!" << std::endl;
        return;
    }

    for (const auto &record : records) {
        file << record.lastName << " " 
             << record.duration << " " 
             << record.costPerMinute << std::endl;
    }
    file.close();
    std::cout << "Данные успешно сохранены в новый файл.\n";
}

int main() {
    std::vector<CallRecord> records;
    std::string filename;
    
    std::cout << "Введите имя файла для чтения данных: ";
    std::cin >> filename;
    loadData(filename, records);

    int choice;
    do {
        std::cout << "\nМеню:\n"
                  << "1. Просмотр данных\n"
                  << "2. Корректировка данных\n"
                  << "3. Вычислить стоимость всех разговоров\n"
                  << "4. Сохранить данные в новый файл\n"
                  << "0. Выход\n"
                  << "Выберите действие: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                displayData(records);
                break;
            case 2: {
                int index;
                std::cout << "Введите индекс записи для корректировки (начиная с 0): ";
                std::cin >> index;
                editRecord(records, index);
                break;
            }
            case 3: {
                double totalCost = calculateTotalCost(records);
                std::cout << "Общая стоимость всех разговоров: " << totalCost << " руб." << std::endl;
                break;
            }
            case 4: {
                std::string saveFilename;
                std::cout << "Введите имя файла для сохранения данных: ";
                std::cin >> saveFilename;
                saveData(saveFilename, records);
                break;
            }
            case 0:
                std::cout << "Выход из программы." << std::endl;
                break;
            default:
                std::cout << "Некорректный выбор. Попробуйте снова." << std::endl;
                break;
        }
    } while (choice != 0);

    return 0;
}