static int parse_probe_event(const char *str)
{
struct perf_probe_event *pev = &params.events[params.nevents];
int ret;
pr_debug("probe-definition(%d): %s\n", params.nevents, str);
if (++params.nevents == MAX_PROBES) {
pr_err("Too many probes (> %d) were specified.", MAX_PROBES);
return -1;
}
ret = parse_perf_probe_command(str, pev);
pr_debug("%d arguments\n", pev->nargs);
return ret;
}
static int parse_probe_event_argv(int argc, const char **argv)
{
int i, len, ret;
char *buf;
len = 0;
for (i = 0; i < argc; i++)
len += strlen(argv[i]) + 1;
buf = zalloc(len + 1);
if (buf == NULL)
return -ENOMEM;
len = 0;
for (i = 0; i < argc; i++)
len += sprintf(&buf[len], "%s ", argv[i]);
params.mod_events = true;
ret = parse_probe_event(buf);
free(buf);
return ret;
}
static int opt_add_probe_event(const struct option *opt __used,
const char *str, int unset __used)
{
if (str) {
params.mod_events = true;
return parse_probe_event(str);
} else
return 0;
}
static int opt_del_probe_event(const struct option *opt __used,
const char *str, int unset __used)
{
if (str) {
params.mod_events = true;
if (!params.dellist)
params.dellist = strlist__new(true, NULL);
strlist__add(params.dellist, str);
}
return 0;
}
static int opt_show_lines(const struct option *opt __used,
const char *str, int unset __used)
{
int ret = 0;
if (str)
ret = parse_line_range_desc(str, &params.line_range);
INIT_LIST_HEAD(&params.line_range.line_list);
params.show_lines = true;
return ret;
}
static int opt_show_vars(const struct option *opt __used,
const char *str, int unset __used)
{
struct perf_probe_event *pev = &params.events[params.nevents];
int ret;
if (!str)
return 0;
ret = parse_probe_event(str);
if (!ret && pev->nargs != 0) {
pr_err(" Error: '--vars' doesn't accept arguments.\n");
return -EINVAL;
}
params.show_vars = true;
return ret;
}
static int opt_set_filter(const struct option *opt __used,
const char *str, int unset __used)
{
const char *err;
if (str) {
pr_debug2("Set filter: %s\n", str);
if (params.filter)
strfilter__delete(params.filter);
params.filter = strfilter__new(str, &err);
if (!params.filter) {
pr_err("Filter parse error at %td.\n", err - str + 1);
pr_err("Source: \"%s\"\n", str);
pr_err(" %*c\n", (int)(err - str + 1), '^');
return -EINVAL;
}
}
return 0;
}
int cmd_probe(int argc, const char **argv, const char *prefix __used)
{
int ret;
argc = parse_options(argc, argv, options, probe_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (argc > 0) {
if (strcmp(argv[0], "-") == 0) {
pr_warning(" Error: '-' is not supported.\n");
usage_with_options(probe_usage, options);
}
ret = parse_probe_event_argv(argc, argv);
if (ret < 0) {
pr_err(" Error: Parse Error. (%d)\n", ret);
return ret;
}
}
if (params.max_probe_points == 0)
params.max_probe_points = MAX_PROBES;
if ((!params.nevents && !params.dellist && !params.list_events &&
!params.show_lines && !params.show_funcs))
usage_with_options(probe_usage, options);
symbol_conf.try_vmlinux_path = (symbol_conf.vmlinux_name == NULL);
if (params.list_events) {
if (params.mod_events) {
pr_err(" Error: Don't use --list with --add/--del.\n");
usage_with_options(probe_usage, options);
}
if (params.show_lines) {
pr_err(" Error: Don't use --list with --line.\n");
usage_with_options(probe_usage, options);
}
if (params.show_vars) {
pr_err(" Error: Don't use --list with --vars.\n");
usage_with_options(probe_usage, options);
}
if (params.show_funcs) {
pr_err(" Error: Don't use --list with --funcs.\n");
usage_with_options(probe_usage, options);
}
ret = show_perf_probe_events();
if (ret < 0)
pr_err(" Error: Failed to show event list. (%d)\n",
ret);
return ret;
}
if (params.show_funcs) {
if (params.nevents != 0 || params.dellist) {
pr_err(" Error: Don't use --funcs with"
" --add/--del.\n");
usage_with_options(probe_usage, options);
}
if (params.show_lines) {
pr_err(" Error: Don't use --funcs with --line.\n");
usage_with_options(probe_usage, options);
}
if (params.show_vars) {
pr_err(" Error: Don't use --funcs with --vars.\n");
usage_with_options(probe_usage, options);
}
if (!params.filter)
params.filter = strfilter__new(DEFAULT_FUNC_FILTER,
NULL);
ret = show_available_funcs(params.target_module,
params.filter);
strfilter__delete(params.filter);
if (ret < 0)
pr_err(" Error: Failed to show functions."
" (%d)\n", ret);
return ret;
}
#ifdef DWARF_SUPPORT
if (params.show_lines) {
if (params.mod_events) {
pr_err(" Error: Don't use --line with"
" --add/--del.\n");
usage_with_options(probe_usage, options);
}
if (params.show_vars) {
pr_err(" Error: Don't use --line with --vars.\n");
usage_with_options(probe_usage, options);
}
ret = show_line_range(&params.line_range, params.target_module);
if (ret < 0)
pr_err(" Error: Failed to show lines. (%d)\n", ret);
return ret;
}
if (params.show_vars) {
if (params.mod_events) {
pr_err(" Error: Don't use --vars with"
" --add/--del.\n");
usage_with_options(probe_usage, options);
}
if (!params.filter)
params.filter = strfilter__new(DEFAULT_VAR_FILTER,
NULL);
ret = show_available_vars(params.events, params.nevents,
params.max_probe_points,
params.target_module,
params.filter,
params.show_ext_vars);
strfilter__delete(params.filter);
if (ret < 0)
pr_err(" Error: Failed to show vars. (%d)\n", ret);
return ret;
}
#endif
if (params.dellist) {
ret = del_perf_probe_events(params.dellist);
strlist__delete(params.dellist);
if (ret < 0) {
pr_err(" Error: Failed to delete events. (%d)\n", ret);
return ret;
}
}
if (params.nevents) {
ret = add_perf_probe_events(params.events, params.nevents,
params.max_probe_points,
params.target_module,
params.force_add);
if (ret < 0) {
pr_err(" Error: Failed to add events. (%d)\n", ret);
return ret;
}
}
return 0;
}
