int sram_check_protect_exec(struct sram_dev *sram, struct sram_reserve *block,
struct sram_partition *part)
{
unsigned long base = (unsigned long)part->base;
unsigned long end = base + block->size;
if (!PAGE_ALIGNED(base) || !PAGE_ALIGNED(end)) {
dev_err(sram->dev,
"SRAM pool marked with 'protect-exec' is not page aligned and will not be created.\n");
return -ENOMEM;
}
return 0;
}
int sram_add_protect_exec(struct sram_partition *part)
{
mutex_lock(&exec_pool_list_mutex);
list_add_tail(&part->list, &exec_pool_list);
mutex_unlock(&exec_pool_list_mutex);
return 0;
}
void *sram_exec_copy(struct gen_pool *pool, void *dst, void *src,
size_t size)
{
struct sram_partition *part = NULL, *p;
unsigned long base;
int pages;
void *dst_cpy;
mutex_lock(&exec_pool_list_mutex);
list_for_each_entry(p, &exec_pool_list, list) {
if (p->pool == pool)
part = p;
}
mutex_unlock(&exec_pool_list_mutex);
if (!part)
return NULL;
if (!addr_in_gen_pool(pool, (unsigned long)dst, size))
return NULL;
base = (unsigned long)part->base;
pages = PAGE_ALIGN(size) / PAGE_SIZE;
mutex_lock(&part->lock);
set_memory_nx((unsigned long)base, pages);
set_memory_rw((unsigned long)base, pages);
dst_cpy = fncpy(dst, src, size);
set_memory_ro((unsigned long)base, pages);
set_memory_x((unsigned long)base, pages);
mutex_unlock(&part->lock);
return dst_cpy;
}
