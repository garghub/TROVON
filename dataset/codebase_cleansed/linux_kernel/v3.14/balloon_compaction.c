struct balloon_dev_info *balloon_devinfo_alloc(void *balloon_dev_descriptor)
{
struct balloon_dev_info *b_dev_info;
b_dev_info = kmalloc(sizeof(*b_dev_info), GFP_KERNEL);
if (!b_dev_info)
return ERR_PTR(-ENOMEM);
b_dev_info->balloon_device = balloon_dev_descriptor;
b_dev_info->mapping = NULL;
b_dev_info->isolated_pages = 0;
spin_lock_init(&b_dev_info->pages_lock);
INIT_LIST_HEAD(&b_dev_info->pages);
return b_dev_info;
}
struct page *balloon_page_enqueue(struct balloon_dev_info *b_dev_info)
{
unsigned long flags;
struct page *page = alloc_page(balloon_mapping_gfp_mask() |
__GFP_NOMEMALLOC | __GFP_NORETRY);
if (!page)
return NULL;
BUG_ON(!trylock_page(page));
spin_lock_irqsave(&b_dev_info->pages_lock, flags);
balloon_page_insert(page, b_dev_info->mapping, &b_dev_info->pages);
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
list_for_each_entry_safe(page, tmp, &b_dev_info->pages, lru) {
if (trylock_page(page)) {
spin_lock_irqsave(&b_dev_info->pages_lock, flags);
get_page(page);
balloon_page_delete(page);
spin_unlock_irqrestore(&b_dev_info->pages_lock, flags);
unlock_page(page);
dequeued_page = true;
break;
}
}
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
struct address_space *balloon_mapping_alloc(struct balloon_dev_info *b_dev_info,
const struct address_space_operations *a_ops)
{
struct address_space *mapping;
mapping = kmalloc(sizeof(*mapping), GFP_KERNEL);
if (!mapping)
return ERR_PTR(-ENOMEM);
address_space_init_once(mapping);
mapping_set_balloon(mapping);
mapping_set_gfp_mask(mapping, balloon_mapping_gfp_mask());
mapping->a_ops = a_ops;
mapping->private_data = b_dev_info;
b_dev_info->mapping = mapping;
return mapping;
}
static inline void __isolate_balloon_page(struct page *page)
{
struct balloon_dev_info *b_dev_info = page->mapping->private_data;
unsigned long flags;
spin_lock_irqsave(&b_dev_info->pages_lock, flags);
list_del(&page->lru);
b_dev_info->isolated_pages++;
spin_unlock_irqrestore(&b_dev_info->pages_lock, flags);
}
static inline void __putback_balloon_page(struct page *page)
{
struct balloon_dev_info *b_dev_info = page->mapping->private_data;
unsigned long flags;
spin_lock_irqsave(&b_dev_info->pages_lock, flags);
list_add(&page->lru, &b_dev_info->pages);
b_dev_info->isolated_pages--;
spin_unlock_irqrestore(&b_dev_info->pages_lock, flags);
}
static inline int __migrate_balloon_page(struct address_space *mapping,
struct page *newpage, struct page *page, enum migrate_mode mode)
{
return page->mapping->a_ops->migratepage(mapping, newpage, page, mode);
}
bool balloon_page_isolate(struct page *page)
{
if (likely(get_page_unless_zero(page))) {
if (likely(trylock_page(page))) {
if (__is_movable_balloon_page(page) &&
page_count(page) == 2) {
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
struct address_space *mapping;
int rc = -EAGAIN;
BUG_ON(!trylock_page(newpage));
if (WARN_ON(!__is_movable_balloon_page(page))) {
dump_page(page, "not movable balloon page");
unlock_page(newpage);
return rc;
}
mapping = page->mapping;
if (mapping)
rc = __migrate_balloon_page(mapping, newpage, page, mode);
unlock_page(newpage);
return rc;
}
