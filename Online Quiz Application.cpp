#include <iostream>
#include <vector>
#include <chrono>
#include <algorithm>
#include <cstdlib>
#include <ctime>

using namespace std;

struct Question {
    string question;
    vector<string> options;
    int correctOption;
};

void conductQuiz(const vector<Question>& questions, int timeLimitSeconds, int& score, int& totalQuestions) {
    chrono::steady_clock::time_point startTime = chrono::steady_clock::now();
    chrono::steady_clock::time_point endTime = startTime + chrono::seconds(timeLimitSeconds);
    for (int i = 0; i < questions.size(); ++i) {
        const Question& q = questions[i];

        cout << "\nQuestion " << (i + 1) << ": " << q.question << endl;
        for (size_t j = 0; j < q.options.size(); ++j) {
            cout << j + 1 << ". " << q.options[j] << endl;
        }
        int userAnswer;
        cout << "Enter your answer (1-" << q.options.size() << "): ";
        cin >> userAnswer;
        if (userAnswer < 1 || userAnswer > static_cast<int>(q.options.size())) {
            cout << "Invalid choice. Skipping this question." << endl;
            continue;
        }
        if (userAnswer == q.correctOption) {
            cout << "Correct!" << endl;
            ++score;
        } else {
            cout << "Wrong. The correct answer is: " << q.options[q.correctOption - 1] << endl;
        }
        chrono::steady_clock::time_point currentTime = chrono::steady_clock::now();
        if (currentTime >= endTime) {
            cout << "\nTime's up! Quiz ended." << endl;
            break;
        }
    }

    totalQuestions += questions.size();
}

int main() {
        srand(static_cast<unsigned int>(time(nullptr)));

    vector<vector<Question>> allQuizzes = {
        {
            {"Who was the first President of the United States?", {"George Washington", "Thomas Jefferson", "Abraham Lincoln", "John Adams"}, 1},
            {"In which year did World War II end?", {"1943", "1944", "1945", "1946"}, 3},
            {"Where was the ancient city of Babylon located?", {"Greece", "Mesopotamia", "Egypt", "Persia"}, 2},
            {"Who was the first female Prime Minister of India?", {"Sonia Gandhi", "Indira Gandhi", "Mayawati", "Sushma Swaraj"}, 2},
            {"When did the French Revolution begin?", {"1789", "1798", "1801", "1810"}, 1},
            {"Who was the first Emperor of China?", {"Qin Shi Huang", "Mao Zedong", "Sun Yat-sen", "Deng Xiaoping"}, 1},
            {"What event marked the beginning of the Renaissance?", {"Fall of Constantinople", "Invention of printing press", "Discovery of America", "Black Death"}, 4},
            {"Who was the last ruler of the Aztec Empire?", {"Montezuma II", "Hernán Cortés", "Atahualpa", "Pizarro"}, 1},
            {"Who wrote 'The Art of War'?", {"Sun Tzu", "Machiavelli", "Confucius", "Laozi"}, 1},            {"Which famous explorer led the first expedition to circumnavigate the globe?", {"Christopher Columbus", "Vasco da Gama", "Ferdinand Magellan", "Marco Polo"}, 3}
        },
        {
            {"In which sport is the term 'slam dunk' used?", {"Basketball", "Football", "Tennis", "Golf"}, 1},
            {"Which country won the FIFA World Cup in 2018?", {"Germany", "Brazil", "France", "Argentina"}, 3},
            {"Who has won the most Grand Slam singles titles in tennis?", {"Serena Williams", "Roger Federer", "Steffi Graf", "Rafael Nadal"}, 2},
            {"In which sport would you perform an 'alley-oop'?", {"Basketball", "Baseball", "Volleyball", "Rugby"}, 1},
            {"Who is the all-time leading scorer in NBA history?", {"Michael Jordan", "LeBron James", "Kareem Abdul-Jabbar", "Kobe Bryant"}, 3},
            {"Which city hosted the 2016 Summer Olympics?", {"Rio de Janeiro", "London", "Beijing", "Tokyo"}, 1},
            {"Which boxer was known as 'The Greatest'?", {"Muhammad Ali", "Mike Tyson", "Floyd Mayweather", "Joe Frazier"}, 1},
            {"Who won the 2021 UEFA Champions League?", {"Real Madrid", "Chelsea", "Manchester City", "Bayern Munich"}, 2},
            {"Which sport uses a shuttlecock?", {"Badminton", "Table Tennis", "Squash", "Cricket"}, 1},
            {"Which country has won the most Olympic gold medals?", {"USA", "China", "Russia", "Germany"}, 1}
        },
                {
            {"What is the chemical symbol for water?", {"H2O", "CO2", "O2", "NaCl"}, 1},
            {"Who developed the theory of relativity?", {"Isaac Newton", "Albert Einstein", "Stephen Hawking", "Galileo Galilei"}, 2},
            {"What is the largest organ in the human body?", {"Liver", "Heart", "Brain", "Skin"}, 4},
            {"Which planet is known as the Red Planet?", {"Venus", "Mars", "Jupiter", "Mercury"}, 2},
            {"What is the powerhouse of the cell?", {"Mitochondrion", "Nucleus", "Ribosome", "Endoplasmic reticulum"}, 1},
            {"Who discovered penicillin?", {"Alexander Fleming", "Louis Pasteur", "Marie Curie", "Robert Koch"}, 1},
            {"What is the hardest natural substance on Earth?", {"Gold", "Diamond", "Iron", "Quartz"}, 2},
            {"Which scientist proposed the laws of motion?", {"Isaac Newton", "Albert Einstein", "Galileo Galilei", "Nikola Tesla"}, 1},
            {"What does DNA stand for?", {"Deoxyribonucleic Acid", "Dinucleic Acid", "Diatonic Acid", "Dichloroacetic Acid"}, 1},
            {"Which gas is most abundant in Earth's atmosphere?", {"Oxygen", "Nitrogen", "Carbon Dioxide", "Argon"}, 2}
        },
        {
            {"Who is the current President of the United States?", {"Joe Biden", "Donald Trump", "Barack Obama", "George W. Bush"}, 1},
            {"What is the capital of Russia?", {"Moscow", "Saint Petersburg", "Kiev", "Warsaw"}, 1},
            {"Who is the Prime Minister of the United Kingdom?", {"Boris Johnson", "Theresa May", "David Cameron", "Tony Blair"}, 1},
            {"Which political ideology advocates for social equality and communal ownership?", {"Capitalism", "Socialism", "Liberalism", "Conservatism"}, 2},
            {"Which country has the oldest continuously operating democracy?", {"USA", "France", "Switzerland", "Greece"}, 1},
            {"What is the political system in which power is held by a single person?", {"Monarchy", "Oligarchy", "Autocracy", "Democracy"}, 3},
            {"Who wrote 'The Communist Manifesto'?", {"Karl Marx and Friedrich Engels", "Vladimir Lenin", "Joseph Stalin", "Leon Trotsky"}, 1},
            {"What is the official residence of the President of the United States?", {"White House", "Capitol Hill", "Pentagon", "Oval Office"}, 1},
            {"Which country has the largest population in the world?", {"India", "China", "USA", "Russia"}, 2},
            {"Which political leader is associated with the phrase 'I have a dream'?", {"Nelson Mandela", "Martin Luther King Jr.", "Mahatma Gandhi", "Winston Churchill"}, 2}
        },
        {
            {"Which is the largest ocean on Earth?", {"Atlantic Ocean", "Indian Ocean", "Pacific Ocean", "Arctic Ocean"}, 3},
            {"Who is the author of 'Harry Potter' series?", {"J.K. Rowling", "Stephen King", "George R.R. Martin", "Dan Brown"}, 1},
            {"What is the currency of Japan?", {"Yuan", "Yen", "Dollar", "Euro"}, 2},
            {"Which is the tallest mountain in the world?", {"Mount Everest", "K2", "Kangchenjunga", "Makalu"}, 1},
            {"Who invented the telephone?", {"Alexander Graham Bell", "Thomas Edison", "Nikola Tesla", "Guglielmo Marconi"}, 1},
            {"Which is the largest desert in the world?", {"Gobi Desert", "Sahara Desert", "Arabian Desert", "Kalahari Desert"}, 2},
            {"Who painted the Mona Lisa?", {"Leonardo da Vinci", "Vincent van Gogh", "Pablo Picasso", "Michelangelo"}, 1},
            {"What is the national animal of Australia?", {"Kangaroo", "Emu", "Koala", "Platypus"}, 1},
            {"Which planet is known as the 'Morning Star' or 'Evening Star'?", {"Mars", "Venus", "Jupiter", "Saturn"}, 2},
            {"Who was the first man to walk on the moon?", {"Neil Armstrong", "Buzz Aldrin", "Yuri Gagarin", "Alan Shepard"}, 1}
        }
    };

    int quizTimeLimit = 300;
    vector<int> scores(allQuizzes.size(), 0);
       cout << "Welcome to the Ultimate Quiz Challenge!" << endl;
    for (size_t i = 0; i < allQuizzes.size(); ++i) {
        const auto& topicQuiz = allQuizzes[i];
        cout << "\nTopic: ";
        if (i == 0) {
            cout << "History";
        } else if (i == 1) {
            cout << "Sports";
        } else if (i == 2) {
            cout << "Science";
        } else if (i == 3) {
            cout << "Politics";
        } else if (i == 4) {
            cout << "General Knowledge (GK)";
        }
        cout << " Quiz" << endl;
        int score = 0;
        int totalQuestions = 0;
        conductQuiz(topicQuiz, quizTimeLimit, score, totalQuestions);
        scores[i] = score;
    }
    cout << "\n\nFinal Scores:" << endl;
    for (size_t i = 0; i < allQuizzes.size(); ++i) {

        if (i == 0) {
            cout << "History";
        } else if (i == 1) {
            cout << "Sports";
        } else if (i == 2) {
            cout << "Science";
        } else if (i == 3) {
            cout << "Politics";
        } else if (i == 4) {
            cout << "General Knowledge (GK)";
        }
        cout << ": " << scores[i] << " out of " << allQuizzes[i].size() << endl;
    }

    return 0;
}

