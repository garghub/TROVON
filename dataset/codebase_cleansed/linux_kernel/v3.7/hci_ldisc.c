int hci_uart_register_proto(struct hci_uart_proto *p)
{
if (p->id >= HCI_UART_MAX_PROTO)
return -EINVAL;
if (hup[p->id])
return -EEXIST;
hup[p->id] = p;
return 0;
}
int hci_uart_unregister_proto(struct hci_uart_proto *p)
{
if (p->id >= HCI_UART_MAX_PROTO)
return -EINVAL;
if (!hup[p->id])
return -EINVAL;
hup[p->id] = NULL;
return 0;
}
static struct hci_uart_proto *hci_uart_get_proto(unsigned int id)
{
if (id >= HCI_UART_MAX_PROTO)
return NULL;
return hup[id];
}
static inline void hci_uart_tx_complete(struct hci_uart *hu, int pkt_type)
{
struct hci_dev *hdev = hu->hdev;
switch (pkt_type) {
case HCI_COMMAND_PKT:
hdev->stat.cmd_tx++;
break;
case HCI_ACLDATA_PKT:
hdev->stat.acl_tx++;
break;
case HCI_SCODATA_PKT:
hdev->stat.sco_tx++;
break;
}
}
static inline struct sk_buff *hci_uart_dequeue(struct hci_uart *hu)
{
struct sk_buff *skb = hu->tx_skb;
if (!skb)
skb = hu->proto->dequeue(hu);
else
hu->tx_skb = NULL;
return skb;
}
int hci_uart_tx_wakeup(struct hci_uart *hu)
{
struct tty_struct *tty = hu->tty;
struct hci_dev *hdev = hu->hdev;
struct sk_buff *skb;
if (test_and_set_bit(HCI_UART_SENDING, &hu->tx_state)) {
set_bit(HCI_UART_TX_WAKEUP, &hu->tx_state);
return 0;
}
BT_DBG("");
restart:
clear_bit(HCI_UART_TX_WAKEUP, &hu->tx_state);
while ((skb = hci_uart_dequeue(hu))) {
int len;
set_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
len = tty->ops->write(tty, skb->data, skb->len);
hdev->stat.byte_tx += len;
skb_pull(skb, len);
if (skb->len) {
hu->tx_skb = skb;
break;
}
hci_uart_tx_complete(hu, bt_cb(skb)->pkt_type);
kfree_skb(skb);
}
if (test_bit(HCI_UART_TX_WAKEUP, &hu->tx_state))
goto restart;
clear_bit(HCI_UART_SENDING, &hu->tx_state);
return 0;
}
static void hci_uart_init_work(struct work_struct *work)
{
struct hci_uart *hu = container_of(work, struct hci_uart, init_ready);
int err;
if (!test_and_clear_bit(HCI_UART_INIT_PENDING, &hu->hdev_flags))
return;
err = hci_register_dev(hu->hdev);
if (err < 0) {
BT_ERR("Can't register HCI device");
hci_free_dev(hu->hdev);
hu->hdev = NULL;
hu->proto->close(hu);
}
set_bit(HCI_UART_REGISTERED, &hu->flags);
}
int hci_uart_init_ready(struct hci_uart *hu)
{
if (!test_bit(HCI_UART_INIT_PENDING, &hu->hdev_flags))
return -EALREADY;
schedule_work(&hu->init_ready);
return 0;
}
static int hci_uart_open(struct hci_dev *hdev)
{
BT_DBG("%s %p", hdev->name, hdev);
set_bit(HCI_RUNNING, &hdev->flags);
return 0;
}
static int hci_uart_flush(struct hci_dev *hdev)
{
struct hci_uart *hu = hci_get_drvdata(hdev);
struct tty_struct *tty = hu->tty;
BT_DBG("hdev %p tty %p", hdev, tty);
if (hu->tx_skb) {
kfree_skb(hu->tx_skb); hu->tx_skb = NULL;
}
tty_ldisc_flush(tty);
tty_driver_flush_buffer(tty);
if (test_bit(HCI_UART_PROTO_SET, &hu->flags))
hu->proto->flush(hu);
return 0;
}
static int hci_uart_close(struct hci_dev *hdev)
{
BT_DBG("hdev %p", hdev);
if (!test_and_clear_bit(HCI_RUNNING, &hdev->flags))
return 0;
hci_uart_flush(hdev);
hdev->flush = NULL;
return 0;
}
static int hci_uart_send_frame(struct sk_buff *skb)
{
struct hci_dev* hdev = (struct hci_dev *) skb->dev;
struct hci_uart *hu;
if (!hdev) {
BT_ERR("Frame for unknown device (hdev=NULL)");
return -ENODEV;
}
if (!test_bit(HCI_RUNNING, &hdev->flags))
return -EBUSY;
hu = hci_get_drvdata(hdev);
BT_DBG("%s: type %d len %d", hdev->name, bt_cb(skb)->pkt_type, skb->len);
hu->proto->enqueue(hu, skb);
hci_uart_tx_wakeup(hu);
return 0;
}
static int hci_uart_tty_open(struct tty_struct *tty)
{
struct hci_uart *hu = (void *) tty->disc_data;
BT_DBG("tty %p", tty);
if (hu)
return -EEXIST;
if (tty->ops->write == NULL)
return -EOPNOTSUPP;
if (!(hu = kzalloc(sizeof(struct hci_uart), GFP_KERNEL))) {
BT_ERR("Can't allocate control structure");
return -ENFILE;
}
tty->disc_data = hu;
hu->tty = tty;
tty->receive_room = 65536;
INIT_WORK(&hu->init_ready, hci_uart_init_work);
spin_lock_init(&hu->rx_lock);
if (tty->ldisc->ops->flush_buffer)
tty->ldisc->ops->flush_buffer(tty);
tty_driver_flush_buffer(tty);
return 0;
}
static void hci_uart_tty_close(struct tty_struct *tty)
{
struct hci_uart *hu = (void *)tty->disc_data;
struct hci_dev *hdev;
BT_DBG("tty %p", tty);
tty->disc_data = NULL;
if (!hu)
return;
hdev = hu->hdev;
if (hdev)
hci_uart_close(hdev);
if (test_and_clear_bit(HCI_UART_PROTO_SET, &hu->flags)) {
if (hdev) {
if (test_bit(HCI_UART_REGISTERED, &hu->flags))
hci_unregister_dev(hdev);
hci_free_dev(hdev);
}
hu->proto->close(hu);
}
kfree(hu);
}
static void hci_uart_tty_wakeup(struct tty_struct *tty)
{
struct hci_uart *hu = (void *)tty->disc_data;
BT_DBG("");
if (!hu)
return;
clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
if (tty != hu->tty)
return;
if (test_bit(HCI_UART_PROTO_SET, &hu->flags))
hci_uart_tx_wakeup(hu);
}
static void hci_uart_tty_receive(struct tty_struct *tty, const u8 *data, char *flags, int count)
{
struct hci_uart *hu = (void *)tty->disc_data;
if (!hu || tty != hu->tty)
return;
if (!test_bit(HCI_UART_PROTO_SET, &hu->flags))
return;
spin_lock(&hu->rx_lock);
hu->proto->recv(hu, (void *) data, count);
hu->hdev->stat.byte_rx += count;
spin_unlock(&hu->rx_lock);
tty_unthrottle(tty);
}
static int hci_uart_register_dev(struct hci_uart *hu)
{
struct hci_dev *hdev;
BT_DBG("");
hdev = hci_alloc_dev();
if (!hdev) {
BT_ERR("Can't allocate HCI device");
return -ENOMEM;
}
hu->hdev = hdev;
hdev->bus = HCI_UART;
hci_set_drvdata(hdev, hu);
hdev->open = hci_uart_open;
hdev->close = hci_uart_close;
hdev->flush = hci_uart_flush;
hdev->send = hci_uart_send_frame;
SET_HCIDEV_DEV(hdev, hu->tty->dev);
if (test_bit(HCI_UART_RAW_DEVICE, &hu->hdev_flags))
set_bit(HCI_QUIRK_RAW_DEVICE, &hdev->quirks);
if (!test_bit(HCI_UART_RESET_ON_INIT, &hu->hdev_flags))
set_bit(HCI_QUIRK_RESET_ON_CLOSE, &hdev->quirks);
if (test_bit(HCI_UART_CREATE_AMP, &hu->hdev_flags))
hdev->dev_type = HCI_AMP;
else
hdev->dev_type = HCI_BREDR;
if (test_bit(HCI_UART_INIT_PENDING, &hu->hdev_flags))
return 0;
if (hci_register_dev(hdev) < 0) {
BT_ERR("Can't register HCI device");
hci_free_dev(hdev);
return -ENODEV;
}
set_bit(HCI_UART_REGISTERED, &hu->flags);
return 0;
}
static int hci_uart_set_proto(struct hci_uart *hu, int id)
{
struct hci_uart_proto *p;
int err;
p = hci_uart_get_proto(id);
if (!p)
return -EPROTONOSUPPORT;
err = p->open(hu);
if (err)
return err;
hu->proto = p;
err = hci_uart_register_dev(hu);
if (err) {
p->close(hu);
return err;
}
return 0;
}
static int hci_uart_tty_ioctl(struct tty_struct *tty, struct file * file,
unsigned int cmd, unsigned long arg)
{
struct hci_uart *hu = (void *)tty->disc_data;
int err = 0;
BT_DBG("");
if (!hu)
return -EBADF;
switch (cmd) {
case HCIUARTSETPROTO:
if (!test_and_set_bit(HCI_UART_PROTO_SET, &hu->flags)) {
err = hci_uart_set_proto(hu, arg);
if (err) {
clear_bit(HCI_UART_PROTO_SET, &hu->flags);
return err;
}
} else
return -EBUSY;
break;
case HCIUARTGETPROTO:
if (test_bit(HCI_UART_PROTO_SET, &hu->flags))
return hu->proto->id;
return -EUNATCH;
case HCIUARTGETDEVICE:
if (test_bit(HCI_UART_PROTO_SET, &hu->flags))
return hu->hdev->id;
return -EUNATCH;
case HCIUARTSETFLAGS:
if (test_bit(HCI_UART_PROTO_SET, &hu->flags))
return -EBUSY;
hu->hdev_flags = arg;
break;
case HCIUARTGETFLAGS:
return hu->hdev_flags;
default:
err = n_tty_ioctl_helper(tty, file, cmd, arg);
break;
}
return err;
}
static ssize_t hci_uart_tty_read(struct tty_struct *tty, struct file *file,
unsigned char __user *buf, size_t nr)
{
return 0;
}
static ssize_t hci_uart_tty_write(struct tty_struct *tty, struct file *file,
const unsigned char *data, size_t count)
{
return 0;
}
static unsigned int hci_uart_tty_poll(struct tty_struct *tty,
struct file *filp, poll_table *wait)
{
return 0;
}
static int __init hci_uart_init(void)
{
static struct tty_ldisc_ops hci_uart_ldisc;
int err;
BT_INFO("HCI UART driver ver %s", VERSION);
memset(&hci_uart_ldisc, 0, sizeof (hci_uart_ldisc));
hci_uart_ldisc.magic = TTY_LDISC_MAGIC;
hci_uart_ldisc.name = "n_hci";
hci_uart_ldisc.open = hci_uart_tty_open;
hci_uart_ldisc.close = hci_uart_tty_close;
hci_uart_ldisc.read = hci_uart_tty_read;
hci_uart_ldisc.write = hci_uart_tty_write;
hci_uart_ldisc.ioctl = hci_uart_tty_ioctl;
hci_uart_ldisc.poll = hci_uart_tty_poll;
hci_uart_ldisc.receive_buf = hci_uart_tty_receive;
hci_uart_ldisc.write_wakeup = hci_uart_tty_wakeup;
hci_uart_ldisc.owner = THIS_MODULE;
if ((err = tty_register_ldisc(N_HCI, &hci_uart_ldisc))) {
BT_ERR("HCI line discipline registration failed. (%d)", err);
return err;
}
#ifdef CONFIG_BT_HCIUART_H4
h4_init();
#endif
#ifdef CONFIG_BT_HCIUART_BCSP
bcsp_init();
#endif
#ifdef CONFIG_BT_HCIUART_LL
ll_init();
#endif
#ifdef CONFIG_BT_HCIUART_ATH3K
ath_init();
#endif
#ifdef CONFIG_BT_HCIUART_3WIRE
h5_init();
#endif
return 0;
}
static void __exit hci_uart_exit(void)
{
int err;
#ifdef CONFIG_BT_HCIUART_H4
h4_deinit();
#endif
#ifdef CONFIG_BT_HCIUART_BCSP
bcsp_deinit();
#endif
#ifdef CONFIG_BT_HCIUART_LL
ll_deinit();
#endif
#ifdef CONFIG_BT_HCIUART_ATH3K
ath_deinit();
#endif
#ifdef CONFIG_BT_HCIUART_3WIRE
h5_deinit();
#endif
if ((err = tty_unregister_ldisc(N_HCI)))
BT_ERR("Can't unregister HCI line discipline (%d)", err);
}
