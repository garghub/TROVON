static int __init default_policy_setup(char *str)
{
ima_use_tcb = 1;
return 1;
}
static bool ima_match_rules(struct ima_measure_rule_entry *rule,
struct inode *inode, enum ima_hooks func, int mask)
{
struct task_struct *tsk = current;
int i;
if ((rule->flags & IMA_FUNC) && rule->func != func)
return false;
if ((rule->flags & IMA_MASK) && rule->mask != mask)
return false;
if ((rule->flags & IMA_FSMAGIC)
&& rule->fsmagic != inode->i_sb->s_magic)
return false;
if ((rule->flags & IMA_UID) && rule->uid != tsk->cred->uid)
return false;
for (i = 0; i < MAX_LSM_RULES; i++) {
int rc = 0;
u32 osid, sid;
if (!rule->lsm[i].rule)
continue;
switch (i) {
case LSM_OBJ_USER:
case LSM_OBJ_ROLE:
case LSM_OBJ_TYPE:
security_inode_getsecid(inode, &osid);
rc = security_filter_rule_match(osid,
rule->lsm[i].type,
Audit_equal,
rule->lsm[i].rule,
NULL);
break;
case LSM_SUBJ_USER:
case LSM_SUBJ_ROLE:
case LSM_SUBJ_TYPE:
security_task_getsecid(tsk, &sid);
rc = security_filter_rule_match(sid,
rule->lsm[i].type,
Audit_equal,
rule->lsm[i].rule,
NULL);
default:
break;
}
if (!rc)
return false;
}
return true;
}
int ima_match_policy(struct inode *inode, enum ima_hooks func, int mask)
{
struct ima_measure_rule_entry *entry;
list_for_each_entry(entry, ima_measure, list) {
bool rc;
rc = ima_match_rules(entry, inode, func, mask);
if (rc)
return entry->action;
}
return 0;
}
void __init ima_init_policy(void)
{
int i, entries;
if (ima_use_tcb)
entries = ARRAY_SIZE(default_rules);
else
entries = 0;
for (i = 0; i < entries; i++)
list_add_tail(&default_rules[i].list, &measure_default_rules);
ima_measure = &measure_default_rules;
}
void ima_update_policy(void)
{
const char *op = "policy_update";
const char *cause = "already exists";
int result = 1;
int audit_info = 0;
if (ima_measure == &measure_default_rules) {
ima_measure = &measure_policy_rules;
cause = "complete";
result = 0;
}
integrity_audit_msg(AUDIT_INTEGRITY_STATUS, NULL,
NULL, op, cause, result, audit_info);
}
static int ima_lsm_rule_init(struct ima_measure_rule_entry *entry,
char *args, int lsm_rule, int audit_type)
{
int result;
if (entry->lsm[lsm_rule].rule)
return -EINVAL;
entry->lsm[lsm_rule].type = audit_type;
result = security_filter_rule_init(entry->lsm[lsm_rule].type,
Audit_equal, args,
&entry->lsm[lsm_rule].rule);
if (!entry->lsm[lsm_rule].rule)
return -EINVAL;
return result;
}
static void ima_log_string(struct audit_buffer *ab, char *key, char *value)
{
audit_log_format(ab, "%s=", key);
audit_log_untrustedstring(ab, value);
audit_log_format(ab, " ");
}
static int ima_parse_rule(char *rule, struct ima_measure_rule_entry *entry)
{
struct audit_buffer *ab;
char *p;
int result = 0;
ab = audit_log_start(NULL, GFP_KERNEL, AUDIT_INTEGRITY_RULE);
entry->uid = -1;
entry->action = UNKNOWN;
while ((p = strsep(&rule, " \t")) != NULL) {
substring_t args[MAX_OPT_ARGS];
int token;
unsigned long lnum;
if (result < 0)
break;
if ((*p == '\0') || (*p == ' ') || (*p == '\t'))
continue;
token = match_token(p, policy_tokens, args);
switch (token) {
case Opt_measure:
ima_log_string(ab, "action", "measure");
if (entry->action != UNKNOWN)
result = -EINVAL;
entry->action = MEASURE;
break;
case Opt_dont_measure:
ima_log_string(ab, "action", "dont_measure");
if (entry->action != UNKNOWN)
result = -EINVAL;
entry->action = DONT_MEASURE;
break;
case Opt_func:
ima_log_string(ab, "func", args[0].from);
if (entry->func)
result = -EINVAL;
if (strcmp(args[0].from, "FILE_CHECK") == 0)
entry->func = FILE_CHECK;
else if (strcmp(args[0].from, "PATH_CHECK") == 0)
entry->func = FILE_CHECK;
else if (strcmp(args[0].from, "FILE_MMAP") == 0)
entry->func = FILE_MMAP;
else if (strcmp(args[0].from, "BPRM_CHECK") == 0)
entry->func = BPRM_CHECK;
else
result = -EINVAL;
if (!result)
entry->flags |= IMA_FUNC;
break;
case Opt_mask:
ima_log_string(ab, "mask", args[0].from);
if (entry->mask)
result = -EINVAL;
if ((strcmp(args[0].from, "MAY_EXEC")) == 0)
entry->mask = MAY_EXEC;
else if (strcmp(args[0].from, "MAY_WRITE") == 0)
entry->mask = MAY_WRITE;
else if (strcmp(args[0].from, "MAY_READ") == 0)
entry->mask = MAY_READ;
else if (strcmp(args[0].from, "MAY_APPEND") == 0)
entry->mask = MAY_APPEND;
else
result = -EINVAL;
if (!result)
entry->flags |= IMA_MASK;
break;
case Opt_fsmagic:
ima_log_string(ab, "fsmagic", args[0].from);
if (entry->fsmagic) {
result = -EINVAL;
break;
}
result = strict_strtoul(args[0].from, 16,
&entry->fsmagic);
if (!result)
entry->flags |= IMA_FSMAGIC;
break;
case Opt_uid:
ima_log_string(ab, "uid", args[0].from);
if (entry->uid != -1) {
result = -EINVAL;
break;
}
result = strict_strtoul(args[0].from, 10, &lnum);
if (!result) {
entry->uid = (uid_t) lnum;
if (entry->uid != lnum)
result = -EINVAL;
else
entry->flags |= IMA_UID;
}
break;
case Opt_obj_user:
ima_log_string(ab, "obj_user", args[0].from);
result = ima_lsm_rule_init(entry, args[0].from,
LSM_OBJ_USER,
AUDIT_OBJ_USER);
break;
case Opt_obj_role:
ima_log_string(ab, "obj_role", args[0].from);
result = ima_lsm_rule_init(entry, args[0].from,
LSM_OBJ_ROLE,
AUDIT_OBJ_ROLE);
break;
case Opt_obj_type:
ima_log_string(ab, "obj_type", args[0].from);
result = ima_lsm_rule_init(entry, args[0].from,
LSM_OBJ_TYPE,
AUDIT_OBJ_TYPE);
break;
case Opt_subj_user:
ima_log_string(ab, "subj_user", args[0].from);
result = ima_lsm_rule_init(entry, args[0].from,
LSM_SUBJ_USER,
AUDIT_SUBJ_USER);
break;
case Opt_subj_role:
ima_log_string(ab, "subj_role", args[0].from);
result = ima_lsm_rule_init(entry, args[0].from,
LSM_SUBJ_ROLE,
AUDIT_SUBJ_ROLE);
break;
case Opt_subj_type:
ima_log_string(ab, "subj_type", args[0].from);
result = ima_lsm_rule_init(entry, args[0].from,
LSM_SUBJ_TYPE,
AUDIT_SUBJ_TYPE);
break;
case Opt_err:
ima_log_string(ab, "UNKNOWN", p);
result = -EINVAL;
break;
}
}
if (!result && (entry->action == UNKNOWN))
result = -EINVAL;
audit_log_format(ab, "res=%d", !!result);
audit_log_end(ab);
return result;
}
ssize_t ima_parse_add_rule(char *rule)
{
const char *op = "update_policy";
char *p;
struct ima_measure_rule_entry *entry;
ssize_t result, len;
int audit_info = 0;
if (ima_measure != &measure_default_rules) {
integrity_audit_msg(AUDIT_INTEGRITY_STATUS, NULL,
NULL, op, "already exists",
-EACCES, audit_info);
return -EACCES;
}
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry) {
integrity_audit_msg(AUDIT_INTEGRITY_STATUS, NULL,
NULL, op, "-ENOMEM", -ENOMEM, audit_info);
return -ENOMEM;
}
INIT_LIST_HEAD(&entry->list);
p = strsep(&rule, "\n");
len = strlen(p) + 1;
if (*p == '#') {
kfree(entry);
return len;
}
result = ima_parse_rule(p, entry);
if (result) {
kfree(entry);
integrity_audit_msg(AUDIT_INTEGRITY_STATUS, NULL,
NULL, op, "invalid policy", result,
audit_info);
return result;
}
mutex_lock(&ima_measure_mutex);
list_add_tail(&entry->list, &measure_policy_rules);
mutex_unlock(&ima_measure_mutex);
return len;
}
void ima_delete_rules(void)
{
struct ima_measure_rule_entry *entry, *tmp;
mutex_lock(&ima_measure_mutex);
list_for_each_entry_safe(entry, tmp, &measure_policy_rules, list) {
list_del(&entry->list);
kfree(entry);
}
mutex_unlock(&ima_measure_mutex);
}
