int msg_create(struct msg_mgr **msg_man,
struct dev_object *hdev_obj, msg_onexit msg_callback)
{
struct bridge_drv_interface *intf_fxns;
struct msg_mgr_ *msg_mgr_obj;
struct msg_mgr *hmsg_mgr;
int status = 0;
DBC_REQUIRE(refs > 0);
DBC_REQUIRE(msg_man != NULL);
DBC_REQUIRE(msg_callback != NULL);
DBC_REQUIRE(hdev_obj != NULL);
*msg_man = NULL;
dev_get_intf_fxns(hdev_obj, &intf_fxns);
status =
(*intf_fxns->msg_create) (&hmsg_mgr, hdev_obj, msg_callback);
if (!status) {
msg_mgr_obj = (struct msg_mgr_ *)hmsg_mgr;
msg_mgr_obj->intf_fxns = intf_fxns;
*msg_man = hmsg_mgr;
} else {
status = -EPERM;
}
return status;
}
void msg_delete(struct msg_mgr *hmsg_mgr)
{
struct msg_mgr_ *msg_mgr_obj = (struct msg_mgr_ *)hmsg_mgr;
struct bridge_drv_interface *intf_fxns;
DBC_REQUIRE(refs > 0);
if (msg_mgr_obj) {
intf_fxns = msg_mgr_obj->intf_fxns;
(*intf_fxns->msg_delete) (hmsg_mgr);
} else {
dev_dbg(bridge, "%s: Error hmsg_mgr handle: %p\n",
__func__, hmsg_mgr);
}
}
void msg_exit(void)
{
DBC_REQUIRE(refs > 0);
refs--;
DBC_ENSURE(refs >= 0);
}
bool msg_mod_init(void)
{
DBC_REQUIRE(refs >= 0);
refs++;
DBC_ENSURE(refs >= 0);
return true;
}
