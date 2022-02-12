static void __init setup_error(char *mesg, int *ints)
{
if (ints[0] == 3)
printk(KERN_ERR "wd7000_setup: \"wd7000=%d,%d,0x%x\" -> %s\n", ints[1], ints[2], ints[3], mesg);
else if (ints[0] == 4)
printk(KERN_ERR "wd7000_setup: \"wd7000=%d,%d,0x%x,%d\" -> %s\n", ints[1], ints[2], ints[3], ints[4], mesg);
else
printk(KERN_ERR "wd7000_setup: \"wd7000=%d,%d,0x%x,%d,%d\" -> %s\n", ints[1], ints[2], ints[3], ints[4], ints[5], mesg);
}
static int __init wd7000_setup(char *str)
{
static short wd7000_card_num;
short i;
int ints[6];
(void) get_options(str, ARRAY_SIZE(ints), ints);
if (wd7000_card_num >= NUM_CONFIGS) {
printk(KERN_ERR "%s: Too many \"wd7000=\" configurations in " "command line!\n", __func__);
return 0;
}
if ((ints[0] < 3) || (ints[0] > 5)) {
printk(KERN_ERR "%s: Error in command line! " "Usage: wd7000=<IRQ>,<DMA>,IO>[,<BUS_ON>" "[,<BUS_OFF>]]\n", __func__);
} else {
for (i = 0; i < NUM_IRQS; i++)
if (ints[1] == wd7000_irq[i])
break;
if (i == NUM_IRQS) {
setup_error("invalid IRQ.", ints);
return 0;
} else
configs[wd7000_card_num].irq = ints[1];
for (i = 0; i < NUM_DMAS; i++)
if (ints[2] == wd7000_dma[i])
break;
if (i == NUM_DMAS) {
setup_error("invalid DMA channel.", ints);
return 0;
} else
configs[wd7000_card_num].dma = ints[2];
for (i = 0; i < NUM_IOPORTS; i++)
if (ints[3] == wd7000_iobase[i])
break;
if (i == NUM_IOPORTS) {
setup_error("invalid I/O base address.", ints);
return 0;
} else
configs[wd7000_card_num].iobase = ints[3];
if (ints[0] > 3) {
if ((ints[4] < 500) || (ints[4] > 31875)) {
setup_error("BUS_ON value is out of range (500" " to 31875 nanoseconds)!", ints);
configs[wd7000_card_num].bus_on = BUS_ON;
} else
configs[wd7000_card_num].bus_on = ints[4] / 125;
} else
configs[wd7000_card_num].bus_on = BUS_ON;
if (ints[0] > 4) {
if ((ints[5] < 500) || (ints[5] > 31875)) {
setup_error("BUS_OFF value is out of range (500" " to 31875 nanoseconds)!", ints);
configs[wd7000_card_num].bus_off = BUS_OFF;
} else
configs[wd7000_card_num].bus_off = ints[5] / 125;
} else
configs[wd7000_card_num].bus_off = BUS_OFF;
if (wd7000_card_num) {
for (i = 0; i < (wd7000_card_num - 1); i++) {
int j = i + 1;
for (; j < wd7000_card_num; j++)
if (configs[i].irq == configs[j].irq) {
setup_error("duplicated IRQ!", ints);
return 0;
}
if (configs[i].dma == configs[j].dma) {
setup_error("duplicated DMA " "channel!", ints);
return 0;
}
if (configs[i].iobase == configs[j].iobase) {
setup_error("duplicated I/O " "base address!", ints);
return 0;
}
}
}
dprintk(KERN_DEBUG "wd7000_setup: IRQ=%d, DMA=%d, I/O=0x%x, "
"BUS_ON=%dns, BUS_OFF=%dns\n", configs[wd7000_card_num].irq, configs[wd7000_card_num].dma, configs[wd7000_card_num].iobase, configs[wd7000_card_num].bus_on * 125, configs[wd7000_card_num].bus_off * 125);
wd7000_card_num++;
}
return 1;
}
static inline void any2scsi(unchar * scsi, int any)
{
*scsi++ = (unsigned)any >> 16;
*scsi++ = (unsigned)any >> 8;
*scsi++ = any;
}
static inline int scsi2int(unchar * scsi)
{
return (scsi[0] << 16) | (scsi[1] << 8) | scsi[2];
}
static inline void wd7000_enable_intr(Adapter * host)
{
host->control |= INT_EN;
outb(host->control, host->iobase + ASC_CONTROL);
}
static inline void wd7000_enable_dma(Adapter * host)
{
unsigned long flags;
host->control |= DMA_EN;
outb(host->control, host->iobase + ASC_CONTROL);
flags = claim_dma_lock();
set_dma_mode(host->dma, DMA_MODE_CASCADE);
enable_dma(host->dma);
release_dma_lock(flags);
}
static inline short WAIT(unsigned port, unsigned mask, unsigned allof, unsigned noneof)
{
unsigned WAITbits;
unsigned long WAITtimeout = jiffies + WAITnexttimeout;
while (time_before_eq(jiffies, WAITtimeout)) {
WAITbits = inb(port) & mask;
if (((WAITbits & allof) == allof) && ((WAITbits & noneof) == 0))
return (0);
}
return (1);
}
static inline int command_out(Adapter * host, unchar * cmd, int len)
{
if (!WAIT(host->iobase + ASC_STAT, ASC_STATMASK, CMD_RDY, 0)) {
while (len--) {
do {
outb(*cmd, host->iobase + ASC_COMMAND);
WAIT(host->iobase + ASC_STAT, ASC_STATMASK, CMD_RDY, 0);
} while (inb(host->iobase + ASC_STAT) & CMD_REJ);
cmd++;
}
return (1);
}
printk(KERN_WARNING "wd7000 command_out: WAIT failed(%d)\n", len + 1);
return (0);
}
static inline Scb *alloc_scbs(struct Scsi_Host *host, int needed)
{
Scb *scb, *p = NULL;
unsigned long flags;
unsigned long timeout = jiffies + WAITnexttimeout;
unsigned long now;
int i;
if (needed <= 0)
return (NULL);
spin_unlock_irq(host->host_lock);
retry:
while (freescbs < needed) {
timeout = jiffies + WAITnexttimeout;
do {
for (now = jiffies; now == jiffies;)
cpu_relax();
} while (freescbs < needed && time_before_eq(jiffies, timeout));
if (freescbs < needed) {
printk(KERN_ERR "wd7000: can't get enough free SCBs.\n");
return (NULL);
}
}
spin_lock_irqsave(&scbpool_lock, flags);
if (freescbs < needed) {
spin_unlock_irqrestore(&scbpool_lock, flags);
goto retry;
}
scb = scbfree;
freescbs -= needed;
for (i = 0; i < needed; i++) {
p = scbfree;
scbfree = p->next;
}
p->next = NULL;
spin_unlock_irqrestore(&scbpool_lock, flags);
spin_lock_irq(host->host_lock);
return (scb);
}
static inline void free_scb(Scb * scb)
{
unsigned long flags;
spin_lock_irqsave(&scbpool_lock, flags);
memset(scb, 0, sizeof(Scb));
scb->next = scbfree;
scbfree = scb;
freescbs++;
spin_unlock_irqrestore(&scbpool_lock, flags);
}
static inline void init_scbs(void)
{
int i;
spin_lock_init(&scbpool_lock);
scbfree = &(scbs[0]);
memset(scbs, 0, sizeof(scbs));
for (i = 0; i < MAX_SCBS - 1; i++) {
scbs[i].next = &(scbs[i + 1]);
scbs[i].SCpnt = NULL;
}
scbs[MAX_SCBS - 1].next = NULL;
scbs[MAX_SCBS - 1].SCpnt = NULL;
}
static int mail_out(Adapter * host, Scb * scbptr)
{
int i, ogmb;
unsigned long flags;
unchar start_ogmb;
Mailbox *ogmbs = host->mb.ogmb;
int *next_ogmb = &(host->next_ogmb);
dprintk("wd7000_mail_out: 0x%06lx", (long) scbptr);
spin_lock_irqsave(host->sh->host_lock, flags);
ogmb = *next_ogmb;
for (i = 0; i < OGMB_CNT; i++) {
if (ogmbs[ogmb].status == 0) {
dprintk(" using OGMB 0x%x", ogmb);
ogmbs[ogmb].status = 1;
any2scsi((unchar *) ogmbs[ogmb].scbptr, (int) scbptr);
*next_ogmb = (ogmb + 1) % OGMB_CNT;
break;
} else
ogmb = (ogmb + 1) % OGMB_CNT;
}
spin_unlock_irqrestore(host->sh->host_lock, flags);
dprintk(", scb is 0x%06lx", (long) scbptr);
if (i >= OGMB_CNT) {
dprintk(", no free OGMBs.\n");
return (0);
}
wd7000_enable_intr(host);
start_ogmb = START_OGMB | ogmb;
command_out(host, &start_ogmb, 1);
dprintk(", awaiting interrupt.\n");
return (1);
}
static int make_code(unsigned hosterr, unsigned scsierr)
{
#ifdef WD7000_DEBUG
int in_error = hosterr;
#endif
switch ((hosterr >> 8) & 0xff) {
case 0:
hosterr = DID_ERROR;
break;
case 1:
hosterr = DID_OK;
break;
case 2:
hosterr = DID_OK;
break;
case 4:
hosterr = DID_TIME_OUT;
break;
case 5:
hosterr = DID_RESET;
break;
case 6:
hosterr = DID_BAD_TARGET;
break;
case 80:
case 81:
hosterr = DID_BAD_INTR;
break;
case 82:
hosterr = DID_ABORT;
break;
case 83:
case 84:
hosterr = DID_RESET;
break;
default:
hosterr = DID_ERROR;
}
#ifdef WD7000_DEBUG
if (scsierr || hosterr)
dprintk("\nSCSI command error: SCSI 0x%02x host 0x%04x return %d\n", scsierr, in_error, hosterr);
#endif
return (scsierr | (hosterr << 16));
}
static irqreturn_t wd7000_intr(int irq, void *dev_id)
{
Adapter *host = (Adapter *) dev_id;
int flag, icmb, errstatus, icmb_status;
int host_error, scsi_error;
Scb *scb;
IcbAny *icb;
struct scsi_cmnd *SCpnt;
Mailbox *icmbs = host->mb.icmb;
unsigned long flags;
spin_lock_irqsave(host->sh->host_lock, flags);
host->int_counter++;
dprintk("wd7000_intr: irq = %d, host = 0x%06lx\n", irq, (long) host);
flag = inb(host->iobase + ASC_INTR_STAT);
dprintk("wd7000_intr: intr stat = 0x%02x\n", flag);
if (!(inb(host->iobase + ASC_STAT) & INT_IM)) {
dprintk("wd7000_intr: phantom interrupt...\n");
goto ack;
}
if (!(flag & MB_INTR))
goto ack;
if (!(flag & IMB_INTR)) {
dprintk("wd7000_intr: free outgoing mailbox\n");
goto ack;
}
icmb = flag & MB_MASK;
icmb_status = icmbs[icmb].status;
if (icmb_status & 0x80) {
dprintk("wd7000_intr: unsolicited interrupt 0x%02x\n", icmb_status);
goto ack;
}
scb = isa_bus_to_virt(scsi2int((unchar *) icmbs[icmb].scbptr));
icmbs[icmb].status = 0;
if (scb->op & ICB_OP_MASK) {
icb = (IcbAny *) scb;
icb->status = icmb_status;
icb->phase = 0;
goto ack;
}
SCpnt = scb->SCpnt;
if (--(SCpnt->SCp.phase) <= 0) {
host_error = scb->vue | (icmb_status << 8);
scsi_error = scb->status;
errstatus = make_code(host_error, scsi_error);
SCpnt->result = errstatus;
free_scb(scb);
SCpnt->scsi_done(SCpnt);
}
ack:
dprintk("wd7000_intr: return from interrupt handler\n");
wd7000_intr_ack(host);
spin_unlock_irqrestore(host->sh->host_lock, flags);
return IRQ_HANDLED;
}
static int wd7000_queuecommand_lck(struct scsi_cmnd *SCpnt,
void (*done)(struct scsi_cmnd *))
{
Scb *scb;
Sgb *sgb;
unchar *cdb = (unchar *) SCpnt->cmnd;
unchar idlun;
short cdblen;
int nseg;
Adapter *host = (Adapter *) SCpnt->device->host->hostdata;
cdblen = SCpnt->cmd_len;
idlun = ((SCpnt->device->id << 5) & 0xe0) | (SCpnt->device->lun & 7);
SCpnt->scsi_done = done;
SCpnt->SCp.phase = 1;
scb = alloc_scbs(SCpnt->device->host, 1);
scb->idlun = idlun;
memcpy(scb->cdb, cdb, cdblen);
scb->direc = 0x40;
scb->SCpnt = SCpnt;
SCpnt->host_scribble = (unchar *) scb;
scb->host = host;
nseg = scsi_sg_count(SCpnt);
if (nseg > 1) {
struct scatterlist *sg;
unsigned i;
dprintk("Using scatter/gather with %d elements.\n", nseg);
sgb = scb->sgb;
scb->op = 1;
any2scsi(scb->dataptr, (int) sgb);
any2scsi(scb->maxlen, nseg * sizeof(Sgb));
scsi_for_each_sg(SCpnt, sg, nseg, i) {
any2scsi(sgb[i].ptr, isa_page_to_bus(sg_page(sg)) + sg->offset);
any2scsi(sgb[i].len, sg->length);
}
} else {
scb->op = 0;
if (nseg) {
struct scatterlist *sg = scsi_sglist(SCpnt);
any2scsi(scb->dataptr, isa_page_to_bus(sg_page(sg)) + sg->offset);
}
any2scsi(scb->maxlen, scsi_bufflen(SCpnt));
}
while (!mail_out(host, scb))
cpu_relax();
return 0;
}
int wd7000_adapter_reset(Adapter * host)
{
InitCmd init_cmd = {
INITIALIZATION,
7,
host->bus_on,
host->bus_off,
0,
{0, 0, 0},
OGMB_CNT,
ICMB_CNT
};
int diag;
outb(ASC_RES, host->iobase + ASC_CONTROL);
udelay(40);
outb(0, host->iobase + ASC_CONTROL);
host->control = 0;
if (WAIT(host->iobase + ASC_STAT, ASC_STATMASK, CMD_RDY, 0)) {
printk(KERN_ERR "wd7000_init: WAIT timed out.\n");
return -1;
}
if ((diag = inb(host->iobase + ASC_INTR_STAT)) != 1) {
printk("wd7000_init: ");
switch (diag) {
case 2:
printk(KERN_ERR "RAM failure.\n");
break;
case 3:
printk(KERN_ERR "FIFO R/W failed\n");
break;
case 4:
printk(KERN_ERR "SBIC register R/W failed\n");
break;
case 5:
printk(KERN_ERR "Initialization D-FF failed.\n");
break;
case 6:
printk(KERN_ERR "Host IRQ D-FF failed.\n");
break;
case 7:
printk(KERN_ERR "ROM checksum error.\n");
break;
default:
printk(KERN_ERR "diagnostic code 0x%02Xh received.\n", diag);
}
return -1;
}
memset(&(host->mb), 0, sizeof(host->mb));
any2scsi((unchar *) & (init_cmd.mailboxes), (int) &(host->mb));
if (!command_out(host, (unchar *) & init_cmd, sizeof(init_cmd))) {
printk(KERN_ERR "wd7000_adapter_reset: adapter initialization failed.\n");
return -1;
}
if (WAIT(host->iobase + ASC_STAT, ASC_STATMASK, ASC_INIT, 0)) {
printk("wd7000_adapter_reset: WAIT timed out.\n");
return -1;
}
return 0;
}
static int wd7000_init(Adapter * host)
{
if (wd7000_adapter_reset(host) == -1)
return 0;
if (request_irq(host->irq, wd7000_intr, IRQF_DISABLED, "wd7000", host)) {
printk("wd7000_init: can't get IRQ %d.\n", host->irq);
return (0);
}
if (request_dma(host->dma, "wd7000")) {
printk("wd7000_init: can't get DMA channel %d.\n", host->dma);
free_irq(host->irq, host);
return (0);
}
wd7000_enable_dma(host);
wd7000_enable_intr(host);
if (!wd7000_diagnostics(host, ICB_DIAG_FULL)) {
free_dma(host->dma);
free_irq(host->irq, NULL);
return (0);
}
return (1);
}
static void wd7000_revision(Adapter * host)
{
static IcbRevLvl icb = { ICB_OP_GET_REVISION };
icb.phase = 1;
mail_out(host, (struct scb *) &icb);
while (icb.phase) {
cpu_relax();
barrier();
}
host->rev1 = icb.primary;
host->rev2 = icb.secondary;
}
static int wd7000_set_info(char *buffer, int length, struct Scsi_Host *host)
{
dprintk("Buffer = <%.*s>, length = %d\n", length, buffer, length);
dprintk("Sorry, this function is currently out of order...\n");
return (length);
}
static int wd7000_proc_info(struct Scsi_Host *host, char *buffer, char **start, off_t offset, int length, int inout)
{
Adapter *adapter = (Adapter *)host->hostdata;
unsigned long flags;
char *pos = buffer;
#ifdef WD7000_DEBUG
Mailbox *ogmbs, *icmbs;
short count;
#endif
if (inout)
return (wd7000_set_info(buffer, length, host));
spin_lock_irqsave(host->host_lock, flags);
SPRINTF("Host scsi%d: Western Digital WD-7000 (rev %d.%d)\n", host->host_no, adapter->rev1, adapter->rev2);
SPRINTF(" IO base: 0x%x\n", adapter->iobase);
SPRINTF(" IRQ: %d\n", adapter->irq);
SPRINTF(" DMA channel: %d\n", adapter->dma);
SPRINTF(" Interrupts: %d\n", adapter->int_counter);
SPRINTF(" BUS_ON time: %d nanoseconds\n", adapter->bus_on * 125);
SPRINTF(" BUS_OFF time: %d nanoseconds\n", adapter->bus_off * 125);
#ifdef WD7000_DEBUG
ogmbs = adapter->mb.ogmb;
icmbs = adapter->mb.icmb;
SPRINTF("\nControl port value: 0x%x\n", adapter->control);
SPRINTF("Incoming mailbox:\n");
SPRINTF(" size: %d\n", ICMB_CNT);
SPRINTF(" queued messages: ");
for (i = count = 0; i < ICMB_CNT; i++)
if (icmbs[i].status) {
count++;
SPRINTF("0x%x ", i);
}
SPRINTF(count ? "\n" : "none\n");
SPRINTF("Outgoing mailbox:\n");
SPRINTF(" size: %d\n", OGMB_CNT);
SPRINTF(" next message: 0x%x\n", adapter->next_ogmb);
SPRINTF(" queued messages: ");
for (i = count = 0; i < OGMB_CNT; i++)
if (ogmbs[i].status) {
count++;
SPRINTF("0x%x ", i);
}
SPRINTF(count ? "\n" : "none\n");
#endif
spin_unlock_irqrestore(host->host_lock, flags);
*start = buffer + offset;
if ((pos - buffer) < offset)
return (0);
else if ((pos - buffer - offset) < length)
return (pos - buffer - offset);
else
return (length);
}
static __init int wd7000_detect(struct scsi_host_template *tpnt)
{
short present = 0, biosaddr_ptr, sig_ptr, i, pass;
short biosptr[NUM_CONFIGS];
unsigned iobase;
Adapter *host = NULL;
struct Scsi_Host *sh;
int unit = 0;
dprintk("wd7000_detect: started\n");
#ifdef MODULE
if (wd7000)
wd7000_setup(wd7000);
#endif
for (i = 0; i < UNITS; wd7000_host[i++] = NULL);
for (i = 0; i < NUM_CONFIGS; biosptr[i++] = -1);
tpnt->proc_name = "wd7000";
tpnt->proc_info = &wd7000_proc_info;
init_scbs();
for (pass = 0; pass < NUM_CONFIGS; pass++) {
for (biosaddr_ptr = 0; biosaddr_ptr < NUM_ADDRS; biosaddr_ptr++)
for (sig_ptr = 0; sig_ptr < NUM_SIGNATURES; sig_ptr++) {
for (i = 0; i < pass; i++)
if (biosptr[i] == biosaddr_ptr)
break;
if (i == pass) {
void __iomem *biosaddr = ioremap(wd7000_biosaddr[biosaddr_ptr] + signatures[sig_ptr].ofs,
signatures[sig_ptr].len);
short bios_match = 1;
if (biosaddr)
bios_match = check_signature(biosaddr, signatures[sig_ptr].sig, signatures[sig_ptr].len);
iounmap(biosaddr);
if (bios_match)
goto bios_matched;
}
}
bios_matched:
#ifdef WD7000_DEBUG
dprintk("wd7000_detect: pass %d\n", pass + 1);
if (biosaddr_ptr == NUM_ADDRS)
dprintk("WD-7000 SST BIOS not detected...\n");
else
dprintk("WD-7000 SST BIOS detected at 0x%lx: checking...\n", wd7000_biosaddr[biosaddr_ptr]);
#endif
if (configs[pass].irq < 0)
continue;
if (unit == UNITS)
continue;
iobase = configs[pass].iobase;
dprintk("wd7000_detect: check IO 0x%x region...\n", iobase);
if (request_region(iobase, 4, "wd7000")) {
dprintk("wd7000_detect: ASC reset (IO 0x%x) ...", iobase);
outb(ASC_RES, iobase + ASC_CONTROL);
msleep(10);
outb(0, iobase + ASC_CONTROL);
if (WAIT(iobase + ASC_STAT, ASC_STATMASK, CMD_RDY, 0)) {
dprintk("failed!\n");
goto err_release;
} else
dprintk("ok!\n");
if (inb(iobase + ASC_INTR_STAT) == 1) {
sh = scsi_register(tpnt, sizeof(Adapter));
if (sh == NULL)
goto err_release;
host = (Adapter *) sh->hostdata;
dprintk("wd7000_detect: adapter allocated at 0x%x\n", (int) host);
memset(host, 0, sizeof(Adapter));
host->irq = configs[pass].irq;
host->dma = configs[pass].dma;
host->iobase = iobase;
host->int_counter = 0;
host->bus_on = configs[pass].bus_on;
host->bus_off = configs[pass].bus_off;
host->sh = wd7000_host[unit] = sh;
unit++;
dprintk("wd7000_detect: Trying init WD-7000 card at IO " "0x%x, IRQ %d, DMA %d...\n", host->iobase, host->irq, host->dma);
if (!wd7000_init(host))
goto err_unregister;
wd7000_revision(host);
if (host->rev1 < 6)
sh->sg_tablesize = 1;
present++;
if (biosaddr_ptr != NUM_ADDRS)
biosptr[pass] = biosaddr_ptr;
printk(KERN_INFO "Western Digital WD-7000 (rev %d.%d) ", host->rev1, host->rev2);
printk("using IO 0x%x, IRQ %d, DMA %d.\n", host->iobase, host->irq, host->dma);
printk(" BUS_ON time: %dns, BUS_OFF time: %dns\n", host->bus_on * 125, host->bus_off * 125);
}
} else
dprintk("wd7000_detect: IO 0x%x region already allocated!\n", iobase);
continue;
err_unregister:
scsi_unregister(sh);
err_release:
release_region(iobase, 4);
}
if (!present)
printk("Failed initialization of WD-7000 SCSI card!\n");
return (present);
}
static int wd7000_release(struct Scsi_Host *shost)
{
if (shost->irq)
free_irq(shost->irq, NULL);
if (shost->io_port && shost->n_io_port)
release_region(shost->io_port, shost->n_io_port);
scsi_unregister(shost);
return 0;
}
static int wd7000_host_reset(struct scsi_cmnd *SCpnt)
{
Adapter *host = (Adapter *) SCpnt->device->host->hostdata;
spin_lock_irq(SCpnt->device->host->host_lock);
if (wd7000_adapter_reset(host) < 0) {
spin_unlock_irq(SCpnt->device->host->host_lock);
return FAILED;
}
wd7000_enable_intr(host);
spin_unlock_irq(SCpnt->device->host->host_lock);
return SUCCESS;
}
static int wd7000_biosparam(struct scsi_device *sdev,
struct block_device *bdev, sector_t capacity, int *ip)
{
char b[BDEVNAME_SIZE];
dprintk("wd7000_biosparam: dev=%s, size=%d, ",
bdevname(bdev, b), capacity);
(void)b;
ip[0] = 64;
ip[1] = 32;
ip[2] = capacity >> 11;
if (ip[2] >= 1024) {
int info[3];
if ((scsicam_bios_param(bdev, capacity, info) < 0) || !(((info[0] == 64) && (info[1] == 32)) || ((info[0] == 255) && (info[1] == 63)))) {
printk("wd7000_biosparam: unable to verify geometry for disk with >1GB.\n" " using extended translation.\n");
ip[0] = 255;
ip[1] = 63;
ip[2] = (unsigned long) capacity / (255 * 63);
} else {
ip[0] = info[0];
ip[1] = info[1];
ip[2] = info[2];
if (info[0] == 255)
printk(KERN_INFO "%s: current partition table is " "using extended translation.\n", __func__);
}
}
dprintk("bios geometry: head=%d, sec=%d, cyl=%d\n", ip[0], ip[1], ip[2]);
dprintk("WARNING: check, if the bios geometry is correct.\n");
return (0);
}
