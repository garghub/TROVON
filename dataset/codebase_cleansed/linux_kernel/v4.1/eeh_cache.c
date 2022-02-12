static inline struct eeh_dev *__eeh_addr_cache_get_device(unsigned long addr)
{
struct rb_node *n = pci_io_addr_cache_root.rb_root.rb_node;
while (n) {
struct pci_io_addr_range *piar;
piar = rb_entry(n, struct pci_io_addr_range, rb_node);
if (addr < piar->addr_lo)
n = n->rb_left;
else if (addr > piar->addr_hi)
n = n->rb_right;
else
return piar->edev;
}
return NULL;
}
struct eeh_dev *eeh_addr_cache_get_dev(unsigned long addr)
{
struct eeh_dev *edev;
unsigned long flags;
spin_lock_irqsave(&pci_io_addr_cache_root.piar_lock, flags);
edev = __eeh_addr_cache_get_device(addr);
spin_unlock_irqrestore(&pci_io_addr_cache_root.piar_lock, flags);
return edev;
}
static void eeh_addr_cache_print(struct pci_io_addr_cache *cache)
{
struct rb_node *n;
int cnt = 0;
n = rb_first(&cache->rb_root);
while (n) {
struct pci_io_addr_range *piar;
piar = rb_entry(n, struct pci_io_addr_range, rb_node);
pr_debug("PCI: %s addr range %d [%lx-%lx]: %s\n",
(piar->flags & IORESOURCE_IO) ? "i/o" : "mem", cnt,
piar->addr_lo, piar->addr_hi, pci_name(piar->pcidev));
cnt++;
n = rb_next(n);
}
}
static struct pci_io_addr_range *
eeh_addr_cache_insert(struct pci_dev *dev, unsigned long alo,
unsigned long ahi, unsigned int flags)
{
struct rb_node **p = &pci_io_addr_cache_root.rb_root.rb_node;
struct rb_node *parent = NULL;
struct pci_io_addr_range *piar;
while (*p) {
parent = *p;
piar = rb_entry(parent, struct pci_io_addr_range, rb_node);
if (ahi < piar->addr_lo) {
p = &parent->rb_left;
} else if (alo > piar->addr_hi) {
p = &parent->rb_right;
} else {
if (dev != piar->pcidev ||
alo != piar->addr_lo || ahi != piar->addr_hi) {
pr_warn("PIAR: overlapping address range\n");
}
return piar;
}
}
piar = kzalloc(sizeof(struct pci_io_addr_range), GFP_ATOMIC);
if (!piar)
return NULL;
piar->addr_lo = alo;
piar->addr_hi = ahi;
piar->edev = pci_dev_to_eeh_dev(dev);
piar->pcidev = dev;
piar->flags = flags;
#ifdef DEBUG
pr_debug("PIAR: insert range=[%lx:%lx] dev=%s\n",
alo, ahi, pci_name(dev));
#endif
rb_link_node(&piar->rb_node, parent, p);
rb_insert_color(&piar->rb_node, &pci_io_addr_cache_root.rb_root);
return piar;
}
static void __eeh_addr_cache_insert_dev(struct pci_dev *dev)
{
struct pci_dn *pdn;
struct eeh_dev *edev;
int i;
pdn = pci_get_pdn_by_devfn(dev->bus, dev->devfn);
if (!pdn) {
pr_warn("PCI: no pci dn found for dev=%s\n",
pci_name(dev));
return;
}
edev = pdn_to_eeh_dev(pdn);
if (!edev) {
pr_warn("PCI: no EEH dev found for %s\n",
pci_name(dev));
return;
}
if (!edev->pe) {
dev_dbg(&dev->dev, "EEH: Skip building address cache\n");
return;
}
for (i = 0; i < DEVICE_COUNT_RESOURCE; i++) {
unsigned long start = pci_resource_start(dev,i);
unsigned long end = pci_resource_end(dev,i);
unsigned int flags = pci_resource_flags(dev,i);
if (0 == (flags & (IORESOURCE_IO | IORESOURCE_MEM)))
continue;
if (start == 0 || ~start == 0 || end == 0 || ~end == 0)
continue;
eeh_addr_cache_insert(dev, start, end, flags);
}
}
void eeh_addr_cache_insert_dev(struct pci_dev *dev)
{
unsigned long flags;
if ((dev->class >> 16) == PCI_BASE_CLASS_BRIDGE)
return;
spin_lock_irqsave(&pci_io_addr_cache_root.piar_lock, flags);
__eeh_addr_cache_insert_dev(dev);
spin_unlock_irqrestore(&pci_io_addr_cache_root.piar_lock, flags);
}
static inline void __eeh_addr_cache_rmv_dev(struct pci_dev *dev)
{
struct rb_node *n;
restart:
n = rb_first(&pci_io_addr_cache_root.rb_root);
while (n) {
struct pci_io_addr_range *piar;
piar = rb_entry(n, struct pci_io_addr_range, rb_node);
if (piar->pcidev == dev) {
rb_erase(n, &pci_io_addr_cache_root.rb_root);
kfree(piar);
goto restart;
}
n = rb_next(n);
}
}
void eeh_addr_cache_rmv_dev(struct pci_dev *dev)
{
unsigned long flags;
spin_lock_irqsave(&pci_io_addr_cache_root.piar_lock, flags);
__eeh_addr_cache_rmv_dev(dev);
spin_unlock_irqrestore(&pci_io_addr_cache_root.piar_lock, flags);
}
void eeh_addr_cache_build(void)
{
struct pci_dn *pdn;
struct eeh_dev *edev;
struct pci_dev *dev = NULL;
spin_lock_init(&pci_io_addr_cache_root.piar_lock);
for_each_pci_dev(dev) {
pdn = pci_get_pdn_by_devfn(dev->bus, dev->devfn);
if (!pdn)
continue;
edev = pdn_to_eeh_dev(pdn);
if (!edev)
continue;
dev->dev.archdata.edev = edev;
edev->pdev = dev;
eeh_addr_cache_insert_dev(dev);
eeh_sysfs_add_device(dev);
}
#ifdef DEBUG
eeh_addr_cache_print(&pci_io_addr_cache_root);
#endif
}
