acpi_status acpi_set_firmware_waking_vector(u32 physical_address)
{
ACPI_FUNCTION_TRACE(acpi_set_firmware_waking_vector);
acpi_gbl_FACS->firmware_waking_vector = physical_address;
if ((acpi_gbl_FACS->length > 32) && (acpi_gbl_FACS->version >= 1)) {
acpi_gbl_FACS->xfirmware_waking_vector = 0;
}
return_ACPI_STATUS(AE_OK);
}
acpi_status acpi_set_firmware_waking_vector64(u64 physical_address)
{
ACPI_FUNCTION_TRACE(acpi_set_firmware_waking_vector64);
if ((acpi_gbl_FACS->length <= 32) || (acpi_gbl_FACS->version < 1)) {
return_ACPI_STATUS(AE_NOT_EXIST);
}
acpi_gbl_FACS->firmware_waking_vector = 0;
acpi_gbl_FACS->xfirmware_waking_vector = physical_address;
return_ACPI_STATUS(AE_OK);
}
acpi_status asmlinkage acpi_enter_sleep_state_s4bios(void)
{
u32 in_value;
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_enter_sleep_state_s4bios);
status =
acpi_write_bit_register(ACPI_BITREG_WAKE_STATUS, ACPI_CLEAR_STATUS);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_hw_clear_acpi_status();
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_hw_disable_all_gpes();
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
acpi_gbl_system_awake_and_running = FALSE;
status = acpi_hw_enable_all_wakeup_gpes();
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
ACPI_FLUSH_CPU_CACHE();
status = acpi_hw_write_port(acpi_gbl_FADT.smi_command,
(u32)acpi_gbl_FADT.s4_bios_request, 8);
do {
acpi_os_stall(ACPI_USEC_PER_MSEC);
status =
acpi_read_bit_register(ACPI_BITREG_WAKE_STATUS, &in_value);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
} while (!in_value);
return_ACPI_STATUS(AE_OK);
}
static acpi_status acpi_hw_sleep_dispatch(u8 sleep_state, u32 function_id)
{
acpi_status status;
struct acpi_sleep_functions *sleep_functions =
&acpi_sleep_dispatch[function_id];
#if (!ACPI_REDUCED_HARDWARE)
if (acpi_gbl_reduced_hardware || acpi_gbl_FADT.sleep_control.address) {
status = sleep_functions->extended_function(sleep_state);
} else {
status = sleep_functions->legacy_function(sleep_state);
}
return (status);
#else
status = sleep_functions->extended_function(sleep_state);
return (status);
#endif
}
acpi_status acpi_enter_sleep_state_prep(u8 sleep_state)
{
acpi_status status;
struct acpi_object_list arg_list;
union acpi_object arg;
u32 sst_value;
ACPI_FUNCTION_TRACE(acpi_enter_sleep_state_prep);
status = acpi_get_sleep_type_data(sleep_state,
&acpi_gbl_sleep_type_a,
&acpi_gbl_sleep_type_b);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
arg_list.count = 1;
arg_list.pointer = &arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = sleep_state;
status =
acpi_evaluate_object(NULL, METHOD_PATHNAME__PTS, &arg_list, NULL);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND) {
return_ACPI_STATUS(status);
}
switch (sleep_state) {
case ACPI_STATE_S0:
sst_value = ACPI_SST_WORKING;
break;
case ACPI_STATE_S1:
case ACPI_STATE_S2:
case ACPI_STATE_S3:
sst_value = ACPI_SST_SLEEPING;
break;
case ACPI_STATE_S4:
sst_value = ACPI_SST_SLEEP_CONTEXT;
break;
default:
sst_value = ACPI_SST_INDICATOR_OFF;
break;
}
acpi_hw_execute_sleep_method(METHOD_PATHNAME__SST, sst_value);
return_ACPI_STATUS(AE_OK);
}
acpi_status asmlinkage acpi_enter_sleep_state(u8 sleep_state)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_enter_sleep_state);
if ((acpi_gbl_sleep_type_a > ACPI_SLEEP_TYPE_MAX) ||
(acpi_gbl_sleep_type_b > ACPI_SLEEP_TYPE_MAX)) {
ACPI_ERROR((AE_INFO, "Sleep values out of range: A=0x%X B=0x%X",
acpi_gbl_sleep_type_a, acpi_gbl_sleep_type_b));
return_ACPI_STATUS(AE_AML_OPERAND_VALUE);
}
status = acpi_hw_sleep_dispatch(sleep_state, ACPI_SLEEP_FUNCTION_ID);
return_ACPI_STATUS(status);
}
acpi_status acpi_leave_sleep_state_prep(u8 sleep_state)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_leave_sleep_state_prep);
status =
acpi_hw_sleep_dispatch(sleep_state, ACPI_WAKE_PREP_FUNCTION_ID);
return_ACPI_STATUS(status);
}
acpi_status acpi_leave_sleep_state(u8 sleep_state)
{
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_leave_sleep_state);
status = acpi_hw_sleep_dispatch(sleep_state, ACPI_WAKE_FUNCTION_ID);
return_ACPI_STATUS(status);
}
