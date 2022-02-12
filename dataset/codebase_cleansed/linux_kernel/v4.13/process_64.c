void show_regs(struct pt_regs *regs)
{
unsigned long long ah, al, bh, bl, ch, cl;
printk("\n");
show_regs_print_info(KERN_DEFAULT);
ah = (regs->pc) >> 32;
al = (regs->pc) & 0xffffffff;
bh = (regs->regs[18]) >> 32;
bl = (regs->regs[18]) & 0xffffffff;
ch = (regs->regs[15]) >> 32;
cl = (regs->regs[15]) & 0xffffffff;
printk("PC : %08Lx%08Lx LINK: %08Lx%08Lx SP : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->sr) >> 32;
al = (regs->sr) & 0xffffffff;
asm volatile ("getcon " __TEA ", %0" : "=r" (bh));
asm volatile ("getcon " __TEA ", %0" : "=r" (bl));
bh = (bh) >> 32;
bl = (bl) & 0xffffffff;
asm volatile ("getcon " __KCR0 ", %0" : "=r" (ch));
asm volatile ("getcon " __KCR0 ", %0" : "=r" (cl));
ch = (ch) >> 32;
cl = (cl) & 0xffffffff;
printk("SR : %08Lx%08Lx TEA : %08Lx%08Lx KCR0: %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[0]) >> 32;
al = (regs->regs[0]) & 0xffffffff;
bh = (regs->regs[1]) >> 32;
bl = (regs->regs[1]) & 0xffffffff;
ch = (regs->regs[2]) >> 32;
cl = (regs->regs[2]) & 0xffffffff;
printk("R0 : %08Lx%08Lx R1 : %08Lx%08Lx R2 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[3]) >> 32;
al = (regs->regs[3]) & 0xffffffff;
bh = (regs->regs[4]) >> 32;
bl = (regs->regs[4]) & 0xffffffff;
ch = (regs->regs[5]) >> 32;
cl = (regs->regs[5]) & 0xffffffff;
printk("R3 : %08Lx%08Lx R4 : %08Lx%08Lx R5 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[6]) >> 32;
al = (regs->regs[6]) & 0xffffffff;
bh = (regs->regs[7]) >> 32;
bl = (regs->regs[7]) & 0xffffffff;
ch = (regs->regs[8]) >> 32;
cl = (regs->regs[8]) & 0xffffffff;
printk("R6 : %08Lx%08Lx R7 : %08Lx%08Lx R8 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[9]) >> 32;
al = (regs->regs[9]) & 0xffffffff;
bh = (regs->regs[10]) >> 32;
bl = (regs->regs[10]) & 0xffffffff;
ch = (regs->regs[11]) >> 32;
cl = (regs->regs[11]) & 0xffffffff;
printk("R9 : %08Lx%08Lx R10 : %08Lx%08Lx R11 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[12]) >> 32;
al = (regs->regs[12]) & 0xffffffff;
bh = (regs->regs[13]) >> 32;
bl = (regs->regs[13]) & 0xffffffff;
ch = (regs->regs[14]) >> 32;
cl = (regs->regs[14]) & 0xffffffff;
printk("R12 : %08Lx%08Lx R13 : %08Lx%08Lx R14 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[16]) >> 32;
al = (regs->regs[16]) & 0xffffffff;
bh = (regs->regs[17]) >> 32;
bl = (regs->regs[17]) & 0xffffffff;
ch = (regs->regs[19]) >> 32;
cl = (regs->regs[19]) & 0xffffffff;
printk("R16 : %08Lx%08Lx R17 : %08Lx%08Lx R19 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[20]) >> 32;
al = (regs->regs[20]) & 0xffffffff;
bh = (regs->regs[21]) >> 32;
bl = (regs->regs[21]) & 0xffffffff;
ch = (regs->regs[22]) >> 32;
cl = (regs->regs[22]) & 0xffffffff;
printk("R20 : %08Lx%08Lx R21 : %08Lx%08Lx R22 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[23]) >> 32;
al = (regs->regs[23]) & 0xffffffff;
bh = (regs->regs[24]) >> 32;
bl = (regs->regs[24]) & 0xffffffff;
ch = (regs->regs[25]) >> 32;
cl = (regs->regs[25]) & 0xffffffff;
printk("R23 : %08Lx%08Lx R24 : %08Lx%08Lx R25 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[26]) >> 32;
al = (regs->regs[26]) & 0xffffffff;
bh = (regs->regs[27]) >> 32;
bl = (regs->regs[27]) & 0xffffffff;
ch = (regs->regs[28]) >> 32;
cl = (regs->regs[28]) & 0xffffffff;
printk("R26 : %08Lx%08Lx R27 : %08Lx%08Lx R28 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[29]) >> 32;
al = (regs->regs[29]) & 0xffffffff;
bh = (regs->regs[30]) >> 32;
bl = (regs->regs[30]) & 0xffffffff;
ch = (regs->regs[31]) >> 32;
cl = (regs->regs[31]) & 0xffffffff;
printk("R29 : %08Lx%08Lx R30 : %08Lx%08Lx R31 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[32]) >> 32;
al = (regs->regs[32]) & 0xffffffff;
bh = (regs->regs[33]) >> 32;
bl = (regs->regs[33]) & 0xffffffff;
ch = (regs->regs[34]) >> 32;
cl = (regs->regs[34]) & 0xffffffff;
printk("R32 : %08Lx%08Lx R33 : %08Lx%08Lx R34 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[35]) >> 32;
al = (regs->regs[35]) & 0xffffffff;
bh = (regs->regs[36]) >> 32;
bl = (regs->regs[36]) & 0xffffffff;
ch = (regs->regs[37]) >> 32;
cl = (regs->regs[37]) & 0xffffffff;
printk("R35 : %08Lx%08Lx R36 : %08Lx%08Lx R37 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[38]) >> 32;
al = (regs->regs[38]) & 0xffffffff;
bh = (regs->regs[39]) >> 32;
bl = (regs->regs[39]) & 0xffffffff;
ch = (regs->regs[40]) >> 32;
cl = (regs->regs[40]) & 0xffffffff;
printk("R38 : %08Lx%08Lx R39 : %08Lx%08Lx R40 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[41]) >> 32;
al = (regs->regs[41]) & 0xffffffff;
bh = (regs->regs[42]) >> 32;
bl = (regs->regs[42]) & 0xffffffff;
ch = (regs->regs[43]) >> 32;
cl = (regs->regs[43]) & 0xffffffff;
printk("R41 : %08Lx%08Lx R42 : %08Lx%08Lx R43 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[44]) >> 32;
al = (regs->regs[44]) & 0xffffffff;
bh = (regs->regs[45]) >> 32;
bl = (regs->regs[45]) & 0xffffffff;
ch = (regs->regs[46]) >> 32;
cl = (regs->regs[46]) & 0xffffffff;
printk("R44 : %08Lx%08Lx R45 : %08Lx%08Lx R46 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[47]) >> 32;
al = (regs->regs[47]) & 0xffffffff;
bh = (regs->regs[48]) >> 32;
bl = (regs->regs[48]) & 0xffffffff;
ch = (regs->regs[49]) >> 32;
cl = (regs->regs[49]) & 0xffffffff;
printk("R47 : %08Lx%08Lx R48 : %08Lx%08Lx R49 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[50]) >> 32;
al = (regs->regs[50]) & 0xffffffff;
bh = (regs->regs[51]) >> 32;
bl = (regs->regs[51]) & 0xffffffff;
ch = (regs->regs[52]) >> 32;
cl = (regs->regs[52]) & 0xffffffff;
printk("R50 : %08Lx%08Lx R51 : %08Lx%08Lx R52 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[53]) >> 32;
al = (regs->regs[53]) & 0xffffffff;
bh = (regs->regs[54]) >> 32;
bl = (regs->regs[54]) & 0xffffffff;
ch = (regs->regs[55]) >> 32;
cl = (regs->regs[55]) & 0xffffffff;
printk("R53 : %08Lx%08Lx R54 : %08Lx%08Lx R55 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[56]) >> 32;
al = (regs->regs[56]) & 0xffffffff;
bh = (regs->regs[57]) >> 32;
bl = (regs->regs[57]) & 0xffffffff;
ch = (regs->regs[58]) >> 32;
cl = (regs->regs[58]) & 0xffffffff;
printk("R56 : %08Lx%08Lx R57 : %08Lx%08Lx R58 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[59]) >> 32;
al = (regs->regs[59]) & 0xffffffff;
bh = (regs->regs[60]) >> 32;
bl = (regs->regs[60]) & 0xffffffff;
ch = (regs->regs[61]) >> 32;
cl = (regs->regs[61]) & 0xffffffff;
printk("R59 : %08Lx%08Lx R60 : %08Lx%08Lx R61 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->regs[62]) >> 32;
al = (regs->regs[62]) & 0xffffffff;
bh = (regs->tregs[0]) >> 32;
bl = (regs->tregs[0]) & 0xffffffff;
ch = (regs->tregs[1]) >> 32;
cl = (regs->tregs[1]) & 0xffffffff;
printk("R62 : %08Lx%08Lx T0 : %08Lx%08Lx T1 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->tregs[2]) >> 32;
al = (regs->tregs[2]) & 0xffffffff;
bh = (regs->tregs[3]) >> 32;
bl = (regs->tregs[3]) & 0xffffffff;
ch = (regs->tregs[4]) >> 32;
cl = (regs->tregs[4]) & 0xffffffff;
printk("T2 : %08Lx%08Lx T3 : %08Lx%08Lx T4 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
ah = (regs->tregs[5]) >> 32;
al = (regs->tregs[5]) & 0xffffffff;
bh = (regs->tregs[6]) >> 32;
bl = (regs->tregs[6]) & 0xffffffff;
ch = (regs->tregs[7]) >> 32;
cl = (regs->tregs[7]) & 0xffffffff;
printk("T5 : %08Lx%08Lx T6 : %08Lx%08Lx T7 : %08Lx%08Lx\n",
ah, al, bh, bl, ch, cl);
if (!user_mode(regs)) {
void show_stack(struct task_struct *tsk, unsigned long *sp);
unsigned long sp = regs->regs[15] & 0xffffffff;
struct task_struct *tsk = get_current();
tsk->thread.kregs = regs;
show_stack(tsk, (unsigned long *)sp);
}
}
void exit_thread(struct task_struct *tsk)
{
#ifdef CONFIG_SH_FPU
if (last_task_used_math == tsk)
last_task_used_math = NULL;
#endif
}
void flush_thread(void)
{
#ifdef CONFIG_SH_FPU
if (last_task_used_math == current) {
last_task_used_math = NULL;
}
clear_used_math();
#endif
if(current->thread.kregs==&fake_swapper_regs) {
current->thread.kregs =
((struct pt_regs *)(THREAD_SIZE + (unsigned long) current) - 1);
current->thread.uregs = current->thread.kregs;
}
}
void release_thread(struct task_struct *dead_task)
{
}
int dump_fpu(struct pt_regs *regs, elf_fpregset_t *fpu)
{
#ifdef CONFIG_SH_FPU
int fpvalid;
struct task_struct *tsk = current;
fpvalid = !!tsk_used_math(tsk);
if (fpvalid) {
if (current == last_task_used_math) {
enable_fpu();
save_fpu(tsk);
disable_fpu();
last_task_used_math = 0;
regs->sr |= SR_FD;
}
memcpy(fpu, &tsk->thread.xstate->hardfpu, sizeof(*fpu));
}
return fpvalid;
#else
return 0;
#endif
}
int copy_thread(unsigned long clone_flags, unsigned long usp,
unsigned long arg, struct task_struct *p)
{
struct pt_regs *childregs;
#ifdef CONFIG_SH_FPU
if (last_task_used_math == current) {
enable_fpu();
save_fpu(current);
disable_fpu();
last_task_used_math = NULL;
current_pt_regs()->sr |= SR_FD;
}
#endif
childregs = (struct pt_regs *)(THREAD_SIZE + task_stack_page(p)) - 1;
p->thread.sp = (unsigned long) childregs;
if (unlikely(p->flags & PF_KTHREAD)) {
memset(childregs, 0, sizeof(struct pt_regs));
childregs->regs[2] = (unsigned long)arg;
childregs->regs[3] = (unsigned long)usp;
childregs->sr = (1 << 30);
childregs->sr |= SR_FD;
p->thread.pc = (unsigned long) ret_from_kernel_thread;
return 0;
}
*childregs = *current_pt_regs();
if (usp)
childregs->regs[15] = neff_sign_extend(usp);
p->thread.uregs = childregs;
childregs->regs[9] = 0;
childregs->sr |= SR_FD;
p->thread.pc = (unsigned long) ret_from_fork;
return 0;
}
static int in_sh64_switch_to(unsigned long pc)
{
extern char __sh64_switch_to_end;
return (pc >= (unsigned long) sh64_switch_to) &&
(pc < (unsigned long) &__sh64_switch_to_end);
}
unsigned long get_wchan(struct task_struct *p)
{
unsigned long pc;
if (!p || p == current || p->state == TASK_RUNNING)
return 0;
pc = thread_saved_pc(p);
#ifdef CONFIG_FRAME_POINTER
if (in_sh64_switch_to(pc)) {
unsigned long schedule_fp;
unsigned long sh64_switch_to_fp;
unsigned long schedule_caller_pc;
sh64_switch_to_fp = (long) p->thread.sp;
schedule_fp = *(unsigned long *) (long)(sh64_switch_to_fp + 4);
schedule_caller_pc = *(unsigned long *) (long)(schedule_fp + 24);
return schedule_caller_pc;
}
#endif
return pc;
}
