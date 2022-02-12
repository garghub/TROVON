static __inline__ char macscsi_read(struct Scsi_Host *instance, int reg)
{
return in_8(instance->io_port + (reg<<4));
}
static __inline__ void macscsi_write(struct Scsi_Host *instance, int reg, int value)
{
out_8(instance->io_port + (reg<<4), value);
}
static int __init mac_scsi_setup(char *str) {
#ifdef DRIVER_SETUP
int ints[7];
(void)get_options( str, ARRAY_SIZE(ints), ints);
if (setup_called++ || ints[0] < 1 || ints[0] > 6) {
printk(KERN_WARNING "scsi: <mac5380>"
" Usage: mac5380=<can_queue>[,<cmd_per_lun>,<sg_tablesize>,<hostid>,<use_tags>,<use_pdma>]\n");
printk(KERN_ALERT "scsi: <mac5380> Bad Penguin parameters?\n");
return 0;
}
if (ints[0] >= 1) {
if (ints[1] > 0)
setup_can_queue = ints[1];
}
if (ints[0] >= 2) {
if (ints[2] > 0)
setup_cmd_per_lun = ints[2];
}
if (ints[0] >= 3) {
if (ints[3] >= 0) {
setup_sg_tablesize = ints[3];
if (setup_sg_tablesize > SG_ALL)
setup_sg_tablesize = SG_ALL;
}
}
if (ints[0] >= 4) {
if (ints[4] >= 0 && ints[4] <= 7)
setup_hostid = ints[4];
else if (ints[4] > 7)
printk(KERN_WARNING "mac_scsi_setup: invalid host ID %d !\n", ints[4] );
}
#ifdef SUPPORT_TAGS
if (ints[0] >= 5) {
if (ints[5] >= 0)
setup_use_tagged_queuing = !!ints[5];
}
if (ints[0] == 6) {
if (ints[6] >= 0)
setup_use_pdma = ints[6];
}
#else
if (ints[0] == 5) {
if (ints[5] >= 0)
setup_use_pdma = ints[5];
}
#endif
#endif
return 1;
}
int __init macscsi_detect(struct scsi_host_template * tpnt)
{
static int called = 0;
int flags = 0;
struct Scsi_Host *instance;
if (!MACH_IS_MAC || called)
return( 0 );
if (macintosh_config->scsi_type != MAC_SCSI_OLD)
return( 0 );
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
#ifdef SUPPORT_TAGS
if (setup_use_tagged_queuing < 0)
setup_use_tagged_queuing = USE_TAGGED_QUEUING;
#endif
instance = scsi_register (tpnt, sizeof(struct NCR5380_hostdata));
if (instance == NULL)
return 0;
if (macintosh_config->ident == MAC_MODEL_IIFX) {
mac_scsi_regp = via1+0x8000;
mac_scsi_drq = via1+0xE000;
mac_scsi_nodrq = via1+0xC000;
flags = FLAG_NO_PSEUDO_DMA;
} else {
mac_scsi_regp = via1+0x10000;
mac_scsi_drq = via1+0x6000;
mac_scsi_nodrq = via1+0x12000;
}
if (! setup_use_pdma)
flags = FLAG_NO_PSEUDO_DMA;
instance->io_port = (unsigned long) mac_scsi_regp;
instance->irq = IRQ_MAC_SCSI;
#ifdef RESET_BOOT
mac_scsi_reset_boot(instance);
#endif
NCR5380_init(instance, flags);
instance->n_io_port = 255;
((struct NCR5380_hostdata *)instance->hostdata)->ctrl = 0;
if (instance->irq != SCSI_IRQ_NONE)
if (request_irq(instance->irq, NCR5380_intr, 0, "ncr5380", instance)) {
printk(KERN_WARNING "scsi%d: IRQ%d not free, interrupts disabled\n",
instance->host_no, instance->irq);
instance->irq = SCSI_IRQ_NONE;
}
printk(KERN_INFO "scsi%d: generic 5380 at port %lX irq", instance->host_no, instance->io_port);
if (instance->irq == SCSI_IRQ_NONE)
printk (KERN_INFO "s disabled");
else
printk (KERN_INFO " %d", instance->irq);
printk(KERN_INFO " options CAN_QUEUE=%d CMD_PER_LUN=%d release=%d",
instance->can_queue, instance->cmd_per_lun, MACSCSI_PUBLIC_RELEASE);
printk(KERN_INFO "\nscsi%d:", instance->host_no);
NCR5380_print_options(instance);
printk("\n");
called = 1;
return 1;
}
int macscsi_release (struct Scsi_Host *shpnt)
{
if (shpnt->irq != SCSI_IRQ_NONE)
free_irq(shpnt->irq, shpnt);
NCR5380_exit(shpnt);
return 0;
}
static void mac_scsi_reset_boot(struct Scsi_Host *instance)
{
unsigned long end;
NCR5380_local_declare();
NCR5380_setup(instance);
printk(KERN_INFO "Macintosh SCSI: resetting the SCSI bus..." );
NCR5380_write( TARGET_COMMAND_REG,
PHASE_SR_TO_TCR( NCR5380_read(STATUS_REG) ));
NCR5380_write( INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_RST );
udelay( 50 );
NCR5380_write( INITIATOR_COMMAND_REG, ICR_BASE );
NCR5380_read( RESET_PARITY_INTERRUPT_REG );
for( end = jiffies + AFTER_RESET_DELAY; time_before(jiffies, end); )
barrier();
printk(KERN_INFO " done\n" );
}
const char * macscsi_info (struct Scsi_Host *spnt) {
return "";
}
static int macscsi_pread (struct Scsi_Host *instance,
unsigned char *dst, int len)
{
unsigned char *d;
volatile unsigned char *s;
NCR5380_local_declare();
NCR5380_setup(instance);
s = mac_scsi_drq+0x60;
d = dst;
while (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_DRQ)
&& !(NCR5380_read(STATUS_REG) & SR_REQ))
;
if (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_DRQ)
&& (NCR5380_read(BUS_AND_STATUS_REG) & BASR_PHASE_MATCH)) {
printk(KERN_ERR "Error in macscsi_pread\n");
return -1;
}
CP_IO_TO_MEM(s, d, len);
if (len != 0) {
printk(KERN_NOTICE "Bus error in macscsi_pread\n");
return -1;
}
return 0;
}
static int macscsi_pwrite (struct Scsi_Host *instance,
unsigned char *src, int len)
{
unsigned char *s;
volatile unsigned char *d;
NCR5380_local_declare();
NCR5380_setup(instance);
s = src;
d = mac_scsi_drq;
while (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_DRQ)
&& (!(NCR5380_read(STATUS_REG) & SR_REQ)
|| (NCR5380_read(BUS_AND_STATUS_REG) & BASR_PHASE_MATCH)))
;
if (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_DRQ)) {
printk(KERN_ERR "Error in macscsi_pwrite\n");
return -1;
}
CP_MEM_TO_IO(s, d, len);
if (len != 0) {
printk(KERN_NOTICE "Bus error in macscsi_pwrite\n");
return -1;
}
return 0;
}
