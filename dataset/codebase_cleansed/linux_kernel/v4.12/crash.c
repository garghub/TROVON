static int handle_fault(struct pt_regs *regs)
{
if (crash_shutdown_cpu == smp_processor_id())
longjmp(crash_shutdown_buf, 1);
return 0;
}
static void crash_ipi_callback(struct pt_regs *regs)
{
static cpumask_t cpus_state_saved = CPU_MASK_NONE;
int cpu = smp_processor_id();
if (!cpu_online(cpu))
return;
hard_irq_disable();
if (!cpumask_test_cpu(cpu, &cpus_state_saved)) {
crash_save_cpu(regs, cpu);
cpumask_set_cpu(cpu, &cpus_state_saved);
}
atomic_inc(&cpus_in_crash);
smp_mb__after_atomic();
while (!time_to_dump)
cpu_relax();
if (ppc_md.kexec_cpu_down)
ppc_md.kexec_cpu_down(1, 1);
#ifdef CONFIG_PPC64
kexec_smp_wait();
#else
for (;;);
#endif
}
static void crash_kexec_prepare_cpus(int cpu)
{
unsigned int msecs;
unsigned int ncpus = num_online_cpus() - 1;
int tries = 0;
int (*old_handler)(struct pt_regs *regs);
printk(KERN_EMERG "Sending IPI to other CPUs\n");
crash_send_ipi(crash_ipi_callback);
smp_wmb();
again:
msecs = IPI_TIMEOUT;
while ((atomic_read(&cpus_in_crash) < ncpus) && (--msecs > 0))
mdelay(1);
if (atomic_read(&cpus_in_crash) >= ncpus) {
printk(KERN_EMERG "IPI complete\n");
return;
}
printk(KERN_EMERG "ERROR: %d cpu(s) not responding\n",
ncpus - atomic_read(&cpus_in_crash));
if ((panic_timeout > 0) || (tries > 0))
return;
old_handler = __debugger;
__debugger = handle_fault;
crash_shutdown_cpu = smp_processor_id();
if (setjmp(crash_shutdown_buf) == 0) {
printk(KERN_EMERG "Activate system reset (dumprestart) "
"to stop other cpu(s)\n");
atomic_set(&cpus_in_crash, 0);
smp_mb();
while (atomic_read(&cpus_in_crash) < ncpus)
cpu_relax();
}
crash_shutdown_cpu = -1;
__debugger = old_handler;
tries++;
goto again;
}
void crash_kexec_secondary(struct pt_regs *regs)
{
unsigned long flags;
int msecs = SECONDARY_TIMEOUT;
local_irq_save(flags);
while (crashing_cpu < 0) {
if (--msecs < 0) {
local_irq_restore(flags);
return;
}
mdelay(1);
}
crash_ipi_callback(regs);
}
static void crash_kexec_prepare_cpus(int cpu)
{
#ifdef CONFIG_PPC64
smp_release_cpus();
#else
#endif
}
void crash_kexec_secondary(struct pt_regs *regs)
{
}
static void __maybe_unused crash_kexec_wait_realmode(int cpu)
{
unsigned int msecs;
int i;
msecs = REAL_MODE_TIMEOUT;
for (i=0; i < nr_cpu_ids && msecs > 0; i++) {
if (i == cpu)
continue;
while (paca[i].kexec_state < KEXEC_STATE_REAL_MODE) {
barrier();
if (!cpu_possible(i) || !cpu_online(i) || (msecs <= 0))
break;
msecs--;
mdelay(1);
}
}
mb();
}
static inline void crash_kexec_wait_realmode(int cpu) {}
int crash_shutdown_register(crash_shutdown_t handler)
{
unsigned int i, rc;
spin_lock(&crash_handlers_lock);
for (i = 0 ; i < CRASH_HANDLER_MAX; i++)
if (!crash_shutdown_handles[i]) {
crash_shutdown_handles[i] = handler;
rc = 0;
break;
}
if (i == CRASH_HANDLER_MAX) {
printk(KERN_ERR "Crash shutdown handles full, "
"not registered.\n");
rc = 1;
}
spin_unlock(&crash_handlers_lock);
return rc;
}
int crash_shutdown_unregister(crash_shutdown_t handler)
{
unsigned int i, rc;
spin_lock(&crash_handlers_lock);
for (i = 0 ; i < CRASH_HANDLER_MAX; i++)
if (crash_shutdown_handles[i] == handler)
break;
if (i == CRASH_HANDLER_MAX) {
printk(KERN_ERR "Crash shutdown handle not found\n");
rc = 1;
} else {
for (; i < (CRASH_HANDLER_MAX - 1); i++)
crash_shutdown_handles[i] =
crash_shutdown_handles[i+1];
crash_shutdown_handles[i] = NULL;
rc = 0;
}
spin_unlock(&crash_handlers_lock);
return rc;
}
void default_machine_crash_shutdown(struct pt_regs *regs)
{
unsigned int i;
int (*old_handler)(struct pt_regs *regs);
hard_irq_disable();
crashing_cpu = smp_processor_id();
if (TRAP(regs) == 0x100)
mdelay(PRIMARY_TIMEOUT);
crash_kexec_prepare_cpus(crashing_cpu);
crash_save_cpu(regs, crashing_cpu);
time_to_dump = 1;
crash_kexec_wait_realmode(crashing_cpu);
machine_kexec_mask_interrupts();
old_handler = __debugger_fault_handler;
__debugger_fault_handler = handle_fault;
crash_shutdown_cpu = smp_processor_id();
for (i = 0; i < CRASH_HANDLER_MAX && crash_shutdown_handles[i]; i++) {
if (setjmp(crash_shutdown_buf) == 0) {
asm volatile("sync; isync");
crash_shutdown_handles[i]();
asm volatile("sync; isync");
}
}
crash_shutdown_cpu = -1;
__debugger_fault_handler = old_handler;
if (ppc_md.kexec_cpu_down)
ppc_md.kexec_cpu_down(1, 0);
}
