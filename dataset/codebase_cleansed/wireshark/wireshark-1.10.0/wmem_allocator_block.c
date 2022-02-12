static void
wmem_block_verify_chunk_chain(wmem_block_chunk_t *chunk)
{
guint32 total_len = 0;
g_assert(chunk->prev == 0);
do {
total_len += chunk->len;
if (WMEM_CHUNK_NEXT(chunk)) {
g_assert(chunk->len == WMEM_CHUNK_NEXT(chunk)->prev);
}
chunk = WMEM_CHUNK_NEXT(chunk);
} while (chunk);
g_assert(total_len == WMEM_BLOCK_SIZE);
}
static void
wmem_block_verify_free_list(wmem_block_allocator_t *allocator)
{
gboolean seen_insert_point = FALSE;
wmem_block_chunk_t *free_list;
wmem_block_free_t *free_head;
if (allocator->free_insert_point == NULL) {
seen_insert_point = TRUE;
}
free_list = allocator->free_list_head;
g_assert(WMEM_GET_FREE(free_list)->prev == NULL);
while (free_list) {
free_head = WMEM_GET_FREE(free_list);
if (free_list == allocator->free_insert_point) {
seen_insert_point = TRUE;
}
g_assert(free_head->in_free_list);
if (free_head->next) {
g_assert(WMEM_GET_FREE(free_head->next)->prev == free_list);
}
free_list = free_head->next;
}
g_assert(seen_insert_point);
}
void
wmem_block_verify(wmem_allocator_t *allocator)
{
GSList *tmp;
wmem_block_allocator_t *private_allocator;
g_assert(allocator->type == WMEM_ALLOCATOR_BLOCK);
private_allocator = (wmem_block_allocator_t*) allocator->private_data;
if (private_allocator->block_list == NULL) {
g_assert(! private_allocator->free_list_head);
g_assert(! private_allocator->free_insert_point);
return;
}
wmem_block_verify_free_list(private_allocator);
tmp = private_allocator->block_list;
while (tmp) {
wmem_block_verify_chunk_chain((wmem_block_chunk_t *)tmp->data);
tmp = tmp->next;
}
}
static void
wmem_block_remove_from_free_list(wmem_block_allocator_t *allocator,
wmem_block_chunk_t *chunk)
{
wmem_block_free_t *freeChunk;
g_assert(!chunk->used);
if (WMEM_CHUNK_DATA_LEN(chunk) < sizeof(wmem_block_free_t)) {
return;
}
freeChunk = WMEM_GET_FREE(chunk);
if (! freeChunk->in_free_list) {
return;
}
if (freeChunk->prev) {
g_assert(WMEM_GET_FREE(freeChunk->prev)->in_free_list);
g_assert(WMEM_GET_FREE(freeChunk->prev)->next == chunk);
WMEM_GET_FREE(freeChunk->prev)->next = freeChunk->next;
}
else {
g_assert(allocator->free_list_head == chunk);
allocator->free_list_head = freeChunk->next;
}
if (freeChunk->next) {
g_assert(WMEM_GET_FREE(freeChunk->next)->in_free_list);
g_assert(WMEM_GET_FREE(freeChunk->next)->prev == chunk);
WMEM_GET_FREE(freeChunk->next)->prev = freeChunk->prev;
}
if (allocator->free_insert_point == chunk) {
allocator->free_insert_point = freeChunk->prev;
}
freeChunk->in_free_list = FALSE;
}
static void
wmem_block_add_to_free_list_after(wmem_block_allocator_t *allocator,
wmem_block_chunk_t *chunk,
wmem_block_chunk_t *insertPoint)
{
wmem_block_free_t *freeChunk;
g_assert(!chunk->used);
g_assert(WMEM_CHUNK_DATA_LEN(chunk) >= sizeof(wmem_block_free_t));
freeChunk = WMEM_GET_FREE(chunk);
g_assert(! freeChunk->in_free_list);
if (insertPoint == NULL) {
freeChunk->next = allocator->free_list_head;
freeChunk->prev = NULL;
allocator->free_list_head = chunk;
if (freeChunk->next) {
WMEM_GET_FREE(freeChunk->next)->prev = chunk;
}
}
else {
freeChunk->next = WMEM_GET_FREE(insertPoint)->next;
freeChunk->prev = insertPoint;
WMEM_GET_FREE(insertPoint)->next = chunk;
if (freeChunk->next) {
WMEM_GET_FREE(freeChunk->next)->prev = chunk;
}
}
freeChunk->in_free_list = TRUE;
}
static void
wmem_block_add_to_free_list(wmem_block_allocator_t *allocator,
wmem_block_chunk_t *chunk)
{
g_assert(!chunk->used);
if (WMEM_CHUNK_DATA_LEN(chunk) >= sizeof(wmem_block_free_t)) {
g_assert(! WMEM_GET_FREE(chunk)->in_free_list);
}
if (chunk->len < WMEM_RECLAIM_LEN) {
return;
}
wmem_block_add_to_free_list_after(allocator, chunk,
allocator->free_insert_point);
if (chunk->len > WMEM_RECLAIM_PRIORITY_LEN) {
allocator->free_insert_point = chunk;
}
}
static wmem_block_chunk_t *
wmem_block_merge_free(wmem_block_allocator_t *allocator,
wmem_block_chunk_t *chunk)
{
wmem_block_chunk_t *tmp;
g_assert(!chunk->used);
tmp = WMEM_CHUNK_NEXT(chunk);
if (tmp && !tmp->used) {
wmem_block_remove_from_free_list(allocator, tmp);
chunk->len += tmp->len;
chunk->last = tmp->last;
}
tmp = WMEM_CHUNK_PREV(chunk);
if (tmp && !tmp->used) {
wmem_block_remove_from_free_list(allocator, tmp);
tmp->len += chunk->len;
tmp->last = chunk->last;
chunk = tmp;
}
tmp = WMEM_CHUNK_NEXT(chunk);
if (tmp) {
tmp->prev = chunk->len;
}
if (WMEM_CHUNK_DATA_LEN(chunk) >= sizeof(wmem_block_free_t)) {
WMEM_GET_FREE(chunk)->in_free_list = FALSE;
}
return chunk;
}
static void
wmem_block_split_free_chunk(wmem_block_allocator_t *allocator,
wmem_block_chunk_t *chunk,
const size_t size)
{
wmem_block_chunk_t *extra;
size_t aligned_size, available;
gboolean last;
g_assert(!chunk->used);
g_assert(WMEM_CHUNK_DATA_LEN(chunk) >= size);
aligned_size = WMEM_ALIGN_SIZE(size);
if (aligned_size + sizeof(wmem_block_chunk_t) >
WMEM_CHUNK_DATA_LEN(chunk)) {
wmem_block_remove_from_free_list(allocator, chunk);
return;
}
last = chunk->last;
available = chunk->len;
if (available < (sizeof(wmem_block_chunk_t) + aligned_size) +
(sizeof(wmem_block_chunk_t) + sizeof(wmem_block_free_t))) {
wmem_block_remove_from_free_list(allocator, chunk);
}
chunk->len = (guint32) (aligned_size + sizeof(wmem_block_chunk_t));
chunk->last = FALSE;
extra = WMEM_CHUNK_NEXT(chunk);
available -= (aligned_size + sizeof(wmem_block_chunk_t));
if (available >= sizeof(wmem_block_chunk_t) + sizeof(wmem_block_free_t)) {
if (! WMEM_GET_FREE(chunk)->in_free_list) {
WMEM_GET_FREE(extra)->in_free_list = FALSE;
}
else {
wmem_block_chunk_t *prev, *next;
wmem_block_free_t *old_blk, *new_blk;
old_blk = WMEM_GET_FREE(chunk);
new_blk = WMEM_GET_FREE(extra);
prev = old_blk->prev;
next = old_blk->next;
new_blk->in_free_list = TRUE;
new_blk->prev = prev;
new_blk->next = next;
if (prev) WMEM_GET_FREE(prev)->next = extra;
if (next) WMEM_GET_FREE(next)->prev = extra;
if (allocator->free_list_head == chunk)
allocator->free_list_head = extra;
if (allocator->free_insert_point == chunk)
allocator->free_insert_point = extra;
}
}
extra->len = (guint32) available;
extra->last = last;
extra->prev = (guint32) (aligned_size + sizeof(wmem_block_chunk_t));
extra->used = FALSE;
chunk = WMEM_CHUNK_NEXT(extra);
if (chunk) {
chunk->prev = extra->len;
}
}
static void
wmem_block_split_used_chunk(wmem_block_allocator_t *allocator,
wmem_block_chunk_t *chunk,
const size_t size)
{
wmem_block_chunk_t *extra;
size_t aligned_size, available;
gboolean last;
g_assert(chunk->used);
g_assert(WMEM_CHUNK_DATA_LEN(chunk) >= size);
aligned_size = WMEM_ALIGN_SIZE(size);
if (aligned_size + sizeof(wmem_block_chunk_t) >
WMEM_CHUNK_DATA_LEN(chunk)) {
return;
}
last = chunk->last;
available = chunk->len;
chunk->len = (guint32) (aligned_size + sizeof(wmem_block_chunk_t));
chunk->last = FALSE;
extra = WMEM_CHUNK_NEXT(chunk);
available -= (aligned_size + sizeof(wmem_block_chunk_t));
extra->len = (guint32) available;
extra->last = last;
extra->prev = (guint32) (aligned_size + sizeof(wmem_block_chunk_t));
extra->used = FALSE;
chunk = WMEM_CHUNK_NEXT(extra);
if (chunk) {
chunk->prev = extra->len;
}
chunk = wmem_block_merge_free(allocator, extra);
g_assert(chunk == extra);
wmem_block_add_to_free_list(allocator, extra);
}
static void
wmem_block_init_block(wmem_block_allocator_t *allocator, void *block)
{
wmem_block_chunk_t *chunk;
chunk = (wmem_block_chunk_t*) block;
chunk->used = FALSE;
chunk->last = TRUE;
chunk->prev = 0;
chunk->len = WMEM_BLOCK_SIZE;
WMEM_GET_FREE(chunk)->in_free_list = FALSE;
wmem_block_add_to_free_list_after(allocator, chunk, NULL);
if (allocator->free_insert_point == NULL) {
allocator->free_insert_point = chunk;
}
}
static void
wmem_block_new_block(wmem_block_allocator_t *allocator)
{
void *block;
block = g_malloc(WMEM_BLOCK_SIZE);
allocator->block_list = g_slist_prepend(allocator->block_list, block);
wmem_block_init_block(allocator, block);
}
static void *
wmem_block_alloc(void *private_data, const size_t size)
{
wmem_block_allocator_t *allocator = (wmem_block_allocator_t*) private_data;
wmem_block_chunk_t *chunk;
g_assert(size < WMEM_BLOCK_SIZE - sizeof(wmem_block_chunk_t));
if (allocator->free_list_head == NULL) {
wmem_block_new_block(allocator);
}
else if (WMEM_CHUNK_DATA_LEN(allocator->free_list_head) < size) {
chunk = allocator->free_list_head;
wmem_block_remove_from_free_list(allocator, chunk);
if (allocator->free_list_head == NULL ||
WMEM_CHUNK_DATA_LEN(allocator->free_list_head) < size) {
wmem_block_new_block(allocator);
}
wmem_block_add_to_free_list(allocator, chunk);
}
chunk = allocator->free_list_head;
g_assert(size <= WMEM_CHUNK_DATA_LEN(chunk));
wmem_block_split_free_chunk(allocator, chunk, size);
g_assert(size <= WMEM_CHUNK_DATA_LEN(chunk));
g_assert(chunk != allocator->free_list_head);
g_assert(chunk != allocator->free_insert_point);
chunk->used = TRUE;
return WMEM_CHUNK_DATA(chunk);
}
static void
wmem_block_free(void *private_data, void *ptr)
{
wmem_block_allocator_t *allocator = (wmem_block_allocator_t*) private_data;
wmem_block_chunk_t *chunk;
chunk = WMEM_DATA_TO_CHUNK(ptr);
g_assert(chunk->used);
chunk->used = FALSE;
chunk = wmem_block_merge_free(allocator, chunk);
wmem_block_add_to_free_list(allocator, chunk);
}
static void *
wmem_block_realloc(void *private_data, void *ptr, const size_t size)
{
wmem_block_allocator_t *allocator = (wmem_block_allocator_t*) private_data;
wmem_block_chunk_t *chunk;
chunk = WMEM_DATA_TO_CHUNK(ptr);
g_assert(chunk->used);
if (size > WMEM_CHUNK_DATA_LEN(chunk)) {
wmem_block_chunk_t *tmp;
tmp = WMEM_CHUNK_NEXT(chunk);
if (tmp && (!tmp->used) &&
(size < WMEM_CHUNK_DATA_LEN(chunk) + tmp->len)) {
size_t split_size;
split_size = size - WMEM_CHUNK_DATA_LEN(chunk);
if (split_size < sizeof(wmem_block_chunk_t)) {
split_size = 0;
}
else {
split_size -= sizeof(wmem_block_chunk_t);
}
wmem_block_split_free_chunk(allocator, tmp, split_size);
chunk->len += tmp->len;
chunk->last = tmp->last;
tmp = WMEM_CHUNK_NEXT(chunk);
if (tmp) {
tmp->prev = chunk->len;
}
return ptr;
}
else {
void *newptr;
newptr = wmem_block_alloc(private_data, size);
memcpy(newptr, ptr, WMEM_CHUNK_DATA_LEN(chunk));
wmem_block_free(private_data, ptr);
return newptr;
}
}
else if (size < WMEM_CHUNK_DATA_LEN(chunk)) {
wmem_block_split_used_chunk(allocator, chunk, size);
return ptr;
}
return ptr;
}
static void
wmem_block_free_all(void *private_data)
{
wmem_block_allocator_t *allocator = (wmem_block_allocator_t*) private_data;
GSList *tmp;
allocator->free_list_head = NULL;
allocator->free_insert_point = NULL;
tmp = allocator->block_list;
while (tmp) {
wmem_block_init_block(allocator, tmp->data);
tmp = tmp->next;
}
}
static void
wmem_block_gc(void *private_data)
{
wmem_block_allocator_t *allocator = (wmem_block_allocator_t*) private_data;
GSList *tmp, *new_block_list = NULL;
wmem_block_chunk_t *chunk;
tmp = allocator->block_list;
while (tmp) {
chunk = (wmem_block_chunk_t *) tmp->data;
if (!chunk->used && chunk->last) {
wmem_block_remove_from_free_list(allocator, chunk);
g_free(chunk);
}
else {
new_block_list = g_slist_prepend(new_block_list, chunk);
}
tmp = tmp->next;
}
g_slist_free(allocator->block_list);
allocator->block_list = new_block_list;
}
static void
wmem_block_allocator_destroy(wmem_allocator_t *allocator)
{
wmem_block_allocator_t *real_allocator;
real_allocator = (wmem_block_allocator_t*) allocator->private_data;
wmem_block_gc(real_allocator);
g_slice_free(wmem_block_allocator_t, real_allocator);
g_slice_free(wmem_allocator_t, allocator);
}
wmem_allocator_t *
wmem_block_allocator_new(void)
{
wmem_allocator_t *allocator;
wmem_block_allocator_t *block_allocator;
allocator = g_slice_new(wmem_allocator_t);
block_allocator = g_slice_new(wmem_block_allocator_t);
allocator->private_data = (void*) block_allocator;
allocator->alloc = &wmem_block_alloc;
allocator->realloc = &wmem_block_realloc;
allocator->free = &wmem_block_free;
allocator->free_all = &wmem_block_free_all;
allocator->gc = &wmem_block_gc;
allocator->destroy = &wmem_block_allocator_destroy;
block_allocator->block_list = NULL;
block_allocator->free_list_head = NULL;
block_allocator->free_insert_point = NULL;
return allocator;
}
