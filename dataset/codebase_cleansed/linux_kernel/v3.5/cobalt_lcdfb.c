static inline void lcd_write_control(struct fb_info *info, u8 control)
{
writel((u32)control << 24, info->screen_base);
}
static inline u8 lcd_read_control(struct fb_info *info)
{
return readl(info->screen_base) >> 24;
}
static inline void lcd_write_data(struct fb_info *info, u8 data)
{
writel((u32)data << 24, info->screen_base + LCD_DATA_REG_OFFSET);
}
static inline u8 lcd_read_data(struct fb_info *info)
{
return readl(info->screen_base + LCD_DATA_REG_OFFSET) >> 24;
}
static inline void cpld_wait(struct fb_info *info)
{
do {
} while (readl(info->screen_base + CPLD_STATUS) & 1);
}
static inline void lcd_write_control(struct fb_info *info, u8 control)
{
cpld_wait(info);
writel(control, info->screen_base + LCD_CTL);
}
static inline u8 lcd_read_control(struct fb_info *info)
{
cpld_wait(info);
readl(info->screen_base + LCD_CTL);
cpld_wait(info);
return readl(info->screen_base + CPLD_DATA) & 0xff;
}
static inline void lcd_write_data(struct fb_info *info, u8 data)
{
cpld_wait(info);
writel(data, info->screen_base + LCD_DATA);
}
static inline u8 lcd_read_data(struct fb_info *info)
{
cpld_wait(info);
readl(info->screen_base + LCD_DATA);
cpld_wait(info);
return readl(info->screen_base + CPLD_DATA) & 0xff;
}
static int lcd_busy_wait(struct fb_info *info)
{
u8 val = 0;
int timeout = 10, retval = 0;
do {
val = lcd_read_control(info);
val &= LCD_BUSY;
if (val != LCD_BUSY)
break;
if (msleep_interruptible(1))
return -EINTR;
timeout--;
} while (timeout);
if (val == LCD_BUSY)
retval = -EBUSY;
return retval;
}
static void lcd_clear(struct fb_info *info)
{
int i;
for (i = 0; i < 4; i++) {
udelay(150);
lcd_write_control(info, LCD_PRERESET);
}
udelay(150);
lcd_write_control(info, LCD_CLEAR);
udelay(150);
lcd_write_control(info, LCD_RESET);
}
static ssize_t cobalt_lcdfb_read(struct fb_info *info, char __user *buf,
size_t count, loff_t *ppos)
{
char src[LCD_CHARS_MAX];
unsigned long pos;
int len, retval = 0;
pos = *ppos;
if (pos >= LCD_CHARS_MAX || count == 0)
return 0;
if (count > LCD_CHARS_MAX)
count = LCD_CHARS_MAX;
if (pos + count > LCD_CHARS_MAX)
count = LCD_CHARS_MAX - pos;
for (len = 0; len < count; len++) {
retval = lcd_busy_wait(info);
if (retval < 0)
break;
lcd_write_control(info, LCD_TEXT_POS(pos));
retval = lcd_busy_wait(info);
if (retval < 0)
break;
src[len] = lcd_read_data(info);
if (pos == 0x0f)
pos = 0x40;
else
pos++;
}
if (retval < 0 && signal_pending(current))
return -ERESTARTSYS;
if (copy_to_user(buf, src, len))
return -EFAULT;
*ppos += len;
return len;
}
static ssize_t cobalt_lcdfb_write(struct fb_info *info, const char __user *buf,
size_t count, loff_t *ppos)
{
char dst[LCD_CHARS_MAX];
unsigned long pos;
int len, retval = 0;
pos = *ppos;
if (pos >= LCD_CHARS_MAX || count == 0)
return 0;
if (count > LCD_CHARS_MAX)
count = LCD_CHARS_MAX;
if (pos + count > LCD_CHARS_MAX)
count = LCD_CHARS_MAX - pos;
if (copy_from_user(dst, buf, count))
return -EFAULT;
for (len = 0; len < count; len++) {
retval = lcd_busy_wait(info);
if (retval < 0)
break;
lcd_write_control(info, LCD_TEXT_POS(pos));
retval = lcd_busy_wait(info);
if (retval < 0)
break;
lcd_write_data(info, dst[len]);
if (pos == 0x0f)
pos = 0x40;
else
pos++;
}
if (retval < 0 && signal_pending(current))
return -ERESTARTSYS;
*ppos += len;
return len;
}
static int cobalt_lcdfb_blank(int blank_mode, struct fb_info *info)
{
int retval;
retval = lcd_busy_wait(info);
if (retval < 0)
return retval;
switch (blank_mode) {
case FB_BLANK_UNBLANK:
lcd_write_control(info, LCD_ON);
break;
default:
lcd_write_control(info, LCD_OFF);
break;
}
return 0;
}
static int cobalt_lcdfb_cursor(struct fb_info *info, struct fb_cursor *cursor)
{
u32 x, y;
int retval;
switch (cursor->set) {
case FB_CUR_SETPOS:
x = cursor->image.dx;
y = cursor->image.dy;
if (x >= LCD_XRES_MAX || y >= LCD_YRES_MAX)
return -EINVAL;
retval = lcd_busy_wait(info);
if (retval < 0)
return retval;
lcd_write_control(info,
LCD_TEXT_POS(info->fix.line_length * y + x));
break;
default:
return -EINVAL;
}
retval = lcd_busy_wait(info);
if (retval < 0)
return retval;
if (cursor->enable)
lcd_write_control(info, LCD_CURSOR_ON);
else
lcd_write_control(info, LCD_CURSOR_OFF);
return 0;
}
static int __devinit cobalt_lcdfb_probe(struct platform_device *dev)
{
struct fb_info *info;
struct resource *res;
int retval;
info = framebuffer_alloc(0, &dev->dev);
if (!info)
return -ENOMEM;
res = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!res) {
framebuffer_release(info);
return -EBUSY;
}
info->screen_size = resource_size(res);
info->screen_base = ioremap(res->start, info->screen_size);
info->fbops = &cobalt_lcd_fbops;
info->fix = cobalt_lcdfb_fix;
info->fix.smem_start = res->start;
info->fix.smem_len = info->screen_size;
info->pseudo_palette = NULL;
info->par = NULL;
info->flags = FBINFO_DEFAULT;
retval = register_framebuffer(info);
if (retval < 0) {
iounmap(info->screen_base);
framebuffer_release(info);
return retval;
}
platform_set_drvdata(dev, info);
lcd_clear(info);
printk(KERN_INFO "fb%d: Cobalt server LCD frame buffer device\n",
info->node);
return 0;
}
static int __devexit cobalt_lcdfb_remove(struct platform_device *dev)
{
struct fb_info *info;
info = platform_get_drvdata(dev);
if (info) {
iounmap(info->screen_base);
unregister_framebuffer(info);
framebuffer_release(info);
}
return 0;
}
static int __init cobalt_lcdfb_init(void)
{
return platform_driver_register(&cobalt_lcdfb_driver);
}
static void __exit cobalt_lcdfb_exit(void)
{
platform_driver_unregister(&cobalt_lcdfb_driver);
}
