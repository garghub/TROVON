static char *get_usb_rcmsg(int rc)
{
static char unkmsg[28];
switch (rc) {
case 0:
return "success";
case -ENOMEM:
return "out of memory";
case -ENODEV:
return "device not present";
case -ENOENT:
return "endpoint not present";
case -ENXIO:
return "URB type not supported";
case -EINVAL:
return "invalid argument";
case -EAGAIN:
return "start frame too early or too much scheduled";
case -EFBIG:
return "too many isoc frames requested";
case -EPIPE:
return "endpoint stalled";
case -EMSGSIZE:
return "invalid packet size";
case -ENOSPC:
return "would overcommit USB bandwidth";
case -ESHUTDOWN:
return "device shut down";
case -EPERM:
return "reject flag set";
case -EHOSTUNREACH:
return "device suspended";
default:
snprintf(unkmsg, sizeof(unkmsg), "unknown error %d", rc);
return unkmsg;
}
}
static char *get_usb_statmsg(int status)
{
static char unkmsg[28];
switch (status) {
case 0:
return "success";
case -ENOENT:
return "unlinked (sync)";
case -EINPROGRESS:
return "URB still pending";
case -EPROTO:
return "bitstuff error, timeout, or unknown USB error";
case -EILSEQ:
return "CRC mismatch, timeout, or unknown USB error";
case -ETIME:
return "USB response timeout";
case -EPIPE:
return "endpoint stalled";
case -ECOMM:
return "IN buffer overrun";
case -ENOSR:
return "OUT buffer underrun";
case -EOVERFLOW:
return "endpoint babble";
case -EREMOTEIO:
return "short packet";
case -ENODEV:
return "device removed";
case -EXDEV:
return "partial isoc transfer";
case -EINVAL:
return "ISO madness";
case -ECONNRESET:
return "unlinked (async)";
case -ESHUTDOWN:
return "device shut down";
default:
snprintf(unkmsg, sizeof(unkmsg), "unknown status %d", status);
return unkmsg;
}
}
static inline char *usb_pipetype_str(int pipe)
{
if (usb_pipeisoc(pipe))
return "Isoc";
if (usb_pipeint(pipe))
return "Int";
if (usb_pipecontrol(pipe))
return "Ctrl";
if (usb_pipebulk(pipe))
return "Bulk";
return "?";
}
static inline void dump_urb(enum debuglevel level, const char *tag,
struct urb *urb)
{
#ifdef CONFIG_GIGASET_DEBUG
int i;
gig_dbg(level, "%s urb(0x%08lx)->{", tag, (unsigned long) urb);
if (urb) {
gig_dbg(level,
" dev=0x%08lx, pipe=%s:EP%d/DV%d:%s, "
"hcpriv=0x%08lx, transfer_flags=0x%x,",
(unsigned long) urb->dev,
usb_pipetype_str(urb->pipe),
usb_pipeendpoint(urb->pipe), usb_pipedevice(urb->pipe),
usb_pipein(urb->pipe) ? "in" : "out",
(unsigned long) urb->hcpriv,
urb->transfer_flags);
gig_dbg(level,
" transfer_buffer=0x%08lx[%d], actual_length=%d, "
"setup_packet=0x%08lx,",
(unsigned long) urb->transfer_buffer,
urb->transfer_buffer_length, urb->actual_length,
(unsigned long) urb->setup_packet);
gig_dbg(level,
" start_frame=%d, number_of_packets=%d, interval=%d, "
"error_count=%d,",
urb->start_frame, urb->number_of_packets, urb->interval,
urb->error_count);
gig_dbg(level,
" context=0x%08lx, complete=0x%08lx, "
"iso_frame_desc[]={",
(unsigned long) urb->context,
(unsigned long) urb->complete);
for (i = 0; i < urb->number_of_packets; i++) {
struct usb_iso_packet_descriptor *pifd
= &urb->iso_frame_desc[i];
gig_dbg(level,
" {offset=%u, length=%u, actual_length=%u, "
"status=%u}",
pifd->offset, pifd->length, pifd->actual_length,
pifd->status);
}
}
gig_dbg(level, "}}");
#endif
}
static int gigaset_set_modem_ctrl(struct cardstate *cs, unsigned old_state,
unsigned new_state)
{
return -EINVAL;
}
static int gigaset_baud_rate(struct cardstate *cs, unsigned cflag)
{
return -EINVAL;
}
static int gigaset_set_line_ctrl(struct cardstate *cs, unsigned cflag)
{
return -EINVAL;
}
static inline int update_basstate(struct bas_cardstate *ucs,
int set, int clear)
{
unsigned long flags;
int state;
spin_lock_irqsave(&ucs->lock, flags);
state = ucs->basstate;
ucs->basstate = (state & ~clear) | set;
spin_unlock_irqrestore(&ucs->lock, flags);
return state;
}
static inline void error_hangup(struct bc_state *bcs)
{
struct cardstate *cs = bcs->cs;
gigaset_add_event(cs, &bcs->at_state, EV_HUP, NULL, 0, NULL);
gigaset_schedule_event(cs);
}
static inline void error_reset(struct cardstate *cs)
{
update_basstate(cs->hw.bas, BS_RESETTING, 0);
if (req_submit(cs->bcs, HD_RESET_INTERRUPT_PIPE, 0, BAS_TIMEOUT))
usb_queue_reset_device(cs->hw.bas->interface);
}
static void check_pending(struct bas_cardstate *ucs)
{
unsigned long flags;
spin_lock_irqsave(&ucs->lock, flags);
switch (ucs->pending) {
case 0:
break;
case HD_OPEN_ATCHANNEL:
if (ucs->basstate & BS_ATOPEN)
ucs->pending = 0;
break;
case HD_OPEN_B1CHANNEL:
if (ucs->basstate & BS_B1OPEN)
ucs->pending = 0;
break;
case HD_OPEN_B2CHANNEL:
if (ucs->basstate & BS_B2OPEN)
ucs->pending = 0;
break;
case HD_CLOSE_ATCHANNEL:
if (!(ucs->basstate & BS_ATOPEN))
ucs->pending = 0;
break;
case HD_CLOSE_B1CHANNEL:
if (!(ucs->basstate & BS_B1OPEN))
ucs->pending = 0;
break;
case HD_CLOSE_B2CHANNEL:
if (!(ucs->basstate & BS_B2OPEN))
ucs->pending = 0;
break;
case HD_DEVICE_INIT_ACK:
ucs->pending = 0;
break;
case HD_RESET_INTERRUPT_PIPE:
if (!(ucs->basstate & BS_RESETTING))
ucs->pending = 0;
break;
default:
dev_warn(&ucs->interface->dev,
"unknown pending request 0x%02x cleared\n",
ucs->pending);
ucs->pending = 0;
}
if (!ucs->pending)
del_timer(&ucs->timer_ctrl);
spin_unlock_irqrestore(&ucs->lock, flags);
}
static void cmd_in_timeout(unsigned long data)
{
struct cardstate *cs = (struct cardstate *) data;
struct bas_cardstate *ucs = cs->hw.bas;
int rc;
if (!ucs->rcvbuf_size) {
gig_dbg(DEBUG_USBREQ, "%s: no receive in progress", __func__);
return;
}
if (ucs->retry_cmd_in++ >= BAS_RETRY) {
dev_err(cs->dev,
"control read: timeout, giving up after %d tries\n",
ucs->retry_cmd_in);
kfree(ucs->rcvbuf);
ucs->rcvbuf = NULL;
ucs->rcvbuf_size = 0;
error_reset(cs);
return;
}
gig_dbg(DEBUG_USBREQ, "%s: timeout, retry %d",
__func__, ucs->retry_cmd_in);
rc = atread_submit(cs, BAS_TIMEOUT);
if (rc < 0) {
kfree(ucs->rcvbuf);
ucs->rcvbuf = NULL;
ucs->rcvbuf_size = 0;
if (rc != -ENODEV)
error_reset(cs);
}
}
static void read_ctrl_callback(struct urb *urb)
{
struct inbuf_t *inbuf = urb->context;
struct cardstate *cs = inbuf->cs;
struct bas_cardstate *ucs = cs->hw.bas;
int status = urb->status;
unsigned numbytes;
int rc;
update_basstate(ucs, 0, BS_ATRDPEND);
wake_up(&ucs->waitqueue);
del_timer(&ucs->timer_cmd_in);
switch (status) {
case 0:
numbytes = urb->actual_length;
if (unlikely(numbytes != ucs->rcvbuf_size)) {
dev_warn(cs->dev,
"control read: received %d chars, expected %d\n",
numbytes, ucs->rcvbuf_size);
if (numbytes > ucs->rcvbuf_size)
numbytes = ucs->rcvbuf_size;
}
if (gigaset_fill_inbuf(inbuf, ucs->rcvbuf, numbytes)) {
gig_dbg(DEBUG_INTR, "%s-->BH", __func__);
gigaset_schedule_event(cs);
}
break;
case -ENOENT:
case -ECONNRESET:
case -EINPROGRESS:
case -ENODEV:
case -ESHUTDOWN:
gig_dbg(DEBUG_USBREQ, "%s: %s",
__func__, get_usb_statmsg(status));
break;
default:
if (ucs->retry_cmd_in++ < BAS_RETRY) {
gig_dbg(DEBUG_USBREQ, "%s: %s, retry %d", __func__,
get_usb_statmsg(status), ucs->retry_cmd_in);
rc = atread_submit(cs, BAS_TIMEOUT);
if (rc >= 0)
return;
if (rc == -ENODEV)
break;
}
dev_err(cs->dev, "control read: %s, giving up after %d tries\n",
get_usb_statmsg(status), ucs->retry_cmd_in);
error_reset(cs);
}
kfree(ucs->rcvbuf);
ucs->rcvbuf = NULL;
ucs->rcvbuf_size = 0;
}
static int atread_submit(struct cardstate *cs, int timeout)
{
struct bas_cardstate *ucs = cs->hw.bas;
int basstate;
int ret;
gig_dbg(DEBUG_USBREQ, "-------> HD_READ_ATMESSAGE (%d)",
ucs->rcvbuf_size);
basstate = update_basstate(ucs, BS_ATRDPEND, 0);
if (basstate & BS_ATRDPEND) {
dev_err(cs->dev,
"could not submit HD_READ_ATMESSAGE: URB busy\n");
return -EBUSY;
}
if (basstate & BS_SUSPEND) {
dev_notice(cs->dev,
"HD_READ_ATMESSAGE not submitted, "
"suspend in progress\n");
update_basstate(ucs, 0, BS_ATRDPEND);
return -ENODEV;
}
ucs->dr_cmd_in.bRequestType = IN_VENDOR_REQ;
ucs->dr_cmd_in.bRequest = HD_READ_ATMESSAGE;
ucs->dr_cmd_in.wValue = 0;
ucs->dr_cmd_in.wIndex = 0;
ucs->dr_cmd_in.wLength = cpu_to_le16(ucs->rcvbuf_size);
usb_fill_control_urb(ucs->urb_cmd_in, ucs->udev,
usb_rcvctrlpipe(ucs->udev, 0),
(unsigned char *) &ucs->dr_cmd_in,
ucs->rcvbuf, ucs->rcvbuf_size,
read_ctrl_callback, cs->inbuf);
ret = usb_submit_urb(ucs->urb_cmd_in, GFP_ATOMIC);
if (ret != 0) {
update_basstate(ucs, 0, BS_ATRDPEND);
dev_err(cs->dev, "could not submit HD_READ_ATMESSAGE: %s\n",
get_usb_rcmsg(ret));
return ret;
}
if (timeout > 0) {
gig_dbg(DEBUG_USBREQ, "setting timeout of %d/10 secs", timeout);
mod_timer(&ucs->timer_cmd_in, jiffies + timeout * HZ / 10);
}
return 0;
}
static void int_in_work(struct work_struct *work)
{
struct bas_cardstate *ucs =
container_of(work, struct bas_cardstate, int_in_wq);
struct urb *urb = ucs->urb_int_in;
struct cardstate *cs = urb->context;
int rc;
rc = usb_clear_halt(ucs->udev, urb->pipe);
gig_dbg(DEBUG_USBREQ, "clear_halt: %s", get_usb_rcmsg(rc));
if (rc == 0)
rc = usb_submit_urb(urb, GFP_ATOMIC);
switch (rc) {
case 0:
case -ENODEV:
case -EINVAL:
break;
default:
dev_err(cs->dev, "clear halt failed: %s\n", get_usb_rcmsg(rc));
rc = usb_lock_device_for_reset(ucs->udev, ucs->interface);
if (rc == 0) {
rc = usb_reset_device(ucs->udev);
usb_unlock_device(ucs->udev);
}
}
ucs->retry_int_in = 0;
}
static void int_in_resubmit(unsigned long data)
{
struct cardstate *cs = (struct cardstate *) data;
struct bas_cardstate *ucs = cs->hw.bas;
int rc;
if (ucs->retry_int_in++ >= BAS_RETRY) {
dev_err(cs->dev, "interrupt read: giving up after %d tries\n",
ucs->retry_int_in);
usb_queue_reset_device(ucs->interface);
return;
}
gig_dbg(DEBUG_USBREQ, "%s: retry %d", __func__, ucs->retry_int_in);
rc = usb_submit_urb(ucs->urb_int_in, GFP_ATOMIC);
if (rc != 0 && rc != -ENODEV) {
dev_err(cs->dev, "could not resubmit interrupt URB: %s\n",
get_usb_rcmsg(rc));
usb_queue_reset_device(ucs->interface);
}
}
static void read_int_callback(struct urb *urb)
{
struct cardstate *cs = urb->context;
struct bas_cardstate *ucs = cs->hw.bas;
struct bc_state *bcs;
int status = urb->status;
unsigned long flags;
int rc;
unsigned l;
int channel;
switch (status) {
case 0:
ucs->retry_int_in = 0;
break;
case -EPIPE:
schedule_work(&ucs->int_in_wq);
case -ENOENT:
case -ECONNRESET:
case -EINPROGRESS:
case -ENODEV:
case -ESHUTDOWN:
gig_dbg(DEBUG_USBREQ, "%s: %s",
__func__, get_usb_statmsg(status));
return;
case -EPROTO:
case -EILSEQ:
case -ETIME:
gig_dbg(DEBUG_USBREQ, "%s: %s",
__func__, get_usb_statmsg(status));
mod_timer(&ucs->timer_int_in, jiffies + HZ / 10);
return;
default:
dev_warn(cs->dev, "interrupt read: %s\n",
get_usb_statmsg(status));
goto resubmit;
}
if (unlikely(urb->actual_length < IP_MSGSIZE)) {
dev_warn(cs->dev, "incomplete interrupt packet (%d bytes)\n",
urb->actual_length);
goto resubmit;
}
l = (unsigned) ucs->int_in_buf[1] +
(((unsigned) ucs->int_in_buf[2]) << 8);
gig_dbg(DEBUG_USBREQ, "<-------%d: 0x%02x (%u [0x%02x 0x%02x])",
urb->actual_length, (int)ucs->int_in_buf[0], l,
(int)ucs->int_in_buf[1], (int)ucs->int_in_buf[2]);
channel = 0;
switch (ucs->int_in_buf[0]) {
case HD_DEVICE_INIT_OK:
update_basstate(ucs, BS_INIT, 0);
break;
case HD_READY_SEND_ATDATA:
del_timer(&ucs->timer_atrdy);
update_basstate(ucs, BS_ATREADY, BS_ATTIMER);
start_cbsend(cs);
break;
case HD_OPEN_B2CHANNEL_ACK:
++channel;
case HD_OPEN_B1CHANNEL_ACK:
bcs = cs->bcs + channel;
update_basstate(ucs, BS_B1OPEN << channel, 0);
gigaset_bchannel_up(bcs);
break;
case HD_OPEN_ATCHANNEL_ACK:
update_basstate(ucs, BS_ATOPEN, 0);
start_cbsend(cs);
break;
case HD_CLOSE_B2CHANNEL_ACK:
++channel;
case HD_CLOSE_B1CHANNEL_ACK:
bcs = cs->bcs + channel;
update_basstate(ucs, 0, BS_B1OPEN << channel);
stopurbs(bcs->hw.bas);
gigaset_bchannel_down(bcs);
break;
case HD_CLOSE_ATCHANNEL_ACK:
update_basstate(ucs, 0, BS_ATOPEN);
break;
case HD_B2_FLOW_CONTROL:
++channel;
case HD_B1_FLOW_CONTROL:
bcs = cs->bcs + channel;
atomic_add((l - BAS_NORMFRAME) * BAS_CORRFRAMES,
&bcs->hw.bas->corrbytes);
gig_dbg(DEBUG_ISO,
"Flow control (channel %d, sub %d): 0x%02x => %d",
channel, bcs->hw.bas->numsub, l,
atomic_read(&bcs->hw.bas->corrbytes));
break;
case HD_RECEIVEATDATA_ACK:
if (!l) {
dev_warn(cs->dev,
"HD_RECEIVEATDATA_ACK with length 0 ignored\n");
break;
}
spin_lock_irqsave(&cs->lock, flags);
if (ucs->basstate & BS_ATRDPEND) {
spin_unlock_irqrestore(&cs->lock, flags);
dev_warn(cs->dev,
"HD_RECEIVEATDATA_ACK(%d) during HD_READ_ATMESSAGE(%d) ignored\n",
l, ucs->rcvbuf_size);
break;
}
if (ucs->rcvbuf_size) {
dev_err(cs->dev,
"receive AT data overrun, %d bytes lost\n",
ucs->rcvbuf_size);
kfree(ucs->rcvbuf);
ucs->rcvbuf_size = 0;
}
ucs->rcvbuf = kmalloc(l, GFP_ATOMIC);
if (ucs->rcvbuf == NULL) {
spin_unlock_irqrestore(&cs->lock, flags);
dev_err(cs->dev, "out of memory receiving AT data\n");
break;
}
ucs->rcvbuf_size = l;
ucs->retry_cmd_in = 0;
rc = atread_submit(cs, BAS_TIMEOUT);
if (rc < 0) {
kfree(ucs->rcvbuf);
ucs->rcvbuf = NULL;
ucs->rcvbuf_size = 0;
}
spin_unlock_irqrestore(&cs->lock, flags);
if (rc < 0 && rc != -ENODEV)
error_reset(cs);
break;
case HD_RESET_INTERRUPT_PIPE_ACK:
update_basstate(ucs, 0, BS_RESETTING);
dev_notice(cs->dev, "interrupt pipe reset\n");
break;
case HD_SUSPEND_END:
gig_dbg(DEBUG_USBREQ, "HD_SUSPEND_END");
break;
default:
dev_warn(cs->dev,
"unknown Gigaset signal 0x%02x (%u) ignored\n",
(int) ucs->int_in_buf[0], l);
}
check_pending(ucs);
wake_up(&ucs->waitqueue);
resubmit:
rc = usb_submit_urb(urb, GFP_ATOMIC);
if (unlikely(rc != 0 && rc != -ENODEV)) {
dev_err(cs->dev, "could not resubmit interrupt URB: %s\n",
get_usb_rcmsg(rc));
error_reset(cs);
}
}
static void read_iso_callback(struct urb *urb)
{
struct bc_state *bcs;
struct bas_bc_state *ubc;
int status = urb->status;
unsigned long flags;
int i, rc;
if (unlikely(status == -ENOENT ||
status == -ECONNRESET ||
status == -EINPROGRESS ||
status == -ENODEV ||
status == -ESHUTDOWN)) {
gig_dbg(DEBUG_ISO, "%s: %s",
__func__, get_usb_statmsg(status));
return;
}
bcs = urb->context;
ubc = bcs->hw.bas;
spin_lock_irqsave(&ubc->isoinlock, flags);
if (likely(ubc->isoindone == NULL)) {
ubc->isoindone = urb;
ubc->isoinstatus = status;
tasklet_hi_schedule(&ubc->rcvd_tasklet);
} else {
gig_dbg(DEBUG_ISO, "%s: overrun", __func__);
ubc->loststatus = status;
for (i = 0; i < BAS_NUMFRAMES; i++) {
ubc->isoinlost += urb->iso_frame_desc[i].actual_length;
if (unlikely(urb->iso_frame_desc[i].status != 0 &&
urb->iso_frame_desc[i].status != -EINPROGRESS))
ubc->loststatus = urb->iso_frame_desc[i].status;
urb->iso_frame_desc[i].status = 0;
urb->iso_frame_desc[i].actual_length = 0;
}
if (likely(ubc->running)) {
urb->dev = bcs->cs->hw.bas->udev;
urb->transfer_flags = URB_ISO_ASAP;
urb->number_of_packets = BAS_NUMFRAMES;
rc = usb_submit_urb(urb, GFP_ATOMIC);
if (unlikely(rc != 0 && rc != -ENODEV)) {
dev_err(bcs->cs->dev,
"could not resubmit isoc read URB: %s\n",
get_usb_rcmsg(rc));
dump_urb(DEBUG_ISO, "isoc read", urb);
error_hangup(bcs);
}
}
}
spin_unlock_irqrestore(&ubc->isoinlock, flags);
}
static void write_iso_callback(struct urb *urb)
{
struct isow_urbctx_t *ucx;
struct bas_bc_state *ubc;
int status = urb->status;
unsigned long flags;
if (unlikely(status == -ENOENT ||
status == -ECONNRESET ||
status == -EINPROGRESS ||
status == -ENODEV ||
status == -ESHUTDOWN)) {
gig_dbg(DEBUG_ISO, "%s: %s",
__func__, get_usb_statmsg(status));
return;
}
ucx = urb->context;
ubc = ucx->bcs->hw.bas;
ucx->status = status;
spin_lock_irqsave(&ubc->isooutlock, flags);
ubc->isooutovfl = ubc->isooutdone;
ubc->isooutdone = ucx;
spin_unlock_irqrestore(&ubc->isooutlock, flags);
tasklet_hi_schedule(&ubc->sent_tasklet);
}
static int starturbs(struct bc_state *bcs)
{
struct bas_bc_state *ubc = bcs->hw.bas;
struct urb *urb;
int j, k;
int rc;
if (bcs->proto2 == L2_HDLC)
bcs->inputstate |= INS_flag_hunt;
ubc->running = 1;
for (k = 0; k < BAS_INURBS; k++) {
urb = ubc->isoinurbs[k];
if (!urb) {
rc = -EFAULT;
goto error;
}
urb->dev = bcs->cs->hw.bas->udev;
urb->pipe = usb_rcvisocpipe(urb->dev, 3 + 2 * bcs->channel);
urb->transfer_flags = URB_ISO_ASAP;
urb->transfer_buffer = ubc->isoinbuf + k * BAS_INBUFSIZE;
urb->transfer_buffer_length = BAS_INBUFSIZE;
urb->number_of_packets = BAS_NUMFRAMES;
urb->interval = BAS_FRAMETIME;
urb->complete = read_iso_callback;
urb->context = bcs;
for (j = 0; j < BAS_NUMFRAMES; j++) {
urb->iso_frame_desc[j].offset = j * BAS_MAXFRAME;
urb->iso_frame_desc[j].length = BAS_MAXFRAME;
urb->iso_frame_desc[j].status = 0;
urb->iso_frame_desc[j].actual_length = 0;
}
dump_urb(DEBUG_ISO, "Initial isoc read", urb);
rc = usb_submit_urb(urb, GFP_ATOMIC);
if (rc != 0)
goto error;
}
gigaset_isowbuf_init(ubc->isooutbuf, PPP_FLAG);
for (k = 0; k < BAS_OUTURBS; ++k) {
urb = ubc->isoouturbs[k].urb;
if (!urb) {
rc = -EFAULT;
goto error;
}
urb->dev = bcs->cs->hw.bas->udev;
urb->pipe = usb_sndisocpipe(urb->dev, 4 + 2 * bcs->channel);
urb->transfer_flags = URB_ISO_ASAP;
urb->transfer_buffer = ubc->isooutbuf->data;
urb->transfer_buffer_length = sizeof(ubc->isooutbuf->data);
urb->number_of_packets = BAS_NUMFRAMES;
urb->interval = BAS_FRAMETIME;
urb->complete = write_iso_callback;
urb->context = &ubc->isoouturbs[k];
for (j = 0; j < BAS_NUMFRAMES; ++j) {
urb->iso_frame_desc[j].offset = BAS_OUTBUFSIZE;
urb->iso_frame_desc[j].length = BAS_NORMFRAME;
urb->iso_frame_desc[j].status = 0;
urb->iso_frame_desc[j].actual_length = 0;
}
ubc->isoouturbs[k].limit = -1;
}
for (k = 0; k < BAS_OUTURBS - 1; ++k) {
dump_urb(DEBUG_ISO, "Initial isoc write", urb);
rc = usb_submit_urb(ubc->isoouturbs[k].urb, GFP_ATOMIC);
if (rc != 0)
goto error;
}
dump_urb(DEBUG_ISO, "Initial isoc write (free)", urb);
ubc->isooutfree = &ubc->isoouturbs[BAS_OUTURBS - 1];
ubc->isooutdone = ubc->isooutovfl = NULL;
return 0;
error:
stopurbs(ubc);
return rc;
}
static void stopurbs(struct bas_bc_state *ubc)
{
int k, rc;
ubc->running = 0;
for (k = 0; k < BAS_INURBS; ++k) {
rc = usb_unlink_urb(ubc->isoinurbs[k]);
gig_dbg(DEBUG_ISO,
"%s: isoc input URB %d unlinked, result = %s",
__func__, k, get_usb_rcmsg(rc));
}
for (k = 0; k < BAS_OUTURBS; ++k) {
rc = usb_unlink_urb(ubc->isoouturbs[k].urb);
gig_dbg(DEBUG_ISO,
"%s: isoc output URB %d unlinked, result = %s",
__func__, k, get_usb_rcmsg(rc));
}
}
static int submit_iso_write_urb(struct isow_urbctx_t *ucx)
{
struct urb *urb = ucx->urb;
struct bas_bc_state *ubc = ucx->bcs->hw.bas;
struct usb_iso_packet_descriptor *ifd;
int corrbytes, nframe, rc;
urb->dev = ucx->bcs->cs->hw.bas->udev;
urb->transfer_flags = URB_ISO_ASAP;
urb->transfer_buffer = ubc->isooutbuf->data;
urb->transfer_buffer_length = sizeof(ubc->isooutbuf->data);
for (nframe = 0; nframe < BAS_NUMFRAMES; nframe++) {
ifd = &urb->iso_frame_desc[nframe];
ifd->length = BAS_NORMFRAME;
corrbytes = atomic_read(&ubc->corrbytes);
if (corrbytes != 0) {
gig_dbg(DEBUG_ISO, "%s: corrbytes=%d",
__func__, corrbytes);
if (corrbytes > BAS_HIGHFRAME - BAS_NORMFRAME)
corrbytes = BAS_HIGHFRAME - BAS_NORMFRAME;
else if (corrbytes < BAS_LOWFRAME - BAS_NORMFRAME)
corrbytes = BAS_LOWFRAME - BAS_NORMFRAME;
ifd->length += corrbytes;
atomic_add(-corrbytes, &ubc->corrbytes);
}
rc = gigaset_isowbuf_getbytes(ubc->isooutbuf, ifd->length);
if (rc < 0) {
if (rc == -EBUSY) {
gig_dbg(DEBUG_ISO,
"%s: buffer busy at frame %d",
__func__, nframe);
} else {
dev_err(ucx->bcs->cs->dev,
"%s: buffer error %d at frame %d\n",
__func__, rc, nframe);
return rc;
}
break;
}
ifd->offset = rc;
ucx->limit = ubc->isooutbuf->nextread;
ifd->status = 0;
ifd->actual_length = 0;
}
if (unlikely(nframe == 0))
return 0;
urb->number_of_packets = nframe;
rc = usb_submit_urb(urb, GFP_ATOMIC);
if (unlikely(rc)) {
if (rc == -ENODEV)
gig_dbg(DEBUG_ISO, "%s: disconnected", __func__);
else
dev_err(ucx->bcs->cs->dev,
"could not submit isoc write URB: %s\n",
get_usb_rcmsg(rc));
return rc;
}
++ubc->numsub;
return nframe;
}
static void write_iso_tasklet(unsigned long data)
{
struct bc_state *bcs = (struct bc_state *) data;
struct bas_bc_state *ubc = bcs->hw.bas;
struct cardstate *cs = bcs->cs;
struct isow_urbctx_t *done, *next, *ovfl;
struct urb *urb;
int status;
struct usb_iso_packet_descriptor *ifd;
unsigned long flags;
int i;
struct sk_buff *skb;
int len;
int rc;
for (;;) {
if (unlikely(!(ubc->running))) {
gig_dbg(DEBUG_ISO, "%s: not running", __func__);
return;
}
spin_lock_irqsave(&ubc->isooutlock, flags);
done = ubc->isooutdone;
ubc->isooutdone = NULL;
ovfl = ubc->isooutovfl;
ubc->isooutovfl = NULL;
spin_unlock_irqrestore(&ubc->isooutlock, flags);
if (ovfl) {
dev_err(cs->dev, "isoc write underrun\n");
error_hangup(bcs);
break;
}
if (!done)
break;
spin_lock_irqsave(&ubc->isooutlock, flags);
next = ubc->isooutfree;
ubc->isooutfree = NULL;
spin_unlock_irqrestore(&ubc->isooutlock, flags);
if (next) {
rc = submit_iso_write_urb(next);
if (unlikely(rc <= 0 && rc != -ENODEV)) {
spin_lock_irqsave(&ubc->isooutlock, flags);
if (ubc->isooutfree == NULL) {
ubc->isooutfree = next;
next = NULL;
}
spin_unlock_irqrestore(&ubc->isooutlock, flags);
if (next) {
dev_err(cs->dev,
"losing isoc write URB\n");
error_hangup(bcs);
}
}
}
urb = done->urb;
status = done->status;
switch (status) {
case -EXDEV:
gig_dbg(DEBUG_ISO, "%s: URB partially completed",
__func__);
case 0:
for (i = 0; i < BAS_NUMFRAMES; i++) {
ifd = &urb->iso_frame_desc[i];
if (ifd->status ||
ifd->actual_length != ifd->length) {
dev_warn(cs->dev,
"isoc write: frame %d[%d/%d]: %s\n",
i, ifd->actual_length,
ifd->length,
get_usb_statmsg(ifd->status));
break;
}
}
break;
case -EPIPE:
dev_err(cs->dev, "isoc write: stalled\n");
error_hangup(bcs);
break;
default:
dev_warn(cs->dev, "isoc write: %s\n",
get_usb_statmsg(status));
}
if (done->limit >= 0)
ubc->isooutbuf->read = done->limit;
spin_lock_irqsave(&ubc->isooutlock, flags);
next = ubc->isooutfree;
ubc->isooutfree = done;
spin_unlock_irqrestore(&ubc->isooutlock, flags);
if (next) {
rc = submit_iso_write_urb(next);
if (unlikely(rc <= 0 && rc != -ENODEV)) {
error_hangup(bcs);
}
}
}
while ((skb = skb_dequeue(&bcs->squeue))) {
len = skb->len;
if (gigaset_isoc_buildframe(bcs, skb->data, len) == -EAGAIN) {
skb_queue_head(&bcs->squeue, skb);
gig_dbg(DEBUG_ISO, "%s: skb requeued, qlen=%d",
__func__, skb_queue_len(&bcs->squeue));
break;
}
skb_pull(skb, len);
gigaset_skb_sent(bcs, skb);
dev_kfree_skb_any(skb);
}
}
static void read_iso_tasklet(unsigned long data)
{
struct bc_state *bcs = (struct bc_state *) data;
struct bas_bc_state *ubc = bcs->hw.bas;
struct cardstate *cs = bcs->cs;
struct urb *urb;
int status;
struct usb_iso_packet_descriptor *ifd;
char *rcvbuf;
unsigned long flags;
int totleft, numbytes, offset, frame, rc;
for (;;) {
spin_lock_irqsave(&ubc->isoinlock, flags);
urb = ubc->isoindone;
if (!urb) {
spin_unlock_irqrestore(&ubc->isoinlock, flags);
return;
}
status = ubc->isoinstatus;
ubc->isoindone = NULL;
if (unlikely(ubc->loststatus != -EINPROGRESS)) {
dev_warn(cs->dev,
"isoc read overrun, URB dropped (status: %s, %d bytes)\n",
get_usb_statmsg(ubc->loststatus),
ubc->isoinlost);
ubc->loststatus = -EINPROGRESS;
}
spin_unlock_irqrestore(&ubc->isoinlock, flags);
if (unlikely(!(ubc->running))) {
gig_dbg(DEBUG_ISO,
"%s: channel not running, "
"dropped URB with status: %s",
__func__, get_usb_statmsg(status));
return;
}
switch (status) {
case 0:
break;
case -EXDEV:
gig_dbg(DEBUG_ISO, "%s: URB partially completed",
__func__);
break;
case -ENOENT:
case -ECONNRESET:
case -EINPROGRESS:
gig_dbg(DEBUG_ISO, "%s: %s",
__func__, get_usb_statmsg(status));
continue;
case -EPIPE:
dev_err(cs->dev, "isoc read: stalled\n");
error_hangup(bcs);
continue;
default:
dev_warn(cs->dev, "isoc read: %s\n",
get_usb_statmsg(status));
goto error;
}
rcvbuf = urb->transfer_buffer;
totleft = urb->actual_length;
for (frame = 0; totleft > 0 && frame < BAS_NUMFRAMES; frame++) {
ifd = &urb->iso_frame_desc[frame];
numbytes = ifd->actual_length;
switch (ifd->status) {
case 0:
break;
case -EPROTO:
case -EILSEQ:
case -ETIME:
gig_dbg(DEBUG_ISO,
"isoc read: frame %d[%d]: %s\n",
frame, numbytes,
get_usb_statmsg(ifd->status));
break;
default:
dev_warn(cs->dev,
"isoc read: frame %d[%d]: %s\n",
frame, numbytes,
get_usb_statmsg(ifd->status));
}
if (unlikely(numbytes > BAS_MAXFRAME))
dev_warn(cs->dev,
"isoc read: frame %d[%d]: %s\n",
frame, numbytes,
"exceeds max frame size");
if (unlikely(numbytes > totleft)) {
dev_warn(cs->dev,
"isoc read: frame %d[%d]: %s\n",
frame, numbytes,
"exceeds total transfer length");
numbytes = totleft;
}
offset = ifd->offset;
if (unlikely(offset + numbytes > BAS_INBUFSIZE)) {
dev_warn(cs->dev,
"isoc read: frame %d[%d]: %s\n",
frame, numbytes,
"exceeds end of buffer");
numbytes = BAS_INBUFSIZE - offset;
}
gigaset_isoc_receive(rcvbuf + offset, numbytes, bcs);
totleft -= numbytes;
}
if (unlikely(totleft > 0))
dev_warn(cs->dev, "isoc read: %d data bytes missing\n",
totleft);
error:
for (frame = 0; frame < BAS_NUMFRAMES; frame++) {
urb->iso_frame_desc[frame].status = 0;
urb->iso_frame_desc[frame].actual_length = 0;
}
urb->dev = bcs->cs->hw.bas->udev;
urb->transfer_flags = URB_ISO_ASAP;
urb->number_of_packets = BAS_NUMFRAMES;
rc = usb_submit_urb(urb, GFP_ATOMIC);
if (unlikely(rc != 0 && rc != -ENODEV)) {
dev_err(cs->dev,
"could not resubmit isoc read URB: %s\n",
get_usb_rcmsg(rc));
dump_urb(DEBUG_ISO, "resubmit isoc read", urb);
error_hangup(bcs);
}
}
}
static void req_timeout(unsigned long data)
{
struct cardstate *cs = (struct cardstate *) data;
struct bas_cardstate *ucs = cs->hw.bas;
int pending;
unsigned long flags;
check_pending(ucs);
spin_lock_irqsave(&ucs->lock, flags);
pending = ucs->pending;
ucs->pending = 0;
spin_unlock_irqrestore(&ucs->lock, flags);
switch (pending) {
case 0:
gig_dbg(DEBUG_USBREQ, "%s: no request pending", __func__);
break;
case HD_OPEN_ATCHANNEL:
dev_err(cs->dev, "timeout opening AT channel\n");
error_reset(cs);
break;
case HD_OPEN_B1CHANNEL:
dev_err(cs->dev, "timeout opening channel 1\n");
error_hangup(&cs->bcs[0]);
break;
case HD_OPEN_B2CHANNEL:
dev_err(cs->dev, "timeout opening channel 2\n");
error_hangup(&cs->bcs[1]);
break;
case HD_CLOSE_ATCHANNEL:
dev_err(cs->dev, "timeout closing AT channel\n");
error_reset(cs);
break;
case HD_CLOSE_B1CHANNEL:
dev_err(cs->dev, "timeout closing channel 1\n");
error_reset(cs);
break;
case HD_CLOSE_B2CHANNEL:
dev_err(cs->dev, "timeout closing channel 2\n");
error_reset(cs);
break;
case HD_RESET_INTERRUPT_PIPE:
dev_err(cs->dev,
"reset interrupt pipe timeout, attempting USB reset\n");
usb_queue_reset_device(ucs->interface);
break;
default:
dev_warn(cs->dev, "request 0x%02x timed out, clearing\n",
pending);
}
wake_up(&ucs->waitqueue);
}
static void write_ctrl_callback(struct urb *urb)
{
struct bas_cardstate *ucs = urb->context;
int status = urb->status;
int rc;
unsigned long flags;
switch (status) {
case 0:
spin_lock_irqsave(&ucs->lock, flags);
switch (ucs->pending) {
case HD_DEVICE_INIT_ACK:
del_timer(&ucs->timer_ctrl);
ucs->pending = 0;
break;
}
spin_unlock_irqrestore(&ucs->lock, flags);
return;
case -ENOENT:
case -ECONNRESET:
case -EINPROGRESS:
case -ENODEV:
case -ESHUTDOWN:
gig_dbg(DEBUG_USBREQ, "%s: %s",
__func__, get_usb_statmsg(status));
break;
default:
if (++ucs->retry_ctrl > BAS_RETRY ||
(ucs->basstate & BS_SUSPEND)) {
dev_err(&ucs->interface->dev,
"control request 0x%02x failed: %s\n",
ucs->dr_ctrl.bRequest,
get_usb_statmsg(status));
break;
}
dev_notice(&ucs->interface->dev,
"control request 0x%02x: %s, retry %d\n",
ucs->dr_ctrl.bRequest, get_usb_statmsg(status),
ucs->retry_ctrl);
urb->dev = ucs->udev;
rc = usb_submit_urb(urb, GFP_ATOMIC);
if (unlikely(rc)) {
dev_err(&ucs->interface->dev,
"could not resubmit request 0x%02x: %s\n",
ucs->dr_ctrl.bRequest, get_usb_rcmsg(rc));
break;
}
return;
}
spin_lock_irqsave(&ucs->lock, flags);
del_timer(&ucs->timer_ctrl);
ucs->pending = 0;
spin_unlock_irqrestore(&ucs->lock, flags);
wake_up(&ucs->waitqueue);
}
static int req_submit(struct bc_state *bcs, int req, int val, int timeout)
{
struct bas_cardstate *ucs = bcs->cs->hw.bas;
int ret;
unsigned long flags;
gig_dbg(DEBUG_USBREQ, "-------> 0x%02x (%d)", req, val);
spin_lock_irqsave(&ucs->lock, flags);
if (ucs->pending) {
spin_unlock_irqrestore(&ucs->lock, flags);
dev_err(bcs->cs->dev,
"submission of request 0x%02x failed: "
"request 0x%02x still pending\n",
req, ucs->pending);
return -EBUSY;
}
ucs->dr_ctrl.bRequestType = OUT_VENDOR_REQ;
ucs->dr_ctrl.bRequest = req;
ucs->dr_ctrl.wValue = cpu_to_le16(val);
ucs->dr_ctrl.wIndex = 0;
ucs->dr_ctrl.wLength = 0;
usb_fill_control_urb(ucs->urb_ctrl, ucs->udev,
usb_sndctrlpipe(ucs->udev, 0),
(unsigned char *) &ucs->dr_ctrl, NULL, 0,
write_ctrl_callback, ucs);
ucs->retry_ctrl = 0;
ret = usb_submit_urb(ucs->urb_ctrl, GFP_ATOMIC);
if (unlikely(ret)) {
dev_err(bcs->cs->dev, "could not submit request 0x%02x: %s\n",
req, get_usb_rcmsg(ret));
spin_unlock_irqrestore(&ucs->lock, flags);
return ret;
}
ucs->pending = req;
if (timeout > 0) {
gig_dbg(DEBUG_USBREQ, "setting timeout of %d/10 secs", timeout);
mod_timer(&ucs->timer_ctrl, jiffies + timeout * HZ / 10);
}
spin_unlock_irqrestore(&ucs->lock, flags);
return 0;
}
static int gigaset_init_bchannel(struct bc_state *bcs)
{
struct cardstate *cs = bcs->cs;
int req, ret;
unsigned long flags;
spin_lock_irqsave(&cs->lock, flags);
if (unlikely(!cs->connected)) {
gig_dbg(DEBUG_USBREQ, "%s: not connected", __func__);
spin_unlock_irqrestore(&cs->lock, flags);
return -ENODEV;
}
if (cs->hw.bas->basstate & BS_SUSPEND) {
dev_notice(cs->dev,
"not starting isoc I/O, suspend in progress\n");
spin_unlock_irqrestore(&cs->lock, flags);
return -EHOSTUNREACH;
}
ret = starturbs(bcs);
if (ret < 0) {
spin_unlock_irqrestore(&cs->lock, flags);
dev_err(cs->dev,
"could not start isoc I/O for channel B%d: %s\n",
bcs->channel + 1,
ret == -EFAULT ? "null URB" : get_usb_rcmsg(ret));
if (ret != -ENODEV)
error_hangup(bcs);
return ret;
}
req = bcs->channel ? HD_OPEN_B2CHANNEL : HD_OPEN_B1CHANNEL;
ret = req_submit(bcs, req, 0, BAS_TIMEOUT);
if (ret < 0) {
dev_err(cs->dev, "could not open channel B%d\n",
bcs->channel + 1);
stopurbs(bcs->hw.bas);
}
spin_unlock_irqrestore(&cs->lock, flags);
if (ret < 0 && ret != -ENODEV)
error_hangup(bcs);
return ret;
}
static int gigaset_close_bchannel(struct bc_state *bcs)
{
struct cardstate *cs = bcs->cs;
int req, ret;
unsigned long flags;
spin_lock_irqsave(&cs->lock, flags);
if (unlikely(!cs->connected)) {
spin_unlock_irqrestore(&cs->lock, flags);
gig_dbg(DEBUG_USBREQ, "%s: not connected", __func__);
return -ENODEV;
}
if (!(cs->hw.bas->basstate & (bcs->channel ? BS_B2OPEN : BS_B1OPEN))) {
spin_unlock_irqrestore(&cs->lock, flags);
gigaset_bchannel_down(bcs);
return 0;
}
req = bcs->channel ? HD_CLOSE_B2CHANNEL : HD_CLOSE_B1CHANNEL;
ret = req_submit(bcs, req, 0, BAS_TIMEOUT);
if (ret < 0)
dev_err(cs->dev, "closing channel B%d failed\n",
bcs->channel + 1);
spin_unlock_irqrestore(&cs->lock, flags);
return ret;
}
static void complete_cb(struct cardstate *cs)
{
struct cmdbuf_t *cb = cs->cmdbuf;
cs->cmdbytes -= cs->curlen;
gig_dbg(DEBUG_OUTPUT, "write_command: sent %u bytes, %u left",
cs->curlen, cs->cmdbytes);
if (cb->next != NULL) {
cs->cmdbuf = cb->next;
cs->cmdbuf->prev = NULL;
cs->curlen = cs->cmdbuf->len;
} else {
cs->cmdbuf = NULL;
cs->lastcmdbuf = NULL;
cs->curlen = 0;
}
if (cb->wake_tasklet)
tasklet_schedule(cb->wake_tasklet);
kfree(cb);
}
static void write_command_callback(struct urb *urb)
{
struct cardstate *cs = urb->context;
struct bas_cardstate *ucs = cs->hw.bas;
int status = urb->status;
unsigned long flags;
update_basstate(ucs, 0, BS_ATWRPEND);
wake_up(&ucs->waitqueue);
switch (status) {
case 0:
break;
case -ENOENT:
case -ECONNRESET:
case -EINPROGRESS:
case -ENODEV:
case -ESHUTDOWN:
gig_dbg(DEBUG_USBREQ, "%s: %s",
__func__, get_usb_statmsg(status));
return;
default:
if (++ucs->retry_cmd_out > BAS_RETRY) {
dev_warn(cs->dev,
"command write: %s, "
"giving up after %d retries\n",
get_usb_statmsg(status),
ucs->retry_cmd_out);
break;
}
if (ucs->basstate & BS_SUSPEND) {
dev_warn(cs->dev,
"command write: %s, "
"won't retry - suspend requested\n",
get_usb_statmsg(status));
break;
}
if (cs->cmdbuf == NULL) {
dev_warn(cs->dev,
"command write: %s, "
"cannot retry - cmdbuf gone\n",
get_usb_statmsg(status));
break;
}
dev_notice(cs->dev, "command write: %s, retry %d\n",
get_usb_statmsg(status), ucs->retry_cmd_out);
if (atwrite_submit(cs, cs->cmdbuf->buf, cs->cmdbuf->len) >= 0)
return;
update_basstate(ucs, BS_ATREADY, 0);
}
spin_lock_irqsave(&cs->cmdlock, flags);
if (cs->cmdbuf != NULL)
complete_cb(cs);
spin_unlock_irqrestore(&cs->cmdlock, flags);
}
static void atrdy_timeout(unsigned long data)
{
struct cardstate *cs = (struct cardstate *) data;
struct bas_cardstate *ucs = cs->hw.bas;
dev_warn(cs->dev, "timeout waiting for HD_READY_SEND_ATDATA\n");
update_basstate(ucs, BS_ATREADY, BS_ATTIMER);
start_cbsend(cs);
}
static int atwrite_submit(struct cardstate *cs, unsigned char *buf, int len)
{
struct bas_cardstate *ucs = cs->hw.bas;
int rc;
gig_dbg(DEBUG_USBREQ, "-------> HD_WRITE_ATMESSAGE (%d)", len);
if (update_basstate(ucs, BS_ATWRPEND, 0) & BS_ATWRPEND) {
dev_err(cs->dev,
"could not submit HD_WRITE_ATMESSAGE: URB busy\n");
return -EBUSY;
}
ucs->dr_cmd_out.bRequestType = OUT_VENDOR_REQ;
ucs->dr_cmd_out.bRequest = HD_WRITE_ATMESSAGE;
ucs->dr_cmd_out.wValue = 0;
ucs->dr_cmd_out.wIndex = 0;
ucs->dr_cmd_out.wLength = cpu_to_le16(len);
usb_fill_control_urb(ucs->urb_cmd_out, ucs->udev,
usb_sndctrlpipe(ucs->udev, 0),
(unsigned char *) &ucs->dr_cmd_out, buf, len,
write_command_callback, cs);
rc = usb_submit_urb(ucs->urb_cmd_out, GFP_ATOMIC);
if (unlikely(rc)) {
update_basstate(ucs, 0, BS_ATWRPEND);
dev_err(cs->dev, "could not submit HD_WRITE_ATMESSAGE: %s\n",
get_usb_rcmsg(rc));
return rc;
}
if (!(update_basstate(ucs, BS_ATTIMER, BS_ATREADY) & BS_ATTIMER)) {
gig_dbg(DEBUG_OUTPUT, "setting ATREADY timeout of %d/10 secs",
ATRDY_TIMEOUT);
mod_timer(&ucs->timer_atrdy, jiffies + ATRDY_TIMEOUT * HZ / 10);
}
return 0;
}
static int start_cbsend(struct cardstate *cs)
{
struct cmdbuf_t *cb;
struct bas_cardstate *ucs = cs->hw.bas;
unsigned long flags;
int rc;
int retval = 0;
if (ucs->basstate & BS_SUSPEND) {
gig_dbg(DEBUG_OUTPUT, "suspending");
return -EHOSTUNREACH;
}
if (!(ucs->basstate & BS_ATOPEN)) {
gig_dbg(DEBUG_OUTPUT, "AT channel not open");
rc = req_submit(cs->bcs, HD_OPEN_ATCHANNEL, 0, BAS_TIMEOUT);
if (rc < 0) {
spin_lock_irqsave(&cs->cmdlock, flags);
while (cs->cmdbuf != NULL)
complete_cb(cs);
spin_unlock_irqrestore(&cs->cmdlock, flags);
}
return rc;
}
spin_lock_irqsave(&cs->cmdlock, flags);
while ((cb = cs->cmdbuf) != NULL && (ucs->basstate & BS_ATREADY)) {
ucs->retry_cmd_out = 0;
rc = atwrite_submit(cs, cb->buf, cb->len);
if (unlikely(rc)) {
retval = rc;
complete_cb(cs);
}
}
spin_unlock_irqrestore(&cs->cmdlock, flags);
return retval;
}
static int gigaset_write_cmd(struct cardstate *cs, struct cmdbuf_t *cb)
{
unsigned long flags;
int rc;
gigaset_dbg_buffer(cs->mstate != MS_LOCKED ?
DEBUG_TRANSCMD : DEBUG_LOCKCMD,
"CMD Transmit", cb->len, cb->buf);
if (cb->len == 3 && !memcmp(cb->buf, "+++", 3)) {
spin_lock_irqsave(&cs->lock, flags);
if (!(cs->hw.bas->basstate & BS_ATRDPEND)) {
kfree(cs->hw.bas->rcvbuf);
cs->hw.bas->rcvbuf = NULL;
cs->hw.bas->rcvbuf_size = 0;
cs->hw.bas->retry_cmd_in = 0;
atread_submit(cs, 0);
}
spin_unlock_irqrestore(&cs->lock, flags);
rc = req_submit(cs->bcs, HD_CLOSE_ATCHANNEL, 0, BAS_TIMEOUT);
if (cb->wake_tasklet)
tasklet_schedule(cb->wake_tasklet);
if (!rc)
rc = cb->len;
kfree(cb);
return rc;
}
spin_lock_irqsave(&cs->cmdlock, flags);
cb->prev = cs->lastcmdbuf;
if (cs->lastcmdbuf)
cs->lastcmdbuf->next = cb;
else {
cs->cmdbuf = cb;
cs->curlen = cb->len;
}
cs->cmdbytes += cb->len;
cs->lastcmdbuf = cb;
spin_unlock_irqrestore(&cs->cmdlock, flags);
spin_lock_irqsave(&cs->lock, flags);
if (unlikely(!cs->connected)) {
spin_unlock_irqrestore(&cs->lock, flags);
gig_dbg(DEBUG_USBREQ, "%s: not connected", __func__);
spin_lock_irqsave(&cs->cmdlock, flags);
while (cs->cmdbuf != NULL)
complete_cb(cs);
spin_unlock_irqrestore(&cs->cmdlock, flags);
return -ENODEV;
}
rc = start_cbsend(cs);
spin_unlock_irqrestore(&cs->lock, flags);
return rc < 0 ? rc : cb->len;
}
static int gigaset_write_room(struct cardstate *cs)
{
return IF_WRITEBUF;
}
static int gigaset_chars_in_buffer(struct cardstate *cs)
{
return cs->cmdbytes;
}
static int gigaset_brkchars(struct cardstate *cs, const unsigned char buf[6])
{
return -EINVAL;
}
static void gigaset_freebcshw(struct bc_state *bcs)
{
struct bas_bc_state *ubc = bcs->hw.bas;
int i;
if (!ubc)
return;
ubc->running = 0;
gig_dbg(DEBUG_INIT, "%s: killing isoc URBs", __func__);
for (i = 0; i < BAS_OUTURBS; ++i) {
usb_kill_urb(ubc->isoouturbs[i].urb);
usb_free_urb(ubc->isoouturbs[i].urb);
}
for (i = 0; i < BAS_INURBS; ++i) {
usb_kill_urb(ubc->isoinurbs[i]);
usb_free_urb(ubc->isoinurbs[i]);
}
tasklet_kill(&ubc->sent_tasklet);
tasklet_kill(&ubc->rcvd_tasklet);
kfree(ubc->isooutbuf);
kfree(ubc);
bcs->hw.bas = NULL;
}
static int gigaset_initbcshw(struct bc_state *bcs)
{
int i;
struct bas_bc_state *ubc;
bcs->hw.bas = ubc = kmalloc(sizeof(struct bas_bc_state), GFP_KERNEL);
if (!ubc) {
pr_err("out of memory\n");
return -ENOMEM;
}
ubc->running = 0;
atomic_set(&ubc->corrbytes, 0);
spin_lock_init(&ubc->isooutlock);
for (i = 0; i < BAS_OUTURBS; ++i) {
ubc->isoouturbs[i].urb = NULL;
ubc->isoouturbs[i].bcs = bcs;
}
ubc->isooutdone = ubc->isooutfree = ubc->isooutovfl = NULL;
ubc->numsub = 0;
ubc->isooutbuf = kmalloc(sizeof(struct isowbuf_t), GFP_KERNEL);
if (!ubc->isooutbuf) {
pr_err("out of memory\n");
kfree(ubc);
bcs->hw.bas = NULL;
return -ENOMEM;
}
tasklet_init(&ubc->sent_tasklet,
write_iso_tasklet, (unsigned long) bcs);
spin_lock_init(&ubc->isoinlock);
for (i = 0; i < BAS_INURBS; ++i)
ubc->isoinurbs[i] = NULL;
ubc->isoindone = NULL;
ubc->loststatus = -EINPROGRESS;
ubc->isoinlost = 0;
ubc->seqlen = 0;
ubc->inbyte = 0;
ubc->inbits = 0;
ubc->goodbytes = 0;
ubc->alignerrs = 0;
ubc->fcserrs = 0;
ubc->frameerrs = 0;
ubc->giants = 0;
ubc->runts = 0;
ubc->aborts = 0;
ubc->shared0s = 0;
ubc->stolen0s = 0;
tasklet_init(&ubc->rcvd_tasklet,
read_iso_tasklet, (unsigned long) bcs);
return 0;
}
static void gigaset_reinitbcshw(struct bc_state *bcs)
{
struct bas_bc_state *ubc = bcs->hw.bas;
bcs->hw.bas->running = 0;
atomic_set(&bcs->hw.bas->corrbytes, 0);
bcs->hw.bas->numsub = 0;
spin_lock_init(&ubc->isooutlock);
spin_lock_init(&ubc->isoinlock);
ubc->loststatus = -EINPROGRESS;
}
static void gigaset_freecshw(struct cardstate *cs)
{
kfree(cs->hw.bas->int_in_buf);
kfree(cs->hw.bas);
cs->hw.bas = NULL;
}
static int gigaset_initcshw(struct cardstate *cs)
{
struct bas_cardstate *ucs;
cs->hw.bas = ucs = kmalloc(sizeof *ucs, GFP_KERNEL);
if (!ucs) {
pr_err("out of memory\n");
return -ENOMEM;
}
ucs->int_in_buf = kmalloc(IP_MSGSIZE, GFP_KERNEL);
if (!ucs->int_in_buf) {
kfree(ucs);
pr_err("out of memory\n");
return -ENOMEM;
}
ucs->urb_cmd_in = NULL;
ucs->urb_cmd_out = NULL;
ucs->rcvbuf = NULL;
ucs->rcvbuf_size = 0;
spin_lock_init(&ucs->lock);
ucs->pending = 0;
ucs->basstate = 0;
setup_timer(&ucs->timer_ctrl, req_timeout, (unsigned long) cs);
setup_timer(&ucs->timer_atrdy, atrdy_timeout, (unsigned long) cs);
setup_timer(&ucs->timer_cmd_in, cmd_in_timeout, (unsigned long) cs);
setup_timer(&ucs->timer_int_in, int_in_resubmit, (unsigned long) cs);
init_waitqueue_head(&ucs->waitqueue);
INIT_WORK(&ucs->int_in_wq, int_in_work);
return 0;
}
static void freeurbs(struct cardstate *cs)
{
struct bas_cardstate *ucs = cs->hw.bas;
struct bas_bc_state *ubc;
int i, j;
gig_dbg(DEBUG_INIT, "%s: killing URBs", __func__);
for (j = 0; j < BAS_CHANNELS; ++j) {
ubc = cs->bcs[j].hw.bas;
for (i = 0; i < BAS_OUTURBS; ++i) {
usb_kill_urb(ubc->isoouturbs[i].urb);
usb_free_urb(ubc->isoouturbs[i].urb);
ubc->isoouturbs[i].urb = NULL;
}
for (i = 0; i < BAS_INURBS; ++i) {
usb_kill_urb(ubc->isoinurbs[i]);
usb_free_urb(ubc->isoinurbs[i]);
ubc->isoinurbs[i] = NULL;
}
}
usb_kill_urb(ucs->urb_int_in);
usb_free_urb(ucs->urb_int_in);
ucs->urb_int_in = NULL;
usb_kill_urb(ucs->urb_cmd_out);
usb_free_urb(ucs->urb_cmd_out);
ucs->urb_cmd_out = NULL;
usb_kill_urb(ucs->urb_cmd_in);
usb_free_urb(ucs->urb_cmd_in);
ucs->urb_cmd_in = NULL;
usb_kill_urb(ucs->urb_ctrl);
usb_free_urb(ucs->urb_ctrl);
ucs->urb_ctrl = NULL;
}
static int gigaset_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_host_interface *hostif;
struct usb_device *udev = interface_to_usbdev(interface);
struct cardstate *cs = NULL;
struct bas_cardstate *ucs = NULL;
struct bas_bc_state *ubc;
struct usb_endpoint_descriptor *endpoint;
int i, j;
int rc;
gig_dbg(DEBUG_INIT,
"%s: Check if device matches .. (Vendor: 0x%x, Product: 0x%x)",
__func__, le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct));
hostif = interface->cur_altsetting;
if (hostif->desc.bAlternateSetting != 3) {
gig_dbg(DEBUG_INIT,
"%s: wrong alternate setting %d - trying to switch",
__func__, hostif->desc.bAlternateSetting);
if (usb_set_interface(udev, hostif->desc.bInterfaceNumber, 3)
< 0) {
dev_warn(&udev->dev, "usb_set_interface failed, "
"device %d interface %d altsetting %d\n",
udev->devnum, hostif->desc.bInterfaceNumber,
hostif->desc.bAlternateSetting);
return -ENODEV;
}
hostif = interface->cur_altsetting;
}
if (hostif->desc.bInterfaceClass != 255) {
dev_warn(&udev->dev, "%s: bInterfaceClass == %d\n",
__func__, hostif->desc.bInterfaceClass);
return -ENODEV;
}
dev_info(&udev->dev,
"%s: Device matched (Vendor: 0x%x, Product: 0x%x)\n",
__func__, le16_to_cpu(udev->descriptor.idVendor),
le16_to_cpu(udev->descriptor.idProduct));
cs = gigaset_initcs(driver, BAS_CHANNELS, 0, 0, cidmode,
GIGASET_MODULENAME);
if (!cs)
return -ENODEV;
ucs = cs->hw.bas;
usb_get_dev(udev);
ucs->udev = udev;
ucs->interface = interface;
cs->dev = &interface->dev;
if (!(ucs->urb_int_in = usb_alloc_urb(0, GFP_KERNEL)) ||
!(ucs->urb_cmd_in = usb_alloc_urb(0, GFP_KERNEL)) ||
!(ucs->urb_cmd_out = usb_alloc_urb(0, GFP_KERNEL)) ||
!(ucs->urb_ctrl = usb_alloc_urb(0, GFP_KERNEL)))
goto allocerr;
for (j = 0; j < BAS_CHANNELS; ++j) {
ubc = cs->bcs[j].hw.bas;
for (i = 0; i < BAS_OUTURBS; ++i)
if (!(ubc->isoouturbs[i].urb =
usb_alloc_urb(BAS_NUMFRAMES, GFP_KERNEL)))
goto allocerr;
for (i = 0; i < BAS_INURBS; ++i)
if (!(ubc->isoinurbs[i] =
usb_alloc_urb(BAS_NUMFRAMES, GFP_KERNEL)))
goto allocerr;
}
ucs->rcvbuf = NULL;
ucs->rcvbuf_size = 0;
endpoint = &hostif->endpoint[0].desc;
usb_fill_int_urb(ucs->urb_int_in, udev,
usb_rcvintpipe(udev,
usb_endpoint_num(endpoint)),
ucs->int_in_buf, IP_MSGSIZE, read_int_callback, cs,
endpoint->bInterval);
rc = usb_submit_urb(ucs->urb_int_in, GFP_KERNEL);
if (rc != 0) {
dev_err(cs->dev, "could not submit interrupt URB: %s\n",
get_usb_rcmsg(rc));
goto error;
}
ucs->retry_int_in = 0;
rc = req_submit(cs->bcs, HD_DEVICE_INIT_ACK, 0, 0);
if (rc != 0)
goto error;
if (startmode == SM_LOCKED)
cs->mstate = MS_LOCKED;
usb_set_intfdata(interface, cs);
rc = gigaset_start(cs);
if (rc < 0)
goto error;
return 0;
allocerr:
dev_err(cs->dev, "could not allocate URBs\n");
rc = -ENOMEM;
error:
freeurbs(cs);
usb_set_intfdata(interface, NULL);
usb_put_dev(udev);
gigaset_freecs(cs);
return rc;
}
static void gigaset_disconnect(struct usb_interface *interface)
{
struct cardstate *cs;
struct bas_cardstate *ucs;
int j;
cs = usb_get_intfdata(interface);
ucs = cs->hw.bas;
dev_info(cs->dev, "disconnecting Gigaset base\n");
ucs->basstate = 0;
for (j = 0; j < BAS_CHANNELS; ++j)
gigaset_bchannel_down(cs->bcs + j);
gigaset_stop(cs);
del_timer_sync(&ucs->timer_ctrl);
del_timer_sync(&ucs->timer_atrdy);
del_timer_sync(&ucs->timer_cmd_in);
del_timer_sync(&ucs->timer_int_in);
cancel_work_sync(&ucs->int_in_wq);
freeurbs(cs);
usb_set_intfdata(interface, NULL);
kfree(ucs->rcvbuf);
ucs->rcvbuf = NULL;
ucs->rcvbuf_size = 0;
usb_put_dev(ucs->udev);
ucs->interface = NULL;
ucs->udev = NULL;
cs->dev = NULL;
gigaset_freecs(cs);
}
static int gigaset_suspend(struct usb_interface *intf, pm_message_t message)
{
struct cardstate *cs = usb_get_intfdata(intf);
struct bas_cardstate *ucs = cs->hw.bas;
int rc;
if (update_basstate(ucs, BS_SUSPEND, 0) & BS_SUSPEND) {
gig_dbg(DEBUG_SUSPEND, "already suspended");
return 0;
}
rc = wait_event_timeout(ucs->waitqueue,
!(ucs->basstate &
(BS_B1OPEN | BS_B2OPEN | BS_ATRDPEND | BS_ATWRPEND)),
BAS_TIMEOUT * HZ / 10);
gig_dbg(DEBUG_SUSPEND, "wait_event_timeout() -> %d", rc);
if (ucs->basstate & (BS_B1OPEN | BS_B2OPEN | BS_ATRDPEND | BS_ATWRPEND)) {
dev_warn(cs->dev, "cannot suspend:\n");
if (ucs->basstate & BS_B1OPEN)
dev_warn(cs->dev, " B channel 1 open\n");
if (ucs->basstate & BS_B2OPEN)
dev_warn(cs->dev, " B channel 2 open\n");
if (ucs->basstate & BS_ATRDPEND)
dev_warn(cs->dev, " receiving AT reply\n");
if (ucs->basstate & BS_ATWRPEND)
dev_warn(cs->dev, " sending AT command\n");
update_basstate(ucs, 0, BS_SUSPEND);
return -EBUSY;
}
if (ucs->basstate & BS_ATOPEN) {
gig_dbg(DEBUG_SUSPEND, "closing AT channel");
rc = req_submit(cs->bcs, HD_CLOSE_ATCHANNEL, 0, 0);
if (rc) {
update_basstate(ucs, 0, BS_SUSPEND);
return rc;
}
wait_event_timeout(ucs->waitqueue, !ucs->pending,
BAS_TIMEOUT * HZ / 10);
}
usb_kill_urb(ucs->urb_ctrl);
usb_kill_urb(ucs->urb_int_in);
del_timer_sync(&ucs->timer_ctrl);
del_timer_sync(&ucs->timer_atrdy);
del_timer_sync(&ucs->timer_cmd_in);
del_timer_sync(&ucs->timer_int_in);
if (message.event != PM_EVENT_ON)
cancel_work_sync(&ucs->int_in_wq);
gig_dbg(DEBUG_SUSPEND, "suspend complete");
return 0;
}
static int gigaset_resume(struct usb_interface *intf)
{
struct cardstate *cs = usb_get_intfdata(intf);
struct bas_cardstate *ucs = cs->hw.bas;
int rc;
rc = usb_submit_urb(ucs->urb_int_in, GFP_KERNEL);
if (rc) {
dev_err(cs->dev, "could not resubmit interrupt URB: %s\n",
get_usb_rcmsg(rc));
return rc;
}
ucs->retry_int_in = 0;
update_basstate(ucs, 0, BS_SUSPEND);
gig_dbg(DEBUG_SUSPEND, "resume complete");
return 0;
}
static int gigaset_pre_reset(struct usb_interface *intf)
{
return gigaset_suspend(intf, PMSG_ON);
}
static int gigaset_post_reset(struct usb_interface *intf)
{
return gigaset_resume(intf);
}
static int __init bas_gigaset_init(void)
{
int result;
driver = gigaset_initdriver(GIGASET_MINOR, GIGASET_MINORS,
GIGASET_MODULENAME, GIGASET_DEVNAME,
&gigops, THIS_MODULE);
if (driver == NULL)
goto error;
result = usb_register(&gigaset_usb_driver);
if (result < 0) {
pr_err("error %d registering USB driver\n", -result);
goto error;
}
pr_info(DRIVER_DESC "\n");
return 0;
error:
if (driver)
gigaset_freedriver(driver);
driver = NULL;
return -1;
}
static void __exit bas_gigaset_exit(void)
{
struct bas_cardstate *ucs;
int i;
gigaset_blockdriver(driver);
for (i = 0; i < driver->minors; i++) {
if (gigaset_shutdown(driver->cs + i) < 0)
continue;
ucs = driver->cs[i].hw.bas;
if (ucs->basstate & BS_B1OPEN) {
gig_dbg(DEBUG_INIT, "closing B1 channel");
usb_control_msg(ucs->udev,
usb_sndctrlpipe(ucs->udev, 0),
HD_CLOSE_B1CHANNEL, OUT_VENDOR_REQ,
0, 0, NULL, 0, BAS_TIMEOUT);
}
if (ucs->basstate & BS_B2OPEN) {
gig_dbg(DEBUG_INIT, "closing B2 channel");
usb_control_msg(ucs->udev,
usb_sndctrlpipe(ucs->udev, 0),
HD_CLOSE_B2CHANNEL, OUT_VENDOR_REQ,
0, 0, NULL, 0, BAS_TIMEOUT);
}
if (ucs->basstate & BS_ATOPEN) {
gig_dbg(DEBUG_INIT, "closing AT channel");
usb_control_msg(ucs->udev,
usb_sndctrlpipe(ucs->udev, 0),
HD_CLOSE_ATCHANNEL, OUT_VENDOR_REQ,
0, 0, NULL, 0, BAS_TIMEOUT);
}
ucs->basstate = 0;
}
usb_deregister(&gigaset_usb_driver);
gigaset_freedriver(driver);
driver = NULL;
}
