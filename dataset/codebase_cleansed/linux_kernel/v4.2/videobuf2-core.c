static int __vb2_buf_mem_alloc(struct vb2_buffer *vb)
{
struct vb2_queue *q = vb->vb2_queue;
enum dma_data_direction dma_dir =
V4L2_TYPE_IS_OUTPUT(q->type) ? DMA_TO_DEVICE : DMA_FROM_DEVICE;
void *mem_priv;
int plane;
for (plane = 0; plane < vb->num_planes; ++plane) {
unsigned long size = PAGE_ALIGN(q->plane_sizes[plane]);
mem_priv = call_ptr_memop(vb, alloc, q->alloc_ctx[plane],
size, dma_dir, q->gfp_flags);
if (IS_ERR_OR_NULL(mem_priv))
goto free;
vb->planes[plane].mem_priv = mem_priv;
vb->v4l2_planes[plane].length = q->plane_sizes[plane];
}
return 0;
free:
for (; plane > 0; --plane) {
call_void_memop(vb, put, vb->planes[plane - 1].mem_priv);
vb->planes[plane - 1].mem_priv = NULL;
}
return -ENOMEM;
}
static void __vb2_buf_mem_free(struct vb2_buffer *vb)
{
unsigned int plane;
for (plane = 0; plane < vb->num_planes; ++plane) {
call_void_memop(vb, put, vb->planes[plane].mem_priv);
vb->planes[plane].mem_priv = NULL;
dprintk(3, "freed plane %d of buffer %d\n", plane,
vb->v4l2_buf.index);
}
}
static void __vb2_buf_userptr_put(struct vb2_buffer *vb)
{
unsigned int plane;
for (plane = 0; plane < vb->num_planes; ++plane) {
if (vb->planes[plane].mem_priv)
call_void_memop(vb, put_userptr, vb->planes[plane].mem_priv);
vb->planes[plane].mem_priv = NULL;
}
}
static void __vb2_plane_dmabuf_put(struct vb2_buffer *vb, struct vb2_plane *p)
{
if (!p->mem_priv)
return;
if (p->dbuf_mapped)
call_void_memop(vb, unmap_dmabuf, p->mem_priv);
call_void_memop(vb, detach_dmabuf, p->mem_priv);
dma_buf_put(p->dbuf);
memset(p, 0, sizeof(*p));
}
static void __vb2_buf_dmabuf_put(struct vb2_buffer *vb)
{
unsigned int plane;
for (plane = 0; plane < vb->num_planes; ++plane)
__vb2_plane_dmabuf_put(vb, &vb->planes[plane]);
}
static void __setup_lengths(struct vb2_queue *q, unsigned int n)
{
unsigned int buffer, plane;
struct vb2_buffer *vb;
for (buffer = q->num_buffers; buffer < q->num_buffers + n; ++buffer) {
vb = q->bufs[buffer];
if (!vb)
continue;
for (plane = 0; plane < vb->num_planes; ++plane)
vb->v4l2_planes[plane].length = q->plane_sizes[plane];
}
}
static void __setup_offsets(struct vb2_queue *q, unsigned int n)
{
unsigned int buffer, plane;
struct vb2_buffer *vb;
unsigned long off;
if (q->num_buffers) {
struct v4l2_plane *p;
vb = q->bufs[q->num_buffers - 1];
p = &vb->v4l2_planes[vb->num_planes - 1];
off = PAGE_ALIGN(p->m.mem_offset + p->length);
} else {
off = 0;
}
for (buffer = q->num_buffers; buffer < q->num_buffers + n; ++buffer) {
vb = q->bufs[buffer];
if (!vb)
continue;
for (plane = 0; plane < vb->num_planes; ++plane) {
vb->v4l2_planes[plane].m.mem_offset = off;
dprintk(3, "buffer %d, plane %d offset 0x%08lx\n",
buffer, plane, off);
off += vb->v4l2_planes[plane].length;
off = PAGE_ALIGN(off);
}
}
}
static int __vb2_queue_alloc(struct vb2_queue *q, enum v4l2_memory memory,
unsigned int num_buffers, unsigned int num_planes)
{
unsigned int buffer;
struct vb2_buffer *vb;
int ret;
for (buffer = 0; buffer < num_buffers; ++buffer) {
vb = kzalloc(q->buf_struct_size, GFP_KERNEL);
if (!vb) {
dprintk(1, "memory alloc for buffer struct failed\n");
break;
}
if (V4L2_TYPE_IS_MULTIPLANAR(q->type))
vb->v4l2_buf.length = num_planes;
vb->state = VB2_BUF_STATE_DEQUEUED;
vb->vb2_queue = q;
vb->num_planes = num_planes;
vb->v4l2_buf.index = q->num_buffers + buffer;
vb->v4l2_buf.type = q->type;
vb->v4l2_buf.memory = memory;
if (memory == V4L2_MEMORY_MMAP) {
ret = __vb2_buf_mem_alloc(vb);
if (ret) {
dprintk(1, "failed allocating memory for "
"buffer %d\n", buffer);
kfree(vb);
break;
}
ret = call_vb_qop(vb, buf_init, vb);
if (ret) {
dprintk(1, "buffer %d %p initialization"
" failed\n", buffer, vb);
__vb2_buf_mem_free(vb);
kfree(vb);
break;
}
}
q->bufs[q->num_buffers + buffer] = vb;
}
__setup_lengths(q, buffer);
if (memory == V4L2_MEMORY_MMAP)
__setup_offsets(q, buffer);
dprintk(1, "allocated %d buffers, %d plane(s) each\n",
buffer, num_planes);
return buffer;
}
static void __vb2_free_mem(struct vb2_queue *q, unsigned int buffers)
{
unsigned int buffer;
struct vb2_buffer *vb;
for (buffer = q->num_buffers - buffers; buffer < q->num_buffers;
++buffer) {
vb = q->bufs[buffer];
if (!vb)
continue;
if (q->memory == V4L2_MEMORY_MMAP)
__vb2_buf_mem_free(vb);
else if (q->memory == V4L2_MEMORY_DMABUF)
__vb2_buf_dmabuf_put(vb);
else
__vb2_buf_userptr_put(vb);
}
}
static int __vb2_queue_free(struct vb2_queue *q, unsigned int buffers)
{
unsigned int buffer;
for (buffer = q->num_buffers - buffers; buffer < q->num_buffers;
++buffer) {
if (q->bufs[buffer] == NULL)
continue;
if (q->bufs[buffer]->state == VB2_BUF_STATE_PREPARING) {
dprintk(1, "preparing buffers, cannot free\n");
return -EAGAIN;
}
}
for (buffer = q->num_buffers - buffers; buffer < q->num_buffers;
++buffer) {
struct vb2_buffer *vb = q->bufs[buffer];
if (vb && vb->planes[0].mem_priv)
call_void_vb_qop(vb, buf_cleanup, vb);
}
__vb2_free_mem(q, buffers);
#ifdef CONFIG_VIDEO_ADV_DEBUG
if (q->num_buffers) {
bool unbalanced = q->cnt_start_streaming != q->cnt_stop_streaming ||
q->cnt_wait_prepare != q->cnt_wait_finish;
if (unbalanced || debug) {
pr_info("vb2: counters for queue %p:%s\n", q,
unbalanced ? " UNBALANCED!" : "");
pr_info("vb2: setup: %u start_streaming: %u stop_streaming: %u\n",
q->cnt_queue_setup, q->cnt_start_streaming,
q->cnt_stop_streaming);
pr_info("vb2: wait_prepare: %u wait_finish: %u\n",
q->cnt_wait_prepare, q->cnt_wait_finish);
}
q->cnt_queue_setup = 0;
q->cnt_wait_prepare = 0;
q->cnt_wait_finish = 0;
q->cnt_start_streaming = 0;
q->cnt_stop_streaming = 0;
}
for (buffer = 0; buffer < q->num_buffers; ++buffer) {
struct vb2_buffer *vb = q->bufs[buffer];
bool unbalanced = vb->cnt_mem_alloc != vb->cnt_mem_put ||
vb->cnt_mem_prepare != vb->cnt_mem_finish ||
vb->cnt_mem_get_userptr != vb->cnt_mem_put_userptr ||
vb->cnt_mem_attach_dmabuf != vb->cnt_mem_detach_dmabuf ||
vb->cnt_mem_map_dmabuf != vb->cnt_mem_unmap_dmabuf ||
vb->cnt_buf_queue != vb->cnt_buf_done ||
vb->cnt_buf_prepare != vb->cnt_buf_finish ||
vb->cnt_buf_init != vb->cnt_buf_cleanup;
if (unbalanced || debug) {
pr_info("vb2: counters for queue %p, buffer %d:%s\n",
q, buffer, unbalanced ? " UNBALANCED!" : "");
pr_info("vb2: buf_init: %u buf_cleanup: %u buf_prepare: %u buf_finish: %u\n",
vb->cnt_buf_init, vb->cnt_buf_cleanup,
vb->cnt_buf_prepare, vb->cnt_buf_finish);
pr_info("vb2: buf_queue: %u buf_done: %u\n",
vb->cnt_buf_queue, vb->cnt_buf_done);
pr_info("vb2: alloc: %u put: %u prepare: %u finish: %u mmap: %u\n",
vb->cnt_mem_alloc, vb->cnt_mem_put,
vb->cnt_mem_prepare, vb->cnt_mem_finish,
vb->cnt_mem_mmap);
pr_info("vb2: get_userptr: %u put_userptr: %u\n",
vb->cnt_mem_get_userptr, vb->cnt_mem_put_userptr);
pr_info("vb2: attach_dmabuf: %u detach_dmabuf: %u map_dmabuf: %u unmap_dmabuf: %u\n",
vb->cnt_mem_attach_dmabuf, vb->cnt_mem_detach_dmabuf,
vb->cnt_mem_map_dmabuf, vb->cnt_mem_unmap_dmabuf);
pr_info("vb2: get_dmabuf: %u num_users: %u vaddr: %u cookie: %u\n",
vb->cnt_mem_get_dmabuf,
vb->cnt_mem_num_users,
vb->cnt_mem_vaddr,
vb->cnt_mem_cookie);
}
}
#endif
for (buffer = q->num_buffers - buffers; buffer < q->num_buffers;
++buffer) {
kfree(q->bufs[buffer]);
q->bufs[buffer] = NULL;
}
q->num_buffers -= buffers;
if (!q->num_buffers) {
q->memory = 0;
INIT_LIST_HEAD(&q->queued_list);
}
return 0;
}
static int __verify_planes_array(struct vb2_buffer *vb, const struct v4l2_buffer *b)
{
if (!V4L2_TYPE_IS_MULTIPLANAR(b->type))
return 0;
if (NULL == b->m.planes) {
dprintk(1, "multi-planar buffer passed but "
"planes array not provided\n");
return -EINVAL;
}
if (b->length < vb->num_planes || b->length > VIDEO_MAX_PLANES) {
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
length = (b->memory == V4L2_MEMORY_USERPTR ||
b->memory == V4L2_MEMORY_DMABUF)
? b->m.planes[plane].length
: vb->v4l2_planes[plane].length;
bytesused = b->m.planes[plane].bytesused
? b->m.planes[plane].bytesused : length;
if (b->m.planes[plane].bytesused > length)
return -EINVAL;
if (b->m.planes[plane].data_offset > 0 &&
b->m.planes[plane].data_offset >= bytesused)
return -EINVAL;
}
} else {
length = (b->memory == V4L2_MEMORY_USERPTR)
? b->length : vb->v4l2_planes[0].length;
bytesused = b->bytesused ? b->bytesused : length;
if (b->bytesused > length)
return -EINVAL;
}
return 0;
}
static bool __buffer_in_use(struct vb2_queue *q, struct vb2_buffer *vb)
{
unsigned int plane;
for (plane = 0; plane < vb->num_planes; ++plane) {
void *mem_priv = vb->planes[plane].mem_priv;
if (mem_priv && call_memop(vb, num_users, mem_priv) > 1)
return true;
}
return false;
}
static bool __buffers_in_use(struct vb2_queue *q)
{
unsigned int buffer;
for (buffer = 0; buffer < q->num_buffers; ++buffer) {
if (__buffer_in_use(q, q->bufs[buffer]))
return true;
}
return false;
}
static void __fill_v4l2_buffer(struct vb2_buffer *vb, struct v4l2_buffer *b)
{
struct vb2_queue *q = vb->vb2_queue;
memcpy(b, &vb->v4l2_buf, offsetof(struct v4l2_buffer, m));
b->reserved2 = vb->v4l2_buf.reserved2;
b->reserved = vb->v4l2_buf.reserved;
if (V4L2_TYPE_IS_MULTIPLANAR(q->type)) {
b->length = vb->num_planes;
memcpy(b->m.planes, vb->v4l2_planes,
b->length * sizeof(struct v4l2_plane));
} else {
b->length = vb->v4l2_planes[0].length;
b->bytesused = vb->v4l2_planes[0].bytesused;
if (q->memory == V4L2_MEMORY_MMAP)
b->m.offset = vb->v4l2_planes[0].m.mem_offset;
else if (q->memory == V4L2_MEMORY_USERPTR)
b->m.userptr = vb->v4l2_planes[0].m.userptr;
else if (q->memory == V4L2_MEMORY_DMABUF)
b->m.fd = vb->v4l2_planes[0].m.fd;
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
if (__buffer_in_use(q, vb))
b->flags |= V4L2_BUF_FLAG_MAPPED;
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
__fill_v4l2_buffer(vb, b);
return ret;
}
static int __verify_userptr_ops(struct vb2_queue *q)
{
if (!(q->io_modes & VB2_USERPTR) || !q->mem_ops->get_userptr ||
!q->mem_ops->put_userptr)
return -EINVAL;
return 0;
}
static int __verify_mmap_ops(struct vb2_queue *q)
{
if (!(q->io_modes & VB2_MMAP) || !q->mem_ops->alloc ||
!q->mem_ops->put || !q->mem_ops->mmap)
return -EINVAL;
return 0;
}
static int __verify_dmabuf_ops(struct vb2_queue *q)
{
if (!(q->io_modes & VB2_DMABUF) || !q->mem_ops->attach_dmabuf ||
!q->mem_ops->detach_dmabuf || !q->mem_ops->map_dmabuf ||
!q->mem_ops->unmap_dmabuf)
return -EINVAL;
return 0;
}
static int __verify_memory_type(struct vb2_queue *q,
enum v4l2_memory memory, enum v4l2_buf_type type)
{
if (memory != V4L2_MEMORY_MMAP && memory != V4L2_MEMORY_USERPTR &&
memory != V4L2_MEMORY_DMABUF) {
dprintk(1, "unsupported memory type\n");
return -EINVAL;
}
if (type != q->type) {
dprintk(1, "requested type is incorrect\n");
return -EINVAL;
}
if (memory == V4L2_MEMORY_MMAP && __verify_mmap_ops(q)) {
dprintk(1, "MMAP for current setup unsupported\n");
return -EINVAL;
}
if (memory == V4L2_MEMORY_USERPTR && __verify_userptr_ops(q)) {
dprintk(1, "USERPTR for current setup unsupported\n");
return -EINVAL;
}
if (memory == V4L2_MEMORY_DMABUF && __verify_dmabuf_ops(q)) {
dprintk(1, "DMABUF for current setup unsupported\n");
return -EINVAL;
}
if (vb2_fileio_is_active(q)) {
dprintk(1, "file io in progress\n");
return -EBUSY;
}
return 0;
}
static int __reqbufs(struct vb2_queue *q, struct v4l2_requestbuffers *req)
{
unsigned int num_buffers, allocated_buffers, num_planes = 0;
int ret;
if (q->streaming) {
dprintk(1, "streaming active\n");
return -EBUSY;
}
if (req->count == 0 || q->num_buffers != 0 || q->memory != req->memory) {
mutex_lock(&q->mmap_lock);
if (q->memory == V4L2_MEMORY_MMAP && __buffers_in_use(q)) {
mutex_unlock(&q->mmap_lock);
dprintk(1, "memory in use, cannot free\n");
return -EBUSY;
}
__vb2_queue_cancel(q);
ret = __vb2_queue_free(q, q->num_buffers);
mutex_unlock(&q->mmap_lock);
if (ret)
return ret;
if (req->count == 0)
return 0;
}
num_buffers = min_t(unsigned int, req->count, VIDEO_MAX_FRAME);
num_buffers = max_t(unsigned int, num_buffers, q->min_buffers_needed);
memset(q->plane_sizes, 0, sizeof(q->plane_sizes));
memset(q->alloc_ctx, 0, sizeof(q->alloc_ctx));
q->memory = req->memory;
ret = call_qop(q, queue_setup, q, NULL, &num_buffers, &num_planes,
q->plane_sizes, q->alloc_ctx);
if (ret)
return ret;
allocated_buffers = __vb2_queue_alloc(q, req->memory, num_buffers, num_planes);
if (allocated_buffers == 0) {
dprintk(1, "memory allocation failed\n");
return -ENOMEM;
}
if (allocated_buffers < q->min_buffers_needed)
ret = -ENOMEM;
if (!ret && allocated_buffers < num_buffers) {
num_buffers = allocated_buffers;
ret = call_qop(q, queue_setup, q, NULL, &num_buffers,
&num_planes, q->plane_sizes, q->alloc_ctx);
if (!ret && allocated_buffers < num_buffers)
ret = -ENOMEM;
}
mutex_lock(&q->mmap_lock);
q->num_buffers = allocated_buffers;
if (ret < 0) {
__vb2_queue_free(q, allocated_buffers);
mutex_unlock(&q->mmap_lock);
return ret;
}
mutex_unlock(&q->mmap_lock);
req->count = allocated_buffers;
q->waiting_for_buffers = !V4L2_TYPE_IS_OUTPUT(q->type);
return 0;
}
int vb2_reqbufs(struct vb2_queue *q, struct v4l2_requestbuffers *req)
{
int ret = __verify_memory_type(q, req->memory, req->type);
return ret ? ret : __reqbufs(q, req);
}
static int __create_bufs(struct vb2_queue *q, struct v4l2_create_buffers *create)
{
unsigned int num_planes = 0, num_buffers, allocated_buffers;
int ret;
if (q->num_buffers == VIDEO_MAX_FRAME) {
dprintk(1, "maximum number of buffers already allocated\n");
return -ENOBUFS;
}
if (!q->num_buffers) {
memset(q->plane_sizes, 0, sizeof(q->plane_sizes));
memset(q->alloc_ctx, 0, sizeof(q->alloc_ctx));
q->memory = create->memory;
q->waiting_for_buffers = !V4L2_TYPE_IS_OUTPUT(q->type);
}
num_buffers = min(create->count, VIDEO_MAX_FRAME - q->num_buffers);
ret = call_qop(q, queue_setup, q, &create->format, &num_buffers,
&num_planes, q->plane_sizes, q->alloc_ctx);
if (ret)
return ret;
allocated_buffers = __vb2_queue_alloc(q, create->memory, num_buffers,
num_planes);
if (allocated_buffers == 0) {
dprintk(1, "memory allocation failed\n");
return -ENOMEM;
}
if (allocated_buffers < num_buffers) {
num_buffers = allocated_buffers;
ret = call_qop(q, queue_setup, q, &create->format, &num_buffers,
&num_planes, q->plane_sizes, q->alloc_ctx);
if (!ret && allocated_buffers < num_buffers)
ret = -ENOMEM;
}
mutex_lock(&q->mmap_lock);
q->num_buffers += allocated_buffers;
if (ret < 0) {
__vb2_queue_free(q, allocated_buffers);
mutex_unlock(&q->mmap_lock);
return -ENOMEM;
}
mutex_unlock(&q->mmap_lock);
create->count = allocated_buffers;
return 0;
}
int vb2_create_bufs(struct vb2_queue *q, struct v4l2_create_buffers *create)
{
int ret = __verify_memory_type(q, create->memory, create->format.type);
create->index = q->num_buffers;
if (create->count == 0)
return ret != -EBUSY ? ret : 0;
return ret ? ret : __create_bufs(q, create);
}
void *vb2_plane_vaddr(struct vb2_buffer *vb, unsigned int plane_no)
{
if (plane_no > vb->num_planes || !vb->planes[plane_no].mem_priv)
return NULL;
return call_ptr_memop(vb, vaddr, vb->planes[plane_no].mem_priv);
}
void *vb2_plane_cookie(struct vb2_buffer *vb, unsigned int plane_no)
{
if (plane_no >= vb->num_planes || !vb->planes[plane_no].mem_priv)
return NULL;
return call_ptr_memop(vb, cookie, vb->planes[plane_no].mem_priv);
}
void vb2_buffer_done(struct vb2_buffer *vb, enum vb2_buffer_state state)
{
struct vb2_queue *q = vb->vb2_queue;
unsigned long flags;
unsigned int plane;
if (WARN_ON(vb->state != VB2_BUF_STATE_ACTIVE))
return;
if (WARN_ON(state != VB2_BUF_STATE_DONE &&
state != VB2_BUF_STATE_ERROR &&
state != VB2_BUF_STATE_QUEUED &&
state != VB2_BUF_STATE_REQUEUEING))
state = VB2_BUF_STATE_ERROR;
#ifdef CONFIG_VIDEO_ADV_DEBUG
vb->cnt_buf_done++;
#endif
dprintk(4, "done processing on buffer %d, state: %d\n",
vb->v4l2_buf.index, state);
for (plane = 0; plane < vb->num_planes; ++plane)
call_void_memop(vb, finish, vb->planes[plane].mem_priv);
spin_lock_irqsave(&q->done_lock, flags);
if (state == VB2_BUF_STATE_QUEUED ||
state == VB2_BUF_STATE_REQUEUEING) {
vb->state = VB2_BUF_STATE_QUEUED;
} else {
list_add_tail(&vb->done_entry, &q->done_list);
vb->state = state;
}
atomic_dec(&q->owned_by_drv_count);
spin_unlock_irqrestore(&q->done_lock, flags);
switch (state) {
case VB2_BUF_STATE_QUEUED:
return;
case VB2_BUF_STATE_REQUEUEING:
if (q->start_streaming_called)
__enqueue_in_driver(vb);
return;
default:
wake_up(&q->done_wq);
break;
}
}
void vb2_discard_done(struct vb2_queue *q)
{
struct vb2_buffer *vb;
unsigned long flags;
spin_lock_irqsave(&q->done_lock, flags);
list_for_each_entry(vb, &q->done_list, done_entry)
vb->state = VB2_BUF_STATE_ERROR;
spin_unlock_irqrestore(&q->done_lock, flags);
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
static void __fill_vb2_buffer(struct vb2_buffer *vb, const struct v4l2_buffer *b,
struct v4l2_plane *v4l2_planes)
{
unsigned int plane;
if (V4L2_TYPE_IS_MULTIPLANAR(b->type)) {
if (b->memory == V4L2_MEMORY_USERPTR) {
for (plane = 0; plane < vb->num_planes; ++plane) {
v4l2_planes[plane].m.userptr =
b->m.planes[plane].m.userptr;
v4l2_planes[plane].length =
b->m.planes[plane].length;
}
}
if (b->memory == V4L2_MEMORY_DMABUF) {
for (plane = 0; plane < vb->num_planes; ++plane) {
v4l2_planes[plane].m.fd =
b->m.planes[plane].m.fd;
v4l2_planes[plane].length =
b->m.planes[plane].length;
}
}
if (V4L2_TYPE_IS_OUTPUT(b->type)) {
for (plane = 0; plane < vb->num_planes; ++plane) {
struct v4l2_plane *pdst = &v4l2_planes[plane];
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
if (b->memory == V4L2_MEMORY_USERPTR) {
v4l2_planes[0].m.userptr = b->m.userptr;
v4l2_planes[0].length = b->length;
}
if (b->memory == V4L2_MEMORY_DMABUF) {
v4l2_planes[0].m.fd = b->m.fd;
v4l2_planes[0].length = b->length;
}
if (V4L2_TYPE_IS_OUTPUT(b->type)) {
if (b->bytesused == 0)
vb2_warn_zero_bytesused(vb);
if (vb->vb2_queue->allow_zero_bytesused)
v4l2_planes[0].bytesused = b->bytesused;
else
v4l2_planes[0].bytesused = b->bytesused ?
b->bytesused : v4l2_planes[0].length;
} else
v4l2_planes[0].bytesused = 0;
}
vb->v4l2_buf.flags = b->flags & ~V4L2_BUFFER_MASK_FLAGS;
if ((vb->vb2_queue->timestamp_flags & V4L2_BUF_FLAG_TIMESTAMP_MASK) !=
V4L2_BUF_FLAG_TIMESTAMP_COPY || !V4L2_TYPE_IS_OUTPUT(b->type)) {
vb->v4l2_buf.flags &= ~V4L2_BUF_FLAG_TSTAMP_SRC_MASK;
}
if (V4L2_TYPE_IS_OUTPUT(b->type)) {
vb->v4l2_buf.flags &= ~V4L2_BUF_FLAG_TIMECODE;
vb->v4l2_buf.field = b->field;
} else {
vb->v4l2_buf.flags &= ~V4L2_BUFFER_OUT_FLAGS;
}
}
static int __qbuf_mmap(struct vb2_buffer *vb, const struct v4l2_buffer *b)
{
__fill_vb2_buffer(vb, b, vb->v4l2_planes);
return call_vb_qop(vb, buf_prepare, vb);
}
static int __qbuf_userptr(struct vb2_buffer *vb, const struct v4l2_buffer *b)
{
struct v4l2_plane planes[VIDEO_MAX_PLANES];
struct vb2_queue *q = vb->vb2_queue;
void *mem_priv;
unsigned int plane;
int ret;
enum dma_data_direction dma_dir =
V4L2_TYPE_IS_OUTPUT(q->type) ? DMA_TO_DEVICE : DMA_FROM_DEVICE;
bool reacquired = vb->planes[0].mem_priv == NULL;
memset(planes, 0, sizeof(planes[0]) * vb->num_planes);
__fill_vb2_buffer(vb, b, planes);
for (plane = 0; plane < vb->num_planes; ++plane) {
if (vb->v4l2_planes[plane].m.userptr &&
vb->v4l2_planes[plane].m.userptr == planes[plane].m.userptr
&& vb->v4l2_planes[plane].length == planes[plane].length)
continue;
dprintk(3, "userspace address for plane %d changed, "
"reacquiring memory\n", plane);
if (planes[plane].length < q->plane_sizes[plane]) {
dprintk(1, "provided buffer size %u is less than "
"setup size %u for plane %d\n",
planes[plane].length,
q->plane_sizes[plane], plane);
ret = -EINVAL;
goto err;
}
if (vb->planes[plane].mem_priv) {
if (!reacquired) {
reacquired = true;
call_void_vb_qop(vb, buf_cleanup, vb);
}
call_void_memop(vb, put_userptr, vb->planes[plane].mem_priv);
}
vb->planes[plane].mem_priv = NULL;
memset(&vb->v4l2_planes[plane], 0, sizeof(struct v4l2_plane));
mem_priv = call_ptr_memop(vb, get_userptr, q->alloc_ctx[plane],
planes[plane].m.userptr,
planes[plane].length, dma_dir);
if (IS_ERR_OR_NULL(mem_priv)) {
dprintk(1, "failed acquiring userspace "
"memory for plane %d\n", plane);
ret = mem_priv ? PTR_ERR(mem_priv) : -EINVAL;
goto err;
}
vb->planes[plane].mem_priv = mem_priv;
}
for (plane = 0; plane < vb->num_planes; ++plane)
vb->v4l2_planes[plane] = planes[plane];
if (reacquired) {
ret = call_vb_qop(vb, buf_init, vb);
if (ret) {
dprintk(1, "buffer initialization failed\n");
goto err;
}
}
ret = call_vb_qop(vb, buf_prepare, vb);
if (ret) {
dprintk(1, "buffer preparation failed\n");
call_void_vb_qop(vb, buf_cleanup, vb);
goto err;
}
return 0;
err:
for (plane = 0; plane < vb->num_planes; ++plane) {
if (vb->planes[plane].mem_priv)
call_void_memop(vb, put_userptr, vb->planes[plane].mem_priv);
vb->planes[plane].mem_priv = NULL;
vb->v4l2_planes[plane].m.userptr = 0;
vb->v4l2_planes[plane].length = 0;
}
return ret;
}
static int __qbuf_dmabuf(struct vb2_buffer *vb, const struct v4l2_buffer *b)
{
struct v4l2_plane planes[VIDEO_MAX_PLANES];
struct vb2_queue *q = vb->vb2_queue;
void *mem_priv;
unsigned int plane;
int ret;
enum dma_data_direction dma_dir =
V4L2_TYPE_IS_OUTPUT(q->type) ? DMA_TO_DEVICE : DMA_FROM_DEVICE;
bool reacquired = vb->planes[0].mem_priv == NULL;
memset(planes, 0, sizeof(planes[0]) * vb->num_planes);
__fill_vb2_buffer(vb, b, planes);
for (plane = 0; plane < vb->num_planes; ++plane) {
struct dma_buf *dbuf = dma_buf_get(planes[plane].m.fd);
if (IS_ERR_OR_NULL(dbuf)) {
dprintk(1, "invalid dmabuf fd for plane %d\n",
plane);
ret = -EINVAL;
goto err;
}
if (planes[plane].length == 0)
planes[plane].length = dbuf->size;
if (planes[plane].length < q->plane_sizes[plane]) {
dprintk(1, "invalid dmabuf length for plane %d\n",
plane);
ret = -EINVAL;
goto err;
}
if (dbuf == vb->planes[plane].dbuf &&
vb->v4l2_planes[plane].length == planes[plane].length) {
dma_buf_put(dbuf);
continue;
}
dprintk(1, "buffer for plane %d changed\n", plane);
if (!reacquired) {
reacquired = true;
call_void_vb_qop(vb, buf_cleanup, vb);
}
__vb2_plane_dmabuf_put(vb, &vb->planes[plane]);
memset(&vb->v4l2_planes[plane], 0, sizeof(struct v4l2_plane));
mem_priv = call_ptr_memop(vb, attach_dmabuf, q->alloc_ctx[plane],
dbuf, planes[plane].length, dma_dir);
if (IS_ERR(mem_priv)) {
dprintk(1, "failed to attach dmabuf\n");
ret = PTR_ERR(mem_priv);
dma_buf_put(dbuf);
goto err;
}
vb->planes[plane].dbuf = dbuf;
vb->planes[plane].mem_priv = mem_priv;
}
for (plane = 0; plane < vb->num_planes; ++plane) {
ret = call_memop(vb, map_dmabuf, vb->planes[plane].mem_priv);
if (ret) {
dprintk(1, "failed to map dmabuf for plane %d\n",
plane);
goto err;
}
vb->planes[plane].dbuf_mapped = 1;
}
for (plane = 0; plane < vb->num_planes; ++plane)
vb->v4l2_planes[plane] = planes[plane];
if (reacquired) {
ret = call_vb_qop(vb, buf_init, vb);
if (ret) {
dprintk(1, "buffer initialization failed\n");
goto err;
}
}
ret = call_vb_qop(vb, buf_prepare, vb);
if (ret) {
dprintk(1, "buffer preparation failed\n");
call_void_vb_qop(vb, buf_cleanup, vb);
goto err;
}
return 0;
err:
__vb2_buf_dmabuf_put(vb);
return ret;
}
static void __enqueue_in_driver(struct vb2_buffer *vb)
{
struct vb2_queue *q = vb->vb2_queue;
unsigned int plane;
vb->state = VB2_BUF_STATE_ACTIVE;
atomic_inc(&q->owned_by_drv_count);
for (plane = 0; plane < vb->num_planes; ++plane)
call_void_memop(vb, prepare, vb->planes[plane].mem_priv);
call_void_vb_qop(vb, buf_queue, vb);
}
static int __buf_prepare(struct vb2_buffer *vb, const struct v4l2_buffer *b)
{
struct vb2_queue *q = vb->vb2_queue;
int ret;
ret = __verify_length(vb, b);
if (ret < 0) {
dprintk(1, "plane parameters verification failed: %d\n", ret);
return ret;
}
if (b->field == V4L2_FIELD_ALTERNATE && V4L2_TYPE_IS_OUTPUT(q->type)) {
dprintk(1, "the field is incorrectly set to ALTERNATE for an output buffer\n");
return -EINVAL;
}
if (q->error) {
dprintk(1, "fatal error occurred on queue\n");
return -EIO;
}
vb->state = VB2_BUF_STATE_PREPARING;
vb->v4l2_buf.timestamp.tv_sec = 0;
vb->v4l2_buf.timestamp.tv_usec = 0;
vb->v4l2_buf.sequence = 0;
switch (q->memory) {
case V4L2_MEMORY_MMAP:
ret = __qbuf_mmap(vb, b);
break;
case V4L2_MEMORY_USERPTR:
down_read(&current->mm->mmap_sem);
ret = __qbuf_userptr(vb, b);
up_read(&current->mm->mmap_sem);
break;
case V4L2_MEMORY_DMABUF:
ret = __qbuf_dmabuf(vb, b);
break;
default:
WARN(1, "Invalid queue type\n");
ret = -EINVAL;
}
if (ret)
dprintk(1, "buffer preparation failed: %d\n", ret);
vb->state = ret ? VB2_BUF_STATE_DEQUEUED : VB2_BUF_STATE_PREPARED;
return ret;
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
int vb2_prepare_buf(struct vb2_queue *q, struct v4l2_buffer *b)
{
struct vb2_buffer *vb;
int ret;
if (vb2_fileio_is_active(q)) {
dprintk(1, "file io in progress\n");
return -EBUSY;
}
ret = vb2_queue_or_prepare_buf(q, b, "prepare_buf");
if (ret)
return ret;
vb = q->bufs[b->index];
if (vb->state != VB2_BUF_STATE_DEQUEUED) {
dprintk(1, "invalid buffer state %d\n",
vb->state);
return -EINVAL;
}
ret = __buf_prepare(vb, b);
if (!ret) {
__fill_v4l2_buffer(vb, b);
dprintk(1, "prepare of buffer %d succeeded\n", vb->v4l2_buf.index);
}
return ret;
}
static int vb2_start_streaming(struct vb2_queue *q)
{
struct vb2_buffer *vb;
int ret;
list_for_each_entry(vb, &q->queued_list, queued_entry)
__enqueue_in_driver(vb);
q->start_streaming_called = 1;
ret = call_qop(q, start_streaming, q,
atomic_read(&q->owned_by_drv_count));
if (!ret)
return 0;
q->start_streaming_called = 0;
dprintk(1, "driver refused to start streaming\n");
if (WARN_ON(atomic_read(&q->owned_by_drv_count))) {
unsigned i;
for (i = 0; i < q->num_buffers; ++i) {
vb = q->bufs[i];
if (vb->state == VB2_BUF_STATE_ACTIVE)
vb2_buffer_done(vb, VB2_BUF_STATE_QUEUED);
}
WARN_ON(atomic_read(&q->owned_by_drv_count));
}
WARN_ON(!list_empty(&q->done_list));
return ret;
}
static int vb2_internal_qbuf(struct vb2_queue *q, struct v4l2_buffer *b)
{
int ret = vb2_queue_or_prepare_buf(q, b, "qbuf");
struct vb2_buffer *vb;
if (ret)
return ret;
vb = q->bufs[b->index];
switch (vb->state) {
case VB2_BUF_STATE_DEQUEUED:
ret = __buf_prepare(vb, b);
if (ret)
return ret;
break;
case VB2_BUF_STATE_PREPARED:
break;
case VB2_BUF_STATE_PREPARING:
dprintk(1, "buffer still being prepared\n");
return -EINVAL;
default:
dprintk(1, "invalid buffer state %d\n", vb->state);
return -EINVAL;
}
list_add_tail(&vb->queued_entry, &q->queued_list);
q->queued_count++;
q->waiting_for_buffers = false;
vb->state = VB2_BUF_STATE_QUEUED;
if (V4L2_TYPE_IS_OUTPUT(q->type)) {
if ((q->timestamp_flags & V4L2_BUF_FLAG_TIMESTAMP_MASK) ==
V4L2_BUF_FLAG_TIMESTAMP_COPY)
vb->v4l2_buf.timestamp = b->timestamp;
vb->v4l2_buf.flags |= b->flags & V4L2_BUF_FLAG_TIMECODE;
if (b->flags & V4L2_BUF_FLAG_TIMECODE)
vb->v4l2_buf.timecode = b->timecode;
}
if (q->start_streaming_called)
__enqueue_in_driver(vb);
__fill_v4l2_buffer(vb, b);
if (q->streaming && !q->start_streaming_called &&
q->queued_count >= q->min_buffers_needed) {
ret = vb2_start_streaming(q);
if (ret)
return ret;
}
dprintk(1, "qbuf of buffer %d succeeded\n", vb->v4l2_buf.index);
return 0;
}
int vb2_qbuf(struct vb2_queue *q, struct v4l2_buffer *b)
{
if (vb2_fileio_is_active(q)) {
dprintk(1, "file io in progress\n");
return -EBUSY;
}
return vb2_internal_qbuf(q, b);
}
static int __vb2_wait_for_done_vb(struct vb2_queue *q, int nonblocking)
{
for (;;) {
int ret;
if (!q->streaming) {
dprintk(1, "streaming off, will not wait for buffers\n");
return -EINVAL;
}
if (q->error) {
dprintk(1, "Queue in error state, will not wait for buffers\n");
return -EIO;
}
if (q->last_buffer_dequeued) {
dprintk(3, "last buffer dequeued already, will not wait for buffers\n");
return -EPIPE;
}
if (!list_empty(&q->done_list)) {
break;
}
if (nonblocking) {
dprintk(1, "nonblocking and no buffers to dequeue, "
"will not wait\n");
return -EAGAIN;
}
call_void_qop(q, wait_prepare, q);
dprintk(3, "will sleep waiting for buffers\n");
ret = wait_event_interruptible(q->done_wq,
!list_empty(&q->done_list) || !q->streaming ||
q->error);
call_void_qop(q, wait_finish, q);
if (ret) {
dprintk(1, "sleep was interrupted\n");
return ret;
}
}
return 0;
}
static int __vb2_get_done_vb(struct vb2_queue *q, struct vb2_buffer **vb,
struct v4l2_buffer *b, int nonblocking)
{
unsigned long flags;
int ret;
ret = __vb2_wait_for_done_vb(q, nonblocking);
if (ret)
return ret;
spin_lock_irqsave(&q->done_lock, flags);
*vb = list_first_entry(&q->done_list, struct vb2_buffer, done_entry);
ret = __verify_planes_array(*vb, b);
if (!ret)
list_del(&(*vb)->done_entry);
spin_unlock_irqrestore(&q->done_lock, flags);
return ret;
}
int vb2_wait_for_all_buffers(struct vb2_queue *q)
{
if (!q->streaming) {
dprintk(1, "streaming off, will not wait for buffers\n");
return -EINVAL;
}
if (q->start_streaming_called)
wait_event(q->done_wq, !atomic_read(&q->owned_by_drv_count));
return 0;
}
static void __vb2_dqbuf(struct vb2_buffer *vb)
{
struct vb2_queue *q = vb->vb2_queue;
unsigned int i;
if (vb->state == VB2_BUF_STATE_DEQUEUED)
return;
vb->state = VB2_BUF_STATE_DEQUEUED;
if (q->memory == V4L2_MEMORY_DMABUF)
for (i = 0; i < vb->num_planes; ++i) {
if (!vb->planes[i].dbuf_mapped)
continue;
call_void_memop(vb, unmap_dmabuf, vb->planes[i].mem_priv);
vb->planes[i].dbuf_mapped = 0;
}
}
static int vb2_internal_dqbuf(struct vb2_queue *q, struct v4l2_buffer *b, bool nonblocking)
{
struct vb2_buffer *vb = NULL;
int ret;
if (b->type != q->type) {
dprintk(1, "invalid buffer type\n");
return -EINVAL;
}
ret = __vb2_get_done_vb(q, &vb, b, nonblocking);
if (ret < 0)
return ret;
switch (vb->state) {
case VB2_BUF_STATE_DONE:
dprintk(3, "returning done buffer\n");
break;
case VB2_BUF_STATE_ERROR:
dprintk(3, "returning done buffer with errors\n");
break;
default:
dprintk(1, "invalid buffer state\n");
return -EINVAL;
}
call_void_vb_qop(vb, buf_finish, vb);
__fill_v4l2_buffer(vb, b);
list_del(&vb->queued_entry);
q->queued_count--;
if (!V4L2_TYPE_IS_OUTPUT(q->type) &&
vb->v4l2_buf.flags & V4L2_BUF_FLAG_LAST)
q->last_buffer_dequeued = true;
__vb2_dqbuf(vb);
dprintk(1, "dqbuf of buffer %d, with state %d\n",
vb->v4l2_buf.index, vb->state);
return 0;
}
int vb2_dqbuf(struct vb2_queue *q, struct v4l2_buffer *b, bool nonblocking)
{
if (vb2_fileio_is_active(q)) {
dprintk(1, "file io in progress\n");
return -EBUSY;
}
return vb2_internal_dqbuf(q, b, nonblocking);
}
static void __vb2_queue_cancel(struct vb2_queue *q)
{
unsigned int i;
if (q->start_streaming_called)
call_void_qop(q, stop_streaming, q);
if (WARN_ON(atomic_read(&q->owned_by_drv_count))) {
for (i = 0; i < q->num_buffers; ++i)
if (q->bufs[i]->state == VB2_BUF_STATE_ACTIVE)
vb2_buffer_done(q->bufs[i], VB2_BUF_STATE_ERROR);
WARN_ON(atomic_read(&q->owned_by_drv_count));
}
q->streaming = 0;
q->start_streaming_called = 0;
q->queued_count = 0;
q->error = 0;
INIT_LIST_HEAD(&q->queued_list);
INIT_LIST_HEAD(&q->done_list);
atomic_set(&q->owned_by_drv_count, 0);
wake_up_all(&q->done_wq);
for (i = 0; i < q->num_buffers; ++i) {
struct vb2_buffer *vb = q->bufs[i];
if (vb->state != VB2_BUF_STATE_DEQUEUED) {
vb->state = VB2_BUF_STATE_PREPARED;
call_void_vb_qop(vb, buf_finish, vb);
}
__vb2_dqbuf(vb);
}
}
static int vb2_internal_streamon(struct vb2_queue *q, enum v4l2_buf_type type)
{
int ret;
if (type != q->type) {
dprintk(1, "invalid stream type\n");
return -EINVAL;
}
if (q->streaming) {
dprintk(3, "already streaming\n");
return 0;
}
if (!q->num_buffers) {
dprintk(1, "no buffers have been allocated\n");
return -EINVAL;
}
if (q->num_buffers < q->min_buffers_needed) {
dprintk(1, "need at least %u allocated buffers\n",
q->min_buffers_needed);
return -EINVAL;
}
if (q->queued_count >= q->min_buffers_needed) {
ret = vb2_start_streaming(q);
if (ret) {
__vb2_queue_cancel(q);
return ret;
}
}
q->streaming = 1;
dprintk(3, "successful\n");
return 0;
}
void vb2_queue_error(struct vb2_queue *q)
{
q->error = 1;
wake_up_all(&q->done_wq);
}
int vb2_streamon(struct vb2_queue *q, enum v4l2_buf_type type)
{
if (vb2_fileio_is_active(q)) {
dprintk(1, "file io in progress\n");
return -EBUSY;
}
return vb2_internal_streamon(q, type);
}
static int vb2_internal_streamoff(struct vb2_queue *q, enum v4l2_buf_type type)
{
if (type != q->type) {
dprintk(1, "invalid stream type\n");
return -EINVAL;
}
__vb2_queue_cancel(q);
q->waiting_for_buffers = !V4L2_TYPE_IS_OUTPUT(q->type);
q->last_buffer_dequeued = false;
dprintk(3, "successful\n");
return 0;
}
int vb2_streamoff(struct vb2_queue *q, enum v4l2_buf_type type)
{
if (vb2_fileio_is_active(q)) {
dprintk(1, "file io in progress\n");
return -EBUSY;
}
return vb2_internal_streamoff(q, type);
}
static int __find_plane_by_offset(struct vb2_queue *q, unsigned long off,
unsigned int *_buffer, unsigned int *_plane)
{
struct vb2_buffer *vb;
unsigned int buffer, plane;
for (buffer = 0; buffer < q->num_buffers; ++buffer) {
vb = q->bufs[buffer];
for (plane = 0; plane < vb->num_planes; ++plane) {
if (vb->v4l2_planes[plane].m.mem_offset == off) {
*_buffer = buffer;
*_plane = plane;
return 0;
}
}
}
return -EINVAL;
}
int vb2_expbuf(struct vb2_queue *q, struct v4l2_exportbuffer *eb)
{
struct vb2_buffer *vb = NULL;
struct vb2_plane *vb_plane;
int ret;
struct dma_buf *dbuf;
if (q->memory != V4L2_MEMORY_MMAP) {
dprintk(1, "queue is not currently set up for mmap\n");
return -EINVAL;
}
if (!q->mem_ops->get_dmabuf) {
dprintk(1, "queue does not support DMA buffer exporting\n");
return -EINVAL;
}
if (eb->flags & ~(O_CLOEXEC | O_ACCMODE)) {
dprintk(1, "queue does support only O_CLOEXEC and access mode flags\n");
return -EINVAL;
}
if (eb->type != q->type) {
dprintk(1, "invalid buffer type\n");
return -EINVAL;
}
if (eb->index >= q->num_buffers) {
dprintk(1, "buffer index out of range\n");
return -EINVAL;
}
vb = q->bufs[eb->index];
if (eb->plane >= vb->num_planes) {
dprintk(1, "buffer plane out of range\n");
return -EINVAL;
}
if (vb2_fileio_is_active(q)) {
dprintk(1, "expbuf: file io in progress\n");
return -EBUSY;
}
vb_plane = &vb->planes[eb->plane];
dbuf = call_ptr_memop(vb, get_dmabuf, vb_plane->mem_priv, eb->flags & O_ACCMODE);
if (IS_ERR_OR_NULL(dbuf)) {
dprintk(1, "failed to export buffer %d, plane %d\n",
eb->index, eb->plane);
return -EINVAL;
}
ret = dma_buf_fd(dbuf, eb->flags & ~O_ACCMODE);
if (ret < 0) {
dprintk(3, "buffer %d, plane %d failed to export (%d)\n",
eb->index, eb->plane, ret);
dma_buf_put(dbuf);
return ret;
}
dprintk(3, "buffer %d, plane %d exported as %d descriptor\n",
eb->index, eb->plane, ret);
eb->fd = ret;
return 0;
}
int vb2_mmap(struct vb2_queue *q, struct vm_area_struct *vma)
{
unsigned long off = vma->vm_pgoff << PAGE_SHIFT;
struct vb2_buffer *vb;
unsigned int buffer = 0, plane = 0;
int ret;
unsigned long length;
if (q->memory != V4L2_MEMORY_MMAP) {
dprintk(1, "queue is not currently set up for mmap\n");
return -EINVAL;
}
if (!(vma->vm_flags & VM_SHARED)) {
dprintk(1, "invalid vma flags, VM_SHARED needed\n");
return -EINVAL;
}
if (V4L2_TYPE_IS_OUTPUT(q->type)) {
if (!(vma->vm_flags & VM_WRITE)) {
dprintk(1, "invalid vma flags, VM_WRITE needed\n");
return -EINVAL;
}
} else {
if (!(vma->vm_flags & VM_READ)) {
dprintk(1, "invalid vma flags, VM_READ needed\n");
return -EINVAL;
}
}
if (vb2_fileio_is_active(q)) {
dprintk(1, "mmap: file io in progress\n");
return -EBUSY;
}
ret = __find_plane_by_offset(q, off, &buffer, &plane);
if (ret)
return ret;
vb = q->bufs[buffer];
length = PAGE_ALIGN(vb->v4l2_planes[plane].length);
if (length < (vma->vm_end - vma->vm_start)) {
dprintk(1,
"MMAP invalid, as it would overflow buffer length\n");
return -EINVAL;
}
mutex_lock(&q->mmap_lock);
ret = call_memop(vb, mmap, vb->planes[plane].mem_priv, vma);
mutex_unlock(&q->mmap_lock);
if (ret)
return ret;
dprintk(3, "buffer %d, plane %d successfully mapped\n", buffer, plane);
return 0;
}
unsigned long vb2_get_unmapped_area(struct vb2_queue *q,
unsigned long addr,
unsigned long len,
unsigned long pgoff,
unsigned long flags)
{
unsigned long off = pgoff << PAGE_SHIFT;
struct vb2_buffer *vb;
unsigned int buffer, plane;
void *vaddr;
int ret;
if (q->memory != V4L2_MEMORY_MMAP) {
dprintk(1, "queue is not currently set up for mmap\n");
return -EINVAL;
}
ret = __find_plane_by_offset(q, off, &buffer, &plane);
if (ret)
return ret;
vb = q->bufs[buffer];
vaddr = vb2_plane_vaddr(vb, plane);
return vaddr ? (unsigned long)vaddr : -EINVAL;
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
if (!V4L2_TYPE_IS_OUTPUT(q->type) && !(req_events & (POLLIN | POLLRDNORM)))
return res;
if (V4L2_TYPE_IS_OUTPUT(q->type) && !(req_events & (POLLOUT | POLLWRNORM)))
return res;
if (q->num_buffers == 0 && !vb2_fileio_is_active(q)) {
if (!V4L2_TYPE_IS_OUTPUT(q->type) && (q->io_modes & VB2_READ) &&
(req_events & (POLLIN | POLLRDNORM))) {
if (__vb2_init_fileio(q, 1))
return res | POLLERR;
}
if (V4L2_TYPE_IS_OUTPUT(q->type) && (q->io_modes & VB2_WRITE) &&
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
if (V4L2_TYPE_IS_OUTPUT(q->type) && q->queued_count < q->num_buffers)
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
return (V4L2_TYPE_IS_OUTPUT(q->type)) ?
res | POLLOUT | POLLWRNORM :
res | POLLIN | POLLRDNORM;
}
return res;
}
int vb2_queue_init(struct vb2_queue *q)
{
if (WARN_ON(!q) ||
WARN_ON(!q->ops) ||
WARN_ON(!q->mem_ops) ||
WARN_ON(!q->type) ||
WARN_ON(!q->io_modes) ||
WARN_ON(!q->ops->queue_setup) ||
WARN_ON(!q->ops->buf_queue) ||
WARN_ON(q->timestamp_flags &
~(V4L2_BUF_FLAG_TIMESTAMP_MASK |
V4L2_BUF_FLAG_TSTAMP_SRC_MASK)))
return -EINVAL;
WARN_ON((q->timestamp_flags & V4L2_BUF_FLAG_TIMESTAMP_MASK) ==
V4L2_BUF_FLAG_TIMESTAMP_UNKNOWN);
INIT_LIST_HEAD(&q->queued_list);
INIT_LIST_HEAD(&q->done_list);
spin_lock_init(&q->done_lock);
mutex_init(&q->mmap_lock);
init_waitqueue_head(&q->done_wq);
if (q->buf_struct_size == 0)
q->buf_struct_size = sizeof(struct vb2_buffer);
return 0;
}
void vb2_queue_release(struct vb2_queue *q)
{
__vb2_cleanup_fileio(q);
__vb2_queue_cancel(q);
mutex_lock(&q->mmap_lock);
__vb2_queue_free(q, q->num_buffers);
mutex_unlock(&q->mmap_lock);
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
fileio->req.memory = V4L2_MEMORY_MMAP;
fileio->req.type = q->type;
q->fileio = fileio;
ret = __reqbufs(q, &fileio->req);
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
bool is_multiplanar = V4L2_TYPE_IS_MULTIPLANAR(q->type);
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
ret = vb2_internal_streamon(q, q->type);
if (ret)
goto err_reqbufs;
return ret;
err_reqbufs:
fileio->req.count = 0;
__reqbufs(q, &fileio->req);
err_kfree:
q->fileio = NULL;
kfree(fileio);
return ret;
}
static int __vb2_cleanup_fileio(struct vb2_queue *q)
{
struct vb2_fileio_data *fileio = q->fileio;
if (fileio) {
vb2_internal_streamoff(q, q->type);
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
bool is_multiplanar = V4L2_TYPE_IS_MULTIPLANAR(q->type);
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
if (V4L2_TYPE_IS_OUTPUT(q->type)) {
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
ret = __vb2_init_fileio(q, !V4L2_TYPE_IS_OUTPUT(q->type));
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
int res = __verify_memory_type(vdev->queue, p->memory, p->type);
if (res)
return res;
if (vb2_queue_is_busy(vdev, file))
return -EBUSY;
res = __reqbufs(vdev->queue, p);
if (res == 0)
vdev->queue->owner = p->count ? file->private_data : NULL;
return res;
}
int vb2_ioctl_create_bufs(struct file *file, void *priv,
struct v4l2_create_buffers *p)
{
struct video_device *vdev = video_devdata(file);
int res = __verify_memory_type(vdev->queue, p->memory, p->format.type);
p->index = vdev->queue->num_buffers;
if (p->count == 0)
return res != -EBUSY ? res : 0;
if (res)
return res;
if (vb2_queue_is_busy(vdev, file))
return -EBUSY;
res = __create_bufs(vdev->queue, p);
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
