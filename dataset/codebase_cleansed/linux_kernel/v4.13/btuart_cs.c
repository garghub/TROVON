static int btuart_write(unsigned int iobase, int fifo_size, __u8 *buf, int len)
{
int actual = 0;
if (!(inb(iobase + UART_LSR) & UART_LSR_THRE))
return 0;
while ((fifo_size-- > 0) && (actual < len)) {
outb(buf[actual], iobase + UART_TX);
actual++;
}
return actual;
}
static void btuart_write_wakeup(struct btuart_info *info)
{
if (!info) {
BT_ERR("Unknown device");
return;
}
if (test_and_set_bit(XMIT_SENDING, &(info->tx_state))) {
set_bit(XMIT_WAKEUP, &(info->tx_state));
return;
}
do {
unsigned int iobase = info->p_dev->resource[0]->start;
register struct sk_buff *skb;
int len;
clear_bit(XMIT_WAKEUP, &(info->tx_state));
if (!pcmcia_dev_present(info->p_dev))
return;
skb = skb_dequeue(&(info->txq));
if (!skb)
break;
len = btuart_write(iobase, 16, skb->data, skb->len);
set_bit(XMIT_WAKEUP, &(info->tx_state));
if (len == skb->len) {
kfree_skb(skb);
} else {
skb_pull(skb, len);
skb_queue_head(&(info->txq), skb);
}
info->hdev->stat.byte_tx += len;
} while (test_bit(XMIT_WAKEUP, &(info->tx_state)));
clear_bit(XMIT_SENDING, &(info->tx_state));
}
static void btuart_receive(struct btuart_info *info)
{
unsigned int iobase;
int boguscount = 0;
if (!info) {
BT_ERR("Unknown device");
return;
}
iobase = info->p_dev->resource[0]->start;
do {
info->hdev->stat.byte_rx++;
if (!info->rx_skb) {
info->rx_state = RECV_WAIT_PACKET_TYPE;
info->rx_count = 0;
info->rx_skb = bt_skb_alloc(HCI_MAX_FRAME_SIZE, GFP_ATOMIC);
if (!info->rx_skb) {
BT_ERR("Can't allocate mem for new packet");
return;
}
}
if (info->rx_state == RECV_WAIT_PACKET_TYPE) {
hci_skb_pkt_type(info->rx_skb) = inb(iobase + UART_RX);
switch (hci_skb_pkt_type(info->rx_skb)) {
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
BT_ERR("Unknown HCI packet with type 0x%02x received",
hci_skb_pkt_type(info->rx_skb));
info->hdev->stat.err_rx++;
kfree_skb(info->rx_skb);
info->rx_skb = NULL;
break;
}
} else {
skb_put_u8(info->rx_skb, inb(iobase + UART_RX));
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
hci_recv_frame(info->hdev, info->rx_skb);
info->rx_skb = NULL;
break;
}
}
}
if (boguscount++ > 16)
break;
} while (inb(iobase + UART_LSR) & UART_LSR_DR);
}
static irqreturn_t btuart_interrupt(int irq, void *dev_inst)
{
struct btuart_info *info = dev_inst;
unsigned int iobase;
int boguscount = 0;
int iir, lsr;
irqreturn_t r = IRQ_NONE;
if (!info || !info->hdev)
return IRQ_NONE;
iobase = info->p_dev->resource[0]->start;
spin_lock(&(info->lock));
iir = inb(iobase + UART_IIR) & UART_IIR_ID;
while (iir) {
r = IRQ_HANDLED;
lsr = inb(iobase + UART_LSR);
switch (iir) {
case UART_IIR_RLSI:
BT_ERR("RLSI");
break;
case UART_IIR_RDI:
btuart_receive(info);
break;
case UART_IIR_THRI:
if (lsr & UART_LSR_THRE) {
btuart_write_wakeup(info);
}
break;
default:
BT_ERR("Unhandled IIR=%#x", iir);
break;
}
if (boguscount++ > 100)
break;
iir = inb(iobase + UART_IIR) & UART_IIR_ID;
}
spin_unlock(&(info->lock));
return r;
}
static void btuart_change_speed(struct btuart_info *info,
unsigned int speed)
{
unsigned long flags;
unsigned int iobase;
int fcr;
int lcr;
int divisor;
if (!info) {
BT_ERR("Unknown device");
return;
}
iobase = info->p_dev->resource[0]->start;
spin_lock_irqsave(&(info->lock), flags);
outb(0, iobase + UART_IER);
divisor = SPEED_MAX / speed;
fcr = UART_FCR_ENABLE_FIFO | UART_FCR_CLEAR_RCVR | UART_FCR_CLEAR_XMIT;
if (speed < 38400)
fcr |= UART_FCR_TRIGGER_1;
else
fcr |= UART_FCR_TRIGGER_14;
lcr = UART_LCR_WLEN8;
outb(UART_LCR_DLAB | lcr, iobase + UART_LCR);
outb(divisor & 0xff, iobase + UART_DLL);
outb(divisor >> 8, iobase + UART_DLM);
outb(lcr, iobase + UART_LCR);
outb(fcr, iobase + UART_FCR);
outb(UART_IER_RLSI | UART_IER_RDI | UART_IER_THRI, iobase + UART_IER);
spin_unlock_irqrestore(&(info->lock), flags);
}
static int btuart_hci_flush(struct hci_dev *hdev)
{
struct btuart_info *info = hci_get_drvdata(hdev);
skb_queue_purge(&(info->txq));
return 0;
}
static int btuart_hci_open(struct hci_dev *hdev)
{
return 0;
}
static int btuart_hci_close(struct hci_dev *hdev)
{
btuart_hci_flush(hdev);
return 0;
}
static int btuart_hci_send_frame(struct hci_dev *hdev, struct sk_buff *skb)
{
struct btuart_info *info = hci_get_drvdata(hdev);
switch (hci_skb_pkt_type(skb)) {
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
memcpy(skb_push(skb, 1), &hci_skb_pkt_type(skb), 1);
skb_queue_tail(&(info->txq), skb);
btuart_write_wakeup(info);
return 0;
}
static int btuart_open(struct btuart_info *info)
{
unsigned long flags;
unsigned int iobase = info->p_dev->resource[0]->start;
struct hci_dev *hdev;
spin_lock_init(&(info->lock));
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
hdev->open = btuart_hci_open;
hdev->close = btuart_hci_close;
hdev->flush = btuart_hci_flush;
hdev->send = btuart_hci_send_frame;
spin_lock_irqsave(&(info->lock), flags);
outb(0, iobase + UART_MCR);
outb(0, iobase + UART_IER);
outb(UART_LCR_WLEN8, iobase + UART_LCR);
outb((UART_MCR_DTR | UART_MCR_RTS | UART_MCR_OUT2), iobase + UART_MCR);
spin_unlock_irqrestore(&(info->lock), flags);
btuart_change_speed(info, DEFAULT_BAUD_RATE);
msleep(1000);
if (hci_register_dev(hdev) < 0) {
BT_ERR("Can't register HCI device");
info->hdev = NULL;
hci_free_dev(hdev);
return -ENODEV;
}
return 0;
}
static int btuart_close(struct btuart_info *info)
{
unsigned long flags;
unsigned int iobase = info->p_dev->resource[0]->start;
struct hci_dev *hdev = info->hdev;
if (!hdev)
return -ENODEV;
btuart_hci_close(hdev);
spin_lock_irqsave(&(info->lock), flags);
outb(0, iobase + UART_MCR);
outb(0, iobase + UART_IER);
spin_unlock_irqrestore(&(info->lock), flags);
hci_unregister_dev(hdev);
hci_free_dev(hdev);
return 0;
}
static int btuart_probe(struct pcmcia_device *link)
{
struct btuart_info *info;
info = devm_kzalloc(&link->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->p_dev = link;
link->priv = info;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_VPP |
CONF_AUTO_SET_IO;
return btuart_config(link);
}
static void btuart_detach(struct pcmcia_device *link)
{
btuart_release(link);
}
static int btuart_check_config(struct pcmcia_device *p_dev, void *priv_data)
{
int *try = priv_data;
if (!try)
p_dev->io_lines = 16;
if ((p_dev->resource[0]->end != 8) || (p_dev->resource[0]->start == 0))
return -EINVAL;
p_dev->resource[0]->end = 8;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
return pcmcia_request_io(p_dev);
}
static int btuart_check_config_notpicky(struct pcmcia_device *p_dev,
void *priv_data)
{
static unsigned int base[5] = { 0x3f8, 0x2f8, 0x3e8, 0x2e8, 0x0 };
int j;
if (p_dev->io_lines > 3)
return -ENODEV;
p_dev->resource[0]->flags &= ~IO_DATA_PATH_WIDTH;
p_dev->resource[0]->flags |= IO_DATA_PATH_WIDTH_8;
p_dev->resource[0]->end = 8;
for (j = 0; j < 5; j++) {
p_dev->resource[0]->start = base[j];
p_dev->io_lines = base[j] ? 16 : 3;
if (!pcmcia_request_io(p_dev))
return 0;
}
return -ENODEV;
}
static int btuart_config(struct pcmcia_device *link)
{
struct btuart_info *info = link->priv;
int i;
int try;
for (try = 0; try < 2; try++)
if (!pcmcia_loop_config(link, btuart_check_config, &try))
goto found_port;
if (!pcmcia_loop_config(link, btuart_check_config_notpicky, NULL))
goto found_port;
BT_ERR("No usable port range found");
goto failed;
found_port:
i = pcmcia_request_irq(link, btuart_interrupt);
if (i != 0)
goto failed;
i = pcmcia_enable_device(link);
if (i != 0)
goto failed;
if (btuart_open(info) != 0)
goto failed;
return 0;
failed:
btuart_release(link);
return -ENODEV;
}
static void btuart_release(struct pcmcia_device *link)
{
struct btuart_info *info = link->priv;
btuart_close(info);
pcmcia_disable_device(link);
}
