size_t copy_page_to_iter(struct page *page, size_t offset, size_t bytes,
struct iov_iter *i)
{
size_t skip, copy, left, wanted;
const struct iovec *iov;
char __user *buf;
void *kaddr, *from;
if (unlikely(bytes > i->count))
bytes = i->count;
if (unlikely(!bytes))
return 0;
wanted = bytes;
iov = i->iov;
skip = i->iov_offset;
buf = iov->iov_base + skip;
copy = min(bytes, iov->iov_len - skip);
if (!fault_in_pages_writeable(buf, copy)) {
kaddr = kmap_atomic(page);
from = kaddr + offset;
left = __copy_to_user_inatomic(buf, from, copy);
copy -= left;
skip += copy;
from += copy;
bytes -= copy;
while (unlikely(!left && bytes)) {
iov++;
buf = iov->iov_base;
copy = min(bytes, iov->iov_len);
left = __copy_to_user_inatomic(buf, from, copy);
copy -= left;
skip = copy;
from += copy;
bytes -= copy;
}
if (likely(!bytes)) {
kunmap_atomic(kaddr);
goto done;
}
offset = from - kaddr;
buf += copy;
kunmap_atomic(kaddr);
copy = min(bytes, iov->iov_len - skip);
}
kaddr = kmap(page);
from = kaddr + offset;
left = __copy_to_user(buf, from, copy);
copy -= left;
skip += copy;
from += copy;
bytes -= copy;
while (unlikely(!left && bytes)) {
iov++;
buf = iov->iov_base;
copy = min(bytes, iov->iov_len);
left = __copy_to_user(buf, from, copy);
copy -= left;
skip = copy;
from += copy;
bytes -= copy;
}
kunmap(page);
done:
i->count -= wanted - bytes;
i->nr_segs -= iov - i->iov;
i->iov = iov;
i->iov_offset = skip;
return wanted - bytes;
}
static size_t __iovec_copy_from_user_inatomic(char *vaddr,
const struct iovec *iov, size_t base, size_t bytes)
{
size_t copied = 0, left = 0;
while (bytes) {
char __user *buf = iov->iov_base + base;
int copy = min(bytes, iov->iov_len - base);
base = 0;
left = __copy_from_user_inatomic(vaddr, buf, copy);
copied += copy;
bytes -= copy;
vaddr += copy;
iov++;
if (unlikely(left))
break;
}
return copied - left;
}
size_t iov_iter_copy_from_user_atomic(struct page *page,
struct iov_iter *i, unsigned long offset, size_t bytes)
{
char *kaddr;
size_t copied;
kaddr = kmap_atomic(page);
if (likely(i->nr_segs == 1)) {
int left;
char __user *buf = i->iov->iov_base + i->iov_offset;
left = __copy_from_user_inatomic(kaddr + offset, buf, bytes);
copied = bytes - left;
} else {
copied = __iovec_copy_from_user_inatomic(kaddr + offset,
i->iov, i->iov_offset, bytes);
}
kunmap_atomic(kaddr);
return copied;
}
size_t iov_iter_copy_from_user(struct page *page,
struct iov_iter *i, unsigned long offset, size_t bytes)
{
char *kaddr;
size_t copied;
kaddr = kmap(page);
if (likely(i->nr_segs == 1)) {
int left;
char __user *buf = i->iov->iov_base + i->iov_offset;
left = __copy_from_user(kaddr + offset, buf, bytes);
copied = bytes - left;
} else {
copied = __iovec_copy_from_user_inatomic(kaddr + offset,
i->iov, i->iov_offset, bytes);
}
kunmap(page);
return copied;
}
void iov_iter_advance(struct iov_iter *i, size_t bytes)
{
BUG_ON(i->count < bytes);
if (likely(i->nr_segs == 1)) {
i->iov_offset += bytes;
i->count -= bytes;
} else {
const struct iovec *iov = i->iov;
size_t base = i->iov_offset;
unsigned long nr_segs = i->nr_segs;
while (bytes || unlikely(i->count && !iov->iov_len)) {
int copy;
copy = min(bytes, iov->iov_len - base);
BUG_ON(!i->count || i->count < copy);
i->count -= copy;
bytes -= copy;
base += copy;
if (iov->iov_len == base) {
iov++;
nr_segs--;
base = 0;
}
}
i->iov = iov;
i->iov_offset = base;
i->nr_segs = nr_segs;
}
}
int iov_iter_fault_in_readable(struct iov_iter *i, size_t bytes)
{
char __user *buf = i->iov->iov_base + i->iov_offset;
bytes = min(bytes, i->iov->iov_len - i->iov_offset);
return fault_in_pages_readable(buf, bytes);
}
size_t iov_iter_single_seg_count(const struct iov_iter *i)
{
const struct iovec *iov = i->iov;
if (i->nr_segs == 1)
return i->count;
else
return min(i->count, iov->iov_len - i->iov_offset);
}
