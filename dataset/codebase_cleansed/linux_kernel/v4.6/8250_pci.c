static void moan_device(const char *str, struct pci_dev *dev)
{
dev_err(&dev->dev,
"%s: %s\n"
"Please send the output of lspci -vv, this\n"
"message (0x%04x,0x%04x,0x%04x,0x%04x), the\n"
"manufacturer and name of serial board or\n"
"modem board to <linux-serial@vger.kernel.org>.\n",
pci_name(dev), str, dev->vendor, dev->device,
dev->subsystem_vendor, dev->subsystem_device);
}
static int
setup_port(struct serial_private *priv, struct uart_8250_port *port,
int bar, int offset, int regshift)
{
struct pci_dev *dev = priv->dev;
if (bar >= PCI_NUM_BAR_RESOURCES)
return -EINVAL;
if (pci_resource_flags(dev, bar) & IORESOURCE_MEM) {
if (!pcim_iomap(dev, bar, 0) && !pcim_iomap_table(dev))
return -ENOMEM;
port->port.iotype = UPIO_MEM;
port->port.iobase = 0;
port->port.mapbase = pci_resource_start(dev, bar) + offset;
port->port.membase = pcim_iomap_table(dev)[bar] + offset;
port->port.regshift = regshift;
} else {
port->port.iotype = UPIO_PORT;
port->port.iobase = pci_resource_start(dev, bar) + offset;
port->port.mapbase = 0;
port->port.membase = NULL;
port->port.regshift = 0;
}
return 0;
}
static int addidata_apci7800_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
unsigned int bar = 0, offset = board->first_offset;
bar = FL_GET_BASE(board->flags);
if (idx < 2) {
offset += idx * board->uart_offset;
} else if ((idx >= 2) && (idx < 4)) {
bar += 1;
offset += ((idx - 2) * board->uart_offset);
} else if ((idx >= 4) && (idx < 6)) {
bar += 2;
offset += ((idx - 4) * board->uart_offset);
} else if (idx >= 6) {
bar += 3;
offset += ((idx - 6) * board->uart_offset);
}
return setup_port(priv, port, bar, offset, board->reg_shift);
}
static int
afavlab_setup(struct serial_private *priv, const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
unsigned int bar, offset = board->first_offset;
bar = FL_GET_BASE(board->flags);
if (idx < 4)
bar += idx;
else {
bar = 4;
offset += (idx - 4) * board->uart_offset;
}
return setup_port(priv, port, bar, offset, board->reg_shift);
}
static int pci_hp_diva_init(struct pci_dev *dev)
{
int rc = 0;
switch (dev->subsystem_device) {
case PCI_DEVICE_ID_HP_DIVA_TOSCA1:
case PCI_DEVICE_ID_HP_DIVA_HALFDOME:
case PCI_DEVICE_ID_HP_DIVA_KEYSTONE:
case PCI_DEVICE_ID_HP_DIVA_EVEREST:
rc = 3;
break;
case PCI_DEVICE_ID_HP_DIVA_TOSCA2:
rc = 2;
break;
case PCI_DEVICE_ID_HP_DIVA_MAESTRO:
rc = 4;
break;
case PCI_DEVICE_ID_HP_DIVA_POWERBAR:
case PCI_DEVICE_ID_HP_DIVA_HURRICANE:
rc = 1;
break;
}
return rc;
}
static int
pci_hp_diva_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
unsigned int offset = board->first_offset;
unsigned int bar = FL_GET_BASE(board->flags);
switch (priv->dev->subsystem_device) {
case PCI_DEVICE_ID_HP_DIVA_MAESTRO:
if (idx == 3)
idx++;
break;
case PCI_DEVICE_ID_HP_DIVA_EVEREST:
if (idx > 0)
idx++;
if (idx > 2)
idx++;
break;
}
if (idx > 2)
offset = 0x18;
offset += idx * board->uart_offset;
return setup_port(priv, port, bar, offset, board->reg_shift);
}
static int pci_inteli960ni_init(struct pci_dev *dev)
{
u32 oldval;
if (!(dev->subsystem_device & 0x1000))
return -ENODEV;
pci_read_config_dword(dev, 0x44, &oldval);
if (oldval == 0x00001000L) {
dev_dbg(&dev->dev, "Local i960 firmware missing\n");
return -ENODEV;
}
return 0;
}
static int pci_plx9050_init(struct pci_dev *dev)
{
u8 irq_config;
void __iomem *p;
if ((pci_resource_flags(dev, 0) & IORESOURCE_MEM) == 0) {
moan_device("no memory in bar 0", dev);
return 0;
}
irq_config = 0x41;
if (dev->vendor == PCI_VENDOR_ID_PANACOM ||
dev->subsystem_vendor == PCI_SUBVENDOR_ID_EXSYS)
irq_config = 0x43;
if ((dev->vendor == PCI_VENDOR_ID_PLX) &&
(dev->device == PCI_DEVICE_ID_PLX_ROMULUS))
irq_config = 0x5b;
p = ioremap_nocache(pci_resource_start(dev, 0), 0x80);
if (p == NULL)
return -ENOMEM;
writel(irq_config, p + 0x4c);
readl(p + 0x4c);
iounmap(p);
return 0;
}
static void pci_plx9050_exit(struct pci_dev *dev)
{
u8 __iomem *p;
if ((pci_resource_flags(dev, 0) & IORESOURCE_MEM) == 0)
return;
p = ioremap_nocache(pci_resource_start(dev, 0), 0x80);
if (p != NULL) {
writel(0, p + 0x4c);
readl(p + 0x4c);
iounmap(p);
}
}
static void pci_ni8420_exit(struct pci_dev *dev)
{
void __iomem *p;
unsigned int bar = 0;
if ((pci_resource_flags(dev, bar) & IORESOURCE_MEM) == 0) {
moan_device("no memory in bar", dev);
return;
}
p = pci_ioremap_bar(dev, bar);
if (p == NULL)
return;
writel(readl(p + NI8420_INT_ENABLE_REG) & ~(NI8420_INT_ENABLE_BIT),
p + NI8420_INT_ENABLE_REG);
iounmap(p);
}
static void pci_ni8430_exit(struct pci_dev *dev)
{
void __iomem *p;
unsigned int bar = 0;
if ((pci_resource_flags(dev, bar) & IORESOURCE_MEM) == 0) {
moan_device("no memory in bar", dev);
return;
}
p = pci_ioremap_bar(dev, bar);
if (p == NULL)
return;
writel(MITE_LCIMR2_CLR_CPU_IE, p + MITE_LCIMR2);
iounmap(p);
}
static int
sbs_setup(struct serial_private *priv, const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
unsigned int bar, offset = board->first_offset;
bar = 0;
if (idx < 4) {
offset += idx * board->uart_offset;
} else if (idx < 8) {
offset += idx * board->uart_offset + 0xC00;
} else
return 1;
return setup_port(priv, port, bar, offset, board->reg_shift);
}
static int sbs_init(struct pci_dev *dev)
{
u8 __iomem *p;
p = pci_ioremap_bar(dev, 0);
if (p == NULL)
return -ENOMEM;
writeb(0x10, p + OCT_REG_CR_OFF);
udelay(50);
writeb(0x0, p + OCT_REG_CR_OFF);
writeb(0x4, p + OCT_REG_CR_OFF);
iounmap(p);
return 0;
}
static void sbs_exit(struct pci_dev *dev)
{
u8 __iomem *p;
p = pci_ioremap_bar(dev, 0);
if (p != NULL)
writeb(0, p + OCT_REG_CR_OFF);
iounmap(p);
}
static int pci_siig10x_init(struct pci_dev *dev)
{
u16 data;
void __iomem *p;
switch (dev->device & 0xfff8) {
case PCI_DEVICE_ID_SIIG_1S_10x:
data = 0xffdf;
break;
case PCI_DEVICE_ID_SIIG_2S_10x:
data = 0xf7ff;
break;
default:
data = 0xfffb;
break;
}
p = ioremap_nocache(pci_resource_start(dev, 0), 0x80);
if (p == NULL)
return -ENOMEM;
writew(readw(p + 0x28) & data, p + 0x28);
readw(p + 0x28);
iounmap(p);
return 0;
}
static int pci_siig20x_init(struct pci_dev *dev)
{
u8 data;
pci_read_config_byte(dev, 0x6f, &data);
pci_write_config_byte(dev, 0x6f, data & 0xef);
if (((dev->device & 0xfffc) == PCI_DEVICE_ID_SIIG_2S_20x) ||
((dev->device & 0xfffc) == PCI_DEVICE_ID_SIIG_2S1P_20x)) {
pci_read_config_byte(dev, 0x73, &data);
pci_write_config_byte(dev, 0x73, data & 0xef);
}
return 0;
}
static int pci_siig_init(struct pci_dev *dev)
{
unsigned int type = dev->device & 0xff00;
if (type == 0x1000)
return pci_siig10x_init(dev);
else if (type == 0x2000)
return pci_siig20x_init(dev);
moan_device("Unknown SIIG card", dev);
return -ENODEV;
}
static int pci_siig_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
unsigned int bar = FL_GET_BASE(board->flags) + idx, offset = 0;
if (idx > 3) {
bar = 4;
offset = (idx - 4) * 8;
}
return setup_port(priv, port, bar, offset, 0);
}
static int pci_timedia_probe(struct pci_dev *dev)
{
if ((dev->subsystem_device & 0x00f0) >= 0x70) {
dev_info(&dev->dev,
"ignoring Timedia subdevice %04x for parport_serial\n",
dev->subsystem_device);
return -ENODEV;
}
return 0;
}
static int pci_timedia_init(struct pci_dev *dev)
{
const unsigned short *ids;
int i, j;
for (i = 0; i < ARRAY_SIZE(timedia_data); i++) {
ids = timedia_data[i].ids;
for (j = 0; ids[j]; j++)
if (dev->subsystem_device == ids[j])
return timedia_data[i].num;
}
return 0;
}
static int
pci_timedia_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
unsigned int bar = 0, offset = board->first_offset;
switch (idx) {
case 0:
bar = 0;
break;
case 1:
offset = board->uart_offset;
bar = 0;
break;
case 2:
bar = 1;
break;
case 3:
offset = board->uart_offset;
case 4:
case 5:
case 6:
case 7:
bar = idx - 2;
}
return setup_port(priv, port, bar, offset, board->reg_shift);
}
static int
titan_400l_800l_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
unsigned int bar, offset = board->first_offset;
switch (idx) {
case 0:
bar = 1;
break;
case 1:
bar = 2;
break;
default:
bar = 4;
offset = (idx - 2) * board->uart_offset;
}
return setup_port(priv, port, bar, offset, board->reg_shift);
}
static int pci_xircom_init(struct pci_dev *dev)
{
msleep(100);
return 0;
}
static int pci_ni8420_init(struct pci_dev *dev)
{
void __iomem *p;
unsigned int bar = 0;
if ((pci_resource_flags(dev, bar) & IORESOURCE_MEM) == 0) {
moan_device("no memory in bar", dev);
return 0;
}
p = pci_ioremap_bar(dev, bar);
if (p == NULL)
return -ENOMEM;
writel(readl(p + NI8420_INT_ENABLE_REG) | NI8420_INT_ENABLE_BIT,
p + NI8420_INT_ENABLE_REG);
iounmap(p);
return 0;
}
static int pci_ni8430_init(struct pci_dev *dev)
{
void __iomem *p;
struct pci_bus_region region;
u32 device_window;
unsigned int bar = 0;
if ((pci_resource_flags(dev, bar) & IORESOURCE_MEM) == 0) {
moan_device("no memory in bar", dev);
return 0;
}
p = pci_ioremap_bar(dev, bar);
if (p == NULL)
return -ENOMEM;
pcibios_resource_to_bus(dev->bus, &region, &dev->resource[bar]);
device_window = ((region.start + MITE_IOWBSR1_WIN_OFFSET) & 0xffffff00)
| MITE_IOWBSR1_WENAB | MITE_IOWBSR1_WSIZE;
writel(device_window, p + MITE_IOWBSR1);
writel((readl(p + MITE_IOWCR1) & MITE_IOWCR1_RAMSEL_MASK),
p + MITE_IOWCR1);
writel(MITE_LCIMR1_IO_IE_0, p + MITE_LCIMR1);
writel(MITE_LCIMR2_SET_CPU_IE, p + MITE_LCIMR2);
iounmap(p);
return 0;
}
static int
pci_ni8430_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
struct pci_dev *dev = priv->dev;
void __iomem *p;
unsigned int bar, offset = board->first_offset;
if (idx >= board->num_ports)
return 1;
bar = FL_GET_BASE(board->flags);
offset += idx * board->uart_offset;
p = pci_ioremap_bar(dev, bar);
if (!p)
return -ENOMEM;
writeb(readb(p + offset + NI8430_PORTCON) | NI8430_PORTCON_TXVR_ENABLE,
p + offset + NI8430_PORTCON);
iounmap(p);
return setup_port(priv, port, bar, offset, board->reg_shift);
}
static int pci_netmos_9900_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
unsigned int bar;
if ((priv->dev->device != PCI_DEVICE_ID_NETMOS_9865) &&
(priv->dev->subsystem_device & 0xff00) == 0x3000) {
bar = 3 * idx;
return setup_port(priv, port, bar, 0, board->reg_shift);
} else {
return pci_default_setup(priv, board, port, idx);
}
}
static int pci_netmos_9900_numports(struct pci_dev *dev)
{
unsigned int c = dev->class;
unsigned int pi;
unsigned short sub_serports;
pi = c & 0xff;
if (pi == 2)
return 1;
if ((pi == 0) && (dev->device == PCI_DEVICE_ID_NETMOS_9900)) {
sub_serports = dev->subsystem_device & 0xf;
if (sub_serports > 0)
return sub_serports;
dev_err(&dev->dev,
"NetMos/Mostech serial driver ignoring port on ambiguous config.\n");
return 0;
}
moan_device("unknown NetMos/Mostech program interface", dev);
return 0;
}
static int pci_netmos_init(struct pci_dev *dev)
{
unsigned int num_serial = dev->subsystem_device & 0xf;
if ((dev->device == PCI_DEVICE_ID_NETMOS_9901) ||
(dev->device == PCI_DEVICE_ID_NETMOS_9865))
return 0;
if (dev->subsystem_vendor == PCI_VENDOR_ID_IBM &&
dev->subsystem_device == 0x0299)
return 0;
switch (dev->device) {
case PCI_DEVICE_ID_NETMOS_9904:
case PCI_DEVICE_ID_NETMOS_9912:
case PCI_DEVICE_ID_NETMOS_9922:
case PCI_DEVICE_ID_NETMOS_9900:
num_serial = pci_netmos_9900_numports(dev);
break;
default:
break;
}
if (num_serial == 0) {
moan_device("unknown NetMos/Mostech device", dev);
return -ENODEV;
}
return num_serial;
}
static int pci_ite887x_init(struct pci_dev *dev)
{
static const short inta_addr[] = { 0x2a0, 0x2c0, 0x220, 0x240, 0x1e0,
0x200, 0x280, 0 };
int ret, i, type;
struct resource *iobase = NULL;
u32 miscr, uartbar, ioport;
i = 0;
while (inta_addr[i] && iobase == NULL) {
iobase = request_region(inta_addr[i], ITE_887x_IOSIZE,
"ite887x");
if (iobase != NULL) {
pci_write_config_dword(dev, ITE_887x_POSIO0,
ITE_887x_POSIO_ENABLE | ITE_887x_POSIO_SPEED |
ITE_887x_POSIO_IOSIZE_32 | inta_addr[i]);
pci_write_config_dword(dev, ITE_887x_INTCBAR,
inta_addr[i]);
ret = inb(inta_addr[i]);
if (ret != 0xff) {
break;
}
release_region(iobase->start, ITE_887x_IOSIZE);
iobase = NULL;
}
i++;
}
if (!inta_addr[i]) {
dev_err(&dev->dev, "ite887x: could not find iobase\n");
return -ENODEV;
}
type = inb(iobase->start + 0x18) & 0x0f;
switch (type) {
case 0x2:
case 0xa:
ret = 0;
break;
case 0xe:
ret = 2;
break;
case 0x6:
ret = 1;
break;
case 0x8:
ret = 2;
break;
default:
moan_device("Unknown ITE887x", dev);
ret = -ENODEV;
}
for (i = 0; i < ret; i++) {
pci_read_config_dword(dev, ITE_887x_PS0BAR + (0x4 * (i + 1)),
&ioport);
ioport &= 0x0000FF00;
pci_write_config_dword(dev, ITE_887x_POSIO0 + (0x4 * (i + 1)),
ITE_887x_POSIO_ENABLE | ITE_887x_POSIO_SPEED |
ITE_887x_POSIO_IOSIZE_8 | ioport);
pci_read_config_dword(dev, ITE_887x_UARTBAR, &uartbar);
uartbar &= ~(0xffff << (16 * i));
uartbar |= (ioport << (16 * i));
pci_write_config_dword(dev, ITE_887x_UARTBAR, uartbar);
pci_read_config_dword(dev, ITE_887x_MISCR, &miscr);
miscr &= ~(0xf << (12 - 4 * i));
miscr |= 1 << (23 - i);
pci_write_config_dword(dev, ITE_887x_MISCR, miscr);
}
if (ret <= 0) {
release_region(iobase->start, ITE_887x_IOSIZE);
}
return ret;
}
static void pci_ite887x_exit(struct pci_dev *dev)
{
u32 ioport;
pci_read_config_dword(dev, ITE_887x_POSIO0, &ioport);
ioport &= 0xffff;
release_region(ioport, ITE_887x_IOSIZE);
}
static int pci_endrun_init(struct pci_dev *dev)
{
u8 __iomem *p;
unsigned long deviceID;
unsigned int number_uarts = 0;
if (dev->vendor == PCI_VENDOR_ID_ENDRUN &&
(dev->device & 0xf000) != 0xe000)
return 0;
p = pci_iomap(dev, 0, 5);
if (p == NULL)
return -ENOMEM;
deviceID = ioread32(p);
if (deviceID == 0x07000200) {
number_uarts = ioread8(p + 4);
dev_dbg(&dev->dev,
"%d ports detected on EndRun PCI Express device\n",
number_uarts);
}
pci_iounmap(dev, p);
return number_uarts;
}
static int pci_oxsemi_tornado_init(struct pci_dev *dev)
{
u8 __iomem *p;
unsigned long deviceID;
unsigned int number_uarts = 0;
if (dev->vendor == PCI_VENDOR_ID_OXSEMI &&
(dev->device & 0xF000) != 0xC000)
return 0;
p = pci_iomap(dev, 0, 5);
if (p == NULL)
return -ENOMEM;
deviceID = ioread32(p);
if (deviceID == 0x07000200) {
number_uarts = ioread8(p + 4);
dev_dbg(&dev->dev,
"%d ports detected on Oxford PCI Express device\n",
number_uarts);
}
pci_iounmap(dev, p);
return number_uarts;
}
static int pci_asix_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
port->bugs |= UART_BUG_PARITY;
return pci_default_setup(priv, board, port, idx);
}
static int pci_quatech_amcc(u16 devid)
{
struct quatech_feature *qf = &quatech_cards[0];
while (qf->devid) {
if (qf->devid == devid)
return qf->amcc;
qf++;
}
pr_err("quatech: unknown port type '0x%04X'.\n", devid);
return 0;
}
static int pci_quatech_rqopr(struct uart_8250_port *port)
{
unsigned long base = port->port.iobase;
u8 LCR, val;
LCR = inb(base + UART_LCR);
outb(0xBF, base + UART_LCR);
val = inb(base + UART_SCR);
outb(LCR, base + UART_LCR);
return val;
}
static void pci_quatech_wqopr(struct uart_8250_port *port, u8 qopr)
{
unsigned long base = port->port.iobase;
u8 LCR, val;
LCR = inb(base + UART_LCR);
outb(0xBF, base + UART_LCR);
val = inb(base + UART_SCR);
outb(qopr, base + UART_SCR);
outb(LCR, base + UART_LCR);
}
static int pci_quatech_rqmcr(struct uart_8250_port *port)
{
unsigned long base = port->port.iobase;
u8 LCR, val, qmcr;
LCR = inb(base + UART_LCR);
outb(0xBF, base + UART_LCR);
val = inb(base + UART_SCR);
outb(val | 0x10, base + UART_SCR);
qmcr = inb(base + UART_MCR);
outb(val, base + UART_SCR);
outb(LCR, base + UART_LCR);
return qmcr;
}
static void pci_quatech_wqmcr(struct uart_8250_port *port, u8 qmcr)
{
unsigned long base = port->port.iobase;
u8 LCR, val;
LCR = inb(base + UART_LCR);
outb(0xBF, base + UART_LCR);
val = inb(base + UART_SCR);
outb(val | 0x10, base + UART_SCR);
outb(qmcr, base + UART_MCR);
outb(val, base + UART_SCR);
outb(LCR, base + UART_LCR);
}
static int pci_quatech_has_qmcr(struct uart_8250_port *port)
{
unsigned long base = port->port.iobase;
u8 LCR, val;
LCR = inb(base + UART_LCR);
outb(0xBF, base + UART_LCR);
val = inb(base + UART_SCR);
if (val & 0x20) {
outb(0x80, UART_LCR);
if (!(inb(UART_SCR) & 0x20)) {
outb(LCR, base + UART_LCR);
return 1;
}
}
return 0;
}
static int pci_quatech_test(struct uart_8250_port *port)
{
u8 reg, qopr;
qopr = pci_quatech_rqopr(port);
pci_quatech_wqopr(port, qopr & QPCR_TEST_FOR1);
reg = pci_quatech_rqopr(port) & 0xC0;
if (reg != QPCR_TEST_GET1)
return -EINVAL;
pci_quatech_wqopr(port, (qopr & QPCR_TEST_FOR1)|QPCR_TEST_FOR2);
reg = pci_quatech_rqopr(port) & 0xC0;
if (reg != QPCR_TEST_GET2)
return -EINVAL;
pci_quatech_wqopr(port, (qopr & QPCR_TEST_FOR1)|QPCR_TEST_FOR3);
reg = pci_quatech_rqopr(port) & 0xC0;
if (reg != QPCR_TEST_GET3)
return -EINVAL;
pci_quatech_wqopr(port, (qopr & QPCR_TEST_FOR1)|QPCR_TEST_FOR4);
reg = pci_quatech_rqopr(port) & 0xC0;
if (reg != QPCR_TEST_GET4)
return -EINVAL;
pci_quatech_wqopr(port, qopr);
return 0;
}
static int pci_quatech_clock(struct uart_8250_port *port)
{
u8 qopr, reg, set;
unsigned long clock;
if (pci_quatech_test(port) < 0)
return 1843200;
qopr = pci_quatech_rqopr(port);
pci_quatech_wqopr(port, qopr & ~QOPR_CLOCK_X8);
reg = pci_quatech_rqopr(port);
if (reg & QOPR_CLOCK_X8) {
clock = 1843200;
goto out;
}
pci_quatech_wqopr(port, qopr | QOPR_CLOCK_X8);
reg = pci_quatech_rqopr(port);
if (!(reg & QOPR_CLOCK_X8)) {
clock = 1843200;
goto out;
}
reg &= QOPR_CLOCK_X8;
if (reg == QOPR_CLOCK_X2) {
clock = 3685400;
set = QOPR_CLOCK_X2;
} else if (reg == QOPR_CLOCK_X4) {
clock = 7372800;
set = QOPR_CLOCK_X4;
} else if (reg == QOPR_CLOCK_X8) {
clock = 14745600;
set = QOPR_CLOCK_X8;
} else {
clock = 1843200;
set = QOPR_CLOCK_X1;
}
qopr &= ~QOPR_CLOCK_RATE_MASK;
qopr |= set;
out:
pci_quatech_wqopr(port, qopr);
return clock;
}
static int pci_quatech_rs422(struct uart_8250_port *port)
{
u8 qmcr;
int rs422 = 0;
if (!pci_quatech_has_qmcr(port))
return 0;
qmcr = pci_quatech_rqmcr(port);
pci_quatech_wqmcr(port, 0xFF);
if (pci_quatech_rqmcr(port))
rs422 = 1;
pci_quatech_wqmcr(port, qmcr);
return rs422;
}
static int pci_quatech_init(struct pci_dev *dev)
{
if (pci_quatech_amcc(dev->device)) {
unsigned long base = pci_resource_start(dev, 0);
if (base) {
u32 tmp;
outl(inl(base + 0x38) | 0x00002000, base + 0x38);
tmp = inl(base + 0x3c);
outl(tmp | 0x01000000, base + 0x3c);
outl(tmp &= ~0x01000000, base + 0x3c);
}
}
return 0;
}
static int pci_quatech_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
port->port.iobase = pci_resource_start(priv->dev, FL_GET_BASE(board->flags));
port->port.uartclk = pci_quatech_clock(port);
if (pci_quatech_rs422(port))
pr_warn("quatech: software control of RS422 features not currently supported.\n");
return pci_default_setup(priv, board, port, idx);
}
static void pci_quatech_exit(struct pci_dev *dev)
{
}
static int pci_default_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
unsigned int bar, offset = board->first_offset, maxnr;
bar = FL_GET_BASE(board->flags);
if (board->flags & FL_BASE_BARS)
bar += idx;
else
offset += idx * board->uart_offset;
maxnr = (pci_resource_len(priv->dev, bar) - board->first_offset) >>
(board->reg_shift + 3);
if (board->flags & FL_REGION_SZ_CAP && idx >= maxnr)
return 1;
return setup_port(priv, port, bar, offset, board->reg_shift);
}
static int
ce4100_serial_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
int ret;
ret = setup_port(priv, port, idx, 0, board->reg_shift);
port->port.iotype = UPIO_MEM32;
port->port.type = PORT_XSCALE;
port->port.flags = (port->port.flags | UPF_FIXED_PORT | UPF_FIXED_TYPE);
port->port.regshift = 2;
return ret;
}
static void
byt_set_termios(struct uart_port *p, struct ktermios *termios,
struct ktermios *old)
{
unsigned int baud = tty_termios_baud_rate(termios);
unsigned long fref = 100000000, fuart = baud * 16;
unsigned long w = BIT(15) - 1;
unsigned long m, n;
u32 reg;
fuart *= rounddown_pow_of_two(fref / fuart);
rational_best_approximation(fuart, fref, w, w, &m, &n);
p->uartclk = fuart;
reg = (m << BYT_PRV_CLK_M_VAL_SHIFT) | (n << BYT_PRV_CLK_N_VAL_SHIFT);
writel(reg, p->membase + BYT_PRV_CLK);
reg |= BYT_PRV_CLK_EN | BYT_PRV_CLK_UPDATE;
writel(reg, p->membase + BYT_PRV_CLK);
p->status &= ~UPSTAT_AUTOCTS;
if (termios->c_cflag & CRTSCTS)
p->status |= UPSTAT_AUTOCTS;
serial8250_do_set_termios(p, termios, old);
}
static bool byt_dma_filter(struct dma_chan *chan, void *param)
{
struct dw_dma_slave *dws = param;
if (dws->dma_dev != chan->device->dev)
return false;
chan->private = dws;
return true;
}
static int
byt_serial_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
struct pci_dev *pdev = priv->dev;
struct device *dev = port->port.dev;
struct uart_8250_dma *dma;
struct dw_dma_slave *tx_param, *rx_param;
struct pci_dev *dma_dev;
int ret;
dma = devm_kzalloc(dev, sizeof(*dma), GFP_KERNEL);
if (!dma)
return -ENOMEM;
tx_param = devm_kzalloc(dev, sizeof(*tx_param), GFP_KERNEL);
if (!tx_param)
return -ENOMEM;
rx_param = devm_kzalloc(dev, sizeof(*rx_param), GFP_KERNEL);
if (!rx_param)
return -ENOMEM;
switch (pdev->device) {
case PCI_DEVICE_ID_INTEL_BYT_UART1:
case PCI_DEVICE_ID_INTEL_BSW_UART1:
case PCI_DEVICE_ID_INTEL_BDW_UART1:
rx_param->src_id = 3;
tx_param->dst_id = 2;
break;
case PCI_DEVICE_ID_INTEL_BYT_UART2:
case PCI_DEVICE_ID_INTEL_BSW_UART2:
case PCI_DEVICE_ID_INTEL_BDW_UART2:
rx_param->src_id = 5;
tx_param->dst_id = 4;
break;
default:
return -EINVAL;
}
rx_param->src_master = 1;
rx_param->dst_master = 0;
dma->rxconf.src_maxburst = 16;
tx_param->src_master = 1;
tx_param->dst_master = 0;
dma->txconf.dst_maxburst = 16;
dma_dev = pci_get_slot(pdev->bus, PCI_DEVFN(PCI_SLOT(pdev->devfn), 0));
rx_param->dma_dev = &dma_dev->dev;
tx_param->dma_dev = &dma_dev->dev;
dma->fn = byt_dma_filter;
dma->rx_param = rx_param;
dma->tx_param = tx_param;
ret = pci_default_setup(priv, board, port, idx);
port->port.iotype = UPIO_MEM;
port->port.type = PORT_16550A;
port->port.flags = (port->port.flags | UPF_FIXED_PORT | UPF_FIXED_TYPE);
port->port.set_termios = byt_set_termios;
port->port.fifosize = 64;
port->tx_loadsz = 64;
port->dma = dma;
port->capabilities = UART_CAP_FIFO | UART_CAP_AFE;
writel(BYT_TX_OVF_INT_MASK, port->port.membase + BYT_TX_OVF_INT);
return ret;
}
static int
pci_omegapci_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
return setup_port(priv, port, 2, idx * 8, 0);
}
static int
pci_brcm_trumanage_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
int ret = pci_default_setup(priv, board, port, idx);
port->port.type = PORT_BRCM_TRUMANAGE;
port->port.flags = (port->port.flags | UPF_FIXED_PORT | UPF_FIXED_TYPE);
return ret;
}
static int pci_fintek_rs485_config(struct uart_port *port,
struct serial_rs485 *rs485)
{
struct pci_dev *pci_dev = to_pci_dev(port->dev);
u8 setting;
u8 *index = (u8 *) port->private_data;
pci_read_config_byte(pci_dev, 0x40 + 8 * *index + 7, &setting);
if (!rs485)
rs485 = &port->rs485;
else if (rs485->flags & SER_RS485_ENABLED)
memset(rs485->padding, 0, sizeof(rs485->padding));
else
memset(rs485, 0, sizeof(*rs485));
rs485->flags &= SER_RS485_ENABLED | SER_RS485_RTS_ON_SEND;
if (rs485->flags & SER_RS485_ENABLED) {
setting |= FINTEK_RTS_CONTROL_BY_HW;
if (rs485->flags & SER_RS485_RTS_ON_SEND) {
setting &= ~FINTEK_RTS_INVERT;
} else {
setting |= FINTEK_RTS_INVERT;
}
rs485->delay_rts_after_send = 0;
rs485->delay_rts_before_send = 0;
} else {
setting &= ~(FINTEK_RTS_CONTROL_BY_HW | FINTEK_RTS_INVERT);
}
pci_write_config_byte(pci_dev, 0x40 + 8 * *index + 7, setting);
if (rs485 != &port->rs485)
port->rs485 = *rs485;
return 0;
}
static int pci_fintek_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
struct pci_dev *pdev = priv->dev;
u8 *data;
u8 config_base;
u16 iobase;
config_base = 0x40 + 0x08 * idx;
pci_read_config_word(pdev, config_base + 4, &iobase);
dev_dbg(&pdev->dev, "%s: idx=%d iobase=0x%x", __func__, idx, iobase);
port->port.iotype = UPIO_PORT;
port->port.iobase = iobase;
port->port.rs485_config = pci_fintek_rs485_config;
data = devm_kzalloc(&pdev->dev, sizeof(u8), GFP_KERNEL);
if (!data)
return -ENOMEM;
*data = idx;
port->port.private_data = data;
return 0;
}
static int pci_fintek_init(struct pci_dev *dev)
{
unsigned long iobase;
u32 max_port, i;
u32 bar_data[3];
u8 config_base;
struct serial_private *priv = pci_get_drvdata(dev);
struct uart_8250_port *port;
switch (dev->device) {
case 0x1104:
case 0x1108:
max_port = dev->device & 0xff;
break;
case 0x1112:
max_port = 12;
break;
default:
return -EINVAL;
}
pci_read_config_dword(dev, 0x24, &bar_data[0]);
pci_read_config_dword(dev, 0x20, &bar_data[1]);
pci_read_config_dword(dev, 0x1c, &bar_data[2]);
for (i = 0; i < max_port; ++i) {
config_base = 0x40 + 0x08 * i;
iobase = (bar_data[i / 4] & 0xffffffe0) + (i % 4) * 8;
pci_write_config_byte(dev, config_base + 0x00, 0x01);
pci_write_config_byte(dev, config_base + 0x01, 0x33);
pci_write_config_byte(dev, config_base + 0x04,
(u8)(iobase & 0xff));
pci_write_config_byte(dev, config_base + 0x05,
(u8)((iobase & 0xff00) >> 8));
pci_write_config_byte(dev, config_base + 0x06, dev->irq);
if (priv) {
port = serial8250_get_port(priv->line[i]);
pci_fintek_rs485_config(&port->port, NULL);
} else {
pci_write_config_byte(dev, config_base + 0x07, 0x01);
}
}
return max_port;
}
static int skip_tx_en_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
port->port.flags |= UPF_NO_TXEN_TEST;
dev_dbg(&priv->dev->dev,
"serial8250: skipping TxEn test for device [%04x:%04x] subsystem [%04x:%04x]\n",
priv->dev->vendor, priv->dev->device,
priv->dev->subsystem_vendor, priv->dev->subsystem_device);
return pci_default_setup(priv, board, port, idx);
}
static void kt_handle_break(struct uart_port *p)
{
struct uart_8250_port *up = up_to_u8250p(p);
serial8250_clear_and_reinit_fifos(up);
}
static unsigned int kt_serial_in(struct uart_port *p, int offset)
{
struct uart_8250_port *up = up_to_u8250p(p);
unsigned int val;
val = inb(p->iobase + offset);
if (offset == UART_IER) {
if (val == 0)
val = up->ier;
}
return val;
}
static int kt_serial_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
port->port.flags |= UPF_BUG_THRE;
port->port.serial_in = kt_serial_in;
port->port.handle_break = kt_handle_break;
return skip_tx_en_setup(priv, board, port, idx);
}
static int pci_eg20t_init(struct pci_dev *dev)
{
#if defined(CONFIG_SERIAL_PCH_UART) || defined(CONFIG_SERIAL_PCH_UART_MODULE)
return -ENODEV;
#else
return 0;
#endif
}
static int
pci_xr17c154_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
port->port.flags |= UPF_EXAR_EFR;
return pci_default_setup(priv, board, port, idx);
}
static inline int
xr17v35x_has_slave(struct serial_private *priv)
{
const int dev_id = priv->dev->device;
return ((dev_id == PCI_DEVICE_ID_EXAR_XR17V4358) ||
(dev_id == PCI_DEVICE_ID_EXAR_XR17V8358));
}
static int
pci_xr17v35x_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
u8 __iomem *p;
p = pci_ioremap_bar(priv->dev, 0);
if (p == NULL)
return -ENOMEM;
port->port.flags |= UPF_EXAR_EFR;
if (xr17v35x_has_slave(priv) && idx >= 8)
port->port.uartclk = (7812500 * 16 / 2);
if (idx == 0) {
writeb(0x00, p + 0x8f);
writeb(0x00, p + 0x90);
writeb(0x00, p + 0x91);
writeb(0x00, p + 0x92);
writeb(0x00, p + 0x93);
writeb(0x00, p + 0x94);
writeb(0x00, p + 0x95);
writeb(0x00, p + 0x96);
writeb(0x00, p + 0x97);
writeb(0x00, p + 0x98);
writeb(0x00, p + 0x99);
writeb(0x00, p + 0x9a);
}
writeb(0x00, p + UART_EXAR_8XMODE);
writeb(UART_FCTR_EXAR_TRGD, p + UART_EXAR_FCTR);
writeb(128, p + UART_EXAR_TXTRG);
writeb(128, p + UART_EXAR_RXTRG);
iounmap(p);
return pci_default_setup(priv, board, port, idx);
}
static int
pci_fastcom335_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
u8 __iomem *p;
p = pci_ioremap_bar(priv->dev, 0);
if (p == NULL)
return -ENOMEM;
port->port.flags |= UPF_EXAR_EFR;
if (idx == 0) {
switch (priv->dev->device) {
case PCI_DEVICE_ID_COMMTECH_4222PCI335:
case PCI_DEVICE_ID_COMMTECH_4224PCI335:
writeb(0x78, p + 0x90);
writeb(0x00, p + 0x92);
writeb(0x00, p + 0x93);
break;
case PCI_DEVICE_ID_COMMTECH_2324PCI335:
case PCI_DEVICE_ID_COMMTECH_2328PCI335:
writeb(0x00, p + 0x90);
writeb(0xc0, p + 0x92);
writeb(0xc0, p + 0x93);
break;
}
writeb(0x00, p + 0x8f);
writeb(0x00, p + 0x91);
writeb(0x00, p + 0x94);
}
writeb(0x00, p + UART_EXAR_8XMODE);
writeb(UART_FCTR_EXAR_TRGD, p + UART_EXAR_FCTR);
writeb(32, p + UART_EXAR_TXTRG);
writeb(32, p + UART_EXAR_RXTRG);
iounmap(p);
return pci_default_setup(priv, board, port, idx);
}
static int
pci_wch_ch353_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
port->port.flags |= UPF_FIXED_TYPE;
port->port.type = PORT_16550A;
return pci_default_setup(priv, board, port, idx);
}
static int
pci_wch_ch38x_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_8250_port *port, int idx)
{
port->port.flags |= UPF_FIXED_TYPE;
port->port.type = PORT_16850;
return pci_default_setup(priv, board, port, idx);
}
static inline int quirk_id_matches(u32 quirk_id, u32 dev_id)
{
return quirk_id == PCI_ANY_ID || quirk_id == dev_id;
}
static struct pci_serial_quirk *find_quirk(struct pci_dev *dev)
{
struct pci_serial_quirk *quirk;
for (quirk = pci_serial_quirks; ; quirk++)
if (quirk_id_matches(quirk->vendor, dev->vendor) &&
quirk_id_matches(quirk->device, dev->device) &&
quirk_id_matches(quirk->subvendor, dev->subsystem_vendor) &&
quirk_id_matches(quirk->subdevice, dev->subsystem_device))
break;
return quirk;
}
static inline int get_pci_irq(struct pci_dev *dev,
const struct pciserial_board *board)
{
if (board->flags & FL_NOIRQ)
return 0;
else
return dev->irq;
}
static int
serial_pci_guess_board(struct pci_dev *dev, struct pciserial_board *board)
{
const struct pci_device_id *bldev;
int num_iomem, num_port, first_port = -1, i;
if ((((dev->class >> 8) != PCI_CLASS_COMMUNICATION_SERIAL) &&
((dev->class >> 8) != PCI_CLASS_COMMUNICATION_MODEM)) ||
(dev->class & 0xff) > 6)
return -ENODEV;
for (bldev = blacklist;
bldev < blacklist + ARRAY_SIZE(blacklist);
bldev++) {
if (dev->vendor == bldev->vendor &&
dev->device == bldev->device)
return -ENODEV;
}
num_iomem = num_port = 0;
for (i = 0; i < PCI_NUM_BAR_RESOURCES; i++) {
if (pci_resource_flags(dev, i) & IORESOURCE_IO) {
num_port++;
if (first_port == -1)
first_port = i;
}
if (pci_resource_flags(dev, i) & IORESOURCE_MEM)
num_iomem++;
}
if (num_iomem <= 1 && num_port == 1) {
board->flags = first_port;
board->num_ports = pci_resource_len(dev, first_port) / 8;
return 0;
}
first_port = -1;
num_port = 0;
for (i = 0; i < PCI_NUM_BAR_RESOURCES; i++) {
if (pci_resource_flags(dev, i) & IORESOURCE_IO &&
pci_resource_len(dev, i) == 8 &&
(first_port == -1 || (first_port + num_port) == i)) {
num_port++;
if (first_port == -1)
first_port = i;
}
}
if (num_port > 1) {
board->flags = first_port | FL_BASE_BARS;
board->num_ports = num_port;
return 0;
}
return -ENODEV;
}
static inline int
serial_pci_matches(const struct pciserial_board *board,
const struct pciserial_board *guessed)
{
return
board->num_ports == guessed->num_ports &&
board->base_baud == guessed->base_baud &&
board->uart_offset == guessed->uart_offset &&
board->reg_shift == guessed->reg_shift &&
board->first_offset == guessed->first_offset;
}
struct serial_private *
pciserial_init_ports(struct pci_dev *dev, const struct pciserial_board *board)
{
struct uart_8250_port uart;
struct serial_private *priv;
struct pci_serial_quirk *quirk;
int rc, nr_ports, i;
nr_ports = board->num_ports;
quirk = find_quirk(dev);
if (quirk->init) {
rc = quirk->init(dev);
if (rc < 0) {
priv = ERR_PTR(rc);
goto err_out;
}
if (rc)
nr_ports = rc;
}
priv = kzalloc(sizeof(struct serial_private) +
sizeof(unsigned int) * nr_ports,
GFP_KERNEL);
if (!priv) {
priv = ERR_PTR(-ENOMEM);
goto err_deinit;
}
priv->dev = dev;
priv->quirk = quirk;
memset(&uart, 0, sizeof(uart));
uart.port.flags = UPF_SKIP_TEST | UPF_BOOT_AUTOCONF | UPF_SHARE_IRQ;
uart.port.uartclk = board->base_baud * 16;
uart.port.irq = get_pci_irq(dev, board);
uart.port.dev = &dev->dev;
for (i = 0; i < nr_ports; i++) {
if (quirk->setup(priv, board, &uart, i))
break;
dev_dbg(&dev->dev, "Setup PCI port: port %lx, irq %d, type %d\n",
uart.port.iobase, uart.port.irq, uart.port.iotype);
priv->line[i] = serial8250_register_8250_port(&uart);
if (priv->line[i] < 0) {
dev_err(&dev->dev,
"Couldn't register serial port %lx, irq %d, type %d, error %d\n",
uart.port.iobase, uart.port.irq,
uart.port.iotype, priv->line[i]);
break;
}
}
priv->nr = i;
return priv;
err_deinit:
if (quirk->exit)
quirk->exit(dev);
err_out:
return priv;
}
void pciserial_remove_ports(struct serial_private *priv)
{
struct pci_serial_quirk *quirk;
int i;
for (i = 0; i < priv->nr; i++)
serial8250_unregister_port(priv->line[i]);
quirk = find_quirk(priv->dev);
if (quirk->exit)
quirk->exit(priv->dev);
kfree(priv);
}
void pciserial_suspend_ports(struct serial_private *priv)
{
int i;
for (i = 0; i < priv->nr; i++)
if (priv->line[i] >= 0)
serial8250_suspend_port(priv->line[i]);
if (priv->quirk->exit)
priv->quirk->exit(priv->dev);
}
void pciserial_resume_ports(struct serial_private *priv)
{
int i;
if (priv->quirk->init)
priv->quirk->init(priv->dev);
for (i = 0; i < priv->nr; i++)
if (priv->line[i] >= 0)
serial8250_resume_port(priv->line[i]);
}
static int
pciserial_init_one(struct pci_dev *dev, const struct pci_device_id *ent)
{
struct pci_serial_quirk *quirk;
struct serial_private *priv;
const struct pciserial_board *board;
struct pciserial_board tmp;
int rc;
quirk = find_quirk(dev);
if (quirk->probe) {
rc = quirk->probe(dev);
if (rc)
return rc;
}
if (ent->driver_data >= ARRAY_SIZE(pci_boards)) {
dev_err(&dev->dev, "invalid driver_data: %ld\n",
ent->driver_data);
return -EINVAL;
}
board = &pci_boards[ent->driver_data];
rc = pcim_enable_device(dev);
pci_save_state(dev);
if (rc)
return rc;
if (ent->driver_data == pbn_default) {
memcpy(&tmp, board, sizeof(struct pciserial_board));
board = &tmp;
rc = serial_pci_guess_board(dev, &tmp);
if (rc)
return rc;
} else {
memcpy(&tmp, &pci_boards[pbn_default],
sizeof(struct pciserial_board));
rc = serial_pci_guess_board(dev, &tmp);
if (rc == 0 && serial_pci_matches(board, &tmp))
moan_device("Redundant entry in serial pci_table.",
dev);
}
priv = pciserial_init_ports(dev, board);
if (IS_ERR(priv))
return PTR_ERR(priv);
pci_set_drvdata(dev, priv);
return 0;
}
static void pciserial_remove_one(struct pci_dev *dev)
{
struct serial_private *priv = pci_get_drvdata(dev);
pciserial_remove_ports(priv);
}
static int pciserial_suspend_one(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct serial_private *priv = pci_get_drvdata(pdev);
if (priv)
pciserial_suspend_ports(priv);
return 0;
}
static int pciserial_resume_one(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct serial_private *priv = pci_get_drvdata(pdev);
int err;
if (priv) {
err = pci_enable_device(pdev);
if (err)
dev_err(dev, "Unable to re-enable ports, trying to continue.\n");
pciserial_resume_ports(priv);
}
return 0;
}
static pci_ers_result_t serial8250_io_error_detected(struct pci_dev *dev,
pci_channel_state_t state)
{
struct serial_private *priv = pci_get_drvdata(dev);
if (state == pci_channel_io_perm_failure)
return PCI_ERS_RESULT_DISCONNECT;
if (priv)
pciserial_suspend_ports(priv);
pci_disable_device(dev);
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t serial8250_io_slot_reset(struct pci_dev *dev)
{
int rc;
rc = pci_enable_device(dev);
if (rc)
return PCI_ERS_RESULT_DISCONNECT;
pci_restore_state(dev);
pci_save_state(dev);
return PCI_ERS_RESULT_RECOVERED;
}
static void serial8250_io_resume(struct pci_dev *dev)
{
struct serial_private *priv = pci_get_drvdata(dev);
if (priv)
pciserial_resume_ports(priv);
}
