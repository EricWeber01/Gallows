#pragma once
#include <iostream>
#include <Windows.h>
#include <fstream>
#include <vector>
#include <string>
#include <iterator>
#include <map>
using namespace std;
class Gallows
{
private:
    ifstream m_input;
    const string m_word;
    map<char, vector<size_t>> m_posMap;
    string m_searchWord;
    static const vector<string> m_images;
    enum steps: size_t
    {
        BEGIN, ONE, TWO, THREE, FOR, FIVE, SIX, SEVEN, END
    }
    m_step = BEGIN;
    enum result: size_t
    {
        LOSE, WIN
    }
    m_res = LOSE;
    void FillMap()
    {
        size_t pos{};
        for (char ch : m_word)
            m_posMap[ch].emplace_back(pos++);
    }
    char getChar()
    {
        cout << "Enter one character: ";
        char ch{};
        cin >> ch;
        return m_posMap.find(ch) != m_posMap.cend() ? ch : '\0';
    }
    friend steps& operator++(steps&);
public:
    Gallows(const string& filename = "word.txt") :m_input(filename), m_word(istream_iterator<char>(m_input), istream_iterator<char>()), m_searchWord(m_word.size(), '*');
    void Play();
};
const vector<string> Gallows::m_images
{
    {   },
    {
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        "\n"
        " ****************************\n"
        " *                          *\n"
    },
    {
        "        ***************\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        " ****************************\n"
        " *                          *\n"
    },
    {
        "        ***************\n"
        "        |             *\n"
        "        |             *\n"
        "        |             *\n"
        "        |             *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        " ****************************\n"
        " *                          *\n"
    },
    {
        "        ***************\n"
        "        |             *\n"
        "        |             *\n"
        "        |             *\n"
        "        |             *\n"
        "        O             *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        " ****************************\n"
        " *                          *\n"
    },
    {
        "        ***************\n"
        "        |             *\n"
        "        |             *\n"
        "        |             *\n"
        "        |             *\n"
        "        O             *\n"
        "      /   \\          *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        " ****************************\n"
        " *                          *\n"
    },
    {
        "        ***************\n"
        "        |             *\n"
        "        |             *\n"
        "        |             *\n"
        "        |             *\n"
        "        O             *\n"
        "      / | \\          *\n"
        "        |             *\n"
        "                      *\n"
        "                      *\n"
        "                      *\n"
        " ****************************\n"
        " *                          *\n"
    },
    {
        "        ***************\n"
        "        |             *\n"
        "        |             *\n"
        "        |             *\n"
        "        |             *\n"
        "        O             *\n"
        "      / | \\          *\n"
        "        |             *\n"
        "       / \\           *\n"
        "                      *\n"
        "                      *\n"
        " ****************************\n"
        " *                          *\n"
    }
};