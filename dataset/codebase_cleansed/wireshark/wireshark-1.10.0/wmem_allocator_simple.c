static void *
wmem_simple_alloc(void *private_data, const size_t size)
{
void *buf;
wmem_simple_allocator_t *allocator;
allocator = (wmem_simple_allocator_t*) private_data;
buf = g_malloc(size);
g_hash_table_insert(allocator->block_table, buf, buf);
return buf;
}
static void
wmem_simple_free(void *private_data, void *ptr)
{
gboolean removed;
wmem_simple_allocator_t *allocator;
allocator = (wmem_simple_allocator_t*) private_data;
removed = g_hash_table_remove(allocator->block_table, ptr);
g_assert(removed);
}
static void *
wmem_simple_realloc(void *private_data, void *ptr, const size_t size)
{
void *newptr;
wmem_simple_allocator_t *allocator;
allocator = (wmem_simple_allocator_t*) private_data;
newptr = g_realloc(ptr, size);
if (ptr != newptr) {
g_hash_table_steal(allocator->block_table, ptr);
g_hash_table_insert(allocator->block_table, newptr, newptr);
}
return newptr;
}
static void
wmem_simple_free_all(void *private_data)
{
wmem_simple_allocator_t *allocator;
allocator = (wmem_simple_allocator_t*) private_data;
g_hash_table_remove_all(allocator->block_table);
}
static void
wmem_simple_gc(void *private_data _U_)
{
}
static void
wmem_simple_allocator_destroy(wmem_allocator_t *allocator)
{
wmem_simple_allocator_t *private_allocator;
private_allocator = (wmem_simple_allocator_t*) allocator->private_data;
g_hash_table_destroy(private_allocator->block_table);
g_slice_free(wmem_simple_allocator_t, private_allocator);
g_slice_free(wmem_allocator_t, allocator);
}
wmem_allocator_t *
wmem_simple_allocator_new(void)
{
wmem_allocator_t *allocator;
wmem_simple_allocator_t *simple_allocator;
allocator = g_slice_new(wmem_allocator_t);
simple_allocator = g_slice_new(wmem_simple_allocator_t);
allocator->private_data = (void*) simple_allocator;
allocator->alloc = &wmem_simple_alloc;
allocator->realloc = &wmem_simple_realloc;
allocator->free = &wmem_simple_free;
allocator->free_all = &wmem_simple_free_all;
allocator->gc = &wmem_simple_gc;
allocator->destroy = &wmem_simple_allocator_destroy;
simple_allocator->block_table = g_hash_table_new_full(
&g_direct_hash, &g_direct_equal, NULL, &g_free);
return allocator;
}
