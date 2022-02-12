unsigned long find_first_bit_inv(const unsigned long *addr, unsigned long size)
{
const unsigned long *p = addr;
unsigned long result = 0;
unsigned long tmp;
while (size & ~(BITS_PER_LONG - 1)) {
if ((tmp = *(p++)))
goto found;
result += BITS_PER_LONG;
size -= BITS_PER_LONG;
}
if (!size)
return result;
tmp = (*p) & (~0UL << (BITS_PER_LONG - size));
if (!tmp)
return result + size;
found:
return result + (__fls(tmp) ^ (BITS_PER_LONG - 1));
}
unsigned long find_next_bit_inv(const unsigned long *addr, unsigned long size,
unsigned long offset)
{
const unsigned long *p = addr + (offset / BITS_PER_LONG);
unsigned long result = offset & ~(BITS_PER_LONG - 1);
unsigned long tmp;
if (offset >= size)
return size;
size -= result;
offset %= BITS_PER_LONG;
if (offset) {
tmp = *(p++);
tmp &= (~0UL >> offset);
if (size < BITS_PER_LONG)
goto found_first;
if (tmp)
goto found_middle;
size -= BITS_PER_LONG;
result += BITS_PER_LONG;
}
while (size & ~(BITS_PER_LONG-1)) {
if ((tmp = *(p++)))
goto found_middle;
result += BITS_PER_LONG;
size -= BITS_PER_LONG;
}
if (!size)
return result;
tmp = *p;
found_first:
tmp &= (~0UL << (BITS_PER_LONG - size));
if (!tmp)
return result + size;
found_middle:
return result + (__fls(tmp) ^ (BITS_PER_LONG - 1));
}
