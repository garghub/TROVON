void synchronise_count_master(int cpu)
{
int i;
unsigned long flags;
printk(KERN_INFO "Synchronize counters for CPU %u: ", cpu);
local_irq_save(flags);
for (i = 0; i < NR_LOOPS; i++) {
while (atomic_read(&count_count_start) != 1)
mb();
atomic_set(&count_count_stop, 0);
smp_wmb();
atomic_inc(&count_count_start);
if (i == 1)
initcount = read_c0_count();
if (i == NR_LOOPS-1)
write_c0_count(initcount);
while (atomic_read(&count_count_stop) != 1)
mb();
atomic_set(&count_count_start, 0);
smp_wmb();
atomic_inc(&count_count_stop);
}
write_c0_compare(read_c0_count() + COUNTON);
local_irq_restore(flags);
printk("done.\n");
}
void synchronise_count_slave(int cpu)
{
int i;
for (i = 0; i < NR_LOOPS; i++) {
atomic_inc(&count_count_start);
while (atomic_read(&count_count_start) != 2)
mb();
if (i == NR_LOOPS-1)
write_c0_count(initcount);
atomic_inc(&count_count_stop);
while (atomic_read(&count_count_stop) != 2)
mb();
}
write_c0_compare(read_c0_count() + COUNTON);
}
