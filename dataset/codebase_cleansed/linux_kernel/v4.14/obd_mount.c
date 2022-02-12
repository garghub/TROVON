int lustre_process_log(struct super_block *sb, char *logname,
struct config_llog_instance *cfg)
{
struct lustre_cfg *lcfg;
struct lustre_cfg_bufs *bufs;
struct lustre_sb_info *lsi = s2lsi(sb);
struct obd_device *mgc = lsi->lsi_mgc;
int rc;
LASSERT(mgc);
LASSERT(cfg);
bufs = kzalloc(sizeof(*bufs), GFP_NOFS);
if (!bufs)
return -ENOMEM;
lustre_cfg_bufs_reset(bufs, mgc->obd_name);
lustre_cfg_bufs_set_string(bufs, 1, logname);
lustre_cfg_bufs_set(bufs, 2, cfg, sizeof(*cfg));
lustre_cfg_bufs_set(bufs, 3, &sb, sizeof(sb));
lcfg = kzalloc(lustre_cfg_len(bufs->lcfg_bufcount, bufs->lcfg_buflen),
GFP_NOFS);
if (!lcfg) {
rc = -ENOMEM;
goto out;
}
lustre_cfg_init(lcfg, LCFG_LOG_START, bufs);
rc = obd_process_config(mgc, sizeof(*lcfg), lcfg);
kfree(lcfg);
out:
kfree(bufs);
if (rc == -EINVAL)
LCONSOLE_ERROR_MSG(0x15b, "%s: The configuration from log '%s' failed from the MGS (%d). Make sure this client and the MGS are running compatible versions of Lustre.\n",
mgc->obd_name, logname, rc);
else if (rc)
LCONSOLE_ERROR_MSG(0x15c, "%s: The configuration from log '%s' failed (%d). This may be the result of communication errors between this node and the MGS, a bad configuration, or other errors. See the syslog for more information.\n",
mgc->obd_name, logname,
rc);
return rc;
}
int lustre_end_log(struct super_block *sb, char *logname,
struct config_llog_instance *cfg)
{
struct lustre_cfg *lcfg;
struct lustre_cfg_bufs bufs;
struct lustre_sb_info *lsi = s2lsi(sb);
struct obd_device *mgc = lsi->lsi_mgc;
int rc;
if (!mgc)
return -ENOENT;
lustre_cfg_bufs_reset(&bufs, mgc->obd_name);
lustre_cfg_bufs_set_string(&bufs, 1, logname);
if (cfg)
lustre_cfg_bufs_set(&bufs, 2, cfg, sizeof(*cfg));
lcfg = kzalloc(lustre_cfg_len(bufs.lcfg_bufcount, bufs.lcfg_buflen),
GFP_NOFS);
if (!lcfg)
return -ENOMEM;
lustre_cfg_init(lcfg, LCFG_LOG_END, &bufs);
rc = obd_process_config(mgc, sizeof(*lcfg), lcfg);
kfree(lcfg);
return rc;
}
static int do_lcfg(char *cfgname, lnet_nid_t nid, int cmd,
char *s1, char *s2, char *s3, char *s4)
{
struct lustre_cfg_bufs bufs;
struct lustre_cfg *lcfg = NULL;
int rc;
CDEBUG(D_TRACE, "lcfg %s %#x %s %s %s %s\n", cfgname,
cmd, s1, s2, s3, s4);
lustre_cfg_bufs_reset(&bufs, cfgname);
if (s1)
lustre_cfg_bufs_set_string(&bufs, 1, s1);
if (s2)
lustre_cfg_bufs_set_string(&bufs, 2, s2);
if (s3)
lustre_cfg_bufs_set_string(&bufs, 3, s3);
if (s4)
lustre_cfg_bufs_set_string(&bufs, 4, s4);
lcfg = kzalloc(lustre_cfg_len(bufs.lcfg_bufcount, bufs.lcfg_buflen),
GFP_NOFS);
if (!lcfg)
return -ENOMEM;
lustre_cfg_init(lcfg, cmd, &bufs);
lcfg->lcfg_nid = nid;
rc = class_process_config(lcfg);
kfree(lcfg);
return rc;
}
static int lustre_start_simple(char *obdname, char *type, char *uuid,
char *s1, char *s2, char *s3, char *s4)
{
int rc;
CDEBUG(D_MOUNT, "Starting obd %s (typ=%s)\n", obdname, type);
rc = do_lcfg(obdname, 0, LCFG_ATTACH, type, uuid, NULL, NULL);
if (rc) {
CERROR("%s attach error %d\n", obdname, rc);
return rc;
}
rc = do_lcfg(obdname, 0, LCFG_SETUP, s1, s2, s3, s4);
if (rc) {
CERROR("%s setup error %d\n", obdname, rc);
do_lcfg(obdname, 0, LCFG_DETACH, NULL, NULL, NULL, NULL);
}
return rc;
}
int lustre_start_mgc(struct super_block *sb)
{
struct obd_connect_data *data = NULL;
struct lustre_sb_info *lsi = s2lsi(sb);
struct obd_device *obd;
struct obd_export *exp;
struct obd_uuid *uuid;
class_uuid_t uuidc;
lnet_nid_t nid;
char nidstr[LNET_NIDSTR_SIZE];
char *mgcname = NULL, *niduuid = NULL, *mgssec = NULL;
char *ptr;
int rc = 0, i = 0, j;
LASSERT(lsi->lsi_lmd);
ptr = lsi->lsi_lmd->lmd_dev;
if (class_parse_nid(ptr, &nid, &ptr) == 0)
i++;
if (i == 0) {
CERROR("No valid MGS nids found.\n");
return -EINVAL;
}
mutex_lock(&mgc_start_lock);
libcfs_nid2str_r(nid, nidstr, sizeof(nidstr));
mgcname = kasprintf(GFP_NOFS,
"%s%s", LUSTRE_MGC_OBDNAME, nidstr);
niduuid = kasprintf(GFP_NOFS, "%s_%x", mgcname, i);
if (!mgcname || !niduuid) {
rc = -ENOMEM;
goto out_free;
}
mgssec = lsi->lsi_lmd->lmd_mgssec ? lsi->lsi_lmd->lmd_mgssec : "";
data = kzalloc(sizeof(*data), GFP_NOFS);
if (!data) {
rc = -ENOMEM;
goto out_free;
}
obd = class_name2obd(mgcname);
if (obd && !obd->obd_stopping) {
int recov_bk;
rc = obd_set_info_async(NULL, obd->obd_self_export,
strlen(KEY_MGSSEC), KEY_MGSSEC,
strlen(mgssec), mgssec, NULL);
if (rc)
goto out_free;
atomic_inc(&obd->u.cli.cl_mgc_refcount);
if (lmd_is_client(lsi->lsi_lmd)) {
int has_ir;
int vallen = sizeof(*data);
__u32 *flags = &lsi->lsi_lmd->lmd_flags;
rc = obd_get_info(NULL, obd->obd_self_export,
strlen(KEY_CONN_DATA), KEY_CONN_DATA,
&vallen, data);
LASSERT(rc == 0);
has_ir = OCD_HAS_FLAG(data, IMP_RECOV);
if (has_ir ^ !(*flags & LMD_FLG_NOIR)) {
LCONSOLE_WARN(
"Trying to mount a client with IR setting not compatible with current mgc. Force to use current mgc setting that is IR %s.\n",
has_ir ? "enabled" : "disabled");
if (has_ir)
*flags &= ~LMD_FLG_NOIR;
else
*flags |= LMD_FLG_NOIR;
}
}
recov_bk = 0;
recov_bk++;
CDEBUG(D_MOUNT, "%s: Set MGC reconnect %d\n", mgcname,
recov_bk);
rc = obd_set_info_async(NULL, obd->obd_self_export,
sizeof(KEY_INIT_RECOV_BACKUP),
KEY_INIT_RECOV_BACKUP,
sizeof(recov_bk), &recov_bk, NULL);
rc = 0;
goto out;
}
CDEBUG(D_MOUNT, "Start MGC '%s'\n", mgcname);
i = 0;
ptr = lsi->lsi_lmd->lmd_dev;
while (class_parse_nid(ptr, &nid, &ptr) == 0) {
rc = do_lcfg(mgcname, nid,
LCFG_ADD_UUID, niduuid, NULL, NULL, NULL);
if (!rc)
i++;
if (*ptr == ':')
break;
}
if (i == 0) {
CERROR("No valid MGS nids found.\n");
rc = -EINVAL;
goto out_free;
}
lsi->lsi_lmd->lmd_mgs_failnodes = 1;
uuid = kzalloc(sizeof(*uuid), GFP_NOFS);
if (!uuid) {
rc = -ENOMEM;
goto out_free;
}
ll_generate_random_uuid(uuidc);
class_uuid_unparse(uuidc, uuid);
rc = lustre_start_simple(mgcname, LUSTRE_MGC_NAME,
(char *)uuid->uuid, LUSTRE_MGS_OBDNAME,
niduuid, NULL, NULL);
kfree(uuid);
if (rc)
goto out_free;
i = 1;
while (ptr && ((*ptr == ':' ||
class_find_param(ptr, PARAM_MGSNODE, &ptr) == 0))) {
sprintf(niduuid, "%s_%x", mgcname, i);
j = 0;
while (class_parse_nid_quiet(ptr, &nid, &ptr) == 0) {
rc = do_lcfg(mgcname, nid, LCFG_ADD_UUID, niduuid,
NULL, NULL, NULL);
if (!rc)
++j;
if (*ptr == ':')
break;
}
if (j > 0) {
rc = do_lcfg(mgcname, 0, LCFG_ADD_CONN,
niduuid, NULL, NULL, NULL);
if (!rc)
i++;
} else {
break;
}
}
lsi->lsi_lmd->lmd_mgs_failnodes = i;
obd = class_name2obd(mgcname);
if (!obd) {
CERROR("Can't find mgcobd %s\n", mgcname);
rc = -ENOTCONN;
goto out_free;
}
rc = obd_set_info_async(NULL, obd->obd_self_export,
strlen(KEY_MGSSEC), KEY_MGSSEC,
strlen(mgssec), mgssec, NULL);
if (rc)
goto out_free;
atomic_set(&obd->u.cli.cl_mgc_refcount, 1);
data->ocd_connect_flags = OBD_CONNECT_VERSION | OBD_CONNECT_AT |
OBD_CONNECT_FULL20 | OBD_CONNECT_IMP_RECOV |
OBD_CONNECT_LVB_TYPE | OBD_CONNECT_BULK_MBITS;
#if OBD_OCD_VERSION(3, 0, 53, 0) > LUSTRE_VERSION_CODE
data->ocd_connect_flags |= OBD_CONNECT_MNE_SWAB;
#endif
if (lmd_is_client(lsi->lsi_lmd) &&
lsi->lsi_lmd->lmd_flags & LMD_FLG_NOIR)
data->ocd_connect_flags &= ~OBD_CONNECT_IMP_RECOV;
data->ocd_version = LUSTRE_VERSION_CODE;
rc = obd_connect(NULL, &exp, obd, &obd->obd_uuid, data, NULL);
if (rc) {
CERROR("connect failed %d\n", rc);
goto out;
}
obd->u.cli.cl_mgc_mgsexp = exp;
out:
lsi->lsi_mgc = obd;
out_free:
mutex_unlock(&mgc_start_lock);
kfree(data);
kfree(mgcname);
kfree(niduuid);
return rc;
}
static int lustre_stop_mgc(struct super_block *sb)
{
struct lustre_sb_info *lsi = s2lsi(sb);
struct obd_device *obd;
char *niduuid = NULL, *ptr = NULL;
int i, rc = 0, len = 0;
if (!lsi)
return -ENOENT;
obd = lsi->lsi_mgc;
if (!obd)
return -ENOENT;
lsi->lsi_mgc = NULL;
mutex_lock(&mgc_start_lock);
LASSERT(atomic_read(&obd->u.cli.cl_mgc_refcount) > 0);
if (!atomic_dec_and_test(&obd->u.cli.cl_mgc_refcount)) {
CDEBUG(D_MOUNT, "mgc still has %d references.\n",
atomic_read(&obd->u.cli.cl_mgc_refcount));
rc = -EBUSY;
goto out;
}
obd->obd_no_recov = 1;
if (obd->u.cli.cl_mgc_mgsexp) {
rc = obd_disconnect(obd->u.cli.cl_mgc_mgsexp);
if (rc)
CDEBUG(D_MOUNT, "disconnect failed %d\n", rc);
}
len = strlen(obd->obd_name) + 6;
niduuid = kzalloc(len, GFP_NOFS);
if (niduuid) {
strcpy(niduuid, obd->obd_name);
ptr = niduuid + strlen(niduuid);
}
rc = class_manual_cleanup(obd);
if (rc)
goto out;
if (!niduuid) {
rc = -ENOMEM;
goto out;
}
for (i = 0; i < lsi->lsi_lmd->lmd_mgs_failnodes; i++) {
sprintf(ptr, "_%x", i);
rc = do_lcfg(LUSTRE_MGC_OBDNAME, 0, LCFG_DEL_UUID,
niduuid, NULL, NULL, NULL);
if (rc)
CERROR("del MDC UUID %s failed: rc = %d\n",
niduuid, rc);
}
out:
kfree(niduuid);
mutex_unlock(&mgc_start_lock);
return rc;
}
static struct lustre_sb_info *lustre_init_lsi(struct super_block *sb)
{
struct lustre_sb_info *lsi;
lsi = kzalloc(sizeof(*lsi), GFP_NOFS);
if (!lsi)
return NULL;
lsi->lsi_lmd = kzalloc(sizeof(*lsi->lsi_lmd), GFP_NOFS);
if (!lsi->lsi_lmd) {
kfree(lsi);
return NULL;
}
lsi->lsi_lmd->lmd_exclude_count = 0;
lsi->lsi_lmd->lmd_recovery_time_soft = 0;
lsi->lsi_lmd->lmd_recovery_time_hard = 0;
s2lsi_nocast(sb) = lsi;
atomic_set(&lsi->lsi_mounts, 1);
lsi->lsi_flags = LSI_UMOUNT_FAILOVER;
return lsi;
}
static int lustre_free_lsi(struct super_block *sb)
{
struct lustre_sb_info *lsi = s2lsi(sb);
CDEBUG(D_MOUNT, "Freeing lsi %p\n", lsi);
LASSERT(atomic_read(&lsi->lsi_mounts) == 0);
if (lsi->lsi_lmd) {
kfree(lsi->lsi_lmd->lmd_dev);
kfree(lsi->lsi_lmd->lmd_profile);
kfree(lsi->lsi_lmd->lmd_mgssec);
kfree(lsi->lsi_lmd->lmd_opts);
if (lsi->lsi_lmd->lmd_exclude_count)
kfree(lsi->lsi_lmd->lmd_exclude);
kfree(lsi->lsi_lmd->lmd_mgs);
kfree(lsi->lsi_lmd->lmd_osd_type);
kfree(lsi->lsi_lmd->lmd_params);
kfree(lsi->lsi_lmd);
}
LASSERT(!lsi->lsi_llsbi);
kfree(lsi);
s2lsi_nocast(sb) = NULL;
return 0;
}
static int lustre_put_lsi(struct super_block *sb)
{
struct lustre_sb_info *lsi = s2lsi(sb);
CDEBUG(D_MOUNT, "put %p %d\n", sb, atomic_read(&lsi->lsi_mounts));
if (atomic_dec_and_test(&lsi->lsi_mounts)) {
lustre_free_lsi(sb);
return 1;
}
return 0;
}
static int server_name2fsname(const char *svname, char *fsname,
const char **endptr)
{
const char *dash;
dash = svname + strnlen(svname, 8);
for (; dash > svname && *dash != '-' && *dash != ':'; dash--)
;
if (dash == svname)
return -EINVAL;
if (fsname) {
strncpy(fsname, svname, dash - svname);
fsname[dash - svname] = '\0';
}
if (endptr)
*endptr = dash;
return 0;
}
static int server_name2index(const char *svname, __u32 *idx,
const char **endptr)
{
unsigned long index;
int rc;
const char *dash;
rc = server_name2fsname(svname, NULL, &dash);
if (rc != 0)
return rc;
dash++;
if (strncmp(dash, "MDT", 3) == 0)
rc = LDD_F_SV_TYPE_MDT;
else if (strncmp(dash, "OST", 3) == 0)
rc = LDD_F_SV_TYPE_OST;
else
return -EINVAL;
dash += 3;
if (strncmp(dash, "all", 3) == 0) {
if (endptr)
*endptr = dash + 3;
return rc | LDD_F_SV_ALL;
}
index = simple_strtoul(dash, (char **)endptr, 16);
if (idx)
*idx = index;
if (endptr && strncmp(LUSTRE_MDC_NAME, *endptr + 1,
sizeof(LUSTRE_MDC_NAME) - 1) == 0)
*endptr += sizeof(LUSTRE_MDC_NAME);
return rc;
}
int lustre_common_put_super(struct super_block *sb)
{
int rc;
CDEBUG(D_MOUNT, "dropping sb %p\n", sb);
rc = lustre_stop_mgc(sb);
if (rc && (rc != -ENOENT)) {
if (rc != -EBUSY) {
CERROR("Can't stop MGC: %d\n", rc);
return rc;
}
CDEBUG(D_MOUNT, "MGC still in use\n");
}
lustre_put_lsi(sb);
return rc;
}
static void lmd_print(struct lustre_mount_data *lmd)
{
int i;
PRINT_CMD(D_MOUNT, " mount data:\n");
if (lmd_is_client(lmd))
PRINT_CMD(D_MOUNT, "profile: %s\n", lmd->lmd_profile);
PRINT_CMD(D_MOUNT, "device: %s\n", lmd->lmd_dev);
PRINT_CMD(D_MOUNT, "flags: %x\n", lmd->lmd_flags);
if (lmd->lmd_opts)
PRINT_CMD(D_MOUNT, "options: %s\n", lmd->lmd_opts);
if (lmd->lmd_recovery_time_soft)
PRINT_CMD(D_MOUNT, "recovery time soft: %d\n",
lmd->lmd_recovery_time_soft);
if (lmd->lmd_recovery_time_hard)
PRINT_CMD(D_MOUNT, "recovery time hard: %d\n",
lmd->lmd_recovery_time_hard);
for (i = 0; i < lmd->lmd_exclude_count; i++) {
PRINT_CMD(D_MOUNT, "exclude %d: OST%04x\n", i,
lmd->lmd_exclude[i]);
}
}
int lustre_check_exclusion(struct super_block *sb, char *svname)
{
struct lustre_sb_info *lsi = s2lsi(sb);
struct lustre_mount_data *lmd = lsi->lsi_lmd;
__u32 index;
int i, rc;
rc = server_name2index(svname, &index, NULL);
if (rc != LDD_F_SV_TYPE_OST)
return 0;
CDEBUG(D_MOUNT, "Check exclusion %s (%d) in %d of %s\n", svname,
index, lmd->lmd_exclude_count, lmd->lmd_dev);
for (i = 0; i < lmd->lmd_exclude_count; i++) {
if (index == lmd->lmd_exclude[i]) {
CWARN("Excluding %s (on exclusion list)\n", svname);
return 1;
}
}
return 0;
}
static int lmd_make_exclusion(struct lustre_mount_data *lmd, const char *ptr)
{
const char *s1 = ptr, *s2;
__u32 index = 0, *exclude_list;
int rc = 0, devmax;
devmax = strlen(ptr) / 8 + 1;
exclude_list = kcalloc(devmax, sizeof(index), GFP_NOFS);
if (!exclude_list)
return -ENOMEM;
while (*s1 && *s1 != ' ' && *s1 != ',') {
s1++;
rc = server_name2index(s1, &index, &s2);
if (rc < 0) {
CERROR("Can't parse server name '%s': rc = %d\n",
s1, rc);
break;
}
if (rc == LDD_F_SV_TYPE_OST)
exclude_list[lmd->lmd_exclude_count++] = index;
else
CDEBUG(D_MOUNT, "ignoring exclude %.*s: type = %#x\n",
(uint)(s2 - s1), s1, rc);
s1 = s2;
if (lmd->lmd_exclude_count >= devmax)
break;
}
if (rc >= 0)
rc = 0;
if (lmd->lmd_exclude_count) {
lmd->lmd_exclude = kcalloc(lmd->lmd_exclude_count,
sizeof(index), GFP_NOFS);
if (lmd->lmd_exclude) {
memcpy(lmd->lmd_exclude, exclude_list,
sizeof(index) * lmd->lmd_exclude_count);
} else {
rc = -ENOMEM;
lmd->lmd_exclude_count = 0;
}
}
kfree(exclude_list);
return rc;
}
static int lmd_parse_mgssec(struct lustre_mount_data *lmd, char *ptr)
{
char *tail;
int length;
kfree(lmd->lmd_mgssec);
lmd->lmd_mgssec = NULL;
tail = strchr(ptr, ',');
if (!tail)
length = strlen(ptr);
else
length = tail - ptr;
lmd->lmd_mgssec = kzalloc(length + 1, GFP_NOFS);
if (!lmd->lmd_mgssec)
return -ENOMEM;
memcpy(lmd->lmd_mgssec, ptr, length);
lmd->lmd_mgssec[length] = '\0';
return 0;
}
static int lmd_parse_string(char **handle, char *ptr)
{
char *tail;
int length;
if (!handle || !ptr)
return -EINVAL;
kfree(*handle);
*handle = NULL;
tail = strchr(ptr, ',');
if (!tail)
length = strlen(ptr);
else
length = tail - ptr;
*handle = kzalloc(length + 1, GFP_NOFS);
if (!*handle)
return -ENOMEM;
memcpy(*handle, ptr, length);
(*handle)[length] = '\0';
return 0;
}
static int lmd_parse_mgs(struct lustre_mount_data *lmd, char **ptr)
{
lnet_nid_t nid;
char *tail = *ptr;
char *mgsnid;
int length;
int oldlen = 0;
while (class_parse_nid_quiet(tail, &nid, &tail) == 0)
;
length = tail - *ptr;
if (length == 0) {
LCONSOLE_ERROR_MSG(0x159, "Can't parse NID '%s'\n", *ptr);
return -EINVAL;
}
if (lmd->lmd_mgs)
oldlen = strlen(lmd->lmd_mgs) + 1;
mgsnid = kzalloc(oldlen + length + 1, GFP_NOFS);
if (!mgsnid)
return -ENOMEM;
if (lmd->lmd_mgs) {
memcpy(mgsnid, lmd->lmd_mgs, oldlen);
mgsnid[oldlen - 1] = ':';
kfree(lmd->lmd_mgs);
}
memcpy(mgsnid + oldlen, *ptr, length);
mgsnid[oldlen + length] = '\0';
lmd->lmd_mgs = mgsnid;
*ptr = tail;
return 0;
}
static int lmd_parse(char *options, struct lustre_mount_data *lmd)
{
char *s1, *s2, *devname = NULL;
struct lustre_mount_data *raw = (struct lustre_mount_data *)options;
int rc = 0;
LASSERT(lmd);
if (!options) {
LCONSOLE_ERROR_MSG(0x162, "Missing mount data: check that /sbin/mount.lustre is installed.\n");
return -EINVAL;
}
if ((raw->lmd_magic & 0xffffff00) == (LMD_MAGIC & 0xffffff00)) {
LCONSOLE_ERROR_MSG(0x163, "You're using an old version of /sbin/mount.lustre. Please install version %s\n",
LUSTRE_VERSION_STRING);
return -EINVAL;
}
lmd->lmd_magic = LMD_MAGIC;
lmd->lmd_params = kzalloc(LMD_PARAMS_MAXLEN, GFP_NOFS);
if (!lmd->lmd_params)
return -ENOMEM;
lmd->lmd_params[0] = '\0';
s1 = options;
while (*s1) {
int clear = 0;
int time_min = OBD_RECOVERY_TIME_MIN;
char *s3;
while (*s1 == ' ' || *s1 == ',')
s1++;
s3 = s1;
if (strncmp(s1, "abort_recov", 11) == 0) {
lmd->lmd_flags |= LMD_FLG_ABORT_RECOV;
clear++;
} else if (strncmp(s1, "recovery_time_soft=", 19) == 0) {
lmd->lmd_recovery_time_soft = max_t(int,
simple_strtoul(s1 + 19, NULL, 10), time_min);
clear++;
} else if (strncmp(s1, "recovery_time_hard=", 19) == 0) {
lmd->lmd_recovery_time_hard = max_t(int,
simple_strtoul(s1 + 19, NULL, 10), time_min);
clear++;
} else if (strncmp(s1, "noir", 4) == 0) {
lmd->lmd_flags |= LMD_FLG_NOIR;
clear++;
} else if (strncmp(s1, "nosvc", 5) == 0) {
lmd->lmd_flags |= LMD_FLG_NOSVC;
clear++;
} else if (strncmp(s1, "nomgs", 5) == 0) {
lmd->lmd_flags |= LMD_FLG_NOMGS;
clear++;
} else if (strncmp(s1, "noscrub", 7) == 0) {
lmd->lmd_flags |= LMD_FLG_NOSCRUB;
clear++;
} else if (strncmp(s1, PARAM_MGSNODE,
sizeof(PARAM_MGSNODE) - 1) == 0) {
s2 = s1 + sizeof(PARAM_MGSNODE) - 1;
rc = lmd_parse_mgs(lmd, &s2);
if (rc)
goto invalid;
clear++;
} else if (strncmp(s1, "writeconf", 9) == 0) {
lmd->lmd_flags |= LMD_FLG_WRITECONF;
clear++;
} else if (strncmp(s1, "update", 6) == 0) {
lmd->lmd_flags |= LMD_FLG_UPDATE;
clear++;
} else if (strncmp(s1, "virgin", 6) == 0) {
lmd->lmd_flags |= LMD_FLG_VIRGIN;
clear++;
} else if (strncmp(s1, "noprimnode", 10) == 0) {
lmd->lmd_flags |= LMD_FLG_NO_PRIMNODE;
clear++;
} else if (strncmp(s1, "mgssec=", 7) == 0) {
rc = lmd_parse_mgssec(lmd, s1 + 7);
if (rc)
goto invalid;
s3 = s2;
clear++;
} else if (strncmp(s1, "exclude=", 8) == 0) {
rc = lmd_make_exclusion(lmd, s1 + 7);
if (rc)
goto invalid;
clear++;
} else if (strncmp(s1, "mgs", 3) == 0) {
lmd->lmd_flags |= LMD_FLG_MGS;
clear++;
} else if (strncmp(s1, "svname=", 7) == 0) {
rc = lmd_parse_string(&lmd->lmd_profile, s1 + 7);
if (rc)
goto invalid;
clear++;
} else if (strncmp(s1, "param=", 6) == 0) {
size_t length, params_length;
char *tail = strchr(s1 + 6, ',');
if (!tail) {
length = strlen(s1);
} else {
lnet_nid_t nid;
char *param_str = tail + 1;
int supplementary = 1;
while (!class_parse_nid_quiet(param_str, &nid,
&param_str)) {
supplementary = 0;
}
length = param_str - s1 - supplementary;
}
length -= 6;
params_length = strlen(lmd->lmd_params);
if (params_length + length + 1 >= LMD_PARAMS_MAXLEN)
return -E2BIG;
strncat(lmd->lmd_params, s1 + 6, length);
lmd->lmd_params[params_length + length] = '\0';
strlcat(lmd->lmd_params, " ", LMD_PARAMS_MAXLEN);
s3 = s1 + 6 + length;
clear++;
} else if (strncmp(s1, "osd=", 4) == 0) {
rc = lmd_parse_string(&lmd->lmd_osd_type, s1 + 4);
if (rc)
goto invalid;
clear++;
}
else if (strncmp(s1, "device=", 7) == 0) {
devname = s1 + 7;
*s1 = '\0';
break;
}
s2 = strchr(s1, ',');
if (!s2) {
if (clear)
*s1 = '\0';
break;
}
s2++;
if (clear)
memmove(s1, s2, strlen(s2) + 1);
else
s1 = s2;
}
if (!devname) {
LCONSOLE_ERROR_MSG(0x164, "Can't find the device name (need mount option 'device=...')\n");
goto invalid;
}
s1 = strstr(devname, ":/");
if (s1) {
++s1;
lmd->lmd_flags |= LMD_FLG_CLIENT;
while (*++s1 == '/')
;
lmd->lmd_profile = kasprintf(GFP_NOFS, "%s-client", s1);
if (!lmd->lmd_profile)
return -ENOMEM;
}
lmd->lmd_dev = kzalloc(strlen(devname) + 1, GFP_NOFS);
if (!lmd->lmd_dev)
return -ENOMEM;
strcpy(lmd->lmd_dev, devname);
s1 = options + strlen(options) - 1;
while (s1 >= options && (*s1 == ',' || *s1 == ' '))
*s1-- = 0;
if (*options != 0) {
lmd->lmd_opts = kzalloc(strlen(options) + 1, GFP_NOFS);
if (!lmd->lmd_opts)
return -ENOMEM;
strcpy(lmd->lmd_opts, options);
}
lmd_print(lmd);
lmd->lmd_magic = LMD_MAGIC;
return rc;
invalid:
CERROR("Bad mount options %s\n", options);
return -EINVAL;
}
static int lustre_fill_super(struct super_block *sb, void *data, int silent)
{
struct lustre_mount_data *lmd;
struct lustre_mount_data2 *lmd2 = data;
struct lustre_sb_info *lsi;
int rc;
CDEBUG(D_MOUNT | D_VFSTRACE, "VFS Op: sb %p\n", sb);
lsi = lustre_init_lsi(sb);
if (!lsi)
return -ENOMEM;
lmd = lsi->lsi_lmd;
lockdep_off();
obd_zombie_barrier();
if (lmd_parse((lmd2->lmd2_data), lmd)) {
lustre_put_lsi(sb);
rc = -EINVAL;
goto out;
}
if (lmd_is_client(lmd)) {
CDEBUG(D_MOUNT, "Mounting client %s\n", lmd->lmd_profile);
if (!client_fill_super)
request_module("lustre");
if (!client_fill_super) {
LCONSOLE_ERROR_MSG(0x165, "Nothing registered for client mount! Is the 'lustre' module loaded?\n");
lustre_put_lsi(sb);
rc = -ENODEV;
} else {
rc = lustre_start_mgc(sb);
if (rc) {
lustre_common_put_super(sb);
goto out;
}
rc = (*client_fill_super)(sb, lmd2->lmd2_mnt);
}
} else {
CERROR("This is client-side-only module, cannot handle server mount.\n");
rc = -EINVAL;
}
goto out;
out:
if (rc) {
CERROR("Unable to mount %s (%d)\n",
s2lsi(sb) ? lmd->lmd_dev : "", rc);
} else {
CDEBUG(D_SUPER, "Mount %s complete\n",
lmd->lmd_dev);
}
lockdep_on();
return rc;
}
void lustre_register_client_fill_super(int (*cfs)(struct super_block *sb,
struct vfsmount *mnt))
{
client_fill_super = cfs;
}
void lustre_register_kill_super_cb(void (*cfs)(struct super_block *sb))
{
kill_super_cb = cfs;
}
static struct dentry *lustre_mount(struct file_system_type *fs_type, int flags,
const char *devname, void *data)
{
struct lustre_mount_data2 lmd2 = {
.lmd2_data = data,
.lmd2_mnt = NULL
};
return mount_nodev(fs_type, flags, &lmd2, lustre_fill_super);
}
static void lustre_kill_super(struct super_block *sb)
{
struct lustre_sb_info *lsi = s2lsi(sb);
if (kill_super_cb && lsi)
(*kill_super_cb)(sb);
kill_anon_super(sb);
}
int lustre_register_fs(void)
{
return register_filesystem(&lustre_fs_type);
}
int lustre_unregister_fs(void)
{
return unregister_filesystem(&lustre_fs_type);
}
