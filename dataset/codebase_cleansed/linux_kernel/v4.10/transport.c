static void usb_stor_blocking_completion(struct urb *urb)
{
struct completion *urb_done_ptr = urb->context;
complete(urb_done_ptr);
}
static int usb_stor_msg_common(struct us_data *us, int timeout)
{
struct completion urb_done;
long timeleft;
int status;
if (test_bit(US_FLIDX_ABORTING, &us->dflags))
return -EIO;
init_completion(&urb_done);
us->current_urb->context = &urb_done;
us->current_urb->transfer_flags = 0;
if (us->current_urb->transfer_buffer == us->iobuf)
us->current_urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
us->current_urb->transfer_dma = us->iobuf_dma;
status = usb_submit_urb(us->current_urb, GFP_NOIO);
if (status) {
return status;
}
set_bit(US_FLIDX_URB_ACTIVE, &us->dflags);
if (test_bit(US_FLIDX_ABORTING, &us->dflags)) {
if (test_and_clear_bit(US_FLIDX_URB_ACTIVE, &us->dflags)) {
usb_stor_dbg(us, "-- cancelling URB\n");
usb_unlink_urb(us->current_urb);
}
}
timeleft = wait_for_completion_interruptible_timeout(
&urb_done, timeout ? : MAX_SCHEDULE_TIMEOUT);
clear_bit(US_FLIDX_URB_ACTIVE, &us->dflags);
if (timeleft <= 0) {
usb_stor_dbg(us, "%s -- cancelling URB\n",
timeleft == 0 ? "Timeout" : "Signal");
usb_kill_urb(us->current_urb);
}
return us->current_urb->status;
}
int usb_stor_control_msg(struct us_data *us, unsigned int pipe,
u8 request, u8 requesttype, u16 value, u16 index,
void *data, u16 size, int timeout)
{
int status;
usb_stor_dbg(us, "rq=%02x rqtype=%02x value=%04x index=%02x len=%u\n",
request, requesttype, value, index, size);
us->cr->bRequestType = requesttype;
us->cr->bRequest = request;
us->cr->wValue = cpu_to_le16(value);
us->cr->wIndex = cpu_to_le16(index);
us->cr->wLength = cpu_to_le16(size);
usb_fill_control_urb(us->current_urb, us->pusb_dev, pipe,
(unsigned char*) us->cr, data, size,
usb_stor_blocking_completion, NULL);
status = usb_stor_msg_common(us, timeout);
if (status == 0)
status = us->current_urb->actual_length;
return status;
}
int usb_stor_clear_halt(struct us_data *us, unsigned int pipe)
{
int result;
int endp = usb_pipeendpoint(pipe);
if (usb_pipein (pipe))
endp |= USB_DIR_IN;
result = usb_stor_control_msg(us, us->send_ctrl_pipe,
USB_REQ_CLEAR_FEATURE, USB_RECIP_ENDPOINT,
USB_ENDPOINT_HALT, endp,
NULL, 0, 3*HZ);
if (result >= 0)
usb_reset_endpoint(us->pusb_dev, endp);
usb_stor_dbg(us, "result = %d\n", result);
return result;
}
static int interpret_urb_result(struct us_data *us, unsigned int pipe,
unsigned int length, int result, unsigned int partial)
{
usb_stor_dbg(us, "Status code %d; transferred %u/%u\n",
result, partial, length);
switch (result) {
case 0:
if (partial != length) {
usb_stor_dbg(us, "-- short transfer\n");
return USB_STOR_XFER_SHORT;
}
usb_stor_dbg(us, "-- transfer complete\n");
return USB_STOR_XFER_GOOD;
case -EPIPE:
if (usb_pipecontrol(pipe)) {
usb_stor_dbg(us, "-- stall on control pipe\n");
return USB_STOR_XFER_STALLED;
}
usb_stor_dbg(us, "clearing endpoint halt for pipe 0x%x\n",
pipe);
if (usb_stor_clear_halt(us, pipe) < 0)
return USB_STOR_XFER_ERROR;
return USB_STOR_XFER_STALLED;
case -EOVERFLOW:
usb_stor_dbg(us, "-- babble\n");
return USB_STOR_XFER_LONG;
case -ECONNRESET:
usb_stor_dbg(us, "-- transfer cancelled\n");
return USB_STOR_XFER_ERROR;
case -EREMOTEIO:
usb_stor_dbg(us, "-- short read transfer\n");
return USB_STOR_XFER_SHORT;
case -EIO:
usb_stor_dbg(us, "-- abort or disconnect in progress\n");
return USB_STOR_XFER_ERROR;
default:
usb_stor_dbg(us, "-- unknown error\n");
return USB_STOR_XFER_ERROR;
}
}
int usb_stor_ctrl_transfer(struct us_data *us, unsigned int pipe,
u8 request, u8 requesttype, u16 value, u16 index,
void *data, u16 size)
{
int result;
usb_stor_dbg(us, "rq=%02x rqtype=%02x value=%04x index=%02x len=%u\n",
request, requesttype, value, index, size);
us->cr->bRequestType = requesttype;
us->cr->bRequest = request;
us->cr->wValue = cpu_to_le16(value);
us->cr->wIndex = cpu_to_le16(index);
us->cr->wLength = cpu_to_le16(size);
usb_fill_control_urb(us->current_urb, us->pusb_dev, pipe,
(unsigned char*) us->cr, data, size,
usb_stor_blocking_completion, NULL);
result = usb_stor_msg_common(us, 0);
return interpret_urb_result(us, pipe, size, result,
us->current_urb->actual_length);
}
static int usb_stor_intr_transfer(struct us_data *us, void *buf,
unsigned int length)
{
int result;
unsigned int pipe = us->recv_intr_pipe;
unsigned int maxp;
usb_stor_dbg(us, "xfer %u bytes\n", length);
maxp = usb_maxpacket(us->pusb_dev, pipe, usb_pipeout(pipe));
if (maxp > length)
maxp = length;
usb_fill_int_urb(us->current_urb, us->pusb_dev, pipe, buf,
maxp, usb_stor_blocking_completion, NULL,
us->ep_bInterval);
result = usb_stor_msg_common(us, 0);
return interpret_urb_result(us, pipe, length, result,
us->current_urb->actual_length);
}
int usb_stor_bulk_transfer_buf(struct us_data *us, unsigned int pipe,
void *buf, unsigned int length, unsigned int *act_len)
{
int result;
usb_stor_dbg(us, "xfer %u bytes\n", length);
usb_fill_bulk_urb(us->current_urb, us->pusb_dev, pipe, buf, length,
usb_stor_blocking_completion, NULL);
result = usb_stor_msg_common(us, 0);
if (act_len)
*act_len = us->current_urb->actual_length;
return interpret_urb_result(us, pipe, length, result,
us->current_urb->actual_length);
}
static int usb_stor_bulk_transfer_sglist(struct us_data *us, unsigned int pipe,
struct scatterlist *sg, int num_sg, unsigned int length,
unsigned int *act_len)
{
int result;
if (test_bit(US_FLIDX_ABORTING, &us->dflags))
return USB_STOR_XFER_ERROR;
usb_stor_dbg(us, "xfer %u bytes, %d entries\n", length, num_sg);
result = usb_sg_init(&us->current_sg, us->pusb_dev, pipe, 0,
sg, num_sg, length, GFP_NOIO);
if (result) {
usb_stor_dbg(us, "usb_sg_init returned %d\n", result);
return USB_STOR_XFER_ERROR;
}
set_bit(US_FLIDX_SG_ACTIVE, &us->dflags);
if (test_bit(US_FLIDX_ABORTING, &us->dflags)) {
if (test_and_clear_bit(US_FLIDX_SG_ACTIVE, &us->dflags)) {
usb_stor_dbg(us, "-- cancelling sg request\n");
usb_sg_cancel(&us->current_sg);
}
}
usb_sg_wait(&us->current_sg);
clear_bit(US_FLIDX_SG_ACTIVE, &us->dflags);
result = us->current_sg.status;
if (act_len)
*act_len = us->current_sg.bytes;
return interpret_urb_result(us, pipe, length, result,
us->current_sg.bytes);
}
int usb_stor_bulk_srb(struct us_data* us, unsigned int pipe,
struct scsi_cmnd* srb)
{
unsigned int partial;
int result = usb_stor_bulk_transfer_sglist(us, pipe, scsi_sglist(srb),
scsi_sg_count(srb), scsi_bufflen(srb),
&partial);
scsi_set_resid(srb, scsi_bufflen(srb) - partial);
return result;
}
int usb_stor_bulk_transfer_sg(struct us_data* us, unsigned int pipe,
void *buf, unsigned int length_left, int use_sg, int *residual)
{
int result;
unsigned int partial;
if (use_sg) {
result = usb_stor_bulk_transfer_sglist(us, pipe,
(struct scatterlist *) buf, use_sg,
length_left, &partial);
length_left -= partial;
} else {
result = usb_stor_bulk_transfer_buf(us, pipe, buf,
length_left, &partial);
length_left -= partial;
}
if (residual)
*residual = length_left;
return result;
}
static void last_sector_hacks(struct us_data *us, struct scsi_cmnd *srb)
{
struct gendisk *disk;
struct scsi_disk *sdkp;
u32 sector;
static unsigned char record_not_found[18] = {
[0] = 0x70,
[2] = MEDIUM_ERROR,
[7] = 0x0a,
[12] = 0x14
};
if (!us->use_last_sector_hacks)
return;
if (srb->cmnd[0] != READ_10 && srb->cmnd[0] != WRITE_10)
goto done;
sector = (srb->cmnd[2] << 24) | (srb->cmnd[3] << 16) |
(srb->cmnd[4] << 8) | (srb->cmnd[5]);
disk = srb->request->rq_disk;
if (!disk)
goto done;
sdkp = scsi_disk(disk);
if (!sdkp)
goto done;
if (sector + 1 != sdkp->capacity)
goto done;
if (srb->result == SAM_STAT_GOOD && scsi_get_resid(srb) == 0) {
us->use_last_sector_hacks = 0;
} else {
if (++us->last_sector_retries < 3)
return;
srb->result = SAM_STAT_CHECK_CONDITION;
memcpy(srb->sense_buffer, record_not_found,
sizeof(record_not_found));
}
done:
if (srb->cmnd[0] != TEST_UNIT_READY)
us->last_sector_retries = 0;
}
void usb_stor_invoke_transport(struct scsi_cmnd *srb, struct us_data *us)
{
int need_auto_sense;
int result;
scsi_set_resid(srb, 0);
result = us->transport(srb, us);
if (test_bit(US_FLIDX_TIMED_OUT, &us->dflags)) {
usb_stor_dbg(us, "-- command was aborted\n");
srb->result = DID_ABORT << 16;
goto Handle_Errors;
}
if (result == USB_STOR_TRANSPORT_ERROR) {
usb_stor_dbg(us, "-- transport indicates error, resetting\n");
srb->result = DID_ERROR << 16;
goto Handle_Errors;
}
if (result == USB_STOR_TRANSPORT_NO_SENSE) {
srb->result = SAM_STAT_CHECK_CONDITION;
last_sector_hacks(us, srb);
return;
}
srb->result = SAM_STAT_GOOD;
need_auto_sense = 0;
if ((us->protocol == USB_PR_CB || us->protocol == USB_PR_DPCM_USB) &&
srb->sc_data_direction != DMA_FROM_DEVICE) {
usb_stor_dbg(us, "-- CB transport device requiring auto-sense\n");
need_auto_sense = 1;
}
if (result == USB_STOR_TRANSPORT_FAILED) {
usb_stor_dbg(us, "-- transport indicates command failure\n");
need_auto_sense = 1;
}
if (unlikely((srb->cmnd[0] == ATA_16 || srb->cmnd[0] == ATA_12) &&
result == USB_STOR_TRANSPORT_GOOD &&
!(us->fflags & US_FL_SANE_SENSE) &&
!(us->fflags & US_FL_BAD_SENSE) &&
!(srb->cmnd[2] & 0x20))) {
usb_stor_dbg(us, "-- SAT supported, increasing auto-sense\n");
us->fflags |= US_FL_SANE_SENSE;
}
if ((scsi_get_resid(srb) > 0) &&
!((srb->cmnd[0] == REQUEST_SENSE) ||
(srb->cmnd[0] == INQUIRY) ||
(srb->cmnd[0] == MODE_SENSE) ||
(srb->cmnd[0] == LOG_SENSE) ||
(srb->cmnd[0] == MODE_SENSE_10))) {
usb_stor_dbg(us, "-- unexpectedly short transfer\n");
}
if (need_auto_sense) {
int temp_result;
struct scsi_eh_save ses;
int sense_size = US_SENSE_SIZE;
struct scsi_sense_hdr sshdr;
const u8 *scdd;
u8 fm_ili;
if (us->fflags & US_FL_SANE_SENSE)
sense_size = ~0;
Retry_Sense:
usb_stor_dbg(us, "Issuing auto-REQUEST_SENSE\n");
scsi_eh_prep_cmnd(srb, &ses, NULL, 0, sense_size);
if (us->subclass == USB_SC_RBC || us->subclass == USB_SC_SCSI ||
us->subclass == USB_SC_CYP_ATACB)
srb->cmd_len = 6;
else
srb->cmd_len = 12;
scsi_set_resid(srb, 0);
temp_result = us->transport(us->srb, us);
scsi_eh_restore_cmnd(srb, &ses);
if (test_bit(US_FLIDX_TIMED_OUT, &us->dflags)) {
usb_stor_dbg(us, "-- auto-sense aborted\n");
srb->result = DID_ABORT << 16;
if (sense_size != US_SENSE_SIZE) {
us->fflags &= ~US_FL_SANE_SENSE;
us->fflags |= US_FL_BAD_SENSE;
}
goto Handle_Errors;
}
if (temp_result == USB_STOR_TRANSPORT_FAILED &&
sense_size != US_SENSE_SIZE) {
usb_stor_dbg(us, "-- auto-sense failure, retry small sense\n");
sense_size = US_SENSE_SIZE;
us->fflags &= ~US_FL_SANE_SENSE;
us->fflags |= US_FL_BAD_SENSE;
goto Retry_Sense;
}
if (temp_result != USB_STOR_TRANSPORT_GOOD) {
usb_stor_dbg(us, "-- auto-sense failure\n");
srb->result = DID_ERROR << 16;
if (!(us->fflags & US_FL_SCM_MULT_TARG))
goto Handle_Errors;
return;
}
if (srb->sense_buffer[7] > (US_SENSE_SIZE - 8) &&
!(us->fflags & US_FL_SANE_SENSE) &&
!(us->fflags & US_FL_BAD_SENSE) &&
(srb->sense_buffer[0] & 0x7C) == 0x70) {
usb_stor_dbg(us, "-- SANE_SENSE support enabled\n");
us->fflags |= US_FL_SANE_SENSE;
usb_stor_dbg(us, "-- Sense data truncated to %i from %i\n",
US_SENSE_SIZE,
srb->sense_buffer[7] + 8);
srb->sense_buffer[7] = (US_SENSE_SIZE - 8);
}
scsi_normalize_sense(srb->sense_buffer, SCSI_SENSE_BUFFERSIZE,
&sshdr);
usb_stor_dbg(us, "-- Result from auto-sense is %d\n",
temp_result);
usb_stor_dbg(us, "-- code: 0x%x, key: 0x%x, ASC: 0x%x, ASCQ: 0x%x\n",
sshdr.response_code, sshdr.sense_key,
sshdr.asc, sshdr.ascq);
#ifdef CONFIG_USB_STORAGE_DEBUG
usb_stor_show_sense(us, sshdr.sense_key, sshdr.asc, sshdr.ascq);
#endif
srb->result = SAM_STAT_CHECK_CONDITION;
scdd = scsi_sense_desc_find(srb->sense_buffer,
SCSI_SENSE_BUFFERSIZE, 4);
fm_ili = (scdd ? scdd[3] : srb->sense_buffer[2]) & 0xA0;
if (sshdr.sense_key == 0 && sshdr.asc == 0 && sshdr.ascq == 0 &&
fm_ili == 0) {
if (result == USB_STOR_TRANSPORT_GOOD) {
srb->result = SAM_STAT_GOOD;
srb->sense_buffer[0] = 0x0;
} else {
srb->result = DID_ERROR << 16;
if ((sshdr.response_code & 0x72) == 0x72)
srb->sense_buffer[1] = HARDWARE_ERROR;
else
srb->sense_buffer[2] = HARDWARE_ERROR;
}
}
}
if (unlikely((us->fflags & US_FL_INITIAL_READ10) &&
srb->cmnd[0] == READ_10)) {
if (srb->result == SAM_STAT_GOOD) {
set_bit(US_FLIDX_READ10_WORKED, &us->dflags);
} else if (test_bit(US_FLIDX_READ10_WORKED, &us->dflags)) {
clear_bit(US_FLIDX_READ10_WORKED, &us->dflags);
set_bit(US_FLIDX_REDO_READ10, &us->dflags);
}
if (test_bit(US_FLIDX_REDO_READ10, &us->dflags)) {
clear_bit(US_FLIDX_REDO_READ10, &us->dflags);
srb->result = DID_IMM_RETRY << 16;
srb->sense_buffer[0] = 0;
}
}
if ((srb->result == SAM_STAT_GOOD || srb->sense_buffer[2] == 0) &&
scsi_bufflen(srb) - scsi_get_resid(srb) < srb->underflow)
srb->result = DID_ERROR << 16;
last_sector_hacks(us, srb);
return;
Handle_Errors:
scsi_lock(us_to_host(us));
set_bit(US_FLIDX_RESETTING, &us->dflags);
clear_bit(US_FLIDX_ABORTING, &us->dflags);
scsi_unlock(us_to_host(us));
mutex_unlock(&us->dev_mutex);
result = usb_stor_port_reset(us);
mutex_lock(&us->dev_mutex);
if (result < 0) {
scsi_lock(us_to_host(us));
usb_stor_report_device_reset(us);
scsi_unlock(us_to_host(us));
us->transport_reset(us);
}
clear_bit(US_FLIDX_RESETTING, &us->dflags);
last_sector_hacks(us, srb);
}
void usb_stor_stop_transport(struct us_data *us)
{
if (test_and_clear_bit(US_FLIDX_URB_ACTIVE, &us->dflags)) {
usb_stor_dbg(us, "-- cancelling URB\n");
usb_unlink_urb(us->current_urb);
}
if (test_and_clear_bit(US_FLIDX_SG_ACTIVE, &us->dflags)) {
usb_stor_dbg(us, "-- cancelling sg request\n");
usb_sg_cancel(&us->current_sg);
}
}
int usb_stor_CB_transport(struct scsi_cmnd *srb, struct us_data *us)
{
unsigned int transfer_length = scsi_bufflen(srb);
unsigned int pipe = 0;
int result;
memcpy(us->iobuf, srb->cmnd, srb->cmd_len);
result = usb_stor_ctrl_transfer(us, us->send_ctrl_pipe,
US_CBI_ADSC,
USB_TYPE_CLASS | USB_RECIP_INTERFACE, 0,
us->ifnum, us->iobuf, srb->cmd_len);
usb_stor_dbg(us, "Call to usb_stor_ctrl_transfer() returned %d\n",
result);
if (result == USB_STOR_XFER_STALLED) {
return USB_STOR_TRANSPORT_FAILED;
}
if (result != USB_STOR_XFER_GOOD) {
return USB_STOR_TRANSPORT_ERROR;
}
if (transfer_length) {
pipe = srb->sc_data_direction == DMA_FROM_DEVICE ?
us->recv_bulk_pipe : us->send_bulk_pipe;
result = usb_stor_bulk_srb(us, pipe, srb);
usb_stor_dbg(us, "CBI data stage result is 0x%x\n", result);
if (result == USB_STOR_XFER_STALLED)
return USB_STOR_TRANSPORT_FAILED;
if (result > USB_STOR_XFER_STALLED)
return USB_STOR_TRANSPORT_ERROR;
}
if (us->protocol != USB_PR_CBI)
return USB_STOR_TRANSPORT_GOOD;
result = usb_stor_intr_transfer(us, us->iobuf, 2);
usb_stor_dbg(us, "Got interrupt data (0x%x, 0x%x)\n",
us->iobuf[0], us->iobuf[1]);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (us->subclass == USB_SC_UFI) {
if (srb->cmnd[0] == REQUEST_SENSE ||
srb->cmnd[0] == INQUIRY)
return USB_STOR_TRANSPORT_GOOD;
if (us->iobuf[0])
goto Failed;
return USB_STOR_TRANSPORT_GOOD;
}
if (us->iobuf[0]) {
usb_stor_dbg(us, "CBI IRQ data showed reserved bType 0x%x\n",
us->iobuf[0]);
goto Failed;
}
switch (us->iobuf[1] & 0x0F) {
case 0x00:
return USB_STOR_TRANSPORT_GOOD;
case 0x01:
goto Failed;
}
return USB_STOR_TRANSPORT_ERROR;
Failed:
if (pipe)
usb_stor_clear_halt(us, pipe);
return USB_STOR_TRANSPORT_FAILED;
}
int usb_stor_Bulk_max_lun(struct us_data *us)
{
int result;
us->iobuf[0] = 0;
result = usb_stor_control_msg(us, us->recv_ctrl_pipe,
US_BULK_GET_MAX_LUN,
USB_DIR_IN | USB_TYPE_CLASS |
USB_RECIP_INTERFACE,
0, us->ifnum, us->iobuf, 1, 10*HZ);
usb_stor_dbg(us, "GetMaxLUN command result is %d, data is %d\n",
result, us->iobuf[0]);
if (result > 0) {
if (us->iobuf[0] < 16) {
return us->iobuf[0];
} else {
dev_info(&us->pusb_intf->dev,
"Max LUN %d is not valid, using 0 instead",
us->iobuf[0]);
}
}
return 0;
}
int usb_stor_Bulk_transport(struct scsi_cmnd *srb, struct us_data *us)
{
struct bulk_cb_wrap *bcb = (struct bulk_cb_wrap *) us->iobuf;
struct bulk_cs_wrap *bcs = (struct bulk_cs_wrap *) us->iobuf;
unsigned int transfer_length = scsi_bufflen(srb);
unsigned int residue;
int result;
int fake_sense = 0;
unsigned int cswlen;
unsigned int cbwlen = US_BULK_CB_WRAP_LEN;
if (unlikely(us->fflags & US_FL_BULK32)) {
cbwlen = 32;
us->iobuf[31] = 0;
}
bcb->Signature = cpu_to_le32(US_BULK_CB_SIGN);
bcb->DataTransferLength = cpu_to_le32(transfer_length);
bcb->Flags = srb->sc_data_direction == DMA_FROM_DEVICE ?
US_BULK_FLAG_IN : 0;
bcb->Tag = ++us->tag;
bcb->Lun = srb->device->lun;
if (us->fflags & US_FL_SCM_MULT_TARG)
bcb->Lun |= srb->device->id << 4;
bcb->Length = srb->cmd_len;
memset(bcb->CDB, 0, sizeof(bcb->CDB));
memcpy(bcb->CDB, srb->cmnd, bcb->Length);
usb_stor_dbg(us, "Bulk Command S 0x%x T 0x%x L %d F %d Trg %d LUN %d CL %d\n",
le32_to_cpu(bcb->Signature), bcb->Tag,
le32_to_cpu(bcb->DataTransferLength), bcb->Flags,
(bcb->Lun >> 4), (bcb->Lun & 0x0F),
bcb->Length);
result = usb_stor_bulk_transfer_buf(us, us->send_bulk_pipe,
bcb, cbwlen, NULL);
usb_stor_dbg(us, "Bulk command transfer result=%d\n", result);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
if (unlikely(us->fflags & US_FL_GO_SLOW))
usleep_range(125, 150);
if (transfer_length) {
unsigned int pipe = srb->sc_data_direction == DMA_FROM_DEVICE ?
us->recv_bulk_pipe : us->send_bulk_pipe;
result = usb_stor_bulk_srb(us, pipe, srb);
usb_stor_dbg(us, "Bulk data transfer result 0x%x\n", result);
if (result == USB_STOR_XFER_ERROR)
return USB_STOR_TRANSPORT_ERROR;
if (result == USB_STOR_XFER_LONG)
fake_sense = 1;
if (result == USB_STOR_XFER_SHORT &&
srb->sc_data_direction == DMA_FROM_DEVICE &&
transfer_length - scsi_get_resid(srb) ==
US_BULK_CS_WRAP_LEN) {
struct scatterlist *sg = NULL;
unsigned int offset = 0;
if (usb_stor_access_xfer_buf((unsigned char *) bcs,
US_BULK_CS_WRAP_LEN, srb, &sg,
&offset, FROM_XFER_BUF) ==
US_BULK_CS_WRAP_LEN &&
bcs->Signature ==
cpu_to_le32(US_BULK_CS_SIGN)) {
usb_stor_dbg(us, "Device skipped data phase\n");
scsi_set_resid(srb, transfer_length);
goto skipped_data_phase;
}
}
}
usb_stor_dbg(us, "Attempting to get CSW...\n");
result = usb_stor_bulk_transfer_buf(us, us->recv_bulk_pipe,
bcs, US_BULK_CS_WRAP_LEN, &cswlen);
if (result == USB_STOR_XFER_SHORT && cswlen == 0) {
usb_stor_dbg(us, "Received 0-length CSW; retrying...\n");
result = usb_stor_bulk_transfer_buf(us, us->recv_bulk_pipe,
bcs, US_BULK_CS_WRAP_LEN, &cswlen);
}
if (result == USB_STOR_XFER_STALLED) {
usb_stor_dbg(us, "Attempting to get CSW (2nd try)...\n");
result = usb_stor_bulk_transfer_buf(us, us->recv_bulk_pipe,
bcs, US_BULK_CS_WRAP_LEN, NULL);
}
usb_stor_dbg(us, "Bulk status result = %d\n", result);
if (result != USB_STOR_XFER_GOOD)
return USB_STOR_TRANSPORT_ERROR;
skipped_data_phase:
residue = le32_to_cpu(bcs->Residue);
usb_stor_dbg(us, "Bulk Status S 0x%x T 0x%x R %u Stat 0x%x\n",
le32_to_cpu(bcs->Signature), bcs->Tag,
residue, bcs->Status);
if (!(bcs->Tag == us->tag || (us->fflags & US_FL_BULK_IGNORE_TAG)) ||
bcs->Status > US_BULK_STAT_PHASE) {
usb_stor_dbg(us, "Bulk logical error\n");
return USB_STOR_TRANSPORT_ERROR;
}
if (!us->bcs_signature) {
us->bcs_signature = bcs->Signature;
if (us->bcs_signature != cpu_to_le32(US_BULK_CS_SIGN))
usb_stor_dbg(us, "Learnt BCS signature 0x%08X\n",
le32_to_cpu(us->bcs_signature));
} else if (bcs->Signature != us->bcs_signature) {
usb_stor_dbg(us, "Signature mismatch: got %08X, expecting %08X\n",
le32_to_cpu(bcs->Signature),
le32_to_cpu(us->bcs_signature));
return USB_STOR_TRANSPORT_ERROR;
}
if (residue && !(us->fflags & US_FL_IGNORE_RESIDUE)) {
if (bcs->Status == US_BULK_STAT_OK &&
scsi_get_resid(srb) == 0 &&
((srb->cmnd[0] == INQUIRY &&
transfer_length == 36) ||
(srb->cmnd[0] == READ_CAPACITY &&
transfer_length == 8))) {
us->fflags |= US_FL_IGNORE_RESIDUE;
} else {
residue = min(residue, transfer_length);
scsi_set_resid(srb, max(scsi_get_resid(srb),
(int) residue));
}
}
switch (bcs->Status) {
case US_BULK_STAT_OK:
if (fake_sense) {
memcpy(srb->sense_buffer,
usb_stor_sense_invalidCDB,
sizeof(usb_stor_sense_invalidCDB));
return USB_STOR_TRANSPORT_NO_SENSE;
}
return USB_STOR_TRANSPORT_GOOD;
case US_BULK_STAT_FAIL:
return USB_STOR_TRANSPORT_FAILED;
case US_BULK_STAT_PHASE:
return USB_STOR_TRANSPORT_ERROR;
}
return USB_STOR_TRANSPORT_ERROR;
}
static int usb_stor_reset_common(struct us_data *us,
u8 request, u8 requesttype,
u16 value, u16 index, void *data, u16 size)
{
int result;
int result2;
if (test_bit(US_FLIDX_DISCONNECTING, &us->dflags)) {
usb_stor_dbg(us, "No reset during disconnect\n");
return -EIO;
}
result = usb_stor_control_msg(us, us->send_ctrl_pipe,
request, requesttype, value, index, data, size,
5*HZ);
if (result < 0) {
usb_stor_dbg(us, "Soft reset failed: %d\n", result);
return result;
}
wait_event_interruptible_timeout(us->delay_wait,
test_bit(US_FLIDX_DISCONNECTING, &us->dflags),
HZ*6);
if (test_bit(US_FLIDX_DISCONNECTING, &us->dflags)) {
usb_stor_dbg(us, "Reset interrupted by disconnect\n");
return -EIO;
}
usb_stor_dbg(us, "Soft reset: clearing bulk-in endpoint halt\n");
result = usb_stor_clear_halt(us, us->recv_bulk_pipe);
usb_stor_dbg(us, "Soft reset: clearing bulk-out endpoint halt\n");
result2 = usb_stor_clear_halt(us, us->send_bulk_pipe);
if (result >= 0)
result = result2;
if (result < 0)
usb_stor_dbg(us, "Soft reset failed\n");
else
usb_stor_dbg(us, "Soft reset done\n");
return result;
}
int usb_stor_CB_reset(struct us_data *us)
{
memset(us->iobuf, 0xFF, CB_RESET_CMD_SIZE);
us->iobuf[0] = SEND_DIAGNOSTIC;
us->iobuf[1] = 4;
return usb_stor_reset_common(us, US_CBI_ADSC,
USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0, us->ifnum, us->iobuf, CB_RESET_CMD_SIZE);
}
int usb_stor_Bulk_reset(struct us_data *us)
{
return usb_stor_reset_common(us, US_BULK_RESET_REQUEST,
USB_TYPE_CLASS | USB_RECIP_INTERFACE,
0, us->ifnum, NULL, 0);
}
int usb_stor_port_reset(struct us_data *us)
{
int result;
if (us->pusb_dev->quirks & USB_QUIRK_RESET)
return -EPERM;
result = usb_lock_device_for_reset(us->pusb_dev, us->pusb_intf);
if (result < 0)
usb_stor_dbg(us, "unable to lock device for reset: %d\n",
result);
else {
if (test_bit(US_FLIDX_DISCONNECTING, &us->dflags)) {
result = -EIO;
usb_stor_dbg(us, "No reset during disconnect\n");
} else {
result = usb_reset_device(us->pusb_dev);
usb_stor_dbg(us, "usb_reset_device returns %d\n",
result);
}
usb_unlock_device(us->pusb_dev);
}
return result;
}
