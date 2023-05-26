#include <iostream>
#include <string.h>

using namespace std;

struct item
{
    int id_item, banyak, harga;
    string nama, placeholder;
    item *next;
    item *prev;
};

struct customer
{
    int id_customer, harga;
    string nama, tanggal, waktu;
    customer *next;
    customer *prev;
};

struct customer *customer_init = NULL;
struct item *init = NULL;

// inisiasi node baru
item *node_baru()
{
    item *baru = new item;
    cout << "------------------------------------------------";
    cout << "-----------------------------------------------------\t\t" << endl;
    cout << "Silakan input ID Item : " << endl;
    cin >> baru->id_item;

    cout << "------------------------------------------------";
    cout << "-----------------------------------------------------\t\t" << endl;

    cout << "Silakan input Nama Item : " << endl;
    cin >> baru->nama;

    cout << "------------------------------------------------";
    cout << "-----------------------------------------------------\t\t" << endl;

    cout << "Silakan input Kuantitas Item : " << endl;
    cin >> baru->banyak;

    cout << "------------------------------------------------";
    cout << "-----------------------------------------------------\t\t" << endl;

    cout << "Silakan input Harga Item : " << endl;
    cin >> baru->harga;

    baru->next = NULL;
    baru->prev = NULL;
}

customer *new_node()
{
    customer *customer_baru = new customer;
    cout << "------------------------------------------------";
    cout << "-----------------------------------------------------\t\t" << endl;
    cout << "Silakan input id anda : " << endl;
    cin >> customer_baru->id_customer;
    cout << "------------------------------------------------";
    cout << "-----------------------------------------------------\t\t" << endl;
    cout << "Silakan input nama anda : " << endl;
    cin >> customer_baru->nama;
    cout << "------------------------------------------------";
    cout << "-----------------------------------------------------\t\t" << endl;
    cout << "Silakan input tanggal kedatangan anda (contoh: 19_Agustus)" << endl;
    cin >> customer_baru->tanggal;
    cout << "------------------------------------------------";
    cout << "-----------------------------------------------------\t\t" << endl;
    cout << "Silakan input waktu kedatangan anda : " << endl;
    cin >> customer_baru->waktu;

    customer_baru->next = NULL;
}

void bubbleSort()
{
    if (init == nullptr || init->next == nullptr)
        return;

    bool swapped;
    item *current;
    item *last = nullptr;

    do
    {
        swapped = false;
        current = init;

        while (current->next != last)
        {
            if (current->id_item > current->next->id_item)
            {
                // Swap the items
                swap(current->id_item, current->next->id_item);
                swap(current->banyak, current->next->banyak);
                swap(current->harga, current->next->harga);
                swap(current->nama, current->next->nama);
                swap(current->placeholder, current->next->placeholder);
                swapped = true;
            }
            current = current->next;
        }
        last = current;
    } while (swapped);
}

// addItem
void addItem()
{
    item *add;
    add = node_baru();
    if (init == NULL)
    {
        init = add;
    }
    else
    {
        item *traverse;
        traverse = init;
        while (traverse->next != NULL)
        {
            traverse = traverse->next;
        }
        traverse->next = add;
        add->prev = traverse;
    }
    bubbleSort();
}

// addCustomer
void addCustomer()
{
    customer *add_customer;
    add_customer = new_node();
    if (customer_init == NULL)
    {
        customer_init = add_customer;
    }
    else
    {
        customer *traverse;
        traverse = customer_init;
        while (traverse->next != NULL)
        {
            traverse = traverse->next;
        }
        traverse->next = add_customer;
        add_customer->prev = traverse;
    }
}

// deleteItem
void deleteItem()
{
    item *deleteItem;
    deleteItem = init;
    if (deleteItem != NULL)
    {
        init = init->next;
        cout << "---------------------------------" << endl;
        cout << "Data berhasil dihapus" << endl;
        cout << "---------------------------------" << endl;

        free(deleteItem);
    }
    else
    {
        cout << "---------------------------------" << endl;
        cout << "Item masih kosong" << endl;
        cout << "---------------------------------" << endl;
    }
}

void deleteByID()
{
    int ID;
    item *deleteitemID;
    deleteitemID = init;
    if (deleteitemID != NULL)
    {
        cout << "Input ID Item yang akan dihapus: ";
        cin >> ID;
        if (deleteitemID->id_item == ID)
        {
            init = init->next;
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
            cout << "Data berhasil dihapus" << endl;
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
            free(deleteitemID);
        }
    }
    else
    {
        cout << "------------------------------------------------";
        cout << "-----------------------------------------------------\t\t" << endl;
        cout << "Item masih kosong" << endl;
        cout << "------------------------------------------------";
        cout << "-----------------------------------------------------\t\t" << endl;
    }
}

// database produk
int database()
{
    int temp = 0;
    item *database = init;
    while (database != NULL)
    {
        database = database->next;
        temp++;
    }
    return temp;
}

int traverseID(int id)
{
    int count = 1;
    item *idItem = init;
    while (idItem != NULL)
    {
        // cek idItem pada node
        if (idItem->id_item == id)
        {
            break;
        }
        else
        {
            count++;
        }
        idItem = idItem->next;
    }
    return count;
}

// BeliItem
void beliItem()
{
    string produk[32];
    int temp = 0;
    int bayar, posisi = 0;
    int total[32] = {0}; // initialize the array to 0
    int count = 0;       // to keep track of the number of items bought
    int opr, id, banyak, harga;
    int i = 1;
    item *show;
    item *now = init;
    item *traverse = init;
    customer *totalHarga = customer_init;
    if (init == NULL)
    {
        cout << "MAAF STOK SEDANG KOSONG" << endl;
    }
    else
    {
        cout << "Mau beli berapa barang?" << endl; // basic looping
        cin >> opr;
        int data = database(); // cek banyak barang di database
        while (i <= opr)
        {
            if (traverse != NULL)
            {
                cout << "\t\t----------------- DATABASE ITEM ---------------------\t\t" << endl;
                while (traverse != NULL)
                {
                    cout << "------------------------------------------------";
                    cout << "-----------------------------------------------------\t\t" << endl;
                    cout << "Product ID: " << traverse->id_item << endl;
                    cout << "Product Name: " << traverse->nama << endl;
                    cout << "Quantity: " << traverse->banyak << endl;
                    cout << "Price: " << traverse->harga << endl;
                    traverse = traverse->next;
                    cout << "------------------------------------------------";
                    cout << "-----------------------------------------------------\t\t" << endl;
                }
            }
            else
            {
                cout << "\t\t----------------- SELAMAT DATANG DI AGRISTORE ---------------------\t\t" << endl;
            }

            cout << "pilih ID Item:" << endl;
            cin >> id;
            posisi = traverseID(id); // buat cek ID yang dipilih ada di db
            // cek posisi tidak melebihi banyak barang
            if (posisi <= data)
            {
                while (now->id_item != id)
                {
                    now = now->next;
                }
                cout << "Beli berapa banyak?" << endl;
                cin >> banyak;
                produk[temp] = now->nama;
                temp++;
                total[count] = now->harga * banyak;
                count++;
                // hitung harga total
                now->banyak = now->banyak - banyak; // operasi perkurangan kuantitas barang
                i++;
            }
            else
            {
                cout << "Item tidak tersedia di database" << endl;
            }
        }

        cout << "------------------------------------------------";
        cout << "-----------------------------------------------------\t\t" << endl;
        cout << "Barang yang anda beli adalah: " << endl;
        for (int i = 0; i < opr; i++)
        {
            cout << produk[i] << endl;
        }

        cout << "------------------------------------------------";
        cout << "-----------------------------------------------------\t\t" << endl;
        for (int i = 0; i < opr; i++)
        {
            cout << "Total Harga Semua Item adalah : Rp." << total[i] << endl;
        }
        cout << "------------------------------------------------";
        cout << "-----------------------------------------------------\t\t" << endl;
    }
}

// katalog item
void showItem()
{
    item *traverse;
    traverse = init;
    if (traverse != NULL)
    {
        cout << "\t\t----------------- DATABASE ITEM ---------------------\t\t" << endl;
        while (traverse != NULL)
        {
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
            cout << "\nPRODUCT ID\t"
                 << "PRODUCT NAME\t"
                 << "QUANTITY\t"
                 << "PRICE" << endl;
            cout << traverse->id_item << "\t\t";
            cout << traverse->nama << "\t\t";
            cout << traverse->banyak << "\t\t";
            cout << traverse->harga << endl;
            traverse = traverse->next;
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
            cout << endl;
        }
    }
    else
    {
        cout << "\t\t----------------- TIDAK ADA ITEM DI DATABASE ---------------------\t\t" << endl;
        cout << endl;
    }
}

void showCustomer()
{
    customer *traverse = customer_init;
    if (traverse == NULL)
    {
        cout << "\t\t----------------- BELUM ADA PENGUNJUNG ---------------------\t\t" << endl;
    }
    else
    {
        cout << "\t\t----------------- DATA PENGUNJUNG ---------------------\t\t" << endl;
        while (traverse != NULL)
        {
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
            cout << "\nCustomer ID\t"
                 << "Customer Name\t"
                 << "Tanggal" << "\t"
                 << "Jam" << endl;
            cout << traverse->id_customer << "\t\t";
            cout << traverse->nama << "\t\t";
            cout << traverse->tanggal << "\t\t";
            cout << traverse->waktu << endl;
            traverse = traverse->next;
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
        }
    }
}

void showHarga()
{
    customer *traverseHarga = customer_init;
    if (traverseHarga == NULL)
    {
        cout << "\t\t----------------- BELUM ADA PEMBELI ---------------------\t\t" << endl;
    }
    else
    {
        while (traverseHarga != NULL)
        {
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
            cout << "Customer ID: " << traverseHarga->harga << endl;
            cout << "Total Beli: " << traverseHarga->harga << endl;
            traverseHarga = traverseHarga->next;
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
        }
    }
}

void searchItem()
{
    string nama;
    int temp = 0;
    struct item *src = init;
    if (src == NULL)
    {
        cout << "\t\t----------------- TIDAK ADA ITEM DI DATABASE ---------------------\t\t" << endl;
    }
    else
    {
        while (src != NULL)
        {
            cout << "Silakan cari produk yang anda inginkan di sini: " << endl;
            cin >> nama;
            if (nama == src->nama)
            {
                temp = 1;
                break;
            }
            src = src->next;
        }
        if (temp == 1)
        {
            cout << "Produk tersedia di katalog" << endl;
        }
        else
        {
            cout << "Produk tidak tersedia saat ini" << endl;
        }
    }
}

int main()
{
    int option;
    int role;
    do
    {
        cout << endl;
        cout << "\t\t----------------- SELAMAT DATANG DI AGRISTORE ---------------------\t\t" << endl;
    menu_choice:
        cout << "1. ADMIN" << endl;
        cout << "2. EMPLOYEE" << endl;
        cout << "3. CUSTOMER" << endl;
        cout << "4. Exit" << endl;
        cout << "------------------------------------------------";
        cout << "-----------------------------------------------------\t\t" << endl;
        cout << "choice: ";
        cin >> role;

        switch (role)
        {
        case 1:
        admin_choice:
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
            cout << "1. Tambah Item Ke Database" << endl;
            cout << "2. Cetak Total Beli" << endl;
            cout << "3. Cetak Item yang tersedia pada Database" << endl;
            cout << "4. Cetak Data Customer" << endl;
            cout << "5. Cari Item pada Database" << endl;
            cout << "6. Hapus item" << endl;
            cout << "7. Return" << endl;
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
            cout << "choice: ";
            cin >> option;
            switch (option)
            {
            case 1:
                cout << endl;
                addItem();
                goto admin_choice;
                break;
            case 2:
                cout << endl;
                showHarga();
                goto admin_choice;
                break;
            case 3:
                cout << endl;
                showItem();
                goto admin_choice;
                break;
            case 4:
                cout << endl;
                showCustomer();
                goto admin_choice;
                break;
            case 5:
                searchItem();
                goto admin_choice;
                break;

            case 6:
                deleteByID();
                goto admin_choice;
                break;

            case 7:
                goto menu_choice;
                break;
            }

        case 2:
        employee_choice:
            cout << endl;
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
            cout << "1. Cetak item pada database" << endl;
            cout << "2. Return" << endl;
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
            cout << "choice: ";
            cin >> option;
            switch (option)
            {
            case 1:
                cout << endl;
                showItem();
                goto employee_choice;
                break;
            case 2:
                cout << endl;
                goto menu_choice;
                break;
            }
        case 3:
        customer_choice:
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
            cout << "1. Tambah ID Customer" << endl;
            cout << "2. Beli barang" << endl;
            cout << "3. Return" << endl;
            cout << "------------------------------------------------";
            cout << "-----------------------------------------------------\t\t" << endl;
            cout << "choice: ";
            cin >> option;
            switch (option)
            {
            case 1:
                cout << endl;
                addCustomer();
                goto customer_choice;
                break;

            case 2:
                cout << endl;
                beliItem();
                goto customer_choice;
                break;
            case 3:
                cout << endl;
                goto menu_choice;
                break;
            default:
                goto menu_choice;
            }
            break;
        }

    } while (role != 4);
    return 0;
}