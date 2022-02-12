void
acpi_ut_push_generic_state(union acpi_generic_state **list_head,
union acpi_generic_state *state)
{
ACPI_FUNCTION_ENTRY();
state->common.next = *list_head;
*list_head = state;
return;
}
union acpi_generic_state *acpi_ut_pop_generic_state(union acpi_generic_state
**list_head)
{
union acpi_generic_state *state;
ACPI_FUNCTION_ENTRY();
state = *list_head;
if (state) {
*list_head = state->common.next;
}
return (state);
}
union acpi_generic_state *acpi_ut_create_generic_state(void)
{
union acpi_generic_state *state;
ACPI_FUNCTION_ENTRY();
state = acpi_os_acquire_object(acpi_gbl_state_cache);
if (state) {
state->common.descriptor_type = ACPI_DESC_TYPE_STATE;
}
return (state);
}
struct acpi_thread_state *acpi_ut_create_thread_state(void)
{
union acpi_generic_state *state;
ACPI_FUNCTION_ENTRY();
state = acpi_ut_create_generic_state();
if (!state) {
return (NULL);
}
state->common.descriptor_type = ACPI_DESC_TYPE_STATE_THREAD;
state->thread.thread_id = acpi_os_get_thread_id();
if (!state->thread.thread_id) {
ACPI_ERROR((AE_INFO, "Invalid zero ID from AcpiOsGetThreadId"));
state->thread.thread_id = (acpi_thread_id) 1;
}
return ((struct acpi_thread_state *)state);
}
union acpi_generic_state *acpi_ut_create_update_state(union acpi_operand_object
*object, u16 action)
{
union acpi_generic_state *state;
ACPI_FUNCTION_ENTRY();
state = acpi_ut_create_generic_state();
if (!state) {
return (NULL);
}
state->common.descriptor_type = ACPI_DESC_TYPE_STATE_UPDATE;
state->update.object = object;
state->update.value = action;
return (state);
}
union acpi_generic_state *acpi_ut_create_pkg_state(void *internal_object,
void *external_object,
u32 index)
{
union acpi_generic_state *state;
ACPI_FUNCTION_ENTRY();
state = acpi_ut_create_generic_state();
if (!state) {
return (NULL);
}
state->common.descriptor_type = ACPI_DESC_TYPE_STATE_PACKAGE;
state->pkg.source_object = (union acpi_operand_object *)internal_object;
state->pkg.dest_object = external_object;
state->pkg.index = index;
state->pkg.num_packages = 1;
return (state);
}
union acpi_generic_state *acpi_ut_create_control_state(void)
{
union acpi_generic_state *state;
ACPI_FUNCTION_ENTRY();
state = acpi_ut_create_generic_state();
if (!state) {
return (NULL);
}
state->common.descriptor_type = ACPI_DESC_TYPE_STATE_CONTROL;
state->common.state = ACPI_CONTROL_CONDITIONAL_EXECUTING;
return (state);
}
void acpi_ut_delete_generic_state(union acpi_generic_state *state)
{
ACPI_FUNCTION_ENTRY();
if (state) {
(void)acpi_os_release_object(acpi_gbl_state_cache, state);
}
return;
}
