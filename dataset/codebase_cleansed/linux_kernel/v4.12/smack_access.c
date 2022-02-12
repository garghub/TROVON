int smk_access_entry(char *subject_label, char *object_label,
struct list_head *rule_list)
{
int may = -ENOENT;
struct smack_rule *srp;
list_for_each_entry_rcu(srp, rule_list, list) {
if (srp->smk_object->smk_known == object_label &&
srp->smk_subject->smk_known == subject_label) {
may = srp->smk_access;
break;
}
}
if ((may & MAY_WRITE) == MAY_WRITE)
may |= MAY_LOCK;
return may;
}
int smk_access(struct smack_known *subject, struct smack_known *object,
int request, struct smk_audit_info *a)
{
int may = MAY_NOT;
int rc = 0;
if (subject == &smack_known_star) {
rc = -EACCES;
goto out_audit;
}
if (object == &smack_known_web || subject == &smack_known_web)
goto out_audit;
if (object == &smack_known_star)
goto out_audit;
if (subject->smk_known == object->smk_known)
goto out_audit;
if ((request & MAY_ANYREAD) == request ||
(request & MAY_LOCK) == request) {
if (object == &smack_known_floor)
goto out_audit;
if (subject == &smack_known_hat)
goto out_audit;
}
rcu_read_lock();
may = smk_access_entry(subject->smk_known, object->smk_known,
&subject->smk_rules);
rcu_read_unlock();
if (may <= 0 || (request & may) != request) {
rc = -EACCES;
goto out_audit;
}
#ifdef CONFIG_SECURITY_SMACK_BRINGUP
if (may & MAY_BRINGUP)
rc = SMACK_BRINGUP_ALLOW;
#endif
out_audit:
#ifdef CONFIG_SECURITY_SMACK_BRINGUP
if (rc < 0) {
if (object == smack_unconfined)
rc = SMACK_UNCONFINED_OBJECT;
if (subject == smack_unconfined)
rc = SMACK_UNCONFINED_SUBJECT;
}
#endif
#ifdef CONFIG_AUDIT
if (a)
smack_log(subject->smk_known, object->smk_known,
request, rc, a);
#endif
return rc;
}
int smk_tskacc(struct task_smack *tsp, struct smack_known *obj_known,
u32 mode, struct smk_audit_info *a)
{
struct smack_known *sbj_known = smk_of_task(tsp);
int may;
int rc;
rc = smk_access(sbj_known, obj_known, mode, NULL);
if (rc >= 0) {
may = smk_access_entry(sbj_known->smk_known,
obj_known->smk_known,
&tsp->smk_rules);
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
smack_log(sbj_known->smk_known, obj_known->smk_known,
mode, rc, a);
#endif
return rc;
}
int smk_curacc(struct smack_known *obj_known,
u32 mode, struct smk_audit_info *a)
{
struct task_smack *tsp = current_security();
return smk_tskacc(tsp, obj_known, mode, a);
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
if (access & MAY_LOCK)
string[i++] = 'l';
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
if (sad->request[0] == '\0')
audit_log_format(ab, " labels_differ");
else
audit_log_format(ab, " requested=%s", sad->request);
}
void smack_log(char *subject_label, char *object_label, int request,
int result, struct smk_audit_info *ad)
{
#ifdef CONFIG_SECURITY_SMACK_BRINGUP
char request_buffer[SMK_NUM_ACCESS_TYPE + 5];
#else
char request_buffer[SMK_NUM_ACCESS_TYPE + 1];
#endif
struct smack_audit_data *sad;
struct common_audit_data *a = &ad->a;
if (result < 0 && (log_policy & SMACK_AUDIT_DENIED) == 0)
return;
if (result == 0 && (log_policy & SMACK_AUDIT_ACCEPT) == 0)
return;
sad = a->smack_audit_data;
if (sad->function == NULL)
sad->function = "unknown";
smack_str_from_perm(request_buffer, request);
sad->subject = subject_label;
sad->object = object_label;
#ifdef CONFIG_SECURITY_SMACK_BRINGUP
if (result == SMACK_UNCONFINED_SUBJECT)
strcat(request_buffer, "(US)");
else if (result == SMACK_UNCONFINED_OBJECT)
strcat(request_buffer, "(UO)");
if (result > 0)
result = 0;
#endif
sad->request = request_buffer;
sad->result = result;
common_lsm_audit(a, smack_log_callback, NULL);
}
void smack_log(char *subject_label, char *object_label, int request,
int result, struct smk_audit_info *ad)
{
}
void smk_insert_entry(struct smack_known *skp)
{
unsigned int hash;
struct hlist_head *head;
hash = full_name_hash(NULL, skp->smk_known, strlen(skp->smk_known));
head = &smack_known_hash[hash & (SMACK_HASH_SLOTS - 1)];
hlist_add_head_rcu(&skp->smk_hashed, head);
list_add_rcu(&skp->list, &smack_known_list);
}
struct smack_known *smk_find_entry(const char *string)
{
unsigned int hash;
struct hlist_head *head;
struct smack_known *skp;
hash = full_name_hash(NULL, string, strlen(string));
head = &smack_known_hash[hash & (SMACK_HASH_SLOTS - 1)];
hlist_for_each_entry_rcu(skp, head, smk_hashed)
if (strcmp(skp->smk_known, string) == 0)
return skp;
return NULL;
}
char *smk_parse_smack(const char *string, int len)
{
char *smack;
int i;
if (len <= 0)
len = strlen(string) + 1;
if (string[0] == '-')
return ERR_PTR(-EINVAL);
for (i = 0; i < len; i++)
if (string[i] > '~' || string[i] <= ' ' || string[i] == '/' ||
string[i] == '"' || string[i] == '\\' || string[i] == '\'')
break;
if (i == 0 || i >= SMK_LONGLABEL)
return ERR_PTR(-EINVAL);
smack = kzalloc(i + 1, GFP_KERNEL);
if (smack == NULL)
return ERR_PTR(-ENOMEM);
strncpy(smack, string, i);
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
sap->attr.mls.cat = NULL;
for (cat = 1, cp = catset, byte = 0; byte < len; cp++, byte++)
for (m = 0x80; m != 0; m >>= 1, cat++) {
if ((m & *cp) == 0)
continue;
rc = netlbl_catmap_setbit(&sap->attr.mls.cat,
cat, GFP_KERNEL);
if (rc < 0) {
netlbl_catmap_free(sap->attr.mls.cat);
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
if (IS_ERR(smack))
return ERR_CAST(smack);
mutex_lock(&smack_known_lock);
skp = smk_find_entry(smack);
if (skp != NULL)
goto freeout;
skp = kzalloc(sizeof(*skp), GFP_KERNEL);
if (skp == NULL) {
skp = ERR_PTR(-ENOMEM);
goto freeout;
}
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
smk_insert_entry(skp);
goto unlockout;
}
kfree(skp);
skp = ERR_PTR(rc);
freeout:
kfree(smack);
unlockout:
mutex_unlock(&smack_known_lock);
return skp;
}
struct smack_known *smack_from_secid(const u32 secid)
{
struct smack_known *skp;
rcu_read_lock();
list_for_each_entry_rcu(skp, &smack_known_list, list) {
if (skp->smk_secid == secid) {
rcu_read_unlock();
return skp;
}
}
rcu_read_unlock();
return &smack_known_huh;
}
int smack_privileged(int cap)
{
struct smack_known *skp = smk_of_current();
struct smack_known_list_elem *sklep;
if (unlikely(current->flags & PF_KTHREAD))
return 1;
if (!capable(cap))
return 0;
rcu_read_lock();
if (list_empty(&smack_onlycap_list)) {
rcu_read_unlock();
return 1;
}
list_for_each_entry_rcu(sklep, &smack_onlycap_list, list) {
if (sklep->smk_label == skp) {
rcu_read_unlock();
return 1;
}
}
rcu_read_unlock();
return 0;
}
