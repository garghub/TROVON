static int llog_osd_declare_new_object(const struct lu_env *env,
struct local_oid_storage *los,
struct dt_object *o,
struct thandle *th)
{
struct llog_thread_info *lgi = llog_info(env);
lgi->lgi_attr.la_valid = LA_MODE;
lgi->lgi_attr.la_mode = S_IFREG | S_IRUGO | S_IWUSR;
lgi->lgi_dof.dof_type = dt_mode_to_dft(S_IFREG);
return local_object_declare_create(env, los, o, &lgi->lgi_attr,
&lgi->lgi_dof, th);
}
static int llog_osd_create_new_object(const struct lu_env *env,
struct local_oid_storage *los,
struct dt_object *o,
struct thandle *th)
{
struct llog_thread_info *lgi = llog_info(env);
lgi->lgi_attr.la_valid = LA_MODE;
lgi->lgi_attr.la_mode = S_IFREG | S_IRUGO | S_IWUSR;
lgi->lgi_dof.dof_type = dt_mode_to_dft(S_IFREG);
return local_object_create(env, los, o, &lgi->lgi_attr,
&lgi->lgi_dof, th);
}
static int llog_osd_pad(const struct lu_env *env, struct dt_object *o,
loff_t *off, int len, int index, struct thandle *th)
{
struct llog_thread_info *lgi = llog_info(env);
int rc;
ENTRY;
LASSERT(th);
LASSERT(off);
LASSERT(len >= LLOG_MIN_REC_SIZE && (len & 0x7) == 0);
lgi->lgi_tail.lrt_len = lgi->lgi_lrh.lrh_len = len;
lgi->lgi_tail.lrt_index = lgi->lgi_lrh.lrh_index = index;
lgi->lgi_lrh.lrh_type = LLOG_PAD_MAGIC;
lgi->lgi_buf.lb_buf = &lgi->lgi_lrh;
lgi->lgi_buf.lb_len = sizeof(lgi->lgi_lrh);
dt_write_lock(env, o, 0);
rc = dt_record_write(env, o, &lgi->lgi_buf, off, th);
if (rc) {
CERROR("%s: error writing padding record: rc = %d\n",
o->do_lu.lo_dev->ld_obd->obd_name, rc);
GOTO(out, rc);
}
lgi->lgi_buf.lb_buf = &lgi->lgi_tail;
lgi->lgi_buf.lb_len = sizeof(lgi->lgi_tail);
*off += len - sizeof(lgi->lgi_lrh) - sizeof(lgi->lgi_tail);
rc = dt_record_write(env, o, &lgi->lgi_buf, off, th);
if (rc)
CERROR("%s: error writing padding record: rc = %d\n",
o->do_lu.lo_dev->ld_obd->obd_name, rc);
out:
dt_write_unlock(env, o);
RETURN(rc);
}
static int llog_osd_write_blob(const struct lu_env *env, struct dt_object *o,
struct llog_rec_hdr *rec, void *buf,
loff_t *off, struct thandle *th)
{
struct llog_thread_info *lgi = llog_info(env);
int buflen = rec->lrh_len;
int rc;
ENTRY;
LASSERT(env);
LASSERT(o);
if (buflen == 0)
CWARN("0-length record\n");
CDEBUG(D_OTHER, "write blob with type %x, buf %p/%u at off %llu\n",
rec->lrh_type, buf, buflen, *off);
lgi->lgi_attr.la_valid = LA_SIZE;
lgi->lgi_attr.la_size = *off;
if (!buf) {
lgi->lgi_buf.lb_len = buflen;
lgi->lgi_buf.lb_buf = rec;
rc = dt_record_write(env, o, &lgi->lgi_buf, off, th);
if (rc)
CERROR("%s: error writing log record: rc = %d\n",
o->do_lu.lo_dev->ld_obd->obd_name, rc);
GOTO(out, rc);
}
dt_write_lock(env, o, 0);
rec->lrh_len = sizeof(*rec) + buflen + sizeof(lgi->lgi_tail);
lgi->lgi_buf.lb_len = sizeof(*rec);
lgi->lgi_buf.lb_buf = rec;
rc = dt_record_write(env, o, &lgi->lgi_buf, off, th);
if (rc) {
CERROR("%s: error writing log hdr: rc = %d\n",
o->do_lu.lo_dev->ld_obd->obd_name, rc);
GOTO(out_unlock, rc);
}
lgi->lgi_buf.lb_len = buflen;
lgi->lgi_buf.lb_buf = buf;
rc = dt_record_write(env, o, &lgi->lgi_buf, off, th);
if (rc) {
CERROR("%s: error writing log buffer: rc = %d\n",
o->do_lu.lo_dev->ld_obd->obd_name, rc);
GOTO(out_unlock, rc);
}
lgi->lgi_tail.lrt_len = rec->lrh_len;
lgi->lgi_tail.lrt_index = rec->lrh_index;
lgi->lgi_buf.lb_len = sizeof(lgi->lgi_tail);
lgi->lgi_buf.lb_buf = &lgi->lgi_tail;
rc = dt_record_write(env, o, &lgi->lgi_buf, off, th);
if (rc)
CERROR("%s: error writing log tail: rc = %d\n",
o->do_lu.lo_dev->ld_obd->obd_name, rc);
out_unlock:
dt_write_unlock(env, o);
out:
if (rc) {
dt_punch(env, o, lgi->lgi_attr.la_size, OBD_OBJECT_EOF, th,
BYPASS_CAPA);
dt_attr_set(env, o, &lgi->lgi_attr, th, BYPASS_CAPA);
}
RETURN(rc);
}
static int llog_osd_read_header(const struct lu_env *env,
struct llog_handle *handle)
{
struct llog_rec_hdr *llh_hdr;
struct dt_object *o;
struct llog_thread_info *lgi;
int rc;
ENTRY;
LASSERT(sizeof(*handle->lgh_hdr) == LLOG_CHUNK_SIZE);
o = handle->lgh_obj;
LASSERT(o);
lgi = llog_info(env);
rc = dt_attr_get(env, o, &lgi->lgi_attr, NULL);
if (rc)
RETURN(rc);
LASSERT(lgi->lgi_attr.la_valid & LA_SIZE);
if (lgi->lgi_attr.la_size == 0) {
CDEBUG(D_HA, "not reading header from 0-byte log\n");
RETURN(LLOG_EEMPTY);
}
lgi->lgi_off = 0;
lgi->lgi_buf.lb_buf = handle->lgh_hdr;
lgi->lgi_buf.lb_len = LLOG_CHUNK_SIZE;
rc = dt_record_read(env, o, &lgi->lgi_buf, &lgi->lgi_off);
if (rc) {
CERROR("%s: error reading log header from "DFID": rc = %d\n",
o->do_lu.lo_dev->ld_obd->obd_name,
PFID(lu_object_fid(&o->do_lu)), rc);
RETURN(rc);
}
llh_hdr = &handle->lgh_hdr->llh_hdr;
if (LLOG_REC_HDR_NEEDS_SWABBING(llh_hdr))
lustre_swab_llog_hdr(handle->lgh_hdr);
if (llh_hdr->lrh_type != LLOG_HDR_MAGIC) {
CERROR("%s: bad log %s "DFID" header magic: %#x "
"(expected %#x)\n", o->do_lu.lo_dev->ld_obd->obd_name,
handle->lgh_name ? handle->lgh_name : "",
PFID(lu_object_fid(&o->do_lu)),
llh_hdr->lrh_type, LLOG_HDR_MAGIC);
RETURN(-EIO);
} else if (llh_hdr->lrh_len != LLOG_CHUNK_SIZE) {
CERROR("%s: incorrectly sized log %s "DFID" header: "
"%#x (expected %#x)\n"
"you may need to re-run lconf --write_conf.\n",
o->do_lu.lo_dev->ld_obd->obd_name,
handle->lgh_name ? handle->lgh_name : "",
PFID(lu_object_fid(&o->do_lu)),
llh_hdr->lrh_len, LLOG_CHUNK_SIZE);
RETURN(-EIO);
}
handle->lgh_last_idx = handle->lgh_hdr->llh_tail.lrt_index;
RETURN(0);
}
static int llog_osd_declare_write_rec(const struct lu_env *env,
struct llog_handle *loghandle,
struct llog_rec_hdr *rec,
int idx, struct thandle *th)
{
struct llog_thread_info *lgi = llog_info(env);
struct dt_object *o;
int rc;
ENTRY;
LASSERT(env);
LASSERT(th);
LASSERT(loghandle);
o = loghandle->lgh_obj;
LASSERT(o);
rc = dt_declare_record_write(env, o, sizeof(struct llog_log_hdr), 0,
th);
if (rc || idx == 0)
RETURN(rc);
if (dt_object_exists(o)) {
rc = dt_attr_get(env, o, &lgi->lgi_attr, BYPASS_CAPA);
lgi->lgi_off = lgi->lgi_attr.la_size;
LASSERT(ergo(rc == 0, lgi->lgi_attr.la_valid & LA_SIZE));
if (rc)
RETURN(rc);
rc = dt_declare_punch(env, o, lgi->lgi_off, OBD_OBJECT_EOF, th);
if (rc)
RETURN(rc);
} else {
lgi->lgi_off = 0;
}
rc = dt_declare_record_write(env, o, 32 * 1024, lgi->lgi_off, th);
RETURN(rc);
}
static int llog_osd_write_rec(const struct lu_env *env,
struct llog_handle *loghandle,
struct llog_rec_hdr *rec,
struct llog_cookie *reccookie, int cookiecount,
void *buf, int idx, struct thandle *th)
{
struct llog_thread_info *lgi = llog_info(env);
struct llog_log_hdr *llh;
int reclen = rec->lrh_len;
int index, rc, old_tail_idx;
struct llog_rec_tail *lrt;
struct dt_object *o;
size_t left;
ENTRY;
LASSERT(env);
llh = loghandle->lgh_hdr;
LASSERT(llh);
o = loghandle->lgh_obj;
LASSERT(o);
LASSERT(th);
CDEBUG(D_OTHER, "new record %x to "DFID"\n",
rec->lrh_type, PFID(lu_object_fid(&o->do_lu)));
if (buf)
rc = (reclen > LLOG_CHUNK_SIZE - sizeof(struct llog_rec_hdr) -
sizeof(struct llog_rec_tail)) ? -E2BIG : 0;
else
rc = (reclen > LLOG_CHUNK_SIZE) ? -E2BIG : 0;
if (rc)
RETURN(rc);
rc = dt_attr_get(env, o, &lgi->lgi_attr, NULL);
if (rc)
RETURN(rc);
if (buf)
reclen = sizeof(*rec) + rec->lrh_len +
sizeof(struct llog_rec_tail);
if (idx != -1) {
if (idx != 1 && lgi->lgi_attr.la_size == 0)
LBUG();
if (idx && llh->llh_size && llh->llh_size != rec->lrh_len)
RETURN(-EINVAL);
if (!ext2_test_bit(idx, llh->llh_bitmap))
CERROR("%s: modify unset record %u\n",
o->do_lu.lo_dev->ld_obd->obd_name, idx);
if (idx != rec->lrh_index)
CERROR("%s: index mismatch %d %u\n",
o->do_lu.lo_dev->ld_obd->obd_name, idx,
rec->lrh_index);
lgi->lgi_off = 0;
rc = llog_osd_write_blob(env, o, &llh->llh_hdr, NULL,
&lgi->lgi_off, th);
if (rc || idx == 0)
RETURN(rc);
if (buf) {
lgi->lgi_off = loghandle->lgh_cur_offset;
CDEBUG(D_OTHER,
"modify record "DOSTID": idx:%d/%u/%d, len:%u "
"offset %llu\n",
POSTID(&loghandle->lgh_id.lgl_oi), idx,
rec->lrh_index,
loghandle->lgh_cur_idx, rec->lrh_len,
(long long)(lgi->lgi_off - sizeof(*llh)));
if (rec->lrh_index != loghandle->lgh_cur_idx) {
CERROR("%s: modify idx mismatch %u/%d\n",
o->do_lu.lo_dev->ld_obd->obd_name, idx,
loghandle->lgh_cur_idx);
RETURN(-EFAULT);
}
} else {
lgi->lgi_off = sizeof(*llh) + (idx - 1) * reclen;
}
rc = llog_osd_write_blob(env, o, rec, buf, &lgi->lgi_off, th);
if (rc == 0 && reccookie) {
reccookie->lgc_lgl = loghandle->lgh_id;
reccookie->lgc_index = idx;
rc = 1;
}
RETURN(rc);
}
LASSERT(lgi->lgi_attr.la_valid & LA_SIZE);
lgi->lgi_off = lgi->lgi_attr.la_size;
left = LLOG_CHUNK_SIZE - (lgi->lgi_off & (LLOG_CHUNK_SIZE - 1));
if (left != 0 && left != reclen &&
left < (reclen + LLOG_MIN_REC_SIZE)) {
index = loghandle->lgh_last_idx + 1;
rc = llog_osd_pad(env, o, &lgi->lgi_off, left, index, th);
if (rc)
RETURN(rc);
loghandle->lgh_last_idx++;
}
if (loghandle->lgh_last_idx >= LLOG_BITMAP_SIZE(llh) - 1)
RETURN(-ENOSPC);
loghandle->lgh_last_idx++;
index = loghandle->lgh_last_idx;
LASSERT(index < LLOG_BITMAP_SIZE(llh));
rec->lrh_index = index;
if (buf == NULL) {
lrt = (struct llog_rec_tail *)((char *)rec + rec->lrh_len -
sizeof(*lrt));
lrt->lrt_len = rec->lrh_len;
lrt->lrt_index = rec->lrh_index;
}
LASSERT(index < LLOG_BITMAP_SIZE(llh));
spin_lock(&loghandle->lgh_hdr_lock);
if (ext2_set_bit(index, llh->llh_bitmap)) {
CERROR("%s: index %u already set in log bitmap\n",
o->do_lu.lo_dev->ld_obd->obd_name, index);
spin_unlock(&loghandle->lgh_hdr_lock);
LBUG();
}
llh->llh_count++;
spin_unlock(&loghandle->lgh_hdr_lock);
old_tail_idx = llh->llh_tail.lrt_index;
llh->llh_tail.lrt_index = index;
lgi->lgi_off = 0;
rc = llog_osd_write_blob(env, o, &llh->llh_hdr, NULL, &lgi->lgi_off,
th);
if (rc)
GOTO(out, rc);
rc = dt_attr_get(env, o, &lgi->lgi_attr, NULL);
if (rc)
GOTO(out, rc);
LASSERT(lgi->lgi_attr.la_valid & LA_SIZE);
lgi->lgi_off = lgi->lgi_attr.la_size;
rc = llog_osd_write_blob(env, o, rec, buf, &lgi->lgi_off, th);
out:
if (rc) {
spin_lock(&loghandle->lgh_hdr_lock);
ext2_clear_bit(index, llh->llh_bitmap);
llh->llh_count--;
spin_unlock(&loghandle->lgh_hdr_lock);
loghandle->lgh_last_idx--;
llh->llh_tail.lrt_index = old_tail_idx;
lgi->lgi_off = 0;
llog_osd_write_blob(env, o, &llh->llh_hdr, NULL,
&lgi->lgi_off, th);
}
CDEBUG(D_RPCTRACE, "added record "DOSTID": idx: %u, %u\n",
POSTID(&loghandle->lgh_id.lgl_oi), index, rec->lrh_len);
if (rc == 0 && reccookie) {
reccookie->lgc_lgl = loghandle->lgh_id;
reccookie->lgc_index = index;
if ((rec->lrh_type == MDS_UNLINK_REC) ||
(rec->lrh_type == MDS_SETATTR64_REC))
reccookie->lgc_subsys = LLOG_MDS_OST_ORIG_CTXT;
else if (rec->lrh_type == OST_SZ_REC)
reccookie->lgc_subsys = LLOG_SIZE_ORIG_CTXT;
else
reccookie->lgc_subsys = -1;
rc = 1;
}
RETURN(rc);
}
static void llog_skip_over(__u64 *off, int curr, int goal)
{
if (goal <= curr)
return;
*off = (*off + (goal - curr - 1) * LLOG_MIN_REC_SIZE) &
~(LLOG_CHUNK_SIZE - 1);
}
static int llog_osd_next_block(const struct lu_env *env,
struct llog_handle *loghandle, int *cur_idx,
int next_idx, __u64 *cur_offset, void *buf,
int len)
{
struct llog_thread_info *lgi = llog_info(env);
struct dt_object *o;
struct dt_device *dt;
int rc;
ENTRY;
LASSERT(env);
LASSERT(lgi);
if (len == 0 || len & (LLOG_CHUNK_SIZE - 1))
RETURN(-EINVAL);
CDEBUG(D_OTHER, "looking for log index %u (cur idx %u off "LPU64")\n",
next_idx, *cur_idx, *cur_offset);
LASSERT(loghandle);
LASSERT(loghandle->lgh_ctxt);
o = loghandle->lgh_obj;
LASSERT(o);
LASSERT(dt_object_exists(o));
dt = lu2dt_dev(o->do_lu.lo_dev);
LASSERT(dt);
rc = dt_attr_get(env, o, &lgi->lgi_attr, BYPASS_CAPA);
if (rc)
GOTO(out, rc);
while (*cur_offset < lgi->lgi_attr.la_size) {
struct llog_rec_hdr *rec, *last_rec;
struct llog_rec_tail *tail;
llog_skip_over(cur_offset, *cur_idx, next_idx);
lgi->lgi_buf.lb_len = LLOG_CHUNK_SIZE -
(*cur_offset & (LLOG_CHUNK_SIZE - 1));
lgi->lgi_buf.lb_buf = buf;
dt_read_lock(env, o, 0);
rc = dt_read(env, o, &lgi->lgi_buf, cur_offset);
dt_read_unlock(env, o);
if (rc < 0) {
CERROR("%s: can't read llog block from log "DFID
" offset "LPU64": rc = %d\n",
o->do_lu.lo_dev->ld_obd->obd_name,
PFID(lu_object_fid(&o->do_lu)), *cur_offset,
rc);
GOTO(out, rc);
}
if (rc < len) {
memset(buf + rc, 0, len - rc);
}
if (rc == 0)
GOTO(out, rc);
if (rc < sizeof(*tail)) {
CERROR("%s: invalid llog block at log id "DOSTID"/%u "
"offset "LPU64"\n",
o->do_lu.lo_dev->ld_obd->obd_name,
POSTID(&loghandle->lgh_id.lgl_oi),
loghandle->lgh_id.lgl_ogen, *cur_offset);
GOTO(out, rc = -EINVAL);
}
rec = buf;
if (LLOG_REC_HDR_NEEDS_SWABBING(rec))
lustre_swab_llog_rec(rec);
tail = (struct llog_rec_tail *)((char *)buf + rc -
sizeof(struct llog_rec_tail));
last_rec = (struct llog_rec_hdr *)((char *)buf + rc -
le32_to_cpu(tail->lrt_len));
if (LLOG_REC_HDR_NEEDS_SWABBING(last_rec))
lustre_swab_llog_rec(last_rec);
LASSERT(last_rec->lrh_index == tail->lrt_index);
*cur_idx = tail->lrt_index;
if (tail->lrt_index == 0) {
CERROR("%s: invalid llog tail at log id "DOSTID"/%u "
"offset "LPU64"\n",
o->do_lu.lo_dev->ld_obd->obd_name,
POSTID(&loghandle->lgh_id.lgl_oi),
loghandle->lgh_id.lgl_ogen, *cur_offset);
GOTO(out, rc = -EINVAL);
}
if (tail->lrt_index < next_idx)
continue;
if (rec->lrh_index > next_idx) {
CERROR("%s: missed desired record? %u > %u\n",
o->do_lu.lo_dev->ld_obd->obd_name,
rec->lrh_index, next_idx);
GOTO(out, rc = -ENOENT);
}
GOTO(out, rc = 0);
}
GOTO(out, rc = -EIO);
out:
return rc;
}
static int llog_osd_prev_block(const struct lu_env *env,
struct llog_handle *loghandle,
int prev_idx, void *buf, int len)
{
struct llog_thread_info *lgi = llog_info(env);
struct dt_object *o;
struct dt_device *dt;
loff_t cur_offset;
int rc;
ENTRY;
if (len == 0 || len & (LLOG_CHUNK_SIZE - 1))
RETURN(-EINVAL);
CDEBUG(D_OTHER, "looking for log index %u\n", prev_idx);
LASSERT(loghandle);
LASSERT(loghandle->lgh_ctxt);
o = loghandle->lgh_obj;
LASSERT(o);
LASSERT(dt_object_exists(o));
dt = lu2dt_dev(o->do_lu.lo_dev);
LASSERT(dt);
cur_offset = LLOG_CHUNK_SIZE;
llog_skip_over(&cur_offset, 0, prev_idx);
rc = dt_attr_get(env, o, &lgi->lgi_attr, BYPASS_CAPA);
if (rc)
GOTO(out, rc);
while (cur_offset < lgi->lgi_attr.la_size) {
struct llog_rec_hdr *rec, *last_rec;
struct llog_rec_tail *tail;
lgi->lgi_buf.lb_len = len;
lgi->lgi_buf.lb_buf = buf;
dt_read_lock(env, o, 0);
rc = dt_read(env, o, &lgi->lgi_buf, &cur_offset);
dt_read_unlock(env, o);
if (rc < 0) {
CERROR("%s: can't read llog block from log "DFID
" offset "LPU64": rc = %d\n",
o->do_lu.lo_dev->ld_obd->obd_name,
PFID(lu_object_fid(&o->do_lu)), cur_offset, rc);
GOTO(out, rc);
}
if (rc == 0)
GOTO(out, rc);
if (rc < sizeof(*tail)) {
CERROR("%s: invalid llog block at log id "DOSTID"/%u "
"offset "LPU64"\n",
o->do_lu.lo_dev->ld_obd->obd_name,
POSTID(&loghandle->lgh_id.lgl_oi),
loghandle->lgh_id.lgl_ogen, cur_offset);
GOTO(out, rc = -EINVAL);
}
rec = buf;
if (LLOG_REC_HDR_NEEDS_SWABBING(rec))
lustre_swab_llog_rec(rec);
tail = (struct llog_rec_tail *)((char *)buf + rc -
sizeof(struct llog_rec_tail));
last_rec = (struct llog_rec_hdr *)((char *)buf + rc -
le32_to_cpu(tail->lrt_len));
if (LLOG_REC_HDR_NEEDS_SWABBING(last_rec))
lustre_swab_llog_rec(last_rec);
LASSERT(last_rec->lrh_index == tail->lrt_index);
if (tail->lrt_index == 0) {
CERROR("%s: invalid llog tail at log id "DOSTID"/%u "
"offset "LPU64"\n",
o->do_lu.lo_dev->ld_obd->obd_name,
POSTID(&loghandle->lgh_id.lgl_oi),
loghandle->lgh_id.lgl_ogen, cur_offset);
GOTO(out, rc = -EINVAL);
}
if (tail->lrt_index < prev_idx)
continue;
if (rec->lrh_index > prev_idx) {
CERROR("%s: missed desired record? %u > %u\n",
o->do_lu.lo_dev->ld_obd->obd_name,
rec->lrh_index, prev_idx);
GOTO(out, rc = -ENOENT);
}
GOTO(out, rc = 0);
}
GOTO(out, rc = -EIO);
out:
return rc;
}
struct dt_object *llog_osd_dir_get(const struct lu_env *env,
struct llog_ctxt *ctxt)
{
struct dt_device *dt;
struct dt_thread_info *dti = dt_info(env);
struct dt_object *dir;
int rc;
dt = ctxt->loc_exp->exp_obd->obd_lvfs_ctxt.dt;
if (ctxt->loc_dir == NULL) {
rc = dt_root_get(env, dt, &dti->dti_fid);
if (rc)
return ERR_PTR(rc);
dir = dt_locate(env, dt, &dti->dti_fid);
} else {
lu_object_get(&ctxt->loc_dir->do_lu);
dir = ctxt->loc_dir;
}
return dir;
}
static int llog_osd_open(const struct lu_env *env, struct llog_handle *handle,
struct llog_logid *logid, char *name,
enum llog_open_param open_param)
{
struct llog_thread_info *lgi = llog_info(env);
struct llog_ctxt *ctxt = handle->lgh_ctxt;
struct dt_object *o;
struct dt_device *dt;
struct ls_device *ls;
struct local_oid_storage *los;
int rc = 0;
ENTRY;
LASSERT(env);
LASSERT(ctxt);
LASSERT(ctxt->loc_exp);
LASSERT(ctxt->loc_exp->exp_obd);
dt = ctxt->loc_exp->exp_obd->obd_lvfs_ctxt.dt;
LASSERT(dt);
ls = ls_device_get(dt);
if (IS_ERR(ls))
RETURN(PTR_ERR(ls));
mutex_lock(&ls->ls_los_mutex);
los = dt_los_find(ls, name != NULL ? FID_SEQ_LLOG_NAME : FID_SEQ_LLOG);
mutex_unlock(&ls->ls_los_mutex);
LASSERT(los);
ls_device_put(env, ls);
LASSERT(handle);
if (logid != NULL) {
logid_to_fid(logid, &lgi->lgi_fid);
} else if (name) {
struct dt_object *llog_dir;
llog_dir = llog_osd_dir_get(env, ctxt);
if (IS_ERR(llog_dir))
GOTO(out, rc = PTR_ERR(llog_dir));
dt_read_lock(env, llog_dir, 0);
rc = dt_lookup_dir(env, llog_dir, name, &lgi->lgi_fid);
dt_read_unlock(env, llog_dir);
lu_object_put(env, &llog_dir->do_lu);
if (rc == -ENOENT && open_param == LLOG_OPEN_NEW) {
rc = local_object_fid_generate(env, los,
&lgi->lgi_fid);
}
if (rc < 0)
GOTO(out, rc);
OBD_ALLOC(handle->lgh_name, strlen(name) + 1);
if (handle->lgh_name)
strcpy(handle->lgh_name, name);
else
GOTO(out, rc = -ENOMEM);
} else {
LASSERTF(open_param & LLOG_OPEN_NEW, "%#x\n", open_param);
rc = local_object_fid_generate(env, los, &lgi->lgi_fid);
if (rc < 0)
GOTO(out, rc);
}
o = ls_locate(env, ls, &lgi->lgi_fid);
if (IS_ERR(o))
GOTO(out_name, rc = PTR_ERR(o));
if (open_param != LLOG_OPEN_NEW && !dt_object_exists(o))
GOTO(out_put, rc = -ENOENT);
fid_to_logid(&lgi->lgi_fid, &handle->lgh_id);
handle->lgh_obj = o;
handle->private_data = los;
LASSERT(handle->lgh_ctxt);
RETURN(rc);
out_put:
lu_object_put(env, &o->do_lu);
out_name:
if (handle->lgh_name != NULL)
OBD_FREE(handle->lgh_name, strlen(name) + 1);
out:
dt_los_put(los);
RETURN(rc);
}
static int llog_osd_exist(struct llog_handle *handle)
{
LASSERT(handle->lgh_obj);
return (dt_object_exists(handle->lgh_obj) &&
!lu_object_is_dying(handle->lgh_obj->do_lu.lo_header));
}
static int llog_osd_declare_create(const struct lu_env *env,
struct llog_handle *res, struct thandle *th)
{
struct llog_thread_info *lgi = llog_info(env);
struct local_oid_storage *los;
struct dt_object *o;
int rc;
ENTRY;
LASSERT(res->lgh_obj);
LASSERT(th);
o = res->lgh_obj;
if (dt_object_exists(o))
RETURN(0);
los = res->private_data;
LASSERT(los);
rc = llog_osd_declare_new_object(env, los, o, th);
if (rc)
RETURN(rc);
rc = dt_declare_record_write(env, o, LLOG_CHUNK_SIZE, 0, th);
if (rc)
RETURN(rc);
if (res->lgh_name) {
struct dt_object *llog_dir;
llog_dir = llog_osd_dir_get(env, res->lgh_ctxt);
if (IS_ERR(llog_dir))
RETURN(PTR_ERR(llog_dir));
logid_to_fid(&res->lgh_id, &lgi->lgi_fid);
rc = dt_declare_insert(env, llog_dir,
(struct dt_rec *)&lgi->lgi_fid,
(struct dt_key *)res->lgh_name, th);
lu_object_put(env, &llog_dir->do_lu);
if (rc)
CERROR("%s: can't declare named llog %s: rc = %d\n",
o->do_lu.lo_dev->ld_obd->obd_name,
res->lgh_name, rc);
}
RETURN(rc);
}
static int llog_osd_create(const struct lu_env *env, struct llog_handle *res,
struct thandle *th)
{
struct llog_thread_info *lgi = llog_info(env);
struct local_oid_storage *los;
struct dt_object *o;
int rc = 0;
ENTRY;
LASSERT(env);
o = res->lgh_obj;
LASSERT(o);
if (dt_object_exists(o))
RETURN(-EEXIST);
los = res->private_data;
LASSERT(los);
dt_write_lock(env, o, 0);
if (!dt_object_exists(o))
rc = llog_osd_create_new_object(env, los, o, th);
else
rc = -EEXIST;
dt_write_unlock(env, o);
if (rc)
RETURN(rc);
if (res->lgh_name) {
struct dt_object *llog_dir;
llog_dir = llog_osd_dir_get(env, res->lgh_ctxt);
if (IS_ERR(llog_dir))
RETURN(PTR_ERR(llog_dir));
logid_to_fid(&res->lgh_id, &lgi->lgi_fid);
dt_read_lock(env, llog_dir, 0);
rc = dt_insert(env, llog_dir,
(struct dt_rec *)&lgi->lgi_fid,
(struct dt_key *)res->lgh_name,
th, BYPASS_CAPA, 1);
dt_read_unlock(env, llog_dir);
lu_object_put(env, &llog_dir->do_lu);
if (rc)
CERROR("%s: can't create named llog %s: rc = %d\n",
o->do_lu.lo_dev->ld_obd->obd_name,
res->lgh_name, rc);
}
RETURN(rc);
}
static int llog_osd_close(const struct lu_env *env, struct llog_handle *handle)
{
struct local_oid_storage *los;
int rc = 0;
ENTRY;
LASSERT(handle->lgh_obj);
lu_object_put(env, &handle->lgh_obj->do_lu);
los = handle->private_data;
LASSERT(los);
dt_los_put(los);
if (handle->lgh_name)
OBD_FREE(handle->lgh_name, strlen(handle->lgh_name) + 1);
RETURN(rc);
}
static int llog_osd_destroy(const struct lu_env *env,
struct llog_handle *loghandle)
{
struct llog_ctxt *ctxt;
struct dt_object *o, *llog_dir = NULL;
struct dt_device *d;
struct thandle *th;
char *name = NULL;
int rc;
ENTRY;
ctxt = loghandle->lgh_ctxt;
LASSERT(ctxt);
o = loghandle->lgh_obj;
LASSERT(o);
d = lu2dt_dev(o->do_lu.lo_dev);
LASSERT(d);
LASSERT(d == ctxt->loc_exp->exp_obd->obd_lvfs_ctxt.dt);
th = dt_trans_create(env, d);
if (IS_ERR(th))
RETURN(PTR_ERR(th));
if (loghandle->lgh_name) {
llog_dir = llog_osd_dir_get(env, ctxt);
if (IS_ERR(llog_dir))
GOTO(out_trans, rc = PTR_ERR(llog_dir));
name = loghandle->lgh_name;
rc = dt_declare_delete(env, llog_dir,
(struct dt_key *)name, th);
if (rc)
GOTO(out_trans, rc);
}
dt_declare_ref_del(env, o, th);
rc = dt_declare_destroy(env, o, th);
if (rc)
GOTO(out_trans, rc);
rc = dt_trans_start_local(env, d, th);
if (rc)
GOTO(out_trans, rc);
dt_write_lock(env, o, 0);
if (dt_object_exists(o)) {
if (name) {
dt_read_lock(env, llog_dir, 0);
rc = dt_delete(env, llog_dir,
(struct dt_key *) name,
th, BYPASS_CAPA);
dt_read_unlock(env, llog_dir);
if (rc) {
CERROR("%s: can't remove llog %s: rc = %d\n",
o->do_lu.lo_dev->ld_obd->obd_name,
name, rc);
GOTO(out_unlock, rc);
}
}
dt_ref_del(env, o, th);
rc = dt_destroy(env, o, th);
if (rc)
GOTO(out_unlock, rc);
}
out_unlock:
dt_write_unlock(env, o);
out_trans:
dt_trans_stop(env, d, th);
if (llog_dir != NULL)
lu_object_put(env, &llog_dir->do_lu);
RETURN(rc);
}
static int llog_osd_setup(const struct lu_env *env, struct obd_device *obd,
struct obd_llog_group *olg, int ctxt_idx,
struct obd_device *disk_obd)
{
struct local_oid_storage *los;
struct llog_thread_info *lgi = llog_info(env);
struct llog_ctxt *ctxt;
int rc = 0;
ENTRY;
LASSERT(obd);
LASSERT(olg->olg_ctxts[ctxt_idx]);
ctxt = llog_ctxt_get(olg->olg_ctxts[ctxt_idx]);
LASSERT(ctxt);
lgi->lgi_fid.f_seq = FID_SEQ_LLOG;
lgi->lgi_fid.f_oid = 1;
lgi->lgi_fid.f_ver = 0;
rc = local_oid_storage_init(env, disk_obd->obd_lvfs_ctxt.dt,
&lgi->lgi_fid, &los);
if (rc < 0)
return rc;
lgi->lgi_fid.f_seq = FID_SEQ_LLOG_NAME;
lgi->lgi_fid.f_oid = 1;
lgi->lgi_fid.f_ver = 0;
rc = local_oid_storage_init(env, disk_obd->obd_lvfs_ctxt.dt,
&lgi->lgi_fid, &los);
llog_ctxt_put(ctxt);
return rc;
}
static int llog_osd_cleanup(const struct lu_env *env, struct llog_ctxt *ctxt)
{
struct dt_device *dt;
struct ls_device *ls;
struct local_oid_storage *los, *nlos;
LASSERT(ctxt->loc_exp->exp_obd);
dt = ctxt->loc_exp->exp_obd->obd_lvfs_ctxt.dt;
ls = ls_device_get(dt);
if (IS_ERR(ls))
RETURN(PTR_ERR(ls));
mutex_lock(&ls->ls_los_mutex);
los = dt_los_find(ls, FID_SEQ_LLOG);
nlos = dt_los_find(ls, FID_SEQ_LLOG_NAME);
mutex_unlock(&ls->ls_los_mutex);
if (los != NULL) {
dt_los_put(los);
local_oid_storage_fini(env, los);
}
if (nlos != NULL) {
dt_los_put(nlos);
local_oid_storage_fini(env, nlos);
}
ls_device_put(env, ls);
return 0;
}
int llog_osd_get_cat_list(const struct lu_env *env, struct dt_device *d,
int idx, int count, struct llog_catid *idarray)
{
struct llog_thread_info *lgi = llog_info(env);
struct dt_object *o = NULL;
struct thandle *th;
int rc, size;
ENTRY;
LASSERT(d);
size = sizeof(*idarray) * count;
lgi->lgi_off = idx * sizeof(*idarray);
lu_local_obj_fid(&lgi->lgi_fid, LLOG_CATALOGS_OID);
o = dt_locate(env, d, &lgi->lgi_fid);
if (IS_ERR(o))
RETURN(PTR_ERR(o));
if (!dt_object_exists(o)) {
th = dt_trans_create(env, d);
if (IS_ERR(th))
GOTO(out, rc = PTR_ERR(th));
lgi->lgi_attr.la_valid = LA_MODE;
lgi->lgi_attr.la_mode = S_IFREG | S_IRUGO | S_IWUSR;
lgi->lgi_dof.dof_type = dt_mode_to_dft(S_IFREG);
rc = dt_declare_create(env, o, &lgi->lgi_attr, NULL,
&lgi->lgi_dof, th);
if (rc)
GOTO(out_trans, rc);
rc = dt_trans_start_local(env, d, th);
if (rc)
GOTO(out_trans, rc);
dt_write_lock(env, o, 0);
if (!dt_object_exists(o))
rc = dt_create(env, o, &lgi->lgi_attr, NULL,
&lgi->lgi_dof, th);
dt_write_unlock(env, o);
out_trans:
dt_trans_stop(env, d, th);
if (rc)
GOTO(out, rc);
}
rc = dt_attr_get(env, o, &lgi->lgi_attr, BYPASS_CAPA);
if (rc)
GOTO(out, rc);
if (!S_ISREG(lgi->lgi_attr.la_mode)) {
CERROR("%s: CATALOGS is not a regular file!: mode = %o\n",
o->do_lu.lo_dev->ld_obd->obd_name,
lgi->lgi_attr.la_mode);
GOTO(out, rc = -ENOENT);
}
CDEBUG(D_CONFIG, "cat list: disk size=%d, read=%d\n",
(int)lgi->lgi_attr.la_size, size);
if (idarray == NULL) {
rc = lgi->lgi_attr.la_size / sizeof(*idarray);
GOTO(out, rc);
}
memset(idarray, 0, size);
if (lgi->lgi_attr.la_size < lgi->lgi_off + size)
GOTO(out, rc = 0);
if (lgi->lgi_attr.la_size < lgi->lgi_off + size)
size = lgi->lgi_attr.la_size - lgi->lgi_off;
lgi->lgi_buf.lb_buf = idarray;
lgi->lgi_buf.lb_len = size;
rc = dt_record_read(env, o, &lgi->lgi_buf, &lgi->lgi_off);
if (rc) {
CERROR("%s: error reading CATALOGS: rc = %d\n",
o->do_lu.lo_dev->ld_obd->obd_name, rc);
GOTO(out, rc);
}
EXIT;
out:
lu_object_put(env, &o->do_lu);
RETURN(rc);
}
int llog_osd_put_cat_list(const struct lu_env *env, struct dt_device *d,
int idx, int count, struct llog_catid *idarray)
{
struct llog_thread_info *lgi = llog_info(env);
struct dt_object *o = NULL;
struct thandle *th;
int rc, size;
if (!count)
RETURN(0);
LASSERT(d);
size = sizeof(*idarray) * count;
lgi->lgi_off = idx * sizeof(*idarray);
lu_local_obj_fid(&lgi->lgi_fid, LLOG_CATALOGS_OID);
o = dt_locate(env, d, &lgi->lgi_fid);
if (IS_ERR(o))
RETURN(PTR_ERR(o));
if (!dt_object_exists(o))
GOTO(out, rc = -ENOENT);
rc = dt_attr_get(env, o, &lgi->lgi_attr, BYPASS_CAPA);
if (rc)
GOTO(out, rc);
if (!S_ISREG(lgi->lgi_attr.la_mode)) {
CERROR("%s: CATALOGS is not a regular file!: mode = %o\n",
o->do_lu.lo_dev->ld_obd->obd_name,
lgi->lgi_attr.la_mode);
GOTO(out, rc = -ENOENT);
}
th = dt_trans_create(env, d);
if (IS_ERR(th))
GOTO(out, rc = PTR_ERR(th));
rc = dt_declare_record_write(env, o, size, lgi->lgi_off, th);
if (rc)
GOTO(out, rc);
rc = dt_trans_start_local(env, d, th);
if (rc)
GOTO(out_trans, rc);
lgi->lgi_buf.lb_buf = idarray;
lgi->lgi_buf.lb_len = size;
rc = dt_record_write(env, o, &lgi->lgi_buf, &lgi->lgi_off, th);
if (rc)
CDEBUG(D_INODE, "error writeing CATALOGS: rc = %d\n", rc);
out_trans:
dt_trans_stop(env, d, th);
out:
lu_object_put(env, &o->do_lu);
RETURN(rc);
}
