static void start_timing(void)
{
timing_stats.start_time = jiffies;
}
static void end_read_timing(unsigned length)
{
timing_stats.read_time += (jiffies - start_time);
timing_stats.read_bytes += length + 2;
report_timing();
}
static void end_write_timing(unsigned length)
{
timing_stats.write_time += (jiffies - start_time);
timing_stats.write_bytes += length + 2;
report_timing();
}
static void report_timing(void)
{
unsigned long since = jiffies - timing_stats.last_report_time;
if (since >= HZ) {
int first = (timing_stats.last_report_time == 0);
timing_stats.last_report_time = jiffies;
if (!first)
printk(KERN_INFO IPWIRELESS_PCCARD_NAME
": %u us elapsed - read %lu bytes in %u us, wrote %lu bytes in %u us\n",
jiffies_to_usecs(since),
timing_stats.read_bytes,
jiffies_to_usecs(timing_stats.read_time),
timing_stats.write_bytes,
jiffies_to_usecs(timing_stats.write_time));
timing_stats.read_time = 0;
timing_stats.write_time = 0;
timing_stats.read_bytes = 0;
timing_stats.write_bytes = 0;
}
}
static void start_timing(void) { }
static void end_read_timing(unsigned length) { }
static void end_write_timing(unsigned length) { }
static char *data_type(const unsigned char *buf, unsigned length)
{
struct nl_packet_header *hdr = (struct nl_packet_header *) buf;
if (length == 0)
return " ";
if (hdr->packet_rank & NL_FIRST_PACKET) {
switch (hdr->protocol) {
case TL_PROTOCOLID_COM_DATA: return "DATA ";
case TL_PROTOCOLID_COM_CTRL: return "CTRL ";
case TL_PROTOCOLID_SETUP: return "SETUP";
default: return "???? ";
}
} else
return " ";
}
static void dump_data_bytes(const char *type, const unsigned char *data,
unsigned length)
{
char prefix[56];
sprintf(prefix, IPWIRELESS_PCCARD_NAME ": %s %s ",
type, data_type(data, length));
print_hex_dump_bytes(prefix, 0, (void *)data,
length < DUMP_MAX_BYTES ? length : DUMP_MAX_BYTES);
}
static void swap_packet_bitfield_to_le(unsigned char *data)
{
#ifdef __BIG_ENDIAN_BITFIELD
unsigned char tmp = *data, ret = 0;
ret |= (tmp & 0xc0) >> 6;
ret |= (tmp & 0x38) >> 1;
ret |= (tmp & 0x07) << 5;
*data = ret & 0xff;
#endif
}
static void swap_packet_bitfield_from_le(unsigned char *data)
{
#ifdef __BIG_ENDIAN_BITFIELD
unsigned char tmp = *data, ret = 0;
ret |= (tmp & 0xe0) >> 5;
ret |= (tmp & 0x1c) << 1;
ret |= (tmp & 0x03) << 6;
*data = ret & 0xff;
#endif
}
static void do_send_fragment(struct ipw_hardware *hw, unsigned char *data,
unsigned length)
{
unsigned i;
unsigned long flags;
start_timing();
BUG_ON(length > hw->ll_mtu);
if (ipwireless_debug)
dump_data_bytes("send", data, length);
spin_lock_irqsave(&hw->lock, flags);
hw->tx_ready = 0;
swap_packet_bitfield_to_le(data);
if (hw->hw_version == HW_VERSION_1) {
outw((unsigned short) length, hw->base_port + IODWR);
for (i = 0; i < length; i += 2) {
unsigned short d = data[i];
__le16 raw_data;
if (i + 1 < length)
d |= data[i + 1] << 8;
raw_data = cpu_to_le16(d);
outw(raw_data, hw->base_port + IODWR);
}
outw(DCR_TXDONE, hw->base_port + IODCR);
} else if (hw->hw_version == HW_VERSION_2) {
outw((unsigned short) length, hw->base_port);
for (i = 0; i < length; i += 2) {
unsigned short d = data[i];
__le16 raw_data;
if (i + 1 < length)
d |= data[i + 1] << 8;
raw_data = cpu_to_le16(d);
outw(raw_data, hw->base_port);
}
while ((i & 3) != 2) {
outw((unsigned short) 0xDEAD, hw->base_port);
i += 2;
}
writew(MEMRX_RX, &hw->memory_info_regs->memreg_rx);
}
spin_unlock_irqrestore(&hw->lock, flags);
end_write_timing(length);
}
static void do_send_packet(struct ipw_hardware *hw, struct ipw_tx_packet *packet)
{
unsigned short fragment_data_len;
unsigned short data_left = packet->length - packet->offset;
unsigned short header_size;
union nl_packet pkt;
header_size =
(packet->fragment_count == 0)
? NL_FIRST_PACKET_HEADER_SIZE
: NL_FOLLOWING_PACKET_HEADER_SIZE;
fragment_data_len = hw->ll_mtu - header_size;
if (data_left < fragment_data_len)
fragment_data_len = data_left;
pkt.hdr_first.protocol = packet->protocol;
pkt.hdr_first.address = packet->dest_addr;
pkt.hdr_first.packet_rank = 0;
if (packet->fragment_count == 0) {
pkt.hdr_first.packet_rank |= NL_FIRST_PACKET;
pkt.hdr_first.length_lsb = (unsigned char) packet->length;
pkt.hdr_first.length_msb =
(unsigned char) (packet->length >> 8);
}
memcpy(pkt.rawpkt + header_size,
((unsigned char *) packet) + sizeof(struct ipw_tx_packet) +
packet->offset, fragment_data_len);
packet->offset += fragment_data_len;
packet->fragment_count++;
if (packet->offset == packet->length)
pkt.hdr_first.packet_rank |= NL_LAST_PACKET;
do_send_fragment(hw, pkt.rawpkt, header_size + fragment_data_len);
if (packet->offset < packet->length) {
unsigned long flags;
spin_lock_irqsave(&hw->lock, flags);
list_add(&packet->queue, &hw->tx_queue[0]);
hw->tx_queued++;
spin_unlock_irqrestore(&hw->lock, flags);
} else {
if (packet->packet_callback)
packet->packet_callback(packet->callback_data,
packet->length);
kfree(packet);
}
}
static void ipw_setup_hardware(struct ipw_hardware *hw)
{
unsigned long flags;
spin_lock_irqsave(&hw->lock, flags);
if (hw->hw_version == HW_VERSION_1) {
outw(DCR_RXRESET, hw->base_port + IODCR);
outw(DCR_TXRESET, hw->base_port + IODCR);
outw(IER_TXENABLED | IER_RXENABLED, hw->base_port + IOIER);
} else {
unsigned short csr = readw(&hw->memregs_CCR->reg_config_and_status);
csr |= 1;
writew(csr, &hw->memregs_CCR->reg_config_and_status);
}
spin_unlock_irqrestore(&hw->lock, flags);
}
static struct ipw_rx_packet *pool_allocate(struct ipw_hardware *hw,
struct ipw_rx_packet *packet,
int minimum_free_space)
{
if (!packet) {
unsigned long flags;
spin_lock_irqsave(&hw->lock, flags);
if (!list_empty(&hw->rx_pool)) {
packet = list_first_entry(&hw->rx_pool,
struct ipw_rx_packet, queue);
hw->rx_pool_size--;
spin_unlock_irqrestore(&hw->lock, flags);
list_del(&packet->queue);
} else {
const int min_capacity =
ipwireless_ppp_mru(hw->network) + 2;
int new_capacity;
spin_unlock_irqrestore(&hw->lock, flags);
new_capacity =
(minimum_free_space > min_capacity
? minimum_free_space
: min_capacity);
packet = kmalloc(sizeof(struct ipw_rx_packet)
+ new_capacity, GFP_ATOMIC);
if (!packet)
return NULL;
packet->capacity = new_capacity;
}
packet->length = 0;
}
if (packet->length + minimum_free_space > packet->capacity) {
struct ipw_rx_packet *old_packet = packet;
packet = kmalloc(sizeof(struct ipw_rx_packet) +
old_packet->length + minimum_free_space,
GFP_ATOMIC);
if (!packet) {
kfree(old_packet);
return NULL;
}
memcpy(packet, old_packet,
sizeof(struct ipw_rx_packet)
+ old_packet->length);
packet->capacity = old_packet->length + minimum_free_space;
kfree(old_packet);
}
return packet;
}
static void pool_free(struct ipw_hardware *hw, struct ipw_rx_packet *packet)
{
if (hw->rx_pool_size > 6)
kfree(packet);
else {
hw->rx_pool_size++;
list_add(&packet->queue, &hw->rx_pool);
}
}
static void queue_received_packet(struct ipw_hardware *hw,
unsigned int protocol,
unsigned int address,
const unsigned char *data, int length,
int is_last)
{
unsigned int channel_idx = address - 1;
struct ipw_rx_packet *packet = NULL;
unsigned long flags;
if (channel_idx >= NL_NUM_OF_ADDRESSES) {
printk(KERN_INFO IPWIRELESS_PCCARD_NAME
": data packet has bad address %u\n", address);
return;
}
if (protocol == TL_PROTOCOLID_COM_DATA) {
struct ipw_rx_packet **assem =
&hw->packet_assembler[channel_idx];
(*assem) = pool_allocate(hw, *assem, length);
if (!(*assem)) {
printk(KERN_ERR IPWIRELESS_PCCARD_NAME
": no memory for incoming data packet, dropped!\n");
return;
}
(*assem)->protocol = protocol;
(*assem)->channel_idx = channel_idx;
memcpy((unsigned char *)(*assem) +
sizeof(struct ipw_rx_packet)
+ (*assem)->length, data, length);
(*assem)->length += length;
if (is_last) {
packet = *assem;
*assem = NULL;
spin_lock_irqsave(&hw->lock, flags);
hw->rx_bytes_queued += packet->length;
spin_unlock_irqrestore(&hw->lock, flags);
}
} else {
packet = pool_allocate(hw, NULL, length);
if (!packet) {
printk(KERN_ERR IPWIRELESS_PCCARD_NAME
": no memory for incoming ctrl packet, dropped!\n");
return;
}
packet->protocol = protocol;
packet->channel_idx = channel_idx;
memcpy((unsigned char *)packet + sizeof(struct ipw_rx_packet),
data, length);
packet->length = length;
}
if (packet) {
spin_lock_irqsave(&hw->lock, flags);
list_add_tail(&packet->queue, &hw->rx_queue);
hw->blocking_rx =
(hw->rx_bytes_queued >= IPWIRELESS_RX_QUEUE_SIZE);
spin_unlock_irqrestore(&hw->lock, flags);
schedule_work(&hw->work_rx);
}
}
static void ipw_receive_data_work(struct work_struct *work_rx)
{
struct ipw_hardware *hw =
container_of(work_rx, struct ipw_hardware, work_rx);
unsigned long flags;
spin_lock_irqsave(&hw->lock, flags);
while (!list_empty(&hw->rx_queue)) {
struct ipw_rx_packet *packet =
list_first_entry(&hw->rx_queue,
struct ipw_rx_packet, queue);
if (hw->shutting_down)
break;
list_del(&packet->queue);
if (packet->protocol == TL_PROTOCOLID_COM_DATA) {
if (hw->network != NULL) {
spin_unlock_irqrestore(&hw->lock, flags);
ipwireless_network_packet_received(
hw->network,
packet->channel_idx,
(unsigned char *)packet
+ sizeof(struct ipw_rx_packet),
packet->length);
spin_lock_irqsave(&hw->lock, flags);
}
hw->rx_bytes_queued -= packet->length;
} else {
handle_received_CTRL_packet(hw, packet->channel_idx,
(unsigned char *)packet
+ sizeof(struct ipw_rx_packet),
packet->length);
}
pool_free(hw, packet);
hw->blocking_rx =
hw->rx_bytes_queued >= IPWIRELESS_RX_QUEUE_SIZE;
if (hw->shutting_down)
break;
}
spin_unlock_irqrestore(&hw->lock, flags);
}
static void handle_received_CTRL_packet(struct ipw_hardware *hw,
unsigned int channel_idx,
const unsigned char *data, int len)
{
const struct ipw_control_packet_body *body =
(const struct ipw_control_packet_body *) data;
unsigned int changed_mask;
if (len != sizeof(struct ipw_control_packet_body)) {
printk(KERN_INFO IPWIRELESS_PCCARD_NAME
": control packet was %d bytes - wrong size!\n",
len);
return;
}
switch (body->sig_no) {
case COMCTRL_CTS:
changed_mask = IPW_CONTROL_LINE_CTS;
break;
case COMCTRL_DCD:
changed_mask = IPW_CONTROL_LINE_DCD;
break;
case COMCTRL_DSR:
changed_mask = IPW_CONTROL_LINE_DSR;
break;
case COMCTRL_RI:
changed_mask = IPW_CONTROL_LINE_RI;
break;
default:
changed_mask = 0;
}
if (changed_mask != 0) {
if (body->value)
hw->control_lines[channel_idx] |= changed_mask;
else
hw->control_lines[channel_idx] &= ~changed_mask;
if (hw->network)
ipwireless_network_notify_control_line_change(
hw->network,
channel_idx,
hw->control_lines[channel_idx],
changed_mask);
}
}
static void handle_received_packet(struct ipw_hardware *hw,
const union nl_packet *packet,
unsigned short len)
{
unsigned int protocol = packet->hdr.protocol;
unsigned int address = packet->hdr.address;
unsigned int header_length;
const unsigned char *data;
unsigned int data_len;
int is_last = packet->hdr.packet_rank & NL_LAST_PACKET;
if (packet->hdr.packet_rank & NL_FIRST_PACKET)
header_length = NL_FIRST_PACKET_HEADER_SIZE;
else
header_length = NL_FOLLOWING_PACKET_HEADER_SIZE;
data = packet->rawpkt + header_length;
data_len = len - header_length;
switch (protocol) {
case TL_PROTOCOLID_COM_DATA:
case TL_PROTOCOLID_COM_CTRL:
queue_received_packet(hw, protocol, address, data, data_len,
is_last);
break;
case TL_PROTOCOLID_SETUP:
handle_received_SETUP_packet(hw, address, data, data_len,
is_last);
break;
}
}
static void acknowledge_data_read(struct ipw_hardware *hw)
{
if (hw->hw_version == HW_VERSION_1)
outw(DCR_RXDONE, hw->base_port + IODCR);
else
writew(MEMRX_PCINTACKK,
&hw->memory_info_regs->memreg_pc_interrupt_ack);
}
static void do_receive_packet(struct ipw_hardware *hw)
{
unsigned len;
unsigned i;
unsigned char pkt[LL_MTU_MAX];
start_timing();
if (hw->hw_version == HW_VERSION_1) {
len = inw(hw->base_port + IODRR);
if (len > hw->ll_mtu) {
printk(KERN_INFO IPWIRELESS_PCCARD_NAME
": received a packet of %u bytes - longer than the MTU!\n", len);
outw(DCR_RXDONE | DCR_RXRESET, hw->base_port + IODCR);
return;
}
for (i = 0; i < len; i += 2) {
__le16 raw_data = inw(hw->base_port + IODRR);
unsigned short data = le16_to_cpu(raw_data);
pkt[i] = (unsigned char) data;
pkt[i + 1] = (unsigned char) (data >> 8);
}
} else {
len = inw(hw->base_port);
if (len > hw->ll_mtu) {
printk(KERN_INFO IPWIRELESS_PCCARD_NAME
": received a packet of %u bytes - longer than the MTU!\n", len);
writew(MEMRX_PCINTACKK,
&hw->memory_info_regs->memreg_pc_interrupt_ack);
return;
}
for (i = 0; i < len; i += 2) {
__le16 raw_data = inw(hw->base_port);
unsigned short data = le16_to_cpu(raw_data);
pkt[i] = (unsigned char) data;
pkt[i + 1] = (unsigned char) (data >> 8);
}
while ((i & 3) != 2) {
inw(hw->base_port);
i += 2;
}
}
acknowledge_data_read(hw);
swap_packet_bitfield_from_le(pkt);
if (ipwireless_debug)
dump_data_bytes("recv", pkt, len);
handle_received_packet(hw, (union nl_packet *) pkt, len);
end_read_timing(len);
}
static int get_current_packet_priority(struct ipw_hardware *hw)
{
return (hw->to_setup || hw->initializing
? PRIO_SETUP + 1 : NL_NUM_OF_PRIORITIES);
}
static int get_packets_from_hw(struct ipw_hardware *hw)
{
int received = 0;
unsigned long flags;
spin_lock_irqsave(&hw->lock, flags);
while (hw->rx_ready && !hw->blocking_rx) {
received = 1;
hw->rx_ready--;
spin_unlock_irqrestore(&hw->lock, flags);
do_receive_packet(hw);
spin_lock_irqsave(&hw->lock, flags);
}
spin_unlock_irqrestore(&hw->lock, flags);
return received;
}
static int send_pending_packet(struct ipw_hardware *hw, int priority_limit)
{
int more_to_send = 0;
unsigned long flags;
spin_lock_irqsave(&hw->lock, flags);
if (hw->tx_queued && hw->tx_ready) {
int priority;
struct ipw_tx_packet *packet = NULL;
for (priority = 0; priority < priority_limit; priority++) {
if (!list_empty(&hw->tx_queue[priority])) {
packet = list_first_entry(
&hw->tx_queue[priority],
struct ipw_tx_packet,
queue);
hw->tx_queued--;
list_del(&packet->queue);
break;
}
}
if (!packet) {
hw->tx_queued = 0;
spin_unlock_irqrestore(&hw->lock, flags);
return 0;
}
spin_unlock_irqrestore(&hw->lock, flags);
do_send_packet(hw, packet);
spin_lock_irqsave(&hw->lock, flags);
for (priority = 0; priority < priority_limit; priority++)
if (!list_empty(&hw->tx_queue[priority])) {
more_to_send = 1;
break;
}
if (!more_to_send)
hw->tx_queued = 0;
}
spin_unlock_irqrestore(&hw->lock, flags);
return more_to_send;
}
static void ipwireless_do_tasklet(unsigned long hw_)
{
struct ipw_hardware *hw = (struct ipw_hardware *) hw_;
unsigned long flags;
spin_lock_irqsave(&hw->lock, flags);
if (hw->shutting_down) {
spin_unlock_irqrestore(&hw->lock, flags);
return;
}
if (hw->to_setup == 1) {
hw->to_setup = 2;
spin_unlock_irqrestore(&hw->lock, flags);
ipw_setup_hardware(hw);
ipw_send_setup_packet(hw);
send_pending_packet(hw, PRIO_SETUP + 1);
get_packets_from_hw(hw);
} else {
int priority_limit = get_current_packet_priority(hw);
int again;
spin_unlock_irqrestore(&hw->lock, flags);
do {
again = send_pending_packet(hw, priority_limit);
again |= get_packets_from_hw(hw);
} while (again);
}
}
static int is_card_present(struct ipw_hardware *hw)
{
if (hw->hw_version == HW_VERSION_1)
return inw(hw->base_port + IOIR) != 0xFFFF;
else
return readl(&hw->memory_info_regs->memreg_card_present) ==
CARD_PRESENT_VALUE;
}
static irqreturn_t ipwireless_handle_v1_interrupt(int irq,
struct ipw_hardware *hw)
{
unsigned short irqn;
irqn = inw(hw->base_port + IOIR);
if (irqn == 0xFFFF)
return IRQ_NONE;
else if (irqn != 0) {
unsigned short ack = 0;
unsigned long flags;
if (irqn & IR_TXINTR) {
ack |= IR_TXINTR;
spin_lock_irqsave(&hw->lock, flags);
hw->tx_ready = 1;
spin_unlock_irqrestore(&hw->lock, flags);
}
if (irqn & IR_RXINTR) {
ack |= IR_RXINTR;
spin_lock_irqsave(&hw->lock, flags);
hw->rx_ready++;
spin_unlock_irqrestore(&hw->lock, flags);
}
if (ack != 0) {
outw(ack, hw->base_port + IOIR);
tasklet_schedule(&hw->tasklet);
}
return IRQ_HANDLED;
}
return IRQ_NONE;
}
static void acknowledge_pcmcia_interrupt(struct ipw_hardware *hw)
{
unsigned short csr = readw(&hw->memregs_CCR->reg_config_and_status);
csr &= 0xfffd;
writew(csr, &hw->memregs_CCR->reg_config_and_status);
}
static irqreturn_t ipwireless_handle_v2_v3_interrupt(int irq,
struct ipw_hardware *hw)
{
int tx = 0;
int rx = 0;
int rx_repeat = 0;
int try_mem_tx_old;
unsigned long flags;
do {
unsigned short memtx = readw(hw->memreg_tx);
unsigned short memtx_serial;
unsigned short memrxdone =
readw(&hw->memory_info_regs->memreg_rx_done);
try_mem_tx_old = 0;
if (!(memtx & MEMTX_TX) && !(memrxdone & MEMRX_RX_DONE)) {
if (hw->memreg_tx == &hw->memory_info_regs->memreg_tx_new) {
memtx = readw(&hw->memory_info_regs->memreg_tx_old);
if (memtx & MEMTX_TX) {
printk(KERN_INFO IPWIRELESS_PCCARD_NAME
": Using memreg_tx_old\n");
hw->memreg_tx =
&hw->memory_info_regs->memreg_tx_old;
} else {
return IRQ_NONE;
}
} else
return IRQ_NONE;
}
if (!is_card_present(hw)) {
acknowledge_pcmcia_interrupt(hw);
return IRQ_HANDLED;
}
memtx_serial = memtx & (unsigned short) 0xff00;
if (memtx & MEMTX_TX) {
writew(memtx_serial, hw->memreg_tx);
if (hw->serial_number_detected) {
if (memtx_serial != hw->last_memtx_serial) {
hw->last_memtx_serial = memtx_serial;
spin_lock_irqsave(&hw->lock, flags);
hw->rx_ready++;
spin_unlock_irqrestore(&hw->lock, flags);
rx = 1;
} else
rx_repeat = 1;
} else {
if (memtx_serial != 0) {
hw->serial_number_detected = 1;
printk(KERN_DEBUG IPWIRELESS_PCCARD_NAME
": memreg_tx serial num detected\n");
spin_lock_irqsave(&hw->lock, flags);
hw->rx_ready++;
spin_unlock_irqrestore(&hw->lock, flags);
}
rx = 1;
}
}
if (memrxdone & MEMRX_RX_DONE) {
writew(0, &hw->memory_info_regs->memreg_rx_done);
spin_lock_irqsave(&hw->lock, flags);
hw->tx_ready = 1;
spin_unlock_irqrestore(&hw->lock, flags);
tx = 1;
}
if (tx)
writew(MEMRX_PCINTACKK,
&hw->memory_info_regs->memreg_pc_interrupt_ack);
acknowledge_pcmcia_interrupt(hw);
if (tx || rx)
tasklet_schedule(&hw->tasklet);
else if (!rx_repeat) {
if (hw->memreg_tx == &hw->memory_info_regs->memreg_tx_new) {
if (hw->serial_number_detected)
printk(KERN_WARNING IPWIRELESS_PCCARD_NAME
": spurious interrupt - new_tx mode\n");
else {
printk(KERN_WARNING IPWIRELESS_PCCARD_NAME
": no valid memreg_tx value - switching to the old memreg_tx\n");
hw->memreg_tx =
&hw->memory_info_regs->memreg_tx_old;
try_mem_tx_old = 1;
}
} else
printk(KERN_WARNING IPWIRELESS_PCCARD_NAME
": spurious interrupt - old_tx mode\n");
}
} while (try_mem_tx_old == 1);
return IRQ_HANDLED;
}
irqreturn_t ipwireless_interrupt(int irq, void *dev_id)
{
struct ipw_dev *ipw = dev_id;
if (ipw->hardware->hw_version == HW_VERSION_1)
return ipwireless_handle_v1_interrupt(irq, ipw->hardware);
else
return ipwireless_handle_v2_v3_interrupt(irq, ipw->hardware);
}
static void flush_packets_to_hw(struct ipw_hardware *hw)
{
int priority_limit;
unsigned long flags;
spin_lock_irqsave(&hw->lock, flags);
priority_limit = get_current_packet_priority(hw);
spin_unlock_irqrestore(&hw->lock, flags);
while (send_pending_packet(hw, priority_limit));
}
static void send_packet(struct ipw_hardware *hw, int priority,
struct ipw_tx_packet *packet)
{
unsigned long flags;
spin_lock_irqsave(&hw->lock, flags);
list_add_tail(&packet->queue, &hw->tx_queue[priority]);
hw->tx_queued++;
spin_unlock_irqrestore(&hw->lock, flags);
flush_packets_to_hw(hw);
}
static void *alloc_data_packet(int data_size,
unsigned char dest_addr,
unsigned char protocol)
{
struct ipw_tx_packet *packet = kzalloc(
sizeof(struct ipw_tx_packet) + data_size,
GFP_ATOMIC);
if (!packet)
return NULL;
INIT_LIST_HEAD(&packet->queue);
packet->dest_addr = dest_addr;
packet->protocol = protocol;
packet->length = data_size;
return packet;
}
static void *alloc_ctrl_packet(int header_size,
unsigned char dest_addr,
unsigned char protocol,
unsigned char sig_no)
{
struct ipw_control_packet *packet = kzalloc(header_size, GFP_ATOMIC);
if (!packet)
return NULL;
INIT_LIST_HEAD(&packet->header.queue);
packet->header.dest_addr = dest_addr;
packet->header.protocol = protocol;
packet->header.length = header_size - sizeof(struct ipw_tx_packet);
packet->body.sig_no = sig_no;
return packet;
}
int ipwireless_send_packet(struct ipw_hardware *hw, unsigned int channel_idx,
const unsigned char *data, unsigned int length,
void (*callback) (void *cb, unsigned int length),
void *callback_data)
{
struct ipw_tx_packet *packet;
packet = alloc_data_packet(length, (channel_idx + 1),
TL_PROTOCOLID_COM_DATA);
if (!packet)
return -ENOMEM;
packet->packet_callback = callback;
packet->callback_data = callback_data;
memcpy((unsigned char *) packet + sizeof(struct ipw_tx_packet), data,
length);
send_packet(hw, PRIO_DATA, packet);
return 0;
}
static int set_control_line(struct ipw_hardware *hw, int prio,
unsigned int channel_idx, int line, int state)
{
struct ipw_control_packet *packet;
int protocolid = TL_PROTOCOLID_COM_CTRL;
if (prio == PRIO_SETUP)
protocolid = TL_PROTOCOLID_SETUP;
packet = alloc_ctrl_packet(sizeof(struct ipw_control_packet),
(channel_idx + 1), protocolid, line);
if (!packet)
return -ENOMEM;
packet->header.length = sizeof(struct ipw_control_packet_body);
packet->body.value = (state == 0 ? 0 : 1);
send_packet(hw, prio, &packet->header);
return 0;
}
static int set_DTR(struct ipw_hardware *hw, int priority,
unsigned int channel_idx, int state)
{
if (state != 0)
hw->control_lines[channel_idx] |= IPW_CONTROL_LINE_DTR;
else
hw->control_lines[channel_idx] &= ~IPW_CONTROL_LINE_DTR;
return set_control_line(hw, priority, channel_idx, COMCTRL_DTR, state);
}
static int set_RTS(struct ipw_hardware *hw, int priority,
unsigned int channel_idx, int state)
{
if (state != 0)
hw->control_lines[channel_idx] |= IPW_CONTROL_LINE_RTS;
else
hw->control_lines[channel_idx] &= ~IPW_CONTROL_LINE_RTS;
return set_control_line(hw, priority, channel_idx, COMCTRL_RTS, state);
}
int ipwireless_set_DTR(struct ipw_hardware *hw, unsigned int channel_idx,
int state)
{
return set_DTR(hw, PRIO_CTRL, channel_idx, state);
}
int ipwireless_set_RTS(struct ipw_hardware *hw, unsigned int channel_idx,
int state)
{
return set_RTS(hw, PRIO_CTRL, channel_idx, state);
}
static void __handle_setup_get_version_rsp(struct ipw_hardware *hw)
{
struct ipw_setup_config_packet *config_packet;
struct ipw_setup_config_done_packet *config_done_packet;
struct ipw_setup_open_packet *open_packet;
struct ipw_setup_info_packet *info_packet;
int port;
unsigned int channel_idx;
for (port = 1; port <= NL_NUM_OF_ADDRESSES; port++) {
config_packet = alloc_ctrl_packet(
sizeof(struct ipw_setup_config_packet),
ADDR_SETUP_PROT,
TL_PROTOCOLID_SETUP,
TL_SETUP_SIGNO_CONFIG_MSG);
if (!config_packet)
goto exit_nomem;
config_packet->header.length = sizeof(struct tl_setup_config_msg);
config_packet->body.port_no = port;
config_packet->body.prio_data = PRIO_DATA;
config_packet->body.prio_ctrl = PRIO_CTRL;
send_packet(hw, PRIO_SETUP, &config_packet->header);
}
config_done_packet = alloc_ctrl_packet(
sizeof(struct ipw_setup_config_done_packet),
ADDR_SETUP_PROT,
TL_PROTOCOLID_SETUP,
TL_SETUP_SIGNO_CONFIG_DONE_MSG);
if (!config_done_packet)
goto exit_nomem;
config_done_packet->header.length = sizeof(struct tl_setup_config_done_msg);
send_packet(hw, PRIO_SETUP, &config_done_packet->header);
for (port = 1; port <= NL_NUM_OF_ADDRESSES; port++) {
open_packet = alloc_ctrl_packet(
sizeof(struct ipw_setup_open_packet),
ADDR_SETUP_PROT,
TL_PROTOCOLID_SETUP,
TL_SETUP_SIGNO_OPEN_MSG);
if (!open_packet)
goto exit_nomem;
open_packet->header.length = sizeof(struct tl_setup_open_msg);
open_packet->body.port_no = port;
send_packet(hw, PRIO_SETUP, &open_packet->header);
}
for (channel_idx = 0;
channel_idx < NL_NUM_OF_ADDRESSES; channel_idx++) {
int ret;
ret = set_DTR(hw, PRIO_SETUP, channel_idx,
(hw->control_lines[channel_idx] &
IPW_CONTROL_LINE_DTR) != 0);
if (ret) {
printk(KERN_ERR IPWIRELESS_PCCARD_NAME
": error setting DTR (%d)\n", ret);
return;
}
ret = set_RTS(hw, PRIO_SETUP, channel_idx,
(hw->control_lines [channel_idx] &
IPW_CONTROL_LINE_RTS) != 0);
if (ret) {
printk(KERN_ERR IPWIRELESS_PCCARD_NAME
": error setting RTS (%d)\n", ret);
return;
}
}
info_packet = alloc_ctrl_packet(sizeof(struct ipw_setup_info_packet),
ADDR_SETUP_PROT,
TL_PROTOCOLID_SETUP,
TL_SETUP_SIGNO_INFO_MSG);
if (!info_packet)
goto exit_nomem;
info_packet->header.length = sizeof(struct tl_setup_info_msg);
info_packet->body.driver_type = NDISWAN_DRIVER;
info_packet->body.major_version = NDISWAN_DRIVER_MAJOR_VERSION;
info_packet->body.minor_version = NDISWAN_DRIVER_MINOR_VERSION;
send_packet(hw, PRIO_SETUP, &info_packet->header);
hw->to_setup = 0;
return;
exit_nomem:
printk(KERN_ERR IPWIRELESS_PCCARD_NAME
": not enough memory to alloc control packet\n");
hw->to_setup = -1;
}
static void handle_setup_get_version_rsp(struct ipw_hardware *hw,
unsigned char vers_no)
{
del_timer(&hw->setup_timer);
hw->initializing = 0;
printk(KERN_INFO IPWIRELESS_PCCARD_NAME ": card is ready.\n");
if (vers_no == TL_SETUP_VERSION)
__handle_setup_get_version_rsp(hw);
else
printk(KERN_ERR IPWIRELESS_PCCARD_NAME
": invalid hardware version no %u\n",
(unsigned int) vers_no);
}
static void ipw_send_setup_packet(struct ipw_hardware *hw)
{
struct ipw_setup_get_version_query_packet *ver_packet;
ver_packet = alloc_ctrl_packet(
sizeof(struct ipw_setup_get_version_query_packet),
ADDR_SETUP_PROT, TL_PROTOCOLID_SETUP,
TL_SETUP_SIGNO_GET_VERSION_QRY);
ver_packet->header.length = sizeof(struct tl_setup_get_version_qry);
send_packet(hw, PRIO_SETUP, &ver_packet->header);
}
static void handle_received_SETUP_packet(struct ipw_hardware *hw,
unsigned int address,
const unsigned char *data, int len,
int is_last)
{
const union ipw_setup_rx_msg *rx_msg = (const union ipw_setup_rx_msg *) data;
if (address != ADDR_SETUP_PROT) {
printk(KERN_INFO IPWIRELESS_PCCARD_NAME
": setup packet has bad address %d\n", address);
return;
}
switch (rx_msg->sig_no) {
case TL_SETUP_SIGNO_GET_VERSION_RSP:
if (hw->to_setup)
handle_setup_get_version_rsp(hw,
rx_msg->version_rsp_msg.version);
break;
case TL_SETUP_SIGNO_OPEN_MSG:
if (ipwireless_debug) {
unsigned int channel_idx = rx_msg->open_msg.port_no - 1;
printk(KERN_INFO IPWIRELESS_PCCARD_NAME
": OPEN_MSG [channel %u] reply received\n",
channel_idx);
}
break;
case TL_SETUP_SIGNO_INFO_MSG_ACK:
if (ipwireless_debug)
printk(KERN_DEBUG IPWIRELESS_PCCARD_NAME
": card successfully configured as NDISWAN\n");
break;
case TL_SETUP_SIGNO_REBOOT_MSG:
if (hw->to_setup)
printk(KERN_DEBUG IPWIRELESS_PCCARD_NAME
": Setup not completed - ignoring reboot msg\n");
else {
struct ipw_setup_reboot_msg_ack *packet;
printk(KERN_DEBUG IPWIRELESS_PCCARD_NAME
": Acknowledging REBOOT message\n");
packet = alloc_ctrl_packet(
sizeof(struct ipw_setup_reboot_msg_ack),
ADDR_SETUP_PROT, TL_PROTOCOLID_SETUP,
TL_SETUP_SIGNO_REBOOT_MSG_ACK);
packet->header.length =
sizeof(struct TlSetupRebootMsgAck);
send_packet(hw, PRIO_SETUP, &packet->header);
if (hw->reboot_callback)
hw->reboot_callback(hw->reboot_callback_data);
}
break;
default:
printk(KERN_INFO IPWIRELESS_PCCARD_NAME
": unknown setup message %u received\n",
(unsigned int) rx_msg->sig_no);
}
}
static void do_close_hardware(struct ipw_hardware *hw)
{
unsigned int irqn;
if (hw->hw_version == HW_VERSION_1) {
outw(0, hw->base_port + IOIER);
irqn = inw(hw->base_port + IOIR);
if (irqn & IR_TXINTR)
outw(IR_TXINTR, hw->base_port + IOIR);
if (irqn & IR_RXINTR)
outw(IR_RXINTR, hw->base_port + IOIR);
synchronize_irq(hw->irq);
}
}
struct ipw_hardware *ipwireless_hardware_create(void)
{
int i;
struct ipw_hardware *hw =
kzalloc(sizeof(struct ipw_hardware), GFP_KERNEL);
if (!hw)
return NULL;
hw->irq = -1;
hw->initializing = 1;
hw->tx_ready = 1;
hw->rx_bytes_queued = 0;
hw->rx_pool_size = 0;
hw->last_memtx_serial = (unsigned short) 0xffff;
for (i = 0; i < NL_NUM_OF_PRIORITIES; i++)
INIT_LIST_HEAD(&hw->tx_queue[i]);
INIT_LIST_HEAD(&hw->rx_queue);
INIT_LIST_HEAD(&hw->rx_pool);
spin_lock_init(&hw->lock);
tasklet_init(&hw->tasklet, ipwireless_do_tasklet, (unsigned long) hw);
INIT_WORK(&hw->work_rx, ipw_receive_data_work);
setup_timer(&hw->setup_timer, ipwireless_setup_timer,
(unsigned long) hw);
return hw;
}
void ipwireless_init_hardware_v1(struct ipw_hardware *hw,
unsigned int base_port,
void __iomem *attr_memory,
void __iomem *common_memory,
int is_v2_card,
void (*reboot_callback) (void *data),
void *reboot_callback_data)
{
if (hw->removed) {
hw->removed = 0;
enable_irq(hw->irq);
}
hw->base_port = base_port;
hw->hw_version = (is_v2_card ? HW_VERSION_2 : HW_VERSION_1);
hw->ll_mtu = (hw->hw_version == HW_VERSION_1 ? LL_MTU_V1 : LL_MTU_V2);
hw->memregs_CCR = (struct MEMCCR __iomem *)
((unsigned short __iomem *) attr_memory + 0x200);
hw->memory_info_regs = (struct MEMINFREG __iomem *) common_memory;
hw->memreg_tx = &hw->memory_info_regs->memreg_tx_new;
hw->reboot_callback = reboot_callback;
hw->reboot_callback_data = reboot_callback_data;
}
void ipwireless_init_hardware_v2_v3(struct ipw_hardware *hw)
{
hw->initializing = 1;
hw->init_loops = 0;
printk(KERN_INFO IPWIRELESS_PCCARD_NAME
": waiting for card to start up...\n");
ipwireless_setup_timer((unsigned long) hw);
}
static void ipwireless_setup_timer(unsigned long data)
{
struct ipw_hardware *hw = (struct ipw_hardware *) data;
hw->init_loops++;
if (hw->init_loops == TL_SETUP_MAX_VERSION_QRY &&
hw->hw_version == HW_VERSION_2 &&
hw->memreg_tx == &hw->memory_info_regs->memreg_tx_new) {
printk(KERN_INFO IPWIRELESS_PCCARD_NAME
": failed to startup using TX2, trying TX\n");
hw->memreg_tx = &hw->memory_info_regs->memreg_tx_old;
hw->init_loops = 0;
}
if (hw->init_loops == TL_SETUP_MAX_VERSION_QRY) {
printk(KERN_INFO IPWIRELESS_PCCARD_NAME
": card failed to start up!\n");
hw->initializing = 0;
} else {
if (is_card_present(hw)) {
unsigned long flags;
spin_lock_irqsave(&hw->lock, flags);
hw->to_setup = 1;
hw->tx_ready = 1;
spin_unlock_irqrestore(&hw->lock, flags);
tasklet_schedule(&hw->tasklet);
}
mod_timer(&hw->setup_timer,
jiffies + msecs_to_jiffies(TL_SETUP_VERSION_QRY_TMO));
}
}
void ipwireless_stop_interrupts(struct ipw_hardware *hw)
{
if (!hw->shutting_down) {
hw->shutting_down = 1;
del_timer(&hw->setup_timer);
do_close_hardware(hw);
}
}
void ipwireless_hardware_free(struct ipw_hardware *hw)
{
int i;
struct ipw_rx_packet *rp, *rq;
struct ipw_tx_packet *tp, *tq;
ipwireless_stop_interrupts(hw);
flush_work(&hw->work_rx);
for (i = 0; i < NL_NUM_OF_ADDRESSES; i++)
kfree(hw->packet_assembler[i]);
for (i = 0; i < NL_NUM_OF_PRIORITIES; i++)
list_for_each_entry_safe(tp, tq, &hw->tx_queue[i], queue) {
list_del(&tp->queue);
kfree(tp);
}
list_for_each_entry_safe(rp, rq, &hw->rx_queue, queue) {
list_del(&rp->queue);
kfree(rp);
}
list_for_each_entry_safe(rp, rq, &hw->rx_pool, queue) {
list_del(&rp->queue);
kfree(rp);
}
kfree(hw);
}
void ipwireless_associate_network(struct ipw_hardware *hw,
struct ipw_network *network)
{
hw->network = network;
}
