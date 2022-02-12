static inline int getLayerId(const __u8 *usbPacket)
{
return __le32_to_cpup((__le32 *)(usbPacket));
}
static inline int getPacketId(const __u8 *usbPacket)
{
return __le32_to_cpup((__le32 *)(usbPacket+4));
}
static inline int getDataLength(const __u8 *usbPacket)
{
return __le32_to_cpup((__le32 *)(usbPacket+8));
}
static inline int isAbortTrfCmnd(const unsigned char *buf)
{
if (0 == memcmp(buf, GARMIN_STOP_TRANSFER_REQ,
sizeof(GARMIN_STOP_TRANSFER_REQ)) ||
0 == memcmp(buf, GARMIN_STOP_TRANSFER_REQ_V2,
sizeof(GARMIN_STOP_TRANSFER_REQ_V2)))
return 1;
else
return 0;
}
static void send_to_tty(struct usb_serial_port *port,
char *data, unsigned int actual_length)
{
struct tty_struct *tty = tty_port_tty_get(&port->port);
if (tty && actual_length) {
usb_serial_debug_data(debug, &port->dev,
__func__, actual_length, data);
tty_insert_flip_string(tty, data, actual_length);
tty_flip_buffer_push(tty);
}
tty_kref_put(tty);
}
static int pkt_add(struct garmin_data *garmin_data_p,
unsigned char *data, unsigned int data_length)
{
int state = 0;
int result = 0;
unsigned long flags;
struct garmin_packet *pkt;
if (data_length) {
pkt = kmalloc(sizeof(struct garmin_packet)+data_length,
GFP_ATOMIC);
if (pkt == NULL) {
dev_err(&garmin_data_p->port->dev, "out of memory\n");
return 0;
}
pkt->size = data_length;
memcpy(pkt->data, data, data_length);
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->flags |= FLAGS_QUEUING;
result = list_empty(&garmin_data_p->pktlist);
pkt->seq = garmin_data_p->seq_counter++;
list_add_tail(&pkt->list, &garmin_data_p->pktlist);
state = garmin_data_p->state;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
dbg("%s - added: pkt: %d - %d bytes",
__func__, pkt->seq, data_length);
if (result && (state == STATE_GSP_WAIT_DATA))
gsp_next_packet(garmin_data_p);
}
return result;
}
static struct garmin_packet *pkt_pop(struct garmin_data *garmin_data_p)
{
unsigned long flags;
struct garmin_packet *result = NULL;
spin_lock_irqsave(&garmin_data_p->lock, flags);
if (!list_empty(&garmin_data_p->pktlist)) {
result = (struct garmin_packet *)garmin_data_p->pktlist.next;
list_del(&result->list);
}
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
return result;
}
static void pkt_clear(struct garmin_data *garmin_data_p)
{
unsigned long flags;
struct garmin_packet *result = NULL;
dbg("%s", __func__);
spin_lock_irqsave(&garmin_data_p->lock, flags);
while (!list_empty(&garmin_data_p->pktlist)) {
result = (struct garmin_packet *)garmin_data_p->pktlist.next;
list_del(&result->list);
kfree(result);
}
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
}
static int gsp_send_ack(struct garmin_data *garmin_data_p, __u8 pkt_id)
{
__u8 pkt[10];
__u8 cksum = 0;
__u8 *ptr = pkt;
unsigned l = 0;
dbg("%s - pkt-id: 0x%X.", __func__, 0xFF & pkt_id);
*ptr++ = DLE;
*ptr++ = ACK;
cksum += ACK;
*ptr++ = 2;
cksum += 2;
*ptr++ = pkt_id;
cksum += pkt_id;
if (pkt_id == DLE)
*ptr++ = DLE;
*ptr++ = 0;
*ptr++ = 0xFF & (-cksum);
*ptr++ = DLE;
*ptr++ = ETX;
l = ptr-pkt;
send_to_tty(garmin_data_p->port, pkt, l);
return 0;
}
static int gsp_rec_packet(struct garmin_data *garmin_data_p, int count)
{
unsigned long flags;
const __u8 *recpkt = garmin_data_p->inbuffer+GSP_INITIAL_OFFSET;
__le32 *usbdata = (__le32 *) garmin_data_p->inbuffer;
int cksum = 0;
int n = 0;
int pktid = recpkt[0];
int size = recpkt[1];
usb_serial_debug_data(debug, &garmin_data_p->port->dev,
__func__, count-GSP_INITIAL_OFFSET, recpkt);
if (size != (count-GSP_INITIAL_OFFSET-3)) {
dbg("%s - invalid size, expected %d bytes, got %d",
__func__, size, (count-GSP_INITIAL_OFFSET-3));
return -EINVPKT;
}
cksum += *recpkt++;
cksum += *recpkt++;
if ((__u8 *)&(usbdata[3]) != recpkt) {
dbg("%s - ptr mismatch %p - %p",
__func__, &(usbdata[4]), recpkt);
return -EINVPKT;
}
while (n < size) {
cksum += *recpkt++;
n++;
}
if ((0xff & (cksum + *recpkt)) != 0) {
dbg("%s - invalid checksum, expected %02x, got %02x",
__func__, 0xff & -cksum, 0xff & *recpkt);
return -EINVPKT;
}
usbdata[0] = __cpu_to_le32(GARMIN_LAYERID_APPL);
usbdata[1] = __cpu_to_le32(pktid);
usbdata[2] = __cpu_to_le32(size);
garmin_write_bulk(garmin_data_p->port, garmin_data_p->inbuffer,
GARMIN_PKTHDR_LENGTH+size, 0);
if (isAbortTrfCmnd(garmin_data_p->inbuffer)) {
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->flags |= FLAGS_DROP_DATA;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
pkt_clear(garmin_data_p);
}
return count;
}
static int gsp_receive(struct garmin_data *garmin_data_p,
const unsigned char *buf, int count)
{
unsigned long flags;
int offs = 0;
int ack_or_nak_seen = 0;
__u8 *dest;
int size;
int dleSeen;
int skip;
__u8 data;
spin_lock_irqsave(&garmin_data_p->lock, flags);
dest = garmin_data_p->inbuffer;
size = garmin_data_p->insize;
dleSeen = garmin_data_p->flags & FLAGS_GSP_DLESEEN;
skip = garmin_data_p->flags & FLAGS_GSP_SKIP;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
if (size == 0)
size = GSP_INITIAL_OFFSET;
while (offs < count) {
data = *(buf+offs);
offs++;
if (data == DLE) {
if (skip) {
skip = 0;
size = GSP_INITIAL_OFFSET;
dleSeen = 1;
} else if (dleSeen) {
dest[size++] = data;
dleSeen = 0;
} else {
dleSeen = 1;
}
} else if (data == ETX) {
if (dleSeen) {
data = dest[GSP_INITIAL_OFFSET];
if (data == ACK) {
ack_or_nak_seen = ACK;
dbg("ACK packet complete.");
} else if (data == NAK) {
ack_or_nak_seen = NAK;
dbg("NAK packet complete.");
} else {
dbg("packet complete - id=0x%X.",
0xFF & data);
gsp_rec_packet(garmin_data_p, size);
}
skip = 1;
size = GSP_INITIAL_OFFSET;
dleSeen = 0;
} else {
dest[size++] = data;
}
} else if (!skip) {
if (dleSeen) {
size = GSP_INITIAL_OFFSET;
dleSeen = 0;
}
dest[size++] = data;
}
if (size >= GPS_IN_BUFSIZ) {
dbg("%s - packet too large.", __func__);
skip = 1;
size = GSP_INITIAL_OFFSET;
dleSeen = 0;
}
}
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->insize = size;
if (skip)
garmin_data_p->flags |= FLAGS_GSP_SKIP;
else
garmin_data_p->flags &= ~FLAGS_GSP_SKIP;
if (dleSeen)
garmin_data_p->flags |= FLAGS_GSP_DLESEEN;
else
garmin_data_p->flags &= ~FLAGS_GSP_DLESEEN;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
if (ack_or_nak_seen) {
if (gsp_next_packet(garmin_data_p) > 0)
garmin_data_p->state = STATE_ACTIVE;
else
garmin_data_p->state = STATE_GSP_WAIT_DATA;
}
return count;
}
static int gsp_send(struct garmin_data *garmin_data_p,
const unsigned char *buf, int count)
{
const unsigned char *src;
unsigned char *dst;
int pktid = 0;
int datalen = 0;
int cksum = 0;
int i = 0;
int k;
dbg("%s - state %d - %d bytes.", __func__,
garmin_data_p->state, count);
k = garmin_data_p->outsize;
if ((k+count) > GPS_OUT_BUFSIZ) {
dbg("packet too large");
garmin_data_p->outsize = 0;
return -4;
}
memcpy(garmin_data_p->outbuffer+k, buf, count);
k += count;
garmin_data_p->outsize = k;
if (k >= GARMIN_PKTHDR_LENGTH) {
pktid = getPacketId(garmin_data_p->outbuffer);
datalen = getDataLength(garmin_data_p->outbuffer);
i = GARMIN_PKTHDR_LENGTH + datalen;
if (k < i)
return 0;
} else {
return 0;
}
dbg("%s - %d bytes in buffer, %d bytes in pkt.", __func__, k, i);
usb_serial_debug_data(debug, &garmin_data_p->port->dev,
__func__, k, garmin_data_p->outbuffer);
garmin_data_p->outsize = 0;
if (GARMIN_LAYERID_APPL != getLayerId(garmin_data_p->outbuffer)) {
dbg("not an application packet (%d)",
getLayerId(garmin_data_p->outbuffer));
return -1;
}
if (pktid > 255) {
dbg("packet-id %d too large", pktid);
return -2;
}
if (datalen > 255) {
dbg("packet-size %d too large", datalen);
return -3;
}
k = 0;
src = garmin_data_p->outbuffer+GARMIN_PKTHDR_LENGTH;
for (i = 0; i < datalen; i++) {
if (*src++ == DLE)
k++;
}
src = garmin_data_p->outbuffer+GARMIN_PKTHDR_LENGTH;
if (k > (GARMIN_PKTHDR_LENGTH-2)) {
dst = garmin_data_p->outbuffer+GPS_OUT_BUFSIZ-datalen;
memcpy(dst, src, datalen);
src = dst;
}
dst = garmin_data_p->outbuffer;
*dst++ = DLE;
*dst++ = pktid;
cksum += pktid;
*dst++ = datalen;
cksum += datalen;
if (datalen == DLE)
*dst++ = DLE;
for (i = 0; i < datalen; i++) {
__u8 c = *src++;
*dst++ = c;
cksum += c;
if (c == DLE)
*dst++ = DLE;
}
cksum = 0xFF & -cksum;
*dst++ = cksum;
if (cksum == DLE)
*dst++ = DLE;
*dst++ = DLE;
*dst++ = ETX;
i = dst-garmin_data_p->outbuffer;
send_to_tty(garmin_data_p->port, garmin_data_p->outbuffer, i);
garmin_data_p->pkt_id = pktid;
garmin_data_p->state = STATE_WAIT_TTY_ACK;
return i;
}
static int gsp_next_packet(struct garmin_data *garmin_data_p)
{
int result = 0;
struct garmin_packet *pkt = NULL;
while ((pkt = pkt_pop(garmin_data_p)) != NULL) {
dbg("%s - next pkt: %d", __func__, pkt->seq);
result = gsp_send(garmin_data_p, pkt->data, pkt->size);
if (result > 0) {
kfree(pkt);
return result;
}
kfree(pkt);
}
return result;
}
static int nat_receive(struct garmin_data *garmin_data_p,
const unsigned char *buf, int count)
{
unsigned long flags;
__u8 *dest;
int offs = 0;
int result = count;
int len;
while (offs < count) {
if (garmin_data_p->insize >= GARMIN_PKTHDR_LENGTH)
len = GARMIN_PKTHDR_LENGTH
+getDataLength(garmin_data_p->inbuffer);
else
len = GARMIN_PKTHDR_LENGTH;
if (len >= GPS_IN_BUFSIZ) {
dbg("%s - packet size too large: %d", __func__, len);
garmin_data_p->insize = 0;
count = 0;
result = -EINVPKT;
} else {
len -= garmin_data_p->insize;
if (len > (count-offs))
len = (count-offs);
if (len > 0) {
dest = garmin_data_p->inbuffer
+ garmin_data_p->insize;
memcpy(dest, buf+offs, len);
garmin_data_p->insize += len;
offs += len;
}
}
if (garmin_data_p->insize >= GARMIN_PKTHDR_LENGTH) {
len = GARMIN_PKTHDR_LENGTH+
getDataLength(garmin_data_p->inbuffer);
if (garmin_data_p->insize >= len) {
garmin_write_bulk(garmin_data_p->port,
garmin_data_p->inbuffer,
len, 0);
garmin_data_p->insize = 0;
if (isAbortTrfCmnd(garmin_data_p->inbuffer)) {
spin_lock_irqsave(&garmin_data_p->lock,
flags);
garmin_data_p->flags |= FLAGS_DROP_DATA;
spin_unlock_irqrestore(
&garmin_data_p->lock, flags);
pkt_clear(garmin_data_p);
}
}
}
}
return result;
}
static void priv_status_resp(struct usb_serial_port *port)
{
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
__le32 *pkt = (__le32 *)garmin_data_p->privpkt;
pkt[0] = __cpu_to_le32(GARMIN_LAYERID_PRIVATE);
pkt[1] = __cpu_to_le32(PRIV_PKTID_INFO_RESP);
pkt[2] = __cpu_to_le32(12);
pkt[3] = __cpu_to_le32(VERSION_MAJOR << 16 | VERSION_MINOR);
pkt[4] = __cpu_to_le32(garmin_data_p->mode);
pkt[5] = __cpu_to_le32(garmin_data_p->serial_num);
send_to_tty(port, (__u8 *)pkt, 6 * 4);
}
static int process_resetdev_request(struct usb_serial_port *port)
{
unsigned long flags;
int status;
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->flags &= ~(CLEAR_HALT_REQUIRED);
garmin_data_p->state = STATE_RESET;
garmin_data_p->serial_num = 0;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
usb_kill_urb(port->interrupt_in_urb);
dbg("%s - usb_reset_device", __func__);
status = usb_reset_device(port->serial->dev);
if (status)
dbg("%s - usb_reset_device failed: %d",
__func__, status);
return status;
}
static int garmin_clear(struct garmin_data *garmin_data_p)
{
unsigned long flags;
int status = 0;
pkt_clear(garmin_data_p);
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->insize = 0;
garmin_data_p->outsize = 0;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
return status;
}
static int garmin_init_session(struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
int status = 0;
int i = 0;
if (status == 0) {
usb_kill_urb(port->interrupt_in_urb);
dbg("%s - adding interrupt input", __func__);
status = usb_submit_urb(port->interrupt_in_urb, GFP_KERNEL);
if (status)
dev_err(&serial->dev->dev,
"%s - failed submitting interrupt urb, error %d\n",
__func__, status);
}
if (status == 0) {
dbg("%s - starting session ...", __func__);
garmin_data_p->state = STATE_ACTIVE;
for (i = 0; i < 3; i++) {
status = garmin_write_bulk(port,
GARMIN_START_SESSION_REQ,
sizeof(GARMIN_START_SESSION_REQ), 0);
if (status < 0)
break;
}
if (status > 0)
status = 0;
}
return status;
}
static int garmin_open(struct tty_struct *tty, struct usb_serial_port *port)
{
unsigned long flags;
int status = 0;
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
dbg("%s - port %d", __func__, port->number);
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->mode = initial_mode;
garmin_data_p->count = 0;
garmin_data_p->flags &= FLAGS_SESSION_REPLY1_SEEN;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
usb_kill_urb(port->write_urb);
usb_kill_urb(port->read_urb);
if (garmin_data_p->state == STATE_RESET)
status = garmin_init_session(port);
garmin_data_p->state = STATE_ACTIVE;
return status;
}
static void garmin_close(struct usb_serial_port *port)
{
struct usb_serial *serial = port->serial;
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
dbg("%s - port %d - mode=%d state=%d flags=0x%X", __func__,
port->number, garmin_data_p->mode,
garmin_data_p->state, garmin_data_p->flags);
if (!serial)
return;
mutex_lock(&port->serial->disc_mutex);
if (!port->serial->disconnected)
garmin_clear(garmin_data_p);
usb_kill_urb(port->read_urb);
usb_kill_urb(port->write_urb);
if (garmin_data_p->state != STATE_RESET)
garmin_data_p->state = STATE_DISCONNECTED;
mutex_unlock(&port->serial->disc_mutex);
}
static void garmin_write_bulk_callback(struct urb *urb)
{
struct usb_serial_port *port = urb->context;
if (port) {
struct garmin_data *garmin_data_p =
usb_get_serial_port_data(port);
dbg("%s - port %d", __func__, port->number);
if (GARMIN_LAYERID_APPL == getLayerId(urb->transfer_buffer)) {
if (garmin_data_p->mode == MODE_GARMIN_SERIAL) {
gsp_send_ack(garmin_data_p,
((__u8 *)urb->transfer_buffer)[4]);
}
}
usb_serial_port_softint(port);
}
kfree(urb->transfer_buffer);
}
static int garmin_write_bulk(struct usb_serial_port *port,
const unsigned char *buf, int count,
int dismiss_ack)
{
unsigned long flags;
struct usb_serial *serial = port->serial;
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
struct urb *urb;
unsigned char *buffer;
int status;
dbg("%s - port %d, state %d", __func__, port->number,
garmin_data_p->state);
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->flags &= ~FLAGS_DROP_DATA;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
buffer = kmalloc(count, GFP_ATOMIC);
if (!buffer) {
dev_err(&port->dev, "out of memory\n");
return -ENOMEM;
}
urb = usb_alloc_urb(0, GFP_ATOMIC);
if (!urb) {
dev_err(&port->dev, "no more free urbs\n");
kfree(buffer);
return -ENOMEM;
}
memcpy(buffer, buf, count);
usb_serial_debug_data(debug, &port->dev, __func__, count, buffer);
usb_fill_bulk_urb(urb, serial->dev,
usb_sndbulkpipe(serial->dev,
port->bulk_out_endpointAddress),
buffer, count,
garmin_write_bulk_callback,
dismiss_ack ? NULL : port);
urb->transfer_flags |= URB_ZERO_PACKET;
if (GARMIN_LAYERID_APPL == getLayerId(buffer)) {
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->flags |= APP_REQ_SEEN;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
if (garmin_data_p->mode == MODE_GARMIN_SERIAL) {
pkt_clear(garmin_data_p);
garmin_data_p->state = STATE_GSP_WAIT_DATA;
}
}
status = usb_submit_urb(urb, GFP_ATOMIC);
if (status) {
dev_err(&port->dev,
"%s - usb_submit_urb(write bulk) failed with status = %d\n",
__func__, status);
count = status;
}
usb_free_urb(urb);
return count;
}
static int garmin_write(struct tty_struct *tty, struct usb_serial_port *port,
const unsigned char *buf, int count)
{
int pktid, pktsiz, len;
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
__le32 *privpkt = (__le32 *)garmin_data_p->privpkt;
usb_serial_debug_data(debug, &port->dev, __func__, count, buf);
if (garmin_data_p->state == STATE_RESET)
return -EIO;
if (count >= GARMIN_PKTHDR_LENGTH) {
len = PRIVPKTSIZ;
if (count < len)
len = count;
memcpy(garmin_data_p->privpkt, buf, len);
pktsiz = getDataLength(garmin_data_p->privpkt);
pktid = getPacketId(garmin_data_p->privpkt);
if (count == (GARMIN_PKTHDR_LENGTH+pktsiz)
&& GARMIN_LAYERID_PRIVATE ==
getLayerId(garmin_data_p->privpkt)) {
dbg("%s - processing private request %d",
__func__, pktid);
garmin_clear(garmin_data_p);
switch (pktid) {
case PRIV_PKTID_SET_DEBUG:
if (pktsiz != 4)
return -EINVPKT;
debug = __le32_to_cpu(privpkt[3]);
dbg("%s - debug level set to 0x%X",
__func__, debug);
break;
case PRIV_PKTID_SET_MODE:
if (pktsiz != 4)
return -EINVPKT;
garmin_data_p->mode = __le32_to_cpu(privpkt[3]);
dbg("%s - mode set to %d",
__func__, garmin_data_p->mode);
break;
case PRIV_PKTID_INFO_REQ:
priv_status_resp(port);
break;
case PRIV_PKTID_RESET_REQ:
process_resetdev_request(port);
break;
case PRIV_PKTID_SET_DEF_MODE:
if (pktsiz != 4)
return -EINVPKT;
initial_mode = __le32_to_cpu(privpkt[3]);
dbg("%s - initial_mode set to %d",
__func__,
garmin_data_p->mode);
break;
}
return count;
}
}
if (garmin_data_p->mode == MODE_GARMIN_SERIAL) {
return gsp_receive(garmin_data_p, buf, count);
} else {
return nat_receive(garmin_data_p, buf, count);
}
}
static int garmin_write_room(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
return GPS_OUT_BUFSIZ-garmin_data_p->outsize;
}
static void garmin_read_process(struct garmin_data *garmin_data_p,
unsigned char *data, unsigned data_length,
int bulk_data)
{
unsigned long flags;
if (garmin_data_p->flags & FLAGS_DROP_DATA) {
dbg("%s - pkt dropped", __func__);
} else if (garmin_data_p->state != STATE_DISCONNECTED &&
garmin_data_p->state != STATE_RESET) {
if (garmin_data_p->flags & FLAGS_QUEUING) {
pkt_add(garmin_data_p, data, data_length);
} else if (bulk_data ||
getLayerId(data) == GARMIN_LAYERID_APPL) {
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->flags |= APP_RESP_SEEN;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
if (garmin_data_p->mode == MODE_GARMIN_SERIAL) {
pkt_add(garmin_data_p, data, data_length);
} else {
send_to_tty(garmin_data_p->port, data,
data_length);
}
}
}
}
static void garmin_read_bulk_callback(struct urb *urb)
{
unsigned long flags;
struct usb_serial_port *port = urb->context;
struct usb_serial *serial = port->serial;
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
unsigned char *data = urb->transfer_buffer;
int status = urb->status;
int retval;
dbg("%s - port %d", __func__, port->number);
if (!serial) {
dbg("%s - bad serial pointer, exiting", __func__);
return;
}
if (status) {
dbg("%s - nonzero read bulk status received: %d",
__func__, status);
return;
}
usb_serial_debug_data(debug, &port->dev,
__func__, urb->actual_length, data);
garmin_read_process(garmin_data_p, data, urb->actual_length, 1);
if (urb->actual_length == 0 &&
0 != (garmin_data_p->flags & FLAGS_BULK_IN_RESTART)) {
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->flags &= ~FLAGS_BULK_IN_RESTART;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
retval = usb_submit_urb(port->read_urb, GFP_ATOMIC);
if (retval)
dev_err(&port->dev,
"%s - failed resubmitting read urb, error %d\n",
__func__, retval);
} else if (urb->actual_length > 0) {
if (0 == (garmin_data_p->flags & FLAGS_THROTTLED)) {
retval = usb_submit_urb(port->read_urb, GFP_ATOMIC);
if (retval)
dev_err(&port->dev,
"%s - failed resubmitting read urb, "
"error %d\n", __func__, retval);
}
} else {
dbg("%s - end of bulk data", __func__);
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->flags &= ~FLAGS_BULK_IN_ACTIVE;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
}
}
static void garmin_read_int_callback(struct urb *urb)
{
unsigned long flags;
int retval;
struct usb_serial_port *port = urb->context;
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
unsigned char *data = urb->transfer_buffer;
int status = urb->status;
switch (status) {
case 0:
break;
case -ECONNRESET:
case -ENOENT:
case -ESHUTDOWN:
dbg("%s - urb shutting down with status: %d",
__func__, status);
return;
default:
dbg("%s - nonzero urb status received: %d",
__func__, status);
return;
}
usb_serial_debug_data(debug, &port->dev, __func__,
urb->actual_length, urb->transfer_buffer);
if (urb->actual_length == sizeof(GARMIN_BULK_IN_AVAIL_REPLY) &&
0 == memcmp(data, GARMIN_BULK_IN_AVAIL_REPLY,
sizeof(GARMIN_BULK_IN_AVAIL_REPLY))) {
dbg("%s - bulk data available.", __func__);
if (0 == (garmin_data_p->flags & FLAGS_BULK_IN_ACTIVE)) {
retval = usb_submit_urb(port->read_urb, GFP_ATOMIC);
if (retval) {
dev_err(&port->dev,
"%s - failed submitting read urb, error %d\n",
__func__, retval);
} else {
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->flags |= FLAGS_BULK_IN_ACTIVE;
spin_unlock_irqrestore(&garmin_data_p->lock,
flags);
}
} else {
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->flags |= FLAGS_BULK_IN_RESTART;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
}
} else if (urb->actual_length == (4+sizeof(GARMIN_START_SESSION_REPLY))
&& 0 == memcmp(data, GARMIN_START_SESSION_REPLY,
sizeof(GARMIN_START_SESSION_REPLY))) {
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->flags |= FLAGS_SESSION_REPLY1_SEEN;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
garmin_data_p->serial_num = __le32_to_cpup(
(__le32 *)(data+GARMIN_PKTHDR_LENGTH));
dbg("%s - start-of-session reply seen - serial %u.",
__func__, garmin_data_p->serial_num);
}
garmin_read_process(garmin_data_p, data, urb->actual_length, 0);
retval = usb_submit_urb(urb, GFP_ATOMIC);
if (retval)
dev_err(&urb->dev->dev,
"%s - Error %d submitting interrupt urb\n",
__func__, retval);
}
static int garmin_flush_queue(struct garmin_data *garmin_data_p)
{
unsigned long flags;
struct garmin_packet *pkt;
if ((garmin_data_p->flags & FLAGS_THROTTLED) == 0) {
pkt = pkt_pop(garmin_data_p);
if (pkt != NULL) {
send_to_tty(garmin_data_p->port, pkt->data, pkt->size);
kfree(pkt);
mod_timer(&garmin_data_p->timer, (1)+jiffies);
} else {
spin_lock_irqsave(&garmin_data_p->lock, flags);
garmin_data_p->flags &= ~FLAGS_QUEUING;
spin_unlock_irqrestore(&garmin_data_p->lock, flags);
}
}
return 0;
}
static void garmin_throttle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
dbg("%s - port %d", __func__, port->number);
spin_lock_irq(&garmin_data_p->lock);
garmin_data_p->flags |= FLAGS_QUEUING|FLAGS_THROTTLED;
spin_unlock_irq(&garmin_data_p->lock);
}
static void garmin_unthrottle(struct tty_struct *tty)
{
struct usb_serial_port *port = tty->driver_data;
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
int status;
dbg("%s - port %d", __func__, port->number);
spin_lock_irq(&garmin_data_p->lock);
garmin_data_p->flags &= ~FLAGS_THROTTLED;
spin_unlock_irq(&garmin_data_p->lock);
if (garmin_data_p->mode == MODE_NATIVE)
garmin_flush_queue(garmin_data_p);
if (0 != (garmin_data_p->flags & FLAGS_BULK_IN_ACTIVE)) {
status = usb_submit_urb(port->read_urb, GFP_KERNEL);
if (status)
dev_err(&port->dev,
"%s - failed resubmitting read urb, error %d\n",
__func__, status);
}
}
static void timeout_handler(unsigned long data)
{
struct garmin_data *garmin_data_p = (struct garmin_data *) data;
if (garmin_data_p->mode == MODE_NATIVE)
if (garmin_data_p->flags & FLAGS_QUEUING)
garmin_flush_queue(garmin_data_p);
}
static int garmin_attach(struct usb_serial *serial)
{
int status = 0;
struct usb_serial_port *port = serial->port[0];
struct garmin_data *garmin_data_p = NULL;
dbg("%s", __func__);
garmin_data_p = kzalloc(sizeof(struct garmin_data), GFP_KERNEL);
if (garmin_data_p == NULL) {
dev_err(&port->dev, "%s - Out of memory\n", __func__);
return -ENOMEM;
}
init_timer(&garmin_data_p->timer);
spin_lock_init(&garmin_data_p->lock);
INIT_LIST_HEAD(&garmin_data_p->pktlist);
garmin_data_p->timer.data = (unsigned long)garmin_data_p;
garmin_data_p->timer.function = timeout_handler;
garmin_data_p->port = port;
garmin_data_p->state = 0;
garmin_data_p->flags = 0;
garmin_data_p->count = 0;
usb_set_serial_port_data(port, garmin_data_p);
status = garmin_init_session(port);
return status;
}
static void garmin_disconnect(struct usb_serial *serial)
{
struct usb_serial_port *port = serial->port[0];
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
dbg("%s", __func__);
usb_kill_urb(port->interrupt_in_urb);
del_timer_sync(&garmin_data_p->timer);
}
static void garmin_release(struct usb_serial *serial)
{
struct usb_serial_port *port = serial->port[0];
struct garmin_data *garmin_data_p = usb_get_serial_port_data(port);
dbg("%s", __func__);
kfree(garmin_data_p);
}
