static void dcon_clear_irq(void)
{
outb(BIT_GPIO12, VX855_GPI_STATUS_CHG);
}
static int dcon_was_irq(void)
{
u_int8_t tmp;
tmp = inb(VX855_GPI_STATUS_CHG);
return !!(tmp & BIT_GPIO12);
return 0;
}
static int dcon_init_xo_1_5(struct dcon_priv *dcon)
{
unsigned int irq;
u_int8_t tmp;
struct pci_dev *pdev;
pdev = pci_get_device(PCI_VENDOR_ID_VIA,
PCI_DEVICE_ID_VIA_VX855, NULL);
if (!pdev) {
printk(KERN_ERR "cannot find VX855 PCI ID\n");
return 1;
}
pci_read_config_byte(pdev, 0x95, &tmp);
pci_write_config_byte(pdev, 0x95, tmp|0x0c);
pci_read_config_byte(pdev, 0xe3, &tmp);
pci_write_config_byte(pdev, 0xe3, tmp | 0x04);
pci_read_config_byte(pdev, 0xe4, &tmp);
pci_write_config_byte(pdev, 0xe4, tmp|0x08);
pci_read_config_byte(pdev, 0xe1, &tmp);
pci_write_config_byte(pdev, 0xe1, tmp & ~BIT_GPIO12);
pci_read_config_byte(pdev, 0xe0, &tmp);
pci_write_config_byte(pdev, 0xe0, tmp & ~BIT_GPIO12);
dcon_clear_irq();
outb(inb(VX855_GPI_SCI_SMI)|BIT_GPIO12, VX855_GPI_SCI_SMI);
dcon->curr_src = (inl(VX855_GENL_PURPOSE_OUTPUT) & 0x1000) ?
DCON_SOURCE_CPU : DCON_SOURCE_DCON;
dcon->pending_src = dcon->curr_src;
pci_dev_put(pdev);
irq = acpi_gbl_FADT.sci_interrupt;
if (request_irq(irq, &dcon_interrupt, IRQF_SHARED, "DCON", dcon)) {
printk(KERN_ERR PREFIX "DCON (IRQ%d) allocation failed\n", irq);
return 1;
}
return 0;
}
static void set_i2c_line(int sda, int scl)
{
unsigned char tmp;
unsigned int port = 0x26;
outb(port, 0x3c4);
tmp = inb(0x3c5);
if (scl)
tmp |= 0x20;
else
tmp &= ~0x20;
if (sda)
tmp |= 0x10;
else
tmp &= ~0x10;
tmp |= 0x01;
outb(port, 0x3c4);
outb(tmp, 0x3c5);
}
static void dcon_wiggle_xo_1_5(void)
{
int x;
set_i2c_line(1, 1);
for (x = 0; x < 16; x++) {
udelay(5);
set_i2c_line(1, 0);
udelay(5);
set_i2c_line(1, 1);
}
udelay(5);
outb(inb(VX855_GPI_SCI_SMI)|BIT_GPIO12, VX855_GPI_SCI_SMI);
}
static void dcon_set_dconload_xo_1_5(int val)
{
gpio_set_value(VX855_GPIO(1), val);
}
static u8 dcon_read_status_xo_1_5(void)
{
u8 status;
if (!dcon_was_irq())
return -1;
status = gpio_get_value(VX855_GPI(10));
status |= gpio_get_value(VX855_GPI(11)) << 1;
dcon_clear_irq();
return status;
}
