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
static int h4_recv(struct hci_uart *hu, const void *data, int count)
{
struct h4_struct *h4 = hu->priv;
if (!test_bit(HCI_UART_REGISTERED, &hu->flags))
return -EUNATCH;
h4->rx_skb = h4_recv_buf(hu->hdev, h4->rx_skb, data, count,
h4_recv_pkts, ARRAY_SIZE(h4_recv_pkts));
if (IS_ERR(h4->rx_skb)) {
int err = PTR_ERR(h4->rx_skb);
BT_ERR("%s: Frame reassembly failed (%d)", hu->hdev->name, err);
h4->rx_skb = NULL;
return err;
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
return hci_uart_register_proto(&h4p);
}
int __exit h4_deinit(void)
{
return hci_uart_unregister_proto(&h4p);
}
struct sk_buff *h4_recv_buf(struct hci_dev *hdev, struct sk_buff *skb,
const unsigned char *buffer, int count,
const struct h4_recv_pkt *pkts, int pkts_count)
{
while (count) {
int i, len;
if (!skb) {
for (i = 0; i < pkts_count; i++) {
if (buffer[0] != (&pkts[i])->type)
continue;
skb = bt_skb_alloc((&pkts[i])->maxlen,
GFP_ATOMIC);
if (!skb)
return ERR_PTR(-ENOMEM);
bt_cb(skb)->pkt_type = (&pkts[i])->type;
bt_cb(skb)->expect = (&pkts[i])->hlen;
break;
}
if (!skb)
return ERR_PTR(-EILSEQ);
count -= 1;
buffer += 1;
}
len = min_t(uint, bt_cb(skb)->expect - skb->len, count);
memcpy(skb_put(skb, len), buffer, len);
count -= len;
buffer += len;
if (skb->len < bt_cb(skb)->expect)
continue;
for (i = 0; i < pkts_count; i++) {
if (bt_cb(skb)->pkt_type == (&pkts[i])->type)
break;
}
if (i >= pkts_count) {
kfree_skb(skb);
return ERR_PTR(-EILSEQ);
}
if (skb->len == (&pkts[i])->hlen) {
u16 dlen;
switch ((&pkts[i])->lsize) {
case 0:
dlen = 0;
break;
case 1:
dlen = skb->data[(&pkts[i])->loff];
bt_cb(skb)->expect += dlen;
if (skb_tailroom(skb) < dlen) {
kfree_skb(skb);
return ERR_PTR(-EMSGSIZE);
}
break;
case 2:
dlen = get_unaligned_le16(skb->data +
(&pkts[i])->loff);
bt_cb(skb)->expect += dlen;
if (skb_tailroom(skb) < dlen) {
kfree_skb(skb);
return ERR_PTR(-EMSGSIZE);
}
break;
default:
kfree_skb(skb);
return ERR_PTR(-EILSEQ);
}
if (!dlen) {
(&pkts[i])->recv(hdev, skb);
skb = NULL;
}
} else {
(&pkts[i])->recv(hdev, skb);
skb = NULL;
}
}
return skb;
}
