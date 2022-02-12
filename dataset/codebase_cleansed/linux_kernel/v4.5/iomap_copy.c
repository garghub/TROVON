void __ioread32_copy(void *to, const void __iomem *from, size_t count)
{
u32 *dst = to;
const u32 __iomem *src = from;
const u32 __iomem *end = src + count;
while (src < end)
*dst++ = __raw_readl(src++);
}
