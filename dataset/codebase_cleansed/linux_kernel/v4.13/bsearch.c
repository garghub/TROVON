void *bsearch(const void *key, const void *base, size_t num, size_t size,
int (*cmp)(const void *key, const void *elt))
{
const char *pivot;
int result;
while (num > 0) {
pivot = base + (num >> 1) * size;
result = cmp(key, pivot);
if (result == 0)
return (void *)pivot;
if (result > 0) {
base = pivot + size;
num--;
}
num >>= 1;
}
return NULL;
}
