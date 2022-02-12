static int callchain_stack(void *data, char *name)
{
return 0;
}
static void callchain_address(void *data, unsigned long addr, int reliable)
{
struct perf_callchain_entry *entry = data;
if (reliable)
perf_callchain_store(entry, addr);
}
void
perf_callchain_kernel(struct perf_callchain_entry *entry, struct pt_regs *regs)
{
perf_callchain_store(entry, regs->pc);
unwind_stack(NULL, regs, NULL, &callchain_ops, entry);
}
