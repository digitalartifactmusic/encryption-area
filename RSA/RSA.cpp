#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include <boost/multiprecision/cpp_int.hpp>

using namespace boost::multiprecision;

using namespace std;

int main()
{
    long long primeOne = 456457;
    long long primeTwo = 654397;

    long long n = primeOne * primeTwo;                  // Hard Code Prime Factorization
    long long e = 17;

    long long m = (primeOne - 1) * (primeTwo - 1);
    long long d = 175707635633;                         // Hard Code Modular Multiplicative Inverse

    string input = "THANKYOUNOAHIFYOUCANREADTHISTHENYOUHAVESUCCESSFULLYCOMPLETEDTHEASSIGNMENTEMAILMETHISBACK";

    // ENCRYPT

    vector<unsigned short> c;

    long long a = 0;
    long long b = 25;
    unsigned blockSize = 0;
    long long i = 1;
    while (!(n > a&& n < b))
    {
        a += 25 * i;
        b += 25 * i * 100;
        i *= 100;
        blockSize += 2;
    }
    cout << "Block Size: " << blockSize << endl << endl;

    input.resize(((input.length() / (blockSize / 2)) + 1) * (blockSize / 2), 'X');

    for (long long j = 0; j < input.length(); j += blockSize / 2)
    {
        long long temp = 0, tens = 1;
        for (long long k = (blockSize / 2) - 1; k >= 0; k--)
        {
            temp += (input[j + k] - 'A') * tens;
            tens *= 100;
        }
        tens /= 100;

        cout << "Block " << j / (blockSize / 2) << ": " << temp << endl;

        temp = powm(temp, e, n);

        cout << " \tEncrypted: " << temp << endl << endl;

        while(tens)
        {
     
            c.push_back(temp / tens);
            temp %= tens;
            tens /= 100;
        }
    }

    cout << primeOne << endl;
    cout << primeTwo << endl << endl;

    cout << e << endl;
    cout << n << endl << endl;

    cout << d << endl;
    cout << n << endl << endl;

    cout << m << endl << endl;

    for (auto itr : c)
    {
        cout << itr << " ";
    }

    cout << endl << endl;

    
    // DECRYPT //

    n = 298704091429;                           // Hard Code Prime Factorization
    e = 17;

    d = 175707635633;                           // Hard Code Modular Multiplicative Inverse

    string decrypted;

    a = 0;
    b = 25;
    blockSize = 0;
    i = 1;
    while (!(n > a&& n < b))
    {
        a += 25 * i;
        b += 25 * i * 100;
        i *= 100;
        blockSize += 2;
    }
    cout << "Block Size: " << blockSize << endl << endl;

    for (long long i = 0; i < c.size(); i += (blockSize / 2))
    {
        long long temp = 0;
        long long tens = pow(10, blockSize - 2);

        int j = 0;
        while(tens)
        {
            temp += c[i + j] * tens;
            tens /= 100;
            j++;
        }

        cout << "Block " << i / (blockSize / 2) << ": " << temp << endl;

        temp = powm(temp, d, n);

        cout << " \tDecrypted: " << temp << endl << endl;

        tens = pow(10, blockSize - 2);
        while(tens)
        {
            decrypted.push_back((temp / tens) + 'A');
            temp %= tens;
            tens /= 100;
        }
    }

    cout << decrypted;

    cout << endl << endl;

    return 0;
}
