static unsigned int get_pages_from_reserved_pool(void *pool,
struct hmm_page_object *page_obj,
unsigned int size, bool cached)
{
unsigned long flags;
unsigned int i = 0;
unsigned int repool_pgnr;
int j;
struct hmm_reserved_pool_info *repool_info = pool;
if (!repool_info)
return 0;
spin_lock_irqsave(&repool_info->list_lock, flags);
if (repool_info->initialized) {
repool_pgnr = repool_info->index;
for (j = repool_pgnr-1; j >= 0; j--) {
page_obj[i].page = repool_info->pages[j];
page_obj[i].type = HMM_PAGE_TYPE_RESERVED;
i++;
repool_info->index--;
if (i == size)
break;
}
}
spin_unlock_irqrestore(&repool_info->list_lock, flags);
return i;
}
static void free_pages_to_reserved_pool(void *pool,
struct hmm_page_object *page_obj)
{
unsigned long flags;
struct hmm_reserved_pool_info *repool_info = pool;
if (!repool_info)
return;
spin_lock_irqsave(&repool_info->list_lock, flags);
if (repool_info->initialized &&
repool_info->index < repool_info->pgnr &&
page_obj->type == HMM_PAGE_TYPE_RESERVED) {
repool_info->pages[repool_info->index++] = page_obj->page;
}
spin_unlock_irqrestore(&repool_info->list_lock, flags);
}
static int hmm_reserved_pool_setup(struct hmm_reserved_pool_info **repool_info,
unsigned int pool_size)
{
struct hmm_reserved_pool_info *pool_info;
pool_info = kmalloc(sizeof(struct hmm_reserved_pool_info),
GFP_KERNEL);
if (unlikely(!pool_info)) {
dev_err(atomisp_dev, "out of memory for repool_info.\n");
return -ENOMEM;
}
pool_info->pages = kmalloc(sizeof(struct page *) * pool_size,
GFP_KERNEL);
if (unlikely(!pool_info->pages)) {
dev_err(atomisp_dev, "out of memory for repool_info->pages.\n");
kfree(pool_info);
return -ENOMEM;
}
pool_info->index = 0;
pool_info->pgnr = 0;
spin_lock_init(&pool_info->list_lock);
pool_info->initialized = true;
*repool_info = pool_info;
return 0;
}
static int hmm_reserved_pool_init(void **pool, unsigned int pool_size)
{
int ret;
unsigned int blk_pgnr;
unsigned int pgnr = pool_size;
unsigned int order = 0;
unsigned int i = 0;
int fail_number = 0;
struct page *pages;
int j;
struct hmm_reserved_pool_info *repool_info;
if (pool_size == 0)
return 0;
ret = hmm_reserved_pool_setup(&repool_info, pool_size);
if (ret) {
dev_err(atomisp_dev, "hmm_reserved_pool_setup failed.\n");
return ret;
}
pgnr = pool_size;
i = 0;
order = MAX_ORDER;
while (pgnr) {
blk_pgnr = 1U << order;
while (blk_pgnr > pgnr) {
order--;
blk_pgnr >>= 1U;
}
BUG_ON(order > MAX_ORDER);
pages = alloc_pages(GFP_KERNEL | __GFP_NOWARN, order);
if (unlikely(!pages)) {
if (order == 0) {
fail_number++;
dev_err(atomisp_dev, "%s: alloc_pages failed: %d\n",
__func__, fail_number);
if (fail_number == ALLOC_PAGE_FAIL_NUM)
goto end;
} else {
order--;
}
} else {
blk_pgnr = 1U << order;
ret = set_pages_uc(pages, blk_pgnr);
if (ret) {
dev_err(atomisp_dev,
"set pages uncached failed\n");
__free_pages(pages, order);
goto end;
}
for (j = 0; j < blk_pgnr; j++)
repool_info->pages[i++] = pages + j;
repool_info->index += blk_pgnr;
repool_info->pgnr += blk_pgnr;
pgnr -= blk_pgnr;
fail_number = 0;
}
}
end:
repool_info->initialized = true;
*pool = repool_info;
dev_info(atomisp_dev,
"hmm_reserved_pool init successfully,"
"hmm_reserved_pool is with %d pages.\n",
repool_info->pgnr);
return 0;
}
static void hmm_reserved_pool_exit(void **pool)
{
unsigned long flags;
int i, ret;
unsigned int pgnr;
struct hmm_reserved_pool_info *repool_info = *pool;
if (!repool_info)
return;
spin_lock_irqsave(&repool_info->list_lock, flags);
if (!repool_info->initialized) {
spin_unlock_irqrestore(&repool_info->list_lock, flags);
return;
}
pgnr = repool_info->pgnr;
repool_info->index = 0;
repool_info->pgnr = 0;
repool_info->initialized = false;
spin_unlock_irqrestore(&repool_info->list_lock, flags);
for (i = 0; i < pgnr; i++) {
ret = set_pages_wb(repool_info->pages[i], 1);
if (ret)
dev_err(atomisp_dev,
"set page to WB err...ret=%d\n", ret);
if (!ret)
__free_pages(repool_info->pages[i], 0);
}
kfree(repool_info->pages);
kfree(repool_info);
*pool = NULL;
}
static int hmm_reserved_pool_inited(void *pool)
{
struct hmm_reserved_pool_info *repool_info = pool;
if (!repool_info)
return 0;
return repool_info->initialized;
}
