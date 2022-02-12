const char *dev_state_name(enum sci_remote_device_states state)
{
static const char * const strings[] = REMOTE_DEV_STATES;
return strings[state];
}
enum sci_status sci_remote_device_suspend(struct isci_remote_device *idev,
enum sci_remote_node_suspension_reasons reason)
{
return sci_remote_node_context_suspend(&idev->rnc, reason,
SCI_SOFTWARE_SUSPEND_EXPECTED_EVENT);
}
static void isci_remote_device_ready(struct isci_host *ihost, struct isci_remote_device *idev)
{
dev_dbg(&ihost->pdev->dev,
"%s: idev = %p\n", __func__, idev);
clear_bit(IDEV_IO_NCQERROR, &idev->flags);
set_bit(IDEV_IO_READY, &idev->flags);
if (test_and_clear_bit(IDEV_START_PENDING, &idev->flags))
wake_up(&ihost->eventq);
}
static enum sci_status sci_remote_device_terminate_req(
struct isci_host *ihost,
struct isci_remote_device *idev,
int check_abort,
struct isci_request *ireq)
{
if (!test_bit(IREQ_ACTIVE, &ireq->flags) ||
(ireq->target_device != idev) ||
(check_abort && !test_bit(IREQ_PENDING_ABORT, &ireq->flags)))
return SCI_SUCCESS;
dev_dbg(&ihost->pdev->dev,
"%s: idev=%p; flags=%lx; req=%p; req target=%p\n",
__func__, idev, idev->flags, ireq, ireq->target_device);
set_bit(IREQ_ABORT_PATH_ACTIVE, &ireq->flags);
return sci_controller_terminate_request(ihost, idev, ireq);
}
static enum sci_status sci_remote_device_terminate_reqs_checkabort(
struct isci_remote_device *idev,
int chk)
{
struct isci_host *ihost = idev->owning_port->owning_controller;
enum sci_status status = SCI_SUCCESS;
u32 i;
for (i = 0; i < SCI_MAX_IO_REQUESTS; i++) {
struct isci_request *ireq = ihost->reqs[i];
enum sci_status s;
s = sci_remote_device_terminate_req(ihost, idev, chk, ireq);
if (s != SCI_SUCCESS)
status = s;
}
return status;
}
static bool isci_compare_suspendcount(
struct isci_remote_device *idev,
u32 localcount)
{
smp_rmb();
return (localcount != idev->rnc.suspend_count)
|| sci_remote_node_context_is_being_destroyed(&idev->rnc);
}
static bool isci_check_reqterm(
struct isci_host *ihost,
struct isci_remote_device *idev,
struct isci_request *ireq,
u32 localcount)
{
unsigned long flags;
bool res;
spin_lock_irqsave(&ihost->scic_lock, flags);
res = isci_compare_suspendcount(idev, localcount)
&& !test_bit(IREQ_ABORT_PATH_ACTIVE, &ireq->flags);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
return res;
}
static bool isci_check_devempty(
struct isci_host *ihost,
struct isci_remote_device *idev,
u32 localcount)
{
unsigned long flags;
bool res;
spin_lock_irqsave(&ihost->scic_lock, flags);
res = isci_compare_suspendcount(idev, localcount)
&& idev->started_request_count == 0;
spin_unlock_irqrestore(&ihost->scic_lock, flags);
return res;
}
enum sci_status isci_remote_device_terminate_requests(
struct isci_host *ihost,
struct isci_remote_device *idev,
struct isci_request *ireq)
{
enum sci_status status = SCI_SUCCESS;
unsigned long flags;
u32 rnc_suspend_count;
spin_lock_irqsave(&ihost->scic_lock, flags);
if (isci_get_device(idev) == NULL) {
dev_dbg(&ihost->pdev->dev, "%s: failed isci_get_device(idev=%p)\n",
__func__, idev);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
status = SCI_FAILURE;
} else {
smp_rmb();
rnc_suspend_count
= sci_remote_node_context_is_suspended(&idev->rnc)
? 0 : idev->rnc.suspend_count;
dev_dbg(&ihost->pdev->dev,
"%s: idev=%p, ireq=%p; started_request_count=%d, "
"rnc_suspend_count=%d, rnc.suspend_count=%d"
"about to wait\n",
__func__, idev, ireq, idev->started_request_count,
rnc_suspend_count, idev->rnc.suspend_count);
#define MAX_SUSPEND_MSECS 10000
if (ireq) {
set_bit(IREQ_NO_AUTO_FREE_TAG, &ireq->flags);
sci_remote_device_terminate_req(ihost, idev, 0, ireq);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
if (!wait_event_timeout(ihost->eventq,
isci_check_reqterm(ihost, idev, ireq,
rnc_suspend_count),
msecs_to_jiffies(MAX_SUSPEND_MSECS))) {
dev_warn(&ihost->pdev->dev, "%s host%d timeout single\n",
__func__, ihost->id);
dev_dbg(&ihost->pdev->dev,
"%s: ******* Timeout waiting for "
"suspend; idev=%p, current state %s; "
"started_request_count=%d, flags=%lx\n\t"
"rnc_suspend_count=%d, rnc.suspend_count=%d "
"RNC: current state %s, current "
"suspend_type %x dest state %d;\n"
"ireq=%p, ireq->flags = %lx\n",
__func__, idev,
dev_state_name(idev->sm.current_state_id),
idev->started_request_count, idev->flags,
rnc_suspend_count, idev->rnc.suspend_count,
rnc_state_name(idev->rnc.sm.current_state_id),
idev->rnc.suspend_type,
idev->rnc.destination_state,
ireq, ireq->flags);
}
spin_lock_irqsave(&ihost->scic_lock, flags);
clear_bit(IREQ_NO_AUTO_FREE_TAG, &ireq->flags);
if (!test_bit(IREQ_ABORT_PATH_ACTIVE, &ireq->flags))
isci_free_tag(ihost, ireq->io_tag);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
} else {
sci_remote_device_terminate_requests(idev);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
if (!wait_event_timeout(ihost->eventq,
isci_check_devempty(ihost, idev,
rnc_suspend_count),
msecs_to_jiffies(MAX_SUSPEND_MSECS))) {
dev_warn(&ihost->pdev->dev, "%s host%d timeout all\n",
__func__, ihost->id);
dev_dbg(&ihost->pdev->dev,
"%s: ******* Timeout waiting for "
"suspend; idev=%p, current state %s; "
"started_request_count=%d, flags=%lx\n\t"
"rnc_suspend_count=%d, "
"RNC: current state %s, "
"rnc.suspend_count=%d, current "
"suspend_type %x dest state %d\n",
__func__, idev,
dev_state_name(idev->sm.current_state_id),
idev->started_request_count, idev->flags,
rnc_suspend_count,
rnc_state_name(idev->rnc.sm.current_state_id),
idev->rnc.suspend_count,
idev->rnc.suspend_type,
idev->rnc.destination_state);
}
}
dev_dbg(&ihost->pdev->dev, "%s: idev=%p, wait done\n",
__func__, idev);
isci_put_device(idev);
}
return status;
}
static void isci_remote_device_not_ready(struct isci_host *ihost,
struct isci_remote_device *idev,
u32 reason)
{
dev_dbg(&ihost->pdev->dev,
"%s: isci_device = %p; reason = %d\n", __func__, idev, reason);
switch (reason) {
case SCIC_REMOTE_DEVICE_NOT_READY_SATA_SDB_ERROR_FIS_RECEIVED:
set_bit(IDEV_IO_NCQERROR, &idev->flags);
sci_remote_device_suspend(idev, SCI_SW_SUSPEND_NORMAL);
sci_remote_device_terminate_requests(idev);
default:
clear_bit(IDEV_IO_READY, &idev->flags);
break;
}
}
static void rnc_destruct_done(void *_dev)
{
struct isci_remote_device *idev = _dev;
BUG_ON(idev->started_request_count != 0);
sci_change_state(&idev->sm, SCI_DEV_STOPPED);
}
enum sci_status sci_remote_device_terminate_requests(
struct isci_remote_device *idev)
{
return sci_remote_device_terminate_reqs_checkabort(idev, 0);
}
enum sci_status sci_remote_device_stop(struct isci_remote_device *idev,
u32 timeout)
{
struct sci_base_state_machine *sm = &idev->sm;
enum sci_remote_device_states state = sm->current_state_id;
switch (state) {
case SCI_DEV_INITIAL:
case SCI_DEV_FAILED:
case SCI_DEV_FINAL:
default:
dev_warn(scirdev_to_dev(idev), "%s: in wrong state: %s\n",
__func__, dev_state_name(state));
return SCI_FAILURE_INVALID_STATE;
case SCI_DEV_STOPPED:
return SCI_SUCCESS;
case SCI_DEV_STARTING:
BUG_ON(idev->started_request_count != 0);
sci_remote_node_context_destruct(&idev->rnc,
rnc_destruct_done, idev);
sci_change_state(sm, SCI_DEV_STOPPING);
return SCI_SUCCESS;
case SCI_DEV_READY:
case SCI_STP_DEV_IDLE:
case SCI_STP_DEV_CMD:
case SCI_STP_DEV_NCQ:
case SCI_STP_DEV_NCQ_ERROR:
case SCI_STP_DEV_AWAIT_RESET:
case SCI_SMP_DEV_IDLE:
case SCI_SMP_DEV_CMD:
sci_change_state(sm, SCI_DEV_STOPPING);
if (idev->started_request_count == 0)
sci_remote_node_context_destruct(&idev->rnc,
rnc_destruct_done,
idev);
else {
sci_remote_device_suspend(
idev, SCI_SW_SUSPEND_LINKHANG_DETECT);
sci_remote_device_terminate_requests(idev);
}
return SCI_SUCCESS;
case SCI_DEV_STOPPING:
return sci_remote_device_terminate_requests(idev);
case SCI_DEV_RESETTING:
sci_change_state(sm, SCI_DEV_STOPPING);
return SCI_SUCCESS;
}
}
enum sci_status sci_remote_device_reset(struct isci_remote_device *idev)
{
struct sci_base_state_machine *sm = &idev->sm;
enum sci_remote_device_states state = sm->current_state_id;
switch (state) {
case SCI_DEV_INITIAL:
case SCI_DEV_STOPPED:
case SCI_DEV_STARTING:
case SCI_SMP_DEV_IDLE:
case SCI_SMP_DEV_CMD:
case SCI_DEV_STOPPING:
case SCI_DEV_FAILED:
case SCI_DEV_RESETTING:
case SCI_DEV_FINAL:
default:
dev_warn(scirdev_to_dev(idev), "%s: in wrong state: %s\n",
__func__, dev_state_name(state));
return SCI_FAILURE_INVALID_STATE;
case SCI_DEV_READY:
case SCI_STP_DEV_IDLE:
case SCI_STP_DEV_CMD:
case SCI_STP_DEV_NCQ:
case SCI_STP_DEV_NCQ_ERROR:
case SCI_STP_DEV_AWAIT_RESET:
sci_change_state(sm, SCI_DEV_RESETTING);
return SCI_SUCCESS;
}
}
enum sci_status sci_remote_device_reset_complete(struct isci_remote_device *idev)
{
struct sci_base_state_machine *sm = &idev->sm;
enum sci_remote_device_states state = sm->current_state_id;
if (state != SCI_DEV_RESETTING) {
dev_warn(scirdev_to_dev(idev), "%s: in wrong state: %s\n",
__func__, dev_state_name(state));
return SCI_FAILURE_INVALID_STATE;
}
sci_change_state(sm, SCI_DEV_READY);
return SCI_SUCCESS;
}
enum sci_status sci_remote_device_frame_handler(struct isci_remote_device *idev,
u32 frame_index)
{
struct sci_base_state_machine *sm = &idev->sm;
enum sci_remote_device_states state = sm->current_state_id;
struct isci_host *ihost = idev->owning_port->owning_controller;
enum sci_status status;
switch (state) {
case SCI_DEV_INITIAL:
case SCI_DEV_STOPPED:
case SCI_DEV_STARTING:
case SCI_STP_DEV_IDLE:
case SCI_SMP_DEV_IDLE:
case SCI_DEV_FINAL:
default:
dev_warn(scirdev_to_dev(idev), "%s: in wrong state: %s\n",
__func__, dev_state_name(state));
sci_controller_release_frame(ihost, frame_index);
return SCI_FAILURE_INVALID_STATE;
case SCI_DEV_READY:
case SCI_STP_DEV_NCQ_ERROR:
case SCI_STP_DEV_AWAIT_RESET:
case SCI_DEV_STOPPING:
case SCI_DEV_FAILED:
case SCI_DEV_RESETTING: {
struct isci_request *ireq;
struct ssp_frame_hdr hdr;
void *frame_header;
ssize_t word_cnt;
status = sci_unsolicited_frame_control_get_header(&ihost->uf_control,
frame_index,
&frame_header);
if (status != SCI_SUCCESS)
return status;
word_cnt = sizeof(hdr) / sizeof(u32);
sci_swab32_cpy(&hdr, frame_header, word_cnt);
ireq = sci_request_by_tag(ihost, be16_to_cpu(hdr.tag));
if (ireq && ireq->target_device == idev) {
status = sci_io_request_frame_handler(ireq, frame_index);
} else {
sci_controller_release_frame(ihost, frame_index);
}
break;
}
case SCI_STP_DEV_NCQ: {
struct dev_to_host_fis *hdr;
status = sci_unsolicited_frame_control_get_header(&ihost->uf_control,
frame_index,
(void **)&hdr);
if (status != SCI_SUCCESS)
return status;
if (hdr->fis_type == FIS_SETDEVBITS &&
(hdr->status & ATA_ERR)) {
idev->not_ready_reason = SCIC_REMOTE_DEVICE_NOT_READY_SATA_SDB_ERROR_FIS_RECEIVED;
sci_change_state(sm, SCI_STP_DEV_NCQ_ERROR);
} else if (hdr->fis_type == FIS_REGD2H &&
(hdr->status & ATA_ERR)) {
idev->not_ready_reason = SCIC_REMOTE_DEVICE_NOT_READY_SATA_SDB_ERROR_FIS_RECEIVED;
sci_change_state(&idev->sm, SCI_STP_DEV_NCQ_ERROR);
} else
status = SCI_FAILURE;
sci_controller_release_frame(ihost, frame_index);
break;
}
case SCI_STP_DEV_CMD:
case SCI_SMP_DEV_CMD:
status = sci_io_request_frame_handler(idev->working_request, frame_index);
break;
}
return status;
}
static bool is_remote_device_ready(struct isci_remote_device *idev)
{
struct sci_base_state_machine *sm = &idev->sm;
enum sci_remote_device_states state = sm->current_state_id;
switch (state) {
case SCI_DEV_READY:
case SCI_STP_DEV_IDLE:
case SCI_STP_DEV_CMD:
case SCI_STP_DEV_NCQ:
case SCI_STP_DEV_NCQ_ERROR:
case SCI_STP_DEV_AWAIT_RESET:
case SCI_SMP_DEV_IDLE:
case SCI_SMP_DEV_CMD:
return true;
default:
return false;
}
}
static void atapi_remote_device_resume_done(void *_dev)
{
struct isci_remote_device *idev = _dev;
struct isci_request *ireq = idev->working_request;
sci_change_state(&ireq->sm, SCI_REQ_COMPLETED);
}
enum sci_status sci_remote_device_event_handler(struct isci_remote_device *idev,
u32 event_code)
{
enum sci_status status;
struct sci_base_state_machine *sm = &idev->sm;
enum sci_remote_device_states state = sm->current_state_id;
switch (scu_get_event_type(event_code)) {
case SCU_EVENT_TYPE_RNC_OPS_MISC:
case SCU_EVENT_TYPE_RNC_SUSPEND_TX:
case SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX:
status = sci_remote_node_context_event_handler(&idev->rnc, event_code);
break;
case SCU_EVENT_TYPE_PTX_SCHEDULE_EVENT:
if (scu_get_event_code(event_code) == SCU_EVENT_IT_NEXUS_TIMEOUT) {
status = SCI_SUCCESS;
sci_remote_device_suspend(idev, SCI_SW_SUSPEND_NORMAL);
dev_dbg(scirdev_to_dev(idev),
"%s: device: %p event code: %x: %s\n",
__func__, idev, event_code,
is_remote_device_ready(idev)
? "I_T_Nexus_Timeout event"
: "I_T_Nexus_Timeout event in wrong state");
break;
}
default:
dev_dbg(scirdev_to_dev(idev),
"%s: device: %p event code: %x: %s\n",
__func__, idev, event_code,
is_remote_device_ready(idev)
? "unexpected event"
: "unexpected event in wrong state");
status = SCI_FAILURE_INVALID_STATE;
break;
}
if (status != SCI_SUCCESS)
return status;
if (state == SCI_STP_DEV_ATAPI_ERROR) {
if (scu_get_event_type(event_code) == SCU_EVENT_TYPE_RNC_SUSPEND_TX ||
scu_get_event_type(event_code) == SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX) {
return sci_remote_node_context_resume(&idev->rnc,
atapi_remote_device_resume_done,
idev);
}
}
if (state == SCI_STP_DEV_IDLE) {
if (scu_get_event_type(event_code) == SCU_EVENT_TYPE_RNC_SUSPEND_TX ||
scu_get_event_type(event_code) == SCU_EVENT_TYPE_RNC_SUSPEND_TX_RX)
status = sci_remote_node_context_resume(&idev->rnc, NULL, NULL);
}
return status;
}
static void sci_remote_device_start_request(struct isci_remote_device *idev,
struct isci_request *ireq,
enum sci_status status)
{
struct isci_port *iport = idev->owning_port;
if (status != SCI_SUCCESS)
sci_port_complete_io(iport, idev, ireq);
else {
kref_get(&idev->kref);
idev->started_request_count++;
}
}
enum sci_status sci_remote_device_start_io(struct isci_host *ihost,
struct isci_remote_device *idev,
struct isci_request *ireq)
{
struct sci_base_state_machine *sm = &idev->sm;
enum sci_remote_device_states state = sm->current_state_id;
struct isci_port *iport = idev->owning_port;
enum sci_status status;
switch (state) {
case SCI_DEV_INITIAL:
case SCI_DEV_STOPPED:
case SCI_DEV_STARTING:
case SCI_STP_DEV_NCQ_ERROR:
case SCI_DEV_STOPPING:
case SCI_DEV_FAILED:
case SCI_DEV_RESETTING:
case SCI_DEV_FINAL:
default:
dev_warn(scirdev_to_dev(idev), "%s: in wrong state: %s\n",
__func__, dev_state_name(state));
return SCI_FAILURE_INVALID_STATE;
case SCI_DEV_READY:
status = sci_port_start_io(iport, idev, ireq);
if (status != SCI_SUCCESS)
return status;
status = sci_remote_node_context_start_io(&idev->rnc, ireq);
if (status != SCI_SUCCESS)
break;
status = sci_request_start(ireq);
break;
case SCI_STP_DEV_IDLE: {
enum sci_remote_device_states new_state;
struct sas_task *task = isci_request_access_task(ireq);
status = sci_port_start_io(iport, idev, ireq);
if (status != SCI_SUCCESS)
return status;
status = sci_remote_node_context_start_io(&idev->rnc, ireq);
if (status != SCI_SUCCESS)
break;
status = sci_request_start(ireq);
if (status != SCI_SUCCESS)
break;
if (task->ata_task.use_ncq)
new_state = SCI_STP_DEV_NCQ;
else {
idev->working_request = ireq;
new_state = SCI_STP_DEV_CMD;
}
sci_change_state(sm, new_state);
break;
}
case SCI_STP_DEV_NCQ: {
struct sas_task *task = isci_request_access_task(ireq);
if (task->ata_task.use_ncq) {
status = sci_port_start_io(iport, idev, ireq);
if (status != SCI_SUCCESS)
return status;
status = sci_remote_node_context_start_io(&idev->rnc, ireq);
if (status != SCI_SUCCESS)
break;
status = sci_request_start(ireq);
} else
return SCI_FAILURE_INVALID_STATE;
break;
}
case SCI_STP_DEV_AWAIT_RESET:
return SCI_FAILURE_REMOTE_DEVICE_RESET_REQUIRED;
case SCI_SMP_DEV_IDLE:
status = sci_port_start_io(iport, idev, ireq);
if (status != SCI_SUCCESS)
return status;
status = sci_remote_node_context_start_io(&idev->rnc, ireq);
if (status != SCI_SUCCESS)
break;
status = sci_request_start(ireq);
if (status != SCI_SUCCESS)
break;
idev->working_request = ireq;
sci_change_state(&idev->sm, SCI_SMP_DEV_CMD);
break;
case SCI_STP_DEV_CMD:
case SCI_SMP_DEV_CMD:
return SCI_FAILURE_INVALID_STATE;
}
sci_remote_device_start_request(idev, ireq, status);
return status;
}
static enum sci_status common_complete_io(struct isci_port *iport,
struct isci_remote_device *idev,
struct isci_request *ireq)
{
enum sci_status status;
status = sci_request_complete(ireq);
if (status != SCI_SUCCESS)
return status;
status = sci_port_complete_io(iport, idev, ireq);
if (status != SCI_SUCCESS)
return status;
sci_remote_device_decrement_request_count(idev);
return status;
}
enum sci_status sci_remote_device_complete_io(struct isci_host *ihost,
struct isci_remote_device *idev,
struct isci_request *ireq)
{
struct sci_base_state_machine *sm = &idev->sm;
enum sci_remote_device_states state = sm->current_state_id;
struct isci_port *iport = idev->owning_port;
enum sci_status status;
switch (state) {
case SCI_DEV_INITIAL:
case SCI_DEV_STOPPED:
case SCI_DEV_STARTING:
case SCI_STP_DEV_IDLE:
case SCI_SMP_DEV_IDLE:
case SCI_DEV_FAILED:
case SCI_DEV_FINAL:
default:
dev_warn(scirdev_to_dev(idev), "%s: in wrong state: %s\n",
__func__, dev_state_name(state));
return SCI_FAILURE_INVALID_STATE;
case SCI_DEV_READY:
case SCI_STP_DEV_AWAIT_RESET:
case SCI_DEV_RESETTING:
status = common_complete_io(iport, idev, ireq);
break;
case SCI_STP_DEV_CMD:
case SCI_STP_DEV_NCQ:
case SCI_STP_DEV_NCQ_ERROR:
case SCI_STP_DEV_ATAPI_ERROR:
status = common_complete_io(iport, idev, ireq);
if (status != SCI_SUCCESS)
break;
if (ireq->sci_status == SCI_FAILURE_REMOTE_DEVICE_RESET_REQUIRED) {
sci_change_state(sm, SCI_STP_DEV_AWAIT_RESET);
} else if (idev->started_request_count == 0)
sci_change_state(sm, SCI_STP_DEV_IDLE);
break;
case SCI_SMP_DEV_CMD:
status = common_complete_io(iport, idev, ireq);
if (status != SCI_SUCCESS)
break;
sci_change_state(sm, SCI_SMP_DEV_IDLE);
break;
case SCI_DEV_STOPPING:
status = common_complete_io(iport, idev, ireq);
if (status != SCI_SUCCESS)
break;
if (idev->started_request_count == 0)
sci_remote_node_context_destruct(&idev->rnc,
rnc_destruct_done,
idev);
break;
}
if (status != SCI_SUCCESS)
dev_err(scirdev_to_dev(idev),
"%s: Port:0x%p Device:0x%p Request:0x%p Status:0x%x "
"could not complete\n", __func__, iport,
idev, ireq, status);
else
isci_put_device(idev);
return status;
}
static void sci_remote_device_continue_request(void *dev)
{
struct isci_remote_device *idev = dev;
if (idev->working_request)
sci_controller_continue_io(idev->working_request);
}
enum sci_status sci_remote_device_start_task(struct isci_host *ihost,
struct isci_remote_device *idev,
struct isci_request *ireq)
{
struct sci_base_state_machine *sm = &idev->sm;
enum sci_remote_device_states state = sm->current_state_id;
struct isci_port *iport = idev->owning_port;
enum sci_status status;
switch (state) {
case SCI_DEV_INITIAL:
case SCI_DEV_STOPPED:
case SCI_DEV_STARTING:
case SCI_SMP_DEV_IDLE:
case SCI_SMP_DEV_CMD:
case SCI_DEV_STOPPING:
case SCI_DEV_FAILED:
case SCI_DEV_RESETTING:
case SCI_DEV_FINAL:
default:
dev_warn(scirdev_to_dev(idev), "%s: in wrong state: %s\n",
__func__, dev_state_name(state));
return SCI_FAILURE_INVALID_STATE;
case SCI_STP_DEV_IDLE:
case SCI_STP_DEV_CMD:
case SCI_STP_DEV_NCQ:
case SCI_STP_DEV_NCQ_ERROR:
case SCI_STP_DEV_AWAIT_RESET:
status = sci_port_start_io(iport, idev, ireq);
if (status != SCI_SUCCESS)
return status;
status = sci_request_start(ireq);
if (status != SCI_SUCCESS)
goto out;
idev->working_request = ireq;
sci_change_state(sm, SCI_STP_DEV_CMD);
sci_remote_device_suspend(idev,
SCI_SW_SUSPEND_LINKHANG_DETECT);
status = sci_remote_node_context_start_task(&idev->rnc, ireq,
sci_remote_device_continue_request, idev);
out:
sci_remote_device_start_request(idev, ireq, status);
return SCI_FAILURE_RESET_DEVICE_PARTIAL_SUCCESS;
case SCI_DEV_READY:
status = sci_port_start_io(iport, idev, ireq);
if (status != SCI_SUCCESS)
return status;
status = sci_remote_node_context_start_task(&idev->rnc, ireq,
NULL, NULL);
if (status != SCI_SUCCESS)
break;
status = sci_request_start(ireq);
break;
}
sci_remote_device_start_request(idev, ireq, status);
return status;
}
void sci_remote_device_post_request(struct isci_remote_device *idev, u32 request)
{
struct isci_port *iport = idev->owning_port;
u32 context;
context = request |
(ISCI_PEG << SCU_CONTEXT_COMMAND_PROTOCOL_ENGINE_GROUP_SHIFT) |
(iport->physical_port_index << SCU_CONTEXT_COMMAND_LOGICAL_PORT_SHIFT) |
idev->rnc.remote_node_index;
sci_controller_post_request(iport->owning_controller, context);
}
static void remote_device_resume_done(void *_dev)
{
struct isci_remote_device *idev = _dev;
if (is_remote_device_ready(idev))
return;
sci_change_state(&idev->sm, SCI_DEV_READY);
}
static void sci_stp_remote_device_ready_idle_substate_resume_complete_handler(void *_dev)
{
struct isci_remote_device *idev = _dev;
struct isci_host *ihost = idev->owning_port->owning_controller;
if (idev->sm.previous_state_id != SCI_STP_DEV_NCQ)
isci_remote_device_ready(ihost, idev);
}
static void sci_remote_device_initial_state_enter(struct sci_base_state_machine *sm)
{
struct isci_remote_device *idev = container_of(sm, typeof(*idev), sm);
sci_change_state(&idev->sm, SCI_DEV_STOPPED);
}
static enum sci_status sci_remote_device_destruct(struct isci_remote_device *idev)
{
struct sci_base_state_machine *sm = &idev->sm;
enum sci_remote_device_states state = sm->current_state_id;
struct isci_host *ihost;
if (state != SCI_DEV_STOPPED) {
dev_warn(scirdev_to_dev(idev), "%s: in wrong state: %s\n",
__func__, dev_state_name(state));
return SCI_FAILURE_INVALID_STATE;
}
ihost = idev->owning_port->owning_controller;
sci_controller_free_remote_node_context(ihost, idev,
idev->rnc.remote_node_index);
idev->rnc.remote_node_index = SCIC_SDS_REMOTE_NODE_CONTEXT_INVALID_INDEX;
sci_change_state(sm, SCI_DEV_FINAL);
return SCI_SUCCESS;
}
static void isci_remote_device_deconstruct(struct isci_host *ihost, struct isci_remote_device *idev)
{
dev_dbg(&ihost->pdev->dev,
"%s: isci_device = %p\n", __func__, idev);
BUG_ON(idev->started_request_count > 0);
sci_remote_device_destruct(idev);
list_del_init(&idev->node);
isci_put_device(idev);
}
static void sci_remote_device_stopped_state_enter(struct sci_base_state_machine *sm)
{
struct isci_remote_device *idev = container_of(sm, typeof(*idev), sm);
struct isci_host *ihost = idev->owning_port->owning_controller;
u32 prev_state;
prev_state = idev->sm.previous_state_id;
if (prev_state == SCI_DEV_STOPPING)
isci_remote_device_deconstruct(ihost, idev);
sci_controller_remote_device_stopped(ihost, idev);
}
static void sci_remote_device_starting_state_enter(struct sci_base_state_machine *sm)
{
struct isci_remote_device *idev = container_of(sm, typeof(*idev), sm);
struct isci_host *ihost = idev->owning_port->owning_controller;
isci_remote_device_not_ready(ihost, idev,
SCIC_REMOTE_DEVICE_NOT_READY_START_REQUESTED);
}
static void sci_remote_device_ready_state_enter(struct sci_base_state_machine *sm)
{
struct isci_remote_device *idev = container_of(sm, typeof(*idev), sm);
struct isci_host *ihost = idev->owning_port->owning_controller;
struct domain_device *dev = idev->domain_dev;
if (dev->dev_type == SATA_DEV || (dev->tproto & SAS_PROTOCOL_SATA)) {
sci_change_state(&idev->sm, SCI_STP_DEV_IDLE);
} else if (dev_is_expander(dev)) {
sci_change_state(&idev->sm, SCI_SMP_DEV_IDLE);
} else
isci_remote_device_ready(ihost, idev);
}
static void sci_remote_device_ready_state_exit(struct sci_base_state_machine *sm)
{
struct isci_remote_device *idev = container_of(sm, typeof(*idev), sm);
struct domain_device *dev = idev->domain_dev;
if (dev->dev_type == SAS_END_DEV) {
struct isci_host *ihost = idev->owning_port->owning_controller;
isci_remote_device_not_ready(ihost, idev,
SCIC_REMOTE_DEVICE_NOT_READY_STOP_REQUESTED);
}
}
static void sci_remote_device_resetting_state_enter(struct sci_base_state_machine *sm)
{
struct isci_remote_device *idev = container_of(sm, typeof(*idev), sm);
struct isci_host *ihost = idev->owning_port->owning_controller;
dev_dbg(&ihost->pdev->dev,
"%s: isci_device = %p\n", __func__, idev);
sci_remote_device_suspend(idev, SCI_SW_SUSPEND_LINKHANG_DETECT);
}
static void sci_remote_device_resetting_state_exit(struct sci_base_state_machine *sm)
{
struct isci_remote_device *idev = container_of(sm, typeof(*idev), sm);
struct isci_host *ihost = idev->owning_port->owning_controller;
dev_dbg(&ihost->pdev->dev,
"%s: isci_device = %p\n", __func__, idev);
sci_remote_node_context_resume(&idev->rnc, NULL, NULL);
}
static void sci_stp_remote_device_ready_idle_substate_enter(struct sci_base_state_machine *sm)
{
struct isci_remote_device *idev = container_of(sm, typeof(*idev), sm);
idev->working_request = NULL;
if (sci_remote_node_context_is_ready(&idev->rnc)) {
sci_stp_remote_device_ready_idle_substate_resume_complete_handler(idev);
} else {
sci_remote_node_context_resume(&idev->rnc,
sci_stp_remote_device_ready_idle_substate_resume_complete_handler,
idev);
}
}
static void sci_stp_remote_device_ready_cmd_substate_enter(struct sci_base_state_machine *sm)
{
struct isci_remote_device *idev = container_of(sm, typeof(*idev), sm);
struct isci_host *ihost = idev->owning_port->owning_controller;
BUG_ON(idev->working_request == NULL);
isci_remote_device_not_ready(ihost, idev,
SCIC_REMOTE_DEVICE_NOT_READY_SATA_REQUEST_STARTED);
}
static void sci_stp_remote_device_ready_ncq_error_substate_enter(struct sci_base_state_machine *sm)
{
struct isci_remote_device *idev = container_of(sm, typeof(*idev), sm);
struct isci_host *ihost = idev->owning_port->owning_controller;
if (idev->not_ready_reason == SCIC_REMOTE_DEVICE_NOT_READY_SATA_SDB_ERROR_FIS_RECEIVED)
isci_remote_device_not_ready(ihost, idev,
idev->not_ready_reason);
}
static void sci_smp_remote_device_ready_idle_substate_enter(struct sci_base_state_machine *sm)
{
struct isci_remote_device *idev = container_of(sm, typeof(*idev), sm);
struct isci_host *ihost = idev->owning_port->owning_controller;
isci_remote_device_ready(ihost, idev);
}
static void sci_smp_remote_device_ready_cmd_substate_enter(struct sci_base_state_machine *sm)
{
struct isci_remote_device *idev = container_of(sm, typeof(*idev), sm);
struct isci_host *ihost = idev->owning_port->owning_controller;
BUG_ON(idev->working_request == NULL);
isci_remote_device_not_ready(ihost, idev,
SCIC_REMOTE_DEVICE_NOT_READY_SMP_REQUEST_STARTED);
}
static void sci_smp_remote_device_ready_cmd_substate_exit(struct sci_base_state_machine *sm)
{
struct isci_remote_device *idev = container_of(sm, typeof(*idev), sm);
idev->working_request = NULL;
}
static void sci_remote_device_construct(struct isci_port *iport,
struct isci_remote_device *idev)
{
idev->owning_port = iport;
idev->started_request_count = 0;
sci_init_sm(&idev->sm, sci_remote_device_state_table, SCI_DEV_INITIAL);
sci_remote_node_context_construct(&idev->rnc,
SCIC_SDS_REMOTE_NODE_CONTEXT_INVALID_INDEX);
}
static enum sci_status sci_remote_device_da_construct(struct isci_port *iport,
struct isci_remote_device *idev)
{
enum sci_status status;
struct sci_port_properties properties;
sci_remote_device_construct(iport, idev);
sci_port_get_properties(iport, &properties);
idev->device_port_width = hweight32(properties.phy_mask);
status = sci_controller_allocate_remote_node_context(iport->owning_controller,
idev,
&idev->rnc.remote_node_index);
if (status != SCI_SUCCESS)
return status;
idev->connection_rate = sci_port_get_max_allowed_speed(iport);
return SCI_SUCCESS;
}
static enum sci_status sci_remote_device_ea_construct(struct isci_port *iport,
struct isci_remote_device *idev)
{
struct domain_device *dev = idev->domain_dev;
enum sci_status status;
sci_remote_device_construct(iport, idev);
status = sci_controller_allocate_remote_node_context(iport->owning_controller,
idev,
&idev->rnc.remote_node_index);
if (status != SCI_SUCCESS)
return status;
idev->connection_rate = min_t(u16, sci_port_get_max_allowed_speed(iport),
dev->linkrate);
idev->device_port_width = 1;
return SCI_SUCCESS;
}
enum sci_status sci_remote_device_resume(
struct isci_remote_device *idev,
scics_sds_remote_node_context_callback cb_fn,
void *cb_p)
{
enum sci_status status;
status = sci_remote_node_context_resume(&idev->rnc, cb_fn, cb_p);
if (status != SCI_SUCCESS)
dev_dbg(scirdev_to_dev(idev), "%s: failed to resume: %d\n",
__func__, status);
return status;
}
static void isci_remote_device_resume_from_abort_complete(void *cbparam)
{
struct isci_remote_device *idev = cbparam;
struct isci_host *ihost = idev->owning_port->owning_controller;
scics_sds_remote_node_context_callback abort_resume_cb =
idev->abort_resume_cb;
dev_dbg(scirdev_to_dev(idev), "%s: passing-along resume: %p\n",
__func__, abort_resume_cb);
if (abort_resume_cb != NULL) {
idev->abort_resume_cb = NULL;
abort_resume_cb(idev->abort_resume_cbparam);
}
clear_bit(IDEV_ABORT_PATH_RESUME_PENDING, &idev->flags);
wake_up(&ihost->eventq);
}
static bool isci_remote_device_test_resume_done(
struct isci_host *ihost,
struct isci_remote_device *idev)
{
unsigned long flags;
bool done;
spin_lock_irqsave(&ihost->scic_lock, flags);
done = !test_bit(IDEV_ABORT_PATH_RESUME_PENDING, &idev->flags)
|| test_bit(IDEV_STOP_PENDING, &idev->flags)
|| sci_remote_node_context_is_being_destroyed(&idev->rnc);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
return done;
}
void isci_remote_device_wait_for_resume_from_abort(
struct isci_host *ihost,
struct isci_remote_device *idev)
{
dev_dbg(&ihost->pdev->dev, "%s: starting resume wait: %p\n",
__func__, idev);
#define MAX_RESUME_MSECS 10000
if (!wait_event_timeout(ihost->eventq,
isci_remote_device_test_resume_done(ihost, idev),
msecs_to_jiffies(MAX_RESUME_MSECS))) {
dev_warn(&ihost->pdev->dev, "%s: #### Timeout waiting for "
"resume: %p\n", __func__, idev);
}
clear_bit(IDEV_ABORT_PATH_RESUME_PENDING, &idev->flags);
dev_dbg(&ihost->pdev->dev, "%s: resume wait done: %p\n",
__func__, idev);
}
enum sci_status isci_remote_device_resume_from_abort(
struct isci_host *ihost,
struct isci_remote_device *idev)
{
unsigned long flags;
enum sci_status status = SCI_SUCCESS;
int destroyed;
spin_lock_irqsave(&ihost->scic_lock, flags);
idev->abort_resume_cb = idev->rnc.user_callback;
idev->abort_resume_cbparam = idev->rnc.user_cookie;
set_bit(IDEV_ABORT_PATH_RESUME_PENDING, &idev->flags);
clear_bit(IDEV_ABORT_PATH_ACTIVE, &idev->flags);
destroyed = sci_remote_node_context_is_being_destroyed(&idev->rnc);
if (!destroyed)
status = sci_remote_device_resume(
idev, isci_remote_device_resume_from_abort_complete,
idev);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
if (!destroyed && (status == SCI_SUCCESS))
isci_remote_device_wait_for_resume_from_abort(ihost, idev);
else
clear_bit(IDEV_ABORT_PATH_RESUME_PENDING, &idev->flags);
return status;
}
static enum sci_status sci_remote_device_start(struct isci_remote_device *idev,
u32 timeout)
{
struct sci_base_state_machine *sm = &idev->sm;
enum sci_remote_device_states state = sm->current_state_id;
enum sci_status status;
if (state != SCI_DEV_STOPPED) {
dev_warn(scirdev_to_dev(idev), "%s: in wrong state: %s\n",
__func__, dev_state_name(state));
return SCI_FAILURE_INVALID_STATE;
}
status = sci_remote_device_resume(idev, remote_device_resume_done,
idev);
if (status != SCI_SUCCESS)
return status;
sci_change_state(sm, SCI_DEV_STARTING);
return SCI_SUCCESS;
}
static enum sci_status isci_remote_device_construct(struct isci_port *iport,
struct isci_remote_device *idev)
{
struct isci_host *ihost = iport->isci_host;
struct domain_device *dev = idev->domain_dev;
enum sci_status status;
if (dev->parent && dev_is_expander(dev->parent))
status = sci_remote_device_ea_construct(iport, idev);
else
status = sci_remote_device_da_construct(iport, idev);
if (status != SCI_SUCCESS) {
dev_dbg(&ihost->pdev->dev, "%s: construct failed: %d\n",
__func__, status);
return status;
}
status = sci_remote_device_start(idev, ISCI_REMOTE_DEVICE_START_TIMEOUT);
if (status != SCI_SUCCESS)
dev_warn(&ihost->pdev->dev, "remote device start failed: %d\n",
status);
return status;
}
static struct isci_remote_device *
isci_remote_device_alloc(struct isci_host *ihost, struct isci_port *iport)
{
struct isci_remote_device *idev;
int i;
for (i = 0; i < SCI_MAX_REMOTE_DEVICES; i++) {
idev = &ihost->devices[i];
if (!test_and_set_bit(IDEV_ALLOCATED, &idev->flags))
break;
}
if (i >= SCI_MAX_REMOTE_DEVICES) {
dev_warn(&ihost->pdev->dev, "%s: failed\n", __func__);
return NULL;
}
if (WARN_ONCE(!list_empty(&idev->node), "found non-idle remote device\n"))
return NULL;
return idev;
}
void isci_remote_device_release(struct kref *kref)
{
struct isci_remote_device *idev = container_of(kref, typeof(*idev), kref);
struct isci_host *ihost = idev->isci_port->isci_host;
idev->domain_dev = NULL;
idev->isci_port = NULL;
clear_bit(IDEV_START_PENDING, &idev->flags);
clear_bit(IDEV_STOP_PENDING, &idev->flags);
clear_bit(IDEV_IO_READY, &idev->flags);
clear_bit(IDEV_GONE, &idev->flags);
smp_mb__before_clear_bit();
clear_bit(IDEV_ALLOCATED, &idev->flags);
wake_up(&ihost->eventq);
}
enum sci_status isci_remote_device_stop(struct isci_host *ihost, struct isci_remote_device *idev)
{
enum sci_status status;
unsigned long flags;
dev_dbg(&ihost->pdev->dev,
"%s: isci_device = %p\n", __func__, idev);
spin_lock_irqsave(&ihost->scic_lock, flags);
idev->domain_dev->lldd_dev = NULL;
set_bit(IDEV_GONE, &idev->flags);
set_bit(IDEV_STOP_PENDING, &idev->flags);
status = sci_remote_device_stop(idev, 50);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
if (WARN_ONCE(status != SCI_SUCCESS, "failed to stop device\n"))
;
else
wait_for_device_stop(ihost, idev);
dev_dbg(&ihost->pdev->dev,
"%s: isci_device = %p, waiting done.\n", __func__, idev);
return status;
}
void isci_remote_device_gone(struct domain_device *dev)
{
struct isci_host *ihost = dev_to_ihost(dev);
struct isci_remote_device *idev = dev->lldd_dev;
dev_dbg(&ihost->pdev->dev,
"%s: domain_device = %p, isci_device = %p, isci_port = %p\n",
__func__, dev, idev, idev->isci_port);
isci_remote_device_stop(ihost, idev);
}
int isci_remote_device_found(struct domain_device *dev)
{
struct isci_host *isci_host = dev_to_ihost(dev);
struct isci_port *isci_port = dev->port->lldd_port;
struct isci_remote_device *isci_device;
enum sci_status status;
dev_dbg(&isci_host->pdev->dev,
"%s: domain_device = %p\n", __func__, dev);
if (!isci_port)
return -ENODEV;
isci_device = isci_remote_device_alloc(isci_host, isci_port);
if (!isci_device)
return -ENODEV;
kref_init(&isci_device->kref);
INIT_LIST_HEAD(&isci_device->node);
spin_lock_irq(&isci_host->scic_lock);
isci_device->domain_dev = dev;
isci_device->isci_port = isci_port;
list_add_tail(&isci_device->node, &isci_port->remote_dev_list);
set_bit(IDEV_START_PENDING, &isci_device->flags);
status = isci_remote_device_construct(isci_port, isci_device);
dev_dbg(&isci_host->pdev->dev,
"%s: isci_device = %p\n",
__func__, isci_device);
if (status == SCI_SUCCESS) {
dev->lldd_dev = isci_device;
} else
isci_put_device(isci_device);
spin_unlock_irq(&isci_host->scic_lock);
wait_for_device_start(isci_host, isci_device);
return status == SCI_SUCCESS ? 0 : -ENODEV;
}
enum sci_status isci_remote_device_suspend_terminate(
struct isci_host *ihost,
struct isci_remote_device *idev,
struct isci_request *ireq)
{
unsigned long flags;
enum sci_status status;
spin_lock_irqsave(&ihost->scic_lock, flags);
set_bit(IDEV_ABORT_PATH_ACTIVE, &idev->flags);
sci_remote_device_suspend(idev, SCI_SW_SUSPEND_LINKHANG_DETECT);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
status = isci_remote_device_terminate_requests(ihost, idev, ireq);
if (status != SCI_SUCCESS)
dev_dbg(&ihost->pdev->dev,
"%s: isci_remote_device_terminate_requests(%p) "
"returned %d!\n",
__func__, idev, status);
return status;
}
int isci_remote_device_is_safe_to_abort(
struct isci_remote_device *idev)
{
return sci_remote_node_context_is_safe_to_abort(&idev->rnc);
}
enum sci_status sci_remote_device_abort_requests_pending_abort(
struct isci_remote_device *idev)
{
return sci_remote_device_terminate_reqs_checkabort(idev, 1);
}
enum sci_status isci_remote_device_reset_complete(
struct isci_host *ihost,
struct isci_remote_device *idev)
{
unsigned long flags;
enum sci_status status;
spin_lock_irqsave(&ihost->scic_lock, flags);
status = sci_remote_device_reset_complete(idev);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
return status;
}
void isci_dev_set_hang_detection_timeout(
struct isci_remote_device *idev,
u32 timeout)
{
if (dev_is_sata(idev->domain_dev)) {
if (timeout) {
if (test_and_set_bit(IDEV_RNC_LLHANG_ENABLED,
&idev->flags))
return;
} else if (!test_and_clear_bit(IDEV_RNC_LLHANG_ENABLED,
&idev->flags))
return;
sci_port_set_hang_detection_timeout(idev->owning_port,
timeout);
}
}
