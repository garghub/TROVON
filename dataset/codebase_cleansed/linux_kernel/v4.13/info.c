void rds_info_register_func(int optname, rds_info_func func)
{
int offset = optname - RDS_INFO_FIRST;
BUG_ON(optname < RDS_INFO_FIRST || optname > RDS_INFO_LAST);
spin_lock(&rds_info_lock);
BUG_ON(rds_info_funcs[offset]);
rds_info_funcs[offset] = func;
spin_unlock(&rds_info_lock);
}
void rds_info_deregister_func(int optname, rds_info_func func)
{
int offset = optname - RDS_INFO_FIRST;
BUG_ON(optname < RDS_INFO_FIRST || optname > RDS_INFO_LAST);
spin_lock(&rds_info_lock);
BUG_ON(rds_info_funcs[offset] != func);
rds_info_funcs[offset] = NULL;
spin_unlock(&rds_info_lock);
}
void rds_info_iter_unmap(struct rds_info_iterator *iter)
{
if (iter->addr) {
kunmap_atomic(iter->addr);
iter->addr = NULL;
}
}
void rds_info_copy(struct rds_info_iterator *iter, void *data,
unsigned long bytes)
{
unsigned long this;
while (bytes) {
if (!iter->addr)
iter->addr = kmap_atomic(*iter->pages);
this = min(bytes, PAGE_SIZE - iter->offset);
rdsdebug("page %p addr %p offset %lu this %lu data %p "
"bytes %lu\n", *iter->pages, iter->addr,
iter->offset, this, data, bytes);
memcpy(iter->addr + iter->offset, data, this);
data += this;
bytes -= this;
iter->offset += this;
if (iter->offset == PAGE_SIZE) {
kunmap_atomic(iter->addr);
iter->addr = NULL;
iter->offset = 0;
iter->pages++;
}
}
}
int rds_info_getsockopt(struct socket *sock, int optname, char __user *optval,
int __user *optlen)
{
struct rds_info_iterator iter;
struct rds_info_lengths lens;
unsigned long nr_pages = 0;
unsigned long start;
unsigned long i;
rds_info_func func;
struct page **pages = NULL;
int ret;
int len;
int total;
if (get_user(len, optlen)) {
ret = -EFAULT;
goto out;
}
start = (unsigned long)optval;
if (len < 0 || len > INT_MAX - PAGE_SIZE + 1 || start + len < start) {
ret = -EINVAL;
goto out;
}
if (len == 0)
goto call_func;
nr_pages = (PAGE_ALIGN(start + len) - (start & PAGE_MASK))
>> PAGE_SHIFT;
pages = kmalloc(nr_pages * sizeof(struct page *), GFP_KERNEL);
if (!pages) {
ret = -ENOMEM;
goto out;
}
ret = get_user_pages_fast(start, nr_pages, 1, pages);
if (ret != nr_pages) {
if (ret > 0)
nr_pages = ret;
else
nr_pages = 0;
ret = -EAGAIN;
goto out;
}
rdsdebug("len %d nr_pages %lu\n", len, nr_pages);
call_func:
func = rds_info_funcs[optname - RDS_INFO_FIRST];
if (!func) {
ret = -ENOPROTOOPT;
goto out;
}
iter.pages = pages;
iter.addr = NULL;
iter.offset = start & (PAGE_SIZE - 1);
func(sock, len, &iter, &lens);
BUG_ON(lens.each == 0);
total = lens.nr * lens.each;
rds_info_iter_unmap(&iter);
if (total > len) {
len = total;
ret = -ENOSPC;
} else {
len = total;
ret = lens.each;
}
if (put_user(len, optlen))
ret = -EFAULT;
out:
for (i = 0; pages && i < nr_pages; i++)
put_page(pages[i]);
kfree(pages);
return ret;
}
