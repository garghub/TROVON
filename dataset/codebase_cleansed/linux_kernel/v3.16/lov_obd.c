static void lov_getref(struct obd_device *obd)
{
struct lov_obd *lov = &obd->u.lov;
mutex_lock(&lov->lov_lock);
atomic_inc(&lov->lov_refcount);
mutex_unlock(&lov->lov_lock);
return;
}
static void lov_putref(struct obd_device *obd)
{
struct lov_obd *lov = &obd->u.lov;
mutex_lock(&lov->lov_lock);
if (atomic_dec_and_test(&lov->lov_refcount) && lov->lov_death_row) {
LIST_HEAD(kill);
int i;
struct lov_tgt_desc *tgt, *n;
CDEBUG(D_CONFIG, "destroying %d lov targets\n",
lov->lov_death_row);
for (i = 0; i < lov->desc.ld_tgt_count; i++) {
tgt = lov->lov_tgts[i];
if (!tgt || !tgt->ltd_reap)
continue;
list_add(&tgt->ltd_kill, &kill);
lov_ost_pool_remove(&lov->lov_packed, i);
lov->lov_tgts[i] = NULL;
lov->lov_death_row--;
}
mutex_unlock(&lov->lov_lock);
list_for_each_entry_safe(tgt, n, &kill, ltd_kill) {
list_del(&tgt->ltd_kill);
__lov_del_obd(obd, tgt);
}
} else {
mutex_unlock(&lov->lov_lock);
}
}
int lov_connect_obd(struct obd_device *obd, __u32 index, int activate,
struct obd_connect_data *data)
{
struct lov_obd *lov = &obd->u.lov;
struct obd_uuid *tgt_uuid;
struct obd_device *tgt_obd;
static struct obd_uuid lov_osc_uuid = { "LOV_OSC_UUID" };
struct obd_import *imp;
struct proc_dir_entry *lov_proc_dir;
int rc;
if (!lov->lov_tgts[index])
return -EINVAL;
tgt_uuid = &lov->lov_tgts[index]->ltd_uuid;
tgt_obd = lov->lov_tgts[index]->ltd_obd;
if (!tgt_obd->obd_set_up) {
CERROR("Target %s not set up\n", obd_uuid2str(tgt_uuid));
return -EINVAL;
}
tgt_obd->u.cli.cl_sp_me = lov->lov_sp_me;
if (data && (data->ocd_connect_flags & OBD_CONNECT_INDEX))
data->ocd_index = index;
imp = tgt_obd->u.cli.cl_import;
if (activate) {
tgt_obd->obd_no_recov = 0;
ptlrpc_activate_import(imp);
}
rc = obd_register_observer(tgt_obd, obd);
if (rc) {
CERROR("Target %s register_observer error %d\n",
obd_uuid2str(tgt_uuid), rc);
return rc;
}
if (imp->imp_invalid) {
CDEBUG(D_CONFIG, "not connecting OSC %s; administratively "
"disabled\n", obd_uuid2str(tgt_uuid));
return 0;
}
rc = obd_connect(NULL, &lov->lov_tgts[index]->ltd_exp, tgt_obd,
&lov_osc_uuid, data, NULL);
if (rc || !lov->lov_tgts[index]->ltd_exp) {
CERROR("Target %s connect error %d\n",
obd_uuid2str(tgt_uuid), rc);
return -ENODEV;
}
lov->lov_tgts[index]->ltd_reap = 0;
CDEBUG(D_CONFIG, "Connected tgt idx %d %s (%s) %sactive\n", index,
obd_uuid2str(tgt_uuid), tgt_obd->obd_name, activate ? "":"in");
lov_proc_dir = obd->obd_proc_private;
if (lov_proc_dir) {
struct obd_device *osc_obd = lov->lov_tgts[index]->ltd_exp->exp_obd;
struct proc_dir_entry *osc_symlink;
LASSERT(osc_obd != NULL);
LASSERT(osc_obd->obd_magic == OBD_DEVICE_MAGIC);
LASSERT(osc_obd->obd_type->typ_name != NULL);
osc_symlink = lprocfs_add_symlink(osc_obd->obd_name,
lov_proc_dir,
"../../../%s/%s",
osc_obd->obd_type->typ_name,
osc_obd->obd_name);
if (osc_symlink == NULL) {
CERROR("could not register LOV target "
"/proc/fs/lustre/%s/%s/target_obds/%s.",
obd->obd_type->typ_name, obd->obd_name,
osc_obd->obd_name);
lprocfs_remove(&lov_proc_dir);
obd->obd_proc_private = NULL;
}
}
return 0;
}
static int lov_connect(const struct lu_env *env,
struct obd_export **exp, struct obd_device *obd,
struct obd_uuid *cluuid, struct obd_connect_data *data,
void *localdata)
{
struct lov_obd *lov = &obd->u.lov;
struct lov_tgt_desc *tgt;
struct lustre_handle conn;
int i, rc;
CDEBUG(D_CONFIG, "connect #%d\n", lov->lov_connects);
rc = class_connect(&conn, obd, cluuid);
if (rc)
return rc;
*exp = class_conn2export(&conn);
lov->lov_connects++;
LASSERT(lov->lov_connects == 1);
memset(&lov->lov_ocd, 0, sizeof(lov->lov_ocd));
if (data)
lov->lov_ocd = *data;
obd_getref(obd);
for (i = 0; i < lov->desc.ld_tgt_count; i++) {
tgt = lov->lov_tgts[i];
if (!tgt || obd_uuid_empty(&tgt->ltd_uuid))
continue;
rc = lov_connect_obd(obd, i, tgt->ltd_activate, &lov->lov_ocd);
if (rc) {
CERROR("%s: lov connect tgt %d failed: %d\n",
obd->obd_name, i, rc);
continue;
}
if (!lov->lov_tgts[i]->ltd_exp)
continue;
rc = lov_notify(obd, lov->lov_tgts[i]->ltd_exp->exp_obd,
OBD_NOTIFY_CONNECT, (void *)&i);
if (rc) {
CERROR("%s error sending notify %d\n",
obd->obd_name, rc);
}
}
obd_putref(obd);
return 0;
}
static int lov_disconnect_obd(struct obd_device *obd, struct lov_tgt_desc *tgt)
{
struct proc_dir_entry *lov_proc_dir;
struct lov_obd *lov = &obd->u.lov;
struct obd_device *osc_obd;
int rc;
osc_obd = class_exp2obd(tgt->ltd_exp);
CDEBUG(D_CONFIG, "%s: disconnecting target %s\n",
obd->obd_name, osc_obd ? osc_obd->obd_name : "NULL");
if (tgt->ltd_active) {
tgt->ltd_active = 0;
lov->desc.ld_active_tgt_count--;
tgt->ltd_exp->exp_obd->obd_inactive = 1;
}
if (osc_obd) {
lov_proc_dir = obd->obd_proc_private;
if (lov_proc_dir) {
lprocfs_remove_proc_entry(osc_obd->obd_name, lov_proc_dir);
}
osc_obd->obd_force = obd->obd_force;
osc_obd->obd_fail = obd->obd_fail;
osc_obd->obd_no_recov = obd->obd_no_recov;
}
obd_register_observer(osc_obd, NULL);
rc = obd_disconnect(tgt->ltd_exp);
if (rc) {
CERROR("Target %s disconnect error %d\n",
tgt->ltd_uuid.uuid, rc);
rc = 0;
}
tgt->ltd_exp = NULL;
return 0;
}
static int lov_disconnect(struct obd_export *exp)
{
struct obd_device *obd = class_exp2obd(exp);
struct lov_obd *lov = &obd->u.lov;
int i, rc;
if (!lov->lov_tgts)
goto out;
lov->lov_connects--;
if (lov->lov_connects != 0) {
CERROR("disconnect #%d\n", lov->lov_connects);
goto out;
}
obd_getref(obd);
for (i = 0; i < lov->desc.ld_tgt_count; i++) {
if (lov->lov_tgts[i] && lov->lov_tgts[i]->ltd_exp) {
lov_del_target(obd, i, NULL, lov->lov_tgts[i]->ltd_gen);
}
}
obd_putref(obd);
out:
rc = class_disconnect(exp);
return rc;
}
static int lov_set_osc_active(struct obd_device *obd, struct obd_uuid *uuid,
enum obd_notify_event ev)
{
struct lov_obd *lov = &obd->u.lov;
struct lov_tgt_desc *tgt;
int index, activate, active;
CDEBUG(D_INFO, "Searching in lov %p for uuid %s event(%d)\n",
lov, uuid->uuid, ev);
obd_getref(obd);
for (index = 0; index < lov->desc.ld_tgt_count; index++) {
tgt = lov->lov_tgts[index];
if (!tgt)
continue;
if (ev == OBD_NOTIFY_ACTIVATE && tgt->ltd_exp == NULL &&
obd_uuid_equals(uuid, &tgt->ltd_uuid)) {
struct obd_uuid lov_osc_uuid = {"LOV_OSC_UUID"};
obd_connect(NULL, &tgt->ltd_exp, tgt->ltd_obd,
&lov_osc_uuid, &lov->lov_ocd, NULL);
}
if (!tgt->ltd_exp)
continue;
CDEBUG(D_INFO, "lov idx %d is %s conn "LPX64"\n",
index, obd_uuid2str(&tgt->ltd_uuid),
tgt->ltd_exp->exp_handle.h_cookie);
if (obd_uuid_equals(uuid, &tgt->ltd_uuid))
break;
}
if (index == lov->desc.ld_tgt_count)
GOTO(out, index = -EINVAL);
if (ev == OBD_NOTIFY_DEACTIVATE || ev == OBD_NOTIFY_ACTIVATE) {
activate = (ev == OBD_NOTIFY_ACTIVATE) ? 1 : 0;
if (lov->lov_tgts[index]->ltd_activate == activate) {
CDEBUG(D_INFO, "OSC %s already %sactivate!\n",
uuid->uuid, activate ? "" : "de");
} else {
lov->lov_tgts[index]->ltd_activate = activate;
CDEBUG(D_CONFIG, "%sactivate OSC %s\n",
activate ? "" : "de", obd_uuid2str(uuid));
}
} else if (ev == OBD_NOTIFY_INACTIVE || ev == OBD_NOTIFY_ACTIVE) {
active = (ev == OBD_NOTIFY_ACTIVE) ? 1 : 0;
if (lov->lov_tgts[index]->ltd_active == active) {
CDEBUG(D_INFO, "OSC %s already %sactive!\n",
uuid->uuid, active ? "" : "in");
GOTO(out, index);
} else {
CDEBUG(D_CONFIG, "Marking OSC %s %sactive\n",
obd_uuid2str(uuid), active ? "" : "in");
}
lov->lov_tgts[index]->ltd_active = active;
if (active) {
lov->desc.ld_active_tgt_count++;
lov->lov_tgts[index]->ltd_exp->exp_obd->obd_inactive = 0;
} else {
lov->desc.ld_active_tgt_count--;
lov->lov_tgts[index]->ltd_exp->exp_obd->obd_inactive = 1;
}
} else {
CERROR("Unknown event(%d) for uuid %s", ev, uuid->uuid);
}
out:
obd_putref(obd);
return index;
}
static int lov_notify(struct obd_device *obd, struct obd_device *watched,
enum obd_notify_event ev, void *data)
{
int rc = 0;
struct lov_obd *lov = &obd->u.lov;
down_read(&lov->lov_notify_lock);
if (!lov->lov_connects) {
up_read(&lov->lov_notify_lock);
return rc;
}
if (ev == OBD_NOTIFY_ACTIVE || ev == OBD_NOTIFY_INACTIVE ||
ev == OBD_NOTIFY_ACTIVATE || ev == OBD_NOTIFY_DEACTIVATE) {
struct obd_uuid *uuid;
LASSERT(watched);
if (strcmp(watched->obd_type->typ_name, LUSTRE_OSC_NAME)) {
up_read(&lov->lov_notify_lock);
CERROR("unexpected notification of %s %s!\n",
watched->obd_type->typ_name,
watched->obd_name);
return -EINVAL;
}
uuid = &watched->u.cli.cl_target_uuid;
rc = lov_set_osc_active(obd, uuid, ev);
if (rc < 0) {
up_read(&lov->lov_notify_lock);
CERROR("event(%d) of %s failed: %d\n", ev,
obd_uuid2str(uuid), rc);
return rc;
}
data = &rc;
}
if (watched) {
rc = obd_notify_observer(obd, watched, ev, data);
} else {
struct lov_obd *lov = &obd->u.lov;
int i, is_sync;
data = &i;
is_sync = (ev == OBD_NOTIFY_SYNC) ||
(ev == OBD_NOTIFY_SYNC_NONBLOCK);
obd_getref(obd);
for (i = 0; i < lov->desc.ld_tgt_count; i++) {
if (!lov->lov_tgts[i])
continue;
if (is_sync && !lov->lov_tgts[i]->ltd_active)
continue;
rc = obd_notify_observer(obd, lov->lov_tgts[i]->ltd_obd,
ev, data);
if (rc) {
CERROR("%s: notify %s of %s failed %d\n",
obd->obd_name,
obd->obd_observer->obd_name,
lov->lov_tgts[i]->ltd_obd->obd_name,
rc);
}
}
obd_putref(obd);
}
up_read(&lov->lov_notify_lock);
return rc;
}
static int lov_add_target(struct obd_device *obd, struct obd_uuid *uuidp,
__u32 index, int gen, int active)
{
struct lov_obd *lov = &obd->u.lov;
struct lov_tgt_desc *tgt;
struct obd_device *tgt_obd;
int rc;
CDEBUG(D_CONFIG, "uuid:%s idx:%d gen:%d active:%d\n",
uuidp->uuid, index, gen, active);
if (gen <= 0) {
CERROR("request to add OBD %s with invalid generation: %d\n",
uuidp->uuid, gen);
return -EINVAL;
}
tgt_obd = class_find_client_obd(uuidp, LUSTRE_OSC_NAME,
&obd->obd_uuid);
if (tgt_obd == NULL)
return -EINVAL;
mutex_lock(&lov->lov_lock);
if ((index < lov->lov_tgt_size) && (lov->lov_tgts[index] != NULL)) {
tgt = lov->lov_tgts[index];
CERROR("UUID %s already assigned at LOV target index %d\n",
obd_uuid2str(&tgt->ltd_uuid), index);
mutex_unlock(&lov->lov_lock);
return -EEXIST;
}
if (index >= lov->lov_tgt_size) {
struct lov_tgt_desc **newtgts, **old = NULL;
__u32 newsize, oldsize = 0;
newsize = max_t(__u32, lov->lov_tgt_size, 2);
while (newsize < index + 1)
newsize = newsize << 1;
OBD_ALLOC(newtgts, sizeof(*newtgts) * newsize);
if (newtgts == NULL) {
mutex_unlock(&lov->lov_lock);
return -ENOMEM;
}
if (lov->lov_tgt_size) {
memcpy(newtgts, lov->lov_tgts, sizeof(*newtgts) *
lov->lov_tgt_size);
old = lov->lov_tgts;
oldsize = lov->lov_tgt_size;
}
lov->lov_tgts = newtgts;
lov->lov_tgt_size = newsize;
smp_rmb();
if (old)
OBD_FREE(old, sizeof(*old) * oldsize);
CDEBUG(D_CONFIG, "tgts: %p size: %d\n",
lov->lov_tgts, lov->lov_tgt_size);
}
OBD_ALLOC_PTR(tgt);
if (!tgt) {
mutex_unlock(&lov->lov_lock);
return -ENOMEM;
}
rc = lov_ost_pool_add(&lov->lov_packed, index, lov->lov_tgt_size);
if (rc) {
mutex_unlock(&lov->lov_lock);
OBD_FREE_PTR(tgt);
return rc;
}
tgt->ltd_uuid = *uuidp;
tgt->ltd_obd = tgt_obd;
tgt->ltd_gen = gen;
tgt->ltd_index = index;
tgt->ltd_activate = active;
lov->lov_tgts[index] = tgt;
if (index >= lov->desc.ld_tgt_count)
lov->desc.ld_tgt_count = index + 1;
mutex_unlock(&lov->lov_lock);
CDEBUG(D_CONFIG, "idx=%d ltd_gen=%d ld_tgt_count=%d\n",
index, tgt->ltd_gen, lov->desc.ld_tgt_count);
rc = obd_notify(obd, tgt_obd, OBD_NOTIFY_CREATE, &index);
if (lov->lov_connects == 0) {
return 0;
}
obd_getref(obd);
rc = lov_connect_obd(obd, index, active, &lov->lov_ocd);
if (rc)
GOTO(out, rc);
if (!tgt->ltd_exp)
GOTO(out, rc = 0);
if (lov->lov_cache != NULL) {
rc = obd_set_info_async(NULL, tgt->ltd_exp,
sizeof(KEY_CACHE_SET), KEY_CACHE_SET,
sizeof(struct cl_client_cache), lov->lov_cache,
NULL);
if (rc < 0)
GOTO(out, rc);
}
rc = lov_notify(obd, tgt->ltd_exp->exp_obd,
active ? OBD_NOTIFY_CONNECT : OBD_NOTIFY_INACTIVE,
(void *)&index);
out:
if (rc) {
CERROR("add failed (%d), deleting %s\n", rc,
obd_uuid2str(&tgt->ltd_uuid));
lov_del_target(obd, index, NULL, 0);
}
obd_putref(obd);
return rc;
}
int lov_del_target(struct obd_device *obd, __u32 index,
struct obd_uuid *uuidp, int gen)
{
struct lov_obd *lov = &obd->u.lov;
int count = lov->desc.ld_tgt_count;
int rc = 0;
if (index >= count) {
CERROR("LOV target index %d >= number of LOV OBDs %d.\n",
index, count);
return -EINVAL;
}
down_write(&lov->lov_notify_lock);
obd_getref(obd);
if (!lov->lov_tgts[index]) {
CERROR("LOV target at index %d is not setup.\n", index);
GOTO(out, rc = -EINVAL);
}
if (uuidp && !obd_uuid_equals(uuidp, &lov->lov_tgts[index]->ltd_uuid)) {
CERROR("LOV target UUID %s at index %d doesn't match %s.\n",
lov_uuid2str(lov, index), index,
obd_uuid2str(uuidp));
GOTO(out, rc = -EINVAL);
}
CDEBUG(D_CONFIG, "uuid: %s idx: %d gen: %d exp: %p active: %d\n",
lov_uuid2str(lov, index), index,
lov->lov_tgts[index]->ltd_gen, lov->lov_tgts[index]->ltd_exp,
lov->lov_tgts[index]->ltd_active);
lov->lov_tgts[index]->ltd_reap = 1;
lov->lov_death_row++;
out:
obd_putref(obd);
up_write(&lov->lov_notify_lock);
return rc;
}
static void __lov_del_obd(struct obd_device *obd, struct lov_tgt_desc *tgt)
{
struct obd_device *osc_obd;
LASSERT(tgt);
LASSERT(tgt->ltd_reap);
osc_obd = class_exp2obd(tgt->ltd_exp);
CDEBUG(D_CONFIG, "Removing tgt %s : %s\n",
tgt->ltd_uuid.uuid,
osc_obd ? osc_obd->obd_name : "<no obd>");
if (tgt->ltd_exp)
lov_disconnect_obd(obd, tgt);
OBD_FREE_PTR(tgt);
if (osc_obd)
class_manual_cleanup(osc_obd);
}
void lov_fix_desc_stripe_size(__u64 *val)
{
if (*val < LOV_MIN_STRIPE_SIZE) {
if (*val != 0)
LCONSOLE_INFO("Increasing default stripe size to "
"minimum %u\n",
LOV_DESC_STRIPE_SIZE_DEFAULT);
*val = LOV_DESC_STRIPE_SIZE_DEFAULT;
} else if (*val & (LOV_MIN_STRIPE_SIZE - 1)) {
*val &= ~(LOV_MIN_STRIPE_SIZE - 1);
LCONSOLE_WARN("Changing default stripe size to "LPU64" (a "
"multiple of %u)\n",
*val, LOV_MIN_STRIPE_SIZE);
}
}
void lov_fix_desc_stripe_count(__u32 *val)
{
if (*val == 0)
*val = 1;
}
void lov_fix_desc_pattern(__u32 *val)
{
if ((*val != 0) && (*val != LOV_PATTERN_RAID0)) {
LCONSOLE_WARN("Unknown stripe pattern: %#x\n", *val);
*val = 0;
}
}
void lov_fix_desc_qos_maxage(__u32 *val)
{
if (*val == 0)
*val = LOV_DESC_QOS_MAXAGE_DEFAULT;
}
void lov_fix_desc(struct lov_desc *desc)
{
lov_fix_desc_stripe_size(&desc->ld_default_stripe_size);
lov_fix_desc_stripe_count(&desc->ld_default_stripe_count);
lov_fix_desc_pattern(&desc->ld_pattern);
lov_fix_desc_qos_maxage(&desc->ld_qos_maxage);
}
int lov_setup(struct obd_device *obd, struct lustre_cfg *lcfg)
{
struct lprocfs_static_vars lvars = { NULL };
struct lov_desc *desc;
struct lov_obd *lov = &obd->u.lov;
int rc;
if (LUSTRE_CFG_BUFLEN(lcfg, 1) < 1) {
CERROR("LOV setup requires a descriptor\n");
return -EINVAL;
}
desc = (struct lov_desc *)lustre_cfg_buf(lcfg, 1);
if (sizeof(*desc) > LUSTRE_CFG_BUFLEN(lcfg, 1)) {
CERROR("descriptor size wrong: %d > %d\n",
(int)sizeof(*desc), LUSTRE_CFG_BUFLEN(lcfg, 1));
return -EINVAL;
}
if (desc->ld_magic != LOV_DESC_MAGIC) {
if (desc->ld_magic == __swab32(LOV_DESC_MAGIC)) {
CDEBUG(D_OTHER, "%s: Swabbing lov desc %p\n",
obd->obd_name, desc);
lustre_swab_lov_desc(desc);
} else {
CERROR("%s: Bad lov desc magic: %#x\n",
obd->obd_name, desc->ld_magic);
return -EINVAL;
}
}
lov_fix_desc(desc);
desc->ld_active_tgt_count = 0;
lov->desc = *desc;
lov->lov_tgt_size = 0;
mutex_init(&lov->lov_lock);
atomic_set(&lov->lov_refcount, 0);
lov->lov_sp_me = LUSTRE_SP_CLI;
init_rwsem(&lov->lov_notify_lock);
lov->lov_pools_hash_body = cfs_hash_create("POOLS", HASH_POOLS_CUR_BITS,
HASH_POOLS_MAX_BITS,
HASH_POOLS_BKT_BITS, 0,
CFS_HASH_MIN_THETA,
CFS_HASH_MAX_THETA,
&pool_hash_operations,
CFS_HASH_DEFAULT);
INIT_LIST_HEAD(&lov->lov_pool_list);
lov->lov_pool_count = 0;
rc = lov_ost_pool_init(&lov->lov_packed, 0);
if (rc)
GOTO(out, rc);
lprocfs_lov_init_vars(&lvars);
lprocfs_obd_setup(obd, lvars.obd_vars);
#ifdef LPROCFS
{
int rc1;
rc1 = lprocfs_seq_create(obd->obd_proc_entry, "target_obd",
0444, &lov_proc_target_fops, obd);
if (rc1)
CWARN("Error adding the target_obd file\n");
}
#endif
lov->lov_pool_proc_entry = lprocfs_register("pools",
obd->obd_proc_entry,
NULL, NULL);
return 0;
out:
return rc;
}
static int lov_precleanup(struct obd_device *obd, enum obd_cleanup_stage stage)
{
int rc = 0;
struct lov_obd *lov = &obd->u.lov;
switch (stage) {
case OBD_CLEANUP_EARLY: {
int i;
for (i = 0; i < lov->desc.ld_tgt_count; i++) {
if (!lov->lov_tgts[i] || !lov->lov_tgts[i]->ltd_active)
continue;
obd_precleanup(class_exp2obd(lov->lov_tgts[i]->ltd_exp),
OBD_CLEANUP_EARLY);
}
break;
}
default:
break;
}
return rc;
}
static int lov_cleanup(struct obd_device *obd)
{
struct lov_obd *lov = &obd->u.lov;
struct list_head *pos, *tmp;
struct pool_desc *pool;
list_for_each_safe(pos, tmp, &lov->lov_pool_list) {
pool = list_entry(pos, struct pool_desc, pool_list);
CDEBUG(D_INFO, "delete pool %p\n", pool);
lov_pool_del(obd, pool->pool_name);
}
cfs_hash_putref(lov->lov_pools_hash_body);
lov_ost_pool_free(&lov->lov_packed);
lprocfs_obd_cleanup(obd);
if (lov->lov_tgts) {
int i;
obd_getref(obd);
for (i = 0; i < lov->desc.ld_tgt_count; i++) {
if (!lov->lov_tgts[i])
continue;
if (lov->lov_tgts[i]->ltd_active ||
atomic_read(&lov->lov_refcount))
CERROR("lov tgt %d not cleaned!"
" deathrow=%d, lovrc=%d\n",
i, lov->lov_death_row,
atomic_read(&lov->lov_refcount));
lov_del_target(obd, i, 0, 0);
}
obd_putref(obd);
OBD_FREE(lov->lov_tgts, sizeof(*lov->lov_tgts) *
lov->lov_tgt_size);
lov->lov_tgt_size = 0;
}
return 0;
}
int lov_process_config_base(struct obd_device *obd, struct lustre_cfg *lcfg,
__u32 *indexp, int *genp)
{
struct obd_uuid obd_uuid;
int cmd;
int rc = 0;
switch (cmd = lcfg->lcfg_command) {
case LCFG_LOV_ADD_OBD:
case LCFG_LOV_ADD_INA:
case LCFG_LOV_DEL_OBD: {
__u32 index;
int gen;
if (LUSTRE_CFG_BUFLEN(lcfg, 1) > sizeof(obd_uuid.uuid))
GOTO(out, rc = -EINVAL);
obd_str2uuid(&obd_uuid, lustre_cfg_buf(lcfg, 1));
if (sscanf(lustre_cfg_buf(lcfg, 2), "%d", indexp) != 1)
GOTO(out, rc = -EINVAL);
if (sscanf(lustre_cfg_buf(lcfg, 3), "%d", genp) != 1)
GOTO(out, rc = -EINVAL);
index = *indexp;
gen = *genp;
if (cmd == LCFG_LOV_ADD_OBD)
rc = lov_add_target(obd, &obd_uuid, index, gen, 1);
else if (cmd == LCFG_LOV_ADD_INA)
rc = lov_add_target(obd, &obd_uuid, index, gen, 0);
else
rc = lov_del_target(obd, index, &obd_uuid, gen);
GOTO(out, rc);
}
case LCFG_PARAM: {
struct lprocfs_static_vars lvars = { 0 };
struct lov_desc *desc = &(obd->u.lov.desc);
if (!desc)
GOTO(out, rc = -EINVAL);
lprocfs_lov_init_vars(&lvars);
rc = class_process_proc_param(PARAM_LOV, lvars.obd_vars,
lcfg, obd);
if (rc > 0)
rc = 0;
GOTO(out, rc);
}
case LCFG_POOL_NEW:
case LCFG_POOL_ADD:
case LCFG_POOL_DEL:
case LCFG_POOL_REM:
GOTO(out, rc);
default: {
CERROR("Unknown command: %d\n", lcfg->lcfg_command);
GOTO(out, rc = -EINVAL);
}
}
out:
return rc;
}
static int lov_recreate(struct obd_export *exp, struct obdo *src_oa,
struct lov_stripe_md **ea, struct obd_trans_info *oti)
{
struct lov_stripe_md *obj_mdp, *lsm;
struct lov_obd *lov = &exp->exp_obd->u.lov;
unsigned ost_idx;
int rc, i;
LASSERT(src_oa->o_valid & OBD_MD_FLFLAGS &&
src_oa->o_flags & OBD_FL_RECREATE_OBJS);
OBD_ALLOC(obj_mdp, sizeof(*obj_mdp));
if (obj_mdp == NULL)
return -ENOMEM;
ost_idx = src_oa->o_nlink;
lsm = *ea;
if (lsm == NULL)
GOTO(out, rc = -EINVAL);
if (ost_idx >= lov->desc.ld_tgt_count ||
!lov->lov_tgts[ost_idx])
GOTO(out, rc = -EINVAL);
for (i = 0; i < lsm->lsm_stripe_count; i++) {
if (lsm->lsm_oinfo[i]->loi_ost_idx == ost_idx) {
if (ostid_id(&lsm->lsm_oinfo[i]->loi_oi) !=
ostid_id(&src_oa->o_oi))
GOTO(out, rc = -EINVAL);
break;
}
}
if (i == lsm->lsm_stripe_count)
GOTO(out, rc = -EINVAL);
rc = obd_create(NULL, lov->lov_tgts[ost_idx]->ltd_exp,
src_oa, &obj_mdp, oti);
out:
OBD_FREE(obj_mdp, sizeof(*obj_mdp));
return rc;
}
static int lov_create(const struct lu_env *env, struct obd_export *exp,
struct obdo *src_oa, struct lov_stripe_md **ea,
struct obd_trans_info *oti)
{
struct lov_obd *lov;
int rc = 0;
LASSERT(ea != NULL);
if (exp == NULL)
return -EINVAL;
if ((src_oa->o_valid & OBD_MD_FLFLAGS) &&
src_oa->o_flags == OBD_FL_DELORPHAN) {
LBUG();
}
lov = &exp->exp_obd->u.lov;
if (!lov->desc.ld_active_tgt_count)
return -EIO;
obd_getref(exp->exp_obd);
if ((src_oa->o_valid & OBD_MD_FLFLAGS) &&
(src_oa->o_flags & OBD_FL_RECREATE_OBJS)) {
rc = lov_recreate(exp, src_oa, ea, oti);
}
obd_putref(exp->exp_obd);
return rc;
}
static int lov_destroy(const struct lu_env *env, struct obd_export *exp,
struct obdo *oa, struct lov_stripe_md *lsm,
struct obd_trans_info *oti, struct obd_export *md_exp,
void *capa)
{
struct lov_request_set *set;
struct obd_info oinfo;
struct lov_request *req;
struct list_head *pos;
struct lov_obd *lov;
int rc = 0, err = 0;
ASSERT_LSM_MAGIC(lsm);
if (!exp || !exp->exp_obd)
return -ENODEV;
if (oa->o_valid & OBD_MD_FLCOOKIE) {
LASSERT(oti);
LASSERT(oti->oti_logcookies);
}
lov = &exp->exp_obd->u.lov;
obd_getref(exp->exp_obd);
rc = lov_prep_destroy_set(exp, &oinfo, oa, lsm, oti, &set);
if (rc)
GOTO(out, rc);
list_for_each(pos, &set->set_list) {
req = list_entry(pos, struct lov_request, rq_link);
if (oa->o_valid & OBD_MD_FLCOOKIE)
oti->oti_logcookies = set->set_cookies + req->rq_stripe;
err = obd_destroy(env, lov->lov_tgts[req->rq_idx]->ltd_exp,
req->rq_oi.oi_oa, NULL, oti, NULL, capa);
err = lov_update_common_set(set, req, err);
if (err) {
CERROR("%s: destroying objid "DOSTID" subobj "
DOSTID" on OST idx %d: rc = %d\n",
exp->exp_obd->obd_name, POSTID(&oa->o_oi),
POSTID(&req->rq_oi.oi_oa->o_oi),
req->rq_idx, err);
if (!rc)
rc = err;
}
}
if (rc == 0) {
LASSERT(lsm_op_find(lsm->lsm_magic) != NULL);
rc = lsm_op_find(lsm->lsm_magic)->lsm_destroy(lsm, oa, md_exp);
}
err = lov_fini_destroy_set(set);
out:
obd_putref(exp->exp_obd);
return rc ? rc : err;
}
static int lov_getattr(const struct lu_env *env, struct obd_export *exp,
struct obd_info *oinfo)
{
struct lov_request_set *set;
struct lov_request *req;
struct list_head *pos;
struct lov_obd *lov;
int err = 0, rc = 0;
LASSERT(oinfo);
ASSERT_LSM_MAGIC(oinfo->oi_md);
if (!exp || !exp->exp_obd)
return -ENODEV;
lov = &exp->exp_obd->u.lov;
rc = lov_prep_getattr_set(exp, oinfo, &set);
if (rc)
return rc;
list_for_each(pos, &set->set_list) {
req = list_entry(pos, struct lov_request, rq_link);
CDEBUG(D_INFO, "objid "DOSTID"[%d] has subobj "DOSTID" at idx"
" %u\n", POSTID(&oinfo->oi_oa->o_oi), req->rq_stripe,
POSTID(&req->rq_oi.oi_oa->o_oi), req->rq_idx);
rc = obd_getattr(env, lov->lov_tgts[req->rq_idx]->ltd_exp,
&req->rq_oi);
err = lov_update_common_set(set, req, rc);
if (err) {
CERROR("%s: getattr objid "DOSTID" subobj "
DOSTID" on OST idx %d: rc = %d\n",
exp->exp_obd->obd_name,
POSTID(&oinfo->oi_oa->o_oi),
POSTID(&req->rq_oi.oi_oa->o_oi),
req->rq_idx, err);
break;
}
}
rc = lov_fini_getattr_set(set);
if (err)
rc = err;
return rc;
}
static int lov_getattr_interpret(struct ptlrpc_request_set *rqset,
void *data, int rc)
{
struct lov_request_set *lovset = (struct lov_request_set *)data;
int err;
if (rc)
atomic_set(&lovset->set_completes, 0);
err = lov_fini_getattr_set(lovset);
return rc ? rc : err;
}
static int lov_getattr_async(struct obd_export *exp, struct obd_info *oinfo,
struct ptlrpc_request_set *rqset)
{
struct lov_request_set *lovset;
struct lov_obd *lov;
struct list_head *pos;
struct lov_request *req;
int rc = 0, err;
LASSERT(oinfo);
ASSERT_LSM_MAGIC(oinfo->oi_md);
if (!exp || !exp->exp_obd)
return -ENODEV;
lov = &exp->exp_obd->u.lov;
rc = lov_prep_getattr_set(exp, oinfo, &lovset);
if (rc)
return rc;
CDEBUG(D_INFO, "objid "DOSTID": %ux%u byte stripes\n",
POSTID(&oinfo->oi_md->lsm_oi), oinfo->oi_md->lsm_stripe_count,
oinfo->oi_md->lsm_stripe_size);
list_for_each(pos, &lovset->set_list) {
req = list_entry(pos, struct lov_request, rq_link);
CDEBUG(D_INFO, "objid "DOSTID"[%d] has subobj "DOSTID" at idx"
"%u\n", POSTID(&oinfo->oi_oa->o_oi), req->rq_stripe,
POSTID(&req->rq_oi.oi_oa->o_oi), req->rq_idx);
rc = obd_getattr_async(lov->lov_tgts[req->rq_idx]->ltd_exp,
&req->rq_oi, rqset);
if (rc) {
CERROR("%s: getattr objid "DOSTID" subobj"
DOSTID" on OST idx %d: rc = %d\n",
exp->exp_obd->obd_name,
POSTID(&oinfo->oi_oa->o_oi),
POSTID(&req->rq_oi.oi_oa->o_oi),
req->rq_idx, rc);
GOTO(out, rc);
}
}
if (!list_empty(&rqset->set_requests)) {
LASSERT(rc == 0);
LASSERT(rqset->set_interpret == NULL);
rqset->set_interpret = lov_getattr_interpret;
rqset->set_arg = (void *)lovset;
return rc;
}
out:
if (rc)
atomic_set(&lovset->set_completes, 0);
err = lov_fini_getattr_set(lovset);
return rc ? rc : err;
}
static int lov_setattr(const struct lu_env *env, struct obd_export *exp,
struct obd_info *oinfo, struct obd_trans_info *oti)
{
struct lov_request_set *set;
struct lov_obd *lov;
struct list_head *pos;
struct lov_request *req;
int err = 0, rc = 0;
LASSERT(oinfo);
ASSERT_LSM_MAGIC(oinfo->oi_md);
if (!exp || !exp->exp_obd)
return -ENODEV;
LASSERT(!(oinfo->oi_oa->o_valid & ~(OBD_MD_FLID | OBD_MD_FLTYPE |
OBD_MD_FLMODE | OBD_MD_FLATIME |
OBD_MD_FLMTIME | OBD_MD_FLCTIME |
OBD_MD_FLFLAGS | OBD_MD_FLSIZE |
OBD_MD_FLGROUP | OBD_MD_FLUID |
OBD_MD_FLGID | OBD_MD_FLFID |
OBD_MD_FLGENER)));
lov = &exp->exp_obd->u.lov;
rc = lov_prep_setattr_set(exp, oinfo, oti, &set);
if (rc)
return rc;
list_for_each(pos, &set->set_list) {
req = list_entry(pos, struct lov_request, rq_link);
rc = obd_setattr(env, lov->lov_tgts[req->rq_idx]->ltd_exp,
&req->rq_oi, NULL);
err = lov_update_setattr_set(set, req, rc);
if (err) {
CERROR("%s: setattr objid "DOSTID" subobj "
DOSTID" on OST idx %d: rc = %d\n",
exp->exp_obd->obd_name,
POSTID(&set->set_oi->oi_oa->o_oi),
POSTID(&req->rq_oi.oi_oa->o_oi), req->rq_idx,
err);
if (!rc)
rc = err;
}
}
err = lov_fini_setattr_set(set);
if (!rc)
rc = err;
return rc;
}
static int lov_setattr_interpret(struct ptlrpc_request_set *rqset,
void *data, int rc)
{
struct lov_request_set *lovset = (struct lov_request_set *)data;
int err;
if (rc)
atomic_set(&lovset->set_completes, 0);
err = lov_fini_setattr_set(lovset);
return rc ? rc : err;
}
static int lov_setattr_async(struct obd_export *exp, struct obd_info *oinfo,
struct obd_trans_info *oti,
struct ptlrpc_request_set *rqset)
{
struct lov_request_set *set;
struct lov_request *req;
struct list_head *pos;
struct lov_obd *lov;
int rc = 0;
LASSERT(oinfo);
ASSERT_LSM_MAGIC(oinfo->oi_md);
if (oinfo->oi_oa->o_valid & OBD_MD_FLCOOKIE) {
LASSERT(oti);
LASSERT(oti->oti_logcookies);
}
if (!exp || !exp->exp_obd)
return -ENODEV;
lov = &exp->exp_obd->u.lov;
rc = lov_prep_setattr_set(exp, oinfo, oti, &set);
if (rc)
return rc;
CDEBUG(D_INFO, "objid "DOSTID": %ux%u byte stripes\n",
POSTID(&oinfo->oi_md->lsm_oi),
oinfo->oi_md->lsm_stripe_count,
oinfo->oi_md->lsm_stripe_size);
list_for_each(pos, &set->set_list) {
req = list_entry(pos, struct lov_request, rq_link);
if (oinfo->oi_oa->o_valid & OBD_MD_FLCOOKIE)
oti->oti_logcookies = set->set_cookies + req->rq_stripe;
CDEBUG(D_INFO, "objid "DOSTID"[%d] has subobj "DOSTID" at idx"
"%u\n", POSTID(&oinfo->oi_oa->o_oi), req->rq_stripe,
POSTID(&req->rq_oi.oi_oa->o_oi), req->rq_idx);
rc = obd_setattr_async(lov->lov_tgts[req->rq_idx]->ltd_exp,
&req->rq_oi, oti, rqset);
if (rc) {
CERROR("error: setattr objid "DOSTID" subobj"
DOSTID" on OST idx %d: rc = %d\n",
POSTID(&set->set_oi->oi_oa->o_oi),
POSTID(&req->rq_oi.oi_oa->o_oi),
req->rq_idx, rc);
break;
}
}
if (rc || !rqset || list_empty(&rqset->set_requests)) {
int err;
if (rc)
atomic_set(&set->set_completes, 0);
err = lov_fini_setattr_set(set);
return rc ? rc : err;
}
LASSERT(rqset->set_interpret == NULL);
rqset->set_interpret = lov_setattr_interpret;
rqset->set_arg = (void *)set;
return 0;
}
static int lov_punch_interpret(struct ptlrpc_request_set *rqset,
void *data, int rc)
{
struct lov_request_set *lovset = (struct lov_request_set *)data;
int err;
if (rc)
atomic_set(&lovset->set_completes, 0);
err = lov_fini_punch_set(lovset);
return rc ? rc : err;
}
static int lov_punch(const struct lu_env *env, struct obd_export *exp,
struct obd_info *oinfo, struct obd_trans_info *oti,
struct ptlrpc_request_set *rqset)
{
struct lov_request_set *set;
struct lov_obd *lov;
struct list_head *pos;
struct lov_request *req;
int rc = 0;
LASSERT(oinfo);
ASSERT_LSM_MAGIC(oinfo->oi_md);
if (!exp || !exp->exp_obd)
return -ENODEV;
lov = &exp->exp_obd->u.lov;
rc = lov_prep_punch_set(exp, oinfo, oti, &set);
if (rc)
return rc;
list_for_each(pos, &set->set_list) {
req = list_entry(pos, struct lov_request, rq_link);
rc = obd_punch(env, lov->lov_tgts[req->rq_idx]->ltd_exp,
&req->rq_oi, NULL, rqset);
if (rc) {
CERROR("%s: punch objid "DOSTID" subobj "DOSTID
" on OST idx %d: rc = %d\n",
exp->exp_obd->obd_name,
POSTID(&set->set_oi->oi_oa->o_oi),
POSTID(&req->rq_oi.oi_oa->o_oi), req->rq_idx, rc);
break;
}
}
if (rc || list_empty(&rqset->set_requests)) {
int err;
err = lov_fini_punch_set(set);
return rc ? rc : err;
}
LASSERT(rqset->set_interpret == NULL);
rqset->set_interpret = lov_punch_interpret;
rqset->set_arg = (void *)set;
return 0;
}
static int lov_sync_interpret(struct ptlrpc_request_set *rqset,
void *data, int rc)
{
struct lov_request_set *lovset = data;
int err;
if (rc)
atomic_set(&lovset->set_completes, 0);
err = lov_fini_sync_set(lovset);
return rc ?: err;
}
static int lov_sync(const struct lu_env *env, struct obd_export *exp,
struct obd_info *oinfo, obd_off start, obd_off end,
struct ptlrpc_request_set *rqset)
{
struct lov_request_set *set = NULL;
struct lov_obd *lov;
struct list_head *pos;
struct lov_request *req;
int rc = 0;
ASSERT_LSM_MAGIC(oinfo->oi_md);
LASSERT(rqset != NULL);
if (!exp->exp_obd)
return -ENODEV;
lov = &exp->exp_obd->u.lov;
rc = lov_prep_sync_set(exp, oinfo, start, end, &set);
if (rc)
return rc;
CDEBUG(D_INFO, "fsync objid "DOSTID" ["LPX64", "LPX64"]\n",
POSTID(&set->set_oi->oi_oa->o_oi), start, end);
list_for_each(pos, &set->set_list) {
req = list_entry(pos, struct lov_request, rq_link);
rc = obd_sync(env, lov->lov_tgts[req->rq_idx]->ltd_exp,
&req->rq_oi, req->rq_oi.oi_policy.l_extent.start,
req->rq_oi.oi_policy.l_extent.end, rqset);
if (rc) {
CERROR("%s: fsync objid "DOSTID" subobj "DOSTID
" on OST idx %d: rc = %d\n",
exp->exp_obd->obd_name,
POSTID(&set->set_oi->oi_oa->o_oi),
POSTID(&req->rq_oi.oi_oa->o_oi), req->rq_idx,
rc);
break;
}
}
if (rc || list_empty(&rqset->set_requests)) {
int err = lov_fini_sync_set(set);
return rc ?: err;
}
LASSERT(rqset->set_interpret == NULL);
rqset->set_interpret = lov_sync_interpret;
rqset->set_arg = (void *)set;
return 0;
}
static int lov_brw_check(struct lov_obd *lov, struct obd_info *lov_oinfo,
obd_count oa_bufs, struct brw_page *pga)
{
struct obd_info oinfo = { { { 0 } } };
int i, rc = 0;
oinfo.oi_oa = lov_oinfo->oi_oa;
for (i = 0; i < oa_bufs; i++) {
int stripe = lov_stripe_number(lov_oinfo->oi_md, pga[i].off);
int ost = lov_oinfo->oi_md->lsm_oinfo[stripe]->loi_ost_idx;
obd_off start, end;
if (!lov_stripe_intersects(lov_oinfo->oi_md, i, pga[i].off,
pga[i].off + pga[i].count - 1,
&start, &end))
continue;
if (!lov->lov_tgts[ost] || !lov->lov_tgts[ost]->ltd_active) {
CDEBUG(D_HA, "lov idx %d inactive\n", ost);
return -EIO;
}
rc = obd_brw(OBD_BRW_CHECK, lov->lov_tgts[ost]->ltd_exp, &oinfo,
1, &pga[i], NULL);
if (rc)
break;
}
return rc;
}
static int lov_brw(int cmd, struct obd_export *exp, struct obd_info *oinfo,
obd_count oa_bufs, struct brw_page *pga,
struct obd_trans_info *oti)
{
struct lov_request_set *set;
struct lov_request *req;
struct list_head *pos;
struct lov_obd *lov = &exp->exp_obd->u.lov;
int err, rc = 0;
ASSERT_LSM_MAGIC(oinfo->oi_md);
if (cmd == OBD_BRW_CHECK) {
rc = lov_brw_check(lov, oinfo, oa_bufs, pga);
return rc;
}
rc = lov_prep_brw_set(exp, oinfo, oa_bufs, pga, oti, &set);
if (rc)
return rc;
list_for_each(pos, &set->set_list) {
struct obd_export *sub_exp;
struct brw_page *sub_pga;
req = list_entry(pos, struct lov_request, rq_link);
sub_exp = lov->lov_tgts[req->rq_idx]->ltd_exp;
sub_pga = set->set_pga + req->rq_pgaidx;
rc = obd_brw(cmd, sub_exp, &req->rq_oi, req->rq_oabufs,
sub_pga, oti);
if (rc)
break;
lov_update_common_set(set, req, rc);
}
err = lov_fini_brw_set(set);
if (!rc)
rc = err;
return rc;
}
static int lov_enqueue_interpret(struct ptlrpc_request_set *rqset,
void *data, int rc)
{
struct lov_request_set *lovset = (struct lov_request_set *)data;
rc = lov_fini_enqueue_set(lovset, lovset->set_ei->ei_mode, rc, rqset);
return rc;
}
static int lov_enqueue(struct obd_export *exp, struct obd_info *oinfo,
struct ldlm_enqueue_info *einfo,
struct ptlrpc_request_set *rqset)
{
ldlm_mode_t mode = einfo->ei_mode;
struct lov_request_set *set;
struct lov_request *req;
struct list_head *pos;
struct lov_obd *lov;
ldlm_error_t rc;
LASSERT(oinfo);
ASSERT_LSM_MAGIC(oinfo->oi_md);
LASSERT(mode == (mode & -mode));
LASSERT((oinfo->oi_flags & LDLM_FL_REPLAY) == 0);
if (!exp || !exp->exp_obd)
return -ENODEV;
lov = &exp->exp_obd->u.lov;
rc = lov_prep_enqueue_set(exp, oinfo, einfo, &set);
if (rc)
return rc;
list_for_each(pos, &set->set_list) {
req = list_entry(pos, struct lov_request, rq_link);
rc = obd_enqueue(lov->lov_tgts[req->rq_idx]->ltd_exp,
&req->rq_oi, einfo, rqset);
if (rc != ELDLM_OK)
GOTO(out, rc);
}
if (rqset && !list_empty(&rqset->set_requests)) {
LASSERT(rc == 0);
LASSERT(rqset->set_interpret == NULL);
rqset->set_interpret = lov_enqueue_interpret;
rqset->set_arg = (void *)set;
return rc;
}
out:
rc = lov_fini_enqueue_set(set, mode, rc, rqset);
return rc;
}
static int lov_change_cbdata(struct obd_export *exp,
struct lov_stripe_md *lsm, ldlm_iterator_t it,
void *data)
{
struct lov_obd *lov;
int rc = 0, i;
ASSERT_LSM_MAGIC(lsm);
if (!exp || !exp->exp_obd)
return -ENODEV;
lov = &exp->exp_obd->u.lov;
for (i = 0; i < lsm->lsm_stripe_count; i++) {
struct lov_stripe_md submd;
struct lov_oinfo *loi = lsm->lsm_oinfo[i];
if (!lov->lov_tgts[loi->loi_ost_idx]) {
CDEBUG(D_HA, "lov idx %d NULL \n", loi->loi_ost_idx);
continue;
}
submd.lsm_oi = loi->loi_oi;
submd.lsm_stripe_count = 0;
rc = obd_change_cbdata(lov->lov_tgts[loi->loi_ost_idx]->ltd_exp,
&submd, it, data);
}
return rc;
}
static int lov_find_cbdata(struct obd_export *exp,
struct lov_stripe_md *lsm, ldlm_iterator_t it,
void *data)
{
struct lov_obd *lov;
int rc = 0, i;
ASSERT_LSM_MAGIC(lsm);
if (!exp || !exp->exp_obd)
return -ENODEV;
lov = &exp->exp_obd->u.lov;
for (i = 0; i < lsm->lsm_stripe_count; i++) {
struct lov_stripe_md submd;
struct lov_oinfo *loi = lsm->lsm_oinfo[i];
if (!lov->lov_tgts[loi->loi_ost_idx]) {
CDEBUG(D_HA, "lov idx %d NULL \n", loi->loi_ost_idx);
continue;
}
submd.lsm_oi = loi->loi_oi;
submd.lsm_stripe_count = 0;
rc = obd_find_cbdata(lov->lov_tgts[loi->loi_ost_idx]->ltd_exp,
&submd, it, data);
if (rc != 0)
return rc;
}
return rc;
}
static int lov_cancel(struct obd_export *exp, struct lov_stripe_md *lsm,
__u32 mode, struct lustre_handle *lockh)
{
struct lov_request_set *set;
struct obd_info oinfo;
struct lov_request *req;
struct list_head *pos;
struct lov_obd *lov;
struct lustre_handle *lov_lockhp;
int err = 0, rc = 0;
ASSERT_LSM_MAGIC(lsm);
if (!exp || !exp->exp_obd)
return -ENODEV;
LASSERT(lockh);
lov = &exp->exp_obd->u.lov;
rc = lov_prep_cancel_set(exp, &oinfo, lsm, mode, lockh, &set);
if (rc)
return rc;
list_for_each(pos, &set->set_list) {
req = list_entry(pos, struct lov_request, rq_link);
lov_lockhp = set->set_lockh->llh_handles + req->rq_stripe;
rc = obd_cancel(lov->lov_tgts[req->rq_idx]->ltd_exp,
req->rq_oi.oi_md, mode, lov_lockhp);
rc = lov_update_common_set(set, req, rc);
if (rc) {
CERROR("%s: cancel objid "DOSTID" subobj "
DOSTID" on OST idx %d: rc = %d\n",
exp->exp_obd->obd_name, POSTID(&lsm->lsm_oi),
POSTID(&req->rq_oi.oi_md->lsm_oi),
req->rq_idx, rc);
err = rc;
}
}
lov_fini_cancel_set(set);
return err;
}
static int lov_cancel_unused(struct obd_export *exp,
struct lov_stripe_md *lsm,
ldlm_cancel_flags_t flags, void *opaque)
{
struct lov_obd *lov;
int rc = 0, i;
if (!exp || !exp->exp_obd)
return -ENODEV;
lov = &exp->exp_obd->u.lov;
if (lsm == NULL) {
for (i = 0; i < lov->desc.ld_tgt_count; i++) {
int err;
if (!lov->lov_tgts[i] || !lov->lov_tgts[i]->ltd_exp)
continue;
err = obd_cancel_unused(lov->lov_tgts[i]->ltd_exp, NULL,
flags, opaque);
if (!rc)
rc = err;
}
return rc;
}
ASSERT_LSM_MAGIC(lsm);
for (i = 0; i < lsm->lsm_stripe_count; i++) {
struct lov_stripe_md submd;
struct lov_oinfo *loi = lsm->lsm_oinfo[i];
int idx = loi->loi_ost_idx;
int err;
if (!lov->lov_tgts[idx]) {
CDEBUG(D_HA, "lov idx %d NULL\n", idx);
continue;
}
if (!lov->lov_tgts[idx]->ltd_active)
CDEBUG(D_HA, "lov idx %d inactive\n", idx);
submd.lsm_oi = loi->loi_oi;
submd.lsm_stripe_count = 0;
err = obd_cancel_unused(lov->lov_tgts[idx]->ltd_exp,
&submd, flags, opaque);
if (err && lov->lov_tgts[idx]->ltd_active) {
CERROR("%s: cancel unused objid "DOSTID
" subobj "DOSTID" on OST idx %d: rc = %d\n",
exp->exp_obd->obd_name, POSTID(&lsm->lsm_oi),
POSTID(&loi->loi_oi), idx, err);
if (!rc)
rc = err;
}
}
return rc;
}
int lov_statfs_interpret(struct ptlrpc_request_set *rqset, void *data, int rc)
{
struct lov_request_set *lovset = (struct lov_request_set *)data;
int err;
if (rc)
atomic_set(&lovset->set_completes, 0);
err = lov_fini_statfs_set(lovset);
return rc ? rc : err;
}
static int lov_statfs_async(struct obd_export *exp, struct obd_info *oinfo,
__u64 max_age, struct ptlrpc_request_set *rqset)
{
struct obd_device *obd = class_exp2obd(exp);
struct lov_request_set *set;
struct lov_request *req;
struct list_head *pos;
struct lov_obd *lov;
int rc = 0;
LASSERT(oinfo != NULL);
LASSERT(oinfo->oi_osfs != NULL);
lov = &obd->u.lov;
rc = lov_prep_statfs_set(obd, oinfo, &set);
if (rc)
return rc;
list_for_each(pos, &set->set_list) {
req = list_entry(pos, struct lov_request, rq_link);
rc = obd_statfs_async(lov->lov_tgts[req->rq_idx]->ltd_exp,
&req->rq_oi, max_age, rqset);
if (rc)
break;
}
if (rc || list_empty(&rqset->set_requests)) {
int err;
if (rc)
atomic_set(&set->set_completes, 0);
err = lov_fini_statfs_set(set);
return rc ? rc : err;
}
LASSERT(rqset->set_interpret == NULL);
rqset->set_interpret = lov_statfs_interpret;
rqset->set_arg = (void *)set;
return 0;
}
static int lov_statfs(const struct lu_env *env, struct obd_export *exp,
struct obd_statfs *osfs, __u64 max_age, __u32 flags)
{
struct ptlrpc_request_set *set = NULL;
struct obd_info oinfo = { { { 0 } } };
int rc = 0;
set = ptlrpc_prep_set();
if (set == NULL)
return -ENOMEM;
oinfo.oi_osfs = osfs;
oinfo.oi_flags = flags;
rc = lov_statfs_async(exp, &oinfo, max_age, set);
if (rc == 0)
rc = ptlrpc_set_wait(set);
ptlrpc_set_destroy(set);
return rc;
}
static int lov_iocontrol(unsigned int cmd, struct obd_export *exp, int len,
void *karg, void *uarg)
{
struct obd_device *obddev = class_exp2obd(exp);
struct lov_obd *lov = &obddev->u.lov;
int i = 0, rc = 0, count = lov->desc.ld_tgt_count;
struct obd_uuid *uuidp;
switch (cmd) {
case IOC_OBD_STATFS: {
struct obd_ioctl_data *data = karg;
struct obd_device *osc_obd;
struct obd_statfs stat_buf = {0};
__u32 index;
__u32 flags;
memcpy(&index, data->ioc_inlbuf2, sizeof(__u32));
if ((index >= count))
return -ENODEV;
if (!lov->lov_tgts[index])
return -EAGAIN;
if (!lov->lov_tgts[index]->ltd_active)
return -ENODATA;
osc_obd = class_exp2obd(lov->lov_tgts[index]->ltd_exp);
if (!osc_obd)
return -EINVAL;
if (copy_to_user(data->ioc_pbuf2, obd2cli_tgt(osc_obd),
min((int) data->ioc_plen2,
(int) sizeof(struct obd_uuid))))
return -EFAULT;
flags = uarg ? *(__u32 *)uarg : 0;
rc = obd_statfs(NULL, lov->lov_tgts[index]->ltd_exp, &stat_buf,
cfs_time_shift_64(-OBD_STATFS_CACHE_SECONDS),
flags);
if (rc)
return rc;
if (copy_to_user(data->ioc_pbuf1, &stat_buf,
min((int) data->ioc_plen1,
(int) sizeof(stat_buf))))
return -EFAULT;
break;
}
case OBD_IOC_LOV_GET_CONFIG: {
struct obd_ioctl_data *data;
struct lov_desc *desc;
char *buf = NULL;
__u32 *genp;
len = 0;
if (obd_ioctl_getdata(&buf, &len, (void *)uarg))
return -EINVAL;
data = (struct obd_ioctl_data *)buf;
if (sizeof(*desc) > data->ioc_inllen1) {
obd_ioctl_freedata(buf, len);
return -EINVAL;
}
if (sizeof(uuidp->uuid) * count > data->ioc_inllen2) {
obd_ioctl_freedata(buf, len);
return -EINVAL;
}
if (sizeof(__u32) * count > data->ioc_inllen3) {
obd_ioctl_freedata(buf, len);
return -EINVAL;
}
desc = (struct lov_desc *)data->ioc_inlbuf1;
memcpy(desc, &(lov->desc), sizeof(*desc));
uuidp = (struct obd_uuid *)data->ioc_inlbuf2;
genp = (__u32 *)data->ioc_inlbuf3;
for (i = 0; i < count; i++, uuidp++, genp++) {
if (!lov->lov_tgts[i])
continue;
*uuidp = lov->lov_tgts[i]->ltd_uuid;
*genp = lov->lov_tgts[i]->ltd_gen;
}
if (copy_to_user((void *)uarg, buf, len))
rc = -EFAULT;
obd_ioctl_freedata(buf, len);
break;
}
case LL_IOC_LOV_SETSTRIPE:
rc = lov_setstripe(exp, len, karg, uarg);
break;
case LL_IOC_LOV_GETSTRIPE:
rc = lov_getstripe(exp, karg, uarg);
break;
case LL_IOC_LOV_SETEA:
rc = lov_setea(exp, karg, uarg);
break;
case OBD_IOC_QUOTACTL: {
struct if_quotactl *qctl = karg;
struct lov_tgt_desc *tgt = NULL;
struct obd_quotactl *oqctl;
if (qctl->qc_valid == QC_OSTIDX) {
if (qctl->qc_idx < 0 || count <= qctl->qc_idx)
return -EINVAL;
tgt = lov->lov_tgts[qctl->qc_idx];
if (!tgt || !tgt->ltd_exp)
return -EINVAL;
} else if (qctl->qc_valid == QC_UUID) {
for (i = 0; i < count; i++) {
tgt = lov->lov_tgts[i];
if (!tgt ||
!obd_uuid_equals(&tgt->ltd_uuid,
&qctl->obd_uuid))
continue;
if (tgt->ltd_exp == NULL)
return -EINVAL;
break;
}
} else {
return -EINVAL;
}
if (i >= count)
return -EAGAIN;
LASSERT(tgt && tgt->ltd_exp);
OBD_ALLOC_PTR(oqctl);
if (!oqctl)
return -ENOMEM;
QCTL_COPY(oqctl, qctl);
rc = obd_quotactl(tgt->ltd_exp, oqctl);
if (rc == 0) {
QCTL_COPY(qctl, oqctl);
qctl->qc_valid = QC_OSTIDX;
qctl->obd_uuid = tgt->ltd_uuid;
}
OBD_FREE_PTR(oqctl);
break;
}
default: {
int set = 0;
if (count == 0)
return -ENOTTY;
for (i = 0; i < count; i++) {
int err;
struct obd_device *osc_obd;
if (!lov->lov_tgts[i] || !lov->lov_tgts[i]->ltd_exp)
continue;
osc_obd = class_exp2obd(lov->lov_tgts[i]->ltd_exp);
osc_obd->obd_force = obddev->obd_force;
err = obd_iocontrol(cmd, lov->lov_tgts[i]->ltd_exp,
len, karg, uarg);
if (err == -ENODATA && cmd == OBD_IOC_POLL_QUOTACHECK) {
return err;
} else if (err) {
if (lov->lov_tgts[i]->ltd_active) {
CDEBUG(err == -ENOTTY ?
D_IOCTL : D_WARNING,
"iocontrol OSC %s on OST "
"idx %d cmd %x: err = %d\n",
lov_uuid2str(lov, i),
i, cmd, err);
if (!rc)
rc = err;
}
} else {
set = 1;
}
}
if (!set && !rc)
rc = -EIO;
}
}
return rc;
}
obd_size fiemap_calc_fm_end_offset(struct ll_user_fiemap *fiemap,
struct lov_stripe_md *lsm, obd_size fm_start,
obd_size fm_end, int *start_stripe)
{
obd_size local_end = fiemap->fm_extents[0].fe_logical;
obd_off lun_start, lun_end;
obd_size fm_end_offset;
int stripe_no = -1, i;
if (fiemap->fm_extent_count == 0 ||
fiemap->fm_extents[0].fe_logical == 0)
return 0;
for (i = 0; i < lsm->lsm_stripe_count; i++) {
if (lsm->lsm_oinfo[i]->loi_ost_idx ==
fiemap->fm_extents[0].fe_device) {
stripe_no = i;
break;
}
}
if (stripe_no == -1)
return -EINVAL;
if ((lov_stripe_intersects(lsm, stripe_no, fm_start, fm_end,
&lun_start, &lun_end)) != 0 &&
local_end < lun_end) {
fm_end_offset = local_end;
*start_stripe = stripe_no;
} else {
fm_end_offset = 0;
*start_stripe = (stripe_no + 1) % lsm->lsm_stripe_count;
}
return fm_end_offset;
}
int fiemap_calc_last_stripe(struct lov_stripe_md *lsm, obd_size fm_start,
obd_size fm_end, int start_stripe,
int *stripe_count)
{
int last_stripe;
obd_off obd_start, obd_end;
int i, j;
if (fm_end - fm_start > lsm->lsm_stripe_size * lsm->lsm_stripe_count) {
last_stripe = (start_stripe < 1 ? lsm->lsm_stripe_count - 1 :
start_stripe - 1);
*stripe_count = lsm->lsm_stripe_count;
} else {
for (j = 0, i = start_stripe; j < lsm->lsm_stripe_count;
i = (i + 1) % lsm->lsm_stripe_count, j++) {
if ((lov_stripe_intersects(lsm, i, fm_start, fm_end,
&obd_start, &obd_end)) == 0)
break;
}
*stripe_count = j;
last_stripe = (start_stripe + j - 1) %lsm->lsm_stripe_count;
}
return last_stripe;
}
void fiemap_prepare_and_copy_exts(struct ll_user_fiemap *fiemap,
struct ll_fiemap_extent *lcl_fm_ext,
int ost_index, unsigned int ext_count,
int current_extent)
{
char *to;
int ext;
for (ext = 0; ext < ext_count; ext++) {
lcl_fm_ext[ext].fe_device = ost_index;
lcl_fm_ext[ext].fe_flags |= FIEMAP_EXTENT_NET;
}
to = (char *)fiemap + fiemap_count_to_size(current_extent);
memcpy(to, lcl_fm_ext, ext_count * sizeof(struct ll_fiemap_extent));
}
static int lov_fiemap(struct lov_obd *lov, __u32 keylen, void *key,
__u32 *vallen, void *val, struct lov_stripe_md *lsm)
{
struct ll_fiemap_info_key *fm_key = key;
struct ll_user_fiemap *fiemap = val;
struct ll_user_fiemap *fm_local = NULL;
struct ll_fiemap_extent *lcl_fm_ext;
int count_local;
unsigned int get_num_extents = 0;
int ost_index = 0, actual_start_stripe, start_stripe;
obd_size fm_start, fm_end, fm_length, fm_end_offset;
obd_size curr_loc;
int current_extent = 0, rc = 0, i;
int ost_eof = 0;
int ost_done = 0;
int last_stripe;
int cur_stripe = 0, cur_stripe_wrap = 0, stripe_count;
unsigned int buffer_size = FIEMAP_BUFFER_SIZE;
if (!lsm_has_objects(lsm))
GOTO(out, rc = 0);
if (fiemap_count_to_size(fm_key->fiemap.fm_extent_count) < buffer_size)
buffer_size = fiemap_count_to_size(fm_key->fiemap.fm_extent_count);
OBD_ALLOC_LARGE(fm_local, buffer_size);
if (fm_local == NULL)
GOTO(out, rc = -ENOMEM);
lcl_fm_ext = &fm_local->fm_extents[0];
count_local = fiemap_size_to_count(buffer_size);
memcpy(fiemap, &fm_key->fiemap, sizeof(*fiemap));
fm_start = fiemap->fm_start;
fm_length = fiemap->fm_length;
actual_start_stripe = start_stripe = lov_stripe_number(lsm, fm_start);
fm_end = (fm_length == ~0ULL ? fm_key->oa.o_size :
fm_start + fm_length - 1);
if (fm_end > fm_key->oa.o_size)
fm_end = fm_key->oa.o_size;
last_stripe = fiemap_calc_last_stripe(lsm, fm_start, fm_end,
actual_start_stripe, &stripe_count);
fm_end_offset = fiemap_calc_fm_end_offset(fiemap, lsm, fm_start,
fm_end, &start_stripe);
if (fm_end_offset == -EINVAL)
GOTO(out, rc = -EINVAL);
if (fiemap_count_to_size(fiemap->fm_extent_count) > *vallen)
fiemap->fm_extent_count = fiemap_size_to_count(*vallen);
if (fiemap->fm_extent_count == 0) {
get_num_extents = 1;
count_local = 0;
}
for (cur_stripe = start_stripe, i = 0; i < stripe_count;
i++, cur_stripe = (cur_stripe + 1) % lsm->lsm_stripe_count) {
obd_size req_fm_len;
obd_size len_mapped_single_call;
obd_off lun_start, lun_end, obd_object_end;
unsigned int ext_count;
cur_stripe_wrap = cur_stripe;
if ((lov_stripe_intersects(lsm, cur_stripe, fm_start, fm_end,
&lun_start, &obd_object_end)) == 0)
continue;
if (fm_end_offset != 0 && cur_stripe == start_stripe)
lun_start = fm_end_offset;
if (fm_length != ~0ULL) {
if (fm_start + fm_length < fm_start)
fm_length = ~0ULL - fm_start;
lun_end = lov_size_to_stripe(lsm, fm_start + fm_length,
cur_stripe);
} else {
lun_end = ~0ULL;
}
if (lun_start == lun_end)
continue;
req_fm_len = obd_object_end - lun_start;
fm_local->fm_length = 0;
len_mapped_single_call = 0;
ost_eof = 0;
ost_done = 0;
do {
if (get_num_extents == 0) {
if (current_extent + count_local >
fiemap->fm_extent_count)
count_local = fiemap->fm_extent_count -
current_extent;
}
lun_start += len_mapped_single_call;
fm_local->fm_length = req_fm_len - len_mapped_single_call;
req_fm_len = fm_local->fm_length;
fm_local->fm_extent_count = count_local;
fm_local->fm_mapped_extents = 0;
fm_local->fm_flags = fiemap->fm_flags;
fm_key->oa.o_oi = lsm->lsm_oinfo[cur_stripe]->loi_oi;
ost_index = lsm->lsm_oinfo[cur_stripe]->loi_ost_idx;
if (ost_index < 0 || ost_index >=lov->desc.ld_tgt_count)
GOTO(out, rc = -EINVAL);
if (!lov->lov_tgts[ost_index]->ltd_active) {
fm_local->fm_flags |= FIEMAP_EXTENT_LAST;
fm_local->fm_mapped_extents = 1;
lcl_fm_ext[0].fe_logical = lun_start;
lcl_fm_ext[0].fe_length = obd_object_end -
lun_start;
lcl_fm_ext[0].fe_flags |= FIEMAP_EXTENT_UNKNOWN;
goto inactive_tgt;
}
fm_local->fm_start = lun_start;
fm_local->fm_flags &= ~FIEMAP_FLAG_DEVICE_ORDER;
memcpy(&fm_key->fiemap, fm_local, sizeof(*fm_local));
*vallen=fiemap_count_to_size(fm_local->fm_extent_count);
rc = obd_get_info(NULL,
lov->lov_tgts[ost_index]->ltd_exp,
keylen, key, vallen, fm_local, lsm);
if (rc != 0)
GOTO(out, rc);
inactive_tgt:
ext_count = fm_local->fm_mapped_extents;
if (ext_count == 0) {
ost_done = 1;
if (cur_stripe_wrap == last_stripe) {
fiemap->fm_mapped_extents = 0;
goto finish;
}
break;
}
if (get_num_extents) {
current_extent += ext_count;
break;
}
len_mapped_single_call = lcl_fm_ext[ext_count-1].fe_logical -
lun_start + lcl_fm_ext[ext_count - 1].fe_length;
if (req_fm_len <= len_mapped_single_call)
ost_done = 1;
if (lcl_fm_ext[ext_count-1].fe_flags & FIEMAP_EXTENT_LAST)
lcl_fm_ext[ext_count - 1].fe_flags &=
~FIEMAP_EXTENT_LAST;
curr_loc = lov_stripe_size(lsm,
lcl_fm_ext[ext_count - 1].fe_logical+
lcl_fm_ext[ext_count - 1].fe_length,
cur_stripe);
if (curr_loc >= fm_key->oa.o_size)
ost_eof = 1;
fiemap_prepare_and_copy_exts(fiemap, lcl_fm_ext,
ost_index, ext_count,
current_extent);
current_extent += ext_count;
if (current_extent >= fiemap->fm_extent_count)
goto finish;
} while (ost_done == 0 && ost_eof == 0);
if (cur_stripe_wrap == last_stripe)
goto finish;
}
finish:
if (lsm->lsm_stripe_count > 1)
fiemap->fm_flags |= FIEMAP_FLAG_DEVICE_ORDER;
if (get_num_extents)
goto skip_last_device_calc;
if (cur_stripe_wrap == last_stripe) {
if (ost_done || ost_eof)
fiemap->fm_extents[current_extent - 1].fe_flags |=
FIEMAP_EXTENT_LAST;
}
skip_last_device_calc:
fiemap->fm_mapped_extents = current_extent;
out:
OBD_FREE_LARGE(fm_local, buffer_size);
return rc;
}
static int lov_get_info(const struct lu_env *env, struct obd_export *exp,
__u32 keylen, void *key, __u32 *vallen, void *val,
struct lov_stripe_md *lsm)
{
struct obd_device *obddev = class_exp2obd(exp);
struct lov_obd *lov = &obddev->u.lov;
int i, rc;
if (!vallen || !val)
return -EFAULT;
obd_getref(obddev);
if (KEY_IS(KEY_LOCK_TO_STRIPE)) {
struct {
char name[16];
struct ldlm_lock *lock;
} *data = key;
struct ldlm_res_id *res_id = &data->lock->l_resource->lr_name;
struct lov_oinfo *loi;
__u32 *stripe = val;
if (*vallen < sizeof(*stripe))
GOTO(out, rc = -EFAULT);
*vallen = sizeof(*stripe);
for (i = 0; i < lsm->lsm_stripe_count; i++) {
loi = lsm->lsm_oinfo[i];
if (!lov->lov_tgts[loi->loi_ost_idx])
continue;
if (lov->lov_tgts[loi->loi_ost_idx]->ltd_exp ==
data->lock->l_conn_export &&
ostid_res_name_eq(&loi->loi_oi, res_id)) {
*stripe = i;
GOTO(out, rc = 0);
}
}
LDLM_ERROR(data->lock, "lock on inode without such object");
dump_lsm(D_ERROR, lsm);
GOTO(out, rc = -ENXIO);
} else if (KEY_IS(KEY_LAST_ID)) {
struct obd_id_info *info = val;
__u32 size = sizeof(obd_id);
struct lov_tgt_desc *tgt;
LASSERT(*vallen == sizeof(struct obd_id_info));
tgt = lov->lov_tgts[info->idx];
if (!tgt || !tgt->ltd_active)
GOTO(out, rc = -ESRCH);
rc = obd_get_info(env, tgt->ltd_exp, keylen, key,
&size, info->data, NULL);
GOTO(out, rc = 0);
} else if (KEY_IS(KEY_LOVDESC)) {
struct lov_desc *desc_ret = val;
*desc_ret = lov->desc;
GOTO(out, rc = 0);
} else if (KEY_IS(KEY_FIEMAP)) {
rc = lov_fiemap(lov, keylen, key, vallen, val, lsm);
GOTO(out, rc);
} else if (KEY_IS(KEY_CONNECT_FLAG)) {
struct lov_tgt_desc *tgt;
__u64 ost_idx = *((__u64 *)val);
LASSERT(*vallen == sizeof(__u64));
LASSERT(ost_idx < lov->desc.ld_tgt_count);
tgt = lov->lov_tgts[ost_idx];
if (!tgt || !tgt->ltd_exp)
GOTO(out, rc = -ESRCH);
*((__u64 *)val) = exp_connect_flags(tgt->ltd_exp);
GOTO(out, rc = 0);
} else if (KEY_IS(KEY_TGT_COUNT)) {
*((int *)val) = lov->desc.ld_tgt_count;
GOTO(out, rc = 0);
}
rc = -EINVAL;
out:
obd_putref(obddev);
return rc;
}
static int lov_set_info_async(const struct lu_env *env, struct obd_export *exp,
obd_count keylen, void *key, obd_count vallen,
void *val, struct ptlrpc_request_set *set)
{
struct obd_device *obddev = class_exp2obd(exp);
struct lov_obd *lov = &obddev->u.lov;
obd_count count;
int i, rc = 0, err;
struct lov_tgt_desc *tgt;
unsigned incr, check_uuid,
do_inactive, no_set;
unsigned next_id = 0, mds_con = 0, capa = 0;
incr = check_uuid = do_inactive = no_set = 0;
if (set == NULL) {
no_set = 1;
set = ptlrpc_prep_set();
if (!set)
return -ENOMEM;
}
obd_getref(obddev);
count = lov->desc.ld_tgt_count;
if (KEY_IS(KEY_NEXT_ID)) {
count = vallen / sizeof(struct obd_id_info);
vallen = sizeof(obd_id);
incr = sizeof(struct obd_id_info);
do_inactive = 1;
next_id = 1;
} else if (KEY_IS(KEY_CHECKSUM)) {
do_inactive = 1;
} else if (KEY_IS(KEY_EVICT_BY_NID)) {
} else if (KEY_IS(KEY_MDS_CONN)) {
mds_con = 1;
} else if (KEY_IS(KEY_CAPA_KEY)) {
capa = 1;
} else if (KEY_IS(KEY_CACHE_SET)) {
LASSERT(lov->lov_cache == NULL);
lov->lov_cache = val;
do_inactive = 1;
}
for (i = 0; i < count; i++, val = (char *)val + incr) {
if (next_id) {
tgt = lov->lov_tgts[((struct obd_id_info *)val)->idx];
}
int lov_extent_calc(struct obd_export *exp, struct lov_stripe_md *lsm,
int cmd, __u64 *offset)
{
__u32 ssize = lsm->lsm_stripe_size;
__u64 start;
start = *offset;
lov_do_div64(start, ssize);
start = start * ssize;
CDEBUG(D_DLMTRACE, "offset "LPU64", stripe %u, start "LPU64
", end "LPU64"\n", *offset, ssize, start,
start + ssize - 1);
if (cmd == OBD_CALC_STRIPE_END) {
*offset = start + ssize - 1;
} else if (cmd == OBD_CALC_STRIPE_START) {
*offset = start;
} else {
LBUG();
}
return 0;
}
void lov_stripe_lock(struct lov_stripe_md *md)
{
LASSERT(md->lsm_lock_owner != current_pid());
spin_lock(&md->lsm_lock);
LASSERT(md->lsm_lock_owner == 0);
md->lsm_lock_owner = current_pid();
}
void lov_stripe_unlock(struct lov_stripe_md *md)
{
LASSERT(md->lsm_lock_owner == current_pid());
md->lsm_lock_owner = 0;
spin_unlock(&md->lsm_lock);
}
static int lov_quotactl(struct obd_device *obd, struct obd_export *exp,
struct obd_quotactl *oqctl)
{
struct lov_obd *lov = &obd->u.lov;
struct lov_tgt_desc *tgt;
__u64 curspace = 0;
__u64 bhardlimit = 0;
int i, rc = 0;
if (oqctl->qc_cmd != LUSTRE_Q_QUOTAON &&
oqctl->qc_cmd != LUSTRE_Q_QUOTAOFF &&
oqctl->qc_cmd != Q_GETOQUOTA &&
oqctl->qc_cmd != Q_INITQUOTA &&
oqctl->qc_cmd != LUSTRE_Q_SETQUOTA &&
oqctl->qc_cmd != Q_FINVALIDATE) {
CERROR("bad quota opc %x for lov obd", oqctl->qc_cmd);
return -EFAULT;
}
obd_getref(obd);
for (i = 0; i < lov->desc.ld_tgt_count; i++) {
int err;
tgt = lov->lov_tgts[i];
if (!tgt)
continue;
if (!tgt->ltd_active || tgt->ltd_reap) {
if (oqctl->qc_cmd == Q_GETOQUOTA &&
lov->lov_tgts[i]->ltd_activate) {
rc = -EREMOTEIO;
CERROR("ost %d is inactive\n", i);
} else {
CDEBUG(D_HA, "ost %d is inactive\n", i);
}
continue;
}
err = obd_quotactl(tgt->ltd_exp, oqctl);
if (err) {
if (tgt->ltd_active && !rc)
rc = err;
continue;
}
if (oqctl->qc_cmd == Q_GETOQUOTA) {
curspace += oqctl->qc_dqblk.dqb_curspace;
bhardlimit += oqctl->qc_dqblk.dqb_bhardlimit;
}
}
obd_putref(obd);
if (oqctl->qc_cmd == Q_GETOQUOTA) {
oqctl->qc_dqblk.dqb_curspace = curspace;
oqctl->qc_dqblk.dqb_bhardlimit = bhardlimit;
}
return rc;
}
static int lov_quotacheck(struct obd_device *obd, struct obd_export *exp,
struct obd_quotactl *oqctl)
{
struct lov_obd *lov = &obd->u.lov;
int i, rc = 0;
obd_getref(obd);
for (i = 0; i < lov->desc.ld_tgt_count; i++) {
if (!lov->lov_tgts[i])
continue;
if (!lov->lov_tgts[i]->ltd_activate) {
CWARN("lov idx %d was administratively disabled, "
"skip quotacheck on it.\n", i);
continue;
}
if (!lov->lov_tgts[i]->ltd_active) {
CERROR("lov idx %d inactive\n", i);
rc = -EIO;
goto out;
}
}
for (i = 0; i < lov->desc.ld_tgt_count; i++) {
int err;
if (!lov->lov_tgts[i] || !lov->lov_tgts[i]->ltd_activate)
continue;
err = obd_quotacheck(lov->lov_tgts[i]->ltd_exp, oqctl);
if (err && !rc)
rc = err;
}
out:
obd_putref(obd);
return rc;
}
int __init lov_init(void)
{
struct lprocfs_static_vars lvars = { 0 };
int rc;
CDEBUG(D_INFO, "Lustre LOV module (%p).\n", &lov_caches);
rc = lu_kmem_init(lov_caches);
if (rc)
return rc;
lov_oinfo_slab = kmem_cache_create("lov_oinfo",
sizeof(struct lov_oinfo),
0, SLAB_HWCACHE_ALIGN, NULL);
if (lov_oinfo_slab == NULL) {
lu_kmem_fini(lov_caches);
return -ENOMEM;
}
lprocfs_lov_init_vars(&lvars);
rc = class_register_type(&lov_obd_ops, NULL, lvars.module_vars,
LUSTRE_LOV_NAME, &lov_device_type);
if (rc) {
kmem_cache_destroy(lov_oinfo_slab);
lu_kmem_fini(lov_caches);
}
return rc;
}
static void lov_exit(void)
{
class_unregister_type(LUSTRE_LOV_NAME);
kmem_cache_destroy(lov_oinfo_slab);
lu_kmem_fini(lov_caches);
}
