unsigned long __copy_from_user_zeroing(void *to, const void __user *from,
unsigned long n)
{
unsigned long rc = __copy_from_user_inatomic(to, from, n);
if (unlikely(rc))
memset(to + n - rc, 0, rc);
return rc;
}
