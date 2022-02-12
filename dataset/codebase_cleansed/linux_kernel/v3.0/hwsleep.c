acpi_status
acpi_set_firmware_waking_vector(u32 physical_address)
{
ACPI_FUNCTION_TRACE(acpi_set_firmware_waking_vector);
acpi_gbl_FACS->firmware_waking_vector = physical_address;
if ((acpi_gbl_FACS->length > 32) && (acpi_gbl_FACS->version >= 1)) {
acpi_gbl_FACS->xfirmware_waking_vector = 0;
}
return_ACPI_STATUS(AE_OK);
}
acpi_status
acpi_set_firmware_waking_vector64(u64 physical_address)
{
ACPI_FUNCTION_TRACE(acpi_set_firmware_waking_vector64);
if ((acpi_gbl_FACS->length <= 32) || (acpi_gbl_FACS->version < 1)) {
return_ACPI_STATUS(AE_NOT_EXIST);
}
acpi_gbl_FACS->firmware_waking_vector = 0;
acpi_gbl_FACS->xfirmware_waking_vector = physical_address;
return_ACPI_STATUS(AE_OK);
}
acpi_status acpi_enter_sleep_state_prep(u8 sleep_state)
{
acpi_status status;
struct acpi_object_list arg_list;
union acpi_object arg;
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
status = acpi_evaluate_object(NULL, METHOD_NAME__PTS, &arg_list, NULL);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND) {
return_ACPI_STATUS(status);
}
switch (sleep_state) {
case ACPI_STATE_S0:
arg.integer.value = ACPI_SST_WORKING;
break;
case ACPI_STATE_S1:
case ACPI_STATE_S2:
case ACPI_STATE_S3:
arg.integer.value = ACPI_SST_SLEEPING;
break;
case ACPI_STATE_S4:
arg.integer.value = ACPI_SST_SLEEP_CONTEXT;
break;
default:
arg.integer.value = ACPI_SST_INDICATOR_OFF;
break;
}
status = acpi_evaluate_object(NULL, METHOD_NAME__SST, &arg_list, NULL);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND) {
ACPI_EXCEPTION((AE_INFO, status,
"While executing method _SST"));
}
return_ACPI_STATUS(AE_OK);
}
acpi_status asmlinkage acpi_enter_sleep_state(u8 sleep_state)
{
u32 pm1a_control;
u32 pm1b_control;
struct acpi_bit_register_info *sleep_type_reg_info;
struct acpi_bit_register_info *sleep_enable_reg_info;
u32 in_value;
struct acpi_object_list arg_list;
union acpi_object arg;
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_enter_sleep_state);
if ((acpi_gbl_sleep_type_a > ACPI_SLEEP_TYPE_MAX) ||
(acpi_gbl_sleep_type_b > ACPI_SLEEP_TYPE_MAX)) {
ACPI_ERROR((AE_INFO, "Sleep values out of range: A=0x%X B=0x%X",
acpi_gbl_sleep_type_a, acpi_gbl_sleep_type_b));
return_ACPI_STATUS(AE_AML_OPERAND_VALUE);
}
sleep_type_reg_info =
acpi_hw_get_bit_register_info(ACPI_BITREG_SLEEP_TYPE);
sleep_enable_reg_info =
acpi_hw_get_bit_register_info(ACPI_BITREG_SLEEP_ENABLE);
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
if (gts) {
arg_list.count = 1;
arg_list.pointer = &arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = sleep_state;
status = acpi_evaluate_object(NULL, METHOD_NAME__GTS, &arg_list, NULL);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND) {
return_ACPI_STATUS(status);
}
}
status = acpi_hw_register_read(ACPI_REGISTER_PM1_CONTROL,
&pm1a_control);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
ACPI_DEBUG_PRINT((ACPI_DB_INIT,
"Entering sleep state [S%u]\n", sleep_state));
pm1a_control &= ~(sleep_type_reg_info->access_bit_mask |
sleep_enable_reg_info->access_bit_mask);
pm1b_control = pm1a_control;
pm1a_control |=
(acpi_gbl_sleep_type_a << sleep_type_reg_info->bit_position);
pm1b_control |=
(acpi_gbl_sleep_type_b << sleep_type_reg_info->bit_position);
status = acpi_hw_write_pm1_control(pm1a_control, pm1b_control);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
pm1a_control |= sleep_enable_reg_info->access_bit_mask;
pm1b_control |= sleep_enable_reg_info->access_bit_mask;
ACPI_FLUSH_CPU_CACHE();
tboot_sleep(sleep_state, pm1a_control, pm1b_control);
status = acpi_hw_write_pm1_control(pm1a_control, pm1b_control);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
if (sleep_state > ACPI_STATE_S3) {
acpi_os_stall(10000000);
status = acpi_hw_register_write(ACPI_REGISTER_PM1_CONTROL,
sleep_enable_reg_info->
access_bit_mask);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
}
do {
status = acpi_read_bit_register(ACPI_BITREG_WAKE_STATUS,
&in_value);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
} while (!in_value);
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
(u32) acpi_gbl_FADT.S4bios_request, 8);
do {
acpi_os_stall(1000);
status =
acpi_read_bit_register(ACPI_BITREG_WAKE_STATUS, &in_value);
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
} while (!in_value);
return_ACPI_STATUS(AE_OK);
}
acpi_status acpi_leave_sleep_state_prep(u8 sleep_state)
{
struct acpi_object_list arg_list;
union acpi_object arg;
acpi_status status;
struct acpi_bit_register_info *sleep_type_reg_info;
struct acpi_bit_register_info *sleep_enable_reg_info;
u32 pm1a_control;
u32 pm1b_control;
ACPI_FUNCTION_TRACE(acpi_leave_sleep_state_prep);
status = acpi_get_sleep_type_data(ACPI_STATE_S0,
&acpi_gbl_sleep_type_a,
&acpi_gbl_sleep_type_b);
if (ACPI_SUCCESS(status)) {
sleep_type_reg_info =
acpi_hw_get_bit_register_info(ACPI_BITREG_SLEEP_TYPE);
sleep_enable_reg_info =
acpi_hw_get_bit_register_info(ACPI_BITREG_SLEEP_ENABLE);
status = acpi_hw_register_read(ACPI_REGISTER_PM1_CONTROL,
&pm1a_control);
if (ACPI_SUCCESS(status)) {
pm1a_control &= ~(sleep_type_reg_info->access_bit_mask |
sleep_enable_reg_info->
access_bit_mask);
pm1b_control = pm1a_control;
pm1a_control |= (acpi_gbl_sleep_type_a <<
sleep_type_reg_info->bit_position);
pm1b_control |= (acpi_gbl_sleep_type_b <<
sleep_type_reg_info->bit_position);
(void)acpi_hw_write_pm1_control(pm1a_control,
pm1b_control);
}
}
if (bfs) {
arg_list.count = 1;
arg_list.pointer = &arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = sleep_state;
status = acpi_evaluate_object(NULL, METHOD_NAME__BFS, &arg_list, NULL);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND) {
ACPI_EXCEPTION((AE_INFO, status, "During Method _BFS"));
}
}
return_ACPI_STATUS(status);
}
acpi_status acpi_leave_sleep_state(u8 sleep_state)
{
struct acpi_object_list arg_list;
union acpi_object arg;
acpi_status status;
ACPI_FUNCTION_TRACE(acpi_leave_sleep_state);
acpi_gbl_sleep_type_a = ACPI_SLEEP_TYPE_INVALID;
arg_list.count = 1;
arg_list.pointer = &arg;
arg.type = ACPI_TYPE_INTEGER;
arg.integer.value = ACPI_SST_WAKING;
status = acpi_evaluate_object(NULL, METHOD_NAME__SST, &arg_list, NULL);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND) {
ACPI_EXCEPTION((AE_INFO, status, "During Method _SST"));
}
status = acpi_hw_disable_all_gpes();
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
status = acpi_hw_enable_all_runtime_gpes();
if (ACPI_FAILURE(status)) {
return_ACPI_STATUS(status);
}
arg.integer.value = sleep_state;
status = acpi_evaluate_object(NULL, METHOD_NAME__WAK, &arg_list, NULL);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND) {
ACPI_EXCEPTION((AE_INFO, status, "During Method _WAK"));
}
acpi_write_bit_register(ACPI_BITREG_WAKE_STATUS, 1);
acpi_gbl_system_awake_and_running = TRUE;
(void)
acpi_write_bit_register(acpi_gbl_fixed_event_info
[ACPI_EVENT_POWER_BUTTON].
enable_register_id, ACPI_ENABLE_EVENT);
(void)
acpi_write_bit_register(acpi_gbl_fixed_event_info
[ACPI_EVENT_POWER_BUTTON].
status_register_id, ACPI_CLEAR_STATUS);
arg.integer.value = ACPI_SST_WORKING;
status = acpi_evaluate_object(NULL, METHOD_NAME__SST, &arg_list, NULL);
if (ACPI_FAILURE(status) && status != AE_NOT_FOUND) {
ACPI_EXCEPTION((AE_INFO, status, "During Method _SST"));
}
return_ACPI_STATUS(status);
}
