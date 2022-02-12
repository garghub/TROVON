static int __init cpu8815_init(void)
{
int i;
platform_add_devices(platform_devs, ARRAY_SIZE(platform_devs));
for (i = 0; i < ARRAY_SIZE(amba_devs); i++)
amba_device_register(amba_devs[i], &iomem_resource);
return 0;
}
void __init cpu8815_map_io(void)
{
iotable_init(nomadik_io_desc, ARRAY_SIZE(nomadik_io_desc));
}
void __init cpu8815_init_irq(void)
{
vic_init(io_p2v(NOMADIK_IC_BASE + 0x00), IRQ_VIC_START + 0, ~0, 0);
vic_init(io_p2v(NOMADIK_IC_BASE + 0x20), IRQ_VIC_START + 32, ~0, 0);
clk_init();
}
void __init cpu8815_platform_init(void)
{
#ifdef CONFIG_CACHE_L2X0
l2x0_init(io_p2v(NOMADIK_L2CC_BASE), 0x00730249, 0xfe000fff);
#endif
return;
}
void cpu8815_restart(char mode, const char *cmd)
{
void __iomem *src_rstsr = io_p2v(NOMADIK_SRC_BASE + 0x18);
writel(1, src_rstsr);
}
