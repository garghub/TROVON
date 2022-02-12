static u8 *pcan_msg_init(struct pcan_usb_pro_msg *pm, void *buffer_addr,
int buffer_size)
{
if (buffer_size < PCAN_USBPRO_MSG_HEADER_LEN)
return NULL;
pm->u.rec_buffer = (u8 *)buffer_addr;
pm->rec_buffer_size = pm->rec_buffer_len = buffer_size;
pm->rec_ptr = pm->u.rec_buffer + PCAN_USBPRO_MSG_HEADER_LEN;
return pm->rec_ptr;
}
static u8 *pcan_msg_init_empty(struct pcan_usb_pro_msg *pm,
void *buffer_addr, int buffer_size)
{
u8 *pr = pcan_msg_init(pm, buffer_addr, buffer_size);
if (pr) {
pm->rec_buffer_len = PCAN_USBPRO_MSG_HEADER_LEN;
*pm->u.rec_cnt = 0;
}
return pr;
}
static int pcan_msg_add_rec(struct pcan_usb_pro_msg *pm, u8 id, ...)
{
int len, i;
u8 *pc;
va_list ap;
va_start(ap, id);
pc = pm->rec_ptr + 1;
i = 0;
switch (id) {
case PCAN_USBPRO_TXMSG8:
i += 4;
case PCAN_USBPRO_TXMSG4:
i += 4;
case PCAN_USBPRO_TXMSG0:
*pc++ = va_arg(ap, int);
*pc++ = va_arg(ap, int);
*pc++ = va_arg(ap, int);
*(u32 *)pc = cpu_to_le32(va_arg(ap, u32));
pc += 4;
memcpy(pc, va_arg(ap, int *), i);
pc += i;
break;
case PCAN_USBPRO_SETBTR:
case PCAN_USBPRO_GETDEVID:
*pc++ = va_arg(ap, int);
pc += 2;
*(u32 *)pc = cpu_to_le32(va_arg(ap, u32));
pc += 4;
break;
case PCAN_USBPRO_SETFILTR:
case PCAN_USBPRO_SETBUSACT:
case PCAN_USBPRO_SETSILENT:
*pc++ = va_arg(ap, int);
*(u16 *)pc = cpu_to_le16(va_arg(ap, int));
pc += 2;
break;
case PCAN_USBPRO_SETLED:
*pc++ = va_arg(ap, int);
*(u16 *)pc = cpu_to_le16(va_arg(ap, int));
pc += 2;
*(u32 *)pc = cpu_to_le32(va_arg(ap, u32));
pc += 4;
break;
case PCAN_USBPRO_SETTS:
pc++;
*(u16 *)pc = cpu_to_le16(va_arg(ap, int));
pc += 2;
break;
default:
pr_err("%s: %s(): unknown data type %02Xh (%d)\n",
PCAN_USB_DRIVER_NAME, __func__, id, id);
pc--;
break;
}
len = pc - pm->rec_ptr;
if (len > 0) {
*pm->u.rec_cnt = cpu_to_le32(*pm->u.rec_cnt+1);
*pm->rec_ptr = id;
pm->rec_ptr = pc;
pm->rec_buffer_len += len;
}
va_end(ap);
return len;
}
static int pcan_usb_pro_send_cmd(struct peak_usb_device *dev,
struct pcan_usb_pro_msg *pum)
{
int actual_length;
int err;
if (!(dev->state & PCAN_USB_STATE_CONNECTED))
return 0;
err = usb_bulk_msg(dev->udev,
usb_sndbulkpipe(dev->udev, PCAN_USBPRO_EP_CMDOUT),
pum->u.rec_buffer, pum->rec_buffer_len,
&actual_length, PCAN_USBPRO_COMMAND_TIMEOUT);
if (err)
netdev_err(dev->netdev, "sending command failure: %d\n", err);
return err;
}
static int pcan_usb_pro_wait_rsp(struct peak_usb_device *dev,
struct pcan_usb_pro_msg *pum)
{
u8 req_data_type, req_channel;
int actual_length;
int i, err = 0;
if (!(dev->state & PCAN_USB_STATE_CONNECTED))
return 0;
req_data_type = pum->u.rec_buffer[4];
req_channel = pum->u.rec_buffer[5];
*pum->u.rec_cnt = 0;
for (i = 0; !err && i < PCAN_USBPRO_RSP_SUBMIT_MAX; i++) {
struct pcan_usb_pro_msg rsp;
union pcan_usb_pro_rec *pr;
u32 r, rec_cnt;
u16 rec_len;
u8 *pc;
err = usb_bulk_msg(dev->udev,
usb_rcvbulkpipe(dev->udev, PCAN_USBPRO_EP_CMDIN),
pum->u.rec_buffer, pum->rec_buffer_len,
&actual_length, PCAN_USBPRO_COMMAND_TIMEOUT);
if (err) {
netdev_err(dev->netdev, "waiting rsp error %d\n", err);
break;
}
if (actual_length == 0)
continue;
err = -EBADMSG;
if (actual_length < PCAN_USBPRO_MSG_HEADER_LEN) {
netdev_err(dev->netdev,
"got abnormal too small rsp (len=%d)\n",
actual_length);
break;
}
pc = pcan_msg_init(&rsp, pum->u.rec_buffer,
actual_length);
rec_cnt = le32_to_cpu(*rsp.u.rec_cnt);
for (r = 0; r < rec_cnt; r++) {
pr = (union pcan_usb_pro_rec *)pc;
rec_len = pcan_usb_pro_sizeof_rec[pr->data_type];
if (!rec_len) {
netdev_err(dev->netdev,
"got unprocessed record in msg\n");
pcan_dump_mem("rcvd rsp msg", pum->u.rec_buffer,
actual_length);
break;
}
if (pr->data_type != req_data_type)
netdev_err(dev->netdev,
"got unwanted rsp %xh: ignored\n",
pr->data_type);
else if ((req_channel != 0xff) && \
(pr->bus_act.channel != req_channel))
netdev_err(dev->netdev,
"got rsp %xh but on chan%u: ignored\n",
req_data_type, pr->bus_act.channel);
else
return 0;
pc += rec_len;
}
}
return (i >= PCAN_USBPRO_RSP_SUBMIT_MAX) ? -ERANGE : err;
}
static int pcan_usb_pro_send_req(struct peak_usb_device *dev, int req_id,
int req_value, void *req_addr, int req_size)
{
int err;
u8 req_type;
unsigned int p;
if (!(dev->state & PCAN_USB_STATE_CONNECTED))
return 0;
memset(req_addr, '\0', req_size);
req_type = USB_TYPE_VENDOR | USB_RECIP_OTHER;
switch (req_id) {
case PCAN_USBPRO_REQ_FCT:
p = usb_sndctrlpipe(dev->udev, 0);
break;
default:
p = usb_rcvctrlpipe(dev->udev, 0);
req_type |= USB_DIR_IN;
break;
}
err = usb_control_msg(dev->udev, p, req_id, req_type, req_value, 0,
req_addr, req_size, 2 * USB_CTRL_GET_TIMEOUT);
if (err < 0) {
netdev_info(dev->netdev,
"unable to request usb[type=%d value=%d] err=%d\n",
req_id, req_value, err);
return err;
}
return 0;
}
static int pcan_usb_pro_set_ts(struct peak_usb_device *dev, u16 onoff)
{
struct pcan_usb_pro_msg um;
pcan_msg_init_empty(&um, dev->cmd_buf, PCAN_USB_MAX_CMD_LEN);
pcan_msg_add_rec(&um, PCAN_USBPRO_SETTS, onoff);
return pcan_usb_pro_send_cmd(dev, &um);
}
static int pcan_usb_pro_set_bitrate(struct peak_usb_device *dev, u32 ccbt)
{
struct pcan_usb_pro_device *pdev =
container_of(dev, struct pcan_usb_pro_device, dev);
struct pcan_usb_pro_msg um;
pcan_msg_init_empty(&um, dev->cmd_buf, PCAN_USB_MAX_CMD_LEN);
pcan_msg_add_rec(&um, PCAN_USBPRO_SETBTR, dev->ctrl_idx, ccbt);
pdev->cached_ccbt = ccbt;
return pcan_usb_pro_send_cmd(dev, &um);
}
static int pcan_usb_pro_set_bus(struct peak_usb_device *dev, u8 onoff)
{
struct pcan_usb_pro_msg um;
if (onoff) {
struct pcan_usb_pro_device *pdev =
container_of(dev, struct pcan_usb_pro_device, dev);
pcan_usb_pro_set_bitrate(dev, pdev->cached_ccbt);
}
pcan_msg_init_empty(&um, dev->cmd_buf, PCAN_USB_MAX_CMD_LEN);
pcan_msg_add_rec(&um, PCAN_USBPRO_SETBUSACT, dev->ctrl_idx, onoff);
return pcan_usb_pro_send_cmd(dev, &um);
}
static int pcan_usb_pro_set_silent(struct peak_usb_device *dev, u8 onoff)
{
struct pcan_usb_pro_msg um;
pcan_msg_init_empty(&um, dev->cmd_buf, PCAN_USB_MAX_CMD_LEN);
pcan_msg_add_rec(&um, PCAN_USBPRO_SETSILENT, dev->ctrl_idx, onoff);
return pcan_usb_pro_send_cmd(dev, &um);
}
static int pcan_usb_pro_set_filter(struct peak_usb_device *dev, u16 filter_mode)
{
struct pcan_usb_pro_msg um;
pcan_msg_init_empty(&um, dev->cmd_buf, PCAN_USB_MAX_CMD_LEN);
pcan_msg_add_rec(&um, PCAN_USBPRO_SETFILTR, dev->ctrl_idx, filter_mode);
return pcan_usb_pro_send_cmd(dev, &um);
}
static int pcan_usb_pro_set_led(struct peak_usb_device *dev, u8 mode,
u32 timeout)
{
struct pcan_usb_pro_msg um;
pcan_msg_init_empty(&um, dev->cmd_buf, PCAN_USB_MAX_CMD_LEN);
pcan_msg_add_rec(&um, PCAN_USBPRO_SETLED, dev->ctrl_idx, mode, timeout);
return pcan_usb_pro_send_cmd(dev, &um);
}
static int pcan_usb_pro_get_device_id(struct peak_usb_device *dev,
u32 *device_id)
{
struct pcan_usb_pro_devid *pdn;
struct pcan_usb_pro_msg um;
int err;
u8 *pc;
pc = pcan_msg_init_empty(&um, dev->cmd_buf, PCAN_USB_MAX_CMD_LEN);
pcan_msg_add_rec(&um, PCAN_USBPRO_GETDEVID, dev->ctrl_idx);
err = pcan_usb_pro_send_cmd(dev, &um);
if (err)
return err;
err = pcan_usb_pro_wait_rsp(dev, &um);
if (err)
return err;
pdn = (struct pcan_usb_pro_devid *)pc;
if (device_id)
*device_id = le32_to_cpu(pdn->serial_num);
return err;
}
static int pcan_usb_pro_set_bittiming(struct peak_usb_device *dev,
struct can_bittiming *bt)
{
u32 ccbt;
ccbt = (dev->can.ctrlmode & CAN_CTRLMODE_3_SAMPLES) ? 0x00800000 : 0;
ccbt |= (bt->sjw - 1) << 24;
ccbt |= (bt->phase_seg2 - 1) << 20;
ccbt |= (bt->prop_seg + bt->phase_seg1 - 1) << 16;
ccbt |= bt->brp - 1;
netdev_info(dev->netdev, "setting ccbt=0x%08x\n", ccbt);
return pcan_usb_pro_set_bitrate(dev, ccbt);
}
static void pcan_usb_pro_restart_complete(struct urb *urb)
{
peak_usb_async_complete(urb);
peak_usb_restart_complete(urb->context);
}
static int pcan_usb_pro_restart_async(struct peak_usb_device *dev,
struct urb *urb, u8 *buf)
{
struct pcan_usb_pro_msg um;
pcan_msg_init_empty(&um, buf, PCAN_USB_MAX_CMD_LEN);
pcan_msg_add_rec(&um, PCAN_USBPRO_SETBUSACT, dev->ctrl_idx, 1);
usb_fill_bulk_urb(urb, dev->udev,
usb_sndbulkpipe(dev->udev, PCAN_USBPRO_EP_CMDOUT),
buf, PCAN_USB_MAX_CMD_LEN,
pcan_usb_pro_restart_complete, dev);
return usb_submit_urb(urb, GFP_ATOMIC);
}
static int pcan_usb_pro_drv_loaded(struct peak_usb_device *dev, int loaded)
{
u8 *buffer;
int err;
buffer = kmalloc(PCAN_USBPRO_FCT_DRVLD_REQ_LEN, GFP_KERNEL);
if (!buffer)
return -ENOMEM;
buffer[0] = 0;
buffer[1] = !!loaded;
err = pcan_usb_pro_send_req(dev, PCAN_USBPRO_REQ_FCT,
PCAN_USBPRO_FCT_DRVLD, buffer,
PCAN_USBPRO_FCT_DRVLD_REQ_LEN);
kfree(buffer);
return err;
}
static inline
struct pcan_usb_pro_interface *pcan_usb_pro_dev_if(struct peak_usb_device *dev)
{
struct pcan_usb_pro_device *pdev =
container_of(dev, struct pcan_usb_pro_device, dev);
return pdev->usb_if;
}
static int pcan_usb_pro_handle_canmsg(struct pcan_usb_pro_interface *usb_if,
struct pcan_usb_pro_rxmsg *rx)
{
const unsigned int ctrl_idx = (rx->len >> 4) & 0x0f;
struct peak_usb_device *dev = usb_if->dev[ctrl_idx];
struct net_device *netdev = dev->netdev;
struct can_frame *can_frame;
struct sk_buff *skb;
struct timeval tv;
struct skb_shared_hwtstamps *hwts;
skb = alloc_can_skb(netdev, &can_frame);
if (!skb)
return -ENOMEM;
can_frame->can_id = le32_to_cpu(rx->id);
can_frame->can_dlc = rx->len & 0x0f;
if (rx->flags & PCAN_USBPRO_EXT)
can_frame->can_id |= CAN_EFF_FLAG;
if (rx->flags & PCAN_USBPRO_RTR)
can_frame->can_id |= CAN_RTR_FLAG;
else
memcpy(can_frame->data, rx->data, can_frame->can_dlc);
peak_usb_get_ts_tv(&usb_if->time_ref, le32_to_cpu(rx->ts32), &tv);
hwts = skb_hwtstamps(skb);
hwts->hwtstamp = timeval_to_ktime(tv);
netif_rx(skb);
netdev->stats.rx_packets++;
netdev->stats.rx_bytes += can_frame->can_dlc;
return 0;
}
static int pcan_usb_pro_handle_error(struct pcan_usb_pro_interface *usb_if,
struct pcan_usb_pro_rxstatus *er)
{
const u32 raw_status = le32_to_cpu(er->status);
const unsigned int ctrl_idx = (er->channel >> 4) & 0x0f;
struct peak_usb_device *dev = usb_if->dev[ctrl_idx];
struct net_device *netdev = dev->netdev;
struct can_frame *can_frame;
enum can_state new_state = CAN_STATE_ERROR_ACTIVE;
u8 err_mask = 0;
struct sk_buff *skb;
struct timeval tv;
struct skb_shared_hwtstamps *hwts;
if (dev->can.state == CAN_STATE_BUS_OFF)
return 0;
if (!raw_status) {
dev->can.state = CAN_STATE_ERROR_ACTIVE;
return 0;
}
if (raw_status & (PCAN_USBPRO_STATUS_OVERRUN |
PCAN_USBPRO_STATUS_QOVERRUN)) {
new_state = CAN_STATE_MAX;
}
if (raw_status & PCAN_USBPRO_STATUS_BUS) {
new_state = CAN_STATE_BUS_OFF;
} else if (raw_status & PCAN_USBPRO_STATUS_ERROR) {
u32 rx_err_cnt = (le32_to_cpu(er->err_frm) & 0x00ff0000) >> 16;
u32 tx_err_cnt = (le32_to_cpu(er->err_frm) & 0xff000000) >> 24;
if (rx_err_cnt > 127)
err_mask |= CAN_ERR_CRTL_RX_PASSIVE;
else if (rx_err_cnt > 96)
err_mask |= CAN_ERR_CRTL_RX_WARNING;
if (tx_err_cnt > 127)
err_mask |= CAN_ERR_CRTL_TX_PASSIVE;
else if (tx_err_cnt > 96)
err_mask |= CAN_ERR_CRTL_TX_WARNING;
if (err_mask & (CAN_ERR_CRTL_RX_WARNING |
CAN_ERR_CRTL_TX_WARNING))
new_state = CAN_STATE_ERROR_WARNING;
else if (err_mask & (CAN_ERR_CRTL_RX_PASSIVE |
CAN_ERR_CRTL_TX_PASSIVE))
new_state = CAN_STATE_ERROR_PASSIVE;
}
if (dev->can.state == new_state)
return 0;
skb = alloc_can_err_skb(netdev, &can_frame);
if (!skb)
return -ENOMEM;
switch (new_state) {
case CAN_STATE_BUS_OFF:
can_frame->can_id |= CAN_ERR_BUSOFF;
can_bus_off(netdev);
break;
case CAN_STATE_ERROR_PASSIVE:
can_frame->can_id |= CAN_ERR_CRTL;
can_frame->data[1] |= err_mask;
dev->can.can_stats.error_passive++;
break;
case CAN_STATE_ERROR_WARNING:
can_frame->can_id |= CAN_ERR_CRTL;
can_frame->data[1] |= err_mask;
dev->can.can_stats.error_warning++;
break;
case CAN_STATE_ERROR_ACTIVE:
break;
default:
if (raw_status & PCAN_USBPRO_STATUS_OVERRUN) {
can_frame->can_id |= CAN_ERR_PROT;
can_frame->data[2] |= CAN_ERR_PROT_OVERLOAD;
netdev->stats.rx_over_errors++;
netdev->stats.rx_errors++;
}
if (raw_status & PCAN_USBPRO_STATUS_QOVERRUN) {
can_frame->can_id |= CAN_ERR_CRTL;
can_frame->data[1] |= CAN_ERR_CRTL_RX_OVERFLOW;
netdev->stats.rx_over_errors++;
netdev->stats.rx_errors++;
}
new_state = CAN_STATE_ERROR_ACTIVE;
break;
}
dev->can.state = new_state;
peak_usb_get_ts_tv(&usb_if->time_ref, le32_to_cpu(er->ts32), &tv);
hwts = skb_hwtstamps(skb);
hwts->hwtstamp = timeval_to_ktime(tv);
netif_rx(skb);
netdev->stats.rx_packets++;
netdev->stats.rx_bytes += can_frame->can_dlc;
return 0;
}
static void pcan_usb_pro_handle_ts(struct pcan_usb_pro_interface *usb_if,
struct pcan_usb_pro_rxts *ts)
{
if (usb_if->cm_ignore_count > 0)
usb_if->cm_ignore_count--;
else
peak_usb_set_ts_now(&usb_if->time_ref,
le32_to_cpu(ts->ts64[1]));
}
static int pcan_usb_pro_decode_buf(struct peak_usb_device *dev, struct urb *urb)
{
struct pcan_usb_pro_interface *usb_if = pcan_usb_pro_dev_if(dev);
struct net_device *netdev = dev->netdev;
struct pcan_usb_pro_msg usb_msg;
u8 *rec_ptr, *msg_end;
u16 rec_cnt;
int err = 0;
rec_ptr = pcan_msg_init(&usb_msg, urb->transfer_buffer,
urb->actual_length);
if (!rec_ptr) {
netdev_err(netdev, "bad msg hdr len %d\n", urb->actual_length);
return -EINVAL;
}
msg_end = urb->transfer_buffer + urb->actual_length;
rec_cnt = le16_to_cpu(*usb_msg.u.rec_cnt_rd);
for (; rec_cnt > 0; rec_cnt--) {
union pcan_usb_pro_rec *pr = (union pcan_usb_pro_rec *)rec_ptr;
u16 sizeof_rec = pcan_usb_pro_sizeof_rec[pr->data_type];
if (!sizeof_rec) {
netdev_err(netdev,
"got unsupported rec in usb msg:\n");
err = -ENOTSUPP;
break;
}
if (rec_ptr + sizeof_rec > msg_end) {
netdev_err(netdev,
"got frag rec: should inc usb rx buf size\n");
err = -EBADMSG;
break;
}
switch (pr->data_type) {
case PCAN_USBPRO_RXMSG8:
case PCAN_USBPRO_RXMSG4:
case PCAN_USBPRO_RXMSG0:
case PCAN_USBPRO_RXRTR:
err = pcan_usb_pro_handle_canmsg(usb_if, &pr->rx_msg);
if (err < 0)
goto fail;
break;
case PCAN_USBPRO_RXSTATUS:
err = pcan_usb_pro_handle_error(usb_if, &pr->rx_status);
if (err < 0)
goto fail;
break;
case PCAN_USBPRO_RXTS:
pcan_usb_pro_handle_ts(usb_if, &pr->rx_ts);
break;
default:
netdev_err(netdev,
"unhandled rec type 0x%02x (%d): ignored\n",
pr->data_type, pr->data_type);
break;
}
rec_ptr += sizeof_rec;
}
fail:
if (err)
pcan_dump_mem("received msg",
urb->transfer_buffer, urb->actual_length);
return err;
}
static int pcan_usb_pro_encode_msg(struct peak_usb_device *dev,
struct sk_buff *skb, u8 *obuf, size_t *size)
{
struct can_frame *cf = (struct can_frame *)skb->data;
u8 data_type, len, flags;
struct pcan_usb_pro_msg usb_msg;
pcan_msg_init_empty(&usb_msg, obuf, *size);
if ((cf->can_id & CAN_RTR_FLAG) || (cf->can_dlc == 0))
data_type = PCAN_USBPRO_TXMSG0;
else if (cf->can_dlc <= 4)
data_type = PCAN_USBPRO_TXMSG4;
else
data_type = PCAN_USBPRO_TXMSG8;
len = (dev->ctrl_idx << 4) | (cf->can_dlc & 0x0f);
flags = 0;
if (cf->can_id & CAN_EFF_FLAG)
flags |= 0x02;
if (cf->can_id & CAN_RTR_FLAG)
flags |= 0x01;
pcan_msg_add_rec(&usb_msg, data_type, 0, flags, len, cf->can_id,
cf->data);
*size = usb_msg.rec_buffer_len;
return 0;
}
static int pcan_usb_pro_start(struct peak_usb_device *dev)
{
struct pcan_usb_pro_device *pdev =
container_of(dev, struct pcan_usb_pro_device, dev);
int err;
err = pcan_usb_pro_set_silent(dev,
dev->can.ctrlmode & CAN_CTRLMODE_LISTENONLY);
if (err)
return err;
err = pcan_usb_pro_set_filter(dev, 1);
if (err)
return err;
if (pdev->usb_if->dev_opened_count == 0) {
peak_usb_init_time_ref(&pdev->usb_if->time_ref, &pcan_usb_pro);
err = pcan_usb_pro_set_ts(dev, 1);
}
pdev->usb_if->dev_opened_count++;
return err;
}
static int pcan_usb_pro_stop(struct peak_usb_device *dev)
{
struct pcan_usb_pro_device *pdev =
container_of(dev, struct pcan_usb_pro_device, dev);
if (pdev->usb_if->dev_opened_count == 1)
pcan_usb_pro_set_ts(dev, 0);
pdev->usb_if->dev_opened_count--;
return 0;
}
static int pcan_usb_pro_init(struct peak_usb_device *dev)
{
struct pcan_usb_pro_device *pdev =
container_of(dev, struct pcan_usb_pro_device, dev);
struct pcan_usb_pro_interface *usb_if = NULL;
struct pcan_usb_pro_fwinfo *fi = NULL;
struct pcan_usb_pro_blinfo *bi = NULL;
int err;
if (!dev->prev_siblings) {
usb_if = kzalloc(sizeof(struct pcan_usb_pro_interface),
GFP_KERNEL);
fi = kmalloc(sizeof(struct pcan_usb_pro_fwinfo), GFP_KERNEL);
bi = kmalloc(sizeof(struct pcan_usb_pro_blinfo), GFP_KERNEL);
if (!usb_if || !fi || !bi) {
err = -ENOMEM;
goto err_out;
}
usb_if->cm_ignore_count = 5;
err = pcan_usb_pro_send_req(dev, PCAN_USBPRO_REQ_INFO,
PCAN_USBPRO_INFO_FW,
fi, sizeof(*fi));
if (err) {
dev_err(dev->netdev->dev.parent,
"unable to read %s firmware info (err %d)\n",
pcan_usb_pro.name, err);
goto err_out;
}
err = pcan_usb_pro_send_req(dev, PCAN_USBPRO_REQ_INFO,
PCAN_USBPRO_INFO_BL,
bi, sizeof(*bi));
if (err) {
dev_err(dev->netdev->dev.parent,
"unable to read %s bootloader info (err %d)\n",
pcan_usb_pro.name, err);
goto err_out;
}
err = pcan_usb_pro_drv_loaded(dev, 1);
if (err)
goto err_out;
dev_info(dev->netdev->dev.parent,
"PEAK-System %s hwrev %u serial %08X.%08X (%u channels)\n",
pcan_usb_pro.name,
bi->hw_rev, bi->serial_num_hi, bi->serial_num_lo,
pcan_usb_pro.ctrl_count);
} else {
usb_if = pcan_usb_pro_dev_if(dev->prev_siblings);
}
pdev->usb_if = usb_if;
usb_if->dev[dev->ctrl_idx] = dev;
pcan_usb_pro_set_led(dev, 0, 1);
kfree(bi);
kfree(fi);
return 0;
err_out:
kfree(bi);
kfree(fi);
kfree(usb_if);
return err;
}
static void pcan_usb_pro_exit(struct peak_usb_device *dev)
{
struct pcan_usb_pro_device *pdev =
container_of(dev, struct pcan_usb_pro_device, dev);
if (dev->can.state != CAN_STATE_STOPPED) {
pcan_usb_pro_set_bus(dev, 0);
}
if (dev->ctrl_idx == 0) {
if (pdev->usb_if->dev_opened_count > 0)
pcan_usb_pro_set_ts(dev, 0);
pcan_usb_pro_drv_loaded(dev, 0);
}
}
static void pcan_usb_pro_free(struct peak_usb_device *dev)
{
if (!dev->prev_siblings && !dev->next_siblings)
kfree(pcan_usb_pro_dev_if(dev));
}
static int pcan_usb_pro_probe(struct usb_interface *intf)
{
struct usb_host_interface *if_desc;
int i;
if_desc = intf->altsetting;
for (i = 0; i < if_desc->desc.bNumEndpoints; i++) {
struct usb_endpoint_descriptor *ep = &if_desc->endpoint[i].desc;
switch (ep->bEndpointAddress) {
case PCAN_USBPRO_EP_CMDOUT:
case PCAN_USBPRO_EP_CMDIN:
case PCAN_USBPRO_EP_MSGOUT_0:
case PCAN_USBPRO_EP_MSGOUT_1:
case PCAN_USBPRO_EP_MSGIN:
case PCAN_USBPRO_EP_UNUSED:
break;
default:
return -ENODEV;
}
}
return 0;
}
