bool palindrome(string s){
    for(int i = 0, j = s.size()-1; i < j; i++, j--){
        while(isalnum(s[i]) == false && i < j) i++;
        while(isalnum(s[j]) == false && i < j) j--;
        if(toupper(s[i]) != toupper(s[j]) ) return false;
    }
    return true;
}
//https://leetcode.com/problems/valid-palindrome/solutions/40048/here-s-a-clean-c-solution/?orderBy=most_votes
