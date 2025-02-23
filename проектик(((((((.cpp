﻿#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    srand(time(0));
    string poslnick;

    while (true) {
        system("cls");
        cout << "--------------------------------------------------------" << endl;
        cout << "Добро пожаловать на программу по генерации Никнеймов" << endl;
        cout << "--------------------------------------------------------" << endl << endl;
        cout << " - [ 1 ] -  Сгенерировать никнейм" << endl;
        cout << " - [ 2 ] - Сохранить никнейм" << endl;
        cout << " - [ 3 ] - Создать свой никнейм" << endl;
        cout << " - [ 4 ] - Просмотреть последние 5 никнеймов" << endl;
        cout << " - [ 5 ] - Готовые никнеймы" << endl;
        cout << " - [ 0 ] - Выход" << endl;
        cout << "Выберите действие: ";

        int opt;
        cin >> opt;
        cin.ignore(); // Очищаем своего рода "Буфер Обмена"

        if (opt == 0) {
            break;
        }

        if (opt == 1) {
            while (true) {
                system("cls");
                cout << "Выберите сколько частей будет в вашем никнейме" << endl;
                cout << "[1] 2 части" << endl;
                cout << "[2] 3 части" << endl;
                cout << "[0] Назад" << endl;
                cout << "Выберите вариант: ";

                int parts;             
                cin >> parts;           
                cin.ignore();

                if (parts == 0) {
                    break;
                }

                string pref[] = { "Проклятый", "Теневой", "Багровый", "Одержимый", "Нечестивый", "Грозовой", "Кровавый", "Безликий", "Искажённый", "Лунный", "Разрушительный", "Мистический", "Пылающий", "Хаотичный", "Арканный", "Мрачный", "Прокажённый", "Жестокий", "Бесконечный", "Обречённый" };
                string mid[] = { "Колдун", "Шаман", "Заклинатель", "Манипулятор", "Иллюзионист", "Разрушитель", "Проклинатель", "Оракул", "Некромант", "Хранитель", "Алхимик", "Ткач Барьеров", "Демонолог", "Палач", "Истерзанный", "Проводник", "Странник", "Ловец Душ", "Каратель", "Арбитр" };
                string suf[] = { "Бездны", "Разлома", "Тьмы", "Пустоты", "Разрушения", "Хаоса", "Легиона", "Ярости", "Омрачения", "Катастрофы", "Гнева", "Искажения", "Смерти", "Лунного Света", "Астрала", "Армагеддона", "Проклятия", "Заката", "Скверны", "Исчезновения" };

                if (parts == 1) {
                    poslnick = pref[rand() % 20] + " " + suf[rand() % 20]; // Генерация 2-частного никнейма
                }
                else if (parts == 2) {
                    poslnick = pref[rand() % 20] + " " + mid[rand() % 20] + " " + suf[rand() % 20]; // Генерация 3-частного никнейма
                }

                cout << "Ваш никнейм: " << poslnick << endl;
                system("pause");
            }
        }
        else if (opt == 2) {
            if (poslnick.empty()) {
                cout << "Сначала создайте никнейм!" << endl;
            }
            else {
                ofstream file("nicknames.txt", ios::app);
                file << poslnick << endl;
                file.close();
                cout << "Никнейм сохранён: " << poslnick << endl;
            }
            system("pause");
        }
        else if (opt == 3) {
            string part1 = "", part2 = "", part3 = "";

            while (true) {
                system("cls");
                cout << "--- Создание своего никнейма ---" << endl;
                cout << "[1] Выбрать первую часть" << endl;
                cout << "[2] Выбрать вторую часть" << endl;
                cout << "[3] Выбрать третью часть (необязательно)" << endl;
                cout << "[4] Просмотреть созданный никнейм" << endl;
                cout << "[0] Назад" << endl;
                cout << "Выберите вариант: ";

                int subopt;
                cin >> subopt;
                cin.ignore();


                if (subopt == 0) {
                    break;
                }

                if (subopt == 1) {
                    cout << "Выберите первую часть из списка:" << endl;
                    string opts[] = { "Проклятый", "Теневой", "Багровый", "Одержимый", "Нечестивый", "Грозовой", "Кровавый", "Безликий", "Искажённый", "Лунный" };
                    for (int i = 0; i < 10; i++) {  
                        cout << "[" << i + 1 << "] " << opts[i] << endl;  
                    }
                    cout << "[0] Назад" << endl;
                    int choice;
                    cin >> choice;
                    cin.ignore();
                    if (choice == 0) continue;
                    part1 = opts[choice - 1]; 
                }
                else if (subopt == 2) {
                    cout << "Выберите вторую часть из списка:" << endl;
                    string opts[] = { "Колдун", "Шаман", "Заклинатель", "Манипулятор", "Иллюзионист", "Разрушитель", "Проклинатель", "Оракул", "Некромант", "Хранитель" };
                    for (int i = 0; i < 10; i++) {
                        cout << "[" << i + 1 << "] " << opts[i] << endl;
                    }
                    cout << "[0] Назад" << endl;
                    int choice;
                    cin >> choice;
                    cin.ignore();
                    if (choice == 0) continue;
                    part2 = opts[choice - 1];
                }
                else if (subopt == 3) {
                    cout << "Выберите третью часть из списка:" << endl;
                    string opts[] = { "Бездны", "Разлома", "Тьмы", "Пустоты", "Разрушения", "Хаоса", "Легиона", "Ярости", "Омрачения", "Катастрофы" };
                    for (int i = 0; i < 10; i++) {
                        cout << "[" << i + 1 << "] " << opts[i] << endl;
                    }
                    cout << "[0] Назад" << endl;
                    int choice;
                    cin >> choice;
                    cin.ignore();
                    if (choice == 0) continue;
                    part3 = opts[choice - 1];
                }
                else if (subopt == 4) {
                    if (part1.empty() || part2.empty()) {
                        cout << "Вы должны выбрать хотя бы две части никнейма!" << endl;
                    }
                    else {
                        poslnick = part1 + " " + part2;
                        if (!part3.empty()) {     
                            poslnick += " " + part3;
                        }
                        cout << "Ваш созданный никнейм: " << poslnick << endl;
                    }
                }
                system("pause");
            }
        }
        else if (opt == 4) {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "        --- Последние 5 сохранённых никнеймов ---" << endl;
            cout << "--------------------------------------------------------" << endl;
            ifstream file("nicknames.txt");

            if (!file) {
                cout << "--------------------------------------------------------" << endl;
                cout << "         Сохранённые никнеймы не обнаруженны!" << endl;
                cout << "--------------------------------------------------------" << endl;
                system("pause");
                continue;
            }

            string nicknames[100];
            int count = 0;

            while (getline(file, nicknames[count]) && count < 100) {
                count++;   
            }

            file.close();

            if (count == 0) {
                cout << "--------------------------------------------------------" << endl;
                cout << "           У вас нету сохранённых никнеймов!" << endl;
                cout << "--------------------------------------------------------" << endl;
            }
            else {
                cout << "--------------------------------------------------------" << endl;
                cout << "            Просмотр сохранённых никнеймов" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "[ > Всего сохранённых никнеймов: [ " << count << " ]" << " < ]" << endl;

                int start = (count >= 5) ? count - 5 : 0;

                for (int i = start; i < count; i++) {
                    cout << " [" << (i - start + 1) << "] " << nicknames[i] << endl;
                }
            }

            system("pause");
        }
        else if (opt == 5) {
            system("cls");
            cout << "--------------------------------------------------------" << endl;
            cout << "                 --- Готовые никнеймы ---" << endl;
            cout << "--------------------------------------------------------" << endl;

            string readyNicknames[] = {
                // Никнеймы в стиле Jujutsu Kaisen
                "Проклятый Король", "Теневой Манипулятор", "Багровый Заклинатель", "Одержимый Колдун Бездны", "Разрушитель Проклятий",
                "Шаман Тьмы", "Грозовой Некромант", "Нечестивый Алхимик", "Оракул Легиона", "Арканный Иллюзионист",
                "Мистический Призыватель", "Палач Омрачения", "Заклинатель Разлома", "Экзорцист Катастрофы", "Пылающий Демонолог",
                "Хранитель Заката", "Странник Смерти", "Каратель Исчезновения", "Прокажённый Шаман", "Проклятый Властелин",
                "Одержимый Хранитель", "Лунный Волшебник", "Властелин Разрушения", "Манипулятор Барьеров", "Иллюзионист Бездны",

                // Никнеймы с отсылкой на Dota 2 (токсичные и мемные)
                "0-12 Мид", "Рошан Украден", "Лесной Спирит", "Бот-Гений", "5к ММР на Аркане",
                "Денди из 2013", "Рики на Миде", "Суппорт без Вардов", "Соло-Рошан", "Афк Лес",
                "Чел на ВР", "Пудж без Хуков", "Репорт Фидера", "Шторм на 7 Слотов", "Керри без Слотов",
                "Ластпик Течис", "Снайпер с Драгон Лансом", "Сларк 0-15", "Тиммейт на АП", "Скаймаг с Даггером",
                "Соло-Мипо", "Оракл на Керри", "Тинкер без Манты", "Саппорт Десераптор", "Единичка Огр"
            };

            int totalNicknames = sizeof(readyNicknames) / sizeof(readyNicknames[0]);
            int page = 0;
            const int perPage = 10;

            while (true) {
                system("cls");
                cout << "--------------------------------------------------------" << endl;
                cout << "                 --- Готовые никнеймы ---" << endl;
                cout << "--------------------------------------------------------" << endl;
                cout << "[ > Страница " << page + 1 << " из " << (totalNicknames / perPage + (totalNicknames % perPage != 0)) << " < ]" << endl;
                cout << "--------------------------------------------------------" << endl;

                int start = page * perPage;
                int end = min(start + perPage, totalNicknames);

                for (int i = start; i < end; i++) {
                    cout << " [" << (i - start + 1) << "] " << readyNicknames[i] << endl;
                }

                cout << "--------------------------------------------------------" << endl;
                cout << "[ N ] - Следующая страница" << endl;
                cout << "[ B ] - Предыдущая страница" << endl;
                cout << "[ 0 ] - Назад" << endl;
                cout << "Выберите действие: ";

                char action;               // Объявление переменной типа char для хранения одного символа
                cin >> action;             // Ввод одного символа с консоли
                cin.ignore();              // Очищаем буфер ввода


                if (action == '0') {
                    break;
                }
                else if ((action == 'N' || action == 'n') && end < totalNicknames) {
                    page++;
                }
                else if ((action == 'B' || action == 'b') && page > 0) {
                    page--;
                }
            }
        }

        else {
            cout << "--------------------------------------------------------" << endl;
            cout << "                НЕИЗВЕСТНАЯ КОМАНДА!" << endl;
            cout << "--------------------------------------------------------" << endl << endl;
            system("pause");
        }
    }
    return 0;
}