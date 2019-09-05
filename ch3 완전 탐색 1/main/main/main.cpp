//
//  main.cpp
//  main
//
//  Created by 이상아 on 05/09/2019.
//  Copyright © 2019 snaag. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 10819 차이를 최대로
int main(int argc, const char * argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n, temp, max=-1, differ=0;
    vector<int> v;
    
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> temp;
        v.push_back(temp);
    }
    sort(v.begin(), v.end());
    
    do{
        differ = 0;
        
        for(int i=1; i<n; i++)
            differ += abs(v[i-1]-v[i]);
        
        
        if(differ > max)
            max = differ;
        
    }while(next_permutation(v.begin(), v.end()));
    
    cout << max << "\n";
    
    return 0;
}
