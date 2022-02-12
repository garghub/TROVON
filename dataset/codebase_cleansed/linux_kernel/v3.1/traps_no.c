void die_if_kernel(char *str, struct pt_regs *fp, int nr)
{
if (!(fp->sr & PS_S))
return;
console_verbose();
printk(KERN_EMERG "%s: %08x\n",str,nr);
printk(KERN_EMERG "PC: [<%08lx>]\nSR: %04x SP: %p a2: %08lx\n",
fp->pc, fp->sr, fp, fp->a2);
printk(KERN_EMERG "d0: %08lx d1: %08lx d2: %08lx d3: %08lx\n",
fp->d0, fp->d1, fp->d2, fp->d3);
printk(KERN_EMERG "d4: %08lx d5: %08lx a0: %08lx a1: %08lx\n",
fp->d4, fp->d5, fp->a0, fp->a1);
printk(KERN_EMERG "Process %s (pid: %d, stackpage=%08lx)\n",
current->comm, current->pid, PAGE_SIZE+(unsigned long)current);
show_stack(NULL, (unsigned long *)(fp + 1));
add_taint(TAINT_DIE);
do_exit(SIGSEGV);
}
asmlinkage void buserr_c(struct frame *fp)
{
if (user_mode(&fp->ptregs))
current->thread.esp0 = (unsigned long) fp;
#if defined(DEBUG)
printk (KERN_DEBUG "*** Bus Error *** Format is %x\n", fp->ptregs.format);
#endif
die_if_kernel("bad frame format",&fp->ptregs,0);
#if defined(DEBUG)
printk(KERN_DEBUG "Unknown SIGSEGV - 4\n");
#endif
force_sig(SIGSEGV, current);
}
static void print_this_address(unsigned long addr, int i)
{
#ifdef CONFIG_KALLSYMS
printk(KERN_EMERG " [%08lx] ", addr);
print_symbol(KERN_CONT "%s\n", addr);
#else
if (i % 5)
printk(KERN_CONT " [%08lx] ", addr);
else
printk(KERN_EMERG " [%08lx] ", addr);
i++;
#endif
}
static void __show_stack(struct task_struct *task, unsigned long *stack)
{
unsigned long *endstack, addr;
#ifdef CONFIG_FRAME_POINTER
unsigned long *last_stack;
#endif
int i;
if (!stack)
stack = (unsigned long *)task->thread.ksp;
addr = (unsigned long) stack;
endstack = (unsigned long *) PAGE_ALIGN(addr);
printk(KERN_EMERG "Stack from %08lx:", (unsigned long)stack);
for (i = 0; i < kstack_depth_to_print; i++) {
if (stack + 1 + i > endstack)
break;
if (i % 8 == 0)
printk(KERN_EMERG " ");
printk(KERN_CONT " %08lx", *(stack + i));
}
printk("\n");
i = 0;
#ifdef CONFIG_FRAME_POINTER
printk(KERN_EMERG "Call Trace:\n");
last_stack = stack - 1;
while (stack <= endstack && stack > last_stack) {
addr = *(stack + 1);
print_this_address(addr, i);
i++;
last_stack = stack;
stack = (unsigned long *)*stack;
}
printk("\n");
#else
printk(KERN_EMERG "Call Trace with CONFIG_FRAME_POINTER disabled:\n");
while (stack <= endstack) {
addr = *stack++;
if (__kernel_text_address(addr)) {
print_this_address(addr, i);
i++;
}
}
printk(KERN_CONT "\n");
#endif
}
void bad_super_trap(struct frame *fp)
{
int vector = (fp->ptregs.vector >> 2) & 0xff;
console_verbose();
if (vector < ARRAY_SIZE(vec_names))
printk (KERN_WARNING "*** %s *** FORMAT=%X\n",
vec_names[vector],
fp->ptregs.format);
else
printk (KERN_WARNING "*** Exception %d *** FORMAT=%X\n",
vector,
fp->ptregs.format);
printk (KERN_WARNING "Current process id is %d\n", current->pid);
die_if_kernel("BAD KERNEL TRAP", &fp->ptregs, 0);
}
asmlinkage void trap_c(struct frame *fp)
{
int sig;
int vector = (fp->ptregs.vector >> 2) & 0xff;
siginfo_t info;
if (fp->ptregs.sr & PS_S) {
if (vector == VEC_TRACE) {
} else
bad_super_trap(fp);
return;
}
switch (vector) {
case VEC_ADDRERR:
info.si_code = BUS_ADRALN;
sig = SIGBUS;
break;
case VEC_ILLEGAL:
case VEC_LINE10:
case VEC_LINE11:
info.si_code = ILL_ILLOPC;
sig = SIGILL;
break;
case VEC_PRIV:
info.si_code = ILL_PRVOPC;
sig = SIGILL;
break;
case VEC_COPROC:
info.si_code = ILL_COPROC;
sig = SIGILL;
break;
case VEC_TRAP1:
fp->ptregs.pc -= 2;
info.si_code = TRAP_TRACE;
sig = SIGTRAP;
break;
case VEC_TRAP2:
case VEC_TRAP3:
case VEC_TRAP4:
case VEC_TRAP5:
case VEC_TRAP6:
case VEC_TRAP7:
case VEC_TRAP8:
case VEC_TRAP9:
case VEC_TRAP10:
case VEC_TRAP11:
case VEC_TRAP12:
case VEC_TRAP13:
case VEC_TRAP14:
info.si_code = ILL_ILLTRP;
sig = SIGILL;
break;
case VEC_FPBRUC:
case VEC_FPOE:
case VEC_FPNAN:
info.si_code = FPE_FLTINV;
sig = SIGFPE;
break;
case VEC_FPIR:
info.si_code = FPE_FLTRES;
sig = SIGFPE;
break;
case VEC_FPDIVZ:
info.si_code = FPE_FLTDIV;
sig = SIGFPE;
break;
case VEC_FPUNDER:
info.si_code = FPE_FLTUND;
sig = SIGFPE;
break;
case VEC_FPOVER:
info.si_code = FPE_FLTOVF;
sig = SIGFPE;
break;
case VEC_ZERODIV:
info.si_code = FPE_INTDIV;
sig = SIGFPE;
break;
case VEC_CHK:
case VEC_TRAP:
info.si_code = FPE_INTOVF;
sig = SIGFPE;
break;
case VEC_TRACE:
info.si_code = TRAP_TRACE;
sig = SIGTRAP;
break;
case VEC_TRAP15:
info.si_code = TRAP_BRKPT;
sig = SIGTRAP;
break;
default:
info.si_code = ILL_ILLOPC;
sig = SIGILL;
break;
}
info.si_signo = sig;
info.si_errno = 0;
switch (fp->ptregs.format) {
default:
info.si_addr = (void *) fp->ptregs.pc;
break;
case 2:
info.si_addr = (void *) fp->un.fmt2.iaddr;
break;
case 7:
info.si_addr = (void *) fp->un.fmt7.effaddr;
break;
case 9:
info.si_addr = (void *) fp->un.fmt9.iaddr;
break;
case 10:
info.si_addr = (void *) fp->un.fmta.daddr;
break;
case 11:
info.si_addr = (void *) fp->un.fmtb.daddr;
break;
}
force_sig_info (sig, &info, current);
}
asmlinkage void set_esp0(unsigned long ssp)
{
current->thread.esp0 = ssp;
}
void dump_stack(void)
{
unsigned long *stack;
stack = (unsigned long *)&stack;
stack++;
__show_stack(current, stack);
}
void show_stack(struct task_struct *task, unsigned long *stack)
{
if (!stack && !task)
dump_stack();
else
__show_stack(task, stack);
}
