static void smk_netlabel_audit_set(struct netlbl_audit *nap)
{
nap->loginuid = audit_get_loginuid(current);
nap->sessionid = audit_get_sessionid(current);
nap->secid = smack_to_secid(smk_of_current());
}
static int smk_set_access(struct smack_rule *srp, struct list_head *rule_list,
struct mutex *rule_lock)
{
struct smack_rule *sp;
int found = 0;
mutex_lock(rule_lock);
list_for_each_entry_rcu(sp, rule_list, list) {
if (sp->smk_object == srp->smk_object &&
sp->smk_subject == srp->smk_subject) {
found = 1;
sp->smk_access = srp->smk_access;
break;
}
}
if (found == 0)
list_add_rcu(&srp->list, rule_list);
mutex_unlock(rule_lock);
return found;
}
static int smk_parse_rule(const char *data, struct smack_rule *rule, int import)
{
char smack[SMK_LABELLEN];
struct smack_known *skp;
if (import) {
rule->smk_subject = smk_import(data, 0);
if (rule->smk_subject == NULL)
return -1;
rule->smk_object = smk_import(data + SMK_LABELLEN, 0);
if (rule->smk_object == NULL)
return -1;
} else {
smk_parse_smack(data, 0, smack);
skp = smk_find_entry(smack);
if (skp == NULL)
return -1;
rule->smk_subject = skp->smk_known;
smk_parse_smack(data + SMK_LABELLEN, 0, smack);
skp = smk_find_entry(smack);
if (skp == NULL)
return -1;
rule->smk_object = skp->smk_known;
}
rule->smk_access = 0;
switch (data[SMK_LABELLEN + SMK_LABELLEN]) {
case '-':
break;
case 'r':
case 'R':
rule->smk_access |= MAY_READ;
break;
default:
return -1;
}
switch (data[SMK_LABELLEN + SMK_LABELLEN + 1]) {
case '-':
break;
case 'w':
case 'W':
rule->smk_access |= MAY_WRITE;
break;
default:
return -1;
}
switch (data[SMK_LABELLEN + SMK_LABELLEN + 2]) {
case '-':
break;
case 'x':
case 'X':
rule->smk_access |= MAY_EXEC;
break;
default:
return -1;
}
switch (data[SMK_LABELLEN + SMK_LABELLEN + 3]) {
case '-':
break;
case 'a':
case 'A':
rule->smk_access |= MAY_APPEND;
break;
default:
return -1;
}
switch (data[SMK_LABELLEN + SMK_LABELLEN + 4]) {
case '-':
break;
case 't':
case 'T':
rule->smk_access |= MAY_TRANSMUTE;
break;
default:
return -1;
}
return 0;
}
static ssize_t smk_write_load_list(struct file *file, const char __user *buf,
size_t count, loff_t *ppos,
struct list_head *rule_list,
struct mutex *rule_lock)
{
struct smack_master_list *smlp;
struct smack_known *skp;
struct smack_rule *rule;
char *data;
int rc = -EINVAL;
int load = 0;
if (*ppos != 0)
return -EINVAL;
if (count < (SMK_OLOADLEN) || count > SMK_LOADLEN)
return -EINVAL;
data = kzalloc(SMK_LOADLEN, GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
if (copy_from_user(data, buf, count) != 0) {
rc = -EFAULT;
goto out;
}
if (count == (SMK_OLOADLEN))
data[SMK_OLOADLEN] = '-';
rule = kzalloc(sizeof(*rule), GFP_KERNEL);
if (rule == NULL) {
rc = -ENOMEM;
goto out;
}
if (smk_parse_rule(data, rule, 1))
goto out_free_rule;
if (rule_list == NULL) {
load = 1;
skp = smk_find_entry(rule->smk_subject);
rule_list = &skp->smk_rules;
rule_lock = &skp->smk_rules_lock;
}
rc = count;
if (load && !smk_set_access(rule, rule_list, rule_lock)) {
smlp = kzalloc(sizeof(*smlp), GFP_KERNEL);
if (smlp != NULL) {
smlp->smk_rule = rule;
list_add_rcu(&smlp->list, &smack_rule_list);
} else
rc = -ENOMEM;
goto out;
}
out_free_rule:
kfree(rule);
out:
kfree(data);
return rc;
}
static void *smk_seq_start(struct seq_file *s, loff_t *pos,
struct list_head *head)
{
struct list_head *list;
if (s->index == 0)
s->private = head;
if (s->private == NULL)
return NULL;
list = s->private;
if (list_empty(list))
return NULL;
if (s->index == 0)
return list->next;
return list;
}
static void *smk_seq_next(struct seq_file *s, void *v, loff_t *pos,
struct list_head *head)
{
struct list_head *list = v;
if (list_is_last(list, head)) {
s->private = NULL;
return NULL;
}
s->private = list->next;
return list->next;
}
static void smk_seq_stop(struct seq_file *s, void *v)
{
}
static void *load_seq_start(struct seq_file *s, loff_t *pos)
{
return smk_seq_start(s, pos, &smack_rule_list);
}
static void *load_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
return smk_seq_next(s, v, pos, &smack_rule_list);
}
static int load_seq_show(struct seq_file *s, void *v)
{
struct list_head *list = v;
struct smack_master_list *smlp =
list_entry(list, struct smack_master_list, list);
struct smack_rule *srp = smlp->smk_rule;
seq_printf(s, "%s %s", (char *)srp->smk_subject,
(char *)srp->smk_object);
seq_putc(s, ' ');
if (srp->smk_access & MAY_READ)
seq_putc(s, 'r');
if (srp->smk_access & MAY_WRITE)
seq_putc(s, 'w');
if (srp->smk_access & MAY_EXEC)
seq_putc(s, 'x');
if (srp->smk_access & MAY_APPEND)
seq_putc(s, 'a');
if (srp->smk_access & MAY_TRANSMUTE)
seq_putc(s, 't');
if (srp->smk_access == 0)
seq_putc(s, '-');
seq_putc(s, '\n');
return 0;
}
static int smk_open_load(struct inode *inode, struct file *file)
{
return seq_open(file, &load_seq_ops);
}
static ssize_t smk_write_load(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
return smk_write_load_list(file, buf, count, ppos, NULL, NULL);
}
static void smk_cipso_doi(void)
{
int rc;
struct cipso_v4_doi *doip;
struct netlbl_audit nai;
smk_netlabel_audit_set(&nai);
rc = netlbl_cfg_map_del(NULL, PF_INET, NULL, NULL, &nai);
if (rc != 0)
printk(KERN_WARNING "%s:%d remove rc = %d\n",
__func__, __LINE__, rc);
doip = kmalloc(sizeof(struct cipso_v4_doi), GFP_KERNEL);
if (doip == NULL)
panic("smack: Failed to initialize cipso DOI.\n");
doip->map.std = NULL;
doip->doi = smk_cipso_doi_value;
doip->type = CIPSO_V4_MAP_PASS;
doip->tags[0] = CIPSO_V4_TAG_RBITMAP;
for (rc = 1; rc < CIPSO_V4_TAG_MAXCNT; rc++)
doip->tags[rc] = CIPSO_V4_TAG_INVALID;
rc = netlbl_cfg_cipsov4_add(doip, &nai);
if (rc != 0) {
printk(KERN_WARNING "%s:%d cipso add rc = %d\n",
__func__, __LINE__, rc);
kfree(doip);
return;
}
rc = netlbl_cfg_cipsov4_map_add(doip->doi, NULL, NULL, NULL, &nai);
if (rc != 0) {
printk(KERN_WARNING "%s:%d map add rc = %d\n",
__func__, __LINE__, rc);
kfree(doip);
return;
}
}
static void smk_unlbl_ambient(char *oldambient)
{
int rc;
struct netlbl_audit nai;
smk_netlabel_audit_set(&nai);
if (oldambient != NULL) {
rc = netlbl_cfg_map_del(oldambient, PF_INET, NULL, NULL, &nai);
if (rc != 0)
printk(KERN_WARNING "%s:%d remove rc = %d\n",
__func__, __LINE__, rc);
}
rc = netlbl_cfg_unlbl_map_add(smack_net_ambient, PF_INET,
NULL, NULL, &nai);
if (rc != 0)
printk(KERN_WARNING "%s:%d add rc = %d\n",
__func__, __LINE__, rc);
}
static void *cipso_seq_start(struct seq_file *s, loff_t *pos)
{
return smk_seq_start(s, pos, &smack_known_list);
}
static void *cipso_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
return smk_seq_next(s, v, pos, &smack_known_list);
}
static int cipso_seq_show(struct seq_file *s, void *v)
{
struct list_head *list = v;
struct smack_known *skp =
list_entry(list, struct smack_known, list);
struct smack_cipso *scp = skp->smk_cipso;
char *cbp;
char sep = '/';
int cat = 1;
int i;
unsigned char m;
if (scp == NULL)
return 0;
seq_printf(s, "%s %3d", (char *)&skp->smk_known, scp->smk_level);
cbp = scp->smk_catset;
for (i = 0; i < SMK_LABELLEN; i++)
for (m = 0x80; m != 0; m >>= 1) {
if (m & cbp[i]) {
seq_printf(s, "%c%d", sep, cat);
sep = ',';
}
cat++;
}
seq_putc(s, '\n');
return 0;
}
static int smk_open_cipso(struct inode *inode, struct file *file)
{
return seq_open(file, &cipso_seq_ops);
}
static ssize_t smk_write_cipso(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct smack_known *skp;
struct smack_cipso *scp = NULL;
char mapcatset[SMK_LABELLEN];
int maplevel;
int cat;
int catlen;
ssize_t rc = -EINVAL;
char *data = NULL;
char *rule;
int ret;
int i;
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
if (*ppos != 0)
return -EINVAL;
if (count < SMK_CIPSOMIN || count > SMK_CIPSOMAX)
return -EINVAL;
data = kzalloc(count + 1, GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
if (copy_from_user(data, buf, count) != 0) {
rc = -EFAULT;
goto unlockedout;
}
if (data[0] == '-') {
rc = -EINVAL;
goto unlockedout;
}
data[count] = '\0';
rule = data;
mutex_lock(&smack_cipso_lock);
skp = smk_import_entry(rule, 0);
if (skp == NULL)
goto out;
rule += SMK_LABELLEN;
ret = sscanf(rule, "%d", &maplevel);
if (ret != 1 || maplevel > SMACK_CIPSO_MAXLEVEL)
goto out;
rule += SMK_DIGITLEN;
ret = sscanf(rule, "%d", &catlen);
if (ret != 1 || catlen > SMACK_CIPSO_MAXCATNUM)
goto out;
if (count != (SMK_CIPSOMIN + catlen * SMK_DIGITLEN))
goto out;
memset(mapcatset, 0, sizeof(mapcatset));
for (i = 0; i < catlen; i++) {
rule += SMK_DIGITLEN;
ret = sscanf(rule, "%d", &cat);
if (ret != 1 || cat > SMACK_CIPSO_MAXCATVAL)
goto out;
smack_catset_bit(cat, mapcatset);
}
if (skp->smk_cipso == NULL) {
scp = kzalloc(sizeof(struct smack_cipso), GFP_KERNEL);
if (scp == NULL) {
rc = -ENOMEM;
goto out;
}
}
spin_lock_bh(&skp->smk_cipsolock);
if (scp == NULL)
scp = skp->smk_cipso;
else
skp->smk_cipso = scp;
scp->smk_level = maplevel;
memcpy(scp->smk_catset, mapcatset, sizeof(mapcatset));
spin_unlock_bh(&skp->smk_cipsolock);
rc = count;
out:
mutex_unlock(&smack_cipso_lock);
unlockedout:
kfree(data);
return rc;
}
static void *netlbladdr_seq_start(struct seq_file *s, loff_t *pos)
{
return smk_seq_start(s, pos, &smk_netlbladdr_list);
}
static void *netlbladdr_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
return smk_seq_next(s, v, pos, &smk_netlbladdr_list);
}
static int netlbladdr_seq_show(struct seq_file *s, void *v)
{
struct list_head *list = v;
struct smk_netlbladdr *skp =
list_entry(list, struct smk_netlbladdr, list);
unsigned char *hp = (char *) &skp->smk_host.sin_addr.s_addr;
int maskn;
u32 temp_mask = be32_to_cpu(skp->smk_mask.s_addr);
for (maskn = 0; temp_mask; temp_mask <<= 1, maskn++);
seq_printf(s, "%u.%u.%u.%u/%d %s\n",
hp[0], hp[1], hp[2], hp[3], maskn, skp->smk_label);
return 0;
}
static int smk_open_netlbladdr(struct inode *inode, struct file *file)
{
return seq_open(file, &netlbladdr_seq_ops);
}
static void smk_netlbladdr_insert(struct smk_netlbladdr *new)
{
struct smk_netlbladdr *m, *m_next;
if (list_empty(&smk_netlbladdr_list)) {
list_add_rcu(&new->list, &smk_netlbladdr_list);
return;
}
m = list_entry_rcu(smk_netlbladdr_list.next,
struct smk_netlbladdr, list);
if (new->smk_mask.s_addr > m->smk_mask.s_addr) {
list_add_rcu(&new->list, &smk_netlbladdr_list);
return;
}
list_for_each_entry_rcu(m, &smk_netlbladdr_list, list) {
if (list_is_last(&m->list, &smk_netlbladdr_list)) {
list_add_rcu(&new->list, &m->list);
return;
}
m_next = list_entry_rcu(m->list.next,
struct smk_netlbladdr, list);
if (new->smk_mask.s_addr > m_next->smk_mask.s_addr) {
list_add_rcu(&new->list, &m->list);
return;
}
}
}
static ssize_t smk_write_netlbladdr(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct smk_netlbladdr *skp;
struct sockaddr_in newname;
char smack[SMK_LABELLEN];
char *sp;
char data[SMK_NETLBLADDRMAX + 1];
char *host = (char *)&newname.sin_addr.s_addr;
int rc;
struct netlbl_audit audit_info;
struct in_addr mask;
unsigned int m;
int found;
u32 mask_bits = (1<<31);
__be32 nsa;
u32 temp_mask;
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
if (*ppos != 0)
return -EINVAL;
if (count < SMK_NETLBLADDRMIN || count > SMK_NETLBLADDRMAX)
return -EINVAL;
if (copy_from_user(data, buf, count) != 0)
return -EFAULT;
data[count] = '\0';
rc = sscanf(data, "%hhd.%hhd.%hhd.%hhd/%d %s",
&host[0], &host[1], &host[2], &host[3], &m, smack);
if (rc != 6) {
rc = sscanf(data, "%hhd.%hhd.%hhd.%hhd %s",
&host[0], &host[1], &host[2], &host[3], smack);
if (rc != 5)
return -EINVAL;
m = BEBITS;
}
if (m > BEBITS)
return -EINVAL;
if (smack[0] != '-') {
sp = smk_import(smack, 0);
if (sp == NULL)
return -EINVAL;
} else {
if (strcmp(smack, smack_cipso_option) == 0)
sp = (char *)smack_cipso_option;
else
return -EINVAL;
}
for (temp_mask = 0; m > 0; m--) {
temp_mask |= mask_bits;
mask_bits >>= 1;
}
mask.s_addr = cpu_to_be32(temp_mask);
newname.sin_addr.s_addr &= mask.s_addr;
mutex_lock(&smk_netlbladdr_lock);
nsa = newname.sin_addr.s_addr;
found = 0;
list_for_each_entry_rcu(skp, &smk_netlbladdr_list, list) {
if (skp->smk_host.sin_addr.s_addr == nsa &&
skp->smk_mask.s_addr == mask.s_addr) {
found = 1;
break;
}
}
smk_netlabel_audit_set(&audit_info);
if (found == 0) {
skp = kzalloc(sizeof(*skp), GFP_KERNEL);
if (skp == NULL)
rc = -ENOMEM;
else {
rc = 0;
skp->smk_host.sin_addr.s_addr = newname.sin_addr.s_addr;
skp->smk_mask.s_addr = mask.s_addr;
skp->smk_label = sp;
smk_netlbladdr_insert(skp);
}
} else {
if (skp->smk_label != smack_cipso_option)
rc = netlbl_cfg_unlbl_static_del(&init_net, NULL,
&skp->smk_host.sin_addr, &skp->smk_mask,
PF_INET, &audit_info);
else
rc = 0;
skp->smk_label = sp;
}
if (rc == 0 && sp != smack_cipso_option)
rc = netlbl_cfg_unlbl_static_add(&init_net, NULL,
&skp->smk_host.sin_addr, &skp->smk_mask, PF_INET,
smack_to_secid(skp->smk_label), &audit_info);
if (rc == 0)
rc = count;
mutex_unlock(&smk_netlbladdr_lock);
return rc;
}
static ssize_t smk_read_doi(struct file *filp, char __user *buf,
size_t count, loff_t *ppos)
{
char temp[80];
ssize_t rc;
if (*ppos != 0)
return 0;
sprintf(temp, "%d", smk_cipso_doi_value);
rc = simple_read_from_buffer(buf, count, ppos, temp, strlen(temp));
return rc;
}
static ssize_t smk_write_doi(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
char temp[80];
int i;
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
if (count >= sizeof(temp) || count == 0)
return -EINVAL;
if (copy_from_user(temp, buf, count) != 0)
return -EFAULT;
temp[count] = '\0';
if (sscanf(temp, "%d", &i) != 1)
return -EINVAL;
smk_cipso_doi_value = i;
smk_cipso_doi();
return count;
}
static ssize_t smk_read_direct(struct file *filp, char __user *buf,
size_t count, loff_t *ppos)
{
char temp[80];
ssize_t rc;
if (*ppos != 0)
return 0;
sprintf(temp, "%d", smack_cipso_direct);
rc = simple_read_from_buffer(buf, count, ppos, temp, strlen(temp));
return rc;
}
static ssize_t smk_write_direct(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
char temp[80];
int i;
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
if (count >= sizeof(temp) || count == 0)
return -EINVAL;
if (copy_from_user(temp, buf, count) != 0)
return -EFAULT;
temp[count] = '\0';
if (sscanf(temp, "%d", &i) != 1)
return -EINVAL;
smack_cipso_direct = i;
return count;
}
static ssize_t smk_read_ambient(struct file *filp, char __user *buf,
size_t cn, loff_t *ppos)
{
ssize_t rc;
int asize;
if (*ppos != 0)
return 0;
mutex_lock(&smack_ambient_lock);
asize = strlen(smack_net_ambient) + 1;
if (cn >= asize)
rc = simple_read_from_buffer(buf, cn, ppos,
smack_net_ambient, asize);
else
rc = -EINVAL;
mutex_unlock(&smack_ambient_lock);
return rc;
}
static ssize_t smk_write_ambient(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
char in[SMK_LABELLEN];
char *oldambient;
char *smack;
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
if (count >= SMK_LABELLEN)
return -EINVAL;
if (copy_from_user(in, buf, count) != 0)
return -EFAULT;
smack = smk_import(in, count);
if (smack == NULL)
return -EINVAL;
mutex_lock(&smack_ambient_lock);
oldambient = smack_net_ambient;
smack_net_ambient = smack;
smk_unlbl_ambient(oldambient);
mutex_unlock(&smack_ambient_lock);
return count;
}
static ssize_t smk_read_onlycap(struct file *filp, char __user *buf,
size_t cn, loff_t *ppos)
{
char *smack = "";
ssize_t rc = -EINVAL;
int asize;
if (*ppos != 0)
return 0;
if (smack_onlycap != NULL)
smack = smack_onlycap;
asize = strlen(smack) + 1;
if (cn >= asize)
rc = simple_read_from_buffer(buf, cn, ppos, smack, asize);
return rc;
}
static ssize_t smk_write_onlycap(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
char in[SMK_LABELLEN];
char *sp = smk_of_task(current->cred->security);
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
if (smack_onlycap != NULL && smack_onlycap != sp)
return -EPERM;
if (count >= SMK_LABELLEN)
return -EINVAL;
if (copy_from_user(in, buf, count) != 0)
return -EFAULT;
smack_onlycap = smk_import(in, count);
return count;
}
static ssize_t smk_read_logging(struct file *filp, char __user *buf,
size_t count, loff_t *ppos)
{
char temp[32];
ssize_t rc;
if (*ppos != 0)
return 0;
sprintf(temp, "%d\n", log_policy);
rc = simple_read_from_buffer(buf, count, ppos, temp, strlen(temp));
return rc;
}
static ssize_t smk_write_logging(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
char temp[32];
int i;
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
if (count >= sizeof(temp) || count == 0)
return -EINVAL;
if (copy_from_user(temp, buf, count) != 0)
return -EFAULT;
temp[count] = '\0';
if (sscanf(temp, "%d", &i) != 1)
return -EINVAL;
if (i < 0 || i > 3)
return -EINVAL;
log_policy = i;
return count;
}
static void *load_self_seq_start(struct seq_file *s, loff_t *pos)
{
struct task_smack *tsp = current_security();
return smk_seq_start(s, pos, &tsp->smk_rules);
}
static void *load_self_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
struct task_smack *tsp = current_security();
return smk_seq_next(s, v, pos, &tsp->smk_rules);
}
static int load_self_seq_show(struct seq_file *s, void *v)
{
struct list_head *list = v;
struct smack_rule *srp =
list_entry(list, struct smack_rule, list);
seq_printf(s, "%s %s", (char *)srp->smk_subject,
(char *)srp->smk_object);
seq_putc(s, ' ');
if (srp->smk_access & MAY_READ)
seq_putc(s, 'r');
if (srp->smk_access & MAY_WRITE)
seq_putc(s, 'w');
if (srp->smk_access & MAY_EXEC)
seq_putc(s, 'x');
if (srp->smk_access & MAY_APPEND)
seq_putc(s, 'a');
if (srp->smk_access & MAY_TRANSMUTE)
seq_putc(s, 't');
if (srp->smk_access == 0)
seq_putc(s, '-');
seq_putc(s, '\n');
return 0;
}
static int smk_open_load_self(struct inode *inode, struct file *file)
{
return seq_open(file, &load_self_seq_ops);
}
static ssize_t smk_write_load_self(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct task_smack *tsp = current_security();
return smk_write_load_list(file, buf, count, ppos, &tsp->smk_rules,
&tsp->smk_rules_lock);
}
static ssize_t smk_write_access(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct smack_rule rule;
char *data;
int res;
data = simple_transaction_get(file, buf, count);
if (IS_ERR(data))
return PTR_ERR(data);
if (count < SMK_LOADLEN || smk_parse_rule(data, &rule, 0))
return -EINVAL;
res = smk_access(rule.smk_subject, rule.smk_object, rule.smk_access,
NULL);
data[0] = res == 0 ? '1' : '0';
data[1] = '\0';
simple_transaction_set(file, 2);
return SMK_LOADLEN;
}
static int smk_fill_super(struct super_block *sb, void *data, int silent)
{
int rc;
struct inode *root_inode;
static struct tree_descr smack_files[] = {
[SMK_LOAD] = {
"load", &smk_load_ops, S_IRUGO|S_IWUSR},
[SMK_CIPSO] = {
"cipso", &smk_cipso_ops, S_IRUGO|S_IWUSR},
[SMK_DOI] = {
"doi", &smk_doi_ops, S_IRUGO|S_IWUSR},
[SMK_DIRECT] = {
"direct", &smk_direct_ops, S_IRUGO|S_IWUSR},
[SMK_AMBIENT] = {
"ambient", &smk_ambient_ops, S_IRUGO|S_IWUSR},
[SMK_NETLBLADDR] = {
"netlabel", &smk_netlbladdr_ops, S_IRUGO|S_IWUSR},
[SMK_ONLYCAP] = {
"onlycap", &smk_onlycap_ops, S_IRUGO|S_IWUSR},
[SMK_LOGGING] = {
"logging", &smk_logging_ops, S_IRUGO|S_IWUSR},
[SMK_LOAD_SELF] = {
"load-self", &smk_load_self_ops, S_IRUGO|S_IWUGO},
[SMK_ACCESSES] = {
"access", &smk_access_ops, S_IRUGO|S_IWUGO},
{""}
};
rc = simple_fill_super(sb, SMACK_MAGIC, smack_files);
if (rc != 0) {
printk(KERN_ERR "%s failed %d while creating inodes\n",
__func__, rc);
return rc;
}
root_inode = sb->s_root->d_inode;
root_inode->i_security = new_inode_smack(smack_known_floor.smk_known);
return 0;
}
static struct dentry *smk_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
return mount_single(fs_type, flags, data, smk_fill_super);
}
static int __init init_smk_fs(void)
{
int err;
if (!security_module_enable(&smack_ops))
return 0;
err = register_filesystem(&smk_fs_type);
if (!err) {
smackfs_mount = kern_mount(&smk_fs_type);
if (IS_ERR(smackfs_mount)) {
printk(KERN_ERR "smackfs: could not mount!\n");
err = PTR_ERR(smackfs_mount);
smackfs_mount = NULL;
}
}
smk_cipso_doi();
smk_unlbl_ambient(NULL);
mutex_init(&smack_known_floor.smk_rules_lock);
mutex_init(&smack_known_hat.smk_rules_lock);
mutex_init(&smack_known_huh.smk_rules_lock);
mutex_init(&smack_known_invalid.smk_rules_lock);
mutex_init(&smack_known_star.smk_rules_lock);
mutex_init(&smack_known_web.smk_rules_lock);
INIT_LIST_HEAD(&smack_known_floor.smk_rules);
INIT_LIST_HEAD(&smack_known_hat.smk_rules);
INIT_LIST_HEAD(&smack_known_huh.smk_rules);
INIT_LIST_HEAD(&smack_known_invalid.smk_rules);
INIT_LIST_HEAD(&smack_known_star.smk_rules);
INIT_LIST_HEAD(&smack_known_web.smk_rules);
return err;
}
