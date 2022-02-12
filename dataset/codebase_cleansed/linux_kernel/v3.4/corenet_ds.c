void __init corenet_ds_pic_init(void)
{
struct mpic *mpic;
unsigned int flags = MPIC_BIG_ENDIAN | MPIC_SINGLE_DEST_CPU |
MPIC_NO_RESET;
if (ppc_md.get_irq == mpic_get_coreint_irq)
flags |= MPIC_ENABLE_COREINT;
mpic = mpic_alloc(NULL, 0, flags, 0, 256, " OpenPIC ");
BUG_ON(mpic == NULL);
mpic_init(mpic);
}
void __init corenet_ds_setup_arch(void)
{
#ifdef CONFIG_PCI
struct device_node *np;
struct pci_controller *hose;
#endif
dma_addr_t max = 0xffffffff;
mpc85xx_smp_init();
#ifdef CONFIG_PCI
for_each_node_by_type(np, "pci") {
if (of_device_is_compatible(np, "fsl,p4080-pcie") ||
of_device_is_compatible(np, "fsl,qoriq-pcie-v2.2")) {
fsl_add_bridge(np, 0);
hose = pci_find_hose_for_OF_device(np);
max = min(max, hose->dma_window_base_cur +
hose->dma_window_size);
}
}
#ifdef CONFIG_PPC64
pci_devs_phb_init();
#endif
#endif
#ifdef CONFIG_SWIOTLB
if (memblock_end_of_DRAM() > max) {
ppc_swiotlb_enable = 1;
set_pci_dma_ops(&swiotlb_dma_ops);
ppc_md.pci_dma_dev_setup = pci_dma_dev_setup_swiotlb;
}
#endif
pr_info("%s board from Freescale Semiconductor\n", ppc_md.name);
}
int __init corenet_ds_publish_devices(void)
{
return of_platform_bus_probe(NULL, of_device_ids, NULL);
}
