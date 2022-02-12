int ASYNC_is_capable(void)
{
ucontext_t ctx;
return getcontext(&ctx) == 0;
}
void async_local_cleanup(void)
{
}
int async_fibre_makecontext(async_fibre *fibre)
{
fibre->env_init = 0;
if (getcontext(&fibre->fibre) == 0) {
fibre->fibre.uc_stack.ss_sp = OPENSSL_malloc(STACKSIZE);
if (fibre->fibre.uc_stack.ss_sp != NULL) {
fibre->fibre.uc_stack.ss_size = STACKSIZE;
fibre->fibre.uc_link = NULL;
makecontext(&fibre->fibre, async_start_func, 0);
return 1;
}
} else {
fibre->fibre.uc_stack.ss_sp = NULL;
}
return 0;
}
void async_fibre_free(async_fibre *fibre)
{
OPENSSL_free(fibre->fibre.uc_stack.ss_sp);
fibre->fibre.uc_stack.ss_sp = NULL;
}
