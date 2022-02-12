static void no_printf (unsigned char * format, ...)
{
#ifdef EBUG
va_list ap;
va_start (ap, format);
debug((format, ap));
va_end (ap);
#endif
}
void diva_didd_load_time_init (void) {
memset (&HandleTable[0], 0x00, sizeof(HandleTable));
memset (&NotificationTable[0], 0x00, sizeof(NotificationTable));
diva_os_initialize_spin_lock (&didd_spin, "didd");
}
void diva_didd_load_time_finit (void) {
diva_os_destroy_spin_lock (&didd_spin, "didd");
}
static int diva_didd_add_descriptor (DESCRIPTOR* d) {
diva_os_spin_lock_magic_t irql;
int i;
if (d->type == IDI_DIMAINT) {
if (d->request) {
MAdapter.request = d->request;
dprintf = (DIVA_DI_PRINTF)d->request;
diva_notify_adapter_change (&MAdapter, 0);
DBG_TRC (("DIMAINT registered, dprintf=%08x", d->request))
} else {
DBG_TRC (("DIMAINT removed"))
diva_notify_adapter_change (&MAdapter, 1);
MAdapter.request = (IDI_CALL)no_printf;
dprintf = no_printf;
}
return (NEW_MAX_DESCRIPTORS);
}
for (i = 0; i < NEW_MAX_DESCRIPTORS; i++) {
diva_os_enter_spin_lock (&didd_spin, &irql, "didd_add");
if (HandleTable[i].type == 0) {
memcpy (&HandleTable[i], d, sizeof(*d));
Adapters++;
diva_os_leave_spin_lock (&didd_spin, &irql, "didd_add");
diva_notify_adapter_change (d, 0);
DBG_TRC (("Add adapter[%d], request=%08x", (i+1), d->request))
return (i+1);
}
diva_os_leave_spin_lock (&didd_spin, &irql, "didd_add");
}
DBG_ERR (("Can't add adapter, out of resources"))
return (-1);
}
static int diva_didd_remove_descriptor (IDI_CALL request) {
diva_os_spin_lock_magic_t irql;
int i;
if (request == MAdapter.request) {
DBG_TRC(("DIMAINT removed"))
dprintf = no_printf;
diva_notify_adapter_change (&MAdapter, 1);
MAdapter.request = (IDI_CALL)no_printf;
return (0);
}
for (i = 0; (Adapters && (i < NEW_MAX_DESCRIPTORS)); i++) {
if (HandleTable[i].request == request) {
diva_notify_adapter_change (&HandleTable[i], 1);
diva_os_enter_spin_lock (&didd_spin, &irql, "didd_rm");
memset (&HandleTable[i], 0x00, sizeof(HandleTable[0]));
Adapters--;
diva_os_leave_spin_lock (&didd_spin, &irql, "didd_rm");
DBG_TRC (("Remove adapter[%d], request=%08x", (i+1), request))
return (0);
}
}
DBG_ERR (("Invalid request=%08x, can't remove adapter", request))
return (-1);
}
static int diva_didd_read_adapter_array (DESCRIPTOR* buffer, int length) {
diva_os_spin_lock_magic_t irql;
int src, dst;
memset (buffer, 0x00, length);
length /= sizeof(DESCRIPTOR);
DBG_TRC (("DIDD_Read, space = %d, Adapters = %d", length, Adapters+2))
diva_os_enter_spin_lock (&didd_spin, &irql, "didd_read");
for (src = 0, dst = 0;
(Adapters && (src < NEW_MAX_DESCRIPTORS) && (dst < length));
src++) {
if (HandleTable[src].type) {
memcpy (&buffer[dst], &HandleTable[src], sizeof(DESCRIPTOR));
dst++;
}
}
diva_os_leave_spin_lock (&didd_spin, &irql, "didd_read");
if (dst < length) {
memcpy (&buffer[dst], &MAdapter, sizeof(DESCRIPTOR));
dst++;
} else {
DBG_ERR (("Can't write DIMAINT. Array too small"))
}
if (dst < length) {
memcpy (&buffer[dst], &DAdapter, sizeof(DESCRIPTOR));
dst++;
} else {
DBG_ERR (("Can't write DADAPTER. Array too small"))
}
DBG_TRC (("Read %d adapters", dst))
return (dst == length);
}
static void IDI_CALL_LINK_T diva_dadapter_request (\
ENTITY IDI_CALL_ENTITY_T *e) {
IDI_SYNC_REQ *syncReq = (IDI_SYNC_REQ *)e ;
if (e->Req) {
e->Rc = OUT_OF_RESOURCES;
DBG_ERR (("Can't process async request, Req=%02x", e->Req))
return;
}
switch (e->Rc) {
case IDI_SYNC_REQ_DIDD_REGISTER_ADAPTER_NOTIFY: {
diva_didd_adapter_notify_t* pinfo = &syncReq->didd_notify.info;
pinfo->handle = diva_register_adapter_callback (\
(didd_adapter_change_callback_t)pinfo->callback,
(void IDI_CALL_ENTITY_T *)pinfo->context);
e->Rc = 0xff;
} break;
case IDI_SYNC_REQ_DIDD_REMOVE_ADAPTER_NOTIFY: {
diva_didd_adapter_notify_t* pinfo = &syncReq->didd_notify.info;
diva_remove_adapter_callback (pinfo->handle);
e->Rc = 0xff;
} break;
case IDI_SYNC_REQ_DIDD_ADD_ADAPTER: {
diva_didd_add_adapter_t* pinfo = &syncReq->didd_add_adapter.info;
if (diva_didd_add_descriptor ((DESCRIPTOR*)pinfo->descriptor) < 0) {
e->Rc = OUT_OF_RESOURCES;
} else {
e->Rc = 0xff;
}
} break;
case IDI_SYNC_REQ_DIDD_REMOVE_ADAPTER: {
diva_didd_remove_adapter_t* pinfo = &syncReq->didd_remove_adapter.info;
if (diva_didd_remove_descriptor ((IDI_CALL)pinfo->p_request) < 0) {
e->Rc = OUT_OF_RESOURCES;
} else {
e->Rc = 0xff;
}
} break;
case IDI_SYNC_REQ_DIDD_READ_ADAPTER_ARRAY: {
diva_didd_read_adapter_array_t* pinfo =\
&syncReq->didd_read_adapter_array.info;
if (diva_didd_read_adapter_array ((DESCRIPTOR*)pinfo->buffer,
(int)pinfo->length)) {
e->Rc = OUT_OF_RESOURCES;
} else {
e->Rc = 0xff;
}
} break;
default:
DBG_ERR (("Can't process sync request, Req=%02x", e->Rc))
e->Rc = OUT_OF_RESOURCES;
}
}
static dword diva_register_adapter_callback (\
didd_adapter_change_callback_t callback,
void IDI_CALL_ENTITY_T* context) {
diva_os_spin_lock_magic_t irql;
dword i;
for (i = 0; i < DIVA_DIDD_MAX_NOTIFICATIONS; i++) {
diva_os_enter_spin_lock (&didd_spin, &irql, "didd_nfy_add");
if (!NotificationTable[i].callback) {
NotificationTable[i].callback = callback;
NotificationTable[i].context = context;
diva_os_leave_spin_lock (&didd_spin, &irql, "didd_nfy_add");
DBG_TRC(("Register adapter notification[%d]=%08x", i+1, callback))
return (i+1);
}
diva_os_leave_spin_lock (&didd_spin, &irql, "didd_nfy_add");
}
DBG_ERR (("Can't register adapter notification, overflow"))
return (0);
}
static void diva_remove_adapter_callback (dword handle) {
diva_os_spin_lock_magic_t irql;
if (handle && ((--handle) < DIVA_DIDD_MAX_NOTIFICATIONS)) {
diva_os_enter_spin_lock (&didd_spin, &irql, "didd_nfy_rm");
NotificationTable[handle].callback = NULL;
NotificationTable[handle].context = NULL;
diva_os_leave_spin_lock (&didd_spin, &irql, "didd_nfy_rm");
DBG_TRC(("Remove adapter notification[%d]", (int)(handle+1)))
return;
}
DBG_ERR(("Can't remove adapter notification, handle=%d", handle))
}
static void diva_notify_adapter_change (DESCRIPTOR* d, int removal) {
int i, do_notify;
didd_adapter_change_notification_t nfy;
diva_os_spin_lock_magic_t irql;
for (i = 0; i < DIVA_DIDD_MAX_NOTIFICATIONS; i++) {
do_notify = 0;
diva_os_enter_spin_lock (&didd_spin, &irql, "didd_nfy");
if (NotificationTable[i].callback) {
memcpy (&nfy, &NotificationTable[i], sizeof(nfy));
do_notify = 1;
}
diva_os_leave_spin_lock (&didd_spin, &irql, "didd_nfy");
if (do_notify) {
(*(nfy.callback))(nfy.context, d, removal);
}
}
}
void IDI_CALL_LINK_T DIVA_DIDD_Read (void IDI_CALL_ENTITY_T * buffer,
int length) {
diva_didd_read_adapter_array (buffer, length);
}
