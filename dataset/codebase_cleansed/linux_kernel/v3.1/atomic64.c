static inline spinlock_t *lock_addr(const atomic64_t *v)
{
unsigned long addr = (unsigned long) v;
addr >>= L1_CACHE_SHIFT;
addr ^= (addr >> 8) ^ (addr >> 16);
return &atomic64_lock[addr & (NR_LOCKS - 1)].lock;
}
long long atomic64_read(const atomic64_t *v)
{
unsigned long flags;
spinlock_t *lock = lock_addr(v);
long long val;
spin_lock_irqsave(lock, flags);
val = v->counter;
spin_unlock_irqrestore(lock, flags);
return val;
}
void atomic64_set(atomic64_t *v, long long i)
{
unsigned long flags;
spinlock_t *lock = lock_addr(v);
spin_lock_irqsave(lock, flags);
v->counter = i;
spin_unlock_irqrestore(lock, flags);
}
void atomic64_add(long long a, atomic64_t *v)
{
unsigned long flags;
spinlock_t *lock = lock_addr(v);
spin_lock_irqsave(lock, flags);
v->counter += a;
spin_unlock_irqrestore(lock, flags);
}
long long atomic64_add_return(long long a, atomic64_t *v)
{
unsigned long flags;
spinlock_t *lock = lock_addr(v);
long long val;
spin_lock_irqsave(lock, flags);
val = v->counter += a;
spin_unlock_irqrestore(lock, flags);
return val;
}
void atomic64_sub(long long a, atomic64_t *v)
{
unsigned long flags;
spinlock_t *lock = lock_addr(v);
spin_lock_irqsave(lock, flags);
v->counter -= a;
spin_unlock_irqrestore(lock, flags);
}
long long atomic64_sub_return(long long a, atomic64_t *v)
{
unsigned long flags;
spinlock_t *lock = lock_addr(v);
long long val;
spin_lock_irqsave(lock, flags);
val = v->counter -= a;
spin_unlock_irqrestore(lock, flags);
return val;
}
long long atomic64_dec_if_positive(atomic64_t *v)
{
unsigned long flags;
spinlock_t *lock = lock_addr(v);
long long val;
spin_lock_irqsave(lock, flags);
val = v->counter - 1;
if (val >= 0)
v->counter = val;
spin_unlock_irqrestore(lock, flags);
return val;
}
long long atomic64_cmpxchg(atomic64_t *v, long long o, long long n)
{
unsigned long flags;
spinlock_t *lock = lock_addr(v);
long long val;
spin_lock_irqsave(lock, flags);
val = v->counter;
if (val == o)
v->counter = n;
spin_unlock_irqrestore(lock, flags);
return val;
}
long long atomic64_xchg(atomic64_t *v, long long new)
{
unsigned long flags;
spinlock_t *lock = lock_addr(v);
long long val;
spin_lock_irqsave(lock, flags);
val = v->counter;
v->counter = new;
spin_unlock_irqrestore(lock, flags);
return val;
}
int atomic64_add_unless(atomic64_t *v, long long a, long long u)
{
unsigned long flags;
spinlock_t *lock = lock_addr(v);
int ret = 0;
spin_lock_irqsave(lock, flags);
if (v->counter != u) {
v->counter += a;
ret = 1;
}
spin_unlock_irqrestore(lock, flags);
return ret;
}
static int init_atomic64_lock(void)
{
int i;
for (i = 0; i < NR_LOCKS; ++i)
spin_lock_init(&atomic64_lock[i].lock);
return 0;
}
