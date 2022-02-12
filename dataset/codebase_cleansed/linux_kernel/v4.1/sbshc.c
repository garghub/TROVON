static inline int smb_hc_read(struct acpi_smb_hc *hc, u8 address, u8 *data)
{
return ec_read(hc->offset + address, data);
}
static inline int smb_hc_write(struct acpi_smb_hc *hc, u8 address, u8 data)
{
return ec_write(hc->offset + address, data);
}
static inline int smb_check_done(struct acpi_smb_hc *hc)
{
union acpi_smb_status status = {.raw = 0};
smb_hc_read(hc, ACPI_SMB_STATUS, &status.raw);
return status.fields.done && (status.fields.status == SMBUS_OK);
}
static int wait_transaction_complete(struct acpi_smb_hc *hc, int timeout)
{
if (wait_event_timeout(hc->wait, smb_check_done(hc),
msecs_to_jiffies(timeout)))
return 0;
if (smb_check_done(hc))
return 0;
else
return -ETIME;
}
static int acpi_smbus_transaction(struct acpi_smb_hc *hc, u8 protocol,
u8 address, u8 command, u8 *data, u8 length)
{
int ret = -EFAULT, i;
u8 temp, sz = 0;
if (!hc) {
printk(KERN_ERR PREFIX "host controller is not configured\n");
return ret;
}
mutex_lock(&hc->lock);
if (macbook)
udelay(5);
if (smb_hc_read(hc, ACPI_SMB_PROTOCOL, &temp))
goto end;
if (temp) {
ret = -EBUSY;
goto end;
}
smb_hc_write(hc, ACPI_SMB_COMMAND, command);
if (!(protocol & 0x01)) {
smb_hc_write(hc, ACPI_SMB_BLOCK_COUNT, length);
for (i = 0; i < length; ++i)
smb_hc_write(hc, ACPI_SMB_DATA + i, data[i]);
}
smb_hc_write(hc, ACPI_SMB_ADDRESS, address << 1);
smb_hc_write(hc, ACPI_SMB_PROTOCOL, protocol);
ret = wait_transaction_complete(hc, 1000);
if (ret || !(protocol & 0x01))
goto end;
switch (protocol) {
case SMBUS_RECEIVE_BYTE:
case SMBUS_READ_BYTE:
sz = 1;
break;
case SMBUS_READ_WORD:
sz = 2;
break;
case SMBUS_READ_BLOCK:
if (smb_hc_read(hc, ACPI_SMB_BLOCK_COUNT, &sz)) {
ret = -EFAULT;
goto end;
}
sz &= 0x1f;
break;
}
for (i = 0; i < sz; ++i)
smb_hc_read(hc, ACPI_SMB_DATA + i, &data[i]);
end:
mutex_unlock(&hc->lock);
return ret;
}
int acpi_smbus_read(struct acpi_smb_hc *hc, u8 protocol, u8 address,
u8 command, u8 *data)
{
return acpi_smbus_transaction(hc, protocol, address, command, data, 0);
}
int acpi_smbus_write(struct acpi_smb_hc *hc, u8 protocol, u8 address,
u8 command, u8 *data, u8 length)
{
return acpi_smbus_transaction(hc, protocol, address, command, data, length);
}
int acpi_smbus_register_callback(struct acpi_smb_hc *hc,
smbus_alarm_callback callback, void *context)
{
mutex_lock(&hc->lock);
hc->callback = callback;
hc->context = context;
mutex_unlock(&hc->lock);
return 0;
}
int acpi_smbus_unregister_callback(struct acpi_smb_hc *hc)
{
mutex_lock(&hc->lock);
hc->callback = NULL;
hc->context = NULL;
mutex_unlock(&hc->lock);
return 0;
}
static inline void acpi_smbus_callback(void *context)
{
struct acpi_smb_hc *hc = context;
if (hc->callback)
hc->callback(hc->context);
}
static int smbus_alarm(void *context)
{
struct acpi_smb_hc *hc = context;
union acpi_smb_status status;
u8 address;
if (smb_hc_read(hc, ACPI_SMB_STATUS, &status.raw))
return 0;
if (status.fields.done)
wake_up(&hc->wait);
if (!status.fields.alarm)
return 0;
mutex_lock(&hc->lock);
smb_hc_read(hc, ACPI_SMB_ALARM_ADDRESS, &address);
status.fields.alarm = 0;
smb_hc_write(hc, ACPI_SMB_STATUS, status.raw);
switch (address >> 1) {
case ACPI_SBS_CHARGER:
case ACPI_SBS_MANAGER:
case ACPI_SBS_BATTERY:
acpi_os_execute(OSL_NOTIFY_HANDLER,
acpi_smbus_callback, hc);
default:;
}
mutex_unlock(&hc->lock);
return 0;
}
static int macbook_dmi_match(const struct dmi_system_id *d)
{
pr_debug("Detected MacBook, enabling workaround\n");
macbook = true;
return 0;
}
static int acpi_smbus_hc_add(struct acpi_device *device)
{
int status;
unsigned long long val;
struct acpi_smb_hc *hc;
dmi_check_system(acpi_smbus_dmi_table);
if (!device)
return -EINVAL;
status = acpi_evaluate_integer(device->handle, "_EC", NULL, &val);
if (ACPI_FAILURE(status)) {
printk(KERN_ERR PREFIX "error obtaining _EC.\n");
return -EIO;
}
strcpy(acpi_device_name(device), ACPI_SMB_HC_DEVICE_NAME);
strcpy(acpi_device_class(device), ACPI_SMB_HC_CLASS);
hc = kzalloc(sizeof(struct acpi_smb_hc), GFP_KERNEL);
if (!hc)
return -ENOMEM;
mutex_init(&hc->lock);
init_waitqueue_head(&hc->wait);
hc->ec = acpi_driver_data(device->parent);
hc->offset = (val >> 8) & 0xff;
hc->query_bit = val & 0xff;
device->driver_data = hc;
acpi_ec_add_query_handler(hc->ec, hc->query_bit, NULL, smbus_alarm, hc);
printk(KERN_INFO PREFIX "SBS HC: EC = 0x%p, offset = 0x%0x, query_bit = 0x%0x\n",
hc->ec, hc->offset, hc->query_bit);
return 0;
}
static int acpi_smbus_hc_remove(struct acpi_device *device)
{
struct acpi_smb_hc *hc;
if (!device)
return -EINVAL;
hc = acpi_driver_data(device);
acpi_ec_remove_query_handler(hc->ec, hc->query_bit);
kfree(hc);
device->driver_data = NULL;
return 0;
}
