int fb_alloc_cmap_gfp(struct fb_cmap *cmap, int len, int transp, gfp_t flags)
{
int size = len * sizeof(u16);
int ret = -ENOMEM;
if (cmap->len != len) {
fb_dealloc_cmap(cmap);
if (!len)
return 0;
cmap->red = kmalloc(size, flags);
if (!cmap->red)
goto fail;
cmap->green = kmalloc(size, flags);
if (!cmap->green)
goto fail;
cmap->blue = kmalloc(size, flags);
if (!cmap->blue)
goto fail;
if (transp) {
cmap->transp = kmalloc(size, flags);
if (!cmap->transp)
goto fail;
} else {
cmap->transp = NULL;
}
}
cmap->start = 0;
cmap->len = len;
ret = fb_copy_cmap(fb_default_cmap(len), cmap);
if (ret)
goto fail;
return 0;
fail:
fb_dealloc_cmap(cmap);
return ret;
}
int fb_alloc_cmap(struct fb_cmap *cmap, int len, int transp)
{
return fb_alloc_cmap_gfp(cmap, len, transp, GFP_ATOMIC);
}
void fb_dealloc_cmap(struct fb_cmap *cmap)
{
kfree(cmap->red);
kfree(cmap->green);
kfree(cmap->blue);
kfree(cmap->transp);
cmap->red = cmap->green = cmap->blue = cmap->transp = NULL;
cmap->len = 0;
}
int fb_copy_cmap(const struct fb_cmap *from, struct fb_cmap *to)
{
unsigned int tooff = 0, fromoff = 0;
size_t size;
if (to->start > from->start)
fromoff = to->start - from->start;
else
tooff = from->start - to->start;
if (fromoff >= from->len || tooff >= to->len)
return -EINVAL;
size = min_t(size_t, to->len - tooff, from->len - fromoff);
if (size == 0)
return -EINVAL;
size *= sizeof(u16);
memcpy(to->red+tooff, from->red+fromoff, size);
memcpy(to->green+tooff, from->green+fromoff, size);
memcpy(to->blue+tooff, from->blue+fromoff, size);
if (from->transp && to->transp)
memcpy(to->transp+tooff, from->transp+fromoff, size);
return 0;
}
int fb_cmap_to_user(const struct fb_cmap *from, struct fb_cmap_user *to)
{
unsigned int tooff = 0, fromoff = 0;
size_t size;
if (to->start > from->start)
fromoff = to->start - from->start;
else
tooff = from->start - to->start;
if (fromoff >= from->len || tooff >= to->len)
return -EINVAL;
size = min_t(size_t, to->len - tooff, from->len - fromoff);
if (size == 0)
return -EINVAL;
size *= sizeof(u16);
if (copy_to_user(to->red+tooff, from->red+fromoff, size))
return -EFAULT;
if (copy_to_user(to->green+tooff, from->green+fromoff, size))
return -EFAULT;
if (copy_to_user(to->blue+tooff, from->blue+fromoff, size))
return -EFAULT;
if (from->transp && to->transp)
if (copy_to_user(to->transp+tooff, from->transp+fromoff, size))
return -EFAULT;
return 0;
}
int fb_set_cmap(struct fb_cmap *cmap, struct fb_info *info)
{
int i, start, rc = 0;
u16 *red, *green, *blue, *transp;
u_int hred, hgreen, hblue, htransp = 0xffff;
red = cmap->red;
green = cmap->green;
blue = cmap->blue;
transp = cmap->transp;
start = cmap->start;
if (start < 0 || (!info->fbops->fb_setcolreg &&
!info->fbops->fb_setcmap))
return -EINVAL;
if (info->fbops->fb_setcmap) {
rc = info->fbops->fb_setcmap(cmap, info);
} else {
for (i = 0; i < cmap->len; i++) {
hred = *red++;
hgreen = *green++;
hblue = *blue++;
if (transp)
htransp = *transp++;
if (info->fbops->fb_setcolreg(start++,
hred, hgreen, hblue,
htransp, info))
break;
}
}
if (rc == 0)
fb_copy_cmap(cmap, &info->cmap);
return rc;
}
int fb_set_user_cmap(struct fb_cmap_user *cmap, struct fb_info *info)
{
int rc, size = cmap->len * sizeof(u16);
struct fb_cmap umap;
if (size < 0 || size < cmap->len)
return -E2BIG;
memset(&umap, 0, sizeof(struct fb_cmap));
rc = fb_alloc_cmap_gfp(&umap, cmap->len, cmap->transp != NULL,
GFP_KERNEL);
if (rc)
return rc;
if (copy_from_user(umap.red, cmap->red, size) ||
copy_from_user(umap.green, cmap->green, size) ||
copy_from_user(umap.blue, cmap->blue, size) ||
(cmap->transp && copy_from_user(umap.transp, cmap->transp, size))) {
rc = -EFAULT;
goto out;
}
umap.start = cmap->start;
if (!lock_fb_info(info)) {
rc = -ENODEV;
goto out;
}
rc = fb_set_cmap(&umap, info);
unlock_fb_info(info);
out:
fb_dealloc_cmap(&umap);
return rc;
}
const struct fb_cmap *fb_default_cmap(int len)
{
if (len <= 2)
return &default_2_colors;
if (len <= 4)
return &default_4_colors;
if (len <= 8)
return &default_8_colors;
return &default_16_colors;
}
void fb_invert_cmaps(void)
{
u_int i;
for (i = 0; i < ARRAY_SIZE(red2); i++) {
red2[i] = ~red2[i];
green2[i] = ~green2[i];
blue2[i] = ~blue2[i];
}
for (i = 0; i < ARRAY_SIZE(red4); i++) {
red4[i] = ~red4[i];
green4[i] = ~green4[i];
blue4[i] = ~blue4[i];
}
for (i = 0; i < ARRAY_SIZE(red8); i++) {
red8[i] = ~red8[i];
green8[i] = ~green8[i];
blue8[i] = ~blue8[i];
}
for (i = 0; i < ARRAY_SIZE(red16); i++) {
red16[i] = ~red16[i];
green16[i] = ~green16[i];
blue16[i] = ~blue16[i];
}
}
