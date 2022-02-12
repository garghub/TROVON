static inline const char *basename(const char *path)
{
const char *tail = strrchr(path, '/');
return tail ? tail+1 : path;
}
static char *ddebug_describe_flags(struct _ddebug *dp, char *buf,
size_t maxlen)
{
char *p = buf;
int i;
BUG_ON(maxlen < 4);
for (i = 0; i < ARRAY_SIZE(opt_array); ++i)
if (dp->flags & opt_array[i].flag)
*p++ = opt_array[i].opt_char;
if (p == buf)
*p++ = '-';
*p = '\0';
return buf;
}
static void ddebug_change(const struct ddebug_query *query,
unsigned int flags, unsigned int mask)
{
int i;
struct ddebug_table *dt;
unsigned int newflags;
unsigned int nfound = 0;
char flagbuf[8];
mutex_lock(&ddebug_lock);
list_for_each_entry(dt, &ddebug_tables, link) {
if (query->module != NULL &&
strcmp(query->module, dt->mod_name))
continue;
for (i = 0 ; i < dt->num_ddebugs ; i++) {
struct _ddebug *dp = &dt->ddebugs[i];
if (query->filename != NULL &&
strcmp(query->filename, dp->filename) &&
strcmp(query->filename, basename(dp->filename)))
continue;
if (query->function != NULL &&
strcmp(query->function, dp->function))
continue;
if (query->format != NULL &&
strstr(dp->format, query->format) == NULL)
continue;
if (query->first_lineno &&
dp->lineno < query->first_lineno)
continue;
if (query->last_lineno &&
dp->lineno > query->last_lineno)
continue;
nfound++;
newflags = (dp->flags & mask) | flags;
if (newflags == dp->flags)
continue;
if (!newflags)
dt->num_enabled--;
else if (!dp->flags)
dt->num_enabled++;
dp->flags = newflags;
if (newflags)
dp->enabled = 1;
else
dp->enabled = 0;
if (verbose)
printk(KERN_INFO
"ddebug: changed %s:%d [%s]%s %s\n",
dp->filename, dp->lineno,
dt->mod_name, dp->function,
ddebug_describe_flags(dp, flagbuf,
sizeof(flagbuf)));
}
}
mutex_unlock(&ddebug_lock);
if (!nfound && verbose)
printk(KERN_INFO "ddebug: no matches for query\n");
}
static int ddebug_tokenize(char *buf, char *words[], int maxwords)
{
int nwords = 0;
while (*buf) {
char *end;
buf = skip_spaces(buf);
if (!*buf)
break;
if (*buf == '"' || *buf == '\'') {
int quote = *buf++;
for (end = buf ; *end && *end != quote ; end++)
;
if (!*end)
return -EINVAL;
} else {
for (end = buf ; *end && !isspace(*end) ; end++)
;
BUG_ON(end == buf);
}
if (nwords == maxwords)
return -EINVAL;
if (*end)
*end++ = '\0';
words[nwords++] = buf;
buf = end;
}
if (verbose) {
int i;
printk(KERN_INFO "%s: split into words:", __func__);
for (i = 0 ; i < nwords ; i++)
printk(" \"%s\"", words[i]);
printk("\n");
}
return nwords;
}
static inline int parse_lineno(const char *str, unsigned int *val)
{
char *end = NULL;
BUG_ON(str == NULL);
if (*str == '\0') {
*val = 0;
return 0;
}
*val = simple_strtoul(str, &end, 10);
return end == NULL || end == str || *end != '\0' ? -EINVAL : 0;
}
static char *unescape(char *str)
{
char *in = str;
char *out = str;
while (*in) {
if (*in == '\\') {
if (in[1] == '\\') {
*out++ = '\\';
in += 2;
continue;
} else if (in[1] == 't') {
*out++ = '\t';
in += 2;
continue;
} else if (in[1] == 'n') {
*out++ = '\n';
in += 2;
continue;
} else if (isodigit(in[1]) &&
isodigit(in[2]) &&
isodigit(in[3])) {
*out++ = ((in[1] - '0')<<6) |
((in[2] - '0')<<3) |
(in[3] - '0');
in += 4;
continue;
}
}
*out++ = *in++;
}
*out = '\0';
return str;
}
static int ddebug_parse_query(char *words[], int nwords,
struct ddebug_query *query)
{
unsigned int i;
if (nwords % 2 != 0)
return -EINVAL;
memset(query, 0, sizeof(*query));
for (i = 0 ; i < nwords ; i += 2) {
if (!strcmp(words[i], "func"))
query->function = words[i+1];
else if (!strcmp(words[i], "file"))
query->filename = words[i+1];
else if (!strcmp(words[i], "module"))
query->module = words[i+1];
else if (!strcmp(words[i], "format"))
query->format = unescape(words[i+1]);
else if (!strcmp(words[i], "line")) {
char *first = words[i+1];
char *last = strchr(first, '-');
if (last)
*last++ = '\0';
if (parse_lineno(first, &query->first_lineno) < 0)
return -EINVAL;
if (last != NULL) {
if (parse_lineno(last, &query->last_lineno) < 0)
return -EINVAL;
} else {
query->last_lineno = query->first_lineno;
}
} else {
if (verbose)
printk(KERN_ERR "%s: unknown keyword \"%s\"\n",
__func__, words[i]);
return -EINVAL;
}
}
if (verbose)
printk(KERN_INFO "%s: q->function=\"%s\" q->filename=\"%s\" "
"q->module=\"%s\" q->format=\"%s\" q->lineno=%u-%u\n",
__func__, query->function, query->filename,
query->module, query->format, query->first_lineno,
query->last_lineno);
return 0;
}
static int ddebug_parse_flags(const char *str, unsigned int *flagsp,
unsigned int *maskp)
{
unsigned flags = 0;
int op = '=', i;
switch (*str) {
case '+':
case '-':
case '=':
op = *str++;
break;
default:
return -EINVAL;
}
if (verbose)
printk(KERN_INFO "%s: op='%c'\n", __func__, op);
for ( ; *str ; ++str) {
for (i = ARRAY_SIZE(opt_array) - 1; i >= 0; i--) {
if (*str == opt_array[i].opt_char) {
flags |= opt_array[i].flag;
break;
}
}
if (i < 0)
return -EINVAL;
}
if (flags == 0)
return -EINVAL;
if (verbose)
printk(KERN_INFO "%s: flags=0x%x\n", __func__, flags);
switch (op) {
case '=':
*maskp = 0;
*flagsp = flags;
break;
case '+':
*maskp = ~0U;
*flagsp = flags;
break;
case '-':
*maskp = ~flags;
*flagsp = 0;
break;
}
if (verbose)
printk(KERN_INFO "%s: *flagsp=0x%x *maskp=0x%x\n",
__func__, *flagsp, *maskp);
return 0;
}
static int ddebug_exec_query(char *query_string)
{
unsigned int flags = 0, mask = 0;
struct ddebug_query query;
#define MAXWORDS 9
int nwords;
char *words[MAXWORDS];
nwords = ddebug_tokenize(query_string, words, MAXWORDS);
if (nwords <= 0)
return -EINVAL;
if (ddebug_parse_query(words, nwords-1, &query))
return -EINVAL;
if (ddebug_parse_flags(words[nwords-1], &flags, &mask))
return -EINVAL;
ddebug_change(&query, flags, mask);
return 0;
}
int __dynamic_pr_debug(struct _ddebug *descriptor, const char *fmt, ...)
{
va_list args;
int res;
BUG_ON(!descriptor);
BUG_ON(!fmt);
va_start(args, fmt);
res = printk(KERN_DEBUG);
if (descriptor->flags & _DPRINTK_FLAGS_INCL_TID) {
if (in_interrupt())
res += printk(KERN_CONT "<intr> ");
else
res += printk(KERN_CONT "[%d] ", task_pid_vnr(current));
}
if (descriptor->flags & _DPRINTK_FLAGS_INCL_MODNAME)
res += printk(KERN_CONT "%s:", descriptor->modname);
if (descriptor->flags & _DPRINTK_FLAGS_INCL_FUNCNAME)
res += printk(KERN_CONT "%s:", descriptor->function);
if (descriptor->flags & _DPRINTK_FLAGS_INCL_LINENO)
res += printk(KERN_CONT "%d ", descriptor->lineno);
res += vprintk(fmt, args);
va_end(args);
return res;
}
static __init int ddebug_setup_query(char *str)
{
if (strlen(str) >= 1024) {
pr_warning("ddebug boot param string too large\n");
return 0;
}
strcpy(ddebug_setup_string, str);
return 1;
}
static ssize_t ddebug_proc_write(struct file *file, const char __user *ubuf,
size_t len, loff_t *offp)
{
char tmpbuf[256];
int ret;
if (len == 0)
return 0;
if (len > sizeof(tmpbuf)-1)
return -E2BIG;
if (copy_from_user(tmpbuf, ubuf, len))
return -EFAULT;
tmpbuf[len] = '\0';
if (verbose)
printk(KERN_INFO "%s: read %d bytes from userspace\n",
__func__, (int)len);
ret = ddebug_exec_query(tmpbuf);
if (ret)
return ret;
*offp += len;
return len;
}
static struct _ddebug *ddebug_iter_first(struct ddebug_iter *iter)
{
if (list_empty(&ddebug_tables)) {
iter->table = NULL;
iter->idx = 0;
return NULL;
}
iter->table = list_entry(ddebug_tables.next,
struct ddebug_table, link);
iter->idx = 0;
return &iter->table->ddebugs[iter->idx];
}
static struct _ddebug *ddebug_iter_next(struct ddebug_iter *iter)
{
if (iter->table == NULL)
return NULL;
if (++iter->idx == iter->table->num_ddebugs) {
iter->idx = 0;
if (list_is_last(&iter->table->link, &ddebug_tables)) {
iter->table = NULL;
return NULL;
}
iter->table = list_entry(iter->table->link.next,
struct ddebug_table, link);
}
return &iter->table->ddebugs[iter->idx];
}
static void *ddebug_proc_start(struct seq_file *m, loff_t *pos)
{
struct ddebug_iter *iter = m->private;
struct _ddebug *dp;
int n = *pos;
if (verbose)
printk(KERN_INFO "%s: called m=%p *pos=%lld\n",
__func__, m, (unsigned long long)*pos);
mutex_lock(&ddebug_lock);
if (!n)
return SEQ_START_TOKEN;
if (n < 0)
return NULL;
dp = ddebug_iter_first(iter);
while (dp != NULL && --n > 0)
dp = ddebug_iter_next(iter);
return dp;
}
static void *ddebug_proc_next(struct seq_file *m, void *p, loff_t *pos)
{
struct ddebug_iter *iter = m->private;
struct _ddebug *dp;
if (verbose)
printk(KERN_INFO "%s: called m=%p p=%p *pos=%lld\n",
__func__, m, p, (unsigned long long)*pos);
if (p == SEQ_START_TOKEN)
dp = ddebug_iter_first(iter);
else
dp = ddebug_iter_next(iter);
++*pos;
return dp;
}
static int ddebug_proc_show(struct seq_file *m, void *p)
{
struct ddebug_iter *iter = m->private;
struct _ddebug *dp = p;
char flagsbuf[8];
if (verbose)
printk(KERN_INFO "%s: called m=%p p=%p\n",
__func__, m, p);
if (p == SEQ_START_TOKEN) {
seq_puts(m,
"# filename:lineno [module]function flags format\n");
return 0;
}
seq_printf(m, "%s:%u [%s]%s %s \"",
dp->filename, dp->lineno,
iter->table->mod_name, dp->function,
ddebug_describe_flags(dp, flagsbuf, sizeof(flagsbuf)));
seq_escape(m, dp->format, "\t\r\n\"");
seq_puts(m, "\"\n");
return 0;
}
static void ddebug_proc_stop(struct seq_file *m, void *p)
{
if (verbose)
printk(KERN_INFO "%s: called m=%p p=%p\n",
__func__, m, p);
mutex_unlock(&ddebug_lock);
}
static int ddebug_proc_open(struct inode *inode, struct file *file)
{
struct ddebug_iter *iter;
int err;
if (verbose)
printk(KERN_INFO "%s: called\n", __func__);
iter = kzalloc(sizeof(*iter), GFP_KERNEL);
if (iter == NULL)
return -ENOMEM;
err = seq_open(file, &ddebug_proc_seqops);
if (err) {
kfree(iter);
return err;
}
((struct seq_file *) file->private_data)->private = iter;
return 0;
}
int ddebug_add_module(struct _ddebug *tab, unsigned int n,
const char *name)
{
struct ddebug_table *dt;
char *new_name;
dt = kzalloc(sizeof(*dt), GFP_KERNEL);
if (dt == NULL)
return -ENOMEM;
new_name = kstrdup(name, GFP_KERNEL);
if (new_name == NULL) {
kfree(dt);
return -ENOMEM;
}
dt->mod_name = new_name;
dt->num_ddebugs = n;
dt->num_enabled = 0;
dt->ddebugs = tab;
mutex_lock(&ddebug_lock);
list_add_tail(&dt->link, &ddebug_tables);
mutex_unlock(&ddebug_lock);
if (verbose)
printk(KERN_INFO "%u debug prints in module %s\n",
n, dt->mod_name);
return 0;
}
static void ddebug_table_free(struct ddebug_table *dt)
{
list_del_init(&dt->link);
kfree(dt->mod_name);
kfree(dt);
}
int ddebug_remove_module(const char *mod_name)
{
struct ddebug_table *dt, *nextdt;
int ret = -ENOENT;
if (verbose)
printk(KERN_INFO "%s: removing module \"%s\"\n",
__func__, mod_name);
mutex_lock(&ddebug_lock);
list_for_each_entry_safe(dt, nextdt, &ddebug_tables, link) {
if (!strcmp(dt->mod_name, mod_name)) {
ddebug_table_free(dt);
ret = 0;
}
}
mutex_unlock(&ddebug_lock);
return ret;
}
static void ddebug_remove_all_tables(void)
{
mutex_lock(&ddebug_lock);
while (!list_empty(&ddebug_tables)) {
struct ddebug_table *dt = list_entry(ddebug_tables.next,
struct ddebug_table,
link);
ddebug_table_free(dt);
}
mutex_unlock(&ddebug_lock);
}
static int __init dynamic_debug_init_debugfs(void)
{
struct dentry *dir, *file;
if (!ddebug_init_success)
return -ENODEV;
dir = debugfs_create_dir("dynamic_debug", NULL);
if (!dir)
return -ENOMEM;
file = debugfs_create_file("control", 0644, dir, NULL,
&ddebug_proc_fops);
if (!file) {
debugfs_remove(dir);
return -ENOMEM;
}
return 0;
}
static int __init dynamic_debug_init(void)
{
struct _ddebug *iter, *iter_start;
const char *modname = NULL;
int ret = 0;
int n = 0;
if (__start___verbose != __stop___verbose) {
iter = __start___verbose;
modname = iter->modname;
iter_start = iter;
for (; iter < __stop___verbose; iter++) {
if (strcmp(modname, iter->modname)) {
ret = ddebug_add_module(iter_start, n, modname);
if (ret)
goto out_free;
n = 0;
modname = iter->modname;
iter_start = iter;
}
n++;
}
ret = ddebug_add_module(iter_start, n, modname);
}
if (ddebug_setup_string[0] != '\0') {
ret = ddebug_exec_query(ddebug_setup_string);
if (ret)
pr_warning("Invalid ddebug boot param %s",
ddebug_setup_string);
else
pr_info("ddebug initialized with string %s",
ddebug_setup_string);
}
out_free:
if (ret)
ddebug_remove_all_tables();
else
ddebug_init_success = 1;
return 0;
}
