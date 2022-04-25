#include <iostream>
#include <stack>
#include <string.h>
using namespace std;
class SongQueue
{
    stack<string> stk;

public:
    void addSong(string choice)
    {
        stk.push(choice);
        cout << "\n adding song: " << stk.top() << endl;
        cout << "\n song added." << endl;
    }
    void delSong()
    {
        cout << "\n deleting song: " << stk.top() << endl;
        cout << "\n song deleted" << endl;
    }
    void playSong()
    {
        cout << "\n playing current song: " << stk.top() << endl;
        cout << "\n song played." << endl;
        stk.pop();
    }
};

int main()
{
    SongQueue playlist;
    playlist.addSong("Older");
    playlist.addSong("Have we met before.");
    playlist.playSong();
    playlist.delSong();
    playlist.addSong("Maniac");
    playlist.playSong();
}