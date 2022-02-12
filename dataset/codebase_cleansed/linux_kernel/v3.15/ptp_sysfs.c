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
static int ptp_pin_name2index(struct ptp_clock *ptp, const char *name)
{
int i;
for (i = 0; i < ptp->info->n_pins; i++) {
if (!strcmp(ptp->info->pin_config[i].name, name))
return i;
}
return -1;
}
static ssize_t ptp_pin_show(struct device *dev, struct device_attribute *attr,
char *page)
{
struct ptp_clock *ptp = dev_get_drvdata(dev);
unsigned int func, chan;
int index;
index = ptp_pin_name2index(ptp, attr->attr.name);
if (index < 0)
return -EINVAL;
if (mutex_lock_interruptible(&ptp->pincfg_mux))
return -ERESTARTSYS;
func = ptp->info->pin_config[index].func;
chan = ptp->info->pin_config[index].chan;
mutex_unlock(&ptp->pincfg_mux);
return snprintf(page, PAGE_SIZE, "%u %u\n", func, chan);
}
static ssize_t ptp_pin_store(struct device *dev, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ptp_clock *ptp = dev_get_drvdata(dev);
unsigned int func, chan;
int cnt, err, index;
cnt = sscanf(buf, "%u %u", &func, &chan);
if (cnt != 2)
return -EINVAL;
index = ptp_pin_name2index(ptp, attr->attr.name);
if (index < 0)
return -EINVAL;
if (mutex_lock_interruptible(&ptp->pincfg_mux))
return -ERESTARTSYS;
err = ptp_set_pinfunc(ptp, index, func, chan);
mutex_unlock(&ptp->pincfg_mux);
if (err)
return err;
return count;
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
if (info->n_pins) {
sysfs_remove_group(&dev->kobj, &ptp->pin_attr_group);
kfree(ptp->pin_attr);
kfree(ptp->pin_dev_attr);
}
return 0;
}
static int ptp_populate_pins(struct ptp_clock *ptp)
{
struct device *dev = ptp->dev;
struct ptp_clock_info *info = ptp->info;
int err = -ENOMEM, i, n_pins = info->n_pins;
ptp->pin_dev_attr = kzalloc(n_pins * sizeof(*ptp->pin_dev_attr),
GFP_KERNEL);
if (!ptp->pin_dev_attr)
goto no_dev_attr;
ptp->pin_attr = kzalloc((1 + n_pins) * sizeof(struct attribute *),
GFP_KERNEL);
if (!ptp->pin_attr)
goto no_pin_attr;
for (i = 0; i < n_pins; i++) {
struct device_attribute *da = &ptp->pin_dev_attr[i];
sysfs_attr_init(&da->attr);
da->attr.name = info->pin_config[i].name;
da->attr.mode = 0644;
da->show = ptp_pin_show;
da->store = ptp_pin_store;
ptp->pin_attr[i] = &da->attr;
}
ptp->pin_attr_group.name = "pins";
ptp->pin_attr_group.attrs = ptp->pin_attr;
err = sysfs_create_group(&dev->kobj, &ptp->pin_attr_group);
if (err)
goto no_group;
return 0;
no_group:
kfree(ptp->pin_attr);
no_pin_attr:
kfree(ptp->pin_dev_attr);
no_dev_attr:
return err;
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
if (info->n_pins) {
err = ptp_populate_pins(ptp);
if (err)
goto out5;
}
return 0;
out5:
if (info->pps)
device_remove_file(dev, &dev_attr_pps_enable);
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
