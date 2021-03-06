static void ip32_machine_restart(char *cmd)
{
crime->control = CRIME_CONTROL_HARD_RESET;
while (1);
}
static inline void ip32_machine_halt(void)
{
ip32_machine_power_off();
}
static void ip32_machine_power_off(void)
{
unsigned char reg_a, xctrl_a, xctrl_b;
disable_irq(MACEISA_RTC_IRQ);
reg_a = CMOS_READ(RTC_REG_A);
reg_a &= ~DS_REGA_DV2;
reg_a |= DS_REGA_DV1;
CMOS_WRITE(reg_a | DS_REGA_DV0, RTC_REG_A);
wbflush();
xctrl_b = CMOS_READ(DS_B1_XCTRL4B)
| DS_XCTRL4B_ABE | DS_XCTRL4B_KFE;
CMOS_WRITE(xctrl_b, DS_B1_XCTRL4B);
xctrl_a = CMOS_READ(DS_B1_XCTRL4A) & ~DS_XCTRL4A_IFS;
CMOS_WRITE(xctrl_a, DS_B1_XCTRL4A);
wbflush();
CMOS_WRITE(xctrl_a | DS_XCTRL4A_PAB, DS_B1_XCTRL4A);
CMOS_WRITE(reg_a, RTC_REG_A);
wbflush();
while (1);
}
static void power_timeout(unsigned long data)
{
ip32_machine_power_off();
}
static void blink_timeout(unsigned long data)
{
unsigned long led = mace->perif.ctrl.misc ^ MACEISA_LED_RED;
mace->perif.ctrl.misc = led;
mod_timer(&blink_timer, jiffies + data);
}
static void debounce(unsigned long data)
{
unsigned char reg_a, reg_c, xctrl_a;
reg_c = CMOS_READ(RTC_INTR_FLAGS);
reg_a = CMOS_READ(RTC_REG_A);
CMOS_WRITE(reg_a | DS_REGA_DV0, RTC_REG_A);
wbflush();
xctrl_a = CMOS_READ(DS_B1_XCTRL4A);
if ((xctrl_a & DS_XCTRL4A_IFS) || (reg_c & RTC_IRQF )) {
debounce_timer.expires = jiffies + 50;
add_timer(&debounce_timer);
CMOS_WRITE(xctrl_a & ~DS_XCTRL4A_IFS, DS_B1_XCTRL4A);
CMOS_WRITE(reg_a & ~DS_REGA_DV0, RTC_REG_A);
return;
}
CMOS_WRITE(reg_a & ~DS_REGA_DV0, RTC_REG_A);
if (has_panicked)
ip32_machine_restart(NULL);
enable_irq(MACEISA_RTC_IRQ);
}
static inline void ip32_power_button(void)
{
if (has_panicked)
return;
if (shuting_down || kill_cad_pid(SIGINT, 1)) {
ip32_machine_power_off();
}
shuting_down = 1;
blink_timer.data = POWERDOWN_FREQ;
blink_timeout(POWERDOWN_FREQ);
init_timer(&power_timer);
power_timer.function = power_timeout;
power_timer.expires = jiffies + POWERDOWN_TIMEOUT * HZ;
add_timer(&power_timer);
}
static irqreturn_t ip32_rtc_int(int irq, void *dev_id)
{
unsigned char reg_c;
reg_c = CMOS_READ(RTC_INTR_FLAGS);
if (!(reg_c & RTC_IRQF)) {
printk(KERN_WARNING
"%s: RTC IRQ without RTC_IRQF\n", __func__);
}
disable_irq_nosync(MACEISA_RTC_IRQ);
init_timer(&debounce_timer);
debounce_timer.function = debounce;
debounce_timer.expires = jiffies + 50;
add_timer(&debounce_timer);
printk(KERN_DEBUG "Power button pressed\n");
ip32_power_button();
return IRQ_HANDLED;
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
pm_power_off = ip32_machine_power_off;
init_timer(&blink_timer);
blink_timer.function = blink_timeout;
atomic_notifier_chain_register(&panic_notifier_list, &panic_block);
if (request_irq(MACEISA_RTC_IRQ, ip32_rtc_int, 0, "rtc", NULL))
panic("Can't allocate MACEISA RTC IRQ");
return 0;
}
