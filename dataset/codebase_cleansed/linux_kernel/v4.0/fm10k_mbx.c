static void fm10k_fifo_init(struct fm10k_mbx_fifo *fifo, u32 *buffer, u16 size)
{
fifo->buffer = buffer;
fifo->size = size;
fifo->head = 0;
fifo->tail = 0;
}
static u16 fm10k_fifo_used(struct fm10k_mbx_fifo *fifo)
{
return fifo->tail - fifo->head;
}
static u16 fm10k_fifo_unused(struct fm10k_mbx_fifo *fifo)
{
return fifo->size + fifo->head - fifo->tail;
}
static bool fm10k_fifo_empty(struct fm10k_mbx_fifo *fifo)
{
return fifo->head == fifo->tail;
}
static u16 fm10k_fifo_head_offset(struct fm10k_mbx_fifo *fifo, u16 offset)
{
return (fifo->head + offset) & (fifo->size - 1);
}
static u16 fm10k_fifo_tail_offset(struct fm10k_mbx_fifo *fifo, u16 offset)
{
return (fifo->tail + offset) & (fifo->size - 1);
}
static u16 fm10k_fifo_head_len(struct fm10k_mbx_fifo *fifo)
{
u32 *head = fifo->buffer + fm10k_fifo_head_offset(fifo, 0);
if (fm10k_fifo_empty(fifo))
return 0;
return FM10K_TLV_DWORD_LEN(*head);
}
static u16 fm10k_fifo_head_drop(struct fm10k_mbx_fifo *fifo)
{
u16 len = fm10k_fifo_head_len(fifo);
fifo->head += len;
return len;
}
static u16 fm10k_mbx_index_len(struct fm10k_mbx_info *mbx, u16 head, u16 tail)
{
u16 len = tail - head;
if (len > tail)
len -= 2;
return len & ((mbx->mbmem_len << 1) - 1);
}
static u16 fm10k_mbx_tail_add(struct fm10k_mbx_info *mbx, u16 offset)
{
u16 tail = (mbx->tail + offset + 1) & ((mbx->mbmem_len << 1) - 1);
return (tail > mbx->tail) ? --tail : ++tail;
}
static u16 fm10k_mbx_tail_sub(struct fm10k_mbx_info *mbx, u16 offset)
{
u16 tail = (mbx->tail - offset - 1) & ((mbx->mbmem_len << 1) - 1);
return (tail < mbx->tail) ? ++tail : --tail;
}
static u16 fm10k_mbx_head_add(struct fm10k_mbx_info *mbx, u16 offset)
{
u16 head = (mbx->head + offset + 1) & ((mbx->mbmem_len << 1) - 1);
return (head > mbx->head) ? --head : ++head;
}
static u16 fm10k_mbx_head_sub(struct fm10k_mbx_info *mbx, u16 offset)
{
u16 head = (mbx->head - offset - 1) & ((mbx->mbmem_len << 1) - 1);
return (head < mbx->head) ? ++head : --head;
}
static u16 fm10k_mbx_pushed_tail_len(struct fm10k_mbx_info *mbx)
{
u32 *tail = mbx->rx.buffer + fm10k_fifo_tail_offset(&mbx->rx, 0);
if (!mbx->pushed)
return 0;
return FM10K_TLV_DWORD_LEN(*tail);
}
static void fm10k_fifo_write_copy(struct fm10k_mbx_fifo *fifo,
const u32 *msg, u16 tail_offset, u16 len)
{
u16 end = fm10k_fifo_tail_offset(fifo, tail_offset);
u32 *tail = fifo->buffer + end;
end = fifo->size - end;
if (end < len)
memcpy(fifo->buffer, msg + end, (len - end) << 2);
else
end = len;
memcpy(tail, msg, end << 2);
}
static s32 fm10k_fifo_enqueue(struct fm10k_mbx_fifo *fifo, const u32 *msg)
{
u16 len = FM10K_TLV_DWORD_LEN(*msg);
if (len > fifo->size)
return FM10K_MBX_ERR_SIZE;
if (len > fm10k_fifo_unused(fifo))
return FM10K_MBX_ERR_NO_SPACE;
fm10k_fifo_write_copy(fifo, msg, 0, len);
wmb();
fifo->tail += len;
return 0;
}
static u16 fm10k_mbx_validate_msg_size(struct fm10k_mbx_info *mbx, u16 len)
{
struct fm10k_mbx_fifo *fifo = &mbx->rx;
u16 total_len = 0, msg_len;
u32 *msg;
len += mbx->pushed;
do {
msg = fifo->buffer + fm10k_fifo_tail_offset(fifo, total_len);
msg_len = FM10K_TLV_DWORD_LEN(*msg);
total_len += msg_len;
} while (total_len < len);
if ((len < total_len) && (msg_len <= mbx->rx.size))
return 0;
return (len < total_len) ? len : (len - total_len);
}
static void fm10k_mbx_write_copy(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx)
{
struct fm10k_mbx_fifo *fifo = &mbx->tx;
u32 mbmem = mbx->mbmem_reg;
u32 *head = fifo->buffer;
u16 end, len, tail, mask;
if (!mbx->tail_len)
return;
mask = mbx->mbmem_len - 1;
len = mbx->tail_len;
tail = fm10k_mbx_tail_sub(mbx, len);
if (tail > mask)
tail++;
end = fm10k_fifo_head_offset(fifo, mbx->pulled);
head += end;
rmb();
for (end = fifo->size - end; len; head = fifo->buffer) {
do {
tail &= mask;
if (!tail)
tail++;
fm10k_write_reg(hw, mbmem + tail++, *(head++));
} while (--len && --end);
}
}
static void fm10k_mbx_pull_head(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx, u16 head)
{
u16 mbmem_len, len, ack = fm10k_mbx_index_len(mbx, head, mbx->tail);
struct fm10k_mbx_fifo *fifo = &mbx->tx;
mbx->pulled += mbx->tail_len - ack;
mbmem_len = mbx->mbmem_len - 1;
len = fm10k_fifo_used(fifo) - mbx->pulled;
if (len > mbmem_len)
len = mbmem_len;
mbx->tail = fm10k_mbx_tail_add(mbx, len - ack);
mbx->tail_len = len;
for (len = fm10k_fifo_head_len(fifo);
len && (mbx->pulled >= len);
len = fm10k_fifo_head_len(fifo)) {
mbx->pulled -= fm10k_fifo_head_drop(fifo);
mbx->tx_messages++;
mbx->tx_dwords += len;
}
fm10k_mbx_write_copy(hw, mbx);
}
static void fm10k_mbx_read_copy(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx)
{
struct fm10k_mbx_fifo *fifo = &mbx->rx;
u32 mbmem = mbx->mbmem_reg ^ mbx->mbmem_len;
u32 *tail = fifo->buffer;
u16 end, len, head;
len = mbx->head_len;
head = fm10k_mbx_head_sub(mbx, len);
if (head >= mbx->mbmem_len)
head++;
end = fm10k_fifo_tail_offset(fifo, mbx->pushed);
tail += end;
for (end = fifo->size - end; len; tail = fifo->buffer) {
do {
head &= mbx->mbmem_len - 1;
if (!head)
head++;
*(tail++) = fm10k_read_reg(hw, mbmem + head++);
} while (--len && --end);
}
wmb();
}
static s32 fm10k_mbx_push_tail(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx,
u16 tail)
{
struct fm10k_mbx_fifo *fifo = &mbx->rx;
u16 len, seq = fm10k_mbx_index_len(mbx, mbx->head, tail);
len = fm10k_fifo_unused(fifo) - mbx->pushed;
if (len > seq)
len = seq;
mbx->head = fm10k_mbx_head_add(mbx, len);
mbx->head_len = len;
if (!len)
return 0;
fm10k_mbx_read_copy(hw, mbx);
if (fm10k_mbx_validate_msg_size(mbx, len))
return FM10K_MBX_ERR_SIZE;
mbx->pushed += len;
for (len = fm10k_mbx_pushed_tail_len(mbx);
len && (mbx->pushed >= len);
len = fm10k_mbx_pushed_tail_len(mbx)) {
fifo->tail += len;
mbx->pushed -= len;
mbx->rx_messages++;
mbx->rx_dwords += len;
}
return 0;
}
static u16 fm10k_crc_16b(const u32 *data, u16 seed, u16 len)
{
u32 result = seed;
while (len--) {
result ^= *(data++);
result = (result >> 8) ^ fm10k_crc_16b_table[result & 0xFF];
result = (result >> 8) ^ fm10k_crc_16b_table[result & 0xFF];
if (!(len--))
break;
result = (result >> 8) ^ fm10k_crc_16b_table[result & 0xFF];
result = (result >> 8) ^ fm10k_crc_16b_table[result & 0xFF];
}
return (u16)result;
}
static u16 fm10k_fifo_crc(struct fm10k_mbx_fifo *fifo, u16 offset,
u16 len, u16 seed)
{
u32 *data = fifo->buffer + offset;
offset = fifo->size - offset;
if (offset < len) {
seed = fm10k_crc_16b(data, seed, offset * 2);
data = fifo->buffer;
len -= offset;
}
return fm10k_crc_16b(data, seed, len * 2);
}
static void fm10k_mbx_update_local_crc(struct fm10k_mbx_info *mbx, u16 head)
{
u16 len = mbx->tail_len - fm10k_mbx_index_len(mbx, head, mbx->tail);
head = fm10k_fifo_head_offset(&mbx->tx, mbx->pulled);
mbx->local = fm10k_fifo_crc(&mbx->tx, head, len, mbx->local);
}
static s32 fm10k_mbx_verify_remote_crc(struct fm10k_mbx_info *mbx)
{
struct fm10k_mbx_fifo *fifo = &mbx->rx;
u16 len = mbx->head_len;
u16 offset = fm10k_fifo_tail_offset(fifo, mbx->pushed) - len;
u16 crc;
if (len)
mbx->remote = fm10k_fifo_crc(fifo, offset, len, mbx->remote);
crc = fm10k_crc_16b(&mbx->mbx_hdr, mbx->remote, 1);
return crc ? FM10K_MBX_ERR_CRC : 0;
}
static bool fm10k_mbx_rx_ready(struct fm10k_mbx_info *mbx)
{
u16 msg_size = fm10k_fifo_head_len(&mbx->rx);
return msg_size && (fm10k_fifo_used(&mbx->rx) >= msg_size);
}
static bool fm10k_mbx_tx_ready(struct fm10k_mbx_info *mbx, u16 len)
{
u16 fifo_unused = fm10k_fifo_unused(&mbx->tx);
return (mbx->state == FM10K_STATE_OPEN) && (fifo_unused >= len);
}
static bool fm10k_mbx_tx_complete(struct fm10k_mbx_info *mbx)
{
return fm10k_fifo_empty(&mbx->tx);
}
static u16 fm10k_mbx_dequeue_rx(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx)
{
struct fm10k_mbx_fifo *fifo = &mbx->rx;
s32 err;
u16 cnt;
for (cnt = 0; !fm10k_fifo_empty(fifo); cnt++) {
err = fm10k_tlv_msg_parse(hw, fifo->buffer + fifo->head,
mbx, mbx->msg_data);
if (err < 0)
mbx->rx_parse_err++;
fm10k_fifo_head_drop(fifo);
}
memmove(fifo->buffer, fifo->buffer + fifo->tail, mbx->pushed << 2);
fifo->tail -= fifo->head;
fifo->head = 0;
return cnt;
}
static s32 fm10k_mbx_enqueue_tx(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx, const u32 *msg)
{
u32 countdown = mbx->timeout;
s32 err;
switch (mbx->state) {
case FM10K_STATE_CLOSED:
case FM10K_STATE_DISCONNECT:
return FM10K_MBX_ERR_NO_MBX;
default:
break;
}
err = fm10k_fifo_enqueue(&mbx->tx, msg);
while (err && countdown) {
countdown--;
udelay(mbx->udelay);
mbx->ops.process(hw, mbx);
err = fm10k_fifo_enqueue(&mbx->tx, msg);
}
if (err) {
mbx->timeout = 0;
mbx->tx_busy++;
}
if (!mbx->tail_len)
mbx->ops.process(hw, mbx);
return 0;
}
static s32 fm10k_mbx_read(struct fm10k_hw *hw, struct fm10k_mbx_info *mbx)
{
if (mbx->mbx_hdr)
return FM10K_MBX_ERR_BUSY;
if (fm10k_read_reg(hw, mbx->mbx_reg) & FM10K_MBX_REQ_INTERRUPT)
mbx->mbx_lock = FM10K_MBX_ACK;
fm10k_write_reg(hw, mbx->mbx_reg,
FM10K_MBX_REQ_INTERRUPT | FM10K_MBX_ACK_INTERRUPT);
mbx->mbx_hdr = fm10k_read_reg(hw, mbx->mbmem_reg ^ mbx->mbmem_len);
return 0;
}
static void fm10k_mbx_write(struct fm10k_hw *hw, struct fm10k_mbx_info *mbx)
{
u32 mbmem = mbx->mbmem_reg;
fm10k_write_reg(hw, mbmem, mbx->mbx_hdr);
if (mbx->mbx_lock)
fm10k_write_reg(hw, mbx->mbx_reg, mbx->mbx_lock);
mbx->mbx_hdr = 0;
mbx->mbx_lock = 0;
}
static void fm10k_mbx_create_connect_hdr(struct fm10k_mbx_info *mbx)
{
mbx->mbx_lock |= FM10K_MBX_REQ;
mbx->mbx_hdr = FM10K_MSG_HDR_FIELD_SET(FM10K_MSG_CONNECT, TYPE) |
FM10K_MSG_HDR_FIELD_SET(mbx->head, HEAD) |
FM10K_MSG_HDR_FIELD_SET(mbx->rx.size - 1, CONNECT_SIZE);
}
static void fm10k_mbx_create_data_hdr(struct fm10k_mbx_info *mbx)
{
u32 hdr = FM10K_MSG_HDR_FIELD_SET(FM10K_MSG_DATA, TYPE) |
FM10K_MSG_HDR_FIELD_SET(mbx->tail, TAIL) |
FM10K_MSG_HDR_FIELD_SET(mbx->head, HEAD);
struct fm10k_mbx_fifo *fifo = &mbx->tx;
u16 crc;
if (mbx->tail_len)
mbx->mbx_lock |= FM10K_MBX_REQ;
crc = fm10k_fifo_crc(fifo, fm10k_fifo_head_offset(fifo, mbx->pulled),
mbx->tail_len, mbx->local);
crc = fm10k_crc_16b(&hdr, crc, 1);
mbx->mbx_hdr = hdr | FM10K_MSG_HDR_FIELD_SET(crc, CRC);
}
static void fm10k_mbx_create_disconnect_hdr(struct fm10k_mbx_info *mbx)
{
u32 hdr = FM10K_MSG_HDR_FIELD_SET(FM10K_MSG_DISCONNECT, TYPE) |
FM10K_MSG_HDR_FIELD_SET(mbx->tail, TAIL) |
FM10K_MSG_HDR_FIELD_SET(mbx->head, HEAD);
u16 crc = fm10k_crc_16b(&hdr, mbx->local, 1);
mbx->mbx_lock |= FM10K_MBX_ACK;
mbx->mbx_hdr = hdr | FM10K_MSG_HDR_FIELD_SET(crc, CRC);
}
static void fm10k_mbx_create_error_msg(struct fm10k_mbx_info *mbx, s32 err)
{
switch (err) {
case FM10K_MBX_ERR_TAIL:
case FM10K_MBX_ERR_HEAD:
case FM10K_MBX_ERR_TYPE:
case FM10K_MBX_ERR_SIZE:
case FM10K_MBX_ERR_RSVD0:
case FM10K_MBX_ERR_CRC:
break;
default:
return;
}
mbx->mbx_lock |= FM10K_MBX_REQ;
mbx->mbx_hdr = FM10K_MSG_HDR_FIELD_SET(FM10K_MSG_ERROR, TYPE) |
FM10K_MSG_HDR_FIELD_SET(err, ERR_NO) |
FM10K_MSG_HDR_FIELD_SET(mbx->head, HEAD);
}
static s32 fm10k_mbx_validate_msg_hdr(struct fm10k_mbx_info *mbx)
{
u16 type, rsvd0, head, tail, size;
const u32 *hdr = &mbx->mbx_hdr;
type = FM10K_MSG_HDR_FIELD_GET(*hdr, TYPE);
rsvd0 = FM10K_MSG_HDR_FIELD_GET(*hdr, RSVD0);
tail = FM10K_MSG_HDR_FIELD_GET(*hdr, TAIL);
head = FM10K_MSG_HDR_FIELD_GET(*hdr, HEAD);
size = FM10K_MSG_HDR_FIELD_GET(*hdr, CONNECT_SIZE);
if (rsvd0)
return FM10K_MBX_ERR_RSVD0;
switch (type) {
case FM10K_MSG_DISCONNECT:
if (tail != mbx->head)
return FM10K_MBX_ERR_TAIL;
case FM10K_MSG_DATA:
if (!head || (head == FM10K_MSG_HDR_MASK(HEAD)))
return FM10K_MBX_ERR_HEAD;
if (fm10k_mbx_index_len(mbx, head, mbx->tail) > mbx->tail_len)
return FM10K_MBX_ERR_HEAD;
if (!tail || (tail == FM10K_MSG_HDR_MASK(TAIL)))
return FM10K_MBX_ERR_TAIL;
if (fm10k_mbx_index_len(mbx, mbx->head, tail) < mbx->mbmem_len)
break;
return FM10K_MBX_ERR_TAIL;
case FM10K_MSG_CONNECT:
if ((size < FM10K_VFMBX_MSG_MTU) || (size & (size + 1)))
return FM10K_MBX_ERR_SIZE;
case FM10K_MSG_ERROR:
if (!head || (head == FM10K_MSG_HDR_MASK(HEAD)))
return FM10K_MBX_ERR_HEAD;
if (tail)
return FM10K_MBX_ERR_TAIL;
break;
default:
return FM10K_MBX_ERR_TYPE;
}
return 0;
}
static s32 fm10k_mbx_create_reply(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx, u16 head)
{
switch (mbx->state) {
case FM10K_STATE_OPEN:
case FM10K_STATE_DISCONNECT:
fm10k_mbx_update_local_crc(mbx, head);
fm10k_mbx_pull_head(hw, mbx, head);
if (mbx->tail_len || (mbx->state == FM10K_STATE_OPEN))
fm10k_mbx_create_data_hdr(mbx);
else
fm10k_mbx_create_disconnect_hdr(mbx);
break;
case FM10K_STATE_CONNECT:
fm10k_mbx_create_connect_hdr(mbx);
break;
case FM10K_STATE_CLOSED:
fm10k_mbx_create_disconnect_hdr(mbx);
default:
break;
}
return 0;
}
static void fm10k_mbx_reset_work(struct fm10k_mbx_info *mbx)
{
mbx->max_size = mbx->rx.size - 1;
mbx->pushed = 0;
mbx->pulled = 0;
mbx->tail_len = 0;
mbx->head_len = 0;
mbx->rx.tail = 0;
mbx->rx.head = 0;
}
static void fm10k_mbx_update_max_size(struct fm10k_mbx_info *mbx, u16 size)
{
u16 len;
mbx->max_size = size;
for (len = fm10k_fifo_head_len(&mbx->tx);
len > size;
len = fm10k_fifo_head_len(&mbx->tx)) {
fm10k_fifo_head_drop(&mbx->tx);
mbx->tx_dropped++;
}
}
static void fm10k_mbx_connect_reset(struct fm10k_mbx_info *mbx)
{
fm10k_mbx_reset_work(mbx);
mbx->local = FM10K_MBX_CRC_SEED;
mbx->remote = FM10K_MBX_CRC_SEED;
if (mbx->state == FM10K_STATE_OPEN)
mbx->state = FM10K_STATE_CONNECT;
else
mbx->state = FM10K_STATE_CLOSED;
}
static s32 fm10k_mbx_process_connect(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx)
{
const enum fm10k_mbx_state state = mbx->state;
const u32 *hdr = &mbx->mbx_hdr;
u16 size, head;
size = FM10K_MSG_HDR_FIELD_GET(*hdr, CONNECT_SIZE);
head = FM10K_MSG_HDR_FIELD_GET(*hdr, HEAD);
switch (state) {
case FM10K_STATE_DISCONNECT:
case FM10K_STATE_OPEN:
fm10k_mbx_connect_reset(mbx);
break;
case FM10K_STATE_CONNECT:
if (size > mbx->rx.size) {
mbx->max_size = mbx->rx.size - 1;
} else {
mbx->state = FM10K_STATE_OPEN;
fm10k_mbx_update_max_size(mbx, size);
}
break;
default:
break;
}
mbx->tail = head;
return fm10k_mbx_create_reply(hw, mbx, head);
}
static s32 fm10k_mbx_process_data(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx)
{
const u32 *hdr = &mbx->mbx_hdr;
u16 head, tail;
s32 err;
head = FM10K_MSG_HDR_FIELD_GET(*hdr, HEAD);
tail = FM10K_MSG_HDR_FIELD_GET(*hdr, TAIL);
if (mbx->state == FM10K_STATE_CONNECT) {
mbx->tail = head;
mbx->state = FM10K_STATE_OPEN;
}
err = fm10k_mbx_push_tail(hw, mbx, tail);
if (err < 0)
return err;
err = fm10k_mbx_verify_remote_crc(mbx);
if (err)
return err;
fm10k_mbx_dequeue_rx(hw, mbx);
return fm10k_mbx_create_reply(hw, mbx, head);
}
static s32 fm10k_mbx_process_disconnect(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx)
{
const enum fm10k_mbx_state state = mbx->state;
const u32 *hdr = &mbx->mbx_hdr;
u16 head;
s32 err;
head = FM10K_MSG_HDR_FIELD_GET(*hdr, HEAD);
if (mbx->pushed)
return FM10K_MBX_ERR_TAIL;
mbx->head_len = 0;
err = fm10k_mbx_verify_remote_crc(mbx);
if (err)
return err;
switch (state) {
case FM10K_STATE_DISCONNECT:
case FM10K_STATE_OPEN:
if (!fm10k_mbx_tx_complete(mbx))
break;
if (head != mbx->tail)
return FM10K_MBX_ERR_HEAD;
fm10k_mbx_connect_reset(mbx);
break;
default:
break;
}
return fm10k_mbx_create_reply(hw, mbx, head);
}
static s32 fm10k_mbx_process_error(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx)
{
const u32 *hdr = &mbx->mbx_hdr;
s32 err_no;
u16 head;
head = FM10K_MSG_HDR_FIELD_GET(*hdr, HEAD);
err_no = FM10K_MSG_HDR_FIELD_GET(*hdr, ERR_NO);
err_no |= ~FM10K_MSG_HDR_MASK(ERR_NO);
switch (mbx->state) {
case FM10K_STATE_OPEN:
case FM10K_STATE_DISCONNECT:
fm10k_mbx_reset_work(mbx);
mbx->local = FM10K_MBX_CRC_SEED;
mbx->remote = FM10K_MBX_CRC_SEED;
mbx->tail = head;
if (mbx->state == FM10K_STATE_OPEN) {
mbx->state = FM10K_STATE_CONNECT;
break;
}
fm10k_mbx_create_connect_hdr(mbx);
return 0;
default:
break;
}
return fm10k_mbx_create_reply(hw, mbx, mbx->tail);
}
static s32 fm10k_mbx_process(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx)
{
s32 err;
if (mbx->state == FM10K_STATE_CLOSED)
return 0;
err = fm10k_mbx_read(hw, mbx);
if (err)
return err;
err = fm10k_mbx_validate_msg_hdr(mbx);
if (err < 0)
goto msg_err;
switch (FM10K_MSG_HDR_FIELD_GET(mbx->mbx_hdr, TYPE)) {
case FM10K_MSG_CONNECT:
err = fm10k_mbx_process_connect(hw, mbx);
break;
case FM10K_MSG_DATA:
err = fm10k_mbx_process_data(hw, mbx);
break;
case FM10K_MSG_DISCONNECT:
err = fm10k_mbx_process_disconnect(hw, mbx);
break;
case FM10K_MSG_ERROR:
err = fm10k_mbx_process_error(hw, mbx);
break;
default:
err = FM10K_MBX_ERR_TYPE;
break;
}
msg_err:
if (err < 0)
fm10k_mbx_create_error_msg(mbx, err);
fm10k_mbx_write(hw, mbx);
return err;
}
static void fm10k_mbx_disconnect(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx)
{
int timeout = mbx->timeout ? FM10K_MBX_DISCONNECT_TIMEOUT : 0;
mbx->state = FM10K_STATE_DISCONNECT;
fm10k_write_reg(hw, mbx->mbx_reg, FM10K_MBX_REQ |
FM10K_MBX_INTERRUPT_DISABLE);
do {
udelay(FM10K_MBX_POLL_DELAY);
mbx->ops.process(hw, mbx);
timeout -= FM10K_MBX_POLL_DELAY;
} while ((timeout > 0) && (mbx->state != FM10K_STATE_CLOSED));
fm10k_mbx_connect_reset(mbx);
fm10k_mbx_update_max_size(mbx, 0);
fm10k_write_reg(hw, mbx->mbmem_reg, 0);
}
static s32 fm10k_mbx_connect(struct fm10k_hw *hw, struct fm10k_mbx_info *mbx)
{
if (!mbx->rx.buffer)
return FM10K_MBX_ERR_NO_SPACE;
if (mbx->state != FM10K_STATE_CLOSED)
return FM10K_MBX_ERR_BUSY;
mbx->timeout = FM10K_MBX_INIT_TIMEOUT;
mbx->state = FM10K_STATE_CONNECT;
fm10k_mbx_create_disconnect_hdr(mbx);
fm10k_write_reg(hw, mbx->mbmem_reg ^ mbx->mbmem_len, mbx->mbx_hdr);
mbx->mbx_lock = FM10K_MBX_REQ_INTERRUPT | FM10K_MBX_ACK_INTERRUPT |
FM10K_MBX_INTERRUPT_ENABLE;
fm10k_mbx_create_connect_hdr(mbx);
fm10k_mbx_write(hw, mbx);
return 0;
}
static s32 fm10k_mbx_validate_handlers(const struct fm10k_msg_data *msg_data)
{
const struct fm10k_tlv_attr *attr;
unsigned int id;
if (!msg_data)
return 0;
while (msg_data->id != FM10K_TLV_ERROR) {
if (!msg_data->func)
return FM10K_ERR_PARAM;
attr = msg_data->attr;
if (attr) {
while (attr->id != FM10K_TLV_ERROR) {
id = attr->id;
attr++;
if (id >= attr->id)
return FM10K_ERR_PARAM;
if (id >= FM10K_TLV_RESULTS_MAX)
return FM10K_ERR_PARAM;
}
if (attr->id != FM10K_TLV_ERROR)
return FM10K_ERR_PARAM;
}
id = msg_data->id;
msg_data++;
if (id >= msg_data->id)
return FM10K_ERR_PARAM;
}
if ((msg_data->id != FM10K_TLV_ERROR) || !msg_data->func)
return FM10K_ERR_PARAM;
return 0;
}
static s32 fm10k_mbx_register_handlers(struct fm10k_mbx_info *mbx,
const struct fm10k_msg_data *msg_data)
{
if (fm10k_mbx_validate_handlers(msg_data))
return FM10K_ERR_PARAM;
mbx->msg_data = msg_data;
return 0;
}
s32 fm10k_pfvf_mbx_init(struct fm10k_hw *hw, struct fm10k_mbx_info *mbx,
const struct fm10k_msg_data *msg_data, u8 id)
{
switch (hw->mac.type) {
case fm10k_mac_vf:
mbx->mbx_reg = FM10K_VFMBX;
mbx->mbmem_reg = FM10K_VFMBMEM(FM10K_VFMBMEM_VF_XOR);
break;
case fm10k_mac_pf:
if (id < 64) {
mbx->mbx_reg = FM10K_MBX(id);
mbx->mbmem_reg = FM10K_MBMEM_VF(id, 0);
break;
}
default:
return FM10K_MBX_ERR_NO_MBX;
}
mbx->state = FM10K_STATE_CLOSED;
if (fm10k_mbx_validate_handlers(msg_data))
return FM10K_ERR_PARAM;
mbx->msg_data = msg_data;
mbx->timeout = 0;
mbx->udelay = FM10K_MBX_INIT_DELAY;
mbx->tail = 1;
mbx->head = 1;
mbx->local = FM10K_MBX_CRC_SEED;
mbx->remote = FM10K_MBX_CRC_SEED;
mbx->max_size = FM10K_MBX_MSG_MAX_SIZE;
mbx->mbmem_len = FM10K_VFMBMEM_VF_XOR;
fm10k_fifo_init(&mbx->tx, mbx->buffer, FM10K_MBX_TX_BUFFER_SIZE);
fm10k_fifo_init(&mbx->rx, &mbx->buffer[FM10K_MBX_TX_BUFFER_SIZE],
FM10K_MBX_RX_BUFFER_SIZE);
mbx->ops.connect = fm10k_mbx_connect;
mbx->ops.disconnect = fm10k_mbx_disconnect;
mbx->ops.rx_ready = fm10k_mbx_rx_ready;
mbx->ops.tx_ready = fm10k_mbx_tx_ready;
mbx->ops.tx_complete = fm10k_mbx_tx_complete;
mbx->ops.enqueue_tx = fm10k_mbx_enqueue_tx;
mbx->ops.process = fm10k_mbx_process;
mbx->ops.register_handlers = fm10k_mbx_register_handlers;
return 0;
}
static void fm10k_sm_mbx_create_data_hdr(struct fm10k_mbx_info *mbx)
{
if (mbx->tail_len)
mbx->mbx_lock |= FM10K_MBX_REQ;
mbx->mbx_hdr = FM10K_MSG_HDR_FIELD_SET(mbx->tail, SM_TAIL) |
FM10K_MSG_HDR_FIELD_SET(mbx->remote, SM_VER) |
FM10K_MSG_HDR_FIELD_SET(mbx->head, SM_HEAD);
}
static void fm10k_sm_mbx_create_connect_hdr(struct fm10k_mbx_info *mbx, u8 err)
{
if (mbx->local)
mbx->mbx_lock |= FM10K_MBX_REQ;
mbx->mbx_hdr = FM10K_MSG_HDR_FIELD_SET(mbx->tail, SM_TAIL) |
FM10K_MSG_HDR_FIELD_SET(mbx->remote, SM_VER) |
FM10K_MSG_HDR_FIELD_SET(mbx->head, SM_HEAD) |
FM10K_MSG_HDR_FIELD_SET(err, SM_ERR);
}
static void fm10k_sm_mbx_connect_reset(struct fm10k_mbx_info *mbx)
{
fm10k_mbx_reset_work(mbx);
mbx->local = FM10K_SM_MBX_VERSION;
mbx->remote = 0;
mbx->tail = 1;
mbx->head = 1;
mbx->state = FM10K_STATE_CONNECT;
}
static s32 fm10k_sm_mbx_connect(struct fm10k_hw *hw, struct fm10k_mbx_info *mbx)
{
if (!mbx->rx.buffer)
return FM10K_MBX_ERR_NO_SPACE;
if (mbx->state != FM10K_STATE_CLOSED)
return FM10K_MBX_ERR_BUSY;
mbx->timeout = FM10K_MBX_INIT_TIMEOUT;
mbx->state = FM10K_STATE_CONNECT;
mbx->max_size = FM10K_MBX_MSG_MAX_SIZE;
fm10k_sm_mbx_connect_reset(mbx);
mbx->mbx_lock = FM10K_MBX_REQ_INTERRUPT | FM10K_MBX_ACK_INTERRUPT |
FM10K_MBX_INTERRUPT_ENABLE;
fm10k_sm_mbx_create_connect_hdr(mbx, 0);
fm10k_mbx_write(hw, mbx);
return 0;
}
static void fm10k_sm_mbx_disconnect(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx)
{
int timeout = mbx->timeout ? FM10K_MBX_DISCONNECT_TIMEOUT : 0;
mbx->state = FM10K_STATE_DISCONNECT;
fm10k_write_reg(hw, mbx->mbx_reg, FM10K_MBX_REQ |
FM10K_MBX_INTERRUPT_DISABLE);
do {
udelay(FM10K_MBX_POLL_DELAY);
mbx->ops.process(hw, mbx);
timeout -= FM10K_MBX_POLL_DELAY;
} while ((timeout > 0) && (mbx->state != FM10K_STATE_CLOSED));
mbx->state = FM10K_STATE_CLOSED;
mbx->remote = 0;
fm10k_mbx_reset_work(mbx);
fm10k_mbx_update_max_size(mbx, 0);
fm10k_write_reg(hw, mbx->mbmem_reg, 0);
}
static s32 fm10k_sm_mbx_validate_fifo_hdr(struct fm10k_mbx_info *mbx)
{
const u32 *hdr = &mbx->mbx_hdr;
u16 tail, head, ver;
tail = FM10K_MSG_HDR_FIELD_GET(*hdr, SM_TAIL);
ver = FM10K_MSG_HDR_FIELD_GET(*hdr, SM_VER);
head = FM10K_MSG_HDR_FIELD_GET(*hdr, SM_HEAD);
switch (ver) {
case 0:
break;
case FM10K_SM_MBX_VERSION:
if (!head || head > FM10K_SM_MBX_FIFO_LEN)
return FM10K_MBX_ERR_HEAD;
if (!tail || tail > FM10K_SM_MBX_FIFO_LEN)
return FM10K_MBX_ERR_TAIL;
if (mbx->tail < head)
head += mbx->mbmem_len - 1;
if (tail < mbx->head)
tail += mbx->mbmem_len - 1;
if (fm10k_mbx_index_len(mbx, head, mbx->tail) > mbx->tail_len)
return FM10K_MBX_ERR_HEAD;
if (fm10k_mbx_index_len(mbx, mbx->head, tail) < mbx->mbmem_len)
break;
return FM10K_MBX_ERR_TAIL;
default:
return FM10K_MBX_ERR_SRC;
}
return 0;
}
static void fm10k_sm_mbx_process_error(struct fm10k_mbx_info *mbx)
{
const enum fm10k_mbx_state state = mbx->state;
switch (state) {
case FM10K_STATE_DISCONNECT:
mbx->remote = 0;
break;
case FM10K_STATE_OPEN:
fm10k_sm_mbx_connect_reset(mbx);
break;
case FM10K_STATE_CONNECT:
if (mbx->remote) {
while (mbx->local > 1)
mbx->local--;
mbx->remote = 0;
}
break;
default:
break;
}
fm10k_sm_mbx_create_connect_hdr(mbx, 0);
}
static void fm10k_sm_mbx_create_error_msg(struct fm10k_mbx_info *mbx, s32 err)
{
switch (err) {
case FM10K_MBX_ERR_TAIL:
case FM10K_MBX_ERR_HEAD:
case FM10K_MBX_ERR_SRC:
case FM10K_MBX_ERR_SIZE:
case FM10K_MBX_ERR_RSVD0:
break;
default:
return;
}
fm10k_sm_mbx_process_error(mbx);
fm10k_sm_mbx_create_connect_hdr(mbx, 1);
}
static s32 fm10k_sm_mbx_receive(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx,
u16 tail)
{
u16 mbmem_len = mbx->mbmem_len - 1;
s32 err;
if (tail < mbx->head)
tail += mbmem_len;
err = fm10k_mbx_push_tail(hw, mbx, tail);
if (err < 0)
return err;
fm10k_mbx_dequeue_rx(hw, mbx);
mbx->head = fm10k_mbx_head_sub(mbx, mbx->pushed);
mbx->pushed = 0;
if (mbx->head > mbmem_len)
mbx->head -= mbmem_len;
return err;
}
static void fm10k_sm_mbx_transmit(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx, u16 head)
{
struct fm10k_mbx_fifo *fifo = &mbx->tx;
u16 mbmem_len = mbx->mbmem_len - 1;
u16 tail_len, len = 0;
u32 *msg;
if (mbx->tail < head)
head += mbmem_len;
fm10k_mbx_pull_head(hw, mbx, head);
do {
msg = fifo->buffer + fm10k_fifo_head_offset(fifo, len);
tail_len = len;
len += FM10K_TLV_DWORD_LEN(*msg);
} while ((len <= mbx->tail_len) && (len < mbmem_len));
if (mbx->tail_len > tail_len) {
mbx->tail = fm10k_mbx_tail_sub(mbx, mbx->tail_len - tail_len);
mbx->tail_len = tail_len;
}
if (mbx->tail > mbmem_len)
mbx->tail -= mbmem_len;
}
static void fm10k_sm_mbx_create_reply(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx, u16 head)
{
switch (mbx->state) {
case FM10K_STATE_OPEN:
case FM10K_STATE_DISCONNECT:
fm10k_sm_mbx_transmit(hw, mbx, head);
if (mbx->tail_len || (mbx->state == FM10K_STATE_OPEN)) {
fm10k_sm_mbx_create_data_hdr(mbx);
} else {
mbx->remote = 0;
fm10k_sm_mbx_create_connect_hdr(mbx, 0);
}
break;
case FM10K_STATE_CONNECT:
case FM10K_STATE_CLOSED:
fm10k_sm_mbx_create_connect_hdr(mbx, 0);
break;
default:
break;
}
}
static void fm10k_sm_mbx_process_reset(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx)
{
const enum fm10k_mbx_state state = mbx->state;
switch (state) {
case FM10K_STATE_DISCONNECT:
mbx->state = FM10K_STATE_CLOSED;
mbx->remote = 0;
mbx->local = 0;
break;
case FM10K_STATE_OPEN:
fm10k_sm_mbx_connect_reset(mbx);
break;
case FM10K_STATE_CONNECT:
mbx->remote = mbx->local;
default:
break;
}
fm10k_sm_mbx_create_reply(hw, mbx, mbx->tail);
}
static s32 fm10k_sm_mbx_process_version_1(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx)
{
const u32 *hdr = &mbx->mbx_hdr;
u16 head, tail;
s32 len;
tail = FM10K_MSG_HDR_FIELD_GET(*hdr, SM_TAIL);
head = FM10K_MSG_HDR_FIELD_GET(*hdr, SM_HEAD);
if (mbx->state == FM10K_STATE_CONNECT) {
if (!mbx->remote)
goto send_reply;
if (mbx->remote != 1)
return FM10K_MBX_ERR_SRC;
mbx->state = FM10K_STATE_OPEN;
}
do {
len = fm10k_sm_mbx_receive(hw, mbx, tail);
if (len < 0)
return len;
} while (len);
send_reply:
fm10k_sm_mbx_create_reply(hw, mbx, head);
return 0;
}
static s32 fm10k_sm_mbx_process(struct fm10k_hw *hw,
struct fm10k_mbx_info *mbx)
{
s32 err;
if (mbx->state == FM10K_STATE_CLOSED)
return 0;
err = fm10k_mbx_read(hw, mbx);
if (err)
return err;
err = fm10k_sm_mbx_validate_fifo_hdr(mbx);
if (err < 0)
goto fifo_err;
if (FM10K_MSG_HDR_FIELD_GET(mbx->mbx_hdr, SM_ERR)) {
fm10k_sm_mbx_process_error(mbx);
goto fifo_err;
}
switch (FM10K_MSG_HDR_FIELD_GET(mbx->mbx_hdr, SM_VER)) {
case 0:
fm10k_sm_mbx_process_reset(hw, mbx);
break;
case FM10K_SM_MBX_VERSION:
err = fm10k_sm_mbx_process_version_1(hw, mbx);
break;
}
fifo_err:
if (err < 0)
fm10k_sm_mbx_create_error_msg(mbx, err);
fm10k_mbx_write(hw, mbx);
return err;
}
s32 fm10k_sm_mbx_init(struct fm10k_hw *hw, struct fm10k_mbx_info *mbx,
const struct fm10k_msg_data *msg_data)
{
mbx->mbx_reg = FM10K_GMBX;
mbx->mbmem_reg = FM10K_MBMEM_PF(0);
mbx->state = FM10K_STATE_CLOSED;
if (fm10k_mbx_validate_handlers(msg_data))
return FM10K_ERR_PARAM;
mbx->msg_data = msg_data;
mbx->timeout = 0;
mbx->udelay = FM10K_MBX_INIT_DELAY;
mbx->max_size = FM10K_MBX_MSG_MAX_SIZE;
mbx->mbmem_len = FM10K_MBMEM_PF_XOR;
fm10k_fifo_init(&mbx->tx, mbx->buffer, FM10K_MBX_TX_BUFFER_SIZE);
fm10k_fifo_init(&mbx->rx, &mbx->buffer[FM10K_MBX_TX_BUFFER_SIZE],
FM10K_MBX_RX_BUFFER_SIZE);
mbx->ops.connect = fm10k_sm_mbx_connect;
mbx->ops.disconnect = fm10k_sm_mbx_disconnect;
mbx->ops.rx_ready = fm10k_mbx_rx_ready;
mbx->ops.tx_ready = fm10k_mbx_tx_ready;
mbx->ops.tx_complete = fm10k_mbx_tx_complete;
mbx->ops.enqueue_tx = fm10k_mbx_enqueue_tx;
mbx->ops.process = fm10k_sm_mbx_process;
mbx->ops.register_handlers = fm10k_mbx_register_handlers;
return 0;
}
