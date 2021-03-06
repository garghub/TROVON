static int timblogiw_bytes_per_line(const struct timblogiw_tvnorm *norm)
{
return norm->width * 2;
}
static int timblogiw_frame_size(const struct timblogiw_tvnorm *norm)
{
return norm->height * timblogiw_bytes_per_line(norm);
}
static const struct timblogiw_tvnorm *timblogiw_get_norm(const v4l2_std_id std)
{
int i;
for (i = 0; i < ARRAY_SIZE(timblogiw_tvnorms); i++)
if (timblogiw_tvnorms[i].std & std)
return timblogiw_tvnorms + i;
return timblogiw_tvnorms;
}
static void timblogiw_dma_cb(void *data)
{
struct timblogiw_buffer *buf = data;
struct timblogiw_fh *fh = buf->fh;
struct videobuf_buffer *vb = &buf->vb;
spin_lock(&fh->queue_lock);
buf->cookie = -1;
fh->frame_count++;
if (vb->state != VIDEOBUF_ERROR) {
list_del(&vb->queue);
v4l2_get_timestamp(&vb->ts);
vb->field_count = fh->frame_count * 2;
vb->state = VIDEOBUF_DONE;
wake_up(&vb->done);
}
if (!list_empty(&fh->capture)) {
vb = list_entry(fh->capture.next, struct videobuf_buffer,
queue);
vb->state = VIDEOBUF_ACTIVE;
}
spin_unlock(&fh->queue_lock);
}
static bool timblogiw_dma_filter_fn(struct dma_chan *chan, void *filter_param)
{
return chan->chan_id == (uintptr_t)filter_param;
}
static int timblogiw_g_fmt(struct file *file, void *priv,
struct v4l2_format *format)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw *lw = video_get_drvdata(vdev);
struct timblogiw_fh *fh = priv;
dev_dbg(&vdev->dev, "%s entry\n", __func__);
if (format->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
mutex_lock(&lw->lock);
format->fmt.pix.width = fh->cur_norm->width;
format->fmt.pix.height = fh->cur_norm->height;
format->fmt.pix.pixelformat = V4L2_PIX_FMT_UYVY;
format->fmt.pix.bytesperline = timblogiw_bytes_per_line(fh->cur_norm);
format->fmt.pix.sizeimage = timblogiw_frame_size(fh->cur_norm);
format->fmt.pix.field = V4L2_FIELD_NONE;
mutex_unlock(&lw->lock);
return 0;
}
static int timblogiw_try_fmt(struct file *file, void *priv,
struct v4l2_format *format)
{
struct video_device *vdev = video_devdata(file);
struct v4l2_pix_format *pix = &format->fmt.pix;
dev_dbg(&vdev->dev,
"%s - width=%d, height=%d, pixelformat=%d, field=%d\n"
"bytes per line %d, size image: %d, colorspace: %d\n",
__func__,
pix->width, pix->height, pix->pixelformat, pix->field,
pix->bytesperline, pix->sizeimage, pix->colorspace);
if (format->type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
if (pix->field != V4L2_FIELD_NONE)
return -EINVAL;
if (pix->pixelformat != V4L2_PIX_FMT_UYVY)
return -EINVAL;
return 0;
}
static int timblogiw_s_fmt(struct file *file, void *priv,
struct v4l2_format *format)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw *lw = video_get_drvdata(vdev);
struct timblogiw_fh *fh = priv;
struct v4l2_pix_format *pix = &format->fmt.pix;
int err;
mutex_lock(&lw->lock);
err = timblogiw_try_fmt(file, priv, format);
if (err)
goto out;
if (videobuf_queue_is_busy(&fh->vb_vidq)) {
dev_err(&vdev->dev, "%s queue busy\n", __func__);
err = -EBUSY;
goto out;
}
pix->width = fh->cur_norm->width;
pix->height = fh->cur_norm->height;
out:
mutex_unlock(&lw->lock);
return err;
}
static int timblogiw_querycap(struct file *file, void *priv,
struct v4l2_capability *cap)
{
struct video_device *vdev = video_devdata(file);
dev_dbg(&vdev->dev, "%s: Entry\n", __func__);
memset(cap, 0, sizeof(*cap));
strncpy(cap->card, TIMBLOGIWIN_NAME, sizeof(cap->card)-1);
strncpy(cap->driver, DRIVER_NAME, sizeof(cap->driver) - 1);
strlcpy(cap->bus_info, vdev->name, sizeof(cap->bus_info));
cap->version = TIMBLOGIW_VERSION_CODE;
cap->capabilities = V4L2_CAP_VIDEO_CAPTURE | V4L2_CAP_STREAMING |
V4L2_CAP_READWRITE;
return 0;
}
static int timblogiw_enum_fmt(struct file *file, void *priv,
struct v4l2_fmtdesc *fmt)
{
struct video_device *vdev = video_devdata(file);
dev_dbg(&vdev->dev, "%s, index: %d\n", __func__, fmt->index);
if (fmt->index != 0)
return -EINVAL;
memset(fmt, 0, sizeof(*fmt));
fmt->index = 0;
fmt->type = V4L2_BUF_TYPE_VIDEO_CAPTURE;
strncpy(fmt->description, "4:2:2, packed, YUYV",
sizeof(fmt->description)-1);
fmt->pixelformat = V4L2_PIX_FMT_UYVY;
return 0;
}
static int timblogiw_g_parm(struct file *file, void *priv,
struct v4l2_streamparm *sp)
{
struct timblogiw_fh *fh = priv;
struct v4l2_captureparm *cp = &sp->parm.capture;
cp->capability = V4L2_CAP_TIMEPERFRAME;
cp->timeperframe.numerator = 1;
cp->timeperframe.denominator = fh->cur_norm->fps;
return 0;
}
static int timblogiw_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *rb)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw_fh *fh = priv;
dev_dbg(&vdev->dev, "%s: entry\n", __func__);
return videobuf_reqbufs(&fh->vb_vidq, rb);
}
static int timblogiw_querybuf(struct file *file, void *priv,
struct v4l2_buffer *b)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw_fh *fh = priv;
dev_dbg(&vdev->dev, "%s: entry\n", __func__);
return videobuf_querybuf(&fh->vb_vidq, b);
}
static int timblogiw_qbuf(struct file *file, void *priv, struct v4l2_buffer *b)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw_fh *fh = priv;
dev_dbg(&vdev->dev, "%s: entry\n", __func__);
return videobuf_qbuf(&fh->vb_vidq, b);
}
static int timblogiw_dqbuf(struct file *file, void *priv,
struct v4l2_buffer *b)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw_fh *fh = priv;
dev_dbg(&vdev->dev, "%s: entry\n", __func__);
return videobuf_dqbuf(&fh->vb_vidq, b, file->f_flags & O_NONBLOCK);
}
static int timblogiw_g_std(struct file *file, void *priv, v4l2_std_id *std)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw_fh *fh = priv;
dev_dbg(&vdev->dev, "%s: entry\n", __func__);
*std = fh->cur_norm->std;
return 0;
}
static int timblogiw_s_std(struct file *file, void *priv, v4l2_std_id *std)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw *lw = video_get_drvdata(vdev);
struct timblogiw_fh *fh = priv;
int err = 0;
dev_dbg(&vdev->dev, "%s: entry\n", __func__);
mutex_lock(&lw->lock);
if (TIMBLOGIW_HAS_DECODER(lw))
err = v4l2_subdev_call(lw->sd_enc, core, s_std, *std);
if (!err)
fh->cur_norm = timblogiw_get_norm(*std);
mutex_unlock(&lw->lock);
return err;
}
static int timblogiw_enuminput(struct file *file, void *priv,
struct v4l2_input *inp)
{
struct video_device *vdev = video_devdata(file);
int i;
dev_dbg(&vdev->dev, "%s: Entry\n", __func__);
if (inp->index != 0)
return -EINVAL;
inp->index = 0;
strncpy(inp->name, "Timb input 1", sizeof(inp->name) - 1);
inp->type = V4L2_INPUT_TYPE_CAMERA;
inp->std = 0;
for (i = 0; i < ARRAY_SIZE(timblogiw_tvnorms); i++)
inp->std |= timblogiw_tvnorms[i].std;
return 0;
}
static int timblogiw_g_input(struct file *file, void *priv,
unsigned int *input)
{
struct video_device *vdev = video_devdata(file);
dev_dbg(&vdev->dev, "%s: Entry\n", __func__);
*input = 0;
return 0;
}
static int timblogiw_s_input(struct file *file, void *priv, unsigned int input)
{
struct video_device *vdev = video_devdata(file);
dev_dbg(&vdev->dev, "%s: Entry\n", __func__);
if (input != 0)
return -EINVAL;
return 0;
}
static int timblogiw_streamon(struct file *file, void *priv, unsigned int type)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw_fh *fh = priv;
dev_dbg(&vdev->dev, "%s: entry\n", __func__);
if (type != V4L2_BUF_TYPE_VIDEO_CAPTURE) {
dev_dbg(&vdev->dev, "%s - No capture device\n", __func__);
return -EINVAL;
}
fh->frame_count = 0;
return videobuf_streamon(&fh->vb_vidq);
}
static int timblogiw_streamoff(struct file *file, void *priv,
unsigned int type)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw_fh *fh = priv;
dev_dbg(&vdev->dev, "%s entry\n", __func__);
if (type != V4L2_BUF_TYPE_VIDEO_CAPTURE)
return -EINVAL;
return videobuf_streamoff(&fh->vb_vidq);
}
static int timblogiw_querystd(struct file *file, void *priv, v4l2_std_id *std)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw *lw = video_get_drvdata(vdev);
struct timblogiw_fh *fh = priv;
dev_dbg(&vdev->dev, "%s entry\n", __func__);
if (TIMBLOGIW_HAS_DECODER(lw))
return v4l2_subdev_call(lw->sd_enc, video, querystd, std);
else {
*std = fh->cur_norm->std;
return 0;
}
}
static int timblogiw_enum_framesizes(struct file *file, void *priv,
struct v4l2_frmsizeenum *fsize)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw_fh *fh = priv;
dev_dbg(&vdev->dev, "%s - index: %d, format: %d\n", __func__,
fsize->index, fsize->pixel_format);
if ((fsize->index != 0) ||
(fsize->pixel_format != V4L2_PIX_FMT_UYVY))
return -EINVAL;
fsize->type = V4L2_FRMSIZE_TYPE_DISCRETE;
fsize->discrete.width = fh->cur_norm->width;
fsize->discrete.height = fh->cur_norm->height;
return 0;
}
static int buffer_setup(struct videobuf_queue *vq, unsigned int *count,
unsigned int *size)
{
struct timblogiw_fh *fh = vq->priv_data;
*size = timblogiw_frame_size(fh->cur_norm);
if (!*count)
*count = 32;
while (*size * *count > TIMBLOGIW_MAX_VIDEO_MEM * 1024 * 1024)
(*count)--;
return 0;
}
static int buffer_prepare(struct videobuf_queue *vq, struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct timblogiw_fh *fh = vq->priv_data;
struct timblogiw_buffer *buf = container_of(vb, struct timblogiw_buffer,
vb);
unsigned int data_size = timblogiw_frame_size(fh->cur_norm);
int err = 0;
if (vb->baddr && vb->bsize < data_size)
return -ENOMEM;
vb->size = data_size;
vb->width = fh->cur_norm->width;
vb->height = fh->cur_norm->height;
vb->field = field;
if (vb->state == VIDEOBUF_NEEDS_INIT) {
int i;
unsigned int size;
unsigned int bytes_per_desc = TIMBLOGIW_LINES_PER_DESC *
timblogiw_bytes_per_line(fh->cur_norm);
dma_addr_t addr;
sg_init_table(buf->sg, ARRAY_SIZE(buf->sg));
err = videobuf_iolock(vq, vb, NULL);
if (err)
goto err;
addr = videobuf_to_dma_contig(vb);
for (i = 0, size = 0; size < data_size; i++) {
sg_dma_address(buf->sg + i) = addr + size;
size += bytes_per_desc;
sg_dma_len(buf->sg + i) = (size > data_size) ?
(bytes_per_desc - (size - data_size)) :
bytes_per_desc;
}
vb->state = VIDEOBUF_PREPARED;
buf->cookie = -1;
buf->fh = fh;
}
return 0;
err:
videobuf_dma_contig_free(vq, vb);
vb->state = VIDEOBUF_NEEDS_INIT;
return err;
}
static void buffer_queue(struct videobuf_queue *vq, struct videobuf_buffer *vb)
{
struct timblogiw_fh *fh = vq->priv_data;
struct timblogiw_buffer *buf = container_of(vb, struct timblogiw_buffer,
vb);
struct dma_async_tx_descriptor *desc;
int sg_elems;
int bytes_per_desc = TIMBLOGIW_LINES_PER_DESC *
timblogiw_bytes_per_line(fh->cur_norm);
sg_elems = timblogiw_frame_size(fh->cur_norm) / bytes_per_desc;
sg_elems +=
(timblogiw_frame_size(fh->cur_norm) % bytes_per_desc) ? 1 : 0;
if (list_empty(&fh->capture))
vb->state = VIDEOBUF_ACTIVE;
else
vb->state = VIDEOBUF_QUEUED;
list_add_tail(&vb->queue, &fh->capture);
spin_unlock_irq(&fh->queue_lock);
desc = dmaengine_prep_slave_sg(fh->chan,
buf->sg, sg_elems, DMA_DEV_TO_MEM,
DMA_PREP_INTERRUPT | DMA_COMPL_SKIP_SRC_UNMAP);
if (!desc) {
spin_lock_irq(&fh->queue_lock);
list_del_init(&vb->queue);
vb->state = VIDEOBUF_PREPARED;
return;
}
desc->callback_param = buf;
desc->callback = timblogiw_dma_cb;
buf->cookie = desc->tx_submit(desc);
spin_lock_irq(&fh->queue_lock);
}
static void buffer_release(struct videobuf_queue *vq,
struct videobuf_buffer *vb)
{
struct timblogiw_fh *fh = vq->priv_data;
struct timblogiw_buffer *buf = container_of(vb, struct timblogiw_buffer,
vb);
videobuf_waiton(vq, vb, 0, 0);
if (buf->cookie >= 0)
dma_sync_wait(fh->chan, buf->cookie);
videobuf_dma_contig_free(vq, vb);
vb->state = VIDEOBUF_NEEDS_INIT;
}
static int timblogiw_open(struct file *file)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw *lw = video_get_drvdata(vdev);
struct timblogiw_fh *fh;
v4l2_std_id std;
dma_cap_mask_t mask;
int err = 0;
dev_dbg(&vdev->dev, "%s: entry\n", __func__);
mutex_lock(&lw->lock);
if (lw->opened) {
err = -EBUSY;
goto out;
}
if (TIMBLOGIW_HAS_DECODER(lw) && !lw->sd_enc) {
struct i2c_adapter *adapt;
adapt = i2c_get_adapter(lw->pdata.i2c_adapter);
if (!adapt) {
dev_err(&vdev->dev, "No I2C bus #%d\n",
lw->pdata.i2c_adapter);
err = -ENODEV;
goto out;
}
lw->sd_enc = v4l2_i2c_new_subdev_board(&lw->v4l2_dev, adapt,
lw->pdata.encoder.info, NULL);
i2c_put_adapter(adapt);
if (!lw->sd_enc) {
dev_err(&vdev->dev, "Failed to get encoder: %s\n",
lw->pdata.encoder.module_name);
err = -ENODEV;
goto out;
}
}
fh = kzalloc(sizeof(*fh), GFP_KERNEL);
if (!fh) {
err = -ENOMEM;
goto out;
}
fh->cur_norm = timblogiw_tvnorms;
timblogiw_querystd(file, fh, &std);
fh->cur_norm = timblogiw_get_norm(std);
INIT_LIST_HEAD(&fh->capture);
spin_lock_init(&fh->queue_lock);
dma_cap_zero(mask);
dma_cap_set(DMA_SLAVE, mask);
dma_cap_set(DMA_PRIVATE, mask);
fh->chan = dma_request_channel(mask, timblogiw_dma_filter_fn,
(void *)(uintptr_t)lw->pdata.dma_channel);
if (!fh->chan) {
dev_err(&vdev->dev, "Failed to get DMA channel\n");
kfree(fh);
err = -ENODEV;
goto out;
}
file->private_data = fh;
videobuf_queue_dma_contig_init(&fh->vb_vidq,
&timblogiw_video_qops, lw->dev, &fh->queue_lock,
V4L2_BUF_TYPE_VIDEO_CAPTURE, V4L2_FIELD_NONE,
sizeof(struct timblogiw_buffer), fh, NULL);
lw->opened = true;
out:
mutex_unlock(&lw->lock);
return err;
}
static int timblogiw_close(struct file *file)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw *lw = video_get_drvdata(vdev);
struct timblogiw_fh *fh = file->private_data;
dev_dbg(&vdev->dev, "%s: Entry\n", __func__);
videobuf_stop(&fh->vb_vidq);
videobuf_mmap_free(&fh->vb_vidq);
dma_release_channel(fh->chan);
kfree(fh);
mutex_lock(&lw->lock);
lw->opened = false;
mutex_unlock(&lw->lock);
return 0;
}
static ssize_t timblogiw_read(struct file *file, char __user *data,
size_t count, loff_t *ppos)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw_fh *fh = file->private_data;
dev_dbg(&vdev->dev, "%s: entry\n", __func__);
return videobuf_read_stream(&fh->vb_vidq, data, count, ppos, 0,
file->f_flags & O_NONBLOCK);
}
static unsigned int timblogiw_poll(struct file *file,
struct poll_table_struct *wait)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw_fh *fh = file->private_data;
dev_dbg(&vdev->dev, "%s: entry\n", __func__);
return videobuf_poll_stream(file, &fh->vb_vidq, wait);
}
static int timblogiw_mmap(struct file *file, struct vm_area_struct *vma)
{
struct video_device *vdev = video_devdata(file);
struct timblogiw_fh *fh = file->private_data;
dev_dbg(&vdev->dev, "%s: entry\n", __func__);
return videobuf_mmap_mapper(&fh->vb_vidq, vma);
}
static int timblogiw_probe(struct platform_device *pdev)
{
int err;
struct timblogiw *lw = NULL;
struct timb_video_platform_data *pdata = pdev->dev.platform_data;
if (!pdata) {
dev_err(&pdev->dev, "No platform data\n");
err = -EINVAL;
goto err;
}
if (!pdata->encoder.module_name)
dev_info(&pdev->dev, "Running without decoder\n");
lw = kzalloc(sizeof(*lw), GFP_KERNEL);
if (!lw) {
err = -ENOMEM;
goto err;
}
if (pdev->dev.parent)
lw->dev = pdev->dev.parent;
else
lw->dev = &pdev->dev;
memcpy(&lw->pdata, pdata, sizeof(lw->pdata));
mutex_init(&lw->lock);
lw->video_dev = timblogiw_template;
strlcpy(lw->v4l2_dev.name, DRIVER_NAME, sizeof(lw->v4l2_dev.name));
err = v4l2_device_register(NULL, &lw->v4l2_dev);
if (err)
goto err_register;
lw->video_dev.v4l2_dev = &lw->v4l2_dev;
platform_set_drvdata(pdev, lw);
video_set_drvdata(&lw->video_dev, lw);
err = video_register_device(&lw->video_dev, VFL_TYPE_GRABBER, 0);
if (err) {
dev_err(&pdev->dev, "Error reg video: %d\n", err);
goto err_request;
}
return 0;
err_request:
platform_set_drvdata(pdev, NULL);
v4l2_device_unregister(&lw->v4l2_dev);
err_register:
kfree(lw);
err:
dev_err(&pdev->dev, "Failed to register: %d\n", err);
return err;
}
static int timblogiw_remove(struct platform_device *pdev)
{
struct timblogiw *lw = platform_get_drvdata(pdev);
video_unregister_device(&lw->video_dev);
v4l2_device_unregister(&lw->v4l2_dev);
kfree(lw);
platform_set_drvdata(pdev, NULL);
return 0;
}
