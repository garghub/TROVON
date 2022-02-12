acpi_status
acpi_ev_walk_gpe_list(acpi_gpe_callback gpe_walk_callback, void *context)
{
struct acpi_gpe_block_info *gpe_block;
struct acpi_gpe_xrupt_info *gpe_xrupt_info;
acpi_status status = AE_OK;
acpi_cpu_flags flags;
ACPI_FUNCTION_TRACE(ev_walk_gpe_list);
flags = acpi_os_acquire_lock(acpi_gbl_gpe_lock);
gpe_xrupt_info = acpi_gbl_gpe_xrupt_list_head;
while (gpe_xrupt_info) {
gpe_block = gpe_xrupt_info->gpe_block_list_head;
while (gpe_block) {
status =
gpe_walk_callback(gpe_xrupt_info, gpe_block,
context);
if (ACPI_FAILURE(status)) {
if (status == AE_CTRL_END) {
status = AE_OK;
}
goto unlock_and_exit;
}
gpe_block = gpe_block->next;
}
gpe_xrupt_info = gpe_xrupt_info->next;
}
unlock_and_exit:
acpi_os_release_lock(acpi_gbl_gpe_lock, flags);
return_ACPI_STATUS(status);
}
u8 acpi_ev_valid_gpe_event(struct acpi_gpe_event_info *gpe_event_info)
{
struct acpi_gpe_xrupt_info *gpe_xrupt_block;
struct acpi_gpe_block_info *gpe_block;
ACPI_FUNCTION_ENTRY();
gpe_xrupt_block = acpi_gbl_gpe_xrupt_list_head;
while (gpe_xrupt_block) {
gpe_block = gpe_xrupt_block->gpe_block_list_head;
while (gpe_block) {
if ((&gpe_block->event_info[0] <= gpe_event_info) &&
(&gpe_block->event_info[gpe_block->gpe_count] >
gpe_event_info)) {
return (TRUE);
}
gpe_block = gpe_block->next;
}
gpe_xrupt_block = gpe_xrupt_block->next;
}
return (FALSE);
}
acpi_status
acpi_ev_get_gpe_device(struct acpi_gpe_xrupt_info *gpe_xrupt_info,
struct acpi_gpe_block_info *gpe_block, void *context)
{
struct acpi_gpe_device_info *info = context;
info->next_block_base_index += gpe_block->gpe_count;
if (info->index < info->next_block_base_index) {
if ((gpe_block->node)->type == ACPI_TYPE_DEVICE) {
info->gpe_device = gpe_block->node;
}
info->status = AE_OK;
return (AE_CTRL_END);
}
return (AE_OK);
}
struct acpi_gpe_xrupt_info *acpi_ev_get_gpe_xrupt_block(u32 interrupt_number)
{
struct acpi_gpe_xrupt_info *next_gpe_xrupt;
struct acpi_gpe_xrupt_info *gpe_xrupt;
acpi_status status;
acpi_cpu_flags flags;
ACPI_FUNCTION_TRACE(ev_get_gpe_xrupt_block);
next_gpe_xrupt = acpi_gbl_gpe_xrupt_list_head;
while (next_gpe_xrupt) {
if (next_gpe_xrupt->interrupt_number == interrupt_number) {
return_PTR(next_gpe_xrupt);
}
next_gpe_xrupt = next_gpe_xrupt->next;
}
gpe_xrupt = ACPI_ALLOCATE_ZEROED(sizeof(struct acpi_gpe_xrupt_info));
if (!gpe_xrupt) {
return_PTR(NULL);
}
gpe_xrupt->interrupt_number = interrupt_number;
flags = acpi_os_acquire_lock(acpi_gbl_gpe_lock);
if (acpi_gbl_gpe_xrupt_list_head) {
next_gpe_xrupt = acpi_gbl_gpe_xrupt_list_head;
while (next_gpe_xrupt->next) {
next_gpe_xrupt = next_gpe_xrupt->next;
}
next_gpe_xrupt->next = gpe_xrupt;
gpe_xrupt->previous = next_gpe_xrupt;
} else {
acpi_gbl_gpe_xrupt_list_head = gpe_xrupt;
}
acpi_os_release_lock(acpi_gbl_gpe_lock, flags);
if (interrupt_number != acpi_gbl_FADT.sci_interrupt) {
status = acpi_os_install_interrupt_handler(interrupt_number,
acpi_ev_gpe_xrupt_handler,
gpe_xrupt);
if (ACPI_FAILURE(status)) {
ACPI_ERROR((AE_INFO,
"Could not install GPE interrupt handler at level 0x%X",
interrupt_number));
return_PTR(NULL);
}
}
return_PTR(gpe_xrupt);
}
acpi_status acpi_ev_delete_gpe_xrupt(struct acpi_gpe_xrupt_info *gpe_xrupt)
{
acpi_status status;
acpi_cpu_flags flags;
ACPI_FUNCTION_TRACE(ev_delete_gpe_xrupt);
if (gpe_xrupt->interrupt_number == acpi_gbl_FADT.sci_interrupt) {
gpe_xrupt->gpe_block_list_head = NULL;
return_ACPI_STATUS(AE_OK);
}
status =
acpi_os_remove_interrupt_handler(gpe_xrupt->interrupt_number,
acpi_ev_gpe_xrupt_handler);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
flags = acpi_os_acquire_lock(acpi_gbl_gpe_lock);
if (gpe_xrupt->previous) {
gpe_xrupt->previous->next = gpe_xrupt->next;
} else {
acpi_gbl_gpe_xrupt_list_head = gpe_xrupt->next;
}
if (gpe_xrupt->next) {
gpe_xrupt->next->previous = gpe_xrupt->previous;
}
acpi_os_release_lock(acpi_gbl_gpe_lock, flags);
ACPI_FREE(gpe_xrupt);
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_ev_delete_gpe_handlers(struct acpi_gpe_xrupt_info *gpe_xrupt_info,
struct acpi_gpe_block_info *gpe_block,
void *context)
{
struct acpi_gpe_event_info *gpe_event_info;
struct acpi_gpe_notify_info *notify;
struct acpi_gpe_notify_info *next;
u32 i;
u32 j;
ACPI_FUNCTION_TRACE(ev_delete_gpe_handlers);
for (i = 0; i < gpe_block->register_count; i++) {
for (j = 0; j < ACPI_GPE_REGISTER_WIDTH; j++) {
gpe_event_info = &gpe_block->event_info[((acpi_size) i *
ACPI_GPE_REGISTER_WIDTH)
+ j];
if ((gpe_event_info->flags & ACPI_GPE_DISPATCH_MASK) ==
ACPI_GPE_DISPATCH_HANDLER) {
ACPI_FREE(gpe_event_info->dispatch.handler);
gpe_event_info->dispatch.handler = NULL;
gpe_event_info->flags &=
~ACPI_GPE_DISPATCH_MASK;
} else
if ((gpe_event_info->
flags & ACPI_GPE_DISPATCH_MASK) ==
ACPI_GPE_DISPATCH_NOTIFY) {
notify = gpe_event_info->dispatch.notify_list;
while (notify) {
next = notify->next;
ACPI_FREE(notify);
notify = next;
}
gpe_event_info->dispatch.notify_list = NULL;
gpe_event_info->flags &=
~ACPI_GPE_DISPATCH_MASK;
}
}
}
return_ACPI_STATUS(AE_OK);
}
