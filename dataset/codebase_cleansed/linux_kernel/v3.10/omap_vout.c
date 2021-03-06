static int omap_vout_try_format(struct v4l2_pix_format *pix)
{
int ifmt, bpp = 0;
pix->height = clamp(pix->height, (u32)VID_MIN_HEIGHT,
(u32)VID_MAX_HEIGHT);
pix->width = clamp(pix->width, (u32)VID_MIN_WIDTH, (u32)VID_MAX_WIDTH);
for (ifmt = 0; ifmt < NUM_OUTPUT_FORMATS; ifmt++) {
if (pix->pixelformat == omap_formats[ifmt].pixelformat)
break;
}
if (ifmt == NUM_OUTPUT_FORMATS)
ifmt = 0;
pix->pixelformat = omap_formats[ifmt].pixelformat;
pix->field = V4L2_FIELD_ANY;
pix->priv = 0;
switch (pix->pixelformat) {
case V4L2_PIX_FMT_YUYV:
case V4L2_PIX_FMT_UYVY:
default:
pix->colorspace = V4L2_COLORSPACE_JPEG;
bpp = YUYV_BPP;
break;
case V4L2_PIX_FMT_RGB565:
case V4L2_PIX_FMT_RGB565X:
pix->colorspace = V4L2_COLORSPACE_SRGB;
bpp = RGB565_BPP;
break;
case V4L2_PIX_FMT_RGB24:
pix->colorspace = V4L2_COLORSPACE_SRGB;
bpp = RGB24_BPP;
break;
case V4L2_PIX_FMT_RGB32:
case V4L2_PIX_FMT_BGR32:
pix->colorspace = V4L2_COLORSPACE_SRGB;
bpp = RGB32_BPP;
break;
}
pix->bytesperline = pix->width * bpp;
pix->sizeimage = pix->bytesperline * pix->height;
return bpp;
}
static u32 omap_vout_uservirt_to_phys(u32 virtp)
{
unsigned long physp = 0;
struct vm_area_struct *vma;
struct mm_struct *mm = current->mm;
if (virtp >= PAGE_OFFSET)
return virt_to_phys((void *) virtp);
down_read(&current->mm->mmap_sem);
vma = find_vma(mm, virtp);
if (vma && (vma->vm_flags & VM_IO) && vma->vm_pgoff) {
physp = (vma->vm_pgoff << PAGE_SHIFT) + (virtp - vma->vm_start);
up_read(&current->mm->mmap_sem);
} else {
int res, nr_pages = 1;
struct page *pages;
res = get_user_pages(current, current->mm, virtp, nr_pages, 1,
0, &pages, NULL);
up_read(&current->mm->mmap_sem);
if (res == nr_pages) {
physp = __pa(page_address(&pages[0]) +
(virtp & ~PAGE_MASK));
} else {
printk(KERN_WARNING VOUT_NAME
"get_user_pages failed\n");
return 0;
}
}
return physp;
}
void omap_vout_free_buffers(struct omap_vout_device *vout)
{
int i, numbuffers;
numbuffers = (vout->vid) ? video2_numbuffers : video1_numbuffers;
vout->buffer_size = (vout->vid) ? video2_bufsize : video1_bufsize;
for (i = 0; i < numbuffers; i++) {
omap_vout_free_buffer(vout->buf_virt_addr[i],
vout->buffer_size);
vout->buf_phy_addr[i] = 0;
vout->buf_virt_addr[i] = 0;
}
}
static int v4l2_rot_to_dss_rot(int v4l2_rotation,
enum dss_rotation *rotation, bool mirror)
{
int ret = 0;
switch (v4l2_rotation) {
case 90:
*rotation = dss_rotation_90_degree;
break;
case 180:
*rotation = dss_rotation_180_degree;
break;
case 270:
*rotation = dss_rotation_270_degree;
break;
case 0:
*rotation = dss_rotation_0_degree;
break;
default:
ret = -EINVAL;
}
return ret;
}
static int omap_vout_calculate_offset(struct omap_vout_device *vout)
{
struct omapvideo_info *ovid;
struct v4l2_rect *crop = &vout->crop;
struct v4l2_pix_format *pix = &vout->pix;
int *cropped_offset = &vout->cropped_offset;
int ps = 2, line_length = 0;
ovid = &vout->vid_info;
if (ovid->rotation_type == VOUT_ROT_VRFB) {
omap_vout_calculate_vrfb_offset(vout);
} else {
vout->line_length = line_length = pix->width;
if (V4L2_PIX_FMT_YUYV == pix->pixelformat ||
V4L2_PIX_FMT_UYVY == pix->pixelformat)
ps = 2;
else if (V4L2_PIX_FMT_RGB32 == pix->pixelformat)
ps = 4;
else if (V4L2_PIX_FMT_RGB24 == pix->pixelformat)
ps = 3;
vout->ps = ps;
*cropped_offset = (line_length * ps) *
crop->top + crop->left * ps;
}
v4l2_dbg(1, debug, &vout->vid_dev->v4l2_dev, "%s Offset:%x\n",
__func__, vout->cropped_offset);
return 0;
}
static int video_mode_to_dss_mode(struct omap_vout_device *vout)
{
struct omap_overlay *ovl;
struct omapvideo_info *ovid;
struct v4l2_pix_format *pix = &vout->pix;
enum omap_color_mode mode;
ovid = &vout->vid_info;
ovl = ovid->overlays[0];
switch (pix->pixelformat) {
case 0:
break;
case V4L2_PIX_FMT_YUYV:
mode = OMAP_DSS_COLOR_YUV2;
break;
case V4L2_PIX_FMT_UYVY:
mode = OMAP_DSS_COLOR_UYVY;
break;
case V4L2_PIX_FMT_RGB565:
mode = OMAP_DSS_COLOR_RGB16;
break;
case V4L2_PIX_FMT_RGB24:
mode = OMAP_DSS_COLOR_RGB24P;
break;
case V4L2_PIX_FMT_RGB32:
mode = (ovl->id == OMAP_DSS_VIDEO1) ?
OMAP_DSS_COLOR_RGB24U : OMAP_DSS_COLOR_ARGB32;
break;
case V4L2_PIX_FMT_BGR32:
mode = OMAP_DSS_COLOR_RGBX32;
break;
default:
mode = -EINVAL;
}
return mode;
}
static int omapvid_setup_overlay(struct omap_vout_device *vout,
struct omap_overlay *ovl, int posx, int posy, int outw,
int outh, u32 addr)
{
int ret = 0;
struct omap_overlay_info info;
int cropheight, cropwidth, pixheight, pixwidth;
if ((ovl->caps & OMAP_DSS_OVL_CAP_SCALE) == 0 &&
(outw != vout->pix.width || outh != vout->pix.height)) {
ret = -EINVAL;
goto setup_ovl_err;
}
vout->dss_mode = video_mode_to_dss_mode(vout);
if (vout->dss_mode == -EINVAL) {
ret = -EINVAL;
goto setup_ovl_err;
}
if (is_rotation_90_or_270(vout)) {
cropheight = vout->crop.width;
cropwidth = vout->crop.height;
pixheight = vout->pix.width;
pixwidth = vout->pix.height;
} else {
cropheight = vout->crop.height;
cropwidth = vout->crop.width;
pixheight = vout->pix.height;
pixwidth = vout->pix.width;
}
ovl->get_overlay_info(ovl, &info);
info.paddr = addr;
info.width = cropwidth;
info.height = cropheight;
info.color_mode = vout->dss_mode;
info.mirror = vout->mirror;
info.pos_x = posx;
info.pos_y = posy;
info.out_width = outw;
info.out_height = outh;
info.global_alpha = vout->win.global_alpha;
if (!is_rotation_enabled(vout)) {
info.rotation = 0;
info.rotation_type = OMAP_DSS_ROT_DMA;
info.screen_width = pixwidth;
} else {
info.rotation = vout->rotation;
info.rotation_type = OMAP_DSS_ROT_VRFB;
info.screen_width = 2048;
}
v4l2_dbg(1, debug, &vout->vid_dev->v4l2_dev,
"%s enable=%d addr=%x width=%d\n height=%d color_mode=%d\n"
"rotation=%d mirror=%d posx=%d posy=%d out_width = %d \n"
"out_height=%d rotation_type=%d screen_width=%d\n",
__func__, ovl->is_enabled(ovl), info.paddr, info.width, info.height,
info.color_mode, info.rotation, info.mirror, info.pos_x,
info.pos_y, info.out_width, info.out_height, info.rotation_type,
info.screen_width);
ret = ovl->set_overlay_info(ovl, &info);
if (ret)
goto setup_ovl_err;
return 0;
setup_ovl_err:
v4l2_warn(&vout->vid_dev->v4l2_dev, "setup_overlay failed\n");
return ret;
}
static int omapvid_init(struct omap_vout_device *vout, u32 addr)
{
int ret = 0, i;
struct v4l2_window *win;
struct omap_overlay *ovl;
int posx, posy, outw, outh, temp;
struct omap_video_timings *timing;
struct omapvideo_info *ovid = &vout->vid_info;
win = &vout->win;
for (i = 0; i < ovid->num_overlays; i++) {
struct omap_dss_device *dssdev;
ovl = ovid->overlays[i];
dssdev = ovl->get_device(ovl);
if (!dssdev)
return -EINVAL;
timing = &dssdev->panel.timings;
outw = win->w.width;
outh = win->w.height;
switch (vout->rotation) {
case dss_rotation_90_degree:
temp = outw;
outw = outh;
outh = temp;
posy = (timing->y_res - win->w.width) - win->w.left;
posx = win->w.top;
break;
case dss_rotation_180_degree:
posx = (timing->x_res - win->w.width) - win->w.left;
posy = (timing->y_res - win->w.height) - win->w.top;
break;
case dss_rotation_270_degree:
temp = outw;
outw = outh;
outh = temp;
posy = win->w.left;
posx = (timing->x_res - win->w.height) - win->w.top;
break;
default:
posx = win->w.left;
posy = win->w.top;
break;
}
ret = omapvid_setup_overlay(vout, ovl, posx, posy,
outw, outh, addr);
if (ret)
goto omapvid_init_err;
}
return 0;
omapvid_init_err:
v4l2_warn(&vout->vid_dev->v4l2_dev, "apply_changes failed\n");
return ret;
}
static int omapvid_apply_changes(struct omap_vout_device *vout)
{
int i;
struct omap_overlay *ovl;
struct omapvideo_info *ovid = &vout->vid_info;
for (i = 0; i < ovid->num_overlays; i++) {
struct omap_dss_device *dssdev;
ovl = ovid->overlays[i];
dssdev = ovl->get_device(ovl);
if (!dssdev)
return -EINVAL;
ovl->manager->apply(ovl->manager);
}
return 0;
}
static int omapvid_handle_interlace_display(struct omap_vout_device *vout,
unsigned int irqstatus, struct timeval timevalue)
{
u32 fid;
if (vout->first_int) {
vout->first_int = 0;
goto err;
}
if (irqstatus & DISPC_IRQ_EVSYNC_ODD)
fid = 1;
else if (irqstatus & DISPC_IRQ_EVSYNC_EVEN)
fid = 0;
else
goto err;
vout->field_id ^= 1;
if (fid != vout->field_id) {
if (fid == 0)
vout->field_id = fid;
} else if (0 == fid) {
if (vout->cur_frm == vout->next_frm)
goto err;
vout->cur_frm->ts = timevalue;
vout->cur_frm->state = VIDEOBUF_DONE;
wake_up_interruptible(&vout->cur_frm->done);
vout->cur_frm = vout->next_frm;
} else {
if (list_empty(&vout->dma_queue) ||
(vout->cur_frm != vout->next_frm))
goto err;
}
return vout->field_id;
err:
return 0;
}
static void omap_vout_isr(void *arg, unsigned int irqstatus)
{
int ret, fid, mgr_id;
u32 addr, irq;
struct omap_overlay *ovl;
struct timeval timevalue;
struct omapvideo_info *ovid;
struct omap_dss_device *cur_display;
struct omap_vout_device *vout = (struct omap_vout_device *)arg;
if (!vout->streaming)
return;
ovid = &vout->vid_info;
ovl = ovid->overlays[0];
mgr_id = ovl->manager->id;
cur_display = ovl->get_device(ovl);
if (!cur_display)
return;
spin_lock(&vout->vbq_lock);
v4l2_get_timestamp(&timevalue);
switch (cur_display->type) {
case OMAP_DISPLAY_TYPE_DSI:
case OMAP_DISPLAY_TYPE_DPI:
if (mgr_id == OMAP_DSS_CHANNEL_LCD)
irq = DISPC_IRQ_VSYNC;
else if (mgr_id == OMAP_DSS_CHANNEL_LCD2)
irq = DISPC_IRQ_VSYNC2;
else
goto vout_isr_err;
if (!(irqstatus & irq))
goto vout_isr_err;
break;
case OMAP_DISPLAY_TYPE_VENC:
fid = omapvid_handle_interlace_display(vout, irqstatus,
timevalue);
if (!fid)
goto vout_isr_err;
break;
case OMAP_DISPLAY_TYPE_HDMI:
if (!(irqstatus & DISPC_IRQ_EVSYNC_EVEN))
goto vout_isr_err;
break;
default:
goto vout_isr_err;
}
if (!vout->first_int && (vout->cur_frm != vout->next_frm)) {
vout->cur_frm->ts = timevalue;
vout->cur_frm->state = VIDEOBUF_DONE;
wake_up_interruptible(&vout->cur_frm->done);
vout->cur_frm = vout->next_frm;
}
vout->first_int = 0;
if (list_empty(&vout->dma_queue))
goto vout_isr_err;
vout->next_frm = list_entry(vout->dma_queue.next,
struct videobuf_buffer, queue);
list_del(&vout->next_frm->queue);
vout->next_frm->state = VIDEOBUF_ACTIVE;
addr = (unsigned long) vout->queued_buf_addr[vout->next_frm->i]
+ vout->cropped_offset;
ret = omapvid_init(vout, addr);
if (ret) {
printk(KERN_ERR VOUT_NAME
"failed to set overlay info\n");
goto vout_isr_err;
}
ret = omapvid_apply_changes(vout);
if (ret)
printk(KERN_ERR VOUT_NAME "failed to change mode\n");
vout_isr_err:
spin_unlock(&vout->vbq_lock);
}
static int omap_vout_buffer_setup(struct videobuf_queue *q, unsigned int *count,
unsigned int *size)
{
int startindex = 0, i, j;
u32 phy_addr = 0, virt_addr = 0;
struct omap_vout_device *vout = q->priv_data;
struct omapvideo_info *ovid = &vout->vid_info;
int vid_max_buf_size;
if (!vout)
return -EINVAL;
vid_max_buf_size = vout->vid == OMAP_VIDEO1 ? video1_bufsize :
video2_bufsize;
if (V4L2_BUF_TYPE_VIDEO_OUTPUT != q->type)
return -EINVAL;
startindex = (vout->vid == OMAP_VIDEO1) ?
video1_numbuffers : video2_numbuffers;
if (V4L2_MEMORY_MMAP == vout->memory && *count < startindex)
*count = startindex;
if (ovid->rotation_type == VOUT_ROT_VRFB) {
if (omap_vout_vrfb_buffer_setup(vout, count, startindex))
return -ENOMEM;
}
if (V4L2_MEMORY_MMAP != vout->memory)
return 0;
*size = PAGE_ALIGN(vout->pix.width * vout->pix.height * vout->bpp);
startindex = (vout->vid == OMAP_VIDEO1) ?
video1_numbuffers : video2_numbuffers;
if (*size > vid_max_buf_size) {
v4l2_err(&vout->vid_dev->v4l2_dev,
"buffer allocation mismatch [%u] [%u]\n",
*size, vout->buffer_size);
return -ENOMEM;
}
for (i = startindex; i < *count; i++) {
vout->buffer_size = *size;
virt_addr = omap_vout_alloc_buffer(vout->buffer_size,
&phy_addr);
if (!virt_addr) {
if (ovid->rotation_type == VOUT_ROT_NONE) {
break;
} else {
if (!is_rotation_enabled(vout))
break;
for (j = i; j < *count; j++) {
omap_vout_free_buffer(
vout->smsshado_virt_addr[j],
vout->smsshado_size);
vout->smsshado_virt_addr[j] = 0;
vout->smsshado_phy_addr[j] = 0;
}
}
}
vout->buf_virt_addr[i] = virt_addr;
vout->buf_phy_addr[i] = phy_addr;
}
*count = vout->buffer_allocated = i;
return 0;
}
static void omap_vout_free_extra_buffers(struct omap_vout_device *vout)
{
int num_buffers = 0, i;
num_buffers = (vout->vid == OMAP_VIDEO1) ?
video1_numbuffers : video2_numbuffers;
for (i = num_buffers; i < vout->buffer_allocated; i++) {
if (vout->buf_virt_addr[i])
omap_vout_free_buffer(vout->buf_virt_addr[i],
vout->buffer_size);
vout->buf_virt_addr[i] = 0;
vout->buf_phy_addr[i] = 0;
}
vout->buffer_allocated = num_buffers;
}
static int omap_vout_buffer_prepare(struct videobuf_queue *q,
struct videobuf_buffer *vb,
enum v4l2_field field)
{
struct omap_vout_device *vout = q->priv_data;
struct omapvideo_info *ovid = &vout->vid_info;
if (VIDEOBUF_NEEDS_INIT == vb->state) {
vb->width = vout->pix.width;
vb->height = vout->pix.height;
vb->size = vb->width * vb->height * vout->bpp;
vb->field = field;
}
vb->state = VIDEOBUF_PREPARED;
if (V4L2_MEMORY_USERPTR == vb->memory) {
if (0 == vb->baddr)
return -EINVAL;
vout->queued_buf_addr[vb->i] = (u8 *)
omap_vout_uservirt_to_phys(vb->baddr);
} else {
u32 addr, dma_addr;
unsigned long size;
addr = (unsigned long) vout->buf_virt_addr[vb->i];
size = (unsigned long) vb->size;
dma_addr = dma_map_single(vout->vid_dev->v4l2_dev.dev, (void *) addr,
size, DMA_TO_DEVICE);
if (dma_mapping_error(vout->vid_dev->v4l2_dev.dev, dma_addr))
v4l2_err(&vout->vid_dev->v4l2_dev, "dma_map_single failed\n");
vout->queued_buf_addr[vb->i] = (u8 *)vout->buf_phy_addr[vb->i];
}
if (ovid->rotation_type == VOUT_ROT_VRFB)
return omap_vout_prepare_vrfb(vout, vb);
else
return 0;
}
static void omap_vout_buffer_queue(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
struct omap_vout_device *vout = q->priv_data;
list_add_tail(&vb->queue, &vout->dma_queue);
vb->state = VIDEOBUF_QUEUED;
}
static void omap_vout_buffer_release(struct videobuf_queue *q,
struct videobuf_buffer *vb)
{
struct omap_vout_device *vout = q->priv_data;
vb->state = VIDEOBUF_NEEDS_INIT;
if (V4L2_MEMORY_MMAP != vout->memory)
return;
}
static unsigned int omap_vout_poll(struct file *file,
struct poll_table_struct *wait)
{
struct omap_vout_device *vout = file->private_data;
struct videobuf_queue *q = &vout->vbq;
return videobuf_poll_stream(file, q, wait);
}
static void omap_vout_vm_open(struct vm_area_struct *vma)
{
struct omap_vout_device *vout = vma->vm_private_data;
v4l2_dbg(1, debug, &vout->vid_dev->v4l2_dev,
"vm_open [vma=%08lx-%08lx]\n", vma->vm_start, vma->vm_end);
vout->mmap_count++;
}
static void omap_vout_vm_close(struct vm_area_struct *vma)
{
struct omap_vout_device *vout = vma->vm_private_data;
v4l2_dbg(1, debug, &vout->vid_dev->v4l2_dev,
"vm_close [vma=%08lx-%08lx]\n", vma->vm_start, vma->vm_end);
vout->mmap_count--;
}
static int omap_vout_mmap(struct file *file, struct vm_area_struct *vma)
{
int i;
void *pos;
unsigned long start = vma->vm_start;
unsigned long size = (vma->vm_end - vma->vm_start);
struct omap_vout_device *vout = file->private_data;
struct videobuf_queue *q = &vout->vbq;
v4l2_dbg(1, debug, &vout->vid_dev->v4l2_dev,
" %s pgoff=0x%lx, start=0x%lx, end=0x%lx\n", __func__,
vma->vm_pgoff, vma->vm_start, vma->vm_end);
for (i = 0; i < VIDEO_MAX_FRAME; i++) {
if (NULL == q->bufs[i])
continue;
if (V4L2_MEMORY_MMAP != q->bufs[i]->memory)
continue;
if (q->bufs[i]->boff == (vma->vm_pgoff << PAGE_SHIFT))
break;
}
if (VIDEO_MAX_FRAME == i) {
v4l2_dbg(1, debug, &vout->vid_dev->v4l2_dev,
"offset invalid [offset=0x%lx]\n",
(vma->vm_pgoff << PAGE_SHIFT));
return -EINVAL;
}
if (size > vout->buffer_size) {
v4l2_err(&vout->vid_dev->v4l2_dev,
"insufficient memory [%lu] [%u]\n",
size, vout->buffer_size);
return -ENOMEM;
}
q->bufs[i]->baddr = vma->vm_start;
vma->vm_flags |= VM_DONTEXPAND | VM_DONTDUMP;
vma->vm_page_prot = pgprot_writecombine(vma->vm_page_prot);
vma->vm_ops = &omap_vout_vm_ops;
vma->vm_private_data = (void *) vout;
pos = (void *)vout->buf_virt_addr[i];
vma->vm_pgoff = virt_to_phys((void *)pos) >> PAGE_SHIFT;
while (size > 0) {
unsigned long pfn;
pfn = virt_to_phys((void *) pos) >> PAGE_SHIFT;
if (remap_pfn_range(vma, start, pfn, PAGE_SIZE, PAGE_SHARED))
return -EAGAIN;
start += PAGE_SIZE;
pos += PAGE_SIZE;
size -= PAGE_SIZE;
}
vout->mmap_count++;
v4l2_dbg(1, debug, &vout->vid_dev->v4l2_dev, "Exiting %s\n", __func__);
return 0;
}
static int omap_vout_release(struct file *file)
{
unsigned int ret, i;
struct videobuf_queue *q;
struct omapvideo_info *ovid;
struct omap_vout_device *vout = file->private_data;
v4l2_dbg(1, debug, &vout->vid_dev->v4l2_dev, "Entering %s\n", __func__);
ovid = &vout->vid_info;
if (!vout)
return 0;
q = &vout->vbq;
for (i = 0; i < ovid->num_overlays; i++) {
struct omap_overlay *ovl = ovid->overlays[i];
struct omap_dss_device *dssdev = ovl->get_device(ovl);
if (dssdev)
ovl->disable(ovl);
}
ret = omapvid_apply_changes(vout);
if (ret)
v4l2_warn(&vout->vid_dev->v4l2_dev,
"Unable to apply changes\n");
omap_vout_free_extra_buffers(vout);
if (ovid->rotation_type == VOUT_ROT_VRFB) {
if (!vout->vrfb_static_allocation)
omap_vout_free_vrfb_buffers(vout);
}
videobuf_mmap_free(q);
if (vout->streaming) {
u32 mask = 0;
mask = DISPC_IRQ_VSYNC | DISPC_IRQ_EVSYNC_EVEN |
DISPC_IRQ_EVSYNC_ODD | DISPC_IRQ_VSYNC2;
omap_dispc_unregister_isr(omap_vout_isr, vout, mask);
vout->streaming = 0;
videobuf_streamoff(q);
videobuf_queue_cancel(q);
}
if (vout->mmap_count != 0)
vout->mmap_count = 0;
vout->opened -= 1;
file->private_data = NULL;
if (vout->buffer_allocated)
videobuf_mmap_free(q);
v4l2_dbg(1, debug, &vout->vid_dev->v4l2_dev, "Exiting %s\n", __func__);
return ret;
}
static int omap_vout_open(struct file *file)
{
struct videobuf_queue *q;
struct omap_vout_device *vout = NULL;
vout = video_drvdata(file);
v4l2_dbg(1, debug, &vout->vid_dev->v4l2_dev, "Entering %s\n", __func__);
if (vout == NULL)
return -ENODEV;
if (vout->opened)
return -EBUSY;
vout->opened += 1;
file->private_data = vout;
vout->type = V4L2_BUF_TYPE_VIDEO_OUTPUT;
q = &vout->vbq;
video_vbq_ops.buf_setup = omap_vout_buffer_setup;
video_vbq_ops.buf_prepare = omap_vout_buffer_prepare;
video_vbq_ops.buf_release = omap_vout_buffer_release;
video_vbq_ops.buf_queue = omap_vout_buffer_queue;
spin_lock_init(&vout->vbq_lock);
videobuf_queue_dma_contig_init(q, &video_vbq_ops, q->dev,
&vout->vbq_lock, vout->type, V4L2_FIELD_NONE,
sizeof(struct videobuf_buffer), vout, NULL);
v4l2_dbg(1, debug, &vout->vid_dev->v4l2_dev, "Exiting %s\n", __func__);
return 0;
}
static int vidioc_querycap(struct file *file, void *fh,
struct v4l2_capability *cap)
{
struct omap_vout_device *vout = fh;
strlcpy(cap->driver, VOUT_NAME, sizeof(cap->driver));
strlcpy(cap->card, vout->vfd->name, sizeof(cap->card));
cap->bus_info[0] = '\0';
cap->capabilities = V4L2_CAP_STREAMING | V4L2_CAP_VIDEO_OUTPUT |
V4L2_CAP_VIDEO_OUTPUT_OVERLAY;
return 0;
}
static int vidioc_enum_fmt_vid_out(struct file *file, void *fh,
struct v4l2_fmtdesc *fmt)
{
int index = fmt->index;
if (index >= NUM_OUTPUT_FORMATS)
return -EINVAL;
fmt->flags = omap_formats[index].flags;
strlcpy(fmt->description, omap_formats[index].description,
sizeof(fmt->description));
fmt->pixelformat = omap_formats[index].pixelformat;
return 0;
}
static int vidioc_g_fmt_vid_out(struct file *file, void *fh,
struct v4l2_format *f)
{
struct omap_vout_device *vout = fh;
f->fmt.pix = vout->pix;
return 0;
}
static int vidioc_try_fmt_vid_out(struct file *file, void *fh,
struct v4l2_format *f)
{
struct omap_overlay *ovl;
struct omapvideo_info *ovid;
struct omap_video_timings *timing;
struct omap_vout_device *vout = fh;
struct omap_dss_device *dssdev;
ovid = &vout->vid_info;
ovl = ovid->overlays[0];
dssdev = ovl->get_device(ovl);
if (!dssdev)
return -EINVAL;
timing = &dssdev->panel.timings;
vout->fbuf.fmt.height = timing->y_res;
vout->fbuf.fmt.width = timing->x_res;
omap_vout_try_format(&f->fmt.pix);
return 0;
}
static int vidioc_s_fmt_vid_out(struct file *file, void *fh,
struct v4l2_format *f)
{
int ret, bpp;
struct omap_overlay *ovl;
struct omapvideo_info *ovid;
struct omap_video_timings *timing;
struct omap_vout_device *vout = fh;
struct omap_dss_device *dssdev;
if (vout->streaming)
return -EBUSY;
mutex_lock(&vout->lock);
ovid = &vout->vid_info;
ovl = ovid->overlays[0];
dssdev = ovl->get_device(ovl);
if (!dssdev) {
ret = -EINVAL;
goto s_fmt_vid_out_exit;
}
timing = &dssdev->panel.timings;
if ((is_rotation_enabled(vout)) &&
f->fmt.pix.pixelformat == V4L2_PIX_FMT_RGB24) {
ret = -EINVAL;
goto s_fmt_vid_out_exit;
}
if (is_rotation_90_or_270(vout)) {
vout->fbuf.fmt.height = timing->x_res;
vout->fbuf.fmt.width = timing->y_res;
} else {
vout->fbuf.fmt.height = timing->y_res;
vout->fbuf.fmt.width = timing->x_res;
}
bpp = omap_vout_try_format(&f->fmt.pix);
f->fmt.pix.sizeimage = f->fmt.pix.width * f->fmt.pix.height * bpp;
vout->bpp = bpp;
vout->pix = f->fmt.pix;
vout->vrfb_bpp = 1;
if (V4L2_PIX_FMT_YUYV == vout->pix.pixelformat ||
V4L2_PIX_FMT_UYVY == vout->pix.pixelformat)
vout->vrfb_bpp = 2;
omap_vout_new_format(&vout->pix, &vout->fbuf, &vout->crop, &vout->win);
ret = 0;
s_fmt_vid_out_exit:
mutex_unlock(&vout->lock);
return ret;
}
static int vidioc_try_fmt_vid_overlay(struct file *file, void *fh,
struct v4l2_format *f)
{
int ret = 0;
struct omap_vout_device *vout = fh;
struct omap_overlay *ovl;
struct omapvideo_info *ovid;
struct v4l2_window *win = &f->fmt.win;
ovid = &vout->vid_info;
ovl = ovid->overlays[0];
ret = omap_vout_try_window(&vout->fbuf, win);
if (!ret) {
if ((ovl->caps & OMAP_DSS_OVL_CAP_GLOBAL_ALPHA) == 0)
win->global_alpha = 255;
else
win->global_alpha = f->fmt.win.global_alpha;
}
return ret;
}
static int vidioc_s_fmt_vid_overlay(struct file *file, void *fh,
struct v4l2_format *f)
{
int ret = 0;
struct omap_overlay *ovl;
struct omapvideo_info *ovid;
struct omap_vout_device *vout = fh;
struct v4l2_window *win = &f->fmt.win;
mutex_lock(&vout->lock);
ovid = &vout->vid_info;
ovl = ovid->overlays[0];
ret = omap_vout_new_window(&vout->crop, &vout->win, &vout->fbuf, win);
if (!ret) {
if ((ovl->caps & OMAP_DSS_OVL_CAP_GLOBAL_ALPHA) == 0)
vout->win.global_alpha = 255;
else
vout->win.global_alpha = f->fmt.win.global_alpha;
vout->win.chromakey = f->fmt.win.chromakey;
}
mutex_unlock(&vout->lock);
return ret;
}
static int vidioc_g_fmt_vid_overlay(struct file *file, void *fh,
struct v4l2_format *f)
{
u32 key_value = 0;
struct omap_overlay *ovl;
struct omapvideo_info *ovid;
struct omap_vout_device *vout = fh;
struct omap_overlay_manager_info info;
struct v4l2_window *win = &f->fmt.win;
ovid = &vout->vid_info;
ovl = ovid->overlays[0];
win->w = vout->win.w;
win->field = vout->win.field;
win->global_alpha = vout->win.global_alpha;
if (ovl->manager && ovl->manager->get_manager_info) {
ovl->manager->get_manager_info(ovl->manager, &info);
key_value = info.trans_key;
}
win->chromakey = key_value;
return 0;
}
static int vidioc_cropcap(struct file *file, void *fh,
struct v4l2_cropcap *cropcap)
{
struct omap_vout_device *vout = fh;
struct v4l2_pix_format *pix = &vout->pix;
if (cropcap->type != V4L2_BUF_TYPE_VIDEO_OUTPUT)
return -EINVAL;
cropcap->bounds.width = pix->width & ~1;
cropcap->bounds.height = pix->height & ~1;
omap_vout_default_crop(&vout->pix, &vout->fbuf, &cropcap->defrect);
cropcap->pixelaspect.numerator = 1;
cropcap->pixelaspect.denominator = 1;
return 0;
}
static int vidioc_g_crop(struct file *file, void *fh, struct v4l2_crop *crop)
{
struct omap_vout_device *vout = fh;
if (crop->type != V4L2_BUF_TYPE_VIDEO_OUTPUT)
return -EINVAL;
crop->c = vout->crop;
return 0;
}
static int vidioc_s_crop(struct file *file, void *fh, const struct v4l2_crop *crop)
{
int ret = -EINVAL;
struct omap_vout_device *vout = fh;
struct omapvideo_info *ovid;
struct omap_overlay *ovl;
struct omap_video_timings *timing;
struct omap_dss_device *dssdev;
if (vout->streaming)
return -EBUSY;
mutex_lock(&vout->lock);
ovid = &vout->vid_info;
ovl = ovid->overlays[0];
dssdev = ovl->get_device(ovl);
if (!dssdev) {
ret = -EINVAL;
goto s_crop_err;
}
timing = &dssdev->panel.timings;
if (is_rotation_90_or_270(vout)) {
vout->fbuf.fmt.height = timing->x_res;
vout->fbuf.fmt.width = timing->y_res;
} else {
vout->fbuf.fmt.height = timing->y_res;
vout->fbuf.fmt.width = timing->x_res;
}
if (crop->type == V4L2_BUF_TYPE_VIDEO_OUTPUT)
ret = omap_vout_new_crop(&vout->pix, &vout->crop, &vout->win,
&vout->fbuf, &crop->c);
s_crop_err:
mutex_unlock(&vout->lock);
return ret;
}
static int vidioc_queryctrl(struct file *file, void *fh,
struct v4l2_queryctrl *ctrl)
{
int ret = 0;
switch (ctrl->id) {
case V4L2_CID_ROTATE:
ret = v4l2_ctrl_query_fill(ctrl, 0, 270, 90, 0);
break;
case V4L2_CID_BG_COLOR:
ret = v4l2_ctrl_query_fill(ctrl, 0, 0xFFFFFF, 1, 0);
break;
case V4L2_CID_VFLIP:
ret = v4l2_ctrl_query_fill(ctrl, 0, 1, 1, 0);
break;
default:
ctrl->name[0] = '\0';
ret = -EINVAL;
}
return ret;
}
static int vidioc_g_ctrl(struct file *file, void *fh, struct v4l2_control *ctrl)
{
int ret = 0;
struct omap_vout_device *vout = fh;
switch (ctrl->id) {
case V4L2_CID_ROTATE:
ctrl->value = vout->control[0].value;
break;
case V4L2_CID_BG_COLOR:
{
struct omap_overlay_manager_info info;
struct omap_overlay *ovl;
ovl = vout->vid_info.overlays[0];
if (!ovl->manager || !ovl->manager->get_manager_info) {
ret = -EINVAL;
break;
}
ovl->manager->get_manager_info(ovl->manager, &info);
ctrl->value = info.default_color;
break;
}
case V4L2_CID_VFLIP:
ctrl->value = vout->control[2].value;
break;
default:
ret = -EINVAL;
}
return ret;
}
static int vidioc_s_ctrl(struct file *file, void *fh, struct v4l2_control *a)
{
int ret = 0;
struct omap_vout_device *vout = fh;
switch (a->id) {
case V4L2_CID_ROTATE:
{
struct omapvideo_info *ovid;
int rotation = a->value;
ovid = &vout->vid_info;
mutex_lock(&vout->lock);
if (rotation && ovid->rotation_type == VOUT_ROT_NONE) {
mutex_unlock(&vout->lock);
ret = -ERANGE;
break;
}
if (rotation && vout->pix.pixelformat == V4L2_PIX_FMT_RGB24) {
mutex_unlock(&vout->lock);
ret = -EINVAL;
break;
}
if (v4l2_rot_to_dss_rot(rotation, &vout->rotation,
vout->mirror)) {
mutex_unlock(&vout->lock);
ret = -EINVAL;
break;
}
vout->control[0].value = rotation;
mutex_unlock(&vout->lock);
break;
}
case V4L2_CID_BG_COLOR:
{
struct omap_overlay *ovl;
unsigned int color = a->value;
struct omap_overlay_manager_info info;
ovl = vout->vid_info.overlays[0];
mutex_lock(&vout->lock);
if (!ovl->manager || !ovl->manager->get_manager_info) {
mutex_unlock(&vout->lock);
ret = -EINVAL;
break;
}
ovl->manager->get_manager_info(ovl->manager, &info);
info.default_color = color;
if (ovl->manager->set_manager_info(ovl->manager, &info)) {
mutex_unlock(&vout->lock);
ret = -EINVAL;
break;
}
vout->control[1].value = color;
mutex_unlock(&vout->lock);
break;
}
case V4L2_CID_VFLIP:
{
struct omap_overlay *ovl;
struct omapvideo_info *ovid;
unsigned int mirror = a->value;
ovid = &vout->vid_info;
ovl = ovid->overlays[0];
mutex_lock(&vout->lock);
if (mirror && ovid->rotation_type == VOUT_ROT_NONE) {
mutex_unlock(&vout->lock);
ret = -ERANGE;
break;
}
if (mirror && vout->pix.pixelformat == V4L2_PIX_FMT_RGB24) {
mutex_unlock(&vout->lock);
ret = -EINVAL;
break;
}
vout->mirror = mirror;
vout->control[2].value = mirror;
mutex_unlock(&vout->lock);
break;
}
default:
ret = -EINVAL;
}
return ret;
}
static int vidioc_reqbufs(struct file *file, void *fh,
struct v4l2_requestbuffers *req)
{
int ret = 0;
unsigned int i, num_buffers = 0;
struct omap_vout_device *vout = fh;
struct videobuf_queue *q = &vout->vbq;
if ((req->type != V4L2_BUF_TYPE_VIDEO_OUTPUT) || (req->count < 0))
return -EINVAL;
if ((V4L2_MEMORY_MMAP != req->memory) &&
(V4L2_MEMORY_USERPTR != req->memory))
return -EINVAL;
mutex_lock(&vout->lock);
if (vout->streaming) {
ret = -EBUSY;
goto reqbuf_err;
}
if (q->bufs[0] && (V4L2_MEMORY_MMAP == q->bufs[0]->memory)) {
if (vout->mmap_count) {
ret = -EBUSY;
goto reqbuf_err;
}
num_buffers = (vout->vid == OMAP_VIDEO1) ?
video1_numbuffers : video2_numbuffers;
for (i = num_buffers; i < vout->buffer_allocated; i++) {
omap_vout_free_buffer(vout->buf_virt_addr[i],
vout->buffer_size);
vout->buf_virt_addr[i] = 0;
vout->buf_phy_addr[i] = 0;
}
vout->buffer_allocated = num_buffers;
videobuf_mmap_free(q);
} else if (q->bufs[0] && (V4L2_MEMORY_USERPTR == q->bufs[0]->memory)) {
if (vout->buffer_allocated) {
videobuf_mmap_free(q);
for (i = 0; i < vout->buffer_allocated; i++) {
kfree(q->bufs[i]);
q->bufs[i] = NULL;
}
vout->buffer_allocated = 0;
}
}
vout->memory = req->memory;
INIT_LIST_HEAD(&vout->dma_queue);
ret = videobuf_reqbufs(q, req);
if (ret < 0)
goto reqbuf_err;
vout->buffer_allocated = req->count;
reqbuf_err:
mutex_unlock(&vout->lock);
return ret;
}
static int vidioc_querybuf(struct file *file, void *fh,
struct v4l2_buffer *b)
{
struct omap_vout_device *vout = fh;
return videobuf_querybuf(&vout->vbq, b);
}
static int vidioc_qbuf(struct file *file, void *fh,
struct v4l2_buffer *buffer)
{
struct omap_vout_device *vout = fh;
struct videobuf_queue *q = &vout->vbq;
if ((V4L2_BUF_TYPE_VIDEO_OUTPUT != buffer->type) ||
(buffer->index >= vout->buffer_allocated) ||
(q->bufs[buffer->index]->memory != buffer->memory)) {
return -EINVAL;
}
if (V4L2_MEMORY_USERPTR == buffer->memory) {
if ((buffer->length < vout->pix.sizeimage) ||
(0 == buffer->m.userptr)) {
return -EINVAL;
}
}
if ((is_rotation_enabled(vout)) &&
vout->vrfb_dma_tx.req_status == DMA_CHAN_NOT_ALLOTED) {
v4l2_warn(&vout->vid_dev->v4l2_dev,
"DMA Channel not allocated for Rotation\n");
return -EINVAL;
}
return videobuf_qbuf(q, buffer);
}
static int vidioc_dqbuf(struct file *file, void *fh, struct v4l2_buffer *b)
{
struct omap_vout_device *vout = fh;
struct videobuf_queue *q = &vout->vbq;
int ret;
u32 addr;
unsigned long size;
struct videobuf_buffer *vb;
vb = q->bufs[b->index];
if (!vout->streaming)
return -EINVAL;
if (file->f_flags & O_NONBLOCK)
ret = videobuf_dqbuf(q, (struct v4l2_buffer *)b, 1);
else
ret = videobuf_dqbuf(q, (struct v4l2_buffer *)b, 0);
addr = (unsigned long) vout->buf_phy_addr[vb->i];
size = (unsigned long) vb->size;
dma_unmap_single(vout->vid_dev->v4l2_dev.dev, addr,
size, DMA_TO_DEVICE);
return ret;
}
static int vidioc_streamon(struct file *file, void *fh, enum v4l2_buf_type i)
{
int ret = 0, j;
u32 addr = 0, mask = 0;
struct omap_vout_device *vout = fh;
struct videobuf_queue *q = &vout->vbq;
struct omapvideo_info *ovid = &vout->vid_info;
mutex_lock(&vout->lock);
if (vout->streaming) {
ret = -EBUSY;
goto streamon_err;
}
ret = videobuf_streamon(q);
if (ret)
goto streamon_err;
if (list_empty(&vout->dma_queue)) {
ret = -EIO;
goto streamon_err1;
}
vout->next_frm = vout->cur_frm = list_entry(vout->dma_queue.next,
struct videobuf_buffer, queue);
list_del(&vout->cur_frm->queue);
vout->cur_frm->state = VIDEOBUF_ACTIVE;
vout->field_id = 0;
vout->streaming = 1;
vout->first_int = 1;
if (omap_vout_calculate_offset(vout)) {
ret = -EINVAL;
goto streamon_err1;
}
addr = (unsigned long) vout->queued_buf_addr[vout->cur_frm->i]
+ vout->cropped_offset;
mask = DISPC_IRQ_VSYNC | DISPC_IRQ_EVSYNC_EVEN | DISPC_IRQ_EVSYNC_ODD
| DISPC_IRQ_VSYNC2;
ret = omapvid_init(vout, addr);
if (ret) {
v4l2_err(&vout->vid_dev->v4l2_dev,
"failed to set overlay info\n");
goto streamon_err1;
}
omap_dispc_register_isr(omap_vout_isr, vout, mask);
ret = omapvid_apply_changes(vout);
if (ret)
v4l2_err(&vout->vid_dev->v4l2_dev, "failed to change mode\n");
for (j = 0; j < ovid->num_overlays; j++) {
struct omap_overlay *ovl = ovid->overlays[j];
struct omap_dss_device *dssdev = ovl->get_device(ovl);
if (dssdev) {
ret = ovl->enable(ovl);
if (ret)
goto streamon_err1;
}
}
ret = 0;
streamon_err1:
if (ret)
ret = videobuf_streamoff(q);
streamon_err:
mutex_unlock(&vout->lock);
return ret;
}
static int vidioc_streamoff(struct file *file, void *fh, enum v4l2_buf_type i)
{
u32 mask = 0;
int ret = 0, j;
struct omap_vout_device *vout = fh;
struct omapvideo_info *ovid = &vout->vid_info;
if (!vout->streaming)
return -EINVAL;
vout->streaming = 0;
mask = DISPC_IRQ_VSYNC | DISPC_IRQ_EVSYNC_EVEN | DISPC_IRQ_EVSYNC_ODD
| DISPC_IRQ_VSYNC2;
omap_dispc_unregister_isr(omap_vout_isr, vout, mask);
for (j = 0; j < ovid->num_overlays; j++) {
struct omap_overlay *ovl = ovid->overlays[j];
struct omap_dss_device *dssdev = ovl->get_device(ovl);
if (dssdev)
ovl->disable(ovl);
}
ret = omapvid_apply_changes(vout);
if (ret)
v4l2_err(&vout->vid_dev->v4l2_dev, "failed to change mode in"
" streamoff\n");
INIT_LIST_HEAD(&vout->dma_queue);
ret = videobuf_streamoff(&vout->vbq);
return ret;
}
static int vidioc_s_fbuf(struct file *file, void *fh,
const struct v4l2_framebuffer *a)
{
int enable = 0;
struct omap_overlay *ovl;
struct omapvideo_info *ovid;
struct omap_vout_device *vout = fh;
struct omap_overlay_manager_info info;
enum omap_dss_trans_key_type key_type = OMAP_DSS_COLOR_KEY_GFX_DST;
ovid = &vout->vid_info;
ovl = ovid->overlays[0];
if ((a->flags & V4L2_FBUF_FLAG_SRC_CHROMAKEY) &&
(a->flags & V4L2_FBUF_FLAG_CHROMAKEY))
return -EINVAL;
if ((a->flags & V4L2_FBUF_FLAG_CHROMAKEY) &&
(a->flags & V4L2_FBUF_FLAG_LOCAL_ALPHA))
return -EINVAL;
if ((a->flags & V4L2_FBUF_FLAG_SRC_CHROMAKEY)) {
vout->fbuf.flags |= V4L2_FBUF_FLAG_SRC_CHROMAKEY;
key_type = OMAP_DSS_COLOR_KEY_VID_SRC;
} else
vout->fbuf.flags &= ~V4L2_FBUF_FLAG_SRC_CHROMAKEY;
if ((a->flags & V4L2_FBUF_FLAG_CHROMAKEY)) {
vout->fbuf.flags |= V4L2_FBUF_FLAG_CHROMAKEY;
key_type = OMAP_DSS_COLOR_KEY_GFX_DST;
} else
vout->fbuf.flags &= ~V4L2_FBUF_FLAG_CHROMAKEY;
if (a->flags & (V4L2_FBUF_FLAG_CHROMAKEY |
V4L2_FBUF_FLAG_SRC_CHROMAKEY))
enable = 1;
else
enable = 0;
if (ovl->manager && ovl->manager->get_manager_info &&
ovl->manager->set_manager_info) {
ovl->manager->get_manager_info(ovl->manager, &info);
info.trans_enabled = enable;
info.trans_key_type = key_type;
info.trans_key = vout->win.chromakey;
if (ovl->manager->set_manager_info(ovl->manager, &info))
return -EINVAL;
}
if (a->flags & V4L2_FBUF_FLAG_LOCAL_ALPHA) {
vout->fbuf.flags |= V4L2_FBUF_FLAG_LOCAL_ALPHA;
enable = 1;
} else {
vout->fbuf.flags &= ~V4L2_FBUF_FLAG_LOCAL_ALPHA;
enable = 0;
}
if (ovl->manager && ovl->manager->get_manager_info &&
ovl->manager->set_manager_info) {
ovl->manager->get_manager_info(ovl->manager, &info);
if ((ovl->caps & OMAP_DSS_OVL_CAP_ZORDER) == 0)
info.partial_alpha_enabled = enable;
if (ovl->manager->set_manager_info(ovl->manager, &info))
return -EINVAL;
}
return 0;
}
static int vidioc_g_fbuf(struct file *file, void *fh,
struct v4l2_framebuffer *a)
{
struct omap_overlay *ovl;
struct omapvideo_info *ovid;
struct omap_vout_device *vout = fh;
struct omap_overlay_manager_info info;
ovid = &vout->vid_info;
ovl = ovid->overlays[0];
a->flags = V4L2_FBUF_FLAG_OVERLAY;
a->capability = V4L2_FBUF_CAP_LOCAL_ALPHA | V4L2_FBUF_CAP_CHROMAKEY
| V4L2_FBUF_CAP_SRC_CHROMAKEY;
if (ovl->manager && ovl->manager->get_manager_info) {
ovl->manager->get_manager_info(ovl->manager, &info);
if (info.trans_key_type == OMAP_DSS_COLOR_KEY_VID_SRC)
a->flags |= V4L2_FBUF_FLAG_SRC_CHROMAKEY;
if (info.trans_key_type == OMAP_DSS_COLOR_KEY_GFX_DST)
a->flags |= V4L2_FBUF_FLAG_CHROMAKEY;
}
if (ovl->manager && ovl->manager->get_manager_info) {
ovl->manager->get_manager_info(ovl->manager, &info);
if (info.partial_alpha_enabled)
a->flags |= V4L2_FBUF_FLAG_LOCAL_ALPHA;
}
return 0;
}
static int __init omap_vout_setup_video_data(struct omap_vout_device *vout)
{
struct video_device *vfd;
struct v4l2_pix_format *pix;
struct v4l2_control *control;
struct omap_overlay *ovl = vout->vid_info.overlays[0];
struct omap_dss_device *display = ovl->get_device(ovl);
pix = &vout->pix;
pix->width = QQVGA_WIDTH;
pix->height = QQVGA_HEIGHT;
pix->pixelformat = V4L2_PIX_FMT_RGB565;
pix->field = V4L2_FIELD_ANY;
pix->bytesperline = pix->width * 2;
pix->sizeimage = pix->bytesperline * pix->height;
pix->priv = 0;
pix->colorspace = V4L2_COLORSPACE_JPEG;
vout->bpp = RGB565_BPP;
vout->fbuf.fmt.width = display->panel.timings.x_res;
vout->fbuf.fmt.height = display->panel.timings.y_res;
vout->win.global_alpha = 255;
vout->fbuf.flags = 0;
vout->fbuf.capability = V4L2_FBUF_CAP_LOCAL_ALPHA |
V4L2_FBUF_CAP_SRC_CHROMAKEY | V4L2_FBUF_CAP_CHROMAKEY;
vout->win.chromakey = 0;
omap_vout_new_format(pix, &vout->fbuf, &vout->crop, &vout->win);
control = vout->control;
control[0].id = V4L2_CID_ROTATE;
control[0].value = 0;
vout->rotation = 0;
vout->mirror = 0;
vout->control[2].id = V4L2_CID_HFLIP;
vout->control[2].value = 0;
if (vout->vid_info.rotation_type == VOUT_ROT_VRFB)
vout->vrfb_bpp = 2;
control[1].id = V4L2_CID_BG_COLOR;
control[1].value = 0;
vfd = vout->vfd = video_device_alloc();
if (!vfd) {
printk(KERN_ERR VOUT_NAME ": could not allocate"
" video device struct\n");
return -ENOMEM;
}
vfd->release = video_device_release;
vfd->ioctl_ops = &vout_ioctl_ops;
strlcpy(vfd->name, VOUT_NAME, sizeof(vfd->name));
vfd->fops = &omap_vout_fops;
vfd->v4l2_dev = &vout->vid_dev->v4l2_dev;
vfd->vfl_dir = VFL_DIR_TX;
mutex_init(&vout->lock);
vfd->minor = -1;
return 0;
}
static int __init omap_vout_setup_video_bufs(struct platform_device *pdev,
int vid_num)
{
u32 numbuffers;
int ret = 0, i;
struct omapvideo_info *ovid;
struct omap_vout_device *vout;
struct v4l2_device *v4l2_dev = platform_get_drvdata(pdev);
struct omap2video_device *vid_dev =
container_of(v4l2_dev, struct omap2video_device, v4l2_dev);
vout = vid_dev->vouts[vid_num];
ovid = &vout->vid_info;
numbuffers = (vid_num == 0) ? video1_numbuffers : video2_numbuffers;
vout->buffer_size = (vid_num == 0) ? video1_bufsize : video2_bufsize;
dev_info(&pdev->dev, "Buffer Size = %d\n", vout->buffer_size);
for (i = 0; i < numbuffers; i++) {
vout->buf_virt_addr[i] =
omap_vout_alloc_buffer(vout->buffer_size,
(u32 *) &vout->buf_phy_addr[i]);
if (!vout->buf_virt_addr[i]) {
numbuffers = i;
ret = -ENOMEM;
goto free_buffers;
}
}
vout->cropped_offset = 0;
if (ovid->rotation_type == VOUT_ROT_VRFB) {
int static_vrfb_allocation = (vid_num == 0) ?
vid1_static_vrfb_alloc : vid2_static_vrfb_alloc;
ret = omap_vout_setup_vrfb_bufs(pdev, vid_num,
static_vrfb_allocation);
}
return ret;
free_buffers:
for (i = 0; i < numbuffers; i++) {
omap_vout_free_buffer(vout->buf_virt_addr[i],
vout->buffer_size);
vout->buf_virt_addr[i] = 0;
vout->buf_phy_addr[i] = 0;
}
return ret;
}
static int __init omap_vout_create_video_devices(struct platform_device *pdev)
{
int ret = 0, k;
struct omap_vout_device *vout;
struct video_device *vfd = NULL;
struct v4l2_device *v4l2_dev = platform_get_drvdata(pdev);
struct omap2video_device *vid_dev = container_of(v4l2_dev,
struct omap2video_device, v4l2_dev);
for (k = 0; k < pdev->num_resources; k++) {
vout = kzalloc(sizeof(struct omap_vout_device), GFP_KERNEL);
if (!vout) {
dev_err(&pdev->dev, ": could not allocate memory\n");
return -ENOMEM;
}
vout->vid = k;
vid_dev->vouts[k] = vout;
vout->vid_dev = vid_dev;
if (pdev->num_resources == 1)
vout->vid_info.overlays[0] = vid_dev->overlays[k + 2];
else
vout->vid_info.overlays[0] = vid_dev->overlays[k + 1];
vout->vid_info.num_overlays = 1;
vout->vid_info.id = k + 1;
if (omap_vout_dss_omap24xx() || omap_vout_dss_omap34xx())
vout->vid_info.rotation_type = VOUT_ROT_VRFB;
if (omap_vout_setup_video_data(vout) != 0) {
ret = -ENOMEM;
goto error;
}
if (omap_vout_setup_video_bufs(pdev, k) != 0) {
ret = -ENOMEM;
goto error1;
}
vfd = vout->vfd;
if (video_register_device(vfd, VFL_TYPE_GRABBER, -1) < 0) {
dev_err(&pdev->dev, ": Could not register "
"Video for Linux device\n");
vfd->minor = -1;
ret = -ENODEV;
goto error2;
}
video_set_drvdata(vfd, vout);
dev_info(&pdev->dev, ": registered and initialized"
" video device %d\n", vfd->minor);
if (k == (pdev->num_resources - 1))
return 0;
continue;
error2:
if (vout->vid_info.rotation_type == VOUT_ROT_VRFB)
omap_vout_release_vrfb(vout);
omap_vout_free_buffers(vout);
error1:
video_device_release(vfd);
error:
kfree(vout);
return ret;
}
return -ENODEV;
}
static void omap_vout_cleanup_device(struct omap_vout_device *vout)
{
struct video_device *vfd;
struct omapvideo_info *ovid;
if (!vout)
return;
vfd = vout->vfd;
ovid = &vout->vid_info;
if (vfd) {
if (!video_is_registered(vfd)) {
video_device_release(vfd);
} else {
video_unregister_device(vfd);
}
}
if (ovid->rotation_type == VOUT_ROT_VRFB) {
omap_vout_release_vrfb(vout);
if (vout->vrfb_static_allocation)
omap_vout_free_vrfb_buffers(vout);
}
omap_vout_free_buffers(vout);
kfree(vout);
}
static int omap_vout_remove(struct platform_device *pdev)
{
int k;
struct v4l2_device *v4l2_dev = platform_get_drvdata(pdev);
struct omap2video_device *vid_dev = container_of(v4l2_dev, struct
omap2video_device, v4l2_dev);
v4l2_device_unregister(v4l2_dev);
for (k = 0; k < pdev->num_resources; k++)
omap_vout_cleanup_device(vid_dev->vouts[k]);
for (k = 0; k < vid_dev->num_displays; k++) {
if (vid_dev->displays[k]->state != OMAP_DSS_DISPLAY_DISABLED)
vid_dev->displays[k]->driver->disable(vid_dev->displays[k]);
omap_dss_put_device(vid_dev->displays[k]);
}
kfree(vid_dev);
return 0;
}
static int __init omap_vout_probe(struct platform_device *pdev)
{
int ret = 0, i;
struct omap_overlay *ovl;
struct omap_dss_device *dssdev = NULL;
struct omap_dss_device *def_display;
struct omap2video_device *vid_dev = NULL;
if (omapdss_is_initialized() == false)
return -EPROBE_DEFER;
ret = omapdss_compat_init();
if (ret) {
dev_err(&pdev->dev, "failed to init dss\n");
return ret;
}
if (pdev->num_resources == 0) {
dev_err(&pdev->dev, "probed for an unknown device\n");
ret = -ENODEV;
goto err_dss_init;
}
vid_dev = kzalloc(sizeof(struct omap2video_device), GFP_KERNEL);
if (vid_dev == NULL) {
ret = -ENOMEM;
goto err_dss_init;
}
vid_dev->num_displays = 0;
for_each_dss_dev(dssdev) {
omap_dss_get_device(dssdev);
if (!dssdev->driver) {
dev_warn(&pdev->dev, "no driver for display: %s\n",
dssdev->name);
omap_dss_put_device(dssdev);
continue;
}
vid_dev->displays[vid_dev->num_displays++] = dssdev;
}
if (vid_dev->num_displays == 0) {
dev_err(&pdev->dev, "no displays\n");
ret = -EINVAL;
goto probe_err0;
}
vid_dev->num_overlays = omap_dss_get_num_overlays();
for (i = 0; i < vid_dev->num_overlays; i++)
vid_dev->overlays[i] = omap_dss_get_overlay(i);
vid_dev->num_managers = omap_dss_get_num_overlay_managers();
for (i = 0; i < vid_dev->num_managers; i++)
vid_dev->managers[i] = omap_dss_get_overlay_manager(i);
for (i = 1; i < vid_dev->num_overlays; i++) {
ovl = omap_dss_get_overlay(i);
dssdev = ovl->get_device(ovl);
if (dssdev) {
def_display = dssdev;
} else {
dev_warn(&pdev->dev, "cannot find display\n");
def_display = NULL;
}
if (def_display) {
struct omap_dss_driver *dssdrv = def_display->driver;
ret = dssdrv->enable(def_display);
if (ret) {
dev_warn(&pdev->dev,
"'%s' Display already enabled\n",
def_display->name);
}
}
}
if (v4l2_device_register(&pdev->dev, &vid_dev->v4l2_dev) < 0) {
dev_err(&pdev->dev, "v4l2_device_register failed\n");
ret = -ENODEV;
goto probe_err1;
}
ret = omap_vout_create_video_devices(pdev);
if (ret)
goto probe_err2;
for (i = 0; i < vid_dev->num_displays; i++) {
struct omap_dss_device *display = vid_dev->displays[i];
if (display->driver->update)
display->driver->update(display, 0, 0,
display->panel.timings.x_res,
display->panel.timings.y_res);
}
return 0;
probe_err2:
v4l2_device_unregister(&vid_dev->v4l2_dev);
probe_err1:
for (i = 1; i < vid_dev->num_overlays; i++) {
def_display = NULL;
ovl = omap_dss_get_overlay(i);
dssdev = ovl->get_device(ovl);
if (dssdev)
def_display = dssdev;
if (def_display && def_display->driver)
def_display->driver->disable(def_display);
}
probe_err0:
kfree(vid_dev);
err_dss_init:
omapdss_compat_uninit();
return ret;
}
static int __init omap_vout_init(void)
{
if (platform_driver_probe(&omap_vout_driver, omap_vout_probe) != 0) {
printk(KERN_ERR VOUT_NAME ":Could not register Video driver\n");
return -EINVAL;
}
return 0;
}
static void omap_vout_cleanup(void)
{
platform_driver_unregister(&omap_vout_driver);
}
