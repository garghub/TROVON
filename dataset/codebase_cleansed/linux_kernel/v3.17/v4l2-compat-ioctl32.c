static long native_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
long ret = -ENOIOCTLCMD;
if (file->f_op->unlocked_ioctl)
ret = file->f_op->unlocked_ioctl(file, cmd, arg);
return ret;
}
static int get_v4l2_window32(struct v4l2_window *kp, struct v4l2_window32 __user *up)
{
if (!access_ok(VERIFY_READ, up, sizeof(struct v4l2_window32)) ||
copy_from_user(&kp->w, &up->w, sizeof(up->w)) ||
get_user(kp->field, &up->field) ||
get_user(kp->chromakey, &up->chromakey) ||
get_user(kp->clipcount, &up->clipcount))
return -EFAULT;
if (kp->clipcount > 2048)
return -EINVAL;
if (kp->clipcount) {
struct v4l2_clip32 __user *uclips;
struct v4l2_clip __user *kclips;
int n = kp->clipcount;
compat_caddr_t p;
if (get_user(p, &up->clips))
return -EFAULT;
uclips = compat_ptr(p);
kclips = compat_alloc_user_space(n * sizeof(struct v4l2_clip));
kp->clips = kclips;
while (--n >= 0) {
if (copy_in_user(&kclips->c, &uclips->c, sizeof(uclips->c)))
return -EFAULT;
if (put_user(n ? kclips + 1 : NULL, &kclips->next))
return -EFAULT;
uclips += 1;
kclips += 1;
}
} else
kp->clips = NULL;
return 0;
}
static int put_v4l2_window32(struct v4l2_window *kp, struct v4l2_window32 __user *up)
{
if (copy_to_user(&up->w, &kp->w, sizeof(kp->w)) ||
put_user(kp->field, &up->field) ||
put_user(kp->chromakey, &up->chromakey) ||
put_user(kp->clipcount, &up->clipcount))
return -EFAULT;
return 0;
}
static inline int get_v4l2_pix_format(struct v4l2_pix_format *kp, struct v4l2_pix_format __user *up)
{
if (copy_from_user(kp, up, sizeof(struct v4l2_pix_format)))
return -EFAULT;
return 0;
}
static inline int get_v4l2_pix_format_mplane(struct v4l2_pix_format_mplane *kp,
struct v4l2_pix_format_mplane __user *up)
{
if (copy_from_user(kp, up, sizeof(struct v4l2_pix_format_mplane)))
return -EFAULT;
return 0;
}
static inline int put_v4l2_pix_format(struct v4l2_pix_format *kp, struct v4l2_pix_format __user *up)
{
if (copy_to_user(up, kp, sizeof(struct v4l2_pix_format)))
return -EFAULT;
return 0;
}
static inline int put_v4l2_pix_format_mplane(struct v4l2_pix_format_mplane *kp,
struct v4l2_pix_format_mplane __user *up)
{
if (copy_to_user(up, kp, sizeof(struct v4l2_pix_format_mplane)))
return -EFAULT;
return 0;
}
static inline int get_v4l2_vbi_format(struct v4l2_vbi_format *kp, struct v4l2_vbi_format __user *up)
{
if (copy_from_user(kp, up, sizeof(struct v4l2_vbi_format)))
return -EFAULT;
return 0;
}
static inline int put_v4l2_vbi_format(struct v4l2_vbi_format *kp, struct v4l2_vbi_format __user *up)
{
if (copy_to_user(up, kp, sizeof(struct v4l2_vbi_format)))
return -EFAULT;
return 0;
}
static inline int get_v4l2_sliced_vbi_format(struct v4l2_sliced_vbi_format *kp, struct v4l2_sliced_vbi_format __user *up)
{
if (copy_from_user(kp, up, sizeof(struct v4l2_sliced_vbi_format)))
return -EFAULT;
return 0;
}
static inline int put_v4l2_sliced_vbi_format(struct v4l2_sliced_vbi_format *kp, struct v4l2_sliced_vbi_format __user *up)
{
if (copy_to_user(up, kp, sizeof(struct v4l2_sliced_vbi_format)))
return -EFAULT;
return 0;
}
static int __get_v4l2_format32(struct v4l2_format *kp, struct v4l2_format32 __user *up)
{
if (get_user(kp->type, &up->type))
return -EFAULT;
switch (kp->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
case V4L2_BUF_TYPE_VIDEO_OUTPUT:
return get_v4l2_pix_format(&kp->fmt.pix, &up->fmt.pix);
case V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE:
case V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE:
return get_v4l2_pix_format_mplane(&kp->fmt.pix_mp,
&up->fmt.pix_mp);
case V4L2_BUF_TYPE_VIDEO_OVERLAY:
case V4L2_BUF_TYPE_VIDEO_OUTPUT_OVERLAY:
return get_v4l2_window32(&kp->fmt.win, &up->fmt.win);
case V4L2_BUF_TYPE_VBI_CAPTURE:
case V4L2_BUF_TYPE_VBI_OUTPUT:
return get_v4l2_vbi_format(&kp->fmt.vbi, &up->fmt.vbi);
case V4L2_BUF_TYPE_SLICED_VBI_CAPTURE:
case V4L2_BUF_TYPE_SLICED_VBI_OUTPUT:
return get_v4l2_sliced_vbi_format(&kp->fmt.sliced, &up->fmt.sliced);
default:
printk(KERN_INFO "compat_ioctl32: unexpected VIDIOC_FMT type %d\n",
kp->type);
return -EINVAL;
}
}
static int get_v4l2_format32(struct v4l2_format *kp, struct v4l2_format32 __user *up)
{
if (!access_ok(VERIFY_READ, up, sizeof(struct v4l2_format32)))
return -EFAULT;
return __get_v4l2_format32(kp, up);
}
static int get_v4l2_create32(struct v4l2_create_buffers *kp, struct v4l2_create_buffers32 __user *up)
{
if (!access_ok(VERIFY_READ, up, sizeof(struct v4l2_create_buffers32)) ||
copy_from_user(kp, up, offsetof(struct v4l2_create_buffers32, format)))
return -EFAULT;
return __get_v4l2_format32(&kp->format, &up->format);
}
static int __put_v4l2_format32(struct v4l2_format *kp, struct v4l2_format32 __user *up)
{
switch (kp->type) {
case V4L2_BUF_TYPE_VIDEO_CAPTURE:
case V4L2_BUF_TYPE_VIDEO_OUTPUT:
return put_v4l2_pix_format(&kp->fmt.pix, &up->fmt.pix);
case V4L2_BUF_TYPE_VIDEO_CAPTURE_MPLANE:
case V4L2_BUF_TYPE_VIDEO_OUTPUT_MPLANE:
return put_v4l2_pix_format_mplane(&kp->fmt.pix_mp,
&up->fmt.pix_mp);
case V4L2_BUF_TYPE_VIDEO_OVERLAY:
case V4L2_BUF_TYPE_VIDEO_OUTPUT_OVERLAY:
return put_v4l2_window32(&kp->fmt.win, &up->fmt.win);
case V4L2_BUF_TYPE_VBI_CAPTURE:
case V4L2_BUF_TYPE_VBI_OUTPUT:
return put_v4l2_vbi_format(&kp->fmt.vbi, &up->fmt.vbi);
case V4L2_BUF_TYPE_SLICED_VBI_CAPTURE:
case V4L2_BUF_TYPE_SLICED_VBI_OUTPUT:
return put_v4l2_sliced_vbi_format(&kp->fmt.sliced, &up->fmt.sliced);
default:
printk(KERN_INFO "compat_ioctl32: unexpected VIDIOC_FMT type %d\n",
kp->type);
return -EINVAL;
}
}
static int put_v4l2_format32(struct v4l2_format *kp, struct v4l2_format32 __user *up)
{
if (!access_ok(VERIFY_WRITE, up, sizeof(struct v4l2_format32)) ||
put_user(kp->type, &up->type))
return -EFAULT;
return __put_v4l2_format32(kp, up);
}
static int put_v4l2_create32(struct v4l2_create_buffers *kp, struct v4l2_create_buffers32 __user *up)
{
if (!access_ok(VERIFY_WRITE, up, sizeof(struct v4l2_create_buffers32)) ||
copy_to_user(up, kp, offsetof(struct v4l2_create_buffers32, format.fmt)))
return -EFAULT;
return __put_v4l2_format32(&kp->format, &up->format);
}
static int get_v4l2_standard32(struct v4l2_standard *kp, struct v4l2_standard32 __user *up)
{
if (!access_ok(VERIFY_READ, up, sizeof(struct v4l2_standard32)) ||
get_user(kp->index, &up->index))
return -EFAULT;
return 0;
}
static int put_v4l2_standard32(struct v4l2_standard *kp, struct v4l2_standard32 __user *up)
{
if (!access_ok(VERIFY_WRITE, up, sizeof(struct v4l2_standard32)) ||
put_user(kp->index, &up->index) ||
copy_to_user(up->id, &kp->id, sizeof(__u64)) ||
copy_to_user(up->name, kp->name, 24) ||
copy_to_user(&up->frameperiod, &kp->frameperiod, sizeof(kp->frameperiod)) ||
put_user(kp->framelines, &up->framelines) ||
copy_to_user(up->reserved, kp->reserved, 4 * sizeof(__u32)))
return -EFAULT;
return 0;
}
static int get_v4l2_plane32(struct v4l2_plane *up, struct v4l2_plane32 *up32,
enum v4l2_memory memory)
{
void __user *up_pln;
compat_long_t p;
if (copy_in_user(up, up32, 2 * sizeof(__u32)) ||
copy_in_user(&up->data_offset, &up32->data_offset,
sizeof(__u32)))
return -EFAULT;
if (memory == V4L2_MEMORY_USERPTR) {
if (get_user(p, &up32->m.userptr))
return -EFAULT;
up_pln = compat_ptr(p);
if (put_user((unsigned long)up_pln, &up->m.userptr))
return -EFAULT;
} else if (memory == V4L2_MEMORY_DMABUF) {
if (copy_in_user(&up->m.fd, &up32->m.fd, sizeof(int)))
return -EFAULT;
} else {
if (copy_in_user(&up->m.mem_offset, &up32->m.mem_offset,
sizeof(__u32)))
return -EFAULT;
}
return 0;
}
static int put_v4l2_plane32(struct v4l2_plane *up, struct v4l2_plane32 *up32,
enum v4l2_memory memory)
{
if (copy_in_user(up32, up, 2 * sizeof(__u32)) ||
copy_in_user(&up32->data_offset, &up->data_offset,
sizeof(__u32)))
return -EFAULT;
if (memory == V4L2_MEMORY_MMAP)
if (copy_in_user(&up32->m.mem_offset, &up->m.mem_offset,
sizeof(__u32)))
return -EFAULT;
if (memory == V4L2_MEMORY_DMABUF)
if (copy_in_user(&up32->m.fd, &up->m.fd,
sizeof(int)))
return -EFAULT;
return 0;
}
static int get_v4l2_buffer32(struct v4l2_buffer *kp, struct v4l2_buffer32 __user *up)
{
struct v4l2_plane32 __user *uplane32;
struct v4l2_plane __user *uplane;
compat_caddr_t p;
int num_planes;
int ret;
if (!access_ok(VERIFY_READ, up, sizeof(struct v4l2_buffer32)) ||
get_user(kp->index, &up->index) ||
get_user(kp->type, &up->type) ||
get_user(kp->flags, &up->flags) ||
get_user(kp->memory, &up->memory))
return -EFAULT;
if (V4L2_TYPE_IS_OUTPUT(kp->type))
if (get_user(kp->bytesused, &up->bytesused) ||
get_user(kp->field, &up->field) ||
get_user(kp->timestamp.tv_sec, &up->timestamp.tv_sec) ||
get_user(kp->timestamp.tv_usec,
&up->timestamp.tv_usec))
return -EFAULT;
if (V4L2_TYPE_IS_MULTIPLANAR(kp->type)) {
if (get_user(kp->length, &up->length))
return -EFAULT;
num_planes = kp->length;
if (num_planes == 0) {
kp->m.planes = NULL;
return 0;
}
if (get_user(p, &up->m.planes))
return -EFAULT;
uplane32 = compat_ptr(p);
if (!access_ok(VERIFY_READ, uplane32,
num_planes * sizeof(struct v4l2_plane32)))
return -EFAULT;
uplane = compat_alloc_user_space(num_planes *
sizeof(struct v4l2_plane));
kp->m.planes = uplane;
while (--num_planes >= 0) {
ret = get_v4l2_plane32(uplane, uplane32, kp->memory);
if (ret)
return ret;
++uplane;
++uplane32;
}
} else {
switch (kp->memory) {
case V4L2_MEMORY_MMAP:
if (get_user(kp->length, &up->length) ||
get_user(kp->m.offset, &up->m.offset))
return -EFAULT;
break;
case V4L2_MEMORY_USERPTR:
{
compat_long_t tmp;
if (get_user(kp->length, &up->length) ||
get_user(tmp, &up->m.userptr))
return -EFAULT;
kp->m.userptr = (unsigned long)compat_ptr(tmp);
}
break;
case V4L2_MEMORY_OVERLAY:
if (get_user(kp->m.offset, &up->m.offset))
return -EFAULT;
break;
case V4L2_MEMORY_DMABUF:
if (get_user(kp->m.fd, &up->m.fd))
return -EFAULT;
break;
}
}
return 0;
}
static int put_v4l2_buffer32(struct v4l2_buffer *kp, struct v4l2_buffer32 __user *up)
{
struct v4l2_plane32 __user *uplane32;
struct v4l2_plane __user *uplane;
compat_caddr_t p;
int num_planes;
int ret;
if (!access_ok(VERIFY_WRITE, up, sizeof(struct v4l2_buffer32)) ||
put_user(kp->index, &up->index) ||
put_user(kp->type, &up->type) ||
put_user(kp->flags, &up->flags) ||
put_user(kp->memory, &up->memory))
return -EFAULT;
if (put_user(kp->bytesused, &up->bytesused) ||
put_user(kp->field, &up->field) ||
put_user(kp->timestamp.tv_sec, &up->timestamp.tv_sec) ||
put_user(kp->timestamp.tv_usec, &up->timestamp.tv_usec) ||
copy_to_user(&up->timecode, &kp->timecode, sizeof(struct v4l2_timecode)) ||
put_user(kp->sequence, &up->sequence) ||
put_user(kp->reserved2, &up->reserved2) ||
put_user(kp->reserved, &up->reserved))
return -EFAULT;
if (V4L2_TYPE_IS_MULTIPLANAR(kp->type)) {
num_planes = kp->length;
if (num_planes == 0)
return 0;
uplane = kp->m.planes;
if (get_user(p, &up->m.planes))
return -EFAULT;
uplane32 = compat_ptr(p);
while (--num_planes >= 0) {
ret = put_v4l2_plane32(uplane, uplane32, kp->memory);
if (ret)
return ret;
++uplane;
++uplane32;
}
} else {
switch (kp->memory) {
case V4L2_MEMORY_MMAP:
if (put_user(kp->length, &up->length) ||
put_user(kp->m.offset, &up->m.offset))
return -EFAULT;
break;
case V4L2_MEMORY_USERPTR:
if (put_user(kp->length, &up->length) ||
put_user(kp->m.userptr, &up->m.userptr))
return -EFAULT;
break;
case V4L2_MEMORY_OVERLAY:
if (put_user(kp->m.offset, &up->m.offset))
return -EFAULT;
break;
case V4L2_MEMORY_DMABUF:
if (put_user(kp->m.fd, &up->m.fd))
return -EFAULT;
break;
}
}
return 0;
}
static int get_v4l2_framebuffer32(struct v4l2_framebuffer *kp, struct v4l2_framebuffer32 __user *up)
{
u32 tmp;
if (!access_ok(VERIFY_READ, up, sizeof(struct v4l2_framebuffer32)) ||
get_user(tmp, &up->base) ||
get_user(kp->capability, &up->capability) ||
get_user(kp->flags, &up->flags) ||
copy_from_user(&kp->fmt, &up->fmt, sizeof(up->fmt)))
return -EFAULT;
kp->base = compat_ptr(tmp);
return 0;
}
static int put_v4l2_framebuffer32(struct v4l2_framebuffer *kp, struct v4l2_framebuffer32 __user *up)
{
u32 tmp = (u32)((unsigned long)kp->base);
if (!access_ok(VERIFY_WRITE, up, sizeof(struct v4l2_framebuffer32)) ||
put_user(tmp, &up->base) ||
put_user(kp->capability, &up->capability) ||
put_user(kp->flags, &up->flags) ||
copy_to_user(&up->fmt, &kp->fmt, sizeof(up->fmt)))
return -EFAULT;
return 0;
}
static inline int get_v4l2_input32(struct v4l2_input *kp, struct v4l2_input32 __user *up)
{
if (copy_from_user(kp, up, sizeof(struct v4l2_input32)))
return -EFAULT;
return 0;
}
static inline int put_v4l2_input32(struct v4l2_input *kp, struct v4l2_input32 __user *up)
{
if (copy_to_user(up, kp, sizeof(struct v4l2_input32)))
return -EFAULT;
return 0;
}
static inline int ctrl_is_pointer(u32 id)
{
switch (id) {
case V4L2_CID_RDS_TX_PS_NAME:
case V4L2_CID_RDS_TX_RADIO_TEXT:
return 1;
default:
return 0;
}
}
static int get_v4l2_ext_controls32(struct v4l2_ext_controls *kp, struct v4l2_ext_controls32 __user *up)
{
struct v4l2_ext_control32 __user *ucontrols;
struct v4l2_ext_control __user *kcontrols;
int n;
compat_caddr_t p;
if (!access_ok(VERIFY_READ, up, sizeof(struct v4l2_ext_controls32)) ||
get_user(kp->ctrl_class, &up->ctrl_class) ||
get_user(kp->count, &up->count) ||
get_user(kp->error_idx, &up->error_idx) ||
copy_from_user(kp->reserved, up->reserved, sizeof(kp->reserved)))
return -EFAULT;
n = kp->count;
if (n == 0) {
kp->controls = NULL;
return 0;
}
if (get_user(p, &up->controls))
return -EFAULT;
ucontrols = compat_ptr(p);
if (!access_ok(VERIFY_READ, ucontrols,
n * sizeof(struct v4l2_ext_control32)))
return -EFAULT;
kcontrols = compat_alloc_user_space(n * sizeof(struct v4l2_ext_control));
kp->controls = kcontrols;
while (--n >= 0) {
if (copy_in_user(kcontrols, ucontrols, sizeof(*ucontrols)))
return -EFAULT;
if (ctrl_is_pointer(kcontrols->id)) {
void __user *s;
if (get_user(p, &ucontrols->string))
return -EFAULT;
s = compat_ptr(p);
if (put_user(s, &kcontrols->string))
return -EFAULT;
}
ucontrols++;
kcontrols++;
}
return 0;
}
static int put_v4l2_ext_controls32(struct v4l2_ext_controls *kp, struct v4l2_ext_controls32 __user *up)
{
struct v4l2_ext_control32 __user *ucontrols;
struct v4l2_ext_control __user *kcontrols = kp->controls;
int n = kp->count;
compat_caddr_t p;
if (!access_ok(VERIFY_WRITE, up, sizeof(struct v4l2_ext_controls32)) ||
put_user(kp->ctrl_class, &up->ctrl_class) ||
put_user(kp->count, &up->count) ||
put_user(kp->error_idx, &up->error_idx) ||
copy_to_user(up->reserved, kp->reserved, sizeof(up->reserved)))
return -EFAULT;
if (!kp->count)
return 0;
if (get_user(p, &up->controls))
return -EFAULT;
ucontrols = compat_ptr(p);
if (!access_ok(VERIFY_WRITE, ucontrols,
n * sizeof(struct v4l2_ext_control32)))
return -EFAULT;
while (--n >= 0) {
unsigned size = sizeof(*ucontrols);
if (ctrl_is_pointer(kcontrols->id))
size -= sizeof(ucontrols->value64);
if (copy_in_user(ucontrols, kcontrols, size))
return -EFAULT;
ucontrols++;
kcontrols++;
}
return 0;
}
static int put_v4l2_event32(struct v4l2_event *kp, struct v4l2_event32 __user *up)
{
if (!access_ok(VERIFY_WRITE, up, sizeof(struct v4l2_event32)) ||
put_user(kp->type, &up->type) ||
copy_to_user(&up->u, &kp->u, sizeof(kp->u)) ||
put_user(kp->pending, &up->pending) ||
put_user(kp->sequence, &up->sequence) ||
compat_put_timespec(&kp->timestamp, &up->timestamp) ||
put_user(kp->id, &up->id) ||
copy_to_user(up->reserved, kp->reserved, 8 * sizeof(__u32)))
return -EFAULT;
return 0;
}
static int get_v4l2_edid32(struct v4l2_edid *kp, struct v4l2_edid32 __user *up)
{
u32 tmp;
if (!access_ok(VERIFY_READ, up, sizeof(struct v4l2_edid32)) ||
get_user(kp->pad, &up->pad) ||
get_user(kp->start_block, &up->start_block) ||
get_user(kp->blocks, &up->blocks) ||
get_user(tmp, &up->edid) ||
copy_from_user(kp->reserved, up->reserved, sizeof(kp->reserved)))
return -EFAULT;
kp->edid = compat_ptr(tmp);
return 0;
}
static int put_v4l2_edid32(struct v4l2_edid *kp, struct v4l2_edid32 __user *up)
{
u32 tmp = (u32)((unsigned long)kp->edid);
if (!access_ok(VERIFY_WRITE, up, sizeof(struct v4l2_edid32)) ||
put_user(kp->pad, &up->pad) ||
put_user(kp->start_block, &up->start_block) ||
put_user(kp->blocks, &up->blocks) ||
put_user(tmp, &up->edid) ||
copy_to_user(kp->reserved, up->reserved, sizeof(kp->reserved)))
return -EFAULT;
return 0;
}
static long do_video_ioctl(struct file *file, unsigned int cmd, unsigned long arg)
{
union {
struct v4l2_format v2f;
struct v4l2_buffer v2b;
struct v4l2_framebuffer v2fb;
struct v4l2_input v2i;
struct v4l2_standard v2s;
struct v4l2_ext_controls v2ecs;
struct v4l2_event v2ev;
struct v4l2_create_buffers v2crt;
struct v4l2_edid v2edid;
unsigned long vx;
int vi;
} karg;
void __user *up = compat_ptr(arg);
int compatible_arg = 1;
long err = 0;
switch (cmd) {
case VIDIOC_G_FMT32: cmd = VIDIOC_G_FMT; break;
case VIDIOC_S_FMT32: cmd = VIDIOC_S_FMT; break;
case VIDIOC_QUERYBUF32: cmd = VIDIOC_QUERYBUF; break;
case VIDIOC_G_FBUF32: cmd = VIDIOC_G_FBUF; break;
case VIDIOC_S_FBUF32: cmd = VIDIOC_S_FBUF; break;
case VIDIOC_QBUF32: cmd = VIDIOC_QBUF; break;
case VIDIOC_DQBUF32: cmd = VIDIOC_DQBUF; break;
case VIDIOC_ENUMSTD32: cmd = VIDIOC_ENUMSTD; break;
case VIDIOC_ENUMINPUT32: cmd = VIDIOC_ENUMINPUT; break;
case VIDIOC_TRY_FMT32: cmd = VIDIOC_TRY_FMT; break;
case VIDIOC_G_EXT_CTRLS32: cmd = VIDIOC_G_EXT_CTRLS; break;
case VIDIOC_S_EXT_CTRLS32: cmd = VIDIOC_S_EXT_CTRLS; break;
case VIDIOC_TRY_EXT_CTRLS32: cmd = VIDIOC_TRY_EXT_CTRLS; break;
case VIDIOC_DQEVENT32: cmd = VIDIOC_DQEVENT; break;
case VIDIOC_OVERLAY32: cmd = VIDIOC_OVERLAY; break;
case VIDIOC_STREAMON32: cmd = VIDIOC_STREAMON; break;
case VIDIOC_STREAMOFF32: cmd = VIDIOC_STREAMOFF; break;
case VIDIOC_G_INPUT32: cmd = VIDIOC_G_INPUT; break;
case VIDIOC_S_INPUT32: cmd = VIDIOC_S_INPUT; break;
case VIDIOC_G_OUTPUT32: cmd = VIDIOC_G_OUTPUT; break;
case VIDIOC_S_OUTPUT32: cmd = VIDIOC_S_OUTPUT; break;
case VIDIOC_CREATE_BUFS32: cmd = VIDIOC_CREATE_BUFS; break;
case VIDIOC_PREPARE_BUF32: cmd = VIDIOC_PREPARE_BUF; break;
case VIDIOC_G_EDID32: cmd = VIDIOC_G_EDID; break;
case VIDIOC_S_EDID32: cmd = VIDIOC_S_EDID; break;
}
switch (cmd) {
case VIDIOC_OVERLAY:
case VIDIOC_STREAMON:
case VIDIOC_STREAMOFF:
case VIDIOC_S_INPUT:
case VIDIOC_S_OUTPUT:
err = get_user(karg.vi, (s32 __user *)up);
compatible_arg = 0;
break;
case VIDIOC_G_INPUT:
case VIDIOC_G_OUTPUT:
compatible_arg = 0;
break;
case VIDIOC_G_EDID:
case VIDIOC_S_EDID:
err = get_v4l2_edid32(&karg.v2edid, up);
compatible_arg = 0;
break;
case VIDIOC_G_FMT:
case VIDIOC_S_FMT:
case VIDIOC_TRY_FMT:
err = get_v4l2_format32(&karg.v2f, up);
compatible_arg = 0;
break;
case VIDIOC_CREATE_BUFS:
err = get_v4l2_create32(&karg.v2crt, up);
compatible_arg = 0;
break;
case VIDIOC_PREPARE_BUF:
case VIDIOC_QUERYBUF:
case VIDIOC_QBUF:
case VIDIOC_DQBUF:
err = get_v4l2_buffer32(&karg.v2b, up);
compatible_arg = 0;
break;
case VIDIOC_S_FBUF:
err = get_v4l2_framebuffer32(&karg.v2fb, up);
compatible_arg = 0;
break;
case VIDIOC_G_FBUF:
compatible_arg = 0;
break;
case VIDIOC_ENUMSTD:
err = get_v4l2_standard32(&karg.v2s, up);
compatible_arg = 0;
break;
case VIDIOC_ENUMINPUT:
err = get_v4l2_input32(&karg.v2i, up);
compatible_arg = 0;
break;
case VIDIOC_G_EXT_CTRLS:
case VIDIOC_S_EXT_CTRLS:
case VIDIOC_TRY_EXT_CTRLS:
err = get_v4l2_ext_controls32(&karg.v2ecs, up);
compatible_arg = 0;
break;
case VIDIOC_DQEVENT:
compatible_arg = 0;
break;
}
if (err)
return err;
if (compatible_arg)
err = native_ioctl(file, cmd, (unsigned long)up);
else {
mm_segment_t old_fs = get_fs();
set_fs(KERNEL_DS);
err = native_ioctl(file, cmd, (unsigned long)&karg);
set_fs(old_fs);
}
switch (cmd) {
case VIDIOC_G_EXT_CTRLS:
case VIDIOC_S_EXT_CTRLS:
case VIDIOC_TRY_EXT_CTRLS:
if (put_v4l2_ext_controls32(&karg.v2ecs, up))
err = -EFAULT;
break;
}
if (err)
return err;
switch (cmd) {
case VIDIOC_S_INPUT:
case VIDIOC_S_OUTPUT:
case VIDIOC_G_INPUT:
case VIDIOC_G_OUTPUT:
err = put_user(((s32)karg.vi), (s32 __user *)up);
break;
case VIDIOC_G_FBUF:
err = put_v4l2_framebuffer32(&karg.v2fb, up);
break;
case VIDIOC_DQEVENT:
err = put_v4l2_event32(&karg.v2ev, up);
break;
case VIDIOC_G_EDID:
case VIDIOC_S_EDID:
err = put_v4l2_edid32(&karg.v2edid, up);
break;
case VIDIOC_G_FMT:
case VIDIOC_S_FMT:
case VIDIOC_TRY_FMT:
err = put_v4l2_format32(&karg.v2f, up);
break;
case VIDIOC_CREATE_BUFS:
err = put_v4l2_create32(&karg.v2crt, up);
break;
case VIDIOC_QUERYBUF:
case VIDIOC_QBUF:
case VIDIOC_DQBUF:
err = put_v4l2_buffer32(&karg.v2b, up);
break;
case VIDIOC_ENUMSTD:
err = put_v4l2_standard32(&karg.v2s, up);
break;
case VIDIOC_ENUMINPUT:
err = put_v4l2_input32(&karg.v2i, up);
break;
}
return err;
}
long v4l2_compat_ioctl32(struct file *file, unsigned int cmd, unsigned long arg)
{
struct video_device *vdev = video_devdata(file);
long ret = -ENOIOCTLCMD;
if (!file->f_op->unlocked_ioctl)
return ret;
if (_IOC_TYPE(cmd) == 'V' && _IOC_NR(cmd) < BASE_VIDIOC_PRIVATE)
ret = do_video_ioctl(file, cmd, arg);
else if (vdev->fops->compat_ioctl32)
ret = vdev->fops->compat_ioctl32(file, cmd, arg);
if (ret == -ENOIOCTLCMD)
pr_warn("compat_ioctl32: unknown ioctl '%c', dir=%d, #%d (0x%08x)\n",
_IOC_TYPE(cmd), _IOC_DIR(cmd), _IOC_NR(cmd), cmd);
return ret;
}
