static void impl_check(void)
{
CRYPTO_w_lock(CRYPTO_LOCK_EX_DATA);
if(!impl)
impl = &impl_default;
CRYPTO_w_unlock(CRYPTO_LOCK_EX_DATA);
}
const CRYPTO_EX_DATA_IMPL *CRYPTO_get_ex_data_implementation(void)
{
IMPL_CHECK
return impl;
}
int CRYPTO_set_ex_data_implementation(const CRYPTO_EX_DATA_IMPL *i)
{
int toret = 0;
CRYPTO_w_lock(CRYPTO_LOCK_EX_DATA);
if(!impl)
{
impl = i;
toret = 1;
}
CRYPTO_w_unlock(CRYPTO_LOCK_EX_DATA);
return toret;
}
static unsigned long ex_hash_cb(const void *a_void)
{
return ((const EX_CLASS_ITEM *)a_void)->class_index;
}
static int ex_cmp_cb(const void *a_void, const void *b_void)
{
return (((const EX_CLASS_ITEM *)a_void)->class_index -
((const EX_CLASS_ITEM *)b_void)->class_index);
}
static int ex_data_check(void)
{
int toret = 1;
CRYPTO_w_lock(CRYPTO_LOCK_EX_DATA);
if(!ex_data && ((ex_data = lh_new(ex_hash_cb, ex_cmp_cb)) == NULL))
toret = 0;
CRYPTO_w_unlock(CRYPTO_LOCK_EX_DATA);
return toret;
}
static void def_cleanup_util_cb(CRYPTO_EX_DATA_FUNCS *funcs)
{
OPENSSL_free(funcs);
}
static void def_cleanup_cb(const void *a_void)
{
EX_CLASS_ITEM *item = (EX_CLASS_ITEM *)a_void;
sk_CRYPTO_EX_DATA_FUNCS_pop_free(item->meth, def_cleanup_util_cb);
OPENSSL_free(item);
}
static EX_CLASS_ITEM *def_get_class(int class_index)
{
EX_CLASS_ITEM d, *p, *gen;
EX_DATA_CHECK(return NULL;)
d.class_index = class_index;
CRYPTO_w_lock(CRYPTO_LOCK_EX_DATA);
p = lh_retrieve(ex_data, &d);
if(!p)
{
gen = OPENSSL_malloc(sizeof(EX_CLASS_ITEM));
if(gen)
{
gen->class_index = class_index;
gen->meth_num = 0;
gen->meth = sk_CRYPTO_EX_DATA_FUNCS_new_null();
if(!gen->meth)
OPENSSL_free(gen);
else
{
lh_insert(ex_data, gen);
p = gen;
}
}
}
CRYPTO_w_unlock(CRYPTO_LOCK_EX_DATA);
if(!p)
CRYPTOerr(CRYPTO_F_DEF_GET_CLASS,ERR_R_MALLOC_FAILURE);
return p;
}
static int def_add_index(EX_CLASS_ITEM *item, long argl, void *argp,
CRYPTO_EX_new *new_func, CRYPTO_EX_dup *dup_func,
CRYPTO_EX_free *free_func)
{
int toret = -1;
CRYPTO_EX_DATA_FUNCS *a = (CRYPTO_EX_DATA_FUNCS *)OPENSSL_malloc(
sizeof(CRYPTO_EX_DATA_FUNCS));
if(!a)
{
CRYPTOerr(CRYPTO_F_DEF_ADD_INDEX,ERR_R_MALLOC_FAILURE);
return -1;
}
a->argl=argl;
a->argp=argp;
a->new_func=new_func;
a->dup_func=dup_func;
a->free_func=free_func;
CRYPTO_w_lock(CRYPTO_LOCK_EX_DATA);
while (sk_CRYPTO_EX_DATA_FUNCS_num(item->meth) <= item->meth_num)
{
if (!sk_CRYPTO_EX_DATA_FUNCS_push(item->meth, NULL))
{
CRYPTOerr(CRYPTO_F_DEF_ADD_INDEX,ERR_R_MALLOC_FAILURE);
OPENSSL_free(a);
goto err;
}
}
toret = item->meth_num++;
sk_CRYPTO_EX_DATA_FUNCS_set(item->meth, toret, a);
err:
CRYPTO_w_unlock(CRYPTO_LOCK_EX_DATA);
return toret;
}
static int int_new_class(void)
{
int toret;
CRYPTO_w_lock(CRYPTO_LOCK_EX_DATA);
toret = ex_class++;
CRYPTO_w_unlock(CRYPTO_LOCK_EX_DATA);
return toret;
}
static void int_cleanup(void)
{
EX_DATA_CHECK(return;)
lh_doall(ex_data, def_cleanup_cb);
lh_free(ex_data);
ex_data = NULL;
impl = NULL;
}
static int int_get_new_index(int class_index, long argl, void *argp,
CRYPTO_EX_new *new_func, CRYPTO_EX_dup *dup_func,
CRYPTO_EX_free *free_func)
{
EX_CLASS_ITEM *item = def_get_class(class_index);
if(!item)
return -1;
return def_add_index(item, argl, argp, new_func, dup_func, free_func);
}
static int int_new_ex_data(int class_index, void *obj,
CRYPTO_EX_DATA *ad)
{
int mx,i;
void *ptr;
CRYPTO_EX_DATA_FUNCS **storage = NULL;
EX_CLASS_ITEM *item = def_get_class(class_index);
if(!item)
return 0;
ad->sk = NULL;
CRYPTO_r_lock(CRYPTO_LOCK_EX_DATA);
mx = sk_CRYPTO_EX_DATA_FUNCS_num(item->meth);
if(mx > 0)
{
storage = OPENSSL_malloc(mx * sizeof(CRYPTO_EX_DATA_FUNCS*));
if(!storage)
goto skip;
for(i = 0; i < mx; i++)
storage[i] = sk_CRYPTO_EX_DATA_FUNCS_value(item->meth,i);
}
skip:
CRYPTO_r_unlock(CRYPTO_LOCK_EX_DATA);
if((mx > 0) && !storage)
{
CRYPTOerr(CRYPTO_F_INT_NEW_EX_DATA,ERR_R_MALLOC_FAILURE);
return 0;
}
for(i = 0; i < mx; i++)
{
if(storage[i] && storage[i]->new_func)
{
ptr = CRYPTO_get_ex_data(ad, i);
storage[i]->new_func(obj,ptr,ad,i,
storage[i]->argl,storage[i]->argp);
}
}
if(storage)
OPENSSL_free(storage);
return 1;
}
static int int_dup_ex_data(int class_index, CRYPTO_EX_DATA *to,
CRYPTO_EX_DATA *from)
{
int mx, j, i;
char *ptr;
CRYPTO_EX_DATA_FUNCS **storage = NULL;
EX_CLASS_ITEM *item;
if(!from->sk)
return 1;
if((item = def_get_class(class_index)) == NULL)
return 0;
CRYPTO_r_lock(CRYPTO_LOCK_EX_DATA);
mx = sk_CRYPTO_EX_DATA_FUNCS_num(item->meth);
j = sk_num(from->sk);
if(j < mx)
mx = j;
if(mx > 0)
{
storage = OPENSSL_malloc(mx * sizeof(CRYPTO_EX_DATA_FUNCS*));
if(!storage)
goto skip;
for(i = 0; i < mx; i++)
storage[i] = sk_CRYPTO_EX_DATA_FUNCS_value(item->meth,i);
}
skip:
CRYPTO_r_unlock(CRYPTO_LOCK_EX_DATA);
if((mx > 0) && !storage)
{
CRYPTOerr(CRYPTO_F_INT_DUP_EX_DATA,ERR_R_MALLOC_FAILURE);
return 0;
}
for(i = 0; i < mx; i++)
{
ptr = CRYPTO_get_ex_data(from, i);
if(storage[i] && storage[i]->dup_func)
storage[i]->dup_func(to,from,&ptr,i,
storage[i]->argl,storage[i]->argp);
CRYPTO_set_ex_data(to,i,ptr);
}
if(storage)
OPENSSL_free(storage);
return 1;
}
static void int_free_ex_data(int class_index, void *obj,
CRYPTO_EX_DATA *ad)
{
int mx,i;
EX_CLASS_ITEM *item;
void *ptr;
CRYPTO_EX_DATA_FUNCS **storage = NULL;
if((item = def_get_class(class_index)) == NULL)
return;
CRYPTO_r_lock(CRYPTO_LOCK_EX_DATA);
mx = sk_CRYPTO_EX_DATA_FUNCS_num(item->meth);
if(mx > 0)
{
storage = OPENSSL_malloc(mx * sizeof(CRYPTO_EX_DATA_FUNCS*));
if(!storage)
goto skip;
for(i = 0; i < mx; i++)
storage[i] = sk_CRYPTO_EX_DATA_FUNCS_value(item->meth,i);
}
skip:
CRYPTO_r_unlock(CRYPTO_LOCK_EX_DATA);
if((mx > 0) && !storage)
{
CRYPTOerr(CRYPTO_F_INT_FREE_EX_DATA,ERR_R_MALLOC_FAILURE);
return;
}
for(i = 0; i < mx; i++)
{
if(storage[i] && storage[i]->free_func)
{
ptr = CRYPTO_get_ex_data(ad,i);
storage[i]->free_func(obj,ptr,ad,i,
storage[i]->argl,storage[i]->argp);
}
}
if(storage)
OPENSSL_free(storage);
if(ad->sk)
{
sk_free(ad->sk);
ad->sk=NULL;
}
}
int CRYPTO_ex_data_new_class(void)
{
IMPL_CHECK
return EX_IMPL(new_class)();
}
void CRYPTO_cleanup_all_ex_data(void)
{
IMPL_CHECK
EX_IMPL(cleanup)();
}
int CRYPTO_get_ex_new_index(int class_index, long argl, void *argp,
CRYPTO_EX_new *new_func, CRYPTO_EX_dup *dup_func,
CRYPTO_EX_free *free_func)
{
int ret = -1;
IMPL_CHECK
ret = EX_IMPL(get_new_index)(class_index,
argl, argp, new_func, dup_func, free_func);
return ret;
}
int CRYPTO_new_ex_data(int class_index, void *obj, CRYPTO_EX_DATA *ad)
{
IMPL_CHECK
return EX_IMPL(new_ex_data)(class_index, obj, ad);
}
int CRYPTO_dup_ex_data(int class_index, CRYPTO_EX_DATA *to,
CRYPTO_EX_DATA *from)
{
IMPL_CHECK
return EX_IMPL(dup_ex_data)(class_index, to, from);
}
void CRYPTO_free_ex_data(int class_index, void *obj, CRYPTO_EX_DATA *ad)
{
IMPL_CHECK
EX_IMPL(free_ex_data)(class_index, obj, ad);
}
int CRYPTO_set_ex_data(CRYPTO_EX_DATA *ad, int idx, void *val)
{
int i;
if (ad->sk == NULL)
{
if ((ad->sk=sk_new_null()) == NULL)
{
CRYPTOerr(CRYPTO_F_CRYPTO_SET_EX_DATA,ERR_R_MALLOC_FAILURE);
return(0);
}
}
i=sk_num(ad->sk);
while (i <= idx)
{
if (!sk_push(ad->sk,NULL))
{
CRYPTOerr(CRYPTO_F_CRYPTO_SET_EX_DATA,ERR_R_MALLOC_FAILURE);
return(0);
}
i++;
}
sk_set(ad->sk,idx,val);
return(1);
}
void *CRYPTO_get_ex_data(const CRYPTO_EX_DATA *ad, int idx)
{
if (ad->sk == NULL)
return(0);
else if (idx >= sk_num(ad->sk))
return(0);
else
return(sk_value(ad->sk,idx));
}
