int class_find_param(char *buf, char *key, char **valp)
{
char *ptr;
if (!buf)
return 1;
ptr = strstr(buf, key);
if (ptr == NULL)
return 1;
if (valp)
*valp = ptr + strlen(key);
return 0;
}
struct cfg_interop_param *class_find_old_param(const char *param,
struct cfg_interop_param *ptr)
{
char *value = NULL;
int name_len = 0;
if (param == NULL || ptr == NULL)
return NULL;
value = strchr(param, '=');
if (value == NULL)
name_len = strlen(param);
else
name_len = value - param;
while (ptr->old_param != NULL) {
if (strncmp(param, ptr->old_param, name_len) == 0 &&
name_len == strlen(ptr->old_param))
return ptr;
ptr++;
}
return NULL;
}
int class_get_next_param(char **params, char *copy)
{
char *q1, *q2, *str;
int len;
str = *params;
while (*str == ' ')
str++;
if (*str == '\0') {
*params = NULL;
return 1;
}
while (1) {
q1 = strpbrk(str, " '\"");
if (q1 == NULL) {
len = strlen(str);
memcpy(copy, str, len);
copy[len] = '\0';
*params = NULL;
return 0;
}
len = q1 - str;
if (*q1 == ' ') {
memcpy(copy, str, len);
copy[len] = '\0';
*params = str + len;
return 0;
}
memcpy(copy, str, len);
copy += len;
str = q1 + 1;
q2 = strchr(str, *q1);
if (q2 == NULL) {
CERROR("Unbalanced quota in parameters: \"%s\"\n",
*params);
return -EINVAL;
}
len = q2 - str;
memcpy(copy, str, len);
copy += len;
str = q2 + 1;
}
return 1;
}
int class_match_param(char *buf, char *key, char **valp)
{
if (!buf)
return 1;
if (memcmp(buf, key, strlen(key)) != 0)
return 1;
if (valp)
*valp = buf + strlen(key);
return 0;
}
static int parse_nid(char *buf, void *value, int quiet)
{
lnet_nid_t *nid = (lnet_nid_t *)value;
*nid = libcfs_str2nid(buf);
if (*nid != LNET_NID_ANY)
return 0;
if (!quiet)
LCONSOLE_ERROR_MSG(0x159, "Can't parse NID '%s'\n", buf);
return -EINVAL;
}
static int parse_net(char *buf, void *value)
{
__u32 *net = (__u32 *)value;
*net = libcfs_str2net(buf);
CDEBUG(D_INFO, "Net %s\n", libcfs_net2str(*net));
return 0;
}
static int class_parse_value(char *buf, int opc, void *value, char **endh,
int quiet)
{
char *endp;
char tmp;
int rc = 0;
if (!buf)
return 1;
while (*buf == ',' || *buf == ':')
buf++;
if (*buf == ' ' || *buf == '/' || *buf == '\0')
return 1;
endp = strpbrk(buf, ",: /");
if (endp == NULL)
endp = buf + strlen(buf);
tmp = *endp;
*endp = '\0';
switch (opc) {
default:
LBUG();
case CLASS_PARSE_NID:
rc = parse_nid(buf, value, quiet);
break;
case CLASS_PARSE_NET:
rc = parse_net(buf, value);
break;
}
*endp = tmp;
if (rc != 0)
return rc;
if (endh)
*endh = endp;
return 0;
}
int class_parse_nid(char *buf, lnet_nid_t *nid, char **endh)
{
return class_parse_value(buf, CLASS_PARSE_NID, (void *)nid, endh, 0);
}
int class_parse_nid_quiet(char *buf, lnet_nid_t *nid, char **endh)
{
return class_parse_value(buf, CLASS_PARSE_NID, (void *)nid, endh, 1);
}
int class_parse_net(char *buf, __u32 *net, char **endh)
{
return class_parse_value(buf, CLASS_PARSE_NET, (void *)net, endh, 0);
}
int class_match_nid(char *buf, char *key, lnet_nid_t nid)
{
lnet_nid_t tmp;
int rc = -1;
while (class_find_param(buf, key, &buf) == 0) {
while (class_parse_nid(buf, &tmp, &buf) == 0) {
if (tmp == nid)
return 1;
}
rc = 0;
}
return rc;
}
int class_match_net(char *buf, char *key, __u32 net)
{
__u32 tmp;
int rc = -1;
while (class_find_param(buf, key, &buf) == 0) {
while (class_parse_net(buf, &tmp, &buf) == 0) {
if (tmp == net)
return 1;
}
rc = 0;
}
return rc;
}
int class_attach(struct lustre_cfg *lcfg)
{
struct obd_device *obd = NULL;
char *typename, *name, *uuid;
int rc, len;
if (!LUSTRE_CFG_BUFLEN(lcfg, 1)) {
CERROR("No type passed!\n");
return -EINVAL;
}
typename = lustre_cfg_string(lcfg, 1);
if (!LUSTRE_CFG_BUFLEN(lcfg, 0)) {
CERROR("No name passed!\n");
return -EINVAL;
}
name = lustre_cfg_string(lcfg, 0);
if (!LUSTRE_CFG_BUFLEN(lcfg, 2)) {
CERROR("No UUID passed!\n");
return -EINVAL;
}
uuid = lustre_cfg_string(lcfg, 2);
CDEBUG(D_IOCTL, "attach type %s name: %s uuid: %s\n",
MKSTR(typename), MKSTR(name), MKSTR(uuid));
obd = class_newdev(typename, name);
if (IS_ERR(obd)) {
rc = PTR_ERR(obd);
obd = NULL;
CERROR("Cannot create device %s of type %s : %d\n",
name, typename, rc);
goto out;
}
LASSERTF(obd != NULL, "Cannot get obd device %s of type %s\n",
name, typename);
LASSERTF(obd->obd_magic == OBD_DEVICE_MAGIC,
"obd %p obd_magic %08X != %08X\n",
obd, obd->obd_magic, OBD_DEVICE_MAGIC);
LASSERTF(strncmp(obd->obd_name, name, strlen(name)) == 0,
"%p obd_name %s != %s\n", obd, obd->obd_name, name);
rwlock_init(&obd->obd_pool_lock);
obd->obd_pool_limit = 0;
obd->obd_pool_slv = 0;
INIT_LIST_HEAD(&obd->obd_exports);
INIT_LIST_HEAD(&obd->obd_unlinked_exports);
INIT_LIST_HEAD(&obd->obd_delayed_exports);
INIT_LIST_HEAD(&obd->obd_exports_timed);
INIT_LIST_HEAD(&obd->obd_nid_stats);
spin_lock_init(&obd->obd_nid_lock);
spin_lock_init(&obd->obd_dev_lock);
mutex_init(&obd->obd_dev_mutex);
spin_lock_init(&obd->obd_osfs_lock);
obd->obd_osfs_age = cfs_time_shift_64(-1000);
init_rwsem(&obd->obd_observer_link_sem);
cfs_init_timer(&obd->obd_recovery_timer);
spin_lock_init(&obd->obd_recovery_task_lock);
init_waitqueue_head(&obd->obd_next_transno_waitq);
init_waitqueue_head(&obd->obd_evict_inprogress_waitq);
INIT_LIST_HEAD(&obd->obd_req_replay_queue);
INIT_LIST_HEAD(&obd->obd_lock_replay_queue);
INIT_LIST_HEAD(&obd->obd_final_req_queue);
INIT_LIST_HEAD(&obd->obd_evict_list);
llog_group_init(&obd->obd_olg, FID_SEQ_LLOG);
obd->obd_conn_inprogress = 0;
len = strlen(uuid);
if (len >= sizeof(obd->obd_uuid)) {
CERROR("uuid must be < %d bytes long\n",
(int)sizeof(obd->obd_uuid));
rc = -EINVAL;
goto out;
}
memcpy(obd->obd_uuid.uuid, uuid, len);
if (OBP(obd, attach)) {
rc = OBP(obd, attach)(obd, sizeof(*lcfg), lcfg);
if (rc) {
rc = -EINVAL;
goto out;
}
}
spin_lock(&obd->obd_dev_lock);
atomic_set(&obd->obd_refcount, 1);
spin_unlock(&obd->obd_dev_lock);
lu_ref_init(&obd->obd_reference);
lu_ref_add(&obd->obd_reference, "attach", obd);
obd->obd_attached = 1;
CDEBUG(D_IOCTL, "OBD: dev %d attached type %s with refcount %d\n",
obd->obd_minor, typename, atomic_read(&obd->obd_refcount));
return 0;
out:
if (obd != NULL) {
class_release_dev(obd);
}
return rc;
}
int class_setup(struct obd_device *obd, struct lustre_cfg *lcfg)
{
int err = 0;
struct obd_export *exp;
LASSERT(obd != NULL);
LASSERTF(obd == class_num2obd(obd->obd_minor),
"obd %p != obd_devs[%d] %p\n",
obd, obd->obd_minor, class_num2obd(obd->obd_minor));
LASSERTF(obd->obd_magic == OBD_DEVICE_MAGIC,
"obd %p obd_magic %08x != %08x\n",
obd, obd->obd_magic, OBD_DEVICE_MAGIC);
if (!obd->obd_attached) {
CERROR("Device %d not attached\n", obd->obd_minor);
return -ENODEV;
}
if (obd->obd_set_up) {
CERROR("Device %d already setup (type %s)\n",
obd->obd_minor, obd->obd_type->typ_name);
return -EEXIST;
}
spin_lock(&obd->obd_dev_lock);
if (obd->obd_starting) {
spin_unlock(&obd->obd_dev_lock);
CERROR("Device %d setup in progress (type %s)\n",
obd->obd_minor, obd->obd_type->typ_name);
return -EEXIST;
}
obd->obd_starting = 1;
obd->obd_uuid_hash = NULL;
obd->obd_nid_hash = NULL;
obd->obd_nid_stats_hash = NULL;
spin_unlock(&obd->obd_dev_lock);
obd->obd_uuid_hash = cfs_hash_create("UUID_HASH",
HASH_UUID_CUR_BITS,
HASH_UUID_MAX_BITS,
HASH_UUID_BKT_BITS, 0,
CFS_HASH_MIN_THETA,
CFS_HASH_MAX_THETA,
&uuid_hash_ops, CFS_HASH_DEFAULT);
if (!obd->obd_uuid_hash) {
err = -ENOMEM;
goto err_hash;
}
obd->obd_nid_hash = cfs_hash_create("NID_HASH",
HASH_NID_CUR_BITS,
HASH_NID_MAX_BITS,
HASH_NID_BKT_BITS, 0,
CFS_HASH_MIN_THETA,
CFS_HASH_MAX_THETA,
&nid_hash_ops, CFS_HASH_DEFAULT);
if (!obd->obd_nid_hash) {
err = -ENOMEM;
goto err_hash;
}
obd->obd_nid_stats_hash = cfs_hash_create("NID_STATS",
HASH_NID_STATS_CUR_BITS,
HASH_NID_STATS_MAX_BITS,
HASH_NID_STATS_BKT_BITS, 0,
CFS_HASH_MIN_THETA,
CFS_HASH_MAX_THETA,
&nid_stat_hash_ops, CFS_HASH_DEFAULT);
if (!obd->obd_nid_stats_hash) {
err = -ENOMEM;
goto err_hash;
}
exp = class_new_export(obd, &obd->obd_uuid);
if (IS_ERR(exp)) {
err = PTR_ERR(exp);
goto err_hash;
}
obd->obd_self_export = exp;
list_del_init(&exp->exp_obd_chain_timed);
class_export_put(exp);
err = obd_setup(obd, lcfg);
if (err)
goto err_exp;
obd->obd_set_up = 1;
spin_lock(&obd->obd_dev_lock);
class_incref(obd, "setup", obd);
spin_unlock(&obd->obd_dev_lock);
CDEBUG(D_IOCTL, "finished setup of obd %s (uuid %s)\n",
obd->obd_name, obd->obd_uuid.uuid);
return 0;
err_exp:
if (obd->obd_self_export) {
class_unlink_export(obd->obd_self_export);
obd->obd_self_export = NULL;
}
err_hash:
if (obd->obd_uuid_hash) {
cfs_hash_putref(obd->obd_uuid_hash);
obd->obd_uuid_hash = NULL;
}
if (obd->obd_nid_hash) {
cfs_hash_putref(obd->obd_nid_hash);
obd->obd_nid_hash = NULL;
}
if (obd->obd_nid_stats_hash) {
cfs_hash_putref(obd->obd_nid_stats_hash);
obd->obd_nid_stats_hash = NULL;
}
obd->obd_starting = 0;
CERROR("setup %s failed (%d)\n", obd->obd_name, err);
return err;
}
int class_detach(struct obd_device *obd, struct lustre_cfg *lcfg)
{
if (obd->obd_set_up) {
CERROR("OBD device %d still set up\n", obd->obd_minor);
return -EBUSY;
}
spin_lock(&obd->obd_dev_lock);
if (!obd->obd_attached) {
spin_unlock(&obd->obd_dev_lock);
CERROR("OBD device %d not attached\n", obd->obd_minor);
return -ENODEV;
}
obd->obd_attached = 0;
spin_unlock(&obd->obd_dev_lock);
CDEBUG(D_IOCTL, "detach on obd %s (uuid %s)\n",
obd->obd_name, obd->obd_uuid.uuid);
class_decref(obd, "attach", obd);
return 0;
}
int class_cleanup(struct obd_device *obd, struct lustre_cfg *lcfg)
{
int err = 0;
char *flag;
OBD_RACE(OBD_FAIL_LDLM_RECOV_CLIENTS);
if (!obd->obd_set_up) {
CERROR("Device %d not setup\n", obd->obd_minor);
return -ENODEV;
}
spin_lock(&obd->obd_dev_lock);
if (obd->obd_stopping) {
spin_unlock(&obd->obd_dev_lock);
CERROR("OBD %d already stopping\n", obd->obd_minor);
return -ENODEV;
}
obd->obd_stopping = 1;
while (obd->obd_conn_inprogress > 0) {
spin_unlock(&obd->obd_dev_lock);
cond_resched();
spin_lock(&obd->obd_dev_lock);
}
spin_unlock(&obd->obd_dev_lock);
if (lcfg->lcfg_bufcount >= 2 && LUSTRE_CFG_BUFLEN(lcfg, 1) > 0) {
for (flag = lustre_cfg_string(lcfg, 1); *flag != 0; flag++)
switch (*flag) {
case 'F':
obd->obd_force = 1;
break;
case 'A':
LCONSOLE_WARN("Failing over %s\n",
obd->obd_name);
obd->obd_fail = 1;
obd->obd_no_transno = 1;
obd->obd_no_recov = 1;
if (OBP(obd, iocontrol)) {
obd_iocontrol(OBD_IOC_SYNC,
obd->obd_self_export,
0, NULL, NULL);
}
break;
default:
CERROR("Unrecognised flag '%c'\n", *flag);
}
}
LASSERT(obd->obd_self_export);
if (atomic_read(&obd->obd_refcount) > 3) {
CDEBUG(D_IOCTL, "%s: forcing exports to disconnect: %d\n",
obd->obd_name, atomic_read(&obd->obd_refcount) - 3);
dump_exports(obd, 0);
class_disconnect_exports(obd);
}
err = obd_precleanup(obd, OBD_CLEANUP_EXPORTS);
if (err)
CERROR("Precleanup %s returned %d\n",
obd->obd_name, err);
if (obd->obd_uuid_hash) {
cfs_hash_putref(obd->obd_uuid_hash);
obd->obd_uuid_hash = NULL;
}
if (obd->obd_nid_hash) {
cfs_hash_putref(obd->obd_nid_hash);
obd->obd_nid_hash = NULL;
}
if (obd->obd_nid_stats_hash) {
cfs_hash_putref(obd->obd_nid_stats_hash);
obd->obd_nid_stats_hash = NULL;
}
class_decref(obd, "setup", obd);
obd->obd_set_up = 0;
return 0;
}
struct obd_device *class_incref(struct obd_device *obd,
const char *scope, const void *source)
{
lu_ref_add_atomic(&obd->obd_reference, scope, source);
atomic_inc(&obd->obd_refcount);
CDEBUG(D_INFO, "incref %s (%p) now %d\n", obd->obd_name, obd,
atomic_read(&obd->obd_refcount));
return obd;
}
void class_decref(struct obd_device *obd, const char *scope, const void *source)
{
int err;
int refs;
spin_lock(&obd->obd_dev_lock);
atomic_dec(&obd->obd_refcount);
refs = atomic_read(&obd->obd_refcount);
spin_unlock(&obd->obd_dev_lock);
lu_ref_del(&obd->obd_reference, scope, source);
CDEBUG(D_INFO, "Decref %s (%p) now %d\n", obd->obd_name, obd, refs);
if ((refs == 1) && obd->obd_stopping) {
spin_lock(&obd->obd_self_export->exp_lock);
obd->obd_self_export->exp_flags |= exp_flags_from_obd(obd);
spin_unlock(&obd->obd_self_export->exp_lock);
class_unlink_export(obd->obd_self_export);
return;
}
if (refs == 0) {
CDEBUG(D_CONFIG, "finishing cleanup of obd %s (%s)\n",
obd->obd_name, obd->obd_uuid.uuid);
LASSERT(!obd->obd_attached);
if (obd->obd_stopping) {
err = obd_cleanup(obd);
if (err)
CERROR("Cleanup %s returned %d\n",
obd->obd_name, err);
}
if (OBP(obd, detach)) {
err = OBP(obd, detach)(obd);
if (err)
CERROR("Detach returned %d\n", err);
}
class_release_dev(obd);
}
}
int class_add_conn(struct obd_device *obd, struct lustre_cfg *lcfg)
{
struct obd_import *imp;
struct obd_uuid uuid;
int rc;
if (LUSTRE_CFG_BUFLEN(lcfg, 1) < 1 ||
LUSTRE_CFG_BUFLEN(lcfg, 1) > sizeof(struct obd_uuid)) {
CERROR("invalid conn_uuid\n");
return -EINVAL;
}
if (strcmp(obd->obd_type->typ_name, LUSTRE_MDC_NAME) &&
strcmp(obd->obd_type->typ_name, LUSTRE_OSC_NAME) &&
strcmp(obd->obd_type->typ_name, LUSTRE_OSP_NAME) &&
strcmp(obd->obd_type->typ_name, LUSTRE_LWP_NAME) &&
strcmp(obd->obd_type->typ_name, LUSTRE_MGC_NAME)) {
CERROR("can't add connection on non-client dev\n");
return -EINVAL;
}
imp = obd->u.cli.cl_import;
if (!imp) {
CERROR("try to add conn on immature client dev\n");
return -EINVAL;
}
obd_str2uuid(&uuid, lustre_cfg_string(lcfg, 1));
rc = obd_add_conn(imp, &uuid, lcfg->lcfg_num);
return rc;
}
int class_del_conn(struct obd_device *obd, struct lustre_cfg *lcfg)
{
struct obd_import *imp;
struct obd_uuid uuid;
int rc;
if (LUSTRE_CFG_BUFLEN(lcfg, 1) < 1 ||
LUSTRE_CFG_BUFLEN(lcfg, 1) > sizeof(struct obd_uuid)) {
CERROR("invalid conn_uuid\n");
return -EINVAL;
}
if (strcmp(obd->obd_type->typ_name, LUSTRE_MDC_NAME) &&
strcmp(obd->obd_type->typ_name, LUSTRE_OSC_NAME)) {
CERROR("can't del connection on non-client dev\n");
return -EINVAL;
}
imp = obd->u.cli.cl_import;
if (!imp) {
CERROR("try to del conn on immature client dev\n");
return -EINVAL;
}
obd_str2uuid(&uuid, lustre_cfg_string(lcfg, 1));
rc = obd_del_conn(imp, &uuid);
return rc;
}
struct lustre_profile *class_get_profile(const char *prof)
{
struct lustre_profile *lprof;
list_for_each_entry(lprof, &lustre_profile_list, lp_list) {
if (!strcmp(lprof->lp_profile, prof)) {
return lprof;
}
}
return NULL;
}
int class_add_profile(int proflen, char *prof, int osclen, char *osc,
int mdclen, char *mdc)
{
struct lustre_profile *lprof;
int err = 0;
CDEBUG(D_CONFIG, "Add profile %s\n", prof);
OBD_ALLOC(lprof, sizeof(*lprof));
if (lprof == NULL)
return -ENOMEM;
INIT_LIST_HEAD(&lprof->lp_list);
LASSERT(proflen == (strlen(prof) + 1));
OBD_ALLOC(lprof->lp_profile, proflen);
if (lprof->lp_profile == NULL) {
err = -ENOMEM;
goto out;
}
memcpy(lprof->lp_profile, prof, proflen);
LASSERT(osclen == (strlen(osc) + 1));
OBD_ALLOC(lprof->lp_dt, osclen);
if (lprof->lp_dt == NULL) {
err = -ENOMEM;
goto out;
}
memcpy(lprof->lp_dt, osc, osclen);
if (mdclen > 0) {
LASSERT(mdclen == (strlen(mdc) + 1));
OBD_ALLOC(lprof->lp_md, mdclen);
if (lprof->lp_md == NULL) {
err = -ENOMEM;
goto out;
}
memcpy(lprof->lp_md, mdc, mdclen);
}
list_add(&lprof->lp_list, &lustre_profile_list);
return err;
out:
if (lprof->lp_md)
OBD_FREE(lprof->lp_md, mdclen);
if (lprof->lp_dt)
OBD_FREE(lprof->lp_dt, osclen);
if (lprof->lp_profile)
OBD_FREE(lprof->lp_profile, proflen);
OBD_FREE(lprof, sizeof(*lprof));
return err;
}
void class_del_profile(const char *prof)
{
struct lustre_profile *lprof;
CDEBUG(D_CONFIG, "Del profile %s\n", prof);
lprof = class_get_profile(prof);
if (lprof) {
list_del(&lprof->lp_list);
OBD_FREE(lprof->lp_profile, strlen(lprof->lp_profile) + 1);
OBD_FREE(lprof->lp_dt, strlen(lprof->lp_dt) + 1);
if (lprof->lp_md)
OBD_FREE(lprof->lp_md, strlen(lprof->lp_md) + 1);
OBD_FREE(lprof, sizeof(*lprof));
}
}
void class_del_profiles(void)
{
struct lustre_profile *lprof, *n;
list_for_each_entry_safe(lprof, n, &lustre_profile_list, lp_list) {
list_del(&lprof->lp_list);
OBD_FREE(lprof->lp_profile, strlen(lprof->lp_profile) + 1);
OBD_FREE(lprof->lp_dt, strlen(lprof->lp_dt) + 1);
if (lprof->lp_md)
OBD_FREE(lprof->lp_md, strlen(lprof->lp_md) + 1);
OBD_FREE(lprof, sizeof(*lprof));
}
}
static int class_set_global(char *ptr, int val, struct lustre_cfg *lcfg)
{
if (class_match_param(ptr, PARAM_AT_MIN, NULL) == 0)
at_min = val;
else if (class_match_param(ptr, PARAM_AT_MAX, NULL) == 0)
at_max = val;
else if (class_match_param(ptr, PARAM_AT_EXTRA, NULL) == 0)
at_extra = val;
else if (class_match_param(ptr, PARAM_AT_EARLY_MARGIN, NULL) == 0)
at_early_margin = val;
else if (class_match_param(ptr, PARAM_AT_HISTORY, NULL) == 0)
at_history = val;
else if (class_match_param(ptr, PARAM_JOBID_VAR, NULL) == 0)
strlcpy(obd_jobid_var, lustre_cfg_string(lcfg, 2),
JOBSTATS_JOBID_VAR_MAX_LEN + 1);
else
return -EINVAL;
CDEBUG(D_IOCTL, "global %s = %d\n", ptr, val);
return 0;
}
void lustre_register_client_process_config(int (*cpc)(struct lustre_cfg *lcfg))
{
client_process_config = cpc;
}
struct lustre_cfg *lustre_cfg_rename(struct lustre_cfg *cfg,
const char *new_name)
{
struct lustre_cfg_bufs *bufs = NULL;
struct lustre_cfg *new_cfg = NULL;
char *param = NULL;
char *new_param = NULL;
char *value = NULL;
int name_len = 0;
int new_len = 0;
if (cfg == NULL || new_name == NULL)
return ERR_PTR(-EINVAL);
param = lustre_cfg_string(cfg, 1);
if (param == NULL)
return ERR_PTR(-EINVAL);
value = strchr(param, '=');
if (value == NULL)
name_len = strlen(param);
else
name_len = value - param;
new_len = LUSTRE_CFG_BUFLEN(cfg, 1) + strlen(new_name) - name_len;
OBD_ALLOC(new_param, new_len);
if (new_param == NULL)
return ERR_PTR(-ENOMEM);
strcpy(new_param, new_name);
if (value != NULL)
strcat(new_param, value);
OBD_ALLOC_PTR(bufs);
if (bufs == NULL) {
OBD_FREE(new_param, new_len);
return ERR_PTR(-ENOMEM);
}
lustre_cfg_bufs_reset(bufs, NULL);
lustre_cfg_bufs_init(bufs, cfg);
lustre_cfg_bufs_set_string(bufs, 1, new_param);
new_cfg = lustre_cfg_new(cfg->lcfg_command, bufs);
OBD_FREE(new_param, new_len);
OBD_FREE_PTR(bufs);
if (new_cfg == NULL)
return ERR_PTR(-ENOMEM);
new_cfg->lcfg_num = cfg->lcfg_num;
new_cfg->lcfg_flags = cfg->lcfg_flags;
new_cfg->lcfg_nid = cfg->lcfg_nid;
new_cfg->lcfg_nal = cfg->lcfg_nal;
return new_cfg;
}
static int process_param2_config(struct lustre_cfg *lcfg)
{
char *param = lustre_cfg_string(lcfg, 1);
char *upcall = lustre_cfg_string(lcfg, 2);
char *argv[] = {
[0] = "/usr/sbin/lctl",
[1] = "set_param",
[2] = param,
[3] = NULL
};
struct timeval start;
struct timeval end;
int rc;
if (strcmp(upcall, LCTL_UPCALL) != 0) {
CERROR("Unsupported upcall %s\n", upcall);
return -EINVAL;
}
do_gettimeofday(&start);
rc = call_usermodehelper(argv[0], argv, NULL, 1);
do_gettimeofday(&end);
if (rc < 0) {
CERROR(
"lctl: error invoking upcall %s %s %s: rc = %d; time %ldus\n",
argv[0], argv[1], argv[2], rc,
cfs_timeval_sub(&end, &start, NULL));
} else {
CDEBUG(D_HA, "lctl: invoked upcall %s %s %s, time %ldus\n",
argv[0], argv[1], argv[2],
cfs_timeval_sub(&end, &start, NULL));
rc = 0;
}
return rc;
}
void lustre_register_quota_process_config(int (*qpc)(struct lustre_cfg *lcfg))
{
quota_process_config = qpc;
}
int class_process_config(struct lustre_cfg *lcfg)
{
struct obd_device *obd;
int err;
LASSERT(lcfg && !IS_ERR(lcfg));
CDEBUG(D_IOCTL, "processing cmd: %x\n", lcfg->lcfg_command);
switch (lcfg->lcfg_command) {
case LCFG_ATTACH: {
err = class_attach(lcfg);
goto out;
}
case LCFG_ADD_UUID: {
CDEBUG(D_IOCTL, "adding mapping from uuid %s to nid %#llx (%s)\n",
lustre_cfg_string(lcfg, 1), lcfg->lcfg_nid,
libcfs_nid2str(lcfg->lcfg_nid));
err = class_add_uuid(lustre_cfg_string(lcfg, 1), lcfg->lcfg_nid);
goto out;
}
case LCFG_DEL_UUID: {
CDEBUG(D_IOCTL, "removing mappings for uuid %s\n",
(lcfg->lcfg_bufcount < 2 || LUSTRE_CFG_BUFLEN(lcfg, 1) == 0)
? "<all uuids>" : lustre_cfg_string(lcfg, 1));
err = class_del_uuid(lustre_cfg_string(lcfg, 1));
goto out;
}
case LCFG_MOUNTOPT: {
CDEBUG(D_IOCTL, "mountopt: profile %s osc %s mdc %s\n",
lustre_cfg_string(lcfg, 1),
lustre_cfg_string(lcfg, 2),
lustre_cfg_string(lcfg, 3));
err = class_add_profile(LUSTRE_CFG_BUFLEN(lcfg, 1),
lustre_cfg_string(lcfg, 1),
LUSTRE_CFG_BUFLEN(lcfg, 2),
lustre_cfg_string(lcfg, 2),
LUSTRE_CFG_BUFLEN(lcfg, 3),
lustre_cfg_string(lcfg, 3));
goto out;
}
case LCFG_DEL_MOUNTOPT: {
CDEBUG(D_IOCTL, "mountopt: profile %s\n",
lustre_cfg_string(lcfg, 1));
class_del_profile(lustre_cfg_string(lcfg, 1));
err = 0;
goto out;
}
case LCFG_SET_TIMEOUT: {
CDEBUG(D_IOCTL, "changing lustre timeout from %d to %d\n",
obd_timeout, lcfg->lcfg_num);
obd_timeout = max(lcfg->lcfg_num, 1U);
obd_timeout_set = 1;
err = 0;
goto out;
}
case LCFG_SET_LDLM_TIMEOUT: {
CDEBUG(D_IOCTL, "changing lustre ldlm_timeout from %d to %d\n",
ldlm_timeout, lcfg->lcfg_num);
ldlm_timeout = max(lcfg->lcfg_num, 1U);
if (ldlm_timeout >= obd_timeout)
ldlm_timeout = max(obd_timeout / 3, 1U);
ldlm_timeout_set = 1;
err = 0;
goto out;
}
case LCFG_SET_UPCALL: {
LCONSOLE_ERROR_MSG(0x15a, "recovery upcall is deprecated\n");
err = 0;
goto out;
}
case LCFG_MARKER: {
struct cfg_marker *marker;
marker = lustre_cfg_buf(lcfg, 1);
CDEBUG(D_IOCTL, "marker %d (%#x) %.16s %s\n", marker->cm_step,
marker->cm_flags, marker->cm_tgtname, marker->cm_comment);
err = 0;
goto out;
}
case LCFG_PARAM: {
char *tmp;
if ((class_match_param(lustre_cfg_string(lcfg, 1),
PARAM_LLITE, NULL) == 0) &&
client_process_config) {
err = (*client_process_config)(lcfg);
goto out;
} else if ((class_match_param(lustre_cfg_string(lcfg, 1),
PARAM_SYS, &tmp) == 0)) {
err = class_set_global(tmp, lcfg->lcfg_num, lcfg);
if (err != 0)
CWARN("Ignoring unknown param %s\n", tmp);
err = 0;
goto out;
} else if ((class_match_param(lustre_cfg_string(lcfg, 1),
PARAM_QUOTA, &tmp) == 0) &&
quota_process_config) {
err = (*quota_process_config)(lcfg);
goto out;
}
break;
}
case LCFG_SET_PARAM: {
err = process_param2_config(lcfg);
goto out;
}
}
obd = class_name2obd(lustre_cfg_string(lcfg, 0));
if (obd == NULL) {
if (!LUSTRE_CFG_BUFLEN(lcfg, 0))
CERROR("this lcfg command requires a device name\n");
else
CERROR("no device for: %s\n",
lustre_cfg_string(lcfg, 0));
err = -EINVAL;
goto out;
}
switch (lcfg->lcfg_command) {
case LCFG_SETUP: {
err = class_setup(obd, lcfg);
goto out;
}
case LCFG_DETACH: {
err = class_detach(obd, lcfg);
err = 0;
goto out;
}
case LCFG_CLEANUP: {
err = class_cleanup(obd, lcfg);
err = 0;
goto out;
}
case LCFG_ADD_CONN: {
err = class_add_conn(obd, lcfg);
err = 0;
goto out;
}
case LCFG_DEL_CONN: {
err = class_del_conn(obd, lcfg);
err = 0;
goto out;
}
case LCFG_POOL_NEW: {
err = obd_pool_new(obd, lustre_cfg_string(lcfg, 2));
err = 0;
goto out;
}
case LCFG_POOL_ADD: {
err = obd_pool_add(obd, lustre_cfg_string(lcfg, 2),
lustre_cfg_string(lcfg, 3));
err = 0;
goto out;
}
case LCFG_POOL_REM: {
err = obd_pool_rem(obd, lustre_cfg_string(lcfg, 2),
lustre_cfg_string(lcfg, 3));
err = 0;
goto out;
}
case LCFG_POOL_DEL: {
err = obd_pool_del(obd, lustre_cfg_string(lcfg, 2));
err = 0;
goto out;
}
default: {
err = obd_process_config(obd, sizeof(*lcfg), lcfg);
goto out;
}
}
out:
if ((err < 0) && !(lcfg->lcfg_command & LCFG_REQUIRED)) {
CWARN("Ignoring error %d on optional command %#x\n", err,
lcfg->lcfg_command);
err = 0;
}
return err;
}
int class_process_proc_param(char *prefix, struct lprocfs_vars *lvars,
struct lustre_cfg *lcfg, void *data)
{
struct lprocfs_vars *var;
struct file fakefile;
struct seq_file fake_seqfile;
char *key, *sval;
int i, keylen, vallen;
int matched = 0, j = 0;
int rc = 0;
int skip = 0;
if (lcfg->lcfg_command != LCFG_PARAM) {
CERROR("Unknown command: %d\n", lcfg->lcfg_command);
return -EINVAL;
}
fakefile.private_data = &fake_seqfile;
fake_seqfile.private = data;
for (i = 1; i < lcfg->lcfg_bufcount; i++) {
key = lustre_cfg_buf(lcfg, i);
class_match_param(key, prefix, &key);
sval = strchr(key, '=');
if (!sval || (*(sval + 1) == 0)) {
CERROR("Can't parse param %s (missing '=')\n", key);
continue;
}
keylen = sval - key;
sval++;
vallen = strlen(sval);
matched = 0;
j = 0;
while (lvars[j].name) {
var = &lvars[j];
if (class_match_param(key, (char *)var->name, NULL) == 0
&& keylen == strlen(var->name)) {
matched++;
rc = -EROFS;
if (var->fops && var->fops->write) {
mm_segment_t oldfs;
oldfs = get_fs();
set_fs(KERNEL_DS);
rc = (var->fops->write)(&fakefile, sval,
vallen, NULL);
set_fs(oldfs);
}
break;
}
j++;
}
if (!matched) {
if (strnchr(key, keylen, '.'))
return -ENOSYS;
CERROR("%s: unknown param %s\n",
(char *)lustre_cfg_string(lcfg, 0), key);
skip++;
} else if (rc < 0) {
CERROR("writing proc entry %s err %d\n",
var->name, rc);
rc = 0;
} else {
CDEBUG(D_CONFIG, "%s.%.*s: Set parameter %.*s=%s\n",
lustre_cfg_string(lcfg, 0),
(int)strlen(prefix) - 1, prefix,
(int)(sval - key - 1), key, sval);
}
}
if (rc > 0)
rc = 0;
if (!rc && skip)
rc = skip;
return rc;
}
int class_config_llog_handler(const struct lu_env *env,
struct llog_handle *handle,
struct llog_rec_hdr *rec, void *data)
{
struct config_llog_instance *clli = data;
int cfg_len = rec->lrh_len;
char *cfg_buf = (char *) (rec + 1);
int rc = 0;
switch (rec->lrh_type) {
case OBD_CFG_REC: {
struct lustre_cfg *lcfg, *lcfg_new;
struct lustre_cfg_bufs bufs;
char *inst_name = NULL;
int inst_len = 0;
int inst = 0, swab = 0;
lcfg = (struct lustre_cfg *)cfg_buf;
if (lcfg->lcfg_version == __swab32(LUSTRE_CFG_VERSION)) {
lustre_swab_lustre_cfg(lcfg);
swab = 1;
}
rc = lustre_cfg_sanity_check(cfg_buf, cfg_len);
if (rc)
goto out;
if (lcfg->lcfg_command == LCFG_MARKER) {
struct cfg_marker *marker = lustre_cfg_buf(lcfg, 1);
lustre_swab_cfg_marker(marker, swab,
LUSTRE_CFG_BUFLEN(lcfg, 1));
CDEBUG(D_CONFIG, "Marker, inst_flg=%#x mark_flg=%#x\n",
clli->cfg_flags, marker->cm_flags);
if (marker->cm_flags & CM_START) {
clli->cfg_flags = CFG_F_MARKER;
if (marker->cm_flags & CM_SKIP) {
clli->cfg_flags |= CFG_F_SKIP;
CDEBUG(D_CONFIG, "SKIP #%d\n",
marker->cm_step);
} else if ((marker->cm_flags & CM_EXCLUDE) ||
(clli->cfg_sb &&
lustre_check_exclusion(clli->cfg_sb,
marker->cm_tgtname))) {
clli->cfg_flags |= CFG_F_EXCLUDE;
CDEBUG(D_CONFIG, "EXCLUDE %d\n",
marker->cm_step);
}
} else if (marker->cm_flags & CM_END) {
clli->cfg_flags = 0;
}
}
if (!(clli->cfg_flags & CFG_F_COMPAT146) &&
!(clli->cfg_flags & CFG_F_MARKER) &&
(lcfg->lcfg_command != LCFG_MARKER)) {
CWARN("Config not inside markers, ignoring! (inst: %p, uuid: %s, flags: %#x)\n",
clli->cfg_instance,
clli->cfg_uuid.uuid, clli->cfg_flags);
clli->cfg_flags |= CFG_F_SKIP;
}
if (clli->cfg_flags & CFG_F_SKIP) {
CDEBUG(D_CONFIG, "skipping %#x\n",
clli->cfg_flags);
rc = 0;
break;
}
{
char *typename = lustre_cfg_string(lcfg, 1);
char *index = lustre_cfg_string(lcfg, 2);
if ((lcfg->lcfg_command == LCFG_ATTACH && typename &&
strcmp(typename, "mds") == 0)) {
CWARN("For 1.8 interoperability, rename obd type from mds to mdt\n");
typename[2] = 't';
}
if ((lcfg->lcfg_command == LCFG_SETUP && index &&
strcmp(index, "type") == 0)) {
CDEBUG(D_INFO, "For 1.8 interoperability, set this index to '0'\n");
index[0] = '0';
index[1] = 0;
}
}
if (clli->cfg_flags & CFG_F_EXCLUDE) {
CDEBUG(D_CONFIG, "cmd: %x marked EXCLUDED\n",
lcfg->lcfg_command);
if (lcfg->lcfg_command == LCFG_LOV_ADD_OBD)
lcfg->lcfg_command = LCFG_LOV_ADD_INA;
}
lustre_cfg_bufs_init(&bufs, lcfg);
if (clli && clli->cfg_instance &&
LUSTRE_CFG_BUFLEN(lcfg, 0) > 0){
inst = 1;
inst_len = LUSTRE_CFG_BUFLEN(lcfg, 0) +
sizeof(clli->cfg_instance) * 2 + 4;
OBD_ALLOC(inst_name, inst_len);
if (inst_name == NULL) {
rc = -ENOMEM;
goto out;
}
sprintf(inst_name, "%s-%p",
lustre_cfg_string(lcfg, 0),
clli->cfg_instance);
lustre_cfg_bufs_set_string(&bufs, 0, inst_name);
CDEBUG(D_CONFIG, "cmd %x, instance name: %s\n",
lcfg->lcfg_command, inst_name);
}
if (clli && clli->cfg_instance != NULL &&
lcfg->lcfg_command == LCFG_ATTACH) {
lustre_cfg_bufs_set_string(&bufs, 2,
clli->cfg_uuid.uuid);
}
if (clli && clli->cfg_instance == NULL &&
lcfg->lcfg_command == LCFG_SPTLRPC_CONF) {
lustre_cfg_bufs_set(&bufs, 2, bufs.lcfg_buf[1],
bufs.lcfg_buflen[1]);
lustre_cfg_bufs_set(&bufs, 1, bufs.lcfg_buf[0],
bufs.lcfg_buflen[0]);
lustre_cfg_bufs_set_string(&bufs, 0,
clli->cfg_obdname);
}
lcfg_new = lustre_cfg_new(lcfg->lcfg_command, &bufs);
lcfg_new->lcfg_num = lcfg->lcfg_num;
lcfg_new->lcfg_flags = lcfg->lcfg_flags;
if (lcfg->lcfg_nal != 0 &&
(lcfg->lcfg_nid >> 32) == 0) {
__u32 addr = (__u32)(lcfg->lcfg_nid & 0xffffffff);
lcfg_new->lcfg_nid =
LNET_MKNID(LNET_MKNET(lcfg->lcfg_nal, 0), addr);
CWARN("Converted pre-newconfig NAL %d NID %x to %s\n",
lcfg->lcfg_nal, addr,
libcfs_nid2str(lcfg_new->lcfg_nid));
} else {
lcfg_new->lcfg_nid = lcfg->lcfg_nid;
}
lcfg_new->lcfg_nal = 0;
rc = class_process_config(lcfg_new);
lustre_cfg_free(lcfg_new);
if (inst)
OBD_FREE(inst_name, inst_len);
break;
}
default:
CERROR("Unknown llog record type %#x encountered\n",
rec->lrh_type);
break;
}
out:
if (rc) {
CERROR("%s: cfg command failed: rc = %d\n",
handle->lgh_ctxt->loc_obd->obd_name, rc);
class_config_dump_handler(NULL, handle, rec, data);
}
return rc;
}
int class_config_parse_llog(const struct lu_env *env, struct llog_ctxt *ctxt,
char *name, struct config_llog_instance *cfg)
{
struct llog_process_cat_data cd = {0, 0};
struct llog_handle *llh;
llog_cb_t callback;
int rc;
CDEBUG(D_INFO, "looking up llog %s\n", name);
rc = llog_open(env, ctxt, &llh, NULL, name, LLOG_OPEN_EXISTS);
if (rc)
return rc;
rc = llog_init_handle(env, llh, LLOG_F_IS_PLAIN, NULL);
if (rc)
goto parse_out;
if (cfg) {
cd.lpcd_first_idx = cfg->cfg_last_idx;
callback = cfg->cfg_callback;
LASSERT(callback != NULL);
} else {
callback = class_config_llog_handler;
}
cd.lpcd_last_idx = 0;
rc = llog_process(env, llh, callback, cfg, &cd);
CDEBUG(D_CONFIG, "Processed log %s gen %d-%d (rc=%d)\n", name,
cd.lpcd_first_idx + 1, cd.lpcd_last_idx, rc);
if (cfg)
cfg->cfg_last_idx = cd.lpcd_last_idx;
parse_out:
llog_close(env, llh);
return rc;
}
int class_config_parse_rec(struct llog_rec_hdr *rec, char *buf, int size)
{
struct lustre_cfg *lcfg = (struct lustre_cfg *)(rec + 1);
char *ptr = buf;
char *end = buf + size;
int rc = 0;
LASSERT(rec->lrh_type == OBD_CFG_REC);
rc = lustre_cfg_sanity_check(lcfg, rec->lrh_len);
if (rc < 0)
return rc;
ptr += snprintf(ptr, end-ptr, "cmd=%05x ", lcfg->lcfg_command);
if (lcfg->lcfg_flags)
ptr += snprintf(ptr, end-ptr, "flags=%#08x ",
lcfg->lcfg_flags);
if (lcfg->lcfg_num)
ptr += snprintf(ptr, end-ptr, "num=%#08x ", lcfg->lcfg_num);
if (lcfg->lcfg_nid)
ptr += snprintf(ptr, end-ptr, "nid=%s(%#llx)\n ",
libcfs_nid2str(lcfg->lcfg_nid),
lcfg->lcfg_nid);
if (lcfg->lcfg_command == LCFG_MARKER) {
struct cfg_marker *marker = lustre_cfg_buf(lcfg, 1);
ptr += snprintf(ptr, end-ptr, "marker=%d(%#x)%s '%s'",
marker->cm_step, marker->cm_flags,
marker->cm_tgtname, marker->cm_comment);
} else {
int i;
for (i = 0; i < lcfg->lcfg_bufcount; i++) {
ptr += snprintf(ptr, end-ptr, "%d:%s ", i,
lustre_cfg_string(lcfg, i));
}
}
rc = ptr - buf;
return rc;
}
int class_config_dump_handler(const struct lu_env *env,
struct llog_handle *handle,
struct llog_rec_hdr *rec, void *data)
{
char *outstr;
int rc = 0;
OBD_ALLOC(outstr, 256);
if (outstr == NULL)
return -ENOMEM;
if (rec->lrh_type == OBD_CFG_REC) {
class_config_parse_rec(rec, outstr, 256);
LCONSOLE(D_WARNING, " %s\n", outstr);
} else {
LCONSOLE(D_WARNING, "unhandled lrh_type: %#x\n", rec->lrh_type);
rc = -EINVAL;
}
OBD_FREE(outstr, 256);
return rc;
}
int class_config_dump_llog(const struct lu_env *env, struct llog_ctxt *ctxt,
char *name, struct config_llog_instance *cfg)
{
struct llog_handle *llh;
int rc;
LCONSOLE_INFO("Dumping config log %s\n", name);
rc = llog_open(env, ctxt, &llh, NULL, name, LLOG_OPEN_EXISTS);
if (rc)
return rc;
rc = llog_init_handle(env, llh, LLOG_F_IS_PLAIN, NULL);
if (rc)
goto parse_out;
rc = llog_process(env, llh, class_config_dump_handler, cfg, NULL);
parse_out:
llog_close(env, llh);
LCONSOLE_INFO("End config log %s\n", name);
return rc;
}
int class_manual_cleanup(struct obd_device *obd)
{
char flags[3] = "";
struct lustre_cfg *lcfg;
struct lustre_cfg_bufs bufs;
int rc;
if (!obd) {
CERROR("empty cleanup\n");
return -EALREADY;
}
if (obd->obd_force)
strcat(flags, "F");
if (obd->obd_fail)
strcat(flags, "A");
CDEBUG(D_CONFIG, "Manual cleanup of %s (flags='%s')\n",
obd->obd_name, flags);
lustre_cfg_bufs_reset(&bufs, obd->obd_name);
lustre_cfg_bufs_set_string(&bufs, 1, flags);
lcfg = lustre_cfg_new(LCFG_CLEANUP, &bufs);
if (!lcfg)
return -ENOMEM;
rc = class_process_config(lcfg);
if (rc) {
CERROR("cleanup failed %d: %s\n", rc, obd->obd_name);
goto out;
}
lcfg->lcfg_command = LCFG_DETACH;
rc = class_process_config(lcfg);
if (rc)
CERROR("detach failed %d: %s\n", rc, obd->obd_name);
out:
lustre_cfg_free(lcfg);
return rc;
}
static unsigned
uuid_hash(struct cfs_hash *hs, const void *key, unsigned mask)
{
return cfs_hash_djb2_hash(((struct obd_uuid *)key)->uuid,
sizeof(((struct obd_uuid *)key)->uuid), mask);
}
static void *
uuid_key(struct hlist_node *hnode)
{
struct obd_export *exp;
exp = hlist_entry(hnode, struct obd_export, exp_uuid_hash);
return &exp->exp_client_uuid;
}
static int
uuid_keycmp(const void *key, struct hlist_node *hnode)
{
struct obd_export *exp;
LASSERT(key);
exp = hlist_entry(hnode, struct obd_export, exp_uuid_hash);
return obd_uuid_equals(key, &exp->exp_client_uuid) &&
!exp->exp_failed;
}
static void *
uuid_export_object(struct hlist_node *hnode)
{
return hlist_entry(hnode, struct obd_export, exp_uuid_hash);
}
static void
uuid_export_get(struct cfs_hash *hs, struct hlist_node *hnode)
{
struct obd_export *exp;
exp = hlist_entry(hnode, struct obd_export, exp_uuid_hash);
class_export_get(exp);
}
static void
uuid_export_put_locked(struct cfs_hash *hs, struct hlist_node *hnode)
{
struct obd_export *exp;
exp = hlist_entry(hnode, struct obd_export, exp_uuid_hash);
class_export_put(exp);
}
static unsigned
nid_hash(struct cfs_hash *hs, const void *key, unsigned mask)
{
return cfs_hash_djb2_hash(key, sizeof(lnet_nid_t), mask);
}
static void *
nid_key(struct hlist_node *hnode)
{
struct obd_export *exp;
exp = hlist_entry(hnode, struct obd_export, exp_nid_hash);
return &exp->exp_connection->c_peer.nid;
}
static int
nid_kepcmp(const void *key, struct hlist_node *hnode)
{
struct obd_export *exp;
LASSERT(key);
exp = hlist_entry(hnode, struct obd_export, exp_nid_hash);
return exp->exp_connection->c_peer.nid == *(lnet_nid_t *)key &&
!exp->exp_failed;
}
static void *
nid_export_object(struct hlist_node *hnode)
{
return hlist_entry(hnode, struct obd_export, exp_nid_hash);
}
static void
nid_export_get(struct cfs_hash *hs, struct hlist_node *hnode)
{
struct obd_export *exp;
exp = hlist_entry(hnode, struct obd_export, exp_nid_hash);
class_export_get(exp);
}
static void
nid_export_put_locked(struct cfs_hash *hs, struct hlist_node *hnode)
{
struct obd_export *exp;
exp = hlist_entry(hnode, struct obd_export, exp_nid_hash);
class_export_put(exp);
}
static void *
nidstats_key(struct hlist_node *hnode)
{
struct nid_stat *ns;
ns = hlist_entry(hnode, struct nid_stat, nid_hash);
return &ns->nid;
}
static int
nidstats_keycmp(const void *key, struct hlist_node *hnode)
{
return *(lnet_nid_t *)nidstats_key(hnode) == *(lnet_nid_t *)key;
}
static void *
nidstats_object(struct hlist_node *hnode)
{
return hlist_entry(hnode, struct nid_stat, nid_hash);
}
static void
nidstats_get(struct cfs_hash *hs, struct hlist_node *hnode)
{
struct nid_stat *ns;
ns = hlist_entry(hnode, struct nid_stat, nid_hash);
nidstat_getref(ns);
}
static void
nidstats_put_locked(struct cfs_hash *hs, struct hlist_node *hnode)
{
struct nid_stat *ns;
ns = hlist_entry(hnode, struct nid_stat, nid_hash);
nidstat_putref(ns);
}
