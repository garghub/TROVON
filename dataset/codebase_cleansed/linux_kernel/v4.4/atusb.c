static int atusb_control_msg(struct atusb *atusb, unsigned int pipe,
__u8 request, __u8 requesttype,
__u16 value, __u16 index,
void *data, __u16 size, int timeout)
{
struct usb_device *usb_dev = atusb->usb_dev;
int ret;
if (atusb->err)
return atusb->err;
ret = usb_control_msg(usb_dev, pipe, request, requesttype,
value, index, data, size, timeout);
if (ret < 0) {
atusb->err = ret;
dev_err(&usb_dev->dev,
"atusb_control_msg: req 0x%02x val 0x%x idx 0x%x, error %d\n",
request, value, index, ret);
}
return ret;
}
static int atusb_command(struct atusb *atusb, uint8_t cmd, uint8_t arg)
{
struct usb_device *usb_dev = atusb->usb_dev;
dev_dbg(&usb_dev->dev, "atusb_command: cmd = 0x%x\n", cmd);
return atusb_control_msg(atusb, usb_sndctrlpipe(usb_dev, 0),
cmd, ATUSB_REQ_TO_DEV, arg, 0, NULL, 0, 1000);
}
static int atusb_write_reg(struct atusb *atusb, uint8_t reg, uint8_t value)
{
struct usb_device *usb_dev = atusb->usb_dev;
dev_dbg(&usb_dev->dev, "atusb_write_reg: 0x%02x <- 0x%02x\n",
reg, value);
return atusb_control_msg(atusb, usb_sndctrlpipe(usb_dev, 0),
ATUSB_REG_WRITE, ATUSB_REQ_TO_DEV,
value, reg, NULL, 0, 1000);
}
static int atusb_read_reg(struct atusb *atusb, uint8_t reg)
{
struct usb_device *usb_dev = atusb->usb_dev;
int ret;
uint8_t value;
dev_dbg(&usb_dev->dev, "atusb: reg = 0x%x\n", reg);
ret = atusb_control_msg(atusb, usb_rcvctrlpipe(usb_dev, 0),
ATUSB_REG_READ, ATUSB_REQ_FROM_DEV,
0, reg, &value, 1, 1000);
return ret >= 0 ? value : ret;
}
static int atusb_write_subreg(struct atusb *atusb, uint8_t reg, uint8_t mask,
uint8_t shift, uint8_t value)
{
struct usb_device *usb_dev = atusb->usb_dev;
uint8_t orig, tmp;
int ret = 0;
dev_dbg(&usb_dev->dev, "atusb_write_subreg: 0x%02x <- 0x%02x\n",
reg, value);
orig = atusb_read_reg(atusb, reg);
tmp = orig & ~mask;
tmp |= (value << shift) & mask;
if (tmp != orig)
ret = atusb_write_reg(atusb, reg, tmp);
return ret;
}
static int atusb_get_and_clear_error(struct atusb *atusb)
{
int err = atusb->err;
atusb->err = 0;
return err;
}
static int atusb_submit_rx_urb(struct atusb *atusb, struct urb *urb)
{
struct usb_device *usb_dev = atusb->usb_dev;
struct sk_buff *skb = urb->context;
int ret;
if (!skb) {
skb = alloc_skb(MAX_RX_XFER, GFP_KERNEL);
if (!skb) {
dev_warn_ratelimited(&usb_dev->dev,
"atusb_in: can't allocate skb\n");
return -ENOMEM;
}
skb_put(skb, MAX_RX_XFER);
SKB_ATUSB(skb) = atusb;
}
usb_fill_bulk_urb(urb, usb_dev, usb_rcvbulkpipe(usb_dev, 1),
skb->data, MAX_RX_XFER, atusb_in, skb);
usb_anchor_urb(urb, &atusb->rx_urbs);
ret = usb_submit_urb(urb, GFP_KERNEL);
if (ret) {
usb_unanchor_urb(urb);
kfree_skb(skb);
urb->context = NULL;
}
return ret;
}
static void atusb_work_urbs(struct work_struct *work)
{
struct atusb *atusb =
container_of(to_delayed_work(work), struct atusb, work);
struct usb_device *usb_dev = atusb->usb_dev;
struct urb *urb;
int ret;
if (atusb->shutdown)
return;
do {
urb = usb_get_from_anchor(&atusb->idle_urbs);
if (!urb)
return;
ret = atusb_submit_rx_urb(atusb, urb);
} while (!ret);
usb_anchor_urb(urb, &atusb->idle_urbs);
dev_warn_ratelimited(&usb_dev->dev,
"atusb_in: can't allocate/submit URB (%d)\n", ret);
schedule_delayed_work(&atusb->work,
msecs_to_jiffies(ATUSB_ALLOC_DELAY_MS) + 1);
}
static void atusb_tx_done(struct atusb *atusb, uint8_t seq)
{
struct usb_device *usb_dev = atusb->usb_dev;
uint8_t expect = atusb->tx_ack_seq;
dev_dbg(&usb_dev->dev, "atusb_tx_done (0x%02x/0x%02x)\n", seq, expect);
if (seq == expect) {
ieee802154_xmit_complete(atusb->hw, atusb->tx_skb, false);
} else {
ieee802154_wake_queue(atusb->hw);
if (atusb->tx_skb)
dev_kfree_skb_irq(atusb->tx_skb);
}
}
static void atusb_in_good(struct urb *urb)
{
struct usb_device *usb_dev = urb->dev;
struct sk_buff *skb = urb->context;
struct atusb *atusb = SKB_ATUSB(skb);
uint8_t len, lqi;
if (!urb->actual_length) {
dev_dbg(&usb_dev->dev, "atusb_in: zero-sized URB ?\n");
return;
}
len = *skb->data;
if (urb->actual_length == 1) {
atusb_tx_done(atusb, len);
return;
}
if (len + 1 > urb->actual_length - 1) {
dev_dbg(&usb_dev->dev, "atusb_in: frame len %d+1 > URB %u-1\n",
len, urb->actual_length);
return;
}
if (!ieee802154_is_valid_psdu_len(len)) {
dev_dbg(&usb_dev->dev, "atusb_in: frame corrupted\n");
return;
}
lqi = skb->data[len + 1];
dev_dbg(&usb_dev->dev, "atusb_in: rx len %d lqi 0x%02x\n", len, lqi);
skb_pull(skb, 1);
skb_trim(skb, len);
ieee802154_rx_irqsafe(atusb->hw, skb, lqi);
urb->context = NULL;
}
static void atusb_in(struct urb *urb)
{
struct usb_device *usb_dev = urb->dev;
struct sk_buff *skb = urb->context;
struct atusb *atusb = SKB_ATUSB(skb);
dev_dbg(&usb_dev->dev, "atusb_in: status %d len %d\n",
urb->status, urb->actual_length);
if (urb->status) {
if (urb->status == -ENOENT) {
kfree_skb(skb);
urb->context = NULL;
return;
}
dev_dbg(&usb_dev->dev, "atusb_in: URB error %d\n", urb->status);
} else {
atusb_in_good(urb);
}
usb_anchor_urb(urb, &atusb->idle_urbs);
if (!atusb->shutdown)
schedule_delayed_work(&atusb->work, 0);
}
static void atusb_free_urbs(struct atusb *atusb)
{
struct urb *urb;
while (1) {
urb = usb_get_from_anchor(&atusb->idle_urbs);
if (!urb)
break;
if (urb->context)
kfree_skb(urb->context);
usb_free_urb(urb);
}
}
static int atusb_alloc_urbs(struct atusb *atusb, int n)
{
struct urb *urb;
while (n) {
urb = usb_alloc_urb(0, GFP_KERNEL);
if (!urb) {
atusb_free_urbs(atusb);
return -ENOMEM;
}
usb_anchor_urb(urb, &atusb->idle_urbs);
n--;
}
return 0;
}
static void atusb_xmit_complete(struct urb *urb)
{
dev_dbg(&urb->dev->dev, "atusb_xmit urb completed");
}
static int atusb_xmit(struct ieee802154_hw *hw, struct sk_buff *skb)
{
struct atusb *atusb = hw->priv;
struct usb_device *usb_dev = atusb->usb_dev;
int ret;
dev_dbg(&usb_dev->dev, "atusb_xmit (%d)\n", skb->len);
atusb->tx_skb = skb;
atusb->tx_ack_seq++;
atusb->tx_dr.wIndex = cpu_to_le16(atusb->tx_ack_seq);
atusb->tx_dr.wLength = cpu_to_le16(skb->len);
usb_fill_control_urb(atusb->tx_urb, usb_dev,
usb_sndctrlpipe(usb_dev, 0),
(unsigned char *)&atusb->tx_dr, skb->data,
skb->len, atusb_xmit_complete, NULL);
ret = usb_submit_urb(atusb->tx_urb, GFP_ATOMIC);
dev_dbg(&usb_dev->dev, "atusb_xmit done (%d)\n", ret);
return ret;
}
static int atusb_channel(struct ieee802154_hw *hw, u8 page, u8 channel)
{
struct atusb *atusb = hw->priv;
int ret;
ret = atusb_write_reg(atusb, RG_PHY_CC_CCA, channel);
if (ret < 0)
return ret;
msleep(1);
return 0;
}
static int atusb_ed(struct ieee802154_hw *hw, u8 *level)
{
BUG_ON(!level);
*level = 0xbe;
return 0;
}
static int atusb_set_hw_addr_filt(struct ieee802154_hw *hw,
struct ieee802154_hw_addr_filt *filt,
unsigned long changed)
{
struct atusb *atusb = hw->priv;
struct device *dev = &atusb->usb_dev->dev;
if (changed & IEEE802154_AFILT_SADDR_CHANGED) {
u16 addr = le16_to_cpu(filt->short_addr);
dev_vdbg(dev, "atusb_set_hw_addr_filt called for saddr\n");
atusb_write_reg(atusb, RG_SHORT_ADDR_0, addr);
atusb_write_reg(atusb, RG_SHORT_ADDR_1, addr >> 8);
}
if (changed & IEEE802154_AFILT_PANID_CHANGED) {
u16 pan = le16_to_cpu(filt->pan_id);
dev_vdbg(dev, "atusb_set_hw_addr_filt called for pan id\n");
atusb_write_reg(atusb, RG_PAN_ID_0, pan);
atusb_write_reg(atusb, RG_PAN_ID_1, pan >> 8);
}
if (changed & IEEE802154_AFILT_IEEEADDR_CHANGED) {
u8 i, addr[IEEE802154_EXTENDED_ADDR_LEN];
memcpy(addr, &filt->ieee_addr, IEEE802154_EXTENDED_ADDR_LEN);
dev_vdbg(dev, "atusb_set_hw_addr_filt called for IEEE addr\n");
for (i = 0; i < 8; i++)
atusb_write_reg(atusb, RG_IEEE_ADDR_0 + i, addr[i]);
}
if (changed & IEEE802154_AFILT_PANC_CHANGED) {
dev_vdbg(dev,
"atusb_set_hw_addr_filt called for panc change\n");
if (filt->pan_coord)
atusb_write_subreg(atusb, SR_AACK_I_AM_COORD, 1);
else
atusb_write_subreg(atusb, SR_AACK_I_AM_COORD, 0);
}
return atusb_get_and_clear_error(atusb);
}
static int atusb_start(struct ieee802154_hw *hw)
{
struct atusb *atusb = hw->priv;
struct usb_device *usb_dev = atusb->usb_dev;
int ret;
dev_dbg(&usb_dev->dev, "atusb_start\n");
schedule_delayed_work(&atusb->work, 0);
atusb_command(atusb, ATUSB_RX_MODE, 1);
ret = atusb_get_and_clear_error(atusb);
if (ret < 0)
usb_kill_anchored_urbs(&atusb->idle_urbs);
return ret;
}
static void atusb_stop(struct ieee802154_hw *hw)
{
struct atusb *atusb = hw->priv;
struct usb_device *usb_dev = atusb->usb_dev;
dev_dbg(&usb_dev->dev, "atusb_stop\n");
usb_kill_anchored_urbs(&atusb->idle_urbs);
atusb_command(atusb, ATUSB_RX_MODE, 0);
atusb_get_and_clear_error(atusb);
}
static int
atusb_set_txpower(struct ieee802154_hw *hw, s32 mbm)
{
struct atusb *atusb = hw->priv;
u32 i;
for (i = 0; i < hw->phy->supported.tx_powers_size; i++) {
if (hw->phy->supported.tx_powers[i] == mbm)
return atusb_write_subreg(atusb, SR_TX_PWR_23X, i);
}
return -EINVAL;
}
static int
atusb_set_promiscuous_mode(struct ieee802154_hw *hw, const bool on)
{
struct atusb *atusb = hw->priv;
int ret;
if (on) {
ret = atusb_write_subreg(atusb, SR_AACK_DIS_ACK, 1);
if (ret < 0)
return ret;
ret = atusb_write_subreg(atusb, SR_AACK_PROM_MODE, 1);
if (ret < 0)
return ret;
} else {
ret = atusb_write_subreg(atusb, SR_AACK_PROM_MODE, 0);
if (ret < 0)
return ret;
ret = atusb_write_subreg(atusb, SR_AACK_DIS_ACK, 0);
if (ret < 0)
return ret;
}
return 0;
}
static int atusb_get_and_show_revision(struct atusb *atusb)
{
struct usb_device *usb_dev = atusb->usb_dev;
unsigned char buffer[3];
int ret;
ret = atusb_control_msg(atusb, usb_rcvctrlpipe(usb_dev, 0),
ATUSB_ID, ATUSB_REQ_FROM_DEV, 0, 0,
buffer, 3, 1000);
if (ret >= 0)
dev_info(&usb_dev->dev,
"Firmware: major: %u, minor: %u, hardware type: %u\n",
buffer[0], buffer[1], buffer[2]);
if (buffer[0] == 0 && buffer[1] < 2) {
dev_info(&usb_dev->dev,
"Firmware version (%u.%u) is predates our first public release.",
buffer[0], buffer[1]);
dev_info(&usb_dev->dev, "Please update to version 0.2 or newer");
}
return ret;
}
static int atusb_get_and_show_build(struct atusb *atusb)
{
struct usb_device *usb_dev = atusb->usb_dev;
char build[ATUSB_BUILD_SIZE + 1];
int ret;
ret = atusb_control_msg(atusb, usb_rcvctrlpipe(usb_dev, 0),
ATUSB_BUILD, ATUSB_REQ_FROM_DEV, 0, 0,
build, ATUSB_BUILD_SIZE, 1000);
if (ret >= 0) {
build[ret] = 0;
dev_info(&usb_dev->dev, "Firmware: build %s\n", build);
}
return ret;
}
static int atusb_get_and_show_chip(struct atusb *atusb)
{
struct usb_device *usb_dev = atusb->usb_dev;
uint8_t man_id_0, man_id_1, part_num, version_num;
const char *chip;
man_id_0 = atusb_read_reg(atusb, RG_MAN_ID_0);
man_id_1 = atusb_read_reg(atusb, RG_MAN_ID_1);
part_num = atusb_read_reg(atusb, RG_PART_NUM);
version_num = atusb_read_reg(atusb, RG_VERSION_NUM);
if (atusb->err)
return atusb->err;
if ((man_id_1 << 8 | man_id_0) != ATUSB_JEDEC_ATMEL) {
dev_err(&usb_dev->dev,
"non-Atmel transceiver xxxx%02x%02x\n",
man_id_1, man_id_0);
goto fail;
}
switch (part_num) {
case 2:
chip = "AT86RF230";
break;
case 3:
chip = "AT86RF231";
break;
default:
dev_err(&usb_dev->dev,
"unexpected transceiver, part 0x%02x version 0x%02x\n",
part_num, version_num);
goto fail;
}
dev_info(&usb_dev->dev, "ATUSB: %s version %d\n", chip, version_num);
return 0;
fail:
atusb->err = -ENODEV;
return -ENODEV;
}
static int atusb_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
struct usb_device *usb_dev = interface_to_usbdev(interface);
struct ieee802154_hw *hw;
struct atusb *atusb = NULL;
int ret = -ENOMEM;
hw = ieee802154_alloc_hw(sizeof(struct atusb), &atusb_ops);
if (!hw)
return -ENOMEM;
atusb = hw->priv;
atusb->hw = hw;
atusb->usb_dev = usb_get_dev(usb_dev);
usb_set_intfdata(interface, atusb);
atusb->shutdown = 0;
atusb->err = 0;
INIT_DELAYED_WORK(&atusb->work, atusb_work_urbs);
init_usb_anchor(&atusb->idle_urbs);
init_usb_anchor(&atusb->rx_urbs);
if (atusb_alloc_urbs(atusb, ATUSB_NUM_RX_URBS))
goto fail;
atusb->tx_dr.bRequestType = ATUSB_REQ_TO_DEV;
atusb->tx_dr.bRequest = ATUSB_TX;
atusb->tx_dr.wValue = cpu_to_le16(0);
atusb->tx_urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!atusb->tx_urb)
goto fail;
hw->parent = &usb_dev->dev;
hw->flags = IEEE802154_HW_TX_OMIT_CKSUM | IEEE802154_HW_AFILT |
IEEE802154_HW_PROMISCUOUS;
hw->phy->flags = WPAN_PHY_FLAG_TXPOWER;
hw->phy->current_page = 0;
hw->phy->current_channel = 11;
hw->phy->supported.channels[0] = 0x7FFF800;
hw->phy->supported.tx_powers = atusb_powers;
hw->phy->supported.tx_powers_size = ARRAY_SIZE(atusb_powers);
hw->phy->transmit_power = hw->phy->supported.tx_powers[0];
ieee802154_random_extended_addr(&hw->phy->perm_extended_addr);
atusb_command(atusb, ATUSB_RF_RESET, 0);
atusb_get_and_show_chip(atusb);
atusb_get_and_show_revision(atusb);
atusb_get_and_show_build(atusb);
ret = atusb_get_and_clear_error(atusb);
if (ret) {
dev_err(&atusb->usb_dev->dev,
"%s: initialization failed, error = %d\n",
__func__, ret);
goto fail;
}
ret = ieee802154_register_hw(hw);
if (ret)
goto fail;
atusb_write_reg(atusb, RG_TRX_STATE, STATE_FORCE_TRX_OFF);
msleep(1);
#if 0
atusb_write_subreg(atusb, SR_RX_SAFE_MODE, 1);
#endif
atusb_write_reg(atusb, RG_IRQ_MASK, 0xff);
ret = atusb_get_and_clear_error(atusb);
if (!ret)
return 0;
dev_err(&atusb->usb_dev->dev,
"%s: setup failed, error = %d\n",
__func__, ret);
ieee802154_unregister_hw(hw);
fail:
atusb_free_urbs(atusb);
usb_kill_urb(atusb->tx_urb);
usb_free_urb(atusb->tx_urb);
usb_put_dev(usb_dev);
ieee802154_free_hw(hw);
return ret;
}
static void atusb_disconnect(struct usb_interface *interface)
{
struct atusb *atusb = usb_get_intfdata(interface);
dev_dbg(&atusb->usb_dev->dev, "atusb_disconnect\n");
atusb->shutdown = 1;
cancel_delayed_work_sync(&atusb->work);
usb_kill_anchored_urbs(&atusb->rx_urbs);
atusb_free_urbs(atusb);
usb_kill_urb(atusb->tx_urb);
usb_free_urb(atusb->tx_urb);
ieee802154_unregister_hw(atusb->hw);
ieee802154_free_hw(atusb->hw);
usb_set_intfdata(interface, NULL);
usb_put_dev(atusb->usb_dev);
pr_debug("atusb_disconnect done\n");
}
