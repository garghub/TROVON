STORE_METHOD *STORE_create_method(char *name)
{
STORE_METHOD *store_method = (STORE_METHOD *)OPENSSL_malloc(sizeof(STORE_METHOD));
if (store_method)
memset(store_method, 0, sizeof(*store_method));
store_method->name = BUF_strdup(name);
return store_method;
}
void STORE_destroy_method(STORE_METHOD *store_method)
{
if (!store_method) return;
OPENSSL_free(store_method->name);
store_method->name = NULL;
OPENSSL_free(store_method);
}
int STORE_method_set_initialise_function(STORE_METHOD *sm, STORE_INITIALISE_FUNC_PTR init_f)
{
sm->init = init_f;
return 1;
}
int STORE_method_set_cleanup_function(STORE_METHOD *sm, STORE_CLEANUP_FUNC_PTR clean_f)
{
sm->clean = clean_f;
return 1;
}
int STORE_method_set_generate_function(STORE_METHOD *sm, STORE_GENERATE_OBJECT_FUNC_PTR generate_f)
{
sm->generate_object = generate_f;
return 1;
}
int STORE_method_set_get_function(STORE_METHOD *sm, STORE_GET_OBJECT_FUNC_PTR get_f)
{
sm->get_object = get_f;
return 1;
}
int STORE_method_set_store_function(STORE_METHOD *sm, STORE_STORE_OBJECT_FUNC_PTR store_f)
{
sm->store_object = store_f;
return 1;
}
int STORE_method_set_modify_function(STORE_METHOD *sm, STORE_MODIFY_OBJECT_FUNC_PTR modify_f)
{
sm->modify_object = modify_f;
return 1;
}
int STORE_method_set_revoke_function(STORE_METHOD *sm, STORE_HANDLE_OBJECT_FUNC_PTR revoke_f)
{
sm->revoke_object = revoke_f;
return 1;
}
int STORE_method_set_delete_function(STORE_METHOD *sm, STORE_HANDLE_OBJECT_FUNC_PTR delete_f)
{
sm->delete_object = delete_f;
return 1;
}
int STORE_method_set_list_start_function(STORE_METHOD *sm, STORE_START_OBJECT_FUNC_PTR list_start_f)
{
sm->list_object_start = list_start_f;
return 1;
}
int STORE_method_set_list_next_function(STORE_METHOD *sm, STORE_NEXT_OBJECT_FUNC_PTR list_next_f)
{
sm->list_object_next = list_next_f;
return 1;
}
int STORE_method_set_list_end_function(STORE_METHOD *sm, STORE_END_OBJECT_FUNC_PTR list_end_f)
{
sm->list_object_end = list_end_f;
return 1;
}
int STORE_method_set_update_store_function(STORE_METHOD *sm, STORE_GENERIC_FUNC_PTR update_f)
{
sm->update_store = update_f;
return 1;
}
int STORE_method_set_lock_store_function(STORE_METHOD *sm, STORE_GENERIC_FUNC_PTR lock_f)
{
sm->lock_store = lock_f;
return 1;
}
int STORE_method_set_unlock_store_function(STORE_METHOD *sm, STORE_GENERIC_FUNC_PTR unlock_f)
{
sm->unlock_store = unlock_f;
return 1;
}
int STORE_method_set_ctrl_function(STORE_METHOD *sm, STORE_CTRL_FUNC_PTR ctrl_f)
{
sm->ctrl = ctrl_f;
return 1;
}
STORE_INITIALISE_FUNC_PTR STORE_method_get_initialise_function(STORE_METHOD *sm)
{
return sm->init;
}
STORE_CLEANUP_FUNC_PTR STORE_method_get_cleanup_function(STORE_METHOD *sm)
{
return sm->clean;
}
STORE_GENERATE_OBJECT_FUNC_PTR STORE_method_get_generate_function(STORE_METHOD *sm)
{
return sm->generate_object;
}
STORE_GET_OBJECT_FUNC_PTR STORE_method_get_get_function(STORE_METHOD *sm)
{
return sm->get_object;
}
STORE_STORE_OBJECT_FUNC_PTR STORE_method_get_store_function(STORE_METHOD *sm)
{
return sm->store_object;
}
STORE_MODIFY_OBJECT_FUNC_PTR STORE_method_get_modify_function(STORE_METHOD *sm)
{
return sm->modify_object;
}
STORE_HANDLE_OBJECT_FUNC_PTR STORE_method_get_revoke_function(STORE_METHOD *sm)
{
return sm->revoke_object;
}
STORE_HANDLE_OBJECT_FUNC_PTR STORE_method_get_delete_function(STORE_METHOD *sm)
{
return sm->delete_object;
}
STORE_START_OBJECT_FUNC_PTR STORE_method_get_list_start_function(STORE_METHOD *sm)
{
return sm->list_object_start;
}
STORE_NEXT_OBJECT_FUNC_PTR STORE_method_get_list_next_function(STORE_METHOD *sm)
{
return sm->list_object_next;
}
STORE_END_OBJECT_FUNC_PTR STORE_method_get_list_end_function(STORE_METHOD *sm)
{
return sm->list_object_end;
}
STORE_GENERIC_FUNC_PTR STORE_method_get_update_store_function(STORE_METHOD *sm)
{
return sm->update_store;
}
STORE_GENERIC_FUNC_PTR STORE_method_get_lock_store_function(STORE_METHOD *sm)
{
return sm->lock_store;
}
STORE_GENERIC_FUNC_PTR STORE_method_get_unlock_store_function(STORE_METHOD *sm)
{
return sm->unlock_store;
}
STORE_CTRL_FUNC_PTR STORE_method_get_ctrl_function(STORE_METHOD *sm)
{
return sm->ctrl;
}
