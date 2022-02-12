static inline void *get_rloc_data(u32 *dl)
{
return (u8 *)dl + get_rloc_offs(*dl);
}
static inline void *get_loc_data(u32 *dl, void *ent)
{
return (u8 *)ent + get_rloc_offs(*dl);
}
static __kprobes int PRINT_TYPE_FUNC_NAME(string)(struct trace_seq *s,
const char *name,
void *data, void *ent)
{
int len = *(u32 *)data >> 16;
if (!len)
return trace_seq_printf(s, " %s=(fault)", name);
else
return trace_seq_printf(s, " %s=\"%s\"", name,
(const char *)get_loc_data(data, ent));
}
static unsigned long update_symbol_cache(struct symbol_cache *sc)
{
sc->addr = (unsigned long)kallsyms_lookup_name(sc->symbol);
if (sc->addr)
sc->addr += sc->offset;
return sc->addr;
}
static void free_symbol_cache(struct symbol_cache *sc)
{
kfree(sc->symbol);
kfree(sc);
}
static struct symbol_cache *alloc_symbol_cache(const char *sym, long offset)
{
struct symbol_cache *sc;
if (!sym || strlen(sym) == 0)
return NULL;
sc = kzalloc(sizeof(struct symbol_cache), GFP_KERNEL);
if (!sc)
return NULL;
sc->symbol = kstrdup(sym, GFP_KERNEL);
if (!sc->symbol) {
kfree(sc);
return NULL;
}
sc->offset = offset;
update_symbol_cache(sc);
return sc;
}
static __kprobes void update_deref_fetch_param(struct deref_fetch_param *data)
{
if (CHECK_FETCH_FUNCS(deref, data->orig.fn))
update_deref_fetch_param(data->orig.data);
else if (CHECK_FETCH_FUNCS(symbol, data->orig.fn))
update_symbol_cache(data->orig.data);
}
static __kprobes void free_deref_fetch_param(struct deref_fetch_param *data)
{
if (CHECK_FETCH_FUNCS(deref, data->orig.fn))
free_deref_fetch_param(data->orig.data);
else if (CHECK_FETCH_FUNCS(symbol, data->orig.fn))
free_symbol_cache(data->orig.data);
kfree(data);
}
static __kprobes void
update_bitfield_fetch_param(struct bitfield_fetch_param *data)
{
if (CHECK_FETCH_FUNCS(deref, data->orig.fn))
update_deref_fetch_param(data->orig.data);
else if (CHECK_FETCH_FUNCS(symbol, data->orig.fn))
update_symbol_cache(data->orig.data);
}
static __kprobes void
free_bitfield_fetch_param(struct bitfield_fetch_param *data)
{
if (CHECK_FETCH_FUNCS(deref, data->orig.fn))
free_deref_fetch_param(data->orig.data);
else if (CHECK_FETCH_FUNCS(symbol, data->orig.fn))
free_symbol_cache(data->orig.data);
kfree(data);
}
static const struct fetch_type *find_fetch_type(const char *type)
{
int i;
if (!type)
type = DEFAULT_FETCH_TYPE_STR;
if (*type == 'b') {
unsigned long bs;
type = strchr(type, '/');
if (!type)
goto fail;
type++;
if (strict_strtoul(type, 0, &bs))
goto fail;
switch (bs) {
case 8:
return find_fetch_type("u8");
case 16:
return find_fetch_type("u16");
case 32:
return find_fetch_type("u32");
case 64:
return find_fetch_type("u64");
default:
goto fail;
}
}
for (i = 0; i < ARRAY_SIZE(fetch_type_table); i++)
if (strcmp(type, fetch_type_table[i].name) == 0)
return &fetch_type_table[i];
fail:
return NULL;
}
static __kprobes void fetch_stack_address(struct pt_regs *regs,
void *dummy, void *dest)
{
*(unsigned long *)dest = kernel_stack_pointer(regs);
}
static fetch_func_t get_fetch_size_function(const struct fetch_type *type,
fetch_func_t orig_fn)
{
int i;
if (type != &fetch_type_table[FETCH_TYPE_STRING])
return NULL;
for (i = 0; i < FETCH_MTD_END; i++)
if (type->fetch[i] == orig_fn)
return fetch_type_table[FETCH_TYPE_STRSIZE].fetch[i];
WARN_ON(1);
return NULL;
}
int traceprobe_split_symbol_offset(char *symbol, unsigned long *offset)
{
char *tmp;
int ret;
if (!offset)
return -EINVAL;
tmp = strchr(symbol, '+');
if (tmp) {
ret = strict_strtoul(tmp + 1, 0, offset);
if (ret)
return ret;
*tmp = '\0';
} else
*offset = 0;
return 0;
}
static int parse_probe_vars(char *arg, const struct fetch_type *t,
struct fetch_param *f, bool is_return)
{
int ret = 0;
unsigned long param;
if (strcmp(arg, "retval") == 0) {
if (is_return)
f->fn = t->fetch[FETCH_MTD_retval];
else
ret = -EINVAL;
} else if (strncmp(arg, "stack", 5) == 0) {
if (arg[5] == '\0') {
if (strcmp(t->name, DEFAULT_FETCH_TYPE_STR) == 0)
f->fn = fetch_stack_address;
else
ret = -EINVAL;
} else if (isdigit(arg[5])) {
ret = strict_strtoul(arg + 5, 10, &param);
if (ret || param > PARAM_MAX_STACK)
ret = -EINVAL;
else {
f->fn = t->fetch[FETCH_MTD_stack];
f->data = (void *)param;
}
} else
ret = -EINVAL;
} else
ret = -EINVAL;
return ret;
}
static int parse_probe_arg(char *arg, const struct fetch_type *t,
struct fetch_param *f, bool is_return, bool is_kprobe)
{
unsigned long param;
long offset;
char *tmp;
int ret;
ret = 0;
if (!is_kprobe && arg[0] != '%')
return -EINVAL;
switch (arg[0]) {
case '$':
ret = parse_probe_vars(arg + 1, t, f, is_return);
break;
case '%':
ret = regs_query_register_offset(arg + 1);
if (ret >= 0) {
f->fn = t->fetch[FETCH_MTD_reg];
f->data = (void *)(unsigned long)ret;
ret = 0;
}
break;
case '@':
if (isdigit(arg[1])) {
ret = strict_strtoul(arg + 1, 0, &param);
if (ret)
break;
f->fn = t->fetch[FETCH_MTD_memory];
f->data = (void *)param;
} else {
ret = traceprobe_split_symbol_offset(arg + 1, &offset);
if (ret)
break;
f->data = alloc_symbol_cache(arg + 1, offset);
if (f->data)
f->fn = t->fetch[FETCH_MTD_symbol];
}
break;
case '+':
arg++;
case '-':
tmp = strchr(arg, '(');
if (!tmp)
break;
*tmp = '\0';
ret = strict_strtol(arg, 0, &offset);
if (ret)
break;
arg = tmp + 1;
tmp = strrchr(arg, ')');
if (tmp) {
struct deref_fetch_param *dprm;
const struct fetch_type *t2;
t2 = find_fetch_type(NULL);
*tmp = '\0';
dprm = kzalloc(sizeof(struct deref_fetch_param), GFP_KERNEL);
if (!dprm)
return -ENOMEM;
dprm->offset = offset;
ret = parse_probe_arg(arg, t2, &dprm->orig, is_return,
is_kprobe);
if (ret)
kfree(dprm);
else {
f->fn = t->fetch[FETCH_MTD_deref];
f->data = (void *)dprm;
}
}
break;
}
if (!ret && !f->fn) {
pr_info("%s type has no corresponding fetch method.\n", t->name);
ret = -EINVAL;
}
return ret;
}
static int __parse_bitfield_probe_arg(const char *bf,
const struct fetch_type *t,
struct fetch_param *f)
{
struct bitfield_fetch_param *bprm;
unsigned long bw, bo;
char *tail;
if (*bf != 'b')
return 0;
bprm = kzalloc(sizeof(*bprm), GFP_KERNEL);
if (!bprm)
return -ENOMEM;
bprm->orig = *f;
f->fn = t->fetch[FETCH_MTD_bitfield];
f->data = (void *)bprm;
bw = simple_strtoul(bf + 1, &tail, 0);
if (bw == 0 || *tail != '@')
return -EINVAL;
bf = tail + 1;
bo = simple_strtoul(bf, &tail, 0);
if (tail == bf || *tail != '/')
return -EINVAL;
bprm->hi_shift = BYTES_TO_BITS(t->size) - (bw + bo);
bprm->low_shift = bprm->hi_shift + bo;
return (BYTES_TO_BITS(t->size) < (bw + bo)) ? -EINVAL : 0;
}
int traceprobe_parse_probe_arg(char *arg, ssize_t *size,
struct probe_arg *parg, bool is_return, bool is_kprobe)
{
const char *t;
int ret;
if (strlen(arg) > MAX_ARGSTR_LEN) {
pr_info("Argument is too long.: %s\n", arg);
return -ENOSPC;
}
parg->comm = kstrdup(arg, GFP_KERNEL);
if (!parg->comm) {
pr_info("Failed to allocate memory for command '%s'.\n", arg);
return -ENOMEM;
}
t = strchr(parg->comm, ':');
if (t) {
arg[t - parg->comm] = '\0';
t++;
}
parg->type = find_fetch_type(t);
if (!parg->type) {
pr_info("Unsupported type: %s\n", t);
return -EINVAL;
}
parg->offset = *size;
*size += parg->type->size;
ret = parse_probe_arg(arg, parg->type, &parg->fetch, is_return, is_kprobe);
if (ret >= 0 && t != NULL)
ret = __parse_bitfield_probe_arg(t, parg->type, &parg->fetch);
if (ret >= 0) {
parg->fetch_size.fn = get_fetch_size_function(parg->type,
parg->fetch.fn);
parg->fetch_size.data = parg->fetch.data;
}
return ret;
}
int traceprobe_conflict_field_name(const char *name,
struct probe_arg *args, int narg)
{
int i;
for (i = 0; i < ARRAY_SIZE(reserved_field_names); i++)
if (strcmp(reserved_field_names[i], name) == 0)
return 1;
for (i = 0; i < narg; i++)
if (strcmp(args[i].name, name) == 0)
return 1;
return 0;
}
void traceprobe_update_arg(struct probe_arg *arg)
{
if (CHECK_FETCH_FUNCS(bitfield, arg->fetch.fn))
update_bitfield_fetch_param(arg->fetch.data);
else if (CHECK_FETCH_FUNCS(deref, arg->fetch.fn))
update_deref_fetch_param(arg->fetch.data);
else if (CHECK_FETCH_FUNCS(symbol, arg->fetch.fn))
update_symbol_cache(arg->fetch.data);
}
void traceprobe_free_probe_arg(struct probe_arg *arg)
{
if (CHECK_FETCH_FUNCS(bitfield, arg->fetch.fn))
free_bitfield_fetch_param(arg->fetch.data);
else if (CHECK_FETCH_FUNCS(deref, arg->fetch.fn))
free_deref_fetch_param(arg->fetch.data);
else if (CHECK_FETCH_FUNCS(symbol, arg->fetch.fn))
free_symbol_cache(arg->fetch.data);
kfree(arg->name);
kfree(arg->comm);
}
int traceprobe_command(const char *buf, int (*createfn)(int, char **))
{
char **argv;
int argc, ret;
argc = 0;
ret = 0;
argv = argv_split(GFP_KERNEL, buf, &argc);
if (!argv)
return -ENOMEM;
if (argc)
ret = createfn(argc, argv);
argv_free(argv);
return ret;
}
ssize_t traceprobe_probes_write(struct file *file, const char __user *buffer,
size_t count, loff_t *ppos,
int (*createfn)(int, char **))
{
char *kbuf, *tmp;
int ret = 0;
size_t done = 0;
size_t size;
kbuf = kmalloc(WRITE_BUFSIZE, GFP_KERNEL);
if (!kbuf)
return -ENOMEM;
while (done < count) {
size = count - done;
if (size >= WRITE_BUFSIZE)
size = WRITE_BUFSIZE - 1;
if (copy_from_user(kbuf, buffer + done, size)) {
ret = -EFAULT;
goto out;
}
kbuf[size] = '\0';
tmp = strchr(kbuf, '\n');
if (tmp) {
*tmp = '\0';
size = tmp - kbuf + 1;
} else if (done + size < count) {
pr_warning("Line length is too long: "
"Should be less than %d.", WRITE_BUFSIZE);
ret = -EINVAL;
goto out;
}
done += size;
tmp = strchr(kbuf, '#');
if (tmp)
*tmp = '\0';
ret = traceprobe_command(kbuf, createfn);
if (ret)
goto out;
}
ret = done;
out:
kfree(kbuf);
return ret;
}
