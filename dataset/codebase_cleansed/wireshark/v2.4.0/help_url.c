const char *
topic_online_url(topic_action_e action)
{
switch(action) {
case(ONLINEPAGE_HOME):
return "https://www.wireshark.org";
break;
case(ONLINEPAGE_WIKI):
return "https://wiki.wireshark.org";
break;
case(ONLINEPAGE_DOWNLOAD):
return "https://www.wireshark.org/download.html";
break;
case(ONLINEPAGE_DOCS):
return "https://www.wireshark.org/docs/";
break;
case(ONLINEPAGE_USERGUIDE):
return "https://www.wireshark.org/docs/wsug_html_chunked/";
break;
case(ONLINEPAGE_FAQ):
return "http://www.wireshark.org/faq.html";
break;
case(ONLINEPAGE_ASK):
return "https://ask.wireshark.org";
break;
case(ONLINEPAGE_SAMPLE_FILES):
return "https://wiki.wireshark.org/SampleCaptures";
break;
case(ONLINEPAGE_CAPTURE_SETUP):
return "https://wiki.wireshark.org/CaptureSetup";
break;
case(ONLINEPAGE_NETWORK_MEDIA):
return "https://wiki.wireshark.org/CaptureSetup/NetworkMedia";
break;
case(ONLINEPAGE_SAMPLE_CAPTURES):
return "https://wiki.wireshark.org/SampleCaptures";
break;
case(ONLINEPAGE_SECURITY):
return "https://wiki.wireshark.org/Security";
break;
case(ONLINEPAGE_CHIMNEY):
return "https://wiki.wireshark.org/CaptureSetup/Offloading#chimney";
break;
default:
return NULL;
}
}
gchar *
user_guide_url(const gchar *page) {
GString *url = g_string_new("");
#ifdef HHC_DIR
HWND hw;
g_string_printf(url, "%s\\user-guide.chm::/wsug_chm/%s>Wireshark Help",
get_datafile_dir(), page);
hw = HtmlHelpW(NULL,
utf_8to16(url->str),
HH_DISPLAY_TOPIC, 0);
if(hw != NULL) {
g_string_free(url, TRUE );
return NULL;
}
#endif
#ifdef DOC_DIR
if (g_file_test(DOC_DIR "/guides/wsug_html_chunked", G_FILE_TEST_IS_DIR)) {
g_string_printf(url, "file://" DOC_DIR "/guides/wsug_html_chunked/%s", page);
} else {
#endif
g_string_printf(url, "https://www.wireshark.org/docs/wsug_html_chunked/%s", page);
#ifdef DOC_DIR
}
#endif
return g_string_free(url, FALSE);
}
gchar *
topic_action_url(topic_action_e action)
{
gchar *url;
url = g_strdup(topic_online_url(action));
if(url != NULL) {
return url;
}
switch(action) {
case(LOCALPAGE_MAN_WIRESHARK):
url = data_file_url("wireshark.html");
break;
case(LOCALPAGE_MAN_WIRESHARK_FILTER):
url = data_file_url("wireshark-filter.html");
break;
case(LOCALPAGE_MAN_CAPINFOS):
url = data_file_url("capinfos.html");
break;
case(LOCALPAGE_MAN_DUMPCAP):
url = data_file_url("dumpcap.html");
break;
case(LOCALPAGE_MAN_EDITCAP):
url = data_file_url("editcap.html");
break;
case(LOCALPAGE_MAN_MERGECAP):
url = data_file_url("mergecap.html");
break;
case(LOCALPAGE_MAN_RAWSHARK):
url = data_file_url("rawshark.html");
break;
case(LOCALPAGE_MAN_REORDERCAP):
url = data_file_url("reordercap.html");
break;
case(LOCALPAGE_MAN_TEXT2PCAP):
url = data_file_url("text2pcap.html");
break;
case(LOCALPAGE_MAN_TSHARK):
url = data_file_url("tshark.html");
break;
case(HELP_CONTENT):
url = user_guide_url( "index.html");
break;
case(HELP_CAPTURE_OPTIONS_DIALOG):
url = user_guide_url("ChCapCaptureOptions.html");
break;
case(HELP_CAPTURE_FILTERS_DIALOG):
url = user_guide_url("ChWorkDefineFilterSection.html");
break;
case(HELP_DISPLAY_FILTERS_DIALOG):
url = user_guide_url("ChWorkDefineFilterSection.html");
break;
case(HELP_FILTER_EXPRESSION_DIALOG):
url = user_guide_url("ChWorkFilterAddExpressionSection.html");
break;
case(HELP_COLORING_RULES_DIALOG):
url = user_guide_url("ChCustColorizationSection.html");
break;
case(HELP_CONFIG_PROFILES_DIALOG):
url = user_guide_url("ChCustConfigProfilesSection.html");
break;
case (HELP_MANUAL_ADDR_RESOLVE_DIALOG):
url = user_guide_url("ChManualAddressResolveSection.html");
break;
case(HELP_PRINT_DIALOG):
url = user_guide_url("ChIOPrintSection.html");
break;
case(HELP_FIND_DIALOG):
url = user_guide_url("ChWorkFindPacketSection.html");
break;
case(HELP_FIREWALL_DIALOG):
url = user_guide_url("ChUseToolsMenuSection.html");
break;
case(HELP_GOTO_DIALOG):
url = user_guide_url("ChWorkGoToPacketSection.html");
break;
case(HELP_CAPTURE_INTERFACES_DIALOG):
url = user_guide_url("ChCapInterfaceSection.html");
break;
case(HELP_CAPTURE_INFO_DIALOG):
url = user_guide_url("ChCapRunningSection.html");
break;
case(HELP_CAPTURE_MANAGE_INTERFACES_DIALOG):
url = user_guide_url("ChCapManageInterfacesSection.html");
break;
case(HELP_ENABLED_PROTOCOLS_DIALOG):
url = user_guide_url("ChCustProtocolDissectionSection.html");
break;
case(HELP_ENABLED_HEURISTICS_DIALOG):
url = user_guide_url("ChCustProtocolDissectionSection.html");
break;
case(HELP_DECODE_AS_DIALOG):
url = user_guide_url("ChCustProtocolDissectionSection.html");
break;
case(HELP_DECODE_AS_SHOW_DIALOG):
url = user_guide_url("ChCustProtocolDissectionSection.html");
break;
case(HELP_FOLLOW_STREAM_DIALOG):
url = user_guide_url("ChAdvFollowTCPSection.html");
break;
case(HELP_SHOW_PACKET_BYTES_DIALOG):
url = user_guide_url("ChAdvShowPacketBytes.html");
break;
case(HELP_EXPERT_INFO_DIALOG):
url = user_guide_url("ChAdvExpert.html");
break;
#ifdef HAVE_EXTCAP
case(HELP_EXTCAP_OPTIONS_DIALOG):
url = data_file_url("extcap.html");
break;
#endif
case(HELP_STATS_SUMMARY_DIALOG):
url = user_guide_url("ChStatSummary.html");
break;
case(HELP_STATS_PROTO_HIERARCHY_DIALOG):
url = user_guide_url("ChStatHierarchy.html");
break;
case(HELP_STATS_ENDPOINTS_DIALOG):
url = user_guide_url("ChStatEndpoints.html");
break;
case(HELP_STATS_CONVERSATIONS_DIALOG):
url = user_guide_url("ChStatConversations.html");
break;
case(HELP_STATS_IO_GRAPH_DIALOG):
url = user_guide_url("ChStatIOGraphs.html");
break;
case(HELP_STATS_COMPARE_FILES_DIALOG):
url = user_guide_url("ChStatCompareCaptureFiles.html");
break;
case(HELP_STATS_LTE_MAC_TRAFFIC_DIALOG):
url = user_guide_url("ChTelLTEMACTraffic.html");
break;
case(HELP_STATS_LTE_RLC_TRAFFIC_DIALOG):
url = user_guide_url("ChTelLTERLCTraffic.html");
break;
case(HELP_STATS_WLAN_TRAFFIC_DIALOG):
url = user_guide_url("ChStatWLANTraffic.html");
break;
case(HELP_FILESET_DIALOG):
url = user_guide_url("ChIOFileSetSection.html");
break;
case(HELP_CAPTURE_INTERFACE_OPTIONS_DIALOG):
url = user_guide_url("ChCustPreferencesSection.html#ChCustInterfaceOptionsSection");
break;
case(HELP_CAPTURE_INTERFACES_DETAILS_DIALOG):
url = user_guide_url("ChCapInterfaceDetailsSection.html");
break;
case(HELP_PREFERENCES_DIALOG):
url = user_guide_url("ChCustPreferencesSection.html");
break;
case(HELP_EXPORT_FILE_DIALOG):
case(HELP_EXPORT_FILE_WIN32_DIALOG):
url = user_guide_url("ChIOExportSection.html");
break;
case(HELP_EXPORT_BYTES_DIALOG):
case(HELP_EXPORT_BYTES_WIN32_DIALOG):
url = user_guide_url("ChIOExportSection.html#ChIOExportSelectedDialog");
break;
case(HELP_EXPORT_OBJECT_LIST):
url = user_guide_url("ChIOExportSection.html#ChIOExportObjectsDialog");
break;
case(HELP_OPEN_DIALOG):
case(HELP_OPEN_WIN32_DIALOG):
url = user_guide_url("ChIOOpenSection.html");
break;
case(HELP_MERGE_DIALOG):
case(HELP_MERGE_WIN32_DIALOG):
url = user_guide_url("ChIOMergeSection.html");
break;
case(HELP_IMPORT_DIALOG):
url = user_guide_url("ChIOImportSection.html");
break;
case(HELP_SAVE_DIALOG):
case(HELP_SAVE_WIN32_DIALOG):
url = user_guide_url("ChIOSaveSection.html");
break;
case(HELP_TIME_SHIFT_DIALOG):
url = user_guide_url("ChWorkShiftTimePacketSection.html");
break;
case(HELP_FILTER_SAVE_DIALOG):
url = user_guide_url("ChWorkFilterSaveSection.html");
break;
case(HELP_TELEPHONY_VOIP_CALLS_DIALOG):
url = user_guide_url("ChTelVoipCalls.html");
break;
case(HELP_RTP_ANALYSIS_DIALOG):
url = user_guide_url("ChTelRTPAnalysis.html");
break;
case(HELP_NEW_PACKET_DIALOG):
url = user_guide_url("ChapterWork.html#ChWorkPacketSepView");
break;
case(HELP_IAX2_ANALYSIS_DIALOG):
url = user_guide_url("ChTelIAX2Analysis.html");
break;
case(HELP_TELEPHONY_RTP_PLAYER_DIALOG):
url = user_guide_url("ChTelRtpPlayer.html");
break;
case(TOPIC_ACTION_NONE):
default:
g_assert_not_reached();
}
return url;
}
