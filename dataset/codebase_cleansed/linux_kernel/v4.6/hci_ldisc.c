int hci_uart_register_proto(const struct hci_uart_proto *p)
{
if (p->id >= HCI_UART_MAX_PROTO)
return -EINVAL;
if (hup[p->id])
return -EEXIST;
hup[p->id] = p;
BT_INFO("HCI UART protocol %s registered", p->name);
return 0;
}
int hci_uart_unregister_proto(const struct hci_uart_proto *p)
{
if (p->id >= HCI_UART_MAX_PROTO)
return -EINVAL;
if (!hup[p->id])
return -EINVAL;
hup[p->id] = NULL;
return 0;
}
static const struct hci_uart_proto *hci_uart_get_proto(unsigned int id)
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
if (test_and_set_bit(HCI_UART_SENDING, &hu->tx_state)) {
set_bit(HCI_UART_TX_WAKEUP, &hu->tx_state);
return 0;
}
BT_DBG("");
schedule_work(&hu->write_work);
return 0;
}
static void hci_uart_write_work(struct work_struct *work)
{
struct hci_uart *hu = container_of(work, struct hci_uart, write_work);
struct tty_struct *tty = hu->tty;
struct hci_dev *hdev = hu->hdev;
struct sk_buff *skb;
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
hci_uart_tx_complete(hu, hci_skb_pkt_type(skb));
kfree_skb(skb);
}
if (test_bit(HCI_UART_TX_WAKEUP, &hu->tx_state))
goto restart;
clear_bit(HCI_UART_SENDING, &hu->tx_state);
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
hci_uart_flush(hdev);
hdev->flush = NULL;
return 0;
}
static int hci_uart_send_frame(struct hci_dev *hdev, struct sk_buff *skb)
{
struct hci_uart *hu = hci_get_drvdata(hdev);
BT_DBG("%s: type %d len %d", hdev->name, hci_skb_pkt_type(skb),
skb->len);
hu->proto->enqueue(hu, skb);
hci_uart_tx_wakeup(hu);
return 0;
}
void hci_uart_set_flow_control(struct hci_uart *hu, bool enable)
{
struct tty_struct *tty = hu->tty;
struct ktermios ktermios;
int status;
unsigned int set = 0;
unsigned int clear = 0;
if (enable) {
ktermios = tty->termios;
ktermios.c_cflag &= ~CRTSCTS;
status = tty_set_termios(tty, &ktermios);
BT_DBG("Disabling hardware flow control: %s",
status ? "failed" : "success");
status = tty->driver->ops->tiocmget(tty);
BT_DBG("Current tiocm 0x%x", status);
set &= ~(TIOCM_OUT2 | TIOCM_RTS);
clear = ~set;
set &= TIOCM_DTR | TIOCM_RTS | TIOCM_OUT1 |
TIOCM_OUT2 | TIOCM_LOOP;
clear &= TIOCM_DTR | TIOCM_RTS | TIOCM_OUT1 |
TIOCM_OUT2 | TIOCM_LOOP;
status = tty->driver->ops->tiocmset(tty, set, clear);
BT_DBG("Clearing RTS: %s", status ? "failed" : "success");
} else {
status = tty->driver->ops->tiocmget(tty);
BT_DBG("Current tiocm 0x%x", status);
set |= (TIOCM_OUT2 | TIOCM_RTS);
clear = ~set;
set &= TIOCM_DTR | TIOCM_RTS | TIOCM_OUT1 |
TIOCM_OUT2 | TIOCM_LOOP;
clear &= TIOCM_DTR | TIOCM_RTS | TIOCM_OUT1 |
TIOCM_OUT2 | TIOCM_LOOP;
status = tty->driver->ops->tiocmset(tty, set, clear);
BT_DBG("Setting RTS: %s", status ? "failed" : "success");
ktermios = tty->termios;
ktermios.c_cflag |= CRTSCTS;
status = tty_set_termios(tty, &ktermios);
BT_DBG("Enabling hardware flow control: %s",
status ? "failed" : "success");
}
}
void hci_uart_set_speeds(struct hci_uart *hu, unsigned int init_speed,
unsigned int oper_speed)
{
hu->init_speed = init_speed;
hu->oper_speed = oper_speed;
}
void hci_uart_init_tty(struct hci_uart *hu)
{
struct tty_struct *tty = hu->tty;
struct ktermios ktermios;
ktermios = tty->termios;
ktermios.c_iflag &= ~(IGNBRK | BRKINT | PARMRK | ISTRIP |
INLCR | IGNCR | ICRNL | IXON);
ktermios.c_oflag &= ~OPOST;
ktermios.c_lflag &= ~(ECHO | ECHONL | ICANON | ISIG | IEXTEN);
ktermios.c_cflag &= ~(CSIZE | PARENB);
ktermios.c_cflag |= CS8;
ktermios.c_cflag |= CRTSCTS;
tty_set_termios(tty, &ktermios);
}
void hci_uart_set_baudrate(struct hci_uart *hu, unsigned int speed)
{
struct tty_struct *tty = hu->tty;
struct ktermios ktermios;
ktermios = tty->termios;
ktermios.c_cflag &= ~CBAUD;
tty_termios_encode_baud_rate(&ktermios, speed, speed);
tty_set_termios(tty, &ktermios);
BT_DBG("%s: New tty speeds: %d/%d", hu->hdev->name,
tty->termios.c_ispeed, tty->termios.c_ospeed);
}
static int hci_uart_setup(struct hci_dev *hdev)
{
struct hci_uart *hu = hci_get_drvdata(hdev);
struct hci_rp_read_local_version *ver;
struct sk_buff *skb;
unsigned int speed;
int err;
if (hu->init_speed)
speed = hu->init_speed;
else if (hu->proto->init_speed)
speed = hu->proto->init_speed;
else
speed = 0;
if (speed)
hci_uart_set_baudrate(hu, speed);
if (hu->oper_speed)
speed = hu->oper_speed;
else if (hu->proto->oper_speed)
speed = hu->proto->oper_speed;
else
speed = 0;
if (hu->proto->set_baudrate && speed) {
err = hu->proto->set_baudrate(hu, speed);
if (!err)
hci_uart_set_baudrate(hu, speed);
}
if (hu->proto->setup)
return hu->proto->setup(hu);
if (!test_bit(HCI_UART_VND_DETECT, &hu->hdev_flags))
return 0;
skb = __hci_cmd_sync(hdev, HCI_OP_READ_LOCAL_VERSION, 0, NULL,
HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
BT_ERR("%s: Reading local version information failed (%ld)",
hdev->name, PTR_ERR(skb));
return 0;
}
if (skb->len != sizeof(*ver)) {
BT_ERR("%s: Event length mismatch for version information",
hdev->name);
goto done;
}
ver = (struct hci_rp_read_local_version *)skb->data;
switch (le16_to_cpu(ver->manufacturer)) {
#ifdef CONFIG_BT_HCIUART_INTEL
case 2:
hdev->set_bdaddr = btintel_set_bdaddr;
btintel_check_bdaddr(hdev);
break;
#endif
#ifdef CONFIG_BT_HCIUART_BCM
case 15:
hdev->set_bdaddr = btbcm_set_bdaddr;
btbcm_check_bdaddr(hdev);
break;
#endif
}
done:
kfree_skb(skb);
return 0;
}
static int hci_uart_tty_open(struct tty_struct *tty)
{
struct hci_uart *hu;
BT_DBG("tty %p", tty);
if (tty->ops->write == NULL)
return -EOPNOTSUPP;
hu = kzalloc(sizeof(struct hci_uart), GFP_KERNEL);
if (!hu) {
BT_ERR("Can't allocate control structure");
return -ENFILE;
}
tty->disc_data = hu;
hu->tty = tty;
tty->receive_room = 65536;
INIT_WORK(&hu->init_ready, hci_uart_init_work);
INIT_WORK(&hu->write_work, hci_uart_write_work);
tty_driver_flush_buffer(tty);
return 0;
}
static void hci_uart_tty_close(struct tty_struct *tty)
{
struct hci_uart *hu = tty->disc_data;
struct hci_dev *hdev;
BT_DBG("tty %p", tty);
tty->disc_data = NULL;
if (!hu)
return;
hdev = hu->hdev;
if (hdev)
hci_uart_close(hdev);
cancel_work_sync(&hu->write_work);
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
struct hci_uart *hu = tty->disc_data;
BT_DBG("");
if (!hu)
return;
clear_bit(TTY_DO_WRITE_WAKEUP, &tty->flags);
if (tty != hu->tty)
return;
if (test_bit(HCI_UART_PROTO_SET, &hu->flags))
hci_uart_tx_wakeup(hu);
}
static void hci_uart_tty_receive(struct tty_struct *tty, const u8 *data,
char *flags, int count)
{
struct hci_uart *hu = tty->disc_data;
if (!hu || tty != hu->tty)
return;
if (!test_bit(HCI_UART_PROTO_SET, &hu->flags))
return;
hu->proto->recv(hu, data, count);
if (hu->hdev)
hu->hdev->stat.byte_rx += count;
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
if (hu->proto->setup)
hdev->manufacturer = hu->proto->manufacturer;
hdev->open = hci_uart_open;
hdev->close = hci_uart_close;
hdev->flush = hci_uart_flush;
hdev->send = hci_uart_send_frame;
hdev->setup = hci_uart_setup;
SET_HCIDEV_DEV(hdev, hu->tty->dev);
if (test_bit(HCI_UART_RAW_DEVICE, &hu->hdev_flags))
set_bit(HCI_QUIRK_RAW_DEVICE, &hdev->quirks);
if (test_bit(HCI_UART_EXT_CONFIG, &hu->hdev_flags))
set_bit(HCI_QUIRK_EXTERNAL_CONFIG, &hdev->quirks);
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
const struct hci_uart_proto *p;
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
static int hci_uart_set_flags(struct hci_uart *hu, unsigned long flags)
{
unsigned long valid_flags = BIT(HCI_UART_RAW_DEVICE) |
BIT(HCI_UART_RESET_ON_INIT) |
BIT(HCI_UART_CREATE_AMP) |
BIT(HCI_UART_INIT_PENDING) |
BIT(HCI_UART_EXT_CONFIG) |
BIT(HCI_UART_VND_DETECT);
if (flags & ~valid_flags)
return -EINVAL;
hu->hdev_flags = flags;
return 0;
}
static int hci_uart_tty_ioctl(struct tty_struct *tty, struct file *file,
unsigned int cmd, unsigned long arg)
{
struct hci_uart *hu = tty->disc_data;
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
if (test_bit(HCI_UART_REGISTERED, &hu->flags))
return hu->hdev->id;
return -EUNATCH;
case HCIUARTSETFLAGS:
if (test_bit(HCI_UART_PROTO_SET, &hu->flags))
return -EBUSY;
err = hci_uart_set_flags(hu, arg);
if (err)
return err;
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
memset(&hci_uart_ldisc, 0, sizeof(hci_uart_ldisc));
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
err = tty_register_ldisc(N_HCI, &hci_uart_ldisc);
if (err) {
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
#ifdef CONFIG_BT_HCIUART_INTEL
intel_init();
#endif
#ifdef CONFIG_BT_HCIUART_BCM
bcm_init();
#endif
#ifdef CONFIG_BT_HCIUART_QCA
qca_init();
#endif
#ifdef CONFIG_BT_HCIUART_AG6XX
ag6xx_init();
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
#ifdef CONFIG_BT_HCIUART_INTEL
intel_deinit();
#endif
#ifdef CONFIG_BT_HCIUART_BCM
bcm_deinit();
#endif
#ifdef CONFIG_BT_HCIUART_QCA
qca_deinit();
#endif
#ifdef CONFIG_BT_HCIUART_AG6XX
ag6xx_deinit();
#endif
err = tty_unregister_ldisc(N_HCI);
if (err)
BT_ERR("Can't unregister HCI line discipline (%d)", err);
}
