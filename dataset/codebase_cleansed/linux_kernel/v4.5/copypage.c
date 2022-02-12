void __cpu_copy_user_page(void *kto, const void *kfrom, unsigned long vaddr)
{
struct page *page = virt_to_page(kto);
copy_page(kto, kfrom);
flush_dcache_page(page);
}
void __cpu_clear_user_page(void *kaddr, unsigned long vaddr)
{
clear_page(kaddr);
}
