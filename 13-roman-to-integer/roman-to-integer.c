int romanToInt(char* s) {
    int result = 0;
    int prev_value = 0;
    int length = strlen(s);
    
    for (int i = length - 1; i >= 0; i--) {
        int current_value;
        if (s[i] == 'I') {
            current_value = 1;
        } else if (s[i] == 'V') {
            current_value = 5;
        } else if (s[i] == 'X') {
            current_value = 10;
        } else if (s[i] == 'L') {
            current_value = 50;
        } else if (s[i] == 'C') {
            current_value = 100;
        } else if (s[i] == 'D') {
            current_value = 500;
        } else if (s[i] == 'M') {
            current_value = 1000;
        } else {
            current_value = 0;
        }
        if (current_value < prev_value) {
            result -= current_value;
        } else {
            result += current_value;
        }   
        prev_value = current_value;
    }
    return result;
}