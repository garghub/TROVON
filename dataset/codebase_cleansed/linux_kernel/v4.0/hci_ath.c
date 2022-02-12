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
static int ath_flush(struct hci_uart *hu)
{
struct ath_struct *ath = hu->priv;
BT_DBG("hu %p", hu);
skb_queue_purge(&ath->txq);
return 0;
}
static int ath_close(struct hci_uart *hu)
{
struct ath_struct *ath = hu->priv;
BT_DBG("hu %p", hu);
skb_queue_purge(&ath->txq);
cancel_work_sync(&ath->ctxtsw);
hu->priv = NULL;
kfree(ath);
return 0;
}
static int ath_enqueue(struct hci_uart *hu, struct sk_buff *skb)
{
struct ath_struct *ath = hu->priv;
if (bt_cb(skb)->pkt_type == HCI_SCODATA_PKT) {
kfree_skb(skb);
return 0;
}
if (bt_cb(skb)->pkt_type == HCI_COMMAND_PKT) {
struct hci_command_hdr *hdr = (void *)skb->data;
if (__le16_to_cpu(hdr->opcode) == HCI_OP_ATH_SLEEP)
ath->cur_sleep = skb->data[HCI_COMMAND_HDR_SIZE];
}
BT_DBG("hu %p skb %p", hu, skb);
memcpy(skb_push(skb, 1), &bt_cb(skb)->pkt_type, 1);
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
static int ath_recv(struct hci_uart *hu, void *data, int count)
{
int ret;
ret = hci_recv_stream_fragment(hu->hdev, data, count);
if (ret < 0) {
BT_ERR("Frame Reassembly Failed");
return ret;
}
return count;
}
int __init ath_init(void)
{
int err = hci_uart_register_proto(&athp);
if (!err)
BT_INFO("HCIATH3K protocol initialized");
else
BT_ERR("HCIATH3K protocol registration failed");
return err;
}
int __exit ath_deinit(void)
{
return hci_uart_unregister_proto(&athp);
}
