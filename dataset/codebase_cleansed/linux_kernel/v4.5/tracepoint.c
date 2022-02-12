static void set_trace_idt_ctr(int val)
{
atomic_set(&trace_idt_ctr, val);
wmb();
}
static void switch_idt(void *arg)
{
unsigned long flags;
local_irq_save(flags);
load_current_idt();
local_irq_restore(flags);
}
void trace_irq_vector_regfunc(void)
{
mutex_lock(&irq_vector_mutex);
if (!trace_irq_vector_refcount) {
set_trace_idt_ctr(1);
smp_call_function(switch_idt, NULL, 0);
switch_idt(NULL);
}
trace_irq_vector_refcount++;
mutex_unlock(&irq_vector_mutex);
}
void trace_irq_vector_unregfunc(void)
{
mutex_lock(&irq_vector_mutex);
trace_irq_vector_refcount--;
if (!trace_irq_vector_refcount) {
set_trace_idt_ctr(0);
smp_call_function(switch_idt, NULL, 0);
switch_idt(NULL);
}
mutex_unlock(&irq_vector_mutex);
}
