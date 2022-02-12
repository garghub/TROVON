static inline const char *trim_prefix(const char *path)
{
int skip = strlen(__FILE__) - strlen("lib/dynamic_debug.c");
if (strncmp(path, __FILE__, skip))
skip = 0;
return path + skip;
}
static char *ddebug_describe_flags(struct _ddebug *dp, char *buf,
size_t maxlen)
{
char *p = buf;
int i;
BUG_ON(maxlen < 6);
for (i = 0; i < ARRAY_SIZE(opt_array); ++i)
if (dp->flags & opt_array[i].flag)
*p++ = opt_array[i].opt_char;
if (p == buf)
*p++ = '_';
*p = '\0';
return buf;
}
static void vpr_info_dq(const struct ddebug_query *query, const char *msg)
{
int fmtlen = 0;
if (query->format) {
fmtlen = strlen(query->format);
while (fmtlen && query->format[fmtlen - 1] == '\n')
fmtlen--;
}
vpr_info("%s: func=\"%s\" file=\"%s\" module=\"%s\" format=\"%.*s\" lineno=%u-%u\n",
msg,
query->function ? query->function : "",
query->filename ? query->filename : "",
query->module ? query->module : "",
fmtlen, query->format ? query->format : "",
query->first_lineno, query->last_lineno);
}
static int ddebug_change(const struct ddebug_query *query,
unsigned int flags, unsigned int mask)
{
int i;
struct ddebug_table *dt;
unsigned int newflags;
unsigned int nfound = 0;
char flagbuf[10];
mutex_lock(&ddebug_lock);
list_for_each_entry(dt, &ddebug_tables, link) {
if (query->module &&
!match_wildcard(query->module, dt->mod_name))
continue;
for (i = 0; i < dt->num_ddebugs; i++) {
struct _ddebug *dp = &dt->ddebugs[i];
if (query->filename &&
!match_wildcard(query->filename, dp->filename) &&
!match_wildcard(query->filename,
kbasename(dp->filename)) &&
!match_wildcard(query->filename,
trim_prefix(dp->filename)))
continue;
if (query->function &&
!match_wildcard(query->function, dp->function))
continue;
if (query->format &&
!strstr(dp->format, query->format))
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
dp->flags = newflags;
vpr_info("changed %s:%d [%s]%s =%s\n",
trim_prefix(dp->filename), dp->lineno,
dt->mod_name, dp->function,
ddebug_describe_flags(dp, flagbuf,
sizeof(flagbuf)));
}
}
mutex_unlock(&ddebug_lock);
if (!nfound && verbose)
pr_info("no matches for query\n");
return nfound;
}
static int ddebug_tokenize(char *buf, char *words[], int maxwords)
{
int nwords = 0;
while (*buf) {
char *end;
buf = skip_spaces(buf);
if (!*buf)
break;
if (*buf == '#')
break;
if (*buf == '"' || *buf == '\'') {
int quote = *buf++;
for (end = buf; *end && *end != quote; end++)
;
if (!*end) {
pr_err("unclosed quote: %s\n", buf);
return -EINVAL;
}
} else {
for (end = buf; *end && !isspace(*end); end++)
;
BUG_ON(end == buf);
}
if (nwords == maxwords) {
pr_err("too many words, legal max <=%d\n", maxwords);
return -EINVAL;
}
if (*end)
*end++ = '\0';
words[nwords++] = buf;
buf = end;
}
if (verbose) {
int i;
pr_info("split into words:");
for (i = 0; i < nwords; i++)
pr_cont(" \"%s\"", words[i]);
pr_cont("\n");
}
return nwords;
}
static inline int parse_lineno(const char *str, unsigned int *val)
{
BUG_ON(str == NULL);
if (*str == '\0') {
*val = 0;
return 0;
}
if (kstrtouint(str, 10, val) < 0) {
pr_err("bad line-number: %s\n", str);
return -EINVAL;
}
return 0;
}
static int check_set(const char **dest, char *src, char *name)
{
int rc = 0;
if (*dest) {
rc = -EINVAL;
pr_err("match-spec:%s val:%s overridden by %s\n",
name, *dest, src);
}
*dest = src;
return rc;
}
static int ddebug_parse_query(char *words[], int nwords,
struct ddebug_query *query, const char *modname)
{
unsigned int i;
int rc = 0;
if (nwords % 2 != 0) {
pr_err("expecting pairs of match-spec <value>\n");
return -EINVAL;
}
memset(query, 0, sizeof(*query));
if (modname)
query->module = modname;
for (i = 0; i < nwords; i += 2) {
if (!strcmp(words[i], "func")) {
rc = check_set(&query->function, words[i+1], "func");
} else if (!strcmp(words[i], "file")) {
rc = check_set(&query->filename, words[i+1], "file");
} else if (!strcmp(words[i], "module")) {
rc = check_set(&query->module, words[i+1], "module");
} else if (!strcmp(words[i], "format")) {
string_unescape_inplace(words[i+1], UNESCAPE_SPACE |
UNESCAPE_OCTAL |
UNESCAPE_SPECIAL);
rc = check_set(&query->format, words[i+1], "format");
} else if (!strcmp(words[i], "line")) {
char *first = words[i+1];
char *last = strchr(first, '-');
if (query->first_lineno || query->last_lineno) {
pr_err("match-spec: line used 2x\n");
return -EINVAL;
}
if (last)
*last++ = '\0';
if (parse_lineno(first, &query->first_lineno) < 0)
return -EINVAL;
if (last) {
if (parse_lineno(last, &query->last_lineno) < 0)
return -EINVAL;
if (query->last_lineno < query->first_lineno) {
pr_err("last-line:%d < 1st-line:%d\n",
query->last_lineno,
query->first_lineno);
return -EINVAL;
}
} else {
query->last_lineno = query->first_lineno;
}
} else {
pr_err("unknown keyword \"%s\"\n", words[i]);
return -EINVAL;
}
if (rc)
return rc;
}
vpr_info_dq(query, "parsed");
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
pr_err("bad flag-op %c, at start of %s\n", *str, str);
return -EINVAL;
}
vpr_info("op='%c'\n", op);
for (; *str ; ++str) {
for (i = ARRAY_SIZE(opt_array) - 1; i >= 0; i--) {
if (*str == opt_array[i].opt_char) {
flags |= opt_array[i].flag;
break;
}
}
if (i < 0) {
pr_err("unknown flag '%c' in \"%s\"\n", *str, str);
return -EINVAL;
}
}
vpr_info("flags=0x%x\n", flags);
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
vpr_info("*flagsp=0x%x *maskp=0x%x\n", *flagsp, *maskp);
return 0;
}
static int ddebug_exec_query(char *query_string, const char *modname)
{
unsigned int flags = 0, mask = 0;
struct ddebug_query query;
#define MAXWORDS 9
int nwords, nfound;
char *words[MAXWORDS];
nwords = ddebug_tokenize(query_string, words, MAXWORDS);
if (nwords <= 0) {
pr_err("tokenize failed\n");
return -EINVAL;
}
if (ddebug_parse_flags(words[nwords-1], &flags, &mask)) {
pr_err("flags parse failed\n");
return -EINVAL;
}
if (ddebug_parse_query(words, nwords-1, &query, modname)) {
pr_err("query parse failed\n");
return -EINVAL;
}
nfound = ddebug_change(&query, flags, mask);
vpr_info_dq(&query, nfound ? "applied" : "no-match");
return nfound;
}
static int ddebug_exec_queries(char *query, const char *modname)
{
char *split;
int i, errs = 0, exitcode = 0, rc, nfound = 0;
for (i = 0; query; query = split) {
split = strpbrk(query, ";\n");
if (split)
*split++ = '\0';
query = skip_spaces(query);
if (!query || !*query || *query == '#')
continue;
vpr_info("query %d: \"%s\"\n", i, query);
rc = ddebug_exec_query(query, modname);
if (rc < 0) {
errs++;
exitcode = rc;
} else {
nfound += rc;
}
i++;
}
vpr_info("processed %d queries, with %d matches, %d errs\n",
i, nfound, errs);
if (exitcode)
return exitcode;
return nfound;
}
static int remaining(int wrote)
{
if (PREFIX_SIZE - wrote > 0)
return PREFIX_SIZE - wrote;
return 0;
}
static char *dynamic_emit_prefix(const struct _ddebug *desc, char *buf)
{
int pos_after_tid;
int pos = 0;
*buf = '\0';
if (desc->flags & _DPRINTK_FLAGS_INCL_TID) {
if (in_interrupt())
pos += snprintf(buf + pos, remaining(pos), "<intr> ");
else
pos += snprintf(buf + pos, remaining(pos), "[%d] ",
task_pid_vnr(current));
}
pos_after_tid = pos;
if (desc->flags & _DPRINTK_FLAGS_INCL_MODNAME)
pos += snprintf(buf + pos, remaining(pos), "%s:",
desc->modname);
if (desc->flags & _DPRINTK_FLAGS_INCL_FUNCNAME)
pos += snprintf(buf + pos, remaining(pos), "%s:",
desc->function);
if (desc->flags & _DPRINTK_FLAGS_INCL_LINENO)
pos += snprintf(buf + pos, remaining(pos), "%d:",
desc->lineno);
if (pos - pos_after_tid)
pos += snprintf(buf + pos, remaining(pos), " ");
if (pos >= PREFIX_SIZE)
buf[PREFIX_SIZE - 1] = '\0';
return buf;
}
int __dynamic_pr_debug(struct _ddebug *descriptor, const char *fmt, ...)
{
va_list args;
int res;
struct va_format vaf;
char buf[PREFIX_SIZE];
BUG_ON(!descriptor);
BUG_ON(!fmt);
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
res = printk(KERN_DEBUG "%s%pV",
dynamic_emit_prefix(descriptor, buf), &vaf);
va_end(args);
return res;
}
int __dynamic_dev_dbg(struct _ddebug *descriptor,
const struct device *dev, const char *fmt, ...)
{
struct va_format vaf;
va_list args;
int res;
BUG_ON(!descriptor);
BUG_ON(!fmt);
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
if (!dev) {
res = printk(KERN_DEBUG "(NULL device *): %pV", &vaf);
} else {
char buf[PREFIX_SIZE];
res = dev_printk_emit(7, dev, "%s%s %s: %pV",
dynamic_emit_prefix(descriptor, buf),
dev_driver_string(dev), dev_name(dev),
&vaf);
}
va_end(args);
return res;
}
int __dynamic_netdev_dbg(struct _ddebug *descriptor,
const struct net_device *dev, const char *fmt, ...)
{
struct va_format vaf;
va_list args;
int res;
BUG_ON(!descriptor);
BUG_ON(!fmt);
va_start(args, fmt);
vaf.fmt = fmt;
vaf.va = &args;
if (dev && dev->dev.parent) {
char buf[PREFIX_SIZE];
res = dev_printk_emit(7, dev->dev.parent,
"%s%s %s %s: %pV",
dynamic_emit_prefix(descriptor, buf),
dev_driver_string(dev->dev.parent),
dev_name(dev->dev.parent),
netdev_name(dev), &vaf);
} else if (dev) {
res = printk(KERN_DEBUG "%s: %pV", netdev_name(dev), &vaf);
} else {
res = printk(KERN_DEBUG "(NULL net_device): %pV", &vaf);
}
va_end(args);
return res;
}
static __init int ddebug_setup_query(char *str)
{
if (strlen(str) >= DDEBUG_STRING_SIZE) {
pr_warn("ddebug boot param string too large\n");
return 0;
}
strlcpy(ddebug_setup_string, str, DDEBUG_STRING_SIZE);
return 1;
}
static ssize_t ddebug_proc_write(struct file *file, const char __user *ubuf,
size_t len, loff_t *offp)
{
char *tmpbuf;
int ret;
if (len == 0)
return 0;
if (len > USER_BUF_PAGE - 1) {
pr_warn("expected <%d bytes into control\n", USER_BUF_PAGE);
return -E2BIG;
}
tmpbuf = kmalloc(len + 1, GFP_KERNEL);
if (!tmpbuf)
return -ENOMEM;
if (copy_from_user(tmpbuf, ubuf, len)) {
kfree(tmpbuf);
return -EFAULT;
}
tmpbuf[len] = '\0';
vpr_info("read %d bytes from userspace\n", (int)len);
ret = ddebug_exec_queries(tmpbuf, NULL);
kfree(tmpbuf);
if (ret < 0)
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
vpr_info("called m=%p *pos=%lld\n", m, (unsigned long long)*pos);
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
vpr_info("called m=%p p=%p *pos=%lld\n",
m, p, (unsigned long long)*pos);
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
char flagsbuf[10];
vpr_info("called m=%p p=%p\n", m, p);
if (p == SEQ_START_TOKEN) {
seq_puts(m,
"# filename:lineno [module]function flags format\n");
return 0;
}
seq_printf(m, "%s:%u [%s]%s =%s \"",
trim_prefix(dp->filename), dp->lineno,
iter->table->mod_name, dp->function,
ddebug_describe_flags(dp, flagsbuf, sizeof(flagsbuf)));
seq_escape(m, dp->format, "\t\r\n\"");
seq_puts(m, "\"\n");
return 0;
}
static void ddebug_proc_stop(struct seq_file *m, void *p)
{
vpr_info("called m=%p p=%p\n", m, p);
mutex_unlock(&ddebug_lock);
}
static int ddebug_proc_open(struct inode *inode, struct file *file)
{
struct ddebug_iter *iter;
int err;
vpr_info("called\n");
iter = kzalloc(sizeof(*iter), GFP_KERNEL);
if (iter == NULL)
return -ENOMEM;
err = seq_open(file, &ddebug_proc_seqops);
if (err) {
kfree(iter);
return err;
}
((struct seq_file *)file->private_data)->private = iter;
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
dt->ddebugs = tab;
mutex_lock(&ddebug_lock);
list_add_tail(&dt->link, &ddebug_tables);
mutex_unlock(&ddebug_lock);
vpr_info("%u debug prints in module %s\n", n, dt->mod_name);
return 0;
}
static int ddebug_dyndbg_param_cb(char *param, char *val,
const char *modname, int on_err)
{
char *sep;
sep = strchr(param, '.');
if (sep) {
*sep = '\0';
modname = param;
param = sep + 1;
}
if (strcmp(param, "dyndbg"))
return on_err;
ddebug_exec_queries((val ? val : "+p"), modname);
return 0;
}
static int ddebug_dyndbg_boot_param_cb(char *param, char *val,
const char *unused)
{
vpr_info("%s=\"%s\"\n", param, val);
return ddebug_dyndbg_param_cb(param, val, NULL, 0);
}
int ddebug_dyndbg_module_param_cb(char *param, char *val, const char *module)
{
vpr_info("module: %s %s=\"%s\"\n", module, param, val);
return ddebug_dyndbg_param_cb(param, val, module, -ENOENT);
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
vpr_info("removing module \"%s\"\n", mod_name);
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
char *cmdline;
int ret = 0;
int n = 0, entries = 0, modct = 0;
int verbose_bytes = 0;
if (__start___verbose == __stop___verbose) {
pr_warn("_ddebug table is empty in a CONFIG_DYNAMIC_DEBUG build\n");
return 1;
}
iter = __start___verbose;
modname = iter->modname;
iter_start = iter;
for (; iter < __stop___verbose; iter++) {
entries++;
verbose_bytes += strlen(iter->modname) + strlen(iter->function)
+ strlen(iter->filename) + strlen(iter->format);
if (strcmp(modname, iter->modname)) {
modct++;
ret = ddebug_add_module(iter_start, n, modname);
if (ret)
goto out_err;
n = 0;
modname = iter->modname;
iter_start = iter;
}
n++;
}
ret = ddebug_add_module(iter_start, n, modname);
if (ret)
goto out_err;
ddebug_init_success = 1;
vpr_info("%d modules, %d entries and %d bytes in ddebug tables, %d bytes in (readonly) verbose section\n",
modct, entries, (int)(modct * sizeof(struct ddebug_table)),
verbose_bytes + (int)(__stop___verbose - __start___verbose));
if (ddebug_setup_string[0] != '\0') {
pr_warn("ddebug_query param name is deprecated, change it to dyndbg\n");
ret = ddebug_exec_queries(ddebug_setup_string, NULL);
if (ret < 0)
pr_warn("Invalid ddebug boot param %s\n",
ddebug_setup_string);
else
pr_info("%d changes by ddebug_query\n", ret);
}
cmdline = kstrdup(saved_command_line, GFP_KERNEL);
parse_args("dyndbg params", cmdline, NULL,
0, 0, 0, &ddebug_dyndbg_boot_param_cb);
kfree(cmdline);
return 0;
out_err:
ddebug_remove_all_tables();
return 0;
}
