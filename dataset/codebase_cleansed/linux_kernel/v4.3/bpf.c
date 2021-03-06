static __u64 ptr_to_u64(void *ptr)
{
return (__u64) (unsigned long) ptr;
}
static int sys_bpf(enum bpf_cmd cmd, union bpf_attr *attr,
unsigned int size)
{
return syscall(__NR_bpf, cmd, attr, size);
}
int bpf_create_map(enum bpf_map_type map_type, int key_size,
int value_size, int max_entries)
{
union bpf_attr attr;
memset(&attr, '\0', sizeof(attr));
attr.map_type = map_type;
attr.key_size = key_size;
attr.value_size = value_size;
attr.max_entries = max_entries;
return sys_bpf(BPF_MAP_CREATE, &attr, sizeof(attr));
}
int bpf_load_program(enum bpf_prog_type type, struct bpf_insn *insns,
size_t insns_cnt, char *license,
u32 kern_version, char *log_buf, size_t log_buf_sz)
{
int fd;
union bpf_attr attr;
bzero(&attr, sizeof(attr));
attr.prog_type = type;
attr.insn_cnt = (__u32)insns_cnt;
attr.insns = ptr_to_u64(insns);
attr.license = ptr_to_u64(license);
attr.log_buf = ptr_to_u64(NULL);
attr.log_size = 0;
attr.log_level = 0;
attr.kern_version = kern_version;
fd = sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
if (fd >= 0 || !log_buf || !log_buf_sz)
return fd;
attr.log_buf = ptr_to_u64(log_buf);
attr.log_size = log_buf_sz;
attr.log_level = 1;
log_buf[0] = 0;
return sys_bpf(BPF_PROG_LOAD, &attr, sizeof(attr));
}
