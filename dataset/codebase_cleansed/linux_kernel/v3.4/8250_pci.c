static void moan_device(const char *str, struct pci_dev *dev)
{
printk(KERN_WARNING
"%s: %s\n"
"Please send the output of lspci -vv, this\n"
"message (0x%04x,0x%04x,0x%04x,0x%04x), the\n"
"manufacturer and name of serial board or\n"
"modem board to rmk+serial@arm.linux.org.uk.\n",
pci_name(dev), str, dev->vendor, dev->device,
dev->subsystem_vendor, dev->subsystem_device);
}
static int
setup_port(struct serial_private *priv, struct uart_port *port,
int bar, int offset, int regshift)
{
struct pci_dev *dev = priv->dev;
unsigned long base, len;
if (bar >= PCI_NUM_BAR_RESOURCES)
return -EINVAL;
base = pci_resource_start(dev, bar);
if (pci_resource_flags(dev, bar) & IORESOURCE_MEM) {
len = pci_resource_len(dev, bar);
if (!priv->remapped_bar[bar])
priv->remapped_bar[bar] = ioremap_nocache(base, len);
if (!priv->remapped_bar[bar])
return -ENOMEM;
port->iotype = UPIO_MEM;
port->iobase = 0;
port->mapbase = base + offset;
port->membase = priv->remapped_bar[bar] + offset;
port->regshift = regshift;
} else {
port->iotype = UPIO_PORT;
port->iobase = base + offset;
port->mapbase = 0;
port->membase = NULL;
port->regshift = 0;
}
return 0;
}
static int addidata_apci7800_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_port *port, int idx)
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
struct uart_port *port, int idx)
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
struct uart_port *port, int idx)
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
unsigned long oldval;
if (!(dev->subsystem_device & 0x1000))
return -ENODEV;
pci_read_config_dword(dev, 0x44, (void *)&oldval);
if (oldval == 0x00001000L) {
printk(KERN_DEBUG "Local i960 firmware missing");
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
static void __devexit pci_plx9050_exit(struct pci_dev *dev)
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
static void __devexit pci_ni8420_exit(struct pci_dev *dev)
{
void __iomem *p;
unsigned long base, len;
unsigned int bar = 0;
if ((pci_resource_flags(dev, bar) & IORESOURCE_MEM) == 0) {
moan_device("no memory in bar", dev);
return;
}
base = pci_resource_start(dev, bar);
len = pci_resource_len(dev, bar);
p = ioremap_nocache(base, len);
if (p == NULL)
return;
writel(readl(p + NI8420_INT_ENABLE_REG) & ~(NI8420_INT_ENABLE_BIT),
p + NI8420_INT_ENABLE_REG);
iounmap(p);
}
static void __devexit pci_ni8430_exit(struct pci_dev *dev)
{
void __iomem *p;
unsigned long base, len;
unsigned int bar = 0;
if ((pci_resource_flags(dev, bar) & IORESOURCE_MEM) == 0) {
moan_device("no memory in bar", dev);
return;
}
base = pci_resource_start(dev, bar);
len = pci_resource_len(dev, bar);
p = ioremap_nocache(base, len);
if (p == NULL)
return;
writel(MITE_LCIMR2_CLR_CPU_IE, p + MITE_LCIMR2);
iounmap(p);
}
static int
sbs_setup(struct serial_private *priv, const struct pciserial_board *board,
struct uart_port *port, int idx)
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
static void __devexit sbs_exit(struct pci_dev *dev)
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
struct uart_port *port, int idx)
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
struct uart_port *port, int idx)
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
struct uart_port *port, int idx)
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
unsigned long base, len;
unsigned int bar = 0;
if ((pci_resource_flags(dev, bar) & IORESOURCE_MEM) == 0) {
moan_device("no memory in bar", dev);
return 0;
}
base = pci_resource_start(dev, bar);
len = pci_resource_len(dev, bar);
p = ioremap_nocache(base, len);
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
unsigned long base, len;
u32 device_window;
unsigned int bar = 0;
if ((pci_resource_flags(dev, bar) & IORESOURCE_MEM) == 0) {
moan_device("no memory in bar", dev);
return 0;
}
base = pci_resource_start(dev, bar);
len = pci_resource_len(dev, bar);
p = ioremap_nocache(base, len);
if (p == NULL)
return -ENOMEM;
device_window = ((base + MITE_IOWBSR1_WIN_OFFSET) & 0xffffff00)
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
struct uart_port *port, int idx)
{
void __iomem *p;
unsigned long base, len;
unsigned int bar, offset = board->first_offset;
if (idx >= board->num_ports)
return 1;
bar = FL_GET_BASE(board->flags);
offset += idx * board->uart_offset;
base = pci_resource_start(priv->dev, bar);
len = pci_resource_len(priv->dev, bar);
p = ioremap_nocache(base, len);
writeb(readb(p + offset + NI8430_PORTCON) | NI8430_PORTCON_TXVR_ENABLE,
p + offset + NI8430_PORTCON);
iounmap(p);
return setup_port(priv, port, bar, offset, board->reg_shift);
}
static int pci_netmos_9900_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_port *port, int idx)
{
unsigned int bar;
if ((priv->dev->subsystem_device & 0xff00) == 0x3000) {
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
pi = (c & 0xff);
if (pi == 2) {
return 1;
} else if ((pi == 0) &&
(dev->device == PCI_DEVICE_ID_NETMOS_9900)) {
sub_serports = dev->subsystem_device & 0xf;
if (sub_serports > 0) {
return sub_serports;
} else {
printk(KERN_NOTICE "NetMos/Mostech serial driver ignoring port on ambiguous config.\n");
return 0;
}
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
if (num_serial == 0 ) {
moan_device("unknown NetMos/Mostech device", dev);
}
}
if (num_serial == 0)
return -ENODEV;
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
printk(KERN_ERR "ite887x: could not find iobase\n");
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
static void __devexit pci_ite887x_exit(struct pci_dev *dev)
{
u32 ioport;
pci_read_config_dword(dev, ITE_887x_POSIO0, &ioport);
ioport &= 0xffff;
release_region(ioport, ITE_887x_IOSIZE);
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
printk(KERN_DEBUG
"%d ports detected on Oxford PCI Express device\n",
number_uarts);
}
pci_iounmap(dev, p);
return number_uarts;
}
static int
pci_default_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_port *port, int idx)
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
struct uart_port *port, int idx)
{
int ret;
ret = setup_port(priv, port, 0, 0, board->reg_shift);
port->iotype = UPIO_MEM32;
port->type = PORT_XSCALE;
port->flags = (port->flags | UPF_FIXED_PORT | UPF_FIXED_TYPE);
port->regshift = 2;
return ret;
}
static int
pci_omegapci_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_port *port, int idx)
{
return setup_port(priv, port, 2, idx * 8, 0);
}
static int skip_tx_en_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_port *port, int idx)
{
port->flags |= UPF_NO_TXEN_TEST;
printk(KERN_DEBUG "serial8250: skipping TxEn test for device "
"[%04x:%04x] subsystem [%04x:%04x]\n",
priv->dev->vendor,
priv->dev->device,
priv->dev->subsystem_vendor,
priv->dev->subsystem_device);
return pci_default_setup(priv, board, port, idx);
}
static int kt_serial_setup(struct serial_private *priv,
const struct pciserial_board *board,
struct uart_port *port, int idx)
{
port->flags |= UPF_BUG_THRE;
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
struct uart_port *port, int idx)
{
port->flags |= UPF_EXAR_EFR;
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
static int __devinit
serial_pci_guess_board(struct pci_dev *dev, struct pciserial_board *board)
{
const struct pci_device_id *blacklist;
int num_iomem, num_port, first_port = -1, i;
if ((((dev->class >> 8) != PCI_CLASS_COMMUNICATION_SERIAL) &&
((dev->class >> 8) != PCI_CLASS_COMMUNICATION_MODEM)) ||
(dev->class & 0xff) > 6)
return -ENODEV;
for (blacklist = softmodem_blacklist;
blacklist < softmodem_blacklist + ARRAY_SIZE(softmodem_blacklist);
blacklist++) {
if (dev->vendor == blacklist->vendor &&
dev->device == blacklist->device)
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
struct uart_port serial_port;
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
memset(&serial_port, 0, sizeof(struct uart_port));
serial_port.flags = UPF_SKIP_TEST | UPF_BOOT_AUTOCONF | UPF_SHARE_IRQ;
serial_port.uartclk = board->base_baud * 16;
serial_port.irq = get_pci_irq(dev, board);
serial_port.dev = &dev->dev;
for (i = 0; i < nr_ports; i++) {
if (quirk->setup(priv, board, &serial_port, i))
break;
#ifdef SERIAL_DEBUG_PCI
printk(KERN_DEBUG "Setup PCI port: port %lx, irq %d, type %d\n",
serial_port.iobase, serial_port.irq, serial_port.iotype);
#endif
priv->line[i] = serial8250_register_port(&serial_port);
if (priv->line[i] < 0) {
printk(KERN_WARNING "Couldn't register serial port %s: %d\n", pci_name(dev), priv->line[i]);
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
for (i = 0; i < PCI_NUM_BAR_RESOURCES; i++) {
if (priv->remapped_bar[i])
iounmap(priv->remapped_bar[i]);
priv->remapped_bar[i] = NULL;
}
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
static int __devinit
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
printk(KERN_ERR "pci_init_one: invalid driver_data: %ld\n",
ent->driver_data);
return -EINVAL;
}
board = &pci_boards[ent->driver_data];
rc = pci_enable_device(dev);
pci_save_state(dev);
if (rc)
return rc;
if (ent->driver_data == pbn_default) {
memcpy(&tmp, board, sizeof(struct pciserial_board));
board = &tmp;
rc = serial_pci_guess_board(dev, &tmp);
if (rc)
goto disable;
} else {
memcpy(&tmp, &pci_boards[pbn_default],
sizeof(struct pciserial_board));
rc = serial_pci_guess_board(dev, &tmp);
if (rc == 0 && serial_pci_matches(board, &tmp))
moan_device("Redundant entry in serial pci_table.",
dev);
}
priv = pciserial_init_ports(dev, board);
if (!IS_ERR(priv)) {
pci_set_drvdata(dev, priv);
return 0;
}
rc = PTR_ERR(priv);
disable:
pci_disable_device(dev);
return rc;
}
static void __devexit pciserial_remove_one(struct pci_dev *dev)
{
struct serial_private *priv = pci_get_drvdata(dev);
pci_set_drvdata(dev, NULL);
pciserial_remove_ports(priv);
pci_disable_device(dev);
}
static int pciserial_suspend_one(struct pci_dev *dev, pm_message_t state)
{
struct serial_private *priv = pci_get_drvdata(dev);
if (priv)
pciserial_suspend_ports(priv);
pci_save_state(dev);
pci_set_power_state(dev, pci_choose_state(dev, state));
return 0;
}
static int pciserial_resume_one(struct pci_dev *dev)
{
int err;
struct serial_private *priv = pci_get_drvdata(dev);
pci_set_power_state(dev, PCI_D0);
pci_restore_state(dev);
if (priv) {
err = pci_enable_device(dev);
if (err)
printk(KERN_ERR "pciserial: Unable to re-enable ports, trying to continue.\n");
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
static int __init serial8250_pci_init(void)
{
return pci_register_driver(&serial_pci_driver);
}
static void __exit serial8250_pci_exit(void)
{
pci_unregister_driver(&serial_pci_driver);
}
