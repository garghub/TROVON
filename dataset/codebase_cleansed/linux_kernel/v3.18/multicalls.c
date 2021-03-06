void xen_mc_flush(void)
{
struct mc_buffer *b = this_cpu_ptr(&mc_buffer);
struct multicall_entry *mc;
int ret = 0;
unsigned long flags;
int i;
BUG_ON(preemptible());
local_irq_save(flags);
trace_xen_mc_flush(b->mcidx, b->argidx, b->cbidx);
switch (b->mcidx) {
case 0:
BUG_ON(b->argidx != 0);
break;
case 1:
mc = &b->entries[0];
mc->result = privcmd_call(mc->op,
mc->args[0], mc->args[1], mc->args[2],
mc->args[3], mc->args[4]);
ret = mc->result < 0;
break;
default:
#if MC_DEBUG
memcpy(b->debug, b->entries,
b->mcidx * sizeof(struct multicall_entry));
#endif
if (HYPERVISOR_multicall(b->entries, b->mcidx) != 0)
BUG();
for (i = 0; i < b->mcidx; i++)
if (b->entries[i].result < 0)
ret++;
#if MC_DEBUG
if (ret) {
printk(KERN_ERR "%d multicall(s) failed: cpu %d\n",
ret, smp_processor_id());
dump_stack();
for (i = 0; i < b->mcidx; i++) {
printk(KERN_DEBUG " call %2d/%d: op=%lu arg=[%lx] result=%ld\t%pF\n",
i+1, b->mcidx,
b->debug[i].op,
b->debug[i].args[0],
b->entries[i].result,
b->caller[i]);
}
}
#endif
}
b->mcidx = 0;
b->argidx = 0;
for (i = 0; i < b->cbidx; i++) {
struct callback *cb = &b->callbacks[i];
(*cb->fn)(cb->data);
}
b->cbidx = 0;
local_irq_restore(flags);
WARN_ON(ret);
}
struct multicall_space __xen_mc_entry(size_t args)
{
struct mc_buffer *b = this_cpu_ptr(&mc_buffer);
struct multicall_space ret;
unsigned argidx = roundup(b->argidx, sizeof(u64));
trace_xen_mc_entry_alloc(args);
BUG_ON(preemptible());
BUG_ON(b->argidx >= MC_ARGS);
if (unlikely(b->mcidx == MC_BATCH ||
(argidx + args) >= MC_ARGS)) {
trace_xen_mc_flush_reason((b->mcidx == MC_BATCH) ?
XEN_MC_FL_BATCH : XEN_MC_FL_ARGS);
xen_mc_flush();
argidx = roundup(b->argidx, sizeof(u64));
}
ret.mc = &b->entries[b->mcidx];
#if MC_DEBUG
b->caller[b->mcidx] = __builtin_return_address(0);
#endif
b->mcidx++;
ret.args = &b->args[argidx];
b->argidx = argidx + args;
BUG_ON(b->argidx >= MC_ARGS);
return ret;
}
struct multicall_space xen_mc_extend_args(unsigned long op, size_t size)
{
struct mc_buffer *b = this_cpu_ptr(&mc_buffer);
struct multicall_space ret = { NULL, NULL };
BUG_ON(preemptible());
BUG_ON(b->argidx >= MC_ARGS);
if (unlikely(b->mcidx == 0 ||
b->entries[b->mcidx - 1].op != op)) {
trace_xen_mc_extend_args(op, size, XEN_MC_XE_BAD_OP);
goto out;
}
if (unlikely((b->argidx + size) >= MC_ARGS)) {
trace_xen_mc_extend_args(op, size, XEN_MC_XE_NO_SPACE);
goto out;
}
ret.mc = &b->entries[b->mcidx - 1];
ret.args = &b->args[b->argidx];
b->argidx += size;
BUG_ON(b->argidx >= MC_ARGS);
trace_xen_mc_extend_args(op, size, XEN_MC_XE_OK);
out:
return ret;
}
void xen_mc_callback(void (*fn)(void *), void *data)
{
struct mc_buffer *b = this_cpu_ptr(&mc_buffer);
struct callback *cb;
if (b->cbidx == MC_BATCH) {
trace_xen_mc_flush_reason(XEN_MC_FL_CALLBACK);
xen_mc_flush();
}
trace_xen_mc_callback(fn, data);
cb = &b->callbacks[b->cbidx++];
cb->fn = fn;
cb->data = data;
}
