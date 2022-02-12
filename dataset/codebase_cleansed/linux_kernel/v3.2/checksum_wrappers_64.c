__wsum csum_and_copy_from_user(const void __user *src, void *dst,
int len, __wsum sum, int *err_ptr)
{
unsigned int csum;
might_sleep();
*err_ptr = 0;
if (!len) {
csum = 0;
goto out;
}
if (unlikely((len < 0) || !access_ok(VERIFY_READ, src, len))) {
*err_ptr = -EFAULT;
csum = (__force unsigned int)sum;
goto out;
}
csum = csum_partial_copy_generic((void __force *)src, dst,
len, sum, err_ptr, NULL);
if (unlikely(*err_ptr)) {
int missing = __copy_from_user(dst, src, len);
if (missing) {
memset(dst + len - missing, 0, missing);
*err_ptr = -EFAULT;
} else {
*err_ptr = 0;
}
csum = csum_partial(dst, len, sum);
}
out:
return (__force __wsum)csum;
}
__wsum csum_and_copy_to_user(const void *src, void __user *dst, int len,
__wsum sum, int *err_ptr)
{
unsigned int csum;
might_sleep();
*err_ptr = 0;
if (!len) {
csum = 0;
goto out;
}
if (unlikely((len < 0) || !access_ok(VERIFY_WRITE, dst, len))) {
*err_ptr = -EFAULT;
csum = -1;
goto out;
}
csum = csum_partial_copy_generic(src, (void __force *)dst,
len, sum, NULL, err_ptr);
if (unlikely(*err_ptr)) {
csum = csum_partial(src, len, sum);
if (copy_to_user(dst, src, len)) {
*err_ptr = -EFAULT;
csum = -1;
}
}
out:
return (__force __wsum)csum;
}
