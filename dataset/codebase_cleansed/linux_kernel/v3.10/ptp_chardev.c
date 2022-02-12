int ptp_open(struct posix_clock *pc, fmode_t fmode)
{
return 0;
}
long ptp_ioctl(struct posix_clock *pc, unsigned int cmd, unsigned long arg)
{
struct ptp_clock_caps caps;
struct ptp_clock_request req;
struct ptp_sys_offset *sysoff = NULL;
struct ptp_clock *ptp = container_of(pc, struct ptp_clock, clock);
struct ptp_clock_info *ops = ptp->info;
struct ptp_clock_time *pct;
struct timespec ts;
int enable, err = 0;
unsigned int i;
switch (cmd) {
case PTP_CLOCK_GETCAPS:
memset(&caps, 0, sizeof(caps));
caps.max_adj = ptp->info->max_adj;
caps.n_alarm = ptp->info->n_alarm;
caps.n_ext_ts = ptp->info->n_ext_ts;
caps.n_per_out = ptp->info->n_per_out;
caps.pps = ptp->info->pps;
if (copy_to_user((void __user *)arg, &caps, sizeof(caps)))
err = -EFAULT;
break;
case PTP_EXTTS_REQUEST:
if (copy_from_user(&req.extts, (void __user *)arg,
sizeof(req.extts))) {
err = -EFAULT;
break;
}
if (req.extts.index >= ops->n_ext_ts) {
err = -EINVAL;
break;
}
req.type = PTP_CLK_REQ_EXTTS;
enable = req.extts.flags & PTP_ENABLE_FEATURE ? 1 : 0;
err = ops->enable(ops, &req, enable);
break;
case PTP_PEROUT_REQUEST:
if (copy_from_user(&req.perout, (void __user *)arg,
sizeof(req.perout))) {
err = -EFAULT;
break;
}
if (req.perout.index >= ops->n_per_out) {
err = -EINVAL;
break;
}
req.type = PTP_CLK_REQ_PEROUT;
enable = req.perout.period.sec || req.perout.period.nsec;
err = ops->enable(ops, &req, enable);
break;
case PTP_ENABLE_PPS:
if (!capable(CAP_SYS_TIME))
return -EPERM;
req.type = PTP_CLK_REQ_PPS;
enable = arg ? 1 : 0;
err = ops->enable(ops, &req, enable);
break;
case PTP_SYS_OFFSET:
sysoff = kmalloc(sizeof(*sysoff), GFP_KERNEL);
if (!sysoff) {
err = -ENOMEM;
break;
}
if (copy_from_user(sysoff, (void __user *)arg,
sizeof(*sysoff))) {
err = -EFAULT;
break;
}
if (sysoff->n_samples > PTP_MAX_SAMPLES) {
err = -EINVAL;
break;
}
pct = &sysoff->ts[0];
for (i = 0; i < sysoff->n_samples; i++) {
getnstimeofday(&ts);
pct->sec = ts.tv_sec;
pct->nsec = ts.tv_nsec;
pct++;
ptp->info->gettime(ptp->info, &ts);
pct->sec = ts.tv_sec;
pct->nsec = ts.tv_nsec;
pct++;
}
getnstimeofday(&ts);
pct->sec = ts.tv_sec;
pct->nsec = ts.tv_nsec;
if (copy_to_user((void __user *)arg, sysoff, sizeof(*sysoff)))
err = -EFAULT;
break;
default:
err = -ENOTTY;
break;
}
kfree(sysoff);
return err;
}
unsigned int ptp_poll(struct posix_clock *pc, struct file *fp, poll_table *wait)
{
struct ptp_clock *ptp = container_of(pc, struct ptp_clock, clock);
poll_wait(fp, &ptp->tsev_wq, wait);
return queue_cnt(&ptp->tsevq) ? POLLIN : 0;
}
ssize_t ptp_read(struct posix_clock *pc,
uint rdflags, char __user *buf, size_t cnt)
{
struct ptp_clock *ptp = container_of(pc, struct ptp_clock, clock);
struct timestamp_event_queue *queue = &ptp->tsevq;
struct ptp_extts_event *event;
unsigned long flags;
size_t qcnt, i;
int result;
if (cnt % sizeof(struct ptp_extts_event) != 0)
return -EINVAL;
if (cnt > EXTTS_BUFSIZE)
cnt = EXTTS_BUFSIZE;
cnt = cnt / sizeof(struct ptp_extts_event);
if (mutex_lock_interruptible(&ptp->tsevq_mux))
return -ERESTARTSYS;
if (wait_event_interruptible(ptp->tsev_wq,
ptp->defunct || queue_cnt(queue))) {
mutex_unlock(&ptp->tsevq_mux);
return -ERESTARTSYS;
}
if (ptp->defunct) {
mutex_unlock(&ptp->tsevq_mux);
return -ENODEV;
}
event = kmalloc(EXTTS_BUFSIZE, GFP_KERNEL);
if (!event) {
mutex_unlock(&ptp->tsevq_mux);
return -ENOMEM;
}
spin_lock_irqsave(&queue->lock, flags);
qcnt = queue_cnt(queue);
if (cnt > qcnt)
cnt = qcnt;
for (i = 0; i < cnt; i++) {
event[i] = queue->buf[queue->head];
queue->head = (queue->head + 1) % PTP_MAX_TIMESTAMPS;
}
spin_unlock_irqrestore(&queue->lock, flags);
cnt = cnt * sizeof(struct ptp_extts_event);
mutex_unlock(&ptp->tsevq_mux);
result = cnt;
if (copy_to_user(buf, event, cnt))
result = -EFAULT;
kfree(event);
return result;
}
