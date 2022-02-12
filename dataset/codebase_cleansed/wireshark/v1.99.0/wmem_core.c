void *
wmem_alloc(wmem_allocator_t *allocator, const size_t size)
{
if (allocator == NULL) {
return g_malloc(size);
}
g_assert(allocator->in_scope);
if (size == 0) {
return NULL;
}
return allocator->alloc(allocator->private_data, size);
}
void *
wmem_alloc0(wmem_allocator_t *allocator, const size_t size)
{
void *buf;
buf = wmem_alloc(allocator, size);
if (buf) {
memset(buf, 0, size);
}
return buf;
}
void
wmem_free(wmem_allocator_t *allocator, void *ptr)
{
if (allocator == NULL) {
g_free(ptr);
return;
}
g_assert(allocator->in_scope);
if (ptr == NULL) {
return;
}
allocator->free(allocator->private_data, ptr);
}
void *
wmem_realloc(wmem_allocator_t *allocator, void *ptr, const size_t size)
{
if (allocator == NULL) {
return g_realloc(ptr, size);
}
if (ptr == NULL) {
return wmem_alloc(allocator, size);
}
if (size == 0) {
wmem_free(allocator, ptr);
return NULL;
}
g_assert(allocator->in_scope);
return allocator->realloc(allocator->private_data, ptr, size);
}
static void
wmem_free_all_real(wmem_allocator_t *allocator, gboolean final)
{
wmem_call_callbacks(allocator,
final ? WMEM_CB_DESTROY_EVENT : WMEM_CB_FREE_EVENT);
allocator->free_all(allocator->private_data);
}
void
wmem_free_all(wmem_allocator_t *allocator)
{
wmem_free_all_real(allocator, FALSE);
}
void
wmem_gc(wmem_allocator_t *allocator)
{
allocator->gc(allocator->private_data);
}
void
wmem_destroy_allocator(wmem_allocator_t *allocator)
{
wmem_free_all_real(allocator, TRUE);
allocator->cleanup(allocator->private_data);
wmem_free(NULL, allocator);
}
wmem_allocator_t *
wmem_allocator_new(const wmem_allocator_type_t type)
{
wmem_allocator_t *allocator;
wmem_allocator_type_t real_type;
if (do_override) {
real_type = override_type;
}
else {
real_type = type;
}
allocator = wmem_new(NULL, wmem_allocator_t);
allocator->type = real_type;
allocator->callbacks = NULL;
allocator->in_scope = TRUE;
switch (real_type) {
case WMEM_ALLOCATOR_SIMPLE:
wmem_simple_allocator_init(allocator);
break;
case WMEM_ALLOCATOR_BLOCK:
wmem_block_allocator_init(allocator);
break;
case WMEM_ALLOCATOR_BLOCK_FAST:
wmem_block_fast_allocator_init(allocator);
break;
case WMEM_ALLOCATOR_STRICT:
wmem_strict_allocator_init(allocator);
break;
default:
g_assert_not_reached();
return NULL;
};
return allocator;
}
void
wmem_init(void)
{
const char *override_env;
override_env = getenv("WIRESHARK_DEBUG_WMEM_OVERRIDE");
if (override_env == NULL) {
do_override = FALSE;
}
else {
do_override = TRUE;
if (strncmp(override_env, "simple", strlen("simple")) == 0) {
override_type = WMEM_ALLOCATOR_SIMPLE;
}
else if (strncmp(override_env, "block", strlen("block")) == 0) {
override_type = WMEM_ALLOCATOR_BLOCK;
}
else if (strncmp(override_env, "strict", strlen("strict")) == 0) {
override_type = WMEM_ALLOCATOR_STRICT;
}
else if (strncmp(override_env, "block_fast", strlen("block_fast")) == 0) {
override_type = WMEM_ALLOCATOR_BLOCK_FAST;
}
else {
g_warning("Unrecognized wmem override");
do_override = FALSE;
}
}
wmem_init_scopes();
wmem_init_hashing();
}
void
wmem_cleanup(void)
{
wmem_cleanup_scopes();
}
