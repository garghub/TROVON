int *__atomic_hashed_lock(volatile void *v)
{
unsigned long ptr = __insn_mm((unsigned long)v >> 1,
(unsigned long)atomic_locks,
2, (ATOMIC_HASH_SHIFT + 2) - 1);
return (int *)ptr;
}
static int is_atomic_lock(int *p)
{
return p >= &atomic_locks[0] && p < &atomic_locks[ATOMIC_HASH_SIZE];
}
void __atomic_fault_unlock(int *irqlock_word)
{
BUG_ON(!is_atomic_lock(irqlock_word));
BUG_ON(*irqlock_word != 1);
*irqlock_word = 0;
}
static inline int *__atomic_setup(volatile void *v)
{
*(volatile int *)v;
return __atomic_hashed_lock(v);
}
int _atomic_xchg(int *v, int n)
{
return __atomic_xchg(v, __atomic_setup(v), n).val;
}
int _atomic_xchg_add(int *v, int i)
{
return __atomic_xchg_add(v, __atomic_setup(v), i).val;
}
int _atomic_xchg_add_unless(int *v, int a, int u)
{
return __atomic_xchg_add_unless(v, __atomic_setup(v), u, a).val;
}
int _atomic_cmpxchg(int *v, int o, int n)
{
return __atomic_cmpxchg(v, __atomic_setup(v), o, n).val;
}
unsigned long _atomic_or(volatile unsigned long *p, unsigned long mask)
{
return __atomic_or((int *)p, __atomic_setup(p), mask).val;
}
unsigned long _atomic_and(volatile unsigned long *p, unsigned long mask)
{
return __atomic_and((int *)p, __atomic_setup(p), mask).val;
}
unsigned long _atomic_andn(volatile unsigned long *p, unsigned long mask)
{
return __atomic_andn((int *)p, __atomic_setup(p), mask).val;
}
unsigned long _atomic_xor(volatile unsigned long *p, unsigned long mask)
{
return __atomic_xor((int *)p, __atomic_setup(p), mask).val;
}
long long _atomic64_xchg(long long *v, long long n)
{
return __atomic64_xchg(v, __atomic_setup(v), n);
}
long long _atomic64_xchg_add(long long *v, long long i)
{
return __atomic64_xchg_add(v, __atomic_setup(v), i);
}
long long _atomic64_xchg_add_unless(long long *v, long long a, long long u)
{
return __atomic64_xchg_add_unless(v, __atomic_setup(v), u, a);
}
long long _atomic64_cmpxchg(long long *v, long long o, long long n)
{
return __atomic64_cmpxchg(v, __atomic_setup(v), o, n);
}
long long _atomic64_and(long long *v, long long n)
{
return __atomic64_and(v, __atomic_setup(v), n);
}
long long _atomic64_or(long long *v, long long n)
{
return __atomic64_or(v, __atomic_setup(v), n);
}
long long _atomic64_xor(long long *v, long long n)
{
return __atomic64_xor(v, __atomic_setup(v), n);
}
struct __get_user __atomic_bad_address(int __user *addr)
{
if (unlikely(!access_ok(VERIFY_WRITE, addr, sizeof(int))))
panic("Bad address used for kernel atomic op: %p\n", addr);
return (struct __get_user) { .err = -EFAULT };
}
void __init __init_atomic_per_cpu(void)
{
BUILD_BUG_ON(ATOMIC_HASH_SIZE & (ATOMIC_HASH_SIZE-1));
BUG_ON(ATOMIC_HASH_SIZE < nr_cpu_ids);
BUG_ON((unsigned long)atomic_locks % PAGE_SIZE != 0);
BUILD_BUG_ON(ATOMIC_HASH_SIZE * sizeof(int) > PAGE_SIZE);
BUILD_BUG_ON((PAGE_SIZE >> 3) > ATOMIC_HASH_SIZE);
}
