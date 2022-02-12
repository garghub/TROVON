void init_capture_stop_conditions(void){
cnd_register_class(CND_CLASS_TIMEOUT,
_cnd_constr_timeout,
_cnd_destr_timeout,
_cnd_eval_timeout,
_cnd_reset_timeout);
cnd_register_class(CND_CLASS_CAPTURESIZE,
_cnd_constr_capturesize,
_cnd_destr_capturesize,
_cnd_eval_capturesize,
_cnd_reset_capturesize);
}
void cleanup_capture_stop_conditions(void){
cnd_unregister_class(CND_CLASS_TIMEOUT);
cnd_unregister_class(CND_CLASS_CAPTURESIZE);
}
static condition* _cnd_constr_timeout(condition* cnd, va_list ap){
cnd_timeout_dat *data = NULL;
if((data = (cnd_timeout_dat*)g_malloc(sizeof(cnd_timeout_dat))) == NULL)
return NULL;
data->start_time = time(NULL);
data->timeout_s = va_arg(ap, gint32);
cnd_set_user_data(cnd, (void*)data);
return cnd;
}
static void _cnd_destr_timeout(condition* cnd){
g_free(cnd_get_user_data(cnd));
}
static gboolean _cnd_eval_timeout(condition* cnd, va_list ap _U_){
cnd_timeout_dat* data = (cnd_timeout_dat*)cnd_get_user_data(cnd);
gint32 elapsed_time;
if(data->timeout_s == 0) return FALSE;
elapsed_time = (gint32) (time(NULL) - data->start_time);
if(elapsed_time >= data->timeout_s) return TRUE;
return FALSE;
}
static void _cnd_reset_timeout(condition *cnd){
((cnd_timeout_dat*)cnd_get_user_data(cnd))->start_time = time(NULL);
}
static condition* _cnd_constr_capturesize(condition* cnd, va_list ap){
cnd_capturesize_dat *data = NULL;
if((data = (cnd_capturesize_dat*)g_malloc(sizeof(cnd_capturesize_dat))) == NULL)
return NULL;
data->max_capture_size = va_arg(ap, long);
cnd_set_user_data(cnd, (void*)data);
return cnd;
}
static void _cnd_destr_capturesize(condition* cnd){
g_free(cnd_get_user_data(cnd));
}
static gboolean _cnd_eval_capturesize(condition* cnd, va_list ap){
cnd_capturesize_dat* data = (cnd_capturesize_dat*)cnd_get_user_data(cnd);
if(data->max_capture_size == 0) return FALSE;
if(va_arg(ap, long) >= data->max_capture_size){
return TRUE;
}
return FALSE;
}
static void _cnd_reset_capturesize(condition *cnd _U_){
}
