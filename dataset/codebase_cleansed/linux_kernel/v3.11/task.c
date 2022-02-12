static void isci_task_refuse(struct isci_host *ihost, struct sas_task *task,
enum service_response response,
enum exec_status status)
{
unsigned long flags;
dev_dbg(&ihost->pdev->dev, "%s: task = %p, response=%d, status=%d\n",
__func__, task, response, status);
spin_lock_irqsave(&task->task_state_lock, flags);
task->task_status.resp = response;
task->task_status.stat = status;
task->task_state_flags |= SAS_TASK_STATE_DONE;
task->task_state_flags &= ~(SAS_TASK_AT_INITIATOR |
SAS_TASK_STATE_PENDING);
task->lldd_task = NULL;
spin_unlock_irqrestore(&task->task_state_lock, flags);
task->task_done(task);
}
static inline int isci_device_io_ready(struct isci_remote_device *idev,
struct sas_task *task)
{
return idev ? test_bit(IDEV_IO_READY, &idev->flags) ||
(test_bit(IDEV_IO_NCQERROR, &idev->flags) &&
isci_task_is_ncq_recovery(task))
: 0;
}
int isci_task_execute_task(struct sas_task *task, int num, gfp_t gfp_flags)
{
struct isci_host *ihost = dev_to_ihost(task->dev);
struct isci_remote_device *idev;
unsigned long flags;
bool io_ready;
u16 tag;
dev_dbg(&ihost->pdev->dev, "%s: num=%d\n", __func__, num);
for_each_sas_task(num, task) {
enum sci_status status = SCI_FAILURE;
spin_lock_irqsave(&ihost->scic_lock, flags);
idev = isci_lookup_device(task->dev);
io_ready = isci_device_io_ready(idev, task);
tag = isci_alloc_tag(ihost);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
dev_dbg(&ihost->pdev->dev,
"task: %p, num: %d dev: %p idev: %p:%#lx cmd = %p\n",
task, num, task->dev, idev, idev ? idev->flags : 0,
task->uldd_task);
if (!idev) {
isci_task_refuse(ihost, task, SAS_TASK_UNDELIVERED,
SAS_DEVICE_UNKNOWN);
} else if (!io_ready || tag == SCI_CONTROLLER_INVALID_IO_TAG) {
isci_task_refuse(ihost, task, SAS_TASK_COMPLETE,
SAS_QUEUE_FULL);
} else {
spin_lock_irqsave(&task->task_state_lock, flags);
if (task->task_state_flags & SAS_TASK_STATE_ABORTED) {
spin_unlock_irqrestore(&task->task_state_lock,
flags);
isci_task_refuse(ihost, task,
SAS_TASK_UNDELIVERED,
SAM_STAT_TASK_ABORTED);
} else {
task->task_state_flags |= SAS_TASK_AT_INITIATOR;
spin_unlock_irqrestore(&task->task_state_lock, flags);
status = isci_request_execute(ihost, idev, task, tag);
if (status != SCI_SUCCESS) {
spin_lock_irqsave(&task->task_state_lock, flags);
task->task_state_flags &= ~SAS_TASK_AT_INITIATOR;
spin_unlock_irqrestore(&task->task_state_lock, flags);
if (test_bit(IDEV_GONE, &idev->flags)) {
isci_task_refuse(ihost, task,
SAS_TASK_UNDELIVERED,
SAS_DEVICE_UNKNOWN);
} else {
isci_task_refuse(ihost, task,
SAS_TASK_COMPLETE,
SAS_QUEUE_FULL);
}
}
}
}
if (status != SCI_SUCCESS && tag != SCI_CONTROLLER_INVALID_IO_TAG) {
spin_lock_irqsave(&ihost->scic_lock, flags);
isci_tci_free(ihost, ISCI_TAG_TCI(tag));
spin_unlock_irqrestore(&ihost->scic_lock, flags);
}
isci_put_device(idev);
}
return 0;
}
static struct isci_request *isci_task_request_build(struct isci_host *ihost,
struct isci_remote_device *idev,
u16 tag, struct isci_tmf *isci_tmf)
{
enum sci_status status = SCI_FAILURE;
struct isci_request *ireq = NULL;
struct domain_device *dev;
dev_dbg(&ihost->pdev->dev,
"%s: isci_tmf = %p\n", __func__, isci_tmf);
dev = idev->domain_dev;
ireq = isci_tmf_request_from_tag(ihost, isci_tmf, tag);
if (!ireq)
return NULL;
status = sci_task_request_construct(ihost, idev, tag,
ireq);
if (status != SCI_SUCCESS) {
dev_warn(&ihost->pdev->dev,
"%s: sci_task_request_construct failed - "
"status = 0x%x\n",
__func__,
status);
return NULL;
}
if (dev->dev_type == SAS_END_DEVICE) {
isci_tmf->proto = SAS_PROTOCOL_SSP;
status = sci_task_request_construct_ssp(ireq);
if (status != SCI_SUCCESS)
return NULL;
}
return ireq;
}
static int isci_task_execute_tmf(struct isci_host *ihost,
struct isci_remote_device *idev,
struct isci_tmf *tmf, unsigned long timeout_ms)
{
DECLARE_COMPLETION_ONSTACK(completion);
enum sci_task_status status = SCI_TASK_FAILURE;
struct isci_request *ireq;
int ret = TMF_RESP_FUNC_FAILED;
unsigned long flags;
unsigned long timeleft;
u16 tag;
spin_lock_irqsave(&ihost->scic_lock, flags);
tag = isci_alloc_tag(ihost);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
if (tag == SCI_CONTROLLER_INVALID_IO_TAG)
return ret;
if (!idev ||
(!test_bit(IDEV_IO_READY, &idev->flags) &&
!test_bit(IDEV_IO_NCQERROR, &idev->flags))) {
dev_dbg(&ihost->pdev->dev,
"%s: idev = %p not ready (%#lx)\n",
__func__,
idev, idev ? idev->flags : 0);
goto err_tci;
} else
dev_dbg(&ihost->pdev->dev,
"%s: idev = %p\n",
__func__, idev);
tmf->complete = &completion;
tmf->status = SCI_FAILURE_TIMEOUT;
ireq = isci_task_request_build(ihost, idev, tag, tmf);
if (!ireq)
goto err_tci;
spin_lock_irqsave(&ihost->scic_lock, flags);
status = sci_controller_start_task(ihost, idev, ireq);
if (status != SCI_TASK_SUCCESS) {
dev_dbg(&ihost->pdev->dev,
"%s: start_io failed - status = 0x%x, request = %p\n",
__func__,
status,
ireq);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
goto err_tci;
}
spin_unlock_irqrestore(&ihost->scic_lock, flags);
isci_remote_device_resume_from_abort(ihost, idev);
timeleft = wait_for_completion_timeout(&completion,
msecs_to_jiffies(timeout_ms));
if (timeleft == 0) {
isci_remote_device_suspend_terminate(ihost, idev, ireq);
}
isci_print_tmf(ihost, tmf);
if (tmf->status == SCI_SUCCESS)
ret = TMF_RESP_FUNC_COMPLETE;
else if (tmf->status == SCI_FAILURE_IO_RESPONSE_VALID) {
dev_dbg(&ihost->pdev->dev,
"%s: tmf.status == "
"SCI_FAILURE_IO_RESPONSE_VALID\n",
__func__);
ret = TMF_RESP_FUNC_COMPLETE;
}
dev_dbg(&ihost->pdev->dev,
"%s: completed request = %p\n",
__func__,
ireq);
return ret;
err_tci:
spin_lock_irqsave(&ihost->scic_lock, flags);
isci_tci_free(ihost, ISCI_TAG_TCI(tag));
spin_unlock_irqrestore(&ihost->scic_lock, flags);
return ret;
}
static void isci_task_build_tmf(struct isci_tmf *tmf,
enum isci_tmf_function_codes code)
{
memset(tmf, 0, sizeof(*tmf));
tmf->tmf_code = code;
}
static void isci_task_build_abort_task_tmf(struct isci_tmf *tmf,
enum isci_tmf_function_codes code,
struct isci_request *old_request)
{
isci_task_build_tmf(tmf, code);
tmf->io_tag = old_request->io_tag;
}
static int isci_task_send_lu_reset_sas(
struct isci_host *isci_host,
struct isci_remote_device *isci_device,
u8 *lun)
{
struct isci_tmf tmf;
int ret = TMF_RESP_FUNC_FAILED;
dev_dbg(&isci_host->pdev->dev,
"%s: isci_host = %p, isci_device = %p\n",
__func__, isci_host, isci_device);
isci_task_build_tmf(&tmf, isci_tmf_ssp_lun_reset);
#define ISCI_LU_RESET_TIMEOUT_MS 2000
ret = isci_task_execute_tmf(isci_host, isci_device, &tmf, ISCI_LU_RESET_TIMEOUT_MS);
if (ret == TMF_RESP_FUNC_COMPLETE)
dev_dbg(&isci_host->pdev->dev,
"%s: %p: TMF_LU_RESET passed\n",
__func__, isci_device);
else
dev_dbg(&isci_host->pdev->dev,
"%s: %p: TMF_LU_RESET failed (%x)\n",
__func__, isci_device, ret);
return ret;
}
int isci_task_lu_reset(struct domain_device *dev, u8 *lun)
{
struct isci_host *ihost = dev_to_ihost(dev);
struct isci_remote_device *idev;
unsigned long flags;
int ret = TMF_RESP_FUNC_COMPLETE;
spin_lock_irqsave(&ihost->scic_lock, flags);
idev = isci_get_device(dev->lldd_dev);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
dev_dbg(&ihost->pdev->dev,
"%s: domain_device=%p, isci_host=%p; isci_device=%p\n",
__func__, dev, ihost, idev);
if (!idev) {
dev_dbg(&ihost->pdev->dev, "%s: No dev\n", __func__);
ret = TMF_RESP_FUNC_FAILED;
goto out;
}
if (isci_remote_device_suspend_terminate(ihost, idev, NULL)
!= SCI_SUCCESS) {
ret = TMF_RESP_FUNC_FAILED;
goto out;
}
if (!test_bit(IDEV_GONE, &idev->flags)) {
if (dev_is_sata(dev))
sas_ata_schedule_reset(dev);
else
ret = isci_task_send_lu_reset_sas(ihost, idev, lun);
}
out:
isci_put_device(idev);
return ret;
}
int isci_task_clear_nexus_port(struct asd_sas_port *port)
{
return TMF_RESP_FUNC_FAILED;
}
int isci_task_clear_nexus_ha(struct sas_ha_struct *ha)
{
return TMF_RESP_FUNC_FAILED;
}
int isci_task_abort_task(struct sas_task *task)
{
struct isci_host *ihost = dev_to_ihost(task->dev);
DECLARE_COMPLETION_ONSTACK(aborted_io_completion);
struct isci_request *old_request = NULL;
struct isci_remote_device *idev = NULL;
struct isci_tmf tmf;
int ret = TMF_RESP_FUNC_FAILED;
unsigned long flags;
int target_done_already = 0;
spin_lock_irqsave(&ihost->scic_lock, flags);
spin_lock(&task->task_state_lock);
old_request = task->lldd_task;
if (!(task->task_state_flags & SAS_TASK_STATE_DONE) &&
(task->task_state_flags & SAS_TASK_AT_INITIATOR) &&
old_request) {
idev = isci_get_device(task->dev->lldd_dev);
target_done_already = test_bit(IREQ_COMPLETE_IN_TARGET,
&old_request->flags);
}
spin_unlock(&task->task_state_lock);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
dev_warn(&ihost->pdev->dev,
"%s: dev = %p (%s%s), task = %p, old_request == %p\n",
__func__, idev,
(dev_is_sata(task->dev) ? "STP/SATA"
: ((dev_is_expander(task->dev))
? "SMP"
: "SSP")),
((idev) ? ((test_bit(IDEV_GONE, &idev->flags))
? " IDEV_GONE"
: "")
: " <NULL>"),
task, old_request);
if (!idev || !old_request) {
spin_lock_irqsave(&task->task_state_lock, flags);
task->task_state_flags |= SAS_TASK_STATE_DONE;
task->task_state_flags &= ~(SAS_TASK_AT_INITIATOR |
SAS_TASK_STATE_PENDING);
spin_unlock_irqrestore(&task->task_state_lock, flags);
ret = TMF_RESP_FUNC_COMPLETE;
dev_warn(&ihost->pdev->dev,
"%s: abort task not needed for %p\n",
__func__, task);
goto out;
}
if (isci_remote_device_suspend_terminate(ihost, idev, old_request)
!= SCI_SUCCESS) {
dev_warn(&ihost->pdev->dev,
"%s: isci_remote_device_reset_terminate(dev=%p, "
"req=%p, task=%p) failed\n",
__func__, idev, old_request, task);
ret = TMF_RESP_FUNC_FAILED;
goto out;
}
spin_lock_irqsave(&ihost->scic_lock, flags);
if (task->task_proto == SAS_PROTOCOL_SMP ||
sas_protocol_ata(task->task_proto) ||
target_done_already ||
test_bit(IDEV_GONE, &idev->flags)) {
spin_unlock_irqrestore(&ihost->scic_lock, flags);
isci_remote_device_resume_from_abort(ihost, idev);
dev_warn(&ihost->pdev->dev,
"%s: %s request"
" or complete_in_target (%d), "
"or IDEV_GONE (%d), thus no TMF\n",
__func__,
((task->task_proto == SAS_PROTOCOL_SMP)
? "SMP"
: (sas_protocol_ata(task->task_proto)
? "SATA/STP"
: "<other>")
),
test_bit(IREQ_COMPLETE_IN_TARGET,
&old_request->flags),
test_bit(IDEV_GONE, &idev->flags));
spin_lock_irqsave(&task->task_state_lock, flags);
task->task_state_flags &= ~(SAS_TASK_AT_INITIATOR |
SAS_TASK_STATE_PENDING);
task->task_state_flags |= SAS_TASK_STATE_DONE;
spin_unlock_irqrestore(&task->task_state_lock, flags);
ret = TMF_RESP_FUNC_COMPLETE;
} else {
isci_task_build_abort_task_tmf(&tmf, isci_tmf_ssp_task_abort,
old_request);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
#define ISCI_ABORT_TASK_TIMEOUT_MS 500
ret = isci_task_execute_tmf(ihost, idev, &tmf,
ISCI_ABORT_TASK_TIMEOUT_MS);
}
out:
dev_warn(&ihost->pdev->dev,
"%s: Done; dev = %p, task = %p , old_request == %p\n",
__func__, idev, task, old_request);
isci_put_device(idev);
return ret;
}
int isci_task_abort_task_set(
struct domain_device *d_device,
u8 *lun)
{
return TMF_RESP_FUNC_FAILED;
}
int isci_task_clear_aca(
struct domain_device *d_device,
u8 *lun)
{
return TMF_RESP_FUNC_FAILED;
}
int isci_task_clear_task_set(
struct domain_device *d_device,
u8 *lun)
{
return TMF_RESP_FUNC_FAILED;
}
int isci_task_query_task(
struct sas_task *task)
{
if (task->task_state_flags & SAS_TASK_NEED_DEV_RESET)
return TMF_RESP_FUNC_FAILED;
else
return TMF_RESP_FUNC_SUCC;
}
void
isci_task_request_complete(struct isci_host *ihost,
struct isci_request *ireq,
enum sci_task_status completion_status)
{
struct isci_tmf *tmf = isci_request_access_tmf(ireq);
struct completion *tmf_complete = NULL;
dev_dbg(&ihost->pdev->dev,
"%s: request = %p, status=%d\n",
__func__, ireq, completion_status);
set_bit(IREQ_COMPLETE_IN_TARGET, &ireq->flags);
if (tmf) {
tmf->status = completion_status;
if (tmf->proto == SAS_PROTOCOL_SSP) {
memcpy(&tmf->resp.resp_iu,
&ireq->ssp.rsp,
SSP_RESP_IU_MAX_SIZE);
} else if (tmf->proto == SAS_PROTOCOL_SATA) {
memcpy(&tmf->resp.d2h_fis,
&ireq->stp.rsp,
sizeof(struct dev_to_host_fis));
}
tmf_complete = tmf->complete;
}
sci_controller_complete_io(ihost, ireq->target_device, ireq);
set_bit(IREQ_TERMINATED, &ireq->flags);
if (test_and_clear_bit(IREQ_ABORT_PATH_ACTIVE, &ireq->flags))
wake_up_all(&ihost->eventq);
if (!test_bit(IREQ_NO_AUTO_FREE_TAG, &ireq->flags))
isci_free_tag(ihost, ireq->io_tag);
if (tmf_complete)
complete(tmf_complete);
}
static int isci_reset_device(struct isci_host *ihost,
struct domain_device *dev,
struct isci_remote_device *idev)
{
int rc = TMF_RESP_FUNC_COMPLETE, reset_stat = -1;
struct sas_phy *phy = sas_get_local_phy(dev);
struct isci_port *iport = dev->port->lldd_port;
dev_dbg(&ihost->pdev->dev, "%s: idev %p\n", __func__, idev);
if (isci_remote_device_suspend_terminate(ihost, idev, NULL)
!= SCI_SUCCESS) {
rc = TMF_RESP_FUNC_FAILED;
goto out;
}
if (!test_bit(IDEV_GONE, &idev->flags)) {
if (scsi_is_sas_phy_local(phy)) {
struct isci_phy *iphy = &ihost->phys[phy->number];
reset_stat = isci_port_perform_hard_reset(ihost, iport,
iphy);
} else
reset_stat = sas_phy_reset(phy, !dev_is_sata(dev));
}
isci_remote_device_resume_from_abort(ihost, idev);
dev_dbg(&ihost->pdev->dev, "%s: idev %p complete, reset_stat=%d.\n",
__func__, idev, reset_stat);
out:
sas_put_local_phy(phy);
return rc;
}
int isci_task_I_T_nexus_reset(struct domain_device *dev)
{
struct isci_host *ihost = dev_to_ihost(dev);
struct isci_remote_device *idev;
unsigned long flags;
int ret;
spin_lock_irqsave(&ihost->scic_lock, flags);
idev = isci_get_device(dev->lldd_dev);
spin_unlock_irqrestore(&ihost->scic_lock, flags);
if (!idev) {
ret = TMF_RESP_FUNC_COMPLETE;
goto out;
}
ret = isci_reset_device(ihost, dev, idev);
out:
isci_put_device(idev);
return ret;
}
