static void int_free_str(char *s)
{
OPENSSL_free(s);
}
static void dynamic_data_ctx_free_func(void *parent, void *ptr,
CRYPTO_EX_DATA *ad, int idx, long argl,
void *argp)
{
if (ptr) {
dynamic_data_ctx *ctx = (dynamic_data_ctx *)ptr;
DSO_free(ctx->dynamic_dso);
OPENSSL_free(ctx->DYNAMIC_LIBNAME);
OPENSSL_free(ctx->engine_id);
sk_OPENSSL_STRING_pop_free(ctx->dirs, int_free_str);
OPENSSL_free(ctx);
}
}
static int dynamic_set_data_ctx(ENGINE *e, dynamic_data_ctx **ctx)
{
dynamic_data_ctx *c = OPENSSL_zalloc(sizeof(*c));
int ret = 1;
if (c == NULL) {
ENGINEerr(ENGINE_F_DYNAMIC_SET_DATA_CTX, ERR_R_MALLOC_FAILURE);
return 0;
}
c->dirs = sk_OPENSSL_STRING_new_null();
if (c->dirs == NULL) {
ENGINEerr(ENGINE_F_DYNAMIC_SET_DATA_CTX, ERR_R_MALLOC_FAILURE);
OPENSSL_free(c);
return 0;
}
c->DYNAMIC_F1 = "v_check";
c->DYNAMIC_F2 = "bind_engine";
c->dir_load = 1;
CRYPTO_THREAD_write_lock(global_engine_lock);
if ((*ctx = (dynamic_data_ctx *)ENGINE_get_ex_data(e,
dynamic_ex_data_idx))
== NULL) {
ret = ENGINE_set_ex_data(e, dynamic_ex_data_idx, c);
if (ret) {
*ctx = c;
c = NULL;
}
}
CRYPTO_THREAD_unlock(global_engine_lock);
if (c)
sk_OPENSSL_STRING_free(c->dirs);
OPENSSL_free(c);
return ret;
}
static dynamic_data_ctx *dynamic_get_data_ctx(ENGINE *e)
{
dynamic_data_ctx *ctx;
if (dynamic_ex_data_idx < 0) {
int new_idx = ENGINE_get_ex_new_index(0, NULL, NULL, NULL,
dynamic_data_ctx_free_func);
if (new_idx == -1) {
ENGINEerr(ENGINE_F_DYNAMIC_GET_DATA_CTX, ENGINE_R_NO_INDEX);
return NULL;
}
CRYPTO_THREAD_write_lock(global_engine_lock);
if (dynamic_ex_data_idx < 0) {
dynamic_ex_data_idx = new_idx;
new_idx = -1;
}
CRYPTO_THREAD_unlock(global_engine_lock);
}
ctx = (dynamic_data_ctx *)ENGINE_get_ex_data(e, dynamic_ex_data_idx);
if ((ctx == NULL) && !dynamic_set_data_ctx(e, &ctx))
return NULL;
return ctx;
}
static ENGINE *engine_dynamic(void)
{
ENGINE *ret = ENGINE_new();
if (ret == NULL)
return NULL;
if (!ENGINE_set_id(ret, engine_dynamic_id) ||
!ENGINE_set_name(ret, engine_dynamic_name) ||
!ENGINE_set_init_function(ret, dynamic_init) ||
!ENGINE_set_finish_function(ret, dynamic_finish) ||
!ENGINE_set_ctrl_function(ret, dynamic_ctrl) ||
!ENGINE_set_flags(ret, ENGINE_FLAGS_BY_ID_COPY) ||
!ENGINE_set_cmd_defns(ret, dynamic_cmd_defns)) {
ENGINE_free(ret);
return NULL;
}
return ret;
}
void engine_load_dynamic_int(void)
{
ENGINE *toadd = engine_dynamic();
if (!toadd)
return;
ENGINE_add(toadd);
ENGINE_free(toadd);
ERR_clear_error();
}
static int dynamic_init(ENGINE *e)
{
return 0;
}
static int dynamic_finish(ENGINE *e)
{
return 0;
}
static int dynamic_ctrl(ENGINE *e, int cmd, long i, void *p, void (*f) (void))
{
dynamic_data_ctx *ctx = dynamic_get_data_ctx(e);
int initialised;
if (!ctx) {
ENGINEerr(ENGINE_F_DYNAMIC_CTRL, ENGINE_R_NOT_LOADED);
return 0;
}
initialised = ((ctx->dynamic_dso == NULL) ? 0 : 1);
if (initialised) {
ENGINEerr(ENGINE_F_DYNAMIC_CTRL, ENGINE_R_ALREADY_LOADED);
return 0;
}
switch (cmd) {
case DYNAMIC_CMD_SO_PATH:
if (p && (strlen((const char *)p) < 1))
p = NULL;
OPENSSL_free(ctx->DYNAMIC_LIBNAME);
if (p)
ctx->DYNAMIC_LIBNAME = OPENSSL_strdup(p);
else
ctx->DYNAMIC_LIBNAME = NULL;
return (ctx->DYNAMIC_LIBNAME ? 1 : 0);
case DYNAMIC_CMD_NO_VCHECK:
ctx->no_vcheck = ((i == 0) ? 0 : 1);
return 1;
case DYNAMIC_CMD_ID:
if (p && (strlen((const char *)p) < 1))
p = NULL;
OPENSSL_free(ctx->engine_id);
if (p)
ctx->engine_id = OPENSSL_strdup(p);
else
ctx->engine_id = NULL;
return (ctx->engine_id ? 1 : 0);
case DYNAMIC_CMD_LIST_ADD:
if ((i < 0) || (i > 2)) {
ENGINEerr(ENGINE_F_DYNAMIC_CTRL, ENGINE_R_INVALID_ARGUMENT);
return 0;
}
ctx->list_add_value = (int)i;
return 1;
case DYNAMIC_CMD_LOAD:
return dynamic_load(e, ctx);
case DYNAMIC_CMD_DIR_LOAD:
if ((i < 0) || (i > 2)) {
ENGINEerr(ENGINE_F_DYNAMIC_CTRL, ENGINE_R_INVALID_ARGUMENT);
return 0;
}
ctx->dir_load = (int)i;
return 1;
case DYNAMIC_CMD_DIR_ADD:
if (!p || (strlen((const char *)p) < 1)) {
ENGINEerr(ENGINE_F_DYNAMIC_CTRL, ENGINE_R_INVALID_ARGUMENT);
return 0;
}
{
char *tmp_str = OPENSSL_strdup(p);
if (tmp_str == NULL) {
ENGINEerr(ENGINE_F_DYNAMIC_CTRL, ERR_R_MALLOC_FAILURE);
return 0;
}
if (!sk_OPENSSL_STRING_push(ctx->dirs, tmp_str)) {
OPENSSL_free(tmp_str);
ENGINEerr(ENGINE_F_DYNAMIC_CTRL, ERR_R_MALLOC_FAILURE);
return 0;
}
}
return 1;
default:
break;
}
ENGINEerr(ENGINE_F_DYNAMIC_CTRL, ENGINE_R_CTRL_COMMAND_NOT_IMPLEMENTED);
return 0;
}
static int int_load(dynamic_data_ctx *ctx)
{
int num, loop;
if ((ctx->dir_load != 2) && (DSO_load(ctx->dynamic_dso,
ctx->DYNAMIC_LIBNAME, NULL,
0)) != NULL)
return 1;
if (!ctx->dir_load || (num = sk_OPENSSL_STRING_num(ctx->dirs)) < 1)
return 0;
for (loop = 0; loop < num; loop++) {
const char *s = sk_OPENSSL_STRING_value(ctx->dirs, loop);
char *merge = DSO_merge(ctx->dynamic_dso, ctx->DYNAMIC_LIBNAME, s);
if (!merge)
return 0;
if (DSO_load(ctx->dynamic_dso, merge, NULL, 0)) {
OPENSSL_free(merge);
return 1;
}
OPENSSL_free(merge);
}
return 0;
}
static int dynamic_load(ENGINE *e, dynamic_data_ctx *ctx)
{
ENGINE cpy;
dynamic_fns fns;
if (ctx->dynamic_dso == NULL)
ctx->dynamic_dso = DSO_new();
if (ctx->dynamic_dso == NULL)
return 0;
if (!ctx->DYNAMIC_LIBNAME) {
if (!ctx->engine_id)
return 0;
DSO_ctrl(ctx->dynamic_dso, DSO_CTRL_SET_FLAGS,
DSO_FLAG_NAME_TRANSLATION_EXT_ONLY, NULL);
ctx->DYNAMIC_LIBNAME =
DSO_convert_filename(ctx->dynamic_dso, ctx->engine_id);
}
if (!int_load(ctx)) {
ENGINEerr(ENGINE_F_DYNAMIC_LOAD, ENGINE_R_DSO_NOT_FOUND);
DSO_free(ctx->dynamic_dso);
ctx->dynamic_dso = NULL;
return 0;
}
if (!
(ctx->bind_engine =
(dynamic_bind_engine) DSO_bind_func(ctx->dynamic_dso,
ctx->DYNAMIC_F2))) {
ctx->bind_engine = NULL;
DSO_free(ctx->dynamic_dso);
ctx->dynamic_dso = NULL;
ENGINEerr(ENGINE_F_DYNAMIC_LOAD, ENGINE_R_DSO_FAILURE);
return 0;
}
if (!ctx->no_vcheck) {
unsigned long vcheck_res = 0;
ctx->v_check =
(dynamic_v_check_fn) DSO_bind_func(ctx->dynamic_dso,
ctx->DYNAMIC_F1);
if (ctx->v_check)
vcheck_res = ctx->v_check(OSSL_DYNAMIC_VERSION);
if (vcheck_res < OSSL_DYNAMIC_OLDEST) {
ctx->bind_engine = NULL;
ctx->v_check = NULL;
DSO_free(ctx->dynamic_dso);
ctx->dynamic_dso = NULL;
ENGINEerr(ENGINE_F_DYNAMIC_LOAD,
ENGINE_R_VERSION_INCOMPATIBILITY);
return 0;
}
}
memcpy(&cpy, e, sizeof(ENGINE));
fns.static_state = ENGINE_get_static_state();
CRYPTO_get_mem_functions(&fns.mem_fns.malloc_fn, &fns.mem_fns.realloc_fn,
&fns.mem_fns.free_fn);
engine_set_all_null(e);
if (!ctx->bind_engine(e, ctx->engine_id, &fns)) {
ctx->bind_engine = NULL;
ctx->v_check = NULL;
DSO_free(ctx->dynamic_dso);
ctx->dynamic_dso = NULL;
ENGINEerr(ENGINE_F_DYNAMIC_LOAD, ENGINE_R_INIT_FAILED);
memcpy(e, &cpy, sizeof(ENGINE));
return 0;
}
if (ctx->list_add_value > 0) {
if (!ENGINE_add(e)) {
if (ctx->list_add_value > 1) {
ENGINEerr(ENGINE_F_DYNAMIC_LOAD,
ENGINE_R_CONFLICTING_ENGINE_ID);
return 0;
}
ERR_clear_error();
}
}
return 1;
}
