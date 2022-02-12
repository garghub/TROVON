static inline struct ecb *ecb_dma_to_cpu (struct Scsi_Host *host,
dma_addr_t dma)
{
struct aha1740_hostdata *hdata = HOSTDATA (host);
dma_addr_t offset;
offset = dma - hdata->ecb_dma_addr;
return (struct ecb *)(((char *) hdata->ecb) + (unsigned int) offset);
}
static inline dma_addr_t ecb_cpu_to_dma (struct Scsi_Host *host, void *cpu)
{
struct aha1740_hostdata *hdata = HOSTDATA (host);
dma_addr_t offset;
offset = (char *) cpu - (char *) hdata->ecb;
return hdata->ecb_dma_addr + offset;
}
static int aha1740_show_info(struct seq_file *m, struct Scsi_Host *shpnt)
{
struct aha1740_hostdata *host = HOSTDATA(shpnt);
seq_printf(m, "aha174x at IO:%lx, IRQ %d, SLOT %d.\n"
"Extended translation %sabled.\n",
shpnt->io_port, shpnt->irq, host->edev->slot,
host->translation ? "en" : "dis");
return 0;
}
static int aha1740_makecode(unchar *sense, unchar *status)
{
struct statusword
{
ushort don:1,
du:1,
:1, qf:1,
sc:1,
dor:1,
ch:1,
intr:1,
asa:1,
sns:1,
:1, ini:1,
me:1,
:1, eca:1,
:1;
} status_word;
int retval = DID_OK;
status_word = * (struct statusword *) status;
#ifdef DEBUG
printk("makecode from %x,%x,%x,%x %x,%x,%x,%x",
status[0], status[1], status[2], status[3],
sense[0], sense[1], sense[2], sense[3]);
#endif
if (!status_word.don) {
if ( (status[1]&0x18) || status_word.sc ) {
switch ( status[2] ) {
case 0x12:
if ( status_word.dor )
retval=DID_ERROR;
case 0x00:
break;
case 0x11:
case 0x21:
retval=DID_TIME_OUT;
break;
case 0x0a:
retval=DID_BAD_TARGET;
break;
case 0x04:
case 0x05:
retval=DID_ABORT;
break;
default:
retval=DID_ERROR;
}
} else {
if ( status_word.qf ) {
retval = DID_TIME_OUT;
printk("aha1740.c: WARNING: AHA1740 queue overflow!\n");
} else
if ( status[0]&0x60 ) {
retval = DID_ERROR;
}
}
}
return status[3] | retval << 16;
}
static int aha1740_test_port(unsigned int base)
{
if ( inb(PORTADR(base)) & PORTADDR_ENH )
return 1;
printk("aha174x: Board detected, but not in enhanced mode, so disabled it.\n");
return 0;
}
static irqreturn_t aha1740_intr_handle(int irq, void *dev_id)
{
struct Scsi_Host *host = (struct Scsi_Host *) dev_id;
void (*my_done)(Scsi_Cmnd *);
int errstatus, adapstat;
int number_serviced;
struct ecb *ecbptr;
Scsi_Cmnd *SCtmp;
unsigned int base;
unsigned long flags;
int handled = 0;
struct aha1740_sg *sgptr;
struct eisa_device *edev;
if (!host)
panic("aha1740.c: Irq from unknown host!\n");
spin_lock_irqsave(host->host_lock, flags);
base = host->io_port;
number_serviced = 0;
edev = HOSTDATA(host)->edev;
while(inb(G2STAT(base)) & G2STAT_INTPEND) {
handled = 1;
DEB(printk("aha1740_intr top of loop.\n"));
adapstat = inb(G2INTST(base));
ecbptr = ecb_dma_to_cpu (host, inl(MBOXIN0(base)));
outb(G2CNTRL_IRST,G2CNTRL(base));
switch ( adapstat & G2INTST_MASK ) {
case G2INTST_CCBRETRY:
case G2INTST_CCBERROR:
case G2INTST_CCBGOOD:
outb(G2CNTRL_HRDY,G2CNTRL(base));
if (!ecbptr) {
printk("Aha1740 null ecbptr in interrupt (%x,%x,%x,%d)\n",
inb(G2STAT(base)),adapstat,
inb(G2INTST(base)), number_serviced++);
continue;
}
SCtmp = ecbptr->SCpnt;
if (!SCtmp) {
printk("Aha1740 null SCtmp in interrupt (%x,%x,%x,%d)\n",
inb(G2STAT(base)),adapstat,
inb(G2INTST(base)), number_serviced++);
continue;
}
sgptr = (struct aha1740_sg *) SCtmp->host_scribble;
scsi_dma_unmap(SCtmp);
dma_free_coherent (&edev->dev,
sizeof (struct aha1740_sg),
SCtmp->host_scribble,
sgptr->sg_dma_addr);
if ( (adapstat & G2INTST_MASK) == G2INTST_CCBERROR ) {
memcpy(SCtmp->sense_buffer, ecbptr->sense,
SCSI_SENSE_BUFFERSIZE);
errstatus = aha1740_makecode(ecbptr->sense,ecbptr->status);
} else
errstatus = 0;
DEB(if (errstatus)
printk("aha1740_intr_handle: returning %6x\n",
errstatus));
SCtmp->result = errstatus;
my_done = ecbptr->done;
memset(ecbptr,0,sizeof(struct ecb));
if ( my_done )
my_done(SCtmp);
break;
case G2INTST_HARDFAIL:
printk(KERN_ALERT "aha1740 hardware failure!\n");
panic("aha1740.c");
case G2INTST_ASNEVENT:
printk("aha1740 asynchronous event: %02x %02x %02x %02x %02x\n",
adapstat,
inb(MBOXIN0(base)),
inb(MBOXIN1(base)),
inb(MBOXIN2(base)),
inb(MBOXIN3(base)));
outb(G2CNTRL_HRDY,G2CNTRL(base));
break;
case G2INTST_CMDGOOD:
break;
case G2INTST_CMDERROR:
break;
}
number_serviced++;
}
spin_unlock_irqrestore(host->host_lock, flags);
return IRQ_RETVAL(handled);
}
static int aha1740_queuecommand_lck(Scsi_Cmnd * SCpnt, void (*done)(Scsi_Cmnd *))
{
unchar direction;
unchar *cmd = (unchar *) SCpnt->cmnd;
unchar target = scmd_id(SCpnt);
struct aha1740_hostdata *host = HOSTDATA(SCpnt->device->host);
unsigned long flags;
dma_addr_t sg_dma;
struct aha1740_sg *sgptr;
int ecbno, nseg;
DEB(int i);
if(*cmd == REQUEST_SENSE) {
SCpnt->result = 0;
done(SCpnt);
return 0;
}
#ifdef DEBUG
if (*cmd == READ_10 || *cmd == WRITE_10)
i = xscsi2int(cmd+2);
else if (*cmd == READ_6 || *cmd == WRITE_6)
i = scsi2int(cmd+2);
else
i = -1;
printk("aha1740_queuecommand: dev %d cmd %02x pos %d len %d ",
target, *cmd, i, bufflen);
printk("scsi cmd:");
for (i = 0; i < SCpnt->cmd_len; i++) printk("%02x ", cmd[i]);
printk("\n");
#endif
spin_lock_irqsave(SCpnt->device->host->host_lock, flags);
ecbno = host->last_ecb_used + 1;
if (ecbno >= AHA1740_ECBS)
ecbno = 0;
do {
if (!host->ecb[ecbno].cmdw)
break;
ecbno++;
if (ecbno >= AHA1740_ECBS)
ecbno = 0;
} while (ecbno != host->last_ecb_used);
if (host->ecb[ecbno].cmdw)
panic("Unable to find empty ecb for aha1740.\n");
host->ecb[ecbno].cmdw = AHA1740CMD_INIT;
host->last_ecb_used = ecbno;
spin_unlock_irqrestore(SCpnt->device->host->host_lock, flags);
#ifdef DEBUG
printk("Sending command (%d %x)...", ecbno, done);
#endif
host->ecb[ecbno].cdblen = SCpnt->cmd_len;
direction = 0;
if (*cmd == READ_10 || *cmd == READ_6)
direction = 1;
else if (*cmd == WRITE_10 || *cmd == WRITE_6)
direction = 0;
memcpy(host->ecb[ecbno].cdb, cmd, SCpnt->cmd_len);
SCpnt->host_scribble = dma_alloc_coherent (&host->edev->dev,
sizeof (struct aha1740_sg),
&sg_dma, GFP_ATOMIC);
if(SCpnt->host_scribble == NULL) {
printk(KERN_WARNING "aha1740: out of memory in queuecommand!\n");
return 1;
}
sgptr = (struct aha1740_sg *) SCpnt->host_scribble;
sgptr->sg_dma_addr = sg_dma;
nseg = scsi_dma_map(SCpnt);
BUG_ON(nseg < 0);
if (nseg) {
struct scatterlist *sg;
struct aha1740_chain * cptr;
int i;
DEB(unsigned char * ptr);
host->ecb[ecbno].sg = 1;
cptr = sgptr->sg_chain;
scsi_for_each_sg(SCpnt, sg, nseg, i) {
cptr[i].datalen = sg_dma_len (sg);
cptr[i].dataptr = sg_dma_address (sg);
}
host->ecb[ecbno].datalen = nseg * sizeof(struct aha1740_chain);
host->ecb[ecbno].dataptr = sg_dma;
#ifdef DEBUG
printk("cptr %x: ",cptr);
ptr = (unsigned char *) cptr;
for(i=0;i<24;i++) printk("%02x ", ptr[i]);
#endif
} else {
host->ecb[ecbno].datalen = 0;
host->ecb[ecbno].dataptr = 0;
}
host->ecb[ecbno].lun = SCpnt->device->lun;
host->ecb[ecbno].ses = 1;
host->ecb[ecbno].dir = direction;
host->ecb[ecbno].ars = 1;
host->ecb[ecbno].senselen = 12;
host->ecb[ecbno].senseptr = ecb_cpu_to_dma (SCpnt->device->host,
host->ecb[ecbno].sense);
host->ecb[ecbno].statusptr = ecb_cpu_to_dma (SCpnt->device->host,
host->ecb[ecbno].status);
host->ecb[ecbno].done = done;
host->ecb[ecbno].SCpnt = SCpnt;
#ifdef DEBUG
{
int i;
printk("aha1740_command: sending.. ");
for (i = 0; i < sizeof(host->ecb[ecbno]) - 10; i++)
printk("%02x ", ((unchar *)&host->ecb[ecbno])[i]);
}
printk("\n");
#endif
if (done) {
#define LOOPCNT_WARN 10
#define LOOPCNT_MAX 1000000
int loopcnt;
unsigned int base = SCpnt->device->host->io_port;
DEB(printk("aha1740[%d] critical section\n",ecbno));
spin_lock_irqsave(SCpnt->device->host->host_lock, flags);
for (loopcnt = 0; ; loopcnt++) {
if (inb(G2STAT(base)) & G2STAT_MBXOUT) break;
if (loopcnt == LOOPCNT_WARN) {
printk("aha1740[%d]_mbxout wait!\n",ecbno);
}
if (loopcnt == LOOPCNT_MAX)
panic("aha1740.c: mbxout busy!\n");
}
outl (ecb_cpu_to_dma (SCpnt->device->host, host->ecb + ecbno),
MBOXOUT0(base));
for (loopcnt = 0; ; loopcnt++) {
if (! (inb(G2STAT(base)) & G2STAT_BUSY)) break;
if (loopcnt == LOOPCNT_WARN) {
printk("aha1740[%d]_attn wait!\n",ecbno);
}
if (loopcnt == LOOPCNT_MAX)
panic("aha1740.c: attn wait failed!\n");
}
outb(ATTN_START | (target & 7), ATTN(base));
spin_unlock_irqrestore(SCpnt->device->host->host_lock, flags);
DEB(printk("aha1740[%d] request queued.\n",ecbno));
} else
printk(KERN_ALERT "aha1740_queuecommand: done can't be NULL\n");
return 0;
}
int aha1740_eh_abort_handler (Scsi_Cmnd *dummy)
{
return 0;
}
static int aha1740_probe (struct device *dev)
{
int slotbase, rc;
unsigned int irq_level, irq_type, translation;
struct Scsi_Host *shpnt;
struct aha1740_hostdata *host;
struct eisa_device *edev = to_eisa_device (dev);
DEB(printk("aha1740_probe: \n"));
slotbase = edev->base_addr + EISA_VENDOR_ID_OFFSET;
if (!request_region(slotbase, SLOTSIZE, "aha1740"))
return -EBUSY;
if (!aha1740_test_port(slotbase))
goto err_release_region;
aha1740_getconfig(slotbase,&irq_level,&irq_type,&translation);
if ((inb(G2STAT(slotbase)) &
(G2STAT_MBXOUT|G2STAT_BUSY)) != G2STAT_MBXOUT) {
outb(G2CNTRL_HRST, G2CNTRL(slotbase));
outb(0, G2CNTRL(slotbase));
}
printk(KERN_INFO "Configuring slot %d at IO:%x, IRQ %u (%s)\n",
edev->slot, slotbase, irq_level, irq_type ? "edge" : "level");
printk(KERN_INFO "aha174x: Extended translation %sabled.\n",
translation ? "en" : "dis");
shpnt = scsi_host_alloc(&aha1740_template,
sizeof(struct aha1740_hostdata));
if(shpnt == NULL)
goto err_release_region;
shpnt->base = 0;
shpnt->io_port = slotbase;
shpnt->n_io_port = SLOTSIZE;
shpnt->irq = irq_level;
shpnt->dma_channel = 0xff;
host = HOSTDATA(shpnt);
host->edev = edev;
host->translation = translation;
host->ecb_dma_addr = dma_map_single (&edev->dev, host->ecb,
sizeof (host->ecb),
DMA_BIDIRECTIONAL);
if (!host->ecb_dma_addr) {
printk (KERN_ERR "aha1740_probe: Couldn't map ECB, giving up\n");
scsi_unregister (shpnt);
goto err_host_put;
}
DEB(printk("aha1740_probe: enable interrupt channel %d\n",irq_level));
if (request_irq(irq_level,aha1740_intr_handle,irq_type ? 0 : IRQF_SHARED,
"aha1740",shpnt)) {
printk(KERN_ERR "aha1740_probe: Unable to allocate IRQ %d.\n",
irq_level);
goto err_unmap;
}
eisa_set_drvdata (edev, shpnt);
rc = scsi_add_host (shpnt, dev);
if (rc)
goto err_irq;
scsi_scan_host (shpnt);
return 0;
err_irq:
free_irq(irq_level, shpnt);
err_unmap:
dma_unmap_single (&edev->dev, host->ecb_dma_addr,
sizeof (host->ecb), DMA_BIDIRECTIONAL);
err_host_put:
scsi_host_put (shpnt);
err_release_region:
release_region(slotbase, SLOTSIZE);
return -ENODEV;
}
static int aha1740_remove (struct device *dev)
{
struct Scsi_Host *shpnt = dev_get_drvdata(dev);
struct aha1740_hostdata *host = HOSTDATA (shpnt);
scsi_remove_host(shpnt);
free_irq (shpnt->irq, shpnt);
dma_unmap_single (dev, host->ecb_dma_addr,
sizeof (host->ecb), DMA_BIDIRECTIONAL);
release_region (shpnt->io_port, SLOTSIZE);
scsi_host_put (shpnt);
return 0;
}
static __init int aha1740_init (void)
{
return eisa_driver_register (&aha1740_driver);
}
static __exit void aha1740_exit (void)
{
eisa_driver_unregister (&aha1740_driver);
}
