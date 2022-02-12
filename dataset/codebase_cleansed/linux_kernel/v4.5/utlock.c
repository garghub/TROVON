acpi_status acpi_ut_create_rw_lock(struct acpi_rw_lock *lock)
{
acpi_status status;
lock->num_readers = 0;
status = acpi_os_create_mutex(&lock->reader_mutex);
if (ACPI_FAILURE(status)) {
return (status);
}
status = acpi_os_create_mutex(&lock->writer_mutex);
return (status);
}
void acpi_ut_delete_rw_lock(struct acpi_rw_lock *lock)
{
acpi_os_delete_mutex(lock->reader_mutex);
acpi_os_delete_mutex(lock->writer_mutex);
lock->num_readers = 0;
lock->reader_mutex = NULL;
lock->writer_mutex = NULL;
}
acpi_status acpi_ut_acquire_read_lock(struct acpi_rw_lock *lock)
{
acpi_status status;
status = acpi_os_acquire_mutex(lock->reader_mutex, ACPI_WAIT_FOREVER);
if (ACPI_FAILURE(status)) {
return (status);
}
lock->num_readers++;
if (lock->num_readers == 1) {
status =
acpi_os_acquire_mutex(lock->writer_mutex,
ACPI_WAIT_FOREVER);
}
acpi_os_release_mutex(lock->reader_mutex);
return (status);
}
acpi_status acpi_ut_release_read_lock(struct acpi_rw_lock *lock)
{
acpi_status status;
status = acpi_os_acquire_mutex(lock->reader_mutex, ACPI_WAIT_FOREVER);
if (ACPI_FAILURE(status)) {
return (status);
}
lock->num_readers--;
if (lock->num_readers == 0) {
acpi_os_release_mutex(lock->writer_mutex);
}
acpi_os_release_mutex(lock->reader_mutex);
return (status);
}
acpi_status acpi_ut_acquire_write_lock(struct acpi_rw_lock *lock)
{
acpi_status status;
status = acpi_os_acquire_mutex(lock->writer_mutex, ACPI_WAIT_FOREVER);
return (status);
}
void acpi_ut_release_write_lock(struct acpi_rw_lock *lock)
{
acpi_os_release_mutex(lock->writer_mutex);
}
