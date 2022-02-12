static enum blk_eh_timer_return qla4xxx_eh_cmd_timed_out(struct scsi_cmnd *sc)
{
struct iscsi_cls_session *session;
struct ddb_entry *ddb_entry;
session = starget_to_session(scsi_target(sc->device));
ddb_entry = session->dd_data;
if (atomic_read(&ddb_entry->state) != DDB_STATE_ONLINE)
return BLK_EH_RESET_TIMER;
else
return BLK_EH_NOT_HANDLED;
}
static void qla4xxx_recovery_timedout(struct iscsi_cls_session *session)
{
struct ddb_entry *ddb_entry = session->dd_data;
struct scsi_qla_host *ha = ddb_entry->ha;
if (atomic_read(&ddb_entry->state) != DDB_STATE_ONLINE) {
atomic_set(&ddb_entry->state, DDB_STATE_DEAD);
DEBUG2(printk("scsi%ld: %s: ddb [%d] session recovery timeout "
"of (%d) secs exhausted, marking device DEAD.\n",
ha->host_no, __func__, ddb_entry->fw_ddb_index,
ddb_entry->sess->recovery_tmo));
}
}
static int qla4xxx_host_get_param(struct Scsi_Host *shost,
enum iscsi_host_param param, char *buf)
{
struct scsi_qla_host *ha = to_qla_host(shost);
int len;
switch (param) {
case ISCSI_HOST_PARAM_HWADDRESS:
len = sysfs_format_mac(buf, ha->my_mac, MAC_ADDR_LEN);
break;
case ISCSI_HOST_PARAM_IPADDRESS:
len = sprintf(buf, "%d.%d.%d.%d\n", ha->ip_address[0],
ha->ip_address[1], ha->ip_address[2],
ha->ip_address[3]);
break;
case ISCSI_HOST_PARAM_INITIATOR_NAME:
len = sprintf(buf, "%s\n", ha->name_string);
break;
default:
return -ENOSYS;
}
return len;
}
static int qla4xxx_sess_get_param(struct iscsi_cls_session *sess,
enum iscsi_param param, char *buf)
{
struct ddb_entry *ddb_entry = sess->dd_data;
int len;
switch (param) {
case ISCSI_PARAM_TARGET_NAME:
len = snprintf(buf, PAGE_SIZE - 1, "%s\n",
ddb_entry->iscsi_name);
break;
case ISCSI_PARAM_TPGT:
len = sprintf(buf, "%u\n", ddb_entry->tpgt);
break;
case ISCSI_PARAM_TARGET_ALIAS:
len = snprintf(buf, PAGE_SIZE - 1, "%s\n",
ddb_entry->iscsi_alias);
break;
default:
return -ENOSYS;
}
return len;
}
static int qla4xxx_conn_get_param(struct iscsi_cls_conn *conn,
enum iscsi_param param, char *buf)
{
struct iscsi_cls_session *session;
struct ddb_entry *ddb_entry;
int len;
session = iscsi_dev_to_session(conn->dev.parent);
ddb_entry = session->dd_data;
switch (param) {
case ISCSI_PARAM_CONN_PORT:
len = sprintf(buf, "%hu\n", ddb_entry->port);
break;
case ISCSI_PARAM_CONN_ADDRESS:
len = sprintf(buf, "%pI4\n", &ddb_entry->ip_addr);
break;
default:
return -ENOSYS;
}
return len;
}
static int qla4xxx_tgt_dscvr(struct Scsi_Host *shost,
enum iscsi_tgt_dscvr type, uint32_t enable,
struct sockaddr *dst_addr)
{
struct scsi_qla_host *ha;
struct sockaddr_in *addr;
struct sockaddr_in6 *addr6;
int ret = 0;
ha = (struct scsi_qla_host *) shost->hostdata;
switch (type) {
case ISCSI_TGT_DSCVR_SEND_TARGETS:
if (dst_addr->sa_family == AF_INET) {
addr = (struct sockaddr_in *)dst_addr;
if (qla4xxx_send_tgts(ha, (char *)&addr->sin_addr,
addr->sin_port) != QLA_SUCCESS)
ret = -EIO;
} else if (dst_addr->sa_family == AF_INET6) {
addr6 = (struct sockaddr_in6 *)dst_addr;
if (qla4xxx_send_tgts(ha, (char *)&addr6->sin6_addr,
addr6->sin6_port) != QLA_SUCCESS)
ret = -EIO;
} else
ret = -ENOSYS;
break;
default:
ret = -ENOSYS;
}
return ret;
}
void qla4xxx_destroy_sess(struct ddb_entry *ddb_entry)
{
if (!ddb_entry->sess)
return;
if (ddb_entry->conn) {
atomic_set(&ddb_entry->state, DDB_STATE_DEAD);
iscsi_remove_session(ddb_entry->sess);
}
iscsi_free_session(ddb_entry->sess);
}
int qla4xxx_add_sess(struct ddb_entry *ddb_entry)
{
int err;
ddb_entry->sess->recovery_tmo = ql4xsess_recovery_tmo;
err = iscsi_add_session(ddb_entry->sess, ddb_entry->fw_ddb_index);
if (err) {
DEBUG2(printk(KERN_ERR "Could not add session.\n"));
return err;
}
ddb_entry->conn = iscsi_create_conn(ddb_entry->sess, 0, 0);
if (!ddb_entry->conn) {
iscsi_remove_session(ddb_entry->sess);
DEBUG2(printk(KERN_ERR "Could not add connection.\n"));
return -ENOMEM;
}
iscsi_unblock_session(ddb_entry->sess);
return 0;
}
struct ddb_entry *qla4xxx_alloc_sess(struct scsi_qla_host *ha)
{
struct ddb_entry *ddb_entry;
struct iscsi_cls_session *sess;
sess = iscsi_alloc_session(ha->host, &qla4xxx_iscsi_transport,
sizeof(struct ddb_entry));
if (!sess)
return NULL;
ddb_entry = sess->dd_data;
memset(ddb_entry, 0, sizeof(*ddb_entry));
ddb_entry->ha = ha;
ddb_entry->sess = sess;
return ddb_entry;
}
static void qla4xxx_scan_start(struct Scsi_Host *shost)
{
struct scsi_qla_host *ha = shost_priv(shost);
struct ddb_entry *ddb_entry, *ddbtemp;
list_for_each_entry_safe(ddb_entry, ddbtemp, &ha->ddb_list, list) {
if (ddb_entry->fw_ddb_device_state == DDB_DS_SESSION_ACTIVE)
qla4xxx_add_sess(ddb_entry);
}
}
static void qla4xxx_start_timer(struct scsi_qla_host *ha, void *func,
unsigned long interval)
{
DEBUG(printk("scsi: %s: Starting timer thread for adapter %d\n",
__func__, ha->host->host_no));
init_timer(&ha->timer);
ha->timer.expires = jiffies + interval * HZ;
ha->timer.data = (unsigned long)ha;
ha->timer.function = (void (*)(unsigned long))func;
add_timer(&ha->timer);
ha->timer_active = 1;
}
static void qla4xxx_stop_timer(struct scsi_qla_host *ha)
{
del_timer_sync(&ha->timer);
ha->timer_active = 0;
}
void qla4xxx_mark_device_missing(struct scsi_qla_host *ha,
struct ddb_entry *ddb_entry)
{
if ((atomic_read(&ddb_entry->state) != DDB_STATE_DEAD)) {
atomic_set(&ddb_entry->state, DDB_STATE_MISSING);
DEBUG2(printk("scsi%ld: ddb [%d] marked MISSING\n",
ha->host_no, ddb_entry->fw_ddb_index));
} else
DEBUG2(printk("scsi%ld: ddb [%d] DEAD\n", ha->host_no,
ddb_entry->fw_ddb_index))
iscsi_block_session(ddb_entry->sess);
iscsi_conn_error_event(ddb_entry->conn, ISCSI_ERR_CONN_FAILED);
}
void qla4xxx_mark_all_devices_missing(struct scsi_qla_host *ha)
{
struct ddb_entry *ddb_entry, *ddbtemp;
list_for_each_entry_safe(ddb_entry, ddbtemp, &ha->ddb_list, list) {
qla4xxx_mark_device_missing(ha, ddb_entry);
}
}
static struct srb* qla4xxx_get_new_srb(struct scsi_qla_host *ha,
struct ddb_entry *ddb_entry,
struct scsi_cmnd *cmd)
{
struct srb *srb;
srb = mempool_alloc(ha->srb_mempool, GFP_ATOMIC);
if (!srb)
return srb;
kref_init(&srb->srb_ref);
srb->ha = ha;
srb->ddb = ddb_entry;
srb->cmd = cmd;
srb->flags = 0;
CMD_SP(cmd) = (void *)srb;
return srb;
}
static void qla4xxx_srb_free_dma(struct scsi_qla_host *ha, struct srb *srb)
{
struct scsi_cmnd *cmd = srb->cmd;
if (srb->flags & SRB_DMA_VALID) {
scsi_dma_unmap(cmd);
srb->flags &= ~SRB_DMA_VALID;
}
CMD_SP(cmd) = NULL;
}
void qla4xxx_srb_compl(struct kref *ref)
{
struct srb *srb = container_of(ref, struct srb, srb_ref);
struct scsi_cmnd *cmd = srb->cmd;
struct scsi_qla_host *ha = srb->ha;
qla4xxx_srb_free_dma(ha, srb);
mempool_free(srb, ha->srb_mempool);
cmd->scsi_done(cmd);
}
static int qla4xxx_queuecommand(struct Scsi_Host *host, struct scsi_cmnd *cmd)
{
struct scsi_qla_host *ha = to_qla_host(host);
struct ddb_entry *ddb_entry = cmd->device->hostdata;
struct iscsi_cls_session *sess = ddb_entry->sess;
struct srb *srb;
int rval;
if (test_bit(AF_EEH_BUSY, &ha->flags)) {
if (test_bit(AF_PCI_CHANNEL_IO_PERM_FAILURE, &ha->flags))
cmd->result = DID_NO_CONNECT << 16;
else
cmd->result = DID_REQUEUE << 16;
goto qc_fail_command;
}
if (!sess) {
cmd->result = DID_IMM_RETRY << 16;
goto qc_fail_command;
}
rval = iscsi_session_chkready(sess);
if (rval) {
cmd->result = rval;
goto qc_fail_command;
}
if (atomic_read(&ddb_entry->state) != DDB_STATE_ONLINE) {
if (atomic_read(&ddb_entry->state) == DDB_STATE_DEAD) {
cmd->result = DID_NO_CONNECT << 16;
goto qc_fail_command;
}
return SCSI_MLQUEUE_TARGET_BUSY;
}
if (test_bit(DPC_RESET_HA_INTR, &ha->dpc_flags) ||
test_bit(DPC_RESET_ACTIVE, &ha->dpc_flags) ||
test_bit(DPC_RESET_HA, &ha->dpc_flags) ||
test_bit(DPC_HA_UNRECOVERABLE, &ha->dpc_flags) ||
test_bit(DPC_HA_NEED_QUIESCENT, &ha->dpc_flags) ||
!test_bit(AF_ONLINE, &ha->flags) ||
test_bit(DPC_RESET_HA_FW_CONTEXT, &ha->dpc_flags))
goto qc_host_busy;
srb = qla4xxx_get_new_srb(ha, ddb_entry, cmd);
if (!srb)
goto qc_host_busy;
rval = qla4xxx_send_command_to_isp(ha, srb);
if (rval != QLA_SUCCESS)
goto qc_host_busy_free_sp;
return 0;
qc_host_busy_free_sp:
qla4xxx_srb_free_dma(ha, srb);
mempool_free(srb, ha->srb_mempool);
qc_host_busy:
return SCSI_MLQUEUE_HOST_BUSY;
qc_fail_command:
cmd->scsi_done(cmd);
return 0;
}
static void qla4xxx_mem_free(struct scsi_qla_host *ha)
{
if (ha->queues)
dma_free_coherent(&ha->pdev->dev, ha->queues_len, ha->queues,
ha->queues_dma);
ha->queues_len = 0;
ha->queues = NULL;
ha->queues_dma = 0;
ha->request_ring = NULL;
ha->request_dma = 0;
ha->response_ring = NULL;
ha->response_dma = 0;
ha->shadow_regs = NULL;
ha->shadow_regs_dma = 0;
if (ha->srb_mempool)
mempool_destroy(ha->srb_mempool);
ha->srb_mempool = NULL;
if (is_qla8022(ha)) {
if (ha->nx_pcibase)
iounmap(
(struct device_reg_82xx __iomem *)ha->nx_pcibase);
} else if (ha->reg)
iounmap(ha->reg);
pci_release_regions(ha->pdev);
}
static int qla4xxx_mem_alloc(struct scsi_qla_host *ha)
{
unsigned long align;
ha->queues_len = ((REQUEST_QUEUE_DEPTH * QUEUE_SIZE) +
(RESPONSE_QUEUE_DEPTH * QUEUE_SIZE) +
sizeof(struct shadow_regs) +
MEM_ALIGN_VALUE +
(PAGE_SIZE - 1)) & ~(PAGE_SIZE - 1);
ha->queues = dma_alloc_coherent(&ha->pdev->dev, ha->queues_len,
&ha->queues_dma, GFP_KERNEL);
if (ha->queues == NULL) {
ql4_printk(KERN_WARNING, ha,
"Memory Allocation failed - queues.\n");
goto mem_alloc_error_exit;
}
memset(ha->queues, 0, ha->queues_len);
align = 0;
if ((unsigned long)ha->queues_dma & (MEM_ALIGN_VALUE - 1))
align = MEM_ALIGN_VALUE - ((unsigned long)ha->queues_dma &
(MEM_ALIGN_VALUE - 1));
ha->request_dma = ha->queues_dma + align;
ha->request_ring = (struct queue_entry *) (ha->queues + align);
ha->response_dma = ha->queues_dma + align +
(REQUEST_QUEUE_DEPTH * QUEUE_SIZE);
ha->response_ring = (struct queue_entry *) (ha->queues + align +
(REQUEST_QUEUE_DEPTH *
QUEUE_SIZE));
ha->shadow_regs_dma = ha->queues_dma + align +
(REQUEST_QUEUE_DEPTH * QUEUE_SIZE) +
(RESPONSE_QUEUE_DEPTH * QUEUE_SIZE);
ha->shadow_regs = (struct shadow_regs *) (ha->queues + align +
(REQUEST_QUEUE_DEPTH *
QUEUE_SIZE) +
(RESPONSE_QUEUE_DEPTH *
QUEUE_SIZE));
ha->srb_mempool = mempool_create(SRB_MIN_REQ, mempool_alloc_slab,
mempool_free_slab, srb_cachep);
if (ha->srb_mempool == NULL) {
ql4_printk(KERN_WARNING, ha,
"Memory Allocation failed - SRB Pool.\n");
goto mem_alloc_error_exit;
}
return QLA_SUCCESS;
mem_alloc_error_exit:
qla4xxx_mem_free(ha);
return QLA_ERROR;
}
static void qla4_8xxx_check_fw_alive(struct scsi_qla_host *ha)
{
uint32_t fw_heartbeat_counter, halt_status;
fw_heartbeat_counter = qla4_8xxx_rd_32(ha, QLA82XX_PEG_ALIVE_COUNTER);
if (fw_heartbeat_counter == 0xffffffff) {
DEBUG2(printk(KERN_WARNING "scsi%ld: %s: Device in frozen "
"state, QLA82XX_PEG_ALIVE_COUNTER is 0xffffffff\n",
ha->host_no, __func__));
return;
}
if (ha->fw_heartbeat_counter == fw_heartbeat_counter) {
ha->seconds_since_last_heartbeat++;
if (ha->seconds_since_last_heartbeat == 2) {
ha->seconds_since_last_heartbeat = 0;
halt_status = qla4_8xxx_rd_32(ha,
QLA82XX_PEG_HALT_STATUS1);
ql4_printk(KERN_INFO, ha,
"scsi(%ld): %s, Dumping hw/fw registers:\n "
" PEG_HALT_STATUS1: 0x%x, PEG_HALT_STATUS2:"
" 0x%x,\n PEG_NET_0_PC: 0x%x, PEG_NET_1_PC:"
" 0x%x,\n PEG_NET_2_PC: 0x%x, PEG_NET_3_PC:"
" 0x%x,\n PEG_NET_4_PC: 0x%x\n",
ha->host_no, __func__, halt_status,
qla4_8xxx_rd_32(ha,
QLA82XX_PEG_HALT_STATUS2),
qla4_8xxx_rd_32(ha, QLA82XX_CRB_PEG_NET_0 +
0x3c),
qla4_8xxx_rd_32(ha, QLA82XX_CRB_PEG_NET_1 +
0x3c),
qla4_8xxx_rd_32(ha, QLA82XX_CRB_PEG_NET_2 +
0x3c),
qla4_8xxx_rd_32(ha, QLA82XX_CRB_PEG_NET_3 +
0x3c),
qla4_8xxx_rd_32(ha, QLA82XX_CRB_PEG_NET_4 +
0x3c));
if (halt_status & HALT_STATUS_UNRECOVERABLE)
set_bit(DPC_HA_UNRECOVERABLE, &ha->dpc_flags);
else {
printk("scsi%ld: %s: detect abort needed!\n",
ha->host_no, __func__);
set_bit(DPC_RESET_HA, &ha->dpc_flags);
}
qla4xxx_wake_dpc(ha);
qla4xxx_mailbox_premature_completion(ha);
}
} else
ha->seconds_since_last_heartbeat = 0;
ha->fw_heartbeat_counter = fw_heartbeat_counter;
}
void qla4_8xxx_watchdog(struct scsi_qla_host *ha)
{
uint32_t dev_state;
dev_state = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DEV_STATE);
if (!(test_bit(DPC_RESET_ACTIVE, &ha->dpc_flags) ||
test_bit(DPC_RESET_HA, &ha->dpc_flags) ||
test_bit(DPC_RETRY_RESET_HA, &ha->dpc_flags))) {
if (dev_state == QLA82XX_DEV_NEED_RESET &&
!test_bit(DPC_RESET_HA, &ha->dpc_flags)) {
if (!ql4xdontresethba) {
ql4_printk(KERN_INFO, ha, "%s: HW State: "
"NEED RESET!\n", __func__);
set_bit(DPC_RESET_HA, &ha->dpc_flags);
qla4xxx_wake_dpc(ha);
qla4xxx_mailbox_premature_completion(ha);
}
} else if (dev_state == QLA82XX_DEV_NEED_QUIESCENT &&
!test_bit(DPC_HA_NEED_QUIESCENT, &ha->dpc_flags)) {
ql4_printk(KERN_INFO, ha, "%s: HW State: NEED QUIES!\n",
__func__);
set_bit(DPC_HA_NEED_QUIESCENT, &ha->dpc_flags);
qla4xxx_wake_dpc(ha);
} else {
qla4_8xxx_check_fw_alive(ha);
}
}
}
static void qla4xxx_timer(struct scsi_qla_host *ha)
{
struct ddb_entry *ddb_entry, *dtemp;
int start_dpc = 0;
uint16_t w;
if (test_bit(AF_EEH_BUSY, &ha->flags)) {
mod_timer(&ha->timer, jiffies + HZ);
return;
}
if (!pci_channel_offline(ha->pdev))
pci_read_config_word(ha->pdev, PCI_VENDOR_ID, &w);
if (is_qla8022(ha)) {
qla4_8xxx_watchdog(ha);
}
list_for_each_entry_safe(ddb_entry, dtemp, &ha->ddb_list, list) {
if (adapter_up(ha) &&
!test_bit(DF_RELOGIN, &ddb_entry->flags) &&
atomic_read(&ddb_entry->state) != DDB_STATE_ONLINE) {
if (atomic_read(&ddb_entry->retry_relogin_timer) !=
INVALID_ENTRY) {
if (atomic_read(&ddb_entry->retry_relogin_timer)
== 0) {
atomic_set(&ddb_entry->
retry_relogin_timer,
INVALID_ENTRY);
set_bit(DPC_RELOGIN_DEVICE,
&ha->dpc_flags);
set_bit(DF_RELOGIN, &ddb_entry->flags);
DEBUG2(printk("scsi%ld: %s: ddb [%d]"
" login device\n",
ha->host_no, __func__,
ddb_entry->fw_ddb_index));
} else
atomic_dec(&ddb_entry->
retry_relogin_timer);
}
}
if (atomic_read(&ddb_entry->relogin_timer) &&
(atomic_dec_and_test(&ddb_entry->relogin_timer) != 0)) {
if (atomic_read(&ddb_entry->state) !=
DDB_STATE_ONLINE &&
ddb_entry->fw_ddb_device_state ==
DDB_DS_SESSION_FAILED) {
atomic_inc(&ddb_entry->relogin_retry_count);
DEBUG2(printk("scsi%ld: ddb [%d] relogin"
" timed out-retrying"
" relogin (%d)\n",
ha->host_no,
ddb_entry->fw_ddb_index,
atomic_read(&ddb_entry->
relogin_retry_count))
);
start_dpc++;
DEBUG(printk("scsi%ld:%d:%d: ddb [%d] "
"initiate relogin after"
" %d seconds\n",
ha->host_no, ddb_entry->bus,
ddb_entry->target,
ddb_entry->fw_ddb_index,
ddb_entry->default_time2wait + 4)
);
atomic_set(&ddb_entry->retry_relogin_timer,
ddb_entry->default_time2wait + 4);
}
}
}
if (!is_qla8022(ha)) {
if (ha->firmware_options & FWOPT_HEARTBEAT_ENABLE &&
ha->heartbeat_interval != 0) {
ha->seconds_since_last_heartbeat++;
if (ha->seconds_since_last_heartbeat >
ha->heartbeat_interval + 2)
set_bit(DPC_RESET_HA, &ha->dpc_flags);
}
}
if (start_dpc ||
test_bit(DPC_RESET_HA, &ha->dpc_flags) ||
test_bit(DPC_RETRY_RESET_HA, &ha->dpc_flags) ||
test_bit(DPC_RELOGIN_DEVICE, &ha->dpc_flags) ||
test_bit(DPC_RESET_HA_FW_CONTEXT, &ha->dpc_flags) ||
test_bit(DPC_RESET_HA_INTR, &ha->dpc_flags) ||
test_bit(DPC_GET_DHCP_IP_ADDR, &ha->dpc_flags) ||
test_bit(DPC_LINK_CHANGED, &ha->dpc_flags) ||
test_bit(DPC_HA_UNRECOVERABLE, &ha->dpc_flags) ||
test_bit(DPC_HA_NEED_QUIESCENT, &ha->dpc_flags) ||
test_bit(DPC_AEN, &ha->dpc_flags)) {
DEBUG2(printk("scsi%ld: %s: scheduling dpc routine"
" - dpc flags = 0x%lx\n",
ha->host_no, __func__, ha->dpc_flags));
qla4xxx_wake_dpc(ha);
}
mod_timer(&ha->timer, jiffies + HZ);
DEBUG2(ha->seconds_since_last_intr++);
}
static int qla4xxx_cmd_wait(struct scsi_qla_host *ha)
{
uint32_t index = 0;
unsigned long flags;
struct scsi_cmnd *cmd;
unsigned long wtime = jiffies + (WAIT_CMD_TOV * HZ);
DEBUG2(ql4_printk(KERN_INFO, ha, "Wait up to %d seconds for cmds to "
"complete\n", WAIT_CMD_TOV));
while (!time_after_eq(jiffies, wtime)) {
spin_lock_irqsave(&ha->hardware_lock, flags);
for (index = 0; index < ha->host->can_queue; index++) {
cmd = scsi_host_find_tag(ha->host, index);
if (cmd != NULL && CMD_SP(cmd))
break;
}
spin_unlock_irqrestore(&ha->hardware_lock, flags);
if (index == ha->host->can_queue)
return QLA_SUCCESS;
msleep(1000);
}
return QLA_ERROR;
}
int qla4xxx_hw_reset(struct scsi_qla_host *ha)
{
uint32_t ctrl_status;
unsigned long flags = 0;
DEBUG2(printk(KERN_ERR "scsi%ld: %s\n", ha->host_no, __func__));
if (ql4xxx_lock_drvr_wait(ha) != QLA_SUCCESS)
return QLA_ERROR;
spin_lock_irqsave(&ha->hardware_lock, flags);
ctrl_status = readw(&ha->reg->ctrl_status);
if ((ctrl_status & CSR_SCSI_RESET_INTR) != 0)
writel(set_rmask(CSR_SCSI_RESET_INTR), &ha->reg->ctrl_status);
writel(set_rmask(CSR_SOFT_RESET), &ha->reg->ctrl_status);
readl(&ha->reg->ctrl_status);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
return QLA_SUCCESS;
}
int qla4xxx_soft_reset(struct scsi_qla_host *ha)
{
uint32_t max_wait_time;
unsigned long flags = 0;
int status;
uint32_t ctrl_status;
status = qla4xxx_hw_reset(ha);
if (status != QLA_SUCCESS)
return status;
status = QLA_ERROR;
max_wait_time = RESET_INTR_TOV;
do {
spin_lock_irqsave(&ha->hardware_lock, flags);
ctrl_status = readw(&ha->reg->ctrl_status);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
if ((ctrl_status & CSR_NET_RESET_INTR) == 0)
break;
msleep(1000);
} while ((--max_wait_time));
if ((ctrl_status & CSR_NET_RESET_INTR) != 0) {
DEBUG2(printk(KERN_WARNING
"scsi%ld: Network Reset Intr not cleared by "
"Network function, clearing it now!\n",
ha->host_no));
spin_lock_irqsave(&ha->hardware_lock, flags);
writel(set_rmask(CSR_NET_RESET_INTR), &ha->reg->ctrl_status);
readl(&ha->reg->ctrl_status);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
}
max_wait_time = SOFT_RESET_TOV;
do {
spin_lock_irqsave(&ha->hardware_lock, flags);
ctrl_status = readw(&ha->reg->ctrl_status);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
if ((ctrl_status & CSR_SOFT_RESET) == 0) {
status = QLA_SUCCESS;
break;
}
msleep(1000);
} while ((--max_wait_time));
spin_lock_irqsave(&ha->hardware_lock, flags);
ctrl_status = readw(&ha->reg->ctrl_status);
if ((ctrl_status & CSR_SCSI_RESET_INTR) != 0) {
writel(set_rmask(CSR_SCSI_RESET_INTR), &ha->reg->ctrl_status);
readl(&ha->reg->ctrl_status);
}
spin_unlock_irqrestore(&ha->hardware_lock, flags);
if (max_wait_time == 0) {
spin_lock_irqsave(&ha->hardware_lock, flags);
writel(set_rmask(CSR_FORCE_SOFT_RESET), &ha->reg->ctrl_status);
readl(&ha->reg->ctrl_status);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
max_wait_time = SOFT_RESET_TOV;
do {
spin_lock_irqsave(&ha->hardware_lock, flags);
ctrl_status = readw(&ha->reg->ctrl_status);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
if ((ctrl_status & CSR_FORCE_SOFT_RESET) == 0) {
status = QLA_SUCCESS;
break;
}
msleep(1000);
} while ((--max_wait_time));
}
return status;
}
static void qla4xxx_abort_active_cmds(struct scsi_qla_host *ha, int res)
{
struct srb *srb;
int i;
unsigned long flags;
spin_lock_irqsave(&ha->hardware_lock, flags);
for (i = 0; i < ha->host->can_queue; i++) {
srb = qla4xxx_del_from_active_array(ha, i);
if (srb != NULL) {
srb->cmd->result = res;
kref_put(&srb->srb_ref, qla4xxx_srb_compl);
}
}
spin_unlock_irqrestore(&ha->hardware_lock, flags);
}
void qla4xxx_dead_adapter_cleanup(struct scsi_qla_host *ha)
{
clear_bit(AF_ONLINE, &ha->flags);
ql4_printk(KERN_INFO, ha, "Disabling the board\n");
qla4xxx_abort_active_cmds(ha, DID_NO_CONNECT << 16);
qla4xxx_mark_all_devices_missing(ha);
clear_bit(AF_INIT_DONE, &ha->flags);
}
static int qla4xxx_recover_adapter(struct scsi_qla_host *ha)
{
int status = QLA_ERROR;
uint8_t reset_chip = 0;
scsi_block_requests(ha->host);
clear_bit(AF_ONLINE, &ha->flags);
DEBUG2(ql4_printk(KERN_INFO, ha, "%s: adapter OFFLINE\n", __func__));
set_bit(DPC_RESET_ACTIVE, &ha->dpc_flags);
if (test_bit(DPC_RESET_HA, &ha->dpc_flags))
reset_chip = 1;
if (test_bit(DPC_RESET_HA_INTR, &ha->dpc_flags)) {
status = QLA_SUCCESS;
goto recover_ha_init_adapter;
}
if (is_qla8022(ha) && !reset_chip &&
test_bit(DPC_RESET_HA_FW_CONTEXT, &ha->dpc_flags)) {
DEBUG2(ql4_printk(KERN_INFO, ha,
"scsi%ld: %s - Performing stop_firmware...\n",
ha->host_no, __func__));
status = ha->isp_ops->reset_firmware(ha);
if (status == QLA_SUCCESS) {
if (!test_bit(AF_FW_RECOVERY, &ha->flags))
qla4xxx_cmd_wait(ha);
ha->isp_ops->disable_intrs(ha);
qla4xxx_process_aen(ha, FLUSH_DDB_CHANGED_AENS);
qla4xxx_abort_active_cmds(ha, DID_RESET << 16);
} else {
reset_chip = 1;
clear_bit(DPC_RESET_HA_FW_CONTEXT, &ha->dpc_flags);
set_bit(DPC_RESET_HA, &ha->dpc_flags);
}
}
if (!is_qla8022(ha) || reset_chip) {
if (!test_bit(AF_FW_RECOVERY, &ha->flags))
qla4xxx_cmd_wait(ha);
qla4xxx_process_aen(ha, FLUSH_DDB_CHANGED_AENS);
qla4xxx_abort_active_cmds(ha, DID_RESET << 16);
DEBUG2(ql4_printk(KERN_INFO, ha,
"scsi%ld: %s - Performing chip reset..\n",
ha->host_no, __func__));
status = ha->isp_ops->reset_chip(ha);
}
qla4xxx_process_aen(ha, FLUSH_DDB_CHANGED_AENS);
recover_ha_init_adapter:
if (status == QLA_SUCCESS) {
if (!is_qla8022(ha) && (ha->mac_index == 3))
ssleep(6);
status = qla4xxx_initialize_adapter(ha, PRESERVE_DDB_LIST);
}
if (!test_bit(AF_ONLINE, &ha->flags) &&
!test_bit(DPC_RESET_HA_INTR, &ha->dpc_flags)) {
if (!test_bit(DPC_RETRY_RESET_HA, &ha->dpc_flags)) {
ha->retry_reset_ha_cnt = MAX_RESET_HA_RETRIES;
DEBUG2(printk("scsi%ld: recover adapter - retrying "
"(%d) more times\n", ha->host_no,
ha->retry_reset_ha_cnt));
set_bit(DPC_RETRY_RESET_HA, &ha->dpc_flags);
status = QLA_ERROR;
} else {
if (ha->retry_reset_ha_cnt > 0) {
ha->retry_reset_ha_cnt--;
DEBUG2(printk("scsi%ld: recover adapter - "
"retry remaining %d\n",
ha->host_no,
ha->retry_reset_ha_cnt));
status = QLA_ERROR;
}
if (ha->retry_reset_ha_cnt == 0) {
DEBUG2(printk("scsi%ld: recover adapter "
"failed - board disabled\n",
ha->host_no));
qla4xxx_dead_adapter_cleanup(ha);
clear_bit(DPC_RETRY_RESET_HA, &ha->dpc_flags);
clear_bit(DPC_RESET_HA, &ha->dpc_flags);
clear_bit(DPC_RESET_HA_FW_CONTEXT,
&ha->dpc_flags);
status = QLA_ERROR;
}
}
} else {
clear_bit(DPC_RESET_HA, &ha->dpc_flags);
clear_bit(DPC_RESET_HA_FW_CONTEXT, &ha->dpc_flags);
clear_bit(DPC_RETRY_RESET_HA, &ha->dpc_flags);
}
ha->adapter_error_count++;
if (test_bit(AF_ONLINE, &ha->flags))
ha->isp_ops->enable_intrs(ha);
scsi_unblock_requests(ha->host);
clear_bit(DPC_RESET_ACTIVE, &ha->dpc_flags);
DEBUG2(printk("scsi%ld: recover adapter: %s\n", ha->host_no,
status == QLA_ERROR ? "FAILED" : "SUCCEEDED"));
return status;
}
static void qla4xxx_relogin_all_devices(struct scsi_qla_host *ha)
{
struct ddb_entry *ddb_entry, *dtemp;
list_for_each_entry_safe(ddb_entry, dtemp, &ha->ddb_list, list) {
if ((atomic_read(&ddb_entry->state) == DDB_STATE_MISSING) ||
(atomic_read(&ddb_entry->state) == DDB_STATE_DEAD)) {
if (ddb_entry->fw_ddb_device_state ==
DDB_DS_SESSION_ACTIVE) {
atomic_set(&ddb_entry->state, DDB_STATE_ONLINE);
ql4_printk(KERN_INFO, ha, "scsi%ld: %s: ddb[%d]"
" marked ONLINE\n", ha->host_no, __func__,
ddb_entry->fw_ddb_index);
iscsi_unblock_session(ddb_entry->sess);
} else
qla4xxx_relogin_device(ha, ddb_entry);
}
}
}
void qla4xxx_wake_dpc(struct scsi_qla_host *ha)
{
if (ha->dpc_thread)
queue_work(ha->dpc_thread, &ha->dpc_work);
}
static void qla4xxx_do_dpc(struct work_struct *work)
{
struct scsi_qla_host *ha =
container_of(work, struct scsi_qla_host, dpc_work);
struct ddb_entry *ddb_entry, *dtemp;
int status = QLA_ERROR;
DEBUG2(printk("scsi%ld: %s: DPC handler waking up."
"flags = 0x%08lx, dpc_flags = 0x%08lx\n",
ha->host_no, __func__, ha->flags, ha->dpc_flags))
if (!test_bit(AF_INIT_DONE, &ha->flags))
return;
if (test_bit(AF_EEH_BUSY, &ha->flags)) {
DEBUG2(printk(KERN_INFO "scsi%ld: %s: flags = %lx\n",
ha->host_no, __func__, ha->flags));
return;
}
if (is_qla8022(ha)) {
if (test_bit(DPC_HA_UNRECOVERABLE, &ha->dpc_flags)) {
qla4_8xxx_idc_lock(ha);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DEV_STATE,
QLA82XX_DEV_FAILED);
qla4_8xxx_idc_unlock(ha);
ql4_printk(KERN_INFO, ha, "HW State: FAILED\n");
qla4_8xxx_device_state_handler(ha);
}
if (test_and_clear_bit(DPC_HA_NEED_QUIESCENT, &ha->dpc_flags)) {
qla4_8xxx_need_qsnt_handler(ha);
}
}
if (!test_bit(DPC_RESET_ACTIVE, &ha->dpc_flags) &&
(test_bit(DPC_RESET_HA, &ha->dpc_flags) ||
test_bit(DPC_RESET_HA_INTR, &ha->dpc_flags) ||
test_bit(DPC_RESET_HA_FW_CONTEXT, &ha->dpc_flags))) {
if (ql4xdontresethba) {
DEBUG2(printk("scsi%ld: %s: Don't Reset HBA\n",
ha->host_no, __func__));
clear_bit(DPC_RESET_HA, &ha->dpc_flags);
clear_bit(DPC_RESET_HA_INTR, &ha->dpc_flags);
clear_bit(DPC_RESET_HA_FW_CONTEXT, &ha->dpc_flags);
goto dpc_post_reset_ha;
}
if (test_bit(DPC_RESET_HA_FW_CONTEXT, &ha->dpc_flags) ||
test_bit(DPC_RESET_HA, &ha->dpc_flags))
qla4xxx_recover_adapter(ha);
if (test_bit(DPC_RESET_HA_INTR, &ha->dpc_flags)) {
uint8_t wait_time = RESET_INTR_TOV;
while ((readw(&ha->reg->ctrl_status) &
(CSR_SOFT_RESET | CSR_FORCE_SOFT_RESET)) != 0) {
if (--wait_time == 0)
break;
msleep(1000);
}
if (wait_time == 0)
DEBUG2(printk("scsi%ld: %s: SR|FSR "
"bit not cleared-- resetting\n",
ha->host_no, __func__));
qla4xxx_abort_active_cmds(ha, DID_RESET << 16);
if (ql4xxx_lock_drvr_wait(ha) == QLA_SUCCESS) {
qla4xxx_process_aen(ha, FLUSH_DDB_CHANGED_AENS);
status = qla4xxx_recover_adapter(ha);
}
clear_bit(DPC_RESET_HA_INTR, &ha->dpc_flags);
if (status == QLA_SUCCESS)
ha->isp_ops->enable_intrs(ha);
}
}
dpc_post_reset_ha:
if (test_and_clear_bit(DPC_AEN, &ha->dpc_flags))
qla4xxx_process_aen(ha, PROCESS_ALL_AENS);
if (test_and_clear_bit(DPC_GET_DHCP_IP_ADDR, &ha->dpc_flags))
qla4xxx_get_dhcp_ip_address(ha);
if (test_and_clear_bit(DPC_LINK_CHANGED, &ha->dpc_flags)) {
if (!test_bit(AF_LINK_UP, &ha->flags)) {
qla4xxx_mark_all_devices_missing(ha);
} else {
qla4xxx_relogin_all_devices(ha);
}
}
if (adapter_up(ha) &&
test_and_clear_bit(DPC_RELOGIN_DEVICE, &ha->dpc_flags)) {
list_for_each_entry_safe(ddb_entry, dtemp,
&ha->ddb_list, list) {
if (test_and_clear_bit(DF_RELOGIN, &ddb_entry->flags) &&
atomic_read(&ddb_entry->state) != DDB_STATE_ONLINE)
qla4xxx_relogin_device(ha, ddb_entry);
if (test_bit(DPC_RESET_HA, &ha->dpc_flags)) {
printk(KERN_WARNING "scsi%ld: %s: "
"need to reset hba\n",
ha->host_no, __func__);
break;
}
}
}
}
static void qla4xxx_free_adapter(struct scsi_qla_host *ha)
{
if (test_bit(AF_INTERRUPTS_ON, &ha->flags)) {
ha->isp_ops->disable_intrs(ha);
}
if (ha->timer_active)
qla4xxx_stop_timer(ha);
if (ha->dpc_thread)
destroy_workqueue(ha->dpc_thread);
ha->isp_ops->reset_firmware(ha);
if (is_qla8022(ha)) {
qla4_8xxx_idc_lock(ha);
qla4_8xxx_clear_drv_active(ha);
qla4_8xxx_idc_unlock(ha);
}
if (test_and_clear_bit(AF_IRQ_ATTACHED, &ha->flags))
qla4xxx_free_irqs(ha);
qla4xxx_mem_free(ha);
}
int qla4_8xxx_iospace_config(struct scsi_qla_host *ha)
{
int status = 0;
uint8_t revision_id;
unsigned long mem_base, mem_len, db_base, db_len;
struct pci_dev *pdev = ha->pdev;
status = pci_request_regions(pdev, DRIVER_NAME);
if (status) {
printk(KERN_WARNING
"scsi(%ld) Failed to reserve PIO regions (%s) "
"status=%d\n", ha->host_no, pci_name(pdev), status);
goto iospace_error_exit;
}
pci_read_config_byte(pdev, PCI_REVISION_ID, &revision_id);
DEBUG2(printk(KERN_INFO "%s: revision-id=%d\n",
__func__, revision_id));
ha->revision_id = revision_id;
mem_base = pci_resource_start(pdev, 0);
mem_len = pci_resource_len(pdev, 0);
DEBUG2(printk(KERN_INFO "%s: ioremap from %lx a size of %lx\n",
__func__, mem_base, mem_len));
ha->nx_pcibase = (unsigned long)ioremap(mem_base, mem_len);
if (!ha->nx_pcibase) {
printk(KERN_ERR
"cannot remap MMIO (%s), aborting\n", pci_name(pdev));
pci_release_regions(ha->pdev);
goto iospace_error_exit;
}
ha->qla4_8xxx_reg =
(struct device_reg_82xx __iomem *)((uint8_t *)ha->nx_pcibase +
0xbc000 + (ha->pdev->devfn << 11));
db_base = pci_resource_start(pdev, 4);
db_len = pci_resource_len(pdev, 4);
ha->nx_db_wr_ptr = (ha->pdev->devfn == 4 ? QLA82XX_CAM_RAM_DB1 :
QLA82XX_CAM_RAM_DB2);
return 0;
iospace_error_exit:
return -ENOMEM;
}
int qla4xxx_iospace_config(struct scsi_qla_host *ha)
{
unsigned long pio, pio_len, pio_flags;
unsigned long mmio, mmio_len, mmio_flags;
pio = pci_resource_start(ha->pdev, 0);
pio_len = pci_resource_len(ha->pdev, 0);
pio_flags = pci_resource_flags(ha->pdev, 0);
if (pio_flags & IORESOURCE_IO) {
if (pio_len < MIN_IOBASE_LEN) {
ql4_printk(KERN_WARNING, ha,
"Invalid PCI I/O region size\n");
pio = 0;
}
} else {
ql4_printk(KERN_WARNING, ha, "region #0 not a PIO resource\n");
pio = 0;
}
mmio = pci_resource_start(ha->pdev, 1);
mmio_len = pci_resource_len(ha->pdev, 1);
mmio_flags = pci_resource_flags(ha->pdev, 1);
if (!(mmio_flags & IORESOURCE_MEM)) {
ql4_printk(KERN_ERR, ha,
"region #0 not an MMIO resource, aborting\n");
goto iospace_error_exit;
}
if (mmio_len < MIN_IOBASE_LEN) {
ql4_printk(KERN_ERR, ha,
"Invalid PCI mem region size, aborting\n");
goto iospace_error_exit;
}
if (pci_request_regions(ha->pdev, DRIVER_NAME)) {
ql4_printk(KERN_WARNING, ha,
"Failed to reserve PIO/MMIO regions\n");
goto iospace_error_exit;
}
ha->pio_address = pio;
ha->pio_length = pio_len;
ha->reg = ioremap(mmio, MIN_IOBASE_LEN);
if (!ha->reg) {
ql4_printk(KERN_ERR, ha,
"cannot remap MMIO, aborting\n");
goto iospace_error_exit;
}
return 0;
iospace_error_exit:
return -ENOMEM;
}
uint16_t qla4xxx_rd_shdw_req_q_out(struct scsi_qla_host *ha)
{
return (uint16_t)le32_to_cpu(ha->shadow_regs->req_q_out);
}
uint16_t qla4_8xxx_rd_shdw_req_q_out(struct scsi_qla_host *ha)
{
return (uint16_t)le32_to_cpu(readl(&ha->qla4_8xxx_reg->req_q_out));
}
uint16_t qla4xxx_rd_shdw_rsp_q_in(struct scsi_qla_host *ha)
{
return (uint16_t)le32_to_cpu(ha->shadow_regs->rsp_q_in);
}
uint16_t qla4_8xxx_rd_shdw_rsp_q_in(struct scsi_qla_host *ha)
{
return (uint16_t)le32_to_cpu(readl(&ha->qla4_8xxx_reg->rsp_q_in));
}
static int __devinit qla4xxx_probe_adapter(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int ret = -ENODEV, status;
struct Scsi_Host *host;
struct scsi_qla_host *ha;
uint8_t init_retry_count = 0;
char buf[34];
struct qla4_8xxx_legacy_intr_set *nx_legacy_intr;
uint32_t dev_state;
if (pci_enable_device(pdev))
return -1;
host = scsi_host_alloc(&qla4xxx_driver_template, sizeof(*ha));
if (host == NULL) {
printk(KERN_WARNING
"qla4xxx: Couldn't allocate host from scsi layer!\n");
goto probe_disable_device;
}
ha = (struct scsi_qla_host *) host->hostdata;
memset(ha, 0, sizeof(*ha));
ha->pdev = pdev;
ha->host = host;
ha->host_no = host->host_no;
pci_enable_pcie_error_reporting(pdev);
if (is_qla8022(ha)) {
ha->isp_ops = &qla4_8xxx_isp_ops;
rwlock_init(&ha->hw_lock);
ha->qdr_sn_window = -1;
ha->ddr_mn_window = -1;
ha->curr_window = 255;
ha->func_num = PCI_FUNC(ha->pdev->devfn);
nx_legacy_intr = &legacy_intr[ha->func_num];
ha->nx_legacy_intr.int_vec_bit = nx_legacy_intr->int_vec_bit;
ha->nx_legacy_intr.tgt_status_reg =
nx_legacy_intr->tgt_status_reg;
ha->nx_legacy_intr.tgt_mask_reg = nx_legacy_intr->tgt_mask_reg;
ha->nx_legacy_intr.pci_int_reg = nx_legacy_intr->pci_int_reg;
} else {
ha->isp_ops = &qla4xxx_isp_ops;
}
if (is_qla8022(ha))
pdev->needs_freset = 1;
ret = ha->isp_ops->iospace_config(ha);
if (ret)
goto probe_failed_ioconfig;
ql4_printk(KERN_INFO, ha, "Found an ISP%04x, irq %d, iobase 0x%p\n",
pdev->device, pdev->irq, ha->reg);
qla4xxx_config_dma_addressing(ha);
INIT_LIST_HEAD(&ha->ddb_list);
INIT_LIST_HEAD(&ha->free_srb_q);
mutex_init(&ha->mbox_sem);
init_completion(&ha->mbx_intr_comp);
spin_lock_init(&ha->hardware_lock);
if (qla4xxx_mem_alloc(ha)) {
ql4_printk(KERN_WARNING, ha,
"[ERROR] Failed to allocate memory for adapter\n");
ret = -ENOMEM;
goto probe_failed;
}
if (is_qla8022(ha))
(void) qla4_8xxx_get_flash_info(ha);
status = qla4xxx_initialize_adapter(ha, REBUILD_DDB_LIST);
while ((!test_bit(AF_ONLINE, &ha->flags)) &&
init_retry_count++ < MAX_INIT_RETRIES) {
if (is_qla8022(ha)) {
qla4_8xxx_idc_lock(ha);
dev_state = qla4_8xxx_rd_32(ha, QLA82XX_CRB_DEV_STATE);
qla4_8xxx_idc_unlock(ha);
if (dev_state == QLA82XX_DEV_FAILED) {
ql4_printk(KERN_WARNING, ha, "%s: don't retry "
"initialize adapter. H/W is in failed state\n",
__func__);
break;
}
}
DEBUG2(printk("scsi: %s: retrying adapter initialization "
"(%d)\n", __func__, init_retry_count));
if (ha->isp_ops->reset_chip(ha) == QLA_ERROR)
continue;
status = qla4xxx_initialize_adapter(ha, REBUILD_DDB_LIST);
}
if (!test_bit(AF_ONLINE, &ha->flags)) {
ql4_printk(KERN_WARNING, ha, "Failed to initialize adapter\n");
if (is_qla8022(ha) && ql4xdontresethba) {
DEBUG2(printk(KERN_ERR "HW STATE: FAILED\n"));
qla4_8xxx_idc_lock(ha);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DEV_STATE,
QLA82XX_DEV_FAILED);
qla4_8xxx_idc_unlock(ha);
}
ret = -ENODEV;
goto probe_failed;
}
host->cmd_per_lun = 3;
host->max_channel = 0;
host->max_lun = MAX_LUNS - 1;
host->max_id = MAX_TARGETS;
host->max_cmd_len = IOCB_MAX_CDB_LEN;
host->can_queue = MAX_SRBS ;
host->transportt = qla4xxx_scsi_transport;
ret = scsi_init_shared_tag_map(host, MAX_SRBS);
if (ret) {
ql4_printk(KERN_WARNING, ha,
"scsi_init_shared_tag_map failed\n");
goto probe_failed;
}
DEBUG2(printk("scsi: %s: Starting kernel thread for "
"qla4xxx_dpc\n", __func__));
sprintf(buf, "qla4xxx_%lu_dpc", ha->host_no);
ha->dpc_thread = create_singlethread_workqueue(buf);
if (!ha->dpc_thread) {
ql4_printk(KERN_WARNING, ha, "Unable to start DPC thread!\n");
ret = -ENODEV;
goto probe_failed;
}
INIT_WORK(&ha->dpc_work, qla4xxx_do_dpc);
if (!is_qla8022(ha)) {
ret = qla4xxx_request_irqs(ha);
if (ret) {
ql4_printk(KERN_WARNING, ha, "Failed to reserve "
"interrupt %d already in use.\n", pdev->irq);
goto probe_failed;
}
}
pci_save_state(ha->pdev);
ha->isp_ops->enable_intrs(ha);
qla4xxx_start_timer(ha, qla4xxx_timer, 1);
set_bit(AF_INIT_DONE, &ha->flags);
pci_set_drvdata(pdev, ha);
ret = scsi_add_host(host, &pdev->dev);
if (ret)
goto probe_failed;
printk(KERN_INFO
" QLogic iSCSI HBA Driver version: %s\n"
" QLogic ISP%04x @ %s, host#=%ld, fw=%02d.%02d.%02d.%02d\n",
qla4xxx_version_str, ha->pdev->device, pci_name(ha->pdev),
ha->host_no, ha->firmware_version[0], ha->firmware_version[1],
ha->patch_number, ha->build_number);
scsi_scan_host(host);
return 0;
probe_failed:
qla4xxx_free_adapter(ha);
probe_failed_ioconfig:
pci_disable_pcie_error_reporting(pdev);
scsi_host_put(ha->host);
probe_disable_device:
pci_disable_device(pdev);
return ret;
}
static void qla4xxx_prevent_other_port_reinit(struct scsi_qla_host *ha)
{
struct scsi_qla_host *other_ha = NULL;
struct pci_dev *other_pdev = NULL;
int fn = ISP4XXX_PCI_FN_2;
if (PCI_FUNC(ha->pdev->devfn) & BIT_1)
fn = ISP4XXX_PCI_FN_1;
other_pdev =
pci_get_domain_bus_and_slot(pci_domain_nr(ha->pdev->bus),
ha->pdev->bus->number, PCI_DEVFN(PCI_SLOT(ha->pdev->devfn),
fn));
if (other_pdev) {
if (atomic_read(&other_pdev->enable_cnt)) {
other_ha = pci_get_drvdata(other_pdev);
if (other_ha) {
set_bit(AF_HA_REMOVAL, &other_ha->flags);
DEBUG2(ql4_printk(KERN_INFO, ha, "%s: "
"Prevent %s reinit\n", __func__,
dev_name(&other_ha->pdev->dev)));
}
}
pci_dev_put(other_pdev);
}
}
static void __devexit qla4xxx_remove_adapter(struct pci_dev *pdev)
{
struct scsi_qla_host *ha;
ha = pci_get_drvdata(pdev);
if (!is_qla8022(ha))
qla4xxx_prevent_other_port_reinit(ha);
qla4xxx_free_ddb_list(ha);
scsi_remove_host(ha->host);
qla4xxx_free_adapter(ha);
scsi_host_put(ha->host);
pci_disable_pcie_error_reporting(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
static void qla4xxx_config_dma_addressing(struct scsi_qla_host *ha)
{
int retval;
if (pci_set_dma_mask(ha->pdev, DMA_BIT_MASK(64)) == 0) {
if (pci_set_consistent_dma_mask(ha->pdev, DMA_BIT_MASK(64))) {
dev_dbg(&ha->pdev->dev,
"Failed to set 64 bit PCI consistent mask; "
"using 32 bit.\n");
retval = pci_set_consistent_dma_mask(ha->pdev,
DMA_BIT_MASK(32));
}
} else
retval = pci_set_dma_mask(ha->pdev, DMA_BIT_MASK(32));
}
static int qla4xxx_slave_alloc(struct scsi_device *sdev)
{
struct iscsi_cls_session *sess = starget_to_session(sdev->sdev_target);
struct ddb_entry *ddb = sess->dd_data;
int queue_depth = QL4_DEF_QDEPTH;
sdev->hostdata = ddb;
sdev->tagged_supported = 1;
if (ql4xmaxqdepth != 0 && ql4xmaxqdepth <= 0xffffU)
queue_depth = ql4xmaxqdepth;
scsi_activate_tcq(sdev, queue_depth);
return 0;
}
static int qla4xxx_slave_configure(struct scsi_device *sdev)
{
sdev->tagged_supported = 1;
return 0;
}
static void qla4xxx_slave_destroy(struct scsi_device *sdev)
{
scsi_deactivate_tcq(sdev, 1);
}
struct srb *qla4xxx_del_from_active_array(struct scsi_qla_host *ha,
uint32_t index)
{
struct srb *srb = NULL;
struct scsi_cmnd *cmd = NULL;
cmd = scsi_host_find_tag(ha->host, index);
if (!cmd)
return srb;
srb = (struct srb *)CMD_SP(cmd);
if (!srb)
return srb;
if (srb->flags & SRB_DMA_VALID) {
ha->req_q_count += srb->iocb_cnt;
ha->iocb_cnt -= srb->iocb_cnt;
if (srb->cmd)
srb->cmd->host_scribble =
(unsigned char *)(unsigned long) MAX_SRBS;
}
return srb;
}
static int qla4xxx_eh_wait_on_command(struct scsi_qla_host *ha,
struct scsi_cmnd *cmd)
{
int done = 0;
struct srb *rp;
uint32_t max_wait_time = EH_WAIT_CMD_TOV;
int ret = SUCCESS;
if (unlikely(pci_channel_offline(ha->pdev)) ||
(test_bit(AF_EEH_BUSY, &ha->flags))) {
ql4_printk(KERN_WARNING, ha, "scsi%ld: Return from %s\n",
ha->host_no, __func__);
return ret;
}
do {
rp = (struct srb *) CMD_SP(cmd);
if (rp == NULL) {
done++;
break;
}
msleep(2000);
} while (max_wait_time--);
return done;
}
static int qla4xxx_wait_for_hba_online(struct scsi_qla_host *ha)
{
unsigned long wait_online;
wait_online = jiffies + (HBA_ONLINE_TOV * HZ);
while (time_before(jiffies, wait_online)) {
if (adapter_up(ha))
return QLA_SUCCESS;
msleep(2000);
}
return QLA_ERROR;
}
static int qla4xxx_eh_wait_for_commands(struct scsi_qla_host *ha,
struct scsi_target *stgt,
struct scsi_device *sdev)
{
int cnt;
int status = 0;
struct scsi_cmnd *cmd;
for (cnt = 0; cnt < ha->host->can_queue; cnt++) {
cmd = scsi_host_find_tag(ha->host, cnt);
if (cmd && stgt == scsi_target(cmd->device) &&
(!sdev || sdev == cmd->device)) {
if (!qla4xxx_eh_wait_on_command(ha, cmd)) {
status++;
break;
}
}
}
return status;
}
static int qla4xxx_eh_abort(struct scsi_cmnd *cmd)
{
struct scsi_qla_host *ha = to_qla_host(cmd->device->host);
unsigned int id = cmd->device->id;
unsigned int lun = cmd->device->lun;
unsigned long flags;
struct srb *srb = NULL;
int ret = SUCCESS;
int wait = 0;
ql4_printk(KERN_INFO, ha,
"scsi%ld:%d:%d: Abort command issued cmd=%p\n",
ha->host_no, id, lun, cmd);
spin_lock_irqsave(&ha->hardware_lock, flags);
srb = (struct srb *) CMD_SP(cmd);
if (!srb) {
spin_unlock_irqrestore(&ha->hardware_lock, flags);
return SUCCESS;
}
kref_get(&srb->srb_ref);
spin_unlock_irqrestore(&ha->hardware_lock, flags);
if (qla4xxx_abort_task(ha, srb) != QLA_SUCCESS) {
DEBUG3(printk("scsi%ld:%d:%d: Abort_task mbx failed.\n",
ha->host_no, id, lun));
ret = FAILED;
} else {
DEBUG3(printk("scsi%ld:%d:%d: Abort_task mbx success.\n",
ha->host_no, id, lun));
wait = 1;
}
kref_put(&srb->srb_ref, qla4xxx_srb_compl);
if (wait) {
if (!qla4xxx_eh_wait_on_command(ha, cmd)) {
DEBUG2(printk("scsi%ld:%d:%d: Abort handler timed out\n",
ha->host_no, id, lun));
ret = FAILED;
}
}
ql4_printk(KERN_INFO, ha,
"scsi%ld:%d:%d: Abort command - %s\n",
ha->host_no, id, lun, (ret == SUCCESS) ? "succeeded" : "failed");
return ret;
}
static int qla4xxx_eh_device_reset(struct scsi_cmnd *cmd)
{
struct scsi_qla_host *ha = to_qla_host(cmd->device->host);
struct ddb_entry *ddb_entry = cmd->device->hostdata;
int ret = FAILED, stat;
if (!ddb_entry)
return ret;
ret = iscsi_block_scsi_eh(cmd);
if (ret)
return ret;
ret = FAILED;
ql4_printk(KERN_INFO, ha,
"scsi%ld:%d:%d:%d: DEVICE RESET ISSUED.\n", ha->host_no,
cmd->device->channel, cmd->device->id, cmd->device->lun);
DEBUG2(printk(KERN_INFO
"scsi%ld: DEVICE_RESET cmd=%p jiffies = 0x%lx, to=%x,"
"dpc_flags=%lx, status=%x allowed=%d\n", ha->host_no,
cmd, jiffies, cmd->request->timeout / HZ,
ha->dpc_flags, cmd->result, cmd->allowed));
stat = qla4xxx_reset_lun(ha, ddb_entry, cmd->device->lun);
if (stat != QLA_SUCCESS) {
ql4_printk(KERN_INFO, ha, "DEVICE RESET FAILED. %d\n", stat);
goto eh_dev_reset_done;
}
if (qla4xxx_eh_wait_for_commands(ha, scsi_target(cmd->device),
cmd->device)) {
ql4_printk(KERN_INFO, ha,
"DEVICE RESET FAILED - waiting for "
"commands.\n");
goto eh_dev_reset_done;
}
if (qla4xxx_send_marker_iocb(ha, ddb_entry, cmd->device->lun,
MM_LUN_RESET) != QLA_SUCCESS)
goto eh_dev_reset_done;
ql4_printk(KERN_INFO, ha,
"scsi(%ld:%d:%d:%d): DEVICE RESET SUCCEEDED.\n",
ha->host_no, cmd->device->channel, cmd->device->id,
cmd->device->lun);
ret = SUCCESS;
eh_dev_reset_done:
return ret;
}
static int qla4xxx_eh_target_reset(struct scsi_cmnd *cmd)
{
struct scsi_qla_host *ha = to_qla_host(cmd->device->host);
struct ddb_entry *ddb_entry = cmd->device->hostdata;
int stat, ret;
if (!ddb_entry)
return FAILED;
ret = iscsi_block_scsi_eh(cmd);
if (ret)
return ret;
starget_printk(KERN_INFO, scsi_target(cmd->device),
"WARM TARGET RESET ISSUED.\n");
DEBUG2(printk(KERN_INFO
"scsi%ld: TARGET_DEVICE_RESET cmd=%p jiffies = 0x%lx, "
"to=%x,dpc_flags=%lx, status=%x allowed=%d\n",
ha->host_no, cmd, jiffies, cmd->request->timeout / HZ,
ha->dpc_flags, cmd->result, cmd->allowed));
stat = qla4xxx_reset_target(ha, ddb_entry);
if (stat != QLA_SUCCESS) {
starget_printk(KERN_INFO, scsi_target(cmd->device),
"WARM TARGET RESET FAILED.\n");
return FAILED;
}
if (qla4xxx_eh_wait_for_commands(ha, scsi_target(cmd->device),
NULL)) {
starget_printk(KERN_INFO, scsi_target(cmd->device),
"WARM TARGET DEVICE RESET FAILED - "
"waiting for commands.\n");
return FAILED;
}
if (qla4xxx_send_marker_iocb(ha, ddb_entry, cmd->device->lun,
MM_TGT_WARM_RESET) != QLA_SUCCESS) {
starget_printk(KERN_INFO, scsi_target(cmd->device),
"WARM TARGET DEVICE RESET FAILED - "
"marker iocb failed.\n");
return FAILED;
}
starget_printk(KERN_INFO, scsi_target(cmd->device),
"WARM TARGET RESET SUCCEEDED.\n");
return SUCCESS;
}
static int qla4xxx_eh_host_reset(struct scsi_cmnd *cmd)
{
int return_status = FAILED;
struct scsi_qla_host *ha;
ha = (struct scsi_qla_host *) cmd->device->host->hostdata;
if (ql4xdontresethba) {
DEBUG2(printk("scsi%ld: %s: Don't Reset HBA\n",
ha->host_no, __func__));
return FAILED;
}
ql4_printk(KERN_INFO, ha,
"scsi(%ld:%d:%d:%d): HOST RESET ISSUED.\n", ha->host_no,
cmd->device->channel, cmd->device->id, cmd->device->lun);
if (qla4xxx_wait_for_hba_online(ha) != QLA_SUCCESS) {
DEBUG2(printk("scsi%ld:%d: %s: Unable to reset host. Adapter "
"DEAD.\n", ha->host_no, cmd->device->channel,
__func__));
return FAILED;
}
if (!test_bit(DPC_RESET_HA, &ha->dpc_flags)) {
if (is_qla8022(ha))
set_bit(DPC_RESET_HA_FW_CONTEXT, &ha->dpc_flags);
else
set_bit(DPC_RESET_HA, &ha->dpc_flags);
}
if (qla4xxx_recover_adapter(ha) == QLA_SUCCESS)
return_status = SUCCESS;
ql4_printk(KERN_INFO, ha, "HOST RESET %s.\n",
return_status == FAILED ? "FAILED" : "SUCCEEDED");
return return_status;
}
static pci_ers_result_t
qla4xxx_pci_error_detected(struct pci_dev *pdev, pci_channel_state_t state)
{
struct scsi_qla_host *ha = pci_get_drvdata(pdev);
ql4_printk(KERN_WARNING, ha, "scsi%ld: %s: error detected:state %x\n",
ha->host_no, __func__, state);
if (!is_aer_supported(ha))
return PCI_ERS_RESULT_NONE;
switch (state) {
case pci_channel_io_normal:
clear_bit(AF_EEH_BUSY, &ha->flags);
return PCI_ERS_RESULT_CAN_RECOVER;
case pci_channel_io_frozen:
set_bit(AF_EEH_BUSY, &ha->flags);
qla4xxx_mailbox_premature_completion(ha);
qla4xxx_free_irqs(ha);
pci_disable_device(pdev);
qla4xxx_abort_active_cmds(ha, DID_RESET << 16);
return PCI_ERS_RESULT_NEED_RESET;
case pci_channel_io_perm_failure:
set_bit(AF_EEH_BUSY, &ha->flags);
set_bit(AF_PCI_CHANNEL_IO_PERM_FAILURE, &ha->flags);
qla4xxx_abort_active_cmds(ha, DID_NO_CONNECT << 16);
return PCI_ERS_RESULT_DISCONNECT;
}
return PCI_ERS_RESULT_NEED_RESET;
}
static pci_ers_result_t
qla4xxx_pci_mmio_enabled(struct pci_dev *pdev)
{
struct scsi_qla_host *ha = pci_get_drvdata(pdev);
if (!is_aer_supported(ha))
return PCI_ERS_RESULT_NONE;
return PCI_ERS_RESULT_RECOVERED;
}
static uint32_t qla4_8xxx_error_recovery(struct scsi_qla_host *ha)
{
uint32_t rval = QLA_ERROR;
uint32_t ret = 0;
int fn;
struct pci_dev *other_pdev = NULL;
ql4_printk(KERN_WARNING, ha, "scsi%ld: In %s\n", ha->host_no, __func__);
set_bit(DPC_RESET_ACTIVE, &ha->dpc_flags);
if (test_bit(AF_ONLINE, &ha->flags)) {
clear_bit(AF_ONLINE, &ha->flags);
qla4xxx_mark_all_devices_missing(ha);
qla4xxx_process_aen(ha, FLUSH_DDB_CHANGED_AENS);
}
fn = PCI_FUNC(ha->pdev->devfn);
while (fn > 0) {
fn--;
ql4_printk(KERN_INFO, ha, "scsi%ld: %s: Finding PCI device at "
"func %x\n", ha->host_no, __func__, fn);
other_pdev =
pci_get_domain_bus_and_slot(pci_domain_nr(ha->pdev->bus),
ha->pdev->bus->number, PCI_DEVFN(PCI_SLOT(ha->pdev->devfn),
fn));
if (!other_pdev)
continue;
if (atomic_read(&other_pdev->enable_cnt)) {
ql4_printk(KERN_INFO, ha, "scsi%ld: %s: Found PCI "
"func in enabled state%x\n", ha->host_no,
__func__, fn);
pci_dev_put(other_pdev);
break;
}
pci_dev_put(other_pdev);
}
if (!fn) {
ql4_printk(KERN_INFO, ha, "scsi%ld: %s: devfn being reset "
"0x%x is the owner\n", ha->host_no, __func__,
ha->pdev->devfn);
qla4_8xxx_idc_lock(ha);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DEV_STATE,
QLA82XX_DEV_COLD);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DRV_IDC_VERSION,
QLA82XX_IDC_VERSION);
qla4_8xxx_idc_unlock(ha);
clear_bit(AF_FW_RECOVERY, &ha->flags);
rval = qla4xxx_initialize_adapter(ha, PRESERVE_DDB_LIST);
qla4_8xxx_idc_lock(ha);
if (rval != QLA_SUCCESS) {
ql4_printk(KERN_INFO, ha, "scsi%ld: %s: HW State: "
"FAILED\n", ha->host_no, __func__);
qla4_8xxx_clear_drv_active(ha);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DEV_STATE,
QLA82XX_DEV_FAILED);
} else {
ql4_printk(KERN_INFO, ha, "scsi%ld: %s: HW State: "
"READY\n", ha->host_no, __func__);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DEV_STATE,
QLA82XX_DEV_READY);
qla4_8xxx_wr_32(ha, QLA82XX_CRB_DRV_STATE, 0);
qla4_8xxx_set_drv_active(ha);
ret = qla4xxx_request_irqs(ha);
if (ret) {
ql4_printk(KERN_WARNING, ha, "Failed to "
"reserve interrupt %d already in use.\n",
ha->pdev->irq);
rval = QLA_ERROR;
} else {
ha->isp_ops->enable_intrs(ha);
rval = QLA_SUCCESS;
}
}
qla4_8xxx_idc_unlock(ha);
} else {
ql4_printk(KERN_INFO, ha, "scsi%ld: %s: devfn 0x%x is not "
"the reset owner\n", ha->host_no, __func__,
ha->pdev->devfn);
if ((qla4_8xxx_rd_32(ha, QLA82XX_CRB_DEV_STATE) ==
QLA82XX_DEV_READY)) {
clear_bit(AF_FW_RECOVERY, &ha->flags);
rval = qla4xxx_initialize_adapter(ha,
PRESERVE_DDB_LIST);
if (rval == QLA_SUCCESS) {
ret = qla4xxx_request_irqs(ha);
if (ret) {
ql4_printk(KERN_WARNING, ha, "Failed to"
" reserve interrupt %d already in"
" use.\n", ha->pdev->irq);
rval = QLA_ERROR;
} else {
ha->isp_ops->enable_intrs(ha);
rval = QLA_SUCCESS;
}
}
qla4_8xxx_idc_lock(ha);
qla4_8xxx_set_drv_active(ha);
qla4_8xxx_idc_unlock(ha);
}
}
clear_bit(DPC_RESET_ACTIVE, &ha->dpc_flags);
return rval;
}
static pci_ers_result_t
qla4xxx_pci_slot_reset(struct pci_dev *pdev)
{
pci_ers_result_t ret = PCI_ERS_RESULT_DISCONNECT;
struct scsi_qla_host *ha = pci_get_drvdata(pdev);
int rc;
ql4_printk(KERN_WARNING, ha, "scsi%ld: %s: slot_reset\n",
ha->host_no, __func__);
if (!is_aer_supported(ha))
return PCI_ERS_RESULT_NONE;
pci_restore_state(pdev);
pci_save_state(pdev);
rc = pci_enable_device(pdev);
if (rc) {
ql4_printk(KERN_WARNING, ha, "scsi%ld: %s: Can't re-enable "
"device after reset\n", ha->host_no, __func__);
goto exit_slot_reset;
}
ha->isp_ops->disable_intrs(ha);
if (is_qla8022(ha)) {
if (qla4_8xxx_error_recovery(ha) == QLA_SUCCESS) {
ret = PCI_ERS_RESULT_RECOVERED;
goto exit_slot_reset;
} else
goto exit_slot_reset;
}
exit_slot_reset:
ql4_printk(KERN_WARNING, ha, "scsi%ld: %s: Return=%x\n"
"device after reset\n", ha->host_no, __func__, ret);
return ret;
}
static void
qla4xxx_pci_resume(struct pci_dev *pdev)
{
struct scsi_qla_host *ha = pci_get_drvdata(pdev);
int ret;
ql4_printk(KERN_WARNING, ha, "scsi%ld: %s: pci_resume\n",
ha->host_no, __func__);
ret = qla4xxx_wait_for_hba_online(ha);
if (ret != QLA_SUCCESS) {
ql4_printk(KERN_ERR, ha, "scsi%ld: %s: the device failed to "
"resume I/O from slot/link_reset\n", ha->host_no,
__func__);
}
pci_cleanup_aer_uncorrect_error_status(pdev);
clear_bit(AF_EEH_BUSY, &ha->flags);
}
static int __init qla4xxx_module_init(void)
{
int ret;
srb_cachep = kmem_cache_create("qla4xxx_srbs", sizeof(struct srb), 0,
SLAB_HWCACHE_ALIGN, NULL);
if (srb_cachep == NULL) {
printk(KERN_ERR
"%s: Unable to allocate SRB cache..."
"Failing load!\n", DRIVER_NAME);
ret = -ENOMEM;
goto no_srp_cache;
}
strcpy(qla4xxx_version_str, QLA4XXX_DRIVER_VERSION);
if (ql4xextended_error_logging)
strcat(qla4xxx_version_str, "-debug");
qla4xxx_scsi_transport =
iscsi_register_transport(&qla4xxx_iscsi_transport);
if (!qla4xxx_scsi_transport){
ret = -ENODEV;
goto release_srb_cache;
}
ret = pci_register_driver(&qla4xxx_pci_driver);
if (ret)
goto unregister_transport;
printk(KERN_INFO "QLogic iSCSI HBA Driver\n");
return 0;
unregister_transport:
iscsi_unregister_transport(&qla4xxx_iscsi_transport);
release_srb_cache:
kmem_cache_destroy(srb_cachep);
no_srp_cache:
return ret;
}
static void __exit qla4xxx_module_exit(void)
{
pci_unregister_driver(&qla4xxx_pci_driver);
iscsi_unregister_transport(&qla4xxx_iscsi_transport);
kmem_cache_destroy(srb_cachep);
}
