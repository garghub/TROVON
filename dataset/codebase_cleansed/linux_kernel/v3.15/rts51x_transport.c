unsigned int rts51x_access_sglist(unsigned char *buffer,
unsigned int buflen, void *sglist,
void **sgptr, unsigned int *offset,
enum xfer_buf_dir dir)
{
unsigned int cnt;
struct scatterlist *sg = (struct scatterlist *)*sgptr;
if (!sg)
sg = (struct scatterlist *)sglist;
cnt = 0;
while (cnt < buflen && sg) {
struct page *page = sg_page(sg) +
((sg->offset + *offset) >> PAGE_SHIFT);
unsigned int poff = (sg->offset + *offset) & (PAGE_SIZE - 1);
unsigned int sglen = sg->length - *offset;
if (sglen > buflen - cnt) {
sglen = buflen - cnt;
*offset += sglen;
} else {
*offset = 0;
sg = sg_next(sg);
}
while (sglen > 0) {
unsigned int plen = min(sglen, (unsigned int)
PAGE_SIZE - poff);
unsigned char *ptr = kmap(page);
if (dir == TO_XFER_BUF)
memcpy(ptr + poff, buffer + cnt, plen);
else
memcpy(buffer + cnt, ptr + poff, plen);
kunmap(page);
poff = 0;
++page;
cnt += plen;
sglen -= plen;
}
}
*sgptr = sg;
return cnt;
}
static unsigned int rts51x_access_xfer_buf(unsigned char *buffer,
unsigned int buflen, struct scsi_cmnd *srb,
struct scatterlist **sgptr,
unsigned int *offset, enum xfer_buf_dir dir)
{
return rts51x_access_sglist(buffer, buflen, (void *)scsi_sglist(srb),
(void **)sgptr, offset, dir);
}
void rts51x_set_xfer_buf(unsigned char *buffer,
unsigned int buflen, struct scsi_cmnd *srb)
{
unsigned int offset = 0;
struct scatterlist *sg = NULL;
buflen = min(buflen, scsi_bufflen(srb));
buflen = rts51x_access_xfer_buf(buffer, buflen, srb, &sg, &offset,
TO_XFER_BUF);
if (buflen < scsi_bufflen(srb))
scsi_set_resid(srb, scsi_bufflen(srb) - buflen);
}
void rts51x_get_xfer_buf(unsigned char *buffer,
unsigned int buflen, struct scsi_cmnd *srb)
{
unsigned int offset = 0;
struct scatterlist *sg = NULL;
buflen = min(buflen, scsi_bufflen(srb));
buflen = rts51x_access_xfer_buf(buffer, buflen, srb, &sg, &offset,
FROM_XFER_BUF);
if (buflen < scsi_bufflen(srb))
scsi_set_resid(srb, scsi_bufflen(srb) - buflen);
}
static void urb_done_completion(struct urb *urb)
{
struct completion *urb_done_ptr = urb->context;
if (urb_done_ptr)
complete(urb_done_ptr);
}
static int rts51x_msg_common(struct rts51x_chip *chip, struct urb *urb,
int timeout)
{
struct rts51x_usb *rts51x = chip->usb;
struct completion urb_done;
long timeleft;
int status;
if (test_bit(FLIDX_ABORTING, &rts51x->dflags))
TRACE_RET(chip, -EIO);
init_completion(&urb_done);
urb->context = &urb_done;
urb->actual_length = 0;
urb->error_count = 0;
urb->status = 0;
urb->transfer_flags = URB_NO_SETUP_DMA_MAP;
if (urb->transfer_buffer == rts51x->iobuf) {
urb->transfer_flags |= URB_NO_TRANSFER_DMA_MAP;
urb->transfer_dma = rts51x->iobuf_dma;
}
urb->setup_dma = rts51x->cr_dma;
status = usb_submit_urb(urb, GFP_NOIO);
if (status) {
TRACE_RET(chip, status);
}
set_bit(FLIDX_URB_ACTIVE, &rts51x->dflags);
if (test_bit(FLIDX_ABORTING, &rts51x->dflags)) {
if (test_and_clear_bit(FLIDX_URB_ACTIVE, &rts51x->dflags)) {
RTS51X_DEBUGP("-- cancelling URB\n");
usb_unlink_urb(urb);
}
}
timeleft =
wait_for_completion_interruptible_timeout(&urb_done,
(timeout * HZ /
1000) ? :
MAX_SCHEDULE_TIMEOUT);
clear_bit(FLIDX_URB_ACTIVE, &rts51x->dflags);
if (timeleft <= 0) {
RTS51X_DEBUGP("%s -- cancelling URB\n",
timeleft == 0 ? "Timeout" : "Signal");
usb_kill_urb(urb);
if (timeleft == 0)
status = -ETIMEDOUT;
else
status = -EINTR;
} else {
status = urb->status;
}
return status;
}
static int interpret_urb_result(struct rts51x_chip *chip, unsigned int pipe,
unsigned int length, int result,
unsigned int partial)
{
int retval = STATUS_SUCCESS;
switch (result) {
case 0:
if (partial != length) {
RTS51X_DEBUGP("-- short transfer\n");
TRACE_RET(chip, STATUS_TRANS_SHORT);
}
return STATUS_SUCCESS;
case -EPIPE:
if (usb_pipecontrol(pipe)) {
RTS51X_DEBUGP("-- stall on control pipe\n");
TRACE_RET(chip, STATUS_STALLED);
}
RTS51X_DEBUGP("clearing endpoint halt for pipe 0x%x\n", pipe);
if (rts51x_clear_halt(chip, pipe) < 0)
TRACE_RET(chip, STATUS_ERROR);
retval = STATUS_STALLED;
TRACE_GOTO(chip, Exit);
case -EOVERFLOW:
RTS51X_DEBUGP("-- babble\n");
retval = STATUS_TRANS_LONG;
TRACE_GOTO(chip, Exit);
case -ECONNRESET:
RTS51X_DEBUGP("-- transfer cancelled\n");
retval = STATUS_ERROR;
TRACE_GOTO(chip, Exit);
case -EREMOTEIO:
RTS51X_DEBUGP("-- short read transfer\n");
retval = STATUS_TRANS_SHORT;
TRACE_GOTO(chip, Exit);
case -EIO:
RTS51X_DEBUGP("-- abort or disconnect in progress\n");
retval = STATUS_ERROR;
TRACE_GOTO(chip, Exit);
case -ETIMEDOUT:
RTS51X_DEBUGP("-- time out\n");
retval = STATUS_TIMEDOUT;
TRACE_GOTO(chip, Exit);
default:
RTS51X_DEBUGP("-- unknown error\n");
retval = STATUS_ERROR;
TRACE_GOTO(chip, Exit);
}
Exit:
if ((retval != STATUS_SUCCESS) && !usb_pipecontrol(pipe))
rts51x_clear_hw_error(chip);
return retval;
}
int rts51x_ctrl_transfer(struct rts51x_chip *chip, unsigned int pipe,
u8 request, u8 requesttype, u16 value, u16 index,
void *data, u16 size, int timeout)
{
struct rts51x_usb *rts51x = chip->usb;
int result;
RTS51X_DEBUGP("%s: rq=%02x rqtype=%02x value=%04x index=%02x len=%u\n",
__func__, request, requesttype, value, index, size);
rts51x->cr->bRequestType = requesttype;
rts51x->cr->bRequest = request;
rts51x->cr->wValue = cpu_to_le16(value);
rts51x->cr->wIndex = cpu_to_le16(index);
rts51x->cr->wLength = cpu_to_le16(size);
usb_fill_control_urb(rts51x->current_urb, rts51x->pusb_dev, pipe,
(unsigned char *)rts51x->cr, data, size,
urb_done_completion, NULL);
result = rts51x_msg_common(chip, rts51x->current_urb, timeout);
return interpret_urb_result(chip, pipe, size, result,
rts51x->current_urb->actual_length);
}
static int rts51x_clear_halt(struct rts51x_chip *chip, unsigned int pipe)
{
int result;
int endp = usb_pipeendpoint(pipe);
if (usb_pipein(pipe))
endp |= USB_DIR_IN;
result = rts51x_ctrl_transfer(chip, SND_CTRL_PIPE(chip),
USB_REQ_CLEAR_FEATURE, USB_RECIP_ENDPOINT,
USB_ENDPOINT_HALT, endp, NULL, 0, 3000);
if (result != STATUS_SUCCESS)
TRACE_RET(chip, STATUS_FAIL);
usb_reset_endpoint(chip->usb->pusb_dev, endp);
return STATUS_SUCCESS;
}
static void rts51x_sg_clean(struct usb_sg_request *io)
{
if (io->urbs) {
while (io->entries--)
usb_free_urb(io->urbs[io->entries]);
kfree(io->urbs);
io->urbs = NULL;
}
io->dev = NULL;
}
static int rts51x_sg_init(struct usb_sg_request *io, struct usb_device *dev,
unsigned pipe, unsigned period, struct scatterlist *sg,
int nents, size_t length, gfp_t mem_flags)
{
return usb_sg_init(io, dev, pipe, period, sg, nents, length, mem_flags);
}
static int rts51x_sg_wait(struct usb_sg_request *io, int timeout)
{
long timeleft;
int i;
int entries = io->entries;
spin_lock_irq(&io->lock);
i = 0;
while (i < entries && !io->status) {
int retval;
io->urbs[i]->dev = io->dev;
retval = usb_submit_urb(io->urbs[i], GFP_ATOMIC);
spin_unlock_irq(&io->lock);
switch (retval) {
case -ENXIO:
case -EAGAIN:
case -ENOMEM:
io->urbs[i]->dev = NULL;
retval = 0;
yield();
break;
case 0:
++i;
cpu_relax();
break;
default:
io->urbs[i]->dev = NULL;
io->urbs[i]->status = retval;
dev_dbg(&io->dev->dev, "%s, submit --> %d\n",
__func__, retval);
usb_sg_cancel(io);
}
spin_lock_irq(&io->lock);
if (retval && (io->status == 0 || io->status == -ECONNRESET))
io->status = retval;
}
io->count -= entries - i;
if (io->count == 0)
complete(&io->complete);
spin_unlock_irq(&io->lock);
timeleft =
wait_for_completion_interruptible_timeout(&io->complete,
(timeout * HZ /
1000) ? :
MAX_SCHEDULE_TIMEOUT);
if (timeleft <= 0) {
RTS51X_DEBUGP("%s -- cancelling SG request\n",
timeleft == 0 ? "Timeout" : "Signal");
usb_sg_cancel(io);
if (timeleft == 0)
io->status = -ETIMEDOUT;
else
io->status = -EINTR;
}
rts51x_sg_clean(io);
return io->status;
}
static int rts51x_bulk_transfer_sglist(struct rts51x_chip *chip,
unsigned int pipe,
struct scatterlist *sg, int num_sg,
unsigned int length,
unsigned int *act_len, int timeout)
{
int result;
if (test_bit(FLIDX_ABORTING, &chip->usb->dflags))
TRACE_RET(chip, STATUS_ERROR);
RTS51X_DEBUGP("%s: xfer %u bytes, %d entries\n", __func__,
length, num_sg);
result =
rts51x_sg_init(&chip->usb->current_sg, chip->usb->pusb_dev, pipe, 0,
sg, num_sg, length, GFP_NOIO);
if (result) {
RTS51X_DEBUGP("rts51x_sg_init returned %d\n", result);
TRACE_RET(chip, STATUS_ERROR);
}
set_bit(FLIDX_SG_ACTIVE, &chip->usb->dflags);
if (test_bit(FLIDX_ABORTING, &chip->usb->dflags)) {
if (test_and_clear_bit(FLIDX_SG_ACTIVE, &chip->usb->dflags)) {
RTS51X_DEBUGP("-- cancelling sg request\n");
usb_sg_cancel(&chip->usb->current_sg);
}
}
result = rts51x_sg_wait(&chip->usb->current_sg, timeout);
clear_bit(FLIDX_SG_ACTIVE, &chip->usb->dflags);
if (act_len)
*act_len = chip->usb->current_sg.bytes;
return interpret_urb_result(chip, pipe, length, result,
chip->usb->current_sg.bytes);
}
static int rts51x_bulk_transfer_buf(struct rts51x_chip *chip,
unsigned int pipe,
void *buf, unsigned int length,
unsigned int *act_len, int timeout)
{
int result;
usb_fill_bulk_urb(chip->usb->current_urb, chip->usb->pusb_dev, pipe,
buf, length, urb_done_completion, NULL);
result = rts51x_msg_common(chip, chip->usb->current_urb, timeout);
if (act_len)
*act_len = chip->usb->current_urb->actual_length;
return interpret_urb_result(chip, pipe, length, result,
chip->usb->current_urb->actual_length);
}
int rts51x_transfer_data(struct rts51x_chip *chip, unsigned int pipe,
void *buf, unsigned int len, int use_sg,
unsigned int *act_len, int timeout)
{
int result;
if (timeout < 600)
timeout = 600;
if (use_sg) {
result =
rts51x_bulk_transfer_sglist(chip, pipe,
(struct scatterlist *)buf,
use_sg, len, act_len, timeout);
} else {
result =
rts51x_bulk_transfer_buf(chip, pipe, buf, len, act_len,
timeout);
}
return result;
}
int rts51x_transfer_data_partial(struct rts51x_chip *chip, unsigned int pipe,
void *buf, void **ptr, unsigned int *offset,
unsigned int len, int use_sg,
unsigned int *act_len, int timeout)
{
int result;
if (timeout < 600)
timeout = 600;
if (use_sg) {
void *tmp_buf = kmalloc(len, GFP_KERNEL);
if (!tmp_buf)
TRACE_RET(chip, STATUS_NOMEM);
if (usb_pipeout(pipe)) {
rts51x_access_sglist(tmp_buf, len, buf, ptr, offset,
FROM_XFER_BUF);
}
result =
rts51x_bulk_transfer_buf(chip, pipe, tmp_buf, len, act_len,
timeout);
if (result == STATUS_SUCCESS) {
if (usb_pipein(pipe)) {
rts51x_access_sglist(tmp_buf, len, buf, ptr,
offset, TO_XFER_BUF);
}
}
kfree(tmp_buf);
} else {
unsigned int step = 0;
if (offset)
step = *offset;
result =
rts51x_bulk_transfer_buf(chip, pipe, buf + step, len,
act_len, timeout);
if (act_len)
step += *act_len;
else
step += len;
if (offset)
*offset = step;
}
return result;
}
int rts51x_get_epc_status(struct rts51x_chip *chip, u16 *status)
{
unsigned int pipe = RCV_INTR_PIPE(chip);
struct usb_host_endpoint *ep;
struct completion urb_done;
int result;
if (!status)
TRACE_RET(chip, STATUS_ERROR);
init_completion(&urb_done);
ep = chip->usb->pusb_dev->ep_in[usb_pipeendpoint(pipe)];
usb_fill_int_urb(chip->usb->intr_urb, chip->usb->pusb_dev, pipe,
status, 2, urb_done_completion, &urb_done, 10);
result = rts51x_msg_common(chip, chip->usb->intr_urb, 100);
return interpret_urb_result(chip, pipe, 2, result,
chip->usb->intr_urb->actual_length);
}
void rts51x_invoke_transport(struct scsi_cmnd *srb, struct rts51x_chip *chip)
{
int result;
#ifdef CONFIG_PM
if (chip->option.ss_en) {
if (srb->cmnd[0] == TEST_UNIT_READY) {
if (RTS51X_CHK_STAT(chip, STAT_SS)) {
if (check_fake_card_ready(chip,
SCSI_LUN(srb))) {
srb->result = SAM_STAT_GOOD;
} else {
srb->result = SAM_STAT_CHECK_CONDITION;
memcpy(srb->sense_buffer,
media_not_present, SENSE_SIZE);
}
return;
}
} else if (srb->cmnd[0] == ALLOW_MEDIUM_REMOVAL) {
if (RTS51X_CHK_STAT(chip, STAT_SS)) {
int prevent = srb->cmnd[4] & 0x1;
if (prevent) {
srb->result = SAM_STAT_CHECK_CONDITION;
memcpy(srb->sense_buffer,
invalid_cmd_field, SENSE_SIZE);
} else {
srb->result = SAM_STAT_GOOD;
}
return;
}
} else {
if (RTS51X_CHK_STAT(chip, STAT_SS)
|| RTS51X_CHK_STAT(chip, STAT_SS_PRE)) {
RTS51X_DEBUGP("Try to wake up device\n");
chip->resume_from_scsi = 1;
rts51x_try_to_exit_ss(chip);
if (RTS51X_CHK_STAT(chip, STAT_SS)) {
wait_timeout(3000);
rts51x_init_chip(chip);
rts51x_init_cards(chip);
}
}
}
}
#endif
result = rts51x_scsi_handler(srb, chip);
if (result == TRANSPORT_ERROR) {
RTS51X_DEBUGP("-- transport indicates error, resetting\n");
srb->result = DID_ERROR << 16;
goto Handle_Errors;
}
srb->result = SAM_STAT_GOOD;
if (result == TRANSPORT_FAILED) {
srb->result = SAM_STAT_CHECK_CONDITION;
memcpy(srb->sense_buffer,
(unsigned char *)&(chip->sense_buffer[SCSI_LUN(srb)]),
sizeof(struct sense_data_t));
}
return;
Handle_Errors:
return;
}
