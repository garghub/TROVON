static void mac_lte_stat_reset(void *phs)
{
mac_lte_stat_t *mac_lte_stat = (mac_lte_stat_t *)phs;
mac_lte_ep_t *list = mac_lte_stat->ep_list;
char *display_name;
gchar title[256];
GtkListStore *store;
gint i, n;
if (mac_lte_stat->mac_lte_stat_dlg_w != NULL) {
display_name = cf_get_display_name(&cfile);
g_snprintf(title, sizeof(title), "Wireshark: LTE MAC Traffic Statistics: %s (filter=\"%s\")",
display_name,
strlen(mac_lte_stat->filter) ? mac_lte_stat->filter : "none");
g_free(display_name);
gtk_window_set_title(GTK_WINDOW(mac_lte_stat->mac_lte_stat_dlg_w), title);
}
g_snprintf(title, sizeof(title), "UL/DL-SCH data (0 entries)");
gtk_frame_set_label(GTK_FRAME(mac_lte_stat->mac_lte_stat_ues_lb), title);
memset(mac_lte_stat->used_ueids, 0, 65535);
mac_lte_stat->number_of_ueids = 0;
memset(mac_lte_stat->used_rntis, 0, 65535);
mac_lte_stat->number_of_rntis = 0;
memset(&(mac_lte_stat->common_stats), 0, sizeof(mac_lte_common_stats));
store = GTK_LIST_STORE(gtk_tree_view_get_model(mac_lte_stat->ue_table));
gtk_list_store_clear(store);
if (!list) {
return;
}
mac_lte_stat->ep_list = NULL;
for (n=1; n <=4; n++) {
for (i=CCCH_COLUMN; i < NUM_CHANNEL_COLUMNS; i++) {
gtk_label_set_text(GTK_LABEL(mac_lte_stat->selected_ue_column_entry[i][n]), "0");
}
}
}
static mac_lte_ep_t* alloc_mac_lte_ep(const struct mac_lte_tap_info *si, packet_info *pinfo _U_)
{
mac_lte_ep_t *ep;
int n;
if (!si) {
return NULL;
}
if (!(ep = (mac_lte_ep_t *)g_malloc(sizeof(mac_lte_ep_t)))) {
return NULL;
}
ep->stats.rnti = si->rnti;
ep->stats.rnti_type = si->rntiType;
ep->stats.ueid = si->ueid;
ep->stats.UL_frames = 0;
ep->stats.DL_frames = 0;
ep->stats.UL_total_bytes = 0;
ep->stats.UL_raw_bytes = 0;
ep->stats.DL_raw_bytes = 0;
ep->stats.UL_padding_bytes = 0;
ep->stats.DL_padding_bytes = 0;
ep->stats.DL_total_bytes = 0;
ep->stats.UL_CRC_errors = 0;
ep->stats.DL_CRC_failures = 0;
ep->stats.DL_CRC_high_code_rate = 0;
ep->stats.DL_CRC_PDSCH_lost = 0;
ep->stats.DL_CRC_Duplicate_Nonzero_rv = 0;
ep->stats.UL_retx_frames = 0;
ep->stats.DL_retx_frames = 0;
for (n=0; n < 11; n++) {
ep->stats.UL_sdus_for_lcid[n] = 0;
ep->stats.UL_bytes_for_lcid[n] = 0;
}
ep->stats.DL_total_bytes = 0;
for (n=0; n < 11; n++) {
ep->stats.DL_sdus_for_lcid[n] = 0;
ep->stats.DL_bytes_for_lcid[n] = 0;
}
ep->next = NULL;
ep->iter_valid = FALSE;
return ep;
}
static void update_ueid_rnti_counts(guint16 rnti, guint16 ueid, mac_lte_stat_t *hs)
{
if (!hs->used_ueids[ueid]) {
hs->used_ueids[ueid] = TRUE;
hs->number_of_ueids++;
}
if (!hs->used_rntis[rnti]) {
hs->used_rntis[rnti] = TRUE;
hs->number_of_rntis++;
}
}
static int mac_lte_stat_packet(void *phs, packet_info *pinfo, epan_dissect_t *edt _U_,
const void *phi)
{
int n;
mac_lte_stat_t *hs = (mac_lte_stat_t *)phs;
mac_lte_ep_t *tmp = NULL, *te = NULL;
const struct mac_lte_tap_info *si = (const struct mac_lte_tap_info *)phi;
if (!hs) {
return 0;
}
hs->common_stats.all_frames++;
switch (si->rntiType) {
case P_RNTI:
hs->common_stats.pch_frames++;
hs->common_stats.pch_bytes += si->single_number_of_bytes;
hs->common_stats.pch_paging_ids += si->number_of_paging_ids;
return 1;
case SI_RNTI:
hs->common_stats.sib_frames++;
hs->common_stats.sib_bytes += si->single_number_of_bytes;
return 1;
case NO_RNTI:
hs->common_stats.mib_frames++;
return 1;
case RA_RNTI:
hs->common_stats.rar_frames++;
hs->common_stats.rar_entries += si->number_of_rars;
return 1;
case C_RNTI:
case SPS_RNTI:
break;
default:
return 0;
}
switch (si->direction) {
case DIRECTION_UPLINK:
hs->common_stats.max_ul_ues_in_tti =
MAX(hs->common_stats.max_ul_ues_in_tti, si->ueInTTI);
break;
case DIRECTION_DOWNLINK:
hs->common_stats.max_dl_ues_in_tti =
MAX(hs->common_stats.max_dl_ues_in_tti, si->ueInTTI);
break;
}
if (!hs->ep_list) {
hs->ep_list = alloc_mac_lte_ep(si, pinfo);
te = hs->ep_list;
update_ueid_rnti_counts(si->rnti, si->ueid, hs);
} else {
for (tmp = hs->ep_list;(tmp != NULL); tmp = tmp->next) {
if ((tmp->stats.rnti == si->rnti) &&
(tmp->stats.ueid == si->ueid)) {
te = tmp;
break;
}
}
if (te == NULL) {
if ((te = alloc_mac_lte_ep(si, pinfo))) {
mac_lte_ep_t *p = hs->ep_list;
while (p->next) {
p = p->next;
}
p->next = te;
te->next = NULL;
update_ueid_rnti_counts(si->rnti, si->ueid, hs);
}
}
}
if (!te) {
return 0;
}
te->stats.rnti = si->rnti;
te->stats.is_predefined_data = si->isPredefinedData;
if (si->direction == DIRECTION_UPLINK) {
if (si->isPHYRetx) {
te->stats.UL_retx_frames++;
return 1;
}
if (si->crcStatusValid && (si->crcStatus != crc_success)) {
te->stats.UL_CRC_errors++;
return 1;
}
if (te->stats.UL_frames == 0) {
te->stats.UL_time_start = si->time;
}
te->stats.UL_time_stop = si->time;
te->stats.UL_frames++;
te->stats.UL_raw_bytes += si->raw_length;
te->stats.UL_padding_bytes += si->padding_bytes;
if (si->isPredefinedData) {
te->stats.UL_total_bytes += si->single_number_of_bytes;
}
else {
for (n=0; n < 11; n++) {
te->stats.UL_sdus_for_lcid[n] += si->sdus_for_lcid[n];
te->stats.UL_bytes_for_lcid[n] += si->bytes_for_lcid[n];
te->stats.UL_total_bytes += si->bytes_for_lcid[n];
}
}
}
else {
if (si->isPHYRetx) {
te->stats.DL_retx_frames++;
return 1;
}
if (si->crcStatusValid && (si->crcStatus != crc_success)) {
switch (si->crcStatus) {
case crc_fail:
te->stats.DL_CRC_failures++;
break;
case crc_high_code_rate:
te->stats.DL_CRC_high_code_rate++;
break;
case crc_pdsch_lost:
te->stats.DL_CRC_PDSCH_lost++;
break;
case crc_duplicate_nonzero_rv:
te->stats.DL_CRC_Duplicate_Nonzero_rv++;
break;
default:
break;
}
return 1;
}
if (te->stats.DL_frames == 0) {
te->stats.DL_time_start = si->time;
}
te->stats.DL_time_stop = si->time;
te->stats.DL_frames++;
te->stats.DL_raw_bytes += si->raw_length;
te->stats.DL_padding_bytes += si->padding_bytes;
if (si->isPredefinedData) {
te->stats.DL_total_bytes += si->single_number_of_bytes;
}
else {
for (n=0; n < 11; n++) {
te->stats.DL_sdus_for_lcid[n] += si->sdus_for_lcid[n];
te->stats.DL_bytes_for_lcid[n] += si->bytes_for_lcid[n];
te->stats.DL_total_bytes += si->bytes_for_lcid[n];
}
}
}
return 1;
}
static void mac_lte_ue_details(mac_lte_ep_t *mac_stat_ep, mac_lte_stat_t *hs)
{
int n;
gchar buff[32];
guint8 show_dct_errors;
for (n=0; n < PREDEFINED_COLUMN-1; n++) {
g_snprintf(buff, sizeof(buff), "%u",
(mac_stat_ep != NULL) ? mac_stat_ep->stats.UL_sdus_for_lcid[n] : 0);
gtk_label_set_text(GTK_LABEL(hs->selected_ue_column_entry[n+1][1]), buff);
}
if (mac_stat_ep != NULL) {
g_snprintf(buff, sizeof(buff), "%u",
mac_stat_ep->stats.is_predefined_data ? mac_stat_ep->stats.UL_frames : 0);
}
else {
g_snprintf(buff, sizeof(buff), "%u", 0);
}
gtk_label_set_text(GTK_LABEL(hs->selected_ue_column_entry[PREDEFINED_COLUMN][1]), buff);
for (n=0; n < PREDEFINED_COLUMN-1; n++) {
g_snprintf(buff, sizeof(buff), "%u",
(mac_stat_ep != NULL) ? mac_stat_ep->stats.UL_bytes_for_lcid[n] : 0);
gtk_label_set_text(GTK_LABEL(hs->selected_ue_column_entry[n+1][2]), buff);
}
if (mac_stat_ep != NULL) {
g_snprintf(buff, sizeof(buff), "%u",
mac_stat_ep->stats.is_predefined_data ? mac_stat_ep->stats.UL_total_bytes : 0);
}
else {
g_snprintf(buff, sizeof(buff), "%u", 0);
}
gtk_label_set_text(GTK_LABEL(hs->selected_ue_column_entry[PREDEFINED_COLUMN][2]), buff);
for (n=0; n < PREDEFINED_COLUMN-1; n++) {
g_snprintf(buff, sizeof(buff), "%u",
(mac_stat_ep != NULL) ? mac_stat_ep->stats.DL_sdus_for_lcid[n] : 0);
gtk_label_set_text(GTK_LABEL(hs->selected_ue_column_entry[n+1][3]), buff);
}
if (mac_stat_ep != NULL) {
g_snprintf(buff, sizeof(buff), "%u",
mac_stat_ep->stats.is_predefined_data ? mac_stat_ep->stats.DL_frames : 0);
}
else {
g_snprintf(buff, sizeof(buff), "%u", 0);
}
gtk_label_set_text(GTK_LABEL(hs->selected_ue_column_entry[PREDEFINED_COLUMN][3]), buff);
for (n=0; n < PREDEFINED_COLUMN-1; n++) {
g_snprintf(buff, sizeof(buff), "%u",
(mac_stat_ep != NULL) ? mac_stat_ep->stats.DL_bytes_for_lcid[n] : 0);
gtk_label_set_text(GTK_LABEL(hs->selected_ue_column_entry[n+1][4]), buff);
}
if (mac_stat_ep != NULL) {
g_snprintf(buff, sizeof(buff), "%u",
mac_stat_ep->stats.is_predefined_data ? mac_stat_ep->stats.DL_total_bytes : 0);
}
else {
g_snprintf(buff, sizeof(buff), "%u", 0);
}
gtk_label_set_text(GTK_LABEL(hs->selected_ue_column_entry[PREDEFINED_COLUMN][4]), buff);
if (mac_stat_ep) {
hs->selected_rnti = mac_stat_ep->stats.rnti;
hs->selected_ueid = mac_stat_ep->stats.ueid;
}
gtk_widget_set_sensitive(hs->ul_filter_bt, mac_stat_ep != NULL);
gtk_widget_set_sensitive(hs->dl_filter_bt, mac_stat_ep != NULL);
gtk_widget_set_sensitive(hs->uldl_filter_bt, mac_stat_ep != NULL);
gtk_widget_set_sensitive(hs->show_mac_rach_cb, mac_stat_ep != NULL);
gtk_widget_set_sensitive(hs->show_mac_srs_cb, mac_stat_ep != NULL);
gtk_widget_set_sensitive(hs->show_dct_errors_cb, mac_stat_ep != NULL);
show_dct_errors = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hs->show_dct_errors_cb));
gtk_widget_set_sensitive(hs->dct_error_substring_lb, show_dct_errors && (mac_stat_ep != NULL));
gtk_widget_set_sensitive(hs->dct_error_substring_te, show_dct_errors && (mac_stat_ep != NULL));
}
static float calculate_bw(nstime_t *start_time, nstime_t *stop_time, guint32 bytes)
{
if (memcmp(start_time, stop_time, sizeof(nstime_t)) != 0) {
float elapsed_ms = (((float)stop_time->secs - (float)start_time->secs) * 1000) +
(((float)stop_time->nsecs - (float)start_time->nsecs) / 1000000);
if (elapsed_ms < 2.0) {
return 0.0f;
}
return ((bytes * 8) / elapsed_ms) / 1000;
}
else {
return 0.0f;
}
}
static void mac_lte_stat_draw(void *phs)
{
gchar buff[32];
guint16 number_of_ues = 0;
char *display_name;
gchar title[256];
mac_lte_stat_t *hs = (mac_lte_stat_t *)phs;
mac_lte_ep_t *list = hs->ep_list, *tmp = 0;
GtkListStore *ues_store;
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
g_snprintf(buff, sizeof(buff), "Max UL UEs/TTI: %u", hs->common_stats.max_ul_ues_in_tti);
gtk_label_set_text(GTK_LABEL(hs->ul_max_ues_per_tti), buff);
g_snprintf(buff, sizeof(buff), "Max DL UEs/TTI: %u", hs->common_stats.max_dl_ues_in_tti);
gtk_label_set_text(GTK_LABEL(hs->dl_max_ues_per_tti), buff);
g_snprintf(buff, sizeof(buff), "MIBs: %u", hs->common_stats.mib_frames);
gtk_label_set_text(GTK_LABEL(hs->common_mib_frames), buff);
g_snprintf(buff, sizeof(buff), "SIB Frames: %u", hs->common_stats.sib_frames);
gtk_label_set_text(GTK_LABEL(hs->common_sib_frames), buff);
g_snprintf(buff, sizeof(buff), "SIB Bytes: %u", hs->common_stats.sib_bytes);
gtk_label_set_text(GTK_LABEL(hs->common_sib_bytes), buff);
g_snprintf(buff, sizeof(buff), "PCH Frames: %u", hs->common_stats.pch_frames);
gtk_label_set_text(GTK_LABEL(hs->common_pch_frames), buff);
g_snprintf(buff, sizeof(buff), "PCH Bytes: %u", hs->common_stats.pch_bytes);
gtk_label_set_text(GTK_LABEL(hs->common_pch_bytes), buff);
g_snprintf(buff, sizeof(buff), "PCH Paging Ids: %u", hs->common_stats.pch_paging_ids);
gtk_label_set_text(GTK_LABEL(hs->common_pch_paging_ids), buff);
g_snprintf(buff, sizeof(buff), "RAR Frames: %u", hs->common_stats.rar_frames);
gtk_label_set_text(GTK_LABEL(hs->common_rar_frames), buff);
g_snprintf(buff, sizeof(buff), "RAR Entries: %u", hs->common_stats.rar_entries);
gtk_label_set_text(GTK_LABEL(hs->common_rar_entries), buff);
ues_store = GTK_LIST_STORE(gtk_tree_view_get_model(hs->ue_table));
for (tmp = list; (tmp!=NULL); tmp=tmp->next, number_of_ues++);
g_snprintf(title, sizeof(title), "UL/DL-SCH data (%u entries - %u unique RNTIs, %u unique UEIds)",
number_of_ues, hs->number_of_rntis, hs->number_of_ueids);
gtk_frame_set_label(GTK_FRAME(hs->mac_lte_stat_ues_lb), title);
display_name = cf_get_display_name(&cfile);
g_snprintf(title, sizeof(title), "Wireshark: LTE MAC Traffic Statistics: %s (%u UEs, %u frames) (filter=\"%s\")",
display_name,
number_of_ues,
hs->common_stats.all_frames,
strlen(hs->filter) ? hs->filter : "none");
g_free(display_name);
gtk_window_set_title(GTK_WINDOW(hs->mac_lte_stat_dlg_w), title);
for (tmp = list; tmp; tmp=tmp->next) {
float UL_bw = calculate_bw(&tmp->stats.UL_time_start,
&tmp->stats.UL_time_stop,
tmp->stats.UL_total_bytes);
float DL_bw = calculate_bw(&tmp->stats.DL_time_start,
&tmp->stats.DL_time_stop,
tmp->stats.DL_total_bytes);
if (tmp->iter_valid != TRUE) {
gtk_list_store_append(ues_store, &tmp->iter);
tmp->iter_valid = TRUE;
}
gtk_list_store_set(ues_store, &tmp->iter,
RNTI_COLUMN, tmp->stats.rnti,
RNTI_TYPE_COLUMN,
(tmp->stats.rnti_type == C_RNTI) ? "C-RNTI" : "SPS-RNTI",
UEID_COLUMN, tmp->stats.ueid,
UL_FRAMES_COLUMN, tmp->stats.UL_frames,
UL_BYTES_COLUMN, tmp->stats.UL_total_bytes,
UL_BW_COLUMN, UL_bw,
UL_PADDING_PERCENT_COLUMN,
tmp->stats.UL_raw_bytes ?
(((float)tmp->stats.UL_padding_bytes / (float)tmp->stats.UL_raw_bytes) * 100.0) :
0.0,
UL_RETX_FRAMES_COLUMN, tmp->stats.UL_retx_frames,
DL_FRAMES_COLUMN, tmp->stats.DL_frames,
DL_BYTES_COLUMN, tmp->stats.DL_total_bytes,
DL_BW_COLUMN, DL_bw,
DL_PADDING_PERCENT_COLUMN,
tmp->stats.DL_raw_bytes ?
(((float)tmp->stats.DL_padding_bytes / (float)tmp->stats.DL_raw_bytes) * 100.0) :
0.0,
DL_CRC_FAILED_COLUMN, tmp->stats.DL_CRC_failures,
DL_CRC_HIGH_CODE_RATE_COLUMN, tmp->stats.DL_CRC_high_code_rate,
DL_CRC_PDSCH_LOST_COLUMN, tmp->stats.DL_CRC_PDSCH_lost,
DL_CRC_DUPLICATE_NONZERO_RV, tmp->stats.DL_CRC_Duplicate_Nonzero_rv,
DL_RETX_FRAMES_COLUMN, tmp->stats.DL_retx_frames,
TABLE_COLUMN, tmp,
-1);
}
if (hs->selected_rnti != 0) {
GtkTreeIter *ue_iter = NULL;
mac_lte_ep_t *ep = hs->ep_list;
while (ep != NULL) {
if ((ep->stats.ueid == hs->selected_ueid) &&
(ep->stats.rnti == hs->selected_rnti)) {
ue_iter = &ep->iter;
break;
}
ep = ep->next;
}
if (ue_iter != NULL) {
gtk_tree_selection_select_iter(gtk_tree_view_get_selection(hs->ue_table),
ue_iter);
}
}
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(hs->ue_table));
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
mac_lte_ep_t *ep;
gtk_tree_model_get(model, &iter, TABLE_COLUMN, &ep, -1);
mac_lte_ue_details(ep, hs);
}
}
static void set_filter_expression(guint16 ueid,
guint16 rnti,
Direction_t direction,
gint showRACH,
gint showSRs,
gint showDCTErrors,
const gchar *DCTErrorSubstring,
mac_lte_stat_t *hs)
{
#define MAX_FILTER_LEN 512
static char buffer[MAX_FILTER_LEN];
int offset = 0;
if (showRACH) {
offset += g_snprintf(buffer+offset, MAX_FILTER_LEN-offset,
"(mac-lte.rar or (mac-lte.preamble-sent and mac-lte.ueid == %u)) or (",
ueid);
}
if (showSRs) {
offset += g_snprintf(buffer+offset, MAX_FILTER_LEN-offset,
"(mac-lte.sr-req and mac-lte.ueid == %u) or (",
ueid);
}
if (showDCTErrors) {
if (strlen(DCTErrorSubstring) > 0) {
offset += g_snprintf(buffer+offset, MAX_FILTER_LEN-offset,
"(dct2000.error-comment and (dct2000.comment contains \"%s\")) or (",
DCTErrorSubstring);
}
else {
offset += g_snprintf(buffer+offset, MAX_FILTER_LEN-offset,
"dct2000.error-comment or (");
}
}
if (strlen(hs->filter)) {
offset += g_snprintf(buffer+offset, MAX_FILTER_LEN-offset, "%s and ", hs->filter);
}
switch (direction) {
case UL_Only:
offset += g_snprintf(buffer+offset, MAX_FILTER_LEN-offset, "(mac-lte.direction == 0) and ");
break;
case DL_Only:
offset += g_snprintf(buffer+offset, MAX_FILTER_LEN-offset, "(mac-lte.direction == 1) and ");
break;
default:
break;
}
offset += g_snprintf(buffer+offset, MAX_FILTER_LEN-offset,
"mac-lte.rnti == %u and mac-lte.ueid == %u",
rnti, ueid);
if (showRACH) {
offset += g_snprintf(buffer+offset, MAX_FILTER_LEN-offset, ")");
}
if (showSRs) {
offset += g_snprintf(buffer+offset, MAX_FILTER_LEN-offset, ")");
}
if (showDCTErrors) {
g_snprintf(buffer+offset, MAX_FILTER_LEN-offset, ")");
}
gtk_entry_set_text(GTK_ENTRY(main_display_filter_widget), buffer);
main_filter_packets(&cfile, buffer, TRUE);
}
static void ul_filter_clicked(GtkWindow *win _U_, mac_lte_stat_t* hs)
{
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(hs->ue_table));
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
mac_lte_ep_t *ep;
gtk_tree_model_get(model, &iter, TABLE_COLUMN, &ep, -1);
set_filter_expression(ep->stats.ueid, ep->stats.rnti, UL_Only,
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hs->show_mac_rach_cb)),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hs->show_mac_srs_cb)),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hs->show_dct_errors_cb)),
gtk_entry_get_text(GTK_ENTRY(hs->dct_error_substring_te)),
hs);
}
}
static void dl_filter_clicked(GtkWindow *win _U_, mac_lte_stat_t *hs)
{
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(hs->ue_table));
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
mac_lte_ep_t *ep;
gtk_tree_model_get(model, &iter, TABLE_COLUMN, &ep, -1);
set_filter_expression(ep->stats.ueid, ep->stats.rnti, DL_Only,
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hs->show_mac_rach_cb)),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hs->show_mac_srs_cb)),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hs->show_dct_errors_cb)),
gtk_entry_get_text(GTK_ENTRY(hs->dct_error_substring_te)),
hs);
}
}
static void uldl_filter_clicked(GtkWindow *win _U_, mac_lte_stat_t *hs)
{
GtkTreeSelection *sel;
GtkTreeModel *model;
GtkTreeIter iter;
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(hs->ue_table));
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
mac_lte_ep_t *ep;
gtk_tree_model_get(model, &iter, TABLE_COLUMN, &ep, -1);
set_filter_expression(ep->stats.ueid, ep->stats.rnti, UL_and_DL,
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hs->show_mac_rach_cb)),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hs->show_mac_srs_cb)),
gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hs->show_dct_errors_cb)),
gtk_entry_get_text(GTK_ENTRY(hs->dct_error_substring_te)),
hs);
}
}
static void mac_lte_select_cb(GtkTreeSelection *sel, gpointer data)
{
mac_lte_stat_t *hs = (mac_lte_stat_t *)data;
mac_lte_ep_t *ep;
GtkTreeModel *model;
GtkTreeIter iter;
if (gtk_tree_selection_get_selected(sel, &model, &iter)) {
gtk_tree_model_get(model, &iter, TABLE_COLUMN, &ep, -1);
mac_lte_ue_details(ep, hs);
}
else {
mac_lte_ue_details(NULL, hs);
}
}
static void mac_lte_dct_errors_cb(GtkTreeSelection *sel _U_, gpointer data)
{
mac_lte_stat_t *hs = (mac_lte_stat_t*)data;
guint8 show_dct_errors = gtk_toggle_button_get_active(GTK_TOGGLE_BUTTON(hs->show_dct_errors_cb));
gtk_widget_set_sensitive(hs->dct_error_substring_lb, show_dct_errors);
gtk_widget_set_sensitive(hs->dct_error_substring_te, show_dct_errors);
}
static void win_destroy_cb(GtkWindow *win _U_, gpointer data)
{
mac_lte_stat_t *hs = (mac_lte_stat_t *)data;
remove_tap_listener(hs);
if (hs->mac_lte_stat_dlg_w != NULL) {
window_destroy(hs->mac_lte_stat_dlg_w);
hs->mac_lte_stat_dlg_w = NULL;
}
mac_lte_stat_reset(hs);
g_free(hs->filter);
g_free(hs);
}
static void gtk_mac_lte_stat_init(const char *opt_arg, void *userdata _U_)
{
mac_lte_stat_t *hs;
const char *filter = NULL;
GString *error_string;
GtkWidget *ues_scrolled_window;
GtkWidget *bbox;
GtkWidget *top_level_vbox;
GtkWidget *system_row_hbox;
GtkWidget *common_row_hbox;
GtkWidget *ues_vb;
GtkWidget *selected_ue_hb;
GtkWidget *mac_lte_stat_system_lb;
GtkWidget *mac_lte_stat_common_channel_lb;
GtkWidget *mac_lte_stat_selected_ue_lb;
GtkWidget *selected_ue_vbox[NUM_CHANNEL_COLUMNS];
GtkWidget *selected_ue_column_titles[5];
GtkWidget *mac_lte_stat_filters_lb;
GtkWidget *filter_buttons_hb;
GtkWidget *close_bt;
GtkWidget *help_bt;
GtkListStore *store;
GtkTreeView *tree_view;
GtkCellRenderer *renderer;
GtkTreeViewColumn *column;
GtkTreeSelection *sel;
gchar *display_name;
gchar title[256];
gint i, n;
if (strncmp(opt_arg, "mac-lte,stat,", 13) == 0) {
filter = opt_arg + 13;
}
else {
filter = NULL;
}
hs = (mac_lte_stat_t *)g_malloc(sizeof(mac_lte_stat_t));
hs->ep_list = NULL;
if (filter) {
hs->filter = g_strdup(filter);
}
else {
hs->filter = NULL;
}
display_name = cf_get_display_name(&cfile);
g_snprintf(title, sizeof(title), "Wireshark: LTE MAC Statistics: %s",
display_name);
g_free(display_name);
hs->mac_lte_stat_dlg_w = window_new_with_geom(GTK_WINDOW_TOPLEVEL, title, "LTE MAC Statistics", GTK_WIN_POS_CENTER_ON_PARENT);
gtk_window_set_default_size(GTK_WINDOW(hs->mac_lte_stat_dlg_w), 750, 300);
top_level_vbox = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 3, FALSE);
gtk_container_add(GTK_CONTAINER(hs->mac_lte_stat_dlg_w), top_level_vbox);
gtk_container_set_border_width(GTK_CONTAINER(top_level_vbox), 6);
gtk_widget_show(top_level_vbox);
mac_lte_stat_system_lb = gtk_frame_new("System Data");
system_row_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(mac_lte_stat_system_lb), system_row_hbox);
gtk_container_set_border_width(GTK_CONTAINER(system_row_hbox), 5);
gtk_box_pack_start(GTK_BOX(top_level_vbox), mac_lte_stat_system_lb, FALSE, FALSE, 0);
hs->ul_max_ues_per_tti = gtk_label_new("Max UL UEs/TTI:");
gtk_misc_set_alignment(GTK_MISC(hs->ul_max_ues_per_tti), 0.0f, .5f);
gtk_box_pack_start(GTK_BOX(system_row_hbox), hs->ul_max_ues_per_tti, TRUE, TRUE, 0);
gtk_widget_show(hs->ul_max_ues_per_tti);
hs->dl_max_ues_per_tti = gtk_label_new("Max DL UEs/TTI:");
gtk_misc_set_alignment(GTK_MISC(hs->dl_max_ues_per_tti), 0.0f, .5f);
gtk_box_pack_start(GTK_BOX(system_row_hbox), hs->dl_max_ues_per_tti, TRUE, TRUE, 0);
gtk_widget_show(hs->dl_max_ues_per_tti);
mac_lte_stat_common_channel_lb = gtk_frame_new("Common Channel Data");
common_row_hbox = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(mac_lte_stat_common_channel_lb), common_row_hbox);
gtk_container_set_border_width(GTK_CONTAINER(common_row_hbox), 5);
gtk_box_pack_start(GTK_BOX(top_level_vbox), mac_lte_stat_common_channel_lb, FALSE, FALSE, 0);
hs->common_mib_frames = gtk_label_new("MIBs:");
gtk_misc_set_alignment(GTK_MISC(hs->common_mib_frames), 0.0f, .5f);
gtk_box_pack_start(GTK_BOX(common_row_hbox), hs->common_mib_frames, TRUE, TRUE, 0);
gtk_widget_show(hs->common_mib_frames);
hs->common_sib_frames = gtk_label_new("SIB Frames:");
gtk_misc_set_alignment(GTK_MISC(hs->common_sib_frames), 0.0f, .5f);
gtk_box_pack_start(GTK_BOX(common_row_hbox), hs->common_sib_frames, TRUE, TRUE, 0);
gtk_widget_show(hs->common_sib_frames);
hs->common_sib_bytes = gtk_label_new("SIB Bytes:");
gtk_misc_set_alignment(GTK_MISC(hs->common_sib_bytes), 0.0f, .5f);
gtk_box_pack_start(GTK_BOX(common_row_hbox), hs->common_sib_bytes, TRUE, TRUE, 0);
gtk_widget_show(hs->common_sib_bytes);
hs->common_pch_frames = gtk_label_new("PCH Frames:");
gtk_misc_set_alignment(GTK_MISC(hs->common_pch_frames), 0.0f, .5f);
gtk_box_pack_start(GTK_BOX(common_row_hbox), hs->common_pch_frames, TRUE, TRUE, 0);
gtk_widget_show(hs->common_pch_frames);
hs->common_pch_bytes = gtk_label_new("PCH Bytes:");
gtk_misc_set_alignment(GTK_MISC(hs->common_pch_bytes), 0.0f, .5f);
gtk_box_pack_start(GTK_BOX(common_row_hbox), hs->common_pch_bytes, TRUE, TRUE, 0);
gtk_widget_show(hs->common_pch_bytes);
hs->common_pch_paging_ids = gtk_label_new("PCH Paging IDs:");
gtk_misc_set_alignment(GTK_MISC(hs->common_pch_paging_ids), 0.0f, .5f);
gtk_box_pack_start(GTK_BOX(common_row_hbox), hs->common_pch_paging_ids, TRUE, TRUE, 0);
gtk_widget_show(hs->common_pch_paging_ids);
hs->common_rar_frames = gtk_label_new("RAR Frames:");
gtk_misc_set_alignment(GTK_MISC(hs->common_rar_frames), 0.0f, .5f);
gtk_box_pack_start(GTK_BOX(common_row_hbox), hs->common_rar_frames, TRUE, TRUE, 0);
gtk_widget_show(hs->common_rar_frames);
hs->common_rar_entries = gtk_label_new("RAR Entries:");
gtk_misc_set_alignment(GTK_MISC(hs->common_rar_entries), 0.0f, .5f);
gtk_box_pack_start(GTK_BOX(common_row_hbox), hs->common_rar_entries, TRUE, TRUE, 0);
gtk_widget_show(hs->common_rar_entries);
hs->mac_lte_stat_ues_lb = gtk_frame_new("UL/DL-SCH Data (0 UEs)");
ues_vb = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_container_add(GTK_CONTAINER(hs->mac_lte_stat_ues_lb), ues_vb);
gtk_container_set_border_width(GTK_CONTAINER(ues_vb), 5);
ues_scrolled_window = scrolled_window_new(NULL, NULL);
gtk_box_pack_start(GTK_BOX(ues_vb), ues_scrolled_window, TRUE, TRUE, 0);
gtk_scrolled_window_set_shadow_type(GTK_SCROLLED_WINDOW(ues_scrolled_window),
GTK_SHADOW_IN);
store = gtk_list_store_new(NUM_UE_COLUMNS, G_TYPE_INT, G_TYPE_STRING, G_TYPE_INT,
G_TYPE_INT, G_TYPE_INT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_INT,
G_TYPE_INT, G_TYPE_INT, G_TYPE_FLOAT, G_TYPE_FLOAT, G_TYPE_INT,
G_TYPE_INT, G_TYPE_INT, G_TYPE_INT, G_TYPE_INT,
G_TYPE_POINTER);
hs->ue_table = GTK_TREE_VIEW(tree_view_new(GTK_TREE_MODEL(store)));
gtk_container_add(GTK_CONTAINER (ues_scrolled_window), GTK_WIDGET(hs->ue_table));
g_object_unref(G_OBJECT(store));
tree_view = hs->ue_table;
gtk_tree_view_set_headers_visible(tree_view, TRUE);
gtk_tree_view_set_headers_clickable(tree_view, TRUE);
for (i = 0; i < TABLE_COLUMN; i++) {
if ((i == UL_PADDING_PERCENT_COLUMN) ||
(i == DL_PADDING_PERCENT_COLUMN)) {
renderer = gtk_cell_renderer_progress_new();
column = gtk_tree_view_column_new_with_attributes(ue_titles[i], renderer,
"text", i,
"value", i,
NULL);
}
else {
renderer = gtk_cell_renderer_text_new();
column = gtk_tree_view_column_new_with_attributes(ue_titles[i], renderer,
"text", i, NULL);
}
gtk_tree_view_column_set_sort_column_id(column, i);
if (i == 0) {
gtk_tree_view_column_set_expand(column, TRUE);
} else {
g_object_set(G_OBJECT(renderer), "xalign", 1.0, NULL);
}
gtk_tree_view_column_set_sizing(column, GTK_TREE_VIEW_COLUMN_AUTOSIZE);
gtk_tree_view_column_set_resizable(column, TRUE);
gtk_tree_view_append_column(tree_view, column);
}
sel = gtk_tree_view_get_selection(GTK_TREE_VIEW(hs->ue_table));
gtk_tree_selection_set_mode(sel, GTK_SELECTION_SINGLE);
g_signal_connect(sel, "changed", G_CALLBACK(mac_lte_select_cb), hs);
gtk_box_pack_start(GTK_BOX(top_level_vbox), hs->mac_lte_stat_ues_lb, TRUE, TRUE, 0);
mac_lte_stat_selected_ue_lb = gtk_frame_new("Selected UE details");
selected_ue_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6, FALSE);
gtk_container_add(GTK_CONTAINER(mac_lte_stat_selected_ue_lb), selected_ue_hb);
gtk_container_set_border_width(GTK_CONTAINER(selected_ue_hb), 5);
selected_ue_vbox[0] = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_box_pack_start(GTK_BOX(selected_ue_hb), selected_ue_vbox[0], TRUE, TRUE, 0);
selected_ue_column_titles[0] = gtk_label_new("");
gtk_misc_set_alignment(GTK_MISC(selected_ue_column_titles[0]), 0.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(selected_ue_vbox[0]), selected_ue_column_titles[0], FALSE, FALSE, 0);
for (n=1; n < 5; n++) {
selected_ue_column_titles[n] = gtk_label_new(selected_ue_row_names[n-1]);
gtk_misc_set_alignment(GTK_MISC(selected_ue_column_titles[n]), 0.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(selected_ue_vbox[0]), selected_ue_column_titles[n], FALSE, FALSE, 0);
gtk_widget_show(selected_ue_column_titles[n]);
}
for (i=CCCH_COLUMN; i < NUM_CHANNEL_COLUMNS; i++) {
selected_ue_vbox[i] = ws_gtk_box_new(GTK_ORIENTATION_VERTICAL, 0, FALSE);
gtk_box_pack_start(GTK_BOX(selected_ue_hb), selected_ue_vbox[i], TRUE, TRUE, 0);
hs->selected_ue_column_entry[i][0] = gtk_label_new(channel_titles[i-1]);
gtk_misc_set_alignment(GTK_MISC(hs->selected_ue_column_entry[i][0]), 0.5f, 0.0f);
gtk_box_pack_start(GTK_BOX(selected_ue_vbox[i]), hs->selected_ue_column_entry[i][0], FALSE, FALSE, 0);
for (n=1; n < 5; n++) {
hs->selected_ue_column_entry[i][n] = gtk_label_new("0");
gtk_misc_set_alignment(GTK_MISC(hs->selected_ue_column_entry[i][n]), 1.0f, 0.0f);
gtk_box_pack_start(GTK_BOX(selected_ue_vbox[i]), hs->selected_ue_column_entry[i][n], FALSE, FALSE, 0);
gtk_widget_show(hs->selected_ue_column_entry[i][n]);
}
}
gtk_box_pack_start(GTK_BOX(top_level_vbox), mac_lte_stat_selected_ue_lb, FALSE, FALSE, 0);
mac_lte_stat_filters_lb = gtk_frame_new("Filter on UE");
filter_buttons_hb = ws_gtk_box_new(GTK_ORIENTATION_HORIZONTAL, 6, FALSE);
gtk_container_add(GTK_CONTAINER(mac_lte_stat_filters_lb), filter_buttons_hb);
gtk_container_set_border_width(GTK_CONTAINER(filter_buttons_hb), 2);
gtk_box_pack_start(GTK_BOX(top_level_vbox), mac_lte_stat_filters_lb, FALSE, FALSE, 0);
hs->ul_filter_bt = gtk_button_new_with_label("Set UL display filter on selected this UE");
gtk_box_pack_start(GTK_BOX(filter_buttons_hb), hs->ul_filter_bt, FALSE, FALSE, 0);
g_signal_connect(hs->ul_filter_bt, "clicked", G_CALLBACK(ul_filter_clicked), hs);
gtk_widget_set_sensitive(hs->ul_filter_bt, FALSE);
gtk_widget_show(hs->ul_filter_bt);
gtk_widget_set_tooltip_text(hs->ul_filter_bt,
"Generate and set a filter showing only UL frames with selected RNTI and UEId");
hs->dl_filter_bt = gtk_button_new_with_label("Set DL display filter on selected this UE");
gtk_box_pack_start(GTK_BOX(filter_buttons_hb), hs->dl_filter_bt, FALSE, FALSE, 0);
g_signal_connect(hs->dl_filter_bt, "clicked", G_CALLBACK(dl_filter_clicked), hs);
gtk_widget_set_sensitive(hs->dl_filter_bt, FALSE);
gtk_widget_show(hs->dl_filter_bt);
gtk_widget_set_tooltip_text(hs->dl_filter_bt,
"Generate and set a filter showing only DL frames with selected RNTI and UEId");
hs->uldl_filter_bt = gtk_button_new_with_label("Set UL / DL display filter on selected this UE");
gtk_box_pack_start(GTK_BOX(filter_buttons_hb), hs->uldl_filter_bt, FALSE, FALSE, 0);
g_signal_connect(hs->uldl_filter_bt, "clicked", G_CALLBACK(uldl_filter_clicked), hs);
gtk_widget_set_sensitive(hs->uldl_filter_bt, FALSE);
gtk_widget_show(hs->uldl_filter_bt);
gtk_widget_set_tooltip_text(hs->uldl_filter_bt,
"Generate and set a filter showing only frames with selected RNTI and UEId");
hs->show_mac_rach_cb = gtk_check_button_new_with_mnemonic("Show MAC RACH");
gtk_widget_set_sensitive(hs->show_mac_rach_cb, FALSE);
gtk_box_pack_start(GTK_BOX(filter_buttons_hb), hs->show_mac_rach_cb, TRUE, TRUE, 0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(hs->show_mac_rach_cb), FALSE);
gtk_widget_set_tooltip_text(hs->show_mac_rach_cb, "When checked, generated filters will show "
"MAC RACH attempts for the UE");
hs->show_mac_srs_cb = gtk_check_button_new_with_mnemonic("Show MAC SRs");
gtk_widget_set_sensitive(hs->show_mac_srs_cb, FALSE);
gtk_box_pack_start(GTK_BOX(filter_buttons_hb), hs->show_mac_srs_cb, TRUE, TRUE, 0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(hs->show_mac_srs_cb), FALSE);
gtk_widget_set_tooltip_text(hs->show_mac_srs_cb, "When checked, generated filters will show "
"MAC SRs for the UE");
hs->show_dct_errors_cb = gtk_check_button_new_with_mnemonic("Show DCT2000 error strings");
gtk_box_pack_start(GTK_BOX(filter_buttons_hb), hs->show_dct_errors_cb, TRUE, TRUE, 0);
gtk_toggle_button_set_active(GTK_TOGGLE_BUTTON(hs->show_dct_errors_cb), FALSE);
g_signal_connect(hs->show_dct_errors_cb, "toggled", G_CALLBACK(mac_lte_dct_errors_cb), hs);
gtk_widget_set_tooltip_text(hs->show_dct_errors_cb, "When checked, generated filters will "
"include DCT2000 error strings");
gtk_widget_set_sensitive(hs->show_dct_errors_cb, FALSE);
hs->dct_error_substring_lb = gtk_label_new("...containing");
gtk_box_pack_start(GTK_BOX(filter_buttons_hb), hs->dct_error_substring_lb, FALSE, FALSE, 0);
gtk_widget_show(hs->dct_error_substring_lb);
gtk_widget_set_sensitive(hs->dct_error_substring_lb, FALSE);
hs->dct_error_substring_te = gtk_entry_new();
gtk_box_pack_start(GTK_BOX(filter_buttons_hb), hs->dct_error_substring_te, FALSE, FALSE, 0);
gtk_widget_show(hs->dct_error_substring_te);
gtk_widget_set_sensitive(hs->dct_error_substring_te, FALSE);
gtk_widget_set_tooltip_text(hs->dct_error_substring_te,
"If given, only match error strings containing this substring");
error_string = register_tap_listener("mac-lte", hs,
filter, 0,
mac_lte_stat_reset,
mac_lte_stat_packet,
mac_lte_stat_draw);
if (error_string) {
simple_dialog(ESD_TYPE_ERROR, ESD_BTN_OK, "%s", error_string->str);
g_string_free(error_string, TRUE);
g_free(hs);
return;
}
bbox = dlg_button_row_new (GTK_STOCK_CLOSE, GTK_STOCK_HELP, NULL);
gtk_box_pack_end (GTK_BOX(top_level_vbox), bbox, FALSE, FALSE, 0);
close_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_CLOSE);
window_set_cancel_button(hs->mac_lte_stat_dlg_w, close_bt, window_cancel_button_cb);
help_bt = (GtkWidget *)g_object_get_data(G_OBJECT(bbox), GTK_STOCK_HELP);
g_signal_connect(help_bt, "clicked", G_CALLBACK(topic_cb), (gpointer)HELP_STATS_LTE_MAC_TRAFFIC_DIALOG);
g_signal_connect(hs->mac_lte_stat_dlg_w, "delete_event", G_CALLBACK(window_delete_event_cb), NULL);
g_signal_connect(hs->mac_lte_stat_dlg_w, "destroy", G_CALLBACK(win_destroy_cb), hs);
gtk_widget_show_all(hs->mac_lte_stat_dlg_w);
window_present(hs->mac_lte_stat_dlg_w);
cf_retap_packets(&cfile);
gdk_window_raise(gtk_widget_get_window(hs->mac_lte_stat_dlg_w));
}
void register_tap_listener_mac_lte_stat(void)
{
register_param_stat(&mac_lte_stat_dlg, "_MAC", REGISTER_STAT_GROUP_TELEPHONY_LTE);
}
