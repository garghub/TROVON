static int ccio_dma_supported( struct pci_dev *dev, u64 mask)
{
if (dev == NULL) {
printk(KERN_ERR MODULE_NAME ": EISA/ISA/et al not supported\n");
BUG();
return(0);
}
return((int) (mask >= 0xffffffffUL));
}
static void *ccio_alloc_consistent(struct pci_dev *dev, size_t size,
dma_addr_t *handle)
{
void *ret;
ret = (void *)__get_free_pages(GFP_ATOMIC, get_order(size));
if (ret != NULL) {
memset(ret, 0, size);
*handle = virt_to_phys(ret);
}
return ret;
}
static void ccio_free_consistent(struct pci_dev *dev, size_t size,
void *vaddr, dma_addr_t handle)
{
free_pages((unsigned long)vaddr, get_order(size));
}
static dma_addr_t ccio_map_single(struct pci_dev *dev, void *ptr, size_t size,
int direction)
{
return virt_to_phys(ptr);
}
static void ccio_unmap_single(struct pci_dev *dev, dma_addr_t dma_addr,
size_t size, int direction)
{
}
static int ccio_map_sg(struct pci_dev *dev, struct scatterlist *sglist, int nents, int direction)
{
int tmp = nents;
while (nents) {
sg_dma_address(sglist) = ccio_map_single(dev, sglist->address, sglist->length, direction);
sg_dma_len(sglist) = sglist->length;
nents--;
sglist++;
}
return tmp;
}
static void ccio_unmap_sg(struct pci_dev *dev, struct scatterlist *sglist, int nents, int direction)
{
#if 0
while (nents) {
ccio_unmap_single(dev, sg_dma_address(sglist), sg_dma_len(sglist), direction);
nents--;
sglist++;
}
return;
#else
#endif
}
static int
ccio_probe(struct parisc_device *dev)
{
printk(KERN_INFO "%s found %s at 0x%lx\n", MODULE_NAME,
dev->id.hversion == U2_BC_GSC ? "U2" : "UTurn",
dev->hpa.start);
#if 0
ccio_hw_init(ccio_dev);
ccio_common_init(ccio_dev);
#endif
hppa_dma_ops = &ccio_ops;
return 0;
}
void __init ccio_init(void)
{
register_parisc_driver(&ccio_driver);
}
