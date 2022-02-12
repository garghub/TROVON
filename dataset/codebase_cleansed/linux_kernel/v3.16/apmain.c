static void ap_display_usage(void)
{
ACPI_USAGE_HEADER("acpidump [options]");
ACPI_OPTION("-b", "Dump tables to binary files");
ACPI_OPTION("-c", "Dump customized tables");
ACPI_OPTION("-h -?", "This help message");
ACPI_OPTION("-o <File>", "Redirect output to file");
ACPI_OPTION("-r <Address>", "Dump tables from specified RSDP");
ACPI_OPTION("-s", "Print table summaries only");
ACPI_OPTION("-v", "Display version information");
ACPI_OPTION("-z", "Verbose mode");
printf("\nTable Options:\n");
ACPI_OPTION("-a <Address>", "Get table via a physical address");
ACPI_OPTION("-f <BinaryFile>", "Get table via a binary file");
ACPI_OPTION("-n <Signature>", "Get table via a name/signature");
ACPI_OPTION("-x", "Do not use but dump XSDT");
ACPI_OPTION("-x -x", "Do not use or dump XSDT");
printf("\n"
"Invocation without parameters dumps all available tables\n"
"Multiple mixed instances of -a, -f, and -n are supported\n\n");
}
static void ap_insert_action(char *argument, u32 to_be_done)
{
action_table[current_action].argument = argument;
action_table[current_action].to_be_done = to_be_done;
current_action++;
if (current_action > AP_MAX_ACTIONS) {
fprintf(stderr, "Too many table options (max %u)\n",
AP_MAX_ACTIONS);
exit(-1);
}
}
static int ap_do_options(int argc, char **argv)
{
int j;
acpi_status status;
while ((j = acpi_getopt(argc, argv, AP_SUPPORTED_OPTIONS)) != EOF)
switch (j) {
case 'b':
gbl_binary_mode = TRUE;
continue;
case 'c':
gbl_dump_customized_tables = TRUE;
continue;
case 'h':
case '?':
ap_display_usage();
exit(0);
case 'o':
if (ap_open_output_file(acpi_gbl_optarg)) {
exit(-1);
}
continue;
case 'r':
status =
acpi_ut_strtoul64(acpi_gbl_optarg, 0,
&gbl_rsdp_base);
if (ACPI_FAILURE(status)) {
fprintf(stderr,
"%s: Could not convert to a physical address\n",
acpi_gbl_optarg);
exit(-1);
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
printf(ACPI_COMMON_SIGNON(AP_UTILITY_NAME));
exit(0);
case 'z':
gbl_verbose_mode = TRUE;
fprintf(stderr, ACPI_COMMON_SIGNON(AP_UTILITY_NAME));
continue;
case 'a':
ap_insert_action(acpi_gbl_optarg,
AP_DUMP_TABLE_BY_ADDRESS);
break;
case 'f':
ap_insert_action(acpi_gbl_optarg,
AP_DUMP_TABLE_BY_FILE);
break;
case 'n':
ap_insert_action(acpi_gbl_optarg,
AP_DUMP_TABLE_BY_NAME);
break;
default:
ap_display_usage();
exit(-1);
}
if (current_action == 0) {
ap_insert_action(NULL, AP_DUMP_ALL_TABLES);
}
return (0);
}
int ACPI_SYSTEM_XFACE main(int argc, char *argv[])
{
int status = 0;
struct ap_dump_action *action;
u32 file_size;
u32 i;
ACPI_DEBUG_INITIALIZE();
if (ap_do_options(argc, argv)) {
return (-1);
}
for (i = 0; i < current_action; i++) {
action = &action_table[i];
switch (action->to_be_done) {
case AP_DUMP_ALL_TABLES:
status = ap_dump_all_tables();
break;
case AP_DUMP_TABLE_BY_ADDRESS:
status = ap_dump_table_by_address(action->argument);
break;
case AP_DUMP_TABLE_BY_NAME:
status = ap_dump_table_by_name(action->argument);
break;
case AP_DUMP_TABLE_BY_FILE:
status = ap_dump_table_from_file(action->argument);
break;
default:
fprintf(stderr,
"Internal error, invalid action: 0x%X\n",
action->to_be_done);
return (-1);
}
if (status) {
return (status);
}
}
if (gbl_output_file) {
if (gbl_verbose_mode) {
file_size = cm_get_file_size(gbl_output_file);
fprintf(stderr,
"Output file %s contains 0x%X (%u) bytes\n\n",
gbl_output_filename, file_size, file_size);
}
fclose(gbl_output_file);
}
return (status);
}
