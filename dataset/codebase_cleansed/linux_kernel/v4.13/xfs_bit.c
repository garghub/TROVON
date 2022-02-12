int
xfs_bitmap_empty(uint *map, uint size)
{
uint i;
for (i = 0; i < size; i++) {
if (map[i] != 0)
return 0;
}
return 1;
}
int
xfs_contig_bits(uint *map, uint size, uint start_bit)
{
uint * p = ((unsigned int *) map) + (start_bit >> BIT_TO_WORD_SHIFT);
uint result = 0;
uint tmp;
size <<= BIT_TO_WORD_SHIFT;
ASSERT(start_bit < size);
size -= start_bit & ~(NBWORD - 1);
start_bit &= (NBWORD - 1);
if (start_bit) {
tmp = *p++;
tmp |= (~0U >> (NBWORD-start_bit));
if (tmp != ~0U)
goto found;
result += NBWORD;
size -= NBWORD;
}
while (size) {
if ((tmp = *p++) != ~0U)
goto found;
result += NBWORD;
size -= NBWORD;
}
return result - start_bit;
found:
return result + ffz(tmp) - start_bit;
}
int xfs_next_bit(uint *map, uint size, uint start_bit)
{
uint * p = ((unsigned int *) map) + (start_bit >> BIT_TO_WORD_SHIFT);
uint result = start_bit & ~(NBWORD - 1);
uint tmp;
size <<= BIT_TO_WORD_SHIFT;
if (start_bit >= size)
return -1;
size -= result;
start_bit &= (NBWORD - 1);
if (start_bit) {
tmp = *p++;
tmp &= (~0U << start_bit);
if (tmp != 0U)
goto found;
result += NBWORD;
size -= NBWORD;
}
while (size) {
if ((tmp = *p++) != 0U)
goto found;
result += NBWORD;
size -= NBWORD;
}
return -1;
found:
return result + ffs(tmp) - 1;
}
