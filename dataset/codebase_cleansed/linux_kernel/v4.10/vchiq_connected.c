static void connected_init(void)
{
if (!g_once_init) {
mutex_init(&g_connected_mutex);
g_once_init = 1;
}
}
void vchiq_add_connected_callback(VCHIQ_CONNECTED_CALLBACK_T callback)
{
connected_init();
if (mutex_lock_killable(&g_connected_mutex) != 0)
return;
if (g_connected)
callback();
else {
if (g_num_deferred_callbacks >= MAX_CALLBACKS)
vchiq_log_error(vchiq_core_log_level,
"There already %d callback registered - "
"please increase MAX_CALLBACKS",
g_num_deferred_callbacks);
else {
g_deferred_callback[g_num_deferred_callbacks] =
callback;
g_num_deferred_callbacks++;
}
}
mutex_unlock(&g_connected_mutex);
}
void vchiq_call_connected_callbacks(void)
{
int i;
connected_init();
if (mutex_lock_killable(&g_connected_mutex) != 0)
return;
for (i = 0; i < g_num_deferred_callbacks; i++)
g_deferred_callback[i]();
g_num_deferred_callbacks = 0;
g_connected = 1;
mutex_unlock(&g_connected_mutex);
}
