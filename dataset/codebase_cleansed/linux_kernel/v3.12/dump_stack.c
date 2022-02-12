static void __dump_stack(void)
{
dump_stack_print_info(KERN_DEFAULT);
show_stack(NULL, NULL);
}
asmlinkage void dump_stack(void)
{
int was_locked;
int old;
int cpu;
preempt_disable();
retry:
cpu = smp_processor_id();
old = atomic_cmpxchg(&dump_lock, -1, cpu);
if (old == -1) {
was_locked = 0;
} else if (old == cpu) {
was_locked = 1;
} else {
cpu_relax();
goto retry;
}
__dump_stack();
if (!was_locked)
atomic_set(&dump_lock, -1);
preempt_enable();
}
asmlinkage void dump_stack(void)
{
__dump_stack();
}
