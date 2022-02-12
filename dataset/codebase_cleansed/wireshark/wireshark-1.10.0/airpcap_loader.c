static guint
get_wep_key(pref_t *pref, gpointer ud)
{
gchar *key_string = NULL;
guint8 key_type = AIRPDCAP_KEY_TYPE_WEP;
keys_cb_data_t* user_data;
uat_t *uat;
guint i;
const char* err = NULL;
uat_wep_key_record_t* wep_keys;
decryption_key_t* new_key;
user_data = (keys_cb_data_t*)ud;
if (g_ascii_strcasecmp(pref->name, "wep_key_table") == 0 && pref->type == PREF_UAT)
{
uat = (uat_t *)pref->varp.uat;
if (!uat->loaded)
{
uat_load(uat, &err);
if (err != NULL)
return 1;
}
for (i = 0, wep_keys = (uat_wep_key_record_t*)*uat->user_ptr; i < *uat->nrows_p; i++, wep_keys++)
{
if (g_ascii_strncasecmp(wep_keys->string, STRING_KEY_TYPE_WEP ":", 4) == 0) {
key_type = AIRPDCAP_KEY_TYPE_WEP;
key_string = (gchar*)wep_keys->string+4;
}
else if (g_ascii_strncasecmp(wep_keys->string, STRING_KEY_TYPE_WPA_PWD ":", 8) == 0) {
key_string = (gchar*)wep_keys->string+8;
key_type = AIRPDCAP_KEY_TYPE_WPA_PWD;
}
else if (g_ascii_strncasecmp(wep_keys->string, STRING_KEY_TYPE_WPA_PSK ":", 8) == 0) {
key_string = (gchar*)wep_keys->string+8;
key_type = AIRPDCAP_KEY_TYPE_WPA_PSK;
}
else {
key_type = wep_keys->key;
key_string = (gchar*)wep_keys->string;
}
new_key = parse_key_string(key_string, key_type);
if (new_key != NULL)
{
user_data->list = g_list_append(user_data->list,new_key);
user_data->number_of_keys++;
user_data->current_index++;
}
}
}
return 0;
}
gboolean
wep_key_is_valid(char* key)
{
GString *new_key_string;
guint i=0;
if (key == NULL)
return FALSE;
new_key_string = g_string_new(key);
if ( ((new_key_string->len) > WEP_KEY_MAX_CHAR_SIZE) || ((new_key_string->len) < 2))
{
g_string_free(new_key_string,FALSE);
return FALSE;
}
if ((new_key_string->len % 2) != 0)
{
g_string_free(new_key_string,FALSE);
return FALSE;
}
for(i = 0; i < new_key_string->len; i++)
{
if (!g_ascii_isxdigit(new_key_string->str[i]))
{
g_string_free(new_key_string,FALSE);
return FALSE;
}
}
g_string_free(new_key_string,FALSE);
return TRUE;
}
static guint
set_wep_key(pref_t *pref, gpointer ud _U_)
{
keys_cb_data_t* user_data;
uat_t *uat;
gint i;
const char* err = NULL;
uat_wep_key_record_t uat_key;
decryption_key_t* new_key;
user_data = (keys_cb_data_t*)ud;
if (g_ascii_strcasecmp(pref->name, "wep_key_table") == 0 && pref->type == PREF_UAT)
{
uat = (uat_t *)pref->varp.uat;
if (!uat->loaded)
{
uat_load(uat, &err);
if (err != NULL)
return 1;
uat->loaded = 1;
}
uat_clear(uat);
for (i = 0; i < user_data->number_of_keys; i++)
{
new_key = (decryption_key_t*)g_list_nth_data(user_data->list,i);
uat_key.string = get_key_string(new_key);
uat_key.key = new_key->type;
uat_add_record(uat, &uat_key, TRUE);
}
uat_save(uat, &err);
if (err != NULL)
return 1;
}
return 0;
}
gboolean
load_wlan_driver_wep_keys(void)
{
keys_cb_data_t* user_data;
guint i;
wlan_prefs = prefs_find_module("wlan");
user_data = (keys_cb_data_t*)g_malloc(sizeof(keys_cb_data_t));
user_data->list = NULL;
user_data->current_index = 0;
user_data->number_of_keys= 0;
prefs_pref_foreach(wlan_prefs, get_wep_key, (gpointer)user_data);
wlan_prefs->prefs_changed = TRUE;
prefs_apply(wlan_prefs);
write_wlan_driver_wep_keys_to_registry(user_data->list);
for(i=0;i<g_list_length(user_data->list);i++)
{
g_free(g_list_nth(user_data->list,i)->data);
}
g_list_free(user_data->list);
g_free(user_data);
return TRUE;
}
gboolean
write_wlan_wep_keys_to_registry(airpcap_if_info_t* info_if, GList* key_list)
{
guint i,j;
GString *new_key;
gchar s[3];
PAirpcapKeysCollection KeysCollection;
guint KeysCollectionSize;
guint8 KeyByte;
guint keys_in_list = 0;
decryption_key_t* key_item = NULL;
keys_in_list = g_list_length(key_list);
KeysCollectionSize = (guint)AirpcapKeysCollectionSize(keys_in_list);
KeysCollection = (PAirpcapKeysCollection)g_malloc(KeysCollectionSize);
if (!KeysCollection)
{
return FALSE;
}
KeysCollection->nKeys = keys_in_list;
for(i = 0; i < keys_in_list; i++)
{
KeysCollection->Keys[i].KeyType = AIRPDCAP_KEY_TYPE_WEP;
key_item = (decryption_key_t*)g_list_nth_data(key_list,i);
new_key = g_string_new(key_item->key->str);
KeysCollection->Keys[i].KeyLen = (guint) new_key->len / 2;
memset(&KeysCollection->Keys[i].KeyData, 0, sizeof(KeysCollection->Keys[i].KeyData));
for(j = 0 ; j < new_key->len; j += 2)
{
s[0] = new_key->str[j];
s[1] = new_key->str[j+1];
s[2] = '\0';
KeyByte = (guint8)strtol(s, NULL, 16);
KeysCollection->Keys[i].KeyData[j / 2] = KeyByte;
}
g_string_free(new_key,TRUE);
}
if (info_if->keysCollection != NULL)
g_free(info_if->keysCollection);
info_if->keysCollection = KeysCollection;
info_if->keysCollectionSize = KeysCollectionSize;
info_if->saved = FALSE;
airpcap_save_selected_if_configuration(info_if);
return TRUE;
}
gboolean
write_wlan_driver_wep_keys_to_registry(GList* key_list)
{
guint i,j,k,n,y;
GString *new_key;
gchar s[3];
PAirpcapKeysCollection KeysCollection;
guint KeysCollectionSize;
guint8 KeyByte;
guint keys_in_list = 0;
decryption_key_t* key_item = NULL;
airpcap_if_info_t* fake_info_if = NULL;
fake_info_if = airpcap_driver_fake_if_info_new();
if (fake_info_if == NULL)
return FALSE;
n = g_list_length(key_list);
for(k = 0; k < n; k++ )
if (((decryption_key_t*)g_list_nth_data(key_list,k))->type == AIRPDCAP_KEY_TYPE_WEP)
keys_in_list++;
KeysCollectionSize = (guint)AirpcapKeysCollectionSize(keys_in_list);
KeysCollection = (PAirpcapKeysCollection)g_malloc(KeysCollectionSize);
if (!KeysCollection)
{
return FALSE;
}
KeysCollection->nKeys = keys_in_list;
y = 0;
for(i = 0; i < n; i++)
{
key_item = (decryption_key_t*)g_list_nth_data(key_list,i);
if (key_item->type == AIRPDCAP_KEY_TYPE_WEP)
{
KeysCollection->Keys[y].KeyType = AIRPDCAP_KEY_TYPE_WEP;
new_key = g_string_new(key_item->key->str);
KeysCollection->Keys[y].KeyLen = (guint) new_key->len / 2;
memset(&KeysCollection->Keys[y].KeyData, 0, sizeof(KeysCollection->Keys[y].KeyData));
for(j = 0 ; j < new_key->len; j += 2)
{
s[0] = new_key->str[j];
s[1] = new_key->str[j+1];
s[2] = '\0';
KeyByte = (guint8)strtol(s, NULL, 16);
KeysCollection->Keys[y].KeyData[j / 2] = KeyByte;
}
y++;
g_string_free(new_key,TRUE);
}
else if (key_item->type == AIRPDCAP_KEY_TYPE_WPA_PWD)
{
}
else if (key_item->type == AIRPDCAP_KEY_TYPE_WPA_PMK)
{
}
}
if (fake_info_if->keysCollection != NULL)
g_free(fake_info_if->keysCollection);
fake_info_if->keysCollection = KeysCollection;
fake_info_if->keysCollectionSize = KeysCollectionSize;
fake_info_if->saved = FALSE;
airpcap_save_driver_if_configuration(fake_info_if);
airpcap_if_info_free(fake_info_if);
return TRUE;
}
int
save_wlan_driver_wep_keys(void)
{
GList* key_list = NULL;
char* tmp_key = NULL;
guint keys_in_list,i;
keys_cb_data_t* user_data;
airpcap_if_info_t* fake_info_if = NULL;
fake_info_if = airpcap_driver_fake_if_info_new();
if (fake_info_if == NULL)
return 0;
wlan_prefs = prefs_find_module("wlan");
user_data = (keys_cb_data_t*)g_malloc(sizeof(keys_cb_data_t));
if (fake_info_if->keysCollectionSize != 0)
keys_in_list = AirpcapKeysCollectionSizeToKeyCount(fake_info_if->keysCollectionSize);
else
keys_in_list = 0;
for(i=0; i<keys_in_list; i++)
{
if (fake_info_if->keysCollection->Keys[i].KeyType == AIRPDCAP_KEY_TYPE_WEP)
{
tmp_key = airpcap_get_key_string(fake_info_if->keysCollection->Keys[i]);
key_list = g_list_append(key_list,g_strdup(tmp_key));
g_free(tmp_key);
}
}
keys_in_list = g_list_length(key_list);
user_data->list = key_list;
user_data->current_index = 0;
user_data->number_of_keys= keys_in_list;
wlan_prefs = prefs_find_module("wlan");
prefs_pref_foreach(wlan_prefs, set_wep_key, (gpointer)user_data);
wlan_prefs->prefs_changed = TRUE;
prefs_apply(wlan_prefs);
for(i=0;i<g_list_length(user_data->list);i++)
{
g_free(g_list_nth(user_data->list,i)->data);
}
g_list_free(user_data->list);
g_free(user_data);
airpcap_if_info_free(fake_info_if);
return keys_in_list;
}
int
save_wlan_wireshark_wep_keys(GList* key_ls)
{
GList* key_list = NULL;
guint keys_in_list,i;
keys_cb_data_t* user_data;
decryption_key_t* tmp_dk;
wlan_prefs = prefs_find_module("wlan");
user_data = (keys_cb_data_t*)g_malloc(sizeof(keys_cb_data_t));
keys_in_list = g_list_length(key_ls);
key_list = key_ls;
user_data->list = key_list;
user_data->current_index = 0;
user_data->number_of_keys= keys_in_list;
wlan_prefs = prefs_find_module("wlan");
prefs_pref_foreach(wlan_prefs, set_wep_key, (gpointer)user_data);
wlan_prefs->prefs_changed = TRUE;
prefs_apply(wlan_prefs);
for(i=0;i<g_list_length(user_data->list);i++)
{
tmp_dk = (decryption_key_t*)g_list_nth(user_data->list,i)->data;
g_string_free(tmp_dk->key,TRUE);
if (tmp_dk->ssid != NULL) g_byte_array_free(tmp_dk->ssid,TRUE);
}
g_list_free(user_data->list);
g_free(user_data);
return keys_in_list;
}
static gchar *
cant_get_airpcap_if_list_error_message(const char *err_str)
{
return g_strdup_printf("Can't get list of Wireless interfaces: %s", err_str);
}
gboolean
airpcap_if_store_cur_config_as_adapter_default(PAirpcapHandle ah)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapStoreCurConfigAsAdapterDefault(ah);
}
PAirpcapHandle
airpcap_if_open(gchar * name, gchar * err)
{
if (!AirpcapLoaded) return NULL;
if (name == NULL) return NULL;
return g_PAirpcapOpen(name,err);
}
void
airpcap_if_close(PAirpcapHandle handle)
{
if (!AirpcapLoaded) return;
g_PAirpcapClose(handle);
}
int
airpcap_get_dll_state(void)
{
return AirpcapVersion;
}
gboolean
airpcap_if_turn_led_on(PAirpcapHandle AdapterHandle, guint LedNumber)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapTurnLedOn(AdapterHandle,LedNumber);
}
gboolean
airpcap_if_turn_led_off(PAirpcapHandle AdapterHandle, guint LedNumber)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapTurnLedOff(AdapterHandle,LedNumber);
}
gboolean
airpcap_if_get_device_channel(PAirpcapHandle ah, guint * ch)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapGetDeviceChannel(ah,ch);
}
gboolean
airpcap_if_get_device_supported_channels(PAirpcapHandle ah, AirpcapChannelInfo **cInfo, guint * nInfo)
{
if (!AirpcapLoaded) return FALSE;
if (airpcap_get_dll_state() == AIRPCAP_DLL_OLD) {
*nInfo = num_legacy_channels;
*cInfo = (AirpcapChannelInfo*)&LegacyChannels;
return TRUE;
} else if (airpcap_get_dll_state() == AIRPCAP_DLL_OK) {
return g_PAirpcapGetDeviceSupportedChannels(ah, cInfo, nInfo);
}
return FALSE;
}
Dot11Channel*
airpcap_if_get_device_supported_channels_array(PAirpcapHandle ah, guint * pNumSupportedChannels)
{
AirpcapChannelInfo *chanInfo;
guint i=0, j=0, numInfo = 0;
if (!AirpcapLoaded)
return NULL;
if (airpcap_if_get_device_supported_channels(ah, &chanInfo, &numInfo) == FALSE)
return NULL;
numSupportedChannels = 0;
if (numInfo == 0)
return NULL;
pSupportedChannels = (Dot11Channel *)g_malloc(numInfo * (sizeof *pSupportedChannels));
for (i = 0; i < numInfo; i++)
{
guint supportedChannel = G_MAXUINT;
for (j = 0; j < numSupportedChannels; j++)
{
if (pSupportedChannels[j].Frequency == chanInfo[i].Frequency)
{
supportedChannel = j;
break;
}
}
if (supportedChannel == G_MAXUINT)
{
pSupportedChannels[numSupportedChannels].Frequency = chanInfo[i].Frequency;
switch(chanInfo[i].ExtChannel)
{
case -1:
pSupportedChannels[numSupportedChannels].Flags = FLAG_CAN_BE_LOW;
break;
case +1:
pSupportedChannels[numSupportedChannels].Flags = FLAG_CAN_BE_HIGH;
break;
case 0:
default:
pSupportedChannels[numSupportedChannels].Flags = 0;
}
pSupportedChannels[numSupportedChannels].Flags |=
FREQ_IS_BG(pSupportedChannels[numSupportedChannels].Frequency) ?
FLAG_IS_BG_CHANNEL : FLAG_IS_A_CHANNEL;
pSupportedChannels[numSupportedChannels].Channel =
ieee80211_mhz_to_chan(pSupportedChannels[numSupportedChannels].Frequency);
numSupportedChannels++;
}
else
{
switch(chanInfo[i].ExtChannel)
{
case -1:
pSupportedChannels[supportedChannel].Flags |= FLAG_CAN_BE_LOW;
break;
case +1:
pSupportedChannels[supportedChannel].Flags |= FLAG_CAN_BE_HIGH;
break;
case 0:
default:
break;
}
}
}
if (numSupportedChannels < 1)
return NULL;
for (i = 0 ; i < numSupportedChannels - 1; i++)
{
for (j = i + 1; j < numSupportedChannels; j++)
{
if (pSupportedChannels[i].Frequency > pSupportedChannels[j].Frequency)
{
Dot11Channel temp = pSupportedChannels[i];
pSupportedChannels[i] = pSupportedChannels[j];
pSupportedChannels[j] = temp;
}
}
}
*pNumSupportedChannels = numSupportedChannels;
return pSupportedChannels;
}
gboolean
airpcap_if_set_device_channel(PAirpcapHandle ah, guint ch)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapSetDeviceChannel(ah,ch);
}
gboolean
airpcap_if_set_device_channel_ex(PAirpcapHandle ah, AirpcapChannelInfo ChannelInfo)
{
if (!AirpcapLoaded) return FALSE;
if (airpcap_get_dll_state() == AIRPCAP_DLL_OLD){
gint channel = 0;
channel = ieee80211_mhz_to_chan(ChannelInfo.Frequency);
if (channel < 0){
return FALSE;
} else {
return airpcap_if_set_device_channel(ah, channel);
}
} else if (airpcap_get_dll_state() == AIRPCAP_DLL_OK){
return g_PAirpcapSetDeviceChannelEx (ah, ChannelInfo);
}
return FALSE;
}
gboolean
airpcap_if_get_device_channel_ex(PAirpcapHandle ah, PAirpcapChannelInfo pChannelInfo)
{
if (!AirpcapLoaded) return FALSE;
pChannelInfo->Frequency = 0;
pChannelInfo->ExtChannel = 0;
pChannelInfo->Reserved[0] = 0;
pChannelInfo->Reserved[1] = 0;
pChannelInfo->Reserved[2] = 0;
if (airpcap_get_dll_state() == AIRPCAP_DLL_OLD){
guint channel = 0;
guint chan_freq = 0;
if (!airpcap_if_get_device_channel(ah, &channel)) return FALSE;
chan_freq = ieee80211_chan_to_mhz(channel, TRUE);
if (chan_freq == 0) return FALSE;
pChannelInfo->Frequency = chan_freq;
return TRUE;
} else if (airpcap_get_dll_state() == AIRPCAP_DLL_OK){
return g_PAirpcapGetDeviceChannelEx (ah, pChannelInfo);
}
return FALSE;
}
gboolean
airpcap_if_get_link_type(PAirpcapHandle ah, PAirpcapLinkType lt)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapGetLinkType(ah,lt);
}
gboolean
airpcap_if_set_link_type(PAirpcapHandle ah, AirpcapLinkType lt)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapSetLinkType(ah,lt);
}
gboolean
airpcap_if_get_fcs_presence(PAirpcapHandle ah, gboolean * fcs)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapGetFcsPresence(ah,fcs);
}
gboolean
airpcap_if_set_fcs_presence(PAirpcapHandle ah, gboolean fcs)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapSetFcsPresence(ah,fcs);
}
gboolean
airpcap_if_get_decryption_state(PAirpcapHandle ah, PAirpcapDecryptionState PEnable)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapGetDecryptionState(ah,PEnable);
}
gboolean
airpcap_if_set_decryption_state(PAirpcapHandle ah, AirpcapDecryptionState Enable)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapSetDecryptionState(ah,Enable);
}
gboolean
airpcap_if_get_driver_decryption_state(PAirpcapHandle ah, PAirpcapDecryptionState PEnable)
{
if (!AirpcapLoaded || (g_PAirpcapGetDriverDecryptionState==NULL)) return FALSE;
return g_PAirpcapGetDriverDecryptionState(ah,PEnable);
}
gboolean
airpcap_if_set_driver_decryption_state(PAirpcapHandle ah, AirpcapDecryptionState Enable)
{
if (!AirpcapLoaded || (g_PAirpcapSetDriverDecryptionState==NULL)) return FALSE;
return g_PAirpcapSetDriverDecryptionState(ah,Enable);
}
gboolean
airpcap_if_get_fcs_validation(PAirpcapHandle ah, PAirpcapValidationType val)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapGetFcsValidation(ah,val);
}
gboolean
airpcap_if_set_fcs_validation(PAirpcapHandle ah, AirpcapValidationType val)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapSetFcsValidation(ah,val);
}
gboolean
airpcap_if_set_device_keys(PAirpcapHandle AdapterHandle, PAirpcapKeysCollection KeysCollection)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapSetDeviceKeys(AdapterHandle,KeysCollection);
}
gboolean
airpcap_if_get_device_keys(PAirpcapHandle AdapterHandle, PAirpcapKeysCollection KeysCollection, guint * PKeysCollectionSize)
{
if (!AirpcapLoaded) return FALSE;
return g_PAirpcapGetDeviceKeys(AdapterHandle,KeysCollection,PKeysCollectionSize);
}
gboolean
airpcap_if_set_driver_keys(PAirpcapHandle AdapterHandle, PAirpcapKeysCollection KeysCollection)
{
if (!AirpcapLoaded || (g_PAirpcapSetDriverKeys==NULL)) return FALSE;
return g_PAirpcapSetDriverKeys(AdapterHandle,KeysCollection);
}
gboolean
airpcap_if_get_driver_keys(PAirpcapHandle AdapterHandle, PAirpcapKeysCollection KeysCollection, guint * PKeysCollectionSize)
{
if (!AirpcapLoaded || (g_PAirpcapGetDriverKeys==NULL)) return FALSE;
return g_PAirpcapGetDriverKeys(AdapterHandle,KeysCollection,PKeysCollectionSize);
}
airpcap_if_info_t *
airpcap_if_info_new(char *name, char *description)
{
PAirpcapHandle ad;
gchar ebuf[AIRPCAP_ERRBUF_SIZE];
airpcap_if_info_t *if_info = NULL;
ad = airpcap_if_open(name, ebuf);
if (ad)
{
if_info = (airpcap_if_info_t *)g_malloc0(sizeof (airpcap_if_info_t));
if_info->name = g_strdup(name);
if (description == NULL){
if_info->description = NULL;
}else{
if_info->description = g_strdup(description);
}
if_info->ip_addr = NULL;
if_info->loopback = FALSE;
airpcap_if_get_fcs_validation(ad,&(if_info->CrcValidationOn));
airpcap_if_get_fcs_presence(ad,&(if_info->IsFcsPresent));
airpcap_if_get_link_type(ad,&(if_info->linkType));
airpcap_if_get_device_channel_ex(ad,&(if_info->channelInfo));
if_info->pSupportedChannels = airpcap_if_get_device_supported_channels_array(ad, &(if_info->numSupportedChannels));
airpcap_if_turn_led_on(ad, 0);
airpcap_if_get_decryption_state(ad, &(if_info->DecryptionOn));
if_info->led = TRUE;
if_info->blinking = FALSE;
if_info->saved = TRUE;
if (airpcap_if_load_keys(ad,if_info))
{
airpcap_if_close(ad);
}
}
return if_info;
}
airpcap_if_info_t*
airpcap_driver_fake_if_info_new(void)
{
PAirpcapHandle ad;
gchar ebuf[AIRPCAP_ERRBUF_SIZE];
airpcap_if_info_t *if_info = NULL;
airpcap_if_info_t *fake_if_info = NULL;
if (airpcap_if_list == NULL)
return NULL;
if_info = (airpcap_if_info_t *)g_list_nth_data(airpcap_if_list,0);
if (if_info == NULL)
return NULL;
ad = airpcap_if_open(if_info->name, ebuf);
if (ad)
{
fake_if_info = (airpcap_if_info_t *)g_malloc(sizeof (airpcap_if_info_t));
fake_if_info->name = g_strdup(if_info->name);
fake_if_info->description = g_strdup(if_info->description);
fake_if_info->loopback = FALSE;
fake_if_info->ip_addr = NULL;
airpcap_if_get_driver_decryption_state(ad, &(fake_if_info->DecryptionOn));
airpcap_if_get_fcs_validation(ad,&(fake_if_info->CrcValidationOn));
airpcap_if_get_fcs_presence(ad,&(fake_if_info->IsFcsPresent));
airpcap_if_get_link_type(ad,&(fake_if_info->linkType));
airpcap_if_get_device_channel_ex(ad,&(fake_if_info->channelInfo));
airpcap_if_turn_led_on(ad, 0);
fake_if_info->led = TRUE;
fake_if_info->blinking = FALSE;
fake_if_info->saved = TRUE;
if (airpcap_if_load_driver_keys(ad,fake_if_info))
{
airpcap_if_close(ad);
}
}
return fake_if_info;
}
void
airpcap_if_info_print(airpcap_if_info_t* if_info)
{
guint i;
if (if_info == NULL)
{
g_print("\nWARNING : AirPcap Interface pointer is NULL!\n");
return;
}
g_print("\n----------------- AirPcap Interface \n");
g_print(" NAME: %s\n",if_info->name);
g_print(" DESCRIPTION: %s\n",if_info->description);
g_print(" BLINKING: %s\n",if_info->blinking ? "TRUE" : "FALSE");
g_print(" channelInfo.Frequency: %u\n",if_info->channelInfo.Frequency);
g_print(" channelInfo.ExtChannel: %d\n",if_info->channelInfo.ExtChannel);
g_print(" CRCVALIDATION: %s\n",if_info->CrcValidationOn ? "ON" : "OFF");
g_print(" DECRYPTION: %s\n",if_info->DecryptionOn ? "ON" : "OFF");
g_print(" IP ADDR: %s\n",if_info->ip_addr!=NULL ? "NOT NULL" : "NULL");
g_print(" FCSPRESENT: %s\n",if_info->IsFcsPresent ? "TRUE" : "FALSE");
g_print(" KEYSCOLLECTION: %s\n",if_info->keysCollection!=NULL ? "NOT NULL" : "NULL");
g_print(" KEYSCOLLECTIONSIZE: %u\n",if_info->keysCollectionSize);
g_print(" LED: %s\n",if_info->led ? "ON" : "OFF");
g_print(" LINKTYPE: %d\n",if_info->linkType);
g_print(" LOOPBACK: %s\n",if_info->loopback ? "YES" : "NO");
g_print(" (GTK) TAG: %d\n",if_info->tag);
g_print("SUPPORTED CHANNELS POINTER: %p\n",if_info->pSupportedChannels);
g_print(" NUM SUPPORTED CHANNELS: %u\n",if_info->numSupportedChannels);
for(i=0; i<(if_info->numSupportedChannels); i++){
g_print("\n SUPPORTED CHANNEL #%u\n",i+1);
g_print(" CHANNEL: %u\n",if_info->pSupportedChannels[i].Channel);
g_print(" FREQUENCY: %u\n",if_info->pSupportedChannels[i].Frequency);
g_print(" FLAGS: %u\n",if_info->pSupportedChannels[i].Flags);
}
g_print("\n\n");
}
gboolean
airpcap_if_load_keys(PAirpcapHandle ad, airpcap_if_info_t *if_info)
{
if (!if_info) return FALSE;
if_info->keysCollectionSize = 0;
if_info->keysCollection = NULL;
if (!airpcap_if_get_device_keys(ad, NULL, &(if_info->keysCollectionSize)))
{
if (if_info->keysCollectionSize == 0)
{
if_info->keysCollection = NULL;
airpcap_if_close(ad);
return FALSE;
}
if_info->keysCollection = (PAirpcapKeysCollection)g_malloc(if_info->keysCollectionSize);
if (!if_info->keysCollection)
{
if_info->keysCollectionSize = 0;
if_info->keysCollection = NULL;
airpcap_if_close(ad);
return FALSE;
}
airpcap_if_get_device_keys(ad, if_info->keysCollection, &(if_info->keysCollectionSize));
return TRUE;
}
airpcap_if_close(ad);
return FALSE;
}
gboolean
airpcap_if_load_driver_keys(PAirpcapHandle ad, airpcap_if_info_t *if_info)
{
if_info->keysCollectionSize = 0;
if_info->keysCollection = NULL;
if (!airpcap_if_get_driver_keys(ad, NULL, &(if_info->keysCollectionSize)))
{
if (if_info->keysCollectionSize == 0)
{
if_info->keysCollection = NULL;
airpcap_if_close(ad);
return FALSE;
}
if_info->keysCollection = (PAirpcapKeysCollection)g_malloc(if_info->keysCollectionSize);
if (!if_info->keysCollection)
{
if_info->keysCollectionSize = 0;
if_info->keysCollection = NULL;
airpcap_if_close(ad);
return FALSE;
}
airpcap_if_get_driver_keys(ad, if_info->keysCollection, &(if_info->keysCollectionSize));
return TRUE;
}
airpcap_if_close(ad);
return FALSE;
}
void
airpcap_if_save_keys(PAirpcapHandle ad, airpcap_if_info_t *if_info)
{
if (!if_info || !AirpcapLoaded) return;
if (if_info->keysCollection != NULL)
g_PAirpcapSetDeviceKeys(ad,if_info->keysCollection);
}
void
airpcap_if_save_driver_keys(PAirpcapHandle ad, airpcap_if_info_t *if_info)
{
if (if_info->keysCollection != NULL)
airpcap_if_set_driver_keys(ad,if_info->keysCollection);
}
static void
free_airpcap_if_cb(gpointer data, gpointer user_data _U_)
{
airpcap_if_info_t *if_info = (airpcap_if_info_t *)data;
if (NULL == if_info)
return;
if (if_info->name != NULL)
g_free(if_info->name);
if (if_info->description != NULL)
g_free(if_info->description);
if (if_info->keysCollection != NULL)
{
g_free(if_info->keysCollection);
if_info->keysCollection = NULL;
}
if (if_info->ip_addr != NULL)
g_slist_free(if_info->ip_addr);
g_free(if_info);
}
void
free_airpcap_interface_list(GList *if_list)
{
g_list_foreach(if_list, free_airpcap_if_cb, NULL);
g_list_free(if_list);
if_list = NULL;
}
GList*
get_airpcap_interface_list(int *err, char **err_str)
{
GList *il = NULL;
airpcap_if_info_t *if_info;
int n_adapts;
AirpcapDeviceDescription *devsList, *adListEntry;
char errbuf[AIRPCAP_ERRBUF_SIZE];
*err = 0;
if (!AirpcapLoaded)
{
*err = AIRPCAP_NOT_LOADED;
return il;
}
if (!g_PAirpcapGetDeviceList(&devsList, errbuf))
{
*err = CANT_GET_AIRPCAP_INTERFACE_LIST;
if (err_str != NULL)
*err_str = cant_get_airpcap_if_list_error_message(errbuf);
return il;
}
adListEntry = devsList;
n_adapts = 0;
while(adListEntry)
{
n_adapts++;
adListEntry = adListEntry->next;
}
if (n_adapts == 0)
{
g_PAirpcapFreeDeviceList(devsList);
*err = NO_AIRPCAP_INTERFACES_FOUND;
if (err_str != NULL)
*err_str = NULL;
return il;
}
adListEntry = devsList;
while(adListEntry)
{
if_info = airpcap_if_info_new(adListEntry->Name, adListEntry->Description);
if (if_info != NULL){
il = g_list_append(il, if_info);
}
adListEntry = adListEntry->next;
}
g_PAirpcapFreeDeviceList(devsList);
return il;
}
airpcap_if_info_t* get_airpcap_if_from_name(GList* if_list, const gchar* name)
{
GList* curr;
airpcap_if_info_t* if_info;
for (curr = g_list_first(if_list); curr; curr = g_list_next(curr)) {
if_info = (airpcap_if_info_t *)curr->data;
if (if_info && (g_ascii_strcasecmp(if_info->name, name) == 0)) {
return (if_info);
}
}
return (NULL);
}
gchar*
airpcap_get_key_string(AirpcapKey key)
{
unsigned int j = 0;
gchar *dst,*src;
dst = NULL;
src = NULL;
if (key.KeyType == AIRPDCAP_KEY_TYPE_WEP)
{
if (key.KeyLen != 0)
{
dst = (gchar*)g_malloc(sizeof(gchar)*WEP_KEY_MAX_CHAR_SIZE + 1);
dst[0]='\0';
for(j = 0; j < key.KeyLen; j++)
{
src = g_strdup_printf("%.2x", key.KeyData[j]);
g_strlcat(dst, src, WEP_KEY_MAX_CHAR_SIZE+1);
}
g_free(src);
}
}
else if (key.KeyType == AIRPDCAP_KEY_TYPE_WPA_PWD)
{
}
else if (key.KeyType == AIRPDCAP_KEY_TYPE_WPA_PMK)
{
}
else
{
}
return dst;
}
void
airpcap_if_clear_decryption_settings(airpcap_if_info_t* info_if)
{
if (info_if != NULL)
{
if (info_if->keysCollection != NULL)
{
g_free(info_if->keysCollection);
info_if->keysCollection = NULL;
}
info_if->keysCollectionSize = 0;
info_if->DecryptionOn = AIRPCAP_DECRYPTION_OFF;
info_if->saved = FALSE;
}
}
gchar*
airpcap_get_if_string_number(airpcap_if_info_t* if_info)
{
gchar* number;
guint n;
int a;
a = sscanf(if_info->name,AIRPCAP_DEVICE_NUMBER_EXTRACT_STRING,&n);
if (a == 0)
{
if (g_ascii_strcasecmp(if_info->name,AIRPCAP_DEVICE_ANY_EXTRACT_STRING)!=0)
number = g_strdup_printf("??");
else
number = g_strdup_printf(AIRPCAP_CHANNEL_ANY_NAME);
}
else
{
number = g_strdup_printf("%.2u",n);
}
return number;
}
gchar*
airpcap_get_if_string_number_from_description(gchar* description)
{
gchar* number;
gchar* pointer;
number = (gchar*)g_malloc(sizeof(gchar)*3);
pointer = g_strrstr(description,"#\0");
number[0] = *(pointer+1);
number[1] = *(pointer+2);
number[2] = '\0';
return number;
}
airpcap_if_info_t*
airpcap_get_default_if(GList* airpcap_if_list_p)
{
airpcap_if_info_t* if_info = NULL;
if ((prefs.capture_device != NULL) && (*prefs.capture_device != '\0'))
{
if_info = get_airpcap_if_from_name(airpcap_if_list_p,
get_if_name(prefs.capture_device));
}
return if_info;
}
void
airpcap_load_selected_if_configuration(airpcap_if_info_t* if_info)
{
gchar ebuf[AIRPCAP_ERRBUF_SIZE];
PAirpcapHandle ad;
if (if_info != NULL)
{
ad = airpcap_if_open(if_info->name, ebuf);
if (ad)
{
if (if_info->blinking)
{
if (!(if_info->led)) airpcap_if_turn_led_on(ad, 0);
}
airpcap_if_get_device_channel_ex(ad,&(if_info->channelInfo));
airpcap_if_get_fcs_validation(ad,&(if_info->CrcValidationOn));
airpcap_if_get_fcs_presence(ad,&(if_info->IsFcsPresent));
airpcap_if_get_link_type(ad,&(if_info->linkType));
airpcap_if_get_decryption_state(ad, &(if_info->DecryptionOn));
if (airpcap_if_load_keys(ad,if_info))
airpcap_if_close(ad);
if_info->saved = TRUE;
}
else
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, " Error in opening adapter for %s",if_info->description);
}
}
}
void
airpcap_save_selected_if_configuration(airpcap_if_info_t* if_info)
{
gchar ebuf[AIRPCAP_ERRBUF_SIZE];
PAirpcapHandle ad;
if (if_info != NULL)
{
ad = airpcap_if_open(if_info->name, ebuf);
if (ad)
{
if (if_info->blinking)
{
if (!(if_info->led)) airpcap_if_turn_led_on(ad, 0);
}
airpcap_if_set_device_channel_ex(ad,if_info->channelInfo);
airpcap_if_set_fcs_validation(ad,if_info->CrcValidationOn);
airpcap_if_set_fcs_presence(ad,if_info->IsFcsPresent);
airpcap_if_set_link_type(ad,if_info->linkType);
airpcap_if_set_decryption_state(ad, if_info->DecryptionOn);
airpcap_if_save_keys(ad,if_info);
if (!airpcap_if_store_cur_config_as_adapter_default(ad))
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "Cannot save Wireless configuration!!!\nRemember that in order to store the configuration in the registry you have to:\n\n- Close all the airpcap-based applications.\n- Be sure to have administrative privileges.");
if_info->saved = FALSE;
airpcap_if_close(ad);
return;
}
if_info->saved = TRUE;
airpcap_if_close(ad);
}
else
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, " Error in opening adapter for %s",if_info->description);
}
}
}
void
airpcap_save_driver_if_configuration(airpcap_if_info_t* fake_if_info)
{
gchar ebuf[AIRPCAP_ERRBUF_SIZE];
PAirpcapHandle ad;
if (fake_if_info != NULL)
{
ad = airpcap_if_open(fake_if_info->name, ebuf);
if (ad)
{
airpcap_if_set_driver_decryption_state(ad, fake_if_info->DecryptionOn);
airpcap_if_save_driver_keys(ad,fake_if_info);
airpcap_if_close(ad);
}
else
{
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, " Error in opening adapter for %s",fake_if_info->description);
}
}
return;
}
void
print_key_list(GList* key_list)
{
gint n,i;
decryption_key_t* tmp;
if (key_list == NULL)
{
g_print("\n\n******* KEY LIST NULL *******\n\n");
return;
}
n = g_list_length(key_list);
g_print("\n\n********* KEY LIST **********\n\n");
g_print("NUMBER OF KEYS IN LIST : %d\n\n",n);
for(i =0; i < n; i++)
{
g_print("[%d] :\n",i+1);
tmp = (decryption_key_t*)(g_list_nth_data(key_list,i));
g_print("KEY : %s\n",tmp->key->str);
g_print("BITS: %d\n",tmp->bits);
if (tmp->type == AIRPDCAP_KEY_TYPE_WEP)
g_print("TYPE: %s\n",AIRPCAP_WEP_KEY_STRING);
else if (tmp->type == AIRPDCAP_KEY_TYPE_WPA_PWD)
g_print("TYPE: %s\n",AIRPCAP_WPA_PWD_KEY_STRING);
else if (tmp->type == AIRPDCAP_KEY_TYPE_WPA_PMK)
g_print("TYPE: %s\n",AIRPCAP_WPA_BIN_KEY_STRING);
else
g_print("TYPE: %s\n","???");
g_print("SSID: %s\n",(tmp->ssid != NULL) ?
format_text((guchar *)tmp->ssid->data, tmp->ssid->len) : "---");
g_print("\n");
}
g_print("\n*****************************\n\n");
}
GList *
get_airpcap_device_keys(airpcap_if_info_t* info_if)
{
char* tmp_key = NULL;
guint i,keys_in_list = 0;
decryption_key_t *new_key = NULL;
GList *key_list = NULL;
if (info_if->keysCollectionSize != 0)
keys_in_list = AirpcapKeysCollectionSizeToKeyCount(info_if->keysCollectionSize);
else
keys_in_list = 0;
for(i=0; i<keys_in_list; i++)
{
if (info_if->keysCollection->Keys[i].KeyType == AIRPDCAP_KEY_TYPE_WEP)
{
new_key = (decryption_key_t*)g_malloc(sizeof(decryption_key_t));
tmp_key = airpcap_get_key_string(info_if->keysCollection->Keys[i]);
new_key->key = g_string_new(tmp_key);
g_free(tmp_key);
new_key->bits = (guint) new_key->key->len *4;
new_key->ssid = NULL;
new_key->type = info_if->keysCollection->Keys[i].KeyType;
key_list = g_list_append(key_list,(gpointer)new_key);
}
else if (info_if->keysCollection->Keys[i].KeyType == AIRPDCAP_KEY_TYPE_WPA_PWD)
{
}
else if (info_if->keysCollection->Keys[i].KeyType == AIRPDCAP_KEY_TYPE_WPA_PMK)
{
}
}
return key_list;
}
GList *
get_airpcap_driver_keys(void)
{
char *tmp_key = NULL;
guint i,keys_in_list = 0;
decryption_key_t *new_key = NULL;
GList *key_list = NULL;
airpcap_if_info_t* fake_info_if = NULL;
fake_info_if = airpcap_driver_fake_if_info_new();
if (fake_info_if == NULL)
return NULL;
if (fake_info_if->keysCollectionSize != 0)
keys_in_list = AirpcapKeysCollectionSizeToKeyCount(fake_info_if->keysCollectionSize);
else
keys_in_list = 0;
for(i=0; i<keys_in_list; i++)
{
if (fake_info_if->keysCollection->Keys[i].KeyType == AIRPDCAP_KEY_TYPE_WEP)
{
new_key = (decryption_key_t*)g_malloc(sizeof(decryption_key_t));
tmp_key = airpcap_get_key_string(fake_info_if->keysCollection->Keys[i]);
new_key->key = g_string_new(tmp_key);
if (tmp_key != NULL) g_free(tmp_key);
new_key->bits = (guint) new_key->key->len *4;
new_key->ssid = NULL;
new_key->type = fake_info_if->keysCollection->Keys[i].KeyType;
key_list = g_list_append(key_list,(gpointer)new_key);
}
else if (fake_info_if->keysCollection->Keys[i].KeyType == AIRPDCAP_KEY_TYPE_WPA_PWD)
{
}
else if (fake_info_if->keysCollection->Keys[i].KeyType == AIRPDCAP_KEY_TYPE_WPA_PMK)
{
}
}
airpcap_if_info_free(fake_info_if);
return key_list;
}
GList *
get_wireshark_keys(void)
{
keys_cb_data_t *wep_user_data = NULL;
GList *final_list = NULL;
GList *wep_final_list = NULL;
wlan_prefs = prefs_find_module("wlan");
wep_user_data = (keys_cb_data_t*)g_malloc(sizeof(keys_cb_data_t));
wep_user_data->list = NULL;
wep_user_data->current_index = 0;
wep_user_data->number_of_keys= 0;
prefs_pref_foreach(wlan_prefs, get_wep_key, (gpointer)wep_user_data);
wep_final_list = wep_user_data->list;
final_list = wep_final_list;
g_free(wep_user_data);
return final_list;
}
GList *
merge_key_list(GList* list1, GList* list2)
{
guint n1=0,n2=0;
guint i;
decryption_key_t *dk1=NULL,
*dk2=NULL,
*new_dk=NULL;
GList* merged_list = NULL;
if ( (list1 == NULL) && (list2 == NULL) )
return NULL;
if (list1 == NULL)
{
n2 = g_list_length(list2);
for(i=0;i<n2;i++)
{
new_dk = (decryption_key_t*)g_malloc(sizeof(decryption_key_t));
dk2 = (decryption_key_t *)g_list_nth_data(list2,i);
new_dk->bits = dk2->bits;
new_dk->type = dk2->type;
new_dk->key = g_string_new(dk2->key->str);
new_dk->ssid = byte_array_dup(dk2->ssid);
if (g_list_length(merged_list) < MAX_ENCRYPTION_KEYS)
merged_list = g_list_append(merged_list,(gpointer)new_dk);
}
}
else if (list2 == NULL)
{
n1 = g_list_length(list1);
for(i=0;i<n1;i++)
{
new_dk = (decryption_key_t*)g_malloc(sizeof(decryption_key_t));
dk1 = (decryption_key_t*)g_list_nth_data(list1,i);
new_dk->bits = dk1->bits;
new_dk->type = dk1->type;
new_dk->key = g_string_new(dk1->key->str);
new_dk->ssid = byte_array_dup(dk1->ssid);
if (g_list_length(merged_list) < MAX_ENCRYPTION_KEYS)
merged_list = g_list_append(merged_list,(gpointer)new_dk);
}
}
else
{
n1 = g_list_length(list1);
n2 = g_list_length(list2);
for(i=0;i<n1;i++)
{
new_dk = (decryption_key_t*)g_malloc(sizeof(decryption_key_t));
dk1 = (decryption_key_t *)g_list_nth_data(list1,i);
new_dk->bits = dk1->bits;
new_dk->type = dk1->type;
new_dk->key = g_string_new(dk1->key->str);
new_dk->ssid = byte_array_dup(dk1->ssid);
if (g_list_length(merged_list) < MAX_ENCRYPTION_KEYS)
merged_list = g_list_append(merged_list,(gpointer)new_dk);
}
for(i=0;i<n2;i++)
{
dk2 = (decryption_key_t *)g_list_nth_data(list2,i);
if (!key_is_in_list(dk2,merged_list))
{
new_dk = (decryption_key_t*)g_malloc(sizeof(decryption_key_t));
new_dk->bits = dk2->bits;
new_dk->type = dk2->type;
new_dk->key = g_string_new(dk2->key->str);
new_dk->ssid = byte_array_dup(dk2->ssid);
if (g_list_length(merged_list) < MAX_ENCRYPTION_KEYS)
merged_list = g_list_append(merged_list,(gpointer)new_dk);
}
}
}
return merged_list;
}
void
free_key_list(GList *list)
{
guint i,n;
decryption_key_t *curr_key;
if (list == NULL)
return;
n = g_list_length(list);
for(i = 0; i < n; i++)
{
curr_key = (decryption_key_t*)g_list_nth_data(list,i);
if (curr_key->key != NULL)
g_string_free(curr_key->key, TRUE);
if (curr_key->ssid != NULL)
g_byte_array_free(curr_key->ssid, TRUE);
g_free(curr_key);
curr_key = NULL;
}
g_list_free(list);
return;
}
gboolean
key_is_in_list(decryption_key_t *dk,GList *list)
{
guint i,n;
decryption_key_t *curr_key = NULL;
gboolean found = FALSE;
if ( (list == NULL) || (dk == NULL) )
return FALSE;
n = g_list_length(list);
if (n < 1)
return FALSE;
for(i = 0; i < n; i++)
{
curr_key = (decryption_key_t*)g_list_nth_data(list,i);
if (keys_are_equals(dk,curr_key))
found = TRUE;
}
return found;
}
gboolean
keys_are_equals(decryption_key_t *k1,decryption_key_t *k2)
{
if ((k1==NULL) || (k2==NULL))
return FALSE;
if (g_string_equal(k1->key,k2->key) &&
(k1->bits == k2->bits) &&
(k1->type == k2->type))
{
if ((k1->ssid == NULL) && (k2->ssid == NULL))
return TRUE;
return byte_array_equal(k1->ssid,k2->ssid);
}
return FALSE;
}
gboolean
key_lists_are_equal(GList* list1, GList* list2)
{
guint n1 = 0,n2=0;
guint wep_n1 = 0,wep_n2=0;
GList *wep_list1 = NULL;
GList *wep_list2 = NULL;
guint i;
decryption_key_t *dk1=NULL,*dk2=NULL;
n1 = g_list_length(list1);
n2 = g_list_length(list2);
for(i=0;i<n1;i++)
{
dk1=(decryption_key_t*)g_list_nth_data(list1,i);
if (dk1->type == AIRPDCAP_KEY_TYPE_WEP)
{
wep_list1 = g_list_append(wep_list1,(gpointer)dk1);
wep_n1++;
}
}
for(i=0;i<n2;i++)
{
dk2=(decryption_key_t*)g_list_nth_data(list2,i);
if (dk2->type == AIRPDCAP_KEY_TYPE_WEP)
{
wep_list2 = g_list_append(wep_list2,(gpointer)dk2);
wep_n2++;
}
}
if (wep_n1 != wep_n2) return FALSE;
n2 = wep_n2;
for(i=0;i<n2;i++)
{
dk2=(decryption_key_t*)g_list_nth_data(wep_list2,i);
if (!key_is_in_list(dk2,wep_list1)) return FALSE;
}
return TRUE;
}
static guint
test_if_on(pref_t *pref, gpointer ud)
{
gboolean *is_on;
gboolean number;
is_on = (gboolean*)ud;
if (g_ascii_strncasecmp(pref->name, "enable_decryption", 17) == 0 && pref->type == PREF_BOOL)
{
number = *pref->varp.boolp;
if (number) *is_on = TRUE;
else *is_on = FALSE;
return 1;
}
return 0;
}
gboolean
wireshark_decryption_on(void)
{
gboolean is_on;
wlan_prefs = prefs_find_module("wlan");
prefs_pref_foreach(wlan_prefs, test_if_on, (gpointer)&is_on);
return is_on;
}
gboolean
airpcap_decryption_on(void)
{
gboolean is_on = FALSE;
airpcap_if_info_t* fake_if_info = NULL;
fake_if_info = airpcap_driver_fake_if_info_new();
if (fake_if_info != NULL)
{
if (fake_if_info->DecryptionOn == AIRPCAP_DECRYPTION_ON)
is_on = TRUE;
else if (fake_if_info->DecryptionOn == AIRPCAP_DECRYPTION_OFF)
is_on = FALSE;
}
airpcap_if_info_free(fake_if_info);
return is_on;
}
void
airpcap_if_info_free(airpcap_if_info_t *if_info)
{
if (if_info != NULL)
{
if (if_info->name != NULL)
g_free(if_info->name);
if (if_info->description != NULL)
g_free(if_info->description);
if (if_info->keysCollection != NULL)
{
g_free(if_info->keysCollection);
if_info->keysCollection = NULL;
}
if (if_info->ip_addr != NULL)
{
g_slist_free(if_info->ip_addr);
if_info->ip_addr = NULL;
}
if (if_info != NULL)
{
g_free(if_info);
if_info = NULL;
}
}
}
static guint
set_on_off(pref_t *pref, gpointer ud)
{
gboolean *is_on;
is_on = (gboolean*)ud;
if (g_ascii_strncasecmp(pref->name, "enable_decryption", 17) == 0 && pref->type == PREF_BOOL)
{
if (*is_on)
*pref->varp.boolp = TRUE;
else
*pref->varp.boolp = FALSE;
return 1;
}
return 0;
}
void
set_wireshark_decryption(gboolean on_off)
{
gboolean is_on;
is_on = on_off;
wlan_prefs = prefs_find_module("wlan");
prefs_pref_foreach(wlan_prefs, set_on_off, (gpointer)&is_on);
wlan_prefs->prefs_changed = TRUE;
prefs_apply(wlan_prefs);
}
gboolean
set_airpcap_decryption(gboolean on_off)
{
gchar ebuf[AIRPCAP_ERRBUF_SIZE];
PAirpcapHandle ad,ad_driver;
gboolean success = TRUE;
gint n = 0;
gint i = 0;
airpcap_if_info_t* curr_if = NULL;
airpcap_if_info_t* fake_if_info = NULL;
fake_if_info = airpcap_driver_fake_if_info_new();
if (fake_if_info == NULL)
return TRUE;
ad_driver = airpcap_if_open(fake_if_info->name, ebuf);
if (ad_driver)
{
if (on_off)
airpcap_if_set_driver_decryption_state(ad_driver,AIRPCAP_DECRYPTION_ON);
else
airpcap_if_set_driver_decryption_state(ad_driver,AIRPCAP_DECRYPTION_OFF);
airpcap_if_close(ad_driver);
}
airpcap_if_info_free(fake_if_info);
n = g_list_length(airpcap_if_list);
for(i = 0; i < n; i++)
{
curr_if = (airpcap_if_info_t*)g_list_nth_data(airpcap_if_list,i);
if (curr_if != NULL)
{
ad = airpcap_if_open(curr_if->name, ebuf);
if (ad)
{
curr_if->DecryptionOn = AIRPCAP_DECRYPTION_OFF;
airpcap_if_set_decryption_state(ad,curr_if->DecryptionOn);
if (!airpcap_if_store_cur_config_as_adapter_default(ad))
{
success = FALSE;
}
airpcap_if_close(ad);
}
}
}
return success;
}
int load_airpcap(void)
{
#ifdef _WIN32
gboolean base_functions = TRUE;
gboolean eleven_n_functions = TRUE;
if ((AirpcapLib = ws_load_library("airpcap.dll")) == NULL)
{
AirpcapVersion = AIRPCAP_DLL_NOT_FOUND;
return AirpcapVersion;
}
else
{
if ((g_PAirpcapGetLastError = (AirpcapGetLastErrorHandler) GetProcAddress(AirpcapLib, "AirpcapGetLastError")) == NULL) base_functions = FALSE;
if ((g_PAirpcapGetDeviceList = (AirpcapGetDeviceListHandler) GetProcAddress(AirpcapLib, "AirpcapGetDeviceList")) == NULL) base_functions = FALSE;
if ((g_PAirpcapFreeDeviceList = (AirpcapFreeDeviceListHandler) GetProcAddress(AirpcapLib, "AirpcapFreeDeviceList")) == NULL) base_functions = FALSE;
if ((g_PAirpcapOpen = (AirpcapOpenHandler) GetProcAddress(AirpcapLib, "AirpcapOpen")) == NULL) base_functions = FALSE;
if ((g_PAirpcapClose = (AirpcapCloseHandler) GetProcAddress(AirpcapLib, "AirpcapClose")) == NULL) base_functions = FALSE;
if ((g_PAirpcapGetLinkType = (AirpcapGetLinkTypeHandler) GetProcAddress(AirpcapLib, "AirpcapGetLinkType")) == NULL) base_functions = FALSE;
if ((g_PAirpcapSetLinkType = (AirpcapSetLinkTypeHandler) GetProcAddress(AirpcapLib, "AirpcapSetLinkType")) == NULL) base_functions = FALSE;
if ((g_PAirpcapSetKernelBuffer = (AirpcapSetKernelBufferHandler) GetProcAddress(AirpcapLib, "AirpcapSetKernelBuffer")) == NULL) base_functions = FALSE;
if ((g_PAirpcapSetFilter = (AirpcapSetFilterHandler) GetProcAddress(AirpcapLib, "AirpcapSetFilter")) == NULL) base_functions = FALSE;
if ((g_PAirpcapGetMacAddress = (AirpcapGetMacAddressHandler) GetProcAddress(AirpcapLib, "AirpcapGetMacAddress")) == NULL) base_functions = FALSE;
if ((g_PAirpcapSetMinToCopy = (AirpcapSetMinToCopyHandler) GetProcAddress(AirpcapLib, "AirpcapSetMinToCopy")) == NULL) base_functions = FALSE;
if ((g_PAirpcapGetReadEvent = (AirpcapGetReadEventHandler) GetProcAddress(AirpcapLib, "AirpcapGetReadEvent")) == NULL) base_functions = FALSE;
if ((g_PAirpcapRead = (AirpcapReadHandler) GetProcAddress(AirpcapLib, "AirpcapRead")) == NULL) base_functions = FALSE;
if ((g_PAirpcapGetStats = (AirpcapGetStatsHandler) GetProcAddress(AirpcapLib, "AirpcapGetStats")) == NULL) base_functions = FALSE;
if ((g_PAirpcapTurnLedOn = (AirpcapTurnLedOnHandler) GetProcAddress(AirpcapLib, "AirpcapTurnLedOn")) == NULL) base_functions = FALSE;
if ((g_PAirpcapTurnLedOff = (AirpcapTurnLedOffHandler) GetProcAddress(AirpcapLib, "AirpcapTurnLedOff")) == NULL) base_functions = FALSE;
if ((g_PAirpcapGetDeviceChannel = (AirpcapGetDeviceChannelHandler) GetProcAddress(AirpcapLib, "AirpcapGetDeviceChannel")) == NULL) base_functions = FALSE;
if ((g_PAirpcapSetDeviceChannel = (AirpcapSetDeviceChannelHandler) GetProcAddress(AirpcapLib, "AirpcapSetDeviceChannel")) == NULL) base_functions = FALSE;
if ((g_PAirpcapGetFcsPresence = (AirpcapGetFcsPresenceHandler) GetProcAddress(AirpcapLib, "AirpcapGetFcsPresence")) == NULL) base_functions = FALSE;
if ((g_PAirpcapSetFcsPresence = (AirpcapSetFcsPresenceHandler) GetProcAddress(AirpcapLib, "AirpcapSetFcsPresence")) == NULL) base_functions = FALSE;
if ((g_PAirpcapGetFcsValidation = (AirpcapGetFcsValidationHandler) GetProcAddress(AirpcapLib, "AirpcapGetFcsValidation")) == NULL) base_functions = FALSE;
if ((g_PAirpcapSetFcsValidation = (AirpcapSetFcsValidationHandler) GetProcAddress(AirpcapLib, "AirpcapSetFcsValidation")) == NULL) base_functions = FALSE;
if ((g_PAirpcapGetDeviceKeys = (AirpcapGetDeviceKeysHandler) GetProcAddress(AirpcapLib, "AirpcapGetDeviceKeys")) == NULL) base_functions = FALSE;
if ((g_PAirpcapSetDeviceKeys = (AirpcapSetDeviceKeysHandler) GetProcAddress(AirpcapLib, "AirpcapSetDeviceKeys")) == NULL) base_functions = FALSE;
if ((g_PAirpcapGetDecryptionState = (AirpcapGetDecryptionStateHandler) GetProcAddress(AirpcapLib, "AirpcapGetDecryptionState")) == NULL) base_functions = FALSE;
if ((g_PAirpcapSetDecryptionState = (AirpcapSetDecryptionStateHandler) GetProcAddress(AirpcapLib, "AirpcapSetDecryptionState")) == NULL) base_functions = FALSE;
if ((g_PAirpcapStoreCurConfigAsAdapterDefault = (AirpcapStoreCurConfigAsAdapterDefaultHandler) GetProcAddress(AirpcapLib, "AirpcapStoreCurConfigAsAdapterDefault")) == NULL) base_functions = FALSE;
if ((g_PAirpcapGetVersion = (AirpcapGetVersionHandler) GetProcAddress(AirpcapLib, "AirpcapGetVersion")) == NULL) base_functions = FALSE;
if ((g_PAirpcapGetDriverDecryptionState = (AirpcapGetDriverDecryptionStateHandler) GetProcAddress(AirpcapLib, "AirpcapGetDriverDecryptionState")) == NULL) base_functions = FALSE;
if ((g_PAirpcapSetDriverDecryptionState = (AirpcapSetDriverDecryptionStateHandler) GetProcAddress(AirpcapLib, "AirpcapSetDriverDecryptionState")) == NULL) base_functions = FALSE;
if ((g_PAirpcapGetDriverKeys = (AirpcapGetDriverKeysHandler) GetProcAddress(AirpcapLib, "AirpcapGetDriverKeys")) == NULL) base_functions = FALSE;
if ((g_PAirpcapSetDriverKeys = (AirpcapSetDriverKeysHandler) GetProcAddress(AirpcapLib, "AirpcapSetDriverKeys")) == NULL) base_functions = FALSE;
if ((g_PAirpcapSetDeviceChannelEx = (AirpcapSetDeviceChannelExHandler) GetProcAddress(AirpcapLib, "AirpcapSetDeviceChannelEx")) == NULL) eleven_n_functions = FALSE;
if ((g_PAirpcapGetDeviceChannelEx = (AirpcapGetDeviceChannelExHandler) GetProcAddress(AirpcapLib, "AirpcapGetDeviceChannelEx")) == NULL) eleven_n_functions = FALSE;
if ((g_PAirpcapGetDeviceSupportedChannels = (AirpcapGetDeviceSupportedChannelsHandler) GetProcAddress(AirpcapLib, "AirpcapGetDeviceSupportedChannels")) == NULL) eleven_n_functions = FALSE;
if (base_functions && eleven_n_functions){
AirpcapLoaded = TRUE;
AirpcapVersion = AIRPCAP_DLL_OK;
} else if (base_functions){
AirpcapLoaded = TRUE;
AirpcapVersion = AIRPCAP_DLL_OLD;
return AIRPCAP_DLL_OK;
}else{
AirpcapLoaded = FALSE;
AirpcapVersion = AIRPCAP_DLL_ERROR;
}
}
return AirpcapVersion;
#else
return AIRPCAP_DLL_NOT_FOUND;
#endif
}
void
get_compiled_airpcap_version(GString *str)
{
g_string_append(str, "with AirPcap");
}
void
get_runtime_airpcap_version(GString *str)
{
guint vmaj, vmin, vrev, build;
if (AirpcapLoaded == FALSE) {
g_string_append(str, "without AirPcap");
return;
}
g_PAirpcapGetVersion(&vmaj, &vmin, &vrev, &build);
g_string_append_printf(str, "with AirPcap %d.%d.%d build %d", vmaj, vmin,
vrev, build);
}
