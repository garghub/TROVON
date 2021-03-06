static void apollo_send_data(struct hecubafb_par *par, unsigned char data)
{
par->board->set_data(par, data);
par->board->set_ctl(par, HCB_DS_BIT, 0);
par->board->wait_for_ack(par, 0);
par->board->set_ctl(par, HCB_DS_BIT, 1);
par->board->wait_for_ack(par, 1);
}
static void apollo_send_command(struct hecubafb_par *par, unsigned char data)
{
par->board->set_ctl(par, HCB_CD_BIT, 1);
apollo_send_data(par, data);
par->board->set_ctl(par, HCB_CD_BIT, 0);
}
static void hecubafb_dpy_update(struct hecubafb_par *par)
{
int i;
unsigned char *buf = (unsigned char __force *)par->info->screen_base;
apollo_send_command(par, APOLLO_START_NEW_IMG);
for (i=0; i < (DPY_W*DPY_H/8); i++) {
apollo_send_data(par, *(buf++));
}
apollo_send_command(par, APOLLO_STOP_IMG_DATA);
apollo_send_command(par, APOLLO_DISPLAY_IMG);
}
static void hecubafb_dpy_deferred_io(struct fb_info *info,
struct list_head *pagelist)
{
hecubafb_dpy_update(info->par);
}
static void hecubafb_fillrect(struct fb_info *info,
const struct fb_fillrect *rect)
{
struct hecubafb_par *par = info->par;
sys_fillrect(info, rect);
hecubafb_dpy_update(par);
}
static void hecubafb_copyarea(struct fb_info *info,
const struct fb_copyarea *area)
{
struct hecubafb_par *par = info->par;
sys_copyarea(info, area);
hecubafb_dpy_update(par);
}
static void hecubafb_imageblit(struct fb_info *info,
const struct fb_image *image)
{
struct hecubafb_par *par = info->par;
sys_imageblit(info, image);
hecubafb_dpy_update(par);
}
static ssize_t hecubafb_write(struct fb_info *info, const char __user *buf,
size_t count, loff_t *ppos)
{
struct hecubafb_par *par = info->par;
unsigned long p = *ppos;
void *dst;
int err = 0;
unsigned long total_size;
if (info->state != FBINFO_STATE_RUNNING)
return -EPERM;
total_size = info->fix.smem_len;
if (p > total_size)
return -EFBIG;
if (count > total_size) {
err = -EFBIG;
count = total_size;
}
if (count + p > total_size) {
if (!err)
err = -ENOSPC;
count = total_size - p;
}
dst = (void __force *) (info->screen_base + p);
if (copy_from_user(dst, buf, count))
err = -EFAULT;
if (!err)
*ppos += count;
hecubafb_dpy_update(par);
return (err) ? err : count;
}
static int hecubafb_probe(struct platform_device *dev)
{
struct fb_info *info;
struct hecuba_board *board;
int retval = -ENOMEM;
int videomemorysize;
unsigned char *videomemory;
struct hecubafb_par *par;
board = dev->dev.platform_data;
if (!board)
return -EINVAL;
if (!try_module_get(board->owner))
return -ENODEV;
videomemorysize = (DPY_W*DPY_H)/8;
videomemory = vzalloc(videomemorysize);
if (!videomemory)
goto err_videomem_alloc;
info = framebuffer_alloc(sizeof(struct hecubafb_par), &dev->dev);
if (!info)
goto err_fballoc;
info->screen_base = (char __force __iomem *)videomemory;
info->fbops = &hecubafb_ops;
info->var = hecubafb_var;
info->fix = hecubafb_fix;
info->fix.smem_len = videomemorysize;
par = info->par;
par->info = info;
par->board = board;
par->send_command = apollo_send_command;
par->send_data = apollo_send_data;
info->flags = FBINFO_FLAG_DEFAULT | FBINFO_VIRTFB;
info->fbdefio = &hecubafb_defio;
fb_deferred_io_init(info);
retval = register_framebuffer(info);
if (retval < 0)
goto err_fbreg;
platform_set_drvdata(dev, info);
fb_info(info, "Hecuba frame buffer device, using %dK of video memory\n",
videomemorysize >> 10);
retval = par->board->init(par);
if (retval < 0)
goto err_fbreg;
return 0;
err_fbreg:
framebuffer_release(info);
err_fballoc:
vfree(videomemory);
err_videomem_alloc:
module_put(board->owner);
return retval;
}
static int hecubafb_remove(struct platform_device *dev)
{
struct fb_info *info = platform_get_drvdata(dev);
if (info) {
struct hecubafb_par *par = info->par;
fb_deferred_io_cleanup(info);
unregister_framebuffer(info);
vfree((void __force *)info->screen_base);
if (par->board->remove)
par->board->remove(par);
module_put(par->board->owner);
framebuffer_release(info);
}
return 0;
}
