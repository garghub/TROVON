static void memwinon(struct board_info *b, unsigned int win)
{
b->memwinon(b, win);
}
static void memwinoff(struct board_info *b, unsigned int win)
{
b->memwinoff(b, win);
}
static void globalwinon(struct channel *ch)
{
ch->board->globalwinon(ch);
}
static void rxwinon(struct channel *ch)
{
ch->board->rxwinon(ch);
}
static void txwinon(struct channel *ch)
{
ch->board->txwinon(ch);
}
static void memoff(struct channel *ch)
{
ch->board->memoff(ch);
}
static void assertgwinon(struct channel *ch)
{
ch->board->assertgwinon(ch);
}
static void assertmemoff(struct channel *ch)
{
ch->board->assertmemoff(ch);
}
static void pcxem_memwinon(struct board_info *b, unsigned int win)
{
outb_p(FEPWIN | win, b->port + 1);
}
static void pcxem_memwinoff(struct board_info *b, unsigned int win)
{
outb_p(0, b->port + 1);
}
static void pcxem_globalwinon(struct channel *ch)
{
outb_p(FEPWIN, (int)ch->board->port + 1);
}
static void pcxem_rxwinon(struct channel *ch)
{
outb_p(ch->rxwin, (int)ch->board->port + 1);
}
static void pcxem_txwinon(struct channel *ch)
{
outb_p(ch->txwin, (int)ch->board->port + 1);
}
static void pcxem_memoff(struct channel *ch)
{
outb_p(0, (int)ch->board->port + 1);
}
static void pcxe_memwinon(struct board_info *b, unsigned int win)
{
outb_p(FEPWIN | win, b->port + 1);
}
static void pcxe_memwinoff(struct board_info *b, unsigned int win)
{
outb_p(inb(b->port) & ~FEPMEM, b->port + 1);
outb_p(0, b->port + 1);
}
static void pcxe_globalwinon(struct channel *ch)
{
outb_p(FEPWIN, (int)ch->board->port + 1);
}
static void pcxe_rxwinon(struct channel *ch)
{
outb_p(ch->rxwin, (int)ch->board->port + 1);
}
static void pcxe_txwinon(struct channel *ch)
{
outb_p(ch->txwin, (int)ch->board->port + 1);
}
static void pcxe_memoff(struct channel *ch)
{
outb_p(0, (int)ch->board->port);
outb_p(0, (int)ch->board->port + 1);
}
static void pcxi_memwinon(struct board_info *b, unsigned int win)
{
outb_p(inb(b->port) | FEPMEM, b->port);
}
static void pcxi_memwinoff(struct board_info *b, unsigned int win)
{
outb_p(inb(b->port) & ~FEPMEM, b->port);
}
static void pcxi_globalwinon(struct channel *ch)
{
outb_p(FEPMEM, ch->board->port);
}
static void pcxi_rxwinon(struct channel *ch)
{
outb_p(FEPMEM, ch->board->port);
}
static void pcxi_txwinon(struct channel *ch)
{
outb_p(FEPMEM, ch->board->port);
}
static void pcxi_memoff(struct channel *ch)
{
outb_p(0, ch->board->port);
}
static void pcxi_assertgwinon(struct channel *ch)
{
epcaassert(inb(ch->board->port) & FEPMEM, "Global memory off");
}
static void pcxi_assertmemoff(struct channel *ch)
{
epcaassert(!(inb(ch->board->port) & FEPMEM), "Memory on");
}
static void dummy_memwinon(struct board_info *b, unsigned int win)
{
}
static void dummy_memwinoff(struct board_info *b, unsigned int win)
{
}
static void dummy_globalwinon(struct channel *ch)
{
}
static void dummy_rxwinon(struct channel *ch)
{
}
static void dummy_txwinon(struct channel *ch)
{
}
static void dummy_memoff(struct channel *ch)
{
}
static void dummy_assertgwinon(struct channel *ch)
{
}
static void dummy_assertmemoff(struct channel *ch)
{
}
static struct channel *verifyChannel(struct tty_struct *tty)
{
if (tty) {
struct channel *ch = tty->driver_data;
if (ch >= &digi_channels[0] && ch < &digi_channels[nbdevs]) {
if (ch->magic == EPCA_MAGIC)
return ch;
}
}
return NULL;
}
static void pc_sched_event(struct channel *ch, int event)
{
ch->event |= 1 << event;
schedule_work(&ch->tqueue);
}
static void epca_error(int line, char *msg)
{
printk(KERN_ERR "epca_error (Digi): line = %d %s\n", line, msg);
}
static void pc_close(struct tty_struct *tty, struct file *filp)
{
struct channel *ch;
struct tty_port *port;
ch = verifyChannel(tty);
if (ch == NULL)
return;
port = &ch->port;
if (tty_port_close_start(port, tty, filp) == 0)
return;
pc_flush_buffer(tty);
shutdown(ch, tty);
tty_port_close_end(port, tty);
ch->event = 0;
tty_port_tty_set(port, NULL);
}
static void shutdown(struct channel *ch, struct tty_struct *tty)
{
unsigned long flags;
struct board_chan __iomem *bc;
struct tty_port *port = &ch->port;
if (!(port->flags & ASYNC_INITIALIZED))
return;
spin_lock_irqsave(&epca_lock, flags);
globalwinon(ch);
bc = ch->brdchan;
if (bc)
writeb(0, &bc->idata);
if (tty->termios->c_cflag & HUPCL) {
ch->omodem &= ~(ch->m_rts | ch->m_dtr);
fepcmd(ch, SETMODEM, 0, ch->m_dtr | ch->m_rts, 10, 1);
}
memoff(ch);
port->flags &= ~ASYNC_INITIALIZED;
spin_unlock_irqrestore(&epca_lock, flags);
}
static void pc_hangup(struct tty_struct *tty)
{
struct channel *ch;
ch = verifyChannel(tty);
if (ch != NULL) {
pc_flush_buffer(tty);
tty_ldisc_flush(tty);
shutdown(ch, tty);
ch->event = 0;
tty_port_hangup(&ch->port);
}
}
static int pc_write(struct tty_struct *tty,
const unsigned char *buf, int bytesAvailable)
{
unsigned int head, tail;
int dataLen;
int size;
int amountCopied;
struct channel *ch;
unsigned long flags;
int remain;
struct board_chan __iomem *bc;
ch = verifyChannel(tty);
if (ch == NULL)
return 0;
bc = ch->brdchan;
size = ch->txbufsize;
amountCopied = 0;
spin_lock_irqsave(&epca_lock, flags);
globalwinon(ch);
head = readw(&bc->tin) & (size - 1);
tail = readw(&bc->tout);
if (tail != readw(&bc->tout))
tail = readw(&bc->tout);
tail &= (size - 1);
if (head >= tail) {
dataLen = size - head;
remain = size - (head - tail) - 1;
} else {
remain = tail - head - 1;
dataLen = remain;
}
bytesAvailable = min(remain, bytesAvailable);
txwinon(ch);
while (bytesAvailable > 0) {
dataLen = min(bytesAvailable, dataLen);
memcpy_toio(ch->txptr + head, buf, dataLen);
buf += dataLen;
head += dataLen;
amountCopied += dataLen;
bytesAvailable -= dataLen;
if (head >= size) {
head = 0;
dataLen = tail;
}
}
ch->statusflags |= TXBUSY;
globalwinon(ch);
writew(head, &bc->tin);
if ((ch->statusflags & LOWWAIT) == 0) {
ch->statusflags |= LOWWAIT;
writeb(1, &bc->ilow);
}
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
return amountCopied;
}
static int pc_write_room(struct tty_struct *tty)
{
int remain = 0;
struct channel *ch;
unsigned long flags;
unsigned int head, tail;
struct board_chan __iomem *bc;
ch = verifyChannel(tty);
if (ch != NULL) {
spin_lock_irqsave(&epca_lock, flags);
globalwinon(ch);
bc = ch->brdchan;
head = readw(&bc->tin) & (ch->txbufsize - 1);
tail = readw(&bc->tout);
if (tail != readw(&bc->tout))
tail = readw(&bc->tout);
tail &= (ch->txbufsize - 1);
remain = tail - head - 1;
if (remain < 0)
remain += ch->txbufsize;
if (remain && (ch->statusflags & LOWWAIT) == 0) {
ch->statusflags |= LOWWAIT;
writeb(1, &bc->ilow);
}
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
}
return remain;
}
static int pc_chars_in_buffer(struct tty_struct *tty)
{
int chars;
unsigned int ctail, head, tail;
int remain;
unsigned long flags;
struct channel *ch;
struct board_chan __iomem *bc;
ch = verifyChannel(tty);
if (ch == NULL)
return 0;
spin_lock_irqsave(&epca_lock, flags);
globalwinon(ch);
bc = ch->brdchan;
tail = readw(&bc->tout);
head = readw(&bc->tin);
ctail = readw(&ch->mailbox->cout);
if (tail == head && readw(&ch->mailbox->cin) == ctail &&
readb(&bc->tbusy) == 0)
chars = 0;
else {
head = readw(&bc->tin) & (ch->txbufsize - 1);
tail &= (ch->txbufsize - 1);
remain = tail - head - 1;
if (remain < 0)
remain += ch->txbufsize;
chars = (int)(ch->txbufsize - remain);
if (!(ch->statusflags & EMPTYWAIT))
setup_empty_event(tty, ch);
}
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
return chars;
}
static void pc_flush_buffer(struct tty_struct *tty)
{
unsigned int tail;
unsigned long flags;
struct channel *ch;
struct board_chan __iomem *bc;
ch = verifyChannel(tty);
if (ch == NULL)
return;
spin_lock_irqsave(&epca_lock, flags);
globalwinon(ch);
bc = ch->brdchan;
tail = readw(&bc->tout);
fepcmd(ch, STOUT, (unsigned) tail, 0, 0, 0);
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
tty_wakeup(tty);
}
static void pc_flush_chars(struct tty_struct *tty)
{
struct channel *ch;
ch = verifyChannel(tty);
if (ch != NULL) {
unsigned long flags;
spin_lock_irqsave(&epca_lock, flags);
if ((ch->statusflags & TXBUSY) &&
!(ch->statusflags & EMPTYWAIT))
setup_empty_event(tty, ch);
spin_unlock_irqrestore(&epca_lock, flags);
}
}
static int epca_carrier_raised(struct tty_port *port)
{
struct channel *ch = container_of(port, struct channel, port);
if (ch->imodem & ch->dcd)
return 1;
return 0;
}
static void epca_dtr_rts(struct tty_port *port, int onoff)
{
}
static int pc_open(struct tty_struct *tty, struct file *filp)
{
struct channel *ch;
struct tty_port *port;
unsigned long flags;
int line, retval, boardnum;
struct board_chan __iomem *bc;
unsigned int head;
line = tty->index;
if (line < 0 || line >= nbdevs)
return -ENODEV;
ch = &digi_channels[line];
port = &ch->port;
boardnum = ch->boardnum;
if (invalid_lilo_config) {
if (setup_error_code & INVALID_BOARD_TYPE)
printk(KERN_ERR "epca: pc_open: Invalid board type specified in kernel options.\n");
if (setup_error_code & INVALID_NUM_PORTS)
printk(KERN_ERR "epca: pc_open: Invalid number of ports specified in kernel options.\n");
if (setup_error_code & INVALID_MEM_BASE)
printk(KERN_ERR "epca: pc_open: Invalid board memory address specified in kernel options.\n");
if (setup_error_code & INVALID_PORT_BASE)
printk(KERN_ERR "epca; pc_open: Invalid board port address specified in kernel options.\n");
if (setup_error_code & INVALID_BOARD_STATUS)
printk(KERN_ERR "epca: pc_open: Invalid board status specified in kernel options.\n");
if (setup_error_code & INVALID_ALTPIN)
printk(KERN_ERR "epca: pc_open: Invalid board altpin specified in kernel options;\n");
tty->driver_data = NULL;
return -ENODEV;
}
if (boardnum >= num_cards || boards[boardnum].status == DISABLED) {
tty->driver_data = NULL;
return(-ENODEV);
}
bc = ch->brdchan;
if (bc == NULL) {
tty->driver_data = NULL;
return -ENODEV;
}
spin_lock_irqsave(&port->lock, flags);
port->count++;
tty->driver_data = ch;
port->tty = tty;
spin_lock(&epca_lock);
globalwinon(ch);
ch->statusflags = 0;
ch->imodem = readb(&bc->mstat);
head = readw(&bc->rin);
writew(head, &bc->rout);
epcaparam(tty, ch);
memoff(ch);
spin_unlock(&epca_lock);
port->flags |= ASYNC_INITIALIZED;
spin_unlock_irqrestore(&port->lock, flags);
retval = tty_port_block_til_ready(port, tty, filp);
if (retval)
return retval;
spin_lock_irqsave(&port->lock, flags);
port->tty = tty;
spin_lock(&epca_lock);
globalwinon(ch);
writeb(1, &bc->idata);
memoff(ch);
spin_unlock(&epca_lock);
spin_unlock_irqrestore(&port->lock, flags);
return 0;
}
static int __init epca_module_init(void)
{
return pc_init();
}
static void __exit epca_module_exit(void)
{
int count, crd;
struct board_info *bd;
struct channel *ch;
del_timer_sync(&epca_timer);
if (tty_unregister_driver(pc_driver) ||
tty_unregister_driver(pc_info)) {
printk(KERN_WARNING "epca: cleanup_module failed to un-register tty driver\n");
return;
}
put_tty_driver(pc_driver);
put_tty_driver(pc_info);
for (crd = 0; crd < num_cards; crd++) {
bd = &boards[crd];
if (!bd) {
printk(KERN_ERR "<Error> - Digi : cleanup_module failed\n");
return;
}
ch = card_ptr[crd];
for (count = 0; count < bd->numports; count++, ch++) {
struct tty_struct *tty = tty_port_tty_get(&ch->port);
if (tty) {
tty_hangup(tty);
tty_kref_put(tty);
}
}
}
pci_unregister_driver(&epca_driver);
}
static int info_open(struct tty_struct *tty, struct file *filp)
{
return 0;
}
static int __init pc_init(void)
{
int crd;
struct board_info *bd;
unsigned char board_id = 0;
int err = -ENOMEM;
int pci_boards_found, pci_count;
pci_count = 0;
pc_driver = alloc_tty_driver(MAX_ALLOC);
if (!pc_driver)
goto out1;
pc_info = alloc_tty_driver(MAX_ALLOC);
if (!pc_info)
goto out2;
if (!liloconfig) {
nbdevs = NBDEVS;
num_cards = NUMCARDS;
memcpy(&boards, &static_boards,
sizeof(struct board_info) * NUMCARDS);
}
printk(KERN_INFO "DIGI epca driver version %s loaded.\n", VERSION);
pci_boards_found = 0;
if (num_cards < MAXBOARDS)
pci_boards_found += init_PCI();
num_cards += pci_boards_found;
pc_driver->owner = THIS_MODULE;
pc_driver->name = "ttyD";
pc_driver->major = DIGI_MAJOR;
pc_driver->minor_start = 0;
pc_driver->type = TTY_DRIVER_TYPE_SERIAL;
pc_driver->subtype = SERIAL_TYPE_NORMAL;
pc_driver->init_termios = tty_std_termios;
pc_driver->init_termios.c_iflag = 0;
pc_driver->init_termios.c_oflag = 0;
pc_driver->init_termios.c_cflag = B9600 | CS8 | CREAD | CLOCAL | HUPCL;
pc_driver->init_termios.c_lflag = 0;
pc_driver->init_termios.c_ispeed = 9600;
pc_driver->init_termios.c_ospeed = 9600;
pc_driver->flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_HARDWARE_BREAK;
tty_set_operations(pc_driver, &pc_ops);
pc_info->owner = THIS_MODULE;
pc_info->name = "digi_ctl";
pc_info->major = DIGIINFOMAJOR;
pc_info->minor_start = 0;
pc_info->type = TTY_DRIVER_TYPE_SERIAL;
pc_info->subtype = SERIAL_TYPE_INFO;
pc_info->init_termios = tty_std_termios;
pc_info->init_termios.c_iflag = 0;
pc_info->init_termios.c_oflag = 0;
pc_info->init_termios.c_lflag = 0;
pc_info->init_termios.c_cflag = B9600 | CS8 | CREAD | HUPCL;
pc_info->init_termios.c_ispeed = 9600;
pc_info->init_termios.c_ospeed = 9600;
pc_info->flags = TTY_DRIVER_REAL_RAW;
tty_set_operations(pc_info, &info_ops);
for (crd = 0; crd < num_cards; crd++) {
bd = &boards[crd];
switch (bd->type) {
case PCXEM:
case EISAXEM:
bd->memwinon = pcxem_memwinon;
bd->memwinoff = pcxem_memwinoff;
bd->globalwinon = pcxem_globalwinon;
bd->txwinon = pcxem_txwinon;
bd->rxwinon = pcxem_rxwinon;
bd->memoff = pcxem_memoff;
bd->assertgwinon = dummy_assertgwinon;
bd->assertmemoff = dummy_assertmemoff;
break;
case PCIXEM:
case PCIXRJ:
case PCIXR:
bd->memwinon = dummy_memwinon;
bd->memwinoff = dummy_memwinoff;
bd->globalwinon = dummy_globalwinon;
bd->txwinon = dummy_txwinon;
bd->rxwinon = dummy_rxwinon;
bd->memoff = dummy_memoff;
bd->assertgwinon = dummy_assertgwinon;
bd->assertmemoff = dummy_assertmemoff;
break;
case PCXE:
case PCXEVE:
bd->memwinon = pcxe_memwinon;
bd->memwinoff = pcxe_memwinoff;
bd->globalwinon = pcxe_globalwinon;
bd->txwinon = pcxe_txwinon;
bd->rxwinon = pcxe_rxwinon;
bd->memoff = pcxe_memoff;
bd->assertgwinon = dummy_assertgwinon;
bd->assertmemoff = dummy_assertmemoff;
break;
case PCXI:
case PC64XE:
bd->memwinon = pcxi_memwinon;
bd->memwinoff = pcxi_memwinoff;
bd->globalwinon = pcxi_globalwinon;
bd->txwinon = pcxi_txwinon;
bd->rxwinon = pcxi_rxwinon;
bd->memoff = pcxi_memoff;
bd->assertgwinon = pcxi_assertgwinon;
bd->assertmemoff = pcxi_assertmemoff;
break;
default:
break;
}
switch (bd->type) {
case PCXE:
case PCXEVE:
case PC64XE:
bd->memory_seg = 0xf000;
break;
case PCXI:
board_id = inb((int)bd->port);
if ((board_id & 0x1) == 0x1) {
if ((board_id & 0x30) == 0)
bd->memory_seg = 0xf000;
if ((board_id & 0x30) == 0x10)
bd->memory_seg = 0xe000;
if ((board_id & 0x30) == 0x20)
bd->memory_seg = 0xc000;
if ((board_id & 0x30) == 0x30)
bd->memory_seg = 0x8000;
} else
printk(KERN_ERR "epca: Board at 0x%x doesn't appear to be an XI\n", (int)bd->port);
break;
}
}
err = tty_register_driver(pc_driver);
if (err) {
printk(KERN_ERR "Couldn't register Digi PC/ driver");
goto out3;
}
err = tty_register_driver(pc_info);
if (err) {
printk(KERN_ERR "Couldn't register Digi PC/ info ");
goto out4;
}
init_timer(&epca_timer);
epca_timer.function = epcapoll;
mod_timer(&epca_timer, jiffies + HZ/25);
return 0;
out4:
tty_unregister_driver(pc_driver);
out3:
put_tty_driver(pc_info);
out2:
put_tty_driver(pc_driver);
out1:
return err;
}
static void post_fep_init(unsigned int crd)
{
int i;
void __iomem *memaddr;
struct global_data __iomem *gd;
struct board_info *bd;
struct board_chan __iomem *bc;
struct channel *ch;
int shrinkmem = 0, lowwater;
bd = &boards[crd];
if (bd->type >= PCIXEM) {
bd->numports = readw(bd->re_map_membase + XEMPORTS);
epcaassert(bd->numports <= 64, "PCI returned a invalid number of ports");
nbdevs += (bd->numports);
} else {
bd->re_map_membase = ioremap_nocache(bd->membase, 0x10000);
}
if (crd != 0)
card_ptr[crd] = card_ptr[crd-1] + boards[crd-1].numports;
else
card_ptr[crd] = &digi_channels[crd];
ch = card_ptr[crd];
epcaassert(ch <= &digi_channels[nbdevs - 1], "ch out of range");
memaddr = bd->re_map_membase;
bc = memaddr + CHANSTRUCT;
gd = memaddr + GLOBAL;
if ((bd->type == PCXEVE || bd->type == PCXE) &&
(readw(memaddr + XEPORTS) < 3))
shrinkmem = 1;
if (bd->type < PCIXEM)
if (!request_region((int)bd->port, 4, board_desc[bd->type]))
return;
memwinon(bd, 0);
for (i = 0; i < bd->numports; i++, ch++, bc++) {
unsigned long flags;
u16 tseg, rseg;
tty_port_init(&ch->port);
ch->port.ops = &epca_port_ops;
ch->brdchan = bc;
ch->mailbox = gd;
INIT_WORK(&ch->tqueue, do_softint);
ch->board = &boards[crd];
spin_lock_irqsave(&epca_lock, flags);
switch (bd->type) {
case EISAXEM:
case PCXEM:
case PCIXEM:
case PCIXRJ:
case PCIXR:
ch->m_rts = 0x02;
ch->m_dcd = 0x80;
ch->m_dsr = 0x20;
ch->m_cts = 0x10;
ch->m_ri = 0x40;
ch->m_dtr = 0x01;
break;
case PCXE:
case PCXEVE:
case PCXI:
case PC64XE:
ch->m_rts = 0x02;
ch->m_dcd = 0x08;
ch->m_dsr = 0x10;
ch->m_cts = 0x20;
ch->m_ri = 0x40;
ch->m_dtr = 0x80;
break;
}
if (boards[crd].altpin) {
ch->dsr = ch->m_dcd;
ch->dcd = ch->m_dsr;
ch->digiext.digi_flags |= DIGI_ALTPIN;
} else {
ch->dcd = ch->m_dcd;
ch->dsr = ch->m_dsr;
}
ch->boardnum = crd;
ch->channelnum = i;
ch->magic = EPCA_MAGIC;
tty_port_tty_set(&ch->port, NULL);
if (shrinkmem) {
fepcmd(ch, SETBUFFER, 32, 0, 0, 0);
shrinkmem = 0;
}
tseg = readw(&bc->tseg);
rseg = readw(&bc->rseg);
switch (bd->type) {
case PCIXEM:
case PCIXRJ:
case PCIXR:
ch->txptr = memaddr + ((tseg << 4) & 0x1fffff);
ch->rxptr = memaddr + ((rseg << 4) & 0x1fffff);
ch->txwin = FEPWIN | (tseg >> 11);
ch->rxwin = FEPWIN | (rseg >> 11);
break;
case PCXEM:
case EISAXEM:
ch->txptr = memaddr + ((tseg << 4) & 0x7fff);
ch->rxptr = memaddr + ((rseg << 4) & 0x7fff);
ch->txwin = FEPWIN | (tseg >> 11);
ch->rxwin = FEPWIN | (rseg >> 11);
break;
case PCXEVE:
case PCXE:
ch->txptr = memaddr + (((tseg - bd->memory_seg) << 4)
& 0x1fff);
ch->txwin = FEPWIN | ((tseg - bd->memory_seg) >> 9);
ch->rxptr = memaddr + (((rseg - bd->memory_seg) << 4)
& 0x1fff);
ch->rxwin = FEPWIN | ((rseg - bd->memory_seg) >> 9);
break;
case PCXI:
case PC64XE:
ch->txptr = memaddr + ((tseg - bd->memory_seg) << 4);
ch->rxptr = memaddr + ((rseg - bd->memory_seg) << 4);
ch->txwin = ch->rxwin = 0;
break;
}
ch->txbufhead = 0;
ch->txbufsize = readw(&bc->tmax) + 1;
ch->rxbufhead = 0;
ch->rxbufsize = readw(&bc->rmax) + 1;
lowwater = ch->txbufsize >= 2000 ? 1024 : (ch->txbufsize / 2);
fepcmd(ch, STXLWATER, lowwater, 0, 10, 0);
fepcmd(ch, SRXLWATER, (ch->rxbufsize / 4), 0, 10, 0);
fepcmd(ch, SRXHWATER, (3 * ch->rxbufsize / 4), 0, 10, 0);
writew(100, &bc->edelay);
writeb(1, &bc->idata);
ch->startc = readb(&bc->startc);
ch->stopc = readb(&bc->stopc);
ch->startca = readb(&bc->startca);
ch->stopca = readb(&bc->stopca);
ch->fepcflag = 0;
ch->fepiflag = 0;
ch->fepoflag = 0;
ch->fepstartc = 0;
ch->fepstopc = 0;
ch->fepstartca = 0;
ch->fepstopca = 0;
ch->port.close_delay = 50;
spin_unlock_irqrestore(&epca_lock, flags);
}
printk(KERN_INFO
"Digi PC/Xx Driver V%s: %s I/O = 0x%lx Mem = 0x%lx Ports = %d\n",
VERSION, board_desc[bd->type], (long)bd->port,
(long)bd->membase, bd->numports);
memwinoff(bd, 0);
}
static void epcapoll(unsigned long ignored)
{
unsigned long flags;
int crd;
unsigned int head, tail;
struct channel *ch;
struct board_info *bd;
for (crd = 0; crd < num_cards; crd++) {
bd = &boards[crd];
ch = card_ptr[crd];
if ((bd->status == DISABLED) || digi_poller_inhibited)
continue;
spin_lock_irqsave(&epca_lock, flags);
assertmemoff(ch);
globalwinon(ch);
head = readw(&ch->mailbox->ein);
tail = readw(&ch->mailbox->eout);
if (head != tail)
doevent(crd);
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
}
mod_timer(&epca_timer, jiffies + (HZ / 25));
}
static void doevent(int crd)
{
void __iomem *eventbuf;
struct channel *ch, *chan0;
static struct tty_struct *tty;
struct board_info *bd;
struct board_chan __iomem *bc;
unsigned int tail, head;
int event, channel;
int mstat, lstat;
bd = &boards[crd];
chan0 = card_ptr[crd];
epcaassert(chan0 <= &digi_channels[nbdevs - 1], "ch out of range");
assertgwinon(chan0);
while ((tail = readw(&chan0->mailbox->eout)) !=
(head = readw(&chan0->mailbox->ein))) {
assertgwinon(chan0);
eventbuf = bd->re_map_membase + tail + ISTART;
channel = readb(eventbuf);
event = readb(eventbuf + 1);
mstat = readb(eventbuf + 2);
lstat = readb(eventbuf + 3);
ch = chan0 + channel;
if ((unsigned)channel >= bd->numports || !ch) {
if (channel >= bd->numports)
ch = chan0;
bc = ch->brdchan;
goto next;
}
bc = ch->brdchan;
if (bc == NULL)
goto next;
tty = tty_port_tty_get(&ch->port);
if (event & DATA_IND) {
receive_data(ch, tty);
assertgwinon(ch);
}
if (event & MODEMCHG_IND) {
ch->imodem = mstat;
if (test_bit(ASYNCB_CHECK_CD, &ch->port.flags)) {
if (mstat & ch->dcd)
wake_up_interruptible(&ch->port.open_wait);
else
pc_sched_event(ch, EPCA_EVENT_HANGUP);
}
}
if (tty) {
if (event & BREAK_IND) {
tty_insert_flip_char(tty, 0, TTY_BREAK);
tty_schedule_flip(tty);
} else if (event & LOWTX_IND) {
if (ch->statusflags & LOWWAIT) {
ch->statusflags &= ~LOWWAIT;
tty_wakeup(tty);
}
} else if (event & EMPTYTX_IND) {
ch->statusflags &= ~TXBUSY;
if (ch->statusflags & EMPTYWAIT) {
ch->statusflags &= ~EMPTYWAIT;
tty_wakeup(tty);
}
}
tty_kref_put(tty);
}
next:
globalwinon(ch);
BUG_ON(!bc);
writew(1, &bc->idata);
writew((tail + 4) & (IMAX - ISTART - 4), &chan0->mailbox->eout);
globalwinon(chan0);
}
}
static void fepcmd(struct channel *ch, int cmd, int word_or_byte,
int byte2, int ncmds, int bytecmd)
{
unchar __iomem *memaddr;
unsigned int head, cmdTail, cmdStart, cmdMax;
long count;
int n;
if (ch->board->status == DISABLED)
return;
assertgwinon(ch);
head = readw(&ch->mailbox->cin);
cmdStart = readw(&ch->mailbox->cstart);
cmdMax = (cmdStart + 4 + readw(&ch->mailbox->cmax));
memaddr = ch->board->re_map_membase;
if (head >= (cmdMax - cmdStart) || (head & 03)) {
printk(KERN_ERR "line %d: Out of range, cmd = %x, head = %x\n",
__LINE__, cmd, head);
printk(KERN_ERR "line %d: Out of range, cmdMax = %x, cmdStart = %x\n",
__LINE__, cmdMax, cmdStart);
return;
}
if (bytecmd) {
writeb(cmd, memaddr + head + cmdStart + 0);
writeb(ch->channelnum, memaddr + head + cmdStart + 1);
writeb(word_or_byte, memaddr + head + cmdStart + 2);
writeb(byte2, memaddr + head + cmdStart + 3);
} else {
writeb(cmd, memaddr + head + cmdStart + 0);
writeb(ch->channelnum, memaddr + head + cmdStart + 1);
writeb(word_or_byte, memaddr + head + cmdStart + 2);
}
head = (head + 4) & (cmdMax - cmdStart - 4);
writew(head, &ch->mailbox->cin);
count = FEPTIMEOUT;
for (;;) {
count--;
if (count == 0) {
printk(KERN_ERR "<Error> - Fep not responding in fepcmd()\n");
return;
}
head = readw(&ch->mailbox->cin);
cmdTail = readw(&ch->mailbox->cout);
n = (head - cmdTail) & (cmdMax - cmdStart - 4);
if (n <= ncmds * (sizeof(short) * 4))
break;
}
}
static unsigned termios2digi_h(struct channel *ch, unsigned cflag)
{
unsigned res = 0;
if (cflag & CRTSCTS) {
ch->digiext.digi_flags |= (RTSPACE | CTSPACE);
res |= ((ch->m_cts) | (ch->m_rts));
}
if (ch->digiext.digi_flags & RTSPACE)
res |= ch->m_rts;
if (ch->digiext.digi_flags & DTRPACE)
res |= ch->m_dtr;
if (ch->digiext.digi_flags & CTSPACE)
res |= ch->m_cts;
if (ch->digiext.digi_flags & DSRPACE)
res |= ch->dsr;
if (ch->digiext.digi_flags & DCDPACE)
res |= ch->dcd;
if (res & (ch->m_rts))
ch->digiext.digi_flags |= RTSPACE;
if (res & (ch->m_cts))
ch->digiext.digi_flags |= CTSPACE;
return res;
}
static unsigned termios2digi_i(struct channel *ch, unsigned iflag)
{
unsigned res = iflag & (IGNBRK | BRKINT | IGNPAR | PARMRK |
INPCK | ISTRIP | IXON | IXANY | IXOFF);
if (ch->digiext.digi_flags & DIGI_AIXON)
res |= IAIXON;
return res;
}
static unsigned termios2digi_c(struct channel *ch, unsigned cflag)
{
unsigned res = 0;
if (cflag & CBAUDEX) {
ch->digiext.digi_flags |= DIGI_FAST;
res |= FEP_HUPCL;
} else
ch->digiext.digi_flags &= ~DIGI_FAST;
res |= cflag & ((CBAUD ^ CBAUDEX) | PARODD | PARENB | CSTOPB | CSIZE);
if (cflag & CBAUDEX) {
if ((!((cflag & 0x7) ^ (B115200 & ~CBAUDEX))) ||
(!((cflag & 0x7) ^ (B230400 & ~CBAUDEX))))
res += 1;
}
return res;
}
static void epcaparam(struct tty_struct *tty, struct channel *ch)
{
unsigned int cmdHead;
struct ktermios *ts;
struct board_chan __iomem *bc;
unsigned mval, hflow, cflag, iflag;
bc = ch->brdchan;
epcaassert(bc != NULL, "bc out of range");
assertgwinon(ch);
ts = tty->termios;
if ((ts->c_cflag & CBAUD) == 0) {
cmdHead = readw(&bc->rin);
writew(cmdHead, &bc->rout);
cmdHead = readw(&bc->tin);
fepcmd(ch, STOUT, (unsigned) cmdHead, 0, 0, 0);
mval = 0;
} else {
cflag = termios2digi_c(ch, ts->c_cflag);
if (cflag != ch->fepcflag) {
ch->fepcflag = cflag;
fepcmd(ch, SETCTRLFLAGS, (unsigned) cflag, 0, 0, 0);
}
if (ts->c_cflag & CLOCAL)
clear_bit(ASYNCB_CHECK_CD, &ch->port.flags);
else
set_bit(ASYNCB_CHECK_CD, &ch->port.flags);
mval = ch->m_dtr | ch->m_rts;
}
iflag = termios2digi_i(ch, ts->c_iflag);
if (iflag != ch->fepiflag) {
ch->fepiflag = iflag;
fepcmd(ch, SETIFLAGS, (unsigned int) ch->fepiflag, 0, 0, 0);
}
writeb(ch->dcd, &bc->mint);
if ((ts->c_cflag & CLOCAL) || (ch->digiext.digi_flags & DIGI_FORCEDCD))
if (ch->digiext.digi_flags & DIGI_FORCEDCD)
writeb(0, &bc->mint);
ch->imodem = readb(&bc->mstat);
hflow = termios2digi_h(ch, ts->c_cflag);
if (hflow != ch->hflow) {
ch->hflow = hflow;
fepcmd(ch, SETHFLOW, hflow, 0xff, 0, 1);
}
mval ^= ch->modemfake & (mval ^ ch->modem);
if (ch->omodem ^ mval) {
ch->omodem = mval;
fepcmd(ch, SETMODEM, 0, ((ch->m_dtr)|(ch->m_rts)), 0, 1);
fepcmd(ch, SETMODEM, mval, 0, 0, 1);
}
if (ch->startc != ch->fepstartc || ch->stopc != ch->fepstopc) {
ch->fepstartc = ch->startc;
ch->fepstopc = ch->stopc;
fepcmd(ch, SONOFFC, ch->fepstartc, ch->fepstopc, 0, 1);
}
if (ch->startca != ch->fepstartca || ch->stopca != ch->fepstopca) {
ch->fepstartca = ch->startca;
ch->fepstopca = ch->stopca;
fepcmd(ch, SAUXONOFFC, ch->fepstartca, ch->fepstopca, 0, 1);
}
}
static void receive_data(struct channel *ch, struct tty_struct *tty)
{
unchar *rptr;
struct ktermios *ts = NULL;
struct board_chan __iomem *bc;
int dataToRead, wrapgap, bytesAvailable;
unsigned int tail, head;
unsigned int wrapmask;
globalwinon(ch);
if (ch->statusflags & RXSTOPPED)
return;
if (tty)
ts = tty->termios;
bc = ch->brdchan;
BUG_ON(!bc);
wrapmask = ch->rxbufsize - 1;
head = readw(&bc->rin);
head &= wrapmask;
tail = readw(&bc->rout) & wrapmask;
bytesAvailable = (head - tail) & wrapmask;
if (bytesAvailable == 0)
return;
if (!tty || !ts || !(ts->c_cflag & CREAD)) {
writew(head, &bc->rout);
return;
}
if (tty_buffer_request_room(tty, bytesAvailable + 1) == 0)
return;
if (readb(&bc->orun)) {
writeb(0, &bc->orun);
printk(KERN_WARNING "epca; overrun! DigiBoard device %s\n",
tty->name);
tty_insert_flip_char(tty, 0, TTY_OVERRUN);
}
rxwinon(ch);
while (bytesAvailable > 0) {
wrapgap = (head >= tail) ? head - tail : ch->rxbufsize - tail;
dataToRead = (wrapgap < bytesAvailable) ? wrapgap
: bytesAvailable;
dataToRead = tty_prepare_flip_string(tty, &rptr, dataToRead);
if (dataToRead == 0)
break;
memcpy_fromio(rptr, ch->rxptr + tail, dataToRead);
tail = (tail + dataToRead) & wrapmask;
bytesAvailable -= dataToRead;
}
globalwinon(ch);
writew(tail, &bc->rout);
tty_schedule_flip(tty);
}
static int info_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
switch (cmd) {
case DIGI_GETINFO:
{
struct digi_info di;
int brd;
if (get_user(brd, (unsigned int __user *)arg))
return -EFAULT;
if (brd < 0 || brd >= num_cards || num_cards == 0)
return -ENODEV;
memset(&di, 0, sizeof(di));
di.board = brd;
di.status = boards[brd].status;
di.type = boards[brd].type ;
di.numports = boards[brd].numports ;
di.port = (unsigned char *)boards[brd].port ;
di.membase = (unsigned char *)boards[brd].membase ;
if (copy_to_user((void __user *)arg, &di, sizeof(di)))
return -EFAULT;
break;
}
case DIGI_POLLER:
{
int brd = arg & 0xff000000 >> 16;
unsigned char state = arg & 0xff;
if (brd < 0 || brd >= num_cards) {
printk(KERN_ERR "epca: DIGI POLLER : brd not valid!\n");
return -ENODEV;
}
digi_poller_inhibited = state;
break;
}
case DIGI_INIT:
{
int crd;
for (crd = 0; crd < num_cards; crd++)
post_fep_init(crd);
break;
}
default:
return -ENOTTY;
}
return 0;
}
static int pc_tiocmget(struct tty_struct *tty)
{
struct channel *ch = tty->driver_data;
struct board_chan __iomem *bc;
unsigned int mstat, mflag = 0;
unsigned long flags;
if (ch)
bc = ch->brdchan;
else
return -EINVAL;
spin_lock_irqsave(&epca_lock, flags);
globalwinon(ch);
mstat = readb(&bc->mstat);
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
if (mstat & ch->m_dtr)
mflag |= TIOCM_DTR;
if (mstat & ch->m_rts)
mflag |= TIOCM_RTS;
if (mstat & ch->m_cts)
mflag |= TIOCM_CTS;
if (mstat & ch->dsr)
mflag |= TIOCM_DSR;
if (mstat & ch->m_ri)
mflag |= TIOCM_RI;
if (mstat & ch->dcd)
mflag |= TIOCM_CD;
return mflag;
}
static int pc_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
struct channel *ch = tty->driver_data;
unsigned long flags;
if (!ch)
return -EINVAL;
spin_lock_irqsave(&epca_lock, flags);
if (set & TIOCM_RTS) {
ch->modemfake |= ch->m_rts;
ch->modem |= ch->m_rts;
}
if (set & TIOCM_DTR) {
ch->modemfake |= ch->m_dtr;
ch->modem |= ch->m_dtr;
}
if (clear & TIOCM_RTS) {
ch->modemfake |= ch->m_rts;
ch->modem &= ~ch->m_rts;
}
if (clear & TIOCM_DTR) {
ch->modemfake |= ch->m_dtr;
ch->modem &= ~ch->m_dtr;
}
globalwinon(ch);
epcaparam(tty, ch);
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
return 0;
}
static int pc_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
digiflow_t dflow;
unsigned long flags;
unsigned int mflag, mstat;
unsigned char startc, stopc;
struct board_chan __iomem *bc;
struct channel *ch = tty->driver_data;
void __user *argp = (void __user *)arg;
if (ch)
bc = ch->brdchan;
else
return -EINVAL;
switch (cmd) {
case TIOCMODG:
mflag = pc_tiocmget(tty);
if (put_user(mflag, (unsigned long __user *)argp))
return -EFAULT;
break;
case TIOCMODS:
if (get_user(mstat, (unsigned __user *)argp))
return -EFAULT;
return pc_tiocmset(tty, mstat, ~mstat);
case TIOCSDTR:
spin_lock_irqsave(&epca_lock, flags);
ch->omodem |= ch->m_dtr;
globalwinon(ch);
fepcmd(ch, SETMODEM, ch->m_dtr, 0, 10, 1);
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
break;
case TIOCCDTR:
spin_lock_irqsave(&epca_lock, flags);
ch->omodem &= ~ch->m_dtr;
globalwinon(ch);
fepcmd(ch, SETMODEM, 0, ch->m_dtr, 10, 1);
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
break;
case DIGI_GETA:
if (copy_to_user(argp, &ch->digiext, sizeof(digi_t)))
return -EFAULT;
break;
case DIGI_SETAW:
case DIGI_SETAF:
if (cmd == DIGI_SETAW) {
spin_lock_irqsave(&epca_lock, flags);
setup_empty_event(tty, ch);
spin_unlock_irqrestore(&epca_lock, flags);
tty_wait_until_sent(tty, 0);
} else {
if (tty->ldisc->ops->flush_buffer)
tty->ldisc->ops->flush_buffer(tty);
}
case DIGI_SETA:
if (copy_from_user(&ch->digiext, argp, sizeof(digi_t)))
return -EFAULT;
if (ch->digiext.digi_flags & DIGI_ALTPIN) {
ch->dcd = ch->m_dsr;
ch->dsr = ch->m_dcd;
} else {
ch->dcd = ch->m_dcd;
ch->dsr = ch->m_dsr;
}
spin_lock_irqsave(&epca_lock, flags);
globalwinon(ch);
epcaparam(tty, ch);
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
break;
case DIGI_GETFLOW:
case DIGI_GETAFLOW:
spin_lock_irqsave(&epca_lock, flags);
globalwinon(ch);
if (cmd == DIGI_GETFLOW) {
dflow.startc = readb(&bc->startc);
dflow.stopc = readb(&bc->stopc);
} else {
dflow.startc = readb(&bc->startca);
dflow.stopc = readb(&bc->stopca);
}
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
if (copy_to_user(argp, &dflow, sizeof(dflow)))
return -EFAULT;
break;
case DIGI_SETAFLOW:
case DIGI_SETFLOW:
if (cmd == DIGI_SETFLOW) {
startc = ch->startc;
stopc = ch->stopc;
} else {
startc = ch->startca;
stopc = ch->stopca;
}
if (copy_from_user(&dflow, argp, sizeof(dflow)))
return -EFAULT;
if (dflow.startc != startc || dflow.stopc != stopc) {
spin_lock_irqsave(&epca_lock, flags);
globalwinon(ch);
if (cmd == DIGI_SETFLOW) {
ch->fepstartc = ch->startc = dflow.startc;
ch->fepstopc = ch->stopc = dflow.stopc;
fepcmd(ch, SONOFFC, ch->fepstartc,
ch->fepstopc, 0, 1);
} else {
ch->fepstartca = ch->startca = dflow.startc;
ch->fepstopca = ch->stopca = dflow.stopc;
fepcmd(ch, SAUXONOFFC, ch->fepstartca,
ch->fepstopca, 0, 1);
}
if (ch->statusflags & TXSTOPPED)
pc_start(tty);
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
}
break;
default:
return -ENOIOCTLCMD;
}
return 0;
}
static void pc_set_termios(struct tty_struct *tty, struct ktermios *old_termios)
{
struct channel *ch;
unsigned long flags;
ch = verifyChannel(tty);
if (ch != NULL) {
spin_lock_irqsave(&epca_lock, flags);
globalwinon(ch);
epcaparam(tty, ch);
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
if ((old_termios->c_cflag & CRTSCTS) &&
((tty->termios->c_cflag & CRTSCTS) == 0))
tty->hw_stopped = 0;
if (!(old_termios->c_cflag & CLOCAL) &&
(tty->termios->c_cflag & CLOCAL))
wake_up_interruptible(&ch->port.open_wait);
}
}
static void do_softint(struct work_struct *work)
{
struct channel *ch = container_of(work, struct channel, tqueue);
if (ch && ch->magic == EPCA_MAGIC) {
struct tty_struct *tty = tty_port_tty_get(&ch->port);
if (tty && tty->driver_data) {
if (test_and_clear_bit(EPCA_EVENT_HANGUP, &ch->event)) {
tty_hangup(tty);
wake_up_interruptible(&ch->port.open_wait);
clear_bit(ASYNCB_NORMAL_ACTIVE,
&ch->port.flags);
}
}
tty_kref_put(tty);
}
}
static void pc_stop(struct tty_struct *tty)
{
struct channel *ch;
unsigned long flags;
ch = verifyChannel(tty);
if (ch != NULL) {
spin_lock_irqsave(&epca_lock, flags);
if ((ch->statusflags & TXSTOPPED) == 0) {
globalwinon(ch);
fepcmd(ch, PAUSETX, 0, 0, 0, 0);
ch->statusflags |= TXSTOPPED;
memoff(ch);
}
spin_unlock_irqrestore(&epca_lock, flags);
}
}
static void pc_start(struct tty_struct *tty)
{
struct channel *ch;
ch = verifyChannel(tty);
if (ch != NULL) {
unsigned long flags;
spin_lock_irqsave(&epca_lock, flags);
if (ch->statusflags & TXSTOPPED) {
struct board_chan __iomem *bc;
globalwinon(ch);
bc = ch->brdchan;
if (ch->statusflags & LOWWAIT)
writeb(1, &bc->ilow);
fepcmd(ch, RESUMETX, 0, 0, 0, 0);
ch->statusflags &= ~TXSTOPPED;
memoff(ch);
}
spin_unlock_irqrestore(&epca_lock, flags);
}
}
static void pc_throttle(struct tty_struct *tty)
{
struct channel *ch;
unsigned long flags;
ch = verifyChannel(tty);
if (ch != NULL) {
spin_lock_irqsave(&epca_lock, flags);
if ((ch->statusflags & RXSTOPPED) == 0) {
globalwinon(ch);
fepcmd(ch, PAUSERX, 0, 0, 0, 0);
ch->statusflags |= RXSTOPPED;
memoff(ch);
}
spin_unlock_irqrestore(&epca_lock, flags);
}
}
static void pc_unthrottle(struct tty_struct *tty)
{
struct channel *ch;
unsigned long flags;
ch = verifyChannel(tty);
if (ch != NULL) {
spin_lock_irqsave(&epca_lock, flags);
if (ch->statusflags & RXSTOPPED) {
globalwinon(ch);
fepcmd(ch, RESUMERX, 0, 0, 0, 0);
ch->statusflags &= ~RXSTOPPED;
memoff(ch);
}
spin_unlock_irqrestore(&epca_lock, flags);
}
}
static int pc_send_break(struct tty_struct *tty, int msec)
{
struct channel *ch = tty->driver_data;
unsigned long flags;
if (msec == -1)
msec = 0xFFFF;
else if (msec > 0xFFFE)
msec = 0xFFFE;
else if (msec < 1)
msec = 1;
spin_lock_irqsave(&epca_lock, flags);
globalwinon(ch);
fepcmd(ch, SENDBREAK, msec, 0, 10, 0);
memoff(ch);
spin_unlock_irqrestore(&epca_lock, flags);
return 0;
}
static void setup_empty_event(struct tty_struct *tty, struct channel *ch)
{
struct board_chan __iomem *bc = ch->brdchan;
globalwinon(ch);
ch->statusflags |= EMPTYWAIT;
writeb(1, &bc->iempty);
memoff(ch);
}
static void __init epca_setup(char *str, int *ints)
{
struct board_info board;
int index, loop, last;
char *temp, *t2;
unsigned len;
if (!liloconfig)
liloconfig = 1;
memset(&board, 0, sizeof(board));
for (last = 0, index = 1; index <= ints[0]; index++)
switch (index) {
case 1:
board.status = ints[index];
if (board.status == 2) {
nbdevs = 0;
num_cards = 0;
return;
}
if (board.status > 2) {
printk(KERN_ERR "epca_setup: Invalid board status 0x%x\n",
board.status);
invalid_lilo_config = 1;
setup_error_code |= INVALID_BOARD_STATUS;
return;
}
last = index;
break;
case 2:
board.type = ints[index];
if (board.type >= PCIXEM) {
printk(KERN_ERR "epca_setup: Invalid board type 0x%x\n", board.type);
invalid_lilo_config = 1;
setup_error_code |= INVALID_BOARD_TYPE;
return;
}
last = index;
break;
case 3:
board.altpin = ints[index];
if (board.altpin > 1) {
printk(KERN_ERR "epca_setup: Invalid board altpin 0x%x\n", board.altpin);
invalid_lilo_config = 1;
setup_error_code |= INVALID_ALTPIN;
return;
}
last = index;
break;
case 4:
board.numports = ints[index];
if (board.numports < 2 || board.numports > 256) {
printk(KERN_ERR "epca_setup: Invalid board numports 0x%x\n", board.numports);
invalid_lilo_config = 1;
setup_error_code |= INVALID_NUM_PORTS;
return;
}
nbdevs += board.numports;
last = index;
break;
case 5:
board.port = ints[index];
if (ints[index] <= 0) {
printk(KERN_ERR "epca_setup: Invalid io port 0x%x\n", (unsigned int)board.port);
invalid_lilo_config = 1;
setup_error_code |= INVALID_PORT_BASE;
return;
}
last = index;
break;
case 6:
board.membase = ints[index];
if (ints[index] <= 0) {
printk(KERN_ERR "epca_setup: Invalid memory base 0x%x\n",
(unsigned int)board.membase);
invalid_lilo_config = 1;
setup_error_code |= INVALID_MEM_BASE;
return;
}
last = index;
break;
default:
printk(KERN_ERR "<Error> - epca_setup: Too many integer parms\n");
return;
}
while (str && *str) {
temp = str;
while (*temp && (*temp != ','))
temp++;
if (!*temp)
temp = NULL;
else
*temp++ = 0;
index = last + 1;
switch (index) {
case 1:
len = strlen(str);
if (strncmp("Disable", str, len) == 0)
board.status = 0;
else if (strncmp("Enable", str, len) == 0)
board.status = 1;
else {
printk(KERN_ERR "epca_setup: Invalid status %s\n", str);
invalid_lilo_config = 1;
setup_error_code |= INVALID_BOARD_STATUS;
return;
}
last = index;
break;
case 2:
for (loop = 0; loop < EPCA_NUM_TYPES; loop++)
if (strcmp(board_desc[loop], str) == 0)
break;
if (index < EPCA_NUM_TYPES)
board.type = loop;
else {
printk(KERN_ERR "epca_setup: Invalid board type: %s\n", str);
invalid_lilo_config = 1;
setup_error_code |= INVALID_BOARD_TYPE;
return;
}
last = index;
break;
case 3:
len = strlen(str);
if (strncmp("Disable", str, len) == 0)
board.altpin = 0;
else if (strncmp("Enable", str, len) == 0)
board.altpin = 1;
else {
printk(KERN_ERR "epca_setup: Invalid altpin %s\n", str);
invalid_lilo_config = 1;
setup_error_code |= INVALID_ALTPIN;
return;
}
last = index;
break;
case 4:
t2 = str;
while (isdigit(*t2))
t2++;
if (*t2) {
printk(KERN_ERR "epca_setup: Invalid port count %s\n", str);
invalid_lilo_config = 1;
setup_error_code |= INVALID_NUM_PORTS;
return;
}
board.numports = simple_strtoul(str, NULL, 0);
nbdevs += board.numports;
last = index;
break;
case 5:
t2 = str;
while (isxdigit(*t2))
t2++;
if (*t2) {
printk(KERN_ERR "epca_setup: Invalid i/o address %s\n", str);
invalid_lilo_config = 1;
setup_error_code |= INVALID_PORT_BASE;
return;
}
board.port = simple_strtoul(str, NULL, 16);
last = index;
break;
case 6:
t2 = str;
while (isxdigit(*t2))
t2++;
if (*t2) {
printk(KERN_ERR "epca_setup: Invalid memory base %s\n", str);
invalid_lilo_config = 1;
setup_error_code |= INVALID_MEM_BASE;
return;
}
board.membase = simple_strtoul(str, NULL, 16);
last = index;
break;
default:
printk(KERN_ERR "epca: Too many string parms\n");
return;
}
str = temp;
}
if (last < 6) {
printk(KERN_ERR "epca: Insufficient parms specified\n");
return;
}
memcpy((void *)&boards[num_cards], (void *)&board, sizeof(board));
printk(KERN_INFO "PC/Xx: Added board %i, %s %i ports at 0x%4.4X base 0x%6.6X\n",
num_cards, board_desc[board.type],
board.numports, (int)board.port, (unsigned int) board.membase);
num_cards++;
}
static int __init epca_real_setup(char *str)
{
int ints[11];
epca_setup(get_options(str, 11, ints), ints);
return 1;
}
static int __devinit epca_init_one(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
static int board_num = -1;
int board_idx, info_idx = ent->driver_data;
unsigned long addr;
if (pci_enable_device(pdev))
return -EIO;
board_num++;
board_idx = board_num + num_cards;
if (board_idx >= MAXBOARDS)
goto err_out;
addr = pci_resource_start(pdev, epca_info_tbl[info_idx].bar_idx);
if (!addr) {
printk(KERN_ERR PFX "PCI region #%d not available (size 0)\n",
epca_info_tbl[info_idx].bar_idx);
goto err_out;
}
boards[board_idx].status = ENABLED;
boards[board_idx].type = epca_info_tbl[info_idx].board_type;
boards[board_idx].numports = 0x0;
boards[board_idx].port = addr + PCI_IO_OFFSET;
boards[board_idx].membase = addr;
if (!request_mem_region(addr + PCI_IO_OFFSET, 0x200000, "epca")) {
printk(KERN_ERR PFX "resource 0x%x @ 0x%lx unavailable\n",
0x200000, addr + PCI_IO_OFFSET);
goto err_out;
}
boards[board_idx].re_map_port = ioremap_nocache(addr + PCI_IO_OFFSET,
0x200000);
if (!boards[board_idx].re_map_port) {
printk(KERN_ERR PFX "cannot map 0x%x @ 0x%lx\n",
0x200000, addr + PCI_IO_OFFSET);
goto err_out_free_pciio;
}
if (!request_mem_region(addr, 0x200000, "epca")) {
printk(KERN_ERR PFX "resource 0x%x @ 0x%lx unavailable\n",
0x200000, addr);
goto err_out_free_iounmap;
}
boards[board_idx].re_map_membase = ioremap_nocache(addr, 0x200000);
if (!boards[board_idx].re_map_membase) {
printk(KERN_ERR PFX "cannot map 0x%x @ 0x%lx\n",
0x200000, addr + PCI_IO_OFFSET);
goto err_out_free_memregion;
}
if (info_idx != brd_xrj) {
pci_write_config_byte(pdev, 0x40, 0);
pci_write_config_byte(pdev, 0x46, 0);
}
return 0;
err_out_free_memregion:
release_mem_region(addr, 0x200000);
err_out_free_iounmap:
iounmap(boards[board_idx].re_map_port);
err_out_free_pciio:
release_mem_region(addr + PCI_IO_OFFSET, 0x200000);
err_out:
return -ENODEV;
}
static int __init init_PCI(void)
{
memset(&epca_driver, 0, sizeof(epca_driver));
epca_driver.name = "epca";
epca_driver.id_table = epca_pci_tbl;
epca_driver.probe = epca_init_one;
return pci_register_driver(&epca_driver);
}
