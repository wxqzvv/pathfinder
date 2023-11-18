int mx_atoi(const char *str) {
    int i;
    long long verification = 0;

    // verification for negative sign
    if (str[0] == '-') {
        // verification if the next character is a valid digit or not
        if (str[1] == 45 || !(str[1] >= 48 && str[1] <= 57) ||
            (str[1] == ' ' || str[1] == '\t' || str[1] == '\n' ||
             str[1] == '\v' || str[1] == '\f' || str[1] == '\r')) {
            return 0;
        }

        // Convert the string to a negative integer
        for (i = 1; (str[i] >= 48 && str[i] <= 57) &&
                    !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
                      str[i] == '\v' || str[i] == '\f' || str[i] == '\r');
             i++) {
            verification = (str[i] - '0') + (10 * verification);
        }

        // Handle overflow
        while (verification < -2147483647 - 1) {
            verification = verification + 2147483647 + 2147483647;
        }

        return -(int)verification;
    }

    // Convert the string to a positive integer
    for (i = 0; ((str[i] >= 48 && str[i] <= 57) &&
                 !(str[i] == ' ' || str[i] == '\t' || str[i] == '\n' ||
                   str[i] == '\v' || str[i] == '\f' || str[i] == '\r'));
         i++) {
        verification = (verification * 10) + (str[i] - '0');
    }

    // Handle overflow
    while (verification >= 2147483647) {
        return -1;
    }

    return (int)verification;
}
