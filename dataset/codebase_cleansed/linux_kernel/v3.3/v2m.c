static void __init v2m_timer_init(void)
{
u32 scctrl;
scctrl = readl(MMIO_P2V(V2M_SYSCTL + SCCTRL));
scctrl |= SCCTRL_TIMEREN0SEL_TIMCLK;
scctrl |= SCCTRL_TIMEREN1SEL_TIMCLK;
writel(scctrl, MMIO_P2V(V2M_SYSCTL + SCCTRL));
writel(0, MMIO_P2V(V2M_TIMER0) + TIMER_CTRL);
writel(0, MMIO_P2V(V2M_TIMER1) + TIMER_CTRL);
sp804_clocksource_init(MMIO_P2V(V2M_TIMER1), "v2m-timer1");
sp804_clockevents_init(MMIO_P2V(V2M_TIMER0), IRQ_V2M_TIMER0,
"v2m-timer0");
}
int v2m_cfg_write(u32 devfn, u32 data)
{
u32 val;
printk("%s: writing %08x to %08x\n", __func__, data, devfn);
devfn |= SYS_CFG_START | SYS_CFG_WRITE;
spin_lock(&v2m_cfg_lock);
val = readl(MMIO_P2V(V2M_SYS_CFGSTAT));
writel(val & ~SYS_CFG_COMPLETE, MMIO_P2V(V2M_SYS_CFGSTAT));
writel(data, MMIO_P2V(V2M_SYS_CFGDATA));
writel(devfn, MMIO_P2V(V2M_SYS_CFGCTRL));
do {
val = readl(MMIO_P2V(V2M_SYS_CFGSTAT));
} while (val == 0);
spin_unlock(&v2m_cfg_lock);
return !!(val & SYS_CFG_ERR);
}
int v2m_cfg_read(u32 devfn, u32 *data)
{
u32 val;
devfn |= SYS_CFG_START;
spin_lock(&v2m_cfg_lock);
writel(0, MMIO_P2V(V2M_SYS_CFGSTAT));
writel(devfn, MMIO_P2V(V2M_SYS_CFGCTRL));
mb();
do {
cpu_relax();
val = readl(MMIO_P2V(V2M_SYS_CFGSTAT));
} while (val == 0);
*data = readl(MMIO_P2V(V2M_SYS_CFGDATA));
spin_unlock(&v2m_cfg_lock);
return !!(val & SYS_CFG_ERR);
}
static void v2m_flash_set_vpp(struct platform_device *pdev, int on)
{
writel(on != 0, MMIO_P2V(V2M_SYS_FLASH));
}
static unsigned int v2m_mmci_status(struct device *dev)
{
return readl(MMIO_P2V(V2M_SYS_MCI)) & (1 << 0);
}
static long v2m_osc_round(struct clk *clk, unsigned long rate)
{
return rate;
}
static int v2m_osc1_set(struct clk *clk, unsigned long rate)
{
return v2m_cfg_write(SYS_CFG_OSC | SYS_CFG_SITE_MB | 1, rate);
}
static void __init v2m_init_early(void)
{
ct_desc->init_early();
clkdev_add_table(v2m_lookups, ARRAY_SIZE(v2m_lookups));
versatile_sched_clock_init(MMIO_P2V(V2M_SYS_24MHZ), 24000000);
}
static void v2m_power_off(void)
{
if (v2m_cfg_write(SYS_CFG_SHUTDOWN | SYS_CFG_SITE_MB, 0))
printk(KERN_EMERG "Unable to shutdown\n");
}
static void v2m_restart(char str, const char *cmd)
{
if (v2m_cfg_write(SYS_CFG_REBOOT | SYS_CFG_SITE_MB, 0))
printk(KERN_EMERG "Unable to reboot\n");
}
static void __init v2m_populate_ct_desc(void)
{
int i;
u32 current_tile_id;
ct_desc = NULL;
current_tile_id = readl(MMIO_P2V(V2M_SYS_PROCID0)) & V2M_CT_ID_MASK;
for (i = 0; i < ARRAY_SIZE(ct_descs) && !ct_desc; ++i)
if (ct_descs[i]->id == current_tile_id)
ct_desc = ct_descs[i];
if (!ct_desc)
panic("vexpress: failed to populate core tile description "
"for tile ID 0x%8x\n", current_tile_id);
}
static void __init v2m_map_io(void)
{
iotable_init(v2m_io_desc, ARRAY_SIZE(v2m_io_desc));
v2m_populate_ct_desc();
ct_desc->map_io();
}
static void __init v2m_init_irq(void)
{
ct_desc->init_irq();
}
static void __init v2m_init(void)
{
int i;
platform_device_register(&v2m_pcie_i2c_device);
platform_device_register(&v2m_ddc_i2c_device);
platform_device_register(&v2m_flash_device);
platform_device_register(&v2m_cf_device);
platform_device_register(&v2m_eth_device);
platform_device_register(&v2m_usb_device);
for (i = 0; i < ARRAY_SIZE(v2m_amba_devs); i++)
amba_device_register(v2m_amba_devs[i], &iomem_resource);
pm_power_off = v2m_power_off;
ct_desc->init_tile();
}
