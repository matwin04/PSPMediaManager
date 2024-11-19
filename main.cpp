#include <ftxui/component/screen_interactive.hpp>
#include <ftxui/component/component.hpp>
#include <SFML/Audio.hpp>
#include <string>
#include <fstream>
#include <filesystem>
#include <vector>
#include "metadata.h"

namespace fs = std::filesystem;
using namespace std;

//Create Library Folder
void createLibFolders(){
    const string libraryPath = "/library";
    fs::create_directories(libraryPath);

    const string testPath = libraryPath + "/test";
    const string musicPath = libraryPath + "/music";
    fs::create_directories(testPath);
    fs::create_directories(musicPath);

}
int main(){
    const string fileName = "test.mp3";

    //Metadata Object
    metadata metadata(fileName);

    //Load and Play
    sf::Music music;
    if (!music.openFromFile(fileName)) {
        cerr << "Failed to load file : " << fileName << endl;
        return 1;
    }
    music.play();

    //Playback Status
    string playStatus = "Playing";

    //UI
    auto screen = ftxui::ScreenInteractive::TerminalOutput();

    auto titleText = ftxui::Renderer([&] {
        return ftxui::vbox({
            ftxui::text("Audio Player with Metadata") | ftxui::bold | ftxui::center,
            ftxui::separator(),
            ftxui::text("Now Playing:") | ftxui::bold,
            ftxui::text("Title: " + metadata.getTitle()),
            ftxui::text("Artist: " + metadata.getArtist()),
            ftxui::text("Album: " + metadata.getAlbum()),
            ftxui::separator(),
            ftxui::text("Playback Status: " + playStatus),
            ftxui::separator(),
            ftxui::text("[SPACE] Play/Pause") | ftxui::bold,
            ftxui::text("[ESC] Quit") | ftxui::bold,
        }) | ftxui::border;
    });

    //Play Pause Button
    auto ppbtn = ftxui::Button("Play/Pause",[&] {
        if (music.getStatus() == sf::Music::Playing) {
            music.pause();
            playStatus = "Paused";
        } else if (music.getStatus() == sf::Music::Paused) {
            music.play();
            playStatus = "Playing";
        }
    });

    //Quit Button
    auto quitButton = ftxui::Button("Quit", screen.ExitLoopClosure());

    //Buttons 
    auto buttons = ftxui::Container::Vertical({
        ppbtn,
        quitButton,
    });

    auto renderer = ftxui::Renderer(buttons, [&] {
        return ftxui::vbox({
            titleText->Render(),
            ftxui::hbox({ppbtn->Render(), quitButton->Render()}) | ftxui::center,
        });
    });
    screen.Loop(renderer);
    return 0;
}