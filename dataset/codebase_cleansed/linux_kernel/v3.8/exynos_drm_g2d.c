static int g2d_init_cmdlist(struct g2d_data *g2d)
{
struct device *dev = g2d->dev;
struct g2d_cmdlist_node *node = g2d->cmdlist_node;
struct exynos_drm_subdrv *subdrv = &g2d->subdrv;
int nr;
int ret;
init_dma_attrs(&g2d->cmdlist_dma_attrs);
dma_set_attr(DMA_ATTR_WRITE_COMBINE, &g2d->cmdlist_dma_attrs);
g2d->cmdlist_pool_virt = dma_alloc_attrs(subdrv->drm_dev->dev,
G2D_CMDLIST_POOL_SIZE,
&g2d->cmdlist_pool, GFP_KERNEL,
&g2d->cmdlist_dma_attrs);
if (!g2d->cmdlist_pool_virt) {
dev_err(dev, "failed to allocate dma memory\n");
return -ENOMEM;
}
node = kcalloc(G2D_CMDLIST_NUM, sizeof(*node), GFP_KERNEL);
if (!node) {
dev_err(dev, "failed to allocate memory\n");
ret = -ENOMEM;
goto err;
}
for (nr = 0; nr < G2D_CMDLIST_NUM; nr++) {
node[nr].cmdlist =
g2d->cmdlist_pool_virt + nr * G2D_CMDLIST_SIZE;
node[nr].dma_addr =
g2d->cmdlist_pool + nr * G2D_CMDLIST_SIZE;
list_add_tail(&node[nr].list, &g2d->free_cmdlist);
}
return 0;
err:
dma_free_attrs(subdrv->drm_dev->dev, G2D_CMDLIST_POOL_SIZE,
g2d->cmdlist_pool_virt,
g2d->cmdlist_pool, &g2d->cmdlist_dma_attrs);
return ret;
}
static void g2d_fini_cmdlist(struct g2d_data *g2d)
{
struct exynos_drm_subdrv *subdrv = &g2d->subdrv;
kfree(g2d->cmdlist_node);
dma_free_attrs(subdrv->drm_dev->dev, G2D_CMDLIST_POOL_SIZE,
g2d->cmdlist_pool_virt,
g2d->cmdlist_pool, &g2d->cmdlist_dma_attrs);
}
static struct g2d_cmdlist_node *g2d_get_cmdlist(struct g2d_data *g2d)
{
struct device *dev = g2d->dev;
struct g2d_cmdlist_node *node;
mutex_lock(&g2d->cmdlist_mutex);
if (list_empty(&g2d->free_cmdlist)) {
dev_err(dev, "there is no free cmdlist\n");
mutex_unlock(&g2d->cmdlist_mutex);
return NULL;
}
node = list_first_entry(&g2d->free_cmdlist, struct g2d_cmdlist_node,
list);
list_del_init(&node->list);
mutex_unlock(&g2d->cmdlist_mutex);
return node;
}
static void g2d_put_cmdlist(struct g2d_data *g2d, struct g2d_cmdlist_node *node)
{
mutex_lock(&g2d->cmdlist_mutex);
list_move_tail(&node->list, &g2d->free_cmdlist);
mutex_unlock(&g2d->cmdlist_mutex);
}
static void g2d_add_cmdlist_to_inuse(struct exynos_drm_g2d_private *g2d_priv,
struct g2d_cmdlist_node *node)
{
struct g2d_cmdlist_node *lnode;
if (list_empty(&g2d_priv->inuse_cmdlist))
goto add_to_list;
lnode = list_entry(g2d_priv->inuse_cmdlist.prev,
struct g2d_cmdlist_node, list);
lnode->cmdlist->data[lnode->cmdlist->last] = node->dma_addr;
add_to_list:
list_add_tail(&node->list, &g2d_priv->inuse_cmdlist);
if (node->event)
list_add_tail(&node->event->base.link, &g2d_priv->event_list);
}
static void g2d_userptr_put_dma_addr(struct drm_device *drm_dev,
unsigned long obj,
bool force)
{
struct g2d_cmdlist_userptr *g2d_userptr =
(struct g2d_cmdlist_userptr *)obj;
if (!obj)
return;
if (force)
goto out;
atomic_dec(&g2d_userptr->refcount);
if (atomic_read(&g2d_userptr->refcount) > 0)
return;
if (g2d_userptr->in_pool)
return;
out:
exynos_gem_unmap_sgt_from_dma(drm_dev, g2d_userptr->sgt,
DMA_BIDIRECTIONAL);
exynos_gem_put_pages_to_userptr(g2d_userptr->pages,
g2d_userptr->npages,
g2d_userptr->vma);
if (!g2d_userptr->out_of_list)
list_del_init(&g2d_userptr->list);
sg_free_table(g2d_userptr->sgt);
kfree(g2d_userptr->sgt);
g2d_userptr->sgt = NULL;
kfree(g2d_userptr->pages);
g2d_userptr->pages = NULL;
kfree(g2d_userptr);
g2d_userptr = NULL;
}
static dma_addr_t *g2d_userptr_get_dma_addr(struct drm_device *drm_dev,
unsigned long userptr,
unsigned long size,
struct drm_file *filp,
unsigned long *obj)
{
struct drm_exynos_file_private *file_priv = filp->driver_priv;
struct exynos_drm_g2d_private *g2d_priv = file_priv->g2d_priv;
struct g2d_cmdlist_userptr *g2d_userptr;
struct g2d_data *g2d;
struct page **pages;
struct sg_table *sgt;
struct vm_area_struct *vma;
unsigned long start, end;
unsigned int npages, offset;
int ret;
if (!size) {
DRM_ERROR("invalid userptr size.\n");
return ERR_PTR(-EINVAL);
}
g2d = dev_get_drvdata(g2d_priv->dev);
list_for_each_entry(g2d_userptr, &g2d_priv->userptr_list, list) {
if (g2d_userptr->userptr == userptr) {
if (g2d_userptr->size == size) {
atomic_inc(&g2d_userptr->refcount);
*obj = (unsigned long)g2d_userptr;
return &g2d_userptr->dma_addr;
}
g2d_userptr->out_of_list = true;
g2d_userptr->in_pool = false;
list_del_init(&g2d_userptr->list);
break;
}
}
g2d_userptr = kzalloc(sizeof(*g2d_userptr), GFP_KERNEL);
if (!g2d_userptr) {
DRM_ERROR("failed to allocate g2d_userptr.\n");
return ERR_PTR(-ENOMEM);
}
atomic_set(&g2d_userptr->refcount, 1);
start = userptr & PAGE_MASK;
offset = userptr & ~PAGE_MASK;
end = PAGE_ALIGN(userptr + size);
npages = (end - start) >> PAGE_SHIFT;
g2d_userptr->npages = npages;
pages = kzalloc(npages * sizeof(struct page *), GFP_KERNEL);
if (!pages) {
DRM_ERROR("failed to allocate pages.\n");
kfree(g2d_userptr);
return ERR_PTR(-ENOMEM);
}
vma = find_vma(current->mm, userptr);
if (!vma) {
DRM_ERROR("failed to get vm region.\n");
ret = -EFAULT;
goto err_free_pages;
}
if (vma->vm_end < userptr + size) {
DRM_ERROR("vma is too small.\n");
ret = -EFAULT;
goto err_free_pages;
}
g2d_userptr->vma = exynos_gem_get_vma(vma);
if (!g2d_userptr->vma) {
DRM_ERROR("failed to copy vma.\n");
ret = -ENOMEM;
goto err_free_pages;
}
g2d_userptr->size = size;
ret = exynos_gem_get_pages_from_userptr(start & PAGE_MASK,
npages, pages, vma);
if (ret < 0) {
DRM_ERROR("failed to get user pages from userptr.\n");
goto err_put_vma;
}
g2d_userptr->pages = pages;
sgt = kzalloc(sizeof *sgt, GFP_KERNEL);
if (!sgt) {
DRM_ERROR("failed to allocate sg table.\n");
ret = -ENOMEM;
goto err_free_userptr;
}
ret = sg_alloc_table_from_pages(sgt, pages, npages, offset,
size, GFP_KERNEL);
if (ret < 0) {
DRM_ERROR("failed to get sgt from pages.\n");
goto err_free_sgt;
}
g2d_userptr->sgt = sgt;
ret = exynos_gem_map_sgt_with_dma(drm_dev, g2d_userptr->sgt,
DMA_BIDIRECTIONAL);
if (ret < 0) {
DRM_ERROR("failed to map sgt with dma region.\n");
goto err_free_sgt;
}
g2d_userptr->dma_addr = sgt->sgl[0].dma_address;
g2d_userptr->userptr = userptr;
list_add_tail(&g2d_userptr->list, &g2d_priv->userptr_list);
if (g2d->current_pool + (npages << PAGE_SHIFT) < g2d->max_pool) {
g2d->current_pool += npages << PAGE_SHIFT;
g2d_userptr->in_pool = true;
}
*obj = (unsigned long)g2d_userptr;
return &g2d_userptr->dma_addr;
err_free_sgt:
sg_free_table(sgt);
kfree(sgt);
sgt = NULL;
err_free_userptr:
exynos_gem_put_pages_to_userptr(g2d_userptr->pages,
g2d_userptr->npages,
g2d_userptr->vma);
err_put_vma:
exynos_gem_put_vma(g2d_userptr->vma);
err_free_pages:
kfree(pages);
kfree(g2d_userptr);
pages = NULL;
g2d_userptr = NULL;
return ERR_PTR(ret);
}
static void g2d_userptr_free_all(struct drm_device *drm_dev,
struct g2d_data *g2d,
struct drm_file *filp)
{
struct drm_exynos_file_private *file_priv = filp->driver_priv;
struct exynos_drm_g2d_private *g2d_priv = file_priv->g2d_priv;
struct g2d_cmdlist_userptr *g2d_userptr, *n;
list_for_each_entry_safe(g2d_userptr, n, &g2d_priv->userptr_list, list)
if (g2d_userptr->in_pool)
g2d_userptr_put_dma_addr(drm_dev,
(unsigned long)g2d_userptr,
true);
g2d->current_pool = 0;
}
static int g2d_map_cmdlist_gem(struct g2d_data *g2d,
struct g2d_cmdlist_node *node,
struct drm_device *drm_dev,
struct drm_file *file)
{
struct g2d_cmdlist *cmdlist = node->cmdlist;
int offset;
int i;
for (i = 0; i < node->map_nr; i++) {
unsigned long handle;
dma_addr_t *addr;
offset = cmdlist->last - (i * 2 + 1);
handle = cmdlist->data[offset];
if (node->obj_type[i] == BUF_TYPE_GEM) {
addr = exynos_drm_gem_get_dma_addr(drm_dev, handle,
file);
if (IS_ERR(addr)) {
node->map_nr = i;
return -EFAULT;
}
} else {
struct drm_exynos_g2d_userptr g2d_userptr;
if (copy_from_user(&g2d_userptr, (void __user *)handle,
sizeof(struct drm_exynos_g2d_userptr))) {
node->map_nr = i;
return -EFAULT;
}
addr = g2d_userptr_get_dma_addr(drm_dev,
g2d_userptr.userptr,
g2d_userptr.size,
file,
&handle);
if (IS_ERR(addr)) {
node->map_nr = i;
return -EFAULT;
}
}
cmdlist->data[offset] = *addr;
node->handles[i] = handle;
}
return 0;
}
static void g2d_unmap_cmdlist_gem(struct g2d_data *g2d,
struct g2d_cmdlist_node *node,
struct drm_file *filp)
{
struct exynos_drm_subdrv *subdrv = &g2d->subdrv;
int i;
for (i = 0; i < node->map_nr; i++) {
unsigned long handle = node->handles[i];
if (node->obj_type[i] == BUF_TYPE_GEM)
exynos_drm_gem_put_dma_addr(subdrv->drm_dev, handle,
filp);
else
g2d_userptr_put_dma_addr(subdrv->drm_dev, handle,
false);
node->handles[i] = 0;
}
node->map_nr = 0;
}
static void g2d_dma_start(struct g2d_data *g2d,
struct g2d_runqueue_node *runqueue_node)
{
struct g2d_cmdlist_node *node =
list_first_entry(&runqueue_node->run_cmdlist,
struct g2d_cmdlist_node, list);
pm_runtime_get_sync(g2d->dev);
clk_enable(g2d->gate_clk);
writel_relaxed(G2D_INTEN_ACF | G2D_INTEN_UCF | G2D_INTEN_GCF,
g2d->regs + G2D_INTEN);
writel_relaxed(node->dma_addr, g2d->regs + G2D_DMA_SFR_BASE_ADDR);
writel_relaxed(G2D_DMA_START, g2d->regs + G2D_DMA_COMMAND);
}
static struct g2d_runqueue_node *g2d_get_runqueue_node(struct g2d_data *g2d)
{
struct g2d_runqueue_node *runqueue_node;
if (list_empty(&g2d->runqueue))
return NULL;
runqueue_node = list_first_entry(&g2d->runqueue,
struct g2d_runqueue_node, list);
list_del_init(&runqueue_node->list);
return runqueue_node;
}
static void g2d_free_runqueue_node(struct g2d_data *g2d,
struct g2d_runqueue_node *runqueue_node)
{
struct g2d_cmdlist_node *node;
if (!runqueue_node)
return;
mutex_lock(&g2d->cmdlist_mutex);
list_for_each_entry(node, &runqueue_node->run_cmdlist, list)
g2d_unmap_cmdlist_gem(g2d, node, runqueue_node->filp);
list_splice_tail_init(&runqueue_node->run_cmdlist, &g2d->free_cmdlist);
mutex_unlock(&g2d->cmdlist_mutex);
kmem_cache_free(g2d->runqueue_slab, runqueue_node);
}
static void g2d_exec_runqueue(struct g2d_data *g2d)
{
g2d->runqueue_node = g2d_get_runqueue_node(g2d);
if (g2d->runqueue_node)
g2d_dma_start(g2d, g2d->runqueue_node);
}
static void g2d_runqueue_worker(struct work_struct *work)
{
struct g2d_data *g2d = container_of(work, struct g2d_data,
runqueue_work);
mutex_lock(&g2d->runqueue_mutex);
clk_disable(g2d->gate_clk);
pm_runtime_put_sync(g2d->dev);
complete(&g2d->runqueue_node->complete);
if (g2d->runqueue_node->async)
g2d_free_runqueue_node(g2d, g2d->runqueue_node);
if (g2d->suspended)
g2d->runqueue_node = NULL;
else
g2d_exec_runqueue(g2d);
mutex_unlock(&g2d->runqueue_mutex);
}
static void g2d_finish_event(struct g2d_data *g2d, u32 cmdlist_no)
{
struct drm_device *drm_dev = g2d->subdrv.drm_dev;
struct g2d_runqueue_node *runqueue_node = g2d->runqueue_node;
struct drm_exynos_pending_g2d_event *e;
struct timeval now;
unsigned long flags;
if (list_empty(&runqueue_node->event_list))
return;
e = list_first_entry(&runqueue_node->event_list,
struct drm_exynos_pending_g2d_event, base.link);
do_gettimeofday(&now);
e->event.tv_sec = now.tv_sec;
e->event.tv_usec = now.tv_usec;
e->event.cmdlist_no = cmdlist_no;
spin_lock_irqsave(&drm_dev->event_lock, flags);
list_move_tail(&e->base.link, &e->base.file_priv->event_list);
wake_up_interruptible(&e->base.file_priv->event_wait);
spin_unlock_irqrestore(&drm_dev->event_lock, flags);
}
static irqreturn_t g2d_irq_handler(int irq, void *dev_id)
{
struct g2d_data *g2d = dev_id;
u32 pending;
pending = readl_relaxed(g2d->regs + G2D_INTC_PEND);
if (pending)
writel_relaxed(pending, g2d->regs + G2D_INTC_PEND);
if (pending & G2D_INTP_GCMD_FIN) {
u32 cmdlist_no = readl_relaxed(g2d->regs + G2D_DMA_STATUS);
cmdlist_no = (cmdlist_no & G2D_DMA_LIST_DONE_COUNT) >>
G2D_DMA_LIST_DONE_COUNT_OFFSET;
g2d_finish_event(g2d, cmdlist_no);
writel_relaxed(0, g2d->regs + G2D_DMA_HOLD_CMD);
if (!(pending & G2D_INTP_ACMD_FIN)) {
writel_relaxed(G2D_DMA_CONTINUE,
g2d->regs + G2D_DMA_COMMAND);
}
}
if (pending & G2D_INTP_ACMD_FIN)
queue_work(g2d->g2d_workq, &g2d->runqueue_work);
return IRQ_HANDLED;
}
static int g2d_check_reg_offset(struct device *dev,
struct g2d_cmdlist_node *node,
int nr, bool for_addr)
{
struct g2d_cmdlist *cmdlist = node->cmdlist;
int reg_offset;
int index;
int i;
for (i = 0; i < nr; i++) {
index = cmdlist->last - 2 * (i + 1);
if (for_addr) {
reg_offset = (cmdlist->data[index] &
~0x7fffffff) >> 31;
if (reg_offset) {
node->obj_type[i] = BUF_TYPE_USERPTR;
cmdlist->data[index] &= ~G2D_BUF_USERPTR;
}
}
reg_offset = cmdlist->data[index] & ~0xfffff000;
if (reg_offset < G2D_VALID_START || reg_offset > G2D_VALID_END)
goto err;
if (reg_offset % 4)
goto err;
switch (reg_offset) {
case G2D_SRC_BASE_ADDR:
case G2D_SRC_PLANE2_BASE_ADDR:
case G2D_DST_BASE_ADDR:
case G2D_DST_PLANE2_BASE_ADDR:
case G2D_PAT_BASE_ADDR:
case G2D_MSK_BASE_ADDR:
if (!for_addr)
goto err;
if (node->obj_type[i] != BUF_TYPE_USERPTR)
node->obj_type[i] = BUF_TYPE_GEM;
break;
default:
if (for_addr)
goto err;
break;
}
}
return 0;
err:
dev_err(dev, "Bad register offset: 0x%lx\n", cmdlist->data[index]);
return -EINVAL;
}
int exynos_g2d_get_ver_ioctl(struct drm_device *drm_dev, void *data,
struct drm_file *file)
{
struct drm_exynos_g2d_get_ver *ver = data;
ver->major = G2D_HW_MAJOR_VER;
ver->minor = G2D_HW_MINOR_VER;
return 0;
}
int exynos_g2d_set_cmdlist_ioctl(struct drm_device *drm_dev, void *data,
struct drm_file *file)
{
struct drm_exynos_file_private *file_priv = file->driver_priv;
struct exynos_drm_g2d_private *g2d_priv = file_priv->g2d_priv;
struct device *dev = g2d_priv->dev;
struct g2d_data *g2d;
struct drm_exynos_g2d_set_cmdlist *req = data;
struct drm_exynos_g2d_cmd *cmd;
struct drm_exynos_pending_g2d_event *e;
struct g2d_cmdlist_node *node;
struct g2d_cmdlist *cmdlist;
unsigned long flags;
int size;
int ret;
if (!dev)
return -ENODEV;
g2d = dev_get_drvdata(dev);
if (!g2d)
return -EFAULT;
node = g2d_get_cmdlist(g2d);
if (!node)
return -ENOMEM;
node->event = NULL;
if (req->event_type != G2D_EVENT_NOT) {
spin_lock_irqsave(&drm_dev->event_lock, flags);
if (file->event_space < sizeof(e->event)) {
spin_unlock_irqrestore(&drm_dev->event_lock, flags);
ret = -ENOMEM;
goto err;
}
file->event_space -= sizeof(e->event);
spin_unlock_irqrestore(&drm_dev->event_lock, flags);
e = kzalloc(sizeof(*node->event), GFP_KERNEL);
if (!e) {
dev_err(dev, "failed to allocate event\n");
spin_lock_irqsave(&drm_dev->event_lock, flags);
file->event_space += sizeof(e->event);
spin_unlock_irqrestore(&drm_dev->event_lock, flags);
ret = -ENOMEM;
goto err;
}
e->event.base.type = DRM_EXYNOS_G2D_EVENT;
e->event.base.length = sizeof(e->event);
e->event.user_data = req->user_data;
e->base.event = &e->event.base;
e->base.file_priv = file;
e->base.destroy = (void (*) (struct drm_pending_event *)) kfree;
node->event = e;
}
cmdlist = node->cmdlist;
cmdlist->last = 0;
cmdlist->data[cmdlist->last++] = G2D_SOFT_RESET;
cmdlist->data[cmdlist->last++] = G2D_SFRCLEAR;
cmdlist->data[cmdlist->last++] = G2D_SRC_BASE_ADDR;
cmdlist->data[cmdlist->last++] = 0;
if (node->event) {
cmdlist->data[cmdlist->last++] = G2D_DMA_HOLD_CMD;
cmdlist->data[cmdlist->last++] = G2D_LIST_HOLD;
}
size = cmdlist->last + req->cmd_nr * 2 + req->cmd_buf_nr * 2 + 2;
if (size > G2D_CMDLIST_DATA_NUM) {
dev_err(dev, "cmdlist size is too big\n");
ret = -EINVAL;
goto err_free_event;
}
cmd = (struct drm_exynos_g2d_cmd *)(uint32_t)req->cmd;
if (copy_from_user(cmdlist->data + cmdlist->last,
(void __user *)cmd,
sizeof(*cmd) * req->cmd_nr)) {
ret = -EFAULT;
goto err_free_event;
}
cmdlist->last += req->cmd_nr * 2;
ret = g2d_check_reg_offset(dev, node, req->cmd_nr, false);
if (ret < 0)
goto err_free_event;
node->map_nr = req->cmd_buf_nr;
if (req->cmd_buf_nr) {
struct drm_exynos_g2d_cmd *cmd_buf;
cmd_buf = (struct drm_exynos_g2d_cmd *)(uint32_t)req->cmd_buf;
if (copy_from_user(cmdlist->data + cmdlist->last,
(void __user *)cmd_buf,
sizeof(*cmd_buf) * req->cmd_buf_nr)) {
ret = -EFAULT;
goto err_free_event;
}
cmdlist->last += req->cmd_buf_nr * 2;
ret = g2d_check_reg_offset(dev, node, req->cmd_buf_nr, true);
if (ret < 0)
goto err_free_event;
ret = g2d_map_cmdlist_gem(g2d, node, drm_dev, file);
if (ret < 0)
goto err_unmap;
}
cmdlist->data[cmdlist->last++] = G2D_BITBLT_START;
cmdlist->data[cmdlist->last++] = G2D_START_BITBLT;
cmdlist->head = cmdlist->last / 2;
cmdlist->data[cmdlist->last] = 0;
g2d_add_cmdlist_to_inuse(g2d_priv, node);
return 0;
err_unmap:
g2d_unmap_cmdlist_gem(g2d, node, file);
err_free_event:
if (node->event) {
spin_lock_irqsave(&drm_dev->event_lock, flags);
file->event_space += sizeof(e->event);
spin_unlock_irqrestore(&drm_dev->event_lock, flags);
kfree(node->event);
}
err:
g2d_put_cmdlist(g2d, node);
return ret;
}
int exynos_g2d_exec_ioctl(struct drm_device *drm_dev, void *data,
struct drm_file *file)
{
struct drm_exynos_file_private *file_priv = file->driver_priv;
struct exynos_drm_g2d_private *g2d_priv = file_priv->g2d_priv;
struct device *dev = g2d_priv->dev;
struct g2d_data *g2d;
struct drm_exynos_g2d_exec *req = data;
struct g2d_runqueue_node *runqueue_node;
struct list_head *run_cmdlist;
struct list_head *event_list;
if (!dev)
return -ENODEV;
g2d = dev_get_drvdata(dev);
if (!g2d)
return -EFAULT;
runqueue_node = kmem_cache_alloc(g2d->runqueue_slab, GFP_KERNEL);
if (!runqueue_node) {
dev_err(dev, "failed to allocate memory\n");
return -ENOMEM;
}
run_cmdlist = &runqueue_node->run_cmdlist;
event_list = &runqueue_node->event_list;
INIT_LIST_HEAD(run_cmdlist);
INIT_LIST_HEAD(event_list);
init_completion(&runqueue_node->complete);
runqueue_node->async = req->async;
list_splice_init(&g2d_priv->inuse_cmdlist, run_cmdlist);
list_splice_init(&g2d_priv->event_list, event_list);
if (list_empty(run_cmdlist)) {
dev_err(dev, "there is no inuse cmdlist\n");
kmem_cache_free(g2d->runqueue_slab, runqueue_node);
return -EPERM;
}
mutex_lock(&g2d->runqueue_mutex);
runqueue_node->pid = current->pid;
runqueue_node->filp = file;
list_add_tail(&runqueue_node->list, &g2d->runqueue);
if (!g2d->runqueue_node)
g2d_exec_runqueue(g2d);
mutex_unlock(&g2d->runqueue_mutex);
if (runqueue_node->async)
goto out;
wait_for_completion(&runqueue_node->complete);
g2d_free_runqueue_node(g2d, runqueue_node);
out:
return 0;
}
static int g2d_subdrv_probe(struct drm_device *drm_dev, struct device *dev)
{
struct g2d_data *g2d;
int ret;
g2d = dev_get_drvdata(dev);
if (!g2d)
return -EFAULT;
ret = g2d_init_cmdlist(g2d);
if (ret < 0) {
dev_err(dev, "cmdlist init failed\n");
return ret;
}
if (!is_drm_iommu_supported(drm_dev))
return 0;
ret = drm_iommu_attach_device(drm_dev, dev);
if (ret < 0) {
dev_err(dev, "failed to enable iommu.\n");
g2d_fini_cmdlist(g2d);
}
return ret;
}
static void g2d_subdrv_remove(struct drm_device *drm_dev, struct device *dev)
{
if (!is_drm_iommu_supported(drm_dev))
return;
drm_iommu_detach_device(drm_dev, dev);
}
static int g2d_open(struct drm_device *drm_dev, struct device *dev,
struct drm_file *file)
{
struct drm_exynos_file_private *file_priv = file->driver_priv;
struct exynos_drm_g2d_private *g2d_priv;
g2d_priv = kzalloc(sizeof(*g2d_priv), GFP_KERNEL);
if (!g2d_priv) {
dev_err(dev, "failed to allocate g2d private data\n");
return -ENOMEM;
}
g2d_priv->dev = dev;
file_priv->g2d_priv = g2d_priv;
INIT_LIST_HEAD(&g2d_priv->inuse_cmdlist);
INIT_LIST_HEAD(&g2d_priv->event_list);
INIT_LIST_HEAD(&g2d_priv->userptr_list);
return 0;
}
static void g2d_close(struct drm_device *drm_dev, struct device *dev,
struct drm_file *file)
{
struct drm_exynos_file_private *file_priv = file->driver_priv;
struct exynos_drm_g2d_private *g2d_priv = file_priv->g2d_priv;
struct g2d_data *g2d;
struct g2d_cmdlist_node *node, *n;
if (!dev)
return;
g2d = dev_get_drvdata(dev);
if (!g2d)
return;
mutex_lock(&g2d->cmdlist_mutex);
list_for_each_entry_safe(node, n, &g2d_priv->inuse_cmdlist, list) {
g2d_unmap_cmdlist_gem(g2d, node, file);
list_move_tail(&node->list, &g2d->free_cmdlist);
}
mutex_unlock(&g2d->cmdlist_mutex);
g2d_userptr_free_all(drm_dev, g2d, file);
kfree(file_priv->g2d_priv);
}
static int g2d_probe(struct platform_device *pdev)
{
struct device *dev = &pdev->dev;
struct resource *res;
struct g2d_data *g2d;
struct exynos_drm_subdrv *subdrv;
int ret;
g2d = devm_kzalloc(&pdev->dev, sizeof(*g2d), GFP_KERNEL);
if (!g2d) {
dev_err(dev, "failed to allocate driver data\n");
return -ENOMEM;
}
g2d->runqueue_slab = kmem_cache_create("g2d_runqueue_slab",
sizeof(struct g2d_runqueue_node), 0, 0, NULL);
if (!g2d->runqueue_slab)
return -ENOMEM;
g2d->dev = dev;
g2d->g2d_workq = create_singlethread_workqueue("g2d");
if (!g2d->g2d_workq) {
dev_err(dev, "failed to create workqueue\n");
ret = -EINVAL;
goto err_destroy_slab;
}
INIT_WORK(&g2d->runqueue_work, g2d_runqueue_worker);
INIT_LIST_HEAD(&g2d->free_cmdlist);
INIT_LIST_HEAD(&g2d->runqueue);
mutex_init(&g2d->cmdlist_mutex);
mutex_init(&g2d->runqueue_mutex);
g2d->gate_clk = devm_clk_get(dev, "fimg2d");
if (IS_ERR(g2d->gate_clk)) {
dev_err(dev, "failed to get gate clock\n");
ret = PTR_ERR(g2d->gate_clk);
goto err_destroy_workqueue;
}
pm_runtime_enable(dev);
res = platform_get_resource(pdev, IORESOURCE_MEM, 0);
g2d->regs = devm_request_and_ioremap(&pdev->dev, res);
if (!g2d->regs) {
dev_err(dev, "failed to remap I/O memory\n");
ret = -ENXIO;
goto err_put_clk;
}
g2d->irq = platform_get_irq(pdev, 0);
if (g2d->irq < 0) {
dev_err(dev, "failed to get irq\n");
ret = g2d->irq;
goto err_put_clk;
}
ret = devm_request_irq(&pdev->dev, g2d->irq, g2d_irq_handler, 0,
"drm_g2d", g2d);
if (ret < 0) {
dev_err(dev, "irq request failed\n");
goto err_put_clk;
}
g2d->max_pool = MAX_POOL;
platform_set_drvdata(pdev, g2d);
subdrv = &g2d->subdrv;
subdrv->dev = dev;
subdrv->probe = g2d_subdrv_probe;
subdrv->remove = g2d_subdrv_remove;
subdrv->open = g2d_open;
subdrv->close = g2d_close;
ret = exynos_drm_subdrv_register(subdrv);
if (ret < 0) {
dev_err(dev, "failed to register drm g2d device\n");
goto err_put_clk;
}
dev_info(dev, "The exynos g2d(ver %d.%d) successfully probed\n",
G2D_HW_MAJOR_VER, G2D_HW_MINOR_VER);
return 0;
err_put_clk:
pm_runtime_disable(dev);
err_destroy_workqueue:
destroy_workqueue(g2d->g2d_workq);
err_destroy_slab:
kmem_cache_destroy(g2d->runqueue_slab);
return ret;
}
static int g2d_remove(struct platform_device *pdev)
{
struct g2d_data *g2d = platform_get_drvdata(pdev);
cancel_work_sync(&g2d->runqueue_work);
exynos_drm_subdrv_unregister(&g2d->subdrv);
while (g2d->runqueue_node) {
g2d_free_runqueue_node(g2d, g2d->runqueue_node);
g2d->runqueue_node = g2d_get_runqueue_node(g2d);
}
pm_runtime_disable(&pdev->dev);
g2d_fini_cmdlist(g2d);
destroy_workqueue(g2d->g2d_workq);
kmem_cache_destroy(g2d->runqueue_slab);
return 0;
}
static int g2d_suspend(struct device *dev)
{
struct g2d_data *g2d = dev_get_drvdata(dev);
mutex_lock(&g2d->runqueue_mutex);
g2d->suspended = true;
mutex_unlock(&g2d->runqueue_mutex);
while (g2d->runqueue_node)
usleep_range(500, 1000);
flush_work(&g2d->runqueue_work);
return 0;
}
static int g2d_resume(struct device *dev)
{
struct g2d_data *g2d = dev_get_drvdata(dev);
g2d->suspended = false;
g2d_exec_runqueue(g2d);
return 0;
}
