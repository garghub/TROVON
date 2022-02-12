void __iomem *iorpc_ioremap(int hv_fd, resource_size_t offset,
unsigned long size)
{
pgprot_t mmio_base, prot = { 0 };
unsigned long pfn;
int err;
err = __iorpc_get_mmio_base(hv_fd, &mmio_base);
if (err) {
TRACE("get_mmio_base() failure: %d\n", err);
return NULL;
}
err = __iorpc_check_mmio_offset(hv_fd, offset, size);
if (err) {
TRACE("check_mmio_offset() failure: %d\n", err);
return NULL;
}
prot = hv_pte_set_lotar(prot, hv_pte_get_lotar(mmio_base));
pfn = pte_pfn(mmio_base) + PFN_DOWN(offset);
return ioremap_prot(PFN_PHYS(pfn), size, prot);
}
