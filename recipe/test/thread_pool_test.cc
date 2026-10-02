#include <stdio.h>

#include <atomic>
#include <string>

#include "hwy/contrib/thread_pool/thread_pool.h"
#include "hwy/stats.h"

int main() {
  hwy::ThreadPool pool(2);
  std::atomic<uint64_t> sum{0};
  pool.Run(0, 100, [&](uint64_t task, size_t /*thread*/) { sum += task; });
  if (sum.load() != 4950) {
    fprintf(stderr, "unexpected sum %llu\n",
            static_cast<unsigned long long>(sum.load()));
    return 1;
  }

  hwy::Stats a, b;
  a.Notify(1.0f);
  b.Notify(3.0f);
  a.Assimilate(b);
  printf("%s\n", a.ToString().c_str());
  return 0;
}
