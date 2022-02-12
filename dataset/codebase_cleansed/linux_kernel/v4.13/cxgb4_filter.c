static inline bool is_field_set(u32 val, u32 mask)
{
return val || mask;
}
static inline bool unsupported(u32 conf, u32 conf_mask, u32 val, u32 mask)
{
return !(conf & conf_mask) && is_field_set(val, mask);
}
static int validate_filter(struct net_device *dev,
struct ch_filter_specification *fs)
{
struct adapter *adapter = netdev2adap(dev);
u32 fconf, iconf;
fconf = adapter->params.tp.vlan_pri_map;
iconf = adapter->params.tp.ingress_config;
if (unsupported(fconf, FCOE_F, fs->val.fcoe, fs->mask.fcoe) ||
unsupported(fconf, PORT_F, fs->val.iport, fs->mask.iport) ||
unsupported(fconf, TOS_F, fs->val.tos, fs->mask.tos) ||
unsupported(fconf, ETHERTYPE_F, fs->val.ethtype,
fs->mask.ethtype) ||
unsupported(fconf, MACMATCH_F, fs->val.macidx, fs->mask.macidx) ||
unsupported(fconf, MPSHITTYPE_F, fs->val.matchtype,
fs->mask.matchtype) ||
unsupported(fconf, FRAGMENTATION_F, fs->val.frag, fs->mask.frag) ||
unsupported(fconf, PROTOCOL_F, fs->val.proto, fs->mask.proto) ||
unsupported(fconf, VNIC_ID_F, fs->val.pfvf_vld,
fs->mask.pfvf_vld) ||
unsupported(fconf, VNIC_ID_F, fs->val.ovlan_vld,
fs->mask.ovlan_vld) ||
unsupported(fconf, VLAN_F, fs->val.ivlan_vld, fs->mask.ivlan_vld))
return -EOPNOTSUPP;
if (is_field_set(fs->val.pfvf_vld, fs->mask.pfvf_vld) &&
is_field_set(fs->val.ovlan_vld, fs->mask.ovlan_vld))
return -EOPNOTSUPP;
if (unsupported(iconf, VNIC_F, fs->val.pfvf_vld, fs->mask.pfvf_vld) ||
(is_field_set(fs->val.ovlan_vld, fs->mask.ovlan_vld) &&
(iconf & VNIC_F)))
return -EOPNOTSUPP;
if (fs->val.pf > 0x7 || fs->val.vf > 0x7f)
return -ERANGE;
fs->mask.pf &= 0x7;
fs->mask.vf &= 0x7f;
if (fs->action == FILTER_SWITCH &&
fs->eport >= adapter->params.nports)
return -ERANGE;
if (fs->val.iport >= adapter->params.nports)
return -ERANGE;
if (is_t4(adapter->params.chip) &&
fs->action == FILTER_SWITCH &&
(fs->newvlan == VLAN_REMOVE ||
fs->newvlan == VLAN_REWRITE))
return -EOPNOTSUPP;
return 0;
}
static int get_filter_steerq(struct net_device *dev,
struct ch_filter_specification *fs)
{
struct adapter *adapter = netdev2adap(dev);
int iq;
if (!fs->dirsteer) {
if (fs->iq)
return -EINVAL;
iq = 0;
} else {
struct port_info *pi = netdev_priv(dev);
if (fs->iq < pi->nqsets)
iq = adapter->sge.ethrxq[pi->first_qset +
fs->iq].rspq.abs_id;
else
iq = fs->iq;
}
return iq;
}
static int cxgb4_set_ftid(struct tid_info *t, int fidx, int family)
{
spin_lock_bh(&t->ftid_lock);
if (test_bit(fidx, t->ftid_bmap)) {
spin_unlock_bh(&t->ftid_lock);
return -EBUSY;
}
if (family == PF_INET)
__set_bit(fidx, t->ftid_bmap);
else
bitmap_allocate_region(t->ftid_bmap, fidx, 2);
spin_unlock_bh(&t->ftid_lock);
return 0;
}
static void cxgb4_clear_ftid(struct tid_info *t, int fidx, int family)
{
spin_lock_bh(&t->ftid_lock);
if (family == PF_INET)
__clear_bit(fidx, t->ftid_bmap);
else
bitmap_release_region(t->ftid_bmap, fidx, 2);
spin_unlock_bh(&t->ftid_lock);
}
static int del_filter_wr(struct adapter *adapter, int fidx)
{
struct filter_entry *f = &adapter->tids.ftid_tab[fidx];
struct fw_filter_wr *fwr;
struct sk_buff *skb;
unsigned int len;
len = sizeof(*fwr);
skb = alloc_skb(len, GFP_KERNEL);
if (!skb)
return -ENOMEM;
fwr = __skb_put(skb, len);
t4_mk_filtdelwr(f->tid, fwr, adapter->sge.fw_evtq.abs_id);
f->pending = 1;
t4_mgmt_tx(adapter, skb);
return 0;
}
int set_filter_wr(struct adapter *adapter, int fidx)
{
struct filter_entry *f = &adapter->tids.ftid_tab[fidx];
struct fw_filter_wr *fwr;
struct sk_buff *skb;
skb = alloc_skb(sizeof(*fwr), GFP_KERNEL);
if (!skb)
return -ENOMEM;
if (f->fs.newdmac || f->fs.newvlan) {
f->l2t = t4_l2t_alloc_switching(adapter, f->fs.vlan,
f->fs.eport, f->fs.dmac);
if (!f->l2t) {
kfree_skb(skb);
return -ENOMEM;
}
}
fwr = __skb_put_zero(skb, sizeof(*fwr));
fwr->op_pkd = htonl(FW_WR_OP_V(FW_FILTER_WR));
fwr->len16_pkd = htonl(FW_WR_LEN16_V(sizeof(*fwr) / 16));
fwr->tid_to_iq =
htonl(FW_FILTER_WR_TID_V(f->tid) |
FW_FILTER_WR_RQTYPE_V(f->fs.type) |
FW_FILTER_WR_NOREPLY_V(0) |
FW_FILTER_WR_IQ_V(f->fs.iq));
fwr->del_filter_to_l2tix =
htonl(FW_FILTER_WR_RPTTID_V(f->fs.rpttid) |
FW_FILTER_WR_DROP_V(f->fs.action == FILTER_DROP) |
FW_FILTER_WR_DIRSTEER_V(f->fs.dirsteer) |
FW_FILTER_WR_MASKHASH_V(f->fs.maskhash) |
FW_FILTER_WR_DIRSTEERHASH_V(f->fs.dirsteerhash) |
FW_FILTER_WR_LPBK_V(f->fs.action == FILTER_SWITCH) |
FW_FILTER_WR_DMAC_V(f->fs.newdmac) |
FW_FILTER_WR_SMAC_V(f->fs.newsmac) |
FW_FILTER_WR_INSVLAN_V(f->fs.newvlan == VLAN_INSERT ||
f->fs.newvlan == VLAN_REWRITE) |
FW_FILTER_WR_RMVLAN_V(f->fs.newvlan == VLAN_REMOVE ||
f->fs.newvlan == VLAN_REWRITE) |
FW_FILTER_WR_HITCNTS_V(f->fs.hitcnts) |
FW_FILTER_WR_TXCHAN_V(f->fs.eport) |
FW_FILTER_WR_PRIO_V(f->fs.prio) |
FW_FILTER_WR_L2TIX_V(f->l2t ? f->l2t->idx : 0));
fwr->ethtype = htons(f->fs.val.ethtype);
fwr->ethtypem = htons(f->fs.mask.ethtype);
fwr->frag_to_ovlan_vldm =
(FW_FILTER_WR_FRAG_V(f->fs.val.frag) |
FW_FILTER_WR_FRAGM_V(f->fs.mask.frag) |
FW_FILTER_WR_IVLAN_VLD_V(f->fs.val.ivlan_vld) |
FW_FILTER_WR_OVLAN_VLD_V(f->fs.val.ovlan_vld) |
FW_FILTER_WR_IVLAN_VLDM_V(f->fs.mask.ivlan_vld) |
FW_FILTER_WR_OVLAN_VLDM_V(f->fs.mask.ovlan_vld));
fwr->smac_sel = 0;
fwr->rx_chan_rx_rpl_iq =
htons(FW_FILTER_WR_RX_CHAN_V(0) |
FW_FILTER_WR_RX_RPL_IQ_V(adapter->sge.fw_evtq.abs_id));
fwr->maci_to_matchtypem =
htonl(FW_FILTER_WR_MACI_V(f->fs.val.macidx) |
FW_FILTER_WR_MACIM_V(f->fs.mask.macidx) |
FW_FILTER_WR_FCOE_V(f->fs.val.fcoe) |
FW_FILTER_WR_FCOEM_V(f->fs.mask.fcoe) |
FW_FILTER_WR_PORT_V(f->fs.val.iport) |
FW_FILTER_WR_PORTM_V(f->fs.mask.iport) |
FW_FILTER_WR_MATCHTYPE_V(f->fs.val.matchtype) |
FW_FILTER_WR_MATCHTYPEM_V(f->fs.mask.matchtype));
fwr->ptcl = f->fs.val.proto;
fwr->ptclm = f->fs.mask.proto;
fwr->ttyp = f->fs.val.tos;
fwr->ttypm = f->fs.mask.tos;
fwr->ivlan = htons(f->fs.val.ivlan);
fwr->ivlanm = htons(f->fs.mask.ivlan);
fwr->ovlan = htons(f->fs.val.ovlan);
fwr->ovlanm = htons(f->fs.mask.ovlan);
memcpy(fwr->lip, f->fs.val.lip, sizeof(fwr->lip));
memcpy(fwr->lipm, f->fs.mask.lip, sizeof(fwr->lipm));
memcpy(fwr->fip, f->fs.val.fip, sizeof(fwr->fip));
memcpy(fwr->fipm, f->fs.mask.fip, sizeof(fwr->fipm));
fwr->lp = htons(f->fs.val.lport);
fwr->lpm = htons(f->fs.mask.lport);
fwr->fp = htons(f->fs.val.fport);
fwr->fpm = htons(f->fs.mask.fport);
if (f->fs.newsmac)
memcpy(fwr->sma, f->fs.smac, sizeof(fwr->sma));
f->pending = 1;
set_wr_txq(skb, CPL_PRIORITY_CONTROL, f->fs.val.iport & 0x3);
t4_ofld_send(adapter, skb);
return 0;
}
int writable_filter(struct filter_entry *f)
{
if (f->locked)
return -EPERM;
if (f->pending)
return -EBUSY;
return 0;
}
int delete_filter(struct adapter *adapter, unsigned int fidx)
{
struct filter_entry *f;
int ret;
if (fidx >= adapter->tids.nftids + adapter->tids.nsftids)
return -EINVAL;
f = &adapter->tids.ftid_tab[fidx];
ret = writable_filter(f);
if (ret)
return ret;
if (f->valid)
return del_filter_wr(adapter, fidx);
return 0;
}
void clear_filter(struct adapter *adap, struct filter_entry *f)
{
if (f->l2t)
cxgb4_l2t_release(f->l2t);
memset(f, 0, sizeof(*f));
}
void clear_all_filters(struct adapter *adapter)
{
unsigned int i;
if (adapter->tids.ftid_tab) {
struct filter_entry *f = &adapter->tids.ftid_tab[0];
unsigned int max_ftid = adapter->tids.nftids +
adapter->tids.nsftids;
for (i = 0; i < max_ftid; i++, f++)
if (f->valid || f->pending)
clear_filter(adapter, f);
}
}
static void fill_default_mask(struct ch_filter_specification *fs)
{
unsigned int lip = 0, lip_mask = 0;
unsigned int fip = 0, fip_mask = 0;
unsigned int i;
if (fs->val.iport && !fs->mask.iport)
fs->mask.iport |= ~0;
if (fs->val.fcoe && !fs->mask.fcoe)
fs->mask.fcoe |= ~0;
if (fs->val.matchtype && !fs->mask.matchtype)
fs->mask.matchtype |= ~0;
if (fs->val.macidx && !fs->mask.macidx)
fs->mask.macidx |= ~0;
if (fs->val.ethtype && !fs->mask.ethtype)
fs->mask.ethtype |= ~0;
if (fs->val.ivlan && !fs->mask.ivlan)
fs->mask.ivlan |= ~0;
if (fs->val.ovlan && !fs->mask.ovlan)
fs->mask.ovlan |= ~0;
if (fs->val.frag && !fs->mask.frag)
fs->mask.frag |= ~0;
if (fs->val.tos && !fs->mask.tos)
fs->mask.tos |= ~0;
if (fs->val.proto && !fs->mask.proto)
fs->mask.proto |= ~0;
for (i = 0; i < ARRAY_SIZE(fs->val.lip); i++) {
lip |= fs->val.lip[i];
lip_mask |= fs->mask.lip[i];
fip |= fs->val.fip[i];
fip_mask |= fs->mask.fip[i];
}
if (lip && !lip_mask)
memset(fs->mask.lip, ~0, sizeof(fs->mask.lip));
if (fip && !fip_mask)
memset(fs->mask.fip, ~0, sizeof(fs->mask.lip));
if (fs->val.lport && !fs->mask.lport)
fs->mask.lport = ~0;
if (fs->val.fport && !fs->mask.fport)
fs->mask.fport = ~0;
}
int __cxgb4_set_filter(struct net_device *dev, int filter_id,
struct ch_filter_specification *fs,
struct filter_ctx *ctx)
{
struct adapter *adapter = netdev2adap(dev);
unsigned int max_fidx, fidx;
struct filter_entry *f;
u32 iconf;
int iq, ret;
max_fidx = adapter->tids.nftids;
if (filter_id != (max_fidx + adapter->tids.nsftids - 1) &&
filter_id >= max_fidx)
return -E2BIG;
fill_default_mask(fs);
ret = validate_filter(dev, fs);
if (ret)
return ret;
iq = get_filter_steerq(dev, fs);
if (iq < 0)
return iq;
if (fs->type == 0) {
fidx = filter_id & ~0x3;
if (fidx != filter_id &&
adapter->tids.ftid_tab[fidx].fs.type) {
f = &adapter->tids.ftid_tab[fidx];
if (f->valid) {
dev_err(adapter->pdev_dev,
"Invalid location. IPv6 requires 4 slots and is occupying slots %u to %u\n",
fidx, fidx + 3);
return -EINVAL;
}
}
} else {
if (filter_id & 0x3) {
dev_err(adapter->pdev_dev,
"Invalid location. IPv6 must be aligned on a 4-slot boundary\n");
return -EINVAL;
}
for (fidx = filter_id + 1; fidx < filter_id + 4; fidx++) {
f = &adapter->tids.ftid_tab[fidx];
if (f->valid) {
dev_err(adapter->pdev_dev,
"Invalid location. IPv6 requires 4 slots and an IPv4 filter exists at %u\n",
fidx);
return -EINVAL;
}
}
}
f = &adapter->tids.ftid_tab[filter_id];
if (f->valid)
return -EBUSY;
fidx = filter_id + adapter->tids.ftid_base;
ret = cxgb4_set_ftid(&adapter->tids, filter_id,
fs->type ? PF_INET6 : PF_INET);
if (ret)
return ret;
ret = writable_filter(f);
if (ret) {
cxgb4_clear_ftid(&adapter->tids, filter_id,
fs->type ? PF_INET6 : PF_INET);
return ret;
}
if (f->valid)
clear_filter(adapter, f);
f->fs = *fs;
f->fs.iq = iq;
f->dev = dev;
iconf = adapter->params.tp.ingress_config;
if (iconf & VNIC_F) {
f->fs.val.ovlan = (fs->val.pf << 13) | fs->val.vf;
f->fs.mask.ovlan = (fs->mask.pf << 13) | fs->mask.vf;
f->fs.val.ovlan_vld = fs->val.pfvf_vld;
f->fs.mask.ovlan_vld = fs->mask.pfvf_vld;
}
f->ctx = ctx;
f->tid = fidx;
ret = set_filter_wr(adapter, filter_id);
if (ret) {
cxgb4_clear_ftid(&adapter->tids, filter_id,
fs->type ? PF_INET6 : PF_INET);
clear_filter(adapter, f);
}
return ret;
}
int __cxgb4_del_filter(struct net_device *dev, int filter_id,
struct filter_ctx *ctx)
{
struct adapter *adapter = netdev2adap(dev);
struct filter_entry *f;
unsigned int max_fidx;
int ret;
max_fidx = adapter->tids.nftids;
if (filter_id != (max_fidx + adapter->tids.nsftids - 1) &&
filter_id >= max_fidx)
return -E2BIG;
f = &adapter->tids.ftid_tab[filter_id];
ret = writable_filter(f);
if (ret)
return ret;
if (f->valid) {
f->ctx = ctx;
cxgb4_clear_ftid(&adapter->tids, filter_id,
f->fs.type ? PF_INET6 : PF_INET);
return del_filter_wr(adapter, filter_id);
}
if (ctx) {
ctx->result = 0;
complete(&ctx->completion);
}
return ret;
}
int cxgb4_set_filter(struct net_device *dev, int filter_id,
struct ch_filter_specification *fs)
{
struct filter_ctx ctx;
int ret;
init_completion(&ctx.completion);
ret = __cxgb4_set_filter(dev, filter_id, fs, &ctx);
if (ret)
goto out;
ret = wait_for_completion_timeout(&ctx.completion, 10 * HZ);
if (!ret)
return -ETIMEDOUT;
ret = ctx.result;
out:
return ret;
}
int cxgb4_del_filter(struct net_device *dev, int filter_id)
{
struct filter_ctx ctx;
int ret;
init_completion(&ctx.completion);
ret = __cxgb4_del_filter(dev, filter_id, &ctx);
if (ret)
goto out;
ret = wait_for_completion_timeout(&ctx.completion, 10 * HZ);
if (!ret)
return -ETIMEDOUT;
ret = ctx.result;
out:
return ret;
}
void filter_rpl(struct adapter *adap, const struct cpl_set_tcb_rpl *rpl)
{
unsigned int tid = GET_TID(rpl);
struct filter_entry *f = NULL;
unsigned int max_fidx;
int idx;
max_fidx = adap->tids.nftids + adap->tids.nsftids;
if (adap->tids.ftid_tab) {
idx = tid - adap->tids.ftid_base;
if (idx >= max_fidx)
return;
f = &adap->tids.ftid_tab[idx];
if (f->tid != tid)
return;
}
if (f) {
unsigned int ret = TCB_COOKIE_G(rpl->cookie);
struct filter_ctx *ctx;
ctx = f->ctx;
f->ctx = NULL;
if (ret == FW_FILTER_WR_FLT_DELETED) {
clear_filter(adap, f);
if (ctx)
ctx->result = 0;
} else if (ret == FW_FILTER_WR_SMT_TBL_FULL) {
dev_err(adap->pdev_dev, "filter %u setup failed due to full SMT\n",
idx);
clear_filter(adap, f);
if (ctx)
ctx->result = -ENOMEM;
} else if (ret == FW_FILTER_WR_FLT_ADDED) {
f->smtidx = (be64_to_cpu(rpl->oldval) >> 24) & 0xff;
f->pending = 0;
f->valid = 1;
if (ctx) {
ctx->result = 0;
ctx->tid = idx;
}
} else {
dev_err(adap->pdev_dev, "filter %u setup failed with error %u\n",
idx, ret);
clear_filter(adap, f);
if (ctx)
ctx->result = -EINVAL;
}
if (ctx)
complete(&ctx->completion);
}
}
