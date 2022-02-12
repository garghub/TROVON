u8 debug_monitors_arch(void)
{
return cpuid_feature_extract_unsigned_field(read_sanitised_ftr_reg(SYS_ID_AA64DFR0_EL1),
ID_AA64DFR0_DEBUGVER_SHIFT);
}
static void mdscr_write(u32 mdscr)
{
unsigned long flags;
local_dbg_save(flags);
write_sysreg(mdscr, mdscr_el1);
local_dbg_restore(flags);
}
static u32 mdscr_read(void)
{
return read_sysreg(mdscr_el1);
}
static int create_debug_debugfs_entry(void)
{
debugfs_create_bool("debug_enabled", 0644, NULL, &debug_enabled);
return 0;
}
static int __init early_debug_disable(char *buf)
{
debug_enabled = false;
return 0;
}
void enable_debug_monitors(enum dbg_active_el el)
{
u32 mdscr, enable = 0;
WARN_ON(preemptible());
if (this_cpu_inc_return(mde_ref_count) == 1)
enable = DBG_MDSCR_MDE;
if (el == DBG_ACTIVE_EL1 &&
this_cpu_inc_return(kde_ref_count) == 1)
enable |= DBG_MDSCR_KDE;
if (enable && debug_enabled) {
mdscr = mdscr_read();
mdscr |= enable;
mdscr_write(mdscr);
}
}
void disable_debug_monitors(enum dbg_active_el el)
{
u32 mdscr, disable = 0;
WARN_ON(preemptible());
if (this_cpu_dec_return(mde_ref_count) == 0)
disable = ~DBG_MDSCR_MDE;
if (el == DBG_ACTIVE_EL1 &&
this_cpu_dec_return(kde_ref_count) == 0)
disable &= ~DBG_MDSCR_KDE;
if (disable) {
mdscr = mdscr_read();
mdscr &= disable;
mdscr_write(mdscr);
}
}
static int clear_os_lock(unsigned int cpu)
{
write_sysreg(0, oslar_el1);
isb();
return 0;
}
static int debug_monitors_init(void)
{
return cpuhp_setup_state(CPUHP_AP_ARM64_DEBUG_MONITORS_STARTING,
"arm64/debug_monitors:starting",
clear_os_lock, NULL);
}
static void set_regs_spsr_ss(struct pt_regs *regs)
{
regs->pstate |= DBG_SPSR_SS;
}
static void clear_regs_spsr_ss(struct pt_regs *regs)
{
regs->pstate &= ~DBG_SPSR_SS;
}
void register_step_hook(struct step_hook *hook)
{
spin_lock(&step_hook_lock);
list_add_rcu(&hook->node, &step_hook);
spin_unlock(&step_hook_lock);
}
void unregister_step_hook(struct step_hook *hook)
{
spin_lock(&step_hook_lock);
list_del_rcu(&hook->node);
spin_unlock(&step_hook_lock);
synchronize_rcu();
}
static int call_step_hook(struct pt_regs *regs, unsigned int esr)
{
struct step_hook *hook;
int retval = DBG_HOOK_ERROR;
rcu_read_lock();
list_for_each_entry_rcu(hook, &step_hook, node) {
retval = hook->fn(regs, esr);
if (retval == DBG_HOOK_HANDLED)
break;
}
rcu_read_unlock();
return retval;
}
static void send_user_sigtrap(int si_code)
{
struct pt_regs *regs = current_pt_regs();
siginfo_t info = {
.si_signo = SIGTRAP,
.si_errno = 0,
.si_code = si_code,
.si_addr = (void __user *)instruction_pointer(regs),
};
if (WARN_ON(!user_mode(regs)))
return;
if (interrupts_enabled(regs))
local_irq_enable();
force_sig_info(SIGTRAP, &info, current);
}
static int single_step_handler(unsigned long addr, unsigned int esr,
struct pt_regs *regs)
{
bool handler_found = false;
if (!reinstall_suspended_bps(regs))
return 0;
#ifdef CONFIG_KPROBES
if (kprobe_single_step_handler(regs, esr) == DBG_HOOK_HANDLED)
handler_found = true;
#endif
if (!handler_found && call_step_hook(regs, esr) == DBG_HOOK_HANDLED)
handler_found = true;
if (!handler_found && user_mode(regs)) {
send_user_sigtrap(TRAP_TRACE);
user_rewind_single_step(current);
} else if (!handler_found) {
pr_warn("Unexpected kernel single-step exception at EL1\n");
set_regs_spsr_ss(regs);
}
return 0;
}
void register_break_hook(struct break_hook *hook)
{
spin_lock(&break_hook_lock);
list_add_rcu(&hook->node, &break_hook);
spin_unlock(&break_hook_lock);
}
void unregister_break_hook(struct break_hook *hook)
{
spin_lock(&break_hook_lock);
list_del_rcu(&hook->node);
spin_unlock(&break_hook_lock);
synchronize_rcu();
}
static int call_break_hook(struct pt_regs *regs, unsigned int esr)
{
struct break_hook *hook;
int (*fn)(struct pt_regs *regs, unsigned int esr) = NULL;
rcu_read_lock();
list_for_each_entry_rcu(hook, &break_hook, node)
if ((esr & hook->esr_mask) == hook->esr_val)
fn = hook->fn;
rcu_read_unlock();
return fn ? fn(regs, esr) : DBG_HOOK_ERROR;
}
static int brk_handler(unsigned long addr, unsigned int esr,
struct pt_regs *regs)
{
bool handler_found = false;
#ifdef CONFIG_KPROBES
if ((esr & BRK64_ESR_MASK) == BRK64_ESR_KPROBES) {
if (kprobe_breakpoint_handler(regs, esr) == DBG_HOOK_HANDLED)
handler_found = true;
}
#endif
if (!handler_found && call_break_hook(regs, esr) == DBG_HOOK_HANDLED)
handler_found = true;
if (!handler_found && user_mode(regs)) {
send_user_sigtrap(TRAP_BRKPT);
} else if (!handler_found) {
pr_warn("Unexpected kernel BRK exception at EL1\n");
return -EFAULT;
}
return 0;
}
int aarch32_break_handler(struct pt_regs *regs)
{
u32 arm_instr;
u16 thumb_instr;
bool bp = false;
void __user *pc = (void __user *)instruction_pointer(regs);
if (!compat_user_mode(regs))
return -EFAULT;
if (compat_thumb_mode(regs)) {
__le16 instr;
get_user(instr, (__le16 __user *)pc);
thumb_instr = le16_to_cpu(instr);
if (thumb_instr == AARCH32_BREAK_THUMB2_LO) {
get_user(instr, (__le16 __user *)(pc + 2));
thumb_instr = le16_to_cpu(instr);
bp = thumb_instr == AARCH32_BREAK_THUMB2_HI;
} else {
bp = thumb_instr == AARCH32_BREAK_THUMB;
}
} else {
__le32 instr;
get_user(instr, (__le32 __user *)pc);
arm_instr = le32_to_cpu(instr);
bp = (arm_instr & ~0xf0000000) == AARCH32_BREAK_ARM;
}
if (!bp)
return -EFAULT;
send_user_sigtrap(TRAP_BRKPT);
return 0;
}
static int __init debug_traps_init(void)
{
hook_debug_fault_code(DBG_ESR_EVT_HWSS, single_step_handler, SIGTRAP,
TRAP_TRACE, "single-step handler");
hook_debug_fault_code(DBG_ESR_EVT_BRK, brk_handler, SIGTRAP,
TRAP_BRKPT, "ptrace BRK handler");
return 0;
}
void user_rewind_single_step(struct task_struct *task)
{
if (test_ti_thread_flag(task_thread_info(task), TIF_SINGLESTEP))
set_regs_spsr_ss(task_pt_regs(task));
}
void user_fastforward_single_step(struct task_struct *task)
{
if (test_ti_thread_flag(task_thread_info(task), TIF_SINGLESTEP))
clear_regs_spsr_ss(task_pt_regs(task));
}
void kernel_enable_single_step(struct pt_regs *regs)
{
WARN_ON(!irqs_disabled());
set_regs_spsr_ss(regs);
mdscr_write(mdscr_read() | DBG_MDSCR_SS);
enable_debug_monitors(DBG_ACTIVE_EL1);
}
void kernel_disable_single_step(void)
{
WARN_ON(!irqs_disabled());
mdscr_write(mdscr_read() & ~DBG_MDSCR_SS);
disable_debug_monitors(DBG_ACTIVE_EL1);
}
int kernel_active_single_step(void)
{
WARN_ON(!irqs_disabled());
return mdscr_read() & DBG_MDSCR_SS;
}
void user_enable_single_step(struct task_struct *task)
{
struct thread_info *ti = task_thread_info(task);
if (!test_and_set_ti_thread_flag(ti, TIF_SINGLESTEP))
set_regs_spsr_ss(task_pt_regs(task));
}
void user_disable_single_step(struct task_struct *task)
{
clear_ti_thread_flag(task_thread_info(task), TIF_SINGLESTEP);
}
