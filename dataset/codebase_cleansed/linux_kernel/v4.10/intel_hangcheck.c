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
return HANGCHECK_ACTIVE;
}
if (!subunits_stuck(engine))
return HANGCHECK_ACTIVE;
return HANGCHECK_HUNG;
}
static enum intel_engine_hangcheck_action
engine_stuck(struct intel_engine_cs *engine, u64 acthd)
{
struct drm_i915_private *dev_priv = engine->i915;
enum intel_engine_hangcheck_action ha;
u32 tmp;
ha = head_stuck(engine, acthd);
if (ha != HANGCHECK_HUNG)
return ha;
if (IS_GEN2(dev_priv))
return HANGCHECK_HUNG;
tmp = I915_READ_CTL(engine);
if (tmp & RING_WAIT) {
i915_handle_error(dev_priv, 0,
"Kicking stuck wait on %s",
engine->name);
I915_WRITE_CTL(engine, tmp);
return HANGCHECK_KICK;
}
if (INTEL_GEN(dev_priv) >= 6 && tmp & RING_WAIT_SEMAPHORE) {
switch (semaphore_passed(engine)) {
default:
return HANGCHECK_HUNG;
case 1:
i915_handle_error(dev_priv, 0,
"Kicking stuck semaphore on %s",
engine->name);
I915_WRITE_CTL(engine, tmp);
return HANGCHECK_KICK;
case 0:
return HANGCHECK_WAIT;
}
}
return HANGCHECK_HUNG;
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
#define BUSY 1
#define KICK 5
#define HUNG 20
#define ACTIVE_DECAY 15
if (!i915.enable_hangcheck)
return;
if (!READ_ONCE(dev_priv->gt.awake))
return;
intel_uncore_arm_unclaimed_mmio_detection(dev_priv);
for_each_engine(engine, dev_priv, id) {
bool busy = intel_engine_has_waiter(engine);
u64 acthd;
u32 seqno;
u32 submit;
semaphore_clear_deadlocks(dev_priv);
if (engine->irq_seqno_barrier)
engine->irq_seqno_barrier(engine);
acthd = intel_engine_get_active_head(engine);
seqno = intel_engine_get_seqno(engine);
submit = intel_engine_last_submit(engine);
if (engine->hangcheck.seqno == seqno) {
if (i915_seqno_passed(seqno, submit)) {
engine->hangcheck.action = HANGCHECK_IDLE;
} else {
engine->hangcheck.action =
engine_stuck(engine, acthd);
switch (engine->hangcheck.action) {
case HANGCHECK_IDLE:
case HANGCHECK_WAIT:
break;
case HANGCHECK_ACTIVE:
engine->hangcheck.score += BUSY;
break;
case HANGCHECK_KICK:
engine->hangcheck.score += KICK;
break;
case HANGCHECK_HUNG:
engine->hangcheck.score += HUNG;
break;
}
}
if (engine->hangcheck.score >= HANGCHECK_SCORE_RING_HUNG) {
hung |= intel_engine_flag(engine);
if (engine->hangcheck.action != HANGCHECK_HUNG)
stuck |= intel_engine_flag(engine);
}
} else {
engine->hangcheck.action = HANGCHECK_ACTIVE;
if (engine->hangcheck.score > 0)
engine->hangcheck.score -= ACTIVE_DECAY;
if (engine->hangcheck.score < 0)
engine->hangcheck.score = 0;
acthd = 0;
memset(&engine->hangcheck.instdone, 0,
sizeof(engine->hangcheck.instdone));
}
engine->hangcheck.seqno = seqno;
engine->hangcheck.acthd = acthd;
busy_count += busy;
}
if (hung) {
char msg[80];
unsigned int tmp;
int len;
if (stuck != hung)
hung &= ~stuck;
len = scnprintf(msg, sizeof(msg),
"%s on ", stuck == hung ? "No progress" : "Hang");
for_each_engine_masked(engine, dev_priv, hung, tmp)
len += scnprintf(msg + len, sizeof(msg) - len,
"%s, ", engine->name);
msg[len-2] = '\0';
return i915_handle_error(dev_priv, hung, msg);
}
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
