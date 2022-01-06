#include "../core/Mat.h"
#include <random>

static const ll128 min128 = std::numeric_limits<ll128>::min();
static const ll128 max128 = std::numeric_limits<ll128>::max();
static const ll min64 = std::numeric_limits<ll>::min();
static const ll max64 = std::numeric_limits<ll>::max();

int dim = 200;
int PRINT_DETAIL = 0;

Mat rand_mat(int r, int c) {
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<ll128> val(min64, max64);

    Mat a(r, c);
    for (int i =0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            a(i, j) = val(eng);
        }
    }
    return a;
}

void test_mul() {
    int rows = dim, cols = dim;

    Mat a = rand_mat(rows, cols);
    Mat b = rand_mat(rows, cols);

    auto start = std::chrono::system_clock::now();
    Mat c = a * b;
    auto end = std::chrono::system_clock::now();

    if (PRINT_DETAIL) {
        a.print("a");
        b.print("b");
        c.print("c");
    }

    std::cout << "bit=128" << ", dim=" << dim << ", time of queqiao: " << (end - start).count() / 1e6 << "ms" << std::endl;
}

int main(int argc, char** argv) {
    test_mul();
}