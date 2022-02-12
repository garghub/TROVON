struct gtm_timer *gtm_get_timer16(void)
{
struct gtm *gtm = NULL;
int i;
list_for_each_entry(gtm, &gtms, list_node) {
spin_lock_irq(&gtm->lock);
for (i = 0; i < ARRAY_SIZE(gtm->timers); i++) {
if (!gtm->timers[i].requested) {
gtm->timers[i].requested = true;
spin_unlock_irq(&gtm->lock);
return &gtm->timers[i];
}
}
spin_unlock_irq(&gtm->lock);
}
if (gtm)
return ERR_PTR(-EBUSY);
return ERR_PTR(-ENODEV);
}
struct gtm_timer *gtm_get_specific_timer16(struct gtm *gtm,
unsigned int timer)
{
struct gtm_timer *ret = ERR_PTR(-EBUSY);
if (timer > 3)
return ERR_PTR(-EINVAL);
spin_lock_irq(&gtm->lock);
if (gtm->timers[timer].requested)
goto out;
ret = &gtm->timers[timer];
ret->requested = true;
out:
spin_unlock_irq(&gtm->lock);
return ret;
}
void gtm_put_timer16(struct gtm_timer *tmr)
{
gtm_stop_timer16(tmr);
spin_lock_irq(&tmr->gtm->lock);
tmr->requested = false;
spin_unlock_irq(&tmr->gtm->lock);
}
static int gtm_set_ref_timer16(struct gtm_timer *tmr, int frequency,
int reference_value, bool free_run)
{
struct gtm *gtm = tmr->gtm;
int num = tmr - &gtm->timers[0];
unsigned int prescaler;
u8 iclk = GTMDR_ICLK_ICLK;
u8 psr;
u8 sps;
unsigned long flags;
int max_prescaler = 256 * 256 * 16;
if (!tmr->gtpsr)
max_prescaler /= 256;
prescaler = gtm->clock / frequency;
if (prescaler > max_prescaler)
return -EINVAL;
if (prescaler > max_prescaler / 16) {
iclk = GTMDR_ICLK_SLGO;
prescaler /= 16;
}
if (prescaler <= 256) {
psr = 0;
sps = prescaler - 1;
} else {
psr = 256 - 1;
sps = prescaler / 256 - 1;
}
spin_lock_irqsave(&gtm->lock, flags);
clrsetbits_8(tmr->gtcfr, ~(GTCFR_STP(num) | GTCFR_RST(num)),
GTCFR_STP(num) | GTCFR_RST(num));
setbits8(tmr->gtcfr, GTCFR_STP(num));
if (tmr->gtpsr)
out_be16(tmr->gtpsr, psr);
clrsetbits_be16(tmr->gtmdr, 0xFFFF, iclk | GTMDR_SPS(sps) |
GTMDR_ORI | (free_run ? GTMDR_FRR : 0));
out_be16(tmr->gtcnr, 0);
out_be16(tmr->gtrfr, reference_value);
out_be16(tmr->gtevr, 0xFFFF);
clrbits8(tmr->gtcfr, GTCFR_STP(num));
spin_unlock_irqrestore(&gtm->lock, flags);
return 0;
}
int gtm_set_timer16(struct gtm_timer *tmr, unsigned long usec, bool reload)
{
int freq = 1000000;
unsigned int bit;
bit = fls_long(usec);
if (bit > 15) {
freq >>= bit - 15;
usec >>= bit - 15;
}
if (!freq)
return -EINVAL;
return gtm_set_ref_timer16(tmr, freq, usec, reload);
}
int gtm_set_exact_timer16(struct gtm_timer *tmr, u16 usec, bool reload)
{
const int freq = 1000000;
return gtm_set_ref_timer16(tmr, freq, usec, reload);
}
void gtm_stop_timer16(struct gtm_timer *tmr)
{
struct gtm *gtm = tmr->gtm;
int num = tmr - &gtm->timers[0];
unsigned long flags;
spin_lock_irqsave(&gtm->lock, flags);
setbits8(tmr->gtcfr, GTCFR_STP(num));
out_be16(tmr->gtevr, 0xFFFF);
spin_unlock_irqrestore(&gtm->lock, flags);
}
void gtm_ack_timer16(struct gtm_timer *tmr, u16 events)
{
out_be16(tmr->gtevr, events);
}
static void __init gtm_set_shortcuts(struct device_node *np,
struct gtm_timer *timers,
struct gtm_timers_regs __iomem *regs)
{
timers[0].gtcfr = &regs->gtcfr1;
timers[0].gtmdr = &regs->gtmdr1;
timers[0].gtcnr = &regs->gtcnr1;
timers[0].gtrfr = &regs->gtrfr1;
timers[0].gtevr = &regs->gtevr1;
timers[1].gtcfr = &regs->gtcfr1;
timers[1].gtmdr = &regs->gtmdr2;
timers[1].gtcnr = &regs->gtcnr2;
timers[1].gtrfr = &regs->gtrfr2;
timers[1].gtevr = &regs->gtevr2;
timers[2].gtcfr = &regs->gtcfr2;
timers[2].gtmdr = &regs->gtmdr3;
timers[2].gtcnr = &regs->gtcnr3;
timers[2].gtrfr = &regs->gtrfr3;
timers[2].gtevr = &regs->gtevr3;
timers[3].gtcfr = &regs->gtcfr2;
timers[3].gtmdr = &regs->gtmdr4;
timers[3].gtcnr = &regs->gtcnr4;
timers[3].gtrfr = &regs->gtrfr4;
timers[3].gtevr = &regs->gtevr4;
if (!of_device_is_compatible(np, "fsl,cpm2-gtm")) {
timers[0].gtpsr = &regs->gtpsr1;
timers[1].gtpsr = &regs->gtpsr2;
timers[2].gtpsr = &regs->gtpsr3;
timers[3].gtpsr = &regs->gtpsr4;
}
}
static int __init fsl_gtm_init(void)
{
struct device_node *np;
for_each_compatible_node(np, NULL, "fsl,gtm") {
int i;
struct gtm *gtm;
const u32 *clock;
int size;
gtm = kzalloc(sizeof(*gtm), GFP_KERNEL);
if (!gtm) {
pr_err("%pOF: unable to allocate memory\n",
np);
continue;
}
spin_lock_init(&gtm->lock);
clock = of_get_property(np, "clock-frequency", &size);
if (!clock || size != sizeof(*clock)) {
pr_err("%pOF: no clock-frequency\n", np);
goto err;
}
gtm->clock = *clock;
for (i = 0; i < ARRAY_SIZE(gtm->timers); i++) {
unsigned int irq;
irq = irq_of_parse_and_map(np, i);
if (!irq) {
pr_err("%pOF: not enough interrupts specified\n",
np);
goto err;
}
gtm->timers[i].irq = irq;
gtm->timers[i].gtm = gtm;
}
gtm->regs = of_iomap(np, 0);
if (!gtm->regs) {
pr_err("%pOF: unable to iomap registers\n",
np);
goto err;
}
gtm_set_shortcuts(np, gtm->timers, gtm->regs);
list_add(&gtm->list_node, &gtms);
np->data = gtm;
of_node_get(np);
continue;
err:
kfree(gtm);
}
return 0;
}
