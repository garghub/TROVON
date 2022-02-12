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
if (!PagePrivate(page)) {
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
static inline void __isolate_balloon_page(struct page *page)
{
struct balloon_dev_info *b_dev_info = balloon_page_device(page);
unsigned long flags;
spin_lock_irqsave(&b_dev_info->pages_lock, flags);
ClearPagePrivate(page);
list_del(&page->lru);
b_dev_info->isolated_pages++;
spin_unlock_irqrestore(&b_dev_info->pages_lock, flags);
}
static inline void __putback_balloon_page(struct page *page)
{
struct balloon_dev_info *b_dev_info = balloon_page_device(page);
unsigned long flags;
spin_lock_irqsave(&b_dev_info->pages_lock, flags);
SetPagePrivate(page);
list_add(&page->lru, &b_dev_info->pages);
b_dev_info->isolated_pages--;
spin_unlock_irqrestore(&b_dev_info->pages_lock, flags);
}
bool balloon_page_isolate(struct page *page)
{
if (likely(get_page_unless_zero(page))) {
if (likely(trylock_page(page))) {
if (balloon_page_movable(page)) {
__isolate_balloon_page(page);
unlock_page(page);
return true;
}
unlock_page(page);
}
put_page(page);
}
return false;
}
void balloon_page_putback(struct page *page)
{
lock_page(page);
if (__is_movable_balloon_page(page)) {
__putback_balloon_page(page);
put_page(page);
} else {
WARN_ON(1);
dump_page(page, "not movable balloon page");
}
unlock_page(page);
}
int balloon_page_migrate(struct page *newpage,
struct page *page, enum migrate_mode mode)
{
struct balloon_dev_info *balloon = balloon_page_device(page);
int rc = -EAGAIN;
VM_BUG_ON_PAGE(!PageLocked(page), page);
VM_BUG_ON_PAGE(!PageLocked(newpage), newpage);
if (WARN_ON(!__is_movable_balloon_page(page))) {
dump_page(page, "not movable balloon page");
return rc;
}
if (balloon && balloon->migratepage)
rc = balloon->migratepage(balloon, newpage, page, mode);
return rc;
}
