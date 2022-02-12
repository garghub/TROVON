void
follow_stats(follow_stats_t* stats)
{
int i;
for (i = 0; i < 2 ; i++) {
memcpy(stats->ip_address[i], ip_address[i], MAX_IPADDR_LEN);
stats->port[i] = port[i];
stats->bytes_written[i] = bytes_written[i];
stats->is_ipv6 = is_ipv6;
}
}
char*
build_follow_filter( packet_info *pi ) {
char* buf;
int len;
conversation_t *conv=NULL;
struct tcp_analysis *tcpd;
if( ((pi->net_src.type == AT_IPv4 && pi->net_dst.type == AT_IPv4) ||
(pi->net_src.type == AT_IPv6 && pi->net_dst.type == AT_IPv6))
&& pi->ipproto == IP_PROTO_TCP
&& (conv=find_conversation(pi->fd->num, &pi->src, &pi->dst, pi->ptype,
pi->srcport, pi->destport, 0)) != NULL ) {
tcpd=get_tcp_conversation_data(conv, pi);
if (tcpd) {
buf = g_strdup_printf("tcp.stream eq %d", tcpd->stream);
tcp_stream_to_follow = tcpd->stream;
if (pi->net_src.type == AT_IPv4) {
len = 4;
is_ipv6 = FALSE;
} else {
len = 16;
is_ipv6 = TRUE;
}
} else {
return NULL;
}
}
else if( pi->net_src.type == AT_IPv4 && pi->net_dst.type == AT_IPv4
&& pi->ipproto == IP_PROTO_UDP ) {
buf = g_strdup_printf(
"(ip.addr eq %s and ip.addr eq %s) and (udp.port eq %d and udp.port eq %d)",
ip_to_str((guint8 *)pi->net_src.data),
ip_to_str((guint8 *)pi->net_dst.data),
pi->srcport, pi->destport );
len = 4;
is_ipv6 = FALSE;
}
else if( pi->net_src.type == AT_IPv6 && pi->net_dst.type == AT_IPv6
&& pi->ipproto == IP_PROTO_UDP ) {
buf = g_strdup_printf(
"(ipv6.addr eq %s and ipv6.addr eq %s) and (udp.port eq %d and udp.port eq %d)",
ip6_to_str((const struct e_in6_addr *)pi->net_src.data),
ip6_to_str((const struct e_in6_addr *)pi->net_dst.data),
pi->srcport, pi->destport );
len = 16;
is_ipv6 = TRUE;
}
else {
return NULL;
}
memcpy(ip_address[0], pi->net_src.data, len);
memcpy(ip_address[1], pi->net_dst.data, len);
port[0] = pi->srcport;
port[1] = pi->destport;
return buf;
}
gboolean
follow_tcp_addr(const address *addr0, guint port0,
const address *addr1, guint port1)
{
if (addr0 == NULL || addr1 == NULL || addr0->type != addr1->type ||
port0 > G_MAXUINT16 || port1 > G_MAXUINT16 ) {
return FALSE;
}
if (find_tcp_index || find_tcp_addr) {
return FALSE;
}
switch (addr0->type) {
default:
return FALSE;
case AT_IPv4:
case AT_IPv6:
is_ipv6 = addr0->type == AT_IPv6;
break;
}
find_tcp_index = TRUE;
memcpy(ip_address[0], addr0->data, addr0->len);
SET_ADDRESS(&tcp_addr[0], addr0->type, addr0->len, ip_address[0]);
port[0] = port0;
memcpy(ip_address[1], addr1->data, addr1->len);
SET_ADDRESS(&tcp_addr[1], addr1->type, addr1->len, ip_address[1]);
port[1] = port1;
return TRUE;
}
gboolean
follow_tcp_index(guint32 indx)
{
if (find_tcp_index || find_tcp_addr) {
return FALSE;
}
find_tcp_addr = TRUE;
tcp_stream_to_follow = indx;
memset(ip_address, 0, sizeof ip_address);
port[0] = port[1] = 0;
return TRUE;
}
void
reassemble_tcp( guint32 tcp_stream, guint32 sequence, guint32 acknowledgement,
guint32 length, const char* data, guint32 data_length,
int synflag, address *net_src, address *net_dst,
guint srcport, guint dstport) {
guint8 srcx[MAX_IPADDR_LEN], dstx[MAX_IPADDR_LEN];
int src_index, j, first = 0, len;
guint32 newseq;
tcp_frag *tmp_frag;
tcp_stream_chunk sc;
src_index = -1;
if (find_tcp_index) {
if ((port[0] == srcport && port[1] == dstport &&
ADDRESSES_EQUAL(&tcp_addr[0], net_src) &&
ADDRESSES_EQUAL(&tcp_addr[1], net_dst))
||
(port[1] == srcport && port[0] == dstport &&
ADDRESSES_EQUAL(&tcp_addr[1], net_src) &&
ADDRESSES_EQUAL(&tcp_addr[0], net_dst))) {
find_tcp_index = FALSE;
tcp_stream_to_follow = tcp_stream;
}
else {
return;
}
}
else if ( tcp_stream != tcp_stream_to_follow )
return;
if ((net_src->type != AT_IPv4 && net_src->type != AT_IPv6) ||
(net_dst->type != AT_IPv4 && net_dst->type != AT_IPv6))
return;
if (net_src->type == AT_IPv4)
len = 4;
else
len = 16;
memcpy(srcx, net_src->data, len);
memcpy(dstx, net_dst->data, len);
if (find_tcp_addr) {
find_tcp_addr = FALSE;
memcpy(ip_address[0], net_src->data, net_src->len);
port[0] = srcport;
memcpy(ip_address[1], net_dst->data, net_dst->len);
port[1] = dstport;
}
for( j=0; j<2; j++ ) {
if (memcmp(src_addr[j], srcx, len) == 0 && src_port[j] == srcport ) {
src_index = j;
}
}
if( src_index < 0 ) {
for( j=0; j<2; j++ ) {
if( src_port[j] == 0 ) {
memcpy(src_addr[j], srcx, len);
src_port[j] = srcport;
src_index = j;
first = 1;
break;
}
}
}
if( src_index < 0 ) {
fprintf( stderr, "ERROR in reassemble_tcp: Too many addresses!\n");
return;
}
if( data_length < length ) {
incomplete_tcp_stream = TRUE;
}
if( frags[1-src_index] ) {
memcpy(sc.src_addr, dstx, len);
sc.src_port = dstport;
sc.dlen = 0;
while ( check_fragments( 1-src_index, &sc, acknowledgement ) )
;
}
memcpy(sc.src_addr, srcx, len);
sc.src_port = srcport;
sc.dlen = data_length;
if( first ) {
seq[src_index] = sequence + length;
if( synflag ) {
seq[src_index]++;
}
write_packet_data( src_index, &sc, data );
return;
}
if( sequence < seq[src_index] ) {
newseq = sequence + length;
if( newseq > seq[src_index] ) {
guint32 new_len;
new_len = seq[src_index] - sequence;
if ( data_length <= new_len ) {
data = NULL;
data_length = 0;
incomplete_tcp_stream = TRUE;
} else {
data += new_len;
data_length -= new_len;
}
sc.dlen = data_length;
sequence = seq[src_index];
length = newseq - seq[src_index];
}
}
if ( sequence == seq[src_index] ) {
seq[src_index] += length;
if( synflag ) seq[src_index]++;
if( data ) {
write_packet_data( src_index, &sc, data );
}
while( check_fragments( src_index, &sc, 0 ) )
;
}
else {
if(data_length > 0 && ((glong)(sequence - seq[src_index]) > 0) ) {
tmp_frag = (tcp_frag *)g_malloc( sizeof( tcp_frag ) );
tmp_frag->data = (gchar *)g_malloc( data_length );
tmp_frag->seq = sequence;
tmp_frag->len = length;
tmp_frag->data_len = data_length;
memcpy( tmp_frag->data, data, data_length );
if( frags[src_index] ) {
tmp_frag->next = frags[src_index];
} else {
tmp_frag->next = NULL;
}
frags[src_index] = tmp_frag;
}
}
}
static int
check_fragments( int idx, tcp_stream_chunk *sc, guint32 acknowledged ) {
tcp_frag *prev = NULL;
tcp_frag *current;
guint32 lowest_seq;
gchar *dummy_str;
current = frags[idx];
if( current ) {
lowest_seq = current->seq;
while( current ) {
if( (glong)(lowest_seq - current->seq) > 0 ) {
lowest_seq = current->seq;
}
if( current->seq < seq[idx] ) {
guint32 newseq;
newseq = current->seq + current->len;
if( newseq > seq[idx] ) {
guint32 new_pos;
new_pos = seq[idx] - current->seq;
if ( current->data_len > new_pos ) {
sc->dlen = current->data_len - new_pos;
write_packet_data( idx, sc, current->data + new_pos );
}
seq[idx] += (current->len - new_pos);
}
if( prev ) {
prev->next = current->next;
} else {
frags[idx] = current->next;
}
g_free( current->data );
g_free( current );
return 1;
}
if( current->seq == seq[idx] ) {
if( current->data ) {
sc->dlen = current->data_len;
write_packet_data( idx, sc, current->data );
}
seq[idx] += current->len;
if( prev ) {
prev->next = current->next;
} else {
frags[idx] = current->next;
}
g_free( current->data );
g_free( current );
return 1;
}
prev = current;
current = current->next;
}
if( (glong)(acknowledged - lowest_seq) > 0 ) {
dummy_str = g_strdup_printf("[%d bytes missing in capture file]",
(int)(lowest_seq - seq[idx]) );
sc->dlen = (guint32) strlen(dummy_str);
write_packet_data( idx, sc, dummy_str );
g_free(dummy_str);
seq[idx] = lowest_seq;
return 1;
}
}
return 0;
}
void
reset_tcp_reassembly(void)
{
tcp_frag *current, *next;
int i;
empty_tcp_stream = TRUE;
incomplete_tcp_stream = FALSE;
find_tcp_addr = FALSE;
find_tcp_index = FALSE;
for( i=0; i<2; i++ ) {
seq[i] = 0;
memset(src_addr[i], '\0', MAX_IPADDR_LEN);
src_port[i] = 0;
memset(ip_address[i], '\0', MAX_IPADDR_LEN);
port[i] = 0;
bytes_written[i] = 0;
current = frags[i];
while( current ) {
next = current->next;
g_free( current->data );
g_free( current );
current = next;
}
frags[i] = NULL;
}
}
static void
write_packet_data( int idx, tcp_stream_chunk *sc, const char *data )
{
size_t ret;
ret = fwrite( sc, 1, sizeof(tcp_stream_chunk), data_out_file );
DISSECTOR_ASSERT(sizeof(tcp_stream_chunk) == ret);
ret = fwrite( data, 1, sc->dlen, data_out_file );
DISSECTOR_ASSERT(sc->dlen == ret);
bytes_written[idx] += sc->dlen;
empty_tcp_stream = FALSE;
}
