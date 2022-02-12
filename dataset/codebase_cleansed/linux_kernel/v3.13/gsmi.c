static struct gsmi_buf *gsmi_buf_alloc(void)
{
struct gsmi_buf *smibuf;
smibuf = kzalloc(sizeof(*smibuf), GFP_KERNEL);
if (!smibuf) {
printk(KERN_ERR "gsmi: out of memory\n");
return NULL;
}
smibuf->start = dma_pool_alloc(gsmi_dev.dma_pool, GFP_KERNEL,
&smibuf->handle);
if (!smibuf->start) {
printk(KERN_ERR "gsmi: failed to allocate name buffer\n");
kfree(smibuf);
return NULL;
}
smibuf->length = GSMI_BUF_SIZE;
smibuf->address = (u32)virt_to_phys(smibuf->start);
return smibuf;
}
static void gsmi_buf_free(struct gsmi_buf *smibuf)
{
if (smibuf) {
if (smibuf->start)
dma_pool_free(gsmi_dev.dma_pool, smibuf->start,
smibuf->handle);
kfree(smibuf);
}
}
static int gsmi_exec(u8 func, u8 sub)
{
u16 cmd = (sub << 8) | func;
u16 result = 0;
int rc = 0;
if (gsmi_dev.handshake_type == GSMI_HANDSHAKE_CF) {
asm volatile (
"stc\n"
"outb %%al, %%dx\n"
"1: jc 1b\n"
: "=a" (result)
: "0" (cmd),
"d" (gsmi_dev.smi_cmd),
"b" (gsmi_dev.param_buf->address)
: "memory", "cc"
);
} else if (gsmi_dev.handshake_type == GSMI_HANDSHAKE_SPIN) {
asm volatile (
"outb %%al, %%dx\n"
"1: loop 1b\n"
: "=a" (result)
: "0" (cmd),
"d" (gsmi_dev.smi_cmd),
"b" (gsmi_dev.param_buf->address),
"c" (spincount)
: "memory", "cc"
);
} else {
asm volatile (
"outb %%al, %%dx\n\t"
: "=a" (result)
: "0" (cmd),
"d" (gsmi_dev.smi_cmd),
"b" (gsmi_dev.param_buf->address)
: "memory", "cc"
);
}
switch (result) {
case GSMI_SUCCESS:
break;
case GSMI_VAR_NOT_FOUND:
rc = 1;
break;
case GSMI_INVALID_PARAMETER:
printk(KERN_ERR "gsmi: exec 0x%04x: Invalid parameter\n", cmd);
rc = -EINVAL;
break;
case GSMI_BUFFER_TOO_SMALL:
printk(KERN_ERR "gsmi: exec 0x%04x: Buffer too small\n", cmd);
rc = -ENOMEM;
break;
case GSMI_UNSUPPORTED:
case GSMI_UNSUPPORTED2:
if (sub != GSMI_CMD_HANDSHAKE_TYPE)
printk(KERN_ERR "gsmi: exec 0x%04x: Not supported\n",
cmd);
rc = -ENOSYS;
break;
case GSMI_NOT_READY:
printk(KERN_ERR "gsmi: exec 0x%04x: Not ready\n", cmd);
rc = -EBUSY;
break;
case GSMI_DEVICE_ERROR:
printk(KERN_ERR "gsmi: exec 0x%04x: Device error\n", cmd);
rc = -EFAULT;
break;
case GSMI_NOT_FOUND:
printk(KERN_ERR "gsmi: exec 0x%04x: Data not found\n", cmd);
rc = -ENOENT;
break;
case GSMI_LOG_FULL:
printk(KERN_ERR "gsmi: exec 0x%04x: Log full\n", cmd);
rc = -ENOSPC;
break;
case GSMI_HANDSHAKE_CF:
case GSMI_HANDSHAKE_SPIN:
case GSMI_HANDSHAKE_NONE:
rc = result;
break;
default:
printk(KERN_ERR "gsmi: exec 0x%04x: Unknown error 0x%04x\n",
cmd, result);
rc = -ENXIO;
}
return rc;
}
static efi_status_t gsmi_get_variable(efi_char16_t *name,
efi_guid_t *vendor, u32 *attr,
unsigned long *data_size,
void *data)
{
struct gsmi_nvram_var_param param = {
.name_ptr = gsmi_dev.name_buf->address,
.data_ptr = gsmi_dev.data_buf->address,
.data_len = (u32)*data_size,
};
efi_status_t ret = EFI_SUCCESS;
unsigned long flags;
size_t name_len = ucs2_strnlen(name, GSMI_BUF_SIZE / 2);
int rc;
if (name_len >= GSMI_BUF_SIZE / 2)
return EFI_BAD_BUFFER_SIZE;
spin_lock_irqsave(&gsmi_dev.lock, flags);
memcpy(&param.guid, vendor, sizeof(param.guid));
memset(gsmi_dev.name_buf->start, 0, gsmi_dev.name_buf->length);
memcpy(gsmi_dev.name_buf->start, name, name_len * 2);
memset(gsmi_dev.data_buf->start, 0, gsmi_dev.data_buf->length);
memset(gsmi_dev.param_buf->start, 0, gsmi_dev.param_buf->length);
memcpy(gsmi_dev.param_buf->start, &param, sizeof(param));
rc = gsmi_exec(GSMI_CALLBACK, GSMI_CMD_GET_NVRAM_VAR);
if (rc < 0) {
printk(KERN_ERR "gsmi: Get Variable failed\n");
ret = EFI_LOAD_ERROR;
} else if (rc == 1) {
ret = EFI_NOT_FOUND;
} else {
memcpy(&param, gsmi_dev.param_buf->start, sizeof(param));
*data_size = min_t(unsigned long, *data_size,
gsmi_dev.data_buf->length);
*data_size = min_t(unsigned long, *data_size, param.data_len);
memcpy(data, gsmi_dev.data_buf->start, *data_size);
*attr = EFI_VARIABLE_NON_VOLATILE |
EFI_VARIABLE_BOOTSERVICE_ACCESS |
EFI_VARIABLE_RUNTIME_ACCESS;
}
spin_unlock_irqrestore(&gsmi_dev.lock, flags);
return ret;
}
static efi_status_t gsmi_get_next_variable(unsigned long *name_size,
efi_char16_t *name,
efi_guid_t *vendor)
{
struct gsmi_get_next_var_param param = {
.name_ptr = gsmi_dev.name_buf->address,
.name_len = gsmi_dev.name_buf->length,
};
efi_status_t ret = EFI_SUCCESS;
int rc;
unsigned long flags;
if (*name_size != GSMI_BUF_SIZE)
return EFI_BAD_BUFFER_SIZE;
if (ucs2_strnlen(name, GSMI_BUF_SIZE / 2) == GSMI_BUF_SIZE / 2)
return EFI_INVALID_PARAMETER;
spin_lock_irqsave(&gsmi_dev.lock, flags);
memcpy(&param.guid, vendor, sizeof(param.guid));
memcpy(gsmi_dev.name_buf->start, name, *name_size);
memset(gsmi_dev.param_buf->start, 0, gsmi_dev.param_buf->length);
memcpy(gsmi_dev.param_buf->start, &param, sizeof(param));
rc = gsmi_exec(GSMI_CALLBACK, GSMI_CMD_GET_NEXT_VAR);
if (rc < 0) {
printk(KERN_ERR "gsmi: Get Next Variable Name failed\n");
ret = EFI_LOAD_ERROR;
} else if (rc == 1) {
ret = EFI_NOT_FOUND;
} else {
memcpy(&param, gsmi_dev.param_buf->start, sizeof(param));
memcpy(name, gsmi_dev.name_buf->start, GSMI_BUF_SIZE);
*name_size = ucs2_strnlen(name, GSMI_BUF_SIZE / 2) * 2;
memcpy(vendor, &param.guid, sizeof(param.guid));
ret = EFI_SUCCESS;
}
spin_unlock_irqrestore(&gsmi_dev.lock, flags);
return ret;
}
static efi_status_t gsmi_set_variable(efi_char16_t *name,
efi_guid_t *vendor,
u32 attr,
unsigned long data_size,
void *data)
{
struct gsmi_nvram_var_param param = {
.name_ptr = gsmi_dev.name_buf->address,
.data_ptr = gsmi_dev.data_buf->address,
.data_len = (u32)data_size,
.attributes = EFI_VARIABLE_NON_VOLATILE |
EFI_VARIABLE_BOOTSERVICE_ACCESS |
EFI_VARIABLE_RUNTIME_ACCESS,
};
size_t name_len = ucs2_strnlen(name, GSMI_BUF_SIZE / 2);
efi_status_t ret = EFI_SUCCESS;
int rc;
unsigned long flags;
if (name_len >= GSMI_BUF_SIZE / 2)
return EFI_BAD_BUFFER_SIZE;
spin_lock_irqsave(&gsmi_dev.lock, flags);
memcpy(&param.guid, vendor, sizeof(param.guid));
memset(gsmi_dev.name_buf->start, 0, gsmi_dev.name_buf->length);
memcpy(gsmi_dev.name_buf->start, name, name_len * 2);
memset(gsmi_dev.data_buf->start, 0, gsmi_dev.data_buf->length);
memcpy(gsmi_dev.data_buf->start, data, data_size);
memset(gsmi_dev.param_buf->start, 0, gsmi_dev.param_buf->length);
memcpy(gsmi_dev.param_buf->start, &param, sizeof(param));
rc = gsmi_exec(GSMI_CALLBACK, GSMI_CMD_SET_NVRAM_VAR);
if (rc < 0) {
printk(KERN_ERR "gsmi: Set Variable failed\n");
ret = EFI_INVALID_PARAMETER;
}
spin_unlock_irqrestore(&gsmi_dev.lock, flags);
return ret;
}
static ssize_t eventlog_write(struct file *filp, struct kobject *kobj,
struct bin_attribute *bin_attr,
char *buf, loff_t pos, size_t count)
{
struct gsmi_set_eventlog_param param = {
.data_ptr = gsmi_dev.data_buf->address,
};
int rc = 0;
unsigned long flags;
if (count < sizeof(u32))
return -EINVAL;
param.type = *(u32 *)buf;
count -= sizeof(u32);
buf += sizeof(u32);
if (count > gsmi_dev.data_buf->length)
return -EINVAL;
param.data_len = count - sizeof(u32);
spin_lock_irqsave(&gsmi_dev.lock, flags);
memset(gsmi_dev.data_buf->start, 0, gsmi_dev.data_buf->length);
memcpy(gsmi_dev.data_buf->start, buf, param.data_len);
memset(gsmi_dev.param_buf->start, 0, gsmi_dev.param_buf->length);
memcpy(gsmi_dev.param_buf->start, &param, sizeof(param));
rc = gsmi_exec(GSMI_CALLBACK, GSMI_CMD_SET_EVENT_LOG);
if (rc < 0)
printk(KERN_ERR "gsmi: Set Event Log failed\n");
spin_unlock_irqrestore(&gsmi_dev.lock, flags);
return rc;
}
static ssize_t gsmi_clear_eventlog_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
int rc;
unsigned long flags;
unsigned long val;
struct {
u32 percentage;
u32 data_type;
} param;
rc = kstrtoul(buf, 0, &val);
if (rc)
return rc;
if (val > 100)
return -EINVAL;
param.percentage = val;
param.data_type = 0;
spin_lock_irqsave(&gsmi_dev.lock, flags);
memset(gsmi_dev.param_buf->start, 0, gsmi_dev.param_buf->length);
memcpy(gsmi_dev.param_buf->start, &param, sizeof(param));
rc = gsmi_exec(GSMI_CALLBACK, GSMI_CMD_CLEAR_EVENT_LOG);
spin_unlock_irqrestore(&gsmi_dev.lock, flags);
if (rc)
return rc;
return count;
}
static ssize_t gsmi_clear_config_store(struct kobject *kobj,
struct kobj_attribute *attr,
const char *buf, size_t count)
{
int rc;
unsigned long flags;
spin_lock_irqsave(&gsmi_dev.lock, flags);
memset(gsmi_dev.param_buf->start, 0, gsmi_dev.param_buf->length);
rc = gsmi_exec(GSMI_CALLBACK, GSMI_CMD_CLEAR_CONFIG);
spin_unlock_irqrestore(&gsmi_dev.lock, flags);
if (rc)
return rc;
return count;
}
static int gsmi_shutdown_reason(int reason)
{
struct gsmi_log_entry_type_1 entry = {
.type = GSMI_LOG_ENTRY_TYPE_KERNEL,
.instance = reason,
};
struct gsmi_set_eventlog_param param = {
.data_len = sizeof(entry),
.type = 1,
};
static int saved_reason;
int rc = 0;
unsigned long flags;
if (saved_reason & (1 << reason))
return 0;
spin_lock_irqsave(&gsmi_dev.lock, flags);
saved_reason |= (1 << reason);
memset(gsmi_dev.data_buf->start, 0, gsmi_dev.data_buf->length);
memcpy(gsmi_dev.data_buf->start, &entry, sizeof(entry));
param.data_ptr = gsmi_dev.data_buf->address;
memset(gsmi_dev.param_buf->start, 0, gsmi_dev.param_buf->length);
memcpy(gsmi_dev.param_buf->start, &param, sizeof(param));
rc = gsmi_exec(GSMI_CALLBACK, GSMI_CMD_SET_EVENT_LOG);
spin_unlock_irqrestore(&gsmi_dev.lock, flags);
if (rc < 0)
printk(KERN_ERR "gsmi: Log Shutdown Reason failed\n");
else
printk(KERN_EMERG "gsmi: Log Shutdown Reason 0x%02x\n",
reason);
return rc;
}
static int gsmi_reboot_callback(struct notifier_block *nb,
unsigned long reason, void *arg)
{
gsmi_shutdown_reason(GSMI_SHUTDOWN_CLEAN);
return NOTIFY_DONE;
}
static int gsmi_die_callback(struct notifier_block *nb,
unsigned long reason, void *arg)
{
if (reason == DIE_OOPS)
gsmi_shutdown_reason(GSMI_SHUTDOWN_OOPS);
return NOTIFY_DONE;
}
static int gsmi_panic_callback(struct notifier_block *nb,
unsigned long reason, void *arg)
{
gsmi_shutdown_reason(GSMI_SHUTDOWN_PANIC);
return NOTIFY_DONE;
}
static u64 __init local_hash_64(u64 val, unsigned bits)
{
u64 hash = val;
u64 n = hash;
n <<= 18;
hash -= n;
n <<= 33;
hash -= n;
n <<= 3;
hash += n;
n <<= 3;
hash -= n;
n <<= 4;
hash += n;
n <<= 2;
hash += n;
return hash >> (64 - bits);
}
static u32 __init hash_oem_table_id(char s[8])
{
u64 input;
memcpy(&input, s, 8);
return local_hash_64(input, 32);
}
static __init int gsmi_system_valid(void)
{
u32 hash;
if (!dmi_check_system(gsmi_dmi_table))
return -ENODEV;
if (!strncmp(acpi_gbl_FADT.header.oem_table_id, "FACP", 4)) {
printk(KERN_INFO "gsmi: Board is too old\n");
return -ENODEV;
}
hash = hash_oem_table_id(acpi_gbl_FADT.header.oem_table_id);
if (hash == QUIRKY_BOARD_HASH) {
const char *bios_ver = dmi_get_system_info(DMI_BIOS_VERSION);
if (strncmp(bios_ver, "1.0", 3) == 0) {
pr_info("gsmi: disabled on this board's BIOS %s\n",
bios_ver);
return -ENODEV;
}
}
if (acpi_gbl_FADT.smi_command == 0) {
pr_info("gsmi: missing smi_command\n");
return -ENODEV;
}
return 0;
}
static __init int gsmi_init(void)
{
unsigned long flags;
int ret;
ret = gsmi_system_valid();
if (ret)
return ret;
gsmi_dev.smi_cmd = acpi_gbl_FADT.smi_command;
gsmi_dev.pdev = platform_device_register_full(&gsmi_dev_info);
if (IS_ERR(gsmi_dev.pdev)) {
printk(KERN_ERR "gsmi: unable to register platform device\n");
return PTR_ERR(gsmi_dev.pdev);
}
spin_lock_init(&gsmi_dev.lock);
ret = -ENOMEM;
gsmi_dev.dma_pool = dma_pool_create("gsmi", &gsmi_dev.pdev->dev,
GSMI_BUF_SIZE, GSMI_BUF_ALIGN, 0);
if (!gsmi_dev.dma_pool)
goto out_err;
gsmi_dev.name_buf = gsmi_buf_alloc();
if (!gsmi_dev.name_buf) {
printk(KERN_ERR "gsmi: failed to allocate name buffer\n");
goto out_err;
}
gsmi_dev.data_buf = gsmi_buf_alloc();
if (!gsmi_dev.data_buf) {
printk(KERN_ERR "gsmi: failed to allocate data buffer\n");
goto out_err;
}
gsmi_dev.param_buf = gsmi_buf_alloc();
if (!gsmi_dev.param_buf) {
printk(KERN_ERR "gsmi: failed to allocate param buffer\n");
goto out_err;
}
spin_lock_irqsave(&gsmi_dev.lock, flags);
gsmi_dev.handshake_type = GSMI_HANDSHAKE_SPIN;
gsmi_dev.handshake_type =
gsmi_exec(GSMI_CALLBACK, GSMI_CMD_HANDSHAKE_TYPE);
if (gsmi_dev.handshake_type == -ENOSYS)
gsmi_dev.handshake_type = GSMI_HANDSHAKE_NONE;
spin_unlock_irqrestore(&gsmi_dev.lock, flags);
if (gsmi_dev.handshake_type == -ENXIO) {
printk(KERN_INFO "gsmi version " DRIVER_VERSION
" failed to load\n");
ret = -ENODEV;
goto out_err;
}
ret = -ENOMEM;
gsmi_kobj = kobject_create_and_add("gsmi", firmware_kobj);
if (!gsmi_kobj) {
printk(KERN_INFO "gsmi: Failed to create firmware kobj\n");
goto out_err;
}
ret = sysfs_create_bin_file(gsmi_kobj, &eventlog_bin_attr);
if (ret) {
printk(KERN_INFO "gsmi: Failed to setup eventlog");
goto out_err;
}
ret = sysfs_create_files(gsmi_kobj, gsmi_attrs);
if (ret) {
printk(KERN_INFO "gsmi: Failed to add attrs");
goto out_remove_bin_file;
}
ret = efivars_register(&efivars, &efivar_ops, gsmi_kobj);
if (ret) {
printk(KERN_INFO "gsmi: Failed to register efivars\n");
goto out_remove_sysfs_files;
}
ret = efivars_sysfs_init();
if (ret) {
printk(KERN_INFO "gsmi: Failed to create efivars files\n");
efivars_unregister(&efivars);
goto out_remove_sysfs_files;
}
register_reboot_notifier(&gsmi_reboot_notifier);
register_die_notifier(&gsmi_die_notifier);
atomic_notifier_chain_register(&panic_notifier_list,
&gsmi_panic_notifier);
printk(KERN_INFO "gsmi version " DRIVER_VERSION " loaded\n");
return 0;
out_remove_sysfs_files:
sysfs_remove_files(gsmi_kobj, gsmi_attrs);
out_remove_bin_file:
sysfs_remove_bin_file(gsmi_kobj, &eventlog_bin_attr);
out_err:
kobject_put(gsmi_kobj);
gsmi_buf_free(gsmi_dev.param_buf);
gsmi_buf_free(gsmi_dev.data_buf);
gsmi_buf_free(gsmi_dev.name_buf);
if (gsmi_dev.dma_pool)
dma_pool_destroy(gsmi_dev.dma_pool);
platform_device_unregister(gsmi_dev.pdev);
pr_info("gsmi: failed to load: %d\n", ret);
return ret;
}
static void __exit gsmi_exit(void)
{
unregister_reboot_notifier(&gsmi_reboot_notifier);
unregister_die_notifier(&gsmi_die_notifier);
atomic_notifier_chain_unregister(&panic_notifier_list,
&gsmi_panic_notifier);
efivars_unregister(&efivars);
sysfs_remove_files(gsmi_kobj, gsmi_attrs);
sysfs_remove_bin_file(gsmi_kobj, &eventlog_bin_attr);
kobject_put(gsmi_kobj);
gsmi_buf_free(gsmi_dev.param_buf);
gsmi_buf_free(gsmi_dev.data_buf);
gsmi_buf_free(gsmi_dev.name_buf);
dma_pool_destroy(gsmi_dev.dma_pool);
platform_device_unregister(gsmi_dev.pdev);
}
