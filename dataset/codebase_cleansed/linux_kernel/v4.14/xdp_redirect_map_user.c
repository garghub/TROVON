static void int_exit(int sig)
{
set_link_xdp_fd(ifindex_in, -1, xdp_flags);
if (ifindex_out_xdp_dummy_attached)
set_link_xdp_fd(ifindex_out, -1, xdp_flags);
exit(0);
}
static void poll_stats(int interval, int ifindex)
{
unsigned int nr_cpus = bpf_num_possible_cpus();
__u64 values[nr_cpus], prev[nr_cpus];
memset(prev, 0, sizeof(prev));
while (1) {
__u64 sum = 0;
__u32 key = 0;
int i;
sleep(interval);
assert(bpf_map_lookup_elem(map_fd[1], &key, values) == 0);
for (i = 0; i < nr_cpus; i++)
sum += (values[i] - prev[i]);
if (sum)
printf("ifindex %i: %10llu pkt/s\n",
ifindex, sum / interval);
memcpy(prev, values, sizeof(values));
}
}
static void usage(const char *prog)
{
fprintf(stderr,
"usage: %s [OPTS] IFINDEX_IN IFINDEX_OUT\n\n"
"OPTS:\n"
" -S use skb-mode\n"
" -N enforce native mode\n",
prog);
}
int main(int argc, char **argv)
{
const char *optstr = "SN";
char filename[256];
int ret, opt, key = 0;
while ((opt = getopt(argc, argv, optstr)) != -1) {
switch (opt) {
case 'S':
xdp_flags |= XDP_FLAGS_SKB_MODE;
break;
case 'N':
xdp_flags |= XDP_FLAGS_DRV_MODE;
break;
default:
usage(basename(argv[0]));
return 1;
}
}
if (optind == argc) {
printf("usage: %s IFINDEX_IN IFINDEX_OUT\n", argv[0]);
return 1;
}
ifindex_in = strtoul(argv[optind], NULL, 0);
ifindex_out = strtoul(argv[optind + 1], NULL, 0);
printf("input: %d output: %d\n", ifindex_in, ifindex_out);
snprintf(filename, sizeof(filename), "%s_kern.o", argv[0]);
if (load_bpf_file(filename)) {
printf("%s", bpf_log_buf);
return 1;
}
if (!prog_fd[0]) {
printf("load_bpf_file: %s\n", strerror(errno));
return 1;
}
if (set_link_xdp_fd(ifindex_in, prog_fd[0], xdp_flags) < 0) {
printf("ERROR: link set xdp fd failed on %d\n", ifindex_in);
return 1;
}
if (set_link_xdp_fd(ifindex_out, prog_fd[1],
(xdp_flags | XDP_FLAGS_UPDATE_IF_NOEXIST)) < 0) {
printf("WARN: link set xdp fd failed on %d\n", ifindex_out);
ifindex_out_xdp_dummy_attached = false;
}
signal(SIGINT, int_exit);
signal(SIGTERM, int_exit);
printf("map[0] (vports) = %i, map[1] (map) = %i, map[2] (count) = %i\n",
map_fd[0], map_fd[1], map_fd[2]);
ret = bpf_map_update_elem(map_fd[0], &key, &ifindex_out, 0);
if (ret) {
perror("bpf_update_elem");
goto out;
}
poll_stats(2, ifindex_out);
out:
return 0;
}
