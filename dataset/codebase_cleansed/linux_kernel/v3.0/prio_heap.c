int heap_init(struct ptr_heap *heap, size_t size, gfp_t gfp_mask,
int (*gt)(void *, void *))
{
heap->ptrs = kmalloc(size, gfp_mask);
if (!heap->ptrs)
return -ENOMEM;
heap->size = 0;
heap->max = size / sizeof(void *);
heap->gt = gt;
return 0;
}
void heap_free(struct ptr_heap *heap)
{
kfree(heap->ptrs);
}
void *heap_insert(struct ptr_heap *heap, void *p)
{
void *res;
void **ptrs = heap->ptrs;
int pos;
if (heap->size < heap->max) {
pos = heap->size++;
while (pos > 0 && heap->gt(p, ptrs[(pos-1)/2])) {
ptrs[pos] = ptrs[(pos-1)/2];
pos = (pos-1)/2;
}
ptrs[pos] = p;
return NULL;
}
if (heap->gt(p, ptrs[0]))
return p;
res = ptrs[0];
ptrs[0] = p;
pos = 0;
while (1) {
int left = 2 * pos + 1;
int right = 2 * pos + 2;
int largest = pos;
if (left < heap->size && heap->gt(ptrs[left], p))
largest = left;
if (right < heap->size && heap->gt(ptrs[right], ptrs[largest]))
largest = right;
if (largest == pos)
break;
ptrs[pos] = ptrs[largest];
ptrs[largest] = p;
pos = largest;
}
return res;
}
