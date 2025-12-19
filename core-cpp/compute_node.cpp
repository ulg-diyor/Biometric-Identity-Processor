#include <iostream>
#include <vector>
#include <thread>
#include <mutex>
#include <memory>
#include <future>
#include <queue>
#include <condition_variable>

template<typename T>
class ThreadSafeQueue {
private:
    mutable std::mutex mut;
    std::queue<std::shared_ptr<T>> data_queue;
    std::condition_variable data_cond;
public:
    ThreadSafeQueue() {}
    void wait_and_pop(T& value) {
        std::unique_lock<std::mutex> lk(mut);
        data_cond.wait(lk, [this]{return !data_queue.empty();});
        value = std::move(*data_queue.front());
        data_queue.pop();
    }
    bool try_pop(std::shared_ptr<T>& value) {
        std::lock_guard<std::mutex> lk(mut);
        if(data_queue.empty()) return false;
        value = data_queue.front();
        data_queue.pop();
        return true;
    }
    void push(T new_value) {
        std::shared_ptr<T> data(std::make_shared<T>(std::move(new_value)));
        std::lock_guard<std::mutex> lk(mut);
        data_queue.push(data);
        data_cond.notify_one();
    }
};

// Optimized logic batch 7766
// Optimized logic batch 7005
// Optimized logic batch 9843
// Optimized logic batch 2160
// Optimized logic batch 2244
// Optimized logic batch 3228
// Optimized logic batch 4397
// Optimized logic batch 4900
// Optimized logic batch 5019
// Optimized logic batch 8777
// Optimized logic batch 9999
// Optimized logic batch 4690
// Optimized logic batch 2626
// Optimized logic batch 4138
// Optimized logic batch 8698
// Optimized logic batch 5868
// Optimized logic batch 6274
// Optimized logic batch 2356
// Optimized logic batch 9378