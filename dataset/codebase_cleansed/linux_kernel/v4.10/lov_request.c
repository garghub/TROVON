static void lov_init_set(struct lov_request_set *set)
{
set->set_count = 0;
atomic_set(&set->set_completes, 0);
atomic_set(&set->set_success, 0);
atomic_set(&set->set_finish_checked, 0);
INIT_LIST_HEAD(&set->set_list);
atomic_set(&set->set_refcount, 1);
init_waitqueue_head(&set->set_waitq);
}
void lov_finish_set(struct lov_request_set *set)
{
struct list_head *pos, *n;
LASSERT(set);
list_for_each_safe(pos, n, &set->set_list) {
struct lov_request *req = list_entry(pos,
struct lov_request,
rq_link);
list_del_init(&req->rq_link);
kfree(req->rq_oi.oi_osfs);
kfree(req);
}
kfree(set);
}
static int lov_set_finished(struct lov_request_set *set, int idempotent)
{
int completes = atomic_read(&set->set_completes);
CDEBUG(D_INFO, "check set %d/%d\n", completes, set->set_count);
if (completes == set->set_count) {
if (idempotent)
return 1;
if (atomic_inc_return(&set->set_finish_checked) == 1)
return 1;
}
return 0;
}
static void lov_update_set(struct lov_request_set *set,
struct lov_request *req, int rc)
{
req->rq_complete = 1;
req->rq_rc = rc;
atomic_inc(&set->set_completes);
if (rc == 0)
atomic_inc(&set->set_success);
wake_up(&set->set_waitq);
}
static void lov_set_add_req(struct lov_request *req,
struct lov_request_set *set)
{
list_add_tail(&req->rq_link, &set->set_list);
set->set_count++;
req->rq_rqset = set;
}
static int lov_check_set(struct lov_obd *lov, int idx)
{
int rc;
struct lov_tgt_desc *tgt;
mutex_lock(&lov->lov_lock);
tgt = lov->lov_tgts[idx];
rc = !tgt || tgt->ltd_active ||
(tgt->ltd_exp &&
class_exp2cliimp(tgt->ltd_exp)->imp_connect_tried);
mutex_unlock(&lov->lov_lock);
return rc;
}
static int lov_check_and_wait_active(struct lov_obd *lov, int ost_idx)
{
wait_queue_head_t waitq;
struct l_wait_info lwi;
struct lov_tgt_desc *tgt;
int rc = 0;
mutex_lock(&lov->lov_lock);
tgt = lov->lov_tgts[ost_idx];
if (unlikely(!tgt)) {
rc = 0;
goto out;
}
if (likely(tgt->ltd_active)) {
rc = 1;
goto out;
}
if (tgt->ltd_exp && class_exp2cliimp(tgt->ltd_exp)->imp_connect_tried) {
rc = 0;
goto out;
}
mutex_unlock(&lov->lov_lock);
init_waitqueue_head(&waitq);
lwi = LWI_TIMEOUT_INTERVAL(cfs_time_seconds(obd_timeout),
cfs_time_seconds(1), NULL, NULL);
rc = l_wait_event(waitq, lov_check_set(lov, ost_idx), &lwi);
if (tgt->ltd_active)
return 1;
return 0;
out:
mutex_unlock(&lov->lov_lock);
return rc;
}
int lov_fini_statfs(struct obd_device *obd, struct obd_statfs *osfs,
int success)
{
if (success) {
__u32 expected_stripes = lov_get_stripecnt(&obd->u.lov,
LOV_MAGIC, 0);
if (osfs->os_files != LOV_U64_MAX)
lov_do_div64(osfs->os_files, expected_stripes);
if (osfs->os_ffree != LOV_U64_MAX)
lov_do_div64(osfs->os_ffree, expected_stripes);
spin_lock(&obd->obd_osfs_lock);
memcpy(&obd->obd_osfs, osfs, sizeof(*osfs));
obd->obd_osfs_age = cfs_time_current_64();
spin_unlock(&obd->obd_osfs_lock);
return 0;
}
return -EIO;
}
int lov_fini_statfs_set(struct lov_request_set *set)
{
int rc = 0;
if (!set)
return 0;
if (atomic_read(&set->set_completes)) {
rc = lov_fini_statfs(set->set_obd, set->set_oi->oi_osfs,
atomic_read(&set->set_success));
}
lov_put_reqset(set);
return rc;
}
static void lov_update_statfs(struct obd_statfs *osfs,
struct obd_statfs *lov_sfs,
int success)
{
int shift = 0, quit = 0;
__u64 tmp;
if (success == 0) {
memcpy(osfs, lov_sfs, sizeof(*lov_sfs));
} else {
if (osfs->os_bsize != lov_sfs->os_bsize) {
tmp = osfs->os_bsize | lov_sfs->os_bsize;
for (shift = 0; shift <= 64; ++shift) {
if (tmp & 1) {
if (quit)
break;
quit = 1;
shift = 0;
}
tmp >>= 1;
}
}
if (osfs->os_bsize < lov_sfs->os_bsize) {
osfs->os_bsize = lov_sfs->os_bsize;
osfs->os_bfree >>= shift;
osfs->os_bavail >>= shift;
osfs->os_blocks >>= shift;
} else if (shift != 0) {
lov_sfs->os_bfree >>= shift;
lov_sfs->os_bavail >>= shift;
lov_sfs->os_blocks >>= shift;
}
osfs->os_bfree += lov_sfs->os_bfree;
osfs->os_bavail += lov_sfs->os_bavail;
osfs->os_blocks += lov_sfs->os_blocks;
LOV_SUM_MAX(osfs->os_files, lov_sfs->os_files);
LOV_SUM_MAX(osfs->os_ffree, lov_sfs->os_ffree);
}
}
static int cb_statfs_update(void *cookie, int rc)
{
struct obd_info *oinfo = cookie;
struct lov_request *lovreq;
struct lov_request_set *set;
struct obd_statfs *osfs, *lov_sfs;
struct lov_obd *lov;
struct lov_tgt_desc *tgt;
struct obd_device *lovobd, *tgtobd;
int success;
lovreq = container_of(oinfo, struct lov_request, rq_oi);
set = lovreq->rq_rqset;
lovobd = set->set_obd;
lov = &lovobd->u.lov;
osfs = set->set_oi->oi_osfs;
lov_sfs = oinfo->oi_osfs;
success = atomic_read(&set->set_success);
lov_update_set(set, lovreq, rc);
if (rc)
goto out;
obd_getref(lovobd);
tgt = lov->lov_tgts[lovreq->rq_idx];
if (!tgt || !tgt->ltd_active)
goto out_update;
tgtobd = class_exp2obd(tgt->ltd_exp);
spin_lock(&tgtobd->obd_osfs_lock);
memcpy(&tgtobd->obd_osfs, lov_sfs, sizeof(*lov_sfs));
if ((oinfo->oi_flags & OBD_STATFS_FROM_CACHE) == 0)
tgtobd->obd_osfs_age = cfs_time_current_64();
spin_unlock(&tgtobd->obd_osfs_lock);
out_update:
lov_update_statfs(osfs, lov_sfs, success);
obd_putref(lovobd);
out:
if (set->set_oi->oi_flags & OBD_STATFS_PTLRPCD &&
lov_set_finished(set, 0)) {
lov_statfs_interpret(NULL, set, set->set_count !=
atomic_read(&set->set_success));
}
return 0;
}
int lov_prep_statfs_set(struct obd_device *obd, struct obd_info *oinfo,
struct lov_request_set **reqset)
{
struct lov_request_set *set;
struct lov_obd *lov = &obd->u.lov;
int rc = 0, i;
set = kzalloc(sizeof(*set), GFP_NOFS);
if (!set)
return -ENOMEM;
lov_init_set(set);
set->set_obd = obd;
set->set_oi = oinfo;
for (i = 0; i < lov->desc.ld_tgt_count; i++) {
struct lov_request *req;
if (!lov->lov_tgts[i] ||
(oinfo->oi_flags & OBD_STATFS_NODELAY &&
!lov->lov_tgts[i]->ltd_active)) {
CDEBUG(D_HA, "lov idx %d inactive\n", i);
continue;
}
if (!lov->lov_tgts[i]->ltd_active)
lov_check_and_wait_active(lov, i);
if (!lov->lov_tgts[i]->ltd_exp) {
CDEBUG(D_HA, "lov idx %d administratively disabled\n", i);
continue;
}
req = kzalloc(sizeof(*req), GFP_NOFS);
if (!req) {
rc = -ENOMEM;
goto out_set;
}
req->rq_oi.oi_osfs = kzalloc(sizeof(*req->rq_oi.oi_osfs),
GFP_NOFS);
if (!req->rq_oi.oi_osfs) {
kfree(req);
rc = -ENOMEM;
goto out_set;
}
req->rq_idx = i;
req->rq_oi.oi_cb_up = cb_statfs_update;
req->rq_oi.oi_flags = oinfo->oi_flags;
lov_set_add_req(req, set);
}
if (!set->set_count) {
rc = -EIO;
goto out_set;
}
*reqset = set;
return rc;
out_set:
lov_fini_statfs_set(set);
return rc;
}
