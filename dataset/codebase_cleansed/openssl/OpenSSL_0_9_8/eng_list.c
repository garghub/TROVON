static void engine_list_cleanup(void)
{
ENGINE *iterator = engine_list_head;
while(iterator != NULL)
{
ENGINE_remove(iterator);
iterator = engine_list_head;
}
return;
}
static int engine_list_add(ENGINE *e)
{
int conflict = 0;
ENGINE *iterator = NULL;
if(e == NULL)
{
ENGINEerr(ENGINE_F_ENGINE_LIST_ADD,
ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
iterator = engine_list_head;
while(iterator && !conflict)
{
conflict = (strcmp(iterator->id, e->id) == 0);
iterator = iterator->next;
}
if(conflict)
{
ENGINEerr(ENGINE_F_ENGINE_LIST_ADD,
ENGINE_R_CONFLICTING_ENGINE_ID);
return 0;
}
if(engine_list_head == NULL)
{
if(engine_list_tail)
{
ENGINEerr(ENGINE_F_ENGINE_LIST_ADD,
ENGINE_R_INTERNAL_LIST_ERROR);
return 0;
}
engine_list_head = e;
e->prev = NULL;
engine_cleanup_add_last(engine_list_cleanup);
}
else
{
if((engine_list_tail == NULL) ||
(engine_list_tail->next != NULL))
{
ENGINEerr(ENGINE_F_ENGINE_LIST_ADD,
ENGINE_R_INTERNAL_LIST_ERROR);
return 0;
}
engine_list_tail->next = e;
e->prev = engine_list_tail;
}
e->struct_ref++;
engine_ref_debug(e, 0, 1)
engine_list_tail = e;
e->next = NULL;
return 1;
}
static int engine_list_remove(ENGINE *e)
{
ENGINE *iterator;
if(e == NULL)
{
ENGINEerr(ENGINE_F_ENGINE_LIST_REMOVE,
ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
iterator = engine_list_head;
while(iterator && (iterator != e))
iterator = iterator->next;
if(iterator == NULL)
{
ENGINEerr(ENGINE_F_ENGINE_LIST_REMOVE,
ENGINE_R_ENGINE_IS_NOT_IN_LIST);
return 0;
}
if(e->next)
e->next->prev = e->prev;
if(e->prev)
e->prev->next = e->next;
if(engine_list_head == e)
engine_list_head = e->next;
if(engine_list_tail == e)
engine_list_tail = e->prev;
engine_free_util(e, 0);
return 1;
}
ENGINE *ENGINE_get_first(void)
{
ENGINE *ret;
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
ret = engine_list_head;
if(ret)
{
ret->struct_ref++;
engine_ref_debug(ret, 0, 1)
}
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
return ret;
}
ENGINE *ENGINE_get_last(void)
{
ENGINE *ret;
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
ret = engine_list_tail;
if(ret)
{
ret->struct_ref++;
engine_ref_debug(ret, 0, 1)
}
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
return ret;
}
ENGINE *ENGINE_get_next(ENGINE *e)
{
ENGINE *ret = NULL;
if(e == NULL)
{
ENGINEerr(ENGINE_F_ENGINE_GET_NEXT,
ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
ret = e->next;
if(ret)
{
ret->struct_ref++;
engine_ref_debug(ret, 0, 1)
}
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
ENGINE_free(e);
return ret;
}
ENGINE *ENGINE_get_prev(ENGINE *e)
{
ENGINE *ret = NULL;
if(e == NULL)
{
ENGINEerr(ENGINE_F_ENGINE_GET_PREV,
ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
ret = e->prev;
if(ret)
{
ret->struct_ref++;
engine_ref_debug(ret, 0, 1)
}
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
ENGINE_free(e);
return ret;
}
int ENGINE_add(ENGINE *e)
{
int to_return = 1;
if(e == NULL)
{
ENGINEerr(ENGINE_F_ENGINE_ADD,
ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
if((e->id == NULL) || (e->name == NULL))
{
ENGINEerr(ENGINE_F_ENGINE_ADD,
ENGINE_R_ID_OR_NAME_MISSING);
}
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
if(!engine_list_add(e))
{
ENGINEerr(ENGINE_F_ENGINE_ADD,
ENGINE_R_INTERNAL_LIST_ERROR);
to_return = 0;
}
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
return to_return;
}
int ENGINE_remove(ENGINE *e)
{
int to_return = 1;
if(e == NULL)
{
ENGINEerr(ENGINE_F_ENGINE_REMOVE,
ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
if(!engine_list_remove(e))
{
ENGINEerr(ENGINE_F_ENGINE_REMOVE,
ENGINE_R_INTERNAL_LIST_ERROR);
to_return = 0;
}
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
return to_return;
}
static void engine_cpy(ENGINE *dest, const ENGINE *src)
{
dest->id = src->id;
dest->name = src->name;
#ifndef OPENSSL_NO_RSA
dest->rsa_meth = src->rsa_meth;
#endif
#ifndef OPENSSL_NO_DSA
dest->dsa_meth = src->dsa_meth;
#endif
#ifndef OPENSSL_NO_DH
dest->dh_meth = src->dh_meth;
#endif
#ifndef OPENSSL_NO_ECDH
dest->ecdh_meth = src->ecdh_meth;
#endif
#ifndef OPENSSL_NO_ECDSA
dest->ecdsa_meth = src->ecdsa_meth;
#endif
dest->rand_meth = src->rand_meth;
dest->store_meth = src->store_meth;
dest->ciphers = src->ciphers;
dest->digests = src->digests;
dest->destroy = src->destroy;
dest->init = src->init;
dest->finish = src->finish;
dest->ctrl = src->ctrl;
dest->load_privkey = src->load_privkey;
dest->load_pubkey = src->load_pubkey;
dest->cmd_defns = src->cmd_defns;
dest->flags = src->flags;
}
ENGINE *ENGINE_by_id(const char *id)
{
ENGINE *iterator;
char *load_dir = NULL;
if(id == NULL)
{
ENGINEerr(ENGINE_F_ENGINE_BY_ID,
ERR_R_PASSED_NULL_PARAMETER);
return NULL;
}
CRYPTO_w_lock(CRYPTO_LOCK_ENGINE);
iterator = engine_list_head;
while(iterator && (strcmp(id, iterator->id) != 0))
iterator = iterator->next;
if(iterator)
{
if(iterator->flags & ENGINE_FLAGS_BY_ID_COPY)
{
ENGINE *cp = ENGINE_new();
if(!cp)
iterator = NULL;
else
{
engine_cpy(cp, iterator);
iterator = cp;
}
}
else
{
iterator->struct_ref++;
engine_ref_debug(iterator, 0, 1)
}
}
CRYPTO_w_unlock(CRYPTO_LOCK_ENGINE);
#if 0
if(iterator == NULL)
{
ENGINEerr(ENGINE_F_ENGINE_BY_ID,
ENGINE_R_NO_SUCH_ENGINE);
ERR_add_error_data(2, "id=", id);
}
return iterator;
#else
if(iterator) return iterator;
#ifdef OPENSSL_SYS_VMS
if((load_dir = getenv("OPENSSL_ENGINES")) == 0) load_dir = "SSLROOT:[ENGINES]";
#else
if((load_dir = getenv("OPENSSL_ENGINES")) == 0) load_dir = ENGINESDIR;
#endif
iterator = ENGINE_by_id("dynamic");
if(!iterator || !ENGINE_ctrl_cmd_string(iterator, "ID", id, 0) ||
!ENGINE_ctrl_cmd_string(iterator, "DIR_LOAD", "2", 0) ||
!ENGINE_ctrl_cmd_string(iterator, "DIR_ADD",
load_dir, 0) ||
!ENGINE_ctrl_cmd_string(iterator, "LOAD", NULL, 0))
goto notfound;
return iterator;
notfound:
ENGINEerr(ENGINE_F_ENGINE_BY_ID,ENGINE_R_NO_SUCH_ENGINE);
ERR_add_error_data(2, "id=", id);
return NULL;
#endif
}
int ENGINE_up_ref(ENGINE *e)
{
if (e == NULL)
{
ENGINEerr(ENGINE_F_ENGINE_UP_REF,ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
CRYPTO_add(&e->struct_ref,1,CRYPTO_LOCK_ENGINE);
return 1;
}
