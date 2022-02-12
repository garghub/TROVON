void *
wmem_alloc(wmem_allocator_t *allocator, const size_t size)
{
if (allocator == NULL) {
return g_malloc(size);
}
if (size == 0) {
return NULL;
}
return allocator->alloc(allocator->private_data, size);
}
void *
wmem_alloc0(wmem_allocator_t *allocator, const size_t size)
{
void *buf;
if (size == 0) {
return NULL;
}
buf = wmem_alloc(allocator, size);
memset(buf, 0, size);
return buf;
}
void
wmem_free(wmem_allocator_t *allocator, void *ptr)
{
if (allocator == NULL) {
g_free(ptr);
return;
}
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
return allocator->realloc(allocator->private_data, ptr, size);
}
void
wmem_free_all(wmem_allocator_t *allocator)
{
allocator->free_all(allocator->private_data);
}
void
wmem_gc(wmem_allocator_t *allocator)
{
allocator->gc(allocator->private_data);
}
void
wmem_destroy_allocator(wmem_allocator_t *allocator)
{
wmem_free_all(allocator);
allocator->destroy(allocator);
}
wmem_allocator_t *
wmem_allocator_new(const wmem_allocator_type_t type)
{
const char *override;
wmem_allocator_t *allocator;
wmem_allocator_type_t real_type;
override = getenv("WIRESHARK_DEBUG_WMEM_OVERRIDE");
if (override == NULL) {
real_type = type;
}
else if (strncmp(override, "simple", strlen("simple")) == 0) {
real_type = WMEM_ALLOCATOR_SIMPLE;
}
else if (strncmp(override, "block", strlen("block")) == 0) {
real_type = WMEM_ALLOCATOR_BLOCK;
}
else if (strncmp(override, "strict", strlen("strict")) == 0) {
real_type = WMEM_ALLOCATOR_STRICT;
}
else {
g_warning("Unrecognized wmem override");
real_type = type;
}
switch (real_type) {
case WMEM_ALLOCATOR_SIMPLE:
allocator = wmem_simple_allocator_new();
break;
case WMEM_ALLOCATOR_BLOCK:
allocator = wmem_block_allocator_new();
break;
case WMEM_ALLOCATOR_STRICT:
allocator = wmem_strict_allocator_new();
break;
default:
g_assert_not_reached();
return NULL;
};
allocator->type = real_type;
return allocator;
}
void
wmem_init(void)
{
wmem_init_scopes();
}
void
wmem_cleanup(void)
{
wmem_cleanup_scopes();
}
