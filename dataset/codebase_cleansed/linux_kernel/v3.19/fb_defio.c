static struct page *fb_deferred_io_page(struct fb_info *info, unsigned long offs)
{
void *screen_base = (void __force *) info->screen_base;
struct page *page;
if (is_vmalloc_addr(screen_base + offs))
page = vmalloc_to_page(screen_base + offs);
else
page = pfn_to_page((info->fix.smem_start + offs) >> PAGE_SHIFT);
return page;
}
static int fb_deferred_io_fault(struct vm_area_struct *vma,
struct vm_fault *vmf)
{
unsigned long offset;
struct page *page;
struct fb_info *info = vma->vm_private_data;
offset = vmf->pgoff << PAGE_SHIFT;
if (offset >= info->fix.smem_len)
return VM_FAULT_SIGBUS;
page = fb_deferred_io_page(info, offset);
if (!page)
return VM_FAULT_SIGBUS;
get_page(page);
if (vma->vm_file)
page->mapping = vma->vm_file->f_mapping;
else
printk(KERN_ERR "no mapping available\n");
BUG_ON(!page->mapping);
page->index = vmf->pgoff;
vmf->page = page;
return 0;
}
int fb_deferred_io_fsync(struct file *file, loff_t start, loff_t end, int datasync)
{
struct fb_info *info = file->private_data;
struct inode *inode = file_inode(file);
int err = filemap_write_and_wait_range(inode->i_mapping, start, end);
if (err)
return err;
if (!info->fbdefio)
return 0;
mutex_lock(&inode->i_mutex);
cancel_delayed_work_sync(&info->deferred_work);
schedule_delayed_work(&info->deferred_work, 0);
mutex_unlock(&inode->i_mutex);
return 0;
}
static int fb_deferred_io_mkwrite(struct vm_area_struct *vma,
struct vm_fault *vmf)
{
struct page *page = vmf->page;
struct fb_info *info = vma->vm_private_data;
struct fb_deferred_io *fbdefio = info->fbdefio;
struct page *cur;
file_update_time(vma->vm_file);
mutex_lock(&fbdefio->lock);
if (fbdefio->first_io && list_empty(&fbdefio->pagelist))
fbdefio->first_io(info);
lock_page(page);
list_for_each_entry(cur, &fbdefio->pagelist, lru) {
if (unlikely(cur == page))
goto page_already_added;
else if (cur->index > page->index)
break;
}
list_add_tail(&page->lru, &cur->lru);
page_already_added:
mutex_unlock(&fbdefio->lock);
schedule_delayed_work(&info->deferred_work, fbdefio->delay);
return VM_FAULT_LOCKED;
}
static int fb_deferred_io_set_page_dirty(struct page *page)
{
if (!PageDirty(page))
SetPageDirty(page);
return 0;
}
static int fb_deferred_io_mmap(struct fb_info *info, struct vm_area_struct *vma)
{
vma->vm_ops = &fb_deferred_io_vm_ops;
vma->vm_flags |= VM_DONTEXPAND | VM_DONTDUMP;
if (!(info->flags & FBINFO_VIRTFB))
vma->vm_flags |= VM_IO;
vma->vm_private_data = info;
return 0;
}
static void fb_deferred_io_work(struct work_struct *work)
{
struct fb_info *info = container_of(work, struct fb_info,
deferred_work.work);
struct list_head *node, *next;
struct page *cur;
struct fb_deferred_io *fbdefio = info->fbdefio;
mutex_lock(&fbdefio->lock);
list_for_each_entry(cur, &fbdefio->pagelist, lru) {
lock_page(cur);
page_mkclean(cur);
unlock_page(cur);
}
fbdefio->deferred_io(info, &fbdefio->pagelist);
list_for_each_safe(node, next, &fbdefio->pagelist) {
list_del(node);
}
mutex_unlock(&fbdefio->lock);
}
void fb_deferred_io_init(struct fb_info *info)
{
struct fb_deferred_io *fbdefio = info->fbdefio;
BUG_ON(!fbdefio);
mutex_init(&fbdefio->lock);
info->fbops->fb_mmap = fb_deferred_io_mmap;
INIT_DELAYED_WORK(&info->deferred_work, fb_deferred_io_work);
INIT_LIST_HEAD(&fbdefio->pagelist);
if (fbdefio->delay == 0)
fbdefio->delay = HZ;
}
void fb_deferred_io_open(struct fb_info *info,
struct inode *inode,
struct file *file)
{
file->f_mapping->a_ops = &fb_deferred_io_aops;
}
void fb_deferred_io_cleanup(struct fb_info *info)
{
struct fb_deferred_io *fbdefio = info->fbdefio;
struct page *page;
int i;
BUG_ON(!fbdefio);
cancel_delayed_work_sync(&info->deferred_work);
for (i = 0 ; i < info->fix.smem_len; i += PAGE_SIZE) {
page = fb_deferred_io_page(info, i);
page->mapping = NULL;
}
info->fbops->fb_mmap = NULL;
mutex_destroy(&fbdefio->lock);
}
