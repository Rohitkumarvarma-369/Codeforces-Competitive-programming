/*
Rohit Kumar Varma (@immortal_1)
Amrita Vishwa Vidyapeetham, Amritapuri.
*/

/*

1490/B: Balanced Remainders

Logic: Here an array of integers is given. Consider 3 variables "zero", "one", "two", we can iterate and increment zero if 
the remainder is zero to a particular element in the iteration of the array, likewise we will increment the count if one and
two. The we need to make all these 3 balanced, i.e, equal. We know that the number of remainders with 3 can only be between
0 or 1 or 2, so if one of the count variable zero or one or two is increased the other one is decreased. And also, given that
we can only "increment" the value of an element in one move, so the only following cases can happen:

0 remainder --> 1 remainder
1 remainder --> 2 remainder
2 remainder ->> 0 remainder

and the most optimal balanced target to reach is target = len(arr)/3

so till zero==one==two==target;
we increment zero if it is less than target and decrement two, cause increment in zero is due to decrement in two.
simillarly ++one, --zero
and ++two, --one.

will continue till: zero==one==two==target;

every iteration of this will do ++counter, and counter is printed!!!



*/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ll t;
	cin>>t;

	while(t--){
		ll a;
		cin>>a;

		ll arr[a];

		for(ll i=0;i<a;i++){
			cin>>arr[i];
		}
		ll zero = 0;
		ll one = 0;
		ll two = 0;
		for(ll i=0;i<a;i++){

			if(arr[i]%3==0){
				++zero;
			}
			if(arr[i]%3==1){
				++one;
			}
			if(arr[i]%3==2){
				++two;
			}

		}

		bool checker  =false;
		ll target = a/3;
		ll counter = 0;
		while(checker==false){

			if((zero==target) && (one==target) && (two==target)){
				checker=true;
				break;
				
			}


			if((zero-target)<0){
				--two;
				++zero;
				
			}
			else if((one-target)<0){
				
				--zero;
				++one;
				
			}
			else if((two-target)<0){
				
				--one;
				++two;
				
				
			}



			if(checker==false){
				++counter;
				
			}
			if((zero==target) && (one==target) && (two==target)){
				checker= true;
				
			}
		}

		cout<<counter<<endl;
	}
}