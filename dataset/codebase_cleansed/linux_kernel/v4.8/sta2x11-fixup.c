static void sta2x11_new_instance(struct pci_dev *pdev)
{
struct sta2x11_instance *instance;
instance = kzalloc(sizeof(*instance), GFP_ATOMIC);
if (!instance)
return;
instance->bus0 = pdev->subordinate->number + 1;
if (list_empty(&sta2x11_instance_list)) {
int size = STA2X11_SWIOTLB_SIZE;
dev_info(&pdev->dev, "Using SWIOTLB (size %i)\n", size);
if (swiotlb_late_init_with_default_size(size))
dev_emerg(&pdev->dev, "init swiotlb failed\n");
}
list_add(&instance->list, &sta2x11_instance_list);
}
static struct sta2x11_instance *sta2x11_pdev_to_instance(struct pci_dev *pdev)
{
struct sta2x11_instance *instance;
int ep;
list_for_each_entry(instance, &sta2x11_instance_list, list) {
ep = pdev->bus->number - instance->bus0;
if (ep >= 0 && ep < STA2X11_NR_EP)
return instance;
}
return NULL;
}
static int sta2x11_pdev_to_ep(struct pci_dev *pdev)
{
struct sta2x11_instance *instance;
instance = sta2x11_pdev_to_instance(pdev);
if (!instance)
return -1;
return pdev->bus->number - instance->bus0;
}
static struct sta2x11_mapping *sta2x11_pdev_to_mapping(struct pci_dev *pdev)
{
struct sta2x11_instance *instance;
int ep;
instance = sta2x11_pdev_to_instance(pdev);
if (!instance)
return NULL;
ep = sta2x11_pdev_to_ep(pdev);
return instance->map + ep;
}
struct sta2x11_instance *sta2x11_get_instance(struct pci_dev *pdev)
{
return sta2x11_pdev_to_instance(pdev);
}
static dma_addr_t p2a(dma_addr_t p, struct pci_dev *pdev)
{
struct sta2x11_mapping *map;
dma_addr_t a;
map = sta2x11_pdev_to_mapping(pdev);
a = p + map->amba_base;
return a;
}
static dma_addr_t a2p(dma_addr_t a, struct pci_dev *pdev)
{
struct sta2x11_mapping *map;
dma_addr_t p;
map = sta2x11_pdev_to_mapping(pdev);
p = a - map->amba_base;
return p;
}
static void *sta2x11_swiotlb_alloc_coherent(struct device *dev,
size_t size,
dma_addr_t *dma_handle,
gfp_t flags,
unsigned long attrs)
{
void *vaddr;
vaddr = x86_swiotlb_alloc_coherent(dev, size, dma_handle, flags, attrs);
*dma_handle = p2a(*dma_handle, to_pci_dev(dev));
return vaddr;
}
static void sta2x11_setup_pdev(struct pci_dev *pdev)
{
struct sta2x11_instance *instance = sta2x11_pdev_to_instance(pdev);
if (!instance)
return;
pci_set_consistent_dma_mask(pdev, STA2X11_AMBA_SIZE - 1);
pci_set_dma_mask(pdev, STA2X11_AMBA_SIZE - 1);
pdev->dev.archdata.dma_ops = &sta2x11_dma_ops;
pci_set_master(pdev);
}
bool dma_capable(struct device *dev, dma_addr_t addr, size_t size)
{
struct sta2x11_mapping *map;
if (dev->archdata.dma_ops != &sta2x11_dma_ops) {
if (!dev->dma_mask)
return false;
return addr + size - 1 <= *dev->dma_mask;
}
map = sta2x11_pdev_to_mapping(to_pci_dev(dev));
if (!map || (addr < map->amba_base))
return false;
if (addr + size >= map->amba_base + STA2X11_AMBA_SIZE) {
return false;
}
return true;
}
dma_addr_t phys_to_dma(struct device *dev, phys_addr_t paddr)
{
if (dev->archdata.dma_ops != &sta2x11_dma_ops)
return paddr;
return p2a(paddr, to_pci_dev(dev));
}
phys_addr_t dma_to_phys(struct device *dev, dma_addr_t daddr)
{
if (dev->archdata.dma_ops != &sta2x11_dma_ops)
return daddr;
return a2p(daddr, to_pci_dev(dev));
}
static void sta2x11_map_ep(struct pci_dev *pdev)
{
struct sta2x11_mapping *map = sta2x11_pdev_to_mapping(pdev);
int i;
if (!map)
return;
pci_read_config_dword(pdev, AHB_BASE(0), &map->amba_base);
pci_write_config_dword(pdev, AHB_PEXLBASE(0), 0);
pci_write_config_dword(pdev, AHB_PEXHBASE(0), 0);
pci_write_config_dword(pdev, AHB_CRW(0), STA2X11_AMBA_SIZE |
AHB_CRW_WTYPE_MEM | AHB_CRW_ENABLE);
for (i = 1; i < STA2X11_NR_FUNCS; i++)
pci_write_config_dword(pdev, AHB_CRW(i), 0);
dev_info(&pdev->dev,
"sta2x11: Map EP %i: AMBA address %#8x-%#8x\n",
sta2x11_pdev_to_ep(pdev), map->amba_base,
map->amba_base + STA2X11_AMBA_SIZE - 1);
}
static void suspend_mapping(struct pci_dev *pdev)
{
struct sta2x11_mapping *map = sta2x11_pdev_to_mapping(pdev);
int i;
if (!map)
return;
if (map->is_suspended)
return;
map->is_suspended = 1;
for (i = 0; i < STA2X11_NR_FUNCS; i++) {
struct sta2x11_ahb_regs *regs = map->regs + i;
pci_read_config_dword(pdev, AHB_BASE(i), &regs->base);
pci_read_config_dword(pdev, AHB_PEXLBASE(i), &regs->pexlbase);
pci_read_config_dword(pdev, AHB_PEXHBASE(i), &regs->pexhbase);
pci_read_config_dword(pdev, AHB_CRW(i), &regs->crw);
}
}
static void resume_mapping(struct pci_dev *pdev)
{
struct sta2x11_mapping *map = sta2x11_pdev_to_mapping(pdev);
int i;
if (!map)
return;
if (!map->is_suspended)
goto out;
map->is_suspended = 0;
for (i = 0; i < STA2X11_NR_FUNCS; i++) {
struct sta2x11_ahb_regs *regs = map->regs + i;
pci_write_config_dword(pdev, AHB_BASE(i), regs->base);
pci_write_config_dword(pdev, AHB_PEXLBASE(i), regs->pexlbase);
pci_write_config_dword(pdev, AHB_PEXHBASE(i), regs->pexhbase);
pci_write_config_dword(pdev, AHB_CRW(i), regs->crw);
}
out:
pci_set_master(pdev);
}
