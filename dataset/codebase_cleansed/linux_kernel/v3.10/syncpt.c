static struct host1x_syncpt *_host1x_syncpt_alloc(struct host1x *host,
struct device *dev,
int client_managed)
{
int i;
struct host1x_syncpt *sp = host->syncpt;
char *name;
for (i = 0; i < host->info->nb_pts && sp->name; i++, sp++)
;
if (sp->dev)
return NULL;
name = kasprintf(GFP_KERNEL, "%02d-%s", sp->id,
dev ? dev_name(dev) : NULL);
if (!name)
return NULL;
sp->dev = dev;
sp->name = name;
sp->client_managed = client_managed;
return sp;
}
u32 host1x_syncpt_id(struct host1x_syncpt *sp)
{
return sp->id;
}
u32 host1x_syncpt_incr_max(struct host1x_syncpt *sp, u32 incrs)
{
return (u32)atomic_add_return(incrs, &sp->max_val);
}
void host1x_syncpt_restore(struct host1x *host)
{
struct host1x_syncpt *sp_base = host->syncpt;
u32 i;
for (i = 0; i < host1x_syncpt_nb_pts(host); i++)
host1x_hw_syncpt_restore(host, sp_base + i);
for (i = 0; i < host1x_syncpt_nb_bases(host); i++)
host1x_hw_syncpt_restore_wait_base(host, sp_base + i);
wmb();
}
void host1x_syncpt_save(struct host1x *host)
{
struct host1x_syncpt *sp_base = host->syncpt;
u32 i;
for (i = 0; i < host1x_syncpt_nb_pts(host); i++) {
if (host1x_syncpt_client_managed(sp_base + i))
host1x_hw_syncpt_load(host, sp_base + i);
else
WARN_ON(!host1x_syncpt_idle(sp_base + i));
}
for (i = 0; i < host1x_syncpt_nb_bases(host); i++)
host1x_hw_syncpt_load_wait_base(host, sp_base + i);
}
u32 host1x_syncpt_load(struct host1x_syncpt *sp)
{
u32 val;
val = host1x_hw_syncpt_load(sp->host, sp);
trace_host1x_syncpt_load_min(sp->id, val);
return val;
}
u32 host1x_syncpt_load_wait_base(struct host1x_syncpt *sp)
{
u32 val;
host1x_hw_syncpt_load_wait_base(sp->host, sp);
val = sp->base_val;
return val;
}
void host1x_syncpt_cpu_incr(struct host1x_syncpt *sp)
{
host1x_hw_syncpt_cpu_incr(sp->host, sp);
}
void host1x_syncpt_incr(struct host1x_syncpt *sp)
{
if (host1x_syncpt_client_managed(sp))
host1x_syncpt_incr_max(sp, 1);
host1x_syncpt_cpu_incr(sp);
}
static bool syncpt_load_min_is_expired(struct host1x_syncpt *sp, u32 thresh)
{
host1x_hw_syncpt_load(sp->host, sp);
return host1x_syncpt_is_expired(sp, thresh);
}
int host1x_syncpt_wait(struct host1x_syncpt *sp, u32 thresh, long timeout,
u32 *value)
{
DECLARE_WAIT_QUEUE_HEAD_ONSTACK(wq);
void *ref;
struct host1x_waitlist *waiter;
int err = 0, check_count = 0;
u32 val;
if (value)
*value = 0;
if (host1x_syncpt_is_expired(sp, thresh)) {
if (value)
*value = host1x_syncpt_load(sp);
return 0;
}
val = host1x_hw_syncpt_load(sp->host, sp);
if (host1x_syncpt_is_expired(sp, thresh)) {
if (value)
*value = val;
goto done;
}
if (!timeout) {
err = -EAGAIN;
goto done;
}
waiter = kzalloc(sizeof(*waiter), GFP_KERNEL);
if (!waiter) {
err = -ENOMEM;
goto done;
}
err = host1x_intr_add_action(sp->host, sp->id, thresh,
HOST1X_INTR_ACTION_WAKEUP_INTERRUPTIBLE,
&wq, waiter, &ref);
if (err)
goto done;
err = -EAGAIN;
if (timeout < 0)
timeout = LONG_MAX;
while (timeout) {
long check = min_t(long, SYNCPT_CHECK_PERIOD, timeout);
int remain = wait_event_interruptible_timeout(wq,
syncpt_load_min_is_expired(sp, thresh),
check);
if (remain > 0 || host1x_syncpt_is_expired(sp, thresh)) {
if (value)
*value = host1x_syncpt_load(sp);
err = 0;
break;
}
if (remain < 0) {
err = remain;
break;
}
timeout -= check;
if (timeout && check_count <= MAX_STUCK_CHECK_COUNT) {
dev_warn(sp->host->dev,
"%s: syncpoint id %d (%s) stuck waiting %d, timeout=%ld\n",
current->comm, sp->id, sp->name,
thresh, timeout);
host1x_debug_dump_syncpts(sp->host);
if (check_count == MAX_STUCK_CHECK_COUNT)
host1x_debug_dump(sp->host);
check_count++;
}
}
host1x_intr_put_ref(sp->host, sp->id, ref);
done:
return err;
}
bool host1x_syncpt_is_expired(struct host1x_syncpt *sp, u32 thresh)
{
u32 current_val;
u32 future_val;
smp_rmb();
current_val = (u32)atomic_read(&sp->min_val);
future_val = (u32)atomic_read(&sp->max_val);
if (!host1x_syncpt_client_managed(sp))
return future_val - thresh >= current_val - thresh;
else
return (s32)(current_val - thresh) >= 0;
}
int host1x_syncpt_patch_wait(struct host1x_syncpt *sp, void *patch_addr)
{
return host1x_hw_syncpt_patch_wait(sp->host, sp, patch_addr);
}
int host1x_syncpt_init(struct host1x *host)
{
struct host1x_syncpt *syncpt;
int i;
syncpt = devm_kzalloc(host->dev, sizeof(*syncpt) * host->info->nb_pts,
GFP_KERNEL);
if (!syncpt)
return -ENOMEM;
for (i = 0; i < host->info->nb_pts; ++i) {
syncpt[i].id = i;
syncpt[i].host = host;
}
host->syncpt = syncpt;
host1x_syncpt_restore(host);
host->nop_sp = _host1x_syncpt_alloc(host, NULL, 0);
if (!host->nop_sp)
return -ENOMEM;
return 0;
}
struct host1x_syncpt *host1x_syncpt_request(struct device *dev,
int client_managed)
{
struct host1x *host = dev_get_drvdata(dev->parent);
return _host1x_syncpt_alloc(host, dev, client_managed);
}
void host1x_syncpt_free(struct host1x_syncpt *sp)
{
if (!sp)
return;
kfree(sp->name);
sp->dev = NULL;
sp->name = NULL;
sp->client_managed = 0;
}
void host1x_syncpt_deinit(struct host1x *host)
{
int i;
struct host1x_syncpt *sp = host->syncpt;
for (i = 0; i < host->info->nb_pts; i++, sp++)
kfree(sp->name);
}
int host1x_syncpt_nb_pts(struct host1x *host)
{
return host->info->nb_pts;
}
int host1x_syncpt_nb_bases(struct host1x *host)
{
return host->info->nb_bases;
}
int host1x_syncpt_nb_mlocks(struct host1x *host)
{
return host->info->nb_mlocks;
}
struct host1x_syncpt *host1x_syncpt_get(struct host1x *host, u32 id)
{
if (host->info->nb_pts < id)
return NULL;
return host->syncpt + id;
}
