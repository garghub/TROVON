int ufshcd_dwc_dme_set_attrs(struct ufs_hba *hba,
const struct ufshcd_dme_attr_val *v, int n)
{
int ret = 0;
int attr_node = 0;
for (attr_node = 0; attr_node < n; attr_node++) {
ret = ufshcd_dme_set_attr(hba, v[attr_node].attr_sel,
ATTR_SET_NOR, v[attr_node].mib_val, v[attr_node].peer);
if (ret)
return ret;
}
return 0;
}
static void ufshcd_dwc_program_clk_div(struct ufs_hba *hba, u32 divider_val)
{
ufshcd_writel(hba, divider_val, DWC_UFS_REG_HCLKDIV);
}
static int ufshcd_dwc_link_is_up(struct ufs_hba *hba)
{
int dme_result = 0;
ufshcd_dme_get(hba, UIC_ARG_MIB(VS_POWERSTATE), &dme_result);
if (dme_result == UFSHCD_LINK_IS_UP) {
ufshcd_set_link_active(hba);
return 0;
}
return 1;
}
static int ufshcd_dwc_connection_setup(struct ufs_hba *hba)
{
const struct ufshcd_dme_attr_val setup_attrs[] = {
{ UIC_ARG_MIB(T_CONNECTIONSTATE), 0, DME_LOCAL },
{ UIC_ARG_MIB(N_DEVICEID), 0, DME_LOCAL },
{ UIC_ARG_MIB(N_DEVICEID_VALID), 0, DME_LOCAL },
{ UIC_ARG_MIB(T_PEERDEVICEID), 1, DME_LOCAL },
{ UIC_ARG_MIB(T_PEERCPORTID), 0, DME_LOCAL },
{ UIC_ARG_MIB(T_TRAFFICCLASS), 0, DME_LOCAL },
{ UIC_ARG_MIB(T_CPORTFLAGS), 0x6, DME_LOCAL },
{ UIC_ARG_MIB(T_CPORTMODE), 1, DME_LOCAL },
{ UIC_ARG_MIB(T_CONNECTIONSTATE), 1, DME_LOCAL },
{ UIC_ARG_MIB(T_CONNECTIONSTATE), 0, DME_PEER },
{ UIC_ARG_MIB(N_DEVICEID), 1, DME_PEER },
{ UIC_ARG_MIB(N_DEVICEID_VALID), 1, DME_PEER },
{ UIC_ARG_MIB(T_PEERDEVICEID), 1, DME_PEER },
{ UIC_ARG_MIB(T_PEERCPORTID), 0, DME_PEER },
{ UIC_ARG_MIB(T_TRAFFICCLASS), 0, DME_PEER },
{ UIC_ARG_MIB(T_CPORTFLAGS), 0x6, DME_PEER },
{ UIC_ARG_MIB(T_CPORTMODE), 1, DME_PEER },
{ UIC_ARG_MIB(T_CONNECTIONSTATE), 1, DME_PEER }
};
return ufshcd_dwc_dme_set_attrs(hba, setup_attrs, ARRAY_SIZE(setup_attrs));
}
int ufshcd_dwc_link_startup_notify(struct ufs_hba *hba,
enum ufs_notify_change_status status)
{
int err = 0;
if (status == PRE_CHANGE) {
ufshcd_dwc_program_clk_div(hba, DWC_UFS_REG_HCLKDIV_DIV_125);
if (hba->vops->phy_initialization) {
err = hba->vops->phy_initialization(hba);
if (err) {
dev_err(hba->dev, "Phy setup failed (%d)\n",
err);
goto out;
}
}
} else {
err = ufshcd_dwc_link_is_up(hba);
if (err) {
dev_err(hba->dev, "Link is not up\n");
goto out;
}
err = ufshcd_dwc_connection_setup(hba);
if (err)
dev_err(hba->dev, "Connection setup failed (%d)\n",
err);
}
out:
return err;
}
