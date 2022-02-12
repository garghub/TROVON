void leave_mm(int cpu)
{
struct mm_struct *loaded_mm = this_cpu_read(cpu_tlbstate.loaded_mm);
if (loaded_mm == &init_mm)
return;
if (this_cpu_read(cpu_tlbstate.state) == TLBSTATE_OK)
BUG();
switch_mm(NULL, &init_mm, NULL);
}
void switch_mm(struct mm_struct *prev, struct mm_struct *next,
struct task_struct *tsk)
{
unsigned long flags;
local_irq_save(flags);
switch_mm_irqs_off(prev, next, tsk);
local_irq_restore(flags);
}
void switch_mm_irqs_off(struct mm_struct *prev, struct mm_struct *next,
struct task_struct *tsk)
{
unsigned cpu = smp_processor_id();
struct mm_struct *real_prev = this_cpu_read(cpu_tlbstate.loaded_mm);
this_cpu_write(cpu_tlbstate.state, TLBSTATE_OK);
if (real_prev == next) {
if (WARN_ON_ONCE(!cpumask_test_cpu(cpu, mm_cpumask(next))))
cpumask_set_cpu(cpu, mm_cpumask(next));
return;
}
if (IS_ENABLED(CONFIG_VMAP_STACK)) {
unsigned int stack_pgd_index = pgd_index(current_stack_pointer());
pgd_t *pgd = next->pgd + stack_pgd_index;
if (unlikely(pgd_none(*pgd)))
set_pgd(pgd, init_mm.pgd[stack_pgd_index]);
}
this_cpu_write(cpu_tlbstate.loaded_mm, next);
WARN_ON_ONCE(cpumask_test_cpu(cpu, mm_cpumask(next)));
cpumask_set_cpu(cpu, mm_cpumask(next));
load_cr3(next->pgd);
trace_tlb_flush_rcuidle(TLB_FLUSH_ON_TASK_SWITCH, TLB_FLUSH_ALL);
WARN_ON_ONCE(!cpumask_test_cpu(cpu, mm_cpumask(real_prev)) &&
real_prev != &init_mm);
cpumask_clear_cpu(cpu, mm_cpumask(real_prev));
load_mm_cr4(next);
switch_ldt(real_prev, next);
}
static void flush_tlb_func_common(const struct flush_tlb_info *f,
bool local, enum tlb_flush_reason reason)
{
VM_WARN_ON(!irqs_disabled());
if (this_cpu_read(cpu_tlbstate.state) != TLBSTATE_OK) {
leave_mm(smp_processor_id());
return;
}
if (f->end == TLB_FLUSH_ALL) {
local_flush_tlb();
if (local)
count_vm_tlb_event(NR_TLB_LOCAL_FLUSH_ALL);
trace_tlb_flush(reason, TLB_FLUSH_ALL);
} else {
unsigned long addr;
unsigned long nr_pages = (f->end - f->start) >> PAGE_SHIFT;
addr = f->start;
while (addr < f->end) {
__flush_tlb_single(addr);
addr += PAGE_SIZE;
}
if (local)
count_vm_tlb_events(NR_TLB_LOCAL_FLUSH_ONE, nr_pages);
trace_tlb_flush(reason, nr_pages);
}
}
static void flush_tlb_func_local(void *info, enum tlb_flush_reason reason)
{
const struct flush_tlb_info *f = info;
flush_tlb_func_common(f, true, reason);
}
static void flush_tlb_func_remote(void *info)
{
const struct flush_tlb_info *f = info;
inc_irq_stat(irq_tlb_count);
if (f->mm && f->mm != this_cpu_read(cpu_tlbstate.loaded_mm))
return;
count_vm_tlb_event(NR_TLB_REMOTE_FLUSH_RECEIVED);
flush_tlb_func_common(f, false, TLB_REMOTE_SHOOTDOWN);
}
void native_flush_tlb_others(const struct cpumask *cpumask,
const struct flush_tlb_info *info)
{
count_vm_tlb_event(NR_TLB_REMOTE_FLUSH);
if (info->end == TLB_FLUSH_ALL)
trace_tlb_flush(TLB_REMOTE_SEND_IPI, TLB_FLUSH_ALL);
else
trace_tlb_flush(TLB_REMOTE_SEND_IPI,
(info->end - info->start) >> PAGE_SHIFT);
if (is_uv_system()) {
unsigned int cpu;
cpu = smp_processor_id();
cpumask = uv_flush_tlb_others(cpumask, info);
if (cpumask)
smp_call_function_many(cpumask, flush_tlb_func_remote,
(void *)info, 1);
return;
}
smp_call_function_many(cpumask, flush_tlb_func_remote,
(void *)info, 1);
}
void flush_tlb_mm_range(struct mm_struct *mm, unsigned long start,
unsigned long end, unsigned long vmflag)
{
int cpu;
struct flush_tlb_info info = {
.mm = mm,
};
cpu = get_cpu();
smp_mb();
if ((end != TLB_FLUSH_ALL) &&
!(vmflag & VM_HUGETLB) &&
((end - start) >> PAGE_SHIFT) <= tlb_single_page_flush_ceiling) {
info.start = start;
info.end = end;
} else {
info.start = 0UL;
info.end = TLB_FLUSH_ALL;
}
if (mm == this_cpu_read(cpu_tlbstate.loaded_mm)) {
VM_WARN_ON(irqs_disabled());
local_irq_disable();
flush_tlb_func_local(&info, TLB_LOCAL_MM_SHOOTDOWN);
local_irq_enable();
}
if (cpumask_any_but(mm_cpumask(mm), cpu) < nr_cpu_ids)
flush_tlb_others(mm_cpumask(mm), &info);
put_cpu();
}
static void do_flush_tlb_all(void *info)
{
count_vm_tlb_event(NR_TLB_REMOTE_FLUSH_RECEIVED);
__flush_tlb_all();
if (this_cpu_read(cpu_tlbstate.state) == TLBSTATE_LAZY)
leave_mm(smp_processor_id());
}
void flush_tlb_all(void)
{
count_vm_tlb_event(NR_TLB_REMOTE_FLUSH);
on_each_cpu(do_flush_tlb_all, NULL, 1);
}
static void do_kernel_range_flush(void *info)
{
struct flush_tlb_info *f = info;
unsigned long addr;
for (addr = f->start; addr < f->end; addr += PAGE_SIZE)
__flush_tlb_single(addr);
}
void flush_tlb_kernel_range(unsigned long start, unsigned long end)
{
if (end == TLB_FLUSH_ALL ||
(end - start) > tlb_single_page_flush_ceiling << PAGE_SHIFT) {
on_each_cpu(do_flush_tlb_all, NULL, 1);
} else {
struct flush_tlb_info info;
info.start = start;
info.end = end;
on_each_cpu(do_kernel_range_flush, &info, 1);
}
}
void arch_tlbbatch_flush(struct arch_tlbflush_unmap_batch *batch)
{
struct flush_tlb_info info = {
.mm = NULL,
.start = 0UL,
.end = TLB_FLUSH_ALL,
};
int cpu = get_cpu();
if (cpumask_test_cpu(cpu, &batch->cpumask)) {
VM_WARN_ON(irqs_disabled());
local_irq_disable();
flush_tlb_func_local(&info, TLB_LOCAL_SHOOTDOWN);
local_irq_enable();
}
if (cpumask_any_but(&batch->cpumask, cpu) < nr_cpu_ids)
flush_tlb_others(&batch->cpumask, &info);
cpumask_clear(&batch->cpumask);
put_cpu();
}
static ssize_t tlbflush_read_file(struct file *file, char __user *user_buf,
size_t count, loff_t *ppos)
{
char buf[32];
unsigned int len;
len = sprintf(buf, "%ld\n", tlb_single_page_flush_ceiling);
return simple_read_from_buffer(user_buf, count, ppos, buf, len);
}
static ssize_t tlbflush_write_file(struct file *file,
const char __user *user_buf, size_t count, loff_t *ppos)
{
char buf[32];
ssize_t len;
int ceiling;
len = min(count, sizeof(buf) - 1);
if (copy_from_user(buf, user_buf, len))
return -EFAULT;
buf[len] = '\0';
if (kstrtoint(buf, 0, &ceiling))
return -EINVAL;
if (ceiling < 0)
return -EINVAL;
tlb_single_page_flush_ceiling = ceiling;
return count;
}
static int __init create_tlb_single_page_flush_ceiling(void)
{
debugfs_create_file("tlb_single_page_flush_ceiling", S_IRUSR | S_IWUSR,
arch_debugfs_dir, NULL, &fops_tlbflush);
return 0;
}
