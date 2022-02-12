void
xpc_clear_interface(void)
{
memset(&xpc_interface, 0, sizeof(xpc_interface));
}
enum xp_retval
xpc_connect(int ch_number, xpc_channel_func func, void *key, u16 payload_size,
u16 nentries, u32 assigned_limit, u32 idle_limit)
{
struct xpc_registration *registration;
DBUG_ON(ch_number < 0 || ch_number >= XPC_MAX_NCHANNELS);
DBUG_ON(payload_size == 0 || nentries == 0);
DBUG_ON(func == NULL);
DBUG_ON(assigned_limit == 0 || idle_limit > assigned_limit);
if (XPC_MSG_SIZE(payload_size) > XPC_MSG_MAX_SIZE)
return xpPayloadTooBig;
registration = &xpc_registrations[ch_number];
if (mutex_lock_interruptible(&registration->mutex) != 0)
return xpInterrupted;
if (registration->func != NULL) {
mutex_unlock(&registration->mutex);
return xpAlreadyRegistered;
}
registration->entry_size = XPC_MSG_SIZE(payload_size);
registration->nentries = nentries;
registration->assigned_limit = assigned_limit;
registration->idle_limit = idle_limit;
registration->key = key;
registration->func = func;
mutex_unlock(&registration->mutex);
if (xpc_interface.connect)
xpc_interface.connect(ch_number);
return xpSuccess;
}
void
xpc_disconnect(int ch_number)
{
struct xpc_registration *registration;
DBUG_ON(ch_number < 0 || ch_number >= XPC_MAX_NCHANNELS);
registration = &xpc_registrations[ch_number];
mutex_lock(&registration->mutex);
if (registration->func == NULL) {
mutex_unlock(&registration->mutex);
return;
}
registration->func = NULL;
registration->key = NULL;
registration->nentries = 0;
registration->entry_size = 0;
registration->assigned_limit = 0;
registration->idle_limit = 0;
if (xpc_interface.disconnect)
xpc_interface.disconnect(ch_number);
mutex_unlock(&registration->mutex);
return;
}
int __init
xp_init(void)
{
enum xp_retval ret;
int ch_number;
for (ch_number = 0; ch_number < XPC_MAX_NCHANNELS; ch_number++)
mutex_init(&xpc_registrations[ch_number].mutex);
if (is_shub())
ret = xp_init_sn2();
else if (is_uv())
ret = xp_init_uv();
else
ret = 0;
if (ret != xpSuccess)
return ret;
return 0;
}
void __exit
xp_exit(void)
{
if (is_shub())
xp_exit_sn2();
else if (is_uv())
xp_exit_uv();
}
