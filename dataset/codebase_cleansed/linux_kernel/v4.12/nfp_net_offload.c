void nfp_net_filter_stats_timer(unsigned long data)
{
struct nfp_net *nn = (void *)data;
struct nfp_stat_pair latest;
spin_lock_bh(&nn->rx_filter_lock);
if (nn->dp.ctrl & NFP_NET_CFG_CTRL_BPF)
mod_timer(&nn->rx_filter_stats_timer,
jiffies + NFP_NET_STAT_POLL_IVL);
spin_unlock_bh(&nn->rx_filter_lock);
latest.pkts = nn_readq(nn, NFP_NET_CFG_STATS_APP1_FRAMES);
latest.bytes = nn_readq(nn, NFP_NET_CFG_STATS_APP1_BYTES);
if (latest.pkts != nn->rx_filter.pkts)
nn->rx_filter_change = jiffies;
nn->rx_filter = latest;
}
static void nfp_net_bpf_stats_reset(struct nfp_net *nn)
{
nn->rx_filter.pkts = nn_readq(nn, NFP_NET_CFG_STATS_APP1_FRAMES);
nn->rx_filter.bytes = nn_readq(nn, NFP_NET_CFG_STATS_APP1_BYTES);
nn->rx_filter_prev = nn->rx_filter;
nn->rx_filter_change = jiffies;
}
static int
nfp_net_bpf_stats_update(struct nfp_net *nn, struct tc_cls_bpf_offload *cls_bpf)
{
struct tc_action *a;
LIST_HEAD(actions);
u64 bytes, pkts;
pkts = nn->rx_filter.pkts - nn->rx_filter_prev.pkts;
bytes = nn->rx_filter.bytes - nn->rx_filter_prev.bytes;
bytes -= pkts * ETH_HLEN;
nn->rx_filter_prev = nn->rx_filter;
preempt_disable();
tcf_exts_to_list(cls_bpf->exts, &actions);
list_for_each_entry(a, &actions, list)
tcf_action_stats_update(a, bytes, pkts, nn->rx_filter_change);
preempt_enable();
return 0;
}
static int
nfp_net_bpf_get_act(struct nfp_net *nn, struct tc_cls_bpf_offload *cls_bpf)
{
const struct tc_action *a;
LIST_HEAD(actions);
if (!cls_bpf->exts)
return NN_ACT_XDP;
if (cls_bpf->exts_integrated) {
if (tc_no_actions(cls_bpf->exts))
return NN_ACT_DIRECT;
return -EOPNOTSUPP;
}
if (!tc_single_action(cls_bpf->exts))
return -EOPNOTSUPP;
tcf_exts_to_list(cls_bpf->exts, &actions);
list_for_each_entry(a, &actions, list) {
if (is_tcf_gact_shot(a))
return NN_ACT_TC_DROP;
if (is_tcf_mirred_egress_redirect(a) &&
tcf_mirred_ifindex(a) == nn->dp.netdev->ifindex)
return NN_ACT_TC_REDIR;
}
return -EOPNOTSUPP;
}
static int
nfp_net_bpf_offload_prepare(struct nfp_net *nn,
struct tc_cls_bpf_offload *cls_bpf,
struct nfp_bpf_result *res,
void **code, dma_addr_t *dma_addr, u16 max_instr)
{
unsigned int code_sz = max_instr * sizeof(u64);
enum nfp_bpf_action_type act;
u16 start_off, done_off;
unsigned int max_mtu;
int ret;
if (!IS_ENABLED(CONFIG_BPF_SYSCALL))
return -EOPNOTSUPP;
ret = nfp_net_bpf_get_act(nn, cls_bpf);
if (ret < 0)
return ret;
act = ret;
max_mtu = nn_readb(nn, NFP_NET_CFG_BPF_INL_MTU) * 64 - 32;
if (max_mtu < nn->dp.netdev->mtu) {
nn_info(nn, "BPF offload not supported with MTU larger than HW packet split boundary\n");
return -EOPNOTSUPP;
}
start_off = nn_readw(nn, NFP_NET_CFG_BPF_START);
done_off = nn_readw(nn, NFP_NET_CFG_BPF_DONE);
*code = dma_zalloc_coherent(nn->dp.dev, code_sz, dma_addr, GFP_KERNEL);
if (!*code)
return -ENOMEM;
ret = nfp_bpf_jit(cls_bpf->prog, *code, act, start_off, done_off,
max_instr, res);
if (ret)
goto out;
return 0;
out:
dma_free_coherent(nn->dp.dev, code_sz, *code, *dma_addr);
return ret;
}
static void
nfp_net_bpf_load_and_start(struct nfp_net *nn, u32 tc_flags,
void *code, dma_addr_t dma_addr,
unsigned int code_sz, unsigned int n_instr,
bool dense_mode)
{
u64 bpf_addr = dma_addr;
int err;
nn->dp.bpf_offload_skip_sw = !!(tc_flags & TCA_CLS_FLAGS_SKIP_SW);
if (dense_mode)
bpf_addr |= NFP_NET_CFG_BPF_CFG_8CTX;
nn_writew(nn, NFP_NET_CFG_BPF_SIZE, n_instr);
nn_writeq(nn, NFP_NET_CFG_BPF_ADDR, bpf_addr);
err = nfp_net_reconfig(nn, NFP_NET_CFG_UPDATE_BPF);
if (err)
nn_err(nn, "FW command error while loading BPF: %d\n", err);
nn->dp.ctrl |= NFP_NET_CFG_CTRL_BPF;
nn_writel(nn, NFP_NET_CFG_CTRL, nn->dp.ctrl);
err = nfp_net_reconfig(nn, NFP_NET_CFG_UPDATE_GEN);
if (err)
nn_err(nn, "FW command error while enabling BPF: %d\n", err);
dma_free_coherent(nn->dp.dev, code_sz, code, dma_addr);
nfp_net_bpf_stats_reset(nn);
mod_timer(&nn->rx_filter_stats_timer, jiffies + NFP_NET_STAT_POLL_IVL);
}
static int nfp_net_bpf_stop(struct nfp_net *nn)
{
if (!(nn->dp.ctrl & NFP_NET_CFG_CTRL_BPF))
return 0;
spin_lock_bh(&nn->rx_filter_lock);
nn->dp.ctrl &= ~NFP_NET_CFG_CTRL_BPF;
spin_unlock_bh(&nn->rx_filter_lock);
nn_writel(nn, NFP_NET_CFG_CTRL, nn->dp.ctrl);
del_timer_sync(&nn->rx_filter_stats_timer);
nn->dp.bpf_offload_skip_sw = 0;
return nfp_net_reconfig(nn, NFP_NET_CFG_UPDATE_GEN);
}
int nfp_net_bpf_offload(struct nfp_net *nn, struct tc_cls_bpf_offload *cls_bpf)
{
struct nfp_bpf_result res;
dma_addr_t dma_addr;
u16 max_instr;
void *code;
int err;
max_instr = nn_readw(nn, NFP_NET_CFG_BPF_MAX_LEN);
switch (cls_bpf->command) {
case TC_CLSBPF_REPLACE:
if (nn->dp.bpf_offload_skip_sw)
return -EBUSY;
err = nfp_net_bpf_offload_prepare(nn, cls_bpf, &res, &code,
&dma_addr, max_instr);
if (err)
return err;
nfp_net_bpf_stop(nn);
nfp_net_bpf_load_and_start(nn, cls_bpf->gen_flags, code,
dma_addr, max_instr * sizeof(u64),
res.n_instr, res.dense_mode);
return 0;
case TC_CLSBPF_ADD:
if (nn->dp.ctrl & NFP_NET_CFG_CTRL_BPF)
return -EBUSY;
err = nfp_net_bpf_offload_prepare(nn, cls_bpf, &res, &code,
&dma_addr, max_instr);
if (err)
return err;
nfp_net_bpf_load_and_start(nn, cls_bpf->gen_flags, code,
dma_addr, max_instr * sizeof(u64),
res.n_instr, res.dense_mode);
return 0;
case TC_CLSBPF_DESTROY:
return nfp_net_bpf_stop(nn);
case TC_CLSBPF_STATS:
return nfp_net_bpf_stats_update(nn, cls_bpf);
default:
return -EOPNOTSUPP;
}
}
