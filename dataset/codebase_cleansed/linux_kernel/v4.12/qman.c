static inline u32 qm_in(struct qm_portal *p, u32 offset)
{
return be32_to_cpu(__raw_readl(p->addr.ci + offset));
}
static inline void qm_out(struct qm_portal *p, u32 offset, u32 val)
{
__raw_writel(cpu_to_be32(val), p->addr.ci + offset);
}
static inline void qm_cl_invalidate(struct qm_portal *p, u32 offset)
{
dpaa_invalidate(p->addr.ce + offset);
}
static inline void qm_cl_touch_ro(struct qm_portal *p, u32 offset)
{
dpaa_touch_ro(p->addr.ce + offset);
}
static inline u32 qm_ce_in(struct qm_portal *p, u32 offset)
{
return be32_to_cpu(__raw_readl(p->addr.ce + offset));
}
static struct qm_eqcr_entry *eqcr_carryclear(struct qm_eqcr_entry *p)
{
uintptr_t addr = (uintptr_t)p;
addr &= ~EQCR_CARRY;
return (struct qm_eqcr_entry *)addr;
}
static int eqcr_ptr2idx(struct qm_eqcr_entry *e)
{
return ((uintptr_t)e >> EQCR_SHIFT) & (QM_EQCR_SIZE - 1);
}
static inline void eqcr_inc(struct qm_eqcr *eqcr)
{
struct qm_eqcr_entry *partial = eqcr->cursor + 1;
eqcr->cursor = eqcr_carryclear(partial);
if (partial != eqcr->cursor)
eqcr->vbit ^= QM_EQCR_VERB_VBIT;
}
static inline int qm_eqcr_init(struct qm_portal *portal,
enum qm_eqcr_pmode pmode,
unsigned int eq_stash_thresh,
int eq_stash_prio)
{
struct qm_eqcr *eqcr = &portal->eqcr;
u32 cfg;
u8 pi;
eqcr->ring = portal->addr.ce + QM_CL_EQCR;
eqcr->ci = qm_in(portal, QM_REG_EQCR_CI_CINH) & (QM_EQCR_SIZE - 1);
qm_cl_invalidate(portal, QM_CL_EQCR_CI_CENA);
pi = qm_in(portal, QM_REG_EQCR_PI_CINH) & (QM_EQCR_SIZE - 1);
eqcr->cursor = eqcr->ring + pi;
eqcr->vbit = (qm_in(portal, QM_REG_EQCR_PI_CINH) & QM_EQCR_SIZE) ?
QM_EQCR_VERB_VBIT : 0;
eqcr->available = QM_EQCR_SIZE - 1 -
dpaa_cyc_diff(QM_EQCR_SIZE, eqcr->ci, pi);
eqcr->ithresh = qm_in(portal, QM_REG_EQCR_ITR);
#ifdef CONFIG_FSL_DPAA_CHECKING
eqcr->busy = 0;
eqcr->pmode = pmode;
#endif
cfg = (qm_in(portal, QM_REG_CFG) & 0x00ffffff) |
(eq_stash_thresh << 28) |
(eq_stash_prio << 26) |
((pmode & 0x3) << 24);
qm_out(portal, QM_REG_CFG, cfg);
return 0;
}
static inline unsigned int qm_eqcr_get_ci_stashing(struct qm_portal *portal)
{
return (qm_in(portal, QM_REG_CFG) >> 28) & 0x7;
}
static inline void qm_eqcr_finish(struct qm_portal *portal)
{
struct qm_eqcr *eqcr = &portal->eqcr;
u8 pi = qm_in(portal, QM_REG_EQCR_PI_CINH) & (QM_EQCR_SIZE - 1);
u8 ci = qm_in(portal, QM_REG_EQCR_CI_CINH) & (QM_EQCR_SIZE - 1);
DPAA_ASSERT(!eqcr->busy);
if (pi != eqcr_ptr2idx(eqcr->cursor))
pr_crit("losing uncommitted EQCR entries\n");
if (ci != eqcr->ci)
pr_crit("missing existing EQCR completions\n");
if (eqcr->ci != eqcr_ptr2idx(eqcr->cursor))
pr_crit("EQCR destroyed unquiesced\n");
}
static inline struct qm_eqcr_entry *qm_eqcr_start_no_stash(struct qm_portal
*portal)
{
struct qm_eqcr *eqcr = &portal->eqcr;
DPAA_ASSERT(!eqcr->busy);
if (!eqcr->available)
return NULL;
#ifdef CONFIG_FSL_DPAA_CHECKING
eqcr->busy = 1;
#endif
dpaa_zero(eqcr->cursor);
return eqcr->cursor;
}
static inline struct qm_eqcr_entry *qm_eqcr_start_stash(struct qm_portal
*portal)
{
struct qm_eqcr *eqcr = &portal->eqcr;
u8 diff, old_ci;
DPAA_ASSERT(!eqcr->busy);
if (!eqcr->available) {
old_ci = eqcr->ci;
eqcr->ci = qm_ce_in(portal, QM_CL_EQCR_CI_CENA) &
(QM_EQCR_SIZE - 1);
diff = dpaa_cyc_diff(QM_EQCR_SIZE, old_ci, eqcr->ci);
eqcr->available += diff;
if (!diff)
return NULL;
}
#ifdef CONFIG_FSL_DPAA_CHECKING
eqcr->busy = 1;
#endif
dpaa_zero(eqcr->cursor);
return eqcr->cursor;
}
static inline void eqcr_commit_checks(struct qm_eqcr *eqcr)
{
DPAA_ASSERT(eqcr->busy);
DPAA_ASSERT(!(be32_to_cpu(eqcr->cursor->fqid) & ~QM_FQID_MASK));
DPAA_ASSERT(eqcr->available >= 1);
}
static inline void qm_eqcr_pvb_commit(struct qm_portal *portal, u8 myverb)
{
struct qm_eqcr *eqcr = &portal->eqcr;
struct qm_eqcr_entry *eqcursor;
eqcr_commit_checks(eqcr);
DPAA_ASSERT(eqcr->pmode == qm_eqcr_pvb);
dma_wmb();
eqcursor = eqcr->cursor;
eqcursor->_ncw_verb = myverb | eqcr->vbit;
dpaa_flush(eqcursor);
eqcr_inc(eqcr);
eqcr->available--;
#ifdef CONFIG_FSL_DPAA_CHECKING
eqcr->busy = 0;
#endif
}
static inline void qm_eqcr_cce_prefetch(struct qm_portal *portal)
{
qm_cl_touch_ro(portal, QM_CL_EQCR_CI_CENA);
}
static inline u8 qm_eqcr_cce_update(struct qm_portal *portal)
{
struct qm_eqcr *eqcr = &portal->eqcr;
u8 diff, old_ci = eqcr->ci;
eqcr->ci = qm_ce_in(portal, QM_CL_EQCR_CI_CENA) & (QM_EQCR_SIZE - 1);
qm_cl_invalidate(portal, QM_CL_EQCR_CI_CENA);
diff = dpaa_cyc_diff(QM_EQCR_SIZE, old_ci, eqcr->ci);
eqcr->available += diff;
return diff;
}
static inline void qm_eqcr_set_ithresh(struct qm_portal *portal, u8 ithresh)
{
struct qm_eqcr *eqcr = &portal->eqcr;
eqcr->ithresh = ithresh;
qm_out(portal, QM_REG_EQCR_ITR, ithresh);
}
static inline u8 qm_eqcr_get_avail(struct qm_portal *portal)
{
struct qm_eqcr *eqcr = &portal->eqcr;
return eqcr->available;
}
static inline u8 qm_eqcr_get_fill(struct qm_portal *portal)
{
struct qm_eqcr *eqcr = &portal->eqcr;
return QM_EQCR_SIZE - 1 - eqcr->available;
}
static const struct qm_dqrr_entry *dqrr_carryclear(
const struct qm_dqrr_entry *p)
{
uintptr_t addr = (uintptr_t)p;
addr &= ~DQRR_CARRY;
return (const struct qm_dqrr_entry *)addr;
}
static inline int dqrr_ptr2idx(const struct qm_dqrr_entry *e)
{
return ((uintptr_t)e >> DQRR_SHIFT) & (QM_DQRR_SIZE - 1);
}
static const struct qm_dqrr_entry *dqrr_inc(const struct qm_dqrr_entry *e)
{
return dqrr_carryclear(e + 1);
}
static inline void qm_dqrr_set_maxfill(struct qm_portal *portal, u8 mf)
{
qm_out(portal, QM_REG_CFG, (qm_in(portal, QM_REG_CFG) & 0xff0fffff) |
((mf & (QM_DQRR_SIZE - 1)) << 20));
}
static inline int qm_dqrr_init(struct qm_portal *portal,
const struct qm_portal_config *config,
enum qm_dqrr_dmode dmode,
enum qm_dqrr_pmode pmode,
enum qm_dqrr_cmode cmode, u8 max_fill)
{
struct qm_dqrr *dqrr = &portal->dqrr;
u32 cfg;
qm_out(portal, QM_REG_DQRR_SDQCR, 0);
qm_out(portal, QM_REG_DQRR_VDQCR, 0);
qm_out(portal, QM_REG_DQRR_PDQCR, 0);
dqrr->ring = portal->addr.ce + QM_CL_DQRR;
dqrr->pi = qm_in(portal, QM_REG_DQRR_PI_CINH) & (QM_DQRR_SIZE - 1);
dqrr->ci = qm_in(portal, QM_REG_DQRR_CI_CINH) & (QM_DQRR_SIZE - 1);
dqrr->cursor = dqrr->ring + dqrr->ci;
dqrr->fill = dpaa_cyc_diff(QM_DQRR_SIZE, dqrr->ci, dqrr->pi);
dqrr->vbit = (qm_in(portal, QM_REG_DQRR_PI_CINH) & QM_DQRR_SIZE) ?
QM_DQRR_VERB_VBIT : 0;
dqrr->ithresh = qm_in(portal, QM_REG_DQRR_ITR);
#ifdef CONFIG_FSL_DPAA_CHECKING
dqrr->dmode = dmode;
dqrr->pmode = pmode;
dqrr->cmode = cmode;
#endif
for (cfg = 0; cfg < QM_DQRR_SIZE; cfg++)
dpaa_invalidate(qm_cl(dqrr->ring, cfg));
cfg = (qm_in(portal, QM_REG_CFG) & 0xff000f00) |
((max_fill & (QM_DQRR_SIZE - 1)) << 20) |
((dmode & 1) << 18) |
((cmode & 3) << 16) |
0xa0 |
(0 ? 0x40 : 0) |
(0 ? 0x10 : 0);
qm_out(portal, QM_REG_CFG, cfg);
qm_dqrr_set_maxfill(portal, max_fill);
return 0;
}
static inline void qm_dqrr_finish(struct qm_portal *portal)
{
#ifdef CONFIG_FSL_DPAA_CHECKING
struct qm_dqrr *dqrr = &portal->dqrr;
if (dqrr->cmode != qm_dqrr_cdc &&
dqrr->ci != dqrr_ptr2idx(dqrr->cursor))
pr_crit("Ignoring completed DQRR entries\n");
#endif
}
static inline const struct qm_dqrr_entry *qm_dqrr_current(
struct qm_portal *portal)
{
struct qm_dqrr *dqrr = &portal->dqrr;
if (!dqrr->fill)
return NULL;
return dqrr->cursor;
}
static inline u8 qm_dqrr_next(struct qm_portal *portal)
{
struct qm_dqrr *dqrr = &portal->dqrr;
DPAA_ASSERT(dqrr->fill);
dqrr->cursor = dqrr_inc(dqrr->cursor);
return --dqrr->fill;
}
static inline void qm_dqrr_pvb_update(struct qm_portal *portal)
{
struct qm_dqrr *dqrr = &portal->dqrr;
struct qm_dqrr_entry *res = qm_cl(dqrr->ring, dqrr->pi);
DPAA_ASSERT(dqrr->pmode == qm_dqrr_pvb);
#ifndef CONFIG_FSL_PAMU
dpaa_invalidate_touch_ro(res);
#endif
if ((__raw_readb(&res->verb) & QM_DQRR_VERB_VBIT) == dqrr->vbit) {
dqrr->pi = (dqrr->pi + 1) & (QM_DQRR_SIZE - 1);
if (!dqrr->pi)
dqrr->vbit ^= QM_DQRR_VERB_VBIT;
dqrr->fill++;
}
}
static inline void qm_dqrr_cdc_consume_1ptr(struct qm_portal *portal,
const struct qm_dqrr_entry *dq,
int park)
{
__maybe_unused struct qm_dqrr *dqrr = &portal->dqrr;
int idx = dqrr_ptr2idx(dq);
DPAA_ASSERT(dqrr->cmode == qm_dqrr_cdc);
DPAA_ASSERT((dqrr->ring + idx) == dq);
DPAA_ASSERT(idx < QM_DQRR_SIZE);
qm_out(portal, QM_REG_DQRR_DCAP, (0 << 8) |
((park ? 1 : 0) << 6) |
idx);
}
static inline void qm_dqrr_cdc_consume_n(struct qm_portal *portal, u32 bitmask)
{
__maybe_unused struct qm_dqrr *dqrr = &portal->dqrr;
DPAA_ASSERT(dqrr->cmode == qm_dqrr_cdc);
qm_out(portal, QM_REG_DQRR_DCAP, (1 << 8) |
(bitmask << 16));
}
static inline void qm_dqrr_sdqcr_set(struct qm_portal *portal, u32 sdqcr)
{
qm_out(portal, QM_REG_DQRR_SDQCR, sdqcr);
}
static inline void qm_dqrr_vdqcr_set(struct qm_portal *portal, u32 vdqcr)
{
qm_out(portal, QM_REG_DQRR_VDQCR, vdqcr);
}
static inline void qm_dqrr_set_ithresh(struct qm_portal *portal, u8 ithresh)
{
qm_out(portal, QM_REG_DQRR_ITR, ithresh);
}
static union qm_mr_entry *mr_carryclear(union qm_mr_entry *p)
{
uintptr_t addr = (uintptr_t)p;
addr &= ~MR_CARRY;
return (union qm_mr_entry *)addr;
}
static inline int mr_ptr2idx(const union qm_mr_entry *e)
{
return ((uintptr_t)e >> MR_SHIFT) & (QM_MR_SIZE - 1);
}
static inline union qm_mr_entry *mr_inc(union qm_mr_entry *e)
{
return mr_carryclear(e + 1);
}
static inline int qm_mr_init(struct qm_portal *portal, enum qm_mr_pmode pmode,
enum qm_mr_cmode cmode)
{
struct qm_mr *mr = &portal->mr;
u32 cfg;
mr->ring = portal->addr.ce + QM_CL_MR;
mr->pi = qm_in(portal, QM_REG_MR_PI_CINH) & (QM_MR_SIZE - 1);
mr->ci = qm_in(portal, QM_REG_MR_CI_CINH) & (QM_MR_SIZE - 1);
mr->cursor = mr->ring + mr->ci;
mr->fill = dpaa_cyc_diff(QM_MR_SIZE, mr->ci, mr->pi);
mr->vbit = (qm_in(portal, QM_REG_MR_PI_CINH) & QM_MR_SIZE)
? QM_MR_VERB_VBIT : 0;
mr->ithresh = qm_in(portal, QM_REG_MR_ITR);
#ifdef CONFIG_FSL_DPAA_CHECKING
mr->pmode = pmode;
mr->cmode = cmode;
#endif
cfg = (qm_in(portal, QM_REG_CFG) & 0xfffff0ff) |
((cmode & 1) << 8);
qm_out(portal, QM_REG_CFG, cfg);
return 0;
}
static inline void qm_mr_finish(struct qm_portal *portal)
{
struct qm_mr *mr = &portal->mr;
if (mr->ci != mr_ptr2idx(mr->cursor))
pr_crit("Ignoring completed MR entries\n");
}
static inline const union qm_mr_entry *qm_mr_current(struct qm_portal *portal)
{
struct qm_mr *mr = &portal->mr;
if (!mr->fill)
return NULL;
return mr->cursor;
}
static inline int qm_mr_next(struct qm_portal *portal)
{
struct qm_mr *mr = &portal->mr;
DPAA_ASSERT(mr->fill);
mr->cursor = mr_inc(mr->cursor);
return --mr->fill;
}
static inline void qm_mr_pvb_update(struct qm_portal *portal)
{
struct qm_mr *mr = &portal->mr;
union qm_mr_entry *res = qm_cl(mr->ring, mr->pi);
DPAA_ASSERT(mr->pmode == qm_mr_pvb);
if ((__raw_readb(&res->verb) & QM_MR_VERB_VBIT) == mr->vbit) {
mr->pi = (mr->pi + 1) & (QM_MR_SIZE - 1);
if (!mr->pi)
mr->vbit ^= QM_MR_VERB_VBIT;
mr->fill++;
res = mr_inc(res);
}
dpaa_invalidate_touch_ro(res);
}
static inline void qm_mr_cci_consume(struct qm_portal *portal, u8 num)
{
struct qm_mr *mr = &portal->mr;
DPAA_ASSERT(mr->cmode == qm_mr_cci);
mr->ci = (mr->ci + num) & (QM_MR_SIZE - 1);
qm_out(portal, QM_REG_MR_CI_CINH, mr->ci);
}
static inline void qm_mr_cci_consume_to_current(struct qm_portal *portal)
{
struct qm_mr *mr = &portal->mr;
DPAA_ASSERT(mr->cmode == qm_mr_cci);
mr->ci = mr_ptr2idx(mr->cursor);
qm_out(portal, QM_REG_MR_CI_CINH, mr->ci);
}
static inline void qm_mr_set_ithresh(struct qm_portal *portal, u8 ithresh)
{
qm_out(portal, QM_REG_MR_ITR, ithresh);
}
static inline int qm_mc_init(struct qm_portal *portal)
{
struct qm_mc *mc = &portal->mc;
mc->cr = portal->addr.ce + QM_CL_CR;
mc->rr = portal->addr.ce + QM_CL_RR0;
mc->rridx = (__raw_readb(&mc->cr->_ncw_verb) & QM_MCC_VERB_VBIT)
? 0 : 1;
mc->vbit = mc->rridx ? QM_MCC_VERB_VBIT : 0;
#ifdef CONFIG_FSL_DPAA_CHECKING
mc->state = qman_mc_idle;
#endif
return 0;
}
static inline void qm_mc_finish(struct qm_portal *portal)
{
#ifdef CONFIG_FSL_DPAA_CHECKING
struct qm_mc *mc = &portal->mc;
DPAA_ASSERT(mc->state == qman_mc_idle);
if (mc->state != qman_mc_idle)
pr_crit("Losing incomplete MC command\n");
#endif
}
static inline union qm_mc_command *qm_mc_start(struct qm_portal *portal)
{
struct qm_mc *mc = &portal->mc;
DPAA_ASSERT(mc->state == qman_mc_idle);
#ifdef CONFIG_FSL_DPAA_CHECKING
mc->state = qman_mc_user;
#endif
dpaa_zero(mc->cr);
return mc->cr;
}
static inline void qm_mc_commit(struct qm_portal *portal, u8 myverb)
{
struct qm_mc *mc = &portal->mc;
union qm_mc_result *rr = mc->rr + mc->rridx;
DPAA_ASSERT(mc->state == qman_mc_user);
dma_wmb();
mc->cr->_ncw_verb = myverb | mc->vbit;
dpaa_flush(mc->cr);
dpaa_invalidate_touch_ro(rr);
#ifdef CONFIG_FSL_DPAA_CHECKING
mc->state = qman_mc_hw;
#endif
}
static inline union qm_mc_result *qm_mc_result(struct qm_portal *portal)
{
struct qm_mc *mc = &portal->mc;
union qm_mc_result *rr = mc->rr + mc->rridx;
DPAA_ASSERT(mc->state == qman_mc_hw);
if (!__raw_readb(&rr->verb)) {
dpaa_invalidate_touch_ro(rr);
return NULL;
}
mc->rridx ^= 1;
mc->vbit ^= QM_MCC_VERB_VBIT;
#ifdef CONFIG_FSL_DPAA_CHECKING
mc->state = qman_mc_idle;
#endif
return rr;
}
static inline int qm_mc_result_timeout(struct qm_portal *portal,
union qm_mc_result **mcr)
{
int timeout = QM_MCR_TIMEOUT;
do {
*mcr = qm_mc_result(portal);
if (*mcr)
break;
udelay(1);
} while (--timeout);
return timeout;
}
static inline void fq_set(struct qman_fq *fq, u32 mask)
{
set_bits(mask, &fq->flags);
}
static inline void fq_clear(struct qman_fq *fq, u32 mask)
{
clear_bits(mask, &fq->flags);
}
static inline int fq_isset(struct qman_fq *fq, u32 mask)
{
return fq->flags & mask;
}
static inline int fq_isclear(struct qman_fq *fq, u32 mask)
{
return !(fq->flags & mask);
}
static inline struct qman_portal *get_affine_portal(void)
{
return &get_cpu_var(qman_affine_portal);
}
static inline void put_affine_portal(void)
{
put_cpu_var(qman_affine_portal);
}
int qman_wq_alloc(void)
{
qm_portal_wq = alloc_workqueue("qman_portal_wq", 0, 1);
if (!qm_portal_wq)
return -ENOMEM;
return 0;
}
int qman_alloc_fq_table(u32 _num_fqids)
{
num_fqids = _num_fqids;
fq_table = vzalloc(num_fqids * 2 * sizeof(struct qman_fq *));
if (!fq_table)
return -ENOMEM;
pr_debug("Allocated fq lookup table at %p, entry count %u\n",
fq_table, num_fqids * 2);
return 0;
}
static struct qman_fq *idx_to_fq(u32 idx)
{
struct qman_fq *fq;
#ifdef CONFIG_FSL_DPAA_CHECKING
if (WARN_ON(idx >= num_fqids * 2))
return NULL;
#endif
fq = fq_table[idx];
DPAA_ASSERT(!fq || idx == fq->idx);
return fq;
}
static struct qman_fq *fqid_to_fq(u32 fqid)
{
return idx_to_fq(fqid * 2);
}
static struct qman_fq *tag_to_fq(u32 tag)
{
#if BITS_PER_LONG == 64
return idx_to_fq(tag);
#else
return (struct qman_fq *)tag;
#endif
}
static u32 fq_to_tag(struct qman_fq *fq)
{
#if BITS_PER_LONG == 64
return fq->idx;
#else
return (u32)fq;
#endif
}
static irqreturn_t portal_isr(int irq, void *ptr)
{
struct qman_portal *p = ptr;
u32 clear = QM_DQAVAIL_MASK | p->irq_sources;
u32 is = qm_in(&p->p, QM_REG_ISR) & p->irq_sources;
if (unlikely(!is))
return IRQ_NONE;
if (is & QM_PIRQ_DQRI)
__poll_portal_fast(p, QMAN_POLL_LIMIT);
clear |= __poll_portal_slow(p, is);
qm_out(&p->p, QM_REG_ISR, clear);
return IRQ_HANDLED;
}
static int drain_mr_fqrni(struct qm_portal *p)
{
const union qm_mr_entry *msg;
loop:
msg = qm_mr_current(p);
if (!msg) {
u64 now, then = jiffies;
do {
now = jiffies;
} while ((then + 10000) > now);
msg = qm_mr_current(p);
if (!msg)
return 0;
}
if ((msg->verb & QM_MR_VERB_TYPE_MASK) != QM_MR_VERB_FQRNI) {
pr_err("Found verb 0x%x in MR\n", msg->verb);
return -1;
}
qm_mr_next(p);
qm_mr_cci_consume(p, 1);
goto loop;
}
static int qman_create_portal(struct qman_portal *portal,
const struct qm_portal_config *c,
const struct qman_cgrs *cgrs)
{
struct qm_portal *p;
int ret;
u32 isdr;
p = &portal->p;
#ifdef CONFIG_FSL_PAMU
portal->use_eqcr_ci_stashing = ((qman_ip_rev >= QMAN_REV30) ? 1 : 0);
#else
portal->use_eqcr_ci_stashing = 0;
#endif
p->addr.ce = c->addr_virt[DPAA_PORTAL_CE];
p->addr.ci = c->addr_virt[DPAA_PORTAL_CI];
if (qm_eqcr_init(p, qm_eqcr_pvb,
portal->use_eqcr_ci_stashing ? 3 : 0, 1)) {
dev_err(c->dev, "EQCR initialisation failed\n");
goto fail_eqcr;
}
if (qm_dqrr_init(p, c, qm_dqrr_dpush, qm_dqrr_pvb,
qm_dqrr_cdc, DQRR_MAXFILL)) {
dev_err(c->dev, "DQRR initialisation failed\n");
goto fail_dqrr;
}
if (qm_mr_init(p, qm_mr_pvb, qm_mr_cci)) {
dev_err(c->dev, "MR initialisation failed\n");
goto fail_mr;
}
if (qm_mc_init(p)) {
dev_err(c->dev, "MC initialisation failed\n");
goto fail_mc;
}
qm_dqrr_set_ithresh(p, QMAN_PIRQ_DQRR_ITHRESH);
qm_mr_set_ithresh(p, QMAN_PIRQ_MR_ITHRESH);
qm_out(p, QM_REG_ITPR, QMAN_PIRQ_IPERIOD);
portal->cgrs = kmalloc(2 * sizeof(*cgrs), GFP_KERNEL);
if (!portal->cgrs)
goto fail_cgrs;
qman_cgrs_init(&portal->cgrs[1]);
if (cgrs)
portal->cgrs[0] = *cgrs;
else
qman_cgrs_fill(&portal->cgrs[0]);
INIT_LIST_HEAD(&portal->cgr_cbs);
spin_lock_init(&portal->cgr_lock);
INIT_WORK(&portal->congestion_work, qm_congestion_task);
INIT_WORK(&portal->mr_work, qm_mr_process_task);
portal->bits = 0;
portal->sdqcr = QM_SDQCR_SOURCE_CHANNELS | QM_SDQCR_COUNT_UPTO3 |
QM_SDQCR_DEDICATED_PRECEDENCE | QM_SDQCR_TYPE_PRIO_QOS |
QM_SDQCR_TOKEN_SET(0xab) | QM_SDQCR_CHANNELS_DEDICATED;
isdr = 0xffffffff;
qm_out(p, QM_REG_ISDR, isdr);
portal->irq_sources = 0;
qm_out(p, QM_REG_IER, 0);
qm_out(p, QM_REG_ISR, 0xffffffff);
snprintf(portal->irqname, MAX_IRQNAME, IRQNAME, c->cpu);
if (request_irq(c->irq, portal_isr, 0, portal->irqname, portal)) {
dev_err(c->dev, "request_irq() failed\n");
goto fail_irq;
}
if (c->cpu != -1 && irq_can_set_affinity(c->irq) &&
irq_set_affinity(c->irq, cpumask_of(c->cpu))) {
dev_err(c->dev, "irq_set_affinity() failed\n");
goto fail_affinity;
}
isdr &= ~QM_PIRQ_EQCI;
qm_out(p, QM_REG_ISDR, isdr);
ret = qm_eqcr_get_fill(p);
if (ret) {
dev_err(c->dev, "EQCR unclean\n");
goto fail_eqcr_empty;
}
isdr &= ~(QM_PIRQ_DQRI | QM_PIRQ_MRI);
qm_out(p, QM_REG_ISDR, isdr);
if (qm_dqrr_current(p)) {
dev_err(c->dev, "DQRR unclean\n");
qm_dqrr_cdc_consume_n(p, 0xffff);
}
if (qm_mr_current(p) && drain_mr_fqrni(p)) {
const union qm_mr_entry *e = qm_mr_current(p);
dev_err(c->dev, "MR dirty, VB 0x%x, rc 0x%x, addr 0x%llx\n",
e->verb, e->ern.rc, qm_fd_addr_get64(&e->ern.fd));
goto fail_dqrr_mr_empty;
}
portal->config = c;
qm_out(p, QM_REG_ISDR, 0);
qm_out(p, QM_REG_IIR, 0);
qm_dqrr_sdqcr_set(p, portal->sdqcr);
return 0;
fail_dqrr_mr_empty:
fail_eqcr_empty:
fail_affinity:
free_irq(c->irq, portal);
fail_irq:
kfree(portal->cgrs);
fail_cgrs:
qm_mc_finish(p);
fail_mc:
qm_mr_finish(p);
fail_mr:
qm_dqrr_finish(p);
fail_dqrr:
qm_eqcr_finish(p);
fail_eqcr:
return -EIO;
}
struct qman_portal *qman_create_affine_portal(const struct qm_portal_config *c,
const struct qman_cgrs *cgrs)
{
struct qman_portal *portal;
int err;
portal = &per_cpu(qman_affine_portal, c->cpu);
err = qman_create_portal(portal, c, cgrs);
if (err)
return NULL;
spin_lock(&affine_mask_lock);
cpumask_set_cpu(c->cpu, &affine_mask);
affine_channels[c->cpu] = c->channel;
affine_portals[c->cpu] = portal;
spin_unlock(&affine_mask_lock);
return portal;
}
static void qman_destroy_portal(struct qman_portal *qm)
{
const struct qm_portal_config *pcfg;
qm_dqrr_sdqcr_set(&qm->p, 0);
qm_eqcr_cce_update(&qm->p);
qm_eqcr_cce_update(&qm->p);
pcfg = qm->config;
free_irq(pcfg->irq, qm);
kfree(qm->cgrs);
qm_mc_finish(&qm->p);
qm_mr_finish(&qm->p);
qm_dqrr_finish(&qm->p);
qm_eqcr_finish(&qm->p);
qm->config = NULL;
}
const struct qm_portal_config *qman_destroy_affine_portal(void)
{
struct qman_portal *qm = get_affine_portal();
const struct qm_portal_config *pcfg;
int cpu;
pcfg = qm->config;
cpu = pcfg->cpu;
qman_destroy_portal(qm);
spin_lock(&affine_mask_lock);
cpumask_clear_cpu(cpu, &affine_mask);
spin_unlock(&affine_mask_lock);
put_affine_portal();
return pcfg;
}
static inline void fq_state_change(struct qman_portal *p, struct qman_fq *fq,
const union qm_mr_entry *msg, u8 verb)
{
switch (verb) {
case QM_MR_VERB_FQRL:
DPAA_ASSERT(fq_isset(fq, QMAN_FQ_STATE_ORL));
fq_clear(fq, QMAN_FQ_STATE_ORL);
break;
case QM_MR_VERB_FQRN:
DPAA_ASSERT(fq->state == qman_fq_state_parked ||
fq->state == qman_fq_state_sched);
DPAA_ASSERT(fq_isset(fq, QMAN_FQ_STATE_CHANGING));
fq_clear(fq, QMAN_FQ_STATE_CHANGING);
if (msg->fq.fqs & QM_MR_FQS_NOTEMPTY)
fq_set(fq, QMAN_FQ_STATE_NE);
if (msg->fq.fqs & QM_MR_FQS_ORLPRESENT)
fq_set(fq, QMAN_FQ_STATE_ORL);
fq->state = qman_fq_state_retired;
break;
case QM_MR_VERB_FQPN:
DPAA_ASSERT(fq->state == qman_fq_state_sched);
DPAA_ASSERT(fq_isclear(fq, QMAN_FQ_STATE_CHANGING));
fq->state = qman_fq_state_parked;
}
}
static void qm_congestion_task(struct work_struct *work)
{
struct qman_portal *p = container_of(work, struct qman_portal,
congestion_work);
struct qman_cgrs rr, c;
union qm_mc_result *mcr;
struct qman_cgr *cgr;
spin_lock(&p->cgr_lock);
qm_mc_start(&p->p);
qm_mc_commit(&p->p, QM_MCC_VERB_QUERYCONGESTION);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
spin_unlock(&p->cgr_lock);
dev_crit(p->config->dev, "QUERYCONGESTION timeout\n");
qman_p_irqsource_add(p, QM_PIRQ_CSCI);
return;
}
qman_cgrs_and(&rr, (struct qman_cgrs *)&mcr->querycongestion.state,
&p->cgrs[0]);
qman_cgrs_xor(&c, &rr, &p->cgrs[1]);
qman_cgrs_cp(&p->cgrs[1], &rr);
list_for_each_entry(cgr, &p->cgr_cbs, node)
if (cgr->cb && qman_cgrs_get(&c, cgr->cgrid))
cgr->cb(p, cgr, qman_cgrs_get(&rr, cgr->cgrid));
spin_unlock(&p->cgr_lock);
qman_p_irqsource_add(p, QM_PIRQ_CSCI);
}
static void qm_mr_process_task(struct work_struct *work)
{
struct qman_portal *p = container_of(work, struct qman_portal,
mr_work);
const union qm_mr_entry *msg;
struct qman_fq *fq;
u8 verb, num = 0;
preempt_disable();
while (1) {
qm_mr_pvb_update(&p->p);
msg = qm_mr_current(&p->p);
if (!msg)
break;
verb = msg->verb & QM_MR_VERB_TYPE_MASK;
if (verb & 0x20) {
switch (verb) {
case QM_MR_VERB_FQRNI:
break;
case QM_MR_VERB_FQRN:
case QM_MR_VERB_FQRL:
fq = fqid_to_fq(qm_fqid_get(&msg->fq));
if (WARN_ON(!fq))
break;
fq_state_change(p, fq, msg, verb);
if (fq->cb.fqs)
fq->cb.fqs(p, fq, msg);
break;
case QM_MR_VERB_FQPN:
fq = tag_to_fq(be32_to_cpu(msg->fq.context_b));
fq_state_change(p, fq, msg, verb);
if (fq->cb.fqs)
fq->cb.fqs(p, fq, msg);
break;
case QM_MR_VERB_DC_ERN:
pr_crit_once("Leaking DCP ERNs!\n");
break;
default:
pr_crit("Invalid MR verb 0x%02x\n", verb);
}
} else {
fq = tag_to_fq(be32_to_cpu(msg->ern.tag));
fq->cb.ern(p, fq, msg);
}
num++;
qm_mr_next(&p->p);
}
qm_mr_cci_consume(&p->p, num);
qman_p_irqsource_add(p, QM_PIRQ_MRI);
preempt_enable();
}
static u32 __poll_portal_slow(struct qman_portal *p, u32 is)
{
if (is & QM_PIRQ_CSCI) {
qman_p_irqsource_remove(p, QM_PIRQ_CSCI);
queue_work_on(smp_processor_id(), qm_portal_wq,
&p->congestion_work);
}
if (is & QM_PIRQ_EQRI) {
qm_eqcr_cce_update(&p->p);
qm_eqcr_set_ithresh(&p->p, 0);
wake_up(&affine_queue);
}
if (is & QM_PIRQ_MRI) {
qman_p_irqsource_remove(p, QM_PIRQ_MRI);
queue_work_on(smp_processor_id(), qm_portal_wq,
&p->mr_work);
}
return is;
}
static noinline void clear_vdqcr(struct qman_portal *p, struct qman_fq *fq)
{
p->vdqcr_owned = NULL;
fq_clear(fq, QMAN_FQ_STATE_VDQCR);
wake_up(&affine_queue);
}
static inline unsigned int __poll_portal_fast(struct qman_portal *p,
unsigned int poll_limit)
{
const struct qm_dqrr_entry *dq;
struct qman_fq *fq;
enum qman_cb_dqrr_result res;
unsigned int limit = 0;
do {
qm_dqrr_pvb_update(&p->p);
dq = qm_dqrr_current(&p->p);
if (!dq)
break;
if (dq->stat & QM_DQRR_STAT_UNSCHEDULED) {
fq = p->vdqcr_owned;
if (dq->stat & QM_DQRR_STAT_FQ_EMPTY)
fq_clear(fq, QMAN_FQ_STATE_NE);
res = fq->cb.dqrr(p, fq, dq);
if (res == qman_cb_dqrr_stop)
break;
if (dq->stat & QM_DQRR_STAT_DQCR_EXPIRED)
clear_vdqcr(p, fq);
} else {
fq = tag_to_fq(be32_to_cpu(dq->context_b));
res = fq->cb.dqrr(p, fq, dq);
if (res == qman_cb_dqrr_stop)
break;
}
DPAA_ASSERT((dq->stat & QM_DQRR_STAT_FQ_HELDACTIVE) ||
(res != qman_cb_dqrr_park));
if (res != qman_cb_dqrr_defer)
qm_dqrr_cdc_consume_1ptr(&p->p, dq,
res == qman_cb_dqrr_park);
qm_dqrr_next(&p->p);
} while (++limit < poll_limit && res != qman_cb_dqrr_consume_stop);
return limit;
}
void qman_p_irqsource_add(struct qman_portal *p, u32 bits)
{
unsigned long irqflags;
local_irq_save(irqflags);
set_bits(bits & QM_PIRQ_VISIBLE, &p->irq_sources);
qm_out(&p->p, QM_REG_IER, p->irq_sources);
local_irq_restore(irqflags);
}
void qman_p_irqsource_remove(struct qman_portal *p, u32 bits)
{
unsigned long irqflags;
u32 ier;
local_irq_save(irqflags);
bits &= QM_PIRQ_VISIBLE;
clear_bits(bits, &p->irq_sources);
qm_out(&p->p, QM_REG_IER, p->irq_sources);
ier = qm_in(&p->p, QM_REG_IER);
qm_out(&p->p, QM_REG_ISR, ~ier);
local_irq_restore(irqflags);
}
const cpumask_t *qman_affine_cpus(void)
{
return &affine_mask;
}
u16 qman_affine_channel(int cpu)
{
if (cpu < 0) {
struct qman_portal *portal = get_affine_portal();
cpu = portal->config->cpu;
put_affine_portal();
}
WARN_ON(!cpumask_test_cpu(cpu, &affine_mask));
return affine_channels[cpu];
}
struct qman_portal *qman_get_affine_portal(int cpu)
{
return affine_portals[cpu];
}
int qman_p_poll_dqrr(struct qman_portal *p, unsigned int limit)
{
return __poll_portal_fast(p, limit);
}
void qman_p_static_dequeue_add(struct qman_portal *p, u32 pools)
{
unsigned long irqflags;
local_irq_save(irqflags);
pools &= p->config->pools;
p->sdqcr |= pools;
qm_dqrr_sdqcr_set(&p->p, p->sdqcr);
local_irq_restore(irqflags);
}
static const char *mcr_result_str(u8 result)
{
switch (result) {
case QM_MCR_RESULT_NULL:
return "QM_MCR_RESULT_NULL";
case QM_MCR_RESULT_OK:
return "QM_MCR_RESULT_OK";
case QM_MCR_RESULT_ERR_FQID:
return "QM_MCR_RESULT_ERR_FQID";
case QM_MCR_RESULT_ERR_FQSTATE:
return "QM_MCR_RESULT_ERR_FQSTATE";
case QM_MCR_RESULT_ERR_NOTEMPTY:
return "QM_MCR_RESULT_ERR_NOTEMPTY";
case QM_MCR_RESULT_PENDING:
return "QM_MCR_RESULT_PENDING";
case QM_MCR_RESULT_ERR_BADCOMMAND:
return "QM_MCR_RESULT_ERR_BADCOMMAND";
}
return "<unknown MCR result>";
}
int qman_create_fq(u32 fqid, u32 flags, struct qman_fq *fq)
{
if (flags & QMAN_FQ_FLAG_DYNAMIC_FQID) {
int ret = qman_alloc_fqid(&fqid);
if (ret)
return ret;
}
fq->fqid = fqid;
fq->flags = flags;
fq->state = qman_fq_state_oos;
fq->cgr_groupid = 0;
if (fqid == 0 || fqid >= num_fqids) {
WARN(1, "bad fqid %d\n", fqid);
return -EINVAL;
}
fq->idx = fqid * 2;
if (flags & QMAN_FQ_FLAG_NO_MODIFY)
fq->idx++;
WARN_ON(fq_table[fq->idx]);
fq_table[fq->idx] = fq;
return 0;
}
void qman_destroy_fq(struct qman_fq *fq)
{
switch (fq->state) {
case qman_fq_state_parked:
case qman_fq_state_oos:
if (fq_isset(fq, QMAN_FQ_FLAG_DYNAMIC_FQID))
qman_release_fqid(fq->fqid);
DPAA_ASSERT(fq_table[fq->idx]);
fq_table[fq->idx] = NULL;
return;
default:
break;
}
DPAA_ASSERT(NULL == "qman_free_fq() on unquiesced FQ!");
}
u32 qman_fq_fqid(struct qman_fq *fq)
{
return fq->fqid;
}
int qman_init_fq(struct qman_fq *fq, u32 flags, struct qm_mcc_initfq *opts)
{
union qm_mc_command *mcc;
union qm_mc_result *mcr;
struct qman_portal *p;
u8 res, myverb;
int ret = 0;
myverb = (flags & QMAN_INITFQ_FLAG_SCHED)
? QM_MCC_VERB_INITFQ_SCHED : QM_MCC_VERB_INITFQ_PARKED;
if (fq->state != qman_fq_state_oos &&
fq->state != qman_fq_state_parked)
return -EINVAL;
#ifdef CONFIG_FSL_DPAA_CHECKING
if (fq_isset(fq, QMAN_FQ_FLAG_NO_MODIFY))
return -EINVAL;
#endif
if (opts && (be16_to_cpu(opts->we_mask) & QM_INITFQ_WE_OAC)) {
if (be16_to_cpu(opts->we_mask) & QM_INITFQ_WE_TDTHRESH)
return -EINVAL;
}
p = get_affine_portal();
if (fq_isset(fq, QMAN_FQ_STATE_CHANGING) ||
(fq->state != qman_fq_state_oos &&
fq->state != qman_fq_state_parked)) {
ret = -EBUSY;
goto out;
}
mcc = qm_mc_start(&p->p);
if (opts)
mcc->initfq = *opts;
qm_fqid_set(&mcc->fq, fq->fqid);
mcc->initfq.count = 0;
if (fq_isclear(fq, QMAN_FQ_FLAG_TO_DCPORTAL)) {
dma_addr_t phys_fq;
mcc->initfq.we_mask |= cpu_to_be16(QM_INITFQ_WE_CONTEXTB);
mcc->initfq.fqd.context_b = cpu_to_be32(fq_to_tag(fq));
if (!(be16_to_cpu(mcc->initfq.we_mask) &
QM_INITFQ_WE_CONTEXTA)) {
mcc->initfq.we_mask |=
cpu_to_be16(QM_INITFQ_WE_CONTEXTA);
memset(&mcc->initfq.fqd.context_a, 0,
sizeof(mcc->initfq.fqd.context_a));
} else {
struct qman_portal *p = qman_dma_portal;
phys_fq = dma_map_single(p->config->dev, fq,
sizeof(*fq), DMA_TO_DEVICE);
if (dma_mapping_error(p->config->dev, phys_fq)) {
dev_err(p->config->dev, "dma_mapping failed\n");
ret = -EIO;
goto out;
}
qm_fqd_stashing_set64(&mcc->initfq.fqd, phys_fq);
}
}
if (flags & QMAN_INITFQ_FLAG_LOCAL) {
int wq = 0;
if (!(be16_to_cpu(mcc->initfq.we_mask) &
QM_INITFQ_WE_DESTWQ)) {
mcc->initfq.we_mask |=
cpu_to_be16(QM_INITFQ_WE_DESTWQ);
wq = 4;
}
qm_fqd_set_destwq(&mcc->initfq.fqd, p->config->channel, wq);
}
qm_mc_commit(&p->p, myverb);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
dev_err(p->config->dev, "MCR timeout\n");
ret = -ETIMEDOUT;
goto out;
}
DPAA_ASSERT((mcr->verb & QM_MCR_VERB_MASK) == myverb);
res = mcr->result;
if (res != QM_MCR_RESULT_OK) {
ret = -EIO;
goto out;
}
if (opts) {
if (be16_to_cpu(opts->we_mask) & QM_INITFQ_WE_FQCTRL) {
if (be16_to_cpu(opts->fqd.fq_ctrl) & QM_FQCTRL_CGE)
fq_set(fq, QMAN_FQ_STATE_CGR_EN);
else
fq_clear(fq, QMAN_FQ_STATE_CGR_EN);
}
if (be16_to_cpu(opts->we_mask) & QM_INITFQ_WE_CGID)
fq->cgr_groupid = opts->fqd.cgid;
}
fq->state = (flags & QMAN_INITFQ_FLAG_SCHED) ?
qman_fq_state_sched : qman_fq_state_parked;
out:
put_affine_portal();
return ret;
}
int qman_schedule_fq(struct qman_fq *fq)
{
union qm_mc_command *mcc;
union qm_mc_result *mcr;
struct qman_portal *p;
int ret = 0;
if (fq->state != qman_fq_state_parked)
return -EINVAL;
#ifdef CONFIG_FSL_DPAA_CHECKING
if (fq_isset(fq, QMAN_FQ_FLAG_NO_MODIFY))
return -EINVAL;
#endif
p = get_affine_portal();
if (fq_isset(fq, QMAN_FQ_STATE_CHANGING) ||
fq->state != qman_fq_state_parked) {
ret = -EBUSY;
goto out;
}
mcc = qm_mc_start(&p->p);
qm_fqid_set(&mcc->fq, fq->fqid);
qm_mc_commit(&p->p, QM_MCC_VERB_ALTER_SCHED);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
dev_err(p->config->dev, "ALTER_SCHED timeout\n");
ret = -ETIMEDOUT;
goto out;
}
DPAA_ASSERT((mcr->verb & QM_MCR_VERB_MASK) == QM_MCR_VERB_ALTER_SCHED);
if (mcr->result != QM_MCR_RESULT_OK) {
ret = -EIO;
goto out;
}
fq->state = qman_fq_state_sched;
out:
put_affine_portal();
return ret;
}
int qman_retire_fq(struct qman_fq *fq, u32 *flags)
{
union qm_mc_command *mcc;
union qm_mc_result *mcr;
struct qman_portal *p;
int ret;
u8 res;
if (fq->state != qman_fq_state_parked &&
fq->state != qman_fq_state_sched)
return -EINVAL;
#ifdef CONFIG_FSL_DPAA_CHECKING
if (fq_isset(fq, QMAN_FQ_FLAG_NO_MODIFY))
return -EINVAL;
#endif
p = get_affine_portal();
if (fq_isset(fq, QMAN_FQ_STATE_CHANGING) ||
fq->state == qman_fq_state_retired ||
fq->state == qman_fq_state_oos) {
ret = -EBUSY;
goto out;
}
mcc = qm_mc_start(&p->p);
qm_fqid_set(&mcc->fq, fq->fqid);
qm_mc_commit(&p->p, QM_MCC_VERB_ALTER_RETIRE);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
dev_crit(p->config->dev, "ALTER_RETIRE timeout\n");
ret = -ETIMEDOUT;
goto out;
}
DPAA_ASSERT((mcr->verb & QM_MCR_VERB_MASK) == QM_MCR_VERB_ALTER_RETIRE);
res = mcr->result;
if (res == QM_MCR_RESULT_OK) {
ret = 0;
if (mcr->alterfq.fqs & QM_MCR_FQS_NOTEMPTY)
fq_set(fq, QMAN_FQ_STATE_NE);
if (mcr->alterfq.fqs & QM_MCR_FQS_ORLPRESENT)
fq_set(fq, QMAN_FQ_STATE_ORL);
if (flags)
*flags = fq->flags;
fq->state = qman_fq_state_retired;
if (fq->cb.fqs) {
union qm_mr_entry msg;
msg.verb = QM_MR_VERB_FQRNI;
msg.fq.fqs = mcr->alterfq.fqs;
qm_fqid_set(&msg.fq, fq->fqid);
msg.fq.context_b = cpu_to_be32(fq_to_tag(fq));
fq->cb.fqs(p, fq, &msg);
}
} else if (res == QM_MCR_RESULT_PENDING) {
ret = 1;
fq_set(fq, QMAN_FQ_STATE_CHANGING);
} else {
ret = -EIO;
}
out:
put_affine_portal();
return ret;
}
int qman_oos_fq(struct qman_fq *fq)
{
union qm_mc_command *mcc;
union qm_mc_result *mcr;
struct qman_portal *p;
int ret = 0;
if (fq->state != qman_fq_state_retired)
return -EINVAL;
#ifdef CONFIG_FSL_DPAA_CHECKING
if (fq_isset(fq, QMAN_FQ_FLAG_NO_MODIFY))
return -EINVAL;
#endif
p = get_affine_portal();
if (fq_isset(fq, QMAN_FQ_STATE_BLOCKOOS) ||
fq->state != qman_fq_state_retired) {
ret = -EBUSY;
goto out;
}
mcc = qm_mc_start(&p->p);
qm_fqid_set(&mcc->fq, fq->fqid);
qm_mc_commit(&p->p, QM_MCC_VERB_ALTER_OOS);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
ret = -ETIMEDOUT;
goto out;
}
DPAA_ASSERT((mcr->verb & QM_MCR_VERB_MASK) == QM_MCR_VERB_ALTER_OOS);
if (mcr->result != QM_MCR_RESULT_OK) {
ret = -EIO;
goto out;
}
fq->state = qman_fq_state_oos;
out:
put_affine_portal();
return ret;
}
int qman_query_fq(struct qman_fq *fq, struct qm_fqd *fqd)
{
union qm_mc_command *mcc;
union qm_mc_result *mcr;
struct qman_portal *p = get_affine_portal();
int ret = 0;
mcc = qm_mc_start(&p->p);
qm_fqid_set(&mcc->fq, fq->fqid);
qm_mc_commit(&p->p, QM_MCC_VERB_QUERYFQ);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
ret = -ETIMEDOUT;
goto out;
}
DPAA_ASSERT((mcr->verb & QM_MCR_VERB_MASK) == QM_MCR_VERB_QUERYFQ);
if (mcr->result == QM_MCR_RESULT_OK)
*fqd = mcr->queryfq.fqd;
else
ret = -EIO;
out:
put_affine_portal();
return ret;
}
int qman_query_fq_np(struct qman_fq *fq, struct qm_mcr_queryfq_np *np)
{
union qm_mc_command *mcc;
union qm_mc_result *mcr;
struct qman_portal *p = get_affine_portal();
int ret = 0;
mcc = qm_mc_start(&p->p);
qm_fqid_set(&mcc->fq, fq->fqid);
qm_mc_commit(&p->p, QM_MCC_VERB_QUERYFQ_NP);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
ret = -ETIMEDOUT;
goto out;
}
DPAA_ASSERT((mcr->verb & QM_MCR_VERB_MASK) == QM_MCR_VERB_QUERYFQ_NP);
if (mcr->result == QM_MCR_RESULT_OK)
*np = mcr->queryfq_np;
else if (mcr->result == QM_MCR_RESULT_ERR_FQID)
ret = -ERANGE;
else
ret = -EIO;
out:
put_affine_portal();
return ret;
}
static int qman_query_cgr(struct qman_cgr *cgr,
struct qm_mcr_querycgr *cgrd)
{
union qm_mc_command *mcc;
union qm_mc_result *mcr;
struct qman_portal *p = get_affine_portal();
int ret = 0;
mcc = qm_mc_start(&p->p);
mcc->cgr.cgid = cgr->cgrid;
qm_mc_commit(&p->p, QM_MCC_VERB_QUERYCGR);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
ret = -ETIMEDOUT;
goto out;
}
DPAA_ASSERT((mcr->verb & QM_MCR_VERB_MASK) == QM_MCC_VERB_QUERYCGR);
if (mcr->result == QM_MCR_RESULT_OK)
*cgrd = mcr->querycgr;
else {
dev_err(p->config->dev, "QUERY_CGR failed: %s\n",
mcr_result_str(mcr->result));
ret = -EIO;
}
out:
put_affine_portal();
return ret;
}
int qman_query_cgr_congested(struct qman_cgr *cgr, bool *result)
{
struct qm_mcr_querycgr query_cgr;
int err;
err = qman_query_cgr(cgr, &query_cgr);
if (err)
return err;
*result = !!query_cgr.cgr.cs;
return 0;
}
static int set_p_vdqcr(struct qman_portal *p, struct qman_fq *fq, u32 vdqcr)
{
unsigned long irqflags;
int ret = -EBUSY;
local_irq_save(irqflags);
if (p->vdqcr_owned)
goto out;
if (fq_isset(fq, QMAN_FQ_STATE_VDQCR))
goto out;
fq_set(fq, QMAN_FQ_STATE_VDQCR);
p->vdqcr_owned = fq;
qm_dqrr_vdqcr_set(&p->p, vdqcr);
ret = 0;
out:
local_irq_restore(irqflags);
return ret;
}
static int set_vdqcr(struct qman_portal **p, struct qman_fq *fq, u32 vdqcr)
{
int ret;
*p = get_affine_portal();
ret = set_p_vdqcr(*p, fq, vdqcr);
put_affine_portal();
return ret;
}
static int wait_vdqcr_start(struct qman_portal **p, struct qman_fq *fq,
u32 vdqcr, u32 flags)
{
int ret = 0;
if (flags & QMAN_VOLATILE_FLAG_WAIT_INT)
ret = wait_event_interruptible(affine_queue,
!set_vdqcr(p, fq, vdqcr));
else
wait_event(affine_queue, !set_vdqcr(p, fq, vdqcr));
return ret;
}
int qman_volatile_dequeue(struct qman_fq *fq, u32 flags, u32 vdqcr)
{
struct qman_portal *p;
int ret;
if (fq->state != qman_fq_state_parked &&
fq->state != qman_fq_state_retired)
return -EINVAL;
if (vdqcr & QM_VDQCR_FQID_MASK)
return -EINVAL;
if (fq_isset(fq, QMAN_FQ_STATE_VDQCR))
return -EBUSY;
vdqcr = (vdqcr & ~QM_VDQCR_FQID_MASK) | fq->fqid;
if (flags & QMAN_VOLATILE_FLAG_WAIT)
ret = wait_vdqcr_start(&p, fq, vdqcr, flags);
else
ret = set_vdqcr(&p, fq, vdqcr);
if (ret)
return ret;
if (flags & QMAN_VOLATILE_FLAG_FINISH) {
if (flags & QMAN_VOLATILE_FLAG_WAIT_INT)
wait_event_interruptible(affine_queue,
!fq_isset(fq, QMAN_FQ_STATE_VDQCR));
else
wait_event(affine_queue,
!fq_isset(fq, QMAN_FQ_STATE_VDQCR));
}
return 0;
}
static void update_eqcr_ci(struct qman_portal *p, u8 avail)
{
if (avail)
qm_eqcr_cce_prefetch(&p->p);
else
qm_eqcr_cce_update(&p->p);
}
int qman_enqueue(struct qman_fq *fq, const struct qm_fd *fd)
{
struct qman_portal *p;
struct qm_eqcr_entry *eq;
unsigned long irqflags;
u8 avail;
p = get_affine_portal();
local_irq_save(irqflags);
if (p->use_eqcr_ci_stashing) {
eq = qm_eqcr_start_stash(&p->p);
} else {
avail = qm_eqcr_get_avail(&p->p);
if (avail < 2)
update_eqcr_ci(p, avail);
eq = qm_eqcr_start_no_stash(&p->p);
}
if (unlikely(!eq))
goto out;
qm_fqid_set(eq, fq->fqid);
eq->tag = cpu_to_be32(fq_to_tag(fq));
eq->fd = *fd;
qm_eqcr_pvb_commit(&p->p, QM_EQCR_VERB_CMD_ENQUEUE);
out:
local_irq_restore(irqflags);
put_affine_portal();
return 0;
}
static int qm_modify_cgr(struct qman_cgr *cgr, u32 flags,
struct qm_mcc_initcgr *opts)
{
union qm_mc_command *mcc;
union qm_mc_result *mcr;
struct qman_portal *p = get_affine_portal();
u8 verb = QM_MCC_VERB_MODIFYCGR;
int ret = 0;
mcc = qm_mc_start(&p->p);
if (opts)
mcc->initcgr = *opts;
mcc->initcgr.cgid = cgr->cgrid;
if (flags & QMAN_CGR_FLAG_USE_INIT)
verb = QM_MCC_VERB_INITCGR;
qm_mc_commit(&p->p, verb);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
ret = -ETIMEDOUT;
goto out;
}
DPAA_ASSERT((mcr->verb & QM_MCR_VERB_MASK) == verb);
if (mcr->result != QM_MCR_RESULT_OK)
ret = -EIO;
out:
put_affine_portal();
return ret;
}
static void qm_cgr_cscn_targ_set(struct __qm_mc_cgr *cgr, int pi, u32 val)
{
if (qman_ip_rev >= QMAN_REV30)
cgr->cscn_targ_upd_ctrl = cpu_to_be16(pi |
QM_CGR_TARG_UDP_CTRL_WRITE_BIT);
else
cgr->cscn_targ = cpu_to_be32(val | QM_CGR_TARG_PORTAL(pi));
}
static void qm_cgr_cscn_targ_clear(struct __qm_mc_cgr *cgr, int pi, u32 val)
{
if (qman_ip_rev >= QMAN_REV30)
cgr->cscn_targ_upd_ctrl = cpu_to_be16(pi);
else
cgr->cscn_targ = cpu_to_be32(val & ~QM_CGR_TARG_PORTAL(pi));
}
void qman_init_cgr_all(void)
{
struct qman_cgr cgr;
int err_cnt = 0;
for (cgr.cgrid = 0; cgr.cgrid < CGR_NUM; cgr.cgrid++) {
if (qm_modify_cgr(&cgr, QMAN_CGR_FLAG_USE_INIT, NULL))
err_cnt++;
}
if (err_cnt)
pr_err("Warning: %d error%s while initialising CGR h/w\n",
err_cnt, (err_cnt > 1) ? "s" : "");
}
int qman_create_cgr(struct qman_cgr *cgr, u32 flags,
struct qm_mcc_initcgr *opts)
{
struct qm_mcr_querycgr cgr_state;
int ret;
struct qman_portal *p;
if (cgr->cgrid >= CGR_NUM)
return -EINVAL;
preempt_disable();
p = get_affine_portal();
qman_cgr_cpus[cgr->cgrid] = smp_processor_id();
preempt_enable();
cgr->chan = p->config->channel;
spin_lock(&p->cgr_lock);
if (opts) {
struct qm_mcc_initcgr local_opts = *opts;
ret = qman_query_cgr(cgr, &cgr_state);
if (ret)
goto out;
qm_cgr_cscn_targ_set(&local_opts.cgr, PORTAL_IDX(p),
be32_to_cpu(cgr_state.cgr.cscn_targ));
local_opts.we_mask |= cpu_to_be16(QM_CGR_WE_CSCN_TARG);
if (flags & QMAN_CGR_FLAG_USE_INIT)
ret = qm_modify_cgr(cgr, QMAN_CGR_FLAG_USE_INIT,
&local_opts);
else
ret = qm_modify_cgr(cgr, 0, &local_opts);
if (ret)
goto out;
}
list_add(&cgr->node, &p->cgr_cbs);
ret = qman_query_cgr(cgr, &cgr_state);
if (ret) {
dev_err(p->config->dev, "CGR HW state partially modified\n");
ret = 0;
goto out;
}
if (cgr->cb && cgr_state.cgr.cscn_en &&
qman_cgrs_get(&p->cgrs[1], cgr->cgrid))
cgr->cb(p, cgr, 1);
out:
spin_unlock(&p->cgr_lock);
put_affine_portal();
return ret;
}
int qman_delete_cgr(struct qman_cgr *cgr)
{
unsigned long irqflags;
struct qm_mcr_querycgr cgr_state;
struct qm_mcc_initcgr local_opts;
int ret = 0;
struct qman_cgr *i;
struct qman_portal *p = get_affine_portal();
if (cgr->chan != p->config->channel) {
dev_err(p->config->dev, "CGR not owned by current portal");
dev_dbg(p->config->dev, " create 0x%x, delete 0x%x\n",
cgr->chan, p->config->channel);
ret = -EINVAL;
goto put_portal;
}
memset(&local_opts, 0, sizeof(struct qm_mcc_initcgr));
spin_lock_irqsave(&p->cgr_lock, irqflags);
list_del(&cgr->node);
list_for_each_entry(i, &p->cgr_cbs, node)
if (i->cgrid == cgr->cgrid && i->cb)
goto release_lock;
ret = qman_query_cgr(cgr, &cgr_state);
if (ret) {
list_add(&cgr->node, &p->cgr_cbs);
goto release_lock;
}
local_opts.we_mask = cpu_to_be16(QM_CGR_WE_CSCN_TARG);
qm_cgr_cscn_targ_clear(&local_opts.cgr, PORTAL_IDX(p),
be32_to_cpu(cgr_state.cgr.cscn_targ));
ret = qm_modify_cgr(cgr, 0, &local_opts);
if (ret)
list_add(&cgr->node, &p->cgr_cbs);
release_lock:
spin_unlock_irqrestore(&p->cgr_lock, irqflags);
put_portal:
put_affine_portal();
return ret;
}
static int qman_delete_cgr_thread(void *p)
{
struct cgr_comp *cgr_comp = (struct cgr_comp *)p;
int ret;
ret = qman_delete_cgr(cgr_comp->cgr);
complete(&cgr_comp->completion);
return ret;
}
void qman_delete_cgr_safe(struct qman_cgr *cgr)
{
struct task_struct *thread;
struct cgr_comp cgr_comp;
preempt_disable();
if (qman_cgr_cpus[cgr->cgrid] != smp_processor_id()) {
init_completion(&cgr_comp.completion);
cgr_comp.cgr = cgr;
thread = kthread_create(qman_delete_cgr_thread, &cgr_comp,
"cgr_del");
if (IS_ERR(thread))
goto out;
kthread_bind(thread, qman_cgr_cpus[cgr->cgrid]);
wake_up_process(thread);
wait_for_completion(&cgr_comp.completion);
preempt_enable();
return;
}
out:
qman_delete_cgr(cgr);
preempt_enable();
}
static int _qm_mr_consume_and_match_verb(struct qm_portal *p, int v)
{
const union qm_mr_entry *msg;
int found = 0;
qm_mr_pvb_update(p);
msg = qm_mr_current(p);
while (msg) {
if ((msg->verb & QM_MR_VERB_TYPE_MASK) == v)
found = 1;
qm_mr_next(p);
qm_mr_cci_consume_to_current(p);
qm_mr_pvb_update(p);
msg = qm_mr_current(p);
}
return found;
}
static int _qm_dqrr_consume_and_match(struct qm_portal *p, u32 fqid, int s,
bool wait)
{
const struct qm_dqrr_entry *dqrr;
int found = 0;
do {
qm_dqrr_pvb_update(p);
dqrr = qm_dqrr_current(p);
if (!dqrr)
cpu_relax();
} while (wait && !dqrr);
while (dqrr) {
if (qm_fqid_get(dqrr) == fqid && (dqrr->stat & s))
found = 1;
qm_dqrr_cdc_consume_1ptr(p, dqrr, 0);
qm_dqrr_pvb_update(p);
qm_dqrr_next(p);
dqrr = qm_dqrr_current(p);
}
return found;
}
static int qman_shutdown_fq(u32 fqid)
{
struct qman_portal *p;
struct device *dev;
union qm_mc_command *mcc;
union qm_mc_result *mcr;
int orl_empty, drain = 0, ret = 0;
u32 channel, wq, res;
u8 state;
p = get_affine_portal();
dev = p->config->dev;
mcc = qm_mc_start(&p->p);
qm_fqid_set(&mcc->fq, fqid);
qm_mc_commit(&p->p, QM_MCC_VERB_QUERYFQ_NP);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
dev_err(dev, "QUERYFQ_NP timeout\n");
ret = -ETIMEDOUT;
goto out;
}
DPAA_ASSERT((mcr->verb & QM_MCR_VERB_MASK) == QM_MCR_VERB_QUERYFQ_NP);
state = mcr->queryfq_np.state & QM_MCR_NP_STATE_MASK;
if (state == QM_MCR_NP_STATE_OOS)
goto out;
mcc = qm_mc_start(&p->p);
qm_fqid_set(&mcc->fq, fqid);
qm_mc_commit(&p->p, QM_MCC_VERB_QUERYFQ);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
dev_err(dev, "QUERYFQ timeout\n");
ret = -ETIMEDOUT;
goto out;
}
DPAA_ASSERT((mcr->verb & QM_MCR_VERB_MASK) == QM_MCR_VERB_QUERYFQ);
channel = qm_fqd_get_chan(&mcr->queryfq.fqd);
wq = qm_fqd_get_wq(&mcr->queryfq.fqd);
switch (state) {
case QM_MCR_NP_STATE_TEN_SCHED:
case QM_MCR_NP_STATE_TRU_SCHED:
case QM_MCR_NP_STATE_ACTIVE:
case QM_MCR_NP_STATE_PARKED:
orl_empty = 0;
mcc = qm_mc_start(&p->p);
qm_fqid_set(&mcc->fq, fqid);
qm_mc_commit(&p->p, QM_MCC_VERB_ALTER_RETIRE);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
dev_err(dev, "QUERYFQ_NP timeout\n");
ret = -ETIMEDOUT;
goto out;
}
DPAA_ASSERT((mcr->verb & QM_MCR_VERB_MASK) ==
QM_MCR_VERB_ALTER_RETIRE);
res = mcr->result;
if (res == QM_MCR_RESULT_PENDING) {
int found_fqrn = 0;
u16 dequeue_wq = 0;
drain = 1;
if (channel >= qm_channel_pool1 &&
channel < qm_channel_pool1 + 15) {
dequeue_wq = (channel -
qm_channel_pool1 + 1)<<4 | wq;
} else if (channel < qm_channel_pool1) {
dequeue_wq = wq;
} else {
dev_err(dev, "Can't recover FQ 0x%x, ch: 0x%x",
fqid, channel);
ret = -EBUSY;
goto out;
}
if (channel < qm_channel_pool1)
qm_dqrr_sdqcr_set(&p->p,
QM_SDQCR_TYPE_ACTIVE |
QM_SDQCR_CHANNELS_DEDICATED);
else
qm_dqrr_sdqcr_set(&p->p,
QM_SDQCR_TYPE_ACTIVE |
QM_SDQCR_CHANNELS_POOL_CONV
(channel));
do {
qm_dqrr_drain_nomatch(&p->p);
found_fqrn = qm_mr_drain(&p->p, FQRN);
cpu_relax();
} while (!found_fqrn);
}
if (res != QM_MCR_RESULT_OK &&
res != QM_MCR_RESULT_PENDING) {
dev_err(dev, "retire_fq failed: FQ 0x%x, res=0x%x\n",
fqid, res);
ret = -EIO;
goto out;
}
if (!(mcr->alterfq.fqs & QM_MCR_FQS_ORLPRESENT)) {
orl_empty = 1;
}
if (drain || mcr->alterfq.fqs & QM_MCR_FQS_NOTEMPTY) {
do {
u32 vdqcr = fqid | QM_VDQCR_NUMFRAMES_SET(3);
qm_dqrr_vdqcr_set(&p->p, vdqcr);
} while (qm_dqrr_drain_wait(&p->p, fqid, FQ_EMPTY));
}
qm_dqrr_sdqcr_set(&p->p, 0);
while (!orl_empty) {
orl_empty = qm_mr_drain(&p->p, FQRL);
cpu_relax();
}
mcc = qm_mc_start(&p->p);
qm_fqid_set(&mcc->fq, fqid);
qm_mc_commit(&p->p, QM_MCC_VERB_ALTER_OOS);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
ret = -ETIMEDOUT;
goto out;
}
DPAA_ASSERT((mcr->verb & QM_MCR_VERB_MASK) ==
QM_MCR_VERB_ALTER_OOS);
if (mcr->result != QM_MCR_RESULT_OK) {
dev_err(dev, "OOS after drain fail: FQ 0x%x (0x%x)\n",
fqid, mcr->result);
ret = -EIO;
goto out;
}
break;
case QM_MCR_NP_STATE_RETIRED:
mcc = qm_mc_start(&p->p);
qm_fqid_set(&mcc->fq, fqid);
qm_mc_commit(&p->p, QM_MCC_VERB_ALTER_OOS);
if (!qm_mc_result_timeout(&p->p, &mcr)) {
ret = -ETIMEDOUT;
goto out;
}
DPAA_ASSERT((mcr->verb & QM_MCR_VERB_MASK) ==
QM_MCR_VERB_ALTER_OOS);
if (mcr->result) {
dev_err(dev, "OOS fail: FQ 0x%x (0x%x)\n",
fqid, mcr->result);
ret = -EIO;
goto out;
}
break;
case QM_MCR_NP_STATE_OOS:
break;
default:
ret = -EIO;
}
out:
put_affine_portal();
return ret;
}
const struct qm_portal_config *qman_get_qm_portal_config(
struct qman_portal *portal)
{
return portal->config;
}
static int qman_alloc_range(struct gen_pool *p, u32 *result, u32 cnt)
{
unsigned long addr;
addr = gen_pool_alloc(p, cnt);
if (!addr)
return -ENOMEM;
*result = addr & ~DPAA_GENALLOC_OFF;
return 0;
}
int qman_alloc_fqid_range(u32 *result, u32 count)
{
return qman_alloc_range(qm_fqalloc, result, count);
}
int qman_alloc_pool_range(u32 *result, u32 count)
{
return qman_alloc_range(qm_qpalloc, result, count);
}
int qman_alloc_cgrid_range(u32 *result, u32 count)
{
return qman_alloc_range(qm_cgralloc, result, count);
}
int qman_release_fqid(u32 fqid)
{
int ret = qman_shutdown_fq(fqid);
if (ret) {
pr_debug("FQID %d leaked\n", fqid);
return ret;
}
gen_pool_free(qm_fqalloc, fqid | DPAA_GENALLOC_OFF, 1);
return 0;
}
static int qpool_cleanup(u32 qp)
{
struct qman_fq fq = {
.fqid = QM_FQID_RANGE_START
};
int err;
do {
struct qm_mcr_queryfq_np np;
err = qman_query_fq_np(&fq, &np);
if (err == -ERANGE)
return 0;
else if (WARN_ON(err))
return err;
if ((np.state & QM_MCR_NP_STATE_MASK) != QM_MCR_NP_STATE_OOS) {
struct qm_fqd fqd;
err = qman_query_fq(&fq, &fqd);
if (WARN_ON(err))
return err;
if (qm_fqd_get_chan(&fqd) == qp) {
err = qman_shutdown_fq(fq.fqid);
if (err)
return err;
}
}
fq.fqid++;
} while (1);
}
int qman_release_pool(u32 qp)
{
int ret;
ret = qpool_cleanup(qp);
if (ret) {
pr_debug("CHID %d leaked\n", qp);
return ret;
}
gen_pool_free(qm_qpalloc, qp | DPAA_GENALLOC_OFF, 1);
return 0;
}
static int cgr_cleanup(u32 cgrid)
{
struct qman_fq fq = {
.fqid = QM_FQID_RANGE_START
};
int err;
do {
struct qm_mcr_queryfq_np np;
err = qman_query_fq_np(&fq, &np);
if (err == -ERANGE)
return 0;
else if (WARN_ON(err))
return err;
if ((np.state & QM_MCR_NP_STATE_MASK) != QM_MCR_NP_STATE_OOS) {
struct qm_fqd fqd;
err = qman_query_fq(&fq, &fqd);
if (WARN_ON(err))
return err;
if (be16_to_cpu(fqd.fq_ctrl) & QM_FQCTRL_CGE &&
fqd.cgid == cgrid) {
pr_err("CRGID 0x%x is being used by FQID 0x%x, CGR will be leaked\n",
cgrid, fq.fqid);
return -EIO;
}
}
fq.fqid++;
} while (1);
}
int qman_release_cgrid(u32 cgrid)
{
int ret;
ret = cgr_cleanup(cgrid);
if (ret) {
pr_debug("CGRID %d leaked\n", cgrid);
return ret;
}
gen_pool_free(qm_cgralloc, cgrid | DPAA_GENALLOC_OFF, 1);
return 0;
}
