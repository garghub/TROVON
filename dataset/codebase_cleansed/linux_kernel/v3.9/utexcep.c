const char *acpi_format_exception(acpi_status status)
{
const char *exception = NULL;
ACPI_FUNCTION_ENTRY();
exception = acpi_ut_validate_exception(status);
if (!exception) {
ACPI_ERROR((AE_INFO,
"Unknown exception code: 0x%8.8X", status));
exception = "UNKNOWN_STATUS_CODE";
}
return (ACPI_CAST_PTR(const char, exception));
}
const char *acpi_ut_validate_exception(acpi_status status)
{
u32 sub_status;
const char *exception = NULL;
ACPI_FUNCTION_ENTRY();
sub_status = (status & ~AE_CODE_MASK);
switch (status & AE_CODE_MASK) {
case AE_CODE_ENVIRONMENTAL:
if (sub_status <= AE_CODE_ENV_MAX) {
exception = acpi_gbl_exception_names_env[sub_status];
}
break;
case AE_CODE_PROGRAMMER:
if (sub_status <= AE_CODE_PGM_MAX) {
exception = acpi_gbl_exception_names_pgm[sub_status];
}
break;
case AE_CODE_ACPI_TABLES:
if (sub_status <= AE_CODE_TBL_MAX) {
exception = acpi_gbl_exception_names_tbl[sub_status];
}
break;
case AE_CODE_AML:
if (sub_status <= AE_CODE_AML_MAX) {
exception = acpi_gbl_exception_names_aml[sub_status];
}
break;
case AE_CODE_CONTROL:
if (sub_status <= AE_CODE_CTRL_MAX) {
exception = acpi_gbl_exception_names_ctrl[sub_status];
}
break;
default:
break;
}
return (ACPI_CAST_PTR(const char, exception));
}
