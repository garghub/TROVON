static void
show_version(GString *comp_info_str, GString *runtime_info_str)
{
printf("Captype (Wireshark) %s\n"
"\n"
"%s"
"\n"
"%s"
"\n"
"%s",
get_ws_vcs_version_info(), get_copyright_info(),
comp_info_str->str, runtime_info_str->str);
}
static void
print_usage(FILE *output)
{
fprintf(output, "\n");
fprintf(output, "Usage: captype <infile> ...\n");
}
static void
failure_message(const char *msg_format _U_, va_list ap _U_)
{
return;
}
static void
get_captype_compiled_info(GString *str)
{
g_string_append(str, ", ");
#ifdef HAVE_LIBZ
g_string_append(str, "with libz ");
#ifdef ZLIB_VERSION
g_string_append(str, ZLIB_VERSION);
#else
g_string_append(str, "(version unknown)");
#endif
#else
g_string_append(str, "without libz");
#endif
}
static void
get_captype_runtime_info(GString *str)
{
#if defined(HAVE_LIBZ) && !defined(_WIN32)
g_string_append_printf(str, ", with libz %s", zlibVersion());
#endif
}
int
main(int argc, char *argv[])
{
GString *comp_info_str;
GString *runtime_info_str;
wtap *wth;
int err;
gchar *err_info;
int i;
int opt;
int overall_error_status;
static const struct option long_options[] = {
{(char *)"help", no_argument, NULL, 'h'},
{(char *)"version", no_argument, NULL, 'v'},
{0, 0, 0, 0 }
};
#ifdef HAVE_PLUGINS
char *init_progfile_dir_error;
#endif
comp_info_str = g_string_new("Compiled ");
get_compiled_version_info(comp_info_str, NULL, get_captype_compiled_info);
runtime_info_str = g_string_new("Running ");
get_runtime_version_info(runtime_info_str, get_captype_runtime_info);
ws_add_crash_info("Captype (Wireshark) %s\n"
"\n"
"%s"
"\n"
"%s",
get_ws_vcs_version_info(), comp_info_str->str, runtime_info_str->str);
#ifdef _WIN32
arg_list_utf_16to8(argc, argv);
create_app_running_mutex();
#endif
init_process_policies();
init_open_routines();
#ifdef HAVE_PLUGINS
if ((init_progfile_dir_error = init_progfile_dir(argv[0], main))) {
g_warning("captype: init_progfile_dir(): %s", init_progfile_dir_error);
g_free(init_progfile_dir_error);
} else {
wtap_register_plugin_types();
init_report_err(failure_message,NULL,NULL,NULL);
scan_plugins();
register_all_wiretap_modules();
}
#endif
while ((opt = getopt_long(argc, argv, "hv", long_options, NULL)) !=-1) {
switch (opt) {
case 'h':
printf("Captype (Wireshark) %s\n"
"Print the file types of capture files.\n"
"See http://www.wireshark.org for more information.\n",
get_ws_vcs_version_info());
print_usage(stdout);
exit(0);
break;
case 'v':
show_version(comp_info_str, runtime_info_str);
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
setlocale(LC_ALL, "");
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
fprintf(stderr, "captype: Can't open %s: %s\n", argv[i],
wtap_strerror(err));
switch (err) {
case WTAP_ERR_UNSUPPORTED:
case WTAP_ERR_UNSUPPORTED_ENCAP:
case WTAP_ERR_BAD_FILE:
fprintf(stderr, "(%s)\n", err_info);
g_free(err_info);
break;
}
overall_error_status = 1;
}
}
}
return overall_error_status;
}
