static inline unsigned long
__encode_dr7(int drnum, unsigned int len, unsigned int type)
{
unsigned long bp_info;
bp_info = (len | type) & 0xf;
bp_info <<= (DR_CONTROL_SHIFT + drnum * DR_CONTROL_SIZE);
bp_info |= (DR_GLOBAL_ENABLE << (drnum * DR_ENABLE_SIZE));
return bp_info;
}
unsigned long encode_dr7(int drnum, unsigned int len, unsigned int type)
{
return __encode_dr7(drnum, len, type) | DR_GLOBAL_SLOWDOWN;
}
int decode_dr7(unsigned long dr7, int bpnum, unsigned *len, unsigned *type)
{
int bp_info = dr7 >> (DR_CONTROL_SHIFT + bpnum * DR_CONTROL_SIZE);
*len = (bp_info & 0xc) | 0x40;
*type = (bp_info & 0x3) | 0x80;
return (dr7 >> (bpnum * DR_ENABLE_SIZE)) & 0x3;
}
int arch_install_hw_breakpoint(struct perf_event *bp)
{
struct arch_hw_breakpoint *info = counter_arch_bp(bp);
unsigned long *dr7;
int i;
for (i = 0; i < HBP_NUM; i++) {
struct perf_event **slot = this_cpu_ptr(&bp_per_reg[i]);
if (!*slot) {
*slot = bp;
break;
}
}
if (WARN_ONCE(i == HBP_NUM, "Can't find any breakpoint slot"))
return -EBUSY;
set_debugreg(info->address, i);
__this_cpu_write(cpu_debugreg[i], info->address);
dr7 = this_cpu_ptr(&cpu_dr7);
*dr7 |= encode_dr7(i, info->len, info->type);
set_debugreg(*dr7, 7);
if (info->mask)
set_dr_addr_mask(info->mask, i);
return 0;
}
void arch_uninstall_hw_breakpoint(struct perf_event *bp)
{
struct arch_hw_breakpoint *info = counter_arch_bp(bp);
unsigned long *dr7;
int i;
for (i = 0; i < HBP_NUM; i++) {
struct perf_event **slot = this_cpu_ptr(&bp_per_reg[i]);
if (*slot == bp) {
*slot = NULL;
break;
}
}
if (WARN_ONCE(i == HBP_NUM, "Can't find any breakpoint slot"))
return;
dr7 = this_cpu_ptr(&cpu_dr7);
*dr7 &= ~__encode_dr7(i, info->len, info->type);
set_debugreg(*dr7, 7);
if (info->mask)
set_dr_addr_mask(0, i);
}
int arch_check_bp_in_kernelspace(struct perf_event *bp)
{
unsigned int len;
unsigned long va;
struct arch_hw_breakpoint *info = counter_arch_bp(bp);
va = info->address;
len = bp->attr.bp_len;
return (va >= TASK_SIZE_MAX) || ((va + len - 1) >= TASK_SIZE_MAX);
}
int arch_bp_generic_fields(int x86_len, int x86_type,
int *gen_len, int *gen_type)
{
switch (x86_type) {
case X86_BREAKPOINT_EXECUTE:
if (x86_len != X86_BREAKPOINT_LEN_X)
return -EINVAL;
*gen_type = HW_BREAKPOINT_X;
*gen_len = sizeof(long);
return 0;
case X86_BREAKPOINT_WRITE:
*gen_type = HW_BREAKPOINT_W;
break;
case X86_BREAKPOINT_RW:
*gen_type = HW_BREAKPOINT_W | HW_BREAKPOINT_R;
break;
default:
return -EINVAL;
}
switch (x86_len) {
case X86_BREAKPOINT_LEN_1:
*gen_len = HW_BREAKPOINT_LEN_1;
break;
case X86_BREAKPOINT_LEN_2:
*gen_len = HW_BREAKPOINT_LEN_2;
break;
case X86_BREAKPOINT_LEN_4:
*gen_len = HW_BREAKPOINT_LEN_4;
break;
#ifdef CONFIG_X86_64
case X86_BREAKPOINT_LEN_8:
*gen_len = HW_BREAKPOINT_LEN_8;
break;
#endif
default:
return -EINVAL;
}
return 0;
}
static int arch_build_bp_info(struct perf_event *bp)
{
struct arch_hw_breakpoint *info = counter_arch_bp(bp);
info->address = bp->attr.bp_addr;
switch (bp->attr.bp_type) {
case HW_BREAKPOINT_W:
info->type = X86_BREAKPOINT_WRITE;
break;
case HW_BREAKPOINT_W | HW_BREAKPOINT_R:
info->type = X86_BREAKPOINT_RW;
break;
case HW_BREAKPOINT_X:
if (bp->attr.bp_addr >= TASK_SIZE_MAX) {
#ifdef CONFIG_KPROBES
if (within_kprobe_blacklist(bp->attr.bp_addr))
return -EINVAL;
#else
return -EINVAL;
#endif
}
info->type = X86_BREAKPOINT_EXECUTE;
if (bp->attr.bp_len == sizeof(long)) {
info->len = X86_BREAKPOINT_LEN_X;
return 0;
}
default:
return -EINVAL;
}
info->mask = 0;
switch (bp->attr.bp_len) {
case HW_BREAKPOINT_LEN_1:
info->len = X86_BREAKPOINT_LEN_1;
break;
case HW_BREAKPOINT_LEN_2:
info->len = X86_BREAKPOINT_LEN_2;
break;
case HW_BREAKPOINT_LEN_4:
info->len = X86_BREAKPOINT_LEN_4;
break;
#ifdef CONFIG_X86_64
case HW_BREAKPOINT_LEN_8:
info->len = X86_BREAKPOINT_LEN_8;
break;
#endif
default:
if (!is_power_of_2(bp->attr.bp_len))
return -EINVAL;
if (bp->attr.bp_addr & (bp->attr.bp_len - 1))
return -EINVAL;
if (!boot_cpu_has(X86_FEATURE_BPEXT))
return -EOPNOTSUPP;
info->mask = bp->attr.bp_len - 1;
info->len = X86_BREAKPOINT_LEN_1;
}
return 0;
}
int arch_validate_hwbkpt_settings(struct perf_event *bp)
{
struct arch_hw_breakpoint *info = counter_arch_bp(bp);
unsigned int align;
int ret;
ret = arch_build_bp_info(bp);
if (ret)
return ret;
switch (info->len) {
case X86_BREAKPOINT_LEN_1:
align = 0;
if (info->mask)
align = info->mask;
break;
case X86_BREAKPOINT_LEN_2:
align = 1;
break;
case X86_BREAKPOINT_LEN_4:
align = 3;
break;
#ifdef CONFIG_X86_64
case X86_BREAKPOINT_LEN_8:
align = 7;
break;
#endif
default:
WARN_ON_ONCE(1);
}
if (info->address & align)
return -EINVAL;
return 0;
}
void aout_dump_debugregs(struct user *dump)
{
int i;
int dr7 = 0;
struct perf_event *bp;
struct arch_hw_breakpoint *info;
struct thread_struct *thread = &current->thread;
for (i = 0; i < HBP_NUM; i++) {
bp = thread->ptrace_bps[i];
if (bp && !bp->attr.disabled) {
dump->u_debugreg[i] = bp->attr.bp_addr;
info = counter_arch_bp(bp);
dr7 |= encode_dr7(i, info->len, info->type);
} else {
dump->u_debugreg[i] = 0;
}
}
dump->u_debugreg[4] = 0;
dump->u_debugreg[5] = 0;
dump->u_debugreg[6] = current->thread.debugreg6;
dump->u_debugreg[7] = dr7;
}
void flush_ptrace_hw_breakpoint(struct task_struct *tsk)
{
int i;
struct thread_struct *t = &tsk->thread;
for (i = 0; i < HBP_NUM; i++) {
unregister_hw_breakpoint(t->ptrace_bps[i]);
t->ptrace_bps[i] = NULL;
}
t->debugreg6 = 0;
t->ptrace_dr7 = 0;
}
void hw_breakpoint_restore(void)
{
set_debugreg(__this_cpu_read(cpu_debugreg[0]), 0);
set_debugreg(__this_cpu_read(cpu_debugreg[1]), 1);
set_debugreg(__this_cpu_read(cpu_debugreg[2]), 2);
set_debugreg(__this_cpu_read(cpu_debugreg[3]), 3);
set_debugreg(current->thread.debugreg6, 6);
set_debugreg(__this_cpu_read(cpu_dr7), 7);
}
static int hw_breakpoint_handler(struct die_args *args)
{
int i, cpu, rc = NOTIFY_STOP;
struct perf_event *bp;
unsigned long dr7, dr6;
unsigned long *dr6_p;
dr6_p = (unsigned long *)ERR_PTR(args->err);
dr6 = *dr6_p;
if (dr6 & DR_STEP)
return NOTIFY_DONE;
if ((dr6 & DR_TRAP_BITS) == 0)
return NOTIFY_DONE;
get_debugreg(dr7, 7);
set_debugreg(0UL, 7);
current->thread.debugreg6 &= ~DR_TRAP_BITS;
cpu = get_cpu();
for (i = 0; i < HBP_NUM; ++i) {
if (likely(!(dr6 & (DR_TRAP0 << i))))
continue;
rcu_read_lock();
bp = per_cpu(bp_per_reg[i], cpu);
(*dr6_p) &= ~(DR_TRAP0 << i);
if (!bp) {
rcu_read_unlock();
break;
}
perf_bp_event(bp, args->regs);
if (bp->hw.info.type == X86_BREAKPOINT_EXECUTE)
args->regs->flags |= X86_EFLAGS_RF;
rcu_read_unlock();
}
if ((current->thread.debugreg6 & DR_TRAP_BITS) ||
(dr6 & (~DR_TRAP_BITS)))
rc = NOTIFY_DONE;
set_debugreg(dr7, 7);
put_cpu();
return rc;
}
int hw_breakpoint_exceptions_notify(
struct notifier_block *unused, unsigned long val, void *data)
{
if (val != DIE_DEBUG)
return NOTIFY_DONE;
return hw_breakpoint_handler(data);
}
void hw_breakpoint_pmu_read(struct perf_event *bp)
{
}
