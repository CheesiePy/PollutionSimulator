#ifndef POLLUTIONSIMULATOREXTEND_SORTEDPAIR_H
#define POLLUTIONSIMULATOREXTEND_SORTEDPAIR_H
#include <iostream>

template <class K, class V>
class SortedPair{
public:
    SortedPair(): key(0), val(0){};
    // c'tor
    SortedPair(K& setKey, V* setVal):key(setKey),val(setVal){};
    // Big Three
    //copy c'tor
    SortedPair(const SortedPair<K, V>& sp):key(sp.getKey()),val(sp.getVal()){};
    // = operator;
    SortedPair& operator =(const SortedPair<K , V>& other){
        if(this == other)
            return *this;
        setVal(other.getVal());
        setKey(other.getKey());
        return *this;
    }
    //d'tor
    ~SortedPair(){
    }

    // Getters
    K& getKey() const {return key;};
    V* getVal() const {return val;};

    friend ostream& operator <<(ostream& out, const SortedPair<K , V>& sp) {
        out << sp.getKey();
        return out;
    }
    void setVal(V* setVal){val = setVal;}

private:
    void setKey(const K& setKey){key = setKey;}
    K& key;
    V* val;
};
template<class K, class V>
ostream& operator <<(ostream& out, const SortedPair<K , V>& sp);

#endif
