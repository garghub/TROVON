static bool
ipehr_is_semaphore_wait(struct intel_engine_cs *engine, u32 ipehr)
{
if (INTEL_GEN(engine->i915) >= 8) {
return (ipehr >> 23) == 0x1c;
} else {
ipehr &= ~MI_SEMAPHORE_SYNC_MASK;
return ipehr == (MI_SEMAPHORE_MBOX | MI_SEMAPHORE_COMPARE |
MI_SEMAPHORE_REGISTER);
}
}
static struct intel_engine_cs *
semaphore_wait_to_signaller_ring(struct intel_engine_cs *engine, u32 ipehr,
u64 offset)
{
struct drm_i915_private *dev_priv = engine->i915;
struct intel_engine_cs *signaller;
enum intel_engine_id id;
if (INTEL_GEN(dev_priv) >= 8) {
for_each_engine(signaller, dev_priv, id) {
if (engine == signaller)
continue;
if (offset == signaller->semaphore.signal_ggtt[engine->hw_id])
return signaller;
}
} else {
u32 sync_bits = ipehr & MI_SEMAPHORE_SYNC_MASK;
for_each_engine(signaller, dev_priv, id) {
if(engine == signaller)
continue;
if (sync_bits == signaller->semaphore.mbox.wait[engine->hw_id])
return signaller;
}
}
DRM_DEBUG_DRIVER("No signaller ring found for %s, ipehr 0x%08x, offset 0x%016llx\n",
engine->name, ipehr, offset);
return ERR_PTR(-ENODEV);
}
static struct intel_engine_cs *
semaphore_waits_for(struct intel_engine_cs *engine, u32 *seqno)
{
struct drm_i915_private *dev_priv = engine->i915;
void __iomem *vaddr;
u32 cmd, ipehr, head;
u64 offset = 0;
int i, backwards;
if (engine->buffer == NULL)
return NULL;
ipehr = I915_READ(RING_IPEHR(engine->mmio_base));
if (!ipehr_is_semaphore_wait(engine, ipehr))
return NULL;
head = I915_READ_HEAD(engine) & HEAD_ADDR;
backwards = (INTEL_GEN(dev_priv) >= 8) ? 5 : 4;
vaddr = (void __iomem *)engine->buffer->vaddr;
for (i = backwards; i; --i) {
head &= engine->buffer->size - 1;
cmd = ioread32(vaddr + head);
if (cmd == ipehr)
break;
head -= 4;
}
if (!i)
return NULL;
*seqno = ioread32(vaddr + head + 4) + 1;
if (INTEL_GEN(dev_priv) >= 8) {
offset = ioread32(vaddr + head + 12);
offset <<= 32;
offset |= ioread32(vaddr + head + 8);
}
return semaphore_wait_to_signaller_ring(engine, ipehr, offset);
}
static int semaphore_passed(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
struct intel_engine_cs *signaller;
u32 seqno;
engine->hangcheck.deadlock++;
signaller = semaphore_waits_for(engine, &seqno);
if (signaller == NULL)
return -1;
if (IS_ERR(signaller))
return 0;
if (signaller->hangcheck.deadlock >= I915_NUM_ENGINES)
return -1;
if (i915_seqno_passed(intel_engine_get_seqno(signaller), seqno))
return 1;
if (I915_READ_CTL(signaller) & RING_WAIT_SEMAPHORE &&
semaphore_passed(signaller) < 0)
return -1;
return 0;
}
static void semaphore_clear_deadlocks(struct drm_i915_private *dev_priv)
{
struct intel_engine_cs *engine;
enum intel_engine_id id;
for_each_engine(engine, dev_priv, id)
engine->hangcheck.deadlock = 0;
}
static bool instdone_unchanged(u32 current_instdone, u32 *old_instdone)
{
u32 tmp = current_instdone | *old_instdone;
bool unchanged;
unchanged = tmp == *old_instdone;
*old_instdone |= tmp;
return unchanged;
}
static bool subunits_stuck(struct intel_engine_cs *engine)
{
struct drm_i915_private *dev_priv = engine->i915;
struct intel_instdone instdone;
struct intel_instdone *accu_instdone = &engine->hangcheck.instdone;
bool stuck;
int slice;
int subslice;
if (engine->id != RCS)
return true;
intel_engine_get_instdone(engine, &instdone);
stuck = instdone_unchanged(instdone.instdone,
&accu_instdone->instdone);
stuck &= instdone_unchanged(instdone.slice_common,
&accu_instdone->slice_common);
for_each_instdone_slice_subslice(dev_priv, slice, subslice) {
stuck &= instdone_unchanged(instdone.sampler[slice][subslice],
&accu_instdone->sampler[slice][subslice]);
stuck &= instdone_unchanged(instdone.row[slice][subslice],
&accu_instdone->row[slice][subslice]);
}
return stuck;
}
static enum intel_engine_hangcheck_action
head_stuck(struct intel_engine_cs *engine, u64 acthd)
{
if (acthd != engine->hangcheck.acthd) {
memset(&engine->hangcheck.instdone, 0,
sizeof(engine->hangcheck.instdone));
return ENGINE_ACTIVE_HEAD;
}
if (!subunits_stuck(engine))
return ENGINE_ACTIVE_SUBUNITS;
return ENGINE_DEAD;
}
static enum intel_engine_hangcheck_action
engine_stuck(struct intel_engine_cs *engine, u64 acthd)
{
struct drm_i915_private *dev_priv = engine->i915;
enum intel_engine_hangcheck_action ha;
u32 tmp;
ha = head_stuck(engine, acthd);
if (ha != ENGINE_DEAD)
return ha;
if (IS_GEN2(dev_priv))
return ENGINE_DEAD;
tmp = I915_READ_CTL(engine);
if (tmp & RING_WAIT) {
i915_handle_error(dev_priv, 0,
"Kicking stuck wait on %s",
engine->name);
I915_WRITE_CTL(engine, tmp);
return ENGINE_WAIT_KICK;
}
if (INTEL_GEN(dev_priv) >= 6 && tmp & RING_WAIT_SEMAPHORE) {
switch (semaphore_passed(engine)) {
default:
return ENGINE_DEAD;
case 1:
i915_handle_error(dev_priv, 0,
"Kicking stuck semaphore on %s",
engine->name);
I915_WRITE_CTL(engine, tmp);
return ENGINE_WAIT_KICK;
case 0:
return ENGINE_WAIT;
}
}
return ENGINE_DEAD;
}
static void hangcheck_load_sample(struct intel_engine_cs *engine,
struct intel_engine_hangcheck *hc)
{
if (engine->irq_seqno_barrier)
engine->irq_seqno_barrier(engine);
hc->acthd = intel_engine_get_active_head(engine);
hc->seqno = intel_engine_get_seqno(engine);
}
static void hangcheck_store_sample(struct intel_engine_cs *engine,
const struct intel_engine_hangcheck *hc)
{
engine->hangcheck.acthd = hc->acthd;
engine->hangcheck.seqno = hc->seqno;
engine->hangcheck.action = hc->action;
engine->hangcheck.stalled = hc->stalled;
}
static enum intel_engine_hangcheck_action
hangcheck_get_action(struct intel_engine_cs *engine,
const struct intel_engine_hangcheck *hc)
{
if (engine->hangcheck.seqno != hc->seqno)
return ENGINE_ACTIVE_SEQNO;
if (i915_seqno_passed(hc->seqno, intel_engine_last_submit(engine)))
return ENGINE_IDLE;
return engine_stuck(engine, hc->acthd);
}
static void hangcheck_accumulate_sample(struct intel_engine_cs *engine,
struct intel_engine_hangcheck *hc)
{
unsigned long timeout = I915_ENGINE_DEAD_TIMEOUT;
hc->action = hangcheck_get_action(engine, hc);
switch (hc->action) {
case ENGINE_IDLE:
case ENGINE_ACTIVE_SEQNO:
hc->acthd = 0;
memset(&engine->hangcheck.instdone, 0,
sizeof(engine->hangcheck.instdone));
case ENGINE_WAIT_KICK:
case ENGINE_WAIT:
engine->hangcheck.action_timestamp = jiffies;
break;
case ENGINE_ACTIVE_HEAD:
case ENGINE_ACTIVE_SUBUNITS:
timeout = I915_SEQNO_DEAD_TIMEOUT;
break;
case ENGINE_DEAD:
break;
default:
MISSING_CASE(hc->action);
}
hc->stalled = time_after(jiffies,
engine->hangcheck.action_timestamp + timeout);
}
static void hangcheck_declare_hang(struct drm_i915_private *i915,
unsigned int hung,
unsigned int stuck)
{
struct intel_engine_cs *engine;
char msg[80];
unsigned int tmp;
int len;
if (stuck != hung)
hung &= ~stuck;
len = scnprintf(msg, sizeof(msg),
"%s on ", stuck == hung ? "No progress" : "Hang");
for_each_engine_masked(engine, i915, hung, tmp)
len += scnprintf(msg + len, sizeof(msg) - len,
"%s, ", engine->name);
msg[len-2] = '\0';
return i915_handle_error(i915, hung, msg);
}
static void i915_hangcheck_elapsed(struct work_struct *work)
{
struct drm_i915_private *dev_priv =
container_of(work, typeof(*dev_priv),
gpu_error.hangcheck_work.work);
struct intel_engine_cs *engine;
enum intel_engine_id id;
unsigned int hung = 0, stuck = 0;
int busy_count = 0;
if (!i915.enable_hangcheck)
return;
if (!READ_ONCE(dev_priv->gt.awake))
return;
if (i915_terminally_wedged(&dev_priv->gpu_error))
return;
intel_uncore_arm_unclaimed_mmio_detection(dev_priv);
for_each_engine(engine, dev_priv, id) {
struct intel_engine_hangcheck cur_state, *hc = &cur_state;
const bool busy = intel_engine_has_waiter(engine);
semaphore_clear_deadlocks(dev_priv);
hangcheck_load_sample(engine, hc);
hangcheck_accumulate_sample(engine, hc);
hangcheck_store_sample(engine, hc);
if (engine->hangcheck.stalled) {
hung |= intel_engine_flag(engine);
if (hc->action != ENGINE_DEAD)
stuck |= intel_engine_flag(engine);
}
busy_count += busy;
}
if (hung)
hangcheck_declare_hang(dev_priv, hung, stuck);
if (busy_count)
i915_queue_hangcheck(dev_priv);
}
void intel_engine_init_hangcheck(struct intel_engine_cs *engine)
{
memset(&engine->hangcheck, 0, sizeof(engine->hangcheck));
}
void intel_hangcheck_init(struct drm_i915_private *i915)
{
INIT_DELAYED_WORK(&i915->gpu_error.hangcheck_work,
i915_hangcheck_elapsed);
}
