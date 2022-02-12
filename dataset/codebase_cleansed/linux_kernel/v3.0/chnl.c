int chnl_create(struct chnl_mgr **channel_mgr,
struct dev_object *hdev_obj,
const struct chnl_mgrattrs *mgr_attrts)
{
int status;
struct chnl_mgr *hchnl_mgr;
struct chnl_mgr_ *chnl_mgr_obj = NULL;
DBC_REQUIRE(refs > 0);
DBC_REQUIRE(channel_mgr != NULL);
DBC_REQUIRE(mgr_attrts != NULL);
*channel_mgr = NULL;
if ((0 < mgr_attrts->max_channels) &&
(mgr_attrts->max_channels <= CHNL_MAXCHANNELS))
status = 0;
else if (mgr_attrts->max_channels == 0)
status = -EINVAL;
else
status = -ECHRNG;
if (mgr_attrts->word_size == 0)
status = -EINVAL;
if (!status) {
status = dev_get_chnl_mgr(hdev_obj, &hchnl_mgr);
if (!status && hchnl_mgr != NULL)
status = -EEXIST;
}
if (!status) {
struct bridge_drv_interface *intf_fxns;
dev_get_intf_fxns(hdev_obj, &intf_fxns);
status = (*intf_fxns->chnl_create) (&hchnl_mgr, hdev_obj,
mgr_attrts);
if (!status) {
chnl_mgr_obj = (struct chnl_mgr_ *)hchnl_mgr;
chnl_mgr_obj->intf_fxns = intf_fxns;
*channel_mgr = hchnl_mgr;
}
}
DBC_ENSURE(status || chnl_mgr_obj);
return status;
}
int chnl_destroy(struct chnl_mgr *hchnl_mgr)
{
struct chnl_mgr_ *chnl_mgr_obj = (struct chnl_mgr_ *)hchnl_mgr;
struct bridge_drv_interface *intf_fxns;
int status;
DBC_REQUIRE(refs > 0);
if (chnl_mgr_obj) {
intf_fxns = chnl_mgr_obj->intf_fxns;
status = (*intf_fxns->chnl_destroy) (hchnl_mgr);
} else {
status = -EFAULT;
}
return status;
}
void chnl_exit(void)
{
DBC_REQUIRE(refs > 0);
refs--;
DBC_ENSURE(refs >= 0);
}
bool chnl_init(void)
{
bool ret = true;
DBC_REQUIRE(refs >= 0);
if (ret)
refs++;
DBC_ENSURE((ret && (refs > 0)) || (!ret && (refs >= 0)));
return ret;
}
