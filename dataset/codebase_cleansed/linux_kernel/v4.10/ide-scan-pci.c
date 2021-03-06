int __ide_pci_register_driver(struct pci_driver *driver, struct module *module,
const char *mod_name)
{
if (!pre_init)
return __pci_register_driver(driver, module, mod_name);
driver->driver.owner = module;
list_add_tail(&driver->node, &ide_pci_drivers);
return 0;
}
static int __init ide_scan_pcidev(struct pci_dev *dev)
{
struct list_head *l;
struct pci_driver *d;
list_for_each(l, &ide_pci_drivers) {
d = list_entry(l, struct pci_driver, node);
if (d->id_table) {
const struct pci_device_id *id =
pci_match_id(d->id_table, dev);
if (id != NULL && d->probe(dev, id) >= 0) {
dev->driver = d;
pci_dev_get(dev);
return 1;
}
}
}
return 0;
}
static int __init ide_scan_pcibus(void)
{
struct pci_dev *dev = NULL;
struct pci_driver *d;
struct list_head *l, *n;
pre_init = 0;
for_each_pci_dev(dev)
ide_scan_pcidev(dev);
list_for_each_safe(l, n, &ide_pci_drivers) {
list_del(l);
d = list_entry(l, struct pci_driver, node);
if (__pci_register_driver(d, d->driver.owner,
d->driver.mod_name))
printk(KERN_ERR "%s: failed to register %s driver\n",
__func__, d->driver.mod_name);
}
return 0;
}
