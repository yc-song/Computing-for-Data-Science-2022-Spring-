#include <cstdlib>
#include <iostream>
#include <math.h>
#include <vector>

void countPrimes(unsigned int m, unsigned int n);
int main() {
   unsigned int start_num;
    unsigned int end_num;
  std::cout << "Find prime number within a range:\n";
  std::cout << "--------------------------------------\n";
  std::cout << "-> The start of the range: ";
    std::cin >> start_num;
  std::cout << "-> The end of the range: ";
    std::cin >> end_num;
    std::cout << "\nThe prime numbers between " << start_num
          << " and " << end_num << " are:" << std::endl;
    countPrimes(start_num, end_num);
    return EXIT_SUCCESS;

}
void  countPrimes(unsigned int m, unsigned int n) {
    std::vector<unsigned int> primenumber = {2};
    std::vector<unsigned int>::iterator iter;

    for (unsigned int m = *(primenumber.begin()) + 1; m <= n; m++) {
        for (iter = primenumber.begin();
            iter != primenumber.end(); iter++) {
            if (m >= pow(*(iter)-1, 2)) {
                if (iter != primenumber.end() - 1) {
                    if (m % *iter == 0) break;
                    if (pow(*(iter + 1) - 1, 2) > m && m % *iter != 0) {
                        primenumber.push_back(m);
                        break;
                    }
                }
                    else if (m % *iter != 0) {
                        primenumber.push_back(m);
                        break;
                    }
                }
            }
        }
    

    for (iter = primenumber.begin(); iter != primenumber.end(); iter++) {
        if (*iter>=m) std::cout << *iter <<" ";
    }

}
