unsigned long find_next_bit(const unsigned long *addr, unsigned long size,
unsigned long offset)
{
const unsigned long *p = addr + BITOP_WORD(offset);
unsigned long result = offset & ~(BITS_PER_LONG-1);
unsigned long tmp;
if (offset >= size)
return size;
size -= result;
offset %= BITS_PER_LONG;
if (offset) {
tmp = *(p++);
tmp &= (~0UL << offset);
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
tmp &= (~0UL >> (BITS_PER_LONG - size));
if (tmp == 0UL)
return result + size;
found_middle:
return result + __ffs(tmp);
}
unsigned long find_next_zero_bit(const unsigned long *addr, unsigned long size,
unsigned long offset)
{
const unsigned long *p = addr + BITOP_WORD(offset);
unsigned long result = offset & ~(BITS_PER_LONG-1);
unsigned long tmp;
if (offset >= size)
return size;
size -= result;
offset %= BITS_PER_LONG;
if (offset) {
tmp = *(p++);
tmp |= ~0UL >> (BITS_PER_LONG - offset);
if (size < BITS_PER_LONG)
goto found_first;
if (~tmp)
goto found_middle;
size -= BITS_PER_LONG;
result += BITS_PER_LONG;
}
while (size & ~(BITS_PER_LONG-1)) {
if (~(tmp = *(p++)))
goto found_middle;
result += BITS_PER_LONG;
size -= BITS_PER_LONG;
}
if (!size)
return result;
tmp = *p;
found_first:
tmp |= ~0UL << size;
if (tmp == ~0UL)
return result + size;
found_middle:
return result + ffz(tmp);
}
unsigned long find_first_bit(const unsigned long *addr, unsigned long size)
{
const unsigned long *p = addr;
unsigned long result = 0;
unsigned long tmp;
while (size & ~(BITS_PER_LONG-1)) {
if ((tmp = *(p++)))
goto found;
result += BITS_PER_LONG;
size -= BITS_PER_LONG;
}
if (!size)
return result;
tmp = (*p) & (~0UL >> (BITS_PER_LONG - size));
if (tmp == 0UL)
return result + size;
found:
return result + __ffs(tmp);
}
unsigned long find_first_zero_bit(const unsigned long *addr, unsigned long size)
{
const unsigned long *p = addr;
unsigned long result = 0;
unsigned long tmp;
while (size & ~(BITS_PER_LONG-1)) {
if (~(tmp = *(p++)))
goto found;
result += BITS_PER_LONG;
size -= BITS_PER_LONG;
}
if (!size)
return result;
tmp = (*p) | (~0UL << size);
if (tmp == ~0UL)
return result + size;
found:
return result + ffz(tmp);
}
static inline unsigned long ext2_swabp(const unsigned long * x)
{
#if BITS_PER_LONG == 64
return (unsigned long) __swab64p((u64 *) x);
#elif BITS_PER_LONG == 32
return (unsigned long) __swab32p((u32 *) x);
#else
#error BITS_PER_LONG not defined
#endif
}
static inline unsigned long ext2_swab(const unsigned long y)
{
#if BITS_PER_LONG == 64
return (unsigned long) __swab64((u64) y);
#elif BITS_PER_LONG == 32
return (unsigned long) __swab32((u32) y);
#else
#error BITS_PER_LONG not defined
#endif
}
unsigned long find_next_zero_bit_le(const void *addr, unsigned
long size, unsigned long offset)
{
const unsigned long *p = addr;
unsigned long result = offset & ~(BITS_PER_LONG - 1);
unsigned long tmp;
if (offset >= size)
return size;
p += BITOP_WORD(offset);
size -= result;
offset &= (BITS_PER_LONG - 1UL);
if (offset) {
tmp = ext2_swabp(p++);
tmp |= (~0UL >> (BITS_PER_LONG - offset));
if (size < BITS_PER_LONG)
goto found_first;
if (~tmp)
goto found_middle;
size -= BITS_PER_LONG;
result += BITS_PER_LONG;
}
while (size & ~(BITS_PER_LONG - 1)) {
if (~(tmp = *(p++)))
goto found_middle_swap;
result += BITS_PER_LONG;
size -= BITS_PER_LONG;
}
if (!size)
return result;
tmp = ext2_swabp(p);
found_first:
tmp |= ~0UL << size;
if (tmp == ~0UL)
return result + size;
found_middle:
return result + ffz(tmp);
found_middle_swap:
return result + ffz(ext2_swab(tmp));
}
unsigned long find_next_bit_le(const void *addr, unsigned
long size, unsigned long offset)
{
const unsigned long *p = addr;
unsigned long result = offset & ~(BITS_PER_LONG - 1);
unsigned long tmp;
if (offset >= size)
return size;
p += BITOP_WORD(offset);
size -= result;
offset &= (BITS_PER_LONG - 1UL);
if (offset) {
tmp = ext2_swabp(p++);
tmp &= (~0UL << offset);
if (size < BITS_PER_LONG)
goto found_first;
if (tmp)
goto found_middle;
size -= BITS_PER_LONG;
result += BITS_PER_LONG;
}
while (size & ~(BITS_PER_LONG - 1)) {
tmp = *(p++);
if (tmp)
goto found_middle_swap;
result += BITS_PER_LONG;
size -= BITS_PER_LONG;
}
if (!size)
return result;
tmp = ext2_swabp(p);
found_first:
tmp &= (~0UL >> (BITS_PER_LONG - size));
if (tmp == 0UL)
return result + size;
found_middle:
return result + __ffs(tmp);
found_middle_swap:
return result + __ffs(ext2_swab(tmp));
}
