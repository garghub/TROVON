unsigned int pxa25x_get_clk_frequency_khz(int info)
{
unsigned long cccr, turbo;
unsigned int l, L, m, M, n2, N;
cccr = CCCR;
asm( "mrc\tp14, 0, %0, c6, c0, 0" : "=r" (turbo) );
l = L_clk_mult[(cccr >> 0) & 0x1f];
m = M_clk_mult[(cccr >> 5) & 0x03];
n2 = N2_clk_mult[(cccr >> 7) & 0x07];
L = l * BASE_CLK;
M = m * L;
N = n2 * M / 2;
if(info)
{
L += 5000;
printk( KERN_INFO "Memory clock: %d.%02dMHz (*%d)\n",
L / 1000000, (L % 1000000) / 10000, l );
M += 5000;
printk( KERN_INFO "Run Mode clock: %d.%02dMHz (*%d)\n",
M / 1000000, (M % 1000000) / 10000, m );
N += 5000;
printk( KERN_INFO "Turbo Mode clock: %d.%02dMHz (*%d.%d, %sactive)\n",
N / 1000000, (N % 1000000) / 10000, n2 / 2, (n2 % 2) * 5,
(turbo & 1) ? "" : "in" );
}
return (turbo & 1) ? (N/1000) : (M/1000);
}
static unsigned long clk_pxa25x_mem_getrate(struct clk *clk)
{
return L_clk_mult[(CCCR >> 0) & 0x1f] * BASE_CLK;
}
static void clk_gpio12_enable(struct clk *clk)
{
pxa2xx_mfp_config(gpio12_config_32k, 1);
}
static void clk_gpio12_disable(struct clk *clk)
{
pxa2xx_mfp_config(gpio12_config_gpio, 1);
}
static void clk_gpio11_enable(struct clk *clk)
{
pxa2xx_mfp_config(gpio11_config_3m6, 1);
}
static void clk_gpio11_disable(struct clk *clk)
{
pxa2xx_mfp_config(gpio11_config_gpio, 1);
}
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
clkdev_add_table(pxa25x_clkregs, ARRAY_SIZE(pxa25x_clkregs));
if ((ret = pxa_init_dma(IRQ_DMA, 16)))
return ret;
pxa25x_init_pm();
register_syscore_ops(&pxa_irq_syscore_ops);
register_syscore_ops(&pxa2xx_mfp_syscore_ops);
register_syscore_ops(&pxa2xx_clock_syscore_ops);
pxa_register_device(&pxa_device_gpio, &pxa25x_gpio_info);
ret = platform_add_devices(pxa25x_devices,
ARRAY_SIZE(pxa25x_devices));
if (ret)
return ret;
}
if (cpu_is_pxa255())
clkdev_add(&pxa25x_hwuart_clkreg);
return ret;
}
