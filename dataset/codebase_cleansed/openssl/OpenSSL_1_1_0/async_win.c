int ASYNC_is_capable(void)
{
return 1;
}
void async_local_cleanup(void)
{
async_ctx *ctx = async_get_ctx();
if (ctx != NULL) {
async_fibre *fibre = &ctx->dispatcher;
if (fibre != NULL && fibre->fibre != NULL && fibre->converted) {
ConvertFiberToThread();
fibre->fibre = NULL;
}
}
}
int async_fibre_init_dispatcher(async_fibre *fibre)
{
fibre->fibre = ConvertThreadToFiber(NULL);
if (fibre->fibre == NULL) {
fibre->converted = 0;
fibre->fibre = GetCurrentFiber();
if (fibre->fibre == NULL)
return 0;
} else {
fibre->converted = 1;
}
return 1;
}
VOID CALLBACK async_start_func_win(PVOID unused)
{
async_start_func();
}
