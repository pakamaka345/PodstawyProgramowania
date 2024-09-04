/*#include <iostream>


unsigned short* find_subset(unsigned short* arr, int n, bool (*f)(unsigned short*, int), int& length)
{
    int max_length = 0;
    unsigned short* tmp = nullptr;
    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(f(arr + i, j - i + 1) && max_length < j - i + 1){
                max_length = j - i + 1;
                tmp = arr + i;
            }
        }
    }
    length = max_length;
    return tmp;
}
bool is_stricly_increasing(unsigned short* arr, int size)
{
    for(int i = 0; i < size - 1; i++){
        if(arr[i] >= arr[i + 1])
            return false;
    }
    return true;
}
bool are_zero_even_bits(unsigned short* arr, int size)
{
    for(int i = 0; i < size; i++){
        if(arr[i] != (arr[i] & 0b1010101010101010))
            return false;
    }
    return true;
    
}

int main()
{
    int n = 10;
    unsigned short* arr = new unsigned short[n] {1, 2, 5, 2, 2, 10, 11, 12, 13, 3};
    int length = 0;
    unsigned short* result1 = find_subset(arr, n, is_stricly_increasing, length);
    for(int i = 0; i < length; i++){
        std::cout << *(result1 + i) << " ";
    }
    unsigned short* result2 = find_subset(arr, n, are_zero_even_bits, length);
    
    std::cout << std::endl;
    for(int i = 0; i < length; i++){
        std::cout << *(result2 + i) << " ";
    }
    delete[] arr;
}
*/
/*#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

class Hotel{
    private:
    string name;
    int rooms;
    int rez_rooms;
    double rate;
    public:
    Hotel(string name, int rooms, double rate){
        this->name = name;
        this->rooms = rooms;
        this->rate = rate;
        rez_rooms = 0;
    } 
    void reserveRoom(){
        rez_rooms++;
    }
    void cancelReservation(){
        rez_rooms--;
    }
    double getRating(){
        return rate;
    }
    int getFreeRooms(){
        return rooms - rez_rooms;
    }
    string getName(){
        return name;
    }
};

int main()
{
    Hotel** hotels = new Hotel*[3];
    hotels[0] = new Hotel("Ararat", 10, 4.0);
    hotels[1] = new Hotel("Marriott", 20, 4.5);
    hotels[2] = new Hotel("Hyatt", 30, 3.5);
    
    sort(hotels, hotels + 3, [](Hotel* a, Hotel*b){
        return a->getRating() > b->getRating();
    });

    for(int i = 0; i < 3; i++){
        cout << hotels[i]->getName() << " " << hotels[i]->getRating() << " " << hotels[i]->getFreeRooms() << endl;
    }
    std::cout << endl;
    hotels[0]->reserveRoom();
    hotels[1]->reserveRoom();
    hotels[1]->reserveRoom();
    hotels[2]->reserveRoom();
    hotels[2]->reserveRoom();
    hotels[2]->reserveRoom();
    hotels[2]->reserveRoom();

    for(int i = 0; i < 3; i++){
        cout << hotels[i]->getName() << " " << hotels[i]->getRating() << " " << hotels[i]->getFreeRooms() << endl;
    }
    hotels[0]->cancelReservation();
    for(int i = 0; i < 3; i++){
        cout << hotels[i]->getName() << " " << hotels[i]->getRating() << " " << hotels[i]->getFreeRooms() << endl;
    }
    for(int i = 0; i < 3; i++){
        delete hotels[i];
    }
    delete[] hotels;
}
*/
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>

using namespace std;

struct ImageMeta{
    string name;
    int width;
    int height;
    int bitsPerPixel;
};

void addImageMetaToFile(ImageMeta meta, string path)
{
    ofstream file(path, ios::app);
    file << meta.name << " " << meta.width << " " << meta.height << " " << meta.bitsPerPixel << endl;
    file.close();
}

ImageMeta* readImageMetaFromFile(string path)
{
    ifstream file(path);
    if(!file.is_open()) return nullptr;
    int n = 0;
    string line;
    while(getline(file, line)){
        n++;
    }
    file.clear();
    file.seekg(0);
    ImageMeta* images = new ImageMeta[n];
    int i = 0;
    
    while(getline(file, line)){
        stringstream ss(line);
        string token;
        getline(ss, token, ' ');
        images[i].name = token;
        getline(ss, token, ' ');
        images[i].width = stoi(token);
        getline(ss, token, ' ');
        images[i].height = stoi(token);
        getline(ss, token, ' ');
        images[i].bitsPerPixel = stoi(token);
        i++;
    }
    file.close();
    return images;
}


int main()
{
    ImageMeta meta1 = {"image1", 1920, 1080, 24};
    ImageMeta meta2 = {"image2", 1280, 720, 16};
    ImageMeta meta3 = {"image3", 800, 600, 8};
    ImageMeta meta4 = {"image4", 800, 600, 8};
    addImageMetaToFile(meta1, "C:/project/C++/files/images.txt");
    addImageMetaToFile(meta2, "C:/project/C++/files/images.txt");
    addImageMetaToFile(meta3, "C:/project/C++/files/images.txt");
    addImageMetaToFile(meta4, "C:/project/C++/files/images.txt");

    ImageMeta* images = readImageMetaFromFile("C:/project/C++/files/images.txt");
    for(int i = 0; i < 4; i++){
        cout << right << setfill('-') << '"' << images[i].name << ", w: " << setw(5) << images[i].width << ", h: " << setw(5) << images[i].height << ", bpp: " << setfill(' ') << left << setw(3) << images[i].bitsPerPixel << '"' << endl;
    }
    delete[] images;
}
