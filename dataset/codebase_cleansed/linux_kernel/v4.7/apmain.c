static void ap_display_usage(void)
{
ACPI_USAGE_HEADER("acpidump [options]");
ACPI_OPTION("-b", "Dump tables to binary files");
ACPI_OPTION("-h -?", "This help message");
ACPI_OPTION("-o <File>", "Redirect output to file");
ACPI_OPTION("-r <Address>", "Dump tables from specified RSDP");
ACPI_OPTION("-s", "Print table summaries only");
ACPI_OPTION("-v", "Display version information");
ACPI_OPTION("-z", "Verbose mode");
ACPI_USAGE_TEXT("\nTable Options:\n");
ACPI_OPTION("-a <Address>", "Get table via a physical address");
ACPI_OPTION("-c <on|off>", "Turning on/off customized table dumping");
ACPI_OPTION("-f <BinaryFile>", "Get table via a binary file");
ACPI_OPTION("-n <Signature>", "Get table via a name/signature");
ACPI_OPTION("-x", "Do not use but dump XSDT");
ACPI_OPTION("-x -x", "Do not use or dump XSDT");
ACPI_USAGE_TEXT("\n"
"Invocation without parameters dumps all available tables\n"
"Multiple mixed instances of -a, -f, and -n are supported\n\n");
}
static int ap_insert_action(char *argument, u32 to_be_done)
{
action_table[current_action].argument = argument;
action_table[current_action].to_be_done = to_be_done;
current_action++;
if (current_action > AP_MAX_ACTIONS) {
acpi_log_error("Too many table options (max %u)\n",
AP_MAX_ACTIONS);
return (-1);
}
return (0);
}
static int ap_do_options(int argc, char **argv)
{
int j;
acpi_status status;
while ((j =
acpi_getopt(argc, argv, AP_SUPPORTED_OPTIONS)) != ACPI_OPT_END)
switch (j) {
case 'b':
gbl_binary_mode = TRUE;
continue;
case 'c':
if (!strcmp(acpi_gbl_optarg, "on")) {
gbl_dump_customized_tables = TRUE;
} else if (!strcmp(acpi_gbl_optarg, "off")) {
gbl_dump_customized_tables = FALSE;
} else {
acpi_log_error
("%s: Cannot handle this switch, please use on|off\n",
acpi_gbl_optarg);
return (-1);
}
continue;
case 'h':
case '?':
ap_display_usage();
return (1);
case 'o':
if (ap_open_output_file(acpi_gbl_optarg)) {
return (-1);
}
continue;
case 'r':
status =
acpi_ut_strtoul64(acpi_gbl_optarg, ACPI_ANY_BASE,
ACPI_MAX64_BYTE_WIDTH,
&gbl_rsdp_base);
if (ACPI_FAILURE(status)) {
acpi_log_error
("%s: Could not convert to a physical address\n",
acpi_gbl_optarg);
return (-1);
}
continue;
case 's':
gbl_summary_mode = TRUE;
continue;
case 'x':
if (!acpi_gbl_do_not_use_xsdt) {
acpi_gbl_do_not_use_xsdt = TRUE;
} else {
gbl_do_not_dump_xsdt = TRUE;
}
continue;
case 'v':
acpi_os_printf(ACPI_COMMON_SIGNON(AP_UTILITY_NAME));
return (1);
case 'z':
gbl_verbose_mode = TRUE;
acpi_log_error(ACPI_COMMON_SIGNON(AP_UTILITY_NAME));
continue;
case 'a':
if (ap_insert_action
(acpi_gbl_optarg, AP_DUMP_TABLE_BY_ADDRESS)) {
return (-1);
}
break;
case 'f':
if (ap_insert_action
(acpi_gbl_optarg, AP_DUMP_TABLE_BY_FILE)) {
return (-1);
}
break;
case 'n':
if (ap_insert_action
(acpi_gbl_optarg, AP_DUMP_TABLE_BY_NAME)) {
return (-1);
}
break;
default:
ap_display_usage();
return (-1);
}
if (current_action == 0) {
if (ap_insert_action(NULL, AP_DUMP_ALL_TABLES)) {
return (-1);
}
}
return (0);
}
