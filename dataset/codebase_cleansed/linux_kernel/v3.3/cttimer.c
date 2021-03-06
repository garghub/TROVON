static void ct_systimer_callback(unsigned long data)
{
struct ct_timer_instance *ti = (struct ct_timer_instance *)data;
struct snd_pcm_substream *substream = ti->substream;
struct snd_pcm_runtime *runtime = substream->runtime;
struct ct_atc_pcm *apcm = ti->apcm;
unsigned int period_size = runtime->period_size;
unsigned int buffer_size = runtime->buffer_size;
unsigned long flags;
unsigned int position, dist, interval;
position = substream->ops->pointer(substream);
dist = (position + buffer_size - ti->position) % buffer_size;
if (dist >= period_size ||
position / period_size != ti->position / period_size) {
apcm->interrupt(apcm);
ti->position = position;
}
interval = ((period_size - (position % period_size))
* HZ + (runtime->rate - 1)) / runtime->rate + HZ * 5 / 1000;
spin_lock_irqsave(&ti->lock, flags);
if (ti->running)
mod_timer(&ti->timer, jiffies + interval);
spin_unlock_irqrestore(&ti->lock, flags);
}
static void ct_systimer_init(struct ct_timer_instance *ti)
{
setup_timer(&ti->timer, ct_systimer_callback,
(unsigned long)ti);
}
static void ct_systimer_start(struct ct_timer_instance *ti)
{
struct snd_pcm_runtime *runtime = ti->substream->runtime;
unsigned long flags;
spin_lock_irqsave(&ti->lock, flags);
ti->running = 1;
mod_timer(&ti->timer,
jiffies + (runtime->period_size * HZ +
(runtime->rate - 1)) / runtime->rate);
spin_unlock_irqrestore(&ti->lock, flags);
}
static void ct_systimer_stop(struct ct_timer_instance *ti)
{
unsigned long flags;
spin_lock_irqsave(&ti->lock, flags);
ti->running = 0;
del_timer(&ti->timer);
spin_unlock_irqrestore(&ti->lock, flags);
}
static void ct_systimer_prepare(struct ct_timer_instance *ti)
{
ct_systimer_stop(ti);
try_to_del_timer_sync(&ti->timer);
}
static void ct_xfitimer_irq_rearm(struct ct_timer *atimer, int ticks)
{
struct hw *hw = atimer->atc->hw;
if (ticks > MAX_TICKS)
ticks = MAX_TICKS;
hw->set_timer_tick(hw, ticks);
if (!atimer->running)
hw->set_timer_irq(hw, 1);
atimer->running = 1;
}
static void ct_xfitimer_irq_stop(struct ct_timer *atimer)
{
if (atimer->running) {
struct hw *hw = atimer->atc->hw;
hw->set_timer_irq(hw, 0);
hw->set_timer_tick(hw, 0);
atimer->running = 0;
}
}
static inline unsigned int ct_xfitimer_get_wc(struct ct_timer *atimer)
{
struct hw *hw = atimer->atc->hw;
return hw->get_wc(hw);
}
static int ct_xfitimer_reprogram(struct ct_timer *atimer, int can_update)
{
struct ct_timer_instance *ti;
unsigned int min_intr = (unsigned int)-1;
int updates = 0;
unsigned int wc, diff;
if (list_empty(&atimer->running_head)) {
ct_xfitimer_irq_stop(atimer);
atimer->reprogram = 0;
return 0;
}
wc = ct_xfitimer_get_wc(atimer);
diff = wc - atimer->wc;
atimer->wc = wc;
list_for_each_entry(ti, &atimer->running_head, running_list) {
if (ti->frag_count > diff)
ti->frag_count -= diff;
else {
unsigned int pos;
unsigned int period_size, rate;
period_size = ti->substream->runtime->period_size;
rate = ti->substream->runtime->rate;
pos = ti->substream->ops->pointer(ti->substream);
if (pos / period_size != ti->position / period_size) {
ti->need_update = 1;
ti->position = pos;
updates++;
}
pos %= period_size;
pos = period_size - pos;
ti->frag_count = div_u64((u64)pos * CT_TIMER_FREQ +
rate - 1, rate);
}
if (ti->need_update && !can_update)
min_intr = 0;
if (ti->frag_count < min_intr)
min_intr = ti->frag_count;
}
if (min_intr < MIN_TICKS)
min_intr = MIN_TICKS;
ct_xfitimer_irq_rearm(atimer, min_intr);
atimer->reprogram = 0;
return updates;
}
static void ct_xfitimer_check_period(struct ct_timer *atimer)
{
struct ct_timer_instance *ti;
unsigned long flags;
spin_lock_irqsave(&atimer->list_lock, flags);
list_for_each_entry(ti, &atimer->instance_head, instance_list) {
if (ti->running && ti->need_update) {
ti->need_update = 0;
ti->apcm->interrupt(ti->apcm);
}
}
spin_unlock_irqrestore(&atimer->list_lock, flags);
}
static void ct_xfitimer_callback(struct ct_timer *atimer)
{
int update;
unsigned long flags;
spin_lock_irqsave(&atimer->lock, flags);
atimer->irq_handling = 1;
do {
update = ct_xfitimer_reprogram(atimer, 1);
spin_unlock(&atimer->lock);
if (update)
ct_xfitimer_check_period(atimer);
spin_lock(&atimer->lock);
} while (atimer->reprogram);
atimer->irq_handling = 0;
spin_unlock_irqrestore(&atimer->lock, flags);
}
static void ct_xfitimer_prepare(struct ct_timer_instance *ti)
{
ti->frag_count = ti->substream->runtime->period_size;
ti->running = 0;
ti->need_update = 0;
}
static void ct_xfitimer_update(struct ct_timer *atimer)
{
unsigned long flags;
spin_lock_irqsave(&atimer->lock, flags);
if (atimer->irq_handling) {
atimer->reprogram = 1;
spin_unlock_irqrestore(&atimer->lock, flags);
return;
}
ct_xfitimer_irq_stop(atimer);
ct_xfitimer_reprogram(atimer, 0);
spin_unlock_irqrestore(&atimer->lock, flags);
}
static void ct_xfitimer_start(struct ct_timer_instance *ti)
{
struct ct_timer *atimer = ti->timer_base;
unsigned long flags;
spin_lock_irqsave(&atimer->lock, flags);
if (list_empty(&ti->running_list))
atimer->wc = ct_xfitimer_get_wc(atimer);
ti->running = 1;
ti->need_update = 0;
list_add(&ti->running_list, &atimer->running_head);
spin_unlock_irqrestore(&atimer->lock, flags);
ct_xfitimer_update(atimer);
}
static void ct_xfitimer_stop(struct ct_timer_instance *ti)
{
struct ct_timer *atimer = ti->timer_base;
unsigned long flags;
spin_lock_irqsave(&atimer->lock, flags);
list_del_init(&ti->running_list);
ti->running = 0;
spin_unlock_irqrestore(&atimer->lock, flags);
ct_xfitimer_update(atimer);
}
static void ct_xfitimer_free_global(struct ct_timer *atimer)
{
ct_xfitimer_irq_stop(atimer);
}
struct ct_timer_instance *
ct_timer_instance_new(struct ct_timer *atimer, struct ct_atc_pcm *apcm)
{
struct ct_timer_instance *ti;
ti = kzalloc(sizeof(*ti), GFP_KERNEL);
if (!ti)
return NULL;
spin_lock_init(&ti->lock);
INIT_LIST_HEAD(&ti->instance_list);
INIT_LIST_HEAD(&ti->running_list);
ti->timer_base = atimer;
ti->apcm = apcm;
ti->substream = apcm->substream;
if (atimer->ops->init)
atimer->ops->init(ti);
spin_lock_irq(&atimer->list_lock);
list_add(&ti->instance_list, &atimer->instance_head);
spin_unlock_irq(&atimer->list_lock);
return ti;
}
void ct_timer_prepare(struct ct_timer_instance *ti)
{
if (ti->timer_base->ops->prepare)
ti->timer_base->ops->prepare(ti);
ti->position = 0;
ti->running = 0;
}
void ct_timer_start(struct ct_timer_instance *ti)
{
struct ct_timer *atimer = ti->timer_base;
atimer->ops->start(ti);
}
void ct_timer_stop(struct ct_timer_instance *ti)
{
struct ct_timer *atimer = ti->timer_base;
atimer->ops->stop(ti);
}
void ct_timer_instance_free(struct ct_timer_instance *ti)
{
struct ct_timer *atimer = ti->timer_base;
atimer->ops->stop(ti);
if (atimer->ops->free_instance)
atimer->ops->free_instance(ti);
spin_lock_irq(&atimer->list_lock);
list_del(&ti->instance_list);
spin_unlock_irq(&atimer->list_lock);
kfree(ti);
}
static void ct_timer_interrupt(void *data, unsigned int status)
{
struct ct_timer *timer = data;
if ((status & IT_INT) && timer->ops->interrupt)
timer->ops->interrupt(timer);
}
struct ct_timer *ct_timer_new(struct ct_atc *atc)
{
struct ct_timer *atimer;
struct hw *hw;
atimer = kzalloc(sizeof(*atimer), GFP_KERNEL);
if (!atimer)
return NULL;
spin_lock_init(&atimer->lock);
spin_lock_init(&atimer->list_lock);
INIT_LIST_HEAD(&atimer->instance_head);
INIT_LIST_HEAD(&atimer->running_head);
atimer->atc = atc;
hw = atc->hw;
if (!use_system_timer && hw->set_timer_irq) {
snd_printd(KERN_INFO "ctxfi: Use xfi-native timer\n");
atimer->ops = &ct_xfitimer_ops;
hw->irq_callback_data = atimer;
hw->irq_callback = ct_timer_interrupt;
} else {
snd_printd(KERN_INFO "ctxfi: Use system timer\n");
atimer->ops = &ct_systimer_ops;
}
return atimer;
}
void ct_timer_free(struct ct_timer *atimer)
{
struct hw *hw = atimer->atc->hw;
hw->irq_callback = NULL;
if (atimer->ops->free_global)
atimer->ops->free_global(atimer);
kfree(atimer);
}
