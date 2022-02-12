static struct pci_dev *do_pci_probe(void)
{
struct pci_dev *my_dev;
my_dev = pci_get_device(PCI_VENDOR_ID_ATI,
PCI_DEVICE_ID_ATI_264VT, NULL);
if (my_dev) {
printk(KERN_ERR DRIVER_NAME ": Using device: %s\n",
pci_name(my_dev));
pci_addr_phys = 0;
if (my_dev->resource[0].flags & IORESOURCE_MEM) {
pci_addr_phys = my_dev->resource[0].start;
printk(KERN_INFO DRIVER_NAME ": memory at 0x%08X\n",
(unsigned int)pci_addr_phys);
}
if (pci_addr_phys == 0) {
printk(KERN_ERR DRIVER_NAME ": no memory resource ?\n");
return NULL;
}
} else {
printk(KERN_ERR DRIVER_NAME ": pci_probe failed\n");
return NULL;
}
return my_dev;
}
static int atir_add_to_buf(void *data, struct lirc_buffer *buf)
{
unsigned char key;
int status;
status = poll_main();
key = (status >> 8) & 0xFF;
if (status & 0xFF) {
dprintk("reading key %02X\n", key);
lirc_buffer_write(buf, &key);
return 0;
}
return -ENODATA;
}
static int atir_set_use_inc(void *data)
{
dprintk("driver is opened\n");
return 0;
}
static void atir_set_use_dec(void *data)
{
dprintk("driver is closed\n");
}
int init_module(void)
{
struct pci_dev *pdev;
pdev = do_pci_probe();
if (pdev == NULL)
return 1;
if (!atir_init_start())
return 1;
strcpy(atir_driver.name, "ATIR");
atir_driver.minor = -1;
atir_driver.code_length = 8;
atir_driver.sample_rate = 10;
atir_driver.data = 0;
atir_driver.add_to_buf = atir_add_to_buf;
atir_driver.set_use_inc = atir_set_use_inc;
atir_driver.set_use_dec = atir_set_use_dec;
atir_driver.dev = &pdev->dev;
atir_driver.owner = THIS_MODULE;
atir_minor = lirc_register_driver(&atir_driver);
if (atir_minor < 0) {
printk(KERN_ERR DRIVER_NAME ": failed to register driver!\n");
return atir_minor;
}
dprintk("driver is registered on minor %d\n", atir_minor);
return 0;
}
void cleanup_module(void)
{
lirc_unregister_driver(atir_minor);
}
static int atir_init_start(void)
{
pci_addr_lin = ioremap(pci_addr_phys + DATA_PCI_OFF, 0x400);
if (pci_addr_lin == 0) {
printk(KERN_INFO DRIVER_NAME ": pci mem must be mapped\n");
return 0;
}
return 1;
}
static void cycle_delay(int cycle)
{
udelay(WAIT_CYCLE*cycle);
}
static int poll_main()
{
unsigned char status_high, status_low;
do_i2c_start();
seems_wr_byte(0xAA);
seems_wr_byte(0x01);
do_i2c_start();
seems_wr_byte(0xAB);
status_low = seems_rd_byte();
status_high = seems_rd_byte();
do_i2c_stop();
return (status_high << 8) | status_low;
}
static void do_i2c_start(void)
{
do_set_bits(3);
cycle_delay(4);
do_set_bits(1);
cycle_delay(7);
do_set_bits(0);
cycle_delay(2);
}
static void do_i2c_stop(void)
{
unsigned char bits;
bits = do_get_bits() & 0xFD;
do_set_bits(bits);
cycle_delay(1);
bits |= 1;
do_set_bits(bits);
cycle_delay(2);
bits |= 2;
do_set_bits(bits);
bits = 3;
do_set_bits(bits);
cycle_delay(2);
}
static void seems_wr_byte(unsigned char value)
{
int i;
unsigned char reg;
reg = do_get_bits();
for (i = 0; i < 8; i++) {
if (value & 0x80)
reg |= 0x02;
else
reg &= 0xFD;
do_set_bits(reg);
cycle_delay(1);
reg |= 1;
do_set_bits(reg);
cycle_delay(1);
reg &= 0xFE;
do_set_bits(reg);
cycle_delay(1);
value <<= 1;
}
cycle_delay(2);
reg |= 2;
do_set_bits(reg);
reg |= 1;
do_set_bits(reg);
cycle_delay(1);
do_get_bits();
reg &= 0xFE;
do_set_bits(reg);
cycle_delay(3);
}
static unsigned char seems_rd_byte(void)
{
int i;
int rd_byte;
unsigned char bits_2, bits_1;
bits_1 = do_get_bits() | 2;
do_set_bits(bits_1);
rd_byte = 0;
for (i = 0; i < 8; i++) {
bits_1 &= 0xFE;
do_set_bits(bits_1);
cycle_delay(2);
bits_1 |= 1;
do_set_bits(bits_1);
cycle_delay(1);
bits_2 = do_get_bits();
if (bits_2 & 2)
rd_byte |= 1;
rd_byte <<= 1;
}
bits_1 = 0;
if (bits_2 == 0)
bits_1 |= 2;
do_set_bits(bits_1);
cycle_delay(2);
bits_1 |= 1;
do_set_bits(bits_1);
cycle_delay(3);
bits_1 &= 0xFE;
do_set_bits(bits_1);
cycle_delay(2);
rd_byte >>= 1;
rd_byte &= 0xFF;
return rd_byte;
}
static void do_set_bits(unsigned char new_bits)
{
int reg_val;
reg_val = read_index(0x34);
if (new_bits & 2) {
reg_val &= 0xFFFFFFDF;
reg_val |= 1;
} else {
reg_val &= 0xFFFFFFFE;
reg_val |= 0x20;
}
reg_val |= 0x10;
write_index(0x34, reg_val);
reg_val = read_index(0x31);
if (new_bits & 1)
reg_val |= 0x1000000;
else
reg_val &= 0xFEFFFFFF;
reg_val |= 0x8000000;
write_index(0x31, reg_val);
}
static unsigned char do_get_bits(void)
{
unsigned char bits;
int reg_val;
reg_val = read_index(0x34);
reg_val |= 0x10;
reg_val &= 0xFFFFFFDF;
write_index(0x34, reg_val);
reg_val = read_index(0x34);
bits = 0;
if (reg_val & 8)
bits |= 2;
else
bits &= 0xFD;
reg_val = read_index(0x31);
if (reg_val & 0x1000000)
bits |= 1;
else
bits &= 0xFE;
return bits;
}
static unsigned int read_index(unsigned char index)
{
unsigned char *addr;
unsigned int value;
addr = pci_addr_lin + ((index & 0xFF) << 2);
value = readl(addr);
return value;
}
static void write_index(unsigned char index, unsigned int reg_val)
{
unsigned char *addr;
addr = pci_addr_lin + ((index & 0xFF) << 2);
writel(reg_val, addr);
}
