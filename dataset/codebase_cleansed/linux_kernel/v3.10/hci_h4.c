static int h4_open(struct hci_uart *hu)
{
struct h4_struct *h4;
BT_DBG("hu %p", hu);
h4 = kzalloc(sizeof(*h4), GFP_KERNEL);
if (!h4)
return -ENOMEM;
skb_queue_head_init(&h4->txq);
hu->priv = h4;
return 0;
}
static int h4_flush(struct hci_uart *hu)
{
struct h4_struct *h4 = hu->priv;
BT_DBG("hu %p", hu);
skb_queue_purge(&h4->txq);
return 0;
}
static int h4_close(struct hci_uart *hu)
{
struct h4_struct *h4 = hu->priv;
hu->priv = NULL;
BT_DBG("hu %p", hu);
skb_queue_purge(&h4->txq);
kfree_skb(h4->rx_skb);
hu->priv = NULL;
kfree(h4);
return 0;
}
static int h4_enqueue(struct hci_uart *hu, struct sk_buff *skb)
{
struct h4_struct *h4 = hu->priv;
BT_DBG("hu %p skb %p", hu, skb);
memcpy(skb_push(skb, 1), &bt_cb(skb)->pkt_type, 1);
skb_queue_tail(&h4->txq, skb);
return 0;
}
static inline int h4_check_data_len(struct h4_struct *h4, int len)
{
int room = skb_tailroom(h4->rx_skb);
BT_DBG("len %d room %d", len, room);
if (!len) {
hci_recv_frame(h4->rx_skb);
} else if (len > room) {
BT_ERR("Data length is too large");
kfree_skb(h4->rx_skb);
} else {
h4->rx_state = H4_W4_DATA;
h4->rx_count = len;
return len;
}
h4->rx_state = H4_W4_PACKET_TYPE;
h4->rx_skb = NULL;
h4->rx_count = 0;
return 0;
}
static int h4_recv(struct hci_uart *hu, void *data, int count)
{
int ret;
if (!test_bit(HCI_UART_REGISTERED, &hu->flags))
return -EUNATCH;
ret = hci_recv_stream_fragment(hu->hdev, data, count);
if (ret < 0) {
BT_ERR("Frame Reassembly Failed");
return ret;
}
return count;
}
static struct sk_buff *h4_dequeue(struct hci_uart *hu)
{
struct h4_struct *h4 = hu->priv;
return skb_dequeue(&h4->txq);
}
int __init h4_init(void)
{
int err = hci_uart_register_proto(&h4p);
if (!err)
BT_INFO("HCI H4 protocol initialized");
else
BT_ERR("HCI H4 protocol registration failed");
return err;
}
int __exit h4_deinit(void)
{
return hci_uart_unregister_proto(&h4p);
}
