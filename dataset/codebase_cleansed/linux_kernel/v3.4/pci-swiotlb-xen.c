int __init pci_xen_swiotlb_detect(void)
{
if ((xen_initial_domain() || swiotlb || swiotlb_force) &&
(xen_pv_domain()))
xen_swiotlb = 1;
if (xen_pv_domain())
swiotlb = 0;
return xen_swiotlb;
}
void __init pci_xen_swiotlb_init(void)
{
if (xen_swiotlb) {
xen_swiotlb_init(1);
dma_ops = &xen_swiotlb_dma_ops;
pci_request_acs();
}
}
