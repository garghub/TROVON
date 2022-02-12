static void
sctpstat_reset(void *phs)
{
sctpstat_t *sctp_stat = (sctpstat_t *)phs;
sctp_ep_t *list = (sctp_ep_t *)sctp_stat->ep_list;
sctp_ep_t *tmp = NULL;
guint16 chunk_type;
if (!list)
return;
for (tmp = list; tmp; tmp = tmp->next)
for (chunk_type = 0; chunk_type < 256; chunk_type++)
tmp->chunk_count[chunk_type] = 0;
sctp_stat->number_of_packets = 0;
}
static sctp_ep_t *
alloc_sctp_ep(const struct _sctp_info *si)
{
sctp_ep_t *ep;
guint16 chunk_type;
if (!si)
return NULL;
if (!(ep = g_new(sctp_ep_t, 1)))
return NULL;
COPY_ADDRESS(&ep->src, &si->ip_src);
COPY_ADDRESS(&ep->dst, &si->ip_dst);
ep->sport = si->sport;
ep->dport = si->dport;
ep->next = NULL;
for (chunk_type = 0; chunk_type < 256; chunk_type++)
ep->chunk_count[chunk_type] = 0;
return ep;
}
static int
sctpstat_packet(void *phs, packet_info *pinfo _U_, epan_dissect_t *edt _U_, const void *phi)
{
sctpstat_t *hs = (sctpstat_t *)phs;
sctp_ep_t *tmp = NULL, *te = NULL;
const struct _sctp_info *si = (const struct _sctp_info *)phi;
guint32 tvb_number;
guint8 chunk_type;
if (!hs)
return (0);
hs->number_of_packets++;
if (!hs->ep_list) {
hs->ep_list = alloc_sctp_ep(si);
te = hs->ep_list;
} else {
for (tmp = hs->ep_list; tmp; tmp = tmp->next)
{
if ((!CMP_ADDRESS(&tmp->src, &si->ip_src)) &&
(!CMP_ADDRESS(&tmp->dst, &si->ip_dst)) &&
(tmp->sport == si->sport) &&
(tmp->dport == si->dport))
{
te = tmp;
break;
}
}
if (!te) {
if ((te = alloc_sctp_ep(si))) {
te->next = hs->ep_list;
hs->ep_list = te;
}
}
}
if (!te)
return (0);
if (si->number_of_tvbs > 0) {
chunk_type = CHUNK_TYPE(si->tvb[0]);
if ((chunk_type == SCTP_INIT_CHUNK_ID) ||
(chunk_type == SCTP_INIT_ACK_CHUNK_ID)) {
te->chunk_count[chunk_type]++;
} else {
for (tvb_number = 0; tvb_number < si->number_of_tvbs; tvb_number++)
te->chunk_count[CHUNK_TYPE(si->tvb[tvb_number])]++;
}
}
return (1);
}
static void
sctpstat_draw(void *phs)
{
sctpstat_t *hs = (sctpstat_t *)phs;
sctp_ep_t *list = hs->ep_list, *tmp;
char *src_addr, *dst_addr;
printf("-------------------------------------------- SCTP Statistics --------------------------------------------------------------------------\n");
printf("| Total packets RX/TX %u\n", hs->number_of_packets);
printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
printf("| Source IP |PortA| Dest. IP |PortB| DATA | SACK | HBEAT |HBEATACK| INIT | INITACK| COOKIE |COOKIACK| ABORT | ERROR |\n");
printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
for (tmp = list; tmp; tmp = tmp->next) {
src_addr = (char*)address_to_str(NULL, &tmp->src);
dst_addr = (char*)address_to_str(NULL, &tmp->dst);
printf("|%15s|%5u|%15s|%5u|%8u|%8u|%8u|%8u|%8u|%8u|%8u|%8u|%8u|%8u|\n",
src_addr, tmp->sport,
dst_addr, tmp->dport,
tmp->chunk_count[SCTP_DATA_CHUNK_ID],
tmp->chunk_count[SCTP_SACK_CHUNK_ID],
tmp->chunk_count[SCTP_HEARTBEAT_CHUNK_ID],
tmp->chunk_count[SCTP_HEARTBEAT_ACK_CHUNK_ID],
tmp->chunk_count[SCTP_INIT_CHUNK_ID],
tmp->chunk_count[SCTP_INIT_ACK_CHUNK_ID],
tmp->chunk_count[SCTP_COOKIE_ECHO_CHUNK_ID],
tmp->chunk_count[SCTP_COOKIE_ACK_CHUNK_ID],
tmp->chunk_count[SCTP_ABORT_CHUNK_ID],
tmp->chunk_count[SCTP_ERROR_CHUNK_ID]);
wmem_free(NULL, src_addr);
wmem_free(NULL, dst_addr);
}
printf("---------------------------------------------------------------------------------------------------------------------------------------\n");
}
static void
sctpstat_init(const char *opt_arg, void *userdata _U_)
{
sctpstat_t *hs;
GString *error_string;
hs = (sctpstat_t *)g_malloc(sizeof(sctpstat_t));
if (!strncmp(opt_arg, "sctp,stat,", 11)) {
hs->filter = g_strdup(opt_arg+11);
} else {
hs->filter = NULL;
}
hs->ep_list = NULL;
hs->number_of_packets = 0;
sctpstat_reset(hs);
error_string = register_tap_listener("sctp", hs, hs->filter, 0, NULL, sctpstat_packet, sctpstat_draw);
if (error_string) {
g_free(hs->filter);
g_free(hs);
fprintf(stderr, "tshark: Couldn't register sctp,stat tap: %s\n",
error_string->str);
g_string_free(error_string, TRUE);
exit(1);
}
}
void
register_tap_listener_sctpstat(void)
{
register_stat_tap_ui(&sctpstat_ui, NULL);
}
