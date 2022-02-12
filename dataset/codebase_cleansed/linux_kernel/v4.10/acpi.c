static int xen_acpi_notify_hypervisor_state(u8 sleep_state,
u32 val_a, u32 val_b,
bool extended)
{
unsigned int bits = extended ? 8 : 16;
struct xen_platform_op op = {
.cmd = XENPF_enter_acpi_sleep,
.interface_version = XENPF_INTERFACE_VERSION,
.u.enter_acpi_sleep = {
.val_a = (u16)val_a,
.val_b = (u16)val_b,
.sleep_state = sleep_state,
.flags = extended ? XENPF_ACPI_SLEEP_EXTENDED : 0,
},
};
if (WARN((val_a & (~0 << bits)) || (val_b & (~0 << bits)),
"Using more than %u bits of sleep control values %#x/%#x!"
"Email xen-devel@lists.xen.org - Thank you.\n", \
bits, val_a, val_b))
return -1;
HYPERVISOR_platform_op(&op);
return 1;
}
int xen_acpi_notify_hypervisor_sleep(u8 sleep_state,
u32 pm1a_cnt, u32 pm1b_cnt)
{
return xen_acpi_notify_hypervisor_state(sleep_state, pm1a_cnt,
pm1b_cnt, false);
}
int xen_acpi_notify_hypervisor_extended_sleep(u8 sleep_state,
u32 val_a, u32 val_b)
{
return xen_acpi_notify_hypervisor_state(sleep_state, val_a,
val_b, true);
}
