const char *stack_type_name(enum stack_type type)
{
BUILD_BUG_ON(N_EXCEPTION_STACKS != 4);
if (type == STACK_TYPE_IRQ)
return "IRQ";
if (type >= STACK_TYPE_EXCEPTION && type <= STACK_TYPE_EXCEPTION_LAST)
return exception_stack_names[type - STACK_TYPE_EXCEPTION];
return NULL;
}
static bool in_exception_stack(unsigned long *stack, struct stack_info *info)
{
unsigned long *begin, *end;
struct pt_regs *regs;
unsigned k;
BUILD_BUG_ON(N_EXCEPTION_STACKS != 4);
for (k = 0; k < N_EXCEPTION_STACKS; k++) {
end = (unsigned long *)raw_cpu_ptr(&orig_ist)->ist[k];
begin = end - (exception_stack_sizes[k] / sizeof(long));
regs = (struct pt_regs *)end - 1;
if (stack < begin || stack >= end)
continue;
info->type = STACK_TYPE_EXCEPTION + k;
info->begin = begin;
info->end = end;
info->next_sp = (unsigned long *)regs->sp;
return true;
}
return false;
}
static bool in_irq_stack(unsigned long *stack, struct stack_info *info)
{
unsigned long *end = (unsigned long *)this_cpu_read(irq_stack_ptr);
unsigned long *begin = end - (IRQ_STACK_SIZE / sizeof(long));
if (stack < begin || stack > end)
return false;
info->type = STACK_TYPE_IRQ;
info->begin = begin;
info->end = end;
info->next_sp = (unsigned long *)*(end - 1);
return true;
}
int get_stack_info(unsigned long *stack, struct task_struct *task,
struct stack_info *info, unsigned long *visit_mask)
{
if (!stack)
goto unknown;
task = task ? : current;
if (in_task_stack(stack, task, info))
goto recursion_check;
if (task != current)
goto unknown;
if (in_exception_stack(stack, info))
goto recursion_check;
if (in_irq_stack(stack, info))
goto recursion_check;
goto unknown;
recursion_check:
if (visit_mask) {
if (*visit_mask & (1UL << info->type)) {
printk_deferred_once(KERN_WARNING "WARNING: stack recursion on stack type %d\n", info->type);
goto unknown;
}
*visit_mask |= 1UL << info->type;
}
return 0;
unknown:
info->type = STACK_TYPE_UNKNOWN;
return -EINVAL;
}
void show_regs(struct pt_regs *regs)
{
int i;
show_regs_print_info(KERN_DEFAULT);
__show_regs(regs, 1);
if (!user_mode(regs)) {
unsigned int code_prologue = code_bytes * 43 / 64;
unsigned int code_len = code_bytes;
unsigned char c;
u8 *ip;
show_trace_log_lvl(current, regs, NULL, KERN_DEFAULT);
printk(KERN_DEFAULT "Code: ");
ip = (u8 *)regs->ip - code_prologue;
if (ip < (u8 *)PAGE_OFFSET || probe_kernel_address(ip, c)) {
ip = (u8 *)regs->ip;
code_len = code_len - code_prologue + 1;
}
for (i = 0; i < code_len; i++, ip++) {
if (ip < (u8 *)PAGE_OFFSET ||
probe_kernel_address(ip, c)) {
pr_cont(" Bad RIP value.");
break;
}
if (ip == (u8 *)regs->ip)
pr_cont("<%02x> ", c);
else
pr_cont("%02x ", c);
}
}
pr_cont("\n");
}
int is_valid_bugaddr(unsigned long ip)
{
unsigned short ud2;
if (__copy_from_user(&ud2, (const void __user *) ip, sizeof(ud2)))
return 0;
return ud2 == 0x0b0f;
}
