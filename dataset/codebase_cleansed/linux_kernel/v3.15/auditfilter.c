static inline void audit_free_rule(struct audit_entry *e)
{
int i;
struct audit_krule *erule = &e->rule;
if (erule->watch)
audit_put_watch(erule->watch);
if (erule->fields)
for (i = 0; i < erule->field_count; i++) {
struct audit_field *f = &erule->fields[i];
kfree(f->lsm_str);
security_audit_rule_free(f->lsm_rule);
}
kfree(erule->fields);
kfree(erule->filterkey);
kfree(e);
}
void audit_free_rule_rcu(struct rcu_head *head)
{
struct audit_entry *e = container_of(head, struct audit_entry, rcu);
audit_free_rule(e);
}
static inline struct audit_entry *audit_init_entry(u32 field_count)
{
struct audit_entry *entry;
struct audit_field *fields;
entry = kzalloc(sizeof(*entry), GFP_KERNEL);
if (unlikely(!entry))
return NULL;
fields = kzalloc(sizeof(*fields) * field_count, GFP_KERNEL);
if (unlikely(!fields)) {
kfree(entry);
return NULL;
}
entry->rule.fields = fields;
return entry;
}
char *audit_unpack_string(void **bufp, size_t *remain, size_t len)
{
char *str;
if (!*bufp || (len == 0) || (len > *remain))
return ERR_PTR(-EINVAL);
if (len > PATH_MAX)
return ERR_PTR(-ENAMETOOLONG);
str = kmalloc(len + 1, GFP_KERNEL);
if (unlikely(!str))
return ERR_PTR(-ENOMEM);
memcpy(str, *bufp, len);
str[len] = 0;
*bufp += len;
*remain -= len;
return str;
}
static inline int audit_to_inode(struct audit_krule *krule,
struct audit_field *f)
{
if (krule->listnr != AUDIT_FILTER_EXIT ||
krule->watch || krule->inode_f || krule->tree ||
(f->op != Audit_equal && f->op != Audit_not_equal))
return -EINVAL;
krule->inode_f = f;
return 0;
}
int __init audit_register_class(int class, unsigned *list)
{
__u32 *p = kzalloc(AUDIT_BITMASK_SIZE * sizeof(__u32), GFP_KERNEL);
if (!p)
return -ENOMEM;
while (*list != ~0U) {
unsigned n = *list++;
if (n >= AUDIT_BITMASK_SIZE * 32 - AUDIT_SYSCALL_CLASSES) {
kfree(p);
return -EINVAL;
}
p[AUDIT_WORD(n)] |= AUDIT_BIT(n);
}
if (class >= AUDIT_SYSCALL_CLASSES || classes[class]) {
kfree(p);
return -EINVAL;
}
classes[class] = p;
return 0;
}
int audit_match_class(int class, unsigned syscall)
{
if (unlikely(syscall >= AUDIT_BITMASK_SIZE * 32))
return 0;
if (unlikely(class >= AUDIT_SYSCALL_CLASSES || !classes[class]))
return 0;
return classes[class][AUDIT_WORD(syscall)] & AUDIT_BIT(syscall);
}
static inline int audit_match_class_bits(int class, u32 *mask)
{
int i;
if (classes[class]) {
for (i = 0; i < AUDIT_BITMASK_SIZE; i++)
if (mask[i] & classes[class][i])
return 0;
}
return 1;
}
static int audit_match_signal(struct audit_entry *entry)
{
struct audit_field *arch = entry->rule.arch_f;
if (!arch) {
return (audit_match_class_bits(AUDIT_CLASS_SIGNAL,
entry->rule.mask) &&
audit_match_class_bits(AUDIT_CLASS_SIGNAL_32,
entry->rule.mask));
}
switch(audit_classify_arch(arch->val)) {
case 0:
return (audit_match_class_bits(AUDIT_CLASS_SIGNAL,
entry->rule.mask));
case 1:
return (audit_match_class_bits(AUDIT_CLASS_SIGNAL_32,
entry->rule.mask));
default:
return 1;
}
}
static inline struct audit_entry *audit_to_entry_common(struct audit_rule_data *rule)
{
unsigned listnr;
struct audit_entry *entry;
int i, err;
err = -EINVAL;
listnr = rule->flags & ~AUDIT_FILTER_PREPEND;
switch(listnr) {
default:
goto exit_err;
#ifdef CONFIG_AUDITSYSCALL
case AUDIT_FILTER_ENTRY:
if (rule->action == AUDIT_ALWAYS)
goto exit_err;
case AUDIT_FILTER_EXIT:
case AUDIT_FILTER_TASK:
#endif
case AUDIT_FILTER_USER:
case AUDIT_FILTER_TYPE:
;
}
if (unlikely(rule->action == AUDIT_POSSIBLE)) {
pr_err("AUDIT_POSSIBLE is deprecated\n");
goto exit_err;
}
if (rule->action != AUDIT_NEVER && rule->action != AUDIT_ALWAYS)
goto exit_err;
if (rule->field_count > AUDIT_MAX_FIELDS)
goto exit_err;
err = -ENOMEM;
entry = audit_init_entry(rule->field_count);
if (!entry)
goto exit_err;
entry->rule.flags = rule->flags & AUDIT_FILTER_PREPEND;
entry->rule.listnr = listnr;
entry->rule.action = rule->action;
entry->rule.field_count = rule->field_count;
for (i = 0; i < AUDIT_BITMASK_SIZE; i++)
entry->rule.mask[i] = rule->mask[i];
for (i = 0; i < AUDIT_SYSCALL_CLASSES; i++) {
int bit = AUDIT_BITMASK_SIZE * 32 - i - 1;
__u32 *p = &entry->rule.mask[AUDIT_WORD(bit)];
__u32 *class;
if (!(*p & AUDIT_BIT(bit)))
continue;
*p &= ~AUDIT_BIT(bit);
class = classes[i];
if (class) {
int j;
for (j = 0; j < AUDIT_BITMASK_SIZE; j++)
entry->rule.mask[j] |= class[j];
}
}
return entry;
exit_err:
return ERR_PTR(err);
}
static u32 audit_to_op(u32 op)
{
u32 n;
for (n = Audit_equal; n < Audit_bad && audit_ops[n] != op; n++)
;
return n;
}
static int audit_field_valid(struct audit_entry *entry, struct audit_field *f)
{
switch(f->type) {
case AUDIT_MSGTYPE:
if (entry->rule.listnr != AUDIT_FILTER_TYPE &&
entry->rule.listnr != AUDIT_FILTER_USER)
return -EINVAL;
break;
};
switch(f->type) {
default:
return -EINVAL;
case AUDIT_UID:
case AUDIT_EUID:
case AUDIT_SUID:
case AUDIT_FSUID:
case AUDIT_LOGINUID:
case AUDIT_OBJ_UID:
case AUDIT_GID:
case AUDIT_EGID:
case AUDIT_SGID:
case AUDIT_FSGID:
case AUDIT_OBJ_GID:
case AUDIT_PID:
case AUDIT_PERS:
case AUDIT_MSGTYPE:
case AUDIT_PPID:
case AUDIT_DEVMAJOR:
case AUDIT_DEVMINOR:
case AUDIT_EXIT:
case AUDIT_SUCCESS:
case AUDIT_INODE:
if (f->op == Audit_bitmask || f->op == Audit_bittest)
return -EINVAL;
break;
case AUDIT_ARG0:
case AUDIT_ARG1:
case AUDIT_ARG2:
case AUDIT_ARG3:
case AUDIT_SUBJ_USER:
case AUDIT_SUBJ_ROLE:
case AUDIT_SUBJ_TYPE:
case AUDIT_SUBJ_SEN:
case AUDIT_SUBJ_CLR:
case AUDIT_OBJ_USER:
case AUDIT_OBJ_ROLE:
case AUDIT_OBJ_TYPE:
case AUDIT_OBJ_LEV_LOW:
case AUDIT_OBJ_LEV_HIGH:
case AUDIT_WATCH:
case AUDIT_DIR:
case AUDIT_FILTERKEY:
break;
case AUDIT_LOGINUID_SET:
if ((f->val != 0) && (f->val != 1))
return -EINVAL;
case AUDIT_ARCH:
if (f->op != Audit_not_equal && f->op != Audit_equal)
return -EINVAL;
break;
case AUDIT_PERM:
if (f->val & ~15)
return -EINVAL;
break;
case AUDIT_FILETYPE:
if (f->val & ~S_IFMT)
return -EINVAL;
break;
case AUDIT_FIELD_COMPARE:
if (f->val > AUDIT_MAX_FIELD_COMPARE)
return -EINVAL;
break;
};
return 0;
}
static struct audit_entry *audit_data_to_entry(struct audit_rule_data *data,
size_t datasz)
{
int err = 0;
struct audit_entry *entry;
void *bufp;
size_t remain = datasz - sizeof(struct audit_rule_data);
int i;
char *str;
entry = audit_to_entry_common(data);
if (IS_ERR(entry))
goto exit_nofree;
bufp = data->buf;
entry->rule.vers_ops = 2;
for (i = 0; i < data->field_count; i++) {
struct audit_field *f = &entry->rule.fields[i];
err = -EINVAL;
f->op = audit_to_op(data->fieldflags[i]);
if (f->op == Audit_bad)
goto exit_free;
f->type = data->fields[i];
f->val = data->values[i];
f->uid = INVALID_UID;
f->gid = INVALID_GID;
f->lsm_str = NULL;
f->lsm_rule = NULL;
if ((f->type == AUDIT_LOGINUID) && (f->val == AUDIT_UID_UNSET)) {
f->type = AUDIT_LOGINUID_SET;
f->val = 0;
}
if ((f->type == AUDIT_PID) || (f->type == AUDIT_PPID)) {
struct pid *pid;
rcu_read_lock();
pid = find_vpid(f->val);
if (!pid) {
rcu_read_unlock();
err = -ESRCH;
goto exit_free;
}
f->val = pid_nr(pid);
rcu_read_unlock();
}
err = audit_field_valid(entry, f);
if (err)
goto exit_free;
err = -EINVAL;
switch (f->type) {
case AUDIT_LOGINUID:
case AUDIT_UID:
case AUDIT_EUID:
case AUDIT_SUID:
case AUDIT_FSUID:
case AUDIT_OBJ_UID:
f->uid = make_kuid(current_user_ns(), f->val);
if (!uid_valid(f->uid))
goto exit_free;
break;
case AUDIT_GID:
case AUDIT_EGID:
case AUDIT_SGID:
case AUDIT_FSGID:
case AUDIT_OBJ_GID:
f->gid = make_kgid(current_user_ns(), f->val);
if (!gid_valid(f->gid))
goto exit_free;
break;
case AUDIT_ARCH:
entry->rule.arch_f = f;
break;
case AUDIT_SUBJ_USER:
case AUDIT_SUBJ_ROLE:
case AUDIT_SUBJ_TYPE:
case AUDIT_SUBJ_SEN:
case AUDIT_SUBJ_CLR:
case AUDIT_OBJ_USER:
case AUDIT_OBJ_ROLE:
case AUDIT_OBJ_TYPE:
case AUDIT_OBJ_LEV_LOW:
case AUDIT_OBJ_LEV_HIGH:
str = audit_unpack_string(&bufp, &remain, f->val);
if (IS_ERR(str))
goto exit_free;
entry->rule.buflen += f->val;
err = security_audit_rule_init(f->type, f->op, str,
(void **)&f->lsm_rule);
if (err == -EINVAL) {
pr_warn("audit rule for LSM \'%s\' is invalid\n",
str);
err = 0;
}
if (err) {
kfree(str);
goto exit_free;
} else
f->lsm_str = str;
break;
case AUDIT_WATCH:
str = audit_unpack_string(&bufp, &remain, f->val);
if (IS_ERR(str))
goto exit_free;
entry->rule.buflen += f->val;
err = audit_to_watch(&entry->rule, str, f->val, f->op);
if (err) {
kfree(str);
goto exit_free;
}
break;
case AUDIT_DIR:
str = audit_unpack_string(&bufp, &remain, f->val);
if (IS_ERR(str))
goto exit_free;
entry->rule.buflen += f->val;
err = audit_make_tree(&entry->rule, str, f->op);
kfree(str);
if (err)
goto exit_free;
break;
case AUDIT_INODE:
err = audit_to_inode(&entry->rule, f);
if (err)
goto exit_free;
break;
case AUDIT_FILTERKEY:
if (entry->rule.filterkey || f->val > AUDIT_MAX_KEY_LEN)
goto exit_free;
str = audit_unpack_string(&bufp, &remain, f->val);
if (IS_ERR(str))
goto exit_free;
entry->rule.buflen += f->val;
entry->rule.filterkey = str;
break;
}
}
if (entry->rule.inode_f && entry->rule.inode_f->op == Audit_not_equal)
entry->rule.inode_f = NULL;
exit_nofree:
return entry;
exit_free:
if (entry->rule.watch)
audit_put_watch(entry->rule.watch);
if (entry->rule.tree)
audit_put_tree(entry->rule.tree);
audit_free_rule(entry);
return ERR_PTR(err);
}
static inline size_t audit_pack_string(void **bufp, const char *str)
{
size_t len = strlen(str);
memcpy(*bufp, str, len);
*bufp += len;
return len;
}
static struct audit_rule_data *audit_krule_to_data(struct audit_krule *krule)
{
struct audit_rule_data *data;
void *bufp;
int i;
data = kmalloc(sizeof(*data) + krule->buflen, GFP_KERNEL);
if (unlikely(!data))
return NULL;
memset(data, 0, sizeof(*data));
data->flags = krule->flags | krule->listnr;
data->action = krule->action;
data->field_count = krule->field_count;
bufp = data->buf;
for (i = 0; i < data->field_count; i++) {
struct audit_field *f = &krule->fields[i];
data->fields[i] = f->type;
data->fieldflags[i] = audit_ops[f->op];
switch(f->type) {
case AUDIT_SUBJ_USER:
case AUDIT_SUBJ_ROLE:
case AUDIT_SUBJ_TYPE:
case AUDIT_SUBJ_SEN:
case AUDIT_SUBJ_CLR:
case AUDIT_OBJ_USER:
case AUDIT_OBJ_ROLE:
case AUDIT_OBJ_TYPE:
case AUDIT_OBJ_LEV_LOW:
case AUDIT_OBJ_LEV_HIGH:
data->buflen += data->values[i] =
audit_pack_string(&bufp, f->lsm_str);
break;
case AUDIT_WATCH:
data->buflen += data->values[i] =
audit_pack_string(&bufp,
audit_watch_path(krule->watch));
break;
case AUDIT_DIR:
data->buflen += data->values[i] =
audit_pack_string(&bufp,
audit_tree_path(krule->tree));
break;
case AUDIT_FILTERKEY:
data->buflen += data->values[i] =
audit_pack_string(&bufp, krule->filterkey);
break;
default:
data->values[i] = f->val;
}
}
for (i = 0; i < AUDIT_BITMASK_SIZE; i++) data->mask[i] = krule->mask[i];
return data;
}
static int audit_compare_rule(struct audit_krule *a, struct audit_krule *b)
{
int i;
if (a->flags != b->flags ||
a->listnr != b->listnr ||
a->action != b->action ||
a->field_count != b->field_count)
return 1;
for (i = 0; i < a->field_count; i++) {
if (a->fields[i].type != b->fields[i].type ||
a->fields[i].op != b->fields[i].op)
return 1;
switch(a->fields[i].type) {
case AUDIT_SUBJ_USER:
case AUDIT_SUBJ_ROLE:
case AUDIT_SUBJ_TYPE:
case AUDIT_SUBJ_SEN:
case AUDIT_SUBJ_CLR:
case AUDIT_OBJ_USER:
case AUDIT_OBJ_ROLE:
case AUDIT_OBJ_TYPE:
case AUDIT_OBJ_LEV_LOW:
case AUDIT_OBJ_LEV_HIGH:
if (strcmp(a->fields[i].lsm_str, b->fields[i].lsm_str))
return 1;
break;
case AUDIT_WATCH:
if (strcmp(audit_watch_path(a->watch),
audit_watch_path(b->watch)))
return 1;
break;
case AUDIT_DIR:
if (strcmp(audit_tree_path(a->tree),
audit_tree_path(b->tree)))
return 1;
break;
case AUDIT_FILTERKEY:
if (strcmp(a->filterkey, b->filterkey))
return 1;
break;
case AUDIT_UID:
case AUDIT_EUID:
case AUDIT_SUID:
case AUDIT_FSUID:
case AUDIT_LOGINUID:
case AUDIT_OBJ_UID:
if (!uid_eq(a->fields[i].uid, b->fields[i].uid))
return 1;
break;
case AUDIT_GID:
case AUDIT_EGID:
case AUDIT_SGID:
case AUDIT_FSGID:
case AUDIT_OBJ_GID:
if (!gid_eq(a->fields[i].gid, b->fields[i].gid))
return 1;
break;
default:
if (a->fields[i].val != b->fields[i].val)
return 1;
}
}
for (i = 0; i < AUDIT_BITMASK_SIZE; i++)
if (a->mask[i] != b->mask[i])
return 1;
return 0;
}
static inline int audit_dupe_lsm_field(struct audit_field *df,
struct audit_field *sf)
{
int ret = 0;
char *lsm_str;
lsm_str = kstrdup(sf->lsm_str, GFP_KERNEL);
if (unlikely(!lsm_str))
return -ENOMEM;
df->lsm_str = lsm_str;
ret = security_audit_rule_init(df->type, df->op, df->lsm_str,
(void **)&df->lsm_rule);
if (ret == -EINVAL) {
pr_warn("audit rule for LSM \'%s\' is invalid\n",
df->lsm_str);
ret = 0;
}
return ret;
}
struct audit_entry *audit_dupe_rule(struct audit_krule *old)
{
u32 fcount = old->field_count;
struct audit_entry *entry;
struct audit_krule *new;
char *fk;
int i, err = 0;
entry = audit_init_entry(fcount);
if (unlikely(!entry))
return ERR_PTR(-ENOMEM);
new = &entry->rule;
new->vers_ops = old->vers_ops;
new->flags = old->flags;
new->listnr = old->listnr;
new->action = old->action;
for (i = 0; i < AUDIT_BITMASK_SIZE; i++)
new->mask[i] = old->mask[i];
new->prio = old->prio;
new->buflen = old->buflen;
new->inode_f = old->inode_f;
new->field_count = old->field_count;
new->tree = old->tree;
memcpy(new->fields, old->fields, sizeof(struct audit_field) * fcount);
for (i = 0; i < fcount; i++) {
switch (new->fields[i].type) {
case AUDIT_SUBJ_USER:
case AUDIT_SUBJ_ROLE:
case AUDIT_SUBJ_TYPE:
case AUDIT_SUBJ_SEN:
case AUDIT_SUBJ_CLR:
case AUDIT_OBJ_USER:
case AUDIT_OBJ_ROLE:
case AUDIT_OBJ_TYPE:
case AUDIT_OBJ_LEV_LOW:
case AUDIT_OBJ_LEV_HIGH:
err = audit_dupe_lsm_field(&new->fields[i],
&old->fields[i]);
break;
case AUDIT_FILTERKEY:
fk = kstrdup(old->filterkey, GFP_KERNEL);
if (unlikely(!fk))
err = -ENOMEM;
else
new->filterkey = fk;
}
if (err) {
audit_free_rule(entry);
return ERR_PTR(err);
}
}
if (old->watch) {
audit_get_watch(old->watch);
new->watch = old->watch;
}
return entry;
}
static struct audit_entry *audit_find_rule(struct audit_entry *entry,
struct list_head **p)
{
struct audit_entry *e, *found = NULL;
struct list_head *list;
int h;
if (entry->rule.inode_f) {
h = audit_hash_ino(entry->rule.inode_f->val);
*p = list = &audit_inode_hash[h];
} else if (entry->rule.watch) {
for (h = 0; h < AUDIT_INODE_BUCKETS; h++) {
list = &audit_inode_hash[h];
list_for_each_entry(e, list, list)
if (!audit_compare_rule(&entry->rule, &e->rule)) {
found = e;
goto out;
}
}
goto out;
} else {
*p = list = &audit_filter_list[entry->rule.listnr];
}
list_for_each_entry(e, list, list)
if (!audit_compare_rule(&entry->rule, &e->rule)) {
found = e;
goto out;
}
out:
return found;
}
static inline int audit_add_rule(struct audit_entry *entry)
{
struct audit_entry *e;
struct audit_watch *watch = entry->rule.watch;
struct audit_tree *tree = entry->rule.tree;
struct list_head *list;
int err;
#ifdef CONFIG_AUDITSYSCALL
int dont_count = 0;
if (entry->rule.listnr == AUDIT_FILTER_USER ||
entry->rule.listnr == AUDIT_FILTER_TYPE)
dont_count = 1;
#endif
mutex_lock(&audit_filter_mutex);
e = audit_find_rule(entry, &list);
if (e) {
mutex_unlock(&audit_filter_mutex);
err = -EEXIST;
if (tree)
audit_put_tree(tree);
goto error;
}
if (watch) {
err = audit_add_watch(&entry->rule, &list);
if (err) {
mutex_unlock(&audit_filter_mutex);
if (tree)
audit_put_tree(tree);
goto error;
}
}
if (tree) {
err = audit_add_tree_rule(&entry->rule);
if (err) {
mutex_unlock(&audit_filter_mutex);
goto error;
}
}
entry->rule.prio = ~0ULL;
if (entry->rule.listnr == AUDIT_FILTER_EXIT) {
if (entry->rule.flags & AUDIT_FILTER_PREPEND)
entry->rule.prio = ++prio_high;
else
entry->rule.prio = --prio_low;
}
if (entry->rule.flags & AUDIT_FILTER_PREPEND) {
list_add(&entry->rule.list,
&audit_rules_list[entry->rule.listnr]);
list_add_rcu(&entry->list, list);
entry->rule.flags &= ~AUDIT_FILTER_PREPEND;
} else {
list_add_tail(&entry->rule.list,
&audit_rules_list[entry->rule.listnr]);
list_add_tail_rcu(&entry->list, list);
}
#ifdef CONFIG_AUDITSYSCALL
if (!dont_count)
audit_n_rules++;
if (!audit_match_signal(entry))
audit_signals++;
#endif
mutex_unlock(&audit_filter_mutex);
return 0;
error:
if (watch)
audit_put_watch(watch);
return err;
}
static inline int audit_del_rule(struct audit_entry *entry)
{
struct audit_entry *e;
struct audit_watch *watch = entry->rule.watch;
struct audit_tree *tree = entry->rule.tree;
struct list_head *list;
int ret = 0;
#ifdef CONFIG_AUDITSYSCALL
int dont_count = 0;
if (entry->rule.listnr == AUDIT_FILTER_USER ||
entry->rule.listnr == AUDIT_FILTER_TYPE)
dont_count = 1;
#endif
mutex_lock(&audit_filter_mutex);
e = audit_find_rule(entry, &list);
if (!e) {
mutex_unlock(&audit_filter_mutex);
ret = -ENOENT;
goto out;
}
if (e->rule.watch)
audit_remove_watch_rule(&e->rule);
if (e->rule.tree)
audit_remove_tree_rule(&e->rule);
list_del_rcu(&e->list);
list_del(&e->rule.list);
call_rcu(&e->rcu, audit_free_rule_rcu);
#ifdef CONFIG_AUDITSYSCALL
if (!dont_count)
audit_n_rules--;
if (!audit_match_signal(entry))
audit_signals--;
#endif
mutex_unlock(&audit_filter_mutex);
out:
if (watch)
audit_put_watch(watch);
if (tree)
audit_put_tree(tree);
return ret;
}
static void audit_list_rules(__u32 portid, int seq, struct sk_buff_head *q)
{
struct sk_buff *skb;
struct audit_krule *r;
int i;
for (i=0; i<AUDIT_NR_FILTERS; i++) {
list_for_each_entry(r, &audit_rules_list[i], list) {
struct audit_rule_data *data;
data = audit_krule_to_data(r);
if (unlikely(!data))
break;
skb = audit_make_reply(portid, seq, AUDIT_LIST_RULES,
0, 1, data,
sizeof(*data) + data->buflen);
if (skb)
skb_queue_tail(q, skb);
kfree(data);
}
}
skb = audit_make_reply(portid, seq, AUDIT_LIST_RULES, 1, 1, NULL, 0);
if (skb)
skb_queue_tail(q, skb);
}
static void audit_log_rule_change(char *action, struct audit_krule *rule, int res)
{
struct audit_buffer *ab;
uid_t loginuid = from_kuid(&init_user_ns, audit_get_loginuid(current));
unsigned int sessionid = audit_get_sessionid(current);
if (!audit_enabled)
return;
ab = audit_log_start(NULL, GFP_KERNEL, AUDIT_CONFIG_CHANGE);
if (!ab)
return;
audit_log_format(ab, "auid=%u ses=%u" ,loginuid, sessionid);
audit_log_task_context(ab);
audit_log_format(ab, " op=");
audit_log_string(ab, action);
audit_log_key(ab, rule->filterkey);
audit_log_format(ab, " list=%d res=%d", rule->listnr, res);
audit_log_end(ab);
}
int audit_rule_change(int type, __u32 portid, int seq, void *data,
size_t datasz)
{
int err = 0;
struct audit_entry *entry;
switch (type) {
case AUDIT_ADD_RULE:
entry = audit_data_to_entry(data, datasz);
if (IS_ERR(entry))
return PTR_ERR(entry);
err = audit_add_rule(entry);
audit_log_rule_change("add rule", &entry->rule, !err);
if (err)
audit_free_rule(entry);
break;
case AUDIT_DEL_RULE:
entry = audit_data_to_entry(data, datasz);
if (IS_ERR(entry))
return PTR_ERR(entry);
err = audit_del_rule(entry);
audit_log_rule_change("remove rule", &entry->rule, !err);
audit_free_rule(entry);
break;
default:
return -EINVAL;
}
return err;
}
int audit_list_rules_send(struct sk_buff *request_skb, int seq)
{
u32 portid = NETLINK_CB(request_skb).portid;
struct net *net = sock_net(NETLINK_CB(request_skb).sk);
struct task_struct *tsk;
struct audit_netlink_list *dest;
int err = 0;
dest = kmalloc(sizeof(struct audit_netlink_list), GFP_KERNEL);
if (!dest)
return -ENOMEM;
dest->net = get_net(net);
dest->portid = portid;
skb_queue_head_init(&dest->q);
mutex_lock(&audit_filter_mutex);
audit_list_rules(portid, seq, &dest->q);
mutex_unlock(&audit_filter_mutex);
tsk = kthread_run(audit_send_list, dest, "audit_send_list");
if (IS_ERR(tsk)) {
skb_queue_purge(&dest->q);
kfree(dest);
err = PTR_ERR(tsk);
}
return err;
}
int audit_comparator(u32 left, u32 op, u32 right)
{
switch (op) {
case Audit_equal:
return (left == right);
case Audit_not_equal:
return (left != right);
case Audit_lt:
return (left < right);
case Audit_le:
return (left <= right);
case Audit_gt:
return (left > right);
case Audit_ge:
return (left >= right);
case Audit_bitmask:
return (left & right);
case Audit_bittest:
return ((left & right) == right);
default:
BUG();
return 0;
}
}
int audit_uid_comparator(kuid_t left, u32 op, kuid_t right)
{
switch (op) {
case Audit_equal:
return uid_eq(left, right);
case Audit_not_equal:
return !uid_eq(left, right);
case Audit_lt:
return uid_lt(left, right);
case Audit_le:
return uid_lte(left, right);
case Audit_gt:
return uid_gt(left, right);
case Audit_ge:
return uid_gte(left, right);
case Audit_bitmask:
case Audit_bittest:
default:
BUG();
return 0;
}
}
int audit_gid_comparator(kgid_t left, u32 op, kgid_t right)
{
switch (op) {
case Audit_equal:
return gid_eq(left, right);
case Audit_not_equal:
return !gid_eq(left, right);
case Audit_lt:
return gid_lt(left, right);
case Audit_le:
return gid_lte(left, right);
case Audit_gt:
return gid_gt(left, right);
case Audit_ge:
return gid_gte(left, right);
case Audit_bitmask:
case Audit_bittest:
default:
BUG();
return 0;
}
}
int parent_len(const char *path)
{
int plen;
const char *p;
plen = strlen(path);
if (plen == 0)
return plen;
p = path + plen - 1;
while ((*p == '/') && (p > path))
p--;
while ((*p != '/') && (p > path))
p--;
if (*p == '/')
p++;
return p - path;
}
int audit_compare_dname_path(const char *dname, const char *path, int parentlen)
{
int dlen, pathlen;
const char *p;
dlen = strlen(dname);
pathlen = strlen(path);
if (pathlen < dlen)
return 1;
parentlen = parentlen == AUDIT_NAME_FULL ? parent_len(path) : parentlen;
if (pathlen - parentlen != dlen)
return 1;
p = path + parentlen;
return strncmp(p, dname, dlen);
}
static int audit_filter_user_rules(struct audit_krule *rule, int type,
enum audit_state *state)
{
int i;
for (i = 0; i < rule->field_count; i++) {
struct audit_field *f = &rule->fields[i];
pid_t pid;
int result = 0;
u32 sid;
switch (f->type) {
case AUDIT_PID:
pid = task_pid_nr(current);
result = audit_comparator(pid, f->op, f->val);
break;
case AUDIT_UID:
result = audit_uid_comparator(current_uid(), f->op, f->uid);
break;
case AUDIT_GID:
result = audit_gid_comparator(current_gid(), f->op, f->gid);
break;
case AUDIT_LOGINUID:
result = audit_uid_comparator(audit_get_loginuid(current),
f->op, f->uid);
break;
case AUDIT_LOGINUID_SET:
result = audit_comparator(audit_loginuid_set(current),
f->op, f->val);
break;
case AUDIT_MSGTYPE:
result = audit_comparator(type, f->op, f->val);
break;
case AUDIT_SUBJ_USER:
case AUDIT_SUBJ_ROLE:
case AUDIT_SUBJ_TYPE:
case AUDIT_SUBJ_SEN:
case AUDIT_SUBJ_CLR:
if (f->lsm_rule) {
security_task_getsecid(current, &sid);
result = security_audit_rule_match(sid,
f->type,
f->op,
f->lsm_rule,
NULL);
}
break;
}
if (!result)
return 0;
}
switch (rule->action) {
case AUDIT_NEVER: *state = AUDIT_DISABLED; break;
case AUDIT_ALWAYS: *state = AUDIT_RECORD_CONTEXT; break;
}
return 1;
}
int audit_filter_user(int type)
{
enum audit_state state = AUDIT_DISABLED;
struct audit_entry *e;
int rc, ret;
ret = 1;
rcu_read_lock();
list_for_each_entry_rcu(e, &audit_filter_list[AUDIT_FILTER_USER], list) {
rc = audit_filter_user_rules(&e->rule, type, &state);
if (rc) {
if (rc > 0 && state == AUDIT_DISABLED)
ret = 0;
break;
}
}
rcu_read_unlock();
return ret;
}
int audit_filter_type(int type)
{
struct audit_entry *e;
int result = 0;
rcu_read_lock();
if (list_empty(&audit_filter_list[AUDIT_FILTER_TYPE]))
goto unlock_and_return;
list_for_each_entry_rcu(e, &audit_filter_list[AUDIT_FILTER_TYPE],
list) {
int i;
for (i = 0; i < e->rule.field_count; i++) {
struct audit_field *f = &e->rule.fields[i];
if (f->type == AUDIT_MSGTYPE) {
result = audit_comparator(type, f->op, f->val);
if (!result)
break;
}
}
if (result)
goto unlock_and_return;
}
unlock_and_return:
rcu_read_unlock();
return result;
}
static int update_lsm_rule(struct audit_krule *r)
{
struct audit_entry *entry = container_of(r, struct audit_entry, rule);
struct audit_entry *nentry;
int err = 0;
if (!security_audit_rule_known(r))
return 0;
nentry = audit_dupe_rule(r);
if (IS_ERR(nentry)) {
err = PTR_ERR(nentry);
audit_panic("error updating LSM filters");
if (r->watch)
list_del(&r->rlist);
list_del_rcu(&entry->list);
list_del(&r->list);
} else {
if (r->watch || r->tree)
list_replace_init(&r->rlist, &nentry->rule.rlist);
list_replace_rcu(&entry->list, &nentry->list);
list_replace(&r->list, &nentry->rule.list);
}
call_rcu(&entry->rcu, audit_free_rule_rcu);
return err;
}
int audit_update_lsm_rules(void)
{
struct audit_krule *r, *n;
int i, err = 0;
mutex_lock(&audit_filter_mutex);
for (i = 0; i < AUDIT_NR_FILTERS; i++) {
list_for_each_entry_safe(r, n, &audit_rules_list[i], list) {
int res = update_lsm_rule(r);
if (!err)
err = res;
}
}
mutex_unlock(&audit_filter_mutex);
return err;
}
