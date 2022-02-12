static void __init v2m_sp804_init(void __iomem *base, unsigned int irq)
{
if (WARN_ON(!base || irq == NO_IRQ))
return;
sp804_clocksource_init(base + TIMER_2_BASE, "v2m-timer1");
sp804_clockevents_init(base + TIMER_1_BASE, irq, "v2m-timer0");
}
static void __init v2m_timer_init(void)
{
vexpress_clk_init(ioremap(V2M_SYSCTL, SZ_4K));
v2m_sp804_init(ioremap(V2M_TIMER01, SZ_4K), IRQ_V2M_TIMER0);
}
static void __init v2m_init_early(void)
{
if (ct_desc->init_early)
ct_desc->init_early();
versatile_sched_clock_init(vexpress_get_24mhz_clock_base(), 24000000);
}
static void __init v2m_populate_ct_desc(void)
{
int i;
u32 current_tile_id;
ct_desc = NULL;
current_tile_id = vexpress_get_procid(VEXPRESS_SITE_MASTER)
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
vexpress_sysreg_early_init(ioremap(V2M_SYSREGS, SZ_4K));
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
regulator_register_fixed(0, v2m_eth_supplies,
ARRAY_SIZE(v2m_eth_supplies));
platform_device_register(&v2m_sysreg_device);
platform_device_register(&v2m_pcie_i2c_device);
platform_device_register(&v2m_ddc_i2c_device);
platform_device_register(&v2m_flash_device);
platform_device_register(&v2m_cf_device);
platform_device_register(&v2m_eth_device);
platform_device_register(&v2m_usb_device);
for (i = 0; i < ARRAY_SIZE(v2m_amba_devs); i++)
amba_device_register(v2m_amba_devs[i], &iomem_resource);
vexpress_syscfg_device_register(&v2m_muxfpga_device);
vexpress_syscfg_device_register(&v2m_shutdown_device);
vexpress_syscfg_device_register(&v2m_reboot_device);
vexpress_syscfg_device_register(&v2m_dvimode_device);
ct_desc->init_tile();
}
