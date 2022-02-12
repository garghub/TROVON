static u64 flexrm_read_desc(void *desc_ptr)
{
return le64_to_cpu(*((u64 *)desc_ptr));
}
static void flexrm_write_desc(void *desc_ptr, u64 desc)
{
*((u64 *)desc_ptr) = cpu_to_le64(desc);
}
static u32 flexrm_cmpl_desc_to_reqid(u64 cmpl_desc)
{
return (u32)(cmpl_desc & CMPL_OPAQUE_MASK);
}
static int flexrm_cmpl_desc_to_error(u64 cmpl_desc)
{
u32 status;
status = DESC_DEC(cmpl_desc, CMPL_DME_STATUS_SHIFT,
CMPL_DME_STATUS_MASK);
if (status & DME_STATUS_ERROR_MASK)
return -EIO;
status = DESC_DEC(cmpl_desc, CMPL_RM_STATUS_SHIFT,
CMPL_RM_STATUS_MASK);
status &= RM_STATUS_CODE_MASK;
if (status == RM_STATUS_CODE_AE_TIMEOUT)
return -ETIMEDOUT;
return 0;
}
static bool flexrm_is_next_table_desc(void *desc_ptr)
{
u64 desc = flexrm_read_desc(desc_ptr);
u32 type = DESC_DEC(desc, DESC_TYPE_SHIFT, DESC_TYPE_MASK);
return (type == NPTR_TYPE) ? true : false;
}
static u64 flexrm_next_table_desc(u32 toggle, dma_addr_t next_addr)
{
u64 desc = 0;
DESC_ENC(desc, NPTR_TYPE, DESC_TYPE_SHIFT, DESC_TYPE_MASK);
DESC_ENC(desc, toggle, NPTR_TOGGLE_SHIFT, NPTR_TOGGLE_MASK);
DESC_ENC(desc, next_addr, NPTR_ADDR_SHIFT, NPTR_ADDR_MASK);
return desc;
}
static u64 flexrm_null_desc(u32 toggle)
{
u64 desc = 0;
DESC_ENC(desc, NULL_TYPE, DESC_TYPE_SHIFT, DESC_TYPE_MASK);
DESC_ENC(desc, toggle, NULL_TOGGLE_SHIFT, NULL_TOGGLE_MASK);
return desc;
}
static u32 flexrm_estimate_header_desc_count(u32 nhcnt)
{
u32 hcnt = nhcnt / HEADER_BDCOUNT_MAX;
if (!(nhcnt % HEADER_BDCOUNT_MAX))
hcnt += 1;
return hcnt;
}
static void flexrm_flip_header_toogle(void *desc_ptr)
{
u64 desc = flexrm_read_desc(desc_ptr);
if (desc & ((u64)0x1 << HEADER_TOGGLE_SHIFT))
desc &= ~((u64)0x1 << HEADER_TOGGLE_SHIFT);
else
desc |= ((u64)0x1 << HEADER_TOGGLE_SHIFT);
flexrm_write_desc(desc_ptr, desc);
}
static u64 flexrm_header_desc(u32 toggle, u32 startpkt, u32 endpkt,
u32 bdcount, u32 flags, u32 opaque)
{
u64 desc = 0;
DESC_ENC(desc, HEADER_TYPE, DESC_TYPE_SHIFT, DESC_TYPE_MASK);
DESC_ENC(desc, toggle, HEADER_TOGGLE_SHIFT, HEADER_TOGGLE_MASK);
DESC_ENC(desc, startpkt, HEADER_STARTPKT_SHIFT, HEADER_STARTPKT_MASK);
DESC_ENC(desc, endpkt, HEADER_ENDPKT_SHIFT, HEADER_ENDPKT_MASK);
DESC_ENC(desc, bdcount, HEADER_BDCOUNT_SHIFT, HEADER_BDCOUNT_MASK);
DESC_ENC(desc, flags, HEADER_FLAGS_SHIFT, HEADER_FLAGS_MASK);
DESC_ENC(desc, opaque, HEADER_OPAQUE_SHIFT, HEADER_OPAQUE_MASK);
return desc;
}
static void flexrm_enqueue_desc(u32 nhpos, u32 nhcnt, u32 reqid,
u64 desc, void **desc_ptr, u32 *toggle,
void *start_desc, void *end_desc)
{
u64 d;
u32 nhavail, _toggle, _startpkt, _endpkt, _bdcount;
if (nhcnt <= nhpos)
return;
if ((nhpos % HEADER_BDCOUNT_MAX == 0) && (nhcnt - nhpos)) {
nhavail = (nhcnt - nhpos);
_toggle = (nhpos == 0) ? !(*toggle) : (*toggle);
_startpkt = (nhpos == 0) ? 0x1 : 0x0;
_endpkt = (nhavail <= HEADER_BDCOUNT_MAX) ? 0x1 : 0x0;
_bdcount = (nhavail <= HEADER_BDCOUNT_MAX) ?
nhavail : HEADER_BDCOUNT_MAX;
if (nhavail <= HEADER_BDCOUNT_MAX)
_bdcount = nhavail;
else
_bdcount = HEADER_BDCOUNT_MAX;
d = flexrm_header_desc(_toggle, _startpkt, _endpkt,
_bdcount, 0x0, reqid);
flexrm_write_desc(*desc_ptr, d);
*desc_ptr += sizeof(desc);
if (*desc_ptr == end_desc)
*desc_ptr = start_desc;
while (flexrm_is_next_table_desc(*desc_ptr)) {
*toggle = (*toggle) ? 0 : 1;
*desc_ptr += sizeof(desc);
if (*desc_ptr == end_desc)
*desc_ptr = start_desc;
}
}
flexrm_write_desc(*desc_ptr, desc);
*desc_ptr += sizeof(desc);
if (*desc_ptr == end_desc)
*desc_ptr = start_desc;
while (flexrm_is_next_table_desc(*desc_ptr)) {
*toggle = (*toggle) ? 0 : 1;
*desc_ptr += sizeof(desc);
if (*desc_ptr == end_desc)
*desc_ptr = start_desc;
}
}
static u64 flexrm_src_desc(dma_addr_t addr, unsigned int length)
{
u64 desc = 0;
DESC_ENC(desc, SRC_TYPE, DESC_TYPE_SHIFT, DESC_TYPE_MASK);
DESC_ENC(desc, length, SRC_LENGTH_SHIFT, SRC_LENGTH_MASK);
DESC_ENC(desc, addr, SRC_ADDR_SHIFT, SRC_ADDR_MASK);
return desc;
}
static u64 flexrm_msrc_desc(dma_addr_t addr, unsigned int length_div_16)
{
u64 desc = 0;
DESC_ENC(desc, MSRC_TYPE, DESC_TYPE_SHIFT, DESC_TYPE_MASK);
DESC_ENC(desc, length_div_16, MSRC_LENGTH_SHIFT, MSRC_LENGTH_MASK);
DESC_ENC(desc, addr, MSRC_ADDR_SHIFT, MSRC_ADDR_MASK);
return desc;
}
static u64 flexrm_dst_desc(dma_addr_t addr, unsigned int length)
{
u64 desc = 0;
DESC_ENC(desc, DST_TYPE, DESC_TYPE_SHIFT, DESC_TYPE_MASK);
DESC_ENC(desc, length, DST_LENGTH_SHIFT, DST_LENGTH_MASK);
DESC_ENC(desc, addr, DST_ADDR_SHIFT, DST_ADDR_MASK);
return desc;
}
static u64 flexrm_mdst_desc(dma_addr_t addr, unsigned int length_div_16)
{
u64 desc = 0;
DESC_ENC(desc, MDST_TYPE, DESC_TYPE_SHIFT, DESC_TYPE_MASK);
DESC_ENC(desc, length_div_16, MDST_LENGTH_SHIFT, MDST_LENGTH_MASK);
DESC_ENC(desc, addr, MDST_ADDR_SHIFT, MDST_ADDR_MASK);
return desc;
}
static u64 flexrm_imm_desc(u64 data)
{
u64 desc = 0;
DESC_ENC(desc, IMM_TYPE, DESC_TYPE_SHIFT, DESC_TYPE_MASK);
DESC_ENC(desc, data, IMM_DATA_SHIFT, IMM_DATA_MASK);
return desc;
}
static u64 flexrm_srct_desc(dma_addr_t addr, unsigned int length)
{
u64 desc = 0;
DESC_ENC(desc, SRCT_TYPE, DESC_TYPE_SHIFT, DESC_TYPE_MASK);
DESC_ENC(desc, length, SRCT_LENGTH_SHIFT, SRCT_LENGTH_MASK);
DESC_ENC(desc, addr, SRCT_ADDR_SHIFT, SRCT_ADDR_MASK);
return desc;
}
static u64 flexrm_dstt_desc(dma_addr_t addr, unsigned int length)
{
u64 desc = 0;
DESC_ENC(desc, DSTT_TYPE, DESC_TYPE_SHIFT, DESC_TYPE_MASK);
DESC_ENC(desc, length, DSTT_LENGTH_SHIFT, DSTT_LENGTH_MASK);
DESC_ENC(desc, addr, DSTT_ADDR_SHIFT, DSTT_ADDR_MASK);
return desc;
}
static u64 flexrm_immt_desc(u64 data)
{
u64 desc = 0;
DESC_ENC(desc, IMMT_TYPE, DESC_TYPE_SHIFT, DESC_TYPE_MASK);
DESC_ENC(desc, data, IMMT_DATA_SHIFT, IMMT_DATA_MASK);
return desc;
}
static bool flexrm_spu_sanity_check(struct brcm_message *msg)
{
struct scatterlist *sg;
if (!msg->spu.src || !msg->spu.dst)
return false;
for (sg = msg->spu.src; sg; sg = sg_next(sg)) {
if (sg->length & 0xf) {
if (sg->length > SRC_LENGTH_MASK)
return false;
} else {
if (sg->length > (MSRC_LENGTH_MASK * 16))
return false;
}
}
for (sg = msg->spu.dst; sg; sg = sg_next(sg)) {
if (sg->length & 0xf) {
if (sg->length > DST_LENGTH_MASK)
return false;
} else {
if (sg->length > (MDST_LENGTH_MASK * 16))
return false;
}
}
return true;
}
static u32 flexrm_spu_estimate_nonheader_desc_count(struct brcm_message *msg)
{
u32 cnt = 0;
unsigned int dst_target = 0;
struct scatterlist *src_sg = msg->spu.src, *dst_sg = msg->spu.dst;
while (src_sg || dst_sg) {
if (src_sg) {
cnt++;
dst_target = src_sg->length;
src_sg = sg_next(src_sg);
} else
dst_target = UINT_MAX;
while (dst_target && dst_sg) {
cnt++;
if (dst_sg->length < dst_target)
dst_target -= dst_sg->length;
else
dst_target = 0;
dst_sg = sg_next(dst_sg);
}
}
return cnt;
}
static int flexrm_spu_dma_map(struct device *dev, struct brcm_message *msg)
{
int rc;
rc = dma_map_sg(dev, msg->spu.src, sg_nents(msg->spu.src),
DMA_TO_DEVICE);
if (rc < 0)
return rc;
rc = dma_map_sg(dev, msg->spu.dst, sg_nents(msg->spu.dst),
DMA_FROM_DEVICE);
if (rc < 0) {
dma_unmap_sg(dev, msg->spu.src, sg_nents(msg->spu.src),
DMA_TO_DEVICE);
return rc;
}
return 0;
}
static void flexrm_spu_dma_unmap(struct device *dev, struct brcm_message *msg)
{
dma_unmap_sg(dev, msg->spu.dst, sg_nents(msg->spu.dst),
DMA_FROM_DEVICE);
dma_unmap_sg(dev, msg->spu.src, sg_nents(msg->spu.src),
DMA_TO_DEVICE);
}
static void *flexrm_spu_write_descs(struct brcm_message *msg, u32 nhcnt,
u32 reqid, void *desc_ptr, u32 toggle,
void *start_desc, void *end_desc)
{
u64 d;
u32 nhpos = 0;
void *orig_desc_ptr = desc_ptr;
unsigned int dst_target = 0;
struct scatterlist *src_sg = msg->spu.src, *dst_sg = msg->spu.dst;
while (src_sg || dst_sg) {
if (src_sg) {
if (sg_dma_len(src_sg) & 0xf)
d = flexrm_src_desc(sg_dma_address(src_sg),
sg_dma_len(src_sg));
else
d = flexrm_msrc_desc(sg_dma_address(src_sg),
sg_dma_len(src_sg)/16);
flexrm_enqueue_desc(nhpos, nhcnt, reqid,
d, &desc_ptr, &toggle,
start_desc, end_desc);
nhpos++;
dst_target = sg_dma_len(src_sg);
src_sg = sg_next(src_sg);
} else
dst_target = UINT_MAX;
while (dst_target && dst_sg) {
if (sg_dma_len(dst_sg) & 0xf)
d = flexrm_dst_desc(sg_dma_address(dst_sg),
sg_dma_len(dst_sg));
else
d = flexrm_mdst_desc(sg_dma_address(dst_sg),
sg_dma_len(dst_sg)/16);
flexrm_enqueue_desc(nhpos, nhcnt, reqid,
d, &desc_ptr, &toggle,
start_desc, end_desc);
nhpos++;
if (sg_dma_len(dst_sg) < dst_target)
dst_target -= sg_dma_len(dst_sg);
else
dst_target = 0;
dst_sg = sg_next(dst_sg);
}
}
flexrm_write_desc(desc_ptr, flexrm_null_desc(!toggle));
wmb();
flexrm_flip_header_toogle(orig_desc_ptr);
return desc_ptr;
}
static bool flexrm_sba_sanity_check(struct brcm_message *msg)
{
u32 i;
if (!msg->sba.cmds || !msg->sba.cmds_count)
return false;
for (i = 0; i < msg->sba.cmds_count; i++) {
if (((msg->sba.cmds[i].flags & BRCM_SBA_CMD_TYPE_B) ||
(msg->sba.cmds[i].flags & BRCM_SBA_CMD_TYPE_C)) &&
(msg->sba.cmds[i].flags & BRCM_SBA_CMD_HAS_OUTPUT))
return false;
if ((msg->sba.cmds[i].flags & BRCM_SBA_CMD_TYPE_B) &&
(msg->sba.cmds[i].data_len > SRCT_LENGTH_MASK))
return false;
if ((msg->sba.cmds[i].flags & BRCM_SBA_CMD_TYPE_C) &&
(msg->sba.cmds[i].data_len > SRCT_LENGTH_MASK))
return false;
if ((msg->sba.cmds[i].flags & BRCM_SBA_CMD_HAS_RESP) &&
(msg->sba.cmds[i].resp_len > DSTT_LENGTH_MASK))
return false;
if ((msg->sba.cmds[i].flags & BRCM_SBA_CMD_HAS_OUTPUT) &&
(msg->sba.cmds[i].data_len > DSTT_LENGTH_MASK))
return false;
}
return true;
}
static u32 flexrm_sba_estimate_nonheader_desc_count(struct brcm_message *msg)
{
u32 i, cnt;
cnt = 0;
for (i = 0; i < msg->sba.cmds_count; i++) {
cnt++;
if ((msg->sba.cmds[i].flags & BRCM_SBA_CMD_TYPE_B) ||
(msg->sba.cmds[i].flags & BRCM_SBA_CMD_TYPE_C))
cnt++;
if (msg->sba.cmds[i].flags & BRCM_SBA_CMD_HAS_RESP)
cnt++;
if (msg->sba.cmds[i].flags & BRCM_SBA_CMD_HAS_OUTPUT)
cnt++;
}
return cnt;
}
static void *flexrm_sba_write_descs(struct brcm_message *msg, u32 nhcnt,
u32 reqid, void *desc_ptr, u32 toggle,
void *start_desc, void *end_desc)
{
u64 d;
u32 i, nhpos = 0;
struct brcm_sba_command *c;
void *orig_desc_ptr = desc_ptr;
for (i = 0; i < msg->sba.cmds_count; i++) {
c = &msg->sba.cmds[i];
if ((c->flags & BRCM_SBA_CMD_HAS_RESP) &&
(c->flags & BRCM_SBA_CMD_HAS_OUTPUT)) {
d = flexrm_dst_desc(c->resp, c->resp_len);
flexrm_enqueue_desc(nhpos, nhcnt, reqid,
d, &desc_ptr, &toggle,
start_desc, end_desc);
nhpos++;
} else if (c->flags & BRCM_SBA_CMD_HAS_RESP) {
d = flexrm_dstt_desc(c->resp, c->resp_len);
flexrm_enqueue_desc(nhpos, nhcnt, reqid,
d, &desc_ptr, &toggle,
start_desc, end_desc);
nhpos++;
}
if (c->flags & BRCM_SBA_CMD_HAS_OUTPUT) {
d = flexrm_dstt_desc(c->data, c->data_len);
flexrm_enqueue_desc(nhpos, nhcnt, reqid,
d, &desc_ptr, &toggle,
start_desc, end_desc);
nhpos++;
}
if (c->flags & BRCM_SBA_CMD_TYPE_B) {
d = flexrm_imm_desc(c->cmd);
flexrm_enqueue_desc(nhpos, nhcnt, reqid,
d, &desc_ptr, &toggle,
start_desc, end_desc);
nhpos++;
} else {
d = flexrm_immt_desc(c->cmd);
flexrm_enqueue_desc(nhpos, nhcnt, reqid,
d, &desc_ptr, &toggle,
start_desc, end_desc);
nhpos++;
}
if ((c->flags & BRCM_SBA_CMD_TYPE_B) ||
(c->flags & BRCM_SBA_CMD_TYPE_C)) {
d = flexrm_srct_desc(c->data, c->data_len);
flexrm_enqueue_desc(nhpos, nhcnt, reqid,
d, &desc_ptr, &toggle,
start_desc, end_desc);
nhpos++;
}
}
flexrm_write_desc(desc_ptr, flexrm_null_desc(!toggle));
wmb();
flexrm_flip_header_toogle(orig_desc_ptr);
return desc_ptr;
}
static bool flexrm_sanity_check(struct brcm_message *msg)
{
if (!msg)
return false;
switch (msg->type) {
case BRCM_MESSAGE_SPU:
return flexrm_spu_sanity_check(msg);
case BRCM_MESSAGE_SBA:
return flexrm_sba_sanity_check(msg);
default:
return false;
};
}
static u32 flexrm_estimate_nonheader_desc_count(struct brcm_message *msg)
{
if (!msg)
return 0;
switch (msg->type) {
case BRCM_MESSAGE_SPU:
return flexrm_spu_estimate_nonheader_desc_count(msg);
case BRCM_MESSAGE_SBA:
return flexrm_sba_estimate_nonheader_desc_count(msg);
default:
return 0;
};
}
static int flexrm_dma_map(struct device *dev, struct brcm_message *msg)
{
if (!dev || !msg)
return -EINVAL;
switch (msg->type) {
case BRCM_MESSAGE_SPU:
return flexrm_spu_dma_map(dev, msg);
default:
break;
}
return 0;
}
static void flexrm_dma_unmap(struct device *dev, struct brcm_message *msg)
{
if (!dev || !msg)
return;
switch (msg->type) {
case BRCM_MESSAGE_SPU:
flexrm_spu_dma_unmap(dev, msg);
break;
default:
break;
}
}
static void *flexrm_write_descs(struct brcm_message *msg, u32 nhcnt,
u32 reqid, void *desc_ptr, u32 toggle,
void *start_desc, void *end_desc)
{
if (!msg || !desc_ptr || !start_desc || !end_desc)
return ERR_PTR(-ENOTSUPP);
if ((desc_ptr < start_desc) || (end_desc <= desc_ptr))
return ERR_PTR(-ERANGE);
switch (msg->type) {
case BRCM_MESSAGE_SPU:
return flexrm_spu_write_descs(msg, nhcnt, reqid,
desc_ptr, toggle,
start_desc, end_desc);
case BRCM_MESSAGE_SBA:
return flexrm_sba_write_descs(msg, nhcnt, reqid,
desc_ptr, toggle,
start_desc, end_desc);
default:
return ERR_PTR(-ENOTSUPP);
};
}
static int flexrm_new_request(struct flexrm_ring *ring,
struct brcm_message *batch_msg,
struct brcm_message *msg)
{
void *next;
unsigned long flags;
u32 val, count, nhcnt;
u32 read_offset, write_offset;
bool exit_cleanup = false;
int ret = 0, reqid;
if (!flexrm_sanity_check(msg))
return -EIO;
msg->error = 0;
reqid = ida_simple_get(&ring->requests_ida, 0,
RING_MAX_REQ_COUNT, GFP_KERNEL);
if (reqid < 0) {
spin_lock_irqsave(&ring->lock, flags);
if (batch_msg)
ring->last_pending_msg = batch_msg;
else
ring->last_pending_msg = msg;
spin_unlock_irqrestore(&ring->lock, flags);
return 0;
}
ring->requests[reqid] = msg;
ret = flexrm_dma_map(ring->mbox->dev, msg);
if (ret < 0) {
ring->requests[reqid] = NULL;
ida_simple_remove(&ring->requests_ida, reqid);
return ret;
}
spin_lock_irqsave(&ring->lock, flags);
if (ring->last_pending_msg)
ret = -ENOSPC;
spin_unlock_irqrestore(&ring->lock, flags);
if (ret < 0) {
dev_warn(ring->mbox->dev, "no space in ring %d\n", ring->num);
exit_cleanup = true;
goto exit;
}
read_offset = readl_relaxed(ring->regs + RING_BD_READ_PTR);
val = readl_relaxed(ring->regs + RING_BD_START_ADDR);
read_offset *= RING_DESC_SIZE;
read_offset += (u32)(BD_START_ADDR_DECODE(val) - ring->bd_dma_base);
nhcnt = flexrm_estimate_nonheader_desc_count(msg);
count = flexrm_estimate_header_desc_count(nhcnt) + nhcnt + 1;
write_offset = ring->bd_write_offset;
while (count) {
if (!flexrm_is_next_table_desc(ring->bd_base + write_offset))
count--;
write_offset += RING_DESC_SIZE;
if (write_offset == RING_BD_SIZE)
write_offset = 0x0;
if (write_offset == read_offset)
break;
}
if (count) {
spin_lock_irqsave(&ring->lock, flags);
if (batch_msg)
ring->last_pending_msg = batch_msg;
else
ring->last_pending_msg = msg;
spin_unlock_irqrestore(&ring->lock, flags);
ret = 0;
exit_cleanup = true;
goto exit;
}
next = flexrm_write_descs(msg, nhcnt, reqid,
ring->bd_base + ring->bd_write_offset,
RING_BD_TOGGLE_VALID(ring->bd_write_offset),
ring->bd_base, ring->bd_base + RING_BD_SIZE);
if (IS_ERR(next)) {
ret = PTR_ERR(next);
exit_cleanup = true;
goto exit;
}
ring->bd_write_offset = (unsigned long)(next - ring->bd_base);
exit:
msg->error = ret;
if (exit_cleanup) {
flexrm_dma_unmap(ring->mbox->dev, msg);
ring->requests[reqid] = NULL;
ida_simple_remove(&ring->requests_ida, reqid);
}
return ret;
}
static int flexrm_process_completions(struct flexrm_ring *ring)
{
u64 desc;
int err, count = 0;
unsigned long flags;
struct brcm_message *msg = NULL;
u32 reqid, cmpl_read_offset, cmpl_write_offset;
struct mbox_chan *chan = &ring->mbox->controller.chans[ring->num];
spin_lock_irqsave(&ring->lock, flags);
if (ring->last_pending_msg) {
msg = ring->last_pending_msg;
ring->last_pending_msg = NULL;
}
cmpl_write_offset = readl_relaxed(ring->regs + RING_CMPL_WRITE_PTR);
cmpl_write_offset *= RING_DESC_SIZE;
cmpl_read_offset = ring->cmpl_read_offset;
ring->cmpl_read_offset = cmpl_write_offset;
spin_unlock_irqrestore(&ring->lock, flags);
if (msg)
mbox_send_message(chan, msg);
reqid = 0;
while (cmpl_read_offset != cmpl_write_offset) {
desc = *((u64 *)(ring->cmpl_base + cmpl_read_offset));
cmpl_read_offset += RING_DESC_SIZE;
if (cmpl_read_offset == RING_CMPL_SIZE)
cmpl_read_offset = 0;
err = flexrm_cmpl_desc_to_error(desc);
if (err < 0) {
dev_warn(ring->mbox->dev,
"got completion desc=0x%lx with error %d",
(unsigned long)desc, err);
}
reqid = flexrm_cmpl_desc_to_reqid(desc);
msg = ring->requests[reqid];
if (!msg) {
dev_warn(ring->mbox->dev,
"null msg pointer for completion desc=0x%lx",
(unsigned long)desc);
continue;
}
ring->requests[reqid] = NULL;
ida_simple_remove(&ring->requests_ida, reqid);
flexrm_dma_unmap(ring->mbox->dev, msg);
msg->error = err;
mbox_chan_received_data(chan, msg);
count++;
}
return count;
}
static irqreturn_t flexrm_irq_event(int irq, void *dev_id)
{
return IRQ_WAKE_THREAD;
}
static irqreturn_t flexrm_irq_thread(int irq, void *dev_id)
{
flexrm_process_completions(dev_id);
return IRQ_HANDLED;
}
static int flexrm_send_data(struct mbox_chan *chan, void *data)
{
int i, rc;
struct flexrm_ring *ring = chan->con_priv;
struct brcm_message *msg = data;
if (msg->type == BRCM_MESSAGE_BATCH) {
for (i = msg->batch.msgs_queued;
i < msg->batch.msgs_count; i++) {
rc = flexrm_new_request(ring, msg,
&msg->batch.msgs[i]);
if (rc) {
msg->error = rc;
return rc;
}
msg->batch.msgs_queued++;
}
return 0;
}
return flexrm_new_request(ring, NULL, data);
}
static bool flexrm_peek_data(struct mbox_chan *chan)
{
int cnt = flexrm_process_completions(chan->con_priv);
return (cnt > 0) ? true : false;
}
static int flexrm_startup(struct mbox_chan *chan)
{
u64 d;
u32 val, off;
int ret = 0;
dma_addr_t next_addr;
struct flexrm_ring *ring = chan->con_priv;
ring->bd_base = dma_pool_alloc(ring->mbox->bd_pool,
GFP_KERNEL, &ring->bd_dma_base);
if (!ring->bd_base) {
dev_err(ring->mbox->dev, "can't allocate BD memory\n");
ret = -ENOMEM;
goto fail;
}
for (off = 0; off < RING_BD_SIZE; off += RING_DESC_SIZE) {
next_addr = off + RING_DESC_SIZE;
if (next_addr == RING_BD_SIZE)
next_addr = 0;
next_addr += ring->bd_dma_base;
if (RING_BD_ALIGN_CHECK(next_addr))
d = flexrm_next_table_desc(RING_BD_TOGGLE_VALID(off),
next_addr);
else
d = flexrm_null_desc(RING_BD_TOGGLE_INVALID(off));
flexrm_write_desc(ring->bd_base + off, d);
}
ring->cmpl_base = dma_pool_alloc(ring->mbox->cmpl_pool,
GFP_KERNEL, &ring->cmpl_dma_base);
if (!ring->cmpl_base) {
dev_err(ring->mbox->dev, "can't allocate completion memory\n");
ret = -ENOMEM;
goto fail_free_bd_memory;
}
memset(ring->cmpl_base, 0, RING_CMPL_SIZE);
if (ring->irq == UINT_MAX) {
dev_err(ring->mbox->dev, "ring IRQ not available\n");
ret = -ENODEV;
goto fail_free_cmpl_memory;
}
ret = request_threaded_irq(ring->irq,
flexrm_irq_event,
flexrm_irq_thread,
0, dev_name(ring->mbox->dev), ring);
if (ret) {
dev_err(ring->mbox->dev, "failed to request ring IRQ\n");
goto fail_free_cmpl_memory;
}
ring->irq_requested = true;
writel_relaxed(0x0, ring->regs + RING_CONTROL);
val = BD_START_ADDR_VALUE(ring->bd_dma_base);
writel_relaxed(val, ring->regs + RING_BD_START_ADDR);
ring->bd_write_offset =
readl_relaxed(ring->regs + RING_BD_WRITE_PTR);
ring->bd_write_offset *= RING_DESC_SIZE;
val = CMPL_START_ADDR_VALUE(ring->cmpl_dma_base);
writel_relaxed(val, ring->regs + RING_CMPL_START_ADDR);
ring->last_pending_msg = NULL;
ring->cmpl_read_offset =
readl_relaxed(ring->regs + RING_CMPL_WRITE_PTR);
ring->cmpl_read_offset *= RING_DESC_SIZE;
readl_relaxed(ring->regs + RING_NUM_REQ_RECV_LS);
readl_relaxed(ring->regs + RING_NUM_REQ_RECV_MS);
readl_relaxed(ring->regs + RING_NUM_REQ_TRANS_LS);
readl_relaxed(ring->regs + RING_NUM_REQ_TRANS_MS);
readl_relaxed(ring->regs + RING_NUM_REQ_OUTSTAND);
val = 0;
val |= (ring->msi_timer_val << MSI_TIMER_VAL_SHIFT);
val |= BIT(MSI_ENABLE_SHIFT);
val |= (ring->msi_count_threshold & MSI_COUNT_MASK) << MSI_COUNT_SHIFT;
writel_relaxed(val, ring->regs + RING_MSI_CONTROL);
val = BIT(CONTROL_ACTIVE_SHIFT);
writel_relaxed(val, ring->regs + RING_CONTROL);
return 0;
fail_free_cmpl_memory:
dma_pool_free(ring->mbox->cmpl_pool,
ring->cmpl_base, ring->cmpl_dma_base);
ring->cmpl_base = NULL;
fail_free_bd_memory:
dma_pool_free(ring->mbox->bd_pool,
ring->bd_base, ring->bd_dma_base);
ring->bd_base = NULL;
fail:
return ret;
}
static void flexrm_shutdown(struct mbox_chan *chan)
{
u32 reqid;
unsigned int timeout;
struct brcm_message *msg;
struct flexrm_ring *ring = chan->con_priv;
writel_relaxed(0x0, ring->regs + RING_CONTROL);
timeout = 1000;
writel_relaxed(BIT(CONTROL_FLUSH_SHIFT),
ring->regs + RING_CONTROL);
do {
if (readl_relaxed(ring->regs + RING_FLUSH_DONE) &
FLUSH_DONE_MASK)
break;
mdelay(1);
} while (timeout--);
for (reqid = 0; reqid < RING_MAX_REQ_COUNT; reqid++) {
msg = ring->requests[reqid];
if (!msg)
continue;
ring->requests[reqid] = NULL;
ida_simple_remove(&ring->requests_ida, reqid);
flexrm_dma_unmap(ring->mbox->dev, msg);
msg->error = -EIO;
mbox_chan_received_data(chan, msg);
}
if (ring->irq_requested) {
free_irq(ring->irq, ring);
ring->irq_requested = false;
}
if (ring->cmpl_base) {
dma_pool_free(ring->mbox->cmpl_pool,
ring->cmpl_base, ring->cmpl_dma_base);
ring->cmpl_base = NULL;
}
if (ring->bd_base) {
dma_pool_free(ring->mbox->bd_pool,
ring->bd_base, ring->bd_dma_base);
ring->bd_base = NULL;
}
}
static bool flexrm_last_tx_done(struct mbox_chan *chan)
{
bool ret;
unsigned long flags;
struct flexrm_ring *ring = chan->con_priv;
spin_lock_irqsave(&ring->lock, flags);
ret = (ring->last_pending_msg) ? false : true;
spin_unlock_irqrestore(&ring->lock, flags);
return ret;
}
static struct mbox_chan *flexrm_mbox_of_xlate(struct mbox_controller *cntlr,
const struct of_phandle_args *pa)
{
struct mbox_chan *chan;
struct flexrm_ring *ring;
if (pa->args_count < 3)
return ERR_PTR(-EINVAL);
if (pa->args[0] >= cntlr->num_chans)
return ERR_PTR(-ENOENT);
if (pa->args[1] > MSI_COUNT_MASK)
return ERR_PTR(-EINVAL);
if (pa->args[2] > MSI_TIMER_VAL_MASK)
return ERR_PTR(-EINVAL);
chan = &cntlr->chans[pa->args[0]];
ring = chan->con_priv;
ring->msi_count_threshold = pa->args[1];
ring->msi_timer_val = pa->args[2];
return chan;
}
static void flexrm_mbox_msi_write(struct msi_desc *desc, struct msi_msg *msg)
{
struct device *dev = msi_desc_to_dev(desc);
struct flexrm_mbox *mbox = dev_get_drvdata(dev);
struct flexrm_ring *ring = &mbox->rings[desc->platform.msi_index];
writel_relaxed(msg->address_lo, ring->regs + RING_MSI_ADDR_LS);
writel_relaxed(msg->address_hi, ring->regs + RING_MSI_ADDR_MS);
writel_relaxed(msg->data, ring->regs + RING_MSI_DATA_VALUE);
}
static int flexrm_mbox_probe(struct platform_device *pdev)
{
int index, ret = 0;
void __iomem *regs;
void __iomem *regs_end;
struct msi_desc *desc;
struct resource *iomem;
struct flexrm_ring *ring;
struct flexrm_mbox *mbox;
struct device *dev = &pdev->dev;
mbox = devm_kzalloc(dev, sizeof(*mbox), GFP_KERNEL);
if (!mbox) {
ret = -ENOMEM;
goto fail;
}
mbox->dev = dev;
platform_set_drvdata(pdev, mbox);
iomem = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!iomem || (resource_size(iomem) < RING_REGS_SIZE)) {
ret = -ENODEV;
goto fail;
}
mbox->regs = devm_ioremap_resource(&pdev->dev, iomem);
if (IS_ERR(mbox->regs)) {
ret = PTR_ERR(mbox->regs);
dev_err(&pdev->dev, "Failed to remap mailbox regs: %d\n", ret);
goto fail;
}
regs_end = mbox->regs + resource_size(iomem);
mbox->num_rings = 0;
for (regs = mbox->regs; regs < regs_end; regs += RING_REGS_SIZE) {
if (readl_relaxed(regs + RING_VER) == RING_VER_MAGIC)
mbox->num_rings++;
}
if (!mbox->num_rings) {
ret = -ENODEV;
goto fail;
}
ring = devm_kcalloc(dev, mbox->num_rings, sizeof(*ring), GFP_KERNEL);
if (!ring) {
ret = -ENOMEM;
goto fail;
}
mbox->rings = ring;
regs = mbox->regs;
for (index = 0; index < mbox->num_rings; index++) {
ring = &mbox->rings[index];
ring->num = index;
ring->mbox = mbox;
while ((regs < regs_end) &&
(readl_relaxed(regs + RING_VER) != RING_VER_MAGIC))
regs += RING_REGS_SIZE;
if (regs_end <= regs) {
ret = -ENODEV;
goto fail;
}
ring->regs = regs;
regs += RING_REGS_SIZE;
ring->irq = UINT_MAX;
ring->irq_requested = false;
ring->msi_timer_val = MSI_TIMER_VAL_MASK;
ring->msi_count_threshold = 0x1;
ida_init(&ring->requests_ida);
memset(ring->requests, 0, sizeof(ring->requests));
ring->bd_base = NULL;
ring->bd_dma_base = 0;
ring->cmpl_base = NULL;
ring->cmpl_dma_base = 0;
spin_lock_init(&ring->lock);
ring->last_pending_msg = NULL;
ring->cmpl_read_offset = 0;
}
ret = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(40));
if (ret) {
ret = dma_set_mask_and_coherent(dev, DMA_BIT_MASK(32));
if (ret)
goto fail;
}
mbox->bd_pool = dma_pool_create("bd", dev, RING_BD_SIZE,
1 << RING_BD_ALIGN_ORDER, 0);
if (!mbox->bd_pool) {
ret = -ENOMEM;
goto fail;
}
mbox->cmpl_pool = dma_pool_create("cmpl", dev, RING_CMPL_SIZE,
1 << RING_CMPL_ALIGN_ORDER, 0);
if (!mbox->cmpl_pool) {
ret = -ENOMEM;
goto fail_destroy_bd_pool;
}
ret = platform_msi_domain_alloc_irqs(dev, mbox->num_rings,
flexrm_mbox_msi_write);
if (ret)
goto fail_destroy_cmpl_pool;
for_each_msi_entry(desc, dev) {
ring = &mbox->rings[desc->platform.msi_index];
ring->irq = desc->irq;
}
mbox->controller.txdone_irq = false;
mbox->controller.txdone_poll = true;
mbox->controller.txpoll_period = 1;
mbox->controller.ops = &flexrm_mbox_chan_ops;
mbox->controller.dev = dev;
mbox->controller.num_chans = mbox->num_rings;
mbox->controller.of_xlate = flexrm_mbox_of_xlate;
mbox->controller.chans = devm_kcalloc(dev, mbox->num_rings,
sizeof(*mbox->controller.chans), GFP_KERNEL);
if (!mbox->controller.chans) {
ret = -ENOMEM;
goto fail_free_msis;
}
for (index = 0; index < mbox->num_rings; index++)
mbox->controller.chans[index].con_priv = &mbox->rings[index];
ret = mbox_controller_register(&mbox->controller);
if (ret)
goto fail_free_msis;
dev_info(dev, "registered flexrm mailbox with %d channels\n",
mbox->controller.num_chans);
return 0;
fail_free_msis:
platform_msi_domain_free_irqs(dev);
fail_destroy_cmpl_pool:
dma_pool_destroy(mbox->cmpl_pool);
fail_destroy_bd_pool:
dma_pool_destroy(mbox->bd_pool);
fail:
return ret;
}
static int flexrm_mbox_remove(struct platform_device *pdev)
{
int index;
struct device *dev = &pdev->dev;
struct flexrm_ring *ring;
struct flexrm_mbox *mbox = platform_get_drvdata(pdev);
mbox_controller_unregister(&mbox->controller);
platform_msi_domain_free_irqs(dev);
dma_pool_destroy(mbox->cmpl_pool);
dma_pool_destroy(mbox->bd_pool);
for (index = 0; index < mbox->num_rings; index++) {
ring = &mbox->rings[index];
ida_destroy(&ring->requests_ida);
}
return 0;
}
