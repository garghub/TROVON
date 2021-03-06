static ssize_t aoedisk_show_state(struct device *dev,
struct device_attribute *attr, char *page)
{
struct gendisk *disk = dev_to_disk(dev);
struct aoedev *d = disk->private_data;
return snprintf(page, PAGE_SIZE,
"%s%s\n",
(d->flags & DEVFL_UP) ? "up" : "down",
(d->flags & DEVFL_KICKME) ? ",kickme" :
(d->nopen && !(d->flags & DEVFL_UP)) ? ",closewait" : "");
}
static ssize_t aoedisk_show_mac(struct device *dev,
struct device_attribute *attr, char *page)
{
struct gendisk *disk = dev_to_disk(dev);
struct aoedev *d = disk->private_data;
struct aoetgt *t = d->targets[0];
if (t == NULL)
return snprintf(page, PAGE_SIZE, "none\n");
return snprintf(page, PAGE_SIZE, "%pm\n", t->addr);
}
static ssize_t aoedisk_show_netif(struct device *dev,
struct device_attribute *attr, char *page)
{
struct gendisk *disk = dev_to_disk(dev);
struct aoedev *d = disk->private_data;
struct net_device *nds[8], **nd, **nnd, **ne;
struct aoetgt **t, **te;
struct aoeif *ifp, *e;
char *p;
memset(nds, 0, sizeof nds);
nd = nds;
ne = nd + ARRAY_SIZE(nds);
t = d->targets;
te = t + d->ntargets;
for (; t < te && *t; t++) {
ifp = (*t)->ifs;
e = ifp + NAOEIFS;
for (; ifp < e && ifp->nd; ifp++) {
for (nnd = nds; nnd < nd; nnd++)
if (*nnd == ifp->nd)
break;
if (nnd == nd && nd != ne)
*nd++ = ifp->nd;
}
}
ne = nd;
nd = nds;
if (*nd == NULL)
return snprintf(page, PAGE_SIZE, "none\n");
for (p = page; nd < ne; nd++)
p += snprintf(p, PAGE_SIZE - (p-page), "%s%s",
p == page ? "" : ",", (*nd)->name);
p += snprintf(p, PAGE_SIZE - (p-page), "\n");
return p-page;
}
static ssize_t aoedisk_show_fwver(struct device *dev,
struct device_attribute *attr, char *page)
{
struct gendisk *disk = dev_to_disk(dev);
struct aoedev *d = disk->private_data;
return snprintf(page, PAGE_SIZE, "0x%04x\n", (unsigned int) d->fw_ver);
}
static ssize_t aoedisk_show_payload(struct device *dev,
struct device_attribute *attr, char *page)
{
struct gendisk *disk = dev_to_disk(dev);
struct aoedev *d = disk->private_data;
return snprintf(page, PAGE_SIZE, "%lu\n", d->maxbcnt);
}
static int
aoedisk_add_sysfs(struct aoedev *d)
{
return sysfs_create_group(&disk_to_dev(d->gd)->kobj, &attr_group);
}
void
aoedisk_rm_sysfs(struct aoedev *d)
{
sysfs_remove_group(&disk_to_dev(d->gd)->kobj, &attr_group);
}
static int
aoeblk_open(struct block_device *bdev, fmode_t mode)
{
struct aoedev *d = bdev->bd_disk->private_data;
ulong flags;
if (!virt_addr_valid(d)) {
pr_crit("aoe: invalid device pointer in %s\n",
__func__);
WARN_ON(1);
return -ENODEV;
}
if (!(d->flags & DEVFL_UP) || d->flags & DEVFL_TKILL)
return -ENODEV;
mutex_lock(&aoeblk_mutex);
spin_lock_irqsave(&d->lock, flags);
if (d->flags & DEVFL_UP && !(d->flags & DEVFL_TKILL)) {
d->nopen++;
spin_unlock_irqrestore(&d->lock, flags);
mutex_unlock(&aoeblk_mutex);
return 0;
}
spin_unlock_irqrestore(&d->lock, flags);
mutex_unlock(&aoeblk_mutex);
return -ENODEV;
}
static void
aoeblk_release(struct gendisk *disk, fmode_t mode)
{
struct aoedev *d = disk->private_data;
ulong flags;
spin_lock_irqsave(&d->lock, flags);
if (--d->nopen == 0) {
spin_unlock_irqrestore(&d->lock, flags);
aoecmd_cfg(d->aoemajor, d->aoeminor);
return;
}
spin_unlock_irqrestore(&d->lock, flags);
}
static void
aoeblk_request(struct request_queue *q)
{
struct aoedev *d;
struct request *rq;
d = q->queuedata;
if ((d->flags & DEVFL_UP) == 0) {
pr_info_ratelimited("aoe: device %ld.%d is not up\n",
d->aoemajor, d->aoeminor);
while ((rq = blk_peek_request(q))) {
blk_start_request(rq);
aoe_end_request(d, rq, 1);
}
return;
}
aoecmd_work(d);
}
static int
aoeblk_getgeo(struct block_device *bdev, struct hd_geometry *geo)
{
struct aoedev *d = bdev->bd_disk->private_data;
if ((d->flags & DEVFL_UP) == 0) {
printk(KERN_ERR "aoe: disk not up\n");
return -ENODEV;
}
geo->cylinders = d->geo.cylinders;
geo->heads = d->geo.heads;
geo->sectors = d->geo.sectors;
return 0;
}
static int
aoeblk_ioctl(struct block_device *bdev, fmode_t mode, uint cmd, ulong arg)
{
struct aoedev *d;
if (!arg)
return -EINVAL;
d = bdev->bd_disk->private_data;
if ((d->flags & DEVFL_UP) == 0) {
pr_err("aoe: disk not up\n");
return -ENODEV;
}
if (cmd == HDIO_GET_IDENTITY) {
if (!copy_to_user((void __user *) arg, &d->ident,
sizeof(d->ident)))
return 0;
return -EFAULT;
}
if (cmd != SG_IO)
pr_info("aoe: unknown ioctl 0x%x\n", cmd);
return -ENOTTY;
}
void
aoeblk_gdalloc(void *vp)
{
struct aoedev *d = vp;
struct gendisk *gd;
mempool_t *mp;
struct request_queue *q;
enum { KB = 1024, MB = KB * KB, READ_AHEAD = 2 * MB, };
ulong flags;
int late = 0;
spin_lock_irqsave(&d->lock, flags);
if (d->flags & DEVFL_GDALLOC
&& !(d->flags & DEVFL_TKILL)
&& !(d->flags & DEVFL_GD_NOW))
d->flags |= DEVFL_GD_NOW;
else
late = 1;
spin_unlock_irqrestore(&d->lock, flags);
if (late)
return;
gd = alloc_disk(AOE_PARTITIONS);
if (gd == NULL) {
pr_err("aoe: cannot allocate disk structure for %ld.%d\n",
d->aoemajor, d->aoeminor);
goto err;
}
mp = mempool_create(MIN_BUFS, mempool_alloc_slab, mempool_free_slab,
buf_pool_cache);
if (mp == NULL) {
printk(KERN_ERR "aoe: cannot allocate bufpool for %ld.%d\n",
d->aoemajor, d->aoeminor);
goto err_disk;
}
q = blk_init_queue(aoeblk_request, &d->lock);
if (q == NULL) {
pr_err("aoe: cannot allocate block queue for %ld.%d\n",
d->aoemajor, d->aoeminor);
goto err_mempool;
}
spin_lock_irqsave(&d->lock, flags);
WARN_ON(!(d->flags & DEVFL_GD_NOW));
WARN_ON(!(d->flags & DEVFL_GDALLOC));
WARN_ON(d->flags & DEVFL_TKILL);
WARN_ON(d->gd);
WARN_ON(d->flags & DEVFL_UP);
blk_queue_max_hw_sectors(q, BLK_DEF_MAX_SECTORS);
q->backing_dev_info.name = "aoe";
q->backing_dev_info.ra_pages = READ_AHEAD / PAGE_CACHE_SIZE;
d->bufpool = mp;
d->blkq = gd->queue = q;
q->queuedata = d;
d->gd = gd;
if (aoe_maxsectors)
blk_queue_max_hw_sectors(q, aoe_maxsectors);
gd->major = AOE_MAJOR;
gd->first_minor = d->sysminor;
gd->fops = &aoe_bdops;
gd->private_data = d;
set_capacity(gd, d->ssize);
snprintf(gd->disk_name, sizeof gd->disk_name, "etherd/e%ld.%d",
d->aoemajor, d->aoeminor);
d->flags &= ~DEVFL_GDALLOC;
d->flags |= DEVFL_UP;
spin_unlock_irqrestore(&d->lock, flags);
add_disk(gd);
aoedisk_add_sysfs(d);
spin_lock_irqsave(&d->lock, flags);
WARN_ON(!(d->flags & DEVFL_GD_NOW));
d->flags &= ~DEVFL_GD_NOW;
spin_unlock_irqrestore(&d->lock, flags);
return;
err_mempool:
mempool_destroy(mp);
err_disk:
put_disk(gd);
err:
spin_lock_irqsave(&d->lock, flags);
d->flags &= ~DEVFL_GD_NOW;
schedule_work(&d->work);
spin_unlock_irqrestore(&d->lock, flags);
}
void
aoeblk_exit(void)
{
kmem_cache_destroy(buf_pool_cache);
}
int __init
aoeblk_init(void)
{
buf_pool_cache = kmem_cache_create("aoe_bufs",
sizeof(struct buf),
0, 0, NULL);
if (buf_pool_cache == NULL)
return -ENOMEM;
return 0;
}
