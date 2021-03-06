static void bluecard_activity_led_timeout(u_long arg)
{
bluecard_info_t *info = (bluecard_info_t *)arg;
unsigned int iobase = info->p_dev->resource[0]->start;
if (!test_bit(CARD_HAS_PCCARD_ID, &(info->hw_state)))
return;
if (test_bit(CARD_HAS_ACTIVITY_LED, &(info->hw_state))) {
outb(0x08 | 0x20, iobase + 0x30);
} else {
outb(0x00, iobase + 0x30);
}
}
static void bluecard_enable_activity_led(bluecard_info_t *info)
{
unsigned int iobase = info->p_dev->resource[0]->start;
if (!test_bit(CARD_HAS_PCCARD_ID, &(info->hw_state)))
return;
if (test_bit(CARD_HAS_ACTIVITY_LED, &(info->hw_state))) {
outb(0x10 | 0x40, iobase + 0x30);
mod_timer(&(info->timer), jiffies + HZ / 4);
} else {
outb(0x08 | 0x20, iobase + 0x30);
mod_timer(&(info->timer), jiffies + HZ / 2);
}
}
static int bluecard_write(unsigned int iobase, unsigned int offset, __u8 *buf, int len)
{
int i, actual;
actual = (len > 15) ? 15 : len;
outb_p(actual, iobase + offset);
for (i = 0; i < actual; i++)
outb_p(buf[i], iobase + offset + i + 1);
return actual;
}
static void bluecard_write_wakeup(bluecard_info_t *info)
{
if (!info) {
BT_ERR("Unknown device");
return;
}
if (!test_bit(XMIT_SENDING_READY, &(info->tx_state)))
return;
if (test_and_set_bit(XMIT_SENDING, &(info->tx_state))) {
set_bit(XMIT_WAKEUP, &(info->tx_state));
return;
}
do {
unsigned int iobase = info->p_dev->resource[0]->start;
unsigned int offset;
unsigned char command;
unsigned long ready_bit;
register struct sk_buff *skb;
int len;
clear_bit(XMIT_WAKEUP, &(info->tx_state));
if (!pcmcia_dev_present(info->p_dev))
return;
if (test_bit(XMIT_BUFFER_NUMBER, &(info->tx_state))) {
if (!test_bit(XMIT_BUF_TWO_READY, &(info->tx_state)))
break;
offset = 0x10;
command = REG_COMMAND_TX_BUF_TWO;
ready_bit = XMIT_BUF_TWO_READY;
} else {
if (!test_bit(XMIT_BUF_ONE_READY, &(info->tx_state)))
break;
offset = 0x00;
command = REG_COMMAND_TX_BUF_ONE;
ready_bit = XMIT_BUF_ONE_READY;
}
if (!(skb = skb_dequeue(&(info->txq))))
break;
if (bt_cb(skb)->pkt_type & 0x80) {
info->ctrl_reg |= REG_CONTROL_RTS;
outb(info->ctrl_reg, iobase + REG_CONTROL);
}
bluecard_enable_activity_led(info);
len = bluecard_write(iobase, offset, skb->data, skb->len);
outb_p(command, iobase + REG_COMMAND);
clear_bit(ready_bit, &(info->tx_state));
if (bt_cb(skb)->pkt_type & 0x80) {
DECLARE_WAIT_QUEUE_HEAD_ONSTACK(wq);
DEFINE_WAIT(wait);
unsigned char baud_reg;
switch (bt_cb(skb)->pkt_type) {
case PKT_BAUD_RATE_460800:
baud_reg = REG_CONTROL_BAUD_RATE_460800;
break;
case PKT_BAUD_RATE_230400:
baud_reg = REG_CONTROL_BAUD_RATE_230400;
break;
case PKT_BAUD_RATE_115200:
baud_reg = REG_CONTROL_BAUD_RATE_115200;
break;
case PKT_BAUD_RATE_57600:
default:
baud_reg = REG_CONTROL_BAUD_RATE_57600;
break;
}
prepare_to_wait(&wq, &wait, TASK_INTERRUPTIBLE);
schedule_timeout(HZ/10);
finish_wait(&wq, &wait);
info->ctrl_reg &= ~0x03;
info->ctrl_reg |= baud_reg;
outb(info->ctrl_reg, iobase + REG_CONTROL);
info->ctrl_reg &= ~REG_CONTROL_RTS;
outb(info->ctrl_reg, iobase + REG_CONTROL);
prepare_to_wait(&wq, &wait, TASK_INTERRUPTIBLE);
schedule_timeout(HZ);
finish_wait(&wq, &wait);
}
if (len == skb->len) {
kfree_skb(skb);
} else {
skb_pull(skb, len);
skb_queue_head(&(info->txq), skb);
}
info->hdev->stat.byte_tx += len;
change_bit(XMIT_BUFFER_NUMBER, &(info->tx_state));
} while (test_bit(XMIT_WAKEUP, &(info->tx_state)));
clear_bit(XMIT_SENDING, &(info->tx_state));
}
static int bluecard_read(unsigned int iobase, unsigned int offset, __u8 *buf, int size)
{
int i, n, len;
outb(REG_COMMAND_RX_WIN_ONE, iobase + REG_COMMAND);
len = inb(iobase + offset);
n = 0;
i = 1;
while (n < len) {
if (i == 16) {
outb(REG_COMMAND_RX_WIN_TWO, iobase + REG_COMMAND);
i = 0;
}
buf[n] = inb(iobase + offset + i);
n++;
i++;
}
return len;
}
static void bluecard_receive(bluecard_info_t *info, unsigned int offset)
{
unsigned int iobase;
unsigned char buf[31];
int i, len;
if (!info) {
BT_ERR("Unknown device");
return;
}
iobase = info->p_dev->resource[0]->start;
if (test_bit(XMIT_SENDING_READY, &(info->tx_state)))
bluecard_enable_activity_led(info);
len = bluecard_read(iobase, offset, buf, sizeof(buf));
for (i = 0; i < len; i++) {
if (info->rx_skb == NULL) {
info->rx_state = RECV_WAIT_PACKET_TYPE;
info->rx_count = 0;
if (!(info->rx_skb = bt_skb_alloc(HCI_MAX_FRAME_SIZE, GFP_ATOMIC))) {
BT_ERR("Can't allocate mem for new packet");
return;
}
}
if (info->rx_state == RECV_WAIT_PACKET_TYPE) {
info->rx_skb->dev = (void *) info->hdev;
bt_cb(info->rx_skb)->pkt_type = buf[i];
switch (bt_cb(info->rx_skb)->pkt_type) {
case 0x00:
if (offset != 0x00) {
set_bit(XMIT_BUF_ONE_READY, &(info->tx_state));
set_bit(XMIT_BUF_TWO_READY, &(info->tx_state));
set_bit(XMIT_SENDING_READY, &(info->tx_state));
bluecard_write_wakeup(info);
}
kfree_skb(info->rx_skb);
info->rx_skb = NULL;
break;
case HCI_EVENT_PKT:
info->rx_state = RECV_WAIT_EVENT_HEADER;
info->rx_count = HCI_EVENT_HDR_SIZE;
break;
case HCI_ACLDATA_PKT:
info->rx_state = RECV_WAIT_ACL_HEADER;
info->rx_count = HCI_ACL_HDR_SIZE;
break;
case HCI_SCODATA_PKT:
info->rx_state = RECV_WAIT_SCO_HEADER;
info->rx_count = HCI_SCO_HDR_SIZE;
break;
default:
BT_ERR("Unknown HCI packet with type 0x%02x received", bt_cb(info->rx_skb)->pkt_type);
info->hdev->stat.err_rx++;
kfree_skb(info->rx_skb);
info->rx_skb = NULL;
break;
}
} else {
*skb_put(info->rx_skb, 1) = buf[i];
info->rx_count--;
if (info->rx_count == 0) {
int dlen;
struct hci_event_hdr *eh;
struct hci_acl_hdr *ah;
struct hci_sco_hdr *sh;
switch (info->rx_state) {
case RECV_WAIT_EVENT_HEADER:
eh = hci_event_hdr(info->rx_skb);
info->rx_state = RECV_WAIT_DATA;
info->rx_count = eh->plen;
break;
case RECV_WAIT_ACL_HEADER:
ah = hci_acl_hdr(info->rx_skb);
dlen = __le16_to_cpu(ah->dlen);
info->rx_state = RECV_WAIT_DATA;
info->rx_count = dlen;
break;
case RECV_WAIT_SCO_HEADER:
sh = hci_sco_hdr(info->rx_skb);
info->rx_state = RECV_WAIT_DATA;
info->rx_count = sh->dlen;
break;
case RECV_WAIT_DATA:
hci_recv_frame(info->rx_skb);
info->rx_skb = NULL;
break;
}
}
}
}
info->hdev->stat.byte_rx += len;
}
static irqreturn_t bluecard_interrupt(int irq, void *dev_inst)
{
bluecard_info_t *info = dev_inst;
unsigned int iobase;
unsigned char reg;
if (!info || !info->hdev)
return IRQ_NONE;
if (!test_bit(CARD_READY, &(info->hw_state)))
return IRQ_HANDLED;
iobase = info->p_dev->resource[0]->start;
spin_lock(&(info->lock));
info->ctrl_reg &= ~REG_CONTROL_INTERRUPT;
outb(info->ctrl_reg, iobase + REG_CONTROL);
reg = inb(iobase + REG_INTERRUPT);
if ((reg != 0x00) && (reg != 0xff)) {
if (reg & 0x04) {
bluecard_receive(info, 0x00);
outb(0x04, iobase + REG_INTERRUPT);
outb(REG_COMMAND_RX_BUF_ONE, iobase + REG_COMMAND);
}
if (reg & 0x08) {
bluecard_receive(info, 0x10);
outb(0x08, iobase + REG_INTERRUPT);
outb(REG_COMMAND_RX_BUF_TWO, iobase + REG_COMMAND);
}
if (reg & 0x01) {
set_bit(XMIT_BUF_ONE_READY, &(info->tx_state));
outb(0x01, iobase + REG_INTERRUPT);
bluecard_write_wakeup(info);
}
if (reg & 0x02) {
set_bit(XMIT_BUF_TWO_READY, &(info->tx_state));
outb(0x02, iobase + REG_INTERRUPT);
bluecard_write_wakeup(info);
}
}
info->ctrl_reg |= REG_CONTROL_INTERRUPT;
outb(info->ctrl_reg, iobase + REG_CONTROL);
spin_unlock(&(info->lock));
return IRQ_HANDLED;
}
static int bluecard_hci_set_baud_rate(struct hci_dev *hdev, int baud)
{
bluecard_info_t *info = hci_get_drvdata(hdev);
struct sk_buff *skb;
unsigned char cmd[] = { HCI_COMMAND_PKT, 0x09, 0xfc, 0x01, 0x03 };
if (!(skb = bt_skb_alloc(HCI_MAX_FRAME_SIZE, GFP_ATOMIC))) {
BT_ERR("Can't allocate mem for new packet");
return -1;
}
switch (baud) {
case 460800:
cmd[4] = 0x00;
bt_cb(skb)->pkt_type = PKT_BAUD_RATE_460800;
break;
case 230400:
cmd[4] = 0x01;
bt_cb(skb)->pkt_type = PKT_BAUD_RATE_230400;
break;
case 115200:
cmd[4] = 0x02;
bt_cb(skb)->pkt_type = PKT_BAUD_RATE_115200;
break;
case 57600:
default:
cmd[4] = 0x03;
bt_cb(skb)->pkt_type = PKT_BAUD_RATE_57600;
break;
}
memcpy(skb_put(skb, sizeof(cmd)), cmd, sizeof(cmd));
skb_queue_tail(&(info->txq), skb);
bluecard_write_wakeup(info);
return 0;
}
static int bluecard_hci_flush(struct hci_dev *hdev)
{
bluecard_info_t *info = hci_get_drvdata(hdev);
skb_queue_purge(&(info->txq));
return 0;
}
static int bluecard_hci_open(struct hci_dev *hdev)
{
bluecard_info_t *info = hci_get_drvdata(hdev);
if (test_bit(CARD_HAS_PCCARD_ID, &(info->hw_state)))
bluecard_hci_set_baud_rate(hdev, DEFAULT_BAUD_RATE);
if (test_and_set_bit(HCI_RUNNING, &(hdev->flags)))
return 0;
if (test_bit(CARD_HAS_PCCARD_ID, &(info->hw_state))) {
unsigned int iobase = info->p_dev->resource[0]->start;
outb(0x08 | 0x20, iobase + 0x30);
}
return 0;
}
static int bluecard_hci_close(struct hci_dev *hdev)
{
bluecard_info_t *info = hci_get_drvdata(hdev);
if (!test_and_clear_bit(HCI_RUNNING, &(hdev->flags)))
return 0;
bluecard_hci_flush(hdev);
if (test_bit(CARD_HAS_PCCARD_ID, &(info->hw_state))) {
unsigned int iobase = info->p_dev->resource[0]->start;
outb(0x00, iobase + 0x30);
}
return 0;
}
static int bluecard_hci_send_frame(struct sk_buff *skb)
{
bluecard_info_t *info;
struct hci_dev *hdev = (struct hci_dev *)(skb->dev);
if (!hdev) {
BT_ERR("Frame for unknown HCI device (hdev=NULL)");
return -ENODEV;
}
info = hci_get_drvdata(hdev);
switch (bt_cb(skb)->pkt_type) {
case HCI_COMMAND_PKT:
hdev->stat.cmd_tx++;
break;
case HCI_ACLDATA_PKT:
hdev->stat.acl_tx++;
break;
case HCI_SCODATA_PKT:
hdev->stat.sco_tx++;
break;
};
memcpy(skb_push(skb, 1), &bt_cb(skb)->pkt_type, 1);
skb_queue_tail(&(info->txq), skb);
bluecard_write_wakeup(info);
return 0;
}
static int bluecard_hci_ioctl(struct hci_dev *hdev, unsigned int cmd, unsigned long arg)
{
return -ENOIOCTLCMD;
}
static int bluecard_open(bluecard_info_t *info)
{
unsigned int iobase = info->p_dev->resource[0]->start;
struct hci_dev *hdev;
unsigned char id;
spin_lock_init(&(info->lock));
init_timer(&(info->timer));
info->timer.function = &bluecard_activity_led_timeout;
info->timer.data = (u_long)info;
skb_queue_head_init(&(info->txq));
info->rx_state = RECV_WAIT_PACKET_TYPE;
info->rx_count = 0;
info->rx_skb = NULL;
hdev = hci_alloc_dev();
if (!hdev) {
BT_ERR("Can't allocate HCI device");
return -ENOMEM;
}
info->hdev = hdev;
hdev->bus = HCI_PCCARD;
hci_set_drvdata(hdev, info);
SET_HCIDEV_DEV(hdev, &info->p_dev->dev);
hdev->open = bluecard_hci_open;
hdev->close = bluecard_hci_close;
hdev->flush = bluecard_hci_flush;
hdev->send = bluecard_hci_send_frame;
hdev->ioctl = bluecard_hci_ioctl;
id = inb(iobase + 0x30);
if ((id & 0x0f) == 0x02)
set_bit(CARD_HAS_PCCARD_ID, &(info->hw_state));
if (id & 0x10)
set_bit(CARD_HAS_POWER_LED, &(info->hw_state));
if (id & 0x20)
set_bit(CARD_HAS_ACTIVITY_LED, &(info->hw_state));
info->ctrl_reg = REG_CONTROL_BT_RESET | REG_CONTROL_CARD_RESET;
outb(info->ctrl_reg, iobase + REG_CONTROL);
outb(0x80, iobase + 0x30);
msleep(10);
outb(0x00, iobase + 0x30);
info->ctrl_reg = REG_CONTROL_BT_ON | REG_CONTROL_BT_RES_PU;
outb(info->ctrl_reg, iobase + REG_CONTROL);
outb(0xff, iobase + REG_INTERRUPT);
info->ctrl_reg |= REG_CONTROL_INTERRUPT;
outb(info->ctrl_reg, iobase + REG_CONTROL);
if ((id & 0x0f) == 0x03) {
info->ctrl_reg |= REG_CONTROL_RTS;
outb(info->ctrl_reg, iobase + REG_CONTROL);
info->ctrl_reg |= 0x03;
outb(info->ctrl_reg, iobase + REG_CONTROL);
info->ctrl_reg &= ~REG_CONTROL_RTS;
outb(info->ctrl_reg, iobase + REG_CONTROL);
set_bit(XMIT_BUF_ONE_READY, &(info->tx_state));
set_bit(XMIT_BUF_TWO_READY, &(info->tx_state));
set_bit(XMIT_SENDING_READY, &(info->tx_state));
}
outb(REG_COMMAND_RX_BUF_ONE, iobase + REG_COMMAND);
outb(REG_COMMAND_RX_BUF_TWO, iobase + REG_COMMAND);
set_bit(CARD_READY, &(info->hw_state));
skb_queue_purge(&(info->txq));
outb((0x0f << RTS_LEVEL_SHIFT_BITS) | 1, iobase + REG_RX_CONTROL);
msleep(1250);
if (hci_register_dev(hdev) < 0) {
BT_ERR("Can't register HCI device");
info->hdev = NULL;
hci_free_dev(hdev);
return -ENODEV;
}
return 0;
}
static int bluecard_close(bluecard_info_t *info)
{
unsigned int iobase = info->p_dev->resource[0]->start;
struct hci_dev *hdev = info->hdev;
if (!hdev)
return -ENODEV;
bluecard_hci_close(hdev);
clear_bit(CARD_READY, &(info->hw_state));
info->ctrl_reg = REG_CONTROL_BT_RESET | REG_CONTROL_CARD_RESET;
outb(info->ctrl_reg, iobase + REG_CONTROL);
outb(0x80, iobase + 0x30);
hci_unregister_dev(hdev);
hci_free_dev(hdev);
return 0;
}
static int bluecard_probe(struct pcmcia_device *link)
{
bluecard_info_t *info;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->p_dev = link;
link->priv = info;
link->config_flags |= CONF_ENABLE_IRQ;
return bluecard_config(link);
}
static void bluecard_detach(struct pcmcia_device *link)
{
bluecard_info_t *info = link->priv;
bluecard_release(link);
kfree(info);
}
static int bluecard_config(struct pcmcia_device *link)
{
bluecard_info_t *info = link->priv;
int i, n;
link->config_index = 0x20;
link->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
link->resource[0]->end = 64;
link->io_lines = 6;
for (n = 0; n < 0x400; n += 0x40) {
link->resource[0]->start = n ^ 0x300;
i = pcmcia_request_io(link);
if (i == 0)
break;
}
if (i != 0)
goto failed;
i = pcmcia_request_irq(link, bluecard_interrupt);
if (i != 0)
goto failed;
i = pcmcia_enable_device(link);
if (i != 0)
goto failed;
if (bluecard_open(info) != 0)
goto failed;
return 0;
failed:
bluecard_release(link);
return -ENODEV;
}
static void bluecard_release(struct pcmcia_device *link)
{
bluecard_info_t *info = link->priv;
bluecard_close(info);
del_timer(&(info->timer));
pcmcia_disable_device(link);
}
static int __init init_bluecard_cs(void)
{
return pcmcia_register_driver(&bluecard_driver);
}
static void __exit exit_bluecard_cs(void)
{
pcmcia_unregister_driver(&bluecard_driver);
}
