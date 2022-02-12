void scsi_eh_wakeup(struct Scsi_Host *shost)
{
if (atomic_read(&shost->host_busy) == shost->host_failed) {
trace_scsi_eh_wakeup(shost);
wake_up_process(shost->ehandler);
SCSI_LOG_ERROR_RECOVERY(5, shost_printk(KERN_INFO, shost,
"Waking error handler thread\n"));
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
"eh timeout, not aborting\n"));
} else {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"aborting command\n"));
rtn = scsi_try_to_abort_cmd(sdev->host->hostt, scmd);
if (rtn == SUCCESS) {
set_host_byte(scmd, DID_TIME_OUT);
if (scsi_host_eh_past_deadline(sdev->host)) {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"eh timeout, not retrying "
"aborted command\n"));
} else if (!scsi_noretry_cmd(scmd) &&
(++scmd->retries <= scmd->allowed)) {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_WARNING, scmd,
"retry aborted command\n"));
scsi_queue_insert(scmd, SCSI_MLQUEUE_EH_RETRY);
return;
} else {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_WARNING, scmd,
"finish aborted command\n"));
scsi_finish_command(scmd);
return;
}
} else {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"cmd abort %s\n",
(rtn == FAST_IO_FAIL) ?
"not send" : "failed"));
}
}
if (!scsi_eh_scmd_add(scmd, 0)) {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_WARNING, scmd,
"terminate aborted command\n"));
set_host_byte(scmd, DID_TIME_OUT);
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
scmd->eh_eflags &= ~SCSI_EH_ABORT_SCHEDULED;
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"previous abort failed\n"));
BUG_ON(delayed_work_pending(&scmd->abort_work));
return FAILED;
}
spin_lock_irqsave(shost->host_lock, flags);
if (scsi_host_in_recovery(shost)) {
spin_unlock_irqrestore(shost->host_lock, flags);
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"not aborting, host in recovery\n"));
return FAILED;
}
if (shost->eh_deadline != -1 && !shost->last_reset)
shost->last_reset = jiffies;
spin_unlock_irqrestore(shost->host_lock, flags);
scmd->eh_eflags |= SCSI_EH_ABORT_SCHEDULED;
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd, "abort scheduled\n"));
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
if (rtn == BLK_EH_NOT_HANDLED) {
if (!host->hostt->no_async_abort &&
scsi_abort_command(scmd) == SUCCESS)
return BLK_EH_NOT_HANDLED;
set_host_byte(scmd, DID_TIME_OUT);
if (!scsi_eh_scmd_add(scmd, SCSI_EH_CANCEL_CMD))
rtn = BLK_EH_HANDLED;
}
return rtn;
}
int scsi_block_when_processing_errors(struct scsi_device *sdev)
{
int online;
wait_event(sdev->host->host_wait, !scsi_host_in_recovery(sdev->host));
online = scsi_device_online(sdev);
SCSI_LOG_ERROR_RECOVERY(5, sdev_printk(KERN_INFO, sdev,
"%s: rtn: %d\n", __func__, online));
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
shost_printk(KERN_INFO, shost,
"%s: cmds failed: %d, cancel: %d\n",
__func__, cmd_failed,
cmd_cancel));
cmd_cancel = 0;
cmd_failed = 0;
++devices_failed;
}
}
SCSI_LOG_ERROR_RECOVERY(2, shost_printk(KERN_INFO, shost,
"Total of %d commands on %d"
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
} else if (sshdr->asc == 0x2a && sshdr->ascq == 0x06) {
evt_type = SDEV_EVT_ALUA_STATE_CHANGE_REPORTED;
sdev_printk(KERN_WARNING, sdev,
"Asymmetric access state changed");
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
scsi_report_sense(sdev, &sshdr);
if (scsi_sense_is_deferred(&sshdr))
return NEEDS_RETRY;
if (sdev->handler && sdev->handler->check_sense) {
int rc;
rc = sdev->handler->check_sense(sdev, &sshdr);
if (rc != SCSI_RETURN_NOT_HANDLED)
return rc;
}
if (scmd->cmnd[0] == TEST_UNIT_READY && scmd->scsi_done != scsi_eh_done)
return SUCCESS;
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
if (!sht->track_queue_depth ||
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
scsi_change_queue_depth(tmp_sdev, tmp_sdev->queue_depth + 1);
sdev->last_queue_ramp_up = jiffies;
}
}
static void scsi_handle_queue_full(struct scsi_device *sdev)
{
struct scsi_host_template *sht = sdev->host->hostt;
struct scsi_device *tmp_sdev;
if (!sht->track_queue_depth)
return;
shost_for_each_device(tmp_sdev, sdev->host) {
if (tmp_sdev->channel != sdev->channel ||
tmp_sdev->id != sdev->id)
continue;
scsi_track_queue_full(tmp_sdev, tmp_sdev->queue_depth - 1);
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
SCSI_LOG_ERROR_RECOVERY(3, scmd_printk(KERN_INFO, scmd,
"%s result: %x\n", __func__, scmd->result));
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
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, host, "Snd Host RST\n"));
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
SCSI_LOG_ERROR_RECOVERY(3, scmd_printk(KERN_INFO, scmd,
"%s: Snd Bus RST\n", __func__));
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
static int scsi_try_to_abort_cmd(struct scsi_host_template *hostt,
struct scsi_cmnd *scmd)
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
scmd->eh_eflags = 0;
scmd->cmnd = ses->eh_cmnd;
memset(scmd->cmnd, 0, BLK_MAX_CDB);
memset(&scmd->sdb, 0, sizeof(scmd->sdb));
scmd->request->next_rq = NULL;
scmd->result = 0;
if (sense_bytes) {
scmd->sdb.length = min_t(unsigned, SCSI_SENSE_BUFFERSIZE,
sense_bytes);
sg_init_one(&ses->sense_sgl, scmd->sense_buffer,
scmd->sdb.length);
scmd->sdb.table.sgl = &ses->sense_sgl;
scmd->sc_data_direction = DMA_FROM_DEVICE;
scmd->sdb.table.nents = scmd->sdb.table.orig_nents = 1;
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
rtn = FAILED;
} else {
timeleft = wait_for_completion_timeout(&done, timeout);
rtn = SUCCESS;
}
shost->eh_action = NULL;
scsi_log_completion(scmd, rtn);
SCSI_LOG_ERROR_RECOVERY(3, scmd_printk(KERN_INFO, scmd,
"%s timeleft: %ld\n",
__func__, timeleft));
if (timeleft) {
rtn = scsi_eh_completed_normally(scmd);
SCSI_LOG_ERROR_RECOVERY(3, scmd_printk(KERN_INFO, scmd,
"%s: scsi_eh_completed_normally %x\n", __func__, rtn));
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
} else if (rtn != FAILED) {
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
(scmd->eh_eflags & SCSI_EH_ABORT_SCHEDULED) ||
SCSI_SENSE_VALID(scmd))
continue;
shost = scmd->device->host;
if (scsi_host_eh_past_deadline(shost)) {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"%s: skip request sense, past eh deadline\n",
current->comm));
break;
}
if (status_byte(scmd->result) != CHECK_CONDITION)
continue;
SCSI_LOG_ERROR_RECOVERY(2, scmd_printk(KERN_INFO, scmd,
"%s: requesting sense\n",
current->comm));
rtn = scsi_request_sense(scmd);
if (rtn != SUCCESS)
continue;
SCSI_LOG_ERROR_RECOVERY(3, scmd_printk(KERN_INFO, scmd,
"sense requested, result %x\n", scmd->result));
SCSI_LOG_ERROR_RECOVERY(3, scsi_print_sense(scmd));
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
SCSI_LOG_ERROR_RECOVERY(3, scmd_printk(KERN_INFO, scmd,
"%s return: %x\n", __func__, rtn));
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
sdev_printk(KERN_INFO, sdev,
"%s: skip test device, past eh deadline",
current->comm));
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
scmd_printk(KERN_INFO, scmd,
"%s: skip aborting cmd, past eh deadline\n",
current->comm));
return list_empty(work_q);
}
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"%s: aborting cmd\n", current->comm));
rtn = scsi_try_to_abort_cmd(shost->hostt, scmd);
if (rtn == FAILED) {
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"%s: aborting cmd failed\n",
current->comm));
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
sdev_printk(KERN_INFO, sdev,
"%s: skip START_UNIT, past eh deadline\n",
current->comm));
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
SCSI_LOG_ERROR_RECOVERY(3,
sdev_printk(KERN_INFO, sdev,
"%s: Sending START_UNIT\n",
current->comm));
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
sdev_printk(KERN_INFO, sdev,
"%s: START_UNIT failed\n",
current->comm));
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
sdev_printk(KERN_INFO, sdev,
"%s: skip BDR, past eh deadline\n",
current->comm));
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
SCSI_LOG_ERROR_RECOVERY(3,
sdev_printk(KERN_INFO, sdev,
"%s: Sending BDR\n", current->comm));
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
SCSI_LOG_ERROR_RECOVERY(3,
sdev_printk(KERN_INFO, sdev,
"%s: BDR failed\n", current->comm));
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
"%s: Skip target reset, past eh deadline\n",
current->comm));
return list_empty(work_q);
}
scmd = list_entry(tmp_list.next, struct scsi_cmnd, eh_entry);
id = scmd_id(scmd);
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost,
"%s: Sending target reset to target %d\n",
current->comm, id));
rtn = scsi_try_target_reset(scmd);
if (rtn != SUCCESS && rtn != FAST_IO_FAIL)
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost,
"%s: Target reset failed"
" target: %d\n",
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
"%s: skip BRST, past eh deadline\n",
current->comm));
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
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost,
"%s: Sending BRST chan: %d\n",
current->comm, channel));
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
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost,
"%s: BRST failed chan: %d\n",
current->comm, channel));
}
}
return scsi_eh_test_devices(&check_list, work_q, done_q, 0);
}
static int scsi_eh_host_reset(struct Scsi_Host *shost,
struct list_head *work_q,
struct list_head *done_q)
{
struct scsi_cmnd *scmd, *next;
LIST_HEAD(check_list);
int rtn;
if (!list_empty(work_q)) {
scmd = list_entry(work_q->next,
struct scsi_cmnd, eh_entry);
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost,
"%s: Sending HRST\n",
current->comm));
rtn = scsi_try_host_reset(scmd);
if (rtn == SUCCESS) {
list_splice_init(work_q, &check_list);
} else if (rtn == FAST_IO_FAIL) {
list_for_each_entry_safe(scmd, next, work_q, eh_entry) {
scsi_eh_finish_cmd(scmd, done_q);
}
} else {
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost,
"%s: HRST failed\n",
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
SCSI_LOG_ERROR_RECOVERY(5, scmd_printk(KERN_INFO, scmd,
"%s: device offline - report as SUCCESS\n", __func__));
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
set_host_byte(scmd, DID_TIME_OUT);
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
if (IS_ERR(req))
return;
blk_rq_set_block_pc(req);
req->cmd[0] = ALLOW_MEDIUM_REMOVAL;
req->cmd[1] = 0;
req->cmd[2] = 0;
req->cmd[3] = 0;
req->cmd[4] = SCSI_REMOVAL_PREVENT;
req->cmd[5] = 0;
req->cmd_len = COMMAND_SIZE(req->cmd[0]);
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
if (scsi_device_online(sdev) && sdev->was_reset && sdev->locked) {
scsi_eh_lock_door(sdev);
sdev->was_reset = 0;
}
}
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost, "waking up host to restart\n"));
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
if (!scsi_eh_host_reset(shost, work_q, done_q))
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
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"%s: flush retry cmd\n",
current->comm));
scsi_queue_insert(scmd, SCSI_MLQUEUE_EH_RETRY);
} else {
if (!scmd->result)
scmd->result |= (DRIVER_TIMEOUT << 24);
SCSI_LOG_ERROR_RECOVERY(3,
scmd_printk(KERN_INFO, scmd,
"%s: flush finish cmd\n",
current->comm));
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
while (true) {
set_current_state(TASK_INTERRUPTIBLE);
if (kthread_should_stop())
break;
if ((shost->host_failed == 0 && shost->host_eh_scheduled == 0) ||
shost->host_failed != atomic_read(&shost->host_busy)) {
SCSI_LOG_ERROR_RECOVERY(1,
shost_printk(KERN_INFO, shost,
"scsi_eh_%d: sleeping\n",
shost->host_no));
schedule();
continue;
}
__set_current_state(TASK_RUNNING);
SCSI_LOG_ERROR_RECOVERY(1,
shost_printk(KERN_INFO, shost,
"scsi_eh_%d: waking up %d/%d/%d\n",
shost->host_no, shost->host_eh_scheduled,
shost->host_failed,
atomic_read(&shost->host_busy)));
if (!shost->eh_noresume && scsi_autopm_get_host(shost) != 0) {
SCSI_LOG_ERROR_RECOVERY(1,
shost_printk(KERN_ERR, shost,
"scsi_eh_%d: unable to autoresume\n",
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
shost_printk(KERN_INFO, shost,
"Error handler scsi_eh_%d exiting\n",
shost->host_no));
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
scsi_ioctl_reset(struct scsi_device *dev, int __user *arg)
{
struct scsi_cmnd *scmd;
struct Scsi_Host *shost = dev->host;
struct request req;
unsigned long flags;
int error = 0, rtn, val;
if (!capable(CAP_SYS_ADMIN) || !capable(CAP_SYS_RAWIO))
return -EACCES;
error = get_user(val, arg);
if (error)
return error;
if (scsi_autopm_get_host(shost) < 0)
return -EIO;
error = -EIO;
scmd = scsi_get_command(dev, GFP_KERNEL);
if (!scmd)
goto out_put_autopm_host;
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
switch (val & ~SG_SCSI_RESET_NO_ESCALATE) {
case SG_SCSI_RESET_NOTHING:
rtn = SUCCESS;
break;
case SG_SCSI_RESET_DEVICE:
rtn = scsi_try_bus_device_reset(scmd);
if (rtn == SUCCESS || (val & SG_SCSI_RESET_NO_ESCALATE))
break;
case SG_SCSI_RESET_TARGET:
rtn = scsi_try_target_reset(scmd);
if (rtn == SUCCESS || (val & SG_SCSI_RESET_NO_ESCALATE))
break;
case SG_SCSI_RESET_BUS:
rtn = scsi_try_bus_reset(scmd);
if (rtn == SUCCESS || (val & SG_SCSI_RESET_NO_ESCALATE))
break;
case SG_SCSI_RESET_HOST:
rtn = scsi_try_host_reset(scmd);
if (rtn == SUCCESS)
break;
default:
rtn = FAILED;
break;
}
error = (rtn == SUCCESS) ? 0 : -EIO;
spin_lock_irqsave(shost->host_lock, flags);
shost->tmf_in_progress = 0;
spin_unlock_irqrestore(shost->host_lock, flags);
SCSI_LOG_ERROR_RECOVERY(3,
shost_printk(KERN_INFO, shost,
"waking up host to restart after TMF\n"));
wake_up(&shost->host_wait);
scsi_run_host_queues(shost);
scsi_put_command(scmd);
out_put_autopm_host:
scsi_autopm_put_host(shost);
return error;
}
bool scsi_command_normalize_sense(const struct scsi_cmnd *cmd,
struct scsi_sense_hdr *sshdr)
{
return scsi_normalize_sense(cmd->sense_buffer,
SCSI_SENSE_BUFFERSIZE, sshdr);
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
