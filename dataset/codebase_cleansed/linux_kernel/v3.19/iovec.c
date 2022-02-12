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
int memcpy_fromiovecend(unsigned char *kdata, const struct iovec *iov,
int offset, int len)
{
if (len == 0)
return 0;
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
