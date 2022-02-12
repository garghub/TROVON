static void
wmem_strict_block_check_canaries(wmem_strict_allocator_block_t *block)
{
guint i;
for (i=0; i<WMEM_CANARY_SIZE; i++) {
g_assert(block->leading_canary[i] == WMEM_CANARY_VALUE);
g_assert(block->trailing_canary[i] == WMEM_CANARY_VALUE);
}
}
static void
wmem_strict_ghash_check_canaries(gpointer key _U_, gpointer value,
gpointer user_data _U_)
{
wmem_strict_block_check_canaries((wmem_strict_allocator_block_t *)value);
}
static void
wmem_strict_block_free(wmem_strict_allocator_block_t *block)
{
memset(block->real_data, WMEM_POSTFILL, block->data_len);
wmem_free(NULL, block->leading_canary);
wmem_free(NULL, block);
}
static void
wmem_strict_ghash_block_free(gpointer data)
{
wmem_strict_block_free((wmem_strict_allocator_block_t *)data);
}
static wmem_strict_allocator_block_t *
wmem_strict_block_new(const size_t size)
{
wmem_strict_allocator_block_t *block;
guint i;
block = wmem_new(NULL, wmem_strict_allocator_block_t);
block->data_len = size;
block->leading_canary = (guint8 *)wmem_alloc(NULL, block->data_len + (2 * WMEM_CANARY_SIZE));
block->real_data = block->leading_canary + WMEM_CANARY_SIZE;
block->trailing_canary = block->real_data + block->data_len;
memset(block->real_data, WMEM_PREFILL, block->data_len);
for (i=0; i<WMEM_CANARY_SIZE; i++) {
block->leading_canary[i] = WMEM_CANARY_VALUE;
block->trailing_canary[i] = WMEM_CANARY_VALUE;
}
return block;
}
static void *
wmem_strict_alloc(void *private_data, const size_t size)
{
wmem_strict_allocator_t *allocator;
wmem_strict_allocator_block_t *block;
allocator = (wmem_strict_allocator_t*) private_data;
block = wmem_strict_block_new(size);
g_hash_table_insert(allocator->block_table, block->real_data, block);
return block->real_data;
}
static void
wmem_strict_free(void *private_data, void *ptr)
{
wmem_strict_allocator_t *allocator;
wmem_strict_allocator_block_t *block;
allocator = (wmem_strict_allocator_t*) private_data;
block = (wmem_strict_allocator_block_t *)g_hash_table_lookup(allocator->block_table, ptr);
g_assert(block);
wmem_strict_block_check_canaries(block);
g_hash_table_remove(allocator->block_table, ptr);
}
static void *
wmem_strict_realloc(void *private_data, void *ptr, const size_t size)
{
gsize copy_len;
wmem_strict_allocator_t *allocator;
wmem_strict_allocator_block_t *block, *newblock;
allocator = (wmem_strict_allocator_t*) private_data;
block = (wmem_strict_allocator_block_t *)g_hash_table_lookup(allocator->block_table, ptr);
g_assert(block);
wmem_strict_block_check_canaries(block);
newblock = wmem_strict_block_new(size);
if (block->data_len > newblock->data_len) {
copy_len = newblock->data_len;
}
else {
copy_len = block->data_len;
}
memcpy(newblock->real_data, block->real_data, copy_len);
g_hash_table_remove(allocator->block_table, ptr);
g_hash_table_insert(allocator->block_table, newblock->real_data, newblock);
return newblock->real_data;
}
void
wmem_strict_check_canaries(wmem_allocator_t *allocator)
{
wmem_strict_allocator_t *private_allocator;
if (allocator->type != WMEM_ALLOCATOR_STRICT) {
return;
}
private_allocator = (wmem_strict_allocator_t*) allocator->private_data;
g_hash_table_foreach(private_allocator->block_table,
&wmem_strict_ghash_check_canaries, NULL);
}
static void
wmem_strict_free_all(void *private_data)
{
wmem_strict_allocator_t *allocator;
allocator = (wmem_strict_allocator_t*) private_data;
g_hash_table_foreach(allocator->block_table,
&wmem_strict_ghash_check_canaries, NULL);
g_hash_table_remove_all(allocator->block_table);
}
static void
wmem_strict_gc(void *private_data _U_)
{
}
static void
wmem_strict_allocator_cleanup(void *private_data)
{
wmem_strict_allocator_t *allocator;
allocator = (wmem_strict_allocator_t*) private_data;
g_hash_table_destroy(allocator->block_table);
wmem_free(NULL, allocator);
}
void
wmem_strict_allocator_init(wmem_allocator_t *allocator)
{
wmem_strict_allocator_t *strict_allocator;
strict_allocator = wmem_new(NULL, wmem_strict_allocator_t);
allocator->alloc = &wmem_strict_alloc;
allocator->realloc = &wmem_strict_realloc;
allocator->free = &wmem_strict_free;
allocator->free_all = &wmem_strict_free_all;
allocator->gc = &wmem_strict_gc;
allocator->cleanup = &wmem_strict_allocator_cleanup;
allocator->private_data = (void*) strict_allocator;
strict_allocator->block_table = g_hash_table_new_full(
&g_direct_hash, &g_direct_equal,
NULL, &wmem_strict_ghash_block_free);
}
