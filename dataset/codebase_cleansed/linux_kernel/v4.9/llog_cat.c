static int llog_cat_id2handle(const struct lu_env *env,
struct llog_handle *cathandle,
struct llog_handle **res,
struct llog_logid *logid)
{
struct llog_handle *loghandle;
enum llog_flag fmt;
int rc = 0;
if (!cathandle)
return -EBADF;
fmt = cathandle->lgh_hdr->llh_flags & LLOG_F_EXT_MASK;
down_write(&cathandle->lgh_lock);
list_for_each_entry(loghandle, &cathandle->u.chd.chd_head,
u.phd.phd_entry) {
struct llog_logid *cgl = &loghandle->lgh_id;
if (ostid_id(&cgl->lgl_oi) == ostid_id(&logid->lgl_oi) &&
ostid_seq(&cgl->lgl_oi) == ostid_seq(&logid->lgl_oi)) {
if (cgl->lgl_ogen != logid->lgl_ogen) {
CERROR("%s: log "DOSTID" generation %x != %x\n",
loghandle->lgh_ctxt->loc_obd->obd_name,
POSTID(&logid->lgl_oi), cgl->lgl_ogen,
logid->lgl_ogen);
continue;
}
loghandle->u.phd.phd_cat_handle = cathandle;
up_write(&cathandle->lgh_lock);
rc = 0;
goto out;
}
}
up_write(&cathandle->lgh_lock);
rc = llog_open(env, cathandle->lgh_ctxt, &loghandle, logid, NULL,
LLOG_OPEN_EXISTS);
if (rc < 0) {
CERROR("%s: error opening log id "DOSTID":%x: rc = %d\n",
cathandle->lgh_ctxt->loc_obd->obd_name,
POSTID(&logid->lgl_oi), logid->lgl_ogen, rc);
return rc;
}
rc = llog_init_handle(env, loghandle, fmt | LLOG_F_IS_PLAIN, NULL);
if (rc < 0) {
llog_close(env, loghandle);
loghandle = NULL;
return rc;
}
down_write(&cathandle->lgh_lock);
list_add_tail(&loghandle->u.phd.phd_entry, &cathandle->u.chd.chd_head);
up_write(&cathandle->lgh_lock);
loghandle->u.phd.phd_cat_handle = cathandle;
loghandle->u.phd.phd_cookie.lgc_lgl = cathandle->lgh_id;
loghandle->u.phd.phd_cookie.lgc_index =
loghandle->lgh_hdr->llh_cat_idx;
out:
llog_handle_get(loghandle);
*res = loghandle;
return 0;
}
int llog_cat_close(const struct lu_env *env, struct llog_handle *cathandle)
{
struct llog_handle *loghandle, *n;
list_for_each_entry_safe(loghandle, n, &cathandle->u.chd.chd_head,
u.phd.phd_entry) {
list_del_init(&loghandle->u.phd.phd_entry);
llog_close(env, loghandle);
}
if (cathandle->lgh_ctxt->loc_handle == cathandle)
cathandle->lgh_ctxt->loc_handle = NULL;
return llog_close(env, cathandle);
}
static int llog_cat_process_cb(const struct lu_env *env,
struct llog_handle *cat_llh,
struct llog_rec_hdr *rec, void *data)
{
struct llog_process_data *d = data;
struct llog_logid_rec *lir = (struct llog_logid_rec *)rec;
struct llog_handle *llh;
int rc;
if (rec->lrh_type != LLOG_LOGID_MAGIC) {
CERROR("invalid record in catalog\n");
return -EINVAL;
}
CDEBUG(D_HA, "processing log "DOSTID":%x at index %u of catalog "
DOSTID"\n", POSTID(&lir->lid_id.lgl_oi), lir->lid_id.lgl_ogen,
rec->lrh_index, POSTID(&cat_llh->lgh_id.lgl_oi));
rc = llog_cat_id2handle(env, cat_llh, &llh, &lir->lid_id);
if (rc) {
CERROR("%s: cannot find handle for llog "DOSTID": %d\n",
cat_llh->lgh_ctxt->loc_obd->obd_name,
POSTID(&lir->lid_id.lgl_oi), rc);
return rc;
}
if (rec->lrh_index < d->lpd_startcat)
rc = 0;
else if (d->lpd_startidx > 0) {
struct llog_process_cat_data cd;
cd.lpcd_first_idx = d->lpd_startidx;
cd.lpcd_last_idx = 0;
rc = llog_process_or_fork(env, llh, d->lpd_cb, d->lpd_data,
&cd, false);
d->lpd_startidx = 0;
} else {
rc = llog_process_or_fork(env, llh, d->lpd_cb, d->lpd_data,
NULL, false);
}
llog_handle_put(llh);
return rc;
}
static int llog_cat_process_or_fork(const struct lu_env *env,
struct llog_handle *cat_llh,
llog_cb_t cb, void *data, int startcat,
int startidx, bool fork)
{
struct llog_process_data d;
struct llog_log_hdr *llh = cat_llh->lgh_hdr;
int rc;
LASSERT(llh->llh_flags & LLOG_F_IS_CAT);
d.lpd_data = data;
d.lpd_cb = cb;
d.lpd_startcat = startcat;
d.lpd_startidx = startidx;
if (llh->llh_cat_idx > cat_llh->lgh_last_idx) {
struct llog_process_cat_data cd;
CWARN("catlog "DOSTID" crosses index zero\n",
POSTID(&cat_llh->lgh_id.lgl_oi));
cd.lpcd_first_idx = llh->llh_cat_idx;
cd.lpcd_last_idx = 0;
rc = llog_process_or_fork(env, cat_llh, llog_cat_process_cb,
&d, &cd, fork);
if (rc != 0)
return rc;
cd.lpcd_first_idx = 0;
cd.lpcd_last_idx = cat_llh->lgh_last_idx;
rc = llog_process_or_fork(env, cat_llh, llog_cat_process_cb,
&d, &cd, fork);
} else {
rc = llog_process_or_fork(env, cat_llh, llog_cat_process_cb,
&d, NULL, fork);
}
return rc;
}
int llog_cat_process(const struct lu_env *env, struct llog_handle *cat_llh,
llog_cb_t cb, void *data, int startcat, int startidx)
{
return llog_cat_process_or_fork(env, cat_llh, cb, data, startcat,
startidx, false);
}
