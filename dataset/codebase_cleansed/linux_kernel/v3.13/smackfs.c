static inline void smack_catset_bit(unsigned int cat, char *catsetp)
{
if (cat == 0 || cat > (SMK_CIPSOLEN * 8))
return;
catsetp[(cat - 1) / 8] |= 0x80 >> ((cat - 1) % 8);
}
static void smk_netlabel_audit_set(struct netlbl_audit *nap)
{
struct smack_known *skp = smk_of_current();
nap->loginuid = audit_get_loginuid(current);
nap->sessionid = audit_get_sessionid(current);
nap->secid = skp->smk_secid;
}
static int smk_set_access(struct smack_parsed_rule *srp,
struct list_head *rule_list,
struct mutex *rule_lock, int global)
{
struct smack_rule *sp;
struct smack_master_list *smlp;
int found = 0;
int rc = 0;
mutex_lock(rule_lock);
list_for_each_entry_rcu(sp, rule_list, list) {
if (sp->smk_object == srp->smk_object &&
sp->smk_subject == srp->smk_subject) {
found = 1;
sp->smk_access |= srp->smk_access1;
sp->smk_access &= ~srp->smk_access2;
break;
}
}
if (found == 0) {
sp = kzalloc(sizeof(*sp), GFP_KERNEL);
if (sp == NULL) {
rc = -ENOMEM;
goto out;
}
sp->smk_subject = srp->smk_subject;
sp->smk_object = srp->smk_object;
sp->smk_access = srp->smk_access1 & ~srp->smk_access2;
list_add_rcu(&sp->list, rule_list);
if (global) {
smlp = kzalloc(sizeof(*smlp), GFP_KERNEL);
if (smlp != NULL) {
smlp->smk_rule = sp;
list_add_rcu(&smlp->list, &smack_rule_list);
} else
rc = -ENOMEM;
}
}
out:
mutex_unlock(rule_lock);
return rc;
}
static int smk_perm_from_str(const char *string)
{
int perm = 0;
const char *cp;
for (cp = string; ; cp++)
switch (*cp) {
case '-':
break;
case 'r':
case 'R':
perm |= MAY_READ;
break;
case 'w':
case 'W':
perm |= MAY_WRITE;
break;
case 'x':
case 'X':
perm |= MAY_EXEC;
break;
case 'a':
case 'A':
perm |= MAY_APPEND;
break;
case 't':
case 'T':
perm |= MAY_TRANSMUTE;
break;
case 'l':
case 'L':
perm |= MAY_LOCK;
break;
default:
return perm;
}
}
static int smk_fill_rule(const char *subject, const char *object,
const char *access1, const char *access2,
struct smack_parsed_rule *rule, int import,
int len)
{
const char *cp;
struct smack_known *skp;
if (import) {
rule->smk_subject = smk_import_entry(subject, len);
if (rule->smk_subject == NULL)
return -1;
rule->smk_object = smk_import(object, len);
if (rule->smk_object == NULL)
return -1;
} else {
cp = smk_parse_smack(subject, len);
if (cp == NULL)
return -1;
skp = smk_find_entry(cp);
kfree(cp);
if (skp == NULL)
return -1;
rule->smk_subject = skp;
cp = smk_parse_smack(object, len);
if (cp == NULL)
return -1;
skp = smk_find_entry(cp);
kfree(cp);
if (skp == NULL)
return -1;
rule->smk_object = skp->smk_known;
}
rule->smk_access1 = smk_perm_from_str(access1);
if (access2)
rule->smk_access2 = smk_perm_from_str(access2);
else
rule->smk_access2 = ~rule->smk_access1;
return 0;
}
static int smk_parse_rule(const char *data, struct smack_parsed_rule *rule,
int import)
{
int rc;
rc = smk_fill_rule(data, data + SMK_LABELLEN,
data + SMK_LABELLEN + SMK_LABELLEN, NULL, rule,
import, SMK_LABELLEN);
return rc;
}
static ssize_t smk_parse_long_rule(char *data, struct smack_parsed_rule *rule,
int import, int tokens)
{
ssize_t cnt = 0;
char *tok[4];
int i;
for (i = 0; i < tokens; ++i) {
while (isspace(data[cnt]))
data[cnt++] = '\0';
if (data[cnt] == '\0')
return -1;
tok[i] = data + cnt;
while (data[cnt] && !isspace(data[cnt]))
++cnt;
}
while (isspace(data[cnt]))
data[cnt++] = '\0';
while (i < 4)
tok[i++] = NULL;
if (smk_fill_rule(tok[0], tok[1], tok[2], tok[3], rule, import, 0))
return -1;
return cnt;
}
static ssize_t smk_write_rules_list(struct file *file, const char __user *buf,
size_t count, loff_t *ppos,
struct list_head *rule_list,
struct mutex *rule_lock, int format)
{
struct smack_parsed_rule rule;
char *data;
int rc;
int trunc = 0;
int tokens;
ssize_t cnt = 0;
if (*ppos != 0)
return -EINVAL;
if (format == SMK_FIXED24_FMT) {
if (count < SMK_OLOADLEN || count > SMK_LOADLEN)
return -EINVAL;
} else {
if (count >= PAGE_SIZE) {
count = PAGE_SIZE - 1;
trunc = 1;
}
}
data = kmalloc(count + 1, GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
if (copy_from_user(data, buf, count) != 0) {
rc = -EFAULT;
goto out;
}
if (trunc) {
while (count > 0 && (data[count - 1] != '\n'))
--count;
if (count == 0) {
rc = -EINVAL;
goto out;
}
}
data[count] = '\0';
tokens = (format == SMK_CHANGE_FMT ? 4 : 3);
while (cnt < count) {
if (format == SMK_FIXED24_FMT) {
rc = smk_parse_rule(data, &rule, 1);
if (rc != 0) {
rc = -EINVAL;
goto out;
}
cnt = count;
} else {
rc = smk_parse_long_rule(data + cnt, &rule, 1, tokens);
if (rc <= 0) {
rc = -EINVAL;
goto out;
}
cnt += rc;
}
if (rule_list == NULL)
rc = smk_set_access(&rule, &rule.smk_subject->smk_rules,
&rule.smk_subject->smk_rules_lock, 1);
else
rc = smk_set_access(&rule, rule_list, rule_lock, 0);
if (rc)
goto out;
}
rc = cnt;
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
static void smk_rule_show(struct seq_file *s, struct smack_rule *srp, int max)
{
if (strlen(srp->smk_subject->smk_known) >= max ||
strlen(srp->smk_object) >= max)
return;
if (srp->smk_access == 0)
return;
seq_printf(s, "%s %s", srp->smk_subject->smk_known, srp->smk_object);
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
if (srp->smk_access & MAY_LOCK)
seq_putc(s, 'l');
seq_putc(s, '\n');
}
static void *load2_seq_start(struct seq_file *s, loff_t *pos)
{
return smk_seq_start(s, pos, &smack_rule_list);
}
static void *load2_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
return smk_seq_next(s, v, pos, &smack_rule_list);
}
static int load_seq_show(struct seq_file *s, void *v)
{
struct list_head *list = v;
struct smack_master_list *smlp =
list_entry(list, struct smack_master_list, list);
smk_rule_show(s, smlp->smk_rule, SMK_LABELLEN);
return 0;
}
static int smk_open_load(struct inode *inode, struct file *file)
{
return seq_open(file, &load_seq_ops);
}
static ssize_t smk_write_load(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (!smack_privileged(CAP_MAC_ADMIN))
return -EPERM;
return smk_write_rules_list(file, buf, count, ppos, NULL, NULL,
SMK_FIXED24_FMT);
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
if (smack_net_ambient == NULL)
smack_net_ambient = &smack_known_floor;
rc = netlbl_cfg_unlbl_map_add(smack_net_ambient->smk_known, PF_INET,
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
struct netlbl_lsm_secattr_catmap *cmp = skp->smk_netlabel.attr.mls.cat;
char sep = '/';
int i;
if (strlen(skp->smk_known) >= SMK_LABELLEN)
return 0;
seq_printf(s, "%s %3d", skp->smk_known, skp->smk_netlabel.attr.mls.lvl);
for (i = netlbl_secattr_catmap_walk(cmp, 0); i >= 0;
i = netlbl_secattr_catmap_walk(cmp, i + 1)) {
seq_printf(s, "%c%d", sep, i);
sep = ',';
}
seq_putc(s, '\n');
return 0;
}
static int smk_open_cipso(struct inode *inode, struct file *file)
{
return seq_open(file, &cipso_seq_ops);
}
static ssize_t smk_set_cipso(struct file *file, const char __user *buf,
size_t count, loff_t *ppos, int format)
{
struct smack_known *skp;
struct netlbl_lsm_secattr ncats;
char mapcatset[SMK_CIPSOLEN];
int maplevel;
unsigned int cat;
int catlen;
ssize_t rc = -EINVAL;
char *data = NULL;
char *rule;
int ret;
int i;
if (!smack_privileged(CAP_MAC_ADMIN))
return -EPERM;
if (*ppos != 0)
return -EINVAL;
if (format == SMK_FIXED24_FMT &&
(count < SMK_CIPSOMIN || count > SMK_CIPSOMAX))
return -EINVAL;
data = kzalloc(count + 1, GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
if (copy_from_user(data, buf, count) != 0) {
rc = -EFAULT;
goto unlockedout;
}
data[count] = '\0';
rule = data;
mutex_lock(&smack_cipso_lock);
skp = smk_import_entry(rule, 0);
if (skp == NULL)
goto out;
if (format == SMK_FIXED24_FMT)
rule += SMK_LABELLEN;
else
rule += strlen(skp->smk_known) + 1;
ret = sscanf(rule, "%d", &maplevel);
if (ret != 1 || maplevel > SMACK_CIPSO_MAXLEVEL)
goto out;
rule += SMK_DIGITLEN;
ret = sscanf(rule, "%d", &catlen);
if (ret != 1 || catlen > SMACK_CIPSO_MAXCATNUM)
goto out;
if (format == SMK_FIXED24_FMT &&
count != (SMK_CIPSOMIN + catlen * SMK_DIGITLEN))
goto out;
memset(mapcatset, 0, sizeof(mapcatset));
for (i = 0; i < catlen; i++) {
rule += SMK_DIGITLEN;
ret = sscanf(rule, "%u", &cat);
if (ret != 1 || cat > SMACK_CIPSO_MAXCATNUM)
goto out;
smack_catset_bit(cat, mapcatset);
}
rc = smk_netlbl_mls(maplevel, mapcatset, &ncats, SMK_CIPSOLEN);
if (rc >= 0) {
netlbl_secattr_catmap_free(skp->smk_netlabel.attr.mls.cat);
skp->smk_netlabel.attr.mls.cat = ncats.attr.mls.cat;
skp->smk_netlabel.attr.mls.lvl = ncats.attr.mls.lvl;
rc = count;
}
out:
mutex_unlock(&smack_cipso_lock);
unlockedout:
kfree(data);
return rc;
}
static ssize_t smk_write_cipso(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
return smk_set_cipso(file, buf, count, ppos, SMK_FIXED24_FMT);
}
static int cipso2_seq_show(struct seq_file *s, void *v)
{
struct list_head *list = v;
struct smack_known *skp =
list_entry(list, struct smack_known, list);
struct netlbl_lsm_secattr_catmap *cmp = skp->smk_netlabel.attr.mls.cat;
char sep = '/';
int i;
seq_printf(s, "%s %3d", skp->smk_known, skp->smk_netlabel.attr.mls.lvl);
for (i = netlbl_secattr_catmap_walk(cmp, 0); i >= 0;
i = netlbl_secattr_catmap_walk(cmp, i + 1)) {
seq_printf(s, "%c%d", sep, i);
sep = ',';
}
seq_putc(s, '\n');
return 0;
}
static int smk_open_cipso2(struct inode *inode, struct file *file)
{
return seq_open(file, &cipso2_seq_ops);
}
static ssize_t smk_write_cipso2(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
return smk_set_cipso(file, buf, count, ppos, SMK_LONG_FMT);
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
char *smack;
char *sp;
char *data;
char *host = (char *)&newname.sin_addr.s_addr;
int rc;
struct netlbl_audit audit_info;
struct in_addr mask;
unsigned int m;
int found;
u32 mask_bits = (1<<31);
__be32 nsa;
u32 temp_mask;
if (!smack_privileged(CAP_MAC_ADMIN))
return -EPERM;
if (*ppos != 0)
return -EINVAL;
if (count < SMK_NETLBLADDRMIN)
return -EINVAL;
data = kzalloc(count + 1, GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
if (copy_from_user(data, buf, count) != 0) {
rc = -EFAULT;
goto free_data_out;
}
smack = kzalloc(count + 1, GFP_KERNEL);
if (smack == NULL) {
rc = -ENOMEM;
goto free_data_out;
}
data[count] = '\0';
rc = sscanf(data, "%hhd.%hhd.%hhd.%hhd/%d %s",
&host[0], &host[1], &host[2], &host[3], &m, smack);
if (rc != 6) {
rc = sscanf(data, "%hhd.%hhd.%hhd.%hhd %s",
&host[0], &host[1], &host[2], &host[3], smack);
if (rc != 5) {
rc = -EINVAL;
goto free_out;
}
m = BEBITS;
}
if (m > BEBITS) {
rc = -EINVAL;
goto free_out;
}
if (smack[0] != '-') {
sp = smk_import(smack, 0);
if (sp == NULL) {
rc = -EINVAL;
goto free_out;
}
} else {
if (strcmp(smack, smack_cipso_option) == 0)
sp = (char *)smack_cipso_option;
else {
rc = -EINVAL;
goto free_out;
}
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
free_out:
kfree(smack);
free_data_out:
kfree(data);
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
if (!smack_privileged(CAP_MAC_ADMIN))
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
struct smack_known *skp;
char temp[80];
int i;
if (!smack_privileged(CAP_MAC_ADMIN))
return -EPERM;
if (count >= sizeof(temp) || count == 0)
return -EINVAL;
if (copy_from_user(temp, buf, count) != 0)
return -EFAULT;
temp[count] = '\0';
if (sscanf(temp, "%d", &i) != 1)
return -EINVAL;
if (smack_cipso_direct != i) {
mutex_lock(&smack_known_lock);
list_for_each_entry_rcu(skp, &smack_known_list, list)
if (skp->smk_netlabel.attr.mls.lvl ==
smack_cipso_direct)
skp->smk_netlabel.attr.mls.lvl = i;
smack_cipso_direct = i;
mutex_unlock(&smack_known_lock);
}
return count;
}
static ssize_t smk_read_mapped(struct file *filp, char __user *buf,
size_t count, loff_t *ppos)
{
char temp[80];
ssize_t rc;
if (*ppos != 0)
return 0;
sprintf(temp, "%d", smack_cipso_mapped);
rc = simple_read_from_buffer(buf, count, ppos, temp, strlen(temp));
return rc;
}
static ssize_t smk_write_mapped(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct smack_known *skp;
char temp[80];
int i;
if (!smack_privileged(CAP_MAC_ADMIN))
return -EPERM;
if (count >= sizeof(temp) || count == 0)
return -EINVAL;
if (copy_from_user(temp, buf, count) != 0)
return -EFAULT;
temp[count] = '\0';
if (sscanf(temp, "%d", &i) != 1)
return -EINVAL;
if (smack_cipso_mapped != i) {
mutex_lock(&smack_known_lock);
list_for_each_entry_rcu(skp, &smack_known_list, list)
if (skp->smk_netlabel.attr.mls.lvl ==
smack_cipso_mapped)
skp->smk_netlabel.attr.mls.lvl = i;
smack_cipso_mapped = i;
mutex_unlock(&smack_known_lock);
}
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
asize = strlen(smack_net_ambient->smk_known) + 1;
if (cn >= asize)
rc = simple_read_from_buffer(buf, cn, ppos,
smack_net_ambient->smk_known,
asize);
else
rc = -EINVAL;
mutex_unlock(&smack_ambient_lock);
return rc;
}
static ssize_t smk_write_ambient(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct smack_known *skp;
char *oldambient;
char *data;
int rc = count;
if (!smack_privileged(CAP_MAC_ADMIN))
return -EPERM;
data = kzalloc(count + 1, GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
if (copy_from_user(data, buf, count) != 0) {
rc = -EFAULT;
goto out;
}
skp = smk_import_entry(data, count);
if (skp == NULL) {
rc = -EINVAL;
goto out;
}
mutex_lock(&smack_ambient_lock);
oldambient = smack_net_ambient->smk_known;
smack_net_ambient = skp;
smk_unlbl_ambient(oldambient);
mutex_unlock(&smack_ambient_lock);
out:
kfree(data);
return rc;
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
char *data;
struct smack_known *skp = smk_of_task(current->cred->security);
int rc = count;
if (!smack_privileged(CAP_MAC_ADMIN))
return -EPERM;
if (smack_onlycap != NULL && smack_onlycap != skp->smk_known)
return -EPERM;
data = kzalloc(count, GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
if (copy_from_user(data, buf, count) != 0)
rc = -EFAULT;
else
smack_onlycap = smk_import(data, count);
kfree(data);
return rc;
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
if (!smack_privileged(CAP_MAC_ADMIN))
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
smk_rule_show(s, srp, SMK_LABELLEN);
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
return smk_write_rules_list(file, buf, count, ppos, &tsp->smk_rules,
&tsp->smk_rules_lock, SMK_FIXED24_FMT);
}
static ssize_t smk_user_access(struct file *file, const char __user *buf,
size_t count, loff_t *ppos, int format)
{
struct smack_parsed_rule rule;
char *data;
int res;
data = simple_transaction_get(file, buf, count);
if (IS_ERR(data))
return PTR_ERR(data);
if (format == SMK_FIXED24_FMT) {
if (count < SMK_LOADLEN)
return -EINVAL;
res = smk_parse_rule(data, &rule, 0);
} else {
res = smk_parse_long_rule(data, &rule, 0, 3);
}
if (res < 0)
return -EINVAL;
res = smk_access(rule.smk_subject, rule.smk_object,
rule.smk_access1, NULL);
data[0] = res == 0 ? '1' : '0';
data[1] = '\0';
simple_transaction_set(file, 2);
if (format == SMK_FIXED24_FMT)
return SMK_LOADLEN;
return count;
}
static ssize_t smk_write_access(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
return smk_user_access(file, buf, count, ppos, SMK_FIXED24_FMT);
}
static int load2_seq_show(struct seq_file *s, void *v)
{
struct list_head *list = v;
struct smack_master_list *smlp =
list_entry(list, struct smack_master_list, list);
smk_rule_show(s, smlp->smk_rule, SMK_LONGLABEL);
return 0;
}
static int smk_open_load2(struct inode *inode, struct file *file)
{
return seq_open(file, &load2_seq_ops);
}
static ssize_t smk_write_load2(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (!smack_privileged(CAP_MAC_ADMIN))
return -EPERM;
return smk_write_rules_list(file, buf, count, ppos, NULL, NULL,
SMK_LONG_FMT);
}
static void *load_self2_seq_start(struct seq_file *s, loff_t *pos)
{
struct task_smack *tsp = current_security();
return smk_seq_start(s, pos, &tsp->smk_rules);
}
static void *load_self2_seq_next(struct seq_file *s, void *v, loff_t *pos)
{
struct task_smack *tsp = current_security();
return smk_seq_next(s, v, pos, &tsp->smk_rules);
}
static int load_self2_seq_show(struct seq_file *s, void *v)
{
struct list_head *list = v;
struct smack_rule *srp =
list_entry(list, struct smack_rule, list);
smk_rule_show(s, srp, SMK_LONGLABEL);
return 0;
}
static int smk_open_load_self2(struct inode *inode, struct file *file)
{
return seq_open(file, &load_self2_seq_ops);
}
static ssize_t smk_write_load_self2(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
struct task_smack *tsp = current_security();
return smk_write_rules_list(file, buf, count, ppos, &tsp->smk_rules,
&tsp->smk_rules_lock, SMK_LONG_FMT);
}
static ssize_t smk_write_access2(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
return smk_user_access(file, buf, count, ppos, SMK_LONG_FMT);
}
static ssize_t smk_write_revoke_subj(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
char *data = NULL;
const char *cp = NULL;
struct smack_known *skp;
struct smack_rule *sp;
struct list_head *rule_list;
struct mutex *rule_lock;
int rc = count;
if (*ppos != 0)
return -EINVAL;
if (!smack_privileged(CAP_MAC_ADMIN))
return -EPERM;
if (count == 0 || count > SMK_LONGLABEL)
return -EINVAL;
data = kzalloc(count, GFP_KERNEL);
if (data == NULL)
return -ENOMEM;
if (copy_from_user(data, buf, count) != 0) {
rc = -EFAULT;
goto free_out;
}
cp = smk_parse_smack(data, count);
if (cp == NULL) {
rc = -EINVAL;
goto free_out;
}
skp = smk_find_entry(cp);
if (skp == NULL)
goto free_out;
rule_list = &skp->smk_rules;
rule_lock = &skp->smk_rules_lock;
mutex_lock(rule_lock);
list_for_each_entry_rcu(sp, rule_list, list)
sp->smk_access = 0;
mutex_unlock(rule_lock);
free_out:
kfree(data);
kfree(cp);
return rc;
}
static int smk_init_sysfs(void)
{
smackfs_kset = kset_create_and_add("smackfs", NULL, fs_kobj);
if (!smackfs_kset)
return -ENOMEM;
return 0;
}
static ssize_t smk_write_change_rule(struct file *file, const char __user *buf,
size_t count, loff_t *ppos)
{
if (!capable(CAP_MAC_ADMIN))
return -EPERM;
return smk_write_rules_list(file, buf, count, ppos, NULL, NULL,
SMK_CHANGE_FMT);
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
[SMK_MAPPED] = {
"mapped", &smk_mapped_ops, S_IRUGO|S_IWUSR},
[SMK_LOAD2] = {
"load2", &smk_load2_ops, S_IRUGO|S_IWUSR},
[SMK_LOAD_SELF2] = {
"load-self2", &smk_load_self2_ops, S_IRUGO|S_IWUGO},
[SMK_ACCESS2] = {
"access2", &smk_access2_ops, S_IRUGO|S_IWUGO},
[SMK_CIPSO2] = {
"cipso2", &smk_cipso2_ops, S_IRUGO|S_IWUSR},
[SMK_REVOKE_SUBJ] = {
"revoke-subject", &smk_revoke_subj_ops,
S_IRUGO|S_IWUSR},
[SMK_CHANGE_RULE] = {
"change-rule", &smk_change_rule_ops, S_IRUGO|S_IWUSR},
{""}
};
rc = simple_fill_super(sb, SMACK_MAGIC, smack_files);
if (rc != 0) {
printk(KERN_ERR "%s failed %d while creating inodes\n",
__func__, rc);
return rc;
}
root_inode = sb->s_root->d_inode;
return 0;
}
static struct dentry *smk_mount(struct file_system_type *fs_type,
int flags, const char *dev_name, void *data)
{
return mount_single(fs_type, flags, data, smk_fill_super);
}
static int __init smk_preset_netlabel(struct smack_known *skp)
{
skp->smk_netlabel.domain = skp->smk_known;
skp->smk_netlabel.flags =
NETLBL_SECATTR_DOMAIN | NETLBL_SECATTR_MLS_LVL;
return smk_netlbl_mls(smack_cipso_direct, skp->smk_known,
&skp->smk_netlabel, strlen(skp->smk_known));
}
static int __init init_smk_fs(void)
{
int err;
int rc;
if (!security_module_enable(&smack_ops))
return 0;
err = smk_init_sysfs();
if (err)
printk(KERN_ERR "smackfs: sysfs mountpoint problem.\n");
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
rc = smk_preset_netlabel(&smack_known_floor);
if (err == 0 && rc < 0)
err = rc;
rc = smk_preset_netlabel(&smack_known_hat);
if (err == 0 && rc < 0)
err = rc;
rc = smk_preset_netlabel(&smack_known_huh);
if (err == 0 && rc < 0)
err = rc;
rc = smk_preset_netlabel(&smack_known_invalid);
if (err == 0 && rc < 0)
err = rc;
rc = smk_preset_netlabel(&smack_known_star);
if (err == 0 && rc < 0)
err = rc;
rc = smk_preset_netlabel(&smack_known_web);
if (err == 0 && rc < 0)
err = rc;
return err;
}
