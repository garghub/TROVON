size_t memweight(const void *ptr, size_t bytes)
{
size_t ret = 0;
size_t longs;
const unsigned char *bitmap = ptr;
for (; bytes > 0 && ((unsigned long)bitmap) % sizeof(long);
bytes--, bitmap++)
ret += hweight8(*bitmap);
longs = bytes / sizeof(long);
if (longs) {
BUG_ON(longs >= INT_MAX / BITS_PER_LONG);
ret += bitmap_weight((unsigned long *)bitmap,
longs * BITS_PER_LONG);
bytes -= longs * sizeof(long);
bitmap += longs * sizeof(long);
}
for (; bytes > 0; bytes--, bitmap++)
ret += hweight8(*bitmap);
return ret;
}
