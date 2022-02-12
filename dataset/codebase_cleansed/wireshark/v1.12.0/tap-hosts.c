static void
ipv4_hash_table_print_resolved(gpointer key _U_, gpointer value, gpointer user_data _U_)
{
hashipv4_t *ipv4_hash_table_entry = (hashipv4_t *)value;
if((ipv4_hash_table_entry->flags & DUMMY_ADDRESS_ENTRY)== DUMMY_ADDRESS_ENTRY){
printf("%s\t%s",
ipv4_hash_table_entry->ip,
ipv4_hash_table_entry->name);
}
}
static void
ipv6_hash_table_print_resolved(gpointer key _U_, gpointer value, gpointer user_data _U_)
{
hashipv6_t *ipv6_hash_table_entry = (hashipv6_t *)value;
if((ipv6_hash_table_entry->flags & DUMMY_ADDRESS_ENTRY)== DUMMY_ADDRESS_ENTRY){
printf("%s\t%s",
ipv6_hash_table_entry->ip6,
ipv6_hash_table_entry->name);
}
}
static void
hosts_draw(void *dummy _U_)
{
GHashTable *ipv4_hash_table;
GHashTable *ipv6_hash_table;
printf("# TShark hosts output\n");
printf("#\n");
printf("# Host data gathered from %s\n", cfile.filename);
printf("\n");
ipv4_hash_table = get_ipv4_hash_table();
if(ipv4_hash_table){
g_hash_table_foreach( ipv4_hash_table, ipv4_hash_table_print_resolved, NULL);
}
ipv6_hash_table = get_ipv6_hash_table();
if(ipv6_hash_table){
g_hash_table_foreach( ipv6_hash_table, ipv6_hash_table_print_resolved, NULL);
}
}
static void
hosts_init(const char *opt_arg, void* userdata _U_)
{
GString *error_string;
gchar **tokens;
gint opt_count;
dump_v4 = FALSE;
dump_v6 = FALSE;
if(strcmp(TAP_NAME, opt_arg)==0) {
dump_v4 = TRUE;
dump_v6 = TRUE;
} else {
tokens = g_strsplit(opt_arg,",", 0);
opt_count=0;
while (tokens[opt_count]) {
if (strcmp("ipv4", tokens[opt_count]) == 0) {
dump_v4 = TRUE;
} else if (strcmp("ipv6", tokens[opt_count]) == 0) {
dump_v6 = TRUE;
} else if (opt_count > 0) {
fprintf(stderr, "tshark: invalid \"-z " TAP_NAME "[,ipv4|ipv6]\" argument\n");
exit(1);
}
opt_count++;
}
g_strfreev(tokens);
}
error_string=register_tap_listener("frame", NULL, NULL, TL_REQUIRES_PROTO_TREE,
NULL, NULL, hosts_draw);
if(error_string){
fprintf(stderr, "tshark: Couldn't register " TAP_NAME " tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_hosts(void)
{
register_stat_cmd_arg(TAP_NAME, hosts_init, NULL);
}
