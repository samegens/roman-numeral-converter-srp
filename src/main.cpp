#include <iostream>
#include <string>
using namespace std;

class RomanDigitConverter
{
public:
    static int ToDecimal(char romanDigit)
    {
        if (romanDigit == 'I')
        {
            return 1;
        }
        else if (romanDigit == 'V')
        {
            return 5;
        }
        else if (romanDigit == 'X')
        {
            return 10;
        }
        else if (romanDigit == 'L')
        {
            return 50;
        }
        else if (romanDigit == 'C')
        {
            return 100;
        }
        else if (romanDigit == 'D')
        {
            return 500;
        }
        else if (romanDigit == 'M')
        {
            return 1000;
        }
        else
        {
            return 0;
        }
    }
};

class RomanSegment
{
public:
    RomanSegment(char leftDigit, char rightDigit = '\0') : _leftRomanDigit(leftDigit),
                                                           _rightRomanDigit(rightDigit)
    {
    }

    int ToDecimalNumber() const
    {
        int leftDecimalNumber = RomanDigitConverter::ToDecimal(_leftRomanDigit);
        int rightDecimalNumber = RomanDigitConverter::ToDecimal(_rightRomanDigit);
        if (IsSubtractivePair())
        {
            return rightDecimalNumber - leftDecimalNumber;
        }

        return leftDecimalNumber;
    }

private:
    bool IsSubtractivePair() const
    {
        return _rightRomanDigit > 0;
    }

    char _leftRomanDigit;
    char _rightRomanDigit;
};

class RomanNumberTokenizer
{
public:
    RomanNumberTokenizer(string romanNumber) : _romanNumber(romanNumber),
                                               _currentCharIndex(0)
    {
    }

    bool HasNextSegment() const
    {
        return _currentCharIndex < _romanNumber.length();
    }

    RomanSegment GetNextSegment()
    {
        string currentPair = GetCurrentPair();
        if (IsSubtractivePair(currentPair))
        {
            _currentCharIndex += 2;
            return RomanSegment(currentPair.at(0), currentPair.at(1));
        }

        _currentCharIndex++;
        return RomanSegment(currentPair.at(0));
    }

private:
    string GetCurrentPair()
    {
        if (_currentCharIndex < _romanNumber.length() - 1)
        {
            return _romanNumber.substr(_currentCharIndex, 2);
        }

        if (_currentCharIndex < _romanNumber.length())
        {
            return string(1, _romanNumber.at(_currentCharIndex));
        }

        return string();
    }

    bool IsSubtractivePair(string romanDigitPair)
    {
        return romanDigitPair == "IV" ||
               romanDigitPair == "IX" ||
               romanDigitPair == "XL" ||
               romanDigitPair == "XC" ||
               romanDigitPair == "CD" ||
               romanDigitPair == "CM";
    }

    string _romanNumber;
    int _currentCharIndex;
};

class RomanNumberConverter
{
public:
    int ToDecimal(string romanNumber)
    {
        int decimalNumber = 0;
        auto tokenizer = RomanNumberTokenizer(romanNumber);

        while (tokenizer.HasNextSegment())
        {
            RomanSegment romanSegment = tokenizer.GetNextSegment();
            decimalNumber += romanSegment.ToDecimalNumber();
        }

        return decimalNumber;
    }
};

int
main(int argc, char *argv[])
{
    if (argc != 2)
    {
        cout << "Usage: " << argv[0] << " <roman_numeral>" << endl;
        return 1;
    }

    string roman_input = argv[1];

    auto romanNumberConverter = RomanNumberConverter();
    int decimalNumber = romanNumberConverter.ToDecimal(roman_input);

    cout << decimalNumber << endl;

    return 0;
}
