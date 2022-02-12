int wpa_set_keys(struct vnt_private *pDevice, void *ctx)
{
struct viawget_wpa_param *param = ctx;
struct vnt_manager *pMgmt = &pDevice->vnt_mgmt;
u32 dwKeyIndex = 0;
u8 abyKey[MAX_KEY_LEN];
u8 abySeq[MAX_KEY_LEN];
u64 KeyRSC;
u8 byKeyDecMode = KEY_CTL_WEP;
int ret = 0;
int uu;
int ii;
if (param->u.wpa_key.alg_name > WPA_ALG_CCMP)
return -EINVAL;
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "param->u.wpa_key.alg_name = %d \n",
param->u.wpa_key.alg_name);
if (param->u.wpa_key.alg_name == WPA_ALG_NONE) {
pDevice->eEncryptionStatus = Ndis802_11EncryptionDisabled;
pDevice->bEncryptionEnable = false;
pDevice->byKeyIndex = 0;
pDevice->bTransmitKey = false;
for (uu=0; uu<MAX_KEY_TABLE; uu++) {
MACvDisableKeyEntry(pDevice, uu);
}
return ret;
}
if (param->u.wpa_key.key && param->u.wpa_key.key_len > sizeof(abyKey))
return -EINVAL;
memcpy(&abyKey[0], param->u.wpa_key.key, param->u.wpa_key.key_len);
dwKeyIndex = (u32)(param->u.wpa_key.key_index);
if (param->u.wpa_key.alg_name == WPA_ALG_WEP) {
if (dwKeyIndex > 3) {
return -EINVAL;
} else {
if (param->u.wpa_key.set_tx) {
pDevice->byKeyIndex = (u8)dwKeyIndex;
pDevice->bTransmitKey = true;
dwKeyIndex |= (1 << 31);
}
KeybSetDefaultKey( pDevice,
&(pDevice->sKey),
dwKeyIndex & ~(BIT30 | USE_KEYRSC),
param->u.wpa_key.key_len,
NULL,
abyKey,
KEY_CTL_WEP
);
}
pDevice->eEncryptionStatus = Ndis802_11Encryption1Enabled;
pDevice->bEncryptionEnable = true;
return ret;
}
if (param->u.wpa_key.seq && param->u.wpa_key.seq_len > sizeof(abySeq))
return -EINVAL;
memcpy(&abySeq[0], param->u.wpa_key.seq, param->u.wpa_key.seq_len);
if (param->u.wpa_key.seq_len > 0) {
for (ii = 0 ; ii < param->u.wpa_key.seq_len ; ii++) {
if (ii < 4)
KeyRSC |= (abySeq[ii] << (ii * 8));
else
KeyRSC |= (abySeq[ii] << ((ii-4) * 8));
}
dwKeyIndex |= 1 << 29;
}
if (param->u.wpa_key.key_index >= MAX_GROUP_KEY) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "return dwKeyIndex > 3\n");
return -EINVAL;
}
if (param->u.wpa_key.alg_name == WPA_ALG_TKIP) {
pDevice->eEncryptionStatus = Ndis802_11Encryption2Enabled;
}
if (param->u.wpa_key.alg_name == WPA_ALG_CCMP) {
pDevice->eEncryptionStatus = Ndis802_11Encryption3Enabled;
}
if (param->u.wpa_key.set_tx)
dwKeyIndex |= (1 << 31);
if (pDevice->eEncryptionStatus == Ndis802_11Encryption3Enabled)
byKeyDecMode = KEY_CTL_CCMP;
else if (pDevice->eEncryptionStatus == Ndis802_11Encryption2Enabled)
byKeyDecMode = KEY_CTL_TKIP;
else
byKeyDecMode = KEY_CTL_WEP;
if (pDevice->eEncryptionStatus == Ndis802_11Encryption3Enabled) {
if (param->u.wpa_key.key_len == MAX_KEY_LEN)
byKeyDecMode = KEY_CTL_TKIP;
else if (param->u.wpa_key.key_len == WLAN_WEP40_KEYLEN)
byKeyDecMode = KEY_CTL_WEP;
else if (param->u.wpa_key.key_len == WLAN_WEP104_KEYLEN)
byKeyDecMode = KEY_CTL_WEP;
} else if (pDevice->eEncryptionStatus == Ndis802_11Encryption2Enabled) {
if (param->u.wpa_key.key_len == WLAN_WEP40_KEYLEN)
byKeyDecMode = KEY_CTL_WEP;
else if (param->u.wpa_key.key_len == WLAN_WEP104_KEYLEN)
byKeyDecMode = KEY_CTL_WEP;
}
if ((byKeyDecMode == KEY_CTL_TKIP) &&
(param->u.wpa_key.key_len != MAX_KEY_LEN)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "return - TKIP Key must be 256 bits!\n");
return -EINVAL;
}
if ((byKeyDecMode == KEY_CTL_CCMP) &&
(param->u.wpa_key.key_len != AES_KEY_LEN)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "return - AES Key must be 128 bits\n");
return -EINVAL;
}
if (is_broadcast_ether_addr(&param->addr[0]) || (param->addr == NULL)) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Groupe Key Assign.\n");
if ((KeybSetAllGroupKey(pDevice, &(pDevice->sKey), dwKeyIndex,
param->u.wpa_key.key_len,
&KeyRSC,
(u8 *)abyKey,
byKeyDecMode
) == true) &&
(KeybSetDefaultKey(pDevice,
&(pDevice->sKey),
dwKeyIndex,
param->u.wpa_key.key_len,
&KeyRSC,
(u8 *)abyKey,
byKeyDecMode
) == true) ) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "GROUP Key Assign.\n");
} else {
return -EINVAL;
}
} else {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Pairwise Key Assign.\n");
if (byKeyDecMode == KEY_CTL_WEP) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Pairwise Key can't be WEP\n");
return -EINVAL;
}
dwKeyIndex |= (1 << 30);
if (pMgmt->eConfigMode == WMAC_CONFIG_IBSS_STA) {
return -EINVAL;
}
if (KeybSetKey(pDevice, &(pDevice->sKey), &param->addr[0],
dwKeyIndex, param->u.wpa_key.key_len,
&KeyRSC, (u8 *)abyKey, byKeyDecMode
) == true) {
DBG_PRT(MSG_LEVEL_DEBUG, KERN_INFO "Pairwise Key Set\n");
} else {
if (!compare_ether_addr(&param->addr[0], pDevice->abyBSSID)) {
return -EINVAL;
} else {
return -EINVAL;
}
}
}
if ((ret == 0) && ((param->u.wpa_key.set_tx) != 0)) {
pDevice->byKeyIndex = (u8)param->u.wpa_key.key_index;
pDevice->bTransmitKey = true;
}
pDevice->bEncryptionEnable = true;
return ret;
}
