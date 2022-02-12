static int get_current_cpu(void)
{
#if defined(CONFIG_KVM) && defined(CONFIG_BOOKE)
struct kvm_vcpu *vcpu = current->thread.kvm_vcpu;
return vcpu ? vcpu->arch.irq_cpu_id : -1;
#else
return -1;
#endif
}
static void mpic_irq_raise(struct openpic *opp, struct irq_dest *dst,
int output)
{
struct kvm_interrupt irq = {
.irq = KVM_INTERRUPT_SET_LEVEL,
};
if (!dst->vcpu) {
pr_debug("%s: destination cpu %d does not exist\n",
__func__, (int)(dst - &opp->dst[0]));
return;
}
pr_debug("%s: cpu %d output %d\n", __func__, dst->vcpu->arch.irq_cpu_id,
output);
if (output != ILR_INTTGT_INT)
return;
kvm_vcpu_ioctl_interrupt(dst->vcpu, &irq);
}
static void mpic_irq_lower(struct openpic *opp, struct irq_dest *dst,
int output)
{
if (!dst->vcpu) {
pr_debug("%s: destination cpu %d does not exist\n",
__func__, (int)(dst - &opp->dst[0]));
return;
}
pr_debug("%s: cpu %d output %d\n", __func__, dst->vcpu->arch.irq_cpu_id,
output);
if (output != ILR_INTTGT_INT)
return;
kvmppc_core_dequeue_external(dst->vcpu);
}
static inline void IRQ_setbit(struct irq_queue *q, int n_IRQ)
{
set_bit(n_IRQ, q->queue);
}
static inline void IRQ_resetbit(struct irq_queue *q, int n_IRQ)
{
clear_bit(n_IRQ, q->queue);
}
static void IRQ_check(struct openpic *opp, struct irq_queue *q)
{
int irq = -1;
int next = -1;
int priority = -1;
for (;;) {
irq = find_next_bit(q->queue, opp->max_irq, irq + 1);
if (irq == opp->max_irq)
break;
pr_debug("IRQ_check: irq %d set ivpr_pr=%d pr=%d\n",
irq, IVPR_PRIORITY(opp->src[irq].ivpr), priority);
if (IVPR_PRIORITY(opp->src[irq].ivpr) > priority) {
next = irq;
priority = IVPR_PRIORITY(opp->src[irq].ivpr);
}
}
q->next = next;
q->priority = priority;
}
static int IRQ_get_next(struct openpic *opp, struct irq_queue *q)
{
IRQ_check(opp, q);
return q->next;
}
static void IRQ_local_pipe(struct openpic *opp, int n_CPU, int n_IRQ,
bool active, bool was_active)
{
struct irq_dest *dst;
struct irq_source *src;
int priority;
dst = &opp->dst[n_CPU];
src = &opp->src[n_IRQ];
pr_debug("%s: IRQ %d active %d was %d\n",
__func__, n_IRQ, active, was_active);
if (src->output != ILR_INTTGT_INT) {
pr_debug("%s: output %d irq %d active %d was %d count %d\n",
__func__, src->output, n_IRQ, active, was_active,
dst->outputs_active[src->output]);
if (active) {
if (!was_active &&
dst->outputs_active[src->output]++ == 0) {
pr_debug("%s: Raise OpenPIC output %d cpu %d irq %d\n",
__func__, src->output, n_CPU, n_IRQ);
mpic_irq_raise(opp, dst, src->output);
}
} else {
if (was_active &&
--dst->outputs_active[src->output] == 0) {
pr_debug("%s: Lower OpenPIC output %d cpu %d irq %d\n",
__func__, src->output, n_CPU, n_IRQ);
mpic_irq_lower(opp, dst, src->output);
}
}
return;
}
priority = IVPR_PRIORITY(src->ivpr);
if (active)
IRQ_setbit(&dst->raised, n_IRQ);
else
IRQ_resetbit(&dst->raised, n_IRQ);
IRQ_check(opp, &dst->raised);
if (active && priority <= dst->ctpr) {
pr_debug("%s: IRQ %d priority %d too low for ctpr %d on CPU %d\n",
__func__, n_IRQ, priority, dst->ctpr, n_CPU);
active = 0;
}
if (active) {
if (IRQ_get_next(opp, &dst->servicing) >= 0 &&
priority <= dst->servicing.priority) {
pr_debug("%s: IRQ %d is hidden by servicing IRQ %d on CPU %d\n",
__func__, n_IRQ, dst->servicing.next, n_CPU);
} else {
pr_debug("%s: Raise OpenPIC INT output cpu %d irq %d/%d\n",
__func__, n_CPU, n_IRQ, dst->raised.next);
mpic_irq_raise(opp, dst, ILR_INTTGT_INT);
}
} else {
IRQ_get_next(opp, &dst->servicing);
if (dst->raised.priority > dst->ctpr &&
dst->raised.priority > dst->servicing.priority) {
pr_debug("%s: IRQ %d inactive, IRQ %d prio %d above %d/%d, CPU %d\n",
__func__, n_IRQ, dst->raised.next,
dst->raised.priority, dst->ctpr,
dst->servicing.priority, n_CPU);
} else {
pr_debug("%s: IRQ %d inactive, current prio %d/%d, CPU %d\n",
__func__, n_IRQ, dst->ctpr,
dst->servicing.priority, n_CPU);
mpic_irq_lower(opp, dst, ILR_INTTGT_INT);
}
}
}
static void openpic_update_irq(struct openpic *opp, int n_IRQ)
{
struct irq_source *src;
bool active, was_active;
int i;
src = &opp->src[n_IRQ];
active = src->pending;
if ((src->ivpr & IVPR_MASK_MASK) && !src->nomask) {
pr_debug("%s: IRQ %d is disabled\n", __func__, n_IRQ);
active = false;
}
was_active = !!(src->ivpr & IVPR_ACTIVITY_MASK);
if (!active && !was_active) {
pr_debug("%s: IRQ %d is already inactive\n", __func__, n_IRQ);
return;
}
if (active)
src->ivpr |= IVPR_ACTIVITY_MASK;
else
src->ivpr &= ~IVPR_ACTIVITY_MASK;
if (src->destmask == 0) {
pr_debug("%s: IRQ %d has no target\n", __func__, n_IRQ);
return;
}
if (src->destmask == (1 << src->last_cpu)) {
IRQ_local_pipe(opp, src->last_cpu, n_IRQ, active, was_active);
} else if (!(src->ivpr & IVPR_MODE_MASK)) {
for (i = 0; i < opp->nb_cpus; i++) {
if (src->destmask & (1 << i)) {
IRQ_local_pipe(opp, i, n_IRQ, active,
was_active);
}
}
} else {
for (i = src->last_cpu + 1; i != src->last_cpu; i++) {
if (i == opp->nb_cpus)
i = 0;
if (src->destmask & (1 << i)) {
IRQ_local_pipe(opp, i, n_IRQ, active,
was_active);
src->last_cpu = i;
break;
}
}
}
}
static void openpic_set_irq(void *opaque, int n_IRQ, int level)
{
struct openpic *opp = opaque;
struct irq_source *src;
if (n_IRQ >= MAX_IRQ) {
WARN_ONCE(1, "%s: IRQ %d out of range\n", __func__, n_IRQ);
return;
}
src = &opp->src[n_IRQ];
pr_debug("openpic: set irq %d = %d ivpr=0x%08x\n",
n_IRQ, level, src->ivpr);
if (src->level) {
src->pending = level;
openpic_update_irq(opp, n_IRQ);
} else {
if (level) {
src->pending = 1;
openpic_update_irq(opp, n_IRQ);
}
if (src->output != ILR_INTTGT_INT) {
src->pending = 0;
openpic_update_irq(opp, n_IRQ);
}
}
}
static void openpic_reset(struct openpic *opp)
{
int i;
opp->gcr = GCR_RESET;
opp->frr = ((opp->nb_irqs - 1) << FRR_NIRQ_SHIFT) |
(opp->vid << FRR_VID_SHIFT);
opp->pir = 0;
opp->spve = -1 & opp->vector_mask;
opp->tfrr = opp->tfrr_reset;
for (i = 0; i < opp->max_irq; i++) {
opp->src[i].ivpr = opp->ivpr_reset;
switch (opp->src[i].type) {
case IRQ_TYPE_NORMAL:
opp->src[i].level =
!!(opp->ivpr_reset & IVPR_SENSE_MASK);
break;
case IRQ_TYPE_FSLINT:
opp->src[i].ivpr |= IVPR_POLARITY_MASK;
break;
case IRQ_TYPE_FSLSPECIAL:
break;
}
write_IRQreg_idr(opp, i, opp->idr_reset);
}
for (i = 0; i < MAX_CPU; i++) {
opp->dst[i].ctpr = 15;
memset(&opp->dst[i].raised, 0, sizeof(struct irq_queue));
opp->dst[i].raised.next = -1;
memset(&opp->dst[i].servicing, 0, sizeof(struct irq_queue));
opp->dst[i].servicing.next = -1;
}
for (i = 0; i < MAX_TMR; i++) {
opp->timers[i].tccr = 0;
opp->timers[i].tbcr = TBCR_CI;
}
opp->gcr = 0;
}
static inline uint32_t read_IRQreg_idr(struct openpic *opp, int n_IRQ)
{
return opp->src[n_IRQ].idr;
}
static inline uint32_t read_IRQreg_ilr(struct openpic *opp, int n_IRQ)
{
if (opp->flags & OPENPIC_FLAG_ILR)
return opp->src[n_IRQ].output;
return 0xffffffff;
}
static inline uint32_t read_IRQreg_ivpr(struct openpic *opp, int n_IRQ)
{
return opp->src[n_IRQ].ivpr;
}
static inline void write_IRQreg_idr(struct openpic *opp, int n_IRQ,
uint32_t val)
{
struct irq_source *src = &opp->src[n_IRQ];
uint32_t normal_mask = (1UL << opp->nb_cpus) - 1;
uint32_t crit_mask = 0;
uint32_t mask = normal_mask;
int crit_shift = IDR_EP_SHIFT - opp->nb_cpus;
int i;
if (opp->flags & OPENPIC_FLAG_IDR_CRIT) {
crit_mask = mask << crit_shift;
mask |= crit_mask | IDR_EP;
}
src->idr = val & mask;
pr_debug("Set IDR %d to 0x%08x\n", n_IRQ, src->idr);
if (opp->flags & OPENPIC_FLAG_IDR_CRIT) {
if (src->idr & crit_mask) {
if (src->idr & normal_mask) {
pr_debug("%s: IRQ configured for multiple output types, using critical\n",
__func__);
}
src->output = ILR_INTTGT_CINT;
src->nomask = true;
src->destmask = 0;
for (i = 0; i < opp->nb_cpus; i++) {
int n_ci = IDR_CI0_SHIFT - i;
if (src->idr & (1UL << n_ci))
src->destmask |= 1UL << i;
}
} else {
src->output = ILR_INTTGT_INT;
src->nomask = false;
src->destmask = src->idr & normal_mask;
}
} else {
src->destmask = src->idr;
}
}
static inline void write_IRQreg_ilr(struct openpic *opp, int n_IRQ,
uint32_t val)
{
if (opp->flags & OPENPIC_FLAG_ILR) {
struct irq_source *src = &opp->src[n_IRQ];
src->output = val & ILR_INTTGT_MASK;
pr_debug("Set ILR %d to 0x%08x, output %d\n", n_IRQ, src->idr,
src->output);
}
}
static inline void write_IRQreg_ivpr(struct openpic *opp, int n_IRQ,
uint32_t val)
{
uint32_t mask;
mask = IVPR_MASK_MASK | IVPR_PRIORITY_MASK | IVPR_SENSE_MASK |
IVPR_POLARITY_MASK | opp->vector_mask;
opp->src[n_IRQ].ivpr =
(opp->src[n_IRQ].ivpr & IVPR_ACTIVITY_MASK) | (val & mask);
switch (opp->src[n_IRQ].type) {
case IRQ_TYPE_NORMAL:
opp->src[n_IRQ].level =
!!(opp->src[n_IRQ].ivpr & IVPR_SENSE_MASK);
break;
case IRQ_TYPE_FSLINT:
opp->src[n_IRQ].ivpr &= ~IVPR_SENSE_MASK;
break;
case IRQ_TYPE_FSLSPECIAL:
opp->src[n_IRQ].ivpr &= ~(IVPR_POLARITY_MASK | IVPR_SENSE_MASK);
break;
}
openpic_update_irq(opp, n_IRQ);
pr_debug("Set IVPR %d to 0x%08x -> 0x%08x\n", n_IRQ, val,
opp->src[n_IRQ].ivpr);
}
static void openpic_gcr_write(struct openpic *opp, uint64_t val)
{
if (val & GCR_RESET) {
openpic_reset(opp);
return;
}
opp->gcr &= ~opp->mpic_mode_mask;
opp->gcr |= val & opp->mpic_mode_mask;
}
static int openpic_gbl_write(void *opaque, gpa_t addr, u32 val)
{
struct openpic *opp = opaque;
int err = 0;
pr_debug("%s: addr %#llx <= %08x\n", __func__, addr, val);
if (addr & 0xF)
return 0;
switch (addr) {
case 0x00:
break;
case 0x40:
case 0x50:
case 0x60:
case 0x70:
case 0x80:
case 0x90:
case 0xA0:
case 0xB0:
err = openpic_cpu_write_internal(opp, addr, val,
get_current_cpu());
break;
case 0x1000:
break;
case 0x1020:
openpic_gcr_write(opp, val);
break;
case 0x1080:
break;
case 0x1090:
err = -ENXIO;
break;
case 0x10A0:
case 0x10B0:
case 0x10C0:
case 0x10D0: {
int idx;
idx = (addr - 0x10A0) >> 4;
write_IRQreg_ivpr(opp, opp->irq_ipi0 + idx, val);
break;
}
case 0x10E0:
opp->spve = val & opp->vector_mask;
break;
default:
break;
}
return err;
}
static int openpic_gbl_read(void *opaque, gpa_t addr, u32 *ptr)
{
struct openpic *opp = opaque;
u32 retval;
int err = 0;
pr_debug("%s: addr %#llx\n", __func__, addr);
retval = 0xFFFFFFFF;
if (addr & 0xF)
goto out;
switch (addr) {
case 0x1000:
retval = opp->frr;
retval |= (opp->nb_cpus - 1) << FRR_NCPU_SHIFT;
break;
case 0x1020:
retval = opp->gcr;
break;
case 0x1080:
retval = opp->vir;
break;
case 0x1090:
retval = 0x00000000;
break;
case 0x00:
retval = opp->brr1;
break;
case 0x40:
case 0x50:
case 0x60:
case 0x70:
case 0x80:
case 0x90:
case 0xA0:
case 0xB0:
err = openpic_cpu_read_internal(opp, addr,
&retval, get_current_cpu());
break;
case 0x10A0:
case 0x10B0:
case 0x10C0:
case 0x10D0:
{
int idx;
idx = (addr - 0x10A0) >> 4;
retval = read_IRQreg_ivpr(opp, opp->irq_ipi0 + idx);
}
break;
case 0x10E0:
retval = opp->spve;
break;
default:
break;
}
out:
pr_debug("%s: => 0x%08x\n", __func__, retval);
*ptr = retval;
return err;
}
static int openpic_tmr_write(void *opaque, gpa_t addr, u32 val)
{
struct openpic *opp = opaque;
int idx;
addr += 0x10f0;
pr_debug("%s: addr %#llx <= %08x\n", __func__, addr, val);
if (addr & 0xF)
return 0;
if (addr == 0x10f0) {
opp->tfrr = val;
return 0;
}
idx = (addr >> 6) & 0x3;
addr = addr & 0x30;
switch (addr & 0x30) {
case 0x00:
break;
case 0x10:
if ((opp->timers[idx].tccr & TCCR_TOG) != 0 &&
(val & TBCR_CI) == 0 &&
(opp->timers[idx].tbcr & TBCR_CI) != 0)
opp->timers[idx].tccr &= ~TCCR_TOG;
opp->timers[idx].tbcr = val;
break;
case 0x20:
write_IRQreg_ivpr(opp, opp->irq_tim0 + idx, val);
break;
case 0x30:
write_IRQreg_idr(opp, opp->irq_tim0 + idx, val);
break;
}
return 0;
}
static int openpic_tmr_read(void *opaque, gpa_t addr, u32 *ptr)
{
struct openpic *opp = opaque;
uint32_t retval = -1;
int idx;
pr_debug("%s: addr %#llx\n", __func__, addr);
if (addr & 0xF)
goto out;
idx = (addr >> 6) & 0x3;
if (addr == 0x0) {
retval = opp->tfrr;
goto out;
}
switch (addr & 0x30) {
case 0x00:
retval = opp->timers[idx].tccr;
break;
case 0x10:
retval = opp->timers[idx].tbcr;
break;
case 0x20:
retval = read_IRQreg_ivpr(opp, opp->irq_tim0 + idx);
break;
case 0x30:
retval = read_IRQreg_idr(opp, opp->irq_tim0 + idx);
break;
}
out:
pr_debug("%s: => 0x%08x\n", __func__, retval);
*ptr = retval;
return 0;
}
static int openpic_src_write(void *opaque, gpa_t addr, u32 val)
{
struct openpic *opp = opaque;
int idx;
pr_debug("%s: addr %#llx <= %08x\n", __func__, addr, val);
addr = addr & 0xffff;
idx = addr >> 5;
switch (addr & 0x1f) {
case 0x00:
write_IRQreg_ivpr(opp, idx, val);
break;
case 0x10:
write_IRQreg_idr(opp, idx, val);
break;
case 0x18:
write_IRQreg_ilr(opp, idx, val);
break;
}
return 0;
}
static int openpic_src_read(void *opaque, gpa_t addr, u32 *ptr)
{
struct openpic *opp = opaque;
uint32_t retval;
int idx;
pr_debug("%s: addr %#llx\n", __func__, addr);
retval = 0xFFFFFFFF;
addr = addr & 0xffff;
idx = addr >> 5;
switch (addr & 0x1f) {
case 0x00:
retval = read_IRQreg_ivpr(opp, idx);
break;
case 0x10:
retval = read_IRQreg_idr(opp, idx);
break;
case 0x18:
retval = read_IRQreg_ilr(opp, idx);
break;
}
pr_debug("%s: => 0x%08x\n", __func__, retval);
*ptr = retval;
return 0;
}
static int openpic_msi_write(void *opaque, gpa_t addr, u32 val)
{
struct openpic *opp = opaque;
int idx = opp->irq_msi;
int srs, ibs;
pr_debug("%s: addr %#llx <= 0x%08x\n", __func__, addr, val);
if (addr & 0xF)
return 0;
switch (addr) {
case MSIIR_OFFSET:
srs = val >> MSIIR_SRS_SHIFT;
idx += srs;
ibs = (val & MSIIR_IBS_MASK) >> MSIIR_IBS_SHIFT;
opp->msi[srs].msir |= 1 << ibs;
openpic_set_irq(opp, idx, 1);
break;
default:
break;
}
return 0;
}
static int openpic_msi_read(void *opaque, gpa_t addr, u32 *ptr)
{
struct openpic *opp = opaque;
uint32_t r = 0;
int i, srs;
pr_debug("%s: addr %#llx\n", __func__, addr);
if (addr & 0xF)
return -ENXIO;
srs = addr >> 4;
switch (addr) {
case 0x00:
case 0x10:
case 0x20:
case 0x30:
case 0x40:
case 0x50:
case 0x60:
case 0x70:
r = opp->msi[srs].msir;
opp->msi[srs].msir = 0;
openpic_set_irq(opp, opp->irq_msi + srs, 0);
break;
case 0x120:
for (i = 0; i < MAX_MSI; i++)
r |= (opp->msi[i].msir ? 1 : 0) << i;
break;
}
pr_debug("%s: => 0x%08x\n", __func__, r);
*ptr = r;
return 0;
}
static int openpic_summary_read(void *opaque, gpa_t addr, u32 *ptr)
{
uint32_t r = 0;
pr_debug("%s: addr %#llx\n", __func__, addr);
*ptr = r;
return 0;
}
static int openpic_summary_write(void *opaque, gpa_t addr, u32 val)
{
pr_debug("%s: addr %#llx <= 0x%08x\n", __func__, addr, val);
return 0;
}
static int openpic_cpu_write_internal(void *opaque, gpa_t addr,
u32 val, int idx)
{
struct openpic *opp = opaque;
struct irq_source *src;
struct irq_dest *dst;
int s_IRQ, n_IRQ;
pr_debug("%s: cpu %d addr %#llx <= 0x%08x\n", __func__, idx,
addr, val);
if (idx < 0)
return 0;
if (addr & 0xF)
return 0;
dst = &opp->dst[idx];
addr &= 0xFF0;
switch (addr) {
case 0x40:
case 0x50:
case 0x60:
case 0x70:
idx = (addr - 0x40) >> 4;
opp->src[opp->irq_ipi0 + idx].destmask |= val;
openpic_set_irq(opp, opp->irq_ipi0 + idx, 1);
openpic_set_irq(opp, opp->irq_ipi0 + idx, 0);
break;
case 0x80:
dst->ctpr = val & 0x0000000F;
pr_debug("%s: set CPU %d ctpr to %d, raised %d servicing %d\n",
__func__, idx, dst->ctpr, dst->raised.priority,
dst->servicing.priority);
if (dst->raised.priority <= dst->ctpr) {
pr_debug("%s: Lower OpenPIC INT output cpu %d due to ctpr\n",
__func__, idx);
mpic_irq_lower(opp, dst, ILR_INTTGT_INT);
} else if (dst->raised.priority > dst->servicing.priority) {
pr_debug("%s: Raise OpenPIC INT output cpu %d irq %d\n",
__func__, idx, dst->raised.next);
mpic_irq_raise(opp, dst, ILR_INTTGT_INT);
}
break;
case 0x90:
break;
case 0xA0:
break;
case 0xB0: {
int notify_eoi;
pr_debug("EOI\n");
s_IRQ = IRQ_get_next(opp, &dst->servicing);
if (s_IRQ < 0) {
pr_debug("%s: EOI with no interrupt in service\n",
__func__);
break;
}
IRQ_resetbit(&dst->servicing, s_IRQ);
notify_eoi = s_IRQ;
s_IRQ = IRQ_get_next(opp, &dst->servicing);
n_IRQ = IRQ_get_next(opp, &dst->raised);
src = &opp->src[n_IRQ];
if (n_IRQ != -1 &&
(s_IRQ == -1 ||
IVPR_PRIORITY(src->ivpr) > dst->servicing.priority)) {
pr_debug("Raise OpenPIC INT output cpu %d irq %d\n",
idx, n_IRQ);
mpic_irq_raise(opp, dst, ILR_INTTGT_INT);
}
spin_unlock(&opp->lock);
kvm_notify_acked_irq(opp->kvm, 0, notify_eoi);
spin_lock(&opp->lock);
break;
}
default:
break;
}
return 0;
}
static int openpic_cpu_write(void *opaque, gpa_t addr, u32 val)
{
struct openpic *opp = opaque;
return openpic_cpu_write_internal(opp, addr, val,
(addr & 0x1f000) >> 12);
}
static uint32_t openpic_iack(struct openpic *opp, struct irq_dest *dst,
int cpu)
{
struct irq_source *src;
int retval, irq;
pr_debug("Lower OpenPIC INT output\n");
mpic_irq_lower(opp, dst, ILR_INTTGT_INT);
irq = IRQ_get_next(opp, &dst->raised);
pr_debug("IACK: irq=%d\n", irq);
if (irq == -1)
return opp->spve;
src = &opp->src[irq];
if (!(src->ivpr & IVPR_ACTIVITY_MASK) ||
!(IVPR_PRIORITY(src->ivpr) > dst->ctpr)) {
pr_err("%s: bad raised IRQ %d ctpr %d ivpr 0x%08x\n",
__func__, irq, dst->ctpr, src->ivpr);
openpic_update_irq(opp, irq);
retval = opp->spve;
} else {
IRQ_setbit(&dst->servicing, irq);
retval = IVPR_VECTOR(opp, src->ivpr);
}
if (!src->level) {
src->ivpr &= ~IVPR_ACTIVITY_MASK;
src->pending = 0;
IRQ_resetbit(&dst->raised, irq);
}
if ((irq >= opp->irq_ipi0) && (irq < (opp->irq_ipi0 + MAX_IPI))) {
src->destmask &= ~(1 << cpu);
if (src->destmask && !src->level) {
openpic_set_irq(opp, irq, 1);
openpic_set_irq(opp, irq, 0);
src->ivpr |= IVPR_ACTIVITY_MASK;
}
}
return retval;
}
void kvmppc_mpic_set_epr(struct kvm_vcpu *vcpu)
{
struct openpic *opp = vcpu->arch.mpic;
int cpu = vcpu->arch.irq_cpu_id;
unsigned long flags;
spin_lock_irqsave(&opp->lock, flags);
if ((opp->gcr & opp->mpic_mode_mask) == GCR_MODE_PROXY)
kvmppc_set_epr(vcpu, openpic_iack(opp, &opp->dst[cpu], cpu));
spin_unlock_irqrestore(&opp->lock, flags);
}
static int openpic_cpu_read_internal(void *opaque, gpa_t addr,
u32 *ptr, int idx)
{
struct openpic *opp = opaque;
struct irq_dest *dst;
uint32_t retval;
pr_debug("%s: cpu %d addr %#llx\n", __func__, idx, addr);
retval = 0xFFFFFFFF;
if (idx < 0)
goto out;
if (addr & 0xF)
goto out;
dst = &opp->dst[idx];
addr &= 0xFF0;
switch (addr) {
case 0x80:
retval = dst->ctpr;
break;
case 0x90:
retval = idx;
break;
case 0xA0:
retval = openpic_iack(opp, dst, idx);
break;
case 0xB0:
retval = 0;
break;
default:
break;
}
pr_debug("%s: => 0x%08x\n", __func__, retval);
out:
*ptr = retval;
return 0;
}
static int openpic_cpu_read(void *opaque, gpa_t addr, u32 *ptr)
{
struct openpic *opp = opaque;
return openpic_cpu_read_internal(opp, addr, ptr,
(addr & 0x1f000) >> 12);
}
static void add_mmio_region(struct openpic *opp, const struct mem_reg *mr)
{
if (opp->num_mmio_regions >= MAX_MMIO_REGIONS) {
WARN(1, "kvm mpic: too many mmio regions\n");
return;
}
opp->mmio_regions[opp->num_mmio_regions++] = mr;
}
static void fsl_common_init(struct openpic *opp)
{
int i;
int virq = MAX_SRC;
add_mmio_region(opp, &openpic_msi_mmio);
add_mmio_region(opp, &openpic_summary_mmio);
opp->vid = VID_REVISION_1_2;
opp->vir = VIR_GENERIC;
opp->vector_mask = 0xFFFF;
opp->tfrr_reset = 0;
opp->ivpr_reset = IVPR_MASK_MASK;
opp->idr_reset = 1 << 0;
opp->max_irq = MAX_IRQ;
opp->irq_ipi0 = virq;
virq += MAX_IPI;
opp->irq_tim0 = virq;
virq += MAX_TMR;
BUG_ON(virq > MAX_IRQ);
opp->irq_msi = 224;
for (i = 0; i < opp->fsl->max_ext; i++)
opp->src[i].level = false;
for (i = 16; i < MAX_SRC; i++) {
opp->src[i].type = IRQ_TYPE_FSLINT;
opp->src[i].level = true;
}
for (i = MAX_SRC; i < virq; i++) {
opp->src[i].type = IRQ_TYPE_FSLSPECIAL;
opp->src[i].level = false;
}
}
static int kvm_mpic_read_internal(struct openpic *opp, gpa_t addr, u32 *ptr)
{
int i;
for (i = 0; i < opp->num_mmio_regions; i++) {
const struct mem_reg *mr = opp->mmio_regions[i];
if (mr->start_addr > addr || addr >= mr->start_addr + mr->size)
continue;
return mr->read(opp, addr - mr->start_addr, ptr);
}
return -ENXIO;
}
static int kvm_mpic_write_internal(struct openpic *opp, gpa_t addr, u32 val)
{
int i;
for (i = 0; i < opp->num_mmio_regions; i++) {
const struct mem_reg *mr = opp->mmio_regions[i];
if (mr->start_addr > addr || addr >= mr->start_addr + mr->size)
continue;
return mr->write(opp, addr - mr->start_addr, val);
}
return -ENXIO;
}
static int kvm_mpic_read(struct kvm_vcpu *vcpu,
struct kvm_io_device *this,
gpa_t addr, int len, void *ptr)
{
struct openpic *opp = container_of(this, struct openpic, mmio);
int ret;
union {
u32 val;
u8 bytes[4];
} u;
if (addr & (len - 1)) {
pr_debug("%s: bad alignment %llx/%d\n",
__func__, addr, len);
return -EINVAL;
}
spin_lock_irq(&opp->lock);
ret = kvm_mpic_read_internal(opp, addr - opp->reg_base, &u.val);
spin_unlock_irq(&opp->lock);
if (len == 4) {
*(u32 *)ptr = u.val;
pr_debug("%s: addr %llx ret %d len 4 val %x\n",
__func__, addr, ret, u.val);
} else if (len == 1) {
*(u8 *)ptr = u.bytes[addr & 3];
pr_debug("%s: addr %llx ret %d len 1 val %x\n",
__func__, addr, ret, u.bytes[addr & 3]);
} else {
pr_debug("%s: bad length %d\n", __func__, len);
return -EINVAL;
}
return ret;
}
static int kvm_mpic_write(struct kvm_vcpu *vcpu,
struct kvm_io_device *this,
gpa_t addr, int len, const void *ptr)
{
struct openpic *opp = container_of(this, struct openpic, mmio);
int ret;
if (len != 4) {
pr_debug("%s: bad length %d\n", __func__, len);
return -EOPNOTSUPP;
}
if (addr & 3) {
pr_debug("%s: bad alignment %llx/%d\n", __func__, addr, len);
return -EOPNOTSUPP;
}
spin_lock_irq(&opp->lock);
ret = kvm_mpic_write_internal(opp, addr - opp->reg_base,
*(const u32 *)ptr);
spin_unlock_irq(&opp->lock);
pr_debug("%s: addr %llx ret %d val %x\n",
__func__, addr, ret, *(const u32 *)ptr);
return ret;
}
static void map_mmio(struct openpic *opp)
{
kvm_iodevice_init(&opp->mmio, &mpic_mmio_ops);
kvm_io_bus_register_dev(opp->kvm, KVM_MMIO_BUS,
opp->reg_base, OPENPIC_REG_SIZE,
&opp->mmio);
}
static void unmap_mmio(struct openpic *opp)
{
kvm_io_bus_unregister_dev(opp->kvm, KVM_MMIO_BUS, &opp->mmio);
}
static int set_base_addr(struct openpic *opp, struct kvm_device_attr *attr)
{
u64 base;
if (copy_from_user(&base, (u64 __user *)(long)attr->addr, sizeof(u64)))
return -EFAULT;
if (base & 0x3ffff) {
pr_debug("kvm mpic %s: KVM_DEV_MPIC_BASE_ADDR %08llx not aligned\n",
__func__, base);
return -EINVAL;
}
if (base == opp->reg_base)
return 0;
mutex_lock(&opp->kvm->slots_lock);
unmap_mmio(opp);
opp->reg_base = base;
pr_debug("kvm mpic %s: KVM_DEV_MPIC_BASE_ADDR %08llx\n",
__func__, base);
if (base == 0)
goto out;
map_mmio(opp);
out:
mutex_unlock(&opp->kvm->slots_lock);
return 0;
}
static int access_reg(struct openpic *opp, gpa_t addr, u32 *val, int type)
{
int ret;
if (addr & 3)
return -ENXIO;
spin_lock_irq(&opp->lock);
if (type == ATTR_SET)
ret = kvm_mpic_write_internal(opp, addr, *val);
else
ret = kvm_mpic_read_internal(opp, addr, val);
spin_unlock_irq(&opp->lock);
pr_debug("%s: type %d addr %llx val %x\n", __func__, type, addr, *val);
return ret;
}
static int mpic_set_attr(struct kvm_device *dev, struct kvm_device_attr *attr)
{
struct openpic *opp = dev->private;
u32 attr32;
switch (attr->group) {
case KVM_DEV_MPIC_GRP_MISC:
switch (attr->attr) {
case KVM_DEV_MPIC_BASE_ADDR:
return set_base_addr(opp, attr);
}
break;
case KVM_DEV_MPIC_GRP_REGISTER:
if (get_user(attr32, (u32 __user *)(long)attr->addr))
return -EFAULT;
return access_reg(opp, attr->attr, &attr32, ATTR_SET);
case KVM_DEV_MPIC_GRP_IRQ_ACTIVE:
if (attr->attr > MAX_SRC)
return -EINVAL;
if (get_user(attr32, (u32 __user *)(long)attr->addr))
return -EFAULT;
if (attr32 != 0 && attr32 != 1)
return -EINVAL;
spin_lock_irq(&opp->lock);
openpic_set_irq(opp, attr->attr, attr32);
spin_unlock_irq(&opp->lock);
return 0;
}
return -ENXIO;
}
static int mpic_get_attr(struct kvm_device *dev, struct kvm_device_attr *attr)
{
struct openpic *opp = dev->private;
u64 attr64;
u32 attr32;
int ret;
switch (attr->group) {
case KVM_DEV_MPIC_GRP_MISC:
switch (attr->attr) {
case KVM_DEV_MPIC_BASE_ADDR:
mutex_lock(&opp->kvm->slots_lock);
attr64 = opp->reg_base;
mutex_unlock(&opp->kvm->slots_lock);
if (copy_to_user((u64 __user *)(long)attr->addr,
&attr64, sizeof(u64)))
return -EFAULT;
return 0;
}
break;
case KVM_DEV_MPIC_GRP_REGISTER:
ret = access_reg(opp, attr->attr, &attr32, ATTR_GET);
if (ret)
return ret;
if (put_user(attr32, (u32 __user *)(long)attr->addr))
return -EFAULT;
return 0;
case KVM_DEV_MPIC_GRP_IRQ_ACTIVE:
if (attr->attr > MAX_SRC)
return -EINVAL;
spin_lock_irq(&opp->lock);
attr32 = opp->src[attr->attr].pending;
spin_unlock_irq(&opp->lock);
if (put_user(attr32, (u32 __user *)(long)attr->addr))
return -EFAULT;
return 0;
}
return -ENXIO;
}
static int mpic_has_attr(struct kvm_device *dev, struct kvm_device_attr *attr)
{
switch (attr->group) {
case KVM_DEV_MPIC_GRP_MISC:
switch (attr->attr) {
case KVM_DEV_MPIC_BASE_ADDR:
return 0;
}
break;
case KVM_DEV_MPIC_GRP_REGISTER:
return 0;
case KVM_DEV_MPIC_GRP_IRQ_ACTIVE:
if (attr->attr > MAX_SRC)
break;
return 0;
}
return -ENXIO;
}
static void mpic_destroy(struct kvm_device *dev)
{
struct openpic *opp = dev->private;
dev->kvm->arch.mpic = NULL;
kfree(opp);
kfree(dev);
}
static int mpic_set_default_irq_routing(struct openpic *opp)
{
struct kvm_irq_routing_entry *routing;
routing = kzalloc((sizeof(*routing)), GFP_KERNEL);
if (!routing)
return -ENOMEM;
kvm_set_irq_routing(opp->kvm, routing, 0, 0);
kfree(routing);
return 0;
}
static int mpic_create(struct kvm_device *dev, u32 type)
{
struct openpic *opp;
int ret;
if (dev->kvm->arch.mpic)
return -EINVAL;
opp = kzalloc(sizeof(struct openpic), GFP_KERNEL);
if (!opp)
return -ENOMEM;
dev->private = opp;
opp->kvm = dev->kvm;
opp->dev = dev;
opp->model = type;
spin_lock_init(&opp->lock);
add_mmio_region(opp, &openpic_gbl_mmio);
add_mmio_region(opp, &openpic_tmr_mmio);
add_mmio_region(opp, &openpic_src_mmio);
add_mmio_region(opp, &openpic_cpu_mmio);
switch (opp->model) {
case KVM_DEV_TYPE_FSL_MPIC_20:
opp->fsl = &fsl_mpic_20;
opp->brr1 = 0x00400200;
opp->flags |= OPENPIC_FLAG_IDR_CRIT;
opp->nb_irqs = 80;
opp->mpic_mode_mask = GCR_MODE_MIXED;
fsl_common_init(opp);
break;
case KVM_DEV_TYPE_FSL_MPIC_42:
opp->fsl = &fsl_mpic_42;
opp->brr1 = 0x00400402;
opp->flags |= OPENPIC_FLAG_ILR;
opp->nb_irqs = 196;
opp->mpic_mode_mask = GCR_MODE_PROXY;
fsl_common_init(opp);
break;
default:
ret = -ENODEV;
goto err;
}
ret = mpic_set_default_irq_routing(opp);
if (ret)
goto err;
openpic_reset(opp);
smp_wmb();
dev->kvm->arch.mpic = opp;
return 0;
err:
kfree(opp);
return ret;
}
int kvmppc_mpic_connect_vcpu(struct kvm_device *dev, struct kvm_vcpu *vcpu,
u32 cpu)
{
struct openpic *opp = dev->private;
int ret = 0;
if (dev->ops != &kvm_mpic_ops)
return -EPERM;
if (opp->kvm != vcpu->kvm)
return -EPERM;
if (cpu < 0 || cpu >= MAX_CPU)
return -EPERM;
spin_lock_irq(&opp->lock);
if (opp->dst[cpu].vcpu) {
ret = -EEXIST;
goto out;
}
if (vcpu->arch.irq_type) {
ret = -EBUSY;
goto out;
}
opp->dst[cpu].vcpu = vcpu;
opp->nb_cpus = max(opp->nb_cpus, cpu + 1);
vcpu->arch.mpic = opp;
vcpu->arch.irq_cpu_id = cpu;
vcpu->arch.irq_type = KVMPPC_IRQ_MPIC;
if (opp->mpic_mode_mask == GCR_MODE_PROXY)
vcpu->arch.epr_flags |= KVMPPC_EPR_KERNEL;
out:
spin_unlock_irq(&opp->lock);
return ret;
}
void kvmppc_mpic_disconnect_vcpu(struct openpic *opp, struct kvm_vcpu *vcpu)
{
BUG_ON(!opp->dst[vcpu->arch.irq_cpu_id].vcpu);
opp->dst[vcpu->arch.irq_cpu_id].vcpu = NULL;
}
static int mpic_set_irq(struct kvm_kernel_irq_routing_entry *e,
struct kvm *kvm, int irq_source_id, int level,
bool line_status)
{
u32 irq = e->irqchip.pin;
struct openpic *opp = kvm->arch.mpic;
unsigned long flags;
spin_lock_irqsave(&opp->lock, flags);
openpic_set_irq(opp, irq, level);
spin_unlock_irqrestore(&opp->lock, flags);
return 0;
}
int kvm_set_msi(struct kvm_kernel_irq_routing_entry *e,
struct kvm *kvm, int irq_source_id, int level, bool line_status)
{
struct openpic *opp = kvm->arch.mpic;
unsigned long flags;
spin_lock_irqsave(&opp->lock, flags);
openpic_msi_write(kvm->arch.mpic, MSIIR_OFFSET, e->msi.data);
spin_unlock_irqrestore(&opp->lock, flags);
return 0;
}
int kvm_set_routing_entry(struct kvm *kvm,
struct kvm_kernel_irq_routing_entry *e,
const struct kvm_irq_routing_entry *ue)
{
int r = -EINVAL;
switch (ue->type) {
case KVM_IRQ_ROUTING_IRQCHIP:
e->set = mpic_set_irq;
e->irqchip.irqchip = ue->u.irqchip.irqchip;
e->irqchip.pin = ue->u.irqchip.pin;
if (e->irqchip.pin >= KVM_IRQCHIP_NUM_PINS)
goto out;
break;
case KVM_IRQ_ROUTING_MSI:
e->set = kvm_set_msi;
e->msi.address_lo = ue->u.msi.address_lo;
e->msi.address_hi = ue->u.msi.address_hi;
e->msi.data = ue->u.msi.data;
break;
default:
goto out;
}
r = 0;
out:
return r;
}
