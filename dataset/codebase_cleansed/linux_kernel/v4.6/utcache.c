acpi_status
acpi_os_create_cache(char *cache_name,
u16 object_size,
u16 max_depth, struct acpi_memory_list **return_cache)
{
struct acpi_memory_list *cache;
ACPI_FUNCTION_ENTRY();
if (!cache_name || !return_cache || (object_size < 16)) {
return (AE_BAD_PARAMETER);
}
cache = acpi_os_allocate(sizeof(struct acpi_memory_list));
if (!cache) {
return (AE_NO_MEMORY);
}
memset(cache, 0, sizeof(struct acpi_memory_list));
cache->list_name = cache_name;
cache->object_size = object_size;
cache->max_depth = max_depth;
*return_cache = cache;
return (AE_OK);
}
acpi_status acpi_os_purge_cache(struct acpi_memory_list * cache)
{
void *next;
acpi_status status;
ACPI_FUNCTION_ENTRY();
if (!cache) {
return (AE_BAD_PARAMETER);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_CACHES);
if (ACPI_FAILURE(status)) {
return (status);
}
while (cache->list_head) {
next = ACPI_GET_DESCRIPTOR_PTR(cache->list_head);
ACPI_FREE(cache->list_head);
cache->list_head = next;
cache->current_depth--;
}
(void)acpi_ut_release_mutex(ACPI_MTX_CACHES);
return (AE_OK);
}
acpi_status acpi_os_delete_cache(struct acpi_memory_list * cache)
{
acpi_status status;
ACPI_FUNCTION_ENTRY();
status = acpi_os_purge_cache(cache);
if (ACPI_FAILURE(status)) {
return (status);
}
acpi_os_free(cache);
return (AE_OK);
}
acpi_status
acpi_os_release_object(struct acpi_memory_list * cache, void *object)
{
acpi_status status;
ACPI_FUNCTION_ENTRY();
if (!cache || !object) {
return (AE_BAD_PARAMETER);
}
if (cache->current_depth >= cache->max_depth) {
ACPI_FREE(object);
ACPI_MEM_TRACKING(cache->total_freed++);
}
else {
status = acpi_ut_acquire_mutex(ACPI_MTX_CACHES);
if (ACPI_FAILURE(status)) {
return (status);
}
memset(object, 0xCA, cache->object_size);
ACPI_SET_DESCRIPTOR_TYPE(object, ACPI_DESC_TYPE_CACHED);
ACPI_SET_DESCRIPTOR_PTR(object, cache->list_head);
cache->list_head = object;
cache->current_depth++;
(void)acpi_ut_release_mutex(ACPI_MTX_CACHES);
}
return (AE_OK);
}
void *acpi_os_acquire_object(struct acpi_memory_list *cache)
{
acpi_status status;
void *object;
ACPI_FUNCTION_TRACE(os_acquire_object);
if (!cache) {
return_PTR(NULL);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_CACHES);
if (ACPI_FAILURE(status)) {
return_PTR(NULL);
}
ACPI_MEM_TRACKING(cache->requests++);
if (cache->list_head) {
object = cache->list_head;
cache->list_head = ACPI_GET_DESCRIPTOR_PTR(object);
cache->current_depth--;
ACPI_MEM_TRACKING(cache->hits++);
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"Object %p from %s cache\n", object,
cache->list_name));
status = acpi_ut_release_mutex(ACPI_MTX_CACHES);
if (ACPI_FAILURE(status)) {
return_PTR(NULL);
}
memset(object, 0, cache->object_size);
} else {
ACPI_MEM_TRACKING(cache->total_allocated++);
#ifdef ACPI_DBG_TRACK_ALLOCATIONS
if ((cache->total_allocated - cache->total_freed) >
cache->max_occupied) {
cache->max_occupied =
cache->total_allocated - cache->total_freed;
}
#endif
status = acpi_ut_release_mutex(ACPI_MTX_CACHES);
if (ACPI_FAILURE(status)) {
return_PTR(NULL);
}
object = ACPI_ALLOCATE_ZEROED(cache->object_size);
if (!object) {
return_PTR(NULL);
}
}
return_PTR(object);
}
