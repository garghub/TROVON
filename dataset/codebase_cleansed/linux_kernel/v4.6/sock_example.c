static int test_sock(void)
{
int sock = -1, map_fd, prog_fd, i, key;
long long value = 0, tcp_cnt, udp_cnt, icmp_cnt;
map_fd = bpf_create_map(BPF_MAP_TYPE_ARRAY, sizeof(key), sizeof(value),
256, 0);
if (map_fd < 0) {
printf("failed to create map '%s'\n", strerror(errno));
goto cleanup;
}
struct bpf_insn prog[] = {
BPF_MOV64_REG(BPF_REG_6, BPF_REG_1),
BPF_LD_ABS(BPF_B, ETH_HLEN + offsetof(struct iphdr, protocol) ),
BPF_STX_MEM(BPF_W, BPF_REG_10, BPF_REG_0, -4),
BPF_MOV64_REG(BPF_REG_2, BPF_REG_10),
BPF_ALU64_IMM(BPF_ADD, BPF_REG_2, -4),
BPF_LD_MAP_FD(BPF_REG_1, map_fd),
BPF_RAW_INSN(BPF_JMP | BPF_CALL, 0, 0, 0, BPF_FUNC_map_lookup_elem),
BPF_JMP_IMM(BPF_JEQ, BPF_REG_0, 0, 2),
BPF_MOV64_IMM(BPF_REG_1, 1),
BPF_RAW_INSN(BPF_STX | BPF_XADD | BPF_DW, BPF_REG_0, BPF_REG_1, 0, 0),
BPF_MOV64_IMM(BPF_REG_0, 0),
BPF_EXIT_INSN(),
};
prog_fd = bpf_prog_load(BPF_PROG_TYPE_SOCKET_FILTER, prog, sizeof(prog),
"GPL", 0);
if (prog_fd < 0) {
printf("failed to load prog '%s'\n", strerror(errno));
goto cleanup;
}
sock = open_raw_sock("lo");
if (setsockopt(sock, SOL_SOCKET, SO_ATTACH_BPF, &prog_fd,
sizeof(prog_fd)) < 0) {
printf("setsockopt %s\n", strerror(errno));
goto cleanup;
}
for (i = 0; i < 10; i++) {
key = IPPROTO_TCP;
assert(bpf_lookup_elem(map_fd, &key, &tcp_cnt) == 0);
key = IPPROTO_UDP;
assert(bpf_lookup_elem(map_fd, &key, &udp_cnt) == 0);
key = IPPROTO_ICMP;
assert(bpf_lookup_elem(map_fd, &key, &icmp_cnt) == 0);
printf("TCP %lld UDP %lld ICMP %lld packets\n",
tcp_cnt, udp_cnt, icmp_cnt);
sleep(1);
}
cleanup:
return 0;
}
int main(void)
{
FILE *f;
f = popen("ping -c5 localhost", "r");
(void)f;
return test_sock();
}
