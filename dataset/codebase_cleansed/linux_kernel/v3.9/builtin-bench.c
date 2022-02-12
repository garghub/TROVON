static void dump_suites(int subsys_index)
{
int i;
printf("# List of available suites for %s...\n\n",
subsystems[subsys_index].name);
for (i = 0; subsystems[subsys_index].suites[i].name; i++)
printf("%14s: %s\n",
subsystems[subsys_index].suites[i].name,
subsystems[subsys_index].suites[i].summary);
printf("\n");
return;
}
static void print_usage(void)
{
int i;
printf("Usage: \n");
for (i = 0; bench_usage[i]; i++)
printf("\t%s\n", bench_usage[i]);
printf("\n");
printf("# List of available subsystems...\n\n");
for (i = 0; subsystems[i].name; i++)
printf("%14s: %s\n",
subsystems[i].name, subsystems[i].summary);
printf("\n");
}
static int bench_str2int(const char *str)
{
if (!str)
return BENCH_FORMAT_DEFAULT;
if (!strcmp(str, BENCH_FORMAT_DEFAULT_STR))
return BENCH_FORMAT_DEFAULT;
else if (!strcmp(str, BENCH_FORMAT_SIMPLE_STR))
return BENCH_FORMAT_SIMPLE;
return BENCH_FORMAT_UNKNOWN;
}
static void all_suite(struct bench_subsys *subsys)
{
int i;
const char *argv[2];
struct bench_suite *suites = subsys->suites;
argv[1] = NULL;
for (i = 0; suites[i].fn; i++) {
printf("# Running %s/%s benchmark...\n",
subsys->name,
suites[i].name);
fflush(stdout);
argv[1] = suites[i].name;
suites[i].fn(1, argv, NULL);
printf("\n");
}
}
static void all_subsystem(void)
{
int i;
for (i = 0; subsystems[i].suites; i++)
all_suite(&subsystems[i]);
}
int cmd_bench(int argc, const char **argv, const char *prefix __maybe_unused)
{
int i, j, status = 0;
if (argc < 2) {
print_usage();
goto end;
}
argc = parse_options(argc, argv, bench_options, bench_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
bench_format = bench_str2int(bench_format_str);
if (bench_format == BENCH_FORMAT_UNKNOWN) {
printf("Unknown format descriptor:%s\n", bench_format_str);
goto end;
}
if (argc < 1) {
print_usage();
goto end;
}
if (!strcmp(argv[0], "all")) {
all_subsystem();
goto end;
}
for (i = 0; subsystems[i].name; i++) {
if (strcmp(subsystems[i].name, argv[0]))
continue;
if (argc < 2) {
dump_suites(i);
goto end;
}
if (!strcmp(argv[1], "all")) {
all_suite(&subsystems[i]);
goto end;
}
for (j = 0; subsystems[i].suites[j].name; j++) {
if (strcmp(subsystems[i].suites[j].name, argv[1]))
continue;
if (bench_format == BENCH_FORMAT_DEFAULT)
printf("# Running %s/%s benchmark...\n",
subsystems[i].name,
subsystems[i].suites[j].name);
fflush(stdout);
status = subsystems[i].suites[j].fn(argc - 1,
argv + 1, prefix);
goto end;
}
if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
dump_suites(i);
goto end;
}
printf("Unknown suite:%s for %s\n", argv[1], argv[0]);
status = 1;
goto end;
}
printf("Unknown subsystem:%s\n", argv[0]);
status = 1;
end:
return status;
}
