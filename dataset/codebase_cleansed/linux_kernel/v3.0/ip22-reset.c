static void __noreturn sgi_machine_power_off(void)
{
unsigned int tmp;
local_irq_disable();
tmp = hpc3c0->rtcregs[RTC_CMD] & 0xff;
hpc3c0->rtcregs[RTC_CMD] = tmp | RTC_WAM;
hpc3c0->rtcregs[RTC_WSEC] = 0;
hpc3c0->rtcregs[RTC_WHSEC] = 0;
while (1) {
sgioc->panel = ~SGIOC_PANEL_POWERON;
tmp = hpc3c0->rtcregs[RTC_HOURS_ALARM];
}
}
static void __noreturn sgi_machine_restart(char *command)
{
if (machine_state & MACHINE_SHUTTING_DOWN)
sgi_machine_power_off();
sgimc->cpuctrl0 |= SGIMC_CCTRL0_SYSINIT;
while (1);
}
static void __noreturn sgi_machine_halt(void)
{
if (machine_state & MACHINE_SHUTTING_DOWN)
sgi_machine_power_off();
ArcEnterInteractiveMode();
}
static void power_timeout(unsigned long data)
{
sgi_machine_power_off();
}
static void blink_timeout(unsigned long data)
{
sgi_ioc_reset ^= (SGIOC_RESET_LC0OFF|SGIOC_RESET_LC1OFF);
sgioc->reset = sgi_ioc_reset;
mod_timer(&blink_timer, jiffies + data);
}
static void debounce(unsigned long data)
{
del_timer(&debounce_timer);
if (sgint->istat1 & SGINT_ISTAT1_PWR) {
debounce_timer.expires = jiffies + (HZ / 20);
add_timer(&debounce_timer);
sgioc->panel = SGIOC_PANEL_POWERON | SGIOC_PANEL_POWERINTR |
SGIOC_PANEL_VOLDNINTR | SGIOC_PANEL_VOLDNHOLD |
SGIOC_PANEL_VOLUPINTR | SGIOC_PANEL_VOLUPHOLD;
return;
}
if (machine_state & MACHINE_PANICED)
sgimc->cpuctrl0 |= SGIMC_CCTRL0_SYSINIT;
enable_irq(SGI_PANEL_IRQ);
}
static inline void power_button(void)
{
if (machine_state & MACHINE_PANICED)
return;
if ((machine_state & MACHINE_SHUTTING_DOWN) ||
kill_cad_pid(SIGINT, 1)) {
sgi_machine_power_off();
}
machine_state |= MACHINE_SHUTTING_DOWN;
blink_timer.data = POWERDOWN_FREQ;
blink_timeout(POWERDOWN_FREQ);
init_timer(&power_timer);
power_timer.function = power_timeout;
power_timer.expires = jiffies + POWERDOWN_TIMEOUT * HZ;
add_timer(&power_timer);
}
static irqreturn_t panel_int(int irq, void *dev_id)
{
unsigned int buttons;
buttons = sgioc->panel;
sgioc->panel = SGIOC_PANEL_POWERON | SGIOC_PANEL_POWERINTR;
if (sgint->istat1 & SGINT_ISTAT1_PWR) {
disable_irq_nosync(SGI_PANEL_IRQ);
init_timer(&debounce_timer);
debounce_timer.function = debounce;
debounce_timer.expires = jiffies + 5;
add_timer(&debounce_timer);
}
if (!(buttons & SGIOC_PANEL_POWERINTR))
power_button();
return IRQ_HANDLED;
}
static int panic_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
if (machine_state & MACHINE_PANICED)
return NOTIFY_DONE;
machine_state |= MACHINE_PANICED;
blink_timer.data = PANIC_FREQ;
blink_timeout(PANIC_FREQ);
return NOTIFY_DONE;
}
static int __init reboot_setup(void)
{
int res;
_machine_restart = sgi_machine_restart;
_machine_halt = sgi_machine_halt;
pm_power_off = sgi_machine_power_off;
res = request_irq(SGI_PANEL_IRQ, panel_int, 0, "Front Panel", NULL);
if (res) {
printk(KERN_ERR "Allocation of front panel IRQ failed\n");
return res;
}
init_timer(&blink_timer);
blink_timer.function = blink_timeout;
atomic_notifier_chain_register(&panic_notifier_list, &panic_block);
return 0;
}
