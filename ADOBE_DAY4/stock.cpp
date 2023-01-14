class StockPrice {
public:
map<int,int>rec;
multiset<int>count;
    StockPrice() {
        rec.clear();
        count.clear();
    }
    
    void update(int timestamp, int price) {
        if(rec.find(timestamp)!=rec.end())
        count.erase(count.find(rec[timestamp]));
        rec[timestamp]=price;
        count.insert(price);
            }
    
    int current() {
        return (rec.rbegin())->second;
    }
    
    int maximum() {
        return *(count.rbegin());
    }
    
    int minimum() {
        return *(count.begin());
    }
};

/**
 * Your StockPrice object will be instantiated and called as such:
 * StockPrice* obj = new StockPrice();
 * obj->update(timestamp,price);
 * int param_2 = obj->current();
 * int param_3 = obj->maximum();
 * int param_4 = obj->minimum();
 */
