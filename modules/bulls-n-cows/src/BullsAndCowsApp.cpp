// Copyright 2021 Solovev Aleksandr

#include "include/BullsAndCowsApp.h"

#include <stdexcept>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

#include "include/BullsAndCows.h"

std::string BullsAndCowsApp::operator()(int argc, const char* argv[],
                               int* retcode) const {
    if (retcode)
        *retcode = 1;
    if (argc != 3)
        return help(argv[0]);
    std::string arg = argv[1];
    int count;
    int reedem_answer;
    try
    {
        count = std::stoi(arg);
    } catch (std::invalid_argument& e) {
            return "[ERROR] " + arg + ": invalid argument. " +
                   std::string(e.what());
        } catch (std::out_of_range& e) {
            return "[ERROR] " + arg + ": out of range. " +
                   std::string(e.what());
        }
    arg = argv[2];
    std::vector<int> guess(count);
    try
    {
        for (int i = 0; i < count; i++)
        {
            guess[i] = arg[i]- '0';
        }
        
        reedem_answer = std::stoi(arg);
    } catch (std::invalid_argument& e) {
            return "[ERROR] " + arg + ": invalid argument. " +
                   std::string(e.what());
        } catch (std::out_of_range& e) {
            return "[ERROR] " + arg + ": out of range. " +
                   std::string(e.what());
        }
    int x;
    std::vector<int> answer(count);
    for (int i = 0; i < count; i++)
    {
        do
        {
            x = rand() % 9;
        } while (std::find(answer.begin(), answer.end(), x) != answer.end());
        answer[i] = x;    
    }
    
    std::string str;
    try {
        bullsAndCowsGame game(answer);
        game.setGuess(guess);
        game.guessing();
        std::pair<int, int> result = game.getAnimals();
        str = "Bulls:" + std::to_string(result.first) + " Cows:" + std::to_string(result.second);  
    } catch (std::runtime_error& e) {
        return "[ERROR]" + std::string(e.what());
    }
    
    if (retcode)
        *retcode = 0;
    return str;
}

std::string BullsAndCowsApp::help(const std::string& filename) const {
    return "Usage: " + filename + " COUNT ANSWER\nExample: " + filename +
           "123456789";
}
