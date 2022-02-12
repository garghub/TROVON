static int msmfb_open(struct fb_info *info, int user)
{
return 0;
}
static int msmfb_release(struct fb_info *info, int user)
{
return 0;
}
static void msmfb_handle_dma_interrupt(struct msmfb_callback *callback)
{
unsigned long irq_flags;
struct msmfb_info *msmfb = container_of(callback, struct msmfb_info,
dma_callback);
spin_lock_irqsave(&msmfb->update_lock, irq_flags);
msmfb->frame_done = msmfb->frame_requested;
if (msmfb->sleeping == UPDATING &&
msmfb->frame_done == msmfb->update_frame) {
DLOG(SUSPEND_RESUME, "full update completed\n");
schedule_work(&msmfb->resume_work);
}
spin_unlock_irqrestore(&msmfb->update_lock, irq_flags);
wake_up(&msmfb->frame_wq);
}
static int msmfb_start_dma(struct msmfb_info *msmfb)
{
uint32_t x, y, w, h;
unsigned addr;
unsigned long irq_flags;
uint32_t yoffset;
s64 time_since_request;
struct msm_panel_data *panel = msmfb->panel;
spin_lock_irqsave(&msmfb->update_lock, irq_flags);
time_since_request = ktime_to_ns(ktime_sub(ktime_get(),
msmfb->vsync_request_time));
if (time_since_request > 20 * NSEC_PER_MSEC) {
uint32_t us;
us = do_div(time_since_request, NSEC_PER_MSEC) / NSEC_PER_USEC;
printk(KERN_WARNING "msmfb_start_dma %lld.%03u ms after vsync "
"request\n", time_since_request, us);
}
if (msmfb->frame_done == msmfb->frame_requested) {
spin_unlock_irqrestore(&msmfb->update_lock, irq_flags);
return -1;
}
if (msmfb->sleeping == SLEEPING) {
DLOG(SUSPEND_RESUME, "tried to start dma while asleep\n");
spin_unlock_irqrestore(&msmfb->update_lock, irq_flags);
return -1;
}
x = msmfb->update_info.left;
y = msmfb->update_info.top;
w = msmfb->update_info.eright - x;
h = msmfb->update_info.ebottom - y;
yoffset = msmfb->yoffset;
msmfb->update_info.left = msmfb->xres + 1;
msmfb->update_info.top = msmfb->yres + 1;
msmfb->update_info.eright = 0;
msmfb->update_info.ebottom = 0;
if (unlikely(w > msmfb->xres || h > msmfb->yres ||
w == 0 || h == 0)) {
printk(KERN_INFO "invalid update: %d %d %d "
"%d\n", x, y, w, h);
msmfb->frame_done = msmfb->frame_requested;
goto error;
}
spin_unlock_irqrestore(&msmfb->update_lock, irq_flags);
addr = ((msmfb->xres * (yoffset + y) + x) * 2);
mdp->dma(mdp, addr + msmfb->fb->fix.smem_start,
msmfb->xres * 2, w, h, x, y, &msmfb->dma_callback,
panel->interface_type);
return 0;
error:
spin_unlock_irqrestore(&msmfb->update_lock, irq_flags);
if (panel->clear_vsync)
panel->clear_vsync(panel);
wake_up(&msmfb->frame_wq);
return 0;
}
static void msmfb_handle_vsync_interrupt(struct msmfb_callback *callback)
{
struct msmfb_info *msmfb = container_of(callback, struct msmfb_info,
vsync_callback);
msmfb_start_dma(msmfb);
}
static enum hrtimer_restart msmfb_fake_vsync(struct hrtimer *timer)
{
struct msmfb_info *msmfb = container_of(timer, struct msmfb_info,
fake_vsync);
msmfb_start_dma(msmfb);
return HRTIMER_NORESTART;
}
static void msmfb_pan_update(struct fb_info *info, uint32_t left, uint32_t top,
uint32_t eright, uint32_t ebottom,
uint32_t yoffset, int pan_display)
{
struct msmfb_info *msmfb = info->par;
struct msm_panel_data *panel = msmfb->panel;
unsigned long irq_flags;
int sleeping;
int retry = 1;
DLOG(SHOW_UPDATES, "update %d %d %d %d %d %d\n",
left, top, eright, ebottom, yoffset, pan_display);
restart:
spin_lock_irqsave(&msmfb->update_lock, irq_flags);
if (msmfb->sleeping == SLEEPING) {
DLOG(SUSPEND_RESUME, "drawing while asleep\n");
spin_unlock_irqrestore(&msmfb->update_lock, irq_flags);
if (pan_display)
wait_event_interruptible_timeout(msmfb->frame_wq,
msmfb->sleeping != SLEEPING, HZ/10);
return;
}
sleeping = msmfb->sleeping;
if ((pan_display && msmfb->frame_requested != msmfb->frame_done) ||
sleeping == UPDATING) {
int ret;
spin_unlock_irqrestore(&msmfb->update_lock, irq_flags);
ret = wait_event_interruptible_timeout(msmfb->frame_wq,
msmfb->frame_done == msmfb->frame_requested &&
msmfb->sleeping != UPDATING, 5 * HZ);
if (ret <= 0 && (msmfb->frame_requested != msmfb->frame_done ||
msmfb->sleeping == UPDATING)) {
if (retry && panel->request_vsync &&
(sleeping == AWAKE)) {
panel->request_vsync(panel,
&msmfb->vsync_callback);
retry = 0;
printk(KERN_WARNING "msmfb_pan_display timeout "
"rerequest vsync\n");
} else {
printk(KERN_WARNING "msmfb_pan_display timeout "
"waiting for frame start, %d %d\n",
msmfb->frame_requested,
msmfb->frame_done);
return;
}
}
goto restart;
}
msmfb->frame_requested++;
if (pan_display) {
msmfb->yoffset = yoffset;
if (left == 0 && top == 0 && eright == info->var.xres &&
ebottom == info->var.yres) {
if (sleeping == WAKING) {
msmfb->update_frame = msmfb->frame_requested;
DLOG(SUSPEND_RESUME, "full update starting\n");
msmfb->sleeping = UPDATING;
}
}
}
if (left < msmfb->update_info.left)
msmfb->update_info.left = left;
if (top < msmfb->update_info.top)
msmfb->update_info.top = top;
if (eright > msmfb->update_info.eright)
msmfb->update_info.eright = eright;
if (ebottom > msmfb->update_info.ebottom)
msmfb->update_info.ebottom = ebottom;
DLOG(SHOW_UPDATES, "update queued %d %d %d %d %d\n",
msmfb->update_info.left, msmfb->update_info.top,
msmfb->update_info.eright, msmfb->update_info.ebottom,
msmfb->yoffset);
spin_unlock_irqrestore(&msmfb->update_lock, irq_flags);
msmfb->vsync_request_time = ktime_get();
if (panel->request_vsync && (sleeping == AWAKE)) {
panel->request_vsync(panel, &msmfb->vsync_callback);
} else {
if (!hrtimer_active(&msmfb->fake_vsync)) {
hrtimer_start(&msmfb->fake_vsync,
ktime_set(0, NSEC_PER_SEC/60),
HRTIMER_MODE_REL);
}
}
}
static void msmfb_update(struct fb_info *info, uint32_t left, uint32_t top,
uint32_t eright, uint32_t ebottom)
{
msmfb_pan_update(info, left, top, eright, ebottom, 0, 0);
}
static void power_on_panel(struct work_struct *work)
{
struct msmfb_info *msmfb =
container_of(work, struct msmfb_info, resume_work);
struct msm_panel_data *panel = msmfb->panel;
unsigned long irq_flags;
mutex_lock(&msmfb->panel_init_lock);
DLOG(SUSPEND_RESUME, "turning on panel\n");
if (msmfb->sleeping == UPDATING) {
if (panel->unblank(panel)) {
printk(KERN_INFO "msmfb: panel unblank failed,"
"not starting drawing\n");
goto error;
}
spin_lock_irqsave(&msmfb->update_lock, irq_flags);
msmfb->sleeping = AWAKE;
wake_up(&msmfb->frame_wq);
spin_unlock_irqrestore(&msmfb->update_lock, irq_flags);
}
error:
mutex_unlock(&msmfb->panel_init_lock);
}
static int msmfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
if ((var->xres != info->var.xres) ||
(var->yres != info->var.yres) ||
(var->xres_virtual != info->var.xres_virtual) ||
(var->yres_virtual != info->var.yres_virtual) ||
(var->xoffset != info->var.xoffset) ||
(var->bits_per_pixel != info->var.bits_per_pixel) ||
(var->grayscale != info->var.grayscale))
return -EINVAL;
return 0;
}
int msmfb_pan_display(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct msmfb_info *msmfb = info->par;
struct msm_panel_data *panel = msmfb->panel;
if ((panel->caps & MSMFB_CAP_PARTIAL_UPDATES) &&
(var->reserved[0] == 0x54445055)) {
msmfb_pan_update(info, var->reserved[1] & 0xffff,
var->reserved[1] >> 16,
var->reserved[2] & 0xffff,
var->reserved[2] >> 16, var->yoffset, 1);
} else {
msmfb_pan_update(info, 0, 0, info->var.xres, info->var.yres,
var->yoffset, 1);
}
return 0;
}
static void msmfb_fillrect(struct fb_info *p, const struct fb_fillrect *rect)
{
cfb_fillrect(p, rect);
msmfb_update(p, rect->dx, rect->dy, rect->dx + rect->width,
rect->dy + rect->height);
}
static void msmfb_copyarea(struct fb_info *p, const struct fb_copyarea *area)
{
cfb_copyarea(p, area);
msmfb_update(p, area->dx, area->dy, area->dx + area->width,
area->dy + area->height);
}
static void msmfb_imageblit(struct fb_info *p, const struct fb_image *image)
{
cfb_imageblit(p, image);
msmfb_update(p, image->dx, image->dy, image->dx + image->width,
image->dy + image->height);
}
static int msmfb_blit(struct fb_info *info,
void __user *p)
{
struct mdp_blit_req req;
struct mdp_blit_req_list req_list;
int i;
int ret;
if (copy_from_user(&req_list, p, sizeof(req_list)))
return -EFAULT;
for (i = 0; i < req_list.count; i++) {
struct mdp_blit_req_list *list =
(struct mdp_blit_req_list *)p;
if (copy_from_user(&req, &list->req[i], sizeof(req)))
return -EFAULT;
ret = mdp->blit(mdp, info, &req);
if (ret)
return ret;
}
return 0;
}
static int msmfb_ioctl(struct fb_info *p, unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
int ret;
switch (cmd) {
case MSMFB_GRP_DISP:
mdp->set_grp_disp(mdp, arg);
break;
case MSMFB_BLIT:
ret = msmfb_blit(p, argp);
if (ret)
return ret;
break;
default:
printk(KERN_INFO "msmfb unknown ioctl: %d\n", cmd);
return -EINVAL;
}
return 0;
}
static void setup_fb_info(struct msmfb_info *msmfb)
{
struct fb_info *fb_info = msmfb->fb;
int r;
strncpy(fb_info->fix.id, "msmfb", 16);
fb_info->fix.ypanstep = 1;
fb_info->fbops = &msmfb_ops;
fb_info->flags = FBINFO_DEFAULT;
fb_info->fix.type = FB_TYPE_PACKED_PIXELS;
fb_info->fix.visual = FB_VISUAL_TRUECOLOR;
fb_info->fix.line_length = msmfb->xres * 2;
fb_info->var.xres = msmfb->xres;
fb_info->var.yres = msmfb->yres;
fb_info->var.width = msmfb->panel->fb_data->width;
fb_info->var.height = msmfb->panel->fb_data->height;
fb_info->var.xres_virtual = msmfb->xres;
fb_info->var.yres_virtual = msmfb->yres * 2;
fb_info->var.bits_per_pixel = BITS_PER_PIXEL;
fb_info->var.accel_flags = 0;
fb_info->var.yoffset = 0;
if (msmfb->panel->caps & MSMFB_CAP_PARTIAL_UPDATES) {
fb_info->fix.reserved[0] = 0x5444;
fb_info->fix.reserved[1] = 0x5055;
fb_info->var.reserved[0] = 0x54445055;
fb_info->var.reserved[1] = 0;
fb_info->var.reserved[2] = (uint16_t)msmfb->xres |
((uint32_t)msmfb->yres << 16);
}
fb_info->var.red.offset = 11;
fb_info->var.red.length = 5;
fb_info->var.red.msb_right = 0;
fb_info->var.green.offset = 5;
fb_info->var.green.length = 6;
fb_info->var.green.msb_right = 0;
fb_info->var.blue.offset = 0;
fb_info->var.blue.length = 5;
fb_info->var.blue.msb_right = 0;
r = fb_alloc_cmap(&fb_info->cmap, 16, 0);
fb_info->pseudo_palette = PP;
PP[0] = 0;
for (r = 1; r < 16; r++)
PP[r] = 0xffffffff;
}
static int setup_fbmem(struct msmfb_info *msmfb, struct platform_device *pdev)
{
struct fb_info *fb = msmfb->fb;
struct resource *resource;
unsigned long size = msmfb->xres * msmfb->yres *
(BITS_PER_PIXEL >> 3) * 2;
unsigned char *fbram;
resource = platform_get_resource(pdev, IORESOURCE_MEM, 0);
if (!resource)
return -EINVAL;
if (resource->end - resource->start < size) {
printk(KERN_ERR "allocated resource is too small for "
"fb\n");
return -ENOMEM;
}
fb->fix.smem_start = resource->start;
fb->fix.smem_len = resource_size(resource);
fbram = ioremap(resource->start, resource_size(resource));
if (fbram == NULL) {
printk(KERN_ERR "msmfb: cannot allocate fbram!\n");
return -ENOMEM;
}
fb->screen_base = fbram;
return 0;
}
static int msmfb_probe(struct platform_device *pdev)
{
struct fb_info *fb;
struct msmfb_info *msmfb;
struct msm_panel_data *panel = pdev->dev.platform_data;
int ret;
if (!panel) {
pr_err("msmfb_probe: no platform data\n");
return -EINVAL;
}
if (!panel->fb_data) {
pr_err("msmfb_probe: no fb_data\n");
return -EINVAL;
}
fb = framebuffer_alloc(sizeof(struct msmfb_info), &pdev->dev);
if (!fb)
return -ENOMEM;
msmfb = fb->par;
msmfb->fb = fb;
msmfb->panel = panel;
msmfb->xres = panel->fb_data->xres;
msmfb->yres = panel->fb_data->yres;
ret = setup_fbmem(msmfb, pdev);
if (ret)
goto error_setup_fbmem;
setup_fb_info(msmfb);
spin_lock_init(&msmfb->update_lock);
mutex_init(&msmfb->panel_init_lock);
init_waitqueue_head(&msmfb->frame_wq);
INIT_WORK(&msmfb->resume_work, power_on_panel);
msmfb->black = devm_kzalloc(&pdev->dev,
msmfb->fb->var.bits_per_pixel*msmfb->xres,
GFP_KERNEL);
if (!msmfb->black) {
ret = -ENOMEM;
goto error_register_framebuffer;
}
printk(KERN_INFO "msmfb_probe() installing %d x %d panel\n",
msmfb->xres, msmfb->yres);
msmfb->dma_callback.func = msmfb_handle_dma_interrupt;
msmfb->vsync_callback.func = msmfb_handle_vsync_interrupt;
hrtimer_init(&msmfb->fake_vsync, CLOCK_MONOTONIC,
HRTIMER_MODE_REL);
msmfb->fake_vsync.function = msmfb_fake_vsync;
ret = register_framebuffer(fb);
if (ret)
goto error_register_framebuffer;
msmfb->sleeping = WAKING;
platform_set_drvdata(pdev, msmfb);
return 0;
error_register_framebuffer:
iounmap(fb->screen_base);
error_setup_fbmem:
framebuffer_release(msmfb->fb);
return ret;
}
static int msmfb_remove(struct platform_device *pdev)
{
struct msmfb_info *msmfb;
msmfb = platform_get_drvdata(pdev);
unregister_framebuffer(msmfb->fb);
iounmap(msmfb->fb->screen_base);
framebuffer_release(msmfb->fb);
return 0;
}
static int msmfb_add_mdp_device(struct device *dev,
struct class_interface *class_intf)
{
if (mdp)
return 0;
mdp = container_of(dev, struct mdp_device, dev);
return platform_driver_register(&msm_panel_driver);
}
static void msmfb_remove_mdp_device(struct device *dev,
struct class_interface *class_intf)
{
if (dev != &mdp->dev)
return;
platform_driver_unregister(&msm_panel_driver);
mdp = NULL;
}
static int __init msmfb_init(void)
{
return register_mdp_client(&msm_fb_interface);
}
