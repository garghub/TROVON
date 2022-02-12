void __flush_icache_range(unsigned long start, unsigned long end)
{
invalidate_icache((const void *)start, end - start, PAGE_SIZE);
}
static inline void force_load(char *p)
{
*(volatile char *)p;
}
