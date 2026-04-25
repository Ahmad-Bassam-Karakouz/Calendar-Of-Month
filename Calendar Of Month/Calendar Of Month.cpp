#include <iostream>
#include<cctype>
#include<string>
#include<string.h>
#include<iomanip>

using namespace std;

// ﬁ—«¡… «·”‰… „‰ «·„” Œœ„ .
short read_year()
{
	short y = 0;
	cout << " \nplease enter a year :";
	cin >> y;
	return y;
}

// ﬁ—«¡… «·‘Â— „‰ «·„” Œœ„ .
short read_month()
{
	short m = 0;
	cout << " \nplease enter a month :";
	cin >> m;
	return m;
}

// «· Õﬁﬁ „‰ «·”‰… «–« ﬂ«‰  ﬂ»Ì”… «„ ·« .
bool is_leap_year(short year)
{
	return (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0));
}

// «Ì«„ «·‘Â— .
short days_of_month(short month, short year)
{
	if (month < 1 || month>12)
	{
		return 0;
	}
	short array_for_days_of_month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

	return ((month == 2) ? is_leap_year(year) ? 29 : 28 : array_for_days_of_month[month]);
}

//  — Ì» «Ê· ÌÊ„ «·‘Â— ›Ì «·«”»Ê⁄ .  
short day_order(short year, short month, short day = 1)
{
	short a = ((14 - month) / 12);
	short y = year - a;
	short m = month + (12 * a) - 2;
	short d = (day + year + (year / 4) - (year / 100) + (year / 400) + ((31 * m) / 12)) % 7;
	return d;
}

// «”„ «·‘Â— .
string month_name(short month)
{
	string  array_of_month_name[13] = { "","Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec" };
	return array_of_month_name[month];
}

// «”„«¡ «Ì«„ «·«”»Ê⁄ .
string days_of_week()
{
	return ("  Sun  Mon  Tue  Wed  Thu  Fri  Sat  \n");
}

// ÿ»«⁄… «· ﬁÊÌ„ «·‘Â—Ì .
void print_calendar_of_month(short month, short year)
{
	cout << "  \n\n  _______________" << month_name(month) << "_______________\n\n";
	cout << days_of_week() << "\n";

	int i;
	for (i = 0; i < day_order(year, month, 1); i++)
	{
		printf("     ");
	}
	for (short ii = 1; ii <= days_of_month(month, year); ii++)
	{
		printf("%5d", ii);
		if (++i == 7)
		{
			i = 0;
			cout << "\n";
		}
	}
	cout << "\n  _________________________________\n";

}

int main()
{
	short year = read_year();
	short month = read_month();
	print_calendar_of_month(month, year);
}
