static u32 ccp_alloc_ksb(struct ccp_device *ccp, unsigned int count)
{
int start;
for (;;) {
mutex_lock(&ccp->ksb_mutex);
start = (u32)bitmap_find_next_zero_area(ccp->ksb,
ccp->ksb_count,
ccp->ksb_start,
count, 0);
if (start <= ccp->ksb_count) {
bitmap_set(ccp->ksb, start, count);
mutex_unlock(&ccp->ksb_mutex);
break;
}
ccp->ksb_avail = 0;
mutex_unlock(&ccp->ksb_mutex);
if (wait_event_interruptible(ccp->ksb_queue, ccp->ksb_avail))
return 0;
}
return KSB_START + start;
}
static void ccp_free_ksb(struct ccp_device *ccp, unsigned int start,
unsigned int count)
{
if (!start)
return;
mutex_lock(&ccp->ksb_mutex);
bitmap_clear(ccp->ksb, start - KSB_START, count);
ccp->ksb_avail = 1;
mutex_unlock(&ccp->ksb_mutex);
wake_up_interruptible_all(&ccp->ksb_queue);
}
static u32 ccp_gen_jobid(struct ccp_device *ccp)
{
return atomic_inc_return(&ccp->current_id) & CCP_JOBID_MASK;
}
static void ccp_sg_free(struct ccp_sg_workarea *wa)
{
if (wa->dma_count)
dma_unmap_sg(wa->dma_dev, wa->dma_sg, wa->nents, wa->dma_dir);
wa->dma_count = 0;
}
static int ccp_init_sg_workarea(struct ccp_sg_workarea *wa, struct device *dev,
struct scatterlist *sg, u64 len,
enum dma_data_direction dma_dir)
{
memset(wa, 0, sizeof(*wa));
wa->sg = sg;
if (!sg)
return 0;
wa->nents = sg_nents_for_len(sg, len);
if (wa->nents < 0)
return wa->nents;
wa->bytes_left = len;
wa->sg_used = 0;
if (len == 0)
return 0;
if (dma_dir == DMA_NONE)
return 0;
wa->dma_sg = sg;
wa->dma_dev = dev;
wa->dma_dir = dma_dir;
wa->dma_count = dma_map_sg(dev, sg, wa->nents, dma_dir);
if (!wa->dma_count)
return -ENOMEM;
return 0;
}
static void ccp_update_sg_workarea(struct ccp_sg_workarea *wa, unsigned int len)
{
unsigned int nbytes = min_t(u64, len, wa->bytes_left);
if (!wa->sg)
return;
wa->sg_used += nbytes;
wa->bytes_left -= nbytes;
if (wa->sg_used == wa->sg->length) {
wa->sg = sg_next(wa->sg);
wa->sg_used = 0;
}
}
static void ccp_dm_free(struct ccp_dm_workarea *wa)
{
if (wa->length <= CCP_DMAPOOL_MAX_SIZE) {
if (wa->address)
dma_pool_free(wa->dma_pool, wa->address,
wa->dma.address);
} else {
if (wa->dma.address)
dma_unmap_single(wa->dev, wa->dma.address, wa->length,
wa->dma.dir);
kfree(wa->address);
}
wa->address = NULL;
wa->dma.address = 0;
}
static int ccp_init_dm_workarea(struct ccp_dm_workarea *wa,
struct ccp_cmd_queue *cmd_q,
unsigned int len,
enum dma_data_direction dir)
{
memset(wa, 0, sizeof(*wa));
if (!len)
return 0;
wa->dev = cmd_q->ccp->dev;
wa->length = len;
if (len <= CCP_DMAPOOL_MAX_SIZE) {
wa->dma_pool = cmd_q->dma_pool;
wa->address = dma_pool_alloc(wa->dma_pool, GFP_KERNEL,
&wa->dma.address);
if (!wa->address)
return -ENOMEM;
wa->dma.length = CCP_DMAPOOL_MAX_SIZE;
memset(wa->address, 0, CCP_DMAPOOL_MAX_SIZE);
} else {
wa->address = kzalloc(len, GFP_KERNEL);
if (!wa->address)
return -ENOMEM;
wa->dma.address = dma_map_single(wa->dev, wa->address, len,
dir);
if (!wa->dma.address)
return -ENOMEM;
wa->dma.length = len;
}
wa->dma.dir = dir;
return 0;
}
static void ccp_set_dm_area(struct ccp_dm_workarea *wa, unsigned int wa_offset,
struct scatterlist *sg, unsigned int sg_offset,
unsigned int len)
{
WARN_ON(!wa->address);
scatterwalk_map_and_copy(wa->address + wa_offset, sg, sg_offset, len,
0);
}
static void ccp_get_dm_area(struct ccp_dm_workarea *wa, unsigned int wa_offset,
struct scatterlist *sg, unsigned int sg_offset,
unsigned int len)
{
WARN_ON(!wa->address);
scatterwalk_map_and_copy(wa->address + wa_offset, sg, sg_offset, len,
1);
}
static int ccp_reverse_set_dm_area(struct ccp_dm_workarea *wa,
struct scatterlist *sg,
unsigned int len, unsigned int se_len,
bool sign_extend)
{
unsigned int nbytes, sg_offset, dm_offset, ksb_len, i;
u8 buffer[CCP_REVERSE_BUF_SIZE];
if (WARN_ON(se_len > sizeof(buffer)))
return -EINVAL;
sg_offset = len;
dm_offset = 0;
nbytes = len;
while (nbytes) {
ksb_len = min_t(unsigned int, nbytes, se_len);
sg_offset -= ksb_len;
scatterwalk_map_and_copy(buffer, sg, sg_offset, ksb_len, 0);
for (i = 0; i < ksb_len; i++)
wa->address[dm_offset + i] = buffer[ksb_len - i - 1];
dm_offset += ksb_len;
nbytes -= ksb_len;
if ((ksb_len != se_len) && sign_extend) {
if (wa->address[dm_offset - 1] & 0x80)
memset(wa->address + dm_offset, 0xff,
se_len - ksb_len);
}
}
return 0;
}
static void ccp_reverse_get_dm_area(struct ccp_dm_workarea *wa,
struct scatterlist *sg,
unsigned int len)
{
unsigned int nbytes, sg_offset, dm_offset, ksb_len, i;
u8 buffer[CCP_REVERSE_BUF_SIZE];
sg_offset = 0;
dm_offset = len;
nbytes = len;
while (nbytes) {
ksb_len = min_t(unsigned int, nbytes, sizeof(buffer));
dm_offset -= ksb_len;
for (i = 0; i < ksb_len; i++)
buffer[ksb_len - i - 1] = wa->address[dm_offset + i];
scatterwalk_map_and_copy(buffer, sg, sg_offset, ksb_len, 1);
sg_offset += ksb_len;
nbytes -= ksb_len;
}
}
static void ccp_free_data(struct ccp_data *data, struct ccp_cmd_queue *cmd_q)
{
ccp_dm_free(&data->dm_wa);
ccp_sg_free(&data->sg_wa);
}
static int ccp_init_data(struct ccp_data *data, struct ccp_cmd_queue *cmd_q,
struct scatterlist *sg, u64 sg_len,
unsigned int dm_len,
enum dma_data_direction dir)
{
int ret;
memset(data, 0, sizeof(*data));
ret = ccp_init_sg_workarea(&data->sg_wa, cmd_q->ccp->dev, sg, sg_len,
dir);
if (ret)
goto e_err;
ret = ccp_init_dm_workarea(&data->dm_wa, cmd_q, dm_len, dir);
if (ret)
goto e_err;
return 0;
e_err:
ccp_free_data(data, cmd_q);
return ret;
}
static unsigned int ccp_queue_buf(struct ccp_data *data, unsigned int from)
{
struct ccp_sg_workarea *sg_wa = &data->sg_wa;
struct ccp_dm_workarea *dm_wa = &data->dm_wa;
unsigned int buf_count, nbytes;
if (!from)
memset(dm_wa->address, 0, dm_wa->length);
if (!sg_wa->sg)
return 0;
nbytes = min_t(u64, sg_wa->bytes_left, dm_wa->length);
scatterwalk_map_and_copy(dm_wa->address, sg_wa->sg, sg_wa->sg_used,
nbytes, from);
buf_count = 0;
while (sg_wa->bytes_left && (buf_count < dm_wa->length)) {
nbytes = min(sg_wa->sg->length - sg_wa->sg_used,
dm_wa->length - buf_count);
nbytes = min_t(u64, sg_wa->bytes_left, nbytes);
buf_count += nbytes;
ccp_update_sg_workarea(sg_wa, nbytes);
}
return buf_count;
}
static unsigned int ccp_fill_queue_buf(struct ccp_data *data)
{
return ccp_queue_buf(data, 0);
}
static unsigned int ccp_empty_queue_buf(struct ccp_data *data)
{
return ccp_queue_buf(data, 1);
}
static void ccp_prepare_data(struct ccp_data *src, struct ccp_data *dst,
struct ccp_op *op, unsigned int block_size,
bool blocksize_op)
{
unsigned int sg_src_len, sg_dst_len, op_len;
sg_src_len = sg_dma_len(src->sg_wa.sg) - src->sg_wa.sg_used;
sg_src_len = min_t(u64, src->sg_wa.bytes_left, sg_src_len);
if (dst) {
sg_dst_len = sg_dma_len(dst->sg_wa.sg) - dst->sg_wa.sg_used;
sg_dst_len = min_t(u64, src->sg_wa.bytes_left, sg_dst_len);
op_len = min(sg_src_len, sg_dst_len);
} else {
op_len = sg_src_len;
}
op_len = max(op_len, block_size);
op->soc = 0;
if (sg_src_len < block_size) {
int cp_len = ccp_fill_queue_buf(src);
op->soc = 1;
op->src.u.dma.address = src->dm_wa.dma.address;
op->src.u.dma.offset = 0;
op->src.u.dma.length = (blocksize_op) ? block_size : cp_len;
} else {
op->src.u.dma.address = sg_dma_address(src->sg_wa.sg);
op->src.u.dma.offset = src->sg_wa.sg_used;
op->src.u.dma.length = op_len & ~(block_size - 1);
ccp_update_sg_workarea(&src->sg_wa, op->src.u.dma.length);
}
if (dst) {
if (sg_dst_len < block_size) {
op->soc = 1;
op->dst.u.dma.address = dst->dm_wa.dma.address;
op->dst.u.dma.offset = 0;
op->dst.u.dma.length = op->src.u.dma.length;
} else {
op->dst.u.dma.address = sg_dma_address(dst->sg_wa.sg);
op->dst.u.dma.offset = dst->sg_wa.sg_used;
op->dst.u.dma.length = op->src.u.dma.length;
}
}
}
static void ccp_process_data(struct ccp_data *src, struct ccp_data *dst,
struct ccp_op *op)
{
op->init = 0;
if (dst) {
if (op->dst.u.dma.address == dst->dm_wa.dma.address)
ccp_empty_queue_buf(dst);
else
ccp_update_sg_workarea(&dst->sg_wa,
op->dst.u.dma.length);
}
}
static int ccp_copy_to_from_ksb(struct ccp_cmd_queue *cmd_q,
struct ccp_dm_workarea *wa, u32 jobid, u32 ksb,
u32 byte_swap, bool from)
{
struct ccp_op op;
memset(&op, 0, sizeof(op));
op.cmd_q = cmd_q;
op.jobid = jobid;
op.eom = 1;
if (from) {
op.soc = 1;
op.src.type = CCP_MEMTYPE_KSB;
op.src.u.ksb = ksb;
op.dst.type = CCP_MEMTYPE_SYSTEM;
op.dst.u.dma.address = wa->dma.address;
op.dst.u.dma.length = wa->length;
} else {
op.src.type = CCP_MEMTYPE_SYSTEM;
op.src.u.dma.address = wa->dma.address;
op.src.u.dma.length = wa->length;
op.dst.type = CCP_MEMTYPE_KSB;
op.dst.u.ksb = ksb;
}
op.u.passthru.byte_swap = byte_swap;
return cmd_q->ccp->vdata->perform->perform_passthru(&op);
}
static int ccp_copy_to_ksb(struct ccp_cmd_queue *cmd_q,
struct ccp_dm_workarea *wa, u32 jobid, u32 ksb,
u32 byte_swap)
{
return ccp_copy_to_from_ksb(cmd_q, wa, jobid, ksb, byte_swap, false);
}
static int ccp_copy_from_ksb(struct ccp_cmd_queue *cmd_q,
struct ccp_dm_workarea *wa, u32 jobid, u32 ksb,
u32 byte_swap)
{
return ccp_copy_to_from_ksb(cmd_q, wa, jobid, ksb, byte_swap, true);
}
static int ccp_run_aes_cmac_cmd(struct ccp_cmd_queue *cmd_q,
struct ccp_cmd *cmd)
{
struct ccp_aes_engine *aes = &cmd->u.aes;
struct ccp_dm_workarea key, ctx;
struct ccp_data src;
struct ccp_op op;
unsigned int dm_offset;
int ret;
if (!((aes->key_len == AES_KEYSIZE_128) ||
(aes->key_len == AES_KEYSIZE_192) ||
(aes->key_len == AES_KEYSIZE_256)))
return -EINVAL;
if (aes->src_len & (AES_BLOCK_SIZE - 1))
return -EINVAL;
if (aes->iv_len != AES_BLOCK_SIZE)
return -EINVAL;
if (!aes->key || !aes->iv || !aes->src)
return -EINVAL;
if (aes->cmac_final) {
if (aes->cmac_key_len != AES_BLOCK_SIZE)
return -EINVAL;
if (!aes->cmac_key)
return -EINVAL;
}
BUILD_BUG_ON(CCP_AES_KEY_KSB_COUNT != 1);
BUILD_BUG_ON(CCP_AES_CTX_KSB_COUNT != 1);
ret = -EIO;
memset(&op, 0, sizeof(op));
op.cmd_q = cmd_q;
op.jobid = ccp_gen_jobid(cmd_q->ccp);
op.ksb_key = cmd_q->ksb_key;
op.ksb_ctx = cmd_q->ksb_ctx;
op.init = 1;
op.u.aes.type = aes->type;
op.u.aes.mode = aes->mode;
op.u.aes.action = aes->action;
ret = ccp_init_dm_workarea(&key, cmd_q,
CCP_AES_KEY_KSB_COUNT * CCP_KSB_BYTES,
DMA_TO_DEVICE);
if (ret)
return ret;
dm_offset = CCP_KSB_BYTES - aes->key_len;
ccp_set_dm_area(&key, dm_offset, aes->key, 0, aes->key_len);
ret = ccp_copy_to_ksb(cmd_q, &key, op.jobid, op.ksb_key,
CCP_PASSTHRU_BYTESWAP_256BIT);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_key;
}
ret = ccp_init_dm_workarea(&ctx, cmd_q,
CCP_AES_CTX_KSB_COUNT * CCP_KSB_BYTES,
DMA_BIDIRECTIONAL);
if (ret)
goto e_key;
dm_offset = CCP_KSB_BYTES - AES_BLOCK_SIZE;
ccp_set_dm_area(&ctx, dm_offset, aes->iv, 0, aes->iv_len);
ret = ccp_copy_to_ksb(cmd_q, &ctx, op.jobid, op.ksb_ctx,
CCP_PASSTHRU_BYTESWAP_256BIT);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_ctx;
}
ret = ccp_init_data(&src, cmd_q, aes->src, aes->src_len,
AES_BLOCK_SIZE, DMA_TO_DEVICE);
if (ret)
goto e_ctx;
while (src.sg_wa.bytes_left) {
ccp_prepare_data(&src, NULL, &op, AES_BLOCK_SIZE, true);
if (aes->cmac_final && !src.sg_wa.bytes_left) {
op.eom = 1;
ret = ccp_copy_from_ksb(cmd_q, &ctx, op.jobid,
op.ksb_ctx,
CCP_PASSTHRU_BYTESWAP_256BIT);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_src;
}
ccp_set_dm_area(&ctx, 0, aes->cmac_key, 0,
aes->cmac_key_len);
ret = ccp_copy_to_ksb(cmd_q, &ctx, op.jobid, op.ksb_ctx,
CCP_PASSTHRU_BYTESWAP_256BIT);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_src;
}
}
ret = cmd_q->ccp->vdata->perform->perform_aes(&op);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_src;
}
ccp_process_data(&src, NULL, &op);
}
ret = ccp_copy_from_ksb(cmd_q, &ctx, op.jobid, op.ksb_ctx,
CCP_PASSTHRU_BYTESWAP_256BIT);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_src;
}
dm_offset = CCP_KSB_BYTES - AES_BLOCK_SIZE;
ccp_get_dm_area(&ctx, dm_offset, aes->iv, 0, aes->iv_len);
e_src:
ccp_free_data(&src, cmd_q);
e_ctx:
ccp_dm_free(&ctx);
e_key:
ccp_dm_free(&key);
return ret;
}
static int ccp_run_aes_cmd(struct ccp_cmd_queue *cmd_q, struct ccp_cmd *cmd)
{
struct ccp_aes_engine *aes = &cmd->u.aes;
struct ccp_dm_workarea key, ctx;
struct ccp_data src, dst;
struct ccp_op op;
unsigned int dm_offset;
bool in_place = false;
int ret;
if (aes->mode == CCP_AES_MODE_CMAC)
return ccp_run_aes_cmac_cmd(cmd_q, cmd);
if (!((aes->key_len == AES_KEYSIZE_128) ||
(aes->key_len == AES_KEYSIZE_192) ||
(aes->key_len == AES_KEYSIZE_256)))
return -EINVAL;
if (((aes->mode == CCP_AES_MODE_ECB) ||
(aes->mode == CCP_AES_MODE_CBC) ||
(aes->mode == CCP_AES_MODE_CFB)) &&
(aes->src_len & (AES_BLOCK_SIZE - 1)))
return -EINVAL;
if (!aes->key || !aes->src || !aes->dst)
return -EINVAL;
if (aes->mode != CCP_AES_MODE_ECB) {
if (aes->iv_len != AES_BLOCK_SIZE)
return -EINVAL;
if (!aes->iv)
return -EINVAL;
}
BUILD_BUG_ON(CCP_AES_KEY_KSB_COUNT != 1);
BUILD_BUG_ON(CCP_AES_CTX_KSB_COUNT != 1);
ret = -EIO;
memset(&op, 0, sizeof(op));
op.cmd_q = cmd_q;
op.jobid = ccp_gen_jobid(cmd_q->ccp);
op.ksb_key = cmd_q->ksb_key;
op.ksb_ctx = cmd_q->ksb_ctx;
op.init = (aes->mode == CCP_AES_MODE_ECB) ? 0 : 1;
op.u.aes.type = aes->type;
op.u.aes.mode = aes->mode;
op.u.aes.action = aes->action;
ret = ccp_init_dm_workarea(&key, cmd_q,
CCP_AES_KEY_KSB_COUNT * CCP_KSB_BYTES,
DMA_TO_DEVICE);
if (ret)
return ret;
dm_offset = CCP_KSB_BYTES - aes->key_len;
ccp_set_dm_area(&key, dm_offset, aes->key, 0, aes->key_len);
ret = ccp_copy_to_ksb(cmd_q, &key, op.jobid, op.ksb_key,
CCP_PASSTHRU_BYTESWAP_256BIT);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_key;
}
ret = ccp_init_dm_workarea(&ctx, cmd_q,
CCP_AES_CTX_KSB_COUNT * CCP_KSB_BYTES,
DMA_BIDIRECTIONAL);
if (ret)
goto e_key;
if (aes->mode != CCP_AES_MODE_ECB) {
dm_offset = CCP_KSB_BYTES - AES_BLOCK_SIZE;
ccp_set_dm_area(&ctx, dm_offset, aes->iv, 0, aes->iv_len);
ret = ccp_copy_to_ksb(cmd_q, &ctx, op.jobid, op.ksb_ctx,
CCP_PASSTHRU_BYTESWAP_256BIT);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_ctx;
}
}
if (sg_virt(aes->src) == sg_virt(aes->dst))
in_place = true;
ret = ccp_init_data(&src, cmd_q, aes->src, aes->src_len,
AES_BLOCK_SIZE,
in_place ? DMA_BIDIRECTIONAL : DMA_TO_DEVICE);
if (ret)
goto e_ctx;
if (in_place) {
dst = src;
} else {
ret = ccp_init_data(&dst, cmd_q, aes->dst, aes->src_len,
AES_BLOCK_SIZE, DMA_FROM_DEVICE);
if (ret)
goto e_src;
}
while (src.sg_wa.bytes_left) {
ccp_prepare_data(&src, &dst, &op, AES_BLOCK_SIZE, true);
if (!src.sg_wa.bytes_left) {
op.eom = 1;
if (aes->mode == CCP_AES_MODE_ECB)
op.soc = 1;
}
ret = cmd_q->ccp->vdata->perform->perform_aes(&op);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_dst;
}
ccp_process_data(&src, &dst, &op);
}
if (aes->mode != CCP_AES_MODE_ECB) {
ret = ccp_copy_from_ksb(cmd_q, &ctx, op.jobid, op.ksb_ctx,
CCP_PASSTHRU_BYTESWAP_256BIT);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_dst;
}
dm_offset = CCP_KSB_BYTES - AES_BLOCK_SIZE;
ccp_get_dm_area(&ctx, dm_offset, aes->iv, 0, aes->iv_len);
}
e_dst:
if (!in_place)
ccp_free_data(&dst, cmd_q);
e_src:
ccp_free_data(&src, cmd_q);
e_ctx:
ccp_dm_free(&ctx);
e_key:
ccp_dm_free(&key);
return ret;
}
static int ccp_run_xts_aes_cmd(struct ccp_cmd_queue *cmd_q,
struct ccp_cmd *cmd)
{
struct ccp_xts_aes_engine *xts = &cmd->u.xts;
struct ccp_dm_workarea key, ctx;
struct ccp_data src, dst;
struct ccp_op op;
unsigned int unit_size, dm_offset;
bool in_place = false;
int ret;
switch (xts->unit_size) {
case CCP_XTS_AES_UNIT_SIZE_16:
unit_size = 16;
break;
case CCP_XTS_AES_UNIT_SIZE_512:
unit_size = 512;
break;
case CCP_XTS_AES_UNIT_SIZE_1024:
unit_size = 1024;
break;
case CCP_XTS_AES_UNIT_SIZE_2048:
unit_size = 2048;
break;
case CCP_XTS_AES_UNIT_SIZE_4096:
unit_size = 4096;
break;
default:
return -EINVAL;
}
if (xts->key_len != AES_KEYSIZE_128)
return -EINVAL;
if (!xts->final && (xts->src_len & (AES_BLOCK_SIZE - 1)))
return -EINVAL;
if (xts->iv_len != AES_BLOCK_SIZE)
return -EINVAL;
if (!xts->key || !xts->iv || !xts->src || !xts->dst)
return -EINVAL;
BUILD_BUG_ON(CCP_XTS_AES_KEY_KSB_COUNT != 1);
BUILD_BUG_ON(CCP_XTS_AES_CTX_KSB_COUNT != 1);
ret = -EIO;
memset(&op, 0, sizeof(op));
op.cmd_q = cmd_q;
op.jobid = ccp_gen_jobid(cmd_q->ccp);
op.ksb_key = cmd_q->ksb_key;
op.ksb_ctx = cmd_q->ksb_ctx;
op.init = 1;
op.u.xts.action = xts->action;
op.u.xts.unit_size = xts->unit_size;
ret = ccp_init_dm_workarea(&key, cmd_q,
CCP_XTS_AES_KEY_KSB_COUNT * CCP_KSB_BYTES,
DMA_TO_DEVICE);
if (ret)
return ret;
dm_offset = CCP_KSB_BYTES - AES_KEYSIZE_128;
ccp_set_dm_area(&key, dm_offset, xts->key, 0, xts->key_len);
ccp_set_dm_area(&key, 0, xts->key, dm_offset, xts->key_len);
ret = ccp_copy_to_ksb(cmd_q, &key, op.jobid, op.ksb_key,
CCP_PASSTHRU_BYTESWAP_256BIT);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_key;
}
ret = ccp_init_dm_workarea(&ctx, cmd_q,
CCP_XTS_AES_CTX_KSB_COUNT * CCP_KSB_BYTES,
DMA_BIDIRECTIONAL);
if (ret)
goto e_key;
ccp_set_dm_area(&ctx, 0, xts->iv, 0, xts->iv_len);
ret = ccp_copy_to_ksb(cmd_q, &ctx, op.jobid, op.ksb_ctx,
CCP_PASSTHRU_BYTESWAP_NOOP);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_ctx;
}
if (sg_virt(xts->src) == sg_virt(xts->dst))
in_place = true;
ret = ccp_init_data(&src, cmd_q, xts->src, xts->src_len,
unit_size,
in_place ? DMA_BIDIRECTIONAL : DMA_TO_DEVICE);
if (ret)
goto e_ctx;
if (in_place) {
dst = src;
} else {
ret = ccp_init_data(&dst, cmd_q, xts->dst, xts->src_len,
unit_size, DMA_FROM_DEVICE);
if (ret)
goto e_src;
}
while (src.sg_wa.bytes_left) {
ccp_prepare_data(&src, &dst, &op, unit_size, true);
if (!src.sg_wa.bytes_left)
op.eom = 1;
ret = cmd_q->ccp->vdata->perform->perform_xts_aes(&op);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_dst;
}
ccp_process_data(&src, &dst, &op);
}
ret = ccp_copy_from_ksb(cmd_q, &ctx, op.jobid, op.ksb_ctx,
CCP_PASSTHRU_BYTESWAP_256BIT);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_dst;
}
dm_offset = CCP_KSB_BYTES - AES_BLOCK_SIZE;
ccp_get_dm_area(&ctx, dm_offset, xts->iv, 0, xts->iv_len);
e_dst:
if (!in_place)
ccp_free_data(&dst, cmd_q);
e_src:
ccp_free_data(&src, cmd_q);
e_ctx:
ccp_dm_free(&ctx);
e_key:
ccp_dm_free(&key);
return ret;
}
static int ccp_run_sha_cmd(struct ccp_cmd_queue *cmd_q, struct ccp_cmd *cmd)
{
struct ccp_sha_engine *sha = &cmd->u.sha;
struct ccp_dm_workarea ctx;
struct ccp_data src;
struct ccp_op op;
int ret;
if (sha->ctx_len != CCP_SHA_CTXSIZE)
return -EINVAL;
if (!sha->ctx)
return -EINVAL;
if (!sha->final && (sha->src_len & (CCP_SHA_BLOCKSIZE - 1)))
return -EINVAL;
if (!sha->src_len) {
const u8 *sha_zero;
if (!sha->final)
return 0;
if (sha->msg_bits)
return -EINVAL;
switch (sha->type) {
case CCP_SHA_TYPE_1:
sha_zero = sha1_zero_message_hash;
break;
case CCP_SHA_TYPE_224:
sha_zero = sha224_zero_message_hash;
break;
case CCP_SHA_TYPE_256:
sha_zero = sha256_zero_message_hash;
break;
default:
return -EINVAL;
}
scatterwalk_map_and_copy((void *)sha_zero, sha->ctx, 0,
sha->ctx_len, 1);
return 0;
}
if (!sha->src)
return -EINVAL;
BUILD_BUG_ON(CCP_SHA_KSB_COUNT != 1);
memset(&op, 0, sizeof(op));
op.cmd_q = cmd_q;
op.jobid = ccp_gen_jobid(cmd_q->ccp);
op.ksb_ctx = cmd_q->ksb_ctx;
op.u.sha.type = sha->type;
op.u.sha.msg_bits = sha->msg_bits;
ret = ccp_init_dm_workarea(&ctx, cmd_q,
CCP_SHA_KSB_COUNT * CCP_KSB_BYTES,
DMA_BIDIRECTIONAL);
if (ret)
return ret;
if (sha->first) {
const __be32 *init;
switch (sha->type) {
case CCP_SHA_TYPE_1:
init = ccp_sha1_init;
break;
case CCP_SHA_TYPE_224:
init = ccp_sha224_init;
break;
case CCP_SHA_TYPE_256:
init = ccp_sha256_init;
break;
default:
ret = -EINVAL;
goto e_ctx;
}
memcpy(ctx.address, init, CCP_SHA_CTXSIZE);
} else {
ccp_set_dm_area(&ctx, 0, sha->ctx, 0, sha->ctx_len);
}
ret = ccp_copy_to_ksb(cmd_q, &ctx, op.jobid, op.ksb_ctx,
CCP_PASSTHRU_BYTESWAP_256BIT);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_ctx;
}
ret = ccp_init_data(&src, cmd_q, sha->src, sha->src_len,
CCP_SHA_BLOCKSIZE, DMA_TO_DEVICE);
if (ret)
goto e_ctx;
while (src.sg_wa.bytes_left) {
ccp_prepare_data(&src, NULL, &op, CCP_SHA_BLOCKSIZE, false);
if (sha->final && !src.sg_wa.bytes_left)
op.eom = 1;
ret = cmd_q->ccp->vdata->perform->perform_sha(&op);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_data;
}
ccp_process_data(&src, NULL, &op);
}
ret = ccp_copy_from_ksb(cmd_q, &ctx, op.jobid, op.ksb_ctx,
CCP_PASSTHRU_BYTESWAP_256BIT);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_data;
}
ccp_get_dm_area(&ctx, 0, sha->ctx, 0, sha->ctx_len);
if (sha->final && sha->opad) {
struct ccp_cmd hmac_cmd;
struct scatterlist sg;
u64 block_size, digest_size;
u8 *hmac_buf;
switch (sha->type) {
case CCP_SHA_TYPE_1:
block_size = SHA1_BLOCK_SIZE;
digest_size = SHA1_DIGEST_SIZE;
break;
case CCP_SHA_TYPE_224:
block_size = SHA224_BLOCK_SIZE;
digest_size = SHA224_DIGEST_SIZE;
break;
case CCP_SHA_TYPE_256:
block_size = SHA256_BLOCK_SIZE;
digest_size = SHA256_DIGEST_SIZE;
break;
default:
ret = -EINVAL;
goto e_data;
}
if (sha->opad_len != block_size) {
ret = -EINVAL;
goto e_data;
}
hmac_buf = kmalloc(block_size + digest_size, GFP_KERNEL);
if (!hmac_buf) {
ret = -ENOMEM;
goto e_data;
}
sg_init_one(&sg, hmac_buf, block_size + digest_size);
scatterwalk_map_and_copy(hmac_buf, sha->opad, 0, block_size, 0);
memcpy(hmac_buf + block_size, ctx.address, digest_size);
memset(&hmac_cmd, 0, sizeof(hmac_cmd));
hmac_cmd.engine = CCP_ENGINE_SHA;
hmac_cmd.u.sha.type = sha->type;
hmac_cmd.u.sha.ctx = sha->ctx;
hmac_cmd.u.sha.ctx_len = sha->ctx_len;
hmac_cmd.u.sha.src = &sg;
hmac_cmd.u.sha.src_len = block_size + digest_size;
hmac_cmd.u.sha.opad = NULL;
hmac_cmd.u.sha.opad_len = 0;
hmac_cmd.u.sha.first = 1;
hmac_cmd.u.sha.final = 1;
hmac_cmd.u.sha.msg_bits = (block_size + digest_size) << 3;
ret = ccp_run_sha_cmd(cmd_q, &hmac_cmd);
if (ret)
cmd->engine_error = hmac_cmd.engine_error;
kfree(hmac_buf);
}
e_data:
ccp_free_data(&src, cmd_q);
e_ctx:
ccp_dm_free(&ctx);
return ret;
}
static int ccp_run_rsa_cmd(struct ccp_cmd_queue *cmd_q, struct ccp_cmd *cmd)
{
struct ccp_rsa_engine *rsa = &cmd->u.rsa;
struct ccp_dm_workarea exp, src;
struct ccp_data dst;
struct ccp_op op;
unsigned int ksb_count, i_len, o_len;
int ret;
if (rsa->key_size > CCP_RSA_MAX_WIDTH)
return -EINVAL;
if (!rsa->exp || !rsa->mod || !rsa->src || !rsa->dst)
return -EINVAL;
o_len = ((rsa->key_size + 255) / 256) * 32;
i_len = o_len * 2;
ksb_count = o_len / CCP_KSB_BYTES;
memset(&op, 0, sizeof(op));
op.cmd_q = cmd_q;
op.jobid = ccp_gen_jobid(cmd_q->ccp);
op.ksb_key = ccp_alloc_ksb(cmd_q->ccp, ksb_count);
if (!op.ksb_key)
return -EIO;
ret = ccp_init_dm_workarea(&exp, cmd_q, o_len, DMA_TO_DEVICE);
if (ret)
goto e_ksb;
ret = ccp_reverse_set_dm_area(&exp, rsa->exp, rsa->exp_len,
CCP_KSB_BYTES, false);
if (ret)
goto e_exp;
ret = ccp_copy_to_ksb(cmd_q, &exp, op.jobid, op.ksb_key,
CCP_PASSTHRU_BYTESWAP_NOOP);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_exp;
}
ret = ccp_init_dm_workarea(&src, cmd_q, i_len, DMA_TO_DEVICE);
if (ret)
goto e_exp;
ret = ccp_reverse_set_dm_area(&src, rsa->mod, rsa->mod_len,
CCP_KSB_BYTES, false);
if (ret)
goto e_src;
src.address += o_len;
ret = ccp_reverse_set_dm_area(&src, rsa->src, rsa->src_len,
CCP_KSB_BYTES, false);
if (ret)
goto e_src;
src.address -= o_len;
ret = ccp_init_data(&dst, cmd_q, rsa->dst, rsa->mod_len,
o_len, DMA_FROM_DEVICE);
if (ret)
goto e_src;
op.soc = 1;
op.src.u.dma.address = src.dma.address;
op.src.u.dma.offset = 0;
op.src.u.dma.length = i_len;
op.dst.u.dma.address = dst.dm_wa.dma.address;
op.dst.u.dma.offset = 0;
op.dst.u.dma.length = o_len;
op.u.rsa.mod_size = rsa->key_size;
op.u.rsa.input_len = i_len;
ret = cmd_q->ccp->vdata->perform->perform_rsa(&op);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_dst;
}
ccp_reverse_get_dm_area(&dst.dm_wa, rsa->dst, rsa->mod_len);
e_dst:
ccp_free_data(&dst, cmd_q);
e_src:
ccp_dm_free(&src);
e_exp:
ccp_dm_free(&exp);
e_ksb:
ccp_free_ksb(cmd_q->ccp, op.ksb_key, ksb_count);
return ret;
}
static int ccp_run_passthru_cmd(struct ccp_cmd_queue *cmd_q,
struct ccp_cmd *cmd)
{
struct ccp_passthru_engine *pt = &cmd->u.passthru;
struct ccp_dm_workarea mask;
struct ccp_data src, dst;
struct ccp_op op;
bool in_place = false;
unsigned int i;
int ret;
if (!pt->final && (pt->src_len & (CCP_PASSTHRU_BLOCKSIZE - 1)))
return -EINVAL;
if (!pt->src || !pt->dst)
return -EINVAL;
if (pt->bit_mod != CCP_PASSTHRU_BITWISE_NOOP) {
if (pt->mask_len != CCP_PASSTHRU_MASKSIZE)
return -EINVAL;
if (!pt->mask)
return -EINVAL;
}
BUILD_BUG_ON(CCP_PASSTHRU_KSB_COUNT != 1);
memset(&op, 0, sizeof(op));
op.cmd_q = cmd_q;
op.jobid = ccp_gen_jobid(cmd_q->ccp);
if (pt->bit_mod != CCP_PASSTHRU_BITWISE_NOOP) {
op.ksb_key = cmd_q->ksb_key;
ret = ccp_init_dm_workarea(&mask, cmd_q,
CCP_PASSTHRU_KSB_COUNT *
CCP_KSB_BYTES,
DMA_TO_DEVICE);
if (ret)
return ret;
ccp_set_dm_area(&mask, 0, pt->mask, 0, pt->mask_len);
ret = ccp_copy_to_ksb(cmd_q, &mask, op.jobid, op.ksb_key,
CCP_PASSTHRU_BYTESWAP_NOOP);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_mask;
}
}
if (sg_virt(pt->src) == sg_virt(pt->dst))
in_place = true;
ret = ccp_init_data(&src, cmd_q, pt->src, pt->src_len,
CCP_PASSTHRU_MASKSIZE,
in_place ? DMA_BIDIRECTIONAL : DMA_TO_DEVICE);
if (ret)
goto e_mask;
if (in_place) {
dst = src;
} else {
ret = ccp_init_data(&dst, cmd_q, pt->dst, pt->src_len,
CCP_PASSTHRU_MASKSIZE, DMA_FROM_DEVICE);
if (ret)
goto e_src;
}
dst.sg_wa.sg_used = 0;
for (i = 1; i <= src.sg_wa.dma_count; i++) {
if (!dst.sg_wa.sg ||
(dst.sg_wa.sg->length < src.sg_wa.sg->length)) {
ret = -EINVAL;
goto e_dst;
}
if (i == src.sg_wa.dma_count) {
op.eom = 1;
op.soc = 1;
}
op.src.type = CCP_MEMTYPE_SYSTEM;
op.src.u.dma.address = sg_dma_address(src.sg_wa.sg);
op.src.u.dma.offset = 0;
op.src.u.dma.length = sg_dma_len(src.sg_wa.sg);
op.dst.type = CCP_MEMTYPE_SYSTEM;
op.dst.u.dma.address = sg_dma_address(dst.sg_wa.sg);
op.dst.u.dma.offset = dst.sg_wa.sg_used;
op.dst.u.dma.length = op.src.u.dma.length;
ret = cmd_q->ccp->vdata->perform->perform_passthru(&op);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_dst;
}
dst.sg_wa.sg_used += src.sg_wa.sg->length;
if (dst.sg_wa.sg_used == dst.sg_wa.sg->length) {
dst.sg_wa.sg = sg_next(dst.sg_wa.sg);
dst.sg_wa.sg_used = 0;
}
src.sg_wa.sg = sg_next(src.sg_wa.sg);
}
e_dst:
if (!in_place)
ccp_free_data(&dst, cmd_q);
e_src:
ccp_free_data(&src, cmd_q);
e_mask:
if (pt->bit_mod != CCP_PASSTHRU_BITWISE_NOOP)
ccp_dm_free(&mask);
return ret;
}
static int ccp_run_passthru_nomap_cmd(struct ccp_cmd_queue *cmd_q,
struct ccp_cmd *cmd)
{
struct ccp_passthru_nomap_engine *pt = &cmd->u.passthru_nomap;
struct ccp_dm_workarea mask;
struct ccp_op op;
int ret;
if (!pt->final && (pt->src_len & (CCP_PASSTHRU_BLOCKSIZE - 1)))
return -EINVAL;
if (!pt->src_dma || !pt->dst_dma)
return -EINVAL;
if (pt->bit_mod != CCP_PASSTHRU_BITWISE_NOOP) {
if (pt->mask_len != CCP_PASSTHRU_MASKSIZE)
return -EINVAL;
if (!pt->mask)
return -EINVAL;
}
BUILD_BUG_ON(CCP_PASSTHRU_KSB_COUNT != 1);
memset(&op, 0, sizeof(op));
op.cmd_q = cmd_q;
op.jobid = ccp_gen_jobid(cmd_q->ccp);
if (pt->bit_mod != CCP_PASSTHRU_BITWISE_NOOP) {
op.ksb_key = cmd_q->ksb_key;
mask.length = pt->mask_len;
mask.dma.address = pt->mask;
mask.dma.length = pt->mask_len;
ret = ccp_copy_to_ksb(cmd_q, &mask, op.jobid, op.ksb_key,
CCP_PASSTHRU_BYTESWAP_NOOP);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
return ret;
}
}
op.eom = 1;
op.soc = 1;
op.src.type = CCP_MEMTYPE_SYSTEM;
op.src.u.dma.address = pt->src_dma;
op.src.u.dma.offset = 0;
op.src.u.dma.length = pt->src_len;
op.dst.type = CCP_MEMTYPE_SYSTEM;
op.dst.u.dma.address = pt->dst_dma;
op.dst.u.dma.offset = 0;
op.dst.u.dma.length = pt->src_len;
ret = cmd_q->ccp->vdata->perform->perform_passthru(&op);
if (ret)
cmd->engine_error = cmd_q->cmd_error;
return ret;
}
static int ccp_run_ecc_mm_cmd(struct ccp_cmd_queue *cmd_q, struct ccp_cmd *cmd)
{
struct ccp_ecc_engine *ecc = &cmd->u.ecc;
struct ccp_dm_workarea src, dst;
struct ccp_op op;
int ret;
u8 *save;
if (!ecc->u.mm.operand_1 ||
(ecc->u.mm.operand_1_len > CCP_ECC_MODULUS_BYTES))
return -EINVAL;
if (ecc->function != CCP_ECC_FUNCTION_MINV_384BIT)
if (!ecc->u.mm.operand_2 ||
(ecc->u.mm.operand_2_len > CCP_ECC_MODULUS_BYTES))
return -EINVAL;
if (!ecc->u.mm.result ||
(ecc->u.mm.result_len < CCP_ECC_MODULUS_BYTES))
return -EINVAL;
memset(&op, 0, sizeof(op));
op.cmd_q = cmd_q;
op.jobid = ccp_gen_jobid(cmd_q->ccp);
ret = ccp_init_dm_workarea(&src, cmd_q, CCP_ECC_SRC_BUF_SIZE,
DMA_TO_DEVICE);
if (ret)
return ret;
save = src.address;
ret = ccp_reverse_set_dm_area(&src, ecc->mod, ecc->mod_len,
CCP_ECC_OPERAND_SIZE, false);
if (ret)
goto e_src;
src.address += CCP_ECC_OPERAND_SIZE;
ret = ccp_reverse_set_dm_area(&src, ecc->u.mm.operand_1,
ecc->u.mm.operand_1_len,
CCP_ECC_OPERAND_SIZE, false);
if (ret)
goto e_src;
src.address += CCP_ECC_OPERAND_SIZE;
if (ecc->function != CCP_ECC_FUNCTION_MINV_384BIT) {
ret = ccp_reverse_set_dm_area(&src, ecc->u.mm.operand_2,
ecc->u.mm.operand_2_len,
CCP_ECC_OPERAND_SIZE, false);
if (ret)
goto e_src;
src.address += CCP_ECC_OPERAND_SIZE;
}
src.address = save;
ret = ccp_init_dm_workarea(&dst, cmd_q, CCP_ECC_DST_BUF_SIZE,
DMA_FROM_DEVICE);
if (ret)
goto e_src;
op.soc = 1;
op.src.u.dma.address = src.dma.address;
op.src.u.dma.offset = 0;
op.src.u.dma.length = src.length;
op.dst.u.dma.address = dst.dma.address;
op.dst.u.dma.offset = 0;
op.dst.u.dma.length = dst.length;
op.u.ecc.function = cmd->u.ecc.function;
ret = cmd_q->ccp->vdata->perform->perform_ecc(&op);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_dst;
}
ecc->ecc_result = le16_to_cpup(
(const __le16 *)(dst.address + CCP_ECC_RESULT_OFFSET));
if (!(ecc->ecc_result & CCP_ECC_RESULT_SUCCESS)) {
ret = -EIO;
goto e_dst;
}
ccp_reverse_get_dm_area(&dst, ecc->u.mm.result, CCP_ECC_MODULUS_BYTES);
e_dst:
ccp_dm_free(&dst);
e_src:
ccp_dm_free(&src);
return ret;
}
static int ccp_run_ecc_pm_cmd(struct ccp_cmd_queue *cmd_q, struct ccp_cmd *cmd)
{
struct ccp_ecc_engine *ecc = &cmd->u.ecc;
struct ccp_dm_workarea src, dst;
struct ccp_op op;
int ret;
u8 *save;
if (!ecc->u.pm.point_1.x ||
(ecc->u.pm.point_1.x_len > CCP_ECC_MODULUS_BYTES) ||
!ecc->u.pm.point_1.y ||
(ecc->u.pm.point_1.y_len > CCP_ECC_MODULUS_BYTES))
return -EINVAL;
if (ecc->function == CCP_ECC_FUNCTION_PADD_384BIT) {
if (!ecc->u.pm.point_2.x ||
(ecc->u.pm.point_2.x_len > CCP_ECC_MODULUS_BYTES) ||
!ecc->u.pm.point_2.y ||
(ecc->u.pm.point_2.y_len > CCP_ECC_MODULUS_BYTES))
return -EINVAL;
} else {
if (!ecc->u.pm.domain_a ||
(ecc->u.pm.domain_a_len > CCP_ECC_MODULUS_BYTES))
return -EINVAL;
if (ecc->function == CCP_ECC_FUNCTION_PMUL_384BIT)
if (!ecc->u.pm.scalar ||
(ecc->u.pm.scalar_len > CCP_ECC_MODULUS_BYTES))
return -EINVAL;
}
if (!ecc->u.pm.result.x ||
(ecc->u.pm.result.x_len < CCP_ECC_MODULUS_BYTES) ||
!ecc->u.pm.result.y ||
(ecc->u.pm.result.y_len < CCP_ECC_MODULUS_BYTES))
return -EINVAL;
memset(&op, 0, sizeof(op));
op.cmd_q = cmd_q;
op.jobid = ccp_gen_jobid(cmd_q->ccp);
ret = ccp_init_dm_workarea(&src, cmd_q, CCP_ECC_SRC_BUF_SIZE,
DMA_TO_DEVICE);
if (ret)
return ret;
save = src.address;
ret = ccp_reverse_set_dm_area(&src, ecc->mod, ecc->mod_len,
CCP_ECC_OPERAND_SIZE, false);
if (ret)
goto e_src;
src.address += CCP_ECC_OPERAND_SIZE;
ret = ccp_reverse_set_dm_area(&src, ecc->u.pm.point_1.x,
ecc->u.pm.point_1.x_len,
CCP_ECC_OPERAND_SIZE, false);
if (ret)
goto e_src;
src.address += CCP_ECC_OPERAND_SIZE;
ret = ccp_reverse_set_dm_area(&src, ecc->u.pm.point_1.y,
ecc->u.pm.point_1.y_len,
CCP_ECC_OPERAND_SIZE, false);
if (ret)
goto e_src;
src.address += CCP_ECC_OPERAND_SIZE;
*src.address = 0x01;
src.address += CCP_ECC_OPERAND_SIZE;
if (ecc->function == CCP_ECC_FUNCTION_PADD_384BIT) {
ret = ccp_reverse_set_dm_area(&src, ecc->u.pm.point_2.x,
ecc->u.pm.point_2.x_len,
CCP_ECC_OPERAND_SIZE, false);
if (ret)
goto e_src;
src.address += CCP_ECC_OPERAND_SIZE;
ret = ccp_reverse_set_dm_area(&src, ecc->u.pm.point_2.y,
ecc->u.pm.point_2.y_len,
CCP_ECC_OPERAND_SIZE, false);
if (ret)
goto e_src;
src.address += CCP_ECC_OPERAND_SIZE;
*src.address = 0x01;
src.address += CCP_ECC_OPERAND_SIZE;
} else {
ret = ccp_reverse_set_dm_area(&src, ecc->u.pm.domain_a,
ecc->u.pm.domain_a_len,
CCP_ECC_OPERAND_SIZE, false);
if (ret)
goto e_src;
src.address += CCP_ECC_OPERAND_SIZE;
if (ecc->function == CCP_ECC_FUNCTION_PMUL_384BIT) {
ret = ccp_reverse_set_dm_area(&src, ecc->u.pm.scalar,
ecc->u.pm.scalar_len,
CCP_ECC_OPERAND_SIZE,
false);
if (ret)
goto e_src;
src.address += CCP_ECC_OPERAND_SIZE;
}
}
src.address = save;
ret = ccp_init_dm_workarea(&dst, cmd_q, CCP_ECC_DST_BUF_SIZE,
DMA_FROM_DEVICE);
if (ret)
goto e_src;
op.soc = 1;
op.src.u.dma.address = src.dma.address;
op.src.u.dma.offset = 0;
op.src.u.dma.length = src.length;
op.dst.u.dma.address = dst.dma.address;
op.dst.u.dma.offset = 0;
op.dst.u.dma.length = dst.length;
op.u.ecc.function = cmd->u.ecc.function;
ret = cmd_q->ccp->vdata->perform->perform_ecc(&op);
if (ret) {
cmd->engine_error = cmd_q->cmd_error;
goto e_dst;
}
ecc->ecc_result = le16_to_cpup(
(const __le16 *)(dst.address + CCP_ECC_RESULT_OFFSET));
if (!(ecc->ecc_result & CCP_ECC_RESULT_SUCCESS)) {
ret = -EIO;
goto e_dst;
}
save = dst.address;
ccp_reverse_get_dm_area(&dst, ecc->u.pm.result.x,
CCP_ECC_MODULUS_BYTES);
dst.address += CCP_ECC_OUTPUT_SIZE;
ccp_reverse_get_dm_area(&dst, ecc->u.pm.result.y,
CCP_ECC_MODULUS_BYTES);
dst.address += CCP_ECC_OUTPUT_SIZE;
dst.address = save;
e_dst:
ccp_dm_free(&dst);
e_src:
ccp_dm_free(&src);
return ret;
}
static int ccp_run_ecc_cmd(struct ccp_cmd_queue *cmd_q, struct ccp_cmd *cmd)
{
struct ccp_ecc_engine *ecc = &cmd->u.ecc;
ecc->ecc_result = 0;
if (!ecc->mod ||
(ecc->mod_len > CCP_ECC_MODULUS_BYTES))
return -EINVAL;
switch (ecc->function) {
case CCP_ECC_FUNCTION_MMUL_384BIT:
case CCP_ECC_FUNCTION_MADD_384BIT:
case CCP_ECC_FUNCTION_MINV_384BIT:
return ccp_run_ecc_mm_cmd(cmd_q, cmd);
case CCP_ECC_FUNCTION_PADD_384BIT:
case CCP_ECC_FUNCTION_PMUL_384BIT:
case CCP_ECC_FUNCTION_PDBL_384BIT:
return ccp_run_ecc_pm_cmd(cmd_q, cmd);
default:
return -EINVAL;
}
}
int ccp_run_cmd(struct ccp_cmd_queue *cmd_q, struct ccp_cmd *cmd)
{
int ret;
cmd->engine_error = 0;
cmd_q->cmd_error = 0;
cmd_q->int_rcvd = 0;
cmd_q->free_slots = CMD_Q_DEPTH(ioread32(cmd_q->reg_status));
switch (cmd->engine) {
case CCP_ENGINE_AES:
ret = ccp_run_aes_cmd(cmd_q, cmd);
break;
case CCP_ENGINE_XTS_AES_128:
ret = ccp_run_xts_aes_cmd(cmd_q, cmd);
break;
case CCP_ENGINE_SHA:
ret = ccp_run_sha_cmd(cmd_q, cmd);
break;
case CCP_ENGINE_RSA:
ret = ccp_run_rsa_cmd(cmd_q, cmd);
break;
case CCP_ENGINE_PASSTHRU:
if (cmd->flags & CCP_CMD_PASSTHRU_NO_DMA_MAP)
ret = ccp_run_passthru_nomap_cmd(cmd_q, cmd);
else
ret = ccp_run_passthru_cmd(cmd_q, cmd);
break;
case CCP_ENGINE_ECC:
ret = ccp_run_ecc_cmd(cmd_q, cmd);
break;
default:
ret = -EINVAL;
}
return ret;
}
