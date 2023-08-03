int gilMotivation(int a) {
    if (a >= 999999999) {
        return 112;
    }

    int motivation = 0;
    while (a > 1) {
        a >>= 1; // Right shift by 1 (equivalent to dividing by 2)
        motivation += 4;
    }

    return motivation;
}
