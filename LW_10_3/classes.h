#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <type_traits>

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

template <typename Tname, typename Tlifetime, typename TDOB>
class Plant {
private:
	std::string name;
	int lifetime; // lifetime_in_days
	Data day_of_born;
public:
	Plant(Tname name_ = "Bob", Tlifetime lifetime_ = 365, TDOB day_of_born_ = { 0, 0 }) {
		static_assert(
			std::is_same_v<Tname, std::string> &&
			std::is_same_v<Tlifetime, int> &&
			std::is_same_v<TDOB, Data>,
			"Неккоректные типы данных \n");
		this->name = name_;
		this->lifetime = lifetime_;
		this->day_of_born = day_of_born_;
	}
	void set_name(Tname new_name) {
		static_assert(std::is_same_v<Tname, std::string>, "Требуется std::string!");
		name = new_name;
	}
	void set_lifetime(Tlifetime new_lifetime) {
		static_assert(std::is_same_v<Tlifetime, int>, "Требуется int");
		lifetime = new_lifetime;
	}
	void set_day_of_born(TDOB new_day_of_born) {
		static_assert(std::is_same_v<TDOB, Data>, "Требуется Data");
		day_of_born = new_day_of_born;
	}

	std::string get_name() const { return name; }
	int get_lifetime() const { return lifetime; }
	Data get_day_of_born() const { return day_of_born; }

	void print(std::ostream& os = std::cout) const { // нейронка подсказала
		std::cout << "name - " << name << '\n' << "lifetime - " << lifetime << "\n" << "day when he/she was plant" << day_of_born << "\n";
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
	void infromation_to_file(std::string path) {
		std::ofstream out;
		out.open(path);
		if (out.is_open()) {
			print(out);
		}
		else {
			throw std::runtime_error("Не удалось открыть файл: " + path);
		}

	}

};
template <typename Tname, typename TLifetime, typename TDOB, typename TBloomStart = Data, typename TBloomDuration = int>
class Flower : public Plant<std::string, int, Data> {
private:
	TBloomStart bloom_starting;
	TBloomDuration bloom_duration;
public:
	Flower(Tname name_ = "Bob", TLifetime lifetime_ = 365, TDOB day_of_born_ = { 0, 0 }, TBloomStart bloom_starting_ = { 0, 0 }, TBloomDuration bloom_duration_ = 1) :
		Plant<std::string, int, Data>(name_, lifetime_, day_of_born_), bloom_starting(bloom_starting_), bloom_duration(bloom_duration_) {
		this->bloom_starting = bloom_starting_;
		this->bloom_duration = bloom_duration_;
	};
	void set_bloom_starting(TBloomStart new_bloom_data) {
		static_assert(std::is_same_v<TBloomStart, Data>, "Требуется Data");
		bloom_starting = new_bloom_data;
	}
	void set_bloom_duration(TBloomDuration new_b_d) {
		static_assert(std::is_same_v<TBloomDuration, int>, "Требуется int");
		bloom_duration = new_b_d;
	}
	Data get_bloom_starting() {
		return bloom_starting;
	}
	int get_bloom_duration() {
		return bloom_duration;
	}
	void print(std::ostream& os = std::cout) {
		Plant<std::string, int, Data>::print();
		std::cout << "blosom starting in " << bloom_starting << "\n"
			<< "blossom will continue for " << bloom_duration << " days" << "\n";
	}
	void information_to_file(std::string path) {
		std::ofstream out;
		out.open(path);
		if (out.is_open()) {
			print(out);
		}
		else {
			throw std::runtime_error("Не удалось открыть файл: " + path);
		}
	}
};