int *__atomic_hashed_lock(volatile void *v)
{
#if ATOMIC_LOCKS_FOUND_VIA_TABLE()
unsigned long i =
(unsigned long) v & ((PAGE_SIZE-1) & -sizeof(long long));
unsigned long n = __insn_crc32_32(0, i);
unsigned long l1_index = n >> ((sizeof(n) * 8) - ATOMIC_HASH_L1_SHIFT);
unsigned long l2_index = n & (ATOMIC_HASH_L2_SIZE - 1);
return &atomic_lock_ptr[l1_index]->lock[l2_index];
#else
unsigned long ptr = __insn_mm((unsigned long)v >> 1,
(unsigned long)atomic_locks,
2, (ATOMIC_HASH_SHIFT + 2) - 1);
return (int *)ptr;
#endif
}
static int is_atomic_lock(int *p)
{
#if ATOMIC_LOCKS_FOUND_VIA_TABLE()
int i;
for (i = 0; i < ATOMIC_HASH_L1_SIZE; ++i) {
if (p >= &atomic_lock_ptr[i]->lock[0] &&
p < &atomic_lock_ptr[i]->lock[ATOMIC_HASH_L2_SIZE]) {
return 1;
}
}
return 0;
#else
return p >= &atomic_locks[0] && p < &atomic_locks[ATOMIC_HASH_SIZE];
#endif
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
int _atomic_xchg(atomic_t *v, int n)
{
return __atomic_xchg(&v->counter, __atomic_setup(v), n).val;
}
int _atomic_xchg_add(atomic_t *v, int i)
{
return __atomic_xchg_add(&v->counter, __atomic_setup(v), i).val;
}
int _atomic_xchg_add_unless(atomic_t *v, int a, int u)
{
return __atomic_xchg_add_unless(&v->counter, __atomic_setup(v), u, a)
.val;
}
int _atomic_cmpxchg(atomic_t *v, int o, int n)
{
return __atomic_cmpxchg(&v->counter, __atomic_setup(v), o, n).val;
}
unsigned long _atomic_or(volatile unsigned long *p, unsigned long mask)
{
return __atomic_or((int *)p, __atomic_setup(p), mask).val;
}
unsigned long _atomic_andn(volatile unsigned long *p, unsigned long mask)
{
return __atomic_andn((int *)p, __atomic_setup(p), mask).val;
}
unsigned long _atomic_xor(volatile unsigned long *p, unsigned long mask)
{
return __atomic_xor((int *)p, __atomic_setup(p), mask).val;
}
u64 _atomic64_xchg(atomic64_t *v, u64 n)
{
return __atomic64_xchg(&v->counter, __atomic_setup(v), n);
}
u64 _atomic64_xchg_add(atomic64_t *v, u64 i)
{
return __atomic64_xchg_add(&v->counter, __atomic_setup(v), i);
}
u64 _atomic64_xchg_add_unless(atomic64_t *v, u64 a, u64 u)
{
return __atomic64_xchg_add_unless(&v->counter, __atomic_setup(v),
u, a);
}
u64 _atomic64_cmpxchg(atomic64_t *v, u64 o, u64 n)
{
return __atomic64_cmpxchg(&v->counter, __atomic_setup(v), o, n);
}
struct __get_user __atomic_bad_address(int __user *addr)
{
if (unlikely(!access_ok(VERIFY_WRITE, addr, sizeof(int))))
panic("Bad address used for kernel atomic op: %p\n", addr);
return (struct __get_user) { .err = -EFAULT };
}
static int __init noatomichash(char *str)
{
pr_warning("noatomichash is deprecated.\n");
return 1;
}
void __init __init_atomic_per_cpu(void)
{
#if ATOMIC_LOCKS_FOUND_VIA_TABLE()
unsigned int i;
int actual_cpu;
actual_cpu = cpumask_first(cpu_possible_mask);
for (i = 0; i < ATOMIC_HASH_L1_SIZE; ++i) {
actual_cpu = cpumask_next(actual_cpu, cpu_possible_mask);
if (actual_cpu >= nr_cpu_ids)
actual_cpu = cpumask_first(cpu_possible_mask);
atomic_lock_ptr[i] = &per_cpu(atomic_lock_pool, actual_cpu);
}
#else
BUILD_BUG_ON(ATOMIC_HASH_SIZE & (ATOMIC_HASH_SIZE-1));
BUG_ON(ATOMIC_HASH_SIZE < nr_cpu_ids);
BUG_ON((unsigned long)atomic_locks % PAGE_SIZE != 0);
BUILD_BUG_ON(ATOMIC_HASH_SIZE * sizeof(int) > PAGE_SIZE);
BUILD_BUG_ON((PAGE_SIZE >> 3) > ATOMIC_HASH_SIZE);
#endif
}
