static void
print_usage(FILE *output)
{
fprintf(output, "\n");
fprintf(output, "Usage: captype <infile> ...\n");
}
static void
failure_warning_message(const char *msg_format, va_list ap)
{
fprintf(stderr, "captype: ");
vfprintf(stderr, msg_format, ap);
fprintf(stderr, "\n");
}
static void
failure_message_cont(const char *msg_format, va_list ap)
{
vfprintf(stderr, msg_format, ap);
fprintf(stderr, "\n");
}
int
main(int argc, char *argv[])
{
GString *comp_info_str;
GString *runtime_info_str;
char *init_progfile_dir_error;
wtap *wth;
int err;
gchar *err_info;
int i;
int opt;
int overall_error_status;
static const struct option long_options[] = {
{"help", no_argument, NULL, 'h'},
{"version", no_argument, NULL, 'v'},
{0, 0, 0, 0 }
};
setlocale(LC_ALL, "");
cmdarg_err_init(failure_warning_message, failure_message_cont);
comp_info_str = get_compiled_version_info(NULL, NULL);
runtime_info_str = get_runtime_version_info(NULL);
ws_add_crash_info("Captype (Wireshark) %s\n"
"\n"
"%s"
"\n"
"%s",
get_ws_vcs_version_info(), comp_info_str->str, runtime_info_str->str);
g_string_free(comp_info_str, TRUE);
g_string_free(runtime_info_str, TRUE);
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
create_app_running_mutex();
#endif
init_process_policies();
init_progfile_dir_error = init_progfile_dir(argv[0], main);
if (init_progfile_dir_error != NULL) {
fprintf(stderr,
"captype: Can't get pathname of directory containing the captype program: %s.\n",
init_progfile_dir_error);
g_free(init_progfile_dir_error);
}
wtap_init();
#ifdef HAVE_PLUGINS
init_report_message(failure_warning_message, failure_warning_message,
NULL, NULL, NULL);
scan_plugins(DONT_REPORT_LOAD_FAILURE);
register_all_wiretap_modules();
#endif
while ((opt = getopt_long(argc, argv, "hv", long_options, NULL)) !=-1) {
switch (opt) {
case 'h':
printf("Captype (Wireshark) %s\n"
"Print the file types of capture files.\n"
"See https://www.wireshark.org for more information.\n",
get_ws_vcs_version_info());
print_usage(stdout);
exit(0);
break;
case 'v':
comp_info_str = get_compiled_version_info(NULL, NULL);
runtime_info_str = get_runtime_version_info(NULL);
show_version("Captype (Wireshark)", comp_info_str, runtime_info_str);
g_string_free(comp_info_str, TRUE);
g_string_free(runtime_info_str, TRUE);
exit(0);
break;
case '?':
print_usage(stderr);
exit(1);
break;
}
}
if (argc < 2) {
print_usage(stderr);
return 1;
}
overall_error_status = 0;
for (i = 1; i < argc; i++) {
wth = wtap_open_offline(argv[i], WTAP_TYPE_AUTO, &err, &err_info, FALSE);
if(wth) {
printf("%s: %s\n", argv[i], wtap_file_type_subtype_short_string(wtap_file_type_subtype(wth)));
wtap_close(wth);
} else {
if (err == WTAP_ERR_FILE_UNKNOWN_FORMAT)
printf("%s: unknown\n", argv[i]);
else {
cfile_open_failure_message("captype", argv[i], err, err_info);
overall_error_status = 2;
}
}
}
wtap_cleanup();
free_progdirs();
#ifdef HAVE_PLUGINS
plugins_cleanup();
#endif
return overall_error_status;
}
