int smk_access_entry(char *subject_label, char *object_label,
struct list_head *rule_list)
{
int may = -ENOENT;
struct smack_rule *srp;
list_for_each_entry_rcu(srp, rule_list, list) {
if (srp->smk_object == object_label &&
srp->smk_subject == subject_label) {
may = srp->smk_access;
break;
}
}
return may;
}
int smk_access(char *subject_label, char *object_label, int request,
struct smk_audit_info *a)
{
struct smack_known *skp;
int may = MAY_NOT;
int rc = 0;
if (subject_label == smack_known_star.smk_known) {
rc = -EACCES;
goto out_audit;
}
if (object_label == smack_known_web.smk_known ||
subject_label == smack_known_web.smk_known)
goto out_audit;
if (object_label == smack_known_star.smk_known)
goto out_audit;
if (subject_label == object_label)
goto out_audit;
if ((request & MAY_ANYREAD) == request) {
if (object_label == smack_known_floor.smk_known)
goto out_audit;
if (subject_label == smack_known_hat.smk_known)
goto out_audit;
}
skp = smk_find_entry(subject_label);
rcu_read_lock();
may = smk_access_entry(subject_label, object_label, &skp->smk_rules);
rcu_read_unlock();
if (may > 0 && (request & may) == request)
goto out_audit;
rc = -EACCES;
out_audit:
#ifdef CONFIG_AUDIT
if (a)
smack_log(subject_label, object_label, request, rc, a);
#endif
return rc;
}
int smk_curacc(char *obj_label, u32 mode, struct smk_audit_info *a)
{
struct task_smack *tsp = current_security();
char *sp = smk_of_task(tsp);
int may;
int rc;
rc = smk_access(sp, obj_label, mode, NULL);
if (rc == 0) {
may = smk_access_entry(sp, obj_label, &tsp->smk_rules);
if (may < 0)
goto out_audit;
if ((mode & may) == mode)
goto out_audit;
rc = -EACCES;
}
if (rc != 0 && smack_privileged(CAP_MAC_OVERRIDE))
rc = 0;
out_audit:
#ifdef CONFIG_AUDIT
if (a)
smack_log(sp, obj_label, mode, rc, a);
#endif
return rc;
}
static inline void smack_str_from_perm(char *string, int access)
{
int i = 0;
if (access & MAY_READ)
string[i++] = 'r';
if (access & MAY_WRITE)
string[i++] = 'w';
if (access & MAY_EXEC)
string[i++] = 'x';
if (access & MAY_APPEND)
string[i++] = 'a';
if (access & MAY_TRANSMUTE)
string[i++] = 't';
string[i] = '\0';
}
static void smack_log_callback(struct audit_buffer *ab, void *a)
{
struct common_audit_data *ad = a;
struct smack_audit_data *sad = ad->smack_audit_data;
audit_log_format(ab, "lsm=SMACK fn=%s action=%s",
ad->smack_audit_data->function,
sad->result ? "denied" : "granted");
audit_log_format(ab, " subject=");
audit_log_untrustedstring(ab, sad->subject);
audit_log_format(ab, " object=");
audit_log_untrustedstring(ab, sad->object);
audit_log_format(ab, " requested=%s", sad->request);
}
void smack_log(char *subject_label, char *object_label, int request,
int result, struct smk_audit_info *ad)
{
char request_buffer[SMK_NUM_ACCESS_TYPE + 1];
struct smack_audit_data *sad;
struct common_audit_data *a = &ad->a;
if (result != 0 && (log_policy & SMACK_AUDIT_DENIED) == 0)
return;
if (result == 0 && (log_policy & SMACK_AUDIT_ACCEPT) == 0)
return;
sad = a->smack_audit_data;
if (sad->function == NULL)
sad->function = "unknown";
smack_str_from_perm(request_buffer, request);
sad->subject = subject_label;
sad->object = object_label;
sad->request = request_buffer;
sad->result = result;
common_lsm_audit(a, smack_log_callback, NULL);
}
void smack_log(char *subject_label, char *object_label, int request,
int result, struct smk_audit_info *ad)
{
}
struct smack_known *smk_find_entry(const char *string)
{
struct smack_known *skp;
list_for_each_entry_rcu(skp, &smack_known_list, list) {
if (strcmp(skp->smk_known, string) == 0)
return skp;
}
return NULL;
}
char *smk_parse_smack(const char *string, int len)
{
char *smack;
int i;
if (len <= 0)
len = strlen(string) + 1;
if (string[0] == '-')
return NULL;
for (i = 0; i < len; i++)
if (string[i] > '~' || string[i] <= ' ' || string[i] == '/' ||
string[i] == '"' || string[i] == '\\' || string[i] == '\'')
break;
if (i == 0 || i >= SMK_LONGLABEL)
return NULL;
smack = kzalloc(i + 1, GFP_KERNEL);
if (smack != NULL) {
strncpy(smack, string, i + 1);
smack[i] = '\0';
}
return smack;
}
int smk_netlbl_mls(int level, char *catset, struct netlbl_lsm_secattr *sap,
int len)
{
unsigned char *cp;
unsigned char m;
int cat;
int rc;
int byte;
sap->flags |= NETLBL_SECATTR_MLS_CAT;
sap->attr.mls.lvl = level;
sap->attr.mls.cat = netlbl_secattr_catmap_alloc(GFP_ATOMIC);
sap->attr.mls.cat->startbit = 0;
for (cat = 1, cp = catset, byte = 0; byte < len; cp++, byte++)
for (m = 0x80; m != 0; m >>= 1, cat++) {
if ((m & *cp) == 0)
continue;
rc = netlbl_secattr_catmap_setbit(sap->attr.mls.cat,
cat, GFP_ATOMIC);
if (rc < 0) {
netlbl_secattr_catmap_free(sap->attr.mls.cat);
return rc;
}
}
return 0;
}
struct smack_known *smk_import_entry(const char *string, int len)
{
struct smack_known *skp;
char *smack;
int slen;
int rc;
smack = smk_parse_smack(string, len);
if (smack == NULL)
return NULL;
mutex_lock(&smack_known_lock);
skp = smk_find_entry(smack);
if (skp != NULL)
goto freeout;
skp = kzalloc(sizeof(*skp), GFP_KERNEL);
if (skp == NULL)
goto freeout;
skp->smk_known = smack;
skp->smk_secid = smack_next_secid++;
skp->smk_netlabel.domain = skp->smk_known;
skp->smk_netlabel.flags =
NETLBL_SECATTR_DOMAIN | NETLBL_SECATTR_MLS_LVL;
slen = strlen(smack);
if (slen < SMK_CIPSOLEN)
rc = smk_netlbl_mls(smack_cipso_direct, skp->smk_known,
&skp->smk_netlabel, slen);
else
rc = smk_netlbl_mls(smack_cipso_mapped, (char *)&skp->smk_secid,
&skp->smk_netlabel, sizeof(skp->smk_secid));
if (rc >= 0) {
INIT_LIST_HEAD(&skp->smk_rules);
mutex_init(&skp->smk_rules_lock);
list_add_rcu(&skp->list, &smack_known_list);
goto unlockout;
}
kfree(skp);
skp = NULL;
freeout:
kfree(smack);
unlockout:
mutex_unlock(&smack_known_lock);
return skp;
}
char *smk_import(const char *string, int len)
{
struct smack_known *skp;
if (string[0] == '-')
return NULL;
skp = smk_import_entry(string, len);
if (skp == NULL)
return NULL;
return skp->smk_known;
}
char *smack_from_secid(const u32 secid)
{
struct smack_known *skp;
rcu_read_lock();
list_for_each_entry_rcu(skp, &smack_known_list, list) {
if (skp->smk_secid == secid) {
rcu_read_unlock();
return skp->smk_known;
}
}
rcu_read_unlock();
return smack_known_invalid.smk_known;
}
u32 smack_to_secid(const char *smack)
{
struct smack_known *skp = smk_find_entry(smack);
if (skp == NULL)
return 0;
return skp->smk_secid;
}
