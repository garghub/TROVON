static inline void
wmem_strict_block_check_canaries(wmem_strict_allocator_block_t *block)
{
guint i;
guint8 *canary;
canary = WMEM_BLOCK_TO_PRE_CANARY(block);
for (i=0; i<WMEM_CANARY_SIZE; i++) g_assert(canary[i] == WMEM_CANARY_VALUE);
canary = WMEM_BLOCK_TO_POST_CANARY(block);
for (i=0; i<WMEM_CANARY_SIZE; i++) g_assert(canary[i] == WMEM_CANARY_VALUE);
}
static void *
wmem_strict_alloc(void *private_data, const size_t size)
{
wmem_strict_allocator_t *allocator;
wmem_strict_allocator_block_t *block;
guint i;
guint8 *canary;
allocator = (wmem_strict_allocator_t*) private_data;
block = (wmem_strict_allocator_block_t *)wmem_alloc(NULL, WMEM_FULL_SIZE(size));
block->data_len = size;
memset(WMEM_BLOCK_TO_DATA(block), WMEM_PREFILL, block->data_len);
canary = WMEM_BLOCK_TO_PRE_CANARY(block);
for (i=0; i<WMEM_CANARY_SIZE; i++) canary[i] = WMEM_CANARY_VALUE;
canary = WMEM_BLOCK_TO_POST_CANARY(block);
for (i=0; i<WMEM_CANARY_SIZE; i++) canary[i] = WMEM_CANARY_VALUE;
if (allocator->blocks) {
allocator->blocks->prev = block;
}
block->next = allocator->blocks;
block->prev = NULL;
allocator->blocks = block;
return WMEM_BLOCK_TO_DATA(block);
}
static void
wmem_strict_free(void *private_data, void *ptr)
{
wmem_strict_allocator_t *allocator;
wmem_strict_allocator_block_t *block;
allocator = (wmem_strict_allocator_t*) private_data;
block = WMEM_DATA_TO_BLOCK(ptr);
wmem_strict_block_check_canaries(block);
if (block->next) {
block->next->prev = block->prev;
}
if (block->prev) {
block->prev->next = block->next;
}
else {
allocator->blocks = block->next;
}
memset(block, WMEM_POSTFILL, WMEM_FULL_SIZE(block->data_len));
wmem_free(NULL, block);
}
static void *
wmem_strict_realloc(void *private_data, void *ptr, const size_t size)
{
wmem_strict_allocator_block_t *block;
void *new_ptr;
block = WMEM_DATA_TO_BLOCK(ptr);
new_ptr = wmem_strict_alloc(private_data, size);
if (block->data_len > size) {
memcpy(new_ptr, ptr, size);
}
else {
memcpy(new_ptr, ptr, block->data_len);
}
wmem_strict_free(private_data, ptr);
return new_ptr;
}
void
wmem_strict_check_canaries(wmem_allocator_t *allocator)
{
wmem_strict_allocator_t *private_allocator;
wmem_strict_allocator_block_t *block;
if (allocator->type != WMEM_ALLOCATOR_STRICT) {
return;
}
private_allocator = (wmem_strict_allocator_t*) allocator->private_data;
block = private_allocator->blocks;
while (block) {
wmem_strict_block_check_canaries(block);
block = block->next;
}
}
static void
wmem_strict_free_all(void *private_data)
{
wmem_strict_allocator_t *allocator;
allocator = (wmem_strict_allocator_t*) private_data;
while (allocator->blocks) {
wmem_strict_free(private_data, WMEM_BLOCK_TO_DATA(allocator->blocks));
}
}
static void
wmem_strict_gc(void *private_data _U_)
{
}
static void
wmem_strict_allocator_cleanup(void *private_data)
{
wmem_free(NULL, private_data);
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
strict_allocator->blocks = NULL;
}
