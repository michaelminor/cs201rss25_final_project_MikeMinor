#include "StudentQuizInfo.h"
#include <fstream>
#include <sstream>
#include <iostream>

void readQuizData(const std::string& filename, std::string& correctAnswers,
    std::vector<StudentQuizInfo*>& students) {
    std::ifstream inFile(filename);
    if (!inFile) {
        std::cerr << "Error opening input file.\n";
        return;
    }

    std::getline(inFile, correctAnswers);  // First line: correct answers

    std::string line;
    while (std::getline(inFile, line)) {
        std::istringstream iss(line);
        StudentQuizInfo* student = new StudentQuizInfo;
        iss >> student->studentID >> student->studentAnswers;
        student->correctCount = 0;  // Initialize
        calculateScores(correctAnswers, student);
        students.push_back(student);
    }

    inFile.close();
}

void calculateScores(const std::string& correctAnswers, StudentQuizInfo* studentPtr) {
    for (size_t i = 0; i < correctAnswers.size(); ++i) {
        if (i < studentPtr->studentAnswers.size() && studentPtr->studentAnswers[i] == correctAnswers[i]) {
            studentPtr->correctCount++;
        }
    }
}

void writeResults(const std::string& filename, const std::vector<StudentQuizInfo*>& students) {
    std::ofstream outFile(filename);
    if (!outFile) {
        std::cerr << "Error opening output file.\n";
        return;
    }

    outFile << "STUD ID CORRECT\n";
    for (const auto& student : students) {
        outFile << student->studentID << " " << student->correctCount << "\n";
    }

    outFile.close();
}

void cleanUp(std::vector<StudentQuizInfo*>& students) {
    for (auto student : students) {
        delete student;
    }
    students.clear();
}
