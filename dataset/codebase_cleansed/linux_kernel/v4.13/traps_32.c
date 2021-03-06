static inline void sign_extend(unsigned int count, unsigned char *dst)
{
#ifdef __LITTLE_ENDIAN__
if ((count == 1) && dst[0] & 0x80) {
dst[1] = 0xff;
dst[2] = 0xff;
dst[3] = 0xff;
}
if ((count == 2) && dst[1] & 0x80) {
dst[2] = 0xff;
dst[3] = 0xff;
}
#else
if ((count == 1) && dst[3] & 0x80) {
dst[2] = 0xff;
dst[1] = 0xff;
dst[0] = 0xff;
}
if ((count == 2) && dst[2] & 0x80) {
dst[1] = 0xff;
dst[0] = 0xff;
}
#endif
}
static int handle_unaligned_ins(insn_size_t instruction, struct pt_regs *regs,
struct mem_access *ma)
{
int ret, index, count;
unsigned long *rm, *rn;
unsigned char *src, *dst;
unsigned char __user *srcu, *dstu;
index = (instruction>>8)&15;
rn = &regs->regs[index];
index = (instruction>>4)&15;
rm = &regs->regs[index];
count = 1<<(instruction&3);
switch (count) {
case 1: inc_unaligned_byte_access(); break;
case 2: inc_unaligned_word_access(); break;
case 4: inc_unaligned_dword_access(); break;
case 8: inc_unaligned_multi_access(); break;
}
ret = -EFAULT;
switch (instruction>>12) {
case 0:
if (instruction & 8) {
srcu = (unsigned char __user *)*rm;
srcu += regs->regs[0];
dst = (unsigned char *)rn;
*(unsigned long *)dst = 0;
#if !defined(__LITTLE_ENDIAN__)
dst += 4-count;
#endif
if (ma->from(dst, srcu, count))
goto fetch_fault;
sign_extend(count, dst);
} else {
src = (unsigned char *)rm;
#if !defined(__LITTLE_ENDIAN__)
src += 4-count;
#endif
dstu = (unsigned char __user *)*rn;
dstu += regs->regs[0];
if (ma->to(dstu, src, count))
goto fetch_fault;
}
ret = 0;
break;
case 1:
src = (unsigned char*) rm;
dstu = (unsigned char __user *)*rn;
dstu += (instruction&0x000F)<<2;
if (ma->to(dstu, src, 4))
goto fetch_fault;
ret = 0;
break;
case 2:
if (instruction & 4)
*rn -= count;
src = (unsigned char*) rm;
dstu = (unsigned char __user *)*rn;
#if !defined(__LITTLE_ENDIAN__)
src += 4-count;
#endif
if (ma->to(dstu, src, count))
goto fetch_fault;
ret = 0;
break;
case 5:
srcu = (unsigned char __user *)*rm;
srcu += (instruction & 0x000F) << 2;
dst = (unsigned char *)rn;
*(unsigned long *)dst = 0;
if (ma->from(dst, srcu, 4))
goto fetch_fault;
ret = 0;
break;
case 6:
srcu = (unsigned char __user *)*rm;
if (instruction & 4)
*rm += count;
dst = (unsigned char*) rn;
*(unsigned long*)dst = 0;
#if !defined(__LITTLE_ENDIAN__)
dst += 4-count;
#endif
if (ma->from(dst, srcu, count))
goto fetch_fault;
sign_extend(count, dst);
ret = 0;
break;
case 8:
switch ((instruction&0xFF00)>>8) {
case 0x81:
src = (unsigned char *) &regs->regs[0];
#if !defined(__LITTLE_ENDIAN__)
src += 2;
#endif
dstu = (unsigned char __user *)*rm;
dstu += (instruction & 0x000F) << 1;
if (ma->to(dstu, src, 2))
goto fetch_fault;
ret = 0;
break;
case 0x85:
srcu = (unsigned char __user *)*rm;
srcu += (instruction & 0x000F) << 1;
dst = (unsigned char *) &regs->regs[0];
*(unsigned long *)dst = 0;
#if !defined(__LITTLE_ENDIAN__)
dst += 2;
#endif
if (ma->from(dst, srcu, 2))
goto fetch_fault;
sign_extend(2, dst);
ret = 0;
break;
}
break;
case 9:
srcu = (unsigned char __user *)regs->pc;
srcu += 4;
srcu += (instruction & 0x00FF) << 1;
dst = (unsigned char *)rn;
*(unsigned long *)dst = 0;
#if !defined(__LITTLE_ENDIAN__)
dst += 2;
#endif
if (ma->from(dst, srcu, 2))
goto fetch_fault;
sign_extend(2, dst);
ret = 0;
break;
case 0xd:
srcu = (unsigned char __user *)(regs->pc & ~0x3);
srcu += 4;
srcu += (instruction & 0x00FF) << 2;
dst = (unsigned char *)rn;
*(unsigned long *)dst = 0;
if (ma->from(dst, srcu, 4))
goto fetch_fault;
ret = 0;
break;
}
return ret;
fetch_fault:
die_if_no_fixup("Fault in unaligned fixup", regs, 0);
return -EFAULT;
}
static inline int handle_delayslot(struct pt_regs *regs,
insn_size_t old_instruction,
struct mem_access *ma)
{
insn_size_t instruction;
void __user *addr = (void __user *)(regs->pc +
instruction_size(old_instruction));
if (copy_from_user(&instruction, addr, sizeof(instruction))) {
if (user_mode(regs))
return -EFAULT;
die("delay-slot-insn faulting in handle_unaligned_delayslot",
regs, 0);
}
return handle_unaligned_ins(instruction, regs, ma);
}
int handle_unaligned_access(insn_size_t instruction, struct pt_regs *regs,
struct mem_access *ma, int expected,
unsigned long address)
{
u_int rm;
int ret, index;
if (instruction_size(instruction) != 2)
return -EINVAL;
index = (instruction>>8)&15;
rm = regs->regs[index];
if (!expected) {
unaligned_fixups_notify(current, instruction, regs);
perf_sw_event(PERF_COUNT_SW_ALIGNMENT_FAULTS, 1,
regs, address);
}
ret = -EFAULT;
switch (instruction&0xF000) {
case 0x0000:
if (instruction==0x000B) {
ret = handle_delayslot(regs, instruction, ma);
if (ret==0)
regs->pc = regs->pr;
}
else if ((instruction&0x00FF)==0x0023) {
ret = handle_delayslot(regs, instruction, ma);
if (ret==0)
regs->pc += rm + 4;
}
else if ((instruction&0x00FF)==0x0003) {
ret = handle_delayslot(regs, instruction, ma);
if (ret==0) {
regs->pr = regs->pc + 4;
regs->pc += rm + 4;
}
}
else {
goto simple;
}
break;
case 0x1000:
goto simple;
case 0x2000:
goto simple;
case 0x4000:
if ((instruction&0x00FF)==0x002B) {
ret = handle_delayslot(regs, instruction, ma);
if (ret==0)
regs->pc = rm;
}
else if ((instruction&0x00FF)==0x000B) {
ret = handle_delayslot(regs, instruction, ma);
if (ret==0) {
regs->pr = regs->pc + 4;
regs->pc = rm;
}
}
else {
goto simple;
}
break;
case 0x5000:
goto simple;
case 0x6000:
goto simple;
case 0x8000:
switch (instruction&0x0F00) {
case 0x0100:
goto simple;
case 0x0500:
goto simple;
case 0x0B00:
ret = 0;
break;
case 0x0F00:
ret = handle_delayslot(regs, instruction, ma);
if (ret==0) {
#if defined(CONFIG_CPU_SH4) || defined(CONFIG_SH7705_CACHE_32KB)
if ((regs->sr & 0x00000001) != 0)
regs->pc += 4;
else
#endif
regs->pc += SH_PC_8BIT_OFFSET(instruction);
}
break;
case 0x0900:
ret = 0;
break;
case 0x0D00:
ret = handle_delayslot(regs, instruction, ma);
if (ret==0) {
#if defined(CONFIG_CPU_SH4) || defined(CONFIG_SH7705_CACHE_32KB)
if ((regs->sr & 0x00000001) == 0)
regs->pc += 4;
else
#endif
regs->pc += SH_PC_8BIT_OFFSET(instruction);
}
break;
}
break;
case 0x9000:
goto simple;
case 0xA000:
ret = handle_delayslot(regs, instruction, ma);
if (ret==0)
regs->pc += SH_PC_12BIT_OFFSET(instruction);
break;
case 0xB000:
ret = handle_delayslot(regs, instruction, ma);
if (ret==0) {
regs->pr = regs->pc + 4;
regs->pc += SH_PC_12BIT_OFFSET(instruction);
}
break;
case 0xD000:
goto simple;
}
return ret;
simple:
ret = handle_unaligned_ins(instruction, regs, ma);
if (ret==0)
regs->pc += instruction_size(instruction);
return ret;
}
asmlinkage void do_address_error(struct pt_regs *regs,
unsigned long writeaccess,
unsigned long address)
{
unsigned long error_code = 0;
mm_segment_t oldfs;
siginfo_t info;
insn_size_t instruction;
int tmp;
#ifdef CONFIG_CPU_HAS_SR_RB
error_code = lookup_exception_vector();
#endif
oldfs = get_fs();
if (user_mode(regs)) {
int si_code = BUS_ADRERR;
unsigned int user_action;
local_irq_enable();
inc_unaligned_user_access();
set_fs(USER_DS);
if (copy_from_user(&instruction, (insn_size_t *)(regs->pc & ~1),
sizeof(instruction))) {
set_fs(oldfs);
goto uspace_segv;
}
set_fs(oldfs);
unaligned_fixups_notify(current, instruction, regs);
user_action = unaligned_user_action();
if (user_action & UM_FIXUP)
goto fixup;
if (user_action & UM_SIGNAL)
goto uspace_segv;
else {
regs->pc += instruction_size(instruction);
return;
}
fixup:
if (regs->pc & 1) {
si_code = BUS_ADRALN;
goto uspace_segv;
}
set_fs(USER_DS);
tmp = handle_unaligned_access(instruction, regs,
&user_mem_access, 0,
address);
set_fs(oldfs);
if (tmp == 0)
return;
uspace_segv:
printk(KERN_NOTICE "Sending SIGBUS to \"%s\" due to unaligned "
"access (PC %lx PR %lx)\n", current->comm, regs->pc,
regs->pr);
info.si_signo = SIGBUS;
info.si_errno = 0;
info.si_code = si_code;
info.si_addr = (void __user *)address;
force_sig_info(SIGBUS, &info, current);
} else {
inc_unaligned_kernel_access();
if (regs->pc & 1)
die("unaligned program counter", regs, error_code);
set_fs(KERNEL_DS);
if (copy_from_user(&instruction, (void __user *)(regs->pc),
sizeof(instruction))) {
set_fs(oldfs);
die("insn faulting in do_address_error", regs, 0);
}
unaligned_fixups_notify(current, instruction, regs);
handle_unaligned_access(instruction, regs, &user_mem_access,
0, address);
set_fs(oldfs);
}
}
int is_dsp_inst(struct pt_regs *regs)
{
unsigned short inst = 0;
if (!(current_cpu_data.flags & CPU_HAS_DSP) || (regs->sr & SR_DSP))
return 0;
get_user(inst, ((unsigned short *) regs->pc));
inst &= 0xf000;
if ((inst == 0xf000) || (inst == 0x4000))
return 1;
return 0;
}
asmlinkage void do_divide_error(unsigned long r4)
{
siginfo_t info;
switch (r4) {
case TRAP_DIVZERO_ERROR:
info.si_code = FPE_INTDIV;
break;
case TRAP_DIVOVF_ERROR:
info.si_code = FPE_INTOVF;
break;
}
force_sig_info(SIGFPE, &info, current);
}
asmlinkage void do_reserved_inst(void)
{
struct pt_regs *regs = current_pt_regs();
unsigned long error_code;
struct task_struct *tsk = current;
#ifdef CONFIG_SH_FPU_EMU
unsigned short inst = 0;
int err;
get_user(inst, (unsigned short*)regs->pc);
err = do_fpu_inst(inst, regs);
if (!err) {
regs->pc += instruction_size(inst);
return;
}
#endif
#ifdef CONFIG_SH_DSP
if (is_dsp_inst(regs)) {
regs->sr |= SR_DSP;
tsk->thread.dsp_status.status |= SR_DSP;
return;
}
#endif
error_code = lookup_exception_vector();
local_irq_enable();
force_sig(SIGILL, tsk);
die_if_no_fixup("reserved instruction", regs, error_code);
}
static int emulate_branch(unsigned short inst, struct pt_regs *regs)
{
if (((inst & 0xf000) == 0xb000) ||
((inst & 0xf0ff) == 0x0003) ||
((inst & 0xf0ff) == 0x400b))
regs->pr = regs->pc + 4;
if ((inst & 0xfd00) == 0x8d00) {
regs->pc += SH_PC_8BIT_OFFSET(inst);
return 0;
}
if ((inst & 0xe000) == 0xa000) {
regs->pc += SH_PC_12BIT_OFFSET(inst);
return 0;
}
if ((inst & 0xf0df) == 0x0003) {
regs->pc += regs->regs[(inst & 0x0f00) >> 8] + 4;
return 0;
}
if ((inst & 0xf0df) == 0x400b) {
regs->pc = regs->regs[(inst & 0x0f00) >> 8];
return 0;
}
if ((inst & 0xffff) == 0x000b) {
regs->pc = regs->pr;
return 0;
}
return 1;
}
asmlinkage void do_illegal_slot_inst(void)
{
struct pt_regs *regs = current_pt_regs();
unsigned long inst;
struct task_struct *tsk = current;
if (kprobe_handle_illslot(regs->pc) == 0)
return;
#ifdef CONFIG_SH_FPU_EMU
get_user(inst, (unsigned short *)regs->pc + 1);
if (!do_fpu_inst(inst, regs)) {
get_user(inst, (unsigned short *)regs->pc);
if (!emulate_branch(inst, regs))
return;
}
#endif
inst = lookup_exception_vector();
local_irq_enable();
force_sig(SIGILL, tsk);
die_if_no_fixup("illegal slot instruction", regs, inst);
}
asmlinkage void do_exception_error(void)
{
long ex;
ex = lookup_exception_vector();
die_if_kernel("exception", current_pt_regs(), ex);
}
void per_cpu_trap_init(void)
{
extern void *vbr_base;
asm volatile("ldc %0, vbr"
:
: "r" (&vbr_base)
: "memory");
clear_bl_bit();
}
void *set_exception_table_vec(unsigned int vec, void *handler)
{
extern void *exception_handling_table[];
void *old_handler;
old_handler = exception_handling_table[vec];
exception_handling_table[vec] = handler;
return old_handler;
}
void __init trap_init(void)
{
set_exception_table_vec(TRAP_RESERVED_INST, do_reserved_inst);
set_exception_table_vec(TRAP_ILLEGAL_SLOT_INST, do_illegal_slot_inst);
#if defined(CONFIG_CPU_SH4) && !defined(CONFIG_SH_FPU) || \
defined(CONFIG_SH_FPU_EMU)
set_exception_table_evt(0x800, do_reserved_inst);
set_exception_table_evt(0x820, do_illegal_slot_inst);
#elif defined(CONFIG_SH_FPU)
set_exception_table_evt(0x800, fpu_state_restore_trap_handler);
set_exception_table_evt(0x820, fpu_state_restore_trap_handler);
#endif
#ifdef CONFIG_CPU_SH2
set_exception_table_vec(TRAP_ADDRESS_ERROR, address_error_trap_handler);
#endif
#ifdef CONFIG_CPU_SH2A
set_exception_table_vec(TRAP_DIVZERO_ERROR, do_divide_error);
set_exception_table_vec(TRAP_DIVOVF_ERROR, do_divide_error);
#ifdef CONFIG_SH_FPU
set_exception_table_vec(TRAP_FPU_ERROR, fpu_error_trap_handler);
#endif
#endif
#ifdef TRAP_UBC
set_exception_table_vec(TRAP_UBC, breakpoint_trap_handler);
#endif
}
