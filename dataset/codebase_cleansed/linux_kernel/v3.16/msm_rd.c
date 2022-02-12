static void rd_write(struct msm_rd_state *rd, const void *buf, int sz)
{
struct circ_buf *fifo = &rd->fifo;
const char *ptr = buf;
while (sz > 0) {
char *fptr = &fifo->buf[fifo->head];
int n;
wait_event(rd->fifo_event, circ_space(&rd->fifo) > 0);
n = min(sz, circ_space_to_end(&rd->fifo));
memcpy(fptr, ptr, n);
fifo->head = (fifo->head + n) & (BUF_SZ - 1);
sz -= n;
ptr += n;
wake_up_all(&rd->fifo_event);
}
}
static void rd_write_section(struct msm_rd_state *rd,
enum rd_sect_type type, const void *buf, int sz)
{
rd_write(rd, &type, 4);
rd_write(rd, &sz, 4);
rd_write(rd, buf, sz);
}
static ssize_t rd_read(struct file *file, char __user *buf,
size_t sz, loff_t *ppos)
{
struct msm_rd_state *rd = file->private_data;
struct circ_buf *fifo = &rd->fifo;
const char *fptr = &fifo->buf[fifo->tail];
int n = 0, ret = 0;
mutex_lock(&rd->read_lock);
ret = wait_event_interruptible(rd->fifo_event,
circ_count(&rd->fifo) > 0);
if (ret)
goto out;
n = min_t(int, sz, circ_count_to_end(&rd->fifo));
ret = copy_to_user(buf, fptr, n);
if (ret)
goto out;
fifo->tail = (fifo->tail + n) & (BUF_SZ - 1);
*ppos += n;
wake_up_all(&rd->fifo_event);
out:
mutex_unlock(&rd->read_lock);
if (ret)
return ret;
return n;
}
static int rd_open(struct inode *inode, struct file *file)
{
struct msm_rd_state *rd = inode->i_private;
struct drm_device *dev = rd->dev;
struct msm_drm_private *priv = dev->dev_private;
struct msm_gpu *gpu = priv->gpu;
uint64_t val;
uint32_t gpu_id;
int ret = 0;
mutex_lock(&dev->struct_mutex);
if (rd->open || !gpu) {
ret = -EBUSY;
goto out;
}
file->private_data = rd;
rd->open = true;
gpu->funcs->get_param(gpu, MSM_PARAM_GPU_ID, &val);
gpu_id = val;
rd_write_section(rd, RD_GPU_ID, &gpu_id, sizeof(gpu_id));
out:
mutex_unlock(&dev->struct_mutex);
return ret;
}
static int rd_release(struct inode *inode, struct file *file)
{
struct msm_rd_state *rd = inode->i_private;
rd->open = false;
return 0;
}
int msm_rd_debugfs_init(struct drm_minor *minor)
{
struct msm_drm_private *priv = minor->dev->dev_private;
struct msm_rd_state *rd;
if (priv->rd)
return 0;
rd = kzalloc(sizeof(*rd), GFP_KERNEL);
if (!rd)
return -ENOMEM;
rd->dev = minor->dev;
rd->fifo.buf = rd->buf;
mutex_init(&rd->read_lock);
priv->rd = rd;
init_waitqueue_head(&rd->fifo_event);
rd->node = kzalloc(sizeof(*rd->node), GFP_KERNEL);
if (!rd->node)
goto fail;
rd->ent = debugfs_create_file("rd", S_IFREG | S_IRUGO,
minor->debugfs_root, rd, &rd_debugfs_fops);
if (!rd->ent) {
DRM_ERROR("Cannot create /sys/kernel/debug/dri/%s/rd\n",
minor->debugfs_root->d_name.name);
goto fail;
}
rd->node->minor = minor;
rd->node->dent = rd->ent;
rd->node->info_ent = NULL;
mutex_lock(&minor->debugfs_lock);
list_add(&rd->node->list, &minor->debugfs_list);
mutex_unlock(&minor->debugfs_lock);
return 0;
fail:
msm_rd_debugfs_cleanup(minor);
return -1;
}
void msm_rd_debugfs_cleanup(struct drm_minor *minor)
{
struct msm_drm_private *priv = minor->dev->dev_private;
struct msm_rd_state *rd = priv->rd;
if (!rd)
return;
priv->rd = NULL;
debugfs_remove(rd->ent);
if (rd->node) {
mutex_lock(&minor->debugfs_lock);
list_del(&rd->node->list);
mutex_unlock(&minor->debugfs_lock);
kfree(rd->node);
}
mutex_destroy(&rd->read_lock);
kfree(rd);
}
void msm_rd_dump_submit(struct msm_gem_submit *submit)
{
struct drm_device *dev = submit->dev;
struct msm_drm_private *priv = dev->dev_private;
struct msm_rd_state *rd = priv->rd;
char msg[128];
int i, n;
if (!rd->open)
return;
WARN_ON(!mutex_is_locked(&dev->struct_mutex));
n = snprintf(msg, sizeof(msg), "%.*s/%d: fence=%u",
TASK_COMM_LEN, current->comm, task_pid_nr(current),
submit->fence);
rd_write_section(rd, RD_CMD, msg, ALIGN(n, 4));
for (i = 0; i < submit->nr_cmds; i++) {
uint32_t idx = submit->cmd[i].idx;
uint32_t iova = submit->cmd[i].iova;
uint32_t szd = submit->cmd[i].size;
struct msm_gem_object *obj = submit->bos[idx].obj;
const char *buf = msm_gem_vaddr_locked(&obj->base);
buf += iova - submit->bos[idx].iova;
rd_write_section(rd, RD_GPUADDR,
(uint32_t[2]){ iova, szd * 4 }, 8);
rd_write_section(rd, RD_BUFFER_CONTENTS,
buf, szd * 4);
switch (submit->cmd[i].type) {
case MSM_SUBMIT_CMD_IB_TARGET_BUF:
break;
case MSM_SUBMIT_CMD_CTX_RESTORE_BUF:
case MSM_SUBMIT_CMD_BUF:
rd_write_section(rd, RD_CMDSTREAM_ADDR,
(uint32_t[2]){ iova, szd }, 8);
break;
}
}
}
