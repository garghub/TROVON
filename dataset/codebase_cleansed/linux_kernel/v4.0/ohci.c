static inline struct fw_ohci *fw_ohci(struct fw_card *card)
{
return container_of(card, struct fw_ohci, card);
}
static void log_irqs(struct fw_ohci *ohci, u32 evt)
{
if (likely(!(param_debug &
(OHCI_PARAM_DEBUG_IRQS | OHCI_PARAM_DEBUG_BUSRESETS))))
return;
if (!(param_debug & OHCI_PARAM_DEBUG_IRQS) &&
!(evt & OHCI1394_busReset))
return;
ohci_notice(ohci, "IRQ %08x%s%s%s%s%s%s%s%s%s%s%s%s%s%s%s\n", evt,
evt & OHCI1394_selfIDComplete ? " selfID" : "",
evt & OHCI1394_RQPkt ? " AR_req" : "",
evt & OHCI1394_RSPkt ? " AR_resp" : "",
evt & OHCI1394_reqTxComplete ? " AT_req" : "",
evt & OHCI1394_respTxComplete ? " AT_resp" : "",
evt & OHCI1394_isochRx ? " IR" : "",
evt & OHCI1394_isochTx ? " IT" : "",
evt & OHCI1394_postedWriteErr ? " postedWriteErr" : "",
evt & OHCI1394_cycleTooLong ? " cycleTooLong" : "",
evt & OHCI1394_cycle64Seconds ? " cycle64Seconds" : "",
evt & OHCI1394_cycleInconsistent ? " cycleInconsistent" : "",
evt & OHCI1394_regAccessFail ? " regAccessFail" : "",
evt & OHCI1394_unrecoverableError ? " unrecoverableError" : "",
evt & OHCI1394_busReset ? " busReset" : "",
evt & ~(OHCI1394_selfIDComplete | OHCI1394_RQPkt |
OHCI1394_RSPkt | OHCI1394_reqTxComplete |
OHCI1394_respTxComplete | OHCI1394_isochRx |
OHCI1394_isochTx | OHCI1394_postedWriteErr |
OHCI1394_cycleTooLong | OHCI1394_cycle64Seconds |
OHCI1394_cycleInconsistent |
OHCI1394_regAccessFail | OHCI1394_busReset)
? " ?" : "");
}
static char _p(u32 *s, int shift)
{
return port[*s >> shift & 3];
}
static void log_selfids(struct fw_ohci *ohci, int generation, int self_id_count)
{
u32 *s;
if (likely(!(param_debug & OHCI_PARAM_DEBUG_SELFIDS)))
return;
ohci_notice(ohci, "%d selfIDs, generation %d, local node ID %04x\n",
self_id_count, generation, ohci->node_id);
for (s = ohci->self_id_buffer; self_id_count--; ++s)
if ((*s & 1 << 23) == 0)
ohci_notice(ohci,
"selfID 0: %08x, phy %d [%c%c%c] %s gc=%d %s %s%s%s\n",
*s, *s >> 24 & 63, _p(s, 6), _p(s, 4), _p(s, 2),
speed[*s >> 14 & 3], *s >> 16 & 63,
power[*s >> 8 & 7], *s >> 22 & 1 ? "L" : "",
*s >> 11 & 1 ? "c" : "", *s & 2 ? "i" : "");
else
ohci_notice(ohci,
"selfID n: %08x, phy %d [%c%c%c%c%c%c%c%c]\n",
*s, *s >> 24 & 63,
_p(s, 16), _p(s, 14), _p(s, 12), _p(s, 10),
_p(s, 8), _p(s, 6), _p(s, 4), _p(s, 2));
}
static void log_ar_at_event(struct fw_ohci *ohci,
char dir, int speed, u32 *header, int evt)
{
int tcode = header[0] >> 4 & 0xf;
char specific[12];
if (likely(!(param_debug & OHCI_PARAM_DEBUG_AT_AR)))
return;
if (unlikely(evt >= ARRAY_SIZE(evts)))
evt = 0x1f;
if (evt == OHCI1394_evt_bus_reset) {
ohci_notice(ohci, "A%c evt_bus_reset, generation %d\n",
dir, (header[2] >> 16) & 0xff);
return;
}
switch (tcode) {
case 0x0: case 0x6: case 0x8:
snprintf(specific, sizeof(specific), " = %08x",
be32_to_cpu((__force __be32)header[3]));
break;
case 0x1: case 0x5: case 0x7: case 0x9: case 0xb:
snprintf(specific, sizeof(specific), " %x,%x",
header[3] >> 16, header[3] & 0xffff);
break;
default:
specific[0] = '\0';
}
switch (tcode) {
case 0xa:
ohci_notice(ohci, "A%c %s, %s\n",
dir, evts[evt], tcodes[tcode]);
break;
case 0xe:
ohci_notice(ohci, "A%c %s, PHY %08x %08x\n",
dir, evts[evt], header[1], header[2]);
break;
case 0x0: case 0x1: case 0x4: case 0x5: case 0x9:
ohci_notice(ohci,
"A%c spd %x tl %02x, %04x -> %04x, %s, %s, %04x%08x%s\n",
dir, speed, header[0] >> 10 & 0x3f,
header[1] >> 16, header[0] >> 16, evts[evt],
tcodes[tcode], header[1] & 0xffff, header[2], specific);
break;
default:
ohci_notice(ohci,
"A%c spd %x tl %02x, %04x -> %04x, %s, %s%s\n",
dir, speed, header[0] >> 10 & 0x3f,
header[1] >> 16, header[0] >> 16, evts[evt],
tcodes[tcode], specific);
}
}
static inline void reg_write(const struct fw_ohci *ohci, int offset, u32 data)
{
writel(data, ohci->registers + offset);
}
static inline u32 reg_read(const struct fw_ohci *ohci, int offset)
{
return readl(ohci->registers + offset);
}
static inline void flush_writes(const struct fw_ohci *ohci)
{
reg_read(ohci, OHCI1394_Version);
}
static int read_phy_reg(struct fw_ohci *ohci, int addr)
{
u32 val;
int i;
reg_write(ohci, OHCI1394_PhyControl, OHCI1394_PhyControl_Read(addr));
for (i = 0; i < 3 + 100; i++) {
val = reg_read(ohci, OHCI1394_PhyControl);
if (!~val)
return -ENODEV;
if (val & OHCI1394_PhyControl_ReadDone)
return OHCI1394_PhyControl_ReadData(val);
if (i >= 3)
msleep(1);
}
ohci_err(ohci, "failed to read phy reg %d\n", addr);
dump_stack();
return -EBUSY;
}
static int write_phy_reg(const struct fw_ohci *ohci, int addr, u32 val)
{
int i;
reg_write(ohci, OHCI1394_PhyControl,
OHCI1394_PhyControl_Write(addr, val));
for (i = 0; i < 3 + 100; i++) {
val = reg_read(ohci, OHCI1394_PhyControl);
if (!~val)
return -ENODEV;
if (!(val & OHCI1394_PhyControl_WritePending))
return 0;
if (i >= 3)
msleep(1);
}
ohci_err(ohci, "failed to write phy reg %d, val %u\n", addr, val);
dump_stack();
return -EBUSY;
}
static int update_phy_reg(struct fw_ohci *ohci, int addr,
int clear_bits, int set_bits)
{
int ret = read_phy_reg(ohci, addr);
if (ret < 0)
return ret;
if (addr == 5)
clear_bits |= PHY_INT_STATUS_BITS;
return write_phy_reg(ohci, addr, (ret & ~clear_bits) | set_bits);
}
static int read_paged_phy_reg(struct fw_ohci *ohci, int page, int addr)
{
int ret;
ret = update_phy_reg(ohci, 7, PHY_PAGE_SELECT, page << 5);
if (ret < 0)
return ret;
return read_phy_reg(ohci, addr);
}
static int ohci_read_phy_reg(struct fw_card *card, int addr)
{
struct fw_ohci *ohci = fw_ohci(card);
int ret;
mutex_lock(&ohci->phy_reg_mutex);
ret = read_phy_reg(ohci, addr);
mutex_unlock(&ohci->phy_reg_mutex);
return ret;
}
static int ohci_update_phy_reg(struct fw_card *card, int addr,
int clear_bits, int set_bits)
{
struct fw_ohci *ohci = fw_ohci(card);
int ret;
mutex_lock(&ohci->phy_reg_mutex);
ret = update_phy_reg(ohci, addr, clear_bits, set_bits);
mutex_unlock(&ohci->phy_reg_mutex);
return ret;
}
static inline dma_addr_t ar_buffer_bus(struct ar_context *ctx, unsigned int i)
{
return page_private(ctx->pages[i]);
}
static void ar_context_link_page(struct ar_context *ctx, unsigned int index)
{
struct descriptor *d;
d = &ctx->descriptors[index];
d->branch_address &= cpu_to_le32(~0xf);
d->res_count = cpu_to_le16(PAGE_SIZE);
d->transfer_status = 0;
wmb();
d = &ctx->descriptors[ctx->last_buffer_index];
d->branch_address |= cpu_to_le32(1);
ctx->last_buffer_index = index;
reg_write(ctx->ohci, CONTROL_SET(ctx->regs), CONTEXT_WAKE);
}
static void ar_context_release(struct ar_context *ctx)
{
unsigned int i;
vunmap(ctx->buffer);
for (i = 0; i < AR_BUFFERS; i++)
if (ctx->pages[i]) {
dma_unmap_page(ctx->ohci->card.device,
ar_buffer_bus(ctx, i),
PAGE_SIZE, DMA_FROM_DEVICE);
__free_page(ctx->pages[i]);
}
}
static void ar_context_abort(struct ar_context *ctx, const char *error_msg)
{
struct fw_ohci *ohci = ctx->ohci;
if (reg_read(ohci, CONTROL_CLEAR(ctx->regs)) & CONTEXT_RUN) {
reg_write(ohci, CONTROL_CLEAR(ctx->regs), CONTEXT_RUN);
flush_writes(ohci);
ohci_err(ohci, "AR error: %s; DMA stopped\n", error_msg);
}
}
static inline unsigned int ar_next_buffer_index(unsigned int index)
{
return (index + 1) % AR_BUFFERS;
}
static inline unsigned int ar_first_buffer_index(struct ar_context *ctx)
{
return ar_next_buffer_index(ctx->last_buffer_index);
}
static unsigned int ar_search_last_active_buffer(struct ar_context *ctx,
unsigned int *buffer_offset)
{
unsigned int i, next_i, last = ctx->last_buffer_index;
__le16 res_count, next_res_count;
i = ar_first_buffer_index(ctx);
res_count = ACCESS_ONCE(ctx->descriptors[i].res_count);
while (i != last && res_count == 0) {
next_i = ar_next_buffer_index(i);
rmb();
next_res_count = ACCESS_ONCE(
ctx->descriptors[next_i].res_count);
if (next_res_count == cpu_to_le16(PAGE_SIZE)) {
if (MAX_AR_PACKET_SIZE > PAGE_SIZE && i != last) {
next_i = ar_next_buffer_index(next_i);
rmb();
next_res_count = ACCESS_ONCE(
ctx->descriptors[next_i].res_count);
if (next_res_count != cpu_to_le16(PAGE_SIZE))
goto next_buffer_is_active;
}
break;
}
next_buffer_is_active:
i = next_i;
res_count = next_res_count;
}
rmb();
*buffer_offset = PAGE_SIZE - le16_to_cpu(res_count);
if (*buffer_offset > PAGE_SIZE) {
*buffer_offset = 0;
ar_context_abort(ctx, "corrupted descriptor");
}
return i;
}
static void ar_sync_buffers_for_cpu(struct ar_context *ctx,
unsigned int end_buffer_index,
unsigned int end_buffer_offset)
{
unsigned int i;
i = ar_first_buffer_index(ctx);
while (i != end_buffer_index) {
dma_sync_single_for_cpu(ctx->ohci->card.device,
ar_buffer_bus(ctx, i),
PAGE_SIZE, DMA_FROM_DEVICE);
i = ar_next_buffer_index(i);
}
if (end_buffer_offset > 0)
dma_sync_single_for_cpu(ctx->ohci->card.device,
ar_buffer_bus(ctx, i),
end_buffer_offset, DMA_FROM_DEVICE);
}
static __le32 *handle_ar_packet(struct ar_context *ctx, __le32 *buffer)
{
struct fw_ohci *ohci = ctx->ohci;
struct fw_packet p;
u32 status, length, tcode;
int evt;
p.header[0] = cond_le32_to_cpu(buffer[0]);
p.header[1] = cond_le32_to_cpu(buffer[1]);
p.header[2] = cond_le32_to_cpu(buffer[2]);
tcode = (p.header[0] >> 4) & 0x0f;
switch (tcode) {
case TCODE_WRITE_QUADLET_REQUEST:
case TCODE_READ_QUADLET_RESPONSE:
p.header[3] = (__force __u32) buffer[3];
p.header_length = 16;
p.payload_length = 0;
break;
case TCODE_READ_BLOCK_REQUEST :
p.header[3] = cond_le32_to_cpu(buffer[3]);
p.header_length = 16;
p.payload_length = 0;
break;
case TCODE_WRITE_BLOCK_REQUEST:
case TCODE_READ_BLOCK_RESPONSE:
case TCODE_LOCK_REQUEST:
case TCODE_LOCK_RESPONSE:
p.header[3] = cond_le32_to_cpu(buffer[3]);
p.header_length = 16;
p.payload_length = p.header[3] >> 16;
if (p.payload_length > MAX_ASYNC_PAYLOAD) {
ar_context_abort(ctx, "invalid packet length");
return NULL;
}
break;
case TCODE_WRITE_RESPONSE:
case TCODE_READ_QUADLET_REQUEST:
case OHCI_TCODE_PHY_PACKET:
p.header_length = 12;
p.payload_length = 0;
break;
default:
ar_context_abort(ctx, "invalid tcode");
return NULL;
}
p.payload = (void *) buffer + p.header_length;
length = (p.header_length + p.payload_length + 3) / 4;
status = cond_le32_to_cpu(buffer[length]);
evt = (status >> 16) & 0x1f;
p.ack = evt - 16;
p.speed = (status >> 21) & 0x7;
p.timestamp = status & 0xffff;
p.generation = ohci->request_generation;
log_ar_at_event(ohci, 'R', p.speed, p.header, evt);
if (evt == OHCI1394_evt_no_status &&
(p.header[0] & 0xff) == (OHCI1394_phy_tcode << 4))
p.ack = ACK_COMPLETE;
if (evt == OHCI1394_evt_bus_reset) {
if (!(ohci->quirks & QUIRK_RESET_PACKET))
ohci->request_generation = (p.header[2] >> 16) & 0xff;
} else if (ctx == &ohci->ar_request_ctx) {
fw_core_handle_request(&ohci->card, &p);
} else {
fw_core_handle_response(&ohci->card, &p);
}
return buffer + length + 1;
}
static void *handle_ar_packets(struct ar_context *ctx, void *p, void *end)
{
void *next;
while (p < end) {
next = handle_ar_packet(ctx, p);
if (!next)
return p;
p = next;
}
return p;
}
static void ar_recycle_buffers(struct ar_context *ctx, unsigned int end_buffer)
{
unsigned int i;
i = ar_first_buffer_index(ctx);
while (i != end_buffer) {
dma_sync_single_for_device(ctx->ohci->card.device,
ar_buffer_bus(ctx, i),
PAGE_SIZE, DMA_FROM_DEVICE);
ar_context_link_page(ctx, i);
i = ar_next_buffer_index(i);
}
}
static void ar_context_tasklet(unsigned long data)
{
struct ar_context *ctx = (struct ar_context *)data;
unsigned int end_buffer_index, end_buffer_offset;
void *p, *end;
p = ctx->pointer;
if (!p)
return;
end_buffer_index = ar_search_last_active_buffer(ctx,
&end_buffer_offset);
ar_sync_buffers_for_cpu(ctx, end_buffer_index, end_buffer_offset);
end = ctx->buffer + end_buffer_index * PAGE_SIZE + end_buffer_offset;
if (end_buffer_index < ar_first_buffer_index(ctx)) {
void *buffer_end = ctx->buffer + AR_BUFFERS * PAGE_SIZE;
p = handle_ar_packets(ctx, p, buffer_end);
if (p < buffer_end)
goto error;
p -= AR_BUFFERS * PAGE_SIZE;
}
p = handle_ar_packets(ctx, p, end);
if (p != end) {
if (p > end)
ar_context_abort(ctx, "inconsistent descriptor");
goto error;
}
ctx->pointer = p;
ar_recycle_buffers(ctx, end_buffer_index);
return;
error:
ctx->pointer = NULL;
}
static int ar_context_init(struct ar_context *ctx, struct fw_ohci *ohci,
unsigned int descriptors_offset, u32 regs)
{
unsigned int i;
dma_addr_t dma_addr;
struct page *pages[AR_BUFFERS + AR_WRAPAROUND_PAGES];
struct descriptor *d;
ctx->regs = regs;
ctx->ohci = ohci;
tasklet_init(&ctx->tasklet, ar_context_tasklet, (unsigned long)ctx);
for (i = 0; i < AR_BUFFERS; i++) {
ctx->pages[i] = alloc_page(GFP_KERNEL | GFP_DMA32);
if (!ctx->pages[i])
goto out_of_memory;
dma_addr = dma_map_page(ohci->card.device, ctx->pages[i],
0, PAGE_SIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(ohci->card.device, dma_addr)) {
__free_page(ctx->pages[i]);
ctx->pages[i] = NULL;
goto out_of_memory;
}
set_page_private(ctx->pages[i], dma_addr);
}
for (i = 0; i < AR_BUFFERS; i++)
pages[i] = ctx->pages[i];
for (i = 0; i < AR_WRAPAROUND_PAGES; i++)
pages[AR_BUFFERS + i] = ctx->pages[i];
ctx->buffer = vmap(pages, ARRAY_SIZE(pages), VM_MAP, PAGE_KERNEL);
if (!ctx->buffer)
goto out_of_memory;
ctx->descriptors = ohci->misc_buffer + descriptors_offset;
ctx->descriptors_bus = ohci->misc_buffer_bus + descriptors_offset;
for (i = 0; i < AR_BUFFERS; i++) {
d = &ctx->descriptors[i];
d->req_count = cpu_to_le16(PAGE_SIZE);
d->control = cpu_to_le16(DESCRIPTOR_INPUT_MORE |
DESCRIPTOR_STATUS |
DESCRIPTOR_BRANCH_ALWAYS);
d->data_address = cpu_to_le32(ar_buffer_bus(ctx, i));
d->branch_address = cpu_to_le32(ctx->descriptors_bus +
ar_next_buffer_index(i) * sizeof(struct descriptor));
}
return 0;
out_of_memory:
ar_context_release(ctx);
return -ENOMEM;
}
static void ar_context_run(struct ar_context *ctx)
{
unsigned int i;
for (i = 0; i < AR_BUFFERS; i++)
ar_context_link_page(ctx, i);
ctx->pointer = ctx->buffer;
reg_write(ctx->ohci, COMMAND_PTR(ctx->regs), ctx->descriptors_bus | 1);
reg_write(ctx->ohci, CONTROL_SET(ctx->regs), CONTEXT_RUN);
}
static struct descriptor *find_branch_descriptor(struct descriptor *d, int z)
{
__le16 branch;
branch = d->control & cpu_to_le16(DESCRIPTOR_BRANCH_ALWAYS);
if (z == 2 && branch == cpu_to_le16(DESCRIPTOR_BRANCH_ALWAYS))
return d;
else
return d + z - 1;
}
static void context_tasklet(unsigned long data)
{
struct context *ctx = (struct context *) data;
struct descriptor *d, *last;
u32 address;
int z;
struct descriptor_buffer *desc;
desc = list_entry(ctx->buffer_list.next,
struct descriptor_buffer, list);
last = ctx->last;
while (last->branch_address != 0) {
struct descriptor_buffer *old_desc = desc;
address = le32_to_cpu(last->branch_address);
z = address & 0xf;
address &= ~0xf;
ctx->current_bus = address;
if (address < desc->buffer_bus ||
address >= desc->buffer_bus + desc->used)
desc = list_entry(desc->list.next,
struct descriptor_buffer, list);
d = desc->buffer + (address - desc->buffer_bus) / sizeof(*d);
last = find_branch_descriptor(d, z);
if (!ctx->callback(ctx, d, last))
break;
if (old_desc != desc) {
unsigned long flags;
old_desc->used = 0;
spin_lock_irqsave(&ctx->ohci->lock, flags);
list_move_tail(&old_desc->list, &ctx->buffer_list);
spin_unlock_irqrestore(&ctx->ohci->lock, flags);
}
ctx->last = last;
}
}
static int context_add_buffer(struct context *ctx)
{
struct descriptor_buffer *desc;
dma_addr_t uninitialized_var(bus_addr);
int offset;
if (ctx->total_allocation >= 16*1024*1024)
return -ENOMEM;
desc = dma_alloc_coherent(ctx->ohci->card.device, PAGE_SIZE,
&bus_addr, GFP_ATOMIC);
if (!desc)
return -ENOMEM;
offset = (void *)&desc->buffer - (void *)desc;
desc->buffer_size = PAGE_SIZE - offset;
desc->buffer_bus = bus_addr + offset;
desc->used = 0;
list_add_tail(&desc->list, &ctx->buffer_list);
ctx->total_allocation += PAGE_SIZE;
return 0;
}
static int context_init(struct context *ctx, struct fw_ohci *ohci,
u32 regs, descriptor_callback_t callback)
{
ctx->ohci = ohci;
ctx->regs = regs;
ctx->total_allocation = 0;
INIT_LIST_HEAD(&ctx->buffer_list);
if (context_add_buffer(ctx) < 0)
return -ENOMEM;
ctx->buffer_tail = list_entry(ctx->buffer_list.next,
struct descriptor_buffer, list);
tasklet_init(&ctx->tasklet, context_tasklet, (unsigned long)ctx);
ctx->callback = callback;
memset(ctx->buffer_tail->buffer, 0, sizeof(*ctx->buffer_tail->buffer));
ctx->buffer_tail->buffer->control = cpu_to_le16(DESCRIPTOR_OUTPUT_LAST);
ctx->buffer_tail->buffer->transfer_status = cpu_to_le16(0x8011);
ctx->buffer_tail->used += sizeof(*ctx->buffer_tail->buffer);
ctx->last = ctx->buffer_tail->buffer;
ctx->prev = ctx->buffer_tail->buffer;
ctx->prev_z = 1;
return 0;
}
static void context_release(struct context *ctx)
{
struct fw_card *card = &ctx->ohci->card;
struct descriptor_buffer *desc, *tmp;
list_for_each_entry_safe(desc, tmp, &ctx->buffer_list, list)
dma_free_coherent(card->device, PAGE_SIZE, desc,
desc->buffer_bus -
((void *)&desc->buffer - (void *)desc));
}
static struct descriptor *context_get_descriptors(struct context *ctx,
int z, dma_addr_t *d_bus)
{
struct descriptor *d = NULL;
struct descriptor_buffer *desc = ctx->buffer_tail;
if (z * sizeof(*d) > desc->buffer_size)
return NULL;
if (z * sizeof(*d) > desc->buffer_size - desc->used) {
if (desc->list.next == &ctx->buffer_list) {
if (context_add_buffer(ctx) < 0)
return NULL;
}
desc = list_entry(desc->list.next,
struct descriptor_buffer, list);
ctx->buffer_tail = desc;
}
d = desc->buffer + desc->used / sizeof(*d);
memset(d, 0, z * sizeof(*d));
*d_bus = desc->buffer_bus + desc->used;
return d;
}
static void context_run(struct context *ctx, u32 extra)
{
struct fw_ohci *ohci = ctx->ohci;
reg_write(ohci, COMMAND_PTR(ctx->regs),
le32_to_cpu(ctx->last->branch_address));
reg_write(ohci, CONTROL_CLEAR(ctx->regs), ~0);
reg_write(ohci, CONTROL_SET(ctx->regs), CONTEXT_RUN | extra);
ctx->running = true;
flush_writes(ohci);
}
static void context_append(struct context *ctx,
struct descriptor *d, int z, int extra)
{
dma_addr_t d_bus;
struct descriptor_buffer *desc = ctx->buffer_tail;
struct descriptor *d_branch;
d_bus = desc->buffer_bus + (d - desc->buffer) * sizeof(*d);
desc->used += (z + extra) * sizeof(*d);
wmb();
d_branch = find_branch_descriptor(ctx->prev, ctx->prev_z);
d_branch->branch_address = cpu_to_le32(d_bus | z);
if (unlikely(ctx->ohci->quirks & QUIRK_IR_WAKE) &&
d_branch != ctx->prev &&
(ctx->prev->control & cpu_to_le16(DESCRIPTOR_CMD)) ==
cpu_to_le16(DESCRIPTOR_INPUT_MORE)) {
ctx->prev->branch_address = cpu_to_le32(d_bus | z);
}
ctx->prev = d;
ctx->prev_z = z;
}
static void context_stop(struct context *ctx)
{
struct fw_ohci *ohci = ctx->ohci;
u32 reg;
int i;
reg_write(ohci, CONTROL_CLEAR(ctx->regs), CONTEXT_RUN);
ctx->running = false;
for (i = 0; i < 1000; i++) {
reg = reg_read(ohci, CONTROL_SET(ctx->regs));
if ((reg & CONTEXT_ACTIVE) == 0)
return;
if (i)
udelay(10);
}
ohci_err(ohci, "DMA context still active (0x%08x)\n", reg);
}
static int at_context_queue_packet(struct context *ctx,
struct fw_packet *packet)
{
struct fw_ohci *ohci = ctx->ohci;
dma_addr_t d_bus, uninitialized_var(payload_bus);
struct driver_data *driver_data;
struct descriptor *d, *last;
__le32 *header;
int z, tcode;
d = context_get_descriptors(ctx, 4, &d_bus);
if (d == NULL) {
packet->ack = RCODE_SEND_ERROR;
return -1;
}
d[0].control = cpu_to_le16(DESCRIPTOR_KEY_IMMEDIATE);
d[0].res_count = cpu_to_le16(packet->timestamp);
tcode = (packet->header[0] >> 4) & 0x0f;
header = (__le32 *) &d[1];
switch (tcode) {
case TCODE_WRITE_QUADLET_REQUEST:
case TCODE_WRITE_BLOCK_REQUEST:
case TCODE_WRITE_RESPONSE:
case TCODE_READ_QUADLET_REQUEST:
case TCODE_READ_BLOCK_REQUEST:
case TCODE_READ_QUADLET_RESPONSE:
case TCODE_READ_BLOCK_RESPONSE:
case TCODE_LOCK_REQUEST:
case TCODE_LOCK_RESPONSE:
header[0] = cpu_to_le32((packet->header[0] & 0xffff) |
(packet->speed << 16));
header[1] = cpu_to_le32((packet->header[1] & 0xffff) |
(packet->header[0] & 0xffff0000));
header[2] = cpu_to_le32(packet->header[2]);
if (TCODE_IS_BLOCK_PACKET(tcode))
header[3] = cpu_to_le32(packet->header[3]);
else
header[3] = (__force __le32) packet->header[3];
d[0].req_count = cpu_to_le16(packet->header_length);
break;
case TCODE_LINK_INTERNAL:
header[0] = cpu_to_le32((OHCI1394_phy_tcode << 4) |
(packet->speed << 16));
header[1] = cpu_to_le32(packet->header[1]);
header[2] = cpu_to_le32(packet->header[2]);
d[0].req_count = cpu_to_le16(12);
if (is_ping_packet(&packet->header[1]))
d[0].control |= cpu_to_le16(DESCRIPTOR_PING);
break;
case TCODE_STREAM_DATA:
header[0] = cpu_to_le32((packet->header[0] & 0xffff) |
(packet->speed << 16));
header[1] = cpu_to_le32(packet->header[0] & 0xffff0000);
d[0].req_count = cpu_to_le16(8);
break;
default:
packet->ack = RCODE_SEND_ERROR;
return -1;
}
BUILD_BUG_ON(sizeof(struct driver_data) > sizeof(struct descriptor));
driver_data = (struct driver_data *) &d[3];
driver_data->packet = packet;
packet->driver_data = driver_data;
if (packet->payload_length > 0) {
if (packet->payload_length > sizeof(driver_data->inline_data)) {
payload_bus = dma_map_single(ohci->card.device,
packet->payload,
packet->payload_length,
DMA_TO_DEVICE);
if (dma_mapping_error(ohci->card.device, payload_bus)) {
packet->ack = RCODE_SEND_ERROR;
return -1;
}
packet->payload_bus = payload_bus;
packet->payload_mapped = true;
} else {
memcpy(driver_data->inline_data, packet->payload,
packet->payload_length);
payload_bus = d_bus + 3 * sizeof(*d);
}
d[2].req_count = cpu_to_le16(packet->payload_length);
d[2].data_address = cpu_to_le32(payload_bus);
last = &d[2];
z = 3;
} else {
last = &d[0];
z = 2;
}
last->control |= cpu_to_le16(DESCRIPTOR_OUTPUT_LAST |
DESCRIPTOR_IRQ_ALWAYS |
DESCRIPTOR_BRANCH_ALWAYS);
if (ohci->generation != packet->generation) {
if (packet->payload_mapped)
dma_unmap_single(ohci->card.device, payload_bus,
packet->payload_length, DMA_TO_DEVICE);
packet->ack = RCODE_GENERATION;
return -1;
}
context_append(ctx, d, z, 4 - z);
if (ctx->running)
reg_write(ohci, CONTROL_SET(ctx->regs), CONTEXT_WAKE);
else
context_run(ctx, 0);
return 0;
}
static void at_context_flush(struct context *ctx)
{
tasklet_disable(&ctx->tasklet);
ctx->flushing = true;
context_tasklet((unsigned long)ctx);
ctx->flushing = false;
tasklet_enable(&ctx->tasklet);
}
static int handle_at_packet(struct context *context,
struct descriptor *d,
struct descriptor *last)
{
struct driver_data *driver_data;
struct fw_packet *packet;
struct fw_ohci *ohci = context->ohci;
int evt;
if (last->transfer_status == 0 && !context->flushing)
return 0;
driver_data = (struct driver_data *) &d[3];
packet = driver_data->packet;
if (packet == NULL)
return 1;
if (packet->payload_mapped)
dma_unmap_single(ohci->card.device, packet->payload_bus,
packet->payload_length, DMA_TO_DEVICE);
evt = le16_to_cpu(last->transfer_status) & 0x1f;
packet->timestamp = le16_to_cpu(last->res_count);
log_ar_at_event(ohci, 'T', packet->speed, packet->header, evt);
switch (evt) {
case OHCI1394_evt_timeout:
packet->ack = RCODE_CANCELLED;
break;
case OHCI1394_evt_flushed:
packet->ack = RCODE_GENERATION;
break;
case OHCI1394_evt_missing_ack:
if (context->flushing)
packet->ack = RCODE_GENERATION;
else {
packet->ack = RCODE_NO_ACK;
}
break;
case ACK_COMPLETE + 0x10:
case ACK_PENDING + 0x10:
case ACK_BUSY_X + 0x10:
case ACK_BUSY_A + 0x10:
case ACK_BUSY_B + 0x10:
case ACK_DATA_ERROR + 0x10:
case ACK_TYPE_ERROR + 0x10:
packet->ack = evt - 0x10;
break;
case OHCI1394_evt_no_status:
if (context->flushing) {
packet->ack = RCODE_GENERATION;
break;
}
default:
packet->ack = RCODE_SEND_ERROR;
break;
}
packet->callback(packet, &ohci->card, packet->ack);
return 1;
}
static void handle_local_rom(struct fw_ohci *ohci,
struct fw_packet *packet, u32 csr)
{
struct fw_packet response;
int tcode, length, i;
tcode = HEADER_GET_TCODE(packet->header[0]);
if (TCODE_IS_BLOCK_PACKET(tcode))
length = HEADER_GET_DATA_LENGTH(packet->header[3]);
else
length = 4;
i = csr - CSR_CONFIG_ROM;
if (i + length > CONFIG_ROM_SIZE) {
fw_fill_response(&response, packet->header,
RCODE_ADDRESS_ERROR, NULL, 0);
} else if (!TCODE_IS_READ_REQUEST(tcode)) {
fw_fill_response(&response, packet->header,
RCODE_TYPE_ERROR, NULL, 0);
} else {
fw_fill_response(&response, packet->header, RCODE_COMPLETE,
(void *) ohci->config_rom + i, length);
}
fw_core_handle_response(&ohci->card, &response);
}
static void handle_local_lock(struct fw_ohci *ohci,
struct fw_packet *packet, u32 csr)
{
struct fw_packet response;
int tcode, length, ext_tcode, sel, try;
__be32 *payload, lock_old;
u32 lock_arg, lock_data;
tcode = HEADER_GET_TCODE(packet->header[0]);
length = HEADER_GET_DATA_LENGTH(packet->header[3]);
payload = packet->payload;
ext_tcode = HEADER_GET_EXTENDED_TCODE(packet->header[3]);
if (tcode == TCODE_LOCK_REQUEST &&
ext_tcode == EXTCODE_COMPARE_SWAP && length == 8) {
lock_arg = be32_to_cpu(payload[0]);
lock_data = be32_to_cpu(payload[1]);
} else if (tcode == TCODE_READ_QUADLET_REQUEST) {
lock_arg = 0;
lock_data = 0;
} else {
fw_fill_response(&response, packet->header,
RCODE_TYPE_ERROR, NULL, 0);
goto out;
}
sel = (csr - CSR_BUS_MANAGER_ID) / 4;
reg_write(ohci, OHCI1394_CSRData, lock_data);
reg_write(ohci, OHCI1394_CSRCompareData, lock_arg);
reg_write(ohci, OHCI1394_CSRControl, sel);
for (try = 0; try < 20; try++)
if (reg_read(ohci, OHCI1394_CSRControl) & 0x80000000) {
lock_old = cpu_to_be32(reg_read(ohci,
OHCI1394_CSRData));
fw_fill_response(&response, packet->header,
RCODE_COMPLETE,
&lock_old, sizeof(lock_old));
goto out;
}
ohci_err(ohci, "swap not done (CSR lock timeout)\n");
fw_fill_response(&response, packet->header, RCODE_BUSY, NULL, 0);
out:
fw_core_handle_response(&ohci->card, &response);
}
static void handle_local_request(struct context *ctx, struct fw_packet *packet)
{
u64 offset, csr;
if (ctx == &ctx->ohci->at_request_ctx) {
packet->ack = ACK_PENDING;
packet->callback(packet, &ctx->ohci->card, packet->ack);
}
offset =
((unsigned long long)
HEADER_GET_OFFSET_HIGH(packet->header[1]) << 32) |
packet->header[2];
csr = offset - CSR_REGISTER_BASE;
if (csr >= CSR_CONFIG_ROM && csr < CSR_CONFIG_ROM_END)
handle_local_rom(ctx->ohci, packet, csr);
else switch (csr) {
case CSR_BUS_MANAGER_ID:
case CSR_BANDWIDTH_AVAILABLE:
case CSR_CHANNELS_AVAILABLE_HI:
case CSR_CHANNELS_AVAILABLE_LO:
handle_local_lock(ctx->ohci, packet, csr);
break;
default:
if (ctx == &ctx->ohci->at_request_ctx)
fw_core_handle_request(&ctx->ohci->card, packet);
else
fw_core_handle_response(&ctx->ohci->card, packet);
break;
}
if (ctx == &ctx->ohci->at_response_ctx) {
packet->ack = ACK_COMPLETE;
packet->callback(packet, &ctx->ohci->card, packet->ack);
}
}
static void at_context_transmit(struct context *ctx, struct fw_packet *packet)
{
unsigned long flags;
int ret;
spin_lock_irqsave(&ctx->ohci->lock, flags);
if (HEADER_GET_DESTINATION(packet->header[0]) == ctx->ohci->node_id &&
ctx->ohci->generation == packet->generation) {
spin_unlock_irqrestore(&ctx->ohci->lock, flags);
handle_local_request(ctx, packet);
return;
}
ret = at_context_queue_packet(ctx, packet);
spin_unlock_irqrestore(&ctx->ohci->lock, flags);
if (ret < 0)
packet->callback(packet, &ctx->ohci->card, packet->ack);
}
static void detect_dead_context(struct fw_ohci *ohci,
const char *name, unsigned int regs)
{
u32 ctl;
ctl = reg_read(ohci, CONTROL_SET(regs));
if (ctl & CONTEXT_DEAD)
ohci_err(ohci, "DMA context %s has stopped, error code: %s\n",
name, evts[ctl & 0x1f]);
}
static void handle_dead_contexts(struct fw_ohci *ohci)
{
unsigned int i;
char name[8];
detect_dead_context(ohci, "ATReq", OHCI1394_AsReqTrContextBase);
detect_dead_context(ohci, "ATRsp", OHCI1394_AsRspTrContextBase);
detect_dead_context(ohci, "ARReq", OHCI1394_AsReqRcvContextBase);
detect_dead_context(ohci, "ARRsp", OHCI1394_AsRspRcvContextBase);
for (i = 0; i < 32; ++i) {
if (!(ohci->it_context_support & (1 << i)))
continue;
sprintf(name, "IT%u", i);
detect_dead_context(ohci, name, OHCI1394_IsoXmitContextBase(i));
}
for (i = 0; i < 32; ++i) {
if (!(ohci->ir_context_support & (1 << i)))
continue;
sprintf(name, "IR%u", i);
detect_dead_context(ohci, name, OHCI1394_IsoRcvContextBase(i));
}
}
static u32 cycle_timer_ticks(u32 cycle_timer)
{
u32 ticks;
ticks = cycle_timer & 0xfff;
ticks += 3072 * ((cycle_timer >> 12) & 0x1fff);
ticks += (3072 * 8000) * (cycle_timer >> 25);
return ticks;
}
static u32 get_cycle_time(struct fw_ohci *ohci)
{
u32 c0, c1, c2;
u32 t0, t1, t2;
s32 diff01, diff12;
int i;
c2 = reg_read(ohci, OHCI1394_IsochronousCycleTimer);
if (ohci->quirks & QUIRK_CYCLE_TIMER) {
i = 0;
c1 = c2;
c2 = reg_read(ohci, OHCI1394_IsochronousCycleTimer);
do {
c0 = c1;
c1 = c2;
c2 = reg_read(ohci, OHCI1394_IsochronousCycleTimer);
t0 = cycle_timer_ticks(c0);
t1 = cycle_timer_ticks(c1);
t2 = cycle_timer_ticks(c2);
diff01 = t1 - t0;
diff12 = t2 - t1;
} while ((diff01 <= 0 || diff12 <= 0 ||
diff01 / diff12 >= 2 || diff12 / diff01 >= 2)
&& i++ < 20);
}
return c2;
}
static u32 update_bus_time(struct fw_ohci *ohci)
{
u32 cycle_time_seconds = get_cycle_time(ohci) >> 25;
if (unlikely(!ohci->bus_time_running)) {
reg_write(ohci, OHCI1394_IntMaskSet, OHCI1394_cycle64Seconds);
ohci->bus_time = (lower_32_bits(get_seconds()) & ~0x7f) |
(cycle_time_seconds & 0x40);
ohci->bus_time_running = true;
}
if ((ohci->bus_time & 0x40) != (cycle_time_seconds & 0x40))
ohci->bus_time += 0x40;
return ohci->bus_time | cycle_time_seconds;
}
static int get_status_for_port(struct fw_ohci *ohci, int port_index)
{
int reg;
mutex_lock(&ohci->phy_reg_mutex);
reg = write_phy_reg(ohci, 7, port_index);
if (reg >= 0)
reg = read_phy_reg(ohci, 8);
mutex_unlock(&ohci->phy_reg_mutex);
if (reg < 0)
return reg;
switch (reg & 0x0f) {
case 0x06:
return 2;
case 0x0e:
return 3;
}
return 1;
}
static int get_self_id_pos(struct fw_ohci *ohci, u32 self_id,
int self_id_count)
{
int i;
u32 entry;
for (i = 0; i < self_id_count; i++) {
entry = ohci->self_id_buffer[i];
if ((self_id & 0xff000000) == (entry & 0xff000000))
return -1;
if ((self_id & 0xff000000) < (entry & 0xff000000))
return i;
}
return i;
}
static int initiated_reset(struct fw_ohci *ohci)
{
int reg;
int ret = 0;
mutex_lock(&ohci->phy_reg_mutex);
reg = write_phy_reg(ohci, 7, 0xe0);
if (reg >= 0) {
reg = read_phy_reg(ohci, 8);
reg |= 0x40;
reg = write_phy_reg(ohci, 8, reg);
if (reg >= 0) {
reg = read_phy_reg(ohci, 12);
if (reg >= 0) {
if ((reg & 0x08) == 0x08) {
ret = 0x2;
}
}
}
}
mutex_unlock(&ohci->phy_reg_mutex);
return ret;
}
static int find_and_insert_self_id(struct fw_ohci *ohci, int self_id_count)
{
int reg, i, pos, status;
u32 self_id = 0x8040c800;
reg = reg_read(ohci, OHCI1394_NodeID);
if (!(reg & OHCI1394_NodeID_idValid)) {
ohci_notice(ohci,
"node ID not valid, new bus reset in progress\n");
return -EBUSY;
}
self_id |= ((reg & 0x3f) << 24);
reg = ohci_read_phy_reg(&ohci->card, 4);
if (reg < 0)
return reg;
self_id |= ((reg & 0x07) << 8);
reg = ohci_read_phy_reg(&ohci->card, 1);
if (reg < 0)
return reg;
self_id |= ((reg & 0x3f) << 16);
for (i = 0; i < 3; i++) {
status = get_status_for_port(ohci, i);
if (status < 0)
return status;
self_id |= ((status & 0x3) << (6 - (i * 2)));
}
self_id |= initiated_reset(ohci);
pos = get_self_id_pos(ohci, self_id, self_id_count);
if (pos >= 0) {
memmove(&(ohci->self_id_buffer[pos+1]),
&(ohci->self_id_buffer[pos]),
(self_id_count - pos) * sizeof(*ohci->self_id_buffer));
ohci->self_id_buffer[pos] = self_id;
self_id_count++;
}
return self_id_count;
}
static void bus_reset_work(struct work_struct *work)
{
struct fw_ohci *ohci =
container_of(work, struct fw_ohci, bus_reset_work);
int self_id_count, generation, new_generation, i, j;
u32 reg;
void *free_rom = NULL;
dma_addr_t free_rom_bus = 0;
bool is_new_root;
reg = reg_read(ohci, OHCI1394_NodeID);
if (!(reg & OHCI1394_NodeID_idValid)) {
ohci_notice(ohci,
"node ID not valid, new bus reset in progress\n");
return;
}
if ((reg & OHCI1394_NodeID_nodeNumber) == 63) {
ohci_notice(ohci, "malconfigured bus\n");
return;
}
ohci->node_id = reg & (OHCI1394_NodeID_busNumber |
OHCI1394_NodeID_nodeNumber);
is_new_root = (reg & OHCI1394_NodeID_root) != 0;
if (!(ohci->is_root && is_new_root))
reg_write(ohci, OHCI1394_LinkControlSet,
OHCI1394_LinkControl_cycleMaster);
ohci->is_root = is_new_root;
reg = reg_read(ohci, OHCI1394_SelfIDCount);
if (reg & OHCI1394_SelfIDCount_selfIDError) {
ohci_notice(ohci, "self ID receive error\n");
return;
}
self_id_count = (reg >> 3) & 0xff;
if (self_id_count > 252) {
ohci_notice(ohci, "bad selfIDSize (%08x)\n", reg);
return;
}
generation = (cond_le32_to_cpu(ohci->self_id[0]) >> 16) & 0xff;
rmb();
for (i = 1, j = 0; j < self_id_count; i += 2, j++) {
u32 id = cond_le32_to_cpu(ohci->self_id[i]);
u32 id2 = cond_le32_to_cpu(ohci->self_id[i + 1]);
if (id != ~id2) {
if (id == 0xffff008f) {
ohci_notice(ohci, "ignoring spurious self IDs\n");
self_id_count = j;
break;
}
ohci_notice(ohci, "bad self ID %d/%d (%08x != ~%08x)\n",
j, self_id_count, id, id2);
return;
}
ohci->self_id_buffer[j] = id;
}
if (ohci->quirks & QUIRK_TI_SLLZ059) {
self_id_count = find_and_insert_self_id(ohci, self_id_count);
if (self_id_count < 0) {
ohci_notice(ohci,
"could not construct local self ID\n");
return;
}
}
if (self_id_count == 0) {
ohci_notice(ohci, "no self IDs\n");
return;
}
rmb();
new_generation = (reg_read(ohci, OHCI1394_SelfIDCount) >> 16) & 0xff;
if (new_generation != generation) {
ohci_notice(ohci, "new bus reset, discarding self ids\n");
return;
}
spin_lock_irq(&ohci->lock);
ohci->generation = -1;
context_stop(&ohci->at_request_ctx);
context_stop(&ohci->at_response_ctx);
spin_unlock_irq(&ohci->lock);
at_context_flush(&ohci->at_request_ctx);
at_context_flush(&ohci->at_response_ctx);
spin_lock_irq(&ohci->lock);
ohci->generation = generation;
reg_write(ohci, OHCI1394_IntEventClear, OHCI1394_busReset);
if (ohci->quirks & QUIRK_RESET_PACKET)
ohci->request_generation = generation;
if (ohci->next_config_rom != NULL) {
if (ohci->next_config_rom != ohci->config_rom) {
free_rom = ohci->config_rom;
free_rom_bus = ohci->config_rom_bus;
}
ohci->config_rom = ohci->next_config_rom;
ohci->config_rom_bus = ohci->next_config_rom_bus;
ohci->next_config_rom = NULL;
reg_write(ohci, OHCI1394_BusOptions,
be32_to_cpu(ohci->config_rom[2]));
ohci->config_rom[0] = ohci->next_header;
reg_write(ohci, OHCI1394_ConfigROMhdr,
be32_to_cpu(ohci->next_header));
}
if (param_remote_dma) {
reg_write(ohci, OHCI1394_PhyReqFilterHiSet, ~0);
reg_write(ohci, OHCI1394_PhyReqFilterLoSet, ~0);
}
spin_unlock_irq(&ohci->lock);
if (free_rom)
dma_free_coherent(ohci->card.device, CONFIG_ROM_SIZE,
free_rom, free_rom_bus);
log_selfids(ohci, generation, self_id_count);
fw_core_handle_bus_reset(&ohci->card, ohci->node_id, generation,
self_id_count, ohci->self_id_buffer,
ohci->csr_state_setclear_abdicate);
ohci->csr_state_setclear_abdicate = false;
}
static irqreturn_t irq_handler(int irq, void *data)
{
struct fw_ohci *ohci = data;
u32 event, iso_event;
int i;
event = reg_read(ohci, OHCI1394_IntEventClear);
if (!event || !~event)
return IRQ_NONE;
reg_write(ohci, OHCI1394_IntEventClear,
event & ~(OHCI1394_busReset | OHCI1394_postedWriteErr));
log_irqs(ohci, event);
if (event & OHCI1394_selfIDComplete)
queue_work(selfid_workqueue, &ohci->bus_reset_work);
if (event & OHCI1394_RQPkt)
tasklet_schedule(&ohci->ar_request_ctx.tasklet);
if (event & OHCI1394_RSPkt)
tasklet_schedule(&ohci->ar_response_ctx.tasklet);
if (event & OHCI1394_reqTxComplete)
tasklet_schedule(&ohci->at_request_ctx.tasklet);
if (event & OHCI1394_respTxComplete)
tasklet_schedule(&ohci->at_response_ctx.tasklet);
if (event & OHCI1394_isochRx) {
iso_event = reg_read(ohci, OHCI1394_IsoRecvIntEventClear);
reg_write(ohci, OHCI1394_IsoRecvIntEventClear, iso_event);
while (iso_event) {
i = ffs(iso_event) - 1;
tasklet_schedule(
&ohci->ir_context_list[i].context.tasklet);
iso_event &= ~(1 << i);
}
}
if (event & OHCI1394_isochTx) {
iso_event = reg_read(ohci, OHCI1394_IsoXmitIntEventClear);
reg_write(ohci, OHCI1394_IsoXmitIntEventClear, iso_event);
while (iso_event) {
i = ffs(iso_event) - 1;
tasklet_schedule(
&ohci->it_context_list[i].context.tasklet);
iso_event &= ~(1 << i);
}
}
if (unlikely(event & OHCI1394_regAccessFail))
ohci_err(ohci, "register access failure\n");
if (unlikely(event & OHCI1394_postedWriteErr)) {
reg_read(ohci, OHCI1394_PostedWriteAddressHi);
reg_read(ohci, OHCI1394_PostedWriteAddressLo);
reg_write(ohci, OHCI1394_IntEventClear,
OHCI1394_postedWriteErr);
if (printk_ratelimit())
ohci_err(ohci, "PCI posted write error\n");
}
if (unlikely(event & OHCI1394_cycleTooLong)) {
if (printk_ratelimit())
ohci_notice(ohci, "isochronous cycle too long\n");
reg_write(ohci, OHCI1394_LinkControlSet,
OHCI1394_LinkControl_cycleMaster);
}
if (unlikely(event & OHCI1394_cycleInconsistent)) {
if (printk_ratelimit())
ohci_notice(ohci, "isochronous cycle inconsistent\n");
}
if (unlikely(event & OHCI1394_unrecoverableError))
handle_dead_contexts(ohci);
if (event & OHCI1394_cycle64Seconds) {
spin_lock(&ohci->lock);
update_bus_time(ohci);
spin_unlock(&ohci->lock);
} else
flush_writes(ohci);
return IRQ_HANDLED;
}
static int software_reset(struct fw_ohci *ohci)
{
u32 val;
int i;
reg_write(ohci, OHCI1394_HCControlSet, OHCI1394_HCControl_softReset);
for (i = 0; i < 500; i++) {
val = reg_read(ohci, OHCI1394_HCControlSet);
if (!~val)
return -ENODEV;
if (!(val & OHCI1394_HCControl_softReset))
return 0;
msleep(1);
}
return -EBUSY;
}
static void copy_config_rom(__be32 *dest, const __be32 *src, size_t length)
{
size_t size = length * 4;
memcpy(dest, src, size);
if (size < CONFIG_ROM_SIZE)
memset(&dest[length], 0, CONFIG_ROM_SIZE - size);
}
static int configure_1394a_enhancements(struct fw_ohci *ohci)
{
bool enable_1394a;
int ret, clear, set, offset;
if (!(reg_read(ohci, OHCI1394_HCControlSet) &
OHCI1394_HCControl_programPhyEnable))
return 0;
enable_1394a = false;
ret = read_phy_reg(ohci, 2);
if (ret < 0)
return ret;
if ((ret & PHY_EXTENDED_REGISTERS) == PHY_EXTENDED_REGISTERS) {
ret = read_paged_phy_reg(ohci, 1, 8);
if (ret < 0)
return ret;
if (ret >= 1)
enable_1394a = true;
}
if (ohci->quirks & QUIRK_NO_1394A)
enable_1394a = false;
if (enable_1394a) {
clear = 0;
set = PHY_ENABLE_ACCEL | PHY_ENABLE_MULTI;
} else {
clear = PHY_ENABLE_ACCEL | PHY_ENABLE_MULTI;
set = 0;
}
ret = update_phy_reg(ohci, 5, clear, set);
if (ret < 0)
return ret;
if (enable_1394a)
offset = OHCI1394_HCControlSet;
else
offset = OHCI1394_HCControlClear;
reg_write(ohci, offset, OHCI1394_HCControl_aPhyEnhanceEnable);
reg_write(ohci, OHCI1394_HCControlClear,
OHCI1394_HCControl_programPhyEnable);
return 0;
}
static int probe_tsb41ba3d(struct fw_ohci *ohci)
{
static const u8 id[] = { 0x08, 0x00, 0x28, 0x83, 0x30, 0x05, };
int reg, i;
reg = read_phy_reg(ohci, 2);
if (reg < 0)
return reg;
if ((reg & PHY_EXTENDED_REGISTERS) != PHY_EXTENDED_REGISTERS)
return 0;
for (i = ARRAY_SIZE(id) - 1; i >= 0; i--) {
reg = read_paged_phy_reg(ohci, 1, i + 10);
if (reg < 0)
return reg;
if (reg != id[i])
return 0;
}
return 1;
}
static int ohci_enable(struct fw_card *card,
const __be32 *config_rom, size_t length)
{
struct fw_ohci *ohci = fw_ohci(card);
u32 lps, version, irqs;
int i, ret;
if (software_reset(ohci)) {
ohci_err(ohci, "failed to reset ohci card\n");
return -EBUSY;
}
reg_write(ohci, OHCI1394_HCControlSet,
OHCI1394_HCControl_LPS |
OHCI1394_HCControl_postedWriteEnable);
flush_writes(ohci);
for (lps = 0, i = 0; !lps && i < 3; i++) {
msleep(50);
lps = reg_read(ohci, OHCI1394_HCControlSet) &
OHCI1394_HCControl_LPS;
}
if (!lps) {
ohci_err(ohci, "failed to set Link Power Status\n");
return -EIO;
}
if (ohci->quirks & QUIRK_TI_SLLZ059) {
ret = probe_tsb41ba3d(ohci);
if (ret < 0)
return ret;
if (ret)
ohci_notice(ohci, "local TSB41BA3D phy\n");
else
ohci->quirks &= ~QUIRK_TI_SLLZ059;
}
reg_write(ohci, OHCI1394_HCControlClear,
OHCI1394_HCControl_noByteSwapData);
reg_write(ohci, OHCI1394_SelfIDBuffer, ohci->self_id_bus);
reg_write(ohci, OHCI1394_LinkControlSet,
OHCI1394_LinkControl_cycleTimerEnable |
OHCI1394_LinkControl_cycleMaster);
reg_write(ohci, OHCI1394_ATRetries,
OHCI1394_MAX_AT_REQ_RETRIES |
(OHCI1394_MAX_AT_RESP_RETRIES << 4) |
(OHCI1394_MAX_PHYS_RESP_RETRIES << 8) |
(200 << 16));
ohci->bus_time_running = false;
for (i = 0; i < 32; i++)
if (ohci->ir_context_support & (1 << i))
reg_write(ohci, OHCI1394_IsoRcvContextControlClear(i),
IR_CONTEXT_MULTI_CHANNEL_MODE);
version = reg_read(ohci, OHCI1394_Version) & 0x00ff00ff;
if (version >= OHCI_VERSION_1_1) {
reg_write(ohci, OHCI1394_InitialChannelsAvailableHi,
0xfffffffe);
card->broadcast_channel_auto_allocated = true;
}
reg_write(ohci, OHCI1394_FairnessControl, 0x3f);
ohci->pri_req_max = reg_read(ohci, OHCI1394_FairnessControl) & 0x3f;
reg_write(ohci, OHCI1394_FairnessControl, 0);
card->priority_budget_implemented = ohci->pri_req_max != 0;
reg_write(ohci, OHCI1394_PhyUpperBound, FW_MAX_PHYSICAL_RANGE >> 16);
reg_write(ohci, OHCI1394_IntEventClear, ~0);
reg_write(ohci, OHCI1394_IntMaskClear, ~0);
ret = configure_1394a_enhancements(ohci);
if (ret < 0)
return ret;
ret = ohci_update_phy_reg(card, 4, 0, PHY_LINK_ACTIVE | PHY_CONTENDER);
if (ret < 0)
return ret;
if (config_rom) {
ohci->next_config_rom =
dma_alloc_coherent(ohci->card.device, CONFIG_ROM_SIZE,
&ohci->next_config_rom_bus,
GFP_KERNEL);
if (ohci->next_config_rom == NULL)
return -ENOMEM;
copy_config_rom(ohci->next_config_rom, config_rom, length);
} else {
ohci->next_config_rom = ohci->config_rom;
ohci->next_config_rom_bus = ohci->config_rom_bus;
}
ohci->next_header = ohci->next_config_rom[0];
ohci->next_config_rom[0] = 0;
reg_write(ohci, OHCI1394_ConfigROMhdr, 0);
reg_write(ohci, OHCI1394_BusOptions,
be32_to_cpu(ohci->next_config_rom[2]));
reg_write(ohci, OHCI1394_ConfigROMmap, ohci->next_config_rom_bus);
reg_write(ohci, OHCI1394_AsReqFilterHiSet, 0x80000000);
irqs = OHCI1394_reqTxComplete | OHCI1394_respTxComplete |
OHCI1394_RQPkt | OHCI1394_RSPkt |
OHCI1394_isochTx | OHCI1394_isochRx |
OHCI1394_postedWriteErr |
OHCI1394_selfIDComplete |
OHCI1394_regAccessFail |
OHCI1394_cycleInconsistent |
OHCI1394_unrecoverableError |
OHCI1394_cycleTooLong |
OHCI1394_masterIntEnable;
if (param_debug & OHCI_PARAM_DEBUG_BUSRESETS)
irqs |= OHCI1394_busReset;
reg_write(ohci, OHCI1394_IntMaskSet, irqs);
reg_write(ohci, OHCI1394_HCControlSet,
OHCI1394_HCControl_linkEnable |
OHCI1394_HCControl_BIBimageValid);
reg_write(ohci, OHCI1394_LinkControlSet,
OHCI1394_LinkControl_rcvSelfID |
OHCI1394_LinkControl_rcvPhyPkt);
ar_context_run(&ohci->ar_request_ctx);
ar_context_run(&ohci->ar_response_ctx);
flush_writes(ohci);
fw_schedule_bus_reset(&ohci->card, false, true);
return 0;
}
static int ohci_set_config_rom(struct fw_card *card,
const __be32 *config_rom, size_t length)
{
struct fw_ohci *ohci;
__be32 *next_config_rom;
dma_addr_t uninitialized_var(next_config_rom_bus);
ohci = fw_ohci(card);
next_config_rom =
dma_alloc_coherent(ohci->card.device, CONFIG_ROM_SIZE,
&next_config_rom_bus, GFP_KERNEL);
if (next_config_rom == NULL)
return -ENOMEM;
spin_lock_irq(&ohci->lock);
if (ohci->next_config_rom == NULL) {
ohci->next_config_rom = next_config_rom;
ohci->next_config_rom_bus = next_config_rom_bus;
next_config_rom = NULL;
}
copy_config_rom(ohci->next_config_rom, config_rom, length);
ohci->next_header = config_rom[0];
ohci->next_config_rom[0] = 0;
reg_write(ohci, OHCI1394_ConfigROMmap, ohci->next_config_rom_bus);
spin_unlock_irq(&ohci->lock);
if (next_config_rom != NULL)
dma_free_coherent(ohci->card.device, CONFIG_ROM_SIZE,
next_config_rom, next_config_rom_bus);
fw_schedule_bus_reset(&ohci->card, true, true);
return 0;
}
static void ohci_send_request(struct fw_card *card, struct fw_packet *packet)
{
struct fw_ohci *ohci = fw_ohci(card);
at_context_transmit(&ohci->at_request_ctx, packet);
}
static void ohci_send_response(struct fw_card *card, struct fw_packet *packet)
{
struct fw_ohci *ohci = fw_ohci(card);
at_context_transmit(&ohci->at_response_ctx, packet);
}
static int ohci_cancel_packet(struct fw_card *card, struct fw_packet *packet)
{
struct fw_ohci *ohci = fw_ohci(card);
struct context *ctx = &ohci->at_request_ctx;
struct driver_data *driver_data = packet->driver_data;
int ret = -ENOENT;
tasklet_disable(&ctx->tasklet);
if (packet->ack != 0)
goto out;
if (packet->payload_mapped)
dma_unmap_single(ohci->card.device, packet->payload_bus,
packet->payload_length, DMA_TO_DEVICE);
log_ar_at_event(ohci, 'T', packet->speed, packet->header, 0x20);
driver_data->packet = NULL;
packet->ack = RCODE_CANCELLED;
packet->callback(packet, &ohci->card, packet->ack);
ret = 0;
out:
tasklet_enable(&ctx->tasklet);
return ret;
}
static int ohci_enable_phys_dma(struct fw_card *card,
int node_id, int generation)
{
struct fw_ohci *ohci = fw_ohci(card);
unsigned long flags;
int n, ret = 0;
if (param_remote_dma)
return 0;
spin_lock_irqsave(&ohci->lock, flags);
if (ohci->generation != generation) {
ret = -ESTALE;
goto out;
}
n = (node_id & 0xffc0) == LOCAL_BUS ? node_id & 0x3f : 63;
if (n < 32)
reg_write(ohci, OHCI1394_PhyReqFilterLoSet, 1 << n);
else
reg_write(ohci, OHCI1394_PhyReqFilterHiSet, 1 << (n - 32));
flush_writes(ohci);
out:
spin_unlock_irqrestore(&ohci->lock, flags);
return ret;
}
static u32 ohci_read_csr(struct fw_card *card, int csr_offset)
{
struct fw_ohci *ohci = fw_ohci(card);
unsigned long flags;
u32 value;
switch (csr_offset) {
case CSR_STATE_CLEAR:
case CSR_STATE_SET:
if (ohci->is_root &&
(reg_read(ohci, OHCI1394_LinkControlSet) &
OHCI1394_LinkControl_cycleMaster))
value = CSR_STATE_BIT_CMSTR;
else
value = 0;
if (ohci->csr_state_setclear_abdicate)
value |= CSR_STATE_BIT_ABDICATE;
return value;
case CSR_NODE_IDS:
return reg_read(ohci, OHCI1394_NodeID) << 16;
case CSR_CYCLE_TIME:
return get_cycle_time(ohci);
case CSR_BUS_TIME:
spin_lock_irqsave(&ohci->lock, flags);
value = update_bus_time(ohci);
spin_unlock_irqrestore(&ohci->lock, flags);
return value;
case CSR_BUSY_TIMEOUT:
value = reg_read(ohci, OHCI1394_ATRetries);
return (value >> 4) & 0x0ffff00f;
case CSR_PRIORITY_BUDGET:
return (reg_read(ohci, OHCI1394_FairnessControl) & 0x3f) |
(ohci->pri_req_max << 8);
default:
WARN_ON(1);
return 0;
}
}
static void ohci_write_csr(struct fw_card *card, int csr_offset, u32 value)
{
struct fw_ohci *ohci = fw_ohci(card);
unsigned long flags;
switch (csr_offset) {
case CSR_STATE_CLEAR:
if ((value & CSR_STATE_BIT_CMSTR) && ohci->is_root) {
reg_write(ohci, OHCI1394_LinkControlClear,
OHCI1394_LinkControl_cycleMaster);
flush_writes(ohci);
}
if (value & CSR_STATE_BIT_ABDICATE)
ohci->csr_state_setclear_abdicate = false;
break;
case CSR_STATE_SET:
if ((value & CSR_STATE_BIT_CMSTR) && ohci->is_root) {
reg_write(ohci, OHCI1394_LinkControlSet,
OHCI1394_LinkControl_cycleMaster);
flush_writes(ohci);
}
if (value & CSR_STATE_BIT_ABDICATE)
ohci->csr_state_setclear_abdicate = true;
break;
case CSR_NODE_IDS:
reg_write(ohci, OHCI1394_NodeID, value >> 16);
flush_writes(ohci);
break;
case CSR_CYCLE_TIME:
reg_write(ohci, OHCI1394_IsochronousCycleTimer, value);
reg_write(ohci, OHCI1394_IntEventSet,
OHCI1394_cycleInconsistent);
flush_writes(ohci);
break;
case CSR_BUS_TIME:
spin_lock_irqsave(&ohci->lock, flags);
ohci->bus_time = (update_bus_time(ohci) & 0x40) |
(value & ~0x7f);
spin_unlock_irqrestore(&ohci->lock, flags);
break;
case CSR_BUSY_TIMEOUT:
value = (value & 0xf) | ((value & 0xf) << 4) |
((value & 0xf) << 8) | ((value & 0x0ffff000) << 4);
reg_write(ohci, OHCI1394_ATRetries, value);
flush_writes(ohci);
break;
case CSR_PRIORITY_BUDGET:
reg_write(ohci, OHCI1394_FairnessControl, value & 0x3f);
flush_writes(ohci);
break;
default:
WARN_ON(1);
break;
}
}
static void flush_iso_completions(struct iso_context *ctx)
{
ctx->base.callback.sc(&ctx->base, ctx->last_timestamp,
ctx->header_length, ctx->header,
ctx->base.callback_data);
ctx->header_length = 0;
}
static void copy_iso_headers(struct iso_context *ctx, const u32 *dma_hdr)
{
u32 *ctx_hdr;
if (ctx->header_length + ctx->base.header_size > PAGE_SIZE) {
if (ctx->base.drop_overflow_headers)
return;
flush_iso_completions(ctx);
}
ctx_hdr = ctx->header + ctx->header_length;
ctx->last_timestamp = (u16)le32_to_cpu((__force __le32)dma_hdr[0]);
if (ctx->base.header_size > 0)
ctx_hdr[0] = swab32(dma_hdr[1]);
if (ctx->base.header_size > 4)
ctx_hdr[1] = swab32(dma_hdr[0]);
if (ctx->base.header_size > 8)
memcpy(&ctx_hdr[2], &dma_hdr[2], ctx->base.header_size - 8);
ctx->header_length += ctx->base.header_size;
}
static int handle_ir_packet_per_buffer(struct context *context,
struct descriptor *d,
struct descriptor *last)
{
struct iso_context *ctx =
container_of(context, struct iso_context, context);
struct descriptor *pd;
u32 buffer_dma;
for (pd = d; pd <= last; pd++)
if (pd->transfer_status)
break;
if (pd > last)
return 0;
while (!(d->control & cpu_to_le16(DESCRIPTOR_BRANCH_ALWAYS))) {
d++;
buffer_dma = le32_to_cpu(d->data_address);
dma_sync_single_range_for_cpu(context->ohci->card.device,
buffer_dma & PAGE_MASK,
buffer_dma & ~PAGE_MASK,
le16_to_cpu(d->req_count),
DMA_FROM_DEVICE);
}
copy_iso_headers(ctx, (u32 *) (last + 1));
if (last->control & cpu_to_le16(DESCRIPTOR_IRQ_ALWAYS))
flush_iso_completions(ctx);
return 1;
}
static int handle_ir_buffer_fill(struct context *context,
struct descriptor *d,
struct descriptor *last)
{
struct iso_context *ctx =
container_of(context, struct iso_context, context);
unsigned int req_count, res_count, completed;
u32 buffer_dma;
req_count = le16_to_cpu(last->req_count);
res_count = le16_to_cpu(ACCESS_ONCE(last->res_count));
completed = req_count - res_count;
buffer_dma = le32_to_cpu(last->data_address);
if (completed > 0) {
ctx->mc_buffer_bus = buffer_dma;
ctx->mc_completed = completed;
}
if (res_count != 0)
return 0;
dma_sync_single_range_for_cpu(context->ohci->card.device,
buffer_dma & PAGE_MASK,
buffer_dma & ~PAGE_MASK,
completed, DMA_FROM_DEVICE);
if (last->control & cpu_to_le16(DESCRIPTOR_IRQ_ALWAYS)) {
ctx->base.callback.mc(&ctx->base,
buffer_dma + completed,
ctx->base.callback_data);
ctx->mc_completed = 0;
}
return 1;
}
static void flush_ir_buffer_fill(struct iso_context *ctx)
{
dma_sync_single_range_for_cpu(ctx->context.ohci->card.device,
ctx->mc_buffer_bus & PAGE_MASK,
ctx->mc_buffer_bus & ~PAGE_MASK,
ctx->mc_completed, DMA_FROM_DEVICE);
ctx->base.callback.mc(&ctx->base,
ctx->mc_buffer_bus + ctx->mc_completed,
ctx->base.callback_data);
ctx->mc_completed = 0;
}
static inline void sync_it_packet_for_cpu(struct context *context,
struct descriptor *pd)
{
__le16 control;
u32 buffer_dma;
if (pd->control & cpu_to_le16(DESCRIPTOR_BRANCH_ALWAYS))
return;
pd += 2;
if ((le32_to_cpu(pd->data_address) & PAGE_MASK) ==
(context->current_bus & PAGE_MASK)) {
if (pd->control & cpu_to_le16(DESCRIPTOR_BRANCH_ALWAYS))
return;
pd++;
}
do {
buffer_dma = le32_to_cpu(pd->data_address);
dma_sync_single_range_for_cpu(context->ohci->card.device,
buffer_dma & PAGE_MASK,
buffer_dma & ~PAGE_MASK,
le16_to_cpu(pd->req_count),
DMA_TO_DEVICE);
control = pd->control;
pd++;
} while (!(control & cpu_to_le16(DESCRIPTOR_BRANCH_ALWAYS)));
}
static int handle_it_packet(struct context *context,
struct descriptor *d,
struct descriptor *last)
{
struct iso_context *ctx =
container_of(context, struct iso_context, context);
struct descriptor *pd;
__be32 *ctx_hdr;
for (pd = d; pd <= last; pd++)
if (pd->transfer_status)
break;
if (pd > last)
return 0;
sync_it_packet_for_cpu(context, d);
if (ctx->header_length + 4 > PAGE_SIZE) {
if (ctx->base.drop_overflow_headers)
return 1;
flush_iso_completions(ctx);
}
ctx_hdr = ctx->header + ctx->header_length;
ctx->last_timestamp = le16_to_cpu(last->res_count);
*ctx_hdr = cpu_to_be32((le16_to_cpu(pd->transfer_status) << 16) |
le16_to_cpu(pd->res_count));
ctx->header_length += 4;
if (last->control & cpu_to_le16(DESCRIPTOR_IRQ_ALWAYS))
flush_iso_completions(ctx);
return 1;
}
static void set_multichannel_mask(struct fw_ohci *ohci, u64 channels)
{
u32 hi = channels >> 32, lo = channels;
reg_write(ohci, OHCI1394_IRMultiChanMaskHiClear, ~hi);
reg_write(ohci, OHCI1394_IRMultiChanMaskLoClear, ~lo);
reg_write(ohci, OHCI1394_IRMultiChanMaskHiSet, hi);
reg_write(ohci, OHCI1394_IRMultiChanMaskLoSet, lo);
mmiowb();
ohci->mc_channels = channels;
}
static struct fw_iso_context *ohci_allocate_iso_context(struct fw_card *card,
int type, int channel, size_t header_size)
{
struct fw_ohci *ohci = fw_ohci(card);
struct iso_context *uninitialized_var(ctx);
descriptor_callback_t uninitialized_var(callback);
u64 *uninitialized_var(channels);
u32 *uninitialized_var(mask), uninitialized_var(regs);
int index, ret = -EBUSY;
spin_lock_irq(&ohci->lock);
switch (type) {
case FW_ISO_CONTEXT_TRANSMIT:
mask = &ohci->it_context_mask;
callback = handle_it_packet;
index = ffs(*mask) - 1;
if (index >= 0) {
*mask &= ~(1 << index);
regs = OHCI1394_IsoXmitContextBase(index);
ctx = &ohci->it_context_list[index];
}
break;
case FW_ISO_CONTEXT_RECEIVE:
channels = &ohci->ir_context_channels;
mask = &ohci->ir_context_mask;
callback = handle_ir_packet_per_buffer;
index = *channels & 1ULL << channel ? ffs(*mask) - 1 : -1;
if (index >= 0) {
*channels &= ~(1ULL << channel);
*mask &= ~(1 << index);
regs = OHCI1394_IsoRcvContextBase(index);
ctx = &ohci->ir_context_list[index];
}
break;
case FW_ISO_CONTEXT_RECEIVE_MULTICHANNEL:
mask = &ohci->ir_context_mask;
callback = handle_ir_buffer_fill;
index = !ohci->mc_allocated ? ffs(*mask) - 1 : -1;
if (index >= 0) {
ohci->mc_allocated = true;
*mask &= ~(1 << index);
regs = OHCI1394_IsoRcvContextBase(index);
ctx = &ohci->ir_context_list[index];
}
break;
default:
index = -1;
ret = -ENOSYS;
}
spin_unlock_irq(&ohci->lock);
if (index < 0)
return ERR_PTR(ret);
memset(ctx, 0, sizeof(*ctx));
ctx->header_length = 0;
ctx->header = (void *) __get_free_page(GFP_KERNEL);
if (ctx->header == NULL) {
ret = -ENOMEM;
goto out;
}
ret = context_init(&ctx->context, ohci, regs, callback);
if (ret < 0)
goto out_with_header;
if (type == FW_ISO_CONTEXT_RECEIVE_MULTICHANNEL) {
set_multichannel_mask(ohci, 0);
ctx->mc_completed = 0;
}
return &ctx->base;
out_with_header:
free_page((unsigned long)ctx->header);
out:
spin_lock_irq(&ohci->lock);
switch (type) {
case FW_ISO_CONTEXT_RECEIVE:
*channels |= 1ULL << channel;
break;
case FW_ISO_CONTEXT_RECEIVE_MULTICHANNEL:
ohci->mc_allocated = false;
break;
}
*mask |= 1 << index;
spin_unlock_irq(&ohci->lock);
return ERR_PTR(ret);
}
static int ohci_start_iso(struct fw_iso_context *base,
s32 cycle, u32 sync, u32 tags)
{
struct iso_context *ctx = container_of(base, struct iso_context, base);
struct fw_ohci *ohci = ctx->context.ohci;
u32 control = IR_CONTEXT_ISOCH_HEADER, match;
int index;
if (ctx->context.last->branch_address == 0)
return -ENODATA;
switch (ctx->base.type) {
case FW_ISO_CONTEXT_TRANSMIT:
index = ctx - ohci->it_context_list;
match = 0;
if (cycle >= 0)
match = IT_CONTEXT_CYCLE_MATCH_ENABLE |
(cycle & 0x7fff) << 16;
reg_write(ohci, OHCI1394_IsoXmitIntEventClear, 1 << index);
reg_write(ohci, OHCI1394_IsoXmitIntMaskSet, 1 << index);
context_run(&ctx->context, match);
break;
case FW_ISO_CONTEXT_RECEIVE_MULTICHANNEL:
control |= IR_CONTEXT_BUFFER_FILL|IR_CONTEXT_MULTI_CHANNEL_MODE;
case FW_ISO_CONTEXT_RECEIVE:
index = ctx - ohci->ir_context_list;
match = (tags << 28) | (sync << 8) | ctx->base.channel;
if (cycle >= 0) {
match |= (cycle & 0x07fff) << 12;
control |= IR_CONTEXT_CYCLE_MATCH_ENABLE;
}
reg_write(ohci, OHCI1394_IsoRecvIntEventClear, 1 << index);
reg_write(ohci, OHCI1394_IsoRecvIntMaskSet, 1 << index);
reg_write(ohci, CONTEXT_MATCH(ctx->context.regs), match);
context_run(&ctx->context, control);
ctx->sync = sync;
ctx->tags = tags;
break;
}
return 0;
}
static int ohci_stop_iso(struct fw_iso_context *base)
{
struct fw_ohci *ohci = fw_ohci(base->card);
struct iso_context *ctx = container_of(base, struct iso_context, base);
int index;
switch (ctx->base.type) {
case FW_ISO_CONTEXT_TRANSMIT:
index = ctx - ohci->it_context_list;
reg_write(ohci, OHCI1394_IsoXmitIntMaskClear, 1 << index);
break;
case FW_ISO_CONTEXT_RECEIVE:
case FW_ISO_CONTEXT_RECEIVE_MULTICHANNEL:
index = ctx - ohci->ir_context_list;
reg_write(ohci, OHCI1394_IsoRecvIntMaskClear, 1 << index);
break;
}
flush_writes(ohci);
context_stop(&ctx->context);
tasklet_kill(&ctx->context.tasklet);
return 0;
}
static void ohci_free_iso_context(struct fw_iso_context *base)
{
struct fw_ohci *ohci = fw_ohci(base->card);
struct iso_context *ctx = container_of(base, struct iso_context, base);
unsigned long flags;
int index;
ohci_stop_iso(base);
context_release(&ctx->context);
free_page((unsigned long)ctx->header);
spin_lock_irqsave(&ohci->lock, flags);
switch (base->type) {
case FW_ISO_CONTEXT_TRANSMIT:
index = ctx - ohci->it_context_list;
ohci->it_context_mask |= 1 << index;
break;
case FW_ISO_CONTEXT_RECEIVE:
index = ctx - ohci->ir_context_list;
ohci->ir_context_mask |= 1 << index;
ohci->ir_context_channels |= 1ULL << base->channel;
break;
case FW_ISO_CONTEXT_RECEIVE_MULTICHANNEL:
index = ctx - ohci->ir_context_list;
ohci->ir_context_mask |= 1 << index;
ohci->ir_context_channels |= ohci->mc_channels;
ohci->mc_channels = 0;
ohci->mc_allocated = false;
break;
}
spin_unlock_irqrestore(&ohci->lock, flags);
}
static int ohci_set_iso_channels(struct fw_iso_context *base, u64 *channels)
{
struct fw_ohci *ohci = fw_ohci(base->card);
unsigned long flags;
int ret;
switch (base->type) {
case FW_ISO_CONTEXT_RECEIVE_MULTICHANNEL:
spin_lock_irqsave(&ohci->lock, flags);
if (~ohci->ir_context_channels & ~ohci->mc_channels & *channels) {
*channels = ohci->ir_context_channels;
ret = -EBUSY;
} else {
set_multichannel_mask(ohci, *channels);
ret = 0;
}
spin_unlock_irqrestore(&ohci->lock, flags);
break;
default:
ret = -EINVAL;
}
return ret;
}
static void ohci_resume_iso_dma(struct fw_ohci *ohci)
{
int i;
struct iso_context *ctx;
for (i = 0 ; i < ohci->n_ir ; i++) {
ctx = &ohci->ir_context_list[i];
if (ctx->context.running)
ohci_start_iso(&ctx->base, 0, ctx->sync, ctx->tags);
}
for (i = 0 ; i < ohci->n_it ; i++) {
ctx = &ohci->it_context_list[i];
if (ctx->context.running)
ohci_start_iso(&ctx->base, 0, ctx->sync, ctx->tags);
}
}
static int queue_iso_transmit(struct iso_context *ctx,
struct fw_iso_packet *packet,
struct fw_iso_buffer *buffer,
unsigned long payload)
{
struct descriptor *d, *last, *pd;
struct fw_iso_packet *p;
__le32 *header;
dma_addr_t d_bus, page_bus;
u32 z, header_z, payload_z, irq;
u32 payload_index, payload_end_index, next_page_index;
int page, end_page, i, length, offset;
p = packet;
payload_index = payload;
if (p->skip)
z = 1;
else
z = 2;
if (p->header_length > 0)
z++;
end_page = PAGE_ALIGN(payload_index + p->payload_length) >> PAGE_SHIFT;
if (p->payload_length > 0)
payload_z = end_page - (payload_index >> PAGE_SHIFT);
else
payload_z = 0;
z += payload_z;
header_z = DIV_ROUND_UP(p->header_length, sizeof(*d));
d = context_get_descriptors(&ctx->context, z + header_z, &d_bus);
if (d == NULL)
return -ENOMEM;
if (!p->skip) {
d[0].control = cpu_to_le16(DESCRIPTOR_KEY_IMMEDIATE);
d[0].req_count = cpu_to_le16(8);
d[0].branch_address = cpu_to_le32(d_bus | z);
header = (__le32 *) &d[1];
header[0] = cpu_to_le32(IT_HEADER_SY(p->sy) |
IT_HEADER_TAG(p->tag) |
IT_HEADER_TCODE(TCODE_STREAM_DATA) |
IT_HEADER_CHANNEL(ctx->base.channel) |
IT_HEADER_SPEED(ctx->base.speed));
header[1] =
cpu_to_le32(IT_HEADER_DATA_LENGTH(p->header_length +
p->payload_length));
}
if (p->header_length > 0) {
d[2].req_count = cpu_to_le16(p->header_length);
d[2].data_address = cpu_to_le32(d_bus + z * sizeof(*d));
memcpy(&d[z], p->header, p->header_length);
}
pd = d + z - payload_z;
payload_end_index = payload_index + p->payload_length;
for (i = 0; i < payload_z; i++) {
page = payload_index >> PAGE_SHIFT;
offset = payload_index & ~PAGE_MASK;
next_page_index = (page + 1) << PAGE_SHIFT;
length =
min(next_page_index, payload_end_index) - payload_index;
pd[i].req_count = cpu_to_le16(length);
page_bus = page_private(buffer->pages[page]);
pd[i].data_address = cpu_to_le32(page_bus + offset);
dma_sync_single_range_for_device(ctx->context.ohci->card.device,
page_bus, offset, length,
DMA_TO_DEVICE);
payload_index += length;
}
if (p->interrupt)
irq = DESCRIPTOR_IRQ_ALWAYS;
else
irq = DESCRIPTOR_NO_IRQ;
last = z == 2 ? d : d + z - 1;
last->control |= cpu_to_le16(DESCRIPTOR_OUTPUT_LAST |
DESCRIPTOR_STATUS |
DESCRIPTOR_BRANCH_ALWAYS |
irq);
context_append(&ctx->context, d, z, header_z);
return 0;
}
static int queue_iso_packet_per_buffer(struct iso_context *ctx,
struct fw_iso_packet *packet,
struct fw_iso_buffer *buffer,
unsigned long payload)
{
struct device *device = ctx->context.ohci->card.device;
struct descriptor *d, *pd;
dma_addr_t d_bus, page_bus;
u32 z, header_z, rest;
int i, j, length;
int page, offset, packet_count, header_size, payload_per_buffer;
packet_count = packet->header_length / ctx->base.header_size;
header_size = max(ctx->base.header_size, (size_t)8);
header_z = DIV_ROUND_UP(header_size, sizeof(*d));
page = payload >> PAGE_SHIFT;
offset = payload & ~PAGE_MASK;
payload_per_buffer = packet->payload_length / packet_count;
for (i = 0; i < packet_count; i++) {
z = DIV_ROUND_UP(payload_per_buffer + offset, PAGE_SIZE) + 1;
d = context_get_descriptors(&ctx->context,
z + header_z, &d_bus);
if (d == NULL)
return -ENOMEM;
d->control = cpu_to_le16(DESCRIPTOR_STATUS |
DESCRIPTOR_INPUT_MORE);
if (packet->skip && i == 0)
d->control |= cpu_to_le16(DESCRIPTOR_WAIT);
d->req_count = cpu_to_le16(header_size);
d->res_count = d->req_count;
d->transfer_status = 0;
d->data_address = cpu_to_le32(d_bus + (z * sizeof(*d)));
rest = payload_per_buffer;
pd = d;
for (j = 1; j < z; j++) {
pd++;
pd->control = cpu_to_le16(DESCRIPTOR_STATUS |
DESCRIPTOR_INPUT_MORE);
if (offset + rest < PAGE_SIZE)
length = rest;
else
length = PAGE_SIZE - offset;
pd->req_count = cpu_to_le16(length);
pd->res_count = pd->req_count;
pd->transfer_status = 0;
page_bus = page_private(buffer->pages[page]);
pd->data_address = cpu_to_le32(page_bus + offset);
dma_sync_single_range_for_device(device, page_bus,
offset, length,
DMA_FROM_DEVICE);
offset = (offset + length) & ~PAGE_MASK;
rest -= length;
if (offset == 0)
page++;
}
pd->control = cpu_to_le16(DESCRIPTOR_STATUS |
DESCRIPTOR_INPUT_LAST |
DESCRIPTOR_BRANCH_ALWAYS);
if (packet->interrupt && i == packet_count - 1)
pd->control |= cpu_to_le16(DESCRIPTOR_IRQ_ALWAYS);
context_append(&ctx->context, d, z, header_z);
}
return 0;
}
static int queue_iso_buffer_fill(struct iso_context *ctx,
struct fw_iso_packet *packet,
struct fw_iso_buffer *buffer,
unsigned long payload)
{
struct descriptor *d;
dma_addr_t d_bus, page_bus;
int page, offset, rest, z, i, length;
page = payload >> PAGE_SHIFT;
offset = payload & ~PAGE_MASK;
rest = packet->payload_length;
z = DIV_ROUND_UP(offset + rest, PAGE_SIZE);
if (WARN_ON(offset & 3 || rest & 3 || page + z > buffer->page_count))
return -EFAULT;
for (i = 0; i < z; i++) {
d = context_get_descriptors(&ctx->context, 1, &d_bus);
if (d == NULL)
return -ENOMEM;
d->control = cpu_to_le16(DESCRIPTOR_INPUT_MORE |
DESCRIPTOR_BRANCH_ALWAYS);
if (packet->skip && i == 0)
d->control |= cpu_to_le16(DESCRIPTOR_WAIT);
if (packet->interrupt && i == z - 1)
d->control |= cpu_to_le16(DESCRIPTOR_IRQ_ALWAYS);
if (offset + rest < PAGE_SIZE)
length = rest;
else
length = PAGE_SIZE - offset;
d->req_count = cpu_to_le16(length);
d->res_count = d->req_count;
d->transfer_status = 0;
page_bus = page_private(buffer->pages[page]);
d->data_address = cpu_to_le32(page_bus + offset);
dma_sync_single_range_for_device(ctx->context.ohci->card.device,
page_bus, offset, length,
DMA_FROM_DEVICE);
rest -= length;
offset = 0;
page++;
context_append(&ctx->context, d, 1, 0);
}
return 0;
}
static int ohci_queue_iso(struct fw_iso_context *base,
struct fw_iso_packet *packet,
struct fw_iso_buffer *buffer,
unsigned long payload)
{
struct iso_context *ctx = container_of(base, struct iso_context, base);
unsigned long flags;
int ret = -ENOSYS;
spin_lock_irqsave(&ctx->context.ohci->lock, flags);
switch (base->type) {
case FW_ISO_CONTEXT_TRANSMIT:
ret = queue_iso_transmit(ctx, packet, buffer, payload);
break;
case FW_ISO_CONTEXT_RECEIVE:
ret = queue_iso_packet_per_buffer(ctx, packet, buffer, payload);
break;
case FW_ISO_CONTEXT_RECEIVE_MULTICHANNEL:
ret = queue_iso_buffer_fill(ctx, packet, buffer, payload);
break;
}
spin_unlock_irqrestore(&ctx->context.ohci->lock, flags);
return ret;
}
static void ohci_flush_queue_iso(struct fw_iso_context *base)
{
struct context *ctx =
&container_of(base, struct iso_context, base)->context;
reg_write(ctx->ohci, CONTROL_SET(ctx->regs), CONTEXT_WAKE);
}
static int ohci_flush_iso_completions(struct fw_iso_context *base)
{
struct iso_context *ctx = container_of(base, struct iso_context, base);
int ret = 0;
tasklet_disable(&ctx->context.tasklet);
if (!test_and_set_bit_lock(0, &ctx->flushing_completions)) {
context_tasklet((unsigned long)&ctx->context);
switch (base->type) {
case FW_ISO_CONTEXT_TRANSMIT:
case FW_ISO_CONTEXT_RECEIVE:
if (ctx->header_length != 0)
flush_iso_completions(ctx);
break;
case FW_ISO_CONTEXT_RECEIVE_MULTICHANNEL:
if (ctx->mc_completed != 0)
flush_ir_buffer_fill(ctx);
break;
default:
ret = -ENOSYS;
}
clear_bit_unlock(0, &ctx->flushing_completions);
smp_mb__after_atomic();
}
tasklet_enable(&ctx->context.tasklet);
return ret;
}
static void pmac_ohci_on(struct pci_dev *dev)
{
if (machine_is(powermac)) {
struct device_node *ofn = pci_device_to_OF_node(dev);
if (ofn) {
pmac_call_feature(PMAC_FTR_1394_CABLE_POWER, ofn, 0, 1);
pmac_call_feature(PMAC_FTR_1394_ENABLE, ofn, 0, 1);
}
}
}
static void pmac_ohci_off(struct pci_dev *dev)
{
if (machine_is(powermac)) {
struct device_node *ofn = pci_device_to_OF_node(dev);
if (ofn) {
pmac_call_feature(PMAC_FTR_1394_ENABLE, ofn, 0, 0);
pmac_call_feature(PMAC_FTR_1394_CABLE_POWER, ofn, 0, 0);
}
}
}
static inline void pmac_ohci_on(struct pci_dev *dev) {}
static inline void pmac_ohci_off(struct pci_dev *dev) {}
static int pci_probe(struct pci_dev *dev,
const struct pci_device_id *ent)
{
struct fw_ohci *ohci;
u32 bus_options, max_receive, link_speed, version;
u64 guid;
int i, err;
size_t size;
if (dev->vendor == PCI_VENDOR_ID_PINNACLE_SYSTEMS) {
dev_err(&dev->dev, "Pinnacle MovieBoard is not yet supported\n");
return -ENOSYS;
}
ohci = kzalloc(sizeof(*ohci), GFP_KERNEL);
if (ohci == NULL) {
err = -ENOMEM;
goto fail;
}
fw_card_initialize(&ohci->card, &ohci_driver, &dev->dev);
pmac_ohci_on(dev);
err = pci_enable_device(dev);
if (err) {
dev_err(&dev->dev, "failed to enable OHCI hardware\n");
goto fail_free;
}
pci_set_master(dev);
pci_write_config_dword(dev, OHCI1394_PCI_HCI_Control, 0);
pci_set_drvdata(dev, ohci);
spin_lock_init(&ohci->lock);
mutex_init(&ohci->phy_reg_mutex);
INIT_WORK(&ohci->bus_reset_work, bus_reset_work);
if (!(pci_resource_flags(dev, 0) & IORESOURCE_MEM) ||
pci_resource_len(dev, 0) < OHCI1394_REGISTER_SIZE) {
ohci_err(ohci, "invalid MMIO resource\n");
err = -ENXIO;
goto fail_disable;
}
err = pci_request_region(dev, 0, ohci_driver_name);
if (err) {
ohci_err(ohci, "MMIO resource unavailable\n");
goto fail_disable;
}
ohci->registers = pci_iomap(dev, 0, OHCI1394_REGISTER_SIZE);
if (ohci->registers == NULL) {
ohci_err(ohci, "failed to remap registers\n");
err = -ENXIO;
goto fail_iomem;
}
for (i = 0; i < ARRAY_SIZE(ohci_quirks); i++)
if ((ohci_quirks[i].vendor == dev->vendor) &&
(ohci_quirks[i].device == (unsigned short)PCI_ANY_ID ||
ohci_quirks[i].device == dev->device) &&
(ohci_quirks[i].revision == (unsigned short)PCI_ANY_ID ||
ohci_quirks[i].revision >= dev->revision)) {
ohci->quirks = ohci_quirks[i].flags;
break;
}
if (param_quirks)
ohci->quirks = param_quirks;
BUILD_BUG_ON(AR_BUFFERS * sizeof(struct descriptor) > PAGE_SIZE/4);
BUILD_BUG_ON(SELF_ID_BUF_SIZE > PAGE_SIZE/2);
ohci->misc_buffer = dma_alloc_coherent(ohci->card.device,
PAGE_SIZE,
&ohci->misc_buffer_bus,
GFP_KERNEL);
if (!ohci->misc_buffer) {
err = -ENOMEM;
goto fail_iounmap;
}
err = ar_context_init(&ohci->ar_request_ctx, ohci, 0,
OHCI1394_AsReqRcvContextControlSet);
if (err < 0)
goto fail_misc_buf;
err = ar_context_init(&ohci->ar_response_ctx, ohci, PAGE_SIZE/4,
OHCI1394_AsRspRcvContextControlSet);
if (err < 0)
goto fail_arreq_ctx;
err = context_init(&ohci->at_request_ctx, ohci,
OHCI1394_AsReqTrContextControlSet, handle_at_packet);
if (err < 0)
goto fail_arrsp_ctx;
err = context_init(&ohci->at_response_ctx, ohci,
OHCI1394_AsRspTrContextControlSet, handle_at_packet);
if (err < 0)
goto fail_atreq_ctx;
reg_write(ohci, OHCI1394_IsoRecvIntMaskSet, ~0);
ohci->ir_context_channels = ~0ULL;
ohci->ir_context_support = reg_read(ohci, OHCI1394_IsoRecvIntMaskSet);
reg_write(ohci, OHCI1394_IsoRecvIntMaskClear, ~0);
ohci->ir_context_mask = ohci->ir_context_support;
ohci->n_ir = hweight32(ohci->ir_context_mask);
size = sizeof(struct iso_context) * ohci->n_ir;
ohci->ir_context_list = kzalloc(size, GFP_KERNEL);
reg_write(ohci, OHCI1394_IsoXmitIntMaskSet, ~0);
ohci->it_context_support = reg_read(ohci, OHCI1394_IsoXmitIntMaskSet);
reg_write(ohci, OHCI1394_IsoXmitIntMaskClear, ~0);
ohci->it_context_mask = ohci->it_context_support;
ohci->n_it = hweight32(ohci->it_context_mask);
size = sizeof(struct iso_context) * ohci->n_it;
ohci->it_context_list = kzalloc(size, GFP_KERNEL);
if (ohci->it_context_list == NULL || ohci->ir_context_list == NULL) {
err = -ENOMEM;
goto fail_contexts;
}
ohci->self_id = ohci->misc_buffer + PAGE_SIZE/2;
ohci->self_id_bus = ohci->misc_buffer_bus + PAGE_SIZE/2;
bus_options = reg_read(ohci, OHCI1394_BusOptions);
max_receive = (bus_options >> 12) & 0xf;
link_speed = bus_options & 0x7;
guid = ((u64) reg_read(ohci, OHCI1394_GUIDHi) << 32) |
reg_read(ohci, OHCI1394_GUIDLo);
if (!(ohci->quirks & QUIRK_NO_MSI))
pci_enable_msi(dev);
if (request_irq(dev->irq, irq_handler,
pci_dev_msi_enabled(dev) ? 0 : IRQF_SHARED,
ohci_driver_name, ohci)) {
ohci_err(ohci, "failed to allocate interrupt %d\n", dev->irq);
err = -EIO;
goto fail_msi;
}
err = fw_card_add(&ohci->card, max_receive, link_speed, guid);
if (err)
goto fail_irq;
version = reg_read(ohci, OHCI1394_Version) & 0x00ff00ff;
ohci_notice(ohci,
"added OHCI v%x.%x device as card %d, "
"%d IR + %d IT contexts, quirks 0x%x%s\n",
version >> 16, version & 0xff, ohci->card.index,
ohci->n_ir, ohci->n_it, ohci->quirks,
reg_read(ohci, OHCI1394_PhyUpperBound) ?
", physUB" : "");
return 0;
fail_irq:
free_irq(dev->irq, ohci);
fail_msi:
pci_disable_msi(dev);
fail_contexts:
kfree(ohci->ir_context_list);
kfree(ohci->it_context_list);
context_release(&ohci->at_response_ctx);
fail_atreq_ctx:
context_release(&ohci->at_request_ctx);
fail_arrsp_ctx:
ar_context_release(&ohci->ar_response_ctx);
fail_arreq_ctx:
ar_context_release(&ohci->ar_request_ctx);
fail_misc_buf:
dma_free_coherent(ohci->card.device, PAGE_SIZE,
ohci->misc_buffer, ohci->misc_buffer_bus);
fail_iounmap:
pci_iounmap(dev, ohci->registers);
fail_iomem:
pci_release_region(dev, 0);
fail_disable:
pci_disable_device(dev);
fail_free:
kfree(ohci);
pmac_ohci_off(dev);
fail:
return err;
}
static void pci_remove(struct pci_dev *dev)
{
struct fw_ohci *ohci = pci_get_drvdata(dev);
if (reg_read(ohci, OHCI1394_HCControlSet) & OHCI1394_HCControl_LPS) {
reg_write(ohci, OHCI1394_IntMaskClear, ~0);
flush_writes(ohci);
}
cancel_work_sync(&ohci->bus_reset_work);
fw_core_remove_card(&ohci->card);
software_reset(ohci);
free_irq(dev->irq, ohci);
if (ohci->next_config_rom && ohci->next_config_rom != ohci->config_rom)
dma_free_coherent(ohci->card.device, CONFIG_ROM_SIZE,
ohci->next_config_rom, ohci->next_config_rom_bus);
if (ohci->config_rom)
dma_free_coherent(ohci->card.device, CONFIG_ROM_SIZE,
ohci->config_rom, ohci->config_rom_bus);
ar_context_release(&ohci->ar_request_ctx);
ar_context_release(&ohci->ar_response_ctx);
dma_free_coherent(ohci->card.device, PAGE_SIZE,
ohci->misc_buffer, ohci->misc_buffer_bus);
context_release(&ohci->at_request_ctx);
context_release(&ohci->at_response_ctx);
kfree(ohci->it_context_list);
kfree(ohci->ir_context_list);
pci_disable_msi(dev);
pci_iounmap(dev, ohci->registers);
pci_release_region(dev, 0);
pci_disable_device(dev);
kfree(ohci);
pmac_ohci_off(dev);
dev_notice(&dev->dev, "removed fw-ohci device\n");
}
static int pci_suspend(struct pci_dev *dev, pm_message_t state)
{
struct fw_ohci *ohci = pci_get_drvdata(dev);
int err;
software_reset(ohci);
err = pci_save_state(dev);
if (err) {
ohci_err(ohci, "pci_save_state failed\n");
return err;
}
err = pci_set_power_state(dev, pci_choose_state(dev, state));
if (err)
ohci_err(ohci, "pci_set_power_state failed with %d\n", err);
pmac_ohci_off(dev);
return 0;
}
static int pci_resume(struct pci_dev *dev)
{
struct fw_ohci *ohci = pci_get_drvdata(dev);
int err;
pmac_ohci_on(dev);
pci_set_power_state(dev, PCI_D0);
pci_restore_state(dev);
err = pci_enable_device(dev);
if (err) {
ohci_err(ohci, "pci_enable_device failed\n");
return err;
}
if (!reg_read(ohci, OHCI1394_GUIDLo) &&
!reg_read(ohci, OHCI1394_GUIDHi)) {
reg_write(ohci, OHCI1394_GUIDLo, (u32)ohci->card.guid);
reg_write(ohci, OHCI1394_GUIDHi, (u32)(ohci->card.guid >> 32));
}
err = ohci_enable(&ohci->card, NULL, 0);
if (err)
return err;
ohci_resume_iso_dma(ohci);
return 0;
}
static int __init fw_ohci_init(void)
{
selfid_workqueue = alloc_workqueue(KBUILD_MODNAME, WQ_MEM_RECLAIM, 0);
if (!selfid_workqueue)
return -ENOMEM;
return pci_register_driver(&fw_ohci_pci_driver);
}
static void __exit fw_ohci_cleanup(void)
{
pci_unregister_driver(&fw_ohci_pci_driver);
destroy_workqueue(selfid_workqueue);
}
