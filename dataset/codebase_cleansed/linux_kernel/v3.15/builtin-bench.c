static void dump_benchmarks(struct collection *coll)
{
struct bench *bench;
printf("\n # List of available benchmarks for collection '%s':\n\n", coll->name);
for_each_bench(coll, bench)
printf("%14s: %s\n", bench->name, bench->summary);
printf("\n");
}
static void print_usage(void)
{
struct collection *coll;
int i;
printf("Usage: \n");
for (i = 0; bench_usage[i]; i++)
printf("\t%s\n", bench_usage[i]);
printf("\n");
printf(" # List of all available benchmark collections:\n\n");
for_each_collection(coll)
printf("%14s: %s\n", coll->name, coll->summary);
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
static int run_bench(const char *coll_name, const char *bench_name, bench_fn_t fn,
int argc, const char **argv, const char *prefix)
{
int size;
char *name;
int ret;
size = strlen(coll_name) + 1 + strlen(bench_name) + 1;
name = zalloc(size);
BUG_ON(!name);
scnprintf(name, size, "%s-%s", coll_name, bench_name);
prctl(PR_SET_NAME, name);
argv[0] = name;
ret = fn(argc, argv, prefix);
free(name);
return ret;
}
static void run_collection(struct collection *coll)
{
struct bench *bench;
const char *argv[2];
argv[1] = NULL;
for_each_bench(coll, bench) {
if (!bench->fn)
break;
printf("# Running %s/%s benchmark...\n", coll->name, bench->name);
fflush(stdout);
argv[1] = bench->name;
run_bench(coll->name, bench->name, bench->fn, 1, argv, NULL);
printf("\n");
}
}
static void run_all_collections(void)
{
struct collection *coll;
for_each_collection(coll)
run_collection(coll);
}
int cmd_bench(int argc, const char **argv, const char *prefix __maybe_unused)
{
struct collection *coll;
int ret = 0;
if (argc < 2) {
print_usage();
goto end;
}
argc = parse_options(argc, argv, bench_options, bench_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
bench_format = bench_str2int(bench_format_str);
if (bench_format == BENCH_FORMAT_UNKNOWN) {
printf("Unknown format descriptor: '%s'\n", bench_format_str);
goto end;
}
if (argc < 1) {
print_usage();
goto end;
}
if (!strcmp(argv[0], "all")) {
run_all_collections();
goto end;
}
for_each_collection(coll) {
struct bench *bench;
if (strcmp(coll->name, argv[0]))
continue;
if (argc < 2) {
dump_benchmarks(coll);
goto end;
}
if (!strcmp(argv[1], "all")) {
run_collection(coll);
goto end;
}
for_each_bench(coll, bench) {
if (strcmp(bench->name, argv[1]))
continue;
if (bench_format == BENCH_FORMAT_DEFAULT)
printf("# Running '%s/%s' benchmark:\n", coll->name, bench->name);
fflush(stdout);
ret = run_bench(coll->name, bench->name, bench->fn, argc-1, argv+1, prefix);
goto end;
}
if (!strcmp(argv[1], "-h") || !strcmp(argv[1], "--help")) {
dump_benchmarks(coll);
goto end;
}
printf("Unknown benchmark: '%s' for collection '%s'\n", argv[1], argv[0]);
ret = 1;
goto end;
}
printf("Unknown collection: '%s'\n", argv[0]);
ret = 1;
end:
return ret;
}
