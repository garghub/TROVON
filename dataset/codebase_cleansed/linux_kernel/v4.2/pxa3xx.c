static void pxa3xx_cpu_standby(unsigned int pwrmode)
{
extern const char pm_enter_standby_start[], pm_enter_standby_end[];
void (*fn)(unsigned int) = (void __force *)(sram + 0x8000);
memcpy_toio(sram + 0x8000, pm_enter_standby_start,
pm_enter_standby_end - pm_enter_standby_start);
AD2D0SR = ~0;
AD2D1SR = ~0;
AD2D0ER = wakeup_src;
AD2D1ER = 0;
ASCR = ASCR;
ARSR = ARSR;
local_fiq_disable();
fn(pwrmode);
local_fiq_enable();
AD2D0ER = 0;
AD2D1ER = 0;
}
static void pxa3xx_cpu_pm_suspend(void)
{
volatile unsigned long *p = (volatile void *)0xc0000000;
unsigned long saved_data = *p;
#ifndef CONFIG_IWMMXT
u64 acc0;
asm volatile("mra %Q0, %R0, acc0" : "=r" (acc0));
#endif
extern int pxa3xx_finish_suspend(unsigned long);
CKENA |= (1 << CKEN_BOOT) | (1 << CKEN_TPM);
CKENB |= 1 << (CKEN_HSIO2 & 0x1f);
AD3SR = ~0;
AD3ER = wakeup_src;
ASCR = ASCR;
ARSR = ARSR;
PCFR |= (1u << 13);
PCFR &= ~((1u << 12) | (1u << 1));
PSPR = 0x5c014000;
*p = virt_to_phys(cpu_resume);
cpu_suspend(0, pxa3xx_finish_suspend);
*p = saved_data;
AD3ER = 0;
#ifndef CONFIG_IWMMXT
asm volatile("mar acc0, %Q0, %R0" : "=r" (acc0));
#endif
}
static void pxa3xx_cpu_pm_enter(suspend_state_t state)
{
if (wakeup_src == 0) {
printk(KERN_ERR "Not suspending: no wakeup sources\n");
return;
}
switch (state) {
case PM_SUSPEND_STANDBY:
pxa3xx_cpu_standby(PXA3xx_PM_S0D2C2);
break;
case PM_SUSPEND_MEM:
pxa3xx_cpu_pm_suspend();
break;
}
}
static int pxa3xx_cpu_pm_valid(suspend_state_t state)
{
return state == PM_SUSPEND_MEM || state == PM_SUSPEND_STANDBY;
}
static void __init pxa3xx_init_pm(void)
{
sram = ioremap(ISRAM_START, ISRAM_SIZE);
if (!sram) {
printk(KERN_ERR "Unable to map ISRAM: disabling standby/suspend\n");
return;
}
AD1R |= ADXR_L2 | ADXR_R0;
AD2R |= ADXR_L2 | ADXR_R0;
AD3R |= ADXR_L2 | ADXR_R0;
AD1D0ER = 0;
AD2D0ER = 0;
AD2D1ER = 0;
AD3ER = 0;
pxa_cpu_pm_fns = &pxa3xx_cpu_pm_fns;
}
static int pxa3xx_set_wake(struct irq_data *d, unsigned int on)
{
unsigned long flags, mask = 0;
switch (d->irq) {
case IRQ_SSP3:
mask = ADXER_MFP_WSSP3;
break;
case IRQ_MSL:
mask = ADXER_WMSL0;
break;
case IRQ_USBH2:
case IRQ_USBH1:
mask = ADXER_WUSBH;
break;
case IRQ_KEYPAD:
mask = ADXER_WKP;
break;
case IRQ_AC97:
mask = ADXER_MFP_WAC97;
break;
case IRQ_USIM:
mask = ADXER_WUSIM0;
break;
case IRQ_SSP2:
mask = ADXER_MFP_WSSP2;
break;
case IRQ_I2C:
mask = ADXER_MFP_WI2C;
break;
case IRQ_STUART:
mask = ADXER_MFP_WUART3;
break;
case IRQ_BTUART:
mask = ADXER_MFP_WUART2;
break;
case IRQ_FFUART:
mask = ADXER_MFP_WUART1;
break;
case IRQ_MMC:
mask = ADXER_MFP_WMMC1;
break;
case IRQ_SSP:
mask = ADXER_MFP_WSSP1;
break;
case IRQ_RTCAlrm:
mask = ADXER_WRTC;
break;
case IRQ_SSP4:
mask = ADXER_MFP_WSSP4;
break;
case IRQ_TSI:
mask = ADXER_WTSI;
break;
case IRQ_USIM2:
mask = ADXER_WUSIM1;
break;
case IRQ_MMC2:
mask = ADXER_MFP_WMMC2;
break;
case IRQ_NAND:
mask = ADXER_MFP_WFLASH;
break;
case IRQ_USB2:
mask = ADXER_WUSB2;
break;
case IRQ_WAKEUP0:
mask = ADXER_WEXTWAKE0;
break;
case IRQ_WAKEUP1:
mask = ADXER_WEXTWAKE1;
break;
case IRQ_MMC3:
mask = ADXER_MFP_GEN12;
break;
default:
return -EINVAL;
}
local_irq_save(flags);
if (on)
wakeup_src |= mask;
else
wakeup_src &= ~mask;
local_irq_restore(flags);
return 0;
}
static inline void pxa3xx_init_pm(void) {}
static void pxa_ack_ext_wakeup(struct irq_data *d)
{
PECR |= PECR_IS(d->irq - IRQ_WAKEUP0);
}
static void pxa_mask_ext_wakeup(struct irq_data *d)
{
pxa_mask_irq(d);
PECR &= ~PECR_IE(d->irq - IRQ_WAKEUP0);
}
static void pxa_unmask_ext_wakeup(struct irq_data *d)
{
pxa_unmask_irq(d);
PECR |= PECR_IE(d->irq - IRQ_WAKEUP0);
}
static int pxa_set_ext_wakeup_type(struct irq_data *d, unsigned int flow_type)
{
if (flow_type & IRQ_TYPE_EDGE_RISING)
PWER |= 1 << (d->irq - IRQ_WAKEUP0);
if (flow_type & IRQ_TYPE_EDGE_FALLING)
PWER |= 1 << (d->irq - IRQ_WAKEUP0 + 2);
return 0;
}
static void __init pxa_init_ext_wakeup_irq(int (*fn)(struct irq_data *,
unsigned int))
{
int irq;
for (irq = IRQ_WAKEUP0; irq <= IRQ_WAKEUP1; irq++) {
irq_set_chip_and_handler(irq, &pxa_ext_wakeup_chip,
handle_edge_irq);
set_irq_flags(irq, IRQF_VALID);
}
pxa_ext_wakeup_chip.irq_set_wake = fn;
}
static void __init __pxa3xx_init_irq(void)
{
u32 value;
__asm__ __volatile__("mrc p15, 0, %0, c15, c1, 0\n": "=r"(value));
value |= (1 << 6);
__asm__ __volatile__("mcr p15, 0, %0, c15, c1, 0\n": :"r"(value));
pxa_init_ext_wakeup_irq(pxa3xx_set_wake);
}
void __init pxa3xx_init_irq(void)
{
__pxa3xx_init_irq();
pxa_init_irq(56, pxa3xx_set_wake);
}
void __init pxa3xx_dt_init_irq(void)
{
__pxa3xx_init_irq();
pxa_dt_irq_init(pxa3xx_set_wake);
}
void __init pxa3xx_map_io(void)
{
pxa_map_io();
iotable_init(ARRAY_AND_SIZE(pxa3xx_io_desc));
pxa3xx_get_clk_frequency_khz(1);
}
void __init pxa3xx_set_i2c_power_info(struct i2c_pxa_platform_data *info)
{
pxa_register_device(&pxa3xx_device_i2c_power, info);
}
static int __init pxa3xx_init(void)
{
int ret = 0;
if (cpu_is_pxa3xx()) {
reset_status = ARSR;
ASCR &= ~(ASCR_RDH | ASCR_D1S | ASCR_D2S | ASCR_D3S);
if ((ret = pxa_init_dma(IRQ_DMA, 32)))
return ret;
pxa3xx_init_pm();
register_syscore_ops(&pxa_irq_syscore_ops);
register_syscore_ops(&pxa3xx_mfp_syscore_ops);
if (of_have_populated_dt())
return 0;
ret = platform_add_devices(devices, ARRAY_SIZE(devices));
if (ret)
return ret;
if (cpu_is_pxa300() || cpu_is_pxa310() || cpu_is_pxa320()) {
platform_device_add_data(&pxa3xx_device_gpio,
&pxa3xx_gpio_pdata,
sizeof(pxa3xx_gpio_pdata));
ret = platform_device_register(&pxa3xx_device_gpio);
}
}
return ret;
}
