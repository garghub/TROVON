static void nokia_flow_control(struct serdev_device *serdev, bool enable)
{
if (enable) {
serdev_device_set_rts(serdev, true);
serdev_device_set_flow_control(serdev, true);
} else {
serdev_device_set_flow_control(serdev, false);
serdev_device_set_rts(serdev, false);
}
}
static irqreturn_t wakeup_handler(int irq, void *data)
{
struct nokia_bt_dev *btdev = data;
struct device *dev = &btdev->serdev->dev;
int wake_state = gpiod_get_value(btdev->wakeup_host);
if (btdev->rx_enabled == wake_state)
return IRQ_HANDLED;
if (wake_state)
pm_runtime_get(dev);
else
pm_runtime_put(dev);
btdev->rx_enabled = wake_state;
return IRQ_HANDLED;
}
static int nokia_reset(struct hci_uart *hu)
{
struct nokia_bt_dev *btdev = hu->priv;
struct device *dev = &btdev->serdev->dev;
int err;
gpiod_set_value_cansleep(btdev->reset, 1);
gpiod_set_value_cansleep(btdev->wakeup_bt, 1);
msleep(100);
err = gpiod_get_value_cansleep(btdev->wakeup_host);
if (err == 1) {
dev_err(dev, "reset: host wakeup not low!");
return -EPROTO;
}
serdev_device_write_flush(btdev->serdev);
nokia_flow_control(btdev->serdev, false);
serdev_device_set_baudrate(btdev->serdev, INIT_BAUD_RATE);
gpiod_set_value_cansleep(btdev->reset, 0);
err = serdev_device_wait_for_cts(btdev->serdev, true, 200);
if (err < 0) {
dev_err(dev, "CTS not received: %d", err);
return err;
}
nokia_flow_control(btdev->serdev, true);
return 0;
}
static int nokia_send_alive_packet(struct hci_uart *hu)
{
struct nokia_bt_dev *btdev = hu->priv;
struct device *dev = &btdev->serdev->dev;
struct hci_nokia_alive_hdr *hdr;
struct hci_nokia_alive_pkt *pkt;
struct sk_buff *skb;
int len;
init_completion(&btdev->init_completion);
len = H4_TYPE_SIZE + sizeof(*hdr) + sizeof(*pkt);
skb = bt_skb_alloc(len, GFP_KERNEL);
if (!skb)
return -ENOMEM;
hci_skb_pkt_type(skb) = HCI_NOKIA_ALIVE_PKT;
memset(skb->data, 0x00, len);
hdr = skb_put(skb, sizeof(*hdr));
hdr->dlen = sizeof(*pkt);
pkt = skb_put(skb, sizeof(*pkt));
pkt->mid = NOKIA_ALIVE_REQ;
nokia_enqueue(hu, skb);
hci_uart_tx_wakeup(hu);
dev_dbg(dev, "Alive sent");
if (!wait_for_completion_interruptible_timeout(&btdev->init_completion,
msecs_to_jiffies(1000))) {
return -ETIMEDOUT;
}
if (btdev->init_error < 0)
return btdev->init_error;
return 0;
}
static int nokia_send_negotiation(struct hci_uart *hu)
{
struct nokia_bt_dev *btdev = hu->priv;
struct device *dev = &btdev->serdev->dev;
struct hci_nokia_neg_cmd *neg_cmd;
struct hci_nokia_neg_hdr *neg_hdr;
struct sk_buff *skb;
int len, err;
u16 baud = DIV_ROUND_CLOSEST(btdev->sysclk_speed * 10, SETUP_BAUD_RATE);
int sysclk = btdev->sysclk_speed / 1000;
len = H4_TYPE_SIZE + sizeof(*neg_hdr) + sizeof(*neg_cmd);
skb = bt_skb_alloc(len, GFP_KERNEL);
if (!skb)
return -ENOMEM;
hci_skb_pkt_type(skb) = HCI_NOKIA_NEG_PKT;
neg_hdr = skb_put(skb, sizeof(*neg_hdr));
neg_hdr->dlen = sizeof(*neg_cmd);
neg_cmd = skb_put(skb, sizeof(*neg_cmd));
neg_cmd->ack = NOKIA_NEG_REQ;
neg_cmd->baud = cpu_to_le16(baud);
neg_cmd->unused1 = 0x0000;
neg_cmd->proto = NOKIA_PROTO_BYTE;
neg_cmd->sys_clk = cpu_to_le16(sysclk);
neg_cmd->unused2 = 0x0000;
btdev->init_error = 0;
init_completion(&btdev->init_completion);
nokia_enqueue(hu, skb);
hci_uart_tx_wakeup(hu);
dev_dbg(dev, "Negotiation sent");
if (!wait_for_completion_interruptible_timeout(&btdev->init_completion,
msecs_to_jiffies(10000))) {
return -ETIMEDOUT;
}
if (btdev->init_error < 0)
return btdev->init_error;
nokia_flow_control(btdev->serdev, false);
serdev_device_set_baudrate(btdev->serdev, SETUP_BAUD_RATE);
err = serdev_device_wait_for_cts(btdev->serdev, true, 200);
if (err < 0) {
dev_err(dev, "CTS not received: %d", err);
return err;
}
nokia_flow_control(btdev->serdev, true);
dev_dbg(dev, "Negotiation successful");
return 0;
}
static int nokia_setup_fw(struct hci_uart *hu)
{
struct nokia_bt_dev *btdev = hu->priv;
struct device *dev = &btdev->serdev->dev;
const char *fwname;
const struct firmware *fw;
const u8 *fw_ptr;
size_t fw_size;
int err;
dev_dbg(dev, "setup firmware");
if (btdev->man_id == NOKIA_ID_BCM2048) {
fwname = FIRMWARE_BCM2048;
} else if (btdev->man_id == NOKIA_ID_TI1271) {
fwname = FIRMWARE_TI1271;
} else {
dev_err(dev, "Unsupported bluetooth device!");
return -ENODEV;
}
err = request_firmware(&fw, fwname, dev);
if (err < 0) {
dev_err(dev, "%s: Failed to load Nokia firmware file (%d)",
hu->hdev->name, err);
return err;
}
fw_ptr = fw->data;
fw_size = fw->size;
while (fw_size >= 4) {
u16 pkt_size = get_unaligned_le16(fw_ptr);
u8 pkt_type = fw_ptr[2];
const struct hci_command_hdr *cmd;
u16 opcode;
struct sk_buff *skb;
switch (pkt_type) {
case HCI_COMMAND_PKT:
cmd = (struct hci_command_hdr *)(fw_ptr + 3);
opcode = le16_to_cpu(cmd->opcode);
skb = __hci_cmd_sync(hu->hdev, opcode, cmd->plen,
fw_ptr + 3 + HCI_COMMAND_HDR_SIZE,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
err = PTR_ERR(skb);
dev_err(dev, "%s: FW command %04x failed (%d)",
hu->hdev->name, opcode, err);
goto done;
}
kfree_skb(skb);
break;
case HCI_NOKIA_RADIO_PKT:
case HCI_NOKIA_NEG_PKT:
case HCI_NOKIA_ALIVE_PKT:
break;
}
fw_ptr += pkt_size + 2;
fw_size -= pkt_size + 2;
}
done:
release_firmware(fw);
return err;
}
static int nokia_setup(struct hci_uart *hu)
{
struct nokia_bt_dev *btdev = hu->priv;
struct device *dev = &btdev->serdev->dev;
int err;
btdev->initialized = false;
nokia_flow_control(btdev->serdev, false);
pm_runtime_get_sync(dev);
if (btdev->tx_enabled) {
gpiod_set_value_cansleep(btdev->wakeup_bt, 0);
pm_runtime_put(&btdev->serdev->dev);
btdev->tx_enabled = false;
}
dev_dbg(dev, "protocol setup");
err = nokia_reset(hu);
if (err < 0) {
dev_err(dev, "Reset failed: %d", err);
goto out;
}
err = nokia_send_negotiation(hu);
if (err < 0) {
dev_err(dev, "Negotiation failed: %d", err);
goto out;
}
err = nokia_send_alive_packet(hu);
if (err < 0) {
dev_err(dev, "Alive check failed: %d", err);
goto out;
}
err = nokia_setup_fw(hu);
if (err < 0) {
dev_err(dev, "Could not setup FW: %d", err);
goto out;
}
nokia_flow_control(btdev->serdev, false);
serdev_device_set_baudrate(btdev->serdev, MAX_BAUD_RATE);
nokia_flow_control(btdev->serdev, true);
if (btdev->man_id == NOKIA_ID_BCM2048) {
hu->hdev->set_bdaddr = btbcm_set_bdaddr;
set_bit(HCI_QUIRK_INVALID_BDADDR, &hu->hdev->quirks);
dev_dbg(dev, "bcm2048 has invalid bluetooth address!");
}
dev_dbg(dev, "protocol setup done!");
gpiod_set_value_cansleep(btdev->wakeup_bt, 0);
pm_runtime_put(dev);
btdev->tx_enabled = false;
btdev->initialized = true;
return 0;
out:
pm_runtime_put(dev);
return err;
}
static int nokia_open(struct hci_uart *hu)
{
struct device *dev = &hu->serdev->dev;
dev_dbg(dev, "protocol open");
serdev_device_open(hu->serdev);
pm_runtime_enable(dev);
return 0;
}
static int nokia_flush(struct hci_uart *hu)
{
struct nokia_bt_dev *btdev = hu->priv;
dev_dbg(&btdev->serdev->dev, "flush device");
skb_queue_purge(&btdev->txq);
return 0;
}
static int nokia_close(struct hci_uart *hu)
{
struct nokia_bt_dev *btdev = hu->priv;
struct device *dev = &btdev->serdev->dev;
dev_dbg(dev, "close device");
btdev->initialized = false;
skb_queue_purge(&btdev->txq);
kfree_skb(btdev->rx_skb);
gpiod_set_value(btdev->reset, 1);
gpiod_set_value(btdev->wakeup_bt, 0);
pm_runtime_disable(&btdev->serdev->dev);
serdev_device_close(btdev->serdev);
return 0;
}
static int nokia_enqueue(struct hci_uart *hu, struct sk_buff *skb)
{
struct nokia_bt_dev *btdev = hu->priv;
int err;
memcpy(skb_push(skb, 1), &bt_cb(skb)->pkt_type, 1);
if (skb->len % 2) {
err = skb_pad(skb, 1);
if (err)
return err;
skb_put_u8(skb, 0x00);
}
skb_queue_tail(&btdev->txq, skb);
return 0;
}
static int nokia_recv_negotiation_packet(struct hci_dev *hdev,
struct sk_buff *skb)
{
struct hci_uart *hu = hci_get_drvdata(hdev);
struct nokia_bt_dev *btdev = hu->priv;
struct device *dev = &btdev->serdev->dev;
struct hci_nokia_neg_hdr *hdr;
struct hci_nokia_neg_evt *evt;
int ret = 0;
hdr = (struct hci_nokia_neg_hdr *)skb->data;
if (hdr->dlen != sizeof(*evt)) {
btdev->init_error = -EIO;
ret = -EIO;
goto finish_neg;
}
evt = skb_pull(skb, sizeof(*hdr));
if (evt->ack != NOKIA_NEG_ACK) {
dev_err(dev, "Negotiation received: wrong reply");
btdev->init_error = -EINVAL;
ret = -EINVAL;
goto finish_neg;
}
btdev->man_id = evt->man_id;
btdev->ver_id = evt->ver_id;
dev_dbg(dev, "Negotiation received: baud=%u:clk=%u:manu=%u:vers=%u",
evt->baud, evt->sys_clk, evt->man_id, evt->ver_id);
finish_neg:
complete(&btdev->init_completion);
kfree_skb(skb);
return ret;
}
static int nokia_recv_alive_packet(struct hci_dev *hdev, struct sk_buff *skb)
{
struct hci_uart *hu = hci_get_drvdata(hdev);
struct nokia_bt_dev *btdev = hu->priv;
struct device *dev = &btdev->serdev->dev;
struct hci_nokia_alive_hdr *hdr;
struct hci_nokia_alive_pkt *pkt;
int ret = 0;
hdr = (struct hci_nokia_alive_hdr *)skb->data;
if (hdr->dlen != sizeof(*pkt)) {
dev_err(dev, "Corrupted alive message");
btdev->init_error = -EIO;
ret = -EIO;
goto finish_alive;
}
pkt = skb_pull(skb, sizeof(*hdr));
if (pkt->mid != NOKIA_ALIVE_RESP) {
dev_err(dev, "Alive received: invalid response: 0x%02x!",
pkt->mid);
btdev->init_error = -EINVAL;
ret = -EINVAL;
goto finish_alive;
}
dev_dbg(dev, "Alive received");
finish_alive:
complete(&btdev->init_completion);
kfree_skb(skb);
return ret;
}
static int nokia_recv_radio(struct hci_dev *hdev, struct sk_buff *skb)
{
hci_skb_pkt_type(skb) = HCI_EVENT_PKT;
return hci_recv_frame(hdev, skb);
}
static int nokia_recv(struct hci_uart *hu, const void *data, int count)
{
struct nokia_bt_dev *btdev = hu->priv;
struct device *dev = &btdev->serdev->dev;
int err;
if (!test_bit(HCI_UART_REGISTERED, &hu->flags))
return -EUNATCH;
btdev->rx_skb = h4_recv_buf(hu->hdev, btdev->rx_skb, data, count,
nokia_recv_pkts, ARRAY_SIZE(nokia_recv_pkts));
if (IS_ERR(btdev->rx_skb)) {
err = PTR_ERR(btdev->rx_skb);
dev_err(dev, "Frame reassembly failed (%d)", err);
btdev->rx_skb = NULL;
return err;
}
return count;
}
static struct sk_buff *nokia_dequeue(struct hci_uart *hu)
{
struct nokia_bt_dev *btdev = hu->priv;
struct device *dev = &btdev->serdev->dev;
struct sk_buff *result = skb_dequeue(&btdev->txq);
if (!btdev->initialized)
return result;
if (btdev->tx_enabled == !!result)
return result;
if (result) {
pm_runtime_get_sync(dev);
gpiod_set_value_cansleep(btdev->wakeup_bt, 1);
} else {
serdev_device_wait_until_sent(btdev->serdev, 0);
gpiod_set_value_cansleep(btdev->wakeup_bt, 0);
pm_runtime_put(dev);
}
btdev->tx_enabled = !!result;
return result;
}
static int nokia_bluetooth_serdev_probe(struct serdev_device *serdev)
{
struct device *dev = &serdev->dev;
struct nokia_bt_dev *btdev;
struct clk *sysclk;
int err = 0;
btdev = devm_kzalloc(dev, sizeof(*btdev), GFP_KERNEL);
if (!btdev)
return -ENOMEM;
btdev->hu.serdev = btdev->serdev = serdev;
serdev_device_set_drvdata(serdev, btdev);
btdev->reset = devm_gpiod_get(dev, "reset", GPIOD_OUT_HIGH);
if (IS_ERR(btdev->reset)) {
err = PTR_ERR(btdev->reset);
dev_err(dev, "could not get reset gpio: %d", err);
return err;
}
btdev->wakeup_host = devm_gpiod_get(dev, "host-wakeup", GPIOD_IN);
if (IS_ERR(btdev->wakeup_host)) {
err = PTR_ERR(btdev->wakeup_host);
dev_err(dev, "could not get host wakeup gpio: %d", err);
return err;
}
btdev->wake_irq = gpiod_to_irq(btdev->wakeup_host);
err = devm_request_threaded_irq(dev, btdev->wake_irq, NULL,
wakeup_handler,
IRQF_TRIGGER_RISING | IRQF_TRIGGER_FALLING | IRQF_ONESHOT,
"wakeup", btdev);
if (err) {
dev_err(dev, "could request wakeup irq: %d", err);
return err;
}
btdev->wakeup_bt = devm_gpiod_get(dev, "bluetooth-wakeup",
GPIOD_OUT_LOW);
if (IS_ERR(btdev->wakeup_bt)) {
err = PTR_ERR(btdev->wakeup_bt);
dev_err(dev, "could not get BT wakeup gpio: %d", err);
return err;
}
sysclk = devm_clk_get(dev, "sysclk");
if (IS_ERR(sysclk)) {
err = PTR_ERR(sysclk);
dev_err(dev, "could not get sysclk: %d", err);
return err;
}
clk_prepare_enable(sysclk);
btdev->sysclk_speed = clk_get_rate(sysclk);
clk_disable_unprepare(sysclk);
skb_queue_head_init(&btdev->txq);
btdev->hu.priv = btdev;
btdev->hu.alignment = 2;
err = hci_uart_register_device(&btdev->hu, &nokia_proto);
if (err) {
dev_err(dev, "could not register bluetooth uart: %d", err);
return err;
}
return 0;
}
static void nokia_bluetooth_serdev_remove(struct serdev_device *serdev)
{
struct nokia_bt_dev *btdev = serdev_device_get_drvdata(serdev);
hci_uart_unregister_device(&btdev->hu);
}
static int nokia_bluetooth_runtime_suspend(struct device *dev)
{
struct serdev_device *serdev = to_serdev_device(dev);
nokia_flow_control(serdev, false);
return 0;
}
static int nokia_bluetooth_runtime_resume(struct device *dev)
{
struct serdev_device *serdev = to_serdev_device(dev);
nokia_flow_control(serdev, true);
return 0;
}
