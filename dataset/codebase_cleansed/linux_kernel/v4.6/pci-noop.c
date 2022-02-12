struct pci_controller * __init
alloc_pci_controller(void)
{
struct pci_controller *hose;
hose = alloc_bootmem(sizeof(*hose));
*hose_tail = hose;
hose_tail = &hose->next;
return hose;
}
struct resource * __init
alloc_resource(void)
{
struct resource *res;
res = alloc_bootmem(sizeof(*res));
return res;
}
asmlinkage long
sys_pciconfig_iobase(long which, unsigned long bus, unsigned long dfn)
{
struct pci_controller *hose;
if (which & IOBASE_FROM_HOSE) {
for (hose = hose_head; hose; hose = hose->next)
if (hose->index == bus)
break;
if (!hose)
return -ENODEV;
} else {
if (bus == 0 && dfn == 0)
hose = pci_isa_hose;
else
return -ENODEV;
}
switch (which & ~IOBASE_FROM_HOSE) {
case IOBASE_HOSE:
return hose->index;
case IOBASE_SPARSE_MEM:
return hose->sparse_mem_base;
case IOBASE_DENSE_MEM:
return hose->dense_mem_base;
case IOBASE_SPARSE_IO:
return hose->sparse_io_base;
case IOBASE_DENSE_IO:
return hose->dense_io_base;
case IOBASE_ROOT_BUS:
return hose->bus->number;
}
return -EOPNOTSUPP;
}
asmlinkage long
sys_pciconfig_read(unsigned long bus, unsigned long dfn,
unsigned long off, unsigned long len, void *buf)
{
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
else
return -ENODEV;
}
asmlinkage long
sys_pciconfig_write(unsigned long bus, unsigned long dfn,
unsigned long off, unsigned long len, void *buf)
{
if (!capable(CAP_SYS_ADMIN))
return -EPERM;
else
return -ENODEV;
}
static void *alpha_noop_alloc_coherent(struct device *dev, size_t size,
dma_addr_t *dma_handle, gfp_t gfp,
struct dma_attrs *attrs)
{
void *ret;
if (!dev || *dev->dma_mask >= 0xffffffffUL)
gfp &= ~GFP_DMA;
ret = (void *)__get_free_pages(gfp, get_order(size));
if (ret) {
memset(ret, 0, size);
*dma_handle = virt_to_phys(ret);
}
return ret;
}
static int alpha_noop_supported(struct device *dev, u64 mask)
{
return mask < 0x00ffffffUL ? 0 : 1;
}
