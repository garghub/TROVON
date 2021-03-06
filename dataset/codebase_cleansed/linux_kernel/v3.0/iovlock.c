static int num_pages_spanned(struct iovec *iov)
{
return
((PAGE_ALIGN((unsigned long)iov->iov_base + iov->iov_len) -
((unsigned long)iov->iov_base & PAGE_MASK)) >> PAGE_SHIFT);
}
struct dma_pinned_list *dma_pin_iovec_pages(struct iovec *iov, size_t len)
{
struct dma_pinned_list *local_list;
struct page **pages;
int i;
int ret;
int nr_iovecs = 0;
int iovec_len_used = 0;
int iovec_pages_used = 0;
if (segment_eq(get_fs(), KERNEL_DS))
return NULL;
do {
iovec_len_used += iov[nr_iovecs].iov_len;
iovec_pages_used += num_pages_spanned(&iov[nr_iovecs]);
nr_iovecs++;
} while (iovec_len_used < len);
local_list = kmalloc(sizeof(*local_list)
+ (nr_iovecs * sizeof (struct dma_page_list))
+ (iovec_pages_used * sizeof (struct page*)), GFP_KERNEL);
if (!local_list)
goto out;
pages = (struct page **) &local_list->page_list[nr_iovecs];
local_list->nr_iovecs = 0;
for (i = 0; i < nr_iovecs; i++) {
struct dma_page_list *page_list = &local_list->page_list[i];
len -= iov[i].iov_len;
if (!access_ok(VERIFY_WRITE, iov[i].iov_base, iov[i].iov_len))
goto unpin;
page_list->nr_pages = num_pages_spanned(&iov[i]);
page_list->base_address = iov[i].iov_base;
page_list->pages = pages;
pages += page_list->nr_pages;
down_read(&current->mm->mmap_sem);
ret = get_user_pages(
current,
current->mm,
(unsigned long) iov[i].iov_base,
page_list->nr_pages,
1,
0,
page_list->pages,
NULL);
up_read(&current->mm->mmap_sem);
if (ret != page_list->nr_pages)
goto unpin;
local_list->nr_iovecs = i + 1;
}
return local_list;
unpin:
dma_unpin_iovec_pages(local_list);
out:
return NULL;
}
void dma_unpin_iovec_pages(struct dma_pinned_list *pinned_list)
{
int i, j;
if (!pinned_list)
return;
for (i = 0; i < pinned_list->nr_iovecs; i++) {
struct dma_page_list *page_list = &pinned_list->page_list[i];
for (j = 0; j < page_list->nr_pages; j++) {
set_page_dirty_lock(page_list->pages[j]);
page_cache_release(page_list->pages[j]);
}
}
kfree(pinned_list);
}
dma_cookie_t dma_memcpy_to_iovec(struct dma_chan *chan, struct iovec *iov,
struct dma_pinned_list *pinned_list, unsigned char *kdata, size_t len)
{
int iov_byte_offset;
int copy;
dma_cookie_t dma_cookie = 0;
int iovec_idx;
int page_idx;
if (!chan)
return memcpy_toiovec(iov, kdata, len);
iovec_idx = 0;
while (iovec_idx < pinned_list->nr_iovecs) {
struct dma_page_list *page_list;
while (!iov[iovec_idx].iov_len)
iovec_idx++;
page_list = &pinned_list->page_list[iovec_idx];
iov_byte_offset = ((unsigned long)iov[iovec_idx].iov_base & ~PAGE_MASK);
page_idx = (((unsigned long)iov[iovec_idx].iov_base & PAGE_MASK)
- ((unsigned long)page_list->base_address & PAGE_MASK)) >> PAGE_SHIFT;
while (iov[iovec_idx].iov_len) {
copy = min_t(int, PAGE_SIZE - iov_byte_offset, len);
copy = min_t(int, copy, iov[iovec_idx].iov_len);
dma_cookie = dma_async_memcpy_buf_to_pg(chan,
page_list->pages[page_idx],
iov_byte_offset,
kdata,
copy);
if (unlikely(dma_cookie < 0)) {
dma_async_issue_pending(chan);
continue;
}
len -= copy;
iov[iovec_idx].iov_len -= copy;
iov[iovec_idx].iov_base += copy;
if (!len)
return dma_cookie;
kdata += copy;
iov_byte_offset = 0;
page_idx++;
}
iovec_idx++;
}
BUG();
return -EFAULT;
}
dma_cookie_t dma_memcpy_pg_to_iovec(struct dma_chan *chan, struct iovec *iov,
struct dma_pinned_list *pinned_list, struct page *page,
unsigned int offset, size_t len)
{
int iov_byte_offset;
int copy;
dma_cookie_t dma_cookie = 0;
int iovec_idx;
int page_idx;
int err;
if (!chan || !pinned_list) {
u8 *vaddr = kmap(page);
err = memcpy_toiovec(iov, vaddr + offset, len);
kunmap(page);
return err;
}
iovec_idx = 0;
while (iovec_idx < pinned_list->nr_iovecs) {
struct dma_page_list *page_list;
while (!iov[iovec_idx].iov_len)
iovec_idx++;
page_list = &pinned_list->page_list[iovec_idx];
iov_byte_offset = ((unsigned long)iov[iovec_idx].iov_base & ~PAGE_MASK);
page_idx = (((unsigned long)iov[iovec_idx].iov_base & PAGE_MASK)
- ((unsigned long)page_list->base_address & PAGE_MASK)) >> PAGE_SHIFT;
while (iov[iovec_idx].iov_len) {
copy = min_t(int, PAGE_SIZE - iov_byte_offset, len);
copy = min_t(int, copy, iov[iovec_idx].iov_len);
dma_cookie = dma_async_memcpy_pg_to_pg(chan,
page_list->pages[page_idx],
iov_byte_offset,
page,
offset,
copy);
if (unlikely(dma_cookie < 0)) {
dma_async_issue_pending(chan);
continue;
}
len -= copy;
iov[iovec_idx].iov_len -= copy;
iov[iovec_idx].iov_base += copy;
if (!len)
return dma_cookie;
offset += copy;
iov_byte_offset = 0;
page_idx++;
}
iovec_idx++;
}
BUG();
return -EFAULT;
}
