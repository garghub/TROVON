static inline int synthvid_send(struct hv_device *hdev,
struct synthvid_msg *msg)
{
static atomic64_t request_id = ATOMIC64_INIT(0);
int ret;
msg->pipe_hdr.type = PIPE_MSG_DATA;
msg->pipe_hdr.size = msg->vid_hdr.size;
ret = vmbus_sendpacket(hdev->channel, msg,
msg->vid_hdr.size + sizeof(struct pipe_msg_hdr),
atomic64_inc_return(&request_id),
VM_PKT_DATA_INBAND, 0);
if (ret)
pr_err("Unable to send packet via vmbus\n");
return ret;
}
static int synthvid_send_situ(struct hv_device *hdev)
{
struct fb_info *info = hv_get_drvdata(hdev);
struct synthvid_msg msg;
if (!info)
return -ENODEV;
memset(&msg, 0, sizeof(struct synthvid_msg));
msg.vid_hdr.type = SYNTHVID_SITUATION_UPDATE;
msg.vid_hdr.size = sizeof(struct synthvid_msg_hdr) +
sizeof(struct synthvid_situation_update);
msg.situ.user_ctx = 0;
msg.situ.video_output_count = 1;
msg.situ.video_output[0].active = 1;
msg.situ.video_output[0].vram_offset = 0;
msg.situ.video_output[0].depth_bits = info->var.bits_per_pixel;
msg.situ.video_output[0].width_pixels = info->var.xres;
msg.situ.video_output[0].height_pixels = info->var.yres;
msg.situ.video_output[0].pitch_bytes = info->fix.line_length;
synthvid_send(hdev, &msg);
return 0;
}
static int synthvid_send_ptr(struct hv_device *hdev)
{
struct synthvid_msg msg;
memset(&msg, 0, sizeof(struct synthvid_msg));
msg.vid_hdr.type = SYNTHVID_POINTER_POSITION;
msg.vid_hdr.size = sizeof(struct synthvid_msg_hdr) +
sizeof(struct synthvid_pointer_position);
msg.ptr_pos.is_visible = 1;
msg.ptr_pos.video_output = 0;
msg.ptr_pos.image_x = 0;
msg.ptr_pos.image_y = 0;
synthvid_send(hdev, &msg);
memset(&msg, 0, sizeof(struct synthvid_msg));
msg.vid_hdr.type = SYNTHVID_POINTER_SHAPE;
msg.vid_hdr.size = sizeof(struct synthvid_msg_hdr) +
sizeof(struct synthvid_pointer_shape);
msg.ptr_shape.part_idx = CURSOR_COMPLETE;
msg.ptr_shape.is_argb = 1;
msg.ptr_shape.width = 1;
msg.ptr_shape.height = 1;
msg.ptr_shape.hot_x = 0;
msg.ptr_shape.hot_y = 0;
msg.ptr_shape.data[0] = 0;
msg.ptr_shape.data[1] = 1;
msg.ptr_shape.data[2] = 1;
msg.ptr_shape.data[3] = 1;
synthvid_send(hdev, &msg);
return 0;
}
static int synthvid_update(struct fb_info *info)
{
struct hv_device *hdev = device_to_hv_device(info->device);
struct synthvid_msg msg;
memset(&msg, 0, sizeof(struct synthvid_msg));
msg.vid_hdr.type = SYNTHVID_DIRT;
msg.vid_hdr.size = sizeof(struct synthvid_msg_hdr) +
sizeof(struct synthvid_dirt);
msg.dirt.video_output = 0;
msg.dirt.dirt_count = 1;
msg.dirt.rect[0].x1 = 0;
msg.dirt.rect[0].y1 = 0;
msg.dirt.rect[0].x2 = info->var.xres;
msg.dirt.rect[0].y2 = info->var.yres;
synthvid_send(hdev, &msg);
return 0;
}
static void synthvid_recv_sub(struct hv_device *hdev)
{
struct fb_info *info = hv_get_drvdata(hdev);
struct hvfb_par *par;
struct synthvid_msg *msg;
if (!info)
return;
par = info->par;
msg = (struct synthvid_msg *)par->recv_buf;
if (msg->vid_hdr.type == SYNTHVID_VERSION_RESPONSE ||
msg->vid_hdr.type == SYNTHVID_VRAM_LOCATION_ACK) {
memcpy(par->init_buf, msg, MAX_VMBUS_PKT_SIZE);
complete(&par->wait);
return;
}
if (msg->vid_hdr.type == SYNTHVID_FEATURE_CHANGE) {
if (par->fb_ready) {
synthvid_send_ptr(hdev);
synthvid_send_situ(hdev);
}
par->update = msg->feature_chg.is_dirt_needed;
if (par->update)
schedule_delayed_work(&par->dwork, HVFB_UPDATE_DELAY);
}
}
static void synthvid_receive(void *ctx)
{
struct hv_device *hdev = ctx;
struct fb_info *info = hv_get_drvdata(hdev);
struct hvfb_par *par;
struct synthvid_msg *recv_buf;
u32 bytes_recvd;
u64 req_id;
int ret;
if (!info)
return;
par = info->par;
recv_buf = (struct synthvid_msg *)par->recv_buf;
do {
ret = vmbus_recvpacket(hdev->channel, recv_buf,
MAX_VMBUS_PKT_SIZE,
&bytes_recvd, &req_id);
if (bytes_recvd > 0 &&
recv_buf->pipe_hdr.type == PIPE_MSG_DATA)
synthvid_recv_sub(hdev);
} while (bytes_recvd > 0 && ret == 0);
}
static int synthvid_negotiate_ver(struct hv_device *hdev, u32 ver)
{
struct fb_info *info = hv_get_drvdata(hdev);
struct hvfb_par *par = info->par;
struct synthvid_msg *msg = (struct synthvid_msg *)par->init_buf;
int t, ret = 0;
memset(msg, 0, sizeof(struct synthvid_msg));
msg->vid_hdr.type = SYNTHVID_VERSION_REQUEST;
msg->vid_hdr.size = sizeof(struct synthvid_msg_hdr) +
sizeof(struct synthvid_version_req);
msg->ver_req.version = ver;
synthvid_send(hdev, msg);
t = wait_for_completion_timeout(&par->wait, VSP_TIMEOUT);
if (!t) {
pr_err("Time out on waiting version response\n");
ret = -ETIMEDOUT;
goto out;
}
if (!msg->ver_resp.is_accepted) {
ret = -ENODEV;
goto out;
}
par->synthvid_version = ver;
out:
return ret;
}
static int synthvid_connect_vsp(struct hv_device *hdev)
{
struct fb_info *info = hv_get_drvdata(hdev);
struct hvfb_par *par = info->par;
int ret;
ret = vmbus_open(hdev->channel, RING_BUFSIZE, RING_BUFSIZE,
NULL, 0, synthvid_receive, hdev);
if (ret) {
pr_err("Unable to open vmbus channel\n");
return ret;
}
if (vmbus_proto_version == VERSION_WS2008 ||
vmbus_proto_version == VERSION_WIN7)
ret = synthvid_negotiate_ver(hdev, SYNTHVID_VERSION_WIN7);
else
ret = synthvid_negotiate_ver(hdev, SYNTHVID_VERSION_WIN8);
if (ret) {
pr_err("Synthetic video device version not accepted\n");
goto error;
}
if (par->synthvid_version == SYNTHVID_VERSION_WIN7)
screen_depth = SYNTHVID_DEPTH_WIN7;
else
screen_depth = SYNTHVID_DEPTH_WIN8;
screen_fb_size = hdev->channel->offermsg.offer.
mmio_megabytes * 1024 * 1024;
return 0;
error:
vmbus_close(hdev->channel);
return ret;
}
static int synthvid_send_config(struct hv_device *hdev)
{
struct fb_info *info = hv_get_drvdata(hdev);
struct hvfb_par *par = info->par;
struct synthvid_msg *msg = (struct synthvid_msg *)par->init_buf;
int t, ret = 0;
memset(msg, 0, sizeof(struct synthvid_msg));
msg->vid_hdr.type = SYNTHVID_VRAM_LOCATION;
msg->vid_hdr.size = sizeof(struct synthvid_msg_hdr) +
sizeof(struct synthvid_vram_location);
msg->vram.user_ctx = msg->vram.vram_gpa = info->fix.smem_start;
msg->vram.is_vram_gpa_specified = 1;
synthvid_send(hdev, msg);
t = wait_for_completion_timeout(&par->wait, VSP_TIMEOUT);
if (!t) {
pr_err("Time out on waiting vram location ack\n");
ret = -ETIMEDOUT;
goto out;
}
if (msg->vram_ack.user_ctx != info->fix.smem_start) {
pr_err("Unable to set VRAM location\n");
ret = -ENODEV;
goto out;
}
synthvid_send_ptr(hdev);
synthvid_send_situ(hdev);
out:
return ret;
}
static void hvfb_update_work(struct work_struct *w)
{
struct hvfb_par *par = container_of(w, struct hvfb_par, dwork.work);
struct fb_info *info = par->info;
if (par->fb_ready)
synthvid_update(info);
if (par->update)
schedule_delayed_work(&par->dwork, HVFB_UPDATE_DELAY);
}
static int hvfb_on_panic(struct notifier_block *nb,
unsigned long e, void *p)
{
struct hvfb_par *par;
struct fb_info *info;
par = container_of(nb, struct hvfb_par, hvfb_panic_nb);
par->synchronous_fb = true;
info = par->info;
synthvid_update(info);
return NOTIFY_DONE;
}
static int hvfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
if (var->xres < HVFB_WIDTH_MIN || var->yres < HVFB_HEIGHT_MIN ||
var->xres > screen_width || var->yres > screen_height ||
var->bits_per_pixel != screen_depth)
return -EINVAL;
var->xres_virtual = var->xres;
var->yres_virtual = var->yres;
return 0;
}
static int hvfb_set_par(struct fb_info *info)
{
struct hv_device *hdev = device_to_hv_device(info->device);
return synthvid_send_situ(hdev);
}
static inline u32 chan_to_field(u32 chan, struct fb_bitfield *bf)
{
return ((chan & 0xffff) >> (16 - bf->length)) << bf->offset;
}
static int hvfb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp, struct fb_info *info)
{
u32 *pal = info->pseudo_palette;
if (regno > 15)
return -EINVAL;
pal[regno] = chan_to_field(red, &info->var.red)
| chan_to_field(green, &info->var.green)
| chan_to_field(blue, &info->var.blue)
| chan_to_field(transp, &info->var.transp);
return 0;
}
static int hvfb_blank(int blank, struct fb_info *info)
{
return 1;
}
static void hvfb_cfb_fillrect(struct fb_info *p,
const struct fb_fillrect *rect)
{
struct hvfb_par *par = p->par;
cfb_fillrect(p, rect);
if (par->synchronous_fb)
synthvid_update(p);
}
static void hvfb_cfb_copyarea(struct fb_info *p,
const struct fb_copyarea *area)
{
struct hvfb_par *par = p->par;
cfb_copyarea(p, area);
if (par->synchronous_fb)
synthvid_update(p);
}
static void hvfb_cfb_imageblit(struct fb_info *p,
const struct fb_image *image)
{
struct hvfb_par *par = p->par;
cfb_imageblit(p, image);
if (par->synchronous_fb)
synthvid_update(p);
}
static void hvfb_get_option(struct fb_info *info)
{
struct hvfb_par *par = info->par;
char *opt = NULL, *p;
uint x = 0, y = 0;
if (fb_get_options(KBUILD_MODNAME, &opt) || !opt || !*opt)
return;
p = strsep(&opt, "x");
if (!*p || kstrtouint(p, 0, &x) ||
!opt || !*opt || kstrtouint(opt, 0, &y)) {
pr_err("Screen option is invalid: skipped\n");
return;
}
if (x < HVFB_WIDTH_MIN || y < HVFB_HEIGHT_MIN ||
(par->synthvid_version == SYNTHVID_VERSION_WIN8 &&
x * y * screen_depth / 8 > SYNTHVID_FB_SIZE_WIN8) ||
(par->synthvid_version == SYNTHVID_VERSION_WIN7 &&
(x > SYNTHVID_WIDTH_MAX_WIN7 || y > SYNTHVID_HEIGHT_MAX_WIN7))) {
pr_err("Screen resolution option is out of range: skipped\n");
return;
}
screen_width = x;
screen_height = y;
return;
}
static int hvfb_getmem(struct fb_info *info)
{
struct hvfb_par *par = info->par;
struct pci_dev *pdev = NULL;
void __iomem *fb_virt;
int gen2vm = efi_enabled(EFI_BOOT);
int ret;
par->mem.name = KBUILD_MODNAME;
par->mem.flags = IORESOURCE_MEM | IORESOURCE_BUSY;
if (gen2vm) {
ret = allocate_resource(&hyperv_mmio, &par->mem,
screen_fb_size,
0, -1,
screen_fb_size,
NULL, NULL);
if (ret != 0) {
pr_err("Unable to allocate framebuffer memory\n");
return -ENODEV;
}
} else {
pdev = pci_get_device(PCI_VENDOR_ID_MICROSOFT,
PCI_DEVICE_ID_HYPERV_VIDEO, NULL);
if (!pdev) {
pr_err("Unable to find PCI Hyper-V video\n");
return -ENODEV;
}
if (!(pci_resource_flags(pdev, 0) & IORESOURCE_MEM) ||
pci_resource_len(pdev, 0) < screen_fb_size)
goto err1;
par->mem.end = pci_resource_end(pdev, 0);
par->mem.start = par->mem.end - screen_fb_size + 1;
ret = request_resource(&pdev->resource[0], &par->mem);
if (ret != 0) {
pr_err("Unable to request framebuffer memory\n");
goto err1;
}
}
fb_virt = ioremap(par->mem.start, screen_fb_size);
if (!fb_virt)
goto err2;
info->apertures = alloc_apertures(1);
if (!info->apertures)
goto err3;
if (gen2vm) {
info->apertures->ranges[0].base = screen_info.lfb_base;
info->apertures->ranges[0].size = screen_info.lfb_size;
remove_conflicting_framebuffers(info->apertures,
KBUILD_MODNAME, false);
} else {
info->apertures->ranges[0].base = pci_resource_start(pdev, 0);
info->apertures->ranges[0].size = pci_resource_len(pdev, 0);
}
info->fix.smem_start = par->mem.start;
info->fix.smem_len = screen_fb_size;
info->screen_base = fb_virt;
info->screen_size = screen_fb_size;
if (!gen2vm)
pci_dev_put(pdev);
return 0;
err3:
iounmap(fb_virt);
err2:
release_resource(&par->mem);
err1:
if (!gen2vm)
pci_dev_put(pdev);
return -ENOMEM;
}
static void hvfb_putmem(struct fb_info *info)
{
struct hvfb_par *par = info->par;
iounmap(info->screen_base);
release_resource(&par->mem);
}
static int hvfb_probe(struct hv_device *hdev,
const struct hv_vmbus_device_id *dev_id)
{
struct fb_info *info;
struct hvfb_par *par;
int ret;
info = framebuffer_alloc(sizeof(struct hvfb_par), &hdev->device);
if (!info) {
pr_err("No memory for framebuffer info\n");
return -ENOMEM;
}
par = info->par;
par->info = info;
par->fb_ready = false;
init_completion(&par->wait);
INIT_DELAYED_WORK(&par->dwork, hvfb_update_work);
hv_set_drvdata(hdev, info);
ret = synthvid_connect_vsp(hdev);
if (ret) {
pr_err("Unable to connect to VSP\n");
goto error1;
}
ret = hvfb_getmem(info);
if (ret) {
pr_err("No memory for framebuffer\n");
goto error2;
}
hvfb_get_option(info);
pr_info("Screen resolution: %dx%d, Color depth: %d\n",
screen_width, screen_height, screen_depth);
info->flags = FBINFO_DEFAULT;
info->var.xres_virtual = info->var.xres = screen_width;
info->var.yres_virtual = info->var.yres = screen_height;
info->var.bits_per_pixel = screen_depth;
if (info->var.bits_per_pixel == 16) {
info->var.red = (struct fb_bitfield){11, 5, 0};
info->var.green = (struct fb_bitfield){5, 6, 0};
info->var.blue = (struct fb_bitfield){0, 5, 0};
info->var.transp = (struct fb_bitfield){0, 0, 0};
} else {
info->var.red = (struct fb_bitfield){16, 8, 0};
info->var.green = (struct fb_bitfield){8, 8, 0};
info->var.blue = (struct fb_bitfield){0, 8, 0};
info->var.transp = (struct fb_bitfield){24, 8, 0};
}
info->var.activate = FB_ACTIVATE_NOW;
info->var.height = -1;
info->var.width = -1;
info->var.vmode = FB_VMODE_NONINTERLACED;
strcpy(info->fix.id, KBUILD_MODNAME);
info->fix.type = FB_TYPE_PACKED_PIXELS;
info->fix.visual = FB_VISUAL_TRUECOLOR;
info->fix.line_length = screen_width * screen_depth / 8;
info->fix.accel = FB_ACCEL_NONE;
info->fbops = &hvfb_ops;
info->pseudo_palette = par->pseudo_palette;
ret = synthvid_send_config(hdev);
if (ret)
goto error;
ret = register_framebuffer(info);
if (ret) {
pr_err("Unable to register framebuffer\n");
goto error;
}
par->fb_ready = true;
par->synchronous_fb = false;
par->hvfb_panic_nb.notifier_call = hvfb_on_panic;
atomic_notifier_chain_register(&panic_notifier_list,
&par->hvfb_panic_nb);
return 0;
error:
hvfb_putmem(info);
error2:
vmbus_close(hdev->channel);
error1:
cancel_delayed_work_sync(&par->dwork);
hv_set_drvdata(hdev, NULL);
framebuffer_release(info);
return ret;
}
static int hvfb_remove(struct hv_device *hdev)
{
struct fb_info *info = hv_get_drvdata(hdev);
struct hvfb_par *par = info->par;
atomic_notifier_chain_unregister(&panic_notifier_list,
&par->hvfb_panic_nb);
par->update = false;
par->fb_ready = false;
unregister_framebuffer(info);
cancel_delayed_work_sync(&par->dwork);
vmbus_close(hdev->channel);
hv_set_drvdata(hdev, NULL);
hvfb_putmem(info);
framebuffer_release(info);
return 0;
}
static int hvfb_pci_stub_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
return 0;
}
static void hvfb_pci_stub_remove(struct pci_dev *pdev)
{
}
static int __init hvfb_drv_init(void)
{
int ret;
ret = vmbus_driver_register(&hvfb_drv);
if (ret != 0)
return ret;
ret = pci_register_driver(&hvfb_pci_stub_driver);
if (ret != 0) {
vmbus_driver_unregister(&hvfb_drv);
return ret;
}
return 0;
}
static void __exit hvfb_drv_exit(void)
{
pci_unregister_driver(&hvfb_pci_stub_driver);
vmbus_driver_unregister(&hvfb_drv);
}
