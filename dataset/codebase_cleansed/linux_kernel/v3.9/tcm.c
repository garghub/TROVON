static struct tcm_pool *find_pool(unsigned int tag)
{
struct list_head *lh;
struct tcm_pool *pool;
list_for_each(lh, &pool_list) {
pool = list_entry(lh, struct tcm_pool, list);
if (pool->tag == tag)
return pool;
}
return NULL;
}
unsigned long tcm_alloc(unsigned int tag, size_t len)
{
unsigned long vaddr;
struct tcm_pool *pool;
pool = find_pool(tag);
if (!pool)
return 0;
vaddr = gen_pool_alloc(pool->pool, len);
if (!vaddr)
return 0;
return vaddr;
}
void tcm_free(unsigned int tag, unsigned long addr, size_t len)
{
struct tcm_pool *pool;
pool = find_pool(tag);
if (!pool)
return;
gen_pool_free(pool->pool, addr, len);
}
unsigned int tcm_lookup_tag(unsigned long p)
{
struct list_head *lh;
struct tcm_pool *pool;
unsigned long addr = (unsigned long) p;
list_for_each(lh, &pool_list) {
pool = list_entry(lh, struct tcm_pool, list);
if (addr >= pool->start && addr < pool->end)
return pool->tag;
}
return TCM_INVALID_TAG;
}
int __init tcm_add_region(struct tcm_region *reg)
{
struct tcm_pool *pool;
pool = kmalloc(sizeof(*pool), GFP_KERNEL);
if (!pool) {
pr_err("Failed to alloc memory for TCM pool!\n");
return -ENOMEM;
}
pool->tag = reg->tag;
pool->start = reg->res.start;
pool->end = reg->res.end;
pool->pool = gen_pool_create(3, -1);
if (!pool->pool) {
pr_err("Failed to create TCM pool!\n");
kfree(pool);
return -ENOMEM;
}
if (gen_pool_add(pool->pool, reg->res.start,
reg->res.end - reg->res.start + 1, -1)) {
pr_err("Failed to add memory to TCM pool!\n");
return -ENOMEM;
}
pr_info("Added %s TCM pool (%08x bytes @ %08x)\n",
reg->res.name, reg->res.end - reg->res.start + 1,
reg->res.start);
list_add_tail(&pool->list, &pool_list);
return 0;
}
