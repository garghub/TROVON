static unsigned find_nextpc(struct pt_regs *regs, int *flags)
{
unsigned size;
s8 x8;
s16 x16;
s32 x32;
u8 opc, *pc, *sp, *next;
next = 0;
*flags = SINGLESTEP_PCREL;
pc = (u8 *) regs->pc;
sp = (u8 *) (regs + 1);
opc = *pc;
size = mn10300_insn_sizes[opc];
if (size > 0) {
next = pc + size;
} else {
switch (opc) {
case 0xc0 ... 0xca:
x8 = 2;
if (cond_table[regs->epsw & 0xf] & (1 << (opc & 0xf)))
x8 = (s8)pc[1];
next = pc + x8;
*flags |= SINGLESTEP_BRANCH;
break;
case 0xcc:
case 0xcd:
READ_WORD16(pc + 1, &x16);
next = pc + x16;
*flags |= SINGLESTEP_BRANCH;
break;
case 0xdc:
case 0xdd:
READ_WORD32(pc + 1, &x32);
next = pc + x32;
*flags |= SINGLESTEP_BRANCH;
break;
case 0xde:
next = (u8 *)regs->mdr;
*flags &= ~SINGLESTEP_PCREL;
*flags |= SINGLESTEP_BRANCH;
break;
case 0xdf:
sp += pc[2];
READ_WORD32(sp, &x32);
next = (u8 *)x32;
*flags &= ~SINGLESTEP_PCREL;
*flags |= SINGLESTEP_BRANCH;
break;
case 0xf0:
next = pc + 2;
opc = pc[1];
if (opc >= 0xf0 && opc <= 0xf7) {
switch (opc & 3) {
case 0:
next = (u8 *)regs->a0;
break;
case 1:
next = (u8 *)regs->a1;
break;
case 2:
next = (u8 *)regs->a2;
break;
case 3:
next = (u8 *)regs->a3;
break;
}
*flags &= ~SINGLESTEP_PCREL;
*flags |= SINGLESTEP_BRANCH;
} else if (opc == 0xfc) {
READ_WORD32(sp, &x32);
next = (u8 *)x32;
*flags &= ~SINGLESTEP_PCREL;
*flags |= SINGLESTEP_BRANCH;
} else if (opc == 0xfd) {
READ_WORD32(sp + 4, &x32);
next = (u8 *)x32;
*flags &= ~SINGLESTEP_PCREL;
*flags |= SINGLESTEP_BRANCH;
}
break;
case 0xf8:
next = pc + 3;
opc = pc[1];
if (opc >= 0xe8 && opc <= 0xeb &&
(cond_table[regs->epsw & 0xf] &
(1 << ((opc & 0xf) + 3)))
) {
READ_BYTE(pc+2, &x8);
next = pc + x8;
*flags |= SINGLESTEP_BRANCH;
}
break;
case 0xfa:
if (pc[1] == 0xff) {
READ_WORD16(pc + 2, &x16);
next = pc + x16;
} else
next = pc + 4;
*flags |= SINGLESTEP_BRANCH;
break;
case 0xfc:
x32 = 6;
if (pc[1] == 0xff) {
READ_WORD32(pc + 2, &x32);
}
next = pc + x32;
*flags |= SINGLESTEP_BRANCH;
break;
case 0xd0 ... 0xda:
case 0xdb:
panic("Can't singlestep Lxx/SETLB\n");
break;
}
}
return (unsigned)next;
}
static unsigned __kprobes singlestep_branch_setup(struct pt_regs *regs)
{
u8 opc, *pc, *sp, *next;
next = NULL;
pc = (u8 *) regs->pc;
sp = (u8 *) (regs + 1);
switch (pc[0]) {
case 0xc0 ... 0xca:
case 0xcc:
case 0xdc:
case 0xf8:
next = pc;
break;
case 0xcd:
pc[1] = 5;
pc[2] = 0;
next = pc + 5;
break;
case 0xdd:
pc[1] = 7;
pc[2] = 0;
pc[3] = 0;
pc[4] = 0;
next = pc + 7;
break;
case 0xde:
next = pc + 3;
regs->mdr = (unsigned) next;
break;
case 0xdf:
sp += pc[2];
next = pc + 3;
*(unsigned *)sp = (unsigned) next;
break;
case 0xf0:
next = pc + 2;
opc = pc[1];
if (opc >= 0xf0 && opc <= 0xf3) {
pc[0] = 0xfa;
pc[1] = 0xff;
pc[2] = 4;
pc[3] = 0;
next = pc + 4;
} else if (opc >= 0xf4 && opc <= 0xf7) {
next = pc;
} else if (opc == 0xfc) {
next = pc + 2;
*(unsigned *) sp = (unsigned) next;
} else if (opc == 0xfd) {
next = pc + 2;
*(unsigned *)(sp + 4) = (unsigned) next;
}
break;
case 0xfa:
pc[2] = 4;
pc[3] = 0;
next = pc + 4;
break;
case 0xfc:
pc[2] = 6;
pc[3] = 0;
pc[4] = 0;
pc[5] = 0;
next = pc + 6;
break;
case 0xd0 ... 0xda:
case 0xdb:
panic("Can't singlestep Lxx/SETLB\n");
}
return (unsigned) next;
}
int __kprobes arch_prepare_kprobe(struct kprobe *p)
{
return 0;
}
void __kprobes arch_copy_kprobe(struct kprobe *p)
{
memcpy(p->ainsn.insn, p->addr, MAX_INSN_SIZE);
}
void __kprobes arch_arm_kprobe(struct kprobe *p)
{
*p->addr = BREAKPOINT_INSTRUCTION;
flush_icache_range((unsigned long) p->addr,
(unsigned long) p->addr + sizeof(kprobe_opcode_t));
}
void __kprobes arch_disarm_kprobe(struct kprobe *p)
{
#ifndef CONFIG_MN10300_CACHE_SNOOP
mn10300_dcache_flush();
mn10300_icache_inv();
#endif
}
void arch_remove_kprobe(struct kprobe *p)
{
}
static inline
void __kprobes disarm_kprobe(struct kprobe *p, struct pt_regs *regs)
{
*p->addr = p->opcode;
regs->pc = (unsigned long) p->addr;
#ifndef CONFIG_MN10300_CACHE_SNOOP
mn10300_dcache_flush();
mn10300_icache_inv();
#endif
}
static inline
void __kprobes prepare_singlestep(struct kprobe *p, struct pt_regs *regs)
{
unsigned long nextpc;
cur_kprobe_orig_pc = regs->pc;
memcpy(cur_kprobe_ss_buf, &p->ainsn.insn[0], MAX_INSN_SIZE);
regs->pc = (unsigned long) cur_kprobe_ss_buf;
nextpc = find_nextpc(regs, &cur_kprobe_ss_flags);
if (cur_kprobe_ss_flags & SINGLESTEP_PCREL)
cur_kprobe_next_pc = cur_kprobe_orig_pc + (nextpc - regs->pc);
else
cur_kprobe_next_pc = nextpc;
if (cur_kprobe_ss_flags & SINGLESTEP_BRANCH)
nextpc = singlestep_branch_setup(regs);
cur_kprobe_bp_addr = nextpc;
*(u8 *) nextpc = BREAKPOINT_INSTRUCTION;
mn10300_dcache_flush_range2((unsigned) cur_kprobe_ss_buf,
sizeof(cur_kprobe_ss_buf));
mn10300_icache_inv();
}
static inline int __kprobes kprobe_handler(struct pt_regs *regs)
{
struct kprobe *p;
int ret = 0;
unsigned int *addr = (unsigned int *) regs->pc;
preempt_disable();
if (kprobe_running()) {
p = get_kprobe(addr);
if (p) {
disarm_kprobe(p, regs);
ret = 1;
} else {
p = cur_kprobe;
if (p->break_handler && p->break_handler(p, regs))
goto ss_probe;
}
goto no_kprobe;
}
p = get_kprobe(addr);
if (!p) {
if (*addr != BREAKPOINT_INSTRUCTION) {
ret = 1;
}
goto no_kprobe;
}
kprobe_status = KPROBE_HIT_ACTIVE;
cur_kprobe = p;
if (p->pre_handler(p, regs)) {
return 1;
}
ss_probe:
prepare_singlestep(p, regs);
kprobe_status = KPROBE_HIT_SS;
return 1;
no_kprobe:
preempt_enable_no_resched();
return ret;
}
static void __kprobes resume_execution(struct kprobe *p, struct pt_regs *regs)
{
if (cur_kprobe_ss_flags & SINGLESTEP_BRANCH) {
regs->pc = cur_kprobe_orig_pc;
switch (p->ainsn.insn[0]) {
case 0xcd:
*(unsigned *) regs->sp = regs->mdr = regs->pc + 5;
break;
case 0xdd:
*(unsigned *) regs->sp = regs->mdr = regs->pc + 7;
break;
case 0xf0:
if (p->ainsn.insn[1] >= 0xf0 &&
p->ainsn.insn[1] <= 0xf3) {
regs->mdr = regs->pc + 2;
*(unsigned *) regs->sp = regs->mdr;
}
break;
case 0xfa:
*(unsigned *) regs->sp = regs->mdr = regs->pc + 4;
break;
case 0xfc:
*(unsigned *) regs->sp = regs->mdr = regs->pc + 6;
break;
}
}
regs->pc = cur_kprobe_next_pc;
cur_kprobe_bp_addr = 0;
}
static inline int __kprobes post_kprobe_handler(struct pt_regs *regs)
{
if (!kprobe_running())
return 0;
if (cur_kprobe->post_handler)
cur_kprobe->post_handler(cur_kprobe, regs, 0);
resume_execution(cur_kprobe, regs);
reset_current_kprobe();
preempt_enable_no_resched();
return 1;
}
static inline
int __kprobes kprobe_fault_handler(struct pt_regs *regs, int trapnr)
{
if (cur_kprobe->fault_handler &&
cur_kprobe->fault_handler(cur_kprobe, regs, trapnr))
return 1;
if (kprobe_status & KPROBE_HIT_SS) {
resume_execution(cur_kprobe, regs);
reset_current_kprobe();
preempt_enable_no_resched();
}
return 0;
}
int __kprobes kprobe_exceptions_notify(struct notifier_block *self,
unsigned long val, void *data)
{
struct die_args *args = data;
switch (val) {
case DIE_BREAKPOINT:
if (cur_kprobe_bp_addr != args->regs->pc) {
if (kprobe_handler(args->regs))
return NOTIFY_STOP;
} else {
if (post_kprobe_handler(args->regs))
return NOTIFY_STOP;
}
break;
case DIE_GPF:
if (kprobe_running() &&
kprobe_fault_handler(args->regs, args->trapnr))
return NOTIFY_STOP;
break;
default:
break;
}
return NOTIFY_DONE;
}
int __kprobes setjmp_pre_handler(struct kprobe *p, struct pt_regs *regs)
{
struct jprobe *jp = container_of(p, struct jprobe, kp);
jprobe_saved_regs_location = regs;
memcpy(&jprobe_saved_regs, regs, sizeof(struct pt_regs));
memcpy(&jprobe_saved_stack, regs + 1, sizeof(jprobe_saved_stack));
regs->pc = (unsigned long) jp->entry;
return 1;
}
void __kprobes jprobe_return(void)
{
void *orig_sp = jprobe_saved_regs_location + 1;
preempt_enable_no_resched();
asm volatile(" mov %0,sp\n"
".globl jprobe_return_bp_addr\n"
"jprobe_return_bp_addr:\n\t"
" .byte 0xff\n"
: : "d" (orig_sp));
}
int __kprobes longjmp_break_handler(struct kprobe *p, struct pt_regs *regs)
{
u8 *addr = (u8 *) regs->pc;
if (addr == (u8 *) jprobe_return_bp_addr) {
if (jprobe_saved_regs_location != regs) {
printk(KERN_ERR"JPROBE:"
" Current regs (%p) does not match saved regs"
" (%p).\n",
regs, jprobe_saved_regs_location);
BUG();
}
memcpy(regs, &jprobe_saved_regs, sizeof(struct pt_regs));
memcpy(regs + 1, &jprobe_saved_stack,
sizeof(jprobe_saved_stack));
return 1;
}
return 0;
}
int __init arch_init_kprobes(void)
{
return 0;
}
