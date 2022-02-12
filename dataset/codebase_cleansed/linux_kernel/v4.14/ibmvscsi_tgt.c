static void ibmvscsis_determine_resid(struct se_cmd *se_cmd,
struct srp_rsp *rsp)
{
u32 residual_count = se_cmd->residual_count;
if (!residual_count)
return;
if (se_cmd->se_cmd_flags & SCF_UNDERFLOW_BIT) {
if (se_cmd->data_direction == DMA_TO_DEVICE) {
rsp->flags = SRP_RSP_FLAG_DOUNDER;
rsp->data_out_res_cnt = cpu_to_be32(residual_count);
} else if (se_cmd->data_direction == DMA_FROM_DEVICE) {
rsp->flags = SRP_RSP_FLAG_DIUNDER;
rsp->data_in_res_cnt = cpu_to_be32(residual_count);
}
} else if (se_cmd->se_cmd_flags & SCF_OVERFLOW_BIT) {
if (se_cmd->data_direction == DMA_TO_DEVICE) {
rsp->flags = SRP_RSP_FLAG_DOOVER;
rsp->data_out_res_cnt = cpu_to_be32(residual_count);
} else if (se_cmd->data_direction == DMA_FROM_DEVICE) {
rsp->flags = SRP_RSP_FLAG_DIOVER;
rsp->data_in_res_cnt = cpu_to_be32(residual_count);
}
}
}
static bool connection_broken(struct scsi_info *vscsi)
{
struct viosrp_crq *crq;
u64 buffer[2] = { 0, 0 };
long h_return_code;
bool rc = false;
crq = (struct viosrp_crq *)&buffer;
crq->valid = VALID_CMD_RESP_EL;
crq->format = MESSAGE_IN_CRQ;
crq->status = PING;
h_return_code = h_send_crq(vscsi->dds.unit_id,
cpu_to_be64(buffer[MSG_HI]),
cpu_to_be64(buffer[MSG_LOW]));
pr_debug("connection_broken: rc %ld\n", h_return_code);
if (h_return_code == H_CLOSED)
rc = true;
return rc;
}
static long ibmvscsis_unregister_command_q(struct scsi_info *vscsi)
{
long qrc;
long rc = ADAPT_SUCCESS;
int ticks = 0;
do {
qrc = h_free_crq(vscsi->dds.unit_id);
switch (qrc) {
case H_SUCCESS:
spin_lock_bh(&vscsi->intr_lock);
vscsi->flags &= ~PREP_FOR_SUSPEND_FLAGS;
spin_unlock_bh(&vscsi->intr_lock);
break;
case H_HARDWARE:
case H_PARAMETER:
dev_err(&vscsi->dev, "unregister_command_q: error from h_free_crq %ld\n",
qrc);
rc = ERROR;
break;
case H_BUSY:
case H_LONG_BUSY_ORDER_1_MSEC:
usleep_range(1000, 2000);
ticks += 1;
break;
case H_LONG_BUSY_ORDER_10_MSEC:
usleep_range(10000, 20000);
ticks += 10;
break;
case H_LONG_BUSY_ORDER_100_MSEC:
msleep(100);
ticks += 100;
break;
case H_LONG_BUSY_ORDER_1_SEC:
ssleep(1);
ticks += 1000;
break;
case H_LONG_BUSY_ORDER_10_SEC:
ssleep(10);
ticks += 10000;
break;
case H_LONG_BUSY_ORDER_100_SEC:
ssleep(100);
ticks += 100000;
break;
default:
dev_err(&vscsi->dev, "unregister_command_q: unknown error %ld from h_free_crq\n",
qrc);
rc = ERROR;
break;
}
if (ticks > 300000 && qrc != H_SUCCESS) {
rc = ERROR;
dev_err(&vscsi->dev, "Excessive wait for h_free_crq\n");
}
} while (qrc != H_SUCCESS && rc == ADAPT_SUCCESS);
pr_debug("Freeing CRQ: phyp rc %ld, rc %ld\n", qrc, rc);
return rc;
}
static void ibmvscsis_delete_client_info(struct scsi_info *vscsi,
bool client_closed)
{
vscsi->client_cap = 0;
if (client_closed)
vscsi->client_data.os_type = 0;
}
static long ibmvscsis_free_command_q(struct scsi_info *vscsi)
{
int bytes;
u32 flags_under_lock;
u16 state_under_lock;
long rc = ADAPT_SUCCESS;
if (!(vscsi->flags & CRQ_CLOSED)) {
vio_disable_interrupts(vscsi->dma_dev);
state_under_lock = vscsi->new_state;
flags_under_lock = vscsi->flags;
vscsi->phyp_acr_state = 0;
vscsi->phyp_acr_flags = 0;
spin_unlock_bh(&vscsi->intr_lock);
rc = ibmvscsis_unregister_command_q(vscsi);
spin_lock_bh(&vscsi->intr_lock);
if (state_under_lock != vscsi->new_state)
vscsi->phyp_acr_state = vscsi->new_state;
vscsi->phyp_acr_flags = ((~flags_under_lock) & vscsi->flags);
if (rc == ADAPT_SUCCESS) {
bytes = vscsi->cmd_q.size * PAGE_SIZE;
memset(vscsi->cmd_q.base_addr, 0, bytes);
vscsi->cmd_q.index = 0;
vscsi->flags |= CRQ_CLOSED;
ibmvscsis_delete_client_info(vscsi, false);
}
pr_debug("free_command_q: flags 0x%x, state 0x%hx, acr_flags 0x%x, acr_state 0x%hx\n",
vscsi->flags, vscsi->state, vscsi->phyp_acr_flags,
vscsi->phyp_acr_state);
}
return rc;
}
static struct viosrp_crq *ibmvscsis_cmd_q_dequeue(uint mask,
uint *current_index,
struct viosrp_crq *base_addr)
{
struct viosrp_crq *ptr;
ptr = base_addr + *current_index;
if (ptr->valid) {
*current_index = (*current_index + 1) & mask;
dma_rmb();
} else {
ptr = NULL;
}
return ptr;
}
static long ibmvscsis_send_init_message(struct scsi_info *vscsi, u8 format)
{
struct viosrp_crq *crq;
u64 buffer[2] = { 0, 0 };
long rc;
crq = (struct viosrp_crq *)&buffer;
crq->valid = VALID_INIT_MSG;
crq->format = format;
rc = h_send_crq(vscsi->dds.unit_id, cpu_to_be64(buffer[MSG_HI]),
cpu_to_be64(buffer[MSG_LOW]));
return rc;
}
static long ibmvscsis_check_init_msg(struct scsi_info *vscsi, uint *format)
{
struct viosrp_crq *crq;
long rc = ADAPT_SUCCESS;
crq = ibmvscsis_cmd_q_dequeue(vscsi->cmd_q.mask, &vscsi->cmd_q.index,
vscsi->cmd_q.base_addr);
if (!crq) {
*format = (uint)UNUSED_FORMAT;
} else if (crq->valid == VALID_INIT_MSG && crq->format == INIT_MSG) {
*format = (uint)INIT_MSG;
crq->valid = INVALIDATE_CMD_RESP_EL;
dma_rmb();
crq = ibmvscsis_cmd_q_dequeue(vscsi->cmd_q.mask,
&vscsi->cmd_q.index,
vscsi->cmd_q.base_addr);
if (crq) {
*format = (uint)(crq->format);
rc = ERROR;
crq->valid = INVALIDATE_CMD_RESP_EL;
dma_rmb();
}
} else {
*format = (uint)(crq->format);
rc = ERROR;
crq->valid = INVALIDATE_CMD_RESP_EL;
dma_rmb();
}
return rc;
}
static void ibmvscsis_disconnect(struct work_struct *work)
{
struct scsi_info *vscsi = container_of(work, struct scsi_info,
proc_work);
u16 new_state;
bool wait_idle = false;
spin_lock_bh(&vscsi->intr_lock);
new_state = vscsi->new_state;
vscsi->new_state = 0;
vscsi->flags |= DISCONNECT_SCHEDULED;
vscsi->flags &= ~SCHEDULE_DISCONNECT;
pr_debug("disconnect: flags 0x%x, state 0x%hx\n", vscsi->flags,
vscsi->state);
switch (vscsi->state) {
case NO_QUEUE:
case UNCONFIGURING:
break;
case ERR_DISCONNECT:
if (new_state == UNCONFIGURING)
vscsi->state = new_state;
break;
case ERR_DISCONNECT_RECONNECT:
switch (new_state) {
case UNCONFIGURING:
case ERR_DISCONNECT:
vscsi->state = new_state;
break;
case WAIT_IDLE:
break;
default:
break;
}
break;
case ERR_DISCONNECTED:
if (new_state == UNCONFIGURING)
vscsi->state = new_state;
break;
case WAIT_ENABLED:
switch (new_state) {
case UNCONFIGURING:
vscsi->state = new_state;
vscsi->flags |= RESPONSE_Q_DOWN;
vscsi->flags &= ~(SCHEDULE_DISCONNECT |
DISCONNECT_SCHEDULED);
dma_rmb();
if (vscsi->flags & CFG_SLEEPING) {
vscsi->flags &= ~CFG_SLEEPING;
complete(&vscsi->unconfig);
}
break;
case ERR_DISCONNECT:
case ERR_DISCONNECT_RECONNECT:
case WAIT_IDLE:
dev_err(&vscsi->dev, "disconnect: invalid state %d for WAIT_IDLE\n",
vscsi->state);
break;
}
break;
case WAIT_IDLE:
switch (new_state) {
case UNCONFIGURING:
vscsi->flags |= RESPONSE_Q_DOWN;
vscsi->state = new_state;
vscsi->flags &= ~(SCHEDULE_DISCONNECT |
DISCONNECT_SCHEDULED);
ibmvscsis_free_command_q(vscsi);
break;
case ERR_DISCONNECT:
case ERR_DISCONNECT_RECONNECT:
vscsi->state = new_state;
break;
}
break;
case WAIT_CONNECTION:
case CONNECTED:
case SRP_PROCESSING:
wait_idle = true;
vscsi->state = new_state;
break;
case UNDEFINED:
if (new_state == UNCONFIGURING)
vscsi->state = new_state;
break;
default:
break;
}
if (wait_idle) {
pr_debug("disconnect start wait, active %d, sched %d\n",
(int)list_empty(&vscsi->active_q),
(int)list_empty(&vscsi->schedule_q));
if (!list_empty(&vscsi->active_q) ||
!list_empty(&vscsi->schedule_q)) {
vscsi->flags |= WAIT_FOR_IDLE;
pr_debug("disconnect flags 0x%x\n", vscsi->flags);
spin_unlock_bh(&vscsi->intr_lock);
wait_for_completion(&vscsi->wait_idle);
spin_lock_bh(&vscsi->intr_lock);
}
pr_debug("disconnect stop wait\n");
ibmvscsis_adapter_idle(vscsi);
}
spin_unlock_bh(&vscsi->intr_lock);
}
static void ibmvscsis_post_disconnect(struct scsi_info *vscsi, uint new_state,
uint flag_bits)
{
uint state;
switch (new_state) {
case UNCONFIGURING:
case ERR_DISCONNECT:
case ERR_DISCONNECT_RECONNECT:
case WAIT_IDLE:
break;
default:
dev_err(&vscsi->dev, "post_disconnect: Invalid new state %d\n",
new_state);
return;
}
vscsi->flags |= flag_bits;
pr_debug("post_disconnect: new_state 0x%x, flag_bits 0x%x, vscsi->flags 0x%x, state %hx\n",
new_state, flag_bits, vscsi->flags, vscsi->state);
if (!(vscsi->flags & (DISCONNECT_SCHEDULED | SCHEDULE_DISCONNECT))) {
vscsi->flags |= SCHEDULE_DISCONNECT;
vscsi->new_state = new_state;
INIT_WORK(&vscsi->proc_work, ibmvscsis_disconnect);
(void)queue_work(vscsi->work_q, &vscsi->proc_work);
} else {
if (vscsi->new_state)
state = vscsi->new_state;
else
state = vscsi->state;
switch (state) {
case NO_QUEUE:
case UNCONFIGURING:
break;
case ERR_DISCONNECTED:
case ERR_DISCONNECT:
case UNDEFINED:
if (new_state == UNCONFIGURING)
vscsi->new_state = new_state;
break;
case ERR_DISCONNECT_RECONNECT:
switch (new_state) {
case UNCONFIGURING:
case ERR_DISCONNECT:
vscsi->new_state = new_state;
break;
default:
break;
}
break;
case WAIT_ENABLED:
case WAIT_IDLE:
case WAIT_CONNECTION:
case CONNECTED:
case SRP_PROCESSING:
vscsi->new_state = new_state;
break;
default:
break;
}
}
pr_debug("Leaving post_disconnect: flags 0x%x, new_state 0x%x\n",
vscsi->flags, vscsi->new_state);
}
static long ibmvscsis_handle_init_compl_msg(struct scsi_info *vscsi)
{
long rc = ADAPT_SUCCESS;
switch (vscsi->state) {
case NO_QUEUE:
case ERR_DISCONNECT:
case ERR_DISCONNECT_RECONNECT:
case ERR_DISCONNECTED:
case UNCONFIGURING:
case UNDEFINED:
rc = ERROR;
break;
case WAIT_CONNECTION:
vscsi->state = CONNECTED;
break;
case WAIT_IDLE:
case SRP_PROCESSING:
case CONNECTED:
case WAIT_ENABLED:
default:
rc = ERROR;
dev_err(&vscsi->dev, "init_msg: invalid state %d to get init compl msg\n",
vscsi->state);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
break;
}
return rc;
}
static long ibmvscsis_handle_init_msg(struct scsi_info *vscsi)
{
long rc = ADAPT_SUCCESS;
switch (vscsi->state) {
case WAIT_CONNECTION:
rc = ibmvscsis_send_init_message(vscsi, INIT_COMPLETE_MSG);
switch (rc) {
case H_SUCCESS:
vscsi->state = CONNECTED;
break;
case H_PARAMETER:
dev_err(&vscsi->dev, "init_msg: failed to send, rc %ld\n",
rc);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT, 0);
break;
case H_DROPPED:
dev_err(&vscsi->dev, "init_msg: failed to send, rc %ld\n",
rc);
rc = ERROR;
ibmvscsis_post_disconnect(vscsi,
ERR_DISCONNECT_RECONNECT, 0);
break;
case H_CLOSED:
pr_warn("init_msg: failed to send, rc %ld\n", rc);
rc = 0;
break;
}
break;
case UNDEFINED:
rc = ERROR;
break;
case UNCONFIGURING:
break;
case WAIT_ENABLED:
case CONNECTED:
case SRP_PROCESSING:
case WAIT_IDLE:
case NO_QUEUE:
case ERR_DISCONNECT:
case ERR_DISCONNECT_RECONNECT:
case ERR_DISCONNECTED:
default:
rc = ERROR;
dev_err(&vscsi->dev, "init_msg: invalid state %d to get init msg\n",
vscsi->state);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
break;
}
return rc;
}
static long ibmvscsis_init_msg(struct scsi_info *vscsi, struct viosrp_crq *crq)
{
long rc = ADAPT_SUCCESS;
pr_debug("init_msg: state 0x%hx\n", vscsi->state);
rc = h_vioctl(vscsi->dds.unit_id, H_GET_PARTNER_INFO,
(u64)vscsi->map_ioba | ((u64)PAGE_SIZE << 32), 0, 0, 0,
0);
if (rc == H_SUCCESS) {
vscsi->client_data.partition_number =
be64_to_cpu(*(u64 *)vscsi->map_buf);
pr_debug("init_msg, part num %d\n",
vscsi->client_data.partition_number);
} else {
pr_debug("init_msg h_vioctl rc %ld\n", rc);
rc = ADAPT_SUCCESS;
}
if (crq->format == INIT_MSG) {
rc = ibmvscsis_handle_init_msg(vscsi);
} else if (crq->format == INIT_COMPLETE_MSG) {
rc = ibmvscsis_handle_init_compl_msg(vscsi);
} else {
rc = ERROR;
dev_err(&vscsi->dev, "init_msg: invalid format %d\n",
(uint)crq->format);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
}
return rc;
}
static long ibmvscsis_establish_new_q(struct scsi_info *vscsi)
{
long rc = ADAPT_SUCCESS;
uint format;
rc = h_vioctl(vscsi->dds.unit_id, H_ENABLE_PREPARE_FOR_SUSPEND, 30000,
0, 0, 0, 0);
if (rc == H_SUCCESS)
vscsi->flags |= PREP_FOR_SUSPEND_ENABLED;
else if (rc != H_NOT_FOUND)
pr_err("Error from Enable Prepare for Suspend: %ld\n", rc);
vscsi->flags &= PRESERVE_FLAG_FIELDS;
vscsi->rsp_q_timer.timer_pops = 0;
vscsi->debit = 0;
vscsi->credit = 0;
rc = vio_enable_interrupts(vscsi->dma_dev);
if (rc) {
pr_warn("establish_new_q: failed to enable interrupts, rc %ld\n",
rc);
return rc;
}
rc = ibmvscsis_check_init_msg(vscsi, &format);
if (rc) {
dev_err(&vscsi->dev, "establish_new_q: check_init_msg failed, rc %ld\n",
rc);
return rc;
}
if (format == UNUSED_FORMAT) {
rc = ibmvscsis_send_init_message(vscsi, INIT_MSG);
switch (rc) {
case H_SUCCESS:
case H_DROPPED:
case H_CLOSED:
rc = ADAPT_SUCCESS;
break;
case H_PARAMETER:
case H_HARDWARE:
break;
default:
vscsi->state = UNDEFINED;
rc = H_HARDWARE;
break;
}
} else if (format == INIT_MSG) {
rc = ibmvscsis_handle_init_msg(vscsi);
}
return rc;
}
static void ibmvscsis_reset_queue(struct scsi_info *vscsi)
{
int bytes;
long rc = ADAPT_SUCCESS;
pr_debug("reset_queue: flags 0x%x\n", vscsi->flags);
if (vscsi->flags & (CLIENT_FAILED | TRANS_EVENT)) {
vscsi->flags &= PRESERVE_FLAG_FIELDS;
vscsi->rsp_q_timer.timer_pops = 0;
vscsi->debit = 0;
vscsi->credit = 0;
vscsi->state = WAIT_CONNECTION;
vio_enable_interrupts(vscsi->dma_dev);
} else {
rc = ibmvscsis_free_command_q(vscsi);
if (rc == ADAPT_SUCCESS) {
vscsi->state = WAIT_CONNECTION;
bytes = vscsi->cmd_q.size * PAGE_SIZE;
rc = h_reg_crq(vscsi->dds.unit_id,
vscsi->cmd_q.crq_token, bytes);
if (rc == H_CLOSED || rc == H_SUCCESS) {
rc = ibmvscsis_establish_new_q(vscsi);
}
if (rc != ADAPT_SUCCESS) {
pr_debug("reset_queue: reg_crq rc %ld\n", rc);
vscsi->state = ERR_DISCONNECTED;
vscsi->flags |= RESPONSE_Q_DOWN;
ibmvscsis_free_command_q(vscsi);
}
} else {
vscsi->state = ERR_DISCONNECTED;
vscsi->flags |= RESPONSE_Q_DOWN;
}
}
}
static void ibmvscsis_free_cmd_resources(struct scsi_info *vscsi,
struct ibmvscsis_cmd *cmd)
{
struct iu_entry *iue = cmd->iue;
switch (cmd->type) {
case TASK_MANAGEMENT:
case SCSI_CDB:
if (vscsi->debit)
vscsi->debit -= 1;
break;
case ADAPTER_MAD:
vscsi->flags &= ~PROCESSING_MAD;
break;
case UNSET_TYPE:
break;
default:
dev_err(&vscsi->dev, "free_cmd_resources unknown type %d\n",
cmd->type);
break;
}
cmd->iue = NULL;
list_add_tail(&cmd->list, &vscsi->free_cmd);
srp_iu_put(iue);
if (list_empty(&vscsi->active_q) && list_empty(&vscsi->schedule_q) &&
list_empty(&vscsi->waiting_rsp) && (vscsi->flags & WAIT_FOR_IDLE)) {
vscsi->flags &= ~WAIT_FOR_IDLE;
complete(&vscsi->wait_idle);
}
}
static long ibmvscsis_ready_for_suspend(struct scsi_info *vscsi, bool idle)
{
long rc = 0;
struct viosrp_crq *crq;
crq = vscsi->cmd_q.base_addr + vscsi->cmd_q.index;
pr_debug("ready_suspend: flags 0x%x, state 0x%hx crq_valid:%x\n",
vscsi->flags, vscsi->state, (int)crq->valid);
if (!(vscsi->flags & PREP_FOR_SUSPEND_ABORTED) && !(crq->valid)) {
rc = h_vioctl(vscsi->dds.unit_id, H_READY_FOR_SUSPEND, 0, 0, 0,
0, 0);
if (rc) {
pr_err("Ready for Suspend Vioctl failed: %ld\n", rc);
rc = 0;
}
} else if (((vscsi->flags & PREP_FOR_SUSPEND_OVERWRITE) &&
(vscsi->flags & PREP_FOR_SUSPEND_ABORTED)) ||
((crq->valid) && ((crq->valid != VALID_TRANS_EVENT) ||
(crq->format != RESUME_FROM_SUSP)))) {
if (idle) {
vscsi->state = ERR_DISCONNECT_RECONNECT;
ibmvscsis_reset_queue(vscsi);
rc = -1;
} else if (vscsi->state == CONNECTED) {
ibmvscsis_post_disconnect(vscsi,
ERR_DISCONNECT_RECONNECT, 0);
}
vscsi->flags &= ~PREP_FOR_SUSPEND_OVERWRITE;
if ((crq->valid) && ((crq->valid != VALID_TRANS_EVENT) ||
(crq->format != RESUME_FROM_SUSP)))
pr_err("Invalid element in CRQ after Prepare for Suspend");
}
vscsi->flags &= ~(PREP_FOR_SUSPEND_PENDING | PREP_FOR_SUSPEND_ABORTED);
return rc;
}
static long ibmvscsis_trans_event(struct scsi_info *vscsi,
struct viosrp_crq *crq)
{
long rc = ADAPT_SUCCESS;
pr_debug("trans_event: format %d, flags 0x%x, state 0x%hx\n",
(int)crq->format, vscsi->flags, vscsi->state);
switch (crq->format) {
case MIGRATED:
case PARTNER_FAILED:
case PARTNER_DEREGISTER:
ibmvscsis_delete_client_info(vscsi, true);
if (crq->format == MIGRATED)
vscsi->flags &= ~PREP_FOR_SUSPEND_OVERWRITE;
switch (vscsi->state) {
case NO_QUEUE:
case ERR_DISCONNECTED:
case UNDEFINED:
break;
case UNCONFIGURING:
vscsi->flags |= (RESPONSE_Q_DOWN | TRANS_EVENT);
break;
case WAIT_ENABLED:
break;
case WAIT_CONNECTION:
break;
case CONNECTED:
ibmvscsis_post_disconnect(vscsi, WAIT_IDLE,
(RESPONSE_Q_DOWN |
TRANS_EVENT));
break;
case SRP_PROCESSING:
if ((vscsi->debit > 0) ||
!list_empty(&vscsi->schedule_q) ||
!list_empty(&vscsi->waiting_rsp) ||
!list_empty(&vscsi->active_q)) {
pr_debug("debit %d, sched %d, wait %d, active %d\n",
vscsi->debit,
(int)list_empty(&vscsi->schedule_q),
(int)list_empty(&vscsi->waiting_rsp),
(int)list_empty(&vscsi->active_q));
pr_warn("connection lost with outstanding work\n");
} else {
pr_debug("trans_event: SRP Processing, but no outstanding work\n");
}
ibmvscsis_post_disconnect(vscsi, WAIT_IDLE,
(RESPONSE_Q_DOWN |
TRANS_EVENT));
break;
case ERR_DISCONNECT:
case ERR_DISCONNECT_RECONNECT:
case WAIT_IDLE:
vscsi->flags |= (RESPONSE_Q_DOWN | TRANS_EVENT);
break;
}
break;
case PREPARE_FOR_SUSPEND:
pr_debug("Prep for Suspend, crq status = 0x%x\n",
(int)crq->status);
switch (vscsi->state) {
case ERR_DISCONNECTED:
case WAIT_CONNECTION:
case CONNECTED:
ibmvscsis_ready_for_suspend(vscsi, false);
break;
case SRP_PROCESSING:
vscsi->resume_state = vscsi->state;
vscsi->flags |= PREP_FOR_SUSPEND_PENDING;
if (crq->status == CRQ_ENTRY_OVERWRITTEN)
vscsi->flags |= PREP_FOR_SUSPEND_OVERWRITE;
ibmvscsis_post_disconnect(vscsi, WAIT_IDLE, 0);
break;
case NO_QUEUE:
case UNDEFINED:
case UNCONFIGURING:
case WAIT_ENABLED:
case ERR_DISCONNECT:
case ERR_DISCONNECT_RECONNECT:
case WAIT_IDLE:
pr_err("Invalid state for Prepare for Suspend Trans Event: 0x%x\n",
vscsi->state);
break;
}
break;
case RESUME_FROM_SUSP:
pr_debug("Resume from Suspend, crq status = 0x%x\n",
(int)crq->status);
if (vscsi->flags & PREP_FOR_SUSPEND_PENDING) {
vscsi->flags |= PREP_FOR_SUSPEND_ABORTED;
} else {
if ((crq->status == CRQ_ENTRY_OVERWRITTEN) ||
(vscsi->flags & PREP_FOR_SUSPEND_OVERWRITE)) {
ibmvscsis_post_disconnect(vscsi,
ERR_DISCONNECT_RECONNECT,
0);
vscsi->flags &= ~PREP_FOR_SUSPEND_OVERWRITE;
}
}
break;
default:
rc = ERROR;
dev_err(&vscsi->dev, "trans_event: invalid format %d\n",
(uint)crq->format);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT,
RESPONSE_Q_DOWN);
break;
}
rc = vscsi->flags & SCHEDULE_DISCONNECT;
pr_debug("Leaving trans_event: flags 0x%x, state 0x%hx, rc %ld\n",
vscsi->flags, vscsi->state, rc);
return rc;
}
static void ibmvscsis_poll_cmd_q(struct scsi_info *vscsi)
{
struct viosrp_crq *crq;
long rc;
bool ack = true;
volatile u8 valid;
pr_debug("poll_cmd_q: flags 0x%x, state 0x%hx, q index %ud\n",
vscsi->flags, vscsi->state, vscsi->cmd_q.index);
rc = vscsi->flags & SCHEDULE_DISCONNECT;
crq = vscsi->cmd_q.base_addr + vscsi->cmd_q.index;
valid = crq->valid;
dma_rmb();
while (valid) {
poll_work:
vscsi->cmd_q.index =
(vscsi->cmd_q.index + 1) & vscsi->cmd_q.mask;
if (!rc) {
rc = ibmvscsis_parse_command(vscsi, crq);
} else {
if ((uint)crq->valid == VALID_TRANS_EVENT) {
rc = ibmvscsis_trans_event(vscsi, crq);
} else if (vscsi->flags & TRANS_EVENT) {
pr_debug("poll_cmd_q, ignoring\n");
if (vscsi->cmd_q.index)
vscsi->cmd_q.index -= 1;
else
vscsi->cmd_q.index = vscsi->cmd_q.mask;
break;
}
}
crq->valid = INVALIDATE_CMD_RESP_EL;
crq = vscsi->cmd_q.base_addr + vscsi->cmd_q.index;
valid = crq->valid;
dma_rmb();
}
if (!rc) {
if (ack) {
vio_enable_interrupts(vscsi->dma_dev);
ack = false;
pr_debug("poll_cmd_q, reenabling interrupts\n");
}
valid = crq->valid;
dma_rmb();
if (valid)
goto poll_work;
}
pr_debug("Leaving poll_cmd_q: rc %ld\n", rc);
}
static void ibmvscsis_free_cmd_qs(struct scsi_info *vscsi)
{
struct ibmvscsis_cmd *cmd, *nxt;
pr_debug("free_cmd_qs: waiting_rsp empty %d, timer starter %d\n",
(int)list_empty(&vscsi->waiting_rsp),
vscsi->rsp_q_timer.started);
list_for_each_entry_safe(cmd, nxt, &vscsi->waiting_rsp, list) {
list_del(&cmd->list);
ibmvscsis_free_cmd_resources(vscsi, cmd);
}
}
static struct ibmvscsis_cmd *ibmvscsis_get_free_cmd(struct scsi_info *vscsi)
{
struct ibmvscsis_cmd *cmd = NULL;
struct iu_entry *iue;
iue = srp_iu_get(&vscsi->target);
if (iue) {
cmd = list_first_entry_or_null(&vscsi->free_cmd,
struct ibmvscsis_cmd, list);
if (cmd) {
if (cmd->abort_cmd)
cmd->abort_cmd = NULL;
cmd->flags &= ~(DELAY_SEND);
list_del(&cmd->list);
cmd->iue = iue;
cmd->type = UNSET_TYPE;
memset(&cmd->se_cmd, 0, sizeof(cmd->se_cmd));
} else {
srp_iu_put(iue);
}
}
return cmd;
}
static void ibmvscsis_adapter_idle(struct scsi_info *vscsi)
{
int free_qs = false;
long rc = 0;
pr_debug("adapter_idle: flags 0x%x, state 0x%hx\n", vscsi->flags,
vscsi->state);
if (vscsi->state != WAIT_CONNECTION || vscsi->flags & TRANS_EVENT)
free_qs = true;
switch (vscsi->state) {
case UNCONFIGURING:
ibmvscsis_free_command_q(vscsi);
dma_rmb();
isync();
if (vscsi->flags & CFG_SLEEPING) {
vscsi->flags &= ~CFG_SLEEPING;
complete(&vscsi->unconfig);
}
break;
case ERR_DISCONNECT_RECONNECT:
ibmvscsis_reset_queue(vscsi);
pr_debug("adapter_idle, disc_rec: flags 0x%x\n", vscsi->flags);
break;
case ERR_DISCONNECT:
ibmvscsis_free_command_q(vscsi);
vscsi->flags &= ~(SCHEDULE_DISCONNECT | DISCONNECT_SCHEDULED);
vscsi->flags |= RESPONSE_Q_DOWN;
if (vscsi->tport.enabled)
vscsi->state = ERR_DISCONNECTED;
else
vscsi->state = WAIT_ENABLED;
pr_debug("adapter_idle, disc: flags 0x%x, state 0x%hx\n",
vscsi->flags, vscsi->state);
break;
case WAIT_IDLE:
vscsi->rsp_q_timer.timer_pops = 0;
vscsi->debit = 0;
vscsi->credit = 0;
if (vscsi->flags & PREP_FOR_SUSPEND_PENDING) {
vscsi->state = vscsi->resume_state;
vscsi->resume_state = 0;
rc = ibmvscsis_ready_for_suspend(vscsi, true);
vscsi->flags &= ~DISCONNECT_SCHEDULED;
if (rc)
break;
} else if (vscsi->flags & TRANS_EVENT) {
vscsi->state = WAIT_CONNECTION;
vscsi->flags &= PRESERVE_FLAG_FIELDS;
} else {
vscsi->state = CONNECTED;
vscsi->flags &= ~DISCONNECT_SCHEDULED;
}
pr_debug("adapter_idle, wait: flags 0x%x, state 0x%hx\n",
vscsi->flags, vscsi->state);
ibmvscsis_poll_cmd_q(vscsi);
break;
case ERR_DISCONNECTED:
vscsi->flags &= ~DISCONNECT_SCHEDULED;
pr_debug("adapter_idle, disconnected: flags 0x%x, state 0x%hx\n",
vscsi->flags, vscsi->state);
break;
default:
dev_err(&vscsi->dev, "adapter_idle: in invalid state %d\n",
vscsi->state);
break;
}
if (free_qs)
ibmvscsis_free_cmd_qs(vscsi);
if (vscsi->phyp_acr_state != 0) {
vscsi->flags |= vscsi->phyp_acr_flags;
ibmvscsis_post_disconnect(vscsi, vscsi->phyp_acr_state, 0);
vscsi->phyp_acr_state = 0;
vscsi->phyp_acr_flags = 0;
pr_debug("adapter_idle: flags 0x%x, state 0x%hx, acr_flags 0x%x, acr_state 0x%hx\n",
vscsi->flags, vscsi->state, vscsi->phyp_acr_flags,
vscsi->phyp_acr_state);
}
pr_debug("Leaving adapter_idle: flags 0x%x, state 0x%hx, new_state 0x%x\n",
vscsi->flags, vscsi->state, vscsi->new_state);
}
static long ibmvscsis_copy_crq_packet(struct scsi_info *vscsi,
struct ibmvscsis_cmd *cmd,
struct viosrp_crq *crq)
{
struct iu_entry *iue = cmd->iue;
long rc = 0;
u16 len;
len = be16_to_cpu(crq->IU_length);
if ((len > SRP_MAX_IU_LEN) || (len == 0)) {
dev_err(&vscsi->dev, "copy_crq: Invalid len %d passed", len);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
return SRP_VIOLATION;
}
rc = h_copy_rdma(len, vscsi->dds.window[REMOTE].liobn,
be64_to_cpu(crq->IU_data_ptr),
vscsi->dds.window[LOCAL].liobn, iue->sbuf->dma);
switch (rc) {
case H_SUCCESS:
cmd->init_time = mftb();
iue->remote_token = crq->IU_data_ptr;
iue->iu_len = len;
pr_debug("copy_crq: ioba 0x%llx, init_time 0x%llx\n",
be64_to_cpu(crq->IU_data_ptr), cmd->init_time);
break;
case H_PERMISSION:
if (connection_broken(vscsi))
ibmvscsis_post_disconnect(vscsi,
ERR_DISCONNECT_RECONNECT,
(RESPONSE_Q_DOWN |
CLIENT_FAILED));
else
ibmvscsis_post_disconnect(vscsi,
ERR_DISCONNECT_RECONNECT, 0);
dev_err(&vscsi->dev, "copy_crq: h_copy_rdma failed, rc %ld\n",
rc);
break;
case H_DEST_PARM:
case H_SOURCE_PARM:
default:
dev_err(&vscsi->dev, "copy_crq: h_copy_rdma failed, rc %ld\n",
rc);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
break;
}
return rc;
}
static long ibmvscsis_adapter_info(struct scsi_info *vscsi,
struct iu_entry *iue)
{
struct viosrp_adapter_info *mad = &vio_iu(iue)->mad.adapter_info;
struct mad_adapter_info_data *info;
uint flag_bits = 0;
dma_addr_t token;
long rc;
mad->common.status = cpu_to_be16(VIOSRP_MAD_SUCCESS);
if (be16_to_cpu(mad->common.length) > sizeof(*info)) {
mad->common.status = cpu_to_be16(VIOSRP_MAD_FAILED);
return 0;
}
info = dma_alloc_coherent(&vscsi->dma_dev->dev, sizeof(*info), &token,
GFP_ATOMIC);
if (!info) {
dev_err(&vscsi->dev, "bad dma_alloc_coherent %p\n",
iue->target);
mad->common.status = cpu_to_be16(VIOSRP_MAD_FAILED);
return 0;
}
rc = h_copy_rdma(be16_to_cpu(mad->common.length),
vscsi->dds.window[REMOTE].liobn,
be64_to_cpu(mad->buffer),
vscsi->dds.window[LOCAL].liobn, token);
if (rc != H_SUCCESS) {
if (rc == H_PERMISSION) {
if (connection_broken(vscsi))
flag_bits = (RESPONSE_Q_DOWN | CLIENT_FAILED);
}
pr_warn("adapter_info: h_copy_rdma from client failed, rc %ld\n",
rc);
pr_debug("adapter_info: ioba 0x%llx, flags 0x%x, flag_bits 0x%x\n",
be64_to_cpu(mad->buffer), vscsi->flags, flag_bits);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT,
flag_bits);
goto free_dma;
}
if (vscsi->client_data.partition_number == 0)
vscsi->client_data.partition_number =
be32_to_cpu(info->partition_number);
strncpy(vscsi->client_data.srp_version, info->srp_version,
sizeof(vscsi->client_data.srp_version));
strncpy(vscsi->client_data.partition_name, info->partition_name,
sizeof(vscsi->client_data.partition_name));
vscsi->client_data.mad_version = be32_to_cpu(info->mad_version);
vscsi->client_data.os_type = be32_to_cpu(info->os_type);
strncpy(info->srp_version, SRP_VERSION,
sizeof(info->srp_version));
strncpy(info->partition_name, vscsi->dds.partition_name,
sizeof(info->partition_name));
info->partition_number = cpu_to_be32(vscsi->dds.partition_num);
info->mad_version = cpu_to_be32(MAD_VERSION_1);
info->os_type = cpu_to_be32(LINUX);
memset(&info->port_max_txu[0], 0, sizeof(info->port_max_txu));
info->port_max_txu[0] = cpu_to_be32(MAX_TXU);
dma_wmb();
rc = h_copy_rdma(sizeof(*info), vscsi->dds.window[LOCAL].liobn,
token, vscsi->dds.window[REMOTE].liobn,
be64_to_cpu(mad->buffer));
switch (rc) {
case H_SUCCESS:
break;
case H_SOURCE_PARM:
case H_DEST_PARM:
case H_PERMISSION:
if (connection_broken(vscsi))
flag_bits = (RESPONSE_Q_DOWN | CLIENT_FAILED);
default:
dev_err(&vscsi->dev, "adapter_info: h_copy_rdma to client failed, rc %ld\n",
rc);
ibmvscsis_post_disconnect(vscsi,
ERR_DISCONNECT_RECONNECT,
flag_bits);
break;
}
free_dma:
dma_free_coherent(&vscsi->dma_dev->dev, sizeof(*info), info, token);
pr_debug("Leaving adapter_info, rc %ld\n", rc);
return rc;
}
static int ibmvscsis_cap_mad(struct scsi_info *vscsi, struct iu_entry *iue)
{
struct viosrp_capabilities *mad = &vio_iu(iue)->mad.capabilities;
struct capabilities *cap;
struct mad_capability_common *common;
dma_addr_t token;
u16 olen, len, status, min_len, cap_len;
u32 flag;
uint flag_bits = 0;
long rc = 0;
olen = be16_to_cpu(mad->common.length);
min_len = offsetof(struct capabilities, migration);
if ((olen < min_len) || (olen > PAGE_SIZE)) {
pr_warn("cap_mad: invalid len %d\n", olen);
mad->common.status = cpu_to_be16(VIOSRP_MAD_FAILED);
return 0;
}
cap = dma_alloc_coherent(&vscsi->dma_dev->dev, olen, &token,
GFP_ATOMIC);
if (!cap) {
dev_err(&vscsi->dev, "bad dma_alloc_coherent %p\n",
iue->target);
mad->common.status = cpu_to_be16(VIOSRP_MAD_FAILED);
return 0;
}
rc = h_copy_rdma(olen, vscsi->dds.window[REMOTE].liobn,
be64_to_cpu(mad->buffer),
vscsi->dds.window[LOCAL].liobn, token);
if (rc == H_SUCCESS) {
strncpy(cap->name, dev_name(&vscsi->dma_dev->dev),
SRP_MAX_LOC_LEN);
len = olen - min_len;
status = VIOSRP_MAD_SUCCESS;
common = (struct mad_capability_common *)&cap->migration;
while ((len > 0) && (status == VIOSRP_MAD_SUCCESS) && !rc) {
pr_debug("cap_mad: len left %hd, cap type %d, cap len %hd\n",
len, be32_to_cpu(common->cap_type),
be16_to_cpu(common->length));
cap_len = be16_to_cpu(common->length);
if (cap_len > len) {
dev_err(&vscsi->dev, "cap_mad: cap len mismatch with total len\n");
status = VIOSRP_MAD_FAILED;
break;
}
if (cap_len == 0) {
dev_err(&vscsi->dev, "cap_mad: cap len is 0\n");
status = VIOSRP_MAD_FAILED;
break;
}
switch (common->cap_type) {
default:
pr_debug("cap_mad: unsupported capability\n");
common->server_support = 0;
flag = cpu_to_be32((u32)CAP_LIST_SUPPORTED);
cap->flags &= ~flag;
break;
}
len = len - cap_len;
common = (struct mad_capability_common *)
((char *)common + cap_len);
}
mad->common.status = cpu_to_be16(status);
dma_wmb();
rc = h_copy_rdma(olen, vscsi->dds.window[LOCAL].liobn, token,
vscsi->dds.window[REMOTE].liobn,
be64_to_cpu(mad->buffer));
if (rc != H_SUCCESS) {
pr_debug("cap_mad: failed to copy to client, rc %ld\n",
rc);
if (rc == H_PERMISSION) {
if (connection_broken(vscsi))
flag_bits = (RESPONSE_Q_DOWN |
CLIENT_FAILED);
}
pr_warn("cap_mad: error copying data to client, rc %ld\n",
rc);
ibmvscsis_post_disconnect(vscsi,
ERR_DISCONNECT_RECONNECT,
flag_bits);
}
}
dma_free_coherent(&vscsi->dma_dev->dev, olen, cap, token);
pr_debug("Leaving cap_mad, rc %ld, client_cap 0x%x\n",
rc, vscsi->client_cap);
return rc;
}
static long ibmvscsis_process_mad(struct scsi_info *vscsi, struct iu_entry *iue)
{
struct mad_common *mad = (struct mad_common *)&vio_iu(iue)->mad;
struct viosrp_empty_iu *empty;
long rc = ADAPT_SUCCESS;
switch (be32_to_cpu(mad->type)) {
case VIOSRP_EMPTY_IU_TYPE:
empty = &vio_iu(iue)->mad.empty_iu;
vscsi->empty_iu_id = be64_to_cpu(empty->buffer);
vscsi->empty_iu_tag = be64_to_cpu(empty->common.tag);
mad->status = cpu_to_be16(VIOSRP_MAD_SUCCESS);
break;
case VIOSRP_ADAPTER_INFO_TYPE:
rc = ibmvscsis_adapter_info(vscsi, iue);
break;
case VIOSRP_CAPABILITIES_TYPE:
rc = ibmvscsis_cap_mad(vscsi, iue);
break;
case VIOSRP_ENABLE_FAST_FAIL:
if (vscsi->state == CONNECTED) {
vscsi->fast_fail = true;
mad->status = cpu_to_be16(VIOSRP_MAD_SUCCESS);
} else {
pr_warn("fast fail mad sent after login\n");
mad->status = cpu_to_be16(VIOSRP_MAD_FAILED);
}
break;
default:
mad->status = cpu_to_be16(VIOSRP_MAD_NOT_SUPPORTED);
break;
}
return rc;
}
static void srp_snd_msg_failed(struct scsi_info *vscsi, long rc)
{
ktime_t kt;
if (rc != H_DROPPED) {
ibmvscsis_free_cmd_qs(vscsi);
if (rc == H_CLOSED)
vscsi->flags |= CLIENT_FAILED;
if (!(vscsi->flags & RESPONSE_Q_DOWN)) {
vscsi->flags |= RESPONSE_Q_DOWN;
if (!(vscsi->state & (ERR_DISCONNECT |
ERR_DISCONNECT_RECONNECT |
ERR_DISCONNECTED | UNDEFINED))) {
dev_err(&vscsi->dev, "snd_msg_failed: setting RESPONSE_Q_DOWN, state 0x%hx, flags 0x%x, rc %ld\n",
vscsi->state, vscsi->flags, rc);
}
ibmvscsis_post_disconnect(vscsi,
ERR_DISCONNECT_RECONNECT, 0);
}
return;
}
if ((vscsi->rsp_q_timer.timer_pops < MAX_TIMER_POPS) ||
(vscsi->state == SRP_PROCESSING)) {
pr_debug("snd_msg_failed: response queue full, flags 0x%x, timer started %d, pops %d\n",
vscsi->flags, (int)vscsi->rsp_q_timer.started,
vscsi->rsp_q_timer.timer_pops);
if (!vscsi->rsp_q_timer.started) {
if (vscsi->rsp_q_timer.timer_pops <
MAX_TIMER_POPS) {
kt = WAIT_NANO_SECONDS;
} else {
kt = ktime_set(WAIT_SECONDS, 0);
}
vscsi->rsp_q_timer.started = true;
hrtimer_start(&vscsi->rsp_q_timer.timer, kt,
HRTIMER_MODE_REL);
}
} else {
vscsi->flags |= RESPONSE_Q_DOWN;
ibmvscsis_free_cmd_qs(vscsi);
if (!(vscsi->state & (ERR_DISCONNECT |
ERR_DISCONNECT_RECONNECT |
ERR_DISCONNECTED | UNDEFINED))) {
dev_err(&vscsi->dev, "client crq full too long\n");
ibmvscsis_post_disconnect(vscsi,
ERR_DISCONNECT_RECONNECT,
0);
}
}
}
static void ibmvscsis_send_messages(struct scsi_info *vscsi)
{
u64 msg_hi = 0;
struct viosrp_crq *crq = (struct viosrp_crq *)&msg_hi;
struct ibmvscsis_cmd *cmd, *nxt;
struct iu_entry *iue;
long rc = ADAPT_SUCCESS;
bool retry = false;
if (!(vscsi->flags & RESPONSE_Q_DOWN)) {
do {
retry = false;
list_for_each_entry_safe(cmd, nxt, &vscsi->waiting_rsp,
list) {
if (cmd->flags & DELAY_SEND)
continue;
if (cmd->abort_cmd) {
retry = true;
cmd->abort_cmd->flags &= ~(DELAY_SEND);
cmd->abort_cmd = NULL;
}
if (cmd->se_cmd.transport_state & CMD_T_ABORTED &&
!(cmd->se_cmd.transport_state & CMD_T_TAS)) {
list_del(&cmd->list);
ibmvscsis_free_cmd_resources(vscsi,
cmd);
vscsi->credit += 1;
} else {
iue = cmd->iue;
crq->valid = VALID_CMD_RESP_EL;
crq->format = cmd->rsp.format;
if (cmd->flags & CMD_FAST_FAIL)
crq->status = VIOSRP_ADAPTER_FAIL;
crq->IU_length = cpu_to_be16(cmd->rsp.len);
rc = h_send_crq(vscsi->dma_dev->unit_address,
be64_to_cpu(msg_hi),
be64_to_cpu(cmd->rsp.tag));
pr_debug("send_messages: cmd %p, tag 0x%llx, rc %ld\n",
cmd, be64_to_cpu(cmd->rsp.tag), rc);
if (rc == H_SUCCESS) {
vscsi->rsp_q_timer.timer_pops = 0;
list_del(&cmd->list);
ibmvscsis_free_cmd_resources(vscsi,
cmd);
} else {
srp_snd_msg_failed(vscsi, rc);
break;
}
}
}
} while (retry);
if (!rc) {
vscsi->rsp_q_timer.timer_pops = 0;
}
} else {
ibmvscsis_free_cmd_qs(vscsi);
}
}
static void ibmvscsis_send_mad_resp(struct scsi_info *vscsi,
struct ibmvscsis_cmd *cmd,
struct viosrp_crq *crq)
{
struct iu_entry *iue = cmd->iue;
struct mad_common *mad = (struct mad_common *)&vio_iu(iue)->mad;
uint flag_bits = 0;
long rc;
dma_wmb();
rc = h_copy_rdma(sizeof(struct mad_common),
vscsi->dds.window[LOCAL].liobn, iue->sbuf->dma,
vscsi->dds.window[REMOTE].liobn,
be64_to_cpu(crq->IU_data_ptr));
if (!rc) {
cmd->rsp.format = VIOSRP_MAD_FORMAT;
cmd->rsp.len = sizeof(struct mad_common);
cmd->rsp.tag = mad->tag;
list_add_tail(&cmd->list, &vscsi->waiting_rsp);
ibmvscsis_send_messages(vscsi);
} else {
pr_debug("Error sending mad response, rc %ld\n", rc);
if (rc == H_PERMISSION) {
if (connection_broken(vscsi))
flag_bits = (RESPONSE_Q_DOWN | CLIENT_FAILED);
}
dev_err(&vscsi->dev, "mad: failed to copy to client, rc %ld\n",
rc);
ibmvscsis_free_cmd_resources(vscsi, cmd);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT,
flag_bits);
}
}
static long ibmvscsis_mad(struct scsi_info *vscsi, struct viosrp_crq *crq)
{
struct iu_entry *iue;
struct ibmvscsis_cmd *cmd;
struct mad_common *mad;
long rc = ADAPT_SUCCESS;
switch (vscsi->state) {
case WAIT_CONNECTION:
pr_debug("mad: in Wait Connection state, ignoring MAD, flags %d\n",
vscsi->flags);
return ADAPT_SUCCESS;
case SRP_PROCESSING:
case CONNECTED:
break;
case UNCONFIGURING:
case WAIT_IDLE:
case ERR_DISCONNECT:
case ERR_DISCONNECT_RECONNECT:
default:
dev_err(&vscsi->dev, "mad: invalid adapter state %d for mad\n",
vscsi->state);
return ADAPT_SUCCESS;
}
cmd = ibmvscsis_get_free_cmd(vscsi);
if (!cmd) {
dev_err(&vscsi->dev, "mad: failed to get cmd, debit %d\n",
vscsi->debit);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
return ERROR;
}
iue = cmd->iue;
cmd->type = ADAPTER_MAD;
rc = ibmvscsis_copy_crq_packet(vscsi, cmd, crq);
if (!rc) {
mad = (struct mad_common *)&vio_iu(iue)->mad;
pr_debug("mad: type %d\n", be32_to_cpu(mad->type));
rc = ibmvscsis_process_mad(vscsi, iue);
pr_debug("mad: status %hd, rc %ld\n", be16_to_cpu(mad->status),
rc);
if (!rc)
ibmvscsis_send_mad_resp(vscsi, cmd, crq);
} else {
ibmvscsis_free_cmd_resources(vscsi, cmd);
}
pr_debug("Leaving mad, rc %ld\n", rc);
return rc;
}
static long ibmvscsis_login_rsp(struct scsi_info *vscsi,
struct ibmvscsis_cmd *cmd)
{
struct iu_entry *iue = cmd->iue;
struct srp_login_rsp *rsp = &vio_iu(iue)->srp.login_rsp;
struct format_code *fmt;
uint flag_bits = 0;
long rc = ADAPT_SUCCESS;
memset(rsp, 0, sizeof(struct srp_login_rsp));
rsp->opcode = SRP_LOGIN_RSP;
rsp->req_lim_delta = cpu_to_be32(vscsi->request_limit);
rsp->tag = cmd->rsp.tag;
rsp->max_it_iu_len = cpu_to_be32(SRP_MAX_IU_LEN);
rsp->max_ti_iu_len = cpu_to_be32(SRP_MAX_IU_LEN);
fmt = (struct format_code *)&rsp->buf_fmt;
fmt->buffers = SUPPORTED_FORMATS;
vscsi->credit = 0;
cmd->rsp.len = sizeof(struct srp_login_rsp);
dma_wmb();
rc = h_copy_rdma(cmd->rsp.len, vscsi->dds.window[LOCAL].liobn,
iue->sbuf->dma, vscsi->dds.window[REMOTE].liobn,
be64_to_cpu(iue->remote_token));
switch (rc) {
case H_SUCCESS:
break;
case H_PERMISSION:
if (connection_broken(vscsi))
flag_bits = RESPONSE_Q_DOWN | CLIENT_FAILED;
dev_err(&vscsi->dev, "login_rsp: error copying to client, rc %ld\n",
rc);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT,
flag_bits);
break;
case H_SOURCE_PARM:
case H_DEST_PARM:
default:
dev_err(&vscsi->dev, "login_rsp: error copying to client, rc %ld\n",
rc);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
break;
}
return rc;
}
static long ibmvscsis_srp_login_rej(struct scsi_info *vscsi,
struct ibmvscsis_cmd *cmd, u32 reason)
{
struct iu_entry *iue = cmd->iue;
struct srp_login_rej *rej = &vio_iu(iue)->srp.login_rej;
struct format_code *fmt;
uint flag_bits = 0;
long rc = ADAPT_SUCCESS;
memset(rej, 0, sizeof(*rej));
rej->opcode = SRP_LOGIN_REJ;
rej->reason = cpu_to_be32(reason);
rej->tag = cmd->rsp.tag;
fmt = (struct format_code *)&rej->buf_fmt;
fmt->buffers = SUPPORTED_FORMATS;
cmd->rsp.len = sizeof(*rej);
dma_wmb();
rc = h_copy_rdma(cmd->rsp.len, vscsi->dds.window[LOCAL].liobn,
iue->sbuf->dma, vscsi->dds.window[REMOTE].liobn,
be64_to_cpu(iue->remote_token));
switch (rc) {
case H_SUCCESS:
break;
case H_PERMISSION:
if (connection_broken(vscsi))
flag_bits = RESPONSE_Q_DOWN | CLIENT_FAILED;
dev_err(&vscsi->dev, "login_rej: error copying to client, rc %ld\n",
rc);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT,
flag_bits);
break;
case H_SOURCE_PARM:
case H_DEST_PARM:
default:
dev_err(&vscsi->dev, "login_rej: error copying to client, rc %ld\n",
rc);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
break;
}
return rc;
}
static int ibmvscsis_make_nexus(struct ibmvscsis_tport *tport)
{
char *name = tport->tport_name;
struct ibmvscsis_nexus *nexus;
int rc;
if (tport->ibmv_nexus) {
pr_debug("tport->ibmv_nexus already exists\n");
return 0;
}
nexus = kzalloc(sizeof(*nexus), GFP_KERNEL);
if (!nexus) {
pr_err("Unable to allocate struct ibmvscsis_nexus\n");
return -ENOMEM;
}
nexus->se_sess = target_alloc_session(&tport->se_tpg, 0, 0,
TARGET_PROT_NORMAL, name, nexus,
NULL);
if (IS_ERR(nexus->se_sess)) {
rc = PTR_ERR(nexus->se_sess);
goto transport_init_fail;
}
tport->ibmv_nexus = nexus;
return 0;
transport_init_fail:
kfree(nexus);
return rc;
}
static int ibmvscsis_drop_nexus(struct ibmvscsis_tport *tport)
{
struct se_session *se_sess;
struct ibmvscsis_nexus *nexus;
nexus = tport->ibmv_nexus;
if (!nexus)
return -ENODEV;
se_sess = nexus->se_sess;
if (!se_sess)
return -ENODEV;
target_wait_for_sess_cmds(se_sess);
transport_deregister_session_configfs(se_sess);
transport_deregister_session(se_sess);
tport->ibmv_nexus = NULL;
kfree(nexus);
return 0;
}
static long ibmvscsis_srp_login(struct scsi_info *vscsi,
struct ibmvscsis_cmd *cmd,
struct viosrp_crq *crq)
{
struct iu_entry *iue = cmd->iue;
struct srp_login_req *req = &vio_iu(iue)->srp.login_req;
struct port_id {
__be64 id_extension;
__be64 io_guid;
} *iport, *tport;
struct format_code *fmt;
u32 reason = 0x0;
long rc = ADAPT_SUCCESS;
iport = (struct port_id *)req->initiator_port_id;
tport = (struct port_id *)req->target_port_id;
fmt = (struct format_code *)&req->req_buf_fmt;
if (be32_to_cpu(req->req_it_iu_len) > SRP_MAX_IU_LEN)
reason = SRP_LOGIN_REJ_REQ_IT_IU_LENGTH_TOO_LARGE;
else if (be32_to_cpu(req->req_it_iu_len) < 64)
reason = SRP_LOGIN_REJ_UNABLE_ESTABLISH_CHANNEL;
else if ((be64_to_cpu(iport->id_extension) > (MAX_NUM_PORTS - 1)) ||
(be64_to_cpu(tport->id_extension) > (MAX_NUM_PORTS - 1)))
reason = SRP_LOGIN_REJ_UNABLE_ASSOCIATE_CHANNEL;
else if (req->req_flags & SRP_MULTICHAN_MULTI)
reason = SRP_LOGIN_REJ_MULTI_CHANNEL_UNSUPPORTED;
else if (fmt->buffers & (~SUPPORTED_FORMATS))
reason = SRP_LOGIN_REJ_UNSUPPORTED_DESCRIPTOR_FMT;
else if ((fmt->buffers & SUPPORTED_FORMATS) == 0)
reason = SRP_LOGIN_REJ_UNSUPPORTED_DESCRIPTOR_FMT;
if (vscsi->state == SRP_PROCESSING)
reason = SRP_LOGIN_REJ_CHANNEL_LIMIT_REACHED;
rc = ibmvscsis_make_nexus(&vscsi->tport);
if (rc)
reason = SRP_LOGIN_REJ_UNABLE_ESTABLISH_CHANNEL;
cmd->rsp.format = VIOSRP_SRP_FORMAT;
cmd->rsp.tag = req->tag;
pr_debug("srp_login: reason 0x%x\n", reason);
if (reason)
rc = ibmvscsis_srp_login_rej(vscsi, cmd, reason);
else
rc = ibmvscsis_login_rsp(vscsi, cmd);
if (!rc) {
if (!reason)
vscsi->state = SRP_PROCESSING;
list_add_tail(&cmd->list, &vscsi->waiting_rsp);
ibmvscsis_send_messages(vscsi);
} else {
ibmvscsis_free_cmd_resources(vscsi, cmd);
}
pr_debug("Leaving srp_login, rc %ld\n", rc);
return rc;
}
static long ibmvscsis_srp_i_logout(struct scsi_info *vscsi,
struct ibmvscsis_cmd *cmd,
struct viosrp_crq *crq)
{
struct iu_entry *iue = cmd->iue;
struct srp_i_logout *log_out = &vio_iu(iue)->srp.i_logout;
long rc = ADAPT_SUCCESS;
if ((vscsi->debit > 0) || !list_empty(&vscsi->schedule_q) ||
!list_empty(&vscsi->waiting_rsp)) {
dev_err(&vscsi->dev, "i_logout: outstanding work\n");
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT, 0);
} else {
cmd->rsp.format = SRP_FORMAT;
cmd->rsp.tag = log_out->tag;
cmd->rsp.len = sizeof(struct mad_common);
list_add_tail(&cmd->list, &vscsi->waiting_rsp);
ibmvscsis_send_messages(vscsi);
ibmvscsis_post_disconnect(vscsi, WAIT_IDLE, 0);
}
return rc;
}
static void ibmvscsis_srp_cmd(struct scsi_info *vscsi, struct viosrp_crq *crq)
{
struct ibmvscsis_cmd *cmd;
struct iu_entry *iue;
struct srp_cmd *srp;
struct srp_tsk_mgmt *tsk;
long rc;
if (vscsi->request_limit - vscsi->debit <= 0) {
dev_err(&vscsi->dev, "Client exceeded the request limit (%d), debit %d\n",
vscsi->request_limit, vscsi->debit);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
return;
}
cmd = ibmvscsis_get_free_cmd(vscsi);
if (!cmd) {
dev_err(&vscsi->dev, "srp_cmd failed to get cmd, debit %d\n",
vscsi->debit);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
return;
}
iue = cmd->iue;
srp = &vio_iu(iue)->srp.cmd;
rc = ibmvscsis_copy_crq_packet(vscsi, cmd, crq);
if (rc) {
ibmvscsis_free_cmd_resources(vscsi, cmd);
return;
}
if (vscsi->state == SRP_PROCESSING) {
switch (srp->opcode) {
case SRP_LOGIN_REQ:
rc = ibmvscsis_srp_login(vscsi, cmd, crq);
break;
case SRP_TSK_MGMT:
tsk = &vio_iu(iue)->srp.tsk_mgmt;
pr_debug("tsk_mgmt tag: %llu (0x%llx)\n", tsk->tag,
tsk->tag);
cmd->rsp.tag = tsk->tag;
vscsi->debit += 1;
cmd->type = TASK_MANAGEMENT;
list_add_tail(&cmd->list, &vscsi->schedule_q);
queue_work(vscsi->work_q, &cmd->work);
break;
case SRP_CMD:
pr_debug("srp_cmd tag: %llu (0x%llx)\n", srp->tag,
srp->tag);
cmd->rsp.tag = srp->tag;
vscsi->debit += 1;
cmd->type = SCSI_CDB;
list_add_tail(&cmd->list, &vscsi->schedule_q);
queue_work(vscsi->work_q, &cmd->work);
break;
case SRP_I_LOGOUT:
rc = ibmvscsis_srp_i_logout(vscsi, cmd, crq);
break;
case SRP_CRED_RSP:
case SRP_AER_RSP:
default:
ibmvscsis_free_cmd_resources(vscsi, cmd);
dev_err(&vscsi->dev, "invalid srp cmd, opcode %d\n",
(uint)srp->opcode);
ibmvscsis_post_disconnect(vscsi,
ERR_DISCONNECT_RECONNECT, 0);
break;
}
} else if (srp->opcode == SRP_LOGIN_REQ && vscsi->state == CONNECTED) {
rc = ibmvscsis_srp_login(vscsi, cmd, crq);
} else {
ibmvscsis_free_cmd_resources(vscsi, cmd);
dev_err(&vscsi->dev, "Invalid state %d to handle srp cmd\n",
vscsi->state);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
}
}
static long ibmvscsis_ping_response(struct scsi_info *vscsi)
{
struct viosrp_crq *crq;
u64 buffer[2] = { 0, 0 };
long rc;
crq = (struct viosrp_crq *)&buffer;
crq->valid = VALID_CMD_RESP_EL;
crq->format = (u8)MESSAGE_IN_CRQ;
crq->status = PING_RESPONSE;
rc = h_send_crq(vscsi->dds.unit_id, cpu_to_be64(buffer[MSG_HI]),
cpu_to_be64(buffer[MSG_LOW]));
switch (rc) {
case H_SUCCESS:
break;
case H_CLOSED:
vscsi->flags |= CLIENT_FAILED;
case H_DROPPED:
vscsi->flags |= RESPONSE_Q_DOWN;
case H_REMOTE_PARM:
dev_err(&vscsi->dev, "ping_response: h_send_crq failed, rc %ld\n",
rc);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
break;
default:
dev_err(&vscsi->dev, "ping_response: h_send_crq returned unknown rc %ld\n",
rc);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT, 0);
break;
}
return rc;
}
static long ibmvscsis_parse_command(struct scsi_info *vscsi,
struct viosrp_crq *crq)
{
long rc = ADAPT_SUCCESS;
switch (crq->valid) {
case VALID_CMD_RESP_EL:
switch (crq->format) {
case OS400_FORMAT:
case AIX_FORMAT:
case LINUX_FORMAT:
case MAD_FORMAT:
if (vscsi->flags & PROCESSING_MAD) {
rc = ERROR;
dev_err(&vscsi->dev, "parse_command: already processing mad\n");
ibmvscsis_post_disconnect(vscsi,
ERR_DISCONNECT_RECONNECT,
0);
} else {
vscsi->flags |= PROCESSING_MAD;
rc = ibmvscsis_mad(vscsi, crq);
}
break;
case SRP_FORMAT:
ibmvscsis_srp_cmd(vscsi, crq);
break;
case MESSAGE_IN_CRQ:
if (crq->status == PING)
ibmvscsis_ping_response(vscsi);
break;
default:
dev_err(&vscsi->dev, "parse_command: invalid format %d\n",
(uint)crq->format);
ibmvscsis_post_disconnect(vscsi,
ERR_DISCONNECT_RECONNECT, 0);
break;
}
break;
case VALID_TRANS_EVENT:
rc = ibmvscsis_trans_event(vscsi, crq);
break;
case VALID_INIT_MSG:
rc = ibmvscsis_init_msg(vscsi, crq);
break;
default:
dev_err(&vscsi->dev, "parse_command: invalid valid field %d\n",
(uint)crq->valid);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
break;
}
rc = vscsi->flags & SCHEDULE_DISCONNECT;
return rc;
}
static int read_dma_window(struct scsi_info *vscsi)
{
struct vio_dev *vdev = vscsi->dma_dev;
const __be32 *dma_window;
const __be32 *prop;
dma_window = (const __be32 *)vio_get_attribute(vdev,
"ibm,my-dma-window",
NULL);
if (!dma_window) {
pr_err("Couldn't find ibm,my-dma-window property\n");
return -1;
}
vscsi->dds.window[LOCAL].liobn = be32_to_cpu(*dma_window);
dma_window++;
prop = (const __be32 *)vio_get_attribute(vdev, "ibm,#dma-address-cells",
NULL);
if (!prop) {
pr_warn("Couldn't find ibm,#dma-address-cells property\n");
dma_window++;
} else {
dma_window += be32_to_cpu(*prop);
}
prop = (const __be32 *)vio_get_attribute(vdev, "ibm,#dma-size-cells",
NULL);
if (!prop) {
pr_warn("Couldn't find ibm,#dma-size-cells property\n");
dma_window++;
} else {
dma_window += be32_to_cpu(*prop);
}
vscsi->dds.window[REMOTE].liobn = be32_to_cpu(*dma_window);
return 0;
}
static struct ibmvscsis_tport *ibmvscsis_lookup_port(const char *name)
{
struct ibmvscsis_tport *tport = NULL;
struct vio_dev *vdev;
struct scsi_info *vscsi;
spin_lock_bh(&ibmvscsis_dev_lock);
list_for_each_entry(vscsi, &ibmvscsis_dev_list, list) {
vdev = vscsi->dma_dev;
if (!strcmp(dev_name(&vdev->dev), name)) {
tport = &vscsi->tport;
break;
}
}
spin_unlock_bh(&ibmvscsis_dev_lock);
return tport;
}
static void ibmvscsis_parse_cmd(struct scsi_info *vscsi,
struct ibmvscsis_cmd *cmd)
{
struct iu_entry *iue = cmd->iue;
struct srp_cmd *srp = (struct srp_cmd *)iue->sbuf->buf;
struct ibmvscsis_nexus *nexus;
u64 data_len = 0;
enum dma_data_direction dir;
int attr = 0;
int rc = 0;
nexus = vscsi->tport.ibmv_nexus;
if (srp->add_cdb_len & 0x03) {
dev_err(&vscsi->dev, "parse_cmd: reserved bits set in IU\n");
spin_lock_bh(&vscsi->intr_lock);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
ibmvscsis_free_cmd_resources(vscsi, cmd);
spin_unlock_bh(&vscsi->intr_lock);
return;
}
if (srp_get_desc_table(srp, &dir, &data_len)) {
dev_err(&vscsi->dev, "0x%llx: parsing SRP descriptor table failed.\n",
srp->tag);
goto fail;
}
cmd->rsp.sol_not = srp->sol_not;
switch (srp->task_attr) {
case SRP_SIMPLE_TASK:
attr = TCM_SIMPLE_TAG;
break;
case SRP_ORDERED_TASK:
attr = TCM_ORDERED_TAG;
break;
case SRP_HEAD_TASK:
attr = TCM_HEAD_TAG;
break;
case SRP_ACA_TASK:
attr = TCM_ACA_TAG;
break;
default:
dev_err(&vscsi->dev, "Invalid task attribute %d\n",
srp->task_attr);
goto fail;
}
cmd->se_cmd.tag = be64_to_cpu(srp->tag);
spin_lock_bh(&vscsi->intr_lock);
list_add_tail(&cmd->list, &vscsi->active_q);
spin_unlock_bh(&vscsi->intr_lock);
srp->lun.scsi_lun[0] &= 0x3f;
rc = target_submit_cmd(&cmd->se_cmd, nexus->se_sess, srp->cdb,
cmd->sense_buf, scsilun_to_int(&srp->lun),
data_len, attr, dir, 0);
if (rc) {
dev_err(&vscsi->dev, "target_submit_cmd failed, rc %d\n", rc);
spin_lock_bh(&vscsi->intr_lock);
list_del(&cmd->list);
ibmvscsis_free_cmd_resources(vscsi, cmd);
spin_unlock_bh(&vscsi->intr_lock);
goto fail;
}
return;
fail:
spin_lock_bh(&vscsi->intr_lock);
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT_RECONNECT, 0);
spin_unlock_bh(&vscsi->intr_lock);
}
static void ibmvscsis_parse_task(struct scsi_info *vscsi,
struct ibmvscsis_cmd *cmd)
{
struct iu_entry *iue = cmd->iue;
struct srp_tsk_mgmt *srp_tsk = &vio_iu(iue)->srp.tsk_mgmt;
int tcm_type;
u64 tag_to_abort = 0;
int rc = 0;
struct ibmvscsis_nexus *nexus;
nexus = vscsi->tport.ibmv_nexus;
cmd->rsp.sol_not = srp_tsk->sol_not;
switch (srp_tsk->tsk_mgmt_func) {
case SRP_TSK_ABORT_TASK:
tcm_type = TMR_ABORT_TASK;
tag_to_abort = be64_to_cpu(srp_tsk->task_tag);
break;
case SRP_TSK_ABORT_TASK_SET:
tcm_type = TMR_ABORT_TASK_SET;
break;
case SRP_TSK_CLEAR_TASK_SET:
tcm_type = TMR_CLEAR_TASK_SET;
break;
case SRP_TSK_LUN_RESET:
tcm_type = TMR_LUN_RESET;
break;
case SRP_TSK_CLEAR_ACA:
tcm_type = TMR_CLEAR_ACA;
break;
default:
dev_err(&vscsi->dev, "unknown task mgmt func %d\n",
srp_tsk->tsk_mgmt_func);
cmd->se_cmd.se_tmr_req->response =
TMR_TASK_MGMT_FUNCTION_NOT_SUPPORTED;
rc = -1;
break;
}
if (!rc) {
cmd->se_cmd.tag = be64_to_cpu(srp_tsk->tag);
spin_lock_bh(&vscsi->intr_lock);
list_add_tail(&cmd->list, &vscsi->active_q);
spin_unlock_bh(&vscsi->intr_lock);
srp_tsk->lun.scsi_lun[0] &= 0x3f;
pr_debug("calling submit_tmr, func %d\n",
srp_tsk->tsk_mgmt_func);
rc = target_submit_tmr(&cmd->se_cmd, nexus->se_sess, NULL,
scsilun_to_int(&srp_tsk->lun), srp_tsk,
tcm_type, GFP_KERNEL, tag_to_abort, 0);
if (rc) {
dev_err(&vscsi->dev, "target_submit_tmr failed, rc %d\n",
rc);
spin_lock_bh(&vscsi->intr_lock);
list_del(&cmd->list);
spin_unlock_bh(&vscsi->intr_lock);
cmd->se_cmd.se_tmr_req->response =
TMR_FUNCTION_REJECTED;
}
}
if (rc)
transport_send_check_condition_and_sense(&cmd->se_cmd, 0, 0);
}
static void ibmvscsis_scheduler(struct work_struct *work)
{
struct ibmvscsis_cmd *cmd = container_of(work, struct ibmvscsis_cmd,
work);
struct scsi_info *vscsi = cmd->adapter;
spin_lock_bh(&vscsi->intr_lock);
list_del(&cmd->list);
if (vscsi->flags & (SCHEDULE_DISCONNECT | DISCONNECT_SCHEDULED)) {
ibmvscsis_free_cmd_resources(vscsi, cmd);
if (list_empty(&vscsi->active_q) &&
list_empty(&vscsi->schedule_q) &&
(vscsi->flags & WAIT_FOR_IDLE)) {
vscsi->flags &= ~WAIT_FOR_IDLE;
complete(&vscsi->wait_idle);
}
spin_unlock_bh(&vscsi->intr_lock);
return;
}
spin_unlock_bh(&vscsi->intr_lock);
switch (cmd->type) {
case SCSI_CDB:
ibmvscsis_parse_cmd(vscsi, cmd);
break;
case TASK_MANAGEMENT:
ibmvscsis_parse_task(vscsi, cmd);
break;
default:
dev_err(&vscsi->dev, "scheduler, invalid cmd type %d\n",
cmd->type);
spin_lock_bh(&vscsi->intr_lock);
ibmvscsis_free_cmd_resources(vscsi, cmd);
spin_unlock_bh(&vscsi->intr_lock);
break;
}
}
static int ibmvscsis_alloc_cmds(struct scsi_info *vscsi, int num)
{
struct ibmvscsis_cmd *cmd;
int i;
INIT_LIST_HEAD(&vscsi->free_cmd);
vscsi->cmd_pool = kcalloc(num, sizeof(struct ibmvscsis_cmd),
GFP_KERNEL);
if (!vscsi->cmd_pool)
return -ENOMEM;
for (i = 0, cmd = (struct ibmvscsis_cmd *)vscsi->cmd_pool; i < num;
i++, cmd++) {
cmd->abort_cmd = NULL;
cmd->adapter = vscsi;
INIT_WORK(&cmd->work, ibmvscsis_scheduler);
list_add_tail(&cmd->list, &vscsi->free_cmd);
}
return 0;
}
static void ibmvscsis_free_cmds(struct scsi_info *vscsi)
{
kfree(vscsi->cmd_pool);
vscsi->cmd_pool = NULL;
INIT_LIST_HEAD(&vscsi->free_cmd);
}
static enum hrtimer_restart ibmvscsis_service_wait_q(struct hrtimer *timer)
{
struct timer_cb *p_timer = container_of(timer, struct timer_cb, timer);
struct scsi_info *vscsi = container_of(p_timer, struct scsi_info,
rsp_q_timer);
spin_lock_bh(&vscsi->intr_lock);
p_timer->timer_pops += 1;
p_timer->started = false;
ibmvscsis_send_messages(vscsi);
spin_unlock_bh(&vscsi->intr_lock);
return HRTIMER_NORESTART;
}
static long ibmvscsis_alloctimer(struct scsi_info *vscsi)
{
struct timer_cb *p_timer;
p_timer = &vscsi->rsp_q_timer;
hrtimer_init(&p_timer->timer, CLOCK_MONOTONIC, HRTIMER_MODE_REL);
p_timer->timer.function = ibmvscsis_service_wait_q;
p_timer->started = false;
p_timer->timer_pops = 0;
return ADAPT_SUCCESS;
}
static void ibmvscsis_freetimer(struct scsi_info *vscsi)
{
struct timer_cb *p_timer;
p_timer = &vscsi->rsp_q_timer;
(void)hrtimer_cancel(&p_timer->timer);
p_timer->started = false;
p_timer->timer_pops = 0;
}
static irqreturn_t ibmvscsis_interrupt(int dummy, void *data)
{
struct scsi_info *vscsi = data;
vio_disable_interrupts(vscsi->dma_dev);
tasklet_schedule(&vscsi->work_task);
return IRQ_HANDLED;
}
static long ibmvscsis_enable_change_state(struct scsi_info *vscsi)
{
int bytes;
long rc = ADAPT_SUCCESS;
bytes = vscsi->cmd_q.size * PAGE_SIZE;
rc = h_reg_crq(vscsi->dds.unit_id, vscsi->cmd_q.crq_token, bytes);
if (rc == H_CLOSED || rc == H_SUCCESS) {
vscsi->state = WAIT_CONNECTION;
rc = ibmvscsis_establish_new_q(vscsi);
}
if (rc != ADAPT_SUCCESS) {
vscsi->state = ERR_DISCONNECTED;
vscsi->flags |= RESPONSE_Q_DOWN;
}
return rc;
}
static long ibmvscsis_create_command_q(struct scsi_info *vscsi, int num_cmds)
{
int pages;
struct vio_dev *vdev = vscsi->dma_dev;
pages = 1;
vscsi->cmd_q.size = pages;
vscsi->cmd_q.base_addr =
(struct viosrp_crq *)get_zeroed_page(GFP_KERNEL);
if (!vscsi->cmd_q.base_addr)
return -ENOMEM;
vscsi->cmd_q.mask = ((uint)pages * CRQ_PER_PAGE) - 1;
vscsi->cmd_q.crq_token = dma_map_single(&vdev->dev,
vscsi->cmd_q.base_addr,
PAGE_SIZE, DMA_BIDIRECTIONAL);
if (dma_mapping_error(&vdev->dev, vscsi->cmd_q.crq_token)) {
free_page((unsigned long)vscsi->cmd_q.base_addr);
return -ENOMEM;
}
return 0;
}
static void ibmvscsis_destroy_command_q(struct scsi_info *vscsi)
{
dma_unmap_single(&vscsi->dma_dev->dev, vscsi->cmd_q.crq_token,
PAGE_SIZE, DMA_BIDIRECTIONAL);
free_page((unsigned long)vscsi->cmd_q.base_addr);
vscsi->cmd_q.base_addr = NULL;
vscsi->state = NO_QUEUE;
}
static u8 ibmvscsis_fast_fail(struct scsi_info *vscsi,
struct ibmvscsis_cmd *cmd)
{
struct iu_entry *iue = cmd->iue;
struct se_cmd *se_cmd = &cmd->se_cmd;
struct srp_cmd *srp = (struct srp_cmd *)iue->sbuf->buf;
struct scsi_sense_hdr sshdr;
u8 rc = se_cmd->scsi_status;
if (vscsi->fast_fail && (READ_CMD(srp->cdb) || WRITE_CMD(srp->cdb)))
if (scsi_normalize_sense(se_cmd->sense_buffer,
se_cmd->scsi_sense_length, &sshdr))
if (sshdr.sense_key == HARDWARE_ERROR &&
(se_cmd->residual_count == 0 ||
se_cmd->residual_count == se_cmd->data_length)) {
rc = NO_SENSE;
cmd->flags |= CMD_FAST_FAIL;
}
return rc;
}
static long srp_build_response(struct scsi_info *vscsi,
struct ibmvscsis_cmd *cmd, uint *len_p)
{
struct iu_entry *iue = cmd->iue;
struct se_cmd *se_cmd = &cmd->se_cmd;
struct srp_rsp *rsp;
uint len;
u32 rsp_code;
char *data;
u32 *tsk_status;
long rc = ADAPT_SUCCESS;
spin_lock_bh(&vscsi->intr_lock);
rsp = &vio_iu(iue)->srp.rsp;
len = sizeof(*rsp);
memset(rsp, 0, len);
data = rsp->data;
rsp->opcode = SRP_RSP;
rsp->req_lim_delta = cpu_to_be32(1 + vscsi->credit);
rsp->tag = cmd->rsp.tag;
rsp->flags = 0;
if (cmd->type == SCSI_CDB) {
rsp->status = ibmvscsis_fast_fail(vscsi, cmd);
if (rsp->status) {
pr_debug("build_resp: cmd %p, scsi status %d\n", cmd,
(int)rsp->status);
ibmvscsis_determine_resid(se_cmd, rsp);
if (se_cmd->scsi_sense_length && se_cmd->sense_buffer) {
rsp->sense_data_len =
cpu_to_be32(se_cmd->scsi_sense_length);
rsp->flags |= SRP_RSP_FLAG_SNSVALID;
len += se_cmd->scsi_sense_length;
memcpy(data, se_cmd->sense_buffer,
se_cmd->scsi_sense_length);
}
rsp->sol_not = (cmd->rsp.sol_not & UCSOLNT) >>
UCSOLNT_RESP_SHIFT;
} else if (cmd->flags & CMD_FAST_FAIL) {
pr_debug("build_resp: cmd %p, fast fail\n", cmd);
rsp->sol_not = (cmd->rsp.sol_not & UCSOLNT) >>
UCSOLNT_RESP_SHIFT;
} else {
rsp->sol_not = (cmd->rsp.sol_not & SCSOLNT) >>
SCSOLNT_RESP_SHIFT;
}
} else {
rsp->status = 0;
rsp->resp_data_len = cpu_to_be32(4);
rsp->flags |= SRP_RSP_FLAG_RSPVALID;
switch (se_cmd->se_tmr_req->response) {
case TMR_FUNCTION_COMPLETE:
case TMR_TASK_DOES_NOT_EXIST:
rsp_code = SRP_TASK_MANAGEMENT_FUNCTION_COMPLETE;
rsp->sol_not = (cmd->rsp.sol_not & SCSOLNT) >>
SCSOLNT_RESP_SHIFT;
break;
case TMR_TASK_MGMT_FUNCTION_NOT_SUPPORTED:
case TMR_LUN_DOES_NOT_EXIST:
rsp_code = SRP_TASK_MANAGEMENT_FUNCTION_NOT_SUPPORTED;
rsp->sol_not = (cmd->rsp.sol_not & UCSOLNT) >>
UCSOLNT_RESP_SHIFT;
break;
case TMR_FUNCTION_FAILED:
case TMR_FUNCTION_REJECTED:
default:
rsp_code = SRP_TASK_MANAGEMENT_FUNCTION_FAILED;
rsp->sol_not = (cmd->rsp.sol_not & UCSOLNT) >>
UCSOLNT_RESP_SHIFT;
break;
}
tsk_status = (u32 *)data;
*tsk_status = cpu_to_be32(rsp_code);
data = (char *)(tsk_status + 1);
len += 4;
}
dma_wmb();
rc = h_copy_rdma(len, vscsi->dds.window[LOCAL].liobn, iue->sbuf->dma,
vscsi->dds.window[REMOTE].liobn,
be64_to_cpu(iue->remote_token));
switch (rc) {
case H_SUCCESS:
vscsi->credit = 0;
*len_p = len;
break;
case H_PERMISSION:
if (connection_broken(vscsi))
vscsi->flags |= RESPONSE_Q_DOWN | CLIENT_FAILED;
dev_err(&vscsi->dev, "build_response: error copying to client, rc %ld, flags 0x%x, state 0x%hx\n",
rc, vscsi->flags, vscsi->state);
break;
case H_SOURCE_PARM:
case H_DEST_PARM:
default:
dev_err(&vscsi->dev, "build_response: error copying to client, rc %ld\n",
rc);
break;
}
spin_unlock_bh(&vscsi->intr_lock);
return rc;
}
static int ibmvscsis_rdma(struct ibmvscsis_cmd *cmd, struct scatterlist *sg,
int nsg, struct srp_direct_buf *md, int nmd,
enum dma_data_direction dir, unsigned int bytes)
{
struct iu_entry *iue = cmd->iue;
struct srp_target *target = iue->target;
struct scsi_info *vscsi = target->ldata;
struct scatterlist *sgp;
dma_addr_t client_ioba, server_ioba;
ulong buf_len;
ulong client_len, server_len;
int md_idx;
long tx_len;
long rc = 0;
if (bytes == 0)
return 0;
sgp = sg;
client_len = 0;
server_len = 0;
md_idx = 0;
tx_len = bytes;
do {
if (client_len == 0) {
if (md_idx >= nmd) {
dev_err(&vscsi->dev, "rdma: ran out of client memory descriptors\n");
rc = -EIO;
break;
}
client_ioba = be64_to_cpu(md[md_idx].va);
client_len = be32_to_cpu(md[md_idx].len);
}
if (server_len == 0) {
if (!sgp) {
dev_err(&vscsi->dev, "rdma: ran out of scatter/gather list\n");
rc = -EIO;
break;
}
server_ioba = sg_dma_address(sgp);
server_len = sg_dma_len(sgp);
}
buf_len = tx_len;
if (buf_len > client_len)
buf_len = client_len;
if (buf_len > server_len)
buf_len = server_len;
if (buf_len > max_vdma_size)
buf_len = max_vdma_size;
if (dir == DMA_TO_DEVICE) {
rc = h_copy_rdma(buf_len,
vscsi->dds.window[REMOTE].liobn,
client_ioba,
vscsi->dds.window[LOCAL].liobn,
server_ioba);
} else {
isync();
dma_wmb();
rc = h_copy_rdma(buf_len,
vscsi->dds.window[LOCAL].liobn,
server_ioba,
vscsi->dds.window[REMOTE].liobn,
client_ioba);
}
switch (rc) {
case H_SUCCESS:
break;
case H_PERMISSION:
case H_SOURCE_PARM:
case H_DEST_PARM:
if (connection_broken(vscsi)) {
spin_lock_bh(&vscsi->intr_lock);
vscsi->flags |=
(RESPONSE_Q_DOWN | CLIENT_FAILED);
spin_unlock_bh(&vscsi->intr_lock);
}
dev_err(&vscsi->dev, "rdma: h_copy_rdma failed, rc %ld\n",
rc);
break;
default:
dev_err(&vscsi->dev, "rdma: unknown error %ld from h_copy_rdma\n",
rc);
break;
}
if (!rc) {
tx_len -= buf_len;
if (tx_len) {
client_len -= buf_len;
if (client_len == 0)
md_idx++;
else
client_ioba += buf_len;
server_len -= buf_len;
if (server_len == 0)
sgp = sg_next(sgp);
else
server_ioba += buf_len;
} else {
break;
}
}
} while (!rc);
return rc;
}
static void ibmvscsis_handle_crq(unsigned long data)
{
struct scsi_info *vscsi = (struct scsi_info *)data;
struct viosrp_crq *crq;
long rc;
bool ack = true;
volatile u8 valid;
spin_lock_bh(&vscsi->intr_lock);
pr_debug("got interrupt\n");
if (TARGET_STOP(vscsi)) {
vio_enable_interrupts(vscsi->dma_dev);
pr_debug("handle_crq, don't process: flags 0x%x, state 0x%hx\n",
vscsi->flags, vscsi->state);
spin_unlock_bh(&vscsi->intr_lock);
return;
}
rc = vscsi->flags & SCHEDULE_DISCONNECT;
crq = vscsi->cmd_q.base_addr + vscsi->cmd_q.index;
valid = crq->valid;
dma_rmb();
while (valid) {
cmd_work:
vscsi->cmd_q.index =
(vscsi->cmd_q.index + 1) & vscsi->cmd_q.mask;
if (!rc) {
rc = ibmvscsis_parse_command(vscsi, crq);
} else {
if ((uint)crq->valid == VALID_TRANS_EVENT) {
rc = ibmvscsis_trans_event(vscsi, crq);
} else if (vscsi->flags & TRANS_EVENT) {
if (vscsi->cmd_q.index)
vscsi->cmd_q.index -= 1;
else
vscsi->cmd_q.index = vscsi->cmd_q.mask;
break;
}
}
crq->valid = INVALIDATE_CMD_RESP_EL;
crq = vscsi->cmd_q.base_addr + vscsi->cmd_q.index;
valid = crq->valid;
dma_rmb();
}
if (!rc) {
if (ack) {
vio_enable_interrupts(vscsi->dma_dev);
ack = false;
pr_debug("handle_crq, reenabling interrupts\n");
}
valid = crq->valid;
dma_rmb();
if (valid)
goto cmd_work;
} else {
pr_debug("handle_crq, error: flags 0x%x, state 0x%hx, crq index 0x%x\n",
vscsi->flags, vscsi->state, vscsi->cmd_q.index);
}
pr_debug("Leaving handle_crq: schedule_q empty %d, flags 0x%x, state 0x%hx\n",
(int)list_empty(&vscsi->schedule_q), vscsi->flags,
vscsi->state);
spin_unlock_bh(&vscsi->intr_lock);
}
static int ibmvscsis_probe(struct vio_dev *vdev,
const struct vio_device_id *id)
{
struct scsi_info *vscsi;
int rc = 0;
long hrc = 0;
char wq_name[24];
vscsi = kzalloc(sizeof(*vscsi), GFP_KERNEL);
if (!vscsi) {
rc = -ENOMEM;
pr_err("probe: allocation of adapter failed\n");
return rc;
}
vscsi->dma_dev = vdev;
vscsi->dev = vdev->dev;
INIT_LIST_HEAD(&vscsi->schedule_q);
INIT_LIST_HEAD(&vscsi->waiting_rsp);
INIT_LIST_HEAD(&vscsi->active_q);
snprintf(vscsi->tport.tport_name, IBMVSCSIS_NAMELEN, "%s",
dev_name(&vdev->dev));
pr_debug("probe tport_name: %s\n", vscsi->tport.tport_name);
rc = read_dma_window(vscsi);
if (rc)
goto free_adapter;
pr_debug("Probe: liobn 0x%x, riobn 0x%x\n",
vscsi->dds.window[LOCAL].liobn,
vscsi->dds.window[REMOTE].liobn);
strcpy(vscsi->eye, "VSCSI ");
strncat(vscsi->eye, vdev->name, MAX_EYE);
vscsi->dds.unit_id = vdev->unit_address;
strncpy(vscsi->dds.partition_name, partition_name,
sizeof(vscsi->dds.partition_name));
vscsi->dds.partition_num = partition_number;
spin_lock_bh(&ibmvscsis_dev_lock);
list_add_tail(&vscsi->list, &ibmvscsis_dev_list);
spin_unlock_bh(&ibmvscsis_dev_lock);
vscsi->request_limit = INITIAL_SRP_LIMIT;
rc = srp_target_alloc(&vscsi->target, &vdev->dev, vscsi->request_limit,
SRP_MAX_IU_LEN);
if (rc)
goto rem_list;
vscsi->target.ldata = vscsi;
rc = ibmvscsis_alloc_cmds(vscsi, vscsi->request_limit);
if (rc) {
dev_err(&vscsi->dev, "alloc_cmds failed, rc %d, num %d\n",
rc, vscsi->request_limit);
goto free_target;
}
spin_lock_init(&vscsi->intr_lock);
rc = ibmvscsis_alloctimer(vscsi);
if (rc) {
dev_err(&vscsi->dev, "probe: alloctimer failed, rc %d\n", rc);
goto free_cmds;
}
rc = ibmvscsis_create_command_q(vscsi, 256);
if (rc) {
dev_err(&vscsi->dev, "probe: create_command_q failed, rc %d\n",
rc);
goto free_timer;
}
vscsi->map_buf = kzalloc(PAGE_SIZE, GFP_KERNEL);
if (!vscsi->map_buf) {
rc = -ENOMEM;
dev_err(&vscsi->dev, "probe: allocating cmd buffer failed\n");
goto destroy_queue;
}
vscsi->map_ioba = dma_map_single(&vdev->dev, vscsi->map_buf, PAGE_SIZE,
DMA_BIDIRECTIONAL);
if (dma_mapping_error(&vdev->dev, vscsi->map_ioba)) {
rc = -ENOMEM;
dev_err(&vscsi->dev, "probe: error mapping command buffer\n");
goto free_buf;
}
hrc = h_vioctl(vscsi->dds.unit_id, H_GET_PARTNER_INFO,
(u64)vscsi->map_ioba | ((u64)PAGE_SIZE << 32), 0, 0, 0,
0);
if (hrc == H_SUCCESS)
vscsi->client_data.partition_number =
be64_to_cpu(*(u64 *)vscsi->map_buf);
pr_debug("probe hrc %ld, client partition num %d\n",
hrc, vscsi->client_data.partition_number);
tasklet_init(&vscsi->work_task, ibmvscsis_handle_crq,
(unsigned long)vscsi);
init_completion(&vscsi->wait_idle);
init_completion(&vscsi->unconfig);
snprintf(wq_name, 24, "ibmvscsis%s", dev_name(&vdev->dev));
vscsi->work_q = create_workqueue(wq_name);
if (!vscsi->work_q) {
rc = -ENOMEM;
dev_err(&vscsi->dev, "create_workqueue failed\n");
goto unmap_buf;
}
rc = request_irq(vdev->irq, ibmvscsis_interrupt, 0, "ibmvscsis", vscsi);
if (rc) {
rc = -EPERM;
dev_err(&vscsi->dev, "probe: request_irq failed, rc %d\n", rc);
goto destroy_WQ;
}
vscsi->state = WAIT_ENABLED;
dev_set_drvdata(&vdev->dev, vscsi);
return 0;
destroy_WQ:
destroy_workqueue(vscsi->work_q);
unmap_buf:
dma_unmap_single(&vdev->dev, vscsi->map_ioba, PAGE_SIZE,
DMA_BIDIRECTIONAL);
free_buf:
kfree(vscsi->map_buf);
destroy_queue:
tasklet_kill(&vscsi->work_task);
ibmvscsis_unregister_command_q(vscsi);
ibmvscsis_destroy_command_q(vscsi);
free_timer:
ibmvscsis_freetimer(vscsi);
free_cmds:
ibmvscsis_free_cmds(vscsi);
free_target:
srp_target_free(&vscsi->target);
rem_list:
spin_lock_bh(&ibmvscsis_dev_lock);
list_del(&vscsi->list);
spin_unlock_bh(&ibmvscsis_dev_lock);
free_adapter:
kfree(vscsi);
return rc;
}
static int ibmvscsis_remove(struct vio_dev *vdev)
{
struct scsi_info *vscsi = dev_get_drvdata(&vdev->dev);
pr_debug("remove (%s)\n", dev_name(&vscsi->dma_dev->dev));
spin_lock_bh(&vscsi->intr_lock);
ibmvscsis_post_disconnect(vscsi, UNCONFIGURING, 0);
vscsi->flags |= CFG_SLEEPING;
spin_unlock_bh(&vscsi->intr_lock);
wait_for_completion(&vscsi->unconfig);
vio_disable_interrupts(vdev);
free_irq(vdev->irq, vscsi);
destroy_workqueue(vscsi->work_q);
dma_unmap_single(&vdev->dev, vscsi->map_ioba, PAGE_SIZE,
DMA_BIDIRECTIONAL);
kfree(vscsi->map_buf);
tasklet_kill(&vscsi->work_task);
ibmvscsis_destroy_command_q(vscsi);
ibmvscsis_freetimer(vscsi);
ibmvscsis_free_cmds(vscsi);
srp_target_free(&vscsi->target);
spin_lock_bh(&ibmvscsis_dev_lock);
list_del(&vscsi->list);
spin_unlock_bh(&ibmvscsis_dev_lock);
kfree(vscsi);
return 0;
}
static ssize_t system_id_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%s\n", system_id);
}
static ssize_t partition_number_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
return snprintf(buf, PAGE_SIZE, "%x\n", partition_number);
}
static ssize_t unit_address_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct scsi_info *vscsi = container_of(dev, struct scsi_info, dev);
return snprintf(buf, PAGE_SIZE, "%x\n", vscsi->dma_dev->unit_address);
}
static int ibmvscsis_get_system_info(void)
{
struct device_node *rootdn, *vdevdn;
const char *id, *model, *name;
const uint *num;
rootdn = of_find_node_by_path("/");
if (!rootdn)
return -ENOENT;
model = of_get_property(rootdn, "model", NULL);
id = of_get_property(rootdn, "system-id", NULL);
if (model && id)
snprintf(system_id, sizeof(system_id), "%s-%s", model, id);
name = of_get_property(rootdn, "ibm,partition-name", NULL);
if (name)
strncpy(partition_name, name, sizeof(partition_name));
num = of_get_property(rootdn, "ibm,partition-no", NULL);
if (num)
partition_number = of_read_number(num, 1);
of_node_put(rootdn);
vdevdn = of_find_node_by_path("/vdevice");
if (vdevdn) {
const uint *mvds;
mvds = of_get_property(vdevdn, "ibm,max-virtual-dma-size",
NULL);
if (mvds)
max_vdma_size = *mvds;
of_node_put(vdevdn);
}
return 0;
}
static char *ibmvscsis_get_fabric_name(void)
{
return "ibmvscsis";
}
static char *ibmvscsis_get_fabric_wwn(struct se_portal_group *se_tpg)
{
struct ibmvscsis_tport *tport =
container_of(se_tpg, struct ibmvscsis_tport, se_tpg);
return tport->tport_name;
}
static u16 ibmvscsis_get_tag(struct se_portal_group *se_tpg)
{
struct ibmvscsis_tport *tport =
container_of(se_tpg, struct ibmvscsis_tport, se_tpg);
return tport->tport_tpgt;
}
static u32 ibmvscsis_get_default_depth(struct se_portal_group *se_tpg)
{
return 1;
}
static int ibmvscsis_check_true(struct se_portal_group *se_tpg)
{
return 1;
}
static int ibmvscsis_check_false(struct se_portal_group *se_tpg)
{
return 0;
}
static u32 ibmvscsis_tpg_get_inst_index(struct se_portal_group *se_tpg)
{
return 1;
}
static int ibmvscsis_check_stop_free(struct se_cmd *se_cmd)
{
return target_put_sess_cmd(se_cmd);
}
static void ibmvscsis_release_cmd(struct se_cmd *se_cmd)
{
struct ibmvscsis_cmd *cmd = container_of(se_cmd, struct ibmvscsis_cmd,
se_cmd);
struct scsi_info *vscsi = cmd->adapter;
spin_lock_bh(&vscsi->intr_lock);
list_move_tail(&cmd->list, &vscsi->waiting_rsp);
ibmvscsis_send_messages(vscsi);
spin_unlock_bh(&vscsi->intr_lock);
}
static u32 ibmvscsis_sess_get_index(struct se_session *se_sess)
{
return 0;
}
static int ibmvscsis_write_pending(struct se_cmd *se_cmd)
{
struct ibmvscsis_cmd *cmd = container_of(se_cmd, struct ibmvscsis_cmd,
se_cmd);
struct scsi_info *vscsi = cmd->adapter;
struct iu_entry *iue = cmd->iue;
int rc;
if ((vscsi->flags & (CLIENT_FAILED | RESPONSE_Q_DOWN))) {
pr_err("write_pending failed since: %d\n", vscsi->flags);
return -EIO;
}
rc = srp_transfer_data(cmd, &vio_iu(iue)->srp.cmd, ibmvscsis_rdma,
1, 1);
if (rc) {
pr_err("srp_transfer_data() failed: %d\n", rc);
return -EIO;
}
target_execute_cmd(se_cmd);
return 0;
}
static int ibmvscsis_write_pending_status(struct se_cmd *se_cmd)
{
return 0;
}
static void ibmvscsis_set_default_node_attrs(struct se_node_acl *nacl)
{
}
static int ibmvscsis_get_cmd_state(struct se_cmd *se_cmd)
{
return 0;
}
static int ibmvscsis_queue_data_in(struct se_cmd *se_cmd)
{
struct ibmvscsis_cmd *cmd = container_of(se_cmd, struct ibmvscsis_cmd,
se_cmd);
struct iu_entry *iue = cmd->iue;
struct scsi_info *vscsi = cmd->adapter;
char *sd;
uint len = 0;
int rc;
rc = srp_transfer_data(cmd, &vio_iu(iue)->srp.cmd, ibmvscsis_rdma, 1,
1);
if (rc) {
pr_err("srp_transfer_data failed: %d\n", rc);
sd = se_cmd->sense_buffer;
se_cmd->scsi_sense_length = 18;
memset(se_cmd->sense_buffer, 0, se_cmd->scsi_sense_length);
scsi_build_sense_buffer(0, se_cmd->sense_buffer, MEDIUM_ERROR,
0x08, 0x01);
}
srp_build_response(vscsi, cmd, &len);
cmd->rsp.format = SRP_FORMAT;
cmd->rsp.len = len;
return 0;
}
static int ibmvscsis_queue_status(struct se_cmd *se_cmd)
{
struct ibmvscsis_cmd *cmd = container_of(se_cmd, struct ibmvscsis_cmd,
se_cmd);
struct scsi_info *vscsi = cmd->adapter;
uint len;
pr_debug("queue_status %p\n", se_cmd);
srp_build_response(vscsi, cmd, &len);
cmd->rsp.format = SRP_FORMAT;
cmd->rsp.len = len;
return 0;
}
static void ibmvscsis_queue_tm_rsp(struct se_cmd *se_cmd)
{
struct ibmvscsis_cmd *cmd = container_of(se_cmd, struct ibmvscsis_cmd,
se_cmd);
struct scsi_info *vscsi = cmd->adapter;
struct ibmvscsis_cmd *cmd_itr;
struct iu_entry *iue = iue = cmd->iue;
struct srp_tsk_mgmt *srp_tsk = &vio_iu(iue)->srp.tsk_mgmt;
u64 tag_to_abort = be64_to_cpu(srp_tsk->task_tag);
uint len;
pr_debug("queue_tm_rsp %p, status %d\n",
se_cmd, (int)se_cmd->se_tmr_req->response);
if (srp_tsk->tsk_mgmt_func == SRP_TSK_ABORT_TASK &&
cmd->se_cmd.se_tmr_req->response == TMR_TASK_DOES_NOT_EXIST) {
spin_lock_bh(&vscsi->intr_lock);
list_for_each_entry(cmd_itr, &vscsi->active_q, list) {
if (tag_to_abort == cmd_itr->se_cmd.tag) {
cmd_itr->abort_cmd = cmd;
cmd->flags |= DELAY_SEND;
break;
}
}
spin_unlock_bh(&vscsi->intr_lock);
}
srp_build_response(vscsi, cmd, &len);
cmd->rsp.format = SRP_FORMAT;
cmd->rsp.len = len;
}
static void ibmvscsis_aborted_task(struct se_cmd *se_cmd)
{
pr_debug("ibmvscsis_aborted_task %p task_tag: %llu\n",
se_cmd, se_cmd->tag);
}
static struct se_wwn *ibmvscsis_make_tport(struct target_fabric_configfs *tf,
struct config_group *group,
const char *name)
{
struct ibmvscsis_tport *tport;
tport = ibmvscsis_lookup_port(name);
if (tport) {
tport->tport_proto_id = SCSI_PROTOCOL_SRP;
pr_debug("make_tport(%s), pointer:%p, tport_id:%x\n",
name, tport, tport->tport_proto_id);
return &tport->tport_wwn;
}
return ERR_PTR(-EINVAL);
}
static void ibmvscsis_drop_tport(struct se_wwn *wwn)
{
struct ibmvscsis_tport *tport = container_of(wwn,
struct ibmvscsis_tport,
tport_wwn);
pr_debug("drop_tport(%s)\n",
config_item_name(&tport->tport_wwn.wwn_group.cg_item));
}
static struct se_portal_group *ibmvscsis_make_tpg(struct se_wwn *wwn,
struct config_group *group,
const char *name)
{
struct ibmvscsis_tport *tport =
container_of(wwn, struct ibmvscsis_tport, tport_wwn);
u16 tpgt;
int rc;
if (strstr(name, "tpgt_") != name)
return ERR_PTR(-EINVAL);
rc = kstrtou16(name + 5, 0, &tpgt);
if (rc)
return ERR_PTR(rc);
tport->tport_tpgt = tpgt;
tport->releasing = false;
rc = core_tpg_register(&tport->tport_wwn, &tport->se_tpg,
tport->tport_proto_id);
if (rc)
return ERR_PTR(rc);
return &tport->se_tpg;
}
static void ibmvscsis_drop_tpg(struct se_portal_group *se_tpg)
{
struct ibmvscsis_tport *tport = container_of(se_tpg,
struct ibmvscsis_tport,
se_tpg);
tport->releasing = true;
tport->enabled = false;
ibmvscsis_drop_nexus(tport);
core_tpg_deregister(se_tpg);
}
static ssize_t ibmvscsis_wwn_version_show(struct config_item *item,
char *page)
{
return scnprintf(page, PAGE_SIZE, "%s\n", IBMVSCSIS_VERSION);
}
static ssize_t ibmvscsis_tpg_enable_show(struct config_item *item,
char *page)
{
struct se_portal_group *se_tpg = to_tpg(item);
struct ibmvscsis_tport *tport = container_of(se_tpg,
struct ibmvscsis_tport,
se_tpg);
return snprintf(page, PAGE_SIZE, "%d\n", (tport->enabled) ? 1 : 0);
}
static ssize_t ibmvscsis_tpg_enable_store(struct config_item *item,
const char *page, size_t count)
{
struct se_portal_group *se_tpg = to_tpg(item);
struct ibmvscsis_tport *tport = container_of(se_tpg,
struct ibmvscsis_tport,
se_tpg);
struct scsi_info *vscsi = container_of(tport, struct scsi_info, tport);
unsigned long tmp;
int rc;
long lrc;
rc = kstrtoul(page, 0, &tmp);
if (rc < 0) {
pr_err("Unable to extract srpt_tpg_store_enable\n");
return -EINVAL;
}
if ((tmp != 0) && (tmp != 1)) {
pr_err("Illegal value for srpt_tpg_store_enable\n");
return -EINVAL;
}
if (tmp) {
spin_lock_bh(&vscsi->intr_lock);
tport->enabled = true;
lrc = ibmvscsis_enable_change_state(vscsi);
if (lrc)
pr_err("enable_change_state failed, rc %ld state %d\n",
lrc, vscsi->state);
spin_unlock_bh(&vscsi->intr_lock);
} else {
spin_lock_bh(&vscsi->intr_lock);
tport->enabled = false;
ibmvscsis_post_disconnect(vscsi, ERR_DISCONNECT, 0);
spin_unlock_bh(&vscsi->intr_lock);
}
pr_debug("tpg_enable_store, tmp %ld, state %d\n", tmp, vscsi->state);
return count;
}
static void ibmvscsis_dev_release(struct device *dev) {}
static int __init ibmvscsis_init(void)
{
int rc = 0;
rc = ibmvscsis_get_system_info();
if (rc) {
pr_err("rc %d from get_system_info\n", rc);
goto out;
}
rc = class_register(&ibmvscsis_class);
if (rc) {
pr_err("failed class register\n");
goto out;
}
rc = target_register_template(&ibmvscsis_ops);
if (rc) {
pr_err("rc %d from target_register_template\n", rc);
goto unregister_class;
}
rc = vio_register_driver(&ibmvscsis_driver);
if (rc) {
pr_err("rc %d from vio_register_driver\n", rc);
goto unregister_target;
}
return 0;
unregister_target:
target_unregister_template(&ibmvscsis_ops);
unregister_class:
class_unregister(&ibmvscsis_class);
out:
return rc;
}
static void __exit ibmvscsis_exit(void)
{
pr_info("Unregister IBM virtual SCSI host driver\n");
vio_unregister_driver(&ibmvscsis_driver);
target_unregister_template(&ibmvscsis_ops);
class_unregister(&ibmvscsis_class);
}
