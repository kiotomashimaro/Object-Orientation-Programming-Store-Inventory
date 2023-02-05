// date.cpp

#include "date.hpp"

Date::Date() {
  day = 0;
  month = 0;
  year = 0;
}
Date::Date(const int& d, const int& m, const int& y)
    : day(d), month(m), year(y) {}

void Date::setDay(const int& d) { day = d; }

int Date::getDay() const { return day; }

void Date::setMonth(const int& m) { month = m; }

int Date::getMonth() const { return month; }

void Date::setYear(const int& y) { year = y; }

int Date::getYear() const { return year; }

std::string Date::toString() const {
  std::string temp;
  char output[50];

  sprintf(output, "%d", day);
  temp += output;
  temp += "/";
  sprintf(output, "%d", month);
  temp += output;
  temp += "/";
  sprintf(output, "%d", year);
  temp += output;

  return temp;
}

Date& Date::operator=(const Date& other) {
  this->day = other.getDay();
  this->month = other.getMonth();
  this->year = other.getYear();

  return *this;
}
