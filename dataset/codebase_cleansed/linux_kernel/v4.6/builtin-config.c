static int show_config(const char *key, const char *value,
void *cb __maybe_unused)
{
if (value)
printf("%s=%s\n", key, value);
else
printf("%s\n", key);
return 0;
}
int cmd_config(int argc, const char **argv, const char *prefix __maybe_unused)
{
int ret = 0;
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
switch (actions) {
case ACTION_LIST:
if (argc) {
pr_err("Error: takes no arguments\n");
parse_options_usage(config_usage, config_options, "l", 1);
} else {
ret = perf_config(show_config, NULL);
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
return ret;
}
