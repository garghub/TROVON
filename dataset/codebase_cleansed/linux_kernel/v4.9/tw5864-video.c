static int tw5864_queue_setup(struct vb2_queue *q, unsigned int *num_buffers,
unsigned int *num_planes, unsigned int sizes[],
struct device *alloc_ctxs[])
{
if (*num_planes)
return sizes[0] < H264_VLC_BUF_SIZE ? -EINVAL : 0;
sizes[0] = H264_VLC_BUF_SIZE;
*num_planes = 1;
return 0;
}
static void tw5864_buf_queue(struct vb2_buffer *vb)
{
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct vb2_queue *vq = vb->vb2_queue;
struct tw5864_input *dev = vb2_get_drv_priv(vq);
struct tw5864_buf *buf = container_of(vbuf, struct tw5864_buf, vb);
unsigned long flags;
spin_lock_irqsave(&dev->slock, flags);
list_add_tail(&buf->list, &dev->active);
spin_unlock_irqrestore(&dev->slock, flags);
}
static int tw5864_input_std_get(struct tw5864_input *input,
enum tw5864_vid_std *std)
{
struct tw5864_dev *dev = input->root;
u8 std_reg = tw_indir_readb(TW5864_INDIR_VIN_E(input->nr));
*std = (std_reg & 0x70) >> 4;
if (std_reg & 0x80) {
dev_dbg(&dev->pci->dev,
"Video format detection is in progress, please wait\n");
return -EAGAIN;
}
return 0;
}
static int tw5864_enable_input(struct tw5864_input *input)
{
struct tw5864_dev *dev = input->root;
int nr = input->nr;
unsigned long flags;
int d1_width = 720;
int d1_height;
int frame_width_bus_value = 0;
int frame_height_bus_value = 0;
int reg_frame_bus = 0x1c;
int fmt_reg_value = 0;
int downscale_enabled = 0;
dev_dbg(&dev->pci->dev, "Enabling channel %d\n", nr);
input->frame_seqno = 0;
input->frame_gop_seqno = 0;
input->h264_idr_pic_id = 0;
input->reg_dsp_qp = input->qp;
input->reg_dsp_ref_mvp_lambda = lambda_lookup_table[input->qp];
input->reg_dsp_i4x4_weight = intra4x4_lambda3[input->qp];
input->reg_emu = TW5864_EMU_EN_LPF | TW5864_EMU_EN_BHOST
| TW5864_EMU_EN_SEN | TW5864_EMU_EN_ME | TW5864_EMU_EN_DDR;
input->reg_dsp = nr
| TW5864_DSP_CHROM_SW
| ((0xa << 8) & TW5864_DSP_MB_DELAY)
;
input->resolution = D1;
d1_height = (input->std == STD_NTSC) ? 480 : 576;
input->width = d1_width;
input->height = d1_height;
input->reg_interlacing = 0x4;
switch (input->resolution) {
case D1:
frame_width_bus_value = 0x2cf;
frame_height_bus_value = input->height - 1;
reg_frame_bus = 0x1c;
fmt_reg_value = 0;
downscale_enabled = 0;
input->reg_dsp_codec |= TW5864_CIF_MAP_MD | TW5864_HD1_MAP_MD;
input->reg_emu |= TW5864_DSP_FRAME_TYPE_D1;
input->reg_interlacing = TW5864_DI_EN | TW5864_DSP_INTER_ST;
tw_setl(TW5864_FULL_HALF_FLAG, 1 << nr);
break;
case HD1:
input->height /= 2;
input->width /= 2;
frame_width_bus_value = 0x2cf;
frame_height_bus_value = input->height * 2 - 1;
reg_frame_bus = 0x1c;
fmt_reg_value = 0;
downscale_enabled = 0;
input->reg_dsp_codec |= TW5864_HD1_MAP_MD;
input->reg_emu |= TW5864_DSP_FRAME_TYPE_D1;
tw_clearl(TW5864_FULL_HALF_FLAG, 1 << nr);
break;
case CIF:
input->height /= 4;
input->width /= 2;
frame_width_bus_value = 0x15f;
frame_height_bus_value = input->height * 2 - 1;
reg_frame_bus = 0x07;
fmt_reg_value = 1;
downscale_enabled = 1;
input->reg_dsp_codec |= TW5864_CIF_MAP_MD;
tw_clearl(TW5864_FULL_HALF_FLAG, 1 << nr);
break;
case QCIF:
input->height /= 4;
input->width /= 4;
frame_width_bus_value = 0x15f;
frame_height_bus_value = input->height * 2 - 1;
reg_frame_bus = 0x07;
fmt_reg_value = 1;
downscale_enabled = 1;
input->reg_dsp_codec |= TW5864_CIF_MAP_MD;
tw_clearl(TW5864_FULL_HALF_FLAG, 1 << nr);
break;
}
tw_indir_writeb(TW5864_INDIR_IN_PIC_WIDTH(nr), d1_width / 4);
tw_indir_writeb(TW5864_INDIR_IN_PIC_HEIGHT(nr), d1_height / 4);
tw_indir_writeb(TW5864_INDIR_OUT_PIC_WIDTH(nr), input->width / 4);
tw_indir_writeb(TW5864_INDIR_OUT_PIC_HEIGHT(nr), input->height / 4);
tw_writel(TW5864_DSP_PIC_MAX_MB,
((input->width / 16) << 8) | (input->height / 16));
tw_writel(TW5864_FRAME_WIDTH_BUS_A(nr),
frame_width_bus_value);
tw_writel(TW5864_FRAME_WIDTH_BUS_B(nr),
frame_width_bus_value);
tw_writel(TW5864_FRAME_HEIGHT_BUS_A(nr),
frame_height_bus_value);
tw_writel(TW5864_FRAME_HEIGHT_BUS_B(nr),
(frame_height_bus_value + 1) / 2 - 1);
tw5864_frame_interval_set(input);
if (downscale_enabled)
tw_setl(TW5864_H264EN_CH_DNS, 1 << nr);
tw_mask_shift_writel(TW5864_H264EN_CH_FMT_REG1, 0x3, 2 * nr,
fmt_reg_value);
tw_mask_shift_writel((nr < 2
? TW5864_H264EN_RATE_MAX_LINE_REG1
: TW5864_H264EN_RATE_MAX_LINE_REG2),
0x1f, 5 * (nr % 2),
input->std == STD_NTSC ? 29 : 24);
tw_mask_shift_writel((nr < 2) ? TW5864_FRAME_BUS1 :
TW5864_FRAME_BUS2, 0xff, (nr % 2) * 8,
reg_frame_bus);
spin_lock_irqsave(&dev->slock, flags);
input->enabled = 1;
spin_unlock_irqrestore(&dev->slock, flags);
return 0;
}
void tw5864_request_encoded_frame(struct tw5864_input *input)
{
struct tw5864_dev *dev = input->root;
u32 enc_buf_id_new;
tw_setl(TW5864_DSP_CODEC, TW5864_CIF_MAP_MD | TW5864_HD1_MAP_MD);
tw_writel(TW5864_EMU, input->reg_emu);
tw_writel(TW5864_INTERLACING, input->reg_interlacing);
tw_writel(TW5864_DSP, input->reg_dsp);
tw_writel(TW5864_DSP_QP, input->reg_dsp_qp);
tw_writel(TW5864_DSP_REF_MVP_LAMBDA, input->reg_dsp_ref_mvp_lambda);
tw_writel(TW5864_DSP_I4x4_WEIGHT, input->reg_dsp_i4x4_weight);
tw_mask_shift_writel(TW5864_DSP_INTRA_MODE, TW5864_DSP_INTRA_MODE_MASK,
TW5864_DSP_INTRA_MODE_SHIFT,
TW5864_DSP_INTRA_MODE_16x16);
if (input->frame_gop_seqno == 0) {
tw_writel(TW5864_MOTION_SEARCH_ETC, TW5864_INTRA_EN);
input->h264_idr_pic_id++;
input->h264_idr_pic_id &= TW5864_DSP_REF_FRM;
} else {
tw_writel(TW5864_MOTION_SEARCH_ETC, TW5864_INTRA_EN |
TW5864_ME_EN | BIT(5) );
}
tw5864_prepare_frame_headers(input);
tw_writel(TW5864_VLC,
TW5864_VLC_PCI_SEL |
((input->tail_nb_bits + 24) << TW5864_VLC_BIT_ALIGN_SHIFT) |
input->reg_dsp_qp);
enc_buf_id_new = tw_mask_shift_readl(TW5864_ENC_BUF_PTR_REC1, 0x3,
2 * input->nr);
tw_writel(TW5864_DSP_ENC_ORG_PTR_REG,
enc_buf_id_new << TW5864_DSP_ENC_ORG_PTR_SHIFT);
tw_writel(TW5864_DSP_ENC_REC,
enc_buf_id_new << 12 | ((enc_buf_id_new + 3) & 3));
tw_writel(TW5864_SLICE, TW5864_START_NSLICE);
tw_writel(TW5864_SLICE, 0);
}
static int tw5864_disable_input(struct tw5864_input *input)
{
struct tw5864_dev *dev = input->root;
unsigned long flags;
dev_dbg(&dev->pci->dev, "Disabling channel %d\n", input->nr);
spin_lock_irqsave(&dev->slock, flags);
input->enabled = 0;
spin_unlock_irqrestore(&dev->slock, flags);
return 0;
}
static int tw5864_start_streaming(struct vb2_queue *q, unsigned int count)
{
struct tw5864_input *input = vb2_get_drv_priv(q);
int ret;
ret = tw5864_enable_input(input);
if (!ret)
return 0;
while (!list_empty(&input->active)) {
struct tw5864_buf *buf = list_entry(input->active.next,
struct tw5864_buf, list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_QUEUED);
}
return ret;
}
static void tw5864_stop_streaming(struct vb2_queue *q)
{
unsigned long flags;
struct tw5864_input *input = vb2_get_drv_priv(q);
tw5864_disable_input(input);
spin_lock_irqsave(&input->slock, flags);
if (input->vb) {
vb2_buffer_done(&input->vb->vb.vb2_buf, VB2_BUF_STATE_ERROR);
input->vb = NULL;
}
while (!list_empty(&input->active)) {
struct tw5864_buf *buf = list_entry(input->active.next,
struct tw5864_buf, list);
list_del(&buf->list);
vb2_buffer_done(&buf->vb.vb2_buf, VB2_BUF_STATE_ERROR);
}
spin_unlock_irqrestore(&input->slock, flags);
}
static int tw5864_s_ctrl(struct v4l2_ctrl *ctrl)
{
struct tw5864_input *input =
container_of(ctrl->handler, struct tw5864_input, hdl);
struct tw5864_dev *dev = input->root;
unsigned long flags;
switch (ctrl->id) {
case V4L2_CID_BRIGHTNESS:
tw_indir_writeb(TW5864_INDIR_VIN_A_BRIGHT(input->nr),
(u8)ctrl->val);
break;
case V4L2_CID_HUE:
tw_indir_writeb(TW5864_INDIR_VIN_7_HUE(input->nr),
(u8)ctrl->val);
break;
case V4L2_CID_CONTRAST:
tw_indir_writeb(TW5864_INDIR_VIN_9_CNTRST(input->nr),
(u8)ctrl->val);
break;
case V4L2_CID_SATURATION:
tw_indir_writeb(TW5864_INDIR_VIN_B_SAT_U(input->nr),
(u8)ctrl->val);
tw_indir_writeb(TW5864_INDIR_VIN_C_SAT_V(input->nr),
(u8)ctrl->val);
break;
case V4L2_CID_MPEG_VIDEO_GOP_SIZE:
input->gop = ctrl->val;
return 0;
case V4L2_CID_MPEG_VIDEO_H264_MIN_QP:
spin_lock_irqsave(&input->slock, flags);
input->qp = ctrl->val;
input->reg_dsp_qp = input->qp;
input->reg_dsp_ref_mvp_lambda = lambda_lookup_table[input->qp];
input->reg_dsp_i4x4_weight = intra4x4_lambda3[input->qp];
spin_unlock_irqrestore(&input->slock, flags);
return 0;
case V4L2_CID_DETECT_MD_GLOBAL_THRESHOLD:
memset(input->md_threshold_grid_values, ctrl->val,
sizeof(input->md_threshold_grid_values));
return 0;
case V4L2_CID_DETECT_MD_MODE:
return 0;
case V4L2_CID_DETECT_MD_THRESHOLD_GRID:
memcpy(input->md_threshold_grid_values,
input->md_threshold_grid_ctrl->p_new.p_u16,
sizeof(input->md_threshold_grid_values));
return 0;
}
return 0;
}
static int tw5864_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct tw5864_input *input = video_drvdata(file);
f->fmt.pix.width = 720;
switch (input->std) {
default:
WARN_ON_ONCE(1);
case STD_NTSC:
f->fmt.pix.height = 480;
break;
case STD_PAL:
case STD_SECAM:
f->fmt.pix.height = 576;
break;
}
f->fmt.pix.field = V4L2_FIELD_INTERLACED;
f->fmt.pix.pixelformat = V4L2_PIX_FMT_H264;
f->fmt.pix.sizeimage = H264_VLC_BUF_SIZE;
f->fmt.pix.colorspace = V4L2_COLORSPACE_SMPTE170M;
return 0;
}
static int tw5864_enum_input(struct file *file, void *priv,
struct v4l2_input *i)
{
struct tw5864_input *input = video_drvdata(file);
struct tw5864_dev *dev = input->root;
u8 indir_0x000 = tw_indir_readb(TW5864_INDIR_VIN_0(input->nr));
u8 indir_0x00d = tw_indir_readb(TW5864_INDIR_VIN_D(input->nr));
u8 v1 = indir_0x000;
u8 v2 = indir_0x00d;
if (i->index)
return -EINVAL;
i->type = V4L2_INPUT_TYPE_CAMERA;
snprintf(i->name, sizeof(i->name), "Encoder %d", input->nr);
i->std = TW5864_NORMS;
if (v1 & (1 << 7))
i->status |= V4L2_IN_ST_NO_SYNC;
if (!(v1 & (1 << 6)))
i->status |= V4L2_IN_ST_NO_H_LOCK;
if (v1 & (1 << 2))
i->status |= V4L2_IN_ST_NO_SIGNAL;
if (v1 & (1 << 1))
i->status |= V4L2_IN_ST_NO_COLOR;
if (v2 & (1 << 2))
i->status |= V4L2_IN_ST_MACROVISION;
return 0;
}
static int tw5864_g_input(struct file *file, void *priv, unsigned int *i)
{
*i = 0;
return 0;
}
static int tw5864_s_input(struct file *file, void *priv, unsigned int i)
{
if (i)
return -EINVAL;
return 0;
}
static int tw5864_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct tw5864_input *input = video_drvdata(file);
strcpy(cap->driver, "tw5864");
snprintf(cap->card, sizeof(cap->card), "TW5864 Encoder %d",
input->nr);
sprintf(cap->bus_info, "PCI:%s", pci_name(input->root->pci));
return 0;
}
static int tw5864_querystd(struct file *file, void *priv, v4l2_std_id *std)
{
struct tw5864_input *input = video_drvdata(file);
enum tw5864_vid_std tw_std;
int ret;
ret = tw5864_input_std_get(input, &tw_std);
if (ret)
return ret;
*std = tw5864_get_v4l2_std(tw_std);
return 0;
}
static int tw5864_g_std(struct file *file, void *priv, v4l2_std_id *std)
{
struct tw5864_input *input = video_drvdata(file);
*std = input->v4l2_std;
return 0;
}
static int tw5864_s_std(struct file *file, void *priv, v4l2_std_id std)
{
struct tw5864_input *input = video_drvdata(file);
struct tw5864_dev *dev = input->root;
input->v4l2_std = std;
input->std = tw5864_from_v4l2_std(std);
tw_indir_writeb(TW5864_INDIR_VIN_E(input->nr), input->std);
return 0;
}
static int tw5864_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
if (f->index)
return -EINVAL;
f->pixelformat = V4L2_PIX_FMT_H264;
return 0;
}
static int tw5864_subscribe_event(struct v4l2_fh *fh,
const struct v4l2_event_subscription *sub)
{
switch (sub->type) {
case V4L2_EVENT_CTRL:
return v4l2_ctrl_subscribe_event(fh, sub);
case V4L2_EVENT_MOTION_DET:
return v4l2_event_subscribe(fh, sub, 30, NULL);
}
return -EINVAL;
}
static void tw5864_frame_interval_set(struct tw5864_input *input)
{
struct tw5864_dev *dev = input->root;
u32 unary_framerate = 0;
int shift = 0;
int std_max_fps = input->std == STD_NTSC ? 30 : 25;
for (shift = 0; shift < std_max_fps; shift += input->frame_interval)
unary_framerate |= 0x00000001 << shift;
tw_writel(TW5864_H264EN_RATE_CNTL_LO_WORD(input->nr, 0),
unary_framerate >> 16);
tw_writel(TW5864_H264EN_RATE_CNTL_HI_WORD(input->nr, 0),
unary_framerate & 0xffff);
}
static int tw5864_frameinterval_get(struct tw5864_input *input,
struct v4l2_fract *frameinterval)
{
switch (input->std) {
case STD_NTSC:
frameinterval->numerator = 1001;
frameinterval->denominator = 30000;
break;
case STD_PAL:
case STD_SECAM:
frameinterval->numerator = 1;
frameinterval->denominator = 25;
break;
default:
WARN(1, "tw5864_frameinterval_get requested for unknown std %d\n",
input->std);
return -EINVAL;
}
return 0;
}
static int tw5864_enum_framesizes(struct file *file, void *priv,
struct v4l2_frmsizeenum *fsize)
{
struct tw5864_input *input = video_drvdata(file);
if (fsize->index > 0)
return -EINVAL;
if (fsize->pixel_format != V4L2_PIX_FMT_H264)
return -EINVAL;
fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;
fsize->discrete.width = 720;
fsize->discrete.height = input->std == STD_NTSC ? 480 : 576;
return 0;
}
static int tw5864_enum_frameintervals(struct file *file, void *priv,
struct v4l2_frmivalenum *fintv)
{
struct tw5864_input *input = video_drvdata(file);
struct v4l2_fract frameinterval;
int std_max_fps = input->std == STD_NTSC ? 30 : 25;
struct v4l2_frmsizeenum fsize = { .index = fintv->index,
.pixel_format = fintv->pixel_format };
int ret;
ret = tw5864_enum_framesizes(file, priv, &fsize);
if (ret)
return ret;
if (fintv->width != fsize.discrete.width ||
fintv->height != fsize.discrete.height)
return -EINVAL;
fintv->type = V4L2_FRMIVAL_TYPE_STEPWISE;
ret = tw5864_frameinterval_get(input, &frameinterval);
fintv->stepwise.step = frameinterval;
fintv->stepwise.min = frameinterval;
fintv->stepwise.max = frameinterval;
fintv->stepwise.max.numerator *= std_max_fps;
return ret;
}
static int tw5864_g_parm(struct file *file, void *priv,
struct v4l2_streamparm *sp)
{
struct tw5864_input *input = video_drvdata(file);
struct v4l2_captureparm *cp = &sp->parm.capture;
int ret;
cp->capability = V4L2_CAP_TIMEPERFRAME;
ret = tw5864_frameinterval_get(input, &cp->timeperframe);
cp->timeperframe.numerator *= input->frame_interval;
cp->capturemode = 0;
cp->readbuffers = 2;
return ret;
}
static int tw5864_s_parm(struct file *file, void *priv,
struct v4l2_streamparm *sp)
{
struct tw5864_input *input = video_drvdata(file);
struct v4l2_fract *t = &sp->parm.capture.timeperframe;
struct v4l2_fract time_base;
int ret;
ret = tw5864_frameinterval_get(input, &time_base);
if (ret)
return ret;
if (!t->numerator || !t->denominator) {
t->numerator = time_base.numerator * input->frame_interval;
t->denominator = time_base.denominator;
} else if (t->denominator != time_base.denominator) {
t->numerator = t->numerator * time_base.denominator /
t->denominator;
t->denominator = time_base.denominator;
}
input->frame_interval = t->numerator / time_base.numerator;
if (input->frame_interval < 1)
input->frame_interval = 1;
tw5864_frame_interval_set(input);
return tw5864_g_parm(file, priv, sp);
}
static int tw5864_g_reg(struct file *file, void *fh,
struct v4l2_dbg_register *reg)
{
struct tw5864_input *input = video_drvdata(file);
struct tw5864_dev *dev = input->root;
if (reg->reg < INDIR_SPACE_MAP_SHIFT) {
if (reg->reg > 0x87fff)
return -EINVAL;
reg->size = 4;
reg->val = tw_readl(reg->reg);
} else {
__u64 indir_addr = reg->reg - INDIR_SPACE_MAP_SHIFT;
if (indir_addr > 0xefe)
return -EINVAL;
reg->size = 1;
reg->val = tw_indir_readb(reg->reg);
}
return 0;
}
static int tw5864_s_reg(struct file *file, void *fh,
const struct v4l2_dbg_register *reg)
{
struct tw5864_input *input = video_drvdata(file);
struct tw5864_dev *dev = input->root;
if (reg->reg < INDIR_SPACE_MAP_SHIFT) {
if (reg->reg > 0x87fff)
return -EINVAL;
tw_writel(reg->reg, reg->val);
} else {
__u64 indir_addr = reg->reg - INDIR_SPACE_MAP_SHIFT;
if (indir_addr > 0xefe)
return -EINVAL;
tw_indir_writeb(reg->reg, reg->val);
}
return 0;
}
int tw5864_video_init(struct tw5864_dev *dev, int *video_nr)
{
int i;
int ret;
unsigned long flags;
int last_dma_allocated = -1;
int last_input_nr_registered = -1;
for (i = 0; i < H264_BUF_CNT; i++) {
struct tw5864_h264_frame *frame = &dev->h264_buf[i];
frame->vlc.addr = dma_alloc_coherent(&dev->pci->dev,
H264_VLC_BUF_SIZE,
&frame->vlc.dma_addr,
GFP_KERNEL | GFP_DMA32);
if (!frame->vlc.addr) {
dev_err(&dev->pci->dev, "dma alloc fail\n");
ret = -ENOMEM;
goto free_dma;
}
frame->mv.addr = dma_alloc_coherent(&dev->pci->dev,
H264_MV_BUF_SIZE,
&frame->mv.dma_addr,
GFP_KERNEL | GFP_DMA32);
if (!frame->mv.addr) {
dev_err(&dev->pci->dev, "dma alloc fail\n");
ret = -ENOMEM;
dma_free_coherent(&dev->pci->dev, H264_VLC_BUF_SIZE,
frame->vlc.addr, frame->vlc.dma_addr);
goto free_dma;
}
last_dma_allocated = i;
}
tw5864_encoder_tables_upload(dev);
tw_indir_writeb(TW5864_INDIR_VD_108_POL, TW5864_INDIR_VD_108_POL_BOTH);
tw_indir_writeb(TW5864_INDIR_CLK0_SEL, 0x00);
tw_indir_writeb(TW5864_INDIR_DDRA_DLL_DQS_SEL0, 0x02);
tw_indir_writeb(TW5864_INDIR_DDRA_DLL_DQS_SEL1, 0x02);
tw_indir_writeb(TW5864_INDIR_DDRA_DLL_CLK90_SEL, 0x02);
tw_indir_writeb(TW5864_INDIR_DDRB_DLL_DQS_SEL0, 0x02);
tw_indir_writeb(TW5864_INDIR_DDRB_DLL_DQS_SEL1, 0x02);
tw_indir_writeb(TW5864_INDIR_DDRB_DLL_CLK90_SEL, 0x02);
tw_indir_writeb(TW5864_INDIR_RESET, 0);
tw_indir_writeb(TW5864_INDIR_RESET, TW5864_INDIR_RESET_VD |
TW5864_INDIR_RESET_DLL | TW5864_INDIR_RESET_MUX_CORE);
msleep(20);
tw_writel(TW5864_FULL_HALF_MODE_SEL, 0);
tw_indir_writeb(TW5864_INDIR_PV_VD_CK_POL,
TW5864_INDIR_PV_VD_CK_POL_VD(0) |
TW5864_INDIR_PV_VD_CK_POL_VD(1) |
TW5864_INDIR_PV_VD_CK_POL_VD(2) |
TW5864_INDIR_PV_VD_CK_POL_VD(3));
spin_lock_irqsave(&dev->slock, flags);
dev->encoder_busy = 0;
dev->h264_buf_r_index = 0;
dev->h264_buf_w_index = 0;
tw_writel(TW5864_VLC_STREAM_BASE_ADDR,
dev->h264_buf[dev->h264_buf_w_index].vlc.dma_addr);
tw_writel(TW5864_MV_STREAM_BASE_ADDR,
dev->h264_buf[dev->h264_buf_w_index].mv.dma_addr);
spin_unlock_irqrestore(&dev->slock, flags);
tw_writel(TW5864_SEN_EN_CH, 0x000f);
tw_writel(TW5864_H264EN_CH_EN, 0x000f);
tw_writel(TW5864_H264EN_BUS0_MAP, 0x00000000);
tw_writel(TW5864_H264EN_BUS1_MAP, 0x00001111);
tw_writel(TW5864_H264EN_BUS2_MAP, 0x00002222);
tw_writel(TW5864_H264EN_BUS3_MAP, 0x00003333);
tw_writel(TW5864_ENC_BUF_PTR_REC1, 0x00ff);
tw_writel(TW5864_PCI_INTTM_SCALE, 0);
tw_writel(TW5864_INTERLACING, TW5864_DI_EN);
tw_writel(TW5864_MASTER_ENB_REG, TW5864_PCI_VLC_INTR_ENB);
tw_writel(TW5864_PCI_INTR_CTL,
TW5864_TIMER_INTR_ENB | TW5864_PCI_MAST_ENB |
TW5864_MVD_VLC_MAST_ENB);
dev->irqmask |= TW5864_INTR_VLC_DONE | TW5864_INTR_TIMER;
tw5864_irqmask_apply(dev);
tasklet_init(&dev->tasklet, tw5864_handle_frame_task,
(unsigned long)dev);
for (i = 0; i < TW5864_INPUTS; i++) {
dev->inputs[i].root = dev;
dev->inputs[i].nr = i;
ret = tw5864_video_input_init(&dev->inputs[i], video_nr[i]);
if (ret)
goto fini_video_inputs;
last_input_nr_registered = i;
}
return 0;
fini_video_inputs:
for (i = last_input_nr_registered; i >= 0; i--)
tw5864_video_input_fini(&dev->inputs[i]);
tasklet_kill(&dev->tasklet);
free_dma:
for (i = last_dma_allocated; i >= 0; i--) {
dma_free_coherent(&dev->pci->dev, H264_VLC_BUF_SIZE,
dev->h264_buf[i].vlc.addr,
dev->h264_buf[i].vlc.dma_addr);
dma_free_coherent(&dev->pci->dev, H264_MV_BUF_SIZE,
dev->h264_buf[i].mv.addr,
dev->h264_buf[i].mv.dma_addr);
}
return ret;
}
static int tw5864_video_input_init(struct tw5864_input *input, int video_nr)
{
struct tw5864_dev *dev = input->root;
int ret;
struct v4l2_ctrl_handler *hdl = &input->hdl;
mutex_init(&input->lock);
spin_lock_init(&input->slock);
INIT_LIST_HEAD(&input->active);
input->vidq.type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
input->vidq.timestamp_flags = V4L2_BUF_FLAG_TIMESTAMP_MONOTONIC;
input->vidq.io_modes = VB2_MMAP | VB2_READ | VB2_DMABUF;
input->vidq.ops = &tw5864_video_qops;
input->vidq.mem_ops = &vb2_dma_contig_memops;
input->vidq.drv_priv = input;
input->vidq.gfp_flags = 0;
input->vidq.buf_struct_size = sizeof(struct tw5864_buf);
input->vidq.lock = &input->lock;
input->vidq.min_buffers_needed = 2;
input->vidq.dev = &input->root->pci->dev;
ret = vb2_queue_init(&input->vidq);
if (ret)
goto free_mutex;
input->vdev = tw5864_video_template;
input->vdev.v4l2_dev = &input->root->v4l2_dev;
input->vdev.lock = &input->lock;
input->vdev.queue = &input->vidq;
video_set_drvdata(&input->vdev, input);
v4l2_ctrl_handler_init(hdl, 6);
v4l2_ctrl_new_std(hdl, &tw5864_ctrl_ops,
V4L2_CID_BRIGHTNESS, -128, 127, 1, 0);
v4l2_ctrl_new_std(hdl, &tw5864_ctrl_ops,
V4L2_CID_CONTRAST, 0, 255, 1, 100);
v4l2_ctrl_new_std(hdl, &tw5864_ctrl_ops,
V4L2_CID_SATURATION, 0, 255, 1, 128);
v4l2_ctrl_new_std(hdl, &tw5864_ctrl_ops, V4L2_CID_HUE, -128, 127, 1, 0);
v4l2_ctrl_new_std(hdl, &tw5864_ctrl_ops, V4L2_CID_MPEG_VIDEO_GOP_SIZE,
1, MAX_GOP_SIZE, 1, GOP_SIZE);
v4l2_ctrl_new_std(hdl, &tw5864_ctrl_ops,
V4L2_CID_MPEG_VIDEO_H264_MIN_QP, 28, 51, 1, QP_VALUE);
v4l2_ctrl_new_std_menu(hdl, &tw5864_ctrl_ops,
V4L2_CID_DETECT_MD_MODE,
V4L2_DETECT_MD_MODE_THRESHOLD_GRID, 0,
V4L2_DETECT_MD_MODE_DISABLED);
v4l2_ctrl_new_std(hdl, &tw5864_ctrl_ops,
V4L2_CID_DETECT_MD_GLOBAL_THRESHOLD,
tw5864_md_thresholds.min, tw5864_md_thresholds.max,
tw5864_md_thresholds.step, tw5864_md_thresholds.def);
input->md_threshold_grid_ctrl =
v4l2_ctrl_new_custom(hdl, &tw5864_md_thresholds, NULL);
if (hdl->error) {
ret = hdl->error;
goto free_v4l2_hdl;
}
input->vdev.ctrl_handler = hdl;
v4l2_ctrl_handler_setup(hdl);
input->qp = QP_VALUE;
input->gop = GOP_SIZE;
input->frame_interval = 1;
ret = video_register_device(&input->vdev, VFL_TYPE_GRABBER, video_nr);
if (ret)
goto free_v4l2_hdl;
dev_info(&input->root->pci->dev, "Registered video device %s\n",
video_device_node_name(&input->vdev));
input->v4l2_std = V4L2_STD_NTSC_M;
input->std = STD_NTSC;
tw_indir_writeb(TW5864_INDIR_VIN_E(video_nr), 0x07);
tw_indir_writeb(TW5864_INDIR_VIN_F(video_nr), 0xff);
return 0;
free_v4l2_hdl:
v4l2_ctrl_handler_free(hdl);
vb2_queue_release(&input->vidq);
free_mutex:
mutex_destroy(&input->lock);
return ret;
}
static void tw5864_video_input_fini(struct tw5864_input *dev)
{
video_unregister_device(&dev->vdev);
v4l2_ctrl_handler_free(&dev->hdl);
vb2_queue_release(&dev->vidq);
}
void tw5864_video_fini(struct tw5864_dev *dev)
{
int i;
tasklet_kill(&dev->tasklet);
for (i = 0; i < TW5864_INPUTS; i++)
tw5864_video_input_fini(&dev->inputs[i]);
for (i = 0; i < H264_BUF_CNT; i++) {
dma_free_coherent(&dev->pci->dev, H264_VLC_BUF_SIZE,
dev->h264_buf[i].vlc.addr,
dev->h264_buf[i].vlc.dma_addr);
dma_free_coherent(&dev->pci->dev, H264_MV_BUF_SIZE,
dev->h264_buf[i].mv.addr,
dev->h264_buf[i].mv.dma_addr);
}
}
void tw5864_prepare_frame_headers(struct tw5864_input *input)
{
struct tw5864_buf *vb = input->vb;
u8 *dst;
size_t dst_space;
unsigned long flags;
if (!vb) {
spin_lock_irqsave(&input->slock, flags);
if (list_empty(&input->active)) {
spin_unlock_irqrestore(&input->slock, flags);
input->vb = NULL;
return;
}
vb = list_first_entry(&input->active, struct tw5864_buf, list);
list_del(&vb->list);
spin_unlock_irqrestore(&input->slock, flags);
}
dst = vb2_plane_vaddr(&vb->vb.vb2_buf, 0);
dst_space = vb2_plane_size(&vb->vb.vb2_buf, 0);
if (WARN_ON_ONCE(dst_space < 128))
return;
if (input->frame_gop_seqno == 0)
tw5864_h264_put_stream_header(&dst, &dst_space, input->qp,
input->width, input->height);
tw5864_h264_put_slice_header(&dst, &dst_space, input->h264_idr_pic_id,
input->frame_gop_seqno,
&input->tail_nb_bits, &input->tail);
input->vb = vb;
input->buf_cur_ptr = dst;
input->buf_cur_space_left = dst_space;
}
static unsigned int tw5864_md_metric_from_mvd(u32 mvd)
{
unsigned int mv_y = (mvd >> 10) & 0x3ff;
unsigned int mv_x = mvd & 0x3ff;
mv_x &= 0x0f;
mv_y &= 0x0f;
return mv_y + mv_x;
}
static int tw5864_is_motion_triggered(struct tw5864_h264_frame *frame)
{
struct tw5864_input *input = frame->input;
u32 *mv = (u32 *)frame->mv.addr;
int i;
int detected = 0;
for (i = 0; i < MD_CELLS; i++) {
const u16 thresh = input->md_threshold_grid_values[i];
const unsigned int metric = tw5864_md_metric_from_mvd(mv[i]);
if (metric > thresh)
detected = 1;
if (detected)
break;
}
return detected;
}
static void tw5864_handle_frame_task(unsigned long data)
{
struct tw5864_dev *dev = (struct tw5864_dev *)data;
unsigned long flags;
int batch_size = H264_BUF_CNT;
spin_lock_irqsave(&dev->slock, flags);
while (dev->h264_buf_r_index != dev->h264_buf_w_index && batch_size--) {
struct tw5864_h264_frame *frame =
&dev->h264_buf[dev->h264_buf_r_index];
spin_unlock_irqrestore(&dev->slock, flags);
dma_sync_single_for_cpu(&dev->pci->dev, frame->vlc.dma_addr,
H264_VLC_BUF_SIZE, DMA_FROM_DEVICE);
dma_sync_single_for_cpu(&dev->pci->dev, frame->mv.dma_addr,
H264_MV_BUF_SIZE, DMA_FROM_DEVICE);
tw5864_handle_frame(frame);
dma_sync_single_for_device(&dev->pci->dev, frame->vlc.dma_addr,
H264_VLC_BUF_SIZE, DMA_FROM_DEVICE);
dma_sync_single_for_device(&dev->pci->dev, frame->mv.dma_addr,
H264_MV_BUF_SIZE, DMA_FROM_DEVICE);
spin_lock_irqsave(&dev->slock, flags);
dev->h264_buf_r_index++;
dev->h264_buf_r_index %= H264_BUF_CNT;
}
spin_unlock_irqrestore(&dev->slock, flags);
}
static u32 tw5864_vlc_checksum(u32 *data, int len)
{
u32 val, count_len = len;
val = *data++;
while (((count_len >> 2) - 1) > 0) {
val ^= *data++;
count_len -= 4;
}
val ^= htonl((len >> 2));
return val;
}
static void tw5864_handle_frame(struct tw5864_h264_frame *frame)
{
#define SKIP_VLCBUF_BYTES 3
struct tw5864_input *input = frame->input;
struct tw5864_dev *dev = input->root;
struct tw5864_buf *vb;
struct vb2_v4l2_buffer *v4l2_buf;
int frame_len = frame->vlc_len - SKIP_VLCBUF_BYTES;
u8 *dst = input->buf_cur_ptr;
u8 tail_mask, vlc_mask = 0;
int i;
u8 vlc_first_byte = ((u8 *)(frame->vlc.addr + SKIP_VLCBUF_BYTES))[0];
unsigned long flags;
int zero_run;
u8 *src;
u8 *src_end;
#ifdef DEBUG
if (frame->checksum !=
tw5864_vlc_checksum((u32 *)frame->vlc.addr, frame_len))
dev_err(&dev->pci->dev,
"Checksum of encoded frame doesn't match!\n");
#endif
spin_lock_irqsave(&input->slock, flags);
vb = input->vb;
input->vb = NULL;
spin_unlock_irqrestore(&input->slock, flags);
v4l2_buf = to_vb2_v4l2_buffer(&vb->vb.vb2_buf);
if (!vb) {
dev_dbg(&dev->pci->dev, "vb is empty, dropping frame\n");
return;
}
if (input->buf_cur_space_left < frame_len * 5 / 4) {
dev_err_once(&dev->pci->dev,
"Left space in vb2 buffer, %d bytes, is less than considered safely enough to put frame of length %d. Dropping this frame.\n",
input->buf_cur_space_left, frame_len);
return;
}
for (i = 0; i < 8 - input->tail_nb_bits; i++)
vlc_mask |= 1 << i;
tail_mask = (~vlc_mask) & 0xff;
dst[0] = (input->tail & tail_mask) | (vlc_first_byte & vlc_mask);
frame_len--;
dst++;
src = frame->vlc.addr + SKIP_VLCBUF_BYTES + 1;
src_end = src + frame_len;
zero_run = 0;
for (; src < src_end; src++) {
if (zero_run < 2) {
if (*src == 0)
++zero_run;
else
zero_run = 0;
} else {
if ((*src & ~0x03) == 0)
*dst++ = 0x03;
zero_run = *src == 0;
}
*dst++ = *src;
}
vb2_set_plane_payload(&vb->vb.vb2_buf, 0,
dst - (u8 *)vb2_plane_vaddr(&vb->vb.vb2_buf, 0));
vb->vb.vb2_buf.timestamp = frame->timestamp;
v4l2_buf->field = V4L2_FIELD_INTERLACED;
v4l2_buf->sequence = frame->seqno;
if (frame->gop_seqno &&
tw5864_is_motion_triggered(frame)) {
struct v4l2_event ev = {
.type = V4L2_EVENT_MOTION_DET,
.u.motion_det = {
.flags = V4L2_EVENT_MD_FL_HAVE_FRAME_SEQ,
.frame_sequence = v4l2_buf->sequence,
},
};
v4l2_event_queue(&input->vdev, &ev);
}
vb2_buffer_done(&vb->vb.vb2_buf, VB2_BUF_STATE_DONE);
}
static v4l2_std_id tw5864_get_v4l2_std(enum tw5864_vid_std std)
{
switch (std) {
case STD_NTSC: return V4L2_STD_NTSC_M;
case STD_PAL: return V4L2_STD_PAL_B;
case STD_SECAM: return V4L2_STD_SECAM_B;
case STD_NTSC443: return V4L2_STD_NTSC_443;
case STD_PAL_M: return V4L2_STD_PAL_M;
case STD_PAL_CN: return V4L2_STD_PAL_Nc;
case STD_PAL_60: return V4L2_STD_PAL_60;
case STD_INVALID: return V4L2_STD_UNKNOWN;
}
return 0;
}
static enum tw5864_vid_std tw5864_from_v4l2_std(v4l2_std_id v4l2_std)
{
if (v4l2_std & V4L2_STD_NTSC_M)
return STD_NTSC;
if (v4l2_std & V4L2_STD_PAL_B)
return STD_PAL;
if (v4l2_std & V4L2_STD_SECAM_B)
return STD_SECAM;
if (v4l2_std & V4L2_STD_NTSC_443)
return STD_NTSC443;
if (v4l2_std & V4L2_STD_PAL_M)
return STD_PAL_M;
if (v4l2_std & V4L2_STD_PAL_Nc)
return STD_PAL_CN;
if (v4l2_std & V4L2_STD_PAL_60)
return STD_PAL_60;
return STD_INVALID;
}
static void tw5864_encoder_tables_upload(struct tw5864_dev *dev)
{
int i;
tw_writel(TW5864_VLC_RD, 0x1);
for (i = 0; i < VLC_LOOKUP_TABLE_LEN; i++) {
tw_writel((TW5864_VLC_STREAM_MEM_START + i * 4),
encoder_vlc_lookup_table[i]);
}
tw_writel(TW5864_VLC_RD, 0x0);
for (i = 0; i < QUANTIZATION_TABLE_LEN; i++) {
tw_writel((TW5864_QUAN_TAB + i * 4),
forward_quantization_table[i]);
}
for (i = 0; i < QUANTIZATION_TABLE_LEN; i++) {
tw_writel((TW5864_QUAN_TAB + i * 4),
inverse_quantization_table[i]);
}
}
