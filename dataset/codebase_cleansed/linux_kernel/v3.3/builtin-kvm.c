static int __cmd_record(int argc, const char **argv)
{
int rec_argc, i = 0, j;
const char **rec_argv;
rec_argc = argc + 2;
rec_argv = calloc(rec_argc + 1, sizeof(char *));
rec_argv[i++] = strdup("record");
rec_argv[i++] = strdup("-o");
rec_argv[i++] = strdup(file_name);
for (j = 1; j < argc; j++, i++)
rec_argv[i] = argv[j];
BUG_ON(i != rec_argc);
return cmd_record(i, rec_argv, NULL);
}
static int __cmd_report(int argc, const char **argv)
{
int rec_argc, i = 0, j;
const char **rec_argv;
rec_argc = argc + 2;
rec_argv = calloc(rec_argc + 1, sizeof(char *));
rec_argv[i++] = strdup("report");
rec_argv[i++] = strdup("-i");
rec_argv[i++] = strdup(file_name);
for (j = 1; j < argc; j++, i++)
rec_argv[i] = argv[j];
BUG_ON(i != rec_argc);
return cmd_report(i, rec_argv, NULL);
}
static int __cmd_buildid_list(int argc, const char **argv)
{
int rec_argc, i = 0, j;
const char **rec_argv;
rec_argc = argc + 2;
rec_argv = calloc(rec_argc + 1, sizeof(char *));
rec_argv[i++] = strdup("buildid-list");
rec_argv[i++] = strdup("-i");
rec_argv[i++] = strdup(file_name);
for (j = 1; j < argc; j++, i++)
rec_argv[i] = argv[j];
BUG_ON(i != rec_argc);
return cmd_buildid_list(i, rec_argv, NULL);
}
int cmd_kvm(int argc, const char **argv, const char *prefix __used)
{
perf_host = 0;
perf_guest = 1;
argc = parse_options(argc, argv, kvm_options, kvm_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (!argc)
usage_with_options(kvm_usage, kvm_options);
if (!perf_host)
perf_guest = 1;
if (!file_name) {
if (perf_host && !perf_guest)
sprintf(name_buffer, "perf.data.host");
else if (!perf_host && perf_guest)
sprintf(name_buffer, "perf.data.guest");
else
sprintf(name_buffer, "perf.data.kvm");
file_name = name_buffer;
}
if (!strncmp(argv[0], "rec", 3))
return __cmd_record(argc, argv);
else if (!strncmp(argv[0], "rep", 3))
return __cmd_report(argc, argv);
else if (!strncmp(argv[0], "diff", 4))
return cmd_diff(argc, argv, NULL);
else if (!strncmp(argv[0], "top", 3))
return cmd_top(argc, argv, NULL);
else if (!strncmp(argv[0], "buildid-list", 12))
return __cmd_buildid_list(argc, argv);
else
usage_with_options(kvm_usage, kvm_options);
return 0;
}
