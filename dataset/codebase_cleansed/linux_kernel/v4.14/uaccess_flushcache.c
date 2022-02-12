void memcpy_flushcache(void *dst, const void *src, size_t cnt)
{
memcpy(dst, src, cnt);
__clean_dcache_area_pop(dst, cnt);
}
void memcpy_page_flushcache(char *to, struct page *page, size_t offset,
size_t len)
{
memcpy_flushcache(to, page_address(page) + offset, len);
}
unsigned long __copy_user_flushcache(void *to, const void __user *from,
unsigned long n)
{
unsigned long rc = __arch_copy_from_user(to, from, n);
__clean_dcache_area_pop(to, n - rc);
return rc;
}
