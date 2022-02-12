static inline void keyring_upcall_lock(struct gss_sec_keyring *gsec_kr)
{
#ifdef HAVE_KEYRING_UPCALL_SERIALIZED
mutex_lock(&gsec_kr->gsk_uc_lock);
#endif
}
static inline void keyring_upcall_unlock(struct gss_sec_keyring *gsec_kr)
{
#ifdef HAVE_KEYRING_UPCALL_SERIALIZED
mutex_unlock(&gsec_kr->gsk_uc_lock);
#endif
}
static inline void key_revoke_locked(struct key *key)
{
set_bit(KEY_FLAG_REVOKED, &key->flags);
}
static void ctx_upcall_timeout_kr(unsigned long data)
{
struct ptlrpc_cli_ctx *ctx = (struct ptlrpc_cli_ctx *) data;
struct key *key = ctx2gctx_keyring(ctx)->gck_key;
CWARN("ctx %p, key %p\n", ctx, key);
LASSERT(key);
cli_ctx_expire(ctx);
key_revoke_locked(key);
}
static
void ctx_start_timer_kr(struct ptlrpc_cli_ctx *ctx, long timeout)
{
struct gss_cli_ctx_keyring *gctx_kr = ctx2gctx_keyring(ctx);
struct timer_list *timer = gctx_kr->gck_timer;
LASSERT(timer);
CDEBUG(D_SEC, "ctx %p: start timer %lds\n", ctx, timeout);
timeout = timeout * HZ + cfs_time_current();
init_timer(timer);
timer->expires = timeout;
timer->data = (unsigned long ) ctx;
timer->function = ctx_upcall_timeout_kr;
add_timer(timer);
}
static
void ctx_clear_timer_kr(struct ptlrpc_cli_ctx *ctx)
{
struct gss_cli_ctx_keyring *gctx_kr = ctx2gctx_keyring(ctx);
struct timer_list *timer = gctx_kr->gck_timer;
if (timer == NULL)
return;
CDEBUG(D_SEC, "ctx %p, key %p\n", ctx, gctx_kr->gck_key);
gctx_kr->gck_timer = NULL;
del_singleshot_timer_sync(timer);
OBD_FREE_PTR(timer);
}
static
struct ptlrpc_cli_ctx *ctx_create_kr(struct ptlrpc_sec *sec,
struct vfs_cred *vcred)
{
struct ptlrpc_cli_ctx *ctx;
struct gss_cli_ctx_keyring *gctx_kr;
OBD_ALLOC_PTR(gctx_kr);
if (gctx_kr == NULL)
return NULL;
OBD_ALLOC_PTR(gctx_kr->gck_timer);
if (gctx_kr->gck_timer == NULL) {
OBD_FREE_PTR(gctx_kr);
return NULL;
}
init_timer(gctx_kr->gck_timer);
ctx = &gctx_kr->gck_base.gc_base;
if (gss_cli_ctx_init_common(sec, ctx, &gss_keyring_ctxops, vcred)) {
OBD_FREE_PTR(gctx_kr->gck_timer);
OBD_FREE_PTR(gctx_kr);
return NULL;
}
ctx->cc_expire = cfs_time_current_sec() + KEYRING_UPCALL_TIMEOUT;
clear_bit(PTLRPC_CTX_NEW_BIT, &ctx->cc_flags);
atomic_inc(&ctx->cc_refcount);
return ctx;
}
static void ctx_destroy_kr(struct ptlrpc_cli_ctx *ctx)
{
struct ptlrpc_sec *sec = ctx->cc_sec;
struct gss_cli_ctx_keyring *gctx_kr = ctx2gctx_keyring(ctx);
CDEBUG(D_SEC, "destroying ctx %p\n", ctx);
LASSERT(sec);
LASSERT(atomic_read(&sec->ps_refcount) > 0);
LASSERT(atomic_read(&sec->ps_nctx) > 0);
LASSERT(test_bit(PTLRPC_CTX_CACHED_BIT, &ctx->cc_flags) == 0);
LASSERT(gctx_kr->gck_key == NULL);
ctx_clear_timer_kr(ctx);
LASSERT(gctx_kr->gck_timer == NULL);
if (gss_cli_ctx_fini_common(sec, ctx))
return;
OBD_FREE_PTR(gctx_kr);
atomic_dec(&sec->ps_nctx);
sptlrpc_sec_put(sec);
}
static void ctx_release_kr(struct ptlrpc_cli_ctx *ctx, int sync)
{
if (sync) {
ctx_destroy_kr(ctx);
} else {
atomic_inc(&ctx->cc_refcount);
sptlrpc_gc_add_ctx(ctx);
}
}
static void ctx_put_kr(struct ptlrpc_cli_ctx *ctx, int sync)
{
LASSERT(atomic_read(&ctx->cc_refcount) > 0);
if (atomic_dec_and_test(&ctx->cc_refcount))
ctx_release_kr(ctx, sync);
}
static inline void spin_lock_if(spinlock_t *lock, int condition)
{
if (condition)
spin_lock(lock);
}
static inline void spin_unlock_if(spinlock_t *lock, int condition)
{
if (condition)
spin_unlock(lock);
}
static void ctx_enlist_kr(struct ptlrpc_cli_ctx *ctx, int is_root, int locked)
{
struct ptlrpc_sec *sec = ctx->cc_sec;
struct gss_sec_keyring *gsec_kr = sec2gsec_keyring(sec);
LASSERT(!test_bit(PTLRPC_CTX_CACHED_BIT, &ctx->cc_flags));
LASSERT(atomic_read(&ctx->cc_refcount) > 0);
spin_lock_if(&sec->ps_lock, !locked);
atomic_inc(&ctx->cc_refcount);
set_bit(PTLRPC_CTX_CACHED_BIT, &ctx->cc_flags);
hlist_add_head(&ctx->cc_cache, &gsec_kr->gsk_clist);
if (is_root)
gsec_kr->gsk_root_ctx = ctx;
spin_unlock_if(&sec->ps_lock, !locked);
}
static int ctx_unlist_kr(struct ptlrpc_cli_ctx *ctx, int locked)
{
struct ptlrpc_sec *sec = ctx->cc_sec;
struct gss_sec_keyring *gsec_kr = sec2gsec_keyring(sec);
if (test_and_clear_bit(PTLRPC_CTX_CACHED_BIT, &ctx->cc_flags) == 0)
return 0;
spin_lock_if(&sec->ps_lock, !locked);
if (gsec_kr->gsk_root_ctx == ctx)
gsec_kr->gsk_root_ctx = NULL;
hlist_del_init(&ctx->cc_cache);
atomic_dec(&ctx->cc_refcount);
spin_unlock_if(&sec->ps_lock, !locked);
return 1;
}
static void bind_key_ctx(struct key *key, struct ptlrpc_cli_ctx *ctx)
{
LASSERT(atomic_read(&ctx->cc_refcount) > 0);
LASSERT(atomic_read(&key->usage) > 0);
LASSERT(ctx2gctx_keyring(ctx)->gck_key == NULL);
LASSERT(key->payload.data == NULL);
key_get(key);
atomic_inc(&ctx->cc_refcount);
ctx2gctx_keyring(ctx)->gck_key = key;
key->payload.data = ctx;
}
static void unbind_key_ctx(struct key *key, struct ptlrpc_cli_ctx *ctx)
{
LASSERT(key->payload.data == ctx);
LASSERT(test_bit(PTLRPC_CTX_CACHED_BIT, &ctx->cc_flags) == 0);
key_revoke_locked(key);
key->payload.data = NULL;
ctx2gctx_keyring(ctx)->gck_key = NULL;
ctx_clear_timer_kr(ctx);
ctx_put_kr(ctx, 1);
key_put(key);
}
static void unbind_ctx_kr(struct ptlrpc_cli_ctx *ctx)
{
struct key *key = ctx2gctx_keyring(ctx)->gck_key;
if (key) {
LASSERT(key->payload.data == ctx);
key_get(key);
down_write(&key->sem);
unbind_key_ctx(key, ctx);
up_write(&key->sem);
key_put(key);
}
}
static void unbind_key_locked(struct key *key)
{
struct ptlrpc_cli_ctx *ctx = key->payload.data;
if (ctx)
unbind_key_ctx(key, ctx);
}
static void kill_ctx_kr(struct ptlrpc_cli_ctx *ctx)
{
if (ctx_unlist_kr(ctx, 0))
unbind_ctx_kr(ctx);
}
static void kill_key_locked(struct key *key)
{
struct ptlrpc_cli_ctx *ctx = key->payload.data;
if (ctx && ctx_unlist_kr(ctx, 0))
unbind_key_locked(key);
}
static void dispose_ctx_list_kr(struct hlist_head *freelist)
{
struct hlist_node *next;
struct ptlrpc_cli_ctx *ctx;
struct gss_cli_ctx *gctx;
hlist_for_each_entry_safe(ctx, next, freelist, cc_cache) {
hlist_del_init(&ctx->cc_cache);
gctx = ctx2gctx(ctx);
if (!rawobj_empty(&gctx->gc_svc_handle) &&
sec_is_reverse(gctx->gc_base.cc_sec)) {
gss_svc_upcall_update_sequence(&gctx->gc_svc_handle,
(__u32) atomic_read(&gctx->gc_seq));
}
sptlrpc_cli_ctx_wakeup(ctx);
unbind_ctx_kr(ctx);
ctx_put_kr(ctx, 0);
}
}
static
struct ptlrpc_cli_ctx * sec_lookup_root_ctx_kr(struct ptlrpc_sec *sec)
{
struct gss_sec_keyring *gsec_kr = sec2gsec_keyring(sec);
struct ptlrpc_cli_ctx *ctx = NULL;
spin_lock(&sec->ps_lock);
ctx = gsec_kr->gsk_root_ctx;
if (ctx == NULL && unlikely(sec_is_reverse(sec))) {
struct ptlrpc_cli_ctx *tmp;
hlist_for_each_entry(tmp, &gsec_kr->gsk_clist, cc_cache) {
if (ctx == NULL || ctx->cc_expire == 0 ||
ctx->cc_expire > tmp->cc_expire) {
ctx = tmp;
gsec_kr->gsk_root_ctx = ctx;
}
}
}
if (ctx) {
LASSERT(atomic_read(&ctx->cc_refcount) > 0);
LASSERT(!hlist_empty(&gsec_kr->gsk_clist));
atomic_inc(&ctx->cc_refcount);
}
spin_unlock(&sec->ps_lock);
return ctx;
}
static
void rvs_sec_install_root_ctx_kr(struct ptlrpc_sec *sec,
struct ptlrpc_cli_ctx *new_ctx,
struct key *key)
{
struct gss_sec_keyring *gsec_kr = sec2gsec_keyring(sec);
struct ptlrpc_cli_ctx *ctx;
cfs_time_t now;
ENTRY;
LASSERT(sec_is_reverse(sec));
spin_lock(&sec->ps_lock);
now = cfs_time_current_sec();
hlist_for_each_entry(ctx, &gsec_kr->gsk_clist, cc_cache) {
if (ctx->cc_expire > now + RVS_CTX_EXPIRE_NICE) {
ctx->cc_early_expire = 1;
ctx->cc_expire = now + RVS_CTX_EXPIRE_NICE;
}
}
ctx_enlist_kr(new_ctx, gsec_kr->gsk_root_ctx ? 0 : 1, 1);
if (key)
bind_key_ctx(key, new_ctx);
spin_unlock(&sec->ps_lock);
}
static void construct_key_desc(void *buf, int bufsize,
struct ptlrpc_sec *sec, uid_t uid)
{
snprintf(buf, bufsize, "%d@%x", uid, sec->ps_id);
((char *)buf)[bufsize - 1] = '\0';
}
static
struct ptlrpc_sec * gss_sec_create_kr(struct obd_import *imp,
struct ptlrpc_svc_ctx *svcctx,
struct sptlrpc_flavor *sf)
{
struct gss_sec_keyring *gsec_kr;
ENTRY;
OBD_ALLOC(gsec_kr, sizeof(*gsec_kr));
if (gsec_kr == NULL)
RETURN(NULL);
INIT_HLIST_HEAD(&gsec_kr->gsk_clist);
gsec_kr->gsk_root_ctx = NULL;
mutex_init(&gsec_kr->gsk_root_uc_lock);
#ifdef HAVE_KEYRING_UPCALL_SERIALIZED
mutex_init(&gsec_kr->gsk_uc_lock);
#endif
if (gss_sec_create_common(&gsec_kr->gsk_base, &gss_policy_keyring,
imp, svcctx, sf))
goto err_free;
if (svcctx != NULL &&
sec_install_rctx_kr(&gsec_kr->gsk_base.gs_base, svcctx)) {
gss_sec_destroy_common(&gsec_kr->gsk_base);
goto err_free;
}
RETURN(&gsec_kr->gsk_base.gs_base);
err_free:
OBD_FREE(gsec_kr, sizeof(*gsec_kr));
RETURN(NULL);
}
static
void gss_sec_destroy_kr(struct ptlrpc_sec *sec)
{
struct gss_sec *gsec = sec2gsec(sec);
struct gss_sec_keyring *gsec_kr = sec2gsec_keyring(sec);
CDEBUG(D_SEC, "destroy %s@%p\n", sec->ps_policy->sp_name, sec);
LASSERT(hlist_empty(&gsec_kr->gsk_clist));
LASSERT(gsec_kr->gsk_root_ctx == NULL);
gss_sec_destroy_common(gsec);
OBD_FREE(gsec_kr, sizeof(*gsec_kr));
}
static inline int user_is_root(struct ptlrpc_sec *sec, struct vfs_cred *vcred)
{
if (sec_is_rootonly(sec) || (vcred->vc_uid == 0))
return 1;
else
return 0;
}
static void request_key_unlink(struct key *key)
{
struct task_struct *tsk = current;
struct key *ring;
switch (key_cred(tsk)->jit_keyring) {
case KEY_REQKEY_DEFL_DEFAULT:
case KEY_REQKEY_DEFL_THREAD_KEYRING:
ring = key_get(key_cred(tsk)->thread_keyring);
if (ring)
break;
case KEY_REQKEY_DEFL_PROCESS_KEYRING:
ring = key_get(key_tgcred(tsk)->process_keyring);
if (ring)
break;
case KEY_REQKEY_DEFL_SESSION_KEYRING:
rcu_read_lock();
ring = key_get(rcu_dereference(key_tgcred(tsk)
->session_keyring));
rcu_read_unlock();
if (ring)
break;
case KEY_REQKEY_DEFL_USER_SESSION_KEYRING:
ring = key_get(key_cred(tsk)->user->session_keyring);
break;
case KEY_REQKEY_DEFL_USER_KEYRING:
ring = key_get(key_cred(tsk)->user->uid_keyring);
break;
case KEY_REQKEY_DEFL_GROUP_KEYRING:
default:
LBUG();
}
LASSERT(ring);
key_unlink(ring, key);
key_put(ring);
}
static
struct ptlrpc_cli_ctx * gss_sec_lookup_ctx_kr(struct ptlrpc_sec *sec,
struct vfs_cred *vcred,
int create, int remove_dead)
{
struct obd_import *imp = sec->ps_import;
struct gss_sec_keyring *gsec_kr = sec2gsec_keyring(sec);
struct ptlrpc_cli_ctx *ctx = NULL;
unsigned int is_root = 0, create_new = 0;
struct key *key;
char desc[24];
char *coinfo;
int coinfo_size;
char *co_flags = "";
ENTRY;
LASSERT(imp != NULL);
is_root = user_is_root(sec, vcred);
if (is_root) {
ctx = sec_lookup_root_ctx_kr(sec);
if (ctx || sec_is_reverse(sec))
RETURN(ctx);
}
LASSERT(create != 0);
if (is_root) {
mutex_lock(&gsec_kr->gsk_root_uc_lock);
ctx = sec_lookup_root_ctx_kr(sec);
if (ctx)
goto out;
sec2gsec(sec)->gs_rvs_hdl = gss_get_next_ctx_index();
switch (sec->ps_part) {
case LUSTRE_SP_MDT:
co_flags = "m";
break;
case LUSTRE_SP_OST:
co_flags = "o";
break;
case LUSTRE_SP_MGC:
co_flags = "rmo";
break;
case LUSTRE_SP_CLI:
co_flags = "r";
break;
case LUSTRE_SP_MGS:
default:
LBUG();
}
}
construct_key_desc(desc, sizeof(desc), sec, vcred->vc_uid);
coinfo_size = sizeof(struct obd_uuid) + MAX_OBD_NAME + 64;
OBD_ALLOC(coinfo, coinfo_size);
if (coinfo == NULL)
goto out;
snprintf(coinfo, coinfo_size, "%d:%s:%u:%u:%s:%d:"LPX64":%s",
sec->ps_id, sec2gsec(sec)->gs_mech->gm_name,
vcred->vc_uid, vcred->vc_gid,
co_flags, import_to_gss_svc(imp),
imp->imp_connection->c_peer.nid, imp->imp_obd->obd_name);
CDEBUG(D_SEC, "requesting key for %s\n", desc);
keyring_upcall_lock(gsec_kr);
key = request_key(&gss_key_type, desc, coinfo);
keyring_upcall_unlock(gsec_kr);
OBD_FREE(coinfo, coinfo_size);
if (IS_ERR(key)) {
CERROR("failed request key: %ld\n", PTR_ERR(key));
goto out;
}
CDEBUG(D_SEC, "obtained key %08x for %s\n", key->serial, desc);
down_write(&key->sem);
if (likely(key->payload.data != NULL)) {
ctx = key->payload.data;
LASSERT(atomic_read(&ctx->cc_refcount) >= 1);
LASSERT(ctx2gctx_keyring(ctx)->gck_key == key);
LASSERT(atomic_read(&key->usage) >= 2);
atomic_inc(&ctx->cc_refcount);
} else {
ctx = ctx_create_kr(sec, vcred);
if (ctx != NULL) {
ctx_enlist_kr(ctx, is_root, 0);
bind_key_ctx(key, ctx);
ctx_start_timer_kr(ctx, KEYRING_UPCALL_TIMEOUT);
CDEBUG(D_SEC, "installed key %p <-> ctx %p (sec %p)\n",
key, ctx, sec);
} else {
key_revoke_locked(key);
}
create_new = 1;
}
up_write(&key->sem);
if (is_root && create_new)
request_key_unlink(key);
key_put(key);
out:
if (is_root)
mutex_unlock(&gsec_kr->gsk_root_uc_lock);
RETURN(ctx);
}
static
void gss_sec_release_ctx_kr(struct ptlrpc_sec *sec,
struct ptlrpc_cli_ctx *ctx,
int sync)
{
LASSERT(atomic_read(&sec->ps_refcount) > 0);
LASSERT(atomic_read(&ctx->cc_refcount) == 0);
ctx_release_kr(ctx, sync);
}
static
void flush_user_ctx_cache_kr(struct ptlrpc_sec *sec,
uid_t uid,
int grace, int force)
{
struct key *key;
char desc[24];
if (sec_is_reverse(sec) || sec_is_rootonly(sec))
return;
construct_key_desc(desc, sizeof(desc), sec, uid);
for (;;) {
key = request_key(&gss_key_type, desc, NULL);
if (IS_ERR(key)) {
CDEBUG(D_SEC, "No more key found for current user\n");
break;
}
down_write(&key->sem);
kill_key_locked(key);
key_revoke_locked(key);
up_write(&key->sem);
key_put(key);
}
}
static
void flush_spec_ctx_cache_kr(struct ptlrpc_sec *sec,
uid_t uid,
int grace, int force)
{
struct gss_sec_keyring *gsec_kr;
struct hlist_head freelist = HLIST_HEAD_INIT;
struct hlist_node *next;
struct ptlrpc_cli_ctx *ctx;
ENTRY;
gsec_kr = sec2gsec_keyring(sec);
spin_lock(&sec->ps_lock);
hlist_for_each_entry_safe(ctx, next,
&gsec_kr->gsk_clist, cc_cache) {
LASSERT(atomic_read(&ctx->cc_refcount) > 0);
if (uid != -1 && uid != ctx->cc_vcred.vc_uid)
continue;
if (atomic_read(&ctx->cc_refcount) > 2) {
if (!force)
continue;
CWARN("flush busy ctx %p(%u->%s, extra ref %d)\n",
ctx, ctx->cc_vcred.vc_uid,
sec2target_str(ctx->cc_sec),
atomic_read(&ctx->cc_refcount) - 2);
}
set_bit(PTLRPC_CTX_DEAD_BIT, &ctx->cc_flags);
if (!grace)
clear_bit(PTLRPC_CTX_UPTODATE_BIT, &ctx->cc_flags);
atomic_inc(&ctx->cc_refcount);
if (ctx_unlist_kr(ctx, 1)) {
hlist_add_head(&ctx->cc_cache, &freelist);
} else {
LASSERT(atomic_read(&ctx->cc_refcount) >= 2);
atomic_dec(&ctx->cc_refcount);
}
}
spin_unlock(&sec->ps_lock);
dispose_ctx_list_kr(&freelist);
EXIT;
}
static
int gss_sec_flush_ctx_cache_kr(struct ptlrpc_sec *sec,
uid_t uid, int grace, int force)
{
ENTRY;
CDEBUG(D_SEC, "sec %p(%d, nctx %d), uid %d, grace %d, force %d\n",
sec, atomic_read(&sec->ps_refcount),
atomic_read(&sec->ps_nctx),
uid, grace, force);
if (uid != -1 && uid != 0)
flush_user_ctx_cache_kr(sec, uid, grace, force);
else
flush_spec_ctx_cache_kr(sec, uid, grace, force);
RETURN(0);
}
static
void gss_sec_gc_ctx_kr(struct ptlrpc_sec *sec)
{
struct gss_sec_keyring *gsec_kr = sec2gsec_keyring(sec);
struct hlist_head freelist = HLIST_HEAD_INIT;
struct hlist_node *next;
struct ptlrpc_cli_ctx *ctx;
ENTRY;
CWARN("running gc\n");
spin_lock(&sec->ps_lock);
hlist_for_each_entry_safe(ctx, next,
&gsec_kr->gsk_clist, cc_cache) {
LASSERT(atomic_read(&ctx->cc_refcount) > 0);
atomic_inc(&ctx->cc_refcount);
if (cli_ctx_check_death(ctx) && ctx_unlist_kr(ctx, 1)) {
hlist_add_head(&ctx->cc_cache, &freelist);
CWARN("unhashed ctx %p\n", ctx);
} else {
LASSERT(atomic_read(&ctx->cc_refcount) >= 2);
atomic_dec(&ctx->cc_refcount);
}
}
spin_unlock(&sec->ps_lock);
dispose_ctx_list_kr(&freelist);
EXIT;
return;
}
static
int gss_sec_display_kr(struct ptlrpc_sec *sec, struct seq_file *seq)
{
struct gss_sec_keyring *gsec_kr = sec2gsec_keyring(sec);
struct hlist_node *next;
struct ptlrpc_cli_ctx *ctx;
struct gss_cli_ctx *gctx;
time_t now = cfs_time_current_sec();
ENTRY;
spin_lock(&sec->ps_lock);
hlist_for_each_entry_safe(ctx, next,
&gsec_kr->gsk_clist, cc_cache) {
struct key *key;
char flags_str[40];
char mech[40];
gctx = ctx2gctx(ctx);
key = ctx2gctx_keyring(ctx)->gck_key;
gss_cli_ctx_flags2str(ctx->cc_flags,
flags_str, sizeof(flags_str));
if (gctx->gc_mechctx)
lgss_display(gctx->gc_mechctx, mech, sizeof(mech));
else
snprintf(mech, sizeof(mech), "N/A");
mech[sizeof(mech) - 1] = '\0';
seq_printf(seq, "%p: uid %u, ref %d, expire %ld(%+ld), fl %s, "
"seq %d, win %u, key %08x(ref %d), "
"hdl "LPX64":"LPX64", mech: %s\n",
ctx, ctx->cc_vcred.vc_uid,
atomic_read(&ctx->cc_refcount),
ctx->cc_expire,
ctx->cc_expire ? ctx->cc_expire - now : 0,
flags_str,
atomic_read(&gctx->gc_seq),
gctx->gc_win,
key ? key->serial : 0,
key ? atomic_read(&key->usage) : 0,
gss_handle_to_u64(&gctx->gc_handle),
gss_handle_to_u64(&gctx->gc_svc_handle),
mech);
}
spin_unlock(&sec->ps_lock);
RETURN(0);
}
static
int gss_cli_ctx_refresh_kr(struct ptlrpc_cli_ctx *ctx)
{
return 0;
}
static
int gss_cli_ctx_validate_kr(struct ptlrpc_cli_ctx *ctx)
{
LASSERT(atomic_read(&ctx->cc_refcount) > 0);
LASSERT(ctx->cc_sec);
if (cli_ctx_check_death(ctx)) {
kill_ctx_kr(ctx);
return 1;
}
if (cli_ctx_is_ready(ctx))
return 0;
return 1;
}
static
void gss_cli_ctx_die_kr(struct ptlrpc_cli_ctx *ctx, int grace)
{
LASSERT(atomic_read(&ctx->cc_refcount) > 0);
LASSERT(ctx->cc_sec);
cli_ctx_expire(ctx);
kill_ctx_kr(ctx);
}
static
int sec_install_rctx_kr(struct ptlrpc_sec *sec,
struct ptlrpc_svc_ctx *svc_ctx)
{
struct ptlrpc_cli_ctx *cli_ctx;
struct vfs_cred vcred = { 0, 0 };
int rc;
LASSERT(sec);
LASSERT(svc_ctx);
cli_ctx = ctx_create_kr(sec, &vcred);
if (cli_ctx == NULL)
return -ENOMEM;
rc = gss_copy_rvc_cli_ctx(cli_ctx, svc_ctx);
if (rc) {
CERROR("failed copy reverse cli ctx: %d\n", rc);
ctx_put_kr(cli_ctx, 1);
return rc;
}
rvs_sec_install_root_ctx_kr(sec, cli_ctx, NULL);
ctx_put_kr(cli_ctx, 1);
return 0;
}
static
int gss_svc_accept_kr(struct ptlrpc_request *req)
{
return gss_svc_accept(&gss_policy_keyring, req);
}
static
int gss_svc_install_rctx_kr(struct obd_import *imp,
struct ptlrpc_svc_ctx *svc_ctx)
{
struct ptlrpc_sec *sec;
int rc;
sec = sptlrpc_import_sec_ref(imp);
LASSERT(sec);
rc = sec_install_rctx_kr(sec, svc_ctx);
sptlrpc_sec_put(sec);
return rc;
}
static
int gss_kt_instantiate(struct key *key, const void *data, size_t datalen)
{
int rc;
ENTRY;
if (data != NULL || datalen != 0) {
CERROR("invalid: data %p, len %lu\n", data, (long)datalen);
RETURN(-EINVAL);
}
if (key->payload.data != 0) {
CERROR("key already have payload\n");
RETURN(-EINVAL);
}
LASSERT(key_tgcred(current)->session_keyring);
lockdep_off();
rc = key_link(key_tgcred(current)->session_keyring, key);
lockdep_on();
if (unlikely(rc)) {
CERROR("failed to link key %08x to keyring %08x: %d\n",
key->serial,
key_tgcred(current)->session_keyring->serial, rc);
RETURN(rc);
}
CDEBUG(D_SEC, "key %p instantiated, ctx %p\n", key, key->payload.data);
RETURN(0);
}
static
int gss_kt_update(struct key *key, const void *data, size_t datalen)
{
struct ptlrpc_cli_ctx *ctx = key->payload.data;
struct gss_cli_ctx *gctx;
rawobj_t tmpobj = RAWOBJ_EMPTY;
__u32 datalen32 = (__u32) datalen;
int rc;
ENTRY;
if (data == NULL || datalen == 0) {
CWARN("invalid: data %p, len %lu\n", data, (long)datalen);
RETURN(-EINVAL);
}
if (ctx == NULL) {
CDEBUG(D_SEC, "update too soon: key %p(%x) flags %lx\n",
key, key->serial, key->flags);
rc = key_validate(key);
if (rc == 0)
RETURN(-EAGAIN);
else
RETURN(rc);
}
LASSERT(atomic_read(&ctx->cc_refcount) > 0);
LASSERT(ctx->cc_sec);
ctx_clear_timer_kr(ctx);
if (cli_ctx_is_refreshed(ctx)) {
CWARN("ctx already done refresh\n");
RETURN(0);
}
sptlrpc_cli_ctx_get(ctx);
gctx = ctx2gctx(ctx);
rc = buffer_extract_bytes(&data, &datalen32, &gctx->gc_win,
sizeof(gctx->gc_win));
if (rc) {
CERROR("failed extract seq_win\n");
goto out;
}
if (gctx->gc_win == 0) {
__u32 nego_rpc_err, nego_gss_err;
rc = buffer_extract_bytes(&data, &datalen32, &nego_rpc_err,
sizeof(nego_rpc_err));
if (rc) {
CERROR("failed to extrace rpc rc\n");
goto out;
}
rc = buffer_extract_bytes(&data, &datalen32, &nego_gss_err,
sizeof(nego_gss_err));
if (rc) {
CERROR("failed to extrace gss rc\n");
goto out;
}
CERROR("negotiation: rpc err %d, gss err %x\n",
nego_rpc_err, nego_gss_err);
rc = nego_rpc_err ? nego_rpc_err : -EACCES;
} else {
rc = rawobj_extract_local_alloc(&gctx->gc_handle,
(__u32 **) &data, &datalen32);
if (rc) {
CERROR("failed extract handle\n");
goto out;
}
rc = rawobj_extract_local(&tmpobj, (__u32 **) &data,&datalen32);
if (rc) {
CERROR("failed extract mech\n");
goto out;
}
rc = lgss_import_sec_context(&tmpobj,
sec2gsec(ctx->cc_sec)->gs_mech,
&gctx->gc_mechctx);
if (rc != GSS_S_COMPLETE)
CERROR("failed import context\n");
else
rc = 0;
}
out:
if (rc == 0) {
gss_cli_ctx_uptodate(gctx);
} else {
kill_key_locked(key);
cli_ctx_expire(ctx);
if (rc != -ERESTART)
set_bit(PTLRPC_CTX_ERROR_BIT, &ctx->cc_flags);
}
sptlrpc_cli_ctx_put(ctx, 1);
RETURN(0);
}
static
int gss_kt_match(const struct key *key, const void *desc)
{
return (strcmp(key->description, (const char *) desc) == 0);
}
static
void gss_kt_destroy(struct key *key)
{
ENTRY;
LASSERT(key->payload.data == NULL);
CDEBUG(D_SEC, "destroy key %p\n", key);
EXIT;
}
static
void gss_kt_describe(const struct key *key, struct seq_file *s)
{
if (key->description == NULL)
seq_puts(s, "[null]");
else
seq_puts(s, key->description);
}
int __init gss_init_keyring(void)
{
int rc;
rc = register_key_type(&gss_key_type);
if (rc) {
CERROR("failed to register keyring type: %d\n", rc);
return rc;
}
rc = sptlrpc_register_policy(&gss_policy_keyring);
if (rc) {
unregister_key_type(&gss_key_type);
return rc;
}
return 0;
}
void __exit gss_exit_keyring(void)
{
unregister_key_type(&gss_key_type);
sptlrpc_unregister_policy(&gss_policy_keyring);
}
