#include <iostream>
#include <Windows.h>
#include <cstdlib>
using namespace std;

int isLogged = false;
int value = 300;
int pinkod = 9999;
void hisob_toldirish();
void naqd_pul();
void pul_otkazma();
void balans();

void sorash();

void pin_kod()
{
  int pin;
  cout << "\nPin kodni kiriting:";
  cin >> pin;
  if (pin == pinkod)
  {
    cout << "Muvafaqqiyatli!";
    isLogged = true;
  }
  else
  {
    cout << "Muvafaqqiyatsiz!";
    isLogged = false;
    exit(0);
  }
}

int main()
{
  if (isLogged == false)
  {
    pin_kod();
  }
  system("clear");
  int choose;
  cout << "******************BANKOMAT**********************\n";
  cout << "\n\n";
  cout << "\tOperatsiyani tanlang:\n";
  cout << "1.Hisobni to'ldirish.\n";
  cout << "2.Naqd pul yechish.\n";
  cout << "3.Pul o'tkazma.\n";
  cout << "4.Balansni tekshirish.\n";
  cout << ">>";
  cin >> choose;
  switch (choose)
  {
  case 1:
    hisob_toldirish();
    break;
  case 2:
    naqd_pul();
    break;
  case 3:
    pul_otkazma();
    break;
  case 4:
    balans();
    break;
  default:
    cout << "Xato operatsiya!";
    pin_kod();
  }
}

void naqd_pul()
{
  int naqd, choose;
  system("clear");
  cout << "******************NAQD PUL YECHISH**********************\n";
  cout << "\n\n";
  cout << "Hozirgi hisobingiz: " << value << endl;
  cout << "Qancha miqdorda pul yechmoqchisiz >>";
  cin >> naqd;
  if (naqd > value)
  {
    cout << "Sizda uncha summa mavjud emas!";
    sorash();
  }
  else
  {
    value -= naqd;
    cout << naqd << " summa yechildi!\n";
    sorash();
  }
}
void hisob_toldirish()
{
  int t_sum, choose;
  system("clear");
  cout << "******************HISOBNI TO'LDIRISH**********************\n";
  cout << "\n\n";
  cout << "Summani kiriting >>";
  cin >> t_sum;
  value += t_sum;
  cout << "Hisobingiz " << t_sum << " ga to'ldirildi!\n";
  sorash();
}
void pul_otkazma()
{
  long int karta;
  int k_sum, len;
  system("clear");
  cout << "******************PUL O'TKAZMA**********************\n";
  cout << "\n\n";
  cout << "Qabul qiluvchi karta raqami >>";
  cin >> karta;
  for (len = 0; karta > 0; len++)
  {
    karta = karta / 10;
  }
  if (len == 16)
  {
    cout << "O'tkaziladigan summa >>";
    cin >> k_sum;
    if (k_sum > value)
    {
      cout << "Hisobingizda yetarli mablag' mavjud emas!";
      sorash();
    }
    else
    {
      value -= k_sum;
      system("clear");
      cout << "Tranzaksiya muvaffaqiyatli bajarildi!\n";
      sorash();
    }
  }
  else
  {
    cout << "Karta raqami 16ta raqamdan iborat bo'lishi kerak!";
    sorash();
  }
}
void balans()
{
  system("clear");
  cout << "******************BALANS**********************\n";
  cout << "\n\n";
  cout << "Balansingiz >> " << value << endl;
  sorash();
}

void sorash()
{
  int choose;
  cout << "\n\nBosh menuga qaytasizmi?\n";
  cout << "1.ha\n2.yo'q\n"
       << endl
       << ">>";
  cin >> choose;
  switch (choose)
  {
  case 1:
    main();
    break;
  case 2:
    exit(0);
    break;
  default:
    exit(0);
  }
}
