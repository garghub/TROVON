void pcc_iorw(int sock, unsigned long port, void *buf, size_t size, size_t nmemb, int wr, int flag)
{
u_long addr;
u_long flags;
int need_ex;
#ifdef PCC_DEBUG_DBEX
int _dbex;
#endif
pcc_socket_t *t = &socket[sock];
#ifdef CHAOS_PCC_DEBUG
int map_changed = 0;
#endif
spin_lock_irqsave(&pcc_lock, flags);
need_ex = (size > 1 && flag == 0) ? PCMOD_DBEX : 0;
#ifdef PCC_DEBUG_DBEX
_dbex = need_ex;
need_ex = 0;
#endif
addr = t->mapaddr + port - t->ioaddr + KSEG1;
if (t->current_space != as_io || t->last_iodbex != need_ex) {
u_long cbsz;
pcc_set(sock, PCCR, 0);
cbsz = (t->flags & MAP_16BIT) ? 0 : PCMOD_CBSZ;
pcc_set(sock, PCMOD, PCMOD_AS_IO | cbsz | need_ex);
pcc_set(sock, PCADR, addr & 0x1ff00000);
pcc_set(sock, PCCR, 1);
#ifdef CHAOS_PCC_DEBUG
#if 0
map_changed = (t->current_space == as_attr && size == 2);
#else
map_changed = 1;
#endif
#endif
t->current_space = as_io;
}
if (size == 1) {
unsigned char *bp = (unsigned char *)buf;
#ifdef CHAOS_DEBUG
if (map_changed) {
dummy_readbuf = readb(addr);
}
#endif
if (wr) {
while (nmemb--) {
writeb(*bp++, addr);
}
} else {
while (nmemb--) {
*bp++ = readb(addr);
}
}
} else {
unsigned short *bp = (unsigned short *)buf;
#ifdef CHAOS_PCC_DEBUG
if (map_changed) {
dummy_readbuf = readw(addr);
}
#endif
if (wr) {
while (nmemb--) {
#ifdef PCC_DEBUG_DBEX
if (_dbex) {
unsigned char *cp = (unsigned char *)bp;
unsigned short tmp;
tmp = cp[1] << 8 | cp[0];
writew(tmp, addr);
bp++;
} else
#endif
writew(*bp++, addr);
}
} else {
while (nmemb--) {
#ifdef PCC_DEBUG_DBEX
if (_dbex) {
unsigned char *cp = (unsigned char *)bp;
unsigned short tmp;
tmp = readw(addr);
cp[0] = tmp & 0xff;
cp[1] = (tmp >> 8) & 0xff;
bp++;
} else
#endif
*bp++ = readw(addr);
}
}
}
#if 1
if ((addr = pcc_get(sock, PCIRC)) & PCIRC_BWERR) {
printk("m32r_pcc: BWERR detected : port 0x%04lx : iosize %dbit\n",
port, size * 8);
pcc_set(sock, PCIRC, addr);
}
#endif
t->last_iosize = size;
t->last_iodbex = need_ex;
spin_unlock_irqrestore(&pcc_lock,flags);
return;
}
void pcc_ioread(int sock, unsigned long port, void *buf, size_t size, size_t nmemb, int flag) {
pcc_iorw(sock, port, buf, size, nmemb, 0, flag);
}
void pcc_iowrite(int sock, unsigned long port, void *buf, size_t size, size_t nmemb, int flag) {
pcc_iorw(sock, port, buf, size, nmemb, 1, flag);
}
static unsigned int pcc_get(u_short sock, unsigned int reg)
{
return inl(socket[sock].base + reg);
}
static void pcc_set(u_short sock, unsigned int reg, unsigned int data)
{
outl(data, socket[sock].base + reg);
}
static int __init is_alive(u_short sock)
{
unsigned int stat;
unsigned int f;
stat = pcc_get(sock, PCIRC);
f = (stat & (PCIRC_CDIN1 | PCIRC_CDIN2)) >> 16;
if(!f){
printk("m32r_pcc: No Card is detected at socket %d : stat = 0x%08x\n",stat,sock);
return 0;
}
if(f!=3)
printk("m32r_pcc: Insertion fail (%.8x) at socket %d\n",stat,sock);
else
printk("m32r_pcc: Card is Inserted at socket %d(%.8x)\n",sock,stat);
return 0;
}
static void add_pcc_socket(ulong base, int irq, ulong mapaddr,
unsigned int ioaddr)
{
pcc_socket_t *t = &socket[pcc_sockets];
t->ioaddr = ioaddr;
t->mapaddr = mapaddr;
t->base = base;
#ifdef CHAOS_PCC_DEBUG
t->flags = MAP_16BIT;
#else
t->flags = 0;
#endif
if (is_alive(pcc_sockets))
t->flags |= IS_ALIVE;
if (t->base > 0) {
request_region(t->base, 0x20, "m32r-pcc");
}
printk(KERN_INFO " %s ", pcc[pcc_sockets].name);
printk("pcc at 0x%08lx\n", t->base);
t->socket.features |= (SS_CAP_PCCARD | SS_CAP_STATIC_MAP);
t->socket.map_size = M32R_PCC_MAPSIZE;
t->socket.io_offset = ioaddr;
t->socket.irq_mask = 0;
t->socket.pci_irq = 2 + pcc_sockets;
request_irq(irq, pcc_interrupt, 0, "m32r-pcc", pcc_interrupt);
pcc_sockets++;
return;
}
static irqreturn_t pcc_interrupt(int irq, void *dev)
{
int i, j, irc;
u_int events, active;
int handled = 0;
pr_debug("m32r_pcc: pcc_interrupt(%d)\n", irq);
for (j = 0; j < 20; j++) {
active = 0;
for (i = 0; i < pcc_sockets; i++) {
if ((socket[i].cs_irq != irq) &&
(socket[i].socket.pci_irq != irq))
continue;
handled = 1;
irc = pcc_get(i, PCIRC);
irc >>=16;
pr_debug("m32r_pcc: interrupt: socket %d pcirc 0x%02x ",
i, irc);
if (!irc)
continue;
events = (irc) ? SS_DETECT : 0;
events |= (pcc_get(i,PCCR) & PCCR_PCEN) ? SS_READY : 0;
pr_debug("m32r_pcc: event 0x%02x\n", events);
if (events)
pcmcia_parse_events(&socket[i].socket, events);
active |= events;
active = 0;
}
if (!active) break;
}
if (j == 20)
printk(KERN_NOTICE "m32r-pcc: infinite loop in interrupt handler\n");
pr_debug("m32r_pcc: interrupt done\n");
return IRQ_RETVAL(handled);
}
static void pcc_interrupt_wrapper(u_long data)
{
pcc_interrupt(0, NULL);
init_timer(&poll_timer);
poll_timer.expires = jiffies + poll_interval;
add_timer(&poll_timer);
}
static int _pcc_get_status(u_short sock, u_int *value)
{
u_int status;
status = pcc_get(sock,PCIRC);
*value = ((status & PCIRC_CDIN1) && (status & PCIRC_CDIN2))
? SS_DETECT : 0;
status = pcc_get(sock,PCCR);
#if 0
*value |= (status & PCCR_PCEN) ? SS_READY : 0;
#else
*value |= SS_READY;
#endif
status = pcc_get(sock,PCCSIGCR);
*value |= (status & PCCSIGCR_VEN) ? SS_POWERON : 0;
pr_debug("m32r_pcc: GetStatus(%d) = %#4.4x\n", sock, *value);
return 0;
}
static int _pcc_set_socket(u_short sock, socket_state_t *state)
{
u_long reg = 0;
pr_debug("m32r_pcc: SetSocket(%d, flags %#3.3x, Vcc %d, Vpp %d, "
"io_irq %d, csc_mask %#2.2x)", sock, state->flags,
state->Vcc, state->Vpp, state->io_irq, state->csc_mask);
if (state->Vcc) {
if (state->Vcc == 50) {
reg |= PCCSIGCR_VEN;
} else {
return -EINVAL;
}
}
if (state->flags & SS_RESET) {
pr_debug("m32r_pcc: :RESET\n");
reg |= PCCSIGCR_CRST;
}
if (state->flags & SS_OUTPUT_ENA){
pr_debug("m32r_pcc: :OUTPUT_ENA\n");
} else {
reg |= PCCSIGCR_SEN;
}
pcc_set(sock,PCCSIGCR,reg);
if(state->flags & SS_IOCARD){
pr_debug("m32r_pcc: :IOCARD");
}
if (state->flags & SS_PWR_AUTO) {
pr_debug("m32r_pcc: :PWR_AUTO");
}
if (state->csc_mask & SS_DETECT)
pr_debug("m32r_pcc: :csc-SS_DETECT");
if (state->flags & SS_IOCARD) {
if (state->csc_mask & SS_STSCHG)
pr_debug("m32r_pcc: :STSCHG");
} else {
if (state->csc_mask & SS_BATDEAD)
pr_debug("m32r_pcc: :BATDEAD");
if (state->csc_mask & SS_BATWARN)
pr_debug("m32r_pcc: :BATWARN");
if (state->csc_mask & SS_READY)
pr_debug("m32r_pcc: :READY");
}
pr_debug("m32r_pcc: \n");
return 0;
}
static int _pcc_set_io_map(u_short sock, struct pccard_io_map *io)
{
u_char map;
pr_debug("m32r_pcc: SetIOMap(%d, %d, %#2.2x, %d ns, "
"%#llx-%#llx)\n", sock, io->map, io->flags,
io->speed, (unsigned long long)io->start,
(unsigned long long)io->stop);
map = io->map;
return 0;
}
static int _pcc_set_mem_map(u_short sock, struct pccard_mem_map *mem)
{
u_char map = mem->map;
u_long mode;
u_long addr;
pcc_socket_t *t = &socket[sock];
#ifdef CHAOS_PCC_DEBUG
#if 0
pcc_as_t last = t->current_space;
#endif
#endif
pr_debug("m32r_pcc: SetMemMap(%d, %d, %#2.2x, %d ns, "
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
pcc_set(sock, PCCR, 0);
if (mem->flags & MAP_ATTRIB) {
mode = PCMOD_AS_ATTRIB | PCMOD_CBSZ;
t->current_space = as_attr;
} else {
mode = 0;
t->current_space = as_comm;
}
pcc_set(sock, PCMOD, mode);
addr = t->mapaddr + (mem->card_start & M32R_PCC_MAPMASK);
pcc_set(sock, PCADR, addr);
mem->static_start = addr + mem->card_start;
pcc_set(sock, PCCR, 1);
#ifdef CHAOS_PCC_DEBUG
#if 0
if (last != as_attr) {
#else
if (1) {
#endif
dummy_readbuf = *(u_char *)(addr + KSEG1);
}
#endif
return 0;
}
static int pcc_get_status(struct pcmcia_socket *s, u_int *value)
{
unsigned int sock = container_of(s, struct pcc_socket, socket)->number;
if (socket[sock].flags & IS_ALIVE) {
*value = 0;
return -EINVAL;
}
LOCKED(_pcc_get_status(sock, value));
}
static int pcc_set_socket(struct pcmcia_socket *s, socket_state_t *state)
{
unsigned int sock = container_of(s, struct pcc_socket, socket)->number;
if (socket[sock].flags & IS_ALIVE)
return -EINVAL;
LOCKED(_pcc_set_socket(sock, state));
}
static int pcc_set_io_map(struct pcmcia_socket *s, struct pccard_io_map *io)
{
unsigned int sock = container_of(s, struct pcc_socket, socket)->number;
if (socket[sock].flags & IS_ALIVE)
return -EINVAL;
LOCKED(_pcc_set_io_map(sock, io));
}
static int pcc_set_mem_map(struct pcmcia_socket *s, struct pccard_mem_map *mem)
{
unsigned int sock = container_of(s, struct pcc_socket, socket)->number;
if (socket[sock].flags & IS_ALIVE)
return -EINVAL;
LOCKED(_pcc_set_mem_map(sock, mem));
}
static int pcc_init(struct pcmcia_socket *s)
{
pr_debug("m32r_pcc: init call\n");
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
printk(KERN_INFO "m32r PCC probe:\n");
pcc_sockets = 0;
add_pcc_socket(M32R_PCC0_BASE, PCC0_IRQ, M32R_PCC0_MAPBASE, 0x1000);
#ifdef CONFIG_M32RPCC_SLOT2
add_pcc_socket(M32R_PCC1_BASE, PCC1_IRQ, M32R_PCC1_MAPBASE, 0x2000);
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
#if 0
class_device_create_file(&socket[i].socket.dev,
&class_device_attr_info);
class_device_create_file(&socket[i].socket.dev,
&class_device_attr_exca);
#endif
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
