static inline u32 h264_read_reg(struct venc_h264_inst *inst, u32 addr)
{
return readl(inst->hw_base + addr);
}
static unsigned int h264_get_profile(struct venc_h264_inst *inst,
unsigned int profile)
{
switch (profile) {
case V4L2_MPEG_VIDEO_H264_PROFILE_BASELINE:
return 66;
case V4L2_MPEG_VIDEO_H264_PROFILE_MAIN:
return 77;
case V4L2_MPEG_VIDEO_H264_PROFILE_HIGH:
return 100;
case V4L2_MPEG_VIDEO_H264_PROFILE_CONSTRAINED_BASELINE:
mtk_vcodec_err(inst, "unsupported CONSTRAINED_BASELINE");
return 0;
case V4L2_MPEG_VIDEO_H264_PROFILE_EXTENDED:
mtk_vcodec_err(inst, "unsupported EXTENDED");
return 0;
default:
mtk_vcodec_debug(inst, "unsupported profile %d", profile);
return 100;
}
}
static unsigned int h264_get_level(struct venc_h264_inst *inst,
unsigned int level)
{
switch (level) {
case V4L2_MPEG_VIDEO_H264_LEVEL_1B:
mtk_vcodec_err(inst, "unsupported 1B");
return 0;
case V4L2_MPEG_VIDEO_H264_LEVEL_1_0:
return 10;
case V4L2_MPEG_VIDEO_H264_LEVEL_1_1:
return 11;
case V4L2_MPEG_VIDEO_H264_LEVEL_1_2:
return 12;
case V4L2_MPEG_VIDEO_H264_LEVEL_1_3:
return 13;
case V4L2_MPEG_VIDEO_H264_LEVEL_2_0:
return 20;
case V4L2_MPEG_VIDEO_H264_LEVEL_2_1:
return 21;
case V4L2_MPEG_VIDEO_H264_LEVEL_2_2:
return 22;
case V4L2_MPEG_VIDEO_H264_LEVEL_3_0:
return 30;
case V4L2_MPEG_VIDEO_H264_LEVEL_3_1:
return 31;
case V4L2_MPEG_VIDEO_H264_LEVEL_3_2:
return 32;
case V4L2_MPEG_VIDEO_H264_LEVEL_4_0:
return 40;
case V4L2_MPEG_VIDEO_H264_LEVEL_4_1:
return 41;
case V4L2_MPEG_VIDEO_H264_LEVEL_4_2:
return 42;
default:
mtk_vcodec_debug(inst, "unsupported level %d", level);
return 31;
}
}
static void h264_enc_free_work_buf(struct venc_h264_inst *inst)
{
int i;
mtk_vcodec_debug_enter(inst);
for (i = 0; i < VENC_H264_VPU_WORK_BUF_MAX; i++) {
if (i != VENC_H264_VPU_WORK_BUF_SKIP_FRAME)
mtk_vcodec_mem_free(inst->ctx, &inst->work_bufs[i]);
}
mtk_vcodec_mem_free(inst->ctx, &inst->pps_buf);
mtk_vcodec_debug_leave(inst);
}
static int h264_enc_alloc_work_buf(struct venc_h264_inst *inst)
{
int i;
int ret = 0;
struct venc_h264_vpu_buf *wb = inst->vsi->work_bufs;
mtk_vcodec_debug_enter(inst);
for (i = 0; i < VENC_H264_VPU_WORK_BUF_MAX; i++) {
inst->work_bufs[i].size = wb[i].size;
if (i == VENC_H264_VPU_WORK_BUF_SKIP_FRAME) {
inst->work_bufs[i].va = vpu_mapping_dm_addr(
inst->vpu_inst.dev, wb[i].vpua);
inst->work_bufs[i].dma_addr = 0;
} else {
ret = mtk_vcodec_mem_alloc(inst->ctx,
&inst->work_bufs[i]);
if (ret) {
mtk_vcodec_err(inst,
"cannot allocate buf %d", i);
goto err_alloc;
}
if (i == VENC_H264_VPU_WORK_BUF_RC_CODE) {
void *tmp_va;
tmp_va = vpu_mapping_dm_addr(inst->vpu_inst.dev,
wb[i].vpua);
memcpy(inst->work_bufs[i].va, tmp_va,
wb[i].size);
}
}
wb[i].iova = inst->work_bufs[i].dma_addr;
mtk_vcodec_debug(inst,
"work_buf[%d] va=0x%p iova=%pad size=%zu",
i, inst->work_bufs[i].va,
&inst->work_bufs[i].dma_addr,
inst->work_bufs[i].size);
}
inst->pps_buf.size = 128;
ret = mtk_vcodec_mem_alloc(inst->ctx, &inst->pps_buf);
if (ret) {
mtk_vcodec_err(inst, "cannot allocate pps_buf");
goto err_alloc;
}
mtk_vcodec_debug_leave(inst);
return ret;
err_alloc:
h264_enc_free_work_buf(inst);
return ret;
}
static unsigned int h264_enc_wait_venc_done(struct venc_h264_inst *inst)
{
unsigned int irq_status = 0;
struct mtk_vcodec_ctx *ctx = (struct mtk_vcodec_ctx *)inst->ctx;
if (!mtk_vcodec_wait_for_done_ctx(ctx, MTK_INST_IRQ_RECEIVED,
WAIT_INTR_TIMEOUT_MS)) {
irq_status = ctx->irq_status;
mtk_vcodec_debug(inst, "irq_status %x <-", irq_status);
}
return irq_status;
}
static int h264_encode_sps(struct venc_h264_inst *inst,
struct mtk_vcodec_mem *bs_buf,
unsigned int *bs_size)
{
int ret = 0;
unsigned int irq_status;
mtk_vcodec_debug_enter(inst);
ret = vpu_enc_encode(&inst->vpu_inst, H264_BS_MODE_SPS, NULL,
bs_buf, bs_size);
if (ret)
return ret;
irq_status = h264_enc_wait_venc_done(inst);
if (irq_status != MTK_VENC_IRQ_STATUS_SPS) {
mtk_vcodec_err(inst, "expect irq status %d",
MTK_VENC_IRQ_STATUS_SPS);
return -EINVAL;
}
*bs_size = h264_read_reg(inst, VENC_PIC_BITSTREAM_BYTE_CNT);
mtk_vcodec_debug(inst, "bs size %d <-", *bs_size);
return ret;
}
static int h264_encode_pps(struct venc_h264_inst *inst,
struct mtk_vcodec_mem *bs_buf,
unsigned int *bs_size)
{
int ret = 0;
unsigned int irq_status;
mtk_vcodec_debug_enter(inst);
ret = vpu_enc_encode(&inst->vpu_inst, H264_BS_MODE_PPS, NULL,
bs_buf, bs_size);
if (ret)
return ret;
irq_status = h264_enc_wait_venc_done(inst);
if (irq_status != MTK_VENC_IRQ_STATUS_PPS) {
mtk_vcodec_err(inst, "expect irq status %d",
MTK_VENC_IRQ_STATUS_PPS);
return -EINVAL;
}
*bs_size = h264_read_reg(inst, VENC_PIC_BITSTREAM_BYTE_CNT);
mtk_vcodec_debug(inst, "bs size %d <-", *bs_size);
return ret;
}
static int h264_encode_header(struct venc_h264_inst *inst,
struct mtk_vcodec_mem *bs_buf,
unsigned int *bs_size)
{
int ret = 0;
unsigned int bs_size_sps;
unsigned int bs_size_pps;
ret = h264_encode_sps(inst, bs_buf, &bs_size_sps);
if (ret)
return ret;
ret = h264_encode_pps(inst, &inst->pps_buf, &bs_size_pps);
if (ret)
return ret;
memcpy(bs_buf->va + bs_size_sps, inst->pps_buf.va, bs_size_pps);
*bs_size = bs_size_sps + bs_size_pps;
return ret;
}
static int h264_encode_frame(struct venc_h264_inst *inst,
struct venc_frm_buf *frm_buf,
struct mtk_vcodec_mem *bs_buf,
unsigned int *bs_size)
{
int ret = 0;
unsigned int irq_status;
mtk_vcodec_debug_enter(inst);
ret = vpu_enc_encode(&inst->vpu_inst, H264_BS_MODE_FRAME, frm_buf,
bs_buf, bs_size);
if (ret)
return ret;
if (inst->vpu_inst.state == VEN_IPI_MSG_ENC_STATE_SKIP) {
*bs_size = inst->vpu_inst.bs_size;
memcpy(bs_buf->va,
inst->work_bufs[VENC_H264_VPU_WORK_BUF_SKIP_FRAME].va,
*bs_size);
++inst->frm_cnt;
return ret;
}
irq_status = h264_enc_wait_venc_done(inst);
if (irq_status != MTK_VENC_IRQ_STATUS_FRM) {
mtk_vcodec_err(inst, "irq_status=%d failed", irq_status);
return -EIO;
}
*bs_size = h264_read_reg(inst, VENC_PIC_BITSTREAM_BYTE_CNT);
++inst->frm_cnt;
mtk_vcodec_debug(inst, "frm %d bs_size %d key_frm %d <-",
inst->frm_cnt, *bs_size, inst->vpu_inst.is_key_frm);
return ret;
}
static void h264_encode_filler(struct venc_h264_inst *inst, void *buf,
int size)
{
unsigned char *p = buf;
if (size < H264_FILLER_MARKER_SIZE) {
mtk_vcodec_err(inst, "filler size too small %d", size);
return;
}
memcpy(p, h264_filler_marker, ARRAY_SIZE(h264_filler_marker));
size -= H264_FILLER_MARKER_SIZE;
p += H264_FILLER_MARKER_SIZE;
memset(p, 0xff, size);
}
static int h264_enc_init(struct mtk_vcodec_ctx *ctx, unsigned long *handle)
{
int ret = 0;
struct venc_h264_inst *inst;
inst = kzalloc(sizeof(*inst), GFP_KERNEL);
if (!inst)
return -ENOMEM;
inst->ctx = ctx;
inst->vpu_inst.ctx = ctx;
inst->vpu_inst.dev = ctx->dev->vpu_plat_dev;
inst->vpu_inst.id = IPI_VENC_H264;
inst->hw_base = mtk_vcodec_get_reg_addr(inst->ctx, VENC_SYS);
mtk_vcodec_debug_enter(inst);
ret = vpu_enc_init(&inst->vpu_inst);
inst->vsi = (struct venc_h264_vsi *)inst->vpu_inst.vsi;
mtk_vcodec_debug_leave(inst);
if (ret)
kfree(inst);
else
(*handle) = (unsigned long)inst;
return ret;
}
static int h264_enc_encode(unsigned long handle,
enum venc_start_opt opt,
struct venc_frm_buf *frm_buf,
struct mtk_vcodec_mem *bs_buf,
struct venc_done_result *result)
{
int ret = 0;
struct venc_h264_inst *inst = (struct venc_h264_inst *)handle;
struct mtk_vcodec_ctx *ctx = inst->ctx;
mtk_vcodec_debug(inst, "opt %d ->", opt);
enable_irq(ctx->dev->enc_irq);
switch (opt) {
case VENC_START_OPT_ENCODE_SEQUENCE_HEADER: {
unsigned int bs_size_hdr;
ret = h264_encode_header(inst, bs_buf, &bs_size_hdr);
if (ret)
goto encode_err;
result->bs_size = bs_size_hdr;
result->is_key_frm = false;
break;
}
case VENC_START_OPT_ENCODE_FRAME: {
int hdr_sz;
int hdr_sz_ext;
int filler_sz = 0;
const int bs_alignment = 128;
struct mtk_vcodec_mem tmp_bs_buf;
unsigned int bs_size_hdr;
unsigned int bs_size_frm;
if (!inst->prepend_hdr) {
ret = h264_encode_frame(inst, frm_buf, bs_buf,
&result->bs_size);
if (ret)
goto encode_err;
result->is_key_frm = inst->vpu_inst.is_key_frm;
break;
}
mtk_vcodec_debug(inst, "h264_encode_frame prepend SPS/PPS");
ret = h264_encode_header(inst, bs_buf, &bs_size_hdr);
if (ret)
goto encode_err;
hdr_sz = bs_size_hdr;
hdr_sz_ext = (hdr_sz & (bs_alignment - 1));
if (hdr_sz_ext) {
filler_sz = bs_alignment - hdr_sz_ext;
if (hdr_sz_ext + H264_FILLER_MARKER_SIZE > bs_alignment)
filler_sz += bs_alignment;
h264_encode_filler(inst, bs_buf->va + hdr_sz,
filler_sz);
}
tmp_bs_buf.va = bs_buf->va + hdr_sz + filler_sz;
tmp_bs_buf.dma_addr = bs_buf->dma_addr + hdr_sz + filler_sz;
tmp_bs_buf.size = bs_buf->size - (hdr_sz + filler_sz);
ret = h264_encode_frame(inst, frm_buf, &tmp_bs_buf,
&bs_size_frm);
if (ret)
goto encode_err;
result->bs_size = hdr_sz + filler_sz + bs_size_frm;
mtk_vcodec_debug(inst, "hdr %d filler %d frame %d bs %d",
hdr_sz, filler_sz, bs_size_frm,
result->bs_size);
inst->prepend_hdr = 0;
result->is_key_frm = inst->vpu_inst.is_key_frm;
break;
}
default:
mtk_vcodec_err(inst, "venc_start_opt %d not supported", opt);
ret = -EINVAL;
break;
}
encode_err:
disable_irq(ctx->dev->enc_irq);
mtk_vcodec_debug(inst, "opt %d <-", opt);
return ret;
}
static int h264_enc_set_param(unsigned long handle,
enum venc_set_param_type type,
struct venc_enc_param *enc_prm)
{
int ret = 0;
struct venc_h264_inst *inst = (struct venc_h264_inst *)handle;
mtk_vcodec_debug(inst, "->type=%d", type);
switch (type) {
case VENC_SET_PARAM_ENC:
inst->vsi->config.input_fourcc = enc_prm->input_yuv_fmt;
inst->vsi->config.bitrate = enc_prm->bitrate;
inst->vsi->config.pic_w = enc_prm->width;
inst->vsi->config.pic_h = enc_prm->height;
inst->vsi->config.buf_w = enc_prm->buf_width;
inst->vsi->config.buf_h = enc_prm->buf_height;
inst->vsi->config.gop_size = enc_prm->gop_size;
inst->vsi->config.framerate = enc_prm->frm_rate;
inst->vsi->config.intra_period = enc_prm->intra_period;
inst->vsi->config.profile =
h264_get_profile(inst, enc_prm->h264_profile);
inst->vsi->config.level =
h264_get_level(inst, enc_prm->h264_level);
inst->vsi->config.wfd = 0;
ret = vpu_enc_set_param(&inst->vpu_inst, type, enc_prm);
if (ret)
break;
if (inst->work_buf_allocated) {
h264_enc_free_work_buf(inst);
inst->work_buf_allocated = false;
}
ret = h264_enc_alloc_work_buf(inst);
if (ret)
break;
inst->work_buf_allocated = true;
break;
case VENC_SET_PARAM_PREPEND_HEADER:
inst->prepend_hdr = 1;
mtk_vcodec_debug(inst, "set prepend header mode");
break;
default:
ret = vpu_enc_set_param(&inst->vpu_inst, type, enc_prm);
break;
}
mtk_vcodec_debug_leave(inst);
return ret;
}
static int h264_enc_deinit(unsigned long handle)
{
int ret = 0;
struct venc_h264_inst *inst = (struct venc_h264_inst *)handle;
mtk_vcodec_debug_enter(inst);
ret = vpu_enc_deinit(&inst->vpu_inst);
if (inst->work_buf_allocated)
h264_enc_free_work_buf(inst);
mtk_vcodec_debug_leave(inst);
kfree(inst);
return ret;
}
const struct venc_common_if *get_h264_enc_comm_if(void)
{
return &venc_h264_if;
}
