static void set_scl(u8 value)
{
gpio_set_value(GPIO_SCL, !!value);
udelay(3);
}
static void set_sda(u8 value)
{
gpio_set_value(GPIO_SDA, !!value);
udelay(3);
}
static void set_str(u8 value)
{
gpio_set_value(GPIO_STR, !!value);
udelay(3);
}
static inline void set_control(int line, int value)
{
if (value)
control_value |= (1 << line);
else
control_value &= ~(1 << line);
}
static void output_control(void)
{
int i;
gpio_direction_output(GPIO_SCL, 1);
gpio_direction_output(GPIO_SDA, 1);
for (i = 0; i < 8; i++) {
set_scl(0);
set_sda(control_value & (0x80 >> i));
set_scl(1);
}
set_str(1);
set_str(0);
set_scl(0);
set_sda(1);
set_scl(1);
}
static int hss_set_clock(int port, unsigned int clock_type)
{
int ctrl_int = port ? CONTROL_HSS1_CLK_INT : CONTROL_HSS0_CLK_INT;
switch (clock_type) {
case CLOCK_DEFAULT:
case CLOCK_EXT:
set_control(ctrl_int, 0);
output_control();
return CLOCK_EXT;
case CLOCK_INT:
set_control(ctrl_int, 1);
output_control();
return CLOCK_INT;
default:
return -EINVAL;
}
}
static irqreturn_t hss_dcd_irq(int irq, void *pdev)
{
int port = (irq == IXP4XX_GPIO_IRQ(GPIO_HSS1_DCD_N));
int i = gpio_get_value(port ? GPIO_HSS1_DCD_N : GPIO_HSS0_DCD_N);
set_carrier_cb_tab[port](pdev, !i);
return IRQ_HANDLED;
}
static int hss_open(int port, void *pdev,
void (*set_carrier_cb)(void *pdev, int carrier))
{
int i, irq;
if (!port)
irq = IXP4XX_GPIO_IRQ(GPIO_HSS0_DCD_N);
else
irq = IXP4XX_GPIO_IRQ(GPIO_HSS1_DCD_N);
i = gpio_get_value(port ? GPIO_HSS1_DCD_N : GPIO_HSS0_DCD_N);
set_carrier_cb(pdev, !i);
set_carrier_cb_tab[!!port] = set_carrier_cb;
if ((i = request_irq(irq, hss_dcd_irq, 0, "IXP4xx HSS", pdev)) != 0) {
printk(KERN_ERR "ixp4xx_hss: failed to request IRQ%i (%i)\n",
irq, i);
return i;
}
set_control(port ? CONTROL_HSS1_DTR_N : CONTROL_HSS0_DTR_N, 0);
output_control();
gpio_set_value(port ? GPIO_HSS1_RTS_N : GPIO_HSS0_RTS_N, 0);
return 0;
}
static void hss_close(int port, void *pdev)
{
free_irq(port ? IXP4XX_GPIO_IRQ(GPIO_HSS1_DCD_N) :
IXP4XX_GPIO_IRQ(GPIO_HSS0_DCD_N), pdev);
set_carrier_cb_tab[!!port] = NULL;
set_control(port ? CONTROL_HSS1_DTR_N : CONTROL_HSS0_DTR_N, 1);
output_control();
gpio_set_value(port ? GPIO_HSS1_RTS_N : GPIO_HSS0_RTS_N, 1);
}
static inline u8 __init flash_readb(u8 __iomem *flash, u32 addr)
{
#ifdef __ARMEB__
return __raw_readb(flash + addr);
#else
return __raw_readb(flash + (addr ^ 3));
#endif
}
static inline u16 __init flash_readw(u8 __iomem *flash, u32 addr)
{
#ifdef __ARMEB__
return __raw_readw(flash + addr);
#else
return __raw_readw(flash + (addr ^ 2));
#endif
}
static void __init gmlr_init(void)
{
u8 __iomem *flash;
int i, devices = 1;
ixp4xx_sys_init();
if ((flash = ioremap(IXP4XX_EXP_BUS_BASE_PHYS, 0x80)) == NULL)
printk(KERN_ERR "goramo-mlr: unable to access system"
" configuration data\n");
else {
system_rev = __raw_readl(flash + CFG_REV);
hw_bits = __raw_readl(flash + CFG_HW_BITS);
for (i = 0; i < ETH_ALEN; i++) {
eth_plat[0].hwaddr[i] =
flash_readb(flash, CFG_ETH0_ADDRESS + i);
eth_plat[1].hwaddr[i] =
flash_readb(flash, CFG_ETH1_ADDRESS + i);
}
__raw_writew(FLASH_CMD_READ_ID, flash);
system_serial_high = flash_readw(flash, FLASH_SER_OFF);
system_serial_high <<= 16;
system_serial_high |= flash_readw(flash, FLASH_SER_OFF + 2);
system_serial_low = flash_readw(flash, FLASH_SER_OFF + 4);
system_serial_low <<= 16;
system_serial_low |= flash_readw(flash, FLASH_SER_OFF + 6);
__raw_writew(FLASH_CMD_READ_ARRAY, flash);
iounmap(flash);
}
switch (hw_bits & (CFG_HW_HAS_UART0 | CFG_HW_HAS_UART1)) {
case CFG_HW_HAS_UART0:
memset(&uart_data[1], 0, sizeof(uart_data[1]));
device_uarts.num_resources = 1;
break;
case CFG_HW_HAS_UART1:
device_uarts.dev.platform_data = &uart_data[1];
device_uarts.resource = &uart_resources[1];
device_uarts.num_resources = 1;
break;
}
if (hw_bits & (CFG_HW_HAS_UART0 | CFG_HW_HAS_UART1))
device_tab[devices++] = &device_uarts;
if (hw_bits & CFG_HW_HAS_ETH0)
device_tab[devices++] = &device_eth_tab[0];
if (hw_bits & CFG_HW_HAS_ETH1)
device_tab[devices++] = &device_eth_tab[1];
if (hw_bits & CFG_HW_HAS_HSS0)
device_tab[devices++] = &device_hss_tab[0];
if (hw_bits & CFG_HW_HAS_HSS1)
device_tab[devices++] = &device_hss_tab[1];
if (hw_bits & CFG_HW_HAS_EEPROM)
device_tab[devices++] = &device_i2c;
gpio_request(GPIO_SCL, "SCL/clock");
gpio_request(GPIO_SDA, "SDA/data");
gpio_request(GPIO_STR, "strobe");
gpio_request(GPIO_HSS0_RTS_N, "HSS0 RTS");
gpio_request(GPIO_HSS1_RTS_N, "HSS1 RTS");
gpio_request(GPIO_HSS0_DCD_N, "HSS0 DCD");
gpio_request(GPIO_HSS1_DCD_N, "HSS1 DCD");
gpio_direction_output(GPIO_SCL, 1);
gpio_direction_output(GPIO_SDA, 1);
gpio_direction_output(GPIO_STR, 0);
gpio_direction_output(GPIO_HSS0_RTS_N, 1);
gpio_direction_output(GPIO_HSS1_RTS_N, 1);
gpio_direction_input(GPIO_HSS0_DCD_N);
gpio_direction_input(GPIO_HSS1_DCD_N);
irq_set_irq_type(IXP4XX_GPIO_IRQ(GPIO_HSS0_DCD_N), IRQ_TYPE_EDGE_BOTH);
irq_set_irq_type(IXP4XX_GPIO_IRQ(GPIO_HSS1_DCD_N), IRQ_TYPE_EDGE_BOTH);
set_control(CONTROL_HSS0_DTR_N, 1);
set_control(CONTROL_HSS1_DTR_N, 1);
set_control(CONTROL_EEPROM_WC_N, 1);
set_control(CONTROL_PCI_RESET_N, 1);
output_control();
msleep(1);
flash_resource.start = IXP4XX_EXP_BUS_BASE(0);
flash_resource.end = IXP4XX_EXP_BUS_BASE(0) + ixp4xx_exp_bus_size - 1;
platform_add_devices(device_tab, devices);
}
static void __init gmlr_pci_preinit(void)
{
irq_set_irq_type(IXP4XX_GPIO_IRQ(GPIO_IRQ_ETHA), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(GPIO_IRQ_ETHB), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(GPIO_IRQ_NEC), IRQ_TYPE_LEVEL_LOW);
irq_set_irq_type(IXP4XX_GPIO_IRQ(GPIO_IRQ_MPCI), IRQ_TYPE_LEVEL_LOW);
ixp4xx_pci_preinit();
}
static void __init gmlr_pci_postinit(void)
{
if ((hw_bits & CFG_HW_USB_PORTS) >= 2 &&
(hw_bits & CFG_HW_USB_PORTS) < 5) {
u32 value, addr = BIT(32 - SLOT_NEC) | 0xE0;
if (!ixp4xx_pci_read(addr, NP_CMD_CONFIGREAD, &value)) {
value &= ~7;
value |= (hw_bits & CFG_HW_USB_PORTS);
ixp4xx_pci_write(addr, NP_CMD_CONFIGWRITE, value);
}
}
}
static int __init gmlr_map_irq(const struct pci_dev *dev, u8 slot, u8 pin)
{
switch(slot) {
case SLOT_ETHA: return IXP4XX_GPIO_IRQ(GPIO_IRQ_ETHA);
case SLOT_ETHB: return IXP4XX_GPIO_IRQ(GPIO_IRQ_ETHB);
case SLOT_NEC: return IXP4XX_GPIO_IRQ(GPIO_IRQ_NEC);
default: return IXP4XX_GPIO_IRQ(GPIO_IRQ_MPCI);
}
}
static int __init gmlr_pci_init(void)
{
if (machine_is_goramo_mlr() &&
(hw_bits & (CFG_HW_USB_PORTS | CFG_HW_HAS_PCI_SLOT)))
pci_common_init(&gmlr_hw_pci);
return 0;
}
