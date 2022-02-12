static u_char tcic_getb(u_char reg)
{
u_char val = inb(tcic_base+reg);
printk(KERN_DEBUG "tcic_getb(%#lx) = %#x\n", tcic_base+reg, val);
return val;
}
static u_short tcic_getw(u_char reg)
{
u_short val = inw(tcic_base+reg);
printk(KERN_DEBUG "tcic_getw(%#lx) = %#x\n", tcic_base+reg, val);
return val;
}
static void tcic_setb(u_char reg, u_char data)
{
printk(KERN_DEBUG "tcic_setb(%#lx, %#x)\n", tcic_base+reg, data);
outb(data, tcic_base+reg);
}
static void tcic_setw(u_char reg, u_short data)
{
printk(KERN_DEBUG "tcic_setw(%#lx, %#x)\n", tcic_base+reg, data);
outw(data, tcic_base+reg);
}
static void tcic_setl(u_char reg, u_int data)
{
#ifdef DEBUG_X
printk(KERN_DEBUG "tcic_setl(%#x, %#lx)\n", tcic_base+reg, data);
#endif
outw(data & 0xffff, tcic_base+reg);
outw(data >> 16, tcic_base+reg+2);
}
static void tcic_aux_setb(u_short reg, u_char data)
{
u_char mode = (tcic_getb(TCIC_MODE) & TCIC_MODE_PGMMASK) | reg;
tcic_setb(TCIC_MODE, mode);
tcic_setb(TCIC_AUX, data);
}
static u_short tcic_aux_getw(u_short reg)
{
u_char mode = (tcic_getb(TCIC_MODE) & TCIC_MODE_PGMMASK) | reg;
tcic_setb(TCIC_MODE, mode);
return tcic_getw(TCIC_AUX);
}
static void tcic_aux_setw(u_short reg, u_short data)
{
u_char mode = (tcic_getb(TCIC_MODE) & TCIC_MODE_PGMMASK) | reg;
tcic_setb(TCIC_MODE, mode);
tcic_setw(TCIC_AUX, data);
}
static int to_cycles(int ns)
{
if (ns < 14)
return 0;
else
return 2*(ns-14)/cycle_time;
}
static irqreturn_t __init tcic_irq_count(int irq, void *dev)
{
irq_hits++;
return IRQ_HANDLED;
}
static u_int __init try_irq(int irq)
{
u_short cfg;
irq_hits = 0;
if (request_irq(irq, tcic_irq_count, 0, "irq scan", tcic_irq_count) != 0)
return -1;
mdelay(10);
if (irq_hits) {
free_irq(irq, tcic_irq_count);
return -1;
}
cfg = TCIC_SYSCFG_AUTOBUSY | 0x0a00;
tcic_aux_setw(TCIC_AUX_SYSCFG, cfg | TCIC_IRQ(irq));
tcic_setb(TCIC_IENA, TCIC_IENA_ERR | TCIC_IENA_CFG_HIGH);
tcic_setb(TCIC_ICSR, TCIC_ICSR_ERR | TCIC_ICSR_JAM);
udelay(1000);
free_irq(irq, tcic_irq_count);
tcic_setb(TCIC_IENA, TCIC_IENA_CFG_OFF);
while (tcic_getb(TCIC_ICSR))
tcic_setb(TCIC_ICSR, TCIC_ICSR_JAM);
tcic_aux_setw(TCIC_AUX_SYSCFG, cfg);
return (irq_hits != 1);
}
static u_int __init irq_scan(u_int mask0)
{
u_int mask1;
int i;
#ifdef __alpha__
#define PIC 0x4d0
int level_mask = inb_p(PIC) | (inb_p(PIC+1) << 8);
if (level_mask)
mask0 &= ~level_mask;
#endif
mask1 = 0;
if (do_scan) {
for (i = 0; i < 16; i++)
if ((mask0 & (1 << i)) && (try_irq(i) == 0))
mask1 |= (1 << i);
for (i = 0; i < 16; i++)
if ((mask1 & (1 << i)) && (try_irq(i) != 0)) {
mask1 ^= (1 << i);
}
}
if (mask1) {
printk("scanned");
} else {
for (i = 0; i < 16; i++)
if ((mask0 & (1 << i)) &&
(request_irq(i, tcic_irq_count, 0, "x", tcic_irq_count) == 0)) {
mask1 |= (1 << i);
free_irq(i, tcic_irq_count);
}
printk("default");
}
printk(") = ");
for (i = 0; i < 16; i++)
if (mask1 & (1<<i))
printk("%s%d", ((mask1 & ((1<<i)-1)) ? "," : ""), i);
printk(" ");
return mask1;
}
static int __init is_active(int s)
{
u_short scf1, ioctl, base, num;
u_char pwr, sstat;
u_int addr;
tcic_setl(TCIC_ADDR, (s << TCIC_ADDR_SS_SHFT)
| TCIC_ADDR_INDREG | TCIC_SCF1(s));
scf1 = tcic_getw(TCIC_DATA);
pwr = tcic_getb(TCIC_PWR);
sstat = tcic_getb(TCIC_SSTAT);
addr = TCIC_IWIN(s, 0);
tcic_setw(TCIC_ADDR, addr + TCIC_IBASE_X);
base = tcic_getw(TCIC_DATA);
tcic_setw(TCIC_ADDR, addr + TCIC_ICTL_X);
ioctl = tcic_getw(TCIC_DATA);
if (ioctl & TCIC_ICTL_TINY)
num = 1;
else {
num = (base ^ (base-1));
base = base & (base-1);
}
if ((sstat & TCIC_SSTAT_CD) && (pwr & TCIC_PWR_VCC(s)) &&
(scf1 & TCIC_SCF1_IOSTS) && (ioctl & TCIC_ICTL_ENA) &&
((base & 0xfeef) != 0x02e8)) {
struct resource *res = request_region(base, num, "tcic-2");
if (!res)
return 1;
release_region(base, num);
}
return 0;
}
static int __init get_tcic_id(void)
{
u_short id;
tcic_aux_setw(TCIC_AUX_TEST, TCIC_TEST_DIAG);
id = tcic_aux_getw(TCIC_AUX_ILOCK);
id = (id & TCIC_ILOCKTEST_ID_MASK) >> TCIC_ILOCKTEST_ID_SH;
tcic_aux_setw(TCIC_AUX_TEST, 0);
return id;
}
static int __init init_tcic(void)
{
int i, sock, ret = 0;
u_int mask, scan;
if (platform_driver_register(&tcic_driver))
return -1;
printk(KERN_INFO "Databook TCIC-2 PCMCIA probe: ");
sock = 0;
if (!request_region(tcic_base, 16, "tcic-2")) {
printk("could not allocate ports,\n ");
platform_driver_unregister(&tcic_driver);
return -ENODEV;
}
else {
tcic_setw(TCIC_ADDR, 0);
if (tcic_getw(TCIC_ADDR) == 0) {
tcic_setw(TCIC_ADDR, 0xc3a5);
if (tcic_getw(TCIC_ADDR) == 0xc3a5) sock = 2;
}
if (sock == 0) {
tcic_setb(TCIC_SCTRL, TCIC_SCTRL_RESET);
tcic_setb(TCIC_SCTRL, 0);
tcic_setw(TCIC_ADDR, 0);
if (tcic_getw(TCIC_ADDR) == 0) {
tcic_setw(TCIC_ADDR, 0xc3a5);
if (tcic_getw(TCIC_ADDR) == 0xc3a5) sock = 2;
}
}
}
if (sock == 0) {
printk("not found.\n");
release_region(tcic_base, 16);
platform_driver_unregister(&tcic_driver);
return -ENODEV;
}
sockets = 0;
for (i = 0; i < sock; i++) {
if ((i == ignore) || is_active(i)) continue;
socket_table[sockets].psock = i;
socket_table[sockets].id = get_tcic_id();
socket_table[sockets].socket.owner = THIS_MODULE;
socket_table[sockets].socket.features = SS_CAP_PCCARD | SS_CAP_MEM_ALIGN;
socket_table[sockets].socket.irq_mask = 0x4cf8;
socket_table[sockets].socket.map_size = 0x1000;
sockets++;
}
switch (socket_table[0].id) {
case TCIC_ID_DB86082:
printk("DB86082"); break;
case TCIC_ID_DB86082A:
printk("DB86082A"); break;
case TCIC_ID_DB86084:
printk("DB86084"); break;
case TCIC_ID_DB86084A:
printk("DB86084A"); break;
case TCIC_ID_DB86072:
printk("DB86072"); break;
case TCIC_ID_DB86184:
printk("DB86184"); break;
case TCIC_ID_DB86082B:
printk("DB86082B"); break;
default:
printk("Unknown ID 0x%02x", socket_table[0].id);
}
poll_timer.function = &tcic_timer;
poll_timer.data = 0;
init_timer(&poll_timer);
printk(KERN_CONT ", %d sockets\n", sockets);
printk(KERN_INFO " irq list (");
if (irq_list_count == 0)
mask = irq_mask;
else
for (i = mask = 0; i < irq_list_count; i++)
mask |= (1<<irq_list[i]);
mask &= 0x4cf8;
mask = irq_scan(mask);
for (i=0;i<sockets;i++)
socket_table[i].socket.irq_mask = mask;
scan = (mask & (mask-1));
if (((scan & (scan-1)) == 0) && (poll_interval == 0))
poll_interval = HZ;
if (poll_interval == 0) {
u_int cs_mask = mask & ((cs_irq) ? (1<<cs_irq) : ~(1<<12));
for (i = 15; i > 0; i--)
if ((cs_mask & (1 << i)) &&
(request_irq(i, tcic_interrupt, 0, "tcic",
tcic_interrupt) == 0))
break;
cs_irq = i;
if (cs_irq == 0) poll_interval = HZ;
}
if (socket_table[0].socket.irq_mask & (1 << 11))
printk("sktirq is irq 11, ");
if (cs_irq != 0)
printk("status change on irq %d\n", cs_irq);
else
printk("polled status, interval = %d ms\n",
poll_interval * 1000 / HZ);
for (i = 0; i < sockets; i++) {
tcic_setw(TCIC_ADDR+2, socket_table[i].psock << TCIC_SS_SHFT);
socket_table[i].last_sstat = tcic_getb(TCIC_SSTAT);
}
tcic_interrupt(0, NULL);
platform_device_register(&tcic_device);
for (i = 0; i < sockets; i++) {
socket_table[i].socket.ops = &tcic_operations;
socket_table[i].socket.resource_ops = &pccard_nonstatic_ops;
socket_table[i].socket.dev.parent = &tcic_device.dev;
ret = pcmcia_register_socket(&socket_table[i].socket);
if (ret && i)
pcmcia_unregister_socket(&socket_table[0].socket);
}
return ret;
return 0;
}
static void __exit exit_tcic(void)
{
int i;
del_timer_sync(&poll_timer);
if (cs_irq != 0) {
tcic_aux_setw(TCIC_AUX_SYSCFG, TCIC_SYSCFG_AUTOBUSY|0x0a00);
free_irq(cs_irq, tcic_interrupt);
}
release_region(tcic_base, 16);
for (i = 0; i < sockets; i++) {
pcmcia_unregister_socket(&socket_table[i].socket);
}
platform_device_unregister(&tcic_device);
platform_driver_unregister(&tcic_driver);
}
static irqreturn_t tcic_interrupt(int irq, void *dev)
{
int i, quick = 0;
u_char latch, sstat;
u_short psock;
u_int events;
static volatile int active = 0;
if (active) {
printk(KERN_NOTICE "tcic: reentered interrupt handler!\n");
return IRQ_NONE;
} else
active = 1;
pr_debug("tcic_interrupt()\n");
for (i = 0; i < sockets; i++) {
psock = socket_table[i].psock;
tcic_setl(TCIC_ADDR, (psock << TCIC_ADDR_SS_SHFT)
| TCIC_ADDR_INDREG | TCIC_SCF1(psock));
sstat = tcic_getb(TCIC_SSTAT);
latch = sstat ^ socket_table[psock].last_sstat;
socket_table[i].last_sstat = sstat;
if (tcic_getb(TCIC_ICSR) & TCIC_ICSR_CDCHG) {
tcic_setb(TCIC_ICSR, TCIC_ICSR_CLEAR);
quick = 1;
}
if (latch == 0)
continue;
events = (latch & TCIC_SSTAT_CD) ? SS_DETECT : 0;
events |= (latch & TCIC_SSTAT_WP) ? SS_WRPROT : 0;
if (tcic_getw(TCIC_DATA) & TCIC_SCF1_IOSTS) {
events |= (latch & TCIC_SSTAT_LBAT1) ? SS_STSCHG : 0;
} else {
events |= (latch & TCIC_SSTAT_RDY) ? SS_READY : 0;
events |= (latch & TCIC_SSTAT_LBAT1) ? SS_BATDEAD : 0;
events |= (latch & TCIC_SSTAT_LBAT2) ? SS_BATWARN : 0;
}
if (events) {
pcmcia_parse_events(&socket_table[i].socket, events);
}
}
if (((cs_irq == 0) || quick) && (!tcic_timer_pending)) {
poll_timer.expires = jiffies + (quick ? poll_quick : poll_interval);
add_timer(&poll_timer);
tcic_timer_pending = 1;
}
active = 0;
pr_debug("interrupt done\n");
return IRQ_HANDLED;
}
static void tcic_timer(u_long data)
{
pr_debug("tcic_timer()\n");
tcic_timer_pending = 0;
tcic_interrupt(0, NULL);
}
static int tcic_get_status(struct pcmcia_socket *sock, u_int *value)
{
u_short psock = container_of(sock, struct tcic_socket, socket)->psock;
u_char reg;
tcic_setl(TCIC_ADDR, (psock << TCIC_ADDR_SS_SHFT)
| TCIC_ADDR_INDREG | TCIC_SCF1(psock));
reg = tcic_getb(TCIC_SSTAT);
*value = (reg & TCIC_SSTAT_CD) ? SS_DETECT : 0;
*value |= (reg & TCIC_SSTAT_WP) ? SS_WRPROT : 0;
if (tcic_getw(TCIC_DATA) & TCIC_SCF1_IOSTS) {
*value |= (reg & TCIC_SSTAT_LBAT1) ? SS_STSCHG : 0;
} else {
*value |= (reg & TCIC_SSTAT_RDY) ? SS_READY : 0;
*value |= (reg & TCIC_SSTAT_LBAT1) ? SS_BATDEAD : 0;
*value |= (reg & TCIC_SSTAT_LBAT2) ? SS_BATWARN : 0;
}
reg = tcic_getb(TCIC_PWR);
if (reg & (TCIC_PWR_VCC(psock)|TCIC_PWR_VPP(psock)))
*value |= SS_POWERON;
dev_dbg(&sock->dev, "GetStatus(%d) = %#2.2x\n", psock, *value);
return 0;
}
static int tcic_set_socket(struct pcmcia_socket *sock, socket_state_t *state)
{
u_short psock = container_of(sock, struct tcic_socket, socket)->psock;
u_char reg;
u_short scf1, scf2;
dev_dbg(&sock->dev, "SetSocket(%d, flags %#3.3x, Vcc %d, Vpp %d, "
"io_irq %d, csc_mask %#2.2x)\n", psock, state->flags,
state->Vcc, state->Vpp, state->io_irq, state->csc_mask);
tcic_setw(TCIC_ADDR+2, (psock << TCIC_SS_SHFT) | TCIC_ADR2_INDREG);
reg = tcic_getb(TCIC_PWR);
reg &= ~(TCIC_PWR_VCC(psock) | TCIC_PWR_VPP(psock));
if (state->Vcc == 50) {
switch (state->Vpp) {
case 0: reg |= TCIC_PWR_VCC(psock) | TCIC_PWR_VPP(psock); break;
case 50: reg |= TCIC_PWR_VCC(psock); break;
case 120: reg |= TCIC_PWR_VPP(psock); break;
default: return -EINVAL;
}
} else if (state->Vcc != 0)
return -EINVAL;
if (reg != tcic_getb(TCIC_PWR))
tcic_setb(TCIC_PWR, reg);
reg = TCIC_ILOCK_HOLD_CCLK | TCIC_ILOCK_CWAIT;
if (state->flags & SS_OUTPUT_ENA) {
tcic_setb(TCIC_SCTRL, TCIC_SCTRL_ENA);
reg |= TCIC_ILOCK_CRESENA;
} else
tcic_setb(TCIC_SCTRL, 0);
if (state->flags & SS_RESET)
reg |= TCIC_ILOCK_CRESET;
tcic_aux_setb(TCIC_AUX_ILOCK, reg);
tcic_setw(TCIC_ADDR, TCIC_SCF1(psock));
scf1 = TCIC_SCF1_FINPACK;
scf1 |= TCIC_IRQ(state->io_irq);
if (state->flags & SS_IOCARD) {
scf1 |= TCIC_SCF1_IOSTS;
if (state->flags & SS_SPKR_ENA)
scf1 |= TCIC_SCF1_SPKR;
if (state->flags & SS_DMA_MODE)
scf1 |= TCIC_SCF1_DREQ2 << TCIC_SCF1_DMA_SHIFT;
}
tcic_setw(TCIC_DATA, scf1);
reg = TCIC_WAIT_ASYNC | TCIC_WAIT_SENSE | to_cycles(250);
tcic_aux_setb(TCIC_AUX_WCTL, reg);
tcic_aux_setw(TCIC_AUX_SYSCFG, TCIC_SYSCFG_AUTOBUSY|0x0a00|
TCIC_IRQ(cs_irq));
tcic_setw(TCIC_ADDR, TCIC_SCF2(psock));
scf2 = TCIC_SCF2_MALL;
if (state->csc_mask & SS_DETECT) scf2 &= ~TCIC_SCF2_MCD;
if (state->flags & SS_IOCARD) {
if (state->csc_mask & SS_STSCHG) reg &= ~TCIC_SCF2_MLBAT1;
} else {
if (state->csc_mask & SS_BATDEAD) reg &= ~TCIC_SCF2_MLBAT1;
if (state->csc_mask & SS_BATWARN) reg &= ~TCIC_SCF2_MLBAT2;
if (state->csc_mask & SS_READY) reg &= ~TCIC_SCF2_MRDY;
}
tcic_setw(TCIC_DATA, scf2);
tcic_setb(TCIC_IENA, TCIC_IENA_CDCHG | TCIC_IENA_CFG_HIGH);
return 0;
}
static int tcic_set_io_map(struct pcmcia_socket *sock, struct pccard_io_map *io)
{
u_short psock = container_of(sock, struct tcic_socket, socket)->psock;
u_int addr;
u_short base, len, ioctl;
dev_dbg(&sock->dev, "SetIOMap(%d, %d, %#2.2x, %d ns, "
"%#llx-%#llx)\n", psock, io->map, io->flags, io->speed,
(unsigned long long)io->start, (unsigned long long)io->stop);
if ((io->map > 1) || (io->start > 0xffff) || (io->stop > 0xffff) ||
(io->stop < io->start)) return -EINVAL;
tcic_setw(TCIC_ADDR+2, TCIC_ADR2_INDREG | (psock << TCIC_SS_SHFT));
addr = TCIC_IWIN(psock, io->map);
base = io->start; len = io->stop - io->start;
if ((len & (len+1)) || (base & len)) return -EINVAL;
base |= (len+1)>>1;
tcic_setw(TCIC_ADDR, addr + TCIC_IBASE_X);
tcic_setw(TCIC_DATA, base);
ioctl = (psock << TCIC_ICTL_SS_SHFT);
ioctl |= (len == 0) ? TCIC_ICTL_TINY : 0;
ioctl |= (io->flags & MAP_ACTIVE) ? TCIC_ICTL_ENA : 0;
ioctl |= to_cycles(io->speed) & TCIC_ICTL_WSCNT_MASK;
if (!(io->flags & MAP_AUTOSZ)) {
ioctl |= TCIC_ICTL_QUIET;
ioctl |= (io->flags & MAP_16BIT) ? TCIC_ICTL_BW_16 : TCIC_ICTL_BW_8;
}
tcic_setw(TCIC_ADDR, addr + TCIC_ICTL_X);
tcic_setw(TCIC_DATA, ioctl);
return 0;
}
static int tcic_set_mem_map(struct pcmcia_socket *sock, struct pccard_mem_map *mem)
{
u_short psock = container_of(sock, struct tcic_socket, socket)->psock;
u_short addr, ctl;
u_long base, len, mmap;
dev_dbg(&sock->dev, "SetMemMap(%d, %d, %#2.2x, %d ns, "
"%#llx-%#llx, %#x)\n", psock, mem->map, mem->flags,
mem->speed, (unsigned long long)mem->res->start,
(unsigned long long)mem->res->end, mem->card_start);
if ((mem->map > 3) || (mem->card_start > 0x3ffffff) ||
(mem->res->start > 0xffffff) || (mem->res->end > 0xffffff) ||
(mem->res->start > mem->res->end) || (mem->speed > 1000))
return -EINVAL;
tcic_setw(TCIC_ADDR+2, TCIC_ADR2_INDREG | (psock << TCIC_SS_SHFT));
addr = TCIC_MWIN(psock, mem->map);
base = mem->res->start; len = mem->res->end - mem->res->start;
if ((len & (len+1)) || (base & len)) return -EINVAL;
if (len == 0x0fff)
base = (base >> TCIC_MBASE_HA_SHFT) | TCIC_MBASE_4K_BIT;
else
base = (base | (len+1)>>1) >> TCIC_MBASE_HA_SHFT;
tcic_setw(TCIC_ADDR, addr + TCIC_MBASE_X);
tcic_setw(TCIC_DATA, base);
mmap = mem->card_start - mem->res->start;
mmap = (mmap >> TCIC_MMAP_CA_SHFT) & TCIC_MMAP_CA_MASK;
if (mem->flags & MAP_ATTRIB) mmap |= TCIC_MMAP_REG;
tcic_setw(TCIC_ADDR, addr + TCIC_MMAP_X);
tcic_setw(TCIC_DATA, mmap);
ctl = TCIC_MCTL_QUIET | (psock << TCIC_MCTL_SS_SHFT);
ctl |= to_cycles(mem->speed) & TCIC_MCTL_WSCNT_MASK;
ctl |= (mem->flags & MAP_16BIT) ? 0 : TCIC_MCTL_B8;
ctl |= (mem->flags & MAP_WRPROT) ? TCIC_MCTL_WP : 0;
ctl |= (mem->flags & MAP_ACTIVE) ? TCIC_MCTL_ENA : 0;
tcic_setw(TCIC_ADDR, addr + TCIC_MCTL_X);
tcic_setw(TCIC_DATA, ctl);
return 0;
}
static int tcic_init(struct pcmcia_socket *s)
{
int i;
struct resource res = { .start = 0, .end = 0x1000 };
pccard_io_map io = { 0, 0, 0, 0, 1 };
pccard_mem_map mem = { .res = &res, };
for (i = 0; i < 2; i++) {
io.map = i;
tcic_set_io_map(s, &io);
}
for (i = 0; i < 5; i++) {
mem.map = i;
tcic_set_mem_map(s, &mem);
}
return 0;
}
