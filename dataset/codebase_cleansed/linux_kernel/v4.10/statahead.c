static inline int sa_ready(struct sa_entry *entry)
{
smp_rmb();
return (entry->se_state != SA_ENTRY_INIT);
}
static inline int sa_hash(int val)
{
return val & LL_SA_CACHE_MASK;
}
static inline void
sa_rehash(struct ll_statahead_info *sai, struct sa_entry *entry)
{
int i = sa_hash(entry->se_qstr.hash);
spin_lock(&sai->sai_cache_lock[i]);
list_add_tail(&entry->se_hash, &sai->sai_cache[i]);
spin_unlock(&sai->sai_cache_lock[i]);
}
static inline void
sa_unhash(struct ll_statahead_info *sai, struct sa_entry *entry)
{
int i = sa_hash(entry->se_qstr.hash);
spin_lock(&sai->sai_cache_lock[i]);
list_del_init(&entry->se_hash);
spin_unlock(&sai->sai_cache_lock[i]);
}
static inline int agl_should_run(struct ll_statahead_info *sai,
struct inode *inode)
{
return (inode && S_ISREG(inode->i_mode) && sai->sai_agl_valid);
}
static inline int sa_sent_full(struct ll_statahead_info *sai)
{
return atomic_read(&sai->sai_cache_count) >= sai->sai_max;
}
static inline int sa_has_callback(struct ll_statahead_info *sai)
{
return !list_empty(&sai->sai_interim_entries);
}
static inline int agl_list_empty(struct ll_statahead_info *sai)
{
return list_empty(&sai->sai_agls);
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
static struct sa_entry *
sa_alloc(struct dentry *parent, struct ll_statahead_info *sai, __u64 index,
const char *name, int len)
{
struct ll_inode_info *lli;
struct sa_entry *entry;
int entry_size;
char *dname;
entry_size = sizeof(struct sa_entry) + (len & ~3) + 4;
entry = kzalloc(entry_size, GFP_NOFS);
if (unlikely(!entry))
return ERR_PTR(-ENOMEM);
CDEBUG(D_READA, "alloc sa entry %.*s(%p) index %llu\n",
len, name, entry, index);
entry->se_index = index;
entry->se_state = SA_ENTRY_INIT;
entry->se_size = entry_size;
dname = (char *)entry + sizeof(struct sa_entry);
memcpy(dname, name, len);
dname[len] = 0;
entry->se_qstr.hash = full_name_hash(parent, name, len);
entry->se_qstr.len = len;
entry->se_qstr.name = dname;
lli = ll_i2info(sai->sai_dentry->d_inode);
spin_lock(&lli->lli_sa_lock);
INIT_LIST_HEAD(&entry->se_list);
sa_rehash(sai, entry);
spin_unlock(&lli->lli_sa_lock);
atomic_inc(&sai->sai_cache_count);
return entry;
}
static void sa_free(struct ll_statahead_info *sai, struct sa_entry *entry)
{
CDEBUG(D_READA, "free sa entry %.*s(%p) index %llu\n",
entry->se_qstr.len, entry->se_qstr.name, entry,
entry->se_index);
LASSERT(list_empty(&entry->se_list));
LASSERT(list_empty(&entry->se_hash));
kfree(entry);
atomic_dec(&sai->sai_cache_count);
}
static struct sa_entry *
sa_get(struct ll_statahead_info *sai, const struct qstr *qstr)
{
struct sa_entry *entry;
int i = sa_hash(qstr->hash);
list_for_each_entry(entry, &sai->sai_cache[i], se_hash) {
if (entry->se_qstr.hash == qstr->hash &&
entry->se_qstr.len == qstr->len &&
memcmp(entry->se_qstr.name, qstr->name, qstr->len) == 0)
return entry;
}
return NULL;
}
static inline void
sa_kill(struct ll_statahead_info *sai, struct sa_entry *entry)
{
struct ll_inode_info *lli = ll_i2info(sai->sai_dentry->d_inode);
LASSERT(!list_empty(&entry->se_hash));
LASSERT(!list_empty(&entry->se_list));
LASSERT(sa_ready(entry));
sa_unhash(sai, entry);
spin_lock(&lli->lli_sa_lock);
list_del_init(&entry->se_list);
spin_unlock(&lli->lli_sa_lock);
if (entry->se_inode)
iput(entry->se_inode);
sa_free(sai, entry);
}
static void
sa_put(struct ll_statahead_info *sai, struct sa_entry *entry)
{
struct sa_entry *tmp, *next;
if (entry && entry->se_state == SA_ENTRY_SUCC) {
struct ll_sb_info *sbi = ll_i2sbi(sai->sai_dentry->d_inode);
sai->sai_hit++;
sai->sai_consecutive_miss = 0;
sai->sai_max = min(2 * sai->sai_max, sbi->ll_sa_max);
} else {
sai->sai_miss++;
sai->sai_consecutive_miss++;
}
if (entry)
sa_kill(sai, entry);
list_for_each_entry_safe(tmp, next, &sai->sai_entries, se_list) {
if (!is_omitted_entry(sai, tmp->se_index))
break;
sa_kill(sai, tmp);
}
wake_up(&sai->sai_thread.t_ctl_waitq);
}
static bool
__sa_make_ready(struct ll_statahead_info *sai, struct sa_entry *entry, int ret)
{
struct list_head *pos = &sai->sai_entries;
__u64 index = entry->se_index;
struct sa_entry *se;
LASSERT(!sa_ready(entry));
LASSERT(list_empty(&entry->se_list));
list_for_each_entry_reverse(se, &sai->sai_entries, se_list) {
if (se->se_index < entry->se_index) {
pos = &se->se_list;
break;
}
}
list_add(&entry->se_list, pos);
entry->se_state = ret < 0 ? SA_ENTRY_INVA : SA_ENTRY_SUCC;
return (index == sai->sai_index_wait);
}
static void
sa_make_ready(struct ll_statahead_info *sai, struct sa_entry *entry, int ret)
{
struct ll_inode_info *lli = ll_i2info(sai->sai_dentry->d_inode);
struct md_enqueue_info *minfo = entry->se_minfo;
struct ptlrpc_request *req = entry->se_req;
bool wakeup;
if (minfo) {
entry->se_minfo = NULL;
ll_intent_release(&minfo->mi_it);
iput(minfo->mi_dir);
kfree(minfo);
}
if (req) {
entry->se_req = NULL;
ptlrpc_req_finished(req);
}
spin_lock(&lli->lli_sa_lock);
wakeup = __sa_make_ready(sai, entry, ret);
spin_unlock(&lli->lli_sa_lock);
if (wakeup)
wake_up(&sai->sai_waitq);
}
static void ll_agl_add(struct ll_statahead_info *sai,
struct inode *inode, int index)
{
struct ll_inode_info *child = ll_i2info(inode);
struct ll_inode_info *parent = ll_i2info(sai->sai_dentry->d_inode);
int added = 0;
spin_lock(&child->lli_agl_lock);
if (child->lli_agl_index == 0) {
child->lli_agl_index = index;
spin_unlock(&child->lli_agl_lock);
LASSERT(list_empty(&child->lli_agl_list));
igrab(inode);
spin_lock(&parent->lli_agl_lock);
if (list_empty(&sai->sai_agls))
added = 1;
list_add_tail(&child->lli_agl_list, &sai->sai_agls);
spin_unlock(&parent->lli_agl_lock);
} else {
spin_unlock(&child->lli_agl_lock);
}
if (added > 0)
wake_up(&sai->sai_agl_thread.t_ctl_waitq);
}
static struct ll_statahead_info *ll_sai_alloc(struct dentry *dentry)
{
struct ll_inode_info *lli = ll_i2info(dentry->d_inode);
struct ll_statahead_info *sai;
int i;
sai = kzalloc(sizeof(*sai), GFP_NOFS);
if (!sai)
return NULL;
sai->sai_dentry = dget(dentry);
atomic_set(&sai->sai_refcount, 1);
sai->sai_max = LL_SA_RPC_MIN;
sai->sai_index = 1;
init_waitqueue_head(&sai->sai_waitq);
init_waitqueue_head(&sai->sai_thread.t_ctl_waitq);
init_waitqueue_head(&sai->sai_agl_thread.t_ctl_waitq);
INIT_LIST_HEAD(&sai->sai_interim_entries);
INIT_LIST_HEAD(&sai->sai_entries);
INIT_LIST_HEAD(&sai->sai_agls);
for (i = 0; i < LL_SA_CACHE_SIZE; i++) {
INIT_LIST_HEAD(&sai->sai_cache[i]);
spin_lock_init(&sai->sai_cache_lock[i]);
}
atomic_set(&sai->sai_cache_count, 0);
spin_lock(&sai_generation_lock);
lli->lli_sa_generation = ++sai_generation;
if (unlikely(!sai_generation))
lli->lli_sa_generation = ++sai_generation;
spin_unlock(&sai_generation_lock);
return sai;
}
static inline void ll_sai_free(struct ll_statahead_info *sai)
{
LASSERT(sai->sai_dentry);
dput(sai->sai_dentry);
kfree(sai);
}
static inline struct ll_statahead_info *ll_sai_get(struct inode *dir)
{
struct ll_inode_info *lli = ll_i2info(dir);
struct ll_statahead_info *sai = NULL;
spin_lock(&lli->lli_sa_lock);
sai = lli->lli_sai;
if (sai)
atomic_inc(&sai->sai_refcount);
spin_unlock(&lli->lli_sa_lock);
return sai;
}
static void ll_sai_put(struct ll_statahead_info *sai)
{
struct ll_inode_info *lli = ll_i2info(sai->sai_dentry->d_inode);
if (atomic_dec_and_lock(&sai->sai_refcount, &lli->lli_sa_lock)) {
struct ll_sb_info *sbi = ll_i2sbi(sai->sai_dentry->d_inode);
struct sa_entry *entry, *next;
lli->lli_sai = NULL;
spin_unlock(&lli->lli_sa_lock);
LASSERT(thread_is_stopped(&sai->sai_thread));
LASSERT(thread_is_stopped(&sai->sai_agl_thread));
LASSERT(sai->sai_sent == sai->sai_replied);
LASSERT(!sa_has_callback(sai));
list_for_each_entry_safe(entry, next, &sai->sai_entries,
se_list)
sa_kill(sai, entry);
LASSERT(atomic_read(&sai->sai_cache_count) == 0);
LASSERT(list_empty(&sai->sai_agls));
ll_sai_free(sai);
atomic_dec(&sbi->ll_sa_running);
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
time_before(cfs_time_shift(-1), lli->lli_glimpse_time)) {
up_write(&lli->lli_glimpse_sem);
lli->lli_agl_index = 0;
iput(inode);
return;
}
CDEBUG(D_READA, "Handling (init) async glimpse: inode = "
DFID", idx = %llu\n", PFID(&lli->lli_fid), index);
cl_agl(inode);
lli->lli_agl_index = 0;
lli->lli_glimpse_time = cfs_time_current();
up_write(&lli->lli_glimpse_sem);
CDEBUG(D_READA, "Handled (init) async glimpse: inode= "
DFID", idx = %llu, rc = %d\n",
PFID(&lli->lli_fid), index, rc);
iput(inode);
}
static void sa_instantiate(struct ll_statahead_info *sai,
struct sa_entry *entry)
{
struct inode *dir = sai->sai_dentry->d_inode;
struct inode *child;
struct md_enqueue_info *minfo;
struct lookup_intent *it;
struct ptlrpc_request *req;
struct mdt_body *body;
int rc = 0;
LASSERT(entry->se_handle != 0);
minfo = entry->se_minfo;
it = &minfo->mi_it;
req = entry->se_req;
body = req_capsule_server_get(&req->rq_pill, &RMF_MDT_BODY);
if (!body) {
rc = -EFAULT;
goto out;
}
child = entry->se_inode;
if (!child) {
LASSERT(fid_is_zero(&minfo->mi_data.op_fid2));
if (body->mbo_valid & OBD_MD_MDS) {
rc = -EAGAIN;
goto out;
}
} else {
if (unlikely(!lu_fid_eq(&minfo->mi_data.op_fid2, &body->mbo_fid1))) {
entry->se_inode = NULL;
iput(child);
child = NULL;
}
}
it->it_lock_handle = entry->se_handle;
rc = md_revalidate_lock(ll_i2mdexp(dir), it, ll_inode2fid(dir), NULL);
if (rc != 1) {
rc = -EAGAIN;
goto out;
}
rc = ll_prep_inode(&child, req, dir->i_sb, it);
if (rc)
goto out;
CDEBUG(D_READA, "%s: setting %.*s" DFID " l_data to inode %p\n",
ll_get_fsname(child->i_sb, NULL, 0),
entry->se_qstr.len, entry->se_qstr.name,
PFID(ll_inode2fid(child)), child);
ll_set_lock_data(ll_i2sbi(dir)->ll_md_exp, child, it, NULL);
entry->se_inode = child;
if (agl_should_run(sai, child))
ll_agl_add(sai, child, entry->se_index);
out:
sa_make_ready(sai, entry, rc);
}
static void sa_handle_callback(struct ll_statahead_info *sai)
{
struct ll_inode_info *lli;
lli = ll_i2info(sai->sai_dentry->d_inode);
while (sa_has_callback(sai)) {
struct sa_entry *entry;
spin_lock(&lli->lli_sa_lock);
if (unlikely(!sa_has_callback(sai))) {
spin_unlock(&lli->lli_sa_lock);
break;
}
entry = list_entry(sai->sai_interim_entries.next,
struct sa_entry, se_list);
list_del_init(&entry->se_list);
spin_unlock(&lli->lli_sa_lock);
sa_instantiate(sai, entry);
}
}
static int ll_statahead_interpret(struct ptlrpc_request *req,
struct md_enqueue_info *minfo, int rc)
{
struct lookup_intent *it = &minfo->mi_it;
struct inode *dir = minfo->mi_dir;
struct ll_inode_info *lli = ll_i2info(dir);
struct ll_statahead_info *sai = lli->lli_sai;
struct sa_entry *entry = (struct sa_entry *)minfo->mi_cbdata;
wait_queue_head_t *waitq = NULL;
__u64 handle = 0;
if (it_disposition(it, DISP_LOOKUP_NEG))
rc = -ENOENT;
LASSERT(sai);
LASSERT(!thread_is_stopped(&sai->sai_thread));
LASSERT(entry);
CDEBUG(D_READA, "sa_entry %.*s rc %d\n",
entry->se_qstr.len, entry->se_qstr.name, rc);
if (rc) {
ll_intent_release(it);
iput(dir);
kfree(minfo);
} else {
handle = it->it_lock_handle;
ll_intent_drop_lock(it);
}
spin_lock(&lli->lli_sa_lock);
if (rc) {
if (__sa_make_ready(sai, entry, rc))
waitq = &sai->sai_waitq;
} else {
entry->se_minfo = minfo;
entry->se_req = ptlrpc_request_addref(req);
entry->se_handle = handle;
if (!sa_has_callback(sai))
waitq = &sai->sai_thread.t_ctl_waitq;
list_add_tail(&entry->se_list, &sai->sai_interim_entries);
}
sai->sai_replied++;
if (waitq)
wake_up(waitq);
spin_unlock(&lli->lli_sa_lock);
return rc;
}
static void sa_fini_data(struct md_enqueue_info *minfo,
struct ldlm_enqueue_info *einfo)
{
LASSERT(minfo && einfo);
iput(minfo->mi_dir);
kfree(minfo);
kfree(einfo);
}
static int sa_prep_data(struct inode *dir, struct inode *child,
struct sa_entry *entry, struct md_enqueue_info **pmi,
struct ldlm_enqueue_info **pei)
{
const struct qstr *qstr = &entry->se_qstr;
struct md_enqueue_info *minfo;
struct ldlm_enqueue_info *einfo;
struct md_op_data *op_data;
einfo = kzalloc(sizeof(*einfo), GFP_NOFS);
if (!einfo)
return -ENOMEM;
minfo = kzalloc(sizeof(*minfo), GFP_NOFS);
if (!minfo) {
kfree(einfo);
return -ENOMEM;
}
op_data = ll_prep_md_op_data(&minfo->mi_data, dir, child, qstr->name,
qstr->len, 0, LUSTRE_OPC_ANY, NULL);
if (IS_ERR(op_data)) {
kfree(einfo);
kfree(minfo);
return PTR_ERR(op_data);
}
minfo->mi_it.it_op = IT_GETATTR;
minfo->mi_dir = igrab(dir);
minfo->mi_cb = ll_statahead_interpret;
minfo->mi_cbdata = entry;
einfo->ei_type = LDLM_IBITS;
einfo->ei_mode = it_to_lock_mode(&minfo->mi_it);
einfo->ei_cb_bl = ll_md_blocking_ast;
einfo->ei_cb_cp = ldlm_completion_ast;
einfo->ei_cb_gl = NULL;
einfo->ei_cbdata = NULL;
*pmi = minfo;
*pei = einfo;
return 0;
}
static int sa_lookup(struct inode *dir, struct sa_entry *entry)
{
struct md_enqueue_info *minfo;
struct ldlm_enqueue_info *einfo;
int rc;
rc = sa_prep_data(dir, NULL, entry, &minfo, &einfo);
if (rc)
return rc;
rc = md_intent_getattr_async(ll_i2mdexp(dir), minfo, einfo);
if (rc)
sa_fini_data(minfo, einfo);
return rc;
}
static int sa_revalidate(struct inode *dir, struct sa_entry *entry,
struct dentry *dentry)
{
struct inode *inode = d_inode(dentry);
struct lookup_intent it = { .it_op = IT_GETATTR,
.it_lock_handle = 0 };
struct md_enqueue_info *minfo;
struct ldlm_enqueue_info *einfo;
int rc;
if (unlikely(!inode))
return 1;
if (d_mountpoint(dentry))
return 1;
entry->se_inode = igrab(inode);
rc = md_revalidate_lock(ll_i2mdexp(dir), &it, ll_inode2fid(inode),
NULL);
if (rc == 1) {
entry->se_handle = it.it_lock_handle;
ll_intent_release(&it);
return 1;
}
rc = sa_prep_data(dir, inode, entry, &minfo, &einfo);
if (rc) {
entry->se_inode = NULL;
iput(inode);
return rc;
}
rc = md_intent_getattr_async(ll_i2mdexp(dir), minfo, einfo);
if (rc) {
entry->se_inode = NULL;
iput(inode);
sa_fini_data(minfo, einfo);
}
return rc;
}
static void sa_statahead(struct dentry *parent, const char *name, int len)
{
struct inode *dir = d_inode(parent);
struct ll_inode_info *lli = ll_i2info(dir);
struct ll_statahead_info *sai = lli->lli_sai;
struct dentry *dentry = NULL;
struct sa_entry *entry;
int rc;
entry = sa_alloc(parent, sai, sai->sai_index, name, len);
if (IS_ERR(entry))
return;
dentry = d_lookup(parent, &entry->se_qstr);
if (!dentry) {
rc = sa_lookup(dir, entry);
} else {
rc = sa_revalidate(dir, entry, dentry);
if (rc == 1 && agl_should_run(sai, d_inode(dentry)))
ll_agl_add(sai, d_inode(dentry), entry->se_index);
}
if (dentry)
dput(dentry);
if (rc)
sa_make_ready(sai, entry, rc);
else
sai->sai_sent++;
sai->sai_index++;
}
static int ll_agl_thread(void *arg)
{
struct dentry *parent = arg;
struct inode *dir = d_inode(parent);
struct ll_inode_info *plli = ll_i2info(dir);
struct ll_inode_info *clli;
struct ll_sb_info *sbi = ll_i2sbi(dir);
struct ll_statahead_info *sai;
struct ptlrpc_thread *thread;
struct l_wait_info lwi = { 0 };
sai = ll_sai_get(dir);
thread = &sai->sai_agl_thread;
thread->t_pid = current_pid();
CDEBUG(D_READA, "agl thread started: sai %p, parent %pd\n",
sai, parent);
atomic_inc(&sbi->ll_agl_total);
spin_lock(&plli->lli_agl_lock);
sai->sai_agl_valid = 1;
if (thread_is_init(thread))
thread_set_flags(thread, SVC_RUNNING);
spin_unlock(&plli->lli_agl_lock);
wake_up(&thread->t_ctl_waitq);
while (1) {
l_wait_event(thread->t_ctl_waitq,
!list_empty(&sai->sai_agls) ||
!thread_is_running(thread),
&lwi);
if (!thread_is_running(thread))
break;
spin_lock(&plli->lli_agl_lock);
if (!list_empty(&sai->sai_agls)) {
clli = list_entry(sai->sai_agls.next,
struct ll_inode_info, lli_agl_list);
list_del_init(&clli->lli_agl_list);
spin_unlock(&plli->lli_agl_lock);
ll_agl_trigger(&clli->lli_vfs_inode, sai);
} else {
spin_unlock(&plli->lli_agl_lock);
}
}
spin_lock(&plli->lli_agl_lock);
sai->sai_agl_valid = 0;
while (!list_empty(&sai->sai_agls)) {
clli = list_entry(sai->sai_agls.next,
struct ll_inode_info, lli_agl_list);
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
CDEBUG(D_READA, "agl thread stopped: sai %p, parent %pd\n",
sai, parent);
return 0;
}
static void ll_start_agl(struct dentry *parent, struct ll_statahead_info *sai)
{
struct ptlrpc_thread *thread = &sai->sai_agl_thread;
struct l_wait_info lwi = { 0 };
struct ll_inode_info *plli;
struct task_struct *task;
CDEBUG(D_READA, "start agl thread: sai %p, parent %pd\n",
sai, parent);
plli = ll_i2info(d_inode(parent));
task = kthread_run(ll_agl_thread, parent, "ll_agl_%u",
plli->lli_opendir_pid);
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
struct dentry *parent = arg;
struct inode *dir = d_inode(parent);
struct ll_inode_info *lli = ll_i2info(dir);
struct ll_sb_info *sbi = ll_i2sbi(dir);
struct ll_statahead_info *sai;
struct ptlrpc_thread *sa_thread;
struct ptlrpc_thread *agl_thread;
struct page *page = NULL;
__u64 pos = 0;
int first = 0;
int rc = 0;
struct md_op_data *op_data;
struct l_wait_info lwi = { 0 };
sai = ll_sai_get(dir);
sa_thread = &sai->sai_thread;
agl_thread = &sai->sai_agl_thread;
sa_thread->t_pid = current_pid();
CDEBUG(D_READA, "statahead thread starting: sai %p, parent %pd\n",
sai, parent);
op_data = ll_prep_md_op_data(NULL, dir, dir, NULL, 0, 0,
LUSTRE_OPC_ANY, dir);
if (IS_ERR(op_data)) {
rc = PTR_ERR(op_data);
goto out;
}
op_data->op_max_pages = ll_i2sbi(dir)->ll_md_brw_pages;
if (sbi->ll_flags & LL_SBI_AGL_ENABLED)
ll_start_agl(parent, sai);
atomic_inc(&sbi->ll_sa_total);
spin_lock(&lli->lli_sa_lock);
if (thread_is_init(sa_thread))
thread_set_flags(sa_thread, SVC_RUNNING);
spin_unlock(&lli->lli_sa_lock);
wake_up(&sa_thread->t_ctl_waitq);
while (pos != MDS_DIR_END_OFF && thread_is_running(sa_thread)) {
struct lu_dirpage *dp;
struct lu_dirent *ent;
sai->sai_in_readpage = 1;
page = ll_get_dir_page(dir, op_data, pos);
sai->sai_in_readpage = 0;
if (IS_ERR(page)) {
rc = PTR_ERR(page);
CDEBUG(D_READA, "error reading dir "DFID" at %llu/%llu: opendir_pid = %u: rc = %d\n",
PFID(ll_inode2fid(dir)), pos, sai->sai_index,
lli->lli_opendir_pid, rc);
break;
}
dp = page_address(page);
for (ent = lu_dirent_start(dp);
ent && thread_is_running(sa_thread) && !sa_low_hit(sai);
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
do {
l_wait_event(sa_thread->t_ctl_waitq,
!sa_sent_full(sai) ||
sa_has_callback(sai) ||
!list_empty(&sai->sai_agls) ||
!thread_is_running(sa_thread),
&lwi);
sa_handle_callback(sai);
spin_lock(&lli->lli_agl_lock);
while (sa_sent_full(sai) &&
!agl_list_empty(sai)) {
struct ll_inode_info *clli;
clli = list_entry(sai->sai_agls.next,
struct ll_inode_info, lli_agl_list);
list_del_init(&clli->lli_agl_list);
spin_unlock(&lli->lli_agl_lock);
ll_agl_trigger(&clli->lli_vfs_inode,
sai);
spin_lock(&lli->lli_agl_lock);
}
spin_unlock(&lli->lli_agl_lock);
} while (sa_sent_full(sai) &&
thread_is_running(sa_thread));
sa_statahead(parent, name, namelen);
}
pos = le64_to_cpu(dp->ldp_hash_end);
ll_release_page(dir, page,
le32_to_cpu(dp->ldp_flags) & LDF_COLLIDE);
if (sa_low_hit(sai)) {
rc = -EFAULT;
atomic_inc(&sbi->ll_sa_wrong);
CDEBUG(D_READA, "Statahead for dir "DFID" hit ratio too low: hit/miss %llu/%llu, sent/replied %llu/%llu, stopping statahead thread: pid %d\n",
PFID(&lli->lli_fid), sai->sai_hit,
sai->sai_miss, sai->sai_sent,
sai->sai_replied, current_pid());
break;
}
}
ll_finish_md_op_data(op_data);
if (rc < 0) {
spin_lock(&lli->lli_sa_lock);
thread_set_flags(sa_thread, SVC_STOPPING);
lli->lli_sa_enabled = 0;
spin_unlock(&lli->lli_sa_lock);
}
while (thread_is_running(sa_thread)) {
l_wait_event(sa_thread->t_ctl_waitq,
sa_has_callback(sai) ||
!agl_list_empty(sai) ||
!thread_is_running(sa_thread),
&lwi);
sa_handle_callback(sai);
}
out:
if (sai->sai_agl_valid) {
spin_lock(&lli->lli_agl_lock);
thread_set_flags(agl_thread, SVC_STOPPING);
spin_unlock(&lli->lli_agl_lock);
wake_up(&agl_thread->t_ctl_waitq);
CDEBUG(D_READA, "stop agl thread: sai %p pid %u\n",
sai, (unsigned int)agl_thread->t_pid);
l_wait_event(agl_thread->t_ctl_waitq,
thread_is_stopped(agl_thread),
&lwi);
} else {
thread_set_flags(agl_thread, SVC_STOPPED);
}
while (sai->sai_sent != sai->sai_replied) {
lwi = LWI_TIMEOUT(msecs_to_jiffies(MSEC_PER_SEC >> 3),
NULL, NULL);
l_wait_event(sa_thread->t_ctl_waitq,
sai->sai_sent == sai->sai_replied, &lwi);
}
sa_handle_callback(sai);
spin_lock(&lli->lli_sa_lock);
thread_set_flags(sa_thread, SVC_STOPPED);
spin_unlock(&lli->lli_sa_lock);
CDEBUG(D_READA, "statahead thread stopped: sai %p, parent %pd\n",
sai, parent);
wake_up(&sai->sai_waitq);
wake_up(&sa_thread->t_ctl_waitq);
ll_sai_put(sai);
return rc;
}
void ll_authorize_statahead(struct inode *dir, void *key)
{
struct ll_inode_info *lli = ll_i2info(dir);
spin_lock(&lli->lli_sa_lock);
if (!lli->lli_opendir_key && !lli->lli_sai) {
LASSERT(!lli->lli_opendir_pid);
lli->lli_opendir_key = key;
lli->lli_opendir_pid = current_pid();
lli->lli_sa_enabled = 1;
}
spin_unlock(&lli->lli_sa_lock);
}
void ll_deauthorize_statahead(struct inode *dir, void *key)
{
struct ll_inode_info *lli = ll_i2info(dir);
struct ll_statahead_info *sai;
LASSERT(lli->lli_opendir_key == key);
LASSERT(lli->lli_opendir_pid);
CDEBUG(D_READA, "deauthorize statahead for "DFID"\n",
PFID(&lli->lli_fid));
spin_lock(&lli->lli_sa_lock);
lli->lli_opendir_key = NULL;
lli->lli_opendir_pid = 0;
lli->lli_sa_enabled = 0;
sai = lli->lli_sai;
if (sai && thread_is_running(&sai->sai_thread)) {
thread_set_flags(&sai->sai_thread, SVC_STOPPING);
wake_up(&sai->sai_thread.t_ctl_waitq);
}
spin_unlock(&lli->lli_sa_lock);
}
static int is_first_dirent(struct inode *dir, struct dentry *dentry)
{
const struct qstr *target = &dentry->d_name;
struct md_op_data *op_data;
struct page *page;
__u64 pos = 0;
int dot_de;
int rc = LS_NOT_FIRST_DE;
op_data = ll_prep_md_op_data(NULL, dir, dir, NULL, 0, 0,
LUSTRE_OPC_ANY, dir);
if (IS_ERR(op_data))
return PTR_ERR(op_data);
op_data->op_max_pages = ll_i2sbi(dir)->ll_md_brw_pages;
page = ll_get_dir_page(dir, op_data, pos);
while (1) {
struct lu_dirpage *dp;
struct lu_dirent *ent;
if (IS_ERR(page)) {
struct ll_inode_info *lli = ll_i2info(dir);
rc = PTR_ERR(page);
CERROR("%s: error reading dir "DFID" at %llu: opendir_pid = %u : rc = %d\n",
ll_get_fsname(dir->i_sb, NULL, 0),
PFID(ll_inode2fid(dir)), pos,
lli->lli_opendir_pid, rc);
break;
}
dp = page_address(page);
for (ent = lu_dirent_start(dp); ent;
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
rc = LS_NOT_FIRST_DE;
else if (!dot_de)
rc = LS_FIRST_DE;
else
rc = LS_FIRST_DOT_DE;
ll_release_page(dir, page, false);
goto out;
}
pos = le64_to_cpu(dp->ldp_hash_end);
if (pos == MDS_DIR_END_OFF) {
ll_release_page(dir, page, false);
goto out;
} else {
ll_release_page(dir, page,
le32_to_cpu(dp->ldp_flags) &
LDF_COLLIDE);
page = ll_get_dir_page(dir, op_data, pos);
}
}
out:
ll_finish_md_op_data(op_data);
return rc;
}
static int revalidate_statahead_dentry(struct inode *dir,
struct ll_statahead_info *sai,
struct dentry **dentryp,
bool unplug)
{
struct ll_inode_info *lli = ll_i2info(dir);
struct sa_entry *entry = NULL;
struct l_wait_info lwi = { 0 };
struct ll_dentry_data *ldd;
int rc = 0;
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
if (unplug) {
rc = 1;
goto out_unplug;
}
entry = sa_get(sai, &(*dentryp)->d_name);
if (!entry) {
rc = -EAGAIN;
goto out_unplug;
}
if (!sa_ready(entry) && sai->sai_in_readpage)
sa_handle_callback(sai);
if (!sa_ready(entry)) {
spin_lock(&lli->lli_sa_lock);
sai->sai_index_wait = entry->se_index;
spin_unlock(&lli->lli_sa_lock);
lwi = LWI_TIMEOUT_INTR(cfs_time_seconds(30), NULL,
LWI_ON_SIGNAL_NOOP, NULL);
rc = l_wait_event(sai->sai_waitq, sa_ready(entry), &lwi);
if (rc < 0) {
entry = NULL;
rc = -EAGAIN;
goto out_unplug;
}
}
if (entry->se_state == SA_ENTRY_SUCC && entry->se_inode) {
struct inode *inode = entry->se_inode;
struct lookup_intent it = { .it_op = IT_GETATTR,
.it_lock_handle = entry->se_handle };
__u64 bits;
rc = md_revalidate_lock(ll_i2mdexp(dir), &it,
ll_inode2fid(inode), &bits);
if (rc == 1) {
if (!(*dentryp)->d_inode) {
struct dentry *alias;
alias = ll_splice_alias(inode, *dentryp);
if (IS_ERR(alias)) {
ll_intent_release(&it);
rc = PTR_ERR(alias);
goto out_unplug;
}
*dentryp = alias;
entry->se_inode = NULL;
} else if ((*dentryp)->d_inode != inode) {
CDEBUG(D_READA,
"%s: stale dentry %pd inode "DFID", statahead inode "DFID"\n",
ll_get_fsname((*dentryp)->d_inode->i_sb,
NULL, 0),
*dentryp,
PFID(ll_inode2fid((*dentryp)->d_inode)),
PFID(ll_inode2fid(inode)));
ll_intent_release(&it);
rc = -ESTALE;
goto out_unplug;
}
if ((bits & MDS_INODELOCK_LOOKUP) &&
d_lustre_invalid(*dentryp))
d_lustre_revalidate(*dentryp);
ll_intent_release(&it);
}
}
out_unplug:
ldd = ll_d2d(*dentryp);
ldd->lld_sa_generation = lli->lli_sa_generation;
sa_put(sai, entry);
return rc;
}
static int start_statahead_thread(struct inode *dir, struct dentry *dentry)
{
struct ll_inode_info *lli = ll_i2info(dir);
struct ll_statahead_info *sai = NULL;
struct l_wait_info lwi = { 0 };
struct ptlrpc_thread *thread;
struct task_struct *task;
struct dentry *parent = dentry->d_parent;
int rc;
rc = is_first_dirent(dir, dentry);
if (rc == LS_NOT_FIRST_DE) {
rc = -EFAULT;
goto out;
}
sai = ll_sai_alloc(parent);
if (!sai) {
rc = -ENOMEM;
goto out;
}
sai->sai_ls_all = (rc == LS_FIRST_DOT_DE);
spin_lock(&lli->lli_sa_lock);
if (unlikely(lli->lli_sai || lli->lli_opendir_key ||
lli->lli_opendir_pid != current->pid)) {
spin_unlock(&lli->lli_sa_lock);
rc = -EPERM;
goto out;
}
lli->lli_sai = sai;
spin_unlock(&lli->lli_sa_lock);
atomic_inc(&ll_i2sbi(parent->d_inode)->ll_sa_running);
CDEBUG(D_READA, "start statahead thread: [pid %d] [parent %pd]\n",
current_pid(), parent);
task = kthread_run(ll_statahead_thread, parent, "ll_sa_%u",
lli->lli_opendir_pid);
thread = &sai->sai_thread;
if (IS_ERR(task)) {
rc = PTR_ERR(task);
CERROR("can't start ll_sa thread, rc : %d\n", rc);
goto out;
}
l_wait_event(thread->t_ctl_waitq,
thread_is_running(thread) || thread_is_stopped(thread),
&lwi);
ll_sai_put(sai);
return -EAGAIN;
out:
spin_lock(&lli->lli_sa_lock);
lli->lli_sa_enabled = 0;
lli->lli_sai = NULL;
spin_unlock(&lli->lli_sa_lock);
if (sai)
ll_sai_free(sai);
return rc;
}
int ll_statahead(struct inode *dir, struct dentry **dentryp, bool unplug)
{
struct ll_statahead_info *sai;
sai = ll_sai_get(dir);
if (sai) {
int rc;
rc = revalidate_statahead_dentry(dir, sai, dentryp, unplug);
CDEBUG(D_READA, "revalidate statahead %pd: %d.\n",
*dentryp, rc);
ll_sai_put(sai);
return rc;
}
return start_statahead_thread(dir, *dentryp);
}
