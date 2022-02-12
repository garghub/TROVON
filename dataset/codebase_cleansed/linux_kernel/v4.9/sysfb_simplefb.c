__init bool parse_mode(const struct screen_info *si,
struct simplefb_platform_data *mode)
{
const struct simplefb_format *f;
__u8 type;
unsigned int i;
type = si->orig_video_isVGA;
if (type != VIDEO_TYPE_VLFB && type != VIDEO_TYPE_EFI)
return false;
for (i = 0; i < ARRAY_SIZE(formats); ++i) {
f = &formats[i];
if (si->lfb_depth == f->bits_per_pixel &&
si->red_size == f->red.length &&
si->red_pos == f->red.offset &&
si->green_size == f->green.length &&
si->green_pos == f->green.offset &&
si->blue_size == f->blue.length &&
si->blue_pos == f->blue.offset &&
si->rsvd_size == f->transp.length &&
si->rsvd_pos == f->transp.offset) {
mode->format = f->name;
mode->width = si->lfb_width;
mode->height = si->lfb_height;
mode->stride = si->lfb_linelength;
return true;
}
}
return false;
}
__init int create_simplefb(const struct screen_info *si,
const struct simplefb_platform_data *mode)
{
struct platform_device *pd;
struct resource res;
u64 base, size;
u32 length;
base = si->lfb_base;
if (si->capabilities & VIDEO_CAPABILITY_64BIT_BASE)
base |= (u64)si->ext_lfb_base << 32;
if (!base || (u64)(resource_size_t)base != base) {
printk(KERN_DEBUG "sysfb: inaccessible VRAM base\n");
return -EINVAL;
}
size = si->lfb_size;
if (si->orig_video_isVGA == VIDEO_TYPE_VLFB)
size <<= 16;
length = mode->height * mode->stride;
length = PAGE_ALIGN(length);
if (length > size) {
printk(KERN_WARNING "sysfb: VRAM smaller than advertised\n");
return -EINVAL;
}
memset(&res, 0, sizeof(res));
res.flags = IORESOURCE_MEM | IORESOURCE_BUSY;
res.name = simplefb_resname;
res.start = base;
res.end = res.start + length - 1;
if (res.end <= res.start)
return -EINVAL;
pd = platform_device_register_resndata(NULL, "simple-framebuffer", 0,
&res, 1, mode, sizeof(*mode));
return PTR_ERR_OR_ZERO(pd);
}
