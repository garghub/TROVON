static inline void *octeon_get_dispatch_arg(struct octeon_device *octeon_dev,
u16 opcode, u16 subcode)
{
int idx;
struct list_head *dispatch;
void *fn_arg = NULL;
u16 combined_opcode = OPCODE_SUBCODE(opcode, subcode);
idx = combined_opcode & OCTEON_OPCODE_MASK;
spin_lock_bh(&octeon_dev->dispatch.lock);
if (octeon_dev->dispatch.count == 0) {
spin_unlock_bh(&octeon_dev->dispatch.lock);
return NULL;
}
if (octeon_dev->dispatch.dlist[idx].opcode == combined_opcode) {
fn_arg = octeon_dev->dispatch.dlist[idx].arg;
} else {
list_for_each(dispatch,
&octeon_dev->dispatch.dlist[idx].list) {
if (((struct octeon_dispatch *)dispatch)->opcode ==
combined_opcode) {
fn_arg = ((struct octeon_dispatch *)
dispatch)->arg;
break;
}
}
}
spin_unlock_bh(&octeon_dev->dispatch.lock);
return fn_arg;
}
u32 octeon_droq_check_hw_for_pkts(struct octeon_droq *droq)
{
u32 pkt_count = 0;
pkt_count = readl(droq->pkts_sent_reg);
if (pkt_count) {
atomic_add(pkt_count, &droq->pkts_pending);
writel(pkt_count, droq->pkts_sent_reg);
}
return pkt_count;
}
static void octeon_droq_compute_max_packet_bufs(struct octeon_droq *droq)
{
u32 count = 0;
droq->max_empty_descs = 0;
do {
droq->max_empty_descs++;
count += droq->buffer_size;
} while (count < (64 * 1024));
droq->max_empty_descs = droq->max_count - droq->max_empty_descs;
}
static void octeon_droq_reset_indices(struct octeon_droq *droq)
{
droq->read_idx = 0;
droq->write_idx = 0;
droq->refill_idx = 0;
droq->refill_count = 0;
atomic_set(&droq->pkts_pending, 0);
}
static void
octeon_droq_destroy_ring_buffers(struct octeon_device *oct,
struct octeon_droq *droq)
{
u32 i;
struct octeon_skb_page_info *pg_info;
for (i = 0; i < droq->max_count; i++) {
pg_info = &droq->recv_buf_list[i].pg_info;
if (pg_info->dma)
lio_unmap_ring(oct->pci_dev,
(u64)pg_info->dma);
pg_info->dma = 0;
if (pg_info->page)
recv_buffer_destroy(droq->recv_buf_list[i].buffer,
pg_info);
if (droq->desc_ring && droq->desc_ring[i].info_ptr)
lio_unmap_ring_info(oct->pci_dev,
(u64)droq->
desc_ring[i].info_ptr,
OCT_DROQ_INFO_SIZE);
droq->recv_buf_list[i].buffer = NULL;
}
octeon_droq_reset_indices(droq);
}
static int
octeon_droq_setup_ring_buffers(struct octeon_device *oct,
struct octeon_droq *droq)
{
u32 i;
void *buf;
struct octeon_droq_desc *desc_ring = droq->desc_ring;
for (i = 0; i < droq->max_count; i++) {
buf = recv_buffer_alloc(oct, &droq->recv_buf_list[i].pg_info);
if (!buf) {
dev_err(&oct->pci_dev->dev, "%s buffer alloc failed\n",
__func__);
droq->stats.rx_alloc_failure++;
return -ENOMEM;
}
droq->recv_buf_list[i].buffer = buf;
droq->recv_buf_list[i].data = get_rbd(buf);
droq->info_list[i].length = 0;
desc_ring[i].info_ptr = lio_map_ring_info(droq, i);
desc_ring[i].buffer_ptr =
lio_map_ring(droq->recv_buf_list[i].buffer);
}
octeon_droq_reset_indices(droq);
octeon_droq_compute_max_packet_bufs(droq);
return 0;
}
int octeon_delete_droq(struct octeon_device *oct, u32 q_no)
{
struct octeon_droq *droq = oct->droq[q_no];
dev_dbg(&oct->pci_dev->dev, "%s[%d]\n", __func__, q_no);
octeon_droq_destroy_ring_buffers(oct, droq);
vfree(droq->recv_buf_list);
if (droq->info_base_addr)
cnnic_free_aligned_dma(oct->pci_dev, droq->info_list,
droq->info_alloc_size,
droq->info_base_addr,
droq->info_list_dma);
if (droq->desc_ring)
lio_dma_free(oct, (droq->max_count * OCT_DROQ_DESC_SIZE),
droq->desc_ring, droq->desc_ring_dma);
memset(droq, 0, OCT_DROQ_SIZE);
return 0;
}
int octeon_init_droq(struct octeon_device *oct,
u32 q_no,
u32 num_descs,
u32 desc_size,
void *app_ctx)
{
struct octeon_droq *droq;
u32 desc_ring_size = 0, c_num_descs = 0, c_buf_size = 0;
u32 c_pkts_per_intr = 0, c_refill_threshold = 0;
int orig_node = dev_to_node(&oct->pci_dev->dev);
int numa_node = cpu_to_node(q_no % num_online_cpus());
dev_dbg(&oct->pci_dev->dev, "%s[%d]\n", __func__, q_no);
droq = oct->droq[q_no];
memset(droq, 0, OCT_DROQ_SIZE);
droq->oct_dev = oct;
droq->q_no = q_no;
if (app_ctx)
droq->app_ctx = app_ctx;
else
droq->app_ctx = (void *)(size_t)q_no;
c_num_descs = num_descs;
c_buf_size = desc_size;
if (OCTEON_CN6XXX(oct)) {
struct octeon_config *conf6x = CHIP_FIELD(oct, cn6xxx, conf);
c_pkts_per_intr = (u32)CFG_GET_OQ_PKTS_PER_INTR(conf6x);
c_refill_threshold =
(u32)CFG_GET_OQ_REFILL_THRESHOLD(conf6x);
} else {
return 1;
}
droq->max_count = c_num_descs;
droq->buffer_size = c_buf_size;
desc_ring_size = droq->max_count * OCT_DROQ_DESC_SIZE;
set_dev_node(&oct->pci_dev->dev, numa_node);
droq->desc_ring = lio_dma_alloc(oct, desc_ring_size,
(dma_addr_t *)&droq->desc_ring_dma);
set_dev_node(&oct->pci_dev->dev, orig_node);
if (!droq->desc_ring)
droq->desc_ring = lio_dma_alloc(oct, desc_ring_size,
(dma_addr_t *)&droq->desc_ring_dma);
if (!droq->desc_ring) {
dev_err(&oct->pci_dev->dev,
"Output queue %d ring alloc failed\n", q_no);
return 1;
}
dev_dbg(&oct->pci_dev->dev, "droq[%d]: desc_ring: virt: 0x%p, dma: %lx\n",
q_no, droq->desc_ring, droq->desc_ring_dma);
dev_dbg(&oct->pci_dev->dev, "droq[%d]: num_desc: %d\n", q_no,
droq->max_count);
droq->info_list =
cnnic_numa_alloc_aligned_dma((droq->max_count *
OCT_DROQ_INFO_SIZE),
&droq->info_alloc_size,
&droq->info_base_addr,
numa_node);
if (!droq->info_list) {
dev_err(&oct->pci_dev->dev, "Cannot allocate memory for info list.\n");
lio_dma_free(oct, (droq->max_count * OCT_DROQ_DESC_SIZE),
droq->desc_ring, droq->desc_ring_dma);
return 1;
}
droq->recv_buf_list = (struct octeon_recv_buffer *)
vmalloc_node(droq->max_count *
OCT_DROQ_RECVBUF_SIZE,
numa_node);
if (!droq->recv_buf_list)
droq->recv_buf_list = (struct octeon_recv_buffer *)
vmalloc(droq->max_count *
OCT_DROQ_RECVBUF_SIZE);
if (!droq->recv_buf_list) {
dev_err(&oct->pci_dev->dev, "Output queue recv buf list alloc failed\n");
goto init_droq_fail;
}
if (octeon_droq_setup_ring_buffers(oct, droq))
goto init_droq_fail;
droq->pkts_per_intr = c_pkts_per_intr;
droq->refill_threshold = c_refill_threshold;
dev_dbg(&oct->pci_dev->dev, "DROQ INIT: max_empty_descs: %d\n",
droq->max_empty_descs);
spin_lock_init(&droq->lock);
INIT_LIST_HEAD(&droq->dispatch_list);
oct->fn_list.setup_oq_regs(oct, q_no);
oct->io_qmask.oq |= (1ULL << q_no);
return 0;
init_droq_fail:
octeon_delete_droq(oct, q_no);
return 1;
}
static inline struct octeon_recv_info *octeon_create_recv_info(
struct octeon_device *octeon_dev,
struct octeon_droq *droq,
u32 buf_cnt,
u32 idx)
{
struct octeon_droq_info *info;
struct octeon_recv_pkt *recv_pkt;
struct octeon_recv_info *recv_info;
u32 i, bytes_left;
struct octeon_skb_page_info *pg_info;
info = &droq->info_list[idx];
recv_info = octeon_alloc_recv_info(sizeof(struct __dispatch));
if (!recv_info)
return NULL;
recv_pkt = recv_info->recv_pkt;
recv_pkt->rh = info->rh;
recv_pkt->length = (u32)info->length;
recv_pkt->buffer_count = (u16)buf_cnt;
recv_pkt->octeon_id = (u16)octeon_dev->octeon_id;
i = 0;
bytes_left = (u32)info->length;
while (buf_cnt) {
{
pg_info = &droq->recv_buf_list[idx].pg_info;
lio_unmap_ring(octeon_dev->pci_dev,
(u64)pg_info->dma);
pg_info->page = NULL;
pg_info->dma = 0;
}
recv_pkt->buffer_size[i] =
(bytes_left >=
droq->buffer_size) ? droq->buffer_size : bytes_left;
recv_pkt->buffer_ptr[i] = droq->recv_buf_list[idx].buffer;
droq->recv_buf_list[idx].buffer = NULL;
INCR_INDEX_BY1(idx, droq->max_count);
bytes_left -= droq->buffer_size;
i++;
buf_cnt--;
}
return recv_info;
}
static inline u32
octeon_droq_refill_pullup_descs(struct octeon_droq *droq,
struct octeon_droq_desc *desc_ring)
{
u32 desc_refilled = 0;
u32 refill_index = droq->refill_idx;
while (refill_index != droq->read_idx) {
if (droq->recv_buf_list[refill_index].buffer) {
droq->recv_buf_list[droq->refill_idx].buffer =
droq->recv_buf_list[refill_index].buffer;
droq->recv_buf_list[droq->refill_idx].data =
droq->recv_buf_list[refill_index].data;
desc_ring[droq->refill_idx].buffer_ptr =
desc_ring[refill_index].buffer_ptr;
droq->recv_buf_list[refill_index].buffer = NULL;
desc_ring[refill_index].buffer_ptr = 0;
do {
INCR_INDEX_BY1(droq->refill_idx,
droq->max_count);
desc_refilled++;
droq->refill_count--;
} while (droq->recv_buf_list[droq->refill_idx].
buffer);
}
INCR_INDEX_BY1(refill_index, droq->max_count);
}
return desc_refilled;
}
static u32
octeon_droq_refill(struct octeon_device *octeon_dev, struct octeon_droq *droq)
{
struct octeon_droq_desc *desc_ring;
void *buf = NULL;
u8 *data;
u32 desc_refilled = 0;
struct octeon_skb_page_info *pg_info;
desc_ring = droq->desc_ring;
while (droq->refill_count && (desc_refilled < droq->max_count)) {
if (!droq->recv_buf_list[droq->refill_idx].buffer) {
pg_info =
&droq->recv_buf_list[droq->refill_idx].pg_info;
if (pg_info->page)
buf = recv_buffer_reuse(octeon_dev, pg_info);
else
buf = recv_buffer_alloc(octeon_dev, pg_info);
if (!buf) {
droq->stats.rx_alloc_failure++;
break;
}
droq->recv_buf_list[droq->refill_idx].buffer =
buf;
data = get_rbd(buf);
} else {
data = get_rbd(droq->recv_buf_list
[droq->refill_idx].buffer);
}
droq->recv_buf_list[droq->refill_idx].data = data;
desc_ring[droq->refill_idx].buffer_ptr =
lio_map_ring(droq->recv_buf_list[droq->
refill_idx].buffer);
droq->info_list[droq->refill_idx].length = 0;
INCR_INDEX_BY1(droq->refill_idx, droq->max_count);
desc_refilled++;
droq->refill_count--;
}
if (droq->refill_count)
desc_refilled +=
octeon_droq_refill_pullup_descs(droq, desc_ring);
return desc_refilled;
}
static inline u32
octeon_droq_get_bufcount(u32 buf_size, u32 total_len)
{
u32 buf_cnt = 0;
while (total_len > (buf_size * buf_cnt))
buf_cnt++;
return buf_cnt;
}
static int
octeon_droq_dispatch_pkt(struct octeon_device *oct,
struct octeon_droq *droq,
union octeon_rh *rh,
struct octeon_droq_info *info)
{
u32 cnt;
octeon_dispatch_fn_t disp_fn;
struct octeon_recv_info *rinfo;
cnt = octeon_droq_get_bufcount(droq->buffer_size, (u32)info->length);
disp_fn = octeon_get_dispatch(oct, (u16)rh->r.opcode,
(u16)rh->r.subcode);
if (disp_fn) {
rinfo = octeon_create_recv_info(oct, droq, cnt, droq->read_idx);
if (rinfo) {
struct __dispatch *rdisp = rinfo->rsvd;
rdisp->rinfo = rinfo;
rdisp->disp_fn = disp_fn;
rinfo->recv_pkt->rh = *rh;
list_add_tail(&rdisp->list,
&droq->dispatch_list);
} else {
droq->stats.dropped_nomem++;
}
} else {
dev_err(&oct->pci_dev->dev, "DROQ: No dispatch function (opcode %u/%u)\n",
(unsigned int)rh->r.opcode,
(unsigned int)rh->r.subcode);
droq->stats.dropped_nodispatch++;
}
return cnt;
}
static inline void octeon_droq_drop_packets(struct octeon_device *oct,
struct octeon_droq *droq,
u32 cnt)
{
u32 i = 0, buf_cnt;
struct octeon_droq_info *info;
for (i = 0; i < cnt; i++) {
info = &droq->info_list[droq->read_idx];
octeon_swap_8B_data((u64 *)info, 2);
if (info->length) {
info->length -= OCT_RH_SIZE;
droq->stats.bytes_received += info->length;
buf_cnt = octeon_droq_get_bufcount(droq->buffer_size,
(u32)info->length);
} else {
dev_err(&oct->pci_dev->dev, "DROQ: In drop: pkt with len 0\n");
buf_cnt = 1;
}
INCR_INDEX(droq->read_idx, buf_cnt, droq->max_count);
droq->refill_count += buf_cnt;
}
}
static u32
octeon_droq_fast_process_packets(struct octeon_device *oct,
struct octeon_droq *droq,
u32 pkts_to_process)
{
struct octeon_droq_info *info;
union octeon_rh *rh;
u32 pkt, total_len = 0, pkt_count;
pkt_count = pkts_to_process;
for (pkt = 0; pkt < pkt_count; pkt++) {
u32 pkt_len = 0;
struct sk_buff *nicbuf = NULL;
struct octeon_skb_page_info *pg_info;
void *buf;
info = &droq->info_list[droq->read_idx];
octeon_swap_8B_data((u64 *)info, 2);
if (!info->length) {
dev_err(&oct->pci_dev->dev,
"DROQ[%d] idx: %d len:0, pkt_cnt: %d\n",
droq->q_no, droq->read_idx, pkt_count);
print_hex_dump_bytes("", DUMP_PREFIX_ADDRESS,
(u8 *)info,
OCT_DROQ_INFO_SIZE);
break;
}
info->length -= OCT_RH_SIZE;
rh = &info->rh;
total_len += (u32)info->length;
if (OPCODE_SLOW_PATH(rh)) {
u32 buf_cnt;
buf_cnt = octeon_droq_dispatch_pkt(oct, droq, rh, info);
INCR_INDEX(droq->read_idx, buf_cnt, droq->max_count);
droq->refill_count += buf_cnt;
} else {
if (info->length <= droq->buffer_size) {
pkt_len = (u32)info->length;
nicbuf = droq->recv_buf_list[
droq->read_idx].buffer;
pg_info = &droq->recv_buf_list[
droq->read_idx].pg_info;
if (recv_buffer_recycle(oct, pg_info))
pg_info->page = NULL;
droq->recv_buf_list[droq->read_idx].buffer =
NULL;
INCR_INDEX_BY1(droq->read_idx, droq->max_count);
droq->refill_count++;
} else {
nicbuf = octeon_fast_packet_alloc((u32)
info->length);
pkt_len = 0;
while (pkt_len < info->length) {
int cpy_len, idx = droq->read_idx;
cpy_len = ((pkt_len + droq->buffer_size)
> info->length) ?
((u32)info->length - pkt_len) :
droq->buffer_size;
if (nicbuf) {
octeon_fast_packet_next(droq,
nicbuf,
cpy_len,
idx);
buf = droq->recv_buf_list[idx].
buffer;
recv_buffer_fast_free(buf);
droq->recv_buf_list[idx].buffer
= NULL;
} else {
droq->stats.rx_alloc_failure++;
}
pkt_len += cpy_len;
INCR_INDEX_BY1(droq->read_idx,
droq->max_count);
droq->refill_count++;
}
}
if (nicbuf) {
if (droq->ops.fptr) {
droq->ops.fptr(oct->octeon_id,
nicbuf, pkt_len,
rh, &droq->napi,
droq->ops.farg);
} else {
recv_buffer_free(nicbuf);
}
}
}
if (droq->refill_count >= droq->refill_threshold) {
int desc_refilled = octeon_droq_refill(oct, droq);
wmb();
writel((desc_refilled), droq->pkts_credit_reg);
mmiowb();
}
}
droq->stats.pkts_received += pkt;
droq->stats.bytes_received += total_len;
if ((droq->ops.drop_on_max) && (pkts_to_process - pkt)) {
octeon_droq_drop_packets(oct, droq, (pkts_to_process - pkt));
droq->stats.dropped_toomany += (pkts_to_process - pkt);
return pkts_to_process;
}
return pkt;
}
int
octeon_droq_process_packets(struct octeon_device *oct,
struct octeon_droq *droq,
u32 budget)
{
u32 pkt_count = 0, pkts_processed = 0;
struct list_head *tmp, *tmp2;
pkt_count = atomic_read(&droq->pkts_pending);
if (!pkt_count)
return 0;
if (pkt_count > budget)
pkt_count = budget;
spin_lock(&droq->lock);
pkts_processed = octeon_droq_fast_process_packets(oct, droq, pkt_count);
atomic_sub(pkts_processed, &droq->pkts_pending);
spin_unlock(&droq->lock);
list_for_each_safe(tmp, tmp2, &droq->dispatch_list) {
struct __dispatch *rdisp = (struct __dispatch *)tmp;
list_del(tmp);
rdisp->disp_fn(rdisp->rinfo,
octeon_get_dispatch_arg
(oct,
(u16)rdisp->rinfo->recv_pkt->rh.r.opcode,
(u16)rdisp->rinfo->recv_pkt->rh.r.subcode));
}
if (atomic_read(&droq->pkts_pending))
return 1;
return 0;
}
static int
octeon_droq_process_poll_pkts(struct octeon_device *oct,
struct octeon_droq *droq, u32 budget)
{
struct list_head *tmp, *tmp2;
u32 pkts_available = 0, pkts_processed = 0;
u32 total_pkts_processed = 0;
if (budget > droq->max_count)
budget = droq->max_count;
spin_lock(&droq->lock);
while (total_pkts_processed < budget) {
pkts_available =
CVM_MIN((budget - total_pkts_processed),
(u32)(atomic_read(&droq->pkts_pending)));
if (pkts_available == 0)
break;
pkts_processed =
octeon_droq_fast_process_packets(oct, droq,
pkts_available);
atomic_sub(pkts_processed, &droq->pkts_pending);
total_pkts_processed += pkts_processed;
octeon_droq_check_hw_for_pkts(droq);
}
spin_unlock(&droq->lock);
list_for_each_safe(tmp, tmp2, &droq->dispatch_list) {
struct __dispatch *rdisp = (struct __dispatch *)tmp;
list_del(tmp);
rdisp->disp_fn(rdisp->rinfo,
octeon_get_dispatch_arg
(oct,
(u16)rdisp->rinfo->recv_pkt->rh.r.opcode,
(u16)rdisp->rinfo->recv_pkt->rh.r.subcode));
}
return total_pkts_processed;
}
int
octeon_process_droq_poll_cmd(struct octeon_device *oct, u32 q_no, int cmd,
u32 arg)
{
struct octeon_droq *droq;
droq = oct->droq[q_no];
if (cmd == POLL_EVENT_PROCESS_PKTS)
return octeon_droq_process_poll_pkts(oct, droq, arg);
if (cmd == POLL_EVENT_PENDING_PKTS) {
u32 pkt_cnt = atomic_read(&droq->pkts_pending);
return octeon_droq_process_packets(oct, droq, pkt_cnt);
}
if (cmd == POLL_EVENT_ENABLE_INTR) {
u32 value;
unsigned long flags;
switch (oct->chip_id) {
case OCTEON_CN66XX:
case OCTEON_CN68XX: {
struct octeon_cn6xxx *cn6xxx =
(struct octeon_cn6xxx *)oct->chip;
spin_lock_irqsave
(&cn6xxx->lock_for_droq_int_enb_reg, flags);
value =
octeon_read_csr(oct,
CN6XXX_SLI_PKT_TIME_INT_ENB);
value |= (1 << q_no);
octeon_write_csr(oct,
CN6XXX_SLI_PKT_TIME_INT_ENB,
value);
value =
octeon_read_csr(oct,
CN6XXX_SLI_PKT_CNT_INT_ENB);
value |= (1 << q_no);
octeon_write_csr(oct,
CN6XXX_SLI_PKT_CNT_INT_ENB,
value);
spin_unlock_irqrestore
(&cn6xxx->lock_for_droq_int_enb_reg, flags);
return 0;
}
break;
}
return 0;
}
dev_err(&oct->pci_dev->dev, "%s Unknown command: %d\n", __func__, cmd);
return -EINVAL;
}
int octeon_register_droq_ops(struct octeon_device *oct, u32 q_no,
struct octeon_droq_ops *ops)
{
struct octeon_droq *droq;
unsigned long flags;
struct octeon_config *oct_cfg = NULL;
oct_cfg = octeon_get_conf(oct);
if (!oct_cfg)
return -EINVAL;
if (!(ops)) {
dev_err(&oct->pci_dev->dev, "%s: droq_ops pointer is NULL\n",
__func__);
return -EINVAL;
}
if (q_no >= CFG_GET_OQ_MAX_Q(oct_cfg)) {
dev_err(&oct->pci_dev->dev, "%s: droq id (%d) exceeds MAX (%d)\n",
__func__, q_no, (oct->num_oqs - 1));
return -EINVAL;
}
droq = oct->droq[q_no];
spin_lock_irqsave(&droq->lock, flags);
memcpy(&droq->ops, ops, sizeof(struct octeon_droq_ops));
spin_unlock_irqrestore(&droq->lock, flags);
return 0;
}
int octeon_unregister_droq_ops(struct octeon_device *oct, u32 q_no)
{
unsigned long flags;
struct octeon_droq *droq;
struct octeon_config *oct_cfg = NULL;
oct_cfg = octeon_get_conf(oct);
if (!oct_cfg)
return -EINVAL;
if (q_no >= CFG_GET_OQ_MAX_Q(oct_cfg)) {
dev_err(&oct->pci_dev->dev, "%s: droq id (%d) exceeds MAX (%d)\n",
__func__, q_no, oct->num_oqs - 1);
return -EINVAL;
}
droq = oct->droq[q_no];
if (!droq) {
dev_info(&oct->pci_dev->dev,
"Droq id (%d) not available.\n", q_no);
return 0;
}
spin_lock_irqsave(&droq->lock, flags);
droq->ops.fptr = NULL;
droq->ops.farg = NULL;
droq->ops.drop_on_max = 0;
spin_unlock_irqrestore(&droq->lock, flags);
return 0;
}
int octeon_create_droq(struct octeon_device *oct,
u32 q_no, u32 num_descs,
u32 desc_size, void *app_ctx)
{
struct octeon_droq *droq;
int numa_node = cpu_to_node(q_no % num_online_cpus());
if (oct->droq[q_no]) {
dev_dbg(&oct->pci_dev->dev, "Droq already in use. Cannot create droq %d again\n",
q_no);
return 1;
}
droq = vmalloc_node(sizeof(*droq), numa_node);
if (!droq)
droq = vmalloc(sizeof(*droq));
if (!droq)
goto create_droq_fail;
memset(droq, 0, sizeof(struct octeon_droq));
octeon_set_droq_pkt_op(oct, q_no, 0);
oct->droq[q_no] = droq;
octeon_init_droq(oct, q_no, num_descs, desc_size, app_ctx);
oct->num_oqs++;
dev_dbg(&oct->pci_dev->dev, "%s: Total number of OQ: %d\n", __func__,
oct->num_oqs);
return 0;
create_droq_fail:
octeon_delete_droq(oct, q_no);
return -ENOMEM;
}
