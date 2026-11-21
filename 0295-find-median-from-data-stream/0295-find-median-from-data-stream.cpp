
class MedianFinder {
private:
    priority_queue<int> small;

    priority_queue<int, vector<int>, greater<int>> large;

public:
    MedianFinder() {
    }

    void addNum(int num) {

        // Add to the smaller half
        small.push(num);

        // Move largest element of small to large
        large.push(small.top());
        small.pop();

        // Balance the heaps
        if (large.size() > small.size()) {
            small.push(large.top());
            large.pop();
        }
    }

    double findMedian() {

        if (small.size() > large.size()) {
            return small.top();
        }

        return (small.top() + large.top()) / 2.0;
    }
};
