static int hva_h264_fill_slice_header(struct hva_ctx *pctx,
u8 *slice_header_addr,
struct hva_controls *ctrls,
int frame_num,
u16 *header_size,
u16 *header_offset0,
u16 *header_offset1,
u16 *header_offset2)
{
struct device *dev = ctx_to_dev(pctx);
int cabac = V4L2_MPEG_VIDEO_H264_ENTROPY_MODE_CABAC;
const unsigned char slice_header[] = { 0x00, 0x00, 0x00, 0x01,
0x41, 0x34, 0x07, 0x00};
int idr_pic_id = frame_num % 2;
enum hva_picture_coding_type type;
u32 frame_order = frame_num % ctrls->gop_size;
if (!(frame_num % ctrls->gop_size))
type = PICTURE_CODING_TYPE_I;
else
type = PICTURE_CODING_TYPE_P;
memcpy(slice_header_addr, slice_header, sizeof(slice_header));
*header_size = 56;
*header_offset0 = 40;
*header_offset1 = 13;
*header_offset2 = 0;
if (type == PICTURE_CODING_TYPE_I) {
slice_header_addr[4] = 0x65;
slice_header_addr[5] = 0x11;
if ((frame_num / ctrls->gop_size) % 2) {
*header_size += 4;
*header_offset1 += 4;
slice_header_addr[6] = 0x04;
slice_header_addr[7] = 0x70;
} else {
*header_size += 2;
*header_offset1 += 2;
slice_header_addr[6] = 0x09;
slice_header_addr[7] = 0xC0;
}
} else {
if (ctrls->entropy_mode == cabac) {
*header_size += 1;
*header_offset1 += 1;
slice_header_addr[7] = 0x80;
}
slice_header_addr[5] += ((frame_order & 0x0C) >> 2);
slice_header_addr[6] += ((frame_order & 0x03) << 6);
}
dev_dbg(dev,
"%s %s slice header order %d idrPicId %d header size %d\n",
pctx->name, __func__, frame_order, idr_pic_id, *header_size);
return 0;
}
static int hva_h264_fill_data_nal(struct hva_ctx *pctx,
unsigned int stuffing_bytes, u8 *addr,
unsigned int stream_size, unsigned int *size)
{
struct device *dev = ctx_to_dev(pctx);
const u8 start[] = { 0x00, 0x00, 0x00, 0x01 };
dev_dbg(dev, "%s %s stuffing bytes %d\n", pctx->name, __func__,
stuffing_bytes);
if ((*size + stuffing_bytes + H264_FILLER_DATA_SIZE) > stream_size) {
dev_dbg(dev, "%s %s too many stuffing bytes %d\n",
pctx->name, __func__, stuffing_bytes);
return 0;
}
memcpy(addr + *size, start, sizeof(start));
*size += sizeof(start);
addr[*size] = NALU_TYPE_FILLER_DATA;
*size += 1;
memset(addr + *size, 0xff, stuffing_bytes);
*size += stuffing_bytes;
addr[*size] = 0x80;
*size += 1;
return 0;
}
static int hva_h264_fill_sei_nal(struct hva_ctx *pctx,
enum hva_h264_sei_payload_type type,
u8 *addr, u32 *size)
{
struct device *dev = ctx_to_dev(pctx);
const u8 start[] = { 0x00, 0x00, 0x00, 0x01 };
struct hva_h264_stereo_video_sei info;
u8 offset = 7;
u8 msg = 0;
memcpy(addr + *size, start, sizeof(start));
*size += sizeof(start);
addr[*size] = NALU_TYPE_SEI;
*size += 1;
addr[*size] = type;
*size += 1;
switch (type) {
case SEI_STEREO_VIDEO_INFO:
memset(&info, 0, sizeof(info));
info.field_views_flag = 1;
info.top_field_is_left_view_flag = 1;
addr[*size] = 1;
*size += 1;
msg = info.field_views_flag << offset--;
if (info.field_views_flag) {
msg |= info.top_field_is_left_view_flag <<
offset--;
} else {
msg |= info.current_frame_is_left_view_flag <<
offset--;
msg |= info.next_frame_is_second_view_flag <<
offset--;
}
msg |= info.left_view_self_contained_flag << offset--;
msg |= info.right_view_self_contained_flag << offset--;
addr[*size] = msg;
*size += 1;
addr[*size] = 0x80;
*size += 1;
return 0;
case SEI_BUFFERING_PERIOD:
case SEI_PICTURE_TIMING:
case SEI_FRAME_PACKING_ARRANGEMENT:
default:
dev_err(dev, "%s sei nal type not supported %d\n",
pctx->name, type);
return -EINVAL;
}
}
static int hva_h264_prepare_task(struct hva_ctx *pctx,
struct hva_h264_task *task,
struct hva_frame *frame,
struct hva_stream *stream)
{
struct hva_dev *hva = ctx_to_hdev(pctx);
struct device *dev = ctx_to_dev(pctx);
struct hva_h264_ctx *ctx = (struct hva_h264_ctx *)pctx->priv;
struct hva_buffer *seq_info = ctx->seq_info;
struct hva_buffer *fwd_ref_frame = ctx->ref_frame;
struct hva_buffer *loc_rec_frame = ctx->rec_frame;
struct hva_h264_td *td = &task->td;
struct hva_controls *ctrls = &pctx->ctrls;
struct v4l2_fract *time_per_frame = &pctx->ctrls.time_per_frame;
int cavlc = V4L2_MPEG_VIDEO_H264_ENTROPY_MODE_CAVLC;
u32 frame_num = pctx->stream_num;
u32 addr_esram = hva->esram_addr;
enum v4l2_mpeg_video_h264_level level;
dma_addr_t paddr = 0;
u8 *slice_header_vaddr;
u32 frame_width = frame->info.aligned_width;
u32 frame_height = frame->info.aligned_height;
u32 max_cpb_buffer_size;
unsigned int payload = stream->bytesused;
u32 max_bitrate;
if ((frame_width > max(H264_MAX_SIZE_W, H264_MAX_SIZE_H)) ||
(frame_height > max(H264_MAX_SIZE_W, H264_MAX_SIZE_H))) {
dev_err(dev,
"%s width(%d) or height(%d) exceeds limits (%dx%d)\n",
pctx->name, frame_width, frame_height,
H264_MAX_SIZE_W, H264_MAX_SIZE_H);
return -EINVAL;
}
level = ctrls->level;
memset(td, 0, sizeof(struct hva_h264_td));
td->frame_width = frame_width;
td->frame_height = frame_height;
td->window_width = frame_width;
td->window_height = frame_height;
td->window_horizontal_offset = 0;
td->window_vertical_offset = 0;
td->first_picture_in_sequence = (!frame_num) ? 1 : 0;
td->pic_order_cnt_type = 2;
td->use_constrained_intra_flag = false;
td->brc_type = (ctrls->bitrate_mode == V4L2_MPEG_VIDEO_BITRATE_MODE_CBR)
? BRC_TYPE_CBR : BRC_TYPE_VBR;
td->entropy_coding_mode = (ctrls->entropy_mode == cavlc) ? CAVLC :
CABAC;
td->bit_rate = ctrls->bitrate;
if (time_per_frame->numerator >= 536) {
td->framerate_den = 1;
td->framerate_num = (time_per_frame->denominator +
(time_per_frame->numerator >> 1) - 1) /
time_per_frame->numerator;
td->bit_rate /= time_per_frame->numerator;
td->bit_rate *= time_per_frame->denominator;
td->bit_rate /= td->framerate_num;
} else {
td->framerate_den = time_per_frame->numerator;
td->framerate_num = time_per_frame->denominator;
}
if (ctrls->profile >= V4L2_MPEG_VIDEO_H264_PROFILE_HIGH)
max_bitrate = h264_infos_list[level].max_bitrate *
H264_FACTOR_HIGH;
else
max_bitrate = h264_infos_list[level].max_bitrate *
H264_FACTOR_BASELINE;
if (td->bit_rate > max_bitrate) {
dev_dbg(dev,
"%s bitrate (%d) larger than level and profile allow, clip to %d\n",
pctx->name, td->bit_rate, max_bitrate);
td->bit_rate = max_bitrate;
}
td->cpb_buffer_size = ctrls->cpb_size * 8000;
if (ctrls->profile >= V4L2_MPEG_VIDEO_H264_PROFILE_HIGH)
max_cpb_buffer_size =
h264_infos_list[level].max_cpb_size * H264_FACTOR_HIGH;
else
max_cpb_buffer_size =
h264_infos_list[level].max_cpb_size * H264_FACTOR_BASELINE;
if (td->cpb_buffer_size > max_cpb_buffer_size) {
dev_dbg(dev,
"%s cpb size larger than level %d allows, clip to %d\n",
pctx->name, td->cpb_buffer_size, max_cpb_buffer_size);
td->cpb_buffer_size = max_cpb_buffer_size;
}
td->brc_no_skip = 0;
if ((ctrls->bitrate_mode == V4L2_MPEG_VIDEO_BITRATE_MODE_CBR) &&
td->bit_rate)
td->delay = 1000 * (td->cpb_buffer_size / td->bit_rate);
else
td->delay = 0;
switch (frame->info.pixelformat) {
case V4L2_PIX_FMT_NV12:
td->sampling_mode = SAMPLING_MODE_NV12;
break;
case V4L2_PIX_FMT_NV21:
td->sampling_mode = SAMPLING_MODE_NV21;
break;
default:
dev_err(dev, "%s invalid source pixel format\n",
pctx->name);
return -EINVAL;
}
td->rgb2_yuv_y_coeff = 0x12031008;
td->rgb2_yuv_u_coeff = 0x800EF7FB;
td->rgb2_yuv_v_coeff = 0x80FEF40E;
td->transform_mode = ctrls->dct8x8;
td->encoder_complexity = 2;
td->quant = 28;
if (td->framerate_den == 0) {
dev_err(dev, "%s invalid framerate\n", pctx->name);
return -EINVAL;
}
if (td->framerate_num == 0)
td->brc_type = 0;
td->strict_hrd_compliancy = 1;
td->qp_min = clamp_val(ctrls->qpmin, 0, 51);
td->qp_max = clamp_val(ctrls->qpmax, 0, 51);
td->addr_source_buffer = frame->paddr;
td->addr_fwd_ref_buffer = fwd_ref_frame->paddr;
td->addr_rec_buffer = loc_rec_frame->paddr;
td->addr_output_bitstream_end = (u32)stream->paddr + stream->size;
td->addr_output_bitstream_start = (u32)stream->paddr;
td->bitstream_offset = (((u32)stream->paddr & 0xF) << 3) &
BITSTREAM_OFFSET_MASK;
td->addr_param_out = (u32)ctx->task->paddr +
offsetof(struct hva_h264_task, po);
if (frame_num % 2) {
paddr = seq_info->paddr;
td->addr_spatial_context = ALIGN(paddr, 0x100);
paddr = seq_info->paddr + DATA_SIZE(frame_width,
frame_height);
td->addr_temporal_context = ALIGN(paddr, 0x100);
} else {
paddr = seq_info->paddr;
td->addr_temporal_context = ALIGN(paddr, 0x100);
paddr = seq_info->paddr + DATA_SIZE(frame_width,
frame_height);
td->addr_spatial_context = ALIGN(paddr, 0x100);
}
paddr = seq_info->paddr + 2 * DATA_SIZE(frame_width, frame_height);
td->addr_brc_in_out_parameter = ALIGN(paddr, 0x100);
paddr = td->addr_brc_in_out_parameter + BRC_DATA_SIZE;
td->addr_slice_header = ALIGN(paddr, 0x100);
td->addr_external_sw = ALIGN(addr_esram, 0x100);
addr_esram += SEARCH_WINDOW_BUFFER_MAX_SIZE(frame_width);
td->addr_local_rec_buffer = ALIGN(addr_esram, 0x100);
addr_esram += LOCAL_RECONSTRUCTED_BUFFER_MAX_SIZE(frame_width);
td->addr_lctx = ALIGN(addr_esram, 0x100);
addr_esram += CTX_MB_BUFFER_MAX_SIZE(max(frame_width, frame_height));
td->addr_cabac_context_buffer = ALIGN(addr_esram, 0x100);
if (!(frame_num % ctrls->gop_size)) {
td->picture_coding_type = PICTURE_CODING_TYPE_I;
stream->vbuf.flags |= V4L2_BUF_FLAG_KEYFRAME;
} else {
td->picture_coding_type = PICTURE_CODING_TYPE_P;
stream->vbuf.flags &= ~V4L2_BUF_FLAG_KEYFRAME;
}
slice_header_vaddr = seq_info->vaddr + (td->addr_slice_header -
seq_info->paddr);
hva_h264_fill_slice_header(pctx, slice_header_vaddr, ctrls, frame_num,
&td->slice_header_size_in_bits,
&td->slice_header_offset0,
&td->slice_header_offset1,
&td->slice_header_offset2);
td->chroma_qp_index_offset = 2;
td->slice_synchro_enable = 0;
td->max_slice_number = 1;
if ((stream->vbuf.flags == V4L2_BUF_FLAG_KEYFRAME) &&
(payload > MAX_SPS_PPS_SIZE)) {
dev_err(dev, "%s invalid sps/pps size %d\n", pctx->name,
payload);
return -EINVAL;
}
if (stream->vbuf.flags != V4L2_BUF_FLAG_KEYFRAME)
payload = 0;
if (ctrls->sei_fp && hva_h264_fill_sei_nal(pctx, SEI_STEREO_VIDEO_INFO,
(u8 *)stream->vaddr,
&payload)) {
dev_err(dev, "%s fail to get SEI nal\n", pctx->name);
return -EINVAL;
}
td->non_vcl_nalu_size = payload * 8;
td->addr_output_bitstream_start += ((payload >> 4) << 4);
td->bitstream_offset += (payload - ((payload >> 4) << 4)) * 8;
stream->bytesused = payload;
return 0;
}
static unsigned int hva_h264_get_stream_size(struct hva_h264_task *task)
{
struct hva_h264_po *po = &task->po;
return po->bitstream_size;
}
static u32 hva_h264_get_stuffing_bytes(struct hva_h264_task *task)
{
struct hva_h264_po *po = &task->po;
return po->stuffing_bits >> 3;
}
static int hva_h264_open(struct hva_ctx *pctx)
{
struct device *dev = ctx_to_dev(pctx);
struct hva_h264_ctx *ctx;
struct hva_dev *hva = ctx_to_hdev(pctx);
u32 frame_width = pctx->frameinfo.aligned_width;
u32 frame_height = pctx->frameinfo.aligned_height;
u32 size;
int ret;
size = SEARCH_WINDOW_BUFFER_MAX_SIZE(frame_width) +
LOCAL_RECONSTRUCTED_BUFFER_MAX_SIZE(frame_width) +
CTX_MB_BUFFER_MAX_SIZE(max(frame_width, frame_height)) +
CABAC_CONTEXT_BUFFER_MAX_SIZE(frame_width);
if (hva->esram_size < size) {
dev_err(dev, "%s not enough esram (max:%d request:%d)\n",
pctx->name, hva->esram_size, size);
ret = -EINVAL;
goto err;
}
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx) {
ret = -ENOMEM;
goto err;
}
ret = hva_mem_alloc(pctx,
2 * DATA_SIZE(frame_width, frame_height) +
SLICE_HEADER_SIZE +
BRC_DATA_SIZE,
"hva sequence info",
&ctx->seq_info);
if (ret) {
dev_err(dev,
"%s failed to allocate sequence info buffer\n",
pctx->name);
goto err_ctx;
}
ret = hva_mem_alloc(pctx,
frame_width * frame_height * 3 / 2,
"hva reference frame",
&ctx->ref_frame);
if (ret) {
dev_err(dev, "%s failed to allocate reference frame buffer\n",
pctx->name);
goto err_seq_info;
}
ret = hva_mem_alloc(pctx,
frame_width * frame_height * 3 / 2,
"hva reconstructed frame",
&ctx->rec_frame);
if (ret) {
dev_err(dev,
"%s failed to allocate reconstructed frame buffer\n",
pctx->name);
goto err_ref_frame;
}
ret = hva_mem_alloc(pctx,
sizeof(struct hva_h264_task),
"hva task descriptor",
&ctx->task);
if (ret) {
dev_err(dev,
"%s failed to allocate task descriptor\n",
pctx->name);
goto err_rec_frame;
}
pctx->priv = (void *)ctx;
return 0;
err_rec_frame:
hva_mem_free(pctx, ctx->rec_frame);
err_ref_frame:
hva_mem_free(pctx, ctx->ref_frame);
err_seq_info:
hva_mem_free(pctx, ctx->seq_info);
err_ctx:
devm_kfree(dev, ctx);
err:
return ret;
}
static int hva_h264_close(struct hva_ctx *pctx)
{
struct hva_h264_ctx *ctx = (struct hva_h264_ctx *)pctx->priv;
struct device *dev = ctx_to_dev(pctx);
if (ctx->seq_info)
hva_mem_free(pctx, ctx->seq_info);
if (ctx->ref_frame)
hva_mem_free(pctx, ctx->ref_frame);
if (ctx->rec_frame)
hva_mem_free(pctx, ctx->rec_frame);
if (ctx->task)
hva_mem_free(pctx, ctx->task);
devm_kfree(dev, ctx);
return 0;
}
static int hva_h264_encode(struct hva_ctx *pctx, struct hva_frame *frame,
struct hva_stream *stream)
{
struct hva_h264_ctx *ctx = (struct hva_h264_ctx *)pctx->priv;
struct hva_h264_task *task = (struct hva_h264_task *)ctx->task->vaddr;
struct hva_buffer *tmp_frame;
u32 stuffing_bytes = 0;
int ret = 0;
ret = hva_h264_prepare_task(pctx, task, frame, stream);
if (ret)
goto err;
ret = hva_hw_execute_task(pctx, H264_ENC, ctx->task);
if (ret)
goto err;
pctx->stream_num++;
stream->bytesused += hva_h264_get_stream_size(task);
stuffing_bytes = hva_h264_get_stuffing_bytes(task);
if (stuffing_bytes)
hva_h264_fill_data_nal(pctx, stuffing_bytes,
(u8 *)stream->vaddr,
stream->size,
&stream->bytesused);
tmp_frame = ctx->ref_frame;
ctx->ref_frame = ctx->rec_frame;
ctx->rec_frame = tmp_frame;
return 0;
err:
stream->bytesused = 0;
return ret;
}
