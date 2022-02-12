static inline void
wmem_block_fast_new_block(wmem_block_fast_allocator_t *allocator)
{
wmem_block_fast_hdr_t *block;
block = (wmem_block_fast_hdr_t *)wmem_alloc(NULL, WMEM_BLOCK_SIZE);
block->pos = WMEM_BLOCK_HEADER_SIZE;
block->next = allocator->block_list;
allocator->block_list = block;
}
static void *
wmem_block_fast_alloc(void *private_data, const size_t size)
{
wmem_block_fast_allocator_t *allocator = (wmem_block_fast_allocator_t*) private_data;
wmem_block_fast_chunk_t *chunk;
gint32 real_size;
if (size > WMEM_BLOCK_MAX_ALLOC_SIZE) {
wmem_block_fast_jumbo_t *block;
block = (wmem_block_fast_jumbo_t *)wmem_alloc(NULL,
size + WMEM_JUMBO_HEADER_SIZE + WMEM_CHUNK_HEADER_SIZE);
block->next = allocator->jumbo_list;
block->prev = NULL;
allocator->jumbo_list = block;
chunk = ((wmem_block_fast_chunk_t*)((guint8*)(block) + WMEM_JUMBO_HEADER_SIZE));
chunk->len = JUMBO_MAGIC;
return WMEM_CHUNK_TO_DATA(chunk);
}
real_size = (gint32)(WMEM_ALIGN_SIZE(size) + WMEM_CHUNK_HEADER_SIZE);
if (!allocator->block_list ||
(WMEM_BLOCK_SIZE - allocator->block_list->pos) < real_size) {
wmem_block_fast_new_block(allocator);
}
chunk = (wmem_block_fast_chunk_t *) ((guint8 *) allocator->block_list + allocator->block_list->pos);
chunk->len = (guint32) size;
allocator->block_list->pos += real_size;
return WMEM_CHUNK_TO_DATA(chunk);
}
static void
wmem_block_fast_free(void *private_data _U_, void *ptr _U_)
{
}
static void *
wmem_block_fast_realloc(void *private_data, void *ptr, const size_t size)
{
wmem_block_fast_chunk_t *chunk;
chunk = WMEM_DATA_TO_CHUNK(ptr);
if (chunk->len == JUMBO_MAGIC) {
wmem_block_fast_jumbo_t *block;
block = ((wmem_block_fast_jumbo_t*)((guint8*)(chunk) - WMEM_JUMBO_HEADER_SIZE));
block = (wmem_block_fast_jumbo_t*)wmem_realloc(NULL, block,
size + WMEM_JUMBO_HEADER_SIZE + WMEM_CHUNK_HEADER_SIZE);
if (block->prev) {
block->prev->next = block;
}
else {
wmem_block_fast_allocator_t *allocator = (wmem_block_fast_allocator_t*) private_data;
allocator->jumbo_list = block;
}
if (block->next) {
block->next->prev = block;
}
return ((void*)((guint8*)(block) + WMEM_JUMBO_HEADER_SIZE + WMEM_CHUNK_HEADER_SIZE));
}
else if (chunk->len < size) {
void *newptr;
newptr = wmem_block_fast_alloc(private_data, size);
memcpy(newptr, ptr, chunk->len);
return newptr;
}
return ptr;
}
static void
wmem_block_fast_free_all(void *private_data)
{
wmem_block_fast_allocator_t *allocator = (wmem_block_fast_allocator_t*) private_data;
wmem_block_fast_hdr_t *cur, *nxt;
wmem_block_fast_jumbo_t *cur_jum, *nxt_jum;
cur = allocator->block_list;
if (cur) {
cur->pos = WMEM_BLOCK_HEADER_SIZE;
nxt = cur->next;
cur->next = NULL;
cur = nxt;
}
while (cur) {
nxt = cur->next;
wmem_free(NULL, cur);
cur = nxt;
}
cur_jum = allocator->jumbo_list;
while (cur_jum) {
nxt_jum = cur_jum->next;
wmem_free(NULL, cur_jum);
cur_jum = nxt_jum;
}
allocator->jumbo_list = NULL;
}
static void
wmem_block_fast_gc(void *private_data _U_)
{
}
static void
wmem_block_fast_allocator_cleanup(void *private_data)
{
wmem_block_fast_allocator_t *allocator = (wmem_block_fast_allocator_t*) private_data;
wmem_free(NULL, allocator->block_list);
wmem_free(NULL, private_data);
}
void
wmem_block_fast_allocator_init(wmem_allocator_t *allocator)
{
wmem_block_fast_allocator_t *block_allocator;
block_allocator = wmem_new(NULL, wmem_block_fast_allocator_t);
allocator->walloc = &wmem_block_fast_alloc;
allocator->wrealloc = &wmem_block_fast_realloc;
allocator->wfree = &wmem_block_fast_free;
allocator->free_all = &wmem_block_fast_free_all;
allocator->gc = &wmem_block_fast_gc;
allocator->cleanup = &wmem_block_fast_allocator_cleanup;
allocator->private_data = (void*) block_allocator;
block_allocator->block_list = NULL;
block_allocator->jumbo_list = NULL;
}
