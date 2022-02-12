static inline int open_arg(int flags, int mask)
{
int n = ACC_MODE(flags);
if (flags & (O_TRUNC | O_CREAT))
n |= AUDIT_PERM_WRITE;
return n & mask;
}
static int audit_match_perm(struct audit_context *ctx, int mask)
{
unsigned n;
if (unlikely(!ctx))
return 0;
n = ctx->major;
switch (audit_classify_syscall(ctx->arch, n)) {
case 0:
if ((mask & AUDIT_PERM_WRITE) &&
audit_match_class(AUDIT_CLASS_WRITE, n))
return 1;
if ((mask & AUDIT_PERM_READ) &&
audit_match_class(AUDIT_CLASS_READ, n))
return 1;
if ((mask & AUDIT_PERM_ATTR) &&
audit_match_class(AUDIT_CLASS_CHATTR, n))
return 1;
return 0;
case 1:
if ((mask & AUDIT_PERM_WRITE) &&
audit_match_class(AUDIT_CLASS_WRITE_32, n))
return 1;
if ((mask & AUDIT_PERM_READ) &&
audit_match_class(AUDIT_CLASS_READ_32, n))
return 1;
if ((mask & AUDIT_PERM_ATTR) &&
audit_match_class(AUDIT_CLASS_CHATTR_32, n))
return 1;
return 0;
case 2:
return mask & ACC_MODE(ctx->argv[1]);
case 3:
return mask & ACC_MODE(ctx->argv[2]);
case 4:
return ((mask & AUDIT_PERM_WRITE) && ctx->argv[0] == SYS_BIND);
case 5:
return mask & AUDIT_PERM_EXEC;
default:
return 0;
}
}
static int audit_match_filetype(struct audit_context *ctx, int val)
{
struct audit_names *n;
umode_t mode = (umode_t)val;
if (unlikely(!ctx))
return 0;
list_for_each_entry(n, &ctx->names_list, list) {
if ((n->ino != -1) &&
((n->mode & S_IFMT) == mode))
return 1;
}
return 0;
}
static void audit_set_auditable(struct audit_context *ctx)
{
if (!ctx->prio) {
ctx->prio = 1;
ctx->current_state = AUDIT_RECORD_CONTEXT;
}
}
static int put_tree_ref(struct audit_context *ctx, struct audit_chunk *chunk)
{
struct audit_tree_refs *p = ctx->trees;
int left = ctx->tree_count;
if (likely(left)) {
p->c[--left] = chunk;
ctx->tree_count = left;
return 1;
}
if (!p)
return 0;
p = p->next;
if (p) {
p->c[30] = chunk;
ctx->trees = p;
ctx->tree_count = 30;
return 1;
}
return 0;
}
static int grow_tree_refs(struct audit_context *ctx)
{
struct audit_tree_refs *p = ctx->trees;
ctx->trees = kzalloc(sizeof(struct audit_tree_refs), GFP_KERNEL);
if (!ctx->trees) {
ctx->trees = p;
return 0;
}
if (p)
p->next = ctx->trees;
else
ctx->first_trees = ctx->trees;
ctx->tree_count = 31;
return 1;
}
static void unroll_tree_refs(struct audit_context *ctx,
struct audit_tree_refs *p, int count)
{
#ifdef CONFIG_AUDIT_TREE
struct audit_tree_refs *q;
int n;
if (!p) {
p = ctx->first_trees;
count = 31;
if (!p)
return;
}
n = count;
for (q = p; q != ctx->trees; q = q->next, n = 31) {
while (n--) {
audit_put_chunk(q->c[n]);
q->c[n] = NULL;
}
}
while (n-- > ctx->tree_count) {
audit_put_chunk(q->c[n]);
q->c[n] = NULL;
}
ctx->trees = p;
ctx->tree_count = count;
#endif
}
static void free_tree_refs(struct audit_context *ctx)
{
struct audit_tree_refs *p, *q;
for (p = ctx->first_trees; p; p = q) {
q = p->next;
kfree(p);
}
}
static int match_tree_refs(struct audit_context *ctx, struct audit_tree *tree)
{
#ifdef CONFIG_AUDIT_TREE
struct audit_tree_refs *p;
int n;
if (!tree)
return 0;
for (p = ctx->first_trees; p != ctx->trees; p = p->next) {
for (n = 0; n < 31; n++)
if (audit_tree_match(p->c[n], tree))
return 1;
}
if (p) {
for (n = ctx->tree_count; n < 31; n++)
if (audit_tree_match(p->c[n], tree))
return 1;
}
#endif
return 0;
}
static int audit_compare_uid(kuid_t uid,
struct audit_names *name,
struct audit_field *f,
struct audit_context *ctx)
{
struct audit_names *n;
int rc;
if (name) {
rc = audit_uid_comparator(uid, f->op, name->uid);
if (rc)
return rc;
}
if (ctx) {
list_for_each_entry(n, &ctx->names_list, list) {
rc = audit_uid_comparator(uid, f->op, n->uid);
if (rc)
return rc;
}
}
return 0;
}
static int audit_compare_gid(kgid_t gid,
struct audit_names *name,
struct audit_field *f,
struct audit_context *ctx)
{
struct audit_names *n;
int rc;
if (name) {
rc = audit_gid_comparator(gid, f->op, name->gid);
if (rc)
return rc;
}
if (ctx) {
list_for_each_entry(n, &ctx->names_list, list) {
rc = audit_gid_comparator(gid, f->op, n->gid);
if (rc)
return rc;
}
}
return 0;
}
static int audit_field_compare(struct task_struct *tsk,
const struct cred *cred,
struct audit_field *f,
struct audit_context *ctx,
struct audit_names *name)
{
switch (f->val) {
case AUDIT_COMPARE_UID_TO_OBJ_UID:
return audit_compare_uid(cred->uid, name, f, ctx);
case AUDIT_COMPARE_GID_TO_OBJ_GID:
return audit_compare_gid(cred->gid, name, f, ctx);
case AUDIT_COMPARE_EUID_TO_OBJ_UID:
return audit_compare_uid(cred->euid, name, f, ctx);
case AUDIT_COMPARE_EGID_TO_OBJ_GID:
return audit_compare_gid(cred->egid, name, f, ctx);
case AUDIT_COMPARE_AUID_TO_OBJ_UID:
return audit_compare_uid(tsk->loginuid, name, f, ctx);
case AUDIT_COMPARE_SUID_TO_OBJ_UID:
return audit_compare_uid(cred->suid, name, f, ctx);
case AUDIT_COMPARE_SGID_TO_OBJ_GID:
return audit_compare_gid(cred->sgid, name, f, ctx);
case AUDIT_COMPARE_FSUID_TO_OBJ_UID:
return audit_compare_uid(cred->fsuid, name, f, ctx);
case AUDIT_COMPARE_FSGID_TO_OBJ_GID:
return audit_compare_gid(cred->fsgid, name, f, ctx);
case AUDIT_COMPARE_UID_TO_AUID:
return audit_uid_comparator(cred->uid, f->op, tsk->loginuid);
case AUDIT_COMPARE_UID_TO_EUID:
return audit_uid_comparator(cred->uid, f->op, cred->euid);
case AUDIT_COMPARE_UID_TO_SUID:
return audit_uid_comparator(cred->uid, f->op, cred->suid);
case AUDIT_COMPARE_UID_TO_FSUID:
return audit_uid_comparator(cred->uid, f->op, cred->fsuid);
case AUDIT_COMPARE_AUID_TO_EUID:
return audit_uid_comparator(tsk->loginuid, f->op, cred->euid);
case AUDIT_COMPARE_AUID_TO_SUID:
return audit_uid_comparator(tsk->loginuid, f->op, cred->suid);
case AUDIT_COMPARE_AUID_TO_FSUID:
return audit_uid_comparator(tsk->loginuid, f->op, cred->fsuid);
case AUDIT_COMPARE_EUID_TO_SUID:
return audit_uid_comparator(cred->euid, f->op, cred->suid);
case AUDIT_COMPARE_EUID_TO_FSUID:
return audit_uid_comparator(cred->euid, f->op, cred->fsuid);
case AUDIT_COMPARE_SUID_TO_FSUID:
return audit_uid_comparator(cred->suid, f->op, cred->fsuid);
case AUDIT_COMPARE_GID_TO_EGID:
return audit_gid_comparator(cred->gid, f->op, cred->egid);
case AUDIT_COMPARE_GID_TO_SGID:
return audit_gid_comparator(cred->gid, f->op, cred->sgid);
case AUDIT_COMPARE_GID_TO_FSGID:
return audit_gid_comparator(cred->gid, f->op, cred->fsgid);
case AUDIT_COMPARE_EGID_TO_SGID:
return audit_gid_comparator(cred->egid, f->op, cred->sgid);
case AUDIT_COMPARE_EGID_TO_FSGID:
return audit_gid_comparator(cred->egid, f->op, cred->fsgid);
case AUDIT_COMPARE_SGID_TO_FSGID:
return audit_gid_comparator(cred->sgid, f->op, cred->fsgid);
default:
WARN(1, "Missing AUDIT_COMPARE define. Report as a bug\n");
return 0;
}
return 0;
}
static int audit_filter_rules(struct task_struct *tsk,
struct audit_krule *rule,
struct audit_context *ctx,
struct audit_names *name,
enum audit_state *state,
bool task_creation)
{
const struct cred *cred;
int i, need_sid = 1;
u32 sid;
cred = rcu_dereference_check(tsk->cred, tsk == current || task_creation);
for (i = 0; i < rule->field_count; i++) {
struct audit_field *f = &rule->fields[i];
struct audit_names *n;
int result = 0;
switch (f->type) {
case AUDIT_PID:
result = audit_comparator(tsk->pid, f->op, f->val);
break;
case AUDIT_PPID:
if (ctx) {
if (!ctx->ppid)
ctx->ppid = sys_getppid();
result = audit_comparator(ctx->ppid, f->op, f->val);
}
break;
case AUDIT_UID:
result = audit_uid_comparator(cred->uid, f->op, f->uid);
break;
case AUDIT_EUID:
result = audit_uid_comparator(cred->euid, f->op, f->uid);
break;
case AUDIT_SUID:
result = audit_uid_comparator(cred->suid, f->op, f->uid);
break;
case AUDIT_FSUID:
result = audit_uid_comparator(cred->fsuid, f->op, f->uid);
break;
case AUDIT_GID:
result = audit_gid_comparator(cred->gid, f->op, f->gid);
if (f->op == Audit_equal) {
if (!result)
result = in_group_p(f->gid);
} else if (f->op == Audit_not_equal) {
if (result)
result = !in_group_p(f->gid);
}
break;
case AUDIT_EGID:
result = audit_gid_comparator(cred->egid, f->op, f->gid);
if (f->op == Audit_equal) {
if (!result)
result = in_egroup_p(f->gid);
} else if (f->op == Audit_not_equal) {
if (result)
result = !in_egroup_p(f->gid);
}
break;
case AUDIT_SGID:
result = audit_gid_comparator(cred->sgid, f->op, f->gid);
break;
case AUDIT_FSGID:
result = audit_gid_comparator(cred->fsgid, f->op, f->gid);
break;
case AUDIT_PERS:
result = audit_comparator(tsk->personality, f->op, f->val);
break;
case AUDIT_ARCH:
if (ctx)
result = audit_comparator(ctx->arch, f->op, f->val);
break;
case AUDIT_EXIT:
if (ctx && ctx->return_valid)
result = audit_comparator(ctx->return_code, f->op, f->val);
break;
case AUDIT_SUCCESS:
if (ctx && ctx->return_valid) {
if (f->val)
result = audit_comparator(ctx->return_valid, f->op, AUDITSC_SUCCESS);
else
result = audit_comparator(ctx->return_valid, f->op, AUDITSC_FAILURE);
}
break;
case AUDIT_DEVMAJOR:
if (name) {
if (audit_comparator(MAJOR(name->dev), f->op, f->val) ||
audit_comparator(MAJOR(name->rdev), f->op, f->val))
++result;
} else if (ctx) {
list_for_each_entry(n, &ctx->names_list, list) {
if (audit_comparator(MAJOR(n->dev), f->op, f->val) ||
audit_comparator(MAJOR(n->rdev), f->op, f->val)) {
++result;
break;
}
}
}
break;
case AUDIT_DEVMINOR:
if (name) {
if (audit_comparator(MINOR(name->dev), f->op, f->val) ||
audit_comparator(MINOR(name->rdev), f->op, f->val))
++result;
} else if (ctx) {
list_for_each_entry(n, &ctx->names_list, list) {
if (audit_comparator(MINOR(n->dev), f->op, f->val) ||
audit_comparator(MINOR(n->rdev), f->op, f->val)) {
++result;
break;
}
}
}
break;
case AUDIT_INODE:
if (name)
result = audit_comparator(name->ino, f->op, f->val);
else if (ctx) {
list_for_each_entry(n, &ctx->names_list, list) {
if (audit_comparator(n->ino, f->op, f->val)) {
++result;
break;
}
}
}
break;
case AUDIT_OBJ_UID:
if (name) {
result = audit_uid_comparator(name->uid, f->op, f->uid);
} else if (ctx) {
list_for_each_entry(n, &ctx->names_list, list) {
if (audit_uid_comparator(n->uid, f->op, f->uid)) {
++result;
break;
}
}
}
break;
case AUDIT_OBJ_GID:
if (name) {
result = audit_gid_comparator(name->gid, f->op, f->gid);
} else if (ctx) {
list_for_each_entry(n, &ctx->names_list, list) {
if (audit_gid_comparator(n->gid, f->op, f->gid)) {
++result;
break;
}
}
}
break;
case AUDIT_WATCH:
if (name)
result = audit_watch_compare(rule->watch, name->ino, name->dev);
break;
case AUDIT_DIR:
if (ctx)
result = match_tree_refs(ctx, rule->tree);
break;
case AUDIT_LOGINUID:
result = 0;
if (ctx)
result = audit_uid_comparator(tsk->loginuid, f->op, f->uid);
break;
case AUDIT_LOGINUID_SET:
result = audit_comparator(audit_loginuid_set(tsk), f->op, f->val);
break;
case AUDIT_SUBJ_USER:
case AUDIT_SUBJ_ROLE:
case AUDIT_SUBJ_TYPE:
case AUDIT_SUBJ_SEN:
case AUDIT_SUBJ_CLR:
if (f->lsm_rule) {
if (need_sid) {
security_task_getsecid(tsk, &sid);
need_sid = 0;
}
result = security_audit_rule_match(sid, f->type,
f->op,
f->lsm_rule,
ctx);
}
break;
case AUDIT_OBJ_USER:
case AUDIT_OBJ_ROLE:
case AUDIT_OBJ_TYPE:
case AUDIT_OBJ_LEV_LOW:
case AUDIT_OBJ_LEV_HIGH:
if (f->lsm_rule) {
if (name) {
result = security_audit_rule_match(
name->osid, f->type, f->op,
f->lsm_rule, ctx);
} else if (ctx) {
list_for_each_entry(n, &ctx->names_list, list) {
if (security_audit_rule_match(n->osid, f->type,
f->op, f->lsm_rule,
ctx)) {
++result;
break;
}
}
}
if (!ctx || ctx->type != AUDIT_IPC)
break;
if (security_audit_rule_match(ctx->ipc.osid,
f->type, f->op,
f->lsm_rule, ctx))
++result;
}
break;
case AUDIT_ARG0:
case AUDIT_ARG1:
case AUDIT_ARG2:
case AUDIT_ARG3:
if (ctx)
result = audit_comparator(ctx->argv[f->type-AUDIT_ARG0], f->op, f->val);
break;
case AUDIT_FILTERKEY:
result = 1;
break;
case AUDIT_PERM:
result = audit_match_perm(ctx, f->val);
break;
case AUDIT_FILETYPE:
result = audit_match_filetype(ctx, f->val);
break;
case AUDIT_FIELD_COMPARE:
result = audit_field_compare(tsk, cred, f, ctx, name);
break;
}
if (!result)
return 0;
}
if (ctx) {
if (rule->prio <= ctx->prio)
return 0;
if (rule->filterkey) {
kfree(ctx->filterkey);
ctx->filterkey = kstrdup(rule->filterkey, GFP_ATOMIC);
}
ctx->prio = rule->prio;
}
switch (rule->action) {
case AUDIT_NEVER: *state = AUDIT_DISABLED; break;
case AUDIT_ALWAYS: *state = AUDIT_RECORD_CONTEXT; break;
}
return 1;
}
static enum audit_state audit_filter_task(struct task_struct *tsk, char **key)
{
struct audit_entry *e;
enum audit_state state;
rcu_read_lock();
list_for_each_entry_rcu(e, &audit_filter_list[AUDIT_FILTER_TASK], list) {
if (audit_filter_rules(tsk, &e->rule, NULL, NULL,
&state, true)) {
if (state == AUDIT_RECORD_CONTEXT)
*key = kstrdup(e->rule.filterkey, GFP_ATOMIC);
rcu_read_unlock();
return state;
}
}
rcu_read_unlock();
return AUDIT_BUILD_CONTEXT;
}
static enum audit_state audit_filter_syscall(struct task_struct *tsk,
struct audit_context *ctx,
struct list_head *list)
{
struct audit_entry *e;
enum audit_state state;
if (audit_pid && tsk->tgid == audit_pid)
return AUDIT_DISABLED;
rcu_read_lock();
if (!list_empty(list)) {
int word = AUDIT_WORD(ctx->major);
int bit = AUDIT_BIT(ctx->major);
list_for_each_entry_rcu(e, list, list) {
if ((e->rule.mask[word] & bit) == bit &&
audit_filter_rules(tsk, &e->rule, ctx, NULL,
&state, false)) {
rcu_read_unlock();
ctx->current_state = state;
return state;
}
}
}
rcu_read_unlock();
return AUDIT_BUILD_CONTEXT;
}
static int audit_filter_inode_name(struct task_struct *tsk,
struct audit_names *n,
struct audit_context *ctx) {
int word, bit;
int h = audit_hash_ino((u32)n->ino);
struct list_head *list = &audit_inode_hash[h];
struct audit_entry *e;
enum audit_state state;
word = AUDIT_WORD(ctx->major);
bit = AUDIT_BIT(ctx->major);
if (list_empty(list))
return 0;
list_for_each_entry_rcu(e, list, list) {
if ((e->rule.mask[word] & bit) == bit &&
audit_filter_rules(tsk, &e->rule, ctx, n, &state, false)) {
ctx->current_state = state;
return 1;
}
}
return 0;
}
void audit_filter_inodes(struct task_struct *tsk, struct audit_context *ctx)
{
struct audit_names *n;
if (audit_pid && tsk->tgid == audit_pid)
return;
rcu_read_lock();
list_for_each_entry(n, &ctx->names_list, list) {
if (audit_filter_inode_name(tsk, n, ctx))
break;
}
rcu_read_unlock();
}
static inline struct audit_context *audit_get_context(struct task_struct *tsk,
int return_valid,
long return_code)
{
struct audit_context *context = tsk->audit_context;
if (!context)
return NULL;
context->return_valid = return_valid;
if (unlikely(return_code <= -ERESTARTSYS) &&
(return_code >= -ERESTART_RESTARTBLOCK) &&
(return_code != -ENOIOCTLCMD))
context->return_code = -EINTR;
else
context->return_code = return_code;
if (context->in_syscall && !context->dummy) {
audit_filter_syscall(tsk, context, &audit_filter_list[AUDIT_FILTER_EXIT]);
audit_filter_inodes(tsk, context);
}
tsk->audit_context = NULL;
return context;
}
static inline void audit_free_names(struct audit_context *context)
{
struct audit_names *n, *next;
#if AUDIT_DEBUG == 2
if (context->put_count + context->ino_count != context->name_count) {
int i = 0;
printk(KERN_ERR "%s:%d(:%d): major=%d in_syscall=%d"
" name_count=%d put_count=%d"
" ino_count=%d [NOT freeing]\n",
__FILE__, __LINE__,
context->serial, context->major, context->in_syscall,
context->name_count, context->put_count,
context->ino_count);
list_for_each_entry(n, &context->names_list, list) {
printk(KERN_ERR "names[%d] = %p = %s\n", i++,
n->name, n->name->name ?: "(null)");
}
dump_stack();
return;
}
#endif
#if AUDIT_DEBUG
context->put_count = 0;
context->ino_count = 0;
#endif
list_for_each_entry_safe(n, next, &context->names_list, list) {
list_del(&n->list);
if (n->name && n->name_put)
final_putname(n->name);
if (n->should_free)
kfree(n);
}
context->name_count = 0;
path_put(&context->pwd);
context->pwd.dentry = NULL;
context->pwd.mnt = NULL;
}
static inline void audit_free_aux(struct audit_context *context)
{
struct audit_aux_data *aux;
while ((aux = context->aux)) {
context->aux = aux->next;
kfree(aux);
}
while ((aux = context->aux_pids)) {
context->aux_pids = aux->next;
kfree(aux);
}
}
static inline struct audit_context *audit_alloc_context(enum audit_state state)
{
struct audit_context *context;
context = kzalloc(sizeof(*context), GFP_KERNEL);
if (!context)
return NULL;
context->state = state;
context->prio = state == AUDIT_RECORD_CONTEXT ? ~0ULL : 0;
INIT_LIST_HEAD(&context->killed_trees);
INIT_LIST_HEAD(&context->names_list);
return context;
}
int audit_alloc(struct task_struct *tsk)
{
struct audit_context *context;
enum audit_state state;
char *key = NULL;
if (likely(!audit_ever_enabled))
return 0;
state = audit_filter_task(tsk, &key);
if (state == AUDIT_DISABLED) {
clear_tsk_thread_flag(tsk, TIF_SYSCALL_AUDIT);
return 0;
}
if (!(context = audit_alloc_context(state))) {
kfree(key);
audit_log_lost("out of memory in audit_alloc");
return -ENOMEM;
}
context->filterkey = key;
tsk->audit_context = context;
set_tsk_thread_flag(tsk, TIF_SYSCALL_AUDIT);
return 0;
}
static inline void audit_free_context(struct audit_context *context)
{
audit_free_names(context);
unroll_tree_refs(context, NULL, 0);
free_tree_refs(context);
audit_free_aux(context);
kfree(context->filterkey);
kfree(context->sockaddr);
kfree(context);
}
static int audit_log_pid_context(struct audit_context *context, pid_t pid,
kuid_t auid, kuid_t uid, unsigned int sessionid,
u32 sid, char *comm)
{
struct audit_buffer *ab;
char *ctx = NULL;
u32 len;
int rc = 0;
ab = audit_log_start(context, GFP_KERNEL, AUDIT_OBJ_PID);
if (!ab)
return rc;
audit_log_format(ab, "opid=%d oauid=%d ouid=%d oses=%d", pid,
from_kuid(&init_user_ns, auid),
from_kuid(&init_user_ns, uid), sessionid);
if (sid) {
if (security_secid_to_secctx(sid, &ctx, &len)) {
audit_log_format(ab, " obj=(none)");
rc = 1;
} else {
audit_log_format(ab, " obj=%s", ctx);
security_release_secctx(ctx, len);
}
}
audit_log_format(ab, " ocomm=");
audit_log_untrustedstring(ab, comm);
audit_log_end(ab);
return rc;
}
static int audit_log_single_execve_arg(struct audit_context *context,
struct audit_buffer **ab,
int arg_num,
size_t *len_sent,
const char __user *p,
char *buf)
{
char arg_num_len_buf[12];
const char __user *tmp_p = p;
size_t arg_num_len = snprintf(arg_num_len_buf, 12, "%d", arg_num) + 5;
size_t len, len_left, to_send;
size_t max_execve_audit_len = MAX_EXECVE_AUDIT_LEN;
unsigned int i, has_cntl = 0, too_long = 0;
int ret;
len_left = len = strnlen_user(p, MAX_ARG_STRLEN) - 1;
if (unlikely((len == -1) || len > MAX_ARG_STRLEN - 1)) {
WARN_ON(1);
send_sig(SIGKILL, current, 0);
return -1;
}
do {
if (len_left > MAX_EXECVE_AUDIT_LEN)
to_send = MAX_EXECVE_AUDIT_LEN;
else
to_send = len_left;
ret = copy_from_user(buf, tmp_p, to_send);
if (ret) {
WARN_ON(1);
send_sig(SIGKILL, current, 0);
return -1;
}
buf[to_send] = '\0';
has_cntl = audit_string_contains_control(buf, to_send);
if (has_cntl) {
max_execve_audit_len = MAX_EXECVE_AUDIT_LEN / 2;
break;
}
len_left -= to_send;
tmp_p += to_send;
} while (len_left > 0);
len_left = len;
if (len > max_execve_audit_len)
too_long = 1;
for (i = 0; len_left > 0; i++) {
int room_left;
if (len_left > max_execve_audit_len)
to_send = max_execve_audit_len;
else
to_send = len_left;
room_left = MAX_EXECVE_AUDIT_LEN - arg_num_len - *len_sent;
if (has_cntl)
room_left -= (to_send * 2);
else
room_left -= to_send;
if (room_left < 0) {
*len_sent = 0;
audit_log_end(*ab);
*ab = audit_log_start(context, GFP_KERNEL, AUDIT_EXECVE);
if (!*ab)
return 0;
}
if ((i == 0) && (too_long))
audit_log_format(*ab, " a%d_len=%zu", arg_num,
has_cntl ? 2*len : len);
if (len >= max_execve_audit_len)
ret = copy_from_user(buf, p, to_send);
else
ret = 0;
if (ret) {
WARN_ON(1);
send_sig(SIGKILL, current, 0);
return -1;
}
buf[to_send] = '\0';
audit_log_format(*ab, " a%d", arg_num);
if (too_long)
audit_log_format(*ab, "[%d]", i);
audit_log_format(*ab, "=");
if (has_cntl)
audit_log_n_hex(*ab, buf, to_send);
else
audit_log_string(*ab, buf);
p += to_send;
len_left -= to_send;
*len_sent += arg_num_len;
if (has_cntl)
*len_sent += to_send * 2;
else
*len_sent += to_send;
}
return len + 1;
}
static void audit_log_execve_info(struct audit_context *context,
struct audit_buffer **ab)
{
int i, len;
size_t len_sent = 0;
const char __user *p;
char *buf;
p = (const char __user *)current->mm->arg_start;
audit_log_format(*ab, "argc=%d", context->execve.argc);
buf = kmalloc(MAX_EXECVE_AUDIT_LEN + 1, GFP_KERNEL);
if (!buf) {
audit_panic("out of memory for argv string\n");
return;
}
for (i = 0; i < context->execve.argc; i++) {
len = audit_log_single_execve_arg(context, ab, i,
&len_sent, p, buf);
if (len <= 0)
break;
p += len;
}
kfree(buf);
}
static void show_special(struct audit_context *context, int *call_panic)
{
struct audit_buffer *ab;
int i;
ab = audit_log_start(context, GFP_KERNEL, context->type);
if (!ab)
return;
switch (context->type) {
case AUDIT_SOCKETCALL: {
int nargs = context->socketcall.nargs;
audit_log_format(ab, "nargs=%d", nargs);
for (i = 0; i < nargs; i++)
audit_log_format(ab, " a%d=%lx", i,
context->socketcall.args[i]);
break; }
case AUDIT_IPC: {
u32 osid = context->ipc.osid;
audit_log_format(ab, "ouid=%u ogid=%u mode=%#ho",
from_kuid(&init_user_ns, context->ipc.uid),
from_kgid(&init_user_ns, context->ipc.gid),
context->ipc.mode);
if (osid) {
char *ctx = NULL;
u32 len;
if (security_secid_to_secctx(osid, &ctx, &len)) {
audit_log_format(ab, " osid=%u", osid);
*call_panic = 1;
} else {
audit_log_format(ab, " obj=%s", ctx);
security_release_secctx(ctx, len);
}
}
if (context->ipc.has_perm) {
audit_log_end(ab);
ab = audit_log_start(context, GFP_KERNEL,
AUDIT_IPC_SET_PERM);
if (unlikely(!ab))
return;
audit_log_format(ab,
"qbytes=%lx ouid=%u ogid=%u mode=%#ho",
context->ipc.qbytes,
context->ipc.perm_uid,
context->ipc.perm_gid,
context->ipc.perm_mode);
}
break; }
case AUDIT_MQ_OPEN: {
audit_log_format(ab,
"oflag=0x%x mode=%#ho mq_flags=0x%lx mq_maxmsg=%ld "
"mq_msgsize=%ld mq_curmsgs=%ld",
context->mq_open.oflag, context->mq_open.mode,
context->mq_open.attr.mq_flags,
context->mq_open.attr.mq_maxmsg,
context->mq_open.attr.mq_msgsize,
context->mq_open.attr.mq_curmsgs);
break; }
case AUDIT_MQ_SENDRECV: {
audit_log_format(ab,
"mqdes=%d msg_len=%zd msg_prio=%u "
"abs_timeout_sec=%ld abs_timeout_nsec=%ld",
context->mq_sendrecv.mqdes,
context->mq_sendrecv.msg_len,
context->mq_sendrecv.msg_prio,
context->mq_sendrecv.abs_timeout.tv_sec,
context->mq_sendrecv.abs_timeout.tv_nsec);
break; }
case AUDIT_MQ_NOTIFY: {
audit_log_format(ab, "mqdes=%d sigev_signo=%d",
context->mq_notify.mqdes,
context->mq_notify.sigev_signo);
break; }
case AUDIT_MQ_GETSETATTR: {
struct mq_attr *attr = &context->mq_getsetattr.mqstat;
audit_log_format(ab,
"mqdes=%d mq_flags=0x%lx mq_maxmsg=%ld mq_msgsize=%ld "
"mq_curmsgs=%ld ",
context->mq_getsetattr.mqdes,
attr->mq_flags, attr->mq_maxmsg,
attr->mq_msgsize, attr->mq_curmsgs);
break; }
case AUDIT_CAPSET: {
audit_log_format(ab, "pid=%d", context->capset.pid);
audit_log_cap(ab, "cap_pi", &context->capset.cap.inheritable);
audit_log_cap(ab, "cap_pp", &context->capset.cap.permitted);
audit_log_cap(ab, "cap_pe", &context->capset.cap.effective);
break; }
case AUDIT_MMAP: {
audit_log_format(ab, "fd=%d flags=0x%x", context->mmap.fd,
context->mmap.flags);
break; }
case AUDIT_EXECVE: {
audit_log_execve_info(context, &ab);
break; }
}
audit_log_end(ab);
}
static void audit_log_exit(struct audit_context *context, struct task_struct *tsk)
{
int i, call_panic = 0;
struct audit_buffer *ab;
struct audit_aux_data *aux;
struct audit_names *n;
context->personality = tsk->personality;
ab = audit_log_start(context, GFP_KERNEL, AUDIT_SYSCALL);
if (!ab)
return;
audit_log_format(ab, "arch=%x syscall=%d",
context->arch, context->major);
if (context->personality != PER_LINUX)
audit_log_format(ab, " per=%lx", context->personality);
if (context->return_valid)
audit_log_format(ab, " success=%s exit=%ld",
(context->return_valid==AUDITSC_SUCCESS)?"yes":"no",
context->return_code);
audit_log_format(ab,
" a0=%lx a1=%lx a2=%lx a3=%lx items=%d",
context->argv[0],
context->argv[1],
context->argv[2],
context->argv[3],
context->name_count);
audit_log_task_info(ab, tsk);
audit_log_key(ab, context->filterkey);
audit_log_end(ab);
for (aux = context->aux; aux; aux = aux->next) {
ab = audit_log_start(context, GFP_KERNEL, aux->type);
if (!ab)
continue;
switch (aux->type) {
case AUDIT_BPRM_FCAPS: {
struct audit_aux_data_bprm_fcaps *axs = (void *)aux;
audit_log_format(ab, "fver=%x", axs->fcap_ver);
audit_log_cap(ab, "fp", &axs->fcap.permitted);
audit_log_cap(ab, "fi", &axs->fcap.inheritable);
audit_log_format(ab, " fe=%d", axs->fcap.fE);
audit_log_cap(ab, "old_pp", &axs->old_pcap.permitted);
audit_log_cap(ab, "old_pi", &axs->old_pcap.inheritable);
audit_log_cap(ab, "old_pe", &axs->old_pcap.effective);
audit_log_cap(ab, "new_pp", &axs->new_pcap.permitted);
audit_log_cap(ab, "new_pi", &axs->new_pcap.inheritable);
audit_log_cap(ab, "new_pe", &axs->new_pcap.effective);
break; }
}
audit_log_end(ab);
}
if (context->type)
show_special(context, &call_panic);
if (context->fds[0] >= 0) {
ab = audit_log_start(context, GFP_KERNEL, AUDIT_FD_PAIR);
if (ab) {
audit_log_format(ab, "fd0=%d fd1=%d",
context->fds[0], context->fds[1]);
audit_log_end(ab);
}
}
if (context->sockaddr_len) {
ab = audit_log_start(context, GFP_KERNEL, AUDIT_SOCKADDR);
if (ab) {
audit_log_format(ab, "saddr=");
audit_log_n_hex(ab, (void *)context->sockaddr,
context->sockaddr_len);
audit_log_end(ab);
}
}
for (aux = context->aux_pids; aux; aux = aux->next) {
struct audit_aux_data_pids *axs = (void *)aux;
for (i = 0; i < axs->pid_count; i++)
if (audit_log_pid_context(context, axs->target_pid[i],
axs->target_auid[i],
axs->target_uid[i],
axs->target_sessionid[i],
axs->target_sid[i],
axs->target_comm[i]))
call_panic = 1;
}
if (context->target_pid &&
audit_log_pid_context(context, context->target_pid,
context->target_auid, context->target_uid,
context->target_sessionid,
context->target_sid, context->target_comm))
call_panic = 1;
if (context->pwd.dentry && context->pwd.mnt) {
ab = audit_log_start(context, GFP_KERNEL, AUDIT_CWD);
if (ab) {
audit_log_d_path(ab, " cwd=", &context->pwd);
audit_log_end(ab);
}
}
i = 0;
list_for_each_entry(n, &context->names_list, list) {
if (n->hidden)
continue;
audit_log_name(context, n, NULL, i++, &call_panic);
}
ab = audit_log_start(context, GFP_KERNEL, AUDIT_EOE);
if (ab)
audit_log_end(ab);
if (call_panic)
audit_panic("error converting sid to string");
}
void __audit_free(struct task_struct *tsk)
{
struct audit_context *context;
context = audit_get_context(tsk, 0, 0);
if (!context)
return;
if (context->in_syscall && context->current_state == AUDIT_RECORD_CONTEXT)
audit_log_exit(context, tsk);
if (!list_empty(&context->killed_trees))
audit_kill_trees(&context->killed_trees);
audit_free_context(context);
}
void __audit_syscall_entry(int arch, int major,
unsigned long a1, unsigned long a2,
unsigned long a3, unsigned long a4)
{
struct task_struct *tsk = current;
struct audit_context *context = tsk->audit_context;
enum audit_state state;
if (!context)
return;
BUG_ON(context->in_syscall || context->name_count);
if (!audit_enabled)
return;
context->arch = arch;
context->major = major;
context->argv[0] = a1;
context->argv[1] = a2;
context->argv[2] = a3;
context->argv[3] = a4;
state = context->state;
context->dummy = !audit_n_rules;
if (!context->dummy && state == AUDIT_BUILD_CONTEXT) {
context->prio = 0;
state = audit_filter_syscall(tsk, context, &audit_filter_list[AUDIT_FILTER_ENTRY]);
}
if (state == AUDIT_DISABLED)
return;
context->serial = 0;
context->ctime = CURRENT_TIME;
context->in_syscall = 1;
context->current_state = state;
context->ppid = 0;
}
void __audit_syscall_exit(int success, long return_code)
{
struct task_struct *tsk = current;
struct audit_context *context;
if (success)
success = AUDITSC_SUCCESS;
else
success = AUDITSC_FAILURE;
context = audit_get_context(tsk, success, return_code);
if (!context)
return;
if (context->in_syscall && context->current_state == AUDIT_RECORD_CONTEXT)
audit_log_exit(context, tsk);
context->in_syscall = 0;
context->prio = context->state == AUDIT_RECORD_CONTEXT ? ~0ULL : 0;
if (!list_empty(&context->killed_trees))
audit_kill_trees(&context->killed_trees);
audit_free_names(context);
unroll_tree_refs(context, NULL, 0);
audit_free_aux(context);
context->aux = NULL;
context->aux_pids = NULL;
context->target_pid = 0;
context->target_sid = 0;
context->sockaddr_len = 0;
context->type = 0;
context->fds[0] = -1;
if (context->state != AUDIT_RECORD_CONTEXT) {
kfree(context->filterkey);
context->filterkey = NULL;
}
tsk->audit_context = context;
}
static inline void handle_one(const struct inode *inode)
{
#ifdef CONFIG_AUDIT_TREE
struct audit_context *context;
struct audit_tree_refs *p;
struct audit_chunk *chunk;
int count;
if (likely(hlist_empty(&inode->i_fsnotify_marks)))
return;
context = current->audit_context;
p = context->trees;
count = context->tree_count;
rcu_read_lock();
chunk = audit_tree_lookup(inode);
rcu_read_unlock();
if (!chunk)
return;
if (likely(put_tree_ref(context, chunk)))
return;
if (unlikely(!grow_tree_refs(context))) {
printk(KERN_WARNING "out of memory, audit has lost a tree reference\n");
audit_set_auditable(context);
audit_put_chunk(chunk);
unroll_tree_refs(context, p, count);
return;
}
put_tree_ref(context, chunk);
#endif
}
static void handle_path(const struct dentry *dentry)
{
#ifdef CONFIG_AUDIT_TREE
struct audit_context *context;
struct audit_tree_refs *p;
const struct dentry *d, *parent;
struct audit_chunk *drop;
unsigned long seq;
int count;
context = current->audit_context;
p = context->trees;
count = context->tree_count;
retry:
drop = NULL;
d = dentry;
rcu_read_lock();
seq = read_seqbegin(&rename_lock);
for(;;) {
struct inode *inode = d->d_inode;
if (inode && unlikely(!hlist_empty(&inode->i_fsnotify_marks))) {
struct audit_chunk *chunk;
chunk = audit_tree_lookup(inode);
if (chunk) {
if (unlikely(!put_tree_ref(context, chunk))) {
drop = chunk;
break;
}
}
}
parent = d->d_parent;
if (parent == d)
break;
d = parent;
}
if (unlikely(read_seqretry(&rename_lock, seq) || drop)) {
rcu_read_unlock();
if (!drop) {
unroll_tree_refs(context, p, count);
goto retry;
}
audit_put_chunk(drop);
if (grow_tree_refs(context)) {
unroll_tree_refs(context, p, count);
goto retry;
}
printk(KERN_WARNING
"out of memory, audit has lost a tree reference\n");
unroll_tree_refs(context, p, count);
audit_set_auditable(context);
return;
}
rcu_read_unlock();
#endif
}
static struct audit_names *audit_alloc_name(struct audit_context *context,
unsigned char type)
{
struct audit_names *aname;
if (context->name_count < AUDIT_NAMES) {
aname = &context->preallocated_names[context->name_count];
memset(aname, 0, sizeof(*aname));
} else {
aname = kzalloc(sizeof(*aname), GFP_NOFS);
if (!aname)
return NULL;
aname->should_free = true;
}
aname->ino = (unsigned long)-1;
aname->type = type;
list_add_tail(&aname->list, &context->names_list);
context->name_count++;
#if AUDIT_DEBUG
context->ino_count++;
#endif
return aname;
}
struct filename *
__audit_reusename(const __user char *uptr)
{
struct audit_context *context = current->audit_context;
struct audit_names *n;
list_for_each_entry(n, &context->names_list, list) {
if (!n->name)
continue;
if (n->name->uptr == uptr)
return n->name;
}
return NULL;
}
void __audit_getname(struct filename *name)
{
struct audit_context *context = current->audit_context;
struct audit_names *n;
if (!context->in_syscall) {
#if AUDIT_DEBUG == 2
printk(KERN_ERR "%s:%d(:%d): ignoring getname(%p)\n",
__FILE__, __LINE__, context->serial, name);
dump_stack();
#endif
return;
}
#if AUDIT_DEBUG
BUG_ON(!name->name);
#endif
n = audit_alloc_name(context, AUDIT_TYPE_UNKNOWN);
if (!n)
return;
n->name = name;
n->name_len = AUDIT_NAME_FULL;
n->name_put = true;
name->aname = n;
if (!context->pwd.dentry)
get_fs_pwd(current->fs, &context->pwd);
}
void audit_putname(struct filename *name)
{
struct audit_context *context = current->audit_context;
BUG_ON(!context);
if (!context->in_syscall) {
#if AUDIT_DEBUG == 2
printk(KERN_ERR "%s:%d(:%d): final_putname(%p)\n",
__FILE__, __LINE__, context->serial, name);
if (context->name_count) {
struct audit_names *n;
int i = 0;
list_for_each_entry(n, &context->names_list, list)
printk(KERN_ERR "name[%d] = %p = %s\n", i++,
n->name, n->name->name ?: "(null)");
}
#endif
final_putname(name);
}
#if AUDIT_DEBUG
else {
++context->put_count;
if (context->put_count > context->name_count) {
printk(KERN_ERR "%s:%d(:%d): major=%d"
" in_syscall=%d putname(%p) name_count=%d"
" put_count=%d\n",
__FILE__, __LINE__,
context->serial, context->major,
context->in_syscall, name->name,
context->name_count, context->put_count);
dump_stack();
}
}
#endif
}
void __audit_inode(struct filename *name, const struct dentry *dentry,
unsigned int flags)
{
struct audit_context *context = current->audit_context;
const struct inode *inode = dentry->d_inode;
struct audit_names *n;
bool parent = flags & AUDIT_INODE_PARENT;
if (!context->in_syscall)
return;
if (!name)
goto out_alloc;
#if AUDIT_DEBUG
BUG_ON(!name->name);
#endif
n = name->aname;
if (n) {
if (parent) {
if (n->type == AUDIT_TYPE_PARENT ||
n->type == AUDIT_TYPE_UNKNOWN)
goto out;
} else {
if (n->type != AUDIT_TYPE_PARENT)
goto out;
}
}
list_for_each_entry_reverse(n, &context->names_list, list) {
if (!n->name || n->name->name != name->name)
continue;
if (parent) {
if (n->type == AUDIT_TYPE_PARENT ||
n->type == AUDIT_TYPE_UNKNOWN)
goto out;
} else {
if (n->type != AUDIT_TYPE_PARENT)
goto out;
}
}
out_alloc:
n = audit_alloc_name(context, AUDIT_TYPE_NORMAL);
if (!n)
return;
out:
if (parent) {
n->name_len = n->name ? parent_len(n->name->name) : AUDIT_NAME_FULL;
n->type = AUDIT_TYPE_PARENT;
if (flags & AUDIT_INODE_HIDDEN)
n->hidden = true;
} else {
n->name_len = AUDIT_NAME_FULL;
n->type = AUDIT_TYPE_NORMAL;
}
handle_path(dentry);
audit_copy_inode(n, dentry, inode);
}
void __audit_inode_child(const struct inode *parent,
const struct dentry *dentry,
const unsigned char type)
{
struct audit_context *context = current->audit_context;
const struct inode *inode = dentry->d_inode;
const char *dname = dentry->d_name.name;
struct audit_names *n, *found_parent = NULL, *found_child = NULL;
if (!context->in_syscall)
return;
if (inode)
handle_one(inode);
list_for_each_entry(n, &context->names_list, list) {
if (!n->name || n->type != AUDIT_TYPE_PARENT)
continue;
if (n->ino == parent->i_ino &&
!audit_compare_dname_path(dname, n->name->name, n->name_len)) {
found_parent = n;
break;
}
}
list_for_each_entry(n, &context->names_list, list) {
if (!n->name || n->type != type)
continue;
if (found_parent && (n->name != found_parent->name))
continue;
if (!strcmp(dname, n->name->name) ||
!audit_compare_dname_path(dname, n->name->name,
found_parent ?
found_parent->name_len :
AUDIT_NAME_FULL)) {
found_child = n;
break;
}
}
if (!found_parent) {
n = audit_alloc_name(context, AUDIT_TYPE_PARENT);
if (!n)
return;
audit_copy_inode(n, NULL, parent);
}
if (!found_child) {
found_child = audit_alloc_name(context, type);
if (!found_child)
return;
if (found_parent) {
found_child->name = found_parent->name;
found_child->name_len = AUDIT_NAME_FULL;
found_child->name_put = false;
}
}
if (inode)
audit_copy_inode(found_child, dentry, inode);
else
found_child->ino = (unsigned long)-1;
}
int auditsc_get_stamp(struct audit_context *ctx,
struct timespec *t, unsigned int *serial)
{
if (!ctx->in_syscall)
return 0;
if (!ctx->serial)
ctx->serial = audit_serial();
t->tv_sec = ctx->ctime.tv_sec;
t->tv_nsec = ctx->ctime.tv_nsec;
*serial = ctx->serial;
if (!ctx->prio) {
ctx->prio = 1;
ctx->current_state = AUDIT_RECORD_CONTEXT;
}
return 1;
}
static int audit_set_loginuid_perm(kuid_t loginuid)
{
if (!audit_loginuid_set(current))
return 0;
if (is_audit_feature_set(AUDIT_FEATURE_LOGINUID_IMMUTABLE))
return -EPERM;
if (!capable(CAP_AUDIT_CONTROL))
return -EPERM;
if (is_audit_feature_set(AUDIT_FEATURE_ONLY_UNSET_LOGINUID) && uid_valid(loginuid))
return -EPERM;
return 0;
}
static void audit_log_set_loginuid(kuid_t koldloginuid, kuid_t kloginuid,
unsigned int oldsessionid, unsigned int sessionid,
int rc)
{
struct audit_buffer *ab;
uid_t uid, ologinuid, nloginuid;
uid = from_kuid(&init_user_ns, task_uid(current));
ologinuid = from_kuid(&init_user_ns, koldloginuid);
nloginuid = from_kuid(&init_user_ns, kloginuid),
ab = audit_log_start(NULL, GFP_KERNEL, AUDIT_LOGIN);
if (!ab)
return;
audit_log_format(ab, "pid=%d uid=%u old auid=%u new auid=%u old "
"ses=%u new ses=%u res=%d", current->pid, uid, ologinuid,
nloginuid, oldsessionid, sessionid, !rc);
audit_log_end(ab);
}
int audit_set_loginuid(kuid_t loginuid)
{
struct task_struct *task = current;
unsigned int oldsessionid, sessionid = (unsigned int)-1;
kuid_t oldloginuid;
int rc;
oldloginuid = audit_get_loginuid(current);
oldsessionid = audit_get_sessionid(current);
rc = audit_set_loginuid_perm(loginuid);
if (rc)
goto out;
if (uid_valid(loginuid))
sessionid = atomic_inc_return(&session_id);
task->sessionid = sessionid;
task->loginuid = loginuid;
out:
audit_log_set_loginuid(oldloginuid, loginuid, oldsessionid, sessionid, rc);
return rc;
}
void __audit_mq_open(int oflag, umode_t mode, struct mq_attr *attr)
{
struct audit_context *context = current->audit_context;
if (attr)
memcpy(&context->mq_open.attr, attr, sizeof(struct mq_attr));
else
memset(&context->mq_open.attr, 0, sizeof(struct mq_attr));
context->mq_open.oflag = oflag;
context->mq_open.mode = mode;
context->type = AUDIT_MQ_OPEN;
}
void __audit_mq_sendrecv(mqd_t mqdes, size_t msg_len, unsigned int msg_prio,
const struct timespec *abs_timeout)
{
struct audit_context *context = current->audit_context;
struct timespec *p = &context->mq_sendrecv.abs_timeout;
if (abs_timeout)
memcpy(p, abs_timeout, sizeof(struct timespec));
else
memset(p, 0, sizeof(struct timespec));
context->mq_sendrecv.mqdes = mqdes;
context->mq_sendrecv.msg_len = msg_len;
context->mq_sendrecv.msg_prio = msg_prio;
context->type = AUDIT_MQ_SENDRECV;
}
void __audit_mq_notify(mqd_t mqdes, const struct sigevent *notification)
{
struct audit_context *context = current->audit_context;
if (notification)
context->mq_notify.sigev_signo = notification->sigev_signo;
else
context->mq_notify.sigev_signo = 0;
context->mq_notify.mqdes = mqdes;
context->type = AUDIT_MQ_NOTIFY;
}
void __audit_mq_getsetattr(mqd_t mqdes, struct mq_attr *mqstat)
{
struct audit_context *context = current->audit_context;
context->mq_getsetattr.mqdes = mqdes;
context->mq_getsetattr.mqstat = *mqstat;
context->type = AUDIT_MQ_GETSETATTR;
}
void __audit_ipc_obj(struct kern_ipc_perm *ipcp)
{
struct audit_context *context = current->audit_context;
context->ipc.uid = ipcp->uid;
context->ipc.gid = ipcp->gid;
context->ipc.mode = ipcp->mode;
context->ipc.has_perm = 0;
security_ipc_getsecid(ipcp, &context->ipc.osid);
context->type = AUDIT_IPC;
}
void __audit_ipc_set_perm(unsigned long qbytes, uid_t uid, gid_t gid, umode_t mode)
{
struct audit_context *context = current->audit_context;
context->ipc.qbytes = qbytes;
context->ipc.perm_uid = uid;
context->ipc.perm_gid = gid;
context->ipc.perm_mode = mode;
context->ipc.has_perm = 1;
}
void __audit_bprm(struct linux_binprm *bprm)
{
struct audit_context *context = current->audit_context;
context->type = AUDIT_EXECVE;
context->execve.argc = bprm->argc;
}
int __audit_socketcall(int nargs, unsigned long *args)
{
struct audit_context *context = current->audit_context;
if (nargs <= 0 || nargs > AUDITSC_ARGS || !args)
return -EINVAL;
context->type = AUDIT_SOCKETCALL;
context->socketcall.nargs = nargs;
memcpy(context->socketcall.args, args, nargs * sizeof(unsigned long));
return 0;
}
void __audit_fd_pair(int fd1, int fd2)
{
struct audit_context *context = current->audit_context;
context->fds[0] = fd1;
context->fds[1] = fd2;
}
int __audit_sockaddr(int len, void *a)
{
struct audit_context *context = current->audit_context;
if (!context->sockaddr) {
void *p = kmalloc(sizeof(struct sockaddr_storage), GFP_KERNEL);
if (!p)
return -ENOMEM;
context->sockaddr = p;
}
context->sockaddr_len = len;
memcpy(context->sockaddr, a, len);
return 0;
}
void __audit_ptrace(struct task_struct *t)
{
struct audit_context *context = current->audit_context;
context->target_pid = t->pid;
context->target_auid = audit_get_loginuid(t);
context->target_uid = task_uid(t);
context->target_sessionid = audit_get_sessionid(t);
security_task_getsecid(t, &context->target_sid);
memcpy(context->target_comm, t->comm, TASK_COMM_LEN);
}
int __audit_signal_info(int sig, struct task_struct *t)
{
struct audit_aux_data_pids *axp;
struct task_struct *tsk = current;
struct audit_context *ctx = tsk->audit_context;
kuid_t uid = current_uid(), t_uid = task_uid(t);
if (audit_pid && t->tgid == audit_pid) {
if (sig == SIGTERM || sig == SIGHUP || sig == SIGUSR1 || sig == SIGUSR2) {
audit_sig_pid = tsk->pid;
if (uid_valid(tsk->loginuid))
audit_sig_uid = tsk->loginuid;
else
audit_sig_uid = uid;
security_task_getsecid(tsk, &audit_sig_sid);
}
if (!audit_signals || audit_dummy_context())
return 0;
}
if (!ctx->target_pid) {
ctx->target_pid = t->tgid;
ctx->target_auid = audit_get_loginuid(t);
ctx->target_uid = t_uid;
ctx->target_sessionid = audit_get_sessionid(t);
security_task_getsecid(t, &ctx->target_sid);
memcpy(ctx->target_comm, t->comm, TASK_COMM_LEN);
return 0;
}
axp = (void *)ctx->aux_pids;
if (!axp || axp->pid_count == AUDIT_AUX_PIDS) {
axp = kzalloc(sizeof(*axp), GFP_ATOMIC);
if (!axp)
return -ENOMEM;
axp->d.type = AUDIT_OBJ_PID;
axp->d.next = ctx->aux_pids;
ctx->aux_pids = (void *)axp;
}
BUG_ON(axp->pid_count >= AUDIT_AUX_PIDS);
axp->target_pid[axp->pid_count] = t->tgid;
axp->target_auid[axp->pid_count] = audit_get_loginuid(t);
axp->target_uid[axp->pid_count] = t_uid;
axp->target_sessionid[axp->pid_count] = audit_get_sessionid(t);
security_task_getsecid(t, &axp->target_sid[axp->pid_count]);
memcpy(axp->target_comm[axp->pid_count], t->comm, TASK_COMM_LEN);
axp->pid_count++;
return 0;
}
int __audit_log_bprm_fcaps(struct linux_binprm *bprm,
const struct cred *new, const struct cred *old)
{
struct audit_aux_data_bprm_fcaps *ax;
struct audit_context *context = current->audit_context;
struct cpu_vfs_cap_data vcaps;
struct dentry *dentry;
ax = kmalloc(sizeof(*ax), GFP_KERNEL);
if (!ax)
return -ENOMEM;
ax->d.type = AUDIT_BPRM_FCAPS;
ax->d.next = context->aux;
context->aux = (void *)ax;
dentry = dget(bprm->file->f_dentry);
get_vfs_caps_from_disk(dentry, &vcaps);
dput(dentry);
ax->fcap.permitted = vcaps.permitted;
ax->fcap.inheritable = vcaps.inheritable;
ax->fcap.fE = !!(vcaps.magic_etc & VFS_CAP_FLAGS_EFFECTIVE);
ax->fcap_ver = (vcaps.magic_etc & VFS_CAP_REVISION_MASK) >> VFS_CAP_REVISION_SHIFT;
ax->old_pcap.permitted = old->cap_permitted;
ax->old_pcap.inheritable = old->cap_inheritable;
ax->old_pcap.effective = old->cap_effective;
ax->new_pcap.permitted = new->cap_permitted;
ax->new_pcap.inheritable = new->cap_inheritable;
ax->new_pcap.effective = new->cap_effective;
return 0;
}
void __audit_log_capset(pid_t pid,
const struct cred *new, const struct cred *old)
{
struct audit_context *context = current->audit_context;
context->capset.pid = pid;
context->capset.cap.effective = new->cap_effective;
context->capset.cap.inheritable = new->cap_effective;
context->capset.cap.permitted = new->cap_permitted;
context->type = AUDIT_CAPSET;
}
void __audit_mmap_fd(int fd, int flags)
{
struct audit_context *context = current->audit_context;
context->mmap.fd = fd;
context->mmap.flags = flags;
context->type = AUDIT_MMAP;
}
static void audit_log_task(struct audit_buffer *ab)
{
kuid_t auid, uid;
kgid_t gid;
unsigned int sessionid;
auid = audit_get_loginuid(current);
sessionid = audit_get_sessionid(current);
current_uid_gid(&uid, &gid);
audit_log_format(ab, "auid=%u uid=%u gid=%u ses=%u",
from_kuid(&init_user_ns, auid),
from_kuid(&init_user_ns, uid),
from_kgid(&init_user_ns, gid),
sessionid);
audit_log_task_context(ab);
audit_log_format(ab, " pid=%d comm=", current->pid);
audit_log_untrustedstring(ab, current->comm);
}
static void audit_log_abend(struct audit_buffer *ab, char *reason, long signr)
{
audit_log_task(ab);
audit_log_format(ab, " reason=");
audit_log_string(ab, reason);
audit_log_format(ab, " sig=%ld", signr);
}
void audit_core_dumps(long signr)
{
struct audit_buffer *ab;
if (!audit_enabled)
return;
if (signr == SIGQUIT)
return;
ab = audit_log_start(NULL, GFP_KERNEL, AUDIT_ANOM_ABEND);
if (unlikely(!ab))
return;
audit_log_abend(ab, "memory violation", signr);
audit_log_end(ab);
}
void __audit_seccomp(unsigned long syscall, long signr, int code)
{
struct audit_buffer *ab;
ab = audit_log_start(NULL, GFP_KERNEL, AUDIT_SECCOMP);
if (unlikely(!ab))
return;
audit_log_task(ab);
audit_log_format(ab, " sig=%ld", signr);
audit_log_format(ab, " syscall=%ld", syscall);
audit_log_format(ab, " compat=%d", is_compat_task());
audit_log_format(ab, " ip=0x%lx", KSTK_EIP(current));
audit_log_format(ab, " code=0x%x", code);
audit_log_end(ab);
}
struct list_head *audit_killed_trees(void)
{
struct audit_context *ctx = current->audit_context;
if (likely(!ctx || !ctx->in_syscall))
return NULL;
return &ctx->killed_trees;
}
