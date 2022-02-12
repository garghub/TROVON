static void ossl_init_thread_stop_wrap(void *local)
{
ossl_init_thread_stop((struct thread_local_inits_st *)local);
}
static struct thread_local_inits_st *ossl_init_get_thread_local(int alloc)
{
struct thread_local_inits_st *local =
CRYPTO_THREAD_get_local(&threadstopkey);
if (local == NULL && alloc) {
local = OPENSSL_zalloc(sizeof *local);
CRYPTO_THREAD_set_local(&threadstopkey, local);
}
if (!alloc) {
CRYPTO_THREAD_set_local(&threadstopkey, NULL);
}
return local;
}
static void ossl_init_thread_stop(struct thread_local_inits_st *locals)
{
if (locals == NULL)
return;
if (locals->async) {
#ifdef OPENSSL_INIT_DEBUG
fprintf(stderr, "OPENSSL_INIT: ossl_init_thread_stop: "
"ASYNC_cleanup_thread()\n");
#endif
ASYNC_cleanup_thread();
}
if (locals->err_state) {
#ifdef OPENSSL_INIT_DEBUG
fprintf(stderr, "OPENSSL_INIT: ossl_init_thread_stop: "
"err_delete_thread_state()\n");
#endif
err_delete_thread_state();
}
OPENSSL_free(locals);
}
void OPENSSL_thread_stop(void)
{
ossl_init_thread_stop(
(struct thread_local_inits_st *)ossl_init_get_thread_local(0));
}
int ossl_init_thread_start(uint64_t opts)
{
struct thread_local_inits_st *locals = ossl_init_get_thread_local(1);
if (locals == NULL)
return 0;
if (opts & OPENSSL_INIT_THREAD_ASYNC) {
#ifdef OPENSSL_INIT_DEBUG
fprintf(stderr, "OPENSSL_INIT: ossl_init_thread_start: "
"marking thread for async\n");
#endif
locals->async = 1;
}
if (opts & OPENSSL_INIT_THREAD_ERR_STATE) {
#ifdef OPENSSL_INIT_DEBUG
fprintf(stderr, "OPENSSL_INIT: ossl_init_thread_start: "
"marking thread for err_state\n");
#endif
locals->err_state = 1;
}
return 1;
}
void OPENSSL_cleanup(void)
{
OPENSSL_INIT_STOP *currhandler, *lasthandler;
if (!base_inited)
return;
if (stopped)
return;
stopped = 1;
ossl_init_thread_stop(ossl_init_get_thread_local(0));
currhandler = stop_handlers;
while (currhandler != NULL) {
currhandler->handler();
lasthandler = currhandler;
currhandler = currhandler->next;
OPENSSL_free(lasthandler);
}
stop_handlers = NULL;
CRYPTO_THREAD_lock_free(init_lock);
#ifndef OPENSSL_NO_COMP
if (zlib_inited) {
#ifdef OPENSSL_INIT_DEBUG
fprintf(stderr, "OPENSSL_INIT: OPENSSL_cleanup: "
"comp_zlib_cleanup_int()\n");
#endif
comp_zlib_cleanup_int();
}
#endif
if (async_inited) {
# ifdef OPENSSL_INIT_DEBUG
fprintf(stderr, "OPENSSL_INIT: OPENSSL_cleanup: "
"async_deinit()\n");
# endif
async_deinit();
}
if (load_crypto_strings_inited) {
#ifdef OPENSSL_INIT_DEBUG
fprintf(stderr, "OPENSSL_INIT: OPENSSL_cleanup: "
"err_free_strings_int()\n");
#endif
err_free_strings_int();
}
CRYPTO_THREAD_cleanup_local(&threadstopkey);
#ifdef OPENSSL_INIT_DEBUG
fprintf(stderr, "OPENSSL_INIT: OPENSSL_cleanup: "
"rand_cleanup_int()\n");
fprintf(stderr, "OPENSSL_INIT: OPENSSL_cleanup: "
"conf_modules_free_int()\n");
#ifndef OPENSSL_NO_ENGINE
fprintf(stderr, "OPENSSL_INIT: OPENSSL_cleanup: "
"engine_cleanup_int()\n");
#endif
fprintf(stderr, "OPENSSL_INIT: OPENSSL_cleanup: "
"crypto_cleanup_all_ex_data_int()\n");
fprintf(stderr, "OPENSSL_INIT: OPENSSL_cleanup: "
"bio_sock_cleanup_int()\n");
fprintf(stderr, "OPENSSL_INIT: OPENSSL_cleanup: "
"bio_cleanup()\n");
fprintf(stderr, "OPENSSL_INIT: OPENSSL_cleanup: "
"evp_cleanup_int()\n");
fprintf(stderr, "OPENSSL_INIT: OPENSSL_cleanup: "
"obj_cleanup_int()\n");
fprintf(stderr, "OPENSSL_INIT: OPENSSL_cleanup: "
"err_cleanup()\n");
#endif
rand_cleanup_int();
conf_modules_free_int();
#ifndef OPENSSL_NO_ENGINE
engine_cleanup_int();
#endif
crypto_cleanup_all_ex_data_int();
bio_cleanup();
evp_cleanup_int();
obj_cleanup_int();
err_cleanup();
base_inited = 0;
}
int OPENSSL_init_crypto(uint64_t opts, const OPENSSL_INIT_SETTINGS *settings)
{
static int stoperrset = 0;
if (stopped) {
if (!stoperrset) {
stoperrset = 1;
CRYPTOerr(CRYPTO_F_OPENSSL_INIT_CRYPTO, ERR_R_INIT_FAIL);
}
return 0;
}
if (!RUN_ONCE(&base, ossl_init_base))
return 0;
if ((opts & OPENSSL_INIT_NO_LOAD_CRYPTO_STRINGS)
&& !RUN_ONCE(&load_crypto_strings,
ossl_init_no_load_crypto_strings))
return 0;
if ((opts & OPENSSL_INIT_LOAD_CRYPTO_STRINGS)
&& !RUN_ONCE(&load_crypto_strings, ossl_init_load_crypto_strings))
return 0;
if ((opts & OPENSSL_INIT_NO_ADD_ALL_CIPHERS)
&& !RUN_ONCE(&add_all_ciphers, ossl_init_no_add_algs))
return 0;
if ((opts & OPENSSL_INIT_ADD_ALL_CIPHERS)
&& !RUN_ONCE(&add_all_ciphers, ossl_init_add_all_ciphers))
return 0;
if ((opts & OPENSSL_INIT_NO_ADD_ALL_DIGESTS)
&& !RUN_ONCE(&add_all_digests, ossl_init_no_add_algs))
return 0;
if ((opts & OPENSSL_INIT_ADD_ALL_DIGESTS)
&& !RUN_ONCE(&add_all_digests, ossl_init_add_all_digests))
return 0;
if ((opts & OPENSSL_INIT_NO_LOAD_CONFIG)
&& !RUN_ONCE(&config, ossl_init_no_config))
return 0;
if (opts & OPENSSL_INIT_LOAD_CONFIG) {
int ret;
CRYPTO_THREAD_write_lock(init_lock);
appname = (settings == NULL) ? NULL : settings->appname;
ret = RUN_ONCE(&config, ossl_init_config);
CRYPTO_THREAD_unlock(init_lock);
if (!ret)
return 0;
}
if ((opts & OPENSSL_INIT_ASYNC)
&& !RUN_ONCE(&async, ossl_init_async))
return 0;
#ifndef OPENSSL_NO_ENGINE
if ((opts & OPENSSL_INIT_ENGINE_OPENSSL)
&& !RUN_ONCE(&engine_openssl, ossl_init_engine_openssl))
return 0;
# if !defined(OPENSSL_NO_HW) && \
(defined(__OpenBSD__) || defined(__FreeBSD__) || defined(HAVE_CRYPTODEV))
if ((opts & OPENSSL_INIT_ENGINE_CRYPTODEV)
&& !RUN_ONCE(&engine_cryptodev, ossl_init_engine_cryptodev))
return 0;
# endif
# ifndef OPENSSL_NO_RDRAND
if ((opts & OPENSSL_INIT_ENGINE_RDRAND)
&& !RUN_ONCE(&engine_rdrand, ossl_init_engine_rdrand))
return 0;
# endif
if ((opts & OPENSSL_INIT_ENGINE_DYNAMIC)
&& !RUN_ONCE(&engine_dynamic, ossl_init_engine_dynamic))
return 0;
# ifndef OPENSSL_NO_STATIC_ENGINE
# if !defined(OPENSSL_NO_HW) && !defined(OPENSSL_NO_HW_PADLOCK)
if ((opts & OPENSSL_INIT_ENGINE_PADLOCK)
&& !RUN_ONCE(&engine_padlock, ossl_init_engine_padlock))
return 0;
# endif
# if defined(OPENSSL_SYS_WIN32) && !defined(OPENSSL_NO_CAPIENG)
if ((opts & OPENSSL_INIT_ENGINE_CAPI)
&& !RUN_ONCE(&engine_capi, ossl_init_engine_capi))
return 0;
# endif
# if !defined(OPENSSL_NO_AFALGENG)
if ((opts & OPENSSL_INIT_ENGINE_AFALG)
&& !RUN_ONCE(&engine_afalg, ossl_init_engine_afalg))
return 0;
# endif
# endif
if (opts & (OPENSSL_INIT_ENGINE_ALL_BUILTIN
| OPENSSL_INIT_ENGINE_OPENSSL
| OPENSSL_INIT_ENGINE_AFALG)) {
ENGINE_register_all_complete();
}
#endif
#ifndef OPENSSL_NO_COMP
if ((opts & OPENSSL_INIT_ZLIB)
&& !RUN_ONCE(&zlib, ossl_init_zlib))
return 0;
#endif
return 1;
}
int OPENSSL_atexit(void (*handler)(void))
{
OPENSSL_INIT_STOP *newhand;
newhand = OPENSSL_malloc(sizeof(*newhand));
if (newhand == NULL)
return 0;
newhand->handler = handler;
newhand->next = stop_handlers;
stop_handlers = newhand;
return 1;
}
