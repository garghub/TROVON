enum sched_prio string_to_prio(const char *str)
{
if (strncasecmp("high", str, strlen(str)) == 0)
return SCHED_HIGH;
else if (strncasecmp("default", str, strlen(str)) == 0)
return SCHED_DEFAULT;
else if (strncasecmp("low", str, strlen(str)) == 0)
return SCHED_LOW;
else
return SCHED_ERR;
}
FILE *prepare_output(const char *dirname)
{
FILE *output = NULL;
int len;
char *filename;
struct utsname sysdata;
DIR *dir;
dir = opendir(dirname);
if (dir == NULL) {
if (mkdir(dirname, 0755)) {
perror("mkdir");
fprintf(stderr, "error: Cannot create dir %s\n",
dirname);
return NULL;
}
}
len = strlen(dirname) + 30;
filename = malloc(sizeof(char) * len);
if (uname(&sysdata) == 0) {
len += strlen(sysdata.nodename) + strlen(sysdata.release);
filename = realloc(filename, sizeof(char) * len);
if (filename == NULL) {
perror("realloc");
return NULL;
}
snprintf(filename, len - 1, "%s/benchmark_%s_%s_%li.log",
dirname, sysdata.nodename, sysdata.release, time(NULL));
} else {
snprintf(filename, len - 1, "%s/benchmark_%li.log",
dirname, time(NULL));
}
dprintf("logilename: %s\n", filename);
output = fopen(filename, "w+");
if (output == NULL) {
perror("fopen");
fprintf(stderr, "error: unable to open logfile\n");
}
fprintf(stdout, "Logfile: %s\n", filename);
free(filename);
fprintf(output, "#round load sleep performance powersave percentage\n");
return output;
}
struct config *prepare_default_config()
{
struct config *config = malloc(sizeof(struct config));
dprintf("loading defaults\n");
config->sleep = 500000;
config->load = 500000;
config->sleep_step = 500000;
config->load_step = 500000;
config->cycles = 5;
config->rounds = 50;
config->cpu = 0;
config->prio = SCHED_HIGH;
config->verbose = 0;
strncpy(config->governor, "ondemand", 8);
config->output = stdout;
#ifdef DEFAULT_CONFIG_FILE
if (prepare_config(DEFAULT_CONFIG_FILE, config))
return NULL;
#endif
return config;
}
int prepare_config(const char *path, struct config *config)
{
size_t len = 0;
char *opt, *val, *line = NULL;
FILE *configfile = fopen(path, "r");
if (config == NULL) {
fprintf(stderr, "error: config is NULL\n");
return 1;
}
if (configfile == NULL) {
perror("fopen");
fprintf(stderr, "error: unable to read configfile\n");
free(config);
return 1;
}
while (getline(&line, &len, configfile) != -1) {
if (line[0] == '#' || line[0] == ' ')
continue;
sscanf(line, "%as = %as", &opt, &val);
dprintf("parsing: %s -> %s\n", opt, val);
if (strncmp("sleep", opt, strlen(opt)) == 0)
sscanf(val, "%li", &config->sleep);
else if (strncmp("load", opt, strlen(opt)) == 0)
sscanf(val, "%li", &config->load);
else if (strncmp("load_step", opt, strlen(opt)) == 0)
sscanf(val, "%li", &config->load_step);
else if (strncmp("sleep_step", opt, strlen(opt)) == 0)
sscanf(val, "%li", &config->sleep_step);
else if (strncmp("cycles", opt, strlen(opt)) == 0)
sscanf(val, "%u", &config->cycles);
else if (strncmp("rounds", opt, strlen(opt)) == 0)
sscanf(val, "%u", &config->rounds);
else if (strncmp("verbose", opt, strlen(opt)) == 0)
sscanf(val, "%u", &config->verbose);
else if (strncmp("output", opt, strlen(opt)) == 0)
config->output = prepare_output(val);
else if (strncmp("cpu", opt, strlen(opt)) == 0)
sscanf(val, "%u", &config->cpu);
else if (strncmp("governor", opt, 14) == 0)
strncpy(config->governor, val, 14);
else if (strncmp("priority", opt, strlen(opt)) == 0) {
if (string_to_prio(val) != SCHED_ERR)
config->prio = string_to_prio(val);
}
}
free(line);
free(opt);
free(val);
return 0;
}
