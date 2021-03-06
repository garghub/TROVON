int cs5535_mfgpt_toggle_event(struct cs5535_mfgpt_timer *timer, int cmp,
int event, int enable)
{
uint32_t msr, mask, value, dummy;
int shift = (cmp == MFGPT_CMP1) ? 0 : 8;
if (!timer) {
WARN_ON(1);
return -EIO;
}
switch (event) {
case MFGPT_EVENT_RESET:
msr = MSR_MFGPT_NR;
mask = 1 << (timer->nr + 24);
break;
case MFGPT_EVENT_NMI:
msr = MSR_MFGPT_NR;
mask = 1 << (timer->nr + shift);
break;
case MFGPT_EVENT_IRQ:
msr = MSR_MFGPT_IRQ;
mask = 1 << (timer->nr + shift);
break;
default:
return -EIO;
}
rdmsr(msr, value, dummy);
if (enable)
value |= mask;
else
value &= ~mask;
wrmsr(msr, value, dummy);
return 0;
}
int cs5535_mfgpt_set_irq(struct cs5535_mfgpt_timer *timer, int cmp, int *irq,
int enable)
{
uint32_t zsel, lpc, dummy;
int shift;
if (!timer) {
WARN_ON(1);
return -EIO;
}
rdmsr(MSR_PIC_ZSEL_LOW, zsel, dummy);
shift = ((cmp == MFGPT_CMP1 ? 0 : 4) + timer->nr % 4) * 4;
if (((zsel >> shift) & 0xF) == 2)
return -EIO;
if (!*irq)
*irq = (zsel >> shift) & 0xF;
if (!*irq)
*irq = CONFIG_CS5535_MFGPT_DEFAULT_IRQ;
if (*irq < 1 || *irq == 2 || *irq > 15)
return -EIO;
rdmsr(MSR_PIC_IRQM_LPC, lpc, dummy);
if (lpc & (1 << *irq))
return -EIO;
if (cs5535_mfgpt_toggle_event(timer, cmp, MFGPT_EVENT_IRQ, enable))
return -EIO;
if (enable) {
zsel = (zsel & ~(0xF << shift)) | (*irq << shift);
wrmsr(MSR_PIC_ZSEL_LOW, zsel, dummy);
}
return 0;
}
struct cs5535_mfgpt_timer *cs5535_mfgpt_alloc_timer(int timer_nr, int domain)
{
struct cs5535_mfgpt_chip *mfgpt = &cs5535_mfgpt_chip;
struct cs5535_mfgpt_timer *timer = NULL;
unsigned long flags;
int max;
if (!mfgpt->initialized)
goto done;
if (domain == MFGPT_DOMAIN_WORKING)
max = 6;
else
max = MFGPT_MAX_TIMERS;
if (timer_nr >= max) {
WARN_ON(1);
goto done;
}
spin_lock_irqsave(&mfgpt->lock, flags);
if (timer_nr < 0) {
unsigned long t;
t = find_first_bit(mfgpt->avail, max);
timer_nr = t < max ? (int) t : -1;
} else {
if (!test_bit(timer_nr, mfgpt->avail))
timer_nr = -1;
}
if (timer_nr >= 0)
__clear_bit(timer_nr, mfgpt->avail);
spin_unlock_irqrestore(&mfgpt->lock, flags);
if (timer_nr < 0)
goto done;
timer = kmalloc(sizeof(*timer), GFP_KERNEL);
if (!timer) {
spin_lock_irqsave(&mfgpt->lock, flags);
__set_bit(timer_nr, mfgpt->avail);
spin_unlock_irqrestore(&mfgpt->lock, flags);
goto done;
}
timer->chip = mfgpt;
timer->nr = timer_nr;
dev_info(&mfgpt->pdev->dev, "registered timer %d\n", timer_nr);
done:
return timer;
}
void cs5535_mfgpt_free_timer(struct cs5535_mfgpt_timer *timer)
{
unsigned long flags;
uint16_t val;
val = cs5535_mfgpt_read(timer, MFGPT_REG_SETUP);
if (!(val & MFGPT_SETUP_SETUP)) {
spin_lock_irqsave(&timer->chip->lock, flags);
__set_bit(timer->nr, timer->chip->avail);
spin_unlock_irqrestore(&timer->chip->lock, flags);
}
kfree(timer);
}
uint16_t cs5535_mfgpt_read(struct cs5535_mfgpt_timer *timer, uint16_t reg)
{
return inw(timer->chip->base + reg + (timer->nr * 8));
}
void cs5535_mfgpt_write(struct cs5535_mfgpt_timer *timer, uint16_t reg,
uint16_t value)
{
outw(value, timer->chip->base + reg + (timer->nr * 8));
}
static void __devinit reset_all_timers(void)
{
uint32_t val, dummy;
val = 0xFF; dummy = 0;
wrmsr(MSR_MFGPT_SETUP, val, dummy);
}
static int __devinit scan_timers(struct cs5535_mfgpt_chip *mfgpt)
{
struct cs5535_mfgpt_timer timer = { .chip = mfgpt };
unsigned long flags;
int timers = 0;
uint16_t val;
int i;
if (mfgpt_reset_timers)
reset_all_timers();
spin_lock_irqsave(&mfgpt->lock, flags);
for (i = 0; i < MFGPT_MAX_TIMERS; i++) {
timer.nr = i;
val = cs5535_mfgpt_read(&timer, MFGPT_REG_SETUP);
if (!(val & MFGPT_SETUP_SETUP)) {
__set_bit(i, mfgpt->avail);
timers++;
}
}
spin_unlock_irqrestore(&mfgpt->lock, flags);
return timers;
}
static int __devinit cs5535_mfgpt_probe(struct platform_device *pdev)
{
struct resource *res;
int err = -EIO, t;
res = platform_get_resource(pdev, IORESOURCE_IO, 0);
if (!res) {
dev_err(&pdev->dev, "can't fetch device resource info\n");
goto done;
}
if (!request_region(res->start, resource_size(res), pdev->name)) {
dev_err(&pdev->dev, "can't request region\n");
goto done;
}
cs5535_mfgpt_chip.base = res->start;
cs5535_mfgpt_chip.pdev = pdev;
spin_lock_init(&cs5535_mfgpt_chip.lock);
dev_info(&pdev->dev, "reserved resource region %pR\n", res);
t = scan_timers(&cs5535_mfgpt_chip);
dev_info(&pdev->dev, "%d MFGPT timers available\n", t);
cs5535_mfgpt_chip.initialized = 1;
return 0;
done:
return err;
}
static int __init cs5535_mfgpt_init(void)
{
return platform_driver_register(&cs5535_mfgpt_driver);
}
