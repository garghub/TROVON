static void ks108_writeb_ctl(struct arcfb_par *par,
unsigned int chipindex, unsigned char value)
{
unsigned char chipselval = par->cslut[chipindex];
outb(chipselval|KS_CEHI|KS_SEL_CMD, par->cio_addr);
outb(value, par->dio_addr);
udelay(tuhold);
outb(chipselval|KS_CELO|KS_SEL_CMD, par->cio_addr);
}
static void ks108_writeb_mainctl(struct arcfb_par *par, unsigned char value)
{
outb(value, par->cio_addr);
udelay(tuhold);
}
static unsigned char ks108_readb_ctl2(struct arcfb_par *par)
{
return inb(par->c2io_addr);
}
static void ks108_writeb_data(struct arcfb_par *par,
unsigned int chipindex, unsigned char value)
{
unsigned char chipselval = par->cslut[chipindex];
outb(chipselval|KS_CEHI|KS_SEL_DATA, par->cio_addr);
outb(value, par->dio_addr);
udelay(tuhold);
outb(chipselval|KS_CELO|KS_SEL_DATA, par->cio_addr);
}
static void ks108_set_start_line(struct arcfb_par *par,
unsigned int chipindex, unsigned char y)
{
ks108_writeb_ctl(par, chipindex, KS_SET_DPY_START_LINE|y);
}
static void ks108_set_yaddr(struct arcfb_par *par,
unsigned int chipindex, unsigned char y)
{
ks108_writeb_ctl(par, chipindex, KS_SET_PAGE_NUM|y);
}
static void ks108_set_xaddr(struct arcfb_par *par,
unsigned int chipindex, unsigned char x)
{
ks108_writeb_ctl(par, chipindex, KS_SET_X|x);
}
static void ks108_clear_lcd(struct arcfb_par *par, unsigned int chipindex)
{
int i,j;
for (i = 0; i <= 8; i++) {
ks108_set_yaddr(par, chipindex, i);
ks108_set_xaddr(par, chipindex, 0);
for (j = 0; j < 64; j++) {
ks108_writeb_data(par, chipindex,
(unsigned char) splashval);
}
}
}
static int arcfb_open(struct fb_info *info, int user)
{
struct arcfb_par *par = info->par;
atomic_inc(&par->ref_count);
return 0;
}
static int arcfb_release(struct fb_info *info, int user)
{
struct arcfb_par *par = info->par;
int count = atomic_read(&par->ref_count);
if (!count)
return -EINVAL;
atomic_dec(&par->ref_count);
return 0;
}
static int arcfb_pan_display(struct fb_var_screeninfo *var,
struct fb_info *info)
{
int i;
struct arcfb_par *par = info->par;
if ((var->vmode & FB_VMODE_YWRAP) && (var->yoffset < 64)
&& (info->var.yres <= 64)) {
for (i = 0; i < num_cols; i++) {
ks108_set_start_line(par, i, var->yoffset);
}
info->var.yoffset = var->yoffset;
return 0;
}
return -EINVAL;
}
static irqreturn_t arcfb_interrupt(int vec, void *dev_instance)
{
struct fb_info *info = dev_instance;
unsigned char ctl2status;
struct arcfb_par *par = info->par;
ctl2status = ks108_readb_ctl2(par);
if (!(ctl2status & KS_INTACK))
return IRQ_NONE;
ks108_writeb_mainctl(par, KS_CLRINT);
spin_lock(&par->lock);
if (waitqueue_active(&arcfb_waitq)) {
wake_up(&arcfb_waitq);
}
spin_unlock(&par->lock);
return IRQ_HANDLED;
}
static void arcfb_lcd_update_page(struct arcfb_par *par, unsigned int upper,
unsigned int left, unsigned int right, unsigned int distance)
{
unsigned char *src;
unsigned int xindex, yindex, chipindex, linesize;
int i;
unsigned char val;
unsigned char bitmask, rightshift;
xindex = left >> 6;
yindex = upper >> 6;
chipindex = (xindex + (yindex*num_cols));
ks108_set_yaddr(par, chipindex, upper/8);
linesize = par->info->var.xres/8;
src = (unsigned char __force *) par->info->screen_base + (left/8) +
(upper * linesize);
ks108_set_xaddr(par, chipindex, left);
bitmask=1;
rightshift=0;
while (left <= right) {
val = 0;
for (i = 0; i < 8; i++) {
if ( i > rightshift) {
val |= (*(src + (i*linesize)) & bitmask)
<< (i - rightshift);
} else {
val |= (*(src + (i*linesize)) & bitmask)
>> (rightshift - i);
}
}
ks108_writeb_data(par, chipindex, val);
left++;
if (bitmask == 0x80) {
bitmask = 1;
src++;
rightshift=0;
} else {
bitmask <<= 1;
rightshift++;
}
}
}
static void arcfb_lcd_update_vert(struct arcfb_par *par, unsigned int top,
unsigned int bottom, unsigned int left, unsigned int right)
{
unsigned int distance, upper, lower;
distance = (bottom - top) + 1;
upper = top;
lower = top + 7;
while (distance > 0) {
distance -= 8;
arcfb_lcd_update_page(par, upper, left, right, 8);
upper = lower + 1;
lower = upper + 7;
}
}
static void arcfb_lcd_update_horiz(struct arcfb_par *par, unsigned int left,
unsigned int right, unsigned int top, unsigned int h)
{
unsigned int distance, upper, lower;
distance = h;
upper = floor8(top);
lower = min(upper + distance - 1, ceil64(upper));
while (distance > 0) {
distance -= ((lower - upper) + 1 );
arcfb_lcd_update_vert(par, upper, lower, left, right);
upper = lower + 1;
lower = min(upper + distance - 1, ceil64(upper));
}
}
static void arcfb_lcd_update(struct arcfb_par *par, unsigned int dx,
unsigned int dy, unsigned int w, unsigned int h)
{
unsigned int left, right, distance, y;
y = floor8(dy);
h += dy - y;
h = iceil8(h);
distance = w;
left = dx;
right = min(left + w - 1, ceil64(left));
while (distance > 0) {
arcfb_lcd_update_horiz(par, left, right, y, h);
distance -= ((right - left) + 1);
left = right + 1;
right = min(left + distance - 1, ceil64(left));
}
}
static void arcfb_fillrect(struct fb_info *info,
const struct fb_fillrect *rect)
{
struct arcfb_par *par = info->par;
sys_fillrect(info, rect);
arcfb_lcd_update(par, rect->dx, rect->dy, rect->width, rect->height);
}
static void arcfb_copyarea(struct fb_info *info,
const struct fb_copyarea *area)
{
struct arcfb_par *par = info->par;
sys_copyarea(info, area);
arcfb_lcd_update(par, area->dx, area->dy, area->width, area->height);
}
static void arcfb_imageblit(struct fb_info *info, const struct fb_image *image)
{
struct arcfb_par *par = info->par;
sys_imageblit(info, image);
arcfb_lcd_update(par, image->dx, image->dy, image->width,
image->height);
}
static int arcfb_ioctl(struct fb_info *info,
unsigned int cmd, unsigned long arg)
{
void __user *argp = (void __user *)arg;
struct arcfb_par *par = info->par;
unsigned long flags;
switch (cmd) {
case FBIO_WAITEVENT:
{
DEFINE_WAIT(wait);
if (!par->irq)
return -EINVAL;
spin_lock_irqsave(&par->lock, flags);
prepare_to_wait(&arcfb_waitq, &wait,
TASK_INTERRUPTIBLE);
spin_unlock_irqrestore(&par->lock, flags);
schedule();
finish_wait(&arcfb_waitq, &wait);
}
case FBIO_GETCONTROL2:
{
unsigned char ctl2;
ctl2 = ks108_readb_ctl2(info->par);
if (copy_to_user(argp, &ctl2, sizeof(ctl2)))
return -EFAULT;
return 0;
}
default:
return -EINVAL;
}
}
static ssize_t arcfb_write(struct fb_info *info, const char __user *buf,
size_t count, loff_t *ppos)
{
unsigned long p;
int err=-EINVAL;
unsigned int fbmemlength,x,y,w,h, bitppos, startpos, endpos, bitcount;
struct arcfb_par *par;
unsigned int xres;
p = *ppos;
par = info->par;
xres = info->var.xres;
fbmemlength = (xres * info->var.yres)/8;
if (p > fbmemlength)
return -ENOSPC;
err = 0;
if ((count + p) > fbmemlength) {
count = fbmemlength - p;
err = -ENOSPC;
}
if (count) {
char *base_addr;
base_addr = (char __force *)info->screen_base;
count -= copy_from_user(base_addr + p, buf, count);
*ppos += count;
err = -EFAULT;
}
bitppos = p*8;
startpos = floorXres(bitppos, xres);
endpos = ceilXres((bitppos + (count*8)), xres);
bitcount = endpos - startpos;
x = startpos % xres;
y = startpos / xres;
w = xres;
h = bitcount / xres;
arcfb_lcd_update(par, x, y, w, h);
if (count)
return count;
return err;
}
static int __devinit arcfb_probe(struct platform_device *dev)
{
struct fb_info *info;
int retval = -ENOMEM;
int videomemorysize;
unsigned char *videomemory;
struct arcfb_par *par;
int i;
videomemorysize = (((64*64)*num_cols)*num_rows)/8;
videomemory = vzalloc(videomemorysize);
if (!videomemory)
return retval;
info = framebuffer_alloc(sizeof(struct arcfb_par), &dev->dev);
if (!info)
goto err;
info->screen_base = (char __iomem *)videomemory;
info->fbops = &arcfb_ops;
info->var = arcfb_var;
info->fix = arcfb_fix;
par = info->par;
par->info = info;
if (!dio_addr || !cio_addr || !c2io_addr) {
printk(KERN_WARNING "no IO addresses supplied\n");
goto err1;
}
par->dio_addr = dio_addr;
par->cio_addr = cio_addr;
par->c2io_addr = c2io_addr;
par->cslut[0] = 0x00;
par->cslut[1] = 0x06;
info->flags = FBINFO_FLAG_DEFAULT;
spin_lock_init(&par->lock);
retval = register_framebuffer(info);
if (retval < 0)
goto err1;
platform_set_drvdata(dev, info);
if (irq) {
par->irq = irq;
if (request_irq(par->irq, &arcfb_interrupt, IRQF_SHARED,
"arcfb", info)) {
printk(KERN_INFO
"arcfb: Failed req IRQ %d\n", par->irq);
retval = -EBUSY;
goto err1;
}
}
printk(KERN_INFO
"fb%d: Arc frame buffer device, using %dK of video memory\n",
info->node, videomemorysize >> 10);
for (i = 0; i < num_cols * num_rows; i++) {
ks108_writeb_ctl(par, i, KS_DPY_OFF);
ks108_set_start_line(par, i, 0);
ks108_set_yaddr(par, i, 0);
ks108_set_xaddr(par, i, 0);
ks108_writeb_ctl(par, i, KS_DPY_ON);
}
if (!nosplash) {
for (i = 0; i < num_cols * num_rows; i++) {
printk(KERN_INFO "fb%d: splashing lcd %d\n",
info->node, i);
ks108_set_start_line(par, i, 0);
ks108_clear_lcd(par, i);
}
}
return 0;
err1:
framebuffer_release(info);
err:
vfree(videomemory);
return retval;
}
static int __devexit arcfb_remove(struct platform_device *dev)
{
struct fb_info *info = platform_get_drvdata(dev);
if (info) {
unregister_framebuffer(info);
vfree((void __force *)info->screen_base);
framebuffer_release(info);
}
return 0;
}
static int __init arcfb_init(void)
{
int ret;
if (!arcfb_enable)
return -ENXIO;
ret = platform_driver_register(&arcfb_driver);
if (!ret) {
arcfb_device = platform_device_alloc("arcfb", 0);
if (arcfb_device) {
ret = platform_device_add(arcfb_device);
} else {
ret = -ENOMEM;
}
if (ret) {
platform_device_put(arcfb_device);
platform_driver_unregister(&arcfb_driver);
}
}
return ret;
}
static void __exit arcfb_exit(void)
{
platform_device_unregister(arcfb_device);
platform_driver_unregister(&arcfb_driver);
}
