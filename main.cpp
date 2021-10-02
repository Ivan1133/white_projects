#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
using namespace std;


int Factorial(int x){
    if (x <= 1){
        return 1;
    } else {
        return x * Factorial(x -1);
    }
}

bool IsPalindrom(string word){
    if (word.size() <=1){
        return true;
    } else {
        int num = word.size();
        num = num / 2;

        for (int i=0; i< num;i++){
            if (word[i] != word[word.size() - 1 - i]){
                return false;
            }
        }
        return true;
    }
}

vector<string> PalindromFilter (vector <string> words, int minLength){
    vector <string> answer;
    for (string s : words ){
        if(IsPalindrom(s) && s.size() >= minLength ){
            answer.push_back(s);

        }
    }
    return answer;
}

void MoveStrings(vector<string> & source, vector<string> & destination){

    for( auto s: source){
        destination.push_back(s);
    }
    source.clear();
}


void Reverse(vector<int> & vec){

    int num = vec.size();
    num = num /2;

    for(int i=0;i < num;i++){
        int tmp = vec[i];
        vec[i] = vec[vec.size() -1 - i];
        vec[vec.size() -1 - i] = tmp;
    }

}

string ToLower(const string &st){
    string out;
    for(auto i:st){
        out += tolower(i);
    }
    return out;
}

void size_queue(vector<int> & q,   int num){

    if (num > 0){
        for(int i=0; i < num; i++){
            q.push_back(0);
        }
    } else {
        num = abs(num);
        q.erase(q.end() - num, q.end());
    }
}

void make_sign(string &word, int num, vector<int> & queue){
    if (word == "WORRY"){
        queue[num] = 1;
    } else {
        queue[num] = 0;
    }
}


void change_size(vector<int>  mas ){
    mas.push_back(4);
}

void ALL_BUSES(const map<string, vector<string>> & bus){
    if (bus.empty()){
        cout << "No buses" << endl;
    } else {
        for (auto s: bus){
            cout <<"Bus "<< s.first << ":" ;
        }
    }
}

void print_vector(const vector<string> & station){
    for(auto s:station){
        cout<<s <<" ";
    }
    cout << endl;
}


void print_vector(const vector<int> & station){
    for(auto s:station){
        cout<<s <<" ";
    }
}


class Person{
public:
    string first_name;
    string second_name;
    int age;
    Person(const string & new_first_name, const string & new_second_name, const int & new_age){
        first_name   = new_first_name;
        second_name = new_second_name;
        age = new_age;
    }
    int Age(){
        int res = 2021 - age;
        return res;
    }

};





int main() {

    Person person("Ian","Karelin", 1996);
    cout << person.first_name <<" ";
    cout << person.Age();


    /*
    map<set<string>, int> map_buses;

    int num_queries;
    cin >> num_queries;

    int number_of_map =0;

    for(int i =0; i <num_queries;i++){
        set <string> stops_of_bus;
        int num_stops;
        cin >>num_stops;

        for(int i=0; i < num_stops;i++){
            string stop;
            cin >> stop;
            stops_of_bus.insert(stop);
        }

        if(map_buses[stops_of_bus] == 0){
            number_of_map += 1;
            map_buses[stops_of_bus] =number_of_map;
            cout<<"New bus " <<map_buses[stops_of_bus]<<endl;
        } else {
            cout <<"Already exists for "<<map_buses[stops_of_bus]<<endl;
        }

    }



    */



    /*
    map<string, set<string>> dictionary;
    int number_words;
    cin >> number_words;

    for (int i=0; i < number_words;i++){
        string command;
        cin >> command;
        if(command == "ADD"){
            string first, second;
            cin >>first;
            cin >> second;
            dictionary[first].insert(second);
            dictionary[second].insert(first);
        } else if(command =="COUNT"){
            string word;
            cin >> word;
            cout << dictionary[word].size() << endl;
        } else if(command =="CHECK" ){
            string first, second;
            cin >> first >> second;
            if (dictionary[first].empty() != true & dictionary[first].count(second) >= 1){
                cout <<"YES" << endl;
            } else {
                cout <<"NO" << endl;
            }
        }
    }





    int q;
    cin >>8q;

    map<string, vector<string>> buses;
    map<string, vector<string>> stations;
    map<vector<string>, int> bus_map;
    */






    /*
    int  num_of_stops = 0;

    int num;
    cin >> num;

    for (int i=0; i < num; i++){
        int num_stops;
        cin >> num_stops;
        vector<string> ways;

        for (int j =0; j < num_stops;j++){
            string stop;
            cin >> stop;
            ways.push_back(stop);
        }

        if (bus_map.count(ways) > 0){
            cout << "Already exists for " << bus_map[ways]<<endl;
        } else {
            num_of_stops += 1;
            bus_map[ways] = num_of_stops;
            cout << "New bus " << bus_map[ways] << endl;
        }
    }



*/
    /*
    for(int i=0; i < q; ++i){
        string operation;
        cin >> operation;

        if (operation == "ALL_BUSES"){

            if (buses.size() ==0){
                cout <<"No buses"<<endl;
            } else {
                for (auto s: buses){
                    cout <<"Bus " << s.first <<": ";
                    print_vector(buses[s.first]);
                   // cout << endl;
                }
            }
        } else if (operation == "NEW_BUS") {
            string bus;
            cin >> bus;
            int stop_count;
            cin >> stop_count;

            for(int j =0; j < stop_count;++j){
                string stop;
                cin >> stop;
                buses[bus].push_back(stop);
                stations[stop].push_back(bus);
            }
        } else if(operation == "BUSES_FOR_STOP" ) {
            string stop;
            cin >> stop;
            if (stations.count(stop) ==0){
                cout <<"No stop"<<endl;
            } else {
                print_vector(stations[stop]);
                cout << endl;
            }

        } else if(operation =="STOPS_FOR_BUS"){
            string bus;
            cin >> bus;

            if (buses.count(bus) ==0){
                cout << "No bus"<<endl;
            } else {

                for (auto s: buses[bus]){

                    if(stations[s].size() == 1){
                        cout << "Stop "<< s <<": no interchange" <<endl;
                    } else {
                        cout <<"Stop " << s <<": ";
                        for (auto bus_in: stations[s]){
                            if (bus_in != bus){
                                cout << bus_in <<" ";
                            }
                        }
                        cout << endl;
                    }
                }
            }
        }
    }
     */
    return 0;
}















