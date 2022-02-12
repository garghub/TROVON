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
struct i40e_ieee_ets_config *etscfg;
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
if (!lldpmib || !dcbcfg)
return I40E_ERR_PARAM;
lldpmib += ETH_HLEN;
tlv = (struct i40e_lldp_org_tlv *)lldpmib;
while (tlv) {
typelength = ntohs(tlv->typelength);
type = (u16)((typelength & I40E_LLDP_TLV_TYPE_MASK) >>
I40E_LLDP_TLV_TYPE_SHIFT);
length = (u16)((typelength & I40E_LLDP_TLV_LEN_MASK) >>
I40E_LLDP_TLV_LEN_SHIFT);
if (type == I40E_TLV_TYPE_END)
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
i40e_status i40e_get_dcb_config(struct i40e_hw *hw)
{
i40e_status ret = 0;
ret = i40e_aq_get_dcb_config(hw, I40E_AQ_LLDP_MIB_LOCAL, 0,
&hw->local_dcbx_config);
if (ret)
goto out;
ret = i40e_aq_get_dcb_config(hw, I40E_AQ_LLDP_MIB_REMOTE,
I40E_AQ_LLDP_BRIDGE_TYPE_NEAREST_BRIDGE,
&hw->remote_dcbx_config);
out:
return ret;
}
i40e_status i40e_init_dcb(struct i40e_hw *hw)
{
i40e_status ret = 0;
if (!hw->func_caps.dcb)
return ret;
ret = i40e_get_dcbx_status(hw, &hw->dcbx_status);
if (ret)
return ret;
switch (hw->dcbx_status) {
case I40E_DCBX_STATUS_DONE:
case I40E_DCBX_STATUS_IN_PROGRESS:
ret = i40e_get_dcb_config(hw);
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
