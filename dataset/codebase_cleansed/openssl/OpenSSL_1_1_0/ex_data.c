static EX_CALLBACKS *get_and_lock(int class_index)
{
EX_CALLBACKS *ip;
if (class_index < 0 || class_index >= CRYPTO_EX_INDEX__COUNT) {
CRYPTOerr(CRYPTO_F_GET_AND_LOCK, ERR_R_PASSED_INVALID_ARGUMENT);
return NULL;
}
if (!RUN_ONCE(&ex_data_init, do_ex_data_init)) {
CRYPTOerr(CRYPTO_F_GET_AND_LOCK, ERR_R_MALLOC_FAILURE);
return NULL;
}
if (ex_data_lock == NULL) {
return NULL;
}
ip = &ex_data[class_index];
CRYPTO_THREAD_write_lock(ex_data_lock);
return ip;
}
static void cleanup_cb(EX_CALLBACK *funcs)
{
OPENSSL_free(funcs);
}
void crypto_cleanup_all_ex_data_int(void)
{
int i;
for (i = 0; i < CRYPTO_EX_INDEX__COUNT; ++i) {
EX_CALLBACKS *ip = &ex_data[i];
sk_EX_CALLBACK_pop_free(ip->meth, cleanup_cb);
ip->meth = NULL;
}
CRYPTO_THREAD_lock_free(ex_data_lock);
ex_data_lock = NULL;
}
static void dummy_new(void *parent, void *ptr, CRYPTO_EX_DATA *ad, int idx,
long argl, void *argp)
{
}
static void dummy_free(void *parent, void *ptr, CRYPTO_EX_DATA *ad, int idx,
long argl, void *argp)
{
}
static int dummy_dup(CRYPTO_EX_DATA *to, const CRYPTO_EX_DATA *from,
void *from_d, int idx,
long argl, void *argp)
{
return 0;
}
int CRYPTO_free_ex_index(int class_index, int idx)
{
EX_CALLBACKS *ip = get_and_lock(class_index);
EX_CALLBACK *a;
int toret = 0;
if (ip == NULL)
return 0;
if (idx < 0 || idx >= sk_EX_CALLBACK_num(ip->meth))
goto err;
a = sk_EX_CALLBACK_value(ip->meth, idx);
if (a == NULL)
goto err;
a->new_func = dummy_new;
a->dup_func = dummy_dup;
a->free_func = dummy_free;
toret = 1;
err:
CRYPTO_THREAD_unlock(ex_data_lock);
return toret;
}
int CRYPTO_get_ex_new_index(int class_index, long argl, void *argp,
CRYPTO_EX_new *new_func, CRYPTO_EX_dup *dup_func,
CRYPTO_EX_free *free_func)
{
int toret = -1;
EX_CALLBACK *a;
EX_CALLBACKS *ip = get_and_lock(class_index);
if (ip == NULL)
return -1;
if (ip->meth == NULL) {
ip->meth = sk_EX_CALLBACK_new_null();
if (ip->meth == NULL
|| !sk_EX_CALLBACK_push(ip->meth, NULL)) {
CRYPTOerr(CRYPTO_F_CRYPTO_GET_EX_NEW_INDEX, ERR_R_MALLOC_FAILURE);
goto err;
}
}
a = (EX_CALLBACK *)OPENSSL_malloc(sizeof(*a));
if (a == NULL) {
CRYPTOerr(CRYPTO_F_CRYPTO_GET_EX_NEW_INDEX, ERR_R_MALLOC_FAILURE);
goto err;
}
a->argl = argl;
a->argp = argp;
a->new_func = new_func;
a->dup_func = dup_func;
a->free_func = free_func;
if (!sk_EX_CALLBACK_push(ip->meth, NULL)) {
CRYPTOerr(CRYPTO_F_CRYPTO_GET_EX_NEW_INDEX, ERR_R_MALLOC_FAILURE);
OPENSSL_free(a);
goto err;
}
toret = sk_EX_CALLBACK_num(ip->meth) - 1;
(void)sk_EX_CALLBACK_set(ip->meth, toret, a);
err:
CRYPTO_THREAD_unlock(ex_data_lock);
return toret;
}
int CRYPTO_new_ex_data(int class_index, void *obj, CRYPTO_EX_DATA *ad)
{
int mx, i;
void *ptr;
EX_CALLBACK **storage = NULL;
EX_CALLBACK *stack[10];
EX_CALLBACKS *ip = get_and_lock(class_index);
if (ip == NULL)
return 0;
ad->sk = NULL;
mx = sk_EX_CALLBACK_num(ip->meth);
if (mx > 0) {
if (mx < (int)OSSL_NELEM(stack))
storage = stack;
else
storage = OPENSSL_malloc(sizeof(*storage) * mx);
if (storage != NULL)
for (i = 0; i < mx; i++)
storage[i] = sk_EX_CALLBACK_value(ip->meth, i);
}
CRYPTO_THREAD_unlock(ex_data_lock);
if (mx > 0 && storage == NULL) {
CRYPTOerr(CRYPTO_F_CRYPTO_NEW_EX_DATA, ERR_R_MALLOC_FAILURE);
return 0;
}
for (i = 0; i < mx; i++) {
if (storage[i] && storage[i]->new_func) {
ptr = CRYPTO_get_ex_data(ad, i);
storage[i]->new_func(obj, ptr, ad, i,
storage[i]->argl, storage[i]->argp);
}
}
if (storage != stack)
OPENSSL_free(storage);
return 1;
}
int CRYPTO_dup_ex_data(int class_index, CRYPTO_EX_DATA *to,
const CRYPTO_EX_DATA *from)
{
int mx, j, i;
char *ptr;
EX_CALLBACK *stack[10];
EX_CALLBACK **storage = NULL;
EX_CALLBACKS *ip;
if (from->sk == NULL)
return 1;
if ((ip = get_and_lock(class_index)) == NULL)
return 0;
mx = sk_EX_CALLBACK_num(ip->meth);
j = sk_void_num(from->sk);
if (j < mx)
mx = j;
if (mx > 0) {
if (mx < (int)OSSL_NELEM(stack))
storage = stack;
else
storage = OPENSSL_malloc(sizeof(*storage) * mx);
if (storage != NULL)
for (i = 0; i < mx; i++)
storage[i] = sk_EX_CALLBACK_value(ip->meth, i);
}
CRYPTO_THREAD_unlock(ex_data_lock);
if (mx > 0 && storage == NULL) {
CRYPTOerr(CRYPTO_F_CRYPTO_DUP_EX_DATA, ERR_R_MALLOC_FAILURE);
return 0;
}
for (i = 0; i < mx; i++) {
ptr = CRYPTO_get_ex_data(from, i);
if (storage[i] && storage[i]->dup_func)
storage[i]->dup_func(to, from, &ptr, i,
storage[i]->argl, storage[i]->argp);
CRYPTO_set_ex_data(to, i, ptr);
}
if (storage != stack)
OPENSSL_free(storage);
return 1;
}
void CRYPTO_free_ex_data(int class_index, void *obj, CRYPTO_EX_DATA *ad)
{
int mx, i;
EX_CALLBACKS *ip;
void *ptr;
EX_CALLBACK *stack[10];
EX_CALLBACK **storage = NULL;
if ((ip = get_and_lock(class_index)) == NULL)
return;
mx = sk_EX_CALLBACK_num(ip->meth);
if (mx > 0) {
if (mx < (int)OSSL_NELEM(stack))
storage = stack;
else
storage = OPENSSL_malloc(sizeof(*storage) * mx);
if (storage != NULL)
for (i = 0; i < mx; i++)
storage[i] = sk_EX_CALLBACK_value(ip->meth, i);
}
CRYPTO_THREAD_unlock(ex_data_lock);
if (mx > 0 && storage == NULL) {
CRYPTOerr(CRYPTO_F_CRYPTO_FREE_EX_DATA, ERR_R_MALLOC_FAILURE);
return;
}
for (i = 0; i < mx; i++) {
if (storage[i] && storage[i]->free_func) {
ptr = CRYPTO_get_ex_data(ad, i);
storage[i]->free_func(obj, ptr, ad, i,
storage[i]->argl, storage[i]->argp);
}
}
if (storage != stack)
OPENSSL_free(storage);
sk_void_free(ad->sk);
ad->sk = NULL;
}
int CRYPTO_set_ex_data(CRYPTO_EX_DATA *ad, int idx, void *val)
{
int i;
if (ad->sk == NULL) {
if ((ad->sk = sk_void_new_null()) == NULL) {
CRYPTOerr(CRYPTO_F_CRYPTO_SET_EX_DATA, ERR_R_MALLOC_FAILURE);
return 0;
}
}
for (i = sk_void_num(ad->sk); i <= idx; ++i) {
if (!sk_void_push(ad->sk, NULL)) {
CRYPTOerr(CRYPTO_F_CRYPTO_SET_EX_DATA, ERR_R_MALLOC_FAILURE);
return 0;
}
}
sk_void_set(ad->sk, idx, val);
return 1;
}
void *CRYPTO_get_ex_data(const CRYPTO_EX_DATA *ad, int idx)
{
if (ad->sk == NULL || idx >= sk_void_num(ad->sk))
return NULL;
return sk_void_value(ad->sk, idx);
}
