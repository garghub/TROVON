static int fm2fb_blank(int blank, struct fb_info *info)
{
unsigned char t = FRAMEMASTER_ROM;
if (!blank)
t |= FRAMEMASTER_ENABLE | FRAMEMASTER_NOLACE;
fm2fb_reg[0] = t;
return 0;
}
static int fm2fb_setcolreg(u_int regno, u_int red, u_int green, u_int blue,
u_int transp, struct fb_info *info)
{
if (regno < 16) {
red >>= 8;
green >>= 8;
blue >>= 8;
((u32*)(info->pseudo_palette))[regno] = (red << 16) |
(green << 8) | blue;
}
return 0;
}
static int fm2fb_probe(struct zorro_dev *z, const struct zorro_device_id *id)
{
struct fb_info *info;
unsigned long *ptr;
int is_fm;
int x, y;
is_fm = z->id == ZORRO_PROD_BSC_FRAMEMASTER_II;
if (!zorro_request_device(z,"fm2fb"))
return -ENXIO;
info = framebuffer_alloc(16 * sizeof(u32), &z->dev);
if (!info) {
zorro_release_device(z);
return -ENOMEM;
}
if (fb_alloc_cmap(&info->cmap, 256, 0) < 0) {
framebuffer_release(info);
zorro_release_device(z);
return -ENOMEM;
}
fb_fix.smem_start = zorro_resource_start(z);
info->screen_base = ioremap(fb_fix.smem_start, FRAMEMASTER_SIZE);
fb_fix.mmio_start = fb_fix.smem_start + FRAMEMASTER_REG;
fm2fb_reg = (unsigned char *)(info->screen_base+FRAMEMASTER_REG);
strcpy(fb_fix.id, is_fm ? "FrameMaster II" : "Rainbow II");
ptr = (unsigned long *)fb_fix.smem_start;
for (y = 0; y < 576; y++) {
for (x = 0; x < 96; x++) *ptr++ = 0xffffff;
for (x = 0; x < 96; x++) *ptr++ = 0xffff00;
for (x = 0; x < 96; x++) *ptr++ = 0x00ffff;
for (x = 0; x < 96; x++) *ptr++ = 0x00ff00;
for (x = 0; x < 96; x++) *ptr++ = 0xff00ff;
for (x = 0; x < 96; x++) *ptr++ = 0xff0000;
for (x = 0; x < 96; x++) *ptr++ = 0x0000ff;
for (x = 0; x < 96; x++) *ptr++ = 0x000000;
}
fm2fb_blank(0, info);
if (fm2fb_mode == -1)
fm2fb_mode = FM2FB_MODE_PAL;
info->fbops = &fm2fb_ops;
info->var = fb_var_modes[fm2fb_mode];
info->pseudo_palette = info->par;
info->par = NULL;
info->fix = fb_fix;
info->flags = FBINFO_DEFAULT;
if (register_framebuffer(info) < 0) {
fb_dealloc_cmap(&info->cmap);
iounmap(info->screen_base);
framebuffer_release(info);
zorro_release_device(z);
return -EINVAL;
}
fb_info(info, "%s frame buffer device\n", fb_fix.id);
return 0;
}
int __init fm2fb_setup(char *options)
{
char *this_opt;
if (!options || !*options)
return 0;
while ((this_opt = strsep(&options, ",")) != NULL) {
if (!strncmp(this_opt, "pal", 3))
fm2fb_mode = FM2FB_MODE_PAL;
else if (!strncmp(this_opt, "ntsc", 4))
fm2fb_mode = FM2FB_MODE_NTSC;
}
return 0;
}
int __init fm2fb_init(void)
{
char *option = NULL;
if (fb_get_options("fm2fb", &option))
return -ENODEV;
fm2fb_setup(option);
return zorro_register_driver(&fm2fb_driver);
}
