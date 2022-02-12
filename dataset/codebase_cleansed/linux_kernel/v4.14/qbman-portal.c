static inline u32 qbman_read_register(struct qbman_swp *p, u32 offset)
{
return readl_relaxed(p->addr_cinh + offset);
}
static inline void qbman_write_register(struct qbman_swp *p, u32 offset,
u32 value)
{
writel_relaxed(value, p->addr_cinh + offset);
}
static inline void *qbman_get_cmd(struct qbman_swp *p, u32 offset)
{
return p->addr_cena + offset;
}
static inline u32 qbman_set_swp_cfg(u8 max_fill, u8 wn, u8 est, u8 rpm, u8 dcm,
u8 epm, int sd, int sp, int se,
int dp, int de, int ep)
{
return (max_fill << SWP_CFG_DQRR_MF_SHIFT |
est << SWP_CFG_EST_SHIFT |
wn << SWP_CFG_WN_SHIFT |
rpm << SWP_CFG_RPM_SHIFT |
dcm << SWP_CFG_DCM_SHIFT |
epm << SWP_CFG_EPM_SHIFT |
sd << SWP_CFG_SD_SHIFT |
sp << SWP_CFG_SP_SHIFT |
se << SWP_CFG_SE_SHIFT |
dp << SWP_CFG_DP_SHIFT |
de << SWP_CFG_DE_SHIFT |
ep << SWP_CFG_EP_SHIFT);
}
struct qbman_swp *qbman_swp_init(const struct qbman_swp_desc *d)
{
struct qbman_swp *p = kmalloc(sizeof(*p), GFP_KERNEL);
u32 reg;
if (!p)
return NULL;
p->desc = d;
p->mc.valid_bit = QB_VALID_BIT;
p->sdq = 0;
p->sdq |= qbman_sdqcr_dct_prio_ics << QB_SDQCR_DCT_SHIFT;
p->sdq |= qbman_sdqcr_fc_up_to_3 << QB_SDQCR_FC_SHIFT;
p->sdq |= QMAN_SDQCR_TOKEN << QB_SDQCR_TOK_SHIFT;
atomic_set(&p->vdq.available, 1);
p->vdq.valid_bit = QB_VALID_BIT;
p->dqrr.next_idx = 0;
p->dqrr.valid_bit = QB_VALID_BIT;
if ((p->desc->qman_version & QMAN_REV_MASK) < QMAN_REV_4100) {
p->dqrr.dqrr_size = 4;
p->dqrr.reset_bug = 1;
} else {
p->dqrr.dqrr_size = 8;
p->dqrr.reset_bug = 0;
}
p->addr_cena = d->cena_bar;
p->addr_cinh = d->cinh_bar;
reg = qbman_set_swp_cfg(p->dqrr.dqrr_size,
1,
0,
3,
2,
3,
0,
1,
0,
1,
0,
0);
qbman_write_register(p, QBMAN_CINH_SWP_CFG, reg);
reg = qbman_read_register(p, QBMAN_CINH_SWP_CFG);
if (!reg) {
pr_err("qbman: the portal is not enabled!\n");
return NULL;
}
qbman_write_register(p, QBMAN_CINH_SWP_SDQCR, 0);
return p;
}
void qbman_swp_finish(struct qbman_swp *p)
{
kfree(p);
}
u32 qbman_swp_interrupt_read_status(struct qbman_swp *p)
{
return qbman_read_register(p, QBMAN_CINH_SWP_ISR);
}
void qbman_swp_interrupt_clear_status(struct qbman_swp *p, u32 mask)
{
qbman_write_register(p, QBMAN_CINH_SWP_ISR, mask);
}
u32 qbman_swp_interrupt_get_trigger(struct qbman_swp *p)
{
return qbman_read_register(p, QBMAN_CINH_SWP_IER);
}
void qbman_swp_interrupt_set_trigger(struct qbman_swp *p, u32 mask)
{
qbman_write_register(p, QBMAN_CINH_SWP_IER, mask);
}
int qbman_swp_interrupt_get_inhibit(struct qbman_swp *p)
{
return qbman_read_register(p, QBMAN_CINH_SWP_IIR);
}
void qbman_swp_interrupt_set_inhibit(struct qbman_swp *p, int inhibit)
{
qbman_write_register(p, QBMAN_CINH_SWP_IIR, inhibit ? 0xffffffff : 0);
}
void *qbman_swp_mc_start(struct qbman_swp *p)
{
return qbman_get_cmd(p, QBMAN_CENA_SWP_CR);
}
void qbman_swp_mc_submit(struct qbman_swp *p, void *cmd, u8 cmd_verb)
{
u8 *v = cmd;
dma_wmb();
*v = cmd_verb | p->mc.valid_bit;
}
void *qbman_swp_mc_result(struct qbman_swp *p)
{
u32 *ret, verb;
ret = qbman_get_cmd(p, QBMAN_CENA_SWP_RR(p->mc.valid_bit));
verb = ret[0] & ~QB_VALID_BIT;
if (!verb)
return NULL;
p->mc.valid_bit ^= QB_VALID_BIT;
return ret;
}
void qbman_eq_desc_clear(struct qbman_eq_desc *d)
{
memset(d, 0, sizeof(*d));
}
void qbman_eq_desc_set_no_orp(struct qbman_eq_desc *d, int respond_success)
{
d->verb &= ~(1 << QB_ENQUEUE_CMD_ORP_ENABLE_SHIFT);
if (respond_success)
d->verb |= enqueue_response_always;
else
d->verb |= enqueue_rejects_to_fq;
}
void qbman_eq_desc_set_fq(struct qbman_eq_desc *d, u32 fqid)
{
d->verb &= ~(1 << QB_ENQUEUE_CMD_TARGET_TYPE_SHIFT);
d->tgtid = cpu_to_le32(fqid);
}
void qbman_eq_desc_set_qd(struct qbman_eq_desc *d, u32 qdid,
u32 qd_bin, u32 qd_prio)
{
d->verb |= 1 << QB_ENQUEUE_CMD_TARGET_TYPE_SHIFT;
d->tgtid = cpu_to_le32(qdid);
d->qdbin = cpu_to_le16(qd_bin);
d->qpri = qd_prio;
}
int qbman_swp_enqueue(struct qbman_swp *s, const struct qbman_eq_desc *d,
const struct dpaa2_fd *fd)
{
struct qbman_eq_desc *p;
u32 eqar = qbman_read_register(s, QBMAN_CINH_SWP_EQAR);
if (!EQAR_SUCCESS(eqar))
return -EBUSY;
p = qbman_get_cmd(s, QBMAN_CENA_SWP_EQCR(EQAR_IDX(eqar)));
memcpy(&p->dca, &d->dca, 31);
memcpy(&p->fd, fd, sizeof(*fd));
dma_wmb();
p->verb = d->verb | EQAR_VB(eqar);
return 0;
}
void qbman_swp_push_get(struct qbman_swp *s, u8 channel_idx, int *enabled)
{
u16 src = (s->sdq >> QB_SDQCR_SRC_SHIFT) & QB_SDQCR_SRC_MASK;
WARN_ON(channel_idx > 15);
*enabled = src | (1 << channel_idx);
}
void qbman_swp_push_set(struct qbman_swp *s, u8 channel_idx, int enable)
{
u16 dqsrc;
WARN_ON(channel_idx > 15);
if (enable)
s->sdq |= 1 << channel_idx;
else
s->sdq &= ~(1 << channel_idx);
dqsrc = (s->sdq >> QB_SDQCR_SRC_SHIFT) & QB_SDQCR_SRC_MASK;
if (dqsrc != 0)
qbman_write_register(s, QBMAN_CINH_SWP_SDQCR, s->sdq);
else
qbman_write_register(s, QBMAN_CINH_SWP_SDQCR, 0);
}
void qbman_pull_desc_clear(struct qbman_pull_desc *d)
{
memset(d, 0, sizeof(*d));
}
void qbman_pull_desc_set_storage(struct qbman_pull_desc *d,
struct dpaa2_dq *storage,
dma_addr_t storage_phys,
int stash)
{
d->rsp_addr_virt = (u64)storage;
if (!storage) {
d->verb &= ~(1 << QB_VDQCR_VERB_RLS_SHIFT);
return;
}
d->verb |= 1 << QB_VDQCR_VERB_RLS_SHIFT;
if (stash)
d->verb |= 1 << QB_VDQCR_VERB_WAE_SHIFT;
else
d->verb &= ~(1 << QB_VDQCR_VERB_WAE_SHIFT);
d->rsp_addr = cpu_to_le64(storage_phys);
}
void qbman_pull_desc_set_numframes(struct qbman_pull_desc *d, u8 numframes)
{
d->numf = numframes - 1;
}
void qbman_pull_desc_set_token(struct qbman_pull_desc *d, u8 token)
{
d->tok = token;
}
void qbman_pull_desc_set_fq(struct qbman_pull_desc *d, u32 fqid)
{
d->verb |= 1 << QB_VDQCR_VERB_DCT_SHIFT;
d->verb |= qb_pull_dt_framequeue << QB_VDQCR_VERB_DT_SHIFT;
d->dq_src = cpu_to_le32(fqid);
}
void qbman_pull_desc_set_wq(struct qbman_pull_desc *d, u32 wqid,
enum qbman_pull_type_e dct)
{
d->verb |= dct << QB_VDQCR_VERB_DCT_SHIFT;
d->verb |= qb_pull_dt_workqueue << QB_VDQCR_VERB_DT_SHIFT;
d->dq_src = cpu_to_le32(wqid);
}
void qbman_pull_desc_set_channel(struct qbman_pull_desc *d, u32 chid,
enum qbman_pull_type_e dct)
{
d->verb |= dct << QB_VDQCR_VERB_DCT_SHIFT;
d->verb |= qb_pull_dt_channel << QB_VDQCR_VERB_DT_SHIFT;
d->dq_src = cpu_to_le32(chid);
}
int qbman_swp_pull(struct qbman_swp *s, struct qbman_pull_desc *d)
{
struct qbman_pull_desc *p;
if (!atomic_dec_and_test(&s->vdq.available)) {
atomic_inc(&s->vdq.available);
return -EBUSY;
}
s->vdq.storage = (void *)d->rsp_addr_virt;
p = qbman_get_cmd(s, QBMAN_CENA_SWP_VDQCR);
p->numf = d->numf;
p->tok = QMAN_DQ_TOKEN_VALID;
p->dq_src = d->dq_src;
p->rsp_addr = d->rsp_addr;
p->rsp_addr_virt = d->rsp_addr_virt;
dma_wmb();
p->verb = d->verb | s->vdq.valid_bit;
s->vdq.valid_bit ^= QB_VALID_BIT;
return 0;
}
const struct dpaa2_dq *qbman_swp_dqrr_next(struct qbman_swp *s)
{
u32 verb;
u32 response_verb;
u32 flags;
struct dpaa2_dq *p;
if (unlikely(s->dqrr.reset_bug)) {
u8 pi = qbman_read_register(s, QBMAN_CINH_SWP_DQPI) &
QMAN_DQRR_PI_MASK;
if (pi == s->dqrr.next_idx)
return NULL;
if (s->dqrr.next_idx == (s->dqrr.dqrr_size - 1)) {
pr_debug("next_idx=%d, pi=%d, clear reset bug\n",
s->dqrr.next_idx, pi);
s->dqrr.reset_bug = 0;
}
prefetch(qbman_get_cmd(s,
QBMAN_CENA_SWP_DQRR(s->dqrr.next_idx)));
}
p = qbman_get_cmd(s, QBMAN_CENA_SWP_DQRR(s->dqrr.next_idx));
verb = p->dq.verb;
if ((verb & QB_VALID_BIT) != s->dqrr.valid_bit) {
prefetch(qbman_get_cmd(s,
QBMAN_CENA_SWP_DQRR(s->dqrr.next_idx)));
return NULL;
}
s->dqrr.next_idx++;
s->dqrr.next_idx &= s->dqrr.dqrr_size - 1;
if (!s->dqrr.next_idx)
s->dqrr.valid_bit ^= QB_VALID_BIT;
flags = p->dq.stat;
response_verb = verb & QBMAN_RESULT_MASK;
if ((response_verb == QBMAN_RESULT_DQ) &&
(flags & DPAA2_DQ_STAT_VOLATILE) &&
(flags & DPAA2_DQ_STAT_EXPIRED))
atomic_inc(&s->vdq.available);
prefetch(qbman_get_cmd(s, QBMAN_CENA_SWP_DQRR(s->dqrr.next_idx)));
return p;
}
void qbman_swp_dqrr_consume(struct qbman_swp *s, const struct dpaa2_dq *dq)
{
qbman_write_register(s, QBMAN_CINH_SWP_DCAP, QBMAN_IDX_FROM_DQRR(dq));
}
int qbman_result_has_new_result(struct qbman_swp *s, const struct dpaa2_dq *dq)
{
if (dq->dq.tok != QMAN_DQ_TOKEN_VALID)
return 0;
((struct dpaa2_dq *)dq)->dq.tok = 0;
if (s->vdq.storage == dq) {
s->vdq.storage = NULL;
atomic_inc(&s->vdq.available);
}
return 1;
}
void qbman_release_desc_clear(struct qbman_release_desc *d)
{
memset(d, 0, sizeof(*d));
d->verb = 1 << 5;
}
void qbman_release_desc_set_bpid(struct qbman_release_desc *d, u16 bpid)
{
d->bpid = cpu_to_le16(bpid);
}
void qbman_release_desc_set_rcdi(struct qbman_release_desc *d, int enable)
{
if (enable)
d->verb |= 1 << 6;
else
d->verb &= ~(1 << 6);
}
int qbman_swp_release(struct qbman_swp *s, const struct qbman_release_desc *d,
const u64 *buffers, unsigned int num_buffers)
{
int i;
struct qbman_release_desc *p;
u32 rar;
if (!num_buffers || (num_buffers > 7))
return -EINVAL;
rar = qbman_read_register(s, QBMAN_CINH_SWP_RAR);
if (!RAR_SUCCESS(rar))
return -EBUSY;
p = qbman_get_cmd(s, QBMAN_CENA_SWP_RCR(RAR_IDX(rar)));
for (i = 0; i < num_buffers; i++)
p->buf[i] = cpu_to_le64(buffers[i]);
p->bpid = d->bpid;
dma_wmb();
p->verb = d->verb | RAR_VB(rar) | num_buffers;
return 0;
}
int qbman_swp_acquire(struct qbman_swp *s, u16 bpid, u64 *buffers,
unsigned int num_buffers)
{
struct qbman_acquire_desc *p;
struct qbman_acquire_rslt *r;
int i;
if (!num_buffers || (num_buffers > 7))
return -EINVAL;
p = qbman_swp_mc_start(s);
if (!p)
return -EBUSY;
p->bpid = cpu_to_le16(bpid);
p->num = num_buffers;
r = qbman_swp_mc_complete(s, p, QBMAN_MC_ACQUIRE);
if (unlikely(!r)) {
pr_err("qbman: acquire from BPID %d failed, no response\n",
bpid);
return -EIO;
}
WARN_ON((r->verb & 0x7f) != QBMAN_MC_ACQUIRE);
if (unlikely(r->rslt != QBMAN_MC_RSLT_OK)) {
pr_err("qbman: acquire from BPID 0x%x failed, code=0x%02x\n",
bpid, r->rslt);
return -EIO;
}
WARN_ON(r->num > num_buffers);
for (i = 0; i < r->num; i++)
buffers[i] = le64_to_cpu(r->buf[i]);
return (int)r->num;
}
int qbman_swp_alt_fq_state(struct qbman_swp *s, u32 fqid,
u8 alt_fq_verb)
{
struct qbman_alt_fq_state_desc *p;
struct qbman_alt_fq_state_rslt *r;
p = qbman_swp_mc_start(s);
if (!p)
return -EBUSY;
p->fqid = cpu_to_le32(fqid) & ALT_FQ_FQID_MASK;
r = qbman_swp_mc_complete(s, p, alt_fq_verb);
if (unlikely(!r)) {
pr_err("qbman: mgmt cmd failed, no response (verb=0x%x)\n",
alt_fq_verb);
return -EIO;
}
WARN_ON((r->verb & QBMAN_RESULT_MASK) != alt_fq_verb);
if (unlikely(r->rslt != QBMAN_MC_RSLT_OK)) {
pr_err("qbman: ALT FQID %d failed: verb = 0x%08x code = 0x%02x\n",
fqid, r->verb, r->rslt);
return -EIO;
}
return 0;
}
int qbman_swp_CDAN_set(struct qbman_swp *s, u16 channelid,
u8 we_mask, u8 cdan_en,
u64 ctx)
{
struct qbman_cdan_ctrl_desc *p = NULL;
struct qbman_cdan_ctrl_rslt *r = NULL;
p = qbman_swp_mc_start(s);
if (!p)
return -EBUSY;
p->ch = cpu_to_le16(channelid);
p->we = we_mask;
if (cdan_en)
p->ctrl = 1;
else
p->ctrl = 0;
p->cdan_ctx = cpu_to_le64(ctx);
r = qbman_swp_mc_complete(s, p, QBMAN_WQCHAN_CONFIGURE);
if (unlikely(!r)) {
pr_err("qbman: wqchan config failed, no response\n");
return -EIO;
}
WARN_ON((r->verb & 0x7f) != QBMAN_WQCHAN_CONFIGURE);
if (unlikely(r->rslt != QBMAN_MC_RSLT_OK)) {
pr_err("qbman: CDAN cQID %d failed: code = 0x%02x\n",
channelid, r->rslt);
return -EIO;
}
return 0;
}
