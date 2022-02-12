static void *
wmem_simple_alloc(void *private_data, const size_t size)
{
void *buf;
wmem_simple_allocator_t *allocator;
allocator = (wmem_simple_allocator_t*) private_data;
buf = wmem_alloc(NULL, size);
g_hash_table_insert(allocator->block_table, buf, buf);
return buf;
}
static void
wmem_simple_do_free(gpointer ptr)
{
wmem_free(NULL, ptr);
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
{ void *newptr;
wmem_simple_allocator_t *allocator;
allocator = (wmem_simple_allocator_t*) private_data;
newptr = wmem_realloc(NULL, ptr, size);
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
wmem_simple_allocator_cleanup(void *private_data)
{
wmem_simple_allocator_t *allocator;
allocator = (wmem_simple_allocator_t*) private_data;
g_hash_table_destroy(allocator->block_table);
wmem_free(NULL, allocator);
}
void
wmem_simple_allocator_init(wmem_allocator_t *allocator)
{
wmem_simple_allocator_t *simple_allocator;
simple_allocator = wmem_new(NULL, wmem_simple_allocator_t);
allocator->alloc = &wmem_simple_alloc;
allocator->realloc = &wmem_simple_realloc;
allocator->free = &wmem_simple_free;
allocator->free_all = &wmem_simple_free_all;
allocator->gc = &wmem_simple_gc;
allocator->cleanup = &wmem_simple_allocator_cleanup;
allocator->private_data = (void*) simple_allocator;
simple_allocator->block_table = g_hash_table_new_full(
&g_direct_hash, &g_direct_equal, NULL, &wmem_simple_do_free);
}
