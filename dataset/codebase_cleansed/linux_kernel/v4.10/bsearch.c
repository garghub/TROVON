void *bsearch(const void *key, const void *base, size_t num, size_t size,
int (*cmp)(const void *key, const void *elt))
{
size_t start = 0, end = num;
int result;
while (start < end) {
size_t mid = start + (end - start) / 2;
result = cmp(key, base + mid * size);
if (result < 0)
end = mid;
else if (result > 0)
start = mid + 1;
else
return (void *)base + mid * size;
}
return NULL;
}
