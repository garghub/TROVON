static void xenfb_send_event(struct xenfb_info *info,
union xenfb_out_event *event)
{
u32 prod;
prod = info->page->out_prod;
mb();
XENFB_OUT_RING_REF(info->page, prod) = *event;
wmb();
info->page->out_prod = prod + 1;
notify_remote_via_irq(info->irq);
}
static void xenfb_do_update(struct xenfb_info *info,
int x, int y, int w, int h)
{
union xenfb_out_event event;
memset(&event, 0, sizeof(event));
event.type = XENFB_TYPE_UPDATE;
event.update.x = x;
event.update.y = y;
event.update.width = w;
event.update.height = h;
xenfb_send_event(info, &event);
}
static void xenfb_do_resize(struct xenfb_info *info)
{
union xenfb_out_event event;
memset(&event, 0, sizeof(event));
event.resize = info->resize;
xenfb_send_event(info, &event);
}
static int xenfb_queue_full(struct xenfb_info *info)
{
u32 cons, prod;
prod = info->page->out_prod;
cons = info->page->out_cons;
return prod - cons == XENFB_OUT_RING_LEN;
}
static void xenfb_handle_resize_dpy(struct xenfb_info *info)
{
unsigned long flags;
spin_lock_irqsave(&info->resize_lock, flags);
if (info->resize_dpy) {
if (!xenfb_queue_full(info)) {
info->resize_dpy = 0;
xenfb_do_resize(info);
}
}
spin_unlock_irqrestore(&info->resize_lock, flags);
}
static void xenfb_refresh(struct xenfb_info *info,
int x1, int y1, int w, int h)
{
unsigned long flags;
int x2 = x1 + w - 1;
int y2 = y1 + h - 1;
xenfb_handle_resize_dpy(info);
if (!info->update_wanted)
return;
spin_lock_irqsave(&info->dirty_lock, flags);
if (info->y1 < y1)
y1 = info->y1;
if (info->y2 > y2)
y2 = info->y2;
if (info->x1 < x1)
x1 = info->x1;
if (info->x2 > x2)
x2 = info->x2;
if (xenfb_queue_full(info)) {
info->x1 = x1;
info->x2 = x2;
info->y1 = y1;
info->y2 = y2;
spin_unlock_irqrestore(&info->dirty_lock, flags);
return;
}
info->x1 = info->y1 = INT_MAX;
info->x2 = info->y2 = 0;
spin_unlock_irqrestore(&info->dirty_lock, flags);
if (x1 <= x2 && y1 <= y2)
xenfb_do_update(info, x1, y1, x2 - x1 + 1, y2 - y1 + 1);
}
static void xenfb_deferred_io(struct fb_info *fb_info,
struct list_head *pagelist)
{
struct xenfb_info *info = fb_info->par;
struct page *page;
unsigned long beg, end;
int y1, y2, miny, maxy;
miny = INT_MAX;
maxy = 0;
list_for_each_entry(page, pagelist, lru) {
beg = page->index << PAGE_SHIFT;
end = beg + PAGE_SIZE - 1;
y1 = beg / fb_info->fix.line_length;
y2 = end / fb_info->fix.line_length;
if (y2 >= fb_info->var.yres)
y2 = fb_info->var.yres - 1;
if (miny > y1)
miny = y1;
if (maxy < y2)
maxy = y2;
}
xenfb_refresh(info, 0, miny, fb_info->var.xres, maxy - miny + 1);
}
static int xenfb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp,
struct fb_info *info)
{
u32 v;
if (regno > info->cmap.len)
return 1;
#define CNVT_TOHW(val, width) ((((val)<<(width))+0x7FFF-(val))>>16)
red = CNVT_TOHW(red, info->var.red.length);
green = CNVT_TOHW(green, info->var.green.length);
blue = CNVT_TOHW(blue, info->var.blue.length);
transp = CNVT_TOHW(transp, info->var.transp.length);
#undef CNVT_TOHW
v = (red << info->var.red.offset) |
(green << info->var.green.offset) |
(blue << info->var.blue.offset);
switch (info->var.bits_per_pixel) {
case 16:
case 24:
case 32:
((u32 *)info->pseudo_palette)[regno] = v;
break;
}
return 0;
}
static void xenfb_fillrect(struct fb_info *p, const struct fb_fillrect *rect)
{
struct xenfb_info *info = p->par;
sys_fillrect(p, rect);
xenfb_refresh(info, rect->dx, rect->dy, rect->width, rect->height);
}
static void xenfb_imageblit(struct fb_info *p, const struct fb_image *image)
{
struct xenfb_info *info = p->par;
sys_imageblit(p, image);
xenfb_refresh(info, image->dx, image->dy, image->width, image->height);
}
static void xenfb_copyarea(struct fb_info *p, const struct fb_copyarea *area)
{
struct xenfb_info *info = p->par;
sys_copyarea(p, area);
xenfb_refresh(info, area->dx, area->dy, area->width, area->height);
}
static ssize_t xenfb_write(struct fb_info *p, const char __user *buf,
size_t count, loff_t *ppos)
{
struct xenfb_info *info = p->par;
ssize_t res;
res = fb_sys_write(p, buf, count, ppos);
xenfb_refresh(info, 0, 0, info->page->width, info->page->height);
return res;
}
static int
xenfb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
struct xenfb_info *xenfb_info;
int required_mem_len;
xenfb_info = info->par;
if (!xenfb_info->feature_resize) {
if (var->xres == video[KPARAM_WIDTH] &&
var->yres == video[KPARAM_HEIGHT] &&
var->bits_per_pixel == xenfb_info->page->depth) {
return 0;
}
return -EINVAL;
}
if (var->xres > video[KPARAM_WIDTH] || var->yres > video[KPARAM_HEIGHT])
return -EINVAL;
required_mem_len = var->xres * var->yres * xenfb_info->page->depth / 8;
if (var->bits_per_pixel == xenfb_info->page->depth &&
var->xres <= info->fix.line_length / (XENFB_DEPTH / 8) &&
required_mem_len <= info->fix.smem_len) {
var->xres_virtual = var->xres;
var->yres_virtual = var->yres;
return 0;
}
return -EINVAL;
}
static int xenfb_set_par(struct fb_info *info)
{
struct xenfb_info *xenfb_info;
unsigned long flags;
xenfb_info = info->par;
spin_lock_irqsave(&xenfb_info->resize_lock, flags);
xenfb_info->resize.type = XENFB_TYPE_RESIZE;
xenfb_info->resize.width = info->var.xres;
xenfb_info->resize.height = info->var.yres;
xenfb_info->resize.stride = info->fix.line_length;
xenfb_info->resize.depth = info->var.bits_per_pixel;
xenfb_info->resize.offset = 0;
xenfb_info->resize_dpy = 1;
spin_unlock_irqrestore(&xenfb_info->resize_lock, flags);
return 0;
}
static irqreturn_t xenfb_event_handler(int rq, void *dev_id)
{
struct xenfb_info *info = dev_id;
struct xenfb_page *page = info->page;
if (page->in_cons != page->in_prod) {
info->page->in_cons = info->page->in_prod;
notify_remote_via_irq(info->irq);
}
xenfb_refresh(info, INT_MAX, INT_MAX, -INT_MAX, -INT_MAX);
return IRQ_HANDLED;
}
static int __devinit xenfb_probe(struct xenbus_device *dev,
const struct xenbus_device_id *id)
{
struct xenfb_info *info;
struct fb_info *fb_info;
int fb_size;
int val;
int ret;
info = kzalloc(sizeof(*info), GFP_KERNEL);
if (info == NULL) {
xenbus_dev_fatal(dev, -ENOMEM, "allocating info structure");
return -ENOMEM;
}
if (xenbus_scanf(XBT_NIL, dev->otherend, "videoram", "%d", &val) == 1) {
if (val < video[KPARAM_MEM])
video[KPARAM_MEM] = val;
}
fb_size = video[KPARAM_MEM] * 1024 * 1024;
if (video[KPARAM_WIDTH] * video[KPARAM_HEIGHT] * XENFB_DEPTH / 8
> fb_size) {
video[KPARAM_WIDTH] = XENFB_WIDTH;
video[KPARAM_HEIGHT] = XENFB_HEIGHT;
fb_size = XENFB_DEFAULT_FB_LEN;
}
dev_set_drvdata(&dev->dev, info);
info->xbdev = dev;
info->irq = -1;
info->x1 = info->y1 = INT_MAX;
spin_lock_init(&info->dirty_lock);
spin_lock_init(&info->resize_lock);
info->fb = vzalloc(fb_size);
if (info->fb == NULL)
goto error_nomem;
info->nr_pages = (fb_size + PAGE_SIZE - 1) >> PAGE_SHIFT;
info->mfns = vmalloc(sizeof(unsigned long) * info->nr_pages);
if (!info->mfns)
goto error_nomem;
info->page = (void *)__get_free_page(GFP_KERNEL | __GFP_ZERO);
if (!info->page)
goto error_nomem;
fb_info = framebuffer_alloc(sizeof(u32) * 256, NULL);
if (fb_info == NULL)
goto error_nomem;
fb_info->pseudo_palette = fb_info->par;
fb_info->par = info;
fb_info->screen_base = info->fb;
fb_info->fbops = &xenfb_fb_ops;
fb_info->var.xres_virtual = fb_info->var.xres = video[KPARAM_WIDTH];
fb_info->var.yres_virtual = fb_info->var.yres = video[KPARAM_HEIGHT];
fb_info->var.bits_per_pixel = XENFB_DEPTH;
fb_info->var.red = (struct fb_bitfield){16, 8, 0};
fb_info->var.green = (struct fb_bitfield){8, 8, 0};
fb_info->var.blue = (struct fb_bitfield){0, 8, 0};
fb_info->var.activate = FB_ACTIVATE_NOW;
fb_info->var.height = -1;
fb_info->var.width = -1;
fb_info->var.vmode = FB_VMODE_NONINTERLACED;
fb_info->fix.visual = FB_VISUAL_TRUECOLOR;
fb_info->fix.line_length = fb_info->var.xres * XENFB_DEPTH / 8;
fb_info->fix.smem_start = 0;
fb_info->fix.smem_len = fb_size;
strcpy(fb_info->fix.id, "xen");
fb_info->fix.type = FB_TYPE_PACKED_PIXELS;
fb_info->fix.accel = FB_ACCEL_NONE;
fb_info->flags = FBINFO_FLAG_DEFAULT | FBINFO_VIRTFB;
ret = fb_alloc_cmap(&fb_info->cmap, 256, 0);
if (ret < 0) {
framebuffer_release(fb_info);
xenbus_dev_fatal(dev, ret, "fb_alloc_cmap");
goto error;
}
fb_info->fbdefio = &xenfb_defio;
fb_deferred_io_init(fb_info);
xenfb_init_shared_page(info, fb_info);
ret = xenfb_connect_backend(dev, info);
if (ret < 0)
goto error;
ret = register_framebuffer(fb_info);
if (ret) {
fb_deferred_io_cleanup(fb_info);
fb_dealloc_cmap(&fb_info->cmap);
framebuffer_release(fb_info);
xenbus_dev_fatal(dev, ret, "register_framebuffer");
goto error;
}
info->fb_info = fb_info;
xenfb_make_preferred_console();
return 0;
error_nomem:
ret = -ENOMEM;
xenbus_dev_fatal(dev, ret, "allocating device memory");
error:
xenfb_remove(dev);
return ret;
}
static __devinit void
xenfb_make_preferred_console(void)
{
struct console *c;
if (console_set_on_cmdline)
return;
console_lock();
for_each_console(c) {
if (!strcmp(c->name, "tty") && c->index == 0)
break;
}
console_unlock();
if (c) {
unregister_console(c);
c->flags |= CON_CONSDEV;
c->flags &= ~CON_PRINTBUFFER;
register_console(c);
}
}
static int xenfb_resume(struct xenbus_device *dev)
{
struct xenfb_info *info = dev_get_drvdata(&dev->dev);
xenfb_disconnect_backend(info);
xenfb_init_shared_page(info, info->fb_info);
return xenfb_connect_backend(dev, info);
}
static int xenfb_remove(struct xenbus_device *dev)
{
struct xenfb_info *info = dev_get_drvdata(&dev->dev);
xenfb_disconnect_backend(info);
if (info->fb_info) {
fb_deferred_io_cleanup(info->fb_info);
unregister_framebuffer(info->fb_info);
fb_dealloc_cmap(&info->fb_info->cmap);
framebuffer_release(info->fb_info);
}
free_page((unsigned long)info->page);
vfree(info->mfns);
vfree(info->fb);
kfree(info);
return 0;
}
static unsigned long vmalloc_to_mfn(void *address)
{
return pfn_to_mfn(vmalloc_to_pfn(address));
}
static void xenfb_init_shared_page(struct xenfb_info *info,
struct fb_info *fb_info)
{
int i;
int epd = PAGE_SIZE / sizeof(info->mfns[0]);
for (i = 0; i < info->nr_pages; i++)
info->mfns[i] = vmalloc_to_mfn(info->fb + i * PAGE_SIZE);
for (i = 0; i * epd < info->nr_pages; i++)
info->page->pd[i] = vmalloc_to_mfn(&info->mfns[i * epd]);
info->page->width = fb_info->var.xres;
info->page->height = fb_info->var.yres;
info->page->depth = fb_info->var.bits_per_pixel;
info->page->line_length = fb_info->fix.line_length;
info->page->mem_length = fb_info->fix.smem_len;
info->page->in_cons = info->page->in_prod = 0;
info->page->out_cons = info->page->out_prod = 0;
}
static int xenfb_connect_backend(struct xenbus_device *dev,
struct xenfb_info *info)
{
int ret, evtchn, irq;
struct xenbus_transaction xbt;
ret = xenbus_alloc_evtchn(dev, &evtchn);
if (ret)
return ret;
irq = bind_evtchn_to_irqhandler(evtchn, xenfb_event_handler,
0, dev->devicetype, info);
if (irq < 0) {
xenbus_free_evtchn(dev, evtchn);
xenbus_dev_fatal(dev, ret, "bind_evtchn_to_irqhandler");
return irq;
}
again:
ret = xenbus_transaction_start(&xbt);
if (ret) {
xenbus_dev_fatal(dev, ret, "starting transaction");
goto unbind_irq;
}
ret = xenbus_printf(xbt, dev->nodename, "page-ref", "%lu",
virt_to_mfn(info->page));
if (ret)
goto error_xenbus;
ret = xenbus_printf(xbt, dev->nodename, "event-channel", "%u",
evtchn);
if (ret)
goto error_xenbus;
ret = xenbus_printf(xbt, dev->nodename, "protocol", "%s",
XEN_IO_PROTO_ABI_NATIVE);
if (ret)
goto error_xenbus;
ret = xenbus_printf(xbt, dev->nodename, "feature-update", "1");
if (ret)
goto error_xenbus;
ret = xenbus_transaction_end(xbt, 0);
if (ret) {
if (ret == -EAGAIN)
goto again;
xenbus_dev_fatal(dev, ret, "completing transaction");
goto unbind_irq;
}
xenbus_switch_state(dev, XenbusStateInitialised);
info->irq = irq;
return 0;
error_xenbus:
xenbus_transaction_end(xbt, 1);
xenbus_dev_fatal(dev, ret, "writing xenstore");
unbind_irq:
unbind_from_irqhandler(irq, info);
return ret;
}
static void xenfb_disconnect_backend(struct xenfb_info *info)
{
info->update_wanted = 0;
if (info->irq >= 0)
unbind_from_irqhandler(info->irq, info);
info->irq = -1;
}
static void xenfb_backend_changed(struct xenbus_device *dev,
enum xenbus_state backend_state)
{
struct xenfb_info *info = dev_get_drvdata(&dev->dev);
int val;
switch (backend_state) {
case XenbusStateInitialising:
case XenbusStateInitialised:
case XenbusStateReconfiguring:
case XenbusStateReconfigured:
case XenbusStateUnknown:
case XenbusStateClosed:
break;
case XenbusStateInitWait:
InitWait:
xenbus_switch_state(dev, XenbusStateConnected);
break;
case XenbusStateConnected:
if (dev->state != XenbusStateConnected)
goto InitWait;
if (xenbus_scanf(XBT_NIL, info->xbdev->otherend,
"request-update", "%d", &val) < 0)
val = 0;
if (val)
info->update_wanted = 1;
if (xenbus_scanf(XBT_NIL, dev->otherend,
"feature-resize", "%d", &val) < 0)
val = 0;
info->feature_resize = val;
break;
case XenbusStateClosing:
xenbus_frontend_closed(dev);
break;
}
}
static int __init xenfb_init(void)
{
if (!xen_pv_domain())
return -ENODEV;
if (xen_initial_domain())
return -ENODEV;
return xenbus_register_frontend(&xenfb_driver);
}
static void __exit xenfb_cleanup(void)
{
xenbus_unregister_driver(&xenfb_driver);
}
