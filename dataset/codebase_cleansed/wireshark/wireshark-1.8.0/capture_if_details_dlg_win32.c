static void
supported_list(LPADAPTER adapter)
{
unsigned char values[10000];
int length;
g_warning("supported_list_unhandled");
length = sizeof(values);
if (wpcap_packet_request(adapter, OID_GEN_SUPPORTED_LIST, FALSE , values, &length)) {
guint32 *value = (guint32 *) values;
while (length>=4) {
printf("OID: 0x%08X %s\n", *value, val_to_str(*value, oid_vals, "unknown"));
value++;
length-=4;
}
}
}
static gboolean
supported_query_oid(LPADAPTER adapter, guint32 oid)
{
unsigned char values[10000];
int length;
length = sizeof(values);
if (wpcap_packet_request(adapter, OID_GEN_SUPPORTED_LIST, FALSE , values, &length)) {
guint32 *value = (guint32 *) values;
while (length>=4) {
if(*value == oid) {
return TRUE;
}
value++;
length-=4;
}
}
return FALSE;
}
static void
add_row_to_table(GtkWidget *list, guint *row, gchar *title, const gchar *value, gboolean sensitive)
{
GtkWidget *label;
gchar *indent;
if(strlen(value) != 0) {
indent = g_strdup_printf(" %s", title);
} else {
indent = g_strdup(title);
}
label = gtk_label_new(indent);
g_free(indent);
gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
gtk_widget_set_sensitive(label, sensitive);
gtk_table_attach(GTK_TABLE(list), label, 0, 1, *row, *row+1, GTK_EXPAND | GTK_FILL, 0, 0,0);
label = gtk_label_new(value);
gtk_misc_set_alignment(GTK_MISC(label), 0.0, 0.5);
gtk_widget_set_sensitive(label, sensitive);
gtk_table_attach(GTK_TABLE(list), label, 1, 2, *row, *row+1, GTK_EXPAND | GTK_FILL, 0, 0,0);
*row = *row + 1;
}
static void
add_string_to_table_sensitive(GtkWidget *list, guint *row, gchar *title, gchar *value, gboolean sensitive)
{
add_row_to_table(list, row, title, value, sensitive);
}
static void
add_string_to_table(GtkWidget *list, guint *row, gchar *title, const gchar *value)
{
add_row_to_table(list, row, title, value, TRUE);
}
static void
ssid_details(GtkWidget *table, guint *row, struct ndis_essid *ssid_in) {
struct ndis_essid ssid[2];
ssid[0] = *ssid_in;
g_assert(ssid->length <= NDIS_ESSID_MAX_SIZE);
if(ssid->length != 0) {
ssid->essid[ssid->length] = '\0';
add_string_to_table(table, row, "SSID (Service Set IDentifier)", ssid->essid);
} else {
add_string_to_table(table, row, "SSID (Service Set IDentifier)", "(currently not associated with an SSID)");
}
}
static GString *
rates_details(unsigned char *values, int length) {
int i;
GString *Rates;
float float_value;
int int_value;
Rates = g_string_new("");
if(length != 0) {
i = 0;
while(length--) {
if(values[i]) {
if(i != 0) {
g_string_append(Rates, "/");
}
float_value = ((float) (values[i] & 0x7F)) / 2;
int_value = (int)float_value;
if(float_value == (float)int_value) {
g_string_append_printf(Rates, "%.0f", float_value);
} else {
g_string_append_printf(Rates, "%.1f", float_value);
}
}
i++;
}
Rates = g_string_append(Rates, " MBits/s");
} else {
Rates = g_string_append(Rates, "-");
}
return Rates;
}
static void
hex(unsigned char *p, int len) {
int i = 0;
while(len) {
g_warning("%u: 0x%x (%u) '%c'", i, *p, *p,
isprint(*p) ? *p : '.');
i++;
p++;
len--;
}
}
static void
capture_if_details_802_11_bssid_list(GtkWidget *main_vb, struct ndis_bssid_list *bssid_list)
{
struct ndis_ssid_item *bssid_item;
unsigned char mac[6];
const gchar *manuf_name;
GString *Rates;
if(bssid_list->num_items != 0) {
char *titles[] = { "SSID", "MAC", "Vendor", "Privacy", "RSSI" , "Network Type" , "Infra. Mode" , "Ch." , "Rates", "Country" };
GtkWidget *list;
gboolean privacy_required;
gboolean privacy_wpa;
gboolean privacy_wpa2;
gchar ssid_buff[DETAILS_STR_MAX];
gchar mac_buff[DETAILS_STR_MAX];
gchar vendor_buff[DETAILS_STR_MAX];
gchar privacy_buff[DETAILS_STR_MAX];
gchar rssi_buff[DETAILS_STR_MAX];
gchar nettype_buff[DETAILS_STR_MAX];
gchar infra_buff[DETAILS_STR_MAX];
gchar freq_buff[DETAILS_STR_MAX];
gchar country_buff[DETAILS_STR_MAX] = "";
list = simple_list_new(10, titles);
gtk_box_pack_start(GTK_BOX(main_vb), list, TRUE , TRUE , 0 );
bssid_item = &bssid_list->items[0];
while(bssid_list->num_items--) {
privacy_required = FALSE;
privacy_wpa = FALSE;
privacy_wpa2 = FALSE;
if(bssid_item->ssid.length > DETAILS_STR_MAX-1) {
bssid_item->ssid.length = DETAILS_STR_MAX-1;
}
memcpy(ssid_buff, bssid_item->ssid.essid, bssid_item->ssid.length);
ssid_buff[bssid_item->ssid.length] = '\0';
memcpy(mac, &bssid_item->mac, sizeof(mac));
g_snprintf(mac_buff, DETAILS_STR_MAX, "%02X:%02X:%02X:%02X:%02X:%02X",
mac[0], mac[1], mac[2],
mac[3], mac[4], mac[5]);
manuf_name = get_manuf_name_if_known(mac);
if(manuf_name != NULL) {
g_strlcpy(vendor_buff, manuf_name, DETAILS_STR_MAX);
} else {
vendor_buff[0] = '\0';
}
Rates = rates_details(bssid_item->rates, NDIS_MAX_RATES_EX);
g_snprintf(rssi_buff, DETAILS_STR_MAX, "%d dBm", bssid_item->rssi);
if(bssid_item->privacy) {
privacy_required = TRUE;
}
g_snprintf(nettype_buff, sizeof(nettype_buff), "%s",
val_to_str(bssid_item->net_type, win32_802_11_network_type_vals, "(0x%x)"));
g_snprintf(infra_buff, sizeof(infra_buff), "%s",
val_to_str(bssid_item->mode, win32_802_11_infra_mode_vals, "(0x%x)"));
g_snprintf(freq_buff, sizeof(freq_buff), "%s",
val_to_str(bssid_item->config.ds_config, win32_802_11_channel_vals, "(%u kHz)"));
{
int len = bssid_item->ie_length;
unsigned char *iep = bssid_item->ies;
unsigned char id;
unsigned el_len;
NDIS_802_11_FIXED_IEs *fixed_ies;
#ifdef DEBUG_IE
const gchar *manuf_name;
gchar string_buff[DETAILS_STR_MAX];
#endif
fixed_ies = (NDIS_802_11_FIXED_IEs *) iep;
#if 0
UCHAR Timestamp[8];
USHORT BeaconInterval;
USHORT Capabilities;
} NDIS_802_11_FIXED_IEs, *PNDIS_802_11_FIXED_IEs;
#endif
iep += sizeof(NDIS_802_11_FIXED_IEs);
len = bssid_item->ie_length - sizeof(NDIS_802_11_FIXED_IEs);
while(len >= 2) {
id = *iep;
iep++;
el_len = *iep;
iep++;
len-=2;
#ifdef DEBUG_IE
g_warning("ID: %s (%u) Len: %u",
val_to_str(id, ie_id_vals, "0x%x"), id, el_len);
#endif
switch(id) {
case(IE_ID_COUNTRY):
if(el_len >= 6)
g_snprintf(country_buff, sizeof(country_buff), "%c%c: Ch: %u-%u Max: %ddBm",
iep[0], iep[1], iep[3], iep[4], iep[5]);
break;
case(IE_ID_WPA2):
privacy_wpa2 = TRUE;
break;
case(IE_ID_VENDOR_SPECIFIC):
privacy_wpa = TRUE;
#ifdef DEBUG_IE
manuf_name = get_manuf_name_if_known(iep);
if(manuf_name != NULL) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%02X:%02X:%02X (%s) Type: %02X",
*(iep), *(iep+1), *(iep+2), manuf_name, *(iep+3));
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "%02X:%02X:%02X Type: %02X",
*(iep), *(iep+1), *(iep+2), *(iep+3));
}
g_warning("%s", string_buff);
iep += 4;
el_len-= 4;
len -= 4;
g_warning("WPA IE: %u", id);
hex(iep, el_len);
#endif
break;
case(IE_ID_SSID):
case(IE_ID_SUPPORTED_RATES):
case(IE_ID_DS_PARAMETER_SET):
case(IE_ID_TIM):
case(IE_ID_ERP_INFORMATION):
case(IE_ID_EXTENDED_SUPPORT_RATES):
break;
default:
g_warning("Unknown IE ID: %u Len: %u", id, el_len);
hex(iep, el_len);
}
iep += el_len;
len -= el_len;
}
}
if(privacy_required) {
if(privacy_wpa2) {
g_snprintf(privacy_buff, DETAILS_STR_MAX, "WPA2");
} else {
if(privacy_wpa) {
g_snprintf(privacy_buff, DETAILS_STR_MAX, "WPA");
} else {
g_snprintf(privacy_buff, DETAILS_STR_MAX, "WEP");
}
}
} else {
g_snprintf(privacy_buff, DETAILS_STR_MAX, "None");
}
simple_list_append(list,
0, ssid_buff,
1, mac_buff,
2, vendor_buff,
3, privacy_buff,
4, rssi_buff,
5, nettype_buff,
6, infra_buff,
7, freq_buff,
8, Rates->str,
9, country_buff,
-1);
g_string_free(Rates, TRUE );
bssid_item = (struct ndis_ssid_item *) (((char *) bssid_item) + bssid_item->length);
}
}
}
static int
capture_if_details_802_11(GtkWidget *table, GtkWidget *main_vb, guint *row, LPADAPTER adapter) {
ULONG ulong_value;
LONG rssi = -100;
unsigned int uint_value;
unsigned char values[100];
struct ndis_essid ssid;
int length;
struct ndis_bssid_list *bssid_list;
struct ndis_configuration *configuration;
gchar string_buff[DETAILS_STR_MAX];
GString *Rates;
int entries = 0;
const gchar *manuf_name;
add_string_to_table(table, row, "Current network", "");
length = sizeof(struct ndis_essid);
memset(&ssid, 0, length);
if (wpcap_packet_request(adapter, OID_802_11_SSID, FALSE , (char *) &ssid, &length)) {
ssid_details(table, row, &ssid);
entries++;
} else {
add_string_to_table(table, row, "SSID (Service Set IDentifier)", "-");
}
length = sizeof(values);
memset(values, 0, 6);
if (wpcap_packet_request(adapter, OID_802_11_BSSID, FALSE , values, &length)) {
manuf_name = get_manuf_name_if_known(values);
if(manuf_name != NULL) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%02X:%02X:%02X:%02X:%02X:%02X (%s)",
values[0], values[1], values[2],
values[3], values[4], values[5],
manuf_name);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "%02X:%02X:%02X:%02X:%02X:%02X",
values[0], values[1], values[2],
values[3], values[4], values[5]);
}
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "BSSID (Basic Service Set IDentifier)", string_buff);
if (wpcap_packet_request_uint(adapter, OID_802_11_NETWORK_TYPE_IN_USE, &uint_value)) {
add_string_to_table(table, row, "Network type used",
val_to_str(uint_value, win32_802_11_network_type_vals, "(0x%x)"));
entries++;
} else {
add_string_to_table(table, row, "Network type used", "-");
}
if (wpcap_packet_request_ulong(adapter, OID_802_11_INFRASTRUCTURE_MODE, &uint_value)) {
add_string_to_table(table, row, "Infrastructure mode",
val_to_str(uint_value, win32_802_11_infra_mode_vals, "(0x%x)"));
entries++;
} else {
add_string_to_table(table, row, "Infrastructure mode", "-");
}
if (wpcap_packet_request_ulong(adapter, OID_802_11_AUTHENTICATION_MODE, &uint_value)) {
add_string_to_table(table, row, "Authentication mode",
val_to_str(uint_value, win32_802_11_auth_mode_vals, "(0x%x)"));
entries++;
} else {
add_string_to_table(table, row, "Authentication mode", "-");
}
if (wpcap_packet_request_ulong(adapter, OID_802_11_ENCRYPTION_STATUS, &uint_value)) {
add_string_to_table(table, row, "Encryption status",
val_to_str(uint_value, win32_802_11_encryption_status_vals, "(0x%x)"));
entries++;
} else {
add_string_to_table(table, row, "Encryption status", "-");
}
if (wpcap_packet_request_ulong(adapter, OID_802_11_TX_POWER_LEVEL, &ulong_value)) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%ld mW", ulong_value);
add_string_to_table(table, row, "TX power", string_buff);
entries++;
} else {
add_string_to_table(table, row, "TX power", "-");
}
if (wpcap_packet_request_ulong(adapter, OID_802_11_RSSI, &rssi)) {
#if 0
int i;
GList * scale_items = NULL;
GList * current;
GtkVUMeterScaleItem *item;
for (i = 0; i <= 100; i++) {
item = g_malloc(sizeof(GtkVUMeterScaleItem));
item->level = i;
item->large = !(i%5);
item->label = NULL;
switch(item->level) {
case 0:
item->label = "-100 ";
break;
case 20:
item->label = "-80 ";
break;
case 40:
item->label = "-60 ";
break;
case 60:
item->label = "-40 ";
break;
case 80:
item->label = "-20 ";
break;
case 100:
item->label = "0";
break;
default:
item->label = NULL;
}
scale_items = g_list_append(scale_items, item);
}
if(rssi < -100) {
rssi = -100;
}
g_snprintf(string_buff, DETAILS_STR_MAX, "%ld dBm", rssi);
add_meter_to_table(table, row, "RSSI (Received Signal Strength Indication)",
rssi+100 , string_buff, -100+100, 0+100, -80+100, scale_items);
current = scale_items;
while (current != NULL) {
g_free(current->data);
current = g_list_next(current);
}
g_list_free(scale_items);
entries++;
#endif
} else {
add_string_to_table(table, row, "RSSI (Received Signal Strength Indication)", "-");
}
length = sizeof(values);
if (!wpcap_packet_request(adapter, OID_802_11_SUPPORTED_RATES, FALSE , values, &length)) {
length = 0;
} else {
entries++;
}
if (length != 0 && wpcap_packet_request_uint(adapter, OID_GEN_LINK_SPEED, &uint_value)) {
#if 0
int max;
int yellow;
GList *rates_list;
GList * current;
rates_list = rates_vu_list(values, length, &max);
if(rssi == -100) {
uint_value = 0;
}
uint_value /= 10 * 1000;
g_snprintf(string_buff, DETAILS_STR_MAX, "%u MBits/s", uint_value);
if(max >= 54) {
yellow = 2;
} else {
yellow = 1;
}
add_meter_to_table(table, row, "Link Speed",
uint_value, string_buff, 0, max, yellow, rates_list);
current = rates_list;
while (current != NULL) {
g_free(current->data);
current = g_list_next(current);
}
g_list_free(rates_list);
#endif
}
Rates = rates_details(values, length);
add_string_to_table(table, row, "Supported Rates", Rates->str);
g_string_free(Rates, TRUE );
length = sizeof(values);
if (!wpcap_packet_request(adapter, OID_802_11_DESIRED_RATES, FALSE , values, &length)) {
length = 0;
} else {
entries++;
}
Rates = rates_details(values, length);
add_string_to_table(table, row, "Desired Rates", Rates->str);
g_string_free(Rates, TRUE );
length = sizeof(values);
if (wpcap_packet_request(adapter, OID_802_11_CONFIGURATION, FALSE , (char *) values, &length)) {
configuration = (struct ndis_configuration *) values;
add_string_to_table(table, row, "Channel",
val_to_str(configuration->ds_config, win32_802_11_channel_freq_vals, "(%u kHz)"));
entries++;
} else {
add_string_to_table(table, row, "Channel", "-");
}
length = sizeof(uint_value);
if (wpcap_packet_request(adapter, OID_802_11_BSSID_LIST_SCAN, TRUE , (char *) &uint_value, &length)) {
#if 0
g_warning("BSSID list scan done");
} else {
g_warning("BSSID list scan failed");
#endif
}
length = sizeof(ULONG) + sizeof(struct ndis_ssid_item) * 16;
bssid_list = g_malloc(length);
memset(bssid_list, 0, length);
if (wpcap_packet_request(adapter, OID_802_11_BSSID_LIST, FALSE , (char *) bssid_list, &length)) {
add_string_to_table(table, row, "", "");
add_string_to_table(table, row, "Available networks (BSSID list)", "");
capture_if_details_802_11_bssid_list(main_vb, bssid_list);
entries += bssid_list->num_items;
} else {
add_string_to_table(table, row, "Available networks (BSSID list)", "-");
}
g_free(bssid_list);
return entries;
}
static int
capture_if_details_802_3(GtkWidget *table, GtkWidget *main_vb, guint *row, LPADAPTER adapter) {
unsigned int uint_value;
unsigned char values[100];
int length;
gchar string_buff[DETAILS_STR_MAX];
const gchar *manuf_name;
int entries = 0;
add_string_to_table(table, row, "Characteristics", "");
length = sizeof(values);
if (wpcap_packet_request(adapter, OID_802_3_PERMANENT_ADDRESS, FALSE , values, &length)) {
manuf_name = get_manuf_name_if_known(values);
if(manuf_name != NULL) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%02X:%02X:%02X:%02X:%02X:%02X (%s)",
values[0], values[1], values[2],
values[3], values[4], values[5],
manuf_name);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "%02X:%02X:%02X:%02X:%02X:%02X",
values[0], values[1], values[2],
values[3], values[4], values[5]);
}
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Permanent station address", string_buff);
length = sizeof(values);
if (wpcap_packet_request(adapter, OID_802_3_CURRENT_ADDRESS, FALSE , values, &length)) {
manuf_name = get_manuf_name_if_known(values);
if(manuf_name != NULL) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%02X:%02X:%02X:%02X:%02X:%02X (%s)",
values[0], values[1], values[2],
values[3], values[4], values[5],
manuf_name);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "%02X:%02X:%02X:%02X:%02X:%02X",
values[0], values[1], values[2],
values[3], values[4], values[5]);
}
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Current station address", string_buff);
add_string_to_table(table, row, "", "");
add_string_to_table(table, row, "Statistics", "");
if (wpcap_packet_request_uint(adapter, OID_802_3_RCV_ERROR_ALIGNMENT, &uint_value)) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Packets received with alignment error", string_buff);
if (wpcap_packet_request_uint(adapter, OID_802_3_XMIT_ONE_COLLISION, &uint_value)) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Packets transmitted with one collision", string_buff);
if (wpcap_packet_request_uint(adapter, OID_802_3_XMIT_MORE_COLLISIONS, &uint_value)) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Packets transmitted with more than one collision", string_buff);
if (wpcap_packet_request_uint(adapter, OID_802_3_RCV_OVERRUN, &uint_value)) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Packets not received due to overrun", string_buff);
if (wpcap_packet_request_uint(adapter, OID_802_3_XMIT_DEFERRED, &uint_value)) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Packets transmitted after deferred", string_buff);
if (wpcap_packet_request_uint(adapter, OID_802_3_XMIT_MAX_COLLISIONS, &uint_value)) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Packets not transmitted due to collisions", string_buff);
if (wpcap_packet_request_uint(adapter, OID_802_3_XMIT_UNDERRUN, &uint_value)) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Packets not transmitted due to underrun", string_buff);
if (wpcap_packet_request_uint(adapter, OID_802_3_XMIT_HEARTBEAT_FAILURE, &uint_value)) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Packets transmitted with heartbeat failure", string_buff);
if (wpcap_packet_request_uint(adapter, OID_802_3_XMIT_TIMES_CRS_LOST, &uint_value)) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Times carrier sense signal lost during transmission", string_buff);
if (wpcap_packet_request_uint(adapter, OID_802_3_XMIT_LATE_COLLISIONS, &uint_value)) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Times late collisions detected", string_buff);
return entries;
}
static int
capture_if_details_task_offload(GtkWidget *table, GtkWidget *main_vb, guint *row, LPADAPTER adapter) {
NDIS_TASK_OFFLOAD_HEADER *offload;
unsigned char values[10000];
int length;
gchar string_buff[DETAILS_STR_MAX];
int entries = 0;
int TcpIpChecksumSupported = 0;
int IpSecSupported = 0;
int TcpLargeSendSupported = 0;
offload = (NDIS_TASK_OFFLOAD_HEADER *) values;
offload->Version = NDIS_TASK_OFFLOAD_VERSION;
offload->Size = sizeof(NDIS_TASK_OFFLOAD_HEADER);
offload->Reserved = 0;
offload->OffsetFirstTask = 0;
offload->EncapsulationFormat.Encapsulation = IEEE_802_3_Encapsulation;
offload->EncapsulationFormat.Flags.FixedHeaderSize = 1;
offload->EncapsulationFormat.Flags.Reserved = 0;
offload->EncapsulationFormat.EncapsulationHeaderSize = 14; ;
length = sizeof(values);
if (wpcap_packet_request(adapter, OID_TCP_TASK_OFFLOAD, FALSE , values, &length)) {
NDIS_TASK_OFFLOAD *of;
unsigned char *valuep = values + offload->OffsetFirstTask;
length -= offload->OffsetFirstTask;
do {
of = (NDIS_TASK_OFFLOAD *) valuep;
switch(of->Task) {
case TcpIpChecksumNdisTask:
{
NDIS_TASK_TCP_IP_CHECKSUM *tic = (NDIS_TASK_TCP_IP_CHECKSUM *) (of->TaskBuffer);
entries++;
TcpIpChecksumSupported++;
add_string_to_table(table, row, "TCP/IP Checksum", "");
g_snprintf(string_buff, DETAILS_STR_MAX, "");
add_string_to_table(table, row, "V4 transmit checksum", "");
g_snprintf(string_buff, DETAILS_STR_MAX, "TCP: %s, UDP: %s, IP: %s",
tic->V4Transmit.TcpChecksum ? "Yes" : "No",
tic->V4Transmit.UdpChecksum ? "Yes" : "No",
tic->V4Transmit.IpChecksum ? "Yes" : "No");
add_string_to_table(table, row, "Calculation supported", string_buff);
g_snprintf(string_buff, DETAILS_STR_MAX, "TCP: %s, IP: %s",
tic->V4Transmit.TcpOptionsSupported ? "Yes" : "No",
tic->V4Transmit.IpOptionsSupported ? "Yes" : "No");
add_string_to_table(table, row, "Options fields supported", string_buff);
g_snprintf(string_buff, DETAILS_STR_MAX, "");
add_string_to_table(table, row, "V4 receive checksum", "");
g_snprintf(string_buff, DETAILS_STR_MAX, "TCP: %s, UDP: %s, IP: %s",
tic->V4Receive.TcpChecksum ? "Yes" : "No",
tic->V4Receive.UdpChecksum ? "Yes" : "No",
tic->V4Receive.IpChecksum ? "Yes" : "No");
add_string_to_table(table, row, "Validation supported", string_buff);
g_snprintf(string_buff, DETAILS_STR_MAX, "TCP: %s, IP: %s",
tic->V4Receive.TcpOptionsSupported ? "Yes" : "No",
tic->V4Receive.IpOptionsSupported ? "Yes" : "No");
add_string_to_table(table, row, "Options fields supported", string_buff);
g_snprintf(string_buff, DETAILS_STR_MAX, "");
add_string_to_table(table, row, "V6 transmit checksum", "");
g_snprintf(string_buff, DETAILS_STR_MAX, "TCP: %s, UDP: %s",
tic->V6Transmit.TcpChecksum ? "Yes" : "No",
tic->V6Transmit.UdpChecksum ? "Yes" : "No");
add_string_to_table(table, row, "Calculation supported", string_buff);
g_snprintf(string_buff, DETAILS_STR_MAX, "TCP: %s, IP: %s",
tic->V6Transmit.TcpOptionsSupported ? "Yes" : "No",
tic->V6Transmit.IpOptionsSupported ? "Yes" : "No");
add_string_to_table(table, row, "Options fields supported", string_buff);
g_snprintf(string_buff, DETAILS_STR_MAX, "");
add_string_to_table(table, row, "V6 receive checksum", "");
g_snprintf(string_buff, DETAILS_STR_MAX, "TCP: %s, UDP: %s",
tic->V6Receive.TcpChecksum ? "Yes" : "No",
tic->V6Receive.UdpChecksum ? "Yes" : "No");
add_string_to_table(table, row, "Validation supported", string_buff);
g_snprintf(string_buff, DETAILS_STR_MAX, "TCP: %s, IP: %s",
tic->V6Receive.TcpOptionsSupported ? "Yes" : "No",
tic->V6Receive.IpOptionsSupported ? "Yes" : "No");
add_string_to_table(table, row, "Options fields supported", string_buff);
}
break;
case IpSecNdisTask:
entries++;
IpSecSupported++;
add_string_to_table(table, row, "IPSEC", "");
g_snprintf(string_buff, DETAILS_STR_MAX, "IPSEC (TaskID 1) not decoded yet");
add_string_to_table(table, row, "Task", string_buff);
break;
case TcpLargeSendNdisTask:
{
NDIS_TASK_TCP_LARGE_SEND *tls = (NDIS_TASK_TCP_LARGE_SEND *) (of->TaskBuffer);
entries++;
TcpLargeSendSupported++;
add_string_to_table(table, row, "TCP large send", "");
if(tls->Version == 1) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%u", tls->MaxOffLoadSize);
add_string_to_table(table, row, "Max Offload Size", string_buff);
g_snprintf(string_buff, DETAILS_STR_MAX, "%u", tls->MinSegmentCount);
add_string_to_table(table, row, "Min Segment Count", string_buff);
g_snprintf(string_buff, DETAILS_STR_MAX, "%s", tls->TcpOptions ? "Yes" : "No");
add_string_to_table(table, row, "TCP option fields", string_buff);
g_snprintf(string_buff, DETAILS_STR_MAX, "%s", tls->IpOptions ? "Yes" : "No");
add_string_to_table(table, row, "IP option fields", string_buff);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "%u (unknown)", tls->Version);
add_string_to_table(table, row, "Version", string_buff);
}
}
break;
default:
g_snprintf(string_buff, DETAILS_STR_MAX, "Unknown task %u", of->Task);
add_string_to_table(table, row, "Task", string_buff);
}
add_string_to_table(table, row, "", "");
valuep += of->OffsetNextTask;
length -= of->OffsetNextTask;
} while(of->OffsetNextTask != 0);
}
if(TcpIpChecksumSupported == 0) {
add_string_to_table(table, row, "TCP/IP Checksum", "");
add_string_to_table(table, row, "Offload not supported", "-");
}
if(IpSecSupported == 0) {
add_string_to_table(table, row, "IpSec", "");
add_string_to_table(table, row, "Offload not supported", "-");
}
if(TcpLargeSendSupported == 0) {
add_string_to_table(table, row, "TCP Large Send", "");
add_string_to_table(table, row, "Offload not supported", "-");
}
return entries;
}
static int
capture_if_details_general(GtkWidget *table, GtkWidget *main_vb, guint *row, LPADAPTER adapter, gchar *iface) {
gchar string_buff[DETAILS_STR_MAX];
const gchar *manuf_name;
unsigned int uint_value;
unsigned int uint_array[50];
int uint_array_size;
unsigned int physical_medium;
int i;
unsigned char values[100];
int length;
unsigned short ushort_value;
int entries = 0;
add_string_to_table(table, row, "Characteristics", "");
length = sizeof(values);
if (wpcap_packet_request(adapter, OID_GEN_VENDOR_DESCRIPTION, FALSE , values, &length)) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%s", values);
entries++;
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Vendor description", string_buff);
add_string_to_table(table, row, "Interface", iface);
if (wpcap_packet_request_uint(adapter, OID_GEN_MEDIA_CONNECT_STATUS, &uint_value)) {
entries++;
if(uint_value == 0) {
add_string_to_table(table, row, "Link status", "Connected");
} else {
add_string_to_table(table, row, "Link status", "Disconnected");
}
} else {
add_string_to_table(table, row, "Link status", "-");
}
if (wpcap_packet_request_uint(adapter, OID_GEN_LINK_SPEED, &uint_value)) {
entries++;
uint_value *= 100;
if(uint_value >= 1000 * 1000) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%d MBits/s", uint_value / 1000 / 1000);
} else {
if(uint_value >= 1000) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%d KBits/s", uint_value / 1000);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "%d Bits/s", uint_value);
}
}
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Link speed", string_buff);
uint_array_size = sizeof(uint_array);
if (wpcap_packet_request(adapter, OID_GEN_MEDIA_SUPPORTED, FALSE , (char *) uint_array, &uint_array_size)) {
entries++;
uint_array_size /= sizeof(unsigned int);
i=0;
while(uint_array_size--) {
add_string_to_table(table, row, "Media supported",
val_to_str(uint_array[i], win32_802_3_medium_vals, "(0x%x)"));
i++;
}
} else {
add_string_to_table(table, row, "Media supported", "-");
}
uint_array_size = sizeof(uint_array);
if (wpcap_packet_request(adapter, OID_GEN_MEDIA_IN_USE, FALSE , (char *) uint_array, &uint_array_size)) {
entries++;
uint_array_size /= sizeof(unsigned int);
i=0;
while(uint_array_size--) {
add_string_to_table(table, row, "Medium in use",
val_to_str(uint_array[i], win32_802_3_medium_vals, "(0x%x)"));
i++;
}
} else {
add_string_to_table(table, row, "Medium in use", "-");
}
if (wpcap_packet_request_uint(adapter, OID_GEN_PHYSICAL_MEDIUM, &physical_medium)) {
entries++;
add_string_to_table(table, row, "Physical medium",
val_to_str(physical_medium, win32_802_3_physical_medium_vals, "(0x%x)"));
} else {
add_string_to_table(table, row, "Physical medium", "-");
}
length = sizeof(ushort_value);
if (wpcap_packet_request(adapter, OID_GEN_DRIVER_VERSION, FALSE , (char *) &ushort_value, &length)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%u.%u", ushort_value / 0x100, ushort_value % 0x100);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "NDIS Driver Version", string_buff);
length = sizeof(uint_value);
if (wpcap_packet_request(adapter, OID_GEN_VENDOR_DRIVER_VERSION, FALSE , (char *) &uint_value, &length)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%u.%u (Hex: %X.%X)",
(uint_value / 0x10000 ) % 0x10000,
uint_value % 0x10000,
(uint_value / 0x10000 ) % 0x10000,
uint_value % 0x10000);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Vendor Driver Version", string_buff);
length = sizeof(values);
if (wpcap_packet_request(adapter, OID_GEN_VENDOR_ID, FALSE , values, &length)) {
entries++;
manuf_name = get_manuf_name_if_known(values);
if(manuf_name != NULL) {
g_snprintf(string_buff, DETAILS_STR_MAX, "%02X:%02X:%02X (%s) NIC: %02X",
values[0], values[1], values[2], manuf_name, values[3]);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "%02X:%02X:%02X NIC: %02X",
values[0], values[1], values[2], values[3]);
}
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Vendor ID", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_MAC_OPTIONS, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX,
"802.1P Priority: %s, 802.1Q VLAN: %s",
(uint_value & NDIS_MAC_OPTION_8021P_PRIORITY) ? "Supported" : "Unsupported",
(uint_value & NDIS_MAC_OPTION_8021Q_VLAN) ? "Supported" : "Unsupported" );
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "MAC Options", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_VLAN_ID, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%u", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "VLAN ID", string_buff);
#if 0
if (wpcap_packet_request_uint(adapter, OID_GEN_CURRENT_PACKET_FILTER, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Packet filter", string_buff);
#endif
if (wpcap_packet_request_uint(adapter, OID_GEN_TRANSMIT_BUFFER_SPACE, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Transmit Buffer Space", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_RECEIVE_BUFFER_SPACE, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Receive Buffer Space", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_TRANSMIT_BLOCK_SIZE , &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Transmit Block Size", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_RECEIVE_BLOCK_SIZE, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Receive Block Size", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_MAXIMUM_TOTAL_SIZE, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Maximum Packet Size", string_buff);
return entries;
}
static int
capture_if_details_stats(GtkWidget *table, GtkWidget *main_vb, guint *row, LPADAPTER adapter) {
gchar string_buff[DETAILS_STR_MAX];
unsigned int uint_value;
int entries = 0;
add_string_to_table(table, row, "Statistics", "");
if (wpcap_packet_request_uint(adapter, OID_GEN_XMIT_OK, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Transmit OK", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_XMIT_ERROR, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Transmit Error", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_RCV_OK, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Receive OK", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_RCV_ERROR, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Receive Error", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_RCV_NO_BUFFER, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Receive but no Buffer", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_DIRECTED_BYTES_XMIT, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Directed bytes transmitted w/o errors", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_DIRECTED_FRAMES_XMIT, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Directed packets transmitted w/o errors", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_MULTICAST_BYTES_XMIT, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Multicast bytes transmitted w/o errors", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_MULTICAST_FRAMES_XMIT, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Multicast packets transmitted w/o errors", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_BROADCAST_BYTES_XMIT, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Broadcast bytes transmitted w/o errors", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_BROADCAST_FRAMES_XMIT, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Broadcast packets transmitted w/o errors", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_DIRECTED_BYTES_RCV, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Directed bytes received w/o errors", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_DIRECTED_FRAMES_RCV, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Directed packets received w/o errors", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_MULTICAST_BYTES_RCV, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Multicast bytes received w/o errors", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_MULTICAST_FRAMES_RCV, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Multicast packets received w/o errors", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_BROADCAST_BYTES_RCV, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Broadcast bytes received w/o errors", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_BROADCAST_FRAMES_RCV, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Broadcast packets received w/o errors", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_RCV_CRC_ERROR, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Packets received with CRC or FCS errors", string_buff);
if (wpcap_packet_request_uint(adapter, OID_GEN_TRANSMIT_QUEUE_LENGTH, &uint_value)) {
entries++;
g_snprintf(string_buff, DETAILS_STR_MAX, "%d", uint_value);
} else {
g_snprintf(string_buff, DETAILS_STR_MAX, "-");
}
add_string_to_table(table, row, "Packets queued for transmission", string_buff);
return entries;
}
static GtkWidget *
capture_if_details_page_new(GtkWidget **table)
{
GtkWidget *main_vb;
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 6, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 12);
*table = gtk_table_new(1, 2, FALSE);
gtk_table_set_col_spacings(GTK_TABLE(*table), 6);
gtk_table_set_row_spacings(GTK_TABLE(*table), 3);
gtk_container_add(GTK_CONTAINER(main_vb), *table);
return main_vb;
}
static void
capture_if_details_open_win(char *iface)
{
GtkWidget *details_open_w,
*main_vb, *bbox, *close_bt, *help_bt;
GtkWidget *page_general, *page_stats, *page_802_3, *page_802_11, *page_task_offload;
GtkWidget *page_lb;
GtkWidget *table, *notebook, *label;
guint row;
LPADAPTER adapter;
int entries;
adapter = wpcap_packet_open(iface);
if(adapter == NULL) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK,
"%sCould not open adapter %s!%s"
"\n\nHas it been unplugged?",
simple_dialog_primary_start(), iface, simple_dialog_primary_end());
return;
}
details_open_w = dlg_window_new("Wireshark: Interface Details");
gtk_window_set_destroy_with_parent (GTK_WINDOW(details_open_w), TRUE);
main_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 12, FALSE);
gtk_container_set_border_width(GTK_CONTAINER(main_vb), 12);
gtk_container_add(GTK_CONTAINER(details_open_w), main_vb);
notebook = gtk_notebook_new();
gtk_box_pack_start(GTK_BOX(main_vb), notebook, TRUE , TRUE , 0 );
page_general = capture_if_details_page_new(&table);
page_lb = gtk_label_new("Characteristics");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page_general, page_lb);
row = 0;
entries = capture_if_details_general(table, page_general, &row, adapter, iface);
if(entries == 0) {
gtk_widget_set_sensitive(page_lb, FALSE);
}
page_stats = capture_if_details_page_new(&table);
page_lb = gtk_label_new("Statistics");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page_stats, page_lb);
row = 0;
entries = capture_if_details_stats(table, page_stats, &row, adapter);
if(entries == 0) {
gtk_widget_set_sensitive(page_lb, FALSE);
}
page_802_3 = capture_if_details_page_new(&table);
page_lb = gtk_label_new("802.3 (Ethernet)");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page_802_3, page_lb);
row = 0;
entries = capture_if_details_802_3(table, page_802_3, &row, adapter);
if(entries == 0) {
gtk_widget_set_sensitive(page_lb, FALSE);
}
page_802_11 = capture_if_details_page_new(&table);
page_lb = gtk_label_new("802.11 (WLAN)");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page_802_11, page_lb);
row = 0;
entries = capture_if_details_802_11(table, page_802_11, &row, adapter);
if(entries == 0) {
gtk_widget_set_sensitive(page_lb, FALSE);
}
page_task_offload = capture_if_details_page_new(&table);
page_lb = gtk_label_new("Task Offload");
gtk_notebook_append_page(GTK_NOTEBOOK(notebook), page_task_offload, page_lb);
row = 0;
entries = capture_if_details_task_offload(table, page_task_offload, &row, adapter);
if(entries == 0) {
gtk_widget_set_sensitive(page_lb, FALSE);
}
wpcap_packet_close(adapter);
label = gtk_label_new("Note: the accuracy of all of these values relies only on the network card driver!");
gtk_box_pack_start(GTK_BOX(main_vb), label, FALSE , FALSE , 0 );
bbox = dlg_button_row_new(GTK_STOCK_CLOSE, GTK_STOCK_HELP, NULL);
gtk_box_pack_start(GTK_BOX(main_vb), bbox, FALSE , FALSE , 0 );
close_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(details_open_w, close_bt, window_cancel_button_cb);
help_bt = g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer) (HELP_CAPTURE_INTERFACES_DETAILS_DIALOG));
gtk_widget_grab_focus(close_bt);
g_signal_connect(details_open_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
gtk_widget_show_all(details_open_w);
window_present(details_open_w);
}
static void capture_if_details_open_answered_cb(gpointer dialog _U_, gint btn, gpointer data)
{
switch(btn) {
case(ESD_BTN_OK):
capture_if_details_open_win(data);
break;
case(ESD_BTN_CANCEL):
break;
default:
g_assert_not_reached();
}
}
void
capture_if_details_open(char *iface)
{
char *version;
gboolean version_ok = FALSE;
gpointer dialog;
version = wpcap_packet_get_version();
if(version == NULL) {
simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK,
"%sCouldn't obtain WinPcap packet.dll version!%s"
"\n\nThe WinPcap packet.dll is not installed or the version you use seems to be very old!"
"\n\nPlease update/install WinPcap.",
simple_dialog_primary_start(), simple_dialog_primary_end());
return;
}
if(
strcmp(version, "3" ) > 0 ||
strcmp(version, "3, 2, 0, 29") == 0 ||
strcmp(version, "3, 1, 0, 27") == 0 ||
strcmp(version, "3, 1, 0, 24") == 0 ||
strcmp(version, "3, 1, 0, 23") == 0 ||
strcmp(version, "3, 1, 0, 22") == 0 ||
strcmp(version, "3, 1, 0, 20") == 0 ||
strcmp(version, "3.0 alpha3" ) == 0 ||
strcmp(version, "2.3" ) == 0
) {
version_ok = TRUE;
}
if(!version_ok) {
dialog = simple_dialog(ESD_TYPE_WARN, ESD_BTN_OK | ESD_BTN_CANCEL,
"%sUnknown WinPcap version might crash or fail!%s"
"\n\nThe WinPcap packet.dll version \"%s\" is unknown if it supports required functions!"
"\n\nOnly WinPcap versions 3.0 and 3.1 are known to work with this feature."
"\n\nCrashes or unexpected behaviour might occur, you have been warned!"
"\n\nContinue anyway?",
simple_dialog_primary_start(), simple_dialog_primary_end(), version);
simple_dialog_set_cb(dialog, capture_if_details_open_answered_cb, iface);
} else {
capture_if_details_open_win(iface);
}
}
gboolean
capture_if_has_details(char *iface) {
LPADAPTER adapter;
if (!iface) {
return FALSE;
}
adapter = wpcap_packet_open(iface);
if (adapter) {
wpcap_packet_close(adapter);
return TRUE;
}
return FALSE;
}
