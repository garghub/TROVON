static void __init v2m_sysctl_init(void __iomem *base)
{
u32 scctrl;
if (WARN_ON(!base))
return;
scctrl = readl(base + SCCTRL);
scctrl |= SCCTRL_TIMEREN0SEL_TIMCLK;
scctrl |= SCCTRL_TIMEREN1SEL_TIMCLK;
writel(scctrl, base + SCCTRL);
}
static void __init v2m_sp804_init(void __iomem *base, unsigned int irq)
{
if (WARN_ON(!base || irq == NO_IRQ))
return;
writel(0, base + TIMER_1_BASE + TIMER_CTRL);
writel(0, base + TIMER_2_BASE + TIMER_CTRL);
sp804_clocksource_init(base + TIMER_2_BASE, "v2m-timer1");
sp804_clockevents_init(base + TIMER_1_BASE, irq, "v2m-timer0");
}
static void __init v2m_timer_init(void)
{
v2m_sysctl_init(ioremap(V2M_SYSCTL, SZ_4K));
v2m_sp804_init(ioremap(V2M_TIMER01, SZ_4K), IRQ_V2M_TIMER0);
}
int v2m_cfg_write(u32 devfn, u32 data)
{
u32 val;
printk("%s: writing %08x to %08x\n", __func__, data, devfn);
devfn |= SYS_CFG_START | SYS_CFG_WRITE;
spin_lock(&v2m_cfg_lock);
val = readl(v2m_sysreg_base + V2M_SYS_CFGSTAT);
writel(val & ~SYS_CFG_COMPLETE, v2m_sysreg_base + V2M_SYS_CFGSTAT);
writel(data, v2m_sysreg_base + V2M_SYS_CFGDATA);
writel(devfn, v2m_sysreg_base + V2M_SYS_CFGCTRL);
do {
val = readl(v2m_sysreg_base + V2M_SYS_CFGSTAT);
} while (val == 0);
spin_unlock(&v2m_cfg_lock);
return !!(val & SYS_CFG_ERR);
}
int v2m_cfg_read(u32 devfn, u32 *data)
{
u32 val;
devfn |= SYS_CFG_START;
spin_lock(&v2m_cfg_lock);
writel(0, v2m_sysreg_base + V2M_SYS_CFGSTAT);
writel(devfn, v2m_sysreg_base + V2M_SYS_CFGCTRL);
mb();
do {
cpu_relax();
val = readl(v2m_sysreg_base + V2M_SYS_CFGSTAT);
} while (val == 0);
*data = readl(v2m_sysreg_base + V2M_SYS_CFGDATA);
spin_unlock(&v2m_cfg_lock);
return !!(val & SYS_CFG_ERR);
}
void __init v2m_flags_set(u32 data)
{
writel(~0, v2m_sysreg_base + V2M_SYS_FLAGSCLR);
writel(data, v2m_sysreg_base + V2M_SYS_FLAGSSET);
}
static void v2m_flash_set_vpp(struct platform_device *pdev, int on)
{
writel(on != 0, v2m_sysreg_base + V2M_SYS_FLASH);
}
static unsigned int v2m_mmci_status(struct device *dev)
{
return readl(v2m_sysreg_base + V2M_SYS_MCI) & (1 << 0);
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
versatile_sched_clock_init(v2m_sysreg_base + V2M_SYS_24MHZ, 24000000);
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
current_tile_id = readl(v2m_sysreg_base + V2M_SYS_PROCID0)
& V2M_CT_ID_MASK;
for (i = 0; i < ARRAY_SIZE(ct_descs) && !ct_desc; ++i)
if (ct_descs[i]->id == current_tile_id)
ct_desc = ct_descs[i];
if (!ct_desc)
panic("vexpress: this kernel does not support core tile ID 0x%08x when booting via ATAGs.\n"
"You may need a device tree blob or a different kernel to boot on this board.\n",
current_tile_id);
}
static void __init v2m_map_io(void)
{
iotable_init(v2m_io_desc, ARRAY_SIZE(v2m_io_desc));
v2m_sysreg_base = ioremap(V2M_SYSREGS, SZ_4K);
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
static int __init v2m_dt_scan_memory_map(unsigned long node, const char *uname,
int depth, void *data)
{
const char **map = data;
if (strcmp(uname, "motherboard") != 0)
return 0;
*map = of_get_flat_dt_prop(node, "arm,v2m-memory-map", NULL);
return 1;
}
void __init v2m_dt_map_io(void)
{
const char *map = NULL;
of_scan_flat_dt(v2m_dt_scan_memory_map, &map);
if (map && strcmp(map, "rs1") == 0)
iotable_init(&v2m_rs1_io_desc, 1);
else
iotable_init(v2m_io_desc, ARRAY_SIZE(v2m_io_desc));
#if defined(CONFIG_SMP)
vexpress_dt_smp_map_io();
#endif
}
void __init v2m_dt_init_early(void)
{
struct device_node *node;
u32 dt_hbi;
node = of_find_compatible_node(NULL, NULL, "arm,vexpress-sysreg");
v2m_sysreg_base = of_iomap(node, 0);
if (WARN_ON(!v2m_sysreg_base))
return;
if (of_property_read_u32(allnodes, "arm,hbi", &dt_hbi) == 0) {
u32 misc = readl(v2m_sysreg_base + V2M_SYS_MISC);
u32 id = readl(v2m_sysreg_base + (misc & SYS_MISC_MASTERSITE ?
V2M_SYS_PROCID1 : V2M_SYS_PROCID0));
u32 hbi = id & SYS_PROCIDx_HBI_MASK;
if (WARN_ON(dt_hbi != hbi))
pr_warning("vexpress: DT HBI (%x) is not matching "
"hardware (%x)!\n", dt_hbi, hbi);
}
clkdev_add_table(v2m_dt_lookups, ARRAY_SIZE(v2m_dt_lookups));
versatile_sched_clock_init(v2m_sysreg_base + V2M_SYS_24MHZ, 24000000);
}
static void __init v2m_dt_init_irq(void)
{
of_irq_init(vexpress_irq_match);
}
static void __init v2m_dt_timer_init(void)
{
struct device_node *node;
const char *path;
int err;
node = of_find_compatible_node(NULL, NULL, "arm,sp810");
v2m_sysctl_init(of_iomap(node, 0));
err = of_property_read_string(of_aliases, "arm,v2m_timer", &path);
if (WARN_ON(err))
return;
node = of_find_node_by_path(path);
v2m_sp804_init(of_iomap(node, 0), irq_of_parse_and_map(node, 0));
}
static void __init v2m_dt_init(void)
{
l2x0_of_init(0x00400000, 0xfe0fffff);
of_platform_populate(NULL, of_default_bus_match_table,
v2m_dt_auxdata_lookup, NULL);
pm_power_off = v2m_power_off;
}
