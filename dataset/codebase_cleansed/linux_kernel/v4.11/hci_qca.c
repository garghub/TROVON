static void __serial_clock_on(struct tty_struct *tty)
{
}
static void __serial_clock_off(struct tty_struct *tty)
{
}
static void serial_clock_vote(unsigned long vote, struct hci_uart *hu)
{
struct qca_data *qca = hu->priv;
unsigned int diff;
bool old_vote = (qca->tx_vote | qca->rx_vote);
bool new_vote;
switch (vote) {
case HCI_IBS_VOTE_STATS_UPDATE:
diff = jiffies_to_msecs(jiffies - qca->vote_last_jif);
if (old_vote)
qca->vote_off_ms += diff;
else
qca->vote_on_ms += diff;
return;
case HCI_IBS_TX_VOTE_CLOCK_ON:
qca->tx_vote = true;
qca->tx_votes_on++;
new_vote = true;
break;
case HCI_IBS_RX_VOTE_CLOCK_ON:
qca->rx_vote = true;
qca->rx_votes_on++;
new_vote = true;
break;
case HCI_IBS_TX_VOTE_CLOCK_OFF:
qca->tx_vote = false;
qca->tx_votes_off++;
new_vote = qca->rx_vote | qca->tx_vote;
break;
case HCI_IBS_RX_VOTE_CLOCK_OFF:
qca->rx_vote = false;
qca->rx_votes_off++;
new_vote = qca->rx_vote | qca->tx_vote;
break;
default:
BT_ERR("Voting irregularity");
return;
}
if (new_vote != old_vote) {
if (new_vote)
__serial_clock_on(hu->tty);
else
__serial_clock_off(hu->tty);
BT_DBG("Vote serial clock %s(%s)", new_vote ? "true" : "false",
vote ? "true" : "false");
diff = jiffies_to_msecs(jiffies - qca->vote_last_jif);
if (new_vote) {
qca->votes_on++;
qca->vote_off_ms += diff;
} else {
qca->votes_off++;
qca->vote_on_ms += diff;
}
qca->vote_last_jif = jiffies;
}
}
static int send_hci_ibs_cmd(u8 cmd, struct hci_uart *hu)
{
int err = 0;
struct sk_buff *skb = NULL;
struct qca_data *qca = hu->priv;
BT_DBG("hu %p send hci ibs cmd 0x%x", hu, cmd);
skb = bt_skb_alloc(1, GFP_ATOMIC);
if (!skb) {
BT_ERR("Failed to allocate memory for HCI_IBS packet");
return -ENOMEM;
}
*skb_put(skb, 1) = cmd;
skb_queue_tail(&qca->txq, skb);
return err;
}
static void qca_wq_awake_device(struct work_struct *work)
{
struct qca_data *qca = container_of(work, struct qca_data,
ws_awake_device);
struct hci_uart *hu = qca->hu;
unsigned long retrans_delay;
BT_DBG("hu %p wq awake device", hu);
serial_clock_vote(HCI_IBS_TX_VOTE_CLOCK_ON, hu);
spin_lock(&qca->hci_ibs_lock);
if (send_hci_ibs_cmd(HCI_IBS_WAKE_IND, hu) < 0)
BT_ERR("Failed to send WAKE to device");
qca->ibs_sent_wakes++;
retrans_delay = msecs_to_jiffies(qca->wake_retrans);
mod_timer(&qca->wake_retrans_timer, jiffies + retrans_delay);
spin_unlock(&qca->hci_ibs_lock);
hci_uart_tx_wakeup(hu);
}
static void qca_wq_awake_rx(struct work_struct *work)
{
struct qca_data *qca = container_of(work, struct qca_data,
ws_awake_rx);
struct hci_uart *hu = qca->hu;
BT_DBG("hu %p wq awake rx", hu);
serial_clock_vote(HCI_IBS_RX_VOTE_CLOCK_ON, hu);
spin_lock(&qca->hci_ibs_lock);
qca->rx_ibs_state = HCI_IBS_RX_AWAKE;
if (send_hci_ibs_cmd(HCI_IBS_WAKE_ACK, hu) < 0)
BT_ERR("Failed to acknowledge device wake up");
qca->ibs_sent_wacks++;
spin_unlock(&qca->hci_ibs_lock);
hci_uart_tx_wakeup(hu);
}
static void qca_wq_serial_rx_clock_vote_off(struct work_struct *work)
{
struct qca_data *qca = container_of(work, struct qca_data,
ws_rx_vote_off);
struct hci_uart *hu = qca->hu;
BT_DBG("hu %p rx clock vote off", hu);
serial_clock_vote(HCI_IBS_RX_VOTE_CLOCK_OFF, hu);
}
static void qca_wq_serial_tx_clock_vote_off(struct work_struct *work)
{
struct qca_data *qca = container_of(work, struct qca_data,
ws_tx_vote_off);
struct hci_uart *hu = qca->hu;
BT_DBG("hu %p tx clock vote off", hu);
hci_uart_tx_wakeup(hu);
serial_clock_vote(HCI_IBS_TX_VOTE_CLOCK_OFF, hu);
}
static void hci_ibs_tx_idle_timeout(unsigned long arg)
{
struct hci_uart *hu = (struct hci_uart *)arg;
struct qca_data *qca = hu->priv;
unsigned long flags;
BT_DBG("hu %p idle timeout in %d state", hu, qca->tx_ibs_state);
spin_lock_irqsave_nested(&qca->hci_ibs_lock,
flags, SINGLE_DEPTH_NESTING);
switch (qca->tx_ibs_state) {
case HCI_IBS_TX_AWAKE:
if (send_hci_ibs_cmd(HCI_IBS_SLEEP_IND, hu) < 0) {
BT_ERR("Failed to send SLEEP to device");
break;
}
qca->tx_ibs_state = HCI_IBS_TX_ASLEEP;
qca->ibs_sent_slps++;
queue_work(qca->workqueue, &qca->ws_tx_vote_off);
break;
case HCI_IBS_TX_ASLEEP:
case HCI_IBS_TX_WAKING:
default:
BT_ERR("Spurious timeout tx state %d", qca->tx_ibs_state);
break;
}
spin_unlock_irqrestore(&qca->hci_ibs_lock, flags);
}
static void hci_ibs_wake_retrans_timeout(unsigned long arg)
{
struct hci_uart *hu = (struct hci_uart *)arg;
struct qca_data *qca = hu->priv;
unsigned long flags, retrans_delay;
bool retransmit = false;
BT_DBG("hu %p wake retransmit timeout in %d state",
hu, qca->tx_ibs_state);
spin_lock_irqsave_nested(&qca->hci_ibs_lock,
flags, SINGLE_DEPTH_NESTING);
switch (qca->tx_ibs_state) {
case HCI_IBS_TX_WAKING:
retransmit = true;
if (send_hci_ibs_cmd(HCI_IBS_WAKE_IND, hu) < 0) {
BT_ERR("Failed to acknowledge device wake up");
break;
}
qca->ibs_sent_wakes++;
retrans_delay = msecs_to_jiffies(qca->wake_retrans);
mod_timer(&qca->wake_retrans_timer, jiffies + retrans_delay);
break;
case HCI_IBS_TX_ASLEEP:
case HCI_IBS_TX_AWAKE:
default:
BT_ERR("Spurious timeout tx state %d", qca->tx_ibs_state);
break;
}
spin_unlock_irqrestore(&qca->hci_ibs_lock, flags);
if (retransmit)
hci_uart_tx_wakeup(hu);
}
static int qca_open(struct hci_uart *hu)
{
struct qca_data *qca;
BT_DBG("hu %p qca_open", hu);
qca = kzalloc(sizeof(struct qca_data), GFP_ATOMIC);
if (!qca)
return -ENOMEM;
skb_queue_head_init(&qca->txq);
skb_queue_head_init(&qca->tx_wait_q);
spin_lock_init(&qca->hci_ibs_lock);
qca->workqueue = alloc_ordered_workqueue("qca_wq", 0);
if (!qca->workqueue) {
BT_ERR("QCA Workqueue not initialized properly");
kfree(qca);
return -ENOMEM;
}
INIT_WORK(&qca->ws_awake_rx, qca_wq_awake_rx);
INIT_WORK(&qca->ws_awake_device, qca_wq_awake_device);
INIT_WORK(&qca->ws_rx_vote_off, qca_wq_serial_rx_clock_vote_off);
INIT_WORK(&qca->ws_tx_vote_off, qca_wq_serial_tx_clock_vote_off);
qca->hu = hu;
qca->tx_ibs_state = HCI_IBS_TX_ASLEEP;
qca->rx_ibs_state = HCI_IBS_RX_ASLEEP;
qca->tx_vote = false;
qca->rx_vote = false;
qca->flags = 0;
qca->ibs_sent_wacks = 0;
qca->ibs_sent_slps = 0;
qca->ibs_sent_wakes = 0;
qca->ibs_recv_wacks = 0;
qca->ibs_recv_slps = 0;
qca->ibs_recv_wakes = 0;
qca->vote_last_jif = jiffies;
qca->vote_on_ms = 0;
qca->vote_off_ms = 0;
qca->votes_on = 0;
qca->votes_off = 0;
qca->tx_votes_on = 0;
qca->tx_votes_off = 0;
qca->rx_votes_on = 0;
qca->rx_votes_off = 0;
hu->priv = qca;
setup_timer(&qca->wake_retrans_timer, hci_ibs_wake_retrans_timeout,
(u_long)hu);
qca->wake_retrans = IBS_WAKE_RETRANS_TIMEOUT_MS;
setup_timer(&qca->tx_idle_timer, hci_ibs_tx_idle_timeout, (u_long)hu);
qca->tx_idle_delay = IBS_TX_IDLE_TIMEOUT_MS;
BT_DBG("HCI_UART_QCA open, tx_idle_delay=%u, wake_retrans=%u",
qca->tx_idle_delay, qca->wake_retrans);
return 0;
}
static void qca_debugfs_init(struct hci_dev *hdev)
{
struct hci_uart *hu = hci_get_drvdata(hdev);
struct qca_data *qca = hu->priv;
struct dentry *ibs_dir;
umode_t mode;
if (!hdev->debugfs)
return;
ibs_dir = debugfs_create_dir("ibs", hdev->debugfs);
mode = S_IRUGO;
debugfs_create_u8("tx_ibs_state", mode, ibs_dir, &qca->tx_ibs_state);
debugfs_create_u8("rx_ibs_state", mode, ibs_dir, &qca->rx_ibs_state);
debugfs_create_u64("ibs_sent_sleeps", mode, ibs_dir,
&qca->ibs_sent_slps);
debugfs_create_u64("ibs_sent_wakes", mode, ibs_dir,
&qca->ibs_sent_wakes);
debugfs_create_u64("ibs_sent_wake_acks", mode, ibs_dir,
&qca->ibs_sent_wacks);
debugfs_create_u64("ibs_recv_sleeps", mode, ibs_dir,
&qca->ibs_recv_slps);
debugfs_create_u64("ibs_recv_wakes", mode, ibs_dir,
&qca->ibs_recv_wakes);
debugfs_create_u64("ibs_recv_wake_acks", mode, ibs_dir,
&qca->ibs_recv_wacks);
debugfs_create_bool("tx_vote", mode, ibs_dir, &qca->tx_vote);
debugfs_create_u64("tx_votes_on", mode, ibs_dir, &qca->tx_votes_on);
debugfs_create_u64("tx_votes_off", mode, ibs_dir, &qca->tx_votes_off);
debugfs_create_bool("rx_vote", mode, ibs_dir, &qca->rx_vote);
debugfs_create_u64("rx_votes_on", mode, ibs_dir, &qca->rx_votes_on);
debugfs_create_u64("rx_votes_off", mode, ibs_dir, &qca->rx_votes_off);
debugfs_create_u64("votes_on", mode, ibs_dir, &qca->votes_on);
debugfs_create_u64("votes_off", mode, ibs_dir, &qca->votes_off);
debugfs_create_u32("vote_on_ms", mode, ibs_dir, &qca->vote_on_ms);
debugfs_create_u32("vote_off_ms", mode, ibs_dir, &qca->vote_off_ms);
mode = S_IRUGO | S_IWUSR;
debugfs_create_u32("wake_retrans", mode, ibs_dir, &qca->wake_retrans);
debugfs_create_u32("tx_idle_delay", mode, ibs_dir,
&qca->tx_idle_delay);
}
static int qca_flush(struct hci_uart *hu)
{
struct qca_data *qca = hu->priv;
BT_DBG("hu %p qca flush", hu);
skb_queue_purge(&qca->tx_wait_q);
skb_queue_purge(&qca->txq);
return 0;
}
static int qca_close(struct hci_uart *hu)
{
struct qca_data *qca = hu->priv;
BT_DBG("hu %p qca close", hu);
serial_clock_vote(HCI_IBS_VOTE_STATS_UPDATE, hu);
skb_queue_purge(&qca->tx_wait_q);
skb_queue_purge(&qca->txq);
del_timer(&qca->tx_idle_timer);
del_timer(&qca->wake_retrans_timer);
destroy_workqueue(qca->workqueue);
qca->hu = NULL;
kfree_skb(qca->rx_skb);
hu->priv = NULL;
kfree(qca);
return 0;
}
static void device_want_to_wakeup(struct hci_uart *hu)
{
unsigned long flags;
struct qca_data *qca = hu->priv;
BT_DBG("hu %p want to wake up", hu);
spin_lock_irqsave(&qca->hci_ibs_lock, flags);
qca->ibs_recv_wakes++;
switch (qca->rx_ibs_state) {
case HCI_IBS_RX_ASLEEP:
queue_work(qca->workqueue, &qca->ws_awake_rx);
spin_unlock_irqrestore(&qca->hci_ibs_lock, flags);
return;
case HCI_IBS_RX_AWAKE:
if (send_hci_ibs_cmd(HCI_IBS_WAKE_ACK, hu) < 0) {
BT_ERR("Failed to acknowledge device wake up");
break;
}
qca->ibs_sent_wacks++;
break;
default:
BT_ERR("Received HCI_IBS_WAKE_IND in rx state %d",
qca->rx_ibs_state);
break;
}
spin_unlock_irqrestore(&qca->hci_ibs_lock, flags);
hci_uart_tx_wakeup(hu);
}
static void device_want_to_sleep(struct hci_uart *hu)
{
unsigned long flags;
struct qca_data *qca = hu->priv;
BT_DBG("hu %p want to sleep", hu);
spin_lock_irqsave(&qca->hci_ibs_lock, flags);
qca->ibs_recv_slps++;
switch (qca->rx_ibs_state) {
case HCI_IBS_RX_AWAKE:
qca->rx_ibs_state = HCI_IBS_RX_ASLEEP;
queue_work(qca->workqueue, &qca->ws_rx_vote_off);
break;
case HCI_IBS_RX_ASLEEP:
default:
BT_ERR("Received HCI_IBS_SLEEP_IND in rx state %d",
qca->rx_ibs_state);
break;
}
spin_unlock_irqrestore(&qca->hci_ibs_lock, flags);
}
static void device_woke_up(struct hci_uart *hu)
{
unsigned long flags, idle_delay;
struct qca_data *qca = hu->priv;
struct sk_buff *skb = NULL;
BT_DBG("hu %p woke up", hu);
spin_lock_irqsave(&qca->hci_ibs_lock, flags);
qca->ibs_recv_wacks++;
switch (qca->tx_ibs_state) {
case HCI_IBS_TX_AWAKE:
BT_DBG("Received HCI_IBS_WAKE_ACK in tx state %d",
qca->tx_ibs_state);
break;
case HCI_IBS_TX_WAKING:
while ((skb = skb_dequeue(&qca->tx_wait_q)))
skb_queue_tail(&qca->txq, skb);
del_timer(&qca->wake_retrans_timer);
idle_delay = msecs_to_jiffies(qca->tx_idle_delay);
mod_timer(&qca->tx_idle_timer, jiffies + idle_delay);
qca->tx_ibs_state = HCI_IBS_TX_AWAKE;
break;
case HCI_IBS_TX_ASLEEP:
default:
BT_ERR("Received HCI_IBS_WAKE_ACK in tx state %d",
qca->tx_ibs_state);
break;
}
spin_unlock_irqrestore(&qca->hci_ibs_lock, flags);
hci_uart_tx_wakeup(hu);
}
static int qca_enqueue(struct hci_uart *hu, struct sk_buff *skb)
{
unsigned long flags = 0, idle_delay;
struct qca_data *qca = hu->priv;
BT_DBG("hu %p qca enq skb %p tx_ibs_state %d", hu, skb,
qca->tx_ibs_state);
memcpy(skb_push(skb, 1), &hci_skb_pkt_type(skb), 1);
if (!test_bit(STATE_IN_BAND_SLEEP_ENABLED, &qca->flags)) {
skb_queue_tail(&qca->txq, skb);
return 0;
}
spin_lock_irqsave(&qca->hci_ibs_lock, flags);
switch (qca->tx_ibs_state) {
case HCI_IBS_TX_AWAKE:
BT_DBG("Device awake, sending normally");
skb_queue_tail(&qca->txq, skb);
idle_delay = msecs_to_jiffies(qca->tx_idle_delay);
mod_timer(&qca->tx_idle_timer, jiffies + idle_delay);
break;
case HCI_IBS_TX_ASLEEP:
BT_DBG("Device asleep, waking up and queueing packet");
skb_queue_tail(&qca->tx_wait_q, skb);
qca->tx_ibs_state = HCI_IBS_TX_WAKING;
queue_work(qca->workqueue, &qca->ws_awake_device);
break;
case HCI_IBS_TX_WAKING:
BT_DBG("Device waking up, queueing packet");
skb_queue_tail(&qca->tx_wait_q, skb);
break;
default:
BT_ERR("Illegal tx state: %d (losing packet)",
qca->tx_ibs_state);
kfree_skb(skb);
break;
}
spin_unlock_irqrestore(&qca->hci_ibs_lock, flags);
return 0;
}
static int qca_ibs_sleep_ind(struct hci_dev *hdev, struct sk_buff *skb)
{
struct hci_uart *hu = hci_get_drvdata(hdev);
BT_DBG("hu %p recv hci ibs cmd 0x%x", hu, HCI_IBS_SLEEP_IND);
device_want_to_sleep(hu);
kfree_skb(skb);
return 0;
}
static int qca_ibs_wake_ind(struct hci_dev *hdev, struct sk_buff *skb)
{
struct hci_uart *hu = hci_get_drvdata(hdev);
BT_DBG("hu %p recv hci ibs cmd 0x%x", hu, HCI_IBS_WAKE_IND);
device_want_to_wakeup(hu);
kfree_skb(skb);
return 0;
}
static int qca_ibs_wake_ack(struct hci_dev *hdev, struct sk_buff *skb)
{
struct hci_uart *hu = hci_get_drvdata(hdev);
BT_DBG("hu %p recv hci ibs cmd 0x%x", hu, HCI_IBS_WAKE_ACK);
device_woke_up(hu);
kfree_skb(skb);
return 0;
}
static int qca_recv(struct hci_uart *hu, const void *data, int count)
{
struct qca_data *qca = hu->priv;
if (!test_bit(HCI_UART_REGISTERED, &hu->flags))
return -EUNATCH;
qca->rx_skb = h4_recv_buf(hu->hdev, qca->rx_skb, data, count,
qca_recv_pkts, ARRAY_SIZE(qca_recv_pkts));
if (IS_ERR(qca->rx_skb)) {
int err = PTR_ERR(qca->rx_skb);
BT_ERR("%s: Frame reassembly failed (%d)", hu->hdev->name, err);
qca->rx_skb = NULL;
return err;
}
return count;
}
static struct sk_buff *qca_dequeue(struct hci_uart *hu)
{
struct qca_data *qca = hu->priv;
return skb_dequeue(&qca->txq);
}
static uint8_t qca_get_baudrate_value(int speed)
{
switch (speed) {
case 9600:
return QCA_BAUDRATE_9600;
case 19200:
return QCA_BAUDRATE_19200;
case 38400:
return QCA_BAUDRATE_38400;
case 57600:
return QCA_BAUDRATE_57600;
case 115200:
return QCA_BAUDRATE_115200;
case 230400:
return QCA_BAUDRATE_230400;
case 460800:
return QCA_BAUDRATE_460800;
case 500000:
return QCA_BAUDRATE_500000;
case 921600:
return QCA_BAUDRATE_921600;
case 1000000:
return QCA_BAUDRATE_1000000;
case 2000000:
return QCA_BAUDRATE_2000000;
case 3000000:
return QCA_BAUDRATE_3000000;
case 3500000:
return QCA_BAUDRATE_3500000;
default:
return QCA_BAUDRATE_115200;
}
}
static int qca_set_baudrate(struct hci_dev *hdev, uint8_t baudrate)
{
struct hci_uart *hu = hci_get_drvdata(hdev);
struct qca_data *qca = hu->priv;
struct sk_buff *skb;
u8 cmd[] = { 0x01, 0x48, 0xFC, 0x01, 0x00 };
if (baudrate > QCA_BAUDRATE_3000000)
return -EINVAL;
cmd[4] = baudrate;
skb = bt_skb_alloc(sizeof(cmd), GFP_ATOMIC);
if (!skb) {
BT_ERR("Failed to allocate memory for baudrate packet");
return -ENOMEM;
}
memcpy(skb_put(skb, sizeof(cmd)), cmd, sizeof(cmd));
hci_skb_pkt_type(skb) = HCI_COMMAND_PKT;
skb_queue_tail(&qca->txq, skb);
hci_uart_tx_wakeup(hu);
set_current_state(TASK_UNINTERRUPTIBLE);
schedule_timeout(msecs_to_jiffies(BAUDRATE_SETTLE_TIMEOUT_MS));
set_current_state(TASK_INTERRUPTIBLE);
return 0;
}
static int qca_setup(struct hci_uart *hu)
{
struct hci_dev *hdev = hu->hdev;
struct qca_data *qca = hu->priv;
unsigned int speed, qca_baudrate = QCA_BAUDRATE_115200;
int ret;
BT_INFO("%s: ROME setup", hdev->name);
clear_bit(STATE_IN_BAND_SLEEP_ENABLED, &qca->flags);
speed = 0;
if (hu->init_speed)
speed = hu->init_speed;
else if (hu->proto->init_speed)
speed = hu->proto->init_speed;
if (speed)
hci_uart_set_baudrate(hu, speed);
speed = 0;
if (hu->oper_speed)
speed = hu->oper_speed;
else if (hu->proto->oper_speed)
speed = hu->proto->oper_speed;
if (speed) {
qca_baudrate = qca_get_baudrate_value(speed);
BT_INFO("%s: Set UART speed to %d", hdev->name, speed);
ret = qca_set_baudrate(hdev, qca_baudrate);
if (ret) {
BT_ERR("%s: Failed to change the baud rate (%d)",
hdev->name, ret);
return ret;
}
hci_uart_set_baudrate(hu, speed);
}
ret = qca_uart_setup_rome(hdev, qca_baudrate);
if (!ret) {
set_bit(STATE_IN_BAND_SLEEP_ENABLED, &qca->flags);
qca_debugfs_init(hdev);
}
hu->hdev->set_bdaddr = qca_set_bdaddr_rome;
return ret;
}
int __init qca_init(void)
{
return hci_uart_register_proto(&qca_proto);
}
int __exit qca_deinit(void)
{
return hci_uart_unregister_proto(&qca_proto);
}
