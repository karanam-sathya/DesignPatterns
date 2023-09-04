/*Adapter pattern works as a bridge between two incompatible interfaces. This type of design pattern
comes under structural pattern as this pattern combines the capability of two independent interfaces.
For example if we are dealing with an legacy code which can't be understandable
by the client than we will add a wrapper/adapter which will talk to the legacy code and returns the
required operation to client. */

#include<iostream>
#include<string>
using namespace std;

// Target interface
class AudioPlayer {
public:
    virtual void playMP3(const std::string& filename) = 0;
    virtual void stopMP3() = 0;
};

// Existing AudioPlayer class
class DefaultAudioPlayer : public AudioPlayer {
public:
    void playMP3(const std::string& filename) override {
        // Play MP3 logic
        std::cout << "Playing MP3 file: " << filename << std::endl;
    }

    void stopMP3() override {
        // Stop MP3 logic
        std::cout << "Stopping MP3 playback" << std::endl;
    }
};

// Adaptee class for playing WAV files
class WAVPlayer {
public:
    void playWAV(const std::string& filename) {
        // Play WAV logic
        std::cout << "Playing WAV file: " << filename << std::endl;
    }

    void stopWAV() {
        // Stop WAV logic
        std::cout << "Stopping WAV playback" << std::endl;
    }
};

// Adapter class
class AudioAdapter : public AudioPlayer {
private:
    WAVPlayer *wavPlayer; // Adaptee instance

public:
    AudioAdapter(WAVPlayer *wavPlayer)
    {
        this->wavPlayer = wavPlayer;
    }
    void playMP3(const std::string& filename) override {
        // Reusing existing AudioPlayer interface
        DefaultAudioPlayer audioPlayer;
        audioPlayer.playMP3(filename);
    }

    void stopMP3() override {
        // Reusing existing AudioPlayer interface
        DefaultAudioPlayer audioPlayer;
        audioPlayer.stopMP3();
    }

    void playWAV(const std::string& filename) {
        // Adapting WAVPlayer interface to match AudioPlayer interface
        wavPlayer->playWAV(filename);
    }

    void stopWAV() {
        // Adapting WAVPlayer interface to match AudioPlayer interface
        wavPlayer->stopWAV();
    }
};

void Play(AudioPlayer *audioPlayer)
{
    audioPlayer->playMP3("Rockstar");
    audioPlayer->stopMP3();
}
int main()
{
    WAVPlayer wavPlayer;

    AudioAdapter audioAdapter(&wavPlayer);
    Play(&audioAdapter);
    return 0;
}
