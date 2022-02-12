static inline void bt3c_address(unsigned int iobase, unsigned short addr)
{
outb(addr & 0xff, iobase + ADDR_L);
outb((addr >> 8) & 0xff, iobase + ADDR_H);
}
static inline void bt3c_put(unsigned int iobase, unsigned short value)
{
outb(value & 0xff, iobase + DATA_L);
outb((value >> 8) & 0xff, iobase + DATA_H);
}
static inline void bt3c_io_write(unsigned int iobase, unsigned short addr, unsigned short value)
{
bt3c_address(iobase, addr);
bt3c_put(iobase, value);
}
static inline unsigned short bt3c_get(unsigned int iobase)
{
unsigned short value = inb(iobase + DATA_L);
value |= inb(iobase + DATA_H) << 8;
return value;
}
static inline unsigned short bt3c_read(unsigned int iobase, unsigned short addr)
{
bt3c_address(iobase, addr);
return bt3c_get(iobase);
}
static int bt3c_write(unsigned int iobase, int fifo_size, __u8 *buf, int len)
{
int actual = 0;
bt3c_address(iobase, 0x7080);
while (actual < len) {
bt3c_put(iobase, buf[actual]);
actual++;
}
bt3c_io_write(iobase, 0x7005, actual);
return actual;
}
static void bt3c_write_wakeup(struct bt3c_info *info)
{
if (!info) {
BT_ERR("Unknown device");
return;
}
if (test_and_set_bit(XMIT_SENDING, &(info->tx_state)))
return;
do {
unsigned int iobase = info->p_dev->resource[0]->start;
register struct sk_buff *skb;
int len;
if (!pcmcia_dev_present(info->p_dev))
break;
skb = skb_dequeue(&(info->txq));
if (!skb) {
clear_bit(XMIT_SENDING, &(info->tx_state));
break;
}
len = bt3c_write(iobase, 256, skb->data, skb->len);
if (len != skb->len)
BT_ERR("Very strange");
kfree_skb(skb);
info->hdev->stat.byte_tx += len;
} while (0);
}
static void bt3c_receive(struct bt3c_info *info)
{
unsigned int iobase;
int size = 0, avail;
if (!info) {
BT_ERR("Unknown device");
return;
}
iobase = info->p_dev->resource[0]->start;
avail = bt3c_read(iobase, 0x7006);
bt3c_address(iobase, 0x7480);
while (size < avail) {
size++;
info->hdev->stat.byte_rx++;
if (info->rx_skb == NULL) {
info->rx_state = RECV_WAIT_PACKET_TYPE;
info->rx_count = 0;
info->rx_skb = bt_skb_alloc(HCI_MAX_FRAME_SIZE, GFP_ATOMIC);
if (!info->rx_skb) {
BT_ERR("Can't allocate mem for new packet");
return;
}
}
if (info->rx_state == RECV_WAIT_PACKET_TYPE) {
bt_cb(info->rx_skb)->pkt_type = inb(iobase + DATA_L);
inb(iobase + DATA_H);
switch (bt_cb(info->rx_skb)->pkt_type) {
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
clear_bit(HCI_RUNNING, &(info->hdev->flags));
kfree_skb(info->rx_skb);
info->rx_skb = NULL;
break;
}
} else {
__u8 x = inb(iobase + DATA_L);
*skb_put(info->rx_skb, 1) = x;
inb(iobase + DATA_H);
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
}
bt3c_io_write(iobase, 0x7006, 0x0000);
}
static irqreturn_t bt3c_interrupt(int irq, void *dev_inst)
{
struct bt3c_info *info = dev_inst;
unsigned int iobase;
int iir;
irqreturn_t r = IRQ_NONE;
if (!info || !info->hdev)
return IRQ_NONE;
iobase = info->p_dev->resource[0]->start;
spin_lock(&(info->lock));
iir = inb(iobase + CONTROL);
if (iir & 0x80) {
int stat = bt3c_read(iobase, 0x7001);
if ((stat & 0xff) == 0x7f) {
BT_ERR("Very strange (stat=0x%04x)", stat);
} else if ((stat & 0xff) != 0xff) {
if (stat & 0x0020) {
int status = bt3c_read(iobase, 0x7002) & 0x10;
BT_INFO("%s: Antenna %s", info->hdev->name,
status ? "out" : "in");
}
if (stat & 0x0001)
bt3c_receive(info);
if (stat & 0x0002) {
clear_bit(XMIT_SENDING, &(info->tx_state));
bt3c_write_wakeup(info);
}
bt3c_io_write(iobase, 0x7001, 0x0000);
outb(iir, iobase + CONTROL);
}
r = IRQ_HANDLED;
}
spin_unlock(&(info->lock));
return r;
}
static int bt3c_hci_flush(struct hci_dev *hdev)
{
struct bt3c_info *info = hci_get_drvdata(hdev);
skb_queue_purge(&(info->txq));
return 0;
}
static int bt3c_hci_open(struct hci_dev *hdev)
{
set_bit(HCI_RUNNING, &(hdev->flags));
return 0;
}
static int bt3c_hci_close(struct hci_dev *hdev)
{
if (!test_and_clear_bit(HCI_RUNNING, &(hdev->flags)))
return 0;
bt3c_hci_flush(hdev);
return 0;
}
static int bt3c_hci_send_frame(struct hci_dev *hdev, struct sk_buff *skb)
{
struct bt3c_info *info = hci_get_drvdata(hdev);
unsigned long flags;
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
spin_lock_irqsave(&(info->lock), flags);
bt3c_write_wakeup(info);
spin_unlock_irqrestore(&(info->lock), flags);
return 0;
}
static int bt3c_load_firmware(struct bt3c_info *info,
const unsigned char *firmware,
int count)
{
char *ptr = (char *) firmware;
char b[9];
unsigned int iobase, size, addr, fcs, tmp;
int i, err = 0;
iobase = info->p_dev->resource[0]->start;
bt3c_io_write(iobase, 0x8040, 0x0404);
bt3c_io_write(iobase, 0x8040, 0x0400);
udelay(1);
bt3c_io_write(iobase, 0x8040, 0x0404);
udelay(17);
while (count) {
if (ptr[0] != 'S') {
BT_ERR("Bad address in firmware");
err = -EFAULT;
goto error;
}
memset(b, 0, sizeof(b));
memcpy(b, ptr + 2, 2);
size = simple_strtoul(b, NULL, 16);
memset(b, 0, sizeof(b));
memcpy(b, ptr + 4, 8);
addr = simple_strtoul(b, NULL, 16);
memset(b, 0, sizeof(b));
memcpy(b, ptr + (size * 2) + 2, 2);
fcs = simple_strtoul(b, NULL, 16);
memset(b, 0, sizeof(b));
for (tmp = 0, i = 0; i < size; i++) {
memcpy(b, ptr + (i * 2) + 2, 2);
tmp += simple_strtol(b, NULL, 16);
}
if (((tmp + fcs) & 0xff) != 0xff) {
BT_ERR("Checksum error in firmware");
err = -EILSEQ;
goto error;
}
if (ptr[1] == '3') {
bt3c_address(iobase, addr);
memset(b, 0, sizeof(b));
for (i = 0; i < (size - 4) / 2; i++) {
memcpy(b, ptr + (i * 4) + 12, 4);
tmp = simple_strtoul(b, NULL, 16);
bt3c_put(iobase, tmp);
}
}
ptr += (size * 2) + 6;
count -= (size * 2) + 6;
}
udelay(17);
bt3c_address(iobase, 0x3000);
outb(inb(iobase + CONTROL) | 0x40, iobase + CONTROL);
error:
udelay(17);
bt3c_io_write(iobase, 0x7006, 0x0000);
bt3c_io_write(iobase, 0x7005, 0x0000);
bt3c_io_write(iobase, 0x7001, 0x0000);
return err;
}
static int bt3c_open(struct bt3c_info *info)
{
const struct firmware *firmware;
struct hci_dev *hdev;
int err;
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
hdev->open = bt3c_hci_open;
hdev->close = bt3c_hci_close;
hdev->flush = bt3c_hci_flush;
hdev->send = bt3c_hci_send_frame;
err = request_firmware(&firmware, "BT3CPCC.bin", &info->p_dev->dev);
if (err < 0) {
BT_ERR("Firmware request failed");
goto error;
}
err = bt3c_load_firmware(info, firmware->data, firmware->size);
release_firmware(firmware);
if (err < 0) {
BT_ERR("Firmware loading failed");
goto error;
}
msleep(1000);
err = hci_register_dev(hdev);
if (err < 0) {
BT_ERR("Can't register HCI device");
goto error;
}
return 0;
error:
info->hdev = NULL;
hci_free_dev(hdev);
return err;
}
static int bt3c_close(struct bt3c_info *info)
{
struct hci_dev *hdev = info->hdev;
if (!hdev)
return -ENODEV;
bt3c_hci_close(hdev);
hci_unregister_dev(hdev);
hci_free_dev(hdev);
return 0;
}
static int bt3c_probe(struct pcmcia_device *link)
{
struct bt3c_info *info;
info = devm_kzalloc(&link->dev, sizeof(*info), GFP_KERNEL);
if (!info)
return -ENOMEM;
info->p_dev = link;
link->priv = info;
link->config_flags |= CONF_ENABLE_IRQ | CONF_AUTO_SET_VPP |
CONF_AUTO_SET_IO;
return bt3c_config(link);
}
static void bt3c_detach(struct pcmcia_device *link)
{
bt3c_release(link);
}
static int bt3c_check_config(struct pcmcia_device *p_dev, void *priv_data)
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
static int bt3c_check_config_notpicky(struct pcmcia_device *p_dev,
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
static int bt3c_config(struct pcmcia_device *link)
{
struct bt3c_info *info = link->priv;
int i;
unsigned long try;
for (try = 0; try < 2; try++)
if (!pcmcia_loop_config(link, bt3c_check_config, (void *) try))
goto found_port;
if (!pcmcia_loop_config(link, bt3c_check_config_notpicky, NULL))
goto found_port;
BT_ERR("No usable port range found");
goto failed;
found_port:
i = pcmcia_request_irq(link, &bt3c_interrupt);
if (i != 0)
goto failed;
i = pcmcia_enable_device(link);
if (i != 0)
goto failed;
if (bt3c_open(info) != 0)
goto failed;
return 0;
failed:
bt3c_release(link);
return -ENODEV;
}
static void bt3c_release(struct pcmcia_device *link)
{
struct bt3c_info *info = link->priv;
bt3c_close(info);
pcmcia_disable_device(link);
}
