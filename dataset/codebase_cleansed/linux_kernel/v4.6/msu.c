static inline bool msc_block_is_empty(struct msc_block_desc *bdesc)
{
if (!bdesc->valid_dw)
return true;
if (!msc_data_sz(bdesc))
return true;
return false;
}
static struct msc_window *msc_oldest_window(struct msc *msc)
{
struct msc_window *win;
u32 reg = ioread32(msc->reg_base + REG_MSU_MSC0NWSA);
unsigned long win_addr = (unsigned long)reg << PAGE_SHIFT;
unsigned int found = 0;
if (list_empty(&msc->win_list))
return NULL;
list_for_each_entry(win, &msc->win_list, entry) {
if (win->block[0].addr == win_addr)
found++;
if (msc_block_is_empty(win->block[0].bdesc))
continue;
if (found)
return win;
}
return list_entry(msc->win_list.next, struct msc_window, entry);
}
static unsigned int msc_win_oldest_block(struct msc_window *win)
{
unsigned int blk;
struct msc_block_desc *bdesc = win->block[0].bdesc;
if (!msc_block_wrapped(bdesc))
return 0;
for (blk = 0; blk < win->nr_blocks; blk++) {
bdesc = win->block[blk].bdesc;
if (msc_block_last_written(bdesc))
return blk;
}
return 0;
}
static inline bool msc_is_last_win(struct msc_window *win)
{
return win->entry.next == &win->msc->win_list;
}
static struct msc_window *msc_next_window(struct msc_window *win)
{
if (msc_is_last_win(win))
return list_entry(win->msc->win_list.next, struct msc_window,
entry);
return list_entry(win->entry.next, struct msc_window, entry);
}
static struct msc_block_desc *msc_iter_bdesc(struct msc_iter *iter)
{
return iter->win->block[iter->block].bdesc;
}
static void msc_iter_init(struct msc_iter *iter)
{
memset(iter, 0, sizeof(*iter));
iter->start_block = -1;
iter->block = -1;
}
static struct msc_iter *msc_iter_install(struct msc *msc)
{
struct msc_iter *iter;
iter = kzalloc(sizeof(*iter), GFP_KERNEL);
if (!iter)
return NULL;
msc_iter_init(iter);
iter->msc = msc;
mutex_lock(&msc->iter_mutex);
list_add_tail(&iter->entry, &msc->iter_list);
mutex_unlock(&msc->iter_mutex);
return iter;
}
static void msc_iter_remove(struct msc_iter *iter, struct msc *msc)
{
mutex_lock(&msc->iter_mutex);
list_del(&iter->entry);
mutex_unlock(&msc->iter_mutex);
kfree(iter);
}
static void msc_iter_block_start(struct msc_iter *iter)
{
if (iter->start_block != -1)
return;
iter->start_block = msc_win_oldest_block(iter->win);
iter->block = iter->start_block;
iter->wrap_count = 0;
if (msc_block_wrapped(msc_iter_bdesc(iter)))
iter->wrap_count = 2;
}
static int msc_iter_win_start(struct msc_iter *iter, struct msc *msc)
{
if (iter->start_win)
return 0;
iter->start_win = msc_oldest_window(msc);
if (!iter->start_win)
return -EINVAL;
iter->win = iter->start_win;
iter->start_block = -1;
msc_iter_block_start(iter);
return 0;
}
static int msc_iter_win_advance(struct msc_iter *iter)
{
iter->win = msc_next_window(iter->win);
iter->start_block = -1;
if (iter->win == iter->start_win) {
iter->eof++;
return 1;
}
msc_iter_block_start(iter);
return 0;
}
static int msc_iter_block_advance(struct msc_iter *iter)
{
iter->block_off = 0;
if (iter->wrap_count && iter->block == iter->start_block) {
iter->wrap_count--;
if (!iter->wrap_count)
return msc_iter_win_advance(iter);
}
if (!iter->wrap_count && msc_block_last_written(msc_iter_bdesc(iter)))
return msc_iter_win_advance(iter);
if (++iter->block == iter->win->nr_blocks)
iter->block = 0;
if (!iter->wrap_count && iter->block == iter->start_block)
return msc_iter_win_advance(iter);
return 0;
}
static void msc_buffer_clear_hw_header(struct msc *msc)
{
struct msc_window *win;
mutex_lock(&msc->buf_mutex);
list_for_each_entry(win, &msc->win_list, entry) {
unsigned int blk;
size_t hw_sz = sizeof(struct msc_block_desc) -
offsetof(struct msc_block_desc, hw_tag);
for (blk = 0; blk < win->nr_blocks; blk++) {
struct msc_block_desc *bdesc = win->block[blk].bdesc;
memset(&bdesc->hw_tag, 0, hw_sz);
}
}
mutex_unlock(&msc->buf_mutex);
}
static int msc_configure(struct msc *msc)
{
u32 reg;
if (msc->mode > MSC_MODE_MULTI)
return -ENOTSUPP;
if (msc->mode == MSC_MODE_MULTI)
msc_buffer_clear_hw_header(msc);
reg = msc->base_addr >> PAGE_SHIFT;
iowrite32(reg, msc->reg_base + REG_MSU_MSC0BAR);
if (msc->mode == MSC_MODE_SINGLE) {
reg = msc->nr_pages;
iowrite32(reg, msc->reg_base + REG_MSU_MSC0SIZE);
}
reg = ioread32(msc->reg_base + REG_MSU_MSC0CTL);
reg &= ~(MSC_MODE | MSC_WRAPEN | MSC_EN | MSC_RD_HDR_OVRD);
reg |= msc->mode << __ffs(MSC_MODE);
reg |= msc->burst_len << __ffs(MSC_LEN);
if (msc->wrap)
reg |= MSC_WRAPEN;
if (msc->enabled)
reg |= MSC_EN;
iowrite32(reg, msc->reg_base + REG_MSU_MSC0CTL);
if (msc->enabled) {
msc->thdev->output.multiblock = msc->mode == MSC_MODE_MULTI;
intel_th_trace_enable(msc->thdev);
}
return 0;
}
static void msc_disable(struct msc *msc)
{
unsigned long count;
u32 reg;
if (!msc->enabled)
return;
intel_th_trace_disable(msc->thdev);
for (reg = 0, count = MSC_PLE_WAITLOOP_DEPTH;
count && !(reg & MSCSTS_PLE); count--) {
reg = ioread32(msc->reg_base + REG_MSU_MSC0STS);
cpu_relax();
}
if (!count)
dev_dbg(msc_dev(msc), "timeout waiting for MSC0 PLE\n");
if (msc->mode == MSC_MODE_SINGLE) {
msc->single_wrap = !!(reg & MSCSTS_WRAPSTAT);
reg = ioread32(msc->reg_base + REG_MSU_MSC0MWP);
msc->single_sz = reg & ((msc->nr_pages << PAGE_SHIFT) - 1);
dev_dbg(msc_dev(msc), "MSCnMWP: %08x/%08lx, wrap: %d\n",
reg, msc->single_sz, msc->single_wrap);
}
reg = ioread32(msc->reg_base + REG_MSU_MSC0CTL);
reg &= ~MSC_EN;
iowrite32(reg, msc->reg_base + REG_MSU_MSC0CTL);
msc->enabled = 0;
iowrite32(0, msc->reg_base + REG_MSU_MSC0BAR);
iowrite32(0, msc->reg_base + REG_MSU_MSC0SIZE);
dev_dbg(msc_dev(msc), "MSCnNWSA: %08x\n",
ioread32(msc->reg_base + REG_MSU_MSC0NWSA));
reg = ioread32(msc->reg_base + REG_MSU_MSC0STS);
dev_dbg(msc_dev(msc), "MSCnSTS: %08x\n", reg);
}
static int intel_th_msc_activate(struct intel_th_device *thdev)
{
struct msc *msc = dev_get_drvdata(&thdev->dev);
int ret = 0;
if (!atomic_inc_unless_negative(&msc->user_count))
return -ENODEV;
mutex_lock(&msc->iter_mutex);
if (!list_empty(&msc->iter_list))
ret = -EBUSY;
mutex_unlock(&msc->iter_mutex);
if (ret) {
atomic_dec(&msc->user_count);
return ret;
}
msc->enabled = 1;
return msc_configure(msc);
}
static void intel_th_msc_deactivate(struct intel_th_device *thdev)
{
struct msc *msc = dev_get_drvdata(&thdev->dev);
msc_disable(msc);
atomic_dec(&msc->user_count);
}
static int msc_buffer_contig_alloc(struct msc *msc, unsigned long size)
{
unsigned int order = get_order(size);
struct page *page;
if (!size)
return 0;
page = alloc_pages(GFP_KERNEL | __GFP_ZERO, order);
if (!page)
return -ENOMEM;
split_page(page, order);
msc->nr_pages = size >> PAGE_SHIFT;
msc->base = page_address(page);
msc->base_addr = page_to_phys(page);
return 0;
}
static void msc_buffer_contig_free(struct msc *msc)
{
unsigned long off;
for (off = 0; off < msc->nr_pages << PAGE_SHIFT; off += PAGE_SIZE) {
struct page *page = virt_to_page(msc->base + off);
page->mapping = NULL;
__free_page(page);
}
msc->nr_pages = 0;
}
static struct page *msc_buffer_contig_get_page(struct msc *msc,
unsigned long pgoff)
{
if (pgoff >= msc->nr_pages)
return NULL;
return virt_to_page(msc->base + (pgoff << PAGE_SHIFT));
}
static int msc_buffer_win_alloc(struct msc *msc, unsigned int nr_blocks)
{
struct msc_window *win;
unsigned long size = PAGE_SIZE;
int i, ret = -ENOMEM;
if (!nr_blocks)
return 0;
win = kzalloc(offsetof(struct msc_window, block[nr_blocks]),
GFP_KERNEL);
if (!win)
return -ENOMEM;
if (!list_empty(&msc->win_list)) {
struct msc_window *prev = list_entry(msc->win_list.prev,
struct msc_window, entry);
win->pgoff = prev->pgoff + prev->nr_blocks;
}
for (i = 0; i < nr_blocks; i++) {
win->block[i].bdesc = dma_alloc_coherent(msc_dev(msc), size,
&win->block[i].addr,
GFP_KERNEL);
#ifdef CONFIG_X86
set_memory_uc((unsigned long)win->block[i].bdesc, 1);
#endif
if (!win->block[i].bdesc)
goto err_nomem;
}
win->msc = msc;
win->nr_blocks = nr_blocks;
if (list_empty(&msc->win_list)) {
msc->base = win->block[0].bdesc;
msc->base_addr = win->block[0].addr;
}
list_add_tail(&win->entry, &msc->win_list);
msc->nr_pages += nr_blocks;
return 0;
err_nomem:
for (i--; i >= 0; i--) {
#ifdef CONFIG_X86
set_memory_wb((unsigned long)win->block[i].bdesc, 1);
#endif
dma_free_coherent(msc_dev(msc), size, win->block[i].bdesc,
win->block[i].addr);
}
kfree(win);
return ret;
}
static void msc_buffer_win_free(struct msc *msc, struct msc_window *win)
{
int i;
msc->nr_pages -= win->nr_blocks;
list_del(&win->entry);
if (list_empty(&msc->win_list)) {
msc->base = NULL;
msc->base_addr = 0;
}
for (i = 0; i < win->nr_blocks; i++) {
struct page *page = virt_to_page(win->block[i].bdesc);
page->mapping = NULL;
#ifdef CONFIG_X86
set_memory_wb((unsigned long)win->block[i].bdesc, 1);
#endif
dma_free_coherent(msc_dev(win->msc), PAGE_SIZE,
win->block[i].bdesc, win->block[i].addr);
}
kfree(win);
}
static void msc_buffer_relink(struct msc *msc)
{
struct msc_window *win, *next_win;
list_for_each_entry(win, &msc->win_list, entry) {
unsigned int blk;
u32 sw_tag = 0;
if (msc_is_last_win(win)) {
sw_tag |= MSC_SW_TAG_LASTWIN;
next_win = list_entry(msc->win_list.next,
struct msc_window, entry);
} else {
next_win = list_entry(win->entry.next,
struct msc_window, entry);
}
for (blk = 0; blk < win->nr_blocks; blk++) {
struct msc_block_desc *bdesc = win->block[blk].bdesc;
memset(bdesc, 0, sizeof(*bdesc));
bdesc->next_win = next_win->block[0].addr >> PAGE_SHIFT;
if (blk == win->nr_blocks - 1) {
sw_tag |= MSC_SW_TAG_LASTBLK;
bdesc->next_blk =
win->block[0].addr >> PAGE_SHIFT;
} else {
bdesc->next_blk =
win->block[blk + 1].addr >> PAGE_SHIFT;
}
bdesc->sw_tag = sw_tag;
bdesc->block_sz = PAGE_SIZE / 64;
}
}
wmb();
}
static void msc_buffer_multi_free(struct msc *msc)
{
struct msc_window *win, *iter;
list_for_each_entry_safe(win, iter, &msc->win_list, entry)
msc_buffer_win_free(msc, win);
}
static int msc_buffer_multi_alloc(struct msc *msc, unsigned long *nr_pages,
unsigned int nr_wins)
{
int ret, i;
for (i = 0; i < nr_wins; i++) {
ret = msc_buffer_win_alloc(msc, nr_pages[i]);
if (ret) {
msc_buffer_multi_free(msc);
return ret;
}
}
msc_buffer_relink(msc);
return 0;
}
static void msc_buffer_free(struct msc *msc)
{
if (msc->mode == MSC_MODE_SINGLE)
msc_buffer_contig_free(msc);
else if (msc->mode == MSC_MODE_MULTI)
msc_buffer_multi_free(msc);
}
static int msc_buffer_alloc(struct msc *msc, unsigned long *nr_pages,
unsigned int nr_wins)
{
int ret;
if (atomic_read(&msc->user_count) != -1)
return -EBUSY;
if (msc->mode == MSC_MODE_SINGLE) {
if (nr_wins != 1)
return -EINVAL;
ret = msc_buffer_contig_alloc(msc, nr_pages[0] << PAGE_SHIFT);
} else if (msc->mode == MSC_MODE_MULTI) {
ret = msc_buffer_multi_alloc(msc, nr_pages, nr_wins);
} else {
ret = -ENOTSUPP;
}
if (!ret) {
smp_mb__before_atomic();
if (WARN_ON_ONCE(atomic_cmpxchg(&msc->user_count, -1, 0) != -1))
return -EINVAL;
}
return ret;
}
static int msc_buffer_unlocked_free_unless_used(struct msc *msc)
{
int count, ret = 0;
count = atomic_cmpxchg(&msc->user_count, 0, -1);
if (count > 0)
ret = -EBUSY;
else if (!count)
msc_buffer_free(msc);
return ret;
}
static int msc_buffer_free_unless_used(struct msc *msc)
{
int ret;
mutex_lock(&msc->buf_mutex);
ret = msc_buffer_unlocked_free_unless_used(msc);
mutex_unlock(&msc->buf_mutex);
return ret;
}
static struct page *msc_buffer_get_page(struct msc *msc, unsigned long pgoff)
{
struct msc_window *win;
if (msc->mode == MSC_MODE_SINGLE)
return msc_buffer_contig_get_page(msc, pgoff);
list_for_each_entry(win, &msc->win_list, entry)
if (pgoff >= win->pgoff && pgoff < win->pgoff + win->nr_blocks)
goto found;
return NULL;
found:
pgoff -= win->pgoff;
return virt_to_page(win->block[pgoff].bdesc);
}
static unsigned long msc_win_to_user(void *data, void *src, size_t len)
{
struct msc_win_to_user_struct *u = data;
unsigned long ret;
ret = copy_to_user(u->buf + u->offset, src, len);
u->offset += len - ret;
return ret;
}
static int intel_th_msc_open(struct inode *inode, struct file *file)
{
struct intel_th_device *thdev = file->private_data;
struct msc *msc = dev_get_drvdata(&thdev->dev);
struct msc_iter *iter;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
iter = msc_iter_install(msc);
if (!iter)
return -ENOMEM;
file->private_data = iter;
return nonseekable_open(inode, file);
}
static int intel_th_msc_release(struct inode *inode, struct file *file)
{
struct msc_iter *iter = file->private_data;
struct msc *msc = iter->msc;
msc_iter_remove(iter, msc);
return 0;
}
static ssize_t
msc_single_to_user(struct msc *msc, char __user *buf, loff_t off, size_t len)
{
unsigned long size = msc->nr_pages << PAGE_SHIFT, rem = len;
unsigned long start = off, tocopy = 0;
if (msc->single_wrap) {
start += msc->single_sz;
if (start < size) {
tocopy = min(rem, size - start);
if (copy_to_user(buf, msc->base + start, tocopy))
return -EFAULT;
buf += tocopy;
rem -= tocopy;
start += tocopy;
}
start &= size - 1;
if (rem) {
tocopy = min(rem, msc->single_sz - start);
if (copy_to_user(buf, msc->base + start, tocopy))
return -EFAULT;
rem -= tocopy;
}
return len - rem;
}
if (copy_to_user(buf, msc->base + start, rem))
return -EFAULT;
return len;
}
static ssize_t intel_th_msc_read(struct file *file, char __user *buf,
size_t len, loff_t *ppos)
{
struct msc_iter *iter = file->private_data;
struct msc *msc = iter->msc;
size_t size;
loff_t off = *ppos;
ssize_t ret = 0;
if (!atomic_inc_unless_negative(&msc->user_count))
return 0;
if (msc->enabled) {
ret = -EBUSY;
goto put_count;
}
if (msc->mode == MSC_MODE_SINGLE && !msc->single_wrap)
size = msc->single_sz;
else
size = msc->nr_pages << PAGE_SHIFT;
if (!size)
goto put_count;
if (off >= size)
goto put_count;
if (off + len >= size)
len = size - off;
if (msc->mode == MSC_MODE_SINGLE) {
ret = msc_single_to_user(msc, buf, off, len);
if (ret >= 0)
*ppos += ret;
} else if (msc->mode == MSC_MODE_MULTI) {
struct msc_win_to_user_struct u = {
.buf = buf,
.offset = 0,
};
ret = msc_buffer_iterate(iter, len, &u, msc_win_to_user);
if (ret >= 0)
*ppos = iter->offset;
} else {
ret = -ENOTSUPP;
}
put_count:
atomic_dec(&msc->user_count);
return ret;
}
static void msc_mmap_open(struct vm_area_struct *vma)
{
struct msc_iter *iter = vma->vm_file->private_data;
struct msc *msc = iter->msc;
atomic_inc(&msc->mmap_count);
}
static void msc_mmap_close(struct vm_area_struct *vma)
{
struct msc_iter *iter = vma->vm_file->private_data;
struct msc *msc = iter->msc;
unsigned long pg;
if (!atomic_dec_and_mutex_lock(&msc->mmap_count, &msc->buf_mutex))
return;
for (pg = 0; pg < msc->nr_pages; pg++) {
struct page *page = msc_buffer_get_page(msc, pg);
if (WARN_ON_ONCE(!page))
continue;
if (page->mapping)
page->mapping = NULL;
}
atomic_dec(&msc->user_count);
mutex_unlock(&msc->buf_mutex);
}
static int msc_mmap_fault(struct vm_area_struct *vma, struct vm_fault *vmf)
{
struct msc_iter *iter = vma->vm_file->private_data;
struct msc *msc = iter->msc;
vmf->page = msc_buffer_get_page(msc, vmf->pgoff);
if (!vmf->page)
return VM_FAULT_SIGBUS;
get_page(vmf->page);
vmf->page->mapping = vma->vm_file->f_mapping;
vmf->page->index = vmf->pgoff;
return 0;
}
static int intel_th_msc_mmap(struct file *file, struct vm_area_struct *vma)
{
unsigned long size = vma->vm_end - vma->vm_start;
struct msc_iter *iter = vma->vm_file->private_data;
struct msc *msc = iter->msc;
int ret = -EINVAL;
if (!size || offset_in_page(size))
return -EINVAL;
if (vma->vm_pgoff)
return -EINVAL;
if (!atomic_inc_unless_negative(&msc->user_count))
return -EINVAL;
if (msc->mode != MSC_MODE_SINGLE &&
msc->mode != MSC_MODE_MULTI)
goto out;
if (size >> PAGE_SHIFT != msc->nr_pages)
goto out;
atomic_set(&msc->mmap_count, 1);
ret = 0;
out:
if (ret)
atomic_dec(&msc->user_count);
vma->vm_page_prot = pgprot_noncached(vma->vm_page_prot);
vma->vm_flags |= VM_DONTEXPAND | VM_DONTCOPY;
vma->vm_ops = &msc_mmap_ops;
return ret;
}
static int intel_th_msc_init(struct msc *msc)
{
atomic_set(&msc->user_count, -1);
msc->mode = MSC_MODE_MULTI;
mutex_init(&msc->buf_mutex);
INIT_LIST_HEAD(&msc->win_list);
mutex_init(&msc->iter_mutex);
INIT_LIST_HEAD(&msc->iter_list);
msc->burst_len =
(ioread32(msc->reg_base + REG_MSU_MSC0CTL) & MSC_LEN) >>
__ffs(MSC_LEN);
return 0;
}
static ssize_t
wrap_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct msc *msc = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%d\n", msc->wrap);
}
static ssize_t
wrap_store(struct device *dev, struct device_attribute *attr, const char *buf,
size_t size)
{
struct msc *msc = dev_get_drvdata(dev);
unsigned long val;
int ret;
ret = kstrtoul(buf, 10, &val);
if (ret)
return ret;
msc->wrap = !!val;
return size;
}
static ssize_t
mode_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct msc *msc = dev_get_drvdata(dev);
return scnprintf(buf, PAGE_SIZE, "%s\n", msc_mode[msc->mode]);
}
static ssize_t
mode_store(struct device *dev, struct device_attribute *attr, const char *buf,
size_t size)
{
struct msc *msc = dev_get_drvdata(dev);
size_t len = size;
char *cp;
int i, ret;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
cp = memchr(buf, '\n', len);
if (cp)
len = cp - buf;
for (i = 0; i < ARRAY_SIZE(msc_mode); i++)
if (!strncmp(msc_mode[i], buf, len))
goto found;
return -EINVAL;
found:
mutex_lock(&msc->buf_mutex);
ret = msc_buffer_unlocked_free_unless_used(msc);
if (!ret)
msc->mode = i;
mutex_unlock(&msc->buf_mutex);
return ret ? ret : size;
}
static ssize_t
nr_pages_show(struct device *dev, struct device_attribute *attr, char *buf)
{
struct msc *msc = dev_get_drvdata(dev);
struct msc_window *win;
size_t count = 0;
mutex_lock(&msc->buf_mutex);
if (msc->mode == MSC_MODE_SINGLE)
count = scnprintf(buf, PAGE_SIZE, "%ld\n", msc->nr_pages);
else if (msc->mode == MSC_MODE_MULTI) {
list_for_each_entry(win, &msc->win_list, entry) {
count += scnprintf(buf + count, PAGE_SIZE - count,
"%d%c", win->nr_blocks,
msc_is_last_win(win) ? '\n' : ',');
}
} else {
count = scnprintf(buf, PAGE_SIZE, "unsupported\n");
}
mutex_unlock(&msc->buf_mutex);
return count;
}
static ssize_t
nr_pages_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t size)
{
struct msc *msc = dev_get_drvdata(dev);
unsigned long val, *win = NULL, *rewin;
size_t len = size;
const char *p = buf;
char *end, *s;
int ret, nr_wins = 0;
if (!capable(CAP_SYS_RAWIO))
return -EPERM;
ret = msc_buffer_free_unless_used(msc);
if (ret)
return ret;
end = memchr(buf, '\n', len);
if (end)
len = end - buf;
do {
end = memchr(p, ',', len);
s = kstrndup(p, end ? end - p : len, GFP_KERNEL);
ret = kstrtoul(s, 10, &val);
kfree(s);
if (ret || !val)
goto free_win;
if (nr_wins && msc->mode == MSC_MODE_SINGLE) {
ret = -EINVAL;
goto free_win;
}
nr_wins++;
rewin = krealloc(win, sizeof(*win) * nr_wins, GFP_KERNEL);
if (!rewin) {
kfree(win);
return -ENOMEM;
}
win = rewin;
win[nr_wins - 1] = val;
if (!end)
break;
len -= end - p;
p = end + 1;
} while (len);
mutex_lock(&msc->buf_mutex);
ret = msc_buffer_alloc(msc, win, nr_wins);
mutex_unlock(&msc->buf_mutex);
free_win:
kfree(win);
return ret ? ret : size;
}
static int intel_th_msc_probe(struct intel_th_device *thdev)
{
struct device *dev = &thdev->dev;
struct resource *res;
struct msc *msc;
void __iomem *base;
int err;
res = intel_th_device_get_resource(thdev, IORESOURCE_MEM, 0);
if (!res)
return -ENODEV;
base = devm_ioremap(dev, res->start, resource_size(res));
if (!base)
return -ENOMEM;
msc = devm_kzalloc(dev, sizeof(*msc), GFP_KERNEL);
if (!msc)
return -ENOMEM;
msc->index = thdev->id;
msc->thdev = thdev;
msc->reg_base = base + msc->index * 0x100;
err = intel_th_msc_init(msc);
if (err)
return err;
err = sysfs_create_group(&dev->kobj, &msc_output_group);
if (err)
return err;
dev_set_drvdata(dev, msc);
return 0;
}
static void intel_th_msc_remove(struct intel_th_device *thdev)
{
sysfs_remove_group(&thdev->dev.kobj, &msc_output_group);
}
