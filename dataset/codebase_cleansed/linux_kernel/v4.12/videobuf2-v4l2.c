static int __verify_planes_array(struct vb2_buffer *vb, const struct v4l2_buffer *b)
{
if (!V4L2_TYPE_IS_MULTIPLANAR(b->type))
return 0;
if (b->m.planes == NULL) {
dprintk(1, "multi-planar buffer passed but planes array not provided\n");
return -EINVAL;
}
if (b->length < vb->num_planes || b->length > VB2_MAX_PLANES) {
dprintk(1, "incorrect planes array length, expected %d, got %d\n",
vb->num_planes, b->length);
return -EINVAL;
}
return 0;
}
static int __verify_planes_array_core(struct vb2_buffer *vb, const void *pb)
{
return __verify_planes_array(vb, pb);
}
static int __verify_length(struct vb2_buffer *vb, const struct v4l2_buffer *b)
{
unsigned int length;
unsigned int bytesused;
unsigned int plane;
if (!V4L2_TYPE_IS_OUTPUT(b->type))
return 0;
if (V4L2_TYPE_IS_MULTIPLANAR(b->type)) {
for (plane = 0; plane < vb->num_planes; ++plane) {
length = (b->memory == VB2_MEMORY_USERPTR ||
b->memory == VB2_MEMORY_DMABUF)
? b->m.planes[plane].length
: vb->planes[plane].length;
bytesused = b->m.planes[plane].bytesused
? b->m.planes[plane].bytesused : length;
if (b->m.planes[plane].bytesused > length)
return -EINVAL;
if (b->m.planes[plane].data_offset > 0 &&
b->m.planes[plane].data_offset >= bytesused)
return -EINVAL;
}
} else {
length = (b->memory == VB2_MEMORY_USERPTR)
? b->length : vb->planes[0].length;
if (b->bytesused > length)
return -EINVAL;
}
return 0;
}
static void __copy_timestamp(struct vb2_buffer *vb, const void *pb)
{
const struct v4l2_buffer *b = pb;
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct vb2_queue *q = vb->vb2_queue;
if (q->is_output) {
if (q->copy_timestamp)
vb->timestamp = timeval_to_ns(&b->timestamp);
vbuf->flags |= b->flags & V4L2_BUF_FLAG_TIMECODE;
if (b->flags & V4L2_BUF_FLAG_TIMECODE)
vbuf->timecode = b->timecode;
}
}
static void vb2_warn_zero_bytesused(struct vb2_buffer *vb)
{
static bool check_once;
if (check_once)
return;
check_once = true;
WARN_ON(1);
pr_warn("use of bytesused == 0 is deprecated and will be removed in the future,\n");
if (vb->vb2_queue->allow_zero_bytesused)
pr_warn("use VIDIOC_DECODER_CMD(V4L2_DEC_CMD_STOP) instead.\n");
else
pr_warn("use the actual size instead.\n");
}
static int vb2_queue_or_prepare_buf(struct vb2_queue *q, struct v4l2_buffer *b,
const char *opname)
{
if (b->type != q->type) {
dprintk(1, "%s: invalid buffer type\n", opname);
return -EINVAL;
}
if (b->index >= q->num_buffers) {
dprintk(1, "%s: buffer index out of range\n", opname);
return -EINVAL;
}
if (q->bufs[b->index] == NULL) {
dprintk(1, "%s: buffer is NULL\n", opname);
return -EINVAL;
}
if (b->memory != q->memory) {
dprintk(1, "%s: invalid memory type\n", opname);
return -EINVAL;
}
return __verify_planes_array(q->bufs[b->index], b);
}
static void __fill_v4l2_buffer(struct vb2_buffer *vb, void *pb)
{
struct v4l2_buffer *b = pb;
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct vb2_queue *q = vb->vb2_queue;
unsigned int plane;
b->index = vb->index;
b->type = vb->type;
b->memory = vb->memory;
b->bytesused = 0;
b->flags = vbuf->flags;
b->field = vbuf->field;
b->timestamp = ns_to_timeval(vb->timestamp);
b->timecode = vbuf->timecode;
b->sequence = vbuf->sequence;
b->reserved2 = 0;
b->reserved = 0;
if (q->is_multiplanar) {
b->length = vb->num_planes;
for (plane = 0; plane < vb->num_planes; ++plane) {
struct v4l2_plane *pdst = &b->m.planes[plane];
struct vb2_plane *psrc = &vb->planes[plane];
pdst->bytesused = psrc->bytesused;
pdst->length = psrc->length;
if (q->memory == VB2_MEMORY_MMAP)
pdst->m.mem_offset = psrc->m.offset;
else if (q->memory == VB2_MEMORY_USERPTR)
pdst->m.userptr = psrc->m.userptr;
else if (q->memory == VB2_MEMORY_DMABUF)
pdst->m.fd = psrc->m.fd;
pdst->data_offset = psrc->data_offset;
memset(pdst->reserved, 0, sizeof(pdst->reserved));
}
} else {
b->length = vb->planes[0].length;
b->bytesused = vb->planes[0].bytesused;
if (q->memory == VB2_MEMORY_MMAP)
b->m.offset = vb->planes[0].m.offset;
else if (q->memory == VB2_MEMORY_USERPTR)
b->m.userptr = vb->planes[0].m.userptr;
else if (q->memory == VB2_MEMORY_DMABUF)
b->m.fd = vb->planes[0].m.fd;
}
b->flags &= ~V4L2_BUFFER_MASK_FLAGS;
b->flags |= q->timestamp_flags & V4L2_BUF_FLAG_TIMESTAMP_MASK;
if (!q->copy_timestamp) {
b->flags &= ~V4L2_BUF_FLAG_TSTAMP_SRC_MASK;
b->flags |= q->timestamp_flags & V4L2_BUF_FLAG_TSTAMP_SRC_MASK;
}
switch (vb->state) {
case VB2_BUF_STATE_QUEUED:
case VB2_BUF_STATE_ACTIVE:
b->flags |= V4L2_BUF_FLAG_QUEUED;
break;
case VB2_BUF_STATE_ERROR:
b->flags |= V4L2_BUF_FLAG_ERROR;
case VB2_BUF_STATE_DONE:
b->flags |= V4L2_BUF_FLAG_DONE;
break;
case VB2_BUF_STATE_PREPARED:
b->flags |= V4L2_BUF_FLAG_PREPARED;
break;
case VB2_BUF_STATE_PREPARING:
case VB2_BUF_STATE_DEQUEUED:
case VB2_BUF_STATE_REQUEUEING:
break;
}
if (vb2_buffer_in_use(q, vb))
b->flags |= V4L2_BUF_FLAG_MAPPED;
if (!q->is_output &&
b->flags & V4L2_BUF_FLAG_DONE &&
b->flags & V4L2_BUF_FLAG_LAST)
q->last_buffer_dequeued = true;
}
static int __fill_vb2_buffer(struct vb2_buffer *vb,
const void *pb, struct vb2_plane *planes)
{
struct vb2_queue *q = vb->vb2_queue;
const struct v4l2_buffer *b = pb;
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
unsigned int plane;
int ret;
ret = __verify_length(vb, b);
if (ret < 0) {
dprintk(1, "plane parameters verification failed: %d\n", ret);
return ret;
}
if (b->field == V4L2_FIELD_ALTERNATE && q->is_output) {
dprintk(1, "the field is incorrectly set to ALTERNATE for an output buffer\n");
return -EINVAL;
}
vb->timestamp = 0;
vbuf->sequence = 0;
if (V4L2_TYPE_IS_MULTIPLANAR(b->type)) {
if (b->memory == VB2_MEMORY_USERPTR) {
for (plane = 0; plane < vb->num_planes; ++plane) {
planes[plane].m.userptr =
b->m.planes[plane].m.userptr;
planes[plane].length =
b->m.planes[plane].length;
}
}
if (b->memory == VB2_MEMORY_DMABUF) {
for (plane = 0; plane < vb->num_planes; ++plane) {
planes[plane].m.fd =
b->m.planes[plane].m.fd;
planes[plane].length =
b->m.planes[plane].length;
}
}
if (V4L2_TYPE_IS_OUTPUT(b->type)) {
for (plane = 0; plane < vb->num_planes; ++plane) {
struct vb2_plane *pdst = &planes[plane];
struct v4l2_plane *psrc = &b->m.planes[plane];
if (psrc->bytesused == 0)
vb2_warn_zero_bytesused(vb);
if (vb->vb2_queue->allow_zero_bytesused)
pdst->bytesused = psrc->bytesused;
else
pdst->bytesused = psrc->bytesused ?
psrc->bytesused : pdst->length;
pdst->data_offset = psrc->data_offset;
}
}
} else {
if (b->memory == VB2_MEMORY_USERPTR) {
planes[0].m.userptr = b->m.userptr;
planes[0].length = b->length;
}
if (b->memory == VB2_MEMORY_DMABUF) {
planes[0].m.fd = b->m.fd;
planes[0].length = b->length;
}
if (V4L2_TYPE_IS_OUTPUT(b->type)) {
if (b->bytesused == 0)
vb2_warn_zero_bytesused(vb);
if (vb->vb2_queue->allow_zero_bytesused)
planes[0].bytesused = b->bytesused;
else
planes[0].bytesused = b->bytesused ?
b->bytesused : planes[0].length;
} else
planes[0].bytesused = 0;
}
vbuf->flags = b->flags & ~V4L2_BUFFER_MASK_FLAGS;
if (!vb->vb2_queue->copy_timestamp || !V4L2_TYPE_IS_OUTPUT(b->type)) {
vbuf->flags &= ~V4L2_BUF_FLAG_TSTAMP_SRC_MASK;
}
if (V4L2_TYPE_IS_OUTPUT(b->type)) {
vbuf->flags &= ~V4L2_BUF_FLAG_TIMECODE;
vbuf->field = b->field;
} else {
vbuf->flags &= ~V4L2_BUFFER_OUT_FLAGS;
}
return 0;
}
int vb2_querybuf(struct vb2_queue *q, struct v4l2_buffer *b)
{
struct vb2_buffer *vb;
int ret;
if (b->type != q->type) {
dprintk(1, "wrong buffer type\n");
return -EINVAL;
}
if (b->index >= q->num_buffers) {
dprintk(1, "buffer index out of range\n");
return -EINVAL;
}
vb = q->bufs[b->index];
ret = __verify_planes_array(vb, b);
if (!ret)
vb2_core_querybuf(q, b->index, b);
return ret;
}
int vb2_reqbufs(struct vb2_queue *q, struct v4l2_requestbuffers *req)
{
int ret = vb2_verify_memory_type(q, req->memory, req->type);
return ret ? ret : vb2_core_reqbufs(q, req->memory, &req->count);
}
int vb2_prepare_buf(struct vb2_queue *q, struct v4l2_buffer *b)
{
int ret;
if (vb2_fileio_is_active(q)) {
dprintk(1, "file io in progress\n");
return -EBUSY;
}
ret = vb2_queue_or_prepare_buf(q, b, "prepare_buf");
return ret ? ret : vb2_core_prepare_buf(q, b->index, b);
}
int vb2_create_bufs(struct vb2_queue *q, struct v4l2_create_buffers *create)
{
unsigned requested_planes = 1;
unsigned requested_sizes[VIDEO_MAX_PLANES];
struct v4l2_format *f = &create->format;
int ret = vb2_verify_memory_type(q, create->memory, f->type);
unsigned i;
create->index = q->num_buffers;
if (create->count == 0)
return ret != -EBUSY ? ret : 0;
switch (f->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE:
case V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE:
requested_planes = f->fmt.pix_mp.num_planes;
if (requested_planes == 0 ||
requested_planes > VIDEO_MAX_PLANES)
return -EINVAL;
for (i = 0; i < requested_planes; i++)
requested_sizes[i] =
f->fmt.pix_mp.plane_fmt[i].sizeimage;
break;
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
case V4L2_BUF_TYPE_VIDEO_OUTPUT:
requested_sizes[0] = f->fmt.pix.sizeimage;
break;
case V4L2_BUF_TYPE_VBI_CAPTURE:
case V4L2_BUF_TYPE_VBI_OUTPUT:
requested_sizes[0] = f->fmt.vbi.samples_per_line *
(f->fmt.vbi.count[0] + f->fmt.vbi.count[1]);
break;
case V4L2_BUF_TYPE_SLICED_VBI_CAPTURE:
case V4L2_BUF_TYPE_SLICED_VBI_OUTPUT:
requested_sizes[0] = f->fmt.sliced.io_size;
break;
case V4L2_BUF_TYPE_SDR_CAPTURE:
case V4L2_BUF_TYPE_SDR_OUTPUT:
requested_sizes[0] = f->fmt.sdr.buffersize;
break;
case V4L2_BUF_TYPE_META_CAPTURE:
requested_sizes[0] = f->fmt.meta.buffersize;
break;
default:
return -EINVAL;
}
for (i = 0; i < requested_planes; i++)
if (requested_sizes[i] == 0)
return -EINVAL;
return ret ? ret : vb2_core_create_bufs(q, create->memory,
&create->count, requested_planes, requested_sizes);
}
int vb2_qbuf(struct vb2_queue *q, struct v4l2_buffer *b)
{
int ret;
if (vb2_fileio_is_active(q)) {
dprintk(1, "file io in progress\n");
return -EBUSY;
}
ret = vb2_queue_or_prepare_buf(q, b, "qbuf");
return ret ? ret : vb2_core_qbuf(q, b->index, b);
}
int vb2_dqbuf(struct vb2_queue *q, struct v4l2_buffer *b, bool nonblocking)
{
int ret;
if (vb2_fileio_is_active(q)) {
dprintk(1, "file io in progress\n");
return -EBUSY;
}
if (b->type != q->type) {
dprintk(1, "invalid buffer type\n");
return -EINVAL;
}
ret = vb2_core_dqbuf(q, NULL, b, nonblocking);
b->flags &= ~V4L2_BUF_FLAG_DONE;
return ret;
}
int vb2_streamon(struct vb2_queue *q, enum v4l2_buf_type type)
{
if (vb2_fileio_is_active(q)) {
dprintk(1, "file io in progress\n");
return -EBUSY;
}
return vb2_core_streamon(q, type);
}
int vb2_streamoff(struct vb2_queue *q, enum v4l2_buf_type type)
{
if (vb2_fileio_is_active(q)) {
dprintk(1, "file io in progress\n");
return -EBUSY;
}
return vb2_core_streamoff(q, type);
}
int vb2_expbuf(struct vb2_queue *q, struct v4l2_exportbuffer *eb)
{
return vb2_core_expbuf(q, &eb->fd, eb->type, eb->index,
eb->plane, eb->flags);
}
int vb2_queue_init(struct vb2_queue *q)
{
if (WARN_ON(!q) ||
WARN_ON(q->timestamp_flags &
~(V4L2_BUF_FLAG_TIMESTAMP_MASK |
V4L2_BUF_FLAG_TSTAMP_SRC_MASK)))
return -EINVAL;
WARN_ON((q->timestamp_flags & V4L2_BUF_FLAG_TIMESTAMP_MASK) ==
V4L2_BUF_FLAG_TIMESTAMP_UNKNOWN);
if (WARN_ON(VB2_MEMORY_MMAP != (int)V4L2_MEMORY_MMAP)
|| WARN_ON(VB2_MEMORY_USERPTR != (int)V4L2_MEMORY_USERPTR)
|| WARN_ON(VB2_MEMORY_DMABUF != (int)V4L2_MEMORY_DMABUF))
return -EINVAL;
if (q->buf_struct_size == 0)
q->buf_struct_size = sizeof(struct vb2_v4l2_buffer);
q->buf_ops = &v4l2_buf_ops;
q->is_multiplanar = V4L2_TYPE_IS_MULTIPLANAR(q->type);
q->is_output = V4L2_TYPE_IS_OUTPUT(q->type);
q->copy_timestamp = (q->timestamp_flags & V4L2_BUF_FLAG_TIMESTAMP_MASK)
== V4L2_BUF_FLAG_TIMESTAMP_COPY;
q->quirk_poll_must_check_waiting_for_buffers = true;
return vb2_core_queue_init(q);
}
void vb2_queue_release(struct vb2_queue *q)
{
vb2_core_queue_release(q);
}
unsigned int vb2_poll(struct vb2_queue *q, struct file *file, poll_table *wait)
{
struct video_device *vfd = video_devdata(file);
unsigned long req_events = poll_requested_events(wait);
unsigned int res = 0;
if (test_bit(V4L2_FL_USES_V4L2_FH, &vfd->flags)) {
struct v4l2_fh *fh = file->private_data;
if (v4l2_event_pending(fh))
res = POLLPRI;
else if (req_events & POLLPRI)
poll_wait(file, &fh->wait, wait);
}
return res | vb2_core_poll(q, file, wait);
}
static inline bool vb2_queue_is_busy(struct video_device *vdev, struct file *file)
{
return vdev->queue->owner && vdev->queue->owner != file->private_data;
}
int vb2_ioctl_reqbufs(struct file *file, void *priv,
struct v4l2_requestbuffers *p)
{
struct video_device *vdev = video_devdata(file);
int res = vb2_verify_memory_type(vdev->queue, p->memory, p->type);
if (res)
return res;
if (vb2_queue_is_busy(vdev, file))
return -EBUSY;
res = vb2_core_reqbufs(vdev->queue, p->memory, &p->count);
if (res == 0)
vdev->queue->owner = p->count ? file->private_data : NULL;
return res;
}
int vb2_ioctl_create_bufs(struct file *file, void *priv,
struct v4l2_create_buffers *p)
{
struct video_device *vdev = video_devdata(file);
int res = vb2_verify_memory_type(vdev->queue, p->memory,
p->format.type);
p->index = vdev->queue->num_buffers;
if (p->count == 0)
return res != -EBUSY ? res : 0;
if (res)
return res;
if (vb2_queue_is_busy(vdev, file))
return -EBUSY;
res = vb2_create_bufs(vdev->queue, p);
if (res == 0)
vdev->queue->owner = file->private_data;
return res;
}
int vb2_ioctl_prepare_buf(struct file *file, void *priv,
struct v4l2_buffer *p)
{
struct video_device *vdev = video_devdata(file);
if (vb2_queue_is_busy(vdev, file))
return -EBUSY;
return vb2_prepare_buf(vdev->queue, p);
}
int vb2_ioctl_querybuf(struct file *file, void *priv, struct v4l2_buffer *p)
{
struct video_device *vdev = video_devdata(file);
return vb2_querybuf(vdev->queue, p);
}
int vb2_ioctl_qbuf(struct file *file, void *priv, struct v4l2_buffer *p)
{
struct video_device *vdev = video_devdata(file);
if (vb2_queue_is_busy(vdev, file))
return -EBUSY;
return vb2_qbuf(vdev->queue, p);
}
int vb2_ioctl_dqbuf(struct file *file, void *priv, struct v4l2_buffer *p)
{
struct video_device *vdev = video_devdata(file);
if (vb2_queue_is_busy(vdev, file))
return -EBUSY;
return vb2_dqbuf(vdev->queue, p, file->f_flags & O_NONBLOCK);
}
int vb2_ioctl_streamon(struct file *file, void *priv, enum v4l2_buf_type i)
{
struct video_device *vdev = video_devdata(file);
if (vb2_queue_is_busy(vdev, file))
return -EBUSY;
return vb2_streamon(vdev->queue, i);
}
int vb2_ioctl_streamoff(struct file *file, void *priv, enum v4l2_buf_type i)
{
struct video_device *vdev = video_devdata(file);
if (vb2_queue_is_busy(vdev, file))
return -EBUSY;
return vb2_streamoff(vdev->queue, i);
}
int vb2_ioctl_expbuf(struct file *file, void *priv, struct v4l2_exportbuffer *p)
{
struct video_device *vdev = video_devdata(file);
if (vb2_queue_is_busy(vdev, file))
return -EBUSY;
return vb2_expbuf(vdev->queue, p);
}
int vb2_fop_mmap(struct file *file, struct vm_area_struct *vma)
{
struct video_device *vdev = video_devdata(file);
return vb2_mmap(vdev->queue, vma);
}
int _vb2_fop_release(struct file *file, struct mutex *lock)
{
struct video_device *vdev = video_devdata(file);
if (lock)
mutex_lock(lock);
if (file->private_data == vdev->queue->owner) {
vb2_queue_release(vdev->queue);
vdev->queue->owner = NULL;
}
if (lock)
mutex_unlock(lock);
return v4l2_fh_release(file);
}
int vb2_fop_release(struct file *file)
{
struct video_device *vdev = video_devdata(file);
struct mutex *lock = vdev->queue->lock ? vdev->queue->lock : vdev->lock;
return _vb2_fop_release(file, lock);
}
ssize_t vb2_fop_write(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct video_device *vdev = video_devdata(file);
struct mutex *lock = vdev->queue->lock ? vdev->queue->lock : vdev->lock;
int err = -EBUSY;
if (!(vdev->queue->io_modes & VB2_WRITE))
return -EINVAL;
if (lock && mutex_lock_interruptible(lock))
return -ERESTARTSYS;
if (vb2_queue_is_busy(vdev, file))
goto exit;
err = vb2_write(vdev->queue, buf, count, ppos,
file->f_flags & O_NONBLOCK);
if (vdev->queue->fileio)
vdev->queue->owner = file->private_data;
exit:
if (lock)
mutex_unlock(lock);
return err;
}
ssize_t vb2_fop_read(struct file *file, char __user *buf,
size_t count, loff_t *ppos)
{
struct video_device *vdev = video_devdata(file);
struct mutex *lock = vdev->queue->lock ? vdev->queue->lock : vdev->lock;
int err = -EBUSY;
if (!(vdev->queue->io_modes & VB2_READ))
return -EINVAL;
if (lock && mutex_lock_interruptible(lock))
return -ERESTARTSYS;
if (vb2_queue_is_busy(vdev, file))
goto exit;
err = vb2_read(vdev->queue, buf, count, ppos,
file->f_flags & O_NONBLOCK);
if (vdev->queue->fileio)
vdev->queue->owner = file->private_data;
exit:
if (lock)
mutex_unlock(lock);
return err;
}
unsigned int vb2_fop_poll(struct file *file, poll_table *wait)
{
struct video_device *vdev = video_devdata(file);
struct vb2_queue *q = vdev->queue;
struct mutex *lock = q->lock ? q->lock : vdev->lock;
unsigned res;
void *fileio;
WARN_ON(!lock);
if (lock && mutex_lock_interruptible(lock))
return POLLERR;
fileio = q->fileio;
res = vb2_poll(vdev->queue, file, wait);
if (!fileio && q->fileio)
q->owner = file->private_data;
if (lock)
mutex_unlock(lock);
return res;
}
unsigned long vb2_fop_get_unmapped_area(struct file *file, unsigned long addr,
unsigned long len, unsigned long pgoff, unsigned long flags)
{
struct video_device *vdev = video_devdata(file);
return vb2_get_unmapped_area(vdev->queue, addr, len, pgoff, flags);
}
void vb2_ops_wait_prepare(struct vb2_queue *vq)
{
mutex_unlock(vq->lock);
}
void vb2_ops_wait_finish(struct vb2_queue *vq)
{
mutex_lock(vq->lock);
}
