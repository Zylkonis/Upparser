//
// Created by PC on 29/11/2024.
//

#ifndef CMD_H
#define CMD_H
#include <string>
#include <vector>


class Cmd {
protected:
    std::string name;
    std::vector<std::string> alias;
    int narg;
    std::vector<std::string> args;
    std::string description;
    bool must;
    bool instant;

public:
    friend class Parser;

    virtual ~Cmd() = default;
    virtual void affectArg(const std::vector<std::string>& lArgs) = 0;
    virtual void execute() = 0;

    Cmd(const std::string &name, const std::vector<std::string> &alias, int narg, std::string description, bool must, bool instant);

    std::string getName() const;
    bool isName(const std::string& n) const;

    void setAlias(const std::vector<std::string>& alias);
    const std::vector<std::string>& getAlias() const;
    bool isAlias(const std::string& a);

    std::string getDescription() const;

    bool isMust() const;
    bool isInstant() const;
};

#endif //CMD_H
