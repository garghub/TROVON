static int mpc86xx_exclude_device(struct pci_controller *hose,
u_char bus, u_char devfn)
{
struct device_node* node;
struct resource rsrc;
node = hose->dn;
of_address_to_resource(node, 0, &rsrc);
if ((rsrc.start & 0xfffff) == 0x8000) {
return uli_exclude_device(hose, bus, devfn);
}
return PCIBIOS_SUCCESSFUL;
}
static void __init
mpc86xx_hpcn_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
struct pci_controller *hose;
#endif
dma_addr_t max = 0xffffffff;
if (ppc_md.progress)
ppc_md.progress("mpc86xx_hpcn_setup_arch()", 0);
#ifdef CONFIG_PCI
for_each_compatible_node(np, "pci", "fsl,mpc8641-pcie") {
struct resource rsrc;
of_address_to_resource(np, 0, &rsrc);
if ((rsrc.start & 0xfffff) == 0x8000)
fsl_add_bridge(np, 1);
else
fsl_add_bridge(np, 0);
hose = pci_find_hose_for_OF_device(np);
max = min(max, hose->dma_window_base_cur +
hose->dma_window_size);
}
ppc_md.pci_exclude_device = mpc86xx_exclude_device;
#endif
printk("MPC86xx HPCN board from Freescale Semiconductor\n");
#ifdef CONFIG_SMP
mpc86xx_smp_init();
#endif
#ifdef CONFIG_SWIOTLB
if (memblock_end_of_DRAM() > max) {
ppc_swiotlb_enable = 1;
set_pci_dma_ops(&swiotlb_dma_ops);
ppc_md.pci_dma_dev_setup = pci_dma_dev_setup_swiotlb;
}
#endif
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
