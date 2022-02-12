u8 debug_monitors_arch(void)
{
return read_cpuid(ID_AA64DFR0_EL1) & 0xf;
}
static void mdscr_write(u32 mdscr)
{
unsigned long flags;
local_dbg_save(flags);
asm volatile("msr mdscr_el1, %0" :: "r" (mdscr));
local_dbg_restore(flags);
}
static u32 mdscr_read(void)
{
u32 mdscr;
asm volatile("mrs %0, mdscr_el1" : "=r" (mdscr));
return mdscr;
}
static int create_debug_debugfs_entry(void)
{
debugfs_create_bool("debug_enabled", 0644, NULL, &debug_enabled);
return 0;
}
static int __init early_debug_disable(char *buf)
{
debug_enabled = 0;
return 0;
}
void enable_debug_monitors(enum debug_el el)
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
void disable_debug_monitors(enum debug_el el)
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
static void clear_os_lock(void *unused)
{
asm volatile("msr oslar_el1, %0" : : "r" (0));
isb();
}
static int os_lock_notify(struct notifier_block *self,
unsigned long action, void *data)
{
int cpu = (unsigned long)data;
if (action == CPU_ONLINE)
smp_call_function_single(cpu, clear_os_lock, NULL, 1);
return NOTIFY_OK;
}
static int debug_monitors_init(void)
{
smp_call_function(clear_os_lock, NULL, 1);
clear_os_lock(NULL);
register_cpu_notifier(&os_lock_nb);
return 0;
}
static void set_regs_spsr_ss(struct pt_regs *regs)
{
unsigned long spsr;
spsr = regs->pstate;
spsr &= ~DBG_SPSR_SS;
spsr |= DBG_SPSR_SS;
regs->pstate = spsr;
}
static void clear_regs_spsr_ss(struct pt_regs *regs)
{
unsigned long spsr;
spsr = regs->pstate;
spsr &= ~DBG_SPSR_SS;
regs->pstate = spsr;
}
void register_step_hook(struct step_hook *hook)
{
write_lock(&step_hook_lock);
list_add(&hook->node, &step_hook);
write_unlock(&step_hook_lock);
}
void unregister_step_hook(struct step_hook *hook)
{
write_lock(&step_hook_lock);
list_del(&hook->node);
write_unlock(&step_hook_lock);
}
static int call_step_hook(struct pt_regs *regs, unsigned int esr)
{
struct step_hook *hook;
int retval = DBG_HOOK_ERROR;
read_lock(&step_hook_lock);
list_for_each_entry(hook, &step_hook, node) {
retval = hook->fn(regs, esr);
if (retval == DBG_HOOK_HANDLED)
break;
}
read_unlock(&step_hook_lock);
return retval;
}
static int single_step_handler(unsigned long addr, unsigned int esr,
struct pt_regs *regs)
{
siginfo_t info;
if (!reinstall_suspended_bps(regs))
return 0;
if (user_mode(regs)) {
info.si_signo = SIGTRAP;
info.si_errno = 0;
info.si_code = TRAP_HWBKPT;
info.si_addr = (void __user *)instruction_pointer(regs);
force_sig_info(SIGTRAP, &info, current);
user_rewind_single_step(current);
} else {
if (call_step_hook(regs, esr) == DBG_HOOK_HANDLED)
return 0;
pr_warning("Unexpected kernel single-step exception at EL1\n");
set_regs_spsr_ss(regs);
}
return 0;
}
void register_break_hook(struct break_hook *hook)
{
write_lock(&break_hook_lock);
list_add(&hook->node, &break_hook);
write_unlock(&break_hook_lock);
}
void unregister_break_hook(struct break_hook *hook)
{
write_lock(&break_hook_lock);
list_del(&hook->node);
write_unlock(&break_hook_lock);
}
static int call_break_hook(struct pt_regs *regs, unsigned int esr)
{
struct break_hook *hook;
int (*fn)(struct pt_regs *regs, unsigned int esr) = NULL;
read_lock(&break_hook_lock);
list_for_each_entry(hook, &break_hook, node)
if ((esr & hook->esr_mask) == hook->esr_val)
fn = hook->fn;
read_unlock(&break_hook_lock);
return fn ? fn(regs, esr) : DBG_HOOK_ERROR;
}
static int brk_handler(unsigned long addr, unsigned int esr,
struct pt_regs *regs)
{
siginfo_t info;
if (call_break_hook(regs, esr) == DBG_HOOK_HANDLED)
return 0;
pr_warn("unexpected brk exception at %lx, esr=0x%x\n",
(long)instruction_pointer(regs), esr);
if (!user_mode(regs))
return -EFAULT;
info = (siginfo_t) {
.si_signo = SIGTRAP,
.si_errno = 0,
.si_code = TRAP_BRKPT,
.si_addr = (void __user *)instruction_pointer(regs),
};
force_sig_info(SIGTRAP, &info, current);
return 0;
}
int aarch32_break_handler(struct pt_regs *regs)
{
siginfo_t info;
u32 arm_instr;
u16 thumb_instr;
bool bp = false;
void __user *pc = (void __user *)instruction_pointer(regs);
if (!compat_user_mode(regs))
return -EFAULT;
if (compat_thumb_mode(regs)) {
get_user(thumb_instr, (u16 __user *)pc);
thumb_instr = le16_to_cpu(thumb_instr);
if (thumb_instr == AARCH32_BREAK_THUMB2_LO) {
get_user(thumb_instr, (u16 __user *)(pc + 2));
thumb_instr = le16_to_cpu(thumb_instr);
bp = thumb_instr == AARCH32_BREAK_THUMB2_HI;
} else {
bp = thumb_instr == AARCH32_BREAK_THUMB;
}
} else {
get_user(arm_instr, (u32 __user *)pc);
arm_instr = le32_to_cpu(arm_instr);
bp = (arm_instr & ~0xf0000000) == AARCH32_BREAK_ARM;
}
if (!bp)
return -EFAULT;
info = (siginfo_t) {
.si_signo = SIGTRAP,
.si_errno = 0,
.si_code = TRAP_BRKPT,
.si_addr = pc,
};
force_sig_info(SIGTRAP, &info, current);
return 0;
}
static int __init debug_traps_init(void)
{
hook_debug_fault_code(DBG_ESR_EVT_HWSS, single_step_handler, SIGTRAP,
TRAP_HWBKPT, "single-step handler");
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
set_ti_thread_flag(task_thread_info(task), TIF_SINGLESTEP);
set_regs_spsr_ss(task_pt_regs(task));
}
void user_disable_single_step(struct task_struct *task)
{
clear_ti_thread_flag(task_thread_info(task), TIF_SINGLESTEP);
}
