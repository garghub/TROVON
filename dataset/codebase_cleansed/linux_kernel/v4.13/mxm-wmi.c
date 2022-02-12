int mxm_wmi_call_mxds(int adapter)
{
struct mxds_args args = {
.func = MXM_WMMX_FUNC_MXDS,
.args = 0,
.xarg = 1,
};
struct acpi_buffer input = { (acpi_size)sizeof(args), &args };
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
acpi_status status;
printk("calling mux switch %d\n", adapter);
status = wmi_evaluate_method(MXM_WMMX_GUID, 0x1, adapter, &input,
&output);
if (ACPI_FAILURE(status))
return status;
printk("mux switched %d\n", status);
return 0;
}
int mxm_wmi_call_mxmx(int adapter)
{
struct mxds_args args = {
.func = MXM_WMMX_FUNC_MXMX,
.args = 0,
.xarg = 1,
};
struct acpi_buffer input = { (acpi_size)sizeof(args), &args };
struct acpi_buffer output = { ACPI_ALLOCATE_BUFFER, NULL };
acpi_status status;
printk("calling mux switch %d\n", adapter);
status = wmi_evaluate_method(MXM_WMMX_GUID, 0x1, adapter, &input,
&output);
if (ACPI_FAILURE(status))
return status;
printk("mux mutex set switched %d\n", status);
return 0;
}
bool mxm_wmi_supported(void)
{
bool guid_valid;
guid_valid = wmi_has_guid(MXM_WMMX_GUID);
return guid_valid;
}
static int __init mxm_wmi_init(void)
{
return 0;
}
static void __exit mxm_wmi_exit(void)
{
}
