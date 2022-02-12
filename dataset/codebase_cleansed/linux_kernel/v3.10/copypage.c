void __cpu_copy_user_page(void *kto, const void *kfrom, unsigned long vaddr)
{
copy_page(kto, kfrom);
__flush_dcache_area(kto, PAGE_SIZE);
}
void __cpu_clear_user_page(void *kaddr, unsigned long vaddr)
{
clear_page(kaddr);
}
