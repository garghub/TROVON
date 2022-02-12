u64 notrace trace_clock_local(void)
{
u64 clock;
preempt_disable_notrace();
clock = sched_clock();
preempt_enable_notrace();
return clock;
}
u64 notrace trace_clock(void)
{
return local_clock();
}
u64 notrace trace_clock_jiffies(void)
{
u64 jiffy = jiffies - INITIAL_JIFFIES;
return (u64)jiffies_to_usecs(jiffy) * 1000ULL;
}
u64 notrace trace_clock_global(void)
{
unsigned long flags;
int this_cpu;
u64 now;
local_irq_save(flags);
this_cpu = raw_smp_processor_id();
now = sched_clock_cpu(this_cpu);
if (unlikely(in_nmi()))
goto out;
arch_spin_lock(&trace_clock_struct.lock);
if ((s64)(now - trace_clock_struct.prev_time) < 0)
now = trace_clock_struct.prev_time + 1;
trace_clock_struct.prev_time = now;
arch_spin_unlock(&trace_clock_struct.lock);
out:
local_irq_restore(flags);
return now;
}
u64 notrace trace_clock_counter(void)
{
return atomic64_add_return(1, &trace_counter);
}
