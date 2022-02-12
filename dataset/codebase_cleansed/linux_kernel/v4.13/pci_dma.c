static int sn_dma_supported(struct device *dev, u64 mask)
{
BUG_ON(!dev_is_pci(dev));
if (mask < 0x7fffffff)
return 0;
return 1;
}
int sn_dma_set_mask(struct device *dev, u64 dma_mask)
{
BUG_ON(!dev_is_pci(dev));
if (!sn_dma_supported(dev, dma_mask))
return 0;
*dev->dma_mask = dma_mask;
return 1;
}
static void *sn_dma_alloc_coherent(struct device *dev, size_t size,
dma_addr_t * dma_handle, gfp_t flags,
unsigned long attrs)
{
void *cpuaddr;
unsigned long phys_addr;
int node;
struct pci_dev *pdev = to_pci_dev(dev);
struct sn_pcibus_provider *provider = SN_PCIDEV_BUSPROVIDER(pdev);
BUG_ON(!dev_is_pci(dev));
node = pcibus_to_node(pdev->bus);
if (likely(node >=0)) {
struct page *p = __alloc_pages_node(node,
flags, get_order(size));
if (likely(p))
cpuaddr = page_address(p);
else
return NULL;
} else
cpuaddr = (void *)__get_free_pages(flags, get_order(size));
if (unlikely(!cpuaddr))
return NULL;
memset(cpuaddr, 0x0, size);
phys_addr = __pa(cpuaddr);
*dma_handle = provider->dma_map_consistent(pdev, phys_addr, size,
SN_DMA_ADDR_PHYS);
if (!*dma_handle) {
printk(KERN_ERR "%s: out of ATEs\n", __func__);
free_pages((unsigned long)cpuaddr, get_order(size));
return NULL;
}
return cpuaddr;
}
static void sn_dma_free_coherent(struct device *dev, size_t size, void *cpu_addr,
dma_addr_t dma_handle, unsigned long attrs)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct sn_pcibus_provider *provider = SN_PCIDEV_BUSPROVIDER(pdev);
BUG_ON(!dev_is_pci(dev));
provider->dma_unmap(pdev, dma_handle, 0);
free_pages((unsigned long)cpu_addr, get_order(size));
}
static dma_addr_t sn_dma_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
unsigned long attrs)
{
void *cpu_addr = page_address(page) + offset;
dma_addr_t dma_addr;
unsigned long phys_addr;
struct pci_dev *pdev = to_pci_dev(dev);
struct sn_pcibus_provider *provider = SN_PCIDEV_BUSPROVIDER(pdev);
BUG_ON(!dev_is_pci(dev));
phys_addr = __pa(cpu_addr);
if (attrs & DMA_ATTR_WRITE_BARRIER)
dma_addr = provider->dma_map_consistent(pdev, phys_addr,
size, SN_DMA_ADDR_PHYS);
else
dma_addr = provider->dma_map(pdev, phys_addr, size,
SN_DMA_ADDR_PHYS);
if (!dma_addr) {
printk(KERN_ERR "%s: out of ATEs\n", __func__);
return 0;
}
return dma_addr;
}
static void sn_dma_unmap_page(struct device *dev, dma_addr_t dma_addr,
size_t size, enum dma_data_direction dir,
unsigned long attrs)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct sn_pcibus_provider *provider = SN_PCIDEV_BUSPROVIDER(pdev);
BUG_ON(!dev_is_pci(dev));
provider->dma_unmap(pdev, dma_addr, dir);
}
static void sn_dma_unmap_sg(struct device *dev, struct scatterlist *sgl,
int nhwentries, enum dma_data_direction dir,
unsigned long attrs)
{
int i;
struct pci_dev *pdev = to_pci_dev(dev);
struct sn_pcibus_provider *provider = SN_PCIDEV_BUSPROVIDER(pdev);
struct scatterlist *sg;
BUG_ON(!dev_is_pci(dev));
for_each_sg(sgl, sg, nhwentries, i) {
provider->dma_unmap(pdev, sg->dma_address, dir);
sg->dma_address = (dma_addr_t) NULL;
sg->dma_length = 0;
}
}
static int sn_dma_map_sg(struct device *dev, struct scatterlist *sgl,
int nhwentries, enum dma_data_direction dir,
unsigned long attrs)
{
unsigned long phys_addr;
struct scatterlist *saved_sg = sgl, *sg;
struct pci_dev *pdev = to_pci_dev(dev);
struct sn_pcibus_provider *provider = SN_PCIDEV_BUSPROVIDER(pdev);
int i;
BUG_ON(!dev_is_pci(dev));
for_each_sg(sgl, sg, nhwentries, i) {
dma_addr_t dma_addr;
phys_addr = SG_ENT_PHYS_ADDRESS(sg);
if (attrs & DMA_ATTR_WRITE_BARRIER)
dma_addr = provider->dma_map_consistent(pdev,
phys_addr,
sg->length,
SN_DMA_ADDR_PHYS);
else
dma_addr = provider->dma_map(pdev, phys_addr,
sg->length,
SN_DMA_ADDR_PHYS);
sg->dma_address = dma_addr;
if (!sg->dma_address) {
printk(KERN_ERR "%s: out of ATEs\n", __func__);
if (i > 0)
sn_dma_unmap_sg(dev, saved_sg, i, dir, attrs);
return 0;
}
sg->dma_length = sg->length;
}
return nhwentries;
}
static void sn_dma_sync_single_for_cpu(struct device *dev, dma_addr_t dma_handle,
size_t size, enum dma_data_direction dir)
{
BUG_ON(!dev_is_pci(dev));
}
static void sn_dma_sync_single_for_device(struct device *dev, dma_addr_t dma_handle,
size_t size,
enum dma_data_direction dir)
{
BUG_ON(!dev_is_pci(dev));
}
static void sn_dma_sync_sg_for_cpu(struct device *dev, struct scatterlist *sg,
int nelems, enum dma_data_direction dir)
{
BUG_ON(!dev_is_pci(dev));
}
static void sn_dma_sync_sg_for_device(struct device *dev, struct scatterlist *sg,
int nelems, enum dma_data_direction dir)
{
BUG_ON(!dev_is_pci(dev));
}
static int sn_dma_mapping_error(struct device *dev, dma_addr_t dma_addr)
{
return 0;
}
u64 sn_dma_get_required_mask(struct device *dev)
{
return DMA_BIT_MASK(64);
}
char *sn_pci_get_legacy_mem(struct pci_bus *bus)
{
if (!SN_PCIBUS_BUSSOFT(bus))
return ERR_PTR(-ENODEV);
return (char *)(SN_PCIBUS_BUSSOFT(bus)->bs_legacy_mem | __IA64_UNCACHED_OFFSET);
}
int sn_pci_legacy_read(struct pci_bus *bus, u16 port, u32 *val, u8 size)
{
unsigned long addr;
int ret;
struct ia64_sal_retval isrv;
SAL_CALL(isrv, SN_SAL_IOIF_PCI_SAFE,
pci_domain_nr(bus), bus->number,
0,
0,
port, size, __pa(val));
if (isrv.status == 0)
return size;
if (!SN_PCIBUS_BUSSOFT(bus))
return -ENODEV;
addr = SN_PCIBUS_BUSSOFT(bus)->bs_legacy_io | __IA64_UNCACHED_OFFSET;
addr += port;
ret = ia64_sn_probe_mem(addr, (long)size, (void *)val);
if (ret == 2)
return -EINVAL;
if (ret == 1)
*val = -1;
return size;
}
int sn_pci_legacy_write(struct pci_bus *bus, u16 port, u32 val, u8 size)
{
int ret = size;
unsigned long paddr;
unsigned long *addr;
struct ia64_sal_retval isrv;
SAL_CALL(isrv, SN_SAL_IOIF_PCI_SAFE,
pci_domain_nr(bus), bus->number,
0,
1,
port, size, __pa(&val));
if (isrv.status == 0)
return size;
if (!SN_PCIBUS_BUSSOFT(bus)) {
ret = -ENODEV;
goto out;
}
paddr = SN_PCIBUS_BUSSOFT(bus)->bs_legacy_io | __IA64_UNCACHED_OFFSET;
paddr += port;
addr = (unsigned long *)paddr;
switch (size) {
case 1:
*(volatile u8 *)(addr) = (u8)(val);
break;
case 2:
*(volatile u16 *)(addr) = (u16)(val);
break;
case 4:
*(volatile u32 *)(addr) = (u32)(val);
break;
default:
ret = -EINVAL;
break;
}
out:
return ret;
}
void sn_dma_init(void)
{
dma_ops = &sn_dma_ops;
}
