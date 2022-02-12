static int ath_wakeup_ar3k(struct tty_struct *tty)
{
int status = tty->driver->ops->tiocmget(tty);
if (status & TIOCM_CTS)
return status;
tty->driver->ops->tiocmget(tty);
tty->driver->ops->tiocmset(tty, 0x00, TIOCM_RTS);
mdelay(20);
tty->driver->ops->tiocmget(tty);
tty->driver->ops->tiocmset(tty, TIOCM_RTS, 0x00);
mdelay(20);
status = tty->driver->ops->tiocmget(tty);
return status;
}
static void ath_hci_uart_work(struct work_struct *work)
{
int status;
struct ath_struct *ath;
struct hci_uart *hu;
struct tty_struct *tty;
ath = container_of(work, struct ath_struct, ctxtsw);
hu = ath->hu;
tty = hu->tty;
if (ath->cur_sleep) {
status = ath_wakeup_ar3k(tty);
if (!(status & TIOCM_CTS))
return;
}
clear_bit(HCI_UART_SENDING, &hu->tx_state);
hci_uart_tx_wakeup(hu);
}
static int ath_open(struct hci_uart *hu)
{
struct ath_struct *ath;
BT_DBG("hu %p", hu);
ath = kzalloc(sizeof(*ath), GFP_KERNEL);
if (!ath)
return -ENOMEM;
skb_queue_head_init(&ath->txq);
hu->priv = ath;
ath->hu = hu;
INIT_WORK(&ath->ctxtsw, ath_hci_uart_work);
return 0;
}
static int ath_close(struct hci_uart *hu)
{
struct ath_struct *ath = hu->priv;
BT_DBG("hu %p", hu);
skb_queue_purge(&ath->txq);
kfree_skb(ath->rx_skb);
cancel_work_sync(&ath->ctxtsw);
hu->priv = NULL;
kfree(ath);
return 0;
}
static int ath_flush(struct hci_uart *hu)
{
struct ath_struct *ath = hu->priv;
BT_DBG("hu %p", hu);
skb_queue_purge(&ath->txq);
return 0;
}
static int ath_set_bdaddr(struct hci_dev *hdev, const bdaddr_t *bdaddr)
{
struct sk_buff *skb;
u8 buf[10];
int err;
buf[0] = 0x01;
buf[1] = 0x01;
buf[2] = 0x00;
buf[3] = sizeof(bdaddr_t);
memcpy(buf + 4, bdaddr, sizeof(bdaddr_t));
skb = __hci_cmd_sync(hdev, 0xfc0b, sizeof(buf), buf, HCI_INIT_TIMEOUT);
if (IS_ERR(skb)) {
err = PTR_ERR(skb);
BT_ERR("%s: Change address command failed (%d)",
hdev->name, err);
return err;
}
kfree_skb(skb);
return 0;
}
static int ath_setup(struct hci_uart *hu)
{
BT_DBG("hu %p", hu);
hu->hdev->set_bdaddr = ath_set_bdaddr;
return 0;
}
static int ath_recv(struct hci_uart *hu, const void *data, int count)
{
struct ath_struct *ath = hu->priv;
ath->rx_skb = h4_recv_buf(hu->hdev, ath->rx_skb, data, count,
ath_recv_pkts, ARRAY_SIZE(ath_recv_pkts));
if (IS_ERR(ath->rx_skb)) {
int err = PTR_ERR(ath->rx_skb);
BT_ERR("%s: Frame reassembly failed (%d)", hu->hdev->name, err);
ath->rx_skb = NULL;
return err;
}
return count;
}
static int ath_enqueue(struct hci_uart *hu, struct sk_buff *skb)
{
struct ath_struct *ath = hu->priv;
if (hci_skb_pkt_type(skb) == HCI_SCODATA_PKT) {
kfree_skb(skb);
return 0;
}
if (hci_skb_pkt_type(skb) == HCI_COMMAND_PKT) {
struct hci_command_hdr *hdr = (void *)skb->data;
if (__le16_to_cpu(hdr->opcode) == HCI_OP_ATH_SLEEP)
ath->cur_sleep = skb->data[HCI_COMMAND_HDR_SIZE];
}
BT_DBG("hu %p skb %p", hu, skb);
memcpy(skb_push(skb, 1), &hci_skb_pkt_type(skb), 1);
skb_queue_tail(&ath->txq, skb);
set_bit(HCI_UART_SENDING, &hu->tx_state);
schedule_work(&ath->ctxtsw);
return 0;
}
static struct sk_buff *ath_dequeue(struct hci_uart *hu)
{
struct ath_struct *ath = hu->priv;
return skb_dequeue(&ath->txq);
}
int __init ath_init(void)
{
return hci_uart_register_proto(&athp);
}
int __exit ath_deinit(void)
{
return hci_uart_unregister_proto(&athp);
}
