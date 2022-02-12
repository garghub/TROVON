unsigned int csum_partial_copy(const char *src, char *dst,
int len, unsigned int sum)
{
sum = csum_partial(src, len, sum);
memcpy(dst, src, len);
return sum;
}
unsigned int csum_partial_copy_from_user(const char *src, char *dst,
int len, unsigned int sum,
int *err_ptr)
{
int missing;
missing = copy_from_user(dst, src, len);
if (missing) {
memset(dst + len - missing, 0, missing);
*err_ptr = -EFAULT;
}
return csum_partial(dst, len, sum);
}
