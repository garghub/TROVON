static void no_printf(unsigned char *x, ...)
{
}
static void stop_dbg(void)
{
DbgDeregister();
memset(&MAdapter, 0, sizeof(MAdapter));
dprintf = no_printf;
}
static udiva_card *find_card_in_list(DESCRIPTOR *d)
{
udiva_card *card;
struct list_head *tmp;
diva_os_spin_lock_magic_t old_irql;
diva_os_enter_spin_lock(&ll_lock, &old_irql, "find card");
list_for_each(tmp, &cards) {
card = list_entry(tmp, udiva_card, list);
if (card->d.request == d->request) {
diva_os_leave_spin_lock(&ll_lock, &old_irql,
"find card");
return (card);
}
}
diva_os_leave_spin_lock(&ll_lock, &old_irql, "find card");
return ((udiva_card *) NULL);
}
static void um_new_card(DESCRIPTOR *d)
{
int adapter_nr = 0;
udiva_card *card = NULL;
IDI_SYNC_REQ sync_req;
diva_os_spin_lock_magic_t old_irql;
if (!(card = diva_os_malloc(0, sizeof(udiva_card)))) {
DBG_ERR(("cannot get buffer for card"));
return;
}
memcpy(&card->d, d, sizeof(DESCRIPTOR));
sync_req.xdi_logical_adapter_number.Req = 0;
sync_req.xdi_logical_adapter_number.Rc =
IDI_SYNC_REQ_XDI_GET_LOGICAL_ADAPTER_NUMBER;
card->d.request((ENTITY *)&sync_req);
adapter_nr =
sync_req.xdi_logical_adapter_number.info.logical_adapter_number;
card->Id = adapter_nr;
if (!(diva_user_mode_idi_create_adapter(d, adapter_nr))) {
diva_os_enter_spin_lock(&ll_lock, &old_irql, "add card");
list_add_tail(&card->list, &cards);
diva_os_leave_spin_lock(&ll_lock, &old_irql, "add card");
} else {
DBG_ERR(("could not create user mode idi card %d",
adapter_nr));
diva_os_free(0, card);
}
}
static void um_remove_card(DESCRIPTOR *d)
{
diva_os_spin_lock_magic_t old_irql;
udiva_card *card = NULL;
if (!(card = find_card_in_list(d))) {
DBG_ERR(("cannot find card to remove"));
return;
}
diva_user_mode_idi_remove_adapter(card->Id);
diva_os_enter_spin_lock(&ll_lock, &old_irql, "remove card");
list_del(&card->list);
diva_os_leave_spin_lock(&ll_lock, &old_irql, "remove card");
DBG_LOG(("idi proc entry removed for card %d", card->Id));
diva_os_free(0, card);
}
static void DIVA_EXIT_FUNCTION remove_all_idi_proc(void)
{
udiva_card *card;
diva_os_spin_lock_magic_t old_irql;
rescan:
diva_os_enter_spin_lock(&ll_lock, &old_irql, "remove all");
if (!list_empty(&cards)) {
card = list_entry(cards.next, udiva_card, list);
list_del(&card->list);
diva_os_leave_spin_lock(&ll_lock, &old_irql, "remove all");
diva_user_mode_idi_remove_adapter(card->Id);
diva_os_free(0, card);
goto rescan;
}
diva_os_leave_spin_lock(&ll_lock, &old_irql, "remove all");
}
static void *didd_callback(void *context, DESCRIPTOR *adapter,
int removal)
{
if (adapter->type == IDI_DADAPTER) {
DBG_ERR(("Notification about IDI_DADAPTER change ! Oops."));
return (NULL);
} else if (adapter->type == IDI_DIMAINT) {
if (removal) {
stop_dbg();
} else {
memcpy(&MAdapter, adapter, sizeof(MAdapter));
dprintf = (DIVA_DI_PRINTF) MAdapter.request;
DbgRegister("User IDI", DRIVERRELEASE_IDI, DBG_DEFAULT);
}
} else if ((adapter->type > 0) && (adapter->type < 16)) {
if (removal) {
um_remove_card(adapter);
} else {
um_new_card(adapter);
}
}
return (NULL);
}
static int DIVA_INIT_FUNCTION connect_didd(void)
{
int x = 0;
int dadapter = 0;
IDI_SYNC_REQ req;
DESCRIPTOR DIDD_Table[MAX_DESCRIPTORS];
DIVA_DIDD_Read(DIDD_Table, sizeof(DIDD_Table));
for (x = 0; x < MAX_DESCRIPTORS; x++) {
if (DIDD_Table[x].type == IDI_DADAPTER) {
dadapter = 1;
memcpy(&DAdapter, &DIDD_Table[x], sizeof(DAdapter));
req.didd_notify.e.Req = 0;
req.didd_notify.e.Rc =
IDI_SYNC_REQ_DIDD_REGISTER_ADAPTER_NOTIFY;
req.didd_notify.info.callback = (void *)didd_callback;
req.didd_notify.info.context = NULL;
DAdapter.request((ENTITY *)&req);
if (req.didd_notify.e.Rc != 0xff) {
stop_dbg();
return (0);
}
notify_handle = req.didd_notify.info.handle;
} else if (DIDD_Table[x].type == IDI_DIMAINT) {
memcpy(&MAdapter, &DIDD_Table[x], sizeof(DAdapter));
dprintf = (DIVA_DI_PRINTF) MAdapter.request;
DbgRegister("User IDI", DRIVERRELEASE_IDI, DBG_DEFAULT);
} else if ((DIDD_Table[x].type > 0)
&& (DIDD_Table[x].type < 16)) {
um_new_card(&DIDD_Table[x]);
}
}
if (!dadapter) {
stop_dbg();
}
return (dadapter);
}
static void DIVA_EXIT_FUNCTION disconnect_didd(void)
{
IDI_SYNC_REQ req;
stop_dbg();
req.didd_notify.e.Req = 0;
req.didd_notify.e.Rc = IDI_SYNC_REQ_DIDD_REMOVE_ADAPTER_NOTIFY;
req.didd_notify.info.handle = notify_handle;
DAdapter.request((ENTITY *)&req);
}
int DIVA_INIT_FUNCTION idifunc_init(void)
{
diva_os_initialize_spin_lock(&ll_lock, "idifunc");
if (diva_user_mode_idi_init()) {
DBG_ERR(("init: init failed."));
return (0);
}
if (!connect_didd()) {
diva_user_mode_idi_finit();
DBG_ERR(("init: failed to connect to DIDD."));
return (0);
}
return (1);
}
void DIVA_EXIT_FUNCTION idifunc_finit(void)
{
diva_user_mode_idi_finit();
disconnect_didd();
remove_all_idi_proc();
}
