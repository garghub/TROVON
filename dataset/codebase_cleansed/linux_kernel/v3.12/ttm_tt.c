static void ttm_tt_alloc_page_directory(struct ttm_tt *ttm)
{
ttm->pages = drm_calloc_large(ttm->num_pages, sizeof(void*));
}
static void ttm_dma_tt_alloc_page_directory(struct ttm_dma_tt *ttm)
{
ttm->ttm.pages = drm_calloc_large(ttm->ttm.num_pages, sizeof(void*));
ttm->dma_address = drm_calloc_large(ttm->ttm.num_pages,
sizeof(*ttm->dma_address));
}
static inline int ttm_tt_set_page_caching(struct page *p,
enum ttm_caching_state c_old,
enum ttm_caching_state c_new)
{
int ret = 0;
if (PageHighMem(p))
return 0;
if (c_old != tt_cached) {
ret = set_pages_wb(p, 1);
if (ret)
return ret;
}
if (c_new == tt_wc)
ret = set_memory_wc((unsigned long) page_address(p), 1);
else if (c_new == tt_uncached)
ret = set_pages_uc(p, 1);
return ret;
}
static inline int ttm_tt_set_page_caching(struct page *p,
enum ttm_caching_state c_old,
enum ttm_caching_state c_new)
{
return 0;
}
static int ttm_tt_set_caching(struct ttm_tt *ttm,
enum ttm_caching_state c_state)
{
int i, j;
struct page *cur_page;
int ret;
if (ttm->caching_state == c_state)
return 0;
if (ttm->state == tt_unpopulated) {
ttm->caching_state = c_state;
return 0;
}
if (ttm->caching_state == tt_cached)
drm_clflush_pages(ttm->pages, ttm->num_pages);
for (i = 0; i < ttm->num_pages; ++i) {
cur_page = ttm->pages[i];
if (likely(cur_page != NULL)) {
ret = ttm_tt_set_page_caching(cur_page,
ttm->caching_state,
c_state);
if (unlikely(ret != 0))
goto out_err;
}
}
ttm->caching_state = c_state;
return 0;
out_err:
for (j = 0; j < i; ++j) {
cur_page = ttm->pages[j];
if (likely(cur_page != NULL)) {
(void)ttm_tt_set_page_caching(cur_page, c_state,
ttm->caching_state);
}
}
return ret;
}
int ttm_tt_set_placement_caching(struct ttm_tt *ttm, uint32_t placement)
{
enum ttm_caching_state state;
if (placement & TTM_PL_FLAG_WC)
state = tt_wc;
else if (placement & TTM_PL_FLAG_UNCACHED)
state = tt_uncached;
else
state = tt_cached;
return ttm_tt_set_caching(ttm, state);
}
void ttm_tt_destroy(struct ttm_tt *ttm)
{
if (unlikely(ttm == NULL))
return;
if (ttm->state == tt_bound) {
ttm_tt_unbind(ttm);
}
if (ttm->state == tt_unbound) {
ttm->bdev->driver->ttm_tt_unpopulate(ttm);
}
if (!(ttm->page_flags & TTM_PAGE_FLAG_PERSISTENT_SWAP) &&
ttm->swap_storage)
fput(ttm->swap_storage);
ttm->swap_storage = NULL;
ttm->func->destroy(ttm);
}
int ttm_tt_init(struct ttm_tt *ttm, struct ttm_bo_device *bdev,
unsigned long size, uint32_t page_flags,
struct page *dummy_read_page)
{
ttm->bdev = bdev;
ttm->glob = bdev->glob;
ttm->num_pages = (size + PAGE_SIZE - 1) >> PAGE_SHIFT;
ttm->caching_state = tt_cached;
ttm->page_flags = page_flags;
ttm->dummy_read_page = dummy_read_page;
ttm->state = tt_unpopulated;
ttm->swap_storage = NULL;
ttm_tt_alloc_page_directory(ttm);
if (!ttm->pages) {
ttm_tt_destroy(ttm);
pr_err("Failed allocating page table\n");
return -ENOMEM;
}
return 0;
}
void ttm_tt_fini(struct ttm_tt *ttm)
{
drm_free_large(ttm->pages);
ttm->pages = NULL;
}
int ttm_dma_tt_init(struct ttm_dma_tt *ttm_dma, struct ttm_bo_device *bdev,
unsigned long size, uint32_t page_flags,
struct page *dummy_read_page)
{
struct ttm_tt *ttm = &ttm_dma->ttm;
ttm->bdev = bdev;
ttm->glob = bdev->glob;
ttm->num_pages = (size + PAGE_SIZE - 1) >> PAGE_SHIFT;
ttm->caching_state = tt_cached;
ttm->page_flags = page_flags;
ttm->dummy_read_page = dummy_read_page;
ttm->state = tt_unpopulated;
ttm->swap_storage = NULL;
INIT_LIST_HEAD(&ttm_dma->pages_list);
ttm_dma_tt_alloc_page_directory(ttm_dma);
if (!ttm->pages || !ttm_dma->dma_address) {
ttm_tt_destroy(ttm);
pr_err("Failed allocating page table\n");
return -ENOMEM;
}
return 0;
}
void ttm_dma_tt_fini(struct ttm_dma_tt *ttm_dma)
{
struct ttm_tt *ttm = &ttm_dma->ttm;
drm_free_large(ttm->pages);
ttm->pages = NULL;
drm_free_large(ttm_dma->dma_address);
ttm_dma->dma_address = NULL;
}
void ttm_tt_unbind(struct ttm_tt *ttm)
{
int ret;
if (ttm->state == tt_bound) {
ret = ttm->func->unbind(ttm);
BUG_ON(ret);
ttm->state = tt_unbound;
}
}
int ttm_tt_bind(struct ttm_tt *ttm, struct ttm_mem_reg *bo_mem)
{
int ret = 0;
if (!ttm)
return -EINVAL;
if (ttm->state == tt_bound)
return 0;
ret = ttm->bdev->driver->ttm_tt_populate(ttm);
if (ret)
return ret;
ret = ttm->func->bind(ttm, bo_mem);
if (unlikely(ret != 0))
return ret;
ttm->state = tt_bound;
return 0;
}
int ttm_tt_swapin(struct ttm_tt *ttm)
{
struct address_space *swap_space;
struct file *swap_storage;
struct page *from_page;
struct page *to_page;
int i;
int ret = -ENOMEM;
swap_storage = ttm->swap_storage;
BUG_ON(swap_storage == NULL);
swap_space = file_inode(swap_storage)->i_mapping;
for (i = 0; i < ttm->num_pages; ++i) {
from_page = shmem_read_mapping_page(swap_space, i);
if (IS_ERR(from_page)) {
ret = PTR_ERR(from_page);
goto out_err;
}
to_page = ttm->pages[i];
if (unlikely(to_page == NULL))
goto out_err;
copy_highpage(to_page, from_page);
page_cache_release(from_page);
}
if (!(ttm->page_flags & TTM_PAGE_FLAG_PERSISTENT_SWAP))
fput(swap_storage);
ttm->swap_storage = NULL;
ttm->page_flags &= ~TTM_PAGE_FLAG_SWAPPED;
return 0;
out_err:
return ret;
}
int ttm_tt_swapout(struct ttm_tt *ttm, struct file *persistent_swap_storage)
{
struct address_space *swap_space;
struct file *swap_storage;
struct page *from_page;
struct page *to_page;
int i;
int ret = -ENOMEM;
BUG_ON(ttm->state != tt_unbound && ttm->state != tt_unpopulated);
BUG_ON(ttm->caching_state != tt_cached);
if (!persistent_swap_storage) {
swap_storage = shmem_file_setup("ttm swap",
ttm->num_pages << PAGE_SHIFT,
0);
if (unlikely(IS_ERR(swap_storage))) {
pr_err("Failed allocating swap storage\n");
return PTR_ERR(swap_storage);
}
} else
swap_storage = persistent_swap_storage;
swap_space = file_inode(swap_storage)->i_mapping;
for (i = 0; i < ttm->num_pages; ++i) {
from_page = ttm->pages[i];
if (unlikely(from_page == NULL))
continue;
to_page = shmem_read_mapping_page(swap_space, i);
if (unlikely(IS_ERR(to_page))) {
ret = PTR_ERR(to_page);
goto out_err;
}
copy_highpage(to_page, from_page);
set_page_dirty(to_page);
mark_page_accessed(to_page);
page_cache_release(to_page);
}
ttm->bdev->driver->ttm_tt_unpopulate(ttm);
ttm->swap_storage = swap_storage;
ttm->page_flags |= TTM_PAGE_FLAG_SWAPPED;
if (persistent_swap_storage)
ttm->page_flags |= TTM_PAGE_FLAG_PERSISTENT_SWAP;
return 0;
out_err:
if (!persistent_swap_storage)
fput(swap_storage);
return ret;
}
