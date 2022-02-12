int acpi_getopt_argument(int argc, char **argv)
{
acpi_gbl_optind--;
current_char_ptr++;
if (argv[acpi_gbl_optind][(int)(current_char_ptr + 1)] != '\0') {
acpi_gbl_optarg =
&argv[acpi_gbl_optind++][(int)(current_char_ptr + 1)];
} else if (++acpi_gbl_optind >= argc) {
ACPI_OPTION_ERROR("\nOption requires an argument", 0);
current_char_ptr = 1;
return (-1);
} else {
acpi_gbl_optarg = argv[acpi_gbl_optind++];
}
current_char_ptr = 1;
return (0);
}
int acpi_getopt(int argc, char **argv, char *opts)
{
int current_char;
char *opts_ptr;
if (current_char_ptr == 1) {
if (acpi_gbl_optind >= argc ||
argv[acpi_gbl_optind][0] != '-' ||
argv[acpi_gbl_optind][1] == '\0') {
return (ACPI_OPT_END);
} else if (strcmp(argv[acpi_gbl_optind], "--") == 0) {
acpi_gbl_optind++;
return (ACPI_OPT_END);
}
}
current_char = argv[acpi_gbl_optind][current_char_ptr];
if (current_char == ':' ||
(opts_ptr = strchr(opts, current_char)) == NULL) {
ACPI_OPTION_ERROR("Illegal option: -", current_char);
if (argv[acpi_gbl_optind][++current_char_ptr] == '\0') {
acpi_gbl_optind++;
current_char_ptr = 1;
}
return ('?');
}
if (*++opts_ptr == ':') {
if (argv[acpi_gbl_optind][(int)(current_char_ptr + 1)] != '\0') {
acpi_gbl_optarg =
&argv[acpi_gbl_optind++][(int)
(current_char_ptr + 1)];
} else if (++acpi_gbl_optind >= argc) {
ACPI_OPTION_ERROR("Option requires an argument: -",
current_char);
current_char_ptr = 1;
return ('?');
} else {
acpi_gbl_optarg = argv[acpi_gbl_optind++];
}
current_char_ptr = 1;
}
else if (*opts_ptr == '+') {
if (argv[acpi_gbl_optind][(int)(current_char_ptr + 1)] != '\0') {
acpi_gbl_optarg =
&argv[acpi_gbl_optind++][(int)
(current_char_ptr + 1)];
} else if (++acpi_gbl_optind >= argc) {
acpi_gbl_optarg = NULL;
} else {
acpi_gbl_optarg = argv[acpi_gbl_optind++];
}
current_char_ptr = 1;
}
else if (*opts_ptr == '^') {
if (argv[acpi_gbl_optind][(int)(current_char_ptr + 1)] != '\0') {
acpi_gbl_optarg =
&argv[acpi_gbl_optind][(int)(current_char_ptr + 1)];
} else {
acpi_gbl_optarg = "^";
}
acpi_gbl_sub_opt_char = acpi_gbl_optarg[0];
acpi_gbl_optind++;
current_char_ptr = 1;
}
else if (*opts_ptr == '|') {
if (argv[acpi_gbl_optind][(int)(current_char_ptr + 1)] != '\0') {
acpi_gbl_optarg =
&argv[acpi_gbl_optind][(int)(current_char_ptr + 1)];
} else {
ACPI_OPTION_ERROR
("Option requires a single-character suboption: -",
current_char);
current_char_ptr = 1;
return ('?');
}
acpi_gbl_sub_opt_char = acpi_gbl_optarg[0];
acpi_gbl_optind++;
current_char_ptr = 1;
}
else {
if (argv[acpi_gbl_optind][++current_char_ptr] == '\0') {
current_char_ptr = 1;
acpi_gbl_optind++;
}
acpi_gbl_optarg = NULL;
}
return (current_char);
}
