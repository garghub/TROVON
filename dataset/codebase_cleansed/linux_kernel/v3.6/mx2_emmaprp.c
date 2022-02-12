static struct emmaprp_fmt *find_format(struct v4l2_format *f)
{
struct emmaprp_fmt *fmt;
unsigned int k;
for (k = 0; k < NUM_FORMATS; k++) {
fmt = &formats[k];
if (fmt->fourcc == f->fmt.pix.pixelformat)
break;
}
if (k == NUM_FORMATS)
return NULL;
return &formats[k];
}
static struct emmaprp_q_data *get_q_data(struct emmaprp_ctx *ctx,
enum v4l2_buf_type type)
{
switch (type) {
case V4L2_BUF_TYPE_VIDEO_OUTPUT:
return &(ctx->q_data[V4L2_M2M_SRC]);
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
return &(ctx->q_data[V4L2_M2M_DST]);
default:
BUG();
}
return NULL;
}
static void emmaprp_job_abort(void *priv)
{
struct emmaprp_ctx *ctx = priv;
struct emmaprp_dev *pcdev = ctx->dev;
ctx->aborting = 1;
dprintk(pcdev, "Aborting task\n");
v4l2_m2m_job_finish(pcdev->m2m_dev, ctx->m2m_ctx);
}
static void emmaprp_lock(void *priv)
{
struct emmaprp_ctx *ctx = priv;
struct emmaprp_dev *pcdev = ctx->dev;
mutex_lock(&pcdev->dev_mutex);
}
static void emmaprp_unlock(void *priv)
{
struct emmaprp_ctx *ctx = priv;
struct emmaprp_dev *pcdev = ctx->dev;
mutex_unlock(&pcdev->dev_mutex);
}
static inline void emmaprp_dump_regs(struct emmaprp_dev *pcdev)
{
dprintk(pcdev,
"eMMa-PrP Registers:\n"
" SOURCE_Y_PTR = 0x%08X\n"
" SRC_FRAME_SIZE = 0x%08X\n"
" DEST_Y_PTR = 0x%08X\n"
" DEST_CR_PTR = 0x%08X\n"
" DEST_CB_PTR = 0x%08X\n"
" CH2_OUT_IMAGE_SIZE = 0x%08X\n"
" CNTL = 0x%08X\n",
readl(pcdev->base_emma + PRP_SOURCE_Y_PTR),
readl(pcdev->base_emma + PRP_SRC_FRAME_SIZE),
readl(pcdev->base_emma + PRP_DEST_Y_PTR),
readl(pcdev->base_emma + PRP_DEST_CR_PTR),
readl(pcdev->base_emma + PRP_DEST_CB_PTR),
readl(pcdev->base_emma + PRP_CH2_OUT_IMAGE_SIZE),
readl(pcdev->base_emma + PRP_CNTL));
}
static void emmaprp_device_run(void *priv)
{
struct emmaprp_ctx *ctx = priv;
struct emmaprp_q_data *s_q_data, *d_q_data;
struct vb2_buffer *src_buf, *dst_buf;
struct emmaprp_dev *pcdev = ctx->dev;
unsigned int s_width, s_height;
unsigned int d_width, d_height;
unsigned int d_size;
dma_addr_t p_in, p_out;
u32 tmp;
src_buf = v4l2_m2m_next_src_buf(ctx->m2m_ctx);
dst_buf = v4l2_m2m_next_dst_buf(ctx->m2m_ctx);
s_q_data = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_OUTPUT);
s_width = s_q_data->width;
s_height = s_q_data->height;
d_q_data = get_q_data(ctx, V4L2_BUF_TYPE_VIDEO_CAPTURE);
d_width = d_q_data->width;
d_height = d_q_data->height;
d_size = d_width * d_height;
p_in = vb2_dma_contig_plane_dma_addr(src_buf, 0);
p_out = vb2_dma_contig_plane_dma_addr(dst_buf, 0);
if (!p_in || !p_out) {
v4l2_err(&pcdev->v4l2_dev,
"Acquiring kernel pointers to buffers failed\n");
return;
}
writel(p_in, pcdev->base_emma + PRP_SOURCE_Y_PTR);
writel(PRP_SIZE_WIDTH(s_width) | PRP_SIZE_HEIGHT(s_height),
pcdev->base_emma + PRP_SRC_FRAME_SIZE);
writel(p_out, pcdev->base_emma + PRP_DEST_Y_PTR);
writel(p_out + d_size, pcdev->base_emma + PRP_DEST_CB_PTR);
writel(p_out + d_size + (d_size >> 2),
pcdev->base_emma + PRP_DEST_CR_PTR);
writel(PRP_SIZE_WIDTH(d_width) | PRP_SIZE_HEIGHT(d_height),
pcdev->base_emma + PRP_CH2_OUT_IMAGE_SIZE);
tmp = readl(pcdev->base_emma + PRP_INTR_CNTL);
writel(tmp | PRP_INTR_RDERR |
PRP_INTR_CH2WERR |
PRP_INTR_CH2FC,
pcdev->base_emma + PRP_INTR_CNTL);
emmaprp_dump_regs(pcdev);
tmp = readl(pcdev->base_emma + PRP_CNTL);
writel(tmp | PRP_CNTL_CH2_OUT_YUV420 |
PRP_CNTL_DATA_IN_YUV422 |
PRP_CNTL_CH2EN,
pcdev->base_emma + PRP_CNTL);
}
static irqreturn_t emmaprp_irq(int irq_emma, void *data)
{
struct emmaprp_dev *pcdev = data;
struct emmaprp_ctx *curr_ctx;
struct vb2_buffer *src_vb, *dst_vb;
unsigned long flags;
u32 irqst;
irqst = readl(pcdev->base_emma + PRP_INTRSTATUS);
writel(irqst, pcdev->base_emma + PRP_INTRSTATUS);
dprintk(pcdev, "irqst = 0x%08x\n", irqst);
curr_ctx = v4l2_m2m_get_curr_priv(pcdev->m2m_dev);
if (curr_ctx == NULL) {
pr_err("Instance released before the end of transaction\n");
return IRQ_HANDLED;
}
if (!curr_ctx->aborting) {
if ((irqst & PRP_INTR_ST_RDERR) ||
(irqst & PRP_INTR_ST_CH2WERR)) {
pr_err("PrP bus error ocurred, this transfer is probably corrupted\n");
writel(PRP_CNTL_SWRST, pcdev->base_emma + PRP_CNTL);
} else if (irqst & PRP_INTR_ST_CH2B1CI) {
src_vb = v4l2_m2m_src_buf_remove(curr_ctx->m2m_ctx);
dst_vb = v4l2_m2m_dst_buf_remove(curr_ctx->m2m_ctx);
spin_lock_irqsave(&pcdev->irqlock, flags);
v4l2_m2m_buf_done(src_vb, VB2_BUF_STATE_DONE);
v4l2_m2m_buf_done(dst_vb, VB2_BUF_STATE_DONE);
spin_unlock_irqrestore(&pcdev->irqlock, flags);
}
}
v4l2_m2m_job_finish(pcdev->m2m_dev, curr_ctx->m2m_ctx);
return IRQ_HANDLED;
}
static int vidioc_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
strncpy(cap->driver, MEM2MEM_NAME, sizeof(cap->driver) - 1);
strncpy(cap->card, MEM2MEM_NAME, sizeof(cap->card) - 1);
cap->capabilities = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_VIDEO_OUTPUT |
V4L2_CAP_VIDEO_M2M | V4L2_CAP_STREAMING;
return 0;
}
static int enum_fmt(struct v4l2_fmtdesc *f, u32 type)
{
int i, num;
struct emmaprp_fmt *fmt;
num = 0;
for (i = 0; i < NUM_FORMATS; ++i) {
if (formats[i].types & type) {
if (num == f->index)
break;
++num;
}
}
if (i < NUM_FORMATS) {
fmt = &formats[i];
strlcpy(f->description, fmt->name, sizeof(f->description) - 1);
f->pixelformat = fmt->fourcc;
return 0;
}
return -EINVAL;
}
static int vidioc_enum_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
return enum_fmt(f, MEM2MEM_CAPTURE);
}
static int vidioc_enum_fmt_vid_out(struct file *file, void *priv,
struct v4l2_fmtdesc *f)
{
return enum_fmt(f, MEM2MEM_OUTPUT);
}
static int vidioc_g_fmt(struct emmaprp_ctx *ctx, struct v4l2_format *f)
{
struct vb2_queue *vq;
struct emmaprp_q_data *q_data;
vq = v4l2_m2m_get_vq(ctx->m2m_ctx, f->type);
if (!vq)
return -EINVAL;
q_data = get_q_data(ctx, f->type);
f->fmt.pix.width = q_data->width;
f->fmt.pix.height = q_data->height;
f->fmt.pix.field = V4L2_FIELD_NONE;
f->fmt.pix.pixelformat = q_data->fmt->fourcc;
if (f->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420)
f->fmt.pix.bytesperline = q_data->width * 3 / 2;
else
f->fmt.pix.bytesperline = q_data->width * 2;
f->fmt.pix.sizeimage = q_data->sizeimage;
return 0;
}
static int vidioc_g_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
return vidioc_g_fmt(priv, f);
}
static int vidioc_g_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
return vidioc_g_fmt(priv, f);
}
static int vidioc_try_fmt(struct v4l2_format *f)
{
enum v4l2_field field;
if (!find_format(f))
return -EINVAL;
field = f->fmt.pix.field;
if (field == V4L2_FIELD_ANY)
field = V4L2_FIELD_NONE;
else if (V4L2_FIELD_NONE != field)
return -EINVAL;
f->fmt.pix.field = field;
if (f->fmt.pix.pixelformat == V4L2_PIX_FMT_YUV420) {
v4l_bound_align_image(&f->fmt.pix.width, MIN_W, MAX_W,
W_ALIGN_YUV420, &f->fmt.pix.height,
MIN_H, MAX_H, H_ALIGN, S_ALIGN);
f->fmt.pix.bytesperline = f->fmt.pix.width * 3 / 2;
} else {
v4l_bound_align_image(&f->fmt.pix.width, MIN_W, MAX_W,
W_ALIGN_OTHERS, &f->fmt.pix.height,
MIN_H, MAX_H, H_ALIGN, S_ALIGN);
f->fmt.pix.bytesperline = f->fmt.pix.width * 2;
}
f->fmt.pix.sizeimage = f->fmt.pix.height * f->fmt.pix.bytesperline;
return 0;
}
static int vidioc_try_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
struct emmaprp_fmt *fmt;
struct emmaprp_ctx *ctx = priv;
fmt = find_format(f);
if (!fmt || !(fmt->types & MEM2MEM_CAPTURE)) {
v4l2_err(&ctx->dev->v4l2_dev,
"Fourcc format (0x%08x) invalid.\n",
f->fmt.pix.pixelformat);
return -EINVAL;
}
return vidioc_try_fmt(f);
}
static int vidioc_try_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
struct emmaprp_fmt *fmt;
struct emmaprp_ctx *ctx = priv;
fmt = find_format(f);
if (!fmt || !(fmt->types & MEM2MEM_OUTPUT)) {
v4l2_err(&ctx->dev->v4l2_dev,
"Fourcc format (0x%08x) invalid.\n",
f->fmt.pix.pixelformat);
return -EINVAL;
}
return vidioc_try_fmt(f);
}
static int vidioc_s_fmt(struct emmaprp_ctx *ctx, struct v4l2_format *f)
{
struct emmaprp_q_data *q_data;
struct vb2_queue *vq;
int ret;
vq = v4l2_m2m_get_vq(ctx->m2m_ctx, f->type);
if (!vq)
return -EINVAL;
q_data = get_q_data(ctx, f->type);
if (!q_data)
return -EINVAL;
if (vb2_is_busy(vq)) {
v4l2_err(&ctx->dev->v4l2_dev, "%s queue busy\n", __func__);
return -EBUSY;
}
ret = vidioc_try_fmt(f);
if (ret)
return ret;
q_data->fmt = find_format(f);
q_data->width = f->fmt.pix.width;
q_data->height = f->fmt.pix.height;
if (q_data->fmt->fourcc == V4L2_PIX_FMT_YUV420)
q_data->sizeimage = q_data->width * q_data->height * 3 / 2;
else
q_data->sizeimage = q_data->width * q_data->height * 2;
dprintk(ctx->dev,
"Setting format for type %d, wxh: %dx%d, fmt: %d\n",
f->type, q_data->width, q_data->height, q_data->fmt->fourcc);
return 0;
}
static int vidioc_s_fmt_vid_cap(struct file *file, void *priv,
struct v4l2_format *f)
{
int ret;
ret = vidioc_try_fmt_vid_cap(file, priv, f);
if (ret)
return ret;
return vidioc_s_fmt(priv, f);
}
static int vidioc_s_fmt_vid_out(struct file *file, void *priv,
struct v4l2_format *f)
{
int ret;
ret = vidioc_try_fmt_vid_out(file, priv, f);
if (ret)
return ret;
return vidioc_s_fmt(priv, f);
}
static int vidioc_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *reqbufs)
{
struct emmaprp_ctx *ctx = priv;
return v4l2_m2m_reqbufs(file, ctx->m2m_ctx, reqbufs);
}
static int vidioc_querybuf(struct file *file, void *priv,
struct v4l2_buffer *buf)
{
struct emmaprp_ctx *ctx = priv;
return v4l2_m2m_querybuf(file, ctx->m2m_ctx, buf);
}
static int vidioc_qbuf(struct file *file, void *priv, struct v4l2_buffer *buf)
{
struct emmaprp_ctx *ctx = priv;
return v4l2_m2m_qbuf(file, ctx->m2m_ctx, buf);
}
static int vidioc_dqbuf(struct file *file, void *priv, struct v4l2_buffer *buf)
{
struct emmaprp_ctx *ctx = priv;
return v4l2_m2m_dqbuf(file, ctx->m2m_ctx, buf);
}
static int vidioc_streamon(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct emmaprp_ctx *ctx = priv;
return v4l2_m2m_streamon(file, ctx->m2m_ctx, type);
}
static int vidioc_streamoff(struct file *file, void *priv,
enum v4l2_buf_type type)
{
struct emmaprp_ctx *ctx = priv;
return v4l2_m2m_streamoff(file, ctx->m2m_ctx, type);
}
static int emmaprp_queue_setup(struct vb2_queue *vq,
const struct v4l2_format *fmt,
unsigned int *nbuffers, unsigned int *nplanes,
unsigned int sizes[], void *alloc_ctxs[])
{
struct emmaprp_ctx *ctx = vb2_get_drv_priv(vq);
struct emmaprp_q_data *q_data;
unsigned int size, count = *nbuffers;
q_data = get_q_data(ctx, vq->type);
if (q_data->fmt->fourcc == V4L2_PIX_FMT_YUV420)
size = q_data->width * q_data->height * 3 / 2;
else
size = q_data->width * q_data->height * 2;
while (size * count > MEM2MEM_VID_MEM_LIMIT)
(count)--;
*nplanes = 1;
*nbuffers = count;
sizes[0] = size;
alloc_ctxs[0] = ctx->dev->alloc_ctx;
dprintk(ctx->dev, "get %d buffer(s) of size %d each.\n", count, size);
return 0;
}
static int emmaprp_buf_prepare(struct vb2_buffer *vb)
{
struct emmaprp_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
struct emmaprp_q_data *q_data;
dprintk(ctx->dev, "type: %d\n", vb->vb2_queue->type);
q_data = get_q_data(ctx, vb->vb2_queue->type);
if (vb2_plane_size(vb, 0) < q_data->sizeimage) {
dprintk(ctx->dev, "%s data will not fit into plane"
"(%lu < %lu)\n", __func__,
vb2_plane_size(vb, 0),
(long)q_data->sizeimage);
return -EINVAL;
}
vb2_set_plane_payload(vb, 0, q_data->sizeimage);
return 0;
}
static void emmaprp_buf_queue(struct vb2_buffer *vb)
{
struct emmaprp_ctx *ctx = vb2_get_drv_priv(vb->vb2_queue);
v4l2_m2m_buf_queue(ctx->m2m_ctx, vb);
}
static int queue_init(void *priv, struct vb2_queue *src_vq,
struct vb2_queue *dst_vq)
{
struct emmaprp_ctx *ctx = priv;
int ret;
memset(src_vq, 0, sizeof(*src_vq));
src_vq->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
src_vq->io_modes = VB2_MMAP | VB2_USERPTR;
src_vq->drv_priv = ctx;
src_vq->buf_struct_size = sizeof(struct v4l2_m2m_buffer);
src_vq->ops = &emmaprp_qops;
src_vq->mem_ops = &vb2_dma_contig_memops;
ret = vb2_queue_init(src_vq);
if (ret)
return ret;
memset(dst_vq, 0, sizeof(*dst_vq));
dst_vq->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
dst_vq->io_modes = VB2_MMAP | VB2_USERPTR;
dst_vq->drv_priv = ctx;
dst_vq->buf_struct_size = sizeof(struct v4l2_m2m_buffer);
dst_vq->ops = &emmaprp_qops;
dst_vq->mem_ops = &vb2_dma_contig_memops;
return vb2_queue_init(dst_vq);
}
static int emmaprp_open(struct file *file)
{
struct emmaprp_dev *pcdev = video_drvdata(file);
struct emmaprp_ctx *ctx;
ctx = kzalloc(sizeof *ctx, GFP_KERNEL);
if (!ctx)
return -ENOMEM;
file->private_data = ctx;
ctx->dev = pcdev;
ctx->m2m_ctx = v4l2_m2m_ctx_init(pcdev->m2m_dev, ctx, &queue_init);
if (IS_ERR(ctx->m2m_ctx)) {
int ret = PTR_ERR(ctx->m2m_ctx);
kfree(ctx);
return ret;
}
clk_enable(pcdev->clk_emma);
ctx->q_data[V4L2_M2M_SRC].fmt = &formats[1];
ctx->q_data[V4L2_M2M_DST].fmt = &formats[0];
dprintk(pcdev, "Created instance %p, m2m_ctx: %p\n", ctx, ctx->m2m_ctx);
return 0;
}
static int emmaprp_release(struct file *file)
{
struct emmaprp_dev *pcdev = video_drvdata(file);
struct emmaprp_ctx *ctx = file->private_data;
dprintk(pcdev, "Releasing instance %p\n", ctx);
clk_disable(pcdev->clk_emma);
v4l2_m2m_ctx_release(ctx->m2m_ctx);
kfree(ctx);
return 0;
}
static unsigned int emmaprp_poll(struct file *file,
struct poll_table_struct *wait)
{
struct emmaprp_ctx *ctx = file->private_data;
return v4l2_m2m_poll(file, ctx->m2m_ctx, wait);
}
static int emmaprp_mmap(struct file *file, struct vm_area_struct *vma)
{
struct emmaprp_ctx *ctx = file->private_data;
return v4l2_m2m_mmap(file, ctx->m2m_ctx, vma);
}
static int emmaprp_probe(struct platform_device *pdev)
{
struct emmaprp_dev *pcdev;
struct video_device *vfd;
struct resource *res_emma;
int irq_emma;
int ret;
pcdev = kzalloc(sizeof *pcdev, GFP_KERNEL);
if (!pcdev)
return -ENOMEM;
spin_lock_init(&pcdev->irqlock);
pcdev->clk_emma = clk_get(&pdev->dev, NULL);
if (IS_ERR(pcdev->clk_emma)) {
ret = PTR_ERR(pcdev->clk_emma);
goto free_dev;
}
irq_emma = platform_get_irq(pdev, 0);
res_emma = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (irq_emma < 0 || res_emma == NULL) {
dev_err(&pdev->dev, "Missing platform resources data\n");
ret = -ENODEV;
goto free_clk;
}
ret = v4l2_device_register(&pdev->dev, &pcdev->v4l2_dev);
if (ret)
goto free_clk;
mutex_init(&pcdev->dev_mutex);
vfd = video_device_alloc();
if (!vfd) {
v4l2_err(&pcdev->v4l2_dev, "Failed to allocate video device\n");
ret = -ENOMEM;
goto unreg_dev;
}
*vfd = emmaprp_videodev;
set_bit(V4L2_FL_LOCK_ALL_FOPS, &vfd->flags);
vfd->lock = &pcdev->dev_mutex;
video_set_drvdata(vfd, pcdev);
snprintf(vfd->name, sizeof(vfd->name), "%s", emmaprp_videodev.name);
pcdev->vfd = vfd;
v4l2_info(&pcdev->v4l2_dev, EMMAPRP_MODULE_NAME
" Device registered as /dev/video%d\n", vfd->num);
platform_set_drvdata(pdev, pcdev);
if (devm_request_mem_region(&pdev->dev, res_emma->start,
resource_size(res_emma), MEM2MEM_NAME) == NULL)
goto rel_vdev;
pcdev->base_emma = devm_ioremap(&pdev->dev, res_emma->start,
resource_size(res_emma));
if (!pcdev->base_emma)
goto rel_vdev;
pcdev->irq_emma = irq_emma;
pcdev->res_emma = res_emma;
if (devm_request_irq(&pdev->dev, pcdev->irq_emma, emmaprp_irq,
0, MEM2MEM_NAME, pcdev) < 0)
goto rel_vdev;
pcdev->alloc_ctx = vb2_dma_contig_init_ctx(&pdev->dev);
if (IS_ERR(pcdev->alloc_ctx)) {
v4l2_err(&pcdev->v4l2_dev, "Failed to alloc vb2 context\n");
ret = PTR_ERR(pcdev->alloc_ctx);
goto rel_vdev;
}
pcdev->m2m_dev = v4l2_m2m_init(&m2m_ops);
if (IS_ERR(pcdev->m2m_dev)) {
v4l2_err(&pcdev->v4l2_dev, "Failed to init mem2mem device\n");
ret = PTR_ERR(pcdev->m2m_dev);
goto rel_ctx;
}
ret = video_register_device(vfd, VFL_TYPE_GRABBER, 0);
if (ret) {
v4l2_err(&pcdev->v4l2_dev, "Failed to register video device\n");
goto rel_m2m;
}
return 0;
rel_m2m:
v4l2_m2m_release(pcdev->m2m_dev);
rel_ctx:
vb2_dma_contig_cleanup_ctx(pcdev->alloc_ctx);
rel_vdev:
video_device_release(vfd);
unreg_dev:
v4l2_device_unregister(&pcdev->v4l2_dev);
free_clk:
clk_put(pcdev->clk_emma);
free_dev:
kfree(pcdev);
return ret;
}
static int emmaprp_remove(struct platform_device *pdev)
{
struct emmaprp_dev *pcdev = platform_get_drvdata(pdev);
v4l2_info(&pcdev->v4l2_dev, "Removing " EMMAPRP_MODULE_NAME);
video_unregister_device(pcdev->vfd);
v4l2_m2m_release(pcdev->m2m_dev);
vb2_dma_contig_cleanup_ctx(pcdev->alloc_ctx);
v4l2_device_unregister(&pcdev->v4l2_dev);
clk_put(pcdev->clk_emma);
kfree(pcdev);
return 0;
}
static void __exit emmaprp_exit(void)
{
platform_driver_unregister(&emmaprp_pdrv);
}
static int __init emmaprp_init(void)
{
return platform_driver_register(&emmaprp_pdrv);
}
