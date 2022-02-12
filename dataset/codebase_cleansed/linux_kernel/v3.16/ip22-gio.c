const struct gio_device_id *gio_match_device(const struct gio_device_id *match,
const struct gio_device *dev)
{
const struct gio_device_id *ids;
for (ids = match; ids->id != 0xff; ids++)
if (ids->id == dev->id.id)
return ids;
return NULL;
}
struct gio_device *gio_dev_get(struct gio_device *dev)
{
struct device *tmp;
if (!dev)
return NULL;
tmp = get_device(&dev->dev);
if (tmp)
return to_gio_device(tmp);
else
return NULL;
}
void gio_dev_put(struct gio_device *dev)
{
if (dev)
put_device(&dev->dev);
}
void gio_release_dev(struct device *dev)
{
struct gio_device *giodev;
giodev = to_gio_device(dev);
kfree(giodev);
}
int gio_device_register(struct gio_device *giodev)
{
giodev->dev.bus = &gio_bus_type;
giodev->dev.parent = &gio_bus;
return device_register(&giodev->dev);
}
void gio_device_unregister(struct gio_device *giodev)
{
device_unregister(&giodev->dev);
}
static int gio_bus_match(struct device *dev, struct device_driver *drv)
{
struct gio_device *gio_dev = to_gio_device(dev);
struct gio_driver *gio_drv = to_gio_driver(drv);
return gio_match_device(gio_drv->id_table, gio_dev) != NULL;
}
static int gio_device_probe(struct device *dev)
{
int error = -ENODEV;
struct gio_driver *drv;
struct gio_device *gio_dev;
const struct gio_device_id *match;
drv = to_gio_driver(dev->driver);
gio_dev = to_gio_device(dev);
if (!drv->probe)
return error;
gio_dev_get(gio_dev);
match = gio_match_device(drv->id_table, gio_dev);
if (match)
error = drv->probe(gio_dev, match);
if (error)
gio_dev_put(gio_dev);
return error;
}
static int gio_device_remove(struct device *dev)
{
struct gio_device *gio_dev = to_gio_device(dev);
struct gio_driver *drv = to_gio_driver(dev->driver);
if (dev->driver && drv->remove)
drv->remove(gio_dev);
return 0;
}
static int gio_device_suspend(struct device *dev, pm_message_t state)
{
struct gio_device *gio_dev = to_gio_device(dev);
struct gio_driver *drv = to_gio_driver(dev->driver);
int error = 0;
if (dev->driver && drv->suspend)
error = drv->suspend(gio_dev, state);
return error;
}
static int gio_device_resume(struct device *dev)
{
struct gio_device *gio_dev = to_gio_device(dev);
struct gio_driver *drv = to_gio_driver(dev->driver);
int error = 0;
if (dev->driver && drv->resume)
error = drv->resume(gio_dev);
return error;
}
static void gio_device_shutdown(struct device *dev)
{
struct gio_device *gio_dev = to_gio_device(dev);
struct gio_driver *drv = to_gio_driver(dev->driver);
if (dev->driver && drv->shutdown)
drv->shutdown(gio_dev);
}
static ssize_t modalias_show(struct device *dev, struct device_attribute *a,
char *buf)
{
struct gio_device *gio_dev = to_gio_device(dev);
int len = snprintf(buf, PAGE_SIZE, "gio:%x\n", gio_dev->id.id);
return (len >= PAGE_SIZE) ? (PAGE_SIZE - 1) : len;
}
static ssize_t name_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct gio_device *giodev;
giodev = to_gio_device(dev);
return sprintf(buf, "%s", giodev->name);
}
static ssize_t id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct gio_device *giodev;
giodev = to_gio_device(dev);
return sprintf(buf, "%x", giodev->id.id);
}
static int gio_device_uevent(struct device *dev, struct kobj_uevent_env *env)
{
struct gio_device *gio_dev = to_gio_device(dev);
add_uevent_var(env, "MODALIAS=gio:%x", gio_dev->id.id);
return 0;
}
int gio_register_driver(struct gio_driver *drv)
{
if (!drv->driver.name)
drv->driver.name = drv->name;
if (!drv->driver.owner)
drv->driver.owner = drv->owner;
drv->driver.bus = &gio_bus_type;
return driver_register(&drv->driver);
}
void gio_unregister_driver(struct gio_driver *drv)
{
driver_unregister(&drv->driver);
}
void gio_set_master(struct gio_device *dev)
{
u32 tmp = sgimc->giopar;
switch (dev->slotno) {
case 0:
tmp |= SGIMC_GIOPAR_MASTERGFX;
break;
case 1:
tmp |= SGIMC_GIOPAR_MASTEREXP0;
break;
case 2:
tmp |= SGIMC_GIOPAR_MASTEREXP1;
break;
}
sgimc->giopar = tmp;
}
void ip22_gio_set_64bit(int slotno)
{
u32 tmp = sgimc->giopar;
switch (slotno) {
case 0:
tmp |= SGIMC_GIOPAR_GFX64;
break;
case 1:
tmp |= SGIMC_GIOPAR_EXP064;
break;
case 2:
tmp |= SGIMC_GIOPAR_EXP164;
break;
}
sgimc->giopar = tmp;
}
static int ip22_gio_id(unsigned long addr, u32 *res)
{
u8 tmp8;
u8 tmp16;
u32 tmp32;
u8 *ptr8;
u16 *ptr16;
u32 *ptr32;
ptr32 = (void *)CKSEG1ADDR(addr);
if (!get_dbe(tmp32, ptr32)) {
ptr8 = (void *)CKSEG1ADDR(addr + 3);
if (get_dbe(tmp8, ptr8)) {
*res = tmp32;
return 1;
}
ptr16 = (void *)CKSEG1ADDR(addr + 2);
get_dbe(tmp16, ptr16);
if (tmp8 == (tmp16 & 0xff) &&
tmp8 == (tmp32 & 0xff) &&
tmp16 == (tmp32 & 0xffff)) {
*res = tmp32;
return 1;
}
}
return 0;
}
static int ip22_is_gr2(unsigned long addr)
{
u32 tmp;
u32 *ptr;
ptr = (void *)CKSEG1ADDR(addr + HQ2_MYSTERY_OFFS);
if (!get_dbe(tmp, ptr)) {
if (tmp == 0xdeadbeef)
return 1;
}
return 0;
}
static void ip22_check_gio(int slotno, unsigned long addr, int irq)
{
const char *name = "Unknown";
struct gio_device *gio_dev;
u32 tmp;
__u8 id;
int i;
if (ip22_is_gr2(addr))
tmp = 0x7f;
else {
if (!ip22_gio_id(addr, &tmp)) {
if (ip22_gio_id(addr + NEWPORT_USTATUS_OFFS, &tmp))
tmp = 0x7e;
else
tmp = 0;
}
}
if (tmp) {
id = GIO_ID(tmp);
if (tmp & GIO_32BIT_ID) {
if (tmp & GIO_64BIT_IFACE)
ip22_gio_set_64bit(slotno);
}
for (i = 0; i < ARRAY_SIZE(gio_name_table); i++) {
if (id == gio_name_table[i].id) {
name = gio_name_table[i].name;
break;
}
}
printk(KERN_INFO "GIO: slot %d : %s (id %x)\n",
slotno, name, id);
gio_dev = kzalloc(sizeof *gio_dev, GFP_KERNEL);
gio_dev->name = name;
gio_dev->slotno = slotno;
gio_dev->id.id = id;
gio_dev->resource.start = addr;
gio_dev->resource.end = addr + 0x3fffff;
gio_dev->resource.flags = IORESOURCE_MEM;
gio_dev->irq = irq;
dev_set_name(&gio_dev->dev, "%d", slotno);
gio_device_register(gio_dev);
} else
printk(KERN_INFO "GIO: slot %d : Empty\n", slotno);
}
int __init ip22_gio_init(void)
{
unsigned int pbdma __maybe_unused;
int ret;
ret = device_register(&gio_bus);
if (ret)
return ret;
ret = bus_register(&gio_bus_type);
if (!ret) {
request_resource(&iomem_resource, &gio_bus_resource);
printk(KERN_INFO "GIO: Probing bus...\n");
if (ip22_is_fullhouse()) {
ip22_check_gio(0, GIO_SLOT_GFX_BASE, SGI_GIO_1_IRQ);
ip22_check_gio(1, GIO_SLOT_EXP0_BASE, SGI_GIO_1_IRQ);
} else {
if (get_dbe(pbdma, (unsigned int *)&hpc3c1->pbdma[1]))
ip22_check_gio(0, GIO_SLOT_GFX_BASE,
SGI_GIO_0_IRQ);
ip22_check_gio(1, GIO_SLOT_EXP0_BASE, SGI_GIOEXP0_IRQ);
ip22_check_gio(2, GIO_SLOT_EXP1_BASE, SGI_GIOEXP1_IRQ);
}
} else
device_unregister(&gio_bus);
return ret;
}
