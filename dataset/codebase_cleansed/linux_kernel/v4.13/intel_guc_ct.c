void intel_guc_ct_init_early(struct intel_guc_ct *ct)
{
ct->host_channel.owner = CTB_OWNER_HOST;
}
static inline const char *guc_ct_buffer_type_to_str(u32 type)
{
switch (type) {
case INTEL_GUC_CT_BUFFER_TYPE_SEND:
return "SEND";
case INTEL_GUC_CT_BUFFER_TYPE_RECV:
return "RECV";
default:
return "<invalid>";
}
}
static void guc_ct_buffer_desc_init(struct guc_ct_buffer_desc *desc,
u32 cmds_addr, u32 size, u32 owner)
{
DRM_DEBUG_DRIVER("CT: desc %p init addr=%#x size=%u owner=%u\n",
desc, cmds_addr, size, owner);
memset(desc, 0, sizeof(*desc));
desc->addr = cmds_addr;
desc->size = size;
desc->owner = owner;
}
static void guc_ct_buffer_desc_reset(struct guc_ct_buffer_desc *desc)
{
DRM_DEBUG_DRIVER("CT: desc %p reset head=%u tail=%u\n",
desc, desc->head, desc->tail);
desc->head = 0;
desc->tail = 0;
desc->is_in_error = 0;
}
static int guc_action_register_ct_buffer(struct intel_guc *guc,
u32 desc_addr,
u32 type)
{
u32 action[] = {
INTEL_GUC_ACTION_REGISTER_COMMAND_TRANSPORT_BUFFER,
desc_addr,
sizeof(struct guc_ct_buffer_desc),
type
};
int err;
err = intel_guc_send_mmio(guc, action, ARRAY_SIZE(action));
if (err)
DRM_ERROR("CT: register %s buffer failed; err=%d\n",
guc_ct_buffer_type_to_str(type), err);
return err;
}
static int guc_action_deregister_ct_buffer(struct intel_guc *guc,
u32 owner,
u32 type)
{
u32 action[] = {
INTEL_GUC_ACTION_DEREGISTER_COMMAND_TRANSPORT_BUFFER,
owner,
type
};
int err;
err = intel_guc_send_mmio(guc, action, ARRAY_SIZE(action));
if (err)
DRM_ERROR("CT: deregister %s buffer failed; owner=%d err=%d\n",
guc_ct_buffer_type_to_str(type), owner, err);
return err;
}
static bool ctch_is_open(struct intel_guc_ct_channel *ctch)
{
return ctch->vma != NULL;
}
static int ctch_init(struct intel_guc *guc,
struct intel_guc_ct_channel *ctch)
{
struct i915_vma *vma;
void *blob;
int err;
int i;
GEM_BUG_ON(ctch->vma);
vma = intel_guc_allocate_vma(guc, PAGE_SIZE);
if (IS_ERR(vma)) {
err = PTR_ERR(vma);
goto err_out;
}
ctch->vma = vma;
blob = i915_gem_object_pin_map(vma->obj, I915_MAP_WB);
if (IS_ERR(blob)) {
err = PTR_ERR(blob);
goto err_vma;
}
DRM_DEBUG_DRIVER("CT: vma base=%#x\n", guc_ggtt_offset(ctch->vma));
for (i = 0; i < ARRAY_SIZE(ctch->ctbs); i++) {
GEM_BUG_ON((i != CTB_SEND) && (i != CTB_RECV));
ctch->ctbs[i].desc = blob + PAGE_SIZE/4 * i;
ctch->ctbs[i].cmds = blob + PAGE_SIZE/4 * i + PAGE_SIZE/2;
}
return 0;
err_vma:
i915_vma_unpin_and_release(&ctch->vma);
err_out:
DRM_DEBUG_DRIVER("CT: channel %d initialization failed; err=%d\n",
ctch->owner, err);
return err;
}
static void ctch_fini(struct intel_guc *guc,
struct intel_guc_ct_channel *ctch)
{
GEM_BUG_ON(!ctch->vma);
i915_gem_object_unpin_map(ctch->vma->obj);
i915_vma_unpin_and_release(&ctch->vma);
}
static int ctch_open(struct intel_guc *guc,
struct intel_guc_ct_channel *ctch)
{
u32 base;
int err;
int i;
DRM_DEBUG_DRIVER("CT: channel %d reopen=%s\n",
ctch->owner, yesno(ctch_is_open(ctch)));
if (!ctch->vma) {
err = ctch_init(guc, ctch);
if (unlikely(err))
goto err_out;
}
base = guc_ggtt_offset(ctch->vma);
for (i = 0; i < ARRAY_SIZE(ctch->ctbs); i++) {
GEM_BUG_ON((i != CTB_SEND) && (i != CTB_RECV));
guc_ct_buffer_desc_init(ctch->ctbs[i].desc,
base + PAGE_SIZE/4 * i + PAGE_SIZE/2,
PAGE_SIZE/4,
ctch->owner);
}
err = guc_action_register_ct_buffer(guc,
base + PAGE_SIZE/4 * CTB_RECV,
INTEL_GUC_CT_BUFFER_TYPE_RECV);
if (unlikely(err))
goto err_fini;
err = guc_action_register_ct_buffer(guc,
base + PAGE_SIZE/4 * CTB_SEND,
INTEL_GUC_CT_BUFFER_TYPE_SEND);
if (unlikely(err))
goto err_deregister;
return 0;
err_deregister:
guc_action_deregister_ct_buffer(guc,
ctch->owner,
INTEL_GUC_CT_BUFFER_TYPE_RECV);
err_fini:
ctch_fini(guc, ctch);
err_out:
DRM_ERROR("CT: can't open channel %d; err=%d\n", ctch->owner, err);
return err;
}
static void ctch_close(struct intel_guc *guc,
struct intel_guc_ct_channel *ctch)
{
GEM_BUG_ON(!ctch_is_open(ctch));
guc_action_deregister_ct_buffer(guc,
ctch->owner,
INTEL_GUC_CT_BUFFER_TYPE_SEND);
guc_action_deregister_ct_buffer(guc,
ctch->owner,
INTEL_GUC_CT_BUFFER_TYPE_RECV);
ctch_fini(guc, ctch);
}
static u32 ctch_get_next_fence(struct intel_guc_ct_channel *ctch)
{
return ++ctch->next_fence;
}
static int ctb_write(struct intel_guc_ct_buffer *ctb,
const u32 *action,
u32 len ,
u32 fence)
{
struct guc_ct_buffer_desc *desc = ctb->desc;
u32 head = desc->head / 4;
u32 tail = desc->tail / 4;
u32 size = desc->size / 4;
u32 used;
u32 header;
u32 *cmds = ctb->cmds;
unsigned int i;
GEM_BUG_ON(desc->size % 4);
GEM_BUG_ON(desc->head % 4);
GEM_BUG_ON(desc->tail % 4);
GEM_BUG_ON(tail >= size);
if (tail < head)
used = (size - head) + tail;
else
used = tail - head;
if (unlikely(used + len + 1 >= size))
return -ENOSPC;
header = (len << GUC_CT_MSG_LEN_SHIFT) |
(GUC_CT_MSG_WRITE_FENCE_TO_DESC) |
(action[0] << GUC_CT_MSG_ACTION_SHIFT);
cmds[tail] = header;
tail = (tail + 1) % size;
cmds[tail] = fence;
tail = (tail + 1) % size;
for (i = 1; i < len; i++) {
cmds[tail] = action[i];
tail = (tail + 1) % size;
}
desc->tail = tail * 4;
GEM_BUG_ON(desc->tail > desc->size);
return 0;
}
static int wait_for_response(struct guc_ct_buffer_desc *desc,
u32 fence,
u32 *status)
{
int err;
#define done (READ_ONCE(desc->fence) == fence)
err = wait_for_us(done, 10);
if (err)
err = wait_for(done, 10);
#undef done
if (unlikely(err)) {
DRM_ERROR("CT: fence %u failed; reported fence=%u\n",
fence, desc->fence);
if (WARN_ON(desc->is_in_error)) {
guc_ct_buffer_desc_reset(desc);
err = -EPROTO;
}
}
*status = desc->status;
return err;
}
static int ctch_send(struct intel_guc *guc,
struct intel_guc_ct_channel *ctch,
const u32 *action,
u32 len,
u32 *status)
{
struct intel_guc_ct_buffer *ctb = &ctch->ctbs[CTB_SEND];
struct guc_ct_buffer_desc *desc = ctb->desc;
u32 fence;
int err;
GEM_BUG_ON(!ctch_is_open(ctch));
GEM_BUG_ON(!len);
GEM_BUG_ON(len & ~GUC_CT_MSG_LEN_MASK);
fence = ctch_get_next_fence(ctch);
err = ctb_write(ctb, action, len, fence);
if (unlikely(err))
return err;
intel_guc_notify(guc);
err = wait_for_response(desc, fence, status);
if (unlikely(err))
return err;
if (*status != INTEL_GUC_STATUS_SUCCESS)
return -EIO;
return 0;
}
static int intel_guc_send_ct(struct intel_guc *guc, const u32 *action, u32 len)
{
struct intel_guc_ct_channel *ctch = &guc->ct.host_channel;
u32 status = ~0;
int err;
mutex_lock(&guc->send_mutex);
err = ctch_send(guc, ctch, action, len, &status);
if (unlikely(err)) {
DRM_ERROR("CT: send action %#X failed; err=%d status=%#X\n",
action[0], err, status);
}
mutex_unlock(&guc->send_mutex);
return err;
}
int intel_guc_enable_ct(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
struct intel_guc_ct_channel *ctch = &guc->ct.host_channel;
int err;
GEM_BUG_ON(!HAS_GUC_CT(dev_priv));
err = ctch_open(guc, ctch);
if (unlikely(err))
return err;
guc->send = intel_guc_send_ct;
DRM_INFO("CT: %s\n", enableddisabled(true));
return 0;
}
void intel_guc_disable_ct(struct intel_guc *guc)
{
struct drm_i915_private *dev_priv = guc_to_i915(guc);
struct intel_guc_ct_channel *ctch = &guc->ct.host_channel;
GEM_BUG_ON(!HAS_GUC_CT(dev_priv));
if (!ctch_is_open(ctch))
return;
ctch_close(guc, ctch);
guc->send = intel_guc_send_nop;
DRM_INFO("CT: %s\n", enableddisabled(false));
}
