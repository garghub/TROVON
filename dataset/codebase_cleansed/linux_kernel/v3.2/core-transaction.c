static int try_cancel_split_timeout(struct fw_transaction *t)
{
if (t->is_split_transaction)
return del_timer(&t->split_timeout_timer);
else
return 1;
}
static int close_transaction(struct fw_transaction *transaction,
struct fw_card *card, int rcode)
{
struct fw_transaction *t;
unsigned long flags;
spin_lock_irqsave(&card->lock, flags);
list_for_each_entry(t, &card->transaction_list, link) {
if (t == transaction) {
if (!try_cancel_split_timeout(t)) {
spin_unlock_irqrestore(&card->lock, flags);
goto timed_out;
}
list_del_init(&t->link);
card->tlabel_mask &= ~(1ULL << t->tlabel);
break;
}
}
spin_unlock_irqrestore(&card->lock, flags);
if (&t->link != &card->transaction_list) {
t->callback(card, rcode, NULL, 0, t->callback_data);
return 0;
}
timed_out:
return -ENOENT;
}
int fw_cancel_transaction(struct fw_card *card,
struct fw_transaction *transaction)
{
if (card->driver->cancel_packet(card, &transaction->packet) == 0)
return 0;
return close_transaction(transaction, card, RCODE_CANCELLED);
}
static void split_transaction_timeout_callback(unsigned long data)
{
struct fw_transaction *t = (struct fw_transaction *)data;
struct fw_card *card = t->card;
unsigned long flags;
spin_lock_irqsave(&card->lock, flags);
if (list_empty(&t->link)) {
spin_unlock_irqrestore(&card->lock, flags);
return;
}
list_del(&t->link);
card->tlabel_mask &= ~(1ULL << t->tlabel);
spin_unlock_irqrestore(&card->lock, flags);
t->callback(card, RCODE_CANCELLED, NULL, 0, t->callback_data);
}
static void start_split_transaction_timeout(struct fw_transaction *t,
struct fw_card *card)
{
unsigned long flags;
spin_lock_irqsave(&card->lock, flags);
if (list_empty(&t->link) || WARN_ON(t->is_split_transaction)) {
spin_unlock_irqrestore(&card->lock, flags);
return;
}
t->is_split_transaction = true;
mod_timer(&t->split_timeout_timer,
jiffies + card->split_timeout_jiffies);
spin_unlock_irqrestore(&card->lock, flags);
}
static void transmit_complete_callback(struct fw_packet *packet,
struct fw_card *card, int status)
{
struct fw_transaction *t =
container_of(packet, struct fw_transaction, packet);
switch (status) {
case ACK_COMPLETE:
close_transaction(t, card, RCODE_COMPLETE);
break;
case ACK_PENDING:
start_split_transaction_timeout(t, card);
break;
case ACK_BUSY_X:
case ACK_BUSY_A:
case ACK_BUSY_B:
close_transaction(t, card, RCODE_BUSY);
break;
case ACK_DATA_ERROR:
close_transaction(t, card, RCODE_DATA_ERROR);
break;
case ACK_TYPE_ERROR:
close_transaction(t, card, RCODE_TYPE_ERROR);
break;
default:
close_transaction(t, card, status);
break;
}
}
static void fw_fill_request(struct fw_packet *packet, int tcode, int tlabel,
int destination_id, int source_id, int generation, int speed,
unsigned long long offset, void *payload, size_t length)
{
int ext_tcode;
if (tcode == TCODE_STREAM_DATA) {
packet->header[0] =
HEADER_DATA_LENGTH(length) |
destination_id |
HEADER_TCODE(TCODE_STREAM_DATA);
packet->header_length = 4;
packet->payload = payload;
packet->payload_length = length;
goto common;
}
if (tcode > 0x10) {
ext_tcode = tcode & ~0x10;
tcode = TCODE_LOCK_REQUEST;
} else
ext_tcode = 0;
packet->header[0] =
HEADER_RETRY(RETRY_X) |
HEADER_TLABEL(tlabel) |
HEADER_TCODE(tcode) |
HEADER_DESTINATION(destination_id);
packet->header[1] =
HEADER_OFFSET_HIGH(offset >> 32) | HEADER_SOURCE(source_id);
packet->header[2] =
offset;
switch (tcode) {
case TCODE_WRITE_QUADLET_REQUEST:
packet->header[3] = *(u32 *)payload;
packet->header_length = 16;
packet->payload_length = 0;
break;
case TCODE_LOCK_REQUEST:
case TCODE_WRITE_BLOCK_REQUEST:
packet->header[3] =
HEADER_DATA_LENGTH(length) |
HEADER_EXTENDED_TCODE(ext_tcode);
packet->header_length = 16;
packet->payload = payload;
packet->payload_length = length;
break;
case TCODE_READ_QUADLET_REQUEST:
packet->header_length = 12;
packet->payload_length = 0;
break;
case TCODE_READ_BLOCK_REQUEST:
packet->header[3] =
HEADER_DATA_LENGTH(length) |
HEADER_EXTENDED_TCODE(ext_tcode);
packet->header_length = 16;
packet->payload_length = 0;
break;
default:
WARN(1, "wrong tcode %d\n", tcode);
}
common:
packet->speed = speed;
packet->generation = generation;
packet->ack = 0;
packet->payload_mapped = false;
}
static int allocate_tlabel(struct fw_card *card)
{
int tlabel;
tlabel = card->current_tlabel;
while (card->tlabel_mask & (1ULL << tlabel)) {
tlabel = (tlabel + 1) & 0x3f;
if (tlabel == card->current_tlabel)
return -EBUSY;
}
card->current_tlabel = (tlabel + 1) & 0x3f;
card->tlabel_mask |= 1ULL << tlabel;
return tlabel;
}
void fw_send_request(struct fw_card *card, struct fw_transaction *t, int tcode,
int destination_id, int generation, int speed,
unsigned long long offset, void *payload, size_t length,
fw_transaction_callback_t callback, void *callback_data)
{
unsigned long flags;
int tlabel;
spin_lock_irqsave(&card->lock, flags);
tlabel = allocate_tlabel(card);
if (tlabel < 0) {
spin_unlock_irqrestore(&card->lock, flags);
callback(card, RCODE_SEND_ERROR, NULL, 0, callback_data);
return;
}
t->node_id = destination_id;
t->tlabel = tlabel;
t->card = card;
t->is_split_transaction = false;
setup_timer(&t->split_timeout_timer,
split_transaction_timeout_callback, (unsigned long)t);
t->callback = callback;
t->callback_data = callback_data;
fw_fill_request(&t->packet, tcode, t->tlabel,
destination_id, card->node_id, generation,
speed, offset, payload, length);
t->packet.callback = transmit_complete_callback;
list_add_tail(&t->link, &card->transaction_list);
spin_unlock_irqrestore(&card->lock, flags);
card->driver->send_request(card, &t->packet);
}
static void transaction_callback(struct fw_card *card, int rcode,
void *payload, size_t length, void *data)
{
struct transaction_callback_data *d = data;
if (rcode == RCODE_COMPLETE)
memcpy(d->payload, payload, length);
d->rcode = rcode;
complete(&d->done);
}
int fw_run_transaction(struct fw_card *card, int tcode, int destination_id,
int generation, int speed, unsigned long long offset,
void *payload, size_t length)
{
struct transaction_callback_data d;
struct fw_transaction t;
init_timer_on_stack(&t.split_timeout_timer);
init_completion(&d.done);
d.payload = payload;
fw_send_request(card, &t, tcode, destination_id, generation, speed,
offset, payload, length, transaction_callback, &d);
wait_for_completion(&d.done);
destroy_timer_on_stack(&t.split_timeout_timer);
return d.rcode;
}
static void transmit_phy_packet_callback(struct fw_packet *packet,
struct fw_card *card, int status)
{
complete(&phy_config_done);
}
void fw_send_phy_config(struct fw_card *card,
int node_id, int generation, int gap_count)
{
long timeout = DIV_ROUND_UP(HZ, 10);
u32 data = PHY_IDENTIFIER(PHY_PACKET_CONFIG);
if (node_id != FW_PHY_CONFIG_NO_NODE_ID)
data |= PHY_CONFIG_ROOT_ID(node_id);
if (gap_count == FW_PHY_CONFIG_CURRENT_GAP_COUNT) {
gap_count = card->driver->read_phy_reg(card, 1);
if (gap_count < 0)
return;
gap_count &= 63;
if (gap_count == 63)
return;
}
data |= PHY_CONFIG_GAP_COUNT(gap_count);
mutex_lock(&phy_config_mutex);
phy_config_packet.header[1] = data;
phy_config_packet.header[2] = ~data;
phy_config_packet.generation = generation;
INIT_COMPLETION(phy_config_done);
card->driver->send_request(card, &phy_config_packet);
wait_for_completion_timeout(&phy_config_done, timeout);
mutex_unlock(&phy_config_mutex);
}
static struct fw_address_handler *lookup_overlapping_address_handler(
struct list_head *list, unsigned long long offset, size_t length)
{
struct fw_address_handler *handler;
list_for_each_entry(handler, list, link) {
if (handler->offset < offset + length &&
offset < handler->offset + handler->length)
return handler;
}
return NULL;
}
static bool is_enclosing_handler(struct fw_address_handler *handler,
unsigned long long offset, size_t length)
{
return handler->offset <= offset &&
offset + length <= handler->offset + handler->length;
}
static struct fw_address_handler *lookup_enclosing_address_handler(
struct list_head *list, unsigned long long offset, size_t length)
{
struct fw_address_handler *handler;
list_for_each_entry(handler, list, link) {
if (is_enclosing_handler(handler, offset, length))
return handler;
}
return NULL;
}
static bool is_in_fcp_region(u64 offset, size_t length)
{
return offset >= (CSR_REGISTER_BASE | CSR_FCP_COMMAND) &&
offset + length <= (CSR_REGISTER_BASE | CSR_FCP_END);
}
int fw_core_add_address_handler(struct fw_address_handler *handler,
const struct fw_address_region *region)
{
struct fw_address_handler *other;
unsigned long flags;
int ret = -EBUSY;
if (region->start & 0xffff000000000003ULL ||
region->start >= region->end ||
region->end > 0x0001000000000000ULL ||
handler->length & 3 ||
handler->length == 0)
return -EINVAL;
spin_lock_irqsave(&address_handler_lock, flags);
handler->offset = region->start;
while (handler->offset + handler->length <= region->end) {
if (is_in_fcp_region(handler->offset, handler->length))
other = NULL;
else
other = lookup_overlapping_address_handler
(&address_handler_list,
handler->offset, handler->length);
if (other != NULL) {
handler->offset += other->length;
} else {
list_add_tail(&handler->link, &address_handler_list);
ret = 0;
break;
}
}
spin_unlock_irqrestore(&address_handler_lock, flags);
return ret;
}
void fw_core_remove_address_handler(struct fw_address_handler *handler)
{
unsigned long flags;
spin_lock_irqsave(&address_handler_lock, flags);
list_del(&handler->link);
spin_unlock_irqrestore(&address_handler_lock, flags);
}
static void free_response_callback(struct fw_packet *packet,
struct fw_card *card, int status)
{
struct fw_request *request;
request = container_of(packet, struct fw_request, response);
kfree(request);
}
int fw_get_response_length(struct fw_request *r)
{
int tcode, ext_tcode, data_length;
tcode = HEADER_GET_TCODE(r->request_header[0]);
switch (tcode) {
case TCODE_WRITE_QUADLET_REQUEST:
case TCODE_WRITE_BLOCK_REQUEST:
return 0;
case TCODE_READ_QUADLET_REQUEST:
return 4;
case TCODE_READ_BLOCK_REQUEST:
data_length = HEADER_GET_DATA_LENGTH(r->request_header[3]);
return data_length;
case TCODE_LOCK_REQUEST:
ext_tcode = HEADER_GET_EXTENDED_TCODE(r->request_header[3]);
data_length = HEADER_GET_DATA_LENGTH(r->request_header[3]);
switch (ext_tcode) {
case EXTCODE_FETCH_ADD:
case EXTCODE_LITTLE_ADD:
return data_length;
default:
return data_length / 2;
}
default:
WARN(1, "wrong tcode %d\n", tcode);
return 0;
}
}
void fw_fill_response(struct fw_packet *response, u32 *request_header,
int rcode, void *payload, size_t length)
{
int tcode, tlabel, extended_tcode, source, destination;
tcode = HEADER_GET_TCODE(request_header[0]);
tlabel = HEADER_GET_TLABEL(request_header[0]);
source = HEADER_GET_DESTINATION(request_header[0]);
destination = HEADER_GET_SOURCE(request_header[1]);
extended_tcode = HEADER_GET_EXTENDED_TCODE(request_header[3]);
response->header[0] =
HEADER_RETRY(RETRY_1) |
HEADER_TLABEL(tlabel) |
HEADER_DESTINATION(destination);
response->header[1] =
HEADER_SOURCE(source) |
HEADER_RCODE(rcode);
response->header[2] = 0;
switch (tcode) {
case TCODE_WRITE_QUADLET_REQUEST:
case TCODE_WRITE_BLOCK_REQUEST:
response->header[0] |= HEADER_TCODE(TCODE_WRITE_RESPONSE);
response->header_length = 12;
response->payload_length = 0;
break;
case TCODE_READ_QUADLET_REQUEST:
response->header[0] |=
HEADER_TCODE(TCODE_READ_QUADLET_RESPONSE);
if (payload != NULL)
response->header[3] = *(u32 *)payload;
else
response->header[3] = 0;
response->header_length = 16;
response->payload_length = 0;
break;
case TCODE_READ_BLOCK_REQUEST:
case TCODE_LOCK_REQUEST:
response->header[0] |= HEADER_TCODE(tcode + 2);
response->header[3] =
HEADER_DATA_LENGTH(length) |
HEADER_EXTENDED_TCODE(extended_tcode);
response->header_length = 16;
response->payload = payload;
response->payload_length = length;
break;
default:
WARN(1, "wrong tcode %d\n", tcode);
}
response->payload_mapped = false;
}
static u32 compute_split_timeout_timestamp(struct fw_card *card,
u32 request_timestamp)
{
unsigned int cycles;
u32 timestamp;
cycles = card->split_timeout_cycles;
cycles += request_timestamp & 0x1fff;
timestamp = request_timestamp & ~0x1fff;
timestamp += (cycles / 8000) << 13;
timestamp |= cycles % 8000;
return timestamp;
}
static struct fw_request *allocate_request(struct fw_card *card,
struct fw_packet *p)
{
struct fw_request *request;
u32 *data, length;
int request_tcode;
request_tcode = HEADER_GET_TCODE(p->header[0]);
switch (request_tcode) {
case TCODE_WRITE_QUADLET_REQUEST:
data = &p->header[3];
length = 4;
break;
case TCODE_WRITE_BLOCK_REQUEST:
case TCODE_LOCK_REQUEST:
data = p->payload;
length = HEADER_GET_DATA_LENGTH(p->header[3]);
break;
case TCODE_READ_QUADLET_REQUEST:
data = NULL;
length = 4;
break;
case TCODE_READ_BLOCK_REQUEST:
data = NULL;
length = HEADER_GET_DATA_LENGTH(p->header[3]);
break;
default:
fw_error("ERROR - corrupt request received - %08x %08x %08x\n",
p->header[0], p->header[1], p->header[2]);
return NULL;
}
request = kmalloc(sizeof(*request) + length, GFP_ATOMIC);
if (request == NULL)
return NULL;
request->response.speed = p->speed;
request->response.timestamp =
compute_split_timeout_timestamp(card, p->timestamp);
request->response.generation = p->generation;
request->response.ack = 0;
request->response.callback = free_response_callback;
request->ack = p->ack;
request->length = length;
if (data)
memcpy(request->data, data, length);
memcpy(request->request_header, p->header, sizeof(p->header));
return request;
}
void fw_send_response(struct fw_card *card,
struct fw_request *request, int rcode)
{
if (WARN_ONCE(!request, "invalid for FCP address handlers"))
return;
if (request->ack != ACK_PENDING ||
HEADER_DESTINATION_IS_BROADCAST(request->request_header[0])) {
kfree(request);
return;
}
if (rcode == RCODE_COMPLETE)
fw_fill_response(&request->response, request->request_header,
rcode, request->data,
fw_get_response_length(request));
else
fw_fill_response(&request->response, request->request_header,
rcode, NULL, 0);
card->driver->send_response(card, &request->response);
}
static void handle_exclusive_region_request(struct fw_card *card,
struct fw_packet *p,
struct fw_request *request,
unsigned long long offset)
{
struct fw_address_handler *handler;
unsigned long flags;
int tcode, destination, source;
destination = HEADER_GET_DESTINATION(p->header[0]);
source = HEADER_GET_SOURCE(p->header[1]);
tcode = HEADER_GET_TCODE(p->header[0]);
if (tcode == TCODE_LOCK_REQUEST)
tcode = 0x10 + HEADER_GET_EXTENDED_TCODE(p->header[3]);
spin_lock_irqsave(&address_handler_lock, flags);
handler = lookup_enclosing_address_handler(&address_handler_list,
offset, request->length);
spin_unlock_irqrestore(&address_handler_lock, flags);
if (handler == NULL)
fw_send_response(card, request, RCODE_ADDRESS_ERROR);
else
handler->address_callback(card, request,
tcode, destination, source,
p->generation, offset,
request->data, request->length,
handler->callback_data);
}
static void handle_fcp_region_request(struct fw_card *card,
struct fw_packet *p,
struct fw_request *request,
unsigned long long offset)
{
struct fw_address_handler *handler;
unsigned long flags;
int tcode, destination, source;
if ((offset != (CSR_REGISTER_BASE | CSR_FCP_COMMAND) &&
offset != (CSR_REGISTER_BASE | CSR_FCP_RESPONSE)) ||
request->length > 0x200) {
fw_send_response(card, request, RCODE_ADDRESS_ERROR);
return;
}
tcode = HEADER_GET_TCODE(p->header[0]);
destination = HEADER_GET_DESTINATION(p->header[0]);
source = HEADER_GET_SOURCE(p->header[1]);
if (tcode != TCODE_WRITE_QUADLET_REQUEST &&
tcode != TCODE_WRITE_BLOCK_REQUEST) {
fw_send_response(card, request, RCODE_TYPE_ERROR);
return;
}
spin_lock_irqsave(&address_handler_lock, flags);
list_for_each_entry(handler, &address_handler_list, link) {
if (is_enclosing_handler(handler, offset, request->length))
handler->address_callback(card, NULL, tcode,
destination, source,
p->generation, offset,
request->data,
request->length,
handler->callback_data);
}
spin_unlock_irqrestore(&address_handler_lock, flags);
fw_send_response(card, request, RCODE_COMPLETE);
}
void fw_core_handle_request(struct fw_card *card, struct fw_packet *p)
{
struct fw_request *request;
unsigned long long offset;
if (p->ack != ACK_PENDING && p->ack != ACK_COMPLETE)
return;
if (TCODE_IS_LINK_INTERNAL(HEADER_GET_TCODE(p->header[0]))) {
fw_cdev_handle_phy_packet(card, p);
return;
}
request = allocate_request(card, p);
if (request == NULL) {
return;
}
offset = ((u64)HEADER_GET_OFFSET_HIGH(p->header[1]) << 32) |
p->header[2];
if (!is_in_fcp_region(offset, request->length))
handle_exclusive_region_request(card, p, request, offset);
else
handle_fcp_region_request(card, p, request, offset);
}
void fw_core_handle_response(struct fw_card *card, struct fw_packet *p)
{
struct fw_transaction *t;
unsigned long flags;
u32 *data;
size_t data_length;
int tcode, tlabel, source, rcode;
tcode = HEADER_GET_TCODE(p->header[0]);
tlabel = HEADER_GET_TLABEL(p->header[0]);
source = HEADER_GET_SOURCE(p->header[1]);
rcode = HEADER_GET_RCODE(p->header[1]);
spin_lock_irqsave(&card->lock, flags);
list_for_each_entry(t, &card->transaction_list, link) {
if (t->node_id == source && t->tlabel == tlabel) {
if (!try_cancel_split_timeout(t)) {
spin_unlock_irqrestore(&card->lock, flags);
goto timed_out;
}
list_del_init(&t->link);
card->tlabel_mask &= ~(1ULL << t->tlabel);
break;
}
}
spin_unlock_irqrestore(&card->lock, flags);
if (&t->link == &card->transaction_list) {
timed_out:
fw_notify("Unsolicited response (source %x, tlabel %x)\n",
source, tlabel);
return;
}
switch (tcode) {
case TCODE_READ_QUADLET_RESPONSE:
data = (u32 *) &p->header[3];
data_length = 4;
break;
case TCODE_WRITE_RESPONSE:
data = NULL;
data_length = 0;
break;
case TCODE_READ_BLOCK_RESPONSE:
case TCODE_LOCK_RESPONSE:
data = p->payload;
data_length = HEADER_GET_DATA_LENGTH(p->header[3]);
break;
default:
data = NULL;
data_length = 0;
break;
}
card->driver->cancel_packet(card, &t->packet);
t->callback(card, rcode, data, data_length, t->callback_data);
}
static void handle_topology_map(struct fw_card *card, struct fw_request *request,
int tcode, int destination, int source, int generation,
unsigned long long offset, void *payload, size_t length,
void *callback_data)
{
int start;
if (!TCODE_IS_READ_REQUEST(tcode)) {
fw_send_response(card, request, RCODE_TYPE_ERROR);
return;
}
if ((offset & 3) > 0 || (length & 3) > 0) {
fw_send_response(card, request, RCODE_ADDRESS_ERROR);
return;
}
start = (offset - topology_map_region.start) / 4;
memcpy(payload, &card->topology_map[start], length);
fw_send_response(card, request, RCODE_COMPLETE);
}
static void update_split_timeout(struct fw_card *card)
{
unsigned int cycles;
cycles = card->split_timeout_hi * 8000 + (card->split_timeout_lo >> 19);
cycles = clamp(cycles, 800u, 3u * 8000u);
card->split_timeout_cycles = cycles;
card->split_timeout_jiffies = DIV_ROUND_UP(cycles * HZ, 8000);
}
static void handle_registers(struct fw_card *card, struct fw_request *request,
int tcode, int destination, int source, int generation,
unsigned long long offset, void *payload, size_t length,
void *callback_data)
{
int reg = offset & ~CSR_REGISTER_BASE;
__be32 *data = payload;
int rcode = RCODE_COMPLETE;
unsigned long flags;
switch (reg) {
case CSR_PRIORITY_BUDGET:
if (!card->priority_budget_implemented) {
rcode = RCODE_ADDRESS_ERROR;
break;
}
case CSR_NODE_IDS:
case CSR_STATE_CLEAR:
case CSR_STATE_SET:
case CSR_CYCLE_TIME:
case CSR_BUS_TIME:
case CSR_BUSY_TIMEOUT:
if (tcode == TCODE_READ_QUADLET_REQUEST)
*data = cpu_to_be32(card->driver->read_csr(card, reg));
else if (tcode == TCODE_WRITE_QUADLET_REQUEST)
card->driver->write_csr(card, reg, be32_to_cpu(*data));
else
rcode = RCODE_TYPE_ERROR;
break;
case CSR_RESET_START:
if (tcode == TCODE_WRITE_QUADLET_REQUEST)
card->driver->write_csr(card, CSR_STATE_CLEAR,
CSR_STATE_BIT_ABDICATE);
else
rcode = RCODE_TYPE_ERROR;
break;
case CSR_SPLIT_TIMEOUT_HI:
if (tcode == TCODE_READ_QUADLET_REQUEST) {
*data = cpu_to_be32(card->split_timeout_hi);
} else if (tcode == TCODE_WRITE_QUADLET_REQUEST) {
spin_lock_irqsave(&card->lock, flags);
card->split_timeout_hi = be32_to_cpu(*data) & 7;
update_split_timeout(card);
spin_unlock_irqrestore(&card->lock, flags);
} else {
rcode = RCODE_TYPE_ERROR;
}
break;
case CSR_SPLIT_TIMEOUT_LO:
if (tcode == TCODE_READ_QUADLET_REQUEST) {
*data = cpu_to_be32(card->split_timeout_lo);
} else if (tcode == TCODE_WRITE_QUADLET_REQUEST) {
spin_lock_irqsave(&card->lock, flags);
card->split_timeout_lo =
be32_to_cpu(*data) & 0xfff80000;
update_split_timeout(card);
spin_unlock_irqrestore(&card->lock, flags);
} else {
rcode = RCODE_TYPE_ERROR;
}
break;
case CSR_MAINT_UTILITY:
if (tcode == TCODE_READ_QUADLET_REQUEST)
*data = card->maint_utility_register;
else if (tcode == TCODE_WRITE_QUADLET_REQUEST)
card->maint_utility_register = *data;
else
rcode = RCODE_TYPE_ERROR;
break;
case CSR_BROADCAST_CHANNEL:
if (tcode == TCODE_READ_QUADLET_REQUEST)
*data = cpu_to_be32(card->broadcast_channel);
else if (tcode == TCODE_WRITE_QUADLET_REQUEST)
card->broadcast_channel =
(be32_to_cpu(*data) & BROADCAST_CHANNEL_VALID) |
BROADCAST_CHANNEL_INITIAL;
else
rcode = RCODE_TYPE_ERROR;
break;
case CSR_BUS_MANAGER_ID:
case CSR_BANDWIDTH_AVAILABLE:
case CSR_CHANNELS_AVAILABLE_HI:
case CSR_CHANNELS_AVAILABLE_LO:
BUG();
break;
default:
rcode = RCODE_ADDRESS_ERROR;
break;
}
fw_send_response(card, request, rcode);
}
static int __init fw_core_init(void)
{
int ret;
fw_workqueue = alloc_workqueue("firewire",
WQ_NON_REENTRANT | WQ_MEM_RECLAIM, 0);
if (!fw_workqueue)
return -ENOMEM;
ret = bus_register(&fw_bus_type);
if (ret < 0) {
destroy_workqueue(fw_workqueue);
return ret;
}
fw_cdev_major = register_chrdev(0, "firewire", &fw_device_ops);
if (fw_cdev_major < 0) {
bus_unregister(&fw_bus_type);
destroy_workqueue(fw_workqueue);
return fw_cdev_major;
}
fw_core_add_address_handler(&topology_map, &topology_map_region);
fw_core_add_address_handler(&registers, &registers_region);
fw_core_add_descriptor(&vendor_id_descriptor);
fw_core_add_descriptor(&model_id_descriptor);
return 0;
}
static void __exit fw_core_cleanup(void)
{
unregister_chrdev(fw_cdev_major, "firewire");
bus_unregister(&fw_bus_type);
destroy_workqueue(fw_workqueue);
idr_destroy(&fw_device_idr);
}
