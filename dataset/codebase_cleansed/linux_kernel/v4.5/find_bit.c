static unsigned long _find_next_bit(const unsigned long *addr,
unsigned long nbits, unsigned long start, unsigned long invert)
{
unsigned long tmp;
if (!nbits || start >= nbits)
return nbits;
tmp = addr[start / BITS_PER_LONG] ^ invert;
tmp &= BITMAP_FIRST_WORD_MASK(start);
start = round_down(start, BITS_PER_LONG);
while (!tmp) {
start += BITS_PER_LONG;
if (start >= nbits)
return nbits;
tmp = addr[start / BITS_PER_LONG] ^ invert;
}
return min(start + __ffs(tmp), nbits);
}
unsigned long find_next_bit(const unsigned long *addr, unsigned long size,
unsigned long offset)
{
return _find_next_bit(addr, size, offset, 0UL);
}
unsigned long find_first_bit(const unsigned long *addr, unsigned long size)
{
unsigned long idx;
for (idx = 0; idx * BITS_PER_LONG < size; idx++) {
if (addr[idx])
return min(idx * BITS_PER_LONG + __ffs(addr[idx]), size);
}
return size;
}
