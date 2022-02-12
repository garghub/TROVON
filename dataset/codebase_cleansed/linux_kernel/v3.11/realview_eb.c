static void __init realview_eb_map_io(void)
{
iotable_init(realview_eb_io_desc, ARRAY_SIZE(realview_eb_io_desc));
if (core_tile_eb11mp() || core_tile_a9mp())
iotable_init(realview_eb11mp_io_desc, ARRAY_SIZE(realview_eb11mp_io_desc));
}
static int eth_device_register(void)
{
void __iomem *eth_addr = ioremap(REALVIEW_EB_ETH_BASE, SZ_4K);
const char *name = NULL;
u32 idrev;
if (!eth_addr)
return -ENOMEM;
idrev = readl(eth_addr + 0x50);
if ((idrev & 0xFFFF0000) != 0x01180000)
name = "smc91x";
iounmap(eth_addr);
return realview_eth_register(name, realview_eb_eth_resources);
}
static void __init gic_init_irq(void)
{
if (core_tile_eb11mp() || core_tile_a9mp()) {
unsigned int pldctrl;
writel(0x0000a05f, __io_address(REALVIEW_SYS_LOCK));
pldctrl = readl(__io_address(REALVIEW_SYS_BASE) + REALVIEW_EB11MP_SYS_PLD_CTRL1);
pldctrl |= 0x00800000;
writel(pldctrl, __io_address(REALVIEW_SYS_BASE) + REALVIEW_EB11MP_SYS_PLD_CTRL1);
writel(0x00000000, __io_address(REALVIEW_SYS_LOCK));
gic_init(0, 29, __io_address(REALVIEW_EB11MP_GIC_DIST_BASE),
__io_address(REALVIEW_EB11MP_GIC_CPU_BASE));
#ifndef CONFIG_REALVIEW_EB_ARM11MP_REVB
gic_init(1, 96, __io_address(REALVIEW_EB_GIC_DIST_BASE),
__io_address(REALVIEW_EB_GIC_CPU_BASE));
gic_cascade_irq(1, IRQ_EB11MP_EB_IRQ1);
#endif
} else {
gic_init(0, 29, __io_address(REALVIEW_EB_GIC_DIST_BASE),
__io_address(REALVIEW_EB_GIC_CPU_BASE));
}
}
static void realview_eb11mp_fixup(void)
{
dmac_device.irq[0] = IRQ_EB11MP_DMA;
uart0_device.irq[0] = IRQ_EB11MP_UART0;
uart1_device.irq[0] = IRQ_EB11MP_UART1;
uart2_device.irq[0] = IRQ_EB11MP_UART2;
uart3_device.irq[0] = IRQ_EB11MP_UART3;
clcd_device.irq[0] = IRQ_EB11MP_CLCD;
wdog_device.irq[0] = IRQ_EB11MP_WDOG;
gpio0_device.irq[0] = IRQ_EB11MP_GPIO0;
gpio1_device.irq[0] = IRQ_EB11MP_GPIO1;
gpio2_device.irq[0] = IRQ_EB11MP_GPIO2;
rtc_device.irq[0] = IRQ_EB11MP_RTC;
sci0_device.irq[0] = IRQ_EB11MP_SCI;
ssp0_device.irq[0] = IRQ_EB11MP_SSP;
aaci_device.irq[0] = IRQ_EB11MP_AACI;
mmc0_device.irq[0] = IRQ_EB11MP_MMCI0A;
mmc0_device.irq[1] = IRQ_EB11MP_MMCI0B;
kmi0_device.irq[0] = IRQ_EB11MP_KMI0;
kmi1_device.irq[0] = IRQ_EB11MP_KMI1;
realview_eb_eth_resources[1].start = IRQ_EB11MP_ETH;
realview_eb_eth_resources[1].end = IRQ_EB11MP_ETH;
realview_eb_isp1761_resources[1].start = IRQ_EB11MP_USB;
realview_eb_isp1761_resources[1].end = IRQ_EB11MP_USB;
}
static void __init realview_eb_twd_init(void)
{
if (core_tile_eb11mp() || core_tile_a9mp()) {
int err = twd_local_timer_register(&twd_local_timer);
if (err)
pr_err("twd_local_timer_register failed %d\n", err);
}
}
static void __init realview_eb_timer_init(void)
{
unsigned int timer_irq;
timer0_va_base = __io_address(REALVIEW_EB_TIMER0_1_BASE);
timer1_va_base = __io_address(REALVIEW_EB_TIMER0_1_BASE) + 0x20;
timer2_va_base = __io_address(REALVIEW_EB_TIMER2_3_BASE);
timer3_va_base = __io_address(REALVIEW_EB_TIMER2_3_BASE) + 0x20;
if (core_tile_eb11mp() || core_tile_a9mp())
timer_irq = IRQ_EB11MP_TIMER0_1;
else
timer_irq = IRQ_EB_TIMER0_1;
realview_clk_init(__io_address(REALVIEW_SYS_BASE), false);
realview_timer_init(timer_irq);
realview_eb_twd_init();
}
static void realview_eb_restart(enum reboot_mode mode, const char *cmd)
{
void __iomem *reset_ctrl = __io_address(REALVIEW_SYS_RESETCTL);
void __iomem *lock_ctrl = __io_address(REALVIEW_SYS_LOCK);
__raw_writel(REALVIEW_SYS_LOCK_VAL, lock_ctrl);
if (core_tile_eb11mp())
__raw_writel(0x0008, reset_ctrl);
dsb();
}
static void __init realview_eb_init(void)
{
int i;
if (core_tile_eb11mp() || core_tile_a9mp()) {
realview_eb11mp_fixup();
#ifdef CONFIG_CACHE_L2X0
l2x0_init(__io_address(REALVIEW_EB11MP_L220_BASE), 0x00790000, 0xfe000fff);
#endif
platform_device_register(&pmu_device);
}
realview_flash_register(&realview_eb_flash_resource, 1);
platform_device_register(&realview_i2c_device);
platform_device_register(&char_lcd_device);
eth_device_register();
realview_usb_register(realview_eb_isp1761_resources);
for (i = 0; i < ARRAY_SIZE(amba_devs); i++) {
struct amba_device *d = amba_devs[i];
amba_device_register(d, &iomem_resource);
}
}
