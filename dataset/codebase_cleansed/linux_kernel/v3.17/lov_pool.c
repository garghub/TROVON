static void lov_pool_getref(struct pool_desc *pool)
{
CDEBUG(D_INFO, "pool %p\n", pool);
atomic_inc(&pool->pool_refcount);
}
void lov_pool_putref(struct pool_desc *pool)
{
CDEBUG(D_INFO, "pool %p\n", pool);
if (atomic_dec_and_test(&pool->pool_refcount)) {
LASSERT(hlist_unhashed(&pool->pool_hash));
LASSERT(list_empty(&pool->pool_list));
LASSERT(pool->pool_proc_entry == NULL);
lov_ost_pool_free(&(pool->pool_rr.lqr_pool));
lov_ost_pool_free(&(pool->pool_obds));
OBD_FREE_PTR(pool);
}
}
void lov_pool_putref_locked(struct pool_desc *pool)
{
CDEBUG(D_INFO, "pool %p\n", pool);
LASSERT(atomic_read(&pool->pool_refcount) > 1);
atomic_dec(&pool->pool_refcount);
}
static __u32 pool_hashfn(struct cfs_hash *hash_body, const void *key, unsigned mask)
{
int i;
__u32 result;
char *poolname;
result = 0;
poolname = (char *)key;
for (i = 0; i < LOV_MAXPOOLNAME; i++) {
if (poolname[i] == '\0')
break;
result = (result << 4)^(result >> 28) ^ poolname[i];
}
return (result % mask);
}
static void *pool_key(struct hlist_node *hnode)
{
struct pool_desc *pool;
pool = hlist_entry(hnode, struct pool_desc, pool_hash);
return (pool->pool_name);
}
static int pool_hashkey_keycmp(const void *key, struct hlist_node *compared_hnode)
{
char *pool_name;
struct pool_desc *pool;
pool_name = (char *)key;
pool = hlist_entry(compared_hnode, struct pool_desc, pool_hash);
return !strncmp(pool_name, pool->pool_name, LOV_MAXPOOLNAME);
}
static void *pool_hashobject(struct hlist_node *hnode)
{
return hlist_entry(hnode, struct pool_desc, pool_hash);
}
static void pool_hashrefcount_get(struct cfs_hash *hs, struct hlist_node *hnode)
{
struct pool_desc *pool;
pool = hlist_entry(hnode, struct pool_desc, pool_hash);
lov_pool_getref(pool);
}
static void pool_hashrefcount_put_locked(struct cfs_hash *hs,
struct hlist_node *hnode)
{
struct pool_desc *pool;
pool = hlist_entry(hnode, struct pool_desc, pool_hash);
lov_pool_putref_locked(pool);
}
static void *pool_proc_next(struct seq_file *s, void *v, loff_t *pos)
{
struct pool_iterator *iter = (struct pool_iterator *)s->private;
int prev_idx;
LASSERTF(iter->magic == POOL_IT_MAGIC, "%08X", iter->magic);
if (*pos >= pool_tgt_count(iter->pool))
return NULL;
prev_idx = iter->idx;
down_read(&pool_tgt_rw_sem(iter->pool));
iter->idx++;
if (iter->idx == pool_tgt_count(iter->pool)) {
iter->idx = prev_idx;
up_read(&pool_tgt_rw_sem(iter->pool));
return NULL;
}
up_read(&pool_tgt_rw_sem(iter->pool));
(*pos)++;
return iter;
}
static void *pool_proc_start(struct seq_file *s, loff_t *pos)
{
struct pool_desc *pool = (struct pool_desc *)s->private;
struct pool_iterator *iter;
lov_pool_getref(pool);
if ((pool_tgt_count(pool) == 0) ||
(*pos >= pool_tgt_count(pool))) {
lov_pool_putref(pool);
return NULL;
}
OBD_ALLOC_PTR(iter);
if (!iter)
return ERR_PTR(-ENOMEM);
iter->magic = POOL_IT_MAGIC;
iter->pool = pool;
iter->idx = 0;
s->private = iter;
if (*pos > 0) {
loff_t i;
void *ptr;
i = 0;
do {
ptr = pool_proc_next(s, &iter, &i);
} while ((i < *pos) && (ptr != NULL));
return ptr;
}
return iter;
}
static void pool_proc_stop(struct seq_file *s, void *v)
{
struct pool_iterator *iter = (struct pool_iterator *)s->private;
if ((iter) && (iter->magic == POOL_IT_MAGIC)) {
s->private = iter->pool;
lov_pool_putref(iter->pool);
OBD_FREE_PTR(iter);
}
return;
}
static int pool_proc_show(struct seq_file *s, void *v)
{
struct pool_iterator *iter = (struct pool_iterator *)v;
struct lov_tgt_desc *tgt;
LASSERTF(iter->magic == POOL_IT_MAGIC, "%08X", iter->magic);
LASSERT(iter->pool != NULL);
LASSERT(iter->idx <= pool_tgt_count(iter->pool));
down_read(&pool_tgt_rw_sem(iter->pool));
tgt = pool_tgt(iter->pool, iter->idx);
up_read(&pool_tgt_rw_sem(iter->pool));
if (tgt)
seq_printf(s, "%s\n", obd_uuid2str(&(tgt->ltd_uuid)));
return 0;
}
static int pool_proc_open(struct inode *inode, struct file *file)
{
int rc;
rc = seq_open(file, &pool_proc_ops);
if (!rc) {
struct seq_file *s = file->private_data;
s->private = PDE_DATA(inode);
}
return rc;
}
void lov_dump_pool(int level, struct pool_desc *pool)
{
int i;
lov_pool_getref(pool);
CDEBUG(level, "pool "LOV_POOLNAMEF" has %d members\n",
pool->pool_name, pool->pool_obds.op_count);
down_read(&pool_tgt_rw_sem(pool));
for (i = 0; i < pool_tgt_count(pool) ; i++) {
if (!pool_tgt(pool, i) || !(pool_tgt(pool, i))->ltd_exp)
continue;
CDEBUG(level, "pool "LOV_POOLNAMEF"[%d] = %s\n",
pool->pool_name, i,
obd_uuid2str(&((pool_tgt(pool, i))->ltd_uuid)));
}
up_read(&pool_tgt_rw_sem(pool));
lov_pool_putref(pool);
}
int lov_ost_pool_init(struct ost_pool *op, unsigned int count)
{
if (count == 0)
count = LOV_POOL_INIT_COUNT;
op->op_array = NULL;
op->op_count = 0;
init_rwsem(&op->op_rw_sem);
op->op_size = count;
OBD_ALLOC(op->op_array, op->op_size * sizeof(op->op_array[0]));
if (op->op_array == NULL) {
op->op_size = 0;
return -ENOMEM;
}
return 0;
}
int lov_ost_pool_extend(struct ost_pool *op, unsigned int min_count)
{
__u32 *new;
int new_size;
LASSERT(min_count != 0);
if (op->op_count < op->op_size)
return 0;
new_size = max(min_count, 2 * op->op_size);
OBD_ALLOC(new, new_size * sizeof(op->op_array[0]));
if (new == NULL)
return -ENOMEM;
memcpy(new, op->op_array, op->op_size * sizeof(op->op_array[0]));
OBD_FREE(op->op_array, op->op_size * sizeof(op->op_array[0]));
op->op_array = new;
op->op_size = new_size;
return 0;
}
int lov_ost_pool_add(struct ost_pool *op, __u32 idx, unsigned int min_count)
{
int rc = 0, i;
down_write(&op->op_rw_sem);
rc = lov_ost_pool_extend(op, min_count);
if (rc)
GOTO(out, rc);
for (i = 0; i < op->op_count; i++) {
if (op->op_array[i] == idx)
GOTO(out, rc = -EEXIST);
}
op->op_array[op->op_count] = idx;
op->op_count++;
out:
up_write(&op->op_rw_sem);
return rc;
}
int lov_ost_pool_remove(struct ost_pool *op, __u32 idx)
{
int i;
down_write(&op->op_rw_sem);
for (i = 0; i < op->op_count; i++) {
if (op->op_array[i] == idx) {
memmove(&op->op_array[i], &op->op_array[i + 1],
(op->op_count - i - 1) * sizeof(op->op_array[0]));
op->op_count--;
up_write(&op->op_rw_sem);
return 0;
}
}
up_write(&op->op_rw_sem);
return -EINVAL;
}
int lov_ost_pool_free(struct ost_pool *op)
{
if (op->op_size == 0)
return 0;
down_write(&op->op_rw_sem);
OBD_FREE(op->op_array, op->op_size * sizeof(op->op_array[0]));
op->op_array = NULL;
op->op_count = 0;
op->op_size = 0;
up_write(&op->op_rw_sem);
return 0;
}
int lov_pool_new(struct obd_device *obd, char *poolname)
{
struct lov_obd *lov;
struct pool_desc *new_pool;
int rc;
lov = &(obd->u.lov);
if (strlen(poolname) > LOV_MAXPOOLNAME)
return -ENAMETOOLONG;
OBD_ALLOC_PTR(new_pool);
if (new_pool == NULL)
return -ENOMEM;
strncpy(new_pool->pool_name, poolname, LOV_MAXPOOLNAME);
new_pool->pool_name[LOV_MAXPOOLNAME] = '\0';
new_pool->pool_lobd = obd;
atomic_set(&new_pool->pool_refcount, 1);
rc = lov_ost_pool_init(&new_pool->pool_obds, 0);
if (rc)
GOTO(out_err, rc);
memset(&(new_pool->pool_rr), 0, sizeof(struct lov_qos_rr));
rc = lov_ost_pool_init(&new_pool->pool_rr.lqr_pool, 0);
if (rc)
GOTO(out_free_pool_obds, rc);
INIT_HLIST_NODE(&new_pool->pool_hash);
#if defined (CONFIG_PROC_FS)
lov_pool_getref(new_pool);
new_pool->pool_proc_entry = lprocfs_add_simple(lov->lov_pool_proc_entry,
poolname, new_pool,
&pool_proc_operations);
if (IS_ERR(new_pool->pool_proc_entry)) {
CWARN("Cannot add proc pool entry "LOV_POOLNAMEF"\n", poolname);
new_pool->pool_proc_entry = NULL;
lov_pool_putref(new_pool);
}
CDEBUG(D_INFO, "pool %p - proc %p\n", new_pool, new_pool->pool_proc_entry);
#endif
spin_lock(&obd->obd_dev_lock);
list_add_tail(&new_pool->pool_list, &lov->lov_pool_list);
lov->lov_pool_count++;
spin_unlock(&obd->obd_dev_lock);
rc = cfs_hash_add_unique(lov->lov_pools_hash_body, poolname,
&new_pool->pool_hash);
if (rc)
GOTO(out_err, rc = -EEXIST);
CDEBUG(D_CONFIG, LOV_POOLNAMEF" is pool #%d\n",
poolname, lov->lov_pool_count);
return 0;
out_err:
spin_lock(&obd->obd_dev_lock);
list_del_init(&new_pool->pool_list);
lov->lov_pool_count--;
spin_unlock(&obd->obd_dev_lock);
lprocfs_remove(&new_pool->pool_proc_entry);
lov_ost_pool_free(&new_pool->pool_rr.lqr_pool);
out_free_pool_obds:
lov_ost_pool_free(&new_pool->pool_obds);
OBD_FREE_PTR(new_pool);
return rc;
}
int lov_pool_del(struct obd_device *obd, char *poolname)
{
struct lov_obd *lov;
struct pool_desc *pool;
lov = &(obd->u.lov);
pool = cfs_hash_del_key(lov->lov_pools_hash_body, poolname);
if (pool == NULL)
return -ENOENT;
if (pool->pool_proc_entry != NULL) {
CDEBUG(D_INFO, "proc entry %p\n", pool->pool_proc_entry);
lprocfs_remove(&pool->pool_proc_entry);
lov_pool_putref(pool);
}
spin_lock(&obd->obd_dev_lock);
list_del_init(&pool->pool_list);
lov->lov_pool_count--;
spin_unlock(&obd->obd_dev_lock);
lov_pool_putref(pool);
return 0;
}
int lov_pool_add(struct obd_device *obd, char *poolname, char *ostname)
{
struct obd_uuid ost_uuid;
struct lov_obd *lov;
struct pool_desc *pool;
unsigned int lov_idx;
int rc;
lov = &(obd->u.lov);
pool = cfs_hash_lookup(lov->lov_pools_hash_body, poolname);
if (pool == NULL)
return -ENOENT;
obd_str2uuid(&ost_uuid, ostname);
obd_getref(obd);
for (lov_idx = 0; lov_idx < lov->desc.ld_tgt_count; lov_idx++) {
if (!lov->lov_tgts[lov_idx])
continue;
if (obd_uuid_equals(&ost_uuid,
&(lov->lov_tgts[lov_idx]->ltd_uuid)))
break;
}
if (lov_idx == lov->desc.ld_tgt_count)
GOTO(out, rc = -EINVAL);
rc = lov_ost_pool_add(&pool->pool_obds, lov_idx, lov->lov_tgt_size);
if (rc)
GOTO(out, rc);
pool->pool_rr.lqr_dirty = 1;
CDEBUG(D_CONFIG, "Added %s to "LOV_POOLNAMEF" as member %d\n",
ostname, poolname, pool_tgt_count(pool));
out:
obd_putref(obd);
lov_pool_putref(pool);
return rc;
}
int lov_pool_remove(struct obd_device *obd, char *poolname, char *ostname)
{
struct obd_uuid ost_uuid;
struct lov_obd *lov;
struct pool_desc *pool;
unsigned int lov_idx;
int rc = 0;
lov = &(obd->u.lov);
pool = cfs_hash_lookup(lov->lov_pools_hash_body, poolname);
if (pool == NULL)
return -ENOENT;
obd_str2uuid(&ost_uuid, ostname);
obd_getref(obd);
for (lov_idx = 0; lov_idx < lov->desc.ld_tgt_count; lov_idx++) {
if (!lov->lov_tgts[lov_idx])
continue;
if (obd_uuid_equals(&ost_uuid,
&(lov->lov_tgts[lov_idx]->ltd_uuid)))
break;
}
if (lov_idx == lov->desc.ld_tgt_count)
GOTO(out, rc = -EINVAL);
lov_ost_pool_remove(&pool->pool_obds, lov_idx);
pool->pool_rr.lqr_dirty = 1;
CDEBUG(D_CONFIG, "%s removed from "LOV_POOLNAMEF"\n", ostname,
poolname);
out:
obd_putref(obd);
lov_pool_putref(pool);
return rc;
}
int lov_check_index_in_pool(__u32 idx, struct pool_desc *pool)
{
int i, rc;
lov_pool_getref(pool);
down_read(&pool_tgt_rw_sem(pool));
for (i = 0; i < pool_tgt_count(pool); i++) {
if (pool_tgt_array(pool)[i] == idx)
GOTO(out, rc = 0);
}
rc = -ENOENT;
out:
up_read(&pool_tgt_rw_sem(pool));
lov_pool_putref(pool);
return rc;
}
struct pool_desc *lov_find_pool(struct lov_obd *lov, char *poolname)
{
struct pool_desc *pool;
pool = NULL;
if (poolname[0] != '\0') {
pool = cfs_hash_lookup(lov->lov_pools_hash_body, poolname);
if (pool == NULL)
CWARN("Request for an unknown pool ("LOV_POOLNAMEF")\n",
poolname);
if ((pool != NULL) && (pool_tgt_count(pool) == 0)) {
CWARN("Request for an empty pool ("LOV_POOLNAMEF")\n",
poolname);
lov_pool_putref(pool);
pool = NULL;
}
}
return pool;
}
