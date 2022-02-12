void pci_epf_linkup(struct pci_epf *epf)
{
if (!epf->driver) {
dev_WARN(&epf->dev, "epf device not bound to driver\n");
return;
}
epf->driver->ops->linkup(epf);
}
void pci_epf_unbind(struct pci_epf *epf)
{
if (!epf->driver) {
dev_WARN(&epf->dev, "epf device not bound to driver\n");
return;
}
epf->driver->ops->unbind(epf);
module_put(epf->driver->owner);
}
int pci_epf_bind(struct pci_epf *epf)
{
if (!epf->driver) {
dev_WARN(&epf->dev, "epf device not bound to driver\n");
return -EINVAL;
}
if (!try_module_get(epf->driver->owner))
return -EAGAIN;
return epf->driver->ops->bind(epf);
}
void pci_epf_free_space(struct pci_epf *epf, void *addr, enum pci_barno bar)
{
struct device *dev = &epf->dev;
if (!addr)
return;
dma_free_coherent(dev, epf->bar[bar].size, addr,
epf->bar[bar].phys_addr);
epf->bar[bar].phys_addr = 0;
epf->bar[bar].size = 0;
}
void *pci_epf_alloc_space(struct pci_epf *epf, size_t size, enum pci_barno bar)
{
void *space;
struct device *dev = &epf->dev;
dma_addr_t phys_addr;
if (size < 128)
size = 128;
size = roundup_pow_of_two(size);
space = dma_alloc_coherent(dev, size, &phys_addr, GFP_KERNEL);
if (!space) {
dev_err(dev, "failed to allocate mem space\n");
return NULL;
}
epf->bar[bar].phys_addr = phys_addr;
epf->bar[bar].size = size;
return space;
}
void pci_epf_unregister_driver(struct pci_epf_driver *driver)
{
pci_ep_cfs_remove_epf_group(driver->group);
driver_unregister(&driver->driver);
}
int __pci_epf_register_driver(struct pci_epf_driver *driver,
struct module *owner)
{
int ret;
if (!driver->ops)
return -EINVAL;
if (!driver->ops->bind || !driver->ops->unbind || !driver->ops->linkup)
return -EINVAL;
driver->driver.bus = &pci_epf_bus_type;
driver->driver.owner = owner;
ret = driver_register(&driver->driver);
if (ret)
return ret;
driver->group = pci_ep_cfs_add_epf_group(driver->driver.name);
return 0;
}
void pci_epf_destroy(struct pci_epf *epf)
{
device_unregister(&epf->dev);
}
struct pci_epf *pci_epf_create(const char *name)
{
int ret;
struct pci_epf *epf;
struct device *dev;
char *func_name;
char *buf;
epf = kzalloc(sizeof(*epf), GFP_KERNEL);
if (!epf) {
ret = -ENOMEM;
goto err_ret;
}
buf = kstrdup(name, GFP_KERNEL);
if (!buf) {
ret = -ENOMEM;
goto free_epf;
}
func_name = buf;
buf = strchrnul(buf, '.');
*buf = '\0';
epf->name = kstrdup(func_name, GFP_KERNEL);
if (!epf->name) {
ret = -ENOMEM;
goto free_func_name;
}
dev = &epf->dev;
device_initialize(dev);
dev->bus = &pci_epf_bus_type;
dev->type = &pci_epf_type;
ret = dev_set_name(dev, "%s", name);
if (ret)
goto put_dev;
ret = device_add(dev);
if (ret)
goto put_dev;
kfree(func_name);
return epf;
put_dev:
put_device(dev);
kfree(epf->name);
free_func_name:
kfree(func_name);
free_epf:
kfree(epf);
err_ret:
return ERR_PTR(ret);
}
const struct pci_epf_device_id *
pci_epf_match_device(const struct pci_epf_device_id *id, struct pci_epf *epf)
{
if (!id || !epf)
return NULL;
while (*id->name) {
if (strcmp(epf->name, id->name) == 0)
return id;
id++;
}
return NULL;
}
static void pci_epf_dev_release(struct device *dev)
{
struct pci_epf *epf = to_pci_epf(dev);
kfree(epf->name);
kfree(epf);
}
static int
pci_epf_match_id(const struct pci_epf_device_id *id, const struct pci_epf *epf)
{
while (id->name[0]) {
if (strcmp(epf->name, id->name) == 0)
return true;
id++;
}
return false;
}
static int pci_epf_device_match(struct device *dev, struct device_driver *drv)
{
struct pci_epf *epf = to_pci_epf(dev);
struct pci_epf_driver *driver = to_pci_epf_driver(drv);
if (driver->id_table)
return pci_epf_match_id(driver->id_table, epf);
return !strcmp(epf->name, drv->name);
}
static int pci_epf_device_probe(struct device *dev)
{
struct pci_epf *epf = to_pci_epf(dev);
struct pci_epf_driver *driver = to_pci_epf_driver(dev->driver);
if (!driver->probe)
return -ENODEV;
epf->driver = driver;
return driver->probe(epf);
}
static int pci_epf_device_remove(struct device *dev)
{
int ret = 0;
struct pci_epf *epf = to_pci_epf(dev);
struct pci_epf_driver *driver = to_pci_epf_driver(dev->driver);
if (driver->remove)
ret = driver->remove(epf);
epf->driver = NULL;
return ret;
}
static int __init pci_epf_init(void)
{
int ret;
ret = bus_register(&pci_epf_bus_type);
if (ret) {
pr_err("failed to register pci epf bus --> %d\n", ret);
return ret;
}
return 0;
}
static void __exit pci_epf_exit(void)
{
bus_unregister(&pci_epf_bus_type);
}
