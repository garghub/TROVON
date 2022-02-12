void
PSvEnablePowerSaving(
struct vnt_private *priv,
unsigned short wListenInterval
)
{
u16 wAID = priv->current_aid | BIT(14) | BIT(15);
VNSvOutPortW(priv->PortOffset + MAC_REG_PWBT, C_PWBT);
if (priv->op_mode != NL80211_IFTYPE_ADHOC) {
VNSvOutPortW(priv->PortOffset + MAC_REG_AIDATIM, wAID);
} else {
#if 0
MACvWriteATIMW(priv->PortOffset, pMgmt->wCurrATIMWindow);
#endif
}
MACvRegBitsOn(priv->PortOffset, MAC_REG_PSCFG, PSCFG_AUTOSLEEP);
MACvRegBitsOn(priv->PortOffset, MAC_REG_TFTCTL, TFTCTL_HWUTSF);
if (wListenInterval >= 2) {
MACvRegBitsOff(priv->PortOffset, MAC_REG_PSCTL, PSCTL_ALBCN);
MACvRegBitsOn(priv->PortOffset, MAC_REG_PSCTL, PSCTL_LNBCN);
} else {
MACvRegBitsOn(priv->PortOffset, MAC_REG_PSCTL, PSCTL_ALBCN);
}
MACvRegBitsOn(priv->PortOffset, MAC_REG_PSCTL, PSCTL_PSEN);
priv->bEnablePSMode = true;
priv->bPWBitOn = true;
pr_debug("PS:Power Saving Mode Enable...\n");
}
void
PSvDisablePowerSaving(
struct vnt_private *priv
)
{
MACbPSWakeup(priv);
MACvRegBitsOff(priv->PortOffset, MAC_REG_PSCFG, PSCFG_AUTOSLEEP);
MACvRegBitsOff(priv->PortOffset, MAC_REG_TFTCTL, TFTCTL_HWUTSF);
MACvRegBitsOn(priv->PortOffset, MAC_REG_PSCTL, PSCTL_ALBCN);
priv->bEnablePSMode = false;
priv->bPWBitOn = false;
}
bool
PSbIsNextTBTTWakeUp(
struct vnt_private *priv
)
{
struct ieee80211_hw *hw = priv->hw;
struct ieee80211_conf *conf = &hw->conf;
bool wake_up = false;
if (conf->listen_interval > 1) {
if (!priv->wake_up_count)
priv->wake_up_count = conf->listen_interval;
--priv->wake_up_count;
if (priv->wake_up_count == 1) {
MACvRegBitsOn(priv->PortOffset,
MAC_REG_PSCTL, PSCTL_LNBCN);
wake_up = true;
}
}
return wake_up;
}
