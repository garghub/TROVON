__kernel_size_t __clear_user_hexagon(void __user *dest, unsigned long count)
{
long uncleared;
while (count > PAGE_SIZE) {
uncleared = __copy_to_user_hexagon(dest, &empty_zero_page,
PAGE_SIZE);
if (uncleared)
return count - (PAGE_SIZE - uncleared);
count -= PAGE_SIZE;
dest += PAGE_SIZE;
}
if (count)
count = __copy_to_user_hexagon(dest, &empty_zero_page, count);
return count;
}
unsigned long clear_user_hexagon(void __user *dest, unsigned long count)
{
if (!access_ok(VERIFY_WRITE, dest, count))
return count;
else
return __clear_user_hexagon(dest, count);
}
