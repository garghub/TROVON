static ssize_t clock_name_show(struct device *dev,
struct device_attribute *attr, char *page)
{
struct ptp_clock *ptp = dev_get_drvdata(dev);
return snprintf(page, PAGE_SIZE-1, "%s\n", ptp->info->name);
}
static ssize_t extts_enable_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ptp_clock *ptp = dev_get_drvdata(dev);
struct ptp_clock_info *ops = ptp->info;
struct ptp_clock_request req = { .type = PTP_CLK_REQ_EXTTS };
int cnt, enable;
int err = -EINVAL;
cnt = sscanf(buf, "%u %d", &req.extts.index, &enable);
if (cnt != 2)
goto out;
if (req.extts.index >= ops->n_ext_ts)
goto out;
err = ops->enable(ops, &req, enable ? 1 : 0);
if (err)
goto out;
return count;
out:
return err;
}
static ssize_t extts_fifo_show(struct device *dev,
struct device_attribute *attr, char *page)
{
struct ptp_clock *ptp = dev_get_drvdata(dev);
struct timestamp_event_queue *queue = &ptp->tsevq;
struct ptp_extts_event event;
unsigned long flags;
size_t qcnt;
int cnt = 0;
memset(&event, 0, sizeof(event));
if (mutex_lock_interruptible(&ptp->tsevq_mux))
return -ERESTARTSYS;
spin_lock_irqsave(&queue->lock, flags);
qcnt = queue_cnt(queue);
if (qcnt) {
event = queue->buf[queue->head];
queue->head = (queue->head + 1) % PTP_MAX_TIMESTAMPS;
}
spin_unlock_irqrestore(&queue->lock, flags);
if (!qcnt)
goto out;
cnt = snprintf(page, PAGE_SIZE, "%u %lld %u\n",
event.index, event.t.sec, event.t.nsec);
out:
mutex_unlock(&ptp->tsevq_mux);
return cnt;
}
static ssize_t period_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ptp_clock *ptp = dev_get_drvdata(dev);
struct ptp_clock_info *ops = ptp->info;
struct ptp_clock_request req = { .type = PTP_CLK_REQ_PEROUT };
int cnt, enable, err = -EINVAL;
cnt = sscanf(buf, "%u %lld %u %lld %u", &req.perout.index,
&req.perout.start.sec, &req.perout.start.nsec,
&req.perout.period.sec, &req.perout.period.nsec);
if (cnt != 5)
goto out;
if (req.perout.index >= ops->n_per_out)
goto out;
enable = req.perout.period.sec || req.perout.period.nsec;
err = ops->enable(ops, &req, enable);
if (err)
goto out;
return count;
out:
return err;
}
static ssize_t pps_enable_store(struct device *dev,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ptp_clock *ptp = dev_get_drvdata(dev);
struct ptp_clock_info *ops = ptp->info;
struct ptp_clock_request req = { .type = PTP_CLK_REQ_PPS };
int cnt, enable;
int err = -EINVAL;
if (!capable(CAP_SYS_TIME))
return -EPERM;
cnt = sscanf(buf, "%d", &enable);
if (cnt != 1)
goto out;
err = ops->enable(ops, &req, enable ? 1 : 0);
if (err)
goto out;
return count;
out:
return err;
}
int ptp_cleanup_sysfs(struct ptp_clock *ptp)
{
struct device *dev = ptp->dev;
struct ptp_clock_info *info = ptp->info;
if (info->n_ext_ts) {
device_remove_file(dev, &dev_attr_extts_enable);
device_remove_file(dev, &dev_attr_fifo);
}
if (info->n_per_out)
device_remove_file(dev, &dev_attr_period);
if (info->pps)
device_remove_file(dev, &dev_attr_pps_enable);
return 0;
}
int ptp_populate_sysfs(struct ptp_clock *ptp)
{
struct device *dev = ptp->dev;
struct ptp_clock_info *info = ptp->info;
int err;
if (info->n_ext_ts) {
err = device_create_file(dev, &dev_attr_extts_enable);
if (err)
goto out1;
err = device_create_file(dev, &dev_attr_fifo);
if (err)
goto out2;
}
if (info->n_per_out) {
err = device_create_file(dev, &dev_attr_period);
if (err)
goto out3;
}
if (info->pps) {
err = device_create_file(dev, &dev_attr_pps_enable);
if (err)
goto out4;
}
return 0;
out4:
if (info->n_per_out)
device_remove_file(dev, &dev_attr_period);
out3:
if (info->n_ext_ts)
device_remove_file(dev, &dev_attr_fifo);
out2:
if (info->n_ext_ts)
device_remove_file(dev, &dev_attr_extts_enable);
out1:
return err;
}
