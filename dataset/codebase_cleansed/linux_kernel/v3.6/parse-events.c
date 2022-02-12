static int tp_event_has_id(struct dirent *sys_dir, struct dirent *evt_dir)
{
char evt_path[MAXPATHLEN];
int fd;
snprintf(evt_path, MAXPATHLEN, "%s/%s/%s/id", tracing_events_path,
sys_dir->d_name, evt_dir->d_name);
fd = open(evt_path, O_RDONLY);
if (fd < 0)
return -EINVAL;
close(fd);
return 0;
}
struct tracepoint_path *tracepoint_id_to_path(u64 config)
{
struct tracepoint_path *path = NULL;
DIR *sys_dir, *evt_dir;
struct dirent *sys_next, *evt_next, sys_dirent, evt_dirent;
char id_buf[24];
int fd;
u64 id;
char evt_path[MAXPATHLEN];
char dir_path[MAXPATHLEN];
if (debugfs_valid_mountpoint(tracing_events_path))
return NULL;
sys_dir = opendir(tracing_events_path);
if (!sys_dir)
return NULL;
for_each_subsystem(sys_dir, sys_dirent, sys_next) {
snprintf(dir_path, MAXPATHLEN, "%s/%s", tracing_events_path,
sys_dirent.d_name);
evt_dir = opendir(dir_path);
if (!evt_dir)
continue;
for_each_event(sys_dirent, evt_dir, evt_dirent, evt_next) {
snprintf(evt_path, MAXPATHLEN, "%s/%s/id", dir_path,
evt_dirent.d_name);
fd = open(evt_path, O_RDONLY);
if (fd < 0)
continue;
if (read(fd, id_buf, sizeof(id_buf)) < 0) {
close(fd);
continue;
}
close(fd);
id = atoll(id_buf);
if (id == config) {
closedir(evt_dir);
closedir(sys_dir);
path = zalloc(sizeof(*path));
path->system = malloc(MAX_EVENT_LENGTH);
if (!path->system) {
free(path);
return NULL;
}
path->name = malloc(MAX_EVENT_LENGTH);
if (!path->name) {
free(path->system);
free(path);
return NULL;
}
strncpy(path->system, sys_dirent.d_name,
MAX_EVENT_LENGTH);
strncpy(path->name, evt_dirent.d_name,
MAX_EVENT_LENGTH);
return path;
}
}
closedir(evt_dir);
}
closedir(sys_dir);
return NULL;
}
const char *event_type(int type)
{
switch (type) {
case PERF_TYPE_HARDWARE:
return "hardware";
case PERF_TYPE_SOFTWARE:
return "software";
case PERF_TYPE_TRACEPOINT:
return "tracepoint";
case PERF_TYPE_HW_CACHE:
return "hardware-cache";
default:
break;
}
return "unknown";
}
static int add_event(struct list_head **_list, int *idx,
struct perf_event_attr *attr, char *name)
{
struct perf_evsel *evsel;
struct list_head *list = *_list;
if (!list) {
list = malloc(sizeof(*list));
if (!list)
return -ENOMEM;
INIT_LIST_HEAD(list);
}
event_attr_init(attr);
evsel = perf_evsel__new(attr, (*idx)++);
if (!evsel) {
free(list);
return -ENOMEM;
}
if (name)
evsel->name = strdup(name);
list_add_tail(&evsel->node, list);
*_list = list;
return 0;
}
static int parse_aliases(char *str, const char *names[][PERF_EVSEL__MAX_ALIASES], int size)
{
int i, j;
int n, longest = -1;
for (i = 0; i < size; i++) {
for (j = 0; j < PERF_EVSEL__MAX_ALIASES && names[i][j]; j++) {
n = strlen(names[i][j]);
if (n > longest && !strncasecmp(str, names[i][j], n))
longest = n;
}
if (longest > 0)
return i;
}
return -1;
}
int parse_events_add_cache(struct list_head **list, int *idx,
char *type, char *op_result1, char *op_result2)
{
struct perf_event_attr attr;
char name[MAX_NAME_LEN];
int cache_type = -1, cache_op = -1, cache_result = -1;
char *op_result[2] = { op_result1, op_result2 };
int i, n;
cache_type = parse_aliases(type, perf_evsel__hw_cache,
PERF_COUNT_HW_CACHE_MAX);
if (cache_type == -1)
return -EINVAL;
n = snprintf(name, MAX_NAME_LEN, "%s", type);
for (i = 0; (i < 2) && (op_result[i]); i++) {
char *str = op_result[i];
snprintf(name + n, MAX_NAME_LEN - n, "-%s\n", str);
if (cache_op == -1) {
cache_op = parse_aliases(str, perf_evsel__hw_cache_op,
PERF_COUNT_HW_CACHE_OP_MAX);
if (cache_op >= 0) {
if (!perf_evsel__is_cache_op_valid(cache_type, cache_op))
return -EINVAL;
continue;
}
}
if (cache_result == -1) {
cache_result = parse_aliases(str, perf_evsel__hw_cache_result,
PERF_COUNT_HW_CACHE_RESULT_MAX);
if (cache_result >= 0)
continue;
}
}
if (cache_op == -1)
cache_op = PERF_COUNT_HW_CACHE_OP_READ;
if (cache_result == -1)
cache_result = PERF_COUNT_HW_CACHE_RESULT_ACCESS;
memset(&attr, 0, sizeof(attr));
attr.config = cache_type | (cache_op << 8) | (cache_result << 16);
attr.type = PERF_TYPE_HW_CACHE;
return add_event(list, idx, &attr, name);
}
static int add_tracepoint(struct list_head **list, int *idx,
char *sys_name, char *evt_name)
{
struct perf_event_attr attr;
char name[MAX_NAME_LEN];
char evt_path[MAXPATHLEN];
char id_buf[4];
u64 id;
int fd;
snprintf(evt_path, MAXPATHLEN, "%s/%s/%s/id", tracing_events_path,
sys_name, evt_name);
fd = open(evt_path, O_RDONLY);
if (fd < 0)
return -1;
if (read(fd, id_buf, sizeof(id_buf)) < 0) {
close(fd);
return -1;
}
close(fd);
id = atoll(id_buf);
memset(&attr, 0, sizeof(attr));
attr.config = id;
attr.type = PERF_TYPE_TRACEPOINT;
attr.sample_type |= PERF_SAMPLE_RAW;
attr.sample_type |= PERF_SAMPLE_TIME;
attr.sample_type |= PERF_SAMPLE_CPU;
attr.sample_type |= PERF_SAMPLE_PERIOD;
attr.sample_period = 1;
snprintf(name, MAX_NAME_LEN, "%s:%s", sys_name, evt_name);
return add_event(list, idx, &attr, name);
}
static int add_tracepoint_multi(struct list_head **list, int *idx,
char *sys_name, char *evt_name)
{
char evt_path[MAXPATHLEN];
struct dirent *evt_ent;
DIR *evt_dir;
int ret = 0;
snprintf(evt_path, MAXPATHLEN, "%s/%s", tracing_events_path, sys_name);
evt_dir = opendir(evt_path);
if (!evt_dir) {
perror("Can't open event dir");
return -1;
}
while (!ret && (evt_ent = readdir(evt_dir))) {
if (!strcmp(evt_ent->d_name, ".")
|| !strcmp(evt_ent->d_name, "..")
|| !strcmp(evt_ent->d_name, "enable")
|| !strcmp(evt_ent->d_name, "filter"))
continue;
if (!strglobmatch(evt_ent->d_name, evt_name))
continue;
ret = add_tracepoint(list, idx, sys_name, evt_ent->d_name);
}
return ret;
}
int parse_events_add_tracepoint(struct list_head **list, int *idx,
char *sys, char *event)
{
int ret;
ret = debugfs_valid_mountpoint(tracing_events_path);
if (ret)
return ret;
return strpbrk(event, "*?") ?
add_tracepoint_multi(list, idx, sys, event) :
add_tracepoint(list, idx, sys, event);
}
static int
parse_breakpoint_type(const char *type, struct perf_event_attr *attr)
{
int i;
for (i = 0; i < 3; i++) {
if (!type || !type[i])
break;
#define CHECK_SET_TYPE(bit) \
do { \
if (attr->bp_type & bit) \
return -EINVAL; \
else \
attr->bp_type |= bit; \
} while (0)
switch (type[i]) {
case 'r':
CHECK_SET_TYPE(HW_BREAKPOINT_R);
break;
case 'w':
CHECK_SET_TYPE(HW_BREAKPOINT_W);
break;
case 'x':
CHECK_SET_TYPE(HW_BREAKPOINT_X);
break;
default:
return -EINVAL;
}
}
#undef CHECK_SET_TYPE
if (!attr->bp_type)
attr->bp_type = HW_BREAKPOINT_R | HW_BREAKPOINT_W;
return 0;
}
int parse_events_add_breakpoint(struct list_head **list, int *idx,
void *ptr, char *type)
{
struct perf_event_attr attr;
memset(&attr, 0, sizeof(attr));
attr.bp_addr = (unsigned long) ptr;
if (parse_breakpoint_type(type, &attr))
return -EINVAL;
if (attr.bp_type == HW_BREAKPOINT_X)
attr.bp_len = sizeof(long);
else
attr.bp_len = HW_BREAKPOINT_LEN_4;
attr.type = PERF_TYPE_BREAKPOINT;
attr.sample_period = 1;
return add_event(list, idx, &attr, NULL);
}
static int config_term(struct perf_event_attr *attr,
struct parse_events__term *term)
{
#define CHECK_TYPE_VAL(type) \
do { \
if (PARSE_EVENTS__TERM_TYPE_ ## type != term->type_val) \
return -EINVAL; \
} while (0)
switch (term->type_term) {
case PARSE_EVENTS__TERM_TYPE_CONFIG:
CHECK_TYPE_VAL(NUM);
attr->config = term->val.num;
break;
case PARSE_EVENTS__TERM_TYPE_CONFIG1:
CHECK_TYPE_VAL(NUM);
attr->config1 = term->val.num;
break;
case PARSE_EVENTS__TERM_TYPE_CONFIG2:
CHECK_TYPE_VAL(NUM);
attr->config2 = term->val.num;
break;
case PARSE_EVENTS__TERM_TYPE_SAMPLE_PERIOD:
CHECK_TYPE_VAL(NUM);
attr->sample_period = term->val.num;
break;
case PARSE_EVENTS__TERM_TYPE_BRANCH_SAMPLE_TYPE:
break;
case PARSE_EVENTS__TERM_TYPE_NAME:
CHECK_TYPE_VAL(STR);
break;
default:
return -EINVAL;
}
return 0;
#undef CHECK_TYPE_VAL
}
static int config_attr(struct perf_event_attr *attr,
struct list_head *head, int fail)
{
struct parse_events__term *term;
list_for_each_entry(term, head, list)
if (config_term(attr, term) && fail)
return -EINVAL;
return 0;
}
int parse_events_add_numeric(struct list_head **list, int *idx,
unsigned long type, unsigned long config,
struct list_head *head_config)
{
struct perf_event_attr attr;
memset(&attr, 0, sizeof(attr));
attr.type = type;
attr.config = config;
if (head_config &&
config_attr(&attr, head_config, 1))
return -EINVAL;
return add_event(list, idx, &attr, NULL);
}
static int parse_events__is_name_term(struct parse_events__term *term)
{
return term->type_term == PARSE_EVENTS__TERM_TYPE_NAME;
}
static char *pmu_event_name(struct list_head *head_terms)
{
struct parse_events__term *term;
list_for_each_entry(term, head_terms, list)
if (parse_events__is_name_term(term))
return term->val.str;
return NULL;
}
int parse_events_add_pmu(struct list_head **list, int *idx,
char *name, struct list_head *head_config)
{
struct perf_event_attr attr;
struct perf_pmu *pmu;
pmu = perf_pmu__find(name);
if (!pmu)
return -EINVAL;
memset(&attr, 0, sizeof(attr));
if (perf_pmu__check_alias(pmu, head_config))
return -EINVAL;
config_attr(&attr, head_config, 0);
if (perf_pmu__config(pmu, &attr, head_config))
return -EINVAL;
return add_event(list, idx, &attr,
pmu_event_name(head_config));
}
void parse_events_update_lists(struct list_head *list_event,
struct list_head *list_all)
{
list_splice_tail(list_event, list_all);
free(list_event);
}
int parse_events_modifier(struct list_head *list, char *str)
{
struct perf_evsel *evsel;
int exclude = 0, exclude_GH = 0;
int eu = 0, ek = 0, eh = 0, eH = 0, eG = 0, precise = 0;
if (str == NULL)
return 0;
while (*str) {
if (*str == 'u') {
if (!exclude)
exclude = eu = ek = eh = 1;
eu = 0;
} else if (*str == 'k') {
if (!exclude)
exclude = eu = ek = eh = 1;
ek = 0;
} else if (*str == 'h') {
if (!exclude)
exclude = eu = ek = eh = 1;
eh = 0;
} else if (*str == 'G') {
if (!exclude_GH)
exclude_GH = eG = eH = 1;
eG = 0;
} else if (*str == 'H') {
if (!exclude_GH)
exclude_GH = eG = eH = 1;
eH = 0;
} else if (*str == 'p') {
precise++;
} else
break;
++str;
}
if (precise > 3)
return -EINVAL;
list_for_each_entry(evsel, list, node) {
evsel->attr.exclude_user = eu;
evsel->attr.exclude_kernel = ek;
evsel->attr.exclude_hv = eh;
evsel->attr.precise_ip = precise;
evsel->attr.exclude_host = eH;
evsel->attr.exclude_guest = eG;
}
return 0;
}
static int parse_events__scanner(const char *str, void *data, int start_token)
{
YY_BUFFER_STATE buffer;
void *scanner;
int ret;
ret = parse_events_lex_init_extra(start_token, &scanner);
if (ret)
return ret;
buffer = parse_events__scan_string(str, scanner);
#ifdef PARSER_DEBUG
parse_events_debug = 1;
#endif
ret = parse_events_parse(data, scanner);
parse_events__flush_buffer(buffer, scanner);
parse_events__delete_buffer(buffer, scanner);
parse_events_lex_destroy(scanner);
return ret;
}
int parse_events_terms(struct list_head *terms, const char *str)
{
struct parse_events_data__terms data = {
.terms = NULL,
};
int ret;
ret = parse_events__scanner(str, &data, PE_START_TERMS);
if (!ret) {
list_splice(data.terms, terms);
free(data.terms);
return 0;
}
parse_events__free_terms(data.terms);
return ret;
}
int parse_events(struct perf_evlist *evlist, const char *str, int unset __used)
{
struct parse_events_data__events data = {
.list = LIST_HEAD_INIT(data.list),
.idx = evlist->nr_entries,
};
int ret;
ret = parse_events__scanner(str, &data, PE_START_EVENTS);
if (!ret) {
int entries = data.idx - evlist->nr_entries;
perf_evlist__splice_list_tail(evlist, &data.list, entries);
return 0;
}
fprintf(stderr, "invalid or unsupported event: '%s'\n", str);
fprintf(stderr, "Run 'perf list' for a list of valid events\n");
return ret;
}
int parse_events_option(const struct option *opt, const char *str,
int unset __used)
{
struct perf_evlist *evlist = *(struct perf_evlist **)opt->value;
return parse_events(evlist, str, unset);
}
int parse_filter(const struct option *opt, const char *str,
int unset __used)
{
struct perf_evlist *evlist = *(struct perf_evlist **)opt->value;
struct perf_evsel *last = NULL;
if (evlist->nr_entries > 0)
last = list_entry(evlist->entries.prev, struct perf_evsel, node);
if (last == NULL || last->attr.type != PERF_TYPE_TRACEPOINT) {
fprintf(stderr,
"-F option should follow a -e tracepoint option\n");
return -1;
}
last->filter = strdup(str);
if (last->filter == NULL) {
fprintf(stderr, "not enough memory to hold filter string\n");
return -1;
}
return 0;
}
void print_tracepoint_events(const char *subsys_glob, const char *event_glob)
{
DIR *sys_dir, *evt_dir;
struct dirent *sys_next, *evt_next, sys_dirent, evt_dirent;
char evt_path[MAXPATHLEN];
char dir_path[MAXPATHLEN];
if (debugfs_valid_mountpoint(tracing_events_path))
return;
sys_dir = opendir(tracing_events_path);
if (!sys_dir)
return;
for_each_subsystem(sys_dir, sys_dirent, sys_next) {
if (subsys_glob != NULL &&
!strglobmatch(sys_dirent.d_name, subsys_glob))
continue;
snprintf(dir_path, MAXPATHLEN, "%s/%s", tracing_events_path,
sys_dirent.d_name);
evt_dir = opendir(dir_path);
if (!evt_dir)
continue;
for_each_event(sys_dirent, evt_dir, evt_dirent, evt_next) {
if (event_glob != NULL &&
!strglobmatch(evt_dirent.d_name, event_glob))
continue;
snprintf(evt_path, MAXPATHLEN, "%s:%s",
sys_dirent.d_name, evt_dirent.d_name);
printf(" %-50s [%s]\n", evt_path,
event_type_descriptors[PERF_TYPE_TRACEPOINT]);
}
closedir(evt_dir);
}
closedir(sys_dir);
}
int is_valid_tracepoint(const char *event_string)
{
DIR *sys_dir, *evt_dir;
struct dirent *sys_next, *evt_next, sys_dirent, evt_dirent;
char evt_path[MAXPATHLEN];
char dir_path[MAXPATHLEN];
if (debugfs_valid_mountpoint(tracing_events_path))
return 0;
sys_dir = opendir(tracing_events_path);
if (!sys_dir)
return 0;
for_each_subsystem(sys_dir, sys_dirent, sys_next) {
snprintf(dir_path, MAXPATHLEN, "%s/%s", tracing_events_path,
sys_dirent.d_name);
evt_dir = opendir(dir_path);
if (!evt_dir)
continue;
for_each_event(sys_dirent, evt_dir, evt_dirent, evt_next) {
snprintf(evt_path, MAXPATHLEN, "%s:%s",
sys_dirent.d_name, evt_dirent.d_name);
if (!strcmp(evt_path, event_string)) {
closedir(evt_dir);
closedir(sys_dir);
return 1;
}
}
closedir(evt_dir);
}
closedir(sys_dir);
return 0;
}
static void __print_events_type(u8 type, struct event_symbol *syms,
unsigned max)
{
char name[64];
unsigned i;
for (i = 0; i < max ; i++, syms++) {
if (strlen(syms->alias))
snprintf(name, sizeof(name), "%s OR %s",
syms->symbol, syms->alias);
else
snprintf(name, sizeof(name), "%s", syms->symbol);
printf(" %-50s [%s]\n", name,
event_type_descriptors[type]);
}
}
void print_events_type(u8 type)
{
if (type == PERF_TYPE_SOFTWARE)
__print_events_type(type, event_symbols_sw, PERF_COUNT_SW_MAX);
else
__print_events_type(type, event_symbols_hw, PERF_COUNT_HW_MAX);
}
int print_hwcache_events(const char *event_glob)
{
unsigned int type, op, i, printed = 0;
char name[64];
for (type = 0; type < PERF_COUNT_HW_CACHE_MAX; type++) {
for (op = 0; op < PERF_COUNT_HW_CACHE_OP_MAX; op++) {
if (!perf_evsel__is_cache_op_valid(type, op))
continue;
for (i = 0; i < PERF_COUNT_HW_CACHE_RESULT_MAX; i++) {
__perf_evsel__hw_cache_type_op_res_name(type, op, i,
name, sizeof(name));
if (event_glob != NULL && !strglobmatch(name, event_glob))
continue;
printf(" %-50s [%s]\n", name,
event_type_descriptors[PERF_TYPE_HW_CACHE]);
++printed;
}
}
}
return printed;
}
static void print_symbol_events(const char *event_glob, unsigned type,
struct event_symbol *syms, unsigned max)
{
unsigned i, printed = 0;
char name[MAX_NAME_LEN];
for (i = 0; i < max; i++, syms++) {
if (event_glob != NULL &&
!(strglobmatch(syms->symbol, event_glob) ||
(syms->alias && strglobmatch(syms->alias, event_glob))))
continue;
if (strlen(syms->alias))
snprintf(name, MAX_NAME_LEN, "%s OR %s", syms->symbol, syms->alias);
else
strncpy(name, syms->symbol, MAX_NAME_LEN);
printf(" %-50s [%s]\n", name, event_type_descriptors[type]);
printed++;
}
if (printed)
printf("\n");
}
void print_events(const char *event_glob)
{
printf("\n");
printf("List of pre-defined events (to be used in -e):\n");
print_symbol_events(event_glob, PERF_TYPE_HARDWARE,
event_symbols_hw, PERF_COUNT_HW_MAX);
print_symbol_events(event_glob, PERF_TYPE_SOFTWARE,
event_symbols_sw, PERF_COUNT_SW_MAX);
print_hwcache_events(event_glob);
if (event_glob != NULL)
return;
printf("\n");
printf(" %-50s [%s]\n",
"rNNN",
event_type_descriptors[PERF_TYPE_RAW]);
printf(" %-50s [%s]\n",
"cpu/t1=v1[,t2=v2,t3 ...]/modifier",
event_type_descriptors[PERF_TYPE_RAW]);
printf(" (see 'perf list --help' on how to encode it)\n");
printf("\n");
printf(" %-50s [%s]\n",
"mem:<addr>[:access]",
event_type_descriptors[PERF_TYPE_BREAKPOINT]);
printf("\n");
print_tracepoint_events(NULL, NULL);
}
int parse_events__is_hardcoded_term(struct parse_events__term *term)
{
return term->type_term != PARSE_EVENTS__TERM_TYPE_USER;
}
static int new_term(struct parse_events__term **_term, int type_val,
int type_term, char *config,
char *str, long num)
{
struct parse_events__term *term;
term = zalloc(sizeof(*term));
if (!term)
return -ENOMEM;
INIT_LIST_HEAD(&term->list);
term->type_val = type_val;
term->type_term = type_term;
term->config = config;
switch (type_val) {
case PARSE_EVENTS__TERM_TYPE_NUM:
term->val.num = num;
break;
case PARSE_EVENTS__TERM_TYPE_STR:
term->val.str = str;
break;
default:
return -EINVAL;
}
*_term = term;
return 0;
}
int parse_events__term_num(struct parse_events__term **term,
int type_term, char *config, long num)
{
return new_term(term, PARSE_EVENTS__TERM_TYPE_NUM, type_term,
config, NULL, num);
}
int parse_events__term_str(struct parse_events__term **term,
int type_term, char *config, char *str)
{
return new_term(term, PARSE_EVENTS__TERM_TYPE_STR, type_term,
config, str, 0);
}
int parse_events__term_clone(struct parse_events__term **new,
struct parse_events__term *term)
{
return new_term(new, term->type_val, term->type_term, term->config,
term->val.str, term->val.num);
}
void parse_events__free_terms(struct list_head *terms)
{
struct parse_events__term *term, *h;
list_for_each_entry_safe(term, h, terms, list)
free(term);
free(terms);
}
