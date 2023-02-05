// date.hpp
#ifndef __FECHA_H__
#define __FECHA_H__

#include <iostream>
#include <string>

class Date {
 private:
  int day, month, year;

 public:
  Date();
  Date(const int&, const int&, const int&);

  void setDay(const int&);
  int getDay() const;

  void setMonth(const int&);
  int getMonth() const;

  void setYear(const int&);
  int getYear() const;

  std::string toString() const;

  Date& operator=(const Date&);
};

#endif  // __FECHA_H__