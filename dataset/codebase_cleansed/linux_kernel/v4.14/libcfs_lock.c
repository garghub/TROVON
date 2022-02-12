void
cfs_percpt_lock_free(struct cfs_percpt_lock *pcl)
{
LASSERT(pcl->pcl_locks);
LASSERT(!pcl->pcl_locked);
cfs_percpt_free(pcl->pcl_locks);
LIBCFS_FREE(pcl, sizeof(*pcl));
}
struct cfs_percpt_lock *
cfs_percpt_lock_create(struct cfs_cpt_table *cptab,
struct lock_class_key *keys)
{
struct cfs_percpt_lock *pcl;
spinlock_t *lock;
int i;
LIBCFS_ALLOC(pcl, sizeof(*pcl));
if (!pcl)
return NULL;
pcl->pcl_cptab = cptab;
pcl->pcl_locks = cfs_percpt_alloc(cptab, sizeof(*lock));
if (!pcl->pcl_locks) {
LIBCFS_FREE(pcl, sizeof(*pcl));
return NULL;
}
if (!keys)
CWARN("Cannot setup class key for percpt lock, you may see recursive locking warnings which are actually fake.\n");
cfs_percpt_for_each(lock, i, pcl->pcl_locks) {
spin_lock_init(lock);
if (keys)
lockdep_set_class(lock, &keys[i]);
}
return pcl;
}
void
cfs_percpt_lock(struct cfs_percpt_lock *pcl, int index)
__acquires(pcl->pcl_locks)
{
int ncpt = cfs_cpt_number(pcl->pcl_cptab);
int i;
LASSERT(index >= CFS_PERCPT_LOCK_EX && index < ncpt);
if (ncpt == 1) {
index = 0;
} else {
while (pcl->pcl_locked)
cpu_relax();
}
if (likely(index != CFS_PERCPT_LOCK_EX)) {
spin_lock(pcl->pcl_locks[index]);
return;
}
for (i = 0; i < ncpt; i++) {
spin_lock(pcl->pcl_locks[i]);
if (!i) {
LASSERT(!pcl->pcl_locked);
pcl->pcl_locked = 1;
}
}
}
void
cfs_percpt_unlock(struct cfs_percpt_lock *pcl, int index)
__releases(pcl->pcl_locks)
{
int ncpt = cfs_cpt_number(pcl->pcl_cptab);
int i;
index = ncpt == 1 ? 0 : index;
if (likely(index != CFS_PERCPT_LOCK_EX)) {
spin_unlock(pcl->pcl_locks[index]);
return;
}
for (i = ncpt - 1; i >= 0; i--) {
if (!i) {
LASSERT(pcl->pcl_locked);
pcl->pcl_locked = 0;
}
spin_unlock(pcl->pcl_locks[i]);
}
}
