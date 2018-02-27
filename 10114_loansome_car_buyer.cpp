#include <iostream>

/*
input:
duration of loan (month), the down payment, 
the amount of loan, the number of deprecation records (follow)
month num, deprecation %
*/

int main(int argc, const char * argv[]) {
    int duration = 0, d_record = 0;
    float loan = 0, down_payment = 0;
    while(std::cin >> duration >> down_payment >> loan >> d_record) {
        if (duration <= 0) break;

        int record_count = 0, month = 0;
        float d_percent = 0;
        float car_val = 0, borrower_val = 0;
        float monthlyPayment = loan / duration, decP[101];

        while (d_record--)
        {
            std::cin >> month >> d_percent;
            for (int i = month; i < 101; i++)
                decP[i] = d_percent;
        }

        int cur = 0;
        car_val = (loan + down_payment) * (1 - decP[cur]);
        borrower_val = loan;

        while(car_val < borrower_val) {
            cur++;
            car_val *= (1 - decP[cur]);
            borrower_val -= monthlyPayment;
        }

        if (cur == 1) 
            std::cout << cur << " month" << std::endl;
        else
            std::cout << cur << " months" << std::endl;
    }

    return 0;
}
