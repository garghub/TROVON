OPENSSL_sk_compfunc OPENSSL_sk_set_cmp_func(OPENSSL_STACK *sk, OPENSSL_sk_compfunc c)
{
OPENSSL_sk_compfunc old = sk->comp;
if (sk->comp != c)
sk->sorted = 0;
sk->comp = c;
return old;
}
OPENSSL_STACK *OPENSSL_sk_dup(const OPENSSL_STACK *sk)
{
OPENSSL_STACK *ret;
if ((ret = OPENSSL_malloc(sizeof(*ret))) == NULL)
return NULL;
*ret = *sk;
if ((ret->data = OPENSSL_malloc(sizeof(*ret->data) * sk->num_alloc)) == NULL)
goto err;
memcpy(ret->data, sk->data, sizeof(char *) * sk->num);
return ret;
err:
OPENSSL_sk_free(ret);
return NULL;
}
OPENSSL_STACK *OPENSSL_sk_deep_copy(const OPENSSL_STACK *sk,
OPENSSL_sk_copyfunc copy_func,
OPENSSL_sk_freefunc free_func)
{
OPENSSL_STACK *ret;
int i;
if ((ret = OPENSSL_malloc(sizeof(*ret))) == NULL)
return NULL;
*ret = *sk;
ret->num_alloc = sk->num > MIN_NODES ? sk->num : MIN_NODES;
ret->data = OPENSSL_zalloc(sizeof(*ret->data) * ret->num_alloc);
if (ret->data == NULL) {
OPENSSL_free(ret);
return NULL;
}
for (i = 0; i < ret->num; ++i) {
if (sk->data[i] == NULL)
continue;
if ((ret->data[i] = copy_func(sk->data[i])) == NULL) {
while (--i >= 0)
if (ret->data[i] != NULL)
free_func((void *)ret->data[i]);
OPENSSL_sk_free(ret);
return NULL;
}
}
return ret;
}
OPENSSL_STACK *OPENSSL_sk_new_null(void)
{
return OPENSSL_sk_new((OPENSSL_sk_compfunc)NULL);
}
OPENSSL_STACK *OPENSSL_sk_new(OPENSSL_sk_compfunc c)
{
OPENSSL_STACK *ret;
if ((ret = OPENSSL_zalloc(sizeof(*ret))) == NULL)
goto err;
if ((ret->data = OPENSSL_zalloc(sizeof(*ret->data) * MIN_NODES)) == NULL)
goto err;
ret->comp = c;
ret->num_alloc = MIN_NODES;
return (ret);
err:
OPENSSL_free(ret);
return (NULL);
}
int OPENSSL_sk_insert(OPENSSL_STACK *st, const void *data, int loc)
{
const char **s;
if (st == NULL)
return 0;
if (st->num_alloc <= st->num + 1) {
s = OPENSSL_realloc((char *)st->data,
(unsigned int)sizeof(char *) * st->num_alloc * 2);
if (s == NULL)
return (0);
st->data = s;
st->num_alloc *= 2;
}
if ((loc >= (int)st->num) || (loc < 0))
st->data[st->num] = data;
else {
memmove(&st->data[loc + 1], &st->data[loc],
sizeof(st->data[0]) * (st->num - loc));
st->data[loc] = data;
}
st->num++;
st->sorted = 0;
return (st->num);
}
void *OPENSSL_sk_delete_ptr(OPENSSL_STACK *st, const void *p)
{
int i;
for (i = 0; i < st->num; i++)
if (st->data[i] == p)
return OPENSSL_sk_delete(st, i);
return NULL;
}
void *OPENSSL_sk_delete(OPENSSL_STACK *st, int loc)
{
const char *ret;
if (st == NULL || loc < 0 || loc >= st->num)
return NULL;
ret = st->data[loc];
if (loc != st->num - 1)
memmove(&st->data[loc], &st->data[loc + 1],
sizeof(st->data[0]) * (st->num - loc - 1));
st->num--;
return (void *)ret;
}
static int internal_find(OPENSSL_STACK *st, const void *data,
int ret_val_options)
{
const void *r;
int i;
if (st == NULL)
return -1;
if (st->comp == NULL) {
for (i = 0; i < st->num; i++)
if (st->data[i] == data)
return (i);
return (-1);
}
OPENSSL_sk_sort(st);
if (data == NULL)
return (-1);
r = OBJ_bsearch_ex_(&data, st->data, st->num, sizeof(void *), st->comp,
ret_val_options);
if (r == NULL)
return (-1);
return (int)((const char **)r - st->data);
}
int OPENSSL_sk_find(OPENSSL_STACK *st, const void *data)
{
return internal_find(st, data, OBJ_BSEARCH_FIRST_VALUE_ON_MATCH);
}
int OPENSSL_sk_find_ex(OPENSSL_STACK *st, const void *data)
{
return internal_find(st, data, OBJ_BSEARCH_VALUE_ON_NOMATCH);
}
int OPENSSL_sk_push(OPENSSL_STACK *st, const void *data)
{
return (OPENSSL_sk_insert(st, data, st->num));
}
int OPENSSL_sk_unshift(OPENSSL_STACK *st, const void *data)
{
return (OPENSSL_sk_insert(st, data, 0));
}
void *OPENSSL_sk_shift(OPENSSL_STACK *st)
{
if (st == NULL)
return (NULL);
if (st->num <= 0)
return (NULL);
return (OPENSSL_sk_delete(st, 0));
}
void *OPENSSL_sk_pop(OPENSSL_STACK *st)
{
if (st == NULL)
return (NULL);
if (st->num <= 0)
return (NULL);
return (OPENSSL_sk_delete(st, st->num - 1));
}
void OPENSSL_sk_zero(OPENSSL_STACK *st)
{
if (st == NULL)
return;
if (st->num <= 0)
return;
memset(st->data, 0, sizeof(*st->data) * st->num);
st->num = 0;
}
void OPENSSL_sk_pop_free(OPENSSL_STACK *st, OPENSSL_sk_freefunc func)
{
int i;
if (st == NULL)
return;
for (i = 0; i < st->num; i++)
if (st->data[i] != NULL)
func((char *)st->data[i]);
OPENSSL_sk_free(st);
}
void OPENSSL_sk_free(OPENSSL_STACK *st)
{
if (st == NULL)
return;
OPENSSL_free(st->data);
OPENSSL_free(st);
}
int OPENSSL_sk_num(const OPENSSL_STACK *st)
{
if (st == NULL)
return -1;
return st->num;
}
void *OPENSSL_sk_value(const OPENSSL_STACK *st, int i)
{
if (st == NULL || i < 0 || i >= st->num)
return NULL;
return (void *)st->data[i];
}
void *OPENSSL_sk_set(OPENSSL_STACK *st, int i, const void *data)
{
if (st == NULL || i < 0 || i >= st->num)
return NULL;
st->data[i] = data;
return (void *)st->data[i];
}
void OPENSSL_sk_sort(OPENSSL_STACK *st)
{
if (st && !st->sorted && st->comp != NULL) {
qsort(st->data, st->num, sizeof(char *), st->comp);
st->sorted = 1;
}
}
int OPENSSL_sk_is_sorted(const OPENSSL_STACK *st)
{
if (st == NULL)
return 1;
return st->sorted;
}
