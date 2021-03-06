static int mcs_set_reg(struct mcs_cb *mcs, __u16 reg, __u16 val)
{
struct usb_device *dev = mcs->usbdev;
return usb_control_msg(dev, usb_sndctrlpipe(dev, 0), MCS_WRREQ,
MCS_WR_RTYPE, val, reg, NULL, 0,
msecs_to_jiffies(MCS_CTRL_TIMEOUT));
}
static int mcs_get_reg(struct mcs_cb *mcs, __u16 reg, __u16 * val)
{
struct usb_device *dev = mcs->usbdev;
int ret = usb_control_msg(dev, usb_rcvctrlpipe(dev, 0), MCS_RDREQ,
MCS_RD_RTYPE, 0, reg, val, 2,
msecs_to_jiffies(MCS_CTRL_TIMEOUT));
return ret;
}
static inline int mcs_setup_transceiver_vishay(struct mcs_cb *mcs)
{
int ret = 0;
__u16 rval;
ret = mcs_get_reg(mcs, MCS_XCVR_REG, &rval);
if (unlikely(ret != 2)) {
ret = -EIO;
goto error;
}
rval |= (MCS_MODE0 | MCS_XCVR_CONF);
rval &= ~MCS_STFIR;
rval &= ~MCS_MODE1;
ret = mcs_set_reg(mcs, MCS_XCVR_REG, rval);
if (unlikely(ret))
goto error;
rval &= ~MCS_MODE0;
ret = mcs_set_reg(mcs, MCS_XCVR_REG, rval);
if (unlikely(ret))
goto error;
rval &= ~MCS_XCVR_CONF;
ret = mcs_set_reg(mcs, MCS_XCVR_REG, rval);
if (unlikely(ret))
goto error;
ret = 0;
error:
return ret;
}
static inline int mcs_setup_transceiver_agilent(struct mcs_cb *mcs)
{
IRDA_WARNING("This transceiver type is not supported yet.\n");
return 1;
}
static inline int mcs_setup_transceiver_sharp(struct mcs_cb *mcs)
{
IRDA_WARNING("This transceiver type is not supported yet.\n");
return 1;
}
static inline int mcs_setup_transceiver(struct mcs_cb *mcs)
{
int ret = 0;
__u16 rval;
char *msg;
msg = "Basic transceiver setup error.";
ret = mcs_get_reg(mcs, MCS_MODE_REG, &rval);
if(unlikely(ret != 2))
goto error;
rval |= MCS_DRIVER;
ret = mcs_set_reg(mcs, MCS_MODE_REG, rval);
if(unlikely(ret))
goto error;
rval = 0;
ret = mcs_set_reg(mcs, MCS_MINRXPW_REG, rval);
if(unlikely(ret))
goto error;
ret = mcs_get_reg(mcs, MCS_MODE_REG, &rval);
if(unlikely(ret != 2))
goto error;
rval &= ~MCS_FIR;
if(mcs->sir_tweak)
rval |= MCS_SIR16US;
else
rval &= ~MCS_SIR16US;
rval &= ~(MCS_BBTG | MCS_ASK);
rval &= ~MCS_SPEED_MASK;
rval |= MCS_SPEED_9600;
mcs->speed = 9600;
mcs->new_speed = 0;
rval &= ~MCS_PLLPWDN;
rval |= MCS_DTD | MCS_SIPEN;
ret = mcs_set_reg(mcs, MCS_MODE_REG, rval);
if(unlikely(ret))
goto error;
msg = "transceiver model specific setup error.";
switch (mcs->transceiver_type) {
case MCS_TSC_VISHAY:
ret = mcs_setup_transceiver_vishay(mcs);
break;
case MCS_TSC_SHARP:
ret = mcs_setup_transceiver_sharp(mcs);
break;
case MCS_TSC_AGILENT:
ret = mcs_setup_transceiver_agilent(mcs);
break;
default:
IRDA_WARNING("Unknown transceiver type: %d\n",
mcs->transceiver_type);
ret = 1;
}
if (unlikely(ret))
goto error;
if (mcs->transceiver_type != MCS_TSC_SHARP) {
ret = mcs_get_reg(mcs, MCS_XCVR_REG, &rval);
if (unlikely(ret != 2))
goto error;
if (mcs->receive_mode)
rval |= MCS_RXFAST;
else
rval &= ~MCS_RXFAST;
ret = mcs_set_reg(mcs, MCS_XCVR_REG, rval);
if (unlikely(ret))
goto error;
}
msg = "transceiver reset.";
ret = mcs_get_reg(mcs, MCS_MODE_REG, &rval);
if (unlikely(ret != 2))
goto error;
rval &= ~MCS_RESET;
ret = mcs_set_reg(mcs, MCS_MODE_REG, rval);
if (unlikely(ret))
goto error;
else
return ret;
error:
IRDA_ERROR("%s\n", msg);
return ret;
}
static inline int mcs_wrap_sir_skb(struct sk_buff *skb, __u8 * buf)
{
int wraplen;
wraplen = async_wrap_skb(skb, buf + 2, 4094);
wraplen += 2;
buf[0] = wraplen & 0xff;
buf[1] = (wraplen >> 8) & 0xff;
return wraplen;
}
static unsigned mcs_wrap_fir_skb(const struct sk_buff *skb, __u8 *buf)
{
unsigned int len = 0;
__u32 fcs = ~(crc32_le(~0, skb->data, skb->len));
len = skb->len + 6;
buf[0] = len & 0xff;
buf[1] = (len >> 8) & 0xff;
skb_copy_from_linear_data(skb, buf + 2, skb->len);
buf[len - 4] = fcs & 0xff;
buf[len - 3] = (fcs >> 8) & 0xff;
buf[len - 2] = (fcs >> 16) & 0xff;
buf[len - 1] = (fcs >> 24) & 0xff;
return len;
}
static unsigned mcs_wrap_mir_skb(const struct sk_buff *skb, __u8 *buf)
{
__u16 fcs = 0;
int len = skb->len + 4;
fcs = ~(irda_calc_crc16(~fcs, skb->data, skb->len));
buf[0] = len & 0xff;
buf[1] = (len >> 8) & 0xff;
skb_copy_from_linear_data(skb, buf + 2, skb->len);
buf[len - 2] = fcs & 0xff;
buf[len - 1] = (fcs >> 8) & 0xff;
return len;
}
static void mcs_unwrap_mir(struct mcs_cb *mcs, __u8 *buf, int len)
{
__u16 fcs;
int new_len;
struct sk_buff *skb;
new_len = len - 2;
if(unlikely(new_len <= 0)) {
IRDA_ERROR("%s short frame length %d\n",
mcs->netdev->name, new_len);
++mcs->netdev->stats.rx_errors;
++mcs->netdev->stats.rx_length_errors;
return;
}
fcs = 0;
fcs = irda_calc_crc16(~fcs, buf, len);
if(fcs != GOOD_FCS) {
IRDA_ERROR("crc error calc 0x%x len %d\n",
fcs, new_len);
mcs->netdev->stats.rx_errors++;
mcs->netdev->stats.rx_crc_errors++;
return;
}
skb = dev_alloc_skb(new_len + 1);
if(unlikely(!skb)) {
++mcs->netdev->stats.rx_dropped;
return;
}
skb_reserve(skb, 1);
skb_copy_to_linear_data(skb, buf, new_len);
skb_put(skb, new_len);
skb_reset_mac_header(skb);
skb->protocol = htons(ETH_P_IRDA);
skb->dev = mcs->netdev;
netif_rx(skb);
mcs->netdev->stats.rx_packets++;
mcs->netdev->stats.rx_bytes += new_len;
}
static void mcs_unwrap_fir(struct mcs_cb *mcs, __u8 *buf, int len)
{
__u32 fcs;
int new_len;
struct sk_buff *skb;
new_len = len - 4;
if(unlikely(new_len <= 0)) {
IRDA_ERROR("%s short frame length %d\n",
mcs->netdev->name, new_len);
++mcs->netdev->stats.rx_errors;
++mcs->netdev->stats.rx_length_errors;
return;
}
fcs = ~(crc32_le(~0, buf, new_len));
if(fcs != get_unaligned_le32(buf + new_len)) {
IRDA_ERROR("crc error calc 0x%x len %d\n", fcs, new_len);
mcs->netdev->stats.rx_errors++;
mcs->netdev->stats.rx_crc_errors++;
return;
}
skb = dev_alloc_skb(new_len + 1);
if(unlikely(!skb)) {
++mcs->netdev->stats.rx_dropped;
return;
}
skb_reserve(skb, 1);
skb_copy_to_linear_data(skb, buf, new_len);
skb_put(skb, new_len);
skb_reset_mac_header(skb);
skb->protocol = htons(ETH_P_IRDA);
skb->dev = mcs->netdev;
netif_rx(skb);
mcs->netdev->stats.rx_packets++;
mcs->netdev->stats.rx_bytes += new_len;
}
static inline int mcs_setup_urbs(struct mcs_cb *mcs)
{
mcs->rx_urb = NULL;
mcs->tx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!mcs->tx_urb)
return 0;
mcs->rx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!mcs->rx_urb)
return 0;
return 1;
}
static inline int mcs_receive_start(struct mcs_cb *mcs)
{
mcs->rx_buff.in_frame = FALSE;
mcs->rx_buff.state = OUTSIDE_FRAME;
usb_fill_bulk_urb(mcs->rx_urb, mcs->usbdev,
usb_rcvbulkpipe(mcs->usbdev, mcs->ep_in),
mcs->in_buf, 4096, mcs_receive_irq, mcs);
mcs->rx_urb->status = 0;
return usb_submit_urb(mcs->rx_urb, GFP_KERNEL);
}
static inline int mcs_find_endpoints(struct mcs_cb *mcs,
struct usb_host_endpoint *ep, int epnum)
{
int i;
int ret = 0;
if (!ep)
return ret;
for (i = 0; i < epnum; i++) {
if (ep[i].desc.bEndpointAddress & USB_DIR_IN)
mcs->ep_in = ep[i].desc.bEndpointAddress;
else
mcs->ep_out = ep[i].desc.bEndpointAddress;
if ((mcs->ep_in != 0) && (mcs->ep_out != 0)) {
ret = 1;
break;
}
}
return ret;
}
static void mcs_speed_work(struct work_struct *work)
{
struct mcs_cb *mcs = container_of(work, struct mcs_cb, work);
struct net_device *netdev = mcs->netdev;
mcs_speed_change(mcs);
netif_wake_queue(netdev);
}
static int mcs_speed_change(struct mcs_cb *mcs)
{
int ret = 0;
int rst = 0;
int cnt = 0;
__u16 nspeed;
__u16 rval;
nspeed = mcs_speed_set[(mcs->new_speed >> 8) & 0x0f];
do {
mcs_get_reg(mcs, MCS_RESV_REG, &rval);
} while(cnt++ < 100 && (rval & MCS_IRINTX));
if (cnt > 100) {
IRDA_ERROR("unable to change speed\n");
ret = -EIO;
goto error;
}
mcs_get_reg(mcs, MCS_MODE_REG, &rval);
if (mcs->new_speed <= 115200) {
rval &= ~MCS_FIR;
if ((rst = (mcs->speed > 115200)))
mcs_set_reg(mcs, MCS_MINRXPW_REG, 0);
} else if (mcs->new_speed <= 1152000) {
rval &= ~MCS_FIR;
if ((rst = !(mcs->speed == 576000 || mcs->speed == 1152000)))
mcs_set_reg(mcs, MCS_MINRXPW_REG, 5);
} else {
rval |= MCS_FIR;
if ((rst = (mcs->speed != 4000000)))
mcs_set_reg(mcs, MCS_MINRXPW_REG, 5);
}
rval &= ~MCS_SPEED_MASK;
rval |= nspeed;
ret = mcs_set_reg(mcs, MCS_MODE_REG, rval);
if (unlikely(ret))
goto error;
if (rst)
switch (mcs->transceiver_type) {
case MCS_TSC_VISHAY:
ret = mcs_setup_transceiver_vishay(mcs);
break;
case MCS_TSC_SHARP:
ret = mcs_setup_transceiver_sharp(mcs);
break;
case MCS_TSC_AGILENT:
ret = mcs_setup_transceiver_agilent(mcs);
break;
default:
ret = 1;
IRDA_WARNING("Unknown transceiver type: %d\n",
mcs->transceiver_type);
}
if (unlikely(ret))
goto error;
mcs_get_reg(mcs, MCS_MODE_REG, &rval);
rval &= ~MCS_RESET;
ret = mcs_set_reg(mcs, MCS_MODE_REG, rval);
mcs->speed = mcs->new_speed;
error:
mcs->new_speed = 0;
return ret;
}
static int mcs_net_ioctl(struct net_device *netdev, struct ifreq *rq, int cmd)
{
int ret = 0;
switch (cmd) {
default:
ret = -EOPNOTSUPP;
}
return ret;
}
static int mcs_net_close(struct net_device *netdev)
{
int ret = 0;
struct mcs_cb *mcs = netdev_priv(netdev);
netif_stop_queue(netdev);
kfree_skb(mcs->rx_buff.skb);
usb_kill_urb(mcs->rx_urb);
usb_free_urb(mcs->rx_urb);
usb_kill_urb(mcs->tx_urb);
usb_free_urb(mcs->tx_urb);
if (mcs->irlap)
irlap_close(mcs->irlap);
mcs->irlap = NULL;
return ret;
}
static int mcs_net_open(struct net_device *netdev)
{
struct mcs_cb *mcs = netdev_priv(netdev);
char hwname[16];
int ret = 0;
ret = usb_clear_halt(mcs->usbdev,
usb_sndbulkpipe(mcs->usbdev, mcs->ep_in));
if (ret)
goto error1;
ret = usb_clear_halt(mcs->usbdev,
usb_rcvbulkpipe(mcs->usbdev, mcs->ep_out));
if (ret)
goto error1;
ret = mcs_setup_transceiver(mcs);
if (ret)
goto error1;
ret = -ENOMEM;
mcs->receiving = 0;
mcs->rx_buff.truesize = IRDA_SKB_MAX_MTU;
mcs->rx_buff.skb = dev_alloc_skb(IRDA_SKB_MAX_MTU);
if (!mcs->rx_buff.skb)
goto error1;
skb_reserve(mcs->rx_buff.skb, 1);
mcs->rx_buff.head = mcs->rx_buff.skb->data;
do_gettimeofday(&mcs->rx_time);
sprintf(hwname, "usb#%d", mcs->usbdev->devnum);
mcs->irlap = irlap_open(netdev, &mcs->qos, hwname);
if (!mcs->irlap) {
IRDA_ERROR("mcs7780: irlap_open failed\n");
goto error2;
}
if (!mcs_setup_urbs(mcs))
goto error3;
ret = mcs_receive_start(mcs);
if (ret)
goto error3;
netif_start_queue(netdev);
return 0;
error3:
irlap_close(mcs->irlap);
error2:
kfree_skb(mcs->rx_buff.skb);
error1:
return ret;
}
static void mcs_receive_irq(struct urb *urb)
{
__u8 *bytes;
struct mcs_cb *mcs = urb->context;
int i;
int ret;
if (!netif_running(mcs->netdev))
return;
if (urb->status)
return;
if (urb->actual_length > 0) {
bytes = urb->transfer_buffer;
if(mcs->speed < 576000) {
async_unwrap_char(mcs->netdev, &mcs->netdev->stats,
&mcs->rx_buff, 0xc0);
for (i = 0; i < urb->actual_length; i++)
async_unwrap_char(mcs->netdev, &mcs->netdev->stats,
&mcs->rx_buff, bytes[i]);
async_unwrap_char(mcs->netdev, &mcs->netdev->stats,
&mcs->rx_buff, 0xc1);
}
else if(mcs->speed == 576000 || mcs->speed == 1152000) {
mcs_unwrap_mir(mcs, urb->transfer_buffer,
urb->actual_length);
}
else {
mcs_unwrap_fir(mcs, urb->transfer_buffer,
urb->actual_length);
}
do_gettimeofday(&mcs->rx_time);
}
ret = usb_submit_urb(urb, GFP_ATOMIC);
}
static void mcs_send_irq(struct urb *urb)
{
struct mcs_cb *mcs = urb->context;
struct net_device *ndev = mcs->netdev;
if (unlikely(mcs->new_speed))
schedule_work(&mcs->work);
else
netif_wake_queue(ndev);
}
static netdev_tx_t mcs_hard_xmit(struct sk_buff *skb,
struct net_device *ndev)
{
unsigned long flags;
struct mcs_cb *mcs;
int wraplen;
int ret = 0;
netif_stop_queue(ndev);
mcs = netdev_priv(ndev);
spin_lock_irqsave(&mcs->lock, flags);
mcs->new_speed = irda_get_next_speed(skb);
if (likely(mcs->new_speed == mcs->speed))
mcs->new_speed = 0;
if(mcs->speed < 576000) {
wraplen = mcs_wrap_sir_skb(skb, mcs->out_buf);
}
else if(mcs->speed == 576000 || mcs->speed == 1152000) {
wraplen = mcs_wrap_mir_skb(skb, mcs->out_buf);
}
else {
wraplen = mcs_wrap_fir_skb(skb, mcs->out_buf);
}
usb_fill_bulk_urb(mcs->tx_urb, mcs->usbdev,
usb_sndbulkpipe(mcs->usbdev, mcs->ep_out),
mcs->out_buf, wraplen, mcs_send_irq, mcs);
if ((ret = usb_submit_urb(mcs->tx_urb, GFP_ATOMIC))) {
IRDA_ERROR("failed tx_urb: %d\n", ret);
switch (ret) {
case -ENODEV:
case -EPIPE:
break;
default:
mcs->netdev->stats.tx_errors++;
netif_start_queue(ndev);
}
} else {
mcs->netdev->stats.tx_packets++;
mcs->netdev->stats.tx_bytes += skb->len;
}
dev_kfree_skb(skb);
spin_unlock_irqrestore(&mcs->lock, flags);
return NETDEV_TX_OK;
}
static int mcs_probe(struct usb_interface *intf,
const struct usb_device_id *id)
{
struct usb_device *udev = interface_to_usbdev(intf);
struct net_device *ndev = NULL;
struct mcs_cb *mcs;
int ret = -ENOMEM;
ndev = alloc_irdadev(sizeof(*mcs));
if (!ndev)
goto error1;
IRDA_DEBUG(1, "MCS7780 USB-IrDA bridge found at %d.\n", udev->devnum);
SET_NETDEV_DEV(ndev, &intf->dev);
ret = usb_reset_configuration(udev);
if (ret != 0) {
IRDA_ERROR("mcs7780: usb reset configuration failed\n");
goto error2;
}
mcs = netdev_priv(ndev);
mcs->usbdev = udev;
mcs->netdev = ndev;
spin_lock_init(&mcs->lock);
irda_init_max_qos_capabilies(&mcs->qos);
mcs->qos.baud_rate.bits &=
IR_2400 | IR_9600 | IR_19200 | IR_38400 | IR_57600 | IR_115200
| IR_576000 | IR_1152000 | (IR_4000000 << 8);
mcs->qos.min_turn_time.bits &= qos_mtt_bits;
irda_qos_bits_to_value(&mcs->qos);
INIT_WORK(&mcs->work, mcs_speed_work);
ndev->netdev_ops = &mcs_netdev_ops;
if (!intf->cur_altsetting) {
ret = -ENOMEM;
goto error2;
}
ret = mcs_find_endpoints(mcs, intf->cur_altsetting->endpoint,
intf->cur_altsetting->desc.bNumEndpoints);
if (!ret) {
ret = -ENODEV;
goto error2;
}
ret = register_netdev(ndev);
if (ret != 0)
goto error2;
IRDA_DEBUG(1, "IrDA: Registered MosChip MCS7780 device as %s\n",
ndev->name);
mcs->transceiver_type = transceiver_type;
mcs->sir_tweak = sir_tweak;
mcs->receive_mode = receive_mode;
usb_set_intfdata(intf, mcs);
return 0;
error2:
free_netdev(ndev);
error1:
return ret;
}
static void mcs_disconnect(struct usb_interface *intf)
{
struct mcs_cb *mcs = usb_get_intfdata(intf);
if (!mcs)
return;
cancel_work_sync(&mcs->work);
unregister_netdev(mcs->netdev);
free_netdev(mcs->netdev);
usb_set_intfdata(intf, NULL);
IRDA_DEBUG(0, "MCS7780 now disconnected.\n");
}
