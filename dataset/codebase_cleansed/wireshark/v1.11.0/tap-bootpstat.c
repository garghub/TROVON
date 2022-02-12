static void
dhcp_reset_hash(gchar *key _U_ , dhcp_message_type_t *data, gpointer ptr _U_ )
{
data->packets = 0;
}
static void
dhcp_draw_message_type(gchar *key _U_, dhcp_message_type_t *data, gchar * format )
{
if ((data==NULL) || (data->packets==0))
return;
printf( format, data->name, data->packets);
}
static void
dhcpstat_reset(void *psp)
{
dhcpstat_t *sp=(dhcpstat_t *)psp;
g_hash_table_foreach( sp->hash, (GHFunc)dhcp_reset_hash, NULL);
}
static int
dhcpstat_packet(void *psp, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *pri)
{
dhcpstat_t *sp=(dhcpstat_t *)psp;
const bootp_info_value_t value=(const bootp_info_value_t)pri;
dhcp_message_type_t *sc;
if (sp==NULL)
return 0;
sc = (dhcp_message_type_t *)g_hash_table_lookup(
sp->hash,
value);
if (!sc) {
sc = g_new(dhcp_message_type_t,1);
sc -> packets = 1;
sc -> name = value;
sc -> sp = sp;
g_hash_table_insert(
sp->hash,
(gpointer) value,
sc);
} else {
sc->packets++;
}
return 1;
}
static void
dhcpstat_draw(void *psp)
{
dhcpstat_t *sp=(dhcpstat_t *)psp;
printf("\n");
printf("===================================================================\n");
if (sp->filter==NULL)
printf("BOOTP Statistics\n");
else
printf("BOOTP Statistics with filter %s\n", sp->filter);
printf("BOOTP Option 53: DHCP Messages Types:\n");
printf("DHCP Message Type Packets nb\n" );
g_hash_table_foreach( sp->hash, (GHFunc) dhcp_draw_message_type,
(gpointer)"%23s %-9d\n" );
printf("===================================================================\n");
}
static void
dhcpstat_init(const char *opt_arg, void* userdata _U_)
{
dhcpstat_t *sp;
const char *filter=NULL;
GString *error_string;
if (!strncmp (opt_arg, "bootp,stat,", 11)){
filter=opt_arg+11;
} else {
filter=NULL;
}
sp = g_new(dhcpstat_t,1);
sp->hash = g_hash_table_new( g_str_hash, g_str_equal);
if(filter){
sp->filter=g_strdup(filter);
} else {
sp->filter=NULL;
}
sp->index = 0;
error_string = register_tap_listener(
"bootp",
sp,
filter,
0,
dhcpstat_reset,
dhcpstat_packet,
dhcpstat_draw);
if (error_string){
g_free(sp->filter);
g_free(sp);
fprintf(stderr, "tshark: Couldn't register dhcp,stat tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_gtkdhcpstat(void)
{
register_stat_cmd_arg("bootp,stat,", dhcpstat_init,NULL);
}
