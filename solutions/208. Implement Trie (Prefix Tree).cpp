    
    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }
    
    Node* get(char ch){
        return links[ch-'a'];
    }
    
    void setEnd(){
        flag = true;
    }
    
    bool isEnd(){
        return flag == true;
    }
    
};
​
class Trie {
private: 
    Node* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new Node();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        Node* temp = root;
        for(int i=0;i<word.length();i++){
            if(!temp->containsKey(word[i])){
                temp->put(word[i],new Node());
            }
            temp = temp->get(word[i]);
        }
        temp->setEnd();
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        Node* temp = root;
        for(int i=0;i<word.length();i++){
            if(!temp->containsKey(word[i])){
                return false;
            }
            temp = temp->get(word[i]);
        }
        
        return temp->isEnd();
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        Node* temp = root;
        for(int i=0;i<prefix.length();i++){
            if(!temp->containsKey(prefix[i])){
                return false;
            }
            temp = temp->get(prefix[i]);
        }
        
        return true;
    }
};
​
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
