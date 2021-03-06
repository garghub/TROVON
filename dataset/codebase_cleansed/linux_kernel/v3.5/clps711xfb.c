static int
clps7111fb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
unsigned int level, mask, shift, pal;
if (regno >= (1 << info->var.bits_per_pixel))
return 1;
level = (red * 77 + green * 151 + blue * 28) >> 20;
if (machine_is_edb7211()) {
level = 15 - level;
}
shift = 4 * (regno & 7);
level <<= shift;
mask = 15 << shift;
level &= mask;
regno = regno < 8 ? PALLSW : PALMSW;
pal = clps_readl(regno);
pal = (pal & ~mask) | level;
clps_writel(pal, regno);
return 0;
}
static int
clps7111fb_check_var(struct fb_var_screeninfo *var, struct fb_info *info)
{
var->transp.msb_right = 0;
var->transp.offset = 0;
var->transp.length = 0;
var->red.msb_right = 0;
var->red.offset = 0;
var->red.length = var->bits_per_pixel;
var->green = var->red;
var->blue = var->red;
if (var->bits_per_pixel > 4)
return -EINVAL;
return 0;
}
static int
clps7111fb_set_par(struct fb_info *info)
{
unsigned int lcdcon, syscon, pixclock;
switch (info->var.bits_per_pixel) {
case 1:
info->fix.visual = FB_VISUAL_MONO01;
break;
case 2:
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
break;
case 4:
info->fix.visual = FB_VISUAL_PSEUDOCOLOR;
break;
}
info->fix.line_length = info->var.xres_virtual * info->var.bits_per_pixel / 8;
lcdcon = (info->var.xres_virtual * info->var.yres_virtual * info->var.bits_per_pixel) / 128 - 1;
lcdcon |= ((info->var.xres_virtual / 16) - 1) << 13;
lcdcon |= lcd_ac_prescale << 25;
pixclock = 9 * info->var.pixclock / 244140 - 1;
lcdcon |= pixclock << 19;
if (info->var.bits_per_pixel == 4)
lcdcon |= LCDCON_GSMD;
if (info->var.bits_per_pixel >= 2)
lcdcon |= LCDCON_GSEN;
syscon = clps_readl(SYSCON1);
clps_writel(syscon & ~SYSCON1_LCDEN, SYSCON1);
clps_writel(lcdcon, LCDCON);
clps_writel(syscon | SYSCON1_LCDEN, SYSCON1);
return 0;
}
static int clps7111fb_blank(int blank, struct fb_info *info)
{
if (blank) {
if (machine_is_edb7211()) {
clps_writeb(clps_readb(PDDR) & ~EDB_PD3_LCDBL, PDDR);
clps_writeb(clps_readb(PDDR) & ~EDB_PD1_LCD_DC_DC_EN, PDDR);
udelay(100);
clps_writeb(clps_readb(PDDR) & ~EDB_PD2_LCDEN, PDDR);
clps_writel(clps_readl(SYSCON1) & ~SYSCON1_LCDEN,
SYSCON1);
}
} else {
if (machine_is_edb7211()) {
clps_writel(clps_readl(SYSCON1) | SYSCON1_LCDEN,
SYSCON1);
clps_writeb(clps_readb(PDDR) | EDB_PD2_LCDEN, PDDR);
udelay(100);
clps_writeb(clps_readb(PDDR) | EDB_PD1_LCD_DC_DC_EN,
PDDR);
clps_writeb(clps_readb(PDDR) | EDB_PD3_LCDBL, PDDR);
}
}
return 0;
}
static int backlight_proc_show(struct seq_file *m, void *v)
{
if (machine_is_edb7211()) {
seq_printf(m, "%d\n",
(clps_readb(PDDR) & EDB_PD3_LCDBL) ? 1 : 0);
}
return 0;
}
static int backlight_proc_open(struct inode *inode, struct file *file)
{
return single_open(file, backlight_proc_show, NULL);
}
static ssize_t backlight_proc_write(struct file *file, const char *buffer,
size_t count, loff_t *pos)
{
unsigned char char_value;
int value;
if (count < 1) {
return -EINVAL;
}
if (copy_from_user(&char_value, buffer, 1))
return -EFAULT;
value = char_value - '0';
if (machine_is_edb7211()) {
unsigned char port_d;
port_d = clps_readb(PDDR);
if (value) {
port_d |= EDB_PD3_LCDBL;
} else {
port_d &= ~EDB_PD3_LCDBL;
}
clps_writeb(port_d, PDDR);
}
return count;
}
static void __init clps711x_guess_lcd_params(struct fb_info *info)
{
unsigned int lcdcon, syscon, size;
unsigned long phys_base = PAGE_OFFSET;
void *virt_base = (void *)PAGE_OFFSET;
info->var.xres_virtual = 640;
info->var.yres_virtual = 240;
info->var.bits_per_pixel = 4;
info->var.activate = FB_ACTIVATE_NOW;
info->var.height = -1;
info->var.width = -1;
info->var.pixclock = 93006;
syscon = clps_readl(SYSCON1);
if (syscon & SYSCON1_LCDEN) {
lcdcon = clps_readl(LCDCON);
switch (lcdcon & (LCDCON_GSMD | LCDCON_GSEN)) {
case LCDCON_GSMD | LCDCON_GSEN:
info->var.bits_per_pixel = 4;
break;
case LCDCON_GSEN:
info->var.bits_per_pixel = 2;
break;
default:
info->var.bits_per_pixel = 1;
break;
}
info->var.xres_virtual = (((lcdcon >> 13) & 0x3f) + 1) * 16;
info->var.yres_virtual = (((lcdcon & 0x1fff) + 1) * 128) /
(info->var.xres_virtual *
info->var.bits_per_pixel);
info->var.pixclock = (((lcdcon >> 19) & 0x3f) + 1) * 244140 / 9;
lcd_ac_prescale = (lcdcon >> 25) & 0x1f;
}
info->var.xres = info->var.xres_virtual;
info->var.yres = info->var.yres_virtual;
info->var.grayscale = info->var.bits_per_pixel > 1;
size = info->var.xres * info->var.yres * info->var.bits_per_pixel / 8;
if (size <= 38400) {
printk(KERN_INFO "CLPS711xFB: could use on-board SRAM?\n");
}
if ((syscon & SYSCON1_LCDEN) == 0) {
memset(virt_base, 0, size);
}
info->screen_base = virt_base;
info->fix.smem_start = phys_base;
info->fix.smem_len = PAGE_ALIGN(size);
info->fix.type = FB_TYPE_PACKED_PIXELS;
}
int __init clps711xfb_init(void)
{
int err = -ENOMEM;
if (fb_get_options("clps711xfb", NULL))
return -ENODEV;
cfb = kzalloc(sizeof(*cfb), GFP_KERNEL);
if (!cfb)
goto out;
strcpy(cfb->fix.id, "clps711x");
cfb->fbops = &clps7111fb_ops;
cfb->flags = FBINFO_DEFAULT;
clps711x_guess_lcd_params(cfb);
fb_alloc_cmap(&cfb->cmap, CMAP_MAX_SIZE, 0);
if (!proc_create("backlight", 0444, NULL, &backlight_proc_fops)) {
printk("Couldn't create the /proc entry for the backlight.\n");
return -EINVAL;
}
if (machine_is_p720t()) {
PLD_LCDEN = PLD_LCDEN_EN;
PLD_PWR |= (PLD_S4_ON|PLD_S3_ON|PLD_S2_ON|PLD_S1_ON);
}
if (machine_is_edb7211()) {
clps_writeb(clps_readb(PDDR) | EDB_PD2_LCDEN, PDDR);
udelay(100);
clps_writeb(clps_readb(PDDR) | EDB_PD1_LCD_DC_DC_EN, PDDR);
clps_writeb(clps_readb(PDDR) | EDB_PD3_LCDBL, PDDR);
}
err = register_framebuffer(cfb);
out: return err;
}
static void __exit clps711xfb_exit(void)
{
unregister_framebuffer(cfb);
kfree(cfb);
if (machine_is_p720t()) {
PLD_LCDEN = 0;
PLD_PWR &= ~(PLD_S4_ON|PLD_S3_ON|PLD_S2_ON|PLD_S1_ON);
}
}
