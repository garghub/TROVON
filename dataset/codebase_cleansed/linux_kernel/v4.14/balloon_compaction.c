struct page *balloon_page_enqueue(struct balloon_dev_info *b_dev_info)
{
unsigned long flags;
struct page *page = alloc_page(balloon_mapping_gfp_mask() |
__GFP_NOMEMALLOC | __GFP_NORETRY);
if (!page)
return NULL;
BUG_ON(!trylock_page(page));
spin_lock_irqsave(&b_dev_info->pages_lock, flags);
balloon_page_insert(b_dev_info, page);
__count_vm_event(BALLOON_INFLATE);
spin_unlock_irqrestore(&b_dev_info->pages_lock, flags);
unlock_page(page);
return page;
}
struct page *balloon_page_dequeue(struct balloon_dev_info *b_dev_info)
{
struct page *page, *tmp;
unsigned long flags;
bool dequeued_page;
dequeued_page = false;
spin_lock_irqsave(&b_dev_info->pages_lock, flags);
list_for_each_entry_safe(page, tmp, &b_dev_info->pages, lru) {
if (trylock_page(page)) {
#ifdef CONFIG_BALLOON_COMPACTION
if (PageIsolated(page)) {
unlock_page(page);
continue;
}
#endif
balloon_page_delete(page);
__count_vm_event(BALLOON_DEFLATE);
unlock_page(page);
dequeued_page = true;
break;
}
}
spin_unlock_irqrestore(&b_dev_info->pages_lock, flags);
if (!dequeued_page) {
spin_lock_irqsave(&b_dev_info->pages_lock, flags);
if (unlikely(list_empty(&b_dev_info->pages) &&
!b_dev_info->isolated_pages))
BUG();
spin_unlock_irqrestore(&b_dev_info->pages_lock, flags);
page = NULL;
}
return page;
}
bool balloon_page_isolate(struct page *page, isolate_mode_t mode)
{
struct balloon_dev_info *b_dev_info = balloon_page_device(page);
unsigned long flags;
spin_lock_irqsave(&b_dev_info->pages_lock, flags);
list_del(&page->lru);
b_dev_info->isolated_pages++;
spin_unlock_irqrestore(&b_dev_info->pages_lock, flags);
return true;
}
void balloon_page_putback(struct page *page)
{
struct balloon_dev_info *b_dev_info = balloon_page_device(page);
unsigned long flags;
spin_lock_irqsave(&b_dev_info->pages_lock, flags);
list_add(&page->lru, &b_dev_info->pages);
b_dev_info->isolated_pages--;
spin_unlock_irqrestore(&b_dev_info->pages_lock, flags);
}
int balloon_page_migrate(struct address_space *mapping,
struct page *newpage, struct page *page,
enum migrate_mode mode)
{
struct balloon_dev_info *balloon = balloon_page_device(page);
if (mode == MIGRATE_SYNC_NO_COPY)
return -EINVAL;
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_PAGE(!PageLocked(newpage), newpage);
return balloon->migratepage(balloon, newpage, page, mode);
}
