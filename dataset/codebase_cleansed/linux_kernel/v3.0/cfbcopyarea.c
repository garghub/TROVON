static void
bitcpy(struct fb_info *p, unsigned long __iomem *dst, int dst_idx,
const unsigned long __iomem *src, int src_idx, int bits,
unsigned n, u32 bswapmask)
{
unsigned long first, last;
int const shift = dst_idx-src_idx;
int left, right;
first = fb_shifted_pixels_mask_long(p, dst_idx, bswapmask);
last = ~fb_shifted_pixels_mask_long(p, (dst_idx+n) % bits, bswapmask);
if (!shift) {
if (dst_idx+n <= bits) {
if (last)
first &= last;
FB_WRITEL( comp( FB_READL(src), FB_READL(dst), first), dst);
} else {
if (first != ~0UL) {
FB_WRITEL( comp( FB_READL(src), FB_READL(dst), first), dst);
dst++;
src++;
n -= bits - dst_idx;
}
n /= bits;
while (n >= 8) {
FB_WRITEL(FB_READL(src++), dst++);
FB_WRITEL(FB_READL(src++), dst++);
FB_WRITEL(FB_READL(src++), dst++);
FB_WRITEL(FB_READL(src++), dst++);
FB_WRITEL(FB_READL(src++), dst++);
FB_WRITEL(FB_READL(src++), dst++);
FB_WRITEL(FB_READL(src++), dst++);
FB_WRITEL(FB_READL(src++), dst++);
n -= 8;
}
while (n--)
FB_WRITEL(FB_READL(src++), dst++);
if (last)
FB_WRITEL( comp( FB_READL(src), FB_READL(dst), last), dst);
}
} else {
unsigned long d0, d1;
int m;
right = shift & (bits - 1);
left = -shift & (bits - 1);
bswapmask &= shift;
if (dst_idx+n <= bits) {
if (last)
first &= last;
d0 = FB_READL(src);
d0 = fb_rev_pixels_in_long(d0, bswapmask);
if (shift > 0) {
d0 >>= right;
} else if (src_idx+n <= bits) {
d0 <<= left;
} else {
d1 = FB_READL(src + 1);
d1 = fb_rev_pixels_in_long(d1, bswapmask);
d0 = d0<<left | d1>>right;
}
d0 = fb_rev_pixels_in_long(d0, bswapmask);
FB_WRITEL(comp(d0, FB_READL(dst), first), dst);
} else {
d0 = FB_READL(src++);
d0 = fb_rev_pixels_in_long(d0, bswapmask);
if (shift > 0) {
d1 = d0;
d0 >>= right;
dst++;
n -= bits - dst_idx;
} else {
d1 = FB_READL(src++);
d1 = fb_rev_pixels_in_long(d1, bswapmask);
d0 = d0<<left | d1>>right;
dst++;
n -= bits - dst_idx;
}
d0 = fb_rev_pixels_in_long(d0, bswapmask);
FB_WRITEL(comp(d0, FB_READL(dst), first), dst);
d0 = d1;
m = n % bits;
n /= bits;
while ((n >= 4) && !bswapmask) {
d1 = FB_READL(src++);
FB_WRITEL(d0 << left | d1 >> right, dst++);
d0 = d1;
d1 = FB_READL(src++);
FB_WRITEL(d0 << left | d1 >> right, dst++);
d0 = d1;
d1 = FB_READL(src++);
FB_WRITEL(d0 << left | d1 >> right, dst++);
d0 = d1;
d1 = FB_READL(src++);
FB_WRITEL(d0 << left | d1 >> right, dst++);
d0 = d1;
n -= 4;
}
while (n--) {
d1 = FB_READL(src++);
d1 = fb_rev_pixels_in_long(d1, bswapmask);
d0 = d0 << left | d1 >> right;
d0 = fb_rev_pixels_in_long(d0, bswapmask);
FB_WRITEL(d0, dst++);
d0 = d1;
}
if (last) {
if (m <= right) {
d0 <<= left;
} else {
d1 = FB_READL(src);
d1 = fb_rev_pixels_in_long(d1,
bswapmask);
d0 = d0<<left | d1>>right;
}
d0 = fb_rev_pixels_in_long(d0, bswapmask);
FB_WRITEL(comp(d0, FB_READL(dst), last), dst);
}
}
}
}
static void
bitcpy_rev(struct fb_info *p, unsigned long __iomem *dst, int dst_idx,
const unsigned long __iomem *src, int src_idx, int bits,
unsigned n, u32 bswapmask)
{
unsigned long first, last;
int shift;
dst += (n-1)/bits;
src += (n-1)/bits;
if ((n-1) % bits) {
dst_idx += (n-1) % bits;
dst += dst_idx >> (ffs(bits) - 1);
dst_idx &= bits - 1;
src_idx += (n-1) % bits;
src += src_idx >> (ffs(bits) - 1);
src_idx &= bits - 1;
}
shift = dst_idx-src_idx;
first = fb_shifted_pixels_mask_long(p, bits - 1 - dst_idx, bswapmask);
last = ~fb_shifted_pixels_mask_long(p, bits - 1 - ((dst_idx-n) % bits),
bswapmask);
if (!shift) {
if ((unsigned long)dst_idx+1 >= n) {
if (last)
first &= last;
FB_WRITEL( comp( FB_READL(src), FB_READL(dst), first), dst);
} else {
if (first != ~0UL) {
FB_WRITEL( comp( FB_READL(src), FB_READL(dst), first), dst);
dst--;
src--;
n -= dst_idx+1;
}
n /= bits;
while (n >= 8) {
FB_WRITEL(FB_READL(src--), dst--);
FB_WRITEL(FB_READL(src--), dst--);
FB_WRITEL(FB_READL(src--), dst--);
FB_WRITEL(FB_READL(src--), dst--);
FB_WRITEL(FB_READL(src--), dst--);
FB_WRITEL(FB_READL(src--), dst--);
FB_WRITEL(FB_READL(src--), dst--);
FB_WRITEL(FB_READL(src--), dst--);
n -= 8;
}
while (n--)
FB_WRITEL(FB_READL(src--), dst--);
if (last)
FB_WRITEL( comp( FB_READL(src), FB_READL(dst), last), dst);
}
} else {
unsigned long d0, d1;
int m;
int const left = -shift & (bits-1);
int const right = shift & (bits-1);
bswapmask &= shift;
if ((unsigned long)dst_idx+1 >= n) {
if (last)
first &= last;
d0 = FB_READL(src);
if (shift < 0) {
d0 <<= left;
} else if (1+(unsigned long)src_idx >= n) {
d0 >>= right;
} else {
d1 = FB_READL(src - 1);
d1 = fb_rev_pixels_in_long(d1, bswapmask);
d0 = d0>>right | d1<<left;
}
d0 = fb_rev_pixels_in_long(d0, bswapmask);
FB_WRITEL(comp(d0, FB_READL(dst), first), dst);
} else {
d0 = FB_READL(src--);
d0 = fb_rev_pixels_in_long(d0, bswapmask);
if (shift < 0) {
d1 = d0;
d0 <<= left;
} else {
d1 = FB_READL(src--);
d1 = fb_rev_pixels_in_long(d1, bswapmask);
d0 = d0>>right | d1<<left;
}
d0 = fb_rev_pixels_in_long(d0, bswapmask);
FB_WRITEL(comp(d0, FB_READL(dst), first), dst);
d0 = d1;
dst--;
n -= dst_idx+1;
m = n % bits;
n /= bits;
while ((n >= 4) && !bswapmask) {
d1 = FB_READL(src--);
FB_WRITEL(d0 >> right | d1 << left, dst--);
d0 = d1;
d1 = FB_READL(src--);
FB_WRITEL(d0 >> right | d1 << left, dst--);
d0 = d1;
d1 = FB_READL(src--);
FB_WRITEL(d0 >> right | d1 << left, dst--);
d0 = d1;
d1 = FB_READL(src--);
FB_WRITEL(d0 >> right | d1 << left, dst--);
d0 = d1;
n -= 4;
}
while (n--) {
d1 = FB_READL(src--);
d1 = fb_rev_pixels_in_long(d1, bswapmask);
d0 = d0 >> right | d1 << left;
d0 = fb_rev_pixels_in_long(d0, bswapmask);
FB_WRITEL(d0, dst--);
d0 = d1;
}
if (last) {
if (m <= left) {
d0 >>= right;
} else {
d1 = FB_READL(src);
d1 = fb_rev_pixels_in_long(d1,
bswapmask);
d0 = d0>>right | d1<<left;
}
d0 = fb_rev_pixels_in_long(d0, bswapmask);
FB_WRITEL(comp(d0, FB_READL(dst), last), dst);
}
}
}
}
void cfb_copyarea(struct fb_info *p, const struct fb_copyarea *area)
{
u32 dx = area->dx, dy = area->dy, sx = area->sx, sy = area->sy;
u32 height = area->height, width = area->width;
unsigned long const bits_per_line = p->fix.line_length*8u;
unsigned long __iomem *dst = NULL, *src = NULL;
int bits = BITS_PER_LONG, bytes = bits >> 3;
int dst_idx = 0, src_idx = 0, rev_copy = 0;
u32 bswapmask = fb_compute_bswapmask(p);
if (p->state != FBINFO_STATE_RUNNING)
return;
if ((dy == sy && dx > sx) || (dy > sy)) {
dy += height;
sy += height;
rev_copy = 1;
}
dst = src = (unsigned long __iomem *)((unsigned long)p->screen_base & ~(bytes-1));
dst_idx = src_idx = 8*((unsigned long)p->screen_base & (bytes-1));
dst_idx += dy*bits_per_line + dx*p->var.bits_per_pixel;
src_idx += sy*bits_per_line + sx*p->var.bits_per_pixel;
if (p->fbops->fb_sync)
p->fbops->fb_sync(p);
if (rev_copy) {
while (height--) {
dst_idx -= bits_per_line;
src_idx -= bits_per_line;
dst += dst_idx >> (ffs(bits) - 1);
dst_idx &= (bytes - 1);
src += src_idx >> (ffs(bits) - 1);
src_idx &= (bytes - 1);
bitcpy_rev(p, dst, dst_idx, src, src_idx, bits,
width*p->var.bits_per_pixel, bswapmask);
}
} else {
while (height--) {
dst += dst_idx >> (ffs(bits) - 1);
dst_idx &= (bytes - 1);
src += src_idx >> (ffs(bits) - 1);
src_idx &= (bytes - 1);
bitcpy(p, dst, dst_idx, src, src_idx, bits,
width*p->var.bits_per_pixel, bswapmask);
dst_idx += bits_per_line;
src_idx += bits_per_line;
}
}
}
