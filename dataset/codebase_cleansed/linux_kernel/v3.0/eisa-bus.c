static int is_forced_dev(int *forced_tab,
int forced_count,
struct eisa_root_device *root,
struct eisa_device *edev)
{
int i, x;
for (i = 0; i < forced_count; i++) {
x = (root->bus_nr << 8) | edev->slot;
if (forced_tab[i] == x)
return 1;
}
return 0;
}
static void __init eisa_name_device(struct eisa_device *edev)
{
#ifdef CONFIG_EISA_NAMES
int i;
for (i = 0; i < EISA_INFOS; i++) {
if (!strcmp(edev->id.sig, eisa_table[i].id.sig)) {
strlcpy(edev->pretty_name,
eisa_table[i].name,
sizeof(edev->pretty_name));
return;
}
}
sprintf(edev->pretty_name, "EISA device %.7s", edev->id.sig);
#endif
}
static char __init *decode_eisa_sig(unsigned long addr)
{
static char sig_str[EISA_SIG_LEN];
u8 sig[4];
u16 rev;
int i;
for (i = 0; i < 4; i++) {
#ifdef CONFIG_EISA_VLB_PRIMING
outb(0x80 + i, addr);
#endif
sig[i] = inb(addr + i);
if (!i && (sig[0] & 0x80))
return NULL;
}
sig_str[0] = ((sig[0] >> 2) & 0x1f) + ('A' - 1);
sig_str[1] = (((sig[0] & 3) << 3) | (sig[1] >> 5)) + ('A' - 1);
sig_str[2] = (sig[1] & 0x1f) + ('A' - 1);
rev = (sig[2] << 8) | sig[3];
sprintf(sig_str + 3, "%04X", rev);
return sig_str;
}
static int eisa_bus_match(struct device *dev, struct device_driver *drv)
{
struct eisa_device *edev = to_eisa_device(dev);
struct eisa_driver *edrv = to_eisa_driver(drv);
const struct eisa_device_id *eids = edrv->id_table;
if (!eids)
return 0;
while (strlen(eids->sig)) {
if (!strcmp(eids->sig, edev->id.sig) &&
edev->state & EISA_CONFIG_ENABLED) {
edev->id.driver_data = eids->driver_data;
return 1;
}
eids++;
}
return 0;
}
static int eisa_bus_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct eisa_device *edev = to_eisa_device(dev);
add_uevent_var(env, "MODALIAS=" EISA_DEVICE_MODALIAS_FMT, edev->id.sig);
return 0;
}
int eisa_driver_register(struct eisa_driver *edrv)
{
edrv->driver.bus = &eisa_bus_type;
return driver_register(&edrv->driver);
}
void eisa_driver_unregister(struct eisa_driver *edrv)
{
driver_unregister(&edrv->driver);
}
static ssize_t eisa_show_sig(struct device *dev, struct device_attribute *attr,
char *buf)
{
struct eisa_device *edev = to_eisa_device(dev);
return sprintf(buf, "%s\n", edev->id.sig);
}
static ssize_t eisa_show_state(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct eisa_device *edev = to_eisa_device(dev);
return sprintf(buf, "%d\n", edev->state & EISA_CONFIG_ENABLED);
}
static ssize_t eisa_show_modalias(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct eisa_device *edev = to_eisa_device(dev);
return sprintf(buf, EISA_DEVICE_MODALIAS_FMT "\n", edev->id.sig);
}
static int __init eisa_init_device(struct eisa_root_device *root,
struct eisa_device *edev,
int slot)
{
char *sig;
unsigned long sig_addr;
int i;
sig_addr = SLOT_ADDRESS(root, slot) + EISA_VENDOR_ID_OFFSET;
sig = decode_eisa_sig(sig_addr);
if (!sig)
return -1;
memcpy(edev->id.sig, sig, EISA_SIG_LEN);
edev->slot = slot;
edev->state = inb(SLOT_ADDRESS(root, slot) + EISA_CONFIG_OFFSET)
& EISA_CONFIG_ENABLED;
edev->base_addr = SLOT_ADDRESS(root, slot);
edev->dma_mask = root->dma_mask;
eisa_name_device(edev);
edev->dev.parent = root->dev;
edev->dev.bus = &eisa_bus_type;
edev->dev.dma_mask = &edev->dma_mask;
edev->dev.coherent_dma_mask = edev->dma_mask;
dev_set_name(&edev->dev, "%02X:%02X", root->bus_nr, slot);
for (i = 0; i < EISA_MAX_RESOURCES; i++) {
#ifdef CONFIG_EISA_NAMES
edev->res[i].name = edev->pretty_name;
#else
edev->res[i].name = edev->id.sig;
#endif
}
if (is_forced_dev(enable_dev, enable_dev_count, root, edev))
edev->state = EISA_CONFIG_ENABLED | EISA_CONFIG_FORCED;
if (is_forced_dev(disable_dev, disable_dev_count, root, edev))
edev->state = EISA_CONFIG_FORCED;
return 0;
}
static int __init eisa_register_device(struct eisa_device *edev)
{
int rc = device_register(&edev->dev);
if (rc)
return rc;
rc = device_create_file(&edev->dev, &dev_attr_signature);
if (rc)
goto err_devreg;
rc = device_create_file(&edev->dev, &dev_attr_enabled);
if (rc)
goto err_sig;
rc = device_create_file(&edev->dev, &dev_attr_modalias);
if (rc)
goto err_enab;
return 0;
err_enab:
device_remove_file(&edev->dev, &dev_attr_enabled);
err_sig:
device_remove_file(&edev->dev, &dev_attr_signature);
err_devreg:
device_unregister(&edev->dev);
return rc;
}
static int __init eisa_request_resources(struct eisa_root_device *root,
struct eisa_device *edev,
int slot)
{
int i;
for (i = 0; i < EISA_MAX_RESOURCES; i++) {
if (!slot && i > 0) {
edev->res[i].start = edev->res[i].end = 0;
continue;
}
if (slot) {
edev->res[i].name = NULL;
edev->res[i].start = SLOT_ADDRESS(root, slot)
+ (i * 0x400);
edev->res[i].end = edev->res[i].start + 0xff;
edev->res[i].flags = IORESOURCE_IO;
} else {
edev->res[i].name = NULL;
edev->res[i].start = SLOT_ADDRESS(root, slot)
+ EISA_VENDOR_ID_OFFSET;
edev->res[i].end = edev->res[i].start + 3;
edev->res[i].flags = IORESOURCE_BUSY;
}
if (request_resource(root->res, &edev->res[i]))
goto failed;
}
return 0;
failed:
while (--i >= 0)
release_resource(&edev->res[i]);
return -1;
}
static void __init eisa_release_resources(struct eisa_device *edev)
{
int i;
for (i = 0; i < EISA_MAX_RESOURCES; i++)
if (edev->res[i].start || edev->res[i].end)
release_resource(&edev->res[i]);
}
static int __init eisa_probe(struct eisa_root_device *root)
{
int i, c;
struct eisa_device *edev;
printk(KERN_INFO "EISA: Probing bus %d at %s\n",
root->bus_nr, dev_name(root->dev));
edev = kzalloc(sizeof(*edev), GFP_KERNEL);
if (!edev) {
printk(KERN_ERR "EISA: Couldn't allocate mainboard slot\n");
return -ENOMEM;
}
if (eisa_request_resources(root, edev, 0)) {
printk(KERN_WARNING \
"EISA: Cannot allocate resource for mainboard\n");
kfree(edev);
if (!root->force_probe)
return -EBUSY;
goto force_probe;
}
if (eisa_init_device(root, edev, 0)) {
eisa_release_resources(edev);
kfree(edev);
if (!root->force_probe)
return -ENODEV;
goto force_probe;
}
printk(KERN_INFO "EISA: Mainboard %s detected.\n", edev->id.sig);
if (eisa_register_device(edev)) {
printk(KERN_ERR "EISA: Failed to register %s\n",
edev->id.sig);
eisa_release_resources(edev);
kfree(edev);
}
force_probe:
for (c = 0, i = 1; i <= root->slots; i++) {
edev = kzalloc(sizeof(*edev), GFP_KERNEL);
if (!edev) {
printk(KERN_ERR "EISA: Out of memory for slot %d\n", i);
continue;
}
if (eisa_request_resources(root, edev, i)) {
printk(KERN_WARNING \
"Cannot allocate resource for EISA slot %d\n",
i);
kfree(edev);
continue;
}
if (eisa_init_device(root, edev, i)) {
eisa_release_resources(edev);
kfree(edev);
continue;
}
printk(KERN_INFO "EISA: slot %d : %s detected",
i, edev->id.sig);
switch (edev->state) {
case EISA_CONFIG_ENABLED | EISA_CONFIG_FORCED:
printk(" (forced enabled)");
break;
case EISA_CONFIG_FORCED:
printk(" (forced disabled)");
break;
case 0:
printk(" (disabled)");
break;
}
printk (".\n");
c++;
if (eisa_register_device(edev)) {
printk(KERN_ERR "EISA: Failed to register %s\n",
edev->id.sig);
eisa_release_resources(edev);
kfree(edev);
}
}
printk(KERN_INFO "EISA: Detected %d card%s.\n", c, c == 1 ? "" : "s");
return 0;
}
int __init eisa_root_register(struct eisa_root_device *root)
{
int err;
root->eisa_root_res.name = eisa_root_res.name;
root->eisa_root_res.start = root->res->start;
root->eisa_root_res.end = root->res->end;
root->eisa_root_res.flags = IORESOURCE_BUSY;
err = request_resource(&eisa_root_res, &root->eisa_root_res);
if (err)
return err;
root->bus_nr = eisa_bus_count++;
err = eisa_probe(root);
if (err)
release_resource(&root->eisa_root_res);
return err;
}
static int __init eisa_init(void)
{
int r;
r = bus_register(&eisa_bus_type);
if (r)
return r;
printk(KERN_INFO "EISA bus registered\n");
return 0;
}
