static int
wmem_block_verify_block(wmem_block_hdr_t *block)
{
int total_free_space = 0;
guint32 total_len;
wmem_block_chunk_t *chunk;
chunk = WMEM_BLOCK_TO_CHUNK(block);
total_len = WMEM_BLOCK_HEADER_SIZE;
if (chunk->jumbo) {
return 0;
}
g_assert(chunk->prev == 0);
do {
total_len += chunk->len;
g_assert(chunk->len >= WMEM_CHUNK_HEADER_SIZE);
g_assert(!chunk->jumbo);
if (WMEM_CHUNK_NEXT(chunk)) {
g_assert(chunk->len == WMEM_CHUNK_NEXT(chunk)->prev);
}
if (!chunk->used &&
WMEM_CHUNK_DATA_LEN(chunk) >= sizeof(wmem_block_free_t)) {
total_free_space += chunk->len;
if (!chunk->last) {
g_assert(WMEM_GET_FREE(chunk)->next);
g_assert(WMEM_GET_FREE(chunk)->prev);
}
}
chunk = WMEM_CHUNK_NEXT(chunk);
} while (chunk);
g_assert(total_len == WMEM_BLOCK_SIZE);
return total_free_space;
}
static int
wmem_block_verify_master_list(wmem_block_allocator_t *allocator)
{
wmem_block_chunk_t *cur;
wmem_block_free_t *cur_free;
int free_space = 0;
cur = allocator->master_head;
if (!cur) {
return 0;
}
g_assert(WMEM_GET_FREE(cur)->prev == NULL);
while (cur) {
free_space += cur->len;
cur_free = WMEM_GET_FREE(cur);
g_assert(! cur->used);
if (cur_free->next) {
g_assert(WMEM_GET_FREE(cur_free->next)->prev == cur);
}
if (cur != allocator->master_head) {
g_assert(cur->len == WMEM_BLOCK_SIZE);
}
cur = cur_free->next;
}
return free_space;
}
static int
wmem_block_verify_recycler(wmem_block_allocator_t *allocator)
{
wmem_block_chunk_t *cur;
wmem_block_free_t *cur_free;
int free_space = 0;
cur = allocator->recycler_head;
if (!cur) {
return 0;
}
do {
free_space += cur->len;
cur_free = WMEM_GET_FREE(cur);
g_assert(! cur->used);
g_assert(cur_free->prev);
g_assert(cur_free->next);
g_assert(WMEM_GET_FREE(cur_free->prev)->next == cur);
g_assert(WMEM_GET_FREE(cur_free->next)->prev == cur);
cur = cur_free->next;
} while (cur != allocator->recycler_head);
return free_space;
}
void
wmem_block_verify(wmem_allocator_t *allocator)
{
wmem_block_hdr_t *cur;
wmem_block_allocator_t *private_allocator;
int master_free, recycler_free, chunk_free = 0;
g_assert(allocator->type == WMEM_ALLOCATOR_BLOCK);
private_allocator = (wmem_block_allocator_t*) allocator->private_data;
if (private_allocator->block_list == NULL) {
g_assert(! private_allocator->master_head);
g_assert(! private_allocator->recycler_head);
return;
}
master_free = wmem_block_verify_master_list(private_allocator);
recycler_free = wmem_block_verify_recycler(private_allocator);
cur = private_allocator->block_list;
g_assert(cur->prev == NULL);
while (cur) {
if (cur->next) {
g_assert(cur->next->prev == cur);
}
chunk_free += wmem_block_verify_block(cur);
cur = cur->next;
}
g_assert(chunk_free == master_free + recycler_free);
}
static void
wmem_block_cycle_recycler(wmem_block_allocator_t *allocator)
{
wmem_block_chunk_t *chunk;
wmem_block_free_t *free_chunk;
chunk = allocator->recycler_head;
if (chunk == NULL) {
return;
}
free_chunk = WMEM_GET_FREE(chunk);
if (free_chunk->next->len < chunk->len) {
WMEM_GET_FREE(free_chunk->next)->prev = free_chunk->prev;
WMEM_GET_FREE(free_chunk->prev)->next = free_chunk->next;
free_chunk->prev = free_chunk->next;
free_chunk->next = WMEM_GET_FREE(free_chunk->next)->next;
WMEM_GET_FREE(free_chunk->next)->prev = chunk;
WMEM_GET_FREE(free_chunk->prev)->next = chunk;
}
else {
allocator->recycler_head = free_chunk->next;
}
}
static void
wmem_block_add_to_recycler(wmem_block_allocator_t *allocator,
wmem_block_chunk_t *chunk)
{
wmem_block_free_t *free_chunk;
g_assert(! chunk->used);
if (WMEM_CHUNK_DATA_LEN(chunk) < sizeof(wmem_block_free_t)) {
return;
}
free_chunk = WMEM_GET_FREE(chunk);
if (! allocator->recycler_head) {
free_chunk->next = chunk;
free_chunk->prev = chunk;
allocator->recycler_head = chunk;
}
else {
free_chunk->next = allocator->recycler_head;
free_chunk->prev = WMEM_GET_FREE(allocator->recycler_head)->prev;
WMEM_GET_FREE(free_chunk->next)->prev = chunk;
WMEM_GET_FREE(free_chunk->prev)->next = chunk;
if (chunk->len > allocator->recycler_head->len) {
allocator->recycler_head = chunk;
}
}
}
static void
wmem_block_remove_from_recycler(wmem_block_allocator_t *allocator,
wmem_block_chunk_t *chunk)
{
wmem_block_free_t *free_chunk;
g_assert (! chunk->used);
free_chunk = WMEM_GET_FREE(chunk);
g_assert(free_chunk->prev && free_chunk->next);
if (free_chunk->prev == chunk && free_chunk->next == chunk) {
g_assert(allocator->recycler_head == chunk);
allocator->recycler_head = NULL;
}
else {
WMEM_GET_FREE(free_chunk->prev)->next = free_chunk->next;
WMEM_GET_FREE(free_chunk->next)->prev = free_chunk->prev;
if (allocator->recycler_head == chunk) {
allocator->recycler_head = free_chunk->next;
}
}
}
static void
wmem_block_push_master(wmem_block_allocator_t *allocator,
wmem_block_chunk_t *chunk)
{
wmem_block_free_t *free_chunk;
free_chunk = WMEM_GET_FREE(chunk);
free_chunk->prev = NULL;
free_chunk->next = allocator->master_head;
if (free_chunk->next) {
WMEM_GET_FREE(free_chunk->next)->prev = chunk;
}
allocator->master_head = chunk;
}
static void
wmem_block_pop_master(wmem_block_allocator_t *allocator)
{
wmem_block_chunk_t *chunk;
wmem_block_free_t *free_chunk;
chunk = allocator->master_head;
free_chunk = WMEM_GET_FREE(chunk);
allocator->master_head = free_chunk->next;
if (free_chunk->next) {
WMEM_GET_FREE(free_chunk->next)->prev = NULL;
}
}
static void
wmem_block_merge_free(wmem_block_allocator_t *allocator,
wmem_block_chunk_t *chunk)
{
wmem_block_chunk_t *tmp;
wmem_block_chunk_t *left_free = NULL;
wmem_block_chunk_t *right_free = NULL;
g_assert(!chunk->used);
tmp = WMEM_CHUNK_NEXT(chunk);
if (tmp && !tmp->used) {
if (WMEM_CHUNK_DATA_LEN(tmp) >= sizeof(wmem_block_free_t)) {
right_free = tmp;
}
chunk->len += tmp->len;
chunk->last = tmp->last;
}
tmp = WMEM_CHUNK_PREV(chunk);
if (tmp && !tmp->used) {
if (WMEM_CHUNK_DATA_LEN(tmp) >= sizeof(wmem_block_free_t)) {
left_free = tmp;
}
tmp->len += chunk->len;
tmp->last = chunk->last;
chunk = tmp;
}
if (!chunk->last) {
WMEM_CHUNK_NEXT(chunk)->prev = chunk->len;
}
if (right_free && right_free == allocator->master_head) {
wmem_block_free_t *moved;
if (left_free) {
wmem_block_remove_from_recycler(allocator, left_free);
}
moved = WMEM_GET_FREE(chunk);
moved->prev = NULL;
moved->next = WMEM_GET_FREE(right_free)->next;
allocator->master_head = chunk;
if (moved->next) {
WMEM_GET_FREE(moved->next)->prev = chunk;
}
}
else {
if (right_free) {
wmem_block_remove_from_recycler(allocator, right_free);
}
if (!left_free) {
wmem_block_add_to_recycler(allocator, chunk);
}
}
}
static void
wmem_block_split_free_chunk(wmem_block_allocator_t *allocator,
wmem_block_chunk_t *chunk,
const size_t size)
{
wmem_block_chunk_t *extra;
wmem_block_free_t *old_blk, *new_blk;
size_t aligned_size, available;
gboolean last;
g_assert(!chunk->used);
g_assert(WMEM_CHUNK_DATA_LEN(chunk) >= size);
aligned_size = WMEM_ALIGN_SIZE(size) + WMEM_CHUNK_HEADER_SIZE;
if (WMEM_CHUNK_DATA_LEN(chunk) < aligned_size + sizeof(wmem_block_free_t)) {
if (chunk == allocator->master_head) {
wmem_block_pop_master(allocator);
}
else {
wmem_block_remove_from_recycler(allocator, chunk);
}
return;
}
last = chunk->last;
available = chunk->len - aligned_size;
chunk->len = (guint32) aligned_size;
chunk->last = FALSE;
extra = WMEM_CHUNK_NEXT(chunk);
old_blk = WMEM_GET_FREE(chunk);
new_blk = WMEM_GET_FREE(extra);
if (allocator->master_head == chunk) {
new_blk->prev = old_blk->prev;
new_blk->next = old_blk->next;
if (old_blk->next) {
WMEM_GET_FREE(old_blk->next)->prev = extra;
}
allocator->master_head = extra;
}
else {
if (old_blk->prev == chunk) {
new_blk->prev = extra;
new_blk->next = extra;
}
else {
new_blk->prev = old_blk->prev;
new_blk->next = old_blk->next;
WMEM_GET_FREE(old_blk->prev)->next = extra;
WMEM_GET_FREE(old_blk->next)->prev = extra;
}
if (allocator->recycler_head == chunk) {
allocator->recycler_head = extra;
}
}
extra->len = (guint32) available;
extra->last = last;
extra->prev = chunk->len;
extra->used = FALSE;
extra->jumbo = FALSE;
if (!last) {
WMEM_CHUNK_NEXT(extra)->prev = extra->len;
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
aligned_size = WMEM_ALIGN_SIZE(size) + WMEM_CHUNK_HEADER_SIZE;
if (aligned_size > WMEM_CHUNK_DATA_LEN(chunk)) {
return;
}
last = chunk->last;
available = chunk->len - aligned_size;
chunk->len = (guint32) aligned_size;
chunk->last = FALSE;
extra = WMEM_CHUNK_NEXT(chunk);
extra->len = (guint32) available;
extra->last = last;
extra->prev = chunk->len;
extra->used = FALSE;
extra->jumbo = FALSE;
if (!last) {
WMEM_CHUNK_NEXT(extra)->prev = extra->len;
}
wmem_block_merge_free(allocator, extra);
}
static void
wmem_block_add_to_block_list(wmem_block_allocator_t *allocator,
wmem_block_hdr_t *block)
{
block->prev = NULL;
block->next = allocator->block_list;
if (block->next) {
block->next->prev = block;
}
allocator->block_list = block;
}
static void
wmem_block_remove_from_block_list(wmem_block_allocator_t *allocator,
wmem_block_hdr_t *block)
{
if (block->prev) {
block->prev->next = block->next;
}
else {
allocator->block_list = block->next;
}
if (block->next) {
block->next->prev = block->prev;
}
}
static void
wmem_block_init_block(wmem_block_allocator_t *allocator,
wmem_block_hdr_t *block)
{
wmem_block_chunk_t *chunk;
chunk = WMEM_BLOCK_TO_CHUNK(block);
chunk->used = FALSE;
chunk->jumbo = FALSE;
chunk->last = TRUE;
chunk->prev = 0;
chunk->len = WMEM_BLOCK_SIZE - WMEM_BLOCK_HEADER_SIZE;
wmem_block_push_master(allocator, chunk);
}
static void
wmem_block_new_block(wmem_block_allocator_t *allocator)
{
wmem_block_hdr_t *block;
block = (wmem_block_hdr_t *)wmem_alloc(NULL, WMEM_BLOCK_SIZE);
wmem_block_add_to_block_list(allocator, block);
wmem_block_init_block(allocator, block);
}
static void *
wmem_block_alloc_jumbo(wmem_block_allocator_t *allocator, const size_t size)
{
wmem_block_hdr_t *block;
wmem_block_chunk_t *chunk;
block = (wmem_block_hdr_t *) wmem_alloc(NULL, size
+ WMEM_BLOCK_HEADER_SIZE
+ WMEM_CHUNK_HEADER_SIZE);
wmem_block_add_to_block_list(allocator, block);
chunk = WMEM_BLOCK_TO_CHUNK(block);
chunk->last = TRUE;
chunk->used = TRUE;
chunk->jumbo = TRUE;
chunk->len = 0;
chunk->prev = 0;
return WMEM_CHUNK_TO_DATA(chunk);
}
static void
wmem_block_free_jumbo(wmem_block_allocator_t *allocator,
wmem_block_chunk_t *chunk)
{
wmem_block_hdr_t *block;
block = WMEM_CHUNK_TO_BLOCK(chunk);
wmem_block_remove_from_block_list(allocator, block);
wmem_free(NULL, block);
}
static void *
wmem_block_realloc_jumbo(wmem_block_allocator_t *allocator,
wmem_block_chunk_t *chunk,
const size_t size)
{
wmem_block_hdr_t *block;
block = WMEM_CHUNK_TO_BLOCK(chunk);
block = (wmem_block_hdr_t *) wmem_realloc(NULL, block, size
+ WMEM_BLOCK_HEADER_SIZE
+ WMEM_CHUNK_HEADER_SIZE);
if (block->next) {
block->next->prev = block;
}
if (block->prev) {
block->prev->next = block;
}
else {
allocator->block_list = block;
}
return WMEM_CHUNK_TO_DATA(WMEM_BLOCK_TO_CHUNK(block));
}
static void *
wmem_block_alloc(void *private_data, const size_t size)
{
wmem_block_allocator_t *allocator = (wmem_block_allocator_t*) private_data;
wmem_block_chunk_t *chunk;
if (size > WMEM_BLOCK_MAX_ALLOC_SIZE) {
return wmem_block_alloc_jumbo(allocator, size);
}
if (allocator->recycler_head &&
WMEM_CHUNK_DATA_LEN(allocator->recycler_head) >= size) {
chunk = allocator->recycler_head;
}
else {
if (allocator->master_head &&
WMEM_CHUNK_DATA_LEN(allocator->master_head) < size) {
chunk = allocator->master_head;
wmem_block_pop_master(allocator);
wmem_block_add_to_recycler(allocator, chunk);
}
if (!allocator->master_head) {
wmem_block_new_block(allocator);
}
chunk = allocator->master_head;
}
g_assert(! chunk->used);
g_assert(size <= WMEM_CHUNK_DATA_LEN(chunk));
wmem_block_split_free_chunk(allocator, chunk, size);
g_assert(size <= WMEM_CHUNK_DATA_LEN(chunk));
g_assert(chunk != allocator->master_head);
g_assert(chunk != allocator->recycler_head);
wmem_block_cycle_recycler(allocator);
chunk->used = TRUE;
return WMEM_CHUNK_TO_DATA(chunk);
}
static void
wmem_block_free(void *private_data, void *ptr)
{
wmem_block_allocator_t *allocator = (wmem_block_allocator_t*) private_data;
wmem_block_chunk_t *chunk;
chunk = WMEM_DATA_TO_CHUNK(ptr);
if (chunk->jumbo) {
wmem_block_free_jumbo(allocator, chunk);
return;
}
g_assert(chunk->used);
chunk->used = FALSE;
wmem_block_merge_free(allocator, chunk);
wmem_block_cycle_recycler(allocator);
}
static void *
wmem_block_realloc(void *private_data, void *ptr, const size_t size)
{
wmem_block_allocator_t *allocator = (wmem_block_allocator_t*) private_data;
wmem_block_chunk_t *chunk;
chunk = WMEM_DATA_TO_CHUNK(ptr);
if (chunk->jumbo) {
return wmem_block_realloc_jumbo(allocator, chunk, size);
}
g_assert(chunk->used);
if (size > WMEM_CHUNK_DATA_LEN(chunk)) {
wmem_block_chunk_t *tmp;
tmp = WMEM_CHUNK_NEXT(chunk);
if (tmp && (!tmp->used) &&
(size < WMEM_CHUNK_DATA_LEN(chunk) + tmp->len)) {
size_t split_size;
split_size = size - WMEM_CHUNK_DATA_LEN(chunk);
if (split_size < WMEM_CHUNK_HEADER_SIZE) {
split_size = 0;
}
else {
split_size -= WMEM_CHUNK_HEADER_SIZE;
}
wmem_block_split_free_chunk(allocator, tmp, split_size);
chunk->len += tmp->len;
chunk->last = tmp->last;
tmp = WMEM_CHUNK_NEXT(chunk);
if (tmp) {
tmp->prev = chunk->len;
}
wmem_block_cycle_recycler(allocator);
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
wmem_block_cycle_recycler(allocator);
return ptr;
}
return ptr;
}
static void
wmem_block_free_all(void *private_data)
{
wmem_block_allocator_t *allocator = (wmem_block_allocator_t*) private_data;
wmem_block_hdr_t *cur;
wmem_block_chunk_t *chunk;
allocator->master_head = NULL;
allocator->recycler_head = NULL;
cur = allocator->block_list;
while (cur) {
chunk = WMEM_BLOCK_TO_CHUNK(cur);
if (chunk->jumbo) {
wmem_block_remove_from_block_list(allocator, cur);
cur = cur->next;
wmem_free(NULL, WMEM_CHUNK_TO_BLOCK(chunk));
}
else {
wmem_block_init_block(allocator, cur);
cur = cur->next;
}
}
}
static void
wmem_block_gc(void *private_data)
{
wmem_block_allocator_t *allocator = (wmem_block_allocator_t*) private_data;
wmem_block_hdr_t *cur, *next;
wmem_block_chunk_t *chunk;
wmem_block_free_t *free_chunk;
cur = allocator->block_list;
allocator->block_list = NULL;
while (cur) {
chunk = WMEM_BLOCK_TO_CHUNK(cur);
next = cur->next;
if (!chunk->jumbo && !chunk->used && chunk->last) {
free_chunk = WMEM_GET_FREE(chunk);
if (free_chunk->next) {
WMEM_GET_FREE(free_chunk->next)->prev = free_chunk->prev;
}
if (free_chunk->prev) {
WMEM_GET_FREE(free_chunk->prev)->next = free_chunk->next;
}
if (allocator->recycler_head == chunk) {
if (free_chunk->next == chunk) {
allocator->recycler_head = NULL;
}
else {
allocator->recycler_head = free_chunk->next;
}
}
else if (allocator->master_head == chunk) {
allocator->master_head = free_chunk->next;
}
wmem_free(NULL, cur);
}
else {
wmem_block_add_to_block_list(allocator, cur);
}
cur = next;
}
}
static void
wmem_block_allocator_cleanup(void *private_data)
{
wmem_block_gc(private_data);
wmem_free(NULL, private_data);
}
void
wmem_block_allocator_init(wmem_allocator_t *allocator)
{
wmem_block_allocator_t *block_allocator;
block_allocator = wmem_new(NULL, wmem_block_allocator_t);
allocator->alloc = &wmem_block_alloc;
allocator->realloc = &wmem_block_realloc;
allocator->free = &wmem_block_free;
allocator->free_all = &wmem_block_free_all;
allocator->gc = &wmem_block_gc;
allocator->cleanup = &wmem_block_allocator_cleanup;
allocator->private_data = (void*) block_allocator;
block_allocator->block_list = NULL;
block_allocator->master_head = NULL;
block_allocator->recycler_head = NULL;
}
