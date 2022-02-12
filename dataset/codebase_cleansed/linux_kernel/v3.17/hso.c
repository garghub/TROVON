static inline struct hso_net *dev2net(struct hso_device *hso_dev)
{
return hso_dev->port_data.dev_net;
}
static inline struct hso_serial *dev2ser(struct hso_device *hso_dev)
{
return hso_dev->port_data.dev_serial;
}
static void dbg_dump(int line_count, const char *func_name, unsigned char *buf,
unsigned int len)
{
static char name[255];
sprintf(name, "hso[%d:%s]", line_count, func_name);
print_hex_dump_bytes(name, DUMP_PREFIX_NONE, buf, len);
}
static ssize_t hso_sysfs_show_porttype(struct device *dev,
struct device_attribute *attr,
char *buf)
{
struct hso_device *hso_dev = dev_get_drvdata(dev);
char *port_name;
if (!hso_dev)
return 0;
switch (hso_dev->port_spec & HSO_PORT_MASK) {
case HSO_PORT_CONTROL:
port_name = "Control";
break;
case HSO_PORT_APP:
port_name = "Application";
break;
case HSO_PORT_APP2:
port_name = "Application2";
break;
case HSO_PORT_GPS:
port_name = "GPS";
break;
case HSO_PORT_GPS_CONTROL:
port_name = "GPS Control";
break;
case HSO_PORT_PCSC:
port_name = "PCSC";
break;
case HSO_PORT_DIAG:
port_name = "Diagnostic";
break;
case HSO_PORT_DIAG2:
port_name = "Diagnostic2";
break;
case HSO_PORT_MODEM:
port_name = "Modem";
break;
case HSO_PORT_NETWORK:
port_name = "Network";
break;
default:
port_name = "Unknown";
break;
}
return sprintf(buf, "%s\n", port_name);
}
static int hso_urb_to_index(struct hso_serial *serial, struct urb *urb)
{
int idx;
for (idx = 0; idx < serial->num_rx_urbs; idx++)
if (serial->rx_urb[idx] == urb)
return idx;
dev_err(serial->parent->dev, "hso_urb_to_index failed\n");
return -1;
}
static u32 hso_mux_to_port(int mux)
{
u32 result;
switch (mux) {
case 0x1:
result = HSO_PORT_CONTROL;
break;
case 0x2:
result = HSO_PORT_APP;
break;
case 0x4:
result = HSO_PORT_PCSC;
break;
case 0x8:
result = HSO_PORT_GPS;
break;
case 0x10:
result = HSO_PORT_APP2;
break;
default:
result = HSO_PORT_NO_PORT;
}
return result;
}
static u32 hso_port_to_mux(int port)
{
u32 result;
switch (port & HSO_PORT_MASK) {
case HSO_PORT_CONTROL:
result = 0x0;
break;
case HSO_PORT_APP:
result = 0x1;
break;
case HSO_PORT_PCSC:
result = 0x2;
break;
case HSO_PORT_GPS:
result = 0x3;
break;
case HSO_PORT_APP2:
result = 0x4;
break;
default:
result = 0x0;
}
return result;
}
static struct hso_serial *get_serial_by_shared_int_and_type(
struct hso_shared_int *shared_int,
int mux)
{
int i, port;
port = hso_mux_to_port(mux);
for (i = 0; i < HSO_SERIAL_TTY_MINORS; i++) {
if (serial_table[i] &&
(dev2ser(serial_table[i])->shared_int == shared_int) &&
((serial_table[i]->port_spec & HSO_PORT_MASK) == port)) {
return dev2ser(serial_table[i]);
}
}
return NULL;
}
static struct hso_serial *get_serial_by_index(unsigned index)
{
struct hso_serial *serial = NULL;
unsigned long flags;
spin_lock_irqsave(&serial_table_lock, flags);
if (serial_table[index])
serial = dev2ser(serial_table[index]);
spin_unlock_irqrestore(&serial_table_lock, flags);
return serial;
}
static int get_free_serial_index(void)
{
int index;
unsigned long flags;
spin_lock_irqsave(&serial_table_lock, flags);
for (index = 0; index < HSO_SERIAL_TTY_MINORS; index++) {
if (serial_table[index] == NULL) {
spin_unlock_irqrestore(&serial_table_lock, flags);
return index;
}
}
spin_unlock_irqrestore(&serial_table_lock, flags);
printk(KERN_ERR "%s: no free serial devices in table\n", __func__);
return -1;
}
static void set_serial_by_index(unsigned index, struct hso_serial *serial)
{
unsigned long flags;
spin_lock_irqsave(&serial_table_lock, flags);
if (serial)
serial_table[index] = serial->parent;
else
serial_table[index] = NULL;
spin_unlock_irqrestore(&serial_table_lock, flags);
}
static void handle_usb_error(int status, const char *function,
struct hso_device *hso_dev)
{
char *explanation;
switch (status) {
case -ENODEV:
explanation = "no device";
break;
case -ENOENT:
explanation = "endpoint not enabled";
break;
case -EPIPE:
explanation = "endpoint stalled";
break;
case -ENOSPC:
explanation = "not enough bandwidth";
break;
case -ESHUTDOWN:
explanation = "device disabled";
break;
case -EHOSTUNREACH:
explanation = "device suspended";
break;
case -EINVAL:
case -EAGAIN:
case -EFBIG:
case -EMSGSIZE:
explanation = "internal error";
break;
case -EILSEQ:
case -EPROTO:
case -ETIME:
case -ETIMEDOUT:
explanation = "protocol error";
if (hso_dev)
schedule_work(&hso_dev->reset_device);
break;
default:
explanation = "unknown status";
break;
}
D1("%s: received USB status - %s (%d)", function, explanation, status);
}
static int hso_net_open(struct net_device *net)
{
struct hso_net *odev = netdev_priv(net);
unsigned long flags = 0;
if (!odev) {
dev_err(&net->dev, "No net device !\n");
return -ENODEV;
}
odev->skb_tx_buf = NULL;
spin_lock_irqsave(&odev->net_lock, flags);
odev->rx_parse_state = WAIT_IP;
odev->rx_buf_size = 0;
odev->rx_buf_missing = sizeof(struct iphdr);
spin_unlock_irqrestore(&odev->net_lock, flags);
set_bit(HSO_NET_RUNNING, &odev->flags);
hso_start_net_device(odev->parent);
netif_start_queue(net);
return 0;
}
static int hso_net_close(struct net_device *net)
{
struct hso_net *odev = netdev_priv(net);
netif_stop_queue(net);
clear_bit(HSO_NET_RUNNING, &odev->flags);
hso_stop_net_device(odev->parent);
return 0;
}
static void write_bulk_callback(struct urb *urb)
{
struct hso_net *odev = urb->context;
int status = urb->status;
if (!odev || !test_bit(HSO_NET_RUNNING, &odev->flags)) {
dev_err(&urb->dev->dev, "%s: device not running\n", __func__);
return;
}
if (!netif_device_present(odev->net)) {
dev_err(&urb->dev->dev, "%s: net device not present\n",
__func__);
return;
}
if (status)
handle_usb_error(status, __func__, odev->parent);
hso_put_activity(odev->parent);
netif_wake_queue(odev->net);
}
static netdev_tx_t hso_net_start_xmit(struct sk_buff *skb,
struct net_device *net)
{
struct hso_net *odev = netdev_priv(net);
int result;
netif_stop_queue(net);
if (hso_get_activity(odev->parent) == -EAGAIN) {
odev->skb_tx_buf = skb;
return NETDEV_TX_OK;
}
DUMP1(skb->data, skb->len);
memcpy(odev->mux_bulk_tx_buf, skb->data, skb->len);
D1("len: %d/%d", skb->len, MUX_BULK_TX_BUF_SIZE);
usb_fill_bulk_urb(odev->mux_bulk_tx_urb,
odev->parent->usb,
usb_sndbulkpipe(odev->parent->usb,
odev->out_endp->
bEndpointAddress & 0x7F),
odev->mux_bulk_tx_buf, skb->len, write_bulk_callback,
odev);
odev->mux_bulk_tx_urb->transfer_flags |= URB_ZERO_PACKET;
result = usb_submit_urb(odev->mux_bulk_tx_urb, GFP_ATOMIC);
if (result) {
dev_warn(&odev->parent->interface->dev,
"failed mux_bulk_tx_urb %d\n", result);
net->stats.tx_errors++;
netif_start_queue(net);
} else {
net->stats.tx_packets++;
net->stats.tx_bytes += skb->len;
}
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static void hso_net_tx_timeout(struct net_device *net)
{
struct hso_net *odev = netdev_priv(net);
if (!odev)
return;
dev_warn(&net->dev, "Tx timed out.\n");
if (odev->mux_bulk_tx_urb &&
(odev->mux_bulk_tx_urb->status == -EINPROGRESS))
usb_unlink_urb(odev->mux_bulk_tx_urb);
net->stats.tx_errors++;
}
static void packetizeRx(struct hso_net *odev, unsigned char *ip_pkt,
unsigned int count, unsigned char is_eop)
{
unsigned short temp_bytes;
unsigned short buffer_offset = 0;
unsigned short frame_len;
unsigned char *tmp_rx_buf;
D1("Rx %d bytes", count);
DUMP(ip_pkt, min(128, (int)count));
while (count) {
switch (odev->rx_parse_state) {
case WAIT_IP:
temp_bytes =
(count <
odev->rx_buf_missing) ? count : odev->
rx_buf_missing;
memcpy(((unsigned char *)(&odev->rx_ip_hdr)) +
odev->rx_buf_size, ip_pkt + buffer_offset,
temp_bytes);
odev->rx_buf_size += temp_bytes;
buffer_offset += temp_bytes;
odev->rx_buf_missing -= temp_bytes;
count -= temp_bytes;
if (!odev->rx_buf_missing) {
frame_len = ntohs(odev->rx_ip_hdr.tot_len);
if ((frame_len > DEFAULT_MRU) ||
(frame_len < sizeof(struct iphdr))) {
dev_err(&odev->net->dev,
"Invalid frame (%d) length\n",
frame_len);
odev->rx_parse_state = WAIT_SYNC;
continue;
}
odev->skb_rx_buf = netdev_alloc_skb(odev->net,
frame_len);
if (!odev->skb_rx_buf) {
D1("could not allocate memory");
odev->rx_parse_state = WAIT_SYNC;
return;
}
tmp_rx_buf =
skb_put(odev->skb_rx_buf,
sizeof(struct iphdr));
memcpy(tmp_rx_buf, (char *)&(odev->rx_ip_hdr),
sizeof(struct iphdr));
odev->rx_buf_size = sizeof(struct iphdr);
odev->rx_buf_missing =
frame_len - sizeof(struct iphdr);
odev->rx_parse_state = WAIT_DATA;
}
break;
case WAIT_DATA:
temp_bytes = (count < odev->rx_buf_missing)
? count : odev->rx_buf_missing;
tmp_rx_buf = skb_put(odev->skb_rx_buf, temp_bytes);
memcpy(tmp_rx_buf, ip_pkt + buffer_offset, temp_bytes);
odev->rx_buf_missing -= temp_bytes;
count -= temp_bytes;
buffer_offset += temp_bytes;
odev->rx_buf_size += temp_bytes;
if (!odev->rx_buf_missing) {
odev->skb_rx_buf->protocol = cpu_to_be16(ETH_P_IP);
skb_reset_mac_header(odev->skb_rx_buf);
netif_rx(odev->skb_rx_buf);
odev->skb_rx_buf = NULL;
odev->net->stats.rx_packets++;
odev->net->stats.rx_bytes += odev->rx_buf_size;
odev->rx_buf_size = 0;
odev->rx_buf_missing = sizeof(struct iphdr);
odev->rx_parse_state = WAIT_IP;
}
break;
case WAIT_SYNC:
D1(" W_S");
count = 0;
break;
default:
D1(" ");
count--;
break;
}
}
if (is_eop) {
if (odev->rx_parse_state == WAIT_SYNC) {
odev->rx_parse_state = WAIT_IP;
odev->rx_buf_size = 0;
odev->rx_buf_missing = sizeof(struct iphdr);
}
}
}
static void fix_crc_bug(struct urb *urb, __le16 max_packet_size)
{
static const u8 crc_check[4] = { 0xDE, 0xAD, 0xBE, 0xEF };
u32 rest = urb->actual_length % le16_to_cpu(max_packet_size);
if (((rest == 5) || (rest == 6)) &&
!memcmp(((u8 *)urb->transfer_buffer) + urb->actual_length - 4,
crc_check, 4)) {
urb->actual_length -= 4;
}
}
static void read_bulk_callback(struct urb *urb)
{
struct hso_net *odev = urb->context;
struct net_device *net;
int result;
int status = urb->status;
if (status) {
handle_usb_error(status, __func__, odev->parent);
return;
}
if (!odev || !test_bit(HSO_NET_RUNNING, &odev->flags)) {
D1("BULK IN callback but driver is not active!");
return;
}
usb_mark_last_busy(urb->dev);
net = odev->net;
if (!netif_device_present(net)) {
return;
}
if (odev->parent->port_spec & HSO_INFO_CRC_BUG)
fix_crc_bug(urb, odev->in_endp->wMaxPacketSize);
if (urb->actual_length) {
spin_lock(&odev->net_lock);
packetizeRx(odev, urb->transfer_buffer, urb->actual_length,
(urb->transfer_buffer_length >
urb->actual_length) ? 1 : 0);
spin_unlock(&odev->net_lock);
}
usb_fill_bulk_urb(urb,
odev->parent->usb,
usb_rcvbulkpipe(odev->parent->usb,
odev->in_endp->
bEndpointAddress & 0x7F),
urb->transfer_buffer, MUX_BULK_RX_BUF_SIZE,
read_bulk_callback, odev);
result = usb_submit_urb(urb, GFP_ATOMIC);
if (result)
dev_warn(&odev->parent->interface->dev,
"%s failed submit mux_bulk_rx_urb %d\n", __func__,
result);
}
static void hso_init_termios(struct ktermios *termios)
{
termios->c_iflag &=
~(IGNBRK
| BRKINT
| PARMRK
| ISTRIP
| INLCR
| IGNCR
| ICRNL
| IXON);
termios->c_oflag &= ~OPOST;
termios->c_lflag &=
~(ECHO
| ECHONL
| ICANON
| ISIG
| IEXTEN);
termios->c_cflag &=
~(CSIZE
| PARENB
| CBAUD
| CBAUDEX);
termios->c_cflag |= CS8;
tty_termios_encode_baud_rate(termios, 115200, 115200);
}
static void _hso_serial_set_termios(struct tty_struct *tty,
struct ktermios *old)
{
struct hso_serial *serial = tty->driver_data;
if (!serial) {
printk(KERN_ERR "%s: no tty structures", __func__);
return;
}
D4("port %d", serial->minor);
tty->termios.c_iflag &= ~IXON;
tty->termios.c_cflag &=
~(CSIZE
| PARENB
| CBAUD
| CBAUDEX);
tty->termios.c_cflag |= CS8;
tty_encode_baud_rate(tty, 115200, 115200);
}
static void hso_resubmit_rx_bulk_urb(struct hso_serial *serial, struct urb *urb)
{
int result;
usb_fill_bulk_urb(urb, serial->parent->usb,
usb_rcvbulkpipe(serial->parent->usb,
serial->in_endp->
bEndpointAddress & 0x7F),
urb->transfer_buffer, serial->rx_data_length,
hso_std_serial_read_bulk_callback, serial);
result = usb_submit_urb(urb, GFP_ATOMIC);
if (result) {
dev_err(&urb->dev->dev, "%s failed submit serial rx_urb %d\n",
__func__, result);
}
}
static void put_rxbuf_data_and_resubmit_bulk_urb(struct hso_serial *serial)
{
int count;
struct urb *curr_urb;
while (serial->rx_urb_filled[serial->curr_rx_urb_idx]) {
curr_urb = serial->rx_urb[serial->curr_rx_urb_idx];
count = put_rxbuf_data(curr_urb, serial);
if (count == -1)
return;
if (count == 0) {
serial->curr_rx_urb_idx++;
if (serial->curr_rx_urb_idx >= serial->num_rx_urbs)
serial->curr_rx_urb_idx = 0;
hso_resubmit_rx_bulk_urb(serial, curr_urb);
}
}
}
static void put_rxbuf_data_and_resubmit_ctrl_urb(struct hso_serial *serial)
{
int count = 0;
struct urb *urb;
urb = serial->rx_urb[0];
if (serial->port.count > 0) {
count = put_rxbuf_data(urb, serial);
if (count == -1)
return;
}
if (count == 0 && ((urb->actual_length != 0) ||
(serial->rx_state == RX_PENDING))) {
serial->rx_state = RX_SENT;
hso_mux_serial_read(serial);
} else
serial->rx_state = RX_IDLE;
}
static void hso_std_serial_read_bulk_callback(struct urb *urb)
{
struct hso_serial *serial = urb->context;
int status = urb->status;
D4("\n--- Got serial_read_bulk callback %02x ---", status);
if (!serial) {
D1("serial == NULL");
return;
}
if (status) {
handle_usb_error(status, __func__, serial->parent);
return;
}
D1("Actual length = %d\n", urb->actual_length);
DUMP1(urb->transfer_buffer, urb->actual_length);
if (serial->port.count == 0)
return;
if (serial->parent->port_spec & HSO_INFO_CRC_BUG)
fix_crc_bug(urb, serial->in_endp->wMaxPacketSize);
spin_lock(&serial->serial_lock);
serial->rx_urb_filled[hso_urb_to_index(serial, urb)] = 1;
put_rxbuf_data_and_resubmit_bulk_urb(serial);
spin_unlock(&serial->serial_lock);
}
static void hso_unthrottle_tasklet(struct hso_serial *serial)
{
unsigned long flags;
spin_lock_irqsave(&serial->serial_lock, flags);
if ((serial->parent->port_spec & HSO_INTF_MUX))
put_rxbuf_data_and_resubmit_ctrl_urb(serial);
else
put_rxbuf_data_and_resubmit_bulk_urb(serial);
spin_unlock_irqrestore(&serial->serial_lock, flags);
}
static void hso_unthrottle(struct tty_struct *tty)
{
struct hso_serial *serial = tty->driver_data;
tasklet_hi_schedule(&serial->unthrottle_tasklet);
}
static int hso_serial_open(struct tty_struct *tty, struct file *filp)
{
struct hso_serial *serial = get_serial_by_index(tty->index);
int result;
if (serial == NULL || serial->magic != HSO_SERIAL_MAGIC) {
WARN_ON(1);
tty->driver_data = NULL;
D1("Failed to open port");
return -ENODEV;
}
mutex_lock(&serial->parent->mutex);
result = usb_autopm_get_interface(serial->parent->interface);
if (result < 0)
goto err_out;
D1("Opening %d", serial->minor);
kref_get(&serial->parent->ref);
tty->driver_data = serial;
tty_port_tty_set(&serial->port, tty);
serial->port.count++;
if (serial->port.count == 1) {
serial->rx_state = RX_IDLE;
_hso_serial_set_termios(tty, NULL);
tasklet_init(&serial->unthrottle_tasklet,
(void (*)(unsigned long))hso_unthrottle_tasklet,
(unsigned long)serial);
result = hso_start_serial_device(serial->parent, GFP_KERNEL);
if (result) {
hso_stop_serial_device(serial->parent);
serial->port.count--;
kref_put(&serial->parent->ref, hso_serial_ref_free);
}
} else {
D1("Port was already open");
}
usb_autopm_put_interface(serial->parent->interface);
if (result)
hso_serial_tiocmset(tty, TIOCM_RTS | TIOCM_DTR, 0);
err_out:
mutex_unlock(&serial->parent->mutex);
return result;
}
static void hso_serial_close(struct tty_struct *tty, struct file *filp)
{
struct hso_serial *serial = tty->driver_data;
u8 usb_gone;
D1("Closing serial port");
if (serial == NULL)
return;
mutex_lock(&serial->parent->mutex);
usb_gone = serial->parent->usb_gone;
if (!usb_gone)
usb_autopm_get_interface(serial->parent->interface);
serial->port.count--;
if (serial->port.count <= 0) {
serial->port.count = 0;
tty_port_tty_set(&serial->port, NULL);
if (!usb_gone)
hso_stop_serial_device(serial->parent);
tasklet_kill(&serial->unthrottle_tasklet);
}
if (!usb_gone)
usb_autopm_put_interface(serial->parent->interface);
mutex_unlock(&serial->parent->mutex);
kref_put(&serial->parent->ref, hso_serial_ref_free);
}
static int hso_serial_write(struct tty_struct *tty, const unsigned char *buf,
int count)
{
struct hso_serial *serial = tty->driver_data;
int space, tx_bytes;
unsigned long flags;
if (serial == NULL) {
printk(KERN_ERR "%s: serial is NULL\n", __func__);
return -ENODEV;
}
spin_lock_irqsave(&serial->serial_lock, flags);
space = serial->tx_data_length - serial->tx_buffer_count;
tx_bytes = (count < space) ? count : space;
if (!tx_bytes)
goto out;
memcpy(serial->tx_buffer + serial->tx_buffer_count, buf, tx_bytes);
serial->tx_buffer_count += tx_bytes;
out:
spin_unlock_irqrestore(&serial->serial_lock, flags);
hso_kick_transmit(serial);
return tx_bytes;
}
static int hso_serial_write_room(struct tty_struct *tty)
{
struct hso_serial *serial = tty->driver_data;
int room;
unsigned long flags;
spin_lock_irqsave(&serial->serial_lock, flags);
room = serial->tx_data_length - serial->tx_buffer_count;
spin_unlock_irqrestore(&serial->serial_lock, flags);
return room;
}
static void hso_serial_set_termios(struct tty_struct *tty, struct ktermios *old)
{
struct hso_serial *serial = tty->driver_data;
unsigned long flags;
if (old)
D5("Termios called with: cflags new[%d] - old[%d]",
tty->termios.c_cflag, old->c_cflag);
spin_lock_irqsave(&serial->serial_lock, flags);
if (serial->port.count)
_hso_serial_set_termios(tty, old);
else
tty->termios = *old;
spin_unlock_irqrestore(&serial->serial_lock, flags);
}
static int hso_serial_chars_in_buffer(struct tty_struct *tty)
{
struct hso_serial *serial = tty->driver_data;
int chars;
unsigned long flags;
if (serial == NULL)
return 0;
spin_lock_irqsave(&serial->serial_lock, flags);
chars = serial->tx_buffer_count;
spin_unlock_irqrestore(&serial->serial_lock, flags);
return chars;
}
static int tiocmget_submit_urb(struct hso_serial *serial,
struct hso_tiocmget *tiocmget,
struct usb_device *usb)
{
int result;
if (serial->parent->usb_gone)
return -ENODEV;
usb_fill_int_urb(tiocmget->urb, usb,
usb_rcvintpipe(usb,
tiocmget->endp->
bEndpointAddress & 0x7F),
&tiocmget->serial_state_notification,
sizeof(struct hso_serial_state_notification),
tiocmget_intr_callback, serial,
tiocmget->endp->bInterval);
result = usb_submit_urb(tiocmget->urb, GFP_ATOMIC);
if (result) {
dev_warn(&usb->dev, "%s usb_submit_urb failed %d\n", __func__,
result);
}
return result;
}
static void tiocmget_intr_callback(struct urb *urb)
{
struct hso_serial *serial = urb->context;
struct hso_tiocmget *tiocmget;
int status = urb->status;
u16 UART_state_bitmap, prev_UART_state_bitmap;
struct uart_icount *icount;
struct hso_serial_state_notification *serial_state_notification;
struct usb_device *usb;
int if_num;
if (!serial)
return;
if (status) {
handle_usb_error(status, __func__, serial->parent);
return;
}
tiocmget = serial->tiocmget;
if (!tiocmget)
return;
BUG_ON((serial->parent->port_spec & HSO_PORT_MASK) != HSO_PORT_MODEM);
usb = serial->parent->usb;
if_num = serial->parent->interface->altsetting->desc.bInterfaceNumber;
serial_state_notification = &tiocmget->serial_state_notification;
if (serial_state_notification->bmRequestType != BM_REQUEST_TYPE ||
serial_state_notification->bNotification != B_NOTIFICATION ||
le16_to_cpu(serial_state_notification->wValue) != W_VALUE ||
le16_to_cpu(serial_state_notification->wIndex) != if_num ||
le16_to_cpu(serial_state_notification->wLength) != W_LENGTH) {
dev_warn(&usb->dev,
"hso received invalid serial state notification\n");
DUMP(serial_state_notification,
sizeof(struct hso_serial_state_notification));
} else {
UART_state_bitmap = le16_to_cpu(serial_state_notification->
UART_state_bitmap);
prev_UART_state_bitmap = tiocmget->prev_UART_state_bitmap;
icount = &tiocmget->icount;
spin_lock(&serial->serial_lock);
if ((UART_state_bitmap & B_OVERRUN) !=
(prev_UART_state_bitmap & B_OVERRUN))
icount->parity++;
if ((UART_state_bitmap & B_PARITY) !=
(prev_UART_state_bitmap & B_PARITY))
icount->parity++;
if ((UART_state_bitmap & B_FRAMING) !=
(prev_UART_state_bitmap & B_FRAMING))
icount->frame++;
if ((UART_state_bitmap & B_RING_SIGNAL) &&
!(prev_UART_state_bitmap & B_RING_SIGNAL))
icount->rng++;
if ((UART_state_bitmap & B_BREAK) !=
(prev_UART_state_bitmap & B_BREAK))
icount->brk++;
if ((UART_state_bitmap & B_TX_CARRIER) !=
(prev_UART_state_bitmap & B_TX_CARRIER))
icount->dsr++;
if ((UART_state_bitmap & B_RX_CARRIER) !=
(prev_UART_state_bitmap & B_RX_CARRIER))
icount->dcd++;
tiocmget->prev_UART_state_bitmap = UART_state_bitmap;
spin_unlock(&serial->serial_lock);
tiocmget->intr_completed = 1;
wake_up_interruptible(&tiocmget->waitq);
}
memset(serial_state_notification, 0,
sizeof(struct hso_serial_state_notification));
tiocmget_submit_urb(serial,
tiocmget,
serial->parent->usb);
}
static int
hso_wait_modem_status(struct hso_serial *serial, unsigned long arg)
{
DECLARE_WAITQUEUE(wait, current);
struct uart_icount cprev, cnow;
struct hso_tiocmget *tiocmget;
int ret;
tiocmget = serial->tiocmget;
if (!tiocmget)
return -ENOENT;
spin_lock_irq(&serial->serial_lock);
memcpy(&cprev, &tiocmget->icount, sizeof(struct uart_icount));
spin_unlock_irq(&serial->serial_lock);
add_wait_queue(&tiocmget->waitq, &wait);
for (;;) {
spin_lock_irq(&serial->serial_lock);
memcpy(&cnow, &tiocmget->icount, sizeof(struct uart_icount));
spin_unlock_irq(&serial->serial_lock);
set_current_state(TASK_INTERRUPTIBLE);
if (((arg & TIOCM_RNG) && (cnow.rng != cprev.rng)) ||
((arg & TIOCM_DSR) && (cnow.dsr != cprev.dsr)) ||
((arg & TIOCM_CD) && (cnow.dcd != cprev.dcd))) {
ret = 0;
break;
}
schedule();
if (signal_pending(current)) {
ret = -ERESTARTSYS;
break;
}
cprev = cnow;
}
current->state = TASK_RUNNING;
remove_wait_queue(&tiocmget->waitq, &wait);
return ret;
}
static int hso_get_count(struct tty_struct *tty,
struct serial_icounter_struct *icount)
{
struct uart_icount cnow;
struct hso_serial *serial = tty->driver_data;
struct hso_tiocmget *tiocmget = serial->tiocmget;
memset(icount, 0, sizeof(struct serial_icounter_struct));
if (!tiocmget)
return -ENOENT;
spin_lock_irq(&serial->serial_lock);
memcpy(&cnow, &tiocmget->icount, sizeof(struct uart_icount));
spin_unlock_irq(&serial->serial_lock);
icount->cts = cnow.cts;
icount->dsr = cnow.dsr;
icount->rng = cnow.rng;
icount->dcd = cnow.dcd;
icount->rx = cnow.rx;
icount->tx = cnow.tx;
icount->frame = cnow.frame;
icount->overrun = cnow.overrun;
icount->parity = cnow.parity;
icount->brk = cnow.brk;
icount->buf_overrun = cnow.buf_overrun;
return 0;
}
static int hso_serial_tiocmget(struct tty_struct *tty)
{
int retval;
struct hso_serial *serial = tty->driver_data;
struct hso_tiocmget *tiocmget;
u16 UART_state_bitmap;
if (!serial) {
D1("no tty structures");
return -EINVAL;
}
spin_lock_irq(&serial->serial_lock);
retval = ((serial->rts_state) ? TIOCM_RTS : 0) |
((serial->dtr_state) ? TIOCM_DTR : 0);
tiocmget = serial->tiocmget;
if (tiocmget) {
UART_state_bitmap = le16_to_cpu(
tiocmget->prev_UART_state_bitmap);
if (UART_state_bitmap & B_RING_SIGNAL)
retval |= TIOCM_RNG;
if (UART_state_bitmap & B_RX_CARRIER)
retval |= TIOCM_CD;
if (UART_state_bitmap & B_TX_CARRIER)
retval |= TIOCM_DSR;
}
spin_unlock_irq(&serial->serial_lock);
return retval;
}
static int hso_serial_tiocmset(struct tty_struct *tty,
unsigned int set, unsigned int clear)
{
int val = 0;
unsigned long flags;
int if_num;
struct hso_serial *serial = tty->driver_data;
if (!serial) {
D1("no tty structures");
return -EINVAL;
}
if ((serial->parent->port_spec & HSO_PORT_MASK) != HSO_PORT_MODEM)
return -EINVAL;
if_num = serial->parent->interface->altsetting->desc.bInterfaceNumber;
spin_lock_irqsave(&serial->serial_lock, flags);
if (set & TIOCM_RTS)
serial->rts_state = 1;
if (set & TIOCM_DTR)
serial->dtr_state = 1;
if (clear & TIOCM_RTS)
serial->rts_state = 0;
if (clear & TIOCM_DTR)
serial->dtr_state = 0;
if (serial->dtr_state)
val |= 0x01;
if (serial->rts_state)
val |= 0x02;
spin_unlock_irqrestore(&serial->serial_lock, flags);
return usb_control_msg(serial->parent->usb,
usb_rcvctrlpipe(serial->parent->usb, 0), 0x22,
0x21, val, if_num, NULL, 0,
USB_CTRL_SET_TIMEOUT);
}
static int hso_serial_ioctl(struct tty_struct *tty,
unsigned int cmd, unsigned long arg)
{
struct hso_serial *serial = tty->driver_data;
int ret = 0;
D4("IOCTL cmd: %d, arg: %ld", cmd, arg);
if (!serial)
return -ENODEV;
switch (cmd) {
case TIOCMIWAIT:
ret = hso_wait_modem_status(serial, arg);
break;
default:
ret = -ENOIOCTLCMD;
break;
}
return ret;
}
static void hso_kick_transmit(struct hso_serial *serial)
{
u8 *temp;
unsigned long flags;
int res;
spin_lock_irqsave(&serial->serial_lock, flags);
if (!serial->tx_buffer_count)
goto out;
if (serial->tx_urb_used)
goto out;
if (hso_get_activity(serial->parent) == -EAGAIN)
goto out;
temp = serial->tx_buffer;
serial->tx_buffer = serial->tx_data;
serial->tx_data = temp;
serial->tx_data_count = serial->tx_buffer_count;
serial->tx_buffer_count = 0;
if (temp && serial->write_data) {
res = serial->write_data(serial);
if (res >= 0)
serial->tx_urb_used = 1;
}
out:
spin_unlock_irqrestore(&serial->serial_lock, flags);
}
static int mux_device_request(struct hso_serial *serial, u8 type, u16 port,
struct urb *ctrl_urb,
struct usb_ctrlrequest *ctrl_req,
u8 *ctrl_urb_data, u32 size)
{
int result;
int pipe;
if (!serial || !ctrl_urb || !ctrl_req) {
printk(KERN_ERR "%s: Wrong arguments\n", __func__);
return -EINVAL;
}
ctrl_req->wValue = 0;
ctrl_req->wIndex = cpu_to_le16(hso_port_to_mux(port));
ctrl_req->wLength = cpu_to_le16(size);
if (type == USB_CDC_GET_ENCAPSULATED_RESPONSE) {
ctrl_req->bRequestType = USB_DIR_IN |
USB_TYPE_OPTION_VENDOR |
USB_RECIP_INTERFACE;
ctrl_req->bRequest = USB_CDC_GET_ENCAPSULATED_RESPONSE;
pipe = usb_rcvctrlpipe(serial->parent->usb, 0);
} else {
ctrl_req->bRequestType = USB_DIR_OUT |
USB_TYPE_OPTION_VENDOR |
USB_RECIP_INTERFACE;
ctrl_req->bRequest = USB_CDC_SEND_ENCAPSULATED_COMMAND;
pipe = usb_sndctrlpipe(serial->parent->usb, 0);
}
D2("%s command (%02x) len: %d, port: %d",
type == USB_CDC_GET_ENCAPSULATED_RESPONSE ? "Read" : "Write",
ctrl_req->bRequestType, ctrl_req->wLength, port);
ctrl_urb->transfer_flags = 0;
usb_fill_control_urb(ctrl_urb,
serial->parent->usb,
pipe,
(u8 *) ctrl_req,
ctrl_urb_data, size, ctrl_callback, serial);
result = usb_submit_urb(ctrl_urb, GFP_ATOMIC);
if (result) {
dev_err(&ctrl_urb->dev->dev,
"%s failed submit ctrl_urb %d type %d\n", __func__,
result, type);
return result;
}
return size;
}
static int hso_mux_serial_read(struct hso_serial *serial)
{
if (!serial)
return -EINVAL;
memset(serial->rx_data[0], 0, CTRL_URB_RX_SIZE);
if (serial->num_rx_urbs != 1) {
dev_err(&serial->parent->interface->dev,
"ERROR: mux'd reads with multiple buffers "
"not possible\n");
return 0;
}
return mux_device_request(serial,
USB_CDC_GET_ENCAPSULATED_RESPONSE,
serial->parent->port_spec & HSO_PORT_MASK,
serial->rx_urb[0],
&serial->ctrl_req_rx,
serial->rx_data[0], serial->rx_data_length);
}
static void intr_callback(struct urb *urb)
{
struct hso_shared_int *shared_int = urb->context;
struct hso_serial *serial;
unsigned char *port_req;
int status = urb->status;
int i;
usb_mark_last_busy(urb->dev);
if (!shared_int)
return;
if (status) {
handle_usb_error(status, __func__, NULL);
return;
}
D4("\n--- Got intr callback 0x%02X ---", status);
port_req = urb->transfer_buffer;
D4(" port_req = 0x%.2X\n", *port_req);
for (i = 0; i < 8; i++) {
if (*port_req & (1 << i)) {
serial = get_serial_by_shared_int_and_type(shared_int,
(1 << i));
if (serial != NULL) {
D1("Pending read interrupt on port %d\n", i);
spin_lock(&serial->serial_lock);
if (serial->rx_state == RX_IDLE &&
serial->port.count > 0) {
if (!serial->rx_urb_filled[0]) {
serial->rx_state = RX_SENT;
hso_mux_serial_read(serial);
} else
serial->rx_state = RX_PENDING;
} else {
D1("Already a read pending on "
"port %d or port not open\n", i);
}
spin_unlock(&serial->serial_lock);
}
}
}
hso_mux_submit_intr_urb(shared_int, urb->dev, GFP_ATOMIC);
}
static int hso_mux_serial_write_data(struct hso_serial *serial)
{
if (NULL == serial)
return -EINVAL;
return mux_device_request(serial,
USB_CDC_SEND_ENCAPSULATED_COMMAND,
serial->parent->port_spec & HSO_PORT_MASK,
serial->tx_urb,
&serial->ctrl_req_tx,
serial->tx_data, serial->tx_data_count);
}
static void hso_std_serial_write_bulk_callback(struct urb *urb)
{
struct hso_serial *serial = urb->context;
int status = urb->status;
if (!serial) {
D1("serial == NULL");
return;
}
spin_lock(&serial->serial_lock);
serial->tx_urb_used = 0;
spin_unlock(&serial->serial_lock);
if (status) {
handle_usb_error(status, __func__, serial->parent);
return;
}
hso_put_activity(serial->parent);
tty_port_tty_wakeup(&serial->port);
hso_kick_transmit(serial);
D1(" ");
}
static int hso_std_serial_write_data(struct hso_serial *serial)
{
int count = serial->tx_data_count;
int result;
usb_fill_bulk_urb(serial->tx_urb,
serial->parent->usb,
usb_sndbulkpipe(serial->parent->usb,
serial->out_endp->
bEndpointAddress & 0x7F),
serial->tx_data, serial->tx_data_count,
hso_std_serial_write_bulk_callback, serial);
result = usb_submit_urb(serial->tx_urb, GFP_ATOMIC);
if (result) {
dev_warn(&serial->parent->usb->dev,
"Failed to submit urb - res %d\n", result);
return result;
}
return count;
}
static void ctrl_callback(struct urb *urb)
{
struct hso_serial *serial = urb->context;
struct usb_ctrlrequest *req;
int status = urb->status;
if (!serial)
return;
spin_lock(&serial->serial_lock);
serial->tx_urb_used = 0;
spin_unlock(&serial->serial_lock);
if (status) {
handle_usb_error(status, __func__, serial->parent);
return;
}
req = (struct usb_ctrlrequest *)(urb->setup_packet);
D4("\n--- Got muxed ctrl callback 0x%02X ---", status);
D4("Actual length of urb = %d\n", urb->actual_length);
DUMP1(urb->transfer_buffer, urb->actual_length);
if (req->bRequestType ==
(USB_DIR_IN | USB_TYPE_OPTION_VENDOR | USB_RECIP_INTERFACE)) {
serial->rx_urb_filled[0] = 1;
spin_lock(&serial->serial_lock);
put_rxbuf_data_and_resubmit_ctrl_urb(serial);
spin_unlock(&serial->serial_lock);
} else {
hso_put_activity(serial->parent);
tty_port_tty_wakeup(&serial->port);
hso_kick_transmit(serial);
}
}
static int put_rxbuf_data(struct urb *urb, struct hso_serial *serial)
{
struct tty_struct *tty;
int count;
if (urb == NULL || serial == NULL) {
D1("serial = NULL");
return -2;
}
tty = tty_port_tty_get(&serial->port);
if (tty && test_bit(TTY_THROTTLED, &tty->flags)) {
tty_kref_put(tty);
return -1;
}
D1("data to push to tty");
count = tty_buffer_request_room(&serial->port, urb->actual_length);
if (count >= urb->actual_length) {
tty_insert_flip_string(&serial->port, urb->transfer_buffer,
urb->actual_length);
tty_flip_buffer_push(&serial->port);
} else {
dev_warn(&serial->parent->usb->dev,
"dropping data, %d bytes lost\n", urb->actual_length);
}
tty_kref_put(tty);
serial->rx_urb_filled[hso_urb_to_index(serial, urb)] = 0;
return 0;
}
static void hso_log_port(struct hso_device *hso_dev)
{
char *port_type;
char port_dev[20];
switch (hso_dev->port_spec & HSO_PORT_MASK) {
case HSO_PORT_CONTROL:
port_type = "Control";
break;
case HSO_PORT_APP:
port_type = "Application";
break;
case HSO_PORT_GPS:
port_type = "GPS";
break;
case HSO_PORT_GPS_CONTROL:
port_type = "GPS control";
break;
case HSO_PORT_APP2:
port_type = "Application2";
break;
case HSO_PORT_PCSC:
port_type = "PCSC";
break;
case HSO_PORT_DIAG:
port_type = "Diagnostic";
break;
case HSO_PORT_DIAG2:
port_type = "Diagnostic2";
break;
case HSO_PORT_MODEM:
port_type = "Modem";
break;
case HSO_PORT_NETWORK:
port_type = "Network";
break;
default:
port_type = "Unknown";
break;
}
if ((hso_dev->port_spec & HSO_PORT_MASK) == HSO_PORT_NETWORK) {
sprintf(port_dev, "%s", dev2net(hso_dev)->net->name);
} else
sprintf(port_dev, "/dev/%s%d", tty_filename,
dev2ser(hso_dev)->minor);
dev_dbg(&hso_dev->interface->dev, "HSO: Found %s port %s\n",
port_type, port_dev);
}
static int hso_start_net_device(struct hso_device *hso_dev)
{
int i, result = 0;
struct hso_net *hso_net = dev2net(hso_dev);
if (!hso_net)
return -ENODEV;
for (i = 0; i < MUX_BULK_RX_BUF_COUNT; i++) {
usb_fill_bulk_urb(hso_net->mux_bulk_rx_urb_pool[i],
hso_dev->usb,
usb_rcvbulkpipe(hso_dev->usb,
hso_net->in_endp->
bEndpointAddress & 0x7F),
hso_net->mux_bulk_rx_buf_pool[i],
MUX_BULK_RX_BUF_SIZE, read_bulk_callback,
hso_net);
result = usb_submit_urb(hso_net->mux_bulk_rx_urb_pool[i],
GFP_NOIO);
if (result)
dev_warn(&hso_dev->usb->dev,
"%s failed mux_bulk_rx_urb[%d] %d\n", __func__,
i, result);
}
return result;
}
static int hso_stop_net_device(struct hso_device *hso_dev)
{
int i;
struct hso_net *hso_net = dev2net(hso_dev);
if (!hso_net)
return -ENODEV;
for (i = 0; i < MUX_BULK_RX_BUF_COUNT; i++) {
if (hso_net->mux_bulk_rx_urb_pool[i])
usb_kill_urb(hso_net->mux_bulk_rx_urb_pool[i]);
}
if (hso_net->mux_bulk_tx_urb)
usb_kill_urb(hso_net->mux_bulk_tx_urb);
return 0;
}
static int hso_start_serial_device(struct hso_device *hso_dev, gfp_t flags)
{
int i, result = 0;
struct hso_serial *serial = dev2ser(hso_dev);
if (!serial)
return -ENODEV;
if (!(serial->parent->port_spec & HSO_INTF_MUX)) {
for (i = 0; i < serial->num_rx_urbs; i++) {
usb_fill_bulk_urb(serial->rx_urb[i],
serial->parent->usb,
usb_rcvbulkpipe(serial->parent->usb,
serial->in_endp->
bEndpointAddress &
0x7F),
serial->rx_data[i],
serial->rx_data_length,
hso_std_serial_read_bulk_callback,
serial);
result = usb_submit_urb(serial->rx_urb[i], flags);
if (result) {
dev_warn(&serial->parent->usb->dev,
"Failed to submit urb - res %d\n",
result);
break;
}
}
} else {
mutex_lock(&serial->shared_int->shared_int_lock);
if (!serial->shared_int->use_count) {
result =
hso_mux_submit_intr_urb(serial->shared_int,
hso_dev->usb, flags);
}
serial->shared_int->use_count++;
mutex_unlock(&serial->shared_int->shared_int_lock);
}
if (serial->tiocmget)
tiocmget_submit_urb(serial,
serial->tiocmget,
serial->parent->usb);
return result;
}
static int hso_stop_serial_device(struct hso_device *hso_dev)
{
int i;
struct hso_serial *serial = dev2ser(hso_dev);
struct hso_tiocmget *tiocmget;
if (!serial)
return -ENODEV;
for (i = 0; i < serial->num_rx_urbs; i++) {
if (serial->rx_urb[i]) {
usb_kill_urb(serial->rx_urb[i]);
serial->rx_urb_filled[i] = 0;
}
}
serial->curr_rx_urb_idx = 0;
if (serial->tx_urb)
usb_kill_urb(serial->tx_urb);
if (serial->shared_int) {
mutex_lock(&serial->shared_int->shared_int_lock);
if (serial->shared_int->use_count &&
(--serial->shared_int->use_count == 0)) {
struct urb *urb;
urb = serial->shared_int->shared_intr_urb;
if (urb)
usb_kill_urb(urb);
}
mutex_unlock(&serial->shared_int->shared_int_lock);
}
tiocmget = serial->tiocmget;
if (tiocmget) {
wake_up_interruptible(&tiocmget->waitq);
usb_kill_urb(tiocmget->urb);
}
return 0;
}
static void hso_serial_common_free(struct hso_serial *serial)
{
int i;
if (serial->parent->dev)
device_remove_file(serial->parent->dev, &dev_attr_hsotype);
tty_unregister_device(tty_drv, serial->minor);
for (i = 0; i < serial->num_rx_urbs; i++) {
usb_free_urb(serial->rx_urb[i]);
kfree(serial->rx_data[i]);
}
usb_free_urb(serial->tx_urb);
kfree(serial->tx_data);
tty_port_destroy(&serial->port);
}
static int hso_serial_common_create(struct hso_serial *serial, int num_urbs,
int rx_size, int tx_size)
{
struct device *dev;
int minor;
int i;
tty_port_init(&serial->port);
minor = get_free_serial_index();
if (minor < 0)
goto exit;
serial->parent->dev = tty_port_register_device(&serial->port, tty_drv,
minor, &serial->parent->interface->dev);
dev = serial->parent->dev;
dev_set_drvdata(dev, serial->parent);
i = device_create_file(dev, &dev_attr_hsotype);
serial->minor = minor;
serial->magic = HSO_SERIAL_MAGIC;
spin_lock_init(&serial->serial_lock);
serial->num_rx_urbs = num_urbs;
serial->rx_data_length = rx_size;
for (i = 0; i < serial->num_rx_urbs; i++) {
serial->rx_urb[i] = usb_alloc_urb(0, GFP_KERNEL);
if (!serial->rx_urb[i]) {
dev_err(dev, "Could not allocate urb?\n");
goto exit;
}
serial->rx_urb[i]->transfer_buffer = NULL;
serial->rx_urb[i]->transfer_buffer_length = 0;
serial->rx_data[i] = kzalloc(serial->rx_data_length,
GFP_KERNEL);
if (!serial->rx_data[i])
goto exit;
}
serial->tx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!serial->tx_urb) {
dev_err(dev, "Could not allocate urb?\n");
goto exit;
}
serial->tx_urb->transfer_buffer = NULL;
serial->tx_urb->transfer_buffer_length = 0;
serial->tx_data_count = 0;
serial->tx_buffer_count = 0;
serial->tx_data_length = tx_size;
serial->tx_data = kzalloc(serial->tx_data_length, GFP_KERNEL);
if (!serial->tx_data)
goto exit;
serial->tx_buffer = kzalloc(serial->tx_data_length, GFP_KERNEL);
if (!serial->tx_buffer)
goto exit;
return 0;
exit:
hso_serial_common_free(serial);
return -1;
}
static struct hso_device *hso_create_device(struct usb_interface *intf,
int port_spec)
{
struct hso_device *hso_dev;
hso_dev = kzalloc(sizeof(*hso_dev), GFP_ATOMIC);
if (!hso_dev)
return NULL;
hso_dev->port_spec = port_spec;
hso_dev->usb = interface_to_usbdev(intf);
hso_dev->interface = intf;
kref_init(&hso_dev->ref);
mutex_init(&hso_dev->mutex);
INIT_WORK(&hso_dev->async_get_intf, async_get_intf);
INIT_WORK(&hso_dev->async_put_intf, async_put_intf);
INIT_WORK(&hso_dev->reset_device, reset_device);
return hso_dev;
}
static int remove_net_device(struct hso_device *hso_dev)
{
int i;
for (i = 0; i < HSO_MAX_NET_DEVICES; i++) {
if (network_table[i] == hso_dev) {
network_table[i] = NULL;
break;
}
}
if (i == HSO_MAX_NET_DEVICES)
return -1;
return 0;
}
static void hso_free_net_device(struct hso_device *hso_dev)
{
int i;
struct hso_net *hso_net = dev2net(hso_dev);
if (!hso_net)
return;
remove_net_device(hso_net->parent);
if (hso_net->net)
unregister_netdev(hso_net->net);
for (i = 0; i < MUX_BULK_RX_BUF_COUNT; i++) {
usb_free_urb(hso_net->mux_bulk_rx_urb_pool[i]);
kfree(hso_net->mux_bulk_rx_buf_pool[i]);
hso_net->mux_bulk_rx_buf_pool[i] = NULL;
}
usb_free_urb(hso_net->mux_bulk_tx_urb);
kfree(hso_net->mux_bulk_tx_buf);
hso_net->mux_bulk_tx_buf = NULL;
if (hso_net->net)
free_netdev(hso_net->net);
kfree(hso_dev);
}
static void hso_net_init(struct net_device *net)
{
struct hso_net *hso_net = netdev_priv(net);
D1("sizeof hso_net is %d", (int)sizeof(*hso_net));
net->netdev_ops = &hso_netdev_ops;
net->watchdog_timeo = HSO_NET_TX_TIMEOUT;
net->flags = IFF_POINTOPOINT | IFF_NOARP | IFF_MULTICAST;
net->type = ARPHRD_NONE;
net->mtu = DEFAULT_MTU - 14;
net->tx_queue_len = 10;
net->ethtool_ops = &ops;
spin_lock_init(&hso_net->net_lock);
}
static int add_net_device(struct hso_device *hso_dev)
{
int i;
for (i = 0; i < HSO_MAX_NET_DEVICES; i++) {
if (network_table[i] == NULL) {
network_table[i] = hso_dev;
break;
}
}
if (i == HSO_MAX_NET_DEVICES)
return -1;
return 0;
}
static int hso_rfkill_set_block(void *data, bool blocked)
{
struct hso_device *hso_dev = data;
int enabled = !blocked;
int rv;
mutex_lock(&hso_dev->mutex);
if (hso_dev->usb_gone)
rv = 0;
else
rv = usb_control_msg(hso_dev->usb, usb_rcvctrlpipe(hso_dev->usb, 0),
enabled ? 0x82 : 0x81, 0x40, 0, 0, NULL, 0,
USB_CTRL_SET_TIMEOUT);
mutex_unlock(&hso_dev->mutex);
return rv;
}
static void hso_create_rfkill(struct hso_device *hso_dev,
struct usb_interface *interface)
{
struct hso_net *hso_net = dev2net(hso_dev);
struct device *dev = &hso_net->net->dev;
char *rfkn;
rfkn = kzalloc(20, GFP_KERNEL);
if (!rfkn)
dev_err(dev, "%s - Out of memory\n", __func__);
snprintf(rfkn, 20, "hso-%d",
interface->altsetting->desc.bInterfaceNumber);
hso_net->rfkill = rfkill_alloc(rfkn,
&interface_to_usbdev(interface)->dev,
RFKILL_TYPE_WWAN,
&hso_rfkill_ops, hso_dev);
if (!hso_net->rfkill) {
dev_err(dev, "%s - Out of memory\n", __func__);
kfree(rfkn);
return;
}
if (rfkill_register(hso_net->rfkill) < 0) {
rfkill_destroy(hso_net->rfkill);
kfree(rfkn);
hso_net->rfkill = NULL;
dev_err(dev, "%s - Failed to register rfkill\n", __func__);
return;
}
}
static struct hso_device *hso_create_net_device(struct usb_interface *interface,
int port_spec)
{
int result, i;
struct net_device *net;
struct hso_net *hso_net;
struct hso_device *hso_dev;
hso_dev = hso_create_device(interface, port_spec);
if (!hso_dev)
return NULL;
net = alloc_netdev(sizeof(struct hso_net), "hso%d", NET_NAME_UNKNOWN,
hso_net_init);
if (!net) {
dev_err(&interface->dev, "Unable to create ethernet device\n");
goto exit;
}
hso_net = netdev_priv(net);
hso_dev->port_data.dev_net = hso_net;
hso_net->net = net;
hso_net->parent = hso_dev;
hso_net->in_endp = hso_get_ep(interface, USB_ENDPOINT_XFER_BULK,
USB_DIR_IN);
if (!hso_net->in_endp) {
dev_err(&interface->dev, "Can't find BULK IN endpoint\n");
goto exit;
}
hso_net->out_endp = hso_get_ep(interface, USB_ENDPOINT_XFER_BULK,
USB_DIR_OUT);
if (!hso_net->out_endp) {
dev_err(&interface->dev, "Can't find BULK OUT endpoint\n");
goto exit;
}
SET_NETDEV_DEV(net, &interface->dev);
SET_NETDEV_DEVTYPE(net, &hso_type);
result = register_netdev(net);
if (result) {
dev_err(&interface->dev, "Failed to register device\n");
goto exit;
}
for (i = 0; i < MUX_BULK_RX_BUF_COUNT; i++) {
hso_net->mux_bulk_rx_urb_pool[i] = usb_alloc_urb(0, GFP_KERNEL);
if (!hso_net->mux_bulk_rx_urb_pool[i]) {
dev_err(&interface->dev, "Could not allocate rx urb\n");
goto exit;
}
hso_net->mux_bulk_rx_buf_pool[i] = kzalloc(MUX_BULK_RX_BUF_SIZE,
GFP_KERNEL);
if (!hso_net->mux_bulk_rx_buf_pool[i])
goto exit;
}
hso_net->mux_bulk_tx_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!hso_net->mux_bulk_tx_urb) {
dev_err(&interface->dev, "Could not allocate tx urb\n");
goto exit;
}
hso_net->mux_bulk_tx_buf = kzalloc(MUX_BULK_TX_BUF_SIZE, GFP_KERNEL);
if (!hso_net->mux_bulk_tx_buf)
goto exit;
add_net_device(hso_dev);
hso_log_port(hso_dev);
hso_create_rfkill(hso_dev, interface);
return hso_dev;
exit:
hso_free_net_device(hso_dev);
return NULL;
}
static void hso_free_tiomget(struct hso_serial *serial)
{
struct hso_tiocmget *tiocmget;
if (!serial)
return;
tiocmget = serial->tiocmget;
if (tiocmget) {
usb_free_urb(tiocmget->urb);
tiocmget->urb = NULL;
serial->tiocmget = NULL;
kfree(tiocmget);
}
}
static void hso_free_serial_device(struct hso_device *hso_dev)
{
struct hso_serial *serial = dev2ser(hso_dev);
if (!serial)
return;
set_serial_by_index(serial->minor, NULL);
hso_serial_common_free(serial);
if (serial->shared_int) {
mutex_lock(&serial->shared_int->shared_int_lock);
if (--serial->shared_int->ref_count == 0)
hso_free_shared_int(serial->shared_int);
else
mutex_unlock(&serial->shared_int->shared_int_lock);
}
hso_free_tiomget(serial);
kfree(serial);
kfree(hso_dev);
}
static struct hso_device *hso_create_bulk_serial_device(
struct usb_interface *interface, int port)
{
struct hso_device *hso_dev;
struct hso_serial *serial;
int num_urbs;
struct hso_tiocmget *tiocmget;
hso_dev = hso_create_device(interface, port);
if (!hso_dev)
return NULL;
serial = kzalloc(sizeof(*serial), GFP_KERNEL);
if (!serial)
goto exit;
serial->parent = hso_dev;
hso_dev->port_data.dev_serial = serial;
if ((port & HSO_PORT_MASK) == HSO_PORT_MODEM) {
num_urbs = 2;
serial->tiocmget = kzalloc(sizeof(struct hso_tiocmget),
GFP_KERNEL);
if (serial->tiocmget) {
tiocmget = serial->tiocmget;
tiocmget->urb = usb_alloc_urb(0, GFP_KERNEL);
if (tiocmget->urb) {
mutex_init(&tiocmget->mutex);
init_waitqueue_head(&tiocmget->waitq);
tiocmget->endp = hso_get_ep(
interface,
USB_ENDPOINT_XFER_INT,
USB_DIR_IN);
} else
hso_free_tiomget(serial);
}
}
else
num_urbs = 1;
if (hso_serial_common_create(serial, num_urbs, BULK_URB_RX_SIZE,
BULK_URB_TX_SIZE))
goto exit;
serial->in_endp = hso_get_ep(interface, USB_ENDPOINT_XFER_BULK,
USB_DIR_IN);
if (!serial->in_endp) {
dev_err(&interface->dev, "Failed to find BULK IN ep\n");
goto exit2;
}
if (!
(serial->out_endp =
hso_get_ep(interface, USB_ENDPOINT_XFER_BULK, USB_DIR_OUT))) {
dev_err(&interface->dev, "Failed to find BULK IN ep\n");
goto exit2;
}
serial->write_data = hso_std_serial_write_data;
set_serial_by_index(serial->minor, serial);
hso_log_port(hso_dev);
return hso_dev;
exit2:
hso_serial_common_free(serial);
exit:
hso_free_tiomget(serial);
kfree(serial);
kfree(hso_dev);
return NULL;
}
static
struct hso_device *hso_create_mux_serial_device(struct usb_interface *interface,
int port,
struct hso_shared_int *mux)
{
struct hso_device *hso_dev;
struct hso_serial *serial;
int port_spec;
port_spec = HSO_INTF_MUX;
port_spec &= ~HSO_PORT_MASK;
port_spec |= hso_mux_to_port(port);
if ((port_spec & HSO_PORT_MASK) == HSO_PORT_NO_PORT)
return NULL;
hso_dev = hso_create_device(interface, port_spec);
if (!hso_dev)
return NULL;
serial = kzalloc(sizeof(*serial), GFP_KERNEL);
if (!serial)
goto exit;
hso_dev->port_data.dev_serial = serial;
serial->parent = hso_dev;
if (hso_serial_common_create
(serial, 1, CTRL_URB_RX_SIZE, CTRL_URB_TX_SIZE))
goto exit;
serial->tx_data_length--;
serial->write_data = hso_mux_serial_write_data;
serial->shared_int = mux;
mutex_lock(&serial->shared_int->shared_int_lock);
serial->shared_int->ref_count++;
mutex_unlock(&serial->shared_int->shared_int_lock);
set_serial_by_index(serial->minor, serial);
hso_log_port(hso_dev);
return hso_dev;
exit:
if (serial) {
tty_unregister_device(tty_drv, serial->minor);
kfree(serial);
}
if (hso_dev)
kfree(hso_dev);
return NULL;
}
static void hso_free_shared_int(struct hso_shared_int *mux)
{
usb_free_urb(mux->shared_intr_urb);
kfree(mux->shared_intr_buf);
mutex_unlock(&mux->shared_int_lock);
kfree(mux);
}
static
struct hso_shared_int *hso_create_shared_int(struct usb_interface *interface)
{
struct hso_shared_int *mux = kzalloc(sizeof(*mux), GFP_KERNEL);
if (!mux)
return NULL;
mux->intr_endp = hso_get_ep(interface, USB_ENDPOINT_XFER_INT,
USB_DIR_IN);
if (!mux->intr_endp) {
dev_err(&interface->dev, "Can't find INT IN endpoint\n");
goto exit;
}
mux->shared_intr_urb = usb_alloc_urb(0, GFP_KERNEL);
if (!mux->shared_intr_urb) {
dev_err(&interface->dev, "Could not allocate intr urb?\n");
goto exit;
}
mux->shared_intr_buf =
kzalloc(le16_to_cpu(mux->intr_endp->wMaxPacketSize),
GFP_KERNEL);
if (!mux->shared_intr_buf)
goto exit;
mutex_init(&mux->shared_int_lock);
return mux;
exit:
kfree(mux->shared_intr_buf);
usb_free_urb(mux->shared_intr_urb);
kfree(mux);
return NULL;
}
static int hso_get_config_data(struct usb_interface *interface)
{
struct usb_device *usbdev = interface_to_usbdev(interface);
u8 *config_data = kmalloc(17, GFP_KERNEL);
u32 if_num = interface->altsetting->desc.bInterfaceNumber;
s32 result;
if (!config_data)
return -ENOMEM;
if (usb_control_msg(usbdev, usb_rcvctrlpipe(usbdev, 0),
0x86, 0xC0, 0, 0, config_data, 17,
USB_CTRL_SET_TIMEOUT) != 0x11) {
kfree(config_data);
return -EIO;
}
switch (config_data[if_num]) {
case 0x0:
result = 0;
break;
case 0x1:
result = HSO_PORT_DIAG;
break;
case 0x2:
result = HSO_PORT_GPS;
break;
case 0x3:
result = HSO_PORT_GPS_CONTROL;
break;
case 0x4:
result = HSO_PORT_APP;
break;
case 0x5:
result = HSO_PORT_APP2;
break;
case 0x6:
result = HSO_PORT_CONTROL;
break;
case 0x7:
result = HSO_PORT_NETWORK;
break;
case 0x8:
result = HSO_PORT_MODEM;
break;
case 0x9:
result = HSO_PORT_MSD;
break;
case 0xa:
result = HSO_PORT_PCSC;
break;
case 0xb:
result = HSO_PORT_VOICE;
break;
default:
result = 0;
}
if (result)
result |= HSO_INTF_BULK;
if (config_data[16] & 0x1)
result |= HSO_INFO_CRC_BUG;
kfree(config_data);
return result;
}
static int hso_probe(struct usb_interface *interface,
const struct usb_device_id *id)
{
int mux, i, if_num, port_spec;
unsigned char port_mask;
struct hso_device *hso_dev = NULL;
struct hso_shared_int *shared_int;
struct hso_device *tmp_dev = NULL;
if (interface->cur_altsetting->desc.bInterfaceClass != 0xFF) {
dev_err(&interface->dev, "Not our interface\n");
return -ENODEV;
}
if_num = interface->altsetting->desc.bInterfaceNumber;
if (id->driver_info)
port_spec = ((u32 *)(id->driver_info))[if_num];
else
port_spec = hso_get_config_data(interface);
if (interface->num_altsetting > 1)
usb_set_interface(interface_to_usbdev(interface), if_num, 1);
interface->needs_remote_wakeup = 1;
switch (port_spec & HSO_INTF_MASK) {
case HSO_INTF_MUX:
if ((port_spec & HSO_PORT_MASK) == HSO_PORT_NETWORK) {
if (!disable_net) {
hso_dev = hso_create_net_device(interface,
port_spec);
if (!hso_dev)
goto exit;
tmp_dev = hso_dev;
}
}
if (hso_get_mux_ports(interface, &port_mask))
goto exit;
shared_int = hso_create_shared_int(interface);
if (!shared_int)
goto exit;
for (i = 1, mux = 0; i < 0x100; i = i << 1, mux++) {
if (port_mask & i) {
hso_dev = hso_create_mux_serial_device(
interface, i, shared_int);
if (!hso_dev)
goto exit;
}
}
if (tmp_dev)
hso_dev = tmp_dev;
break;
case HSO_INTF_BULK:
if ((port_spec & HSO_PORT_MASK) == HSO_PORT_NETWORK) {
if (!disable_net)
hso_dev =
hso_create_net_device(interface, port_spec);
} else {
hso_dev =
hso_create_bulk_serial_device(interface, port_spec);
}
if (!hso_dev)
goto exit;
break;
default:
goto exit;
}
usb_set_intfdata(interface, hso_dev);
return 0;
exit:
hso_free_interface(interface);
return -ENODEV;
}
static void hso_disconnect(struct usb_interface *interface)
{
hso_free_interface(interface);
usb_set_intfdata(interface, NULL);
}
static void async_get_intf(struct work_struct *data)
{
struct hso_device *hso_dev =
container_of(data, struct hso_device, async_get_intf);
usb_autopm_get_interface(hso_dev->interface);
}
static void async_put_intf(struct work_struct *data)
{
struct hso_device *hso_dev =
container_of(data, struct hso_device, async_put_intf);
usb_autopm_put_interface(hso_dev->interface);
}
static int hso_get_activity(struct hso_device *hso_dev)
{
if (hso_dev->usb->state == USB_STATE_SUSPENDED) {
if (!hso_dev->is_active) {
hso_dev->is_active = 1;
schedule_work(&hso_dev->async_get_intf);
}
}
if (hso_dev->usb->state != USB_STATE_CONFIGURED)
return -EAGAIN;
usb_mark_last_busy(hso_dev->usb);
return 0;
}
static int hso_put_activity(struct hso_device *hso_dev)
{
if (hso_dev->usb->state != USB_STATE_SUSPENDED) {
if (hso_dev->is_active) {
hso_dev->is_active = 0;
schedule_work(&hso_dev->async_put_intf);
return -EAGAIN;
}
}
hso_dev->is_active = 0;
return 0;
}
static int hso_suspend(struct usb_interface *iface, pm_message_t message)
{
int i, result;
for (i = 0; i < HSO_SERIAL_TTY_MINORS; i++) {
if (serial_table[i] && (serial_table[i]->interface == iface)) {
result = hso_stop_serial_device(serial_table[i]);
if (result)
goto out;
}
}
for (i = 0; i < HSO_MAX_NET_DEVICES; i++) {
if (network_table[i] &&
(network_table[i]->interface == iface)) {
result = hso_stop_net_device(network_table[i]);
if (result)
goto out;
}
}
out:
return 0;
}
static int hso_resume(struct usb_interface *iface)
{
int i, result = 0;
struct hso_net *hso_net;
for (i = 0; i < HSO_SERIAL_TTY_MINORS; i++) {
if (serial_table[i] && (serial_table[i]->interface == iface)) {
if (dev2ser(serial_table[i])->port.count) {
result =
hso_start_serial_device(serial_table[i], GFP_NOIO);
hso_kick_transmit(dev2ser(serial_table[i]));
if (result)
goto out;
}
}
}
for (i = 0; i < HSO_MAX_NET_DEVICES; i++) {
if (network_table[i] &&
(network_table[i]->interface == iface)) {
hso_net = dev2net(network_table[i]);
if (hso_net->flags & IFF_UP) {
if (hso_net->skb_tx_buf) {
dev_dbg(&iface->dev,
"Transmitting"
" lingering data\n");
hso_net_start_xmit(hso_net->skb_tx_buf,
hso_net->net);
hso_net->skb_tx_buf = NULL;
}
result = hso_start_net_device(network_table[i]);
if (result)
goto out;
}
}
}
out:
return result;
}
static void reset_device(struct work_struct *data)
{
struct hso_device *hso_dev =
container_of(data, struct hso_device, reset_device);
struct usb_device *usb = hso_dev->usb;
int result;
if (hso_dev->usb_gone) {
D1("No reset during disconnect\n");
} else {
result = usb_lock_device_for_reset(usb, hso_dev->interface);
if (result < 0)
D1("unable to lock device for reset: %d\n", result);
else {
usb_reset_device(usb);
usb_unlock_device(usb);
}
}
}
static void hso_serial_ref_free(struct kref *ref)
{
struct hso_device *hso_dev = container_of(ref, struct hso_device, ref);
hso_free_serial_device(hso_dev);
}
static void hso_free_interface(struct usb_interface *interface)
{
struct hso_serial *hso_dev;
int i;
for (i = 0; i < HSO_SERIAL_TTY_MINORS; i++) {
if (serial_table[i] &&
(serial_table[i]->interface == interface)) {
hso_dev = dev2ser(serial_table[i]);
tty_port_tty_hangup(&hso_dev->port, false);
mutex_lock(&hso_dev->parent->mutex);
hso_dev->parent->usb_gone = 1;
mutex_unlock(&hso_dev->parent->mutex);
kref_put(&serial_table[i]->ref, hso_serial_ref_free);
}
}
for (i = 0; i < HSO_MAX_NET_DEVICES; i++) {
if (network_table[i] &&
(network_table[i]->interface == interface)) {
struct rfkill *rfk = dev2net(network_table[i])->rfkill;
netif_stop_queue(dev2net(network_table[i])->net);
hso_stop_net_device(network_table[i]);
cancel_work_sync(&network_table[i]->async_put_intf);
cancel_work_sync(&network_table[i]->async_get_intf);
if (rfk) {
rfkill_unregister(rfk);
rfkill_destroy(rfk);
}
hso_free_net_device(network_table[i]);
}
}
}
static struct usb_endpoint_descriptor *hso_get_ep(struct usb_interface *intf,
int type, int dir)
{
int i;
struct usb_host_interface *iface = intf->cur_altsetting;
struct usb_endpoint_descriptor *endp;
for (i = 0; i < iface->desc.bNumEndpoints; i++) {
endp = &iface->endpoint[i].desc;
if (((endp->bEndpointAddress & USB_ENDPOINT_DIR_MASK) == dir) &&
(usb_endpoint_type(endp) == type))
return endp;
}
return NULL;
}
static int hso_get_mux_ports(struct usb_interface *intf, unsigned char *ports)
{
int i;
struct usb_host_interface *iface = intf->cur_altsetting;
if (iface->extralen == 3) {
*ports = iface->extra[2];
return 0;
}
for (i = 0; i < iface->desc.bNumEndpoints; i++) {
if (iface->endpoint[i].extralen == 3) {
*ports = iface->endpoint[i].extra[2];
return 0;
}
}
return -1;
}
static int hso_mux_submit_intr_urb(struct hso_shared_int *shared_int,
struct usb_device *usb, gfp_t gfp)
{
int result;
usb_fill_int_urb(shared_int->shared_intr_urb, usb,
usb_rcvintpipe(usb,
shared_int->intr_endp->bEndpointAddress & 0x7F),
shared_int->shared_intr_buf,
1,
intr_callback, shared_int,
shared_int->intr_endp->bInterval);
result = usb_submit_urb(shared_int->shared_intr_urb, gfp);
if (result)
dev_warn(&usb->dev, "%s failed mux_intr_urb %d\n", __func__,
result);
return result;
}
static int __init hso_init(void)
{
int i;
int result;
printk(KERN_INFO "hso: %s\n", version);
spin_lock_init(&serial_table_lock);
for (i = 0; i < HSO_SERIAL_TTY_MINORS; i++)
serial_table[i] = NULL;
tty_drv = alloc_tty_driver(HSO_SERIAL_TTY_MINORS);
if (!tty_drv)
return -ENOMEM;
tty_drv->driver_name = driver_name;
tty_drv->name = tty_filename;
if (tty_major)
tty_drv->major = tty_major;
tty_drv->minor_start = 0;
tty_drv->type = TTY_DRIVER_TYPE_SERIAL;
tty_drv->subtype = SERIAL_TYPE_NORMAL;
tty_drv->flags = TTY_DRIVER_REAL_RAW | TTY_DRIVER_DYNAMIC_DEV;
tty_drv->init_termios = tty_std_termios;
hso_init_termios(&tty_drv->init_termios);
tty_set_operations(tty_drv, &hso_serial_ops);
result = tty_register_driver(tty_drv);
if (result) {
printk(KERN_ERR "%s - tty_register_driver failed(%d)\n",
__func__, result);
goto err_free_tty;
}
result = usb_register(&hso_driver);
if (result) {
printk(KERN_ERR "Could not register hso driver? error: %d\n",
result);
goto err_unreg_tty;
}
return 0;
err_unreg_tty:
tty_unregister_driver(tty_drv);
err_free_tty:
put_tty_driver(tty_drv);
return result;
}
static void __exit hso_exit(void)
{
printk(KERN_INFO "hso: unloaded\n");
tty_unregister_driver(tty_drv);
put_tty_driver(tty_drv);
usb_deregister(&hso_driver);
}
