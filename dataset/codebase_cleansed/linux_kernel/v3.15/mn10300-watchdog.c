int __init check_watchdog(void)
{
irq_cpustat_t tmp[1];
printk(KERN_INFO "Testing Watchdog... ");
memcpy(tmp, irq_stat, sizeof(tmp));
local_irq_enable();
mdelay((10 * 1000) / watchdog_hz);
local_irq_disable();
if (nmi_count(0) - tmp[0].__nmi_count <= 5) {
printk(KERN_WARNING "CPU#%d: Watchdog appears to be stuck!\n",
0);
return -1;
}
printk(KERN_INFO "OK.\n");
watchdog_hz = 1;
return 0;
}
static int __init setup_watchdog(char *str)
{
unsigned tmp;
int opt;
u8 ctr;
get_option(&str, &opt);
if (opt != 1)
return 0;
watchdog = opt;
if (watchdog) {
set_intr_stub(EXCEP_WDT, watchdog_handler);
ctr = WDCTR_WDCK_65536th;
WDCTR = WDCTR_WDRST | ctr;
WDCTR = ctr;
tmp = WDCTR;
tmp = __muldiv64u(1 << (16 + ctr * 2), 1000000, MN10300_WDCLK);
tmp = 1000000000 / tmp;
watchdog_hz = (tmp + 500) / 1000;
}
return 1;
}
void __init watchdog_go(void)
{
u8 wdt;
if (watchdog) {
printk(KERN_INFO "Watchdog: running at %uHz\n", watchdog_hz);
wdt = WDCTR & ~WDCTR_WDCNE;
WDCTR = wdt | WDCTR_WDRST;
wdt = WDCTR;
WDCTR = wdt | WDCTR_WDCNE;
wdt = WDCTR;
check_watchdog();
}
}
static void watchdog_dump_register(void *dummy)
{
printk(KERN_ERR "--- Register Dump (CPU%d) ---\n", CPUID);
show_registers(current_frame());
}
asmlinkage
void watchdog_interrupt(struct pt_regs *regs, enum exception_code excep)
{
int sum, cpu;
int irq = NMIIRQ;
u8 wdt, tmp;
wdt = WDCTR & ~WDCTR_WDCNE;
WDCTR = wdt;
tmp = WDCTR;
NMICR = NMICR_WDIF;
nmi_count(smp_processor_id())++;
kstat_incr_irq_this_cpu(irq);
for_each_online_cpu(cpu) {
sum = irq_stat[cpu].__irq_count;
if ((last_irq_sums[cpu] == sum)
#if defined(CONFIG_GDBSTUB) && defined(CONFIG_SMP)
&& !(CHK_GDBSTUB_BUSY()
|| atomic_read(&cpu_doing_single_step))
#endif
) {
watchdog_alert_counter[cpu]++;
if (watchdog_alert_counter[cpu] == 5 * watchdog_hz) {
spin_lock(&watchdog_print_lock);
bust_spinlocks(1);
printk(KERN_ERR
"NMI Watchdog detected LOCKUP on CPU%d,"
" pc %08lx, registers:\n",
cpu, regs->pc);
#ifdef CONFIG_SMP
printk(KERN_ERR
"--- Register Dump (CPU%d) ---\n",
CPUID);
#endif
show_registers(regs);
#ifdef CONFIG_SMP
smp_nmi_call_function(watchdog_dump_register,
NULL, 1);
#endif
printk(KERN_NOTICE "console shuts up ...\n");
console_silent();
spin_unlock(&watchdog_print_lock);
bust_spinlocks(0);
#ifdef CONFIG_GDBSTUB
if (CHK_GDBSTUB_BUSY_AND_ACTIVE())
gdbstub_exception(regs, excep);
else
gdbstub_intercept(regs, excep);
#endif
do_exit(SIGSEGV);
}
} else {
last_irq_sums[cpu] = sum;
watchdog_alert_counter[cpu] = 0;
}
}
WDCTR = wdt | WDCTR_WDRST;
tmp = WDCTR;
WDCTR = wdt | WDCTR_WDCNE;
tmp = WDCTR;
}
