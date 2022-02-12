void scsi_eh_wakeup(struct Scsi_Host *shost)
{
if (shost->host_busy == shost->host_failed) {
trace_scsi_eh_wakeup(shost);
wake_up_process(shost->ehandler);
SCSI_LOG_ERROR_RECOVERY(5,
printk("Waking error handler thread\n"));
}
}
void scsi_schedule_eh(struct Scsi_Host *shost)
{
unsigned long flags;
spin_lock_irqsave(shost->host_lock, flags);
if (scsi_host_set_state(shost, SHOST_RECOVERY) == 0 ||
scsi_host_set_state(shost, SHOST_CANCEL_RECOVERY) == 0) {
shost->host_eh_scheduled++;
scsi_eh_wakeup(shost);
}
spin_unlock_irqrestore(shost->host_lock, flags);
}
static int scsi_host_eh_past_deadline(struct Scsi_Host *shost)
{
if (!shost->last_reset || shost->eh_deadline == -1)
return 0;
if (time_before(jiffies, shost->last_reset + shost->eh_deadline) &&
shost->eh_deadline > -1)
return 0;
return 1;
}
void
scmd_eh_abort_handler(struct work_struct *work)
{
struct scsi_cmnd *scmd =
container_of(work, struct scsi_cmnd, abort_work.work);
struct scsi_device *sdev = scmd->device;
int rtn;
if (scsi_host_eh_past_deadline(sdev->host)) {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"scmd %p eh timeout, not aborting\n",
scmd));
} else {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"aborting command %p\n", scmd));
rtn = scsi_try_to_abort_cmd(sdev->host->hostt, scmd);
if (rtn == SUCCESS) {
scmd->result |= DID_TIME_OUT << 16;
if (scsi_host_eh_past_deadline(sdev->host)) {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"scmd %p eh timeout, "
"not retrying aborted "
"command\n", scmd));
} else if (!scsi_noretry_cmd(scmd) &&
(++scmd->retries <= scmd->allowed)) {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_WARNING, scmd,
"scmd %p retry "
"aborted command\n", scmd));
scsi_queue_insert(scmd, SCSI_MLQUEUE_EH_RETRY);
return;
} else {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_WARNING, scmd,
"scmd %p finish "
"aborted command\n", scmd));
scsi_finish_command(scmd);
return;
}
} else {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"scmd %p abort failed, rtn %d\n",
scmd, rtn));
}
}
if (!scsi_eh_scmd_add(scmd, 0)) {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_WARNING, scmd,
"scmd %p terminate "
"aborted command\n", scmd));
scmd->result |= DID_TIME_OUT << 16;
scsi_finish_command(scmd);
}
}
static int
scsi_abort_command(struct scsi_cmnd *scmd)
{
struct scsi_device *sdev = scmd->device;
struct Scsi_Host *shost = sdev->host;
unsigned long flags;
if (scmd->eh_eflags & SCSI_EH_ABORT_SCHEDULED) {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"scmd %p previous abort failed\n", scmd));
cancel_delayed_work(&scmd->abort_work);
return FAILED;
}
spin_lock_irqsave(shost->host_lock, flags);
if (scsi_host_in_recovery(shost)) {
spin_unlock_irqrestore(shost->host_lock, flags);
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"scmd %p not aborting, host in recovery\n",
scmd));
return FAILED;
}
if (shost->eh_deadline != -1 && !shost->last_reset)
shost->last_reset = jiffies;
spin_unlock_irqrestore(shost->host_lock, flags);
scmd->eh_eflags |= SCSI_EH_ABORT_SCHEDULED;
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"scmd %p abort scheduled\n", scmd));
queue_delayed_work(shost->tmf_work_q, &scmd->abort_work, HZ / 100);
return SUCCESS;
}
int scsi_eh_scmd_add(struct scsi_cmnd *scmd, int eh_flag)
{
struct Scsi_Host *shost = scmd->device->host;
unsigned long flags;
int ret = 0;
if (!shost->ehandler)
return 0;
spin_lock_irqsave(shost->host_lock, flags);
if (scsi_host_set_state(shost, SHOST_RECOVERY))
if (scsi_host_set_state(shost, SHOST_CANCEL_RECOVERY))
goto out_unlock;
if (shost->eh_deadline != -1 && !shost->last_reset)
shost->last_reset = jiffies;
ret = 1;
if (scmd->eh_eflags & SCSI_EH_ABORT_SCHEDULED)
eh_flag &= ~SCSI_EH_CANCEL_CMD;
scmd->eh_eflags |= eh_flag;
list_add_tail(&scmd->eh_entry, &shost->eh_cmd_q);
shost->host_failed++;
scsi_eh_wakeup(shost);
out_unlock:
spin_unlock_irqrestore(shost->host_lock, flags);
return ret;
}
enum blk_eh_timer_return scsi_times_out(struct request *req)
{
struct scsi_cmnd *scmd = req->special;
enum blk_eh_timer_return rtn = BLK_EH_NOT_HANDLED;
struct Scsi_Host *host = scmd->device->host;
trace_scsi_dispatch_cmd_timeout(scmd);
scsi_log_completion(scmd, TIMEOUT_ERROR);
if (host->eh_deadline != -1 && !host->last_reset)
host->last_reset = jiffies;
if (host->transportt->eh_timed_out)
rtn = host->transportt->eh_timed_out(scmd);
else if (host->hostt->eh_timed_out)
rtn = host->hostt->eh_timed_out(scmd);
if (rtn == BLK_EH_NOT_HANDLED && !host->hostt->no_async_abort)
if (scsi_abort_command(scmd) == SUCCESS)
return BLK_EH_NOT_HANDLED;
scmd->result |= DID_TIME_OUT << 16;
if (unlikely(rtn == BLK_EH_NOT_HANDLED &&
!scsi_eh_scmd_add(scmd, SCSI_EH_CANCEL_CMD)))
rtn = BLK_EH_HANDLED;
return rtn;
}
int scsi_block_when_processing_errors(struct scsi_device *sdev)
{
int online;
wait_event(sdev->host->host_wait, !scsi_host_in_recovery(sdev->host));
online = scsi_device_online(sdev);
SCSI_LOG_ERROR_RECOVERY(5, printk("%s: rtn: %d\n", __func__,
online));
return online;
}
static inline void scsi_eh_prt_fail_stats(struct Scsi_Host *shost,
struct list_head *work_q)
{
struct scsi_cmnd *scmd;
struct scsi_device *sdev;
int total_failures = 0;
int cmd_failed = 0;
int cmd_cancel = 0;
int devices_failed = 0;
shost_for_each_device(sdev, shost) {
list_for_each_entry(scmd, work_q, eh_entry) {
if (scmd->device == sdev) {
++total_failures;
if (scmd->eh_eflags & SCSI_EH_CANCEL_CMD)
++cmd_cancel;
else
++cmd_failed;
}
}
if (cmd_cancel || cmd_failed) {
SCSI_LOG_ERROR_RECOVERY(3,
sdev_printk(KERN_INFO, sdev,
"%s: cmds failed: %d, cancel: %d\n",
__func__, cmd_failed,
cmd_cancel));
cmd_cancel = 0;
cmd_failed = 0;
++devices_failed;
}
}
SCSI_LOG_ERROR_RECOVERY(2, printk("Total of %d commands on %d"
" devices require eh work\n",
total_failures, devices_failed));
}
static void scsi_report_lun_change(struct scsi_device *sdev)
{
sdev->sdev_target->expecting_lun_change = 1;
}
static void scsi_report_sense(struct scsi_device *sdev,
struct scsi_sense_hdr *sshdr)
{
enum scsi_device_event evt_type = SDEV_EVT_MAXBITS;
if (sshdr->sense_key == UNIT_ATTENTION) {
if (sshdr->asc == 0x3f && sshdr->ascq == 0x03) {
evt_type = SDEV_EVT_INQUIRY_CHANGE_REPORTED;
sdev_printk(KERN_WARNING, sdev,
"Inquiry data has changed");
} else if (sshdr->asc == 0x3f && sshdr->ascq == 0x0e) {
evt_type = SDEV_EVT_LUN_CHANGE_REPORTED;
scsi_report_lun_change(sdev);
sdev_printk(KERN_WARNING, sdev,
"Warning! Received an indication that the "
"LUN assignments on this target have "
"changed. The Linux SCSI layer does not "
"automatically remap LUN assignments.\n");
} else if (sshdr->asc == 0x3f)
sdev_printk(KERN_WARNING, sdev,
"Warning! Received an indication that the "
"operating parameters on this target have "
"changed. The Linux SCSI layer does not "
"automatically adjust these parameters.\n");
if (sshdr->asc == 0x38 && sshdr->ascq == 0x07) {
evt_type = SDEV_EVT_SOFT_THRESHOLD_REACHED_REPORTED;
sdev_printk(KERN_WARNING, sdev,
"Warning! Received an indication that the "
"LUN reached a thin provisioning soft "
"threshold.\n");
}
if (sshdr->asc == 0x2a && sshdr->ascq == 0x01) {
evt_type = SDEV_EVT_MODE_PARAMETER_CHANGE_REPORTED;
sdev_printk(KERN_WARNING, sdev,
"Mode parameters changed");
} else if (sshdr->asc == 0x2a && sshdr->ascq == 0x09) {
evt_type = SDEV_EVT_CAPACITY_CHANGE_REPORTED;
sdev_printk(KERN_WARNING, sdev,
"Capacity data has changed");
} else if (sshdr->asc == 0x2a)
sdev_printk(KERN_WARNING, sdev,
"Parameters changed");
}
if (evt_type != SDEV_EVT_MAXBITS) {
set_bit(evt_type, sdev->pending_events);
schedule_work(&sdev->event_work);
}
}
static int scsi_check_sense(struct scsi_cmnd *scmd)
{
struct scsi_device *sdev = scmd->device;
struct scsi_sense_hdr sshdr;
if (! scsi_command_normalize_sense(scmd, &sshdr))
return FAILED;
if (scmd->cmnd[0] == TEST_UNIT_READY && scmd->scsi_done != scsi_eh_done)
return SUCCESS;
scsi_report_sense(sdev, &sshdr);
if (scsi_sense_is_deferred(&sshdr))
return NEEDS_RETRY;
if (sdev->scsi_dh_data && sdev->scsi_dh_data->scsi_dh &&
sdev->scsi_dh_data->scsi_dh->check_sense) {
int rc;
rc = sdev->scsi_dh_data->scsi_dh->check_sense(sdev, &sshdr);
if (rc != SCSI_RETURN_NOT_HANDLED)
return rc;
}
if (sshdr.response_code == 0x70) {
if (scmd->sense_buffer[2] & 0xe0)
return SUCCESS;
} else {
if ((sshdr.additional_length > 3) &&
(scmd->sense_buffer[8] == 0x4) &&
(scmd->sense_buffer[11] & 0xe0))
return SUCCESS;
}
switch (sshdr.sense_key) {
case NO_SENSE:
return SUCCESS;
case RECOVERED_ERROR:
return SUCCESS;
case ABORTED_COMMAND:
if (sshdr.asc == 0x10)
return SUCCESS;
return NEEDS_RETRY;
case NOT_READY:
case UNIT_ATTENTION:
if (scmd->device->expecting_cc_ua) {
if (sshdr.asc != 0x28 || sshdr.ascq != 0x00) {
scmd->device->expecting_cc_ua = 0;
return NEEDS_RETRY;
}
}
if (scmd->device->sdev_target->expecting_lun_change &&
sshdr.asc == 0x3f && sshdr.ascq == 0x0e)
return NEEDS_RETRY;
if ((sshdr.asc == 0x04) && (sshdr.ascq == 0x01))
return NEEDS_RETRY;
if (scmd->device->allow_restart &&
(sshdr.asc == 0x04) && (sshdr.ascq == 0x02))
return FAILED;
return SUCCESS;
case DATA_PROTECT:
if (sshdr.asc == 0x27 && sshdr.ascq == 0x07) {
set_host_byte(scmd, DID_ALLOC_FAILURE);
return SUCCESS;
}
case COPY_ABORTED:
case VOLUME_OVERFLOW:
case MISCOMPARE:
case BLANK_CHECK:
set_host_byte(scmd, DID_TARGET_FAILURE);
return SUCCESS;
case MEDIUM_ERROR:
if (sshdr.asc == 0x11 ||
sshdr.asc == 0x13 ||
sshdr.asc == 0x14) {
set_host_byte(scmd, DID_MEDIUM_ERROR);
return SUCCESS;
}
return NEEDS_RETRY;
case HARDWARE_ERROR:
if (scmd->device->retry_hwerror)
return ADD_TO_MLQUEUE;
else
set_host_byte(scmd, DID_TARGET_FAILURE);
case ILLEGAL_REQUEST:
if (sshdr.asc == 0x20 ||
sshdr.asc == 0x21 ||
sshdr.asc == 0x24 ||
sshdr.asc == 0x26) {
set_host_byte(scmd, DID_TARGET_FAILURE);
}
return SUCCESS;
default:
return SUCCESS;
}
}
static void scsi_handle_queue_ramp_up(struct scsi_device *sdev)
{
struct scsi_host_template *sht = sdev->host->hostt;
struct scsi_device *tmp_sdev;
if (!sht->change_queue_depth ||
sdev->queue_depth >= sdev->max_queue_depth)
return;
if (time_before(jiffies,
sdev->last_queue_ramp_up + sdev->queue_ramp_up_period))
return;
if (time_before(jiffies,
sdev->last_queue_full_time + sdev->queue_ramp_up_period))
return;
shost_for_each_device(tmp_sdev, sdev->host) {
if (tmp_sdev->channel != sdev->channel ||
tmp_sdev->id != sdev->id ||
tmp_sdev->queue_depth == sdev->max_queue_depth)
continue;
sht->change_queue_depth(tmp_sdev, tmp_sdev->queue_depth + 1,
SCSI_QDEPTH_RAMP_UP);
sdev->last_queue_ramp_up = jiffies;
}
}
static void scsi_handle_queue_full(struct scsi_device *sdev)
{
struct scsi_host_template *sht = sdev->host->hostt;
struct scsi_device *tmp_sdev;
if (!sht->change_queue_depth)
return;
shost_for_each_device(tmp_sdev, sdev->host) {
if (tmp_sdev->channel != sdev->channel ||
tmp_sdev->id != sdev->id)
continue;
sht->change_queue_depth(tmp_sdev, tmp_sdev->queue_depth - 1,
SCSI_QDEPTH_QFULL);
}
}
static int scsi_eh_completed_normally(struct scsi_cmnd *scmd)
{
if (host_byte(scmd->result) == DID_RESET) {
return scsi_check_sense(scmd);
}
if (host_byte(scmd->result) != DID_OK)
return FAILED;
if (msg_byte(scmd->result) != COMMAND_COMPLETE)
return FAILED;
switch (status_byte(scmd->result)) {
case GOOD:
scsi_handle_queue_ramp_up(scmd->device);
case COMMAND_TERMINATED:
return SUCCESS;
case CHECK_CONDITION:
return scsi_check_sense(scmd);
case CONDITION_GOOD:
case INTERMEDIATE_GOOD:
case INTERMEDIATE_C_GOOD:
return SUCCESS;
case RESERVATION_CONFLICT:
if (scmd->cmnd[0] == TEST_UNIT_READY)
return SUCCESS;
return FAILED;
case QUEUE_FULL:
scsi_handle_queue_full(scmd->device);
case BUSY:
return NEEDS_RETRY;
default:
return FAILED;
}
return FAILED;
}
static void scsi_eh_done(struct scsi_cmnd *scmd)
{
struct completion *eh_action;
SCSI_LOG_ERROR_RECOVERY(3,
printk("%s scmd: %p result: %x\n",
__func__, scmd, scmd->result));
eh_action = scmd->device->host->eh_action;
if (eh_action)
complete(eh_action);
}
static int scsi_try_host_reset(struct scsi_cmnd *scmd)
{
unsigned long flags;
int rtn;
struct Scsi_Host *host = scmd->device->host;
struct scsi_host_template *hostt = host->hostt;
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: Snd Host RST\n",
__func__));
if (!hostt->eh_host_reset_handler)
return FAILED;
rtn = hostt->eh_host_reset_handler(scmd);
if (rtn == SUCCESS) {
if (!hostt->skip_settle_delay)
ssleep(HOST_RESET_SETTLE_TIME);
spin_lock_irqsave(host->host_lock, flags);
scsi_report_bus_reset(host, scmd_channel(scmd));
spin_unlock_irqrestore(host->host_lock, flags);
}
return rtn;
}
static int scsi_try_bus_reset(struct scsi_cmnd *scmd)
{
unsigned long flags;
int rtn;
struct Scsi_Host *host = scmd->device->host;
struct scsi_host_template *hostt = host->hostt;
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: Snd Bus RST\n",
__func__));
if (!hostt->eh_bus_reset_handler)
return FAILED;
rtn = hostt->eh_bus_reset_handler(scmd);
if (rtn == SUCCESS) {
if (!hostt->skip_settle_delay)
ssleep(BUS_RESET_SETTLE_TIME);
spin_lock_irqsave(host->host_lock, flags);
scsi_report_bus_reset(host, scmd_channel(scmd));
spin_unlock_irqrestore(host->host_lock, flags);
}
return rtn;
}
static void __scsi_report_device_reset(struct scsi_device *sdev, void *data)
{
sdev->was_reset = 1;
sdev->expecting_cc_ua = 1;
}
static int scsi_try_target_reset(struct scsi_cmnd *scmd)
{
unsigned long flags;
int rtn;
struct Scsi_Host *host = scmd->device->host;
struct scsi_host_template *hostt = host->hostt;
if (!hostt->eh_target_reset_handler)
return FAILED;
rtn = hostt->eh_target_reset_handler(scmd);
if (rtn == SUCCESS) {
spin_lock_irqsave(host->host_lock, flags);
__starget_for_each_device(scsi_target(scmd->device), NULL,
__scsi_report_device_reset);
spin_unlock_irqrestore(host->host_lock, flags);
}
return rtn;
}
static int scsi_try_bus_device_reset(struct scsi_cmnd *scmd)
{
int rtn;
struct scsi_host_template *hostt = scmd->device->host->hostt;
if (!hostt->eh_device_reset_handler)
return FAILED;
rtn = hostt->eh_device_reset_handler(scmd);
if (rtn == SUCCESS)
__scsi_report_device_reset(scmd->device, NULL);
return rtn;
}
static int scsi_try_to_abort_cmd(struct scsi_host_template *hostt, struct scsi_cmnd *scmd)
{
if (!hostt->eh_abort_handler)
return FAILED;
return hostt->eh_abort_handler(scmd);
}
static void scsi_abort_eh_cmnd(struct scsi_cmnd *scmd)
{
if (scsi_try_to_abort_cmd(scmd->device->host->hostt, scmd) != SUCCESS)
if (scsi_try_bus_device_reset(scmd) != SUCCESS)
if (scsi_try_target_reset(scmd) != SUCCESS)
if (scsi_try_bus_reset(scmd) != SUCCESS)
scsi_try_host_reset(scmd);
}
void scsi_eh_prep_cmnd(struct scsi_cmnd *scmd, struct scsi_eh_save *ses,
unsigned char *cmnd, int cmnd_size, unsigned sense_bytes)
{
struct scsi_device *sdev = scmd->device;
ses->cmd_len = scmd->cmd_len;
ses->cmnd = scmd->cmnd;
ses->data_direction = scmd->sc_data_direction;
ses->sdb = scmd->sdb;
ses->next_rq = scmd->request->next_rq;
ses->result = scmd->result;
ses->underflow = scmd->underflow;
ses->prot_op = scmd->prot_op;
scmd->prot_op = SCSI_PROT_NORMAL;
scmd->cmnd = ses->eh_cmnd;
memset(scmd->cmnd, 0, BLK_MAX_CDB);
memset(&scmd->sdb, 0, sizeof(scmd->sdb));
scmd->request->next_rq = NULL;
if (sense_bytes) {
scmd->sdb.length = min_t(unsigned, SCSI_SENSE_BUFFERSIZE,
sense_bytes);
sg_init_one(&ses->sense_sgl, scmd->sense_buffer,
scmd->sdb.length);
scmd->sdb.table.sgl = &ses->sense_sgl;
scmd->sc_data_direction = DMA_FROM_DEVICE;
scmd->sdb.table.nents = 1;
scmd->cmnd[0] = REQUEST_SENSE;
scmd->cmnd[4] = scmd->sdb.length;
scmd->cmd_len = COMMAND_SIZE(scmd->cmnd[0]);
} else {
scmd->sc_data_direction = DMA_NONE;
if (cmnd) {
BUG_ON(cmnd_size > BLK_MAX_CDB);
memcpy(scmd->cmnd, cmnd, cmnd_size);
scmd->cmd_len = COMMAND_SIZE(scmd->cmnd[0]);
}
}
scmd->underflow = 0;
if (sdev->scsi_level <= SCSI_2 && sdev->scsi_level != SCSI_UNKNOWN)
scmd->cmnd[1] = (scmd->cmnd[1] & 0x1f) |
(sdev->lun << 5 & 0xe0);
memset(scmd->sense_buffer, 0, SCSI_SENSE_BUFFERSIZE);
}
void scsi_eh_restore_cmnd(struct scsi_cmnd* scmd, struct scsi_eh_save *ses)
{
scmd->cmd_len = ses->cmd_len;
scmd->cmnd = ses->cmnd;
scmd->sc_data_direction = ses->data_direction;
scmd->sdb = ses->sdb;
scmd->request->next_rq = ses->next_rq;
scmd->result = ses->result;
scmd->underflow = ses->underflow;
scmd->prot_op = ses->prot_op;
}
static int scsi_send_eh_cmnd(struct scsi_cmnd *scmd, unsigned char *cmnd,
int cmnd_size, int timeout, unsigned sense_bytes)
{
struct scsi_device *sdev = scmd->device;
struct Scsi_Host *shost = sdev->host;
DECLARE_COMPLETION_ONSTACK(done);
unsigned long timeleft = timeout;
struct scsi_eh_save ses;
const unsigned long stall_for = msecs_to_jiffies(100);
int rtn;
retry:
scsi_eh_prep_cmnd(scmd, &ses, cmnd, cmnd_size, sense_bytes);
shost->eh_action = &done;
scsi_log_send(scmd);
scmd->scsi_done = scsi_eh_done;
rtn = shost->hostt->queuecommand(shost, scmd);
if (rtn) {
if (timeleft > stall_for) {
scsi_eh_restore_cmnd(scmd, &ses);
timeleft -= stall_for;
msleep(jiffies_to_msecs(stall_for));
goto retry;
}
timeleft = 0;
rtn = NEEDS_RETRY;
} else {
timeleft = wait_for_completion_timeout(&done, timeout);
}
shost->eh_action = NULL;
scsi_log_completion(scmd, rtn);
SCSI_LOG_ERROR_RECOVERY(3,
printk("%s: scmd: %p, timeleft: %ld\n",
__func__, scmd, timeleft));
if (timeleft) {
rtn = scsi_eh_completed_normally(scmd);
SCSI_LOG_ERROR_RECOVERY(3,
printk("%s: scsi_eh_completed_normally %x\n",
__func__, rtn));
switch (rtn) {
case SUCCESS:
case NEEDS_RETRY:
case FAILED:
break;
case ADD_TO_MLQUEUE:
rtn = NEEDS_RETRY;
break;
default:
rtn = FAILED;
break;
}
} else if (!rtn) {
scsi_abort_eh_cmnd(scmd);
rtn = FAILED;
}
scsi_eh_restore_cmnd(scmd, &ses);
return rtn;
}
static int scsi_request_sense(struct scsi_cmnd *scmd)
{
return scsi_send_eh_cmnd(scmd, NULL, 0, scmd->device->eh_timeout, ~0);
}
static int scsi_eh_action(struct scsi_cmnd *scmd, int rtn)
{
if (scmd->request->cmd_type != REQ_TYPE_BLOCK_PC) {
struct scsi_driver *sdrv = scsi_cmd_to_driver(scmd);
if (sdrv->eh_action)
rtn = sdrv->eh_action(scmd, rtn);
}
return rtn;
}
void scsi_eh_finish_cmd(struct scsi_cmnd *scmd, struct list_head *done_q)
{
scmd->device->host->host_failed--;
scmd->eh_eflags = 0;
list_move_tail(&scmd->eh_entry, done_q);
}
int scsi_eh_get_sense(struct list_head *work_q,
struct list_head *done_q)
{
struct scsi_cmnd *scmd, *next;
struct Scsi_Host *shost;
int rtn;
list_for_each_entry_safe(scmd, next, work_q, eh_entry) {
if ((scmd->eh_eflags & SCSI_EH_CANCEL_CMD) ||
SCSI_SENSE_VALID(scmd))
continue;
shost = scmd->device->host;
if (scsi_host_eh_past_deadline(shost)) {
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost,
"skip %s, past eh deadline\n",
__func__));
break;
}
SCSI_LOG_ERROR_RECOVERY(2, scmd_printk(KERN_INFO, scmd,
"%s: requesting sense\n",
current->comm));
rtn = scsi_request_sense(scmd);
if (rtn != SUCCESS)
continue;
SCSI_LOG_ERROR_RECOVERY(3, printk("sense requested for %p"
" result %x\n", scmd,
scmd->result));
SCSI_LOG_ERROR_RECOVERY(3, scsi_print_sense("bh", scmd));
rtn = scsi_decide_disposition(scmd);
if (rtn == SUCCESS)
scmd->retries = scmd->allowed;
else if (rtn != NEEDS_RETRY)
continue;
scsi_eh_finish_cmd(scmd, done_q);
}
return list_empty(work_q);
}
static int scsi_eh_tur(struct scsi_cmnd *scmd)
{
static unsigned char tur_command[6] = {TEST_UNIT_READY, 0, 0, 0, 0, 0};
int retry_cnt = 1, rtn;
retry_tur:
rtn = scsi_send_eh_cmnd(scmd, tur_command, 6,
scmd->device->eh_timeout, 0);
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: scmd %p rtn %x\n",
__func__, scmd, rtn));
switch (rtn) {
case NEEDS_RETRY:
if (retry_cnt--)
goto retry_tur;
case SUCCESS:
return 0;
default:
return 1;
}
}
static int scsi_eh_test_devices(struct list_head *cmd_list,
struct list_head *work_q,
struct list_head *done_q, int try_stu)
{
struct scsi_cmnd *scmd, *next;
struct scsi_device *sdev;
int finish_cmds;
while (!list_empty(cmd_list)) {
scmd = list_entry(cmd_list->next, struct scsi_cmnd, eh_entry);
sdev = scmd->device;
if (!try_stu) {
if (scsi_host_eh_past_deadline(sdev->host)) {
list_splice_init(cmd_list, work_q);
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, sdev->host,
"skip %s, past eh deadline",
__func__));
break;
}
}
finish_cmds = !scsi_device_online(scmd->device) ||
(try_stu && !scsi_eh_try_stu(scmd) &&
!scsi_eh_tur(scmd)) ||
!scsi_eh_tur(scmd);
list_for_each_entry_safe(scmd, next, cmd_list, eh_entry)
if (scmd->device == sdev) {
if (finish_cmds &&
(try_stu ||
scsi_eh_action(scmd, SUCCESS) == SUCCESS))
scsi_eh_finish_cmd(scmd, done_q);
else
list_move_tail(&scmd->eh_entry, work_q);
}
}
return list_empty(work_q);
}
static int scsi_eh_abort_cmds(struct list_head *work_q,
struct list_head *done_q)
{
struct scsi_cmnd *scmd, *next;
LIST_HEAD(check_list);
int rtn;
struct Scsi_Host *shost;
list_for_each_entry_safe(scmd, next, work_q, eh_entry) {
if (!(scmd->eh_eflags & SCSI_EH_CANCEL_CMD))
continue;
shost = scmd->device->host;
if (scsi_host_eh_past_deadline(shost)) {
list_splice_init(&check_list, work_q);
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost,
"skip %s, past eh deadline\n",
__func__));
return list_empty(work_q);
}
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: aborting cmd:"
"0x%p\n", current->comm,
scmd));
rtn = scsi_try_to_abort_cmd(shost->hostt, scmd);
if (rtn == FAILED) {
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: aborting"
" cmd failed:"
"0x%p\n",
current->comm,
scmd));
list_splice_init(&check_list, work_q);
return list_empty(work_q);
}
scmd->eh_eflags &= ~SCSI_EH_CANCEL_CMD;
if (rtn == FAST_IO_FAIL)
scsi_eh_finish_cmd(scmd, done_q);
else
list_move_tail(&scmd->eh_entry, &check_list);
}
return scsi_eh_test_devices(&check_list, work_q, done_q, 0);
}
static int scsi_eh_try_stu(struct scsi_cmnd *scmd)
{
static unsigned char stu_command[6] = {START_STOP, 0, 0, 0, 1, 0};
if (scmd->device->allow_restart) {
int i, rtn = NEEDS_RETRY;
for (i = 0; rtn == NEEDS_RETRY && i < 2; i++)
rtn = scsi_send_eh_cmnd(scmd, stu_command, 6, scmd->device->request_queue->rq_timeout, 0);
if (rtn == SUCCESS)
return 0;
}
return 1;
}
static int scsi_eh_stu(struct Scsi_Host *shost,
struct list_head *work_q,
struct list_head *done_q)
{
struct scsi_cmnd *scmd, *stu_scmd, *next;
struct scsi_device *sdev;
shost_for_each_device(sdev, shost) {
if (scsi_host_eh_past_deadline(shost)) {
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost,
"skip %s, past eh deadline\n",
__func__));
break;
}
stu_scmd = NULL;
list_for_each_entry(scmd, work_q, eh_entry)
if (scmd->device == sdev && SCSI_SENSE_VALID(scmd) &&
scsi_check_sense(scmd) == FAILED ) {
stu_scmd = scmd;
break;
}
if (!stu_scmd)
continue;
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: Sending START_UNIT to sdev:"
" 0x%p\n", current->comm, sdev));
if (!scsi_eh_try_stu(stu_scmd)) {
if (!scsi_device_online(sdev) ||
!scsi_eh_tur(stu_scmd)) {
list_for_each_entry_safe(scmd, next,
work_q, eh_entry) {
if (scmd->device == sdev &&
scsi_eh_action(scmd, SUCCESS) == SUCCESS)
scsi_eh_finish_cmd(scmd, done_q);
}
}
} else {
SCSI_LOG_ERROR_RECOVERY(3,
printk("%s: START_UNIT failed to sdev:"
" 0x%p\n", current->comm, sdev));
}
}
return list_empty(work_q);
}
static int scsi_eh_bus_device_reset(struct Scsi_Host *shost,
struct list_head *work_q,
struct list_head *done_q)
{
struct scsi_cmnd *scmd, *bdr_scmd, *next;
struct scsi_device *sdev;
int rtn;
shost_for_each_device(sdev, shost) {
if (scsi_host_eh_past_deadline(shost)) {
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost,
"skip %s, past eh deadline\n",
__func__));
break;
}
bdr_scmd = NULL;
list_for_each_entry(scmd, work_q, eh_entry)
if (scmd->device == sdev) {
bdr_scmd = scmd;
break;
}
if (!bdr_scmd)
continue;
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: Sending BDR sdev:"
" 0x%p\n", current->comm,
sdev));
rtn = scsi_try_bus_device_reset(bdr_scmd);
if (rtn == SUCCESS || rtn == FAST_IO_FAIL) {
if (!scsi_device_online(sdev) ||
rtn == FAST_IO_FAIL ||
!scsi_eh_tur(bdr_scmd)) {
list_for_each_entry_safe(scmd, next,
work_q, eh_entry) {
if (scmd->device == sdev &&
scsi_eh_action(scmd, rtn) != FAILED)
scsi_eh_finish_cmd(scmd,
done_q);
}
}
} else {
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: BDR"
" failed sdev:"
"0x%p\n",
current->comm,
sdev));
}
}
return list_empty(work_q);
}
static int scsi_eh_target_reset(struct Scsi_Host *shost,
struct list_head *work_q,
struct list_head *done_q)
{
LIST_HEAD(tmp_list);
LIST_HEAD(check_list);
list_splice_init(work_q, &tmp_list);
while (!list_empty(&tmp_list)) {
struct scsi_cmnd *next, *scmd;
int rtn;
unsigned int id;
if (scsi_host_eh_past_deadline(shost)) {
list_splice_init(&check_list, work_q);
list_splice_init(&tmp_list, work_q);
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost,
"skip %s, past eh deadline\n",
__func__));
return list_empty(work_q);
}
scmd = list_entry(tmp_list.next, struct scsi_cmnd, eh_entry);
id = scmd_id(scmd);
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: Sending target reset "
"to target %d\n",
current->comm, id));
rtn = scsi_try_target_reset(scmd);
if (rtn != SUCCESS && rtn != FAST_IO_FAIL)
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: Target reset"
" failed target: "
"%d\n",
current->comm, id));
list_for_each_entry_safe(scmd, next, &tmp_list, eh_entry) {
if (scmd_id(scmd) != id)
continue;
if (rtn == SUCCESS)
list_move_tail(&scmd->eh_entry, &check_list);
else if (rtn == FAST_IO_FAIL)
scsi_eh_finish_cmd(scmd, done_q);
else
list_move(&scmd->eh_entry, work_q);
}
}
return scsi_eh_test_devices(&check_list, work_q, done_q, 0);
}
static int scsi_eh_bus_reset(struct Scsi_Host *shost,
struct list_head *work_q,
struct list_head *done_q)
{
struct scsi_cmnd *scmd, *chan_scmd, *next;
LIST_HEAD(check_list);
unsigned int channel;
int rtn;
for (channel = 0; channel <= shost->max_channel; channel++) {
if (scsi_host_eh_past_deadline(shost)) {
list_splice_init(&check_list, work_q);
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost,
"skip %s, past eh deadline\n",
__func__));
return list_empty(work_q);
}
chan_scmd = NULL;
list_for_each_entry(scmd, work_q, eh_entry) {
if (channel == scmd_channel(scmd)) {
chan_scmd = scmd;
break;
}
}
if (!chan_scmd)
continue;
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: Sending BRST chan:"
" %d\n", current->comm,
channel));
rtn = scsi_try_bus_reset(chan_scmd);
if (rtn == SUCCESS || rtn == FAST_IO_FAIL) {
list_for_each_entry_safe(scmd, next, work_q, eh_entry) {
if (channel == scmd_channel(scmd)) {
if (rtn == FAST_IO_FAIL)
scsi_eh_finish_cmd(scmd,
done_q);
else
list_move_tail(&scmd->eh_entry,
&check_list);
}
}
} else {
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: BRST"
" failed chan: %d\n",
current->comm,
channel));
}
}
return scsi_eh_test_devices(&check_list, work_q, done_q, 0);
}
static int scsi_eh_host_reset(struct list_head *work_q,
struct list_head *done_q)
{
struct scsi_cmnd *scmd, *next;
LIST_HEAD(check_list);
int rtn;
if (!list_empty(work_q)) {
scmd = list_entry(work_q->next,
struct scsi_cmnd, eh_entry);
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: Sending HRST\n"
, current->comm));
rtn = scsi_try_host_reset(scmd);
if (rtn == SUCCESS) {
list_splice_init(work_q, &check_list);
} else if (rtn == FAST_IO_FAIL) {
list_for_each_entry_safe(scmd, next, work_q, eh_entry) {
scsi_eh_finish_cmd(scmd, done_q);
}
} else {
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: HRST"
" failed\n",
current->comm));
}
}
return scsi_eh_test_devices(&check_list, work_q, done_q, 1);
}
static void scsi_eh_offline_sdevs(struct list_head *work_q,
struct list_head *done_q)
{
struct scsi_cmnd *scmd, *next;
list_for_each_entry_safe(scmd, next, work_q, eh_entry) {
sdev_printk(KERN_INFO, scmd->device, "Device offlined - "
"not ready after error recovery\n");
scsi_device_set_state(scmd->device, SDEV_OFFLINE);
if (scmd->eh_eflags & SCSI_EH_CANCEL_CMD) {
}
scsi_eh_finish_cmd(scmd, done_q);
}
return;
}
int scsi_noretry_cmd(struct scsi_cmnd *scmd)
{
switch (host_byte(scmd->result)) {
case DID_OK:
break;
case DID_TIME_OUT:
goto check_type;
case DID_BUS_BUSY:
return (scmd->request->cmd_flags & REQ_FAILFAST_TRANSPORT);
case DID_PARITY:
return (scmd->request->cmd_flags & REQ_FAILFAST_DEV);
case DID_ERROR:
if (msg_byte(scmd->result) == COMMAND_COMPLETE &&
status_byte(scmd->result) == RESERVATION_CONFLICT)
return 0;
case DID_SOFT_ERROR:
return (scmd->request->cmd_flags & REQ_FAILFAST_DRIVER);
}
if (status_byte(scmd->result) != CHECK_CONDITION)
return 0;
check_type:
if (scmd->request->cmd_flags & REQ_FAILFAST_DEV ||
scmd->request->cmd_type == REQ_TYPE_BLOCK_PC)
return 1;
else
return 0;
}
int scsi_decide_disposition(struct scsi_cmnd *scmd)
{
int rtn;
if (!scsi_device_online(scmd->device)) {
SCSI_LOG_ERROR_RECOVERY(5, printk("%s: device offline - report"
" as SUCCESS\n",
__func__));
return SUCCESS;
}
switch (host_byte(scmd->result)) {
case DID_PASSTHROUGH:
scmd->result &= 0xff00ffff;
return SUCCESS;
case DID_OK:
break;
case DID_ABORT:
if (scmd->eh_eflags & SCSI_EH_ABORT_SCHEDULED) {
scmd->result |= DID_TIME_OUT << 16;
return SUCCESS;
}
case DID_NO_CONNECT:
case DID_BAD_TARGET:
return SUCCESS;
case DID_SOFT_ERROR:
goto maybe_retry;
case DID_IMM_RETRY:
return NEEDS_RETRY;
case DID_REQUEUE:
return ADD_TO_MLQUEUE;
case DID_TRANSPORT_DISRUPTED:
goto maybe_retry;
case DID_TRANSPORT_FAILFAST:
return SUCCESS;
case DID_ERROR:
if (msg_byte(scmd->result) == COMMAND_COMPLETE &&
status_byte(scmd->result) == RESERVATION_CONFLICT)
break;
case DID_BUS_BUSY:
case DID_PARITY:
goto maybe_retry;
case DID_TIME_OUT:
if ((scmd->cmnd[0] == TEST_UNIT_READY ||
scmd->cmnd[0] == INQUIRY)) {
return SUCCESS;
} else {
return FAILED;
}
case DID_RESET:
return SUCCESS;
default:
return FAILED;
}
if (msg_byte(scmd->result) != COMMAND_COMPLETE)
return FAILED;
switch (status_byte(scmd->result)) {
case QUEUE_FULL:
scsi_handle_queue_full(scmd->device);
case BUSY:
return ADD_TO_MLQUEUE;
case GOOD:
if (scmd->cmnd[0] == REPORT_LUNS)
scmd->device->sdev_target->expecting_lun_change = 0;
scsi_handle_queue_ramp_up(scmd->device);
case COMMAND_TERMINATED:
return SUCCESS;
case TASK_ABORTED:
goto maybe_retry;
case CHECK_CONDITION:
rtn = scsi_check_sense(scmd);
if (rtn == NEEDS_RETRY)
goto maybe_retry;
return rtn;
case CONDITION_GOOD:
case INTERMEDIATE_GOOD:
case INTERMEDIATE_C_GOOD:
case ACA_ACTIVE:
return SUCCESS;
case RESERVATION_CONFLICT:
sdev_printk(KERN_INFO, scmd->device,
"reservation conflict\n");
set_host_byte(scmd, DID_NEXUS_FAILURE);
return SUCCESS;
default:
return FAILED;
}
return FAILED;
maybe_retry:
if ((++scmd->retries) <= scmd->allowed
&& !scsi_noretry_cmd(scmd)) {
return NEEDS_RETRY;
} else {
return SUCCESS;
}
}
static void eh_lock_door_done(struct request *req, int uptodate)
{
__blk_put_request(req->q, req);
}
static void scsi_eh_lock_door(struct scsi_device *sdev)
{
struct request *req;
req = blk_get_request(sdev->request_queue, READ, GFP_KERNEL);
req->cmd[0] = ALLOW_MEDIUM_REMOVAL;
req->cmd[1] = 0;
req->cmd[2] = 0;
req->cmd[3] = 0;
req->cmd[4] = SCSI_REMOVAL_PREVENT;
req->cmd[5] = 0;
req->cmd_len = COMMAND_SIZE(req->cmd[0]);
req->cmd_type = REQ_TYPE_BLOCK_PC;
req->cmd_flags |= REQ_QUIET;
req->timeout = 10 * HZ;
req->retries = 5;
blk_execute_rq_nowait(req->q, NULL, req, 1, eh_lock_door_done);
}
static void scsi_restart_operations(struct Scsi_Host *shost)
{
struct scsi_device *sdev;
unsigned long flags;
shost_for_each_device(sdev, shost) {
if (scsi_device_online(sdev) && sdev->locked)
scsi_eh_lock_door(sdev);
}
SCSI_LOG_ERROR_RECOVERY(3,
printk("scsi_eh_%d waking up host to restart\n",
shost->host_no));
spin_lock_irqsave(shost->host_lock, flags);
if (scsi_host_set_state(shost, SHOST_RUNNING))
if (scsi_host_set_state(shost, SHOST_CANCEL))
BUG_ON(scsi_host_set_state(shost, SHOST_DEL));
spin_unlock_irqrestore(shost->host_lock, flags);
wake_up(&shost->host_wait);
scsi_run_host_queues(shost);
spin_lock_irqsave(shost->host_lock, flags);
if (shost->host_eh_scheduled)
if (scsi_host_set_state(shost, SHOST_RECOVERY))
WARN_ON(scsi_host_set_state(shost, SHOST_CANCEL_RECOVERY));
spin_unlock_irqrestore(shost->host_lock, flags);
}
void scsi_eh_ready_devs(struct Scsi_Host *shost,
struct list_head *work_q,
struct list_head *done_q)
{
if (!scsi_eh_stu(shost, work_q, done_q))
if (!scsi_eh_bus_device_reset(shost, work_q, done_q))
if (!scsi_eh_target_reset(shost, work_q, done_q))
if (!scsi_eh_bus_reset(shost, work_q, done_q))
if (!scsi_eh_host_reset(work_q, done_q))
scsi_eh_offline_sdevs(work_q,
done_q);
}
void scsi_eh_flush_done_q(struct list_head *done_q)
{
struct scsi_cmnd *scmd, *next;
list_for_each_entry_safe(scmd, next, done_q, eh_entry) {
list_del_init(&scmd->eh_entry);
if (scsi_device_online(scmd->device) &&
!scsi_noretry_cmd(scmd) &&
(++scmd->retries <= scmd->allowed)) {
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: flush"
" retry cmd: %p\n",
current->comm,
scmd));
scsi_queue_insert(scmd, SCSI_MLQUEUE_EH_RETRY);
} else {
if (!scmd->result)
scmd->result |= (DRIVER_TIMEOUT << 24);
SCSI_LOG_ERROR_RECOVERY(3, printk("%s: flush finish"
" cmd: %p\n",
current->comm, scmd));
scsi_finish_command(scmd);
}
}
}
static void scsi_unjam_host(struct Scsi_Host *shost)
{
unsigned long flags;
LIST_HEAD(eh_work_q);
LIST_HEAD(eh_done_q);
spin_lock_irqsave(shost->host_lock, flags);
list_splice_init(&shost->eh_cmd_q, &eh_work_q);
spin_unlock_irqrestore(shost->host_lock, flags);
SCSI_LOG_ERROR_RECOVERY(1, scsi_eh_prt_fail_stats(shost, &eh_work_q));
if (!scsi_eh_get_sense(&eh_work_q, &eh_done_q))
if (!scsi_eh_abort_cmds(&eh_work_q, &eh_done_q))
scsi_eh_ready_devs(shost, &eh_work_q, &eh_done_q);
spin_lock_irqsave(shost->host_lock, flags);
if (shost->eh_deadline != -1)
shost->last_reset = 0;
spin_unlock_irqrestore(shost->host_lock, flags);
scsi_eh_flush_done_q(&eh_done_q);
}
int scsi_error_handler(void *data)
{
struct Scsi_Host *shost = data;
while (!kthread_should_stop()) {
set_current_state(TASK_INTERRUPTIBLE);
if ((shost->host_failed == 0 && shost->host_eh_scheduled == 0) ||
shost->host_failed != shost->host_busy) {
SCSI_LOG_ERROR_RECOVERY(1,
printk("scsi_eh_%d: sleeping\n",
shost->host_no));
schedule();
continue;
}
__set_current_state(TASK_RUNNING);
SCSI_LOG_ERROR_RECOVERY(1,
printk("scsi_eh_%d: waking up %d/%d/%d\n",
shost->host_no, shost->host_eh_scheduled,
shost->host_failed, shost->host_busy));
if (!shost->eh_noresume && scsi_autopm_get_host(shost) != 0) {
SCSI_LOG_ERROR_RECOVERY(1,
printk(KERN_ERR "Error handler scsi_eh_%d "
"unable to autoresume\n",
shost->host_no));
continue;
}
if (shost->transportt->eh_strategy_handler)
shost->transportt->eh_strategy_handler(shost);
else
scsi_unjam_host(shost);
scsi_restart_operations(shost);
if (!shost->eh_noresume)
scsi_autopm_put_host(shost);
}
__set_current_state(TASK_RUNNING);
SCSI_LOG_ERROR_RECOVERY(1,
printk("Error handler scsi_eh_%d exiting\n", shost->host_no));
shost->ehandler = NULL;
return 0;
}
void scsi_report_bus_reset(struct Scsi_Host *shost, int channel)
{
struct scsi_device *sdev;
__shost_for_each_device(sdev, shost) {
if (channel == sdev_channel(sdev))
__scsi_report_device_reset(sdev, NULL);
}
}
void scsi_report_device_reset(struct Scsi_Host *shost, int channel, int target)
{
struct scsi_device *sdev;
__shost_for_each_device(sdev, shost) {
if (channel == sdev_channel(sdev) &&
target == sdev_id(sdev))
__scsi_report_device_reset(sdev, NULL);
}
}
static void
scsi_reset_provider_done_command(struct scsi_cmnd *scmd)
{
}
int
scsi_reset_provider(struct scsi_device *dev, int flag)
{
struct scsi_cmnd *scmd;
struct Scsi_Host *shost = dev->host;
struct request req;
unsigned long flags;
int rtn;
if (scsi_autopm_get_host(shost) < 0)
return FAILED;
scmd = scsi_get_command(dev, GFP_KERNEL);
blk_rq_init(NULL, &req);
scmd->request = &req;
scmd->cmnd = req.cmd;
scmd->scsi_done = scsi_reset_provider_done_command;
memset(&scmd->sdb, 0, sizeof(scmd->sdb));
scmd->cmd_len = 0;
scmd->sc_data_direction = DMA_BIDIRECTIONAL;
spin_lock_irqsave(shost->host_lock, flags);
shost->tmf_in_progress = 1;
spin_unlock_irqrestore(shost->host_lock, flags);
switch (flag) {
case SCSI_TRY_RESET_DEVICE:
rtn = scsi_try_bus_device_reset(scmd);
if (rtn == SUCCESS)
break;
case SCSI_TRY_RESET_TARGET:
rtn = scsi_try_target_reset(scmd);
if (rtn == SUCCESS)
break;
case SCSI_TRY_RESET_BUS:
rtn = scsi_try_bus_reset(scmd);
if (rtn == SUCCESS)
break;
case SCSI_TRY_RESET_HOST:
rtn = scsi_try_host_reset(scmd);
break;
default:
rtn = FAILED;
}
spin_lock_irqsave(shost->host_lock, flags);
shost->tmf_in_progress = 0;
spin_unlock_irqrestore(shost->host_lock, flags);
SCSI_LOG_ERROR_RECOVERY(3,
printk("%s: waking up host to restart after TMF\n",
__func__));
wake_up(&shost->host_wait);
scsi_run_host_queues(shost);
scsi_next_command(scmd);
scsi_autopm_put_host(shost);
return rtn;
}
int scsi_normalize_sense(const u8 *sense_buffer, int sb_len,
struct scsi_sense_hdr *sshdr)
{
if (!sense_buffer || !sb_len)
return 0;
memset(sshdr, 0, sizeof(struct scsi_sense_hdr));
sshdr->response_code = (sense_buffer[0] & 0x7f);
if (!scsi_sense_valid(sshdr))
return 0;
if (sshdr->response_code >= 0x72) {
if (sb_len > 1)
sshdr->sense_key = (sense_buffer[1] & 0xf);
if (sb_len > 2)
sshdr->asc = sense_buffer[2];
if (sb_len > 3)
sshdr->ascq = sense_buffer[3];
if (sb_len > 7)
sshdr->additional_length = sense_buffer[7];
} else {
if (sb_len > 2)
sshdr->sense_key = (sense_buffer[2] & 0xf);
if (sb_len > 7) {
sb_len = (sb_len < (sense_buffer[7] + 8)) ?
sb_len : (sense_buffer[7] + 8);
if (sb_len > 12)
sshdr->asc = sense_buffer[12];
if (sb_len > 13)
sshdr->ascq = sense_buffer[13];
}
}
return 1;
}
int scsi_command_normalize_sense(struct scsi_cmnd *cmd,
struct scsi_sense_hdr *sshdr)
{
return scsi_normalize_sense(cmd->sense_buffer,
SCSI_SENSE_BUFFERSIZE, sshdr);
}
const u8 * scsi_sense_desc_find(const u8 * sense_buffer, int sb_len,
int desc_type)
{
int add_sen_len, add_len, desc_len, k;
const u8 * descp;
if ((sb_len < 8) || (0 == (add_sen_len = sense_buffer[7])))
return NULL;
if ((sense_buffer[0] < 0x72) || (sense_buffer[0] > 0x73))
return NULL;
add_sen_len = (add_sen_len < (sb_len - 8)) ?
add_sen_len : (sb_len - 8);
descp = &sense_buffer[8];
for (desc_len = 0, k = 0; k < add_sen_len; k += desc_len) {
descp += desc_len;
add_len = (k < (add_sen_len - 1)) ? descp[1]: -1;
desc_len = add_len + 2;
if (descp[0] == desc_type)
return descp;
if (add_len < 0)
break;
}
return NULL;
}
int scsi_get_sense_info_fld(const u8 * sense_buffer, int sb_len,
u64 * info_out)
{
int j;
const u8 * ucp;
u64 ull;
if (sb_len < 7)
return 0;
switch (sense_buffer[0] & 0x7f) {
case 0x70:
case 0x71:
if (sense_buffer[0] & 0x80) {
*info_out = (sense_buffer[3] << 24) +
(sense_buffer[4] << 16) +
(sense_buffer[5] << 8) + sense_buffer[6];
return 1;
} else
return 0;
case 0x72:
case 0x73:
ucp = scsi_sense_desc_find(sense_buffer, sb_len,
0 );
if (ucp && (0xa == ucp[1])) {
ull = 0;
for (j = 0; j < 8; ++j) {
if (j > 0)
ull <<= 8;
ull |= ucp[4 + j];
}
*info_out = ull;
return 1;
} else
return 0;
default:
return 0;
}
}
void scsi_build_sense_buffer(int desc, u8 *buf, u8 key, u8 asc, u8 ascq)
{
if (desc) {
buf[0] = 0x72;
buf[1] = key;
buf[2] = asc;
buf[3] = ascq;
buf[7] = 0;
} else {
buf[0] = 0x70;
buf[2] = key;
buf[7] = 0xa;
buf[12] = asc;
buf[13] = ascq;
}
}
