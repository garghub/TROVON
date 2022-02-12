static void
drm_clflush_page(struct page *page)
{
uint8_t *page_virtual;
unsigned int i;
if (unlikely(page == NULL))
return;
page_virtual = kmap_atomic(page, KM_USER0);
for (i = 0; i < PAGE_SIZE; i += boot_cpu_data.x86_clflush_size)
clflush(page_virtual + i);
kunmap_atomic(page_virtual, KM_USER0);
}
static void drm_cache_flush_clflush(struct page *pages[],
unsigned long num_pages)
{
unsigned long i;
mb();
for (i = 0; i < num_pages; i++)
drm_clflush_page(*pages++);
mb();
}
static void
drm_clflush_ipi_handler(void *null)
{
wbinvd();
}
void
drm_clflush_pages(struct page *pages[], unsigned long num_pages)
{
#if defined(CONFIG_X86)
if (cpu_has_clflush) {
drm_cache_flush_clflush(pages, num_pages);
return;
}
if (on_each_cpu(drm_clflush_ipi_handler, NULL, 1) != 0)
printk(KERN_ERR "Timed out waiting for cache flush.\n");
#elif defined(__powerpc__)
unsigned long i;
for (i = 0; i < num_pages; i++) {
struct page *page = pages[i];
void *page_virtual;
if (unlikely(page == NULL))
continue;
page_virtual = kmap_atomic(page, KM_USER0);
flush_dcache_range((unsigned long)page_virtual,
(unsigned long)page_virtual + PAGE_SIZE);
kunmap_atomic(page_virtual, KM_USER0);
}
#else
printk(KERN_ERR "Architecture has no drm_cache.c support\n");
WARN_ON_ONCE(1);
#endif
}
