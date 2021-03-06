static void __init tegra_init_cache(void)
{
#ifdef CONFIG_CACHE_L2X0
int ret;
void __iomem *p = IO_ADDRESS(TEGRA_ARM_PERIF_BASE) + 0x3000;
u32 aux_ctrl, cache_type;
cache_type = readl(p + L2X0_CACHE_TYPE);
aux_ctrl = (cache_type & 0x700) << (17-8);
aux_ctrl |= 0x7C400001;
ret = l2x0_of_init(aux_ctrl, 0x8200c3fe);
if (!ret)
l2x0_saved_regs_addr = virt_to_phys(&l2x0_saved_regs);
#endif
}
static void __init tegra_init_early(void)
{
tegra_apb_io_init();
tegra_init_fuse();
tegra_cpu_reset_handler_init();
tegra_init_cache();
tegra_powergate_init();
tegra_hotplug_init();
}
static void __init tegra_dt_init_irq(void)
{
tegra_pmc_init_irq();
tegra_init_irq();
irqchip_init();
tegra_legacy_irq_syscore_init();
}
static void __init tegra_dt_init(void)
{
struct soc_device_attribute *soc_dev_attr;
struct soc_device *soc_dev;
struct device *parent = NULL;
tegra_pmc_init();
tegra_clocks_apply_init_table();
soc_dev_attr = kzalloc(sizeof(*soc_dev_attr), GFP_KERNEL);
if (!soc_dev_attr)
goto out;
soc_dev_attr->family = kasprintf(GFP_KERNEL, "Tegra");
soc_dev_attr->revision = kasprintf(GFP_KERNEL, "%d", tegra_revision);
soc_dev_attr->soc_id = kasprintf(GFP_KERNEL, "%d", tegra_chip_id);
soc_dev = soc_device_register(soc_dev_attr);
if (IS_ERR(soc_dev)) {
kfree(soc_dev_attr->family);
kfree(soc_dev_attr->revision);
kfree(soc_dev_attr->soc_id);
kfree(soc_dev_attr);
goto out;
}
parent = soc_device_to_device(soc_dev);
out:
of_platform_populate(NULL, of_default_bus_match_table, NULL, parent);
}
static void __init paz00_init(void)
{
if (IS_ENABLED(CONFIG_ARCH_TEGRA_2x_SOC))
tegra_paz00_wifikill_init();
}
static void __init tegra_dt_init_late(void)
{
int i;
tegra_init_suspend();
tegra_cpuidle_init();
tegra_powergate_debugfs_init();
for (i = 0; i < ARRAY_SIZE(board_init_funcs); i++) {
if (of_machine_is_compatible(board_init_funcs[i].machine)) {
board_init_funcs[i].init();
break;
}
}
}
