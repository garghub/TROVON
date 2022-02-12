static inline void initialize_SCp(struct scsi_cmnd *cmd)
{
if (scsi_bufflen(cmd)) {
cmd->SCp.buffer = scsi_sglist(cmd);
cmd->SCp.buffers_residual = scsi_sg_count(cmd) - 1;
cmd->SCp.ptr = sg_virt(cmd->SCp.buffer);
cmd->SCp.this_residual = cmd->SCp.buffer->length;
} else {
cmd->SCp.buffer = NULL;
cmd->SCp.buffers_residual = 0;
cmd->SCp.ptr = NULL;
cmd->SCp.this_residual = 0;
}
}
static int NCR5380_poll_politely(struct Scsi_Host *instance, int reg, int bit, int val, int t)
{
NCR5380_local_declare();
int n = 500;
unsigned long end = jiffies + t;
int r;
NCR5380_setup(instance);
while( n-- > 0)
{
r = NCR5380_read(reg);
if((r & bit) == val)
return 0;
cpu_relax();
}
while(time_before(jiffies, end))
{
r = NCR5380_read(reg);
if((r & bit) == val)
return 0;
if(!in_interrupt())
cond_resched();
else
cpu_relax();
}
return -ETIMEDOUT;
}
static void NCR5380_print(struct Scsi_Host *instance)
{
NCR5380_local_declare();
unsigned char status, data, basr, mr, icr, i;
NCR5380_setup(instance);
data = NCR5380_read(CURRENT_SCSI_DATA_REG);
status = NCR5380_read(STATUS_REG);
mr = NCR5380_read(MODE_REG);
icr = NCR5380_read(INITIATOR_COMMAND_REG);
basr = NCR5380_read(BUS_AND_STATUS_REG);
printk("STATUS_REG: %02x ", status);
for (i = 0; signals[i].mask; ++i)
if (status & signals[i].mask)
printk(",%s", signals[i].name);
printk("\nBASR: %02x ", basr);
for (i = 0; basrs[i].mask; ++i)
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
NCR5380_local_declare();
unsigned char status;
int i;
NCR5380_setup(instance);
status = NCR5380_read(STATUS_REG);
if (!(status & SR_REQ))
printk("scsi%d : REQ not asserted, phase unknown.\n", instance->host_no);
else {
for (i = 0; (phases[i].value != PHASE_UNKNOWN) && (phases[i].value != (status & PHASE_MASK)); ++i);
printk("scsi%d : phase %s\n", instance->host_no, phases[i].name);
}
}
static int should_disconnect(unsigned char cmd)
{
switch (cmd) {
case READ_6:
case WRITE_6:
case SEEK_6:
case READ_10:
case WRITE_10:
case SEEK_10:
return DISCONNECT_TIME_TO_DATA;
case FORMAT_UNIT:
case SEARCH_HIGH:
case SEARCH_LOW:
case SEARCH_EQUAL:
return DISCONNECT_LONG;
default:
return DISCONNECT_NONE;
}
}
static void NCR5380_set_timer(struct NCR5380_hostdata *hostdata, unsigned long timeout)
{
hostdata->time_expires = jiffies + timeout;
schedule_delayed_work(&hostdata->coroutine, timeout);
}
static irqreturn_t __init probe_intr(int irq, void *dev_id)
{
probe_irq = irq;
return IRQ_HANDLED;
}
static int __init __maybe_unused NCR5380_probe_irq(struct Scsi_Host *instance,
int possible)
{
NCR5380_local_declare();
struct NCR5380_hostdata *hostdata = (struct NCR5380_hostdata *) instance->hostdata;
unsigned long timeout;
int trying_irqs, i, mask;
NCR5380_setup(instance);
for (trying_irqs = 0, i = 1, mask = 2; i < 16; ++i, mask <<= 1)
if ((mask & possible) && (request_irq(i, &probe_intr, 0, "NCR-probe", NULL) == 0))
trying_irqs |= mask;
timeout = jiffies + (250 * HZ / 1000);
probe_irq = NO_IRQ;
NCR5380_write(TARGET_COMMAND_REG, 0);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
NCR5380_write(OUTPUT_DATA_REG, hostdata->id_mask);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_DATA | ICR_ASSERT_SEL);
while (probe_irq == NO_IRQ && time_before(jiffies, timeout))
schedule_timeout_uninterruptible(1);
NCR5380_write(SELECT_ENABLE_REG, 0);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
for (i = 1, mask = 2; i < 16; ++i, mask <<= 1)
if (trying_irqs & mask)
free_irq(i, NULL);
return probe_irq;
}
static const char *NCR5380_info(struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
return hostdata->info;
}
static void prepare_info(struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
snprintf(hostdata->info, sizeof(hostdata->info),
"%s, io_port 0x%lx, n_io_port %d, "
"base 0x%lx, irq %d, "
"can_queue %d, cmd_per_lun %d, "
"sg_tablesize %d, this_id %d, "
"flags { %s%s%s}, "
#if defined(USLEEP_POLL) && defined(USLEEP_WAITLONG)
"USLEEP_POLL %d, USLEEP_WAITLONG %d, "
#endif
"options { %s} ",
instance->hostt->name, instance->io_port, instance->n_io_port,
instance->base, instance->irq,
instance->can_queue, instance->cmd_per_lun,
instance->sg_tablesize, instance->this_id,
hostdata->flags & FLAG_NCR53C400 ? "NCR53C400 " : "",
hostdata->flags & FLAG_DTC3181E ? "DTC3181E " : "",
hostdata->flags & FLAG_NO_PSEUDO_DMA ? "NO_PSEUDO_DMA " : "",
#if defined(USLEEP_POLL) && defined(USLEEP_WAITLONG)
USLEEP_POLL, USLEEP_WAITLONG,
#endif
#ifdef AUTOPROBE_IRQ
"AUTOPROBE_IRQ "
#endif
#ifdef DIFFERENTIAL
"DIFFERENTIAL "
#endif
#ifdef REAL_DMA
"REAL_DMA "
#endif
#ifdef REAL_DMA_POLL
"REAL_DMA_POLL "
#endif
#ifdef PARITY
"PARITY "
#endif
#ifdef PSEUDO_DMA
"PSEUDO_DMA "
#endif
#ifdef UNSAFE
"UNSAFE "
#endif
#ifdef NCR53C400
"NCR53C400 "
#endif
"");
}
static void NCR5380_print_status(struct Scsi_Host *instance)
{
NCR5380_dprint(NDEBUG_ANY, instance);
NCR5380_dprint_phase(NDEBUG_ANY, instance);
}
static int __maybe_unused NCR5380_write_info(struct Scsi_Host *instance,
char *buffer, int length)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
hostdata->spin_max_r = 0;
hostdata->spin_max_w = 0;
return 0;
}
static int __maybe_unused NCR5380_show_info(struct seq_file *m,
struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata;
struct scsi_cmnd *ptr;
hostdata = (struct NCR5380_hostdata *) instance->hostdata;
#ifdef PSEUDO_DMA
SPRINTF("Highwater I/O busy spin counts: write %d, read %d\n",
hostdata->spin_max_w, hostdata->spin_max_r);
#endif
spin_lock_irq(instance->host_lock);
if (!hostdata->connected)
SPRINTF("scsi%d: no currently connected command\n", instance->host_no);
else
lprint_Scsi_Cmnd((struct scsi_cmnd *) hostdata->connected, m);
SPRINTF("scsi%d: issue_queue\n", instance->host_no);
for (ptr = (struct scsi_cmnd *) hostdata->issue_queue; ptr; ptr = (struct scsi_cmnd *) ptr->host_scribble)
lprint_Scsi_Cmnd(ptr, m);
SPRINTF("scsi%d: disconnected_queue\n", instance->host_no);
for (ptr = (struct scsi_cmnd *) hostdata->disconnected_queue; ptr; ptr = (struct scsi_cmnd *) ptr->host_scribble)
lprint_Scsi_Cmnd(ptr, m);
spin_unlock_irq(instance->host_lock);
return 0;
}
static void lprint_Scsi_Cmnd(struct scsi_cmnd *cmd, struct seq_file *m)
{
SPRINTF("scsi%d : destination target %d, lun %llu\n", cmd->device->host->host_no, cmd->device->id, cmd->device->lun);
SPRINTF(" command = ");
lprint_command(cmd->cmnd, m);
}
static void lprint_command(unsigned char *command, struct seq_file *m)
{
int i, s;
lprint_opcode(command[0], m);
for (i = 1, s = COMMAND_SIZE(command[0]); i < s; ++i)
SPRINTF("%02x ", command[i]);
SPRINTF("\n");
}
static void lprint_opcode(int opcode, struct seq_file *m)
{
SPRINTF("%2d (0x%02x)", opcode, opcode);
}
static int NCR5380_init(struct Scsi_Host *instance, int flags)
{
NCR5380_local_declare();
int i, pass;
unsigned long timeout;
struct NCR5380_hostdata *hostdata = (struct NCR5380_hostdata *) instance->hostdata;
if(in_interrupt())
printk(KERN_ERR "NCR5380_init called with interrupts off!\n");
#ifdef NCR53C400
if (flags & FLAG_NCR53C400)
instance->NCR5380_instance_name += NCR53C400_address_adjust;
#endif
NCR5380_setup(instance);
hostdata->aborted = 0;
hostdata->id_mask = 1 << instance->this_id;
for (i = hostdata->id_mask; i <= 0x80; i <<= 1)
if (i > hostdata->id_mask)
hostdata->id_higher_mask |= i;
for (i = 0; i < 8; ++i)
hostdata->busy[i] = 0;
#ifdef REAL_DMA
hostdata->dmalen = 0;
#endif
hostdata->targets_present = 0;
hostdata->connected = NULL;
hostdata->issue_queue = NULL;
hostdata->disconnected_queue = NULL;
INIT_DELAYED_WORK(&hostdata->coroutine, NCR5380_main);
if (flags & FLAG_NCR53C400)
hostdata->flags = FLAG_HAS_LAST_BYTE_SENT | flags;
else
hostdata->flags = FLAG_CHECK_LAST_BYTE_SENT | flags;
hostdata->host = instance;
hostdata->time_expires = 0;
prepare_info(instance);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(TARGET_COMMAND_REG, 0);
NCR5380_write(SELECT_ENABLE_REG, 0);
#ifdef NCR53C400
if (hostdata->flags & FLAG_NCR53C400) {
NCR5380_write(C400_CONTROL_STATUS_REG, CSR_BASE);
}
#endif
for (pass = 1; (NCR5380_read(STATUS_REG) & SR_BSY) && pass <= 6; ++pass) {
switch (pass) {
case 1:
case 3:
case 5:
printk(KERN_INFO "scsi%d: SCSI bus busy, waiting up to five seconds\n", instance->host_no);
timeout = jiffies + 5 * HZ;
NCR5380_poll_politely(instance, STATUS_REG, SR_BSY, 0, 5*HZ);
break;
case 2:
printk(KERN_WARNING "scsi%d: bus busy, attempting abort\n", instance->host_no);
do_abort(instance);
break;
case 4:
printk(KERN_WARNING "scsi%d: bus busy, attempting reset\n", instance->host_no);
do_reset(instance);
break;
case 6:
printk(KERN_ERR "scsi%d: bus locked solid or invalid override\n", instance->host_no);
return -ENXIO;
}
}
return 0;
}
static void NCR5380_exit(struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata = (struct NCR5380_hostdata *) instance->hostdata;
cancel_delayed_work_sync(&hostdata->coroutine);
}
static int NCR5380_queue_command_lck(struct scsi_cmnd *cmd, void (*done) (struct scsi_cmnd *))
{
struct Scsi_Host *instance = cmd->device->host;
struct NCR5380_hostdata *hostdata = (struct NCR5380_hostdata *) instance->hostdata;
struct scsi_cmnd *tmp;
#if (NDEBUG & NDEBUG_NO_WRITE)
switch (cmd->cmnd[0]) {
case WRITE_6:
case WRITE_10:
printk("scsi%d : WRITE attempted with NO_WRITE debugging flag set\n", instance->host_no);
cmd->result = (DID_ERROR << 16);
done(cmd);
return 0;
}
#endif
cmd->host_scribble = NULL;
cmd->scsi_done = done;
cmd->result = 0;
if (!(hostdata->issue_queue) || (cmd->cmnd[0] == REQUEST_SENSE)) {
LIST(cmd, hostdata->issue_queue);
cmd->host_scribble = (unsigned char *) hostdata->issue_queue;
hostdata->issue_queue = cmd;
} else {
for (tmp = (struct scsi_cmnd *) hostdata->issue_queue; tmp->host_scribble; tmp = (struct scsi_cmnd *) tmp->host_scribble);
LIST(cmd, tmp);
tmp->host_scribble = (unsigned char *) cmd;
}
dprintk(NDEBUG_QUEUES, "scsi%d : command added to %s of queue\n", instance->host_no, (cmd->cmnd[0] == REQUEST_SENSE) ? "head" : "tail");
schedule_delayed_work(&hostdata->coroutine, 0);
return 0;
}
irqreturn_t NCR5380_intr(int dummy, void *dev_id)
{
NCR5380_local_declare();
struct Scsi_Host *instance = dev_id;
struct NCR5380_hostdata *hostdata = (struct NCR5380_hostdata *) instance->hostdata;
int done;
unsigned char basr;
unsigned long flags;
dprintk(NDEBUG_INTR, "scsi : NCR5380 irq %d triggered\n",
instance->irq);
do {
done = 1;
spin_lock_irqsave(instance->host_lock, flags);
NCR5380_setup(instance);
basr = NCR5380_read(BUS_AND_STATUS_REG);
if (basr & BASR_IRQ) {
NCR5380_dprint(NDEBUG_INTR, instance);
if ((NCR5380_read(STATUS_REG) & (SR_SEL | SR_IO)) == (SR_SEL | SR_IO)) {
done = 0;
dprintk(NDEBUG_INTR, "scsi%d : SEL interrupt\n", instance->host_no);
NCR5380_reselect(instance);
(void) NCR5380_read(RESET_PARITY_INTERRUPT_REG);
} else if (basr & BASR_PARITY_ERROR) {
dprintk(NDEBUG_INTR, "scsi%d : PARITY interrupt\n", instance->host_no);
(void) NCR5380_read(RESET_PARITY_INTERRUPT_REG);
} else if ((NCR5380_read(STATUS_REG) & SR_RST) == SR_RST) {
dprintk(NDEBUG_INTR, "scsi%d : RESET interrupt\n", instance->host_no);
(void) NCR5380_read(RESET_PARITY_INTERRUPT_REG);
} else {
#if defined(REAL_DMA)
if ((NCR5380_read(MODE_REG) & MR_DMA) && ((basr & BASR_END_DMA_TRANSFER) || !(basr & BASR_PHASE_MATCH))) {
int transferred;
if (!hostdata->connected)
panic("scsi%d : received end of DMA interrupt with no connected cmd\n", instance->hostno);
transferred = (hostdata->dmalen - NCR5380_dma_residual(instance));
hostdata->connected->SCp.this_residual -= transferred;
hostdata->connected->SCp.ptr += transferred;
hostdata->dmalen = 0;
(void) NCR5380_read(RESET_PARITY_INTERRUPT_REG);
NCR5380_poll_politely(hostdata, BUS_AND_STATUS_REG, BASR_ACK, 0, 2*HZ);
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
}
#else
dprintk(NDEBUG_INTR, "scsi : unknown interrupt, BASR 0x%X, MR 0x%X, SR 0x%x\n", basr, NCR5380_read(MODE_REG), NCR5380_read(STATUS_REG));
(void) NCR5380_read(RESET_PARITY_INTERRUPT_REG);
#endif
}
}
spin_unlock_irqrestore(instance->host_lock, flags);
if(!done)
schedule_delayed_work(&hostdata->coroutine, 0);
} while (!done);
return IRQ_HANDLED;
}
static int NCR5380_select(struct Scsi_Host *instance, struct scsi_cmnd *cmd)
{
NCR5380_local_declare();
struct NCR5380_hostdata *hostdata = (struct NCR5380_hostdata *) instance->hostdata;
unsigned char tmp[3], phase;
unsigned char *data;
int len;
unsigned long timeout;
unsigned char value;
int err;
NCR5380_setup(instance);
if (hostdata->selecting)
goto part2;
hostdata->restart_select = 0;
NCR5380_dprint(NDEBUG_ARBITRATION, instance);
dprintk(NDEBUG_ARBITRATION, "scsi%d : starting arbitration, id = %d\n", instance->host_no, instance->this_id);
NCR5380_write(TARGET_COMMAND_REG, 0);
NCR5380_write(OUTPUT_DATA_REG, hostdata->id_mask);
NCR5380_write(MODE_REG, MR_ARBITRATE);
spin_unlock_irq(instance->host_lock);
err = NCR5380_poll_politely(instance, INITIATOR_COMMAND_REG, ICR_ARBITRATION_PROGRESS, ICR_ARBITRATION_PROGRESS, 5*HZ);
spin_lock_irq(instance->host_lock);
if (err < 0) {
printk(KERN_DEBUG "scsi: arbitration timeout at %d\n", __LINE__);
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
goto failed;
}
dprintk(NDEBUG_ARBITRATION, "scsi%d : arbitration complete\n", instance->host_no);
udelay(3);
if ((NCR5380_read(INITIATOR_COMMAND_REG) & ICR_ARBITRATION_LOST) || (NCR5380_read(CURRENT_SCSI_DATA_REG) & hostdata->id_higher_mask) || (NCR5380_read(INITIATOR_COMMAND_REG) & ICR_ARBITRATION_LOST)) {
NCR5380_write(MODE_REG, MR_BASE);
dprintk(NDEBUG_ARBITRATION, "scsi%d : lost arbitration, deasserting MR_ARBITRATE\n", instance->host_no);
goto failed;
}
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_SEL);
if (!(hostdata->flags & FLAG_DTC3181E) &&
(NCR5380_read(INITIATOR_COMMAND_REG) & ICR_ARBITRATION_LOST)) {
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
dprintk(NDEBUG_ARBITRATION, "scsi%d : lost arbitration, deasserting ICR_ASSERT_SEL\n", instance->host_no);
goto failed;
}
udelay(2);
dprintk(NDEBUG_ARBITRATION, "scsi%d : won arbitration\n", instance->host_no);
NCR5380_write(OUTPUT_DATA_REG, (hostdata->id_mask | (1 << scmd_id(cmd))));
NCR5380_write(INITIATOR_COMMAND_REG, (ICR_BASE | ICR_ASSERT_BSY | ICR_ASSERT_DATA | ICR_ASSERT_ATN | ICR_ASSERT_SEL));
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(SELECT_ENABLE_REG, 0);
udelay(1);
NCR5380_write(INITIATOR_COMMAND_REG, (ICR_BASE | ICR_ASSERT_DATA | ICR_ASSERT_ATN | ICR_ASSERT_SEL));
udelay(1);
dprintk(NDEBUG_SELECTION, "scsi%d : selecting target %d\n", instance->host_no, scmd_id(cmd));
timeout = jiffies + (250 * HZ / 1000);
hostdata->select_time = 0;
hostdata->selecting = cmd;
part2:
value = NCR5380_read(STATUS_REG) & (SR_BSY | SR_IO);
if (!value && (hostdata->select_time < HZ/4)) {
hostdata->select_time++;
NCR5380_set_timer(hostdata, 1);
return 0;
}
hostdata->selecting = NULL;
if ((NCR5380_read(STATUS_REG) & (SR_SEL | SR_IO)) == (SR_SEL | SR_IO)) {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_reselect(instance);
printk("scsi%d : reselection after won arbitration?\n", instance->host_no);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
return -1;
}
udelay(1);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN);
if (!(NCR5380_read(STATUS_REG) & SR_BSY)) {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
if (hostdata->targets_present & (1 << scmd_id(cmd))) {
printk(KERN_DEBUG "scsi%d : weirdness\n", instance->host_no);
if (hostdata->restart_select)
printk(KERN_DEBUG "\trestart select\n");
NCR5380_dprint(NDEBUG_SELECTION, instance);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
return -1;
}
cmd->result = DID_BAD_TARGET << 16;
cmd->scsi_done(cmd);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
dprintk(NDEBUG_SELECTION, "scsi%d : target did not respond within 250ms\n", instance->host_no);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
return 0;
}
hostdata->targets_present |= (1 << scmd_id(cmd));
spin_unlock_irq(instance->host_lock);
err = NCR5380_poll_politely(instance, STATUS_REG, SR_REQ, SR_REQ, HZ);
spin_lock_irq(instance->host_lock);
if(err) {
printk(KERN_ERR "scsi%d: timeout at NCR5380.c:%d\n", instance->host_no, __LINE__);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
goto failed;
}
dprintk(NDEBUG_SELECTION, "scsi%d : target %d selected, going into MESSAGE OUT phase.\n", instance->host_no, cmd->device->id);
tmp[0] = IDENTIFY(((instance->irq == NO_IRQ) ? 0 : 1), cmd->device->lun);
len = 1;
cmd->tag = 0;
data = tmp;
phase = PHASE_MSGOUT;
NCR5380_transfer_pio(instance, &phase, &len, &data);
dprintk(NDEBUG_SELECTION, "scsi%d : nexus established.\n", instance->host_no);
hostdata->connected = cmd;
hostdata->busy[cmd->device->id] |= (1 << (cmd->device->lun & 0xFF));
initialize_SCp(cmd);
return 0;
failed:
return -1;
}
static int NCR5380_transfer_pio(struct Scsi_Host *instance, unsigned char *phase, int *count, unsigned char **data) {
NCR5380_local_declare();
unsigned char p = *phase, tmp;
int c = *count;
unsigned char *d = *data;
int break_allowed = 0;
struct NCR5380_hostdata *hostdata = (struct NCR5380_hostdata *) instance->hostdata;
NCR5380_setup(instance);
if (!(p & SR_IO))
dprintk(NDEBUG_PIO, "scsi%d : pio write %d bytes\n", instance->host_no, c);
else
dprintk(NDEBUG_PIO, "scsi%d : pio read %d bytes\n", instance->host_no, c);
NCR5380_write(TARGET_COMMAND_REG, PHASE_SR_TO_TCR(p));
if ((p == PHASE_DATAIN) || (p == PHASE_DATAOUT)) {
break_allowed = 1;
}
do {
while (!((tmp = NCR5380_read(STATUS_REG)) & SR_REQ) && !break_allowed);
if (!(tmp & SR_REQ)) {
NCR5380_set_timer(hostdata, USLEEP_SLEEP);
break;
}
dprintk(NDEBUG_HANDSHAKE, "scsi%d : REQ detected\n", instance->host_no);
if ((tmp & PHASE_MASK) != p) {
dprintk(NDEBUG_HANDSHAKE, "scsi%d : phase mismatch\n", instance->host_no);
NCR5380_dprint_phase(NDEBUG_HANDSHAKE, instance);
break;
}
if (!(p & SR_IO))
NCR5380_write(OUTPUT_DATA_REG, *d);
else
*d = NCR5380_read(CURRENT_SCSI_DATA_REG);
++d;
if (!(p & SR_IO)) {
if (!((p & SR_MSG) && c > 1)) {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_DATA);
NCR5380_dprint(NDEBUG_PIO, instance);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_DATA | ICR_ASSERT_ACK);
} else {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_DATA | ICR_ASSERT_ATN);
NCR5380_dprint(NDEBUG_PIO, instance);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_DATA | ICR_ASSERT_ATN | ICR_ASSERT_ACK);
}
} else {
NCR5380_dprint(NDEBUG_PIO, instance);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ACK);
}
NCR5380_poll_politely(instance, STATUS_REG, SR_REQ, 0, 5*HZ);
dprintk(NDEBUG_HANDSHAKE, "scsi%d : req false, handshake complete\n", instance->host_no);
if (!(p == PHASE_MSGIN && c == 1)) {
if (p == PHASE_MSGOUT && c > 1)
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN);
else
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
}
} while (--c);
dprintk(NDEBUG_PIO, "scsi%d : residual %d\n", instance->host_no, c);
*count = c;
*data = d;
tmp = NCR5380_read(STATUS_REG);
if (tmp & SR_REQ)
*phase = tmp & PHASE_MASK;
else
*phase = PHASE_UNKNOWN;
if (!c || (*phase == p))
return 0;
else
return -1;
}
static void do_reset(struct Scsi_Host *host) {
NCR5380_local_declare();
NCR5380_setup(host);
NCR5380_write(TARGET_COMMAND_REG, PHASE_SR_TO_TCR(NCR5380_read(STATUS_REG) & PHASE_MASK));
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_RST);
udelay(25);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
}
static int do_abort(struct Scsi_Host *host) {
NCR5380_local_declare();
unsigned char *msgptr, phase, tmp;
int len;
int rc;
NCR5380_setup(host);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN);
rc = NCR5380_poll_politely(host, STATUS_REG, SR_REQ, SR_REQ, 60 * HZ);
if(rc < 0)
return -1;
tmp = (unsigned char)rc;
NCR5380_write(TARGET_COMMAND_REG, PHASE_SR_TO_TCR(tmp));
if ((tmp & PHASE_MASK) != PHASE_MSGOUT) {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN | ICR_ASSERT_ACK);
rc = NCR5380_poll_politely(host, STATUS_REG, SR_REQ, 0, 3*HZ);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN);
if(rc == -1)
return -1;
}
tmp = ABORT;
msgptr = &tmp;
len = 1;
phase = PHASE_MSGOUT;
NCR5380_transfer_pio(host, &phase, &len, &msgptr);
return len ? -1 : 0;
}
static int NCR5380_transfer_dma(struct Scsi_Host *instance, unsigned char *phase, int *count, unsigned char **data) {
NCR5380_local_declare();
register int c = *count;
register unsigned char p = *phase;
register unsigned char *d = *data;
unsigned char tmp;
int foo;
#if defined(REAL_DMA_POLL)
int cnt, toPIO;
unsigned char saved_data = 0, overrun = 0, residue;
#endif
struct NCR5380_hostdata *hostdata = (struct NCR5380_hostdata *) instance->hostdata;
NCR5380_setup(instance);
if ((tmp = (NCR5380_read(STATUS_REG) & PHASE_MASK)) != p) {
*phase = tmp;
return -1;
}
#if defined(REAL_DMA) || defined(REAL_DMA_POLL)
#ifdef READ_OVERRUNS
if (p & SR_IO) {
c -= 2;
}
#endif
dprintk(NDEBUG_DMA, "scsi%d : initializing DMA channel %d for %s, %d bytes %s %0x\n", instance->host_no, instance->dma_channel, (p & SR_IO) ? "reading" : "writing", c, (p & SR_IO) ? "to" : "from", (unsigned) d);
hostdata->dma_len = (p & SR_IO) ? NCR5380_dma_read_setup(instance, d, c) : NCR5380_dma_write_setup(instance, d, c);
#endif
NCR5380_write(TARGET_COMMAND_REG, PHASE_SR_TO_TCR(p));
#ifdef REAL_DMA
NCR5380_write(MODE_REG, MR_BASE | MR_DMA_MODE | MR_ENABLE_EOP_INTR | MR_MONITOR_BSY);
#elif defined(REAL_DMA_POLL)
NCR5380_write(MODE_REG, MR_BASE | MR_DMA_MODE);
#else
#if defined(PSEUDO_DMA) && defined(UNSAFE)
spin_unlock_irq(instance->host_lock);
#endif
if (hostdata->flags & FLAG_NCR53C400)
NCR5380_write(MODE_REG, MR_BASE | MR_DMA_MODE |
MR_ENABLE_PAR_CHECK | MR_ENABLE_PAR_INTR |
MR_ENABLE_EOP_INTR | MR_MONITOR_BSY);
else
NCR5380_write(MODE_REG, MR_BASE | MR_DMA_MODE);
#endif
dprintk(NDEBUG_DMA, "scsi%d : mode reg = 0x%X\n", instance->host_no, NCR5380_read(MODE_REG));
if (p & SR_IO) {
io_recovery_delay(1);
NCR5380_write(START_DMA_INITIATOR_RECEIVE_REG, 0);
} else {
io_recovery_delay(1);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_DATA);
io_recovery_delay(1);
NCR5380_write(START_DMA_SEND_REG, 0);
io_recovery_delay(1);
}
#if defined(REAL_DMA_POLL)
do {
tmp = NCR5380_read(BUS_AND_STATUS_REG);
} while ((tmp & BASR_PHASE_MATCH) && !(tmp & (BASR_BUSY_ERROR | BASR_END_DMA_TRANSFER)));
if (p & SR_IO) {
#ifdef READ_OVERRUNS
udelay(10);
if (((NCR5380_read(BUS_AND_STATUS_REG) & (BASR_PHASE_MATCH | BASR_ACK)) == (BASR_PHASE_MATCH | BASR_ACK))) {
saved_data = NCR5380_read(INPUT_DATA_REGISTER);
overrun = 1;
}
#endif
} else {
int limit = 100;
while (((tmp = NCR5380_read(BUS_AND_STATUS_REG)) & BASR_ACK) || (NCR5380_read(STATUS_REG) & SR_REQ)) {
if (!(tmp & BASR_PHASE_MATCH))
break;
if (--limit < 0)
break;
}
}
dprintk(NDEBUG_DMA, "scsi%d : polled DMA transfer complete, basr 0x%X, sr 0x%X\n", instance->host_no, tmp, NCR5380_read(STATUS_REG));
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
residue = NCR5380_dma_residual(instance);
c -= residue;
*count -= c;
*data += c;
*phase = NCR5380_read(STATUS_REG) & PHASE_MASK;
#ifdef READ_OVERRUNS
if (*phase == p && (p & SR_IO) && residue == 0) {
if (overrun) {
dprintk(NDEBUG_DMA, "Got an input overrun, using saved byte\n");
**data = saved_data;
*data += 1;
*count -= 1;
cnt = toPIO = 1;
} else {
printk("No overrun??\n");
cnt = toPIO = 2;
}
dprintk(NDEBUG_DMA, "Doing %d-byte PIO to 0x%X\n", cnt, *data);
NCR5380_transfer_pio(instance, phase, &cnt, data);
*count -= toPIO - cnt;
}
#endif
dprintk(NDEBUG_DMA, "Return with data ptr = 0x%X, count %d, last 0x%X, next 0x%X\n", *data, *count, *(*data + *count - 1), *(*data + *count));
return 0;
#elif defined(REAL_DMA)
return 0;
#else
if (p & SR_IO) {
#ifdef DMA_WORKS_RIGHT
foo = NCR5380_pread(instance, d, c);
#else
int diff = 1;
if (hostdata->flags & FLAG_NCR53C400) {
diff = 0;
}
if (!(foo = NCR5380_pread(instance, d, c - diff))) {
if (!(hostdata->flags & FLAG_NCR53C400)) {
while (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_DRQ));
while (NCR5380_read(STATUS_REG) & SR_REQ);
d[c - 1] = NCR5380_read(INPUT_DATA_REG);
}
}
#endif
} else {
#ifdef DMA_WORKS_RIGHT
foo = NCR5380_pwrite(instance, d, c);
#else
int timeout;
dprintk(NDEBUG_C400_PWRITE, "About to pwrite %d bytes\n", c);
if (!(foo = NCR5380_pwrite(instance, d, c))) {
if (!(hostdata->flags & FLAG_HAS_LAST_BYTE_SENT)) {
timeout = 20000;
while (!(NCR5380_read(BUS_AND_STATUS_REG) & BASR_DRQ) && (NCR5380_read(BUS_AND_STATUS_REG) & BASR_PHASE_MATCH));
if (!timeout)
dprintk(NDEBUG_LAST_BYTE_SENT, "scsi%d : timed out on last byte\n", instance->host_no);
if (hostdata->flags & FLAG_CHECK_LAST_BYTE_SENT) {
hostdata->flags &= ~FLAG_CHECK_LAST_BYTE_SENT;
if (NCR5380_read(TARGET_COMMAND_REG) & TCR_LAST_BYTE_SENT) {
hostdata->flags |= FLAG_HAS_LAST_BYTE_SENT;
dprintk(NDEBUG_LAST_BYTE_SENT, "scsi%d : last byte sent works\n", instance->host_no);
}
}
} else {
dprintk(NDEBUG_C400_PWRITE, "Waiting for LASTBYTE\n");
while (!(NCR5380_read(TARGET_COMMAND_REG) & TCR_LAST_BYTE_SENT));
dprintk(NDEBUG_C400_PWRITE, "Got LASTBYTE\n");
}
}
#endif
}
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
if ((!(p & SR_IO)) && (hostdata->flags & FLAG_NCR53C400)) {
dprintk(NDEBUG_C400_PWRITE, "53C400w: Checking for IRQ\n");
if (NCR5380_read(BUS_AND_STATUS_REG) & BASR_IRQ) {
dprintk(NDEBUG_C400_PWRITE, "53C400w: got it, reading reset interrupt reg\n");
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
} else {
printk("53C400w: IRQ NOT THERE!\n");
}
}
*data = d + c;
*count = 0;
*phase = NCR5380_read(STATUS_REG) & PHASE_MASK;
#if defined(PSEUDO_DMA) && defined(UNSAFE)
spin_lock_irq(instance->host_lock);
#endif
return foo;
#endif
}
static void NCR5380_reselect(struct Scsi_Host *instance) {
NCR5380_local_declare();
struct NCR5380_hostdata *hostdata = (struct NCR5380_hostdata *)
instance->hostdata;
unsigned char target_mask;
unsigned char lun, phase;
int len;
unsigned char msg[3];
unsigned char *data;
struct scsi_cmnd *tmp = NULL, *prev;
int abort = 0;
NCR5380_setup(instance);
NCR5380_write(MODE_REG, MR_BASE);
hostdata->restart_select = 1;
target_mask = NCR5380_read(CURRENT_SCSI_DATA_REG) & ~(hostdata->id_mask);
dprintk(NDEBUG_SELECTION, "scsi%d : reselect\n", instance->host_no);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_BSY);
if(NCR5380_poll_politely(instance, STATUS_REG, SR_SEL, 0, 2*HZ)<0)
abort = 1;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
if(NCR5380_poll_politely(instance, STATUS_REG, SR_REQ, SR_REQ, 2*HZ))
abort = 1;
len = 1;
data = msg;
phase = PHASE_MSGIN;
NCR5380_transfer_pio(instance, &phase, &len, &data);
if (!(msg[0] & 0x80)) {
printk(KERN_ERR "scsi%d : expecting IDENTIFY message, got ", instance->host_no);
spi_print_msg(msg);
abort = 1;
} else {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
lun = (msg[0] & 0x07);
for (tmp = (struct scsi_cmnd *) hostdata->disconnected_queue, prev = NULL; tmp; prev = tmp, tmp = (struct scsi_cmnd *) tmp->host_scribble)
if ((target_mask == (1 << tmp->device->id)) && (lun == (u8)tmp->device->lun)
) {
if (prev) {
REMOVE(prev, prev->host_scribble, tmp, tmp->host_scribble);
prev->host_scribble = tmp->host_scribble;
} else {
REMOVE(-1, hostdata->disconnected_queue, tmp, tmp->host_scribble);
hostdata->disconnected_queue = (struct scsi_cmnd *) tmp->host_scribble;
}
tmp->host_scribble = NULL;
break;
}
if (!tmp) {
printk(KERN_ERR "scsi%d : warning : target bitmask %02x lun %d not in disconnect_queue.\n", instance->host_no, target_mask, lun);
abort = 1;
}
}
if (abort) {
do_abort(instance);
} else {
hostdata->connected = tmp;
dprintk(NDEBUG_RESELECTION, "scsi%d : nexus established, target = %d, lun = %llu, tag = %d\n", instance->host_no, tmp->device->id, tmp->device->lun, tmp->tag);
}
}
static void NCR5380_dma_complete(NCR5380_instance * instance) {
NCR5380_local_declare();
struct NCR5380_hostdata *hostdata = (struct NCR5380_hostdata *) instance->hostdata;
int transferred;
NCR5380_setup(instance);
NCR5380_poll_politely(instance, BUS_AND_STATUS_REG, BASR_ACK, 0, 5*HZ);
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
if (!(hostdata->connected->SCp.phase & SR_CD)) {
transferred = instance->dmalen - NCR5380_dma_residual();
hostdata->connected->SCp.this_residual -= transferred;
hostdata->connected->SCp.ptr += transferred;
}
}
static int NCR5380_abort(struct scsi_cmnd *cmd)
{
NCR5380_local_declare();
struct Scsi_Host *instance = cmd->device->host;
struct NCR5380_hostdata *hostdata = (struct NCR5380_hostdata *) instance->hostdata;
struct scsi_cmnd *tmp, **prev;
scmd_printk(KERN_WARNING, cmd, "aborting command\n");
NCR5380_print_status(instance);
NCR5380_setup(instance);
dprintk(NDEBUG_ABORT, "scsi%d : abort called\n", instance->host_no);
dprintk(NDEBUG_ABORT, " basr 0x%X, sr 0x%X\n", NCR5380_read(BUS_AND_STATUS_REG), NCR5380_read(STATUS_REG));
#if 0
if (hostdata->connected == cmd) {
dprintk(NDEBUG_ABORT, "scsi%d : aborting connected command\n", instance->host_no);
hostdata->aborted = 1;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_ASSERT_ATN);
return SUCCESS;
}
#endif
dprintk(NDEBUG_ABORT, "scsi%d : abort going into loop.\n", instance->host_no);
for (prev = (struct scsi_cmnd **) &(hostdata->issue_queue), tmp = (struct scsi_cmnd *) hostdata->issue_queue; tmp; prev = (struct scsi_cmnd **) &(tmp->host_scribble), tmp = (struct scsi_cmnd *) tmp->host_scribble)
if (cmd == tmp) {
REMOVE(5, *prev, tmp, tmp->host_scribble);
(*prev) = (struct scsi_cmnd *) tmp->host_scribble;
tmp->host_scribble = NULL;
tmp->result = DID_ABORT << 16;
dprintk(NDEBUG_ABORT, "scsi%d : abort removed command from issue queue.\n", instance->host_no);
tmp->scsi_done(tmp);
return SUCCESS;
}
#if (NDEBUG & NDEBUG_ABORT)
else if (prev == tmp)
printk(KERN_ERR "scsi%d : LOOP\n", instance->host_no);
#endif
if (hostdata->connected) {
dprintk(NDEBUG_ABORT, "scsi%d : abort failed, command connected.\n", instance->host_no);
return FAILED;
}
for (tmp = (struct scsi_cmnd *) hostdata->disconnected_queue; tmp; tmp = (struct scsi_cmnd *) tmp->host_scribble)
if (cmd == tmp) {
dprintk(NDEBUG_ABORT, "scsi%d : aborting disconnected command.\n", instance->host_no);
if (NCR5380_select(instance, cmd))
return FAILED;
dprintk(NDEBUG_ABORT, "scsi%d : nexus reestablished.\n", instance->host_no);
do_abort(instance);
for (prev = (struct scsi_cmnd **) &(hostdata->disconnected_queue), tmp = (struct scsi_cmnd *) hostdata->disconnected_queue; tmp; prev = (struct scsi_cmnd **) &(tmp->host_scribble), tmp = (struct scsi_cmnd *) tmp->host_scribble)
if (cmd == tmp) {
REMOVE(5, *prev, tmp, tmp->host_scribble);
*prev = (struct scsi_cmnd *) tmp->host_scribble;
tmp->host_scribble = NULL;
tmp->result = DID_ABORT << 16;
tmp->scsi_done(tmp);
return SUCCESS;
}
}
printk(KERN_WARNING "scsi%d : warning : SCSI command probably completed successfully\n"
" before abortion\n", instance->host_no);
return FAILED;
}
static int NCR5380_bus_reset(struct scsi_cmnd *cmd)
{
struct Scsi_Host *instance = cmd->device->host;
NCR5380_local_declare();
NCR5380_setup(instance);
NCR5380_print_status(instance);
spin_lock_irq(instance->host_lock);
do_reset(instance);
spin_unlock_irq(instance->host_lock);
return SUCCESS;
}
