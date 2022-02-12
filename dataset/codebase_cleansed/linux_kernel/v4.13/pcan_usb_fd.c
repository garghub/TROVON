static inline int pufd_omsg_get_channel(struct pcan_ufd_ovr_msg *om)
{
return om->channel & 0xf;
}
static inline
struct pcan_usb_fd_if *pcan_usb_fd_dev_if(struct peak_usb_device *dev)
{
struct pcan_usb_fd_device *pdev =
container_of(dev, struct pcan_usb_fd_device, dev);
return pdev->usb_if;
}
static inline void *pcan_usb_fd_cmd_buffer(struct peak_usb_device *dev)
{
struct pcan_usb_fd_device *pdev =
container_of(dev, struct pcan_usb_fd_device, dev);
return pdev->cmd_buffer_addr;
}
static int pcan_usb_fd_send_cmd(struct peak_usb_device *dev, void *cmd_tail)
{
void *cmd_head = pcan_usb_fd_cmd_buffer(dev);
int err = 0;
u8 *packet_ptr;
int i, n = 1, packet_len;
ptrdiff_t cmd_len;
if (!(dev->state & PCAN_USB_STATE_CONNECTED))
return 0;
cmd_len = cmd_tail - cmd_head;
if (cmd_len <= (PCAN_UFD_CMD_BUFFER_SIZE - sizeof(u64))) {
memset(cmd_tail, 0xff, sizeof(u64));
cmd_len += sizeof(u64);
}
packet_ptr = cmd_head;
if ((dev->udev->speed != USB_SPEED_HIGH) &&
(cmd_len > PCAN_UFD_LOSPD_PKT_SIZE)) {
packet_len = PCAN_UFD_LOSPD_PKT_SIZE;
n += cmd_len / packet_len;
} else {
packet_len = cmd_len;
}
for (i = 0; i < n; i++) {
err = usb_bulk_msg(dev->udev,
usb_sndbulkpipe(dev->udev,
PCAN_USBPRO_EP_CMDOUT),
packet_ptr, packet_len,
NULL, PCAN_UFD_CMD_TIMEOUT_MS);
if (err) {
netdev_err(dev->netdev,
"sending command failure: %d\n", err);
break;
}
packet_ptr += packet_len;
}
return err;
}
static int pcan_usb_fd_build_restart_cmd(struct peak_usb_device *dev, u8 *buf)
{
struct pucan_wr_err_cnt *prc;
struct pucan_command *cmd;
u8 *pc = buf;
prc = (struct pucan_wr_err_cnt *)pc;
prc->opcode_channel = pucan_cmd_opcode_channel(dev->ctrl_idx,
PUCAN_CMD_WR_ERR_CNT);
prc->sel_mask = cpu_to_le16(PUCAN_WRERRCNT_TE|PUCAN_WRERRCNT_RE);
prc->tx_counter = 0;
prc->rx_counter = 0;
pc += sizeof(struct pucan_wr_err_cnt);
if (dev->can.ctrlmode_supported & CAN_CTRLMODE_FD_NON_ISO) {
struct pucan_options *puo = (struct pucan_options *)pc;
puo->opcode_channel =
(dev->can.ctrlmode & CAN_CTRLMODE_FD_NON_ISO) ?
pucan_cmd_opcode_channel(dev->ctrl_idx,
PUCAN_CMD_CLR_DIS_OPTION) :
pucan_cmd_opcode_channel(dev->ctrl_idx,
PUCAN_CMD_SET_EN_OPTION);
puo->options = cpu_to_le16(PUCAN_OPTION_CANDFDISO);
puo->unused = 0;
pc += sizeof(struct pucan_options);
}
cmd = (struct pucan_command *)pc;
cmd->opcode_channel = pucan_cmd_opcode_channel(dev->ctrl_idx,
(dev->can.ctrlmode & CAN_CTRLMODE_LISTENONLY) ?
PUCAN_CMD_LISTEN_ONLY_MODE :
PUCAN_CMD_NORMAL_MODE);
pc += sizeof(struct pucan_command);
return pc - buf;
}
static int pcan_usb_fd_set_bus(struct peak_usb_device *dev, u8 onoff)
{
u8 *pc = pcan_usb_fd_cmd_buffer(dev);
int l;
if (onoff) {
l = pcan_usb_fd_build_restart_cmd(dev, pc);
} else {
struct pucan_command *cmd = (struct pucan_command *)pc;
cmd->opcode_channel = pucan_cmd_opcode_channel(dev->ctrl_idx,
PUCAN_CMD_RESET_MODE);
l = sizeof(struct pucan_command);
}
return pcan_usb_fd_send_cmd(dev, pc + l);
}
static int pcan_usb_fd_set_filter_std(struct peak_usb_device *dev, int idx,
u32 mask)
{
struct pucan_filter_std *cmd = pcan_usb_fd_cmd_buffer(dev);
int i, n;
if ((idx < 0) || (idx >= (1 << PUCAN_FLTSTD_ROW_IDX_BITS))) {
n = 1 << PUCAN_FLTSTD_ROW_IDX_BITS;
idx = 0;
} else {
n = idx + 1;
}
for (i = idx; i < n; i++, cmd++) {
cmd->opcode_channel = pucan_cmd_opcode_channel(dev->ctrl_idx,
PUCAN_CMD_FILTER_STD);
cmd->idx = cpu_to_le16(i);
cmd->mask = cpu_to_le32(mask);
}
return pcan_usb_fd_send_cmd(dev, cmd);
}
static int pcan_usb_fd_set_options(struct peak_usb_device *dev,
bool onoff, u16 ucan_mask, u16 usb_mask)
{
struct pcan_ufd_options *cmd = pcan_usb_fd_cmd_buffer(dev);
cmd->opcode_channel = pucan_cmd_opcode_channel(dev->ctrl_idx,
(onoff) ? PUCAN_CMD_SET_EN_OPTION :
PUCAN_CMD_CLR_DIS_OPTION);
cmd->ucan_mask = cpu_to_le16(ucan_mask);
cmd->usb_mask = cpu_to_le16(usb_mask);
return pcan_usb_fd_send_cmd(dev, ++cmd);
}
static int pcan_usb_fd_set_can_led(struct peak_usb_device *dev, u8 led_mode)
{
struct pcan_ufd_led *cmd = pcan_usb_fd_cmd_buffer(dev);
cmd->opcode_channel = pucan_cmd_opcode_channel(dev->ctrl_idx,
PCAN_UFD_CMD_LED_SET);
cmd->mode = led_mode;
return pcan_usb_fd_send_cmd(dev, ++cmd);
}
static int pcan_usb_fd_set_clock_domain(struct peak_usb_device *dev,
u8 clk_mode)
{
struct pcan_ufd_clock *cmd = pcan_usb_fd_cmd_buffer(dev);
cmd->opcode_channel = pucan_cmd_opcode_channel(dev->ctrl_idx,
PCAN_UFD_CMD_CLK_SET);
cmd->mode = clk_mode;
return pcan_usb_fd_send_cmd(dev, ++cmd);
}
static int pcan_usb_fd_set_bittiming_slow(struct peak_usb_device *dev,
struct can_bittiming *bt)
{
struct pucan_timing_slow *cmd = pcan_usb_fd_cmd_buffer(dev);
cmd->opcode_channel = pucan_cmd_opcode_channel(dev->ctrl_idx,
PUCAN_CMD_TIMING_SLOW);
cmd->sjw_t = PUCAN_TSLOW_SJW_T(bt->sjw - 1,
dev->can.ctrlmode & CAN_CTRLMODE_3_SAMPLES);
cmd->tseg2 = PUCAN_TSLOW_TSEG2(bt->phase_seg2 - 1);
cmd->tseg1 = PUCAN_TSLOW_TSEG1(bt->prop_seg + bt->phase_seg1 - 1);
cmd->brp = cpu_to_le16(PUCAN_TSLOW_BRP(bt->brp - 1));
cmd->ewl = 96;
return pcan_usb_fd_send_cmd(dev, ++cmd);
}
static int pcan_usb_fd_set_bittiming_fast(struct peak_usb_device *dev,
struct can_bittiming *bt)
{
struct pucan_timing_fast *cmd = pcan_usb_fd_cmd_buffer(dev);
cmd->opcode_channel = pucan_cmd_opcode_channel(dev->ctrl_idx,
PUCAN_CMD_TIMING_FAST);
cmd->sjw = PUCAN_TFAST_SJW(bt->sjw - 1);
cmd->tseg2 = PUCAN_TFAST_TSEG2(bt->phase_seg2 - 1);
cmd->tseg1 = PUCAN_TFAST_TSEG1(bt->prop_seg + bt->phase_seg1 - 1);
cmd->brp = cpu_to_le16(PUCAN_TFAST_BRP(bt->brp - 1));
return pcan_usb_fd_send_cmd(dev, ++cmd);
}
static int pcan_usb_fd_restart_async(struct peak_usb_device *dev,
struct urb *urb, u8 *buf)
{
u8 *pc = buf;
pc += pcan_usb_fd_build_restart_cmd(dev, pc);
memset(pc, 0xff, sizeof(struct pucan_command));
pc += sizeof(struct pucan_command);
usb_fill_bulk_urb(urb, dev->udev,
usb_sndbulkpipe(dev->udev, PCAN_USBPRO_EP_CMDOUT),
buf, pc - buf,
pcan_usb_pro_restart_complete, dev);
return usb_submit_urb(urb, GFP_ATOMIC);
}
static int pcan_usb_fd_drv_loaded(struct peak_usb_device *dev, bool loaded)
{
struct pcan_usb_fd_device *pdev =
container_of(dev, struct pcan_usb_fd_device, dev);
pdev->cmd_buffer_addr[0] = 0;
pdev->cmd_buffer_addr[1] = !!loaded;
return pcan_usb_pro_send_req(dev,
PCAN_USBPRO_REQ_FCT,
PCAN_USBPRO_FCT_DRVLD,
pdev->cmd_buffer_addr,
PCAN_USBPRO_FCT_DRVLD_REQ_LEN);
}
static int pcan_usb_fd_decode_canmsg(struct pcan_usb_fd_if *usb_if,
struct pucan_msg *rx_msg)
{
struct pucan_rx_msg *rm = (struct pucan_rx_msg *)rx_msg;
struct peak_usb_device *dev = usb_if->dev[pucan_msg_get_channel(rm)];
struct net_device *netdev = dev->netdev;
struct canfd_frame *cfd;
struct sk_buff *skb;
const u16 rx_msg_flags = le16_to_cpu(rm->flags);
if (rx_msg_flags & PUCAN_MSG_EXT_DATA_LEN) {
skb = alloc_canfd_skb(netdev, &cfd);
if (!skb)
return -ENOMEM;
if (rx_msg_flags & PUCAN_MSG_BITRATE_SWITCH)
cfd->flags |= CANFD_BRS;
if (rx_msg_flags & PUCAN_MSG_ERROR_STATE_IND)
cfd->flags |= CANFD_ESI;
cfd->len = can_dlc2len(get_canfd_dlc(pucan_msg_get_dlc(rm)));
} else {
skb = alloc_can_skb(netdev, (struct can_frame **)&cfd);
if (!skb)
return -ENOMEM;
cfd->len = get_can_dlc(pucan_msg_get_dlc(rm));
}
cfd->can_id = le32_to_cpu(rm->can_id);
if (rx_msg_flags & PUCAN_MSG_EXT_ID)
cfd->can_id |= CAN_EFF_FLAG;
if (rx_msg_flags & PUCAN_MSG_RTR)
cfd->can_id |= CAN_RTR_FLAG;
else
memcpy(cfd->data, rm->d, cfd->len);
peak_usb_netif_rx(skb, &usb_if->time_ref,
le32_to_cpu(rm->ts_low), le32_to_cpu(rm->ts_high));
netdev->stats.rx_packets++;
netdev->stats.rx_bytes += cfd->len;
return 0;
}
static int pcan_usb_fd_decode_status(struct pcan_usb_fd_if *usb_if,
struct pucan_msg *rx_msg)
{
struct pucan_status_msg *sm = (struct pucan_status_msg *)rx_msg;
struct peak_usb_device *dev = usb_if->dev[pucan_stmsg_get_channel(sm)];
struct pcan_usb_fd_device *pdev =
container_of(dev, struct pcan_usb_fd_device, dev);
enum can_state new_state = CAN_STATE_ERROR_ACTIVE;
enum can_state rx_state, tx_state;
struct net_device *netdev = dev->netdev;
struct can_frame *cf;
struct sk_buff *skb;
if (dev->can.state == CAN_STATE_BUS_OFF)
return 0;
if (sm->channel_p_w_b & PUCAN_BUS_BUSOFF) {
new_state = CAN_STATE_BUS_OFF;
} else if (sm->channel_p_w_b & PUCAN_BUS_PASSIVE) {
new_state = CAN_STATE_ERROR_PASSIVE;
} else if (sm->channel_p_w_b & PUCAN_BUS_WARNING) {
new_state = CAN_STATE_ERROR_WARNING;
} else {
dev->can.state = CAN_STATE_ERROR_ACTIVE;
pdev->bec.txerr = 0;
pdev->bec.rxerr = 0;
return 0;
}
if (new_state == dev->can.state)
return 0;
tx_state = (pdev->bec.txerr >= pdev->bec.rxerr) ? new_state : 0;
rx_state = (pdev->bec.txerr <= pdev->bec.rxerr) ? new_state : 0;
skb = alloc_can_err_skb(netdev, &cf);
if (skb)
can_change_state(netdev, cf, tx_state, rx_state);
if (new_state == CAN_STATE_BUS_OFF)
can_bus_off(netdev);
if (!skb)
return -ENOMEM;
peak_usb_netif_rx(skb, &usb_if->time_ref,
le32_to_cpu(sm->ts_low), le32_to_cpu(sm->ts_high));
netdev->stats.rx_packets++;
netdev->stats.rx_bytes += cf->can_dlc;
return 0;
}
static int pcan_usb_fd_decode_error(struct pcan_usb_fd_if *usb_if,
struct pucan_msg *rx_msg)
{
struct pucan_error_msg *er = (struct pucan_error_msg *)rx_msg;
struct peak_usb_device *dev = usb_if->dev[pucan_ermsg_get_channel(er)];
struct pcan_usb_fd_device *pdev =
container_of(dev, struct pcan_usb_fd_device, dev);
pdev->bec.txerr = er->tx_err_cnt;
pdev->bec.rxerr = er->rx_err_cnt;
return 0;
}
static int pcan_usb_fd_decode_overrun(struct pcan_usb_fd_if *usb_if,
struct pucan_msg *rx_msg)
{
struct pcan_ufd_ovr_msg *ov = (struct pcan_ufd_ovr_msg *)rx_msg;
struct peak_usb_device *dev = usb_if->dev[pufd_omsg_get_channel(ov)];
struct net_device *netdev = dev->netdev;
struct can_frame *cf;
struct sk_buff *skb;
skb = alloc_can_err_skb(netdev, &cf);
if (!skb)
return -ENOMEM;
cf->can_id |= CAN_ERR_CRTL;
cf->data[1] |= CAN_ERR_CRTL_RX_OVERFLOW;
peak_usb_netif_rx(skb, &usb_if->time_ref,
le32_to_cpu(ov->ts_low), le32_to_cpu(ov->ts_high));
netdev->stats.rx_over_errors++;
netdev->stats.rx_errors++;
return 0;
}
static void pcan_usb_fd_decode_ts(struct pcan_usb_fd_if *usb_if,
struct pucan_msg *rx_msg)
{
struct pcan_ufd_ts_msg *ts = (struct pcan_ufd_ts_msg *)rx_msg;
if (usb_if->cm_ignore_count > 0)
usb_if->cm_ignore_count--;
else
peak_usb_set_ts_now(&usb_if->time_ref, le32_to_cpu(ts->ts_low));
}
static int pcan_usb_fd_decode_buf(struct peak_usb_device *dev, struct urb *urb)
{
struct pcan_usb_fd_if *usb_if = pcan_usb_fd_dev_if(dev);
struct net_device *netdev = dev->netdev;
struct pucan_msg *rx_msg;
u8 *msg_ptr, *msg_end;
int err = 0;
msg_ptr = urb->transfer_buffer;
msg_end = urb->transfer_buffer + urb->actual_length;
for (; msg_ptr < msg_end;) {
u16 rx_msg_type, rx_msg_size;
rx_msg = (struct pucan_msg *)msg_ptr;
if (!rx_msg->size) {
break;
}
rx_msg_size = le16_to_cpu(rx_msg->size);
rx_msg_type = le16_to_cpu(rx_msg->type);
if (msg_ptr + rx_msg_size > msg_end) {
netdev_err(netdev,
"got frag rec: should inc usb rx buf sze\n");
err = -EBADMSG;
break;
}
switch (rx_msg_type) {
case PUCAN_MSG_CAN_RX:
err = pcan_usb_fd_decode_canmsg(usb_if, rx_msg);
if (err < 0)
goto fail;
break;
case PCAN_UFD_MSG_CALIBRATION:
pcan_usb_fd_decode_ts(usb_if, rx_msg);
break;
case PUCAN_MSG_ERROR:
err = pcan_usb_fd_decode_error(usb_if, rx_msg);
if (err < 0)
goto fail;
break;
case PUCAN_MSG_STATUS:
err = pcan_usb_fd_decode_status(usb_if, rx_msg);
if (err < 0)
goto fail;
break;
case PCAN_UFD_MSG_OVERRUN:
err = pcan_usb_fd_decode_overrun(usb_if, rx_msg);
if (err < 0)
goto fail;
break;
default:
netdev_err(netdev,
"unhandled msg type 0x%02x (%d): ignored\n",
rx_msg_type, rx_msg_type);
break;
}
msg_ptr += rx_msg_size;
}
fail:
if (err)
pcan_dump_mem("received msg",
urb->transfer_buffer, urb->actual_length);
return err;
}
static int pcan_usb_fd_encode_msg(struct peak_usb_device *dev,
struct sk_buff *skb, u8 *obuf, size_t *size)
{
struct pucan_tx_msg *tx_msg = (struct pucan_tx_msg *)obuf;
struct canfd_frame *cfd = (struct canfd_frame *)skb->data;
u16 tx_msg_size, tx_msg_flags;
u8 can_dlc;
tx_msg_size = ALIGN(sizeof(struct pucan_tx_msg) + cfd->len, 4);
tx_msg->size = cpu_to_le16(tx_msg_size);
tx_msg->type = cpu_to_le16(PUCAN_MSG_CAN_TX);
tx_msg_flags = 0;
if (cfd->can_id & CAN_EFF_FLAG) {
tx_msg_flags |= PUCAN_MSG_EXT_ID;
tx_msg->can_id = cpu_to_le32(cfd->can_id & CAN_EFF_MASK);
} else {
tx_msg->can_id = cpu_to_le32(cfd->can_id & CAN_SFF_MASK);
}
if (can_is_canfd_skb(skb)) {
can_dlc = can_len2dlc(cfd->len);
tx_msg_flags |= PUCAN_MSG_EXT_DATA_LEN;
if (cfd->flags & CANFD_BRS)
tx_msg_flags |= PUCAN_MSG_BITRATE_SWITCH;
if (cfd->flags & CANFD_ESI)
tx_msg_flags |= PUCAN_MSG_ERROR_STATE_IND;
} else {
can_dlc = cfd->len;
if (cfd->can_id & CAN_RTR_FLAG)
tx_msg_flags |= PUCAN_MSG_RTR;
}
tx_msg->flags = cpu_to_le16(tx_msg_flags);
tx_msg->channel_dlc = PUCAN_MSG_CHANNEL_DLC(dev->ctrl_idx, can_dlc);
memcpy(tx_msg->d, cfd->data, cfd->len);
tx_msg = (struct pucan_tx_msg *)(obuf + tx_msg_size);
tx_msg->size = 0;
*size = tx_msg_size + sizeof(u32);
return 0;
}
static int pcan_usb_fd_start(struct peak_usb_device *dev)
{
struct pcan_usb_fd_device *pdev =
container_of(dev, struct pcan_usb_fd_device, dev);
int err;
err = pcan_usb_fd_set_filter_std(dev, -1, 0xffffffff);
if (err)
return err;
if (pdev->usb_if->dev_opened_count == 0) {
peak_usb_init_time_ref(&pdev->usb_if->time_ref,
&pcan_usb_pro_fd);
err = pcan_usb_fd_set_options(dev, 1,
PUCAN_OPTION_ERROR,
PCAN_UFD_FLTEXT_CALIBRATION);
}
pdev->usb_if->dev_opened_count++;
pdev->bec.txerr = 0;
pdev->bec.rxerr = 0;
return err;
}
static int pcan_usb_fd_get_berr_counter(const struct net_device *netdev,
struct can_berr_counter *bec)
{
struct peak_usb_device *dev = netdev_priv(netdev);
struct pcan_usb_fd_device *pdev =
container_of(dev, struct pcan_usb_fd_device, dev);
*bec = pdev->bec;
return 0;
}
static int pcan_usb_fd_stop(struct peak_usb_device *dev)
{
struct pcan_usb_fd_device *pdev =
container_of(dev, struct pcan_usb_fd_device, dev);
if (pdev->usb_if->dev_opened_count == 1)
pcan_usb_fd_set_options(dev, 0,
PUCAN_OPTION_ERROR,
PCAN_UFD_FLTEXT_CALIBRATION);
pdev->usb_if->dev_opened_count--;
return 0;
}
static int pcan_usb_fd_init(struct peak_usb_device *dev)
{
struct pcan_usb_fd_device *pdev =
container_of(dev, struct pcan_usb_fd_device, dev);
int i, err = -ENOMEM;
if (!dev->prev_siblings) {
pdev->usb_if = kzalloc(sizeof(*pdev->usb_if), GFP_KERNEL);
if (!pdev->usb_if)
goto err_out;
pdev->cmd_buffer_addr = kmalloc(PCAN_UFD_CMD_BUFFER_SIZE,
GFP_KERNEL);
if (!pdev->cmd_buffer_addr)
goto err_out_1;
pdev->usb_if->cm_ignore_count = 5;
err = pcan_usb_pro_send_req(dev, PCAN_USBPRO_REQ_INFO,
PCAN_USBPRO_INFO_FW,
&pdev->usb_if->fw_info,
sizeof(pdev->usb_if->fw_info));
if (err) {
dev_err(dev->netdev->dev.parent,
"unable to read %s firmware info (err %d)\n",
dev->adapter->name, err);
goto err_out_2;
}
dev_info(dev->netdev->dev.parent,
"PEAK-System %s v%u fw v%u.%u.%u (%u channels)\n",
dev->adapter->name, pdev->usb_if->fw_info.hw_version,
pdev->usb_if->fw_info.fw_version[0],
pdev->usb_if->fw_info.fw_version[1],
pdev->usb_if->fw_info.fw_version[2],
dev->adapter->ctrl_count);
if (pdev->usb_if->fw_info.fw_version[0] >= 2) {
dev->can.ctrlmode_supported |= CAN_CTRLMODE_FD_NON_ISO;
} else {
dev->can.ctrlmode |= CAN_CTRLMODE_FD_NON_ISO;
}
err = pcan_usb_fd_drv_loaded(dev, 1);
if (err) {
dev_err(dev->netdev->dev.parent,
"unable to tell %s driver is loaded (err %d)\n",
dev->adapter->name, err);
goto err_out_2;
}
} else {
struct pcan_usb_fd_device *ppdev =
container_of(dev->prev_siblings,
struct pcan_usb_fd_device, dev);
pdev->usb_if = ppdev->usb_if;
pdev->cmd_buffer_addr = ppdev->cmd_buffer_addr;
dev->can.ctrlmode = ppdev->dev.can.ctrlmode;
dev->can.ctrlmode_supported = ppdev->dev.can.ctrlmode_supported;
}
pdev->usb_if->dev[dev->ctrl_idx] = dev;
dev->device_number =
le32_to_cpu(pdev->usb_if->fw_info.dev_id[dev->ctrl_idx]);
for (i = 0; i < ARRAY_SIZE(pcan_usb_fd_clk_freq); i++)
if (dev->adapter->clock.freq == pcan_usb_fd_clk_freq[i])
break;
if (i >= ARRAY_SIZE(pcan_usb_fd_clk_freq)) {
dev_warn(dev->netdev->dev.parent,
"incompatible clock frequencies\n");
err = -EINVAL;
goto err_out_2;
}
pcan_usb_fd_set_clock_domain(dev, i);
pcan_usb_fd_set_can_led(dev, PCAN_UFD_LED_DEF);
return 0;
err_out_2:
kfree(pdev->cmd_buffer_addr);
err_out_1:
kfree(pdev->usb_if);
err_out:
return err;
}
static void pcan_usb_fd_exit(struct peak_usb_device *dev)
{
struct pcan_usb_fd_device *pdev =
container_of(dev, struct pcan_usb_fd_device, dev);
if (dev->can.state != CAN_STATE_STOPPED) {
pcan_usb_fd_set_bus(dev, 0);
}
pcan_usb_fd_set_can_led(dev, PCAN_UFD_LED_OFF);
if (dev->ctrl_idx == 0) {
if (pdev->usb_if->dev_opened_count > 0)
pcan_usb_fd_set_options(dev, 0,
PUCAN_OPTION_ERROR,
PCAN_UFD_FLTEXT_CALIBRATION);
pcan_usb_fd_drv_loaded(dev, 0);
}
}
static void pcan_usb_fd_free(struct peak_usb_device *dev)
{
if (!dev->prev_siblings && !dev->next_siblings) {
struct pcan_usb_fd_device *pdev =
container_of(dev, struct pcan_usb_fd_device, dev);
kfree(pdev->cmd_buffer_addr);
kfree(pdev->usb_if);
}
}
