static void _print_addr(void *data, unsigned long address, int reliable)
{
pr_info(" [<%08lx>] %s%pF\n", address, reliable ? "" : "? ",
(void *)address);
}
void show_stack(struct task_struct *task, unsigned long *stack)
{
unsigned long *sp = stack;
struct pt_regs *segv_regs = current->thread.segv_regs;
int i;
if (!segv_regs && os_is_signal_stack()) {
pr_err("Received SIGSEGV in SIGSEGV handler,"
" aborting stack trace!\n");
return;
}
if (!stack)
sp = get_stack_pointer(task, segv_regs);
pr_info("Stack:\n");
stack = sp;
for (i = 0; i < 3 * STACKSLOTS_PER_LINE; i++) {
if (kstack_end(stack))
break;
if (i && ((i % STACKSLOTS_PER_LINE) == 0))
pr_cont("\n");
pr_cont(" %08lx", *stack++);
}
pr_cont("\n");
pr_info("Call Trace:\n");
dump_trace(current, &stackops, NULL);
pr_info("\n");
}
