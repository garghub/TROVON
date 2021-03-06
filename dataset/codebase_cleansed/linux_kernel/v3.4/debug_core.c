static int __init opt_kgdb_con(char *str)
{
kgdb_use_con = 1;
return 0;
}
static int __init opt_nokgdbroundup(char *str)
{
kgdb_do_roundup = 0;
return 0;
}
int __weak kgdb_arch_set_breakpoint(struct kgdb_bkpt *bpt)
{
int err;
err = probe_kernel_read(bpt->saved_instr, (char *)bpt->bpt_addr,
BREAK_INSTR_SIZE);
if (err)
return err;
err = probe_kernel_write((char *)bpt->bpt_addr,
arch_kgdb_ops.gdb_bpt_instr, BREAK_INSTR_SIZE);
return err;
}
int __weak kgdb_arch_remove_breakpoint(struct kgdb_bkpt *bpt)
{
return probe_kernel_write((char *)bpt->bpt_addr,
(char *)bpt->saved_instr, BREAK_INSTR_SIZE);
}
int __weak kgdb_validate_break_address(unsigned long addr)
{
struct kgdb_bkpt tmp;
int err;
tmp.bpt_addr = addr;
err = kgdb_arch_set_breakpoint(&tmp);
if (err)
return err;
err = kgdb_arch_remove_breakpoint(&tmp);
if (err)
printk(KERN_ERR "KGDB: Critical breakpoint error, kernel "
"memory destroyed at: %lx", addr);
return err;
}
unsigned long __weak kgdb_arch_pc(int exception, struct pt_regs *regs)
{
return instruction_pointer(regs);
}
int __weak kgdb_arch_init(void)
{
return 0;
}
int __weak kgdb_skipexception(int exception, struct pt_regs *regs)
{
return 0;
}
static void kgdb_flush_swbreak_addr(unsigned long addr)
{
if (!CACHE_FLUSH_IS_SAFE)
return;
if (current->mm && current->mm->mmap_cache) {
flush_cache_range(current->mm->mmap_cache,
addr, addr + BREAK_INSTR_SIZE);
}
flush_icache_range(addr, addr + BREAK_INSTR_SIZE);
}
int dbg_activate_sw_breakpoints(void)
{
int error;
int ret = 0;
int i;
for (i = 0; i < KGDB_MAX_BREAKPOINTS; i++) {
if (kgdb_break[i].state != BP_SET)
continue;
error = kgdb_arch_set_breakpoint(&kgdb_break[i]);
if (error) {
ret = error;
printk(KERN_INFO "KGDB: BP install failed: %lx",
kgdb_break[i].bpt_addr);
continue;
}
kgdb_flush_swbreak_addr(kgdb_break[i].bpt_addr);
kgdb_break[i].state = BP_ACTIVE;
}
return ret;
}
int dbg_set_sw_break(unsigned long addr)
{
int err = kgdb_validate_break_address(addr);
int breakno = -1;
int i;
if (err)
return err;
for (i = 0; i < KGDB_MAX_BREAKPOINTS; i++) {
if ((kgdb_break[i].state == BP_SET) &&
(kgdb_break[i].bpt_addr == addr))
return -EEXIST;
}
for (i = 0; i < KGDB_MAX_BREAKPOINTS; i++) {
if (kgdb_break[i].state == BP_REMOVED &&
kgdb_break[i].bpt_addr == addr) {
breakno = i;
break;
}
}
if (breakno == -1) {
for (i = 0; i < KGDB_MAX_BREAKPOINTS; i++) {
if (kgdb_break[i].state == BP_UNDEFINED) {
breakno = i;
break;
}
}
}
if (breakno == -1)
return -E2BIG;
kgdb_break[breakno].state = BP_SET;
kgdb_break[breakno].type = BP_BREAKPOINT;
kgdb_break[breakno].bpt_addr = addr;
return 0;
}
int dbg_deactivate_sw_breakpoints(void)
{
int error;
int ret = 0;
int i;
for (i = 0; i < KGDB_MAX_BREAKPOINTS; i++) {
if (kgdb_break[i].state != BP_ACTIVE)
continue;
error = kgdb_arch_remove_breakpoint(&kgdb_break[i]);
if (error) {
printk(KERN_INFO "KGDB: BP remove failed: %lx\n",
kgdb_break[i].bpt_addr);
ret = error;
}
kgdb_flush_swbreak_addr(kgdb_break[i].bpt_addr);
kgdb_break[i].state = BP_SET;
}
return ret;
}
int dbg_remove_sw_break(unsigned long addr)
{
int i;
for (i = 0; i < KGDB_MAX_BREAKPOINTS; i++) {
if ((kgdb_break[i].state == BP_SET) &&
(kgdb_break[i].bpt_addr == addr)) {
kgdb_break[i].state = BP_REMOVED;
return 0;
}
}
return -ENOENT;
}
int kgdb_isremovedbreak(unsigned long addr)
{
int i;
for (i = 0; i < KGDB_MAX_BREAKPOINTS; i++) {
if ((kgdb_break[i].state == BP_REMOVED) &&
(kgdb_break[i].bpt_addr == addr))
return 1;
}
return 0;
}
int dbg_remove_all_break(void)
{
int error;
int i;
for (i = 0; i < KGDB_MAX_BREAKPOINTS; i++) {
if (kgdb_break[i].state != BP_ACTIVE)
goto setundefined;
error = kgdb_arch_remove_breakpoint(&kgdb_break[i]);
if (error)
printk(KERN_ERR "KGDB: breakpoint remove failed: %lx\n",
kgdb_break[i].bpt_addr);
setundefined:
kgdb_break[i].state = BP_UNDEFINED;
}
if (arch_kgdb_ops.remove_all_hw_break)
arch_kgdb_ops.remove_all_hw_break();
return 0;
}
static int kgdb_io_ready(int print_wait)
{
if (!dbg_io_ops)
return 0;
if (kgdb_connected)
return 1;
if (atomic_read(&kgdb_setting_breakpoint))
return 1;
if (print_wait) {
#ifdef CONFIG_KGDB_KDB
if (!dbg_kdb_mode)
printk(KERN_CRIT "KGDB: waiting... or $3#33 for KDB\n");
#else
printk(KERN_CRIT "KGDB: Waiting for remote debugger\n");
#endif
}
return 1;
}
static int kgdb_reenter_check(struct kgdb_state *ks)
{
unsigned long addr;
if (atomic_read(&kgdb_active) != raw_smp_processor_id())
return 0;
exception_level++;
addr = kgdb_arch_pc(ks->ex_vector, ks->linux_regs);
dbg_deactivate_sw_breakpoints();
if (dbg_remove_sw_break(addr) == 0) {
exception_level = 0;
kgdb_skipexception(ks->ex_vector, ks->linux_regs);
dbg_activate_sw_breakpoints();
printk(KERN_CRIT "KGDB: re-enter error: breakpoint removed %lx\n",
addr);
WARN_ON_ONCE(1);
return 1;
}
dbg_remove_all_break();
kgdb_skipexception(ks->ex_vector, ks->linux_regs);
if (exception_level > 1) {
dump_stack();
panic("Recursive entry to debugger");
}
printk(KERN_CRIT "KGDB: re-enter exception: ALL breakpoints killed\n");
#ifdef CONFIG_KGDB_KDB
return 0;
#endif
dump_stack();
panic("Recursive entry to debugger");
return 1;
}
static void dbg_touch_watchdogs(void)
{
touch_softlockup_watchdog_sync();
clocksource_touch_watchdog();
rcu_cpu_stall_reset();
}
static int kgdb_cpu_enter(struct kgdb_state *ks, struct pt_regs *regs,
int exception_state)
{
unsigned long flags;
int sstep_tries = 100;
int error;
int cpu;
int trace_on = 0;
int online_cpus = num_online_cpus();
kgdb_info[ks->cpu].enter_kgdb++;
kgdb_info[ks->cpu].exception_state |= exception_state;
if (exception_state == DCPU_WANT_MASTER)
atomic_inc(&masters_in_kgdb);
else
atomic_inc(&slaves_in_kgdb);
if (arch_kgdb_ops.disable_hw_break)
arch_kgdb_ops.disable_hw_break(regs);
acquirelock:
local_irq_save(flags);
cpu = ks->cpu;
kgdb_info[cpu].debuggerinfo = regs;
kgdb_info[cpu].task = current;
kgdb_info[cpu].ret_state = 0;
kgdb_info[cpu].irq_depth = hardirq_count() >> HARDIRQ_SHIFT;
smp_mb();
if (exception_level == 1) {
if (raw_spin_trylock(&dbg_master_lock))
atomic_xchg(&kgdb_active, cpu);
goto cpu_master_loop;
}
while (1) {
cpu_loop:
if (kgdb_info[cpu].exception_state & DCPU_NEXT_MASTER) {
kgdb_info[cpu].exception_state &= ~DCPU_NEXT_MASTER;
goto cpu_master_loop;
} else if (kgdb_info[cpu].exception_state & DCPU_WANT_MASTER) {
if (raw_spin_trylock(&dbg_master_lock)) {
atomic_xchg(&kgdb_active, cpu);
break;
}
} else if (kgdb_info[cpu].exception_state & DCPU_IS_SLAVE) {
if (!raw_spin_is_locked(&dbg_slave_lock))
goto return_normal;
} else {
return_normal:
if (arch_kgdb_ops.correct_hw_break)
arch_kgdb_ops.correct_hw_break();
if (trace_on)
tracing_on();
kgdb_info[cpu].exception_state &=
~(DCPU_WANT_MASTER | DCPU_IS_SLAVE);
kgdb_info[cpu].enter_kgdb--;
smp_mb__before_atomic_dec();
atomic_dec(&slaves_in_kgdb);
dbg_touch_watchdogs();
local_irq_restore(flags);
return 0;
}
cpu_relax();
}
if (atomic_read(&kgdb_cpu_doing_single_step) != -1 &&
(kgdb_info[cpu].task &&
kgdb_info[cpu].task->pid != kgdb_sstep_pid) && --sstep_tries) {
atomic_set(&kgdb_active, -1);
raw_spin_unlock(&dbg_master_lock);
dbg_touch_watchdogs();
local_irq_restore(flags);
goto acquirelock;
}
if (!kgdb_io_ready(1)) {
kgdb_info[cpu].ret_state = 1;
goto kgdb_restore;
}
if (kgdb_skipexception(ks->ex_vector, ks->linux_regs))
goto kgdb_restore;
if (dbg_io_ops->pre_exception)
dbg_io_ops->pre_exception();
if (!kgdb_single_step)
raw_spin_lock(&dbg_slave_lock);
#ifdef CONFIG_SMP
if ((!kgdb_single_step) && kgdb_do_roundup)
kgdb_roundup_cpus(flags);
#endif
while (kgdb_do_roundup && (atomic_read(&masters_in_kgdb) +
atomic_read(&slaves_in_kgdb)) != online_cpus)
cpu_relax();
dbg_deactivate_sw_breakpoints();
kgdb_single_step = 0;
kgdb_contthread = current;
exception_level = 0;
trace_on = tracing_is_on();
if (trace_on)
tracing_off();
while (1) {
cpu_master_loop:
if (dbg_kdb_mode) {
kgdb_connected = 1;
error = kdb_stub(ks);
if (error == -1)
continue;
kgdb_connected = 0;
} else {
error = gdb_serial_stub(ks);
}
if (error == DBG_PASS_EVENT) {
dbg_kdb_mode = !dbg_kdb_mode;
} else if (error == DBG_SWITCH_CPU_EVENT) {
kgdb_info[dbg_switch_cpu].exception_state |=
DCPU_NEXT_MASTER;
goto cpu_loop;
} else {
kgdb_info[cpu].ret_state = error;
break;
}
}
if (dbg_io_ops->post_exception)
dbg_io_ops->post_exception();
if (!kgdb_single_step) {
raw_spin_unlock(&dbg_slave_lock);
while (kgdb_do_roundup && atomic_read(&slaves_in_kgdb))
cpu_relax();
}
kgdb_restore:
if (atomic_read(&kgdb_cpu_doing_single_step) != -1) {
int sstep_cpu = atomic_read(&kgdb_cpu_doing_single_step);
if (kgdb_info[sstep_cpu].task)
kgdb_sstep_pid = kgdb_info[sstep_cpu].task->pid;
else
kgdb_sstep_pid = 0;
}
if (arch_kgdb_ops.correct_hw_break)
arch_kgdb_ops.correct_hw_break();
if (trace_on)
tracing_on();
kgdb_info[cpu].exception_state &=
~(DCPU_WANT_MASTER | DCPU_IS_SLAVE);
kgdb_info[cpu].enter_kgdb--;
smp_mb__before_atomic_dec();
atomic_dec(&masters_in_kgdb);
atomic_set(&kgdb_active, -1);
raw_spin_unlock(&dbg_master_lock);
dbg_touch_watchdogs();
local_irq_restore(flags);
return kgdb_info[cpu].ret_state;
}
int
kgdb_handle_exception(int evector, int signo, int ecode, struct pt_regs *regs)
{
struct kgdb_state kgdb_var;
struct kgdb_state *ks = &kgdb_var;
ks->cpu = raw_smp_processor_id();
ks->ex_vector = evector;
ks->signo = signo;
ks->err_code = ecode;
ks->kgdb_usethreadid = 0;
ks->linux_regs = regs;
if (kgdb_reenter_check(ks))
return 0;
if (kgdb_info[ks->cpu].enter_kgdb != 0)
return 0;
return kgdb_cpu_enter(ks, regs, DCPU_WANT_MASTER);
}
int kgdb_nmicallback(int cpu, void *regs)
{
#ifdef CONFIG_SMP
struct kgdb_state kgdb_var;
struct kgdb_state *ks = &kgdb_var;
memset(ks, 0, sizeof(struct kgdb_state));
ks->cpu = cpu;
ks->linux_regs = regs;
if (kgdb_info[ks->cpu].enter_kgdb == 0 &&
raw_spin_is_locked(&dbg_master_lock)) {
kgdb_cpu_enter(ks, regs, DCPU_IS_SLAVE);
return 0;
}
#endif
return 1;
}
static void kgdb_console_write(struct console *co, const char *s,
unsigned count)
{
unsigned long flags;
if (!kgdb_connected || atomic_read(&kgdb_active) != -1 || dbg_kdb_mode)
return;
local_irq_save(flags);
gdbstub_msg_write(s, count);
local_irq_restore(flags);
}
static void sysrq_handle_dbg(int key)
{
if (!dbg_io_ops) {
printk(KERN_CRIT "ERROR: No KGDB I/O module available\n");
return;
}
if (!kgdb_connected) {
#ifdef CONFIG_KGDB_KDB
if (!dbg_kdb_mode)
printk(KERN_CRIT "KGDB or $3#33 for KDB\n");
#else
printk(KERN_CRIT "Entering KGDB\n");
#endif
}
kgdb_breakpoint();
}
static int kgdb_panic_event(struct notifier_block *self,
unsigned long val,
void *data)
{
if (dbg_kdb_mode)
kdb_printf("PANIC: %s\n", (char *)data);
kgdb_breakpoint();
return NOTIFY_DONE;
}
void __weak kgdb_arch_late(void)
{
}
void __init dbg_late_init(void)
{
dbg_is_early = false;
if (kgdb_io_module_registered)
kgdb_arch_late();
kdb_init(KDB_INIT_FULL);
}
static int
dbg_notify_reboot(struct notifier_block *this, unsigned long code, void *x)
{
switch (kgdbreboot) {
case 1:
kgdb_breakpoint();
case -1:
goto done;
}
if (!dbg_kdb_mode)
gdbstub_exit(code);
done:
return NOTIFY_DONE;
}
static void kgdb_register_callbacks(void)
{
if (!kgdb_io_module_registered) {
kgdb_io_module_registered = 1;
kgdb_arch_init();
if (!dbg_is_early)
kgdb_arch_late();
register_reboot_notifier(&dbg_reboot_notifier);
atomic_notifier_chain_register(&panic_notifier_list,
&kgdb_panic_event_nb);
#ifdef CONFIG_MAGIC_SYSRQ
register_sysrq_key('g', &sysrq_dbg_op);
#endif
if (kgdb_use_con && !kgdb_con_registered) {
register_console(&kgdbcons);
kgdb_con_registered = 1;
}
}
}
static void kgdb_unregister_callbacks(void)
{
if (kgdb_io_module_registered) {
kgdb_io_module_registered = 0;
unregister_reboot_notifier(&dbg_reboot_notifier);
atomic_notifier_chain_unregister(&panic_notifier_list,
&kgdb_panic_event_nb);
kgdb_arch_exit();
#ifdef CONFIG_MAGIC_SYSRQ
unregister_sysrq_key('g', &sysrq_dbg_op);
#endif
if (kgdb_con_registered) {
unregister_console(&kgdbcons);
kgdb_con_registered = 0;
}
}
}
static void kgdb_tasklet_bpt(unsigned long ing)
{
kgdb_breakpoint();
atomic_set(&kgdb_break_tasklet_var, 0);
}
void kgdb_schedule_breakpoint(void)
{
if (atomic_read(&kgdb_break_tasklet_var) ||
atomic_read(&kgdb_active) != -1 ||
atomic_read(&kgdb_setting_breakpoint))
return;
atomic_inc(&kgdb_break_tasklet_var);
tasklet_schedule(&kgdb_tasklet_breakpoint);
}
static void kgdb_initial_breakpoint(void)
{
kgdb_break_asap = 0;
printk(KERN_CRIT "kgdb: Waiting for connection from remote gdb...\n");
kgdb_breakpoint();
}
int kgdb_register_io_module(struct kgdb_io *new_dbg_io_ops)
{
int err;
spin_lock(&kgdb_registration_lock);
if (dbg_io_ops) {
spin_unlock(&kgdb_registration_lock);
printk(KERN_ERR "kgdb: Another I/O driver is already "
"registered with KGDB.\n");
return -EBUSY;
}
if (new_dbg_io_ops->init) {
err = new_dbg_io_ops->init();
if (err) {
spin_unlock(&kgdb_registration_lock);
return err;
}
}
dbg_io_ops = new_dbg_io_ops;
spin_unlock(&kgdb_registration_lock);
printk(KERN_INFO "kgdb: Registered I/O driver %s.\n",
new_dbg_io_ops->name);
kgdb_register_callbacks();
if (kgdb_break_asap)
kgdb_initial_breakpoint();
return 0;
}
void kgdb_unregister_io_module(struct kgdb_io *old_dbg_io_ops)
{
BUG_ON(kgdb_connected);
kgdb_unregister_callbacks();
spin_lock(&kgdb_registration_lock);
WARN_ON_ONCE(dbg_io_ops != old_dbg_io_ops);
dbg_io_ops = NULL;
spin_unlock(&kgdb_registration_lock);
printk(KERN_INFO
"kgdb: Unregistered I/O driver %s, debugger disabled.\n",
old_dbg_io_ops->name);
}
int dbg_io_get_char(void)
{
int ret = dbg_io_ops->read_char();
if (ret == NO_POLL_CHAR)
return -1;
if (!dbg_kdb_mode)
return ret;
if (ret == 127)
return 8;
return ret;
}
void kgdb_breakpoint(void)
{
atomic_inc(&kgdb_setting_breakpoint);
wmb();
arch_kgdb_breakpoint();
wmb();
atomic_dec(&kgdb_setting_breakpoint);
}
static int __init opt_kgdb_wait(char *str)
{
kgdb_break_asap = 1;
kdb_init(KDB_INIT_EARLY);
if (kgdb_io_module_registered)
kgdb_initial_breakpoint();
return 0;
}
