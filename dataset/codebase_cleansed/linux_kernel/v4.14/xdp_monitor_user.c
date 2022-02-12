static void usage(char *argv[])
{
int i;
printf("\nDOCUMENTATION:\n%s\n", __doc__);
printf("\n");
printf(" Usage: %s (options-see-below)\n",
argv[0]);
printf(" Listing options:\n");
for (i = 0; long_options[i].name != 0; i++) {
printf(" --%-15s", long_options[i].name);
if (long_options[i].flag != NULL)
printf(" flag (internal value:%d)",
*long_options[i].flag);
else
printf("(internal short-option: -%c)",
long_options[i].val);
printf("\n");
}
printf("\n");
}
__u64 gettime(void)
{
struct timespec t;
int res;
res = clock_gettime(CLOCK_MONOTONIC, &t);
if (res < 0) {
fprintf(stderr, "Error with gettimeofday! (%i)\n", res);
exit(EXIT_FAILURE);
}
return (__u64) t.tv_sec * NANOSEC_PER_SEC + t.tv_nsec;
}
static const char *err2str(int err)
{
if (err < REDIR_RES_MAX)
return redir_names[err];
return NULL;
}
static void stats_print_headers(bool err_only)
{
if (err_only)
printf("\n%s\n", __doc_err_only__);
printf("%-14s %-10s %-18s %-9s\n",
"XDP_REDIRECT", "pps ", "pps-human-readable", "measure-period");
}
static void stats_print(struct stats_record *rec,
struct stats_record *prev,
bool err_only)
{
int i = 0;
if (err_only)
i = REDIR_ERROR;
for (; i < REDIR_RES_MAX; i++) {
struct record *r = &rec->xdp_redir[i];
struct record *p = &prev->xdp_redir[i];
__u64 period = 0;
__u64 packets = 0;
double pps = 0;
double period_ = 0;
if (p->timestamp) {
packets = r->counter - p->counter;
period = r->timestamp - p->timestamp;
if (period > 0) {
period_ = ((double) period / NANOSEC_PER_SEC);
pps = packets / period_;
}
}
printf("%-14s %-10.0f %'-18.0f %f\n",
err2str(i), pps, pps, period_);
}
}
static __u64 get_key32_value64_percpu(int fd, __u32 key)
{
unsigned int nr_cpus = bpf_num_possible_cpus();
__u64 values[nr_cpus];
__u64 sum = 0;
int i;
if ((bpf_map_lookup_elem(fd, &key, values)) != 0) {
fprintf(stderr,
"ERR: bpf_map_lookup_elem failed key:0x%X\n", key);
return 0;
}
for (i = 0; i < nr_cpus; i++) {
sum += values[i];
}
return sum;
}
static bool stats_collect(int fd, struct stats_record *rec)
{
int i;
for (i = 0; i < REDIR_RES_MAX; i++) {
rec->xdp_redir[i].timestamp = gettime();
rec->xdp_redir[i].counter = get_key32_value64_percpu(fd, i);
}
return true;
}
static void stats_poll(int interval, bool err_only)
{
struct stats_record rec, prev;
int map_fd;
memset(&rec, 0, sizeof(rec));
setlocale(LC_NUMERIC, "en_US");
if (verbose)
printf("\n%s", __doc__);
if (verbose)
printf(" - Stats map: %s\n", map_data[0].name);
map_fd = map_data[0].fd;
stats_print_headers(err_only);
fflush(stdout);
while (1) {
memcpy(&prev, &rec, sizeof(rec));
stats_collect(map_fd, &rec);
stats_print(&rec, &prev, err_only);
fflush(stdout);
sleep(interval);
}
}
void print_bpf_prog_info(void)
{
int i;
printf("Loaded BPF prog have %d bpf program(s)\n", prog_cnt);
for (i = 0; i < prog_cnt; i++) {
printf(" - prog_fd[%d] = fd(%d)\n", i, prog_fd[i]);
}
printf("Loaded BPF prog have %d map(s)\n", map_data_count);
for (i = 0; i < map_data_count; i++) {
char *name = map_data[i].name;
int fd = map_data[i].fd;
printf(" - map_data[%d] = fd(%d) name:%s\n", i, fd, name);
}
printf("Searching for (max:%d) event file descriptor(s)\n", prog_cnt);
for (i = 0; i < prog_cnt; i++) {
if (event_fd[i] != -1)
printf(" - event_fd[%d] = fd(%d)\n", i, event_fd[i]);
}
}
int main(int argc, char **argv)
{
int longindex = 0, opt;
int ret = EXIT_SUCCESS;
char bpf_obj_file[256];
bool errors_only = true;
int interval = 2;
snprintf(bpf_obj_file, sizeof(bpf_obj_file), "%s_kern.o", argv[0]);
while ((opt = getopt_long(argc, argv, "h",
long_options, &longindex)) != -1) {
switch (opt) {
case 'D':
debug = true;
break;
case 'S':
errors_only = false;
break;
case 's':
interval = atoi(optarg);
break;
case 'h':
default:
usage(argv);
return EXIT_FAILURE;
}
}
if (load_bpf_file(bpf_obj_file)) {
printf("ERROR - bpf_log_buf: %s", bpf_log_buf);
return 1;
}
if (!prog_fd[0]) {
printf("ERROR - load_bpf_file: %s\n", strerror(errno));
return 1;
}
if (debug) {
print_bpf_prog_info();
}
if (errors_only) {
close(event_fd[2]);
close(prog_fd[2]);
close(event_fd[3]);
close(prog_fd[3]);
}
stats_poll(interval, errors_only);
return ret;
}
