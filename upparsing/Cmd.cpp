//
// Created by PC on 29/11/2024.
#include <utility>

#include "Parser.h"
#include "Cmd.h"

Cmd::Cmd(const std::string &name, const std::vector<std::string> &alias, const int narg, std::string description, const bool must, const bool instant) :
 name("--" + name), narg(narg), description(std::move(description)), must(must), instant(instant) {
 setAlias(alias);
}


std::string Cmd::getName() const {
 return name;
}

bool Cmd::isName(const std::string& n) const {
 return n == name;
}


void Cmd::setAlias(const std::vector<std::string>& la) {
 std::vector<std::string> aliases;
 for (const std::string& alia : la) {
  aliases.push_back("-" + alia);
 }
 this->alias = aliases;
}

const std::vector<std::string>& Cmd::getAlias() const {
 return alias;
}

bool Cmd::isAlias(const std::string& a) {
 for (const std::string& alias : alias) {
  if (alias == a) {
   return true;
  }
 }
 return false;
}


std::string Cmd::getDescription() const {
 return description;
}


bool Cmd::isMust() const {
 return must;
}

bool Cmd::isInstant() const {
 return instant;
}


