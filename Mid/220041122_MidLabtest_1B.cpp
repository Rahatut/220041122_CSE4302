#include<iostream>
#include<cstring>

using namespace std;

class Motorbike{

    private:
        string modelno;
        double price;
        string manufacturer;
    public:
        Motorbike(string m, double p, string ma){
            modelno=m;
            price=p;
            manufacturer=ma;
        }
        void display(Motorbike& b){

            cout<<"Model number :"<<b.modelno<<endl;
            cout<<"Price :"<<b.price<<endl;
            cout<<"Manufacturer :"<<b.manufacturer<<endl;

        }


        bool operator>(const Motorbike& bike) const {
            return ;
        }

        friend void sortbymanufacturer(Motorbike& bike);

};

void sortbymanufacturer(Motorbike& bike){

    for(int i=0; i<10-1; i++){
        for(int j=0;j<10-i-1;j++){

            if(bike.manufacturer[j]>bike.manufacturer[j+1]){
                string temp;
                strcpy(temp, bike.manufacturer[j+1]);
                strcpy(bike.manufacturer[j+1], bike.manufacturer[j]);
                strcpy(bike.manufacturer[j], temp);
            }
        }
    }
}


int main(){

    Motorbike bike[10];

    bike("H5432", 535000, "Honda");
    bike("H4321", 535000, "Yamaha");
    bike("H5431", 535000, "Toyota");
    bike("H5433", 535000, "Mitsubishi");
    bike("H5435", 535000, "Razor");
    bike("H5438", 535000, "Tesla");
    bike("H5439", 535000, "Tekken");
    bike("H5430", 535000, "Ouken");
    bike("H5433", 535000, "Gallimede");

    bike.display[2];
    bike.display[5];
    bike.display[6];

    sortbymanufacturer(bike);


}
