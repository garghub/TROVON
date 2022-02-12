int exynos_platform_device_ipp_register(void)
{
struct platform_device *pdev;
if (exynos_drm_ipp_pdev)
return -EEXIST;
pdev = platform_device_register_simple("exynos-drm-ipp", -1, NULL, 0);
if (IS_ERR(pdev))
return PTR_ERR(pdev);
exynos_drm_ipp_pdev = pdev;
return 0;
}
void exynos_platform_device_ipp_unregister(void)
{
if (exynos_drm_ipp_pdev) {
platform_device_unregister(exynos_drm_ipp_pdev);
exynos_drm_ipp_pdev = NULL;
}
}
int exynos_drm_ippdrv_register(struct exynos_drm_ippdrv *ippdrv)
{
if (!ippdrv)
return -EINVAL;
mutex_lock(&exynos_drm_ippdrv_lock);
list_add_tail(&ippdrv->drv_list, &exynos_drm_ippdrv_list);
mutex_unlock(&exynos_drm_ippdrv_lock);
return 0;
}
int exynos_drm_ippdrv_unregister(struct exynos_drm_ippdrv *ippdrv)
{
if (!ippdrv)
return -EINVAL;
mutex_lock(&exynos_drm_ippdrv_lock);
list_del(&ippdrv->drv_list);
mutex_unlock(&exynos_drm_ippdrv_lock);
return 0;
}
static int ipp_create_id(struct idr *id_idr, struct mutex *lock, void *obj,
u32 *idp)
{
int ret;
mutex_lock(lock);
ret = idr_alloc(id_idr, obj, 1, 0, GFP_KERNEL);
mutex_unlock(lock);
if (ret < 0)
return ret;
*idp = ret;
return 0;
}
static void *ipp_find_obj(struct idr *id_idr, struct mutex *lock, u32 id)
{
void *obj;
DRM_DEBUG_KMS("id[%d]\n", id);
mutex_lock(lock);
obj = idr_find(id_idr, id);
if (!obj) {
DRM_ERROR("failed to find object.\n");
mutex_unlock(lock);
return ERR_PTR(-ENODEV);
}
mutex_unlock(lock);
return obj;
}
static inline bool ipp_check_dedicated(struct exynos_drm_ippdrv *ippdrv,
enum drm_exynos_ipp_cmd cmd)
{
if (ippdrv->dedicated || (!ipp_is_m2m_cmd(cmd) &&
!pm_runtime_suspended(ippdrv->dev)))
return true;
return false;
}
static struct exynos_drm_ippdrv *ipp_find_driver(struct ipp_context *ctx,
struct drm_exynos_ipp_property *property)
{
struct exynos_drm_ippdrv *ippdrv;
u32 ipp_id = property->ipp_id;
DRM_DEBUG_KMS("ipp_id[%d]\n", ipp_id);
if (ipp_id) {
ippdrv = ipp_find_obj(&ctx->ipp_idr, &ctx->ipp_lock,
ipp_id);
if (IS_ERR(ippdrv)) {
DRM_ERROR("not found ipp%d driver.\n", ipp_id);
return ippdrv;
}
if (ipp_check_dedicated(ippdrv, property->cmd)) {
DRM_ERROR("already used choose device.\n");
return ERR_PTR(-EBUSY);
}
if (ippdrv->check_property &&
ippdrv->check_property(ippdrv->dev, property)) {
DRM_ERROR("not support property.\n");
return ERR_PTR(-EINVAL);
}
return ippdrv;
} else {
list_for_each_entry(ippdrv, &exynos_drm_ippdrv_list, drv_list) {
if (ipp_check_dedicated(ippdrv, property->cmd)) {
DRM_DEBUG_KMS("used device.\n");
continue;
}
if (ippdrv->check_property &&
ippdrv->check_property(ippdrv->dev, property)) {
DRM_DEBUG_KMS("not support property.\n");
continue;
}
return ippdrv;
}
DRM_ERROR("not support ipp driver operations.\n");
}
return ERR_PTR(-ENODEV);
}
static struct exynos_drm_ippdrv *ipp_find_drv_by_handle(u32 prop_id)
{
struct exynos_drm_ippdrv *ippdrv;
struct drm_exynos_ipp_cmd_node *c_node;
int count = 0;
DRM_DEBUG_KMS("prop_id[%d]\n", prop_id);
if (list_empty(&exynos_drm_ippdrv_list)) {
DRM_DEBUG_KMS("ippdrv_list is empty.\n");
return ERR_PTR(-ENODEV);
}
list_for_each_entry(ippdrv, &exynos_drm_ippdrv_list, drv_list) {
DRM_DEBUG_KMS("count[%d]ippdrv[0x%x]\n", count++, (int)ippdrv);
if (!list_empty(&ippdrv->cmd_list)) {
list_for_each_entry(c_node, &ippdrv->cmd_list, list)
if (c_node->property.prop_id == prop_id)
return ippdrv;
}
}
return ERR_PTR(-ENODEV);
}
int exynos_drm_ipp_get_property(struct drm_device *drm_dev, void *data,
struct drm_file *file)
{
struct drm_exynos_file_private *file_priv = file->driver_priv;
struct exynos_drm_ipp_private *priv = file_priv->ipp_priv;
struct device *dev = priv->dev;
struct ipp_context *ctx = get_ipp_context(dev);
struct drm_exynos_ipp_prop_list *prop_list = data;
struct exynos_drm_ippdrv *ippdrv;
int count = 0;
if (!ctx) {
DRM_ERROR("invalid context.\n");
return -EINVAL;
}
if (!prop_list) {
DRM_ERROR("invalid property parameter.\n");
return -EINVAL;
}
DRM_DEBUG_KMS("ipp_id[%d]\n", prop_list->ipp_id);
if (!prop_list->ipp_id) {
list_for_each_entry(ippdrv, &exynos_drm_ippdrv_list, drv_list)
count++;
prop_list->count = count;
} else {
ippdrv = ipp_find_obj(&ctx->ipp_idr, &ctx->ipp_lock,
prop_list->ipp_id);
if (IS_ERR(ippdrv)) {
DRM_ERROR("not found ipp%d driver.\n",
prop_list->ipp_id);
return PTR_ERR(ippdrv);
}
prop_list = ippdrv->prop_list;
}
return 0;
}
static void ipp_print_property(struct drm_exynos_ipp_property *property,
int idx)
{
struct drm_exynos_ipp_config *config = &property->config[idx];
struct drm_exynos_pos *pos = &config->pos;
struct drm_exynos_sz *sz = &config->sz;
DRM_DEBUG_KMS("prop_id[%d]ops[%s]fmt[0x%x]\n",
property->prop_id, idx ? "dst" : "src", config->fmt);
DRM_DEBUG_KMS("pos[%d %d %d %d]sz[%d %d]f[%d]r[%d]\n",
pos->x, pos->y, pos->w, pos->h,
sz->hsize, sz->vsize, config->flip, config->degree);
}
static int ipp_find_and_set_property(struct drm_exynos_ipp_property *property)
{
struct exynos_drm_ippdrv *ippdrv;
struct drm_exynos_ipp_cmd_node *c_node;
u32 prop_id = property->prop_id;
DRM_DEBUG_KMS("prop_id[%d]\n", prop_id);
ippdrv = ipp_find_drv_by_handle(prop_id);
if (IS_ERR(ippdrv)) {
DRM_ERROR("failed to get ipp driver.\n");
return -EINVAL;
}
list_for_each_entry(c_node, &ippdrv->cmd_list, list) {
if ((c_node->property.prop_id == prop_id) &&
(c_node->state == IPP_STATE_STOP)) {
DRM_DEBUG_KMS("found cmd[%d]ippdrv[0x%x]\n",
property->cmd, (int)ippdrv);
c_node->property = *property;
return 0;
}
}
DRM_ERROR("failed to search property.\n");
return -EINVAL;
}
static struct drm_exynos_ipp_cmd_work *ipp_create_cmd_work(void)
{
struct drm_exynos_ipp_cmd_work *cmd_work;
cmd_work = kzalloc(sizeof(*cmd_work), GFP_KERNEL);
if (!cmd_work) {
DRM_ERROR("failed to alloc cmd_work.\n");
return ERR_PTR(-ENOMEM);
}
INIT_WORK((struct work_struct *)cmd_work, ipp_sched_cmd);
return cmd_work;
}
static struct drm_exynos_ipp_event_work *ipp_create_event_work(void)
{
struct drm_exynos_ipp_event_work *event_work;
event_work = kzalloc(sizeof(*event_work), GFP_KERNEL);
if (!event_work) {
DRM_ERROR("failed to alloc event_work.\n");
return ERR_PTR(-ENOMEM);
}
INIT_WORK((struct work_struct *)event_work, ipp_sched_event);
return event_work;
}
int exynos_drm_ipp_set_property(struct drm_device *drm_dev, void *data,
struct drm_file *file)
{
struct drm_exynos_file_private *file_priv = file->driver_priv;
struct exynos_drm_ipp_private *priv = file_priv->ipp_priv;
struct device *dev = priv->dev;
struct ipp_context *ctx = get_ipp_context(dev);
struct drm_exynos_ipp_property *property = data;
struct exynos_drm_ippdrv *ippdrv;
struct drm_exynos_ipp_cmd_node *c_node;
int ret, i;
if (!ctx) {
DRM_ERROR("invalid context.\n");
return -EINVAL;
}
if (!property) {
DRM_ERROR("invalid property parameter.\n");
return -EINVAL;
}
for_each_ipp_ops(i)
ipp_print_property(property, i);
if (property->prop_id) {
DRM_DEBUG_KMS("prop_id[%d]\n", property->prop_id);
return ipp_find_and_set_property(property);
}
ippdrv = ipp_find_driver(ctx, property);
if (IS_ERR(ippdrv)) {
DRM_ERROR("failed to get ipp driver.\n");
return -EINVAL;
}
c_node = kzalloc(sizeof(*c_node), GFP_KERNEL);
if (!c_node) {
DRM_ERROR("failed to allocate map node.\n");
return -ENOMEM;
}
ret = ipp_create_id(&ctx->prop_idr, &ctx->prop_lock, c_node,
&property->prop_id);
if (ret) {
DRM_ERROR("failed to create id.\n");
goto err_clear;
}
DRM_DEBUG_KMS("created prop_id[%d]cmd[%d]ippdrv[0x%x]\n",
property->prop_id, property->cmd, (int)ippdrv);
c_node->priv = priv;
c_node->property = *property;
c_node->state = IPP_STATE_IDLE;
c_node->start_work = ipp_create_cmd_work();
if (IS_ERR(c_node->start_work)) {
DRM_ERROR("failed to create start work.\n");
goto err_clear;
}
c_node->stop_work = ipp_create_cmd_work();
if (IS_ERR(c_node->stop_work)) {
DRM_ERROR("failed to create stop work.\n");
goto err_free_start;
}
c_node->event_work = ipp_create_event_work();
if (IS_ERR(c_node->event_work)) {
DRM_ERROR("failed to create event work.\n");
goto err_free_stop;
}
mutex_init(&c_node->cmd_lock);
mutex_init(&c_node->mem_lock);
mutex_init(&c_node->event_lock);
init_completion(&c_node->start_complete);
init_completion(&c_node->stop_complete);
for_each_ipp_ops(i)
INIT_LIST_HEAD(&c_node->mem_list[i]);
INIT_LIST_HEAD(&c_node->event_list);
list_splice_init(&priv->event_list, &c_node->event_list);
list_add_tail(&c_node->list, &ippdrv->cmd_list);
if (!ipp_is_m2m_cmd(property->cmd))
ippdrv->dedicated = true;
return 0;
err_free_stop:
kfree(c_node->stop_work);
err_free_start:
kfree(c_node->start_work);
err_clear:
kfree(c_node);
return ret;
}
static void ipp_clean_cmd_node(struct drm_exynos_ipp_cmd_node *c_node)
{
list_del(&c_node->list);
mutex_destroy(&c_node->cmd_lock);
mutex_destroy(&c_node->mem_lock);
mutex_destroy(&c_node->event_lock);
kfree(c_node->start_work);
kfree(c_node->stop_work);
kfree(c_node->event_work);
kfree(c_node);
}
static int ipp_check_mem_list(struct drm_exynos_ipp_cmd_node *c_node)
{
struct drm_exynos_ipp_property *property = &c_node->property;
struct drm_exynos_ipp_mem_node *m_node;
struct list_head *head;
int ret, i, count[EXYNOS_DRM_OPS_MAX] = { 0, };
mutex_lock(&c_node->mem_lock);
for_each_ipp_ops(i) {
head = &c_node->mem_list[i];
if (list_empty(head)) {
DRM_DEBUG_KMS("%s memory empty.\n", i ? "dst" : "src");
continue;
}
list_for_each_entry(m_node, head, list) {
DRM_DEBUG_KMS("%s,count[%d]m_node[0x%x]\n",
i ? "dst" : "src", count[i], (int)m_node);
count[i]++;
}
}
DRM_DEBUG_KMS("min[%d]max[%d]\n",
min(count[EXYNOS_DRM_OPS_SRC], count[EXYNOS_DRM_OPS_DST]),
max(count[EXYNOS_DRM_OPS_SRC], count[EXYNOS_DRM_OPS_DST]));
if (ipp_is_m2m_cmd(property->cmd))
ret = min(count[EXYNOS_DRM_OPS_SRC],
count[EXYNOS_DRM_OPS_DST]);
else
ret = max(count[EXYNOS_DRM_OPS_SRC],
count[EXYNOS_DRM_OPS_DST]);
mutex_unlock(&c_node->mem_lock);
return ret;
}
static struct drm_exynos_ipp_mem_node
*ipp_find_mem_node(struct drm_exynos_ipp_cmd_node *c_node,
struct drm_exynos_ipp_queue_buf *qbuf)
{
struct drm_exynos_ipp_mem_node *m_node;
struct list_head *head;
int count = 0;
DRM_DEBUG_KMS("buf_id[%d]\n", qbuf->buf_id);
head = &c_node->mem_list[qbuf->ops_id];
list_for_each_entry(m_node, head, list) {
DRM_DEBUG_KMS("count[%d]m_node[0x%x]\n", count++, (int)m_node);
if (m_node->buf_id == qbuf->buf_id)
return m_node;
}
return NULL;
}
static int ipp_set_mem_node(struct exynos_drm_ippdrv *ippdrv,
struct drm_exynos_ipp_cmd_node *c_node,
struct drm_exynos_ipp_mem_node *m_node)
{
struct exynos_drm_ipp_ops *ops = NULL;
int ret = 0;
DRM_DEBUG_KMS("node[0x%x]\n", (int)m_node);
if (!m_node) {
DRM_ERROR("invalid queue node.\n");
return -EFAULT;
}
mutex_lock(&c_node->mem_lock);
DRM_DEBUG_KMS("ops_id[%d]\n", m_node->ops_id);
ops = ippdrv->ops[m_node->ops_id];
if (!ops) {
DRM_ERROR("not support ops.\n");
ret = -EFAULT;
goto err_unlock;
}
if (ops->set_addr) {
ret = ops->set_addr(ippdrv->dev, &m_node->buf_info,
m_node->buf_id, IPP_BUF_ENQUEUE);
if (ret) {
DRM_ERROR("failed to set addr.\n");
goto err_unlock;
}
}
err_unlock:
mutex_unlock(&c_node->mem_lock);
return ret;
}
static struct drm_exynos_ipp_mem_node
*ipp_get_mem_node(struct drm_device *drm_dev,
struct drm_file *file,
struct drm_exynos_ipp_cmd_node *c_node,
struct drm_exynos_ipp_queue_buf *qbuf)
{
struct drm_exynos_ipp_mem_node *m_node;
struct drm_exynos_ipp_buf_info buf_info;
void *addr;
int i;
mutex_lock(&c_node->mem_lock);
m_node = kzalloc(sizeof(*m_node), GFP_KERNEL);
if (!m_node) {
DRM_ERROR("failed to allocate queue node.\n");
goto err_unlock;
}
memset(&buf_info, 0x0, sizeof(buf_info));
m_node->ops_id = qbuf->ops_id;
m_node->prop_id = qbuf->prop_id;
m_node->buf_id = qbuf->buf_id;
DRM_DEBUG_KMS("m_node[0x%x]ops_id[%d]\n", (int)m_node, qbuf->ops_id);
DRM_DEBUG_KMS("prop_id[%d]buf_id[%d]\n", qbuf->prop_id, m_node->buf_id);
for_each_ipp_planar(i) {
DRM_DEBUG_KMS("i[%d]handle[0x%x]\n", i, qbuf->handle[i]);
if (qbuf->handle[i]) {
addr = exynos_drm_gem_get_dma_addr(drm_dev,
qbuf->handle[i], file);
if (IS_ERR(addr)) {
DRM_ERROR("failed to get addr.\n");
goto err_clear;
}
buf_info.handles[i] = qbuf->handle[i];
buf_info.base[i] = *(dma_addr_t *) addr;
DRM_DEBUG_KMS("i[%d]base[0x%x]hd[0x%x]\n",
i, buf_info.base[i], (int)buf_info.handles[i]);
}
}
m_node->filp = file;
m_node->buf_info = buf_info;
list_add_tail(&m_node->list, &c_node->mem_list[qbuf->ops_id]);
mutex_unlock(&c_node->mem_lock);
return m_node;
err_clear:
kfree(m_node);
err_unlock:
mutex_unlock(&c_node->mem_lock);
return ERR_PTR(-EFAULT);
}
static int ipp_put_mem_node(struct drm_device *drm_dev,
struct drm_exynos_ipp_cmd_node *c_node,
struct drm_exynos_ipp_mem_node *m_node)
{
int i;
DRM_DEBUG_KMS("node[0x%x]\n", (int)m_node);
if (!m_node) {
DRM_ERROR("invalid dequeue node.\n");
return -EFAULT;
}
if (list_empty(&m_node->list)) {
DRM_ERROR("empty memory node.\n");
return -ENOMEM;
}
mutex_lock(&c_node->mem_lock);
DRM_DEBUG_KMS("ops_id[%d]\n", m_node->ops_id);
for_each_ipp_planar(i) {
unsigned long handle = m_node->buf_info.handles[i];
if (handle)
exynos_drm_gem_put_dma_addr(drm_dev, handle,
m_node->filp);
}
list_del(&m_node->list);
kfree(m_node);
mutex_unlock(&c_node->mem_lock);
return 0;
}
static void ipp_free_event(struct drm_pending_event *event)
{
kfree(event);
}
static int ipp_get_event(struct drm_device *drm_dev,
struct drm_file *file,
struct drm_exynos_ipp_cmd_node *c_node,
struct drm_exynos_ipp_queue_buf *qbuf)
{
struct drm_exynos_ipp_send_event *e;
unsigned long flags;
DRM_DEBUG_KMS("ops_id[%d]buf_id[%d]\n", qbuf->ops_id, qbuf->buf_id);
e = kzalloc(sizeof(*e), GFP_KERNEL);
if (!e) {
DRM_ERROR("failed to allocate event.\n");
spin_lock_irqsave(&drm_dev->event_lock, flags);
file->event_space += sizeof(e->event);
spin_unlock_irqrestore(&drm_dev->event_lock, flags);
return -ENOMEM;
}
e->event.base.type = DRM_EXYNOS_IPP_EVENT;
e->event.base.length = sizeof(e->event);
e->event.user_data = qbuf->user_data;
e->event.prop_id = qbuf->prop_id;
e->event.buf_id[EXYNOS_DRM_OPS_DST] = qbuf->buf_id;
e->base.event = &e->event.base;
e->base.file_priv = file;
e->base.destroy = ipp_free_event;
list_add_tail(&e->base.link, &c_node->event_list);
return 0;
}
static void ipp_put_event(struct drm_exynos_ipp_cmd_node *c_node,
struct drm_exynos_ipp_queue_buf *qbuf)
{
struct drm_exynos_ipp_send_event *e, *te;
int count = 0;
if (list_empty(&c_node->event_list)) {
DRM_DEBUG_KMS("event_list is empty.\n");
return;
}
list_for_each_entry_safe(e, te, &c_node->event_list, base.link) {
DRM_DEBUG_KMS("count[%d]e[0x%x]\n", count++, (int)e);
if (!qbuf) {
list_del(&e->base.link);
kfree(e);
}
if (qbuf && (qbuf->buf_id ==
e->event.buf_id[EXYNOS_DRM_OPS_DST])) {
list_del(&e->base.link);
kfree(e);
return;
}
}
}
static void ipp_handle_cmd_work(struct device *dev,
struct exynos_drm_ippdrv *ippdrv,
struct drm_exynos_ipp_cmd_work *cmd_work,
struct drm_exynos_ipp_cmd_node *c_node)
{
struct ipp_context *ctx = get_ipp_context(dev);
cmd_work->ippdrv = ippdrv;
cmd_work->c_node = c_node;
queue_work(ctx->cmd_workq, (struct work_struct *)cmd_work);
}
static int ipp_queue_buf_with_run(struct device *dev,
struct drm_exynos_ipp_cmd_node *c_node,
struct drm_exynos_ipp_mem_node *m_node,
struct drm_exynos_ipp_queue_buf *qbuf)
{
struct exynos_drm_ippdrv *ippdrv;
struct drm_exynos_ipp_property *property;
struct exynos_drm_ipp_ops *ops;
int ret;
ippdrv = ipp_find_drv_by_handle(qbuf->prop_id);
if (IS_ERR(ippdrv)) {
DRM_ERROR("failed to get ipp driver.\n");
return -EFAULT;
}
ops = ippdrv->ops[qbuf->ops_id];
if (!ops) {
DRM_ERROR("failed to get ops.\n");
return -EFAULT;
}
property = &c_node->property;
if (c_node->state != IPP_STATE_START) {
DRM_DEBUG_KMS("bypass for invalid state.\n");
return 0;
}
if (!ipp_check_mem_list(c_node)) {
DRM_DEBUG_KMS("empty memory.\n");
return 0;
}
if (ipp_is_m2m_cmd(property->cmd)) {
struct drm_exynos_ipp_cmd_work *cmd_work = c_node->start_work;
cmd_work->ctrl = IPP_CTRL_PLAY;
ipp_handle_cmd_work(dev, ippdrv, cmd_work, c_node);
} else {
ret = ipp_set_mem_node(ippdrv, c_node, m_node);
if (ret) {
DRM_ERROR("failed to set m node.\n");
return ret;
}
}
return 0;
}
static void ipp_clean_queue_buf(struct drm_device *drm_dev,
struct drm_exynos_ipp_cmd_node *c_node,
struct drm_exynos_ipp_queue_buf *qbuf)
{
struct drm_exynos_ipp_mem_node *m_node, *tm_node;
if (!list_empty(&c_node->mem_list[qbuf->ops_id])) {
list_for_each_entry_safe(m_node, tm_node,
&c_node->mem_list[qbuf->ops_id], list) {
if (m_node->buf_id == qbuf->buf_id &&
m_node->ops_id == qbuf->ops_id)
ipp_put_mem_node(drm_dev, c_node, m_node);
}
}
}
int exynos_drm_ipp_queue_buf(struct drm_device *drm_dev, void *data,
struct drm_file *file)
{
struct drm_exynos_file_private *file_priv = file->driver_priv;
struct exynos_drm_ipp_private *priv = file_priv->ipp_priv;
struct device *dev = priv->dev;
struct ipp_context *ctx = get_ipp_context(dev);
struct drm_exynos_ipp_queue_buf *qbuf = data;
struct drm_exynos_ipp_cmd_node *c_node;
struct drm_exynos_ipp_mem_node *m_node;
int ret;
if (!qbuf) {
DRM_ERROR("invalid buf parameter.\n");
return -EINVAL;
}
if (qbuf->ops_id >= EXYNOS_DRM_OPS_MAX) {
DRM_ERROR("invalid ops parameter.\n");
return -EINVAL;
}
DRM_DEBUG_KMS("prop_id[%d]ops_id[%s]buf_id[%d]buf_type[%d]\n",
qbuf->prop_id, qbuf->ops_id ? "dst" : "src",
qbuf->buf_id, qbuf->buf_type);
c_node = ipp_find_obj(&ctx->prop_idr, &ctx->prop_lock,
qbuf->prop_id);
if (IS_ERR(c_node)) {
DRM_ERROR("failed to get command node.\n");
return PTR_ERR(c_node);
}
switch (qbuf->buf_type) {
case IPP_BUF_ENQUEUE:
m_node = ipp_get_mem_node(drm_dev, file, c_node, qbuf);
if (IS_ERR(m_node)) {
DRM_ERROR("failed to get m_node.\n");
return PTR_ERR(m_node);
}
if (qbuf->ops_id == EXYNOS_DRM_OPS_DST) {
ret = ipp_get_event(drm_dev, file, c_node, qbuf);
if (ret) {
DRM_ERROR("failed to get event.\n");
goto err_clean_node;
}
ret = ipp_queue_buf_with_run(dev, c_node, m_node, qbuf);
if (ret) {
DRM_ERROR("failed to run command.\n");
goto err_clean_node;
}
}
break;
case IPP_BUF_DEQUEUE:
mutex_lock(&c_node->cmd_lock);
if (qbuf->ops_id == EXYNOS_DRM_OPS_DST)
ipp_put_event(c_node, qbuf);
ipp_clean_queue_buf(drm_dev, c_node, qbuf);
mutex_unlock(&c_node->cmd_lock);
break;
default:
DRM_ERROR("invalid buffer control.\n");
return -EINVAL;
}
return 0;
err_clean_node:
DRM_ERROR("clean memory nodes.\n");
ipp_clean_queue_buf(drm_dev, c_node, qbuf);
return ret;
}
static bool exynos_drm_ipp_check_valid(struct device *dev,
enum drm_exynos_ipp_ctrl ctrl, enum drm_exynos_ipp_state state)
{
if (ctrl != IPP_CTRL_PLAY) {
if (pm_runtime_suspended(dev)) {
DRM_ERROR("pm:runtime_suspended.\n");
goto err_status;
}
}
switch (ctrl) {
case IPP_CTRL_PLAY:
if (state != IPP_STATE_IDLE)
goto err_status;
break;
case IPP_CTRL_STOP:
if (state == IPP_STATE_STOP)
goto err_status;
break;
case IPP_CTRL_PAUSE:
if (state != IPP_STATE_START)
goto err_status;
break;
case IPP_CTRL_RESUME:
if (state != IPP_STATE_STOP)
goto err_status;
break;
default:
DRM_ERROR("invalid state.\n");
goto err_status;
}
return true;
err_status:
DRM_ERROR("invalid status:ctrl[%d]state[%d]\n", ctrl, state);
return false;
}
int exynos_drm_ipp_cmd_ctrl(struct drm_device *drm_dev, void *data,
struct drm_file *file)
{
struct drm_exynos_file_private *file_priv = file->driver_priv;
struct exynos_drm_ipp_private *priv = file_priv->ipp_priv;
struct exynos_drm_ippdrv *ippdrv = NULL;
struct device *dev = priv->dev;
struct ipp_context *ctx = get_ipp_context(dev);
struct drm_exynos_ipp_cmd_ctrl *cmd_ctrl = data;
struct drm_exynos_ipp_cmd_work *cmd_work;
struct drm_exynos_ipp_cmd_node *c_node;
if (!ctx) {
DRM_ERROR("invalid context.\n");
return -EINVAL;
}
if (!cmd_ctrl) {
DRM_ERROR("invalid control parameter.\n");
return -EINVAL;
}
DRM_DEBUG_KMS("ctrl[%d]prop_id[%d]\n",
cmd_ctrl->ctrl, cmd_ctrl->prop_id);
ippdrv = ipp_find_drv_by_handle(cmd_ctrl->prop_id);
if (IS_ERR(ippdrv)) {
DRM_ERROR("failed to get ipp driver.\n");
return PTR_ERR(ippdrv);
}
c_node = ipp_find_obj(&ctx->prop_idr, &ctx->prop_lock,
cmd_ctrl->prop_id);
if (IS_ERR(c_node)) {
DRM_ERROR("invalid command node list.\n");
return PTR_ERR(c_node);
}
if (!exynos_drm_ipp_check_valid(ippdrv->dev, cmd_ctrl->ctrl,
c_node->state)) {
DRM_ERROR("invalid state.\n");
return -EINVAL;
}
switch (cmd_ctrl->ctrl) {
case IPP_CTRL_PLAY:
if (pm_runtime_suspended(ippdrv->dev))
pm_runtime_get_sync(ippdrv->dev);
c_node->state = IPP_STATE_START;
cmd_work = c_node->start_work;
cmd_work->ctrl = cmd_ctrl->ctrl;
ipp_handle_cmd_work(dev, ippdrv, cmd_work, c_node);
c_node->state = IPP_STATE_START;
break;
case IPP_CTRL_STOP:
cmd_work = c_node->stop_work;
cmd_work->ctrl = cmd_ctrl->ctrl;
ipp_handle_cmd_work(dev, ippdrv, cmd_work, c_node);
if (!wait_for_completion_timeout(&c_node->stop_complete,
msecs_to_jiffies(300))) {
DRM_ERROR("timeout stop:prop_id[%d]\n",
c_node->property.prop_id);
}
c_node->state = IPP_STATE_STOP;
ippdrv->dedicated = false;
ipp_clean_cmd_node(c_node);
if (list_empty(&ippdrv->cmd_list))
pm_runtime_put_sync(ippdrv->dev);
break;
case IPP_CTRL_PAUSE:
cmd_work = c_node->stop_work;
cmd_work->ctrl = cmd_ctrl->ctrl;
ipp_handle_cmd_work(dev, ippdrv, cmd_work, c_node);
if (!wait_for_completion_timeout(&c_node->stop_complete,
msecs_to_jiffies(200))) {
DRM_ERROR("timeout stop:prop_id[%d]\n",
c_node->property.prop_id);
}
c_node->state = IPP_STATE_STOP;
break;
case IPP_CTRL_RESUME:
c_node->state = IPP_STATE_START;
cmd_work = c_node->start_work;
cmd_work->ctrl = cmd_ctrl->ctrl;
ipp_handle_cmd_work(dev, ippdrv, cmd_work, c_node);
break;
default:
DRM_ERROR("could not support this state currently.\n");
return -EINVAL;
}
DRM_DEBUG_KMS("done ctrl[%d]prop_id[%d]\n",
cmd_ctrl->ctrl, cmd_ctrl->prop_id);
return 0;
}
int exynos_drm_ippnb_register(struct notifier_block *nb)
{
return blocking_notifier_chain_register(
&exynos_drm_ippnb_list, nb);
}
int exynos_drm_ippnb_unregister(struct notifier_block *nb)
{
return blocking_notifier_chain_unregister(
&exynos_drm_ippnb_list, nb);
}
int exynos_drm_ippnb_send_event(unsigned long val, void *v)
{
return blocking_notifier_call_chain(
&exynos_drm_ippnb_list, val, v);
}
static int ipp_set_property(struct exynos_drm_ippdrv *ippdrv,
struct drm_exynos_ipp_property *property)
{
struct exynos_drm_ipp_ops *ops = NULL;
bool swap = false;
int ret, i;
if (!property) {
DRM_ERROR("invalid property parameter.\n");
return -EINVAL;
}
DRM_DEBUG_KMS("prop_id[%d]\n", property->prop_id);
if (ippdrv->reset &&
ippdrv->reset(ippdrv->dev)) {
DRM_ERROR("failed to reset.\n");
return -EINVAL;
}
for_each_ipp_ops(i) {
struct drm_exynos_ipp_config *config =
&property->config[i];
ops = ippdrv->ops[i];
if (!ops || !config) {
DRM_ERROR("not support ops and config.\n");
return -EINVAL;
}
if (ops->set_fmt) {
ret = ops->set_fmt(ippdrv->dev, config->fmt);
if (ret) {
DRM_ERROR("not support format.\n");
return ret;
}
}
if (ops->set_transf) {
ret = ops->set_transf(ippdrv->dev, config->degree,
config->flip, &swap);
if (ret) {
DRM_ERROR("not support tranf.\n");
return -EINVAL;
}
}
if (ops->set_size) {
ret = ops->set_size(ippdrv->dev, swap, &config->pos,
&config->sz);
if (ret) {
DRM_ERROR("not support size.\n");
return ret;
}
}
}
return 0;
}
static int ipp_start_property(struct exynos_drm_ippdrv *ippdrv,
struct drm_exynos_ipp_cmd_node *c_node)
{
struct drm_exynos_ipp_mem_node *m_node;
struct drm_exynos_ipp_property *property = &c_node->property;
struct list_head *head;
int ret, i;
DRM_DEBUG_KMS("prop_id[%d]\n", property->prop_id);
ippdrv->c_node = c_node;
if (!ipp_check_mem_list(c_node)) {
DRM_DEBUG_KMS("empty memory.\n");
return -ENOMEM;
}
ret = ipp_set_property(ippdrv, property);
if (ret) {
DRM_ERROR("failed to set property.\n");
ippdrv->c_node = NULL;
return ret;
}
switch (property->cmd) {
case IPP_CMD_M2M:
for_each_ipp_ops(i) {
head = &c_node->mem_list[i];
m_node = list_first_entry(head,
struct drm_exynos_ipp_mem_node, list);
if (!m_node) {
DRM_ERROR("failed to get node.\n");
ret = -EFAULT;
return ret;
}
DRM_DEBUG_KMS("m_node[0x%x]\n", (int)m_node);
ret = ipp_set_mem_node(ippdrv, c_node, m_node);
if (ret) {
DRM_ERROR("failed to set m node.\n");
return ret;
}
}
break;
case IPP_CMD_WB:
head = &c_node->mem_list[EXYNOS_DRM_OPS_DST];
list_for_each_entry(m_node, head, list) {
ret = ipp_set_mem_node(ippdrv, c_node, m_node);
if (ret) {
DRM_ERROR("failed to set m node.\n");
return ret;
}
}
break;
case IPP_CMD_OUTPUT:
head = &c_node->mem_list[EXYNOS_DRM_OPS_SRC];
list_for_each_entry(m_node, head, list) {
ret = ipp_set_mem_node(ippdrv, c_node, m_node);
if (ret) {
DRM_ERROR("failed to set m node.\n");
return ret;
}
}
break;
default:
DRM_ERROR("invalid operations.\n");
return -EINVAL;
}
DRM_DEBUG_KMS("cmd[%d]\n", property->cmd);
if (ippdrv->start) {
ret = ippdrv->start(ippdrv->dev, property->cmd);
if (ret) {
DRM_ERROR("failed to start ops.\n");
return ret;
}
}
return 0;
}
static int ipp_stop_property(struct drm_device *drm_dev,
struct exynos_drm_ippdrv *ippdrv,
struct drm_exynos_ipp_cmd_node *c_node)
{
struct drm_exynos_ipp_mem_node *m_node, *tm_node;
struct drm_exynos_ipp_property *property = &c_node->property;
struct list_head *head;
int ret = 0, i;
DRM_DEBUG_KMS("prop_id[%d]\n", property->prop_id);
ipp_put_event(c_node, NULL);
switch (property->cmd) {
case IPP_CMD_M2M:
for_each_ipp_ops(i) {
head = &c_node->mem_list[i];
if (list_empty(head)) {
DRM_DEBUG_KMS("mem_list is empty.\n");
break;
}
list_for_each_entry_safe(m_node, tm_node,
head, list) {
ret = ipp_put_mem_node(drm_dev, c_node,
m_node);
if (ret) {
DRM_ERROR("failed to put m_node.\n");
goto err_clear;
}
}
}
break;
case IPP_CMD_WB:
head = &c_node->mem_list[EXYNOS_DRM_OPS_DST];
if (list_empty(head)) {
DRM_DEBUG_KMS("mem_list is empty.\n");
break;
}
list_for_each_entry_safe(m_node, tm_node, head, list) {
ret = ipp_put_mem_node(drm_dev, c_node, m_node);
if (ret) {
DRM_ERROR("failed to put m_node.\n");
goto err_clear;
}
}
break;
case IPP_CMD_OUTPUT:
head = &c_node->mem_list[EXYNOS_DRM_OPS_SRC];
if (list_empty(head)) {
DRM_DEBUG_KMS("mem_list is empty.\n");
break;
}
list_for_each_entry_safe(m_node, tm_node, head, list) {
ret = ipp_put_mem_node(drm_dev, c_node, m_node);
if (ret) {
DRM_ERROR("failed to put m_node.\n");
goto err_clear;
}
}
break;
default:
DRM_ERROR("invalid operations.\n");
ret = -EINVAL;
goto err_clear;
}
err_clear:
if (ippdrv->stop)
ippdrv->stop(ippdrv->dev, property->cmd);
return ret;
}
void ipp_sched_cmd(struct work_struct *work)
{
struct drm_exynos_ipp_cmd_work *cmd_work =
(struct drm_exynos_ipp_cmd_work *)work;
struct exynos_drm_ippdrv *ippdrv;
struct drm_exynos_ipp_cmd_node *c_node;
struct drm_exynos_ipp_property *property;
int ret;
ippdrv = cmd_work->ippdrv;
if (!ippdrv) {
DRM_ERROR("invalid ippdrv list.\n");
return;
}
c_node = cmd_work->c_node;
if (!c_node) {
DRM_ERROR("invalid command node list.\n");
return;
}
mutex_lock(&c_node->cmd_lock);
property = &c_node->property;
switch (cmd_work->ctrl) {
case IPP_CTRL_PLAY:
case IPP_CTRL_RESUME:
ret = ipp_start_property(ippdrv, c_node);
if (ret) {
DRM_ERROR("failed to start property:prop_id[%d]\n",
c_node->property.prop_id);
goto err_unlock;
}
if (ipp_is_m2m_cmd(property->cmd)) {
if (!wait_for_completion_timeout
(&c_node->start_complete, msecs_to_jiffies(200))) {
DRM_ERROR("timeout event:prop_id[%d]\n",
c_node->property.prop_id);
goto err_unlock;
}
}
break;
case IPP_CTRL_STOP:
case IPP_CTRL_PAUSE:
ret = ipp_stop_property(ippdrv->drm_dev, ippdrv,
c_node);
if (ret) {
DRM_ERROR("failed to stop property.\n");
goto err_unlock;
}
complete(&c_node->stop_complete);
break;
default:
DRM_ERROR("unknown control type\n");
break;
}
DRM_DEBUG_KMS("ctrl[%d] done.\n", cmd_work->ctrl);
err_unlock:
mutex_unlock(&c_node->cmd_lock);
}
static int ipp_send_event(struct exynos_drm_ippdrv *ippdrv,
struct drm_exynos_ipp_cmd_node *c_node, int *buf_id)
{
struct drm_device *drm_dev = ippdrv->drm_dev;
struct drm_exynos_ipp_property *property = &c_node->property;
struct drm_exynos_ipp_mem_node *m_node;
struct drm_exynos_ipp_queue_buf qbuf;
struct drm_exynos_ipp_send_event *e;
struct list_head *head;
struct timeval now;
unsigned long flags;
u32 tbuf_id[EXYNOS_DRM_OPS_MAX] = {0, };
int ret, i;
for_each_ipp_ops(i)
DRM_DEBUG_KMS("%s buf_id[%d]\n", i ? "dst" : "src", buf_id[i]);
if (!drm_dev) {
DRM_ERROR("failed to get drm_dev.\n");
return -EINVAL;
}
if (!property) {
DRM_ERROR("failed to get property.\n");
return -EINVAL;
}
if (list_empty(&c_node->event_list)) {
DRM_DEBUG_KMS("event list is empty.\n");
return 0;
}
if (!ipp_check_mem_list(c_node)) {
DRM_DEBUG_KMS("empty memory.\n");
return 0;
}
switch (property->cmd) {
case IPP_CMD_M2M:
for_each_ipp_ops(i) {
head = &c_node->mem_list[i];
m_node = list_first_entry(head,
struct drm_exynos_ipp_mem_node, list);
if (!m_node) {
DRM_ERROR("empty memory node.\n");
return -ENOMEM;
}
tbuf_id[i] = m_node->buf_id;
DRM_DEBUG_KMS("%s buf_id[%d]\n",
i ? "dst" : "src", tbuf_id[i]);
ret = ipp_put_mem_node(drm_dev, c_node, m_node);
if (ret)
DRM_ERROR("failed to put m_node.\n");
}
break;
case IPP_CMD_WB:
memset(&qbuf, 0x0, sizeof(qbuf));
qbuf.ops_id = EXYNOS_DRM_OPS_DST;
qbuf.buf_id = buf_id[EXYNOS_DRM_OPS_DST];
m_node = ipp_find_mem_node(c_node, &qbuf);
if (!m_node) {
DRM_ERROR("empty memory node.\n");
return -ENOMEM;
}
tbuf_id[EXYNOS_DRM_OPS_DST] = m_node->buf_id;
ret = ipp_put_mem_node(drm_dev, c_node, m_node);
if (ret)
DRM_ERROR("failed to put m_node.\n");
break;
case IPP_CMD_OUTPUT:
head = &c_node->mem_list[EXYNOS_DRM_OPS_SRC];
m_node = list_first_entry(head,
struct drm_exynos_ipp_mem_node, list);
if (!m_node) {
DRM_ERROR("empty memory node.\n");
return -ENOMEM;
}
tbuf_id[EXYNOS_DRM_OPS_SRC] = m_node->buf_id;
ret = ipp_put_mem_node(drm_dev, c_node, m_node);
if (ret)
DRM_ERROR("failed to put m_node.\n");
break;
default:
DRM_ERROR("invalid operations.\n");
return -EINVAL;
}
if (tbuf_id[EXYNOS_DRM_OPS_DST] != buf_id[EXYNOS_DRM_OPS_DST])
DRM_ERROR("failed to match buf_id[%d %d]prop_id[%d]\n",
tbuf_id[1], buf_id[1], property->prop_id);
e = list_first_entry(&c_node->event_list,
struct drm_exynos_ipp_send_event, base.link);
if (!e) {
DRM_ERROR("empty event.\n");
return -EINVAL;
}
do_gettimeofday(&now);
DRM_DEBUG_KMS("tv_sec[%ld]tv_usec[%ld]\n", now.tv_sec, now.tv_usec);
e->event.tv_sec = now.tv_sec;
e->event.tv_usec = now.tv_usec;
e->event.prop_id = property->prop_id;
for_each_ipp_ops(i)
e->event.buf_id[i] = tbuf_id[i];
spin_lock_irqsave(&drm_dev->event_lock, flags);
list_move_tail(&e->base.link, &e->base.file_priv->event_list);
wake_up_interruptible(&e->base.file_priv->event_wait);
spin_unlock_irqrestore(&drm_dev->event_lock, flags);
DRM_DEBUG_KMS("done cmd[%d]prop_id[%d]buf_id[%d]\n",
property->cmd, property->prop_id, tbuf_id[EXYNOS_DRM_OPS_DST]);
return 0;
}
void ipp_sched_event(struct work_struct *work)
{
struct drm_exynos_ipp_event_work *event_work =
(struct drm_exynos_ipp_event_work *)work;
struct exynos_drm_ippdrv *ippdrv;
struct drm_exynos_ipp_cmd_node *c_node;
int ret;
if (!event_work) {
DRM_ERROR("failed to get event_work.\n");
return;
}
DRM_DEBUG_KMS("buf_id[%d]\n", event_work->buf_id[EXYNOS_DRM_OPS_DST]);
ippdrv = event_work->ippdrv;
if (!ippdrv) {
DRM_ERROR("failed to get ipp driver.\n");
return;
}
c_node = ippdrv->c_node;
if (!c_node) {
DRM_ERROR("failed to get command node.\n");
return;
}
if (c_node->state != IPP_STATE_START) {
DRM_DEBUG_KMS("bypass state[%d]prop_id[%d]\n",
c_node->state, c_node->property.prop_id);
goto err_completion;
}
mutex_lock(&c_node->event_lock);
ret = ipp_send_event(ippdrv, c_node, event_work->buf_id);
if (ret) {
DRM_ERROR("failed to send event.\n");
goto err_completion;
}
err_completion:
if (ipp_is_m2m_cmd(c_node->property.cmd))
complete(&c_node->start_complete);
mutex_unlock(&c_node->event_lock);
}
static int ipp_subdrv_probe(struct drm_device *drm_dev, struct device *dev)
{
struct ipp_context *ctx = get_ipp_context(dev);
struct exynos_drm_ippdrv *ippdrv;
int ret, count = 0;
list_for_each_entry(ippdrv, &exynos_drm_ippdrv_list, drv_list) {
ippdrv->drm_dev = drm_dev;
ret = ipp_create_id(&ctx->ipp_idr, &ctx->ipp_lock, ippdrv,
&ippdrv->ipp_id);
if (ret) {
DRM_ERROR("failed to create id.\n");
goto err_idr;
}
DRM_DEBUG_KMS("count[%d]ippdrv[0x%x]ipp_id[%d]\n",
count++, (int)ippdrv, ippdrv->ipp_id);
if (ippdrv->ipp_id == 0) {
DRM_ERROR("failed to get ipp_id[%d]\n",
ippdrv->ipp_id);
goto err_idr;
}
ippdrv->parent_dev = dev;
ippdrv->event_workq = ctx->event_workq;
ippdrv->sched_event = ipp_sched_event;
INIT_LIST_HEAD(&ippdrv->cmd_list);
if (is_drm_iommu_supported(drm_dev)) {
ret = drm_iommu_attach_device(drm_dev, ippdrv->dev);
if (ret) {
DRM_ERROR("failed to activate iommu\n");
goto err_iommu;
}
}
}
return 0;
err_iommu:
list_for_each_entry_reverse(ippdrv, &exynos_drm_ippdrv_list, drv_list)
if (is_drm_iommu_supported(drm_dev))
drm_iommu_detach_device(drm_dev, ippdrv->dev);
err_idr:
idr_destroy(&ctx->ipp_idr);
idr_destroy(&ctx->prop_idr);
return ret;
}
static void ipp_subdrv_remove(struct drm_device *drm_dev, struct device *dev)
{
struct exynos_drm_ippdrv *ippdrv;
list_for_each_entry(ippdrv, &exynos_drm_ippdrv_list, drv_list) {
if (is_drm_iommu_supported(drm_dev))
drm_iommu_detach_device(drm_dev, ippdrv->dev);
ippdrv->drm_dev = NULL;
exynos_drm_ippdrv_unregister(ippdrv);
}
}
static int ipp_subdrv_open(struct drm_device *drm_dev, struct device *dev,
struct drm_file *file)
{
struct drm_exynos_file_private *file_priv = file->driver_priv;
struct exynos_drm_ipp_private *priv;
priv = kzalloc(sizeof(*priv), GFP_KERNEL);
if (!priv) {
DRM_ERROR("failed to allocate priv.\n");
return -ENOMEM;
}
priv->dev = dev;
file_priv->ipp_priv = priv;
INIT_LIST_HEAD(&priv->event_list);
DRM_DEBUG_KMS("done priv[0x%x]\n", (int)priv);
return 0;
}
static void ipp_subdrv_close(struct drm_device *drm_dev, struct device *dev,
struct drm_file *file)
{
struct drm_exynos_file_private *file_priv = file->driver_priv;
struct exynos_drm_ipp_private *priv = file_priv->ipp_priv;
struct exynos_drm_ippdrv *ippdrv = NULL;
struct drm_exynos_ipp_cmd_node *c_node, *tc_node;
int count = 0;
DRM_DEBUG_KMS("for priv[0x%x]\n", (int)priv);
if (list_empty(&exynos_drm_ippdrv_list)) {
DRM_DEBUG_KMS("ippdrv_list is empty.\n");
goto err_clear;
}
list_for_each_entry(ippdrv, &exynos_drm_ippdrv_list, drv_list) {
if (list_empty(&ippdrv->cmd_list))
continue;
list_for_each_entry_safe(c_node, tc_node,
&ippdrv->cmd_list, list) {
DRM_DEBUG_KMS("count[%d]ippdrv[0x%x]\n",
count++, (int)ippdrv);
if (c_node->priv == priv) {
if (c_node->state == IPP_STATE_START) {
ipp_stop_property(drm_dev, ippdrv,
c_node);
c_node->state = IPP_STATE_STOP;
}
ippdrv->dedicated = false;
ipp_clean_cmd_node(c_node);
if (list_empty(&ippdrv->cmd_list))
pm_runtime_put_sync(ippdrv->dev);
}
}
}
err_clear:
kfree(priv);
return;
}
static int ipp_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct ipp_context *ctx;
struct exynos_drm_subdrv *subdrv;
int ret;
ctx = devm_kzalloc(dev, sizeof(*ctx), GFP_KERNEL);
if (!ctx)
return -ENOMEM;
mutex_init(&ctx->ipp_lock);
mutex_init(&ctx->prop_lock);
idr_init(&ctx->ipp_idr);
idr_init(&ctx->prop_idr);
ctx->event_workq = create_singlethread_workqueue("ipp_event");
if (!ctx->event_workq) {
dev_err(dev, "failed to create event workqueue\n");
return -EINVAL;
}
ctx->cmd_workq = create_singlethread_workqueue("ipp_cmd");
if (!ctx->cmd_workq) {
dev_err(dev, "failed to create cmd workqueue\n");
ret = -EINVAL;
goto err_event_workq;
}
subdrv = &ctx->subdrv;
subdrv->dev = dev;
subdrv->probe = ipp_subdrv_probe;
subdrv->remove = ipp_subdrv_remove;
subdrv->open = ipp_subdrv_open;
subdrv->close = ipp_subdrv_close;
platform_set_drvdata(pdev, ctx);
ret = exynos_drm_subdrv_register(subdrv);
if (ret < 0) {
DRM_ERROR("failed to register drm ipp device.\n");
goto err_cmd_workq;
}
dev_info(dev, "drm ipp registered successfully.\n");
return 0;
err_cmd_workq:
destroy_workqueue(ctx->cmd_workq);
err_event_workq:
destroy_workqueue(ctx->event_workq);
return ret;
}
static int ipp_remove(struct platform_device *pdev)
{
struct ipp_context *ctx = platform_get_drvdata(pdev);
exynos_drm_subdrv_unregister(&ctx->subdrv);
idr_destroy(&ctx->ipp_idr);
idr_destroy(&ctx->prop_idr);
mutex_destroy(&ctx->ipp_lock);
mutex_destroy(&ctx->prop_lock);
destroy_workqueue(ctx->cmd_workq);
destroy_workqueue(ctx->event_workq);
return 0;
}
static int ipp_power_ctrl(struct ipp_context *ctx, bool enable)
{
DRM_DEBUG_KMS("enable[%d]\n", enable);
return 0;
}
static int ipp_suspend(struct device *dev)
{
struct ipp_context *ctx = get_ipp_context(dev);
if (pm_runtime_suspended(dev))
return 0;
return ipp_power_ctrl(ctx, false);
}
static int ipp_resume(struct device *dev)
{
struct ipp_context *ctx = get_ipp_context(dev);
if (!pm_runtime_suspended(dev))
return ipp_power_ctrl(ctx, true);
return 0;
}
static int ipp_runtime_suspend(struct device *dev)
{
struct ipp_context *ctx = get_ipp_context(dev);
return ipp_power_ctrl(ctx, false);
}
static int ipp_runtime_resume(struct device *dev)
{
struct ipp_context *ctx = get_ipp_context(dev);
return ipp_power_ctrl(ctx, true);
}
