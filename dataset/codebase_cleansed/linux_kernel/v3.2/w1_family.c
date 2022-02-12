int w1_register_family(struct w1_family *newf)
{
struct list_head *ent, *n;
struct w1_family *f;
int ret = 0;
spin_lock(&w1_flock);
list_for_each_safe(ent, n, &w1_families) {
f = list_entry(ent, struct w1_family, family_entry);
if (f->fid == newf->fid) {
ret = -EEXIST;
break;
}
}
if (!ret) {
atomic_set(&newf->refcnt, 0);
list_add_tail(&newf->family_entry, &w1_families);
}
spin_unlock(&w1_flock);
w1_reconnect_slaves(newf, 1);
return ret;
}
void w1_unregister_family(struct w1_family *fent)
{
struct list_head *ent, *n;
struct w1_family *f;
spin_lock(&w1_flock);
list_for_each_safe(ent, n, &w1_families) {
f = list_entry(ent, struct w1_family, family_entry);
if (f->fid == fent->fid) {
list_del(&fent->family_entry);
break;
}
}
spin_unlock(&w1_flock);
w1_reconnect_slaves(fent, 0);
while (atomic_read(&fent->refcnt)) {
printk(KERN_INFO "Waiting for family %u to become free: refcnt=%d.\n",
fent->fid, atomic_read(&fent->refcnt));
if (msleep_interruptible(1000))
flush_signals(current);
}
}
struct w1_family * w1_family_registered(u8 fid)
{
struct list_head *ent, *n;
struct w1_family *f = NULL;
int ret = 0;
list_for_each_safe(ent, n, &w1_families) {
f = list_entry(ent, struct w1_family, family_entry);
if (f->fid == fid) {
ret = 1;
break;
}
}
return (ret) ? f : NULL;
}
static void __w1_family_put(struct w1_family *f)
{
atomic_dec(&f->refcnt);
}
void w1_family_put(struct w1_family *f)
{
spin_lock(&w1_flock);
__w1_family_put(f);
spin_unlock(&w1_flock);
}
void __w1_family_get(struct w1_family *f)
{
smp_mb__before_atomic_inc();
atomic_inc(&f->refcnt);
smp_mb__after_atomic_inc();
}
