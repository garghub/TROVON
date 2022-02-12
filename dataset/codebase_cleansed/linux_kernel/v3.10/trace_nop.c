static void start_nop_trace(struct trace_array *tr)
{
}
static void stop_nop_trace(struct trace_array *tr)
{
}
static int nop_trace_init(struct trace_array *tr)
{
ctx_trace = tr;
start_nop_trace(tr);
return 0;
}
static void nop_trace_reset(struct trace_array *tr)
{
stop_nop_trace(tr);
}
static int nop_set_flag(u32 old_flags, u32 bit, int set)
{
if (bit == TRACE_NOP_OPT_ACCEPT) {
printk(KERN_DEBUG "nop_test_accept flag set to %d: we accept."
" Now cat trace_options to see the result\n",
set);
return 0;
}
if (bit == TRACE_NOP_OPT_REFUSE) {
printk(KERN_DEBUG "nop_test_refuse flag set to %d: we refuse."
"Now cat trace_options to see the result\n",
set);
return -EINVAL;
}
return 0;
}
