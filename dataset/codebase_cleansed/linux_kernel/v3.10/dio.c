static const char *dio_getname(int id)
{
unsigned int i;
for (i = 0; i < ARRAY_SIZE(names); i++)
if (names[i].id == id)
return names[i].name;
return unknowndioname;
}
int __init dio_find(int deviceid)
{
int scode, id;
u_char prid, secid, i;
mm_segment_t fs;
for (scode = 0; scode < DIO_SCMAX; scode++) {
void *va;
unsigned long pa;
if (DIO_SCINHOLE(scode))
continue;
pa = dio_scodetophysaddr(scode);
if (!pa)
continue;
if (scode < DIOII_SCBASE)
va = (void *)(pa + DIO_VIRADDRBASE);
else
va = ioremap(pa, PAGE_SIZE);
fs = get_fs();
set_fs(KERNEL_DS);
if (get_user(i, (unsigned char *)va + DIO_IDOFF)) {
set_fs(fs);
if (scode >= DIOII_SCBASE)
iounmap(va);
continue;
}
set_fs(fs);
prid = DIO_ID(va);
if (DIO_NEEDSSECID(prid)) {
secid = DIO_SECID(va);
id = DIO_ENCODE_ID(prid, secid);
} else
id = prid;
if (id == deviceid) {
if (scode >= DIOII_SCBASE)
iounmap(va);
return scode;
}
}
return -1;
}
static int __init dio_init(void)
{
int scode;
mm_segment_t fs;
int i;
struct dio_dev *dev;
int error;
if (!MACH_IS_HP300)
return 0;
printk(KERN_INFO "Scanning for DIO devices...\n");
INIT_LIST_HEAD(&dio_bus.devices);
dev_set_name(&dio_bus.dev, "dio");
error = device_register(&dio_bus.dev);
if (error) {
pr_err("DIO: Error registering dio_bus\n");
return error;
}
dio_bus.num_resources = (hp300_model == HP_320 ? 1 : 2);
for (i = 0; i < dio_bus.num_resources; i++)
request_resource(&iomem_resource, &dio_bus.resources[i]);
for (scode = 0; scode < DIO_SCMAX; ++scode)
{
u_char prid, secid = 0;
u_char *va;
unsigned long pa;
if (DIO_SCINHOLE(scode))
continue;
pa = dio_scodetophysaddr(scode);
if (!pa)
continue;
if (scode < DIOII_SCBASE)
va = (void *)(pa + DIO_VIRADDRBASE);
else
va = ioremap(pa, PAGE_SIZE);
fs = get_fs();
set_fs(KERNEL_DS);
if (get_user(i, (unsigned char *)va + DIO_IDOFF)) {
set_fs(fs);
if (scode >= DIOII_SCBASE)
iounmap(va);
continue;
}
set_fs(fs);
dev = kzalloc(sizeof(struct dio_dev), GFP_KERNEL);
if (!dev)
return 0;
dev->bus = &dio_bus;
dev->dev.parent = &dio_bus.dev;
dev->dev.bus = &dio_bus_type;
dev->scode = scode;
dev->resource.start = pa;
dev->resource.end = pa + DIO_SIZE(scode, va);
dev_set_name(&dev->dev, "%02x", scode);
prid = DIO_ID(va);
if (DIO_NEEDSSECID(prid)) {
secid = DIO_SECID(va);
dev->id = DIO_ENCODE_ID(prid, secid);
} else
dev->id = prid;
dev->ipl = DIO_IPL(va);
strcpy(dev->name,dio_getname(dev->id));
printk(KERN_INFO "select code %3d: ipl %d: ID %02X", dev->scode, dev->ipl, prid);
if (DIO_NEEDSSECID(prid))
printk(":%02X", secid);
printk(": %s\n", dev->name);
if (scode >= DIOII_SCBASE)
iounmap(va);
error = device_register(&dev->dev);
if (error) {
pr_err("DIO: Error registering device %s\n",
dev->name);
continue;
}
error = dio_create_sysfs_dev_files(dev);
if (error)
dev_err(&dev->dev, "Error creating sysfs files\n");
}
return 0;
}
unsigned long dio_scodetophysaddr(int scode)
{
if (scode >= DIOII_SCBASE) {
return (DIOII_BASE + (scode - 132) * DIOII_DEVSIZE);
} else if (scode > DIO_SCMAX || scode < 0)
return 0;
else if (DIO_SCINHOLE(scode))
return 0;
return (DIO_BASE + scode * DIO_DEVSIZE);
}
