static void tmc_etb_enable_hw(struct tmc_drvdata *drvdata)
{
CS_UNLOCK(drvdata->base);
tmc_wait_for_tmcready(drvdata);
writel_relaxed(TMC_MODE_CIRCULAR_BUFFER, drvdata->base + TMC_MODE);
writel_relaxed(TMC_FFCR_EN_FMT | TMC_FFCR_EN_TI |
TMC_FFCR_FON_FLIN | TMC_FFCR_FON_TRIG_EVT |
TMC_FFCR_TRIGON_TRIGIN,
drvdata->base + TMC_FFCR);
writel_relaxed(drvdata->trigger_cntr, drvdata->base + TMC_TRG);
tmc_enable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static void tmc_etb_dump_hw(struct tmc_drvdata *drvdata)
{
char *bufp;
u32 read_data;
int i;
bufp = drvdata->buf;
drvdata->len = 0;
while (1) {
for (i = 0; i < drvdata->memwidth; i++) {
read_data = readl_relaxed(drvdata->base + TMC_RRD);
if (read_data == 0xFFFFFFFF)
return;
memcpy(bufp, &read_data, 4);
bufp += 4;
drvdata->len += 4;
}
}
}
static void tmc_etb_disable_hw(struct tmc_drvdata *drvdata)
{
CS_UNLOCK(drvdata->base);
tmc_flush_and_stop(drvdata);
if (drvdata->mode == CS_MODE_SYSFS)
tmc_etb_dump_hw(drvdata);
tmc_disable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static void tmc_etf_enable_hw(struct tmc_drvdata *drvdata)
{
CS_UNLOCK(drvdata->base);
tmc_wait_for_tmcready(drvdata);
writel_relaxed(TMC_MODE_HARDWARE_FIFO, drvdata->base + TMC_MODE);
writel_relaxed(TMC_FFCR_EN_FMT | TMC_FFCR_EN_TI,
drvdata->base + TMC_FFCR);
writel_relaxed(0x0, drvdata->base + TMC_BUFWM);
tmc_enable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static void tmc_etf_disable_hw(struct tmc_drvdata *drvdata)
{
CS_UNLOCK(drvdata->base);
tmc_flush_and_stop(drvdata);
tmc_disable_hw(drvdata);
CS_LOCK(drvdata->base);
}
static int tmc_enable_etf_sink_sysfs(struct coresight_device *csdev)
{
int ret = 0;
bool used = false;
char *buf = NULL;
unsigned long flags;
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
spin_lock_irqsave(&drvdata->spinlock, flags);
if (!drvdata->buf) {
spin_unlock_irqrestore(&drvdata->spinlock, flags);
buf = kzalloc(drvdata->size, GFP_KERNEL);
if (!buf)
return -ENOMEM;
spin_lock_irqsave(&drvdata->spinlock, flags);
}
if (drvdata->reading) {
ret = -EBUSY;
goto out;
}
if (drvdata->mode == CS_MODE_SYSFS)
goto out;
if (drvdata->buf) {
memset(drvdata->buf, 0, drvdata->size);
} else {
used = true;
drvdata->buf = buf;
}
drvdata->mode = CS_MODE_SYSFS;
tmc_etb_enable_hw(drvdata);
out:
spin_unlock_irqrestore(&drvdata->spinlock, flags);
if (!used)
kfree(buf);
if (!ret)
dev_info(drvdata->dev, "TMC-ETB/ETF enabled\n");
return ret;
}
static int tmc_enable_etf_sink_perf(struct coresight_device *csdev)
{
int ret = 0;
unsigned long flags;
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->reading) {
ret = -EINVAL;
goto out;
}
if (drvdata->mode != CS_MODE_DISABLED) {
ret = -EINVAL;
goto out;
}
drvdata->mode = CS_MODE_PERF;
tmc_etb_enable_hw(drvdata);
out:
spin_unlock_irqrestore(&drvdata->spinlock, flags);
return ret;
}
static int tmc_enable_etf_sink(struct coresight_device *csdev, u32 mode)
{
switch (mode) {
case CS_MODE_SYSFS:
return tmc_enable_etf_sink_sysfs(csdev);
case CS_MODE_PERF:
return tmc_enable_etf_sink_perf(csdev);
}
return -EINVAL;
}
static void tmc_disable_etf_sink(struct coresight_device *csdev)
{
unsigned long flags;
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->reading) {
spin_unlock_irqrestore(&drvdata->spinlock, flags);
return;
}
if (drvdata->mode != CS_MODE_DISABLED) {
tmc_etb_disable_hw(drvdata);
drvdata->mode = CS_MODE_DISABLED;
}
spin_unlock_irqrestore(&drvdata->spinlock, flags);
dev_info(drvdata->dev, "TMC-ETB/ETF disabled\n");
}
static int tmc_enable_etf_link(struct coresight_device *csdev,
int inport, int outport)
{
unsigned long flags;
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->reading) {
spin_unlock_irqrestore(&drvdata->spinlock, flags);
return -EBUSY;
}
tmc_etf_enable_hw(drvdata);
drvdata->mode = CS_MODE_SYSFS;
spin_unlock_irqrestore(&drvdata->spinlock, flags);
dev_info(drvdata->dev, "TMC-ETF enabled\n");
return 0;
}
static void tmc_disable_etf_link(struct coresight_device *csdev,
int inport, int outport)
{
unsigned long flags;
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->reading) {
spin_unlock_irqrestore(&drvdata->spinlock, flags);
return;
}
tmc_etf_disable_hw(drvdata);
drvdata->mode = CS_MODE_DISABLED;
spin_unlock_irqrestore(&drvdata->spinlock, flags);
dev_info(drvdata->dev, "TMC disabled\n");
}
static void *tmc_alloc_etf_buffer(struct coresight_device *csdev, int cpu,
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
static void tmc_free_etf_buffer(void *config)
{
struct cs_buffers *buf = config;
kfree(buf);
}
static int tmc_set_etf_buffer(struct coresight_device *csdev,
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
static unsigned long tmc_reset_etf_buffer(struct coresight_device *csdev,
struct perf_output_handle *handle,
void *sink_config)
{
long size = 0;
struct cs_buffers *buf = sink_config;
if (buf) {
if (buf->snapshot)
handle->head = local_xchg(&buf->data_size,
buf->nr_pages << PAGE_SHIFT);
size = local_xchg(&buf->data_size, 0);
}
return size;
}
static void tmc_update_etf_buffer(struct coresight_device *csdev,
struct perf_output_handle *handle,
void *sink_config)
{
int i, cur;
u32 *buf_ptr;
u32 read_ptr, write_ptr;
u32 status, to_read;
unsigned long offset;
struct cs_buffers *buf = sink_config;
struct tmc_drvdata *drvdata = dev_get_drvdata(csdev->dev.parent);
if (!buf)
return;
if (WARN_ON_ONCE(drvdata->mode != CS_MODE_PERF))
return;
CS_UNLOCK(drvdata->base);
tmc_flush_and_stop(drvdata);
read_ptr = readl_relaxed(drvdata->base + TMC_RRP);
write_ptr = readl_relaxed(drvdata->base + TMC_RWP);
status = readl_relaxed(drvdata->base + TMC_STS);
if (status & TMC_STS_FULL) {
perf_aux_output_flag(handle, PERF_AUX_FLAG_TRUNCATED);
to_read = drvdata->size;
} else {
to_read = CIRC_CNT(write_ptr, read_ptr, drvdata->size);
}
if (to_read > handle->size) {
u32 mask = 0;
switch (drvdata->memwidth) {
case TMC_MEM_INTF_WIDTH_32BITS:
case TMC_MEM_INTF_WIDTH_64BITS:
case TMC_MEM_INTF_WIDTH_128BITS:
mask = GENMASK(31, 5);
break;
case TMC_MEM_INTF_WIDTH_256BITS:
mask = GENMASK(31, 6);
break;
}
to_read = handle->size & mask;
read_ptr = (write_ptr + drvdata->size) - to_read;
if (read_ptr > (drvdata->size - 1))
read_ptr -= drvdata->size;
writel_relaxed(read_ptr, drvdata->base + TMC_RRP);
perf_aux_output_flag(handle, PERF_AUX_FLAG_TRUNCATED);
}
cur = buf->cur;
offset = buf->offset;
for (i = 0; i < to_read; i += 4) {
buf_ptr = buf->data_pages[cur] + offset;
*buf_ptr = readl_relaxed(drvdata->base + TMC_RRD);
offset += 4;
if (offset >= PAGE_SIZE) {
offset = 0;
cur++;
cur &= buf->nr_pages - 1;
}
}
if (buf->snapshot)
local_set(&buf->data_size, (cur * PAGE_SIZE) + offset);
else
local_add(to_read, &buf->data_size);
CS_LOCK(drvdata->base);
}
int tmc_read_prepare_etb(struct tmc_drvdata *drvdata)
{
enum tmc_mode mode;
int ret = 0;
unsigned long flags;
if (WARN_ON_ONCE(drvdata->config_type != TMC_CONFIG_TYPE_ETB &&
drvdata->config_type != TMC_CONFIG_TYPE_ETF))
return -EINVAL;
spin_lock_irqsave(&drvdata->spinlock, flags);
if (drvdata->reading) {
ret = -EBUSY;
goto out;
}
mode = readl_relaxed(drvdata->base + TMC_MODE);
if (mode != TMC_MODE_CIRCULAR_BUFFER) {
ret = -EINVAL;
goto out;
}
if (drvdata->mode == CS_MODE_PERF) {
ret = -EINVAL;
goto out;
}
if (drvdata->buf == NULL) {
ret = -EINVAL;
goto out;
}
if (drvdata->mode == CS_MODE_SYSFS)
tmc_etb_disable_hw(drvdata);
drvdata->reading = true;
out:
spin_unlock_irqrestore(&drvdata->spinlock, flags);
return ret;
}
int tmc_read_unprepare_etb(struct tmc_drvdata *drvdata)
{
char *buf = NULL;
enum tmc_mode mode;
unsigned long flags;
if (WARN_ON_ONCE(drvdata->config_type != TMC_CONFIG_TYPE_ETB &&
drvdata->config_type != TMC_CONFIG_TYPE_ETF))
return -EINVAL;
spin_lock_irqsave(&drvdata->spinlock, flags);
mode = readl_relaxed(drvdata->base + TMC_MODE);
if (mode != TMC_MODE_CIRCULAR_BUFFER) {
spin_unlock_irqrestore(&drvdata->spinlock, flags);
return -EINVAL;
}
if (drvdata->mode == CS_MODE_SYSFS) {
memset(drvdata->buf, 0, drvdata->size);
tmc_etb_enable_hw(drvdata);
} else {
buf = drvdata->buf;
drvdata->buf = NULL;
}
drvdata->reading = false;
spin_unlock_irqrestore(&drvdata->spinlock, flags);
kfree(buf);
return 0;
}
