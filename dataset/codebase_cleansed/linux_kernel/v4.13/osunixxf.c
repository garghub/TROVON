static void os_enter_line_edit_mode(void)
{
struct termios local_term_attributes;
term_attributes_were_set = 0;
if (!isatty(STDIN_FILENO)) {
return;
}
if (tcgetattr(STDIN_FILENO, &original_term_attributes)) {
fprintf(stderr, "Could not get terminal attributes!\n");
return;
}
memcpy(&local_term_attributes, &original_term_attributes,
sizeof(struct termios));
local_term_attributes.c_lflag &= ~(ICANON | ECHO);
local_term_attributes.c_cc[VMIN] = 1;
local_term_attributes.c_cc[VTIME] = 0;
if (tcsetattr(STDIN_FILENO, TCSANOW, &local_term_attributes)) {
fprintf(stderr, "Could not set terminal attributes!\n");
return;
}
term_attributes_were_set = 1;
}
static void os_exit_line_edit_mode(void)
{
if (!term_attributes_were_set) {
return;
}
if (tcsetattr(STDIN_FILENO, TCSANOW, &original_term_attributes)) {
fprintf(stderr, "Could not restore terminal attributes!\n");
}
}
acpi_status acpi_os_initialize(void)
{
acpi_status status;
acpi_gbl_output_file = stdout;
os_enter_line_edit_mode();
status = acpi_os_create_lock(&acpi_gbl_print_lock);
if (ACPI_FAILURE(status)) {
return (status);
}
return (AE_OK);
}
acpi_status acpi_os_terminate(void)
{
os_exit_line_edit_mode();
return (AE_OK);
}
acpi_physical_address acpi_os_get_root_pointer(void)
{
return (0);
}
acpi_status
acpi_os_predefined_override(const struct acpi_predefined_names *init_val,
acpi_string *new_val)
{
if (!init_val || !new_val) {
return (AE_BAD_PARAMETER);
}
*new_val = NULL;
return (AE_OK);
}
acpi_status
acpi_os_table_override(struct acpi_table_header *existing_table,
struct acpi_table_header **new_table)
{
if (!existing_table || !new_table) {
return (AE_BAD_PARAMETER);
}
*new_table = NULL;
#ifdef ACPI_EXEC_APP
ae_table_override(existing_table, new_table);
return (AE_OK);
#else
return (AE_NO_ACPI_TABLES);
#endif
}
acpi_status
acpi_os_physical_table_override(struct acpi_table_header *existing_table,
acpi_physical_address *new_address,
u32 *new_table_length)
{
return (AE_SUPPORT);
}
acpi_status acpi_os_enter_sleep(u8 sleep_state, u32 rega_value, u32 regb_value)
{
return (AE_OK);
}
void acpi_os_redirect_output(void *destination)
{
acpi_gbl_output_file = destination;
}
void ACPI_INTERNAL_VAR_XFACE acpi_os_printf(const char *fmt, ...)
{
va_list args;
u8 flags;
flags = acpi_gbl_db_output_flags;
if (flags & ACPI_DB_REDIRECTABLE_OUTPUT) {
if (acpi_gbl_debug_file) {
va_start(args, fmt);
vfprintf(acpi_gbl_debug_file, fmt, args);
va_end(args);
} else {
flags |= ACPI_DB_CONSOLE_OUTPUT;
}
}
if (flags & ACPI_DB_CONSOLE_OUTPUT) {
va_start(args, fmt);
vfprintf(acpi_gbl_output_file, fmt, args);
va_end(args);
}
}
void acpi_os_vprintf(const char *fmt, va_list args)
{
u8 flags;
char buffer[ACPI_VPRINTF_BUFFER_SIZE];
vsnprintf(buffer, ACPI_VPRINTF_BUFFER_SIZE, fmt, args);
flags = acpi_gbl_db_output_flags;
if (flags & ACPI_DB_REDIRECTABLE_OUTPUT) {
if (acpi_gbl_debug_file) {
fputs(buffer, acpi_gbl_debug_file);
} else {
flags |= ACPI_DB_CONSOLE_OUTPUT;
}
}
if (flags & ACPI_DB_CONSOLE_OUTPUT) {
fputs(buffer, acpi_gbl_output_file);
}
}
acpi_status acpi_os_get_line(char *buffer, u32 buffer_length, u32 *bytes_read)
{
int input_char;
u32 end_of_line;
for (end_of_line = 0;; end_of_line++) {
if (end_of_line >= buffer_length) {
return (AE_BUFFER_OVERFLOW);
}
if ((input_char = getchar()) == EOF) {
return (AE_ERROR);
}
if (!input_char || input_char == _ASCII_NEWLINE) {
break;
}
buffer[end_of_line] = (char)input_char;
}
buffer[end_of_line] = 0;
if (bytes_read) {
*bytes_read = end_of_line;
}
return (AE_OK);
}
void *acpi_os_map_memory(acpi_physical_address where, acpi_size length)
{
return (ACPI_TO_POINTER((acpi_size)where));
}
void acpi_os_unmap_memory(void *where, acpi_size length)
{
return;
}
void *acpi_os_allocate(acpi_size size)
{
void *mem;
mem = (void *)malloc((size_t) size);
return (mem);
}
void *acpi_os_allocate_zeroed(acpi_size size)
{
void *mem;
mem = (void *)calloc(1, (size_t) size);
return (mem);
}
void acpi_os_free(void *mem)
{
free(mem);
}
acpi_status
acpi_os_create_semaphore(u32 max_units,
u32 initial_units, acpi_handle *out_handle)
{
*out_handle = (acpi_handle)1;
return (AE_OK);
}
acpi_status acpi_os_delete_semaphore(acpi_handle handle)
{
return (AE_OK);
}
acpi_status acpi_os_wait_semaphore(acpi_handle handle, u32 units, u16 timeout)
{
return (AE_OK);
}
acpi_status acpi_os_signal_semaphore(acpi_handle handle, u32 units)
{
return (AE_OK);
}
acpi_status
acpi_os_create_semaphore(u32 max_units,
u32 initial_units, acpi_handle *out_handle)
{
sem_t *sem;
if (!out_handle) {
return (AE_BAD_PARAMETER);
}
#ifdef __APPLE__
{
static int semaphore_count = 0;
char semaphore_name[32];
snprintf(semaphore_name, sizeof(semaphore_name), "acpi_sem_%d",
semaphore_count++);
printf("%s\n", semaphore_name);
sem =
sem_open(semaphore_name, O_EXCL | O_CREAT, 0755,
initial_units);
if (!sem) {
return (AE_NO_MEMORY);
}
sem_unlink(semaphore_name);
}
#else
sem = acpi_os_allocate(sizeof(sem_t));
if (!sem) {
return (AE_NO_MEMORY);
}
if (sem_init(sem, 0, initial_units) == -1) {
acpi_os_free(sem);
return (AE_BAD_PARAMETER);
}
#endif
*out_handle = (acpi_handle)sem;
return (AE_OK);
}
acpi_status acpi_os_delete_semaphore(acpi_handle handle)
{
sem_t *sem = (sem_t *) handle;
if (!sem) {
return (AE_BAD_PARAMETER);
}
#ifdef __APPLE__
if (sem_close(sem) == -1) {
return (AE_BAD_PARAMETER);
}
#else
if (sem_destroy(sem) == -1) {
return (AE_BAD_PARAMETER);
}
#endif
return (AE_OK);
}
acpi_status
acpi_os_wait_semaphore(acpi_handle handle, u32 units, u16 msec_timeout)
{
acpi_status status = AE_OK;
sem_t *sem = (sem_t *) handle;
int ret_val;
#ifndef ACPI_USE_ALTERNATE_TIMEOUT
struct timespec time;
#endif
if (!sem) {
return (AE_BAD_PARAMETER);
}
switch (msec_timeout) {
case 0:
if (sem_trywait(sem) == -1) {
status = (AE_TIME);
}
break;
case ACPI_WAIT_FOREVER:
while (((ret_val = sem_wait(sem)) == -1) && (errno == EINTR)) {
continue;
}
if (ret_val != 0) {
status = (AE_TIME);
}
break;
default:
#ifdef ACPI_USE_ALTERNATE_TIMEOUT
while (msec_timeout) {
if (sem_trywait(sem) == 0) {
return (AE_OK);
}
if (msec_timeout >= 10) {
msec_timeout -= 10;
usleep(10 * ACPI_USEC_PER_MSEC);
} else {
msec_timeout--;
usleep(ACPI_USEC_PER_MSEC);
}
}
status = (AE_TIME);
#else
if (clock_gettime(CLOCK_REALTIME, &time) == -1) {
perror("clock_gettime");
return (AE_TIME);
}
time.tv_sec += (msec_timeout / ACPI_MSEC_PER_SEC);
time.tv_nsec +=
((msec_timeout % ACPI_MSEC_PER_SEC) * ACPI_NSEC_PER_MSEC);
if (time.tv_nsec >= ACPI_NSEC_PER_SEC) {
time.tv_sec += (time.tv_nsec / ACPI_NSEC_PER_SEC);
time.tv_nsec = (time.tv_nsec % ACPI_NSEC_PER_SEC);
}
while (((ret_val = sem_timedwait(sem, &time)) == -1)
&& (errno == EINTR)) {
continue;
}
if (ret_val != 0) {
if (errno != ETIMEDOUT) {
perror("sem_timedwait");
}
status = (AE_TIME);
}
#endif
break;
}
return (status);
}
acpi_status acpi_os_signal_semaphore(acpi_handle handle, u32 units)
{
sem_t *sem = (sem_t *) handle;
if (!sem) {
return (AE_BAD_PARAMETER);
}
if (sem_post(sem) == -1) {
return (AE_LIMIT);
}
return (AE_OK);
}
acpi_status acpi_os_create_lock(acpi_spinlock * out_handle)
{
return (acpi_os_create_semaphore(1, 1, out_handle));
}
void acpi_os_delete_lock(acpi_spinlock handle)
{
acpi_os_delete_semaphore(handle);
}
acpi_cpu_flags acpi_os_acquire_lock(acpi_handle handle)
{
acpi_os_wait_semaphore(handle, 1, 0xFFFF);
return (0);
}
void acpi_os_release_lock(acpi_spinlock handle, acpi_cpu_flags flags)
{
acpi_os_signal_semaphore(handle, 1);
}
u32
acpi_os_install_interrupt_handler(u32 interrupt_number,
acpi_osd_handler service_routine,
void *context)
{
return (AE_OK);
}
acpi_status
acpi_os_remove_interrupt_handler(u32 interrupt_number,
acpi_osd_handler service_routine)
{
return (AE_OK);
}
void acpi_os_stall(u32 microseconds)
{
if (microseconds) {
usleep(microseconds);
}
}
void acpi_os_sleep(u64 milliseconds)
{
sleep(milliseconds / ACPI_MSEC_PER_SEC);
usleep((milliseconds % ACPI_MSEC_PER_SEC) * ACPI_USEC_PER_MSEC);
}
u64 acpi_os_get_timer(void)
{
struct timeval time;
gettimeofday(&time, NULL);
return (((u64)time.tv_sec * ACPI_100NSEC_PER_SEC) +
((u64)time.tv_usec * ACPI_100NSEC_PER_USEC));
}
acpi_status
acpi_os_read_pci_configuration(struct acpi_pci_id *pci_id,
u32 pci_register, u64 *value, u32 width)
{
*value = 0;
return (AE_OK);
}
acpi_status
acpi_os_write_pci_configuration(struct acpi_pci_id *pci_id,
u32 pci_register, u64 value, u32 width)
{
return (AE_OK);
}
acpi_status acpi_os_read_port(acpi_io_address address, u32 *value, u32 width)
{
switch (width) {
case 8:
*value = 0xFF;
break;
case 16:
*value = 0xFFFF;
break;
case 32:
*value = 0xFFFFFFFF;
break;
default:
return (AE_BAD_PARAMETER);
}
return (AE_OK);
}
acpi_status acpi_os_write_port(acpi_io_address address, u32 value, u32 width)
{
return (AE_OK);
}
acpi_status
acpi_os_read_memory(acpi_physical_address address, u64 *value, u32 width)
{
switch (width) {
case 8:
case 16:
case 32:
case 64:
*value = 0;
break;
default:
return (AE_BAD_PARAMETER);
}
return (AE_OK);
}
acpi_status
acpi_os_write_memory(acpi_physical_address address, u64 value, u32 width)
{
return (AE_OK);
}
u8 acpi_os_readable(void *pointer, acpi_size length)
{
return (TRUE);
}
u8 acpi_os_writable(void *pointer, acpi_size length)
{
return (TRUE);
}
acpi_status acpi_os_signal(u32 function, void *info)
{
switch (function) {
case ACPI_SIGNAL_FATAL:
break;
case ACPI_SIGNAL_BREAKPOINT:
break;
default:
break;
}
return (AE_OK);
}
acpi_thread_id acpi_os_get_thread_id(void)
{
pthread_t thread;
thread = pthread_self();
return (ACPI_CAST_PTHREAD_T(thread));
}
acpi_status
acpi_os_execute(acpi_execute_type type,
acpi_osd_exec_callback function, void *context)
{
pthread_t thread;
int ret;
ret =
pthread_create(&thread, NULL, (PTHREAD_CALLBACK) function, context);
if (ret) {
acpi_os_printf("Create thread failed");
}
return (0);
}
acpi_thread_id acpi_os_get_thread_id(void)
{
return (1);
}
acpi_status
acpi_os_execute(acpi_execute_type type,
acpi_osd_exec_callback function, void *context)
{
function(context);
return (AE_OK);
}
void acpi_os_wait_events_complete(void)
{
return;
}
