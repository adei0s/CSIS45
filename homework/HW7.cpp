#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

// convert to minutes 

string convert_to_minutes(int length) {
    int minutes =  length / 60;
    int seconds = length % 60;
    return to_string(minutes) + ":" + to_string(seconds);
}

// print library

void print(string names[], string artists[], int duration[], int size) {
    cout << "Library" << endl << endl;
    cout << "Song | Artist | Duration" << endl << endl;
    for (int i=0; i<size; i++){
        cout << names[i] << " | " << artists[i] << " | " << convert_to_minutes(duration[i]) << endl;
    }
    cout << endl;
}

// find_song - takes song name and return index of the song, -1 if nonexist

int find_song(string names[], string name, int size) {
    for (int i=0; i<size; i++) {
        if (names[i] == name) {
            return i;
        }
    }
    return -1;
}

// find artist - takes artist name and print all songs by the artist

void find_artist(string names[], string artists[], int duration[], string artist, int size) {
    bool found = false;
    for (int i=0; i<size; i++) {
        if (artists[i] == artist) {
            cout << "Match Found" << endl;
            cout << "Song: " << names[i] << endl;
            cout << "Artist: " << artists[i] << endl;
            cout << "Duration: " << convert_to_minutes(duration[i]) << endl << endl;
            found = true;
        }
    }
    if (!found) {
        cout << "No " << artist << " in this library" << endl << endl;
    }
}

// tally song lengths

void library_duration(int duration[], int& total, int size) {
    for (int i=0; i<size; i++) {
        total += duration[i];
    }
}

int main() {

    int size = 10;
    string names[] = {"22", "WAP", "Espresso", "Whole Lotta Money", "Guess", "Taste", "Get Low", "Birds of a Feather", "Not Like Us", "Big Dawgs"};
    string artists[] = {"Taylor Swift", "Cardi B", "Sabrina Carpenter", "Bia", "Charli XCX", "Tyga", "Lil Jon", "Billie Eilish", "Kendrick Lamar", "Hanumankind"};
    int duration[] = {232, 187, 175, 156, 143, 232, 334, 210, 273, 190};


    string song_name;
    string artist_name;
    int total = 0;

    print(names, artists, duration, size);
   
   // search by song

    cout << "Search by song" << endl;
    cout << "enter song name: ";
    getline(cin, song_name);

    int track = find_song(names, song_name, size);
    cout << endl;
    if (track == -1) {
        cout << "No " << song_name << " in this library" << endl << endl;
    }
    else {
        cout << "Match Found" << endl;
        cout << "Song: " << names[track] << endl;
        cout << "Artist: " << artists[track] << endl;
        cout << "Duration: " << convert_to_minutes(duration[track]) << endl << endl;
    }

    // search by artist

    cout << "Seach by artist" << endl;
    cout << "enter Artist: ";
    getline(cin, artist_name);

    find_artist(names, artists, duration, artist_name, size);
    
    // display total

    library_duration(duration, total, size);
    cout << "Total Library Duration = " << convert_to_minutes(total) << endl;
    cout << endl;

    return 0;
}