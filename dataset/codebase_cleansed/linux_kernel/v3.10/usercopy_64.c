unsigned long copy_from_user(void *to, const void __user *from, unsigned long n)
{
if (likely(access_ok(VERIFY_READ, from, n)))
n = __copy_from_user(to, from, n);
else
memset(to, 0, n);
return n;
}
unsigned long copy_to_user(void __user *to, const void *from, unsigned long n)
{
if (likely(access_ok(VERIFY_WRITE, to, n)))
n = __copy_to_user(to, from, n);
return n;
}
unsigned long copy_in_user(void __user *to, const void __user *from,
unsigned long n)
{
might_sleep();
if (likely(access_ok(VERIFY_READ, from, n) &&
access_ok(VERIFY_WRITE, to, n)))
n =__copy_tofrom_user(to, from, n);
return n;
}
