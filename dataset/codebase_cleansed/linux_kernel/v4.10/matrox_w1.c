static __inline__ u8 matrox_w1_read_reg(struct matrox_device *dev, u8 reg)
{
u8 ret;
writeb(reg, dev->port_index);
ret = readb(dev->port_data);
barrier();
return ret;
}
static __inline__ void matrox_w1_write_reg(struct matrox_device *dev, u8 reg, u8 val)
{
writeb(reg, dev->port_index);
writeb(val, dev->port_data);
wmb();
}
static void matrox_w1_write_ddc_bit(void *data, u8 bit)
{
u8 ret;
struct matrox_device *dev = data;
if (bit)
bit = 0;
else
bit = dev->data_mask;
ret = matrox_w1_read_reg(dev, MATROX_GET_CONTROL);
matrox_w1_write_reg(dev, MATROX_GET_CONTROL, ((ret & ~dev->data_mask) | bit));
matrox_w1_write_reg(dev, MATROX_GET_DATA, 0x00);
}
static u8 matrox_w1_read_ddc_bit(void *data)
{
u8 ret;
struct matrox_device *dev = data;
ret = matrox_w1_read_reg(dev, MATROX_GET_DATA);
return ret;
}
static void matrox_w1_hw_init(struct matrox_device *dev)
{
matrox_w1_write_reg(dev, MATROX_GET_DATA, 0xFF);
matrox_w1_write_reg(dev, MATROX_GET_CONTROL, 0x00);
}
static int matrox_w1_probe(struct pci_dev *pdev, const struct pci_device_id *ent)
{
struct matrox_device *dev;
int err;
assert(pdev != NULL);
assert(ent != NULL);
if (pdev->vendor != PCI_VENDOR_ID_MATROX || pdev->device != PCI_DEVICE_ID_MATROX_G400)
return -ENODEV;
dev = kzalloc(sizeof(struct matrox_device) +
sizeof(struct w1_bus_master), GFP_KERNEL);
if (!dev) {
dev_err(&pdev->dev,
"%s: Failed to create new matrox_device object.\n",
__func__);
return -ENOMEM;
}
dev->bus_master = (struct w1_bus_master *)(dev + 1);
dev->phys_addr = pci_resource_start(pdev, 1);
dev->virt_addr = ioremap_nocache(dev->phys_addr, 16384);
if (!dev->virt_addr) {
dev_err(&pdev->dev, "%s: failed to ioremap(0x%lx, %d).\n",
__func__, dev->phys_addr, 16384);
err = -EIO;
goto err_out_free_device;
}
dev->base_addr = dev->virt_addr + MATROX_BASE;
dev->port_index = dev->base_addr + MATROX_PORT_INDEX_OFFSET;
dev->port_data = dev->base_addr + MATROX_PORT_DATA_OFFSET;
dev->data_mask = (MATROX_G400_DDC_DATA);
matrox_w1_hw_init(dev);
dev->bus_master->data = dev;
dev->bus_master->read_bit = &matrox_w1_read_ddc_bit;
dev->bus_master->write_bit = &matrox_w1_write_ddc_bit;
err = w1_add_master_device(dev->bus_master);
if (err)
goto err_out_free_device;
pci_set_drvdata(pdev, dev);
dev->found = 1;
dev_info(&pdev->dev, "Matrox G400 GPIO transport layer for 1-wire.\n");
return 0;
err_out_free_device:
if (dev->virt_addr)
iounmap(dev->virt_addr);
kfree(dev);
return err;
}
static void matrox_w1_remove(struct pci_dev *pdev)
{
struct matrox_device *dev = pci_get_drvdata(pdev);
assert(dev != NULL);
if (dev->found) {
w1_remove_master_device(dev->bus_master);
iounmap(dev->virt_addr);
}
kfree(dev);
}
