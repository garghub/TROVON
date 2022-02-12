static inline long do_strnlen_user(const char __user *src, unsigned long count, unsigned long max)
{
const struct word_at_a_time constants = WORD_AT_A_TIME_CONSTANTS;
long align, res = 0;
unsigned long c;
if (max > count)
max = count;
align = (sizeof(long) - 1) & (unsigned long)src;
src -= align;
max += align;
if (unlikely(__get_user(c,(unsigned long __user *)src)))
return 0;
c |= aligned_byte_mask(align);
for (;;) {
unsigned long data;
if (has_zero(c, &data, &constants)) {
data = prep_zero_mask(c, data, &constants);
data = create_zero_mask(data);
return res + find_zero(data) + 1 - align;
}
res += sizeof(unsigned long);
if (unlikely(max < sizeof(unsigned long)))
break;
max -= sizeof(unsigned long);
if (unlikely(__get_user(c,(unsigned long __user *)(src+res))))
return 0;
}
res -= align;
if (res >= count)
return count+1;
return 0;
}
long strnlen_user(const char __user *str, long count)
{
unsigned long max_addr, src_addr;
if (unlikely(count <= 0))
return 0;
max_addr = user_addr_max();
src_addr = (unsigned long)str;
if (likely(src_addr < max_addr)) {
unsigned long max = max_addr - src_addr;
return do_strnlen_user(str, count, max);
}
return 0;
}
long strlen_user(const char __user *str)
{
unsigned long max_addr, src_addr;
max_addr = user_addr_max();
src_addr = (unsigned long)str;
if (likely(src_addr < max_addr)) {
unsigned long max = max_addr - src_addr;
return do_strnlen_user(str, ~0ul, max);
}
return 0;
}
