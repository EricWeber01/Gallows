#include "Header.h"
Gallows::Gallows(const string& filename = "word.txt") :m_input(filename), m_word(istream_iterator<char>(m_input), istream_iterator<char>()), m_searchWord(m_word.size(), '*')
{
    FillMap();
};
void Gallows::Play()
{
    while (m_step != END)
    {
        system("cls");
        cout << "Введите ==> " << m_searchWord << '\n' << "\n";
        cout << m_images[m_step] << "\n";

        if (char ch{ getChar() })
        {
            const vector<size_t>& vec{ m_posMap[ch] };
            for (size_t i{}, end{ vec.size() }; i < end; ++i)
                m_searchWord[vec[i]] = ch;

            m_posMap.erase(ch);

            if (m_searchWord.find('*') == string::npos)
                m_step = END, m_res = WIN;
        }
        else
            ++m_step;
    }
    system("cls");
    cout << "\nВведите ==> " << m_word << "\n";
    cout << "Ты " << (m_res == WIN ? "Победил.\n" : "Проигрл.\n") << "\n";
}
Gallows::steps& operator++(Gallows::steps&);
Gallows::steps& operator++(Gallows::steps& st)
{
    size_t tmp = st;
    return st = static_cast<Gallows::steps>(++tmp);
}