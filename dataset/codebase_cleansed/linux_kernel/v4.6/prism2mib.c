int prism2mgmt_mibset_mibget(wlandevice_t *wlandev, void *msgp)
{
hfa384x_t *hw = wlandev->priv;
int result, isget;
struct mibrec *mib;
u16 which;
struct p80211msg_dot11req_mibset *msg = msgp;
p80211itemd_t *mibitem;
msg->resultcode.status = P80211ENUM_msgitem_status_data_ok;
msg->resultcode.data = P80211ENUM_resultcode_success;
which = F_STA;
mibitem = (p80211itemd_t *) msg->mibattribute.data;
for (mib = mibtab; mib->did != 0; mib++)
if (mib->did == mibitem->did && (mib->flag & which))
break;
if (mib->did == 0) {
msg->resultcode.data = P80211ENUM_resultcode_not_supported;
goto done;
}
isget = (msg->msgcode == DIDmsg_dot11req_mibget);
if (isget) {
if (!(mib->flag & F_READ)) {
msg->resultcode.data =
P80211ENUM_resultcode_cant_get_writeonly_mib;
goto done;
}
} else {
if (!(mib->flag & F_WRITE)) {
msg->resultcode.data =
P80211ENUM_resultcode_cant_set_readonly_mib;
goto done;
}
}
result = mib->func(mib, isget, wlandev, hw, msg, (void *)mibitem->data);
if (msg->resultcode.data == P80211ENUM_resultcode_success) {
if (result != 0) {
pr_debug("get/set failure, result=%d\n", result);
msg->resultcode.data =
P80211ENUM_resultcode_implementation_failure;
} else {
if (isget) {
msg->mibattribute.status =
P80211ENUM_msgitem_status_data_ok;
mibitem->status =
P80211ENUM_msgitem_status_data_ok;
}
}
}
done:
return 0;
}
static int prism2mib_bytearea2pstr(struct mibrec *mib,
int isget,
wlandevice_t *wlandev,
hfa384x_t *hw,
struct p80211msg_dot11req_mibset *msg,
void *data)
{
int result;
p80211pstrd_t *pstr = data;
u8 bytebuf[MIB_TMP_MAXLEN];
if (isget) {
result =
hfa384x_drvr_getconfig(hw, mib->parm1, bytebuf, mib->parm2);
prism2mgmt_bytearea2pstr(bytebuf, pstr, mib->parm2);
} else {
memset(bytebuf, 0, mib->parm2);
memcpy(bytebuf, pstr->data, pstr->len);
result =
hfa384x_drvr_setconfig(hw, mib->parm1, bytebuf, mib->parm2);
}
return result;
}
static int prism2mib_uint32(struct mibrec *mib,
int isget,
wlandevice_t *wlandev,
hfa384x_t *hw,
struct p80211msg_dot11req_mibset *msg, void *data)
{
int result;
u32 *uint32 = data;
u8 bytebuf[MIB_TMP_MAXLEN];
u16 *wordbuf = (u16 *) bytebuf;
if (isget) {
result = hfa384x_drvr_getconfig16(hw, mib->parm1, wordbuf);
*uint32 = *wordbuf;
} else {
*wordbuf = *uint32;
result = hfa384x_drvr_setconfig16(hw, mib->parm1, *wordbuf);
}
return result;
}
static int prism2mib_flag(struct mibrec *mib,
int isget,
wlandevice_t *wlandev,
hfa384x_t *hw,
struct p80211msg_dot11req_mibset *msg, void *data)
{
int result;
u32 *uint32 = data;
u8 bytebuf[MIB_TMP_MAXLEN];
u16 *wordbuf = (u16 *) bytebuf;
u32 flags;
result = hfa384x_drvr_getconfig16(hw, mib->parm1, wordbuf);
if (result == 0) {
flags = *wordbuf;
if (isget) {
*uint32 = (flags & mib->parm2) ?
P80211ENUM_truth_true : P80211ENUM_truth_false;
} else {
if ((*uint32) == P80211ENUM_truth_true)
flags |= mib->parm2;
else
flags &= ~mib->parm2;
*wordbuf = flags;
result =
hfa384x_drvr_setconfig16(hw, mib->parm1, *wordbuf);
}
}
return result;
}
static int prism2mib_wepdefaultkey(struct mibrec *mib,
int isget,
wlandevice_t *wlandev,
hfa384x_t *hw,
struct p80211msg_dot11req_mibset *msg,
void *data)
{
int result;
p80211pstrd_t *pstr = data;
u8 bytebuf[MIB_TMP_MAXLEN];
u16 len;
if (isget) {
result = 0;
} else {
len = (pstr->len > 5) ? HFA384x_RID_CNFWEP128DEFAULTKEY_LEN :
HFA384x_RID_CNFWEPDEFAULTKEY_LEN;
memset(bytebuf, 0, len);
memcpy(bytebuf, pstr->data, pstr->len);
result = hfa384x_drvr_setconfig(hw, mib->parm1, bytebuf, len);
}
return result;
}
static int prism2mib_privacyinvoked(struct mibrec *mib,
int isget,
wlandevice_t *wlandev,
hfa384x_t *hw,
struct p80211msg_dot11req_mibset *msg,
void *data)
{
if (wlandev->hostwep & HOSTWEP_DECRYPT) {
if (wlandev->hostwep & HOSTWEP_DECRYPT)
mib->parm2 |= HFA384x_WEPFLAGS_DISABLE_RXCRYPT;
if (wlandev->hostwep & HOSTWEP_ENCRYPT)
mib->parm2 |= HFA384x_WEPFLAGS_DISABLE_TXCRYPT;
}
return prism2mib_flag(mib, isget, wlandev, hw, msg, data);
}
static int prism2mib_excludeunencrypted(struct mibrec *mib,
int isget,
wlandevice_t *wlandev,
hfa384x_t *hw,
struct p80211msg_dot11req_mibset *msg,
void *data)
{
return prism2mib_flag(mib, isget, wlandev, hw, msg, data);
}
static int prism2mib_fragmentationthreshold(struct mibrec *mib,
int isget,
wlandevice_t *wlandev,
hfa384x_t *hw,
struct p80211msg_dot11req_mibset *msg,
void *data)
{
u32 *uint32 = data;
if (!isget)
if ((*uint32) % 2) {
netdev_warn(wlandev->netdev,
"Attempt to set odd number FragmentationThreshold\n");
msg->resultcode.data =
P80211ENUM_resultcode_not_supported;
return 0;
}
return prism2mib_uint32(mib, isget, wlandev, hw, msg, data);
}
static int prism2mib_priv(struct mibrec *mib,
int isget,
wlandevice_t *wlandev,
hfa384x_t *hw,
struct p80211msg_dot11req_mibset *msg, void *data)
{
p80211pstrd_t *pstr = data;
switch (mib->did) {
case DIDmib_lnx_lnxConfigTable_lnxRSNAIE:{
hfa384x_WPAData_t wpa;
if (isget) {
hfa384x_drvr_getconfig(hw,
HFA384x_RID_CNFWPADATA,
(u8 *) &wpa,
sizeof(wpa));
pstr->len = le16_to_cpu(wpa.datalen);
memcpy(pstr->data, wpa.data, pstr->len);
} else {
wpa.datalen = cpu_to_le16(pstr->len);
memcpy(wpa.data, pstr->data, pstr->len);
hfa384x_drvr_setconfig(hw,
HFA384x_RID_CNFWPADATA,
(u8 *) &wpa,
sizeof(wpa));
}
break;
}
default:
netdev_err(wlandev->netdev, "Unhandled DID 0x%08x\n", mib->did);
}
return 0;
}
void prism2mgmt_pstr2bytestr(struct hfa384x_bytestr *bytestr,
p80211pstrd_t *pstr)
{
bytestr->len = cpu_to_le16((u16) (pstr->len));
memcpy(bytestr->data, pstr->data, pstr->len);
}
void prism2mgmt_bytestr2pstr(struct hfa384x_bytestr *bytestr,
p80211pstrd_t *pstr)
{
pstr->len = (u8) (le16_to_cpu((u16) (bytestr->len)));
memcpy(pstr->data, bytestr->data, pstr->len);
}
void prism2mgmt_bytearea2pstr(u8 *bytearea, p80211pstrd_t *pstr, int len)
{
pstr->len = (u8) len;
memcpy(pstr->data, bytearea, len);
}
