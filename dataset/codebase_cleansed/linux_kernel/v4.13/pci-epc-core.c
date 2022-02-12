static void devm_pci_epc_release(struct device *dev, void *res)
{
struct pci_epc *epc = *(struct pci_epc **)res;
pci_epc_destroy(epc);
}
static int devm_pci_epc_match(struct device *dev, void *res, void *match_data)
{
struct pci_epc **epc = res;
return *epc == match_data;
}
void pci_epc_put(struct pci_epc *epc)
{
if (!epc || IS_ERR(epc))
return;
module_put(epc->ops->owner);
put_device(&epc->dev);
}
struct pci_epc *pci_epc_get(const char *epc_name)
{
int ret = -EINVAL;
struct pci_epc *epc;
struct device *dev;
struct class_dev_iter iter;
class_dev_iter_init(&iter, pci_epc_class, NULL, NULL);
while ((dev = class_dev_iter_next(&iter))) {
if (strcmp(epc_name, dev_name(dev)))
continue;
epc = to_pci_epc(dev);
if (!try_module_get(epc->ops->owner)) {
ret = -EINVAL;
goto err;
}
class_dev_iter_exit(&iter);
get_device(&epc->dev);
return epc;
}
err:
class_dev_iter_exit(&iter);
return ERR_PTR(ret);
}
void pci_epc_stop(struct pci_epc *epc)
{
unsigned long flags;
if (IS_ERR(epc) || !epc->ops->stop)
return;
spin_lock_irqsave(&epc->lock, flags);
epc->ops->stop(epc);
spin_unlock_irqrestore(&epc->lock, flags);
}
int pci_epc_start(struct pci_epc *epc)
{
int ret;
unsigned long flags;
if (IS_ERR(epc))
return -EINVAL;
if (!epc->ops->start)
return 0;
spin_lock_irqsave(&epc->lock, flags);
ret = epc->ops->start(epc);
spin_unlock_irqrestore(&epc->lock, flags);
return ret;
}
int pci_epc_raise_irq(struct pci_epc *epc, enum pci_epc_irq_type type,
u8 interrupt_num)
{
int ret;
unsigned long flags;
if (IS_ERR(epc))
return -EINVAL;
if (!epc->ops->raise_irq)
return 0;
spin_lock_irqsave(&epc->lock, flags);
ret = epc->ops->raise_irq(epc, type, interrupt_num);
spin_unlock_irqrestore(&epc->lock, flags);
return ret;
}
int pci_epc_get_msi(struct pci_epc *epc)
{
int interrupt;
unsigned long flags;
if (IS_ERR(epc))
return 0;
if (!epc->ops->get_msi)
return 0;
spin_lock_irqsave(&epc->lock, flags);
interrupt = epc->ops->get_msi(epc);
spin_unlock_irqrestore(&epc->lock, flags);
if (interrupt < 0)
return 0;
interrupt = 1 << interrupt;
return interrupt;
}
int pci_epc_set_msi(struct pci_epc *epc, u8 interrupts)
{
int ret;
u8 encode_int;
unsigned long flags;
if (IS_ERR(epc))
return -EINVAL;
if (!epc->ops->set_msi)
return 0;
encode_int = order_base_2(interrupts);
spin_lock_irqsave(&epc->lock, flags);
ret = epc->ops->set_msi(epc, encode_int);
spin_unlock_irqrestore(&epc->lock, flags);
return ret;
}
void pci_epc_unmap_addr(struct pci_epc *epc, phys_addr_t phys_addr)
{
unsigned long flags;
if (IS_ERR(epc))
return;
if (!epc->ops->unmap_addr)
return;
spin_lock_irqsave(&epc->lock, flags);
epc->ops->unmap_addr(epc, phys_addr);
spin_unlock_irqrestore(&epc->lock, flags);
}
int pci_epc_map_addr(struct pci_epc *epc, phys_addr_t phys_addr,
u64 pci_addr, size_t size)
{
int ret;
unsigned long flags;
if (IS_ERR(epc))
return -EINVAL;
if (!epc->ops->map_addr)
return 0;
spin_lock_irqsave(&epc->lock, flags);
ret = epc->ops->map_addr(epc, phys_addr, pci_addr, size);
spin_unlock_irqrestore(&epc->lock, flags);
return ret;
}
void pci_epc_clear_bar(struct pci_epc *epc, int bar)
{
unsigned long flags;
if (IS_ERR(epc))
return;
if (!epc->ops->clear_bar)
return;
spin_lock_irqsave(&epc->lock, flags);
epc->ops->clear_bar(epc, bar);
spin_unlock_irqrestore(&epc->lock, flags);
}
int pci_epc_set_bar(struct pci_epc *epc, enum pci_barno bar,
dma_addr_t bar_phys, size_t size, int flags)
{
int ret;
unsigned long irq_flags;
if (IS_ERR(epc))
return -EINVAL;
if (!epc->ops->set_bar)
return 0;
spin_lock_irqsave(&epc->lock, irq_flags);
ret = epc->ops->set_bar(epc, bar, bar_phys, size, flags);
spin_unlock_irqrestore(&epc->lock, irq_flags);
return ret;
}
int pci_epc_write_header(struct pci_epc *epc, struct pci_epf_header *header)
{
int ret;
unsigned long flags;
if (IS_ERR(epc))
return -EINVAL;
if (!epc->ops->write_header)
return 0;
spin_lock_irqsave(&epc->lock, flags);
ret = epc->ops->write_header(epc, header);
spin_unlock_irqrestore(&epc->lock, flags);
return ret;
}
int pci_epc_add_epf(struct pci_epc *epc, struct pci_epf *epf)
{
unsigned long flags;
if (epf->epc)
return -EBUSY;
if (IS_ERR(epc))
return -EINVAL;
if (epf->func_no > epc->max_functions - 1)
return -EINVAL;
epf->epc = epc;
dma_set_coherent_mask(&epf->dev, epc->dev.coherent_dma_mask);
epf->dev.dma_mask = epc->dev.dma_mask;
spin_lock_irqsave(&epc->lock, flags);
list_add_tail(&epf->list, &epc->pci_epf);
spin_unlock_irqrestore(&epc->lock, flags);
return 0;
}
void pci_epc_remove_epf(struct pci_epc *epc, struct pci_epf *epf)
{
unsigned long flags;
if (!epc || IS_ERR(epc))
return;
spin_lock_irqsave(&epc->lock, flags);
list_del(&epf->list);
spin_unlock_irqrestore(&epc->lock, flags);
}
void pci_epc_linkup(struct pci_epc *epc)
{
unsigned long flags;
struct pci_epf *epf;
if (!epc || IS_ERR(epc))
return;
spin_lock_irqsave(&epc->lock, flags);
list_for_each_entry(epf, &epc->pci_epf, list)
pci_epf_linkup(epf);
spin_unlock_irqrestore(&epc->lock, flags);
}
void pci_epc_destroy(struct pci_epc *epc)
{
pci_ep_cfs_remove_epc_group(epc->group);
device_unregister(&epc->dev);
kfree(epc);
}
void devm_pci_epc_destroy(struct device *dev, struct pci_epc *epc)
{
int r;
r = devres_destroy(dev, devm_pci_epc_release, devm_pci_epc_match,
epc);
dev_WARN_ONCE(dev, r, "couldn't find PCI EPC resource\n");
}
struct pci_epc *
__pci_epc_create(struct device *dev, const struct pci_epc_ops *ops,
struct module *owner)
{
int ret;
struct pci_epc *epc;
if (WARN_ON(!dev)) {
ret = -EINVAL;
goto err_ret;
}
epc = kzalloc(sizeof(*epc), GFP_KERNEL);
if (!epc) {
ret = -ENOMEM;
goto err_ret;
}
spin_lock_init(&epc->lock);
INIT_LIST_HEAD(&epc->pci_epf);
device_initialize(&epc->dev);
dma_set_coherent_mask(&epc->dev, dev->coherent_dma_mask);
epc->dev.class = pci_epc_class;
epc->dev.dma_mask = dev->dma_mask;
epc->ops = ops;
ret = dev_set_name(&epc->dev, "%s", dev_name(dev));
if (ret)
goto put_dev;
ret = device_add(&epc->dev);
if (ret)
goto put_dev;
epc->group = pci_ep_cfs_add_epc_group(dev_name(dev));
return epc;
put_dev:
put_device(&epc->dev);
kfree(epc);
err_ret:
return ERR_PTR(ret);
}
struct pci_epc *
__devm_pci_epc_create(struct device *dev, const struct pci_epc_ops *ops,
struct module *owner)
{
struct pci_epc **ptr, *epc;
ptr = devres_alloc(devm_pci_epc_release, sizeof(*ptr), GFP_KERNEL);
if (!ptr)
return ERR_PTR(-ENOMEM);
epc = __pci_epc_create(dev, ops, owner);
if (!IS_ERR(epc)) {
*ptr = epc;
devres_add(dev, ptr);
} else {
devres_free(ptr);
}
return epc;
}
static int __init pci_epc_init(void)
{
pci_epc_class = class_create(THIS_MODULE, "pci_epc");
if (IS_ERR(pci_epc_class)) {
pr_err("failed to create pci epc class --> %ld\n",
PTR_ERR(pci_epc_class));
return PTR_ERR(pci_epc_class);
}
return 0;
}
static void __exit pci_epc_exit(void)
{
class_destroy(pci_epc_class);
}
