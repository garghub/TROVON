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
cmd->SCp.Status = 0;
cmd->SCp.Message = 0;
}
static int NCR5380_poll_politely2(struct Scsi_Host *instance,
int reg1, int bit1, int val1,
int reg2, int bit2, int val2, int wait)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
unsigned long deadline = jiffies + wait;
unsigned long n;
n = min(10000U, jiffies_to_usecs(wait));
n *= hostdata->accesses_per_ms;
n /= 2000;
do {
if ((NCR5380_read(reg1) & bit1) == val1)
return 0;
if ((NCR5380_read(reg2) & bit2) == val2)
return 0;
cpu_relax();
} while (n--);
if (irqs_disabled() || in_interrupt())
return -ETIMEDOUT;
while (time_is_after_jiffies(deadline)) {
schedule_timeout_uninterruptible(1);
if ((NCR5380_read(reg1) & bit1) == val1)
return 0;
if ((NCR5380_read(reg2) & bit2) == val2)
return 0;
}
return -ETIMEDOUT;
}
static inline int NCR5380_poll_politely(struct Scsi_Host *instance,
int reg, int bit, int val, int wait)
{
return NCR5380_poll_politely2(instance, reg, bit, val,
reg, bit, val, wait);
}
static void NCR5380_print(struct Scsi_Host *instance)
{
unsigned char status, data, basr, mr, icr, i;
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
unsigned char status;
int i;
status = NCR5380_read(STATUS_REG);
if (!(status & SR_REQ))
shost_printk(KERN_DEBUG, instance, "REQ not asserted, phase unknown.\n");
else {
for (i = 0; (phases[i].value != PHASE_UNKNOWN) &&
(phases[i].value != (status & PHASE_MASK)); ++i)
;
shost_printk(KERN_DEBUG, instance, "phase %s\n", phases[i].name);
}
}
static irqreturn_t __init probe_intr(int irq, void *dev_id)
{
probe_irq = irq;
return IRQ_HANDLED;
}
static int __init __maybe_unused NCR5380_probe_irq(struct Scsi_Host *instance,
int possible)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
unsigned long timeout;
int trying_irqs, i, mask;
for (trying_irqs = 0, i = 1, mask = 2; i < 16; ++i, mask <<= 1)
if ((mask & possible) && (request_irq(i, &probe_intr, 0, "NCR-probe", NULL) == 0))
trying_irqs |= mask;
timeout = jiffies + msecs_to_jiffies(250);
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
"options { %s} ",
instance->hostt->name, instance->io_port, instance->n_io_port,
instance->base, instance->irq,
instance->can_queue, instance->cmd_per_lun,
instance->sg_tablesize, instance->this_id,
hostdata->flags & FLAG_NO_DMA_FIXUP ? "NO_DMA_FIXUP " : "",
hostdata->flags & FLAG_NO_PSEUDO_DMA ? "NO_PSEUDO_DMA " : "",
hostdata->flags & FLAG_TOSHIBA_DELAY ? "TOSHIBA_DELAY " : "",
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
"");
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
struct NCR5380_hostdata *hostdata = shost_priv(instance);
seq_printf(m, "Highwater I/O busy spin counts: write %d, read %d\n",
hostdata->spin_max_w, hostdata->spin_max_r);
return 0;
}
static int NCR5380_init(struct Scsi_Host *instance, int flags)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
int i;
unsigned long deadline;
hostdata->host = instance;
hostdata->id_mask = 1 << instance->this_id;
hostdata->id_higher_mask = 0;
for (i = hostdata->id_mask; i <= 0x80; i <<= 1)
if (i > hostdata->id_mask)
hostdata->id_higher_mask |= i;
for (i = 0; i < 8; ++i)
hostdata->busy[i] = 0;
#ifdef REAL_DMA
hostdata->dmalen = 0;
#endif
spin_lock_init(&hostdata->lock);
hostdata->connected = NULL;
hostdata->sensing = NULL;
INIT_LIST_HEAD(&hostdata->autosense);
INIT_LIST_HEAD(&hostdata->unissued);
INIT_LIST_HEAD(&hostdata->disconnected);
hostdata->flags = flags;
INIT_WORK(&hostdata->main_task, NCR5380_main);
hostdata->work_q = alloc_workqueue("ncr5380_%d",
WQ_UNBOUND | WQ_MEM_RECLAIM,
1, instance->host_no);
if (!hostdata->work_q)
return -ENOMEM;
prepare_info(instance);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(TARGET_COMMAND_REG, 0);
NCR5380_write(SELECT_ENABLE_REG, 0);
i = 0;
deadline = jiffies + 1;
do {
cpu_relax();
} while (time_is_after_jiffies(deadline));
deadline += msecs_to_jiffies(256);
do {
NCR5380_read(STATUS_REG);
++i;
cpu_relax();
} while (time_is_after_jiffies(deadline));
hostdata->accesses_per_ms = i / 256;
return 0;
}
static int NCR5380_maybe_reset_bus(struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
int pass;
for (pass = 1; (NCR5380_read(STATUS_REG) & SR_BSY) && pass <= 6; ++pass) {
switch (pass) {
case 1:
case 3:
case 5:
shost_printk(KERN_ERR, instance, "SCSI bus busy, waiting up to five seconds\n");
NCR5380_poll_politely(instance,
STATUS_REG, SR_BSY, 0, 5 * HZ);
break;
case 2:
shost_printk(KERN_ERR, instance, "bus busy, attempting abort\n");
do_abort(instance);
break;
case 4:
shost_printk(KERN_ERR, instance, "bus busy, attempting reset\n");
do_reset(instance);
if (hostdata->flags & FLAG_TOSHIBA_DELAY)
msleep(2500);
else
msleep(500);
break;
case 6:
shost_printk(KERN_ERR, instance, "bus locked solid\n");
return -ENXIO;
}
}
return 0;
}
static void NCR5380_exit(struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
cancel_work_sync(&hostdata->main_task);
destroy_workqueue(hostdata->work_q);
}
static void complete_cmd(struct Scsi_Host *instance,
struct scsi_cmnd *cmd)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
dsprintk(NDEBUG_QUEUES, instance, "complete_cmd: cmd %p\n", cmd);
if (hostdata->sensing == cmd) {
if ((cmd->result & 0xff) != SAM_STAT_GOOD) {
scsi_eh_restore_cmnd(cmd, &hostdata->ses);
set_host_byte(cmd, DID_ERROR);
} else
scsi_eh_restore_cmnd(cmd, &hostdata->ses);
hostdata->sensing = NULL;
}
hostdata->busy[scmd_id(cmd)] &= ~(1 << cmd->device->lun);
cmd->scsi_done(cmd);
}
static int NCR5380_queue_command(struct Scsi_Host *instance,
struct scsi_cmnd *cmd)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
struct NCR5380_cmd *ncmd = scsi_cmd_priv(cmd);
unsigned long flags;
#if (NDEBUG & NDEBUG_NO_WRITE)
switch (cmd->cmnd[0]) {
case WRITE_6:
case WRITE_10:
shost_printk(KERN_DEBUG, instance, "WRITE attempted with NDEBUG_NO_WRITE set\n");
cmd->result = (DID_ERROR << 16);
cmd->scsi_done(cmd);
return 0;
}
#endif
cmd->result = 0;
spin_lock_irqsave(&hostdata->lock, flags);
if (cmd->cmnd[0] == REQUEST_SENSE)
list_add(&ncmd->list, &hostdata->unissued);
else
list_add_tail(&ncmd->list, &hostdata->unissued);
spin_unlock_irqrestore(&hostdata->lock, flags);
dsprintk(NDEBUG_QUEUES, instance, "command %p added to %s of queue\n",
cmd, (cmd->cmnd[0] == REQUEST_SENSE) ? "head" : "tail");
queue_work(hostdata->work_q, &hostdata->main_task);
return 0;
}
static struct scsi_cmnd *dequeue_next_cmd(struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
struct NCR5380_cmd *ncmd;
struct scsi_cmnd *cmd;
if (hostdata->sensing || list_empty(&hostdata->autosense)) {
list_for_each_entry(ncmd, &hostdata->unissued, list) {
cmd = NCR5380_to_scmd(ncmd);
dsprintk(NDEBUG_QUEUES, instance, "dequeue: cmd=%p target=%d busy=0x%02x lun=%llu\n",
cmd, scmd_id(cmd), hostdata->busy[scmd_id(cmd)], cmd->device->lun);
if (!(hostdata->busy[scmd_id(cmd)] & (1 << cmd->device->lun))) {
list_del(&ncmd->list);
dsprintk(NDEBUG_QUEUES, instance,
"dequeue: removed %p from issue queue\n", cmd);
return cmd;
}
}
} else {
ncmd = list_first_entry(&hostdata->autosense,
struct NCR5380_cmd, list);
list_del(&ncmd->list);
cmd = NCR5380_to_scmd(ncmd);
dsprintk(NDEBUG_QUEUES, instance,
"dequeue: removed %p from autosense queue\n", cmd);
scsi_eh_prep_cmnd(cmd, &hostdata->ses, NULL, 0, ~0);
hostdata->sensing = cmd;
return cmd;
}
return NULL;
}
static void requeue_cmd(struct Scsi_Host *instance, struct scsi_cmnd *cmd)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
struct NCR5380_cmd *ncmd = scsi_cmd_priv(cmd);
if (hostdata->sensing == cmd) {
scsi_eh_restore_cmnd(cmd, &hostdata->ses);
list_add(&ncmd->list, &hostdata->autosense);
hostdata->sensing = NULL;
} else
list_add(&ncmd->list, &hostdata->unissued);
}
static void NCR5380_main(struct work_struct *work)
{
struct NCR5380_hostdata *hostdata =
container_of(work, struct NCR5380_hostdata, main_task);
struct Scsi_Host *instance = hostdata->host;
int done;
do {
done = 1;
spin_lock_irq(&hostdata->lock);
while (!hostdata->connected && !hostdata->selecting) {
struct scsi_cmnd *cmd = dequeue_next_cmd(instance);
if (!cmd)
break;
dsprintk(NDEBUG_MAIN, instance, "main: dequeued %p\n", cmd);
if (!NCR5380_select(instance, cmd)) {
dsprintk(NDEBUG_MAIN, instance, "main: select complete\n");
} else {
dsprintk(NDEBUG_MAIN | NDEBUG_QUEUES, instance,
"main: select failed, returning %p to queue\n", cmd);
requeue_cmd(instance, cmd);
}
}
if (hostdata->connected
#ifdef REAL_DMA
&& !hostdata->dmalen
#endif
) {
dsprintk(NDEBUG_MAIN, instance, "main: performing information transfer\n");
NCR5380_information_transfer(instance);
done = 0;
}
spin_unlock_irq(&hostdata->lock);
if (!done)
cond_resched();
} while (!done);
}
static irqreturn_t NCR5380_intr(int irq, void *dev_id)
{
struct Scsi_Host *instance = dev_id;
struct NCR5380_hostdata *hostdata = shost_priv(instance);
int handled = 0;
unsigned char basr;
unsigned long flags;
spin_lock_irqsave(&hostdata->lock, flags);
basr = NCR5380_read(BUS_AND_STATUS_REG);
if (basr & BASR_IRQ) {
unsigned char mr = NCR5380_read(MODE_REG);
unsigned char sr = NCR5380_read(STATUS_REG);
dsprintk(NDEBUG_INTR, instance, "IRQ %d, BASR 0x%02x, SR 0x%02x, MR 0x%02x\n",
irq, basr, sr, mr);
#if defined(REAL_DMA)
if ((mr & MR_DMA_MODE) || (mr & MR_MONITOR_BSY)) {
dsprintk(NDEBUG_INTR, instance, "interrupt in DMA mode\n");
int transferred;
if (!hostdata->connected)
panic("scsi%d : DMA interrupt with no connected cmd\n",
instance->hostno);
transferred = hostdata->dmalen - NCR5380_dma_residual(instance);
hostdata->connected->SCp.this_residual -= transferred;
hostdata->connected->SCp.ptr += transferred;
hostdata->dmalen = 0;
NCR5380_poll_politely(hostdata, BUS_AND_STATUS_REG, BASR_ACK, 0, 2 * HZ);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
} else
#endif
if ((NCR5380_read(CURRENT_SCSI_DATA_REG) & hostdata->id_mask) &&
(sr & (SR_SEL | SR_IO | SR_BSY | SR_RST)) == (SR_SEL | SR_IO)) {
NCR5380_write(SELECT_ENABLE_REG, 0);
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
dsprintk(NDEBUG_INTR, instance, "interrupt with SEL and IO\n");
if (!hostdata->connected) {
NCR5380_reselect(instance);
queue_work(hostdata->work_q, &hostdata->main_task);
}
if (!hostdata->connected)
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
} else {
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
dsprintk(NDEBUG_INTR, instance, "unknown interrupt\n");
}
handled = 1;
} else {
shost_printk(KERN_NOTICE, instance, "interrupt without IRQ bit\n");
}
spin_unlock_irqrestore(&hostdata->lock, flags);
return IRQ_RETVAL(handled);
}
static struct scsi_cmnd *NCR5380_select(struct Scsi_Host *instance,
struct scsi_cmnd *cmd)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
unsigned char tmp[3], phase;
unsigned char *data;
int len;
int err;
NCR5380_dprint(NDEBUG_ARBITRATION, instance);
dsprintk(NDEBUG_ARBITRATION, instance, "starting arbitration, id = %d\n",
instance->this_id);
hostdata->selecting = cmd;
NCR5380_write(TARGET_COMMAND_REG, 0);
NCR5380_write(OUTPUT_DATA_REG, hostdata->id_mask);
NCR5380_write(MODE_REG, MR_ARBITRATE);
spin_unlock_irq(&hostdata->lock);
err = NCR5380_poll_politely2(instance, MODE_REG, MR_ARBITRATE, 0,
INITIATOR_COMMAND_REG, ICR_ARBITRATION_PROGRESS,
ICR_ARBITRATION_PROGRESS, HZ);
spin_lock_irq(&hostdata->lock);
if (!(NCR5380_read(MODE_REG) & MR_ARBITRATE)) {
goto out;
}
if (!hostdata->selecting) {
NCR5380_write(MODE_REG, MR_BASE);
goto out;
}
if (err < 0) {
NCR5380_write(MODE_REG, MR_BASE);
shost_printk(KERN_ERR, instance,
"select: arbitration timeout\n");
goto out;
}
spin_unlock_irq(&hostdata->lock);
udelay(3);
if ((NCR5380_read(INITIATOR_COMMAND_REG) & ICR_ARBITRATION_LOST) ||
(NCR5380_read(CURRENT_SCSI_DATA_REG) & hostdata->id_higher_mask) ||
(NCR5380_read(INITIATOR_COMMAND_REG) & ICR_ARBITRATION_LOST)) {
NCR5380_write(MODE_REG, MR_BASE);
dsprintk(NDEBUG_ARBITRATION, instance, "lost arbitration, deasserting MR_ARBITRATE\n");
spin_lock_irq(&hostdata->lock);
goto out;
}
NCR5380_write(INITIATOR_COMMAND_REG,
ICR_BASE | ICR_ASSERT_SEL | ICR_ASSERT_BSY);
if (hostdata->flags & FLAG_TOSHIBA_DELAY)
udelay(15);
else
udelay(2);
spin_lock_irq(&hostdata->lock);
if (!(NCR5380_read(MODE_REG) & MR_ARBITRATE))
goto out;
if (!hostdata->selecting) {
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
goto out;
}
dsprintk(NDEBUG_ARBITRATION, instance, "won arbitration\n");
NCR5380_write(OUTPUT_DATA_REG, hostdata->id_mask | (1 << scmd_id(cmd)));
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_BSY |
ICR_ASSERT_DATA | ICR_ASSERT_ATN | ICR_ASSERT_SEL);
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(SELECT_ENABLE_REG, 0);
spin_unlock_irq(&hostdata->lock);
udelay(1);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_DATA |
ICR_ASSERT_ATN | ICR_ASSERT_SEL);
udelay(1);
dsprintk(NDEBUG_SELECTION, instance, "selecting target %d\n", scmd_id(cmd));
err = NCR5380_poll_politely(instance, STATUS_REG, SR_BSY, SR_BSY,
msecs_to_jiffies(250));
if ((NCR5380_read(STATUS_REG) & (SR_SEL | SR_IO)) == (SR_SEL | SR_IO)) {
spin_lock_irq(&hostdata->lock);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_reselect(instance);
if (!hostdata->connected)
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
shost_printk(KERN_ERR, instance, "reselection after won arbitration?\n");
goto out;
}
if (err < 0) {
spin_lock_irq(&hostdata->lock);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
if (hostdata->selecting) {
cmd->result = DID_BAD_TARGET << 16;
complete_cmd(instance, cmd);
dsprintk(NDEBUG_SELECTION, instance, "target did not respond within 250ms\n");
cmd = NULL;
}
goto out;
}
udelay(1);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN);
err = NCR5380_poll_politely(instance, STATUS_REG, SR_REQ, SR_REQ, HZ);
spin_lock_irq(&hostdata->lock);
if (err < 0) {
shost_printk(KERN_ERR, instance, "select: REQ timeout\n");
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
goto out;
}
if (!hostdata->selecting) {
do_abort(instance);
goto out;
}
dsprintk(NDEBUG_SELECTION, instance, "target %d selected, going into MESSAGE OUT phase.\n",
scmd_id(cmd));
tmp[0] = IDENTIFY(((instance->irq == NO_IRQ) ? 0 : 1), cmd->device->lun);
len = 1;
cmd->tag = 0;
data = tmp;
phase = PHASE_MSGOUT;
NCR5380_transfer_pio(instance, &phase, &len, &data);
dsprintk(NDEBUG_SELECTION, instance, "nexus established.\n");
hostdata->connected = cmd;
hostdata->busy[cmd->device->id] |= 1 << cmd->device->lun;
initialize_SCp(cmd);
cmd = NULL;
out:
if (!hostdata->selecting)
return NULL;
hostdata->selecting = NULL;
return cmd;
}
static int NCR5380_transfer_pio(struct Scsi_Host *instance,
unsigned char *phase, int *count,
unsigned char **data)
{
unsigned char p = *phase, tmp;
int c = *count;
unsigned char *d = *data;
NCR5380_write(TARGET_COMMAND_REG, PHASE_SR_TO_TCR(p));
do {
if (NCR5380_poll_politely(instance, STATUS_REG, SR_REQ, SR_REQ, HZ) < 0)
break;
dsprintk(NDEBUG_HANDSHAKE, instance, "REQ asserted\n");
if ((NCR5380_read(STATUS_REG) & PHASE_MASK) != p) {
dsprintk(NDEBUG_PIO, instance, "phase mismatch\n");
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
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_DATA);
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
if (NCR5380_poll_politely(instance,
STATUS_REG, SR_REQ, 0, 5 * HZ) < 0)
break;
dsprintk(NDEBUG_HANDSHAKE, instance, "REQ negated, handshake complete\n");
if (!(p == PHASE_MSGIN && c == 1)) {
if (p == PHASE_MSGOUT && c > 1)
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN);
else
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
}
} while (--c);
dsprintk(NDEBUG_PIO, instance, "residual %d\n", c);
*count = c;
*data = d;
tmp = NCR5380_read(STATUS_REG);
if ((tmp & SR_REQ) || ((tmp & SR_IO) && c == 0))
*phase = tmp & PHASE_MASK;
else
*phase = PHASE_UNKNOWN;
if (!c || (*phase == p))
return 0;
else
return -1;
}
static void do_reset(struct Scsi_Host *instance)
{
unsigned long flags;
local_irq_save(flags);
NCR5380_write(TARGET_COMMAND_REG,
PHASE_SR_TO_TCR(NCR5380_read(STATUS_REG) & PHASE_MASK));
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_RST);
udelay(50);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
(void)NCR5380_read(RESET_PARITY_INTERRUPT_REG);
local_irq_restore(flags);
}
static int do_abort(struct Scsi_Host *instance)
{
unsigned char *msgptr, phase, tmp;
int len;
int rc;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN);
rc = NCR5380_poll_politely(instance, STATUS_REG, SR_REQ, SR_REQ, 10 * HZ);
if (rc < 0)
goto timeout;
tmp = NCR5380_read(STATUS_REG) & PHASE_MASK;
NCR5380_write(TARGET_COMMAND_REG, PHASE_SR_TO_TCR(tmp));
if (tmp != PHASE_MSGOUT) {
NCR5380_write(INITIATOR_COMMAND_REG,
ICR_BASE | ICR_ASSERT_ATN | ICR_ASSERT_ACK);
rc = NCR5380_poll_politely(instance, STATUS_REG, SR_REQ, 0, 3 * HZ);
if (rc < 0)
goto timeout;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN);
}
tmp = ABORT;
msgptr = &tmp;
len = 1;
phase = PHASE_MSGOUT;
NCR5380_transfer_pio(instance, &phase, &len, &msgptr);
return len ? -1 : 0;
timeout:
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
return -1;
}
static int NCR5380_transfer_dma(struct Scsi_Host *instance,
unsigned char *phase, int *count,
unsigned char **data)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
register int c = *count;
register unsigned char p = *phase;
register unsigned char *d = *data;
unsigned char tmp;
int foo;
#if defined(REAL_DMA_POLL)
int cnt, toPIO;
unsigned char saved_data = 0, overrun = 0, residue;
#endif
if ((tmp = (NCR5380_read(STATUS_REG) & PHASE_MASK)) != p) {
*phase = tmp;
return -1;
}
#if defined(REAL_DMA) || defined(REAL_DMA_POLL)
if (p & SR_IO) {
if (!(hostdata->flags & FLAG_NO_DMA_FIXUPS))
c -= 2;
}
hostdata->dma_len = (p & SR_IO) ? NCR5380_dma_read_setup(instance, d, c) : NCR5380_dma_write_setup(instance, d, c);
dsprintk(NDEBUG_DMA, instance, "initializing DMA %s: length %d, address %p\n",
(p & SR_IO) ? "receive" : "send", c, *data);
#endif
NCR5380_write(TARGET_COMMAND_REG, PHASE_SR_TO_TCR(p));
#ifdef REAL_DMA
NCR5380_write(MODE_REG, MR_BASE | MR_DMA_MODE | MR_MONITOR_BSY |
MR_ENABLE_EOP_INTR);
#elif defined(REAL_DMA_POLL)
NCR5380_write(MODE_REG, MR_BASE | MR_DMA_MODE | MR_MONITOR_BSY);
#else
if (hostdata->flags & FLAG_NO_DMA_FIXUP)
NCR5380_write(MODE_REG, MR_BASE | MR_DMA_MODE | MR_MONITOR_BSY |
MR_ENABLE_EOP_INTR);
else
NCR5380_write(MODE_REG, MR_BASE | MR_DMA_MODE | MR_MONITOR_BSY);
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
if (!(hostdata->flags & FLAG_NO_DMA_FIXUPS)) {
udelay(10);
if ((NCR5380_read(BUS_AND_STATUS_REG) & (BASR_PHASE_MATCH | BASR_ACK)) ==
(BASR_PHASE_MATCH | BASR_ACK)) {
saved_data = NCR5380_read(INPUT_DATA_REGISTER);
overrun = 1;
}
}
} else {
int limit = 100;
while (((tmp = NCR5380_read(BUS_AND_STATUS_REG)) & BASR_ACK) || (NCR5380_read(STATUS_REG) & SR_REQ)) {
if (!(tmp & BASR_PHASE_MATCH))
break;
if (--limit < 0)
break;
}
}
dsprintk(NDEBUG_DMA, "polled DMA transfer complete, basr 0x%02x, sr 0x%02x\n",
tmp, NCR5380_read(STATUS_REG));
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
residue = NCR5380_dma_residual(instance);
c -= residue;
*count -= c;
*data += c;
*phase = NCR5380_read(STATUS_REG) & PHASE_MASK;
if (!(hostdata->flags & FLAG_NO_DMA_FIXUPS) &&
*phase == p && (p & SR_IO) && residue == 0) {
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
dprintk(NDEBUG_DMA, "Return with data ptr = 0x%X, count %d, last 0x%X, next 0x%X\n", *data, *count, *(*data + *count - 1), *(*data + *count));
return 0;
#elif defined(REAL_DMA)
return 0;
#else
if (p & SR_IO) {
foo = NCR5380_pread(instance, d,
hostdata->flags & FLAG_NO_DMA_FIXUP ? c : c - 1);
if (!foo && !(hostdata->flags & FLAG_NO_DMA_FIXUP)) {
if (NCR5380_poll_politely(instance, BUS_AND_STATUS_REG,
BASR_DRQ, BASR_DRQ, HZ) < 0) {
foo = -1;
shost_printk(KERN_ERR, instance, "PDMA read: DRQ timeout\n");
}
if (NCR5380_poll_politely(instance, STATUS_REG,
SR_REQ, 0, HZ) < 0) {
foo = -1;
shost_printk(KERN_ERR, instance, "PDMA read: !REQ timeout\n");
}
d[c - 1] = NCR5380_read(INPUT_DATA_REG);
}
} else {
foo = NCR5380_pwrite(instance, d, c);
if (!foo && !(hostdata->flags & FLAG_NO_DMA_FIXUP)) {
if (NCR5380_poll_politely2(instance,
BUS_AND_STATUS_REG, BASR_DRQ, BASR_DRQ,
BUS_AND_STATUS_REG, BASR_PHASE_MATCH, 0, HZ) < 0) {
foo = -1;
shost_printk(KERN_ERR, instance, "PDMA write: DRQ and phase timeout\n");
}
}
}
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
NCR5380_read(RESET_PARITY_INTERRUPT_REG);
*data = d + c;
*count = 0;
*phase = NCR5380_read(STATUS_REG) & PHASE_MASK;
return foo;
#endif
}
static void NCR5380_information_transfer(struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
unsigned char msgout = NOP;
int sink = 0;
int len;
int transfersize;
unsigned char *data;
unsigned char phase, tmp, extended_msg[10], old_phase = 0xff;
struct scsi_cmnd *cmd;
while ((cmd = hostdata->connected)) {
struct NCR5380_cmd *ncmd = scsi_cmd_priv(cmd);
tmp = NCR5380_read(STATUS_REG);
if (tmp & SR_REQ) {
phase = (tmp & PHASE_MASK);
if (phase != old_phase) {
old_phase = phase;
NCR5380_dprint_phase(NDEBUG_INFORMATION, instance);
}
if (sink && (phase != PHASE_MSGOUT)) {
NCR5380_write(TARGET_COMMAND_REG, PHASE_SR_TO_TCR(tmp));
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN |
ICR_ASSERT_ACK);
while (NCR5380_read(STATUS_REG) & SR_REQ)
;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE |
ICR_ASSERT_ATN);
sink = 0;
continue;
}
switch (phase) {
case PHASE_DATAOUT:
#if (NDEBUG & NDEBUG_NO_DATAOUT)
shost_printk(KERN_DEBUG, instance, "NDEBUG_NO_DATAOUT set, attempted DATAOUT aborted\n");
sink = 1;
do_abort(instance);
cmd->result = DID_ERROR << 16;
complete_cmd(instance, cmd);
hostdata->connected = NULL;
return;
#endif
case PHASE_DATAIN:
if (!cmd->SCp.this_residual && cmd->SCp.buffers_residual) {
++cmd->SCp.buffer;
--cmd->SCp.buffers_residual;
cmd->SCp.this_residual = cmd->SCp.buffer->length;
cmd->SCp.ptr = sg_virt(cmd->SCp.buffer);
dsprintk(NDEBUG_INFORMATION, instance, "%d bytes and %d buffers left\n",
cmd->SCp.this_residual,
cmd->SCp.buffers_residual);
}
#if defined(PSEUDO_DMA) || defined(REAL_DMA_POLL)
transfersize = 0;
if (!cmd->device->borken &&
!(hostdata->flags & FLAG_NO_PSEUDO_DMA))
transfersize = NCR5380_dma_xfer_len(instance, cmd, phase);
if (transfersize) {
len = transfersize;
if (NCR5380_transfer_dma(instance, &phase,
&len, (unsigned char **)&cmd->SCp.ptr)) {
scmd_printk(KERN_INFO, cmd,
"switching to slow handshake\n");
cmd->device->borken = 1;
sink = 1;
do_abort(instance);
cmd->result = DID_ERROR << 16;
} else
cmd->SCp.this_residual -= transfersize - len;
} else
#endif
{
transfersize = min((unsigned long)cmd->SCp.this_residual,
hostdata->accesses_per_ms / 2);
len = transfersize;
NCR5380_transfer_pio(instance, &phase, &len,
(unsigned char **)&cmd->SCp.ptr);
cmd->SCp.this_residual -= transfersize - len;
}
return;
case PHASE_MSGIN:
len = 1;
data = &tmp;
NCR5380_transfer_pio(instance, &phase, &len, &data);
cmd->SCp.Message = tmp;
switch (tmp) {
case ABORT:
case COMMAND_COMPLETE:
sink = 1;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
dsprintk(NDEBUG_QUEUES, instance,
"COMMAND COMPLETE %p target %d lun %llu\n",
cmd, scmd_id(cmd), cmd->device->lun);
hostdata->connected = NULL;
cmd->result &= ~0xffff;
cmd->result |= cmd->SCp.Status;
cmd->result |= cmd->SCp.Message << 8;
if (cmd->cmnd[0] == REQUEST_SENSE)
complete_cmd(instance, cmd);
else {
if (cmd->SCp.Status == SAM_STAT_CHECK_CONDITION ||
cmd->SCp.Status == SAM_STAT_COMMAND_TERMINATED) {
dsprintk(NDEBUG_QUEUES, instance, "autosense: adding cmd %p to tail of autosense queue\n",
cmd);
list_add_tail(&ncmd->list,
&hostdata->autosense);
} else
complete_cmd(instance, cmd);
}
NCR5380_write(TARGET_COMMAND_REG, 0);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
return;
case MESSAGE_REJECT:
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
switch (hostdata->last_message) {
case HEAD_OF_QUEUE_TAG:
case ORDERED_QUEUE_TAG:
case SIMPLE_QUEUE_TAG:
cmd->device->simple_tags = 0;
hostdata->busy[cmd->device->id] |= (1 << (cmd->device->lun & 0xFF));
break;
default:
break;
}
break;
case DISCONNECT:
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
hostdata->connected = NULL;
list_add(&ncmd->list, &hostdata->disconnected);
dsprintk(NDEBUG_INFORMATION | NDEBUG_QUEUES,
instance, "connected command %p for target %d lun %llu moved to disconnected queue\n",
cmd, scmd_id(cmd), cmd->device->lun);
NCR5380_write(TARGET_COMMAND_REG, 0);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
return;
case SAVE_POINTERS:
case RESTORE_POINTERS:
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
break;
case EXTENDED_MESSAGE:
extended_msg[0] = EXTENDED_MESSAGE;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
spin_unlock_irq(&hostdata->lock);
dsprintk(NDEBUG_EXTENDED, instance, "receiving extended message\n");
len = 2;
data = extended_msg + 1;
phase = PHASE_MSGIN;
NCR5380_transfer_pio(instance, &phase, &len, &data);
dsprintk(NDEBUG_EXTENDED, instance, "length %d, code 0x%02x\n",
(int)extended_msg[1],
(int)extended_msg[2]);
if (!len && extended_msg[1] > 0 &&
extended_msg[1] <= sizeof(extended_msg) - 2) {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
len = extended_msg[1] - 1;
data = extended_msg + 3;
phase = PHASE_MSGIN;
NCR5380_transfer_pio(instance, &phase, &len, &data);
dsprintk(NDEBUG_EXTENDED, instance, "message received, residual %d\n",
len);
switch (extended_msg[2]) {
case EXTENDED_SDTR:
case EXTENDED_WDTR:
case EXTENDED_MODIFY_DATA_POINTER:
case EXTENDED_EXTENDED_IDENTIFY:
tmp = 0;
}
} else if (len) {
shost_printk(KERN_ERR, instance, "error receiving extended message\n");
tmp = 0;
} else {
shost_printk(KERN_NOTICE, instance, "extended message code %02x length %d is too long\n",
extended_msg[2], extended_msg[1]);
tmp = 0;
}
spin_lock_irq(&hostdata->lock);
if (!hostdata->connected)
return;
default:
if (!tmp) {
shost_printk(KERN_ERR, instance, "rejecting message ");
spi_print_msg(extended_msg);
printk("\n");
} else if (tmp != EXTENDED_MESSAGE)
scmd_printk(KERN_INFO, cmd,
"rejecting unknown message %02x\n",
tmp);
else
scmd_printk(KERN_INFO, cmd,
"rejecting unknown extended message code %02x, length %d\n",
extended_msg[1], extended_msg[0]);
msgout = MESSAGE_REJECT;
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_ATN);
break;
}
break;
case PHASE_MSGOUT:
len = 1;
data = &msgout;
hostdata->last_message = msgout;
NCR5380_transfer_pio(instance, &phase, &len, &data);
if (msgout == ABORT) {
hostdata->connected = NULL;
cmd->result = DID_ERROR << 16;
complete_cmd(instance, cmd);
NCR5380_write(SELECT_ENABLE_REG, hostdata->id_mask);
return;
}
msgout = NOP;
break;
case PHASE_CMDOUT:
len = cmd->cmd_len;
data = cmd->cmnd;
NCR5380_transfer_pio(instance, &phase, &len, &data);
break;
case PHASE_STATIN:
len = 1;
data = &tmp;
NCR5380_transfer_pio(instance, &phase, &len, &data);
cmd->SCp.Status = tmp;
break;
default:
shost_printk(KERN_ERR, instance, "unknown phase\n");
NCR5380_dprint(NDEBUG_ANY, instance);
}
} else {
spin_unlock_irq(&hostdata->lock);
NCR5380_poll_politely(instance, STATUS_REG, SR_REQ, SR_REQ, HZ);
spin_lock_irq(&hostdata->lock);
}
}
}
static void NCR5380_reselect(struct Scsi_Host *instance)
{
struct NCR5380_hostdata *hostdata = shost_priv(instance);
unsigned char target_mask;
unsigned char lun, phase;
int len;
unsigned char msg[3];
unsigned char *data;
struct NCR5380_cmd *ncmd;
struct scsi_cmnd *tmp;
NCR5380_write(MODE_REG, MR_BASE);
target_mask = NCR5380_read(CURRENT_SCSI_DATA_REG) & ~(hostdata->id_mask);
dsprintk(NDEBUG_RESELECTION, instance, "reselect\n");
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE | ICR_ASSERT_BSY);
if (NCR5380_poll_politely(instance,
STATUS_REG, SR_SEL, 0, 2 * HZ) < 0) {
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
return;
}
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
if (NCR5380_poll_politely(instance,
STATUS_REG, SR_REQ, SR_REQ, 2 * HZ) < 0) {
do_abort(instance);
return;
}
len = 1;
data = msg;
phase = PHASE_MSGIN;
NCR5380_transfer_pio(instance, &phase, &len, &data);
if (len) {
do_abort(instance);
return;
}
if (!(msg[0] & 0x80)) {
shost_printk(KERN_ERR, instance, "expecting IDENTIFY message, got ");
spi_print_msg(msg);
printk("\n");
do_abort(instance);
return;
}
lun = msg[0] & 0x07;
tmp = NULL;
list_for_each_entry(ncmd, &hostdata->disconnected, list) {
struct scsi_cmnd *cmd = NCR5380_to_scmd(ncmd);
if (target_mask == (1 << scmd_id(cmd)) &&
lun == (u8)cmd->device->lun) {
list_del(&ncmd->list);
tmp = cmd;
break;
}
}
if (tmp) {
dsprintk(NDEBUG_RESELECTION | NDEBUG_QUEUES, instance,
"reselect: removed %p from disconnected queue\n", tmp);
} else {
shost_printk(KERN_ERR, instance, "target bitmask 0x%02x lun %d not in disconnected queue.\n",
target_mask, lun);
do_abort(instance);
return;
}
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
hostdata->connected = tmp;
dsprintk(NDEBUG_RESELECTION, instance, "nexus established, target %d, lun %llu, tag %d\n",
scmd_id(tmp), tmp->device->lun, tmp->tag);
}
static void NCR5380_dma_complete(NCR5380_instance * instance) {
struct NCR5380_hostdata *hostdata = shost_priv(instance);
int transferred;
NCR5380_poll_politely(instance, BUS_AND_STATUS_REG, BASR_ACK, 0, 5*HZ);
NCR5380_write(INITIATOR_COMMAND_REG, ICR_BASE);
if (!(hostdata->connected->SCp.phase & SR_CD)) {
transferred = instance->dmalen - NCR5380_dma_residual();
hostdata->connected->SCp.this_residual -= transferred;
hostdata->connected->SCp.ptr += transferred;
}
}
static bool list_find_cmd(struct list_head *haystack,
struct scsi_cmnd *needle)
{
struct NCR5380_cmd *ncmd;
list_for_each_entry(ncmd, haystack, list)
if (NCR5380_to_scmd(ncmd) == needle)
return true;
return false;
}
static bool list_del_cmd(struct list_head *haystack,
struct scsi_cmnd *needle)
{
if (list_find_cmd(haystack, needle)) {
struct NCR5380_cmd *ncmd = scsi_cmd_priv(needle);
list_del(&ncmd->list);
return true;
}
return false;
}
static int NCR5380_abort(struct scsi_cmnd *cmd)
{
struct Scsi_Host *instance = cmd->device->host;
struct NCR5380_hostdata *hostdata = shost_priv(instance);
unsigned long flags;
int result = SUCCESS;
spin_lock_irqsave(&hostdata->lock, flags);
#if (NDEBUG & NDEBUG_ANY)
scmd_printk(KERN_INFO, cmd, __func__);
#endif
NCR5380_dprint(NDEBUG_ANY, instance);
NCR5380_dprint_phase(NDEBUG_ANY, instance);
if (list_del_cmd(&hostdata->unissued, cmd)) {
dsprintk(NDEBUG_ABORT, instance,
"abort: removed %p from issue queue\n", cmd);
cmd->result = DID_ABORT << 16;
cmd->scsi_done(cmd);
goto out;
}
if (hostdata->selecting == cmd) {
dsprintk(NDEBUG_ABORT, instance,
"abort: cmd %p == selecting\n", cmd);
hostdata->selecting = NULL;
cmd->result = DID_ABORT << 16;
complete_cmd(instance, cmd);
goto out;
}
if (list_del_cmd(&hostdata->disconnected, cmd)) {
dsprintk(NDEBUG_ABORT, instance,
"abort: removed %p from disconnected list\n", cmd);
set_host_byte(cmd, DID_ERROR);
complete_cmd(instance, cmd);
result = FAILED;
goto out;
}
if (hostdata->connected == cmd) {
dsprintk(NDEBUG_ABORT, instance, "abort: cmd %p is connected\n", cmd);
hostdata->connected = NULL;
#ifdef REAL_DMA
hostdata->dma_len = 0;
#endif
if (do_abort(instance)) {
set_host_byte(cmd, DID_ERROR);
complete_cmd(instance, cmd);
result = FAILED;
goto out;
}
set_host_byte(cmd, DID_ABORT);
complete_cmd(instance, cmd);
goto out;
}
if (list_del_cmd(&hostdata->autosense, cmd)) {
dsprintk(NDEBUG_ABORT, instance,
"abort: removed %p from sense queue\n", cmd);
set_host_byte(cmd, DID_ERROR);
complete_cmd(instance, cmd);
}
out:
if (result == FAILED)
dsprintk(NDEBUG_ABORT, instance, "abort: failed to abort %p\n", cmd);
else
dsprintk(NDEBUG_ABORT, instance, "abort: successfully aborted %p\n", cmd);
queue_work(hostdata->work_q, &hostdata->main_task);
spin_unlock_irqrestore(&hostdata->lock, flags);
return result;
}
static int NCR5380_bus_reset(struct scsi_cmnd *cmd)
{
struct Scsi_Host *instance = cmd->device->host;
struct NCR5380_hostdata *hostdata = shost_priv(instance);
int i;
unsigned long flags;
struct NCR5380_cmd *ncmd;
spin_lock_irqsave(&hostdata->lock, flags);
#if (NDEBUG & NDEBUG_ANY)
scmd_printk(KERN_INFO, cmd, __func__);
#endif
NCR5380_dprint(NDEBUG_ANY, instance);
NCR5380_dprint_phase(NDEBUG_ANY, instance);
do_reset(instance);
NCR5380_write(MODE_REG, MR_BASE);
NCR5380_write(TARGET_COMMAND_REG, 0);
NCR5380_write(SELECT_ENABLE_REG, 0);
if (list_del_cmd(&hostdata->unissued, cmd)) {
cmd->result = DID_RESET << 16;
cmd->scsi_done(cmd);
}
if (hostdata->selecting) {
hostdata->selecting->result = DID_RESET << 16;
complete_cmd(instance, hostdata->selecting);
hostdata->selecting = NULL;
}
list_for_each_entry(ncmd, &hostdata->disconnected, list) {
struct scsi_cmnd *cmd = NCR5380_to_scmd(ncmd);
set_host_byte(cmd, DID_RESET);
cmd->scsi_done(cmd);
}
INIT_LIST_HEAD(&hostdata->disconnected);
list_for_each_entry(ncmd, &hostdata->autosense, list) {
struct scsi_cmnd *cmd = NCR5380_to_scmd(ncmd);
set_host_byte(cmd, DID_RESET);
cmd->scsi_done(cmd);
}
INIT_LIST_HEAD(&hostdata->autosense);
if (hostdata->connected) {
set_host_byte(hostdata->connected, DID_RESET);
complete_cmd(instance, hostdata->connected);
hostdata->connected = NULL;
}
for (i = 0; i < 8; ++i)
hostdata->busy[i] = 0;
#ifdef REAL_DMA
hostdata->dma_len = 0;
#endif
queue_work(hostdata->work_q, &hostdata->main_task);
spin_unlock_irqrestore(&hostdata->lock, flags);
return SUCCESS;
}
