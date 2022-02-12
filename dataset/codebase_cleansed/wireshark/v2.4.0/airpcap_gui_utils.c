void
airpcap_set_toolbar_start_capture(airpcap_if_info_t* if_info)
{
GtkWidget *airpcap_toolbar_label;
GtkWidget *toolbar_channel_cb;
GtkWidget *airpcap_toolbar_channel_lb;
GtkWidget *airpcap_toolbar_channel_offset;
GtkWidget *airpcap_toolbar_channel_offset_lb;
GtkWidget *airpcap_toolbar_button;
GtkWidget *airpcap_toolbar_fcs;
GtkWidget *airpcap_toolbar_fcs_lb;
GtkWidget *airpcap_toolbar_decryption;
GtkWidget *airpcap_toolbar_decryption_lb;
GtkWidget *airpcap_toolbar_keys_button;
gchar *if_label_text;
airpcap_toolbar_label = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_INTERFACE_KEY);
toolbar_channel_cb = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_CHANNEL_KEY);
airpcap_toolbar_channel_lb = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_CHANNEL_LABEL_KEY);
airpcap_toolbar_channel_offset = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_CHANNEL_OFFSET_KEY);
airpcap_toolbar_channel_offset_lb = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_CHANNEL_OFFSET_LABEL_KEY);
airpcap_toolbar_fcs = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_FCS_FILTER_KEY);
airpcap_toolbar_fcs_lb = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_FCS_FILTER_LABEL_KEY);
airpcap_toolbar_button = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_ADVANCED_KEY);
airpcap_toolbar_decryption = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_DECRYPTION_KEY);
airpcap_toolbar_decryption_lb = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_DECRYPTION_LABEL_KEY);
airpcap_toolbar_keys_button = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_KEY_MANAGEMENT_KEY);
if (if_info != NULL)
{
gtk_widget_set_sensitive(wireless_tb,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_label,TRUE);
gtk_widget_set_sensitive(toolbar_channel_cb,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_channel_lb,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_channel_offset,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_channel_offset_lb,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_fcs,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_fcs_lb,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_button,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_button,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_decryption,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_decryption_lb,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_keys_button,FALSE);
g_signal_handlers_block_by_func (airpcap_toolbar_decryption,airpcap_toolbar_encryption_cb, wireless_tb);
if (if_info->DecryptionOn == AIRPCAP_DECRYPTION_ON)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(airpcap_toolbar_decryption),TRUE);
else
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(airpcap_toolbar_decryption),FALSE);
g_signal_handlers_unblock_by_func (airpcap_toolbar_decryption,airpcap_toolbar_encryption_cb, wireless_tb);
if_label_text = g_strdup_printf("Current Wireless Interface: #%s", airpcap_get_if_string_number(if_info));
gtk_label_set_text(GTK_LABEL(airpcap_toolbar_label),if_label_text);
g_free(if_label_text);
change_airpcap_settings = FALSE;
if (if_info->pSupportedChannels != NULL && if_info->numSupportedChannels > 0) {
guint i = 0;
for (; i<if_info->numSupportedChannels; i++) {
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(toolbar_channel_cb), ieee80211_mhz_to_str(if_info->pSupportedChannels[i].Frequency));
}
}
airpcap_update_channel_combo(GTK_WIDGET(toolbar_channel_cb),if_info);
airpcap_update_channel_offset_combo(if_info, if_info->channelInfo.Frequency, airpcap_toolbar_channel_offset, TRUE);
change_airpcap_settings = TRUE;
}
else
{
gtk_widget_set_sensitive(wireless_tb,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_label,FALSE);
gtk_widget_set_sensitive(toolbar_channel_cb,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_channel_lb,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_channel_offset,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_channel_offset_lb,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_fcs,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_fcs_lb,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_button,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_button,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_decryption,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_decryption_lb,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_keys_button,FALSE);
}
}
void
airpcap_set_toolbar_stop_capture(airpcap_if_info_t* if_info)
{
GtkWidget *airpcap_toolbar_crc_filter_combo;
GtkWidget *airpcap_toolbar_label;
GtkWidget *toolbar_channel_cb;
GtkWidget *airpcap_toolbar_channel_lb;
GtkWidget *airpcap_toolbar_channel_offset;
GtkWidget *airpcap_toolbar_channel_offset_lb;
GtkWidget *airpcap_toolbar_button;
GtkWidget *airpcap_toolbar_fcs;
GtkWidget *airpcap_toolbar_fcs_lb;
GtkWidget *airpcap_toolbar_decryption;
GtkWidget *airpcap_toolbar_decryption_lb;
GtkWidget *airpcap_toolbar_keys_button;
gchar *if_label_text;
airpcap_toolbar_crc_filter_combo = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_FCS_FILTER_KEY);
airpcap_toolbar_label = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_INTERFACE_KEY);
toolbar_channel_cb = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_CHANNEL_KEY);
airpcap_toolbar_channel_lb = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_CHANNEL_LABEL_KEY);
airpcap_toolbar_channel_offset = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_CHANNEL_OFFSET_KEY);
airpcap_toolbar_channel_offset_lb = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_CHANNEL_OFFSET_LABEL_KEY);
airpcap_toolbar_fcs = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_FCS_FILTER_KEY);
airpcap_toolbar_fcs_lb = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_FCS_FILTER_LABEL_KEY);
airpcap_toolbar_button = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_ADVANCED_KEY);
airpcap_toolbar_decryption = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_DECRYPTION_KEY);
airpcap_toolbar_decryption_lb = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_DECRYPTION_LABEL_KEY);
airpcap_toolbar_keys_button = (GtkWidget *)g_object_get_data(G_OBJECT(wireless_tb),AIRPCAP_TOOLBAR_KEY_MANAGEMENT_KEY);
if (if_info != NULL)
{
gtk_widget_set_sensitive(wireless_tb,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_label,TRUE);
gtk_widget_set_sensitive(toolbar_channel_cb,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_channel_lb,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_channel_offset,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_channel_offset_lb,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_fcs,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_fcs_lb,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_button,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_crc_filter_combo,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_decryption,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_decryption_lb,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_keys_button,TRUE);
airpcap_validation_type_combo_set_by_type(airpcap_toolbar_crc_filter_combo, if_info->CrcValidationOn);
g_signal_handlers_block_by_func (airpcap_toolbar_decryption,airpcap_toolbar_encryption_cb, wireless_tb);
if (if_info->DecryptionOn == AIRPCAP_DECRYPTION_ON)
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(airpcap_toolbar_decryption),TRUE);
else
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(airpcap_toolbar_decryption),FALSE);
g_signal_handlers_unblock_by_func (airpcap_toolbar_decryption,airpcap_toolbar_encryption_cb, wireless_tb);
if_label_text = g_strdup_printf("Current Wireless Interface: #%s", airpcap_get_if_string_number(if_info));
gtk_label_set_text(GTK_LABEL(airpcap_toolbar_label),if_label_text);
g_free(if_label_text);
change_airpcap_settings = FALSE;
if (if_info->pSupportedChannels != NULL && if_info->numSupportedChannels > 0) {
guint i = 0;
for (; i<if_info->numSupportedChannels; i++) {
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(toolbar_channel_cb), ieee80211_mhz_to_str(if_info->pSupportedChannels[i].Frequency));
}
}
airpcap_update_channel_combo(GTK_WIDGET(toolbar_channel_cb),if_info);
airpcap_update_channel_offset_combo(if_info, if_info->channelInfo.Frequency, airpcap_toolbar_channel_offset, TRUE);
change_airpcap_settings = TRUE;
}
else
{
gtk_widget_set_sensitive(wireless_tb,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_label,FALSE);
gtk_widget_set_sensitive(toolbar_channel_cb,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_channel_lb,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_channel_offset,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_channel_offset_lb,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_fcs,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_fcs_lb,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_button,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_crc_filter_combo,FALSE);
gtk_widget_set_sensitive(airpcap_toolbar_decryption,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_decryption_lb,TRUE);
gtk_widget_set_sensitive(airpcap_toolbar_keys_button,TRUE);
change_airpcap_settings = FALSE;
}
}
static guint
get_wep_key(pref_t *pref, gpointer ud)
{
gchar *key_string = NULL;
guint8 key_type = AIRPDCAP_KEY_TYPE_WEP;
keys_cb_data_t* user_data;
uat_t *uat;
guint i;
char* err = NULL;
uat_wep_key_record_t* wep_keys;
decryption_key_t* new_key;
user_data = (keys_cb_data_t*)ud;
if (g_ascii_strcasecmp(prefs_get_name(pref), "wep_key_table") == 0 && prefs_get_type(pref) == PREF_UAT)
{
uat = prefs_get_uat_value(pref);
if (!uat->loaded)
{
if (!uat_load(uat, &err))
{
g_free(err);
return 1;
}
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
static guint
set_wep_key(pref_t *pref, gpointer ud _U_)
{
keys_cb_data_t* user_data;
uat_t *uat;
gint i;
char* err = NULL;
uat_wep_key_record_t uat_key;
decryption_key_t* new_key;
user_data = (keys_cb_data_t*)ud;
if (g_ascii_strcasecmp(prefs_get_name(pref), "wep_key_table") == 0 && prefs_get_type(pref) == PREF_UAT)
{
uat = prefs_get_uat_value(pref);
if (!uat->loaded)
{
if (!uat_load(uat, &err))
{
g_free(err);
return 1;
}
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
if (!uat_save(uat, &err))
{
g_free(err);
return 1;
}
}
return 0;
}
static gboolean
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
static gboolean
load_wlan_driver_wep_keys(void)
{
keys_cb_data_t* user_data;
wlan_prefs = prefs_find_module("wlan");
user_data = (keys_cb_data_t*)g_malloc(sizeof(keys_cb_data_t));
user_data->list = NULL;
user_data->current_index = 0;
user_data->number_of_keys= 0;
prefs_pref_foreach(wlan_prefs, get_wep_key, (gpointer)user_data);
wlan_prefs->prefs_changed = TRUE;
prefs_apply(wlan_prefs);
write_wlan_driver_wep_keys_to_registry(user_data->list);
g_list_foreach(user_data->list, (GFunc)free_key_string, NULL);
g_list_free(user_data->list);
g_free(user_data);
return TRUE;
}
static gboolean
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
static gchar*
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
static int
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
static int
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
static guint
test_if_on(pref_t *pref, gpointer ud)
{
gboolean *is_on;
is_on = (gboolean*)ud;
if (g_ascii_strncasecmp(prefs_get_name(pref), "enable_decryption", 17) == 0 && prefs_get_gui_type(pref) == PREF_BOOL)
{
*is_on = prefs_get_bool_value(pref, pref_current);
return 1;
}
return 0;
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
static guint
set_on_off(pref_t *pref, gpointer ud)
{
gboolean *is_on;
is_on = (gboolean*)ud;
if (g_ascii_strncasecmp(prefs_get_name(pref), "enable_decryption", 17) == 0 && prefs_get_type(pref) == PREF_BOOL)
{
prefs_set_bool_value(pref, *is_on, pref_current);
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
n = g_list_length(g_airpcap_if_list);
for(i = 0; i < n; i++)
{
curr_if = (airpcap_if_info_t*)g_list_nth_data(g_airpcap_if_list,i);
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
void
airpcap_add_key_to_list(GtkListStore *key_list_store, gchar* type, gchar* key, gchar* ssid)
{
GtkTreeIter iter;
gtk_list_store_insert_with_values(key_list_store , &iter, G_MAXINT,
KL_COL_TYPE, type,
KL_COL_KEY, key,
KL_COL_SSID, ssid,
-1);
}
void
airpcap_fill_key_list(GtkListStore *key_list_store)
{
gchar* s = NULL;
unsigned int i,n;
airpcap_if_info_t* fake_if_info;
GList* wireshark_key_list = NULL;
decryption_key_t* curr_key = NULL;
GtkTreeIter iter;
fake_if_info = airpcap_driver_fake_if_info_new();
wireshark_key_list = get_wireshark_keys();
n = g_list_length(wireshark_key_list);
for(i = 0; i < n; i++)
{
curr_key = (decryption_key_t*)g_list_nth_data(wireshark_key_list,i);
if (curr_key->type == AIRPDCAP_KEY_TYPE_WEP)
{
gtk_list_store_insert_with_values(key_list_store , &iter, G_MAXINT,
KL_COL_TYPE, AIRPCAP_WEP_KEY_STRING,
KL_COL_KEY, curr_key->key->str,
KL_COL_SSID, "",
-1);
}
else if (curr_key->type == AIRPDCAP_KEY_TYPE_WPA_PWD)
{
if (curr_key->ssid != NULL)
{
s = format_uri(NULL, curr_key->ssid, ":");
gtk_list_store_insert_with_values(key_list_store , &iter, G_MAXINT,
KL_COL_TYPE, AIRPCAP_WPA_PWD_KEY_STRING,
KL_COL_KEY, curr_key->key->str,
KL_COL_SSID, s,
-1);
wmem_free(NULL, s);
}
else
{
gtk_list_store_insert_with_values(key_list_store , &iter, G_MAXINT,
KL_COL_TYPE, AIRPCAP_WPA_PWD_KEY_STRING,
KL_COL_KEY, curr_key->key->str,
KL_COL_SSID, "",
-1);
}
}
else if (curr_key->type == AIRPDCAP_KEY_TYPE_WPA_PMK)
{
gtk_list_store_insert_with_values(key_list_store , &iter, G_MAXINT,
KL_COL_TYPE, AIRPCAP_WPA_BIN_KEY_STRING,
KL_COL_KEY, curr_key->key->str,
KL_COL_SSID, "",
-1);
}
}
airpcap_if_info_free(fake_if_info);
return;
}
AirpcapValidationType
airpcap_get_validation_type(const gchar* name)
{
if (!(g_ascii_strcasecmp(AIRPCAP_VALIDATION_TYPE_NAME_ALL,name)))
{
return AIRPCAP_VT_ACCEPT_EVERYTHING;
}
else if (!(g_ascii_strcasecmp(AIRPCAP_VALIDATION_TYPE_NAME_CORRECT,name)))
{
return AIRPCAP_VT_ACCEPT_CORRECT_FRAMES;
}
else if (!(g_ascii_strcasecmp(AIRPCAP_VALIDATION_TYPE_NAME_CORRUPT,name)))
{
return AIRPCAP_VT_ACCEPT_CORRUPT_FRAMES;
}
return AIRPCAP_VT_UNKNOWN;
}
const gchar*
airpcap_get_validation_name(AirpcapValidationType vt)
{
if (vt == AIRPCAP_VT_ACCEPT_EVERYTHING)
{
return AIRPCAP_VALIDATION_TYPE_NAME_ALL;
}
else if (vt == AIRPCAP_VT_ACCEPT_CORRECT_FRAMES)
{
return AIRPCAP_VALIDATION_TYPE_NAME_CORRECT;
}
else if (vt == AIRPCAP_VT_ACCEPT_CORRUPT_FRAMES)
{
return AIRPCAP_VALIDATION_TYPE_NAME_CORRUPT;
}
else if (vt == AIRPCAP_VT_UNKNOWN)
{
return AIRPCAP_VALIDATION_TYPE_NAME_UNKNOWN;
}
return NULL;
}
gint
airpcap_get_validation_combo_entry(AirpcapValidationType vt)
{
switch (vt) {
case AIRPCAP_VT_ACCEPT_CORRECT_FRAMES:
return 1;
break;
case AIRPCAP_VT_ACCEPT_CORRUPT_FRAMES:
return 2;
break;
default:
return 0;
break;
}
}
AirpcapLinkType
airpcap_get_link_type(const gchar* name)
{
if (!(g_ascii_strcasecmp(AIRPCAP_LINK_TYPE_NAME_802_11_ONLY,name))) {
return AIRPCAP_LT_802_11;
}else if (!(g_ascii_strcasecmp(AIRPCAP_LINK_TYPE_NAME_802_11_PLUS_RADIO,name))) {
return AIRPCAP_LT_802_11_PLUS_RADIO;
}else if (!(g_ascii_strcasecmp(AIRPCAP_LINK_TYPE_NAME_802_11_PLUS_PPI,name))) {
return AIRPCAP_LT_802_11_PLUS_PPI;
}else{
return AIRPCAP_LT_UNKNOWN;
}
}
const gchar*
airpcap_get_link_name(AirpcapLinkType lt)
{
if (lt == AIRPCAP_LT_802_11) {
return AIRPCAP_LINK_TYPE_NAME_802_11_ONLY;
}else if (lt == AIRPCAP_LT_802_11_PLUS_RADIO) {
return AIRPCAP_LINK_TYPE_NAME_802_11_PLUS_RADIO;
}else if (lt == AIRPCAP_LT_802_11_PLUS_PPI) {
return AIRPCAP_LINK_TYPE_NAME_802_11_PLUS_PPI;
}else if (lt == AIRPCAP_LT_UNKNOWN) {
return AIRPCAP_LINK_TYPE_NAME_UNKNOWN;
}
return NULL;
}
void
airpcap_validation_type_combo_set_by_type(GtkWidget* c, AirpcapValidationType type)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(c), airpcap_get_validation_combo_entry(type));
}
gchar*
airpcap_get_channel_name(guint n)
{
return g_strdup_printf("%d",n);
}
void
airpcap_channel_combo_set_by_frequency(GtkWidget* cb, guint chan_freq)
{
guint i;
for (i = 0; i < airpcap_if_selected->numSupportedChannels; i++) {
if (airpcap_if_selected->pSupportedChannels[i].Frequency == chan_freq) {
gtk_combo_box_set_active(GTK_COMBO_BOX(cb), i);
break;
}
}
}
static gboolean
airpcap_update_frequency_and_offset(airpcap_if_info_t* if_info)
{
gchar ebuf[AIRPCAP_ERRBUF_SIZE];
PAirpcapHandle ad;
gboolean return_value = FALSE;
if (if_info != NULL) {
ad = airpcap_if_open(if_info->name, ebuf);
if (ad != NULL) {
return_value = airpcap_if_set_device_channel_ex(ad,if_info->channelInfo);
airpcap_if_close(ad);
}
}
return return_value;
}
static void
airpcap_channel_changed_common(GtkWidget *channel_cb, gpointer channel_offset_cb, gboolean set)
{
gint cur_chan_idx;
if (channel_cb && channel_offset_cb && change_airpcap_settings && airpcap_if_active) {
cur_chan_idx = gtk_combo_box_get_active(GTK_COMBO_BOX(channel_cb));
if (cur_chan_idx >= 0 && cur_chan_idx < (gint) airpcap_if_active->numSupportedChannels) {
if (set) {
airpcap_if_active->channelInfo.Frequency = airpcap_if_active->pSupportedChannels[cur_chan_idx].Frequency;
}
airpcap_update_channel_offset_combo(airpcap_if_active,
airpcap_if_active->channelInfo.Frequency,
GTK_WIDGET(channel_offset_cb), set);
}
}
}
void
airpcap_channel_changed_set_cb(GtkWidget *channel_cb, gpointer channel_offset_cb)
{
airpcap_channel_changed_common(channel_cb, channel_offset_cb, TRUE);
}
void
airpcap_channel_changed_noset_cb(GtkWidget *channel_cb, gpointer channel_offset_cb)
{
airpcap_channel_changed_common(channel_cb, channel_offset_cb, FALSE);
}
static int
airpcap_get_selected_channel_offset(GtkWidget *channel_offset_cb) {
int offset;
gchar *off_str;
int retval = 0;
if (channel_offset_cb == NULL || !gtk_widget_get_sensitive(channel_offset_cb)) {
return 0;
}
off_str = gtk_combo_box_text_get_active_text (GTK_COMBO_BOX_TEXT(channel_offset_cb));
if (off_str && (g_ascii_strcasecmp("", off_str)))
{
if (airpcap_if_selected != NULL)
{
if (sscanf(off_str, "%d", &offset) == 1) {
if (offset >= -1 && offset <= 1) {
retval = offset;
}
}
}
}
g_free(off_str);
return retval;
}
void
airpcap_channel_offset_changed_cb(GtkWidget *channel_offset_cb, gpointer data _U_)
{
airpcap_if_selected->channelInfo.ExtChannel = airpcap_get_selected_channel_offset(channel_offset_cb);
airpcap_if_selected->saved = FALSE;
change_airpcap_settings = TRUE;
if (!airpcap_update_frequency_and_offset(airpcap_if_selected)) {
simple_dialog(ESD_TYPE_ERROR,ESD_BTN_OK,
"Unable to set extension channel %d",
airpcap_if_selected->channelInfo.ExtChannel);
}
}
void
airpcap_update_channel_offset_combo(airpcap_if_info_t* if_info, guint chan_freq, GtkWidget *channel_offset_cb, gboolean set)
{
gint current_offset;
gint new_offset;
guint i;
gint active_idx = 0;
gint idx_count = -1;
if (!if_info || airpcap_if_is_any(if_info) || if_info->pSupportedChannels == NULL || if_info->numSupportedChannels < 1) {
gtk_widget_set_sensitive(GTK_WIDGET(channel_offset_cb),FALSE);
gtk_combo_box_set_active(GTK_COMBO_BOX(channel_offset_cb), -1);
return;
}
new_offset = current_offset = if_info->channelInfo.ExtChannel;
while (gtk_tree_model_iter_n_children(gtk_combo_box_get_model(GTK_COMBO_BOX(channel_offset_cb)), NULL) > 0) {
gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT(channel_offset_cb), 0);
}
gtk_widget_set_sensitive(GTK_WIDGET(channel_offset_cb), TRUE);
for (i = 0; i < if_info->numSupportedChannels; i++) {
if (if_info->pSupportedChannels[i].Frequency == chan_freq) {
if (current_offset == -1 && !(if_info->pSupportedChannels[i].Flags & FLAG_CAN_BE_LOW)) {
new_offset = 0;
} else if (current_offset == 1 && !(if_info->pSupportedChannels[i].Flags & FLAG_CAN_BE_HIGH)) {
new_offset = 0;
}
if ((if_info->pSupportedChannels[i].Flags & FLAG_CAN_BE_LOW)) {
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(channel_offset_cb), "-1");
idx_count++;
if (new_offset == -1) {
active_idx = idx_count;
}
}
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(channel_offset_cb), "0");
idx_count++;
if (new_offset == 0) {
active_idx = idx_count;
}
if ((if_info->pSupportedChannels[i].Flags & FLAG_CAN_BE_HIGH)) {
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(channel_offset_cb), "+1");
idx_count++;
if (new_offset == 1) {
active_idx = idx_count;
}
}
break;
}
}
gtk_combo_box_set_active(GTK_COMBO_BOX(channel_offset_cb), active_idx);
if (set) {
change_airpcap_settings = TRUE;
if_info->channelInfo.ExtChannel = new_offset;
if (!airpcap_update_frequency_and_offset(if_info)) {
simple_dialog(ESD_TYPE_ERROR,ESD_BTN_OK,"Adapter failed to be set with the following settings: Frequency - %d Extension Channel - %d", if_info->channelInfo.Frequency, if_info->channelInfo.ExtChannel);
}
}
if (idx_count < 1) {
gtk_widget_set_sensitive(channel_offset_cb, FALSE);
}
}
int
airpcap_if_is_any(airpcap_if_info_t* if_info)
{
if (g_ascii_strcasecmp(if_info->name,AIRPCAP_DEVICE_ANY_EXTRACT_STRING)==0)
return 1;
else
return 0;
}
void
airpcap_update_channel_combo(GtkWidget* channel_cb, airpcap_if_info_t* if_info)
{
if (!if_info || airpcap_if_is_any(if_info) || !airpcap_if_selected)
{
gtk_combo_box_set_active(GTK_COMBO_BOX(channel_cb), -1);
change_airpcap_settings = FALSE;
gtk_widget_set_sensitive(GTK_WIDGET(channel_cb),FALSE);
}
else
{
while (gtk_tree_model_iter_n_children(gtk_combo_box_get_model(GTK_COMBO_BOX(channel_cb)), NULL) > 0) {
gtk_combo_box_text_remove(GTK_COMBO_BOX_TEXT(channel_cb), 0);
}
if (if_info->pSupportedChannels != NULL && if_info->numSupportedChannels > 0) {
guint i;
for (i = 0; i<(if_info->numSupportedChannels); i++) {
gtk_combo_box_text_append_text (GTK_COMBO_BOX_TEXT(channel_cb), ieee80211_mhz_to_str(airpcap_if_selected->pSupportedChannels[i].Frequency));
}
}
airpcap_channel_combo_set_by_frequency(channel_cb, if_info->channelInfo.Frequency);
change_airpcap_settings = TRUE;
gtk_widget_set_sensitive(GTK_WIDGET(channel_cb), TRUE);
}
}
static void
airpcap_add_keys_to_driver_from_list(GtkListStore *key_list_store, airpcap_if_info_t *fake_if_info)
{
GtkTreePath *path;
GtkTreeIter iter;
GtkTreeModel *model = GTK_TREE_MODEL(key_list_store);
guint i, j;
gchar s[3];
PAirpcapKeysCollection KeysCollection;
guint KeysCollectionSize;
guint8 KeyByte;
guint keys_in_list = 0;
gchar *row_type, *row_key;
size_t key_len;
if (fake_if_info == NULL)
return;
keys_in_list = gtk_tree_model_iter_n_children(model, NULL);
KeysCollectionSize = (guint)AirpcapKeysCollectionSize(keys_in_list);
KeysCollection = (PAirpcapKeysCollection)g_malloc(KeysCollectionSize);
KeysCollection->nKeys = keys_in_list;
for(i = 0; i < keys_in_list; i++)
{
path = gtk_tree_path_new_from_indices(i, -1);
gtk_tree_model_get_iter(model, &iter, path);
gtk_tree_path_free(path);
gtk_tree_model_get(model, &iter,
KL_COL_TYPE, &row_type,
KL_COL_KEY, &row_key,
-1);
if (g_ascii_strcasecmp(row_type,AIRPCAP_WEP_KEY_STRING) == 0)
KeysCollection->Keys[i].KeyType = AIRPDCAP_KEY_TYPE_WEP;
else if (g_ascii_strcasecmp(row_type,AIRPCAP_WPA_PWD_KEY_STRING) == 0)
KeysCollection->Keys[i].KeyType = AIRPDCAP_KEY_TYPE_WPA_PWD;
else if (g_ascii_strcasecmp(row_type,AIRPCAP_WPA_BIN_KEY_STRING) == 0)
KeysCollection->Keys[i].KeyType = AIRPDCAP_KEY_TYPE_WPA_PMK;
key_len = strlen(row_key);
KeysCollection->Keys[i].KeyLen = (guint) key_len / 2;
memset(&KeysCollection->Keys[i].KeyData, 0, sizeof(KeysCollection->Keys[i].KeyData));
if (KeysCollection->Keys[i].KeyType == AIRPDCAP_KEY_TYPE_WEP)
{
for(j = 0 ; j < key_len; j += 2)
{
s[0] = row_key[j];
s[1] = row_key[j+1];
s[2] = '\0';
KeyByte = (guint8)strtol(s, NULL, 16);
KeysCollection->Keys[i].KeyData[j / 2] = KeyByte;
}
}
g_free(row_type);
g_free(row_key);
}
if (fake_if_info->keysCollection != NULL)
g_free(fake_if_info->keysCollection);
fake_if_info->keysCollection = KeysCollection;
fake_if_info->keysCollectionSize = KeysCollectionSize;
return;
}
void
airpcap_read_and_save_decryption_keys_from_list_store(GtkListStore* key_list_store, airpcap_if_info_t* info_if, GList* if_list)
{
GtkTreeIter iter;
GtkTreeModel *model = GTK_TREE_MODEL(key_list_store);
gboolean items_left;
gint if_n = 0;
gint i = 0;
airpcap_if_info_t* curr_if = NULL;
airpcap_if_info_t* fake_info_if = NULL;
GList* key_list = NULL;
char* tmp_type = NULL;
char* tmp_key = NULL;
char* tmp_ssid = NULL;
decryption_key_t* tmp_dk=NULL;
for (items_left = gtk_tree_model_get_iter_first (model, &iter);
items_left;
items_left = gtk_tree_model_iter_next (model, &iter)) {
gtk_tree_model_get(model, &iter,
KL_COL_TYPE, &tmp_type,
KL_COL_KEY, &tmp_key,
KL_COL_SSID, &tmp_ssid,
-1);
if (g_ascii_strcasecmp(tmp_type, AIRPCAP_WEP_KEY_STRING) == 0)
{
tmp_dk = (decryption_key_t*)g_malloc(sizeof(decryption_key_t));
tmp_dk->key = g_string_new(tmp_key);
tmp_dk->ssid = NULL;
tmp_dk->type = AIRPDCAP_KEY_TYPE_WEP;
tmp_dk->bits = (guint) tmp_dk->key->len * 4;
key_list = g_list_append(key_list,tmp_dk);
}
else if (g_ascii_strcasecmp(tmp_type, AIRPCAP_WPA_PWD_KEY_STRING) == 0)
{
tmp_dk = (decryption_key_t*)g_malloc(sizeof(decryption_key_t));
tmp_dk->key = g_string_new(tmp_key);
tmp_dk->ssid = g_byte_array_new();
uri_str_to_bytes(tmp_ssid?tmp_ssid:"", tmp_dk->ssid);
tmp_dk->type = AIRPDCAP_KEY_TYPE_WPA_PWD;
tmp_dk->bits = 256;
key_list = g_list_append(key_list,tmp_dk);
}
else if (g_ascii_strcasecmp(tmp_type, AIRPCAP_WPA_BIN_KEY_STRING) == 0)
{
tmp_dk = (decryption_key_t*)g_malloc(sizeof(decryption_key_t));
tmp_dk->key = g_string_new(tmp_key);
tmp_dk->ssid = NULL;
tmp_dk->type = AIRPDCAP_KEY_TYPE_WPA_PMK;
tmp_dk->bits = 256;
key_list = g_list_append(key_list,tmp_dk);
}
g_free(tmp_type);
g_free(tmp_ssid);
}
save_wlan_wireshark_wep_keys(key_list);
if ( (if_list == NULL) || (info_if == NULL) ) return;
fake_info_if = airpcap_driver_fake_if_info_new();
airpcap_add_keys_to_driver_from_list(key_list_store,fake_info_if);
airpcap_save_driver_if_configuration(fake_info_if);
airpcap_if_info_free(fake_info_if);
if_n = g_list_length(if_list);
for(i = 0; i < if_n; i++)
{
curr_if = (airpcap_if_info_t*)g_list_nth_data(if_list,i);
if (curr_if != NULL)
{
airpcap_if_clear_decryption_settings(curr_if);
airpcap_save_selected_if_configuration(curr_if);
}
}
}
gboolean
airpcap_check_decryption_keys(GList* if_list)
{
gint if_n = 0;
gint i = 0;
gint n_adapters_keys = 0;
gint n_driver_keys = 0;
airpcap_if_info_t* curr_if = NULL;
GList* wireshark_key_list;
GList* driver_key_list;
GList* curr_adapter_key_list;
gboolean equals = TRUE;
gboolean adapters_keys_equals=TRUE;
if (if_list == NULL)
return TRUE;
if_n = g_list_length(if_list);
wireshark_key_list = get_wireshark_keys();
driver_key_list = get_airpcap_driver_keys();
n_driver_keys = g_list_length(driver_key_list);
equals &= key_lists_are_equal(wireshark_key_list,driver_key_list);
for(i = 0; i < if_n; i++)
{
curr_if = (airpcap_if_info_t*)g_list_nth_data(if_list,i);
curr_adapter_key_list = get_airpcap_device_keys(curr_if);
n_adapters_keys += g_list_length(curr_adapter_key_list);
adapters_keys_equals &= key_lists_are_equal(wireshark_key_list,curr_adapter_key_list);
}
if (n_adapters_keys != 0)
equals &= adapters_keys_equals;
if (n_driver_keys == 0)
return TRUE;
return equals;
}
void
airpcap_load_decryption_keys(GList* if_list)
{
gint if_n = 0;
gint i = 0;
if (if_list == NULL) return;
if_n = g_list_length(if_list);
for(i = 0; i < if_n; i++)
{
load_wlan_driver_wep_keys();
}
}
void
airpcap_save_decryption_keys(GList* key_list, GList* adapters_list)
{
gint if_n = 0;
gint i = 0;
airpcap_if_info_t* curr_if = NULL;
GList* empty_key_list = NULL;
if ( (key_list == NULL) || (adapters_list == NULL)) return;
if_n = g_list_length(adapters_list);
write_wlan_driver_wep_keys_to_registry(key_list);
for(i = 0; i < if_n; i++)
{
curr_if = (airpcap_if_info_t*)g_list_nth_data(adapters_list,i);
write_wlan_wep_keys_to_registry(curr_if,empty_key_list);
}
save_wlan_wireshark_wep_keys(key_list);
}
void
airpcap_enable_toolbar_widgets(GtkWidget* w, gboolean en)
{
GtkWidget *toolbar_tb,
*if_description_lb,
*toolbar_channel_cb,
*channel_lb,
*channel_offset_cb,
*channel_offset_lb,
*fcs_cb,
*fcs_lb,
*advanced_bt;
if (w == NULL)
return;
toolbar_tb = w;
if_description_lb = (GtkWidget *)g_object_get_data(G_OBJECT(toolbar_tb),AIRPCAP_TOOLBAR_INTERFACE_KEY);
channel_lb = (GtkWidget *)g_object_get_data(G_OBJECT(toolbar_tb),AIRPCAP_TOOLBAR_CHANNEL_LABEL_KEY);
toolbar_channel_cb = (GtkWidget *)g_object_get_data(G_OBJECT(toolbar_tb),AIRPCAP_TOOLBAR_CHANNEL_KEY);
channel_offset_cb = (GtkWidget *)g_object_get_data(G_OBJECT(toolbar_tb),AIRPCAP_TOOLBAR_CHANNEL_OFFSET_KEY);
channel_offset_lb = (GtkWidget *)g_object_get_data(G_OBJECT(toolbar_tb),AIRPCAP_TOOLBAR_CHANNEL_OFFSET_LABEL_KEY);
fcs_lb = (GtkWidget *)g_object_get_data(G_OBJECT(toolbar_tb),AIRPCAP_TOOLBAR_FCS_FILTER_LABEL_KEY);
fcs_cb = (GtkWidget *)g_object_get_data(G_OBJECT(toolbar_tb),AIRPCAP_TOOLBAR_FCS_FILTER_KEY);
advanced_bt = (GtkWidget *)g_object_get_data(G_OBJECT(toolbar_tb),AIRPCAP_TOOLBAR_ADVANCED_KEY);
if (if_description_lb != NULL)
gtk_widget_set_sensitive(if_description_lb,en);
if (channel_lb != NULL)
gtk_widget_set_sensitive(channel_lb,en);
if (toolbar_channel_cb != NULL)
gtk_widget_set_sensitive(toolbar_channel_cb,en);
if (channel_offset_cb != NULL)
gtk_widget_set_sensitive(channel_offset_cb,en);
if (channel_offset_lb != NULL)
gtk_widget_set_sensitive(channel_offset_lb,en);
if (fcs_lb != NULL)
gtk_widget_set_sensitive(fcs_lb,en);
if (fcs_cb != NULL)
gtk_widget_set_sensitive(fcs_cb,en);
if (advanced_bt != NULL)
gtk_widget_set_sensitive(advanced_bt,en);
return;
}
