static void gdlm_ast(void *arg)
{
struct gfs2_glock *gl = arg;
unsigned ret = gl->gl_state;
BUG_ON(gl->gl_lksb.sb_flags & DLM_SBF_DEMOTED);
if (gl->gl_lksb.sb_flags & DLM_SBF_VALNOTVALID)
memset(gl->gl_lvb, 0, GDLM_LVB_SIZE);
switch (gl->gl_lksb.sb_status) {
case -DLM_EUNLOCK:
gfs2_glock_free(gl);
return;
case -DLM_ECANCEL:
ret |= LM_OUT_CANCELED;
goto out;
case -EAGAIN:
case -EDEADLK:
goto out;
case -ETIMEDOUT:
ret |= LM_OUT_ERROR;
goto out;
case 0:
break;
default:
BUG();
}
ret = gl->gl_req;
if (gl->gl_lksb.sb_flags & DLM_SBF_ALTMODE) {
if (gl->gl_req == LM_ST_SHARED)
ret = LM_ST_DEFERRED;
else if (gl->gl_req == LM_ST_DEFERRED)
ret = LM_ST_SHARED;
else
BUG();
}
set_bit(GLF_INITIAL, &gl->gl_flags);
gfs2_glock_complete(gl, ret);
return;
out:
if (!test_bit(GLF_INITIAL, &gl->gl_flags))
gl->gl_lksb.sb_lkid = 0;
gfs2_glock_complete(gl, ret);
}
static void gdlm_bast(void *arg, int mode)
{
struct gfs2_glock *gl = arg;
switch (mode) {
case DLM_LOCK_EX:
gfs2_glock_cb(gl, LM_ST_UNLOCKED);
break;
case DLM_LOCK_CW:
gfs2_glock_cb(gl, LM_ST_DEFERRED);
break;
case DLM_LOCK_PR:
gfs2_glock_cb(gl, LM_ST_SHARED);
break;
default:
printk(KERN_ERR "unknown bast mode %d", mode);
BUG();
}
}
static int make_mode(const unsigned int lmstate)
{
switch (lmstate) {
case LM_ST_UNLOCKED:
return DLM_LOCK_NL;
case LM_ST_EXCLUSIVE:
return DLM_LOCK_EX;
case LM_ST_DEFERRED:
return DLM_LOCK_CW;
case LM_ST_SHARED:
return DLM_LOCK_PR;
}
printk(KERN_ERR "unknown LM state %d", lmstate);
BUG();
return -1;
}
static u32 make_flags(const u32 lkid, const unsigned int gfs_flags,
const int req)
{
u32 lkf = 0;
if (gfs_flags & LM_FLAG_TRY)
lkf |= DLM_LKF_NOQUEUE;
if (gfs_flags & LM_FLAG_TRY_1CB) {
lkf |= DLM_LKF_NOQUEUE;
lkf |= DLM_LKF_NOQUEUEBAST;
}
if (gfs_flags & LM_FLAG_PRIORITY) {
lkf |= DLM_LKF_NOORDER;
lkf |= DLM_LKF_HEADQUE;
}
if (gfs_flags & LM_FLAG_ANY) {
if (req == DLM_LOCK_PR)
lkf |= DLM_LKF_ALTCW;
else if (req == DLM_LOCK_CW)
lkf |= DLM_LKF_ALTPR;
else
BUG();
}
if (lkid != 0)
lkf |= DLM_LKF_CONVERT;
lkf |= DLM_LKF_VALBLK;
return lkf;
}
static int gdlm_lock(struct gfs2_glock *gl, unsigned int req_state,
unsigned int flags)
{
struct lm_lockstruct *ls = &gl->gl_sbd->sd_lockstruct;
int req;
u32 lkf;
req = make_mode(req_state);
lkf = make_flags(gl->gl_lksb.sb_lkid, flags, req);
return dlm_lock(ls->ls_dlm, req, &gl->gl_lksb, lkf, gl->gl_strname,
GDLM_STRNAME_BYTES - 1, 0, gdlm_ast, gl, gdlm_bast);
}
static void gdlm_put_lock(struct gfs2_glock *gl)
{
struct gfs2_sbd *sdp = gl->gl_sbd;
struct lm_lockstruct *ls = &sdp->sd_lockstruct;
int error;
if (gl->gl_lksb.sb_lkid == 0) {
gfs2_glock_free(gl);
return;
}
error = dlm_unlock(ls->ls_dlm, gl->gl_lksb.sb_lkid, DLM_LKF_VALBLK,
NULL, gl);
if (error) {
printk(KERN_ERR "gdlm_unlock %x,%llx err=%d\n",
gl->gl_name.ln_type,
(unsigned long long)gl->gl_name.ln_number, error);
return;
}
}
static void gdlm_cancel(struct gfs2_glock *gl)
{
struct lm_lockstruct *ls = &gl->gl_sbd->sd_lockstruct;
dlm_unlock(ls->ls_dlm, gl->gl_lksb.sb_lkid, DLM_LKF_CANCEL, NULL, gl);
}
static int gdlm_mount(struct gfs2_sbd *sdp, const char *fsname)
{
struct lm_lockstruct *ls = &sdp->sd_lockstruct;
int error;
if (fsname == NULL) {
fs_info(sdp, "no fsname found\n");
return -EINVAL;
}
error = dlm_new_lockspace(fsname, strlen(fsname), &ls->ls_dlm,
DLM_LSFL_FS | DLM_LSFL_NEWEXCL |
(ls->ls_nodir ? DLM_LSFL_NODIR : 0),
GDLM_LVB_SIZE);
if (error)
printk(KERN_ERR "dlm_new_lockspace error %d", error);
return error;
}
static void gdlm_unmount(struct gfs2_sbd *sdp)
{
struct lm_lockstruct *ls = &sdp->sd_lockstruct;
if (ls->ls_dlm) {
dlm_release_lockspace(ls->ls_dlm, 2);
ls->ls_dlm = NULL;
}
}
