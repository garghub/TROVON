static void
bfa_cee_format_cee_cfg(void *buffer)
{
struct bfa_cee_attr *cee_cfg = buffer;
bfa_cee_format_lldp_cfg(&cee_cfg->lldp_remote);
}
static void
bfa_cee_stats_swap(struct bfa_cee_stats *stats)
{
u32 *buffer = (u32 *)stats;
int i;
for (i = 0; i < (sizeof(struct bfa_cee_stats) / sizeof(u32));
i++) {
buffer[i] = ntohl(buffer[i]);
}
}
static void
bfa_cee_format_lldp_cfg(struct bfa_cee_lldp_cfg *lldp_cfg)
{
lldp_cfg->time_to_live =
ntohs(lldp_cfg->time_to_live);
lldp_cfg->enabled_system_cap =
ntohs(lldp_cfg->enabled_system_cap);
}
static u32
bfa_cee_attr_meminfo(void)
{
return roundup(sizeof(struct bfa_cee_attr), BFA_DMA_ALIGN_SZ);
}
static u32
bfa_cee_stats_meminfo(void)
{
return roundup(sizeof(struct bfa_cee_stats), BFA_DMA_ALIGN_SZ);
}
static void
bfa_cee_get_attr_isr(struct bfa_cee *cee, enum bfa_status status)
{
cee->get_attr_status = status;
if (status == BFA_STATUS_OK) {
memcpy(cee->attr, cee->attr_dma.kva,
sizeof(struct bfa_cee_attr));
bfa_cee_format_cee_cfg(cee->attr);
}
cee->get_attr_pending = false;
if (cee->cbfn.get_attr_cbfn)
cee->cbfn.get_attr_cbfn(cee->cbfn.get_attr_cbarg, status);
}
static void
bfa_cee_get_stats_isr(struct bfa_cee *cee, enum bfa_status status)
{
cee->get_stats_status = status;
if (status == BFA_STATUS_OK) {
memcpy(cee->stats, cee->stats_dma.kva,
sizeof(struct bfa_cee_stats));
bfa_cee_stats_swap(cee->stats);
}
cee->get_stats_pending = false;
if (cee->cbfn.get_stats_cbfn)
cee->cbfn.get_stats_cbfn(cee->cbfn.get_stats_cbarg, status);
}
static void
bfa_cee_reset_stats_isr(struct bfa_cee *cee, enum bfa_status status)
{
cee->reset_stats_status = status;
cee->reset_stats_pending = false;
if (cee->cbfn.reset_stats_cbfn)
cee->cbfn.reset_stats_cbfn(cee->cbfn.reset_stats_cbarg, status);
}
u32
bfa_nw_cee_meminfo(void)
{
return bfa_cee_attr_meminfo() + bfa_cee_stats_meminfo();
}
void
bfa_nw_cee_mem_claim(struct bfa_cee *cee, u8 *dma_kva, u64 dma_pa)
{
cee->attr_dma.kva = dma_kva;
cee->attr_dma.pa = dma_pa;
cee->stats_dma.kva = dma_kva + bfa_cee_attr_meminfo();
cee->stats_dma.pa = dma_pa + bfa_cee_attr_meminfo();
cee->attr = (struct bfa_cee_attr *) dma_kva;
cee->stats = (struct bfa_cee_stats *)
(dma_kva + bfa_cee_attr_meminfo());
}
static void
bfa_cee_isr(void *cbarg, struct bfi_mbmsg *m)
{
union bfi_cee_i2h_msg_u *msg;
struct bfi_cee_get_rsp *get_rsp;
struct bfa_cee *cee = (struct bfa_cee *) cbarg;
msg = (union bfi_cee_i2h_msg_u *) m;
get_rsp = (struct bfi_cee_get_rsp *) m;
switch (msg->mh.msg_id) {
case BFI_CEE_I2H_GET_CFG_RSP:
bfa_cee_get_attr_isr(cee, get_rsp->cmd_status);
break;
case BFI_CEE_I2H_GET_STATS_RSP:
bfa_cee_get_stats_isr(cee, get_rsp->cmd_status);
break;
case BFI_CEE_I2H_RESET_STATS_RSP:
bfa_cee_reset_stats_isr(cee, get_rsp->cmd_status);
break;
default:
BUG_ON(1);
}
}
static void
bfa_cee_hbfail(void *arg)
{
struct bfa_cee *cee;
cee = (struct bfa_cee *) arg;
if (cee->get_attr_pending == true) {
cee->get_attr_status = BFA_STATUS_FAILED;
cee->get_attr_pending = false;
if (cee->cbfn.get_attr_cbfn) {
cee->cbfn.get_attr_cbfn(cee->cbfn.get_attr_cbarg,
BFA_STATUS_FAILED);
}
}
if (cee->get_stats_pending == true) {
cee->get_stats_status = BFA_STATUS_FAILED;
cee->get_stats_pending = false;
if (cee->cbfn.get_stats_cbfn) {
cee->cbfn.get_stats_cbfn(cee->cbfn.get_stats_cbarg,
BFA_STATUS_FAILED);
}
}
if (cee->reset_stats_pending == true) {
cee->reset_stats_status = BFA_STATUS_FAILED;
cee->reset_stats_pending = false;
if (cee->cbfn.reset_stats_cbfn) {
cee->cbfn.reset_stats_cbfn(cee->cbfn.reset_stats_cbarg,
BFA_STATUS_FAILED);
}
}
}
void
bfa_nw_cee_attach(struct bfa_cee *cee, struct bfa_ioc *ioc,
void *dev)
{
BUG_ON(!(cee != NULL));
cee->dev = dev;
cee->ioc = ioc;
bfa_nw_ioc_mbox_regisr(cee->ioc, BFI_MC_CEE, bfa_cee_isr, cee);
bfa_ioc_hbfail_init(&cee->hbfail, bfa_cee_hbfail, cee);
bfa_nw_ioc_hbfail_register(cee->ioc, &cee->hbfail);
}
