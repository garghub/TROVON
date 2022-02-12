static void store_vblank(struct drm_device *dev, int crtc,
u32 vblank_count_inc,
struct timeval *t_vblank)
{
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
u32 tslot;
assert_spin_locked(&dev->vblank_time_lock);
if (t_vblank) {
tslot = vblank->count + vblank_count_inc;
vblanktimestamp(dev, crtc, tslot) = *t_vblank;
}
smp_wmb();
vblank->count += vblank_count_inc;
smp_wmb();
}
static void drm_update_vblank_count(struct drm_device *dev, int crtc)
{
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
u32 cur_vblank, diff;
bool rc;
struct timeval t_vblank;
do {
cur_vblank = dev->driver->get_vblank_counter(dev, crtc);
rc = drm_get_last_vbltimestamp(dev, crtc, &t_vblank, 0);
} while (cur_vblank != dev->driver->get_vblank_counter(dev, crtc));
diff = cur_vblank - vblank->last;
if (cur_vblank < vblank->last) {
diff += dev->max_vblank_count + 1;
DRM_DEBUG("last_vblank[%d]=0x%x, cur_vblank=0x%x => diff=0x%x\n",
crtc, vblank->last, cur_vblank, diff);
}
DRM_DEBUG("updating vblank count on crtc %d, missed %d\n",
crtc, diff);
if (diff == 0)
return;
if (!rc)
t_vblank = (struct timeval) {0, 0};
store_vblank(dev, crtc, diff, &t_vblank);
}
static void vblank_disable_and_save(struct drm_device *dev, int crtc)
{
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
unsigned long irqflags;
u32 vblcount;
s64 diff_ns;
bool vblrc;
struct timeval tvblank;
int count = DRM_TIMESTAMP_MAXRETRIES;
spin_lock_irqsave(&dev->vblank_time_lock, irqflags);
if (!vblank->enabled &&
drm_get_last_vbltimestamp(dev, crtc, &tvblank, 0)) {
drm_update_vblank_count(dev, crtc);
spin_unlock_irqrestore(&dev->vblank_time_lock, irqflags);
return;
}
if (vblank->enabled) {
dev->driver->disable_vblank(dev, crtc);
vblank->enabled = false;
}
do {
vblank->last = dev->driver->get_vblank_counter(dev, crtc);
vblrc = drm_get_last_vbltimestamp(dev, crtc, &tvblank, 0);
} while (vblank->last != dev->driver->get_vblank_counter(dev, crtc) && (--count) && vblrc);
if (!count)
vblrc = 0;
vblcount = vblank->count;
diff_ns = timeval_to_ns(&tvblank) -
timeval_to_ns(&vblanktimestamp(dev, crtc, vblcount));
if (vblrc && (abs64(diff_ns) > 1000000))
store_vblank(dev, crtc, 1, &tvblank);
spin_unlock_irqrestore(&dev->vblank_time_lock, irqflags);
}
static void vblank_disable_fn(unsigned long arg)
{
struct drm_vblank_crtc *vblank = (void *)arg;
struct drm_device *dev = vblank->dev;
unsigned long irqflags;
int crtc = vblank->crtc;
if (!dev->vblank_disable_allowed)
return;
spin_lock_irqsave(&dev->vbl_lock, irqflags);
if (atomic_read(&vblank->refcount) == 0 && vblank->enabled) {
DRM_DEBUG("disabling vblank on crtc %d\n", crtc);
vblank_disable_and_save(dev, crtc);
}
spin_unlock_irqrestore(&dev->vbl_lock, irqflags);
}
void drm_vblank_cleanup(struct drm_device *dev)
{
int crtc;
if (dev->num_crtcs == 0)
return;
for (crtc = 0; crtc < dev->num_crtcs; crtc++) {
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
WARN_ON(vblank->enabled &&
drm_core_check_feature(dev, DRIVER_MODESET));
del_timer_sync(&vblank->disable_timer);
}
kfree(dev->vblank);
dev->num_crtcs = 0;
}
int drm_vblank_init(struct drm_device *dev, int num_crtcs)
{
int i, ret = -ENOMEM;
spin_lock_init(&dev->vbl_lock);
spin_lock_init(&dev->vblank_time_lock);
dev->num_crtcs = num_crtcs;
dev->vblank = kcalloc(num_crtcs, sizeof(*dev->vblank), GFP_KERNEL);
if (!dev->vblank)
goto err;
for (i = 0; i < num_crtcs; i++) {
struct drm_vblank_crtc *vblank = &dev->vblank[i];
vblank->dev = dev;
vblank->crtc = i;
init_waitqueue_head(&vblank->queue);
setup_timer(&vblank->disable_timer, vblank_disable_fn,
(unsigned long)vblank);
}
DRM_INFO("Supports vblank timestamp caching Rev 2 (21.10.2013).\n");
if (dev->driver->get_vblank_timestamp)
DRM_INFO("Driver supports precise vblank timestamp query.\n");
else
DRM_INFO("No driver support for vblank timestamp query.\n");
if (dev->vblank_disable_immediate && !dev->driver->get_vblank_timestamp) {
dev->vblank_disable_immediate = false;
DRM_INFO("Setting vblank_disable_immediate to false because "
"get_vblank_timestamp == NULL\n");
}
dev->vblank_disable_allowed = false;
return 0;
err:
dev->num_crtcs = 0;
return ret;
}
static void drm_irq_vgaarb_nokms(void *cookie, bool state)
{
struct drm_device *dev = cookie;
if (dev->driver->vgaarb_irq) {
dev->driver->vgaarb_irq(dev, state);
return;
}
if (!dev->irq_enabled)
return;
if (state) {
if (dev->driver->irq_uninstall)
dev->driver->irq_uninstall(dev);
} else {
if (dev->driver->irq_preinstall)
dev->driver->irq_preinstall(dev);
if (dev->driver->irq_postinstall)
dev->driver->irq_postinstall(dev);
}
}
int drm_irq_install(struct drm_device *dev, int irq)
{
int ret;
unsigned long sh_flags = 0;
if (!drm_core_check_feature(dev, DRIVER_HAVE_IRQ))
return -EINVAL;
if (irq == 0)
return -EINVAL;
if (!dev->dev_private)
return -EINVAL;
if (dev->irq_enabled)
return -EBUSY;
dev->irq_enabled = true;
DRM_DEBUG("irq=%d\n", irq);
if (dev->driver->irq_preinstall)
dev->driver->irq_preinstall(dev);
if (drm_core_check_feature(dev, DRIVER_IRQ_SHARED))
sh_flags = IRQF_SHARED;
ret = request_irq(irq, dev->driver->irq_handler,
sh_flags, dev->driver->name, dev);
if (ret < 0) {
dev->irq_enabled = false;
return ret;
}
if (!drm_core_check_feature(dev, DRIVER_MODESET))
vga_client_register(dev->pdev, (void *)dev, drm_irq_vgaarb_nokms, NULL);
if (dev->driver->irq_postinstall)
ret = dev->driver->irq_postinstall(dev);
if (ret < 0) {
dev->irq_enabled = false;
if (!drm_core_check_feature(dev, DRIVER_MODESET))
vga_client_register(dev->pdev, NULL, NULL, NULL);
free_irq(irq, dev);
} else {
dev->irq = irq;
}
return ret;
}
int drm_irq_uninstall(struct drm_device *dev)
{
unsigned long irqflags;
bool irq_enabled;
int i;
if (!drm_core_check_feature(dev, DRIVER_HAVE_IRQ))
return -EINVAL;
irq_enabled = dev->irq_enabled;
dev->irq_enabled = false;
if (dev->num_crtcs) {
spin_lock_irqsave(&dev->vbl_lock, irqflags);
for (i = 0; i < dev->num_crtcs; i++) {
struct drm_vblank_crtc *vblank = &dev->vblank[i];
if (!vblank->enabled)
continue;
WARN_ON(drm_core_check_feature(dev, DRIVER_MODESET));
vblank_disable_and_save(dev, i);
wake_up(&vblank->queue);
}
spin_unlock_irqrestore(&dev->vbl_lock, irqflags);
}
if (!irq_enabled)
return -EINVAL;
DRM_DEBUG("irq=%d\n", dev->irq);
if (!drm_core_check_feature(dev, DRIVER_MODESET))
vga_client_register(dev->pdev, NULL, NULL, NULL);
if (dev->driver->irq_uninstall)
dev->driver->irq_uninstall(dev);
free_irq(dev->irq, dev);
return 0;
}
int drm_control(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_control *ctl = data;
int ret = 0, irq;
if (!drm_core_check_feature(dev, DRIVER_HAVE_IRQ))
return 0;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return 0;
if (WARN_ON(!dev->pdev))
return -EINVAL;
switch (ctl->func) {
case DRM_INST_HANDLER:
irq = dev->pdev->irq;
if (dev->if_version < DRM_IF_VERSION(1, 2) &&
ctl->irq != irq)
return -EINVAL;
mutex_lock(&dev->struct_mutex);
ret = drm_irq_install(dev, irq);
mutex_unlock(&dev->struct_mutex);
return ret;
case DRM_UNINST_HANDLER:
mutex_lock(&dev->struct_mutex);
ret = drm_irq_uninstall(dev);
mutex_unlock(&dev->struct_mutex);
return ret;
default:
return -EINVAL;
}
}
void drm_calc_timestamping_constants(struct drm_crtc *crtc,
const struct drm_display_mode *mode)
{
int linedur_ns = 0, pixeldur_ns = 0, framedur_ns = 0;
int dotclock = mode->crtc_clock;
if (dotclock > 0) {
int frame_size = mode->crtc_htotal * mode->crtc_vtotal;
pixeldur_ns = 1000000 / dotclock;
linedur_ns = div_u64((u64) mode->crtc_htotal * 1000000, dotclock);
framedur_ns = div_u64((u64) frame_size * 1000000, dotclock);
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
framedur_ns /= 2;
} else
DRM_ERROR("crtc %d: Can't calculate constants, dotclock = 0!\n",
crtc->base.id);
crtc->pixeldur_ns = pixeldur_ns;
crtc->linedur_ns = linedur_ns;
crtc->framedur_ns = framedur_ns;
DRM_DEBUG("crtc %d: hwmode: htotal %d, vtotal %d, vdisplay %d\n",
crtc->base.id, mode->crtc_htotal,
mode->crtc_vtotal, mode->crtc_vdisplay);
DRM_DEBUG("crtc %d: clock %d kHz framedur %d linedur %d, pixeldur %d\n",
crtc->base.id, dotclock, framedur_ns,
linedur_ns, pixeldur_ns);
}
int drm_calc_vbltimestamp_from_scanoutpos(struct drm_device *dev, int crtc,
int *max_error,
struct timeval *vblank_time,
unsigned flags,
const struct drm_crtc *refcrtc,
const struct drm_display_mode *mode)
{
struct timeval tv_etime;
ktime_t stime, etime;
int vbl_status;
int vpos, hpos, i;
int framedur_ns, linedur_ns, pixeldur_ns, delta_ns, duration_ns;
bool invbl;
if (crtc < 0 || crtc >= dev->num_crtcs) {
DRM_ERROR("Invalid crtc %d\n", crtc);
return -EINVAL;
}
if (!dev->driver->get_scanout_position) {
DRM_ERROR("Called from driver w/o get_scanout_position()!?\n");
return -EIO;
}
framedur_ns = refcrtc->framedur_ns;
linedur_ns = refcrtc->linedur_ns;
pixeldur_ns = refcrtc->pixeldur_ns;
if (framedur_ns == 0) {
DRM_DEBUG("crtc %d: Noop due to uninitialized mode.\n", crtc);
return -EAGAIN;
}
for (i = 0; i < DRM_TIMESTAMP_MAXRETRIES; i++) {
vbl_status = dev->driver->get_scanout_position(dev, crtc, flags, &vpos,
&hpos, &stime, &etime);
if (!(vbl_status & DRM_SCANOUTPOS_VALID)) {
DRM_DEBUG("crtc %d : scanoutpos query failed [%d].\n",
crtc, vbl_status);
return -EIO;
}
duration_ns = ktime_to_ns(etime) - ktime_to_ns(stime);
if (duration_ns <= *max_error)
break;
}
if (i == DRM_TIMESTAMP_MAXRETRIES) {
DRM_DEBUG("crtc %d: Noisy timestamp %d us > %d us [%d reps].\n",
crtc, duration_ns/1000, *max_error/1000, i);
}
*max_error = duration_ns;
invbl = vbl_status & DRM_SCANOUTPOS_IN_VBLANK;
delta_ns = vpos * linedur_ns + hpos * pixeldur_ns;
if (!drm_timestamp_monotonic)
etime = ktime_mono_to_real(etime);
tv_etime = ktime_to_timeval(etime);
if (delta_ns < 0)
etime = ktime_add_ns(etime, -delta_ns);
else
etime = ktime_sub_ns(etime, delta_ns);
*vblank_time = ktime_to_timeval(etime);
DRM_DEBUG("crtc %d : v %d p(%d,%d)@ %ld.%ld -> %ld.%ld [e %d us, %d rep]\n",
crtc, (int)vbl_status, hpos, vpos,
(long)tv_etime.tv_sec, (long)tv_etime.tv_usec,
(long)vblank_time->tv_sec, (long)vblank_time->tv_usec,
duration_ns/1000, i);
vbl_status = DRM_VBLANKTIME_SCANOUTPOS_METHOD;
if (invbl)
vbl_status |= DRM_VBLANKTIME_IN_VBLANK;
return vbl_status;
}
static struct timeval get_drm_timestamp(void)
{
ktime_t now;
now = drm_timestamp_monotonic ? ktime_get() : ktime_get_real();
return ktime_to_timeval(now);
}
static bool
drm_get_last_vbltimestamp(struct drm_device *dev, int crtc,
struct timeval *tvblank, unsigned flags)
{
int ret;
int max_error = (int) drm_timestamp_precision * 1000;
if (dev->driver->get_vblank_timestamp && (max_error > 0)) {
ret = dev->driver->get_vblank_timestamp(dev, crtc, &max_error,
tvblank, flags);
if (ret > 0)
return true;
}
*tvblank = get_drm_timestamp();
return false;
}
u32 drm_vblank_count(struct drm_device *dev, int crtc)
{
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
if (WARN_ON(crtc >= dev->num_crtcs))
return 0;
return vblank->count;
}
u32 drm_crtc_vblank_count(struct drm_crtc *crtc)
{
return drm_vblank_count(crtc->dev, drm_crtc_index(crtc));
}
u32 drm_vblank_count_and_time(struct drm_device *dev, int crtc,
struct timeval *vblanktime)
{
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
u32 cur_vblank;
if (WARN_ON(crtc >= dev->num_crtcs))
return 0;
do {
cur_vblank = vblank->count;
smp_rmb();
*vblanktime = vblanktimestamp(dev, crtc, cur_vblank);
smp_rmb();
} while (cur_vblank != vblank->count);
return cur_vblank;
}
static void send_vblank_event(struct drm_device *dev,
struct drm_pending_vblank_event *e,
unsigned long seq, struct timeval *now)
{
WARN_ON_SMP(!spin_is_locked(&dev->event_lock));
e->event.sequence = seq;
e->event.tv_sec = now->tv_sec;
e->event.tv_usec = now->tv_usec;
list_add_tail(&e->base.link,
&e->base.file_priv->event_list);
wake_up_interruptible(&e->base.file_priv->event_wait);
trace_drm_vblank_event_delivered(e->base.pid, e->pipe,
e->event.sequence);
}
void drm_send_vblank_event(struct drm_device *dev, int crtc,
struct drm_pending_vblank_event *e)
{
struct timeval now;
unsigned int seq;
if (crtc >= 0) {
seq = drm_vblank_count_and_time(dev, crtc, &now);
} else {
seq = 0;
now = get_drm_timestamp();
}
e->pipe = crtc;
send_vblank_event(dev, e, seq, &now);
}
void drm_crtc_send_vblank_event(struct drm_crtc *crtc,
struct drm_pending_vblank_event *e)
{
drm_send_vblank_event(crtc->dev, drm_crtc_index(crtc), e);
}
static int drm_vblank_enable(struct drm_device *dev, int crtc)
{
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
int ret = 0;
assert_spin_locked(&dev->vbl_lock);
spin_lock(&dev->vblank_time_lock);
if (!vblank->enabled) {
ret = dev->driver->enable_vblank(dev, crtc);
DRM_DEBUG("enabling vblank on crtc %d, ret: %d\n", crtc, ret);
if (ret)
atomic_dec(&vblank->refcount);
else {
vblank->enabled = true;
drm_update_vblank_count(dev, crtc);
}
}
spin_unlock(&dev->vblank_time_lock);
return ret;
}
int drm_vblank_get(struct drm_device *dev, int crtc)
{
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
unsigned long irqflags;
int ret = 0;
if (!dev->num_crtcs)
return -EINVAL;
if (WARN_ON(crtc >= dev->num_crtcs))
return -EINVAL;
spin_lock_irqsave(&dev->vbl_lock, irqflags);
if (atomic_add_return(1, &vblank->refcount) == 1) {
ret = drm_vblank_enable(dev, crtc);
} else {
if (!vblank->enabled) {
atomic_dec(&vblank->refcount);
ret = -EINVAL;
}
}
spin_unlock_irqrestore(&dev->vbl_lock, irqflags);
return ret;
}
int drm_crtc_vblank_get(struct drm_crtc *crtc)
{
return drm_vblank_get(crtc->dev, drm_crtc_index(crtc));
}
void drm_vblank_put(struct drm_device *dev, int crtc)
{
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
if (WARN_ON(atomic_read(&vblank->refcount) == 0))
return;
if (WARN_ON(crtc >= dev->num_crtcs))
return;
if (atomic_dec_and_test(&vblank->refcount)) {
if (drm_vblank_offdelay == 0)
return;
else if (dev->vblank_disable_immediate || drm_vblank_offdelay < 0)
vblank_disable_fn((unsigned long)vblank);
else
mod_timer(&vblank->disable_timer,
jiffies + ((drm_vblank_offdelay * HZ)/1000));
}
}
void drm_crtc_vblank_put(struct drm_crtc *crtc)
{
drm_vblank_put(crtc->dev, drm_crtc_index(crtc));
}
void drm_wait_one_vblank(struct drm_device *dev, int crtc)
{
int ret;
u32 last;
ret = drm_vblank_get(dev, crtc);
if (WARN(ret, "vblank not available on crtc %i, ret=%i\n", crtc, ret))
return;
last = drm_vblank_count(dev, crtc);
ret = wait_event_timeout(dev->vblank[crtc].queue,
last != drm_vblank_count(dev, crtc),
msecs_to_jiffies(100));
WARN(ret == 0, "vblank wait timed out on crtc %i\n", crtc);
drm_vblank_put(dev, crtc);
}
void drm_crtc_wait_one_vblank(struct drm_crtc *crtc)
{
drm_wait_one_vblank(crtc->dev, drm_crtc_index(crtc));
}
void drm_vblank_off(struct drm_device *dev, int crtc)
{
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
struct drm_pending_vblank_event *e, *t;
struct timeval now;
unsigned long irqflags;
unsigned int seq;
if (WARN_ON(crtc >= dev->num_crtcs))
return;
spin_lock_irqsave(&dev->event_lock, irqflags);
spin_lock(&dev->vbl_lock);
vblank_disable_and_save(dev, crtc);
wake_up(&vblank->queue);
if (!vblank->inmodeset) {
atomic_inc(&vblank->refcount);
vblank->inmodeset = 1;
}
spin_unlock(&dev->vbl_lock);
seq = drm_vblank_count_and_time(dev, crtc, &now);
list_for_each_entry_safe(e, t, &dev->vblank_event_list, base.link) {
if (e->pipe != crtc)
continue;
DRM_DEBUG("Sending premature vblank event on disable: \
wanted %d, current %d\n",
e->event.sequence, seq);
list_del(&e->base.link);
drm_vblank_put(dev, e->pipe);
send_vblank_event(dev, e, seq, &now);
}
spin_unlock_irqrestore(&dev->event_lock, irqflags);
}
void drm_crtc_vblank_off(struct drm_crtc *crtc)
{
drm_vblank_off(crtc->dev, drm_crtc_index(crtc));
}
void drm_crtc_vblank_reset(struct drm_crtc *drm_crtc)
{
struct drm_device *dev = drm_crtc->dev;
unsigned long irqflags;
int crtc = drm_crtc_index(drm_crtc);
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
spin_lock_irqsave(&dev->vbl_lock, irqflags);
if (!vblank->inmodeset) {
atomic_inc(&vblank->refcount);
vblank->inmodeset = 1;
}
spin_unlock_irqrestore(&dev->vbl_lock, irqflags);
WARN_ON(!list_empty(&dev->vblank_event_list));
}
void drm_vblank_on(struct drm_device *dev, int crtc)
{
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
unsigned long irqflags;
if (WARN_ON(crtc >= dev->num_crtcs))
return;
spin_lock_irqsave(&dev->vbl_lock, irqflags);
if (vblank->inmodeset) {
atomic_dec(&vblank->refcount);
vblank->inmodeset = 0;
}
vblank->last =
(dev->driver->get_vblank_counter(dev, crtc) - 1) &
dev->max_vblank_count;
if (atomic_read(&vblank->refcount) != 0 ||
(!dev->vblank_disable_immediate && drm_vblank_offdelay == 0))
WARN_ON(drm_vblank_enable(dev, crtc));
spin_unlock_irqrestore(&dev->vbl_lock, irqflags);
}
void drm_crtc_vblank_on(struct drm_crtc *crtc)
{
drm_vblank_on(crtc->dev, drm_crtc_index(crtc));
}
void drm_vblank_pre_modeset(struct drm_device *dev, int crtc)
{
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
if (!dev->num_crtcs)
return;
if (WARN_ON(crtc >= dev->num_crtcs))
return;
if (!vblank->inmodeset) {
vblank->inmodeset = 0x1;
if (drm_vblank_get(dev, crtc) == 0)
vblank->inmodeset |= 0x2;
}
}
void drm_vblank_post_modeset(struct drm_device *dev, int crtc)
{
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
unsigned long irqflags;
if (!dev->num_crtcs)
return;
if (vblank->inmodeset) {
spin_lock_irqsave(&dev->vbl_lock, irqflags);
dev->vblank_disable_allowed = true;
spin_unlock_irqrestore(&dev->vbl_lock, irqflags);
if (vblank->inmodeset & 0x2)
drm_vblank_put(dev, crtc);
vblank->inmodeset = 0;
}
}
int drm_modeset_ctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_modeset_ctl *modeset = data;
unsigned int crtc;
if (!dev->num_crtcs)
return 0;
if (drm_core_check_feature(dev, DRIVER_MODESET))
return 0;
crtc = modeset->crtc;
if (crtc >= dev->num_crtcs)
return -EINVAL;
switch (modeset->cmd) {
case _DRM_PRE_MODESET:
drm_vblank_pre_modeset(dev, crtc);
break;
case _DRM_POST_MODESET:
drm_vblank_post_modeset(dev, crtc);
break;
default:
return -EINVAL;
}
return 0;
}
static int drm_queue_vblank_event(struct drm_device *dev, int pipe,
union drm_wait_vblank *vblwait,
struct drm_file *file_priv)
{
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
struct drm_pending_vblank_event *e;
struct timeval now;
unsigned long flags;
unsigned int seq;
int ret;
e = kzalloc(sizeof(*e), GFP_KERNEL);
if (e == NULL) {
ret = -ENOMEM;
goto err_put;
}
e->pipe = pipe;
e->base.pid = current->pid;
e->event.base.type = DRM_EVENT_VBLANK;
e->event.base.length = sizeof(e->event);
e->event.user_data = vblwait->request.signal;
e->base.event = &e->event.base;
e->base.file_priv = file_priv;
e->base.destroy = (void (*) (struct drm_pending_event *)) kfree;
spin_lock_irqsave(&dev->event_lock, flags);
if (!vblank->enabled) {
ret = -EINVAL;
goto err_unlock;
}
if (file_priv->event_space < sizeof(e->event)) {
ret = -EBUSY;
goto err_unlock;
}
file_priv->event_space -= sizeof(e->event);
seq = drm_vblank_count_and_time(dev, pipe, &now);
if ((vblwait->request.type & _DRM_VBLANK_NEXTONMISS) &&
(seq - vblwait->request.sequence) <= (1 << 23)) {
vblwait->request.sequence = seq + 1;
vblwait->reply.sequence = vblwait->request.sequence;
}
DRM_DEBUG("event on vblank count %d, current %d, crtc %d\n",
vblwait->request.sequence, seq, pipe);
trace_drm_vblank_event_queued(current->pid, pipe,
vblwait->request.sequence);
e->event.sequence = vblwait->request.sequence;
if ((seq - vblwait->request.sequence) <= (1 << 23)) {
drm_vblank_put(dev, pipe);
send_vblank_event(dev, e, seq, &now);
vblwait->reply.sequence = seq;
} else {
list_add_tail(&e->base.link, &dev->vblank_event_list);
vblwait->reply.sequence = vblwait->request.sequence;
}
spin_unlock_irqrestore(&dev->event_lock, flags);
return 0;
err_unlock:
spin_unlock_irqrestore(&dev->event_lock, flags);
kfree(e);
err_put:
drm_vblank_put(dev, pipe);
return ret;
}
int drm_wait_vblank(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_vblank_crtc *vblank;
union drm_wait_vblank *vblwait = data;
int ret;
unsigned int flags, seq, crtc, high_crtc;
if (!dev->irq_enabled)
return -EINVAL;
if (vblwait->request.type & _DRM_VBLANK_SIGNAL)
return -EINVAL;
if (vblwait->request.type &
~(_DRM_VBLANK_TYPES_MASK | _DRM_VBLANK_FLAGS_MASK |
_DRM_VBLANK_HIGH_CRTC_MASK)) {
DRM_ERROR("Unsupported type value 0x%x, supported mask 0x%x\n",
vblwait->request.type,
(_DRM_VBLANK_TYPES_MASK | _DRM_VBLANK_FLAGS_MASK |
_DRM_VBLANK_HIGH_CRTC_MASK));
return -EINVAL;
}
flags = vblwait->request.type & _DRM_VBLANK_FLAGS_MASK;
high_crtc = (vblwait->request.type & _DRM_VBLANK_HIGH_CRTC_MASK);
if (high_crtc)
crtc = high_crtc >> _DRM_VBLANK_HIGH_CRTC_SHIFT;
else
crtc = flags & _DRM_VBLANK_SECONDARY ? 1 : 0;
if (crtc >= dev->num_crtcs)
return -EINVAL;
vblank = &dev->vblank[crtc];
ret = drm_vblank_get(dev, crtc);
if (ret) {
DRM_DEBUG("failed to acquire vblank counter, %d\n", ret);
return ret;
}
seq = drm_vblank_count(dev, crtc);
switch (vblwait->request.type & _DRM_VBLANK_TYPES_MASK) {
case _DRM_VBLANK_RELATIVE:
vblwait->request.sequence += seq;
vblwait->request.type &= ~_DRM_VBLANK_RELATIVE;
case _DRM_VBLANK_ABSOLUTE:
break;
default:
ret = -EINVAL;
goto done;
}
if (flags & _DRM_VBLANK_EVENT) {
return drm_queue_vblank_event(dev, crtc, vblwait, file_priv);
}
if ((flags & _DRM_VBLANK_NEXTONMISS) &&
(seq - vblwait->request.sequence) <= (1<<23)) {
vblwait->request.sequence = seq + 1;
}
DRM_DEBUG("waiting on vblank count %d, crtc %d\n",
vblwait->request.sequence, crtc);
vblank->last_wait = vblwait->request.sequence;
DRM_WAIT_ON(ret, vblank->queue, 3 * HZ,
(((drm_vblank_count(dev, crtc) -
vblwait->request.sequence) <= (1 << 23)) ||
!vblank->enabled ||
!dev->irq_enabled));
if (ret != -EINTR) {
struct timeval now;
vblwait->reply.sequence = drm_vblank_count_and_time(dev, crtc, &now);
vblwait->reply.tval_sec = now.tv_sec;
vblwait->reply.tval_usec = now.tv_usec;
DRM_DEBUG("returning %d to client\n",
vblwait->reply.sequence);
} else {
DRM_DEBUG("vblank wait interrupted by signal\n");
}
done:
drm_vblank_put(dev, crtc);
return ret;
}
static void drm_handle_vblank_events(struct drm_device *dev, int crtc)
{
struct drm_pending_vblank_event *e, *t;
struct timeval now;
unsigned int seq;
assert_spin_locked(&dev->event_lock);
seq = drm_vblank_count_and_time(dev, crtc, &now);
list_for_each_entry_safe(e, t, &dev->vblank_event_list, base.link) {
if (e->pipe != crtc)
continue;
if ((seq - e->event.sequence) > (1<<23))
continue;
DRM_DEBUG("vblank event on %d, current %d\n",
e->event.sequence, seq);
list_del(&e->base.link);
drm_vblank_put(dev, e->pipe);
send_vblank_event(dev, e, seq, &now);
}
trace_drm_vblank_event(crtc, seq);
}
bool drm_handle_vblank(struct drm_device *dev, int crtc)
{
struct drm_vblank_crtc *vblank = &dev->vblank[crtc];
u32 vblcount;
s64 diff_ns;
struct timeval tvblank;
unsigned long irqflags;
if (WARN_ON_ONCE(!dev->num_crtcs))
return false;
if (WARN_ON(crtc >= dev->num_crtcs))
return false;
spin_lock_irqsave(&dev->event_lock, irqflags);
spin_lock(&dev->vblank_time_lock);
if (!vblank->enabled) {
spin_unlock(&dev->vblank_time_lock);
spin_unlock_irqrestore(&dev->event_lock, irqflags);
return false;
}
vblcount = vblank->count;
drm_get_last_vbltimestamp(dev, crtc, &tvblank, DRM_CALLED_FROM_VBLIRQ);
diff_ns = timeval_to_ns(&tvblank) -
timeval_to_ns(&vblanktimestamp(dev, crtc, vblcount));
if (abs64(diff_ns) > DRM_REDUNDANT_VBLIRQ_THRESH_NS)
store_vblank(dev, crtc, 1, &tvblank);
else
DRM_DEBUG("crtc %d: Redundant vblirq ignored. diff_ns = %d\n",
crtc, (int) diff_ns);
spin_unlock(&dev->vblank_time_lock);
wake_up(&vblank->queue);
drm_handle_vblank_events(dev, crtc);
spin_unlock_irqrestore(&dev->event_lock, irqflags);
return true;
}
bool drm_crtc_handle_vblank(struct drm_crtc *crtc)
{
return drm_handle_vblank(crtc->dev, drm_crtc_index(crtc));
}
