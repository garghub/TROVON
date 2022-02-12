unsigned long cmpxchg_386_u8(volatile void *ptr, u8 old, u8 new)
{
u8 prev;
unsigned long flags;
local_irq_save(flags);
prev = *(u8 *)ptr;
if (prev == old)
*(u8 *)ptr = new;
local_irq_restore(flags);
return prev;
}
unsigned long cmpxchg_386_u16(volatile void *ptr, u16 old, u16 new)
{
u16 prev;
unsigned long flags;
local_irq_save(flags);
prev = *(u16 *)ptr;
if (prev == old)
*(u16 *)ptr = new;
local_irq_restore(flags);
return prev;
}
unsigned long cmpxchg_386_u32(volatile void *ptr, u32 old, u32 new)
{
u32 prev;
unsigned long flags;
local_irq_save(flags);
prev = *(u32 *)ptr;
if (prev == old)
*(u32 *)ptr = new;
local_irq_restore(flags);
return prev;
}
