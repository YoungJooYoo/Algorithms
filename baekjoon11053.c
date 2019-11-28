#include <iostream>
#define SEQUENCE_LENGTH (1000+1)
using namespace std;

int main(int argc, const char * argv[]) {
    
    int input_sequence[SEQUENCE_LENGTH] = {0,};
    int memoization[SEQUENCE_LENGTH] = {0,};
    int n = 0;
    int max = 0;
    size_t i;
    size_t j;
    
    /* 수열의 길이로 쓰는 이 배열을 전부 1로 초기화한다. 수열을 찾을때마다 +1하여 수열의 길이를 구해나간다. */
    for (i=0; i<SEQUENCE_LENGTH; i++)
        memoization[i] = 1;
    
    /* 수열의 길이와 수열의 숫자를 입력 받는다. */
    cin >> n;
    for (i=0; i<n; i++)
        cin >> input_sequence[i];
    
    /* 각 원소별로 비교하여 수열로 판단되면, 수열의 길이를 체크하는 배열에 카운팅을 한다. */
    for (i=0; i<SEQUENCE_LENGTH; i++){
        for (j=0; j<i; j++){
//            if (input_sequence[j] < input_sequence[i] && memoization[j]+1 > memoization[i])
            if (input_sequence[i] > input_sequence[j] && memoization[i] < memoization[j]+1)
                memoization[i] = memoization[j]+1;
        }
    }
    
    /* 가장 큰 카운팅 값을 찾아 출력한다. */
    for (i=0; i<SEQUENCE_LENGTH; i++){
        if(memoization[i] > max)
            max = memoization[i];
    }
    cout<<max<<endl;
    return 0;
}
