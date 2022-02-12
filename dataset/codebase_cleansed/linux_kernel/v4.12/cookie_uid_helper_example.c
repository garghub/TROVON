static void maps_create(void)
{
map_fd = bpf_create_map(BPF_MAP_TYPE_HASH, sizeof(uint32_t),
sizeof(struct stats), 100, 0);
if (map_fd < 0)
error(1, errno, "map create failed!\n");
}
static void prog_load(void)
{
static char log_buf[1 << 16];
struct bpf_insn prog[] = {
BPF_MOV64_REG(BPF_REG_6, BPF_REG_1),
BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
BPF_FUNC_get_socket_cookie),
BPF_STX_MEM(BPF_DW, BPF_REG_10, BPF_REG_0, -8),
BPF_MOV64_REG(BPF_REG_7, BPF_REG_10),
BPF_ALU64_IMM(BPF_ADD, BPF_REG_7, -8),
BPF_LD_MAP_FD(BPF_REG_1, map_fd),
BPF_MOV64_REG(BPF_REG_2, BPF_REG_7),
BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
BPF_FUNC_map_lookup_elem),
BPF_JMP_IMM(BPF_JNE, BPF_REG_0, 0, 14),
BPF_MOV64_REG(BPF_REG_1, BPF_REG_6),
BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
BPF_FUNC_get_socket_uid),
BPF_STX_MEM(BPF_DW, BPF_REG_10, BPF_REG_0,
-32 + (__s16)offsetof(struct stats, uid)),
BPF_ST_MEM(BPF_DW, BPF_REG_10,
-32 + (__s16)offsetof(struct stats, packets), 1),
BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_6,
offsetof(struct __sk_buff, len)),
BPF_STX_MEM(BPF_DW, BPF_REG_10, BPF_REG_1,
-32 + (__s16)offsetof(struct stats, bytes)),
BPF_LD_MAP_FD(BPF_REG_1, map_fd),
BPF_MOV64_REG(BPF_REG_2, BPF_REG_7),
BPF_MOV64_REG(BPF_REG_3, BPF_REG_10),
BPF_ALU64_IMM(BPF_ADD, BPF_REG_3, -32),
BPF_MOV64_IMM(BPF_REG_4, 0),
BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0,
BPF_FUNC_map_update_elem),
BPF_JMP_IMM(BPF_JA, 0, 0, 5),
BPF_MOV64_REG(BPF_REG_9, BPF_REG_0),
BPF_MOV64_IMM(BPF_REG_1, 1),
BPF_STX_XADD(BPF_DW, BPF_REG_9, BPF_REG_1,
offsetof(struct stats, packets)),
BPF_LDX_MEM(BPF_W, BPF_REG_1, BPF_REG_6,
offsetof(struct __sk_buff, len)),
BPF_STX_XADD(BPF_DW, BPF_REG_9, BPF_REG_1,
offsetof(struct stats, bytes)),
BPF_LDX_MEM(BPF_W, BPF_REG_0, BPF_REG_6,
offsetof(struct __sk_buff, len)),
BPF_EXIT_INSN(),
};
prog_fd = bpf_load_program(BPF_PROG_TYPE_SOCKET_FILTER, prog,
ARRAY_SIZE(prog), "GPL", 0,
log_buf, sizeof(log_buf));
if (prog_fd < 0)
error(1, errno, "failed to load prog\n%s\n", log_buf);
}
static void prog_attach_iptables(char *file)
{
int ret;
char rules[100];
if (bpf_obj_pin(prog_fd, file))
error(1, errno, "bpf_obj_pin");
if (strlen(file) > 50) {
printf("file path too long: %s\n", file);
exit(1);
}
sprintf(rules, "iptables -A OUTPUT -m bpf --object-pinned %s -j ACCEPT",
file);
ret = system(rules);
if (ret < 0) {
printf("iptables rule update failed: %d/n", WEXITSTATUS(ret));
exit(1);
}
}
static void print_table(void)
{
struct stats curEntry;
uint32_t curN = UINT32_MAX;
uint32_t nextN;
int res;
while (bpf_map_get_next_key(map_fd, &curN, &nextN) > -1) {
curN = nextN;
res = bpf_map_lookup_elem(map_fd, &curN, &curEntry);
if (res < 0) {
error(1, errno, "fail to get entry value of Key: %u\n",
curN);
} else {
printf("cookie: %u, uid: 0x%x, Packet Count: %lu,"
" Bytes Count: %lu\n", curN, curEntry.uid,
curEntry.packets, curEntry.bytes);
}
}
}
static void udp_client(void)
{
struct sockaddr_in si_other = {0};
struct sockaddr_in si_me = {0};
struct stats dataEntry;
int s_rcv, s_send, i, recv_len;
char message = 'a';
char buf;
uint64_t cookie;
int res;
socklen_t cookie_len = sizeof(cookie);
socklen_t slen = sizeof(si_other);
s_rcv = socket(PF_INET, SOCK_DGRAM, 0);
if (s_rcv < 0)
error(1, errno, "rcv socket creat failed!\n");
si_other.sin_family = AF_INET;
si_other.sin_port = htons(PORT);
if (inet_aton("127.0.0.1", &si_other.sin_addr) == 0)
error(1, errno, "inet_aton\n");
if (bind(s_rcv, (struct sockaddr *)&si_other, sizeof(si_other)) == -1)
error(1, errno, "bind\n");
s_send = socket(PF_INET, SOCK_DGRAM, 0);
if (s_send < 0)
error(1, errno, "send socket creat failed!\n");
res = getsockopt(s_send, SOL_SOCKET, SO_COOKIE, &cookie, &cookie_len);
if (res < 0)
printf("get cookie failed: %s\n", strerror(errno));
res = bpf_map_lookup_elem(map_fd, &cookie, &dataEntry);
if (res != -1)
error(1, errno, "socket stat found while flow not active\n");
for (i = 0; i < 10; i++) {
res = sendto(s_send, &message, sizeof(message), 0,
(struct sockaddr *)&si_other, slen);
if (res == -1)
error(1, errno, "send\n");
if (res != sizeof(message))
error(1, 0, "%uB != %luB\n", res, sizeof(message));
recv_len = recvfrom(s_rcv, &buf, sizeof(buf), 0,
(struct sockaddr *)&si_me, &slen);
if (recv_len < 0)
error(1, errno, "revieve\n");
res = memcmp(&(si_other.sin_addr), &(si_me.sin_addr),
sizeof(si_me.sin_addr));
if (res != 0)
error(1, EFAULT, "sender addr error: %d\n", res);
printf("Message received: %c\n", buf);
res = bpf_map_lookup_elem(map_fd, &cookie, &dataEntry);
if (res < 0)
error(1, errno, "lookup sk stat failed, cookie: %lu\n",
cookie);
printf("cookie: %lu, uid: 0x%x, Packet Count: %lu,"
" Bytes Count: %lu\n\n", cookie, dataEntry.uid,
dataEntry.packets, dataEntry.bytes);
}
close(s_send);
close(s_rcv);
}
static int usage(void)
{
printf("Usage: ./run_cookie_uid_helper_example.sh"
" bpfObjName -option\n"
" -t traffic monitor test\n"
" -s getsockopt cookie test\n");
return 1;
}
static void finish(int ret)
{
test_finish = true;
}
int main(int argc, char *argv[])
{
int opt;
bool cfg_test_traffic = false;
bool cfg_test_cookie = false;
if (argc != 3)
return usage();
while ((opt = getopt(argc, argv, "ts")) != -1) {
switch (opt) {
case 't':
cfg_test_traffic = true;
break;
case 's':
cfg_test_cookie = true;
break;
default:
printf("unknown option %c\n", opt);
usage();
return -1;
}
}
maps_create();
prog_load();
prog_attach_iptables(argv[2]);
if (cfg_test_traffic) {
if (signal(SIGINT, finish) == SIG_ERR)
error(1, errno, "register SIGINT handler failed");
if (signal(SIGTERM, finish) == SIG_ERR)
error(1, errno, "register SIGTERM handler failed");
while (!test_finish) {
print_table();
printf("\n");
sleep(1);
};
} else if (cfg_test_cookie) {
udp_client();
}
close(prog_fd);
close(map_fd);
return 0;
}
