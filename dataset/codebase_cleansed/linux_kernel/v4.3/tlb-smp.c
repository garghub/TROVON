void smp_flush_tlb(void *unused)
{
unsigned long cpu_id;
cpu_id = get_cpu();
if (!cpumask_test_cpu(cpu_id, &flush_cpumask))
goto out;
if (flush_va == FLUSH_ALL)
local_flush_tlb();
else
local_flush_tlb_page(flush_mm, flush_va);
smp_mb__before_atomic();
cpumask_clear_cpu(cpu_id, &flush_cpumask);
smp_mb__after_atomic();
out:
put_cpu();
}
static void flush_tlb_others(cpumask_t cpumask, struct mm_struct *mm,
unsigned long va)
{
cpumask_t tmp;
BUG_ON(!mm);
BUG_ON(cpumask_empty(&cpumask));
BUG_ON(cpumask_test_cpu(smp_processor_id(), &cpumask));
cpumask_and(&tmp, &cpumask, cpu_online_mask);
BUG_ON(!cpumask_equal(&cpumask, &tmp));
spin_lock(&tlbstate_lock);
flush_mm = mm;
flush_va = va;
#if NR_CPUS <= BITS_PER_LONG
atomic_or(cpumask.bits[0], (atomic_t *)&flush_cpumask.bits[0]);
#else
#error Not supported.
#endif
smp_call_function(smp_flush_tlb, NULL, 1);
while (!cpumask_empty(&flush_cpumask))
smp_mb();
flush_mm = NULL;
flush_va = 0;
spin_unlock(&tlbstate_lock);
}
void flush_tlb_mm(struct mm_struct *mm)
{
cpumask_t cpu_mask;
preempt_disable();
cpumask_copy(&cpu_mask, mm_cpumask(mm));
cpumask_clear_cpu(smp_processor_id(), &cpu_mask);
local_flush_tlb();
if (!cpumask_empty(&cpu_mask))
flush_tlb_others(cpu_mask, mm, FLUSH_ALL);
preempt_enable();
}
void flush_tlb_current_task(void)
{
struct mm_struct *mm = current->mm;
cpumask_t cpu_mask;
preempt_disable();
cpumask_copy(&cpu_mask, mm_cpumask(mm));
cpumask_clear_cpu(smp_processor_id(), &cpu_mask);
local_flush_tlb();
if (!cpumask_empty(&cpu_mask))
flush_tlb_others(cpu_mask, mm, FLUSH_ALL);
preempt_enable();
}
void flush_tlb_page(struct vm_area_struct *vma, unsigned long va)
{
struct mm_struct *mm = vma->vm_mm;
cpumask_t cpu_mask;
preempt_disable();
cpumask_copy(&cpu_mask, mm_cpumask(mm));
cpumask_clear_cpu(smp_processor_id(), &cpu_mask);
local_flush_tlb_page(mm, va);
if (!cpumask_empty(&cpu_mask))
flush_tlb_others(cpu_mask, mm, va);
preempt_enable();
}
static void do_flush_tlb_all(void *unused)
{
local_flush_tlb_all();
}
void flush_tlb_all(void)
{
on_each_cpu(do_flush_tlb_all, 0, 1);
}
