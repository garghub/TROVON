static int get_total_cpus(void)
{
int nr_cpus = (int)sysconf(_SC_NPROCESSORS_CONF);
if (nr_cpus <= 0) {
pr_err("Could not read cpus\n");
goto error;
} else if (nr_cpus > MAX_CPUS) {
pr_err("Exceed max cpus(%d)\n", (int)MAX_CPUS);
goto error;
}
return nr_cpus;
error:
exit(EXIT_FAILURE);
}
static void *agent_info_new(void)
{
struct agent_info *s;
int i;
s = zalloc(sizeof(struct agent_info));
if (s == NULL) {
pr_err("agent_info zalloc error\n");
exit(EXIT_FAILURE);
}
s->pipe_size = PIPE_INIT;
s->use_stdout = false;
s->cpus = get_total_cpus();
s->ctl_fd = -1;
for (i = 0; i < s->cpus; i++)
s->rw_ti[i] = rw_thread_info_new();
return s;
}
static unsigned long parse_size(const char *arg)
{
unsigned long value, round;
char *ptr;
value = strtoul(arg, &ptr, 10);
switch (*ptr) {
case 'K': case 'k':
value <<= 10;
break;
case 'M': case 'm':
value <<= 20;
break;
default:
break;
}
if (value > PIPE_MAX_SIZE) {
pr_err("Pipe size must be less than 1MB\n");
goto error;
} else if (value < PIPE_MIN_SIZE) {
pr_err("Pipe size must be over 64KB\n");
goto error;
}
round = value & (PAGE_SIZE - 1);
value = value - round;
return value;
error:
return 0;
}
static void usage(char const *prg)
{
pr_err("usage: %s [-h] [-o] [-s <size of pipe>]\n", prg);
}
static const char *make_path(int cpu_num, bool this_is_write_path)
{
int ret;
char *buf;
buf = zalloc(PATH_MAX);
if (buf == NULL) {
pr_err("Could not allocate buffer\n");
goto error;
}
if (this_is_write_path)
ret = snprintf(buf, PATH_MAX, WRITE_PATH_FMT, cpu_num);
else
ret = snprintf(buf, PATH_MAX, READ_PATH_FMT, cpu_num);
if (ret <= 0) {
pr_err("Failed to generate %s path(CPU#%d):%d\n",
this_is_write_path ? "read" : "write", cpu_num, ret);
goto error;
}
return buf;
error:
free(buf);
return NULL;
}
static const char *make_input_path(int cpu_num)
{
return make_path(cpu_num, false);
}
static const char *make_output_path(int cpu_num)
{
return make_path(cpu_num, true);
}
static void *agent_info_init(struct agent_info *s)
{
int cpu;
const char *in_path = NULL;
const char *out_path = NULL;
for (cpu = 0; cpu < s->cpus; cpu++) {
in_path = make_input_path(cpu);
if (in_path == NULL)
goto error;
if (!s->use_stdout) {
out_path = make_output_path(cpu);
if (out_path == NULL)
goto error;
} else
pr_debug("stdout mode\n");
rw_thread_init(cpu, in_path, out_path, s->use_stdout,
s->pipe_size, s->rw_ti[cpu]);
}
s->ctl_fd = rw_ctl_init((const char *)CTL_PATH);
return NULL;
error:
exit(EXIT_FAILURE);
}
static void *parse_args(int argc, char *argv[], struct agent_info *s)
{
int cmd;
unsigned long size;
while ((cmd = getopt(argc, argv, "hos:")) != -1) {
switch (cmd) {
case 'o':
s->use_stdout = true;
break;
case 's':
size = parse_size(optarg);
if (size == 0)
goto error;
s->pipe_size = size;
break;
case 'h':
default:
usage(argv[0]);
goto error;
}
}
agent_info_init(s);
return NULL;
error:
exit(EXIT_FAILURE);
}
static void agent_main_loop(struct agent_info *s)
{
int cpu;
pthread_t rw_thread_per_cpu[MAX_CPUS];
for (cpu = 0; cpu < s->cpus; cpu++)
rw_thread_per_cpu[cpu] = rw_thread_run(s->rw_ti[cpu]);
rw_ctl_loop(s->ctl_fd);
for (cpu = 0; cpu < s->cpus; cpu++) {
int ret;
ret = pthread_join(rw_thread_per_cpu[cpu], NULL);
if (ret != 0) {
pr_err("pthread_join() error:%d (cpu %d)\n", ret, cpu);
exit(EXIT_FAILURE);
}
}
}
static void agent_info_free(struct agent_info *s)
{
int i;
close(s->ctl_fd);
for (i = 0; i < s->cpus; i++) {
close(s->rw_ti[i]->in_fd);
close(s->rw_ti[i]->out_fd);
close(s->rw_ti[i]->read_pipe);
close(s->rw_ti[i]->write_pipe);
free(s->rw_ti[i]);
}
free(s);
}
int main(int argc, char *argv[])
{
struct agent_info *s = NULL;
s = agent_info_new();
parse_args(argc, argv, s);
agent_main_loop(s);
agent_info_free(s);
return 0;
}
