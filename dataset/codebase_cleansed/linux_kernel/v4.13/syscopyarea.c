static void
bitcpy(struct fb_info *p, unsigned long *dst, unsigned dst_idx,
const unsigned long *src, unsigned src_idx, int bits, unsigned n)
{
unsigned long first, last;
int const shift = dst_idx-src_idx;
int left, right;
first = FB_SHIFT_HIGH(p, ~0UL, dst_idx);
last = ~(FB_SHIFT_HIGH(p, ~0UL, (dst_idx+n) % bits));
if (!shift) {
if (dst_idx+n <= bits) {
if (last)
first &= last;
*dst = comp(*src, *dst, first);
} else {
if (first != ~0UL) {
*dst = comp(*src, *dst, first);
dst++;
src++;
n -= bits - dst_idx;
}
n /= bits;
while (n >= 8) {
*dst++ = *src++;
*dst++ = *src++;
*dst++ = *src++;
*dst++ = *src++;
*dst++ = *src++;
*dst++ = *src++;
*dst++ = *src++;
*dst++ = *src++;
n -= 8;
}
while (n--)
*dst++ = *src++;
if (last)
*dst = comp(*src, *dst, last);
}
} else {
unsigned long d0, d1;
int m;
right = shift & (bits - 1);
left = -shift & (bits - 1);
if (dst_idx+n <= bits) {
if (last)
first &= last;
if (shift > 0) {
*dst = comp(*src << left, *dst, first);
} else if (src_idx+n <= bits) {
*dst = comp(*src >> right, *dst, first);
} else {
d0 = *src++;
d1 = *src;
*dst = comp(d0 >> right | d1 << left, *dst,
first);
}
} else {
d0 = *src++;
if (shift > 0) {
*dst = comp(d0 << left, *dst, first);
dst++;
n -= bits - dst_idx;
} else {
d1 = *src++;
*dst = comp(d0 >> right | d1 << left, *dst,
first);
d0 = d1;
dst++;
n -= bits - dst_idx;
}
m = n % bits;
n /= bits;
while (n >= 4) {
d1 = *src++;
*dst++ = d0 >> right | d1 << left;
d0 = d1;
d1 = *src++;
*dst++ = d0 >> right | d1 << left;
d0 = d1;
d1 = *src++;
*dst++ = d0 >> right | d1 << left;
d0 = d1;
d1 = *src++;
*dst++ = d0 >> right | d1 << left;
d0 = d1;
n -= 4;
}
while (n--) {
d1 = *src++;
*dst++ = d0 >> right | d1 << left;
d0 = d1;
}
if (m) {
if (m <= bits - right) {
d0 >>= right;
} else {
d1 = *src;
d0 = d0 >> right | d1 << left;
}
*dst = comp(d0, *dst, last);
}
}
}
}
static void
bitcpy_rev(struct fb_info *p, unsigned long *dst, unsigned dst_idx,
const unsigned long *src, unsigned src_idx, unsigned bits,
unsigned n)
{
unsigned long first, last;
int shift;
dst += (dst_idx + n - 1) / bits;
src += (src_idx + n - 1) / bits;
dst_idx = (dst_idx + n - 1) % bits;
src_idx = (src_idx + n - 1) % bits;
shift = dst_idx-src_idx;
first = ~FB_SHIFT_HIGH(p, ~0UL, (dst_idx + 1) % bits);
last = FB_SHIFT_HIGH(p, ~0UL, (bits + dst_idx + 1 - n) % bits);
if (!shift) {
if ((unsigned long)dst_idx+1 >= n) {
if (first)
last &= first;
*dst = comp(*src, *dst, last);
} else {
if (first) {
*dst = comp(*src, *dst, first);
dst--;
src--;
n -= dst_idx+1;
}
n /= bits;
while (n >= 8) {
*dst-- = *src--;
*dst-- = *src--;
*dst-- = *src--;
*dst-- = *src--;
*dst-- = *src--;
*dst-- = *src--;
*dst-- = *src--;
*dst-- = *src--;
n -= 8;
}
while (n--)
*dst-- = *src--;
if (last != -1UL)
*dst = comp(*src, *dst, last);
}
} else {
int const left = shift & (bits-1);
int const right = -shift & (bits-1);
if ((unsigned long)dst_idx+1 >= n) {
if (first)
last &= first;
if (shift < 0) {
*dst = comp(*src >> right, *dst, last);
} else if (1+(unsigned long)src_idx >= n) {
*dst = comp(*src << left, *dst, last);
} else {
*dst = comp(*src << left | *(src-1) >> right,
*dst, last);
}
} else {
unsigned long d0, d1;
int m;
d0 = *src--;
if (shift < 0) {
d1 = d0;
d0 >>= right;
} else {
d1 = *src--;
d0 = d0 << left | d1 >> right;
}
if (!first)
*dst = d0;
else
*dst = comp(d0, *dst, first);
d0 = d1;
dst--;
n -= dst_idx+1;
m = n % bits;
n /= bits;
while (n >= 4) {
d1 = *src--;
*dst-- = d0 << left | d1 >> right;
d0 = d1;
d1 = *src--;
*dst-- = d0 << left | d1 >> right;
d0 = d1;
d1 = *src--;
*dst-- = d0 << left | d1 >> right;
d0 = d1;
d1 = *src--;
*dst-- = d0 << left | d1 >> right;
d0 = d1;
n -= 4;
}
while (n--) {
d1 = *src--;
*dst-- = d0 << left | d1 >> right;
d0 = d1;
}
if (m) {
if (m <= bits - left) {
d0 <<= left;
} else {
d1 = *src;
d0 = d0 << left | d1 >> right;
}
*dst = comp(d0, *dst, last);
}
}
}
}
void sys_copyarea(struct fb_info *p, const struct fb_copyarea *area)
{
u32 dx = area->dx, dy = area->dy, sx = area->sx, sy = area->sy;
u32 height = area->height, width = area->width;
unsigned long const bits_per_line = p->fix.line_length*8u;
unsigned long *base = NULL;
int bits = BITS_PER_LONG, bytes = bits >> 3;
unsigned dst_idx = 0, src_idx = 0, rev_copy = 0;
if (p->state != FBINFO_STATE_RUNNING)
return;
if ((dy == sy && dx > sx) || (dy > sy)) {
dy += height;
sy += height;
rev_copy = 1;
}
base = (unsigned long *)((unsigned long)p->screen_base & ~(bytes-1));
dst_idx = src_idx = 8*((unsigned long)p->screen_base & (bytes-1));
dst_idx += dy*bits_per_line + dx*p->var.bits_per_pixel;
src_idx += sy*bits_per_line + sx*p->var.bits_per_pixel;
if (p->fbops->fb_sync)
p->fbops->fb_sync(p);
if (rev_copy) {
while (height--) {
dst_idx -= bits_per_line;
src_idx -= bits_per_line;
bitcpy_rev(p, base + (dst_idx / bits), dst_idx % bits,
base + (src_idx / bits), src_idx % bits, bits,
width*p->var.bits_per_pixel);
}
} else {
while (height--) {
bitcpy(p, base + (dst_idx / bits), dst_idx % bits,
base + (src_idx / bits), src_idx % bits, bits,
width*p->var.bits_per_pixel);
dst_idx += bits_per_line;
src_idx += bits_per_line;
}
}
}
