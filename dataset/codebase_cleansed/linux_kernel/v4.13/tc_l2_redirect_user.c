static void usage(void)
{
printf("Usage: tc_l2_ipip_redirect [...]\n");
printf(" -U <file> Update an already pinned BPF array\n");
printf(" -i <ifindex> Interface index\n");
printf(" -h Display this help\n");
}
int main(int argc, char **argv)
{
const char *pinned_file = NULL;
int ifindex = -1;
int array_key = 0;
int array_fd = -1;
int ret = -1;
int opt;
while ((opt = getopt(argc, argv, "F:U:i:")) != -1) {
switch (opt) {
case 'U':
pinned_file = optarg;
break;
case 'i':
ifindex = atoi(optarg);
break;
default:
usage();
goto out;
}
}
if (ifindex < 0 || !pinned_file) {
usage();
goto out;
}
array_fd = bpf_obj_get(pinned_file);
if (array_fd < 0) {
fprintf(stderr, "bpf_obj_get(%s): %s(%d)\n",
pinned_file, strerror(errno), errno);
goto out;
}
ret = bpf_map_update_elem(array_fd, &array_key, &ifindex, 0);
if (ret) {
perror("bpf_map_update_elem");
goto out;
}
out:
if (array_fd != -1)
close(array_fd);
return ret;
}
