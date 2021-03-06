static void acpi_ut_delete_internal_obj(union acpi_operand_object *object)
{
void *obj_pointer = NULL;
union acpi_operand_object *handler_desc;
union acpi_operand_object *second_desc;
union acpi_operand_object *next_desc;
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
ACPI_FUNCTION_TRACE(ut_delete_internal_object_list);
for (internal_obj = obj_list; *internal_obj; internal_obj++) {
acpi_ut_remove_reference(*internal_obj);
}
ACPI_FREE(obj_list);
return_VOID;
}
static void
acpi_ut_update_ref_count(union acpi_operand_object *object, u32 action)
{
u16 count;
u16 new_count;
ACPI_FUNCTION_NAME(ut_update_ref_count);
if (!object) {
return;
}
count = object->common.reference_count;
new_count = count;
switch (action) {
case REF_INCREMENT:
new_count++;
object->common.reference_count = new_count;
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Obj %p Refs=%X, [Incremented]\n",
object, new_count));
break;
case REF_DECREMENT:
if (count < 1) {
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Obj %p Refs=%X, can't decrement! (Set to 0)\n",
object, new_count));
new_count = 0;
} else {
new_count--;
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Obj %p Refs=%X, [Decremented]\n",
object, new_count));
}
if (object->common.type == ACPI_TYPE_METHOD) {
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Method Obj %p Refs=%X, [Decremented]\n",
object, new_count));
}
object->common.reference_count = new_count;
if (new_count == 0) {
acpi_ut_delete_internal_obj(object);
}
break;
case REF_FORCE_DELETE:
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Obj %p Refs=%X, Force delete! (Set to 0)\n",
object, count));
new_count = 0;
object->common.reference_count = new_count;
acpi_ut_delete_internal_obj(object);
break;
default:
ACPI_ERROR((AE_INFO, "Unknown action (0x%X)", action));
break;
}
if (count > ACPI_MAX_REFERENCE_COUNT) {
ACPI_WARNING((AE_INFO,
"Large Reference Count (0x%X) in object %p",
count, object));
}
}
acpi_status
acpi_ut_update_object_reference(union acpi_operand_object *object, u16 action)
{
acpi_status status = AE_OK;
union acpi_generic_state *state_list = NULL;
union acpi_operand_object *next_object = NULL;
union acpi_generic_state *state;
u32 i;
ACPI_FUNCTION_TRACE_PTR(ut_update_object_reference, object);
while (object) {
if (ACPI_GET_DESCRIPTOR_TYPE(object) == ACPI_DESC_TYPE_NAMED) {
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Object %p is NS handle\n", object));
return_ACPI_STATUS(AE_OK);
}
switch (object->common.type) {
case ACPI_TYPE_DEVICE:
case ACPI_TYPE_PROCESSOR:
case ACPI_TYPE_POWER:
case ACPI_TYPE_THERMAL:
acpi_ut_update_ref_count(object->common_notify.
system_notify, action);
acpi_ut_update_ref_count(object->common_notify.
device_notify, action);
break;
case ACPI_TYPE_PACKAGE:
for (i = 0; i < object->package.count; i++) {
status =
acpi_ut_create_update_state_and_push
(object->package.elements[i], action,
&state_list);
if (ACPI_FAILURE(status)) {
goto error_exit;
}
}
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
return_ACPI_STATUS(AE_OK);
error_exit:
ACPI_EXCEPTION((AE_INFO, status,
"Could not update object reference count"));
while (state_list) {
state = acpi_ut_pop_generic_state(&state_list);
acpi_ut_delete_generic_state(state);
}
return_ACPI_STATUS(status);
}
void acpi_ut_add_reference(union acpi_operand_object *object)
{
ACPI_FUNCTION_TRACE_PTR(ut_add_reference, object);
if (!acpi_ut_valid_internal_object(object)) {
return_VOID;
}
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Obj %p Current Refs=%X [To Be Incremented]\n",
object, object->common.reference_count));
(void)acpi_ut_update_object_reference(object, REF_INCREMENT);
return_VOID;
}
void acpi_ut_remove_reference(union acpi_operand_object *object)
{
ACPI_FUNCTION_TRACE_PTR(ut_remove_reference, object);
if (!object ||
(ACPI_GET_DESCRIPTOR_TYPE(object) == ACPI_DESC_TYPE_NAMED)) {
return_VOID;
}
if (!acpi_ut_valid_internal_object(object)) {
return_VOID;
}
ACPI_DEBUG_PRINT((ACPI_DB_ALLOCATIONS,
"Obj %p Current Refs=%X [To Be Decremented]\n",
object, object->common.reference_count));
(void)acpi_ut_update_object_reference(object, REF_DECREMENT);
return_VOID;
}
