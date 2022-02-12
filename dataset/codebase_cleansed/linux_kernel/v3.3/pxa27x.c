void pxa27x_clear_otgph(void)
{
if (cpu_is_pxa27x() && (PSSR & PSSR_OTGPH))
PSSR |= PSSR_OTGPH;
}
void pxa27x_assert_ac97reset(int reset_gpio, int on)
{
if (reset_gpio == 113)
pxa2xx_mfp_config(on ? &ac97_reset_config[0] :
&ac97_reset_config[1], 1);
if (reset_gpio == 95)
pxa2xx_mfp_config(on ? &ac97_reset_config[2] :
&ac97_reset_config[3], 1);
}
unsigned int pxa27x_get_clk_frequency_khz(int info)
{
unsigned long ccsr, clkcfg;
unsigned int l, L, m, M, n2, N, S;
int cccr_a, t, ht, b;
ccsr = CCSR;
cccr_a = CCCR & (1 << 25);
asm( "mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg) );
t = clkcfg & (1 << 0);
ht = clkcfg & (1 << 2);
b = clkcfg & (1 << 3);
l = ccsr & 0x1f;
n2 = (ccsr>>7) & 0xf;
m = (l <= 10) ? 1 : (l <= 20) ? 2 : 4;
L = l * BASE_CLK;
N = (L * n2) / 2;
M = (!cccr_a) ? (L/m) : ((b) ? L : (L/2));
S = (b) ? L : (L/2);
if (info) {
printk( KERN_INFO "Run Mode clock: %d.%02dMHz (*%d)\n",
L / 1000000, (L % 1000000) / 10000, l );
printk( KERN_INFO "Turbo Mode clock: %d.%02dMHz (*%d.%d, %sactive)\n",
N / 1000000, (N % 1000000)/10000, n2 / 2, (n2 % 2)*5,
(t) ? "" : "in" );
printk( KERN_INFO "Memory clock: %d.%02dMHz (/%d)\n",
M / 1000000, (M % 1000000) / 10000, m );
printk( KERN_INFO "System bus clock: %d.%02dMHz \n",
S / 1000000, (S % 1000000) / 10000 );
}
return (t) ? (N/1000) : (L/1000);
}
static unsigned long clk_pxa27x_mem_getrate(struct clk *clk)
{
unsigned long ccsr, clkcfg;
unsigned int l, L, m, M;
int cccr_a, b;
ccsr = CCSR;
cccr_a = CCCR & (1 << 25);
asm( "mrc\tp14, 0, %0, c6, c0, 0" : "=r" (clkcfg) );
b = clkcfg & (1 << 3);
l = ccsr & 0x1f;
m = (l <= 10) ? 1 : (l <= 20) ? 2 : 4;
L = l * BASE_CLK;
M = (!cccr_a) ? (L/m) : ((b) ? L : (L/2));
return M;
}
static unsigned int pxa27x_get_lcdclk_frequency_10khz(void)
{
unsigned long ccsr;
unsigned int l, L, k, K;
ccsr = CCSR;
l = ccsr & 0x1f;
k = (l <= 7) ? 1 : (l <= 16) ? 2 : 4;
L = l * BASE_CLK;
K = L / k;
return (K / 10000);
}
static unsigned long clk_pxa27x_lcd_getrate(struct clk *clk)
{
return pxa27x_get_lcdclk_frequency_10khz() * 10000;
}
int __init pxa27x_set_pwrmode(unsigned int mode)
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
asm volatile("mra %Q0, %R0, acc0" : "=r" (acc0));
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
asm volatile("mar acc0, %Q0, %R0" : "=r" (acc0));
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
PSPR = virt_to_phys(cpu_resume);
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
clkdev_add_table(pxa27x_clkregs, ARRAY_SIZE(pxa27x_clkregs));
if ((ret = pxa_init_dma(IRQ_DMA, 32)))
return ret;
pxa27x_init_pm();
register_syscore_ops(&pxa_irq_syscore_ops);
register_syscore_ops(&pxa2xx_mfp_syscore_ops);
register_syscore_ops(&pxa2xx_clock_syscore_ops);
ret = platform_add_devices(devices, ARRAY_SIZE(devices));
}
return ret;
}
