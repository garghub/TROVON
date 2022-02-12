static int iwl_legacy_eeprom_verify_signature(struct iwl_priv *priv)
{
u32 gp = iwl_read32(priv, CSR_EEPROM_GP) & CSR_EEPROM_GP_VALID_MSK;
int ret = 0;
IWL_DEBUG_EEPROM(priv, "EEPROM signature=0x%08x\n", gp);
switch (gp) {
case CSR_EEPROM_GP_GOOD_SIG_EEP_LESS_THAN_4K:
case CSR_EEPROM_GP_GOOD_SIG_EEP_MORE_THAN_4K:
break;
default:
IWL_ERR(priv, "bad EEPROM signature,"
"EEPROM_GP=0x%08x\n", gp);
ret = -ENOENT;
break;
}
return ret;
}
const u8
*iwl_legacy_eeprom_query_addr(const struct iwl_priv *priv, size_t offset)
{
BUG_ON(offset >= priv->cfg->base_params->eeprom_size);
return &priv->eeprom[offset];
}
u16 iwl_legacy_eeprom_query16(const struct iwl_priv *priv, size_t offset)
{
if (!priv->eeprom)
return 0;
return (u16)priv->eeprom[offset] | ((u16)priv->eeprom[offset + 1] << 8);
}
int iwl_legacy_eeprom_init(struct iwl_priv *priv)
{
__le16 *e;
u32 gp = iwl_read32(priv, CSR_EEPROM_GP);
int sz;
int ret;
u16 addr;
sz = priv->cfg->base_params->eeprom_size;
IWL_DEBUG_EEPROM(priv, "NVM size = %d\n", sz);
priv->eeprom = kzalloc(sz, GFP_KERNEL);
if (!priv->eeprom) {
ret = -ENOMEM;
goto alloc_err;
}
e = (__le16 *)priv->eeprom;
priv->cfg->ops->lib->apm_ops.init(priv);
ret = iwl_legacy_eeprom_verify_signature(priv);
if (ret < 0) {
IWL_ERR(priv, "EEPROM not found, EEPROM_GP=0x%08x\n", gp);
ret = -ENOENT;
goto err;
}
ret = priv->cfg->ops->lib->eeprom_ops.acquire_semaphore(priv);
if (ret < 0) {
IWL_ERR(priv, "Failed to acquire EEPROM semaphore.\n");
ret = -ENOENT;
goto err;
}
for (addr = 0; addr < sz; addr += sizeof(u16)) {
u32 r;
_iwl_legacy_write32(priv, CSR_EEPROM_REG,
CSR_EEPROM_REG_MSK_ADDR & (addr << 1));
ret = iwl_poll_bit(priv, CSR_EEPROM_REG,
CSR_EEPROM_REG_READ_VALID_MSK,
CSR_EEPROM_REG_READ_VALID_MSK,
IWL_EEPROM_ACCESS_TIMEOUT);
if (ret < 0) {
IWL_ERR(priv, "Time out reading EEPROM[%d]\n",
addr);
goto done;
}
r = _iwl_legacy_read_direct32(priv, CSR_EEPROM_REG);
e[addr / 2] = cpu_to_le16(r >> 16);
}
IWL_DEBUG_EEPROM(priv, "NVM Type: %s, version: 0x%x\n",
"EEPROM",
iwl_legacy_eeprom_query16(priv, EEPROM_VERSION));
ret = 0;
done:
priv->cfg->ops->lib->eeprom_ops.release_semaphore(priv);
err:
if (ret)
iwl_legacy_eeprom_free(priv);
iwl_legacy_apm_stop(priv);
alloc_err:
return ret;
}
void iwl_legacy_eeprom_free(struct iwl_priv *priv)
{
kfree(priv->eeprom);
priv->eeprom = NULL;
}
static void iwl_legacy_init_band_reference(const struct iwl_priv *priv,
int eep_band, int *eeprom_ch_count,
const struct iwl_eeprom_channel **eeprom_ch_info,
const u8 **eeprom_ch_index)
{
u32 offset = priv->cfg->ops->lib->
eeprom_ops.regulatory_bands[eep_band - 1];
switch (eep_band) {
case 1:
*eeprom_ch_count = ARRAY_SIZE(iwlegacy_eeprom_band_1);
*eeprom_ch_info = (struct iwl_eeprom_channel *)
iwl_legacy_eeprom_query_addr(priv, offset);
*eeprom_ch_index = iwlegacy_eeprom_band_1;
break;
case 2:
*eeprom_ch_count = ARRAY_SIZE(iwlegacy_eeprom_band_2);
*eeprom_ch_info = (struct iwl_eeprom_channel *)
iwl_legacy_eeprom_query_addr(priv, offset);
*eeprom_ch_index = iwlegacy_eeprom_band_2;
break;
case 3:
*eeprom_ch_count = ARRAY_SIZE(iwlegacy_eeprom_band_3);
*eeprom_ch_info = (struct iwl_eeprom_channel *)
iwl_legacy_eeprom_query_addr(priv, offset);
*eeprom_ch_index = iwlegacy_eeprom_band_3;
break;
case 4:
*eeprom_ch_count = ARRAY_SIZE(iwlegacy_eeprom_band_4);
*eeprom_ch_info = (struct iwl_eeprom_channel *)
iwl_legacy_eeprom_query_addr(priv, offset);
*eeprom_ch_index = iwlegacy_eeprom_band_4;
break;
case 5:
*eeprom_ch_count = ARRAY_SIZE(iwlegacy_eeprom_band_5);
*eeprom_ch_info = (struct iwl_eeprom_channel *)
iwl_legacy_eeprom_query_addr(priv, offset);
*eeprom_ch_index = iwlegacy_eeprom_band_5;
break;
case 6:
*eeprom_ch_count = ARRAY_SIZE(iwlegacy_eeprom_band_6);
*eeprom_ch_info = (struct iwl_eeprom_channel *)
iwl_legacy_eeprom_query_addr(priv, offset);
*eeprom_ch_index = iwlegacy_eeprom_band_6;
break;
case 7:
*eeprom_ch_count = ARRAY_SIZE(iwlegacy_eeprom_band_7);
*eeprom_ch_info = (struct iwl_eeprom_channel *)
iwl_legacy_eeprom_query_addr(priv, offset);
*eeprom_ch_index = iwlegacy_eeprom_band_7;
break;
default:
BUG();
}
}
static int iwl_legacy_mod_ht40_chan_info(struct iwl_priv *priv,
enum ieee80211_band band, u16 channel,
const struct iwl_eeprom_channel *eeprom_ch,
u8 clear_ht40_extension_channel)
{
struct iwl_channel_info *ch_info;
ch_info = (struct iwl_channel_info *)
iwl_legacy_get_channel_info(priv, band, channel);
if (!iwl_legacy_is_channel_valid(ch_info))
return -1;
IWL_DEBUG_EEPROM(priv, "HT40 Ch. %d [%sGHz] %s%s%s%s%s(0x%02x %ddBm):"
" Ad-Hoc %ssupported\n",
ch_info->channel,
iwl_legacy_is_channel_a_band(ch_info) ?
"5.2" : "2.4",
CHECK_AND_PRINT(IBSS),
CHECK_AND_PRINT(ACTIVE),
CHECK_AND_PRINT(RADAR),
CHECK_AND_PRINT(WIDE),
CHECK_AND_PRINT(DFS),
eeprom_ch->flags,
eeprom_ch->max_power_avg,
((eeprom_ch->flags & EEPROM_CHANNEL_IBSS)
&& !(eeprom_ch->flags & EEPROM_CHANNEL_RADAR)) ?
"" : "not ");
ch_info->ht40_eeprom = *eeprom_ch;
ch_info->ht40_max_power_avg = eeprom_ch->max_power_avg;
ch_info->ht40_flags = eeprom_ch->flags;
if (eeprom_ch->flags & EEPROM_CHANNEL_VALID)
ch_info->ht40_extension_channel &=
~clear_ht40_extension_channel;
return 0;
}
int iwl_legacy_init_channel_map(struct iwl_priv *priv)
{
int eeprom_ch_count = 0;
const u8 *eeprom_ch_index = NULL;
const struct iwl_eeprom_channel *eeprom_ch_info = NULL;
int band, ch;
struct iwl_channel_info *ch_info;
if (priv->channel_count) {
IWL_DEBUG_EEPROM(priv, "Channel map already initialized.\n");
return 0;
}
IWL_DEBUG_EEPROM(priv, "Initializing regulatory info from EEPROM\n");
priv->channel_count =
ARRAY_SIZE(iwlegacy_eeprom_band_1) +
ARRAY_SIZE(iwlegacy_eeprom_band_2) +
ARRAY_SIZE(iwlegacy_eeprom_band_3) +
ARRAY_SIZE(iwlegacy_eeprom_band_4) +
ARRAY_SIZE(iwlegacy_eeprom_band_5);
IWL_DEBUG_EEPROM(priv, "Parsing data for %d channels.\n",
priv->channel_count);
priv->channel_info = kzalloc(sizeof(struct iwl_channel_info) *
priv->channel_count, GFP_KERNEL);
if (!priv->channel_info) {
IWL_ERR(priv, "Could not allocate channel_info\n");
priv->channel_count = 0;
return -ENOMEM;
}
ch_info = priv->channel_info;
for (band = 1; band <= 5; band++) {
iwl_legacy_init_band_reference(priv, band, &eeprom_ch_count,
&eeprom_ch_info, &eeprom_ch_index);
for (ch = 0; ch < eeprom_ch_count; ch++) {
ch_info->channel = eeprom_ch_index[ch];
ch_info->band = (band == 1) ? IEEE80211_BAND_2GHZ :
IEEE80211_BAND_5GHZ;
ch_info->eeprom = eeprom_ch_info[ch];
ch_info->flags = eeprom_ch_info[ch].flags;
ch_info->ht40_extension_channel =
IEEE80211_CHAN_NO_HT40;
if (!(iwl_legacy_is_channel_valid(ch_info))) {
IWL_DEBUG_EEPROM(priv,
"Ch. %d Flags %x [%sGHz] - "
"No traffic\n",
ch_info->channel,
ch_info->flags,
iwl_legacy_is_channel_a_band(ch_info) ?
"5.2" : "2.4");
ch_info++;
continue;
}
ch_info->max_power_avg = ch_info->curr_txpow =
eeprom_ch_info[ch].max_power_avg;
ch_info->scan_power = eeprom_ch_info[ch].max_power_avg;
ch_info->min_power = 0;
IWL_DEBUG_EEPROM(priv, "Ch. %d [%sGHz] "
"%s%s%s%s%s%s(0x%02x %ddBm):"
" Ad-Hoc %ssupported\n",
ch_info->channel,
iwl_legacy_is_channel_a_band(ch_info) ?
"5.2" : "2.4",
CHECK_AND_PRINT_I(VALID),
CHECK_AND_PRINT_I(IBSS),
CHECK_AND_PRINT_I(ACTIVE),
CHECK_AND_PRINT_I(RADAR),
CHECK_AND_PRINT_I(WIDE),
CHECK_AND_PRINT_I(DFS),
eeprom_ch_info[ch].flags,
eeprom_ch_info[ch].max_power_avg,
((eeprom_ch_info[ch].
flags & EEPROM_CHANNEL_IBSS)
&& !(eeprom_ch_info[ch].
flags & EEPROM_CHANNEL_RADAR))
? "" : "not ");
ch_info++;
}
}
if (priv->cfg->ops->lib->eeprom_ops.regulatory_bands[5] ==
EEPROM_REGULATORY_BAND_NO_HT40 &&
priv->cfg->ops->lib->eeprom_ops.regulatory_bands[6] ==
EEPROM_REGULATORY_BAND_NO_HT40)
return 0;
for (band = 6; band <= 7; band++) {
enum ieee80211_band ieeeband;
iwl_legacy_init_band_reference(priv, band, &eeprom_ch_count,
&eeprom_ch_info, &eeprom_ch_index);
ieeeband =
(band == 6) ? IEEE80211_BAND_2GHZ : IEEE80211_BAND_5GHZ;
for (ch = 0; ch < eeprom_ch_count; ch++) {
iwl_legacy_mod_ht40_chan_info(priv, ieeeband,
eeprom_ch_index[ch],
&eeprom_ch_info[ch],
IEEE80211_CHAN_NO_HT40PLUS);
iwl_legacy_mod_ht40_chan_info(priv, ieeeband,
eeprom_ch_index[ch] + 4,
&eeprom_ch_info[ch],
IEEE80211_CHAN_NO_HT40MINUS);
}
}
return 0;
}
void iwl_legacy_free_channel_map(struct iwl_priv *priv)
{
kfree(priv->channel_info);
priv->channel_count = 0;
}
const struct
iwl_channel_info *iwl_legacy_get_channel_info(const struct iwl_priv *priv,
enum ieee80211_band band, u16 channel)
{
int i;
switch (band) {
case IEEE80211_BAND_5GHZ:
for (i = 14; i < priv->channel_count; i++) {
if (priv->channel_info[i].channel == channel)
return &priv->channel_info[i];
}
break;
case IEEE80211_BAND_2GHZ:
if (channel >= 1 && channel <= 14)
return &priv->channel_info[channel - 1];
break;
default:
BUG();
}
return NULL;
}
