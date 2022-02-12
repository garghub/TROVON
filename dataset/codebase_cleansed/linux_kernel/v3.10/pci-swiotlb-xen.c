int __init pci_xen_swiotlb_detect(void)
{
if (!xen_pv_domain())
return 0;
if ((xen_initial_domain() || swiotlb || swiotlb_force))
xen_swiotlb = 1;
swiotlb = 0;
#ifdef CONFIG_X86_64
if (max_pfn > MAX_DMA32_PFN)
no_iommu = 1;
#endif
return xen_swiotlb;
}
void __init pci_xen_swiotlb_init(void)
{
if (xen_swiotlb) {
xen_swiotlb_init(1, true );
dma_ops = &xen_swiotlb_dma_ops;
pci_request_acs();
}
}
int pci_xen_swiotlb_init_late(void)
{
int rc;
if (xen_swiotlb)
return 0;
rc = xen_swiotlb_init(1, false );
if (rc)
return rc;
dma_ops = &xen_swiotlb_dma_ops;
pci_request_acs();
return 0;
}
