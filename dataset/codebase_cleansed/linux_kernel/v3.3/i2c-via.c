static void bit_via_setscl(void *data, int state)
{
outb(state ? inb(I2C_DIR) & ~I2C_SCL : inb(I2C_DIR) | I2C_SCL, I2C_DIR);
}
static void bit_via_setsda(void *data, int state)
{
outb(state ? inb(I2C_DIR) & ~I2C_SDA : inb(I2C_DIR) | I2C_SDA, I2C_DIR);
}
static int bit_via_getscl(void *data)
{
return (0 != (inb(I2C_IN) & I2C_SCL));
}
static int bit_via_getsda(void *data)
{
return (0 != (inb(I2C_IN) & I2C_SDA));
}
static int __devinit vt586b_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
u16 base;
u8 rev;
int res;
if (pm_io_base) {
dev_err(&dev->dev, "i2c-via: Will only support one host\n");
return -ENODEV;
}
pci_read_config_byte(dev, PM_CFG_REVID, &rev);
switch (rev) {
case 0x00:
base = PM_CFG_IOBASE0;
break;
case 0x01:
case 0x10:
base = PM_CFG_IOBASE1;
break;
default:
base = PM_CFG_IOBASE1;
}
pci_read_config_word(dev, base, &pm_io_base);
pm_io_base &= (0xff << 8);
if (!request_region(I2C_DIR, IOSPACE, vt586b_driver.name)) {
dev_err(&dev->dev, "IO 0x%x-0x%x already in use\n", I2C_DIR, I2C_DIR + IOSPACE);
return -ENODEV;
}
outb(inb(I2C_DIR) & ~(I2C_SDA | I2C_SCL), I2C_DIR);
outb(inb(I2C_OUT) & ~(I2C_SDA | I2C_SCL), I2C_OUT);
vt586b_adapter.dev.parent = &dev->dev;
res = i2c_bit_add_bus(&vt586b_adapter);
if ( res < 0 ) {
release_region(I2C_DIR, IOSPACE);
pm_io_base = 0;
return res;
}
return 0;
}
static void __devexit vt586b_remove(struct pci_dev *dev)
{
i2c_del_adapter(&vt586b_adapter);
release_region(I2C_DIR, IOSPACE);
pm_io_base = 0;
}
static int __init i2c_vt586b_init(void)
{
return pci_register_driver(&vt586b_driver);
}
static void __exit i2c_vt586b_exit(void)
{
pci_unregister_driver(&vt586b_driver);
}
