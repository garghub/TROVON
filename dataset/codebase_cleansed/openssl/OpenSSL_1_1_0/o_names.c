static int obj_strcmp(const char *a, const char *b)
{
return strcmp(a, b);
}
int OBJ_NAME_init(void)
{
if (names_lh != NULL)
return (1);
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_DISABLE);
names_lh = lh_OBJ_NAME_new(obj_name_hash, obj_name_cmp);
CRYPTO_mem_ctrl(CRYPTO_MEM_CHECK_ENABLE);
return (names_lh != NULL);
}
static int obj_name_cmp(const OBJ_NAME *a, const OBJ_NAME *b)
{
int ret;
ret = a->type - b->type;
if (ret == 0) {
if ((name_funcs_stack != NULL)
&& (sk_NAME_FUNCS_num(name_funcs_stack) > a->type)) {
ret = sk_NAME_FUNCS_value(name_funcs_stack,
a->type)->cmp_func(a->name, b->name);
} else
ret = strcmp(a->name, b->name);
}
return (ret);
}
static unsigned long obj_name_hash(const OBJ_NAME *a)
{
unsigned long ret;
if ((name_funcs_stack != NULL)
&& (sk_NAME_FUNCS_num(name_funcs_stack) > a->type)) {
ret =
sk_NAME_FUNCS_value(name_funcs_stack,
a->type)->hash_func(a->name);
} else {
ret = OPENSSL_LH_strhash(a->name);
}
ret ^= a->type;
return (ret);
}
const char *OBJ_NAME_get(const char *name, int type)
{
OBJ_NAME on, *ret;
int num = 0, alias;
if (name == NULL)
return (NULL);
if ((names_lh == NULL) && !OBJ_NAME_init())
return (NULL);
alias = type & OBJ_NAME_ALIAS;
type &= ~OBJ_NAME_ALIAS;
on.name = name;
on.type = type;
for (;;) {
ret = lh_OBJ_NAME_retrieve(names_lh, &on);
if (ret == NULL)
return (NULL);
if ((ret->alias) && !alias) {
if (++num > 10)
return (NULL);
on.name = ret->data;
} else {
return (ret->data);
}
}
}
int OBJ_NAME_add(const char *name, int type, const char *data)
{
OBJ_NAME *onp, *ret;
int alias;
if ((names_lh == NULL) && !OBJ_NAME_init())
return (0);
alias = type & OBJ_NAME_ALIAS;
type &= ~OBJ_NAME_ALIAS;
onp = OPENSSL_malloc(sizeof(*onp));
if (onp == NULL) {
return 0;
}
onp->name = name;
onp->alias = alias;
onp->type = type;
onp->data = data;
ret = lh_OBJ_NAME_insert(names_lh, onp);
if (ret != NULL) {
if ((name_funcs_stack != NULL)
&& (sk_NAME_FUNCS_num(name_funcs_stack) > ret->type)) {
sk_NAME_FUNCS_value(name_funcs_stack,
ret->type)->free_func(ret->name, ret->type,
ret->data);
}
OPENSSL_free(ret);
} else {
if (lh_OBJ_NAME_error(names_lh)) {
OPENSSL_free(onp);
return 0;
}
}
return 1;
}
int OBJ_NAME_remove(const char *name, int type)
{
OBJ_NAME on, *ret;
if (names_lh == NULL)
return (0);
type &= ~OBJ_NAME_ALIAS;
on.name = name;
on.type = type;
ret = lh_OBJ_NAME_delete(names_lh, &on);
if (ret != NULL) {
if ((name_funcs_stack != NULL)
&& (sk_NAME_FUNCS_num(name_funcs_stack) > ret->type)) {
sk_NAME_FUNCS_value(name_funcs_stack,
ret->type)->free_func(ret->name, ret->type,
ret->data);
}
OPENSSL_free(ret);
return (1);
} else
return (0);
}
static void do_all_fn(const OBJ_NAME *name, OBJ_DOALL *d)
{
if (name->type == d->type)
d->fn(name, d->arg);
}
void OBJ_NAME_do_all(int type, void (*fn) (const OBJ_NAME *, void *arg),
void *arg)
{
OBJ_DOALL d;
d.type = type;
d.fn = fn;
d.arg = arg;
lh_OBJ_NAME_doall_OBJ_DOALL(names_lh, do_all_fn, &d);
}
static void do_all_sorted_fn(const OBJ_NAME *name, void *d_)
{
struct doall_sorted *d = d_;
if (name->type != d->type)
return;
d->names[d->n++] = name;
}
static int do_all_sorted_cmp(const void *n1_, const void *n2_)
{
const OBJ_NAME *const *n1 = n1_;
const OBJ_NAME *const *n2 = n2_;
return strcmp((*n1)->name, (*n2)->name);
}
void OBJ_NAME_do_all_sorted(int type,
void (*fn) (const OBJ_NAME *, void *arg),
void *arg)
{
struct doall_sorted d;
int n;
d.type = type;
d.names =
OPENSSL_malloc(sizeof(*d.names) * lh_OBJ_NAME_num_items(names_lh));
if (d.names != NULL) {
d.n = 0;
OBJ_NAME_do_all(type, do_all_sorted_fn, &d);
qsort((void *)d.names, d.n, sizeof(*d.names), do_all_sorted_cmp);
for (n = 0; n < d.n; ++n)
fn(d.names[n], arg);
OPENSSL_free((void *)d.names);
}
}
static void names_lh_free_doall(OBJ_NAME *onp)
{
if (onp == NULL)
return;
if (free_type < 0 || free_type == onp->type)
OBJ_NAME_remove(onp->name, onp->type);
}
static void name_funcs_free(NAME_FUNCS *ptr)
{
OPENSSL_free(ptr);
}
void OBJ_NAME_cleanup(int type)
{
unsigned long down_load;
if (names_lh == NULL)
return;
free_type = type;
down_load = lh_OBJ_NAME_get_down_load(names_lh);
lh_OBJ_NAME_set_down_load(names_lh, 0);
lh_OBJ_NAME_doall(names_lh, names_lh_free_doall);
if (type < 0) {
lh_OBJ_NAME_free(names_lh);
sk_NAME_FUNCS_pop_free(name_funcs_stack, name_funcs_free);
names_lh = NULL;
name_funcs_stack = NULL;
} else
lh_OBJ_NAME_set_down_load(names_lh, down_load);
}
