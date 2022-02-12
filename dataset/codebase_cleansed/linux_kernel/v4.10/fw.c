static
void wil_memset_toio_32(volatile void __iomem *dst, u32 val,
size_t count)
{
volatile u32 __iomem *d = dst;
for (count += 4; count > 4; count -= 4)
__raw_writel(val, d++);
}
