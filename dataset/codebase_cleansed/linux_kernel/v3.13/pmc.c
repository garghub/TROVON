int wcn36xx_pmc_enter_bmps_state(struct wcn36xx *wcn,
struct ieee80211_vif *vif)
{
int ret = 0;
struct wcn36xx_vif *vif_priv = (struct wcn36xx_vif *)vif->drv_priv;
ret = wcn36xx_smd_enter_bmps(wcn, vif);
if (!ret) {
wcn36xx_dbg(WCN36XX_DBG_PMC, "Entered BMPS\n");
vif_priv->pw_state = WCN36XX_BMPS;
} else {
wcn36xx_err("Can not enter BMPS!\n");
}
return ret;
}
int wcn36xx_pmc_exit_bmps_state(struct wcn36xx *wcn,
struct ieee80211_vif *vif)
{
struct wcn36xx_vif *vif_priv = (struct wcn36xx_vif *)vif->drv_priv;
if (WCN36XX_BMPS != vif_priv->pw_state) {
wcn36xx_err("Not in BMPS mode, no need to exit from BMPS mode!\n");
return -EINVAL;
}
wcn36xx_smd_exit_bmps(wcn, vif);
vif_priv->pw_state = WCN36XX_FULL_POWER;
return 0;
}
int wcn36xx_enable_keep_alive_null_packet(struct wcn36xx *wcn,
struct ieee80211_vif *vif)
{
wcn36xx_dbg(WCN36XX_DBG_PMC, "%s\n", __func__);
return wcn36xx_smd_keep_alive_req(wcn, vif,
WCN36XX_HAL_KEEP_ALIVE_NULL_PKT);
}
