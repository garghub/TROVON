static size_t copy_page_to_iter_iovec(struct page *page, size_t offset, size_t bytes,
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
if (skip == iov->iov_len) {
iov++;
skip = 0;
}
i->count -= wanted - bytes;
i->nr_segs -= iov - i->iov;
i->iov = iov;
i->iov_offset = skip;
return wanted - bytes;
}
static size_t copy_page_from_iter_iovec(struct page *page, size_t offset, size_t bytes,
struct iov_iter *i)
{
size_t skip, copy, left, wanted;
const struct iovec *iov;
char __user *buf;
void *kaddr, *to;
if (unlikely(bytes > i->count))
bytes = i->count;
if (unlikely(!bytes))
return 0;
wanted = bytes;
iov = i->iov;
skip = i->iov_offset;
buf = iov->iov_base + skip;
copy = min(bytes, iov->iov_len - skip);
if (!fault_in_pages_readable(buf, copy)) {
kaddr = kmap_atomic(page);
to = kaddr + offset;
left = __copy_from_user_inatomic(to, buf, copy);
copy -= left;
skip += copy;
to += copy;
bytes -= copy;
while (unlikely(!left && bytes)) {
iov++;
buf = iov->iov_base;
copy = min(bytes, iov->iov_len);
left = __copy_from_user_inatomic(to, buf, copy);
copy -= left;
skip = copy;
to += copy;
bytes -= copy;
}
if (likely(!bytes)) {
kunmap_atomic(kaddr);
goto done;
}
offset = to - kaddr;
buf += copy;
kunmap_atomic(kaddr);
copy = min(bytes, iov->iov_len - skip);
}
kaddr = kmap(page);
to = kaddr + offset;
left = __copy_from_user(to, buf, copy);
copy -= left;
skip += copy;
to += copy;
bytes -= copy;
while (unlikely(!left && bytes)) {
iov++;
buf = iov->iov_base;
copy = min(bytes, iov->iov_len);
left = __copy_from_user(to, buf, copy);
copy -= left;
skip = copy;
to += copy;
bytes -= copy;
}
kunmap(page);
done:
if (skip == iov->iov_len) {
iov++;
skip = 0;
}
i->count -= wanted - bytes;
i->nr_segs -= iov - i->iov;
i->iov = iov;
i->iov_offset = skip;
return wanted - bytes;
}
int iov_iter_fault_in_readable(struct iov_iter *i, size_t bytes)
{
if (!(i->type & (ITER_BVEC|ITER_KVEC))) {
char __user *buf = i->iov->iov_base + i->iov_offset;
bytes = min(bytes, i->iov->iov_len - i->iov_offset);
return fault_in_pages_readable(buf, bytes);
}
return 0;
}
int iov_iter_fault_in_multipages_readable(struct iov_iter *i, size_t bytes)
{
size_t skip = i->iov_offset;
const struct iovec *iov;
int err;
struct iovec v;
if (!(i->type & (ITER_BVEC|ITER_KVEC))) {
iterate_iovec(i, bytes, v, iov, skip, ({
err = fault_in_multipages_readable(v.iov_base,
v.iov_len);
if (unlikely(err))
return err;
0;}))
}
return 0;
}
void iov_iter_init(struct iov_iter *i, int direction,
const struct iovec *iov, unsigned long nr_segs,
size_t count)
{
if (segment_eq(get_fs(), KERNEL_DS)) {
direction |= ITER_KVEC;
i->type = direction;
i->kvec = (struct kvec *)iov;
} else {
i->type = direction;
i->iov = iov;
}
i->nr_segs = nr_segs;
i->iov_offset = 0;
i->count = count;
}
static void memcpy_from_page(char *to, struct page *page, size_t offset, size_t len)
{
char *from = kmap_atomic(page);
memcpy(to, from + offset, len);
kunmap_atomic(from);
}
static void memcpy_to_page(struct page *page, size_t offset, const char *from, size_t len)
{
char *to = kmap_atomic(page);
memcpy(to + offset, from, len);
kunmap_atomic(to);
}
static void memzero_page(struct page *page, size_t offset, size_t len)
{
char *addr = kmap_atomic(page);
memset(addr + offset, 0, len);
kunmap_atomic(addr);
}
size_t copy_to_iter(const void *addr, size_t bytes, struct iov_iter *i)
{
const char *from = addr;
if (unlikely(bytes > i->count))
bytes = i->count;
if (unlikely(!bytes))
return 0;
iterate_and_advance(i, bytes, v,
__copy_to_user(v.iov_base, (from += v.iov_len) - v.iov_len,
v.iov_len),
memcpy_to_page(v.bv_page, v.bv_offset,
(from += v.bv_len) - v.bv_len, v.bv_len),
memcpy(v.iov_base, (from += v.iov_len) - v.iov_len, v.iov_len)
)
return bytes;
}
size_t copy_from_iter(void *addr, size_t bytes, struct iov_iter *i)
{
char *to = addr;
if (unlikely(bytes > i->count))
bytes = i->count;
if (unlikely(!bytes))
return 0;
iterate_and_advance(i, bytes, v,
__copy_from_user((to += v.iov_len) - v.iov_len, v.iov_base,
v.iov_len),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
return bytes;
}
size_t copy_from_iter_nocache(void *addr, size_t bytes, struct iov_iter *i)
{
char *to = addr;
if (unlikely(bytes > i->count))
bytes = i->count;
if (unlikely(!bytes))
return 0;
iterate_and_advance(i, bytes, v,
__copy_from_user_nocache((to += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len),
memcpy_from_page((to += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((to += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
return bytes;
}
size_t copy_page_to_iter(struct page *page, size_t offset, size_t bytes,
struct iov_iter *i)
{
if (i->type & (ITER_BVEC|ITER_KVEC)) {
void *kaddr = kmap_atomic(page);
size_t wanted = copy_to_iter(kaddr + offset, bytes, i);
kunmap_atomic(kaddr);
return wanted;
} else
return copy_page_to_iter_iovec(page, offset, bytes, i);
}
size_t copy_page_from_iter(struct page *page, size_t offset, size_t bytes,
struct iov_iter *i)
{
if (i->type & (ITER_BVEC|ITER_KVEC)) {
void *kaddr = kmap_atomic(page);
size_t wanted = copy_from_iter(kaddr + offset, bytes, i);
kunmap_atomic(kaddr);
return wanted;
} else
return copy_page_from_iter_iovec(page, offset, bytes, i);
}
size_t iov_iter_zero(size_t bytes, struct iov_iter *i)
{
if (unlikely(bytes > i->count))
bytes = i->count;
if (unlikely(!bytes))
return 0;
iterate_and_advance(i, bytes, v,
__clear_user(v.iov_base, v.iov_len),
memzero_page(v.bv_page, v.bv_offset, v.bv_len),
memset(v.iov_base, 0, v.iov_len)
)
return bytes;
}
size_t iov_iter_copy_from_user_atomic(struct page *page,
struct iov_iter *i, unsigned long offset, size_t bytes)
{
char *kaddr = kmap_atomic(page), *p = kaddr + offset;
iterate_all_kinds(i, bytes, v,
__copy_from_user_inatomic((p += v.iov_len) - v.iov_len,
v.iov_base, v.iov_len),
memcpy_from_page((p += v.bv_len) - v.bv_len, v.bv_page,
v.bv_offset, v.bv_len),
memcpy((p += v.iov_len) - v.iov_len, v.iov_base, v.iov_len)
)
kunmap_atomic(kaddr);
return bytes;
}
void iov_iter_advance(struct iov_iter *i, size_t size)
{
iterate_and_advance(i, size, v, 0, 0, 0)
}
size_t iov_iter_single_seg_count(const struct iov_iter *i)
{
if (i->nr_segs == 1)
return i->count;
else if (i->type & ITER_BVEC)
return min(i->count, i->bvec->bv_len - i->iov_offset);
else
return min(i->count, i->iov->iov_len - i->iov_offset);
}
void iov_iter_kvec(struct iov_iter *i, int direction,
const struct kvec *kvec, unsigned long nr_segs,
size_t count)
{
BUG_ON(!(direction & ITER_KVEC));
i->type = direction;
i->kvec = kvec;
i->nr_segs = nr_segs;
i->iov_offset = 0;
i->count = count;
}
void iov_iter_bvec(struct iov_iter *i, int direction,
const struct bio_vec *bvec, unsigned long nr_segs,
size_t count)
{
BUG_ON(!(direction & ITER_BVEC));
i->type = direction;
i->bvec = bvec;
i->nr_segs = nr_segs;
i->iov_offset = 0;
i->count = count;
}
unsigned long iov_iter_alignment(const struct iov_iter *i)
{
unsigned long res = 0;
size_t size = i->count;
if (!size)
return 0;
iterate_all_kinds(i, size, v,
(res |= (unsigned long)v.iov_base | v.iov_len, 0),
res |= v.bv_offset | v.bv_len,
res |= (unsigned long)v.iov_base | v.iov_len
)
return res;
}
ssize_t iov_iter_get_pages(struct iov_iter *i,
struct page **pages, size_t maxsize, unsigned maxpages,
size_t *start)
{
if (maxsize > i->count)
maxsize = i->count;
if (!maxsize)
return 0;
iterate_all_kinds(i, maxsize, v, ({
unsigned long addr = (unsigned long)v.iov_base;
size_t len = v.iov_len + (*start = addr & (PAGE_SIZE - 1));
int n;
int res;
if (len > maxpages * PAGE_SIZE)
len = maxpages * PAGE_SIZE;
addr &= ~(PAGE_SIZE - 1);
n = DIV_ROUND_UP(len, PAGE_SIZE);
res = get_user_pages_fast(addr, n, (i->type & WRITE) != WRITE, pages);
if (unlikely(res < 0))
return res;
return (res == n ? len : res * PAGE_SIZE) - *start;
0;}),({
*start = v.bv_offset;
get_page(*pages = v.bv_page);
return v.bv_len;
}),({
return -EFAULT;
})
)
return 0;
}
static struct page **get_pages_array(size_t n)
{
struct page **p = kmalloc(n * sizeof(struct page *), GFP_KERNEL);
if (!p)
p = vmalloc(n * sizeof(struct page *));
return p;
}
ssize_t iov_iter_get_pages_alloc(struct iov_iter *i,
struct page ***pages, size_t maxsize,
size_t *start)
{
struct page **p;
if (maxsize > i->count)
maxsize = i->count;
if (!maxsize)
return 0;
iterate_all_kinds(i, maxsize, v, ({
unsigned long addr = (unsigned long)v.iov_base;
size_t len = v.iov_len + (*start = addr & (PAGE_SIZE - 1));
int n;
int res;
addr &= ~(PAGE_SIZE - 1);
n = DIV_ROUND_UP(len, PAGE_SIZE);
p = get_pages_array(n);
if (!p)
return -ENOMEM;
res = get_user_pages_fast(addr, n, (i->type & WRITE) != WRITE, p);
if (unlikely(res < 0)) {
kvfree(p);
return res;
}
*pages = p;
return (res == n ? len : res * PAGE_SIZE) - *start;
0;}),({
*start = v.bv_offset;
*pages = p = get_pages_array(1);
if (!p)
return -ENOMEM;
get_page(*p = v.bv_page);
return v.bv_len;
}),({
return -EFAULT;
})
)
return 0;
}
size_t csum_and_copy_from_iter(void *addr, size_t bytes, __wsum *csum,
struct iov_iter *i)
{
char *to = addr;
__wsum sum, next;
size_t off = 0;
if (unlikely(bytes > i->count))
bytes = i->count;
if (unlikely(!bytes))
return 0;
sum = *csum;
iterate_and_advance(i, bytes, v, ({
int err = 0;
next = csum_and_copy_from_user(v.iov_base,
(to += v.iov_len) - v.iov_len,
v.iov_len, 0, &err);
if (!err) {
sum = csum_block_add(sum, next, off);
off += v.iov_len;
}
err ? v.iov_len : 0;
}), ({
char *p = kmap_atomic(v.bv_page);
next = csum_partial_copy_nocheck(p + v.bv_offset,
(to += v.bv_len) - v.bv_len,
v.bv_len, 0);
kunmap_atomic(p);
sum = csum_block_add(sum, next, off);
off += v.bv_len;
}),({
next = csum_partial_copy_nocheck(v.iov_base,
(to += v.iov_len) - v.iov_len,
v.iov_len, 0);
sum = csum_block_add(sum, next, off);
off += v.iov_len;
})
)
*csum = sum;
return bytes;
}
size_t csum_and_copy_to_iter(const void *addr, size_t bytes, __wsum *csum,
struct iov_iter *i)
{
const char *from = addr;
__wsum sum, next;
size_t off = 0;
if (unlikely(bytes > i->count))
bytes = i->count;
if (unlikely(!bytes))
return 0;
sum = *csum;
iterate_and_advance(i, bytes, v, ({
int err = 0;
next = csum_and_copy_to_user((from += v.iov_len) - v.iov_len,
v.iov_base,
v.iov_len, 0, &err);
if (!err) {
sum = csum_block_add(sum, next, off);
off += v.iov_len;
}
err ? v.iov_len : 0;
}), ({
char *p = kmap_atomic(v.bv_page);
next = csum_partial_copy_nocheck((from += v.bv_len) - v.bv_len,
p + v.bv_offset,
v.bv_len, 0);
kunmap_atomic(p);
sum = csum_block_add(sum, next, off);
off += v.bv_len;
}),({
next = csum_partial_copy_nocheck((from += v.iov_len) - v.iov_len,
v.iov_base,
v.iov_len, 0);
sum = csum_block_add(sum, next, off);
off += v.iov_len;
})
)
*csum = sum;
return bytes;
}
int iov_iter_npages(const struct iov_iter *i, int maxpages)
{
size_t size = i->count;
int npages = 0;
if (!size)
return 0;
iterate_all_kinds(i, size, v, ({
unsigned long p = (unsigned long)v.iov_base;
npages += DIV_ROUND_UP(p + v.iov_len, PAGE_SIZE)
- p / PAGE_SIZE;
if (npages >= maxpages)
return maxpages;
0;}),({
npages++;
if (npages >= maxpages)
return maxpages;
}),({
unsigned long p = (unsigned long)v.iov_base;
npages += DIV_ROUND_UP(p + v.iov_len, PAGE_SIZE)
- p / PAGE_SIZE;
if (npages >= maxpages)
return maxpages;
})
)
return npages;
}
const void *dup_iter(struct iov_iter *new, struct iov_iter *old, gfp_t flags)
{
*new = *old;
if (new->type & ITER_BVEC)
return new->bvec = kmemdup(new->bvec,
new->nr_segs * sizeof(struct bio_vec),
flags);
else
return new->iov = kmemdup(new->iov,
new->nr_segs * sizeof(struct iovec),
flags);
}
int import_iovec(int type, const struct iovec __user * uvector,
unsigned nr_segs, unsigned fast_segs,
struct iovec **iov, struct iov_iter *i)
{
ssize_t n;
struct iovec *p;
n = rw_copy_check_uvector(type, uvector, nr_segs, fast_segs,
*iov, &p);
if (n < 0) {
if (p != *iov)
kfree(p);
*iov = NULL;
return n;
}
iov_iter_init(i, type, p, nr_segs, n);
*iov = p == *iov ? NULL : p;
return 0;
}
int compat_import_iovec(int type, const struct compat_iovec __user * uvector,
unsigned nr_segs, unsigned fast_segs,
struct iovec **iov, struct iov_iter *i)
{
ssize_t n;
struct iovec *p;
n = compat_rw_copy_check_uvector(type, uvector, nr_segs, fast_segs,
*iov, &p);
if (n < 0) {
if (p != *iov)
kfree(p);
*iov = NULL;
return n;
}
iov_iter_init(i, type, p, nr_segs, n);
*iov = p == *iov ? NULL : p;
return 0;
}
int import_single_range(int rw, void __user *buf, size_t len,
struct iovec *iov, struct iov_iter *i)
{
if (len > MAX_RW_COUNT)
len = MAX_RW_COUNT;
if (unlikely(!access_ok(!rw, buf, len)))
return -EFAULT;
iov->iov_base = buf;
iov->iov_len = len;
iov_iter_init(i, rw, iov, 1, len);
return 0;
}
