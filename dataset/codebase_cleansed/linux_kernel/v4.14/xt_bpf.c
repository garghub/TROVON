static int __bpf_mt_check_bytecode(struct sock_filter *insns, __u16 len,
struct bpf_prog **ret)
{
struct sock_fprog_kern program;
program.len = len;
program.filter = insns;
if (bpf_prog_create(ret, &program)) {
pr_info("bpf: check failed: parse error\n");
return -EINVAL;
}
return 0;
}
static int __bpf_mt_check_fd(int fd, struct bpf_prog **ret)
{
struct bpf_prog *prog;
prog = bpf_prog_get_type(fd, BPF_PROG_TYPE_SOCKET_FILTER);
if (IS_ERR(prog))
return PTR_ERR(prog);
*ret = prog;
return 0;
}
static int __bpf_mt_check_path(const char *path, struct bpf_prog **ret)
{
mm_segment_t oldfs = get_fs();
int retval, fd;
set_fs(KERNEL_DS);
fd = bpf_obj_get_user(path);
set_fs(oldfs);
if (fd < 0)
return fd;
retval = __bpf_mt_check_fd(fd, ret);
sys_close(fd);
return retval;
}
static int bpf_mt_check(const struct xt_mtchk_param *par)
{
struct xt_bpf_info *info = par->matchinfo;
return __bpf_mt_check_bytecode(info->bpf_program,
info->bpf_program_num_elem,
&info->filter);
}
static int bpf_mt_check_v1(const struct xt_mtchk_param *par)
{
struct xt_bpf_info_v1 *info = par->matchinfo;
if (info->mode == XT_BPF_MODE_BYTECODE)
return __bpf_mt_check_bytecode(info->bpf_program,
info->bpf_program_num_elem,
&info->filter);
else if (info->mode == XT_BPF_MODE_FD_ELF)
return __bpf_mt_check_fd(info->fd, &info->filter);
else if (info->mode == XT_BPF_MODE_PATH_PINNED)
return __bpf_mt_check_path(info->path, &info->filter);
else
return -EINVAL;
}
static bool bpf_mt(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_bpf_info *info = par->matchinfo;
return BPF_PROG_RUN(info->filter, skb);
}
static bool bpf_mt_v1(const struct sk_buff *skb, struct xt_action_param *par)
{
const struct xt_bpf_info_v1 *info = par->matchinfo;
return !!bpf_prog_run_save_cb(info->filter, (struct sk_buff *) skb);
}
static void bpf_mt_destroy(const struct xt_mtdtor_param *par)
{
const struct xt_bpf_info *info = par->matchinfo;
bpf_prog_destroy(info->filter);
}
static void bpf_mt_destroy_v1(const struct xt_mtdtor_param *par)
{
const struct xt_bpf_info_v1 *info = par->matchinfo;
bpf_prog_destroy(info->filter);
}
static int __init bpf_mt_init(void)
{
return xt_register_matches(bpf_mt_reg, ARRAY_SIZE(bpf_mt_reg));
}
static void __exit bpf_mt_exit(void)
{
xt_unregister_matches(bpf_mt_reg, ARRAY_SIZE(bpf_mt_reg));
}
