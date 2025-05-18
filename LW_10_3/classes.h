#pragma once
#include <iostream>
#include <string>
#include <type_traits>
#include <fstream>

class Data {
private:
	int day;
	int month;
public:
	Data(int day_ = 0, int month_ = 0) {
		day = day_;
		month = month_;
	}
	int get_day() const {
		return day;
	}
	int get_month() const {
		return month;
	}
	void set_day(int new_day) {
		day = new_day;
	}
	void set_month(int new_month) {
		month = new_month;
	}
	Data operator + (const Data& alt) {
		int delta_day = (day + alt.day) % 30;
		int delta_month = month + alt.month + (day + alt.day) / 30;
		return Data{ delta_day, delta_month };
	}
	bool operator == (const Data& alt) {
		if (day == alt.day && month == alt.month) {
			return 1;
		}
		return 0;
	}
};
std::ostream& operator <<(std::ostream& stream, const Data& moment) {
	stream << "month - ";
	stream << moment.get_month() << "\t";
	stream << "day - ";
	stream << moment.get_day();
	return stream;
}

class Plant {
private:
	std::string name;
	int lifetime;
	Data day_of_born;
public:
	Plant(std::string name_ = "Bob", int lifetime_ = 365, Data day_of_born_ = { 0, 0 }) {
		this->name = name_;
		this->lifetime = lifetime_;
		this->day_of_born = day_of_born_;
	}
	template <typename T>
	void set_name(T new_name) {
		try
		{
			if (typeid(new_name).name() != "std::string") {
				throw std::exception("Не соответствует тип данных для смены имени \n");
			}
			name = new_name;
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what();
		}
	}
	template <typename T>
	void set_lifetime(T new_lifetime) {
		try
		{
			if (typeid(new_lifetime).name() != "int") {
				throw std::exception("Не соответствует тип данных для смены времени жизни \n"); // сранно звучит
			}
			lifetime = new_lifetime;
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what();
		}
	}
	template <typename T>
	void set_day_of_born(T new_day_of_born) {
		try
		{
			if (typeid(new_day_of_born).name() != "Data") {
				throw std::exception("Не соответствует тип данных для смены даты рождения");
			}
			day_of_born = new_day_of_born;
		}
		catch (const std::exception&)
		{

		}
	}

	std::string get_name() const { return name; }
	int get_lifetime() const { return lifetime; }
	Data get_day_of_born() const { return day_of_born; }

	void print(std::ostream& os = std::cout) const {
		os << "name - " << name << '\n' << "lifetime - " << lifetime << "\n" << "day when he/she was plant" << day_of_born << "\n";
	}
	void how_old_plant() {
		int years = lifetime / 365;
		int months = (lifetime - years * 365) / 30;
		int days = lifetime - years * 365 - months * 30;
		std::cout << "your plant lived for ";
		if (years > 0) {
			std::cout << years << " years ";
		}
		if (months > 0) {
			std::cout << months << " months ";
		}
		if (days > 0) {
			std::cout << days << " days ";
		}
		std::cout << "congrats" << "\n";
	}
	void infromation_to_file(std::string paths) {
		std::ofstream out;
		
		try
		{
			out.open(paths);
			if (out.is_open() == true)
			{
				throw std::exception("Такого файла не существует");
			}
			print(out);
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what();
		}
	}

};

class Flower : public Plant{
private:
	Data bloom_starting;
	int bloom_duration;
public:
	Flower(std::string name_ = "Bob", int lifetime_ = 365, Data day_of_born_ = { 0, 0 }, Data bloom_starting_ = { 0, 0 }, int bloom_duration_ = 1) :
		Plant(name_, lifetime_, day_of_born_), bloom_starting(bloom_starting_), bloom_duration(bloom_duration_) {
		this->bloom_starting = bloom_starting_;
		this->bloom_duration = bloom_duration_;
	};
	void set_bloom_starting(Data new_bloom_starting) {
		bloom_starting = new_bloom_starting;
	}
	void set_bloom_duration(int new_b_d) {
		bloom_duration = new_b_d;
	}
	Data get_bloom_starting() {
		return bloom_starting;
	}
	int get_bloom_duration() {
		return bloom_duration;
	}
	void print(std::ostream& os = std::cout) {
		Plant::print();
		std::cout << "blosom starting in " << bloom_starting << "\n"
			<< "blossom will continue for " << bloom_duration << " days" << "\n";
	}
	void information_to_file(std::string paths) {
		std::ofstream out;
		try
		{
			out.open(paths, std::ofstream::out | std::ofstream::app);
			if (out.is_open() == true)
			{
				throw std::exception("Такого файла не существует");
			}
			print(out);
		}
		catch (const std::exception& ex)
		{
			std::cout << ex.what();
		}
	}
};