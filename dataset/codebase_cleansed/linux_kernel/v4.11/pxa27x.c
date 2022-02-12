void pxa27x_clear_otgph(void)
{
if (cpu_is_pxa27x() && (PSSR & PSSR_OTGPH))
PSSR |= PSSR_OTGPH;
}
void pxa27x_configure_ac97reset(int reset_gpio, bool to_gpio)
{
if (reset_gpio == 113)
pxa2xx_mfp_config(to_gpio ? &ac97_reset_config[0] :
&ac97_reset_config[1], 1);
if (reset_gpio == 95)
pxa2xx_mfp_config(to_gpio ? &ac97_reset_config[2] :
&ac97_reset_config[3], 1);
}
int pxa27x_set_pwrmode(unsigned int mode)
{
switch (mode) {
case PWRMODE_SLEEP:
case PWRMODE_DEEPSLEEP:
pwrmode = mode;
return 0;
}
return -EINVAL;
}
void pxa27x_cpu_pm_save(unsigned long *sleep_save)
{
sleep_save[SLEEP_SAVE_MDREFR] = __raw_readl(MDREFR);
SAVE(PCFR);
SAVE(PSTR);
}
void pxa27x_cpu_pm_restore(unsigned long *sleep_save)
{
__raw_writel(sleep_save[SLEEP_SAVE_MDREFR], MDREFR);
RESTORE(PCFR);
PSSR = PSSR_RDH | PSSR_PH;
RESTORE(PSTR);
}
void pxa27x_cpu_pm_enter(suspend_state_t state)
{
extern void pxa_cpu_standby(void);
#ifndef CONFIG_IWMMXT
u64 acc0;
asm volatile(".arch_extension xscale\n\t"
"mra %Q0, %R0, acc0" : "=r" (acc0));
#endif
PCFR &= ~PCFR_FVC;
PEDR = 0xDF12FE1B;
RCSR = RCSR_HWR | RCSR_WDR | RCSR_SMR | RCSR_GPR;
switch (state) {
case PM_SUSPEND_STANDBY:
pxa_cpu_standby();
break;
case PM_SUSPEND_MEM:
cpu_suspend(pwrmode, pxa27x_finish_suspend);
#ifndef CONFIG_IWMMXT
asm volatile(".arch_extension xscale\n\t"
"mar acc0, %Q0, %R0" : "=r" (acc0));
#endif
break;
}
}
static int pxa27x_cpu_pm_valid(suspend_state_t state)
{
return state == PM_SUSPEND_MEM || state == PM_SUSPEND_STANDBY;
}
static int pxa27x_cpu_pm_prepare(void)
{
PSPR = __pa_symbol(cpu_resume);
return 0;
}
static void pxa27x_cpu_pm_finish(void)
{
PSPR = 0;
}
static void __init pxa27x_init_pm(void)
{
pxa_cpu_pm_fns = &pxa27x_cpu_pm_fns;
}
static inline void pxa27x_init_pm(void) {}
static int pxa27x_set_wake(struct irq_data *d, unsigned int on)
{
int gpio = pxa_irq_to_gpio(d->irq);
uint32_t mask;
if (gpio >= 0 && gpio < 128)
return gpio_set_wake(gpio, on);
if (d->irq == IRQ_KEYPAD)
return keypad_set_wake(on);
switch (d->irq) {
case IRQ_RTCAlrm:
mask = PWER_RTC;
break;
case IRQ_USB:
mask = 1u << 26;
break;
default:
return -EINVAL;
}
if (on)
PWER |= mask;
else
PWER &=~mask;
return 0;
}
void __init pxa27x_init_irq(void)
{
pxa_init_irq(34, pxa27x_set_wake);
}
static int __init
pxa27x_dt_init_irq(struct device_node *node, struct device_node *parent)
{
pxa_dt_irq_init(pxa27x_set_wake);
set_handle_irq(ichp_handle_irq);
return 0;
}
void __init pxa27x_map_io(void)
{
pxa_map_io();
iotable_init(ARRAY_AND_SIZE(pxa27x_io_desc));
pxa27x_get_clk_frequency_khz(1);
}
void __init pxa27x_set_i2c_power_info(struct i2c_pxa_platform_data *info)
{
local_irq_disable();
PCFR |= PCFR_PI2CEN;
local_irq_enable();
pxa_register_device(&pxa27x_device_i2c_power, info);
}
static int __init pxa27x_init(void)
{
int ret = 0;
if (cpu_is_pxa27x()) {
reset_status = RCSR;
pxa27x_init_pm();
register_syscore_ops(&pxa_irq_syscore_ops);
register_syscore_ops(&pxa2xx_mfp_syscore_ops);
if (!of_have_populated_dt()) {
pxa_register_device(&pxa27x_device_gpio,
&pxa27x_gpio_info);
pxa2xx_set_dmac_info(32, 75);
ret = platform_add_devices(devices,
ARRAY_SIZE(devices));
}
}
return ret;
}
