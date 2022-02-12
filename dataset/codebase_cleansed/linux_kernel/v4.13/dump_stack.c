static void __dump_stack(void)
{
dump_stack_print_info(KERN_DEFAULT);
show_stack(NULL, NULL);
}
asmlinkage __visible void dump_stack(void)
{
unsigned long flags;
int was_locked;
int old;
int cpu;
retry:
local_irq_save(flags);
cpu = smp_processor_id();
old = atomic_cmpxchg(&dump_lock, -1, cpu);
if (old == -1) {
was_locked = 0;
} else if (old == cpu) {
was_locked = 1;
} else {
local_irq_restore(flags);
cpu_relax();
goto retry;
}
__dump_stack();
if (!was_locked)
atomic_set(&dump_lock, -1);
local_irq_restore(flags);
}
asmlinkage __visible void dump_stack(void)
{
__dump_stack();
}
