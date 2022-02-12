int dlm_modes_compat(int mode1, int mode2)
{
return __dlm_compat_matrix[mode1 + 1][mode2 + 1];
}
void dlm_print_lkb(struct dlm_lkb *lkb)
{
printk(KERN_ERR "lkb: nodeid %d id %x remid %x exflags %x flags %x "
"sts %d rq %d gr %d wait_type %d wait_nodeid %d seq %llu\n",
lkb->lkb_nodeid, lkb->lkb_id, lkb->lkb_remid, lkb->lkb_exflags,
lkb->lkb_flags, lkb->lkb_status, lkb->lkb_rqmode,
lkb->lkb_grmode, lkb->lkb_wait_type, lkb->lkb_wait_nodeid,
(unsigned long long)lkb->lkb_recover_seq);
}
static void dlm_print_rsb(struct dlm_rsb *r)
{
printk(KERN_ERR "rsb: nodeid %d master %d dir %d flags %lx first %x "
"rlc %d name %s\n",
r->res_nodeid, r->res_master_nodeid, r->res_dir_nodeid,
r->res_flags, r->res_first_lkid, r->res_recover_locks_count,
r->res_name);
}
void dlm_dump_rsb(struct dlm_rsb *r)
{
struct dlm_lkb *lkb;
dlm_print_rsb(r);
printk(KERN_ERR "rsb: root_list empty %d recover_list empty %d\n",
list_empty(&r->res_root_list), list_empty(&r->res_recover_list));
printk(KERN_ERR "rsb lookup list\n");
list_for_each_entry(lkb, &r->res_lookup, lkb_rsb_lookup)
dlm_print_lkb(lkb);
printk(KERN_ERR "rsb grant queue:\n");
list_for_each_entry(lkb, &r->res_grantqueue, lkb_statequeue)
dlm_print_lkb(lkb);
printk(KERN_ERR "rsb convert queue:\n");
list_for_each_entry(lkb, &r->res_convertqueue, lkb_statequeue)
dlm_print_lkb(lkb);
printk(KERN_ERR "rsb wait queue:\n");
list_for_each_entry(lkb, &r->res_waitqueue, lkb_statequeue)
dlm_print_lkb(lkb);
}
static inline void dlm_lock_recovery(struct dlm_ls *ls)
{
down_read(&ls->ls_in_recovery);
}
void dlm_unlock_recovery(struct dlm_ls *ls)
{
up_read(&ls->ls_in_recovery);
}
int dlm_lock_recovery_try(struct dlm_ls *ls)
{
return down_read_trylock(&ls->ls_in_recovery);
}
static inline int can_be_queued(struct dlm_lkb *lkb)
{
return !(lkb->lkb_exflags & DLM_LKF_NOQUEUE);
}
static inline int force_blocking_asts(struct dlm_lkb *lkb)
{
return (lkb->lkb_exflags & DLM_LKF_NOQUEUEBAST);
}
static inline int is_demoted(struct dlm_lkb *lkb)
{
return (lkb->lkb_sbflags & DLM_SBF_DEMOTED);
}
static inline int is_altmode(struct dlm_lkb *lkb)
{
return (lkb->lkb_sbflags & DLM_SBF_ALTMODE);
}
static inline int is_granted(struct dlm_lkb *lkb)
{
return (lkb->lkb_status == DLM_LKSTS_GRANTED);
}
static inline int is_remote(struct dlm_rsb *r)
{
DLM_ASSERT(r->res_nodeid >= 0, dlm_print_rsb(r););
return !!r->res_nodeid;
}
static inline int is_process_copy(struct dlm_lkb *lkb)
{
return (lkb->lkb_nodeid && !(lkb->lkb_flags & DLM_IFL_MSTCPY));
}
static inline int is_master_copy(struct dlm_lkb *lkb)
{
return (lkb->lkb_flags & DLM_IFL_MSTCPY) ? 1 : 0;
}
static inline int middle_conversion(struct dlm_lkb *lkb)
{
if ((lkb->lkb_grmode==DLM_LOCK_PR && lkb->lkb_rqmode==DLM_LOCK_CW) ||
(lkb->lkb_rqmode==DLM_LOCK_PR && lkb->lkb_grmode==DLM_LOCK_CW))
return 1;
return 0;
}
static inline int down_conversion(struct dlm_lkb *lkb)
{
return (!middle_conversion(lkb) && lkb->lkb_rqmode < lkb->lkb_grmode);
}
static inline int is_overlap_unlock(struct dlm_lkb *lkb)
{
return lkb->lkb_flags & DLM_IFL_OVERLAP_UNLOCK;
}
static inline int is_overlap_cancel(struct dlm_lkb *lkb)
{
return lkb->lkb_flags & DLM_IFL_OVERLAP_CANCEL;
}
static inline int is_overlap(struct dlm_lkb *lkb)
{
return (lkb->lkb_flags & (DLM_IFL_OVERLAP_UNLOCK |
DLM_IFL_OVERLAP_CANCEL));
}
static void queue_cast(struct dlm_rsb *r, struct dlm_lkb *lkb, int rv)
{
if (is_master_copy(lkb))
return;
del_timeout(lkb);
DLM_ASSERT(lkb->lkb_lksb, dlm_print_lkb(lkb););
if (rv == -DLM_ECANCEL && (lkb->lkb_flags & DLM_IFL_TIMEOUT_CANCEL)) {
lkb->lkb_flags &= ~DLM_IFL_TIMEOUT_CANCEL;
rv = -ETIMEDOUT;
}
if (rv == -DLM_ECANCEL && (lkb->lkb_flags & DLM_IFL_DEADLOCK_CANCEL)) {
lkb->lkb_flags &= ~DLM_IFL_DEADLOCK_CANCEL;
rv = -EDEADLK;
}
dlm_add_cb(lkb, DLM_CB_CAST, lkb->lkb_grmode, rv, lkb->lkb_sbflags);
}
static inline void queue_cast_overlap(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
queue_cast(r, lkb,
is_overlap_unlock(lkb) ? -DLM_EUNLOCK : -DLM_ECANCEL);
}
static void queue_bast(struct dlm_rsb *r, struct dlm_lkb *lkb, int rqmode)
{
if (is_master_copy(lkb)) {
send_bast(r, lkb, rqmode);
} else {
dlm_add_cb(lkb, DLM_CB_BAST, rqmode, 0, 0);
}
}
static inline void hold_rsb(struct dlm_rsb *r)
{
kref_get(&r->res_ref);
}
void dlm_hold_rsb(struct dlm_rsb *r)
{
hold_rsb(r);
}
static void put_rsb(struct dlm_rsb *r)
{
struct dlm_ls *ls = r->res_ls;
uint32_t bucket = r->res_bucket;
spin_lock(&ls->ls_rsbtbl[bucket].lock);
kref_put(&r->res_ref, toss_rsb);
spin_unlock(&ls->ls_rsbtbl[bucket].lock);
}
void dlm_put_rsb(struct dlm_rsb *r)
{
put_rsb(r);
}
static int pre_rsb_struct(struct dlm_ls *ls)
{
struct dlm_rsb *r1, *r2;
int count = 0;
spin_lock(&ls->ls_new_rsb_spin);
if (ls->ls_new_rsb_count > dlm_config.ci_new_rsb_count / 2) {
spin_unlock(&ls->ls_new_rsb_spin);
return 0;
}
spin_unlock(&ls->ls_new_rsb_spin);
r1 = dlm_allocate_rsb(ls);
r2 = dlm_allocate_rsb(ls);
spin_lock(&ls->ls_new_rsb_spin);
if (r1) {
list_add(&r1->res_hashchain, &ls->ls_new_rsb);
ls->ls_new_rsb_count++;
}
if (r2) {
list_add(&r2->res_hashchain, &ls->ls_new_rsb);
ls->ls_new_rsb_count++;
}
count = ls->ls_new_rsb_count;
spin_unlock(&ls->ls_new_rsb_spin);
if (!count)
return -ENOMEM;
return 0;
}
static int get_rsb_struct(struct dlm_ls *ls, char *name, int len,
struct dlm_rsb **r_ret)
{
struct dlm_rsb *r;
int count;
spin_lock(&ls->ls_new_rsb_spin);
if (list_empty(&ls->ls_new_rsb)) {
count = ls->ls_new_rsb_count;
spin_unlock(&ls->ls_new_rsb_spin);
log_debug(ls, "find_rsb retry %d %d %s",
count, dlm_config.ci_new_rsb_count, name);
return -EAGAIN;
}
r = list_first_entry(&ls->ls_new_rsb, struct dlm_rsb, res_hashchain);
list_del(&r->res_hashchain);
memset(&r->res_hashnode, 0, sizeof(struct rb_node));
ls->ls_new_rsb_count--;
spin_unlock(&ls->ls_new_rsb_spin);
r->res_ls = ls;
r->res_length = len;
memcpy(r->res_name, name, len);
mutex_init(&r->res_mutex);
INIT_LIST_HEAD(&r->res_lookup);
INIT_LIST_HEAD(&r->res_grantqueue);
INIT_LIST_HEAD(&r->res_convertqueue);
INIT_LIST_HEAD(&r->res_waitqueue);
INIT_LIST_HEAD(&r->res_root_list);
INIT_LIST_HEAD(&r->res_recover_list);
*r_ret = r;
return 0;
}
static int rsb_cmp(struct dlm_rsb *r, const char *name, int nlen)
{
char maxname[DLM_RESNAME_MAXLEN];
memset(maxname, 0, DLM_RESNAME_MAXLEN);
memcpy(maxname, name, nlen);
return memcmp(r->res_name, maxname, DLM_RESNAME_MAXLEN);
}
int dlm_search_rsb_tree(struct rb_root *tree, char *name, int len,
struct dlm_rsb **r_ret)
{
struct rb_node *node = tree->rb_node;
struct dlm_rsb *r;
int rc;
while (node) {
r = rb_entry(node, struct dlm_rsb, res_hashnode);
rc = rsb_cmp(r, name, len);
if (rc < 0)
node = node->rb_left;
else if (rc > 0)
node = node->rb_right;
else
goto found;
}
*r_ret = NULL;
return -EBADR;
found:
*r_ret = r;
return 0;
}
static int rsb_insert(struct dlm_rsb *rsb, struct rb_root *tree)
{
struct rb_node **newn = &tree->rb_node;
struct rb_node *parent = NULL;
int rc;
while (*newn) {
struct dlm_rsb *cur = rb_entry(*newn, struct dlm_rsb,
res_hashnode);
parent = *newn;
rc = rsb_cmp(cur, rsb->res_name, rsb->res_length);
if (rc < 0)
newn = &parent->rb_left;
else if (rc > 0)
newn = &parent->rb_right;
else {
log_print("rsb_insert match");
dlm_dump_rsb(rsb);
dlm_dump_rsb(cur);
return -EEXIST;
}
}
rb_link_node(&rsb->res_hashnode, parent, newn);
rb_insert_color(&rsb->res_hashnode, tree);
return 0;
}
static int find_rsb_dir(struct dlm_ls *ls, char *name, int len,
uint32_t hash, uint32_t b,
int dir_nodeid, int from_nodeid,
unsigned int flags, struct dlm_rsb **r_ret)
{
struct dlm_rsb *r = NULL;
int our_nodeid = dlm_our_nodeid();
int from_local = 0;
int from_other = 0;
int from_dir = 0;
int create = 0;
int error;
if (flags & R_RECEIVE_REQUEST) {
if (from_nodeid == dir_nodeid)
from_dir = 1;
else
from_other = 1;
} else if (flags & R_REQUEST) {
from_local = 1;
}
if (from_local || from_dir ||
(from_other && (dir_nodeid == our_nodeid))) {
create = 1;
}
retry:
if (create) {
error = pre_rsb_struct(ls);
if (error < 0)
goto out;
}
spin_lock(&ls->ls_rsbtbl[b].lock);
error = dlm_search_rsb_tree(&ls->ls_rsbtbl[b].keep, name, len, &r);
if (error)
goto do_toss;
kref_get(&r->res_ref);
error = 0;
goto out_unlock;
do_toss:
error = dlm_search_rsb_tree(&ls->ls_rsbtbl[b].toss, name, len, &r);
if (error)
goto do_new;
if ((r->res_master_nodeid != our_nodeid) && from_other) {
log_debug(ls, "find_rsb toss from_other %d master %d dir %d %s",
from_nodeid, r->res_master_nodeid, dir_nodeid,
r->res_name);
error = -ENOTBLK;
goto out_unlock;
}
if ((r->res_master_nodeid != our_nodeid) && from_dir) {
log_error(ls, "find_rsb toss from_dir %d master %d",
from_nodeid, r->res_master_nodeid);
dlm_print_rsb(r);
r->res_master_nodeid = our_nodeid;
r->res_nodeid = 0;
rsb_clear_flag(r, RSB_MASTER_UNCERTAIN);
r->res_first_lkid = 0;
}
if (from_local && (r->res_master_nodeid != our_nodeid)) {
rsb_set_flag(r, RSB_MASTER_UNCERTAIN);
r->res_first_lkid = 0;
}
rb_erase(&r->res_hashnode, &ls->ls_rsbtbl[b].toss);
error = rsb_insert(r, &ls->ls_rsbtbl[b].keep);
goto out_unlock;
do_new:
if (error == -EBADR && !create)
goto out_unlock;
error = get_rsb_struct(ls, name, len, &r);
if (error == -EAGAIN) {
spin_unlock(&ls->ls_rsbtbl[b].lock);
goto retry;
}
if (error)
goto out_unlock;
r->res_hash = hash;
r->res_bucket = b;
r->res_dir_nodeid = dir_nodeid;
kref_init(&r->res_ref);
if (from_dir) {
log_debug(ls, "find_rsb new from_dir %d recreate %s",
from_nodeid, r->res_name);
r->res_master_nodeid = our_nodeid;
r->res_nodeid = 0;
goto out_add;
}
if (from_other && (dir_nodeid != our_nodeid)) {
log_error(ls, "find_rsb new from_other %d dir %d our %d %s",
from_nodeid, dir_nodeid, our_nodeid, r->res_name);
dlm_free_rsb(r);
r = NULL;
error = -ENOTBLK;
goto out_unlock;
}
if (from_other) {
log_debug(ls, "find_rsb new from_other %d dir %d %s",
from_nodeid, dir_nodeid, r->res_name);
}
if (dir_nodeid == our_nodeid) {
r->res_master_nodeid = our_nodeid;
r->res_nodeid = 0;
} else {
r->res_master_nodeid = 0;
r->res_nodeid = -1;
}
out_add:
error = rsb_insert(r, &ls->ls_rsbtbl[b].keep);
out_unlock:
spin_unlock(&ls->ls_rsbtbl[b].lock);
out:
*r_ret = r;
return error;
}
static int find_rsb_nodir(struct dlm_ls *ls, char *name, int len,
uint32_t hash, uint32_t b,
int dir_nodeid, int from_nodeid,
unsigned int flags, struct dlm_rsb **r_ret)
{
struct dlm_rsb *r = NULL;
int our_nodeid = dlm_our_nodeid();
int recover = (flags & R_RECEIVE_RECOVER);
int error;
retry:
error = pre_rsb_struct(ls);
if (error < 0)
goto out;
spin_lock(&ls->ls_rsbtbl[b].lock);
error = dlm_search_rsb_tree(&ls->ls_rsbtbl[b].keep, name, len, &r);
if (error)
goto do_toss;
kref_get(&r->res_ref);
goto out_unlock;
do_toss:
error = dlm_search_rsb_tree(&ls->ls_rsbtbl[b].toss, name, len, &r);
if (error)
goto do_new;
if (!recover && (r->res_master_nodeid != our_nodeid) && from_nodeid) {
log_error(ls, "find_rsb toss from_nodeid %d master %d dir %d",
from_nodeid, r->res_master_nodeid, dir_nodeid);
dlm_print_rsb(r);
error = -ENOTBLK;
goto out_unlock;
}
if (!recover && (r->res_master_nodeid != our_nodeid) &&
(dir_nodeid == our_nodeid)) {
log_error(ls, "find_rsb toss our %d master %d dir %d",
our_nodeid, r->res_master_nodeid, dir_nodeid);
dlm_print_rsb(r);
r->res_master_nodeid = our_nodeid;
r->res_nodeid = 0;
}
rb_erase(&r->res_hashnode, &ls->ls_rsbtbl[b].toss);
error = rsb_insert(r, &ls->ls_rsbtbl[b].keep);
goto out_unlock;
do_new:
error = get_rsb_struct(ls, name, len, &r);
if (error == -EAGAIN) {
spin_unlock(&ls->ls_rsbtbl[b].lock);
goto retry;
}
if (error)
goto out_unlock;
r->res_hash = hash;
r->res_bucket = b;
r->res_dir_nodeid = dir_nodeid;
r->res_master_nodeid = dir_nodeid;
r->res_nodeid = (dir_nodeid == our_nodeid) ? 0 : dir_nodeid;
kref_init(&r->res_ref);
error = rsb_insert(r, &ls->ls_rsbtbl[b].keep);
out_unlock:
spin_unlock(&ls->ls_rsbtbl[b].lock);
out:
*r_ret = r;
return error;
}
static int find_rsb(struct dlm_ls *ls, char *name, int len, int from_nodeid,
unsigned int flags, struct dlm_rsb **r_ret)
{
uint32_t hash, b;
int dir_nodeid;
if (len > DLM_RESNAME_MAXLEN)
return -EINVAL;
hash = jhash(name, len, 0);
b = hash & (ls->ls_rsbtbl_size - 1);
dir_nodeid = dlm_hash2nodeid(ls, hash);
if (dlm_no_directory(ls))
return find_rsb_nodir(ls, name, len, hash, b, dir_nodeid,
from_nodeid, flags, r_ret);
else
return find_rsb_dir(ls, name, len, hash, b, dir_nodeid,
from_nodeid, flags, r_ret);
}
static int validate_master_nodeid(struct dlm_ls *ls, struct dlm_rsb *r,
int from_nodeid)
{
if (dlm_no_directory(ls)) {
log_error(ls, "find_rsb keep from_nodeid %d master %d dir %d",
from_nodeid, r->res_master_nodeid,
r->res_dir_nodeid);
dlm_print_rsb(r);
return -ENOTBLK;
}
if (from_nodeid != r->res_dir_nodeid) {
if (r->res_master_nodeid) {
log_debug(ls, "validate master from_other %d master %d "
"dir %d first %x %s", from_nodeid,
r->res_master_nodeid, r->res_dir_nodeid,
r->res_first_lkid, r->res_name);
}
return -ENOTBLK;
} else {
if (r->res_master_nodeid) {
log_error(ls, "validate master from_dir %d master %d "
"first %x %s",
from_nodeid, r->res_master_nodeid,
r->res_first_lkid, r->res_name);
}
r->res_master_nodeid = dlm_our_nodeid();
r->res_nodeid = 0;
return 0;
}
}
int dlm_master_lookup(struct dlm_ls *ls, int from_nodeid, char *name, int len,
unsigned int flags, int *r_nodeid, int *result)
{
struct dlm_rsb *r = NULL;
uint32_t hash, b;
int from_master = (flags & DLM_LU_RECOVER_DIR);
int fix_master = (flags & DLM_LU_RECOVER_MASTER);
int our_nodeid = dlm_our_nodeid();
int dir_nodeid, error, toss_list = 0;
if (len > DLM_RESNAME_MAXLEN)
return -EINVAL;
if (from_nodeid == our_nodeid) {
log_error(ls, "dlm_master_lookup from our_nodeid %d flags %x",
our_nodeid, flags);
return -EINVAL;
}
hash = jhash(name, len, 0);
b = hash & (ls->ls_rsbtbl_size - 1);
dir_nodeid = dlm_hash2nodeid(ls, hash);
if (dir_nodeid != our_nodeid) {
log_error(ls, "dlm_master_lookup from %d dir %d our %d h %x %d",
from_nodeid, dir_nodeid, our_nodeid, hash,
ls->ls_num_nodes);
*r_nodeid = -1;
return -EINVAL;
}
retry:
error = pre_rsb_struct(ls);
if (error < 0)
return error;
spin_lock(&ls->ls_rsbtbl[b].lock);
error = dlm_search_rsb_tree(&ls->ls_rsbtbl[b].keep, name, len, &r);
if (!error) {
hold_rsb(r);
spin_unlock(&ls->ls_rsbtbl[b].lock);
lock_rsb(r);
goto found;
}
error = dlm_search_rsb_tree(&ls->ls_rsbtbl[b].toss, name, len, &r);
if (error)
goto not_found;
toss_list = 1;
found:
if (r->res_dir_nodeid != our_nodeid) {
log_error(ls, "dlm_master_lookup res_dir %d our %d %s",
r->res_dir_nodeid, our_nodeid, r->res_name);
r->res_dir_nodeid = our_nodeid;
}
if (fix_master && dlm_is_removed(ls, r->res_master_nodeid)) {
r->res_master_nodeid = from_nodeid;
r->res_nodeid = from_nodeid;
rsb_set_flag(r, RSB_NEW_MASTER);
if (toss_list) {
log_error(ls, "dlm_master_lookup fix_master on toss");
dlm_dump_rsb(r);
}
}
if (from_master && (r->res_master_nodeid != from_nodeid)) {
log_limit(ls, "dlm_master_lookup from_master %d "
"master_nodeid %d res_nodeid %d first %x %s",
from_nodeid, r->res_master_nodeid, r->res_nodeid,
r->res_first_lkid, r->res_name);
if (r->res_master_nodeid == our_nodeid) {
log_error(ls, "from_master %d our_master", from_nodeid);
dlm_dump_rsb(r);
dlm_send_rcom_lookup_dump(r, from_nodeid);
goto out_found;
}
r->res_master_nodeid = from_nodeid;
r->res_nodeid = from_nodeid;
rsb_set_flag(r, RSB_NEW_MASTER);
}
if (!r->res_master_nodeid) {
log_debug(ls, "dlm_master_lookup master 0 to %d first %x %s",
from_nodeid, r->res_first_lkid, r->res_name);
r->res_master_nodeid = from_nodeid;
r->res_nodeid = from_nodeid;
}
if (!from_master && !fix_master &&
(r->res_master_nodeid == from_nodeid)) {
log_limit(ls, "dlm_master_lookup from master %d flags %x "
"first %x %s", from_nodeid, flags,
r->res_first_lkid, r->res_name);
}
out_found:
*r_nodeid = r->res_master_nodeid;
if (result)
*result = DLM_LU_MATCH;
if (toss_list) {
r->res_toss_time = jiffies;
spin_unlock(&ls->ls_rsbtbl[b].lock);
} else {
unlock_rsb(r);
put_rsb(r);
}
return 0;
not_found:
error = get_rsb_struct(ls, name, len, &r);
if (error == -EAGAIN) {
spin_unlock(&ls->ls_rsbtbl[b].lock);
goto retry;
}
if (error)
goto out_unlock;
r->res_hash = hash;
r->res_bucket = b;
r->res_dir_nodeid = our_nodeid;
r->res_master_nodeid = from_nodeid;
r->res_nodeid = from_nodeid;
kref_init(&r->res_ref);
r->res_toss_time = jiffies;
error = rsb_insert(r, &ls->ls_rsbtbl[b].toss);
if (error) {
dlm_free_rsb(r);
spin_unlock(&ls->ls_rsbtbl[b].lock);
goto retry;
}
if (result)
*result = DLM_LU_ADD;
*r_nodeid = from_nodeid;
error = 0;
out_unlock:
spin_unlock(&ls->ls_rsbtbl[b].lock);
return error;
}
static void dlm_dump_rsb_hash(struct dlm_ls *ls, uint32_t hash)
{
struct rb_node *n;
struct dlm_rsb *r;
int i;
for (i = 0; i < ls->ls_rsbtbl_size; i++) {
spin_lock(&ls->ls_rsbtbl[i].lock);
for (n = rb_first(&ls->ls_rsbtbl[i].keep); n; n = rb_next(n)) {
r = rb_entry(n, struct dlm_rsb, res_hashnode);
if (r->res_hash == hash)
dlm_dump_rsb(r);
}
spin_unlock(&ls->ls_rsbtbl[i].lock);
}
}
void dlm_dump_rsb_name(struct dlm_ls *ls, char *name, int len)
{
struct dlm_rsb *r = NULL;
uint32_t hash, b;
int error;
hash = jhash(name, len, 0);
b = hash & (ls->ls_rsbtbl_size - 1);
spin_lock(&ls->ls_rsbtbl[b].lock);
error = dlm_search_rsb_tree(&ls->ls_rsbtbl[b].keep, name, len, &r);
if (!error)
goto out_dump;
error = dlm_search_rsb_tree(&ls->ls_rsbtbl[b].toss, name, len, &r);
if (error)
goto out;
out_dump:
dlm_dump_rsb(r);
out:
spin_unlock(&ls->ls_rsbtbl[b].lock);
}
static void toss_rsb(struct kref *kref)
{
struct dlm_rsb *r = container_of(kref, struct dlm_rsb, res_ref);
struct dlm_ls *ls = r->res_ls;
DLM_ASSERT(list_empty(&r->res_root_list), dlm_print_rsb(r););
kref_init(&r->res_ref);
rb_erase(&r->res_hashnode, &ls->ls_rsbtbl[r->res_bucket].keep);
rsb_insert(r, &ls->ls_rsbtbl[r->res_bucket].toss);
r->res_toss_time = jiffies;
ls->ls_rsbtbl[r->res_bucket].flags |= DLM_RTF_SHRINK;
if (r->res_lvbptr) {
dlm_free_lvb(r->res_lvbptr);
r->res_lvbptr = NULL;
}
}
static void unhold_rsb(struct dlm_rsb *r)
{
int rv;
rv = kref_put(&r->res_ref, toss_rsb);
DLM_ASSERT(!rv, dlm_dump_rsb(r););
}
static void kill_rsb(struct kref *kref)
{
struct dlm_rsb *r = container_of(kref, struct dlm_rsb, res_ref);
DLM_ASSERT(list_empty(&r->res_lookup), dlm_dump_rsb(r););
DLM_ASSERT(list_empty(&r->res_grantqueue), dlm_dump_rsb(r););
DLM_ASSERT(list_empty(&r->res_convertqueue), dlm_dump_rsb(r););
DLM_ASSERT(list_empty(&r->res_waitqueue), dlm_dump_rsb(r););
DLM_ASSERT(list_empty(&r->res_root_list), dlm_dump_rsb(r););
DLM_ASSERT(list_empty(&r->res_recover_list), dlm_dump_rsb(r););
}
static void attach_lkb(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
hold_rsb(r);
lkb->lkb_resource = r;
}
static void detach_lkb(struct dlm_lkb *lkb)
{
if (lkb->lkb_resource) {
put_rsb(lkb->lkb_resource);
lkb->lkb_resource = NULL;
}
}
static int create_lkb(struct dlm_ls *ls, struct dlm_lkb **lkb_ret)
{
struct dlm_lkb *lkb;
int rv;
lkb = dlm_allocate_lkb(ls);
if (!lkb)
return -ENOMEM;
lkb->lkb_nodeid = -1;
lkb->lkb_grmode = DLM_LOCK_IV;
kref_init(&lkb->lkb_ref);
INIT_LIST_HEAD(&lkb->lkb_ownqueue);
INIT_LIST_HEAD(&lkb->lkb_rsb_lookup);
INIT_LIST_HEAD(&lkb->lkb_time_list);
INIT_LIST_HEAD(&lkb->lkb_cb_list);
mutex_init(&lkb->lkb_cb_mutex);
INIT_WORK(&lkb->lkb_cb_work, dlm_callback_work);
idr_preload(GFP_NOFS);
spin_lock(&ls->ls_lkbidr_spin);
rv = idr_alloc(&ls->ls_lkbidr, lkb, 1, 0, GFP_NOWAIT);
if (rv >= 0)
lkb->lkb_id = rv;
spin_unlock(&ls->ls_lkbidr_spin);
idr_preload_end();
if (rv < 0) {
log_error(ls, "create_lkb idr error %d", rv);
return rv;
}
*lkb_ret = lkb;
return 0;
}
static int find_lkb(struct dlm_ls *ls, uint32_t lkid, struct dlm_lkb **lkb_ret)
{
struct dlm_lkb *lkb;
spin_lock(&ls->ls_lkbidr_spin);
lkb = idr_find(&ls->ls_lkbidr, lkid);
if (lkb)
kref_get(&lkb->lkb_ref);
spin_unlock(&ls->ls_lkbidr_spin);
*lkb_ret = lkb;
return lkb ? 0 : -ENOENT;
}
static void kill_lkb(struct kref *kref)
{
struct dlm_lkb *lkb = container_of(kref, struct dlm_lkb, lkb_ref);
DLM_ASSERT(!lkb->lkb_status, dlm_print_lkb(lkb););
}
static int __put_lkb(struct dlm_ls *ls, struct dlm_lkb *lkb)
{
uint32_t lkid = lkb->lkb_id;
spin_lock(&ls->ls_lkbidr_spin);
if (kref_put(&lkb->lkb_ref, kill_lkb)) {
idr_remove(&ls->ls_lkbidr, lkid);
spin_unlock(&ls->ls_lkbidr_spin);
detach_lkb(lkb);
if (lkb->lkb_lvbptr && is_master_copy(lkb))
dlm_free_lvb(lkb->lkb_lvbptr);
dlm_free_lkb(lkb);
return 1;
} else {
spin_unlock(&ls->ls_lkbidr_spin);
return 0;
}
}
int dlm_put_lkb(struct dlm_lkb *lkb)
{
struct dlm_ls *ls;
DLM_ASSERT(lkb->lkb_resource, dlm_print_lkb(lkb););
DLM_ASSERT(lkb->lkb_resource->res_ls, dlm_print_lkb(lkb););
ls = lkb->lkb_resource->res_ls;
return __put_lkb(ls, lkb);
}
static inline void hold_lkb(struct dlm_lkb *lkb)
{
kref_get(&lkb->lkb_ref);
}
static inline void unhold_lkb(struct dlm_lkb *lkb)
{
int rv;
rv = kref_put(&lkb->lkb_ref, kill_lkb);
DLM_ASSERT(!rv, dlm_print_lkb(lkb););
}
static void lkb_add_ordered(struct list_head *new, struct list_head *head,
int mode)
{
struct dlm_lkb *lkb = NULL;
list_for_each_entry(lkb, head, lkb_statequeue)
if (lkb->lkb_rqmode < mode)
break;
__list_add(new, lkb->lkb_statequeue.prev, &lkb->lkb_statequeue);
}
static void add_lkb(struct dlm_rsb *r, struct dlm_lkb *lkb, int status)
{
kref_get(&lkb->lkb_ref);
DLM_ASSERT(!lkb->lkb_status, dlm_print_lkb(lkb););
lkb->lkb_timestamp = ktime_get();
lkb->lkb_status = status;
switch (status) {
case DLM_LKSTS_WAITING:
if (lkb->lkb_exflags & DLM_LKF_HEADQUE)
list_add(&lkb->lkb_statequeue, &r->res_waitqueue);
else
list_add_tail(&lkb->lkb_statequeue, &r->res_waitqueue);
break;
case DLM_LKSTS_GRANTED:
lkb_add_ordered(&lkb->lkb_statequeue, &r->res_grantqueue,
lkb->lkb_grmode);
break;
case DLM_LKSTS_CONVERT:
if (lkb->lkb_exflags & DLM_LKF_HEADQUE)
list_add(&lkb->lkb_statequeue, &r->res_convertqueue);
else
list_add_tail(&lkb->lkb_statequeue,
&r->res_convertqueue);
break;
default:
DLM_ASSERT(0, dlm_print_lkb(lkb); printk("sts=%d\n", status););
}
}
static void del_lkb(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
lkb->lkb_status = 0;
list_del(&lkb->lkb_statequeue);
unhold_lkb(lkb);
}
static void move_lkb(struct dlm_rsb *r, struct dlm_lkb *lkb, int sts)
{
hold_lkb(lkb);
del_lkb(r, lkb);
add_lkb(r, lkb, sts);
unhold_lkb(lkb);
}
static int msg_reply_type(int mstype)
{
switch (mstype) {
case DLM_MSG_REQUEST:
return DLM_MSG_REQUEST_REPLY;
case DLM_MSG_CONVERT:
return DLM_MSG_CONVERT_REPLY;
case DLM_MSG_UNLOCK:
return DLM_MSG_UNLOCK_REPLY;
case DLM_MSG_CANCEL:
return DLM_MSG_CANCEL_REPLY;
case DLM_MSG_LOOKUP:
return DLM_MSG_LOOKUP_REPLY;
}
return -1;
}
static int nodeid_warned(int nodeid, int num_nodes, int *warned)
{
int i;
for (i = 0; i < num_nodes; i++) {
if (!warned[i]) {
warned[i] = nodeid;
return 0;
}
if (warned[i] == nodeid)
return 1;
}
return 0;
}
void dlm_scan_waiters(struct dlm_ls *ls)
{
struct dlm_lkb *lkb;
s64 us;
s64 debug_maxus = 0;
u32 debug_scanned = 0;
u32 debug_expired = 0;
int num_nodes = 0;
int *warned = NULL;
if (!dlm_config.ci_waitwarn_us)
return;
mutex_lock(&ls->ls_waiters_mutex);
list_for_each_entry(lkb, &ls->ls_waiters, lkb_wait_reply) {
if (!lkb->lkb_wait_time)
continue;
debug_scanned++;
us = ktime_to_us(ktime_sub(ktime_get(), lkb->lkb_wait_time));
if (us < dlm_config.ci_waitwarn_us)
continue;
lkb->lkb_wait_time = 0;
debug_expired++;
if (us > debug_maxus)
debug_maxus = us;
if (!num_nodes) {
num_nodes = ls->ls_num_nodes;
warned = kzalloc(num_nodes * sizeof(int), GFP_KERNEL);
}
if (!warned)
continue;
if (nodeid_warned(lkb->lkb_wait_nodeid, num_nodes, warned))
continue;
log_error(ls, "waitwarn %x %lld %d us check connection to "
"node %d", lkb->lkb_id, (long long)us,
dlm_config.ci_waitwarn_us, lkb->lkb_wait_nodeid);
}
mutex_unlock(&ls->ls_waiters_mutex);
kfree(warned);
if (debug_expired)
log_debug(ls, "scan_waiters %u warn %u over %d us max %lld us",
debug_scanned, debug_expired,
dlm_config.ci_waitwarn_us, (long long)debug_maxus);
}
static int add_to_waiters(struct dlm_lkb *lkb, int mstype, int to_nodeid)
{
struct dlm_ls *ls = lkb->lkb_resource->res_ls;
int error = 0;
mutex_lock(&ls->ls_waiters_mutex);
if (is_overlap_unlock(lkb) ||
(is_overlap_cancel(lkb) && (mstype == DLM_MSG_CANCEL))) {
error = -EINVAL;
goto out;
}
if (lkb->lkb_wait_type || is_overlap_cancel(lkb)) {
switch (mstype) {
case DLM_MSG_UNLOCK:
lkb->lkb_flags |= DLM_IFL_OVERLAP_UNLOCK;
break;
case DLM_MSG_CANCEL:
lkb->lkb_flags |= DLM_IFL_OVERLAP_CANCEL;
break;
default:
error = -EBUSY;
goto out;
}
lkb->lkb_wait_count++;
hold_lkb(lkb);
log_debug(ls, "addwait %x cur %d overlap %d count %d f %x",
lkb->lkb_id, lkb->lkb_wait_type, mstype,
lkb->lkb_wait_count, lkb->lkb_flags);
goto out;
}
DLM_ASSERT(!lkb->lkb_wait_count,
dlm_print_lkb(lkb);
printk("wait_count %d\n", lkb->lkb_wait_count););
lkb->lkb_wait_count++;
lkb->lkb_wait_type = mstype;
lkb->lkb_wait_time = ktime_get();
lkb->lkb_wait_nodeid = to_nodeid;
hold_lkb(lkb);
list_add(&lkb->lkb_wait_reply, &ls->ls_waiters);
out:
if (error)
log_error(ls, "addwait error %x %d flags %x %d %d %s",
lkb->lkb_id, error, lkb->lkb_flags, mstype,
lkb->lkb_wait_type, lkb->lkb_resource->res_name);
mutex_unlock(&ls->ls_waiters_mutex);
return error;
}
static int _remove_from_waiters(struct dlm_lkb *lkb, int mstype,
struct dlm_message *ms)
{
struct dlm_ls *ls = lkb->lkb_resource->res_ls;
int overlap_done = 0;
if (is_overlap_unlock(lkb) && (mstype == DLM_MSG_UNLOCK_REPLY)) {
log_debug(ls, "remwait %x unlock_reply overlap", lkb->lkb_id);
lkb->lkb_flags &= ~DLM_IFL_OVERLAP_UNLOCK;
overlap_done = 1;
goto out_del;
}
if (is_overlap_cancel(lkb) && (mstype == DLM_MSG_CANCEL_REPLY)) {
log_debug(ls, "remwait %x cancel_reply overlap", lkb->lkb_id);
lkb->lkb_flags &= ~DLM_IFL_OVERLAP_CANCEL;
overlap_done = 1;
goto out_del;
}
if ((mstype == DLM_MSG_CANCEL_REPLY) &&
(lkb->lkb_wait_type != DLM_MSG_CANCEL)) {
log_debug(ls, "remwait %x cancel_reply wait_type %d",
lkb->lkb_id, lkb->lkb_wait_type);
return -1;
}
if ((mstype == DLM_MSG_CONVERT_REPLY) &&
(lkb->lkb_wait_type == DLM_MSG_CONVERT) &&
is_overlap_cancel(lkb) && ms && !ms->m_result) {
log_debug(ls, "remwait %x convert_reply zap overlap_cancel",
lkb->lkb_id);
lkb->lkb_wait_type = 0;
lkb->lkb_flags &= ~DLM_IFL_OVERLAP_CANCEL;
lkb->lkb_wait_count--;
goto out_del;
}
if (lkb->lkb_wait_type) {
lkb->lkb_wait_type = 0;
goto out_del;
}
log_error(ls, "remwait error %x remote %d %x msg %d flags %x no wait",
lkb->lkb_id, ms ? ms->m_header.h_nodeid : 0, lkb->lkb_remid,
mstype, lkb->lkb_flags);
return -1;
out_del:
if (overlap_done && lkb->lkb_wait_type) {
log_error(ls, "remwait error %x reply %d wait_type %d overlap",
lkb->lkb_id, mstype, lkb->lkb_wait_type);
lkb->lkb_wait_count--;
lkb->lkb_wait_type = 0;
}
DLM_ASSERT(lkb->lkb_wait_count, dlm_print_lkb(lkb););
lkb->lkb_flags &= ~DLM_IFL_RESEND;
lkb->lkb_wait_count--;
if (!lkb->lkb_wait_count)
list_del_init(&lkb->lkb_wait_reply);
unhold_lkb(lkb);
return 0;
}
static int remove_from_waiters(struct dlm_lkb *lkb, int mstype)
{
struct dlm_ls *ls = lkb->lkb_resource->res_ls;
int error;
mutex_lock(&ls->ls_waiters_mutex);
error = _remove_from_waiters(lkb, mstype, NULL);
mutex_unlock(&ls->ls_waiters_mutex);
return error;
}
static int remove_from_waiters_ms(struct dlm_lkb *lkb, struct dlm_message *ms)
{
struct dlm_ls *ls = lkb->lkb_resource->res_ls;
int error;
if (ms->m_flags != DLM_IFL_STUB_MS)
mutex_lock(&ls->ls_waiters_mutex);
error = _remove_from_waiters(lkb, ms->m_type, ms);
if (ms->m_flags != DLM_IFL_STUB_MS)
mutex_unlock(&ls->ls_waiters_mutex);
return error;
}
static void wait_pending_remove(struct dlm_rsb *r)
{
struct dlm_ls *ls = r->res_ls;
restart:
spin_lock(&ls->ls_remove_spin);
if (ls->ls_remove_len &&
!rsb_cmp(r, ls->ls_remove_name, ls->ls_remove_len)) {
log_debug(ls, "delay lookup for remove dir %d %s",
r->res_dir_nodeid, r->res_name);
spin_unlock(&ls->ls_remove_spin);
msleep(1);
goto restart;
}
spin_unlock(&ls->ls_remove_spin);
}
static void shrink_bucket(struct dlm_ls *ls, int b)
{
struct rb_node *n, *next;
struct dlm_rsb *r;
char *name;
int our_nodeid = dlm_our_nodeid();
int remote_count = 0;
int need_shrink = 0;
int i, len, rv;
memset(&ls->ls_remove_lens, 0, sizeof(int) * DLM_REMOVE_NAMES_MAX);
spin_lock(&ls->ls_rsbtbl[b].lock);
if (!(ls->ls_rsbtbl[b].flags & DLM_RTF_SHRINK)) {
spin_unlock(&ls->ls_rsbtbl[b].lock);
return;
}
for (n = rb_first(&ls->ls_rsbtbl[b].toss); n; n = next) {
next = rb_next(n);
r = rb_entry(n, struct dlm_rsb, res_hashnode);
if (!dlm_no_directory(ls) &&
(r->res_master_nodeid != our_nodeid) &&
(dlm_dir_nodeid(r) == our_nodeid)) {
continue;
}
need_shrink = 1;
if (!time_after_eq(jiffies, r->res_toss_time +
dlm_config.ci_toss_secs * HZ)) {
continue;
}
if (!dlm_no_directory(ls) &&
(r->res_master_nodeid == our_nodeid) &&
(dlm_dir_nodeid(r) != our_nodeid)) {
ls->ls_remove_lens[remote_count] = r->res_length;
memcpy(ls->ls_remove_names[remote_count], r->res_name,
DLM_RESNAME_MAXLEN);
remote_count++;
if (remote_count >= DLM_REMOVE_NAMES_MAX)
break;
continue;
}
if (!kref_put(&r->res_ref, kill_rsb)) {
log_error(ls, "tossed rsb in use %s", r->res_name);
continue;
}
rb_erase(&r->res_hashnode, &ls->ls_rsbtbl[b].toss);
dlm_free_rsb(r);
}
if (need_shrink)
ls->ls_rsbtbl[b].flags |= DLM_RTF_SHRINK;
else
ls->ls_rsbtbl[b].flags &= ~DLM_RTF_SHRINK;
spin_unlock(&ls->ls_rsbtbl[b].lock);
for (i = 0; i < remote_count; i++) {
name = ls->ls_remove_names[i];
len = ls->ls_remove_lens[i];
spin_lock(&ls->ls_rsbtbl[b].lock);
rv = dlm_search_rsb_tree(&ls->ls_rsbtbl[b].toss, name, len, &r);
if (rv) {
spin_unlock(&ls->ls_rsbtbl[b].lock);
log_debug(ls, "remove_name not toss %s", name);
continue;
}
if (r->res_master_nodeid != our_nodeid) {
spin_unlock(&ls->ls_rsbtbl[b].lock);
log_debug(ls, "remove_name master %d dir %d our %d %s",
r->res_master_nodeid, r->res_dir_nodeid,
our_nodeid, name);
continue;
}
if (r->res_dir_nodeid == our_nodeid) {
spin_unlock(&ls->ls_rsbtbl[b].lock);
log_error(ls, "remove_name dir %d master %d our %d %s",
r->res_dir_nodeid, r->res_master_nodeid,
our_nodeid, name);
continue;
}
if (!time_after_eq(jiffies, r->res_toss_time +
dlm_config.ci_toss_secs * HZ)) {
spin_unlock(&ls->ls_rsbtbl[b].lock);
log_debug(ls, "remove_name toss_time %lu now %lu %s",
r->res_toss_time, jiffies, name);
continue;
}
if (!kref_put(&r->res_ref, kill_rsb)) {
spin_unlock(&ls->ls_rsbtbl[b].lock);
log_error(ls, "remove_name in use %s", name);
continue;
}
rb_erase(&r->res_hashnode, &ls->ls_rsbtbl[b].toss);
spin_lock(&ls->ls_remove_spin);
ls->ls_remove_len = len;
memcpy(ls->ls_remove_name, name, DLM_RESNAME_MAXLEN);
spin_unlock(&ls->ls_remove_spin);
spin_unlock(&ls->ls_rsbtbl[b].lock);
send_remove(r);
spin_lock(&ls->ls_remove_spin);
ls->ls_remove_len = 0;
memset(ls->ls_remove_name, 0, DLM_RESNAME_MAXLEN);
spin_unlock(&ls->ls_remove_spin);
dlm_free_rsb(r);
}
}
void dlm_scan_rsbs(struct dlm_ls *ls)
{
int i;
for (i = 0; i < ls->ls_rsbtbl_size; i++) {
shrink_bucket(ls, i);
if (dlm_locking_stopped(ls))
break;
cond_resched();
}
}
static void add_timeout(struct dlm_lkb *lkb)
{
struct dlm_ls *ls = lkb->lkb_resource->res_ls;
if (is_master_copy(lkb))
return;
if (test_bit(LSFL_TIMEWARN, &ls->ls_flags) &&
!(lkb->lkb_exflags & DLM_LKF_NODLCKWT)) {
lkb->lkb_flags |= DLM_IFL_WATCH_TIMEWARN;
goto add_it;
}
if (lkb->lkb_exflags & DLM_LKF_TIMEOUT)
goto add_it;
return;
add_it:
DLM_ASSERT(list_empty(&lkb->lkb_time_list), dlm_print_lkb(lkb););
mutex_lock(&ls->ls_timeout_mutex);
hold_lkb(lkb);
list_add_tail(&lkb->lkb_time_list, &ls->ls_timeout);
mutex_unlock(&ls->ls_timeout_mutex);
}
static void del_timeout(struct dlm_lkb *lkb)
{
struct dlm_ls *ls = lkb->lkb_resource->res_ls;
mutex_lock(&ls->ls_timeout_mutex);
if (!list_empty(&lkb->lkb_time_list)) {
list_del_init(&lkb->lkb_time_list);
unhold_lkb(lkb);
}
mutex_unlock(&ls->ls_timeout_mutex);
}
void dlm_scan_timeout(struct dlm_ls *ls)
{
struct dlm_rsb *r;
struct dlm_lkb *lkb;
int do_cancel, do_warn;
s64 wait_us;
for (;;) {
if (dlm_locking_stopped(ls))
break;
do_cancel = 0;
do_warn = 0;
mutex_lock(&ls->ls_timeout_mutex);
list_for_each_entry(lkb, &ls->ls_timeout, lkb_time_list) {
wait_us = ktime_to_us(ktime_sub(ktime_get(),
lkb->lkb_timestamp));
if ((lkb->lkb_exflags & DLM_LKF_TIMEOUT) &&
wait_us >= (lkb->lkb_timeout_cs * 10000))
do_cancel = 1;
if ((lkb->lkb_flags & DLM_IFL_WATCH_TIMEWARN) &&
wait_us >= dlm_config.ci_timewarn_cs * 10000)
do_warn = 1;
if (!do_cancel && !do_warn)
continue;
hold_lkb(lkb);
break;
}
mutex_unlock(&ls->ls_timeout_mutex);
if (!do_cancel && !do_warn)
break;
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
if (do_warn) {
lkb->lkb_flags &= ~DLM_IFL_WATCH_TIMEWARN;
if (!(lkb->lkb_exflags & DLM_LKF_TIMEOUT))
del_timeout(lkb);
dlm_timeout_warn(lkb);
}
if (do_cancel) {
log_debug(ls, "timeout cancel %x node %d %s",
lkb->lkb_id, lkb->lkb_nodeid, r->res_name);
lkb->lkb_flags &= ~DLM_IFL_WATCH_TIMEWARN;
lkb->lkb_flags |= DLM_IFL_TIMEOUT_CANCEL;
del_timeout(lkb);
_cancel_lock(r, lkb);
}
unlock_rsb(r);
unhold_rsb(r);
dlm_put_lkb(lkb);
}
}
void dlm_adjust_timeouts(struct dlm_ls *ls)
{
struct dlm_lkb *lkb;
u64 adj_us = jiffies_to_usecs(jiffies - ls->ls_recover_begin);
ls->ls_recover_begin = 0;
mutex_lock(&ls->ls_timeout_mutex);
list_for_each_entry(lkb, &ls->ls_timeout, lkb_time_list)
lkb->lkb_timestamp = ktime_add_us(lkb->lkb_timestamp, adj_us);
mutex_unlock(&ls->ls_timeout_mutex);
if (!dlm_config.ci_waitwarn_us)
return;
mutex_lock(&ls->ls_waiters_mutex);
list_for_each_entry(lkb, &ls->ls_waiters, lkb_wait_reply) {
if (ktime_to_us(lkb->lkb_wait_time))
lkb->lkb_wait_time = ktime_get();
}
mutex_unlock(&ls->ls_waiters_mutex);
}
static void set_lvb_lock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
int b, len = r->res_ls->ls_lvblen;
b = dlm_lvb_operations[lkb->lkb_grmode + 1][lkb->lkb_rqmode + 1];
if (b == 1) {
if (!lkb->lkb_lvbptr)
return;
if (!(lkb->lkb_exflags & DLM_LKF_VALBLK))
return;
if (!r->res_lvbptr)
return;
memcpy(lkb->lkb_lvbptr, r->res_lvbptr, len);
lkb->lkb_lvbseq = r->res_lvbseq;
} else if (b == 0) {
if (lkb->lkb_exflags & DLM_LKF_IVVALBLK) {
rsb_set_flag(r, RSB_VALNOTVALID);
return;
}
if (!lkb->lkb_lvbptr)
return;
if (!(lkb->lkb_exflags & DLM_LKF_VALBLK))
return;
if (!r->res_lvbptr)
r->res_lvbptr = dlm_allocate_lvb(r->res_ls);
if (!r->res_lvbptr)
return;
memcpy(r->res_lvbptr, lkb->lkb_lvbptr, len);
r->res_lvbseq++;
lkb->lkb_lvbseq = r->res_lvbseq;
rsb_clear_flag(r, RSB_VALNOTVALID);
}
if (rsb_flag(r, RSB_VALNOTVALID))
lkb->lkb_sbflags |= DLM_SBF_VALNOTVALID;
}
static void set_lvb_unlock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
if (lkb->lkb_grmode < DLM_LOCK_PW)
return;
if (lkb->lkb_exflags & DLM_LKF_IVVALBLK) {
rsb_set_flag(r, RSB_VALNOTVALID);
return;
}
if (!lkb->lkb_lvbptr)
return;
if (!(lkb->lkb_exflags & DLM_LKF_VALBLK))
return;
if (!r->res_lvbptr)
r->res_lvbptr = dlm_allocate_lvb(r->res_ls);
if (!r->res_lvbptr)
return;
memcpy(r->res_lvbptr, lkb->lkb_lvbptr, r->res_ls->ls_lvblen);
r->res_lvbseq++;
rsb_clear_flag(r, RSB_VALNOTVALID);
}
static void set_lvb_lock_pc(struct dlm_rsb *r, struct dlm_lkb *lkb,
struct dlm_message *ms)
{
int b;
if (!lkb->lkb_lvbptr)
return;
if (!(lkb->lkb_exflags & DLM_LKF_VALBLK))
return;
b = dlm_lvb_operations[lkb->lkb_grmode + 1][lkb->lkb_rqmode + 1];
if (b == 1) {
int len = receive_extralen(ms);
if (len > r->res_ls->ls_lvblen)
len = r->res_ls->ls_lvblen;
memcpy(lkb->lkb_lvbptr, ms->m_extra, len);
lkb->lkb_lvbseq = ms->m_lvbseq;
}
}
static void _remove_lock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
del_lkb(r, lkb);
lkb->lkb_grmode = DLM_LOCK_IV;
unhold_lkb(lkb);
}
static void remove_lock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
set_lvb_unlock(r, lkb);
_remove_lock(r, lkb);
}
static void remove_lock_pc(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
_remove_lock(r, lkb);
}
static int revert_lock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
int rv = 0;
lkb->lkb_rqmode = DLM_LOCK_IV;
switch (lkb->lkb_status) {
case DLM_LKSTS_GRANTED:
break;
case DLM_LKSTS_CONVERT:
move_lkb(r, lkb, DLM_LKSTS_GRANTED);
rv = 1;
break;
case DLM_LKSTS_WAITING:
del_lkb(r, lkb);
lkb->lkb_grmode = DLM_LOCK_IV;
unhold_lkb(lkb);
rv = -1;
break;
default:
log_print("invalid status for revert %d", lkb->lkb_status);
}
return rv;
}
static int revert_lock_pc(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
return revert_lock(r, lkb);
}
static void _grant_lock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
if (lkb->lkb_grmode != lkb->lkb_rqmode) {
lkb->lkb_grmode = lkb->lkb_rqmode;
if (lkb->lkb_status)
move_lkb(r, lkb, DLM_LKSTS_GRANTED);
else
add_lkb(r, lkb, DLM_LKSTS_GRANTED);
}
lkb->lkb_rqmode = DLM_LOCK_IV;
lkb->lkb_highbast = 0;
}
static void grant_lock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
set_lvb_lock(r, lkb);
_grant_lock(r, lkb);
}
static void grant_lock_pc(struct dlm_rsb *r, struct dlm_lkb *lkb,
struct dlm_message *ms)
{
set_lvb_lock_pc(r, lkb, ms);
_grant_lock(r, lkb);
}
static void grant_lock_pending(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
grant_lock(r, lkb);
if (is_master_copy(lkb))
send_grant(r, lkb);
else
queue_cast(r, lkb, 0);
}
static void munge_demoted(struct dlm_lkb *lkb)
{
if (lkb->lkb_rqmode == DLM_LOCK_IV || lkb->lkb_grmode == DLM_LOCK_IV) {
log_print("munge_demoted %x invalid modes gr %d rq %d",
lkb->lkb_id, lkb->lkb_grmode, lkb->lkb_rqmode);
return;
}
lkb->lkb_grmode = DLM_LOCK_NL;
}
static void munge_altmode(struct dlm_lkb *lkb, struct dlm_message *ms)
{
if (ms->m_type != DLM_MSG_REQUEST_REPLY &&
ms->m_type != DLM_MSG_GRANT) {
log_print("munge_altmode %x invalid reply type %d",
lkb->lkb_id, ms->m_type);
return;
}
if (lkb->lkb_exflags & DLM_LKF_ALTPR)
lkb->lkb_rqmode = DLM_LOCK_PR;
else if (lkb->lkb_exflags & DLM_LKF_ALTCW)
lkb->lkb_rqmode = DLM_LOCK_CW;
else {
log_print("munge_altmode invalid exflags %x", lkb->lkb_exflags);
dlm_print_lkb(lkb);
}
}
static inline int first_in_list(struct dlm_lkb *lkb, struct list_head *head)
{
struct dlm_lkb *first = list_entry(head->next, struct dlm_lkb,
lkb_statequeue);
if (lkb->lkb_id == first->lkb_id)
return 1;
return 0;
}
static int queue_conflict(struct list_head *head, struct dlm_lkb *lkb)
{
struct dlm_lkb *this;
list_for_each_entry(this, head, lkb_statequeue) {
if (this == lkb)
continue;
if (!modes_compat(this, lkb))
return 1;
}
return 0;
}
static int conversion_deadlock_detect(struct dlm_rsb *r, struct dlm_lkb *lkb2)
{
struct dlm_lkb *lkb1;
int lkb_is_ahead = 0;
list_for_each_entry(lkb1, &r->res_convertqueue, lkb_statequeue) {
if (lkb1 == lkb2) {
lkb_is_ahead = 1;
continue;
}
if (!lkb_is_ahead) {
if (!modes_compat(lkb2, lkb1))
return 1;
} else {
if (!modes_compat(lkb2, lkb1) &&
!modes_compat(lkb1, lkb2))
return 1;
}
}
return 0;
}
static int _can_be_granted(struct dlm_rsb *r, struct dlm_lkb *lkb, int now,
int recover)
{
int8_t conv = (lkb->lkb_grmode != DLM_LOCK_IV);
if (lkb->lkb_exflags & DLM_LKF_EXPEDITE)
return 1;
if (queue_conflict(&r->res_grantqueue, lkb))
return 0;
if (queue_conflict(&r->res_convertqueue, lkb))
return 0;
if (conv && recover)
return 1;
if (now && conv && !(lkb->lkb_exflags & DLM_LKF_QUECVT))
return 1;
if (now && conv && (lkb->lkb_exflags & DLM_LKF_QUECVT)) {
if (list_empty(&r->res_convertqueue))
return 1;
else
return 0;
}
if (lkb->lkb_exflags & DLM_LKF_NOORDER)
return 1;
if (!now && conv && first_in_list(lkb, &r->res_convertqueue))
return 1;
if (now && !conv && list_empty(&r->res_convertqueue) &&
list_empty(&r->res_waitqueue))
return 1;
if (!now && !conv && list_empty(&r->res_convertqueue) &&
first_in_list(lkb, &r->res_waitqueue))
return 1;
return 0;
}
static int can_be_granted(struct dlm_rsb *r, struct dlm_lkb *lkb, int now,
int recover, int *err)
{
int rv;
int8_t alt = 0, rqmode = lkb->lkb_rqmode;
int8_t is_convert = (lkb->lkb_grmode != DLM_LOCK_IV);
if (err)
*err = 0;
rv = _can_be_granted(r, lkb, now, recover);
if (rv)
goto out;
if (is_convert && can_be_queued(lkb) &&
conversion_deadlock_detect(r, lkb)) {
if (lkb->lkb_exflags & DLM_LKF_CONVDEADLK) {
lkb->lkb_grmode = DLM_LOCK_NL;
lkb->lkb_sbflags |= DLM_SBF_DEMOTED;
} else if (!(lkb->lkb_exflags & DLM_LKF_NODLCKWT)) {
if (err)
*err = -EDEADLK;
else {
log_print("can_be_granted deadlock %x now %d",
lkb->lkb_id, now);
dlm_dump_rsb(r);
}
}
goto out;
}
if (rqmode != DLM_LOCK_PR && (lkb->lkb_exflags & DLM_LKF_ALTPR))
alt = DLM_LOCK_PR;
else if (rqmode != DLM_LOCK_CW && (lkb->lkb_exflags & DLM_LKF_ALTCW))
alt = DLM_LOCK_CW;
if (alt) {
lkb->lkb_rqmode = alt;
rv = _can_be_granted(r, lkb, now, 0);
if (rv)
lkb->lkb_sbflags |= DLM_SBF_ALTMODE;
else
lkb->lkb_rqmode = rqmode;
}
out:
return rv;
}
static int grant_pending_convert(struct dlm_rsb *r, int high, int *cw,
unsigned int *count)
{
struct dlm_lkb *lkb, *s;
int recover = rsb_flag(r, RSB_RECOVER_GRANT);
int hi, demoted, quit, grant_restart, demote_restart;
int deadlk;
quit = 0;
restart:
grant_restart = 0;
demote_restart = 0;
hi = DLM_LOCK_IV;
list_for_each_entry_safe(lkb, s, &r->res_convertqueue, lkb_statequeue) {
demoted = is_demoted(lkb);
deadlk = 0;
if (can_be_granted(r, lkb, 0, recover, &deadlk)) {
grant_lock_pending(r, lkb);
grant_restart = 1;
if (count)
(*count)++;
continue;
}
if (!demoted && is_demoted(lkb)) {
log_print("WARN: pending demoted %x node %d %s",
lkb->lkb_id, lkb->lkb_nodeid, r->res_name);
demote_restart = 1;
continue;
}
if (deadlk) {
log_print("WARN: pending deadlock %x node %d %s",
lkb->lkb_id, lkb->lkb_nodeid, r->res_name);
dlm_dump_rsb(r);
continue;
}
hi = max_t(int, lkb->lkb_rqmode, hi);
if (cw && lkb->lkb_rqmode == DLM_LOCK_CW)
*cw = 1;
}
if (grant_restart)
goto restart;
if (demote_restart && !quit) {
quit = 1;
goto restart;
}
return max_t(int, high, hi);
}
static int grant_pending_wait(struct dlm_rsb *r, int high, int *cw,
unsigned int *count)
{
struct dlm_lkb *lkb, *s;
list_for_each_entry_safe(lkb, s, &r->res_waitqueue, lkb_statequeue) {
if (can_be_granted(r, lkb, 0, 0, NULL)) {
grant_lock_pending(r, lkb);
if (count)
(*count)++;
} else {
high = max_t(int, lkb->lkb_rqmode, high);
if (lkb->lkb_rqmode == DLM_LOCK_CW)
*cw = 1;
}
}
return high;
}
static int lock_requires_bast(struct dlm_lkb *gr, int high, int cw)
{
if (gr->lkb_grmode == DLM_LOCK_PR && cw) {
if (gr->lkb_highbast < DLM_LOCK_EX)
return 1;
return 0;
}
if (gr->lkb_highbast < high &&
!__dlm_compat_matrix[gr->lkb_grmode+1][high+1])
return 1;
return 0;
}
static void grant_pending_locks(struct dlm_rsb *r, unsigned int *count)
{
struct dlm_lkb *lkb, *s;
int high = DLM_LOCK_IV;
int cw = 0;
if (!is_master(r)) {
log_print("grant_pending_locks r nodeid %d", r->res_nodeid);
dlm_dump_rsb(r);
return;
}
high = grant_pending_convert(r, high, &cw, count);
high = grant_pending_wait(r, high, &cw, count);
if (high == DLM_LOCK_IV)
return;
list_for_each_entry_safe(lkb, s, &r->res_grantqueue, lkb_statequeue) {
if (lkb->lkb_bastfn && lock_requires_bast(lkb, high, cw)) {
if (cw && high == DLM_LOCK_PR &&
lkb->lkb_grmode == DLM_LOCK_PR)
queue_bast(r, lkb, DLM_LOCK_CW);
else
queue_bast(r, lkb, high);
lkb->lkb_highbast = high;
}
}
}
static int modes_require_bast(struct dlm_lkb *gr, struct dlm_lkb *rq)
{
if ((gr->lkb_grmode == DLM_LOCK_PR && rq->lkb_rqmode == DLM_LOCK_CW) ||
(gr->lkb_grmode == DLM_LOCK_CW && rq->lkb_rqmode == DLM_LOCK_PR)) {
if (gr->lkb_highbast < DLM_LOCK_EX)
return 1;
return 0;
}
if (gr->lkb_highbast < rq->lkb_rqmode && !modes_compat(gr, rq))
return 1;
return 0;
}
static void send_bast_queue(struct dlm_rsb *r, struct list_head *head,
struct dlm_lkb *lkb)
{
struct dlm_lkb *gr;
list_for_each_entry(gr, head, lkb_statequeue) {
if (gr == lkb)
continue;
if (gr->lkb_bastfn && modes_require_bast(gr, lkb)) {
queue_bast(r, gr, lkb->lkb_rqmode);
gr->lkb_highbast = lkb->lkb_rqmode;
}
}
}
static void send_blocking_asts(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
send_bast_queue(r, &r->res_grantqueue, lkb);
}
static void send_blocking_asts_all(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
send_bast_queue(r, &r->res_grantqueue, lkb);
send_bast_queue(r, &r->res_convertqueue, lkb);
}
static int set_master(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
int our_nodeid = dlm_our_nodeid();
if (rsb_flag(r, RSB_MASTER_UNCERTAIN)) {
rsb_clear_flag(r, RSB_MASTER_UNCERTAIN);
r->res_first_lkid = lkb->lkb_id;
lkb->lkb_nodeid = r->res_nodeid;
return 0;
}
if (r->res_first_lkid && r->res_first_lkid != lkb->lkb_id) {
list_add_tail(&lkb->lkb_rsb_lookup, &r->res_lookup);
return 1;
}
if (r->res_master_nodeid == our_nodeid) {
lkb->lkb_nodeid = 0;
return 0;
}
if (r->res_master_nodeid) {
lkb->lkb_nodeid = r->res_master_nodeid;
return 0;
}
if (dlm_dir_nodeid(r) == our_nodeid) {
log_debug(r->res_ls, "set_master %x self master %d dir %d %s",
lkb->lkb_id, r->res_master_nodeid, r->res_dir_nodeid,
r->res_name);
r->res_master_nodeid = our_nodeid;
r->res_nodeid = 0;
lkb->lkb_nodeid = 0;
return 0;
}
wait_pending_remove(r);
r->res_first_lkid = lkb->lkb_id;
send_lookup(r, lkb);
return 1;
}
static void process_lookup_list(struct dlm_rsb *r)
{
struct dlm_lkb *lkb, *safe;
list_for_each_entry_safe(lkb, safe, &r->res_lookup, lkb_rsb_lookup) {
list_del_init(&lkb->lkb_rsb_lookup);
_request_lock(r, lkb);
schedule();
}
}
static void confirm_master(struct dlm_rsb *r, int error)
{
struct dlm_lkb *lkb;
if (!r->res_first_lkid)
return;
switch (error) {
case 0:
case -EINPROGRESS:
r->res_first_lkid = 0;
process_lookup_list(r);
break;
case -EAGAIN:
case -EBADR:
case -ENOTBLK:
r->res_first_lkid = 0;
if (!list_empty(&r->res_lookup)) {
lkb = list_entry(r->res_lookup.next, struct dlm_lkb,
lkb_rsb_lookup);
list_del_init(&lkb->lkb_rsb_lookup);
r->res_first_lkid = lkb->lkb_id;
_request_lock(r, lkb);
}
break;
default:
log_error(r->res_ls, "confirm_master unknown error %d", error);
}
}
static int set_lock_args(int mode, struct dlm_lksb *lksb, uint32_t flags,
int namelen, unsigned long timeout_cs,
void (*ast) (void *astparam),
void *astparam,
void (*bast) (void *astparam, int mode),
struct dlm_args *args)
{
int rv = -EINVAL;
if (mode < 0 || mode > DLM_LOCK_EX)
goto out;
if (!(flags & DLM_LKF_CONVERT) && (namelen > DLM_RESNAME_MAXLEN))
goto out;
if (flags & DLM_LKF_CANCEL)
goto out;
if (flags & DLM_LKF_QUECVT && !(flags & DLM_LKF_CONVERT))
goto out;
if (flags & DLM_LKF_CONVDEADLK && !(flags & DLM_LKF_CONVERT))
goto out;
if (flags & DLM_LKF_CONVDEADLK && flags & DLM_LKF_NOQUEUE)
goto out;
if (flags & DLM_LKF_EXPEDITE && flags & DLM_LKF_CONVERT)
goto out;
if (flags & DLM_LKF_EXPEDITE && flags & DLM_LKF_QUECVT)
goto out;
if (flags & DLM_LKF_EXPEDITE && flags & DLM_LKF_NOQUEUE)
goto out;
if (flags & DLM_LKF_EXPEDITE && mode != DLM_LOCK_NL)
goto out;
if (!ast || !lksb)
goto out;
if (flags & DLM_LKF_VALBLK && !lksb->sb_lvbptr)
goto out;
if (flags & DLM_LKF_CONVERT && !lksb->sb_lkid)
goto out;
args->flags = flags;
args->astfn = ast;
args->astparam = astparam;
args->bastfn = bast;
args->timeout = timeout_cs;
args->mode = mode;
args->lksb = lksb;
rv = 0;
out:
return rv;
}
static int set_unlock_args(uint32_t flags, void *astarg, struct dlm_args *args)
{
if (flags & ~(DLM_LKF_CANCEL | DLM_LKF_VALBLK | DLM_LKF_IVVALBLK |
DLM_LKF_FORCEUNLOCK))
return -EINVAL;
if (flags & DLM_LKF_CANCEL && flags & DLM_LKF_FORCEUNLOCK)
return -EINVAL;
args->flags = flags;
args->astparam = astarg;
return 0;
}
static int validate_lock_args(struct dlm_ls *ls, struct dlm_lkb *lkb,
struct dlm_args *args)
{
int rv = -EINVAL;
if (args->flags & DLM_LKF_CONVERT) {
if (lkb->lkb_flags & DLM_IFL_MSTCPY)
goto out;
if (args->flags & DLM_LKF_QUECVT &&
!__quecvt_compat_matrix[lkb->lkb_grmode+1][args->mode+1])
goto out;
rv = -EBUSY;
if (lkb->lkb_status != DLM_LKSTS_GRANTED)
goto out;
if (lkb->lkb_wait_type)
goto out;
if (is_overlap(lkb))
goto out;
}
lkb->lkb_exflags = args->flags;
lkb->lkb_sbflags = 0;
lkb->lkb_astfn = args->astfn;
lkb->lkb_astparam = args->astparam;
lkb->lkb_bastfn = args->bastfn;
lkb->lkb_rqmode = args->mode;
lkb->lkb_lksb = args->lksb;
lkb->lkb_lvbptr = args->lksb->sb_lvbptr;
lkb->lkb_ownpid = (int) current->pid;
lkb->lkb_timeout_cs = args->timeout;
rv = 0;
out:
if (rv)
log_debug(ls, "validate_lock_args %d %x %x %x %d %d %s",
rv, lkb->lkb_id, lkb->lkb_flags, args->flags,
lkb->lkb_status, lkb->lkb_wait_type,
lkb->lkb_resource->res_name);
return rv;
}
static int validate_unlock_args(struct dlm_lkb *lkb, struct dlm_args *args)
{
struct dlm_ls *ls = lkb->lkb_resource->res_ls;
int rv = -EINVAL;
if (lkb->lkb_flags & DLM_IFL_MSTCPY) {
log_error(ls, "unlock on MSTCPY %x", lkb->lkb_id);
dlm_print_lkb(lkb);
goto out;
}
if (lkb->lkb_flags & DLM_IFL_ENDOFLIFE) {
log_debug(ls, "unlock on ENDOFLIFE %x", lkb->lkb_id);
rv = -ENOENT;
goto out;
}
if (!list_empty(&lkb->lkb_rsb_lookup)) {
if (args->flags & (DLM_LKF_CANCEL | DLM_LKF_FORCEUNLOCK)) {
log_debug(ls, "unlock on rsb_lookup %x", lkb->lkb_id);
list_del_init(&lkb->lkb_rsb_lookup);
queue_cast(lkb->lkb_resource, lkb,
args->flags & DLM_LKF_CANCEL ?
-DLM_ECANCEL : -DLM_EUNLOCK);
unhold_lkb(lkb);
}
rv = -EBUSY;
goto out;
}
if (args->flags & DLM_LKF_CANCEL) {
if (lkb->lkb_exflags & DLM_LKF_CANCEL)
goto out;
if (is_overlap(lkb))
goto out;
del_timeout(lkb);
if (lkb->lkb_flags & DLM_IFL_RESEND) {
lkb->lkb_flags |= DLM_IFL_OVERLAP_CANCEL;
rv = -EBUSY;
goto out;
}
if (lkb->lkb_status == DLM_LKSTS_GRANTED &&
!lkb->lkb_wait_type) {
rv = -EBUSY;
goto out;
}
switch (lkb->lkb_wait_type) {
case DLM_MSG_LOOKUP:
case DLM_MSG_REQUEST:
lkb->lkb_flags |= DLM_IFL_OVERLAP_CANCEL;
rv = -EBUSY;
goto out;
case DLM_MSG_UNLOCK:
case DLM_MSG_CANCEL:
goto out;
}
goto out_ok;
}
if (args->flags & DLM_LKF_FORCEUNLOCK) {
if (lkb->lkb_exflags & DLM_LKF_FORCEUNLOCK)
goto out;
if (is_overlap_unlock(lkb))
goto out;
del_timeout(lkb);
if (lkb->lkb_flags & DLM_IFL_RESEND) {
lkb->lkb_flags |= DLM_IFL_OVERLAP_UNLOCK;
rv = -EBUSY;
goto out;
}
switch (lkb->lkb_wait_type) {
case DLM_MSG_LOOKUP:
case DLM_MSG_REQUEST:
lkb->lkb_flags |= DLM_IFL_OVERLAP_UNLOCK;
rv = -EBUSY;
goto out;
case DLM_MSG_UNLOCK:
goto out;
}
goto out_ok;
}
rv = -EBUSY;
if (lkb->lkb_wait_type || lkb->lkb_wait_count)
goto out;
out_ok:
lkb->lkb_exflags |= args->flags;
lkb->lkb_sbflags = 0;
lkb->lkb_astparam = args->astparam;
rv = 0;
out:
if (rv)
log_debug(ls, "validate_unlock_args %d %x %x %x %x %d %s", rv,
lkb->lkb_id, lkb->lkb_flags, lkb->lkb_exflags,
args->flags, lkb->lkb_wait_type,
lkb->lkb_resource->res_name);
return rv;
}
static int do_request(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
int error = 0;
if (can_be_granted(r, lkb, 1, 0, NULL)) {
grant_lock(r, lkb);
queue_cast(r, lkb, 0);
goto out;
}
if (can_be_queued(lkb)) {
error = -EINPROGRESS;
add_lkb(r, lkb, DLM_LKSTS_WAITING);
add_timeout(lkb);
goto out;
}
error = -EAGAIN;
queue_cast(r, lkb, -EAGAIN);
out:
return error;
}
static void do_request_effects(struct dlm_rsb *r, struct dlm_lkb *lkb,
int error)
{
switch (error) {
case -EAGAIN:
if (force_blocking_asts(lkb))
send_blocking_asts_all(r, lkb);
break;
case -EINPROGRESS:
send_blocking_asts(r, lkb);
break;
}
}
static int do_convert(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
int error = 0;
int deadlk = 0;
if (can_be_granted(r, lkb, 1, 0, &deadlk)) {
grant_lock(r, lkb);
queue_cast(r, lkb, 0);
goto out;
}
if (deadlk) {
revert_lock(r, lkb);
queue_cast(r, lkb, -EDEADLK);
error = -EDEADLK;
goto out;
}
if (is_demoted(lkb)) {
grant_pending_convert(r, DLM_LOCK_IV, NULL, NULL);
if (_can_be_granted(r, lkb, 1, 0)) {
grant_lock(r, lkb);
queue_cast(r, lkb, 0);
goto out;
}
}
if (can_be_queued(lkb)) {
error = -EINPROGRESS;
del_lkb(r, lkb);
add_lkb(r, lkb, DLM_LKSTS_CONVERT);
add_timeout(lkb);
goto out;
}
error = -EAGAIN;
queue_cast(r, lkb, -EAGAIN);
out:
return error;
}
static void do_convert_effects(struct dlm_rsb *r, struct dlm_lkb *lkb,
int error)
{
switch (error) {
case 0:
grant_pending_locks(r, NULL);
break;
case -EAGAIN:
if (force_blocking_asts(lkb))
send_blocking_asts_all(r, lkb);
break;
case -EINPROGRESS:
send_blocking_asts(r, lkb);
break;
}
}
static int do_unlock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
remove_lock(r, lkb);
queue_cast(r, lkb, -DLM_EUNLOCK);
return -DLM_EUNLOCK;
}
static void do_unlock_effects(struct dlm_rsb *r, struct dlm_lkb *lkb,
int error)
{
grant_pending_locks(r, NULL);
}
static int do_cancel(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
int error;
error = revert_lock(r, lkb);
if (error) {
queue_cast(r, lkb, -DLM_ECANCEL);
return -DLM_ECANCEL;
}
return 0;
}
static void do_cancel_effects(struct dlm_rsb *r, struct dlm_lkb *lkb,
int error)
{
if (error)
grant_pending_locks(r, NULL);
}
static int _request_lock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
int error;
error = set_master(r, lkb);
if (error < 0)
goto out;
if (error) {
error = 0;
goto out;
}
if (is_remote(r)) {
error = send_request(r, lkb);
} else {
error = do_request(r, lkb);
do_request_effects(r, lkb, error);
}
out:
return error;
}
static int _convert_lock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
int error;
if (is_remote(r)) {
error = send_convert(r, lkb);
} else {
error = do_convert(r, lkb);
do_convert_effects(r, lkb, error);
}
return error;
}
static int _unlock_lock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
int error;
if (is_remote(r)) {
error = send_unlock(r, lkb);
} else {
error = do_unlock(r, lkb);
do_unlock_effects(r, lkb, error);
}
return error;
}
static int _cancel_lock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
int error;
if (is_remote(r)) {
error = send_cancel(r, lkb);
} else {
error = do_cancel(r, lkb);
do_cancel_effects(r, lkb, error);
}
return error;
}
static int request_lock(struct dlm_ls *ls, struct dlm_lkb *lkb, char *name,
int len, struct dlm_args *args)
{
struct dlm_rsb *r;
int error;
error = validate_lock_args(ls, lkb, args);
if (error)
return error;
error = find_rsb(ls, name, len, 0, R_REQUEST, &r);
if (error)
return error;
lock_rsb(r);
attach_lkb(r, lkb);
lkb->lkb_lksb->sb_lkid = lkb->lkb_id;
error = _request_lock(r, lkb);
unlock_rsb(r);
put_rsb(r);
return error;
}
static int convert_lock(struct dlm_ls *ls, struct dlm_lkb *lkb,
struct dlm_args *args)
{
struct dlm_rsb *r;
int error;
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
error = validate_lock_args(ls, lkb, args);
if (error)
goto out;
error = _convert_lock(r, lkb);
out:
unlock_rsb(r);
put_rsb(r);
return error;
}
static int unlock_lock(struct dlm_ls *ls, struct dlm_lkb *lkb,
struct dlm_args *args)
{
struct dlm_rsb *r;
int error;
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
error = validate_unlock_args(lkb, args);
if (error)
goto out;
error = _unlock_lock(r, lkb);
out:
unlock_rsb(r);
put_rsb(r);
return error;
}
static int cancel_lock(struct dlm_ls *ls, struct dlm_lkb *lkb,
struct dlm_args *args)
{
struct dlm_rsb *r;
int error;
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
error = validate_unlock_args(lkb, args);
if (error)
goto out;
error = _cancel_lock(r, lkb);
out:
unlock_rsb(r);
put_rsb(r);
return error;
}
int dlm_lock(dlm_lockspace_t *lockspace,
int mode,
struct dlm_lksb *lksb,
uint32_t flags,
void *name,
unsigned int namelen,
uint32_t parent_lkid,
void (*ast) (void *astarg),
void *astarg,
void (*bast) (void *astarg, int mode))
{
struct dlm_ls *ls;
struct dlm_lkb *lkb;
struct dlm_args args;
int error, convert = flags & DLM_LKF_CONVERT;
ls = dlm_find_lockspace_local(lockspace);
if (!ls)
return -EINVAL;
dlm_lock_recovery(ls);
if (convert)
error = find_lkb(ls, lksb->sb_lkid, &lkb);
else
error = create_lkb(ls, &lkb);
if (error)
goto out;
error = set_lock_args(mode, lksb, flags, namelen, 0, ast,
astarg, bast, &args);
if (error)
goto out_put;
if (convert)
error = convert_lock(ls, lkb, &args);
else
error = request_lock(ls, lkb, name, namelen, &args);
if (error == -EINPROGRESS)
error = 0;
out_put:
if (convert || error)
__put_lkb(ls, lkb);
if (error == -EAGAIN || error == -EDEADLK)
error = 0;
out:
dlm_unlock_recovery(ls);
dlm_put_lockspace(ls);
return error;
}
int dlm_unlock(dlm_lockspace_t *lockspace,
uint32_t lkid,
uint32_t flags,
struct dlm_lksb *lksb,
void *astarg)
{
struct dlm_ls *ls;
struct dlm_lkb *lkb;
struct dlm_args args;
int error;
ls = dlm_find_lockspace_local(lockspace);
if (!ls)
return -EINVAL;
dlm_lock_recovery(ls);
error = find_lkb(ls, lkid, &lkb);
if (error)
goto out;
error = set_unlock_args(flags, astarg, &args);
if (error)
goto out_put;
if (flags & DLM_LKF_CANCEL)
error = cancel_lock(ls, lkb, &args);
else
error = unlock_lock(ls, lkb, &args);
if (error == -DLM_EUNLOCK || error == -DLM_ECANCEL)
error = 0;
if (error == -EBUSY && (flags & (DLM_LKF_CANCEL | DLM_LKF_FORCEUNLOCK)))
error = 0;
out_put:
dlm_put_lkb(lkb);
out:
dlm_unlock_recovery(ls);
dlm_put_lockspace(ls);
return error;
}
static int _create_message(struct dlm_ls *ls, int mb_len,
int to_nodeid, int mstype,
struct dlm_message **ms_ret,
struct dlm_mhandle **mh_ret)
{
struct dlm_message *ms;
struct dlm_mhandle *mh;
char *mb;
mh = dlm_lowcomms_get_buffer(to_nodeid, mb_len, GFP_NOFS, &mb);
if (!mh)
return -ENOBUFS;
memset(mb, 0, mb_len);
ms = (struct dlm_message *) mb;
ms->m_header.h_version = (DLM_HEADER_MAJOR | DLM_HEADER_MINOR);
ms->m_header.h_lockspace = ls->ls_global_id;
ms->m_header.h_nodeid = dlm_our_nodeid();
ms->m_header.h_length = mb_len;
ms->m_header.h_cmd = DLM_MSG;
ms->m_type = mstype;
*mh_ret = mh;
*ms_ret = ms;
return 0;
}
static int create_message(struct dlm_rsb *r, struct dlm_lkb *lkb,
int to_nodeid, int mstype,
struct dlm_message **ms_ret,
struct dlm_mhandle **mh_ret)
{
int mb_len = sizeof(struct dlm_message);
switch (mstype) {
case DLM_MSG_REQUEST:
case DLM_MSG_LOOKUP:
case DLM_MSG_REMOVE:
mb_len += r->res_length;
break;
case DLM_MSG_CONVERT:
case DLM_MSG_UNLOCK:
case DLM_MSG_REQUEST_REPLY:
case DLM_MSG_CONVERT_REPLY:
case DLM_MSG_GRANT:
if (lkb && lkb->lkb_lvbptr)
mb_len += r->res_ls->ls_lvblen;
break;
}
return _create_message(r->res_ls, mb_len, to_nodeid, mstype,
ms_ret, mh_ret);
}
static int send_message(struct dlm_mhandle *mh, struct dlm_message *ms)
{
dlm_message_out(ms);
dlm_lowcomms_commit_buffer(mh);
return 0;
}
static void send_args(struct dlm_rsb *r, struct dlm_lkb *lkb,
struct dlm_message *ms)
{
ms->m_nodeid = lkb->lkb_nodeid;
ms->m_pid = lkb->lkb_ownpid;
ms->m_lkid = lkb->lkb_id;
ms->m_remid = lkb->lkb_remid;
ms->m_exflags = lkb->lkb_exflags;
ms->m_sbflags = lkb->lkb_sbflags;
ms->m_flags = lkb->lkb_flags;
ms->m_lvbseq = lkb->lkb_lvbseq;
ms->m_status = lkb->lkb_status;
ms->m_grmode = lkb->lkb_grmode;
ms->m_rqmode = lkb->lkb_rqmode;
ms->m_hash = r->res_hash;
if (lkb->lkb_bastfn)
ms->m_asts |= DLM_CB_BAST;
if (lkb->lkb_astfn)
ms->m_asts |= DLM_CB_CAST;
switch (ms->m_type) {
case DLM_MSG_REQUEST:
case DLM_MSG_LOOKUP:
memcpy(ms->m_extra, r->res_name, r->res_length);
break;
case DLM_MSG_CONVERT:
case DLM_MSG_UNLOCK:
case DLM_MSG_REQUEST_REPLY:
case DLM_MSG_CONVERT_REPLY:
case DLM_MSG_GRANT:
if (!lkb->lkb_lvbptr)
break;
memcpy(ms->m_extra, lkb->lkb_lvbptr, r->res_ls->ls_lvblen);
break;
}
}
static int send_common(struct dlm_rsb *r, struct dlm_lkb *lkb, int mstype)
{
struct dlm_message *ms;
struct dlm_mhandle *mh;
int to_nodeid, error;
to_nodeid = r->res_nodeid;
error = add_to_waiters(lkb, mstype, to_nodeid);
if (error)
return error;
error = create_message(r, lkb, to_nodeid, mstype, &ms, &mh);
if (error)
goto fail;
send_args(r, lkb, ms);
error = send_message(mh, ms);
if (error)
goto fail;
return 0;
fail:
remove_from_waiters(lkb, msg_reply_type(mstype));
return error;
}
static int send_request(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
return send_common(r, lkb, DLM_MSG_REQUEST);
}
static int send_convert(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
int error;
error = send_common(r, lkb, DLM_MSG_CONVERT);
if (!error && down_conversion(lkb)) {
remove_from_waiters(lkb, DLM_MSG_CONVERT_REPLY);
r->res_ls->ls_stub_ms.m_flags = DLM_IFL_STUB_MS;
r->res_ls->ls_stub_ms.m_type = DLM_MSG_CONVERT_REPLY;
r->res_ls->ls_stub_ms.m_result = 0;
__receive_convert_reply(r, lkb, &r->res_ls->ls_stub_ms);
}
return error;
}
static int send_unlock(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
return send_common(r, lkb, DLM_MSG_UNLOCK);
}
static int send_cancel(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
return send_common(r, lkb, DLM_MSG_CANCEL);
}
static int send_grant(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
struct dlm_message *ms;
struct dlm_mhandle *mh;
int to_nodeid, error;
to_nodeid = lkb->lkb_nodeid;
error = create_message(r, lkb, to_nodeid, DLM_MSG_GRANT, &ms, &mh);
if (error)
goto out;
send_args(r, lkb, ms);
ms->m_result = 0;
error = send_message(mh, ms);
out:
return error;
}
static int send_bast(struct dlm_rsb *r, struct dlm_lkb *lkb, int mode)
{
struct dlm_message *ms;
struct dlm_mhandle *mh;
int to_nodeid, error;
to_nodeid = lkb->lkb_nodeid;
error = create_message(r, NULL, to_nodeid, DLM_MSG_BAST, &ms, &mh);
if (error)
goto out;
send_args(r, lkb, ms);
ms->m_bastmode = mode;
error = send_message(mh, ms);
out:
return error;
}
static int send_lookup(struct dlm_rsb *r, struct dlm_lkb *lkb)
{
struct dlm_message *ms;
struct dlm_mhandle *mh;
int to_nodeid, error;
to_nodeid = dlm_dir_nodeid(r);
error = add_to_waiters(lkb, DLM_MSG_LOOKUP, to_nodeid);
if (error)
return error;
error = create_message(r, NULL, to_nodeid, DLM_MSG_LOOKUP, &ms, &mh);
if (error)
goto fail;
send_args(r, lkb, ms);
error = send_message(mh, ms);
if (error)
goto fail;
return 0;
fail:
remove_from_waiters(lkb, DLM_MSG_LOOKUP_REPLY);
return error;
}
static int send_remove(struct dlm_rsb *r)
{
struct dlm_message *ms;
struct dlm_mhandle *mh;
int to_nodeid, error;
to_nodeid = dlm_dir_nodeid(r);
error = create_message(r, NULL, to_nodeid, DLM_MSG_REMOVE, &ms, &mh);
if (error)
goto out;
memcpy(ms->m_extra, r->res_name, r->res_length);
ms->m_hash = r->res_hash;
error = send_message(mh, ms);
out:
return error;
}
static int send_common_reply(struct dlm_rsb *r, struct dlm_lkb *lkb,
int mstype, int rv)
{
struct dlm_message *ms;
struct dlm_mhandle *mh;
int to_nodeid, error;
to_nodeid = lkb->lkb_nodeid;
error = create_message(r, lkb, to_nodeid, mstype, &ms, &mh);
if (error)
goto out;
send_args(r, lkb, ms);
ms->m_result = rv;
error = send_message(mh, ms);
out:
return error;
}
static int send_request_reply(struct dlm_rsb *r, struct dlm_lkb *lkb, int rv)
{
return send_common_reply(r, lkb, DLM_MSG_REQUEST_REPLY, rv);
}
static int send_convert_reply(struct dlm_rsb *r, struct dlm_lkb *lkb, int rv)
{
return send_common_reply(r, lkb, DLM_MSG_CONVERT_REPLY, rv);
}
static int send_unlock_reply(struct dlm_rsb *r, struct dlm_lkb *lkb, int rv)
{
return send_common_reply(r, lkb, DLM_MSG_UNLOCK_REPLY, rv);
}
static int send_cancel_reply(struct dlm_rsb *r, struct dlm_lkb *lkb, int rv)
{
return send_common_reply(r, lkb, DLM_MSG_CANCEL_REPLY, rv);
}
static int send_lookup_reply(struct dlm_ls *ls, struct dlm_message *ms_in,
int ret_nodeid, int rv)
{
struct dlm_rsb *r = &ls->ls_stub_rsb;
struct dlm_message *ms;
struct dlm_mhandle *mh;
int error, nodeid = ms_in->m_header.h_nodeid;
error = create_message(r, NULL, nodeid, DLM_MSG_LOOKUP_REPLY, &ms, &mh);
if (error)
goto out;
ms->m_lkid = ms_in->m_lkid;
ms->m_result = rv;
ms->m_nodeid = ret_nodeid;
error = send_message(mh, ms);
out:
return error;
}
static void receive_flags(struct dlm_lkb *lkb, struct dlm_message *ms)
{
lkb->lkb_exflags = ms->m_exflags;
lkb->lkb_sbflags = ms->m_sbflags;
lkb->lkb_flags = (lkb->lkb_flags & 0xFFFF0000) |
(ms->m_flags & 0x0000FFFF);
}
static void receive_flags_reply(struct dlm_lkb *lkb, struct dlm_message *ms)
{
if (ms->m_flags == DLM_IFL_STUB_MS)
return;
lkb->lkb_sbflags = ms->m_sbflags;
lkb->lkb_flags = (lkb->lkb_flags & 0xFFFF0000) |
(ms->m_flags & 0x0000FFFF);
}
static int receive_extralen(struct dlm_message *ms)
{
return (ms->m_header.h_length - sizeof(struct dlm_message));
}
static int receive_lvb(struct dlm_ls *ls, struct dlm_lkb *lkb,
struct dlm_message *ms)
{
int len;
if (lkb->lkb_exflags & DLM_LKF_VALBLK) {
if (!lkb->lkb_lvbptr)
lkb->lkb_lvbptr = dlm_allocate_lvb(ls);
if (!lkb->lkb_lvbptr)
return -ENOMEM;
len = receive_extralen(ms);
if (len > ls->ls_lvblen)
len = ls->ls_lvblen;
memcpy(lkb->lkb_lvbptr, ms->m_extra, len);
}
return 0;
}
static void fake_bastfn(void *astparam, int mode)
{
log_print("fake_bastfn should not be called");
}
static void fake_astfn(void *astparam)
{
log_print("fake_astfn should not be called");
}
static int receive_request_args(struct dlm_ls *ls, struct dlm_lkb *lkb,
struct dlm_message *ms)
{
lkb->lkb_nodeid = ms->m_header.h_nodeid;
lkb->lkb_ownpid = ms->m_pid;
lkb->lkb_remid = ms->m_lkid;
lkb->lkb_grmode = DLM_LOCK_IV;
lkb->lkb_rqmode = ms->m_rqmode;
lkb->lkb_bastfn = (ms->m_asts & DLM_CB_BAST) ? &fake_bastfn : NULL;
lkb->lkb_astfn = (ms->m_asts & DLM_CB_CAST) ? &fake_astfn : NULL;
if (lkb->lkb_exflags & DLM_LKF_VALBLK) {
lkb->lkb_lvbptr = dlm_allocate_lvb(ls);
if (!lkb->lkb_lvbptr)
return -ENOMEM;
}
return 0;
}
static int receive_convert_args(struct dlm_ls *ls, struct dlm_lkb *lkb,
struct dlm_message *ms)
{
if (lkb->lkb_status != DLM_LKSTS_GRANTED)
return -EBUSY;
if (receive_lvb(ls, lkb, ms))
return -ENOMEM;
lkb->lkb_rqmode = ms->m_rqmode;
lkb->lkb_lvbseq = ms->m_lvbseq;
return 0;
}
static int receive_unlock_args(struct dlm_ls *ls, struct dlm_lkb *lkb,
struct dlm_message *ms)
{
if (receive_lvb(ls, lkb, ms))
return -ENOMEM;
return 0;
}
static void setup_stub_lkb(struct dlm_ls *ls, struct dlm_message *ms)
{
struct dlm_lkb *lkb = &ls->ls_stub_lkb;
lkb->lkb_nodeid = ms->m_header.h_nodeid;
lkb->lkb_remid = ms->m_lkid;
}
static int validate_message(struct dlm_lkb *lkb, struct dlm_message *ms)
{
int from = ms->m_header.h_nodeid;
int error = 0;
switch (ms->m_type) {
case DLM_MSG_CONVERT:
case DLM_MSG_UNLOCK:
case DLM_MSG_CANCEL:
if (!is_master_copy(lkb) || lkb->lkb_nodeid != from)
error = -EINVAL;
break;
case DLM_MSG_CONVERT_REPLY:
case DLM_MSG_UNLOCK_REPLY:
case DLM_MSG_CANCEL_REPLY:
case DLM_MSG_GRANT:
case DLM_MSG_BAST:
if (!is_process_copy(lkb) || lkb->lkb_nodeid != from)
error = -EINVAL;
break;
case DLM_MSG_REQUEST_REPLY:
if (!is_process_copy(lkb))
error = -EINVAL;
else if (lkb->lkb_nodeid != -1 && lkb->lkb_nodeid != from)
error = -EINVAL;
break;
default:
error = -EINVAL;
}
if (error)
log_error(lkb->lkb_resource->res_ls,
"ignore invalid message %d from %d %x %x %x %d",
ms->m_type, from, lkb->lkb_id, lkb->lkb_remid,
lkb->lkb_flags, lkb->lkb_nodeid);
return error;
}
static void send_repeat_remove(struct dlm_ls *ls, char *ms_name, int len)
{
char name[DLM_RESNAME_MAXLEN + 1];
struct dlm_message *ms;
struct dlm_mhandle *mh;
struct dlm_rsb *r;
uint32_t hash, b;
int rv, dir_nodeid;
memset(name, 0, sizeof(name));
memcpy(name, ms_name, len);
hash = jhash(name, len, 0);
b = hash & (ls->ls_rsbtbl_size - 1);
dir_nodeid = dlm_hash2nodeid(ls, hash);
log_error(ls, "send_repeat_remove dir %d %s", dir_nodeid, name);
spin_lock(&ls->ls_rsbtbl[b].lock);
rv = dlm_search_rsb_tree(&ls->ls_rsbtbl[b].keep, name, len, &r);
if (!rv) {
spin_unlock(&ls->ls_rsbtbl[b].lock);
log_error(ls, "repeat_remove on keep %s", name);
return;
}
rv = dlm_search_rsb_tree(&ls->ls_rsbtbl[b].toss, name, len, &r);
if (!rv) {
spin_unlock(&ls->ls_rsbtbl[b].lock);
log_error(ls, "repeat_remove on toss %s", name);
return;
}
spin_lock(&ls->ls_remove_spin);
ls->ls_remove_len = len;
memcpy(ls->ls_remove_name, name, DLM_RESNAME_MAXLEN);
spin_unlock(&ls->ls_remove_spin);
spin_unlock(&ls->ls_rsbtbl[b].lock);
rv = _create_message(ls, sizeof(struct dlm_message) + len,
dir_nodeid, DLM_MSG_REMOVE, &ms, &mh);
if (rv)
return;
memcpy(ms->m_extra, name, len);
ms->m_hash = hash;
send_message(mh, ms);
spin_lock(&ls->ls_remove_spin);
ls->ls_remove_len = 0;
memset(ls->ls_remove_name, 0, DLM_RESNAME_MAXLEN);
spin_unlock(&ls->ls_remove_spin);
}
static int receive_request(struct dlm_ls *ls, struct dlm_message *ms)
{
struct dlm_lkb *lkb;
struct dlm_rsb *r;
int from_nodeid;
int error, namelen = 0;
from_nodeid = ms->m_header.h_nodeid;
error = create_lkb(ls, &lkb);
if (error)
goto fail;
receive_flags(lkb, ms);
lkb->lkb_flags |= DLM_IFL_MSTCPY;
error = receive_request_args(ls, lkb, ms);
if (error) {
__put_lkb(ls, lkb);
goto fail;
}
namelen = receive_extralen(ms);
error = find_rsb(ls, ms->m_extra, namelen, from_nodeid,
R_RECEIVE_REQUEST, &r);
if (error) {
__put_lkb(ls, lkb);
goto fail;
}
lock_rsb(r);
if (r->res_master_nodeid != dlm_our_nodeid()) {
error = validate_master_nodeid(ls, r, from_nodeid);
if (error) {
unlock_rsb(r);
put_rsb(r);
__put_lkb(ls, lkb);
goto fail;
}
}
attach_lkb(r, lkb);
error = do_request(r, lkb);
send_request_reply(r, lkb, error);
do_request_effects(r, lkb, error);
unlock_rsb(r);
put_rsb(r);
if (error == -EINPROGRESS)
error = 0;
if (error)
dlm_put_lkb(lkb);
return 0;
fail:
if (error != -ENOTBLK) {
log_limit(ls, "receive_request %x from %d %d",
ms->m_lkid, from_nodeid, error);
}
if (namelen && error == -EBADR) {
send_repeat_remove(ls, ms->m_extra, namelen);
msleep(1000);
}
setup_stub_lkb(ls, ms);
send_request_reply(&ls->ls_stub_rsb, &ls->ls_stub_lkb, error);
return error;
}
static int receive_convert(struct dlm_ls *ls, struct dlm_message *ms)
{
struct dlm_lkb *lkb;
struct dlm_rsb *r;
int error, reply = 1;
error = find_lkb(ls, ms->m_remid, &lkb);
if (error)
goto fail;
if (lkb->lkb_remid != ms->m_lkid) {
log_error(ls, "receive_convert %x remid %x recover_seq %llu "
"remote %d %x", lkb->lkb_id, lkb->lkb_remid,
(unsigned long long)lkb->lkb_recover_seq,
ms->m_header.h_nodeid, ms->m_lkid);
error = -ENOENT;
goto fail;
}
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
error = validate_message(lkb, ms);
if (error)
goto out;
receive_flags(lkb, ms);
error = receive_convert_args(ls, lkb, ms);
if (error) {
send_convert_reply(r, lkb, error);
goto out;
}
reply = !down_conversion(lkb);
error = do_convert(r, lkb);
if (reply)
send_convert_reply(r, lkb, error);
do_convert_effects(r, lkb, error);
out:
unlock_rsb(r);
put_rsb(r);
dlm_put_lkb(lkb);
return 0;
fail:
setup_stub_lkb(ls, ms);
send_convert_reply(&ls->ls_stub_rsb, &ls->ls_stub_lkb, error);
return error;
}
static int receive_unlock(struct dlm_ls *ls, struct dlm_message *ms)
{
struct dlm_lkb *lkb;
struct dlm_rsb *r;
int error;
error = find_lkb(ls, ms->m_remid, &lkb);
if (error)
goto fail;
if (lkb->lkb_remid != ms->m_lkid) {
log_error(ls, "receive_unlock %x remid %x remote %d %x",
lkb->lkb_id, lkb->lkb_remid,
ms->m_header.h_nodeid, ms->m_lkid);
error = -ENOENT;
goto fail;
}
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
error = validate_message(lkb, ms);
if (error)
goto out;
receive_flags(lkb, ms);
error = receive_unlock_args(ls, lkb, ms);
if (error) {
send_unlock_reply(r, lkb, error);
goto out;
}
error = do_unlock(r, lkb);
send_unlock_reply(r, lkb, error);
do_unlock_effects(r, lkb, error);
out:
unlock_rsb(r);
put_rsb(r);
dlm_put_lkb(lkb);
return 0;
fail:
setup_stub_lkb(ls, ms);
send_unlock_reply(&ls->ls_stub_rsb, &ls->ls_stub_lkb, error);
return error;
}
static int receive_cancel(struct dlm_ls *ls, struct dlm_message *ms)
{
struct dlm_lkb *lkb;
struct dlm_rsb *r;
int error;
error = find_lkb(ls, ms->m_remid, &lkb);
if (error)
goto fail;
receive_flags(lkb, ms);
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
error = validate_message(lkb, ms);
if (error)
goto out;
error = do_cancel(r, lkb);
send_cancel_reply(r, lkb, error);
do_cancel_effects(r, lkb, error);
out:
unlock_rsb(r);
put_rsb(r);
dlm_put_lkb(lkb);
return 0;
fail:
setup_stub_lkb(ls, ms);
send_cancel_reply(&ls->ls_stub_rsb, &ls->ls_stub_lkb, error);
return error;
}
static int receive_grant(struct dlm_ls *ls, struct dlm_message *ms)
{
struct dlm_lkb *lkb;
struct dlm_rsb *r;
int error;
error = find_lkb(ls, ms->m_remid, &lkb);
if (error)
return error;
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
error = validate_message(lkb, ms);
if (error)
goto out;
receive_flags_reply(lkb, ms);
if (is_altmode(lkb))
munge_altmode(lkb, ms);
grant_lock_pc(r, lkb, ms);
queue_cast(r, lkb, 0);
out:
unlock_rsb(r);
put_rsb(r);
dlm_put_lkb(lkb);
return 0;
}
static int receive_bast(struct dlm_ls *ls, struct dlm_message *ms)
{
struct dlm_lkb *lkb;
struct dlm_rsb *r;
int error;
error = find_lkb(ls, ms->m_remid, &lkb);
if (error)
return error;
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
error = validate_message(lkb, ms);
if (error)
goto out;
queue_bast(r, lkb, ms->m_bastmode);
lkb->lkb_highbast = ms->m_bastmode;
out:
unlock_rsb(r);
put_rsb(r);
dlm_put_lkb(lkb);
return 0;
}
static void receive_lookup(struct dlm_ls *ls, struct dlm_message *ms)
{
int len, error, ret_nodeid, from_nodeid, our_nodeid;
from_nodeid = ms->m_header.h_nodeid;
our_nodeid = dlm_our_nodeid();
len = receive_extralen(ms);
error = dlm_master_lookup(ls, from_nodeid, ms->m_extra, len, 0,
&ret_nodeid, NULL);
if (!error && ret_nodeid == our_nodeid) {
receive_request(ls, ms);
return;
}
send_lookup_reply(ls, ms, ret_nodeid, error);
}
static void receive_remove(struct dlm_ls *ls, struct dlm_message *ms)
{
char name[DLM_RESNAME_MAXLEN+1];
struct dlm_rsb *r;
uint32_t hash, b;
int rv, len, dir_nodeid, from_nodeid;
from_nodeid = ms->m_header.h_nodeid;
len = receive_extralen(ms);
if (len > DLM_RESNAME_MAXLEN) {
log_error(ls, "receive_remove from %d bad len %d",
from_nodeid, len);
return;
}
dir_nodeid = dlm_hash2nodeid(ls, ms->m_hash);
if (dir_nodeid != dlm_our_nodeid()) {
log_error(ls, "receive_remove from %d bad nodeid %d",
from_nodeid, dir_nodeid);
return;
}
memset(name, 0, sizeof(name));
memcpy(name, ms->m_extra, len);
hash = jhash(name, len, 0);
b = hash & (ls->ls_rsbtbl_size - 1);
spin_lock(&ls->ls_rsbtbl[b].lock);
rv = dlm_search_rsb_tree(&ls->ls_rsbtbl[b].toss, name, len, &r);
if (rv) {
rv = dlm_search_rsb_tree(&ls->ls_rsbtbl[b].keep, name, len, &r);
if (rv) {
log_error(ls, "receive_remove from %d not found %s",
from_nodeid, name);
spin_unlock(&ls->ls_rsbtbl[b].lock);
return;
}
if (r->res_master_nodeid != from_nodeid) {
log_error(ls, "receive_remove keep from %d master %d",
from_nodeid, r->res_master_nodeid);
dlm_print_rsb(r);
spin_unlock(&ls->ls_rsbtbl[b].lock);
return;
}
log_debug(ls, "receive_remove from %d master %d first %x %s",
from_nodeid, r->res_master_nodeid, r->res_first_lkid,
name);
spin_unlock(&ls->ls_rsbtbl[b].lock);
return;
}
if (r->res_master_nodeid != from_nodeid) {
log_error(ls, "receive_remove toss from %d master %d",
from_nodeid, r->res_master_nodeid);
dlm_print_rsb(r);
spin_unlock(&ls->ls_rsbtbl[b].lock);
return;
}
if (kref_put(&r->res_ref, kill_rsb)) {
rb_erase(&r->res_hashnode, &ls->ls_rsbtbl[b].toss);
spin_unlock(&ls->ls_rsbtbl[b].lock);
dlm_free_rsb(r);
} else {
log_error(ls, "receive_remove from %d rsb ref error",
from_nodeid);
dlm_print_rsb(r);
spin_unlock(&ls->ls_rsbtbl[b].lock);
}
}
static void receive_purge(struct dlm_ls *ls, struct dlm_message *ms)
{
do_purge(ls, ms->m_nodeid, ms->m_pid);
}
static int receive_request_reply(struct dlm_ls *ls, struct dlm_message *ms)
{
struct dlm_lkb *lkb;
struct dlm_rsb *r;
int error, mstype, result;
int from_nodeid = ms->m_header.h_nodeid;
error = find_lkb(ls, ms->m_remid, &lkb);
if (error)
return error;
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
error = validate_message(lkb, ms);
if (error)
goto out;
mstype = lkb->lkb_wait_type;
error = remove_from_waiters(lkb, DLM_MSG_REQUEST_REPLY);
if (error) {
log_error(ls, "receive_request_reply %x remote %d %x result %d",
lkb->lkb_id, from_nodeid, ms->m_lkid, ms->m_result);
dlm_dump_rsb(r);
goto out;
}
if (mstype == DLM_MSG_LOOKUP) {
r->res_master_nodeid = from_nodeid;
r->res_nodeid = from_nodeid;
lkb->lkb_nodeid = from_nodeid;
}
result = ms->m_result;
switch (result) {
case -EAGAIN:
queue_cast(r, lkb, -EAGAIN);
confirm_master(r, -EAGAIN);
unhold_lkb(lkb);
break;
case -EINPROGRESS:
case 0:
receive_flags_reply(lkb, ms);
lkb->lkb_remid = ms->m_lkid;
if (is_altmode(lkb))
munge_altmode(lkb, ms);
if (result) {
add_lkb(r, lkb, DLM_LKSTS_WAITING);
add_timeout(lkb);
} else {
grant_lock_pc(r, lkb, ms);
queue_cast(r, lkb, 0);
}
confirm_master(r, result);
break;
case -EBADR:
case -ENOTBLK:
log_limit(ls, "receive_request_reply %x from %d %d "
"master %d dir %d first %x %s", lkb->lkb_id,
from_nodeid, result, r->res_master_nodeid,
r->res_dir_nodeid, r->res_first_lkid, r->res_name);
if (r->res_dir_nodeid != dlm_our_nodeid() &&
r->res_master_nodeid != dlm_our_nodeid()) {
r->res_master_nodeid = 0;
r->res_nodeid = -1;
lkb->lkb_nodeid = -1;
}
if (is_overlap(lkb)) {
queue_cast_overlap(r, lkb);
confirm_master(r, result);
unhold_lkb(lkb);
} else {
_request_lock(r, lkb);
if (r->res_master_nodeid == dlm_our_nodeid())
confirm_master(r, 0);
}
break;
default:
log_error(ls, "receive_request_reply %x error %d",
lkb->lkb_id, result);
}
if (is_overlap_unlock(lkb) && (result == 0 || result == -EINPROGRESS)) {
log_debug(ls, "receive_request_reply %x result %d unlock",
lkb->lkb_id, result);
lkb->lkb_flags &= ~DLM_IFL_OVERLAP_UNLOCK;
lkb->lkb_flags &= ~DLM_IFL_OVERLAP_CANCEL;
send_unlock(r, lkb);
} else if (is_overlap_cancel(lkb) && (result == -EINPROGRESS)) {
log_debug(ls, "receive_request_reply %x cancel", lkb->lkb_id);
lkb->lkb_flags &= ~DLM_IFL_OVERLAP_UNLOCK;
lkb->lkb_flags &= ~DLM_IFL_OVERLAP_CANCEL;
send_cancel(r, lkb);
} else {
lkb->lkb_flags &= ~DLM_IFL_OVERLAP_CANCEL;
lkb->lkb_flags &= ~DLM_IFL_OVERLAP_UNLOCK;
}
out:
unlock_rsb(r);
put_rsb(r);
dlm_put_lkb(lkb);
return 0;
}
static void __receive_convert_reply(struct dlm_rsb *r, struct dlm_lkb *lkb,
struct dlm_message *ms)
{
switch (ms->m_result) {
case -EAGAIN:
queue_cast(r, lkb, -EAGAIN);
break;
case -EDEADLK:
receive_flags_reply(lkb, ms);
revert_lock_pc(r, lkb);
queue_cast(r, lkb, -EDEADLK);
break;
case -EINPROGRESS:
receive_flags_reply(lkb, ms);
if (is_demoted(lkb))
munge_demoted(lkb);
del_lkb(r, lkb);
add_lkb(r, lkb, DLM_LKSTS_CONVERT);
add_timeout(lkb);
break;
case 0:
receive_flags_reply(lkb, ms);
if (is_demoted(lkb))
munge_demoted(lkb);
grant_lock_pc(r, lkb, ms);
queue_cast(r, lkb, 0);
break;
default:
log_error(r->res_ls, "receive_convert_reply %x remote %d %x %d",
lkb->lkb_id, ms->m_header.h_nodeid, ms->m_lkid,
ms->m_result);
dlm_print_rsb(r);
dlm_print_lkb(lkb);
}
}
static void _receive_convert_reply(struct dlm_lkb *lkb, struct dlm_message *ms)
{
struct dlm_rsb *r = lkb->lkb_resource;
int error;
hold_rsb(r);
lock_rsb(r);
error = validate_message(lkb, ms);
if (error)
goto out;
error = remove_from_waiters_ms(lkb, ms);
if (error)
goto out;
__receive_convert_reply(r, lkb, ms);
out:
unlock_rsb(r);
put_rsb(r);
}
static int receive_convert_reply(struct dlm_ls *ls, struct dlm_message *ms)
{
struct dlm_lkb *lkb;
int error;
error = find_lkb(ls, ms->m_remid, &lkb);
if (error)
return error;
_receive_convert_reply(lkb, ms);
dlm_put_lkb(lkb);
return 0;
}
static void _receive_unlock_reply(struct dlm_lkb *lkb, struct dlm_message *ms)
{
struct dlm_rsb *r = lkb->lkb_resource;
int error;
hold_rsb(r);
lock_rsb(r);
error = validate_message(lkb, ms);
if (error)
goto out;
error = remove_from_waiters_ms(lkb, ms);
if (error)
goto out;
switch (ms->m_result) {
case -DLM_EUNLOCK:
receive_flags_reply(lkb, ms);
remove_lock_pc(r, lkb);
queue_cast(r, lkb, -DLM_EUNLOCK);
break;
case -ENOENT:
break;
default:
log_error(r->res_ls, "receive_unlock_reply %x error %d",
lkb->lkb_id, ms->m_result);
}
out:
unlock_rsb(r);
put_rsb(r);
}
static int receive_unlock_reply(struct dlm_ls *ls, struct dlm_message *ms)
{
struct dlm_lkb *lkb;
int error;
error = find_lkb(ls, ms->m_remid, &lkb);
if (error)
return error;
_receive_unlock_reply(lkb, ms);
dlm_put_lkb(lkb);
return 0;
}
static void _receive_cancel_reply(struct dlm_lkb *lkb, struct dlm_message *ms)
{
struct dlm_rsb *r = lkb->lkb_resource;
int error;
hold_rsb(r);
lock_rsb(r);
error = validate_message(lkb, ms);
if (error)
goto out;
error = remove_from_waiters_ms(lkb, ms);
if (error)
goto out;
switch (ms->m_result) {
case -DLM_ECANCEL:
receive_flags_reply(lkb, ms);
revert_lock_pc(r, lkb);
queue_cast(r, lkb, -DLM_ECANCEL);
break;
case 0:
break;
default:
log_error(r->res_ls, "receive_cancel_reply %x error %d",
lkb->lkb_id, ms->m_result);
}
out:
unlock_rsb(r);
put_rsb(r);
}
static int receive_cancel_reply(struct dlm_ls *ls, struct dlm_message *ms)
{
struct dlm_lkb *lkb;
int error;
error = find_lkb(ls, ms->m_remid, &lkb);
if (error)
return error;
_receive_cancel_reply(lkb, ms);
dlm_put_lkb(lkb);
return 0;
}
static void receive_lookup_reply(struct dlm_ls *ls, struct dlm_message *ms)
{
struct dlm_lkb *lkb;
struct dlm_rsb *r;
int error, ret_nodeid;
int do_lookup_list = 0;
error = find_lkb(ls, ms->m_lkid, &lkb);
if (error) {
log_error(ls, "receive_lookup_reply no lkid %x", ms->m_lkid);
return;
}
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
error = remove_from_waiters(lkb, DLM_MSG_LOOKUP_REPLY);
if (error)
goto out;
ret_nodeid = ms->m_nodeid;
if (r->res_master_nodeid && (r->res_master_nodeid != ret_nodeid)) {
log_error(ls, "receive_lookup_reply %x from %d ret %d "
"master %d dir %d our %d first %x %s",
lkb->lkb_id, ms->m_header.h_nodeid, ret_nodeid,
r->res_master_nodeid, r->res_dir_nodeid,
dlm_our_nodeid(), r->res_first_lkid, r->res_name);
}
if (ret_nodeid == dlm_our_nodeid()) {
r->res_master_nodeid = ret_nodeid;
r->res_nodeid = 0;
do_lookup_list = 1;
r->res_first_lkid = 0;
} else if (ret_nodeid == -1) {
log_error(ls, "receive_lookup_reply %x from %d bad ret_nodeid",
lkb->lkb_id, ms->m_header.h_nodeid);
r->res_master_nodeid = 0;
r->res_nodeid = -1;
lkb->lkb_nodeid = -1;
} else {
r->res_master_nodeid = ret_nodeid;
r->res_nodeid = ret_nodeid;
}
if (is_overlap(lkb)) {
log_debug(ls, "receive_lookup_reply %x unlock %x",
lkb->lkb_id, lkb->lkb_flags);
queue_cast_overlap(r, lkb);
unhold_lkb(lkb);
goto out_list;
}
_request_lock(r, lkb);
out_list:
if (do_lookup_list)
process_lookup_list(r);
out:
unlock_rsb(r);
put_rsb(r);
dlm_put_lkb(lkb);
}
static void _receive_message(struct dlm_ls *ls, struct dlm_message *ms,
uint32_t saved_seq)
{
int error = 0, noent = 0;
if (!dlm_is_member(ls, ms->m_header.h_nodeid)) {
log_limit(ls, "receive %d from non-member %d %x %x %d",
ms->m_type, ms->m_header.h_nodeid, ms->m_lkid,
ms->m_remid, ms->m_result);
return;
}
switch (ms->m_type) {
case DLM_MSG_REQUEST:
error = receive_request(ls, ms);
break;
case DLM_MSG_CONVERT:
error = receive_convert(ls, ms);
break;
case DLM_MSG_UNLOCK:
error = receive_unlock(ls, ms);
break;
case DLM_MSG_CANCEL:
noent = 1;
error = receive_cancel(ls, ms);
break;
case DLM_MSG_REQUEST_REPLY:
error = receive_request_reply(ls, ms);
break;
case DLM_MSG_CONVERT_REPLY:
error = receive_convert_reply(ls, ms);
break;
case DLM_MSG_UNLOCK_REPLY:
error = receive_unlock_reply(ls, ms);
break;
case DLM_MSG_CANCEL_REPLY:
error = receive_cancel_reply(ls, ms);
break;
case DLM_MSG_GRANT:
noent = 1;
error = receive_grant(ls, ms);
break;
case DLM_MSG_BAST:
noent = 1;
error = receive_bast(ls, ms);
break;
case DLM_MSG_LOOKUP:
receive_lookup(ls, ms);
break;
case DLM_MSG_REMOVE:
receive_remove(ls, ms);
break;
case DLM_MSG_LOOKUP_REPLY:
receive_lookup_reply(ls, ms);
break;
case DLM_MSG_PURGE:
receive_purge(ls, ms);
break;
default:
log_error(ls, "unknown message type %d", ms->m_type);
}
if (error == -ENOENT && noent) {
log_debug(ls, "receive %d no %x remote %d %x saved_seq %u",
ms->m_type, ms->m_remid, ms->m_header.h_nodeid,
ms->m_lkid, saved_seq);
} else if (error == -ENOENT) {
log_error(ls, "receive %d no %x remote %d %x saved_seq %u",
ms->m_type, ms->m_remid, ms->m_header.h_nodeid,
ms->m_lkid, saved_seq);
if (ms->m_type == DLM_MSG_CONVERT)
dlm_dump_rsb_hash(ls, ms->m_hash);
}
if (error == -EINVAL) {
log_error(ls, "receive %d inval from %d lkid %x remid %x "
"saved_seq %u",
ms->m_type, ms->m_header.h_nodeid,
ms->m_lkid, ms->m_remid, saved_seq);
}
}
static void dlm_receive_message(struct dlm_ls *ls, struct dlm_message *ms,
int nodeid)
{
if (dlm_locking_stopped(ls)) {
if (!ls->ls_generation) {
log_limit(ls, "receive %d from %d ignore old gen",
ms->m_type, nodeid);
return;
}
dlm_add_requestqueue(ls, nodeid, ms);
} else {
dlm_wait_requestqueue(ls);
_receive_message(ls, ms, 0);
}
}
void dlm_receive_message_saved(struct dlm_ls *ls, struct dlm_message *ms,
uint32_t saved_seq)
{
_receive_message(ls, ms, saved_seq);
}
void dlm_receive_buffer(union dlm_packet *p, int nodeid)
{
struct dlm_header *hd = &p->header;
struct dlm_ls *ls;
int type = 0;
switch (hd->h_cmd) {
case DLM_MSG:
dlm_message_in(&p->message);
type = p->message.m_type;
break;
case DLM_RCOM:
dlm_rcom_in(&p->rcom);
type = p->rcom.rc_type;
break;
default:
log_print("invalid h_cmd %d from %u", hd->h_cmd, nodeid);
return;
}
if (hd->h_nodeid != nodeid) {
log_print("invalid h_nodeid %d from %d lockspace %x",
hd->h_nodeid, nodeid, hd->h_lockspace);
return;
}
ls = dlm_find_lockspace_global(hd->h_lockspace);
if (!ls) {
if (dlm_config.ci_log_debug) {
printk_ratelimited(KERN_DEBUG "dlm: invalid lockspace "
"%u from %d cmd %d type %d\n",
hd->h_lockspace, nodeid, hd->h_cmd, type);
}
if (hd->h_cmd == DLM_RCOM && type == DLM_RCOM_STATUS)
dlm_send_ls_not_ready(nodeid, &p->rcom);
return;
}
down_read(&ls->ls_recv_active);
if (hd->h_cmd == DLM_MSG)
dlm_receive_message(ls, &p->message, nodeid);
else
dlm_receive_rcom(ls, &p->rcom, nodeid);
up_read(&ls->ls_recv_active);
dlm_put_lockspace(ls);
}
static void recover_convert_waiter(struct dlm_ls *ls, struct dlm_lkb *lkb,
struct dlm_message *ms_stub)
{
if (middle_conversion(lkb)) {
hold_lkb(lkb);
memset(ms_stub, 0, sizeof(struct dlm_message));
ms_stub->m_flags = DLM_IFL_STUB_MS;
ms_stub->m_type = DLM_MSG_CONVERT_REPLY;
ms_stub->m_result = -EINPROGRESS;
ms_stub->m_header.h_nodeid = lkb->lkb_nodeid;
_receive_convert_reply(lkb, ms_stub);
lkb->lkb_grmode = DLM_LOCK_IV;
rsb_set_flag(lkb->lkb_resource, RSB_RECOVER_CONVERT);
unhold_lkb(lkb);
} else if (lkb->lkb_rqmode >= lkb->lkb_grmode) {
lkb->lkb_flags |= DLM_IFL_RESEND;
}
}
static int waiter_needs_recovery(struct dlm_ls *ls, struct dlm_lkb *lkb,
int dir_nodeid)
{
if (dlm_no_directory(ls))
return 1;
if (dlm_is_removed(ls, lkb->lkb_wait_nodeid))
return 1;
return 0;
}
void dlm_recover_waiters_pre(struct dlm_ls *ls)
{
struct dlm_lkb *lkb, *safe;
struct dlm_message *ms_stub;
int wait_type, stub_unlock_result, stub_cancel_result;
int dir_nodeid;
ms_stub = kmalloc(sizeof(struct dlm_message), GFP_KERNEL);
if (!ms_stub) {
log_error(ls, "dlm_recover_waiters_pre no mem");
return;
}
mutex_lock(&ls->ls_waiters_mutex);
list_for_each_entry_safe(lkb, safe, &ls->ls_waiters, lkb_wait_reply) {
dir_nodeid = dlm_dir_nodeid(lkb->lkb_resource);
if (lkb->lkb_wait_type != DLM_MSG_UNLOCK) {
log_debug(ls, "waiter %x remote %x msg %d r_nodeid %d "
"lkb_nodeid %d wait_nodeid %d dir_nodeid %d",
lkb->lkb_id,
lkb->lkb_remid,
lkb->lkb_wait_type,
lkb->lkb_resource->res_nodeid,
lkb->lkb_nodeid,
lkb->lkb_wait_nodeid,
dir_nodeid);
}
if (lkb->lkb_wait_type == DLM_MSG_LOOKUP) {
lkb->lkb_flags |= DLM_IFL_RESEND;
continue;
}
if (!waiter_needs_recovery(ls, lkb, dir_nodeid))
continue;
wait_type = lkb->lkb_wait_type;
stub_unlock_result = -DLM_EUNLOCK;
stub_cancel_result = -DLM_ECANCEL;
if (!wait_type) {
if (is_overlap_cancel(lkb)) {
wait_type = DLM_MSG_CANCEL;
if (lkb->lkb_grmode == DLM_LOCK_IV)
stub_cancel_result = 0;
}
if (is_overlap_unlock(lkb)) {
wait_type = DLM_MSG_UNLOCK;
if (lkb->lkb_grmode == DLM_LOCK_IV)
stub_unlock_result = -ENOENT;
}
log_debug(ls, "rwpre overlap %x %x %d %d %d",
lkb->lkb_id, lkb->lkb_flags, wait_type,
stub_cancel_result, stub_unlock_result);
}
switch (wait_type) {
case DLM_MSG_REQUEST:
lkb->lkb_flags |= DLM_IFL_RESEND;
break;
case DLM_MSG_CONVERT:
recover_convert_waiter(ls, lkb, ms_stub);
break;
case DLM_MSG_UNLOCK:
hold_lkb(lkb);
memset(ms_stub, 0, sizeof(struct dlm_message));
ms_stub->m_flags = DLM_IFL_STUB_MS;
ms_stub->m_type = DLM_MSG_UNLOCK_REPLY;
ms_stub->m_result = stub_unlock_result;
ms_stub->m_header.h_nodeid = lkb->lkb_nodeid;
_receive_unlock_reply(lkb, ms_stub);
dlm_put_lkb(lkb);
break;
case DLM_MSG_CANCEL:
hold_lkb(lkb);
memset(ms_stub, 0, sizeof(struct dlm_message));
ms_stub->m_flags = DLM_IFL_STUB_MS;
ms_stub->m_type = DLM_MSG_CANCEL_REPLY;
ms_stub->m_result = stub_cancel_result;
ms_stub->m_header.h_nodeid = lkb->lkb_nodeid;
_receive_cancel_reply(lkb, ms_stub);
dlm_put_lkb(lkb);
break;
default:
log_error(ls, "invalid lkb wait_type %d %d",
lkb->lkb_wait_type, wait_type);
}
schedule();
}
mutex_unlock(&ls->ls_waiters_mutex);
kfree(ms_stub);
}
static struct dlm_lkb *find_resend_waiter(struct dlm_ls *ls)
{
struct dlm_lkb *lkb;
int found = 0;
mutex_lock(&ls->ls_waiters_mutex);
list_for_each_entry(lkb, &ls->ls_waiters, lkb_wait_reply) {
if (lkb->lkb_flags & DLM_IFL_RESEND) {
hold_lkb(lkb);
found = 1;
break;
}
}
mutex_unlock(&ls->ls_waiters_mutex);
if (!found)
lkb = NULL;
return lkb;
}
int dlm_recover_waiters_post(struct dlm_ls *ls)
{
struct dlm_lkb *lkb;
struct dlm_rsb *r;
int error = 0, mstype, err, oc, ou;
while (1) {
if (dlm_locking_stopped(ls)) {
log_debug(ls, "recover_waiters_post aborted");
error = -EINTR;
break;
}
lkb = find_resend_waiter(ls);
if (!lkb)
break;
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
mstype = lkb->lkb_wait_type;
oc = is_overlap_cancel(lkb);
ou = is_overlap_unlock(lkb);
err = 0;
log_debug(ls, "waiter %x remote %x msg %d r_nodeid %d "
"lkb_nodeid %d wait_nodeid %d dir_nodeid %d "
"overlap %d %d", lkb->lkb_id, lkb->lkb_remid, mstype,
r->res_nodeid, lkb->lkb_nodeid, lkb->lkb_wait_nodeid,
dlm_dir_nodeid(r), oc, ou);
lkb->lkb_flags &= ~DLM_IFL_RESEND;
lkb->lkb_flags &= ~DLM_IFL_OVERLAP_UNLOCK;
lkb->lkb_flags &= ~DLM_IFL_OVERLAP_CANCEL;
lkb->lkb_wait_type = 0;
lkb->lkb_wait_count = 0;
mutex_lock(&ls->ls_waiters_mutex);
list_del_init(&lkb->lkb_wait_reply);
mutex_unlock(&ls->ls_waiters_mutex);
unhold_lkb(lkb);
if (oc || ou) {
switch (mstype) {
case DLM_MSG_LOOKUP:
case DLM_MSG_REQUEST:
queue_cast(r, lkb, ou ? -DLM_EUNLOCK :
-DLM_ECANCEL);
unhold_lkb(lkb);
break;
case DLM_MSG_CONVERT:
if (oc) {
queue_cast(r, lkb, -DLM_ECANCEL);
} else {
lkb->lkb_exflags |= DLM_LKF_FORCEUNLOCK;
_unlock_lock(r, lkb);
}
break;
default:
err = 1;
}
} else {
switch (mstype) {
case DLM_MSG_LOOKUP:
case DLM_MSG_REQUEST:
_request_lock(r, lkb);
if (is_master(r))
confirm_master(r, 0);
break;
case DLM_MSG_CONVERT:
_convert_lock(r, lkb);
break;
default:
err = 1;
}
}
if (err) {
log_error(ls, "waiter %x msg %d r_nodeid %d "
"dir_nodeid %d overlap %d %d",
lkb->lkb_id, mstype, r->res_nodeid,
dlm_dir_nodeid(r), oc, ou);
}
unlock_rsb(r);
put_rsb(r);
dlm_put_lkb(lkb);
}
return error;
}
static void purge_mstcpy_list(struct dlm_ls *ls, struct dlm_rsb *r,
struct list_head *list)
{
struct dlm_lkb *lkb, *safe;
list_for_each_entry_safe(lkb, safe, list, lkb_statequeue) {
if (!is_master_copy(lkb))
continue;
if (lkb->lkb_recover_seq == ls->ls_recover_seq)
continue;
del_lkb(r, lkb);
if (!dlm_put_lkb(lkb))
log_error(ls, "purged mstcpy lkb not released");
}
}
void dlm_purge_mstcpy_locks(struct dlm_rsb *r)
{
struct dlm_ls *ls = r->res_ls;
purge_mstcpy_list(ls, r, &r->res_grantqueue);
purge_mstcpy_list(ls, r, &r->res_convertqueue);
purge_mstcpy_list(ls, r, &r->res_waitqueue);
}
static void purge_dead_list(struct dlm_ls *ls, struct dlm_rsb *r,
struct list_head *list,
int nodeid_gone, unsigned int *count)
{
struct dlm_lkb *lkb, *safe;
list_for_each_entry_safe(lkb, safe, list, lkb_statequeue) {
if (!is_master_copy(lkb))
continue;
if ((lkb->lkb_nodeid == nodeid_gone) ||
dlm_is_removed(ls, lkb->lkb_nodeid)) {
if ((lkb->lkb_exflags & DLM_LKF_VALBLK) &&
(lkb->lkb_grmode >= DLM_LOCK_PW)) {
rsb_set_flag(r, RSB_RECOVER_LVB_INVAL);
}
del_lkb(r, lkb);
if (!dlm_put_lkb(lkb))
log_error(ls, "purged dead lkb not released");
rsb_set_flag(r, RSB_RECOVER_GRANT);
(*count)++;
}
}
}
void dlm_recover_purge(struct dlm_ls *ls)
{
struct dlm_rsb *r;
struct dlm_member *memb;
int nodes_count = 0;
int nodeid_gone = 0;
unsigned int lkb_count = 0;
list_for_each_entry(memb, &ls->ls_nodes_gone, list) {
nodes_count++;
nodeid_gone = memb->nodeid;
}
if (!nodes_count)
return;
down_write(&ls->ls_root_sem);
list_for_each_entry(r, &ls->ls_root_list, res_root_list) {
hold_rsb(r);
lock_rsb(r);
if (is_master(r)) {
purge_dead_list(ls, r, &r->res_grantqueue,
nodeid_gone, &lkb_count);
purge_dead_list(ls, r, &r->res_convertqueue,
nodeid_gone, &lkb_count);
purge_dead_list(ls, r, &r->res_waitqueue,
nodeid_gone, &lkb_count);
}
unlock_rsb(r);
unhold_rsb(r);
cond_resched();
}
up_write(&ls->ls_root_sem);
if (lkb_count)
log_rinfo(ls, "dlm_recover_purge %u locks for %u nodes",
lkb_count, nodes_count);
}
static struct dlm_rsb *find_grant_rsb(struct dlm_ls *ls, int bucket)
{
struct rb_node *n;
struct dlm_rsb *r;
spin_lock(&ls->ls_rsbtbl[bucket].lock);
for (n = rb_first(&ls->ls_rsbtbl[bucket].keep); n; n = rb_next(n)) {
r = rb_entry(n, struct dlm_rsb, res_hashnode);
if (!rsb_flag(r, RSB_RECOVER_GRANT))
continue;
if (!is_master(r)) {
rsb_clear_flag(r, RSB_RECOVER_GRANT);
continue;
}
hold_rsb(r);
spin_unlock(&ls->ls_rsbtbl[bucket].lock);
return r;
}
spin_unlock(&ls->ls_rsbtbl[bucket].lock);
return NULL;
}
void dlm_recover_grant(struct dlm_ls *ls)
{
struct dlm_rsb *r;
int bucket = 0;
unsigned int count = 0;
unsigned int rsb_count = 0;
unsigned int lkb_count = 0;
while (1) {
r = find_grant_rsb(ls, bucket);
if (!r) {
if (bucket == ls->ls_rsbtbl_size - 1)
break;
bucket++;
continue;
}
rsb_count++;
count = 0;
lock_rsb(r);
grant_pending_locks(r, &count);
rsb_clear_flag(r, RSB_RECOVER_GRANT);
lkb_count += count;
confirm_master(r, 0);
unlock_rsb(r);
put_rsb(r);
cond_resched();
}
if (lkb_count)
log_rinfo(ls, "dlm_recover_grant %u locks on %u resources",
lkb_count, rsb_count);
}
static struct dlm_lkb *search_remid_list(struct list_head *head, int nodeid,
uint32_t remid)
{
struct dlm_lkb *lkb;
list_for_each_entry(lkb, head, lkb_statequeue) {
if (lkb->lkb_nodeid == nodeid && lkb->lkb_remid == remid)
return lkb;
}
return NULL;
}
static struct dlm_lkb *search_remid(struct dlm_rsb *r, int nodeid,
uint32_t remid)
{
struct dlm_lkb *lkb;
lkb = search_remid_list(&r->res_grantqueue, nodeid, remid);
if (lkb)
return lkb;
lkb = search_remid_list(&r->res_convertqueue, nodeid, remid);
if (lkb)
return lkb;
lkb = search_remid_list(&r->res_waitqueue, nodeid, remid);
if (lkb)
return lkb;
return NULL;
}
static int receive_rcom_lock_args(struct dlm_ls *ls, struct dlm_lkb *lkb,
struct dlm_rsb *r, struct dlm_rcom *rc)
{
struct rcom_lock *rl = (struct rcom_lock *) rc->rc_buf;
lkb->lkb_nodeid = rc->rc_header.h_nodeid;
lkb->lkb_ownpid = le32_to_cpu(rl->rl_ownpid);
lkb->lkb_remid = le32_to_cpu(rl->rl_lkid);
lkb->lkb_exflags = le32_to_cpu(rl->rl_exflags);
lkb->lkb_flags = le32_to_cpu(rl->rl_flags) & 0x0000FFFF;
lkb->lkb_flags |= DLM_IFL_MSTCPY;
lkb->lkb_lvbseq = le32_to_cpu(rl->rl_lvbseq);
lkb->lkb_rqmode = rl->rl_rqmode;
lkb->lkb_grmode = rl->rl_grmode;
lkb->lkb_bastfn = (rl->rl_asts & DLM_CB_BAST) ? &fake_bastfn : NULL;
lkb->lkb_astfn = (rl->rl_asts & DLM_CB_CAST) ? &fake_astfn : NULL;
if (lkb->lkb_exflags & DLM_LKF_VALBLK) {
int lvblen = rc->rc_header.h_length - sizeof(struct dlm_rcom) -
sizeof(struct rcom_lock);
if (lvblen > ls->ls_lvblen)
return -EINVAL;
lkb->lkb_lvbptr = dlm_allocate_lvb(ls);
if (!lkb->lkb_lvbptr)
return -ENOMEM;
memcpy(lkb->lkb_lvbptr, rl->rl_lvb, lvblen);
}
if (rl->rl_wait_type == cpu_to_le16(DLM_MSG_CONVERT) &&
middle_conversion(lkb)) {
rl->rl_status = DLM_LKSTS_CONVERT;
lkb->lkb_grmode = DLM_LOCK_IV;
rsb_set_flag(r, RSB_RECOVER_CONVERT);
}
return 0;
}
int dlm_recover_master_copy(struct dlm_ls *ls, struct dlm_rcom *rc)
{
struct rcom_lock *rl = (struct rcom_lock *) rc->rc_buf;
struct dlm_rsb *r;
struct dlm_lkb *lkb;
uint32_t remid = 0;
int from_nodeid = rc->rc_header.h_nodeid;
int error;
if (rl->rl_parent_lkid) {
error = -EOPNOTSUPP;
goto out;
}
remid = le32_to_cpu(rl->rl_lkid);
error = find_rsb(ls, rl->rl_name, le16_to_cpu(rl->rl_namelen),
from_nodeid, R_RECEIVE_RECOVER, &r);
if (error)
goto out;
lock_rsb(r);
if (dlm_no_directory(ls) && (dlm_dir_nodeid(r) != dlm_our_nodeid())) {
log_error(ls, "dlm_recover_master_copy remote %d %x not dir",
from_nodeid, remid);
error = -EBADR;
goto out_unlock;
}
lkb = search_remid(r, from_nodeid, remid);
if (lkb) {
error = -EEXIST;
goto out_remid;
}
error = create_lkb(ls, &lkb);
if (error)
goto out_unlock;
error = receive_rcom_lock_args(ls, lkb, r, rc);
if (error) {
__put_lkb(ls, lkb);
goto out_unlock;
}
attach_lkb(r, lkb);
add_lkb(r, lkb, rl->rl_status);
error = 0;
ls->ls_recover_locks_in++;
if (!list_empty(&r->res_waitqueue) || !list_empty(&r->res_convertqueue))
rsb_set_flag(r, RSB_RECOVER_GRANT);
out_remid:
rl->rl_remid = cpu_to_le32(lkb->lkb_id);
lkb->lkb_recover_seq = ls->ls_recover_seq;
out_unlock:
unlock_rsb(r);
put_rsb(r);
out:
if (error && error != -EEXIST)
log_rinfo(ls, "dlm_recover_master_copy remote %d %x error %d",
from_nodeid, remid, error);
rl->rl_result = cpu_to_le32(error);
return error;
}
int dlm_recover_process_copy(struct dlm_ls *ls, struct dlm_rcom *rc)
{
struct rcom_lock *rl = (struct rcom_lock *) rc->rc_buf;
struct dlm_rsb *r;
struct dlm_lkb *lkb;
uint32_t lkid, remid;
int error, result;
lkid = le32_to_cpu(rl->rl_lkid);
remid = le32_to_cpu(rl->rl_remid);
result = le32_to_cpu(rl->rl_result);
error = find_lkb(ls, lkid, &lkb);
if (error) {
log_error(ls, "dlm_recover_process_copy no %x remote %d %x %d",
lkid, rc->rc_header.h_nodeid, remid, result);
return error;
}
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
if (!is_process_copy(lkb)) {
log_error(ls, "dlm_recover_process_copy bad %x remote %d %x %d",
lkid, rc->rc_header.h_nodeid, remid, result);
dlm_dump_rsb(r);
unlock_rsb(r);
put_rsb(r);
dlm_put_lkb(lkb);
return -EINVAL;
}
switch (result) {
case -EBADR:
log_debug(ls, "dlm_recover_process_copy %x remote %d %x %d",
lkid, rc->rc_header.h_nodeid, remid, result);
dlm_send_rcom_lock(r, lkb);
goto out;
case -EEXIST:
case 0:
lkb->lkb_remid = remid;
break;
default:
log_error(ls, "dlm_recover_process_copy %x remote %d %x %d unk",
lkid, rc->rc_header.h_nodeid, remid, result);
}
dlm_recovered_lock(r);
out:
unlock_rsb(r);
put_rsb(r);
dlm_put_lkb(lkb);
return 0;
}
int dlm_user_request(struct dlm_ls *ls, struct dlm_user_args *ua,
int mode, uint32_t flags, void *name, unsigned int namelen,
unsigned long timeout_cs)
{
struct dlm_lkb *lkb;
struct dlm_args args;
int error;
dlm_lock_recovery(ls);
error = create_lkb(ls, &lkb);
if (error) {
kfree(ua);
goto out;
}
if (flags & DLM_LKF_VALBLK) {
ua->lksb.sb_lvbptr = kzalloc(DLM_USER_LVB_LEN, GFP_NOFS);
if (!ua->lksb.sb_lvbptr) {
kfree(ua);
__put_lkb(ls, lkb);
error = -ENOMEM;
goto out;
}
}
error = set_lock_args(mode, &ua->lksb, flags, namelen, timeout_cs,
fake_astfn, ua, fake_bastfn, &args);
lkb->lkb_flags |= DLM_IFL_USER;
if (error) {
__put_lkb(ls, lkb);
goto out;
}
error = request_lock(ls, lkb, name, namelen, &args);
switch (error) {
case 0:
break;
case -EINPROGRESS:
error = 0;
break;
case -EAGAIN:
error = 0;
default:
__put_lkb(ls, lkb);
goto out;
}
spin_lock(&ua->proc->locks_spin);
hold_lkb(lkb);
list_add_tail(&lkb->lkb_ownqueue, &ua->proc->locks);
spin_unlock(&ua->proc->locks_spin);
out:
dlm_unlock_recovery(ls);
return error;
}
int dlm_user_convert(struct dlm_ls *ls, struct dlm_user_args *ua_tmp,
int mode, uint32_t flags, uint32_t lkid, char *lvb_in,
unsigned long timeout_cs)
{
struct dlm_lkb *lkb;
struct dlm_args args;
struct dlm_user_args *ua;
int error;
dlm_lock_recovery(ls);
error = find_lkb(ls, lkid, &lkb);
if (error)
goto out;
ua = lkb->lkb_ua;
if (flags & DLM_LKF_VALBLK && !ua->lksb.sb_lvbptr) {
ua->lksb.sb_lvbptr = kzalloc(DLM_USER_LVB_LEN, GFP_NOFS);
if (!ua->lksb.sb_lvbptr) {
error = -ENOMEM;
goto out_put;
}
}
if (lvb_in && ua->lksb.sb_lvbptr)
memcpy(ua->lksb.sb_lvbptr, lvb_in, DLM_USER_LVB_LEN);
ua->xid = ua_tmp->xid;
ua->castparam = ua_tmp->castparam;
ua->castaddr = ua_tmp->castaddr;
ua->bastparam = ua_tmp->bastparam;
ua->bastaddr = ua_tmp->bastaddr;
ua->user_lksb = ua_tmp->user_lksb;
error = set_lock_args(mode, &ua->lksb, flags, 0, timeout_cs,
fake_astfn, ua, fake_bastfn, &args);
if (error)
goto out_put;
error = convert_lock(ls, lkb, &args);
if (error == -EINPROGRESS || error == -EAGAIN || error == -EDEADLK)
error = 0;
out_put:
dlm_put_lkb(lkb);
out:
dlm_unlock_recovery(ls);
kfree(ua_tmp);
return error;
}
int dlm_user_adopt_orphan(struct dlm_ls *ls, struct dlm_user_args *ua_tmp,
int mode, uint32_t flags, void *name, unsigned int namelen,
unsigned long timeout_cs, uint32_t *lkid)
{
struct dlm_lkb *lkb;
struct dlm_user_args *ua;
int found_other_mode = 0;
int found = 0;
int rv = 0;
mutex_lock(&ls->ls_orphans_mutex);
list_for_each_entry(lkb, &ls->ls_orphans, lkb_ownqueue) {
if (lkb->lkb_resource->res_length != namelen)
continue;
if (memcmp(lkb->lkb_resource->res_name, name, namelen))
continue;
if (lkb->lkb_grmode != mode) {
found_other_mode = 1;
continue;
}
found = 1;
list_del_init(&lkb->lkb_ownqueue);
lkb->lkb_flags &= ~DLM_IFL_ORPHAN;
*lkid = lkb->lkb_id;
break;
}
mutex_unlock(&ls->ls_orphans_mutex);
if (!found && found_other_mode) {
rv = -EAGAIN;
goto out;
}
if (!found) {
rv = -ENOENT;
goto out;
}
lkb->lkb_exflags = flags;
lkb->lkb_ownpid = (int) current->pid;
ua = lkb->lkb_ua;
ua->proc = ua_tmp->proc;
ua->xid = ua_tmp->xid;
ua->castparam = ua_tmp->castparam;
ua->castaddr = ua_tmp->castaddr;
ua->bastparam = ua_tmp->bastparam;
ua->bastaddr = ua_tmp->bastaddr;
ua->user_lksb = ua_tmp->user_lksb;
spin_lock(&ua->proc->locks_spin);
list_add_tail(&lkb->lkb_ownqueue, &ua->proc->locks);
spin_unlock(&ua->proc->locks_spin);
out:
kfree(ua_tmp);
return rv;
}
int dlm_user_unlock(struct dlm_ls *ls, struct dlm_user_args *ua_tmp,
uint32_t flags, uint32_t lkid, char *lvb_in)
{
struct dlm_lkb *lkb;
struct dlm_args args;
struct dlm_user_args *ua;
int error;
dlm_lock_recovery(ls);
error = find_lkb(ls, lkid, &lkb);
if (error)
goto out;
ua = lkb->lkb_ua;
if (lvb_in && ua->lksb.sb_lvbptr)
memcpy(ua->lksb.sb_lvbptr, lvb_in, DLM_USER_LVB_LEN);
if (ua_tmp->castparam)
ua->castparam = ua_tmp->castparam;
ua->user_lksb = ua_tmp->user_lksb;
error = set_unlock_args(flags, ua, &args);
if (error)
goto out_put;
error = unlock_lock(ls, lkb, &args);
if (error == -DLM_EUNLOCK)
error = 0;
if (error == -EBUSY && (flags & DLM_LKF_FORCEUNLOCK))
error = 0;
if (error)
goto out_put;
spin_lock(&ua->proc->locks_spin);
if (!list_empty(&lkb->lkb_ownqueue))
list_move(&lkb->lkb_ownqueue, &ua->proc->unlocking);
spin_unlock(&ua->proc->locks_spin);
out_put:
dlm_put_lkb(lkb);
out:
dlm_unlock_recovery(ls);
kfree(ua_tmp);
return error;
}
int dlm_user_cancel(struct dlm_ls *ls, struct dlm_user_args *ua_tmp,
uint32_t flags, uint32_t lkid)
{
struct dlm_lkb *lkb;
struct dlm_args args;
struct dlm_user_args *ua;
int error;
dlm_lock_recovery(ls);
error = find_lkb(ls, lkid, &lkb);
if (error)
goto out;
ua = lkb->lkb_ua;
if (ua_tmp->castparam)
ua->castparam = ua_tmp->castparam;
ua->user_lksb = ua_tmp->user_lksb;
error = set_unlock_args(flags, ua, &args);
if (error)
goto out_put;
error = cancel_lock(ls, lkb, &args);
if (error == -DLM_ECANCEL)
error = 0;
if (error == -EBUSY)
error = 0;
out_put:
dlm_put_lkb(lkb);
out:
dlm_unlock_recovery(ls);
kfree(ua_tmp);
return error;
}
int dlm_user_deadlock(struct dlm_ls *ls, uint32_t flags, uint32_t lkid)
{
struct dlm_lkb *lkb;
struct dlm_args args;
struct dlm_user_args *ua;
struct dlm_rsb *r;
int error;
dlm_lock_recovery(ls);
error = find_lkb(ls, lkid, &lkb);
if (error)
goto out;
ua = lkb->lkb_ua;
error = set_unlock_args(flags, ua, &args);
if (error)
goto out_put;
r = lkb->lkb_resource;
hold_rsb(r);
lock_rsb(r);
error = validate_unlock_args(lkb, &args);
if (error)
goto out_r;
lkb->lkb_flags |= DLM_IFL_DEADLOCK_CANCEL;
error = _cancel_lock(r, lkb);
out_r:
unlock_rsb(r);
put_rsb(r);
if (error == -DLM_ECANCEL)
error = 0;
if (error == -EBUSY)
error = 0;
out_put:
dlm_put_lkb(lkb);
out:
dlm_unlock_recovery(ls);
return error;
}
static int orphan_proc_lock(struct dlm_ls *ls, struct dlm_lkb *lkb)
{
struct dlm_args args;
int error;
hold_lkb(lkb);
mutex_lock(&ls->ls_orphans_mutex);
list_add_tail(&lkb->lkb_ownqueue, &ls->ls_orphans);
mutex_unlock(&ls->ls_orphans_mutex);
set_unlock_args(0, lkb->lkb_ua, &args);
error = cancel_lock(ls, lkb, &args);
if (error == -DLM_ECANCEL)
error = 0;
return error;
}
static int unlock_proc_lock(struct dlm_ls *ls, struct dlm_lkb *lkb)
{
struct dlm_args args;
int error;
set_unlock_args(DLM_LKF_FORCEUNLOCK | DLM_LKF_IVVALBLK,
lkb->lkb_ua, &args);
error = unlock_lock(ls, lkb, &args);
if (error == -DLM_EUNLOCK)
error = 0;
return error;
}
static struct dlm_lkb *del_proc_lock(struct dlm_ls *ls,
struct dlm_user_proc *proc)
{
struct dlm_lkb *lkb = NULL;
mutex_lock(&ls->ls_clear_proc_locks);
if (list_empty(&proc->locks))
goto out;
lkb = list_entry(proc->locks.next, struct dlm_lkb, lkb_ownqueue);
list_del_init(&lkb->lkb_ownqueue);
if (lkb->lkb_exflags & DLM_LKF_PERSISTENT)
lkb->lkb_flags |= DLM_IFL_ORPHAN;
else
lkb->lkb_flags |= DLM_IFL_DEAD;
out:
mutex_unlock(&ls->ls_clear_proc_locks);
return lkb;
}
void dlm_clear_proc_locks(struct dlm_ls *ls, struct dlm_user_proc *proc)
{
struct dlm_lkb *lkb, *safe;
dlm_lock_recovery(ls);
while (1) {
lkb = del_proc_lock(ls, proc);
if (!lkb)
break;
del_timeout(lkb);
if (lkb->lkb_exflags & DLM_LKF_PERSISTENT)
orphan_proc_lock(ls, lkb);
else
unlock_proc_lock(ls, lkb);
dlm_put_lkb(lkb);
}
mutex_lock(&ls->ls_clear_proc_locks);
list_for_each_entry_safe(lkb, safe, &proc->unlocking, lkb_ownqueue) {
list_del_init(&lkb->lkb_ownqueue);
lkb->lkb_flags |= DLM_IFL_DEAD;
dlm_put_lkb(lkb);
}
list_for_each_entry_safe(lkb, safe, &proc->asts, lkb_cb_list) {
memset(&lkb->lkb_callbacks, 0,
sizeof(struct dlm_callback) * DLM_CALLBACKS_SIZE);
list_del_init(&lkb->lkb_cb_list);
dlm_put_lkb(lkb);
}
mutex_unlock(&ls->ls_clear_proc_locks);
dlm_unlock_recovery(ls);
}
static void purge_proc_locks(struct dlm_ls *ls, struct dlm_user_proc *proc)
{
struct dlm_lkb *lkb, *safe;
while (1) {
lkb = NULL;
spin_lock(&proc->locks_spin);
if (!list_empty(&proc->locks)) {
lkb = list_entry(proc->locks.next, struct dlm_lkb,
lkb_ownqueue);
list_del_init(&lkb->lkb_ownqueue);
}
spin_unlock(&proc->locks_spin);
if (!lkb)
break;
lkb->lkb_flags |= DLM_IFL_DEAD;
unlock_proc_lock(ls, lkb);
dlm_put_lkb(lkb);
}
spin_lock(&proc->locks_spin);
list_for_each_entry_safe(lkb, safe, &proc->unlocking, lkb_ownqueue) {
list_del_init(&lkb->lkb_ownqueue);
lkb->lkb_flags |= DLM_IFL_DEAD;
dlm_put_lkb(lkb);
}
spin_unlock(&proc->locks_spin);
spin_lock(&proc->asts_spin);
list_for_each_entry_safe(lkb, safe, &proc->asts, lkb_cb_list) {
memset(&lkb->lkb_callbacks, 0,
sizeof(struct dlm_callback) * DLM_CALLBACKS_SIZE);
list_del_init(&lkb->lkb_cb_list);
dlm_put_lkb(lkb);
}
spin_unlock(&proc->asts_spin);
}
static void do_purge(struct dlm_ls *ls, int nodeid, int pid)
{
struct dlm_lkb *lkb, *safe;
mutex_lock(&ls->ls_orphans_mutex);
list_for_each_entry_safe(lkb, safe, &ls->ls_orphans, lkb_ownqueue) {
if (pid && lkb->lkb_ownpid != pid)
continue;
unlock_proc_lock(ls, lkb);
list_del_init(&lkb->lkb_ownqueue);
dlm_put_lkb(lkb);
}
mutex_unlock(&ls->ls_orphans_mutex);
}
static int send_purge(struct dlm_ls *ls, int nodeid, int pid)
{
struct dlm_message *ms;
struct dlm_mhandle *mh;
int error;
error = _create_message(ls, sizeof(struct dlm_message), nodeid,
DLM_MSG_PURGE, &ms, &mh);
if (error)
return error;
ms->m_nodeid = nodeid;
ms->m_pid = pid;
return send_message(mh, ms);
}
int dlm_user_purge(struct dlm_ls *ls, struct dlm_user_proc *proc,
int nodeid, int pid)
{
int error = 0;
if (nodeid && (nodeid != dlm_our_nodeid())) {
error = send_purge(ls, nodeid, pid);
} else {
dlm_lock_recovery(ls);
if (pid == current->pid)
purge_proc_locks(ls, proc);
else
do_purge(ls, nodeid, pid);
dlm_unlock_recovery(ls);
}
return error;
}
