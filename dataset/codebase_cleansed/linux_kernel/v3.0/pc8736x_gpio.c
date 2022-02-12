static inline void superio_outb(int addr, int val)
{
outb_p(addr, superio_cmd);
outb_p(val, superio_cmd + 1);
}
static inline int superio_inb(int addr)
{
outb_p(addr, superio_cmd);
return inb_p(superio_cmd + 1);
}
static int pc8736x_superio_present(void)
{
int id;
superio_cmd = SIO_BASE1;
id = superio_inb(SIO_SID);
if (id == SIO_SID_PC87365 || id == SIO_SID_PC87366)
return superio_cmd;
superio_cmd = SIO_BASE2;
id = superio_inb(SIO_SID);
if (id == SIO_SID_PC87365 || id == SIO_SID_PC87366)
return superio_cmd;
return 0;
}
static void device_select(unsigned devldn)
{
superio_outb(SIO_UNIT_SEL, devldn);
selected_device = devldn;
}
static void select_pin(unsigned iminor)
{
device_select(SIO_GPIO_UNIT);
superio_outb(SIO_GPIO_PIN_SELECT,
((iminor << 1) & 0xF0) | (iminor & 0x7));
}
static inline u32 pc8736x_gpio_configure_fn(unsigned index, u32 mask, u32 bits,
u32 func_slct)
{
u32 config, new_config;
mutex_lock(&pc8736x_gpio_config_lock);
device_select(SIO_GPIO_UNIT);
select_pin(index);
config = superio_inb(func_slct);
new_config = (config & mask) | bits;
superio_outb(func_slct, new_config);
mutex_unlock(&pc8736x_gpio_config_lock);
return config;
}
static u32 pc8736x_gpio_configure(unsigned index, u32 mask, u32 bits)
{
return pc8736x_gpio_configure_fn(index, mask, bits,
SIO_GPIO_PIN_CONFIG);
}
static int pc8736x_gpio_get(unsigned minor)
{
int port, bit, val;
port = minor >> 3;
bit = minor & 7;
val = inb_p(pc8736x_gpio_base + port_offset[port] + PORT_IN);
val >>= bit;
val &= 1;
dev_dbg(&pdev->dev, "_gpio_get(%d from %x bit %d) == val %d\n",
minor, pc8736x_gpio_base + port_offset[port] + PORT_IN, bit,
val);
return val;
}
static void pc8736x_gpio_set(unsigned minor, int val)
{
int port, bit, curval;
minor &= 0x1f;
port = minor >> 3;
bit = minor & 7;
curval = inb_p(pc8736x_gpio_base + port_offset[port] + PORT_OUT);
dev_dbg(&pdev->dev, "addr:%x cur:%x bit-pos:%d cur-bit:%x + new:%d -> bit-new:%d\n",
pc8736x_gpio_base + port_offset[port] + PORT_OUT,
curval, bit, (curval & ~(1 << bit)), val, (val << bit));
val = (curval & ~(1 << bit)) | (val << bit);
dev_dbg(&pdev->dev, "gpio_set(minor:%d port:%d bit:%d)"
" %2x -> %2x\n", minor, port, bit, curval, val);
outb_p(val, pc8736x_gpio_base + port_offset[port] + PORT_OUT);
curval = inb_p(pc8736x_gpio_base + port_offset[port] + PORT_OUT);
val = inb_p(pc8736x_gpio_base + port_offset[port] + PORT_IN);
dev_dbg(&pdev->dev, "wrote %x, read: %x\n", curval, val);
pc8736x_gpio_shadow[port] = val;
}
static int pc8736x_gpio_current(unsigned minor)
{
int port, bit;
minor &= 0x1f;
port = minor >> 3;
bit = minor & 7;
return ((pc8736x_gpio_shadow[port] >> bit) & 0x01);
}
static void pc8736x_gpio_change(unsigned index)
{
pc8736x_gpio_set(index, !pc8736x_gpio_current(index));
}
static int pc8736x_gpio_open(struct inode *inode, struct file *file)
{
unsigned m = iminor(inode);
file->private_data = &pc8736x_gpio_ops;
dev_dbg(&pdev->dev, "open %d\n", m);
if (m >= PC8736X_GPIO_CT)
return -EINVAL;
return nonseekable_open(inode, file);
}
static void __init pc8736x_init_shadow(void)
{
int port;
for (port = 0; port < 4; ++port)
pc8736x_gpio_shadow[port]
= inb_p(pc8736x_gpio_base + port_offset[port]
+ PORT_OUT);
}
static int __init pc8736x_gpio_init(void)
{
int rc;
dev_t devid;
pdev = platform_device_alloc(DEVNAME, 0);
if (!pdev)
return -ENOMEM;
rc = platform_device_add(pdev);
if (rc) {
rc = -ENODEV;
goto undo_platform_dev_alloc;
}
dev_info(&pdev->dev, "NatSemi pc8736x GPIO Driver Initializing\n");
if (!pc8736x_superio_present()) {
rc = -ENODEV;
dev_err(&pdev->dev, "no device found\n");
goto undo_platform_dev_add;
}
pc8736x_gpio_ops.dev = &pdev->dev;
rc = superio_inb(SIO_CF1);
if (!(rc & 0x01)) {
rc = -ENODEV;
dev_err(&pdev->dev, "device not enabled\n");
goto undo_platform_dev_add;
}
device_select(SIO_GPIO_UNIT);
if (!superio_inb(SIO_UNIT_ACT)) {
rc = -ENODEV;
dev_err(&pdev->dev, "GPIO unit not enabled\n");
goto undo_platform_dev_add;
}
pc8736x_gpio_base = (superio_inb(SIO_BASE_HADDR) << 8
| superio_inb(SIO_BASE_LADDR));
if (!request_region(pc8736x_gpio_base, PC8736X_GPIO_RANGE, DEVNAME)) {
rc = -ENODEV;
dev_err(&pdev->dev, "GPIO ioport %x busy\n",
pc8736x_gpio_base);
goto undo_platform_dev_add;
}
dev_info(&pdev->dev, "GPIO ioport %x reserved\n", pc8736x_gpio_base);
if (major) {
devid = MKDEV(major, 0);
rc = register_chrdev_region(devid, PC8736X_GPIO_CT, DEVNAME);
} else {
rc = alloc_chrdev_region(&devid, 0, PC8736X_GPIO_CT, DEVNAME);
major = MAJOR(devid);
}
if (rc < 0) {
dev_err(&pdev->dev, "register-chrdev failed: %d\n", rc);
goto undo_request_region;
}
if (!major) {
major = rc;
dev_dbg(&pdev->dev, "got dynamic major %d\n", major);
}
pc8736x_init_shadow();
cdev_init(&pc8736x_gpio_cdev, &pc8736x_gpio_fileops);
cdev_add(&pc8736x_gpio_cdev, devid, PC8736X_GPIO_CT);
return 0;
undo_request_region:
release_region(pc8736x_gpio_base, PC8736X_GPIO_RANGE);
undo_platform_dev_add:
platform_device_del(pdev);
undo_platform_dev_alloc:
platform_device_put(pdev);
return rc;
}
static void __exit pc8736x_gpio_cleanup(void)
{
dev_dbg(&pdev->dev, "cleanup\n");
cdev_del(&pc8736x_gpio_cdev);
unregister_chrdev_region(MKDEV(major,0), PC8736X_GPIO_CT);
release_region(pc8736x_gpio_base, PC8736X_GPIO_RANGE);
platform_device_del(pdev);
platform_device_put(pdev);
}
