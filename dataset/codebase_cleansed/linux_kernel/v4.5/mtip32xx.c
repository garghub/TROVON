static bool mtip_check_surprise_removal(struct pci_dev *pdev)
{
u16 vendor_id = 0;
struct driver_data *dd = pci_get_drvdata(pdev);
if (dd->sr)
return true;
pci_read_config_word(pdev, 0x00, &vendor_id);
if (vendor_id == 0xFFFF) {
dd->sr = true;
if (dd->queue)
set_bit(QUEUE_FLAG_DEAD, &dd->queue->queue_flags);
else
dev_warn(&dd->pdev->dev,
"%s: dd->queue is NULL\n", __func__);
return true;
}
return false;
}
static struct mtip_cmd *mtip_get_int_command(struct driver_data *dd)
{
struct request *rq;
rq = blk_mq_alloc_request(dd->queue, 0, BLK_MQ_REQ_RESERVED);
return blk_mq_rq_to_pdu(rq);
}
static void mtip_put_int_command(struct driver_data *dd, struct mtip_cmd *cmd)
{
blk_put_request(blk_mq_rq_from_pdu(cmd));
}
static struct request *mtip_rq_from_tag(struct driver_data *dd,
unsigned int tag)
{
struct blk_mq_hw_ctx *hctx = dd->queue->queue_hw_ctx[0];
return blk_mq_tag_to_rq(hctx->tags, tag);
}
static struct mtip_cmd *mtip_cmd_from_tag(struct driver_data *dd,
unsigned int tag)
{
struct request *rq = mtip_rq_from_tag(dd, tag);
return blk_mq_rq_to_pdu(rq);
}
static void mtip_async_complete(struct mtip_port *port,
int tag, struct mtip_cmd *cmd, int status)
{
struct driver_data *dd = port->dd;
struct request *rq;
if (unlikely(!dd) || unlikely(!port))
return;
if (unlikely(status == PORT_IRQ_TF_ERR)) {
dev_warn(&port->dd->pdev->dev,
"Command tag %d failed due to TFE\n", tag);
}
dma_unmap_sg(&dd->pdev->dev, cmd->sg, cmd->scatter_ents, cmd->direction);
rq = mtip_rq_from_tag(dd, tag);
if (unlikely(cmd->unaligned))
up(&port->cmd_slot_unal);
blk_mq_end_request(rq, status ? -EIO : 0);
}
static int mtip_hba_reset(struct driver_data *dd)
{
unsigned long timeout;
writel(HOST_RESET, dd->mmio + HOST_CTL);
readl(dd->mmio + HOST_CTL);
timeout = jiffies + msecs_to_jiffies(10000);
do {
mdelay(10);
if (test_bit(MTIP_DDF_REMOVE_PENDING_BIT, &dd->dd_flag))
return -1;
} while ((readl(dd->mmio + HOST_CTL) & HOST_RESET)
&& time_before(jiffies, timeout));
if (readl(dd->mmio + HOST_CTL) & HOST_RESET)
return -1;
return 0;
}
static inline void mtip_issue_ncq_command(struct mtip_port *port, int tag)
{
int group = tag >> 5;
spin_lock(&port->cmd_issue_lock[group]);
writel((1 << MTIP_TAG_BIT(tag)),
port->s_active[MTIP_TAG_INDEX(tag)]);
writel((1 << MTIP_TAG_BIT(tag)),
port->cmd_issue[MTIP_TAG_INDEX(tag)]);
spin_unlock(&port->cmd_issue_lock[group]);
}
static int mtip_enable_fis(struct mtip_port *port, int enable)
{
u32 tmp;
tmp = readl(port->mmio + PORT_CMD);
if (enable)
writel(tmp | PORT_CMD_FIS_RX, port->mmio + PORT_CMD);
else
writel(tmp & ~PORT_CMD_FIS_RX, port->mmio + PORT_CMD);
readl(port->mmio + PORT_CMD);
return (((tmp & PORT_CMD_FIS_RX) == PORT_CMD_FIS_RX));
}
static int mtip_enable_engine(struct mtip_port *port, int enable)
{
u32 tmp;
tmp = readl(port->mmio + PORT_CMD);
if (enable)
writel(tmp | PORT_CMD_START, port->mmio + PORT_CMD);
else
writel(tmp & ~PORT_CMD_START, port->mmio + PORT_CMD);
readl(port->mmio + PORT_CMD);
return (((tmp & PORT_CMD_START) == PORT_CMD_START));
}
static inline void mtip_start_port(struct mtip_port *port)
{
mtip_enable_fis(port, 1);
mtip_enable_engine(port, 1);
}
static inline void mtip_deinit_port(struct mtip_port *port)
{
writel(0, port->mmio + PORT_IRQ_MASK);
mtip_enable_engine(port, 0);
mtip_enable_fis(port, 0);
}
static void mtip_init_port(struct mtip_port *port)
{
int i;
mtip_deinit_port(port);
if (readl(port->dd->mmio + HOST_CAP) & HOST_CAP_64) {
writel((port->command_list_dma >> 16) >> 16,
port->mmio + PORT_LST_ADDR_HI);
writel((port->rxfis_dma >> 16) >> 16,
port->mmio + PORT_FIS_ADDR_HI);
}
writel(port->command_list_dma & 0xFFFFFFFF,
port->mmio + PORT_LST_ADDR);
writel(port->rxfis_dma & 0xFFFFFFFF, port->mmio + PORT_FIS_ADDR);
writel(readl(port->mmio + PORT_SCR_ERR), port->mmio + PORT_SCR_ERR);
for (i = 0; i < port->dd->slot_groups; i++)
writel(0xFFFFFFFF, port->completed[i]);
writel(readl(port->mmio + PORT_IRQ_STAT), port->mmio + PORT_IRQ_STAT);
writel(readl(port->dd->mmio + HOST_IRQ_STAT),
port->dd->mmio + HOST_IRQ_STAT);
writel(DEF_PORT_IRQ, port->mmio + PORT_IRQ_MASK);
}
static void mtip_restart_port(struct mtip_port *port)
{
unsigned long timeout;
mtip_enable_engine(port, 0);
timeout = jiffies + msecs_to_jiffies(500);
while ((readl(port->mmio + PORT_CMD) & PORT_CMD_LIST_ON)
&& time_before(jiffies, timeout))
;
if (test_bit(MTIP_DDF_REMOVE_PENDING_BIT, &port->dd->dd_flag))
return;
if (readl(port->mmio + PORT_CMD) & PORT_CMD_LIST_ON) {
dev_warn(&port->dd->pdev->dev,
"PxCMD.CR not clear, escalating reset\n");
if (mtip_hba_reset(port->dd))
dev_err(&port->dd->pdev->dev,
"HBA reset escalation failed.\n");
mdelay(30);
}
dev_warn(&port->dd->pdev->dev, "Issuing COM reset\n");
writel(readl(port->mmio + PORT_SCR_CTL) |
1, port->mmio + PORT_SCR_CTL);
readl(port->mmio + PORT_SCR_CTL);
timeout = jiffies + msecs_to_jiffies(1);
while (time_before(jiffies, timeout))
;
if (test_bit(MTIP_DDF_REMOVE_PENDING_BIT, &port->dd->dd_flag))
return;
writel(readl(port->mmio + PORT_SCR_CTL) & ~1,
port->mmio + PORT_SCR_CTL);
readl(port->mmio + PORT_SCR_CTL);
timeout = jiffies + msecs_to_jiffies(500);
while (((readl(port->mmio + PORT_SCR_STAT) & 0x01) == 0)
&& time_before(jiffies, timeout))
;
if (test_bit(MTIP_DDF_REMOVE_PENDING_BIT, &port->dd->dd_flag))
return;
if ((readl(port->mmio + PORT_SCR_STAT) & 0x01) == 0)
dev_warn(&port->dd->pdev->dev,
"COM reset failed\n");
mtip_init_port(port);
mtip_start_port(port);
}
static int mtip_device_reset(struct driver_data *dd)
{
int rv = 0;
if (mtip_check_surprise_removal(dd->pdev))
return 0;
if (mtip_hba_reset(dd) < 0)
rv = -EFAULT;
mdelay(1);
mtip_init_port(dd->port);
mtip_start_port(dd->port);
writel(readl(dd->mmio + HOST_CTL) | HOST_IRQ_EN,
dd->mmio + HOST_CTL);
return rv;
}
static void print_tags(struct driver_data *dd,
char *msg,
unsigned long *tagbits,
int cnt)
{
unsigned char tagmap[128];
int group, tagmap_len = 0;
memset(tagmap, 0, sizeof(tagmap));
for (group = SLOTBITS_IN_LONGS; group > 0; group--)
tagmap_len += sprintf(tagmap + tagmap_len, "%016lX ",
tagbits[group-1]);
dev_warn(&dd->pdev->dev,
"%d command(s) %s: tagmap [%s]", cnt, msg, tagmap);
}
static void mtip_completion(struct mtip_port *port,
int tag, struct mtip_cmd *command, int status)
{
struct completion *waiting = command->comp_data;
if (unlikely(status == PORT_IRQ_TF_ERR))
dev_warn(&port->dd->pdev->dev,
"Internal command %d completed with TFE\n", tag);
complete(waiting);
}
static void mtip_null_completion(struct mtip_port *port,
int tag, struct mtip_cmd *command, int status)
{
}
static void mtip_handle_tfe(struct driver_data *dd)
{
int group, tag, bit, reissue, rv;
struct mtip_port *port;
struct mtip_cmd *cmd;
u32 completed;
struct host_to_dev_fis *fis;
unsigned long tagaccum[SLOTBITS_IN_LONGS];
unsigned int cmd_cnt = 0;
unsigned char *buf;
char *fail_reason = NULL;
int fail_all_ncq_write = 0, fail_all_ncq_cmds = 0;
dev_warn(&dd->pdev->dev, "Taskfile error\n");
port = dd->port;
set_bit(MTIP_PF_EH_ACTIVE_BIT, &port->flags);
if (test_bit(MTIP_PF_IC_ACTIVE_BIT, &port->flags)) {
cmd = mtip_cmd_from_tag(dd, MTIP_TAG_INTERNAL);
dbg_printk(MTIP_DRV_NAME " TFE for the internal command\n");
if (cmd->comp_data && cmd->comp_func) {
cmd->comp_func(port, MTIP_TAG_INTERNAL,
cmd, PORT_IRQ_TF_ERR);
}
goto handle_tfe_exit;
}
memset(tagaccum, 0, SLOTBITS_IN_LONGS * sizeof(long));
for (group = 0; group < dd->slot_groups; group++) {
completed = readl(port->completed[group]);
dev_warn(&dd->pdev->dev, "g=%u, comp=%x\n", group, completed);
writel(completed, port->completed[group]);
for (bit = 0; bit < 32 && completed; bit++) {
if (!(completed & (1<<bit)))
continue;
tag = (group << 5) + bit;
if (tag == MTIP_TAG_INTERNAL)
continue;
cmd = mtip_cmd_from_tag(dd, tag);
if (likely(cmd->comp_func)) {
set_bit(tag, tagaccum);
cmd_cnt++;
cmd->comp_func(port, tag, cmd, 0);
} else {
dev_err(&port->dd->pdev->dev,
"Missing completion func for tag %d",
tag);
if (mtip_check_surprise_removal(dd->pdev)) {
return;
}
}
}
}
print_tags(dd, "completed (TFE)", tagaccum, cmd_cnt);
mdelay(20);
mtip_restart_port(port);
rv = mtip_read_log_page(dd->port, ATA_LOG_SATA_NCQ,
dd->port->log_buf,
dd->port->log_buf_dma, 1);
if (rv) {
dev_warn(&dd->pdev->dev,
"Error in READ LOG EXT (10h) command\n");
} else {
buf = (unsigned char *)dd->port->log_buf;
if (buf[259] & 0x1) {
dev_info(&dd->pdev->dev,
"Write protect bit is set.\n");
set_bit(MTIP_DDF_WRITE_PROTECT_BIT, &dd->dd_flag);
fail_all_ncq_write = 1;
fail_reason = "write protect";
}
if (buf[288] == 0xF7) {
dev_info(&dd->pdev->dev,
"Exceeded Tmax, drive in thermal shutdown.\n");
set_bit(MTIP_DDF_OVER_TEMP_BIT, &dd->dd_flag);
fail_all_ncq_cmds = 1;
fail_reason = "thermal shutdown";
}
if (buf[288] == 0xBF) {
set_bit(MTIP_DDF_SEC_LOCK_BIT, &dd->dd_flag);
dev_info(&dd->pdev->dev,
"Drive indicates rebuild has failed. Secure erase required.\n");
fail_all_ncq_cmds = 1;
fail_reason = "rebuild failed";
}
}
memset(tagaccum, 0, SLOTBITS_IN_LONGS * sizeof(long));
for (group = 0; group < dd->slot_groups; group++) {
for (bit = 0; bit < 32; bit++) {
reissue = 1;
tag = (group << 5) + bit;
cmd = mtip_cmd_from_tag(dd, tag);
fis = (struct host_to_dev_fis *)cmd->command;
if (tag == MTIP_TAG_INTERNAL ||
fis->command == ATA_CMD_SET_FEATURES)
reissue = 0;
else {
if (fail_all_ncq_cmds ||
(fail_all_ncq_write &&
fis->command == ATA_CMD_FPDMA_WRITE)) {
dev_warn(&dd->pdev->dev,
" Fail: %s w/tag %d [%s].\n",
fis->command == ATA_CMD_FPDMA_WRITE ?
"write" : "read",
tag,
fail_reason != NULL ?
fail_reason : "unknown");
if (cmd->comp_func) {
cmd->comp_func(port, tag,
cmd, -ENODATA);
}
continue;
}
}
if (reissue && (cmd->retries-- > 0)) {
set_bit(tag, tagaccum);
mtip_issue_ncq_command(port, tag);
continue;
}
dev_warn(&port->dd->pdev->dev,
"retiring tag %d\n", tag);
if (cmd->comp_func)
cmd->comp_func(port, tag, cmd, PORT_IRQ_TF_ERR);
else
dev_warn(&port->dd->pdev->dev,
"Bad completion for tag %d\n",
tag);
}
}
print_tags(dd, "reissued (TFE)", tagaccum, cmd_cnt);
handle_tfe_exit:
clear_bit(MTIP_PF_EH_ACTIVE_BIT, &port->flags);
wake_up_interruptible(&port->svc_wait);
}
static inline void mtip_workq_sdbfx(struct mtip_port *port, int group,
u32 completed)
{
struct driver_data *dd = port->dd;
int tag, bit;
struct mtip_cmd *command;
if (!completed) {
WARN_ON_ONCE(!completed);
return;
}
writel(completed, port->completed[group]);
for (bit = 0; (bit < 32) && completed; bit++) {
if (completed & 0x01) {
tag = (group << 5) | bit;
if (unlikely(tag == MTIP_TAG_INTERNAL))
continue;
command = mtip_cmd_from_tag(dd, tag);
if (likely(command->comp_func))
command->comp_func(port, tag, command, 0);
else {
dev_dbg(&dd->pdev->dev,
"Null completion for tag %d",
tag);
if (mtip_check_surprise_removal(
dd->pdev)) {
return;
}
}
}
completed >>= 1;
}
if (atomic_dec_return(&dd->irq_workers_active) == 0)
writel(0xffffffff, dd->mmio + HOST_IRQ_STAT);
}
static inline void mtip_process_legacy(struct driver_data *dd, u32 port_stat)
{
struct mtip_port *port = dd->port;
struct mtip_cmd *cmd = mtip_cmd_from_tag(dd, MTIP_TAG_INTERNAL);
if (test_bit(MTIP_PF_IC_ACTIVE_BIT, &port->flags) &&
(cmd != NULL) && !(readl(port->cmd_issue[MTIP_TAG_INTERNAL])
& (1 << MTIP_TAG_INTERNAL))) {
if (cmd->comp_func) {
cmd->comp_func(port, MTIP_TAG_INTERNAL, cmd, 0);
return;
}
}
return;
}
static inline void mtip_process_errors(struct driver_data *dd, u32 port_stat)
{
if (unlikely(port_stat & PORT_IRQ_CONNECT)) {
dev_warn(&dd->pdev->dev,
"Clearing PxSERR.DIAG.x\n");
writel((1 << 26), dd->port->mmio + PORT_SCR_ERR);
}
if (unlikely(port_stat & PORT_IRQ_PHYRDY)) {
dev_warn(&dd->pdev->dev,
"Clearing PxSERR.DIAG.n\n");
writel((1 << 16), dd->port->mmio + PORT_SCR_ERR);
}
if (unlikely(port_stat & ~PORT_IRQ_HANDLED)) {
dev_warn(&dd->pdev->dev,
"Port stat errors %x unhandled\n",
(port_stat & ~PORT_IRQ_HANDLED));
if (mtip_check_surprise_removal(dd->pdev))
return;
}
if (likely(port_stat & (PORT_IRQ_TF_ERR | PORT_IRQ_IF_ERR))) {
set_bit(MTIP_PF_EH_ACTIVE_BIT, &dd->port->flags);
wake_up_interruptible(&dd->port->svc_wait);
}
}
static inline irqreturn_t mtip_handle_irq(struct driver_data *data)
{
struct driver_data *dd = (struct driver_data *) data;
struct mtip_port *port = dd->port;
u32 hba_stat, port_stat;
int rv = IRQ_NONE;
int do_irq_enable = 1, i, workers;
struct mtip_work *twork;
hba_stat = readl(dd->mmio + HOST_IRQ_STAT);
if (hba_stat) {
rv = IRQ_HANDLED;
port_stat = readl(port->mmio + PORT_IRQ_STAT);
if (unlikely(port_stat == 0xFFFFFFFF)) {
mtip_check_surprise_removal(dd->pdev);
return IRQ_HANDLED;
}
writel(port_stat, port->mmio + PORT_IRQ_STAT);
if (likely(port_stat & PORT_IRQ_SDB_FIS)) {
do_irq_enable = 0;
WARN_ON_ONCE(atomic_read(&dd->irq_workers_active) != 0);
for (i = 0, workers = 0; i < MTIP_MAX_SLOT_GROUPS;
i++) {
twork = &dd->work[i];
twork->completed = readl(port->completed[i]);
if (twork->completed)
workers++;
}
atomic_set(&dd->irq_workers_active, workers);
if (workers) {
for (i = 1; i < MTIP_MAX_SLOT_GROUPS; i++) {
twork = &dd->work[i];
if (twork->completed)
queue_work_on(
twork->cpu_binding,
dd->isr_workq,
&twork->work);
}
if (likely(dd->work[0].completed))
mtip_workq_sdbfx(port, 0,
dd->work[0].completed);
} else {
do_irq_enable = 1;
}
}
if (unlikely(port_stat & PORT_IRQ_ERR)) {
if (unlikely(mtip_check_surprise_removal(dd->pdev))) {
return IRQ_HANDLED;
}
if (test_bit(MTIP_DDF_REMOVE_PENDING_BIT,
&dd->dd_flag))
return rv;
mtip_process_errors(dd, port_stat & PORT_IRQ_ERR);
}
if (unlikely(port_stat & PORT_IRQ_LEGACY))
mtip_process_legacy(dd, port_stat & PORT_IRQ_LEGACY);
}
if (unlikely(do_irq_enable))
writel(hba_stat, dd->mmio + HOST_IRQ_STAT);
return rv;
}
static irqreturn_t mtip_irq_handler(int irq, void *instance)
{
struct driver_data *dd = instance;
return mtip_handle_irq(dd);
}
static void mtip_issue_non_ncq_command(struct mtip_port *port, int tag)
{
writel(1 << MTIP_TAG_BIT(tag),
port->cmd_issue[MTIP_TAG_INDEX(tag)]);
}
static bool mtip_pause_ncq(struct mtip_port *port,
struct host_to_dev_fis *fis)
{
struct host_to_dev_fis *reply;
unsigned long task_file_data;
reply = port->rxfis + RX_FIS_D2H_REG;
task_file_data = readl(port->mmio+PORT_TFDATA);
if ((task_file_data & 1))
return false;
if (fis->command == ATA_CMD_SEC_ERASE_PREP) {
port->ic_pause_timer = jiffies;
return true;
} else if ((fis->command == ATA_CMD_DOWNLOAD_MICRO) &&
(fis->features == 0x03)) {
set_bit(MTIP_PF_DM_ACTIVE_BIT, &port->flags);
port->ic_pause_timer = jiffies;
return true;
} else if ((fis->command == ATA_CMD_SEC_ERASE_UNIT) ||
((fis->command == 0xFC) &&
(fis->features == 0x27 || fis->features == 0x72 ||
fis->features == 0x62 || fis->features == 0x26))) {
clear_bit(MTIP_DDF_SEC_LOCK_BIT, &port->dd->dd_flag);
mtip_restart_port(port);
clear_bit(MTIP_PF_SE_ACTIVE_BIT, &port->flags);
return false;
}
return false;
}
static int mtip_quiesce_io(struct mtip_port *port, unsigned long timeout)
{
unsigned long to;
unsigned int n;
unsigned int active = 1;
blk_mq_stop_hw_queues(port->dd->queue);
to = jiffies + msecs_to_jiffies(timeout);
do {
if (test_bit(MTIP_PF_SVC_THD_ACTIVE_BIT, &port->flags) &&
test_bit(MTIP_PF_ISSUE_CMDS_BIT, &port->flags)) {
msleep(20);
continue;
}
msleep(100);
if (mtip_check_surprise_removal(port->dd->pdev))
goto err_fault;
if (test_bit(MTIP_DDF_REMOVE_PENDING_BIT, &port->dd->dd_flag))
goto err_fault;
active = readl(port->s_active[0]) & 0xFFFFFFFE;
for (n = 1; n < port->dd->slot_groups; n++)
active |= readl(port->s_active[n]);
if (!active)
break;
} while (time_before(jiffies, to));
blk_mq_start_stopped_hw_queues(port->dd->queue, true);
return active ? -EBUSY : 0;
err_fault:
blk_mq_start_stopped_hw_queues(port->dd->queue, true);
return -EFAULT;
}
static int mtip_exec_internal_command(struct mtip_port *port,
struct host_to_dev_fis *fis,
int fis_len,
dma_addr_t buffer,
int buf_len,
u32 opts,
gfp_t atomic,
unsigned long timeout)
{
struct mtip_cmd_sg *command_sg;
DECLARE_COMPLETION_ONSTACK(wait);
struct mtip_cmd *int_cmd;
struct driver_data *dd = port->dd;
int rv = 0;
if (buffer & 0x00000007) {
dev_err(&dd->pdev->dev, "SG buffer is not 8 byte aligned\n");
return -EFAULT;
}
int_cmd = mtip_get_int_command(dd);
set_bit(MTIP_PF_IC_ACTIVE_BIT, &port->flags);
if (fis->command == ATA_CMD_SEC_ERASE_PREP)
set_bit(MTIP_PF_SE_ACTIVE_BIT, &port->flags);
clear_bit(MTIP_PF_DM_ACTIVE_BIT, &port->flags);
if (atomic == GFP_KERNEL) {
if (fis->command != ATA_CMD_STANDBYNOW1) {
if (mtip_quiesce_io(port,
MTIP_QUIESCE_IO_TIMEOUT_MS) < 0) {
dev_warn(&dd->pdev->dev,
"Failed to quiesce IO\n");
mtip_put_int_command(dd, int_cmd);
clear_bit(MTIP_PF_IC_ACTIVE_BIT, &port->flags);
wake_up_interruptible(&port->svc_wait);
return -EBUSY;
}
}
int_cmd->comp_data = &wait;
int_cmd->comp_func = mtip_completion;
} else {
int_cmd->comp_data = NULL;
int_cmd->comp_func = mtip_null_completion;
}
memcpy(int_cmd->command, fis, fis_len*4);
int_cmd->command_header->opts =
__force_bit2int cpu_to_le32(opts | fis_len);
if (buf_len) {
command_sg = int_cmd->command + AHCI_CMD_TBL_HDR_SZ;
command_sg->info =
__force_bit2int cpu_to_le32((buf_len-1) & 0x3FFFFF);
command_sg->dba =
__force_bit2int cpu_to_le32(buffer & 0xFFFFFFFF);
command_sg->dba_upper =
__force_bit2int cpu_to_le32((buffer >> 16) >> 16);
int_cmd->command_header->opts |=
__force_bit2int cpu_to_le32((1 << 16));
}
int_cmd->command_header->byte_count = 0;
mtip_issue_non_ncq_command(port, MTIP_TAG_INTERNAL);
if (atomic == GFP_KERNEL) {
if ((rv = wait_for_completion_interruptible_timeout(
&wait,
msecs_to_jiffies(timeout))) <= 0) {
if (rv == -ERESTARTSYS) {
dev_err(&dd->pdev->dev,
"Internal command [%02X] was interrupted after %lu ms\n",
fis->command, timeout);
rv = -EINTR;
goto exec_ic_exit;
} else if (rv == 0)
dev_err(&dd->pdev->dev,
"Internal command did not complete [%02X] within timeout of %lu ms\n",
fis->command, timeout);
else
dev_err(&dd->pdev->dev,
"Internal command [%02X] wait returned code [%d] after %lu ms - unhandled\n",
fis->command, rv, timeout);
if (mtip_check_surprise_removal(dd->pdev) ||
test_bit(MTIP_DDF_REMOVE_PENDING_BIT,
&dd->dd_flag)) {
dev_err(&dd->pdev->dev,
"Internal command [%02X] wait returned due to SR\n",
fis->command);
rv = -ENXIO;
goto exec_ic_exit;
}
mtip_device_reset(dd);
rv = -EAGAIN;
goto exec_ic_exit;
}
} else {
u32 hba_stat, port_stat;
timeout = jiffies + msecs_to_jiffies(timeout);
while ((readl(port->cmd_issue[MTIP_TAG_INTERNAL])
& (1 << MTIP_TAG_INTERNAL))
&& time_before(jiffies, timeout)) {
if (mtip_check_surprise_removal(dd->pdev)) {
rv = -ENXIO;
goto exec_ic_exit;
}
if ((fis->command != ATA_CMD_STANDBYNOW1) &&
test_bit(MTIP_DDF_REMOVE_PENDING_BIT,
&dd->dd_flag)) {
rv = -ENXIO;
goto exec_ic_exit;
}
port_stat = readl(port->mmio + PORT_IRQ_STAT);
if (!port_stat)
continue;
if (port_stat & PORT_IRQ_ERR) {
dev_err(&dd->pdev->dev,
"Internal command [%02X] failed\n",
fis->command);
mtip_device_reset(dd);
rv = -EIO;
goto exec_ic_exit;
} else {
writel(port_stat, port->mmio + PORT_IRQ_STAT);
hba_stat = readl(dd->mmio + HOST_IRQ_STAT);
if (hba_stat)
writel(hba_stat,
dd->mmio + HOST_IRQ_STAT);
}
break;
}
}
if (readl(port->cmd_issue[MTIP_TAG_INTERNAL])
& (1 << MTIP_TAG_INTERNAL)) {
rv = -ENXIO;
if (!test_bit(MTIP_DDF_REMOVE_PENDING_BIT, &dd->dd_flag)) {
mtip_device_reset(dd);
rv = -EAGAIN;
}
}
exec_ic_exit:
mtip_put_int_command(dd, int_cmd);
clear_bit(MTIP_PF_IC_ACTIVE_BIT, &port->flags);
if (rv >= 0 && mtip_pause_ncq(port, fis)) {
return rv;
}
wake_up_interruptible(&port->svc_wait);
return rv;
}
static inline void ata_swap_string(u16 *buf, unsigned int len)
{
int i;
for (i = 0; i < (len/2); i++)
be16_to_cpus(&buf[i]);
}
static void mtip_set_timeout(struct driver_data *dd,
struct host_to_dev_fis *fis,
unsigned int *timeout, u8 erasemode)
{
switch (fis->command) {
case ATA_CMD_DOWNLOAD_MICRO:
*timeout = 120000;
break;
case ATA_CMD_SEC_ERASE_UNIT:
case 0xFC:
if (erasemode)
*timeout = ((*(dd->port->identify + 90) * 2) * 60000);
else
*timeout = ((*(dd->port->identify + 89) * 2) * 60000);
break;
case ATA_CMD_STANDBYNOW1:
*timeout = 120000;
break;
case 0xF7:
case 0xFA:
*timeout = 60000;
break;
case ATA_CMD_SMART:
*timeout = 15000;
break;
default:
*timeout = MTIP_IOCTL_CMD_TIMEOUT_MS;
break;
}
}
static int mtip_get_identify(struct mtip_port *port, void __user *user_buffer)
{
int rv = 0;
struct host_to_dev_fis fis;
if (test_bit(MTIP_DDF_REMOVE_PENDING_BIT, &port->dd->dd_flag))
return -EFAULT;
memset(&fis, 0, sizeof(struct host_to_dev_fis));
fis.type = 0x27;
fis.opts = 1 << 7;
fis.command = ATA_CMD_ID_ATA;
port->identify_valid = 0;
memset(port->identify, 0, sizeof(u16) * ATA_ID_WORDS);
if (mtip_exec_internal_command(port,
&fis,
5,
port->identify_dma,
sizeof(u16) * ATA_ID_WORDS,
0,
GFP_KERNEL,
MTIP_INT_CMD_TIMEOUT_MS)
< 0) {
rv = -1;
goto out;
}
#ifdef __LITTLE_ENDIAN
ata_swap_string(port->identify + 27, 40);
ata_swap_string(port->identify + 23, 8);
ata_swap_string(port->identify + 10, 20);
#else
{
int i;
for (i = 0; i < ATA_ID_WORDS; i++)
port->identify[i] = le16_to_cpu(port->identify[i]);
}
#endif
if (port->identify[128] & 0x4)
set_bit(MTIP_DDF_SEC_LOCK_BIT, &port->dd->dd_flag);
else
clear_bit(MTIP_DDF_SEC_LOCK_BIT, &port->dd->dd_flag);
#ifdef MTIP_TRIM
if (port->identify[69] & (1 << 14) && port->identify[69] & (1 << 5))
port->dd->trim_supp = true;
else
#endif
port->dd->trim_supp = false;
port->identify_valid = 1;
if (user_buffer) {
if (copy_to_user(
user_buffer,
port->identify,
ATA_ID_WORDS * sizeof(u16))) {
rv = -EFAULT;
goto out;
}
}
out:
return rv;
}
static int mtip_standby_immediate(struct mtip_port *port)
{
int rv;
struct host_to_dev_fis fis;
unsigned long start;
unsigned int timeout;
memset(&fis, 0, sizeof(struct host_to_dev_fis));
fis.type = 0x27;
fis.opts = 1 << 7;
fis.command = ATA_CMD_STANDBYNOW1;
mtip_set_timeout(port->dd, &fis, &timeout, 0);
start = jiffies;
rv = mtip_exec_internal_command(port,
&fis,
5,
0,
0,
0,
GFP_ATOMIC,
timeout);
dbg_printk(MTIP_DRV_NAME "Time taken to complete standby cmd: %d ms\n",
jiffies_to_msecs(jiffies - start));
if (rv)
dev_warn(&port->dd->pdev->dev,
"STANDBY IMMEDIATE command failed.\n");
return rv;
}
static int mtip_read_log_page(struct mtip_port *port, u8 page, u16 *buffer,
dma_addr_t buffer_dma, unsigned int sectors)
{
struct host_to_dev_fis fis;
memset(&fis, 0, sizeof(struct host_to_dev_fis));
fis.type = 0x27;
fis.opts = 1 << 7;
fis.command = ATA_CMD_READ_LOG_EXT;
fis.sect_count = sectors & 0xFF;
fis.sect_cnt_ex = (sectors >> 8) & 0xFF;
fis.lba_low = page;
fis.lba_mid = 0;
fis.device = ATA_DEVICE_OBS;
memset(buffer, 0, sectors * ATA_SECT_SIZE);
return mtip_exec_internal_command(port,
&fis,
5,
buffer_dma,
sectors * ATA_SECT_SIZE,
0,
GFP_ATOMIC,
MTIP_INT_CMD_TIMEOUT_MS);
}
static int mtip_get_smart_data(struct mtip_port *port, u8 *buffer,
dma_addr_t buffer_dma)
{
struct host_to_dev_fis fis;
memset(&fis, 0, sizeof(struct host_to_dev_fis));
fis.type = 0x27;
fis.opts = 1 << 7;
fis.command = ATA_CMD_SMART;
fis.features = 0xD0;
fis.sect_count = 1;
fis.lba_mid = 0x4F;
fis.lba_hi = 0xC2;
fis.device = ATA_DEVICE_OBS;
return mtip_exec_internal_command(port,
&fis,
5,
buffer_dma,
ATA_SECT_SIZE,
0,
GFP_ATOMIC,
15000);
}
static int mtip_get_smart_attr(struct mtip_port *port, unsigned int id,
struct smart_attr *attrib)
{
int rv, i;
struct smart_attr *pattr;
if (!attrib)
return -EINVAL;
if (!port->identify_valid) {
dev_warn(&port->dd->pdev->dev, "IDENTIFY DATA not valid\n");
return -EPERM;
}
if (!(port->identify[82] & 0x1)) {
dev_warn(&port->dd->pdev->dev, "SMART not supported\n");
return -EPERM;
}
if (!(port->identify[85] & 0x1)) {
dev_warn(&port->dd->pdev->dev, "SMART not enabled\n");
return -EPERM;
}
memset(port->smart_buf, 0, ATA_SECT_SIZE);
rv = mtip_get_smart_data(port, port->smart_buf, port->smart_buf_dma);
if (rv) {
dev_warn(&port->dd->pdev->dev, "Failed to ge SMART data\n");
return rv;
}
pattr = (struct smart_attr *)(port->smart_buf + 2);
for (i = 0; i < 29; i++, pattr++)
if (pattr->attr_id == id) {
memcpy(attrib, pattr, sizeof(struct smart_attr));
break;
}
if (i == 29) {
dev_warn(&port->dd->pdev->dev,
"Query for invalid SMART attribute ID\n");
rv = -EINVAL;
}
return rv;
}
static int mtip_send_trim(struct driver_data *dd, unsigned int lba,
unsigned int len)
{
int i, rv = 0;
u64 tlba, tlen, sect_left;
struct mtip_trim_entry *buf;
dma_addr_t dma_addr;
struct host_to_dev_fis fis;
if (!len || dd->trim_supp == false)
return -EINVAL;
WARN_ON(len > (MTIP_MAX_TRIM_ENTRY_LEN * MTIP_MAX_TRIM_ENTRIES));
WARN_ON(len % 8 != 0);
WARN_ON(sizeof(struct mtip_trim) > ATA_SECT_SIZE);
buf = dmam_alloc_coherent(&dd->pdev->dev, ATA_SECT_SIZE, &dma_addr,
GFP_KERNEL);
if (!buf)
return -ENOMEM;
memset(buf, 0, ATA_SECT_SIZE);
for (i = 0, sect_left = len, tlba = lba;
i < MTIP_MAX_TRIM_ENTRIES && sect_left;
i++) {
tlen = (sect_left >= MTIP_MAX_TRIM_ENTRY_LEN ?
MTIP_MAX_TRIM_ENTRY_LEN :
sect_left);
buf[i].lba = __force_bit2int cpu_to_le32(tlba);
buf[i].range = __force_bit2int cpu_to_le16(tlen);
tlba += tlen;
sect_left -= tlen;
}
WARN_ON(sect_left != 0);
memset(&fis, 0, sizeof(struct host_to_dev_fis));
fis.type = 0x27;
fis.opts = 1 << 7;
fis.command = 0xfb;
fis.features = 0x60;
fis.sect_count = 1;
fis.device = ATA_DEVICE_OBS;
if (mtip_exec_internal_command(dd->port,
&fis,
5,
dma_addr,
ATA_SECT_SIZE,
0,
GFP_KERNEL,
MTIP_TRIM_TIMEOUT_MS) < 0)
rv = -EIO;
dmam_free_coherent(&dd->pdev->dev, ATA_SECT_SIZE, buf, dma_addr);
return rv;
}
static bool mtip_hw_get_capacity(struct driver_data *dd, sector_t *sectors)
{
struct mtip_port *port = dd->port;
u64 total, raw0, raw1, raw2, raw3;
raw0 = port->identify[100];
raw1 = port->identify[101];
raw2 = port->identify[102];
raw3 = port->identify[103];
total = raw0 | raw1<<16 | raw2<<32 | raw3<<48;
*sectors = total;
return (bool) !!port->identify_valid;
}
static void mtip_dump_identify(struct mtip_port *port)
{
sector_t sectors;
unsigned short revid;
char cbuf[42];
if (!port->identify_valid)
return;
strlcpy(cbuf, (char *)(port->identify+10), 21);
dev_info(&port->dd->pdev->dev,
"Serial No.: %s\n", cbuf);
strlcpy(cbuf, (char *)(port->identify+23), 9);
dev_info(&port->dd->pdev->dev,
"Firmware Ver.: %s\n", cbuf);
strlcpy(cbuf, (char *)(port->identify+27), 41);
dev_info(&port->dd->pdev->dev, "Model: %s\n", cbuf);
dev_info(&port->dd->pdev->dev, "Security: %04x %s\n",
port->identify[128],
port->identify[128] & 0x4 ? "(LOCKED)" : "");
if (mtip_hw_get_capacity(port->dd, &sectors))
dev_info(&port->dd->pdev->dev,
"Capacity: %llu sectors (%llu MB)\n",
(u64)sectors,
((u64)sectors) * ATA_SECT_SIZE >> 20);
pci_read_config_word(port->dd->pdev, PCI_REVISION_ID, &revid);
switch (revid & 0xFF) {
case 0x1:
strlcpy(cbuf, "A0", 3);
break;
case 0x3:
strlcpy(cbuf, "A2", 3);
break;
default:
strlcpy(cbuf, "?", 2);
break;
}
dev_info(&port->dd->pdev->dev,
"Card Type: %s\n", cbuf);
}
static inline void fill_command_sg(struct driver_data *dd,
struct mtip_cmd *command,
int nents)
{
int n;
unsigned int dma_len;
struct mtip_cmd_sg *command_sg;
struct scatterlist *sg = command->sg;
command_sg = command->command + AHCI_CMD_TBL_HDR_SZ;
for (n = 0; n < nents; n++) {
dma_len = sg_dma_len(sg);
if (dma_len > 0x400000)
dev_err(&dd->pdev->dev,
"DMA segment length truncated\n");
command_sg->info = __force_bit2int
cpu_to_le32((dma_len-1) & 0x3FFFFF);
command_sg->dba = __force_bit2int
cpu_to_le32(sg_dma_address(sg));
command_sg->dba_upper = __force_bit2int
cpu_to_le32((sg_dma_address(sg) >> 16) >> 16);
command_sg++;
sg++;
}
}
static int exec_drive_task(struct mtip_port *port, u8 *command)
{
struct host_to_dev_fis fis;
struct host_to_dev_fis *reply = (port->rxfis + RX_FIS_D2H_REG);
unsigned int to;
memset(&fis, 0, sizeof(struct host_to_dev_fis));
fis.type = 0x27;
fis.opts = 1 << 7;
fis.command = command[0];
fis.features = command[1];
fis.sect_count = command[2];
fis.sector = command[3];
fis.cyl_low = command[4];
fis.cyl_hi = command[5];
fis.device = command[6] & ~0x10;
mtip_set_timeout(port->dd, &fis, &to, 0);
dbg_printk(MTIP_DRV_NAME " %s: User Command: cmd %x, feat %x, nsect %x, sect %x, lcyl %x, hcyl %x, sel %x\n",
__func__,
command[0],
command[1],
command[2],
command[3],
command[4],
command[5],
command[6]);
if (mtip_exec_internal_command(port,
&fis,
5,
0,
0,
0,
GFP_KERNEL,
to) < 0) {
return -1;
}
command[0] = reply->command;
command[1] = reply->features;
command[4] = reply->cyl_low;
command[5] = reply->cyl_hi;
dbg_printk(MTIP_DRV_NAME " %s: Completion Status: stat %x, err %x , cyl_lo %x cyl_hi %x\n",
__func__,
command[0],
command[1],
command[4],
command[5]);
return 0;
}
static int exec_drive_command(struct mtip_port *port, u8 *command,
void __user *user_buffer)
{
struct host_to_dev_fis fis;
struct host_to_dev_fis *reply;
u8 *buf = NULL;
dma_addr_t dma_addr = 0;
int rv = 0, xfer_sz = command[3];
unsigned int to;
if (xfer_sz) {
if (!user_buffer)
return -EFAULT;
buf = dmam_alloc_coherent(&port->dd->pdev->dev,
ATA_SECT_SIZE * xfer_sz,
&dma_addr,
GFP_KERNEL);
if (!buf) {
dev_err(&port->dd->pdev->dev,
"Memory allocation failed (%d bytes)\n",
ATA_SECT_SIZE * xfer_sz);
return -ENOMEM;
}
memset(buf, 0, ATA_SECT_SIZE * xfer_sz);
}
memset(&fis, 0, sizeof(struct host_to_dev_fis));
fis.type = 0x27;
fis.opts = 1 << 7;
fis.command = command[0];
fis.features = command[2];
fis.sect_count = command[3];
if (fis.command == ATA_CMD_SMART) {
fis.sector = command[1];
fis.cyl_low = 0x4F;
fis.cyl_hi = 0xC2;
}
mtip_set_timeout(port->dd, &fis, &to, 0);
if (xfer_sz)
reply = (port->rxfis + RX_FIS_PIO_SETUP);
else
reply = (port->rxfis + RX_FIS_D2H_REG);
dbg_printk(MTIP_DRV_NAME
" %s: User Command: cmd %x, sect %x, "
"feat %x, sectcnt %x\n",
__func__,
command[0],
command[1],
command[2],
command[3]);
if (mtip_exec_internal_command(port,
&fis,
5,
(xfer_sz ? dma_addr : 0),
(xfer_sz ? ATA_SECT_SIZE * xfer_sz : 0),
0,
GFP_KERNEL,
to)
< 0) {
rv = -EFAULT;
goto exit_drive_command;
}
command[0] = reply->command;
command[1] = reply->features;
command[2] = reply->sect_count;
dbg_printk(MTIP_DRV_NAME
" %s: Completion Status: stat %x, "
"err %x, nsect %x\n",
__func__,
command[0],
command[1],
command[2]);
if (xfer_sz) {
if (copy_to_user(user_buffer,
buf,
ATA_SECT_SIZE * command[3])) {
rv = -EFAULT;
goto exit_drive_command;
}
}
exit_drive_command:
if (buf)
dmam_free_coherent(&port->dd->pdev->dev,
ATA_SECT_SIZE * xfer_sz, buf, dma_addr);
return rv;
}
static unsigned int implicit_sector(unsigned char command,
unsigned char features)
{
unsigned int rv = 0;
switch (command) {
case ATA_CMD_SEC_SET_PASS:
case ATA_CMD_SEC_UNLOCK:
case ATA_CMD_SEC_ERASE_PREP:
case ATA_CMD_SEC_ERASE_UNIT:
case ATA_CMD_SEC_FREEZE_LOCK:
case ATA_CMD_SEC_DISABLE_PASS:
case ATA_CMD_PMP_READ:
case ATA_CMD_PMP_WRITE:
rv = 1;
break;
case ATA_CMD_SET_MAX:
if (features == ATA_SET_MAX_UNLOCK)
rv = 1;
break;
case ATA_CMD_SMART:
if ((features == ATA_SMART_READ_VALUES) ||
(features == ATA_SMART_READ_THRESHOLDS))
rv = 1;
break;
case ATA_CMD_CONF_OVERLAY:
if ((features == ATA_DCO_IDENTIFY) ||
(features == ATA_DCO_SET))
rv = 1;
break;
}
return rv;
}
static int exec_drive_taskfile(struct driver_data *dd,
void __user *buf,
ide_task_request_t *req_task,
int outtotal)
{
struct host_to_dev_fis fis;
struct host_to_dev_fis *reply;
u8 *outbuf = NULL;
u8 *inbuf = NULL;
dma_addr_t outbuf_dma = 0;
dma_addr_t inbuf_dma = 0;
dma_addr_t dma_buffer = 0;
int err = 0;
unsigned int taskin = 0;
unsigned int taskout = 0;
u8 nsect = 0;
unsigned int timeout;
unsigned int force_single_sector;
unsigned int transfer_size;
unsigned long task_file_data;
int intotal = outtotal + req_task->out_size;
int erasemode = 0;
taskout = req_task->out_size;
taskin = req_task->in_size;
if (taskin > 130560 || taskout > 130560) {
err = -EINVAL;
goto abort;
}
if (taskout) {
outbuf = memdup_user(buf + outtotal, taskout);
if (IS_ERR(outbuf)) {
err = PTR_ERR(outbuf);
outbuf = NULL;
goto abort;
}
outbuf_dma = pci_map_single(dd->pdev,
outbuf,
taskout,
DMA_TO_DEVICE);
if (outbuf_dma == 0) {
err = -ENOMEM;
goto abort;
}
dma_buffer = outbuf_dma;
}
if (taskin) {
inbuf = memdup_user(buf + intotal, taskin);
if (IS_ERR(inbuf)) {
err = PTR_ERR(inbuf);
inbuf = NULL;
goto abort;
}
inbuf_dma = pci_map_single(dd->pdev,
inbuf,
taskin, DMA_FROM_DEVICE);
if (inbuf_dma == 0) {
err = -ENOMEM;
goto abort;
}
dma_buffer = inbuf_dma;
}
switch (req_task->data_phase) {
case TASKFILE_OUT:
nsect = taskout / ATA_SECT_SIZE;
reply = (dd->port->rxfis + RX_FIS_PIO_SETUP);
break;
case TASKFILE_IN:
reply = (dd->port->rxfis + RX_FIS_PIO_SETUP);
break;
case TASKFILE_NO_DATA:
reply = (dd->port->rxfis + RX_FIS_D2H_REG);
break;
default:
err = -EINVAL;
goto abort;
}
memset(&fis, 0, sizeof(struct host_to_dev_fis));
fis.type = 0x27;
fis.opts = 1 << 7;
fis.command = req_task->io_ports[7];
fis.features = req_task->io_ports[1];
fis.sect_count = req_task->io_ports[2];
fis.lba_low = req_task->io_ports[3];
fis.lba_mid = req_task->io_ports[4];
fis.lba_hi = req_task->io_ports[5];
fis.device = req_task->io_ports[6] & ~0x10;
if ((req_task->in_flags.all == 0) && (req_task->out_flags.all & 1)) {
req_task->in_flags.all =
IDE_TASKFILE_STD_IN_FLAGS |
(IDE_HOB_STD_IN_FLAGS << 8);
fis.lba_low_ex = req_task->hob_ports[3];
fis.lba_mid_ex = req_task->hob_ports[4];
fis.lba_hi_ex = req_task->hob_ports[5];
fis.features_ex = req_task->hob_ports[1];
fis.sect_cnt_ex = req_task->hob_ports[2];
} else {
req_task->in_flags.all = IDE_TASKFILE_STD_IN_FLAGS;
}
force_single_sector = implicit_sector(fis.command, fis.features);
if ((taskin || taskout) && (!fis.sect_count)) {
if (nsect)
fis.sect_count = nsect;
else {
if (!force_single_sector) {
dev_warn(&dd->pdev->dev,
"data movement but "
"sect_count is 0\n");
err = -EINVAL;
goto abort;
}
}
}
dbg_printk(MTIP_DRV_NAME
" %s: cmd %x, feat %x, nsect %x,"
" sect/lbal %x, lcyl/lbam %x, hcyl/lbah %x,"
" head/dev %x\n",
__func__,
fis.command,
fis.features,
fis.sect_count,
fis.lba_low,
fis.lba_mid,
fis.lba_hi,
fis.device);
if ((fis.command == ATA_CMD_SEC_ERASE_UNIT) && outbuf &&
(outbuf[0] & MTIP_SEC_ERASE_MODE)) {
erasemode = 1;
}
mtip_set_timeout(dd, &fis, &timeout, erasemode);
if (force_single_sector)
transfer_size = ATA_SECT_SIZE;
else
transfer_size = ATA_SECT_SIZE * fis.sect_count;
if (mtip_exec_internal_command(dd->port,
&fis,
5,
dma_buffer,
transfer_size,
0,
GFP_KERNEL,
timeout) < 0) {
err = -EIO;
goto abort;
}
task_file_data = readl(dd->port->mmio+PORT_TFDATA);
if ((req_task->data_phase == TASKFILE_IN) && !(task_file_data & 1)) {
reply = dd->port->rxfis + RX_FIS_PIO_SETUP;
req_task->io_ports[7] = reply->control;
} else {
reply = dd->port->rxfis + RX_FIS_D2H_REG;
req_task->io_ports[7] = reply->command;
}
if (inbuf_dma)
pci_unmap_single(dd->pdev, inbuf_dma,
taskin, DMA_FROM_DEVICE);
if (outbuf_dma)
pci_unmap_single(dd->pdev, outbuf_dma,
taskout, DMA_TO_DEVICE);
inbuf_dma = 0;
outbuf_dma = 0;
req_task->io_ports[1] = reply->features;
req_task->io_ports[2] = reply->sect_count;
req_task->io_ports[3] = reply->lba_low;
req_task->io_ports[4] = reply->lba_mid;
req_task->io_ports[5] = reply->lba_hi;
req_task->io_ports[6] = reply->device;
if (req_task->out_flags.all & 1) {
req_task->hob_ports[3] = reply->lba_low_ex;
req_task->hob_ports[4] = reply->lba_mid_ex;
req_task->hob_ports[5] = reply->lba_hi_ex;
req_task->hob_ports[1] = reply->features_ex;
req_task->hob_ports[2] = reply->sect_cnt_ex;
}
dbg_printk(MTIP_DRV_NAME
" %s: Completion: stat %x,"
"err %x, sect_cnt %x, lbalo %x,"
"lbamid %x, lbahi %x, dev %x\n",
__func__,
req_task->io_ports[7],
req_task->io_ports[1],
req_task->io_ports[2],
req_task->io_ports[3],
req_task->io_ports[4],
req_task->io_ports[5],
req_task->io_ports[6]);
if (taskout) {
if (copy_to_user(buf + outtotal, outbuf, taskout)) {
err = -EFAULT;
goto abort;
}
}
if (taskin) {
if (copy_to_user(buf + intotal, inbuf, taskin)) {
err = -EFAULT;
goto abort;
}
}
abort:
if (inbuf_dma)
pci_unmap_single(dd->pdev, inbuf_dma,
taskin, DMA_FROM_DEVICE);
if (outbuf_dma)
pci_unmap_single(dd->pdev, outbuf_dma,
taskout, DMA_TO_DEVICE);
kfree(outbuf);
kfree(inbuf);
return err;
}
static int mtip_hw_ioctl(struct driver_data *dd, unsigned int cmd,
unsigned long arg)
{
switch (cmd) {
case HDIO_GET_IDENTITY:
{
if (copy_to_user((void __user *)arg, dd->port->identify,
sizeof(u16) * ATA_ID_WORDS))
return -EFAULT;
break;
}
case HDIO_DRIVE_CMD:
{
u8 drive_command[4];
if (copy_from_user(drive_command,
(void __user *) arg,
sizeof(drive_command)))
return -EFAULT;
if (exec_drive_command(dd->port,
drive_command,
(void __user *) (arg+4)))
return -EIO;
if (copy_to_user((void __user *) arg,
drive_command,
sizeof(drive_command)))
return -EFAULT;
break;
}
case HDIO_DRIVE_TASK:
{
u8 drive_command[7];
if (copy_from_user(drive_command,
(void __user *) arg,
sizeof(drive_command)))
return -EFAULT;
if (exec_drive_task(dd->port, drive_command))
return -EIO;
if (copy_to_user((void __user *) arg,
drive_command,
sizeof(drive_command)))
return -EFAULT;
break;
}
case HDIO_DRIVE_TASKFILE: {
ide_task_request_t req_task;
int ret, outtotal;
if (copy_from_user(&req_task, (void __user *) arg,
sizeof(req_task)))
return -EFAULT;
outtotal = sizeof(req_task);
ret = exec_drive_taskfile(dd, (void __user *) arg,
&req_task, outtotal);
if (copy_to_user((void __user *) arg, &req_task,
sizeof(req_task)))
return -EFAULT;
return ret;
}
default:
return -EINVAL;
}
return 0;
}
static void mtip_hw_submit_io(struct driver_data *dd, struct request *rq,
struct mtip_cmd *command, int nents,
struct blk_mq_hw_ctx *hctx)
{
struct host_to_dev_fis *fis;
struct mtip_port *port = dd->port;
int dma_dir = rq_data_dir(rq) == READ ? DMA_FROM_DEVICE : DMA_TO_DEVICE;
u64 start = blk_rq_pos(rq);
unsigned int nsect = blk_rq_sectors(rq);
nents = dma_map_sg(&dd->pdev->dev, command->sg, nents, dma_dir);
prefetch(&port->flags);
command->scatter_ents = nents;
command->retries = MTIP_MAX_RETRIES;
fis = command->command;
fis->type = 0x27;
fis->opts = 1 << 7;
if (dma_dir == DMA_FROM_DEVICE)
fis->command = ATA_CMD_FPDMA_READ;
else
fis->command = ATA_CMD_FPDMA_WRITE;
fis->lba_low = start & 0xFF;
fis->lba_mid = (start >> 8) & 0xFF;
fis->lba_hi = (start >> 16) & 0xFF;
fis->lba_low_ex = (start >> 24) & 0xFF;
fis->lba_mid_ex = (start >> 32) & 0xFF;
fis->lba_hi_ex = (start >> 40) & 0xFF;
fis->device = 1 << 6;
fis->features = nsect & 0xFF;
fis->features_ex = (nsect >> 8) & 0xFF;
fis->sect_count = ((rq->tag << 3) | (rq->tag >> 5));
fis->sect_cnt_ex = 0;
fis->control = 0;
fis->res2 = 0;
fis->res3 = 0;
fill_command_sg(dd, command, nents);
if (unlikely(command->unaligned))
fis->device |= 1 << 7;
command->command_header->opts =
__force_bit2int cpu_to_le32(
(nents << 16) | 5 | AHCI_CMD_PREFETCH);
command->command_header->byte_count = 0;
command->comp_data = dd;
command->comp_func = mtip_async_complete;
command->direction = dma_dir;
if (unlikely(port->flags & MTIP_PF_PAUSE_IO)) {
set_bit(rq->tag, port->cmds_to_issue);
set_bit(MTIP_PF_ISSUE_CMDS_BIT, &port->flags);
return;
}
mtip_issue_ncq_command(port, rq->tag);
}
static ssize_t mtip_hw_show_status(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct driver_data *dd = dev_to_disk(dev)->private_data;
int size = 0;
if (test_bit(MTIP_DDF_OVER_TEMP_BIT, &dd->dd_flag))
size += sprintf(buf, "%s", "thermal_shutdown\n");
else if (test_bit(MTIP_DDF_WRITE_PROTECT_BIT, &dd->dd_flag))
size += sprintf(buf, "%s", "write_protect\n");
else
size += sprintf(buf, "%s", "online\n");
return size;
}
static ssize_t show_device_status(struct device_driver *drv, char *buf)
{
int size = 0;
struct driver_data *dd, *tmp;
unsigned long flags;
char id_buf[42];
u16 status = 0;
spin_lock_irqsave(&dev_lock, flags);
size += sprintf(&buf[size], "Devices Present:\n");
list_for_each_entry_safe(dd, tmp, &online_list, online_list) {
if (dd->pdev) {
if (dd->port &&
dd->port->identify &&
dd->port->identify_valid) {
strlcpy(id_buf,
(char *) (dd->port->identify + 10), 21);
status = *(dd->port->identify + 141);
} else {
memset(id_buf, 0, 42);
status = 0;
}
if (dd->port &&
test_bit(MTIP_PF_REBUILD_BIT, &dd->port->flags)) {
size += sprintf(&buf[size],
" device %s %s (ftl rebuild %d %%)\n",
dev_name(&dd->pdev->dev),
id_buf,
status);
} else {
size += sprintf(&buf[size],
" device %s %s\n",
dev_name(&dd->pdev->dev),
id_buf);
}
}
}
size += sprintf(&buf[size], "Devices Being Removed:\n");
list_for_each_entry_safe(dd, tmp, &removing_list, remove_list) {
if (dd->pdev) {
if (dd->port &&
dd->port->identify &&
dd->port->identify_valid) {
strlcpy(id_buf,
(char *) (dd->port->identify+10), 21);
status = *(dd->port->identify + 141);
} else {
memset(id_buf, 0, 42);
status = 0;
}
if (dd->port &&
test_bit(MTIP_PF_REBUILD_BIT, &dd->port->flags)) {
size += sprintf(&buf[size],
" device %s %s (ftl rebuild %d %%)\n",
dev_name(&dd->pdev->dev),
id_buf,
status);
} else {
size += sprintf(&buf[size],
" device %s %s\n",
dev_name(&dd->pdev->dev),
id_buf);
}
}
}
spin_unlock_irqrestore(&dev_lock, flags);
return size;
}
static ssize_t mtip_hw_read_device_status(struct file *f, char __user *ubuf,
size_t len, loff_t *offset)
{
struct driver_data *dd = (struct driver_data *)f->private_data;
int size = *offset;
char *buf;
int rv = 0;
if (!len || *offset)
return 0;
buf = kzalloc(MTIP_DFS_MAX_BUF_SIZE, GFP_KERNEL);
if (!buf) {
dev_err(&dd->pdev->dev,
"Memory allocation: status buffer\n");
return -ENOMEM;
}
size += show_device_status(NULL, buf);
*offset = size <= len ? size : len;
size = copy_to_user(ubuf, buf, *offset);
if (size)
rv = -EFAULT;
kfree(buf);
return rv ? rv : *offset;
}
static ssize_t mtip_hw_read_registers(struct file *f, char __user *ubuf,
size_t len, loff_t *offset)
{
struct driver_data *dd = (struct driver_data *)f->private_data;
char *buf;
u32 group_allocated;
int size = *offset;
int n, rv = 0;
if (!len || size)
return 0;
buf = kzalloc(MTIP_DFS_MAX_BUF_SIZE, GFP_KERNEL);
if (!buf) {
dev_err(&dd->pdev->dev,
"Memory allocation: register buffer\n");
return -ENOMEM;
}
size += sprintf(&buf[size], "H/ S ACTive : [ 0x");
for (n = dd->slot_groups-1; n >= 0; n--)
size += sprintf(&buf[size], "%08X ",
readl(dd->port->s_active[n]));
size += sprintf(&buf[size], "]\n");
size += sprintf(&buf[size], "H/ Command Issue : [ 0x");
for (n = dd->slot_groups-1; n >= 0; n--)
size += sprintf(&buf[size], "%08X ",
readl(dd->port->cmd_issue[n]));
size += sprintf(&buf[size], "]\n");
size += sprintf(&buf[size], "H/ Completed : [ 0x");
for (n = dd->slot_groups-1; n >= 0; n--)
size += sprintf(&buf[size], "%08X ",
readl(dd->port->completed[n]));
size += sprintf(&buf[size], "]\n");
size += sprintf(&buf[size], "H/ PORT IRQ STAT : [ 0x%08X ]\n",
readl(dd->port->mmio + PORT_IRQ_STAT));
size += sprintf(&buf[size], "H/ HOST IRQ STAT : [ 0x%08X ]\n",
readl(dd->mmio + HOST_IRQ_STAT));
size += sprintf(&buf[size], "\n");
size += sprintf(&buf[size], "L/ Commands in Q : [ 0x");
for (n = dd->slot_groups-1; n >= 0; n--) {
if (sizeof(long) > sizeof(u32))
group_allocated =
dd->port->cmds_to_issue[n/2] >> (32*(n&1));
else
group_allocated = dd->port->cmds_to_issue[n];
size += sprintf(&buf[size], "%08X ", group_allocated);
}
size += sprintf(&buf[size], "]\n");
*offset = size <= len ? size : len;
size = copy_to_user(ubuf, buf, *offset);
if (size)
rv = -EFAULT;
kfree(buf);
return rv ? rv : *offset;
}
static ssize_t mtip_hw_read_flags(struct file *f, char __user *ubuf,
size_t len, loff_t *offset)
{
struct driver_data *dd = (struct driver_data *)f->private_data;
char *buf;
int size = *offset;
int rv = 0;
if (!len || size)
return 0;
buf = kzalloc(MTIP_DFS_MAX_BUF_SIZE, GFP_KERNEL);
if (!buf) {
dev_err(&dd->pdev->dev,
"Memory allocation: flag buffer\n");
return -ENOMEM;
}
size += sprintf(&buf[size], "Flag-port : [ %08lX ]\n",
dd->port->flags);
size += sprintf(&buf[size], "Flag-dd : [ %08lX ]\n",
dd->dd_flag);
*offset = size <= len ? size : len;
size = copy_to_user(ubuf, buf, *offset);
if (size)
rv = -EFAULT;
kfree(buf);
return rv ? rv : *offset;
}
static int mtip_hw_sysfs_init(struct driver_data *dd, struct kobject *kobj)
{
if (!kobj || !dd)
return -EINVAL;
if (sysfs_create_file(kobj, &dev_attr_status.attr))
dev_warn(&dd->pdev->dev,
"Error creating 'status' sysfs entry\n");
return 0;
}
static int mtip_hw_sysfs_exit(struct driver_data *dd, struct kobject *kobj)
{
if (!kobj || !dd)
return -EINVAL;
sysfs_remove_file(kobj, &dev_attr_status.attr);
return 0;
}
static int mtip_hw_debugfs_init(struct driver_data *dd)
{
if (!dfs_parent)
return -1;
dd->dfs_node = debugfs_create_dir(dd->disk->disk_name, dfs_parent);
if (IS_ERR_OR_NULL(dd->dfs_node)) {
dev_warn(&dd->pdev->dev,
"Error creating node %s under debugfs\n",
dd->disk->disk_name);
dd->dfs_node = NULL;
return -1;
}
debugfs_create_file("flags", S_IRUGO, dd->dfs_node, dd,
&mtip_flags_fops);
debugfs_create_file("registers", S_IRUGO, dd->dfs_node, dd,
&mtip_regs_fops);
return 0;
}
static void mtip_hw_debugfs_exit(struct driver_data *dd)
{
if (dd->dfs_node)
debugfs_remove_recursive(dd->dfs_node);
}
static inline void hba_setup(struct driver_data *dd)
{
u32 hwdata;
hwdata = readl(dd->mmio + HOST_HSORG);
writel(hwdata |
HSORG_DISABLE_SLOTGRP_INTR |
HSORG_DISABLE_SLOTGRP_PXIS,
dd->mmio + HOST_HSORG);
}
static int mtip_device_unaligned_constrained(struct driver_data *dd)
{
return (dd->pdev->device == P420M_DEVICE_ID ? 1 : 0);
}
static void mtip_detect_product(struct driver_data *dd)
{
u32 hwdata;
unsigned int rev, slotgroups;
hwdata = readl(dd->mmio + HOST_HSORG);
dd->product_type = MTIP_PRODUCT_UNKNOWN;
dd->slot_groups = 1;
if (hwdata & 0x8) {
dd->product_type = MTIP_PRODUCT_ASICFPGA;
rev = (hwdata & HSORG_HWREV) >> 8;
slotgroups = (hwdata & HSORG_SLOTGROUPS) + 1;
dev_info(&dd->pdev->dev,
"ASIC-FPGA design, HS rev 0x%x, "
"%i slot groups [%i slots]\n",
rev,
slotgroups,
slotgroups * 32);
if (slotgroups > MTIP_MAX_SLOT_GROUPS) {
dev_warn(&dd->pdev->dev,
"Warning: driver only supports "
"%i slot groups.\n", MTIP_MAX_SLOT_GROUPS);
slotgroups = MTIP_MAX_SLOT_GROUPS;
}
dd->slot_groups = slotgroups;
return;
}
dev_warn(&dd->pdev->dev, "Unrecognized product id\n");
}
static int mtip_ftl_rebuild_poll(struct driver_data *dd)
{
unsigned long timeout, cnt = 0, start;
dev_warn(&dd->pdev->dev,
"FTL rebuild in progress. Polling for completion.\n");
start = jiffies;
timeout = jiffies + msecs_to_jiffies(MTIP_FTL_REBUILD_TIMEOUT_MS);
do {
if (unlikely(test_bit(MTIP_DDF_REMOVE_PENDING_BIT,
&dd->dd_flag)))
return -EFAULT;
if (mtip_check_surprise_removal(dd->pdev))
return -EFAULT;
if (mtip_get_identify(dd->port, NULL) < 0)
return -EFAULT;
if (*(dd->port->identify + MTIP_FTL_REBUILD_OFFSET) ==
MTIP_FTL_REBUILD_MAGIC) {
ssleep(1);
if (cnt++ >= 180) {
dev_warn(&dd->pdev->dev,
"FTL rebuild in progress (%d secs).\n",
jiffies_to_msecs(jiffies - start) / 1000);
cnt = 0;
}
} else {
dev_warn(&dd->pdev->dev,
"FTL rebuild complete (%d secs).\n",
jiffies_to_msecs(jiffies - start) / 1000);
mtip_block_initialize(dd);
return 0;
}
} while (time_before(jiffies, timeout));
dev_err(&dd->pdev->dev,
"Timed out waiting for FTL rebuild to complete (%d secs).\n",
jiffies_to_msecs(jiffies - start) / 1000);
return -EFAULT;
}
static int mtip_service_thread(void *data)
{
struct driver_data *dd = (struct driver_data *)data;
unsigned long slot, slot_start, slot_wrap;
unsigned int num_cmd_slots = dd->slot_groups * 32;
struct mtip_port *port = dd->port;
while (1) {
if (kthread_should_stop() ||
test_bit(MTIP_PF_SVC_THD_STOP_BIT, &port->flags))
goto st_out;
clear_bit(MTIP_PF_SVC_THD_ACTIVE_BIT, &port->flags);
wait_event_interruptible(port->svc_wait, (port->flags) &&
!(port->flags & MTIP_PF_PAUSE_IO));
set_bit(MTIP_PF_SVC_THD_ACTIVE_BIT, &port->flags);
if (kthread_should_stop() ||
test_bit(MTIP_PF_SVC_THD_STOP_BIT, &port->flags))
goto st_out;
if (unlikely(test_bit(MTIP_DDF_REMOVE_PENDING_BIT,
&dd->dd_flag)))
goto st_out;
restart_eh:
if (test_bit(MTIP_PF_EH_ACTIVE_BIT, &port->flags)) {
mtip_handle_tfe(dd);
clear_bit(MTIP_PF_EH_ACTIVE_BIT, &port->flags);
}
if (test_bit(MTIP_PF_EH_ACTIVE_BIT, &port->flags))
goto restart_eh;
if (test_bit(MTIP_PF_ISSUE_CMDS_BIT, &port->flags)) {
slot = 1;
slot_start = num_cmd_slots;
slot_wrap = 0;
while (1) {
slot = find_next_bit(port->cmds_to_issue,
num_cmd_slots, slot);
if (slot_wrap == 1) {
if ((slot_start >= slot) ||
(slot >= num_cmd_slots))
break;
}
if (unlikely(slot_start == num_cmd_slots))
slot_start = slot;
if (unlikely(slot == num_cmd_slots)) {
slot = 1;
slot_wrap = 1;
continue;
}
mtip_issue_ncq_command(port, slot);
clear_bit(slot, port->cmds_to_issue);
}
clear_bit(MTIP_PF_ISSUE_CMDS_BIT, &port->flags);
}
if (test_bit(MTIP_PF_REBUILD_BIT, &port->flags)) {
if (mtip_ftl_rebuild_poll(dd) < 0)
set_bit(MTIP_DDF_REBUILD_FAILED_BIT,
&dd->dd_flag);
clear_bit(MTIP_PF_REBUILD_BIT, &port->flags);
}
}
st_out:
return 0;
}
static void mtip_dma_free(struct driver_data *dd)
{
struct mtip_port *port = dd->port;
if (port->block1)
dmam_free_coherent(&dd->pdev->dev, BLOCK_DMA_ALLOC_SZ,
port->block1, port->block1_dma);
if (port->command_list) {
dmam_free_coherent(&dd->pdev->dev, AHCI_CMD_TBL_SZ,
port->command_list, port->command_list_dma);
}
}
static int mtip_dma_alloc(struct driver_data *dd)
{
struct mtip_port *port = dd->port;
port->block1 =
dmam_alloc_coherent(&dd->pdev->dev, BLOCK_DMA_ALLOC_SZ,
&port->block1_dma, GFP_KERNEL);
if (!port->block1)
return -ENOMEM;
memset(port->block1, 0, BLOCK_DMA_ALLOC_SZ);
port->command_list =
dmam_alloc_coherent(&dd->pdev->dev, AHCI_CMD_TBL_SZ,
&port->command_list_dma, GFP_KERNEL);
if (!port->command_list) {
dmam_free_coherent(&dd->pdev->dev, BLOCK_DMA_ALLOC_SZ,
port->block1, port->block1_dma);
port->block1 = NULL;
port->block1_dma = 0;
return -ENOMEM;
}
memset(port->command_list, 0, AHCI_CMD_TBL_SZ);
port->rxfis = port->block1 + AHCI_RX_FIS_OFFSET;
port->rxfis_dma = port->block1_dma + AHCI_RX_FIS_OFFSET;
port->identify = port->block1 + AHCI_IDFY_OFFSET;
port->identify_dma = port->block1_dma + AHCI_IDFY_OFFSET;
port->log_buf = port->block1 + AHCI_SECTBUF_OFFSET;
port->log_buf_dma = port->block1_dma + AHCI_SECTBUF_OFFSET;
port->smart_buf = port->block1 + AHCI_SMARTBUF_OFFSET;
port->smart_buf_dma = port->block1_dma + AHCI_SMARTBUF_OFFSET;
return 0;
}
static int mtip_hw_get_identify(struct driver_data *dd)
{
struct smart_attr attr242;
unsigned char *buf;
int rv;
if (mtip_get_identify(dd->port, NULL) < 0)
return -EFAULT;
if (*(dd->port->identify + MTIP_FTL_REBUILD_OFFSET) ==
MTIP_FTL_REBUILD_MAGIC) {
set_bit(MTIP_PF_REBUILD_BIT, &dd->port->flags);
return MTIP_FTL_REBUILD_MAGIC;
}
mtip_dump_identify(dd->port);
rv = mtip_read_log_page(dd->port, ATA_LOG_SATA_NCQ,
dd->port->log_buf,
dd->port->log_buf_dma, 1);
if (rv) {
dev_warn(&dd->pdev->dev,
"Error in READ LOG EXT (10h) command\n");
} else {
buf = (unsigned char *)dd->port->log_buf;
if (buf[259] & 0x1) {
dev_info(&dd->pdev->dev,
"Write protect bit is set.\n");
set_bit(MTIP_DDF_WRITE_PROTECT_BIT, &dd->dd_flag);
}
if (buf[288] == 0xF7) {
dev_info(&dd->pdev->dev,
"Exceeded Tmax, drive in thermal shutdown.\n");
set_bit(MTIP_DDF_OVER_TEMP_BIT, &dd->dd_flag);
}
if (buf[288] == 0xBF) {
dev_info(&dd->pdev->dev,
"Drive indicates rebuild has failed.\n");
}
}
memset(&attr242, 0, sizeof(struct smart_attr));
if (mtip_get_smart_attr(dd->port, 242, &attr242))
dev_warn(&dd->pdev->dev,
"Unable to check write protect progress\n");
else
dev_info(&dd->pdev->dev,
"Write protect progress: %u%% (%u blocks)\n",
attr242.cur, le32_to_cpu(attr242.data));
return rv;
}
static int mtip_hw_init(struct driver_data *dd)
{
int i;
int rv;
unsigned int num_command_slots;
unsigned long timeout, timetaken;
dd->mmio = pcim_iomap_table(dd->pdev)[MTIP_ABAR];
mtip_detect_product(dd);
if (dd->product_type == MTIP_PRODUCT_UNKNOWN) {
rv = -EIO;
goto out1;
}
num_command_slots = dd->slot_groups * 32;
hba_setup(dd);
dd->port = kzalloc_node(sizeof(struct mtip_port), GFP_KERNEL,
dd->numa_node);
if (!dd->port) {
dev_err(&dd->pdev->dev,
"Memory allocation: port structure\n");
return -ENOMEM;
}
for (i = 0; i < MTIP_MAX_SLOT_GROUPS; i++)
dd->work[i].port = dd->port;
if (mtip_device_unaligned_constrained(dd))
dd->unal_qdepth = MTIP_MAX_UNALIGNED_SLOTS;
else
dd->unal_qdepth = 0;
sema_init(&dd->port->cmd_slot_unal, dd->unal_qdepth);
for (i = 0; i < MTIP_MAX_SLOT_GROUPS; i++)
spin_lock_init(&dd->port->cmd_issue_lock[i]);
dd->port->mmio = dd->mmio + PORT_OFFSET;
dd->port->dd = dd;
rv = mtip_dma_alloc(dd);
if (rv < 0)
goto out1;
for (i = 0; i < dd->slot_groups; i++) {
dd->port->s_active[i] =
dd->port->mmio + i*0x80 + PORT_SCR_ACT;
dd->port->cmd_issue[i] =
dd->port->mmio + i*0x80 + PORT_COMMAND_ISSUE;
dd->port->completed[i] =
dd->port->mmio + i*0x80 + PORT_SDBV;
}
timetaken = jiffies;
timeout = jiffies + msecs_to_jiffies(30000);
while (((readl(dd->port->mmio + PORT_SCR_STAT) & 0x0F) != 0x03) &&
time_before(jiffies, timeout)) {
mdelay(100);
}
if (unlikely(mtip_check_surprise_removal(dd->pdev))) {
timetaken = jiffies - timetaken;
dev_warn(&dd->pdev->dev,
"Surprise removal detected at %u ms\n",
jiffies_to_msecs(timetaken));
rv = -ENODEV;
goto out2 ;
}
if (unlikely(test_bit(MTIP_DDF_REMOVE_PENDING_BIT, &dd->dd_flag))) {
timetaken = jiffies - timetaken;
dev_warn(&dd->pdev->dev,
"Removal detected at %u ms\n",
jiffies_to_msecs(timetaken));
rv = -EFAULT;
goto out2;
}
if (!(readl(dd->mmio + HOST_CAP) & HOST_CAP_NZDMA)) {
if (mtip_hba_reset(dd) < 0) {
dev_err(&dd->pdev->dev,
"Card did not reset within timeout\n");
rv = -EIO;
goto out2;
}
} else {
writel(readl(dd->mmio + HOST_IRQ_STAT),
dd->mmio + HOST_IRQ_STAT);
}
mtip_init_port(dd->port);
mtip_start_port(dd->port);
rv = devm_request_irq(&dd->pdev->dev,
dd->pdev->irq,
mtip_irq_handler,
IRQF_SHARED,
dev_driver_string(&dd->pdev->dev),
dd);
if (rv) {
dev_err(&dd->pdev->dev,
"Unable to allocate IRQ %d\n", dd->pdev->irq);
goto out2;
}
irq_set_affinity_hint(dd->pdev->irq, get_cpu_mask(dd->isr_binding));
writel(readl(dd->mmio + HOST_CTL) | HOST_IRQ_EN,
dd->mmio + HOST_CTL);
init_waitqueue_head(&dd->port->svc_wait);
if (test_bit(MTIP_DDF_REMOVE_PENDING_BIT, &dd->dd_flag)) {
rv = -EFAULT;
goto out3;
}
return rv;
out3:
writel(readl(dd->mmio + HOST_CTL) & ~HOST_IRQ_EN,
dd->mmio + HOST_CTL);
irq_set_affinity_hint(dd->pdev->irq, NULL);
devm_free_irq(&dd->pdev->dev, dd->pdev->irq, dd);
out2:
mtip_deinit_port(dd->port);
mtip_dma_free(dd);
out1:
kfree(dd->port);
return rv;
}
static void mtip_standby_drive(struct driver_data *dd)
{
if (dd->sr)
return;
if (!test_bit(MTIP_PF_REBUILD_BIT, &dd->port->flags) &&
!test_bit(MTIP_DDF_SEC_LOCK_BIT, &dd->dd_flag))
if (mtip_standby_immediate(dd->port))
dev_warn(&dd->pdev->dev,
"STANDBY IMMEDIATE failed\n");
}
static int mtip_hw_exit(struct driver_data *dd)
{
if (!dd->sr) {
mtip_deinit_port(dd->port);
writel(readl(dd->mmio + HOST_CTL) & ~HOST_IRQ_EN,
dd->mmio + HOST_CTL);
}
irq_set_affinity_hint(dd->pdev->irq, NULL);
devm_free_irq(&dd->pdev->dev, dd->pdev->irq, dd);
msleep(1000);
mtip_dma_free(dd);
kfree(dd->port);
dd->port = NULL;
return 0;
}
static int mtip_hw_shutdown(struct driver_data *dd)
{
if (!dd->sr && dd->port)
mtip_standby_immediate(dd->port);
return 0;
}
static int mtip_hw_suspend(struct driver_data *dd)
{
if (mtip_standby_immediate(dd->port) != 0) {
dev_err(&dd->pdev->dev,
"Failed standby-immediate command\n");
return -EFAULT;
}
writel(readl(dd->mmio + HOST_CTL) & ~HOST_IRQ_EN,
dd->mmio + HOST_CTL);
mtip_deinit_port(dd->port);
return 0;
}
static int mtip_hw_resume(struct driver_data *dd)
{
hba_setup(dd);
if (mtip_hba_reset(dd) != 0) {
dev_err(&dd->pdev->dev,
"Unable to reset the HBA\n");
return -EFAULT;
}
mtip_init_port(dd->port);
mtip_start_port(dd->port);
writel(readl(dd->mmio + HOST_CTL) | HOST_IRQ_EN,
dd->mmio + HOST_CTL);
return 0;
}
static int rssd_disk_name_format(char *prefix,
int index,
char *buf,
int buflen)
{
const int base = 'z' - 'a' + 1;
char *begin = buf + strlen(prefix);
char *end = buf + buflen;
char *p;
int unit;
p = end - 1;
*p = '\0';
unit = base;
do {
if (p == begin)
return -EINVAL;
*--p = 'a' + (index % unit);
index = (index / unit) - 1;
} while (index >= 0);
memmove(begin, p, end - p);
memcpy(buf, prefix, strlen(prefix));
return 0;
}
static int mtip_block_ioctl(struct block_device *dev,
fmode_t mode,
unsigned cmd,
unsigned long arg)
{
struct driver_data *dd = dev->bd_disk->private_data;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (!dd)
return -ENOTTY;
if (unlikely(test_bit(MTIP_DDF_REMOVE_PENDING_BIT, &dd->dd_flag)))
return -ENOTTY;
switch (cmd) {
case BLKFLSBUF:
return -ENOTTY;
default:
return mtip_hw_ioctl(dd, cmd, arg);
}
}
static int mtip_block_compat_ioctl(struct block_device *dev,
fmode_t mode,
unsigned cmd,
unsigned long arg)
{
struct driver_data *dd = dev->bd_disk->private_data;
if (!capable(CAP_SYS_ADMIN))
return -EACCES;
if (!dd)
return -ENOTTY;
if (unlikely(test_bit(MTIP_DDF_REMOVE_PENDING_BIT, &dd->dd_flag)))
return -ENOTTY;
switch (cmd) {
case BLKFLSBUF:
return -ENOTTY;
case HDIO_DRIVE_TASKFILE: {
struct mtip_compat_ide_task_request_s __user *compat_req_task;
ide_task_request_t req_task;
int compat_tasksize, outtotal, ret;
compat_tasksize =
sizeof(struct mtip_compat_ide_task_request_s);
compat_req_task =
(struct mtip_compat_ide_task_request_s __user *) arg;
if (copy_from_user(&req_task, (void __user *) arg,
compat_tasksize - (2 * sizeof(compat_long_t))))
return -EFAULT;
if (get_user(req_task.out_size, &compat_req_task->out_size))
return -EFAULT;
if (get_user(req_task.in_size, &compat_req_task->in_size))
return -EFAULT;
outtotal = sizeof(struct mtip_compat_ide_task_request_s);
ret = exec_drive_taskfile(dd, (void __user *) arg,
&req_task, outtotal);
if (copy_to_user((void __user *) arg, &req_task,
compat_tasksize -
(2 * sizeof(compat_long_t))))
return -EFAULT;
if (put_user(req_task.out_size, &compat_req_task->out_size))
return -EFAULT;
if (put_user(req_task.in_size, &compat_req_task->in_size))
return -EFAULT;
return ret;
}
default:
return mtip_hw_ioctl(dd, cmd, arg);
}
}
static int mtip_block_getgeo(struct block_device *dev,
struct hd_geometry *geo)
{
struct driver_data *dd = dev->bd_disk->private_data;
sector_t capacity;
if (!dd)
return -ENOTTY;
if (!(mtip_hw_get_capacity(dd, &capacity))) {
dev_warn(&dd->pdev->dev,
"Could not get drive capacity.\n");
return -ENOTTY;
}
geo->heads = 224;
geo->sectors = 56;
sector_div(capacity, (geo->heads * geo->sectors));
geo->cylinders = capacity;
return 0;
}
static inline bool is_se_active(struct driver_data *dd)
{
if (unlikely(test_bit(MTIP_PF_SE_ACTIVE_BIT, &dd->port->flags))) {
if (dd->port->ic_pause_timer) {
unsigned long to = dd->port->ic_pause_timer +
msecs_to_jiffies(1000);
if (time_after(jiffies, to)) {
clear_bit(MTIP_PF_SE_ACTIVE_BIT,
&dd->port->flags);
clear_bit(MTIP_DDF_SEC_LOCK_BIT, &dd->dd_flag);
dd->port->ic_pause_timer = 0;
wake_up_interruptible(&dd->port->svc_wait);
return false;
}
}
return true;
}
return false;
}
static int mtip_submit_request(struct blk_mq_hw_ctx *hctx, struct request *rq)
{
struct driver_data *dd = hctx->queue->queuedata;
struct mtip_cmd *cmd = blk_mq_rq_to_pdu(rq);
unsigned int nents;
if (is_se_active(dd))
return -ENODATA;
if (unlikely(dd->dd_flag & MTIP_DDF_STOP_IO)) {
if (unlikely(test_bit(MTIP_DDF_REMOVE_PENDING_BIT,
&dd->dd_flag))) {
return -ENXIO;
}
if (unlikely(test_bit(MTIP_DDF_OVER_TEMP_BIT, &dd->dd_flag))) {
return -ENODATA;
}
if (unlikely(test_bit(MTIP_DDF_WRITE_PROTECT_BIT,
&dd->dd_flag) &&
rq_data_dir(rq))) {
return -ENODATA;
}
if (unlikely(test_bit(MTIP_DDF_SEC_LOCK_BIT, &dd->dd_flag)))
return -ENODATA;
if (test_bit(MTIP_DDF_REBUILD_FAILED_BIT, &dd->dd_flag))
return -ENXIO;
}
if (rq->cmd_flags & REQ_DISCARD) {
int err;
err = mtip_send_trim(dd, blk_rq_pos(rq), blk_rq_sectors(rq));
blk_mq_end_request(rq, err);
return 0;
}
nents = blk_rq_map_sg(hctx->queue, rq, cmd->sg);
mtip_hw_submit_io(dd, rq, cmd, nents, hctx);
return 0;
}
static bool mtip_check_unal_depth(struct blk_mq_hw_ctx *hctx,
struct request *rq)
{
struct driver_data *dd = hctx->queue->queuedata;
struct mtip_cmd *cmd = blk_mq_rq_to_pdu(rq);
if (rq_data_dir(rq) == READ || !dd->unal_qdepth)
return false;
if (blk_rq_sectors(rq) <= 64) {
if ((blk_rq_pos(rq) & 7) || (blk_rq_sectors(rq) & 7))
cmd->unaligned = 1;
}
if (cmd->unaligned && down_trylock(&dd->port->cmd_slot_unal))
return true;
return false;
}
static int mtip_queue_rq(struct blk_mq_hw_ctx *hctx,
const struct blk_mq_queue_data *bd)
{
struct request *rq = bd->rq;
int ret;
if (unlikely(mtip_check_unal_depth(hctx, rq)))
return BLK_MQ_RQ_QUEUE_BUSY;
blk_mq_start_request(rq);
ret = mtip_submit_request(hctx, rq);
if (likely(!ret))
return BLK_MQ_RQ_QUEUE_OK;
rq->errors = ret;
return BLK_MQ_RQ_QUEUE_ERROR;
}
static void mtip_free_cmd(void *data, struct request *rq,
unsigned int hctx_idx, unsigned int request_idx)
{
struct driver_data *dd = data;
struct mtip_cmd *cmd = blk_mq_rq_to_pdu(rq);
if (!cmd->command)
return;
dmam_free_coherent(&dd->pdev->dev, CMD_DMA_ALLOC_SZ,
cmd->command, cmd->command_dma);
}
static int mtip_init_cmd(void *data, struct request *rq, unsigned int hctx_idx,
unsigned int request_idx, unsigned int numa_node)
{
struct driver_data *dd = data;
struct mtip_cmd *cmd = blk_mq_rq_to_pdu(rq);
u32 host_cap_64 = readl(dd->mmio + HOST_CAP) & HOST_CAP_64;
if (request_idx >= MTIP_MAX_COMMAND_SLOTS)
return 0;
cmd->command = dmam_alloc_coherent(&dd->pdev->dev, CMD_DMA_ALLOC_SZ,
&cmd->command_dma, GFP_KERNEL);
if (!cmd->command)
return -ENOMEM;
memset(cmd->command, 0, CMD_DMA_ALLOC_SZ);
cmd->command_header = dd->port->command_list +
(sizeof(struct mtip_cmd_hdr) * request_idx);
cmd->command_header_dma = dd->port->command_list_dma +
(sizeof(struct mtip_cmd_hdr) * request_idx);
if (host_cap_64)
cmd->command_header->ctbau = __force_bit2int cpu_to_le32((cmd->command_dma >> 16) >> 16);
cmd->command_header->ctba = __force_bit2int cpu_to_le32(cmd->command_dma & 0xFFFFFFFF);
sg_init_table(cmd->sg, MTIP_MAX_SG);
return 0;
}
static int mtip_block_initialize(struct driver_data *dd)
{
int rv = 0, wait_for_rebuild = 0;
sector_t capacity;
unsigned int index = 0;
struct kobject *kobj;
if (dd->disk)
goto skip_create_disk;
if (mtip_hw_init(dd)) {
rv = -EINVAL;
goto protocol_init_error;
}
dd->disk = alloc_disk_node(MTIP_MAX_MINORS, dd->numa_node);
if (dd->disk == NULL) {
dev_err(&dd->pdev->dev,
"Unable to allocate gendisk structure\n");
rv = -EINVAL;
goto alloc_disk_error;
}
do {
if (!ida_pre_get(&rssd_index_ida, GFP_KERNEL))
goto ida_get_error;
spin_lock(&rssd_index_lock);
rv = ida_get_new(&rssd_index_ida, &index);
spin_unlock(&rssd_index_lock);
} while (rv == -EAGAIN);
if (rv)
goto ida_get_error;
rv = rssd_disk_name_format("rssd",
index,
dd->disk->disk_name,
DISK_NAME_LEN);
if (rv)
goto disk_index_error;
dd->disk->driverfs_dev = &dd->pdev->dev;
dd->disk->major = dd->major;
dd->disk->first_minor = index * MTIP_MAX_MINORS;
dd->disk->minors = MTIP_MAX_MINORS;
dd->disk->fops = &mtip_block_ops;
dd->disk->private_data = dd;
dd->index = index;
mtip_hw_debugfs_init(dd);
skip_create_disk:
memset(&dd->tags, 0, sizeof(dd->tags));
dd->tags.ops = &mtip_mq_ops;
dd->tags.nr_hw_queues = 1;
dd->tags.queue_depth = MTIP_MAX_COMMAND_SLOTS;
dd->tags.reserved_tags = 1;
dd->tags.cmd_size = sizeof(struct mtip_cmd);
dd->tags.numa_node = dd->numa_node;
dd->tags.flags = BLK_MQ_F_SHOULD_MERGE;
dd->tags.driver_data = dd;
rv = blk_mq_alloc_tag_set(&dd->tags);
if (rv) {
dev_err(&dd->pdev->dev,
"Unable to allocate request queue\n");
goto block_queue_alloc_init_error;
}
dd->queue = blk_mq_init_queue(&dd->tags);
if (IS_ERR(dd->queue)) {
dev_err(&dd->pdev->dev,
"Unable to allocate request queue\n");
rv = -ENOMEM;
goto block_queue_alloc_init_error;
}
dd->disk->queue = dd->queue;
dd->queue->queuedata = dd;
wait_for_rebuild = mtip_hw_get_identify(dd);
if (wait_for_rebuild < 0) {
dev_err(&dd->pdev->dev,
"Protocol layer initialization failed\n");
rv = -EINVAL;
goto init_hw_cmds_error;
}
if (wait_for_rebuild == MTIP_FTL_REBUILD_MAGIC)
goto start_service_thread;
set_bit(QUEUE_FLAG_NONROT, &dd->queue->queue_flags);
clear_bit(QUEUE_FLAG_ADD_RANDOM, &dd->queue->queue_flags);
blk_queue_max_segments(dd->queue, MTIP_MAX_SG);
blk_queue_physical_block_size(dd->queue, 4096);
blk_queue_max_hw_sectors(dd->queue, 0xffff);
blk_queue_max_segment_size(dd->queue, 0x400000);
blk_queue_io_min(dd->queue, 4096);
blk_queue_bounce_limit(dd->queue, dd->pdev->dma_mask);
blk_queue_flush(dd->queue, 0);
if (dd->trim_supp == true) {
set_bit(QUEUE_FLAG_DISCARD, &dd->queue->queue_flags);
dd->queue->limits.discard_granularity = 4096;
blk_queue_max_discard_sectors(dd->queue,
MTIP_MAX_TRIM_ENTRY_LEN * MTIP_MAX_TRIM_ENTRIES);
dd->queue->limits.discard_zeroes_data = 0;
}
if (!(mtip_hw_get_capacity(dd, &capacity))) {
dev_warn(&dd->pdev->dev,
"Could not read drive capacity\n");
rv = -EIO;
goto read_capacity_error;
}
set_capacity(dd->disk, capacity);
add_disk(dd->disk);
dd->bdev = bdget_disk(dd->disk, 0);
kobj = kobject_get(&disk_to_dev(dd->disk)->kobj);
if (kobj) {
mtip_hw_sysfs_init(dd, kobj);
kobject_put(kobj);
}
if (dd->mtip_svc_handler) {
set_bit(MTIP_DDF_INIT_DONE_BIT, &dd->dd_flag);
return rv;
}
start_service_thread:
dd->mtip_svc_handler = kthread_create_on_node(mtip_service_thread,
dd, dd->numa_node,
"mtip_svc_thd_%02d", index);
if (IS_ERR(dd->mtip_svc_handler)) {
dev_err(&dd->pdev->dev, "service thread failed to start\n");
dd->mtip_svc_handler = NULL;
rv = -EFAULT;
goto kthread_run_error;
}
wake_up_process(dd->mtip_svc_handler);
if (wait_for_rebuild == MTIP_FTL_REBUILD_MAGIC)
rv = wait_for_rebuild;
return rv;
kthread_run_error:
bdput(dd->bdev);
dd->bdev = NULL;
del_gendisk(dd->disk);
read_capacity_error:
init_hw_cmds_error:
blk_cleanup_queue(dd->queue);
blk_mq_free_tag_set(&dd->tags);
block_queue_alloc_init_error:
mtip_hw_debugfs_exit(dd);
disk_index_error:
spin_lock(&rssd_index_lock);
ida_remove(&rssd_index_ida, index);
spin_unlock(&rssd_index_lock);
ida_get_error:
put_disk(dd->disk);
alloc_disk_error:
mtip_hw_exit(dd);
protocol_init_error:
return rv;
}
static int mtip_block_remove(struct driver_data *dd)
{
struct kobject *kobj;
mtip_hw_debugfs_exit(dd);
if (dd->mtip_svc_handler) {
set_bit(MTIP_PF_SVC_THD_STOP_BIT, &dd->port->flags);
wake_up_interruptible(&dd->port->svc_wait);
kthread_stop(dd->mtip_svc_handler);
}
if (test_bit(MTIP_DDF_INIT_DONE_BIT, &dd->dd_flag)) {
kobj = kobject_get(&disk_to_dev(dd->disk)->kobj);
if (kobj) {
mtip_hw_sysfs_exit(dd, kobj);
kobject_put(kobj);
}
}
if (!dd->sr)
mtip_standby_drive(dd);
else
dev_info(&dd->pdev->dev, "device %s surprise removal\n",
dd->disk->disk_name);
if (dd->bdev) {
bdput(dd->bdev);
dd->bdev = NULL;
}
if (dd->disk) {
del_gendisk(dd->disk);
if (dd->disk->queue) {
blk_cleanup_queue(dd->queue);
blk_mq_free_tag_set(&dd->tags);
dd->queue = NULL;
}
put_disk(dd->disk);
}
dd->disk = NULL;
spin_lock(&rssd_index_lock);
ida_remove(&rssd_index_ida, dd->index);
spin_unlock(&rssd_index_lock);
mtip_hw_exit(dd);
return 0;
}
static int mtip_block_shutdown(struct driver_data *dd)
{
mtip_hw_shutdown(dd);
if (dd->disk) {
dev_info(&dd->pdev->dev,
"Shutting down %s ...\n", dd->disk->disk_name);
del_gendisk(dd->disk);
if (dd->disk->queue) {
blk_cleanup_queue(dd->queue);
blk_mq_free_tag_set(&dd->tags);
}
put_disk(dd->disk);
dd->disk = NULL;
dd->queue = NULL;
}
spin_lock(&rssd_index_lock);
ida_remove(&rssd_index_ida, dd->index);
spin_unlock(&rssd_index_lock);
return 0;
}
static int mtip_block_suspend(struct driver_data *dd)
{
dev_info(&dd->pdev->dev,
"Suspending %s ...\n", dd->disk->disk_name);
mtip_hw_suspend(dd);
return 0;
}
static int mtip_block_resume(struct driver_data *dd)
{
dev_info(&dd->pdev->dev, "Resuming %s ...\n",
dd->disk->disk_name);
mtip_hw_resume(dd);
return 0;
}
static void drop_cpu(int cpu)
{
cpu_use[cpu]--;
}
static int get_least_used_cpu_on_node(int node)
{
int cpu, least_used_cpu, least_cnt;
const struct cpumask *node_mask;
node_mask = cpumask_of_node(node);
least_used_cpu = cpumask_first(node_mask);
least_cnt = cpu_use[least_used_cpu];
cpu = least_used_cpu;
for_each_cpu(cpu, node_mask) {
if (cpu_use[cpu] < least_cnt) {
least_used_cpu = cpu;
least_cnt = cpu_use[cpu];
}
}
cpu_use[least_used_cpu]++;
return least_used_cpu;
}
static inline int mtip_get_next_rr_node(void)
{
static int next_node = -1;
if (next_node == -1) {
next_node = first_online_node;
return next_node;
}
next_node = next_online_node(next_node);
if (next_node == MAX_NUMNODES)
next_node = first_online_node;
return next_node;
}
static void mtip_disable_link_opts(struct driver_data *dd, struct pci_dev *pdev)
{
int pos;
unsigned short pcie_dev_ctrl;
pos = pci_find_capability(pdev, PCI_CAP_ID_EXP);
if (pos) {
pci_read_config_word(pdev,
pos + PCI_EXP_DEVCTL,
&pcie_dev_ctrl);
if (pcie_dev_ctrl & (1 << 11) ||
pcie_dev_ctrl & (1 << 4)) {
dev_info(&dd->pdev->dev,
"Disabling ERO/No-Snoop on bridge device %04x:%04x\n",
pdev->vendor, pdev->device);
pcie_dev_ctrl &= ~(PCI_EXP_DEVCTL_NOSNOOP_EN |
PCI_EXP_DEVCTL_RELAX_EN);
pci_write_config_word(pdev,
pos + PCI_EXP_DEVCTL,
pcie_dev_ctrl);
}
}
}
static void mtip_fix_ero_nosnoop(struct driver_data *dd, struct pci_dev *pdev)
{
if (pdev->bus && pdev->bus->self) {
if (pdev->bus->self->vendor == PCI_VENDOR_ID_ATI &&
((pdev->bus->self->device & 0xff00) == 0x5a00)) {
mtip_disable_link_opts(dd, pdev->bus->self);
} else {
struct pci_dev *parent_dev = pdev->bus->self;
if (parent_dev->bus &&
parent_dev->bus->parent &&
parent_dev->bus->parent->self &&
parent_dev->bus->parent->self->vendor ==
PCI_VENDOR_ID_ATI &&
(parent_dev->bus->parent->self->device &
0xff00) == 0x5a00) {
mtip_disable_link_opts(dd,
parent_dev->bus->parent->self);
}
}
}
}
static int mtip_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int rv = 0;
struct driver_data *dd = NULL;
char cpu_list[256];
const struct cpumask *node_mask;
int cpu, i = 0, j = 0;
int my_node = NUMA_NO_NODE;
unsigned long flags;
my_node = pcibus_to_node(pdev->bus);
if (my_node != NUMA_NO_NODE) {
if (!node_online(my_node))
my_node = mtip_get_next_rr_node();
} else {
dev_info(&pdev->dev, "Kernel not reporting proximity, choosing a node\n");
my_node = mtip_get_next_rr_node();
}
dev_info(&pdev->dev, "NUMA node %d (closest: %d,%d, probe on %d:%d)\n",
my_node, pcibus_to_node(pdev->bus), dev_to_node(&pdev->dev),
cpu_to_node(raw_smp_processor_id()), raw_smp_processor_id());
dd = kzalloc_node(sizeof(struct driver_data), GFP_KERNEL, my_node);
if (dd == NULL) {
dev_err(&pdev->dev,
"Unable to allocate memory for driver data\n");
return -ENOMEM;
}
pci_set_drvdata(pdev, dd);
rv = pcim_enable_device(pdev);
if (rv < 0) {
dev_err(&pdev->dev, "Unable to enable device\n");
goto iomap_err;
}
rv = pcim_iomap_regions(pdev, 1 << MTIP_ABAR, MTIP_DRV_NAME);
if (rv < 0) {
dev_err(&pdev->dev, "Unable to map regions\n");
goto iomap_err;
}
if (!pci_set_dma_mask(pdev, DMA_BIT_MASK(64))) {
rv = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
if (rv) {
rv = pci_set_consistent_dma_mask(pdev,
DMA_BIT_MASK(32));
if (rv) {
dev_warn(&pdev->dev,
"64-bit DMA enable failed\n");
goto setmask_err;
}
}
}
dd->major = mtip_major;
dd->instance = instance;
dd->pdev = pdev;
dd->numa_node = my_node;
INIT_LIST_HEAD(&dd->online_list);
INIT_LIST_HEAD(&dd->remove_list);
memset(dd->workq_name, 0, 32);
snprintf(dd->workq_name, 31, "mtipq%d", dd->instance);
dd->isr_workq = create_workqueue(dd->workq_name);
if (!dd->isr_workq) {
dev_warn(&pdev->dev, "Can't create wq %d\n", dd->instance);
rv = -ENOMEM;
goto block_initialize_err;
}
memset(cpu_list, 0, sizeof(cpu_list));
node_mask = cpumask_of_node(dd->numa_node);
if (!cpumask_empty(node_mask)) {
for_each_cpu(cpu, node_mask)
{
snprintf(&cpu_list[j], 256 - j, "%d ", cpu);
j = strlen(cpu_list);
}
dev_info(&pdev->dev, "Node %d on package %d has %d cpu(s): %s\n",
dd->numa_node,
topology_physical_package_id(cpumask_first(node_mask)),
nr_cpus_node(dd->numa_node),
cpu_list);
} else
dev_dbg(&pdev->dev, "mtip32xx: node_mask empty\n");
dd->isr_binding = get_least_used_cpu_on_node(dd->numa_node);
dev_info(&pdev->dev, "Initial IRQ binding node:cpu %d:%d\n",
cpu_to_node(dd->isr_binding), dd->isr_binding);
dd->work[0].cpu_binding = dd->isr_binding;
dd->work[1].cpu_binding = get_least_used_cpu_on_node(dd->numa_node);
dd->work[2].cpu_binding = get_least_used_cpu_on_node(dd->numa_node);
dd->work[3].cpu_binding = dd->work[0].cpu_binding;
dd->work[4].cpu_binding = dd->work[1].cpu_binding;
dd->work[5].cpu_binding = dd->work[2].cpu_binding;
dd->work[6].cpu_binding = dd->work[2].cpu_binding;
dd->work[7].cpu_binding = dd->work[1].cpu_binding;
for_each_present_cpu(cpu) {
memset(cpu_list, 0, sizeof(cpu_list));
for (i = 0, j = 0; i < MTIP_MAX_SLOT_GROUPS; i++) {
if (dd->work[i].cpu_binding == cpu) {
snprintf(&cpu_list[j], 256 - j, "%d ", i);
j = strlen(cpu_list);
}
}
if (j)
dev_info(&pdev->dev, "CPU %d: WQs %s\n", cpu, cpu_list);
}
INIT_WORK(&dd->work[0].work, mtip_workq_sdbf0);
INIT_WORK(&dd->work[1].work, mtip_workq_sdbf1);
INIT_WORK(&dd->work[2].work, mtip_workq_sdbf2);
INIT_WORK(&dd->work[3].work, mtip_workq_sdbf3);
INIT_WORK(&dd->work[4].work, mtip_workq_sdbf4);
INIT_WORK(&dd->work[5].work, mtip_workq_sdbf5);
INIT_WORK(&dd->work[6].work, mtip_workq_sdbf6);
INIT_WORK(&dd->work[7].work, mtip_workq_sdbf7);
pci_set_master(pdev);
rv = pci_enable_msi(pdev);
if (rv) {
dev_warn(&pdev->dev,
"Unable to enable MSI interrupt.\n");
goto msi_initialize_err;
}
mtip_fix_ero_nosnoop(dd, pdev);
rv = mtip_block_initialize(dd);
if (rv < 0) {
dev_err(&pdev->dev,
"Unable to initialize block layer\n");
goto block_initialize_err;
}
instance++;
if (rv != MTIP_FTL_REBUILD_MAGIC)
set_bit(MTIP_DDF_INIT_DONE_BIT, &dd->dd_flag);
else
rv = 0;
spin_lock_irqsave(&dev_lock, flags);
list_add(&dd->online_list, &online_list);
spin_unlock_irqrestore(&dev_lock, flags);
goto done;
block_initialize_err:
pci_disable_msi(pdev);
msi_initialize_err:
if (dd->isr_workq) {
flush_workqueue(dd->isr_workq);
destroy_workqueue(dd->isr_workq);
drop_cpu(dd->work[0].cpu_binding);
drop_cpu(dd->work[1].cpu_binding);
drop_cpu(dd->work[2].cpu_binding);
}
setmask_err:
pcim_iounmap_regions(pdev, 1 << MTIP_ABAR);
iomap_err:
kfree(dd);
pci_set_drvdata(pdev, NULL);
return rv;
done:
return rv;
}
static void mtip_pci_remove(struct pci_dev *pdev)
{
struct driver_data *dd = pci_get_drvdata(pdev);
unsigned long flags, to;
set_bit(MTIP_DDF_REMOVE_PENDING_BIT, &dd->dd_flag);
spin_lock_irqsave(&dev_lock, flags);
list_del_init(&dd->online_list);
list_add(&dd->remove_list, &removing_list);
spin_unlock_irqrestore(&dev_lock, flags);
mtip_check_surprise_removal(pdev);
synchronize_irq(dd->pdev->irq);
to = jiffies + msecs_to_jiffies(4000);
do {
msleep(20);
} while (atomic_read(&dd->irq_workers_active) != 0 &&
time_before(jiffies, to));
if (atomic_read(&dd->irq_workers_active) != 0) {
dev_warn(&dd->pdev->dev,
"Completion workers still active!\n");
}
blk_mq_stop_hw_queues(dd->queue);
mtip_block_remove(dd);
if (dd->isr_workq) {
flush_workqueue(dd->isr_workq);
destroy_workqueue(dd->isr_workq);
drop_cpu(dd->work[0].cpu_binding);
drop_cpu(dd->work[1].cpu_binding);
drop_cpu(dd->work[2].cpu_binding);
}
pci_disable_msi(pdev);
spin_lock_irqsave(&dev_lock, flags);
list_del_init(&dd->remove_list);
spin_unlock_irqrestore(&dev_lock, flags);
kfree(dd);
pcim_iounmap_regions(pdev, 1 << MTIP_ABAR);
pci_set_drvdata(pdev, NULL);
}
static int mtip_pci_suspend(struct pci_dev *pdev, pm_message_t mesg)
{
int rv = 0;
struct driver_data *dd = pci_get_drvdata(pdev);
if (!dd) {
dev_err(&pdev->dev,
"Driver private datastructure is NULL\n");
return -EFAULT;
}
set_bit(MTIP_DDF_RESUME_BIT, &dd->dd_flag);
rv = mtip_block_suspend(dd);
if (rv < 0) {
dev_err(&pdev->dev,
"Failed to suspend controller\n");
return rv;
}
pci_save_state(pdev);
pci_disable_device(pdev);
pci_set_power_state(pdev, PCI_D3hot);
return rv;
}
static int mtip_pci_resume(struct pci_dev *pdev)
{
int rv = 0;
struct driver_data *dd;
dd = pci_get_drvdata(pdev);
if (!dd) {
dev_err(&pdev->dev,
"Driver private datastructure is NULL\n");
return -EFAULT;
}
pci_set_power_state(pdev, PCI_D0);
pci_restore_state(pdev);
rv = pcim_enable_device(pdev);
if (rv < 0) {
dev_err(&pdev->dev,
"Failed to enable card during resume\n");
goto err;
}
pci_set_master(pdev);
rv = mtip_block_resume(dd);
if (rv < 0)
dev_err(&pdev->dev, "Unable to resume\n");
err:
clear_bit(MTIP_DDF_RESUME_BIT, &dd->dd_flag);
return rv;
}
static void mtip_pci_shutdown(struct pci_dev *pdev)
{
struct driver_data *dd = pci_get_drvdata(pdev);
if (dd)
mtip_block_shutdown(dd);
}
static int __init mtip_init(void)
{
int error;
pr_info(MTIP_DRV_NAME " Version " MTIP_DRV_VERSION "\n");
spin_lock_init(&dev_lock);
INIT_LIST_HEAD(&online_list);
INIT_LIST_HEAD(&removing_list);
error = register_blkdev(0, MTIP_DRV_NAME);
if (error <= 0) {
pr_err("Unable to register block device (%d)\n",
error);
return -EBUSY;
}
mtip_major = error;
dfs_parent = debugfs_create_dir("rssd", NULL);
if (IS_ERR_OR_NULL(dfs_parent)) {
pr_warn("Error creating debugfs parent\n");
dfs_parent = NULL;
}
if (dfs_parent) {
dfs_device_status = debugfs_create_file("device_status",
S_IRUGO, dfs_parent, NULL,
&mtip_device_status_fops);
if (IS_ERR_OR_NULL(dfs_device_status)) {
pr_err("Error creating device_status node\n");
dfs_device_status = NULL;
}
}
error = pci_register_driver(&mtip_pci_driver);
if (error) {
debugfs_remove(dfs_parent);
unregister_blkdev(mtip_major, MTIP_DRV_NAME);
}
return error;
}
static void __exit mtip_exit(void)
{
unregister_blkdev(mtip_major, MTIP_DRV_NAME);
pci_unregister_driver(&mtip_pci_driver);
debugfs_remove_recursive(dfs_parent);
}
