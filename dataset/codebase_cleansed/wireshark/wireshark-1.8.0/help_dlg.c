void help_topic_html(const gchar *topic) {
GString *url;
#ifdef HHC_DIR
HWND hw;
url = g_string_new("");
g_string_append_printf(url, "%s\\user-guide.chm::/wsug_chm/%s>Wireshark Help",
get_datafile_dir(), topic);
hw = HtmlHelpW(NULL,
utf_8to16(url->str),
HH_DISPLAY_TOPIC, 0);
g_string_free(url, TRUE );
if(hw != NULL) {
return;
}
#endif
url = g_string_new("");
#ifdef DOC_DIR
if (g_file_test(DOC_DIR "/guides/wsug_html_chunked", G_FILE_TEST_IS_DIR)) {
g_string_append_printf(url, "file://" DOC_DIR "/guides/wsug_html_chunked/%s", topic);
} else {
#endif
g_string_append_printf(url, "http://www.wireshark.org/docs/wsug_html_chunked/%s", topic);
#ifdef DOC_DIR
}
#endif
browser_open_url(url->str);
g_string_free(url, TRUE );
}
void help_redraw(void)
{
GSList *help_page_ent;
help_page_t *help_page;
if (help_w != NULL) {
for (help_page_ent = help_text_pages; help_page_ent != NULL;
help_page_ent = g_slist_next(help_page_ent))
{
help_page = (help_page_t *)help_page_ent->data;
text_page_redraw(help_page->page, help_page->pathname);
}
}
}
const char *
topic_online_url(topic_action_e action)
{
switch(action) {
case(ONLINEPAGE_HOME):
return "http://www.wireshark.org";
break;
case(ONLINEPAGE_WIKI):
return "http://wiki.wireshark.org";
break;
case(ONLINEPAGE_DOWNLOAD):
return "http://www.wireshark.org/download.html";
break;
case(ONLINEPAGE_USERGUIDE):
return "http://www.wireshark.org/docs/wsug_html_chunked/";
break;
case(ONLINEPAGE_FAQ):
return "http://www.wireshark.org/faq.html";
break;
case(ONLINEPAGE_SAMPLE_FILES):
return "http://wiki.wireshark.org/SampleCaptures";
break;
case(ONLINEPAGE_CAPTURE_SETUP):
return "http://wiki.wireshark.org/CaptureSetup";
break;
case(ONLINEPAGE_NETWORK_MEDIA):
return "http://wiki.wireshark.org/CaptureSetup/NetworkMedia";
break;
case(ONLINEPAGE_SAMPLE_CAPTURES):
return "http://wiki.wireshark.org/SampleCaptures";
break;
case(ONLINEPAGE_SECURITY):
return "http://wiki.wireshark.org/Security";
break;
case(ONLINEPAGE_CHIMNEY):
return "http://wiki.wireshark.org/CaptureSetup/Offloading#chimney";
break;
default:
return NULL;
}
}
static void
topic_action(topic_action_e action)
{
const char *online_url;
online_url = topic_online_url(action);
if(online_url != NULL) {
browser_open_url (online_url);
return;
}
switch(action) {
case(LOCALPAGE_MAN_WIRESHARK):
browser_open_data_file("wireshark.html");
break;
case(LOCALPAGE_MAN_WIRESHARK_FILTER):
browser_open_data_file("wireshark-filter.html");
break;
case(LOCALPAGE_MAN_TSHARK):
browser_open_data_file("tshark.html");
break;
case(LOCALPAGE_MAN_RAWSHARK):
browser_open_data_file("rawshark.html");
break;
case(LOCALPAGE_MAN_DUMPCAP):
browser_open_data_file("dumpcap.html");
break;
case(LOCALPAGE_MAN_MERGECAP):
browser_open_data_file("mergecap.html");
break;
case(LOCALPAGE_MAN_EDITCAP):
browser_open_data_file("editcap.html");
break;
case(LOCALPAGE_MAN_TEXT2PCAP):
browser_open_data_file("text2pcap.html");
break;
case(HELP_CONTENT):
help_topic_html( "index.html");
break;
case(HELP_CAPTURE_OPTIONS_DIALOG):
help_topic_html("ChCapCaptureOptions.html");
break;
case(HELP_CAPTURE_FILTERS_DIALOG):
help_topic_html("ChWorkDefineFilterSection.html");
break;
case(HELP_DISPLAY_FILTERS_DIALOG):
help_topic_html("ChWorkDefineFilterSection.html");
break;
case(HELP_COLORING_RULES_DIALOG):
help_topic_html("ChCustColorizationSection.html");
break;
case(HELP_CONFIG_PROFILES_DIALOG):
help_topic_html("ChCustConfigProfilesSection.html");
break;
case (HELP_MANUAL_ADDR_RESOLVE_DIALOG):
help_topic_html("ChManualAddressResolveSection.html");
break;
case(HELP_PRINT_DIALOG):
help_topic_html("ChIOPrintSection.html");
break;
case(HELP_FIND_DIALOG):
help_topic_html("ChWorkFindPacketSection.html");
break;
case(HELP_FIREWALL_DIALOG):
help_topic_html("ChUseToolsMenuSection.html");
break;
case(HELP_GOTO_DIALOG):
help_topic_html("ChWorkGoToPacketSection.html");
break;
case(HELP_CAPTURE_INTERFACES_DIALOG):
help_topic_html("ChCapInterfaceSection.html");
break;
case(HELP_CAPTURE_INFO_DIALOG):
help_topic_html("ChCapRunningSection.html");
break;
case(HELP_ENABLED_PROTOCOLS_DIALOG):
help_topic_html("ChCustProtocolDissectionSection.html");
break;
case(HELP_DECODE_AS_DIALOG):
help_topic_html("ChCustProtocolDissectionSection.html");
break;
case(HELP_DECODE_AS_SHOW_DIALOG):
help_topic_html("ChCustProtocolDissectionSection.html");
break;
case(HELP_FOLLOW_STREAM_DIALOG):
help_topic_html("ChAdvFollowTCPSection.html");
break;
case(HELP_EXPERT_INFO_DIALOG):
help_topic_html("ChAdvExpert.html");
break;
case(HELP_STATS_SUMMARY_DIALOG):
help_topic_html("ChStatSummary.html");
break;
case(HELP_STATS_PROTO_HIERARCHY_DIALOG):
help_topic_html("ChStatHierarchy.html");
break;
case(HELP_STATS_ENDPOINTS_DIALOG):
help_topic_html("ChStatEndpoints.html");
break;
case(HELP_STATS_CONVERSATIONS_DIALOG):
help_topic_html("ChStatConversations.html");
break;
case(HELP_STATS_IO_GRAPH_DIALOG):
help_topic_html("ChStatIOGraphs.html");
break;
case(HELP_STATS_COMPARE_FILES_DIALOG):
help_topic_html("ChStatCompareCaptureFiles.html");
break;
case(HELP_STATS_LTE_MAC_TRAFFIC_DIALOG):
help_topic_html("ChTelLTEMACTraffic.html");
break;
case(HELP_STATS_LTE_RLC_TRAFFIC_DIALOG):
help_topic_html("ChTelLTERLCTraffic.html");
break;
case(HELP_STATS_WLAN_TRAFFIC_DIALOG):
help_topic_html("ChStatWLANTraffic.html");
break;
case(HELP_FILESET_DIALOG):
help_topic_html("ChIOFileSetSection.html");
break;
case(HELP_CAPTURE_INTERFACE_OPTIONS_DIALOG):
help_topic_html("ChCustPreferencesSection.html#ChCustInterfaceOptionsSection");
break;
case(HELP_CAPTURE_INTERFACES_DETAILS_DIALOG):
help_topic_html("ChCapInterfaceDetailsSection.html");
break;
case(HELP_PREFERENCES_DIALOG):
help_topic_html("ChCustPreferencesSection.html");
break;
case(HELP_EXPORT_FILE_DIALOG):
case(HELP_EXPORT_FILE_WIN32_DIALOG):
help_topic_html("ChIOExportSection.html");
break;
case(HELP_EXPORT_BYTES_DIALOG):
case(HELP_EXPORT_BYTES_WIN32_DIALOG):
help_topic_html("ChIOExportSection.html#ChIOExportSelectedDialog");
break;
case(HELP_EXPORT_OBJECT_LIST):
help_topic_html("ChIOExportSection.html#ChIOExportObjectsDialog");
break;
case(HELP_OPEN_DIALOG):
case(HELP_OPEN_WIN32_DIALOG):
help_topic_html("ChIOOpenSection.html");
break;
case(HELP_MERGE_DIALOG):
case(HELP_MERGE_WIN32_DIALOG):
help_topic_html("ChIOMergeSection.html");
break;
case(HELP_IMPORT_DIALOG):
help_topic_html("ChIOImportSection.html");
break;
case(HELP_SAVE_DIALOG):
case(HELP_SAVE_WIN32_DIALOG):
help_topic_html("ChIOSaveSection.html");
break;
case(HELP_TIME_SHIFT_DIALOG):
help_topic_html("ChWorkShiftTimePacketSection.html");
break;
case(HELP_FILTER_SAVE_DIALOG):
help_topic_html("ChWorkFilterSaveSection.html");
break;
default:
g_assert_not_reached();
}
}
void
topic_cb(GtkWidget *w _U_, topic_action_e action)
{
topic_action(action);
}
gboolean
topic_menu_cb(GtkWidget *w _U_, GdkEventButton *event _U_, gpointer user_data)
{
topic_action((topic_action_e)GPOINTER_TO_INT(user_data));
return TRUE;
}
