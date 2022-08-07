#include <iostream>
#include <string>
#include <fstream>

using namespace std;
int i = 0;

struct Book
{
    string Ime, Avtor, Data;
    int K_nomer = 0, Br_knigi = 0, Br_zaemaniq = 0, Nalichnost = 0;
    float Cena = 0;
    bool Zaet = false;
};

void DobaviKniga(Book kniga[100], int& Br)
{
    cout << "Katalojen nomer na kniga[" << i + 1 << "]: ";
    cin >> kniga[i].K_nomer;
    while (kniga[i].K_nomer <= 0)
    {
        cout << "Molq vuvedete pravilen katalojen nomer \n";
        cout << "Katalojen nomer na kniga[" << i + 1 << "]: ";
        cin >> kniga[i].K_nomer;
    }
    for (int k = 0; k < i; k++)
    {
        while (kniga[i].K_nomer == kniga[k].K_nomer)
        {
            cout << "Kniga s tozi katalojen nomer veche sushtestvuva \n\n";
            cout << "Katalojen nomer na kniga[" << i + 1 << "]: ";
            cin >> kniga[i].K_nomer;
        }
    }
    cout << "Cena na kniga[" << i + 1 << "]: ";
    cin >> kniga[i].Cena;
    cin.ignore();
    cout << "Ime na kniga[" << i + 1 << "]: ";
    getline(cin, kniga[i].Ime);
    for (int k = 0; k < i; k++)
    {
        while (kniga[i].Ime == kniga[k].Ime)
        {
            cout << "Kniga s tova ime veche sushtestvuva \n\n";
            cout << "Ime na kniga[" << i + 1 << "]: ";
            getline(cin, kniga[i].Ime);
        }
    }
    cout << "Avtor na kniga[" << i + 1 << "]: ";
    getline(cin, kniga[i].Avtor);
    cout << "Broika na kniga[" << i + 1 << "]: ";
    cin >> kniga[i].Br_knigi;
    cout << "Broi zaemaniq na kniga[" << i + 1 << "]: ";
    cin >> kniga[i].Br_zaemaniq;
    cout << "Nalichnost na kniga[" << i + 1 << "]: ";
    cin >> kniga[i].Nalichnost;
    while (kniga[i].Nalichnost < 0 || kniga[i].Nalichnost > 5)
    {
        cout << "Nalichnostta trqbwa da bude mejdu 0 i 5 \n";
        cout << "Molq vuvedete nalichnost na knigata: ";
        cin >> kniga[i].Nalichnost;
    }
    cin.ignore();
    cout << "Data na kniga[" << i + 1 << "]: ";
    getline(cin, kniga[i].Data);
    cout << "\n";
    Br++;
    i++;
}
void DobaviMnogoKnigi(Book kniga[100], int& Br, int N)
{
    cout << "\tKolko na broi knigi iskate da dobavite ?\n";
    cout << "\tVashiqt izbor: ";
    cin >> N; cout << "\n";
    while (N <= 0 || N >= 100)
    {
        cout << "Molq vuvedete broi mejdu 1 i 100 \n";
        cout << "Vashiqt izbor: ";
        cin >> N;
    }
    for (int k = 0; k < N; k++)
    {
        DobaviKniga(kniga, Br);
    }
}
void BubbleSort(Book kniga[100], int& Br, float& MinCena, string& MinIme)
{
    for (int l = Br; l >= 1; l--)
    {
        for (int m = 0; m < l - 1; m++)
        {
            if (kniga[m].Cena > kniga[m + 1].Cena)
            {
                MinCena = kniga[m].Cena;
                kniga[m].Cena = kniga[m + 1].Cena;
                kniga[m + 1].Cena = MinCena;
                MinIme = kniga[m].Ime;
                kniga[m].Ime = kniga[m + 1].Ime;
                kniga[m + 1].Ime = MinIme;
            }
        }
    }
    for (int n = 0; n < Br; n++)
    {
        cout << "kniga " << kniga[n].Ime << ": " << kniga[n].Cena << "lv \n";
    }
}
void SortPoAvtor(Book kniga[100], int& Br)
{
    string Avtor, Kniga;
    for (int l = Br; l > 1; l--)
    {
        for (int k = 0; k < l - 1; k++)
        {
            if (kniga[k].Avtor > kniga[k + 1].Avtor)
            {
                Avtor = kniga[k].Avtor;
                kniga[k].Avtor = kniga[k + 1].Avtor;
                kniga[k + 1].Avtor = Avtor;
                Kniga = kniga[k].Ime;
                kniga[k].Ime = kniga[k + 1].Ime;
                kniga[k + 1].Ime = Kniga;
            }
        }
    }
    int nomer = 1;
    for (int k = 0; k < Br; k++)
    {
        cout << nomer << ". " << kniga[k].Avtor << ": " << kniga[k].Ime << "\n";
        nomer++;
    }
    cout << "\n";
}
void SortPoData(Book kniga[100], int& Br)
{
    string Avtor, Kniga, Data, d, dd, m, mm, y, yy;
    for (int l = Br; l > 1; l--)
    {
        for (int k = 0; k < l - 1; k++)
        {
            d = kniga[k].Data.substr(0, 2);
            dd = kniga[k + 1].Data.substr(0, 2);
            m = kniga[k].Data.substr(4, 6);
            mm = kniga[k + 1].Data.substr(4, 6);
            y = kniga[k].Data.substr(7, 10);
            yy = kniga[k + 1].Data.substr(7, 10);
            if (y > yy)
            {
            }
            else if (y == yy)
            {
                if (m > mm)
                {
                }
                else if (m == mm)
                {
                    if (d > dd)
                    {
                    }
                    else if (d == dd)
                    {
                    }
                    else
                    {
                        Avtor = kniga[k].Avtor;
                        kniga[k].Avtor = kniga[k + 1].Avtor;
                        kniga[k + 1].Avtor = Avtor;
                        Kniga = kniga[k].Ime;
                        kniga[k].Ime = kniga[k + 1].Ime;
                        kniga[k + 1].Ime = Kniga;
                        Data = kniga[k].Data;
                        kniga[k].Data = kniga[k + 1].Data;
                        kniga[k + 1].Data = Data;
                    }
                }
                else
                {
                    Avtor = kniga[k].Avtor;
                    kniga[k].Avtor = kniga[k + 1].Avtor;
                    kniga[k + 1].Avtor = Avtor;
                    Kniga = kniga[k].Ime;
                    kniga[k].Ime = kniga[k + 1].Ime;
                    kniga[k + 1].Ime = Kniga;
                    Data = kniga[k].Data;
                    kniga[k].Data = kniga[k + 1].Data;
                    kniga[k + 1].Data = Data;
                }
            }
            else
            {
                Avtor = kniga[k].Avtor;
                kniga[k].Avtor = kniga[k + 1].Avtor;
                kniga[k + 1].Avtor = Avtor;
                Kniga = kniga[k].Ime;
                kniga[k].Ime = kniga[k + 1].Ime;
                kniga[k + 1].Ime = Kniga;
                Data = kniga[k].Data;
                kniga[k].Data = kniga[k + 1].Data;
                kniga[k + 1].Data = Data;
            }
        }
    }
    int nomer = 1;
    for (int k = 0; k < Br; k++)
    {
        cout << nomer << ". " << kniga[k].Avtor << ": " << kniga[k].Ime << " s data " << kniga[k].Data << "\n";
        nomer++;
    }
    cout << "\n";
}
void SortPoBrZaemaniqIAvtor(Book kniga[100], int& Br)
{
    string Avtor, Kniga, Ime;
    int Br_Avtor = 0, Br_Zaemaniq = 0;
    for (int l = Br; l > 1; l--)
    {
        for (int k = 0; k < l - 1; k++)
        {
            if (kniga[k].Avtor > kniga[k + 1].Avtor)
            {
                Ime = kniga[k].Avtor;
                kniga[k].Avtor = kniga[k + 1].Avtor;
                kniga[k + 1].Avtor = Ime;
                Br_Zaemaniq = kniga[k].Br_zaemaniq;
                kniga[k].Br_zaemaniq = kniga[k + 1].Br_zaemaniq;
                kniga[k + 1].Br_zaemaniq = Br_Zaemaniq;
                Kniga = kniga[k].Ime;
                kniga[k].Ime = kniga[k + 1].Ime;
                kniga[k + 1].Ime = Kniga;
            }
        }
    }
    for (int l = Br; l > 1; l--)
    {
        for (int k = 0; k < l - 1; k++)
        {
            if (kniga[k].Avtor > kniga[k + 1].Avtor && kniga[k].Br_zaemaniq < kniga[k + 1].Br_zaemaniq)
            {
                Ime = kniga[k].Avtor;
                kniga[k].Avtor = kniga[k + 1].Avtor;
                kniga[k + 1].Avtor = Ime;
                Br_Zaemaniq = kniga[k].Br_zaemaniq;
                kniga[k].Br_zaemaniq = kniga[k + 1].Br_zaemaniq;
                kniga[k + 1].Br_zaemaniq = Br_Zaemaniq;
                Kniga = kniga[k].Ime;
                kniga[k].Ime = kniga[k + 1].Ime;
                kniga[k + 1].Ime = Kniga;
            }
        }
    }
    int nomer = 1;
    for (int k = 0; k < Br; k++)
    {
        if (Br > 0)
        {
            cout << "\t" << nomer << ". " << kniga[k].Avtor << ": " << kniga[k].Ime << ", s broi zaemaniq:" << kniga[k].Br_zaemaniq << "\n";
            nomer++;
        }
        else
        {
            cout << "\t Nqma takuv avtor";
            break;
        }
    }
    Br_Avtor = 0;
    cout << "\n";
}
void SortPoBrZaemaniqIData(Book kniga[100], int& Br)
{
    string Avtor, Kniga, Ime, Data, d, dd, m, mm, y, yy;
    int Br_Avtor = 0, Br_Zaemaniq = 0;
    for (int l = Br; l > 1; l--)
    {
        for (int k = 0; k < l - 1; k++)
        {
            if (kniga[k].Br_zaemaniq < kniga[k + 1].Br_zaemaniq)
            {
                Ime = kniga[k].Avtor;
                kniga[k].Avtor = kniga[k + 1].Avtor;
                kniga[k + 1].Avtor = Ime;
                Br_Zaemaniq = kniga[k].Br_zaemaniq;
                kniga[k].Br_zaemaniq = kniga[k + 1].Br_zaemaniq;
                kniga[k + 1].Br_zaemaniq = Br_Zaemaniq;
                Kniga = kniga[k].Ime;
                kniga[k].Ime = kniga[k + 1].Ime;
                kniga[k + 1].Ime = Kniga;
            }
        }
    }
    for (int l = Br; l > 1; l--)
    {
        for (int k = 0; k < l - 1; k++)
        {
            d = kniga[k].Data.substr(0, 2);
            dd = kniga[k + 1].Data.substr(0, 2);
            m = kniga[k].Data.substr(4, 6);
            mm = kniga[k + 1].Data.substr(4, 6);
            y = kniga[k].Data.substr(7, 10);
            yy = kniga[k + 1].Data.substr(7, 10);
            if (y > yy && kniga[k].Br_zaemaniq < kniga[k + 1].Br_zaemaniq)
            {
            }
            else if (y == yy && kniga[k].Br_zaemaniq < kniga[k + 1].Br_zaemaniq)
            {
                if (m > mm && kniga[k].Br_zaemaniq < kniga[k + 1].Br_zaemaniq)
                {
                }
                else if (m == mm && kniga[k].Br_zaemaniq < kniga[k + 1].Br_zaemaniq)
                {
                    if (d > dd && kniga[k].Br_zaemaniq < kniga[k + 1].Br_zaemaniq)
                    {
                    }
                    else if (d == dd && kniga[k].Br_zaemaniq < kniga[k + 1].Br_zaemaniq)
                    {
                    }
                    else
                    {
                        Avtor = kniga[k].Avtor;
                        kniga[k].Avtor = kniga[k + 1].Avtor;
                        kniga[k + 1].Avtor = Avtor;
                        Kniga = kniga[k].Ime;
                        kniga[k].Ime = kniga[k + 1].Ime;
                        kniga[k + 1].Ime = Kniga;
                        Data = kniga[k].Data;
                        kniga[k].Data = kniga[k + 1].Data;
                        kniga[k + 1].Data = Data;
                        Br_Zaemaniq = kniga[k].Br_zaemaniq;
                        kniga[k].Br_zaemaniq = kniga[k + 1].Br_zaemaniq;
                        kniga[k + 1].Br_zaemaniq = Br_Zaemaniq;
                    }
                }
                else
                {
                    Avtor = kniga[k].Avtor;
                    kniga[k].Avtor = kniga[k + 1].Avtor;
                    kniga[k + 1].Avtor = Avtor;
                    Kniga = kniga[k].Ime;
                    kniga[k].Ime = kniga[k + 1].Ime;
                    kniga[k + 1].Ime = Kniga;
                    Data = kniga[k].Data;
                    kniga[k].Data = kniga[k + 1].Data;
                    kniga[k + 1].Data = Data;
                    Br_Zaemaniq = kniga[k].Br_zaemaniq;
                    kniga[k].Br_zaemaniq = kniga[k + 1].Br_zaemaniq;
                    kniga[k + 1].Br_zaemaniq = Br_Zaemaniq;
                }
            }
            else
            {
                Avtor = kniga[k].Avtor;
                kniga[k].Avtor = kniga[k + 1].Avtor;
                kniga[k + 1].Avtor = Avtor;
                Kniga = kniga[k].Ime;
                kniga[k].Ime = kniga[k + 1].Ime;
                kniga[k + 1].Ime = Kniga;
                Data = kniga[k].Data;
                kniga[k].Data = kniga[k + 1].Data;
                kniga[k + 1].Data = Data;
                Br_Zaemaniq = kniga[k].Br_zaemaniq;
                kniga[k].Br_zaemaniq = kniga[k + 1].Br_zaemaniq;
                kniga[k + 1].Br_zaemaniq = Br_Zaemaniq;
            }
        }
    }
    int nomer = 1;
    for (int k = 0; k < Br; k++)
    {
        if (Br > 0)
        {
            cout << "\t" << nomer << ". " << kniga[k].Ime << ", s broi zaemaniq:" << kniga[k].Br_zaemaniq << " i data: " << kniga[k].Data << "\n";
            nomer++;
        }
        else
        {
            cout << "\t Nqma takuv avtor";
            break;
        }
    }
    Br_Avtor = 0;
    cout << "\n";
}
int IzvediPoAvtor(Book kniga[100], int Br, string ImeNaAvtor)
{
    int Br_Avtor = 0;
    for (int k = 0; k < Br; k++)
    {
        if (ImeNaAvtor == kniga[k].Avtor)
        {
            cout << "kniga: " << kniga[k].Ime << "\n";
            Br_Avtor++;
        }
    }
    cout << "\n";
    return Br_Avtor;
}
int ZaemiKniga(Book kniga[100], int& Br, string ImeNaKniga, string choice)
{
    int Br_Knigi = 0;
    cout << "Vuvedete ime na knigata: ";
    cin.ignore();
    getline(cin, ImeNaKniga);
    for (int k = 0; k < Br; k++)
    {
        if (ImeNaKniga == kniga[k].Ime && kniga[k].Zaet == false)
        {
            Br_Knigi++;
            if (kniga[k].Nalichnost > 0)
            {
                cout << "Iskate li da zaemete kniga: " << kniga[k].Ime << " s avtor: " << kniga[k].Avtor << "\n";
                cout << "Da/Ne \n";
            LOOP:getline(cin, choice);
                if (choice == "Da" || choice == "da" || choice == "dA" || choice == "DA")
                {
                    cout << "Vie zaehte kniga: " << kniga[k].Ime << "\n\n";
                    kniga[k].Br_zaemaniq++;
                    kniga[k].Nalichnost--;
                    kniga[k].Zaet = true;
                    break;
                }
                else if (choice == "Ne" || choice == "ne" || choice == "nE" || choice == "NE")
                {
                    break;
                }
                else
                {
                    cout << "Molq izberete da ili ne \n";
                    goto LOOP;
                }
            }
            else cout << "Tazi kniga ne e nalichna \n\n";
        }
    }
    choice.clear();
    return Br_Knigi;
}
int VurniKnigaPoIme(Book kniga[100], int& Br, string ImeNaKniga, string choice)
{
    int Br_Knigi = 0;
    cout << "\tImeto na knigata: ";
    cin.ignore();
    getline(cin, ImeNaKniga);
    for (int k = 0; k < Br; k++)
    {
        if (ImeNaKniga == kniga[k].Ime && kniga[k].Zaet == true)
        {
            Br_Knigi++;
            cout << "\tIskate li da vurnete kniga: " << kniga[k].Ime << " s avtor: " << kniga[k].Avtor << "\n";
            cout << "\tDa/Ne \n";
            cout << "\t";
        LOOP:getline(cin, choice);
            if (choice == "Da" || choice == "da" || choice == "dA" || choice == "DA")
            {
                cout << "\tVie vurnahte kniga: " << kniga[k].Ime << "\n\n";
                kniga[k].Nalichnost++;
                kniga[k].Zaet = false;
                break;
            }
            else if (choice == "Ne" || choice == "ne" || choice == "nE" || choice == "NE")
            {
                break;
            }
            else
            {
                cout << "Molq izberete da ili ne \n";
                goto LOOP;
            }
        }
        else if (ImeNaKniga == kniga[k].Ime && kniga[k].Zaet == false)
        {
            cout << "\tNe ste zaeli tazi kniga \n\n";
            Br_Knigi++;
        }
    }
    return Br_Knigi;
}
int VurniKnigaPoNomer(Book kniga[100], int& Br, int NomerNaKniga, string choice)
{
    int Br_Knigi = 0;
    cout << "\tKatalojen nomer na knigata: ";
    cin >> NomerNaKniga;
    for (int k = 0; k < Br; k++)
    {
        if (NomerNaKniga == kniga[k].K_nomer && kniga[k].Zaet == true)
        {
            Br_Knigi++;
            cout << "\tIskate li da vurnete kniga: " << kniga[k].Ime << " s avtor: " << kniga[k].Avtor << "\n";
            cout << "\tDa/Ne \n";
            cout << "\t";
            cin.ignore();
        LOOP:getline(cin, choice);
            if (choice == "Da" || choice == "da" || choice == "dA" || choice == "DA")
            {
                cout << "\tVie vurnahte kniga: " << kniga[k].Ime << "\n\n";
                kniga[k].Nalichnost++;
                kniga[k].Zaet = false;
                break;
            }
            else if (choice == "Ne" || choice == "ne" || choice == "nE" || choice == "NE")
            {
                break;
            }
            else
            {
                cout << "Molq izberete da ili ne \n";
                goto LOOP;
            }
        }
        else if (NomerNaKniga == kniga[k].K_nomer && kniga[k].Zaet == false)
        {
            cout << "\tNe ste zaeli tazi kniga \n\n";
            Br_Knigi++;
        }
    }
    return Br_Knigi;
}
void CreateFile(Book kniga[100], int& Br)
{
    ofstream  file;
    if (Br == 0)
        cout << " Nqma vavedeni knigi !\n";
    else
    {
        file.open("knigi.txt", ios::out | ios::ate);
        if (file.fail())
        {
            cout << "Faila ne moja da se sazdade !\n";
        }
        else
        {
            for (int k = 0; k < Br; k++)
            {
                file << "Kniga [" << k + 1 << "]\n";
                file << "Ime: " << kniga[k].Ime;
                file << "\nAvtor: " << kniga[k].Avtor;
                file << "\nKatalojen nomer: " << kniga[k].K_nomer;
                file << "\nCena: " << kniga[k].Cena;
                file << "\nBroi: " << kniga[k].Br_knigi;
                file << "\nBroi zaemaniq: " << kniga[k].Br_zaemaniq;
                file << "\nNalichnost: " << kniga[k].Nalichnost;
                file << "\nData: " << kniga[k].Data;
                file << endl;
            }
            cout << "Knigite bqha zapisani!\n\n";
        }
        file.close();
    }
}
void CreateBinaryFile(Book kniga[100], int& Br)
{
    ofstream  file;
    if (Br == 0)
        cout << " Nqma vavedeni knigi !\n";
    else
    {
        file.open("knigi.dat", ios::binary | ios::out | ios::ate);
        if (file.fail())
        {
            cout << "Faila ne moja da se sazdade !\n";
        }
        else
        {
            for (int k = 0; k < Br; k++)
            {
                file.write((char*)&kniga[k].Ime, sizeof(string));
                file << endl;
                file.write((char*)&kniga[k].Avtor, sizeof(string));
                file << endl;
                file.write((char*)&kniga[k].K_nomer, sizeof(int));
                file << endl;
                file.write((char*)&kniga[k].Cena, sizeof(double));
                file << endl;
                file.write((char*)&kniga[k].Br_knigi, sizeof(int));
                file << endl;
                file.write((char*)&kniga[k].Br_zaemaniq, sizeof(int));
                file << endl;
                file.write((char*)&kniga[k].Nalichnost, sizeof(int));
                file << endl;
                file.write((char*)&kniga[k].Data, sizeof(string));
            }
            cout << "Knigite bqha zapisani!\n";
        }
        file.close();
    }
}

int main()
{
    Book kniga[100];
    int decision = 0, N = 0, Br = 0, Br_Avtor = 0, Br_Knigi = 0, NomerNaKniga = 0;
    float MinCena = 0;
    string ImeNaAvtor, ImeNaKniga, MinIme, MinAvtor, choice, izbor;
    do
    {
        cout << "\t ***Menu*** \t \n";
        cout << ">1. Dobavqne \n";
        cout << ">2. izvejdane \n";
        cout << ">3. Zaemi kniga \n";
        cout << ">4. Vurni kniga \n";
        cout << ">5. Zapishi knigite vuv fail \n";
        cout << ">6. Zapishi knigite v dvoichen fail \n";
        cout << ">7. Izhod \n";
        cout << "Vashiqt izbor: ";
        cin >> decision; cout << "\n";
        switch (decision)
        {
        case 1:
            decision = 0;
            cout << "\t>1. Dobavi edna kniga \n";
            cout << "\t>2. Dobavi mnogo knigi \n";
            cout << "\tVashiqt izbor: ";
            cin >> decision; cout << "\n";
            while (decision < 1 || decision>2)
            {
                cout << "\tMolq izberete 1 ili 2 \n";
                cout << "\tVashiqt izbor: ";
                cin >> decision; cout << "\n";
            }
            switch (decision)
            {
            case 1:
                DobaviKniga(kniga, Br);
                do
                {
                    cout << "Iskate li da dobavite oshte edna kniga ?\n";
                    cout << "Da/Ne \n";
                    cout << "Vashiqt izbor: ";
                    cin >> izbor;
                    if (izbor == "Da" || izbor == "da")
                    {
                        DobaviKniga(kniga, Br);
                    }
                    else
                        break;
                } while (izbor == "Da");
                decision = 0;
                break;
            case 2:
                DobaviMnogoKnigi(kniga, Br, N);
                decision = 0;
                break;
            }
            break;
        case 2:
            decision = 0;
            cout << "\t>1. Izvedi nai-evtinite knigi \n";
            cout << "\t>2. Izvedi knigite na avtor \n";
            cout << "\t>3. Izvedi knigite sortirani po avtor \n";
            cout << "\t>4. Izvedi knigite sortirani po data na izdavane \n";
            cout << "\t>5. Izvedi knigite sortirani po nai-mnogo zaemaniq i avtor \n";
            cout << "\t>6. Izvedi knigite sortirani po nai-malko zaemaniq i data \n";
            cout << "\tVashiqt izbor: ";
            cin >> decision; cout << "\n";
            while (decision < 1 || decision>6)
            {
                cout << "\t\nMolq proverete izbora si \n";
                cout << "\tVashiqt izbor: ";
                cin >> decision; cout << "\n";
            }
            switch (decision)
            {
            case 1:
                BubbleSort(kniga, Br, MinCena, MinIme);
                decision = 0;
                break;
            case 2:
                cin.ignore();
                cout << "\tIzberete avtor: ";
                getline(cin, ImeNaAvtor);
                Br_Avtor = IzvediPoAvtor(kniga, Br, ImeNaAvtor);
                if (Br_Avtor == 0)
                    cout << "Nqma takuv avtor \n\n";
                decision = 0;
                break;
            case 3:
                SortPoAvtor(kniga, Br);
                decision = 0;
                break;
            case 4:
                SortPoData(kniga, Br);
                decision = 0;
                break;
            case 5:
                SortPoBrZaemaniqIAvtor(kniga, Br);
                decision = 0;
                break;
            case 6:
                SortPoBrZaemaniqIData(kniga, Br);
                decision = 0;
                break;
            }
            break;
        case 3:
            decision = 0;
            Br_Knigi = ZaemiKniga(kniga, Br, ImeNaKniga, choice);
            if (Br_Knigi == 0)
                cout << "Nqma takava kniga \n\n";
            decision = 0;
            break;
        case 4:
            decision = 0;
            cout << "\t>1. Po ime \n";
            cout << "\t>2. Po katalojen nomer \n";
            cout << "\tVashiqt izbor: ";
            cin >> decision; cout << "\n";
            while (decision < 1 || decision>2)
            {
                cout << "\t\nMolq izberete 1 ili 2 \n";
                cout << "\tVashiqt izbor: ";
                cin >> decision; cout << "\n";
            }
            switch (decision)
            {
            case 1:
                Br_Knigi = VurniKnigaPoIme(kniga, Br, ImeNaKniga, choice);
                if (Br_Knigi == 0)
                    cout << "\tNqma takava kniga \n\n";
                decision = 0;
                break;
            case 2:
                Br_Knigi = VurniKnigaPoNomer(kniga, Br, NomerNaKniga, choice);
                if (Br_Knigi == 0)
                    cout << "\tNqma takava kniga \n\n";
                decision = 0;
                break;
            }
            break;
        case 5:
            CreateFile(kniga, Br);
            decision = 0;
            break;
        case 6:
            CreateBinaryFile(kniga, Br);
            break;
        case 7:
            cout << "Krai na programata \n";
            break;
        }
    } while (decision != 7);
    return 0;
}
