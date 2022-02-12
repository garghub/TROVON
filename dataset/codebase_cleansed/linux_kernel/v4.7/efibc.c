static void efibc_str_to_str16(const char *str, efi_char16_t *str16)
{
size_t i;
for (i = 0; i < strlen(str); i++)
str16[i] = str[i];
str16[i] = '\0';
}
static int efibc_set_variable(const char *name, const char *value)
{
int ret;
efi_guid_t guid = LINUX_EFI_LOADER_ENTRY_GUID;
struct efivar_entry *entry;
size_t size = (strlen(value) + 1) * sizeof(efi_char16_t);
if (size > sizeof(entry->var.Data)) {
pr_err("value is too large");
return -EINVAL;
}
entry = kmalloc(sizeof(*entry), GFP_KERNEL);
if (!entry) {
pr_err("failed to allocate efivar entry");
return -ENOMEM;
}
efibc_str_to_str16(name, entry->var.VariableName);
efibc_str_to_str16(value, (efi_char16_t *)entry->var.Data);
memcpy(&entry->var.VendorGuid, &guid, sizeof(guid));
ret = efivar_entry_set(entry,
EFI_VARIABLE_NON_VOLATILE
| EFI_VARIABLE_BOOTSERVICE_ACCESS
| EFI_VARIABLE_RUNTIME_ACCESS,
size, entry->var.Data, NULL);
if (ret)
pr_err("failed to set %s EFI variable: 0x%x\n",
name, ret);
kfree(entry);
return ret;
}
static int efibc_reboot_notifier_call(struct notifier_block *notifier,
unsigned long event, void *data)
{
const char *reason = "shutdown";
int ret;
if (event == SYS_RESTART)
reason = "reboot";
ret = efibc_set_variable("LoaderEntryRebootReason", reason);
if (ret || !data)
return NOTIFY_DONE;
efibc_set_variable("LoaderEntryOneShot", (char *)data);
return NOTIFY_DONE;
}
static int __init efibc_init(void)
{
int ret;
if (!efi_enabled(EFI_RUNTIME_SERVICES))
return -ENODEV;
ret = register_reboot_notifier(&efibc_reboot_notifier);
if (ret)
pr_err("unable to register reboot notifier\n");
return ret;
}
static void __exit efibc_exit(void)
{
unregister_reboot_notifier(&efibc_reboot_notifier);
}
