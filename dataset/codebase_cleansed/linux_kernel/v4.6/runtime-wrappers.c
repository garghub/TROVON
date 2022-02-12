static efi_status_t virt_efi_get_time(efi_time_t *tm, efi_time_cap_t *tc)
{
efi_status_t status;
spin_lock(&efi_runtime_lock);
status = efi_call_virt(get_time, tm, tc);
spin_unlock(&efi_runtime_lock);
return status;
}
static efi_status_t virt_efi_set_time(efi_time_t *tm)
{
efi_status_t status;
spin_lock(&efi_runtime_lock);
status = efi_call_virt(set_time, tm);
spin_unlock(&efi_runtime_lock);
return status;
}
static efi_status_t virt_efi_get_wakeup_time(efi_bool_t *enabled,
efi_bool_t *pending,
efi_time_t *tm)
{
efi_status_t status;
spin_lock(&efi_runtime_lock);
status = efi_call_virt(get_wakeup_time, enabled, pending, tm);
spin_unlock(&efi_runtime_lock);
return status;
}
static efi_status_t virt_efi_set_wakeup_time(efi_bool_t enabled, efi_time_t *tm)
{
efi_status_t status;
spin_lock(&efi_runtime_lock);
status = efi_call_virt(set_wakeup_time, enabled, tm);
spin_unlock(&efi_runtime_lock);
return status;
}
static efi_status_t virt_efi_get_variable(efi_char16_t *name,
efi_guid_t *vendor,
u32 *attr,
unsigned long *data_size,
void *data)
{
efi_status_t status;
spin_lock(&efi_runtime_lock);
status = efi_call_virt(get_variable, name, vendor, attr, data_size,
data);
spin_unlock(&efi_runtime_lock);
return status;
}
static efi_status_t virt_efi_get_next_variable(unsigned long *name_size,
efi_char16_t *name,
efi_guid_t *vendor)
{
efi_status_t status;
spin_lock(&efi_runtime_lock);
status = efi_call_virt(get_next_variable, name_size, name, vendor);
spin_unlock(&efi_runtime_lock);
return status;
}
static efi_status_t virt_efi_set_variable(efi_char16_t *name,
efi_guid_t *vendor,
u32 attr,
unsigned long data_size,
void *data)
{
efi_status_t status;
spin_lock(&efi_runtime_lock);
status = efi_call_virt(set_variable, name, vendor, attr, data_size,
data);
spin_unlock(&efi_runtime_lock);
return status;
}
static efi_status_t
virt_efi_set_variable_nonblocking(efi_char16_t *name, efi_guid_t *vendor,
u32 attr, unsigned long data_size,
void *data)
{
efi_status_t status;
if (!spin_trylock(&efi_runtime_lock))
return EFI_NOT_READY;
status = efi_call_virt(set_variable, name, vendor, attr, data_size,
data);
spin_unlock(&efi_runtime_lock);
return status;
}
static efi_status_t virt_efi_query_variable_info(u32 attr,
u64 *storage_space,
u64 *remaining_space,
u64 *max_variable_size)
{
efi_status_t status;
if (efi.runtime_version < EFI_2_00_SYSTEM_TABLE_REVISION)
return EFI_UNSUPPORTED;
spin_lock(&efi_runtime_lock);
status = efi_call_virt(query_variable_info, attr, storage_space,
remaining_space, max_variable_size);
spin_unlock(&efi_runtime_lock);
return status;
}
static efi_status_t
virt_efi_query_variable_info_nonblocking(u32 attr,
u64 *storage_space,
u64 *remaining_space,
u64 *max_variable_size)
{
efi_status_t status;
if (efi.runtime_version < EFI_2_00_SYSTEM_TABLE_REVISION)
return EFI_UNSUPPORTED;
if (!spin_trylock(&efi_runtime_lock))
return EFI_NOT_READY;
status = efi_call_virt(query_variable_info, attr, storage_space,
remaining_space, max_variable_size);
spin_unlock(&efi_runtime_lock);
return status;
}
static efi_status_t virt_efi_get_next_high_mono_count(u32 *count)
{
efi_status_t status;
spin_lock(&efi_runtime_lock);
status = efi_call_virt(get_next_high_mono_count, count);
spin_unlock(&efi_runtime_lock);
return status;
}
static void virt_efi_reset_system(int reset_type,
efi_status_t status,
unsigned long data_size,
efi_char16_t *data)
{
spin_lock(&efi_runtime_lock);
__efi_call_virt(reset_system, reset_type, status, data_size, data);
spin_unlock(&efi_runtime_lock);
}
static efi_status_t virt_efi_update_capsule(efi_capsule_header_t **capsules,
unsigned long count,
unsigned long sg_list)
{
efi_status_t status;
if (efi.runtime_version < EFI_2_00_SYSTEM_TABLE_REVISION)
return EFI_UNSUPPORTED;
spin_lock(&efi_runtime_lock);
status = efi_call_virt(update_capsule, capsules, count, sg_list);
spin_unlock(&efi_runtime_lock);
return status;
}
static efi_status_t virt_efi_query_capsule_caps(efi_capsule_header_t **capsules,
unsigned long count,
u64 *max_size,
int *reset_type)
{
efi_status_t status;
if (efi.runtime_version < EFI_2_00_SYSTEM_TABLE_REVISION)
return EFI_UNSUPPORTED;
spin_lock(&efi_runtime_lock);
status = efi_call_virt(query_capsule_caps, capsules, count, max_size,
reset_type);
spin_unlock(&efi_runtime_lock);
return status;
}
void efi_native_runtime_setup(void)
{
efi.get_time = virt_efi_get_time;
efi.set_time = virt_efi_set_time;
efi.get_wakeup_time = virt_efi_get_wakeup_time;
efi.set_wakeup_time = virt_efi_set_wakeup_time;
efi.get_variable = virt_efi_get_variable;
efi.get_next_variable = virt_efi_get_next_variable;
efi.set_variable = virt_efi_set_variable;
efi.set_variable_nonblocking = virt_efi_set_variable_nonblocking;
efi.get_next_high_mono_count = virt_efi_get_next_high_mono_count;
efi.reset_system = virt_efi_reset_system;
efi.query_variable_info = virt_efi_query_variable_info;
efi.query_variable_info_nonblocking = virt_efi_query_variable_info_nonblocking;
efi.update_capsule = virt_efi_update_capsule;
efi.query_capsule_caps = virt_efi_query_capsule_caps;
}
