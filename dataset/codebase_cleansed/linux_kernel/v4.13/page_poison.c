static int early_page_poison_param(char *buf)
{
if (!buf)
return -EINVAL;
return strtobool(buf, &want_page_poisoning);
}
bool page_poisoning_enabled(void)
{
return (want_page_poisoning ||
(!IS_ENABLED(CONFIG_ARCH_SUPPORTS_DEBUG_PAGEALLOC) &&
debug_pagealloc_enabled()));
}
static void poison_page(struct page *page)
{
void *addr = kmap_atomic(page);
memset(addr, PAGE_POISON, PAGE_SIZE);
kunmap_atomic(addr);
}
static void poison_pages(struct page *page, int n)
{
int i;
for (i = 0; i < n; i++)
poison_page(page + i);
}
static bool single_bit_flip(unsigned char a, unsigned char b)
{
unsigned char error = a ^ b;
return error && !(error & (error - 1));
}
static void check_poison_mem(unsigned char *mem, size_t bytes)
{
static DEFINE_RATELIMIT_STATE(ratelimit, 5 * HZ, 10);
unsigned char *start;
unsigned char *end;
if (IS_ENABLED(CONFIG_PAGE_POISONING_NO_SANITY))
return;
start = memchr_inv(mem, PAGE_POISON, bytes);
if (!start)
return;
for (end = mem + bytes - 1; end > start; end--) {
if (*end != PAGE_POISON)
break;
}
if (!__ratelimit(&ratelimit))
return;
else if (start == end && single_bit_flip(*start, PAGE_POISON))
pr_err("pagealloc: single bit error\n");
else
pr_err("pagealloc: memory corruption\n");
print_hex_dump(KERN_ERR, "", DUMP_PREFIX_ADDRESS, 16, 1, start,
end - start + 1, 1);
dump_stack();
}
static void unpoison_page(struct page *page)
{
void *addr;
addr = kmap_atomic(page);
check_poison_mem(addr, PAGE_SIZE);
kunmap_atomic(addr);
}
static void unpoison_pages(struct page *page, int n)
{
int i;
for (i = 0; i < n; i++)
unpoison_page(page + i);
}
void kernel_poison_pages(struct page *page, int numpages, int enable)
{
if (!page_poisoning_enabled())
return;
if (enable)
unpoison_pages(page, numpages);
else
poison_pages(page, numpages);
}
void __kernel_map_pages(struct page *page, int numpages, int enable)
{
}
