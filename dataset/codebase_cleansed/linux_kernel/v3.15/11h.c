static void
mwifiex_11h_process_infra_join(struct mwifiex_private *priv, u8 **buffer,
struct mwifiex_bssdescriptor *bss_desc)
{
struct mwifiex_ie_types_header *ie_header;
struct mwifiex_ie_types_pwr_capability *cap;
struct mwifiex_ie_types_local_pwr_constraint *constraint;
struct ieee80211_supported_band *sband;
u8 radio_type;
int i;
if (!buffer || !(*buffer))
return;
radio_type = mwifiex_band_to_radio_type((u8) bss_desc->bss_band);
sband = priv->wdev->wiphy->bands[radio_type];
cap = (struct mwifiex_ie_types_pwr_capability *)*buffer;
cap->header.type = cpu_to_le16(WLAN_EID_PWR_CAPABILITY);
cap->header.len = cpu_to_le16(2);
cap->min_pwr = 0;
cap->max_pwr = 0;
*buffer += sizeof(*cap);
constraint = (struct mwifiex_ie_types_local_pwr_constraint *)*buffer;
constraint->header.type = cpu_to_le16(WLAN_EID_PWR_CONSTRAINT);
constraint->header.len = cpu_to_le16(2);
constraint->chan = bss_desc->channel;
constraint->constraint = bss_desc->local_constraint;
*buffer += sizeof(*constraint);
ie_header = (struct mwifiex_ie_types_header *)*buffer;
ie_header->type = cpu_to_le16(TLV_TYPE_PASSTHROUGH);
ie_header->len = cpu_to_le16(2 * sband->n_channels + 2);
*buffer += sizeof(*ie_header);
*(*buffer)++ = WLAN_EID_SUPPORTED_CHANNELS;
*(*buffer)++ = 2 * sband->n_channels;
for (i = 0; i < sband->n_channels; i++) {
*(*buffer)++ = ieee80211_frequency_to_channel(
sband->channels[i].center_freq);
*(*buffer)++ = 1;
}
}
static int mwifiex_11h_activate(struct mwifiex_private *priv, bool flag)
{
u32 enable = flag;
return mwifiex_send_cmd(priv, HostCmd_CMD_802_11_SNMP_MIB,
HostCmd_ACT_GEN_SET, DOT11H_I, &enable, true);
}
void mwifiex_11h_process_join(struct mwifiex_private *priv, u8 **buffer,
struct mwifiex_bssdescriptor *bss_desc)
{
if (bss_desc->sensed_11h) {
mwifiex_11h_activate(priv, true);
bss_desc->cap_info_bitmap |= WLAN_CAPABILITY_SPECTRUM_MGMT;
mwifiex_11h_process_infra_join(priv, buffer, bss_desc);
} else {
mwifiex_11h_activate(priv, false);
bss_desc->cap_info_bitmap &= ~WLAN_CAPABILITY_SPECTRUM_MGMT;
}
}
