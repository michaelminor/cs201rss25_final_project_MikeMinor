#ifndef STUDENTQUIZINFO_H
#define STUDENTQUIZINFO_H

#include <string>
#include <vector>

struct StudentQuizInfo {
    int studentID;
    std::string studentAnswers;
    int correctCount;
};

void readQuizData(const std::string& filename, std::string& correctAnswers,
    std::vector<StudentQuizInfo*>& students);

void calculateScores(const std::string& correctAnswers, StudentQuizInfo* studentPtr);

void writeResults(const std::string& filename, const std::vector<StudentQuizInfo*>& students);

void cleanUp(std::vector<StudentQuizInfo*>& students);

#endif

