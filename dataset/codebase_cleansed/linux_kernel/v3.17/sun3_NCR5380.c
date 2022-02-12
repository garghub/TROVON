static void __init init_tags( void )
{
int target, lun;
TAG_ALLOC *ta;
if (!setup_use_tagged_queuing)
return;
for( target = 0; target < 8; ++target ) {
for( lun = 0; lun < 8; ++lun ) {
ta = &TagAlloc[target][lun];
memset( &ta->allocated, 0, MAX_TAGS/8 );
ta->nr_allocated = 0;
ta->queue_size = MAX_TAGS;
}
}
}
static int is_lun_busy(struct scsi_cmnd *cmd, int should_be_tagged)
{
u8 lun = cmd->device->lun;
SETUP_HOSTDATA(cmd->device->host);
if (hostdata->busy[cmd->device->id] & (1 << lun))
return( 1 );
if (!should_be_tagged ||
!setup_use_tagged_queuing || !cmd->device->tagged_supported)
return( 0 );
if (TagAlloc[cmd->device->id][lun].nr_allocated >=
TagAlloc[cmd->device->id][lun].queue_size ) {
dprintk(NDEBUG_TAGS, "scsi%d: target %d lun %d: no free tags\n",
H_NO(cmd), cmd->device->id, lun );
return( 1 );
}
return( 0 );
}
static void cmd_get_tag(struct scsi_cmnd *cmd, int should_be_tagged)
{
u8 lun = cmd->device->lun;
SETUP_HOSTDATA(cmd->device->host);
if (!should_be_tagged ||
!setup_use_tagged_queuing || !cmd->device->tagged_supported) {
cmd->tag = TAG_NONE;
hostdata->busy[cmd->device->id] |= (1 << lun);
dprintk(NDEBUG_TAGS, "scsi%d: target %d lun %d now allocated by untagged "
"command\n", H_NO(cmd), cmd->device->id, lun );
}
else {
TAG_ALLOC *ta = &TagAlloc[cmd->device->id][lun];
cmd->tag = find_first_zero_bit( &ta->allocated, MAX_TAGS );
set_bit( cmd->tag, &ta->allocated );
ta->nr_allocated++;
dprintk(NDEBUG_TAGS, "scsi%d: using tag %d for target %d lun %d "
"(now %d tags in use)\n",
H_NO(cmd), cmd->tag, cmd->device->id, lun,
ta->nr_allocated );
}
}
static void cmd_free_tag(struct scsi_cmnd *cmd)
{
u8 lun = cmd->device->lun;
SETUP_HOSTDATA(cmd->device->host);
if (cmd->tag == TAG_NONE) {
hostdata->busy[cmd->device->id] &= ~(1 << lun);
dprintk(NDEBUG_TAGS, "scsi%d: target %d lun %d untagged cmd finished\n",
H_NO(cmd), cmd->device->id, lun );
}
else if (cmd->tag >= MAX_TAGS) {
printk(KERN_NOTICE "scsi%d: trying to free bad tag %d!\n",
H_NO(cmd), cmd->tag );
}
else {
TAG_ALLOC *ta = &TagAlloc[cmd->device->id][lun];
clear_bit( cmd->tag, &ta->allocated );
ta->nr_allocated--;
dprintk(NDEBUG_TAGS, "scsi%d: freed tag %d for target %d lun %d\n",
H_NO(cmd), cmd->tag, cmd->device->id, lun );
}
}
static void free_all_tags( void )
{
int target, lun;
TAG_ALLOC *ta;
if (!setup_use_tagged_queuing)
return;
for( target = 0; target < 8; ++target ) {
for( lun = 0; lun < 8; ++lun ) {
ta = &TagAlloc[target][lun];
memset( &ta->allocated, 0, MAX_TAGS/8 );
ta->nr_allocated = 0;
}
}
}
static __inline__ void initialize_SCp(struct scsi_cmnd *cmd)
{
if (scsi_bufflen(cmd)) {
cmd->SCp.buffer = scsi_sglist(cmd);
cmd->SCp.buffers_residual = scsi_sg_count(cmd) - 1;
cmd->SCp.ptr = (char *) SGADDR(cmd->SCp.buffer);
cmd->SCp.this_residual = cmd->SCp.buffer->length;
} else {
cmd->SCp.buffer = NULL;
cmd->SCp.buffers_residual = 0;
cmd->SCp.ptr = NULL;
cmd->SCp.this_residual = 0;
}
}
static void NCR5380_print(struct Scsi_Host *instance) {
unsigned char status, data, basr, mr, icr, i;
unsigned long flags;
local_irq_save(flags);
data = NCR5380_read(CURRENT_SCSI_DATA_REG);
status = NCR5380_read(STATUS_REG);
mr = NCR5380_read(MODE_REG);
icr = NCR5380_read(INITIATOR_COMMAND_REG);
basr = NCR5380_read(BUS_AND_STATUS_REG);
local_irq_restore(flags);
printk("STATUS_REG: %02x ", status);
for (i = 0; signals[i].mask ; ++i)
if (status & signals[i].mask)
printk(",%s", signals[i].name);
printk("\nBASR: %02x ", basr);
for (i = 0; basrs[i].mask ; ++i)
if (basr & basrs[i].mask)
printk(",%s", basrs[i].name);
printk("\nICR: %02x ", icr);
for (i = 0; icrs[i].mask; ++i)
if (icr & icrs[i].mask)
printk(",%s", icrs[i].name);
printk("\nMODE: %02x ", mr);
for (i = 0; mrs[i].mask; ++i)
if (mr & mrs[i].mask)
printk(",%s", mrs[i].name);
printk("\n");
}
static void NCR5380_print_phase(struct Scsi_Host *instance)
{
unsigned char status;
int i;
status = NCR5380_read(STATUS_REG);
if (!(status & SR_REQ))
printk(KERN_DEBUG "scsi%d: REQ not asserted, phase unknown.\n", HOSTNO);
else {
for (i = 0; (phases[i].value != PHASE_UNKNOWN) &&
(phases[i].value != (status & PHASE_MASK)); ++i);
printk(KERN_DEBUG "scsi%d: phase %s\n", HOSTNO, phases[i].name);
}
}
static __inline__ void queue_main(void)
{
if (!main_running) {
schedule_work(&NCR5380_tqueue);
}
}
static inline void NCR5380_all_init (void)
{
static int done = 0;
if (!done) {
dprintk(NDEBUG_INIT, "scsi : NCR5380_all_init()\n");
done = 1;
}
}
static void __init NCR5380_print_options (struct Scsi_Host *instance)
{
printk(" generic options"
#ifdef AUTOSENSE
" AUTOSENSE"
#endif
#ifdef REAL_DMA
" REAL DMA"
#endif
#ifdef PARITY
" PARITY"
#endif
#ifdef SUPPORT_TAGS
" SCSI-2 TAGGED QUEUING"
#endif
);
printk(" generic release=%d", NCR5380_PUBLIC_RELEASE);
}
static void lprint_Scsi_Cmnd(Scsi_Cmnd *cmd)
{
int i, s;
unsigned char *command;
printk("scsi%d: destination target %d, lun %llu\n",
H_NO(cmd), cmd->device->id, cmd->device->lun);
printk(KERN_CONT " command = ");
command = cmd->cmnd;
printk(KERN_CONT "%2d (0x%02x)", command[0], command[0]);
for (i = 1, s = COMMAND_SIZE(command[0]); i < s; ++i)
printk(KERN_CONT " %02x", command[i]);
printk("\n");
}
static void NCR5380_print_status(struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata;
Scsi_Cmnd *ptr;
unsigned long flags;
NCR5380_dprint(NDEBUG_ANY, instance);
NCR5380_dprint_phase(NDEBUG_ANY, instance);
hostdata = (struct NCR5380_hostdata *)instance->hostdata;
printk("\nNCR5380 core release=%d.\n", NCR5380_PUBLIC_RELEASE);
local_irq_save(flags);
printk("NCR5380: coroutine is%s running.\n",
main_running ? "" : "n't");
if (!hostdata->connected)
printk("scsi%d: no currently connected command\n", HOSTNO);
else
lprint_Scsi_Cmnd((Scsi_Cmnd *) hostdata->connected);
printk("scsi%d: issue_queue\n", HOSTNO);
for (ptr = (Scsi_Cmnd *)hostdata->issue_queue; ptr; ptr = NEXT(ptr))
lprint_Scsi_Cmnd(ptr);
printk("scsi%d: disconnected_queue\n", HOSTNO);
for (ptr = (Scsi_Cmnd *) hostdata->disconnected_queue; ptr;
ptr = NEXT(ptr))
lprint_Scsi_Cmnd(ptr);
local_irq_restore(flags);
printk("\n");
}
static void show_Scsi_Cmnd(Scsi_Cmnd *cmd, struct seq_file *m)
{
int i, s;
unsigned char *command;
seq_printf(m, "scsi%d: destination target %d, lun %llu\n",
H_NO(cmd), cmd->device->id, cmd->device->lun);
seq_printf(m, " command = ");
command = cmd->cmnd;
seq_printf(m, "%2d (0x%02x)", command[0], command[0]);
for (i = 1, s = COMMAND_SIZE(command[0]); i < s; ++i)
seq_printf(m, " %02x", command[i]);
seq_printf(m, "\n");
}
static int NCR5380_show_info(struct seq_file *m, struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata;
Scsi_Cmnd *ptr;
unsigned long flags;
hostdata = (struct NCR5380_hostdata *)instance->hostdata;
seq_printf(m, "NCR5380 core release=%d.\n", NCR5380_PUBLIC_RELEASE);
local_irq_save(flags);
seq_printf(m, "NCR5380: coroutine is%s running.\n",
main_running ? "" : "n't");
if (!hostdata->connected)
seq_printf(m, "scsi%d: no currently connected command\n", HOSTNO);
else
show_Scsi_Cmnd((Scsi_Cmnd *) hostdata->connected, m);
seq_printf(m, "scsi%d: issue_queue\n", HOSTNO);
for (ptr = (Scsi_Cmnd *)hostdata->issue_queue; ptr; ptr = NEXT(ptr))
show_Scsi_Cmnd(ptr, m);
seq_printf(m, "scsi%d: disconnected_queue\n", HOSTNO);
for (ptr = (Scsi_Cmnd *) hostdata->disconnected_queue; ptr;
ptr = NEXT(ptr))
show_Scsi_Cmnd(ptr, m);
local_irq_restore(flags);
return 0;
}
static int __init NCR5380_init(struct Scsi_Host *instance, int flags)
{
int i;
SETUP_HOSTDATA(instance);
NCR5380_all_init();
hostdata->aborted = 0;
hostdata->id_mask = 1 << instance->this_id;
hostdata->id_higher_mask = 0;
for (i = hostdata->id_mask; i <= 0x80; i <<= 1)
if (i > hostdata->id_mask)
hostdata->id_higher_mask |= i;
for (i = 0; i < 8; ++i)
hostdata->busy[i] = 0;
#ifdef SUPPORT_TAGS
init_tags();
#endif
#if defined (REAL_DMA)
hostdata->dma_len = 0;
#endif
hostdata->targets_present = 0;
hostdata->connected = NULL;
hostdata->issue_queue = NULL;
hostdata->disconnected_queue = NULL;
hostdata->flags = FLAG_CHECK_LAST_BYTE_SENT;
if (!the_template) {
the_template = instance->hostt;
first_instance = instance;
}
#ifndef AUTOSENSE
if ((instance->cmd_per_lun > 1) || (instance->can_queue > 1))
printk("scsi%d: WARNING : support for multiple outstanding commands enabled\n"
" without AUTOSENSE option, contingent allegiance conditions may\n"
" be incorrectly cleared.\n", HOSTNO);
#endif
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(TARGET_COMMAND_REG, 0);
NCR5380_write(SELECT_ENABLE_REG, 0);
return 0;
}
static void NCR5380_exit(struct Scsi_Host *instance)
{
}
static int NCR5380_queue_command_lck(struct scsi_cmnd *cmd,
void (*done)(struct scsi_cmnd *))
{
SETUP_HOSTDATA(cmd->device->host);
struct scsi_cmnd *tmp;
unsigned long flags;
#if (NDEBUG & NDEBUG_NO_WRITE)
switch (cmd->cmnd[0]) {
case WRITE_6:
case WRITE_10:
printk(KERN_NOTICE "scsi%d: WRITE attempted with NO_WRITE debugging flag set\n",
H_NO(cmd));
cmd->result = (DID_ERROR << 16);
done(cmd);
return 0;
}
#endif
#ifdef NCR5380_STATS
# if 0
if (!hostdata->connected && !hostdata->issue_queue &&
!hostdata->disconnected_queue) {
hostdata->timebase = jiffies;
}
# endif
# ifdef NCR5380_STAT_LIMIT
if (scsi_bufflen(cmd) > NCR5380_STAT_LIMIT)
# endif
switch (cmd->cmnd[0])
{
case WRITE:
case WRITE_6:
case WRITE_10:
hostdata->time_write[cmd->device->id] -= (jiffies - hostdata->timebase);
hostdata->bytes_write[cmd->device->id] += scsi_bufflen(cmd);
hostdata->pendingw++;
break;
case READ:
case READ_6:
case READ_10:
hostdata->time_read[cmd->device->id] -= (jiffies - hostdata->timebase);
hostdata->bytes_read[cmd->device->id] += scsi_bufflen(cmd);
hostdata->pendingr++;
break;
}
#endif
SET_NEXT(cmd, NULL);
cmd->scsi_done = done;
cmd->result = 0;
local_irq_save(flags);
if (!(hostdata->issue_queue) || (cmd->cmnd[0] == REQUEST_SENSE)) {
LIST(cmd, hostdata->issue_queue);
SET_NEXT(cmd, hostdata->issue_queue);
hostdata->issue_queue = cmd;
} else {
for (tmp = (struct scsi_cmnd *)hostdata->issue_queue;
NEXT(tmp); tmp = NEXT(tmp))
;
LIST(cmd, tmp);
SET_NEXT(tmp, cmd);
}
local_irq_restore(flags);
dprintk(NDEBUG_QUEUES, "scsi%d: command added to %s of queue\n", H_NO(cmd),
(cmd->cmnd[0] == REQUEST_SENSE) ? "head" : "tail");
if (in_interrupt() || ((flags >> 8) & 7) >= 6)
queue_main();
else
NCR5380_main(NULL);
return 0;
}
void NCR5380_dma_complete( struct Scsi_Host *instance )
{
SETUP_HOSTDATA(instance);
int transfered;
unsigned char **data;
volatile int *count;
if (!hostdata->connected) {
printk(KERN_WARNING "scsi%d: received end of DMA interrupt with "
"no connected cmd\n", HOSTNO);
return;
}
dprintk(NDEBUG_DMA, "scsi%d: real DMA transfer complete, basr 0x%X, sr 0x%X\n",
HOSTNO, NCR5380_read(BUS_AND_STATUS_REG),
NCR5380_read(STATUS_REG));
if((sun3scsi_dma_finish(rq_data_dir(hostdata->connected->request)))) {
printk("scsi%d: overrun in UDC counter -- not prepared to deal with this!\n", HOSTNO);
printk("please e-mail sammy@sammy.net with a description of how this\n");
printk("error was produced.\n");
BUG();
}
if((NCR5380_read(BUS_AND_STATUS_REG) & (BASR_PHASE_MATCH |
BASR_ACK)) ==
(BASR_PHASE_MATCH | BASR_ACK)) {
printk("scsi%d: BASR %02x\n", HOSTNO, NCR5380_read(BUS_AND_STATUS_REG));
printk("scsi%d: bus stuck in data phase -- probably a single byte "
"overrun!\n", HOSTNO);
printk("not prepared for this error!\n");
printk("please e-mail sammy@sammy.net with a description of how this\n");
printk("error was produced.\n");
BUG();
}
(void) NCR5380_read(RESET_PARITY_INTERRUPT_REG);
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
transfered = hostdata->dma_len - NCR5380_dma_residual(instance);
hostdata->dma_len = 0;
data = (unsigned char **) &(hostdata->connected->SCp.ptr);
count = &(hostdata->connected->SCp.this_residual);
*data += transfered;
*count -= transfered;
}
static irqreturn_t NCR5380_intr (int irq, void *dev_id)
{
struct Scsi_Host *instance = first_instance;
int done = 1, handled = 0;
unsigned char basr;
dprintk(NDEBUG_INTR, "scsi%d: NCR5380 irq triggered\n", HOSTNO);
basr = NCR5380_read(BUS_AND_STATUS_REG);
dprintk(NDEBUG_INTR, "scsi%d: BASR=%02x\n", HOSTNO, basr);
if (basr & BASR_IRQ) {
NCR5380_dprint(NDEBUG_INTR, instance);
if ((NCR5380_read(STATUS_REG) & (SR_SEL|SR_IO)) == (SR_SEL|SR_IO)) {
done = 0;
dprintk(NDEBUG_INTR, "scsi%d: SEL interrupt\n", HOSTNO);
NCR5380_reselect(instance);
(void) NCR5380_read(RESET_PARITY_INTERRUPT_REG);
}
else if (basr & BASR_PARITY_ERROR) {
dprintk(NDEBUG_INTR, "scsi%d: PARITY interrupt\n", HOSTNO);
(void) NCR5380_read(RESET_PARITY_INTERRUPT_REG);
}
else if ((NCR5380_read(STATUS_REG) & SR_RST) == SR_RST) {
dprintk(NDEBUG_INTR, "scsi%d: RESET interrupt\n", HOSTNO);
(void)NCR5380_read(RESET_PARITY_INTERRUPT_REG);
}
else {
#if defined(REAL_DMA)
if ((NCR5380_read(MODE_REG) & MR_DMA_MODE) &&
((basr & BASR_END_DMA_TRANSFER) ||
!(basr & BASR_PHASE_MATCH))) {
dprintk(NDEBUG_INTR, "scsi%d: PHASE MISM or EOP interrupt\n", HOSTNO);
NCR5380_dma_complete( instance );
done = 0;
} else
#endif
{
if (basr & BASR_PHASE_MATCH)
dprintk(NDEBUG_INTR, "scsi%d: unknown interrupt, "
"BASR 0x%x, MR 0x%x, SR 0x%x\n",
HOSTNO, basr, NCR5380_read(MODE_REG),
NCR5380_read(STATUS_REG));
(void) NCR5380_read(RESET_PARITY_INTERRUPT_REG);
#ifdef SUN3_SCSI_VME
dregs->csr |= CSR_DMA_ENABLE;
#endif
}
}
handled = 1;
}
else {
printk(KERN_NOTICE "scsi%d: interrupt without IRQ bit set in BASR, "
"BASR 0x%X, MR 0x%X, SR 0x%x\n", HOSTNO, basr,
NCR5380_read(MODE_REG), NCR5380_read(STATUS_REG));
(void) NCR5380_read(RESET_PARITY_INTERRUPT_REG);
#ifdef SUN3_SCSI_VME
dregs->csr |= CSR_DMA_ENABLE;
#endif
}
if (!done) {
dprintk(NDEBUG_INTR, "scsi%d: in int routine, calling main\n", HOSTNO);
queue_main();
}
return IRQ_RETVAL(handled);
}
static void collect_stats(struct NCR5380_hostdata *hostdata,
struct scsi_cmnd *cmd)
{
# ifdef NCR5380_STAT_LIMIT
if (scsi_bufflen(cmd) > NCR5380_STAT_LIMIT)
# endif
switch (cmd->cmnd[0])
{
case WRITE:
case WRITE_6:
case WRITE_10:
hostdata->time_write[cmd->device->id] += (jiffies - hostdata->timebase);
hostdata->pendingw--;
break;
case READ:
case READ_6:
case READ_10:
hostdata->time_read[cmd->device->id] += (jiffies - hostdata->timebase);
hostdata->pendingr--;
break;
}
}
static int NCR5380_select(struct Scsi_Host *instance, struct scsi_cmnd *cmd,
int tag)
{
SETUP_HOSTDATA(instance);
unsigned char tmp[3], phase;
unsigned char *data;
int len;
unsigned long timeout;
unsigned long flags;
hostdata->restart_select = 0;
NCR5380_dprint(NDEBUG_ARBITRATION, instance);
dprintk(NDEBUG_ARBITRATION, "scsi%d: starting arbitration, id = %d\n", HOSTNO,
instance->this_id);
local_irq_save(flags);
if (hostdata->connected) {
local_irq_restore(flags);
return -1;
}
NCR5380_write(TARGET_COMMAND_REG, 0);
NCR5380_write(OUTPUT_DATA_REG, hostdata->id_mask);
NCR5380_write(MODE_REG, MR_ARBITRATE);
local_irq_restore(flags);
#ifdef NCR_TIMEOUT
{
unsigned long timeout = jiffies + 2*NCR_TIMEOUT;
while (!(NCR5380_read(INITIATOR_COMMAND_REG) & ICR_ARBITRATION_PROGRESS)
&& time_before(jiffies, timeout) && !hostdata->connected)
;
if (time_after_eq(jiffies, timeout))
{
printk("scsi : arbitration timeout at %d\n", __LINE__);
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
return -1;
}
}
#else
while (!(NCR5380_read(INITIATOR_COMMAND_REG) & ICR_ARBITRATION_PROGRESS)
&& !hostdata->connected);
#endif
dprintk(NDEBUG_ARBITRATION, "scsi%d: arbitration complete\n", HOSTNO);
if (hostdata->connected) {
NCR5380_write(MODE_REG, MR_BASE);
return -1;
}
udelay(3);
if ((NCR5380_read(INITIATOR_COMMAND_REG) & ICR_ARBITRATION_LOST) ||
(NCR5380_read(CURRENT_SCSI_DATA_REG) & hostdata->id_higher_mask) ||
(NCR5380_read(INITIATOR_COMMAND_REG) & ICR_ARBITRATION_LOST) ||
hostdata->connected) {
NCR5380_write(MODE_REG, MR_BASE);
dprintk(NDEBUG_ARBITRATION, "scsi%d: lost arbitration, deasserting MR_ARBITRATE\n",
HOSTNO);
return -1;
}
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_SEL |
ICR_ASSERT_BSY ) ;
if ((NCR5380_read(INITIATOR_COMMAND_REG) & ICR_ARBITRATION_LOST) ||
hostdata->connected) {
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
dprintk(NDEBUG_ARBITRATION, "scsi%d: lost arbitration, deasserting ICR_ASSERT_SEL\n",
HOSTNO);
return -1;
}
#ifdef CONFIG_ATARI_SCSI_TOSHIBA_DELAY
udelay(15);
#else
udelay(2);
#endif
if (hostdata->connected) {
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
return -1;
}
dprintk(NDEBUG_ARBITRATION, "scsi%d: won arbitration\n", HOSTNO);
NCR5380_write(OUTPUT_DATA_REG, (hostdata->id_mask | (1 << cmd->device->id)));
NCR5380_write(INITIATOR_COMMAND_REG, (ICR_BASE | ICR_ASSERT_BSY |
ICR_ASSERT_DATA | ICR_ASSERT_ATN | ICR_ASSERT_SEL ));
NCR5380_write(MODE_REG, MR_BASE);
if (hostdata->connected) {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
return -1;
}
NCR5380_write(SELECT_ENABLE_REG, 0);
udelay(1);
NCR5380_write(INITIATOR_COMMAND_REG, (ICR_BASE | ICR_ASSERT_DATA |
ICR_ASSERT_ATN | ICR_ASSERT_SEL));
udelay(1);
dprintk(NDEBUG_SELECTION, "scsi%d: selecting target %d\n", HOSTNO, cmd->device->id);
timeout = jiffies + 25;
#if 0
while (time_before(jiffies, timeout) && !(NCR5380_read(STATUS_REG) &
(SR_BSY | SR_IO)));
if ((NCR5380_read(STATUS_REG) & (SR_SEL | SR_IO)) ==
(SR_SEL | SR_IO)) {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_reselect(instance);
printk (KERN_ERR "scsi%d: reselection after won arbitration?\n",
HOSTNO);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
return -1;
}
#else
while (time_before(jiffies, timeout) && !(NCR5380_read(STATUS_REG) & SR_BSY));
#endif
udelay(1);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN);
if (!(NCR5380_read(STATUS_REG) & SR_BSY)) {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
if (hostdata->targets_present & (1 << cmd->device->id)) {
printk(KERN_ERR "scsi%d: weirdness\n", HOSTNO);
if (hostdata->restart_select)
printk(KERN_NOTICE "\trestart select\n");
NCR5380_dprint(NDEBUG_ANY, instance);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
return -1;
}
cmd->result = DID_BAD_TARGET << 16;
#ifdef NCR5380_STATS
collect_stats(hostdata, cmd);
#endif
#ifdef SUPPORT_TAGS
cmd_free_tag( cmd );
#endif
cmd->scsi_done(cmd);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
dprintk(NDEBUG_SELECTION, "scsi%d: target did not respond within 250ms\n", HOSTNO);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
return 0;
}
hostdata->targets_present |= (1 << cmd->device->id);
while (!(NCR5380_read(STATUS_REG) & SR_REQ));
dprintk(NDEBUG_SELECTION, "scsi%d: target %d selected, going into MESSAGE OUT phase.\n",
HOSTNO, cmd->device->id);
tmp[0] = IDENTIFY(1, cmd->device->lun);
#ifdef SUPPORT_TAGS
if (cmd->tag != TAG_NONE) {
tmp[1] = hostdata->last_message = SIMPLE_QUEUE_TAG;
tmp[2] = cmd->tag;
len = 3;
} else
len = 1;
#else
len = 1;
cmd->tag=0;
#endif
data = tmp;
phase = PHASE_MSGOUT;
NCR5380_transfer_pio(instance, &phase, &len, &data);
dprintk(NDEBUG_SELECTION, "scsi%d: nexus established.\n", HOSTNO);
hostdata->connected = cmd;
#ifndef SUPPORT_TAGS
hostdata->busy[cmd->device->id] |= (1 << cmd->device->lun);
#endif
#ifdef SUN3_SCSI_VME
dregs->csr |= CSR_INTR;
#endif
initialize_SCp(cmd);
return 0;
}
static int NCR5380_transfer_pio( struct Scsi_Host *instance,
unsigned char *phase, int *count,
unsigned char **data)
{
register unsigned char p = *phase, tmp;
register int c = *count;
register unsigned char *d = *data;
NCR5380_write(TARGET_COMMAND_REG, PHASE_SR_TO_TCR(p));
do {
while (!((tmp = NCR5380_read(STATUS_REG)) & SR_REQ));
dprintk(NDEBUG_HANDSHAKE, "scsi%d: REQ detected\n", HOSTNO);
if ((tmp & PHASE_MASK) != p) {
dprintk(NDEBUG_PIO, "scsi%d: phase mismatch\n", HOSTNO);
NCR5380_dprint_phase(NDEBUG_PIO, instance);
break;
}
if (!(p & SR_IO))
NCR5380_write(OUTPUT_DATA_REG, *d);
else
*d = NCR5380_read(CURRENT_SCSI_DATA_REG);
++d;
if (!(p & SR_IO)) {
if (!((p & SR_MSG) && c > 1)) {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE |
ICR_ASSERT_DATA);
NCR5380_dprint(NDEBUG_PIO, instance);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE |
ICR_ASSERT_DATA | ICR_ASSERT_ACK);
} else {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE |
ICR_ASSERT_DATA | ICR_ASSERT_ATN);
NCR5380_dprint(NDEBUG_PIO, instance);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE |
ICR_ASSERT_DATA | ICR_ASSERT_ATN | ICR_ASSERT_ACK);
}
} else {
NCR5380_dprint(NDEBUG_PIO, instance);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ACK);
}
while (NCR5380_read(STATUS_REG) & SR_REQ);
dprintk(NDEBUG_HANDSHAKE, "scsi%d: req false, handshake complete\n", HOSTNO);
if (!(p == PHASE_MSGIN && c == 1)) {
if (p == PHASE_MSGOUT && c > 1)
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN);
else
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
}
} while (--c);
dprintk(NDEBUG_PIO, "scsi%d: residual %d\n", HOSTNO, c);
*count = c;
*data = d;
tmp = NCR5380_read(STATUS_REG);
if ((tmp & SR_REQ) || (p == PHASE_MSGIN && c == 0))
*phase = tmp & PHASE_MASK;
else
*phase = PHASE_UNKNOWN;
if (!c || (*phase == p))
return 0;
else
return -1;
}
static int do_abort (struct Scsi_Host *host)
{
unsigned char tmp, *msgptr, phase;
int len;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN);
while (!((tmp = NCR5380_read(STATUS_REG)) & SR_REQ));
NCR5380_write(TARGET_COMMAND_REG, PHASE_SR_TO_TCR(tmp));
if ((tmp & PHASE_MASK) != PHASE_MSGOUT) {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN |
ICR_ASSERT_ACK);
while (NCR5380_read(STATUS_REG) & SR_REQ);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN);
}
tmp = ABORT;
msgptr = &tmp;
len = 1;
phase = PHASE_MSGOUT;
NCR5380_transfer_pio (host, &phase, &len, &msgptr);
return len ? -1 : 0;
}
static int NCR5380_transfer_dma( struct Scsi_Host *instance,
unsigned char *phase, int *count,
unsigned char **data)
{
SETUP_HOSTDATA(instance);
register int c = *count;
register unsigned char p = *phase;
unsigned long flags;
if(!sun3_dma_setup_done) {
printk("scsi%d: transfer_dma without setup!\n", HOSTNO);
BUG();
}
hostdata->dma_len = c;
dprintk(NDEBUG_DMA, "scsi%d: initializing DMA for %s, %d bytes %s %p\n",
HOSTNO, (p & SR_IO) ? "reading" : "writing",
c, (p & SR_IO) ? "to" : "from", *data);
local_irq_save(flags);
sun3scsi_dma_start(c, *data);
if (p & SR_IO) {
NCR5380_write(TARGET_COMMAND_REG, 1);
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
NCR5380_write(INITIATOR_COMMAND_REG, 0);
NCR5380_write(MODE_REG, (NCR5380_read(MODE_REG) | MR_DMA_MODE | MR_ENABLE_EOP_INTR));
NCR5380_write(START_DMA_INITIATOR_RECEIVE_REG, 0);
} else {
NCR5380_write(TARGET_COMMAND_REG, 0);
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_ASSERT_DATA);
NCR5380_write(MODE_REG, (NCR5380_read(MODE_REG) | MR_DMA_MODE | MR_ENABLE_EOP_INTR));
NCR5380_write(START_DMA_SEND_REG, 0);
}
#ifdef SUN3_SCSI_VME
dregs->csr |= CSR_DMA_ENABLE;
#endif
local_irq_restore(flags);
sun3_dma_active = 1;
return 0;
}
static void NCR5380_information_transfer (struct Scsi_Host *instance)
{
SETUP_HOSTDATA(instance);
unsigned long flags;
unsigned char msgout = NOP;
int sink = 0;
int len;
#if defined(REAL_DMA)
int transfersize;
#endif
unsigned char *data;
unsigned char phase, tmp, extended_msg[10], old_phase=0xff;
struct scsi_cmnd *cmd = (struct scsi_cmnd *) hostdata->connected;
#ifdef SUN3_SCSI_VME
dregs->csr |= CSR_INTR;
#endif
while (1) {
tmp = NCR5380_read(STATUS_REG);
if (tmp & SR_REQ) {
phase = (tmp & PHASE_MASK);
if (phase != old_phase) {
old_phase = phase;
NCR5380_dprint_phase(NDEBUG_INFORMATION, instance);
}
if(phase == PHASE_CMDOUT) {
void *d;
unsigned long count;
if (!cmd->SCp.this_residual && cmd->SCp.buffers_residual) {
count = cmd->SCp.buffer->length;
d = SGADDR(cmd->SCp.buffer);
} else {
count = cmd->SCp.this_residual;
d = cmd->SCp.ptr;
}
#ifdef REAL_DMA
if((count > SUN3_DMA_MINSIZE) && (sun3_dma_setup_done
!= cmd))
{
if (cmd->request->cmd_type == REQ_TYPE_FS) {
sun3scsi_dma_setup(d, count,
rq_data_dir(cmd->request));
sun3_dma_setup_done = cmd;
}
}
#endif
#ifdef SUN3_SCSI_VME
dregs->csr |= CSR_INTR;
#endif
}
if (sink && (phase != PHASE_MSGOUT)) {
NCR5380_write(TARGET_COMMAND_REG, PHASE_SR_TO_TCR(tmp));
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN |
ICR_ASSERT_ACK);
while (NCR5380_read(STATUS_REG) & SR_REQ);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE |
ICR_ASSERT_ATN);
sink = 0;
continue;
}
switch (phase) {
case PHASE_DATAOUT:
#if (NDEBUG & NDEBUG_NO_DATAOUT)
printk("scsi%d: NDEBUG_NO_DATAOUT set, attempted DATAOUT "
"aborted\n", HOSTNO);
sink = 1;
do_abort(instance);
cmd->result = DID_ERROR << 16;
cmd->scsi_done(cmd);
return;
#endif
case PHASE_DATAIN:
if (!cmd->SCp.this_residual && cmd->SCp.buffers_residual) {
++cmd->SCp.buffer;
--cmd->SCp.buffers_residual;
cmd->SCp.this_residual = cmd->SCp.buffer->length;
cmd->SCp.ptr = SGADDR(cmd->SCp.buffer);
dprintk(NDEBUG_INFORMATION, "scsi%d: %d bytes and %d buffers left\n",
HOSTNO, cmd->SCp.this_residual,
cmd->SCp.buffers_residual);
}
#if defined(REAL_DMA)
if((transfersize =
NCR5380_dma_xfer_len(instance,cmd,phase)) > SUN3_DMA_MINSIZE) {
len = transfersize;
cmd->SCp.phase = phase;
if (NCR5380_transfer_dma(instance, &phase,
&len, (unsigned char **) &cmd->SCp.ptr)) {
printk(KERN_NOTICE "scsi%d: switching target %d "
"lun %llu to slow handshake\n", HOSTNO,
cmd->device->id, cmd->device->lun);
cmd->device->borken = 1;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE |
ICR_ASSERT_ATN);
sink = 1;
do_abort(instance);
cmd->result = DID_ERROR << 16;
cmd->scsi_done(cmd);
} else {
#ifdef REAL_DMA
return;
#else
cmd->SCp.this_residual -= transfersize - len;
#endif
}
} else
#endif
NCR5380_transfer_pio(instance, &phase,
(int *) &cmd->SCp.this_residual, (unsigned char **)
&cmd->SCp.ptr);
#ifdef REAL_DMA
if(sun3_dma_setup_done == cmd)
sun3_dma_setup_done = NULL;
#endif
break;
case PHASE_MSGIN:
len = 1;
data = &tmp;
NCR5380_write(SELECT_ENABLE_REG, 0);
NCR5380_transfer_pio(instance, &phase, &len, &data);
cmd->SCp.Message = tmp;
switch (tmp) {
#ifdef LINKED
case LINKED_CMD_COMPLETE:
case LINKED_FLG_CMD_COMPLETE:
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
dprintk(NDEBUG_LINKED, "scsi%d: target %d lun %llu linked command "
"complete.\n", HOSTNO, cmd->device->id, cmd->device->lun);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
if (!cmd->next_link) {
printk(KERN_NOTICE "scsi%d: target %d lun %llu "
"linked command complete, no next_link\n",
HOSTNO, cmd->device->id, cmd->device->lun);
sink = 1;
do_abort (instance);
return;
}
initialize_SCp(cmd->next_link);
cmd->next_link->tag = cmd->tag;
cmd->result = cmd->SCp.Status | (cmd->SCp.Message << 8);
dprintk(NDEBUG_LINKED, "scsi%d: target %d lun %llu linked request "
"done, calling scsi_done().\n",
HOSTNO, cmd->device->id, cmd->device->lun);
#ifdef NCR5380_STATS
collect_stats(hostdata, cmd);
#endif
cmd->scsi_done(cmd);
cmd = hostdata->connected;
break;
#endif
case ABORT:
case COMMAND_COMPLETE:
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
hostdata->connected = NULL;
dprintk(NDEBUG_QUEUES, "scsi%d: command for target %d, lun %llu "
"completed\n", HOSTNO, cmd->device->id, cmd->device->lun);
#ifdef SUPPORT_TAGS
cmd_free_tag( cmd );
if (status_byte(cmd->SCp.Status) == QUEUE_FULL) {
TAG_ALLOC *ta = &TagAlloc[cmd->device->id][cmd->device->lun];
dprintk(NDEBUG_TAGS, "scsi%d: target %d lun %llu returned "
"QUEUE_FULL after %d commands\n",
HOSTNO, cmd->device->id, cmd->device->lun,
ta->nr_allocated);
if (ta->queue_size > ta->nr_allocated)
ta->nr_allocated = ta->queue_size;
}
#else
hostdata->busy[cmd->device->id] &= ~(1 << cmd->device->lun);
#endif
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
if (cmd->cmnd[0] != REQUEST_SENSE)
cmd->result = cmd->SCp.Status | (cmd->SCp.Message << 8);
else if (status_byte(cmd->SCp.Status) != GOOD)
cmd->result = (cmd->result & 0x00ffff) | (DID_ERROR << 16);
#ifdef AUTOSENSE
if ((cmd->cmnd[0] == REQUEST_SENSE) &&
hostdata->ses.cmd_len) {
scsi_eh_restore_cmnd(cmd, &hostdata->ses);
hostdata->ses.cmd_len = 0 ;
}
if ((cmd->cmnd[0] != REQUEST_SENSE) &&
(status_byte(cmd->SCp.Status) == CHECK_CONDITION)) {
scsi_eh_prep_cmnd(cmd, &hostdata->ses, NULL, 0, ~0);
dprintk(NDEBUG_AUTOSENSE, "scsi%d: performing request sense\n",
HOSTNO);
local_irq_save(flags);
LIST(cmd,hostdata->issue_queue);
SET_NEXT(cmd, hostdata->issue_queue);
hostdata->issue_queue = (struct scsi_cmnd *) cmd;
local_irq_restore(flags);
dprintk(NDEBUG_QUEUES, "scsi%d: REQUEST SENSE added to head of "
"issue queue\n", H_NO(cmd));
} else
#endif
{
#ifdef NCR5380_STATS
collect_stats(hostdata, cmd);
#endif
cmd->scsi_done(cmd);
}
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
NCR5380_write(TARGET_COMMAND_REG, 0);
while ((NCR5380_read(STATUS_REG) & SR_BSY) && !hostdata->connected)
barrier();
return;
case MESSAGE_REJECT:
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
switch (hostdata->last_message) {
case HEAD_OF_QUEUE_TAG:
case ORDERED_QUEUE_TAG:
case SIMPLE_QUEUE_TAG:
cmd->device->tagged_supported = 0;
hostdata->busy[cmd->device->id] |= (1 << cmd->device->lun);
cmd->tag = TAG_NONE;
dprintk(NDEBUG_TAGS, "scsi%d: target %d lun %llu rejected "
"QUEUE_TAG message; tagged queuing "
"disabled\n",
HOSTNO, cmd->device->id, cmd->device->lun);
break;
}
break;
case DISCONNECT:
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
local_irq_save(flags);
cmd->device->disconnect = 1;
LIST(cmd,hostdata->disconnected_queue);
SET_NEXT(cmd, hostdata->disconnected_queue);
hostdata->connected = NULL;
hostdata->disconnected_queue = cmd;
local_irq_restore(flags);
dprintk(NDEBUG_QUEUES, "scsi%d: command for target %d lun %llu was "
"moved from connected to the "
"disconnected_queue\n", HOSTNO,
cmd->device->id, cmd->device->lun);
NCR5380_write(TARGET_COMMAND_REG, 0);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
while ((NCR5380_read(STATUS_REG) & SR_BSY) && !hostdata->connected)
barrier();
#ifdef SUN3_SCSI_VME
dregs->csr |= CSR_DMA_ENABLE;
#endif
return;
case SAVE_POINTERS:
case RESTORE_POINTERS:
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
break;
case EXTENDED_MESSAGE:
extended_msg[0] = EXTENDED_MESSAGE;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
dprintk(NDEBUG_EXTENDED, "scsi%d: receiving extended message\n", HOSTNO);
len = 2;
data = extended_msg + 1;
phase = PHASE_MSGIN;
NCR5380_transfer_pio(instance, &phase, &len, &data);
dprintk(NDEBUG_EXTENDED, "scsi%d: length=%d, code=0x%02x\n", HOSTNO,
(int)extended_msg[1], (int)extended_msg[2]);
if (!len && extended_msg[1] <=
(sizeof (extended_msg) - 1)) {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
len = extended_msg[1] - 1;
data = extended_msg + 3;
phase = PHASE_MSGIN;
NCR5380_transfer_pio(instance, &phase, &len, &data);
dprintk(NDEBUG_EXTENDED, "scsi%d: message received, residual %d\n",
HOSTNO, len);
switch (extended_msg[2]) {
case EXTENDED_SDTR:
case EXTENDED_WDTR:
case EXTENDED_MODIFY_DATA_POINTER:
case EXTENDED_EXTENDED_IDENTIFY:
tmp = 0;
}
} else if (len) {
printk(KERN_NOTICE "scsi%d: error receiving "
"extended message\n", HOSTNO);
tmp = 0;
} else {
printk(KERN_NOTICE "scsi%d: extended message "
"code %02x length %d is too long\n",
HOSTNO, extended_msg[2], extended_msg[1]);
tmp = 0;
}
default:
if (!tmp) {
printk(KERN_DEBUG "scsi%d: rejecting message ", HOSTNO);
spi_print_msg(extended_msg);
printk("\n");
} else if (tmp != EXTENDED_MESSAGE)
printk(KERN_DEBUG "scsi%d: rejecting unknown "
"message %02x from target %d, lun %llu\n",
HOSTNO, tmp, cmd->device->id, cmd->device->lun);
else
printk(KERN_DEBUG "scsi%d: rejecting unknown "
"extended message "
"code %02x, length %d from target %d, lun %llu\n",
HOSTNO, extended_msg[1], extended_msg[0],
cmd->device->id, cmd->device->lun);
msgout = MESSAGE_REJECT;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE |
ICR_ASSERT_ATN);
break;
}
break;
case PHASE_MSGOUT:
len = 1;
data = &msgout;
hostdata->last_message = msgout;
NCR5380_transfer_pio(instance, &phase, &len, &data);
if (msgout == ABORT) {
#ifdef SUPPORT_TAGS
cmd_free_tag( cmd );
#else
hostdata->busy[cmd->device->id] &= ~(1 << cmd->device->lun);
#endif
hostdata->connected = NULL;
cmd->result = DID_ERROR << 16;
#ifdef NCR5380_STATS
collect_stats(hostdata, cmd);
#endif
cmd->scsi_done(cmd);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
return;
}
msgout = NOP;
break;
case PHASE_CMDOUT:
len = cmd->cmd_len;
data = cmd->cmnd;
NCR5380_transfer_pio(instance, &phase, &len,
&data);
break;
case PHASE_STATIN:
len = 1;
data = &tmp;
NCR5380_transfer_pio(instance, &phase, &len, &data);
cmd->SCp.Status = tmp;
break;
default:
printk("scsi%d: unknown phase\n", HOSTNO);
NCR5380_dprint(NDEBUG_ANY, instance);
}
}
}
}
static void NCR5380_reselect (struct Scsi_Host *instance)
{
SETUP_HOSTDATA(instance);
unsigned char target_mask;
unsigned char lun;
#ifdef SUPPORT_TAGS
unsigned char tag;
#endif
unsigned char msg[3];
struct scsi_cmnd *tmp = NULL, *prev;
NCR5380_write(MODE_REG, MR_BASE);
hostdata->restart_select = 1;
target_mask = NCR5380_read(CURRENT_SCSI_DATA_REG) & ~(hostdata->id_mask);
dprintk(NDEBUG_RESELECTION, "scsi%d: reselect\n", HOSTNO);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_BSY);
while (NCR5380_read(STATUS_REG) & SR_SEL);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
while (!(NCR5380_read(STATUS_REG) & SR_REQ));
#if 1
NCR5380_write(TARGET_COMMAND_REG, PHASE_SR_TO_TCR(PHASE_MSGIN));
msg[0] = NCR5380_read(CURRENT_SCSI_DATA_REG);
#endif
if (!(msg[0] & 0x80)) {
printk(KERN_DEBUG "scsi%d: expecting IDENTIFY message, got ", HOSTNO);
spi_print_msg(msg);
do_abort(instance);
return;
}
lun = (msg[0] & 0x07);
for (tmp = (struct scsi_cmnd *) hostdata->disconnected_queue, prev = NULL;
tmp; prev = tmp, tmp = NEXT(tmp) ) {
if ((target_mask == (1 << tmp->device->id)) && (lun == tmp->device->lun)
#ifdef SUPPORT_TAGS
&& (tag == tmp->tag)
#endif
) {
if (prev) {
REMOVE(prev, NEXT(prev), tmp, NEXT(tmp));
SET_NEXT(prev, NEXT(tmp));
} else {
REMOVE(-1, hostdata->disconnected_queue, tmp, NEXT(tmp));
hostdata->disconnected_queue = NEXT(tmp);
}
SET_NEXT(tmp, NULL);
break;
}
}
if (!tmp) {
printk(KERN_WARNING "scsi%d: warning: target bitmask %02x lun %d "
#ifdef SUPPORT_TAGS
"tag %d "
#endif
"not in disconnected_queue.\n",
HOSTNO, target_mask, lun
#ifdef SUPPORT_TAGS
, tag
#endif
);
do_abort(instance);
return;
}
#if 1
{
void *d;
unsigned long count;
if (!tmp->SCp.this_residual && tmp->SCp.buffers_residual) {
count = tmp->SCp.buffer->length;
d = SGADDR(tmp->SCp.buffer);
} else {
count = tmp->SCp.this_residual;
d = tmp->SCp.ptr;
}
#ifdef REAL_DMA
if((count > SUN3_DMA_MINSIZE) && (sun3_dma_setup_done != tmp))
{
sun3scsi_dma_setup(d, count, rq_data_dir(tmp->request));
sun3_dma_setup_done = tmp;
}
#endif
}
#endif
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ACK);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
#ifdef SUPPORT_TAGS
tag = TAG_NONE;
if (phase == PHASE_MSGIN && setup_use_tagged_queuing) {
NCR5380_write( INITIATOR_COMMAND_REG, ICR_BASE );
len = 2;
data = msg+1;
if (!NCR5380_transfer_pio(instance, &phase, &len, &data) &&
msg[1] == SIMPLE_QUEUE_TAG)
tag = msg[2];
dprintk(NDEBUG_TAGS, "scsi%d: target mask %02x, lun %d sent tag %d at "
"reselection\n", HOSTNO, target_mask, lun, tag);
}
#endif
hostdata->connected = tmp;
dprintk(NDEBUG_RESELECTION, "scsi%d: nexus established, target = %d, lun = %llu, tag = %d\n",
HOSTNO, tmp->device->id, tmp->device->lun, tmp->tag);
}
static int NCR5380_abort(struct scsi_cmnd *cmd)
{
struct Scsi_Host *instance = cmd->device->host;
SETUP_HOSTDATA(instance);
struct scsi_cmnd *tmp, **prev;
unsigned long flags;
printk(KERN_NOTICE "scsi%d: aborting command\n", HOSTNO);
scsi_print_command(cmd);
NCR5380_print_status (instance);
local_irq_save(flags);
dprintk(NDEBUG_ABORT, "scsi%d: abort called basr 0x%02x, sr 0x%02x\n", HOSTNO,
NCR5380_read(BUS_AND_STATUS_REG),
NCR5380_read(STATUS_REG));
#if 1
if (hostdata->connected == cmd) {
dprintk(NDEBUG_ABORT, "scsi%d: aborting connected command\n", HOSTNO);
if (do_abort(instance) == 0) {
hostdata->aborted = 1;
hostdata->connected = NULL;
cmd->result = DID_ABORT << 16;
#ifdef SUPPORT_TAGS
cmd_free_tag( cmd );
#else
hostdata->busy[cmd->device->id] &= ~(1 << cmd->device->lun);
#endif
local_irq_restore(flags);
cmd->scsi_done(cmd);
return SUCCESS;
} else {
printk("scsi%d: abort of connected command failed!\n", HOSTNO);
return FAILED;
}
}
#endif
for (prev = (struct scsi_cmnd **) &(hostdata->issue_queue),
tmp = (struct scsi_cmnd *) hostdata->issue_queue;
tmp; prev = NEXTADDR(tmp), tmp = NEXT(tmp))
if (cmd == tmp) {
REMOVE(5, *prev, tmp, NEXT(tmp));
(*prev) = NEXT(tmp);
SET_NEXT(tmp, NULL);
tmp->result = DID_ABORT << 16;
local_irq_restore(flags);
dprintk(NDEBUG_ABORT, "scsi%d: abort removed command from issue queue.\n",
HOSTNO);
tmp->scsi_done(tmp);
return SUCCESS;
}
if (hostdata->connected) {
local_irq_restore(flags);
dprintk(NDEBUG_ABORT, "scsi%d: abort failed, command connected.\n", HOSTNO);
return FAILED;
}
for (tmp = (struct scsi_cmnd *) hostdata->disconnected_queue; tmp;
tmp = NEXT(tmp))
if (cmd == tmp) {
local_irq_restore(flags);
dprintk(NDEBUG_ABORT, "scsi%d: aborting disconnected command.\n", HOSTNO);
if (NCR5380_select (instance, cmd, (int) cmd->tag))
return FAILED;
dprintk(NDEBUG_ABORT, "scsi%d: nexus reestablished.\n", HOSTNO);
do_abort (instance);
local_irq_save(flags);
for (prev = (struct scsi_cmnd **) &(hostdata->disconnected_queue),
tmp = (struct scsi_cmnd *) hostdata->disconnected_queue;
tmp; prev = NEXTADDR(tmp), tmp = NEXT(tmp) )
if (cmd == tmp) {
REMOVE(5, *prev, tmp, NEXT(tmp));
*prev = NEXT(tmp);
SET_NEXT(tmp, NULL);
tmp->result = DID_ABORT << 16;
#ifdef SUPPORT_TAGS
cmd_free_tag( tmp );
#else
hostdata->busy[cmd->device->id] &= ~(1 << cmd->device->lun);
#endif
local_irq_restore(flags);
tmp->scsi_done(tmp);
return SUCCESS;
}
}
local_irq_restore(flags);
printk(KERN_INFO "scsi%d: warning : SCSI command probably completed successfully before abortion\n", HOSTNO);
return FAILED;
}
static int NCR5380_bus_reset(struct scsi_cmnd *cmd)
{
SETUP_HOSTDATA(cmd->device->host);
int i;
unsigned long flags;
#if defined(RESET_RUN_DONE)
struct scsi_cmnd *connected, *disconnected_queue;
#endif
NCR5380_print_status (cmd->device->host);
NCR5380_write( TARGET_COMMAND_REG,
PHASE_SR_TO_TCR( NCR5380_read(STATUS_REG) ));
NCR5380_write( INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_RST );
udelay (40);
NCR5380_write( INITIATOR_COMMAND_REG, ICR_BASE );
NCR5380_write( MODE_REG, MR_BASE );
NCR5380_write( TARGET_COMMAND_REG, 0 );
NCR5380_write( SELECT_ENABLE_REG, 0 );
(void)NCR5380_read( RESET_PARITY_INTERRUPT_REG );
#if defined(RESET_RUN_DONE)
local_irq_save(flags);
connected = (struct scsi_cmnd *)hostdata->connected;
hostdata->connected = NULL;
disconnected_queue = (struct scsi_cmnd *)hostdata->disconnected_queue;
hostdata->disconnected_queue = NULL;
#ifdef SUPPORT_TAGS
free_all_tags();
#endif
for( i = 0; i < 8; ++i )
hostdata->busy[i] = 0;
#ifdef REAL_DMA
hostdata->dma_len = 0;
#endif
local_irq_restore(flags);
if ((cmd = connected)) {
dprintk(NDEBUG_ABORT, "scsi%d: reset aborted a connected command\n", H_NO(cmd));
cmd->result = (cmd->result & 0xffff) | (DID_RESET << 16);
cmd->scsi_done( cmd );
}
for (i = 0; (cmd = disconnected_queue); ++i) {
disconnected_queue = NEXT(cmd);
SET_NEXT(cmd, NULL);
cmd->result = (cmd->result & 0xffff) | (DID_RESET << 16);
cmd->scsi_done( cmd );
}
if (i > 0)
dprintk(NDEBUG_ABORT, "scsi: reset aborted %d disconnected command(s)\n", i);
return SUCCESS;
#else
if (hostdata->issue_queue)
dprintk(NDEBUG_ABORT, "scsi%d: reset aborted issued command(s)\n", H_NO(cmd));
if (hostdata->connected)
dprintk(NDEBUG_ABORT, "scsi%d: reset aborted a connected command\n", H_NO(cmd));
if (hostdata->disconnected_queue)
dprintk(NDEBUG_ABORT, "scsi%d: reset aborted disconnected command(s)\n", H_NO(cmd));
local_irq_save(flags);
hostdata->issue_queue = NULL;
hostdata->connected = NULL;
hostdata->disconnected_queue = NULL;
#ifdef SUPPORT_TAGS
free_all_tags();
#endif
for( i = 0; i < 8; ++i )
hostdata->busy[i] = 0;
#ifdef REAL_DMA
hostdata->dma_len = 0;
#endif
local_irq_restore(flags);
return SUCCESS;
#endif
}
