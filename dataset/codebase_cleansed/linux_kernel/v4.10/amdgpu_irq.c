static void amdgpu_hotplug_work_func(struct work_struct *work)
{
struct amdgpu_device *adev = container_of(work, struct amdgpu_device,
hotplug_work);
struct drm_device *dev = adev->ddev;
struct drm_mode_config *mode_config = &dev->mode_config;
struct drm_connector *connector;
mutex_lock(&mode_config->mutex);
if (mode_config->num_connector) {
list_for_each_entry(connector, &mode_config->connector_list, head)
amdgpu_connector_hotplug(connector);
}
mutex_unlock(&mode_config->mutex);
drm_helper_hpd_irq_event(dev);
}
static void amdgpu_irq_reset_work_func(struct work_struct *work)
{
struct amdgpu_device *adev = container_of(work, struct amdgpu_device,
reset_work);
amdgpu_gpu_reset(adev);
}
static void amdgpu_irq_disable_all(struct amdgpu_device *adev)
{
unsigned long irqflags;
unsigned i, j;
int r;
spin_lock_irqsave(&adev->irq.lock, irqflags);
for (i = 0; i < AMDGPU_MAX_IRQ_SRC_ID; ++i) {
struct amdgpu_irq_src *src = adev->irq.sources[i];
if (!src || !src->funcs->set || !src->num_types)
continue;
for (j = 0; j < src->num_types; ++j) {
atomic_set(&src->enabled_types[j], 0);
r = src->funcs->set(adev, src, j,
AMDGPU_IRQ_STATE_DISABLE);
if (r)
DRM_ERROR("error disabling interrupt (%d)\n",
r);
}
}
spin_unlock_irqrestore(&adev->irq.lock, irqflags);
}
void amdgpu_irq_preinstall(struct drm_device *dev)
{
struct amdgpu_device *adev = dev->dev_private;
amdgpu_irq_disable_all(adev);
amdgpu_ih_process(adev);
}
int amdgpu_irq_postinstall(struct drm_device *dev)
{
dev->max_vblank_count = 0x00ffffff;
return 0;
}
void amdgpu_irq_uninstall(struct drm_device *dev)
{
struct amdgpu_device *adev = dev->dev_private;
if (adev == NULL) {
return;
}
amdgpu_irq_disable_all(adev);
}
irqreturn_t amdgpu_irq_handler(int irq, void *arg)
{
struct drm_device *dev = (struct drm_device *) arg;
struct amdgpu_device *adev = dev->dev_private;
irqreturn_t ret;
ret = amdgpu_ih_process(adev);
if (ret == IRQ_HANDLED)
pm_runtime_mark_last_busy(dev->dev);
return ret;
}
static bool amdgpu_msi_ok(struct amdgpu_device *adev)
{
if (amdgpu_msi == 1)
return true;
else if (amdgpu_msi == 0)
return false;
return true;
}
int amdgpu_irq_init(struct amdgpu_device *adev)
{
int r = 0;
spin_lock_init(&adev->irq.lock);
r = drm_vblank_init(adev->ddev, adev->mode_info.num_crtc);
if (r) {
return r;
}
adev->irq.msi_enabled = false;
if (amdgpu_msi_ok(adev)) {
int ret = pci_enable_msi(adev->pdev);
if (!ret) {
adev->irq.msi_enabled = true;
dev_info(adev->dev, "amdgpu: using MSI.\n");
}
}
INIT_WORK(&adev->hotplug_work, amdgpu_hotplug_work_func);
INIT_WORK(&adev->reset_work, amdgpu_irq_reset_work_func);
adev->irq.installed = true;
r = drm_irq_install(adev->ddev, adev->ddev->pdev->irq);
if (r) {
adev->irq.installed = false;
flush_work(&adev->hotplug_work);
cancel_work_sync(&adev->reset_work);
return r;
}
DRM_INFO("amdgpu: irq initialized.\n");
return 0;
}
void amdgpu_irq_fini(struct amdgpu_device *adev)
{
unsigned i;
drm_vblank_cleanup(adev->ddev);
if (adev->irq.installed) {
drm_irq_uninstall(adev->ddev);
adev->irq.installed = false;
if (adev->irq.msi_enabled)
pci_disable_msi(adev->pdev);
flush_work(&adev->hotplug_work);
cancel_work_sync(&adev->reset_work);
}
for (i = 0; i < AMDGPU_MAX_IRQ_SRC_ID; ++i) {
struct amdgpu_irq_src *src = adev->irq.sources[i];
if (!src)
continue;
kfree(src->enabled_types);
src->enabled_types = NULL;
if (src->data) {
kfree(src->data);
kfree(src);
adev->irq.sources[i] = NULL;
}
}
}
int amdgpu_irq_add_id(struct amdgpu_device *adev, unsigned src_id,
struct amdgpu_irq_src *source)
{
if (src_id >= AMDGPU_MAX_IRQ_SRC_ID)
return -EINVAL;
if (adev->irq.sources[src_id] != NULL)
return -EINVAL;
if (!source->funcs)
return -EINVAL;
if (source->num_types && !source->enabled_types) {
atomic_t *types;
types = kcalloc(source->num_types, sizeof(atomic_t),
GFP_KERNEL);
if (!types)
return -ENOMEM;
source->enabled_types = types;
}
adev->irq.sources[src_id] = source;
return 0;
}
void amdgpu_irq_dispatch(struct amdgpu_device *adev,
struct amdgpu_iv_entry *entry)
{
unsigned src_id = entry->src_id;
struct amdgpu_irq_src *src;
int r;
if (src_id >= AMDGPU_MAX_IRQ_SRC_ID) {
DRM_DEBUG("Invalid src_id in IV: %d\n", src_id);
return;
}
if (adev->irq.virq[src_id]) {
generic_handle_irq(irq_find_mapping(adev->irq.domain, src_id));
} else {
src = adev->irq.sources[src_id];
if (!src) {
DRM_DEBUG("Unhandled interrupt src_id: %d\n", src_id);
return;
}
r = src->funcs->process(adev, src, entry);
if (r)
DRM_ERROR("error processing interrupt (%d)\n", r);
}
}
int amdgpu_irq_update(struct amdgpu_device *adev,
struct amdgpu_irq_src *src, unsigned type)
{
unsigned long irqflags;
enum amdgpu_interrupt_state state;
int r;
spin_lock_irqsave(&adev->irq.lock, irqflags);
if (amdgpu_irq_enabled(adev, src, type))
state = AMDGPU_IRQ_STATE_ENABLE;
else
state = AMDGPU_IRQ_STATE_DISABLE;
r = src->funcs->set(adev, src, type, state);
spin_unlock_irqrestore(&adev->irq.lock, irqflags);
return r;
}
void amdgpu_irq_gpu_reset_resume_helper(struct amdgpu_device *adev)
{
int i, j;
for (i = 0; i < AMDGPU_MAX_IRQ_SRC_ID; i++) {
struct amdgpu_irq_src *src = adev->irq.sources[i];
if (!src)
continue;
for (j = 0; j < src->num_types; j++)
amdgpu_irq_update(adev, src, j);
}
}
int amdgpu_irq_get(struct amdgpu_device *adev, struct amdgpu_irq_src *src,
unsigned type)
{
if (!adev->ddev->irq_enabled)
return -ENOENT;
if (type >= src->num_types)
return -EINVAL;
if (!src->enabled_types || !src->funcs->set)
return -EINVAL;
if (atomic_inc_return(&src->enabled_types[type]) == 1)
return amdgpu_irq_update(adev, src, type);
return 0;
}
int amdgpu_irq_put(struct amdgpu_device *adev, struct amdgpu_irq_src *src,
unsigned type)
{
if (!adev->ddev->irq_enabled)
return -ENOENT;
if (type >= src->num_types)
return -EINVAL;
if (!src->enabled_types || !src->funcs->set)
return -EINVAL;
if (atomic_dec_and_test(&src->enabled_types[type]))
return amdgpu_irq_update(adev, src, type);
return 0;
}
bool amdgpu_irq_enabled(struct amdgpu_device *adev, struct amdgpu_irq_src *src,
unsigned type)
{
if (!adev->ddev->irq_enabled)
return false;
if (type >= src->num_types)
return false;
if (!src->enabled_types || !src->funcs->set)
return false;
return !!atomic_read(&src->enabled_types[type]);
}
static void amdgpu_irq_mask(struct irq_data *irqd)
{
}
static void amdgpu_irq_unmask(struct irq_data *irqd)
{
}
static int amdgpu_irqdomain_map(struct irq_domain *d,
unsigned int irq, irq_hw_number_t hwirq)
{
if (hwirq >= AMDGPU_MAX_IRQ_SRC_ID)
return -EPERM;
irq_set_chip_and_handler(irq,
&amdgpu_irq_chip, handle_simple_irq);
return 0;
}
int amdgpu_irq_add_domain(struct amdgpu_device *adev)
{
adev->irq.domain = irq_domain_add_linear(NULL, AMDGPU_MAX_IRQ_SRC_ID,
&amdgpu_hw_irqdomain_ops, adev);
if (!adev->irq.domain) {
DRM_ERROR("GPU irq add domain failed\n");
return -ENODEV;
}
return 0;
}
void amdgpu_irq_remove_domain(struct amdgpu_device *adev)
{
if (adev->irq.domain) {
irq_domain_remove(adev->irq.domain);
adev->irq.domain = NULL;
}
}
unsigned amdgpu_irq_create_mapping(struct amdgpu_device *adev, unsigned src_id)
{
adev->irq.virq[src_id] = irq_create_mapping(adev->irq.domain, src_id);
return adev->irq.virq[src_id];
}
