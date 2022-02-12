int verify_iovec(struct msghdr *m, struct iovec *iov, struct sockaddr_storage *address, int mode)
{
int size, ct, err;
if (m->msg_namelen) {
if (mode == VERIFY_READ) {
void __user *namep;
namep = (void __user __force *) m->msg_name;
err = move_addr_to_kernel(namep, m->msg_namelen,
address);
if (err < 0)
return err;
}
m->msg_name = address;
} else {
m->msg_name = NULL;
}
size = m->msg_iovlen * sizeof(struct iovec);
if (copy_from_user(iov, (void __user __force *) m->msg_iov, size))
return -EFAULT;
m->msg_iov = iov;
err = 0;
for (ct = 0; ct < m->msg_iovlen; ct++) {
size_t len = iov[ct].iov_len;
if (len > INT_MAX - err) {
len = INT_MAX - err;
iov[ct].iov_len = len;
}
err += len;
}
return err;
}
int memcpy_toiovec(struct iovec *iov, unsigned char *kdata, int len)
{
while (len > 0) {
if (iov->iov_len) {
int copy = min_t(unsigned int, iov->iov_len, len);
if (copy_to_user(iov->iov_base, kdata, copy))
return -EFAULT;
kdata += copy;
len -= copy;
iov->iov_len -= copy;
iov->iov_base += copy;
}
iov++;
}
return 0;
}
int memcpy_toiovecend(const struct iovec *iov, unsigned char *kdata,
int offset, int len)
{
int copy;
for (; len > 0; ++iov) {
if (unlikely(offset >= iov->iov_len)) {
offset -= iov->iov_len;
continue;
}
copy = min_t(unsigned int, iov->iov_len - offset, len);
if (copy_to_user(iov->iov_base + offset, kdata, copy))
return -EFAULT;
offset = 0;
kdata += copy;
len -= copy;
}
return 0;
}
int memcpy_fromiovec(unsigned char *kdata, struct iovec *iov, int len)
{
while (len > 0) {
if (iov->iov_len) {
int copy = min_t(unsigned int, len, iov->iov_len);
if (copy_from_user(kdata, iov->iov_base, copy))
return -EFAULT;
len -= copy;
kdata += copy;
iov->iov_base += copy;
iov->iov_len -= copy;
}
iov++;
}
return 0;
}
int memcpy_fromiovecend(unsigned char *kdata, const struct iovec *iov,
int offset, int len)
{
while (offset >= iov->iov_len) {
offset -= iov->iov_len;
iov++;
}
while (len > 0) {
u8 __user *base = iov->iov_base + offset;
int copy = min_t(unsigned int, len, iov->iov_len - offset);
offset = 0;
if (copy_from_user(kdata, base, copy))
return -EFAULT;
len -= copy;
kdata += copy;
iov++;
}
return 0;
}
int csum_partial_copy_fromiovecend(unsigned char *kdata, struct iovec *iov,
int offset, unsigned int len, __wsum *csump)
{
__wsum csum = *csump;
int partial_cnt = 0, err = 0;
while (offset >= iov->iov_len) {
offset -= iov->iov_len;
iov++;
}
while (len > 0) {
u8 __user *base = iov->iov_base + offset;
int copy = min_t(unsigned int, len, iov->iov_len - offset);
offset = 0;
if (partial_cnt) {
int par_len = 4 - partial_cnt;
if (par_len > copy) {
if (copy_from_user(kdata, base, copy))
goto out_fault;
kdata += copy;
base += copy;
partial_cnt += copy;
len -= copy;
iov++;
if (len)
continue;
*csump = csum_partial(kdata - partial_cnt,
partial_cnt, csum);
goto out;
}
if (copy_from_user(kdata, base, par_len))
goto out_fault;
csum = csum_partial(kdata - partial_cnt, 4, csum);
kdata += par_len;
base += par_len;
copy -= par_len;
len -= par_len;
partial_cnt = 0;
}
if (len > copy) {
partial_cnt = copy % 4;
if (partial_cnt) {
copy -= partial_cnt;
if (copy_from_user(kdata + copy, base + copy,
partial_cnt))
goto out_fault;
}
}
if (copy) {
csum = csum_and_copy_from_user(base, kdata, copy,
csum, &err);
if (err)
goto out;
}
len -= copy + partial_cnt;
kdata += copy + partial_cnt;
iov++;
}
*csump = csum;
out:
return err;
out_fault:
err = -EFAULT;
goto out;
}
