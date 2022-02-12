static void watchdog_trigger_immediate(void)
{
sh_wdt_write_cnt(0xFF);
sh_wdt_write_csr(0xC2);
}
static void native_machine_restart(char * __unused)
{
local_irq_disable();
__flush_tlb_global();
trigger_address_error();
#ifdef CONFIG_SUPERH32
watchdog_trigger_immediate();
#endif
while (1)
cpu_sleep();
}
static void native_machine_shutdown(void)
{
smp_send_stop();
}
static void native_machine_power_off(void)
{
if (pm_power_off)
pm_power_off();
}
static void native_machine_halt(void)
{
machine_shutdown();
stop_this_cpu(NULL);
}
void machine_power_off(void)
{
machine_ops.power_off();
}
void machine_shutdown(void)
{
machine_ops.shutdown();
}
void machine_restart(char *cmd)
{
machine_ops.restart(cmd);
}
void machine_halt(void)
{
machine_ops.halt();
}
void machine_crash_shutdown(struct pt_regs *regs)
{
machine_ops.crash_shutdown(regs);
}
