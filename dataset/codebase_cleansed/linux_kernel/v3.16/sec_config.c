const char *sptlrpc_part2name(enum lustre_sec_part part)
{
switch (part) {
case LUSTRE_SP_CLI:
return "cli";
case LUSTRE_SP_MDT:
return "mdt";
case LUSTRE_SP_OST:
return "ost";
case LUSTRE_SP_MGC:
return "mgc";
case LUSTRE_SP_MGS:
return "mgs";
case LUSTRE_SP_ANY:
return "any";
default:
return "err";
}
}
enum lustre_sec_part sptlrpc_target_sec_part(struct obd_device *obd)
{
const char *type = obd->obd_type->typ_name;
if (!strcmp(type, LUSTRE_MDT_NAME))
return LUSTRE_SP_MDT;
if (!strcmp(type, LUSTRE_OST_NAME))
return LUSTRE_SP_OST;
if (!strcmp(type, LUSTRE_MGS_NAME))
return LUSTRE_SP_MGS;
CERROR("unknown target %p(%s)\n", obd, type);
return LUSTRE_SP_ANY;
}
int sptlrpc_parse_flavor(const char *str, struct sptlrpc_flavor *flvr)
{
char buf[32];
char *bulk, *alg;
memset(flvr, 0, sizeof(*flvr));
if (str == NULL || str[0] == '\0') {
flvr->sf_rpc = SPTLRPC_FLVR_INVALID;
return 0;
}
strncpy(buf, str, sizeof(buf));
buf[sizeof(buf) - 1] = '\0';
bulk = strchr(buf, '-');
if (bulk)
*bulk++ = '\0';
flvr->sf_rpc = sptlrpc_name2flavor_base(buf);
if (flvr->sf_rpc == SPTLRPC_FLVR_INVALID)
goto err_out;
if (flvr->sf_rpc == SPTLRPC_FLVR_PLAIN) {
flvr->u_bulk.hash.hash_alg = BULK_HASH_ALG_ADLER32;
if (bulk) {
alg = strchr(bulk, ':');
if (alg == NULL)
goto err_out;
*alg++ = '\0';
if (strcmp(bulk, "hash"))
goto err_out;
flvr->u_bulk.hash.hash_alg = sptlrpc_get_hash_alg(alg);
if (flvr->u_bulk.hash.hash_alg >= BULK_HASH_ALG_MAX)
goto err_out;
}
if (flvr->u_bulk.hash.hash_alg == BULK_HASH_ALG_NULL)
flvr_set_bulk_svc(&flvr->sf_rpc, SPTLRPC_BULK_SVC_NULL);
else
flvr_set_bulk_svc(&flvr->sf_rpc, SPTLRPC_BULK_SVC_INTG);
} else {
if (bulk)
goto err_out;
}
flvr->sf_flags = 0;
return 0;
err_out:
CERROR("invalid flavor string: %s\n", str);
return -EINVAL;
}
static void get_default_flavor(struct sptlrpc_flavor *sf)
{
memset(sf, 0, sizeof(*sf));
sf->sf_rpc = SPTLRPC_FLVR_NULL;
sf->sf_flags = 0;
}
static void sptlrpc_rule_init(struct sptlrpc_rule *rule)
{
rule->sr_netid = LNET_NIDNET(LNET_NID_ANY);
rule->sr_from = LUSTRE_SP_ANY;
rule->sr_to = LUSTRE_SP_ANY;
rule->sr_padding = 0;
get_default_flavor(&rule->sr_flvr);
}
int sptlrpc_parse_rule(char *param, struct sptlrpc_rule *rule)
{
char *flavor, *dir;
int rc;
sptlrpc_rule_init(rule);
flavor = strchr(param, '=');
if (flavor == NULL) {
CERROR("invalid param, no '='\n");
return -EINVAL;
}
*flavor++ = '\0';
dir = strchr(param, '.');
if (dir)
*dir++ = '\0';
if (strcmp(param, "default")) {
rule->sr_netid = libcfs_str2net(param);
if (rule->sr_netid == LNET_NIDNET(LNET_NID_ANY)) {
CERROR("invalid network name: %s\n", param);
return -EINVAL;
}
}
if (dir) {
if (!strcmp(dir, "mdt2ost")) {
rule->sr_from = LUSTRE_SP_MDT;
rule->sr_to = LUSTRE_SP_OST;
} else if (!strcmp(dir, "mdt2mdt")) {
rule->sr_from = LUSTRE_SP_MDT;
rule->sr_to = LUSTRE_SP_MDT;
} else if (!strcmp(dir, "cli2ost")) {
rule->sr_from = LUSTRE_SP_CLI;
rule->sr_to = LUSTRE_SP_OST;
} else if (!strcmp(dir, "cli2mdt")) {
rule->sr_from = LUSTRE_SP_CLI;
rule->sr_to = LUSTRE_SP_MDT;
} else {
CERROR("invalid rule dir segment: %s\n", dir);
return -EINVAL;
}
}
rc = sptlrpc_parse_flavor(flavor, &rule->sr_flvr);
if (rc)
return -EINVAL;
return 0;
}
void sptlrpc_rule_set_free(struct sptlrpc_rule_set *rset)
{
LASSERT(rset->srs_nslot ||
(rset->srs_nrule == 0 && rset->srs_rules == NULL));
if (rset->srs_nslot) {
OBD_FREE(rset->srs_rules,
rset->srs_nslot * sizeof(*rset->srs_rules));
sptlrpc_rule_set_init(rset);
}
}
int sptlrpc_rule_set_expand(struct sptlrpc_rule_set *rset)
{
struct sptlrpc_rule *rules;
int nslot;
might_sleep();
if (rset->srs_nrule < rset->srs_nslot)
return 0;
nslot = rset->srs_nslot + 8;
OBD_ALLOC(rules, nslot * sizeof(*rset->srs_rules));
if (rules == NULL)
return -ENOMEM;
if (rset->srs_nrule) {
LASSERT(rset->srs_nslot && rset->srs_rules);
memcpy(rules, rset->srs_rules,
rset->srs_nrule * sizeof(*rset->srs_rules));
OBD_FREE(rset->srs_rules,
rset->srs_nslot * sizeof(*rset->srs_rules));
}
rset->srs_rules = rules;
rset->srs_nslot = nslot;
return 0;
}
static inline int rule_spec_dir(struct sptlrpc_rule *rule)
{
return (rule->sr_from != LUSTRE_SP_ANY ||
rule->sr_to != LUSTRE_SP_ANY);
}
static inline int rule_spec_net(struct sptlrpc_rule *rule)
{
return (rule->sr_netid != LNET_NIDNET(LNET_NID_ANY));
}
static inline int rule_match_dir(struct sptlrpc_rule *r1,
struct sptlrpc_rule *r2)
{
return (r1->sr_from == r2->sr_from && r1->sr_to == r2->sr_to);
}
static inline int rule_match_net(struct sptlrpc_rule *r1,
struct sptlrpc_rule *r2)
{
return (r1->sr_netid == r2->sr_netid);
}
int sptlrpc_rule_set_merge(struct sptlrpc_rule_set *rset,
struct sptlrpc_rule *rule)
{
struct sptlrpc_rule *p = rset->srs_rules;
int spec_dir, spec_net;
int rc, n, match = 0;
might_sleep();
spec_net = rule_spec_net(rule);
spec_dir = rule_spec_dir(rule);
for (n = 0; n < rset->srs_nrule; n++) {
p = &rset->srs_rules[n];
if (!rule_match_net(p, rule)) {
if (spec_net) {
if (rule_spec_net(p))
continue;
else
break;
} else {
continue;
}
}
if (!rule_match_dir(p, rule)) {
if (spec_dir) {
if (rule_spec_dir(p))
continue;
else
break;
} else {
continue;
}
}
match = 1;
break;
}
if (match) {
LASSERT(n >= 0 && n < rset->srs_nrule);
if (rule->sr_flvr.sf_rpc == SPTLRPC_FLVR_INVALID) {
if (n < rset->srs_nrule - 1)
memmove(&rset->srs_rules[n],
&rset->srs_rules[n + 1],
(rset->srs_nrule - n - 1) *
sizeof(*rule));
rset->srs_nrule--;
} else {
memcpy(&rset->srs_rules[n], rule, sizeof(*rule));
}
} else {
LASSERT(n >= 0 && n <= rset->srs_nrule);
if (rule->sr_flvr.sf_rpc != SPTLRPC_FLVR_INVALID) {
rc = sptlrpc_rule_set_expand(rset);
if (rc)
return rc;
if (n < rset->srs_nrule)
memmove(&rset->srs_rules[n + 1],
&rset->srs_rules[n],
(rset->srs_nrule - n) * sizeof(*rule));
memcpy(&rset->srs_rules[n], rule, sizeof(*rule));
rset->srs_nrule++;
} else {
CDEBUG(D_CONFIG, "ignore the unmatched deletion\n");
}
}
return 0;
}
int sptlrpc_rule_set_choose(struct sptlrpc_rule_set *rset,
enum lustre_sec_part from,
enum lustre_sec_part to,
lnet_nid_t nid,
struct sptlrpc_flavor *sf)
{
struct sptlrpc_rule *r;
int n;
for (n = 0; n < rset->srs_nrule; n++) {
r = &rset->srs_rules[n];
if (LNET_NIDNET(nid) != LNET_NIDNET(LNET_NID_ANY) &&
r->sr_netid != LNET_NIDNET(LNET_NID_ANY) &&
LNET_NIDNET(nid) != r->sr_netid)
continue;
if (from != LUSTRE_SP_ANY && r->sr_from != LUSTRE_SP_ANY &&
from != r->sr_from)
continue;
if (to != LUSTRE_SP_ANY && r->sr_to != LUSTRE_SP_ANY &&
to != r->sr_to)
continue;
*sf = r->sr_flvr;
return 1;
}
return 0;
}
void sptlrpc_rule_set_dump(struct sptlrpc_rule_set *rset)
{
struct sptlrpc_rule *r;
int n;
for (n = 0; n < rset->srs_nrule; n++) {
r = &rset->srs_rules[n];
CDEBUG(D_SEC, "<%02d> from %x to %x, net %x, rpc %x\n", n,
r->sr_from, r->sr_to, r->sr_netid, r->sr_flvr.sf_rpc);
}
}
static int sptlrpc_rule_set_extract(struct sptlrpc_rule_set *gen,
struct sptlrpc_rule_set *tgt,
enum lustre_sec_part from,
enum lustre_sec_part to,
struct sptlrpc_rule_set *rset)
{
struct sptlrpc_rule_set *src[2] = { gen, tgt };
struct sptlrpc_rule *rule;
int i, n, rc;
might_sleep();
for (i = 0; i < 2; i++) {
if (src[i] == NULL)
continue;
for (n = 0; n < src[i]->srs_nrule; n++) {
rule = &src[i]->srs_rules[n];
if (from != LUSTRE_SP_ANY &&
rule->sr_from != LUSTRE_SP_ANY &&
rule->sr_from != from)
continue;
if (to != LUSTRE_SP_ANY &&
rule->sr_to != LUSTRE_SP_ANY &&
rule->sr_to != to)
continue;
rc = sptlrpc_rule_set_merge(rset, rule);
if (rc) {
CERROR("can't merge: %d\n", rc);
return rc;
}
}
}
return 0;
}
static inline int is_hex(char c)
{
return ((c >= '0' && c <= '9') ||
(c >= 'a' && c <= 'f'));
}
static void target2fsname(const char *tgt, char *fsname, int buflen)
{
const char *ptr;
int len;
ptr = strrchr(tgt, '-');
if (ptr) {
if ((strncmp(ptr, "-MDT", 4) != 0 &&
strncmp(ptr, "-OST", 4) != 0) ||
!is_hex(ptr[4]) || !is_hex(ptr[5]) ||
!is_hex(ptr[6]) || !is_hex(ptr[7]))
ptr = NULL;
}
if (ptr == NULL)
len = strlen(tgt);
else
len = ptr - tgt;
len = min(len, buflen - 1);
memcpy(fsname, tgt, len);
fsname[len] = '\0';
}
static void sptlrpc_conf_free_rsets(struct sptlrpc_conf *conf)
{
struct sptlrpc_conf_tgt *conf_tgt, *conf_tgt_next;
sptlrpc_rule_set_free(&conf->sc_rset);
list_for_each_entry_safe(conf_tgt, conf_tgt_next,
&conf->sc_tgts, sct_list) {
sptlrpc_rule_set_free(&conf_tgt->sct_rset);
list_del(&conf_tgt->sct_list);
OBD_FREE_PTR(conf_tgt);
}
LASSERT(list_empty(&conf->sc_tgts));
conf->sc_updated = 0;
conf->sc_local = 0;
}
static void sptlrpc_conf_free(struct sptlrpc_conf *conf)
{
CDEBUG(D_SEC, "free sptlrpc conf %s\n", conf->sc_fsname);
sptlrpc_conf_free_rsets(conf);
list_del(&conf->sc_list);
OBD_FREE_PTR(conf);
}
static
struct sptlrpc_conf_tgt *sptlrpc_conf_get_tgt(struct sptlrpc_conf *conf,
const char *name,
int create)
{
struct sptlrpc_conf_tgt *conf_tgt;
list_for_each_entry(conf_tgt, &conf->sc_tgts, sct_list) {
if (strcmp(conf_tgt->sct_name, name) == 0)
return conf_tgt;
}
if (!create)
return NULL;
OBD_ALLOC_PTR(conf_tgt);
if (conf_tgt) {
strlcpy(conf_tgt->sct_name, name, sizeof(conf_tgt->sct_name));
sptlrpc_rule_set_init(&conf_tgt->sct_rset);
list_add(&conf_tgt->sct_list, &conf->sc_tgts);
}
return conf_tgt;
}
static
struct sptlrpc_conf *sptlrpc_conf_get(const char *fsname,
int create)
{
struct sptlrpc_conf *conf;
list_for_each_entry(conf, &sptlrpc_confs, sc_list) {
if (strcmp(conf->sc_fsname, fsname) == 0)
return conf;
}
if (!create)
return NULL;
OBD_ALLOC_PTR(conf);
if (conf == NULL)
return NULL;
strcpy(conf->sc_fsname, fsname);
sptlrpc_rule_set_init(&conf->sc_rset);
INIT_LIST_HEAD(&conf->sc_tgts);
list_add(&conf->sc_list, &sptlrpc_confs);
CDEBUG(D_SEC, "create sptlrpc conf %s\n", conf->sc_fsname);
return conf;
}
static int sptlrpc_conf_merge_rule(struct sptlrpc_conf *conf,
const char *target,
struct sptlrpc_rule *rule)
{
struct sptlrpc_conf_tgt *conf_tgt;
struct sptlrpc_rule_set *rule_set;
if (strcmp(conf->sc_fsname, target) == 0) {
rule_set = &conf->sc_rset;
} else {
conf_tgt = sptlrpc_conf_get_tgt(conf, target, 1);
if (conf_tgt) {
rule_set = &conf_tgt->sct_rset;
} else {
CERROR("out of memory, can't merge rule!\n");
return -ENOMEM;
}
}
return sptlrpc_rule_set_merge(rule_set, rule);
}
static int __sptlrpc_process_config(struct lustre_cfg *lcfg,
struct sptlrpc_conf *conf)
{
char *target, *param;
char fsname[MTI_NAME_MAXLEN];
struct sptlrpc_rule rule;
int rc;
target = lustre_cfg_string(lcfg, 1);
if (target == NULL) {
CERROR("missing target name\n");
return -EINVAL;
}
param = lustre_cfg_string(lcfg, 2);
if (param == NULL) {
CERROR("missing parameter\n");
return -EINVAL;
}
CDEBUG(D_SEC, "processing rule: %s.%s\n", target, param);
if (strncmp(param, PARAM_SRPC_FLVR, sizeof(PARAM_SRPC_FLVR) - 1) != 0) {
CERROR("Invalid sptlrpc parameter: %s\n", param);
return -EINVAL;
}
param += sizeof(PARAM_SRPC_FLVR) - 1;
rc = sptlrpc_parse_rule(param, &rule);
if (rc)
return -EINVAL;
if (conf == NULL) {
target2fsname(target, fsname, sizeof(fsname));
mutex_lock(&sptlrpc_conf_lock);
conf = sptlrpc_conf_get(fsname, 0);
if (conf == NULL) {
CERROR("can't find conf\n");
rc = -ENOMEM;
} else {
rc = sptlrpc_conf_merge_rule(conf, target, &rule);
}
mutex_unlock(&sptlrpc_conf_lock);
} else {
LASSERT(mutex_is_locked(&sptlrpc_conf_lock));
rc = sptlrpc_conf_merge_rule(conf, target, &rule);
}
if (rc == 0)
conf->sc_modified++;
return rc;
}
int sptlrpc_process_config(struct lustre_cfg *lcfg)
{
return __sptlrpc_process_config(lcfg, NULL);
}
static int logname2fsname(const char *logname, char *buf, int buflen)
{
char *ptr;
int len;
ptr = strrchr(logname, '-');
if (ptr == NULL || strcmp(ptr, "-sptlrpc")) {
CERROR("%s is not a sptlrpc config log\n", logname);
return -EINVAL;
}
len = min((int) (ptr - logname), buflen - 1);
memcpy(buf, logname, len);
buf[len] = '\0';
return 0;
}
void sptlrpc_conf_log_update_begin(const char *logname)
{
struct sptlrpc_conf *conf;
char fsname[16];
if (logname2fsname(logname, fsname, sizeof(fsname)))
return;
mutex_lock(&sptlrpc_conf_lock);
conf = sptlrpc_conf_get(fsname, 0);
if (conf) {
if(conf->sc_local) {
LASSERT(conf->sc_updated == 0);
sptlrpc_conf_free_rsets(conf);
}
conf->sc_modified = 0;
}
mutex_unlock(&sptlrpc_conf_lock);
}
void sptlrpc_conf_log_update_end(const char *logname)
{
struct sptlrpc_conf *conf;
char fsname[16];
if (logname2fsname(logname, fsname, sizeof(fsname)))
return;
mutex_lock(&sptlrpc_conf_lock);
conf = sptlrpc_conf_get(fsname, 0);
if (conf) {
if (conf->sc_updated == 0)
conf->sc_modified++;
conf->sc_updated = 1;
}
mutex_unlock(&sptlrpc_conf_lock);
}
void sptlrpc_conf_log_start(const char *logname)
{
char fsname[16];
if (logname2fsname(logname, fsname, sizeof(fsname)))
return;
mutex_lock(&sptlrpc_conf_lock);
sptlrpc_conf_get(fsname, 1);
mutex_unlock(&sptlrpc_conf_lock);
}
void sptlrpc_conf_log_stop(const char *logname)
{
struct sptlrpc_conf *conf;
char fsname[16];
if (logname2fsname(logname, fsname, sizeof(fsname)))
return;
mutex_lock(&sptlrpc_conf_lock);
conf = sptlrpc_conf_get(fsname, 0);
if (conf)
sptlrpc_conf_free(conf);
mutex_unlock(&sptlrpc_conf_lock);
}
static void inline flavor_set_flags(struct sptlrpc_flavor *sf,
enum lustre_sec_part from,
enum lustre_sec_part to,
unsigned int fl_udesc)
{
if (sf->sf_rpc == SPTLRPC_FLVR_NULL)
return;
if (from == LUSTRE_SP_MDT) {
sf->sf_flags |= PTLRPC_SEC_FL_ROOTONLY;
} else if (from == LUSTRE_SP_CLI && to == LUSTRE_SP_OST) {
sf->sf_flags |= PTLRPC_SEC_FL_ROOTONLY | PTLRPC_SEC_FL_BULK;
} else if (from == LUSTRE_SP_CLI && to == LUSTRE_SP_MDT) {
if (fl_udesc && sf->sf_rpc != SPTLRPC_FLVR_NULL)
sf->sf_flags |= PTLRPC_SEC_FL_UDESC;
}
}
void sptlrpc_conf_choose_flavor(enum lustre_sec_part from,
enum lustre_sec_part to,
struct obd_uuid *target,
lnet_nid_t nid,
struct sptlrpc_flavor *sf)
{
struct sptlrpc_conf *conf;
struct sptlrpc_conf_tgt *conf_tgt;
char name[MTI_NAME_MAXLEN];
int len, rc = 0;
target2fsname(target->uuid, name, sizeof(name));
mutex_lock(&sptlrpc_conf_lock);
conf = sptlrpc_conf_get(name, 0);
if (conf == NULL)
goto out;
len = strlen(target->uuid);
LASSERT(len > 5);
memcpy(name, target->uuid, len - 5);
name[len - 5] = '\0';
conf_tgt = sptlrpc_conf_get_tgt(conf, name, 0);
if (conf_tgt) {
rc = sptlrpc_rule_set_choose(&conf_tgt->sct_rset,
from, to, nid, sf);
if (rc)
goto out;
}
rc = sptlrpc_rule_set_choose(&conf->sc_rset, from, to, nid, sf);
out:
mutex_unlock(&sptlrpc_conf_lock);
if (rc == 0)
get_default_flavor(sf);
flavor_set_flags(sf, from, to, 1);
}
void sptlrpc_target_choose_flavor(struct sptlrpc_rule_set *rset,
enum lustre_sec_part from,
lnet_nid_t nid,
struct sptlrpc_flavor *sf)
{
if (sptlrpc_rule_set_choose(rset, from, LUSTRE_SP_ANY, nid, sf) == 0)
get_default_flavor(sf);
}
void sptlrpc_conf_client_adapt(struct obd_device *obd)
{
struct obd_import *imp;
LASSERT(strcmp(obd->obd_type->typ_name, LUSTRE_MDC_NAME) == 0 ||
strcmp(obd->obd_type->typ_name, LUSTRE_OSC_NAME) ==0);
CDEBUG(D_SEC, "obd %s\n", obd->u.cli.cl_target_uuid.uuid);
down_read(&obd->u.cli.cl_sem);
imp = obd->u.cli.cl_import;
if (imp) {
spin_lock(&imp->imp_lock);
if (imp->imp_sec)
imp->imp_sec_expire = cfs_time_current_sec() +
SEC_ADAPT_DELAY;
spin_unlock(&imp->imp_lock);
}
up_read(&obd->u.cli.cl_sem);
}
static void rule2string(struct sptlrpc_rule *r, char *buf, int buflen)
{
char dirbuf[8];
char *net;
char *ptr = buf;
if (r->sr_netid == LNET_NIDNET(LNET_NID_ANY))
net = "default";
else
net = libcfs_net2str(r->sr_netid);
if (r->sr_from == LUSTRE_SP_ANY && r->sr_to == LUSTRE_SP_ANY)
dirbuf[0] = '\0';
else
snprintf(dirbuf, sizeof(dirbuf), ".%s2%s",
sptlrpc_part2name(r->sr_from),
sptlrpc_part2name(r->sr_to));
ptr += snprintf(buf, buflen, "srpc.flavor.%s%s=", net, dirbuf);
sptlrpc_flavor2name(&r->sr_flvr, ptr, buflen - (ptr - buf));
buf[buflen - 1] = '\0';
}
static int sptlrpc_record_rule_set(struct llog_handle *llh,
char *target,
struct sptlrpc_rule_set *rset)
{
struct lustre_cfg_bufs bufs;
struct lustre_cfg *lcfg;
struct llog_rec_hdr rec;
int buflen;
char param[48];
int i, rc;
for (i = 0; i < rset->srs_nrule; i++) {
rule2string(&rset->srs_rules[i], param, sizeof(param));
lustre_cfg_bufs_reset(&bufs, NULL);
lustre_cfg_bufs_set_string(&bufs, 1, target);
lustre_cfg_bufs_set_string(&bufs, 2, param);
lcfg = lustre_cfg_new(LCFG_SPTLRPC_CONF, &bufs);
LASSERT(lcfg);
buflen = lustre_cfg_len(lcfg->lcfg_bufcount,
lcfg->lcfg_buflens);
rec.lrh_len = llog_data_len(buflen);
rec.lrh_type = OBD_CFG_REC;
rc = llog_write(NULL, llh, &rec, NULL, 0, (void *)lcfg, -1);
if (rc)
CERROR("failed to write a rec: rc = %d\n", rc);
lustre_cfg_free(lcfg);
}
return 0;
}
static int sptlrpc_record_rules(struct llog_handle *llh,
struct sptlrpc_conf *conf)
{
struct sptlrpc_conf_tgt *conf_tgt;
sptlrpc_record_rule_set(llh, conf->sc_fsname, &conf->sc_rset);
list_for_each_entry(conf_tgt, &conf->sc_tgts, sct_list) {
sptlrpc_record_rule_set(llh, conf_tgt->sct_name,
&conf_tgt->sct_rset);
}
return 0;
}
static
int sptlrpc_target_local_copy_conf(struct obd_device *obd,
struct sptlrpc_conf *conf)
{
struct llog_handle *llh = NULL;
struct llog_ctxt *ctxt;
struct lvfs_run_ctxt saved;
struct dentry *dentry;
int rc;
ctxt = llog_get_context(obd, LLOG_CONFIG_ORIG_CTXT);
if (ctxt == NULL)
return -EINVAL;
push_ctxt(&saved, &obd->obd_lvfs_ctxt, NULL);
dentry = ll_lookup_one_len(MOUNT_CONFIGS_DIR, cfs_fs_pwd(current->fs),
strlen(MOUNT_CONFIGS_DIR));
if (IS_ERR(dentry)) {
rc = PTR_ERR(dentry);
CERROR("cannot lookup %s directory: rc = %d\n",
MOUNT_CONFIGS_DIR, rc);
GOTO(out_ctx, rc);
}
rc = llog_erase(NULL, ctxt, NULL, LOG_SPTLRPC_TMP);
if (rc < 0 && rc != -ENOENT) {
CERROR("%s: cannot erase temporary sptlrpc log: rc = %d\n",
obd->obd_name, rc);
GOTO(out_dput, rc);
}
rc = llog_open_create(NULL, ctxt, &llh, NULL, LOG_SPTLRPC_TMP);
if (rc)
GOTO(out_dput, rc);
rc = llog_init_handle(NULL, llh, LLOG_F_IS_PLAIN, NULL);
if (rc)
GOTO(out_close, rc);
rc = sptlrpc_record_rules(llh, conf);
out_close:
llog_close(NULL, llh);
if (rc == 0)
rc = lustre_rename(dentry, obd->obd_lvfs_ctxt.pwdmnt,
LOG_SPTLRPC_TMP, LOG_SPTLRPC);
out_dput:
l_dput(dentry);
out_ctx:
pop_ctxt(&saved, &obd->obd_lvfs_ctxt, NULL);
llog_ctxt_put(ctxt);
CDEBUG(D_SEC, "target %s: write local sptlrpc conf: rc = %d\n",
obd->obd_name, rc);
return rc;
}
static int local_read_handler(const struct lu_env *env,
struct llog_handle *llh,
struct llog_rec_hdr *rec, void *data)
{
struct sptlrpc_conf *conf = (struct sptlrpc_conf *) data;
struct lustre_cfg *lcfg = (struct lustre_cfg *)(rec + 1);
int cfg_len, rc;
if (rec->lrh_type != OBD_CFG_REC) {
CERROR("unhandled lrh_type: %#x\n", rec->lrh_type);
return -EINVAL;
}
cfg_len = rec->lrh_len - sizeof(struct llog_rec_hdr) -
sizeof(struct llog_rec_tail);
rc = lustre_cfg_sanity_check(lcfg, cfg_len);
if (rc) {
CERROR("Insane cfg\n");
return rc;
}
if (lcfg->lcfg_command != LCFG_SPTLRPC_CONF) {
CERROR("invalid command (%x)\n", lcfg->lcfg_command);
return -EINVAL;
}
return __sptlrpc_process_config(lcfg, conf);
}
static
int sptlrpc_target_local_read_conf(struct obd_device *obd,
struct sptlrpc_conf *conf)
{
struct llog_handle *llh = NULL;
struct llog_ctxt *ctxt;
struct lvfs_run_ctxt saved;
int rc;
LASSERT(conf->sc_updated == 0 && conf->sc_local == 0);
ctxt = llog_get_context(obd, LLOG_CONFIG_ORIG_CTXT);
if (ctxt == NULL) {
CERROR("missing llog context\n");
return -EINVAL;
}
push_ctxt(&saved, &obd->obd_lvfs_ctxt, NULL);
rc = llog_open(NULL, ctxt, &llh, NULL, LOG_SPTLRPC, LLOG_OPEN_EXISTS);
if (rc < 0) {
if (rc == -ENOENT)
rc = 0;
GOTO(out_pop, rc);
}
rc = llog_init_handle(NULL, llh, LLOG_F_IS_PLAIN, NULL);
if (rc)
GOTO(out_close, rc);
if (llog_get_size(llh) <= 1) {
CDEBUG(D_SEC, "no local sptlrpc copy found\n");
GOTO(out_close, rc = 0);
}
rc = llog_process(NULL, llh, local_read_handler, (void *)conf, NULL);
if (rc == 0) {
conf->sc_local = 1;
} else {
sptlrpc_conf_free_rsets(conf);
}
out_close:
llog_close(NULL, llh);
out_pop:
pop_ctxt(&saved, &obd->obd_lvfs_ctxt, NULL);
llog_ctxt_put(ctxt);
CDEBUG(D_SEC, "target %s: read local sptlrpc conf: rc = %d\n",
obd->obd_name, rc);
return rc;
}
int sptlrpc_conf_target_get_rules(struct obd_device *obd,
struct sptlrpc_rule_set *rset,
int initial)
{
struct sptlrpc_conf *conf;
struct sptlrpc_conf_tgt *conf_tgt;
enum lustre_sec_part sp_dst;
char fsname[MTI_NAME_MAXLEN];
int rc = 0;
if (strcmp(obd->obd_type->typ_name, LUSTRE_MDT_NAME) == 0) {
sp_dst = LUSTRE_SP_MDT;
} else if (strcmp(obd->obd_type->typ_name, LUSTRE_OST_NAME) == 0) {
sp_dst = LUSTRE_SP_OST;
} else {
CERROR("unexpected obd type %s\n", obd->obd_type->typ_name);
return -EINVAL;
}
CDEBUG(D_SEC, "get rules for target %s\n", obd->obd_uuid.uuid);
target2fsname(obd->obd_uuid.uuid, fsname, sizeof(fsname));
mutex_lock(&sptlrpc_conf_lock);
conf = sptlrpc_conf_get(fsname, 0);
if (conf == NULL) {
CERROR("missing sptlrpc config log\n");
GOTO(out, rc);
}
if (conf->sc_updated == 0) {
if (conf->sc_local)
sptlrpc_conf_free_rsets(conf);
sptlrpc_target_local_read_conf(obd, conf);
} else {
LASSERT(conf->sc_local == 0);
if (initial || conf->sc_modified)
sptlrpc_target_local_copy_conf(obd, conf);
else
CDEBUG(D_SEC, "unchanged, skip updating local copy\n");
}
conf_tgt = sptlrpc_conf_get_tgt(conf, obd->obd_name, 0);
rc = sptlrpc_rule_set_extract(&conf->sc_rset,
conf_tgt ? &conf_tgt->sct_rset: NULL,
LUSTRE_SP_ANY, sp_dst, rset);
out:
mutex_unlock(&sptlrpc_conf_lock);
return rc;
}
int sptlrpc_conf_init(void)
{
mutex_init(&sptlrpc_conf_lock);
return 0;
}
void sptlrpc_conf_fini(void)
{
struct sptlrpc_conf *conf, *conf_next;
mutex_lock(&sptlrpc_conf_lock);
list_for_each_entry_safe(conf, conf_next, &sptlrpc_confs, sc_list) {
sptlrpc_conf_free(conf);
}
LASSERT(list_empty(&sptlrpc_confs));
mutex_unlock(&sptlrpc_conf_lock);
}
