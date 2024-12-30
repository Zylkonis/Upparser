//
// Created by PC on 29/11/2024.
//

#ifndef CIBLES_H
#define CIBLES_H
#include <string>
#include <vector>


class Cible {
    std::vector<std::string> cibles;
    std::string description;
    bool empty;

    public:
    explicit Cible(std::string  description = "No description", bool empty = true);
    explicit Cible(std::vector<std::string> cibles, std::string description = "No description", bool empty = true);

    const std::vector<std::string>& getCibles() const;
    std::string getCible(int i) const;
    void addCible(std::string cible);

    const std::string& getDescription() const;
    void setDescription(std::string des);
};



#endif //CIBLES_H
