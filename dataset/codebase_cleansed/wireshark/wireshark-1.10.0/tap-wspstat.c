static void
wsp_reset_hash(gchar *key _U_ , wsp_status_code_t *data, gpointer ptr _U_ )
{
data->packets = 0;
}
static void
wsp_print_statuscode(gint *key, wsp_status_code_t *data, char* format)
{
if (data && (data->packets!=0))
printf(format, *key, data->packets ,data->name);
}
static void
wsp_free_hash_table( gpointer key, gpointer value, gpointer user_data _U_ )
{
g_free(key);
g_free(value);
}
static void
wspstat_reset(void *psp)
{
wspstat_t *sp=(wspstat_t *)psp;
guint32 i;
for(i=1;i<=sp->num_pdus;i++)
{
sp->pdu_stats[i].packets=0;
}
g_hash_table_foreach( sp->hash, (GHFunc)wsp_reset_hash, NULL);
}
static gint
pdut2index(gint pdut)
{
if (pdut<=0x09) return pdut;
if (pdut>=0x40){
if (pdut <= 0x44){
return pdut-54;
} else if (pdut==0x60||pdut==0x61){
return pdut-81;
}
}
return 0;
}
static gint
index2pdut(gint pdut)
{
if (pdut<=0x09)
return pdut;
if (pdut<=14)
return pdut+54;
if (pdut<=16)
return pdut+81;
return 0;
}
static int
wspstat_packet(void *psp, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *pri)
{
wspstat_t *sp=(wspstat_t *)psp;
const wsp_info_value_t *value=(const wsp_info_value_t *)pri;
gint idx = pdut2index(value->pdut);
int retour=0;
if (value->status_code != 0) {
gint *key=g_new(gint,1);
wsp_status_code_t *sc;
*key=value->status_code ;
sc = (wsp_status_code_t *)g_hash_table_lookup(
sp->hash,
key);
if (!sc) {
sc = g_new(wsp_status_code_t,1);
sc -> packets = 1;
sc -> name = NULL;
g_hash_table_insert(
sp->hash,
key,
sc);
} else {
sc->packets++;
}
retour=1;
}
if (idx!=0) {
sp->pdu_stats[ idx ].packets++;
retour = 1;
}
return retour;
}
static void
wspstat_draw(void *psp)
{
wspstat_t *sp=(wspstat_t *)psp;
guint32 i;
printf("\n");
printf("===================================================================\n");
printf("WSP Statistics:\n");
printf("%-23s %9s || %-23s %9s\n","PDU Type", "Packets", "PDU Type", "Packets");
for(i=1; i<= ((sp->num_pdus+1)/2) ; i++)
{
guint32 ii=i+sp->num_pdus/2;
printf("%-23s %9d", sp->pdu_stats[i ].type, sp->pdu_stats[i ].packets);
printf(" || ");
if (ii< (sp->num_pdus) )
printf("%-23s %9d\n", sp->pdu_stats[ii].type, sp->pdu_stats[ii].packets);
else
printf("\n");
}
printf("\nStatus code in reply packets\n");
printf( "Status Code Packets Description\n");
g_hash_table_foreach( sp->hash, (GHFunc) wsp_print_statuscode,
(gpointer)" 0x%02X %9d %s\n" ) ;
printf("===================================================================\n");
}
static void
wspstat_init(const char *optarg, void* userdata _U_)
{
wspstat_t *sp;
const char *filter=NULL;
guint32 i;
GString *error_string;
wsp_status_code_t *sc;
const value_string *wsp_vals_status_p;
if (!strncmp (optarg, "wsp,stat," , 9)){
filter=optarg+9;
} else {
filter=NULL;
}
sp = g_new(wspstat_t,1);
sp->hash = g_hash_table_new( g_int_hash, g_int_equal);
wsp_vals_status_p = VALUE_STRING_EXT_VS_P(&wsp_vals_status_ext);
for (i=0 ; wsp_vals_status_p[i].strptr ; i++ )
{
gint *key;
sc=g_new(wsp_status_code_t,1);
key=g_new(gint,1);
sc->packets=0;
sc->name=wsp_vals_status_p[i].strptr;
*key=wsp_vals_status_p[i].value;
g_hash_table_insert(
sp->hash,
key,
sc);
}
sp->num_pdus = 16;
sp->pdu_stats=g_new(wsp_pdu_t,(sp->num_pdus+1));
if(filter){
sp->filter=g_strdup(filter);
} else {
sp->filter=NULL;
}
for (i=0;i<sp->num_pdus; i++)
{
sp->pdu_stats[i].packets=0;
sp->pdu_stats[i].type = try_val_to_str_ext( index2pdut( i ), &wsp_vals_pdu_type_ext) ;
}
error_string = register_tap_listener(
"wsp",
sp,
filter,
0,
wspstat_reset,
wspstat_packet,
wspstat_draw);
if (error_string){
g_free(sp->pdu_stats);
g_free(sp->filter);
g_free(sp);
g_hash_table_foreach( sp->hash, (GHFunc) wsp_free_hash_table, NULL ) ;
g_hash_table_destroy( sp->hash );
fprintf(stderr, "tshark: Couldn't register wsp,stat tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_wspstat(void)
{
register_stat_cmd_arg("wsp,stat,", wspstat_init,NULL);
}
