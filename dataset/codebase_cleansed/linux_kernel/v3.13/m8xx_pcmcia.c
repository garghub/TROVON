static int voltage_set(int slot, int vcc, int vpp)
{
u32 reg = 0;
switch (vcc) {
case 0:
break;
case 33:
reg |= BCSR1_PCCVCC0;
break;
case 50:
reg |= BCSR1_PCCVCC1;
break;
default:
return 1;
}
switch (vpp) {
case 0:
break;
case 33:
case 50:
if (vcc == vpp)
reg |= BCSR1_PCCVPP1;
else
return 1;
break;
case 120:
if ((vcc == 33) || (vcc == 50))
reg |= BCSR1_PCCVPP0;
else
return 1;
default:
return 1;
}
out_be32((u32 *) BCSR1,
in_be32((u32 *) BCSR1) & ~(BCSR1_PCCVCC_MASK |
BCSR1_PCCVPP_MASK));
out_be32((u32 *) BCSR1, in_be32((u32 *) BCSR1) | reg);
return 0;
}
static void hardware_enable(int slot)
{
out_be32((u32 *) BCSR1, in_be32((u32 *) BCSR1) & ~BCSR1_PCCEN);
}
static void hardware_disable(int slot)
{
out_be32((u32 *) BCSR1, in_be32((u32 *) BCSR1) | BCSR1_PCCEN);
}
static inline void hardware_enable(int slot)
{
m8xx_pcmcia_ops.hw_ctrl(slot, 1);
}
static inline void hardware_disable(int slot)
{
m8xx_pcmcia_ops.hw_ctrl(slot, 0);
}
static inline int voltage_set(int slot, int vcc, int vpp)
{
return m8xx_pcmcia_ops.voltage_set(slot, vcc, vpp);
}
static int voltage_set(int slot, int vcc, int vpp)
{
u8 reg = 0;
u8 regread;
cpld_regs *ccpld = get_cpld();
switch (vcc) {
case 0:
break;
case 33:
reg |= PCMCIA_VCC_33;
break;
case 50:
reg |= PCMCIA_VCC_50;
break;
default:
return 1;
}
switch (vpp) {
case 0:
break;
case 33:
case 50:
if (vcc == vpp)
reg |= PCMCIA_VPP_VCC;
else
return 1;
break;
case 120:
if ((vcc == 33) || (vcc == 50))
reg |= PCMCIA_VPP_12;
else
return 1;
default:
return 1;
}
reg = reg >> (slot << 2);
regread = in_8(&ccpld->fpga_pc_ctl);
if (reg !=
(regread & ((PCMCIA_VCC_MASK | PCMCIA_VPP_MASK) >> (slot << 2)))) {
regread =
regread & ~((PCMCIA_VCC_MASK | PCMCIA_VPP_MASK) >>
(slot << 2));
out_8(&ccpld->fpga_pc_ctl, reg | regread);
msleep(100);
}
return 0;
}
static irqreturn_t m8xx_interrupt(int irq, void *dev)
{
struct socket_info *s;
struct event_table *e;
unsigned int i, events, pscr, pipr, per;
pcmconf8xx_t *pcmcia = socket[0].pcmcia;
pr_debug("m8xx_pcmcia: Interrupt!\n");
pscr = in_be32(&pcmcia->pcmc_pscr);
pipr = in_be32(&pcmcia->pcmc_pipr);
per = in_be32(&pcmcia->pcmc_per);
for (i = 0; i < PCMCIA_SOCKETS_NO; i++) {
s = &socket[i];
e = &s->events[0];
events = 0;
while (e->regbit) {
if (pscr & e->regbit)
events |= e->eventbit;
e++;
}
if (events & SS_DETECT)
if (((pipr & M8XX_PCMCIA_CD2(i)) >> 1) ^
(pipr & M8XX_PCMCIA_CD1(i))) {
events &= ~SS_DETECT;
}
#ifdef PCMCIA_GLITCHY_CD
if ((events & SS_DETECT) &&
((pipr &
(M8XX_PCMCIA_CD2(i) | M8XX_PCMCIA_CD1(i))) == 0) &&
(s->state.Vcc | s->state.Vpp)) {
events &= ~SS_DETECT;
}
#endif
pr_debug("m8xx_pcmcia: slot %u: events = 0x%02x, pscr = 0x%08x, "
"pipr = 0x%08x\n", i, events, pscr, pipr);
if (events) {
spin_lock(&pending_event_lock);
pending_events[i] |= events;
spin_unlock(&pending_event_lock);
per &= ~M8XX_PCMCIA_RDY_L(0);
per &= ~M8XX_PCMCIA_RDY_L(1);
out_be32(&pcmcia->pcmc_per, per);
if (events)
pcmcia_parse_events(&socket[i].socket, events);
}
}
out_be32(&pcmcia->pcmc_pscr, pscr);
pr_debug("m8xx_pcmcia: Interrupt done.\n");
return IRQ_HANDLED;
}
static u32 m8xx_get_graycode(u32 size)
{
u32 k;
for (k = 0; k < M8XX_SIZES_NO; k++)
if (m8xx_size_to_gray[k] == size)
break;
if ((k == M8XX_SIZES_NO) || (m8xx_size_to_gray[k] == -1))
k = -1;
return k;
}
static u32 m8xx_get_speed(u32 ns, u32 is_io, u32 bus_freq)
{
u32 reg, clocks, psst, psl, psht;
if (!ns) {
if (is_io)
ns = 255;
else
ns = 100;
}
#define ADJ 180
clocks = ((bus_freq / 1000) * ns) / 1000;
clocks = (clocks * ADJ) / (100 * 1000);
if (clocks >= PCMCIA_BMT_LIMIT) {
printk("Max access time limit reached\n");
clocks = PCMCIA_BMT_LIMIT - 1;
}
psst = clocks / 7;
psht = clocks / 7;
psl = (clocks * 5) / 7;
psst += clocks - (psst + psht + psl);
reg = psst << 12;
reg |= psl << 7;
reg |= psht << 16;
return reg;
}
static int m8xx_get_status(struct pcmcia_socket *sock, unsigned int *value)
{
int lsock = container_of(sock, struct socket_info, socket)->slot;
struct socket_info *s = &socket[lsock];
unsigned int pipr, reg;
pcmconf8xx_t *pcmcia = s->pcmcia;
pipr = in_be32(&pcmcia->pcmc_pipr);
*value = ((pipr & (M8XX_PCMCIA_CD1(lsock)
| M8XX_PCMCIA_CD2(lsock))) == 0) ? SS_DETECT : 0;
*value |= (pipr & M8XX_PCMCIA_WP(lsock)) ? SS_WRPROT : 0;
if (s->state.flags & SS_IOCARD)
*value |= (pipr & M8XX_PCMCIA_BVD1(lsock)) ? SS_STSCHG : 0;
else {
*value |= (pipr & M8XX_PCMCIA_RDY(lsock)) ? SS_READY : 0;
*value |= (pipr & M8XX_PCMCIA_BVD1(lsock)) ? SS_BATDEAD : 0;
*value |= (pipr & M8XX_PCMCIA_BVD2(lsock)) ? SS_BATWARN : 0;
}
if (s->state.Vcc | s->state.Vpp)
*value |= SS_POWERON;
reg = (pipr & M8XX_PCMCIA_VS_MASK(lsock))
>> M8XX_PCMCIA_VS_SHIFT(lsock);
if (socket_get(lsock) == PCMCIA_SOCKET_KEY_LV) {
switch (reg) {
case 1:
*value |= SS_3VCARD;
break;
case 2:
*value |= SS_XVCARD;
break;
};
}
pr_debug("m8xx_pcmcia: GetStatus(%d) = %#2.2x\n", lsock, *value);
return 0;
}
static int m8xx_set_socket(struct pcmcia_socket *sock, socket_state_t * state)
{
int lsock = container_of(sock, struct socket_info, socket)->slot;
struct socket_info *s = &socket[lsock];
struct event_table *e;
unsigned int reg;
unsigned long flags;
pcmconf8xx_t *pcmcia = socket[0].pcmcia;
pr_debug("m8xx_pcmcia: SetSocket(%d, flags %#3.3x, Vcc %d, Vpp %d, "
"io_irq %d, csc_mask %#2.2x)\n", lsock, state->flags,
state->Vcc, state->Vpp, state->io_irq, state->csc_mask);
if (voltage_set(lsock, state->Vcc, state->Vpp))
return -EINVAL;
if (state->flags & SS_RESET)
out_be32(M8XX_PGCRX(lsock), in_be32(M8XX_PGCRX(lsock)) | M8XX_PGCRX_CXRESET);
else
out_be32(M8XX_PGCRX(lsock),
in_be32(M8XX_PGCRX(lsock)) & ~M8XX_PGCRX_CXRESET);
if (state->Vcc || state->Vpp)
out_be32(M8XX_PGCRX(lsock), in_be32(M8XX_PGCRX(lsock)) & ~M8XX_PGCRX_CXOE);
else
out_be32(M8XX_PGCRX(lsock),
in_be32(M8XX_PGCRX(lsock)) | M8XX_PGCRX_CXOE);
spin_lock_irqsave(&events_lock, flags);
e = &s->events[0];
reg = 0;
if (state->csc_mask & SS_DETECT) {
e->eventbit = SS_DETECT;
reg |= e->regbit = (M8XX_PCMCIA_CD2(lsock)
| M8XX_PCMCIA_CD1(lsock));
e++;
}
if (state->flags & SS_IOCARD) {
if (state->csc_mask & SS_STSCHG) {
e->eventbit = SS_STSCHG;
reg |= e->regbit = M8XX_PCMCIA_BVD1(lsock);
e++;
}
if (state->io_irq) {
out_be32(M8XX_PGCRX(lsock),
in_be32(M8XX_PGCRX(lsock)) |
mk_int_int_mask(s->hwirq) << 24);
reg |= M8XX_PCMCIA_RDY_L(lsock);
} else
out_be32(M8XX_PGCRX(lsock),
in_be32(M8XX_PGCRX(lsock)) & 0x00ffffff);
} else {
if (state->csc_mask & SS_BATDEAD) {
e->eventbit = SS_BATDEAD;
reg |= e->regbit = M8XX_PCMCIA_BVD1(lsock);
e++;
}
if (state->csc_mask & SS_BATWARN) {
e->eventbit = SS_BATWARN;
reg |= e->regbit = M8XX_PCMCIA_BVD2(lsock);
e++;
}
if (state->csc_mask & SS_READY) {
e->eventbit = SS_READY;
reg |= e->regbit = 0;
e++;
}
}
e->regbit = 0;
out_be32(&pcmcia->pcmc_pscr, reg);
reg |=
in_be32(&pcmcia->
pcmc_per) & (M8XX_PCMCIA_MASK(0) | M8XX_PCMCIA_MASK(1));
out_be32(&pcmcia->pcmc_per, reg);
spin_unlock_irqrestore(&events_lock, flags);
s->state = *state;
return 0;
}
static int m8xx_set_io_map(struct pcmcia_socket *sock, struct pccard_io_map *io)
{
int lsock = container_of(sock, struct socket_info, socket)->slot;
struct socket_info *s = &socket[lsock];
struct pcmcia_win *w;
unsigned int reg, winnr;
pcmconf8xx_t *pcmcia = s->pcmcia;
#define M8XX_SIZE (io->stop - io->start + 1)
#define M8XX_BASE (PCMCIA_IO_WIN_BASE + io->start)
pr_debug("m8xx_pcmcia: SetIOMap(%d, %d, %#2.2x, %d ns, "
"%#4.4llx-%#4.4llx)\n", lsock, io->map, io->flags,
io->speed, (unsigned long long)io->start,
(unsigned long long)io->stop);
if ((io->map >= PCMCIA_IO_WIN_NO) || (io->start > 0xffff)
|| (io->stop > 0xffff) || (io->stop < io->start))
return -EINVAL;
if ((reg = m8xx_get_graycode(M8XX_SIZE)) == -1)
return -EINVAL;
if (io->flags & MAP_ACTIVE) {
pr_debug("m8xx_pcmcia: io->flags & MAP_ACTIVE\n");
winnr = (PCMCIA_MEM_WIN_NO * PCMCIA_SOCKETS_NO)
+ (lsock * PCMCIA_IO_WIN_NO) + io->map;
w = (void *)&pcmcia->pcmc_pbr0;
w += winnr;
out_be32(&w->or, 0);
out_be32(&w->br, M8XX_BASE);
reg <<= 27;
reg |= M8XX_PCMCIA_POR_IO | (lsock << 2);
reg |= m8xx_get_speed(io->speed, 1, s->bus_freq);
if (io->flags & MAP_WRPROT)
reg |= M8XX_PCMCIA_POR_WRPROT;
if (io->flags & MAP_16BIT)
reg |= M8XX_PCMCIA_POR_16BIT;
if (io->flags & MAP_ACTIVE)
reg |= M8XX_PCMCIA_POR_VALID;
out_be32(&w->or, reg);
pr_debug("m8xx_pcmcia: Socket %u: Mapped io window %u at "
"%#8.8x, OR = %#8.8x.\n", lsock, io->map, w->br, w->or);
} else {
winnr = (PCMCIA_MEM_WIN_NO * PCMCIA_SOCKETS_NO)
+ (lsock * PCMCIA_IO_WIN_NO) + io->map;
w = (void *)&pcmcia->pcmc_pbr0;
w += winnr;
out_be32(&w->or, 0);
out_be32(&w->br, 0);
pr_debug("m8xx_pcmcia: Socket %u: Unmapped io window %u at "
"%#8.8x, OR = %#8.8x.\n", lsock, io->map, w->br, w->or);
}
s->io_win[io->map] = *io;
s->io_win[io->map].flags &= (MAP_WRPROT | MAP_16BIT | MAP_ACTIVE);
pr_debug("m8xx_pcmcia: SetIOMap exit\n");
return 0;
}
static int m8xx_set_mem_map(struct pcmcia_socket *sock,
struct pccard_mem_map *mem)
{
int lsock = container_of(sock, struct socket_info, socket)->slot;
struct socket_info *s = &socket[lsock];
struct pcmcia_win *w;
struct pccard_mem_map *old;
unsigned int reg, winnr;
pcmconf8xx_t *pcmcia = s->pcmcia;
pr_debug("m8xx_pcmcia: SetMemMap(%d, %d, %#2.2x, %d ns, "
"%#5.5llx, %#5.5x)\n", lsock, mem->map, mem->flags,
mem->speed, (unsigned long long)mem->static_start,
mem->card_start);
if ((mem->map >= PCMCIA_MEM_WIN_NO)
|| (mem->card_start >= 0x04000000)
|| (mem->static_start & 0xfff)
||(mem->card_start & 0xfff))
return -EINVAL;
if ((reg = m8xx_get_graycode(PCMCIA_MEM_WIN_SIZE)) == -1) {
printk("Cannot set size to 0x%08x.\n", PCMCIA_MEM_WIN_SIZE);
return -EINVAL;
}
reg <<= 27;
winnr = (lsock * PCMCIA_MEM_WIN_NO) + mem->map;
w = (void *)&pcmcia->pcmc_pbr0;
w += winnr;
reg |= lsock << 2;
reg |= m8xx_get_speed(mem->speed, 0, s->bus_freq);
if (mem->flags & MAP_ATTRIB)
reg |= M8XX_PCMCIA_POR_ATTRMEM;
if (mem->flags & MAP_WRPROT)
reg |= M8XX_PCMCIA_POR_WRPROT;
if (mem->flags & MAP_16BIT)
reg |= M8XX_PCMCIA_POR_16BIT;
if (mem->flags & MAP_ACTIVE)
reg |= M8XX_PCMCIA_POR_VALID;
out_be32(&w->or, reg);
pr_debug("m8xx_pcmcia: Socket %u: Mapped memory window %u at %#8.8x, "
"OR = %#8.8x.\n", lsock, mem->map, w->br, w->or);
if (mem->flags & MAP_ACTIVE) {
mem->static_start = PCMCIA_MEM_WIN_BASE +
(PCMCIA_MEM_WIN_SIZE * winnr)
+ mem->card_start;
}
pr_debug("m8xx_pcmcia: SetMemMap(%d, %d, %#2.2x, %d ns, "
"%#5.5llx, %#5.5x)\n", lsock, mem->map, mem->flags,
mem->speed, (unsigned long long)mem->static_start,
mem->card_start);
old = &s->mem_win[mem->map];
*old = *mem;
old->flags &= (MAP_ATTRIB | MAP_WRPROT | MAP_16BIT | MAP_ACTIVE);
return 0;
}
static int m8xx_sock_init(struct pcmcia_socket *sock)
{
int i;
pccard_io_map io = { 0, 0, 0, 0, 1 };
pccard_mem_map mem = { 0, 0, 0, 0, 0, 0 };
pr_debug("m8xx_pcmcia: sock_init(%d)\n", s);
m8xx_set_socket(sock, &dead_socket);
for (i = 0; i < PCMCIA_IO_WIN_NO; i++) {
io.map = i;
m8xx_set_io_map(sock, &io);
}
for (i = 0; i < PCMCIA_MEM_WIN_NO; i++) {
mem.map = i;
m8xx_set_mem_map(sock, &mem);
}
return 0;
}
static int m8xx_sock_suspend(struct pcmcia_socket *sock)
{
return m8xx_set_socket(sock, &dead_socket);
}
static int __init m8xx_probe(struct platform_device *ofdev)
{
struct pcmcia_win *w;
unsigned int i, m, hwirq;
pcmconf8xx_t *pcmcia;
int status;
struct device_node *np = ofdev->dev.of_node;
pcmcia_info("%s\n", version);
pcmcia = of_iomap(np, 0);
if (pcmcia == NULL)
return -EINVAL;
pcmcia_schlvl = irq_of_parse_and_map(np, 0);
hwirq = irq_map[pcmcia_schlvl].hwirq;
if (pcmcia_schlvl < 0) {
iounmap(pcmcia);
return -EINVAL;
}
m8xx_pgcrx[0] = &pcmcia->pcmc_pgcra;
m8xx_pgcrx[1] = &pcmcia->pcmc_pgcrb;
pcmcia_info(PCMCIA_BOARD_MSG " using " PCMCIA_SLOT_MSG
" with IRQ %u (%d). \n", pcmcia_schlvl, hwirq);
if (request_irq(pcmcia_schlvl, m8xx_interrupt, IRQF_SHARED,
driver_name, socket)) {
pcmcia_error("Cannot allocate IRQ %u for SCHLVL!\n",
pcmcia_schlvl);
iounmap(pcmcia);
return -1;
}
w = (void *)&pcmcia->pcmc_pbr0;
out_be32(&pcmcia->pcmc_pscr, M8XX_PCMCIA_MASK(0) | M8XX_PCMCIA_MASK(1));
clrbits32(&pcmcia->pcmc_per, M8XX_PCMCIA_MASK(0) | M8XX_PCMCIA_MASK(1));
out_be32(M8XX_PGCRX(0),
M8XX_PGCRX_CXOE | (mk_int_int_mask(hwirq) << 16));
out_be32(M8XX_PGCRX(1),
M8XX_PGCRX_CXOE | (mk_int_int_mask(hwirq) << 16));
for (i = 0; i < PCMCIA_SOCKETS_NO; i++) {
for (m = 0; m < PCMCIA_MEM_WIN_NO; m++) {
out_be32(&w->br, PCMCIA_MEM_WIN_BASE +
(PCMCIA_MEM_WIN_SIZE
* (m + i * PCMCIA_MEM_WIN_NO)));
out_be32(&w->or, 0);
w++;
}
}
voltage_set(0, 0, 0);
voltage_set(1, 0, 0);
hardware_enable(0);
hardware_enable(1);
for (i = 0; i < PCMCIA_SOCKETS_NO; i++) {
socket[i].slot = i;
socket[i].socket.owner = THIS_MODULE;
socket[i].socket.features =
SS_CAP_PCCARD | SS_CAP_MEM_ALIGN | SS_CAP_STATIC_MAP;
socket[i].socket.irq_mask = 0x000;
socket[i].socket.map_size = 0x1000;
socket[i].socket.io_offset = 0;
socket[i].socket.pci_irq = pcmcia_schlvl;
socket[i].socket.ops = &m8xx_services;
socket[i].socket.resource_ops = &pccard_iodyn_ops;
socket[i].socket.cb_dev = NULL;
socket[i].socket.dev.parent = &ofdev->dev;
socket[i].pcmcia = pcmcia;
socket[i].bus_freq = ppc_proc_freq;
socket[i].hwirq = hwirq;
}
for (i = 0; i < PCMCIA_SOCKETS_NO; i++) {
status = pcmcia_register_socket(&socket[i].socket);
if (status < 0)
pcmcia_error("Socket register failed\n");
}
return 0;
}
static int m8xx_remove(struct platform_device *ofdev)
{
u32 m, i;
struct pcmcia_win *w;
pcmconf8xx_t *pcmcia = socket[0].pcmcia;
for (i = 0; i < PCMCIA_SOCKETS_NO; i++) {
w = (void *)&pcmcia->pcmc_pbr0;
out_be32(&pcmcia->pcmc_pscr, M8XX_PCMCIA_MASK(i));
out_be32(&pcmcia->pcmc_per,
in_be32(&pcmcia->pcmc_per) & ~M8XX_PCMCIA_MASK(i));
out_be32(M8XX_PGCRX(i), M8XX_PGCRX_CXOE);
for (m = 0; m < PCMCIA_MEM_WIN_NO; m++) {
out_be32(&w->or, 0);
w++;
}
voltage_set(i, 0, 0);
hardware_disable(i);
}
for (i = 0; i < PCMCIA_SOCKETS_NO; i++)
pcmcia_unregister_socket(&socket[i].socket);
iounmap(pcmcia);
free_irq(pcmcia_schlvl, NULL);
return 0;
}
