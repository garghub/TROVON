static void
failure_warning_message(const char *msg_format, va_list ap)
{
fprintf(stderr, "randpkt: ");
vfprintf(stderr, msg_format, ap);
fprintf(stderr, "\n");
}
static void
failure_message_cont(const char *msg_format, va_list ap)
{
vfprintf(stderr, msg_format, ap);
fprintf(stderr, "\n");
}
static void
usage(gboolean is_error)
{
FILE *output;
char** abbrev_list;
char** longname_list;
unsigned i = 0;
if (!is_error) {
output = stdout;
}
else {
output = stderr;
}
fprintf(output, "Usage: randpkt [-b maxbytes] [-c count] [-t type] [-r] filename\n");
fprintf(output, "Default max bytes (per packet) is 5000\n");
fprintf(output, "Default count is 1000.\n");
fprintf(output, "-r: random packet type selection\n");
fprintf(output, "\n");
fprintf(output, "Types:\n");
randpkt_example_list(&abbrev_list, &longname_list);
while (abbrev_list[i] && longname_list[i]) {
fprintf(output, "\t%-16s%s\n", abbrev_list[i], longname_list[i]);
i++;
}
g_strfreev(abbrev_list);
g_strfreev(longname_list);
fprintf(output, "\nIf type is not specified, a random packet will be chosen\n\n");
}
int
main(int argc, char **argv)
{
char *init_progfile_dir_error;
int opt;
int produce_type = -1;
char *produce_filename = NULL;
int produce_max_bytes = 5000;
int produce_count = 1000;
randpkt_example *example;
guint8* type = NULL;
int allrandom = FALSE;
wtap_dumper *savedump;
int ret = EXIT_SUCCESS;
static const struct option long_options[] = {
{"help", no_argument, NULL, 'h'},
{0, 0, 0, 0 }
};
init_process_policies();
init_progfile_dir_error = init_progfile_dir(argv[0], main);
if (init_progfile_dir_error != NULL) {
fprintf(stderr,
"capinfos: Can't get pathname of directory containing the capinfos program: %s.\n",
init_progfile_dir_error);
g_free(init_progfile_dir_error);
}
wtap_init();
cmdarg_err_init(failure_warning_message, failure_message_cont);
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
create_app_running_mutex();
#endif
#ifdef HAVE_PLUGINS
init_report_message(failure_warning_message, failure_warning_message,
NULL, NULL, NULL);
scan_plugins(DONT_REPORT_LOAD_FAILURE);
register_all_wiretap_modules();
#endif
while ((opt = getopt_long(argc, argv, "b:c:ht:r", long_options, NULL)) != -1) {
switch (opt) {
case 'b':
produce_max_bytes = get_positive_int(optarg, "max bytes");
if (produce_max_bytes > 65536) {
cmdarg_err("max bytes is > 65536");
ret = INVALID_OPTION;
goto clean_exit;
}
break;
case 'c':
produce_count = get_positive_int(optarg, "count");
break;
case 't':
type = g_strdup(optarg);
break;
case 'h':
usage(FALSE);
goto clean_exit;
break;
case 'r':
allrandom = TRUE;
break;
default:
usage(TRUE);
ret = INVALID_OPTION;
goto clean_exit;
break;
}
}
if (argc > optind) {
produce_filename = argv[optind];
}
else {
usage(TRUE);
ret = INVALID_OPTION;
goto clean_exit;
}
if (!allrandom) {
produce_type = randpkt_parse_type(type);
g_free(type);
example = randpkt_find_example(produce_type);
if (!example) {
ret = INVALID_OPTION;
goto clean_exit;
}
ret = randpkt_example_init(example, produce_filename, produce_max_bytes);
if (ret != EXIT_SUCCESS)
goto clean_exit;
randpkt_loop(example, produce_count);
} else {
if (type) {
fprintf(stderr, "Can't set type in random mode\n");
ret = INVALID_TYPE;
goto clean_exit;
}
produce_type = randpkt_parse_type(NULL);
example = randpkt_find_example(produce_type);
if (!example) {
ret = INVALID_OPTION;
goto clean_exit;
}
ret = randpkt_example_init(example, produce_filename, produce_max_bytes);
if (ret != EXIT_SUCCESS)
goto clean_exit;
while (produce_count-- > 0) {
randpkt_loop(example, 1);
produce_type = randpkt_parse_type(NULL);
savedump = example->dump;
example = randpkt_find_example(produce_type);
if (!example) {
ret = INVALID_OPTION;
goto clean_exit;
}
example->dump = savedump;
}
}
if (!randpkt_example_close(example)) {
ret = CLOSE_ERROR;
}
clean_exit:
wtap_cleanup();
return ret;
}
