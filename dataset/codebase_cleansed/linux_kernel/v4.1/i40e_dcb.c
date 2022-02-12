i40e_status i40e_get_dcbx_status(struct i40e_hw *hw, u16 *status)
{
u32 reg;
if (!status)
return I40E_ERR_PARAM;
reg = rd32(hw, I40E_PRTDCB_GENS);
*status = (u16)((reg & I40E_PRTDCB_GENS_DCBX_STATUS_MASK) >>
I40E_PRTDCB_GENS_DCBX_STATUS_SHIFT);
return 0;
}
static void i40e_parse_ieee_etscfg_tlv(struct i40e_lldp_org_tlv *tlv,
struct i40e_dcbx_config *dcbcfg)
{
struct i40e_dcb_ets_config *etscfg;
u8 *buf = tlv->tlvinfo;
u16 offset = 0;
u8 priority;
int i;
etscfg = &dcbcfg->etscfg;
etscfg->willing = (u8)((buf[offset] & I40E_IEEE_ETS_WILLING_MASK) >>
I40E_IEEE_ETS_WILLING_SHIFT);
etscfg->cbs = (u8)((buf[offset] & I40E_IEEE_ETS_CBS_MASK) >>
I40E_IEEE_ETS_CBS_SHIFT);
etscfg->maxtcs = (u8)((buf[offset] & I40E_IEEE_ETS_MAXTC_MASK) >>
I40E_IEEE_ETS_MAXTC_SHIFT);
offset++;
for (i = 0; i < 4; i++) {
priority = (u8)((buf[offset] & I40E_IEEE_ETS_PRIO_1_MASK) >>
I40E_IEEE_ETS_PRIO_1_SHIFT);
etscfg->prioritytable[i * 2] = priority;
priority = (u8)((buf[offset] & I40E_IEEE_ETS_PRIO_0_MASK) >>
I40E_IEEE_ETS_PRIO_0_SHIFT);
etscfg->prioritytable[i * 2 + 1] = priority;
offset++;
}
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++)
etscfg->tcbwtable[i] = buf[offset++];
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++)
etscfg->tsatable[i] = buf[offset++];
}
static void i40e_parse_ieee_etsrec_tlv(struct i40e_lldp_org_tlv *tlv,
struct i40e_dcbx_config *dcbcfg)
{
u8 *buf = tlv->tlvinfo;
u16 offset = 0;
u8 priority;
int i;
offset++;
for (i = 0; i < 4; i++) {
priority = (u8)((buf[offset] & I40E_IEEE_ETS_PRIO_1_MASK) >>
I40E_IEEE_ETS_PRIO_1_SHIFT);
dcbcfg->etsrec.prioritytable[i*2] = priority;
priority = (u8)((buf[offset] & I40E_IEEE_ETS_PRIO_0_MASK) >>
I40E_IEEE_ETS_PRIO_0_SHIFT);
dcbcfg->etsrec.prioritytable[i*2 + 1] = priority;
offset++;
}
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++)
dcbcfg->etsrec.tcbwtable[i] = buf[offset++];
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++)
dcbcfg->etsrec.tsatable[i] = buf[offset++];
}
static void i40e_parse_ieee_pfccfg_tlv(struct i40e_lldp_org_tlv *tlv,
struct i40e_dcbx_config *dcbcfg)
{
u8 *buf = tlv->tlvinfo;
dcbcfg->pfc.willing = (u8)((buf[0] & I40E_IEEE_PFC_WILLING_MASK) >>
I40E_IEEE_PFC_WILLING_SHIFT);
dcbcfg->pfc.mbc = (u8)((buf[0] & I40E_IEEE_PFC_MBC_MASK) >>
I40E_IEEE_PFC_MBC_SHIFT);
dcbcfg->pfc.pfccap = (u8)((buf[0] & I40E_IEEE_PFC_CAP_MASK) >>
I40E_IEEE_PFC_CAP_SHIFT);
dcbcfg->pfc.pfcenable = buf[1];
}
static void i40e_parse_ieee_app_tlv(struct i40e_lldp_org_tlv *tlv,
struct i40e_dcbx_config *dcbcfg)
{
u16 typelength;
u16 offset = 0;
u16 length;
int i = 0;
u8 *buf;
typelength = ntohs(tlv->typelength);
length = (u16)((typelength & I40E_LLDP_TLV_LEN_MASK) >>
I40E_LLDP_TLV_LEN_SHIFT);
buf = tlv->tlvinfo;
length -= (sizeof(tlv->ouisubtype) + 1);
offset++;
while (offset < length) {
dcbcfg->app[i].priority = (u8)((buf[offset] &
I40E_IEEE_APP_PRIO_MASK) >>
I40E_IEEE_APP_PRIO_SHIFT);
dcbcfg->app[i].selector = (u8)((buf[offset] &
I40E_IEEE_APP_SEL_MASK) >>
I40E_IEEE_APP_SEL_SHIFT);
dcbcfg->app[i].protocolid = (buf[offset + 1] << 0x8) |
buf[offset + 2];
offset += 3;
i++;
if (i >= I40E_DCBX_MAX_APPS)
break;
}
dcbcfg->numapps = i;
}
static void i40e_parse_ieee_tlv(struct i40e_lldp_org_tlv *tlv,
struct i40e_dcbx_config *dcbcfg)
{
u32 ouisubtype;
u8 subtype;
ouisubtype = ntohl(tlv->ouisubtype);
subtype = (u8)((ouisubtype & I40E_LLDP_TLV_SUBTYPE_MASK) >>
I40E_LLDP_TLV_SUBTYPE_SHIFT);
switch (subtype) {
case I40E_IEEE_SUBTYPE_ETS_CFG:
i40e_parse_ieee_etscfg_tlv(tlv, dcbcfg);
break;
case I40E_IEEE_SUBTYPE_ETS_REC:
i40e_parse_ieee_etsrec_tlv(tlv, dcbcfg);
break;
case I40E_IEEE_SUBTYPE_PFC_CFG:
i40e_parse_ieee_pfccfg_tlv(tlv, dcbcfg);
break;
case I40E_IEEE_SUBTYPE_APP_PRI:
i40e_parse_ieee_app_tlv(tlv, dcbcfg);
break;
default:
break;
}
}
static void i40e_parse_org_tlv(struct i40e_lldp_org_tlv *tlv,
struct i40e_dcbx_config *dcbcfg)
{
u32 ouisubtype;
u32 oui;
ouisubtype = ntohl(tlv->ouisubtype);
oui = (u32)((ouisubtype & I40E_LLDP_TLV_OUI_MASK) >>
I40E_LLDP_TLV_OUI_SHIFT);
switch (oui) {
case I40E_IEEE_8021QAZ_OUI:
i40e_parse_ieee_tlv(tlv, dcbcfg);
break;
default:
break;
}
}
i40e_status i40e_lldp_to_dcb_config(u8 *lldpmib,
struct i40e_dcbx_config *dcbcfg)
{
i40e_status ret = 0;
struct i40e_lldp_org_tlv *tlv;
u16 type;
u16 length;
u16 typelength;
u16 offset = 0;
if (!lldpmib || !dcbcfg)
return I40E_ERR_PARAM;
lldpmib += ETH_HLEN;
tlv = (struct i40e_lldp_org_tlv *)lldpmib;
while (1) {
typelength = ntohs(tlv->typelength);
type = (u16)((typelength & I40E_LLDP_TLV_TYPE_MASK) >>
I40E_LLDP_TLV_TYPE_SHIFT);
length = (u16)((typelength & I40E_LLDP_TLV_LEN_MASK) >>
I40E_LLDP_TLV_LEN_SHIFT);
offset += sizeof(typelength) + length;
if ((type == I40E_TLV_TYPE_END) || (offset > I40E_LLDPDU_SIZE))
break;
switch (type) {
case I40E_TLV_TYPE_ORG:
i40e_parse_org_tlv(tlv, dcbcfg);
break;
default:
break;
}
tlv = (struct i40e_lldp_org_tlv *)((char *)tlv +
sizeof(tlv->typelength) +
length);
}
return ret;
}
i40e_status i40e_aq_get_dcb_config(struct i40e_hw *hw, u8 mib_type,
u8 bridgetype,
struct i40e_dcbx_config *dcbcfg)
{
i40e_status ret = 0;
struct i40e_virt_mem mem;
u8 *lldpmib;
ret = i40e_allocate_virt_mem(hw, &mem, I40E_LLDPDU_SIZE);
if (ret)
return ret;
lldpmib = (u8 *)mem.va;
ret = i40e_aq_get_lldp_mib(hw, bridgetype, mib_type,
(void *)lldpmib, I40E_LLDPDU_SIZE,
NULL, NULL, NULL);
if (ret)
goto free_mem;
ret = i40e_lldp_to_dcb_config(lldpmib, dcbcfg);
free_mem:
i40e_free_virt_mem(hw, &mem);
return ret;
}
static void i40e_cee_to_dcb_v1_config(
struct i40e_aqc_get_cee_dcb_cfg_v1_resp *cee_cfg,
struct i40e_dcbx_config *dcbcfg)
{
u16 status, tlv_status = le16_to_cpu(cee_cfg->tlv_status);
u16 app_prio = le16_to_cpu(cee_cfg->oper_app_prio);
u8 i, tc, err;
dcbcfg->etscfg.maxtcs = cee_cfg->oper_num_tc;
for (i = 0; i < 4; i++) {
tc = (u8)((cee_cfg->oper_prio_tc[i] &
I40E_CEE_PGID_PRIO_1_MASK) >>
I40E_CEE_PGID_PRIO_1_SHIFT);
dcbcfg->etscfg.prioritytable[i*2] = tc;
tc = (u8)((cee_cfg->oper_prio_tc[i] &
I40E_CEE_PGID_PRIO_0_MASK) >>
I40E_CEE_PGID_PRIO_0_SHIFT);
dcbcfg->etscfg.prioritytable[i*2 + 1] = tc;
}
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++)
dcbcfg->etscfg.tcbwtable[i] = cee_cfg->oper_tc_bw[i];
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
if (dcbcfg->etscfg.prioritytable[i] == I40E_CEE_PGID_STRICT) {
dcbcfg->etscfg.prioritytable[i] =
cee_cfg->oper_num_tc - 1;
dcbcfg->etscfg.tsatable[i] = I40E_IEEE_TSA_STRICT;
} else {
dcbcfg->etscfg.tsatable[i] = I40E_IEEE_TSA_ETS;
}
}
dcbcfg->pfc.pfcenable = cee_cfg->oper_pfc_en;
dcbcfg->pfc.pfccap = I40E_MAX_TRAFFIC_CLASS;
status = (tlv_status & I40E_AQC_CEE_APP_STATUS_MASK) >>
I40E_AQC_CEE_APP_STATUS_SHIFT;
err = (status & I40E_TLV_STATUS_ERR) ? 1 : 0;
if (!err) {
dcbcfg->numapps = I40E_CEE_OPER_MAX_APPS;
dcbcfg->app[0].priority =
(app_prio & I40E_AQC_CEE_APP_FCOE_MASK) >>
I40E_AQC_CEE_APP_FCOE_SHIFT;
dcbcfg->app[0].selector = I40E_APP_SEL_ETHTYPE;
dcbcfg->app[0].protocolid = I40E_APP_PROTOID_FCOE;
dcbcfg->app[1].priority =
(app_prio & I40E_AQC_CEE_APP_ISCSI_MASK) >>
I40E_AQC_CEE_APP_ISCSI_SHIFT;
dcbcfg->app[1].selector = I40E_APP_SEL_TCPIP;
dcbcfg->app[1].protocolid = I40E_APP_PROTOID_ISCSI;
dcbcfg->app[2].priority =
(app_prio & I40E_AQC_CEE_APP_FIP_MASK) >>
I40E_AQC_CEE_APP_FIP_SHIFT;
dcbcfg->app[2].selector = I40E_APP_SEL_ETHTYPE;
dcbcfg->app[2].protocolid = I40E_APP_PROTOID_FIP;
}
}
static void i40e_cee_to_dcb_config(
struct i40e_aqc_get_cee_dcb_cfg_resp *cee_cfg,
struct i40e_dcbx_config *dcbcfg)
{
u32 status, tlv_status = le32_to_cpu(cee_cfg->tlv_status);
u16 app_prio = le16_to_cpu(cee_cfg->oper_app_prio);
u8 i, tc, err, sync, oper;
dcbcfg->etscfg.maxtcs = cee_cfg->oper_num_tc;
for (i = 0; i < 4; i++) {
tc = (u8)((cee_cfg->oper_prio_tc[i] &
I40E_CEE_PGID_PRIO_1_MASK) >>
I40E_CEE_PGID_PRIO_1_SHIFT);
dcbcfg->etscfg.prioritytable[i*2] = tc;
tc = (u8)((cee_cfg->oper_prio_tc[i] &
I40E_CEE_PGID_PRIO_0_MASK) >>
I40E_CEE_PGID_PRIO_0_SHIFT);
dcbcfg->etscfg.prioritytable[i*2 + 1] = tc;
}
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++)
dcbcfg->etscfg.tcbwtable[i] = cee_cfg->oper_tc_bw[i];
for (i = 0; i < I40E_MAX_TRAFFIC_CLASS; i++) {
if (dcbcfg->etscfg.prioritytable[i] == I40E_CEE_PGID_STRICT) {
dcbcfg->etscfg.prioritytable[i] =
cee_cfg->oper_num_tc - 1;
dcbcfg->etscfg.tsatable[i] = I40E_IEEE_TSA_STRICT;
} else {
dcbcfg->etscfg.tsatable[i] = I40E_IEEE_TSA_ETS;
}
}
dcbcfg->pfc.pfcenable = cee_cfg->oper_pfc_en;
dcbcfg->pfc.pfccap = I40E_MAX_TRAFFIC_CLASS;
status = (tlv_status & I40E_AQC_CEE_APP_STATUS_MASK) >>
I40E_AQC_CEE_APP_STATUS_SHIFT;
err = (status & I40E_TLV_STATUS_ERR) ? 1 : 0;
sync = (status & I40E_TLV_STATUS_SYNC) ? 1 : 0;
oper = (status & I40E_TLV_STATUS_OPER) ? 1 : 0;
if (!err && sync && oper) {
dcbcfg->numapps = I40E_CEE_OPER_MAX_APPS;
dcbcfg->app[0].priority =
(app_prio & I40E_AQC_CEE_APP_FCOE_MASK) >>
I40E_AQC_CEE_APP_FCOE_SHIFT;
dcbcfg->app[0].selector = I40E_APP_SEL_ETHTYPE;
dcbcfg->app[0].protocolid = I40E_APP_PROTOID_FCOE;
dcbcfg->app[1].priority =
(app_prio & I40E_AQC_CEE_APP_ISCSI_MASK) >>
I40E_AQC_CEE_APP_ISCSI_SHIFT;
dcbcfg->app[1].selector = I40E_APP_SEL_TCPIP;
dcbcfg->app[1].protocolid = I40E_APP_PROTOID_ISCSI;
dcbcfg->app[2].priority =
(app_prio & I40E_AQC_CEE_APP_FIP_MASK) >>
I40E_AQC_CEE_APP_FIP_SHIFT;
dcbcfg->app[2].selector = I40E_APP_SEL_ETHTYPE;
dcbcfg->app[2].protocolid = I40E_APP_PROTOID_FIP;
}
}
i40e_status i40e_get_dcb_config(struct i40e_hw *hw)
{
i40e_status ret = 0;
struct i40e_aqc_get_cee_dcb_cfg_resp cee_cfg;
struct i40e_aqc_get_cee_dcb_cfg_v1_resp cee_v1_cfg;
if (((hw->aq.fw_maj_ver == 4) && (hw->aq.fw_min_ver < 33)) ||
(hw->aq.fw_maj_ver < 4))
goto ieee;
if ((hw->aq.fw_maj_ver == 4) && (hw->aq.fw_min_ver == 33)) {
ret = i40e_aq_get_cee_dcb_config(hw, &cee_v1_cfg,
sizeof(cee_v1_cfg), NULL);
if (!ret) {
hw->local_dcbx_config.dcbx_mode = I40E_DCBX_MODE_CEE;
i40e_cee_to_dcb_v1_config(&cee_v1_cfg,
&hw->local_dcbx_config);
}
} else {
ret = i40e_aq_get_cee_dcb_config(hw, &cee_cfg,
sizeof(cee_cfg), NULL);
if (!ret) {
hw->local_dcbx_config.dcbx_mode = I40E_DCBX_MODE_CEE;
i40e_cee_to_dcb_config(&cee_cfg,
&hw->local_dcbx_config);
}
}
if (hw->aq.asq_last_status == I40E_AQ_RC_ENOENT)
goto ieee;
else
goto out;
ieee:
hw->local_dcbx_config.dcbx_mode = I40E_DCBX_MODE_IEEE;
ret = i40e_aq_get_dcb_config(hw, I40E_AQ_LLDP_MIB_LOCAL, 0,
&hw->local_dcbx_config);
if (ret)
goto out;
ret = i40e_aq_get_dcb_config(hw, I40E_AQ_LLDP_MIB_REMOTE,
I40E_AQ_LLDP_BRIDGE_TYPE_NEAREST_BRIDGE,
&hw->remote_dcbx_config);
if (hw->aq.asq_last_status == I40E_AQ_RC_ENOENT)
ret = 0;
out:
return ret;
}
i40e_status i40e_init_dcb(struct i40e_hw *hw)
{
i40e_status ret = 0;
struct i40e_lldp_variables lldp_cfg;
u8 adminstatus = 0;
if (!hw->func_caps.dcb)
return ret;
ret = i40e_read_lldp_cfg(hw, &lldp_cfg);
if (ret)
return ret;
adminstatus = lldp_cfg.adminstatus >> (hw->port * 4);
adminstatus &= 0xF;
if (!adminstatus) {
hw->dcbx_status = I40E_DCBX_STATUS_DISABLED;
return ret;
}
ret = i40e_get_dcbx_status(hw, &hw->dcbx_status);
if (ret)
return ret;
switch (hw->dcbx_status) {
case I40E_DCBX_STATUS_DONE:
case I40E_DCBX_STATUS_IN_PROGRESS:
ret = i40e_get_dcb_config(hw);
if (ret)
return ret;
break;
case I40E_DCBX_STATUS_DISABLED:
return ret;
case I40E_DCBX_STATUS_NOT_STARTED:
case I40E_DCBX_STATUS_MULTIPLE_PEERS:
default:
break;
}
ret = i40e_aq_cfg_lldp_mib_change_event(hw, true, NULL);
if (ret)
return ret;
return ret;
}
i40e_status i40e_read_lldp_cfg(struct i40e_hw *hw,
struct i40e_lldp_variables *lldp_cfg)
{
i40e_status ret = 0;
u32 offset = (2 * I40E_NVM_LLDP_CFG_PTR);
if (!lldp_cfg)
return I40E_ERR_PARAM;
ret = i40e_acquire_nvm(hw, I40E_RESOURCE_READ);
if (ret)
goto err_lldp_cfg;
ret = i40e_aq_read_nvm(hw, I40E_SR_EMP_MODULE_PTR, offset,
sizeof(struct i40e_lldp_variables),
(u8 *)lldp_cfg,
true, NULL);
i40e_release_nvm(hw);
err_lldp_cfg:
return ret;
}
