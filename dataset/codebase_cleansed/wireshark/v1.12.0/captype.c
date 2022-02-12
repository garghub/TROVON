static void
usage(void)
{
fprintf(stderr, "Captype %s"
#ifdef GITVERSION
" (" GITVERSION " from " GITBRANCH ")"
#endif
"\n", VERSION);
fprintf(stderr, "Prints the file types of capture files.\n");
fprintf(stderr, "See http://www.wireshark.org for more information.\n");
fprintf(stderr, "\n");
fprintf(stderr, "Usage: captype <infile> ...\n");
}
static void
failure_message(const char *msg_format _U_, va_list ap _U_)
{
return;
}
int
main(int argc, char *argv[])
{
wtap *wth;
int err;
gchar *err_info;
int i;
int overall_error_status;
#ifdef HAVE_PLUGINS
char *init_progfile_dir_error;
#endif
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
setlocale(LC_ALL, "");
if (argc < 2) {
usage();
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
