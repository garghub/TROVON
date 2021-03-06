static int
smbsids_packet(void *pss _U_, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *psi _U_)
{
return 1;
}
static void
enum_sids(gpointer key, gpointer value, gpointer userdata _U_)
{
const char *sid = (const char *)key;
const char *name = (const char *)value;
printf("%-60s %s\n", sid, name);
}
static void
smbsids_draw(void *pss _U_)
{
printf("\n");
printf("===================================================================\n");
printf("SMB SID List:\n");
g_hash_table_foreach(sid_name_table, enum_sids, NULL);
printf("===================================================================\n");
}
static void
smbsids_init(const char *opt_arg _U_, void *userdata _U_)
{
GString *error_string;
if (!sid_name_snooping) {
fprintf(stderr, "The -z smb,sids function needs SMB/SID-Snooping to be enabled.\n");
fprintf(stderr, "Either enable Edit/Preferences/Protocols/SMB/Snoop SID name mappings in wireshark\n");
fprintf(stderr, "or override the preference file by specifying\n");
fprintf(stderr, " -o \"smb.sid_name_snooping=TRUE\"\n");
fprintf(stderr, "on the tshark command line.\n");
exit(1);
}
error_string = register_tap_listener("smb", NULL, NULL, 0, NULL, smbsids_packet, smbsids_draw);
if (error_string) {
fprintf(stderr, "tshark: Couldn't register smb,sids tap:%s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_smbsids(void)
{
register_stat_tap_ui(&smbsids_ui, NULL);
}
