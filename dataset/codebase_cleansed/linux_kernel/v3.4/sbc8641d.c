static void __init
sbc8641_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
#endif
if (ppc_md.progress)
ppc_md.progress("sbc8641_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,mpc8641-pcie")
fsl_add_bridge(np, 0);
#endif
printk("SBC8641 board from Wind River\n");
#ifdef CONFIG_SMP
mpc86xx_smp_init();
#endif
}
static void
sbc8641_show_cpuinfo(struct seq_file *m)
{
uint svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: Wind River Systems\n");
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
}
static int __init sbc8641_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "wind,sbc8641"))
return 1;
return 0;
}
static long __init
mpc86xx_time_init(void)
{
unsigned int temp;
mtspr(SPRN_TBWL, 0);
mtspr(SPRN_TBWU, 0);
temp = mfspr(SPRN_HID0);
temp |= HID0_TBEN;
mtspr(SPRN_HID0, temp);
asm volatile("isync");
return 0;
}
static int __init declare_of_platform_devices(void)
{
of_platform_bus_probe(NULL, of_bus_ids, NULL);
return 0;
}
