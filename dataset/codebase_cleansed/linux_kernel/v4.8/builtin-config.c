static int show_config(struct perf_config_set *set)
{
struct perf_config_section *section;
struct perf_config_item *item;
if (set == NULL)
return -1;
perf_config_set__for_each_entry(set, section, item) {
char *value = item->value;
if (value)
printf("%s.%s=%s\n", section->name,
item->name, value);
}
return 0;
}
int cmd_config(int argc, const char **argv, const char *prefix __maybe_unused)
{
int ret = 0;
struct perf_config_set *set;
char *user_config = mkpath("%s/.perfconfig", getenv("HOME"));
argc = parse_options(argc, argv, config_options, config_usage,
PARSE_OPT_STOP_AT_NON_OPTION);
if (use_system_config && use_user_config) {
pr_err("Error: only one config file at a time\n");
parse_options_usage(config_usage, config_options, "user", 0);
parse_options_usage(NULL, config_options, "system", 0);
return -1;
}
if (use_system_config)
config_exclusive_filename = perf_etc_perfconfig();
else if (use_user_config)
config_exclusive_filename = user_config;
set = perf_config_set__new();
if (!set) {
ret = -1;
goto out_err;
}
switch (actions) {
case ACTION_LIST:
if (argc) {
pr_err("Error: takes no arguments\n");
parse_options_usage(config_usage, config_options, "l", 1);
} else {
ret = show_config(set);
if (ret < 0) {
const char * config_filename = config_exclusive_filename;
if (!config_exclusive_filename)
config_filename = user_config;
pr_err("Nothing configured, "
"please check your %s \n", config_filename);
}
}
break;
default:
usage_with_options(config_usage, config_options);
}
perf_config_set__delete(set);
out_err:
return ret;
}
