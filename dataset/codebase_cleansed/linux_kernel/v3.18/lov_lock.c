static struct lov_sublock_env *lov_sublock_env_get(const struct lu_env *env,
struct cl_lock *parent,
struct lov_lock_sub *lls)
{
struct lov_sublock_env *subenv;
struct lov_io *lio = lov_env_io(env);
struct cl_io *io = lio->lis_cl.cis_io;
struct lov_io_sub *sub;
subenv = &lov_env_session(env)->ls_subenv;
if (!io || !cl_object_same(io->ci_obj, parent->cll_descr.cld_obj)) {
subenv->lse_env = env;
subenv->lse_io = io;
subenv->lse_sub = NULL;
} else {
sub = lov_sub_get(env, lio, lls->sub_stripe);
if (!IS_ERR(sub)) {
subenv->lse_env = sub->sub_env;
subenv->lse_io = sub->sub_io;
subenv->lse_sub = sub;
} else {
subenv = (void *)sub;
}
}
return subenv;
}
static void lov_sublock_env_put(struct lov_sublock_env *subenv)
{
if (subenv && subenv->lse_sub)
lov_sub_put(subenv->lse_sub);
}
static void lov_sublock_adopt(const struct lu_env *env, struct lov_lock *lck,
struct cl_lock *sublock, int idx,
struct lov_lock_link *link)
{
struct lovsub_lock *lsl;
struct cl_lock *parent = lck->lls_cl.cls_lock;
int rc;
LASSERT(cl_lock_is_mutexed(parent));
LASSERT(cl_lock_is_mutexed(sublock));
lsl = cl2sub_lock(sublock);
LASSERT(lov_lock_link_find(env, lck, lsl) == NULL);
LASSERT(idx < lck->lls_nr);
lck->lls_sub[idx].sub_lock = lsl;
lck->lls_nr_filled++;
LASSERT(lck->lls_nr_filled <= lck->lls_nr);
list_add_tail(&link->lll_list, &lsl->lss_parents);
link->lll_idx = idx;
link->lll_super = lck;
cl_lock_get(parent);
lu_ref_add(&parent->cll_reference, "lov-child", sublock);
lck->lls_sub[idx].sub_flags |= LSF_HELD;
cl_lock_user_add(env, sublock);
rc = lov_sublock_modify(env, lck, lsl, &sublock->cll_descr, idx);
LASSERT(rc == 0);
}
static struct cl_lock *lov_sublock_alloc(const struct lu_env *env,
const struct cl_io *io,
struct lov_lock *lck,
int idx, struct lov_lock_link **out)
{
struct cl_lock *sublock;
struct cl_lock *parent;
struct lov_lock_link *link;
LASSERT(idx < lck->lls_nr);
OBD_SLAB_ALLOC_PTR_GFP(link, lov_lock_link_kmem, GFP_NOFS);
if (link != NULL) {
struct lov_sublock_env *subenv;
struct lov_lock_sub *lls;
struct cl_lock_descr *descr;
parent = lck->lls_cl.cls_lock;
lls = &lck->lls_sub[idx];
descr = &lls->sub_got;
subenv = lov_sublock_env_get(env, parent, lls);
if (!IS_ERR(subenv)) {
sublock = cl_lock_hold(subenv->lse_env, subenv->lse_io,
descr, "lov-parent", parent);
lov_sublock_env_put(subenv);
} else {
sublock = (void *)subenv;
}
if (!IS_ERR(sublock))
*out = link;
else
OBD_SLAB_FREE_PTR(link, lov_lock_link_kmem);
} else
sublock = ERR_PTR(-ENOMEM);
return sublock;
}
static void lov_sublock_unlock(const struct lu_env *env,
struct lovsub_lock *lsl,
struct cl_lock_closure *closure,
struct lov_sublock_env *subenv)
{
lov_sublock_env_put(subenv);
lsl->lss_active = NULL;
cl_lock_disclosure(env, closure);
}
static int lov_sublock_lock(const struct lu_env *env,
struct lov_lock *lck,
struct lov_lock_sub *lls,
struct cl_lock_closure *closure,
struct lov_sublock_env **lsep)
{
struct lovsub_lock *sublock;
struct cl_lock *child;
int result = 0;
LASSERT(list_empty(&closure->clc_list));
sublock = lls->sub_lock;
child = sublock->lss_cl.cls_lock;
result = cl_lock_closure_build(env, child, closure);
if (result == 0) {
struct cl_lock *parent = closure->clc_origin;
LASSERT(cl_lock_is_mutexed(child));
sublock->lss_active = parent;
if (unlikely((child->cll_state == CLS_FREEING) ||
(child->cll_flags & CLF_CANCELLED))) {
struct lov_lock_link *link;
LASSERT(!(lls->sub_flags & LSF_HELD));
link = lov_lock_link_find(env, lck, sublock);
LASSERT(link != NULL);
lov_lock_unlink(env, link, sublock);
lov_sublock_unlock(env, sublock, closure, NULL);
lck->lls_cancel_race = 1;
result = CLO_REPEAT;
} else if (lsep) {
struct lov_sublock_env *subenv;
subenv = lov_sublock_env_get(env, parent, lls);
if (IS_ERR(subenv)) {
lov_sublock_unlock(env, sublock,
closure, NULL);
result = PTR_ERR(subenv);
} else {
*lsep = subenv;
}
}
}
return result;
}
static int lov_subresult(int result, int rc)
{
int result_rank;
int rc_rank;
LASSERTF(result <= 0 || result == CLO_REPEAT || result == CLO_WAIT,
"result = %d", result);
LASSERTF(rc <= 0 || rc == CLO_REPEAT || rc == CLO_WAIT,
"rc = %d\n", rc);
CLASSERT(CLO_WAIT < CLO_REPEAT);
result_rank = result < 0 ? 1 + CLO_REPEAT : result;
rc_rank = rc < 0 ? 1 + CLO_REPEAT : rc;
if (result_rank < rc_rank)
result = rc;
return result;
}
static int lov_lock_sub_init(const struct lu_env *env,
struct lov_lock *lck, const struct cl_io *io)
{
int result = 0;
int i;
int nr;
u64 start;
u64 end;
u64 file_start;
u64 file_end;
struct lov_object *loo = cl2lov(lck->lls_cl.cls_obj);
struct lov_layout_raid0 *r0 = lov_r0(loo);
struct cl_lock *parent = lck->lls_cl.cls_lock;
lck->lls_orig = parent->cll_descr;
file_start = cl_offset(lov2cl(loo), parent->cll_descr.cld_start);
file_end = cl_offset(lov2cl(loo), parent->cll_descr.cld_end + 1) - 1;
for (i = 0, nr = 0; i < r0->lo_nr; i++) {
if (lov_stripe_intersects(loo->lo_lsm, i,
file_start, file_end, &start, &end))
nr++;
}
LASSERT(nr > 0);
OBD_ALLOC_LARGE(lck->lls_sub, nr * sizeof(lck->lls_sub[0]));
if (lck->lls_sub == NULL)
return -ENOMEM;
lck->lls_nr = nr;
for (i = 0, nr = 0; i < r0->lo_nr; ++i) {
if (lov_stripe_intersects(loo->lo_lsm, i,
file_start, file_end, &start, &end)) {
struct cl_lock_descr *descr;
descr = &lck->lls_sub[nr].sub_descr;
LASSERT(descr->cld_obj == NULL);
descr->cld_obj = lovsub2cl(r0->lo_sub[i]);
descr->cld_start = cl_index(descr->cld_obj, start);
descr->cld_end = cl_index(descr->cld_obj, end);
descr->cld_mode = parent->cll_descr.cld_mode;
descr->cld_gid = parent->cll_descr.cld_gid;
descr->cld_enq_flags = parent->cll_descr.cld_enq_flags;
lck->lls_sub[nr].sub_got = *descr;
lck->lls_sub[nr].sub_stripe = i;
nr++;
}
}
LASSERT(nr == lck->lls_nr);
return result;
}
static int lov_sublock_release(const struct lu_env *env, struct lov_lock *lck,
int i, int deluser, int rc)
{
struct cl_lock *parent = lck->lls_cl.cls_lock;
LASSERT(cl_lock_is_mutexed(parent));
if (lck->lls_sub[i].sub_flags & LSF_HELD) {
struct cl_lock *sublock;
int dying;
LASSERT(lck->lls_sub[i].sub_lock != NULL);
sublock = lck->lls_sub[i].sub_lock->lss_cl.cls_lock;
LASSERT(cl_lock_is_mutexed(sublock));
lck->lls_sub[i].sub_flags &= ~LSF_HELD;
if (deluser)
cl_lock_user_del(env, sublock);
dying = (sublock->cll_descr.cld_mode == CLM_PHANTOM ||
sublock->cll_descr.cld_mode == CLM_GROUP ||
(sublock->cll_flags & (CLF_CANCELPEND|CLF_DOOMED))) &&
sublock->cll_holds == 1;
if (dying)
cl_lock_mutex_put(env, parent);
cl_lock_unhold(env, sublock, "lov-parent", parent);
if (dying) {
cl_lock_mutex_get(env, parent);
rc = lov_subresult(rc, CLO_REPEAT);
}
}
return rc;
}
static void lov_sublock_hold(const struct lu_env *env, struct lov_lock *lck,
int i)
{
struct cl_lock *parent = lck->lls_cl.cls_lock;
LASSERT(cl_lock_is_mutexed(parent));
if (!(lck->lls_sub[i].sub_flags & LSF_HELD)) {
struct cl_lock *sublock;
LASSERT(lck->lls_sub[i].sub_lock != NULL);
sublock = lck->lls_sub[i].sub_lock->lss_cl.cls_lock;
LASSERT(cl_lock_is_mutexed(sublock));
LASSERT(sublock->cll_state != CLS_FREEING);
lck->lls_sub[i].sub_flags |= LSF_HELD;
cl_lock_get_trust(sublock);
cl_lock_hold_add(env, sublock, "lov-parent", parent);
cl_lock_user_add(env, sublock);
cl_lock_put(env, sublock);
}
}
static void lov_lock_fini(const struct lu_env *env,
struct cl_lock_slice *slice)
{
struct lov_lock *lck;
int i;
lck = cl2lov_lock(slice);
LASSERT(lck->lls_nr_filled == 0);
if (lck->lls_sub != NULL) {
for (i = 0; i < lck->lls_nr; ++i)
LASSERT(lck->lls_sub[i].sub_lock == NULL);
OBD_FREE_LARGE(lck->lls_sub,
lck->lls_nr * sizeof(lck->lls_sub[0]));
}
OBD_SLAB_FREE_PTR(lck, lov_lock_kmem);
}
static int lov_lock_enqueue_wait(const struct lu_env *env,
struct lov_lock *lck,
struct cl_lock *sublock)
{
struct cl_lock *lock = lck->lls_cl.cls_lock;
int result;
LASSERT(cl_lock_is_mutexed(lock));
cl_lock_mutex_put(env, lock);
result = cl_lock_enqueue_wait(env, sublock, 0);
cl_lock_mutex_get(env, lock);
return result ?: CLO_REPEAT;
}
static int lov_lock_enqueue_one(const struct lu_env *env, struct lov_lock *lck,
struct cl_lock *sublock,
struct cl_io *io, __u32 enqflags, int last)
{
int result;
result = cl_enqueue_try(env, sublock, io, enqflags);
if ((sublock->cll_state == CLS_ENQUEUED) && !(enqflags & CEF_AGL)) {
result = cl_wait_try(env, sublock);
if (result == CLO_REENQUEUED)
result = CLO_WAIT;
}
if ((result == CLO_WAIT) && (sublock->cll_state <= CLS_HELD) &&
(enqflags & CEF_ASYNC) && (!last || (enqflags & CEF_AGL)))
result = 0;
return result;
}
static int lov_sublock_fill(const struct lu_env *env, struct cl_lock *parent,
struct cl_io *io, struct lov_lock *lck, int idx)
{
struct lov_lock_link *link = NULL;
struct cl_lock *sublock;
int result;
LASSERT(parent->cll_depth == 1);
cl_lock_mutex_put(env, parent);
sublock = lov_sublock_alloc(env, io, lck, idx, &link);
if (!IS_ERR(sublock))
cl_lock_mutex_get(env, sublock);
cl_lock_mutex_get(env, parent);
if (!IS_ERR(sublock)) {
cl_lock_get_trust(sublock);
if (parent->cll_state == CLS_QUEUING &&
lck->lls_sub[idx].sub_lock == NULL) {
lov_sublock_adopt(env, lck, sublock, idx, link);
} else {
OBD_SLAB_FREE_PTR(link, lov_lock_link_kmem);
cl_lock_mutex_put(env, parent);
cl_lock_unhold(env, sublock, "lov-parent", parent);
cl_lock_mutex_get(env, parent);
}
cl_lock_mutex_put(env, sublock);
cl_lock_put(env, sublock);
result = CLO_REPEAT;
} else
result = PTR_ERR(sublock);
return result;
}
static int lov_lock_enqueue(const struct lu_env *env,
const struct cl_lock_slice *slice,
struct cl_io *io, __u32 enqflags)
{
struct cl_lock *lock = slice->cls_lock;
struct lov_lock *lck = cl2lov_lock(slice);
struct cl_lock_closure *closure = lov_closure_get(env, lock);
int i;
int result;
enum cl_lock_state minstate;
for (result = 0, minstate = CLS_FREEING, i = 0; i < lck->lls_nr; ++i) {
int rc;
struct lovsub_lock *sub;
struct lov_lock_sub *lls;
struct cl_lock *sublock;
struct lov_sublock_env *subenv;
if (lock->cll_state != CLS_QUEUING) {
LASSERT(i > 0 && result != 0);
break;
}
lls = &lck->lls_sub[i];
sub = lls->sub_lock;
if (sub == NULL) {
result = lov_sublock_fill(env, lock, io, lck, i);
break;
}
sublock = sub->lss_cl.cls_lock;
rc = lov_sublock_lock(env, lck, lls, closure, &subenv);
if (rc == 0) {
lov_sublock_hold(env, lck, i);
rc = lov_lock_enqueue_one(subenv->lse_env, lck, sublock,
subenv->lse_io, enqflags,
i == lck->lls_nr - 1);
minstate = min(minstate, sublock->cll_state);
if (rc == CLO_WAIT) {
switch (sublock->cll_state) {
case CLS_QUEUING:
cl_lock_mutex_get(env, sublock);
lov_sublock_unlock(env, sub, closure,
subenv);
rc = lov_lock_enqueue_wait(env, lck,
sublock);
break;
case CLS_CACHED:
cl_lock_get(sublock);
cl_lock_mutex_get(env, sublock);
lov_sublock_unlock(env, sub, closure,
subenv);
rc = lov_sublock_release(env, lck, i,
1, rc);
cl_lock_mutex_put(env, sublock);
cl_lock_put(env, sublock);
break;
default:
lov_sublock_unlock(env, sub, closure,
subenv);
break;
}
} else {
LASSERT(sublock->cll_conflict == NULL);
lov_sublock_unlock(env, sub, closure, subenv);
}
}
result = lov_subresult(result, rc);
if (result != 0)
break;
}
cl_lock_closure_fini(closure);
return result ?: minstate >= CLS_ENQUEUED ? 0 : CLO_WAIT;
}
static int lov_lock_unuse(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct lov_lock *lck = cl2lov_lock(slice);
struct cl_lock_closure *closure = lov_closure_get(env, slice->cls_lock);
int i;
int result;
for (result = 0, i = 0; i < lck->lls_nr; ++i) {
int rc;
struct lovsub_lock *sub;
struct cl_lock *sublock;
struct lov_lock_sub *lls;
struct lov_sublock_env *subenv;
LASSERT(slice->cls_lock->cll_state == CLS_INTRANSIT);
lls = &lck->lls_sub[i];
sub = lls->sub_lock;
if (sub == NULL)
continue;
sublock = sub->lss_cl.cls_lock;
rc = lov_sublock_lock(env, lck, lls, closure, &subenv);
if (rc == 0) {
if (lls->sub_flags & LSF_HELD) {
LASSERT(sublock->cll_state == CLS_HELD ||
sublock->cll_state == CLS_ENQUEUED);
rc = cl_unuse_try(subenv->lse_env, sublock);
rc = lov_sublock_release(env, lck, i, 0, rc);
}
lov_sublock_unlock(env, sub, closure, subenv);
}
result = lov_subresult(result, rc);
}
if (result == 0 && lck->lls_cancel_race) {
lck->lls_cancel_race = 0;
result = -ESTALE;
}
cl_lock_closure_fini(closure);
return result;
}
static void lov_lock_cancel(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct lov_lock *lck = cl2lov_lock(slice);
struct cl_lock_closure *closure = lov_closure_get(env, slice->cls_lock);
int i;
int result;
for (result = 0, i = 0; i < lck->lls_nr; ++i) {
int rc;
struct lovsub_lock *sub;
struct cl_lock *sublock;
struct lov_lock_sub *lls;
struct lov_sublock_env *subenv;
lls = &lck->lls_sub[i];
sub = lls->sub_lock;
if (sub == NULL)
continue;
sublock = sub->lss_cl.cls_lock;
rc = lov_sublock_lock(env, lck, lls, closure, &subenv);
if (rc == 0) {
if (!(lls->sub_flags & LSF_HELD)) {
lov_sublock_unlock(env, sub, closure, subenv);
continue;
}
switch (sublock->cll_state) {
case CLS_HELD:
rc = cl_unuse_try(subenv->lse_env, sublock);
lov_sublock_release(env, lck, i, 0, 0);
break;
default:
lov_sublock_release(env, lck, i, 1, 0);
break;
}
lov_sublock_unlock(env, sub, closure, subenv);
}
if (rc == CLO_REPEAT) {
--i;
continue;
}
result = lov_subresult(result, rc);
}
if (result)
CL_LOCK_DEBUG(D_ERROR, env, slice->cls_lock,
"lov_lock_cancel fails with %d.\n", result);
cl_lock_closure_fini(closure);
}
static int lov_lock_wait(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct lov_lock *lck = cl2lov_lock(slice);
struct cl_lock_closure *closure = lov_closure_get(env, slice->cls_lock);
enum cl_lock_state minstate;
int reenqueued;
int result;
int i;
again:
for (result = 0, minstate = CLS_FREEING, i = 0, reenqueued = 0;
i < lck->lls_nr; ++i) {
int rc;
struct lovsub_lock *sub;
struct cl_lock *sublock;
struct lov_lock_sub *lls;
struct lov_sublock_env *subenv;
lls = &lck->lls_sub[i];
sub = lls->sub_lock;
LASSERT(sub != NULL);
sublock = sub->lss_cl.cls_lock;
rc = lov_sublock_lock(env, lck, lls, closure, &subenv);
if (rc == 0) {
LASSERT(sublock->cll_state >= CLS_ENQUEUED);
if (sublock->cll_state < CLS_HELD)
rc = cl_wait_try(env, sublock);
minstate = min(minstate, sublock->cll_state);
lov_sublock_unlock(env, sub, closure, subenv);
}
if (rc == CLO_REENQUEUED) {
reenqueued++;
rc = 0;
}
result = lov_subresult(result, rc);
if (result != 0)
break;
}
if (result == 0 && reenqueued != 0)
goto again;
cl_lock_closure_fini(closure);
return result ?: minstate >= CLS_HELD ? 0 : CLO_WAIT;
}
static int lov_lock_use(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct lov_lock *lck = cl2lov_lock(slice);
struct cl_lock_closure *closure = lov_closure_get(env, slice->cls_lock);
int result;
int i;
LASSERT(slice->cls_lock->cll_state == CLS_INTRANSIT);
for (result = 0, i = 0; i < lck->lls_nr; ++i) {
int rc;
struct lovsub_lock *sub;
struct cl_lock *sublock;
struct lov_lock_sub *lls;
struct lov_sublock_env *subenv;
LASSERT(slice->cls_lock->cll_state == CLS_INTRANSIT);
lls = &lck->lls_sub[i];
sub = lls->sub_lock;
if (sub == NULL) {
result = -ESTALE;
break;
}
sublock = sub->lss_cl.cls_lock;
rc = lov_sublock_lock(env, lck, lls, closure, &subenv);
if (rc == 0) {
LASSERT(sublock->cll_state != CLS_FREEING);
lov_sublock_hold(env, lck, i);
if (sublock->cll_state == CLS_CACHED) {
rc = cl_use_try(subenv->lse_env, sublock, 0);
if (rc != 0)
rc = lov_sublock_release(env, lck,
i, 1, rc);
} else if (sublock->cll_state == CLS_NEW) {
result = -ESTALE;
lov_sublock_release(env, lck, i, 1, result);
}
lov_sublock_unlock(env, sub, closure, subenv);
}
result = lov_subresult(result, rc);
if (result != 0)
break;
}
if (lck->lls_cancel_race) {
lck->lls_cancel_race = 0;
LASSERT(result != 0);
result = -ESTALE;
}
cl_lock_closure_fini(closure);
return result;
}
static int lov_lock_stripe_is_matching(const struct lu_env *env,
struct lov_object *lov, int stripe,
const struct cl_lock_descr *child,
const struct cl_lock_descr *descr)
{
struct lov_stripe_md *lsm = lov->lo_lsm;
u64 start;
u64 end;
int result;
if (lov_r0(lov)->lo_nr == 1)
return cl_lock_ext_match(child, descr);
start = cl_offset(&lov->lo_cl, descr->cld_start);
end = cl_offset(&lov->lo_cl, descr->cld_end + 1) - 1;
result = end - start <= lsm->lsm_stripe_size &&
stripe == lov_stripe_number(lsm, start) &&
stripe == lov_stripe_number(lsm, end);
if (result) {
struct cl_lock_descr *subd = &lov_env_info(env)->lti_ldescr;
u64 sub_start;
u64 sub_end;
subd->cld_obj = NULL;
subd->cld_mode = descr->cld_mode;
subd->cld_gid = descr->cld_gid;
result = lov_stripe_intersects(lsm, stripe, start, end,
&sub_start, &sub_end);
LASSERT(result);
subd->cld_start = cl_index(child->cld_obj, sub_start);
subd->cld_end = cl_index(child->cld_obj, sub_end);
result = cl_lock_ext_match(child, subd);
}
return result;
}
static int lov_lock_fits_into(const struct lu_env *env,
const struct cl_lock_slice *slice,
const struct cl_lock_descr *need,
const struct cl_io *io)
{
struct lov_lock *lov = cl2lov_lock(slice);
struct lov_object *obj = cl2lov(slice->cls_obj);
int result;
LASSERT(cl_object_same(need->cld_obj, slice->cls_obj));
LASSERT(lov->lls_nr > 0);
if (need->cld_enq_flags != lov->lls_orig.cld_enq_flags)
return 0;
if (need->cld_mode == CLM_GROUP)
result = cl_lock_ext_match(&lov->lls_orig, need);
else if (lov->lls_nr == 1) {
struct cl_lock_descr *got = &lov->lls_sub[0].sub_got;
result = lov_lock_stripe_is_matching(env,
cl2lov(slice->cls_obj),
lov->lls_sub[0].sub_stripe,
got, need);
} else if (io->ci_type != CIT_SETATTR && io->ci_type != CIT_MISC &&
!cl_io_is_append(io) && need->cld_mode != CLM_PHANTOM)
result = 0;
else
result = cl_lock_ext_match(&lov->lls_orig, need);
CDEBUG(D_DLMTRACE, DDESCR"/"DDESCR" %d %d/%d: %d\n",
PDESCR(&lov->lls_orig), PDESCR(&lov->lls_sub[0].sub_got),
lov->lls_sub[0].sub_stripe, lov->lls_nr, lov_r0(obj)->lo_nr,
result);
return result;
}
void lov_lock_unlink(const struct lu_env *env,
struct lov_lock_link *link, struct lovsub_lock *sub)
{
struct lov_lock *lck = link->lll_super;
struct cl_lock *parent = lck->lls_cl.cls_lock;
LASSERT(cl_lock_is_mutexed(parent));
LASSERT(cl_lock_is_mutexed(sub->lss_cl.cls_lock));
list_del_init(&link->lll_list);
LASSERT(lck->lls_sub[link->lll_idx].sub_lock == sub);
lck->lls_sub[link->lll_idx].sub_lock = NULL;
LASSERT(lck->lls_nr_filled > 0);
lck->lls_nr_filled--;
lu_ref_del(&parent->cll_reference, "lov-child", sub->lss_cl.cls_lock);
cl_lock_put(env, parent);
OBD_SLAB_FREE_PTR(link, lov_lock_link_kmem);
}
struct lov_lock_link *lov_lock_link_find(const struct lu_env *env,
struct lov_lock *lck,
struct lovsub_lock *sub)
{
struct lov_lock_link *scan;
LASSERT(cl_lock_is_mutexed(sub->lss_cl.cls_lock));
list_for_each_entry(scan, &sub->lss_parents, lll_list) {
if (scan->lll_super == lck)
return scan;
}
return NULL;
}
static void lov_lock_delete(const struct lu_env *env,
const struct cl_lock_slice *slice)
{
struct lov_lock *lck = cl2lov_lock(slice);
struct cl_lock_closure *closure = lov_closure_get(env, slice->cls_lock);
struct lov_lock_link *link;
int rc;
int i;
LASSERT(slice->cls_lock->cll_state == CLS_FREEING);
for (i = 0; i < lck->lls_nr; ++i) {
struct lov_lock_sub *lls = &lck->lls_sub[i];
struct lovsub_lock *lsl = lls->sub_lock;
if (lsl == NULL)
continue;
rc = lov_sublock_lock(env, lck, lls, closure, NULL);
if (rc == CLO_REPEAT) {
--i;
continue;
}
LASSERT(rc == 0);
LASSERT(lsl->lss_cl.cls_lock->cll_state < CLS_FREEING);
if (lls->sub_flags & LSF_HELD)
lov_sublock_release(env, lck, i, 1, 0);
link = lov_lock_link_find(env, lck, lsl);
LASSERT(link != NULL);
lov_lock_unlink(env, link, lsl);
LASSERT(lck->lls_sub[i].sub_lock == NULL);
lov_sublock_unlock(env, lsl, closure, NULL);
}
cl_lock_closure_fini(closure);
}
static int lov_lock_print(const struct lu_env *env, void *cookie,
lu_printer_t p, const struct cl_lock_slice *slice)
{
struct lov_lock *lck = cl2lov_lock(slice);
int i;
(*p)(env, cookie, "%d\n", lck->lls_nr);
for (i = 0; i < lck->lls_nr; ++i) {
struct lov_lock_sub *sub;
sub = &lck->lls_sub[i];
(*p)(env, cookie, " %d %x: ", i, sub->sub_flags);
if (sub->sub_lock != NULL)
cl_lock_print(env, cookie, p,
sub->sub_lock->lss_cl.cls_lock);
else
(*p)(env, cookie, "---\n");
}
return 0;
}
int lov_lock_init_raid0(const struct lu_env *env, struct cl_object *obj,
struct cl_lock *lock, const struct cl_io *io)
{
struct lov_lock *lck;
int result;
OBD_SLAB_ALLOC_PTR_GFP(lck, lov_lock_kmem, GFP_NOFS);
if (lck != NULL) {
cl_lock_slice_add(lock, &lck->lls_cl, obj, &lov_lock_ops);
result = lov_lock_sub_init(env, lck, io);
} else
result = -ENOMEM;
return result;
}
static void lov_empty_lock_fini(const struct lu_env *env,
struct cl_lock_slice *slice)
{
struct lov_lock *lck = cl2lov_lock(slice);
OBD_SLAB_FREE_PTR(lck, lov_lock_kmem);
}
static int lov_empty_lock_print(const struct lu_env *env, void *cookie,
lu_printer_t p, const struct cl_lock_slice *slice)
{
(*p)(env, cookie, "empty\n");
return 0;
}
int lov_lock_init_empty(const struct lu_env *env, struct cl_object *obj,
struct cl_lock *lock, const struct cl_io *io)
{
struct lov_lock *lck;
int result = -ENOMEM;
OBD_SLAB_ALLOC_PTR_GFP(lck, lov_lock_kmem, GFP_NOFS);
if (lck != NULL) {
cl_lock_slice_add(lock, &lck->lls_cl, obj, &lov_empty_lock_ops);
lck->lls_orig = lock->cll_descr;
result = 0;
}
return result;
}
static struct cl_lock_closure *lov_closure_get(const struct lu_env *env,
struct cl_lock *parent)
{
struct cl_lock_closure *closure;
closure = &lov_env_info(env)->lti_closure;
LASSERT(list_empty(&closure->clc_list));
cl_lock_closure_init(env, closure, parent, 1);
return closure;
}
