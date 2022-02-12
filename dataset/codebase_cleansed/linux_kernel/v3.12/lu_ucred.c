struct lu_ucred *lu_ucred(const struct lu_env *env)
{
if (!env->le_ses)
return NULL;
return lu_context_key_get(env->le_ses, &lu_ucred_key);
}
struct lu_ucred *lu_ucred_check(const struct lu_env *env)
{
struct lu_ucred *uc = lu_ucred(env);
if (uc && uc->uc_valid != UCRED_OLD && uc->uc_valid != UCRED_NEW)
return NULL;
return uc;
}
struct lu_ucred *lu_ucred_assert(const struct lu_env *env)
{
struct lu_ucred *uc = lu_ucred_check(env);
LASSERT(uc != NULL);
return uc;
}
int lu_ucred_global_init(void)
{
LU_CONTEXT_KEY_INIT(&lu_ucred_key);
return lu_context_key_register(&lu_ucred_key);
}
void lu_ucred_global_fini(void)
{
lu_context_key_degister(&lu_ucred_key);
}
