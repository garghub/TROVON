static struct host1x_syncpt_base *
host1x_syncpt_base_request(struct host1x *host)
{
struct host1x_syncpt_base *bases = host->bases;
unsigned int i;
for (i = 0; i < host->info->nb_bases; i++)
if (!bases[i].requested)
break;
if (i >= host->info->nb_bases)
return NULL;
bases[i].requested = true;
return &bases[i];
}
static void host1x_syncpt_base_free(struct host1x_syncpt_base *base)
{
if (base)
base->requested = false;
}
static struct host1x_syncpt *host1x_syncpt_alloc(struct host1x *host,
struct device *dev,
unsigned long flags)
{
int i;
struct host1x_syncpt *sp = host->syncpt;
char *name;
for (i = 0; i < host->info->nb_pts && sp->name; i++, sp++)
;
if (i >= host->info->nb_pts)
return NULL;
if (flags & HOST1X_SYNCPT_HAS_BASE) {
sp->base = host1x_syncpt_base_request(host);
if (!sp->base)
return NULL;
}
name = kasprintf(GFP_KERNEL, "%02u-%s", sp->id,
dev ? dev_name(dev) : NULL);
if (!name)
return NULL;
sp->dev = dev;
sp->name = name;
if (flags & HOST1X_SYNCPT_CLIENT_MANAGED)
sp->client_managed = true;
else
sp->client_managed = false;
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
unsigned int i;
for (i = 0; i < host1x_syncpt_nb_pts(host); i++)
host1x_hw_syncpt_restore(host, sp_base + i);
for (i = 0; i < host1x_syncpt_nb_bases(host); i++)
host1x_hw_syncpt_restore_wait_base(host, sp_base + i);
wmb();
}
void host1x_syncpt_save(struct host1x *host)
{
struct host1x_syncpt *sp_base = host->syncpt;
unsigned int i;
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
host1x_hw_syncpt_load_wait_base(sp->host, sp);
return sp->base_val;
}
int host1x_syncpt_incr(struct host1x_syncpt *sp)
{
return host1x_hw_syncpt_cpu_incr(sp->host, sp);
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
int remain;
remain = wait_event_interruptible_timeout(wq,
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
"%s: syncpoint id %u (%s) stuck waiting %d, timeout=%ld\n",
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
struct host1x_syncpt_base *bases;
struct host1x_syncpt *syncpt;
unsigned int i;
syncpt = devm_kcalloc(host->dev, host->info->nb_pts, sizeof(*syncpt),
GFP_KERNEL);
if (!syncpt)
return -ENOMEM;
bases = devm_kcalloc(host->dev, host->info->nb_bases, sizeof(*bases),
GFP_KERNEL);
if (!bases)
return -ENOMEM;
for (i = 0; i < host->info->nb_pts; i++) {
syncpt[i].id = i;
syncpt[i].host = host;
}
for (i = 0; i < host->info->nb_bases; i++)
bases[i].id = i;
host->syncpt = syncpt;
host->bases = bases;
host1x_syncpt_restore(host);
host->nop_sp = host1x_syncpt_alloc(host, NULL, 0);
if (!host->nop_sp)
return -ENOMEM;
return 0;
}
struct host1x_syncpt *host1x_syncpt_request(struct device *dev,
unsigned long flags)
{
struct host1x *host = dev_get_drvdata(dev->parent);
return host1x_syncpt_alloc(host, dev, flags);
}
void host1x_syncpt_free(struct host1x_syncpt *sp)
{
if (!sp)
return;
host1x_syncpt_base_free(sp->base);
kfree(sp->name);
sp->base = NULL;
sp->dev = NULL;
sp->name = NULL;
sp->client_managed = false;
}
void host1x_syncpt_deinit(struct host1x *host)
{
struct host1x_syncpt *sp = host->syncpt;
unsigned int i;
for (i = 0; i < host->info->nb_pts; i++, sp++)
kfree(sp->name);
}
u32 host1x_syncpt_read_max(struct host1x_syncpt *sp)
{
smp_rmb();
return (u32)atomic_read(&sp->max_val);
}
u32 host1x_syncpt_read_min(struct host1x_syncpt *sp)
{
smp_rmb();
return (u32)atomic_read(&sp->min_val);
}
u32 host1x_syncpt_read(struct host1x_syncpt *sp)
{
return host1x_syncpt_load(sp);
}
unsigned int host1x_syncpt_nb_pts(struct host1x *host)
{
return host->info->nb_pts;
}
unsigned int host1x_syncpt_nb_bases(struct host1x *host)
{
return host->info->nb_bases;
}
unsigned int host1x_syncpt_nb_mlocks(struct host1x *host)
{
return host->info->nb_mlocks;
}
struct host1x_syncpt *host1x_syncpt_get(struct host1x *host, unsigned int id)
{
if (host->info->nb_pts < id)
return NULL;
return host->syncpt + id;
}
struct host1x_syncpt_base *host1x_syncpt_get_base(struct host1x_syncpt *sp)
{
return sp ? sp->base : NULL;
}
u32 host1x_syncpt_base_id(struct host1x_syncpt_base *base)
{
return base->id;
}
