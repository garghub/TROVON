static __noreturn void ip32_poweroff(void *data)
{
void (*poweroff_func)(struct platform_device *) =
symbol_get(ds1685_rtc_poweroff);
#ifdef CONFIG_MODULES
if (!poweroff_func) {
request_module("rtc-ds1685");
poweroff_func = symbol_get(ds1685_rtc_poweroff);
}
#endif
if (!poweroff_func)
pr_emerg("RTC not available for power-off. Spinning forever ...\n");
else {
(*poweroff_func)((struct platform_device *)data);
symbol_put(ds1685_rtc_poweroff);
}
unreachable();
}
static void ip32_machine_restart(char *cmd)
{
msleep(20);
crime->control = CRIME_CONTROL_HARD_RESET;
unreachable();
}
static void blink_timeout(unsigned long data)
{
unsigned long led = mace->perif.ctrl.misc ^ MACEISA_LED_RED;
mace->perif.ctrl.misc = led;
mod_timer(&blink_timer, jiffies + data);
}
static void ip32_machine_halt(void)
{
ip32_poweroff(&ip32_rtc_device);
}
static void power_timeout(unsigned long data)
{
ip32_poweroff(&ip32_rtc_device);
}
void ip32_prepare_poweroff(void)
{
if (has_panicked)
return;
if (shutting_down || kill_cad_pid(SIGINT, 1)) {
ip32_poweroff(&ip32_rtc_device);
}
shutting_down = 1;
blink_timer.data = POWERDOWN_FREQ;
blink_timeout(POWERDOWN_FREQ);
init_timer(&power_timer);
power_timer.function = power_timeout;
power_timer.expires = jiffies + POWERDOWN_TIMEOUT * HZ;
add_timer(&power_timer);
}
static int panic_event(struct notifier_block *this, unsigned long event,
void *ptr)
{
unsigned long led;
if (has_panicked)
return NOTIFY_DONE;
has_panicked = 1;
led = mace->perif.ctrl.misc | MACEISA_LED_GREEN;
mace->perif.ctrl.misc = led;
blink_timer.data = PANIC_FREQ;
blink_timeout(PANIC_FREQ);
return NOTIFY_DONE;
}
static __init int ip32_reboot_setup(void)
{
unsigned long led = mace->perif.ctrl.misc;
led |= MACEISA_LED_RED;
led &= ~MACEISA_LED_GREEN;
mace->perif.ctrl.misc = led;
_machine_restart = ip32_machine_restart;
_machine_halt = ip32_machine_halt;
pm_power_off = ip32_machine_halt;
init_timer(&blink_timer);
blink_timer.function = blink_timeout;
atomic_notifier_chain_register(&panic_notifier_list, &panic_block);
return 0;
}
