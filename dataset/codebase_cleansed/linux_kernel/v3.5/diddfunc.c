static void *didd_callback(void *context, DESCRIPTOR *adapter,
int removal)
{
if (adapter->type == IDI_DADAPTER) {
DBG_ERR(("Notification about IDI_DADAPTER change ! Oops."))
return (NULL);
} else if (adapter->type == IDI_DIMAINT) {
if (removal) {
DbgDeregister();
} else {
DbgRegister("DIDD", DRIVERRELEASE_DIDD, DBG_DEFAULT);
}
}
return (NULL);
}
static int __init connect_didd(void)
{
int x = 0;
int dadapter = 0;
IDI_SYNC_REQ req;
DESCRIPTOR DIDD_Table[MAX_DESCRIPTORS];
DIVA_DIDD_Read(DIDD_Table, sizeof(DIDD_Table));
for (x = 0; x < MAX_DESCRIPTORS; x++) {
if (DIDD_Table[x].type == IDI_DADAPTER) {
dadapter = 1;
memcpy(&_DAdapter, &DIDD_Table[x], sizeof(_DAdapter));
req.didd_notify.e.Req = 0;
req.didd_notify.e.Rc =
IDI_SYNC_REQ_DIDD_REGISTER_ADAPTER_NOTIFY;
req.didd_notify.info.callback = (void *)didd_callback;
req.didd_notify.info.context = NULL;
_DAdapter.request((ENTITY *)&req);
if (req.didd_notify.e.Rc != 0xff)
return (0);
notify_handle = req.didd_notify.info.handle;
} else if (DIDD_Table[x].type == IDI_DIMAINT) {
DbgRegister("DIDD", DRIVERRELEASE_DIDD, DBG_DEFAULT);
}
}
return (dadapter);
}
static void __exit disconnect_didd(void)
{
IDI_SYNC_REQ req;
req.didd_notify.e.Req = 0;
req.didd_notify.e.Rc = IDI_SYNC_REQ_DIDD_REMOVE_ADAPTER_NOTIFY;
req.didd_notify.info.handle = notify_handle;
_DAdapter.request((ENTITY *)&req);
}
int __init diddfunc_init(void)
{
diva_didd_load_time_init();
if (!connect_didd()) {
DBG_ERR(("init: failed to connect to DIDD."))
diva_didd_load_time_finit();
return (0);
}
return (1);
}
void __exit diddfunc_finit(void)
{
DbgDeregister();
disconnect_didd();
diva_didd_load_time_finit();
}
