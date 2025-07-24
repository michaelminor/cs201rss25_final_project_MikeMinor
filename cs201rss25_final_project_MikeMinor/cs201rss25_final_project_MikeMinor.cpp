#include "StudentQuizInfo.h"
#include <iostream>
#include <vector>

int main() {
    std::string correctAnswers;
    std::vector<StudentQuizInfo*> students;

    readQuizData("quiz_data.txt", correctAnswers, students);
    writeResults("quiz_results.txt", students);
    cleanUp(students);

    std::cout << "Grading complete. Results saved to quiz_results.txt\n";
    return 0;
}
