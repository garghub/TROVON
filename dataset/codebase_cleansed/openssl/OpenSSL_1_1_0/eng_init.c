int engine_unlocked_init(ENGINE *e)
{
int to_return = 1;
if ((e->funct_ref == 0) && e->init)
to_return = e->init(e);
if (to_return) {
e->struct_ref++;
e->funct_ref++;
engine_ref_debug(e, 0, 1);
engine_ref_debug(e, 1, 1);
}
return to_return;
}
int engine_unlocked_finish(ENGINE *e, int unlock_for_handlers)
{
int to_return = 1;
e->funct_ref--;
engine_ref_debug(e, 1, -1);
if ((e->funct_ref == 0) && e->finish) {
if (unlock_for_handlers)
CRYPTO_THREAD_unlock(global_engine_lock);
to_return = e->finish(e);
if (unlock_for_handlers)
CRYPTO_THREAD_write_lock(global_engine_lock);
if (!to_return)
return 0;
}
REF_ASSERT_ISNT(e->funct_ref < 0);
if (!engine_free_util(e, 0)) {
ENGINEerr(ENGINE_F_ENGINE_UNLOCKED_FINISH, ENGINE_R_FINISH_FAILED);
return 0;
}
return to_return;
}
int ENGINE_init(ENGINE *e)
{
int ret;
if (e == NULL) {
ENGINEerr(ENGINE_F_ENGINE_INIT, ERR_R_PASSED_NULL_PARAMETER);
return 0;
}
if (!RUN_ONCE(&engine_lock_init, do_engine_lock_init)) {
ENGINEerr(ENGINE_F_ENGINE_INIT, ERR_R_MALLOC_FAILURE);
return 0;
}
CRYPTO_THREAD_write_lock(global_engine_lock);
ret = engine_unlocked_init(e);
CRYPTO_THREAD_unlock(global_engine_lock);
return ret;
}
int ENGINE_finish(ENGINE *e)
{
int to_return = 1;
if (e == NULL)
return 1;
CRYPTO_THREAD_write_lock(global_engine_lock);
to_return = engine_unlocked_finish(e, 1);
CRYPTO_THREAD_unlock(global_engine_lock);
if (!to_return) {
ENGINEerr(ENGINE_F_ENGINE_FINISH, ENGINE_R_FINISH_FAILED);
return 0;
}
return to_return;
}
