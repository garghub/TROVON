unsigned long intc_phys_to_virt(struct intc_desc_int *d, unsigned long address)
{
struct intc_window *window;
int k;
for (k = 0; k < d->nr_windows; k++) {
window = d->window + k;
if (address < window->phys)
continue;
if (address >= (window->phys + window->size))
continue;
address -= window->phys;
address += (unsigned long)window->virt;
return address;
}
return address;
}
unsigned int intc_get_reg(struct intc_desc_int *d, unsigned long address)
{
unsigned int k;
address = intc_phys_to_virt(d, address);
for (k = 0; k < d->nr_reg; k++) {
if (d->reg[k] == address)
return k;
}
BUG();
return 0;
}
unsigned int intc_set_field_from_handle(unsigned int value,
unsigned int field_value,
unsigned int handle)
{
unsigned int width = _INTC_WIDTH(handle);
unsigned int shift = _INTC_SHIFT(handle);
value &= ~(((1 << width) - 1) << shift);
value |= field_value << shift;
return value;
}
unsigned long intc_get_field_from_handle(unsigned int value, unsigned int handle)
{
unsigned int width = _INTC_WIDTH(handle);
unsigned int shift = _INTC_SHIFT(handle);
unsigned int mask = ((1 << width) - 1) << shift;
return (value & mask) >> shift;
}
static unsigned long test_8(unsigned long addr, unsigned long h,
unsigned long ignore)
{
void __iomem *ptr = (void __iomem *)addr;
return intc_get_field_from_handle(__raw_readb(ptr), h);
}
static unsigned long test_16(unsigned long addr, unsigned long h,
unsigned long ignore)
{
void __iomem *ptr = (void __iomem *)addr;
return intc_get_field_from_handle(__raw_readw(ptr), h);
}
static unsigned long test_32(unsigned long addr, unsigned long h,
unsigned long ignore)
{
void __iomem *ptr = (void __iomem *)addr;
return intc_get_field_from_handle(__raw_readl(ptr), h);
}
static unsigned long write_8(unsigned long addr, unsigned long h,
unsigned long data)
{
void __iomem *ptr = (void __iomem *)addr;
__raw_writeb(intc_set_field_from_handle(0, data, h), ptr);
(void)__raw_readb(ptr);
return 0;
}
static unsigned long write_16(unsigned long addr, unsigned long h,
unsigned long data)
{
void __iomem *ptr = (void __iomem *)addr;
__raw_writew(intc_set_field_from_handle(0, data, h), ptr);
(void)__raw_readw(ptr);
return 0;
}
static unsigned long write_32(unsigned long addr, unsigned long h,
unsigned long data)
{
void __iomem *ptr = (void __iomem *)addr;
__raw_writel(intc_set_field_from_handle(0, data, h), ptr);
(void)__raw_readl(ptr);
return 0;
}
static unsigned long modify_8(unsigned long addr, unsigned long h,
unsigned long data)
{
void __iomem *ptr = (void __iomem *)addr;
unsigned long flags;
unsigned int value;
local_irq_save(flags);
value = intc_set_field_from_handle(__raw_readb(ptr), data, h);
__raw_writeb(value, ptr);
(void)__raw_readb(ptr);
local_irq_restore(flags);
return 0;
}
static unsigned long modify_16(unsigned long addr, unsigned long h,
unsigned long data)
{
void __iomem *ptr = (void __iomem *)addr;
unsigned long flags;
unsigned int value;
local_irq_save(flags);
value = intc_set_field_from_handle(__raw_readw(ptr), data, h);
__raw_writew(value, ptr);
(void)__raw_readw(ptr);
local_irq_restore(flags);
return 0;
}
static unsigned long modify_32(unsigned long addr, unsigned long h,
unsigned long data)
{
void __iomem *ptr = (void __iomem *)addr;
unsigned long flags;
unsigned int value;
local_irq_save(flags);
value = intc_set_field_from_handle(__raw_readl(ptr), data, h);
__raw_writel(value, ptr);
(void)__raw_readl(ptr);
local_irq_restore(flags);
return 0;
}
