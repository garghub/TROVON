acpi_status
acpi_ut_create_list(const char *list_name,
u16 object_size, struct acpi_memory_list **return_cache)
{
struct acpi_memory_list *cache;
cache = acpi_os_allocate(sizeof(struct acpi_memory_list));
if (!cache) {
return (AE_NO_MEMORY);
}
memset(cache, 0, sizeof(struct acpi_memory_list));
cache->list_name = list_name;
cache->object_size = object_size;
*return_cache = cache;
return (AE_OK);
}
void *acpi_ut_allocate_and_track(acpi_size size,
u32 component, const char *module, u32 line)
{
struct acpi_debug_mem_block *allocation;
acpi_status status;
if (!size) {
ACPI_WARNING((module, line,
"Attempt to allocate zero bytes, allocating 1 byte"));
size = 1;
}
allocation =
acpi_os_allocate(size + sizeof(struct acpi_debug_mem_header));
if (!allocation) {
ACPI_WARNING((module, line,
"Could not allocate size %u", (u32)size));
return (NULL);
}
status =
acpi_ut_track_allocation(allocation, size, ACPI_MEM_MALLOC,
component, module, line);
if (ACPI_FAILURE(status)) {
acpi_os_free(allocation);
return (NULL);
}
acpi_gbl_global_list->total_allocated++;
acpi_gbl_global_list->total_size += (u32)size;
acpi_gbl_global_list->current_total_size += (u32)size;
if (acpi_gbl_global_list->current_total_size >
acpi_gbl_global_list->max_occupied) {
acpi_gbl_global_list->max_occupied =
acpi_gbl_global_list->current_total_size;
}
return ((void *)&allocation->user_space);
}
void *acpi_ut_allocate_zeroed_and_track(acpi_size size,
u32 component,
const char *module, u32 line)
{
struct acpi_debug_mem_block *allocation;
acpi_status status;
if (!size) {
ACPI_WARNING((module, line,
"Attempt to allocate zero bytes, allocating 1 byte"));
size = 1;
}
allocation =
acpi_os_allocate_zeroed(size +
sizeof(struct acpi_debug_mem_header));
if (!allocation) {
ACPI_ERROR((module, line,
"Could not allocate size %u", (u32)size));
return (NULL);
}
status = acpi_ut_track_allocation(allocation, size,
ACPI_MEM_CALLOC, component, module,
line);
if (ACPI_FAILURE(status)) {
acpi_os_free(allocation);
return (NULL);
}
acpi_gbl_global_list->total_allocated++;
acpi_gbl_global_list->total_size += (u32)size;
acpi_gbl_global_list->current_total_size += (u32)size;
if (acpi_gbl_global_list->current_total_size >
acpi_gbl_global_list->max_occupied) {
acpi_gbl_global_list->max_occupied =
acpi_gbl_global_list->current_total_size;
}
return ((void *)&allocation->user_space);
}
void
acpi_ut_free_and_track(void *allocation,
u32 component, const char *module, u32 line)
{
struct acpi_debug_mem_block *debug_block;
acpi_status status;
ACPI_FUNCTION_TRACE_PTR(ut_free, allocation);
if (NULL == allocation) {
ACPI_ERROR((module, line, "Attempt to delete a NULL address"));
return_VOID;
}
debug_block = ACPI_CAST_PTR(struct acpi_debug_mem_block,
(((char *)allocation) -
sizeof(struct acpi_debug_mem_header)));
acpi_gbl_global_list->total_freed++;
acpi_gbl_global_list->current_total_size -= debug_block->size;
status =
acpi_ut_remove_allocation(debug_block, component, module, line);
if (ACPI_FAILURE(status)) {
ACPI_EXCEPTION((AE_INFO, status, "Could not free memory"));
}
acpi_os_free(debug_block);
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS, "%p freed (block %p)\n",
allocation, debug_block));
return_VOID;
}
static struct acpi_debug_mem_block *acpi_ut_find_allocation(struct
acpi_debug_mem_block
*allocation)
{
struct acpi_debug_mem_block *element;
element = acpi_gbl_global_list->list_head;
if (!element) {
return (NULL);
}
while (element > allocation) {
if (!element->next) {
return (element);
}
element = element->next;
}
if (element == allocation) {
return (element);
}
return (element->previous);
}
static acpi_status
acpi_ut_track_allocation(struct acpi_debug_mem_block *allocation,
acpi_size size,
u8 alloc_type,
u32 component, const char *module, u32 line)
{
struct acpi_memory_list *mem_list;
struct acpi_debug_mem_block *element;
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE_PTR(ut_track_allocation, allocation);
if (acpi_gbl_disable_mem_tracking) {
return_ACPI_STATUS(AE_OK);
}
mem_list = acpi_gbl_global_list;
status = acpi_ut_acquire_mutex(ACPI_MTX_MEMORY);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
element = acpi_ut_find_allocation(allocation);
if (element == allocation) {
ACPI_ERROR((AE_INFO,
"UtTrackAllocation: Allocation (%p) already present in global list!",
allocation));
goto unlock_and_exit;
}
allocation->size = (u32)size;
allocation->alloc_type = alloc_type;
allocation->component = component;
allocation->line = line;
strncpy(allocation->module, module, ACPI_MAX_MODULE_NAME);
allocation->module[ACPI_MAX_MODULE_NAME - 1] = 0;
if (!element) {
if (mem_list->list_head) {
((struct acpi_debug_mem_block *)(mem_list->list_head))->
previous = allocation;
}
allocation->next = mem_list->list_head;
allocation->previous = NULL;
mem_list->list_head = allocation;
} else {
allocation->next = element->next;
allocation->previous = element;
if (element->next) {
(element->next)->previous = allocation;
}
element->next = allocation;
}
unlock_and_exit:
status = acpi_ut_release_mutex(ACPI_MTX_MEMORY);
return_ACPI_STATUS(status);
}
static acpi_status
acpi_ut_remove_allocation(struct acpi_debug_mem_block *allocation,
u32 component, const char *module, u32 line)
{
struct acpi_memory_list *mem_list;
acpi_status status;
ACPI_FUNCTION_NAME(ut_remove_allocation);
if (acpi_gbl_disable_mem_tracking) {
return (AE_OK);
}
mem_list = acpi_gbl_global_list;
if (NULL == mem_list->list_head) {
ACPI_ERROR((module, line,
"Empty allocation list, nothing to free!"));
return (AE_OK);
}
status = acpi_ut_acquire_mutex(ACPI_MTX_MEMORY);
if (ACPI_FAILURE(status)) {
return (status);
}
if (allocation->previous) {
(allocation->previous)->next = allocation->next;
} else {
mem_list->list_head = allocation->next;
}
if (allocation->next) {
(allocation->next)->previous = allocation->previous;
}
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS, "Freeing %p, size 0%X\n",
&allocation->user_space, allocation->size));
memset(&allocation->user_space, 0xEA, allocation->size);
status = acpi_ut_release_mutex(ACPI_MTX_MEMORY);
return (status);
}
void acpi_ut_dump_allocation_info(void)
{
ACPI_FUNCTION_TRACE(ut_dump_allocation_info);
return_VOID;
}
void acpi_ut_dump_allocations(u32 component, const char *module)
{
struct acpi_debug_mem_block *element;
union acpi_descriptor *descriptor;
u32 num_outstanding = 0;
u8 descriptor_type;
ACPI_FUNCTION_TRACE(ut_dump_allocations);
if (acpi_gbl_disable_mem_tracking) {
return_VOID;
}
if (ACPI_FAILURE(acpi_ut_acquire_mutex(ACPI_MTX_MEMORY))) {
return_VOID;
}
element = acpi_gbl_global_list->list_head;
while (element) {
if ((element->component & component) &&
((module == NULL)
|| (0 == strcmp(module, element->module)))) {
descriptor =
ACPI_CAST_PTR(union acpi_descriptor,
&element->user_space);
if (element->size <
sizeof(struct acpi_common_descriptor)) {
acpi_os_printf("%p Length 0x%04X %9.9s-%u "
"[Not a Descriptor - too small]\n",
descriptor, element->size,
element->module, element->line);
} else {
if (ACPI_GET_DESCRIPTOR_TYPE(descriptor) !=
ACPI_DESC_TYPE_CACHED) {
acpi_os_printf
("%p Length 0x%04X %9.9s-%u [%s] ",
descriptor, element->size,
element->module, element->line,
acpi_ut_get_descriptor_name
(descriptor));
descriptor_type = 0;
switch (ACPI_GET_DESCRIPTOR_TYPE
(descriptor)) {
case ACPI_DESC_TYPE_OPERAND:
if (element->size ==
sizeof(union
acpi_operand_object))
{
descriptor_type =
ACPI_DESC_TYPE_OPERAND;
}
break;
case ACPI_DESC_TYPE_PARSER:
if (element->size ==
sizeof(union
acpi_parse_object)) {
descriptor_type =
ACPI_DESC_TYPE_PARSER;
}
break;
case ACPI_DESC_TYPE_NAMED:
if (element->size ==
sizeof(struct
acpi_namespace_node))
{
descriptor_type =
ACPI_DESC_TYPE_NAMED;
}
break;
default:
break;
}
switch (descriptor_type) {
case ACPI_DESC_TYPE_OPERAND:
acpi_os_printf
("%12.12s RefCount 0x%04X\n",
acpi_ut_get_type_name
(descriptor->object.common.
type),
descriptor->object.common.
reference_count);
break;
case ACPI_DESC_TYPE_PARSER:
acpi_os_printf
("AmlOpcode 0x%04hX\n",
descriptor->op.asl.
aml_opcode);
break;
case ACPI_DESC_TYPE_NAMED:
acpi_os_printf("%4.4s\n",
acpi_ut_get_node_name
(&descriptor->
node));
break;
default:
acpi_os_printf("\n");
break;
}
}
}
num_outstanding++;
}
element = element->next;
}
(void)acpi_ut_release_mutex(ACPI_MTX_MEMORY);
if (!num_outstanding) {
ACPI_INFO(("No outstanding allocations"));
} else {
ACPI_ERROR((AE_INFO, "%u(0x%X) Outstanding allocations",
num_outstanding, num_outstanding));
}
return_VOID;
}
