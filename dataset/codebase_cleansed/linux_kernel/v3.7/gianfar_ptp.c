static u64 tmr_cnt_read(struct etsects *etsects)
{
u64 ns;
u32 lo, hi;
lo = gfar_read(&etsects->regs->tmr_cnt_l);
hi = gfar_read(&etsects->regs->tmr_cnt_h);
ns = ((u64) hi) << 32;
ns |= lo;
return ns;
}
static void tmr_cnt_write(struct etsects *etsects, u64 ns)
{
u32 hi = ns >> 32;
u32 lo = ns & 0xffffffff;
gfar_write(&etsects->regs->tmr_cnt_l, lo);
gfar_write(&etsects->regs->tmr_cnt_h, hi);
}
static void set_alarm(struct etsects *etsects)
{
u64 ns;
u32 lo, hi;
ns = tmr_cnt_read(etsects) + 1500000000ULL;
ns = div_u64(ns, 1000000000UL) * 1000000000ULL;
ns -= etsects->tclk_period;
hi = ns >> 32;
lo = ns & 0xffffffff;
gfar_write(&etsects->regs->tmr_alarm1_l, lo);
gfar_write(&etsects->regs->tmr_alarm1_h, hi);
}
static void set_fipers(struct etsects *etsects)
{
set_alarm(etsects);
gfar_write(&etsects->regs->tmr_fiper1, etsects->tmr_fiper1);
gfar_write(&etsects->regs->tmr_fiper2, etsects->tmr_fiper2);
}
static irqreturn_t isr(int irq, void *priv)
{
struct etsects *etsects = priv;
struct ptp_clock_event event;
u64 ns;
u32 ack = 0, lo, hi, mask, val;
val = gfar_read(&etsects->regs->tmr_tevent);
if (val & ETS1) {
ack |= ETS1;
hi = gfar_read(&etsects->regs->tmr_etts1_h);
lo = gfar_read(&etsects->regs->tmr_etts1_l);
event.type = PTP_CLOCK_EXTTS;
event.index = 0;
event.timestamp = ((u64) hi) << 32;
event.timestamp |= lo;
ptp_clock_event(etsects->clock, &event);
}
if (val & ETS2) {
ack |= ETS2;
hi = gfar_read(&etsects->regs->tmr_etts2_h);
lo = gfar_read(&etsects->regs->tmr_etts2_l);
event.type = PTP_CLOCK_EXTTS;
event.index = 1;
event.timestamp = ((u64) hi) << 32;
event.timestamp |= lo;
ptp_clock_event(etsects->clock, &event);
}
if (val & ALM2) {
ack |= ALM2;
if (etsects->alarm_value) {
event.type = PTP_CLOCK_ALARM;
event.index = 0;
event.timestamp = etsects->alarm_value;
ptp_clock_event(etsects->clock, &event);
}
if (etsects->alarm_interval) {
ns = etsects->alarm_value + etsects->alarm_interval;
hi = ns >> 32;
lo = ns & 0xffffffff;
spin_lock(&etsects->lock);
gfar_write(&etsects->regs->tmr_alarm2_l, lo);
gfar_write(&etsects->regs->tmr_alarm2_h, hi);
spin_unlock(&etsects->lock);
etsects->alarm_value = ns;
} else {
gfar_write(&etsects->regs->tmr_tevent, ALM2);
spin_lock(&etsects->lock);
mask = gfar_read(&etsects->regs->tmr_temask);
mask &= ~ALM2EN;
gfar_write(&etsects->regs->tmr_temask, mask);
spin_unlock(&etsects->lock);
etsects->alarm_value = 0;
etsects->alarm_interval = 0;
}
}
if (val & PP1) {
ack |= PP1;
event.type = PTP_CLOCK_PPS;
ptp_clock_event(etsects->clock, &event);
}
if (ack) {
gfar_write(&etsects->regs->tmr_tevent, ack);
return IRQ_HANDLED;
} else
return IRQ_NONE;
}
static int ptp_gianfar_adjfreq(struct ptp_clock_info *ptp, s32 ppb)
{
u64 adj;
u32 diff, tmr_add;
int neg_adj = 0;
struct etsects *etsects = container_of(ptp, struct etsects, caps);
if (ppb < 0) {
neg_adj = 1;
ppb = -ppb;
}
tmr_add = etsects->tmr_add;
adj = tmr_add;
adj *= ppb;
diff = div_u64(adj, 1000000000ULL);
tmr_add = neg_adj ? tmr_add - diff : tmr_add + diff;
gfar_write(&etsects->regs->tmr_add, tmr_add);
return 0;
}
static int ptp_gianfar_adjtime(struct ptp_clock_info *ptp, s64 delta)
{
s64 now;
unsigned long flags;
struct etsects *etsects = container_of(ptp, struct etsects, caps);
spin_lock_irqsave(&etsects->lock, flags);
now = tmr_cnt_read(etsects);
now += delta;
tmr_cnt_write(etsects, now);
spin_unlock_irqrestore(&etsects->lock, flags);
set_fipers(etsects);
return 0;
}
static int ptp_gianfar_gettime(struct ptp_clock_info *ptp, struct timespec *ts)
{
u64 ns;
u32 remainder;
unsigned long flags;
struct etsects *etsects = container_of(ptp, struct etsects, caps);
spin_lock_irqsave(&etsects->lock, flags);
ns = tmr_cnt_read(etsects);
spin_unlock_irqrestore(&etsects->lock, flags);
ts->tv_sec = div_u64_rem(ns, 1000000000, &remainder);
ts->tv_nsec = remainder;
return 0;
}
static int ptp_gianfar_settime(struct ptp_clock_info *ptp,
const struct timespec *ts)
{
u64 ns;
unsigned long flags;
struct etsects *etsects = container_of(ptp, struct etsects, caps);
ns = ts->tv_sec * 1000000000ULL;
ns += ts->tv_nsec;
spin_lock_irqsave(&etsects->lock, flags);
tmr_cnt_write(etsects, ns);
set_fipers(etsects);
spin_unlock_irqrestore(&etsects->lock, flags);
return 0;
}
static int ptp_gianfar_enable(struct ptp_clock_info *ptp,
struct ptp_clock_request *rq, int on)
{
struct etsects *etsects = container_of(ptp, struct etsects, caps);
unsigned long flags;
u32 bit, mask;
switch (rq->type) {
case PTP_CLK_REQ_EXTTS:
switch (rq->extts.index) {
case 0:
bit = ETS1EN;
break;
case 1:
bit = ETS2EN;
break;
default:
return -EINVAL;
}
spin_lock_irqsave(&etsects->lock, flags);
mask = gfar_read(&etsects->regs->tmr_temask);
if (on)
mask |= bit;
else
mask &= ~bit;
gfar_write(&etsects->regs->tmr_temask, mask);
spin_unlock_irqrestore(&etsects->lock, flags);
return 0;
case PTP_CLK_REQ_PPS:
spin_lock_irqsave(&etsects->lock, flags);
mask = gfar_read(&etsects->regs->tmr_temask);
if (on)
mask |= PP1EN;
else
mask &= ~PP1EN;
gfar_write(&etsects->regs->tmr_temask, mask);
spin_unlock_irqrestore(&etsects->lock, flags);
return 0;
default:
break;
}
return -EOPNOTSUPP;
}
static int get_of_u32(struct device_node *node, char *str, u32 *val)
{
int plen;
const u32 *prop = of_get_property(node, str, &plen);
if (!prop || plen != sizeof(*prop))
return -1;
*val = *prop;
return 0;
}
static int gianfar_ptp_probe(struct platform_device *dev)
{
struct device_node *node = dev->dev.of_node;
struct etsects *etsects;
struct timespec now;
int err = -ENOMEM;
u32 tmr_ctrl;
unsigned long flags;
etsects = kzalloc(sizeof(*etsects), GFP_KERNEL);
if (!etsects)
goto no_memory;
err = -ENODEV;
etsects->caps = ptp_gianfar_caps;
etsects->cksel = DEFAULT_CKSEL;
if (get_of_u32(node, "fsl,tclk-period", &etsects->tclk_period) ||
get_of_u32(node, "fsl,tmr-prsc", &etsects->tmr_prsc) ||
get_of_u32(node, "fsl,tmr-add", &etsects->tmr_add) ||
get_of_u32(node, "fsl,tmr-fiper1", &etsects->tmr_fiper1) ||
get_of_u32(node, "fsl,tmr-fiper2", &etsects->tmr_fiper2) ||
get_of_u32(node, "fsl,max-adj", &etsects->caps.max_adj)) {
pr_err("device tree node missing required elements\n");
goto no_node;
}
etsects->irq = platform_get_irq(dev, 0);
if (etsects->irq == NO_IRQ) {
pr_err("irq not in device tree\n");
goto no_node;
}
if (request_irq(etsects->irq, isr, 0, DRIVER, etsects)) {
pr_err("request_irq failed\n");
goto no_node;
}
etsects->rsrc = platform_get_resource(dev, IORESOURCE_MEM, 0);
if (!etsects->rsrc) {
pr_err("no resource\n");
goto no_resource;
}
if (request_resource(&iomem_resource, etsects->rsrc)) {
pr_err("resource busy\n");
goto no_resource;
}
spin_lock_init(&etsects->lock);
etsects->regs = ioremap(etsects->rsrc->start,
resource_size(etsects->rsrc));
if (!etsects->regs) {
pr_err("ioremap ptp registers failed\n");
goto no_ioremap;
}
getnstimeofday(&now);
ptp_gianfar_settime(&etsects->caps, &now);
tmr_ctrl =
(etsects->tclk_period & TCLK_PERIOD_MASK) << TCLK_PERIOD_SHIFT |
(etsects->cksel & CKSEL_MASK) << CKSEL_SHIFT;
spin_lock_irqsave(&etsects->lock, flags);
gfar_write(&etsects->regs->tmr_ctrl, tmr_ctrl);
gfar_write(&etsects->regs->tmr_add, etsects->tmr_add);
gfar_write(&etsects->regs->tmr_prsc, etsects->tmr_prsc);
gfar_write(&etsects->regs->tmr_fiper1, etsects->tmr_fiper1);
gfar_write(&etsects->regs->tmr_fiper2, etsects->tmr_fiper2);
set_alarm(etsects);
gfar_write(&etsects->regs->tmr_ctrl, tmr_ctrl|FS|RTPE|TE|FRD);
spin_unlock_irqrestore(&etsects->lock, flags);
etsects->clock = ptp_clock_register(&etsects->caps, &dev->dev);
if (IS_ERR(etsects->clock)) {
err = PTR_ERR(etsects->clock);
goto no_clock;
}
gfar_phc_index = ptp_clock_index(etsects->clock);
dev_set_drvdata(&dev->dev, etsects);
return 0;
no_clock:
no_ioremap:
release_resource(etsects->rsrc);
no_resource:
free_irq(etsects->irq, etsects);
no_node:
kfree(etsects);
no_memory:
return err;
}
static int gianfar_ptp_remove(struct platform_device *dev)
{
struct etsects *etsects = dev_get_drvdata(&dev->dev);
gfar_write(&etsects->regs->tmr_temask, 0);
gfar_write(&etsects->regs->tmr_ctrl, 0);
gfar_phc_index = -1;
ptp_clock_unregister(etsects->clock);
iounmap(etsects->regs);
release_resource(etsects->rsrc);
free_irq(etsects->irq, etsects);
kfree(etsects);
return 0;
}
