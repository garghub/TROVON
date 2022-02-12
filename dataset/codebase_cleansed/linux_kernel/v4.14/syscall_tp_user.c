static void verify_map(int map_id)
{
__u32 key = 0;
__u32 val;
if (bpf_map_lookup_elem(map_id, &key, &val) != 0) {
fprintf(stderr, "map_lookup failed: %s\n", strerror(errno));
return;
}
if (val == 0)
fprintf(stderr, "failed: map #%d returns value 0\n", map_id);
}
int main(int argc, char **argv)
{
struct rlimit r = {RLIM_INFINITY, RLIM_INFINITY};
char filename[256];
int fd;
setrlimit(RLIMIT_MEMLOCK, &r);
snprintf(filename, sizeof(filename), "%s_kern.o", argv[0]);
if (load_bpf_file(filename)) {
fprintf(stderr, "%s", bpf_log_buf);
return 1;
}
fd = open(filename, O_RDONLY);
if (fd < 0) {
fprintf(stderr, "open failed: %s\n", strerror(errno));
return 1;
}
close(fd);
verify_map(map_fd[0]);
verify_map(map_fd[1]);
return 0;
}
