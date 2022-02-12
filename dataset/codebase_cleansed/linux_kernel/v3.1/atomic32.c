int __atomic_add_return(int i, atomic_t *v)
{
int ret;
unsigned long flags;
spin_lock_irqsave(ATOMIC_HASH(v), flags);
ret = (v->counter += i);
spin_unlock_irqrestore(ATOMIC_HASH(v), flags);
return ret;
}
int atomic_cmpxchg(atomic_t *v, int old, int new)
{
int ret;
unsigned long flags;
spin_lock_irqsave(ATOMIC_HASH(v), flags);
ret = v->counter;
if (likely(ret == old))
v->counter = new;
spin_unlock_irqrestore(ATOMIC_HASH(v), flags);
return ret;
}
int __atomic_add_unless(atomic_t *v, int a, int u)
{
int ret;
unsigned long flags;
spin_lock_irqsave(ATOMIC_HASH(v), flags);
ret = v->counter;
if (ret != u)
v->counter += a;
spin_unlock_irqrestore(ATOMIC_HASH(v), flags);
return ret;
}
void atomic_set(atomic_t *v, int i)
{
unsigned long flags;
spin_lock_irqsave(ATOMIC_HASH(v), flags);
v->counter = i;
spin_unlock_irqrestore(ATOMIC_HASH(v), flags);
}
unsigned long ___set_bit(unsigned long *addr, unsigned long mask)
{
unsigned long old, flags;
spin_lock_irqsave(ATOMIC_HASH(addr), flags);
old = *addr;
*addr = old | mask;
spin_unlock_irqrestore(ATOMIC_HASH(addr), flags);
return old & mask;
}
unsigned long ___clear_bit(unsigned long *addr, unsigned long mask)
{
unsigned long old, flags;
spin_lock_irqsave(ATOMIC_HASH(addr), flags);
old = *addr;
*addr = old & ~mask;
spin_unlock_irqrestore(ATOMIC_HASH(addr), flags);
return old & mask;
}
unsigned long ___change_bit(unsigned long *addr, unsigned long mask)
{
unsigned long old, flags;
spin_lock_irqsave(ATOMIC_HASH(addr), flags);
old = *addr;
*addr = old ^ mask;
spin_unlock_irqrestore(ATOMIC_HASH(addr), flags);
return old & mask;
}
unsigned long __cmpxchg_u32(volatile u32 *ptr, u32 old, u32 new)
{
unsigned long flags;
u32 prev;
spin_lock_irqsave(ATOMIC_HASH(ptr), flags);
if ((prev = *ptr) == old)
*ptr = new;
spin_unlock_irqrestore(ATOMIC_HASH(ptr), flags);
return (unsigned long)prev;
}
