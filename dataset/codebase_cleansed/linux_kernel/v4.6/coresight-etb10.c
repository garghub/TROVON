static unsigned int etb_get_buffer_depth(struct etb_drvdata *drvdata)
{
u32 depth = 0;
pm_runtime_get_sync(drvdata->dev);
depth = readl_relaxed(drvdata->base + ETB_RAM_DEPTH_REG);
pm_runtime_put(drvdata->dev);
return depth;
}
static void etb_enable_hw(struct etb_drvdata *drvdata)
{
int i;
u32 depth;
CS_UNLOCK(drvdata->base);
depth = drvdata->buffer_depth;
writel_relaxed(0x0, drvdata->base + ETB_RAM_WRITE_POINTER);
for (i = 0; i < depth; i++)
writel_relaxed(0x0, drvdata->base + ETB_RWD_REG);
writel_relaxed(0x0, drvdata->base + ETB_RAM_WRITE_POINTER);
writel_relaxed(0x0, drvdata->base + ETB_RAM_READ_POINTER);
writel_relaxed(drvdata->trigger_cntr, drvdata->base + ETB_TRG);
writel_relaxed(ETB_FFCR_EN_FTC | ETB_FFCR_STOP_TRIGGER,
drvdata->base + ETB_FFCR);
writel_relaxed(ETB_CTL_CAPT_EN, drvdata->base + ETB_CTL_REG);
CS_LOCK(drvdata->base);
}
static int etb_enable(struct coresight_device *csdev, u32 mode)
{
u32 val;
unsigned long flags;
struct etb_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
val = local_cmpxchg(&drvdata->mode,
CS_MODE_DISABLED, mode);
if (val == CS_MODE_PERF)
return -EBUSY;
if (val == CS_MODE_SYSFS)
goto out;
spin_lock_irqsave(&drvdata->spinlock, flags);
etb_enable_hw(drvdata);
spin_unlock_irqrestore(&drvdata->spinlock, flags);
out:
dev_info(drvdata->dev, "ETB enabled\n");
return 0;
}
static void etb_disable_hw(struct etb_drvdata *drvdata)
{
u32 ffcr;
CS_UNLOCK(drvdata->base);
ffcr = readl_relaxed(drvdata->base + ETB_FFCR);
ffcr |= ETB_FFCR_STOP_FI;
writel_relaxed(ffcr, drvdata->base + ETB_FFCR);
ffcr |= ETB_FFCR_FON_MAN;
writel_relaxed(ffcr, drvdata->base + ETB_FFCR);
if (coresight_timeout(drvdata->base, ETB_FFCR, ETB_FFCR_BIT, 0)) {
dev_err(drvdata->dev,
"timeout observed when probing at offset %#x\n",
ETB_FFCR);
}
writel_relaxed(0x0, drvdata->base + ETB_CTL_REG);
if (coresight_timeout(drvdata->base, ETB_FFSR, ETB_FFSR_BIT, 1)) {
dev_err(drvdata->dev,
"timeout observed when probing at offset %#x\n",
ETB_FFCR);
}
CS_LOCK(drvdata->base);
}
static void etb_dump_hw(struct etb_drvdata *drvdata)
{
int i;
u8 *buf_ptr;
u32 read_data, depth;
u32 read_ptr, write_ptr;
u32 frame_off, frame_endoff;
CS_UNLOCK(drvdata->base);
read_ptr = readl_relaxed(drvdata->base + ETB_RAM_READ_POINTER);
write_ptr = readl_relaxed(drvdata->base + ETB_RAM_WRITE_POINTER);
frame_off = write_ptr % ETB_FRAME_SIZE_WORDS;
frame_endoff = ETB_FRAME_SIZE_WORDS - frame_off;
if (frame_off) {
dev_err(drvdata->dev,
"write_ptr: %lu not aligned to formatter frame size\n",
(unsigned long)write_ptr);
dev_err(drvdata->dev, "frameoff: %lu, frame_endoff: %lu\n",
(unsigned long)frame_off, (unsigned long)frame_endoff);
write_ptr += frame_endoff;
}
if ((readl_relaxed(drvdata->base + ETB_STATUS_REG)
& ETB_STATUS_RAM_FULL) == 0)
writel_relaxed(0x0, drvdata->base + ETB_RAM_READ_POINTER);
else
writel_relaxed(write_ptr, drvdata->base + ETB_RAM_READ_POINTER);
depth = drvdata->buffer_depth;
buf_ptr = drvdata->buf;
for (i = 0; i < depth; i++) {
read_data = readl_relaxed(drvdata->base +
ETB_RAM_READ_DATA_REG);
*buf_ptr++ = read_data >> 0;
*buf_ptr++ = read_data >> 8;
*buf_ptr++ = read_data >> 16;
*buf_ptr++ = read_data >> 24;
}
if (frame_off) {
buf_ptr -= (frame_endoff * 4);
for (i = 0; i < frame_endoff; i++) {
*buf_ptr++ = 0x0;
*buf_ptr++ = 0x0;
*buf_ptr++ = 0x0;
*buf_ptr++ = 0x0;
}
}
writel_relaxed(read_ptr, drvdata->base + ETB_RAM_READ_POINTER);
CS_LOCK(drvdata->base);
}
static void etb_disable(struct coresight_device *csdev)
{
struct etb_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
unsigned long flags;
spin_lock_irqsave(&drvdata->spinlock, flags);
etb_disable_hw(drvdata);
etb_dump_hw(drvdata);
spin_unlock_irqrestore(&drvdata->spinlock, flags);
local_set(&drvdata->mode, CS_MODE_DISABLED);
dev_info(drvdata->dev, "ETB disabled\n");
}
static void *etb_alloc_buffer(struct coresight_device *csdev, int cpu,
void **pages, int nr_pages, bool overwrite)
{
int node;
struct cs_buffers *buf;
if (cpu == -1)
cpu = smp_processor_id();
node = cpu_to_node(cpu);
buf = kzalloc_node(sizeof(struct cs_buffers), GFP_KERNEL, node);
if (!buf)
return NULL;
buf->snapshot = overwrite;
buf->nr_pages = nr_pages;
buf->data_pages = pages;
return buf;
}
static void etb_free_buffer(void *config)
{
struct cs_buffers *buf = config;
kfree(buf);
}
static int etb_set_buffer(struct coresight_device *csdev,
struct perf_output_handle *handle,
void *sink_config)
{
int ret = 0;
unsigned long head;
struct cs_buffers *buf = sink_config;
head = handle->head & ((buf->nr_pages << PAGE_SHIFT) - 1);
buf->cur = head / PAGE_SIZE;
buf->offset = head % PAGE_SIZE;
local_set(&buf->data_size, 0);
return ret;
}
static unsigned long etb_reset_buffer(struct coresight_device *csdev,
struct perf_output_handle *handle,
void *sink_config, bool *lost)
{
unsigned long size = 0;
struct cs_buffers *buf = sink_config;
if (buf) {
if (buf->snapshot)
handle->head = local_xchg(&buf->data_size,
buf->nr_pages << PAGE_SHIFT);
*lost = !!local_xchg(&buf->lost, 0);
size = local_xchg(&buf->data_size, 0);
}
return size;
}
static void etb_update_buffer(struct coresight_device *csdev,
struct perf_output_handle *handle,
void *sink_config)
{
int i, cur;
u8 *buf_ptr;
u32 read_ptr, write_ptr, capacity;
u32 status, read_data, to_read;
unsigned long offset;
struct cs_buffers *buf = sink_config;
struct etb_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
if (!buf)
return;
capacity = drvdata->buffer_depth * ETB_FRAME_SIZE_WORDS;
CS_UNLOCK(drvdata->base);
etb_disable_hw(drvdata);
read_ptr = readl_relaxed(drvdata->base + ETB_RAM_READ_POINTER);
write_ptr = readl_relaxed(drvdata->base + ETB_RAM_WRITE_POINTER);
if (write_ptr % ETB_FRAME_SIZE_WORDS) {
dev_err(drvdata->dev,
"write_ptr: %lu not aligned to formatter frame size\n",
(unsigned long)write_ptr);
write_ptr &= ~(ETB_FRAME_SIZE_WORDS - 1);
local_inc(&buf->lost);
}
status = readl_relaxed(drvdata->base + ETB_STATUS_REG);
if (status & ETB_STATUS_RAM_FULL) {
local_inc(&buf->lost);
to_read = capacity;
read_ptr = write_ptr;
} else {
to_read = CIRC_CNT(write_ptr, read_ptr, drvdata->buffer_depth);
to_read *= ETB_FRAME_SIZE_WORDS;
}
if (!buf->snapshot && to_read > handle->size) {
u32 mask = ~(ETB_FRAME_SIZE_WORDS - 1);
to_read -= handle->size & mask;
read_ptr = (write_ptr + drvdata->buffer_depth) -
to_read / ETB_FRAME_SIZE_WORDS;
read_ptr &= ~(drvdata->buffer_depth - 1);
local_inc(&buf->lost);
}
writel_relaxed(read_ptr, drvdata->base + ETB_RAM_READ_POINTER);
cur = buf->cur;
offset = buf->offset;
for (i = 0; i < to_read; i += 4) {
buf_ptr = buf->data_pages[cur] + offset;
read_data = readl_relaxed(drvdata->base +
ETB_RAM_READ_DATA_REG);
*buf_ptr++ = read_data >> 0;
*buf_ptr++ = read_data >> 8;
*buf_ptr++ = read_data >> 16;
*buf_ptr++ = read_data >> 24;
offset += 4;
if (offset >= PAGE_SIZE) {
offset = 0;
cur++;
cur &= buf->nr_pages - 1;
}
}
writel_relaxed(0x0, drvdata->base + ETB_RAM_READ_POINTER);
writel_relaxed(0x0, drvdata->base + ETB_RAM_WRITE_POINTER);
if (buf->snapshot)
local_set(&buf->data_size, (cur * PAGE_SIZE) + offset);
else
local_add(to_read, &buf->data_size);
etb_enable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static void etb_dump(struct etb_drvdata *drvdata)
{
unsigned long flags;
spin_lock_irqsave(&drvdata->spinlock, flags);
if (local_read(&drvdata->mode) == CS_MODE_SYSFS) {
etb_disable_hw(drvdata);
etb_dump_hw(drvdata);
etb_enable_hw(drvdata);
}
spin_unlock_irqrestore(&drvdata->spinlock, flags);
dev_info(drvdata->dev, "ETB dumped\n");
}
static int etb_open(struct inode *inode, struct file *file)
{
struct etb_drvdata *drvdata = container_of(file->private_data,
struct etb_drvdata, miscdev);
if (local_cmpxchg(&drvdata->reading, 0, 1))
return -EBUSY;
dev_dbg(drvdata->dev, "%s: successfully opened\n", __func__);
return 0;
}
static ssize_t etb_read(struct file *file, char __user *data,
size_t len, loff_t *ppos)
{
u32 depth;
struct etb_drvdata *drvdata = container_of(file->private_data,
struct etb_drvdata, miscdev);
etb_dump(drvdata);
depth = drvdata->buffer_depth;
if (*ppos + len > depth * 4)
len = depth * 4 - *ppos;
if (copy_to_user(data, drvdata->buf + *ppos, len)) {
dev_dbg(drvdata->dev, "%s: copy_to_user failed\n", __func__);
return -EFAULT;
}
*ppos += len;
dev_dbg(drvdata->dev, "%s: %zu bytes copied, %d bytes left\n",
__func__, len, (int)(depth * 4 - *ppos));
return len;
}
static int etb_release(struct inode *inode, struct file *file)
{
struct etb_drvdata *drvdata = container_of(file->private_data,
struct etb_drvdata, miscdev);
local_set(&drvdata->reading, 0);
dev_dbg(drvdata->dev, "%s: released\n", __func__);
return 0;
}
static ssize_t status_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
unsigned long flags;
u32 etb_rdr, etb_sr, etb_rrp, etb_rwp;
u32 etb_trg, etb_cr, etb_ffsr, etb_ffcr;
struct etb_drvdata *drvdata = dev_get_drvdata(dev->parent);
pm_runtime_get_sync(drvdata->dev);
spin_lock_irqsave(&drvdata->spinlock, flags);
CS_UNLOCK(drvdata->base);
etb_rdr = readl_relaxed(drvdata->base + ETB_RAM_DEPTH_REG);
etb_sr = readl_relaxed(drvdata->base + ETB_STATUS_REG);
etb_rrp = readl_relaxed(drvdata->base + ETB_RAM_READ_POINTER);
etb_rwp = readl_relaxed(drvdata->base + ETB_RAM_WRITE_POINTER);
etb_trg = readl_relaxed(drvdata->base + ETB_TRG);
etb_cr = readl_relaxed(drvdata->base + ETB_CTL_REG);
etb_ffsr = readl_relaxed(drvdata->base + ETB_FFSR);
etb_ffcr = readl_relaxed(drvdata->base + ETB_FFCR);
CS_LOCK(drvdata->base);
spin_unlock_irqrestore(&drvdata->spinlock, flags);
pm_runtime_put(drvdata->dev);
return sprintf(buf,
"Depth:\t\t0x%x\n"
"Status:\t\t0x%x\n"
"RAM read ptr:\t0x%x\n"
"RAM wrt ptr:\t0x%x\n"
"Trigger cnt:\t0x%x\n"
"Control:\t0x%x\n"
"Flush status:\t0x%x\n"
"Flush ctrl:\t0x%x\n",
etb_rdr, etb_sr, etb_rrp, etb_rwp,
etb_trg, etb_cr, etb_ffsr, etb_ffcr);
return -EINVAL;
}
static ssize_t trigger_cntr_show(struct device *dev,
struct device_attribute *attr, char *buf)
{
struct etb_drvdata *drvdata = dev_get_drvdata(dev->parent);
unsigned long val = drvdata->trigger_cntr;
return sprintf(buf, "%#lx\n", val);
}
static ssize_t trigger_cntr_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t size)
{
int ret;
unsigned long val;
struct etb_drvdata *drvdata = dev_get_drvdata(dev->parent);
ret = kstrtoul(buf, 16, &val);
if (ret)
return ret;
drvdata->trigger_cntr = val;
return size;
}
static int etb_probe(struct amba_device *adev, const struct amba_id *id)
{
int ret;
void __iomem *base;
struct device *dev = &adev->dev;
struct coresight_platform_data *pdata = NULL;
struct etb_drvdata *drvdata;
struct resource *res = &adev->res;
struct coresight_desc *desc;
struct device_node *np = adev->dev.of_node;
if (np) {
pdata = of_get_coresight_platform_data(dev, np);
if (IS_ERR(pdata))
return PTR_ERR(pdata);
adev->dev.platform_data = pdata;
}
drvdata = devm_kzalloc(dev, sizeof(*drvdata), GFP_KERNEL);
if (!drvdata)
return -ENOMEM;
drvdata->dev = &adev->dev;
drvdata->atclk = devm_clk_get(&adev->dev, "atclk");
if (!IS_ERR(drvdata->atclk)) {
ret = clk_prepare_enable(drvdata->atclk);
if (ret)
return ret;
}
dev_set_drvdata(dev, drvdata);
base = devm_ioremap_resource(dev, res);
if (IS_ERR(base))
return PTR_ERR(base);
drvdata->base = base;
spin_lock_init(&drvdata->spinlock);
drvdata->buffer_depth = etb_get_buffer_depth(drvdata);
pm_runtime_put(&adev->dev);
if (drvdata->buffer_depth & 0x80000000)
return -EINVAL;
drvdata->buf = devm_kzalloc(dev,
drvdata->buffer_depth * 4, GFP_KERNEL);
if (!drvdata->buf) {
dev_err(dev, "Failed to allocate %u bytes for buffer data\n",
drvdata->buffer_depth * 4);
return -ENOMEM;
}
desc = devm_kzalloc(dev, sizeof(*desc), GFP_KERNEL);
if (!desc)
return -ENOMEM;
desc->type = CORESIGHT_DEV_TYPE_SINK;
desc->subtype.sink_subtype = CORESIGHT_DEV_SUBTYPE_SINK_BUFFER;
desc->ops = &etb_cs_ops;
desc->pdata = pdata;
desc->dev = dev;
desc->groups = coresight_etb_groups;
drvdata->csdev = coresight_register(desc);
if (IS_ERR(drvdata->csdev))
return PTR_ERR(drvdata->csdev);
drvdata->miscdev.name = pdata->name;
drvdata->miscdev.minor = MISC_DYNAMIC_MINOR;
drvdata->miscdev.fops = &etb_fops;
ret = misc_register(&drvdata->miscdev);
if (ret)
goto err_misc_register;
dev_info(dev, "ETB initialized\n");
return 0;
err_misc_register:
coresight_unregister(drvdata->csdev);
return ret;
}
static int etb_runtime_suspend(struct device *dev)
{
struct etb_drvdata *drvdata = dev_get_drvdata(dev);
if (drvdata && !IS_ERR(drvdata->atclk))
clk_disable_unprepare(drvdata->atclk);
return 0;
}
static int etb_runtime_resume(struct device *dev)
{
struct etb_drvdata *drvdata = dev_get_drvdata(dev);
if (drvdata && !IS_ERR(drvdata->atclk))
clk_prepare_enable(drvdata->atclk);
return 0;
}
