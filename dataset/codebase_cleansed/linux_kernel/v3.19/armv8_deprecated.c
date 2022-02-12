static void register_emulation_hooks(struct insn_emulation_ops *ops)
{
struct undef_hook *hook;
BUG_ON(!ops->hooks);
for (hook = ops->hooks; hook->instr_mask; hook++)
register_undef_hook(hook);
pr_notice("Registered %s emulation handler\n", ops->name);
}
static void remove_emulation_hooks(struct insn_emulation_ops *ops)
{
struct undef_hook *hook;
BUG_ON(!ops->hooks);
for (hook = ops->hooks; hook->instr_mask; hook++)
unregister_undef_hook(hook);
pr_notice("Removed %s emulation handler\n", ops->name);
}
static int update_insn_emulation_mode(struct insn_emulation *insn,
enum insn_emulation_mode prev)
{
int ret = 0;
switch (prev) {
case INSN_UNDEF:
break;
case INSN_EMULATE:
remove_emulation_hooks(insn->ops);
break;
case INSN_HW:
if (insn->ops->set_hw_mode) {
insn->ops->set_hw_mode(false);
pr_notice("Disabled %s support\n", insn->ops->name);
}
break;
}
switch (insn->current_mode) {
case INSN_UNDEF:
break;
case INSN_EMULATE:
register_emulation_hooks(insn->ops);
break;
case INSN_HW:
if (insn->ops->set_hw_mode && insn->ops->set_hw_mode(true))
pr_notice("Enabled %s support\n", insn->ops->name);
else
ret = -EINVAL;
break;
}
return ret;
}
static void register_insn_emulation(struct insn_emulation_ops *ops)
{
unsigned long flags;
struct insn_emulation *insn;
insn = kzalloc(sizeof(*insn), GFP_KERNEL);
insn->ops = ops;
insn->min = INSN_UNDEF;
switch (ops->status) {
case INSN_DEPRECATED:
insn->current_mode = INSN_EMULATE;
insn->max = INSN_HW;
break;
case INSN_OBSOLETE:
insn->current_mode = INSN_UNDEF;
insn->max = INSN_EMULATE;
break;
}
raw_spin_lock_irqsave(&insn_emulation_lock, flags);
list_add(&insn->node, &insn_emulation);
nr_insn_emulated++;
raw_spin_unlock_irqrestore(&insn_emulation_lock, flags);
update_insn_emulation_mode(insn, INSN_UNDEF);
}
static int emulation_proc_handler(struct ctl_table *table, int write,
void __user *buffer, size_t *lenp,
loff_t *ppos)
{
int ret = 0;
struct insn_emulation *insn = (struct insn_emulation *) table->data;
enum insn_emulation_mode prev_mode = insn->current_mode;
table->data = &insn->current_mode;
ret = proc_dointvec_minmax(table, write, buffer, lenp, ppos);
if (ret || !write || prev_mode == insn->current_mode)
goto ret;
ret = update_insn_emulation_mode(insn, prev_mode);
if (ret) {
insn->current_mode = prev_mode;
update_insn_emulation_mode(insn, INSN_UNDEF);
}
ret:
table->data = insn;
return ret;
}
static void register_insn_emulation_sysctl(struct ctl_table *table)
{
unsigned long flags;
int i = 0;
struct insn_emulation *insn;
struct ctl_table *insns_sysctl, *sysctl;
insns_sysctl = kzalloc(sizeof(*sysctl) * (nr_insn_emulated + 1),
GFP_KERNEL);
raw_spin_lock_irqsave(&insn_emulation_lock, flags);
list_for_each_entry(insn, &insn_emulation, node) {
sysctl = &insns_sysctl[i];
sysctl->mode = 0644;
sysctl->maxlen = sizeof(int);
sysctl->procname = insn->ops->name;
sysctl->data = insn;
sysctl->extra1 = &insn->min;
sysctl->extra2 = &insn->max;
sysctl->proc_handler = emulation_proc_handler;
i++;
}
raw_spin_unlock_irqrestore(&insn_emulation_lock, flags);
table->child = insns_sysctl;
register_sysctl_table(table);
}
static void set_segfault(struct pt_regs *regs, unsigned long addr)
{
siginfo_t info;
down_read(&current->mm->mmap_sem);
if (find_vma(current->mm, addr) == NULL)
info.si_code = SEGV_MAPERR;
else
info.si_code = SEGV_ACCERR;
up_read(&current->mm->mmap_sem);
info.si_signo = SIGSEGV;
info.si_errno = 0;
info.si_addr = (void *) instruction_pointer(regs);
pr_debug("SWP{B} emulation: access caused memory abort!\n");
arm64_notify_die("Illegal memory access", regs, &info, 0);
}
static int emulate_swpX(unsigned int address, unsigned int *data,
unsigned int type)
{
unsigned int res = 0;
if ((type != TYPE_SWPB) && (address & 0x3)) {
pr_debug("SWP instruction on unaligned pointer!\n");
return -EFAULT;
}
while (1) {
unsigned long temp;
if (type == TYPE_SWPB)
__user_swpb_asm(*data, address, res, temp);
else
__user_swp_asm(*data, address, res, temp);
if (likely(res != -EAGAIN) || signal_pending(current))
break;
cond_resched();
}
return res;
}
static int swp_handler(struct pt_regs *regs, u32 instr)
{
u32 destreg, data, type, address = 0;
int rn, rt2, res = 0;
perf_sw_event(PERF_COUNT_SW_EMULATION_FAULTS, 1, regs, regs->pc);
type = instr & TYPE_SWPB;
switch (arm_check_condition(instr, regs->pstate)) {
case ARM_OPCODE_CONDTEST_PASS:
break;
case ARM_OPCODE_CONDTEST_FAIL:
goto ret;
case ARM_OPCODE_CONDTEST_UNCOND:
return -EFAULT;
default:
return -EINVAL;
}
rn = aarch32_insn_extract_reg_num(instr, A32_RN_OFFSET);
rt2 = aarch32_insn_extract_reg_num(instr, A32_RT2_OFFSET);
address = (u32)regs->user_regs.regs[rn];
data = (u32)regs->user_regs.regs[rt2];
destreg = aarch32_insn_extract_reg_num(instr, A32_RT_OFFSET);
pr_debug("addr in r%d->0x%08x, dest is r%d, source in r%d->0x%08x)\n",
rn, address, destreg,
aarch32_insn_extract_reg_num(instr, A32_RT2_OFFSET), data);
if (!access_ok(VERIFY_WRITE, (address & ~3), 4)) {
pr_debug("SWP{B} emulation: access to 0x%08x not allowed!\n",
address);
goto fault;
}
res = emulate_swpX(address, &data, type);
if (res == -EFAULT)
goto fault;
else if (res == 0)
regs->user_regs.regs[destreg] = data;
ret:
if (type == TYPE_SWPB)
trace_instruction_emulation("swpb", regs->pc);
else
trace_instruction_emulation("swp", regs->pc);
pr_warn_ratelimited("\"%s\" (%ld) uses obsolete SWP{B} instruction at 0x%llx\n",
current->comm, (unsigned long)current->pid, regs->pc);
regs->pc += 4;
return 0;
fault:
set_segfault(regs, address);
return 0;
}
static int cp15barrier_handler(struct pt_regs *regs, u32 instr)
{
perf_sw_event(PERF_COUNT_SW_EMULATION_FAULTS, 1, regs, regs->pc);
switch (arm_check_condition(instr, regs->pstate)) {
case ARM_OPCODE_CONDTEST_PASS:
break;
case ARM_OPCODE_CONDTEST_FAIL:
goto ret;
case ARM_OPCODE_CONDTEST_UNCOND:
return -EFAULT;
default:
return -EINVAL;
}
switch (aarch32_insn_mcr_extract_crm(instr)) {
case 10:
if (aarch32_insn_mcr_extract_opc2(instr) == 5) {
dmb(sy);
trace_instruction_emulation(
"mcr p15, 0, Rt, c7, c10, 5 ; dmb", regs->pc);
} else {
dsb(sy);
trace_instruction_emulation(
"mcr p15, 0, Rt, c7, c10, 4 ; dsb", regs->pc);
}
break;
case 5:
trace_instruction_emulation(
"mcr p15, 0, Rt, c7, c5, 4 ; isb", regs->pc);
break;
}
ret:
pr_warn_ratelimited("\"%s\" (%ld) uses deprecated CP15 Barrier instruction at 0x%llx\n",
current->comm, (unsigned long)current->pid, regs->pc);
regs->pc += 4;
return 0;
}
static inline void config_sctlr_el1(u32 clear, u32 set)
{
u32 val;
asm volatile("mrs %0, sctlr_el1" : "=r" (val));
val &= ~clear;
val |= set;
asm volatile("msr sctlr_el1, %0" : : "r" (val));
}
static void enable_cp15_ben(void *info)
{
config_sctlr_el1(0, SCTLR_EL1_CP15BEN);
}
static void disable_cp15_ben(void *info)
{
config_sctlr_el1(SCTLR_EL1_CP15BEN, 0);
}
static int cpu_hotplug_notify(struct notifier_block *b,
unsigned long action, void *hcpu)
{
switch (action) {
case CPU_STARTING:
case CPU_STARTING_FROZEN:
enable_cp15_ben(NULL);
return NOTIFY_DONE;
case CPU_DYING:
case CPU_DYING_FROZEN:
disable_cp15_ben(NULL);
return NOTIFY_DONE;
}
return NOTIFY_OK;
}
static int cp15_barrier_set_hw_mode(bool enable)
{
if (enable) {
register_cpu_notifier(&cpu_hotplug_notifier);
on_each_cpu(enable_cp15_ben, NULL, true);
} else {
unregister_cpu_notifier(&cpu_hotplug_notifier);
on_each_cpu(disable_cp15_ben, NULL, true);
}
return true;
}
static int __init armv8_deprecated_init(void)
{
if (IS_ENABLED(CONFIG_SWP_EMULATION))
register_insn_emulation(&swp_ops);
if (IS_ENABLED(CONFIG_CP15_BARRIER_EMULATION))
register_insn_emulation(&cp15_barrier_ops);
register_insn_emulation_sysctl(ctl_abi);
return 0;
}
