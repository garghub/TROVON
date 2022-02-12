acpi_status acpi_ev_init_global_lock_handler(void)
{
acpi_status status;
ACPI_FUNCTION_TRACE(ev_init_global_lock_handler);
status = acpi_install_fixed_event_handler(ACPI_EVENT_GLOBAL,
acpi_ev_global_lock_handler,
NULL);
acpi_gbl_global_lock_present = FALSE;
if (status == AE_NO_HARDWARE_RESPONSE) {
ACPI_ERROR((AE_INFO,
"No response from Global Lock hardware, disabling lock"));
return_ACPI_STATUS(AE_OK);
}
status = acpi_os_create_lock(&acpi_gbl_global_lock_pending_lock);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
acpi_gbl_global_lock_pending = FALSE;
acpi_gbl_global_lock_present = TRUE;
return_ACPI_STATUS(status);
}
acpi_status acpi_ev_remove_global_lock_handler(void)
{
acpi_status status;
ACPI_FUNCTION_TRACE(ev_remove_global_lock_handler);
acpi_gbl_global_lock_present = FALSE;
status = acpi_remove_fixed_event_handler(ACPI_EVENT_GLOBAL,
acpi_ev_global_lock_handler);
return_ACPI_STATUS(status);
}
static u32 acpi_ev_global_lock_handler(void *context)
{
acpi_status status;
acpi_cpu_flags flags;
flags = acpi_os_acquire_lock(acpi_gbl_global_lock_pending_lock);
if (!acpi_gbl_global_lock_pending) {
goto cleanup_and_exit;
}
status = acpi_os_signal_semaphore(acpi_gbl_global_lock_semaphore, 1);
if (ACPI_FAILURE(status)) {
ACPI_ERROR((AE_INFO, "Could not signal Global Lock semaphore"));
}
acpi_gbl_global_lock_pending = FALSE;
cleanup_and_exit:
acpi_os_release_lock(acpi_gbl_global_lock_pending_lock, flags);
return (ACPI_INTERRUPT_HANDLED);
}
acpi_status acpi_ev_acquire_global_lock(u16 timeout)
{
acpi_cpu_flags flags;
acpi_status status;
u8 acquired = FALSE;
ACPI_FUNCTION_TRACE(ev_acquire_global_lock);
status =
acpi_ex_system_wait_mutex(acpi_gbl_global_lock_mutex->mutex.
os_mutex, timeout);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
acpi_gbl_global_lock_handle++;
if (acpi_gbl_global_lock_handle == 0) {
acpi_gbl_global_lock_handle = 1;
}
if (!acpi_gbl_global_lock_present) {
acpi_gbl_global_lock_acquired = TRUE;
return_ACPI_STATUS(AE_OK);
}
flags = acpi_os_acquire_lock(acpi_gbl_global_lock_pending_lock);
do {
ACPI_ACQUIRE_GLOBAL_LOCK(acpi_gbl_FACS, acquired);
if (acquired) {
acpi_gbl_global_lock_acquired = TRUE;
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"Acquired hardware Global Lock\n"));
break;
}
acpi_gbl_global_lock_pending = TRUE;
acpi_os_release_lock(acpi_gbl_global_lock_pending_lock, flags);
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"Waiting for hardware Global Lock\n"));
status =
acpi_ex_system_wait_semaphore
(acpi_gbl_global_lock_semaphore, ACPI_WAIT_FOREVER);
flags = acpi_os_acquire_lock(acpi_gbl_global_lock_pending_lock);
} while (ACPI_SUCCESS(status));
acpi_gbl_global_lock_pending = FALSE;
acpi_os_release_lock(acpi_gbl_global_lock_pending_lock, flags);
return_ACPI_STATUS(status);
}
acpi_status acpi_ev_release_global_lock(void)
{
u8 pending = FALSE;
acpi_status status = AE_OK;
ACPI_FUNCTION_TRACE(ev_release_global_lock);
if (!acpi_gbl_global_lock_acquired) {
ACPI_WARNING((AE_INFO,
"Cannot release the ACPI Global Lock, it has not been acquired"));
return_ACPI_STATUS(AE_NOT_ACQUIRED);
}
if (acpi_gbl_global_lock_present) {
ACPI_RELEASE_GLOBAL_LOCK(acpi_gbl_FACS, pending);
if (pending) {
status =
acpi_write_bit_register
(ACPI_BITREG_GLOBAL_LOCK_RELEASE,
ACPI_ENABLE_EVENT);
}
ACPI_DEBUG_PRINT((ACPI_DB_EXEC,
"Released hardware Global Lock\n"));
}
acpi_gbl_global_lock_acquired = FALSE;
acpi_os_release_mutex(acpi_gbl_global_lock_mutex->mutex.os_mutex);
return_ACPI_STATUS(status);
}
