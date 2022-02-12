static void acpi_ut_delete_internal_obj(union acpi_operand_object *object)
{
void *obj_pointer = NULL;
union acpi_operand_object *handler_desc;
union acpi_operand_object *second_desc;
union acpi_operand_object *next_desc;
union acpi_operand_object *start_desc;
union acpi_operand_object **last_obj_ptr;
ACPI_FUNCTION_TRACE_PTR(ut_delete_internal_obj, object);
if (!object) {
return_VOID;
}
switch (object->common.type) {
case ACPI_TYPE_STRING:
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"**** String %p, ptr %p\n", object,
object->string.pointer));
if (!(object->common.flags & AOPOBJ_STATIC_POINTER)) {
obj_pointer = object->string.pointer;
}
break;
case ACPI_TYPE_BUFFER:
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"**** Buffer %p, ptr %p\n", object,
object->buffer.pointer));
if (!(object->common.flags & AOPOBJ_STATIC_POINTER)) {
obj_pointer = object->buffer.pointer;
}
break;
case ACPI_TYPE_PACKAGE:
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
" **** Package of count %X\n",
object->package.count));
obj_pointer = object->package.elements;
break;
case ACPI_TYPE_DEVICE:
if (object->device.gpe_block) {
(void)acpi_ev_delete_gpe_block(object->device.
gpe_block);
}
case ACPI_TYPE_PROCESSOR:
case ACPI_TYPE_THERMAL:
handler_desc = object->common_notify.handler;
while (handler_desc) {
next_desc = handler_desc->address_space.next;
acpi_ut_remove_reference(handler_desc);
handler_desc = next_desc;
}
break;
case ACPI_TYPE_MUTEX:
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"***** Mutex %p, OS Mutex %p\n",
object, object->mutex.os_mutex));
if (object == acpi_gbl_global_lock_mutex) {
(void)
acpi_os_delete_semaphore
(acpi_gbl_global_lock_semaphore);
acpi_gbl_global_lock_semaphore = NULL;
acpi_os_delete_mutex(object->mutex.os_mutex);
acpi_gbl_global_lock_mutex = NULL;
} else {
acpi_ex_unlink_mutex(object);
acpi_os_delete_mutex(object->mutex.os_mutex);
}
break;
case ACPI_TYPE_EVENT:
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"***** Event %p, OS Semaphore %p\n",
object, object->event.os_semaphore));
(void)acpi_os_delete_semaphore(object->event.os_semaphore);
object->event.os_semaphore = NULL;
break;
case ACPI_TYPE_METHOD:
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"***** Method %p\n", object));
if (object->method.mutex) {
acpi_os_delete_mutex(object->method.mutex->mutex.
os_mutex);
acpi_ut_delete_object_desc(object->method.mutex);
object->method.mutex = NULL;
}
break;
case ACPI_TYPE_REGION:
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"***** Region %p\n", object));
if (!(object->region.node->flags & ANOBJ_TEMPORARY)) {
acpi_ut_remove_address_range(object->region.space_id,
object->region.node);
}
second_desc = acpi_ns_get_secondary_object(object);
if (second_desc) {
handler_desc = object->region.handler;
if (handler_desc) {
next_desc =
handler_desc->address_space.region_list;
start_desc = next_desc;
last_obj_ptr =
&handler_desc->address_space.region_list;
while (next_desc) {
if (next_desc == object) {
*last_obj_ptr =
next_desc->region.next;
break;
}
last_obj_ptr = &next_desc->region.next;
next_desc = next_desc->region.next;
if (next_desc == start_desc) {
ACPI_ERROR((AE_INFO,
"Circular region list in address handler object %p",
handler_desc));
return_VOID;
}
}
if (handler_desc->address_space.handler_flags &
ACPI_ADDR_HANDLER_DEFAULT_INSTALLED) {
if (handler_desc->address_space.setup) {
(void)handler_desc->
address_space.setup(object,
ACPI_REGION_DEACTIVATE,
handler_desc->
address_space.
context,
&second_desc->
extra.
region_context);
}
}
acpi_ut_remove_reference(handler_desc);
}
acpi_ut_delete_object_desc(second_desc);
}
break;
case ACPI_TYPE_BUFFER_FIELD:
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"***** Buffer Field %p\n", object));
second_desc = acpi_ns_get_secondary_object(object);
if (second_desc) {
acpi_ut_delete_object_desc(second_desc);
}
break;
case ACPI_TYPE_LOCAL_BANK_FIELD:
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"***** Bank Field %p\n", object));
second_desc = acpi_ns_get_secondary_object(object);
if (second_desc) {
acpi_ut_delete_object_desc(second_desc);
}
break;
default:
break;
}
if (obj_pointer) {
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Deleting Object Subptr %p\n", obj_pointer));
ACPI_FREE(obj_pointer);
}
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS, "Deleting Object %p [%s]\n",
object, acpi_ut_get_object_type_name(object)));
acpi_ut_delete_object_desc(object);
return_VOID;
}
void acpi_ut_delete_internal_object_list(union acpi_operand_object **obj_list)
{
union acpi_operand_object **internal_obj;
ACPI_FUNCTION_ENTRY();
for (internal_obj = obj_list; *internal_obj; internal_obj++) {
acpi_ut_remove_reference(*internal_obj);
}
ACPI_FREE(obj_list);
return;
}
static void
acpi_ut_update_ref_count(union acpi_operand_object *object, u32 action)
{
u16 original_count;
u16 new_count = 0;
acpi_cpu_flags lock_flags;
ACPI_FUNCTION_NAME(ut_update_ref_count);
if (!object) {
return;
}
lock_flags = acpi_os_acquire_lock(acpi_gbl_reference_count_lock);
original_count = object->common.reference_count;
switch (action) {
case REF_INCREMENT:
new_count = original_count + 1;
object->common.reference_count = new_count;
acpi_os_release_lock(acpi_gbl_reference_count_lock, lock_flags);
if (!original_count) {
ACPI_WARNING((AE_INFO,
"Obj %p, Reference Count was zero before increment\n",
object));
}
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Obj %p Type %.2X Refs %.2X [Incremented]\n",
object, object->common.type, new_count));
break;
case REF_DECREMENT:
if (original_count) {
new_count = original_count - 1;
object->common.reference_count = new_count;
}
acpi_os_release_lock(acpi_gbl_reference_count_lock, lock_flags);
if (!original_count) {
ACPI_WARNING((AE_INFO,
"Obj %p, Reference Count is already zero, cannot decrement\n",
object));
}
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Obj %p Type %.2X Refs %.2X [Decremented]\n",
object, object->common.type, new_count));
if (new_count == 0) {
acpi_ut_delete_internal_obj(object);
}
break;
default:
acpi_os_release_lock(acpi_gbl_reference_count_lock, lock_flags);
ACPI_ERROR((AE_INFO, "Unknown Reference Count action (0x%X)",
action));
return;
}
if (new_count > ACPI_MAX_REFERENCE_COUNT) {
ACPI_WARNING((AE_INFO,
"Large Reference Count (0x%X) in object %p, Type=0x%.2X",
new_count, object, object->common.type));
}
}
acpi_status
acpi_ut_update_object_reference(union acpi_operand_object *object, u16 action)
{
acpi_status status = AE_OK;
union acpi_generic_state *state_list = NULL;
union acpi_operand_object *next_object = NULL;
union acpi_operand_object *prev_object;
union acpi_generic_state *state;
u32 i;
ACPI_FUNCTION_NAME(ut_update_object_reference);
while (object) {
if (ACPI_GET_DESCRIPTOR_TYPE(object) == ACPI_DESC_TYPE_NAMED) {
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Object %p is NS handle\n", object));
return (AE_OK);
}
switch (object->common.type) {
case ACPI_TYPE_DEVICE:
case ACPI_TYPE_PROCESSOR:
case ACPI_TYPE_POWER:
case ACPI_TYPE_THERMAL:
for (i = 0; i < ACPI_NUM_NOTIFY_TYPES; i++) {
prev_object =
object->common_notify.notify_list[i];
while (prev_object) {
next_object =
prev_object->notify.next[i];
acpi_ut_update_ref_count(prev_object,
action);
prev_object = next_object;
}
}
break;
case ACPI_TYPE_PACKAGE:
for (i = 0; i < object->package.count; i++) {
next_object = object->package.elements[i];
if (!next_object) {
continue;
}
switch (next_object->common.type) {
case ACPI_TYPE_INTEGER:
case ACPI_TYPE_STRING:
case ACPI_TYPE_BUFFER:
acpi_ut_update_ref_count(next_object,
action);
break;
default:
status =
acpi_ut_create_update_state_and_push
(next_object, action, &state_list);
if (ACPI_FAILURE(status)) {
goto error_exit;
}
break;
}
}
next_object = NULL;
break;
case ACPI_TYPE_BUFFER_FIELD:
next_object = object->buffer_field.buffer_obj;
break;
case ACPI_TYPE_LOCAL_REGION_FIELD:
next_object = object->field.region_obj;
break;
case ACPI_TYPE_LOCAL_BANK_FIELD:
next_object = object->bank_field.bank_obj;
status =
acpi_ut_create_update_state_and_push(object->
bank_field.
region_obj,
action,
&state_list);
if (ACPI_FAILURE(status)) {
goto error_exit;
}
break;
case ACPI_TYPE_LOCAL_INDEX_FIELD:
next_object = object->index_field.index_obj;
status =
acpi_ut_create_update_state_and_push(object->
index_field.
data_obj,
action,
&state_list);
if (ACPI_FAILURE(status)) {
goto error_exit;
}
break;
case ACPI_TYPE_LOCAL_REFERENCE:
if ((object->reference.class == ACPI_REFCLASS_INDEX) ||
(object->reference.class == ACPI_REFCLASS_NAME)) {
next_object = object->reference.object;
}
break;
case ACPI_TYPE_REGION:
default:
break;
}
acpi_ut_update_ref_count(object, action);
object = NULL;
if (next_object) {
object = next_object;
next_object = NULL;
} else if (state_list) {
state = acpi_ut_pop_generic_state(&state_list);
object = state->update.object;
acpi_ut_delete_generic_state(state);
}
}
return (AE_OK);
error_exit:
ACPI_EXCEPTION((AE_INFO, status,
"Could not update object reference count"));
while (state_list) {
state = acpi_ut_pop_generic_state(&state_list);
acpi_ut_delete_generic_state(state);
}
return (status);
}
void acpi_ut_add_reference(union acpi_operand_object *object)
{
ACPI_FUNCTION_NAME(ut_add_reference);
if (!acpi_ut_valid_internal_object(object)) {
return;
}
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Obj %p Current Refs=%X [To Be Incremented]\n",
object, object->common.reference_count));
(void)acpi_ut_update_object_reference(object, REF_INCREMENT);
return;
}
void acpi_ut_remove_reference(union acpi_operand_object *object)
{
ACPI_FUNCTION_NAME(ut_remove_reference);
if (!object ||
(ACPI_GET_DESCRIPTOR_TYPE(object) == ACPI_DESC_TYPE_NAMED)) {
return;
}
if (!acpi_ut_valid_internal_object(object)) {
return;
}
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Obj %p Current Refs=%X [To Be Decremented]\n",
object, object->common.reference_count));
(void)acpi_ut_update_object_reference(object, REF_DECREMENT);
return;
}
