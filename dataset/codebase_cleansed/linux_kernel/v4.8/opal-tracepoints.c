void opal_tracepoint_regfunc(void)
{
static_key_slow_inc(&opal_tracepoint_key);
}
void opal_tracepoint_unregfunc(void)
{
static_key_slow_dec(&opal_tracepoint_key);
}
void opal_tracepoint_regfunc(void)
{
opal_tracepoint_refcount++;
}
void opal_tracepoint_unregfunc(void)
{
opal_tracepoint_refcount--;
}
void __trace_opal_entry(unsigned long opcode, unsigned long *args)
{
unsigned long flags;
unsigned int *depth;
local_irq_save(flags);
depth = this_cpu_ptr(&opal_trace_depth);
if (*depth)
goto out;
(*depth)++;
preempt_disable();
trace_opal_entry(opcode, args);
(*depth)--;
out:
local_irq_restore(flags);
}
void __trace_opal_exit(long opcode, unsigned long retval)
{
unsigned long flags;
unsigned int *depth;
local_irq_save(flags);
depth = this_cpu_ptr(&opal_trace_depth);
if (*depth)
goto out;
(*depth)++;
trace_opal_exit(opcode, retval);
preempt_enable();
(*depth)--;
out:
local_irq_restore(flags);
}
