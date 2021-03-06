static inline u32 cb_readl(struct yenta_socket *socket, unsigned reg)
{
u32 val = readl(socket->base + reg);
debug("%04x %08x\n", socket, reg, val);
return val;
}
static inline void cb_writel(struct yenta_socket *socket, unsigned reg, u32 val)
{
debug("%04x %08x\n", socket, reg, val);
writel(val, socket->base + reg);
readl(socket->base + reg);
}
static inline u8 config_readb(struct yenta_socket *socket, unsigned offset)
{
u8 val;
pci_read_config_byte(socket->dev, offset, &val);
debug("%04x %02x\n", socket, offset, val);
return val;
}
static inline u16 config_readw(struct yenta_socket *socket, unsigned offset)
{
u16 val;
pci_read_config_word(socket->dev, offset, &val);
debug("%04x %04x\n", socket, offset, val);
return val;
}
static inline u32 config_readl(struct yenta_socket *socket, unsigned offset)
{
u32 val;
pci_read_config_dword(socket->dev, offset, &val);
debug("%04x %08x\n", socket, offset, val);
return val;
}
static inline void config_writeb(struct yenta_socket *socket, unsigned offset, u8 val)
{
debug("%04x %02x\n", socket, offset, val);
pci_write_config_byte(socket->dev, offset, val);
}
static inline void config_writew(struct yenta_socket *socket, unsigned offset, u16 val)
{
debug("%04x %04x\n", socket, offset, val);
pci_write_config_word(socket->dev, offset, val);
}
static inline void config_writel(struct yenta_socket *socket, unsigned offset, u32 val)
{
debug("%04x %08x\n", socket, offset, val);
pci_write_config_dword(socket->dev, offset, val);
}
static inline u8 exca_readb(struct yenta_socket *socket, unsigned reg)
{
u8 val = readb(socket->base + 0x800 + reg);
debug("%04x %02x\n", socket, reg, val);
return val;
}
static inline u8 exca_readw(struct yenta_socket *socket, unsigned reg)
{
u16 val;
val = readb(socket->base + 0x800 + reg);
val |= readb(socket->base + 0x800 + reg + 1) << 8;
debug("%04x %04x\n", socket, reg, val);
return val;
}
static inline void exca_writeb(struct yenta_socket *socket, unsigned reg, u8 val)
{
debug("%04x %02x\n", socket, reg, val);
writeb(val, socket->base + 0x800 + reg);
readb(socket->base + 0x800 + reg);
}
static void exca_writew(struct yenta_socket *socket, unsigned reg, u16 val)
{
debug("%04x %04x\n", socket, reg, val);
writeb(val, socket->base + 0x800 + reg);
writeb(val >> 8, socket->base + 0x800 + reg + 1);
readb(socket->base + 0x800 + reg);
readb(socket->base + 0x800 + reg + 1);
}
static ssize_t show_yenta_registers(struct device *yentadev, struct device_attribute *attr, char *buf)
{
struct pci_dev *dev = to_pci_dev(yentadev);
struct yenta_socket *socket = pci_get_drvdata(dev);
int offset = 0, i;
offset = snprintf(buf, PAGE_SIZE, "CB registers:");
for (i = 0; i < 0x24; i += 4) {
unsigned val;
if (!(i & 15))
offset += snprintf(buf + offset, PAGE_SIZE - offset, "\n%02x:", i);
val = cb_readl(socket, i);
offset += snprintf(buf + offset, PAGE_SIZE - offset, " %08x", val);
}
offset += snprintf(buf + offset, PAGE_SIZE - offset, "\n\nExCA registers:");
for (i = 0; i < 0x45; i++) {
unsigned char val;
if (!(i & 7)) {
if (i & 8) {
memcpy(buf + offset, " -", 2);
offset += 2;
} else
offset += snprintf(buf + offset, PAGE_SIZE - offset, "\n%02x:", i);
}
val = exca_readb(socket, i);
offset += snprintf(buf + offset, PAGE_SIZE - offset, " %02x", val);
}
buf[offset++] = '\n';
return offset;
}
static int yenta_get_status(struct pcmcia_socket *sock, unsigned int *value)
{
struct yenta_socket *socket = container_of(sock, struct yenta_socket, socket);
unsigned int val;
u32 state = cb_readl(socket, CB_SOCKET_STATE);
val = (state & CB_3VCARD) ? SS_3VCARD : 0;
val |= (state & CB_XVCARD) ? SS_XVCARD : 0;
val |= (state & (CB_5VCARD | CB_3VCARD | CB_XVCARD | CB_YVCARD)) ? 0 : SS_PENDING;
val |= (state & (CB_CDETECT1 | CB_CDETECT2)) ? SS_PENDING : 0;
if (state & CB_CBCARD) {
val |= SS_CARDBUS;
val |= (state & CB_CARDSTS) ? SS_STSCHG : 0;
val |= (state & (CB_CDETECT1 | CB_CDETECT2)) ? 0 : SS_DETECT;
val |= (state & CB_PWRCYCLE) ? SS_POWERON | SS_READY : 0;
} else if (state & CB_16BITCARD) {
u8 status = exca_readb(socket, I365_STATUS);
val |= ((status & I365_CS_DETECT) == I365_CS_DETECT) ? SS_DETECT : 0;
if (exca_readb(socket, I365_INTCTL) & I365_PC_IOCARD) {
val |= (status & I365_CS_STSCHG) ? 0 : SS_STSCHG;
} else {
val |= (status & I365_CS_BVD1) ? 0 : SS_BATDEAD;
val |= (status & I365_CS_BVD2) ? 0 : SS_BATWARN;
}
val |= (status & I365_CS_WRPROT) ? SS_WRPROT : 0;
val |= (status & I365_CS_READY) ? SS_READY : 0;
val |= (status & I365_CS_POWERON) ? SS_POWERON : 0;
}
*value = val;
return 0;
}
static void yenta_set_power(struct yenta_socket *socket, socket_state_t *state)
{
if (!(cb_readl(socket, CB_SOCKET_STATE) & CB_CBCARD) &&
(socket->flags & YENTA_16BIT_POWER_EXCA)) {
u8 reg, old;
reg = old = exca_readb(socket, I365_POWER);
reg &= ~(I365_VCC_MASK | I365_VPP1_MASK | I365_VPP2_MASK);
if (socket->flags & YENTA_16BIT_POWER_DF) {
switch (state->Vcc) {
case 33:
reg |= I365_VCC_3V;
break;
case 50:
reg |= I365_VCC_5V;
break;
default:
reg = 0;
break;
}
switch (state->Vpp) {
case 33:
case 50:
reg |= I365_VPP1_5V;
break;
case 120:
reg |= I365_VPP1_12V;
break;
}
} else {
switch (state->Vcc) {
case 50:
reg |= I365_VCC_5V;
break;
default:
reg = 0;
break;
}
switch (state->Vpp) {
case 50:
reg |= I365_VPP1_5V | I365_VPP2_5V;
break;
case 120:
reg |= I365_VPP1_12V | I365_VPP2_12V;
break;
}
}
if (reg != old)
exca_writeb(socket, I365_POWER, reg);
} else {
u32 reg = 0;
switch (state->Vcc) {
case 33:
reg = CB_SC_VCC_3V;
break;
case 50:
reg = CB_SC_VCC_5V;
break;
default:
reg = 0;
break;
}
switch (state->Vpp) {
case 33:
reg |= CB_SC_VPP_3V;
break;
case 50:
reg |= CB_SC_VPP_5V;
break;
case 120:
reg |= CB_SC_VPP_12V;
break;
}
if (reg != cb_readl(socket, CB_SOCKET_CONTROL))
cb_writel(socket, CB_SOCKET_CONTROL, reg);
}
}
static int yenta_set_socket(struct pcmcia_socket *sock, socket_state_t *state)
{
struct yenta_socket *socket = container_of(sock, struct yenta_socket, socket);
u16 bridge;
if (state->Vcc == 0)
yenta_set_power(socket, state);
socket->io_irq = state->io_irq;
bridge = config_readw(socket, CB_BRIDGE_CONTROL) & ~(CB_BRIDGE_CRST | CB_BRIDGE_INTR);
if (cb_readl(socket, CB_SOCKET_STATE) & CB_CBCARD) {
u8 intr;
bridge |= (state->flags & SS_RESET) ? CB_BRIDGE_CRST : 0;
intr = exca_readb(socket, I365_INTCTL);
intr = (intr & ~0xf);
if (!socket->dev->irq) {
intr |= socket->cb_irq ? socket->cb_irq : state->io_irq;
bridge |= CB_BRIDGE_INTR;
}
exca_writeb(socket, I365_INTCTL, intr);
} else {
u8 reg;
reg = exca_readb(socket, I365_INTCTL) & (I365_RING_ENA | I365_INTR_ENA);
reg |= (state->flags & SS_RESET) ? 0 : I365_PC_RESET;
reg |= (state->flags & SS_IOCARD) ? I365_PC_IOCARD : 0;
if (state->io_irq != socket->dev->irq) {
reg |= state->io_irq;
bridge |= CB_BRIDGE_INTR;
}
exca_writeb(socket, I365_INTCTL, reg);
reg = exca_readb(socket, I365_POWER) & (I365_VCC_MASK|I365_VPP1_MASK);
reg |= I365_PWR_NORESET;
if (state->flags & SS_PWR_AUTO)
reg |= I365_PWR_AUTO;
if (state->flags & SS_OUTPUT_ENA)
reg |= I365_PWR_OUT;
if (exca_readb(socket, I365_POWER) != reg)
exca_writeb(socket, I365_POWER, reg);
reg = exca_readb(socket, I365_CSCINT);
reg &= I365_CSC_IRQ_MASK;
reg |= I365_CSC_DETECT;
if (state->flags & SS_IOCARD) {
if (state->csc_mask & SS_STSCHG)
reg |= I365_CSC_STSCHG;
} else {
if (state->csc_mask & SS_BATDEAD)
reg |= I365_CSC_BVD1;
if (state->csc_mask & SS_BATWARN)
reg |= I365_CSC_BVD2;
if (state->csc_mask & SS_READY)
reg |= I365_CSC_READY;
}
exca_writeb(socket, I365_CSCINT, reg);
exca_readb(socket, I365_CSC);
if (sock->zoom_video)
sock->zoom_video(sock, state->flags & SS_ZVCARD);
}
config_writew(socket, CB_BRIDGE_CONTROL, bridge);
cb_writel(socket, CB_SOCKET_EVENT, -1);
cb_writel(socket, CB_SOCKET_MASK, CB_CDMASK);
if (state->Vcc != 0)
yenta_set_power(socket, state);
return 0;
}
static int yenta_set_io_map(struct pcmcia_socket *sock, struct pccard_io_map *io)
{
struct yenta_socket *socket = container_of(sock, struct yenta_socket, socket);
int map;
unsigned char ioctl, addr, enable;
map = io->map;
if (map > 1)
return -EINVAL;
enable = I365_ENA_IO(map);
addr = exca_readb(socket, I365_ADDRWIN);
if (addr & enable) {
addr &= ~enable;
exca_writeb(socket, I365_ADDRWIN, addr);
}
exca_writew(socket, I365_IO(map)+I365_W_START, io->start);
exca_writew(socket, I365_IO(map)+I365_W_STOP, io->stop);
ioctl = exca_readb(socket, I365_IOCTL) & ~I365_IOCTL_MASK(map);
if (io->flags & MAP_0WS)
ioctl |= I365_IOCTL_0WS(map);
if (io->flags & MAP_16BIT)
ioctl |= I365_IOCTL_16BIT(map);
if (io->flags & MAP_AUTOSZ)
ioctl |= I365_IOCTL_IOCS16(map);
exca_writeb(socket, I365_IOCTL, ioctl);
if (io->flags & MAP_ACTIVE)
exca_writeb(socket, I365_ADDRWIN, addr | enable);
return 0;
}
static int yenta_set_mem_map(struct pcmcia_socket *sock, struct pccard_mem_map *mem)
{
struct yenta_socket *socket = container_of(sock, struct yenta_socket, socket);
struct pci_bus_region region;
int map;
unsigned char addr, enable;
unsigned int start, stop, card_start;
unsigned short word;
pcibios_resource_to_bus(socket->dev, &region, mem->res);
map = mem->map;
start = region.start;
stop = region.end;
card_start = mem->card_start;
if (map > 4 || start > stop || ((start ^ stop) >> 24) ||
(card_start >> 26) || mem->speed > 1000)
return -EINVAL;
enable = I365_ENA_MEM(map);
addr = exca_readb(socket, I365_ADDRWIN);
if (addr & enable) {
addr &= ~enable;
exca_writeb(socket, I365_ADDRWIN, addr);
}
exca_writeb(socket, CB_MEM_PAGE(map), start >> 24);
word = (start >> 12) & 0x0fff;
if (mem->flags & MAP_16BIT)
word |= I365_MEM_16BIT;
if (mem->flags & MAP_0WS)
word |= I365_MEM_0WS;
exca_writew(socket, I365_MEM(map) + I365_W_START, word);
word = (stop >> 12) & 0x0fff;
switch (to_cycles(mem->speed)) {
case 0:
break;
case 1:
word |= I365_MEM_WS0;
break;
case 2:
word |= I365_MEM_WS1;
break;
default:
word |= I365_MEM_WS1 | I365_MEM_WS0;
break;
}
exca_writew(socket, I365_MEM(map) + I365_W_STOP, word);
word = ((card_start - start) >> 12) & 0x3fff;
if (mem->flags & MAP_WRPROT)
word |= I365_MEM_WRPROT;
if (mem->flags & MAP_ATTRIB)
word |= I365_MEM_REG;
exca_writew(socket, I365_MEM(map) + I365_W_OFF, word);
if (mem->flags & MAP_ACTIVE)
exca_writeb(socket, I365_ADDRWIN, addr | enable);
return 0;
}
static irqreturn_t yenta_interrupt(int irq, void *dev_id)
{
unsigned int events;
struct yenta_socket *socket = (struct yenta_socket *) dev_id;
u8 csc;
u32 cb_event;
cb_event = cb_readl(socket, CB_SOCKET_EVENT);
cb_writel(socket, CB_SOCKET_EVENT, cb_event);
csc = exca_readb(socket, I365_CSC);
if (!(cb_event || csc))
return IRQ_NONE;
events = (cb_event & (CB_CD1EVENT | CB_CD2EVENT)) ? SS_DETECT : 0 ;
events |= (csc & I365_CSC_DETECT) ? SS_DETECT : 0;
if (exca_readb(socket, I365_INTCTL) & I365_PC_IOCARD) {
events |= (csc & I365_CSC_STSCHG) ? SS_STSCHG : 0;
} else {
events |= (csc & I365_CSC_BVD1) ? SS_BATDEAD : 0;
events |= (csc & I365_CSC_BVD2) ? SS_BATWARN : 0;
events |= (csc & I365_CSC_READY) ? SS_READY : 0;
}
if (events)
pcmcia_parse_events(&socket->socket, events);
return IRQ_HANDLED;
}
static void yenta_interrupt_wrapper(unsigned long data)
{
struct yenta_socket *socket = (struct yenta_socket *) data;
yenta_interrupt(0, (void *)socket);
socket->poll_timer.expires = jiffies + HZ;
add_timer(&socket->poll_timer);
}
static void yenta_clear_maps(struct yenta_socket *socket)
{
int i;
struct resource res = { .start = 0, .end = 0x0fff };
pccard_io_map io = { 0, 0, 0, 0, 1 };
pccard_mem_map mem = { .res = &res, };
yenta_set_socket(&socket->socket, &dead_socket);
for (i = 0; i < 2; i++) {
io.map = i;
yenta_set_io_map(&socket->socket, &io);
}
for (i = 0; i < 5; i++) {
mem.map = i;
yenta_set_mem_map(&socket->socket, &mem);
}
}
static void yenta_interrogate(struct yenta_socket *socket)
{
u32 state;
state = cb_readl(socket, CB_SOCKET_STATE);
if (!(state & (CB_5VCARD | CB_3VCARD | CB_XVCARD | CB_YVCARD)) ||
(state & (CB_CDETECT1 | CB_CDETECT2 | CB_NOTACARD | CB_BADVCCREQ)) ||
((state & (CB_16BITCARD | CB_CBCARD)) == (CB_16BITCARD | CB_CBCARD)))
cb_writel(socket, CB_SOCKET_FORCE, CB_CVSTEST);
}
static int yenta_sock_init(struct pcmcia_socket *sock)
{
struct yenta_socket *socket = container_of(sock, struct yenta_socket, socket);
exca_writeb(socket, I365_GBLCTL, 0x00);
exca_writeb(socket, I365_GENCTL, 0x00);
yenta_interrogate(socket);
yenta_clear_maps(socket);
if (socket->type && socket->type->sock_init)
socket->type->sock_init(socket);
cb_writel(socket, CB_SOCKET_MASK, CB_CDMASK);
return 0;
}
static int yenta_sock_suspend(struct pcmcia_socket *sock)
{
struct yenta_socket *socket = container_of(sock, struct yenta_socket, socket);
cb_writel(socket, CB_SOCKET_MASK, 0x0);
return 0;
}
static int yenta_search_one_res(struct resource *root, struct resource *res,
u32 min)
{
u32 align, size, start, end;
if (res->flags & IORESOURCE_IO) {
align = 1024;
size = BRIDGE_IO_MAX;
start = PCIBIOS_MIN_CARDBUS_IO;
end = ~0U;
} else {
unsigned long avail = root->end - root->start;
int i;
size = BRIDGE_MEM_MAX;
if (size > avail/8) {
size = (avail+1)/8;
i = 0;
while ((size /= 2) != 0)
i++;
size = 1 << i;
}
if (size < min)
size = min;
align = size;
start = PCIBIOS_MIN_MEM;
end = ~0U;
}
do {
if (allocate_resource(root, res, size, start, end, align,
NULL, NULL) == 0) {
return 1;
}
size = size/2;
align = size;
} while (size >= min);
return 0;
}
static int yenta_search_res(struct yenta_socket *socket, struct resource *res,
u32 min)
{
struct resource *root;
int i;
pci_bus_for_each_resource(socket->dev->bus, root, i) {
if (!root)
continue;
if ((res->flags ^ root->flags) &
(IORESOURCE_IO | IORESOURCE_MEM | IORESOURCE_PREFETCH))
continue;
if (yenta_search_one_res(root, res, min))
return 1;
}
return 0;
}
static int yenta_allocate_res(struct yenta_socket *socket, int nr, unsigned type, int addr_start, int addr_end)
{
struct pci_dev *dev = socket->dev;
struct resource *res;
struct pci_bus_region region;
unsigned mask;
res = dev->resource + PCI_BRIDGE_RESOURCES + nr;
if (res->parent)
return 0;
mask = ~0xfff;
if (type & IORESOURCE_IO)
mask = ~3;
res->name = dev->subordinate->name;
res->flags = type;
region.start = config_readl(socket, addr_start) & mask;
region.end = config_readl(socket, addr_end) | ~mask;
if (region.start && region.end > region.start && !override_bios) {
pcibios_bus_to_resource(dev, res, &region);
if (pci_claim_resource(dev, PCI_BRIDGE_RESOURCES + nr) == 0)
return 0;
dev_printk(KERN_INFO, &dev->dev,
"Preassigned resource %d busy or not available, "
"reconfiguring...\n",
nr);
}
if (type & IORESOURCE_IO) {
if ((yenta_search_res(socket, res, BRIDGE_IO_MAX)) ||
(yenta_search_res(socket, res, BRIDGE_IO_ACC)) ||
(yenta_search_res(socket, res, BRIDGE_IO_MIN)))
return 1;
} else {
if (type & IORESOURCE_PREFETCH) {
if ((yenta_search_res(socket, res, BRIDGE_MEM_MAX)) ||
(yenta_search_res(socket, res, BRIDGE_MEM_ACC)) ||
(yenta_search_res(socket, res, BRIDGE_MEM_MIN)))
return 1;
res->flags = IORESOURCE_MEM;
}
if ((yenta_search_res(socket, res, BRIDGE_MEM_MAX)) ||
(yenta_search_res(socket, res, BRIDGE_MEM_ACC)) ||
(yenta_search_res(socket, res, BRIDGE_MEM_MIN)))
return 1;
}
dev_printk(KERN_INFO, &dev->dev,
"no resource of type %x available, trying to continue...\n",
type);
res->start = res->end = res->flags = 0;
return 0;
}
static void yenta_allocate_resources(struct yenta_socket *socket)
{
int program = 0;
program += yenta_allocate_res(socket, 0, IORESOURCE_IO,
PCI_CB_IO_BASE_0, PCI_CB_IO_LIMIT_0);
program += yenta_allocate_res(socket, 1, IORESOURCE_IO,
PCI_CB_IO_BASE_1, PCI_CB_IO_LIMIT_1);
program += yenta_allocate_res(socket, 2, IORESOURCE_MEM|IORESOURCE_PREFETCH,
PCI_CB_MEMORY_BASE_0, PCI_CB_MEMORY_LIMIT_0);
program += yenta_allocate_res(socket, 3, IORESOURCE_MEM,
PCI_CB_MEMORY_BASE_1, PCI_CB_MEMORY_LIMIT_1);
if (program)
pci_setup_cardbus(socket->dev->subordinate);
}
static void yenta_free_resources(struct yenta_socket *socket)
{
int i;
for (i = 0; i < 4; i++) {
struct resource *res;
res = socket->dev->resource + PCI_BRIDGE_RESOURCES + i;
if (res->start != 0 && res->end != 0)
release_resource(res);
res->start = res->end = res->flags = 0;
}
}
static void yenta_close(struct pci_dev *dev)
{
struct yenta_socket *sock = pci_get_drvdata(dev);
device_remove_file(&dev->dev, &dev_attr_yenta_registers);
pcmcia_unregister_socket(&sock->socket);
cb_writel(sock, CB_SOCKET_MASK, 0x0);
exca_writeb(sock, I365_CSCINT, 0);
if (sock->cb_irq)
free_irq(sock->cb_irq, sock);
else
del_timer_sync(&sock->poll_timer);
if (sock->base)
iounmap(sock->base);
yenta_free_resources(sock);
pci_release_regions(dev);
pci_disable_device(dev);
pci_set_drvdata(dev, NULL);
}
static unsigned int yenta_probe_irq(struct yenta_socket *socket, u32 isa_irq_mask)
{
int i;
unsigned long val;
u32 mask;
u8 reg;
cb_writel(socket, CB_SOCKET_EVENT, -1);
cb_writel(socket, CB_SOCKET_MASK, CB_CSTSMASK);
reg = exca_readb(socket, I365_CSCINT);
exca_writeb(socket, I365_CSCINT, 0);
val = probe_irq_on() & isa_irq_mask;
for (i = 1; i < 16; i++) {
if (!((val >> i) & 1))
continue;
exca_writeb(socket, I365_CSCINT, I365_CSC_STSCHG | (i << 4));
cb_writel(socket, CB_SOCKET_FORCE, CB_FCARDSTS);
udelay(100);
cb_writel(socket, CB_SOCKET_EVENT, -1);
}
cb_writel(socket, CB_SOCKET_MASK, 0);
exca_writeb(socket, I365_CSCINT, reg);
mask = probe_irq_mask(val) & 0xffff;
return mask;
}
static irqreturn_t yenta_probe_handler(int irq, void *dev_id)
{
struct yenta_socket *socket = (struct yenta_socket *) dev_id;
u8 csc;
u32 cb_event;
cb_event = cb_readl(socket, CB_SOCKET_EVENT);
cb_writel(socket, CB_SOCKET_EVENT, -1);
csc = exca_readb(socket, I365_CSC);
if (cb_event || csc) {
socket->probe_status = 1;
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static int yenta_probe_cb_irq(struct yenta_socket *socket)
{
u8 reg = 0;
if (!socket->cb_irq)
return -1;
socket->probe_status = 0;
if (request_irq(socket->cb_irq, yenta_probe_handler, IRQF_SHARED, "yenta", socket)) {
dev_printk(KERN_WARNING, &socket->dev->dev,
"request_irq() in yenta_probe_cb_irq() failed!\n");
return -1;
}
if (!socket->dev->irq)
reg = exca_readb(socket, I365_CSCINT);
exca_writeb(socket, I365_CSCINT, reg | I365_CSC_STSCHG);
cb_writel(socket, CB_SOCKET_EVENT, -1);
cb_writel(socket, CB_SOCKET_MASK, CB_CSTSMASK);
cb_writel(socket, CB_SOCKET_FORCE, CB_FCARDSTS);
msleep(100);
cb_writel(socket, CB_SOCKET_MASK, 0);
exca_writeb(socket, I365_CSCINT, reg);
cb_writel(socket, CB_SOCKET_EVENT, -1);
exca_readb(socket, I365_CSC);
free_irq(socket->cb_irq, socket);
return (int) socket->probe_status;
}
static void yenta_get_socket_capabilities(struct yenta_socket *socket, u32 isa_irq_mask)
{
socket->socket.pci_irq = socket->cb_irq;
if (isa_probe)
socket->socket.irq_mask = yenta_probe_irq(socket, isa_irq_mask);
else
socket->socket.irq_mask = 0;
dev_printk(KERN_INFO, &socket->dev->dev,
"ISA IRQ mask 0x%04x, PCI irq %d\n",
socket->socket.irq_mask, socket->cb_irq);
}
static void yenta_config_init(struct yenta_socket *socket)
{
u16 bridge;
struct pci_dev *dev = socket->dev;
struct pci_bus_region region;
pcibios_resource_to_bus(socket->dev, &region, &dev->resource[0]);
config_writel(socket, CB_LEGACY_MODE_BASE, 0);
config_writel(socket, PCI_BASE_ADDRESS_0, region.start);
config_writew(socket, PCI_COMMAND,
PCI_COMMAND_IO |
PCI_COMMAND_MEMORY |
PCI_COMMAND_MASTER |
PCI_COMMAND_WAIT);
config_writeb(socket, PCI_CACHE_LINE_SIZE, L1_CACHE_BYTES / 4);
config_writeb(socket, PCI_LATENCY_TIMER, 168);
config_writel(socket, PCI_PRIMARY_BUS,
(176 << 24) |
((unsigned int)dev->subordinate->busn_res.end << 16) |
((unsigned int)dev->subordinate->busn_res.start << 8) |
dev->subordinate->primary);
bridge = config_readw(socket, CB_BRIDGE_CONTROL);
bridge &= ~(CB_BRIDGE_CRST | CB_BRIDGE_PREFETCH1 | CB_BRIDGE_ISAEN | CB_BRIDGE_VGAEN);
bridge |= CB_BRIDGE_PREFETCH0 | CB_BRIDGE_POSTEN;
config_writew(socket, CB_BRIDGE_CONTROL, bridge);
}
static void yenta_fixup_parent_bridge(struct pci_bus *cardbus_bridge)
{
struct list_head *tmp;
unsigned char upper_limit;
struct pci_bus *bridge_to_fix = cardbus_bridge->parent;
if (bridge_to_fix->busn_res.end >= cardbus_bridge->busn_res.end)
return;
if (!bridge_to_fix->parent)
return;
upper_limit = bridge_to_fix->parent->busn_res.end;
list_for_each(tmp, &bridge_to_fix->parent->children) {
struct pci_bus *silbling = pci_bus_b(tmp);
if (silbling->busn_res.start > bridge_to_fix->busn_res.end
&& silbling->busn_res.start <= upper_limit)
upper_limit = silbling->busn_res.start - 1;
}
if (cardbus_bridge->busn_res.end > upper_limit)
dev_printk(KERN_WARNING, &cardbus_bridge->dev,
"Upper limit for fixing this "
"bridge's parent bridge: #%02x\n", upper_limit);
if (bridge_to_fix->busn_res.end < upper_limit) {
unsigned char subordinate_to_assign =
min_t(int, cardbus_bridge->busn_res.end, upper_limit);
dev_printk(KERN_INFO, &bridge_to_fix->dev,
"Raising subordinate bus# of parent "
"bus (#%02x) from #%02x to #%02x\n",
bridge_to_fix->number,
(int)bridge_to_fix->busn_res.end, subordinate_to_assign);
bridge_to_fix->busn_res.end = subordinate_to_assign;
pci_write_config_byte(bridge_to_fix->self,
PCI_SUBORDINATE_BUS, bridge_to_fix->busn_res.end);
}
}
static int yenta_probe(struct pci_dev *dev, const struct pci_device_id *id)
{
struct yenta_socket *socket;
int ret;
if (!dev->subordinate) {
dev_printk(KERN_ERR, &dev->dev, "no bus associated! "
"(try 'pci=assign-busses')\n");
return -ENODEV;
}
socket = kzalloc(sizeof(struct yenta_socket), GFP_KERNEL);
if (!socket)
return -ENOMEM;
socket->socket.ops = &yenta_socket_operations;
socket->socket.resource_ops = &pccard_nonstatic_ops;
socket->socket.dev.parent = &dev->dev;
socket->socket.driver_data = socket;
socket->socket.owner = THIS_MODULE;
socket->socket.features = SS_CAP_PAGE_REGS | SS_CAP_PCCARD;
socket->socket.map_size = 0x1000;
socket->socket.cb_dev = dev;
socket->dev = dev;
pci_set_drvdata(dev, socket);
if (pci_enable_device(dev)) {
ret = -EBUSY;
goto free;
}
ret = pci_request_regions(dev, "yenta_socket");
if (ret)
goto disable;
if (!pci_resource_start(dev, 0)) {
dev_printk(KERN_ERR, &dev->dev, "No cardbus resource!\n");
ret = -ENODEV;
goto release;
}
socket->base = ioremap(pci_resource_start(dev, 0), 0x1000);
if (!socket->base) {
ret = -ENOMEM;
goto release;
}
dev_printk(KERN_INFO, &dev->dev, "CardBus bridge found [%04x:%04x]\n",
dev->subsystem_vendor, dev->subsystem_device);
yenta_config_init(socket);
cb_writel(socket, CB_SOCKET_MASK, 0x0);
yenta_allocate_resources(socket);
socket->cb_irq = dev->irq;
if (id->driver_data != CARDBUS_TYPE_DEFAULT &&
id->driver_data < ARRAY_SIZE(cardbus_type)) {
socket->type = &cardbus_type[id->driver_data];
ret = socket->type->override(socket);
if (ret < 0)
goto unmap;
}
if (!socket->cb_irq || request_irq(socket->cb_irq, yenta_interrupt, IRQF_SHARED, "yenta", socket)) {
socket->cb_irq = 0;
init_timer(&socket->poll_timer);
socket->poll_timer.function = yenta_interrupt_wrapper;
socket->poll_timer.data = (unsigned long)socket;
socket->poll_timer.expires = jiffies + HZ;
add_timer(&socket->poll_timer);
dev_printk(KERN_INFO, &dev->dev,
"no PCI IRQ, CardBus support disabled for this "
"socket.\n");
dev_printk(KERN_INFO, &dev->dev,
"check your BIOS CardBus, BIOS IRQ or ACPI "
"settings.\n");
} else {
socket->socket.features |= SS_CAP_CARDBUS;
}
yenta_interrogate(socket);
yenta_get_socket_capabilities(socket, isa_interrupts);
dev_printk(KERN_INFO, &dev->dev,
"Socket status: %08x\n", cb_readl(socket, CB_SOCKET_STATE));
yenta_fixup_parent_bridge(dev->subordinate);
ret = pcmcia_register_socket(&socket->socket);
if (ret == 0) {
ret = device_create_file(&dev->dev, &dev_attr_yenta_registers);
if (ret == 0)
goto out;
pcmcia_unregister_socket(&socket->socket);
}
unmap:
iounmap(socket->base);
release:
pci_release_regions(dev);
disable:
pci_disable_device(dev);
free:
kfree(socket);
out:
return ret;
}
static int yenta_dev_suspend_noirq(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct yenta_socket *socket = pci_get_drvdata(pdev);
if (!socket)
return 0;
if (socket->type && socket->type->save_state)
socket->type->save_state(socket);
pci_save_state(pdev);
pci_read_config_dword(pdev, 16*4, &socket->saved_state[0]);
pci_read_config_dword(pdev, 17*4, &socket->saved_state[1]);
pci_disable_device(pdev);
return 0;
}
static int yenta_dev_resume_noirq(struct device *dev)
{
struct pci_dev *pdev = to_pci_dev(dev);
struct yenta_socket *socket = pci_get_drvdata(pdev);
int ret;
if (!socket)
return 0;
pci_write_config_dword(pdev, 16*4, socket->saved_state[0]);
pci_write_config_dword(pdev, 17*4, socket->saved_state[1]);
ret = pci_enable_device(pdev);
if (ret)
return ret;
pci_set_master(pdev);
if (socket->type && socket->type->restore_state)
socket->type->restore_state(socket);
return 0;
}
