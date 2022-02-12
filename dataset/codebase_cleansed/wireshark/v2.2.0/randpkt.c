static void
failure_message(const char *msg_format _U_, va_list ap _U_)
{
return;
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
exit(is_error ? 1 : 0);
}
int
main(int argc, char **argv)
{
int opt;
int produce_type = -1;
char *produce_filename = NULL;
int produce_max_bytes = 5000;
int produce_count = 1000;
randpkt_example *example;
guint8* type = NULL;
int allrandom = FALSE;
wtap_dumper *savedump;
static const struct option long_options[] = {
{"help", no_argument, NULL, 'h'},
{0, 0, 0, 0 }
};
#ifdef HAVE_PLUGINS
char *init_progfile_dir_error;
#endif
init_process_policies();
init_open_routines();
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
create_app_running_mutex();
#endif
#ifdef HAVE_PLUGINS
if ((init_progfile_dir_error = init_progfile_dir(argv[0], main))) {
g_warning("randpkt: init_progfile_dir(): %s", init_progfile_dir_error);
g_free(init_progfile_dir_error);
} else {
wtap_register_plugin_types();
init_report_err(failure_message,NULL,NULL,NULL);
scan_plugins();
register_all_wiretap_modules();
}
#endif
while ((opt = getopt_long(argc, argv, "b:c:ht:r", long_options, NULL)) != -1) {
switch (opt) {
case 'b':
produce_max_bytes = atoi(optarg);
if (produce_max_bytes > 65536) {
fprintf(stderr, "randpkt: Max bytes is 65536\n");
return 1;
}
break;
case 'c':
produce_count = atoi(optarg);
break;
case 't':
type = g_strdup(optarg);
break;
case 'h':
usage(FALSE);
break;
case 'r':
allrandom = TRUE;
break;
default:
usage(TRUE);
break;
}
}
if (argc > optind) {
produce_filename = argv[optind];
}
else {
usage(TRUE);
}
if (!allrandom) {
produce_type = randpkt_parse_type(type);
g_free(type);
example = randpkt_find_example(produce_type);
if (!example)
return 1;
randpkt_example_init(example, produce_filename, produce_max_bytes);
randpkt_loop(example, produce_count);
} else {
if (type) {
fprintf(stderr, "Can't set type in random mode\n");
return 2;
}
produce_type = randpkt_parse_type(NULL);
example = randpkt_find_example(produce_type);
if (!example)
return 1;
randpkt_example_init(example, produce_filename, produce_max_bytes);
while (produce_count-- > 0) {
randpkt_loop(example, 1);
produce_type = randpkt_parse_type(NULL);
savedump = example->dump;
example = randpkt_find_example(produce_type);
if (!example)
return 1;
example->dump = savedump;
}
}
if (!randpkt_example_close(example))
return 2;
return 0;
}
