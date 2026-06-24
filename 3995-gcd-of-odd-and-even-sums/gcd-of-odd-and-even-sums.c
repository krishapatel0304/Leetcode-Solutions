int gcdOfOddEvenSums(int n) {
    long sumOdd=n*n;
    long sumEven=n*(n+1);
    long a=sumOdd, b=sumEven;
    while(b!=0){
        long temp=b;
        b=a%b;
        a=temp;
    }  
    return a;
}