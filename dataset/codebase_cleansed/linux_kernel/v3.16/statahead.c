static inline int ll_sa_entry_unhashed(struct ll_sa_entry *entry)
{
return list_empty(&entry->se_hash);
}
static inline int ll_sa_entry_stated(struct ll_sa_entry *entry)
{
smp_rmb();
return (entry->se_stat != SA_ENTRY_INIT);
}
static inline int ll_sa_entry_hash(int val)
{
return val & LL_SA_CACHE_MASK;
}
static inline void
ll_sa_entry_enhash(struct ll_statahead_info *sai, struct ll_sa_entry *entry)
{
int i = ll_sa_entry_hash(entry->se_qstr.hash);
spin_lock(&sai->sai_cache_lock[i]);
list_add_tail(&entry->se_hash, &sai->sai_cache[i]);
spin_unlock(&sai->sai_cache_lock[i]);
}
static inline void
ll_sa_entry_unhash(struct ll_statahead_info *sai, struct ll_sa_entry *entry)
{
int i = ll_sa_entry_hash(entry->se_qstr.hash);
spin_lock(&sai->sai_cache_lock[i]);
list_del_init(&entry->se_hash);
spin_unlock(&sai->sai_cache_lock[i]);
}
static inline int agl_should_run(struct ll_statahead_info *sai,
struct inode *inode)
{
return (inode != NULL && S_ISREG(inode->i_mode) && sai->sai_agl_valid);
}
static inline struct ll_sa_entry *
sa_first_received_entry(struct ll_statahead_info *sai)
{
return list_entry(sai->sai_entries_received.next,
struct ll_sa_entry, se_list);
}
static inline struct ll_inode_info *
agl_first_entry(struct ll_statahead_info *sai)
{
return list_entry(sai->sai_entries_agl.next,
struct ll_inode_info, lli_agl_list);
}
static inline int sa_sent_full(struct ll_statahead_info *sai)
{
return atomic_read(&sai->sai_cache_count) >= sai->sai_max;
}
static inline int sa_received_empty(struct ll_statahead_info *sai)
{
return list_empty(&sai->sai_entries_received);
}
static inline int agl_list_empty(struct ll_statahead_info *sai)
{
return list_empty(&sai->sai_entries_agl);
}
static inline int sa_low_hit(struct ll_statahead_info *sai)
{
return ((sai->sai_hit > 7 && sai->sai_hit < 4 * sai->sai_miss) ||
(sai->sai_consecutive_miss > 8));
}
static inline int is_omitted_entry(struct ll_statahead_info *sai, __u64 index)
{
return ((__u64)sai->sai_max + index + SA_OMITTED_ENTRY_MAX <
sai->sai_index);
}
static struct ll_sa_entry *
ll_sa_entry_alloc(struct ll_statahead_info *sai, __u64 index,
const char *name, int len)
{
struct ll_inode_info *lli;
struct ll_sa_entry *entry;
int entry_size;
char *dname;
entry_size = sizeof(struct ll_sa_entry) + (len & ~3) + 4;
OBD_ALLOC(entry, entry_size);
if (unlikely(entry == NULL))
return ERR_PTR(-ENOMEM);
CDEBUG(D_READA, "alloc sa entry %.*s(%p) index "LPU64"\n",
len, name, entry, index);
entry->se_index = index;
atomic_set(&entry->se_refcount, 2);
entry->se_stat = SA_ENTRY_INIT;
entry->se_size = entry_size;
dname = (char *)entry + sizeof(struct ll_sa_entry);
memcpy(dname, name, len);
dname[len] = 0;
entry->se_qstr.hash = full_name_hash(name, len);
entry->se_qstr.len = len;
entry->se_qstr.name = dname;
lli = ll_i2info(sai->sai_inode);
spin_lock(&lli->lli_sa_lock);
list_add_tail(&entry->se_link, &sai->sai_entries);
INIT_LIST_HEAD(&entry->se_list);
ll_sa_entry_enhash(sai, entry);
spin_unlock(&lli->lli_sa_lock);
atomic_inc(&sai->sai_cache_count);
return entry;
}
static struct ll_sa_entry *
ll_sa_entry_get_byname(struct ll_statahead_info *sai, const struct qstr *qstr)
{
struct ll_sa_entry *entry;
int i = ll_sa_entry_hash(qstr->hash);
list_for_each_entry(entry, &sai->sai_cache[i], se_hash) {
if (entry->se_qstr.hash == qstr->hash &&
entry->se_qstr.len == qstr->len &&
memcmp(entry->se_qstr.name, qstr->name, qstr->len) == 0)
return entry;
}
return NULL;
}
static struct ll_sa_entry *
ll_sa_entry_get_byindex(struct ll_statahead_info *sai, __u64 index)
{
struct ll_sa_entry *entry;
list_for_each_entry(entry, &sai->sai_entries, se_link) {
if (entry->se_index == index) {
LASSERT(atomic_read(&entry->se_refcount) > 0);
atomic_inc(&entry->se_refcount);
return entry;
}
if (entry->se_index > index)
break;
}
return NULL;
}
static void ll_sa_entry_cleanup(struct ll_statahead_info *sai,
struct ll_sa_entry *entry)
{
struct md_enqueue_info *minfo = entry->se_minfo;
struct ptlrpc_request *req = entry->se_req;
if (minfo) {
entry->se_minfo = NULL;
ll_intent_release(&minfo->mi_it);
iput(minfo->mi_dir);
OBD_FREE_PTR(minfo);
}
if (req) {
entry->se_req = NULL;
ptlrpc_req_finished(req);
}
}
static void ll_sa_entry_put(struct ll_statahead_info *sai,
struct ll_sa_entry *entry)
{
if (atomic_dec_and_test(&entry->se_refcount)) {
CDEBUG(D_READA, "free sa entry %.*s(%p) index "LPU64"\n",
entry->se_qstr.len, entry->se_qstr.name, entry,
entry->se_index);
LASSERT(list_empty(&entry->se_link));
LASSERT(list_empty(&entry->se_list));
LASSERT(ll_sa_entry_unhashed(entry));
ll_sa_entry_cleanup(sai, entry);
if (entry->se_inode)
iput(entry->se_inode);
OBD_FREE(entry, entry->se_size);
atomic_dec(&sai->sai_cache_count);
}
}
static inline void
do_sa_entry_fini(struct ll_statahead_info *sai, struct ll_sa_entry *entry)
{
struct ll_inode_info *lli = ll_i2info(sai->sai_inode);
LASSERT(!ll_sa_entry_unhashed(entry));
LASSERT(!list_empty(&entry->se_link));
ll_sa_entry_unhash(sai, entry);
spin_lock(&lli->lli_sa_lock);
entry->se_stat = SA_ENTRY_DEST;
list_del_init(&entry->se_link);
if (likely(!list_empty(&entry->se_list)))
list_del_init(&entry->se_list);
spin_unlock(&lli->lli_sa_lock);
ll_sa_entry_put(sai, entry);
}
static void
ll_sa_entry_fini(struct ll_statahead_info *sai, struct ll_sa_entry *entry)
{
struct ll_sa_entry *pos, *next;
if (entry)
do_sa_entry_fini(sai, entry);
list_for_each_entry_safe(pos, next, &sai->sai_entries, se_link) {
if (!is_omitted_entry(sai, pos->se_index))
break;
do_sa_entry_fini(sai, pos);
}
}
static void
do_sa_entry_to_stated(struct ll_statahead_info *sai,
struct ll_sa_entry *entry, se_stat_t stat)
{
struct ll_sa_entry *se;
struct list_head *pos = &sai->sai_entries_stated;
if (!list_empty(&entry->se_list))
list_del_init(&entry->se_list);
list_for_each_entry_reverse(se, &sai->sai_entries_stated, se_list) {
if (se->se_index < entry->se_index) {
pos = &se->se_list;
break;
}
}
list_add(&entry->se_list, pos);
entry->se_stat = stat;
}
static int
ll_sa_entry_to_stated(struct ll_statahead_info *sai,
struct ll_sa_entry *entry, se_stat_t stat)
{
struct ll_inode_info *lli = ll_i2info(sai->sai_inode);
int ret = 1;
ll_sa_entry_cleanup(sai, entry);
spin_lock(&lli->lli_sa_lock);
if (likely(entry->se_stat != SA_ENTRY_DEST)) {
do_sa_entry_to_stated(sai, entry, stat);
ret = 0;
}
spin_unlock(&lli->lli_sa_lock);
return ret;
}
static void ll_agl_add(struct ll_statahead_info *sai,
struct inode *inode, int index)
{
struct ll_inode_info *child = ll_i2info(inode);
struct ll_inode_info *parent = ll_i2info(sai->sai_inode);
int added = 0;
spin_lock(&child->lli_agl_lock);
if (child->lli_agl_index == 0) {
child->lli_agl_index = index;
spin_unlock(&child->lli_agl_lock);
LASSERT(list_empty(&child->lli_agl_list));
igrab(inode);
spin_lock(&parent->lli_agl_lock);
if (agl_list_empty(sai))
added = 1;
list_add_tail(&child->lli_agl_list, &sai->sai_entries_agl);
spin_unlock(&parent->lli_agl_lock);
} else {
spin_unlock(&child->lli_agl_lock);
}
if (added > 0)
wake_up(&sai->sai_agl_thread.t_ctl_waitq);
}
static struct ll_statahead_info *ll_sai_alloc(void)
{
struct ll_statahead_info *sai;
int i;
OBD_ALLOC_PTR(sai);
if (!sai)
return NULL;
atomic_set(&sai->sai_refcount, 1);
spin_lock(&sai_generation_lock);
sai->sai_generation = ++sai_generation;
if (unlikely(sai_generation == 0))
sai->sai_generation = ++sai_generation;
spin_unlock(&sai_generation_lock);
sai->sai_max = LL_SA_RPC_MIN;
sai->sai_index = 1;
init_waitqueue_head(&sai->sai_waitq);
init_waitqueue_head(&sai->sai_thread.t_ctl_waitq);
init_waitqueue_head(&sai->sai_agl_thread.t_ctl_waitq);
INIT_LIST_HEAD(&sai->sai_entries);
INIT_LIST_HEAD(&sai->sai_entries_received);
INIT_LIST_HEAD(&sai->sai_entries_stated);
INIT_LIST_HEAD(&sai->sai_entries_agl);
for (i = 0; i < LL_SA_CACHE_SIZE; i++) {
INIT_LIST_HEAD(&sai->sai_cache[i]);
spin_lock_init(&sai->sai_cache_lock[i]);
}
atomic_set(&sai->sai_cache_count, 0);
return sai;
}
static inline struct ll_statahead_info *
ll_sai_get(struct ll_statahead_info *sai)
{
atomic_inc(&sai->sai_refcount);
return sai;
}
static void ll_sai_put(struct ll_statahead_info *sai)
{
struct inode *inode = sai->sai_inode;
struct ll_inode_info *lli = ll_i2info(inode);
if (atomic_dec_and_lock(&sai->sai_refcount, &lli->lli_sa_lock)) {
struct ll_sa_entry *entry, *next;
if (unlikely(atomic_read(&sai->sai_refcount) > 0)) {
spin_unlock(&lli->lli_sa_lock);
return;
}
LASSERT(lli->lli_opendir_key == NULL);
LASSERT(thread_is_stopped(&sai->sai_thread));
LASSERT(thread_is_stopped(&sai->sai_agl_thread));
lli->lli_sai = NULL;
lli->lli_opendir_pid = 0;
spin_unlock(&lli->lli_sa_lock);
if (sai->sai_sent > sai->sai_replied)
CDEBUG(D_READA,"statahead for dir "DFID" does not "
"finish: [sent:"LPU64"] [replied:"LPU64"]\n",
PFID(&lli->lli_fid),
sai->sai_sent, sai->sai_replied);
list_for_each_entry_safe(entry, next,
&sai->sai_entries, se_link)
do_sa_entry_fini(sai, entry);
LASSERT(list_empty(&sai->sai_entries));
LASSERT(sa_received_empty(sai));
LASSERT(list_empty(&sai->sai_entries_stated));
LASSERT(atomic_read(&sai->sai_cache_count) == 0);
LASSERT(agl_list_empty(sai));
iput(inode);
OBD_FREE_PTR(sai);
}
}
static void ll_agl_trigger(struct inode *inode, struct ll_statahead_info *sai)
{
struct ll_inode_info *lli = ll_i2info(inode);
__u64 index = lli->lli_agl_index;
int rc;
LASSERT(list_empty(&lli->lli_agl_list));
if (is_omitted_entry(sai, index + 1)) {
lli->lli_agl_index = 0;
iput(inode);
return;
}
rc = down_write_trylock(&lli->lli_glimpse_sem);
if (rc == 0) {
lli->lli_agl_index = 0;
iput(inode);
return;
}
if (lli->lli_glimpse_time != 0 &&
cfs_time_before(cfs_time_shift(-1), lli->lli_glimpse_time)) {
up_write(&lli->lli_glimpse_sem);
lli->lli_agl_index = 0;
iput(inode);
return;
}
CDEBUG(D_READA, "Handling (init) async glimpse: inode = "
DFID", idx = "LPU64"\n", PFID(&lli->lli_fid), index);
cl_agl(inode);
lli->lli_agl_index = 0;
lli->lli_glimpse_time = cfs_time_current();
up_write(&lli->lli_glimpse_sem);
CDEBUG(D_READA, "Handled (init) async glimpse: inode= "
DFID", idx = "LPU64", rc = %d\n",
PFID(&lli->lli_fid), index, rc);
iput(inode);
}
static void ll_post_statahead(struct ll_statahead_info *sai)
{
struct inode *dir = sai->sai_inode;
struct inode *child;
struct ll_inode_info *lli = ll_i2info(dir);
struct ll_sa_entry *entry;
struct md_enqueue_info *minfo;
struct lookup_intent *it;
struct ptlrpc_request *req;
struct mdt_body *body;
int rc = 0;
spin_lock(&lli->lli_sa_lock);
if (unlikely(sa_received_empty(sai))) {
spin_unlock(&lli->lli_sa_lock);
return;
}
entry = sa_first_received_entry(sai);
atomic_inc(&entry->se_refcount);
list_del_init(&entry->se_list);
spin_unlock(&lli->lli_sa_lock);
LASSERT(entry->se_handle != 0);
minfo = entry->se_minfo;
it = &minfo->mi_it;
req = entry->se_req;
body = req_capsule_server_get(&req->rq_pill, &RMF_MDT_BODY);
if (body == NULL)
GOTO(out, rc = -EFAULT);
child = entry->se_inode;
if (child == NULL) {
LASSERT(fid_is_zero(&minfo->mi_data.op_fid2));
if (body->valid & OBD_MD_MDS)
GOTO(out, rc = -EAGAIN);
} else {
if (unlikely(!lu_fid_eq(&minfo->mi_data.op_fid2, &body->fid1))){
entry->se_inode = NULL;
iput(child);
child = NULL;
}
}
it->d.lustre.it_lock_handle = entry->se_handle;
rc = md_revalidate_lock(ll_i2mdexp(dir), it, ll_inode2fid(dir), NULL);
if (rc != 1)
GOTO(out, rc = -EAGAIN);
rc = ll_prep_inode(&child, req, dir->i_sb, it);
if (rc)
GOTO(out, rc);
CDEBUG(D_DLMTRACE, "setting l_data to inode %p (%lu/%u)\n",
child, child->i_ino, child->i_generation);
ll_set_lock_data(ll_i2sbi(dir)->ll_md_exp, child, it, NULL);
entry->se_inode = child;
if (agl_should_run(sai, child))
ll_agl_add(sai, child, entry->se_index);
out:
rc = ll_sa_entry_to_stated(sai, entry,
rc < 0 ? SA_ENTRY_INVA : SA_ENTRY_SUCC);
if (rc == 0 && entry->se_index == sai->sai_index_wait)
wake_up(&sai->sai_waitq);
ll_sa_entry_put(sai, entry);
}
static int ll_statahead_interpret(struct ptlrpc_request *req,
struct md_enqueue_info *minfo, int rc)
{
struct lookup_intent *it = &minfo->mi_it;
struct inode *dir = minfo->mi_dir;
struct ll_inode_info *lli = ll_i2info(dir);
struct ll_statahead_info *sai = NULL;
struct ll_sa_entry *entry;
int wakeup;
if (it_disposition(it, DISP_LOOKUP_NEG))
rc = -ENOENT;
spin_lock(&lli->lli_sa_lock);
if (unlikely(lli->lli_sai == NULL ||
lli->lli_sai->sai_generation != minfo->mi_generation)) {
spin_unlock(&lli->lli_sa_lock);
GOTO(out, rc = -ESTALE);
} else {
sai = ll_sai_get(lli->lli_sai);
if (unlikely(!thread_is_running(&sai->sai_thread))) {
sai->sai_replied++;
spin_unlock(&lli->lli_sa_lock);
GOTO(out, rc = -EBADFD);
}
entry = ll_sa_entry_get_byindex(sai, minfo->mi_cbdata);
if (entry == NULL) {
sai->sai_replied++;
spin_unlock(&lli->lli_sa_lock);
GOTO(out, rc = -EIDRM);
}
if (rc != 0) {
do_sa_entry_to_stated(sai, entry, SA_ENTRY_INVA);
wakeup = (entry->se_index == sai->sai_index_wait);
} else {
entry->se_minfo = minfo;
entry->se_req = ptlrpc_request_addref(req);
entry->se_handle = it->d.lustre.it_lock_handle;
ll_intent_drop_lock(it);
wakeup = sa_received_empty(sai);
list_add_tail(&entry->se_list,
&sai->sai_entries_received);
}
sai->sai_replied++;
spin_unlock(&lli->lli_sa_lock);
ll_sa_entry_put(sai, entry);
if (wakeup)
wake_up(&sai->sai_thread.t_ctl_waitq);
}
out:
if (rc != 0) {
ll_intent_release(it);
iput(dir);
OBD_FREE_PTR(minfo);
}
if (sai != NULL)
ll_sai_put(sai);
return rc;
}
static void sa_args_fini(struct md_enqueue_info *minfo,
struct ldlm_enqueue_info *einfo)
{
LASSERT(minfo && einfo);
iput(minfo->mi_dir);
capa_put(minfo->mi_data.op_capa1);
capa_put(minfo->mi_data.op_capa2);
OBD_FREE_PTR(minfo);
OBD_FREE_PTR(einfo);
}
static int sa_args_init(struct inode *dir, struct inode *child,
struct ll_sa_entry *entry, struct md_enqueue_info **pmi,
struct ldlm_enqueue_info **pei,
struct obd_capa **pcapa)
{
struct qstr *qstr = &entry->se_qstr;
struct ll_inode_info *lli = ll_i2info(dir);
struct md_enqueue_info *minfo;
struct ldlm_enqueue_info *einfo;
struct md_op_data *op_data;
OBD_ALLOC_PTR(einfo);
if (einfo == NULL)
return -ENOMEM;
OBD_ALLOC_PTR(minfo);
if (minfo == NULL) {
OBD_FREE_PTR(einfo);
return -ENOMEM;
}
op_data = ll_prep_md_op_data(&minfo->mi_data, dir, child, qstr->name,
qstr->len, 0, LUSTRE_OPC_ANY, NULL);
if (IS_ERR(op_data)) {
OBD_FREE_PTR(einfo);
OBD_FREE_PTR(minfo);
return PTR_ERR(op_data);
}
minfo->mi_it.it_op = IT_GETATTR;
minfo->mi_dir = igrab(dir);
minfo->mi_cb = ll_statahead_interpret;
minfo->mi_generation = lli->lli_sai->sai_generation;
minfo->mi_cbdata = entry->se_index;
einfo->ei_type = LDLM_IBITS;
einfo->ei_mode = it_to_lock_mode(&minfo->mi_it);
einfo->ei_cb_bl = ll_md_blocking_ast;
einfo->ei_cb_cp = ldlm_completion_ast;
einfo->ei_cb_gl = NULL;
einfo->ei_cbdata = NULL;
*pmi = minfo;
*pei = einfo;
pcapa[0] = op_data->op_capa1;
pcapa[1] = op_data->op_capa2;
return 0;
}
static int do_sa_lookup(struct inode *dir, struct ll_sa_entry *entry)
{
struct md_enqueue_info *minfo;
struct ldlm_enqueue_info *einfo;
struct obd_capa *capas[2];
int rc;
rc = sa_args_init(dir, NULL, entry, &minfo, &einfo, capas);
if (rc)
return rc;
rc = md_intent_getattr_async(ll_i2mdexp(dir), minfo, einfo);
if (!rc) {
capa_put(capas[0]);
capa_put(capas[1]);
} else {
sa_args_fini(minfo, einfo);
}
return rc;
}
static int do_sa_revalidate(struct inode *dir, struct ll_sa_entry *entry,
struct dentry *dentry)
{
struct inode *inode = dentry->d_inode;
struct lookup_intent it = { .it_op = IT_GETATTR,
.d.lustre.it_lock_handle = 0 };
struct md_enqueue_info *minfo;
struct ldlm_enqueue_info *einfo;
struct obd_capa *capas[2];
int rc;
if (unlikely(inode == NULL))
return 1;
if (d_mountpoint(dentry))
return 1;
entry->se_inode = igrab(inode);
rc = md_revalidate_lock(ll_i2mdexp(dir), &it, ll_inode2fid(inode),NULL);
if (rc == 1) {
entry->se_handle = it.d.lustre.it_lock_handle;
ll_intent_release(&it);
return 1;
}
rc = sa_args_init(dir, inode, entry, &minfo, &einfo, capas);
if (rc) {
entry->se_inode = NULL;
iput(inode);
return rc;
}
rc = md_intent_getattr_async(ll_i2mdexp(dir), minfo, einfo);
if (!rc) {
capa_put(capas[0]);
capa_put(capas[1]);
} else {
entry->se_inode = NULL;
iput(inode);
sa_args_fini(minfo, einfo);
}
return rc;
}
static void ll_statahead_one(struct dentry *parent, const char* entry_name,
int entry_name_len)
{
struct inode *dir = parent->d_inode;
struct ll_inode_info *lli = ll_i2info(dir);
struct ll_statahead_info *sai = lli->lli_sai;
struct dentry *dentry = NULL;
struct ll_sa_entry *entry;
int rc;
int rc1;
entry = ll_sa_entry_alloc(sai, sai->sai_index, entry_name,
entry_name_len);
if (IS_ERR(entry))
return;
dentry = d_lookup(parent, &entry->se_qstr);
if (!dentry) {
rc = do_sa_lookup(dir, entry);
} else {
rc = do_sa_revalidate(dir, entry, dentry);
if (rc == 1 && agl_should_run(sai, dentry->d_inode))
ll_agl_add(sai, dentry->d_inode, entry->se_index);
}
if (dentry != NULL)
dput(dentry);
if (rc) {
rc1 = ll_sa_entry_to_stated(sai, entry,
rc < 0 ? SA_ENTRY_INVA : SA_ENTRY_SUCC);
if (rc1 == 0 && entry->se_index == sai->sai_index_wait)
wake_up(&sai->sai_waitq);
} else {
sai->sai_sent++;
}
sai->sai_index++;
ll_sa_entry_put(sai, entry);
}
static int ll_agl_thread(void *arg)
{
struct dentry *parent = (struct dentry *)arg;
struct inode *dir = parent->d_inode;
struct ll_inode_info *plli = ll_i2info(dir);
struct ll_inode_info *clli;
struct ll_sb_info *sbi = ll_i2sbi(dir);
struct ll_statahead_info *sai = ll_sai_get(plli->lli_sai);
struct ptlrpc_thread *thread = &sai->sai_agl_thread;
struct l_wait_info lwi = { 0 };
thread->t_pid = current_pid();
CDEBUG(D_READA, "agl thread started: sai %p, parent %.*s\n",
sai, parent->d_name.len, parent->d_name.name);
atomic_inc(&sbi->ll_agl_total);
spin_lock(&plli->lli_agl_lock);
sai->sai_agl_valid = 1;
if (thread_is_init(thread))
thread_set_flags(thread, SVC_RUNNING);
spin_unlock(&plli->lli_agl_lock);
wake_up(&thread->t_ctl_waitq);
while (1) {
l_wait_event(thread->t_ctl_waitq,
!agl_list_empty(sai) ||
!thread_is_running(thread),
&lwi);
if (!thread_is_running(thread))
break;
spin_lock(&plli->lli_agl_lock);
if (!agl_list_empty(sai)) {
clli = agl_first_entry(sai);
list_del_init(&clli->lli_agl_list);
spin_unlock(&plli->lli_agl_lock);
ll_agl_trigger(&clli->lli_vfs_inode, sai);
} else {
spin_unlock(&plli->lli_agl_lock);
}
}
spin_lock(&plli->lli_agl_lock);
sai->sai_agl_valid = 0;
while (!agl_list_empty(sai)) {
clli = agl_first_entry(sai);
list_del_init(&clli->lli_agl_list);
spin_unlock(&plli->lli_agl_lock);
clli->lli_agl_index = 0;
iput(&clli->lli_vfs_inode);
spin_lock(&plli->lli_agl_lock);
}
thread_set_flags(thread, SVC_STOPPED);
spin_unlock(&plli->lli_agl_lock);
wake_up(&thread->t_ctl_waitq);
ll_sai_put(sai);
CDEBUG(D_READA, "agl thread stopped: sai %p, parent %.*s\n",
sai, parent->d_name.len, parent->d_name.name);
return 0;
}
static void ll_start_agl(struct dentry *parent, struct ll_statahead_info *sai)
{
struct ptlrpc_thread *thread = &sai->sai_agl_thread;
struct l_wait_info lwi = { 0 };
struct ll_inode_info *plli;
struct task_struct *task;
CDEBUG(D_READA, "start agl thread: sai %p, parent %.*s\n",
sai, parent->d_name.len, parent->d_name.name);
plli = ll_i2info(parent->d_inode);
task = kthread_run(ll_agl_thread, parent,
"ll_agl_%u", plli->lli_opendir_pid);
if (IS_ERR(task)) {
CERROR("can't start ll_agl thread, rc: %ld\n", PTR_ERR(task));
thread_set_flags(thread, SVC_STOPPED);
return;
}
l_wait_event(thread->t_ctl_waitq,
thread_is_running(thread) || thread_is_stopped(thread),
&lwi);
}
static int ll_statahead_thread(void *arg)
{
struct dentry *parent = (struct dentry *)arg;
struct inode *dir = parent->d_inode;
struct ll_inode_info *plli = ll_i2info(dir);
struct ll_inode_info *clli;
struct ll_sb_info *sbi = ll_i2sbi(dir);
struct ll_statahead_info *sai = ll_sai_get(plli->lli_sai);
struct ptlrpc_thread *thread = &sai->sai_thread;
struct ptlrpc_thread *agl_thread = &sai->sai_agl_thread;
struct page *page;
__u64 pos = 0;
int first = 0;
int rc = 0;
struct ll_dir_chain chain;
struct l_wait_info lwi = { 0 };
thread->t_pid = current_pid();
CDEBUG(D_READA, "statahead thread starting: sai %p, parent %.*s\n",
sai, parent->d_name.len, parent->d_name.name);
if (sbi->ll_flags & LL_SBI_AGL_ENABLED)
ll_start_agl(parent, sai);
atomic_inc(&sbi->ll_sa_total);
spin_lock(&plli->lli_sa_lock);
if (thread_is_init(thread))
thread_set_flags(thread, SVC_RUNNING);
spin_unlock(&plli->lli_sa_lock);
wake_up(&thread->t_ctl_waitq);
ll_dir_chain_init(&chain);
page = ll_get_dir_page(dir, pos, &chain);
while (1) {
struct lu_dirpage *dp;
struct lu_dirent *ent;
if (IS_ERR(page)) {
rc = PTR_ERR(page);
CDEBUG(D_READA, "error reading dir "DFID" at "LPU64
"/"LPU64": [rc %d] [parent %u]\n",
PFID(ll_inode2fid(dir)), pos, sai->sai_index,
rc, plli->lli_opendir_pid);
GOTO(out, rc);
}
dp = page_address(page);
for (ent = lu_dirent_start(dp); ent != NULL;
ent = lu_dirent_next(ent)) {
__u64 hash;
int namelen;
char *name;
hash = le64_to_cpu(ent->lde_hash);
if (unlikely(hash < pos))
continue;
namelen = le16_to_cpu(ent->lde_namelen);
if (unlikely(namelen == 0))
continue;
name = ent->lde_name;
if (name[0] == '.') {
if (namelen == 1) {
continue;
} else if (name[1] == '.' && namelen == 2) {
continue;
} else if (!sai->sai_ls_all) {
sai->sai_skip_hidden++;
continue;
}
}
if (unlikely(++first == 1))
continue;
keep_it:
l_wait_event(thread->t_ctl_waitq,
!sa_sent_full(sai) ||
!sa_received_empty(sai) ||
!agl_list_empty(sai) ||
!thread_is_running(thread),
&lwi);
interpret_it:
while (!sa_received_empty(sai))
ll_post_statahead(sai);
if (unlikely(!thread_is_running(thread))) {
ll_release_page(page, 0);
GOTO(out, rc = 0);
}
if (sa_sent_full(sai)) {
spin_lock(&plli->lli_agl_lock);
while (!agl_list_empty(sai)) {
clli = agl_first_entry(sai);
list_del_init(&clli->lli_agl_list);
spin_unlock(&plli->lli_agl_lock);
ll_agl_trigger(&clli->lli_vfs_inode,
sai);
if (!sa_received_empty(sai))
goto interpret_it;
if (unlikely(
!thread_is_running(thread))) {
ll_release_page(page, 0);
GOTO(out, rc = 0);
}
if (!sa_sent_full(sai))
goto do_it;
spin_lock(&plli->lli_agl_lock);
}
spin_unlock(&plli->lli_agl_lock);
goto keep_it;
}
do_it:
ll_statahead_one(parent, name, namelen);
}
pos = le64_to_cpu(dp->ldp_hash_end);
if (pos == MDS_DIR_END_OFF) {
ll_release_page(page, 0);
while (1) {
l_wait_event(thread->t_ctl_waitq,
!sa_received_empty(sai) ||
sai->sai_sent == sai->sai_replied||
!thread_is_running(thread),
&lwi);
while (!sa_received_empty(sai))
ll_post_statahead(sai);
if (unlikely(!thread_is_running(thread)))
GOTO(out, rc = 0);
if (sai->sai_sent == sai->sai_replied &&
sa_received_empty(sai))
break;
}
spin_lock(&plli->lli_agl_lock);
while (!agl_list_empty(sai) &&
thread_is_running(thread)) {
clli = agl_first_entry(sai);
list_del_init(&clli->lli_agl_list);
spin_unlock(&plli->lli_agl_lock);
ll_agl_trigger(&clli->lli_vfs_inode, sai);
spin_lock(&plli->lli_agl_lock);
}
spin_unlock(&plli->lli_agl_lock);
GOTO(out, rc = 0);
} else if (1) {
ll_release_page(page, le32_to_cpu(dp->ldp_flags) &
LDF_COLLIDE);
page = ll_get_dir_page(dir, pos, &chain);
} else {
LASSERT(le32_to_cpu(dp->ldp_flags) & LDF_COLLIDE);
ll_release_page(page, 1);
}
}
out:
if (sai->sai_agl_valid) {
spin_lock(&plli->lli_agl_lock);
thread_set_flags(agl_thread, SVC_STOPPING);
spin_unlock(&plli->lli_agl_lock);
wake_up(&agl_thread->t_ctl_waitq);
CDEBUG(D_READA, "stop agl thread: sai %p pid %u\n",
sai, (unsigned int)agl_thread->t_pid);
l_wait_event(agl_thread->t_ctl_waitq,
thread_is_stopped(agl_thread),
&lwi);
} else {
thread_set_flags(&sai->sai_agl_thread, SVC_STOPPED);
}
ll_dir_chain_fini(&chain);
spin_lock(&plli->lli_sa_lock);
if (!sa_received_empty(sai)) {
thread_set_flags(thread, SVC_STOPPING);
spin_unlock(&plli->lli_sa_lock);
while (!sa_received_empty(sai))
ll_post_statahead(sai);
spin_lock(&plli->lli_sa_lock);
}
thread_set_flags(thread, SVC_STOPPED);
spin_unlock(&plli->lli_sa_lock);
wake_up(&sai->sai_waitq);
wake_up(&thread->t_ctl_waitq);
ll_sai_put(sai);
dput(parent);
CDEBUG(D_READA, "statahead thread stopped: sai %p, parent %.*s\n",
sai, parent->d_name.len, parent->d_name.name);
return rc;
}
void ll_stop_statahead(struct inode *dir, void *key)
{
struct ll_inode_info *lli = ll_i2info(dir);
if (unlikely(key == NULL))
return;
spin_lock(&lli->lli_sa_lock);
if (lli->lli_opendir_key != key || lli->lli_opendir_pid == 0) {
spin_unlock(&lli->lli_sa_lock);
return;
}
lli->lli_opendir_key = NULL;
if (lli->lli_sai) {
struct l_wait_info lwi = { 0 };
struct ptlrpc_thread *thread = &lli->lli_sai->sai_thread;
if (!thread_is_stopped(thread)) {
thread_set_flags(thread, SVC_STOPPING);
spin_unlock(&lli->lli_sa_lock);
wake_up(&thread->t_ctl_waitq);
CDEBUG(D_READA, "stop statahead thread: sai %p pid %u\n",
lli->lli_sai, (unsigned int)thread->t_pid);
l_wait_event(thread->t_ctl_waitq,
thread_is_stopped(thread),
&lwi);
} else {
spin_unlock(&lli->lli_sa_lock);
}
ll_sai_put(lli->lli_sai);
} else {
lli->lli_opendir_pid = 0;
spin_unlock(&lli->lli_sa_lock);
}
}
static int is_first_dirent(struct inode *dir, struct dentry *dentry)
{
struct ll_dir_chain chain;
struct qstr *target = &dentry->d_name;
struct page *page;
__u64 pos = 0;
int dot_de;
int rc = LS_NONE_FIRST_DE;
ll_dir_chain_init(&chain);
page = ll_get_dir_page(dir, pos, &chain);
while (1) {
struct lu_dirpage *dp;
struct lu_dirent *ent;
if (IS_ERR(page)) {
struct ll_inode_info *lli = ll_i2info(dir);
rc = PTR_ERR(page);
CERROR("error reading dir "DFID" at "LPU64": "
"[rc %d] [parent %u]\n",
PFID(ll_inode2fid(dir)), pos,
rc, lli->lli_opendir_pid);
break;
}
dp = page_address(page);
for (ent = lu_dirent_start(dp); ent != NULL;
ent = lu_dirent_next(ent)) {
__u64 hash;
int namelen;
char *name;
hash = le64_to_cpu(ent->lde_hash);
if (unlikely(hash < pos))
continue;
namelen = le16_to_cpu(ent->lde_namelen);
if (unlikely(namelen == 0))
continue;
name = ent->lde_name;
if (name[0] == '.') {
if (namelen == 1)
continue;
else if (name[1] == '.' && namelen == 2)
continue;
else
dot_de = 1;
} else {
dot_de = 0;
}
if (dot_de && target->name[0] != '.') {
CDEBUG(D_READA, "%.*s skip hidden file %.*s\n",
target->len, target->name,
namelen, name);
continue;
}
if (target->len != namelen ||
memcmp(target->name, name, namelen) != 0)
rc = LS_NONE_FIRST_DE;
else if (!dot_de)
rc = LS_FIRST_DE;
else
rc = LS_FIRST_DOT_DE;
ll_release_page(page, 0);
GOTO(out, rc);
}
pos = le64_to_cpu(dp->ldp_hash_end);
if (pos == MDS_DIR_END_OFF) {
ll_release_page(page, 0);
break;
} else if (1) {
ll_release_page(page, le32_to_cpu(dp->ldp_flags) &
LDF_COLLIDE);
page = ll_get_dir_page(dir, pos, &chain);
} else {
LASSERT(le32_to_cpu(dp->ldp_flags) & LDF_COLLIDE);
ll_release_page(page, 1);
}
}
out:
ll_dir_chain_fini(&chain);
return rc;
}
static void
ll_sai_unplug(struct ll_statahead_info *sai, struct ll_sa_entry *entry)
{
struct ptlrpc_thread *thread = &sai->sai_thread;
struct ll_sb_info *sbi = ll_i2sbi(sai->sai_inode);
int hit;
if (entry != NULL && entry->se_stat == SA_ENTRY_SUCC)
hit = 1;
else
hit = 0;
ll_sa_entry_fini(sai, entry);
if (hit) {
sai->sai_hit++;
sai->sai_consecutive_miss = 0;
sai->sai_max = min(2 * sai->sai_max, sbi->ll_sa_max);
} else {
struct ll_inode_info *lli = ll_i2info(sai->sai_inode);
sai->sai_miss++;
sai->sai_consecutive_miss++;
if (sa_low_hit(sai) && thread_is_running(thread)) {
atomic_inc(&sbi->ll_sa_wrong);
CDEBUG(D_READA, "Statahead for dir "DFID" hit "
"ratio too low: hit/miss "LPU64"/"LPU64
", sent/replied "LPU64"/"LPU64", stopping "
"statahead thread\n",
PFID(&lli->lli_fid), sai->sai_hit,
sai->sai_miss, sai->sai_sent,
sai->sai_replied);
spin_lock(&lli->lli_sa_lock);
if (!thread_is_stopped(thread))
thread_set_flags(thread, SVC_STOPPING);
spin_unlock(&lli->lli_sa_lock);
}
}
if (!thread_is_stopped(thread))
wake_up(&thread->t_ctl_waitq);
}
int do_statahead_enter(struct inode *dir, struct dentry **dentryp,
int only_unplug)
{
struct ll_inode_info *lli = ll_i2info(dir);
struct ll_statahead_info *sai = lli->lli_sai;
struct dentry *parent;
struct ll_sa_entry *entry;
struct ptlrpc_thread *thread;
struct l_wait_info lwi = { 0 };
int rc = 0;
struct ll_inode_info *plli;
LASSERT(lli->lli_opendir_pid == current_pid());
if (sai) {
thread = &sai->sai_thread;
if (unlikely(thread_is_stopped(thread) &&
list_empty(&sai->sai_entries_stated))) {
ll_stop_statahead(dir, lli->lli_opendir_key);
return -EAGAIN;
}
if ((*dentryp)->d_name.name[0] == '.') {
if (sai->sai_ls_all ||
sai->sai_miss_hidden >= sai->sai_skip_hidden) {
} else {
if (!sai->sai_ls_all)
sai->sai_ls_all = 1;
sai->sai_miss_hidden++;
return -EAGAIN;
}
}
entry = ll_sa_entry_get_byname(sai, &(*dentryp)->d_name);
if (entry == NULL || only_unplug) {
ll_sai_unplug(sai, entry);
return entry ? 1 : -EAGAIN;
}
if (!ll_sa_entry_stated(entry)) {
sai->sai_index_wait = entry->se_index;
lwi = LWI_TIMEOUT_INTR(cfs_time_seconds(30), NULL,
LWI_ON_SIGNAL_NOOP, NULL);
rc = l_wait_event(sai->sai_waitq,
ll_sa_entry_stated(entry) ||
thread_is_stopped(thread),
&lwi);
if (rc < 0) {
ll_sai_unplug(sai, entry);
return -EAGAIN;
}
}
if (entry->se_stat == SA_ENTRY_SUCC &&
entry->se_inode != NULL) {
struct inode *inode = entry->se_inode;
struct lookup_intent it = { .it_op = IT_GETATTR,
.d.lustre.it_lock_handle =
entry->se_handle };
__u64 bits;
rc = md_revalidate_lock(ll_i2mdexp(dir), &it,
ll_inode2fid(inode), &bits);
if (rc == 1) {
if ((*dentryp)->d_inode == NULL) {
struct dentry *alias;
alias = ll_splice_alias(inode,
*dentryp);
if (IS_ERR(alias)) {
ll_sai_unplug(sai, entry);
return PTR_ERR(alias);
}
*dentryp = alias;
} else if ((*dentryp)->d_inode != inode) {
CDEBUG(D_READA,
"stale dentry %.*s inode %lu/%u, "
"statahead inode %lu/%u\n",
(*dentryp)->d_name.len,
(*dentryp)->d_name.name,
(*dentryp)->d_inode->i_ino,
(*dentryp)->d_inode->i_generation,
inode->i_ino,
inode->i_generation);
ll_sai_unplug(sai, entry);
return -ESTALE;
} else {
iput(inode);
}
entry->se_inode = NULL;
if ((bits & MDS_INODELOCK_LOOKUP) &&
d_lustre_invalid(*dentryp))
d_lustre_revalidate(*dentryp);
ll_intent_release(&it);
}
}
ll_sai_unplug(sai, entry);
return rc;
}
rc = is_first_dirent(dir, *dentryp);
if (rc == LS_NONE_FIRST_DE)
GOTO(out, rc = -EAGAIN);
sai = ll_sai_alloc();
if (sai == NULL)
GOTO(out, rc = -ENOMEM);
sai->sai_ls_all = (rc == LS_FIRST_DOT_DE);
sai->sai_inode = igrab(dir);
if (unlikely(sai->sai_inode == NULL)) {
CWARN("Do not start stat ahead on dying inode "DFID"\n",
PFID(&lli->lli_fid));
GOTO(out, rc = -ESTALE);
}
parent = dget((*dentryp)->d_parent);
if (unlikely(sai->sai_inode != parent->d_inode)) {
struct ll_inode_info *nlli = ll_i2info(parent->d_inode);
CWARN("Race condition, someone changed %.*s just now: "
"old parent "DFID", new parent "DFID"\n",
(*dentryp)->d_name.len, (*dentryp)->d_name.name,
PFID(&lli->lli_fid), PFID(&nlli->lli_fid));
dput(parent);
iput(sai->sai_inode);
GOTO(out, rc = -EAGAIN);
}
CDEBUG(D_READA, "start statahead thread: sai %p, parent %.*s\n",
sai, parent->d_name.len, parent->d_name.name);
ll_sai_get(sai);
lli->lli_sai = sai;
plli = ll_i2info(parent->d_inode);
rc = PTR_ERR(kthread_run(ll_statahead_thread, parent,
"ll_sa_%u", plli->lli_opendir_pid));
thread = &sai->sai_thread;
if (IS_ERR_VALUE(rc)) {
CERROR("can't start ll_sa thread, rc: %d\n", rc);
dput(parent);
lli->lli_opendir_key = NULL;
thread_set_flags(thread, SVC_STOPPED);
thread_set_flags(&sai->sai_agl_thread, SVC_STOPPED);
ll_sai_put(sai);
ll_sai_put(sai);
LASSERT(lli->lli_sai == NULL);
return -EAGAIN;
}
l_wait_event(thread->t_ctl_waitq,
thread_is_running(thread) || thread_is_stopped(thread),
&lwi);
ll_sai_put(sai);
return -EAGAIN;
out:
if (sai != NULL)
OBD_FREE_PTR(sai);
spin_lock(&lli->lli_sa_lock);
lli->lli_opendir_key = NULL;
lli->lli_opendir_pid = 0;
spin_unlock(&lli->lli_sa_lock);
return rc;
}
