static int set_config(struct perf_config_set *set, const char *file_name,
const char *var, const char *value)
{
struct perf_config_section *section = NULL;
struct perf_config_item *item = NULL;
const char *first_line = "# this file is auto-generated.";
FILE *fp;
if (set == NULL)
return -1;
fp = fopen(file_name, "w");
if (!fp)
return -1;
perf_config_set__collect(set, file_name, var, value);
fprintf(fp, "%s\n", first_line);
perf_config_items__for_each_entry(&set->sections, section) {
if (!use_system_config && section->from_system_config)
continue;
fprintf(fp, "[%s]\n", section->name);
perf_config_items__for_each_entry(&section->items, item) {
if (!use_system_config && item->from_system_config)
continue;
if (item->value)
fprintf(fp, "\t%s = %s\n",
item->name, item->value);
}
}
fclose(fp);
return 0;
}
static int show_spec_config(struct perf_config_set *set, const char *var)
{
struct perf_config_section *section;
struct perf_config_item *item;
if (set == NULL)
return -1;
perf_config_items__for_each_entry(&set->sections, section) {
if (!strstarts(var, section->name))
continue;
perf_config_items__for_each_entry(&section->items, item) {
const char *name = var + strlen(section->name) + 1;
if (strcmp(name, item->name) == 0) {
char *value = item->value;
if (value) {
printf("%s=%s\n", var, value);
return 0;
}
}
}
}
return 0;
}
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
static int parse_config_arg(char *arg, char **var, char **value)
{
const char *last_dot = strchr(arg, '.');
if (last_dot == NULL || last_dot == arg) {
pr_err("The config variable does not contain a section name: %s\n", arg);
return -1;
}
if (!last_dot[1]) {
pr_err("The config variable does not contain a variable name: %s\n", arg);
return -1;
}
*value = strchr(arg, '=');
if (*value == NULL)
*var = arg;
else if (!strcmp(*value, "=")) {
pr_err("The config variable does not contain a value: %s\n", arg);
return -1;
} else {
*value = *value + 1;
*var = strsep(&arg, "=");
if (*var[0] == '\0') {
pr_err("invalid config variable: %s\n", arg);
return -1;
}
}
return 0;
}
int cmd_config(int argc, const char **argv)
{
int i, ret = -1;
struct perf_config_set *set;
char *user_config = mkpath("%s/.perfconfig", getenv("HOME"));
const char *config_filename;
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
if (!config_exclusive_filename)
config_filename = user_config;
else
config_filename = config_exclusive_filename;
set = perf_config_set__new();
if (!set)
goto out_err;
switch (actions) {
case ACTION_LIST:
if (argc) {
pr_err("Error: takes no arguments\n");
parse_options_usage(config_usage, config_options, "l", 1);
} else {
if (show_config(set) < 0) {
pr_err("Nothing configured, "
"please check your %s \n", config_filename);
goto out_err;
}
}
break;
default:
if (!argc) {
usage_with_options(config_usage, config_options);
break;
}
for (i = 0; argv[i]; i++) {
char *var, *value;
char *arg = strdup(argv[i]);
if (!arg) {
pr_err("%s: strdup failed\n", __func__);
goto out_err;
}
if (parse_config_arg(arg, &var, &value) < 0) {
free(arg);
goto out_err;
}
if (value == NULL) {
if (show_spec_config(set, var) < 0) {
pr_err("%s is not configured: %s\n",
var, config_filename);
free(arg);
goto out_err;
}
} else {
if (set_config(set, config_filename, var, value) < 0) {
pr_err("Failed to set '%s=%s' on %s\n",
var, value, config_filename);
free(arg);
goto out_err;
}
}
free(arg);
}
}
ret = 0;
out_err:
perf_config_set__delete(set);
return ret;
}
