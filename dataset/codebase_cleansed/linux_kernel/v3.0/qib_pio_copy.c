void qib_pio_copy(void __iomem *to, const void *from, size_t count)
{
#ifdef CONFIG_64BIT
u64 __iomem *dst = to;
const u64 *src = from;
const u64 *end = src + (count >> 1);
while (src < end)
__raw_writeq(*src++, dst++);
if (count & 1)
__raw_writel(*(const u32 *)src, dst);
#else
u32 __iomem *dst = to;
const u32 *src = from;
const u32 *end = src + count;
while (src < end)
__raw_writel(*src++, dst++);
#endif
}
