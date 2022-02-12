static int __init default_measure_policy_setup(char *str)
{
if (ima_policy)
return 1;
ima_policy = ORIGINAL_TCB;
return 1;
}
static int __init policy_setup(char *str)
{
if (ima_policy)
return 1;
if (strcmp(str, "tcb") == 0)
ima_policy = DEFAULT_TCB;
return 1;
}
static int __init default_appraise_policy_setup(char *str)
{
ima_use_appraise_tcb = 1;
return 1;
}
static void ima_lsm_update_rules(void)
{
struct ima_rule_entry *entry;
int result;
int i;
list_for_each_entry(entry, &ima_policy_rules, list) {
for (i = 0; i < MAX_LSM_RULES; i++) {
if (!entry->lsm[i].rule)
continue;
result = security_filter_rule_init(entry->lsm[i].type,
Audit_equal,
entry->lsm[i].args_p,
&entry->lsm[i].rule);
BUG_ON(!entry->lsm[i].rule);
}
}
}
static bool ima_match_rules(struct ima_rule_entry *rule, struct inode *inode,
enum ima_hooks func, int mask)
{
struct task_struct *tsk = current;
const struct cred *cred = current_cred();
int i;
if ((rule->flags & IMA_FUNC) &&
(rule->func != func && func != POST_SETATTR))
return false;
if ((rule->flags & IMA_MASK) &&
(rule->mask != mask && func != POST_SETATTR))
return false;
if ((rule->flags & IMA_INMASK) &&
(!(rule->mask & mask) && func != POST_SETATTR))
return false;
if ((rule->flags & IMA_FSMAGIC)
&& rule->fsmagic != inode->i_sb->s_magic)
return false;
if ((rule->flags & IMA_FSUUID) &&
memcmp(rule->fsuuid, inode->i_sb->s_uuid, sizeof(rule->fsuuid)))
return false;
if ((rule->flags & IMA_UID) && !uid_eq(rule->uid, cred->uid))
return false;
if (rule->flags & IMA_EUID) {
if (has_capability_noaudit(current, CAP_SETUID)) {
if (!uid_eq(rule->uid, cred->euid)
&& !uid_eq(rule->uid, cred->suid)
&& !uid_eq(rule->uid, cred->uid))
return false;
} else if (!uid_eq(rule->uid, cred->euid))
return false;
}
if ((rule->flags & IMA_FOWNER) && !uid_eq(rule->fowner, inode->i_uid))
return false;
for (i = 0; i < MAX_LSM_RULES; i++) {
int rc = 0;
u32 osid, sid;
int retried = 0;
if (!rule->lsm[i].rule)
continue;
retry:
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
if ((rc < 0) && (!retried)) {
retried = 1;
ima_lsm_update_rules();
goto retry;
}
if (!rc)
return false;
}
return true;
}
static int get_subaction(struct ima_rule_entry *rule, enum ima_hooks func)
{
if (!(rule->flags & IMA_FUNC))
return IMA_FILE_APPRAISE;
switch (func) {
case MMAP_CHECK:
return IMA_MMAP_APPRAISE;
case BPRM_CHECK:
return IMA_BPRM_APPRAISE;
case FILE_CHECK:
case POST_SETATTR:
return IMA_FILE_APPRAISE;
case MODULE_CHECK ... MAX_CHECK - 1:
default:
return IMA_READ_APPRAISE;
}
}
int ima_match_policy(struct inode *inode, enum ima_hooks func, int mask,
int flags, int *pcr)
{
struct ima_rule_entry *entry;
int action = 0, actmask = flags | (flags << 1);
rcu_read_lock();
list_for_each_entry_rcu(entry, ima_rules, list) {
if (!(entry->action & actmask))
continue;
if (!ima_match_rules(entry, inode, func, mask))
continue;
action |= entry->flags & IMA_ACTION_FLAGS;
action |= entry->action & IMA_DO_MASK;
if (entry->action & IMA_APPRAISE)
action |= get_subaction(entry, func);
if (entry->action & IMA_DO_MASK)
actmask &= ~(entry->action | entry->action << 1);
else
actmask &= ~(entry->action | entry->action >> 1);
if ((pcr) && (entry->flags & IMA_PCR))
*pcr = entry->pcr;
if (!actmask)
break;
}
rcu_read_unlock();
return action;
}
void ima_update_policy_flag(void)
{
struct ima_rule_entry *entry;
list_for_each_entry(entry, ima_rules, list) {
if (entry->action & IMA_DO_MASK)
ima_policy_flag |= entry->action;
}
ima_appraise |= temp_ima_appraise;
if (!ima_appraise)
ima_policy_flag &= ~IMA_APPRAISE;
}
void __init ima_init_policy(void)
{
int i, measure_entries, appraise_entries;
measure_entries = ima_policy ? ARRAY_SIZE(dont_measure_rules) : 0;
appraise_entries = ima_use_appraise_tcb ?
ARRAY_SIZE(default_appraise_rules) : 0;
for (i = 0; i < measure_entries; i++)
list_add_tail(&dont_measure_rules[i].list, &ima_default_rules);
switch (ima_policy) {
case ORIGINAL_TCB:
for (i = 0; i < ARRAY_SIZE(original_measurement_rules); i++)
list_add_tail(&original_measurement_rules[i].list,
&ima_default_rules);
break;
case DEFAULT_TCB:
for (i = 0; i < ARRAY_SIZE(default_measurement_rules); i++)
list_add_tail(&default_measurement_rules[i].list,
&ima_default_rules);
default:
break;
}
for (i = 0; i < appraise_entries; i++) {
list_add_tail(&default_appraise_rules[i].list,
&ima_default_rules);
if (default_appraise_rules[i].func == POLICY_CHECK)
temp_ima_appraise |= IMA_APPRAISE_POLICY;
}
ima_rules = &ima_default_rules;
ima_update_policy_flag();
}
int ima_check_policy(void)
{
if (list_empty(&ima_temp_rules))
return -EINVAL;
return 0;
}
void ima_update_policy(void)
{
struct list_head *first, *last, *policy;
first = (&ima_temp_rules)->next;
last = (&ima_temp_rules)->prev;
policy = &ima_policy_rules;
synchronize_rcu();
last->next = policy;
rcu_assign_pointer(list_next_rcu(policy->prev), first);
first->prev = policy->prev;
policy->prev = last;
INIT_LIST_HEAD(&ima_temp_rules);
if (ima_rules != policy) {
ima_policy_flag = 0;
ima_rules = policy;
}
ima_update_policy_flag();
}
static int ima_lsm_rule_init(struct ima_rule_entry *entry,
substring_t *args, int lsm_rule, int audit_type)
{
int result;
if (entry->lsm[lsm_rule].rule)
return -EINVAL;
entry->lsm[lsm_rule].args_p = match_strdup(args);
if (!entry->lsm[lsm_rule].args_p)
return -ENOMEM;
entry->lsm[lsm_rule].type = audit_type;
result = security_filter_rule_init(entry->lsm[lsm_rule].type,
Audit_equal,
entry->lsm[lsm_rule].args_p,
&entry->lsm[lsm_rule].rule);
if (!entry->lsm[lsm_rule].rule) {
kfree(entry->lsm[lsm_rule].args_p);
return -EINVAL;
}
return result;
}
static void ima_log_string(struct audit_buffer *ab, char *key, char *value)
{
audit_log_format(ab, "%s=", key);
audit_log_untrustedstring(ab, value);
audit_log_format(ab, " ");
}
static int ima_parse_rule(char *rule, struct ima_rule_entry *entry)
{
struct audit_buffer *ab;
char *from;
char *p;
int result = 0;
ab = audit_log_start(NULL, GFP_KERNEL, AUDIT_INTEGRITY_RULE);
entry->uid = INVALID_UID;
entry->fowner = INVALID_UID;
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
case Opt_appraise:
ima_log_string(ab, "action", "appraise");
if (entry->action != UNKNOWN)
result = -EINVAL;
entry->action = APPRAISE;
break;
case Opt_dont_appraise:
ima_log_string(ab, "action", "dont_appraise");
if (entry->action != UNKNOWN)
result = -EINVAL;
entry->action = DONT_APPRAISE;
break;
case Opt_audit:
ima_log_string(ab, "action", "audit");
if (entry->action != UNKNOWN)
result = -EINVAL;
entry->action = AUDIT;
break;
case Opt_func:
ima_log_string(ab, "func", args[0].from);
if (entry->func)
result = -EINVAL;
if (strcmp(args[0].from, "FILE_CHECK") == 0)
entry->func = FILE_CHECK;
else if (strcmp(args[0].from, "PATH_CHECK") == 0)
entry->func = FILE_CHECK;
else if (strcmp(args[0].from, "MODULE_CHECK") == 0)
entry->func = MODULE_CHECK;
else if (strcmp(args[0].from, "FIRMWARE_CHECK") == 0)
entry->func = FIRMWARE_CHECK;
else if ((strcmp(args[0].from, "FILE_MMAP") == 0)
|| (strcmp(args[0].from, "MMAP_CHECK") == 0))
entry->func = MMAP_CHECK;
else if (strcmp(args[0].from, "BPRM_CHECK") == 0)
entry->func = BPRM_CHECK;
else if (strcmp(args[0].from, "KEXEC_KERNEL_CHECK") ==
0)
entry->func = KEXEC_KERNEL_CHECK;
else if (strcmp(args[0].from, "KEXEC_INITRAMFS_CHECK")
== 0)
entry->func = KEXEC_INITRAMFS_CHECK;
else if (strcmp(args[0].from, "POLICY_CHECK") == 0)
entry->func = POLICY_CHECK;
else
result = -EINVAL;
if (!result)
entry->flags |= IMA_FUNC;
break;
case Opt_mask:
ima_log_string(ab, "mask", args[0].from);
if (entry->mask)
result = -EINVAL;
from = args[0].from;
if (*from == '^')
from++;
if ((strcmp(from, "MAY_EXEC")) == 0)
entry->mask = MAY_EXEC;
else if (strcmp(from, "MAY_WRITE") == 0)
entry->mask = MAY_WRITE;
else if (strcmp(from, "MAY_READ") == 0)
entry->mask = MAY_READ;
else if (strcmp(from, "MAY_APPEND") == 0)
entry->mask = MAY_APPEND;
else
result = -EINVAL;
if (!result)
entry->flags |= (*args[0].from == '^')
? IMA_INMASK : IMA_MASK;
break;
case Opt_fsmagic:
ima_log_string(ab, "fsmagic", args[0].from);
if (entry->fsmagic) {
result = -EINVAL;
break;
}
result = kstrtoul(args[0].from, 16, &entry->fsmagic);
if (!result)
entry->flags |= IMA_FSMAGIC;
break;
case Opt_fsuuid:
ima_log_string(ab, "fsuuid", args[0].from);
if (memchr_inv(entry->fsuuid, 0x00,
sizeof(entry->fsuuid))) {
result = -EINVAL;
break;
}
result = blk_part_pack_uuid(args[0].from,
entry->fsuuid);
if (!result)
entry->flags |= IMA_FSUUID;
break;
case Opt_uid:
ima_log_string(ab, "uid", args[0].from);
case Opt_euid:
if (token == Opt_euid)
ima_log_string(ab, "euid", args[0].from);
if (uid_valid(entry->uid)) {
result = -EINVAL;
break;
}
result = kstrtoul(args[0].from, 10, &lnum);
if (!result) {
entry->uid = make_kuid(current_user_ns(),
(uid_t) lnum);
if (!uid_valid(entry->uid) ||
(uid_t)lnum != lnum)
result = -EINVAL;
else
entry->flags |= (token == Opt_uid)
? IMA_UID : IMA_EUID;
}
break;
case Opt_fowner:
ima_log_string(ab, "fowner", args[0].from);
if (uid_valid(entry->fowner)) {
result = -EINVAL;
break;
}
result = kstrtoul(args[0].from, 10, &lnum);
if (!result) {
entry->fowner = make_kuid(current_user_ns(), (uid_t)lnum);
if (!uid_valid(entry->fowner) || (((uid_t)lnum) != lnum))
result = -EINVAL;
else
entry->flags |= IMA_FOWNER;
}
break;
case Opt_obj_user:
ima_log_string(ab, "obj_user", args[0].from);
result = ima_lsm_rule_init(entry, args,
LSM_OBJ_USER,
AUDIT_OBJ_USER);
break;
case Opt_obj_role:
ima_log_string(ab, "obj_role", args[0].from);
result = ima_lsm_rule_init(entry, args,
LSM_OBJ_ROLE,
AUDIT_OBJ_ROLE);
break;
case Opt_obj_type:
ima_log_string(ab, "obj_type", args[0].from);
result = ima_lsm_rule_init(entry, args,
LSM_OBJ_TYPE,
AUDIT_OBJ_TYPE);
break;
case Opt_subj_user:
ima_log_string(ab, "subj_user", args[0].from);
result = ima_lsm_rule_init(entry, args,
LSM_SUBJ_USER,
AUDIT_SUBJ_USER);
break;
case Opt_subj_role:
ima_log_string(ab, "subj_role", args[0].from);
result = ima_lsm_rule_init(entry, args,
LSM_SUBJ_ROLE,
AUDIT_SUBJ_ROLE);
break;
case Opt_subj_type:
ima_log_string(ab, "subj_type", args[0].from);
result = ima_lsm_rule_init(entry, args,
LSM_SUBJ_TYPE,
AUDIT_SUBJ_TYPE);
break;
case Opt_appraise_type:
if (entry->action != APPRAISE) {
result = -EINVAL;
break;
}
ima_log_string(ab, "appraise_type", args[0].from);
if ((strcmp(args[0].from, "imasig")) == 0)
entry->flags |= IMA_DIGSIG_REQUIRED;
else
result = -EINVAL;
break;
case Opt_permit_directio:
entry->flags |= IMA_PERMIT_DIRECTIO;
break;
case Opt_pcr:
if (entry->action != MEASURE) {
result = -EINVAL;
break;
}
ima_log_string(ab, "pcr", args[0].from);
result = kstrtoint(args[0].from, 10, &entry->pcr);
if (result || INVALID_PCR(entry->pcr))
result = -EINVAL;
else
entry->flags |= IMA_PCR;
break;
case Opt_err:
ima_log_string(ab, "UNKNOWN", p);
result = -EINVAL;
break;
}
}
if (!result && (entry->action == UNKNOWN))
result = -EINVAL;
else if (entry->func == MODULE_CHECK)
temp_ima_appraise |= IMA_APPRAISE_MODULES;
else if (entry->func == FIRMWARE_CHECK)
temp_ima_appraise |= IMA_APPRAISE_FIRMWARE;
else if (entry->func == POLICY_CHECK)
temp_ima_appraise |= IMA_APPRAISE_POLICY;
audit_log_format(ab, "res=%d", !result);
audit_log_end(ab);
return result;
}
ssize_t ima_parse_add_rule(char *rule)
{
static const char op[] = "update_policy";
char *p;
struct ima_rule_entry *entry;
ssize_t result, len;
int audit_info = 0;
p = strsep(&rule, "\n");
len = strlen(p) + 1;
p += strspn(p, " \t");
if (*p == '#' || *p == '\0')
return len;
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (!entry) {
integrity_audit_msg(AUDIT_INTEGRITY_STATUS, NULL,
NULL, op, "-ENOMEM", -ENOMEM, audit_info);
return -ENOMEM;
}
INIT_LIST_HEAD(&entry->list);
result = ima_parse_rule(p, entry);
if (result) {
kfree(entry);
integrity_audit_msg(AUDIT_INTEGRITY_STATUS, NULL,
NULL, op, "invalid-policy", result,
audit_info);
return result;
}
list_add_tail(&entry->list, &ima_temp_rules);
return len;
}
void ima_delete_rules(void)
{
struct ima_rule_entry *entry, *tmp;
int i;
temp_ima_appraise = 0;
list_for_each_entry_safe(entry, tmp, &ima_temp_rules, list) {
for (i = 0; i < MAX_LSM_RULES; i++)
kfree(entry->lsm[i].args_p);
list_del(&entry->list);
kfree(entry);
}
}
void *ima_policy_start(struct seq_file *m, loff_t *pos)
{
loff_t l = *pos;
struct ima_rule_entry *entry;
rcu_read_lock();
list_for_each_entry_rcu(entry, ima_rules, list) {
if (!l--) {
rcu_read_unlock();
return entry;
}
}
rcu_read_unlock();
return NULL;
}
void *ima_policy_next(struct seq_file *m, void *v, loff_t *pos)
{
struct ima_rule_entry *entry = v;
rcu_read_lock();
entry = list_entry_rcu(entry->list.next, struct ima_rule_entry, list);
rcu_read_unlock();
(*pos)++;
return (&entry->list == ima_rules) ? NULL : entry;
}
void ima_policy_stop(struct seq_file *m, void *v)
{
}
static void policy_func_show(struct seq_file *m, enum ima_hooks func)
{
char tbuf[64] = {0,};
switch (func) {
case FILE_CHECK:
seq_printf(m, pt(Opt_func), ft(func_file));
break;
case MMAP_CHECK:
seq_printf(m, pt(Opt_func), ft(func_mmap));
break;
case BPRM_CHECK:
seq_printf(m, pt(Opt_func), ft(func_bprm));
break;
case MODULE_CHECK:
seq_printf(m, pt(Opt_func), ft(func_module));
break;
case FIRMWARE_CHECK:
seq_printf(m, pt(Opt_func), ft(func_firmware));
break;
case POST_SETATTR:
seq_printf(m, pt(Opt_func), ft(func_post));
break;
case KEXEC_KERNEL_CHECK:
seq_printf(m, pt(Opt_func), ft(func_kexec_kernel));
break;
case KEXEC_INITRAMFS_CHECK:
seq_printf(m, pt(Opt_func), ft(func_kexec_initramfs));
break;
case POLICY_CHECK:
seq_printf(m, pt(Opt_func), ft(func_policy));
break;
default:
snprintf(tbuf, sizeof(tbuf), "%d", func);
seq_printf(m, pt(Opt_func), tbuf);
break;
}
seq_puts(m, " ");
}
int ima_policy_show(struct seq_file *m, void *v)
{
struct ima_rule_entry *entry = v;
int i;
char tbuf[64] = {0,};
rcu_read_lock();
if (entry->action & MEASURE)
seq_puts(m, pt(Opt_measure));
if (entry->action & DONT_MEASURE)
seq_puts(m, pt(Opt_dont_measure));
if (entry->action & APPRAISE)
seq_puts(m, pt(Opt_appraise));
if (entry->action & DONT_APPRAISE)
seq_puts(m, pt(Opt_dont_appraise));
if (entry->action & AUDIT)
seq_puts(m, pt(Opt_audit));
seq_puts(m, " ");
if (entry->flags & IMA_FUNC)
policy_func_show(m, entry->func);
if (entry->flags & IMA_MASK) {
if (entry->mask & MAY_EXEC)
seq_printf(m, pt(Opt_mask), mt(mask_exec));
if (entry->mask & MAY_WRITE)
seq_printf(m, pt(Opt_mask), mt(mask_write));
if (entry->mask & MAY_READ)
seq_printf(m, pt(Opt_mask), mt(mask_read));
if (entry->mask & MAY_APPEND)
seq_printf(m, pt(Opt_mask), mt(mask_append));
seq_puts(m, " ");
}
if (entry->flags & IMA_FSMAGIC) {
snprintf(tbuf, sizeof(tbuf), "0x%lx", entry->fsmagic);
seq_printf(m, pt(Opt_fsmagic), tbuf);
seq_puts(m, " ");
}
if (entry->flags & IMA_PCR) {
snprintf(tbuf, sizeof(tbuf), "%d", entry->pcr);
seq_printf(m, pt(Opt_pcr), tbuf);
seq_puts(m, " ");
}
if (entry->flags & IMA_FSUUID) {
seq_printf(m, "fsuuid=%pU", entry->fsuuid);
seq_puts(m, " ");
}
if (entry->flags & IMA_UID) {
snprintf(tbuf, sizeof(tbuf), "%d", __kuid_val(entry->uid));
seq_printf(m, pt(Opt_uid), tbuf);
seq_puts(m, " ");
}
if (entry->flags & IMA_EUID) {
snprintf(tbuf, sizeof(tbuf), "%d", __kuid_val(entry->uid));
seq_printf(m, pt(Opt_euid), tbuf);
seq_puts(m, " ");
}
if (entry->flags & IMA_FOWNER) {
snprintf(tbuf, sizeof(tbuf), "%d", __kuid_val(entry->fowner));
seq_printf(m, pt(Opt_fowner), tbuf);
seq_puts(m, " ");
}
for (i = 0; i < MAX_LSM_RULES; i++) {
if (entry->lsm[i].rule) {
switch (i) {
case LSM_OBJ_USER:
seq_printf(m, pt(Opt_obj_user),
(char *)entry->lsm[i].args_p);
break;
case LSM_OBJ_ROLE:
seq_printf(m, pt(Opt_obj_role),
(char *)entry->lsm[i].args_p);
break;
case LSM_OBJ_TYPE:
seq_printf(m, pt(Opt_obj_type),
(char *)entry->lsm[i].args_p);
break;
case LSM_SUBJ_USER:
seq_printf(m, pt(Opt_subj_user),
(char *)entry->lsm[i].args_p);
break;
case LSM_SUBJ_ROLE:
seq_printf(m, pt(Opt_subj_role),
(char *)entry->lsm[i].args_p);
break;
case LSM_SUBJ_TYPE:
seq_printf(m, pt(Opt_subj_type),
(char *)entry->lsm[i].args_p);
break;
}
}
}
if (entry->flags & IMA_DIGSIG_REQUIRED)
seq_puts(m, "appraise_type=imasig ");
if (entry->flags & IMA_PERMIT_DIRECTIO)
seq_puts(m, "permit_directio ");
rcu_read_unlock();
seq_puts(m, "\n");
return 0;
}
