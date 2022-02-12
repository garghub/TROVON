static void store_vblank(struct drm_device *dev, unsigned int pipe,
u32 vblank_count_inc,
struct timeval *t_vblank, u32 last)
{
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
assert_spin_locked(&dev->vblank_time_lock);
vblank->last = last;
write_seqlock(&vblank->seqlock);
vblank->time = *t_vblank;
vblank->count += vblank_count_inc;
write_sequnlock(&vblank->seqlock);
}
static void drm_reset_vblank_timestamp(struct drm_device *dev, unsigned int pipe)
{
u32 cur_vblank;
bool rc;
struct timeval t_vblank;
int count = DRM_TIMESTAMP_MAXRETRIES;
spin_lock(&dev->vblank_time_lock);
do {
cur_vblank = dev->driver->get_vblank_counter(dev, pipe);
rc = drm_get_last_vbltimestamp(dev, pipe, &t_vblank, 0);
} while (cur_vblank != dev->driver->get_vblank_counter(dev, pipe) && --count > 0);
if (!rc)
t_vblank = (struct timeval) {0, 0};
store_vblank(dev, pipe, 1, &t_vblank, cur_vblank);
spin_unlock(&dev->vblank_time_lock);
}
static void drm_update_vblank_count(struct drm_device *dev, unsigned int pipe,
unsigned long flags)
{
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
u32 cur_vblank, diff;
bool rc;
struct timeval t_vblank;
int count = DRM_TIMESTAMP_MAXRETRIES;
int framedur_ns = vblank->framedur_ns;
do {
cur_vblank = dev->driver->get_vblank_counter(dev, pipe);
rc = drm_get_last_vbltimestamp(dev, pipe, &t_vblank, flags);
} while (cur_vblank != dev->driver->get_vblank_counter(dev, pipe) && --count > 0);
if (dev->max_vblank_count != 0) {
diff = (cur_vblank - vblank->last) & dev->max_vblank_count;
} else if (rc && framedur_ns) {
const struct timeval *t_old;
u64 diff_ns;
t_old = &vblank->time;
diff_ns = timeval_to_ns(&t_vblank) - timeval_to_ns(t_old);
diff = DIV_ROUND_CLOSEST_ULL(diff_ns, framedur_ns);
if (diff == 0 && flags & DRM_CALLED_FROM_VBLIRQ)
DRM_DEBUG_VBL("crtc %u: Redundant vblirq ignored."
" diff_ns = %lld, framedur_ns = %d)\n",
pipe, (long long) diff_ns, framedur_ns);
} else {
diff = (flags & DRM_CALLED_FROM_VBLIRQ) != 0;
}
if (diff > 1 && (vblank->inmodeset & 0x2)) {
DRM_DEBUG_VBL("clamping vblank bump to 1 on crtc %u: diffr=%u"
" due to pre-modeset.\n", pipe, diff);
diff = 1;
}
DRM_DEBUG_VBL("updating vblank count on crtc %u:"
" current=%u, diff=%u, hw=%u hw_last=%u\n",
pipe, vblank->count, diff, cur_vblank, vblank->last);
if (diff == 0) {
WARN_ON_ONCE(cur_vblank != vblank->last);
return;
}
if (!rc && (flags & DRM_CALLED_FROM_VBLIRQ) == 0)
t_vblank = (struct timeval) {0, 0};
store_vblank(dev, pipe, diff, &t_vblank, cur_vblank);
}
static u32 drm_vblank_count(struct drm_device *dev, unsigned int pipe)
{
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
if (WARN_ON(pipe >= dev->num_crtcs))
return 0;
return vblank->count;
}
u32 drm_accurate_vblank_count(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
unsigned int pipe = drm_crtc_index(crtc);
u32 vblank;
unsigned long flags;
WARN(!dev->driver->get_vblank_timestamp,
"This function requires support for accurate vblank timestamps.");
spin_lock_irqsave(&dev->vblank_time_lock, flags);
drm_update_vblank_count(dev, pipe, 0);
vblank = drm_vblank_count(dev, pipe);
spin_unlock_irqrestore(&dev->vblank_time_lock, flags);
return vblank;
}
static void vblank_disable_and_save(struct drm_device *dev, unsigned int pipe)
{
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
unsigned long irqflags;
spin_lock_irqsave(&dev->vblank_time_lock, irqflags);
if (vblank->enabled) {
dev->driver->disable_vblank(dev, pipe);
vblank->enabled = false;
}
drm_update_vblank_count(dev, pipe, 0);
spin_unlock_irqrestore(&dev->vblank_time_lock, irqflags);
}
static void vblank_disable_fn(unsigned long arg)
{
struct drm_vblank_crtc *vblank = (void *)arg;
struct drm_device *dev = vblank->dev;
unsigned int pipe = vblank->pipe;
unsigned long irqflags;
spin_lock_irqsave(&dev->vbl_lock, irqflags);
if (atomic_read(&vblank->refcount) == 0 && vblank->enabled) {
DRM_DEBUG("disabling vblank on crtc %u\n", pipe);
vblank_disable_and_save(dev, pipe);
}
spin_unlock_irqrestore(&dev->vbl_lock, irqflags);
}
void drm_vblank_cleanup(struct drm_device *dev)
{
unsigned int pipe;
if (dev->num_crtcs == 0)
return;
for (pipe = 0; pipe < dev->num_crtcs; pipe++) {
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
WARN_ON(vblank->enabled &&
drm_core_check_feature(dev, DRIVER_MODESET));
del_timer_sync(&vblank->disable_timer);
}
kfree(dev->vblank);
dev->num_crtcs = 0;
}
int drm_vblank_init(struct drm_device *dev, unsigned int num_crtcs)
{
int ret = -ENOMEM;
unsigned int i;
spin_lock_init(&dev->vbl_lock);
spin_lock_init(&dev->vblank_time_lock);
dev->num_crtcs = num_crtcs;
dev->vblank = kcalloc(num_crtcs, sizeof(*dev->vblank), GFP_KERNEL);
if (!dev->vblank)
goto err;
for (i = 0; i < num_crtcs; i++) {
struct drm_vblank_crtc *vblank = &dev->vblank[i];
vblank->dev = dev;
vblank->pipe = i;
init_waitqueue_head(&vblank->queue);
setup_timer(&vblank->disable_timer, vblank_disable_fn,
(unsigned long)vblank);
seqlock_init(&vblank->seqlock);
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
return 0;
err:
dev->num_crtcs = 0;
return ret;
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
if (dev->driver->irq_postinstall)
ret = dev->driver->irq_postinstall(dev);
if (ret < 0) {
dev->irq_enabled = false;
if (drm_core_check_feature(dev, DRIVER_LEGACY))
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
if (drm_core_check_feature(dev, DRIVER_LEGACY))
vga_client_register(dev->pdev, NULL, NULL, NULL);
if (dev->driver->irq_uninstall)
dev->driver->irq_uninstall(dev);
free_irq(dev->irq, dev);
return 0;
}
int drm_legacy_irq_control(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_control *ctl = data;
int ret = 0, irq;
if (!drm_core_check_feature(dev, DRIVER_HAVE_IRQ))
return 0;
if (!drm_core_check_feature(dev, DRIVER_LEGACY))
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
struct drm_device *dev = crtc->dev;
unsigned int pipe = drm_crtc_index(crtc);
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
int linedur_ns = 0, framedur_ns = 0;
int dotclock = mode->crtc_clock;
if (!dev->num_crtcs)
return;
if (WARN_ON(pipe >= dev->num_crtcs))
return;
if (dotclock > 0) {
int frame_size = mode->crtc_htotal * mode->crtc_vtotal;
linedur_ns = div_u64((u64) mode->crtc_htotal * 1000000, dotclock);
framedur_ns = div_u64((u64) frame_size * 1000000, dotclock);
if (mode->flags & DRM_MODE_FLAG_INTERLACE)
framedur_ns /= 2;
} else
DRM_ERROR("crtc %u: Can't calculate constants, dotclock = 0!\n",
crtc->base.id);
vblank->linedur_ns = linedur_ns;
vblank->framedur_ns = framedur_ns;
DRM_DEBUG("crtc %u: hwmode: htotal %d, vtotal %d, vdisplay %d\n",
crtc->base.id, mode->crtc_htotal,
mode->crtc_vtotal, mode->crtc_vdisplay);
DRM_DEBUG("crtc %u: clock %d kHz framedur %d linedur %d\n",
crtc->base.id, dotclock, framedur_ns, linedur_ns);
}
int drm_calc_vbltimestamp_from_scanoutpos(struct drm_device *dev,
unsigned int pipe,
int *max_error,
struct timeval *vblank_time,
unsigned flags,
const struct drm_display_mode *mode)
{
struct timeval tv_etime;
ktime_t stime, etime;
unsigned int vbl_status;
int ret = DRM_VBLANKTIME_SCANOUTPOS_METHOD;
int vpos, hpos, i;
int delta_ns, duration_ns;
if (pipe >= dev->num_crtcs) {
DRM_ERROR("Invalid crtc %u\n", pipe);
return -EINVAL;
}
if (!dev->driver->get_scanout_position) {
DRM_ERROR("Called from driver w/o get_scanout_position()!?\n");
return -EIO;
}
if (mode->crtc_clock == 0) {
DRM_DEBUG("crtc %u: Noop due to uninitialized mode.\n", pipe);
return -EAGAIN;
}
for (i = 0; i < DRM_TIMESTAMP_MAXRETRIES; i++) {
vbl_status = dev->driver->get_scanout_position(dev, pipe, flags,
&vpos, &hpos,
&stime, &etime,
mode);
if (!(vbl_status & DRM_SCANOUTPOS_VALID)) {
DRM_DEBUG("crtc %u : scanoutpos query failed [0x%x].\n",
pipe, vbl_status);
return -EIO;
}
duration_ns = ktime_to_ns(etime) - ktime_to_ns(stime);
if (duration_ns <= *max_error)
break;
}
if (i == DRM_TIMESTAMP_MAXRETRIES) {
DRM_DEBUG("crtc %u: Noisy timestamp %d us > %d us [%d reps].\n",
pipe, duration_ns/1000, *max_error/1000, i);
}
*max_error = duration_ns;
if (vbl_status & DRM_SCANOUTPOS_IN_VBLANK)
ret |= DRM_VBLANKTIME_IN_VBLANK;
delta_ns = div_s64(1000000LL * (vpos * mode->crtc_htotal + hpos),
mode->crtc_clock);
if (!drm_timestamp_monotonic)
etime = ktime_mono_to_real(etime);
tv_etime = ktime_to_timeval(etime);
etime = ktime_sub_ns(etime, delta_ns);
*vblank_time = ktime_to_timeval(etime);
DRM_DEBUG_VBL("crtc %u : v 0x%x p(%d,%d)@ %ld.%ld -> %ld.%ld [e %d us, %d rep]\n",
pipe, vbl_status, hpos, vpos,
(long)tv_etime.tv_sec, (long)tv_etime.tv_usec,
(long)vblank_time->tv_sec, (long)vblank_time->tv_usec,
duration_ns/1000, i);
return ret;
}
static struct timeval get_drm_timestamp(void)
{
ktime_t now;
now = drm_timestamp_monotonic ? ktime_get() : ktime_get_real();
return ktime_to_timeval(now);
}
static bool
drm_get_last_vbltimestamp(struct drm_device *dev, unsigned int pipe,
struct timeval *tvblank, unsigned flags)
{
int ret;
int max_error = (int) drm_timestamp_precision * 1000;
if (dev->driver->get_vblank_timestamp && (max_error > 0)) {
ret = dev->driver->get_vblank_timestamp(dev, pipe, &max_error,
tvblank, flags);
if (ret > 0)
return true;
}
*tvblank = get_drm_timestamp();
return false;
}
u32 drm_crtc_vblank_count(struct drm_crtc *crtc)
{
return drm_vblank_count(crtc->dev, drm_crtc_index(crtc));
}
static u32 drm_vblank_count_and_time(struct drm_device *dev, unsigned int pipe,
struct timeval *vblanktime)
{
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
u32 vblank_count;
unsigned int seq;
if (WARN_ON(pipe >= dev->num_crtcs)) {
*vblanktime = (struct timeval) { 0 };
return 0;
}
do {
seq = read_seqbegin(&vblank->seqlock);
vblank_count = vblank->count;
*vblanktime = vblank->time;
} while (read_seqretry(&vblank->seqlock, seq));
return vblank_count;
}
u32 drm_crtc_vblank_count_and_time(struct drm_crtc *crtc,
struct timeval *vblanktime)
{
return drm_vblank_count_and_time(crtc->dev, drm_crtc_index(crtc),
vblanktime);
}
static void send_vblank_event(struct drm_device *dev,
struct drm_pending_vblank_event *e,
unsigned long seq, struct timeval *now)
{
e->event.sequence = seq;
e->event.tv_sec = now->tv_sec;
e->event.tv_usec = now->tv_usec;
trace_drm_vblank_event_delivered(e->base.pid, e->pipe,
e->event.sequence);
drm_send_event_locked(dev, &e->base);
}
void drm_crtc_arm_vblank_event(struct drm_crtc *crtc,
struct drm_pending_vblank_event *e)
{
struct drm_device *dev = crtc->dev;
unsigned int pipe = drm_crtc_index(crtc);
assert_spin_locked(&dev->event_lock);
e->pipe = pipe;
e->event.sequence = drm_vblank_count(dev, pipe);
list_add_tail(&e->base.link, &dev->vblank_event_list);
}
void drm_crtc_send_vblank_event(struct drm_crtc *crtc,
struct drm_pending_vblank_event *e)
{
struct drm_device *dev = crtc->dev;
unsigned int seq, pipe = drm_crtc_index(crtc);
struct timeval now;
if (dev->num_crtcs > 0) {
seq = drm_vblank_count_and_time(dev, pipe, &now);
} else {
seq = 0;
now = get_drm_timestamp();
}
e->pipe = pipe;
send_vblank_event(dev, e, seq, &now);
}
static int drm_vblank_enable(struct drm_device *dev, unsigned int pipe)
{
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
int ret = 0;
assert_spin_locked(&dev->vbl_lock);
spin_lock(&dev->vblank_time_lock);
if (!vblank->enabled) {
ret = dev->driver->enable_vblank(dev, pipe);
DRM_DEBUG("enabling vblank on crtc %u, ret: %d\n", pipe, ret);
if (ret)
atomic_dec(&vblank->refcount);
else {
vblank->enabled = true;
drm_update_vblank_count(dev, pipe, 0);
}
}
spin_unlock(&dev->vblank_time_lock);
return ret;
}
static int drm_vblank_get(struct drm_device *dev, unsigned int pipe)
{
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
unsigned long irqflags;
int ret = 0;
if (!dev->num_crtcs)
return -EINVAL;
if (WARN_ON(pipe >= dev->num_crtcs))
return -EINVAL;
spin_lock_irqsave(&dev->vbl_lock, irqflags);
if (atomic_add_return(1, &vblank->refcount) == 1) {
ret = drm_vblank_enable(dev, pipe);
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
static void drm_vblank_put(struct drm_device *dev, unsigned int pipe)
{
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
if (WARN_ON(pipe >= dev->num_crtcs))
return;
if (WARN_ON(atomic_read(&vblank->refcount) == 0))
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
void drm_wait_one_vblank(struct drm_device *dev, unsigned int pipe)
{
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
int ret;
u32 last;
if (WARN_ON(pipe >= dev->num_crtcs))
return;
ret = drm_vblank_get(dev, pipe);
if (WARN(ret, "vblank not available on crtc %i, ret=%i\n", pipe, ret))
return;
last = drm_vblank_count(dev, pipe);
ret = wait_event_timeout(vblank->queue,
last != drm_vblank_count(dev, pipe),
msecs_to_jiffies(100));
WARN(ret == 0, "vblank wait timed out on crtc %i\n", pipe);
drm_vblank_put(dev, pipe);
}
void drm_crtc_wait_one_vblank(struct drm_crtc *crtc)
{
drm_wait_one_vblank(crtc->dev, drm_crtc_index(crtc));
}
void drm_crtc_vblank_off(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
unsigned int pipe = drm_crtc_index(crtc);
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
struct drm_pending_vblank_event *e, *t;
struct timeval now;
unsigned long irqflags;
unsigned int seq;
if (WARN_ON(pipe >= dev->num_crtcs))
return;
spin_lock_irqsave(&dev->event_lock, irqflags);
spin_lock(&dev->vbl_lock);
DRM_DEBUG_VBL("crtc %d, vblank enabled %d, inmodeset %d\n",
pipe, vblank->enabled, vblank->inmodeset);
if (drm_core_check_feature(dev, DRIVER_ATOMIC) || !vblank->inmodeset)
vblank_disable_and_save(dev, pipe);
wake_up(&vblank->queue);
if (!vblank->inmodeset) {
atomic_inc(&vblank->refcount);
vblank->inmodeset = 1;
}
spin_unlock(&dev->vbl_lock);
seq = drm_vblank_count_and_time(dev, pipe, &now);
list_for_each_entry_safe(e, t, &dev->vblank_event_list, base.link) {
if (e->pipe != pipe)
continue;
DRM_DEBUG("Sending premature vblank event on disable: "
"wanted %u, current %u\n",
e->event.sequence, seq);
list_del(&e->base.link);
drm_vblank_put(dev, pipe);
send_vblank_event(dev, e, seq, &now);
}
spin_unlock_irqrestore(&dev->event_lock, irqflags);
}
void drm_crtc_vblank_reset(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
unsigned long irqflags;
unsigned int pipe = drm_crtc_index(crtc);
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
spin_lock_irqsave(&dev->vbl_lock, irqflags);
if (!vblank->inmodeset) {
atomic_inc(&vblank->refcount);
vblank->inmodeset = 1;
}
spin_unlock_irqrestore(&dev->vbl_lock, irqflags);
WARN_ON(!list_empty(&dev->vblank_event_list));
}
void drm_crtc_vblank_on(struct drm_crtc *crtc)
{
struct drm_device *dev = crtc->dev;
unsigned int pipe = drm_crtc_index(crtc);
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
unsigned long irqflags;
if (WARN_ON(pipe >= dev->num_crtcs))
return;
spin_lock_irqsave(&dev->vbl_lock, irqflags);
DRM_DEBUG_VBL("crtc %d, vblank enabled %d, inmodeset %d\n",
pipe, vblank->enabled, vblank->inmodeset);
if (vblank->inmodeset) {
atomic_dec(&vblank->refcount);
vblank->inmodeset = 0;
}
drm_reset_vblank_timestamp(dev, pipe);
if (atomic_read(&vblank->refcount) != 0 || drm_vblank_offdelay == 0)
WARN_ON(drm_vblank_enable(dev, pipe));
spin_unlock_irqrestore(&dev->vbl_lock, irqflags);
}
static void drm_legacy_vblank_pre_modeset(struct drm_device *dev,
unsigned int pipe)
{
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
if (!dev->num_crtcs)
return;
if (WARN_ON(pipe >= dev->num_crtcs))
return;
if (!vblank->inmodeset) {
vblank->inmodeset = 0x1;
if (drm_vblank_get(dev, pipe) == 0)
vblank->inmodeset |= 0x2;
}
}
static void drm_legacy_vblank_post_modeset(struct drm_device *dev,
unsigned int pipe)
{
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
unsigned long irqflags;
if (!dev->num_crtcs)
return;
if (WARN_ON(pipe >= dev->num_crtcs))
return;
if (vblank->inmodeset) {
spin_lock_irqsave(&dev->vbl_lock, irqflags);
drm_reset_vblank_timestamp(dev, pipe);
spin_unlock_irqrestore(&dev->vbl_lock, irqflags);
if (vblank->inmodeset & 0x2)
drm_vblank_put(dev, pipe);
vblank->inmodeset = 0;
}
}
int drm_legacy_modeset_ctl(struct drm_device *dev, void *data,
struct drm_file *file_priv)
{
struct drm_modeset_ctl *modeset = data;
unsigned int pipe;
if (!dev->num_crtcs)
return 0;
if (!drm_core_check_feature(dev, DRIVER_LEGACY))
return 0;
pipe = modeset->crtc;
if (pipe >= dev->num_crtcs)
return -EINVAL;
switch (modeset->cmd) {
case _DRM_PRE_MODESET:
drm_legacy_vblank_pre_modeset(dev, pipe);
break;
case _DRM_POST_MODESET:
drm_legacy_vblank_post_modeset(dev, pipe);
break;
default:
return -EINVAL;
}
return 0;
}
static int drm_queue_vblank_event(struct drm_device *dev, unsigned int pipe,
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
spin_lock_irqsave(&dev->event_lock, flags);
if (!vblank->enabled) {
ret = -EINVAL;
goto err_unlock;
}
ret = drm_event_reserve_init_locked(dev, file_priv, &e->base,
&e->event.base);
if (ret)
goto err_unlock;
seq = drm_vblank_count_and_time(dev, pipe, &now);
DRM_DEBUG("event on vblank count %u, current %u, crtc %u\n",
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
unsigned int flags, seq, pipe, high_pipe;
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
high_pipe = (vblwait->request.type & _DRM_VBLANK_HIGH_CRTC_MASK);
if (high_pipe)
pipe = high_pipe >> _DRM_VBLANK_HIGH_CRTC_SHIFT;
else
pipe = flags & _DRM_VBLANK_SECONDARY ? 1 : 0;
if (pipe >= dev->num_crtcs)
return -EINVAL;
vblank = &dev->vblank[pipe];
ret = drm_vblank_get(dev, pipe);
if (ret) {
DRM_DEBUG("failed to acquire vblank counter, %d\n", ret);
return ret;
}
seq = drm_vblank_count(dev, pipe);
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
if ((flags & _DRM_VBLANK_NEXTONMISS) &&
(seq - vblwait->request.sequence) <= (1 << 23)) {
vblwait->request.sequence = seq + 1;
}
if (flags & _DRM_VBLANK_EVENT) {
return drm_queue_vblank_event(dev, pipe, vblwait, file_priv);
}
DRM_DEBUG("waiting on vblank count %u, crtc %u\n",
vblwait->request.sequence, pipe);
DRM_WAIT_ON(ret, vblank->queue, 3 * HZ,
(((drm_vblank_count(dev, pipe) -
vblwait->request.sequence) <= (1 << 23)) ||
!vblank->enabled ||
!dev->irq_enabled));
if (ret != -EINTR) {
struct timeval now;
vblwait->reply.sequence = drm_vblank_count_and_time(dev, pipe, &now);
vblwait->reply.tval_sec = now.tv_sec;
vblwait->reply.tval_usec = now.tv_usec;
DRM_DEBUG("returning %u to client\n",
vblwait->reply.sequence);
} else {
DRM_DEBUG("vblank wait interrupted by signal\n");
}
done:
drm_vblank_put(dev, pipe);
return ret;
}
static void drm_handle_vblank_events(struct drm_device *dev, unsigned int pipe)
{
struct drm_pending_vblank_event *e, *t;
struct timeval now;
unsigned int seq;
assert_spin_locked(&dev->event_lock);
seq = drm_vblank_count_and_time(dev, pipe, &now);
list_for_each_entry_safe(e, t, &dev->vblank_event_list, base.link) {
if (e->pipe != pipe)
continue;
if ((seq - e->event.sequence) > (1<<23))
continue;
DRM_DEBUG("vblank event on %u, current %u\n",
e->event.sequence, seq);
list_del(&e->base.link);
drm_vblank_put(dev, pipe);
send_vblank_event(dev, e, seq, &now);
}
trace_drm_vblank_event(pipe, seq);
}
bool drm_handle_vblank(struct drm_device *dev, unsigned int pipe)
{
struct drm_vblank_crtc *vblank = &dev->vblank[pipe];
unsigned long irqflags;
if (WARN_ON_ONCE(!dev->num_crtcs))
return false;
if (WARN_ON(pipe >= dev->num_crtcs))
return false;
spin_lock_irqsave(&dev->event_lock, irqflags);
spin_lock(&dev->vblank_time_lock);
if (!vblank->enabled) {
spin_unlock(&dev->vblank_time_lock);
spin_unlock_irqrestore(&dev->event_lock, irqflags);
return false;
}
drm_update_vblank_count(dev, pipe, DRM_CALLED_FROM_VBLIRQ);
spin_unlock(&dev->vblank_time_lock);
wake_up(&vblank->queue);
drm_handle_vblank_events(dev, pipe);
spin_unlock_irqrestore(&dev->event_lock, irqflags);
return true;
}
bool drm_crtc_handle_vblank(struct drm_crtc *crtc)
{
return drm_handle_vblank(crtc->dev, drm_crtc_index(crtc));
}
u32 drm_vblank_no_hw_counter(struct drm_device *dev, unsigned int pipe)
{
WARN_ON_ONCE(dev->max_vblank_count != 0);
return 0;
}
