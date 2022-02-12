void maxinefb_ims332_write_register(int regno, register unsigned int val)
{
register unsigned char *regs = (char *) MAXINEFB_IMS332_ADDRESS;
unsigned char *wptr;
wptr = regs + 0xa0000 + (regno << 4);
*((volatile unsigned int *) (regs)) = (val >> 8) & 0xff00;
*((volatile unsigned short *) (wptr)) = val;
}
unsigned int maxinefb_ims332_read_register(int regno)
{
register unsigned char *regs = (char *) MAXINEFB_IMS332_ADDRESS;
unsigned char *rptr;
register unsigned int j, k;
rptr = regs + 0x80000 + (regno << 4);
j = *((volatile unsigned short *) rptr);
k = *((volatile unsigned short *) regs);
return (j & 0xffff) | ((k & 0xff00) << 8);
}
static int maxinefb_setcolreg(unsigned regno, unsigned red, unsigned green,
unsigned blue, unsigned transp, struct fb_info *info)
{
unsigned long hw_colorvalue = 0;
if (regno > 255)
return 1;
red >>= 8;
green >>= 8;
blue >>= 8;
hw_colorvalue = (blue << 16) + (green << 8) + (red);
maxinefb_ims332_write_register(IMS332_REG_COLOR_PALETTE + regno,
hw_colorvalue);
return 0;
}
int __init maxinefb_init(void)
{
unsigned long fboff;
unsigned long fb_start;
int i;
if (fb_get_options("maxinefb", NULL))
return -ENODEV;
if (mips_machtype != MACH_DS5000_XX) {
return -EINVAL;
}
printk(KERN_INFO "Maxinefb: Personal DECstation detected\n");
printk(KERN_INFO "Maxinefb: initializing onboard framebuffer\n");
fb_start = DS5000_xx_ONBOARD_FBMEM_START;
for (fboff = fb_start; fboff < fb_start + 0x1ffff; fboff++)
*(volatile unsigned char *)fboff = 0x0;
maxinefb_fix.smem_start = fb_start;
for (i = 0; i < 512; i++) {
maxinefb_ims332_write_register(IMS332_REG_CURSOR_RAM + i,
0);
}
fb_info.fbops = &maxinefb_ops;
fb_info.screen_base = (char *)maxinefb_fix.smem_start;
fb_info.var = maxinefb_defined;
fb_info.fix = maxinefb_fix;
fb_info.flags = FBINFO_DEFAULT;
fb_alloc_cmap(&fb_info.cmap, 256, 0);
if (register_framebuffer(&fb_info) < 0)
return 1;
return 0;
}
static void __exit maxinefb_exit(void)
{
unregister_framebuffer(&fb_info);
}
