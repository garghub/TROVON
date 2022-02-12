static inline unsigned char sun3scsi_read(int reg)
{
return( sun3_scsi_regp[reg] );
}
static inline void sun3scsi_write(int reg, int value)
{
sun3_scsi_regp[reg] = value;
}
static int sun3scsi_detect(struct scsi_host_template * tpnt)
{
unsigned long ioaddr, irq = 0;
static int called = 0;
struct Scsi_Host *instance;
int i;
unsigned long addrs[3] = { IOBASE_SUN3_VMESCSI,
IOBASE_SUN3_VMESCSI + 0x4000,
0 };
unsigned long vecs[3] = { SUN3_VEC_VMESCSI0,
SUN3_VEC_VMESCSI1,
0 };
switch(idprom->id_machtype) {
case SM_SUN3|SM_3_160:
case SM_SUN3|SM_3_260:
break;
default:
return 0;
}
if(called)
return 0;
tpnt->proc_name = "Sun3 5380 VME SCSI";
tpnt->can_queue =
(setup_can_queue > 0) ? setup_can_queue : CAN_QUEUE;
tpnt->cmd_per_lun =
(setup_cmd_per_lun > 0) ? setup_cmd_per_lun : CMD_PER_LUN;
tpnt->sg_tablesize =
(setup_sg_tablesize >= 0) ? setup_sg_tablesize : SG_TABLESIZE;
if (setup_hostid >= 0)
tpnt->this_id = setup_hostid;
else {
tpnt->this_id = 7;
}
ioaddr = 0;
for(i = 0; addrs[i] != 0; i++) {
unsigned char x;
ioaddr = (unsigned long)sun3_ioremap(addrs[i], PAGE_SIZE,
SUN3_PAGE_TYPE_VME16);
irq = vecs[i];
sun3_scsi_regp = (unsigned char *)ioaddr;
dregs = (struct sun3_dma_regs *)(((unsigned char *)ioaddr) + 8);
if(sun3_map_test((unsigned long)dregs, &x)) {
unsigned short oldcsr;
oldcsr = dregs->csr;
dregs->csr = 0;
udelay(SUN3_DMA_DELAY);
if(dregs->csr == 0x1400)
break;
dregs->csr = oldcsr;
}
iounmap((void *)ioaddr);
ioaddr = 0;
}
if(!ioaddr)
return 0;
#ifdef SUPPORT_TAGS
if (setup_use_tagged_queuing < 0)
setup_use_tagged_queuing = USE_TAGGED_QUEUING;
#endif
instance = scsi_register (tpnt, sizeof(struct NCR5380_hostdata));
if(instance == NULL)
return 0;
default_instance = instance;
instance->io_port = (unsigned long) ioaddr;
instance->irq = irq;
NCR5380_init(instance, 0);
instance->n_io_port = 32;
((struct NCR5380_hostdata *)instance->hostdata)->ctrl = 0;
if (request_irq(instance->irq, scsi_sun3_intr,
0, "Sun3SCSI-5380VME", instance)) {
#ifndef REAL_DMA
printk("scsi%d: IRQ%d not free, interrupts disabled\n",
instance->host_no, instance->irq);
instance->irq = SCSI_IRQ_NONE;
#else
printk("scsi%d: IRQ%d not free, bailing out\n",
instance->host_no, instance->irq);
return 0;
#endif
}
printk("scsi%d: Sun3 5380 VME at port %lX irq", instance->host_no, instance->io_port);
if (instance->irq == SCSI_IRQ_NONE)
printk ("s disabled");
else
printk (" %d", instance->irq);
printk(" options CAN_QUEUE=%d CMD_PER_LUN=%d release=%d",
instance->can_queue, instance->cmd_per_lun,
SUN3SCSI_PUBLIC_RELEASE);
printk("\nscsi%d:", instance->host_no);
NCR5380_print_options(instance);
printk("\n");
dregs->csr = 0;
udelay(SUN3_DMA_DELAY);
dregs->csr = CSR_SCSI | CSR_FIFO | CSR_INTR;
udelay(SUN3_DMA_DELAY);
dregs->fifo_count = 0;
dregs->fifo_count_hi = 0;
dregs->dma_addr_hi = 0;
dregs->dma_addr_lo = 0;
dregs->dma_count_hi = 0;
dregs->dma_count_lo = 0;
dregs->ivect = VME_DATA24 | (instance->irq & 0xff);
called = 1;
#ifdef RESET_BOOT
sun3_scsi_reset_boot(instance);
#endif
return 1;
}
int sun3scsi_release (struct Scsi_Host *shpnt)
{
if (shpnt->irq != SCSI_IRQ_NONE)
free_irq(shpnt->irq, shpnt);
iounmap((void *)sun3_scsi_regp);
return 0;
}
static void sun3_scsi_reset_boot(struct Scsi_Host *instance)
{
unsigned long end;
NCR5380_local_declare();
NCR5380_setup(instance);
printk( "Sun3 SCSI: resetting the SCSI bus..." );
NCR5380_write( TARGET_COMMAND_REG,
PHASE_SR_TO_TCR( NCR5380_read(STATUS_REG) ));
NCR5380_write( INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_RST );
udelay( 50 );
NCR5380_write( INITIATOR_COMMAND_REG, ICR_BASE );
NCR5380_read( RESET_PARITY_INTERRUPT_REG );
for( end = jiffies + AFTER_RESET_DELAY; time_before(jiffies, end); )
barrier();
printk( " done\n" );
}
static const char * sun3scsi_info (struct Scsi_Host *spnt) {
return "";
}
static irqreturn_t scsi_sun3_intr(int irq, void *dummy)
{
unsigned short csr = dregs->csr;
int handled = 0;
dregs->csr &= ~CSR_DMA_ENABLE;
#ifdef SUN3_SCSI_DEBUG
printk("scsi_intr csr %x\n", csr);
#endif
if(csr & ~CSR_GOOD) {
if(csr & CSR_DMA_BUSERR) {
printk("scsi%d: bus error in dma\n", default_instance->host_no);
#ifdef SUN3_SCSI_DEBUG
printk("scsi: residual %x count %x addr %p dmaaddr %x\n",
dregs->fifo_count,
dregs->dma_count_lo | (dregs->dma_count_hi << 16),
sun3_dma_orig_addr,
dregs->dma_addr_lo | (dregs->dma_addr_hi << 16));
#endif
}
if(csr & CSR_DMA_CONFLICT) {
printk("scsi%d: dma conflict\n", default_instance->host_no);
}
handled = 1;
}
if(csr & (CSR_SDB_INT | CSR_DMA_INT)) {
NCR5380_intr(irq, dummy);
handled = 1;
}
return IRQ_RETVAL(handled);
}
static unsigned long sun3scsi_dma_setup(void *data, unsigned long count, int write_flag)
{
void *addr;
if(sun3_dma_orig_addr != NULL)
dvma_unmap(sun3_dma_orig_addr);
addr = (void *)dvma_map_vme((unsigned long) data, count);
sun3_dma_orig_addr = addr;
sun3_dma_orig_count = count;
#ifdef SUN3_SCSI_DEBUG
printk("scsi: dma_setup addr %p count %x\n", addr, count);
#endif
#if 0
dregs->csr &= ~CSR_FIFO;
dregs->csr |= CSR_FIFO;
#endif
if(write_flag)
dregs->csr |= CSR_SEND;
else
dregs->csr &= ~CSR_SEND;
dregs->csr |= CSR_PACK_ENABLE;
dregs->dma_addr_hi = ((unsigned long)addr >> 16);
dregs->dma_addr_lo = ((unsigned long)addr & 0xffff);
dregs->dma_count_hi = 0;
dregs->dma_count_lo = 0;
dregs->fifo_count_hi = 0;
dregs->fifo_count = 0;
#ifdef SUN3_SCSI_DEBUG
printk("scsi: dma_setup done csr %x\n", dregs->csr);
#endif
return count;
}
static inline unsigned long sun3scsi_dma_residual(struct Scsi_Host *instance)
{
return last_residual;
}
static inline unsigned long sun3scsi_dma_xfer_len(unsigned long wanted,
struct scsi_cmnd *cmd,
int write_flag)
{
if (cmd->request->cmd_type == REQ_TYPE_FS)
return wanted;
else
return 0;
}
static int sun3scsi_dma_start(unsigned long count, char *data)
{
unsigned short csr;
csr = dregs->csr;
#ifdef SUN3_SCSI_DEBUG
printk("scsi: dma_start data %p count %x csr %x fifo %x\n", data, count, csr, dregs->fifo_count);
#endif
dregs->dma_count_hi = (sun3_dma_orig_count >> 16);
dregs->dma_count_lo = (sun3_dma_orig_count & 0xffff);
dregs->fifo_count_hi = (sun3_dma_orig_count >> 16);
dregs->fifo_count = (sun3_dma_orig_count & 0xffff);
return 0;
}
static int sun3scsi_dma_finish(int write_flag)
{
unsigned short fifo;
int ret = 0;
sun3_dma_active = 0;
dregs->csr &= ~CSR_DMA_ENABLE;
fifo = dregs->fifo_count;
if(write_flag) {
if((fifo > 0) && (fifo < sun3_dma_orig_count))
fifo++;
}
last_residual = fifo;
#ifdef SUN3_SCSI_DEBUG
printk("scsi: residual %x total %x\n", fifo, sun3_dma_orig_count);
#endif
if((!write_flag) && (dregs->csr & CSR_LEFT)) {
unsigned char *vaddr;
#ifdef SUN3_SCSI_DEBUG
printk("scsi: got left over bytes\n");
#endif
vaddr = (unsigned char *)dvma_vmetov(sun3_dma_orig_addr);
vaddr += (sun3_dma_orig_count - fifo);
vaddr--;
switch(dregs->csr & CSR_LEFT) {
case CSR_LEFT_3:
*vaddr = (dregs->bpack_lo & 0xff00) >> 8;
vaddr--;
case CSR_LEFT_2:
*vaddr = (dregs->bpack_hi & 0x00ff);
vaddr--;
case CSR_LEFT_1:
*vaddr = (dregs->bpack_hi & 0xff00) >> 8;
break;
}
}
dvma_unmap(sun3_dma_orig_addr);
sun3_dma_orig_addr = NULL;
dregs->dma_addr_hi = 0;
dregs->dma_addr_lo = 0;
dregs->dma_count_hi = 0;
dregs->dma_count_lo = 0;
dregs->fifo_count = 0;
dregs->fifo_count_hi = 0;
dregs->csr &= ~CSR_SEND;
#if 0
dregs->csr &= ~CSR_FIFO;
dregs->csr |= CSR_FIFO;
#endif
sun3_dma_setup_done = NULL;
return ret;
}
