static inline struct vmd_dev *vmd_from_bus(struct pci_bus *bus)
{
return container_of(bus->sysdata, struct vmd_dev, sysdata);
}
static void vmd_compose_msi_msg(struct irq_data *data, struct msi_msg *msg)
{
struct vmd_irq *vmdirq = data->chip_data;
struct vmd_irq_list *irq = vmdirq->irq;
msg->address_hi = MSI_ADDR_BASE_HI;
msg->address_lo = MSI_ADDR_BASE_LO | MSI_ADDR_DEST_ID(irq->index);
msg->data = 0;
}
static void vmd_irq_enable(struct irq_data *data)
{
struct vmd_irq *vmdirq = data->chip_data;
raw_spin_lock(&list_lock);
list_add_tail_rcu(&vmdirq->node, &vmdirq->irq->irq_list);
raw_spin_unlock(&list_lock);
data->chip->irq_unmask(data);
}
static void vmd_irq_disable(struct irq_data *data)
{
struct vmd_irq *vmdirq = data->chip_data;
data->chip->irq_mask(data);
raw_spin_lock(&list_lock);
list_del_rcu(&vmdirq->node);
raw_spin_unlock(&list_lock);
}
static int vmd_irq_set_affinity(struct irq_data *data,
const struct cpumask *dest, bool force)
{
return -EINVAL;
}
static irq_hw_number_t vmd_get_hwirq(struct msi_domain_info *info,
msi_alloc_info_t *arg)
{
return 0;
}
static struct vmd_irq_list *vmd_next_irq(struct vmd_dev *vmd)
{
int i, best = 0;
raw_spin_lock(&list_lock);
for (i = 1; i < vmd->msix_count; i++)
if (vmd->irqs[i].count < vmd->irqs[best].count)
best = i;
vmd->irqs[best].count++;
raw_spin_unlock(&list_lock);
return &vmd->irqs[best];
}
static int vmd_msi_init(struct irq_domain *domain, struct msi_domain_info *info,
unsigned int virq, irq_hw_number_t hwirq,
msi_alloc_info_t *arg)
{
struct vmd_dev *vmd = vmd_from_bus(msi_desc_to_pci_dev(arg->desc)->bus);
struct vmd_irq *vmdirq = kzalloc(sizeof(*vmdirq), GFP_KERNEL);
if (!vmdirq)
return -ENOMEM;
INIT_LIST_HEAD(&vmdirq->node);
vmdirq->irq = vmd_next_irq(vmd);
vmdirq->virq = virq;
irq_domain_set_info(domain, virq, vmdirq->irq->vmd_vector, info->chip,
vmdirq, handle_simple_irq, vmd, NULL);
return 0;
}
static void vmd_msi_free(struct irq_domain *domain,
struct msi_domain_info *info, unsigned int virq)
{
struct vmd_irq *vmdirq = irq_get_chip_data(virq);
raw_spin_lock(&list_lock);
vmdirq->irq->count--;
raw_spin_unlock(&list_lock);
kfree_rcu(vmdirq, rcu);
}
static int vmd_msi_prepare(struct irq_domain *domain, struct device *dev,
int nvec, msi_alloc_info_t *arg)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct vmd_dev *vmd = vmd_from_bus(pdev->bus);
if (nvec > vmd->msix_count)
return vmd->msix_count;
memset(arg, 0, sizeof(*arg));
return 0;
}
static void vmd_set_desc(msi_alloc_info_t *arg, struct msi_desc *desc)
{
arg->desc = desc;
}
static struct device *to_vmd_dev(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct vmd_dev *vmd = vmd_from_bus(pdev->bus);
return &vmd->dev->dev;
}
static struct dma_map_ops *vmd_dma_ops(struct device *dev)
{
return to_vmd_dev(dev)->archdata.dma_ops;
}
static void *vmd_alloc(struct device *dev, size_t size, dma_addr_t *addr,
gfp_t flag, struct dma_attrs *attrs)
{
return vmd_dma_ops(dev)->alloc(to_vmd_dev(dev), size, addr, flag,
attrs);
}
static void vmd_free(struct device *dev, size_t size, void *vaddr,
dma_addr_t addr, struct dma_attrs *attrs)
{
return vmd_dma_ops(dev)->free(to_vmd_dev(dev), size, vaddr, addr,
attrs);
}
static int vmd_mmap(struct device *dev, struct vm_area_struct *vma,
void *cpu_addr, dma_addr_t addr, size_t size,
struct dma_attrs *attrs)
{
return vmd_dma_ops(dev)->mmap(to_vmd_dev(dev), vma, cpu_addr, addr,
size, attrs);
}
static int vmd_get_sgtable(struct device *dev, struct sg_table *sgt,
void *cpu_addr, dma_addr_t addr, size_t size,
struct dma_attrs *attrs)
{
return vmd_dma_ops(dev)->get_sgtable(to_vmd_dev(dev), sgt, cpu_addr,
addr, size, attrs);
}
static dma_addr_t vmd_map_page(struct device *dev, struct page *page,
unsigned long offset, size_t size,
enum dma_data_direction dir,
struct dma_attrs *attrs)
{
return vmd_dma_ops(dev)->map_page(to_vmd_dev(dev), page, offset, size,
dir, attrs);
}
static void vmd_unmap_page(struct device *dev, dma_addr_t addr, size_t size,
enum dma_data_direction dir, struct dma_attrs *attrs)
{
vmd_dma_ops(dev)->unmap_page(to_vmd_dev(dev), addr, size, dir, attrs);
}
static int vmd_map_sg(struct device *dev, struct scatterlist *sg, int nents,
enum dma_data_direction dir, struct dma_attrs *attrs)
{
return vmd_dma_ops(dev)->map_sg(to_vmd_dev(dev), sg, nents, dir, attrs);
}
static void vmd_unmap_sg(struct device *dev, struct scatterlist *sg, int nents,
enum dma_data_direction dir, struct dma_attrs *attrs)
{
vmd_dma_ops(dev)->unmap_sg(to_vmd_dev(dev), sg, nents, dir, attrs);
}
static void vmd_sync_single_for_cpu(struct device *dev, dma_addr_t addr,
size_t size, enum dma_data_direction dir)
{
vmd_dma_ops(dev)->sync_single_for_cpu(to_vmd_dev(dev), addr, size, dir);
}
static void vmd_sync_single_for_device(struct device *dev, dma_addr_t addr,
size_t size, enum dma_data_direction dir)
{
vmd_dma_ops(dev)->sync_single_for_device(to_vmd_dev(dev), addr, size,
dir);
}
static void vmd_sync_sg_for_cpu(struct device *dev, struct scatterlist *sg,
int nents, enum dma_data_direction dir)
{
vmd_dma_ops(dev)->sync_sg_for_cpu(to_vmd_dev(dev), sg, nents, dir);
}
static void vmd_sync_sg_for_device(struct device *dev, struct scatterlist *sg,
int nents, enum dma_data_direction dir)
{
vmd_dma_ops(dev)->sync_sg_for_device(to_vmd_dev(dev), sg, nents, dir);
}
static int vmd_mapping_error(struct device *dev, dma_addr_t addr)
{
return vmd_dma_ops(dev)->mapping_error(to_vmd_dev(dev), addr);
}
static int vmd_dma_supported(struct device *dev, u64 mask)
{
return vmd_dma_ops(dev)->dma_supported(to_vmd_dev(dev), mask);
}
static u64 vmd_get_required_mask(struct device *dev)
{
return vmd_dma_ops(dev)->get_required_mask(to_vmd_dev(dev));
}
static void vmd_teardown_dma_ops(struct vmd_dev *vmd)
{
struct dma_domain *domain = &vmd->dma_domain;
if (vmd->dev->dev.archdata.dma_ops)
del_dma_domain(domain);
}
static void vmd_setup_dma_ops(struct vmd_dev *vmd)
{
const struct dma_map_ops *source = vmd->dev->dev.archdata.dma_ops;
struct dma_map_ops *dest = &vmd->dma_ops;
struct dma_domain *domain = &vmd->dma_domain;
domain->domain_nr = vmd->sysdata.domain;
domain->dma_ops = dest;
if (!source)
return;
ASSIGN_VMD_DMA_OPS(source, dest, alloc);
ASSIGN_VMD_DMA_OPS(source, dest, free);
ASSIGN_VMD_DMA_OPS(source, dest, mmap);
ASSIGN_VMD_DMA_OPS(source, dest, get_sgtable);
ASSIGN_VMD_DMA_OPS(source, dest, map_page);
ASSIGN_VMD_DMA_OPS(source, dest, unmap_page);
ASSIGN_VMD_DMA_OPS(source, dest, map_sg);
ASSIGN_VMD_DMA_OPS(source, dest, unmap_sg);
ASSIGN_VMD_DMA_OPS(source, dest, sync_single_for_cpu);
ASSIGN_VMD_DMA_OPS(source, dest, sync_single_for_device);
ASSIGN_VMD_DMA_OPS(source, dest, sync_sg_for_cpu);
ASSIGN_VMD_DMA_OPS(source, dest, sync_sg_for_device);
ASSIGN_VMD_DMA_OPS(source, dest, mapping_error);
ASSIGN_VMD_DMA_OPS(source, dest, dma_supported);
#ifdef ARCH_HAS_DMA_GET_REQUIRED_MASK
ASSIGN_VMD_DMA_OPS(source, dest, get_required_mask);
#endif
add_dma_domain(domain);
}
static void vmd_teardown_dma_ops(struct vmd_dev *vmd) {}
static void vmd_setup_dma_ops(struct vmd_dev *vmd) {}
static char __iomem *vmd_cfg_addr(struct vmd_dev *vmd, struct pci_bus *bus,
unsigned int devfn, int reg, int len)
{
char __iomem *addr = vmd->cfgbar +
(bus->number << 20) + (devfn << 12) + reg;
if ((addr - vmd->cfgbar) + len >=
resource_size(&vmd->dev->resource[VMD_CFGBAR]))
return NULL;
return addr;
}
static int vmd_pci_read(struct pci_bus *bus, unsigned int devfn, int reg,
int len, u32 *value)
{
struct vmd_dev *vmd = vmd_from_bus(bus);
char __iomem *addr = vmd_cfg_addr(vmd, bus, devfn, reg, len);
unsigned long flags;
int ret = 0;
if (!addr)
return -EFAULT;
spin_lock_irqsave(&vmd->cfg_lock, flags);
switch (len) {
case 1:
*value = readb(addr);
break;
case 2:
*value = readw(addr);
break;
case 4:
*value = readl(addr);
break;
default:
ret = -EINVAL;
break;
}
spin_unlock_irqrestore(&vmd->cfg_lock, flags);
return ret;
}
static int vmd_pci_write(struct pci_bus *bus, unsigned int devfn, int reg,
int len, u32 value)
{
struct vmd_dev *vmd = vmd_from_bus(bus);
char __iomem *addr = vmd_cfg_addr(vmd, bus, devfn, reg, len);
unsigned long flags;
int ret = 0;
if (!addr)
return -EFAULT;
spin_lock_irqsave(&vmd->cfg_lock, flags);
switch (len) {
case 1:
writeb(value, addr);
readb(addr);
break;
case 2:
writew(value, addr);
readw(addr);
break;
case 4:
writel(value, addr);
readl(addr);
break;
default:
ret = -EINVAL;
break;
}
spin_unlock_irqrestore(&vmd->cfg_lock, flags);
return ret;
}
static int vmd_find_free_domain(void)
{
int domain = 0xffff;
struct pci_bus *bus = NULL;
while ((bus = pci_find_next_bus(bus)) != NULL)
domain = max_t(int, domain, pci_domain_nr(bus));
return domain + 1;
}
static int vmd_enable_domain(struct vmd_dev *vmd)
{
struct pci_sysdata *sd = &vmd->sysdata;
struct resource *res;
u32 upper_bits;
unsigned long flags;
LIST_HEAD(resources);
res = &vmd->dev->resource[VMD_CFGBAR];
vmd->resources[0] = (struct resource) {
.name = "VMD CFGBAR",
.start = res->start,
.end = (resource_size(res) >> 20) - 1,
.flags = IORESOURCE_BUS | IORESOURCE_PCI_FIXED,
};
res = &vmd->dev->resource[VMD_MEMBAR1];
upper_bits = upper_32_bits(res->end);
flags = res->flags & ~IORESOURCE_SIZEALIGN;
if (!upper_bits)
flags &= ~IORESOURCE_MEM_64;
vmd->resources[1] = (struct resource) {
.name = "VMD MEMBAR1",
.start = res->start,
.end = res->end,
.flags = flags,
};
res = &vmd->dev->resource[VMD_MEMBAR2];
upper_bits = upper_32_bits(res->end);
flags = res->flags & ~IORESOURCE_SIZEALIGN;
if (!upper_bits)
flags &= ~IORESOURCE_MEM_64;
vmd->resources[2] = (struct resource) {
.name = "VMD MEMBAR2",
.start = res->start + 0x2000,
.end = res->end,
.flags = flags,
};
sd->domain = vmd_find_free_domain();
if (sd->domain < 0)
return sd->domain;
sd->node = pcibus_to_node(vmd->dev->bus);
vmd->irq_domain = pci_msi_create_irq_domain(NULL, &vmd_msi_domain_info,
NULL);
if (!vmd->irq_domain)
return -ENODEV;
pci_add_resource(&resources, &vmd->resources[0]);
pci_add_resource(&resources, &vmd->resources[1]);
pci_add_resource(&resources, &vmd->resources[2]);
vmd->bus = pci_create_root_bus(&vmd->dev->dev, 0, &vmd_ops, sd,
&resources);
if (!vmd->bus) {
pci_free_resource_list(&resources);
irq_domain_remove(vmd->irq_domain);
return -ENODEV;
}
vmd_setup_dma_ops(vmd);
dev_set_msi_domain(&vmd->bus->dev, vmd->irq_domain);
pci_rescan_bus(vmd->bus);
WARN(sysfs_create_link(&vmd->dev->dev.kobj, &vmd->bus->dev.kobj,
"domain"), "Can't create symlink to domain\n");
return 0;
}
static irqreturn_t vmd_irq(int irq, void *data)
{
struct vmd_irq_list *irqs = data;
struct vmd_irq *vmdirq;
rcu_read_lock();
list_for_each_entry_rcu(vmdirq, &irqs->irq_list, node)
generic_handle_irq(vmdirq->virq);
rcu_read_unlock();
return IRQ_HANDLED;
}
static int vmd_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct vmd_dev *vmd;
int i, err;
if (resource_size(&dev->resource[VMD_CFGBAR]) < (1 << 20))
return -ENOMEM;
vmd = devm_kzalloc(&dev->dev, sizeof(*vmd), GFP_KERNEL);
if (!vmd)
return -ENOMEM;
vmd->dev = dev;
err = pcim_enable_device(dev);
if (err < 0)
return err;
vmd->cfgbar = pcim_iomap(dev, VMD_CFGBAR, 0);
if (!vmd->cfgbar)
return -ENOMEM;
pci_set_master(dev);
if (dma_set_mask_and_coherent(&dev->dev, DMA_BIT_MASK(64)) &&
dma_set_mask_and_coherent(&dev->dev, DMA_BIT_MASK(32)))
return -ENODEV;
vmd->msix_count = pci_msix_vec_count(dev);
if (vmd->msix_count < 0)
return -ENODEV;
vmd->irqs = devm_kcalloc(&dev->dev, vmd->msix_count, sizeof(*vmd->irqs),
GFP_KERNEL);
if (!vmd->irqs)
return -ENOMEM;
vmd->msix_entries = devm_kcalloc(&dev->dev, vmd->msix_count,
sizeof(*vmd->msix_entries),
GFP_KERNEL);
if (!vmd->msix_entries)
return -ENOMEM;
for (i = 0; i < vmd->msix_count; i++)
vmd->msix_entries[i].entry = i;
vmd->msix_count = pci_enable_msix_range(vmd->dev, vmd->msix_entries, 1,
vmd->msix_count);
if (vmd->msix_count < 0)
return vmd->msix_count;
for (i = 0; i < vmd->msix_count; i++) {
INIT_LIST_HEAD(&vmd->irqs[i].irq_list);
vmd->irqs[i].vmd_vector = vmd->msix_entries[i].vector;
vmd->irqs[i].index = i;
err = devm_request_irq(&dev->dev, vmd->irqs[i].vmd_vector,
vmd_irq, 0, "vmd", &vmd->irqs[i]);
if (err)
return err;
}
spin_lock_init(&vmd->cfg_lock);
pci_set_drvdata(dev, vmd);
err = vmd_enable_domain(vmd);
if (err)
return err;
dev_info(&vmd->dev->dev, "Bound to PCI domain %04x\n",
vmd->sysdata.domain);
return 0;
}
static void vmd_remove(struct pci_dev *dev)
{
struct vmd_dev *vmd = pci_get_drvdata(dev);
pci_set_drvdata(dev, NULL);
sysfs_remove_link(&vmd->dev->dev.kobj, "domain");
pci_stop_root_bus(vmd->bus);
pci_remove_root_bus(vmd->bus);
vmd_teardown_dma_ops(vmd);
irq_domain_remove(vmd->irq_domain);
}
static int vmd_suspend(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
pci_save_state(pdev);
return 0;
}
static int vmd_resume(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
pci_restore_state(pdev);
return 0;
}
