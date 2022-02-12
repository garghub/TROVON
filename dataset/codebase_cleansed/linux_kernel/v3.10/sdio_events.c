void unifi_suspend(void *ospriv)
{
unifi_priv_t *priv = ospriv;
int interfaceTag=0;
priv->wol_suspend = (enable_wol == UNIFI_WOL_OFF) ? FALSE : TRUE;
unifi_trace(priv, UDBG1, "unifi_suspend: wol_suspend %d, enable_wol %d",
priv->wol_suspend, enable_wol );
for( interfaceTag=0;interfaceTag<CSR_WIFI_NUM_INTERFACES;interfaceTag++)
{
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
if (interfacePriv->netdev_registered == 1)
{
if( priv->wol_suspend ) {
unifi_trace(priv, UDBG1, "unifi_suspend: Don't netif_carrier_off");
} else {
unifi_trace(priv, UDBG1, "unifi_suspend: netif_carrier_off");
netif_carrier_off(priv->netdev[interfaceTag]);
}
netif_tx_stop_all_queues(priv->netdev[interfaceTag]);
}
}
unifi_trace(priv, UDBG1, "unifi_suspend: suspend SME");
sme_sys_suspend(priv);
}
void unifi_resume(void *ospriv)
{
unifi_priv_t *priv = ospriv;
int interfaceTag=0;
int r;
int wol = priv->wol_suspend;
unifi_trace(priv, UDBG1, "unifi_resume: resume SME, enable_wol=%d", enable_wol);
r = sme_sys_resume(priv);
if (r) {
unifi_error(priv, "Failed to resume UniFi\n");
}
if (wol) {
unifi_trace(priv, UDBG1, "unifi_resume: try to enable carrier");
for( interfaceTag=0;interfaceTag<CSR_WIFI_NUM_INTERFACES;interfaceTag++) {
netInterface_priv_t *interfacePriv = priv->interfacePriv[interfaceTag];
unifi_trace(priv, UDBG1, "unifi_resume: interfaceTag %d netdev_registered %d mode %d\n",
interfaceTag, interfacePriv->netdev_registered, interfacePriv->interfaceMode);
if (interfacePriv->netdev_registered == 1)
{
netif_carrier_on(priv->netdev[interfaceTag]);
netif_tx_start_all_queues(priv->netdev[interfaceTag]);
}
}
unifi_send_signal(priv->card, NULL, 0, NULL);
}
}
