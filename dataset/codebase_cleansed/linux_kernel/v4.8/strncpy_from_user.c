static inline long do_strncpy_from_user(char *dst, const char __user *src, long count, unsigned long max)
{
const struct word_at_a_time constants = WORD_AT_A_TIME_CONSTANTS;
long res = 0;
if (max > count)
max = count;
if (IS_UNALIGNED(src, dst))
goto byte_at_a_time;
while (max >= sizeof(unsigned long)) {
unsigned long c, data;
unsafe_get_user(c, (unsigned long __user *)(src+res), byte_at_a_time);
*(unsigned long *)(dst+res) = c;
if (has_zero(c, &data, &constants)) {
data = prep_zero_mask(c, data, &constants);
data = create_zero_mask(data);
return res + find_zero(data);
}
res += sizeof(unsigned long);
max -= sizeof(unsigned long);
}
byte_at_a_time:
while (max) {
char c;
unsafe_get_user(c,src+res, efault);
dst[res] = c;
if (!c)
return res;
res++;
max--;
}
if (res >= count)
return res;
efault:
return -EFAULT;
}
long strncpy_from_user(char *dst, const char __user *src, long count)
{
unsigned long max_addr, src_addr;
if (unlikely(count <= 0))
return 0;
max_addr = user_addr_max();
src_addr = (unsigned long)src;
if (likely(src_addr < max_addr)) {
unsigned long max = max_addr - src_addr;
long retval;
kasan_check_write(dst, count);
user_access_begin();
retval = do_strncpy_from_user(dst, src, count, max);
user_access_end();
return retval;
}
return -EFAULT;
}
