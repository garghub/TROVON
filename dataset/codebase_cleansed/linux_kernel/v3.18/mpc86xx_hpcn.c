static int mpc86xx_exclude_device(struct pci_controller *hose,
u_char bus, u_char devfn)
{
if (hose->dn == fsl_pci_primary)
return uli_exclude_device(hose, bus, devfn);
return PCIBIOS_SUCCESSFUL;
}
static void __init
mpc86xx_hpcn_setup_arch(void)
{
if (ppc_md.progress)
ppc_md.progress("mpc86xx_hpcn_setup_arch()", 0);
#ifdef CONFIG_PCI
ppc_md.pci_exclude_device = mpc86xx_exclude_device;
#endif
printk("MPC86xx HPCN board from Freescale Semiconductor\n");
#ifdef CONFIG_SMP
mpc86xx_smp_init();
#endif
fsl_pci_assign_primary();
swiotlb_detect_4g();
}
static void
mpc86xx_hpcn_show_cpuinfo(struct seq_file *m)
{
uint svid = mfspr(SPRN_SVR);
seq_printf(m, "Vendor\t\t: Freescale Semiconductor\n");
seq_printf(m, "SVR\t\t: 0x%x\n", svid);
}
static int __init mpc86xx_hpcn_probe(void)
{
unsigned long root = of_get_flat_dt_root();
if (of_flat_dt_is_compatible(root, "fsl,mpc8641hpcn"))
return 1;
if (of_flat_dt_is_compatible(root, "mpc86xx")) {
pr_warning("WARNING: your dts/dtb is old. You must update before the next kernel release\n");
return 1;
}
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
