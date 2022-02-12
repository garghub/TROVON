static inline s16
frame_diff(u16 left, u16 right)
{
return ((unsigned) (left - right)) % (USB_MAX_FRAME_NUMBER + 1);
}
static inline struct max3421_hcd *
hcd_to_max3421(struct usb_hcd *hcd)
{
return (struct max3421_hcd *) hcd->hcd_priv;
}
static inline struct usb_hcd *
max3421_to_hcd(struct max3421_hcd *max3421_hcd)
{
return container_of((void *) max3421_hcd, struct usb_hcd, hcd_priv);
}
static u8
spi_rd8(struct usb_hcd *hcd, unsigned int reg)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct spi_transfer transfer;
struct spi_message msg;
memset(&transfer, 0, sizeof(transfer));
spi_message_init(&msg);
max3421_hcd->tx->data[0] =
(field(reg, MAX3421_SPI_REG_SHIFT) |
field(MAX3421_SPI_DIR_RD, MAX3421_SPI_DIR_SHIFT));
transfer.tx_buf = max3421_hcd->tx->data;
transfer.rx_buf = max3421_hcd->rx->data;
transfer.len = 2;
spi_message_add_tail(&transfer, &msg);
spi_sync(spi, &msg);
return max3421_hcd->rx->data[1];
}
static void
spi_wr8(struct usb_hcd *hcd, unsigned int reg, u8 val)
{
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
struct spi_transfer transfer;
struct spi_message msg;
memset(&transfer, 0, sizeof(transfer));
spi_message_init(&msg);
max3421_hcd->tx->data[0] =
(field(reg, MAX3421_SPI_REG_SHIFT) |
field(MAX3421_SPI_DIR_WR, MAX3421_SPI_DIR_SHIFT));
max3421_hcd->tx->data[1] = val;
transfer.tx_buf = max3421_hcd->tx->data;
transfer.len = 2;
spi_message_add_tail(&transfer, &msg);
spi_sync(spi, &msg);
}
static void
spi_rd_buf(struct usb_hcd *hcd, unsigned int reg, void *buf, size_t len)
{
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
struct spi_transfer transfer[2];
struct spi_message msg;
memset(transfer, 0, sizeof(transfer));
spi_message_init(&msg);
max3421_hcd->tx->data[0] =
(field(reg, MAX3421_SPI_REG_SHIFT) |
field(MAX3421_SPI_DIR_RD, MAX3421_SPI_DIR_SHIFT));
transfer[0].tx_buf = max3421_hcd->tx->data;
transfer[0].len = 1;
transfer[1].rx_buf = buf;
transfer[1].len = len;
spi_message_add_tail(&transfer[0], &msg);
spi_message_add_tail(&transfer[1], &msg);
spi_sync(spi, &msg);
}
static void
spi_wr_buf(struct usb_hcd *hcd, unsigned int reg, void *buf, size_t len)
{
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
struct spi_transfer transfer[2];
struct spi_message msg;
memset(transfer, 0, sizeof(transfer));
spi_message_init(&msg);
max3421_hcd->tx->data[0] =
(field(reg, MAX3421_SPI_REG_SHIFT) |
field(MAX3421_SPI_DIR_WR, MAX3421_SPI_DIR_SHIFT));
transfer[0].tx_buf = max3421_hcd->tx->data;
transfer[0].len = 1;
transfer[1].tx_buf = buf;
transfer[1].len = len;
spi_message_add_tail(&transfer[0], &msg);
spi_message_add_tail(&transfer[1], &msg);
spi_sync(spi, &msg);
}
static void
max3421_set_speed(struct usb_hcd *hcd, struct usb_device *dev)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
u8 mode_lowspeed, mode_hubpre, mode = max3421_hcd->mode;
mode_lowspeed = BIT(MAX3421_MODE_LOWSPEED_BIT);
mode_hubpre = BIT(MAX3421_MODE_HUBPRE_BIT);
if (max3421_hcd->port_status & USB_PORT_STAT_LOW_SPEED) {
mode |= mode_lowspeed;
mode &= ~mode_hubpre;
} else if (dev->speed == USB_SPEED_LOW) {
mode |= mode_lowspeed | mode_hubpre;
} else {
mode &= ~(mode_lowspeed | mode_hubpre);
}
if (mode != max3421_hcd->mode) {
max3421_hcd->mode = mode;
spi_wr8(hcd, MAX3421_REG_MODE, max3421_hcd->mode);
}
}
static void
max3421_set_address(struct usb_hcd *hcd, struct usb_device *dev, int epnum,
int force_toggles)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
int old_epnum, same_ep, rcvtog, sndtog;
struct usb_device *old_dev;
u8 hctl;
old_dev = max3421_hcd->loaded_dev;
old_epnum = max3421_hcd->loaded_epnum;
same_ep = (dev == old_dev && epnum == old_epnum);
if (same_ep && !force_toggles)
return;
if (old_dev && !same_ep) {
u8 hrsl = spi_rd8(hcd, MAX3421_REG_HRSL);
rcvtog = (hrsl >> MAX3421_HRSL_RCVTOGRD_BIT) & 1;
sndtog = (hrsl >> MAX3421_HRSL_SNDTOGRD_BIT) & 1;
usb_settoggle(old_dev, old_epnum, 0, rcvtog);
usb_settoggle(old_dev, old_epnum, 1, sndtog);
}
rcvtog = usb_gettoggle(dev, epnum, 0);
sndtog = usb_gettoggle(dev, epnum, 1);
hctl = (BIT(rcvtog + MAX3421_HCTL_RCVTOG0_BIT) |
BIT(sndtog + MAX3421_HCTL_SNDTOG0_BIT));
max3421_hcd->loaded_epnum = epnum;
spi_wr8(hcd, MAX3421_REG_HCTL, hctl);
max3421_hcd->loaded_dev = dev;
spi_wr8(hcd, MAX3421_REG_PERADDR, dev->devnum);
}
static int
max3421_ctrl_setup(struct usb_hcd *hcd, struct urb *urb)
{
spi_wr_buf(hcd, MAX3421_REG_SUDFIFO, urb->setup_packet, 8);
return MAX3421_HXFR_SETUP;
}
static int
max3421_transfer_in(struct usb_hcd *hcd, struct urb *urb)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
int epnum = usb_pipeendpoint(urb->pipe);
max3421_hcd->curr_len = 0;
max3421_hcd->hien |= BIT(MAX3421_HI_RCVDAV_BIT);
return MAX3421_HXFR_BULK_IN(epnum);
}
static int
max3421_transfer_out(struct usb_hcd *hcd, struct urb *urb, int fast_retransmit)
{
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
int epnum = usb_pipeendpoint(urb->pipe);
u32 max_packet;
void *src;
src = urb->transfer_buffer + urb->actual_length;
if (fast_retransmit) {
if (max3421_hcd->rev == 0x12) {
spi_wr8(hcd, MAX3421_REG_SNDBC, 0);
spi_wr8(hcd, MAX3421_REG_SNDFIFO, ((u8 *) src)[0]);
spi_wr8(hcd, MAX3421_REG_SNDBC, max3421_hcd->curr_len);
}
return MAX3421_HXFR_BULK_OUT(epnum);
}
max_packet = usb_maxpacket(urb->dev, urb->pipe, 1);
if (max_packet > MAX3421_FIFO_SIZE) {
dev_err(&spi->dev,
"%s: packet-size of %u too big (limit is %u bytes)",
__func__, max_packet, MAX3421_FIFO_SIZE);
max3421_hcd->urb_done = -EMSGSIZE;
return -EMSGSIZE;
}
max3421_hcd->curr_len = min((urb->transfer_buffer_length -
urb->actual_length), max_packet);
spi_wr_buf(hcd, MAX3421_REG_SNDFIFO, src, max3421_hcd->curr_len);
spi_wr8(hcd, MAX3421_REG_SNDBC, max3421_hcd->curr_len);
return MAX3421_HXFR_BULK_OUT(epnum);
}
static void
max3421_next_transfer(struct usb_hcd *hcd, int fast_retransmit)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
struct urb *urb = max3421_hcd->curr_urb;
struct max3421_ep *max3421_ep;
int cmd = -EINVAL;
if (!urb)
return;
max3421_ep = urb->ep->hcpriv;
switch (max3421_ep->pkt_state) {
case PKT_STATE_SETUP:
cmd = max3421_ctrl_setup(hcd, urb);
break;
case PKT_STATE_TRANSFER:
if (usb_urb_dir_in(urb))
cmd = max3421_transfer_in(hcd, urb);
else
cmd = max3421_transfer_out(hcd, urb, fast_retransmit);
break;
case PKT_STATE_TERMINATE:
if (usb_urb_dir_in(urb))
cmd = MAX3421_HXFR_HS_OUT;
else
cmd = MAX3421_HXFR_HS_IN;
break;
}
if (cmd < 0)
return;
spi_wr8(hcd, MAX3421_REG_HXFR, cmd);
max3421_hcd->hien |= BIT(MAX3421_HI_HXFRDN_BIT);
}
static int
max3421_select_and_start_urb(struct usb_hcd *hcd)
{
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
struct urb *urb, *curr_urb = NULL;
struct max3421_ep *max3421_ep;
int epnum, force_toggles = 0;
struct usb_host_endpoint *ep;
struct list_head *pos;
unsigned long flags;
spin_lock_irqsave(&max3421_hcd->lock, flags);
for (;
max3421_hcd->sched_pass < SCHED_PASS_DONE;
++max3421_hcd->sched_pass)
list_for_each(pos, &max3421_hcd->ep_list) {
urb = NULL;
max3421_ep = container_of(pos, struct max3421_ep,
ep_list);
ep = max3421_ep->ep;
switch (usb_endpoint_type(&ep->desc)) {
case USB_ENDPOINT_XFER_ISOC:
case USB_ENDPOINT_XFER_INT:
if (max3421_hcd->sched_pass !=
SCHED_PASS_PERIODIC)
continue;
break;
case USB_ENDPOINT_XFER_CONTROL:
case USB_ENDPOINT_XFER_BULK:
if (max3421_hcd->sched_pass !=
SCHED_PASS_NON_PERIODIC)
continue;
break;
}
if (list_empty(&ep->urb_list))
continue;
urb = list_first_entry(&ep->urb_list, struct urb,
urb_list);
if (urb->unlinked) {
dev_dbg(&spi->dev, "%s: URB %p unlinked=%d",
__func__, urb, urb->unlinked);
max3421_hcd->curr_urb = urb;
max3421_hcd->urb_done = 1;
spin_unlock_irqrestore(&max3421_hcd->lock,
flags);
return 1;
}
switch (usb_endpoint_type(&ep->desc)) {
case USB_ENDPOINT_XFER_CONTROL:
if (frame_diff(max3421_ep->last_active,
max3421_hcd->frame_number) == 0)
continue;
break;
case USB_ENDPOINT_XFER_BULK:
if (max3421_ep->retransmit
&& (frame_diff(max3421_ep->last_active,
max3421_hcd->frame_number)
== 0))
continue;
break;
case USB_ENDPOINT_XFER_ISOC:
case USB_ENDPOINT_XFER_INT:
if (frame_diff(max3421_hcd->frame_number,
max3421_ep->last_active)
< urb->interval)
continue;
break;
}
list_move_tail(pos, &max3421_hcd->ep_list);
curr_urb = urb;
goto done;
}
done:
if (!curr_urb) {
spin_unlock_irqrestore(&max3421_hcd->lock, flags);
return 0;
}
urb = max3421_hcd->curr_urb = curr_urb;
epnum = usb_endpoint_num(&urb->ep->desc);
if (max3421_ep->retransmit)
max3421_ep->retransmit = 0;
else {
if (usb_endpoint_xfer_control(&ep->desc)) {
usb_settoggle(urb->dev, epnum, 0, 1);
usb_settoggle(urb->dev, epnum, 1, 1);
max3421_ep->pkt_state = PKT_STATE_SETUP;
force_toggles = 1;
} else
max3421_ep->pkt_state = PKT_STATE_TRANSFER;
}
spin_unlock_irqrestore(&max3421_hcd->lock, flags);
max3421_ep->last_active = max3421_hcd->frame_number;
max3421_set_address(hcd, urb->dev, epnum, force_toggles);
max3421_set_speed(hcd, urb->dev);
max3421_next_transfer(hcd, 0);
return 1;
}
static int
max3421_check_unlink(struct usb_hcd *hcd)
{
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
struct max3421_ep *max3421_ep;
struct usb_host_endpoint *ep;
struct urb *urb, *next;
unsigned long flags;
int retval = 0;
spin_lock_irqsave(&max3421_hcd->lock, flags);
list_for_each_entry(max3421_ep, &max3421_hcd->ep_list, ep_list) {
ep = max3421_ep->ep;
list_for_each_entry_safe(urb, next, &ep->urb_list, urb_list) {
if (urb->unlinked) {
retval = 1;
dev_dbg(&spi->dev, "%s: URB %p unlinked=%d",
__func__, urb, urb->unlinked);
usb_hcd_unlink_urb_from_ep(hcd, urb);
spin_unlock_irqrestore(&max3421_hcd->lock,
flags);
usb_hcd_giveback_urb(hcd, urb, 0);
spin_lock_irqsave(&max3421_hcd->lock, flags);
}
}
}
spin_unlock_irqrestore(&max3421_hcd->lock, flags);
return retval;
}
static void
max3421_slow_retransmit(struct usb_hcd *hcd)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
struct urb *urb = max3421_hcd->curr_urb;
struct max3421_ep *max3421_ep;
max3421_ep = urb->ep->hcpriv;
max3421_ep->retransmit = 1;
max3421_hcd->curr_urb = NULL;
}
static void
max3421_recv_data_available(struct usb_hcd *hcd)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
struct urb *urb = max3421_hcd->curr_urb;
size_t remaining, transfer_size;
u8 rcvbc;
rcvbc = spi_rd8(hcd, MAX3421_REG_RCVBC);
if (rcvbc > MAX3421_FIFO_SIZE)
rcvbc = MAX3421_FIFO_SIZE;
if (urb->actual_length >= urb->transfer_buffer_length)
remaining = 0;
else
remaining = urb->transfer_buffer_length - urb->actual_length;
transfer_size = rcvbc;
if (transfer_size > remaining)
transfer_size = remaining;
if (transfer_size > 0) {
void *dst = urb->transfer_buffer + urb->actual_length;
spi_rd_buf(hcd, MAX3421_REG_RCVFIFO, dst, transfer_size);
urb->actual_length += transfer_size;
max3421_hcd->curr_len = transfer_size;
}
spi_wr8(hcd, MAX3421_REG_HIRQ, BIT(MAX3421_HI_RCVDAV_BIT));
}
static void
max3421_handle_error(struct usb_hcd *hcd, u8 hrsl)
{
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
u8 result_code = hrsl & MAX3421_HRSL_RESULT_MASK;
struct urb *urb = max3421_hcd->curr_urb;
struct max3421_ep *max3421_ep = urb->ep->hcpriv;
int switch_sndfifo;
switch_sndfifo = (max3421_ep->pkt_state == PKT_STATE_TRANSFER &&
usb_urb_dir_out(urb));
switch (result_code) {
case MAX3421_HRSL_OK:
return;
case MAX3421_HRSL_WRONGPID:
case MAX3421_HRSL_BUSY:
case MAX3421_HRSL_BADREQ:
case MAX3421_HRSL_UNDEF:
case MAX3421_HRSL_KERR:
case MAX3421_HRSL_JERR:
max3421_hcd->urb_done = hrsl_to_error[result_code];
dev_dbg(&spi->dev, "%s: unexpected error HRSL=0x%02x",
__func__, hrsl);
break;
case MAX3421_HRSL_TOGERR:
if (usb_urb_dir_in(urb))
;
else {
int sndtog = (hrsl >> MAX3421_HRSL_SNDTOGRD_BIT) & 1;
sndtog ^= 1;
spi_wr8(hcd, MAX3421_REG_HCTL,
BIT(sndtog + MAX3421_HCTL_SNDTOG0_BIT));
}
case MAX3421_HRSL_BADBC:
case MAX3421_HRSL_PIDERR:
case MAX3421_HRSL_PKTERR:
case MAX3421_HRSL_CRCERR:
case MAX3421_HRSL_BABBLE:
case MAX3421_HRSL_TIMEOUT:
if (max3421_ep->retries++ < USB_MAX_RETRIES)
max3421_slow_retransmit(hcd);
else {
max3421_hcd->urb_done = hrsl_to_error[result_code];
dev_dbg(&spi->dev, "%s: unexpected error HRSL=0x%02x",
__func__, hrsl);
}
break;
case MAX3421_HRSL_STALL:
dev_dbg(&spi->dev, "%s: unexpected error HRSL=0x%02x",
__func__, hrsl);
max3421_hcd->urb_done = hrsl_to_error[result_code];
break;
case MAX3421_HRSL_NAK:
if (max3421_ep->naks++ < NAK_MAX_FAST_RETRANSMITS) {
max3421_next_transfer(hcd, 1);
switch_sndfifo = 0;
} else
max3421_slow_retransmit(hcd);
break;
}
if (switch_sndfifo)
spi_wr8(hcd, MAX3421_REG_SNDBC, 0);
}
static int
max3421_transfer_in_done(struct usb_hcd *hcd, struct urb *urb)
{
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
u32 max_packet;
if (urb->actual_length >= urb->transfer_buffer_length)
return 1;
max_packet = usb_maxpacket(urb->dev, urb->pipe, 0);
if (max_packet > MAX3421_FIFO_SIZE) {
dev_err(&spi->dev,
"%s: packet-size of %u too big (limit is %u bytes)",
__func__, max_packet, MAX3421_FIFO_SIZE);
return -EINVAL;
}
if (max3421_hcd->curr_len < max_packet) {
if (urb->transfer_flags & URB_SHORT_NOT_OK) {
return -EREMOTEIO;
} else
return 1;
}
return 0;
}
static int
max3421_transfer_out_done(struct usb_hcd *hcd, struct urb *urb)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
urb->actual_length += max3421_hcd->curr_len;
if (urb->actual_length < urb->transfer_buffer_length)
return 0;
if (urb->transfer_flags & URB_ZERO_PACKET) {
u32 max_packet = usb_maxpacket(urb->dev, urb->pipe, 1);
if (max3421_hcd->curr_len == max_packet)
return 0;
}
return 1;
}
static void
max3421_host_transfer_done(struct usb_hcd *hcd)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
struct urb *urb = max3421_hcd->curr_urb;
struct max3421_ep *max3421_ep;
u8 result_code, hrsl;
int urb_done = 0;
max3421_hcd->hien &= ~(BIT(MAX3421_HI_HXFRDN_BIT) |
BIT(MAX3421_HI_RCVDAV_BIT));
hrsl = spi_rd8(hcd, MAX3421_REG_HRSL);
result_code = hrsl & MAX3421_HRSL_RESULT_MASK;
#ifdef DEBUG
++max3421_hcd->err_stat[result_code];
#endif
max3421_ep = urb->ep->hcpriv;
if (unlikely(result_code != MAX3421_HRSL_OK)) {
max3421_handle_error(hcd, hrsl);
return;
}
max3421_ep->naks = 0;
max3421_ep->retries = 0;
switch (max3421_ep->pkt_state) {
case PKT_STATE_SETUP:
if (urb->transfer_buffer_length > 0)
max3421_ep->pkt_state = PKT_STATE_TRANSFER;
else
max3421_ep->pkt_state = PKT_STATE_TERMINATE;
break;
case PKT_STATE_TRANSFER:
if (usb_urb_dir_in(urb))
urb_done = max3421_transfer_in_done(hcd, urb);
else
urb_done = max3421_transfer_out_done(hcd, urb);
if (urb_done > 0 && usb_pipetype(urb->pipe) == PIPE_CONTROL) {
max3421_hcd->urb_done = urb_done = 0;
max3421_ep->pkt_state = PKT_STATE_TERMINATE;
}
break;
case PKT_STATE_TERMINATE:
urb_done = 1;
break;
}
if (urb_done)
max3421_hcd->urb_done = urb_done;
else
max3421_next_transfer(hcd, 0);
}
static void
max3421_detect_conn(struct usb_hcd *hcd)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
unsigned int jk, have_conn = 0;
u32 old_port_status, chg;
unsigned long flags;
u8 hrsl, mode;
hrsl = spi_rd8(hcd, MAX3421_REG_HRSL);
jk = ((((hrsl >> MAX3421_HRSL_JSTATUS_BIT) & 1) << 0) |
(((hrsl >> MAX3421_HRSL_KSTATUS_BIT) & 1) << 1));
mode = max3421_hcd->mode;
switch (jk) {
case 0x0:
mode &= ~BIT(MAX3421_MODE_SOFKAENAB_BIT);
break;
case 0x1:
case 0x2:
if (jk == 0x2)
mode ^= BIT(MAX3421_MODE_LOWSPEED_BIT);
mode |= BIT(MAX3421_MODE_SOFKAENAB_BIT);
have_conn = 1;
break;
case 0x3:
break;
}
max3421_hcd->mode = mode;
spi_wr8(hcd, MAX3421_REG_MODE, max3421_hcd->mode);
spin_lock_irqsave(&max3421_hcd->lock, flags);
old_port_status = max3421_hcd->port_status;
if (have_conn)
max3421_hcd->port_status |= USB_PORT_STAT_CONNECTION;
else
max3421_hcd->port_status &= ~USB_PORT_STAT_CONNECTION;
if (mode & BIT(MAX3421_MODE_LOWSPEED_BIT))
max3421_hcd->port_status |= USB_PORT_STAT_LOW_SPEED;
else
max3421_hcd->port_status &= ~USB_PORT_STAT_LOW_SPEED;
chg = (old_port_status ^ max3421_hcd->port_status);
max3421_hcd->port_status |= chg << 16;
spin_unlock_irqrestore(&max3421_hcd->lock, flags);
}
static irqreturn_t
max3421_irq_handler(int irq, void *dev_id)
{
struct usb_hcd *hcd = dev_id;
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
if (max3421_hcd->spi_thread &&
max3421_hcd->spi_thread->state != TASK_RUNNING)
wake_up_process(max3421_hcd->spi_thread);
if (!test_and_set_bit(ENABLE_IRQ, &max3421_hcd->todo))
disable_irq_nosync(spi->irq);
return IRQ_HANDLED;
}
static void
dump_eps(struct usb_hcd *hcd)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
struct max3421_ep *max3421_ep;
struct usb_host_endpoint *ep;
char ubuf[512], *dp, *end;
unsigned long flags;
struct urb *urb;
int epnum, ret;
spin_lock_irqsave(&max3421_hcd->lock, flags);
list_for_each_entry(max3421_ep, &max3421_hcd->ep_list, ep_list) {
ep = max3421_ep->ep;
dp = ubuf;
end = dp + sizeof(ubuf);
*dp = '\0';
list_for_each_entry(urb, &ep->urb_list, urb_list) {
ret = snprintf(dp, end - dp, " %p(%d.%s %d/%d)", urb,
usb_pipetype(urb->pipe),
usb_urb_dir_in(urb) ? "IN" : "OUT",
urb->actual_length,
urb->transfer_buffer_length);
if (ret < 0 || ret >= end - dp)
break;
dp += ret;
}
epnum = usb_endpoint_num(&ep->desc);
pr_info("EP%0u %u lst %04u rtr %u nak %6u rxmt %u: %s\n",
epnum, max3421_ep->pkt_state, max3421_ep->last_active,
max3421_ep->retries, max3421_ep->naks,
max3421_ep->retransmit, ubuf);
}
spin_unlock_irqrestore(&max3421_hcd->lock, flags);
}
static int
max3421_handle_irqs(struct usb_hcd *hcd)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
u32 chg, old_port_status;
unsigned long flags;
u8 hirq;
hirq = spi_rd8(hcd, MAX3421_REG_HIRQ);
hirq &= max3421_hcd->hien;
if (!hirq)
return 0;
spi_wr8(hcd, MAX3421_REG_HIRQ,
hirq & ~(BIT(MAX3421_HI_SNDBAV_BIT) |
BIT(MAX3421_HI_RCVDAV_BIT)));
if (hirq & BIT(MAX3421_HI_FRAME_BIT)) {
max3421_hcd->frame_number = ((max3421_hcd->frame_number + 1)
& USB_MAX_FRAME_NUMBER);
max3421_hcd->sched_pass = SCHED_PASS_PERIODIC;
}
if (hirq & BIT(MAX3421_HI_RCVDAV_BIT))
max3421_recv_data_available(hcd);
if (hirq & BIT(MAX3421_HI_HXFRDN_BIT))
max3421_host_transfer_done(hcd);
if (hirq & BIT(MAX3421_HI_CONDET_BIT))
max3421_detect_conn(hcd);
spin_lock_irqsave(&max3421_hcd->lock, flags);
old_port_status = max3421_hcd->port_status;
if (hirq & BIT(MAX3421_HI_BUSEVENT_BIT)) {
if (max3421_hcd->port_status & USB_PORT_STAT_RESET) {
max3421_hcd->port_status &= ~USB_PORT_STAT_RESET;
max3421_hcd->port_status |= USB_PORT_STAT_ENABLE;
} else {
pr_info("%s: BUSEVENT Bus Resume Done\n", __func__);
}
}
if (hirq & BIT(MAX3421_HI_RWU_BIT))
pr_info("%s: RWU\n", __func__);
if (hirq & BIT(MAX3421_HI_SUSDN_BIT))
pr_info("%s: SUSDN\n", __func__);
chg = (old_port_status ^ max3421_hcd->port_status);
max3421_hcd->port_status |= chg << 16;
spin_unlock_irqrestore(&max3421_hcd->lock, flags);
#ifdef DEBUG
{
static unsigned long last_time;
char sbuf[16 * 16], *dp, *end;
int i;
if (time_after(jiffies, last_time + 5*HZ)) {
dp = sbuf;
end = sbuf + sizeof(sbuf);
*dp = '\0';
for (i = 0; i < 16; ++i) {
int ret = snprintf(dp, end - dp, " %lu",
max3421_hcd->err_stat[i]);
if (ret < 0 || ret >= end - dp)
break;
dp += ret;
}
pr_info("%s: hrsl_stats %s\n", __func__, sbuf);
memset(max3421_hcd->err_stat, 0,
sizeof(max3421_hcd->err_stat));
last_time = jiffies;
dump_eps(hcd);
}
}
#endif
return 1;
}
static int
max3421_reset_hcd(struct usb_hcd *hcd)
{
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
int timeout;
spi_wr8(hcd, MAX3421_REG_USBCTL, BIT(MAX3421_USBCTL_CHIPRES_BIT));
spi_wr8(hcd, MAX3421_REG_USBCTL, 0);
timeout = 1000;
while (1) {
if (spi_rd8(hcd, MAX3421_REG_USBIRQ)
& BIT(MAX3421_USBIRQ_OSCOKIRQ_BIT))
break;
if (--timeout < 0) {
dev_err(&spi->dev,
"timed out waiting for oscillator OK signal");
return 1;
}
cond_resched();
}
max3421_hcd->mode = (BIT(MAX3421_MODE_HOST_BIT) |
BIT(MAX3421_MODE_SOFKAENAB_BIT) |
BIT(MAX3421_MODE_DMPULLDN_BIT) |
BIT(MAX3421_MODE_DPPULLDN_BIT));
spi_wr8(hcd, MAX3421_REG_MODE, max3421_hcd->mode);
max3421_hcd->frame_number = USB_MAX_FRAME_NUMBER;
spi_wr8(hcd, MAX3421_REG_HCTL, BIT(MAX3421_HCTL_FRMRST_BIT));
spi_wr8(hcd, MAX3421_REG_HCTL, BIT(MAX3421_HCTL_SAMPLEBUS_BIT));
max3421_detect_conn(hcd);
max3421_hcd->hien = (BIT(MAX3421_HI_FRAME_BIT) |
BIT(MAX3421_HI_CONDET_BIT) |
BIT(MAX3421_HI_BUSEVENT_BIT));
spi_wr8(hcd, MAX3421_REG_HIEN, max3421_hcd->hien);
spi_wr8(hcd, MAX3421_REG_CPUCTL, BIT(MAX3421_CPUCTL_IE_BIT));
return 1;
}
static int
max3421_urb_done(struct usb_hcd *hcd)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
unsigned long flags;
struct urb *urb;
int status;
status = max3421_hcd->urb_done;
max3421_hcd->urb_done = 0;
if (status > 0)
status = 0;
urb = max3421_hcd->curr_urb;
if (urb) {
max3421_hcd->curr_urb = NULL;
spin_lock_irqsave(&max3421_hcd->lock, flags);
usb_hcd_unlink_urb_from_ep(hcd, urb);
spin_unlock_irqrestore(&max3421_hcd->lock, flags);
usb_hcd_giveback_urb(hcd, urb, status);
}
return 1;
}
static int
max3421_spi_thread(void *dev_id)
{
struct usb_hcd *hcd = dev_id;
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
int i, i_worked = 1;
spi_wr8(hcd, MAX3421_REG_PINCTL,
(BIT(MAX3421_PINCTL_FDUPSPI_BIT) |
BIT(MAX3421_PINCTL_INTLEVEL_BIT)));
while (!kthread_should_stop()) {
max3421_hcd->rev = spi_rd8(hcd, MAX3421_REG_REVISION);
if (max3421_hcd->rev == 0x12 || max3421_hcd->rev == 0x13)
break;
dev_err(&spi->dev, "bad rev 0x%02x", max3421_hcd->rev);
msleep(10000);
}
dev_info(&spi->dev, "rev 0x%x, SPI clk %dHz, bpw %u, irq %d\n",
max3421_hcd->rev, spi->max_speed_hz, spi->bits_per_word,
spi->irq);
while (!kthread_should_stop()) {
if (!i_worked) {
spi_wr8(hcd, MAX3421_REG_HIEN, max3421_hcd->hien);
set_current_state(TASK_INTERRUPTIBLE);
if (test_and_clear_bit(ENABLE_IRQ, &max3421_hcd->todo))
enable_irq(spi->irq);
schedule();
__set_current_state(TASK_RUNNING);
}
i_worked = 0;
if (max3421_hcd->urb_done)
i_worked |= max3421_urb_done(hcd);
else if (max3421_handle_irqs(hcd))
i_worked = 1;
else if (!max3421_hcd->curr_urb)
i_worked |= max3421_select_and_start_urb(hcd);
if (test_and_clear_bit(RESET_HCD, &max3421_hcd->todo))
i_worked |= max3421_reset_hcd(hcd);
if (test_and_clear_bit(RESET_PORT, &max3421_hcd->todo)) {
spi_wr8(hcd, MAX3421_REG_HCTL,
BIT(MAX3421_HCTL_BUSRST_BIT));
i_worked = 1;
}
if (test_and_clear_bit(CHECK_UNLINK, &max3421_hcd->todo))
i_worked |= max3421_check_unlink(hcd);
if (test_and_clear_bit(IOPIN_UPDATE, &max3421_hcd->todo)) {
for (i = 0; i < ARRAY_SIZE(max3421_hcd->iopins); ++i) {
u8 val = spi_rd8(hcd, MAX3421_REG_IOPINS1);
val = ((val & 0xf0) |
(max3421_hcd->iopins[i] & 0x0f));
spi_wr8(hcd, MAX3421_REG_IOPINS1 + i, val);
max3421_hcd->iopins[i] = val;
}
i_worked = 1;
}
}
set_current_state(TASK_RUNNING);
dev_info(&spi->dev, "SPI thread exiting");
return 0;
}
static int
max3421_reset_port(struct usb_hcd *hcd)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
max3421_hcd->port_status &= ~(USB_PORT_STAT_ENABLE |
USB_PORT_STAT_LOW_SPEED);
max3421_hcd->port_status |= USB_PORT_STAT_RESET;
set_bit(RESET_PORT, &max3421_hcd->todo);
wake_up_process(max3421_hcd->spi_thread);
return 0;
}
static int
max3421_reset(struct usb_hcd *hcd)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
hcd->self.sg_tablesize = 0;
hcd->speed = HCD_USB2;
hcd->self.root_hub->speed = USB_SPEED_FULL;
set_bit(RESET_HCD, &max3421_hcd->todo);
wake_up_process(max3421_hcd->spi_thread);
return 0;
}
static int
max3421_start(struct usb_hcd *hcd)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
spin_lock_init(&max3421_hcd->lock);
max3421_hcd->rh_state = MAX3421_RH_RUNNING;
INIT_LIST_HEAD(&max3421_hcd->ep_list);
hcd->power_budget = POWER_BUDGET;
hcd->state = HC_STATE_RUNNING;
hcd->uses_new_polling = 1;
return 0;
}
static void
max3421_stop(struct usb_hcd *hcd)
{
}
static int
max3421_urb_enqueue(struct usb_hcd *hcd, struct urb *urb, gfp_t mem_flags)
{
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
struct max3421_ep *max3421_ep;
unsigned long flags;
int retval;
switch (usb_pipetype(urb->pipe)) {
case PIPE_INTERRUPT:
case PIPE_ISOCHRONOUS:
if (urb->interval < 0) {
dev_err(&spi->dev,
"%s: interval=%d for intr-/iso-pipe; expected > 0\n",
__func__, urb->interval);
return -EINVAL;
}
default:
break;
}
spin_lock_irqsave(&max3421_hcd->lock, flags);
max3421_ep = urb->ep->hcpriv;
if (!max3421_ep) {
max3421_ep = kzalloc(sizeof(struct max3421_ep), GFP_ATOMIC);
if (!max3421_ep) {
retval = -ENOMEM;
goto out;
}
max3421_ep->ep = urb->ep;
max3421_ep->last_active = max3421_hcd->frame_number;
urb->ep->hcpriv = max3421_ep;
list_add_tail(&max3421_ep->ep_list, &max3421_hcd->ep_list);
}
retval = usb_hcd_link_urb_to_ep(hcd, urb);
if (retval == 0) {
max3421_hcd->sched_pass = SCHED_PASS_PERIODIC;
wake_up_process(max3421_hcd->spi_thread);
}
out:
spin_unlock_irqrestore(&max3421_hcd->lock, flags);
return retval;
}
static int
max3421_urb_dequeue(struct usb_hcd *hcd, struct urb *urb, int status)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
unsigned long flags;
int retval;
spin_lock_irqsave(&max3421_hcd->lock, flags);
retval = usb_hcd_check_unlink_urb(hcd, urb, status);
if (retval == 0) {
set_bit(CHECK_UNLINK, &max3421_hcd->todo);
wake_up_process(max3421_hcd->spi_thread);
}
spin_unlock_irqrestore(&max3421_hcd->lock, flags);
return retval;
}
static void
max3421_endpoint_disable(struct usb_hcd *hcd, struct usb_host_endpoint *ep)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
unsigned long flags;
spin_lock_irqsave(&max3421_hcd->lock, flags);
if (ep->hcpriv) {
struct max3421_ep *max3421_ep = ep->hcpriv;
if (!list_empty(&max3421_ep->ep_list))
list_del(&max3421_ep->ep_list);
kfree(max3421_ep);
ep->hcpriv = NULL;
}
spin_unlock_irqrestore(&max3421_hcd->lock, flags);
}
static int
max3421_get_frame_number(struct usb_hcd *hcd)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
return max3421_hcd->frame_number;
}
static int
max3421_hub_status_data(struct usb_hcd *hcd, char *buf)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
unsigned long flags;
int retval = 0;
spin_lock_irqsave(&max3421_hcd->lock, flags);
if (!HCD_HW_ACCESSIBLE(hcd))
goto done;
*buf = 0;
if ((max3421_hcd->port_status & PORT_C_MASK) != 0) {
*buf = (1 << 1);
dev_dbg(hcd->self.controller,
"port status 0x%08x has changes\n",
max3421_hcd->port_status);
retval = 1;
if (max3421_hcd->rh_state == MAX3421_RH_SUSPENDED)
usb_hcd_resume_root_hub(hcd);
}
done:
spin_unlock_irqrestore(&max3421_hcd->lock, flags);
return retval;
}
static inline void
hub_descriptor(struct usb_hub_descriptor *desc)
{
memset(desc, 0, sizeof(*desc));
desc->bDescriptorType = USB_DT_HUB;
desc->bDescLength = 9;
desc->wHubCharacteristics = cpu_to_le16(HUB_CHAR_INDV_PORT_LPSM |
HUB_CHAR_COMMON_OCPM);
desc->bNbrPorts = 1;
}
static void
max3421_gpout_set_value(struct usb_hcd *hcd, u8 pin_number, u8 value)
{
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
u8 mask, idx;
--pin_number;
if (pin_number > 7)
return;
mask = 1u << (pin_number % 4);
idx = pin_number / 4;
if (value)
max3421_hcd->iopins[idx] |= mask;
else
max3421_hcd->iopins[idx] &= ~mask;
set_bit(IOPIN_UPDATE, &max3421_hcd->todo);
wake_up_process(max3421_hcd->spi_thread);
}
static int
max3421_hub_control(struct usb_hcd *hcd, u16 type_req, u16 value, u16 index,
char *buf, u16 length)
{
struct spi_device *spi = to_spi_device(hcd->self.controller);
struct max3421_hcd *max3421_hcd = hcd_to_max3421(hcd);
struct max3421_hcd_platform_data *pdata;
unsigned long flags;
int retval = 0;
spin_lock_irqsave(&max3421_hcd->lock, flags);
pdata = spi->dev.platform_data;
switch (type_req) {
case ClearHubFeature:
break;
case ClearPortFeature:
switch (value) {
case USB_PORT_FEAT_SUSPEND:
break;
case USB_PORT_FEAT_POWER:
dev_dbg(hcd->self.controller, "power-off\n");
max3421_gpout_set_value(hcd, pdata->vbus_gpout,
!pdata->vbus_active_level);
default:
max3421_hcd->port_status &= ~(1 << value);
}
break;
case GetHubDescriptor:
hub_descriptor((struct usb_hub_descriptor *) buf);
break;
case DeviceRequest | USB_REQ_GET_DESCRIPTOR:
case GetPortErrorCount:
case SetHubDepth:
goto error;
case GetHubStatus:
*(__le32 *) buf = cpu_to_le32(0);
break;
case GetPortStatus:
if (index != 1) {
retval = -EPIPE;
goto error;
}
((__le16 *) buf)[0] = cpu_to_le16(max3421_hcd->port_status);
((__le16 *) buf)[1] =
cpu_to_le16(max3421_hcd->port_status >> 16);
break;
case SetHubFeature:
retval = -EPIPE;
break;
case SetPortFeature:
switch (value) {
case USB_PORT_FEAT_LINK_STATE:
case USB_PORT_FEAT_U1_TIMEOUT:
case USB_PORT_FEAT_U2_TIMEOUT:
case USB_PORT_FEAT_BH_PORT_RESET:
goto error;
case USB_PORT_FEAT_SUSPEND:
if (max3421_hcd->active)
max3421_hcd->port_status |=
USB_PORT_STAT_SUSPEND;
break;
case USB_PORT_FEAT_POWER:
dev_dbg(hcd->self.controller, "power-on\n");
max3421_hcd->port_status |= USB_PORT_STAT_POWER;
max3421_gpout_set_value(hcd, pdata->vbus_gpout,
pdata->vbus_active_level);
break;
case USB_PORT_FEAT_RESET:
max3421_reset_port(hcd);
default:
if ((max3421_hcd->port_status & USB_PORT_STAT_POWER)
!= 0)
max3421_hcd->port_status |= (1 << value);
}
break;
default:
dev_dbg(hcd->self.controller,
"hub control req%04x v%04x i%04x l%d\n",
type_req, value, index, length);
error:
retval = -EPIPE;
}
spin_unlock_irqrestore(&max3421_hcd->lock, flags);
return retval;
}
static int
max3421_bus_suspend(struct usb_hcd *hcd)
{
return -1;
}
static int
max3421_bus_resume(struct usb_hcd *hcd)
{
return -1;
}
static int
max3421_map_urb_for_dma(struct usb_hcd *hcd, struct urb *urb, gfp_t mem_flags)
{
return 0;
}
static void
max3421_unmap_urb_for_dma(struct usb_hcd *hcd, struct urb *urb)
{
}
static int
max3421_probe(struct spi_device *spi)
{
struct max3421_hcd *max3421_hcd;
struct usb_hcd *hcd = NULL;
int retval = -ENOMEM;
if (spi_setup(spi) < 0) {
dev_err(&spi->dev, "Unable to setup SPI bus");
return -EFAULT;
}
hcd = usb_create_hcd(&max3421_hcd_desc, &spi->dev,
dev_name(&spi->dev));
if (!hcd) {
dev_err(&spi->dev, "failed to create HCD structure\n");
goto error;
}
set_bit(HCD_FLAG_POLL_RH, &hcd->flags);
max3421_hcd = hcd_to_max3421(hcd);
max3421_hcd->next = max3421_hcd_list;
max3421_hcd_list = max3421_hcd;
INIT_LIST_HEAD(&max3421_hcd->ep_list);
max3421_hcd->tx = kmalloc(sizeof(*max3421_hcd->tx), GFP_KERNEL);
if (!max3421_hcd->tx) {
dev_err(&spi->dev, "failed to kmalloc tx buffer\n");
goto error;
}
max3421_hcd->rx = kmalloc(sizeof(*max3421_hcd->rx), GFP_KERNEL);
if (!max3421_hcd->rx) {
dev_err(&spi->dev, "failed to kmalloc rx buffer\n");
goto error;
}
max3421_hcd->spi_thread = kthread_run(max3421_spi_thread, hcd,
"max3421_spi_thread");
if (max3421_hcd->spi_thread == ERR_PTR(-ENOMEM)) {
dev_err(&spi->dev,
"failed to create SPI thread (out of memory)\n");
goto error;
}
retval = usb_add_hcd(hcd, 0, 0);
if (retval) {
dev_err(&spi->dev, "failed to add HCD\n");
goto error;
}
retval = request_irq(spi->irq, max3421_irq_handler,
IRQF_TRIGGER_LOW, "max3421", hcd);
if (retval < 0) {
dev_err(&spi->dev, "failed to request irq %d\n", spi->irq);
goto error;
}
return 0;
error:
if (hcd) {
kfree(max3421_hcd->tx);
kfree(max3421_hcd->rx);
if (max3421_hcd->spi_thread)
kthread_stop(max3421_hcd->spi_thread);
usb_put_hcd(hcd);
}
return retval;
}
static int
max3421_remove(struct spi_device *spi)
{
struct max3421_hcd *max3421_hcd = NULL, **prev;
struct usb_hcd *hcd = NULL;
unsigned long flags;
for (prev = &max3421_hcd_list; *prev; prev = &(*prev)->next) {
max3421_hcd = *prev;
hcd = max3421_to_hcd(max3421_hcd);
if (hcd->self.controller == &spi->dev)
break;
}
if (!max3421_hcd) {
dev_err(&spi->dev, "no MAX3421 HCD found for SPI device %p\n",
spi);
return -ENODEV;
}
usb_remove_hcd(hcd);
spin_lock_irqsave(&max3421_hcd->lock, flags);
kthread_stop(max3421_hcd->spi_thread);
*prev = max3421_hcd->next;
spin_unlock_irqrestore(&max3421_hcd->lock, flags);
free_irq(spi->irq, hcd);
usb_put_hcd(hcd);
return 0;
}
