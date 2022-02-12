static void syncpt_restore(struct host1x_syncpt *sp)
{
struct host1x *host = sp->host;
int min = host1x_syncpt_read_min(sp);
host1x_sync_writel(host, min, HOST1X_SYNC_SYNCPT(sp->id));
}
static void syncpt_restore_wait_base(struct host1x_syncpt *sp)
{
struct host1x *host = sp->host;
host1x_sync_writel(host, sp->base_val,
HOST1X_SYNC_SYNCPT_BASE(sp->id));
}
static void syncpt_read_wait_base(struct host1x_syncpt *sp)
{
struct host1x *host = sp->host;
sp->base_val =
host1x_sync_readl(host, HOST1X_SYNC_SYNCPT_BASE(sp->id));
}
static u32 syncpt_load(struct host1x_syncpt *sp)
{
struct host1x *host = sp->host;
u32 old, live;
do {
old = host1x_syncpt_read_min(sp);
live = host1x_sync_readl(host, HOST1X_SYNC_SYNCPT(sp->id));
} while ((u32)atomic_cmpxchg(&sp->min_val, old, live) != old);
if (!host1x_syncpt_check_max(sp, live))
dev_err(host->dev, "%s failed: id=%u, min=%d, max=%d\n",
__func__, sp->id, host1x_syncpt_read_min(sp),
host1x_syncpt_read_max(sp));
return live;
}
static int syncpt_cpu_incr(struct host1x_syncpt *sp)
{
struct host1x *host = sp->host;
u32 reg_offset = sp->id / 32;
if (!host1x_syncpt_client_managed(sp) &&
host1x_syncpt_idle(sp))
return -EINVAL;
host1x_sync_writel(host, BIT_MASK(sp->id),
HOST1X_SYNC_SYNCPT_CPU_INCR(reg_offset));
wmb();
return 0;
}
static int syncpt_patch_wait(struct host1x_syncpt *sp, void *patch_addr)
{
u32 override = host1x_class_host_wait_syncpt(
HOST1X_SYNCPT_RESERVED, 0);
*((u32 *)patch_addr) = override;
return 0;
}
