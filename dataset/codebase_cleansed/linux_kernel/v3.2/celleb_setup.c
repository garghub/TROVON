static void celleb_show_cpuinfo(struct seq_file *m)
{
struct device_node *root;
const char *model = "";
root = of_find_node_by_path("/");
if (root)
model = of_get_property(root, "model", NULL);
seq_printf(m, "machine\t\t: %s %s\n", celleb_machine_type, model);
of_node_put(root);
}
static int __init celleb_machine_type_hack(char *ptr)
{
strlcpy(celleb_machine_type, ptr, sizeof(celleb_machine_type));
return 0;
}
static void celleb_progress(char *s, unsigned short hex)
{
printk("*** %04x : %s\n", hex, s ? s : "");
}
static void __init celleb_setup_arch_common(void)
{
loops_per_jiffy = 50000000;
#ifdef CONFIG_DUMMY_CONSOLE
conswitchp = &dummy_con;
#endif
}
static int __init celleb_publish_devices(void)
{
of_platform_bus_probe(NULL, celleb_bus_ids, NULL);
return 0;
}
static void __init celleb_setup_arch_beat(void)
{
#ifdef CONFIG_SPU_BASE
spu_priv1_ops = &spu_priv1_beat_ops;
spu_management_ops = &spu_management_of_ops;
#endif
celleb_setup_arch_common();
}
static int __init celleb_probe_beat(void)
{
unsigned long root = of_get_flat_dt_root();
if (!of_flat_dt_is_compatible(root, "Beat"))
return 0;
powerpc_firmware_features |= FW_FEATURE_CELLEB_ALWAYS
| FW_FEATURE_BEAT | FW_FEATURE_LPAR;
hpte_init_beat_v3();
return 1;
}
static void __init celleb_init_IRQ_native(void)
{
iic_init_IRQ();
spider_init_IRQ();
}
static void __init celleb_setup_arch_native(void)
{
#ifdef CONFIG_SPU_BASE
spu_priv1_ops = &spu_priv1_mmio_ops;
spu_management_ops = &spu_management_of_ops;
#endif
cbe_regs_init();
#ifdef CONFIG_CBE_RAS
cbe_ras_init();
#endif
#ifdef CONFIG_SMP
smp_init_cell();
#endif
cbe_pervasive_init();
celleb_setup_arch_common();
}
static int __init celleb_probe_native(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "Beat") ||
!of_flat_dt_is_compatible(root, "TOSHIBA,Celleb"))
return 0;
powerpc_firmware_features |= FW_FEATURE_CELLEB_ALWAYS;
hpte_init_native();
return 1;
}
