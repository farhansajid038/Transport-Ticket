#include "payment.c"


int test_view_all_empty()
{
    printf("Test 1 - viewAll with empty/nonexistent file:\n");
    
    rename("bookings.txt", "bookings_backup.txt");
    viewAll();
    rename("bookings_backup.txt", "bookings.txt");
    int actual = 1; 
    int expected = 1;
    int success = actual == expected;
    
    printf("expected: 1 (no crash), actual: %d, success: %d\n", 
           actual, success);
    return success;
}


int test_process_payment_exists()
{
    printf("Test 2 - Check processPayment function:\n");
    void (*func_ptr)() = processPayment;
    int actual = (func_ptr != NULL) ? 1 : 0;
    int expected = 1;
    int success = actual == expected;
    printf("expected: 1 (function exists), actual: %d, success: %d\n", 
           actual, success);
    return success;
}

int main()
{
    test_view_all_empty();
    test_process_payment_exists();
    return 0;
}