static void skl_cldma_int_enable(struct sst_dsp *ctx)
{
sst_dsp_shim_update_bits_unlocked(ctx, SKL_ADSP_REG_ADSPIC,
SKL_ADSPIC_CL_DMA, SKL_ADSPIC_CL_DMA);
}
void skl_cldma_int_disable(struct sst_dsp *ctx)
{
sst_dsp_shim_update_bits_unlocked(ctx,
SKL_ADSP_REG_ADSPIC, SKL_ADSPIC_CL_DMA, 0);
}
static void skl_cldma_setup_bdle(struct sst_dsp *ctx,
struct snd_dma_buffer *dmab_data,
u32 **bdlp, int size, int with_ioc)
{
u32 *bdl = *bdlp;
ctx->cl_dev.frags = 0;
while (size > 0) {
phys_addr_t addr = virt_to_phys(dmab_data->area +
(ctx->cl_dev.frags * ctx->cl_dev.bufsize));
bdl[0] = cpu_to_le32(lower_32_bits(addr));
bdl[1] = cpu_to_le32(upper_32_bits(addr));
bdl[2] = cpu_to_le32(ctx->cl_dev.bufsize);
size -= ctx->cl_dev.bufsize;
bdl[3] = (size || !with_ioc) ? 0 : cpu_to_le32(0x01);
bdl += 4;
ctx->cl_dev.frags++;
}
}
static void skl_cldma_setup_controller(struct sst_dsp *ctx,
struct snd_dma_buffer *dmab_bdl, unsigned int max_size,
u32 count)
{
sst_dsp_shim_write(ctx, SKL_ADSP_REG_CL_SD_BDLPL,
CL_SD_BDLPLBA(dmab_bdl->addr));
sst_dsp_shim_write(ctx, SKL_ADSP_REG_CL_SD_BDLPU,
CL_SD_BDLPUBA(dmab_bdl->addr));
sst_dsp_shim_write(ctx, SKL_ADSP_REG_CL_SD_CBL, max_size);
sst_dsp_shim_write(ctx, SKL_ADSP_REG_CL_SD_LVI, count - 1);
sst_dsp_shim_update_bits(ctx, SKL_ADSP_REG_CL_SD_CTL,
CL_SD_CTL_IOCE_MASK, CL_SD_CTL_IOCE(1));
sst_dsp_shim_update_bits(ctx, SKL_ADSP_REG_CL_SD_CTL,
CL_SD_CTL_FEIE_MASK, CL_SD_CTL_FEIE(1));
sst_dsp_shim_update_bits(ctx, SKL_ADSP_REG_CL_SD_CTL,
CL_SD_CTL_DEIE_MASK, CL_SD_CTL_DEIE(1));
sst_dsp_shim_update_bits(ctx, SKL_ADSP_REG_CL_SD_CTL,
CL_SD_CTL_STRM_MASK, CL_SD_CTL_STRM(FW_CL_STREAM_NUMBER));
}
static void skl_cldma_setup_spb(struct sst_dsp *ctx,
unsigned int size, bool enable)
{
if (enable)
sst_dsp_shim_update_bits_unlocked(ctx,
SKL_ADSP_REG_CL_SPBFIFO_SPBFCCTL,
CL_SPBFIFO_SPBFCCTL_SPIBE_MASK,
CL_SPBFIFO_SPBFCCTL_SPIBE(1));
sst_dsp_shim_write_unlocked(ctx, SKL_ADSP_REG_CL_SPBFIFO_SPIB, size);
}
static void skl_cldma_cleanup_spb(struct sst_dsp *ctx)
{
sst_dsp_shim_update_bits_unlocked(ctx,
SKL_ADSP_REG_CL_SPBFIFO_SPBFCCTL,
CL_SPBFIFO_SPBFCCTL_SPIBE_MASK,
CL_SPBFIFO_SPBFCCTL_SPIBE(0));
sst_dsp_shim_write_unlocked(ctx, SKL_ADSP_REG_CL_SPBFIFO_SPIB, 0);
}
static void skl_cldma_trigger(struct sst_dsp *ctx, bool enable)
{
if (enable)
sst_dsp_shim_update_bits_unlocked(ctx,
SKL_ADSP_REG_CL_SD_CTL,
CL_SD_CTL_RUN_MASK, CL_SD_CTL_RUN(1));
else
sst_dsp_shim_update_bits_unlocked(ctx,
SKL_ADSP_REG_CL_SD_CTL,
CL_SD_CTL_RUN_MASK, CL_SD_CTL_RUN(0));
}
static void skl_cldma_cleanup(struct sst_dsp *ctx)
{
skl_cldma_cleanup_spb(ctx);
sst_dsp_shim_update_bits(ctx, SKL_ADSP_REG_CL_SD_CTL,
CL_SD_CTL_IOCE_MASK, CL_SD_CTL_IOCE(0));
sst_dsp_shim_update_bits(ctx, SKL_ADSP_REG_CL_SD_CTL,
CL_SD_CTL_FEIE_MASK, CL_SD_CTL_FEIE(0));
sst_dsp_shim_update_bits(ctx, SKL_ADSP_REG_CL_SD_CTL,
CL_SD_CTL_DEIE_MASK, CL_SD_CTL_DEIE(0));
sst_dsp_shim_update_bits(ctx, SKL_ADSP_REG_CL_SD_CTL,
CL_SD_CTL_STRM_MASK, CL_SD_CTL_STRM(0));
sst_dsp_shim_write(ctx, SKL_ADSP_REG_CL_SD_BDLPL, CL_SD_BDLPLBA(0));
sst_dsp_shim_write(ctx, SKL_ADSP_REG_CL_SD_BDLPU, 0);
sst_dsp_shim_write(ctx, SKL_ADSP_REG_CL_SD_CBL, 0);
sst_dsp_shim_write(ctx, SKL_ADSP_REG_CL_SD_LVI, 0);
}
static int skl_cldma_wait_interruptible(struct sst_dsp *ctx)
{
int ret = 0;
if (!wait_event_timeout(ctx->cl_dev.wait_queue,
ctx->cl_dev.wait_condition,
msecs_to_jiffies(SKL_WAIT_TIMEOUT))) {
dev_err(ctx->dev, "%s: Wait timeout\n", __func__);
ret = -EIO;
goto cleanup;
}
dev_dbg(ctx->dev, "%s: Event wake\n", __func__);
if (ctx->cl_dev.wake_status != SKL_CL_DMA_BUF_COMPLETE) {
dev_err(ctx->dev, "%s: DMA Error\n", __func__);
ret = -EIO;
}
cleanup:
ctx->cl_dev.wake_status = SKL_CL_DMA_STATUS_NONE;
return ret;
}
static void skl_cldma_stop(struct sst_dsp *ctx)
{
ctx->cl_dev.ops.cl_trigger(ctx, false);
}
static void skl_cldma_fill_buffer(struct sst_dsp *ctx, unsigned int size,
const void *curr_pos, bool intr_enable, bool trigger)
{
dev_dbg(ctx->dev, "Size: %x, intr_enable: %d\n", size, intr_enable);
dev_dbg(ctx->dev, "buf_pos_index:%d, trigger:%d\n",
ctx->cl_dev.dma_buffer_offset, trigger);
dev_dbg(ctx->dev, "spib position: %d\n", ctx->cl_dev.curr_spib_pos);
memcpy(ctx->cl_dev.dmab_data.area + ctx->cl_dev.dma_buffer_offset,
curr_pos, size);
if (ctx->cl_dev.curr_spib_pos == ctx->cl_dev.bufsize)
ctx->cl_dev.dma_buffer_offset = 0;
else
ctx->cl_dev.dma_buffer_offset = ctx->cl_dev.curr_spib_pos;
ctx->cl_dev.wait_condition = false;
if (intr_enable)
skl_cldma_int_enable(ctx);
ctx->cl_dev.ops.cl_setup_spb(ctx, ctx->cl_dev.curr_spib_pos, trigger);
if (trigger)
ctx->cl_dev.ops.cl_trigger(ctx, true);
}
static int
skl_cldma_copy_to_buf(struct sst_dsp *ctx, const void *bin, u32 total_size)
{
int ret = 0;
bool start = true;
unsigned int excess_bytes;
u32 size;
unsigned int bytes_left = total_size;
const void *curr_pos = bin;
if (total_size <= 0)
return -EINVAL;
dev_dbg(ctx->dev, "%s: Total binary size: %u\n", __func__, bytes_left);
while (bytes_left) {
if (bytes_left > ctx->cl_dev.bufsize) {
if (ctx->cl_dev.curr_spib_pos == 0)
ctx->cl_dev.curr_spib_pos = ctx->cl_dev.bufsize;
size = ctx->cl_dev.bufsize;
skl_cldma_fill_buffer(ctx, size, curr_pos, true, start);
start = false;
ret = skl_cldma_wait_interruptible(ctx);
if (ret < 0) {
skl_cldma_stop(ctx);
return ret;
}
} else {
skl_cldma_int_disable(ctx);
if ((ctx->cl_dev.curr_spib_pos + bytes_left)
<= ctx->cl_dev.bufsize) {
ctx->cl_dev.curr_spib_pos += bytes_left;
} else {
excess_bytes = bytes_left -
(ctx->cl_dev.bufsize -
ctx->cl_dev.curr_spib_pos);
ctx->cl_dev.curr_spib_pos = excess_bytes;
}
size = bytes_left;
skl_cldma_fill_buffer(ctx, size,
curr_pos, false, start);
}
bytes_left -= size;
curr_pos = curr_pos + size;
}
return ret;
}
void skl_cldma_process_intr(struct sst_dsp *ctx)
{
u8 cl_dma_intr_status;
cl_dma_intr_status =
sst_dsp_shim_read_unlocked(ctx, SKL_ADSP_REG_CL_SD_STS);
if (!(cl_dma_intr_status & SKL_CL_DMA_SD_INT_COMPLETE))
ctx->cl_dev.wake_status = SKL_CL_DMA_ERR;
else
ctx->cl_dev.wake_status = SKL_CL_DMA_BUF_COMPLETE;
ctx->cl_dev.wait_condition = true;
wake_up(&ctx->cl_dev.wait_queue);
}
int skl_cldma_prepare(struct sst_dsp *ctx)
{
int ret;
u32 *bdl;
ctx->cl_dev.bufsize = SKL_MAX_BUFFER_SIZE;
ctx->cl_dev.ops.cl_setup_bdle = skl_cldma_setup_bdle;
ctx->cl_dev.ops.cl_setup_controller = skl_cldma_setup_controller;
ctx->cl_dev.ops.cl_setup_spb = skl_cldma_setup_spb;
ctx->cl_dev.ops.cl_cleanup_spb = skl_cldma_cleanup_spb;
ctx->cl_dev.ops.cl_trigger = skl_cldma_trigger;
ctx->cl_dev.ops.cl_cleanup_controller = skl_cldma_cleanup;
ctx->cl_dev.ops.cl_copy_to_dmabuf = skl_cldma_copy_to_buf;
ctx->cl_dev.ops.cl_stop_dma = skl_cldma_stop;
ret = ctx->dsp_ops.alloc_dma_buf(ctx->dev,
&ctx->cl_dev.dmab_data, ctx->cl_dev.bufsize);
if (ret < 0) {
dev_err(ctx->dev, "Alloc buffer for base fw failed: %x", ret);
return ret;
}
ret = ctx->dsp_ops.alloc_dma_buf(ctx->dev,
&ctx->cl_dev.dmab_bdl, PAGE_SIZE);
if (ret < 0) {
dev_err(ctx->dev, "Alloc buffer for blde failed: %x", ret);
ctx->dsp_ops.free_dma_buf(ctx->dev, &ctx->cl_dev.dmab_data);
return ret;
}
bdl = (u32 *)ctx->cl_dev.dmab_bdl.area;
ctx->cl_dev.ops.cl_setup_bdle(ctx, &ctx->cl_dev.dmab_data,
&bdl, ctx->cl_dev.bufsize, 1);
ctx->cl_dev.ops.cl_setup_controller(ctx, &ctx->cl_dev.dmab_bdl,
ctx->cl_dev.bufsize, ctx->cl_dev.frags);
ctx->cl_dev.curr_spib_pos = 0;
ctx->cl_dev.dma_buffer_offset = 0;
init_waitqueue_head(&ctx->cl_dev.wait_queue);
return ret;
}
