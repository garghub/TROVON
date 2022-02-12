void
cfs_percpt_lock_free(struct cfs_percpt_lock *pcl)
{
LASSERT(pcl->pcl_locks != NULL);
LASSERT(!pcl->pcl_locked);
cfs_percpt_free(pcl->pcl_locks);
LIBCFS_FREE(pcl, sizeof(*pcl));
}
struct cfs_percpt_lock *
cfs_percpt_lock_alloc(struct cfs_cpt_table *cptab)
{
struct cfs_percpt_lock *pcl;
spinlock_t *lock;
int i;
LIBCFS_ALLOC(pcl, sizeof(*pcl));
if (pcl == NULL)
return NULL;
pcl->pcl_cptab = cptab;
pcl->pcl_locks = cfs_percpt_alloc(cptab, sizeof(*lock));
if (pcl->pcl_locks == NULL) {
LIBCFS_FREE(pcl, sizeof(*pcl));
return NULL;
}
cfs_percpt_for_each(lock, i, pcl->pcl_locks)
spin_lock_init(lock);
return pcl;
}
void
cfs_percpt_lock(struct cfs_percpt_lock *pcl, int index)
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
if (i == 0) {
LASSERT(!pcl->pcl_locked);
pcl->pcl_locked = 1;
}
}
}
void
cfs_percpt_unlock(struct cfs_percpt_lock *pcl, int index)
{
int ncpt = cfs_cpt_number(pcl->pcl_cptab);
int i;
index = ncpt == 1 ? 0 : index;
if (likely(index != CFS_PERCPT_LOCK_EX)) {
spin_unlock(pcl->pcl_locks[index]);
return;
}
for (i = ncpt - 1; i >= 0; i--) {
if (i == 0) {
LASSERT(pcl->pcl_locked);
pcl->pcl_locked = 0;
}
spin_unlock(pcl->pcl_locks[i]);
}
}
void
cfs_percpt_atomic_free(atomic_t **refs)
{
cfs_percpt_free(refs);
}
atomic_t **
cfs_percpt_atomic_alloc(struct cfs_cpt_table *cptab, int init_val)
{
atomic_t **refs;
atomic_t *ref;
int i;
refs = cfs_percpt_alloc(cptab, sizeof(*ref));
if (refs == NULL)
return NULL;
cfs_percpt_for_each(ref, i, refs)
atomic_set(ref, init_val);
return refs;
}
int
cfs_percpt_atomic_summary(atomic_t **refs)
{
atomic_t *ref;
int i;
int val = 0;
cfs_percpt_for_each(ref, i, refs)
val += atomic_read(ref);
return val;
}
