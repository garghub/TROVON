static int __verify_planes_array(struct vb2_buffer *vb, const struct v4l2_buffer *b)
{
if (!V4L2_TYPE_IS_MULTIPLANAR(b->type))
return 0;
if (NULL == b->m.planes) {
dprintk(1, "multi-planar buffer passed but "
"planes array not provided\n");
return -EINVAL;
}
if (b->length < vb->num_planes || b->length > VB2_MAX_PLANES) {
dprintk(1, "incorrect planes array length, "
"expected %d, got %d\n", vb->num_planes, b->length);
return -EINVAL;
}
return 0;
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
static int __set_timestamp(struct vb2_buffer *vb, const void *pb)
{
const struct v4l2_buffer *b = pb;
struct vb2_v4l2_buffer *vbuf = to_vb2_v4l2_buffer(vb);
struct vb2_queue *q = vb->vb2_queue;
if (q->is_output) {
if ((q->timestamp_flags & V4L2_BUF_FLAG_TIMESTAMP_MASK) ==
V4L2_BUF_FLAG_TIMESTAMP_COPY)
vbuf->timestamp = b->timestamp;
vbuf->flags |= b->flags & V4L2_BUF_FLAG_TIMECODE;
if (b->flags & V4L2_BUF_FLAG_TIMECODE)
vbuf->timecode = b->timecode;
}
return 0;
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
static int __fill_v4l2_buffer(struct vb2_buffer *vb, void *pb)
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
b->timestamp = vbuf->timestamp;
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
if ((q->timestamp_flags & V4L2_BUF_FLAG_TIMESTAMP_MASK) !=
V4L2_BUF_FLAG_TIMESTAMP_COPY) {
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
return 0;
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
dprintk(1, "the field is incorrectly set to ALTERNATE "
"for an output buffer\n");
return -EINVAL;
}
vbuf->timestamp.tv_sec = 0;
vbuf->timestamp.tv_usec = 0;
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
if ((vb->vb2_queue->timestamp_flags & V4L2_BUF_FLAG_TIMESTAMP_MASK) !=
V4L2_BUF_FLAG_TIMESTAMP_COPY || !V4L2_TYPE_IS_OUTPUT(b->type)) {
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
return ret ? ret : vb2_core_querybuf(q, b->index, b);
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
int ret = vb2_verify_memory_type(q, create->memory,
create->format.type);
create->index = q->num_buffers;
if (create->count == 0)
return ret != -EBUSY ? ret : 0;
return ret ? ret : vb2_core_create_bufs(q, create->memory,
&create->count, &create->format);
}
static int vb2_internal_qbuf(struct vb2_queue *q, struct v4l2_buffer *b)
{
int ret = vb2_queue_or_prepare_buf(q, b, "qbuf");
return ret ? ret : vb2_core_qbuf(q, b->index, b);
}
int vb2_qbuf(struct vb2_queue *q, struct v4l2_buffer *b)
{
if (vb2_fileio_is_active(q)) {
dprintk(1, "file io in progress\n");
return -EBUSY;
}
return vb2_internal_qbuf(q, b);
}
static int vb2_internal_dqbuf(struct vb2_queue *q, struct v4l2_buffer *b,
bool nonblocking)
{
int ret;
if (b->type != q->type) {
dprintk(1, "invalid buffer type\n");
return -EINVAL;
}
ret = vb2_core_dqbuf(q, b, nonblocking);
if (!ret && !q->is_output &&
b->flags & V4L2_BUF_FLAG_LAST)
q->last_buffer_dequeued = true;
return ret;
}
int vb2_dqbuf(struct vb2_queue *q, struct v4l2_buffer *b, bool nonblocking)
{
if (vb2_fileio_is_active(q)) {
dprintk(1, "file io in progress\n");
return -EBUSY;
}
return vb2_internal_dqbuf(q, b, nonblocking);
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
return vb2_core_queue_init(q);
}
void vb2_queue_release(struct vb2_queue *q)
{
__vb2_cleanup_fileio(q);
vb2_core_queue_release(q);
}
unsigned int vb2_poll(struct vb2_queue *q, struct file *file, poll_table *wait)
{
struct video_device *vfd = video_devdata(file);
unsigned long req_events = poll_requested_events(wait);
struct vb2_buffer *vb = NULL;
unsigned int res = 0;
unsigned long flags;
if (test_bit(V4L2_FL_USES_V4L2_FH, &vfd->flags)) {
struct v4l2_fh *fh = file->private_data;
if (v4l2_event_pending(fh))
res = POLLPRI;
else if (req_events & POLLPRI)
poll_wait(file, &fh->wait, wait);
}
if (!q->is_output && !(req_events & (POLLIN | POLLRDNORM)))
return res;
if (q->is_output && !(req_events & (POLLOUT | POLLWRNORM)))
return res;
if (q->num_buffers == 0 && !vb2_fileio_is_active(q)) {
if (!q->is_output && (q->io_modes & VB2_READ) &&
(req_events & (POLLIN | POLLRDNORM))) {
if (__vb2_init_fileio(q, 1))
return res | POLLERR;
}
if (q->is_output && (q->io_modes & VB2_WRITE) &&
(req_events & (POLLOUT | POLLWRNORM))) {
if (__vb2_init_fileio(q, 0))
return res | POLLERR;
return res | POLLOUT | POLLWRNORM;
}
}
if (!vb2_is_streaming(q) || q->error)
return res | POLLERR;
if (q->waiting_for_buffers)
return res | POLLERR;
if (q->is_output && q->queued_count < q->num_buffers)
return res | POLLOUT | POLLWRNORM;
if (list_empty(&q->done_list)) {
if (q->last_buffer_dequeued)
return res | POLLIN | POLLRDNORM;
poll_wait(file, &q->done_wq, wait);
}
spin_lock_irqsave(&q->done_lock, flags);
if (!list_empty(&q->done_list))
vb = list_first_entry(&q->done_list, struct vb2_buffer,
done_entry);
spin_unlock_irqrestore(&q->done_lock, flags);
if (vb && (vb->state == VB2_BUF_STATE_DONE
|| vb->state == VB2_BUF_STATE_ERROR)) {
return (q->is_output) ?
res | POLLOUT | POLLWRNORM :
res | POLLIN | POLLRDNORM;
}
return res;
}
static int __vb2_init_fileio(struct vb2_queue *q, int read)
{
struct vb2_fileio_data *fileio;
int i, ret;
unsigned int count = 0;
if (WARN_ON((read && !(q->io_modes & VB2_READ)) ||
(!read && !(q->io_modes & VB2_WRITE))))
return -EINVAL;
if (!q->mem_ops->vaddr)
return -EBUSY;
if (q->streaming || q->num_buffers > 0)
return -EBUSY;
count = 1;
dprintk(3, "setting up file io: mode %s, count %d, read_once %d, write_immediately %d\n",
(read) ? "read" : "write", count, q->fileio_read_once,
q->fileio_write_immediately);
fileio = kzalloc(sizeof(struct vb2_fileio_data), GFP_KERNEL);
if (fileio == NULL)
return -ENOMEM;
fileio->read_once = q->fileio_read_once;
fileio->write_immediately = q->fileio_write_immediately;
fileio->req.count = count;
fileio->req.memory = VB2_MEMORY_MMAP;
fileio->req.type = q->type;
q->fileio = fileio;
ret = vb2_core_reqbufs(q, fileio->req.memory, &fileio->req.count);
if (ret)
goto err_kfree;
if (q->bufs[0]->num_planes != 1) {
ret = -EBUSY;
goto err_reqbufs;
}
for (i = 0; i < q->num_buffers; i++) {
fileio->bufs[i].vaddr = vb2_plane_vaddr(q->bufs[i], 0);
if (fileio->bufs[i].vaddr == NULL) {
ret = -EINVAL;
goto err_reqbufs;
}
fileio->bufs[i].size = vb2_plane_size(q->bufs[i], 0);
}
if (read) {
bool is_multiplanar = q->is_multiplanar;
for (i = 0; i < q->num_buffers; i++) {
struct v4l2_buffer *b = &fileio->b;
memset(b, 0, sizeof(*b));
b->type = q->type;
if (is_multiplanar) {
memset(&fileio->p, 0, sizeof(fileio->p));
b->m.planes = &fileio->p;
b->length = 1;
}
b->memory = q->memory;
b->index = i;
ret = vb2_internal_qbuf(q, b);
if (ret)
goto err_reqbufs;
fileio->bufs[i].queued = 1;
}
fileio->initial_index = q->num_buffers;
fileio->cur_index = q->num_buffers;
}
ret = vb2_core_streamon(q, q->type);
if (ret)
goto err_reqbufs;
return ret;
err_reqbufs:
fileio->req.count = 0;
vb2_core_reqbufs(q, fileio->req.memory, &fileio->req.count);
err_kfree:
q->fileio = NULL;
kfree(fileio);
return ret;
}
static int __vb2_cleanup_fileio(struct vb2_queue *q)
{
struct vb2_fileio_data *fileio = q->fileio;
if (fileio) {
vb2_core_streamoff(q, q->type);
q->fileio = NULL;
fileio->req.count = 0;
vb2_reqbufs(q, &fileio->req);
kfree(fileio);
dprintk(3, "file io emulator closed\n");
}
return 0;
}
static size_t __vb2_perform_fileio(struct vb2_queue *q, char __user *data, size_t count,
loff_t *ppos, int nonblock, int read)
{
struct vb2_fileio_data *fileio;
struct vb2_fileio_buf *buf;
bool is_multiplanar = q->is_multiplanar;
bool set_timestamp = !read &&
(q->timestamp_flags & V4L2_BUF_FLAG_TIMESTAMP_MASK) ==
V4L2_BUF_FLAG_TIMESTAMP_COPY;
int ret, index;
dprintk(3, "mode %s, offset %ld, count %zd, %sblocking\n",
read ? "read" : "write", (long)*ppos, count,
nonblock ? "non" : "");
if (!data)
return -EINVAL;
if (!vb2_fileio_is_active(q)) {
ret = __vb2_init_fileio(q, read);
dprintk(3, "vb2_init_fileio result: %d\n", ret);
if (ret)
return ret;
}
fileio = q->fileio;
index = fileio->cur_index;
if (index >= q->num_buffers) {
memset(&fileio->b, 0, sizeof(fileio->b));
fileio->b.type = q->type;
fileio->b.memory = q->memory;
if (is_multiplanar) {
memset(&fileio->p, 0, sizeof(fileio->p));
fileio->b.m.planes = &fileio->p;
fileio->b.length = 1;
}
ret = vb2_internal_dqbuf(q, &fileio->b, nonblock);
dprintk(5, "vb2_dqbuf result: %d\n", ret);
if (ret)
return ret;
fileio->dq_count += 1;
fileio->cur_index = index = fileio->b.index;
buf = &fileio->bufs[index];
buf->pos = 0;
buf->queued = 0;
buf->size = read ? vb2_get_plane_payload(q->bufs[index], 0)
: vb2_plane_size(q->bufs[index], 0);
if (is_multiplanar && read &&
fileio->b.m.planes[0].data_offset < buf->size) {
buf->pos = fileio->b.m.planes[0].data_offset;
buf->size -= buf->pos;
}
} else {
buf = &fileio->bufs[index];
}
if (buf->pos + count > buf->size) {
count = buf->size - buf->pos;
dprintk(5, "reducing read count: %zd\n", count);
}
dprintk(3, "copying %zd bytes - buffer %d, offset %u\n",
count, index, buf->pos);
if (read)
ret = copy_to_user(data, buf->vaddr + buf->pos, count);
else
ret = copy_from_user(buf->vaddr + buf->pos, data, count);
if (ret) {
dprintk(3, "error copying data\n");
return -EFAULT;
}
buf->pos += count;
*ppos += count;
if (buf->pos == buf->size || (!read && fileio->write_immediately)) {
if (read && fileio->read_once && fileio->dq_count == 1) {
dprintk(3, "read limit reached\n");
return __vb2_cleanup_fileio(q);
}
memset(&fileio->b, 0, sizeof(fileio->b));
fileio->b.type = q->type;
fileio->b.memory = q->memory;
fileio->b.index = index;
fileio->b.bytesused = buf->pos;
if (is_multiplanar) {
memset(&fileio->p, 0, sizeof(fileio->p));
fileio->p.bytesused = buf->pos;
fileio->b.m.planes = &fileio->p;
fileio->b.length = 1;
}
if (set_timestamp)
v4l2_get_timestamp(&fileio->b.timestamp);
ret = vb2_internal_qbuf(q, &fileio->b);
dprintk(5, "vb2_dbuf result: %d\n", ret);
if (ret)
return ret;
buf->pos = 0;
buf->queued = 1;
buf->size = vb2_plane_size(q->bufs[index], 0);
fileio->q_count += 1;
if (fileio->initial_index < q->num_buffers)
fileio->initial_index++;
fileio->cur_index = fileio->initial_index;
}
if (ret == 0)
ret = count;
return ret;
}
size_t vb2_read(struct vb2_queue *q, char __user *data, size_t count,
loff_t *ppos, int nonblocking)
{
return __vb2_perform_fileio(q, data, count, ppos, nonblocking, 1);
}
size_t vb2_write(struct vb2_queue *q, const char __user *data, size_t count,
loff_t *ppos, int nonblocking)
{
return __vb2_perform_fileio(q, (char __user *) data, count,
ppos, nonblocking, 0);
}
static int vb2_thread(void *data)
{
struct vb2_queue *q = data;
struct vb2_threadio_data *threadio = q->threadio;
struct vb2_fileio_data *fileio = q->fileio;
bool set_timestamp = false;
int prequeue = 0;
int index = 0;
int ret = 0;
if (q->is_output) {
prequeue = q->num_buffers;
set_timestamp =
(q->timestamp_flags & V4L2_BUF_FLAG_TIMESTAMP_MASK) ==
V4L2_BUF_FLAG_TIMESTAMP_COPY;
}
set_freezable();
for (;;) {
struct vb2_buffer *vb;
memset(&fileio->b, 0, sizeof(fileio->b));
fileio->b.type = q->type;
fileio->b.memory = q->memory;
if (prequeue) {
fileio->b.index = index++;
prequeue--;
} else {
call_void_qop(q, wait_finish, q);
if (!threadio->stop)
ret = vb2_internal_dqbuf(q, &fileio->b, 0);
call_void_qop(q, wait_prepare, q);
dprintk(5, "file io: vb2_dqbuf result: %d\n", ret);
}
if (ret || threadio->stop)
break;
try_to_freeze();
vb = q->bufs[fileio->b.index];
if (!(fileio->b.flags & V4L2_BUF_FLAG_ERROR))
if (threadio->fnc(vb, threadio->priv))
break;
call_void_qop(q, wait_finish, q);
if (set_timestamp)
v4l2_get_timestamp(&fileio->b.timestamp);
if (!threadio->stop)
ret = vb2_internal_qbuf(q, &fileio->b);
call_void_qop(q, wait_prepare, q);
if (ret || threadio->stop)
break;
}
while (!kthread_should_stop()) {
set_current_state(TASK_INTERRUPTIBLE);
schedule();
}
return 0;
}
int vb2_thread_start(struct vb2_queue *q, vb2_thread_fnc fnc, void *priv,
const char *thread_name)
{
struct vb2_threadio_data *threadio;
int ret = 0;
if (q->threadio)
return -EBUSY;
if (vb2_is_busy(q))
return -EBUSY;
if (WARN_ON(q->fileio))
return -EBUSY;
threadio = kzalloc(sizeof(*threadio), GFP_KERNEL);
if (threadio == NULL)
return -ENOMEM;
threadio->fnc = fnc;
threadio->priv = priv;
ret = __vb2_init_fileio(q, !q->is_output);
dprintk(3, "file io: vb2_init_fileio result: %d\n", ret);
if (ret)
goto nomem;
q->threadio = threadio;
threadio->thread = kthread_run(vb2_thread, q, "vb2-%s", thread_name);
if (IS_ERR(threadio->thread)) {
ret = PTR_ERR(threadio->thread);
threadio->thread = NULL;
goto nothread;
}
return 0;
nothread:
__vb2_cleanup_fileio(q);
nomem:
kfree(threadio);
return ret;
}
int vb2_thread_stop(struct vb2_queue *q)
{
struct vb2_threadio_data *threadio = q->threadio;
int err;
if (threadio == NULL)
return 0;
threadio->stop = true;
vb2_queue_error(q);
err = kthread_stop(threadio->thread);
__vb2_cleanup_fileio(q);
threadio->thread = NULL;
kfree(threadio);
q->threadio = NULL;
return err;
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
res = vb2_core_create_bufs(vdev->queue, p->memory, &p->count,
&p->format);
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
