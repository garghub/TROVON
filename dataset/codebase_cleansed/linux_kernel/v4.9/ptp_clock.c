static inline int queue_free(struct timestamp_event_queue *q)
{
return PTP_MAX_TIMESTAMPS - queue_cnt(q) - 1;
}
static void enqueue_external_timestamp(struct timestamp_event_queue *queue,
struct ptp_clock_event *src)
{
struct ptp_extts_event *dst;
unsigned long flags;
s64 seconds;
u32 remainder;
seconds = div_u64_rem(src->timestamp, 1000000000, &remainder);
spin_lock_irqsave(&queue->lock, flags);
dst = &queue->buf[queue->tail];
dst->index = src->index;
dst->t.sec = seconds;
dst->t.nsec = remainder;
if (!queue_free(queue))
queue->head = (queue->head + 1) % PTP_MAX_TIMESTAMPS;
queue->tail = (queue->tail + 1) % PTP_MAX_TIMESTAMPS;
spin_unlock_irqrestore(&queue->lock, flags);
}
static s32 scaled_ppm_to_ppb(long ppm)
{
s64 ppb = 1 + ppm;
ppb *= 125;
ppb >>= 13;
return (s32) ppb;
}
static int ptp_clock_getres(struct posix_clock *pc, struct timespec *tp)
{
tp->tv_sec = 0;
tp->tv_nsec = 1;
return 0;
}
static int ptp_clock_settime(struct posix_clock *pc, const struct timespec *tp)
{
struct ptp_clock *ptp = container_of(pc, struct ptp_clock, clock);
struct timespec64 ts = timespec_to_timespec64(*tp);
return ptp->info->settime64(ptp->info, &ts);
}
static int ptp_clock_gettime(struct posix_clock *pc, struct timespec *tp)
{
struct ptp_clock *ptp = container_of(pc, struct ptp_clock, clock);
struct timespec64 ts;
int err;
err = ptp->info->gettime64(ptp->info, &ts);
if (!err)
*tp = timespec64_to_timespec(ts);
return err;
}
static int ptp_clock_adjtime(struct posix_clock *pc, struct timex *tx)
{
struct ptp_clock *ptp = container_of(pc, struct ptp_clock, clock);
struct ptp_clock_info *ops;
int err = -EOPNOTSUPP;
ops = ptp->info;
if (tx->modes & ADJ_SETOFFSET) {
struct timespec ts;
ktime_t kt;
s64 delta;
ts.tv_sec = tx->time.tv_sec;
ts.tv_nsec = tx->time.tv_usec;
if (!(tx->modes & ADJ_NANO))
ts.tv_nsec *= 1000;
if ((unsigned long) ts.tv_nsec >= NSEC_PER_SEC)
return -EINVAL;
kt = timespec_to_ktime(ts);
delta = ktime_to_ns(kt);
err = ops->adjtime(ops, delta);
} else if (tx->modes & ADJ_FREQUENCY) {
s32 ppb = scaled_ppm_to_ppb(tx->freq);
if (ppb > ops->max_adj || ppb < -ops->max_adj)
return -ERANGE;
err = ops->adjfreq(ops, ppb);
ptp->dialed_frequency = tx->freq;
} else if (tx->modes == 0) {
tx->freq = ptp->dialed_frequency;
err = 0;
}
return err;
}
static void delete_ptp_clock(struct posix_clock *pc)
{
struct ptp_clock *ptp = container_of(pc, struct ptp_clock, clock);
mutex_destroy(&ptp->tsevq_mux);
mutex_destroy(&ptp->pincfg_mux);
ida_simple_remove(&ptp_clocks_map, ptp->index);
kfree(ptp);
}
struct ptp_clock *ptp_clock_register(struct ptp_clock_info *info,
struct device *parent)
{
struct ptp_clock *ptp;
int err = 0, index, major = MAJOR(ptp_devt);
if (info->n_alarm > PTP_MAX_ALARMS)
return ERR_PTR(-EINVAL);
err = -ENOMEM;
ptp = kzalloc(sizeof(struct ptp_clock), GFP_KERNEL);
if (ptp == NULL)
goto no_memory;
index = ida_simple_get(&ptp_clocks_map, 0, MINORMASK + 1, GFP_KERNEL);
if (index < 0) {
err = index;
goto no_slot;
}
ptp->clock.ops = ptp_clock_ops;
ptp->clock.release = delete_ptp_clock;
ptp->info = info;
ptp->devid = MKDEV(major, index);
ptp->index = index;
spin_lock_init(&ptp->tsevq.lock);
mutex_init(&ptp->tsevq_mux);
mutex_init(&ptp->pincfg_mux);
init_waitqueue_head(&ptp->tsev_wq);
ptp->dev = device_create(ptp_class, parent, ptp->devid, ptp,
"ptp%d", ptp->index);
if (IS_ERR(ptp->dev))
goto no_device;
dev_set_drvdata(ptp->dev, ptp);
err = ptp_populate_sysfs(ptp);
if (err)
goto no_sysfs;
if (info->pps) {
struct pps_source_info pps;
memset(&pps, 0, sizeof(pps));
snprintf(pps.name, PPS_MAX_NAME_LEN, "ptp%d", index);
pps.mode = PTP_PPS_MODE;
pps.owner = info->owner;
ptp->pps_source = pps_register_source(&pps, PTP_PPS_DEFAULTS);
if (!ptp->pps_source) {
pr_err("failed to register pps source\n");
goto no_pps;
}
}
err = posix_clock_register(&ptp->clock, ptp->devid);
if (err) {
pr_err("failed to create posix clock\n");
goto no_clock;
}
return ptp;
no_clock:
if (ptp->pps_source)
pps_unregister_source(ptp->pps_source);
no_pps:
ptp_cleanup_sysfs(ptp);
no_sysfs:
device_destroy(ptp_class, ptp->devid);
no_device:
mutex_destroy(&ptp->tsevq_mux);
mutex_destroy(&ptp->pincfg_mux);
ida_simple_remove(&ptp_clocks_map, index);
no_slot:
kfree(ptp);
no_memory:
return ERR_PTR(err);
}
int ptp_clock_unregister(struct ptp_clock *ptp)
{
ptp->defunct = 1;
wake_up_interruptible(&ptp->tsev_wq);
if (ptp->pps_source)
pps_unregister_source(ptp->pps_source);
ptp_cleanup_sysfs(ptp);
device_destroy(ptp_class, ptp->devid);
posix_clock_unregister(&ptp->clock);
return 0;
}
void ptp_clock_event(struct ptp_clock *ptp, struct ptp_clock_event *event)
{
struct pps_event_time evt;
switch (event->type) {
case PTP_CLOCK_ALARM:
break;
case PTP_CLOCK_EXTTS:
enqueue_external_timestamp(&ptp->tsevq, event);
wake_up_interruptible(&ptp->tsev_wq);
break;
case PTP_CLOCK_PPS:
pps_get_ts(&evt);
pps_event(ptp->pps_source, &evt, PTP_PPS_EVENT, NULL);
break;
case PTP_CLOCK_PPSUSR:
pps_event(ptp->pps_source, &event->pps_times,
PTP_PPS_EVENT, NULL);
break;
}
}
int ptp_clock_index(struct ptp_clock *ptp)
{
return ptp->index;
}
int ptp_find_pin(struct ptp_clock *ptp,
enum ptp_pin_function func, unsigned int chan)
{
struct ptp_pin_desc *pin = NULL;
int i;
mutex_lock(&ptp->pincfg_mux);
for (i = 0; i < ptp->info->n_pins; i++) {
if (ptp->info->pin_config[i].func == func &&
ptp->info->pin_config[i].chan == chan) {
pin = &ptp->info->pin_config[i];
break;
}
}
mutex_unlock(&ptp->pincfg_mux);
return pin ? i : -1;
}
static void __exit ptp_exit(void)
{
class_destroy(ptp_class);
unregister_chrdev_region(ptp_devt, MINORMASK + 1);
ida_destroy(&ptp_clocks_map);
}
static int __init ptp_init(void)
{
int err;
ptp_class = class_create(THIS_MODULE, "ptp");
if (IS_ERR(ptp_class)) {
pr_err("ptp: failed to allocate class\n");
return PTR_ERR(ptp_class);
}
err = alloc_chrdev_region(&ptp_devt, 0, MINORMASK + 1, "ptp");
if (err < 0) {
pr_err("ptp: failed to allocate device region\n");
goto no_region;
}
ptp_class->dev_groups = ptp_groups;
pr_info("PTP clock support registered\n");
return 0;
no_region:
class_destroy(ptp_class);
return err;
}
