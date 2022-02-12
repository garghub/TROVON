static void frob_econtrol(struct parport *pb, unsigned char m,
unsigned char v)
{
unsigned char ectr = 0;
if (m != 0xff)
ectr = inb(ECONTROL(pb));
DPRINTK(KERN_DEBUG "frob_econtrol(%02x,%02x): %02x -> %02x\n",
m, v, ectr, (ectr & ~m) ^ v);
outb((ectr & ~m) ^ v, ECONTROL(pb));
}
static inline void frob_set_mode(struct parport *p, int mode)
{
frob_econtrol(p, ECR_MODE_MASK, mode << 5);
}
static int change_mode(struct parport *p, int m)
{
const struct parport_pc_private *priv = p->physport->private_data;
unsigned char oecr;
int mode;
DPRINTK(KERN_INFO "parport change_mode ECP-ISA to mode 0x%02x\n", m);
if (!priv->ecr) {
printk(KERN_DEBUG "change_mode: but there's no ECR!\n");
return 0;
}
oecr = inb(ECONTROL(p));
mode = (oecr >> 5) & 0x7;
if (mode == m)
return 0;
if (mode >= 2 && !(priv->ctr & 0x20)) {
unsigned long expire = jiffies + p->physport->cad->timeout;
int counter;
switch (mode) {
case ECR_PPF:
case ECR_ECP:
for (counter = 0; counter < 40; counter++) {
if (inb(ECONTROL(p)) & 0x01)
break;
if (signal_pending(current))
break;
udelay(5);
}
while (!(inb(ECONTROL(p)) & 0x01)) {
if (time_after_eq(jiffies, expire))
return -EBUSY;
schedule_timeout_interruptible(
msecs_to_jiffies(10));
if (signal_pending(current))
break;
}
}
}
if (mode >= 2 && m >= 2) {
oecr &= ~(7 << 5);
oecr |= ECR_PS2 << 5;
ECR_WRITE(p, oecr);
}
oecr &= ~(7 << 5);
oecr |= m << 5;
ECR_WRITE(p, oecr);
return 0;
}
static int clear_epp_timeout(struct parport *pb)
{
unsigned char r;
if (!(parport_pc_read_status(pb) & 0x01))
return 1;
parport_pc_read_status(pb);
r = parport_pc_read_status(pb);
outb(r | 0x01, STATUS(pb));
outb(r & 0xfe, STATUS(pb));
r = parport_pc_read_status(pb);
return !(r & 0x01);
}
static void parport_pc_init_state(struct pardevice *dev,
struct parport_state *s)
{
s->u.pc.ctr = 0xc;
if (dev->irq_func &&
dev->port->irq != PARPORT_IRQ_NONE)
s->u.pc.ctr |= 0x10;
s->u.pc.ecr = 0x34;
}
static void parport_pc_save_state(struct parport *p, struct parport_state *s)
{
const struct parport_pc_private *priv = p->physport->private_data;
s->u.pc.ctr = priv->ctr;
if (priv->ecr)
s->u.pc.ecr = inb(ECONTROL(p));
}
static void parport_pc_restore_state(struct parport *p,
struct parport_state *s)
{
struct parport_pc_private *priv = p->physport->private_data;
register unsigned char c = s->u.pc.ctr & priv->ctr_writable;
outb(c, CONTROL(p));
priv->ctr = c;
if (priv->ecr)
ECR_WRITE(p, s->u.pc.ecr);
}
static size_t parport_pc_epp_read_data(struct parport *port, void *buf,
size_t length, int flags)
{
size_t got = 0;
if (flags & PARPORT_W91284PIC) {
unsigned char status;
size_t left = length;
status = inb(STATUS(port));
while (!(status & 0x08) && got < length) {
if (left >= 16 && (status & 0x20) && !(status & 0x08)) {
if (!((long)buf & 0x03))
insl(EPPDATA(port), buf, 4);
else
insb(EPPDATA(port), buf, 16);
buf += 16;
got += 16;
left -= 16;
} else {
*((char *)buf) = inb(EPPDATA(port));
buf++;
got++;
left--;
}
status = inb(STATUS(port));
if (status & 0x01) {
printk(KERN_DEBUG
"%s: EPP timeout occurred while talking to w91284pic (should not have done)\n", port->name);
clear_epp_timeout(port);
}
}
return got;
}
if ((flags & PARPORT_EPP_FAST) && (length > 1)) {
if (!(((long)buf | length) & 0x03))
insl(EPPDATA(port), buf, (length >> 2));
else
insb(EPPDATA(port), buf, length);
if (inb(STATUS(port)) & 0x01) {
clear_epp_timeout(port);
return -EIO;
}
return length;
}
for (; got < length; got++) {
*((char *)buf) = inb(EPPDATA(port));
buf++;
if (inb(STATUS(port)) & 0x01) {
clear_epp_timeout(port);
break;
}
}
return got;
}
static size_t parport_pc_epp_write_data(struct parport *port, const void *buf,
size_t length, int flags)
{
size_t written = 0;
if ((flags & PARPORT_EPP_FAST) && (length > 1)) {
if (!(((long)buf | length) & 0x03))
outsl(EPPDATA(port), buf, (length >> 2));
else
outsb(EPPDATA(port), buf, length);
if (inb(STATUS(port)) & 0x01) {
clear_epp_timeout(port);
return -EIO;
}
return length;
}
for (; written < length; written++) {
outb(*((char *)buf), EPPDATA(port));
buf++;
if (inb(STATUS(port)) & 0x01) {
clear_epp_timeout(port);
break;
}
}
return written;
}
static size_t parport_pc_epp_read_addr(struct parport *port, void *buf,
size_t length, int flags)
{
size_t got = 0;
if ((flags & PARPORT_EPP_FAST) && (length > 1)) {
insb(EPPADDR(port), buf, length);
if (inb(STATUS(port)) & 0x01) {
clear_epp_timeout(port);
return -EIO;
}
return length;
}
for (; got < length; got++) {
*((char *)buf) = inb(EPPADDR(port));
buf++;
if (inb(STATUS(port)) & 0x01) {
clear_epp_timeout(port);
break;
}
}
return got;
}
static size_t parport_pc_epp_write_addr(struct parport *port,
const void *buf, size_t length,
int flags)
{
size_t written = 0;
if ((flags & PARPORT_EPP_FAST) && (length > 1)) {
outsb(EPPADDR(port), buf, length);
if (inb(STATUS(port)) & 0x01) {
clear_epp_timeout(port);
return -EIO;
}
return length;
}
for (; written < length; written++) {
outb(*((char *)buf), EPPADDR(port));
buf++;
if (inb(STATUS(port)) & 0x01) {
clear_epp_timeout(port);
break;
}
}
return written;
}
static size_t parport_pc_ecpepp_read_data(struct parport *port, void *buf,
size_t length, int flags)
{
size_t got;
frob_set_mode(port, ECR_EPP);
parport_pc_data_reverse(port);
parport_pc_write_control(port, 0x4);
got = parport_pc_epp_read_data(port, buf, length, flags);
frob_set_mode(port, ECR_PS2);
return got;
}
static size_t parport_pc_ecpepp_write_data(struct parport *port,
const void *buf, size_t length,
int flags)
{
size_t written;
frob_set_mode(port, ECR_EPP);
parport_pc_write_control(port, 0x4);
parport_pc_data_forward(port);
written = parport_pc_epp_write_data(port, buf, length, flags);
frob_set_mode(port, ECR_PS2);
return written;
}
static size_t parport_pc_ecpepp_read_addr(struct parport *port, void *buf,
size_t length, int flags)
{
size_t got;
frob_set_mode(port, ECR_EPP);
parport_pc_data_reverse(port);
parport_pc_write_control(port, 0x4);
got = parport_pc_epp_read_addr(port, buf, length, flags);
frob_set_mode(port, ECR_PS2);
return got;
}
static size_t parport_pc_ecpepp_write_addr(struct parport *port,
const void *buf, size_t length,
int flags)
{
size_t written;
frob_set_mode(port, ECR_EPP);
parport_pc_write_control(port, 0x4);
parport_pc_data_forward(port);
written = parport_pc_epp_write_addr(port, buf, length, flags);
frob_set_mode(port, ECR_PS2);
return written;
}
static size_t parport_pc_fifo_write_block_pio(struct parport *port,
const void *buf, size_t length)
{
int ret = 0;
const unsigned char *bufp = buf;
size_t left = length;
unsigned long expire = jiffies + port->physport->cad->timeout;
const int fifo = FIFO(port);
int poll_for = 8;
const struct parport_pc_private *priv = port->physport->private_data;
const int fifo_depth = priv->fifo_depth;
port = port->physport;
parport_pc_disable_irq(port);
frob_econtrol(port, (1<<4) | (1<<2), (1<<4) | (1<<2));
parport_pc_data_forward(port);
while (left) {
unsigned char byte;
unsigned char ecrval = inb(ECONTROL(port));
int i = 0;
if (need_resched() && time_before(jiffies, expire))
schedule();
if (port->waithead) {
printk(KERN_DEBUG "Somebody wants the port\n");
break;
}
if (ecrval & 0x02) {
ECR_WRITE(port, ecrval & ~(1<<2));
false_alarm:
ret = parport_wait_event(port, HZ);
if (ret < 0)
break;
ret = 0;
if (!time_before(jiffies, expire)) {
printk(KERN_DEBUG "FIFO write timed out\n");
break;
}
ecrval = inb(ECONTROL(port));
if (!(ecrval & (1<<2))) {
if (need_resched() &&
time_before(jiffies, expire))
schedule();
goto false_alarm;
}
continue;
}
expire = jiffies + port->cad->timeout;
poll:
if (signal_pending(current))
break;
if (ecrval & 0x01) {
const int n = left < fifo_depth ? left : fifo_depth;
outsb(fifo, bufp, n);
bufp += n;
left -= n;
if (i < (poll_for - 2))
poll_for--;
continue;
} else if (i++ < poll_for) {
udelay(10);
ecrval = inb(ECONTROL(port));
goto poll;
}
byte = *bufp++;
outb(byte, fifo);
left--;
}
dump_parport_state("leave fifo_write_block_pio", port);
return length - left;
}
static size_t parport_pc_fifo_write_block_dma(struct parport *port,
const void *buf, size_t length)
{
int ret = 0;
unsigned long dmaflag;
size_t left = length;
const struct parport_pc_private *priv = port->physport->private_data;
struct device *dev = port->physport->dev;
dma_addr_t dma_addr, dma_handle;
size_t maxlen = 0x10000;
unsigned long start = (unsigned long) buf;
unsigned long end = (unsigned long) buf + length - 1;
dump_parport_state("enter fifo_write_block_dma", port);
if (end < MAX_DMA_ADDRESS) {
if ((start ^ end) & ~0xffffUL)
maxlen = 0x10000 - (start & 0xffff);
dma_addr = dma_handle = dma_map_single(dev, (void *)buf, length,
DMA_TO_DEVICE);
} else {
maxlen = PAGE_SIZE;
dma_addr = priv->dma_handle;
dma_handle = 0;
}
port = port->physport;
parport_pc_disable_irq(port);
frob_econtrol(port, (1<<4) | (1<<2), (1<<4) | (1<<2));
parport_pc_data_forward(port);
while (left) {
unsigned long expire = jiffies + port->physport->cad->timeout;
size_t count = left;
if (count > maxlen)
count = maxlen;
if (!dma_handle)
memcpy(priv->dma_buf, buf, count);
dmaflag = claim_dma_lock();
disable_dma(port->dma);
clear_dma_ff(port->dma);
set_dma_mode(port->dma, DMA_MODE_WRITE);
set_dma_addr(port->dma, dma_addr);
set_dma_count(port->dma, count);
frob_econtrol(port, 1<<3, 1<<3);
frob_econtrol(port, 1<<2, 0);
enable_dma(port->dma);
release_dma_lock(dmaflag);
left -= count;
buf += count;
if (dma_handle)
dma_addr += count;
false_alarm:
ret = parport_wait_event(port, HZ);
if (ret < 0)
break;
ret = 0;
if (!time_before(jiffies, expire)) {
printk(KERN_DEBUG "DMA write timed out\n");
break;
}
if (!(inb(ECONTROL(port)) & (1<<2))) {
cond_resched();
goto false_alarm;
}
dmaflag = claim_dma_lock();
disable_dma(port->dma);
clear_dma_ff(port->dma);
count = get_dma_residue(port->dma);
release_dma_lock(dmaflag);
cond_resched();
if (port->waithead) {
printk(KERN_DEBUG "Somebody wants the port\n");
break;
}
buf -= count;
left += count;
if (dma_handle)
dma_addr -= count;
}
dmaflag = claim_dma_lock();
disable_dma(port->dma);
clear_dma_ff(port->dma);
left += get_dma_residue(port->dma);
release_dma_lock(dmaflag);
frob_econtrol(port, 1<<3, 0);
if (dma_handle)
dma_unmap_single(dev, dma_handle, length, DMA_TO_DEVICE);
dump_parport_state("leave fifo_write_block_dma", port);
return length - left;
}
static inline size_t parport_pc_fifo_write_block(struct parport *port,
const void *buf, size_t length)
{
#ifdef HAS_DMA
if (port->dma != PARPORT_DMA_NONE)
return parport_pc_fifo_write_block_dma(port, buf, length);
#endif
return parport_pc_fifo_write_block_pio(port, buf, length);
}
static size_t parport_pc_compat_write_block_pio(struct parport *port,
const void *buf, size_t length,
int flags)
{
size_t written;
int r;
unsigned long expire;
const struct parport_pc_private *priv = port->physport->private_data;
if (port->physport->cad->timeout <= PARPORT_INACTIVITY_O_NONBLOCK)
return parport_ieee1284_write_compat(port, buf,
length, flags);
parport_pc_data_forward(port);
parport_pc_frob_control(port, PARPORT_CONTROL_STROBE, 0);
r = change_mode(port, ECR_PPF);
if (r)
printk(KERN_DEBUG "%s: Warning change_mode ECR_PPF failed\n",
port->name);
port->physport->ieee1284.phase = IEEE1284_PH_FWD_DATA;
written = parport_pc_fifo_write_block(port, buf, length);
expire = jiffies + (priv->fifo_depth * HZ * 4);
do {
r = change_mode(port, ECR_PS2);
if (r != -EBUSY)
break;
} while (time_before(jiffies, expire));
if (r == -EBUSY) {
printk(KERN_DEBUG "%s: FIFO is stuck\n", port->name);
frob_set_mode(port, ECR_TST);
for (written -= priv->fifo_depth; ; written++) {
if (inb(ECONTROL(port)) & 0x2) {
break;
}
outb(0, FIFO(port));
}
frob_set_mode(port, ECR_PS2);
}
r = parport_wait_peripheral(port,
PARPORT_STATUS_BUSY,
PARPORT_STATUS_BUSY);
if (r)
printk(KERN_DEBUG
"%s: BUSY timeout (%d) in compat_write_block_pio\n",
port->name, r);
port->physport->ieee1284.phase = IEEE1284_PH_FWD_IDLE;
return written;
}
static size_t parport_pc_ecp_write_block_pio(struct parport *port,
const void *buf, size_t length,
int flags)
{
size_t written;
int r;
unsigned long expire;
const struct parport_pc_private *priv = port->physport->private_data;
if (port->physport->cad->timeout <= PARPORT_INACTIVITY_O_NONBLOCK)
return parport_ieee1284_ecp_write_data(port, buf,
length, flags);
if (port->physport->ieee1284.phase != IEEE1284_PH_FWD_IDLE) {
parport_frob_control(port,
PARPORT_CONTROL_INIT
| PARPORT_CONTROL_AUTOFD,
PARPORT_CONTROL_INIT
| PARPORT_CONTROL_AUTOFD);
r = parport_wait_peripheral(port,
PARPORT_STATUS_PAPEROUT,
PARPORT_STATUS_PAPEROUT);
if (r) {
printk(KERN_DEBUG "%s: PError timeout (%d) "
"in ecp_write_block_pio\n", port->name, r);
}
}
parport_pc_data_forward(port);
parport_pc_frob_control(port,
PARPORT_CONTROL_STROBE |
PARPORT_CONTROL_AUTOFD,
0);
r = change_mode(port, ECR_ECP);
if (r)
printk(KERN_DEBUG "%s: Warning change_mode ECR_ECP failed\n",
port->name);
port->physport->ieee1284.phase = IEEE1284_PH_FWD_DATA;
written = parport_pc_fifo_write_block(port, buf, length);
expire = jiffies + (priv->fifo_depth * (HZ * 4));
do {
r = change_mode(port, ECR_PS2);
if (r != -EBUSY)
break;
} while (time_before(jiffies, expire));
if (r == -EBUSY) {
printk(KERN_DEBUG "%s: FIFO is stuck\n", port->name);
frob_set_mode(port, ECR_TST);
for (written -= priv->fifo_depth; ; written++) {
if (inb(ECONTROL(port)) & 0x2) {
break;
}
outb(0, FIFO(port));
}
frob_set_mode(port, ECR_PS2);
parport_pc_data_reverse(port);
udelay(5);
parport_frob_control(port, PARPORT_CONTROL_INIT, 0);
r = parport_wait_peripheral(port, PARPORT_STATUS_PAPEROUT, 0);
if (r)
printk(KERN_DEBUG "%s: PE,1 timeout (%d) "
"in ecp_write_block_pio\n", port->name, r);
parport_frob_control(port,
PARPORT_CONTROL_INIT,
PARPORT_CONTROL_INIT);
r = parport_wait_peripheral(port,
PARPORT_STATUS_PAPEROUT,
PARPORT_STATUS_PAPEROUT);
if (r)
printk(KERN_DEBUG "%s: PE,2 timeout (%d) "
"in ecp_write_block_pio\n", port->name, r);
}
r = parport_wait_peripheral(port,
PARPORT_STATUS_BUSY,
PARPORT_STATUS_BUSY);
if (r)
printk(KERN_DEBUG
"%s: BUSY timeout (%d) in ecp_write_block_pio\n",
port->name, r);
port->physport->ieee1284.phase = IEEE1284_PH_FWD_IDLE;
return written;
}
static struct superio_struct *find_free_superio(void)
{
int i;
for (i = 0; i < NR_SUPERIOS; i++)
if (superios[i].io == 0)
return &superios[i];
return NULL;
}
static void show_parconfig_smsc37c669(int io, int key)
{
int cr1, cr4, cra, cr23, cr26, cr27;
struct superio_struct *s;
static const char *const modes[] = {
"SPP and Bidirectional (PS/2)",
"EPP and SPP",
"ECP",
"ECP and EPP" };
outb(key, io);
outb(key, io);
outb(1, io);
cr1 = inb(io + 1);
outb(4, io);
cr4 = inb(io + 1);
outb(0x0a, io);
cra = inb(io + 1);
outb(0x23, io);
cr23 = inb(io + 1);
outb(0x26, io);
cr26 = inb(io + 1);
outb(0x27, io);
cr27 = inb(io + 1);
outb(0xaa, io);
if (verbose_probing) {
printk(KERN_INFO
"SMSC 37c669 LPT Config: cr_1=0x%02x, 4=0x%02x, "
"A=0x%2x, 23=0x%02x, 26=0x%02x, 27=0x%02x\n",
cr1, cr4, cra, cr23, cr26, cr27);
printk(KERN_INFO
"SMSC LPT Config: io=0x%04x, irq=%c, dma=%c, fifo threshold=%d\n",
cr23 * 4,
(cr27 & 0x0f) ? 'A' - 1 + (cr27 & 0x0f) : '-',
(cr26 & 0x0f) ? 'A' - 1 + (cr26 & 0x0f) : '-',
cra & 0x0f);
printk(KERN_INFO "SMSC LPT Config: enabled=%s power=%s\n",
(cr23 * 4 >= 0x100) ? "yes" : "no",
(cr1 & 4) ? "yes" : "no");
printk(KERN_INFO
"SMSC LPT Config: Port mode=%s, EPP version =%s\n",
(cr1 & 0x08) ? "Standard mode only (SPP)"
: modes[cr4 & 0x03],
(cr4 & 0x40) ? "1.7" : "1.9");
}
if (cr23 * 4 >= 0x100) {
s = find_free_superio();
if (s == NULL)
printk(KERN_INFO "Super-IO: too many chips!\n");
else {
int d;
switch (cr23 * 4) {
case 0x3bc:
s->io = 0x3bc;
s->irq = 7;
break;
case 0x378:
s->io = 0x378;
s->irq = 7;
break;
case 0x278:
s->io = 0x278;
s->irq = 5;
}
d = (cr26 & 0x0f);
if (d == 1 || d == 3)
s->dma = d;
else
s->dma = PARPORT_DMA_NONE;
}
}
}
static void show_parconfig_winbond(int io, int key)
{
int cr30, cr60, cr61, cr70, cr74, crf0;
struct superio_struct *s;
static const char *const modes[] = {
"Standard (SPP) and Bidirectional(PS/2)",
"EPP-1.9 and SPP",
"ECP",
"ECP and EPP-1.9",
"Standard (SPP)",
"EPP-1.7 and SPP",
"undefined!",
"ECP and EPP-1.7" };
static char *const irqtypes[] = {
"pulsed low, high-Z",
"follows nACK" };
outb(key, io);
outb(key, io);
outb(0x07, io);
outb(0x01, io + 1);
outb(0x30, io);
cr30 = inb(io + 1);
outb(0x60, io);
cr60 = inb(io + 1);
outb(0x61, io);
cr61 = inb(io + 1);
outb(0x70, io);
cr70 = inb(io + 1);
outb(0x74, io);
cr74 = inb(io + 1);
outb(0xf0, io);
crf0 = inb(io + 1);
outb(0xaa, io);
if (verbose_probing) {
printk(KERN_INFO
"Winbond LPT Config: cr_30=%02x 60,61=%02x%02x 70=%02x 74=%02x, f0=%02x\n",
cr30, cr60, cr61, cr70, cr74, crf0);
printk(KERN_INFO "Winbond LPT Config: active=%s, io=0x%02x%02x irq=%d, ",
(cr30 & 0x01) ? "yes" : "no", cr60, cr61, cr70 & 0x0f);
if ((cr74 & 0x07) > 3)
printk("dma=none\n");
else
printk("dma=%d\n", cr74 & 0x07);
printk(KERN_INFO
"Winbond LPT Config: irqtype=%s, ECP fifo threshold=%d\n",
irqtypes[crf0>>7], (crf0>>3)&0x0f);
printk(KERN_INFO "Winbond LPT Config: Port mode=%s\n",
modes[crf0 & 0x07]);
}
if (cr30 & 0x01) {
s = find_free_superio();
if (s == NULL)
printk(KERN_INFO "Super-IO: too many chips!\n");
else {
s->io = (cr60 << 8) | cr61;
s->irq = cr70 & 0x0f;
s->dma = (((cr74 & 0x07) > 3) ?
PARPORT_DMA_NONE : (cr74 & 0x07));
}
}
}
static void decode_winbond(int efer, int key, int devid, int devrev, int oldid)
{
const char *type = "unknown";
int id, progif = 2;
if (devid == devrev)
return;
id = (devid << 8) | devrev;
if (id == 0x9771)
type = "83977F/AF";
else if (id == 0x9773)
type = "83977TF / SMSC 97w33x/97w34x";
else if (id == 0x9774)
type = "83977ATF";
else if ((id & ~0x0f) == 0x5270)
type = "83977CTF / SMSC 97w36x";
else if ((id & ~0x0f) == 0x52f0)
type = "83977EF / SMSC 97w35x";
else if ((id & ~0x0f) == 0x5210)
type = "83627";
else if ((id & ~0x0f) == 0x6010)
type = "83697HF";
else if ((oldid & 0x0f) == 0x0a) {
type = "83877F";
progif = 1;
} else if ((oldid & 0x0f) == 0x0b) {
type = "83877AF";
progif = 1;
} else if ((oldid & 0x0f) == 0x0c) {
type = "83877TF";
progif = 1;
} else if ((oldid & 0x0f) == 0x0d) {
type = "83877ATF";
progif = 1;
} else
progif = 0;
if (verbose_probing)
printk(KERN_INFO "Winbond chip at EFER=0x%x key=0x%02x "
"devid=%02x devrev=%02x oldid=%02x type=%s\n",
efer, key, devid, devrev, oldid, type);
if (progif == 2)
show_parconfig_winbond(efer, key);
}
static void decode_smsc(int efer, int key, int devid, int devrev)
{
const char *type = "unknown";
void (*func)(int io, int key);
int id;
if (devid == devrev)
return;
func = NULL;
id = (devid << 8) | devrev;
if (id == 0x0302) {
type = "37c669";
func = show_parconfig_smsc37c669;
} else if (id == 0x6582)
type = "37c665IR";
else if (devid == 0x65)
type = "37c665GT";
else if (devid == 0x66)
type = "37c666GT";
if (verbose_probing)
printk(KERN_INFO "SMSC chip at EFER=0x%x "
"key=0x%02x devid=%02x devrev=%02x type=%s\n",
efer, key, devid, devrev, type);
if (func)
func(efer, key);
}
static void winbond_check(int io, int key)
{
int origval, devid, devrev, oldid, x_devid, x_devrev, x_oldid;
if (!request_region(io, 3, __func__))
return;
origval = inb(io);
outb(0x20, io);
x_devid = inb(io + 1);
outb(0x21, io);
x_devrev = inb(io + 1);
outb(0x09, io);
x_oldid = inb(io + 1);
outb(key, io);
outb(key, io);
outb(0x20, io);
devid = inb(io + 1);
outb(0x21, io);
devrev = inb(io + 1);
outb(0x09, io);
oldid = inb(io + 1);
outb(0xaa, io);
outb(origval, io);
if ((x_devid == devid) && (x_devrev == devrev) && (x_oldid == oldid))
goto out;
decode_winbond(io, key, devid, devrev, oldid);
out:
release_region(io, 3);
}
static void winbond_check2(int io, int key)
{
int origval[3], devid, devrev, oldid, x_devid, x_devrev, x_oldid;
if (!request_region(io, 3, __func__))
return;
origval[0] = inb(io);
origval[1] = inb(io + 1);
origval[2] = inb(io + 2);
outb(0x20, io + 2);
x_devid = inb(io + 2);
outb(0x21, io + 1);
x_devrev = inb(io + 2);
outb(0x09, io + 1);
x_oldid = inb(io + 2);
outb(key, io);
outb(0x20, io + 2);
devid = inb(io + 2);
outb(0x21, io + 1);
devrev = inb(io + 2);
outb(0x09, io + 1);
oldid = inb(io + 2);
outb(0xaa, io);
outb(origval[0], io);
outb(origval[1], io + 1);
outb(origval[2], io + 2);
if (x_devid == devid && x_devrev == devrev && x_oldid == oldid)
goto out;
decode_winbond(io, key, devid, devrev, oldid);
out:
release_region(io, 3);
}
static void smsc_check(int io, int key)
{
int origval, id, rev, oldid, oldrev, x_id, x_rev, x_oldid, x_oldrev;
if (!request_region(io, 3, __func__))
return;
origval = inb(io);
outb(0x0d, io);
x_oldid = inb(io + 1);
outb(0x0e, io);
x_oldrev = inb(io + 1);
outb(0x20, io);
x_id = inb(io + 1);
outb(0x21, io);
x_rev = inb(io + 1);
outb(key, io);
outb(key, io);
outb(0x0d, io);
oldid = inb(io + 1);
outb(0x0e, io);
oldrev = inb(io + 1);
outb(0x20, io);
id = inb(io + 1);
outb(0x21, io);
rev = inb(io + 1);
outb(0xaa, io);
outb(origval, io);
if (x_id == id && x_oldrev == oldrev &&
x_oldid == oldid && x_rev == rev)
goto out;
decode_smsc(io, key, oldid, oldrev);
out:
release_region(io, 3);
}
static void detect_and_report_winbond(void)
{
if (verbose_probing)
printk(KERN_DEBUG "Winbond Super-IO detection, now testing ports 3F0,370,250,4E,2E ...\n");
winbond_check(0x3f0, 0x87);
winbond_check(0x370, 0x87);
winbond_check(0x2e , 0x87);
winbond_check(0x4e , 0x87);
winbond_check(0x3f0, 0x86);
winbond_check2(0x250, 0x88);
winbond_check2(0x250, 0x89);
}
static void detect_and_report_smsc(void)
{
if (verbose_probing)
printk(KERN_DEBUG "SMSC Super-IO detection, now testing Ports 2F0, 370 ...\n");
smsc_check(0x3f0, 0x55);
smsc_check(0x370, 0x55);
smsc_check(0x3f0, 0x44);
smsc_check(0x370, 0x44);
}
static void detect_and_report_it87(void)
{
u16 dev;
u8 origval, r;
if (verbose_probing)
printk(KERN_DEBUG "IT8705 Super-IO detection, now testing port 2E ...\n");
if (!request_muxed_region(0x2e, 2, __func__))
return;
origval = inb(0x2e);
outb(0x87, 0x2e);
outb(0x01, 0x2e);
outb(0x55, 0x2e);
outb(0x55, 0x2e);
outb(0x20, 0x2e);
dev = inb(0x2f) << 8;
outb(0x21, 0x2e);
dev |= inb(0x2f);
if (dev == 0x8712 || dev == 0x8705 || dev == 0x8715 ||
dev == 0x8716 || dev == 0x8718 || dev == 0x8726) {
printk(KERN_INFO "IT%04X SuperIO detected.\n", dev);
outb(0x07, 0x2E);
outb(0x03, 0x2F);
outb(0xF0, 0x2E);
r = inb(0x2f);
outb(0xF0, 0x2E);
outb(r | 8, 0x2F);
outb(0x02, 0x2E);
outb(0x02, 0x2F);
} else {
outb(origval, 0x2e);
}
release_region(0x2e, 2);
}
static struct superio_struct *find_superio(struct parport *p)
{
int i;
for (i = 0; i < NR_SUPERIOS; i++)
if (superios[i].io != p->base)
return &superios[i];
return NULL;
}
static int get_superio_dma(struct parport *p)
{
struct superio_struct *s = find_superio(p);
if (s)
return s->dma;
return PARPORT_DMA_NONE;
}
static int get_superio_irq(struct parport *p)
{
struct superio_struct *s = find_superio(p);
if (s)
return s->irq;
return PARPORT_IRQ_NONE;
}
static int parport_SPP_supported(struct parport *pb)
{
unsigned char r, w;
clear_epp_timeout(pb);
w = 0xc;
outb(w, CONTROL(pb));
r = inb(CONTROL(pb));
if ((r & 0xf) == w) {
w = 0xe;
outb(w, CONTROL(pb));
r = inb(CONTROL(pb));
outb(0xc, CONTROL(pb));
if ((r & 0xf) == w)
return PARPORT_MODE_PCSPP;
}
if (user_specified)
printk(KERN_INFO "parport 0x%lx (WARNING): CTR: "
"wrote 0x%02x, read 0x%02x\n", pb->base, w, r);
w = 0xaa;
parport_pc_write_data(pb, w);
r = parport_pc_read_data(pb);
if (r == w) {
w = 0x55;
parport_pc_write_data(pb, w);
r = parport_pc_read_data(pb);
if (r == w)
return PARPORT_MODE_PCSPP;
}
if (user_specified) {
printk(KERN_INFO "parport 0x%lx (WARNING): DATA: "
"wrote 0x%02x, read 0x%02x\n", pb->base, w, r);
printk(KERN_INFO "parport 0x%lx: You gave this address, "
"but there is probably no parallel port there!\n",
pb->base);
}
if (user_specified)
return PARPORT_MODE_PCSPP;
return 0;
}
static int parport_ECR_present(struct parport *pb)
{
struct parport_pc_private *priv = pb->private_data;
unsigned char r = 0xc;
outb(r, CONTROL(pb));
if ((inb(ECONTROL(pb)) & 0x3) == (r & 0x3)) {
outb(r ^ 0x2, CONTROL(pb));
r = inb(CONTROL(pb));
if ((inb(ECONTROL(pb)) & 0x2) == (r & 0x2))
goto no_reg;
}
if ((inb(ECONTROL(pb)) & 0x3) != 0x1)
goto no_reg;
ECR_WRITE(pb, 0x34);
if (inb(ECONTROL(pb)) != 0x35)
goto no_reg;
priv->ecr = 1;
outb(0xc, CONTROL(pb));
frob_set_mode(pb, ECR_SPP);
return 1;
no_reg:
outb(0xc, CONTROL(pb));
return 0;
}
static int parport_PS2_supported(struct parport *pb)
{
int ok = 0;
clear_epp_timeout(pb);
parport_pc_data_reverse(pb);
parport_pc_write_data(pb, 0x55);
if (parport_pc_read_data(pb) != 0x55)
ok++;
parport_pc_write_data(pb, 0xaa);
if (parport_pc_read_data(pb) != 0xaa)
ok++;
parport_pc_data_forward(pb);
if (ok) {
pb->modes |= PARPORT_MODE_TRISTATE;
} else {
struct parport_pc_private *priv = pb->private_data;
priv->ctr_writable &= ~0x20;
}
return ok;
}
static int parport_ECP_supported(struct parport *pb)
{
int i;
int config, configb;
int pword;
struct parport_pc_private *priv = pb->private_data;
static const int intrline[] = { 0, 7, 9, 10, 11, 14, 15, 5 };
if (!priv->ecr)
return 0;
ECR_WRITE(pb, ECR_SPP << 5);
ECR_WRITE(pb, ECR_TST << 5);
for (i = 0; i < 1024 && !(inb(ECONTROL(pb)) & 0x02); i++)
outb(0xaa, FIFO(pb));
if (i == 1024) {
ECR_WRITE(pb, ECR_SPP << 5);
return 0;
}
priv->fifo_depth = i;
if (verbose_probing)
printk(KERN_DEBUG "0x%lx: FIFO is %d bytes\n", pb->base, i);
frob_econtrol(pb, 1<<2, 1<<2);
frob_econtrol(pb, 1<<2, 0);
for (i = 1; i <= priv->fifo_depth; i++) {
inb(FIFO(pb));
udelay(50);
if (inb(ECONTROL(pb)) & (1<<2))
break;
}
if (i <= priv->fifo_depth) {
if (verbose_probing)
printk(KERN_DEBUG "0x%lx: writeIntrThreshold is %d\n",
pb->base, i);
} else
i = 0;
priv->writeIntrThreshold = i;
frob_set_mode(pb, ECR_PS2);
parport_pc_data_reverse(pb);
frob_set_mode(pb, ECR_TST);
frob_econtrol(pb, 1<<2, 1<<2);
frob_econtrol(pb, 1<<2, 0);
for (i = 1; i <= priv->fifo_depth; i++) {
outb(0xaa, FIFO(pb));
if (inb(ECONTROL(pb)) & (1<<2))
break;
}
if (i <= priv->fifo_depth) {
if (verbose_probing)
printk(KERN_INFO "0x%lx: readIntrThreshold is %d\n",
pb->base, i);
} else
i = 0;
priv->readIntrThreshold = i;
ECR_WRITE(pb, ECR_SPP << 5);
ECR_WRITE(pb, 0xf4);
config = inb(CONFIGA(pb));
pword = (config >> 4) & 0x7;
switch (pword) {
case 0:
pword = 2;
printk(KERN_WARNING "0x%lx: Unsupported pword size!\n",
pb->base);
break;
case 2:
pword = 4;
printk(KERN_WARNING "0x%lx: Unsupported pword size!\n",
pb->base);
break;
default:
printk(KERN_WARNING "0x%lx: Unknown implementation ID\n",
pb->base);
case 1:
pword = 1;
}
priv->pword = pword;
if (verbose_probing) {
printk(KERN_DEBUG "0x%lx: PWord is %d bits\n",
pb->base, 8 * pword);
printk(KERN_DEBUG "0x%lx: Interrupts are ISA-%s\n", pb->base,
config & 0x80 ? "Level" : "Pulses");
configb = inb(CONFIGB(pb));
printk(KERN_DEBUG "0x%lx: ECP port cfgA=0x%02x cfgB=0x%02x\n",
pb->base, config, configb);
printk(KERN_DEBUG "0x%lx: ECP settings irq=", pb->base);
if ((configb >> 3) & 0x07)
printk("%d", intrline[(configb >> 3) & 0x07]);
else
printk("<none or set by other means>");
printk(" dma=");
if ((configb & 0x03) == 0x00)
printk("<none or set by other means>\n");
else
printk("%d\n", configb & 0x07);
}
frob_set_mode(pb, ECR_SPP);
return 1;
}
static int parport_ECPPS2_supported(struct parport *pb)
{
const struct parport_pc_private *priv = pb->private_data;
int result;
unsigned char oecr;
if (!priv->ecr)
return 0;
oecr = inb(ECONTROL(pb));
ECR_WRITE(pb, ECR_PS2 << 5);
result = parport_PS2_supported(pb);
ECR_WRITE(pb, oecr);
return result;
}
static int parport_EPP_supported(struct parport *pb)
{
const struct parport_pc_private *priv = pb->private_data;
if (!clear_epp_timeout(pb))
return 0;
if (priv->ecr) {
unsigned char i;
for (i = 0x00; i < 0x80; i += 0x20) {
ECR_WRITE(pb, i);
if (clear_epp_timeout(pb)) {
return 0;
}
}
}
pb->modes |= PARPORT_MODE_EPP;
pb->ops->epp_read_data = parport_pc_epp_read_data;
pb->ops->epp_write_data = parport_pc_epp_write_data;
pb->ops->epp_read_addr = parport_pc_epp_read_addr;
pb->ops->epp_write_addr = parport_pc_epp_write_addr;
return 1;
}
static int parport_ECPEPP_supported(struct parport *pb)
{
struct parport_pc_private *priv = pb->private_data;
int result;
unsigned char oecr;
if (!priv->ecr)
return 0;
oecr = inb(ECONTROL(pb));
ECR_WRITE(pb, 0x80);
outb(0x04, CONTROL(pb));
result = parport_EPP_supported(pb);
ECR_WRITE(pb, oecr);
if (result) {
pb->ops->epp_read_data = parport_pc_ecpepp_read_data;
pb->ops->epp_write_data = parport_pc_ecpepp_write_data;
pb->ops->epp_read_addr = parport_pc_ecpepp_read_addr;
pb->ops->epp_write_addr = parport_pc_ecpepp_write_addr;
}
return result;
}
static int parport_PS2_supported(struct parport *pb) { return 0; }
static int parport_ECP_supported(struct parport *pb)
{
return 0;
}
static int parport_EPP_supported(struct parport *pb)
{
return 0;
}
static int parport_ECPEPP_supported(struct parport *pb)
{
return 0;
}
static int parport_ECPPS2_supported(struct parport *pb)
{
return 0;
}
static int programmable_irq_support(struct parport *pb)
{
int irq, intrLine;
unsigned char oecr = inb(ECONTROL(pb));
static const int lookup[8] = {
PARPORT_IRQ_NONE, 7, 9, 10, 11, 14, 15, 5
};
ECR_WRITE(pb, ECR_CNF << 5);
intrLine = (inb(CONFIGB(pb)) >> 3) & 0x07;
irq = lookup[intrLine];
ECR_WRITE(pb, oecr);
return irq;
}
static int irq_probe_ECP(struct parport *pb)
{
int i;
unsigned long irqs;
irqs = probe_irq_on();
ECR_WRITE(pb, ECR_SPP << 5);
ECR_WRITE(pb, (ECR_TST << 5) | 0x04);
ECR_WRITE(pb, ECR_TST << 5);
for (i = 0; i < 1024 && !(inb(ECONTROL(pb)) & 0x02) ; i++)
outb(0xaa, FIFO(pb));
pb->irq = probe_irq_off(irqs);
ECR_WRITE(pb, ECR_SPP << 5);
if (pb->irq <= 0)
pb->irq = PARPORT_IRQ_NONE;
return pb->irq;
}
static int irq_probe_EPP(struct parport *pb)
{
#ifndef ADVANCED_DETECT
return PARPORT_IRQ_NONE;
#else
int irqs;
unsigned char oecr;
if (pb->modes & PARPORT_MODE_PCECR)
oecr = inb(ECONTROL(pb));
irqs = probe_irq_on();
if (pb->modes & PARPORT_MODE_PCECR)
frob_econtrol(pb, 0x10, 0x10);
clear_epp_timeout(pb);
parport_pc_frob_control(pb, 0x20, 0x20);
parport_pc_frob_control(pb, 0x10, 0x10);
clear_epp_timeout(pb);
parport_pc_read_epp(pb);
udelay(20);
pb->irq = probe_irq_off(irqs);
if (pb->modes & PARPORT_MODE_PCECR)
ECR_WRITE(pb, oecr);
parport_pc_write_control(pb, 0xc);
if (pb->irq <= 0)
pb->irq = PARPORT_IRQ_NONE;
return pb->irq;
#endif
}
static int irq_probe_SPP(struct parport *pb)
{
return PARPORT_IRQ_NONE;
}
static int parport_irq_probe(struct parport *pb)
{
struct parport_pc_private *priv = pb->private_data;
if (priv->ecr) {
pb->irq = programmable_irq_support(pb);
if (pb->irq == PARPORT_IRQ_NONE)
pb->irq = irq_probe_ECP(pb);
}
if ((pb->irq == PARPORT_IRQ_NONE) && priv->ecr &&
(pb->modes & PARPORT_MODE_EPP))
pb->irq = irq_probe_EPP(pb);
clear_epp_timeout(pb);
if (pb->irq == PARPORT_IRQ_NONE && (pb->modes & PARPORT_MODE_EPP))
pb->irq = irq_probe_EPP(pb);
clear_epp_timeout(pb);
if (pb->irq == PARPORT_IRQ_NONE)
pb->irq = irq_probe_SPP(pb);
if (pb->irq == PARPORT_IRQ_NONE)
pb->irq = get_superio_irq(pb);
return pb->irq;
}
static int programmable_dma_support(struct parport *p)
{
unsigned char oecr = inb(ECONTROL(p));
int dma;
frob_set_mode(p, ECR_CNF);
dma = inb(CONFIGB(p)) & 0x07;
if ((dma & 0x03) == 0)
dma = PARPORT_DMA_NONE;
ECR_WRITE(p, oecr);
return dma;
}
static int parport_dma_probe(struct parport *p)
{
const struct parport_pc_private *priv = p->private_data;
if (priv->ecr)
p->dma = programmable_dma_support(p);
if (p->dma == PARPORT_DMA_NONE) {
p->dma = get_superio_dma(p);
}
return p->dma;
}
struct parport *parport_pc_probe_port(unsigned long int base,
unsigned long int base_hi,
int irq, int dma,
struct device *dev,
int irqflags)
{
struct parport_pc_private *priv;
struct parport_operations *ops;
struct parport *p;
int probedirq = PARPORT_IRQ_NONE;
struct resource *base_res;
struct resource *ECR_res = NULL;
struct resource *EPP_res = NULL;
struct platform_device *pdev = NULL;
int ret;
if (!dev) {
pdev = platform_device_register_simple("parport_pc",
base, NULL, 0);
if (IS_ERR(pdev))
return NULL;
dev = &pdev->dev;
ret = dma_coerce_mask_and_coherent(dev, DMA_BIT_MASK(24));
if (ret) {
dev_err(dev, "Unable to set coherent dma mask: disabling DMA\n");
dma = PARPORT_DMA_NONE;
}
}
ops = kmalloc(sizeof(struct parport_operations), GFP_KERNEL);
if (!ops)
goto out1;
priv = kmalloc(sizeof(struct parport_pc_private), GFP_KERNEL);
if (!priv)
goto out2;
p = parport_register_port(base, irq, dma, ops);
if (!p)
goto out3;
base_res = request_region(base, 3, p->name);
if (!base_res)
goto out4;
memcpy(ops, &parport_pc_ops, sizeof(struct parport_operations));
priv->ctr = 0xc;
priv->ctr_writable = ~0x10;
priv->ecr = 0;
priv->fifo_depth = 0;
priv->dma_buf = NULL;
priv->dma_handle = 0;
INIT_LIST_HEAD(&priv->list);
priv->port = p;
p->dev = dev;
p->base_hi = base_hi;
p->modes = PARPORT_MODE_PCSPP | PARPORT_MODE_SAFEININT;
p->private_data = priv;
if (base_hi) {
ECR_res = request_region(base_hi, 3, p->name);
if (ECR_res)
parport_ECR_present(p);
}
if (base != 0x3bc) {
EPP_res = request_region(base+0x3, 5, p->name);
if (EPP_res)
if (!parport_EPP_supported(p))
parport_ECPEPP_supported(p);
}
if (!parport_SPP_supported(p))
goto out5;
if (priv->ecr)
parport_ECPPS2_supported(p);
else
parport_PS2_supported(p);
p->size = (p->modes & PARPORT_MODE_EPP) ? 8 : 3;
printk(KERN_INFO "%s: PC-style at 0x%lx", p->name, p->base);
if (p->base_hi && priv->ecr)
printk(KERN_CONT " (0x%lx)", p->base_hi);
if (p->irq == PARPORT_IRQ_AUTO) {
p->irq = PARPORT_IRQ_NONE;
parport_irq_probe(p);
} else if (p->irq == PARPORT_IRQ_PROBEONLY) {
p->irq = PARPORT_IRQ_NONE;
parport_irq_probe(p);
probedirq = p->irq;
p->irq = PARPORT_IRQ_NONE;
}
if (p->irq != PARPORT_IRQ_NONE) {
printk(KERN_CONT ", irq %d", p->irq);
priv->ctr_writable |= 0x10;
if (p->dma == PARPORT_DMA_AUTO) {
p->dma = PARPORT_DMA_NONE;
parport_dma_probe(p);
}
}
if (p->dma == PARPORT_DMA_AUTO)
p->dma = PARPORT_DMA_NONE;
#ifdef CONFIG_PARPORT_PC_FIFO
if (parport_ECP_supported(p) &&
p->dma != PARPORT_DMA_NOFIFO &&
priv->fifo_depth > 0 && p->irq != PARPORT_IRQ_NONE) {
p->modes |= PARPORT_MODE_ECP | PARPORT_MODE_COMPAT;
p->ops->compat_write_data = parport_pc_compat_write_block_pio;
#ifdef CONFIG_PARPORT_1284
p->ops->ecp_write_data = parport_pc_ecp_write_block_pio;
#endif
if (p->dma != PARPORT_DMA_NONE) {
printk(KERN_CONT ", dma %d", p->dma);
p->modes |= PARPORT_MODE_DMA;
} else
printk(KERN_CONT ", using FIFO");
} else
p->dma = PARPORT_DMA_NONE;
#endif
printk(KERN_CONT " [");
#define printmode(x) \
{\
if (p->modes & PARPORT_MODE_##x) {\
printk(KERN_CONT "%s%s", f ? "," : "", #x);\
f++;\
} \
}
{
int f = 0;
printmode(PCSPP);
printmode(TRISTATE);
printmode(COMPAT)
printmode(EPP);
printmode(ECP);
printmode(DMA);
}
#undef printmode
#ifndef CONFIG_PARPORT_1284
printk(KERN_CONT "(,...)");
#endif
printk(KERN_CONT "]\n");
if (probedirq != PARPORT_IRQ_NONE)
printk(KERN_INFO "%s: irq %d detected\n", p->name, probedirq);
if (ECR_res && (p->modes & PARPORT_MODE_ECP) == 0) {
release_region(base_hi, 3);
ECR_res = NULL;
}
if (EPP_res && (p->modes & PARPORT_MODE_EPP) == 0) {
release_region(base+3, 5);
EPP_res = NULL;
}
if (p->irq != PARPORT_IRQ_NONE) {
if (request_irq(p->irq, parport_irq_handler,
irqflags, p->name, p)) {
printk(KERN_WARNING "%s: irq %d in use, "
"resorting to polled operation\n",
p->name, p->irq);
p->irq = PARPORT_IRQ_NONE;
p->dma = PARPORT_DMA_NONE;
}
#ifdef CONFIG_PARPORT_PC_FIFO
#ifdef HAS_DMA
if (p->dma != PARPORT_DMA_NONE) {
if (request_dma(p->dma, p->name)) {
printk(KERN_WARNING "%s: dma %d in use, "
"resorting to PIO operation\n",
p->name, p->dma);
p->dma = PARPORT_DMA_NONE;
} else {
priv->dma_buf =
dma_alloc_coherent(dev,
PAGE_SIZE,
&priv->dma_handle,
GFP_KERNEL);
if (!priv->dma_buf) {
printk(KERN_WARNING "%s: "
"cannot get buffer for DMA, "
"resorting to PIO operation\n",
p->name);
free_dma(p->dma);
p->dma = PARPORT_DMA_NONE;
}
}
}
#endif
#endif
}
if (priv->ecr)
ECR_WRITE(p, 0x34);
parport_pc_write_data(p, 0);
parport_pc_data_forward(p);
spin_lock(&ports_lock);
list_add(&priv->list, &ports_list);
spin_unlock(&ports_lock);
parport_announce_port(p);
return p;
out5:
if (ECR_res)
release_region(base_hi, 3);
if (EPP_res)
release_region(base+0x3, 5);
release_region(base, 3);
out4:
parport_put_port(p);
out3:
kfree(priv);
out2:
kfree(ops);
out1:
if (pdev)
platform_device_unregister(pdev);
return NULL;
}
void parport_pc_unregister_port(struct parport *p)
{
struct parport_pc_private *priv = p->private_data;
struct parport_operations *ops = p->ops;
parport_remove_port(p);
spin_lock(&ports_lock);
list_del_init(&priv->list);
spin_unlock(&ports_lock);
#if defined(CONFIG_PARPORT_PC_FIFO) && defined(HAS_DMA)
if (p->dma != PARPORT_DMA_NONE)
free_dma(p->dma);
#endif
if (p->irq != PARPORT_IRQ_NONE)
free_irq(p->irq, p);
release_region(p->base, 3);
if (p->size > 3)
release_region(p->base + 3, p->size - 3);
if (p->modes & PARPORT_MODE_ECP)
release_region(p->base_hi, 3);
#if defined(CONFIG_PARPORT_PC_FIFO) && defined(HAS_DMA)
if (priv->dma_buf)
dma_free_coherent(p->physport->dev, PAGE_SIZE,
priv->dma_buf,
priv->dma_handle);
#endif
kfree(p->private_data);
parport_put_port(p);
kfree(ops);
}
static int sio_ite_8872_probe(struct pci_dev *pdev, int autoirq, int autodma,
const struct parport_pc_via_data *via)
{
short inta_addr[6] = { 0x2A0, 0x2C0, 0x220, 0x240, 0x1E0 };
u32 ite8872set;
u32 ite8872_lpt, ite8872_lpthi;
u8 ite8872_irq, type;
int irq;
int i;
DPRINTK(KERN_DEBUG "sio_ite_8872_probe()\n");
for (i = 0; i < 5; i++) {
if (request_region(inta_addr[i], 32, "it887x")) {
int test;
pci_write_config_dword(pdev, 0x60,
0xe5000000 | inta_addr[i]);
pci_write_config_dword(pdev, 0x78,
0x00000000 | inta_addr[i]);
test = inb(inta_addr[i]);
if (test != 0xff)
break;
release_region(inta_addr[i], 32);
}
}
if (i >= 5) {
printk(KERN_INFO "parport_pc: cannot find ITE8872 INTA\n");
return 0;
}
type = inb(inta_addr[i] + 0x18);
type &= 0x0f;
switch (type) {
case 0x2:
printk(KERN_INFO "parport_pc: ITE8871 found (1P)\n");
ite8872set = 0x64200000;
break;
case 0xa:
printk(KERN_INFO "parport_pc: ITE8875 found (1P)\n");
ite8872set = 0x64200000;
break;
case 0xe:
printk(KERN_INFO "parport_pc: ITE8872 found (2S1P)\n");
ite8872set = 0x64e00000;
break;
case 0x6:
printk(KERN_INFO "parport_pc: ITE8873 found (1S)\n");
release_region(inta_addr[i], 32);
return 0;
case 0x8:
printk(KERN_INFO "parport_pc: ITE8874 found (2S)\n");
release_region(inta_addr[i], 32);
return 0;
default:
printk(KERN_INFO "parport_pc: unknown ITE887x\n");
printk(KERN_INFO "parport_pc: please mail 'lspci -nvv' "
"output to Rich.Liu@ite.com.tw\n");
release_region(inta_addr[i], 32);
return 0;
}
pci_read_config_byte(pdev, 0x3c, &ite8872_irq);
pci_read_config_dword(pdev, 0x1c, &ite8872_lpt);
ite8872_lpt &= 0x0000ff00;
pci_read_config_dword(pdev, 0x20, &ite8872_lpthi);
ite8872_lpthi &= 0x0000ff00;
pci_write_config_dword(pdev, 0x6c, 0xe3000000 | ite8872_lpt);
pci_write_config_dword(pdev, 0x70, 0xe3000000 | ite8872_lpthi);
pci_write_config_dword(pdev, 0x80, (ite8872_lpthi<<16) | ite8872_lpt);
pci_write_config_dword(pdev, 0x9c,
ite8872set | (ite8872_irq * 0x11111));
DPRINTK(KERN_DEBUG "ITE887x: The IRQ is %d.\n", ite8872_irq);
DPRINTK(KERN_DEBUG "ITE887x: The PARALLEL I/O port is 0x%x.\n",
ite8872_lpt);
DPRINTK(KERN_DEBUG "ITE887x: The PARALLEL I/O porthi is 0x%x.\n",
ite8872_lpthi);
irq = ite8872_irq;
if (autoirq != PARPORT_IRQ_AUTO)
irq = PARPORT_IRQ_NONE;
release_region(inta_addr[i], 32);
if (parport_pc_probe_port(ite8872_lpt, ite8872_lpthi,
irq, PARPORT_DMA_NONE, &pdev->dev, 0)) {
printk(KERN_INFO
"parport_pc: ITE 8872 parallel port: io=0x%X",
ite8872_lpt);
if (irq != PARPORT_IRQ_NONE)
printk(", irq=%d", irq);
printk("\n");
return 1;
}
return 0;
}
static int sio_via_probe(struct pci_dev *pdev, int autoirq, int autodma,
const struct parport_pc_via_data *via)
{
u8 tmp, tmp2, siofunc;
u8 ppcontrol = 0;
int dma, irq;
unsigned port1, port2;
unsigned have_epp = 0;
printk(KERN_DEBUG "parport_pc: VIA 686A/8231 detected\n");
switch (parport_init_mode) {
case 1:
printk(KERN_DEBUG "parport_pc: setting SPP mode\n");
siofunc = VIA_FUNCTION_PARPORT_SPP;
break;
case 2:
printk(KERN_DEBUG "parport_pc: setting PS/2 mode\n");
siofunc = VIA_FUNCTION_PARPORT_SPP;
ppcontrol = VIA_PARPORT_BIDIR;
break;
case 3:
printk(KERN_DEBUG "parport_pc: setting EPP mode\n");
siofunc = VIA_FUNCTION_PARPORT_EPP;
ppcontrol = VIA_PARPORT_BIDIR;
have_epp = 1;
break;
case 4:
printk(KERN_DEBUG "parport_pc: setting ECP mode\n");
siofunc = VIA_FUNCTION_PARPORT_ECP;
ppcontrol = VIA_PARPORT_BIDIR;
break;
case 5:
printk(KERN_DEBUG "parport_pc: setting EPP+ECP mode\n");
siofunc = VIA_FUNCTION_PARPORT_ECP;
ppcontrol = VIA_PARPORT_BIDIR|VIA_PARPORT_ECPEPP;
have_epp = 1;
break;
default:
printk(KERN_DEBUG
"parport_pc: probing current configuration\n");
siofunc = VIA_FUNCTION_PROBE;
break;
}
pci_read_config_byte(pdev, via->via_pci_superio_config_reg, &tmp);
tmp |= via->via_pci_superio_config_data;
pci_write_config_byte(pdev, via->via_pci_superio_config_reg, tmp);
outb(via->viacfg_function, VIA_CONFIG_INDEX);
tmp = inb(VIA_CONFIG_DATA);
outb(via->viacfg_parport_control, VIA_CONFIG_INDEX);
tmp2 = inb(VIA_CONFIG_DATA);
if (siofunc == VIA_FUNCTION_PROBE) {
siofunc = tmp & VIA_FUNCTION_PARPORT_DISABLE;
ppcontrol = tmp2;
} else {
tmp &= ~VIA_FUNCTION_PARPORT_DISABLE;
tmp |= siofunc;
outb(via->viacfg_function, VIA_CONFIG_INDEX);
outb(tmp, VIA_CONFIG_DATA);
tmp2 &= ~(VIA_PARPORT_BIDIR|VIA_PARPORT_ECPEPP);
tmp2 |= ppcontrol;
outb(via->viacfg_parport_control, VIA_CONFIG_INDEX);
outb(tmp2, VIA_CONFIG_DATA);
}
outb(via->viacfg_parport_base, VIA_CONFIG_INDEX);
port1 = inb(VIA_CONFIG_DATA) << 2;
printk(KERN_DEBUG "parport_pc: Current parallel port base: 0x%X\n",
port1);
if (port1 == 0x3BC && have_epp) {
outb(via->viacfg_parport_base, VIA_CONFIG_INDEX);
outb((0x378 >> 2), VIA_CONFIG_DATA);
printk(KERN_DEBUG
"parport_pc: Parallel port base changed to 0x378\n");
port1 = 0x378;
}
pci_read_config_byte(pdev, via->via_pci_superio_config_reg, &tmp);
tmp &= ~via->via_pci_superio_config_data;
pci_write_config_byte(pdev, via->via_pci_superio_config_reg, tmp);
if (siofunc == VIA_FUNCTION_PARPORT_DISABLE) {
printk(KERN_INFO "parport_pc: VIA parallel port disabled in BIOS\n");
return 0;
}
pci_read_config_byte(pdev, via->via_pci_parport_irq_reg, &tmp);
irq = ((tmp & VIA_IRQCONTROL_PARALLEL) >> 4);
if (siofunc == VIA_FUNCTION_PARPORT_ECP) {
pci_read_config_byte(pdev, via->via_pci_parport_dma_reg, &tmp);
dma = ((tmp & VIA_DMACONTROL_PARALLEL) >> 2);
} else
dma = PARPORT_DMA_NONE;
if (autoirq == PARPORT_IRQ_NONE) {
irq = PARPORT_IRQ_NONE;
dma = PARPORT_DMA_NONE;
}
if (autodma == PARPORT_DMA_NONE)
dma = PARPORT_DMA_NONE;
switch (port1) {
case 0x3bc:
port2 = 0x7bc; break;
case 0x378:
port2 = 0x778; break;
case 0x278:
port2 = 0x678; break;
default:
printk(KERN_INFO
"parport_pc: Weird VIA parport base 0x%X, ignoring\n",
port1);
return 0;
}
switch (irq) {
case 0:
case 2:
case 8:
case 13:
irq = PARPORT_IRQ_NONE;
break;
default:
break;
}
if (parport_pc_probe_port(port1, port2, irq, dma, &pdev->dev, 0)) {
printk(KERN_INFO
"parport_pc: VIA parallel port: io=0x%X", port1);
if (irq != PARPORT_IRQ_NONE)
printk(", irq=%d", irq);
if (dma != PARPORT_DMA_NONE)
printk(", dma=%d", dma);
printk("\n");
return 1;
}
printk(KERN_WARNING "parport_pc: Strange, can't probe VIA parallel port: io=0x%X, irq=%d, dma=%d\n",
port1, irq, dma);
return 0;
}
static int parport_pc_pci_probe(struct pci_dev *dev,
const struct pci_device_id *id)
{
int err, count, n, i = id->driver_data;
struct pci_parport_data *data;
if (i < last_sio)
return 0;
i -= last_sio;
count = 0;
err = pci_enable_device(dev);
if (err)
return err;
data = kmalloc(sizeof(struct pci_parport_data), GFP_KERNEL);
if (!data)
return -ENOMEM;
if (cards[i].preinit_hook &&
cards[i].preinit_hook(dev, PARPORT_IRQ_NONE, PARPORT_DMA_NONE)) {
kfree(data);
return -ENODEV;
}
for (n = 0; n < cards[i].numports; n++) {
int lo = cards[i].addr[n].lo;
int hi = cards[i].addr[n].hi;
int irq;
unsigned long io_lo, io_hi;
io_lo = pci_resource_start(dev, lo);
io_hi = 0;
if ((hi >= 0) && (hi <= 6))
io_hi = pci_resource_start(dev, hi);
else if (hi > 6)
io_lo += hi;
irq = dev->irq;
if (irq == IRQ_NONE) {
printk(KERN_DEBUG
"PCI parallel port detected: %04x:%04x, I/O at %#lx(%#lx)\n",
parport_pc_pci_tbl[i + last_sio].vendor,
parport_pc_pci_tbl[i + last_sio].device,
io_lo, io_hi);
irq = PARPORT_IRQ_NONE;
} else {
printk(KERN_DEBUG
"PCI parallel port detected: %04x:%04x, I/O at %#lx(%#lx), IRQ %d\n",
parport_pc_pci_tbl[i + last_sio].vendor,
parport_pc_pci_tbl[i + last_sio].device,
io_lo, io_hi, irq);
}
data->ports[count] =
parport_pc_probe_port(io_lo, io_hi, irq,
PARPORT_DMA_NONE, &dev->dev,
IRQF_SHARED);
if (data->ports[count])
count++;
}
data->num = count;
if (cards[i].postinit_hook)
cards[i].postinit_hook(dev, count == 0);
if (count) {
pci_set_drvdata(dev, data);
return 0;
}
kfree(data);
return -ENODEV;
}
static void parport_pc_pci_remove(struct pci_dev *dev)
{
struct pci_parport_data *data = pci_get_drvdata(dev);
int i;
pci_set_drvdata(dev, NULL);
if (data) {
for (i = data->num - 1; i >= 0; i--)
parport_pc_unregister_port(data->ports[i]);
kfree(data);
}
}
static int __init parport_pc_init_superio(int autoirq, int autodma)
{
const struct pci_device_id *id;
struct pci_dev *pdev = NULL;
int ret = 0;
for_each_pci_dev(pdev) {
id = pci_match_id(parport_pc_pci_tbl, pdev);
if (id == NULL || id->driver_data >= last_sio)
continue;
if (parport_pc_superio_info[id->driver_data].probe(
pdev, autoirq, autodma,
parport_pc_superio_info[id->driver_data].via)) {
ret++;
}
}
return ret;
}
static int __init parport_pc_init_superio(int autoirq, int autodma)
{
return 0;
}
static int parport_pc_pnp_probe(struct pnp_dev *dev,
const struct pnp_device_id *id)
{
struct parport *pdata;
unsigned long io_lo, io_hi;
int dma, irq;
if (pnp_port_valid(dev, 0) &&
!(pnp_port_flags(dev, 0) & IORESOURCE_DISABLED)) {
io_lo = pnp_port_start(dev, 0);
} else
return -EINVAL;
if (pnp_port_valid(dev, 1) &&
!(pnp_port_flags(dev, 1) & IORESOURCE_DISABLED)) {
io_hi = pnp_port_start(dev, 1);
} else
io_hi = 0;
if (pnp_irq_valid(dev, 0) &&
!(pnp_irq_flags(dev, 0) & IORESOURCE_DISABLED)) {
irq = pnp_irq(dev, 0);
} else
irq = PARPORT_IRQ_NONE;
if (pnp_dma_valid(dev, 0) &&
!(pnp_dma_flags(dev, 0) & IORESOURCE_DISABLED)) {
dma = pnp_dma(dev, 0);
} else
dma = PARPORT_DMA_NONE;
dev_info(&dev->dev, "reported by %s\n", dev->protocol->name);
pdata = parport_pc_probe_port(io_lo, io_hi, irq, dma, &dev->dev, 0);
if (pdata == NULL)
return -ENODEV;
pnp_set_drvdata(dev, pdata);
return 0;
}
static void parport_pc_pnp_remove(struct pnp_dev *dev)
{
struct parport *pdata = (struct parport *)pnp_get_drvdata(dev);
if (!pdata)
return;
parport_pc_unregister_port(pdata);
}
static int parport_pc_platform_probe(struct platform_device *pdev)
{
return 0;
}
static void __init parport_pc_find_ports(int autoirq, int autodma)
{
int count = 0, err;
#ifdef CONFIG_PARPORT_PC_SUPERIO
detect_and_report_it87();
detect_and_report_winbond();
detect_and_report_smsc();
#endif
count += parport_pc_init_superio(autoirq, autodma);
if (!count) {
err = pnp_register_driver(&parport_pc_pnp_driver);
if (!err)
pnp_registered_parport = 1;
}
parport_pc_find_nonpci_ports(autoirq, autodma);
err = pci_register_driver(&parport_pc_pci_driver);
if (!err)
pci_registered_parport = 1;
}
static int __init parport_parse_param(const char *s, int *val,
int automatic, int none, int nofifo)
{
if (!s)
return 0;
if (!strncmp(s, "auto", 4))
*val = automatic;
else if (!strncmp(s, "none", 4))
*val = none;
else if (nofifo && !strncmp(s, "nofifo", 6))
*val = nofifo;
else {
char *ep;
unsigned long r = simple_strtoul(s, &ep, 0);
if (ep != s)
*val = r;
else {
printk(KERN_ERR "parport: bad specifier `%s'\n", s);
return -1;
}
}
return 0;
}
static int __init parport_parse_irq(const char *irqstr, int *val)
{
return parport_parse_param(irqstr, val, PARPORT_IRQ_AUTO,
PARPORT_IRQ_NONE, 0);
}
static int __init parport_parse_dma(const char *dmastr, int *val)
{
return parport_parse_param(dmastr, val, PARPORT_DMA_AUTO,
PARPORT_DMA_NONE, PARPORT_DMA_NOFIFO);
}
static int __init parport_init_mode_setup(char *str)
{
printk(KERN_DEBUG
"parport_pc.c: Specified parameter parport_init_mode=%s\n", str);
if (!strcmp(str, "spp"))
parport_init_mode = 1;
if (!strcmp(str, "ps2"))
parport_init_mode = 2;
if (!strcmp(str, "epp"))
parport_init_mode = 3;
if (!strcmp(str, "ecp"))
parport_init_mode = 4;
if (!strcmp(str, "ecpepp"))
parport_init_mode = 5;
return 1;
}
static int __init parse_parport_params(void)
{
unsigned int i;
int val;
#ifdef CONFIG_PCI
if (init_mode)
parport_init_mode_setup(init_mode);
#endif
for (i = 0; i < PARPORT_PC_MAX_PORTS && io[i]; i++) {
if (parport_parse_irq(irq[i], &val))
return 1;
irqval[i] = val;
if (parport_parse_dma(dma[i], &val))
return 1;
dmaval[i] = val;
}
if (!io[0]) {
if (irq[0] && !parport_parse_irq(irq[0], &val))
switch (val) {
case PARPORT_IRQ_NONE:
case PARPORT_IRQ_AUTO:
irqval[0] = val;
break;
default:
printk(KERN_WARNING
"parport_pc: irq specified "
"without base address. Use 'io=' "
"to specify one\n");
}
if (dma[0] && !parport_parse_dma(dma[0], &val))
switch (val) {
case PARPORT_DMA_NONE:
case PARPORT_DMA_AUTO:
dmaval[0] = val;
break;
default:
printk(KERN_WARNING
"parport_pc: dma specified "
"without base address. Use 'io=' "
"to specify one\n");
}
}
return 0;
}
static int __init parport_setup(char *str)
{
char *endptr;
char *sep;
int val;
if (!str || !*str || (*str == '0' && !*(str+1))) {
io[0] = PARPORT_DISABLE;
return 1;
}
if (!strncmp(str, "auto", 4)) {
irqval[0] = PARPORT_IRQ_AUTO;
dmaval[0] = PARPORT_DMA_AUTO;
return 1;
}
val = simple_strtoul(str, &endptr, 0);
if (endptr == str) {
printk(KERN_WARNING "parport=%s not understood\n", str);
return 1;
}
if (parport_setup_ptr == PARPORT_PC_MAX_PORTS) {
printk(KERN_ERR "parport=%s ignored, too many ports\n", str);
return 1;
}
io[parport_setup_ptr] = val;
irqval[parport_setup_ptr] = PARPORT_IRQ_NONE;
dmaval[parport_setup_ptr] = PARPORT_DMA_NONE;
sep = strchr(str, ',');
if (sep++) {
if (parport_parse_irq(sep, &val))
return 1;
irqval[parport_setup_ptr] = val;
sep = strchr(sep, ',');
if (sep++) {
if (parport_parse_dma(sep, &val))
return 1;
dmaval[parport_setup_ptr] = val;
}
}
parport_setup_ptr++;
return 1;
}
static int __init parse_parport_params(void)
{
return io[0] == PARPORT_DISABLE;
}
static int __init parport_pc_init(void)
{
int err;
if (parse_parport_params())
return -EINVAL;
err = platform_driver_register(&parport_pc_platform_driver);
if (err)
return err;
if (io[0]) {
int i;
user_specified = 1;
for (i = 0; i < PARPORT_PC_MAX_PORTS; i++) {
if (!io[i])
break;
if (io_hi[i] == PARPORT_IOHI_AUTO)
io_hi[i] = 0x400 + io[i];
parport_pc_probe_port(io[i], io_hi[i],
irqval[i], dmaval[i], NULL, 0);
}
} else
parport_pc_find_ports(irqval[0], dmaval[0]);
return 0;
}
static void __exit parport_pc_exit(void)
{
if (pci_registered_parport)
pci_unregister_driver(&parport_pc_pci_driver);
if (pnp_registered_parport)
pnp_unregister_driver(&parport_pc_pnp_driver);
platform_driver_unregister(&parport_pc_platform_driver);
while (!list_empty(&ports_list)) {
struct parport_pc_private *priv;
struct parport *port;
priv = list_entry(ports_list.next,
struct parport_pc_private, list);
port = priv->port;
if (port->dev && port->dev->bus == &platform_bus_type)
platform_device_unregister(
to_platform_device(port->dev));
parport_pc_unregister_port(port);
}
}
