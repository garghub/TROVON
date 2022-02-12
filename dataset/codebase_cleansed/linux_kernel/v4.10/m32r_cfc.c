static inline u_long pcc_port2addr(unsigned long port, int size) {
u_long addr = 0;
u_long odd;
if (size == 1) {
odd = (port&1) << 11;
port -= port & 1;
addr = CFC_IO_MAPBASE_BYTE - CFC_IOPORT_BASE + odd + port;
} else if (size == 2)
addr = CFC_IO_MAPBASE_WORD - CFC_IOPORT_BASE + port;
return addr;
}
static inline u_long pcc_port2addr(unsigned long port, int size) {
u_long odd;
u_long addr = ((port - CFC_IOPORT_BASE) & 0xf000) << 8;
if (size == 1) {
odd = port & 1;
port -= odd;
odd <<= 11;
addr = (addr | CFC_IO_MAPBASE_BYTE) + odd + (port & 0xfff);
} else if (size == 2)
addr = (addr | CFC_IO_MAPBASE_WORD) + (port & 0xfff);
return addr;
}
void pcc_ioread_byte(int sock, unsigned long port, void *buf, size_t size,
size_t nmemb, int flag)
{
u_long addr;
unsigned char *bp = (unsigned char *)buf;
unsigned long flags;
pr_debug("m32r_cfc: pcc_ioread_byte: sock=%d, port=%#lx, buf=%p, "
"size=%u, nmemb=%d, flag=%d\n",
sock, port, buf, size, nmemb, flag);
addr = pcc_port2addr(port, 1);
if (!addr) {
printk("m32r_cfc:ioread_byte null port :%#lx\n",port);
return;
}
pr_debug("m32r_cfc: pcc_ioread_byte: addr=%#lx\n", addr);
spin_lock_irqsave(&pcc_lock, flags);
while (nmemb--)
*bp++ = readb(addr);
spin_unlock_irqrestore(&pcc_lock, flags);
}
void pcc_ioread_word(int sock, unsigned long port, void *buf, size_t size,
size_t nmemb, int flag)
{
u_long addr;
unsigned short *bp = (unsigned short *)buf;
unsigned long flags;
pr_debug("m32r_cfc: pcc_ioread_word: sock=%d, port=%#lx, "
"buf=%p, size=%u, nmemb=%d, flag=%d\n",
sock, port, buf, size, nmemb, flag);
if (size != 2)
printk("m32r_cfc: ioread_word :illigal size %u : %#lx\n", size,
port);
if (size == 9)
printk("m32r_cfc: ioread_word :insw \n");
addr = pcc_port2addr(port, 2);
if (!addr) {
printk("m32r_cfc:ioread_word null port :%#lx\n",port);
return;
}
pr_debug("m32r_cfc: pcc_ioread_word: addr=%#lx\n", addr);
spin_lock_irqsave(&pcc_lock, flags);
while (nmemb--)
*bp++ = readw(addr);
spin_unlock_irqrestore(&pcc_lock, flags);
}
void pcc_iowrite_byte(int sock, unsigned long port, void *buf, size_t size,
size_t nmemb, int flag)
{
u_long addr;
unsigned char *bp = (unsigned char *)buf;
unsigned long flags;
pr_debug("m32r_cfc: pcc_iowrite_byte: sock=%d, port=%#lx, "
"buf=%p, size=%u, nmemb=%d, flag=%d\n",
sock, port, buf, size, nmemb, flag);
addr = pcc_port2addr(port, 1);
if (!addr) {
printk("m32r_cfc:iowrite_byte null port:%#lx\n",port);
return;
}
pr_debug("m32r_cfc: pcc_iowrite_byte: addr=%#lx\n", addr);
spin_lock_irqsave(&pcc_lock, flags);
while (nmemb--)
writeb(*bp++, addr);
spin_unlock_irqrestore(&pcc_lock, flags);
}
void pcc_iowrite_word(int sock, unsigned long port, void *buf, size_t size,
size_t nmemb, int flag)
{
u_long addr;
unsigned short *bp = (unsigned short *)buf;
unsigned long flags;
pr_debug("m32r_cfc: pcc_iowrite_word: sock=%d, port=%#lx, "
"buf=%p, size=%u, nmemb=%d, flag=%d\n",
sock, port, buf, size, nmemb, flag);
if(size != 2)
printk("m32r_cfc: iowrite_word :illigal size %u : %#lx\n",
size, port);
if(size == 9)
printk("m32r_cfc: iowrite_word :outsw \n");
addr = pcc_port2addr(port, 2);
if (!addr) {
printk("m32r_cfc:iowrite_word null addr :%#lx\n",port);
return;
}
#if 1
if (addr & 1) {
printk("m32r_cfc:iowrite_word port addr (%#lx):%#lx\n", port,
addr);
return;
}
#endif
pr_debug("m32r_cfc: pcc_iowrite_word: addr=%#lx\n", addr);
spin_lock_irqsave(&pcc_lock, flags);
while (nmemb--)
writew(*bp++, addr);
spin_unlock_irqrestore(&pcc_lock, flags);
}
static unsigned int pcc_get(u_short sock, unsigned int reg)
{
unsigned int val = inw(reg);
pr_debug("m32r_cfc: pcc_get: reg(0x%08x)=0x%04x\n", reg, val);
return val;
}
static void pcc_set(u_short sock, unsigned int reg, unsigned int data)
{
outw(data, reg);
pr_debug("m32r_cfc: pcc_set: reg(0x%08x)=0x%04x\n", reg, data);
}
static int __init is_alive(u_short sock)
{
unsigned int stat;
pr_debug("m32r_cfc: is_alive:\n");
printk("CF: ");
stat = pcc_get(sock, (unsigned int)PLD_CFSTS);
if (!stat)
printk("No ");
printk("Card is detected at socket %d : stat = 0x%08x\n", sock, stat);
pr_debug("m32r_cfc: is_alive: sock stat is 0x%04x\n", stat);
return 0;
}
static void add_pcc_socket(ulong base, int irq, ulong mapaddr,
unsigned int ioaddr)
{
pcc_socket_t *t = &socket[pcc_sockets];
pr_debug("m32r_cfc: add_pcc_socket: base=%#lx, irq=%d, "
"mapaddr=%#lx, ioaddr=%08x\n",
base, irq, mapaddr, ioaddr);
t->ioaddr = ioaddr;
t->mapaddr = mapaddr;
#if !defined(CONFIG_PLAT_USRV)
t->base = 0;
t->flags = 0;
t->cs_irq1 = irq;
t->cs_irq2 = irq + 1;
#else
t->base = base;
t->flags = 0;
t->cs_irq1 = 0;
t->cs_irq2 = 0;
#endif
if (is_alive(pcc_sockets))
t->flags |= IS_ALIVE;
#if !defined(CONFIG_PLAT_USRV)
request_region((unsigned int)PLD_CFRSTCR, 0x20, "m32r_cfc");
#else
{
unsigned int reg_base;
reg_base = (unsigned int)PLD_CFRSTCR;
reg_base |= pcc_sockets << 8;
request_region(reg_base, 0x20, "m32r_cfc");
}
#endif
printk(KERN_INFO " %s ", pcc[pcc_sockets].name);
printk("pcc at 0x%08lx\n", t->base);
t->socket.features |= (SS_CAP_PCCARD | SS_CAP_STATIC_MAP);
t->socket.map_size = M32R_PCC_MAPSIZE;
t->socket.io_offset = ioaddr;
t->socket.irq_mask = 0;
#if !defined(CONFIG_PLAT_USRV)
t->socket.pci_irq = PLD_IRQ_CFIREQ ;
#else
t->socket.pci_irq = PLD_IRQ_CF0 + pcc_sockets;
#endif
#ifndef CONFIG_PLAT_USRV
request_irq(irq, pcc_interrupt, 0, "m32r_cfc", pcc_interrupt);
#ifndef CONFIG_PLAT_MAPPI3
request_irq(irq+1, pcc_interrupt, 0, "m32r_cfc", pcc_interrupt);
#endif
pr_debug("m32r_cfc: enable CFMSK, RDYSEL\n");
pcc_set(pcc_sockets, (unsigned int)PLD_CFIMASK, 0x01);
#endif
#if defined(CONFIG_PLAT_M32700UT) || defined(CONFIG_PLAT_USRV) || defined(CONFIG_PLAT_OPSPUT)
pcc_set(pcc_sockets, (unsigned int)PLD_CFCR1, 0x0200);
#endif
pcc_sockets++;
return;
}
static irqreturn_t pcc_interrupt(int irq, void *dev)
{
int i;
u_int events = 0;
int handled = 0;
pr_debug("m32r_cfc: pcc_interrupt: irq=%d, dev=%p\n", irq, dev);
for (i = 0; i < pcc_sockets; i++) {
if (socket[i].cs_irq1 != irq && socket[i].cs_irq2 != irq)
continue;
handled = 1;
pr_debug("m32r_cfc: pcc_interrupt: socket %d irq 0x%02x ",
i, irq);
events |= SS_DETECT;
if (events)
pcmcia_parse_events(&socket[i].socket, events);
}
pr_debug("m32r_cfc: pcc_interrupt: done\n");
return IRQ_RETVAL(handled);
}
static void pcc_interrupt_wrapper(u_long data)
{
pr_debug("m32r_cfc: pcc_interrupt_wrapper:\n");
pcc_interrupt(0, NULL);
init_timer(&poll_timer);
poll_timer.expires = jiffies + poll_interval;
add_timer(&poll_timer);
}
static int _pcc_get_status(u_short sock, u_int *value)
{
u_int status;
pr_debug("m32r_cfc: _pcc_get_status:\n");
status = pcc_get(sock, (unsigned int)PLD_CFSTS);
*value = (status) ? SS_DETECT : 0;
pr_debug("m32r_cfc: _pcc_get_status: status=0x%08x\n", status);
#if defined(CONFIG_PLAT_M32700UT) || defined(CONFIG_PLAT_USRV) || defined(CONFIG_PLAT_OPSPUT)
if ( status ) {
status = inw((unsigned int)PLD_CPCR);
if (!(status & PLD_CPCR_CF)) {
pr_debug("m32r_cfc: _pcc_get_status: "
"power on (CPCR=0x%08x)\n", status);
status |= PLD_CPCR_CF;
outw(status, (unsigned int)PLD_CPCR);
udelay(100);
}
*value |= SS_POWERON;
pcc_set(sock, (unsigned int)PLD_CFBUFCR,0);
udelay(100);
*value |= SS_READY;
*value |= SS_3VCARD;
} else {
status = inw((unsigned int)PLD_CPCR);
status &= ~PLD_CPCR_CF;
outw(status, (unsigned int)PLD_CPCR);
udelay(100);
pr_debug("m32r_cfc: _pcc_get_status: "
"power off (CPCR=0x%08x)\n", status);
}
#elif defined(CONFIG_PLAT_MAPPI2) || defined(CONFIG_PLAT_MAPPI3)
if ( status ) {
status = pcc_get(sock, (unsigned int)PLD_CPCR);
if (status == 0) {
pcc_set(sock, (unsigned int)PLD_CPCR, 1);
pcc_set(sock, (unsigned int)PLD_CFBUFCR,0);
udelay(50);
}
*value |= SS_POWERON;
pcc_set(sock, (unsigned int)PLD_CFBUFCR,0);
udelay(50);
pcc_set(sock, (unsigned int)PLD_CFRSTCR, 0x0101);
udelay(25);
pcc_set(sock, (unsigned int)PLD_CFRSTCR, 0x0100);
mdelay(2);
*value |= SS_READY;
*value |= SS_3VCARD;
} else {
pcc_set(sock, (unsigned int)PLD_CPCR, 0);
udelay(100);
pr_debug("m32r_cfc: _pcc_get_status: "
"power off (CPCR=0x%08x)\n", status);
}
#else
#error no platform configuration
#endif
pr_debug("m32r_cfc: _pcc_get_status: GetStatus(%d) = %#4.4x\n",
sock, *value);
return 0;
}
static int _pcc_set_socket(u_short sock, socket_state_t *state)
{
pr_debug("m32r_cfc: SetSocket(%d, flags %#3.3x, Vcc %d, Vpp %d, "
"io_irq %d, csc_mask %#2.2x)\n", sock, state->flags,
state->Vcc, state->Vpp, state->io_irq, state->csc_mask);
#if defined(CONFIG_PLAT_M32700UT) || defined(CONFIG_PLAT_USRV) || defined(CONFIG_PLAT_OPSPUT) || defined(CONFIG_PLAT_MAPPI2) || defined(CONFIG_PLAT_MAPPI3)
if (state->Vcc) {
if ((state->Vcc != 50) && (state->Vcc != 33))
return -EINVAL;
}
#endif
if (state->flags & SS_RESET) {
pr_debug(":RESET\n");
pcc_set(sock,(unsigned int)PLD_CFRSTCR,0x101);
}else{
pcc_set(sock,(unsigned int)PLD_CFRSTCR,0x100);
}
if (state->flags & SS_OUTPUT_ENA){
pr_debug(":OUTPUT_ENA\n");
pcc_set(sock,(unsigned int)PLD_CFBUFCR,0);
} else {
pcc_set(sock,(unsigned int)PLD_CFBUFCR,1);
}
if(state->flags & SS_IOCARD){
pr_debug(":IOCARD");
}
if (state->flags & SS_PWR_AUTO) {
pr_debug(":PWR_AUTO");
}
if (state->csc_mask & SS_DETECT)
pr_debug(":csc-SS_DETECT");
if (state->flags & SS_IOCARD) {
if (state->csc_mask & SS_STSCHG)
pr_debug(":STSCHG");
} else {
if (state->csc_mask & SS_BATDEAD)
pr_debug(":BATDEAD");
if (state->csc_mask & SS_BATWARN)
pr_debug(":BATWARN");
if (state->csc_mask & SS_READY)
pr_debug(":READY");
}
pr_debug("\n");
return 0;
}
static int _pcc_set_io_map(u_short sock, struct pccard_io_map *io)
{
u_char map;
pr_debug("m32r_cfc: SetIOMap(%d, %d, %#2.2x, %d ns, "
"%#llx-%#llx)\n", sock, io->map, io->flags,
io->speed, (unsigned long long)io->start,
(unsigned long long)io->stop);
map = io->map;
return 0;
}
static int _pcc_set_mem_map(u_short sock, struct pccard_mem_map *mem)
{
u_char map = mem->map;
u_long addr;
pcc_socket_t *t = &socket[sock];
pr_debug("m32r_cfc: SetMemMap(%d, %d, %#2.2x, %d ns, "
"%#llx, %#x)\n", sock, map, mem->flags,
mem->speed, (unsigned long long)mem->static_start,
mem->card_start);
if ((map > MAX_WIN) || (mem->card_start > 0x3ffffff)){
return -EINVAL;
}
if ((mem->flags & MAP_ACTIVE) == 0) {
t->current_space = as_none;
return 0;
}
if (mem->flags & MAP_ATTRIB) {
t->current_space = as_attr;
} else {
t->current_space = as_comm;
}
addr = t->mapaddr + (mem->card_start & M32R_PCC_MAPMASK);
mem->static_start = addr + mem->card_start;
return 0;
}
static int pcc_get_status(struct pcmcia_socket *s, u_int *value)
{
unsigned int sock = container_of(s, struct pcc_socket, socket)->number;
if (socket[sock].flags & IS_ALIVE) {
dev_dbg(&s->dev, "pcc_get_status: sock(%d) -EINVAL\n", sock);
*value = 0;
return -EINVAL;
}
dev_dbg(&s->dev, "pcc_get_status: sock(%d)\n", sock);
LOCKED(_pcc_get_status(sock, value));
}
static int pcc_set_socket(struct pcmcia_socket *s, socket_state_t *state)
{
unsigned int sock = container_of(s, struct pcc_socket, socket)->number;
if (socket[sock].flags & IS_ALIVE) {
dev_dbg(&s->dev, "pcc_set_socket: sock(%d) -EINVAL\n", sock);
return -EINVAL;
}
dev_dbg(&s->dev, "pcc_set_socket: sock(%d)\n", sock);
LOCKED(_pcc_set_socket(sock, state));
}
static int pcc_set_io_map(struct pcmcia_socket *s, struct pccard_io_map *io)
{
unsigned int sock = container_of(s, struct pcc_socket, socket)->number;
if (socket[sock].flags & IS_ALIVE) {
dev_dbg(&s->dev, "pcc_set_io_map: sock(%d) -EINVAL\n", sock);
return -EINVAL;
}
dev_dbg(&s->dev, "pcc_set_io_map: sock(%d)\n", sock);
LOCKED(_pcc_set_io_map(sock, io));
}
static int pcc_set_mem_map(struct pcmcia_socket *s, struct pccard_mem_map *mem)
{
unsigned int sock = container_of(s, struct pcc_socket, socket)->number;
if (socket[sock].flags & IS_ALIVE) {
dev_dbg(&s->dev, "pcc_set_mem_map: sock(%d) -EINVAL\n", sock);
return -EINVAL;
}
dev_dbg(&s->dev, "pcc_set_mem_map: sock(%d)\n", sock);
LOCKED(_pcc_set_mem_map(sock, mem));
}
static int pcc_init(struct pcmcia_socket *s)
{
dev_dbg(&s->dev, "pcc_init()\n");
return 0;
}
static int __init init_m32r_pcc(void)
{
int i, ret;
ret = platform_driver_register(&pcc_driver);
if (ret)
return ret;
ret = platform_device_register(&pcc_device);
if (ret){
platform_driver_unregister(&pcc_driver);
return ret;
}
#if defined(CONFIG_PLAT_MAPPI2) || defined(CONFIG_PLAT_MAPPI3)
pcc_set(0, (unsigned int)PLD_CFCR0, 0x0f0f);
pcc_set(0, (unsigned int)PLD_CFCR1, 0x0200);
#endif
pcc_sockets = 0;
#if !defined(CONFIG_PLAT_USRV)
add_pcc_socket(M32R_PCC0_BASE, PLD_IRQ_CFC_INSERT, CFC_ATTR_MAPBASE,
CFC_IOPORT_BASE);
#else
{
ulong base, mapaddr;
unsigned int ioaddr;
for (i = 0 ; i < M32R_MAX_PCC ; i++) {
base = (ulong)PLD_CFRSTCR;
base = base | (i << 8);
ioaddr = (i + 1) << 12;
mapaddr = CFC_ATTR_MAPBASE | (i << 20);
add_pcc_socket(base, 0, mapaddr, ioaddr);
}
}
#endif
if (pcc_sockets == 0) {
printk("socket is not found.\n");
platform_device_unregister(&pcc_device);
platform_driver_unregister(&pcc_driver);
return -ENODEV;
}
for (i = 0 ; i < pcc_sockets ; i++) {
socket[i].socket.dev.parent = &pcc_device.dev;
socket[i].socket.ops = &pcc_operations;
socket[i].socket.resource_ops = &pccard_static_ops;
socket[i].socket.owner = THIS_MODULE;
socket[i].number = i;
ret = pcmcia_register_socket(&socket[i].socket);
if (!ret)
socket[i].flags |= IS_REGISTERED;
}
if (poll_interval != 0) {
poll_timer.function = pcc_interrupt_wrapper;
poll_timer.data = 0;
init_timer(&poll_timer);
poll_timer.expires = jiffies + poll_interval;
add_timer(&poll_timer);
}
return 0;
}
static void __exit exit_m32r_pcc(void)
{
int i;
for (i = 0; i < pcc_sockets; i++)
if (socket[i].flags & IS_REGISTERED)
pcmcia_unregister_socket(&socket[i].socket);
platform_device_unregister(&pcc_device);
if (poll_interval != 0)
del_timer_sync(&poll_timer);
platform_driver_unregister(&pcc_driver);
}
