static __u64 time_get_ns(void)
{
struct timespec ts;
clock_gettime(CLOCK_MONOTONIC, &ts);
return ts.tv_sec * 1000000000ull + ts.tv_nsec;
}
static void print_old_objects(int fd)
{
long long val = time_get_ns();
__u64 key, next_key;
struct pair v;
key = write(1, "\e[1;1H\e[2J", 12);
key = -1;
while (bpf_map_get_next_key(map_fd[0], &key, &next_key) == 0) {
bpf_map_lookup_elem(map_fd[0], &next_key, &v);
key = next_key;
if (val - v.val < 1000000000ll)
continue;
printf("obj 0x%llx is %2lldsec old was allocated at ip %llx\n",
next_key, (val - v.val) / 1000000000ll, v.ip);
}
}
int main(int ac, char **argv)
{
struct rlimit r = {RLIM_INFINITY, RLIM_INFINITY};
char filename[256];
int i;
snprintf(filename, sizeof(filename), "%s_kern.o", argv[0]);
if (setrlimit(RLIMIT_MEMLOCK, &r)) {
perror("setrlimit(RLIMIT_MEMLOCK, RLIM_INFINITY)");
return 1;
}
if (load_bpf_file(filename)) {
printf("%s", bpf_log_buf);
return 1;
}
for (i = 0; ; i++) {
print_old_objects(map_fd[1]);
sleep(1);
}
return 0;
}
