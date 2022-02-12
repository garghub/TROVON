int
uf_init_hw(unifi_priv_t *priv)
{
int attempts = 0;
int priv_instance;
CsrResult csrResult = CSR_RESULT_FAILURE;
priv_instance = uf_find_priv(priv);
if (priv_instance == -1) {
unifi_warning(priv, "uf_init_hw: Unknown priv instance, will use fw_init[0]\n");
priv_instance = 0;
}
while (1) {
if (attempts > MAX_INIT_ATTEMPTS) {
unifi_error(priv, "Failed to initialise UniFi after %d attempts, "
"giving up.\n",
attempts);
break;
}
attempts++;
unifi_info(priv, "Initialising UniFi, attempt %d\n", attempts);
if (fw_init[priv_instance] > 0) {
unifi_notice(priv, "f/w init prevented by module parameter\n");
break;
} else if (fw_init[priv_instance] == 0) {
fw_init[priv_instance] ++;
}
CsrSdioClaim(priv->sdio);
csrResult = unifi_init_card(priv->card, led_mask);
CsrSdioRelease(priv->sdio);
if (csrResult == CSR_WIFI_HIP_RESULT_NO_DEVICE) {
return CsrHipResultToStatus(csrResult);
}
if (csrResult == CSR_WIFI_HIP_RESULT_NOT_FOUND) {
unifi_error(priv, "Firmware file required, but not found.\n");
return CsrHipResultToStatus(csrResult);
}
if (csrResult != CSR_RESULT_SUCCESS) {
unifi_error(priv, "Failed to initialise UniFi chip.\n");
continue;
}
unifi_card_info(priv->card, &priv->card_info);
return CsrHipResultToStatus(csrResult);
}
return CsrHipResultToStatus(csrResult);
}
