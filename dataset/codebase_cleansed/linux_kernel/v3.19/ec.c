static inline u8 acpi_ec_read_status(struct acpi_ec *ec)
{
u8 x = inb(ec->command_addr);
pr_debug("EC_SC(R) = 0x%2.2x "
"SCI_EVT=%d BURST=%d CMD=%d IBF=%d OBF=%d\n",
x,
!!(x & ACPI_EC_FLAG_SCI),
!!(x & ACPI_EC_FLAG_BURST),
!!(x & ACPI_EC_FLAG_CMD),
!!(x & ACPI_EC_FLAG_IBF),
!!(x & ACPI_EC_FLAG_OBF));
return x;
}
static inline u8 acpi_ec_read_data(struct acpi_ec *ec)
{
u8 x = inb(ec->data_addr);
pr_debug("EC_DATA(R) = 0x%2.2x\n", x);
return x;
}
static inline void acpi_ec_write_cmd(struct acpi_ec *ec, u8 command)
{
pr_debug("EC_SC(W) = 0x%2.2x\n", command);
outb(command, ec->command_addr);
}
static inline void acpi_ec_write_data(struct acpi_ec *ec, u8 data)
{
pr_debug("EC_DATA(W) = 0x%2.2x\n", data);
outb(data, ec->data_addr);
}
static const char *acpi_ec_cmd_string(u8 cmd)
{
switch (cmd) {
case 0x80:
return "RD_EC";
case 0x81:
return "WR_EC";
case 0x82:
return "BE_EC";
case 0x83:
return "BD_EC";
case 0x84:
return "QR_EC";
}
return "UNKNOWN";
}
static int ec_transaction_completed(struct acpi_ec *ec)
{
unsigned long flags;
int ret = 0;
spin_lock_irqsave(&ec->lock, flags);
if (ec->curr && (ec->curr->flags & ACPI_EC_COMMAND_COMPLETE))
ret = 1;
spin_unlock_irqrestore(&ec->lock, flags);
return ret;
}
static bool advance_transaction(struct acpi_ec *ec)
{
struct transaction *t;
u8 status;
bool wakeup = false;
pr_debug("===== %s (%d) =====\n",
in_interrupt() ? "IRQ" : "TASK", smp_processor_id());
status = acpi_ec_read_status(ec);
t = ec->curr;
if (!t)
goto err;
if (t->flags & ACPI_EC_COMMAND_POLL) {
if (t->wlen > t->wi) {
if ((status & ACPI_EC_FLAG_IBF) == 0)
acpi_ec_write_data(ec, t->wdata[t->wi++]);
else
goto err;
} else if (t->rlen > t->ri) {
if ((status & ACPI_EC_FLAG_OBF) == 1) {
t->rdata[t->ri++] = acpi_ec_read_data(ec);
if (t->rlen == t->ri) {
t->flags |= ACPI_EC_COMMAND_COMPLETE;
if (t->command == ACPI_EC_COMMAND_QUERY)
pr_debug("***** Command(%s) hardware completion *****\n",
acpi_ec_cmd_string(t->command));
wakeup = true;
}
} else
goto err;
} else if (t->wlen == t->wi &&
(status & ACPI_EC_FLAG_IBF) == 0) {
t->flags |= ACPI_EC_COMMAND_COMPLETE;
wakeup = true;
}
return wakeup;
} else {
if (EC_FLAGS_QUERY_HANDSHAKE &&
!(status & ACPI_EC_FLAG_SCI) &&
(t->command == ACPI_EC_COMMAND_QUERY)) {
t->flags |= ACPI_EC_COMMAND_POLL;
t->rdata[t->ri++] = 0x00;
t->flags |= ACPI_EC_COMMAND_COMPLETE;
pr_debug("***** Command(%s) software completion *****\n",
acpi_ec_cmd_string(t->command));
wakeup = true;
} else if ((status & ACPI_EC_FLAG_IBF) == 0) {
acpi_ec_write_cmd(ec, t->command);
t->flags |= ACPI_EC_COMMAND_POLL;
} else
goto err;
return wakeup;
}
err:
if (!(status & ACPI_EC_FLAG_SCI)) {
if (in_interrupt() && t)
++t->irq_count;
}
return wakeup;
}
static void start_transaction(struct acpi_ec *ec)
{
ec->curr->irq_count = ec->curr->wi = ec->curr->ri = 0;
ec->curr->flags = 0;
(void)advance_transaction(ec);
}
static int ec_check_sci_sync(struct acpi_ec *ec, u8 state)
{
if (state & ACPI_EC_FLAG_SCI) {
if (!test_and_set_bit(EC_FLAGS_QUERY_PENDING, &ec->flags))
return acpi_ec_sync_query(ec, NULL);
}
return 0;
}
static int ec_poll(struct acpi_ec *ec)
{
unsigned long flags;
int repeat = 5;
while (repeat--) {
unsigned long delay = jiffies +
msecs_to_jiffies(ec_delay);
do {
if (EC_FLAGS_MSI || irqs_disabled()) {
udelay(ACPI_EC_MSI_UDELAY);
if (ec_transaction_completed(ec))
return 0;
} else {
if (wait_event_timeout(ec->wait,
ec_transaction_completed(ec),
msecs_to_jiffies(1)))
return 0;
}
spin_lock_irqsave(&ec->lock, flags);
(void)advance_transaction(ec);
spin_unlock_irqrestore(&ec->lock, flags);
} while (time_before(jiffies, delay));
pr_debug("controller reset, restart transaction\n");
spin_lock_irqsave(&ec->lock, flags);
start_transaction(ec);
spin_unlock_irqrestore(&ec->lock, flags);
}
return -ETIME;
}
static int acpi_ec_transaction_unlocked(struct acpi_ec *ec,
struct transaction *t)
{
unsigned long tmp;
int ret = 0;
if (EC_FLAGS_MSI)
udelay(ACPI_EC_MSI_UDELAY);
spin_lock_irqsave(&ec->lock, tmp);
ec->curr = t;
pr_debug("***** Command(%s) started *****\n",
acpi_ec_cmd_string(t->command));
start_transaction(ec);
if (ec->curr->command == ACPI_EC_COMMAND_QUERY) {
clear_bit(EC_FLAGS_QUERY_PENDING, &ec->flags);
pr_debug("***** Event stopped *****\n");
}
spin_unlock_irqrestore(&ec->lock, tmp);
ret = ec_poll(ec);
spin_lock_irqsave(&ec->lock, tmp);
pr_debug("***** Command(%s) stopped *****\n",
acpi_ec_cmd_string(t->command));
ec->curr = NULL;
spin_unlock_irqrestore(&ec->lock, tmp);
return ret;
}
static int acpi_ec_transaction(struct acpi_ec *ec, struct transaction *t)
{
int status;
u32 glk;
if (!ec || (!t) || (t->wlen && !t->wdata) || (t->rlen && !t->rdata))
return -EINVAL;
if (t->rdata)
memset(t->rdata, 0, t->rlen);
mutex_lock(&ec->mutex);
if (test_bit(EC_FLAGS_BLOCKED, &ec->flags)) {
status = -EINVAL;
goto unlock;
}
if (ec->global_lock) {
status = acpi_acquire_global_lock(ACPI_EC_UDELAY_GLK, &glk);
if (ACPI_FAILURE(status)) {
status = -ENODEV;
goto unlock;
}
}
if (test_bit(EC_FLAGS_GPE_STORM, &ec->flags)) {
acpi_disable_gpe(NULL, ec->gpe);
}
status = acpi_ec_transaction_unlocked(ec, t);
ec_check_sci_sync(ec, acpi_ec_read_status(ec));
if (test_bit(EC_FLAGS_GPE_STORM, &ec->flags)) {
msleep(1);
acpi_enable_gpe(NULL, ec->gpe);
} else if (t->irq_count > ec_storm_threshold) {
pr_info("GPE storm detected(%d GPEs), "
"transactions will use polling mode\n",
t->irq_count);
set_bit(EC_FLAGS_GPE_STORM, &ec->flags);
}
if (ec->global_lock)
acpi_release_global_lock(glk);
unlock:
mutex_unlock(&ec->mutex);
return status;
}
static int acpi_ec_burst_enable(struct acpi_ec *ec)
{
u8 d;
struct transaction t = {.command = ACPI_EC_BURST_ENABLE,
.wdata = NULL, .rdata = &d,
.wlen = 0, .rlen = 1};
return acpi_ec_transaction(ec, &t);
}
static int acpi_ec_burst_disable(struct acpi_ec *ec)
{
struct transaction t = {.command = ACPI_EC_BURST_DISABLE,
.wdata = NULL, .rdata = NULL,
.wlen = 0, .rlen = 0};
return (acpi_ec_read_status(ec) & ACPI_EC_FLAG_BURST) ?
acpi_ec_transaction(ec, &t) : 0;
}
static int acpi_ec_read(struct acpi_ec *ec, u8 address, u8 *data)
{
int result;
u8 d;
struct transaction t = {.command = ACPI_EC_COMMAND_READ,
.wdata = &address, .rdata = &d,
.wlen = 1, .rlen = 1};
result = acpi_ec_transaction(ec, &t);
*data = d;
return result;
}
static int acpi_ec_write(struct acpi_ec *ec, u8 address, u8 data)
{
u8 wdata[2] = { address, data };
struct transaction t = {.command = ACPI_EC_COMMAND_WRITE,
.wdata = wdata, .rdata = NULL,
.wlen = 2, .rlen = 0};
return acpi_ec_transaction(ec, &t);
}
int ec_read(u8 addr, u8 *val)
{
int err;
u8 temp_data;
if (!first_ec)
return -ENODEV;
err = acpi_ec_read(first_ec, addr, &temp_data);
if (!err) {
*val = temp_data;
return 0;
}
return err;
}
int ec_write(u8 addr, u8 val)
{
int err;
if (!first_ec)
return -ENODEV;
err = acpi_ec_write(first_ec, addr, val);
return err;
}
int ec_transaction(u8 command,
const u8 *wdata, unsigned wdata_len,
u8 *rdata, unsigned rdata_len)
{
struct transaction t = {.command = command,
.wdata = wdata, .rdata = rdata,
.wlen = wdata_len, .rlen = rdata_len};
if (!first_ec)
return -ENODEV;
return acpi_ec_transaction(first_ec, &t);
}
acpi_handle ec_get_handle(void)
{
if (!first_ec)
return NULL;
return first_ec->handle;
}
static void acpi_ec_clear(struct acpi_ec *ec)
{
int i, status;
u8 value = 0;
for (i = 0; i < ACPI_EC_CLEAR_MAX; i++) {
status = acpi_ec_sync_query(ec, &value);
if (status || !value)
break;
}
if (unlikely(i == ACPI_EC_CLEAR_MAX))
pr_warn("Warning: Maximum of %d stale EC events cleared\n", i);
else
pr_info("%d stale EC events cleared\n", i);
}
void acpi_ec_block_transactions(void)
{
struct acpi_ec *ec = first_ec;
if (!ec)
return;
mutex_lock(&ec->mutex);
set_bit(EC_FLAGS_BLOCKED, &ec->flags);
mutex_unlock(&ec->mutex);
}
void acpi_ec_unblock_transactions(void)
{
struct acpi_ec *ec = first_ec;
if (!ec)
return;
mutex_lock(&ec->mutex);
clear_bit(EC_FLAGS_BLOCKED, &ec->flags);
if (EC_FLAGS_CLEAR_ON_RESUME)
acpi_ec_clear(ec);
mutex_unlock(&ec->mutex);
}
void acpi_ec_unblock_transactions_early(void)
{
if (first_ec)
clear_bit(EC_FLAGS_BLOCKED, &first_ec->flags);
}
static int acpi_ec_query_unlocked(struct acpi_ec *ec, u8 *data)
{
int result;
u8 d;
struct transaction t = {.command = ACPI_EC_COMMAND_QUERY,
.wdata = NULL, .rdata = &d,
.wlen = 0, .rlen = 1};
if (!ec || !data)
return -EINVAL;
result = acpi_ec_transaction_unlocked(ec, &t);
if (result)
return result;
if (!d)
return -ENODATA;
*data = d;
return 0;
}
int acpi_ec_add_query_handler(struct acpi_ec *ec, u8 query_bit,
acpi_handle handle, acpi_ec_query_func func,
void *data)
{
struct acpi_ec_query_handler *handler =
kzalloc(sizeof(struct acpi_ec_query_handler), GFP_KERNEL);
if (!handler)
return -ENOMEM;
handler->query_bit = query_bit;
handler->handle = handle;
handler->func = func;
handler->data = data;
mutex_lock(&ec->mutex);
list_add(&handler->node, &ec->list);
mutex_unlock(&ec->mutex);
return 0;
}
void acpi_ec_remove_query_handler(struct acpi_ec *ec, u8 query_bit)
{
struct acpi_ec_query_handler *handler, *tmp;
mutex_lock(&ec->mutex);
list_for_each_entry_safe(handler, tmp, &ec->list, node) {
if (query_bit == handler->query_bit) {
list_del(&handler->node);
kfree(handler);
}
}
mutex_unlock(&ec->mutex);
}
static void acpi_ec_run(void *cxt)
{
struct acpi_ec_query_handler *handler = cxt;
if (!handler)
return;
pr_debug("##### Query(0x%02x) started #####\n", handler->query_bit);
if (handler->func)
handler->func(handler->data);
else if (handler->handle)
acpi_evaluate_object(handler->handle, NULL, NULL, NULL);
pr_debug("##### Query(0x%02x) stopped #####\n", handler->query_bit);
kfree(handler);
}
static int acpi_ec_sync_query(struct acpi_ec *ec, u8 *data)
{
u8 value = 0;
int status;
struct acpi_ec_query_handler *handler, *copy;
status = acpi_ec_query_unlocked(ec, &value);
if (data)
*data = value;
if (status)
return status;
list_for_each_entry(handler, &ec->list, node) {
if (value == handler->query_bit) {
copy = kmalloc(sizeof(*handler), GFP_KERNEL);
if (!copy)
return -ENOMEM;
memcpy(copy, handler, sizeof(*copy));
pr_debug("##### Query(0x%02x) scheduled #####\n",
handler->query_bit);
return acpi_os_execute((copy->func) ?
OSL_NOTIFY_HANDLER : OSL_GPE_HANDLER,
acpi_ec_run, copy);
}
}
return 0;
}
static void acpi_ec_gpe_query(void *ec_cxt)
{
struct acpi_ec *ec = ec_cxt;
if (!ec)
return;
mutex_lock(&ec->mutex);
acpi_ec_sync_query(ec, NULL);
mutex_unlock(&ec->mutex);
}
static int ec_check_sci(struct acpi_ec *ec, u8 state)
{
if (state & ACPI_EC_FLAG_SCI) {
if (!test_and_set_bit(EC_FLAGS_QUERY_PENDING, &ec->flags)) {
pr_debug("***** Event started *****\n");
return acpi_os_execute(OSL_NOTIFY_HANDLER,
acpi_ec_gpe_query, ec);
}
}
return 0;
}
static u32 acpi_ec_gpe_handler(acpi_handle gpe_device,
u32 gpe_number, void *data)
{
unsigned long flags;
struct acpi_ec *ec = data;
spin_lock_irqsave(&ec->lock, flags);
if (advance_transaction(ec))
wake_up(&ec->wait);
spin_unlock_irqrestore(&ec->lock, flags);
ec_check_sci(ec, acpi_ec_read_status(ec));
return ACPI_INTERRUPT_HANDLED | ACPI_REENABLE_GPE;
}
static acpi_status
acpi_ec_space_handler(u32 function, acpi_physical_address address,
u32 bits, u64 *value64,
void *handler_context, void *region_context)
{
struct acpi_ec *ec = handler_context;
int result = 0, i, bytes = bits / 8;
u8 *value = (u8 *)value64;
if ((address > 0xFF) || !value || !handler_context)
return AE_BAD_PARAMETER;
if (function != ACPI_READ && function != ACPI_WRITE)
return AE_BAD_PARAMETER;
if (EC_FLAGS_MSI || bits > 8)
acpi_ec_burst_enable(ec);
for (i = 0; i < bytes; ++i, ++address, ++value)
result = (function == ACPI_READ) ?
acpi_ec_read(ec, address, value) :
acpi_ec_write(ec, address, *value);
if (EC_FLAGS_MSI || bits > 8)
acpi_ec_burst_disable(ec);
switch (result) {
case -EINVAL:
return AE_BAD_PARAMETER;
case -ENODEV:
return AE_NOT_FOUND;
case -ETIME:
return AE_TIME;
default:
return AE_OK;
}
}
static struct acpi_ec *make_acpi_ec(void)
{
struct acpi_ec *ec = kzalloc(sizeof(struct acpi_ec), GFP_KERNEL);
if (!ec)
return NULL;
ec->flags = 1 << EC_FLAGS_QUERY_PENDING;
mutex_init(&ec->mutex);
init_waitqueue_head(&ec->wait);
INIT_LIST_HEAD(&ec->list);
spin_lock_init(&ec->lock);
return ec;
}
static acpi_status
acpi_ec_register_query_methods(acpi_handle handle, u32 level,
void *context, void **return_value)
{
char node_name[5];
struct acpi_buffer buffer = { sizeof(node_name), node_name };
struct acpi_ec *ec = context;
int value = 0;
acpi_status status;
status = acpi_get_name(handle, ACPI_SINGLE_NAME, &buffer);
if (ACPI_SUCCESS(status) && sscanf(node_name, "_Q%x", &value) == 1)
acpi_ec_add_query_handler(ec, value, handle, NULL, NULL);
return AE_OK;
}
static acpi_status
ec_parse_device(acpi_handle handle, u32 Level, void *context, void **retval)
{
acpi_status status;
unsigned long long tmp = 0;
struct acpi_ec *ec = context;
ec->command_addr = ec->data_addr = 0;
status = acpi_walk_resources(handle, METHOD_NAME__CRS,
ec_parse_io_ports, ec);
if (ACPI_FAILURE(status))
return status;
status = acpi_evaluate_integer(handle, "_GPE", NULL, &tmp);
if (ACPI_FAILURE(status))
return status;
ec->gpe = tmp;
tmp = 0;
acpi_evaluate_integer(handle, "_GLK", NULL, &tmp);
ec->global_lock = tmp;
ec->handle = handle;
return AE_CTRL_TERMINATE;
}
static int ec_install_handlers(struct acpi_ec *ec)
{
acpi_status status;
if (test_bit(EC_FLAGS_HANDLERS_INSTALLED, &ec->flags))
return 0;
status = acpi_install_gpe_handler(NULL, ec->gpe,
ACPI_GPE_EDGE_TRIGGERED,
&acpi_ec_gpe_handler, ec);
if (ACPI_FAILURE(status))
return -ENODEV;
acpi_enable_gpe(NULL, ec->gpe);
status = acpi_install_address_space_handler(ec->handle,
ACPI_ADR_SPACE_EC,
&acpi_ec_space_handler,
NULL, ec);
if (ACPI_FAILURE(status)) {
if (status == AE_NOT_FOUND) {
pr_err("Fail in evaluating the _REG object"
" of EC device. Broken bios is suspected.\n");
} else {
acpi_disable_gpe(NULL, ec->gpe);
acpi_remove_gpe_handler(NULL, ec->gpe,
&acpi_ec_gpe_handler);
return -ENODEV;
}
}
set_bit(EC_FLAGS_HANDLERS_INSTALLED, &ec->flags);
return 0;
}
static void ec_remove_handlers(struct acpi_ec *ec)
{
if (!test_bit(EC_FLAGS_HANDLERS_INSTALLED, &ec->flags))
return;
acpi_disable_gpe(NULL, ec->gpe);
if (ACPI_FAILURE(acpi_remove_address_space_handler(ec->handle,
ACPI_ADR_SPACE_EC, &acpi_ec_space_handler)))
pr_err("failed to remove space handler\n");
if (ACPI_FAILURE(acpi_remove_gpe_handler(NULL, ec->gpe,
&acpi_ec_gpe_handler)))
pr_err("failed to remove gpe handler\n");
clear_bit(EC_FLAGS_HANDLERS_INSTALLED, &ec->flags);
}
static int acpi_ec_add(struct acpi_device *device)
{
struct acpi_ec *ec = NULL;
int ret;
strcpy(acpi_device_name(device), ACPI_EC_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_EC_CLASS);
if (boot_ec &&
(boot_ec->handle == device->handle ||
boot_ec->handle == ACPI_ROOT_OBJECT)) {
ec = boot_ec;
boot_ec = NULL;
} else {
ec = make_acpi_ec();
if (!ec)
return -ENOMEM;
}
if (ec_parse_device(device->handle, 0, ec, NULL) !=
AE_CTRL_TERMINATE) {
kfree(ec);
return -EINVAL;
}
acpi_walk_namespace(ACPI_TYPE_METHOD, ec->handle, 1,
acpi_ec_register_query_methods, NULL, ec, NULL);
if (!first_ec)
first_ec = ec;
device->driver_data = ec;
ret = !!request_region(ec->data_addr, 1, "EC data");
WARN(!ret, "Could not request EC data io port 0x%lx", ec->data_addr);
ret = !!request_region(ec->command_addr, 1, "EC cmd");
WARN(!ret, "Could not request EC cmd io port 0x%lx", ec->command_addr);
pr_info("GPE = 0x%lx, I/O: command/status = 0x%lx, data = 0x%lx\n",
ec->gpe, ec->command_addr, ec->data_addr);
ret = ec_install_handlers(ec);
clear_bit(EC_FLAGS_QUERY_PENDING, &ec->flags);
if (EC_FLAGS_CLEAR_ON_RESUME) {
mutex_lock(&ec->mutex);
acpi_ec_clear(ec);
mutex_unlock(&ec->mutex);
}
return ret;
}
static int acpi_ec_remove(struct acpi_device *device)
{
struct acpi_ec *ec;
struct acpi_ec_query_handler *handler, *tmp;
if (!device)
return -EINVAL;
ec = acpi_driver_data(device);
ec_remove_handlers(ec);
mutex_lock(&ec->mutex);
list_for_each_entry_safe(handler, tmp, &ec->list, node) {
list_del(&handler->node);
kfree(handler);
}
mutex_unlock(&ec->mutex);
release_region(ec->data_addr, 1);
release_region(ec->command_addr, 1);
device->driver_data = NULL;
if (ec == first_ec)
first_ec = NULL;
kfree(ec);
return 0;
}
static acpi_status
ec_parse_io_ports(struct acpi_resource *resource, void *context)
{
struct acpi_ec *ec = context;
if (resource->type != ACPI_RESOURCE_TYPE_IO)
return AE_OK;
if (ec->data_addr == 0)
ec->data_addr = resource->data.io.minimum;
else if (ec->command_addr == 0)
ec->command_addr = resource->data.io.minimum;
else
return AE_CTRL_TERMINATE;
return AE_OK;
}
int __init acpi_boot_ec_enable(void)
{
if (!boot_ec || test_bit(EC_FLAGS_HANDLERS_INSTALLED, &boot_ec->flags))
return 0;
if (!ec_install_handlers(boot_ec)) {
first_ec = boot_ec;
return 0;
}
return -EFAULT;
}
static int ec_skip_dsdt_scan(const struct dmi_system_id *id)
{
EC_FLAGS_SKIP_DSDT_SCAN = 1;
return 0;
}
static int ec_validate_ecdt(const struct dmi_system_id *id)
{
EC_FLAGS_VALIDATE_ECDT = 1;
return 0;
}
static int ec_flag_msi(const struct dmi_system_id *id)
{
pr_debug("Detected MSI hardware, enabling workarounds.\n");
EC_FLAGS_MSI = 1;
EC_FLAGS_VALIDATE_ECDT = 1;
return 0;
}
static int ec_enlarge_storm_threshold(const struct dmi_system_id *id)
{
pr_debug("Setting the EC GPE storm threshold to 20\n");
ec_storm_threshold = 20;
return 0;
}
static int ec_flag_query_handshake(const struct dmi_system_id *id)
{
pr_debug("Detected the EC firmware requiring QR_EC issued when SCI_EVT set\n");
EC_FLAGS_QUERY_HANDSHAKE = 1;
return 0;
}
static int ec_clear_on_resume(const struct dmi_system_id *id)
{
pr_debug("Detected system needing EC poll on resume.\n");
EC_FLAGS_CLEAR_ON_RESUME = 1;
return 0;
}
int __init acpi_ec_ecdt_probe(void)
{
acpi_status status;
struct acpi_ec *saved_ec = NULL;
struct acpi_table_ecdt *ecdt_ptr;
boot_ec = make_acpi_ec();
if (!boot_ec)
return -ENOMEM;
dmi_check_system(ec_dmi_table);
status = acpi_get_table(ACPI_SIG_ECDT, 1,
(struct acpi_table_header **)&ecdt_ptr);
if (ACPI_SUCCESS(status)) {
pr_info("EC description table is found, configuring boot EC\n");
boot_ec->command_addr = ecdt_ptr->control.address;
boot_ec->data_addr = ecdt_ptr->data.address;
boot_ec->gpe = ecdt_ptr->gpe;
boot_ec->handle = ACPI_ROOT_OBJECT;
acpi_get_handle(ACPI_ROOT_OBJECT, ecdt_ptr->id,
&boot_ec->handle);
if (!EC_FLAGS_VALIDATE_ECDT)
goto install;
saved_ec = kmemdup(boot_ec, sizeof(struct acpi_ec), GFP_KERNEL);
if (!saved_ec)
return -ENOMEM;
}
if (EC_FLAGS_SKIP_DSDT_SCAN) {
kfree(saved_ec);
return -ENODEV;
}
pr_debug("Look up EC in DSDT\n");
status = acpi_get_devices(ec_device_ids[0].id, ec_parse_device,
boot_ec, NULL);
if (ACPI_FAILURE(status) || !boot_ec->handle)
goto error;
if (saved_ec) {
if (saved_ec->command_addr != boot_ec->command_addr ||
saved_ec->data_addr != boot_ec->data_addr ||
saved_ec->gpe != boot_ec->gpe ||
saved_ec->handle != boot_ec->handle)
pr_info("ASUSTek keeps feeding us with broken "
"ECDT tables, which are very hard to workaround. "
"Trying to use DSDT EC info instead. Please send "
"output of acpidump to linux-acpi@vger.kernel.org\n");
kfree(saved_ec);
saved_ec = NULL;
} else {
if (!dmi_name_in_vendors("ASUS") ||
!acpi_has_method(boot_ec->handle, "_INI"))
return -ENODEV;
}
install:
if (!ec_install_handlers(boot_ec)) {
first_ec = boot_ec;
return 0;
}
error:
kfree(boot_ec);
kfree(saved_ec);
boot_ec = NULL;
return -ENODEV;
}
int __init acpi_ec_init(void)
{
int result = 0;
result = acpi_bus_register_driver(&acpi_ec_driver);
if (result < 0)
return -ENODEV;
return result;
}
