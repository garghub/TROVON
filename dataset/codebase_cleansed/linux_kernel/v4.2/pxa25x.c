static void pxa25x_cpu_pm_save(unsigned long *sleep_save)
{
SAVE(PSTR);
}
static void pxa25x_cpu_pm_restore(unsigned long *sleep_save)
{
RESTORE(PSTR);
}
static void pxa25x_cpu_pm_enter(suspend_state_t state)
{
RCSR = RCSR_HWR | RCSR_WDR | RCSR_SMR | RCSR_GPR;
switch (state) {
case PM_SUSPEND_MEM:
cpu_suspend(PWRMODE_SLEEP, pxa25x_finish_suspend);
break;
}
}
static int pxa25x_cpu_pm_prepare(void)
{
PSPR = virt_to_phys(cpu_resume);
return 0;
}
static void pxa25x_cpu_pm_finish(void)
{
PSPR = 0;
}
static void __init pxa25x_init_pm(void)
{
pxa_cpu_pm_fns = &pxa25x_cpu_pm_fns;
}
static inline void pxa25x_init_pm(void) {}
static int pxa25x_set_wake(struct irq_data *d, unsigned int on)
{
int gpio = pxa_irq_to_gpio(d->irq);
uint32_t mask = 0;
if (gpio >= 0 && gpio < 85)
return gpio_set_wake(gpio, on);
if (d->irq == IRQ_RTCAlrm) {
mask = PWER_RTC;
goto set_pwer;
}
return -EINVAL;
set_pwer:
if (on)
PWER |= mask;
else
PWER &=~mask;
return 0;
}
void __init pxa25x_init_irq(void)
{
pxa_init_irq(32, pxa25x_set_wake);
}
void __init pxa26x_init_irq(void)
{
pxa_init_irq(32, pxa25x_set_wake);
}
void __init pxa25x_map_io(void)
{
pxa_map_io();
iotable_init(ARRAY_AND_SIZE(pxa25x_io_desc));
pxa25x_get_clk_frequency_khz(1);
}
static int __init pxa25x_init(void)
{
int ret = 0;
if (cpu_is_pxa25x()) {
reset_status = RCSR;
if ((ret = pxa_init_dma(IRQ_DMA, 16)))
return ret;
pxa25x_init_pm();
register_syscore_ops(&pxa_irq_syscore_ops);
register_syscore_ops(&pxa2xx_mfp_syscore_ops);
pxa_register_device(&pxa25x_device_gpio, &pxa25x_gpio_info);
ret = platform_add_devices(pxa25x_devices,
ARRAY_SIZE(pxa25x_devices));
if (ret)
return ret;
}
return ret;
}
