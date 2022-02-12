unsigned long __phys_addr(unsigned long x)
{
unsigned long y = x - __START_KERNEL_map;
if (unlikely(x > y)) {
x = y + phys_base;
VIRTUAL_BUG_ON(y >= KERNEL_IMAGE_SIZE);
} else {
x = y + (__START_KERNEL_map - PAGE_OFFSET);
VIRTUAL_BUG_ON((x > y) || !phys_addr_valid(x));
}
return x;
}
unsigned long __phys_addr_symbol(unsigned long x)
{
unsigned long y = x - __START_KERNEL_map;
VIRTUAL_BUG_ON(y >= KERNEL_IMAGE_SIZE);
return y + phys_base;
}
bool __virt_addr_valid(unsigned long x)
{
unsigned long y = x - __START_KERNEL_map;
if (unlikely(x > y)) {
x = y + phys_base;
if (y >= KERNEL_IMAGE_SIZE)
return false;
} else {
x = y + (__START_KERNEL_map - PAGE_OFFSET);
if ((x > y) || !phys_addr_valid(x))
return false;
}
return pfn_valid(x >> PAGE_SHIFT);
}
unsigned long __phys_addr(unsigned long x)
{
unsigned long phys_addr = x - PAGE_OFFSET;
VIRTUAL_BUG_ON(x < PAGE_OFFSET);
VIRTUAL_BUG_ON(__vmalloc_start_set && is_vmalloc_addr((void *) x));
if (max_low_pfn) {
VIRTUAL_BUG_ON((phys_addr >> PAGE_SHIFT) > max_low_pfn);
BUG_ON(slow_virt_to_phys((void *)x) != phys_addr);
}
return phys_addr;
}
bool __virt_addr_valid(unsigned long x)
{
if (x < PAGE_OFFSET)
return false;
if (__vmalloc_start_set && is_vmalloc_addr((void *) x))
return false;
if (x >= FIXADDR_START)
return false;
return pfn_valid((x - PAGE_OFFSET) >> PAGE_SHIFT);
}
