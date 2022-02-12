static void
followExit(
const char *strp
)
{
fprintf(stderr, "tshark: follow - %s\n", strp);
exit(1);
}
static const char *
followStrType(
const follow_t *fp
)
{
switch (fp->type)
{
case type_TCP: return "tcp";
case type_UDP: return "udp";
case type_SSL: return "ssl";
}
g_assert_not_reached();
return "<unknown-type>";
}
static const char *
followStrMode(
const follow_t *fp
)
{
switch (fp->mode)
{
case mode_HEX: return "hex";
case mode_ASCII: return "ascii";
case mode_EBCDIC: return "ebcdic";
case mode_RAW: return "raw";
}
g_assert_not_reached();
return "<unknown-mode>";
}
static const char *
followStrFilter(
const follow_t *fp
)
{
static char filter[512];
int len = 0;
const gchar *verp;
gchar *udpfilter;
gchar ip0[MAX_IP6_STR_LEN];
gchar ip1[MAX_IP6_STR_LEN];
if (fp->stream_index != G_MAXUINT32)
{
switch (fp->type)
{
case type_TCP:
case type_SSL:
len = g_snprintf(filter, sizeof filter,
"tcp.stream eq %d", fp->stream_index);
break;
case type_UDP:
udpfilter = build_follow_index_filter(UDP_STREAM);
len = g_snprintf(filter, sizeof filter,
"%s", udpfilter);
g_free(udpfilter);
break;
}
}
else
{
verp = fp->addr[0].type == AT_IPv6 ? "v6" : "";
address_to_str_buf(&fp->addr[0], ip0, sizeof ip0);
address_to_str_buf(&fp->addr[1], ip1, sizeof ip1);
switch (fp->type)
{
case type_TCP:
len = g_snprintf(filter, sizeof filter,
"((ip%s.src eq %s and tcp.srcport eq %d) and "
"(ip%s.dst eq %s and tcp.dstport eq %d))"
" or "
"((ip%s.src eq %s and tcp.srcport eq %d) and "
"(ip%s.dst eq %s and tcp.dstport eq %d))",
verp, ip0, fp->port[0],
verp, ip1, fp->port[1],
verp, ip1, fp->port[1],
verp, ip0, fp->port[0]);
break;
case type_UDP:
len = g_snprintf(filter, sizeof filter,
"((ip%s.src eq %s and udp.srcport eq %d) and "
"(ip%s.dst eq %s and udp.dstport eq %d))"
" or "
"((ip%s.src eq %s and udp.srcport eq %d) and "
"(ip%s.dst eq %s and udp.dstport eq %d))",
verp, ip0, fp->port[0],
verp, ip1, fp->port[1],
verp, ip1, fp->port[1],
verp, ip0, fp->port[0]);
break;
case type_SSL:
break;
}
}
if (len == 0)
{
followExit("Don't know how to create filter.");
}
if (len == sizeof filter)
{
followExit("Filter buffer overflow.");
}
return filter;
}
static void
followFileClose(
follow_t *fp
)
{
if (fp->filep != NULL)
{
fclose(fp->filep);
fp->filep = NULL;
if (fp->type == type_TCP)
{
data_out_file = NULL;
}
}
if (fp->filenamep != NULL)
{
ws_unlink(fp->filenamep);
g_free(fp->filenamep);
fp->filenamep = NULL;
}
}
static void
followFileOpen(
follow_t *fp
)
{
int fd;
char *tempfilep;
if (fp->type == type_TCP && data_out_file != NULL)
{
followExit("Only one TCP stream can be followed at a time.");
}
followFileClose(fp);
fd = create_tempfile(&tempfilep, "follow");
if (fd == -1)
{
followExit("Error creating temp file.");
}
fp->filenamep = g_strdup(tempfilep);
if (fp->filenamep == NULL)
{
ws_close(fd);
ws_unlink(tempfilep);
followExit("Error duping temp file name.");
}
fp->filep = fdopen(fd, "w+b");
if (fp->filep == NULL)
{
ws_close(fd);
ws_unlink(fp->filenamep);
g_free(fp->filenamep);
fp->filenamep = NULL;
followExit("Error opening temp file stream.");
}
if (fp->type == type_TCP)
{
data_out_file = fp->filep;
}
}
static follow_t *
followAlloc(
type_e type
)
{
follow_t *fp;
fp = (follow_t *)g_malloc0(sizeof *fp);
fp->type = type;
SET_ADDRESS(&fp->addr[0], AT_NONE, 0, fp->addrBuf[0]);
SET_ADDRESS(&fp->addr[1], AT_NONE, 0, fp->addrBuf[1]);
return fp;
}
static void
followFree(
follow_t *fp
)
{
followFileClose(fp);
g_free(fp);
}
static int
followUdpPacket(
void *contextp,
packet_info *pip,
epan_dissect_t *edp _U_,
const void *datap
)
{
follow_t *fp = (follow_t *)contextp;
const tvbuff_t *tvbp = (const tvbuff_t *)datap;
tcp_stream_chunk sc;
size_t size;
if (tvbp->length > 0)
{
memcpy(sc.src_addr, pip->net_src.data, pip->net_src.len);
sc.src_port = pip->srcport;
sc.dlen = tvbp->length;
sc.packet_num = pip->fd->num;
size = fwrite(&sc, 1, sizeof sc, fp->filep);
if (sizeof sc != size)
{
followExit("Error writing stream chunk header.");
}
size = fwrite(tvbp->real_data, 1, sc.dlen, fp->filep);
if (sc.dlen != size)
{
followExit("Error writing stream chunk data.");
}
}
return 0;
}
static int
followSslPacket(
void *contextp,
packet_info *pip,
epan_dissect_t *edp _U_,
const void *datap
)
{
follow_t *fp = (follow_t *)contextp;
SslPacketInfo *spip = (SslPacketInfo *)p_get_proto_data(wmem_file_scope(), pip, GPOINTER_TO_INT(datap), 0);
SslDataInfo *sdip;
gint length;
tcp_stream_chunk sc;
size_t size;
if (spip == NULL)
{
return 0;
}
if (fp->addr[0].type == AT_NONE)
{
memcpy(fp->addrBuf[0], pip->net_src.data, pip->net_src.len);
SET_ADDRESS(&fp->addr[0], pip->net_src.type, pip->net_src.len,
fp->addrBuf[0]);
fp->port[0] = pip->srcport;
memcpy(fp->addrBuf[1], pip->net_dst.data, pip->net_dst.len);
SET_ADDRESS(&fp->addr[1], pip->net_dst.type, pip->net_dst.len,
fp->addrBuf[1]);
fp->port[1] = pip->destport;
}
for (length = 0, sdip = spip->appl_data; sdip != NULL; sdip = sdip->next)
{
length += sdip->plain_data.data_len;
}
if (length > 0)
{
memcpy(sc.src_addr, pip->net_src.data, pip->net_src.len);
sc.src_port = pip->srcport;
sc.dlen = length;
sc.packet_num = pip->fd->num;
size = fwrite(&sc, 1, sizeof sc, fp->filep);
if (sizeof sc != size)
{
followExit("Error writing stream chunk header.");
}
for (sdip = spip->appl_data; sdip != NULL; sdip = sdip->next)
{
if (sdip->plain_data.data_len > 0)
{
size = fwrite(sdip->plain_data.data, 1, sdip->plain_data.data_len,
fp->filep);
if (sdip->plain_data.data_len != size)
{
followExit("Error writing stream chunk data.");
}
}
}
}
return 0;
}
static void
followPrintHex(
const char *prefixp,
guint32 offset,
void *datap,
int len
)
{
int ii;
int jj;
int kk;
guint8 val;
char line[LINE_LEN + 1];
for (ii = 0, jj = 0, kk = 0; ii < len; )
{
if ((ii % BYTES_PER_LINE) == 0)
{
g_snprintf(line, LINE_LEN + 1, "%0*X", OFFSET_LEN, offset);
memset(line + HEX_START - OFFSET_SPACE, ' ',
HEX_LEN + OFFSET_SPACE + HEX_SPACE);
jj = HEX_START;
kk = ASCII_START;
}
val = ((guint8 *)datap)[ii];
line[jj++] = bin2hex[val >> 4];
line[jj++] = bin2hex[val & 0xf];
jj++;
line[kk++] = val >= ' ' && val < 0x7f ? val : '.';
if (++ii % BYTES_PER_LINE == BYTES_PER_LINE/2)
{
line[jj++] = ' ';
line[kk++] = ' ';
}
if ((ii % BYTES_PER_LINE) == 0 || ii == len)
{
if (line[kk - 1] == ' ')
{
kk--;
}
line[kk] = 0;
printf("%s%s\n", prefixp, line);
offset += BYTES_PER_LINE;
}
}
}
static void
followDraw(
void *contextp
)
{
static const char separator[] =
"===================================================================\n";
follow_t *fp = (follow_t *)contextp;
tcp_stream_chunk sc;
int node;
const address *addr[2];
int port[2];
gchar buf[MAX_IP6_STR_LEN];
guint32 ii;
guint32 jj;
guint32 len;
guint32 chunk;
guint32 offset[2];
guint8 bin[4096];
char data[(sizeof bin * 2) + 2];
g_assert(sizeof bin % BYTES_PER_LINE == 0);
if ((fp->type == type_TCP) || (fp->type == type_UDP))
{
static const guint8 ip_zero[MAX_IPADDR_LEN] = {0};
follow_stats_t stats;
address_type type;
follow_stats(&stats);
if (stats.port[0] == 0 && stats.port[1] == 0 &&
memcmp(stats.ip_address[0], ip_zero, sizeof ip_zero) == 0 &&
memcmp(stats.ip_address[1], ip_zero, sizeof ip_zero) == 0)
{
type = AT_NONE;
len = 0;
}
else if (stats.is_ipv6)
{
type = AT_IPv6;
len = 16;
}
else
{
type = AT_IPv4;
len = 4;
}
for (node = 0; node < 2; node++)
{
memcpy(fp->addrBuf[node], stats.ip_address[node], len);
SET_ADDRESS(&fp->addr[node], type, len, fp->addrBuf[node]);
fp->port[node] = stats.port[node];
}
}
rewind(fp->filep);
for (chunk = 0;;)
{
len = (guint32)fread(&sc, 1, sizeof sc, fp->filep);
if (len != sizeof sc)
{
sc.dlen = 0;
memcpy(sc.src_addr, fp->addr[0].data, fp->addr[0].len) ;
sc.src_port = fp->port[0];
break;
}
if (sc.dlen > 0)
{
chunk++;
break;
}
}
if (memcmp(sc.src_addr, fp->addr[0].data, fp->addr[0].len) == 0 &&
sc.src_port == fp->port[0])
{
addr[0] = &fp->addr[0];
port[0] = fp->port[0];
addr[1] = &fp->addr[1];
port[1] = fp->port[1];
}
else
{
addr[0] = &fp->addr[1];
port[0] = fp->port[1];
addr[1] = &fp->addr[0];
port[1] = fp->port[0];
}
printf("\n%s", separator);
printf("Follow: %s,%s\n", followStrType(fp), followStrMode(fp));
printf("Filter: %s\n", followStrFilter(fp));
for (node = 0; node < 2; node++)
{
address_to_str_buf(addr[node], buf, sizeof buf);
if (addr[node]->type == AT_IPv6)
{
printf("Node %d: [%s]:%d\n", node, buf, port[node]);
}
else
{
printf("Node %d: %s:%d\n", node, buf, port[node]);
}
}
offset[0] = offset[1] = 0;
while (chunk <= fp->chunkMax)
{
node = (memcmp(addr[0]->data, sc.src_addr, addr[0]->len) == 0 &&
port[0] == sc.src_port) ? 0 : 1;
if (chunk < fp->chunkMin)
{
while (sc.dlen > 0)
{
len = sc.dlen < sizeof bin ? sc.dlen : (guint32)sizeof bin;
sc.dlen -= len;
if (fread(bin, 1, len, fp->filep) != len)
{
followExit("Error reading stream chunk data.");
}
offset[node] += len;
}
}
else
{
switch (fp->mode)
{
case mode_HEX:
break;
case mode_ASCII:
case mode_EBCDIC:
printf("%s%u\n", node ? "\t" : "", sc.dlen);
break;
case mode_RAW:
if (node)
{
putchar('\t');
}
break;
}
while (sc.dlen > 0)
{
len = sc.dlen < sizeof bin ? sc.dlen : (guint32)sizeof bin;
sc.dlen -= len;
if (fread(bin, 1, len, fp->filep) != len)
{
followExit("Error reading stream chunk data.");
}
switch (fp->mode)
{
case mode_HEX:
followPrintHex(node ? "\t" : "", offset[node], bin, len);
break;
case mode_ASCII:
case mode_EBCDIC:
for (ii = 0; ii < len; ii++)
{
switch (bin[ii])
{
case '\r':
case '\n':
data[ii] = bin[ii];
break;
default:
data[ii] = g_ascii_isprint(bin[ii]) ? bin[ii] : '.';
break;
}
}
if (sc.dlen == 0)
{
data[ii++] = '\n';
}
data[ii] = 0;
if (fp->mode == mode_EBCDIC) {
EBCDIC_to_ASCII(data, ii);
}
printf("%s", data);
break;
case mode_RAW:
for (ii = 0, jj = 0; ii < len; ii++)
{
data[jj++] = bin2hex[bin[ii] >> 4];
data[jj++] = bin2hex[bin[ii] & 0xf];
}
if (sc.dlen == 0)
{
data[jj++] = '\n';
}
data[jj] = 0;
printf("%s", data);
}
offset[node] += len;
}
}
for (;;)
{
len = (guint32)fread(&sc, 1, sizeof sc, fp->filep);
if (len != sizeof sc)
{
sc.dlen = 0;
goto done;
}
if (sc.dlen > 0)
{
chunk++;
break;
}
}
}
done:
printf("%s", separator);
followFileClose(fp);
}
static gboolean
followArgStrncmp(
const char **opt_argp,
const char *strp
)
{
int len = (guint32)strlen(strp);
if (strncmp(*opt_argp, strp, len) == 0)
{
*opt_argp += len;
return TRUE;
}
return FALSE;
}
static void
followArgMode(
const char **opt_argp,
follow_t *fp
)
{
if (followArgStrncmp(opt_argp, STR_HEX))
{
fp->mode = mode_HEX;
}
else if (followArgStrncmp(opt_argp, STR_ASCII))
{
fp->mode = mode_ASCII;
}
else if (followArgStrncmp(opt_argp, STR_EBCDIC))
{
fp->mode = mode_EBCDIC;
}
else if (followArgStrncmp(opt_argp, STR_RAW))
{
fp->mode = mode_RAW;
}
else
{
followExit("Invalid display mode.");
}
}
static void
followArgFilter(
const char **opt_argp,
follow_t *fp
)
{
#define _STRING(s) # s
#define STRING(s) _STRING(s)
#define ADDR_CHARS 80
#define ADDR_LEN (ADDR_CHARS + 1)
#define ADDRv6_FMT ",[%" STRING(ADDR_CHARS) "[^]]]:%d%n"
#define ADDRv4_FMT ",%" STRING(ADDR_CHARS) "[^:]:%d%n"
int len;
unsigned int ii;
char addr[ADDR_LEN];
if (sscanf(*opt_argp, ",%u%n", &fp->stream_index, &len) == 1 &&
((*opt_argp)[len] == 0 || (*opt_argp)[len] == ','))
{
*opt_argp += len;
}
else
{
for (ii = 0; ii < sizeof fp->addr/sizeof *fp->addr; ii++)
{
if ((sscanf(*opt_argp, ADDRv6_FMT, addr, &fp->port[ii], &len) != 2 &&
sscanf(*opt_argp, ADDRv4_FMT, addr, &fp->port[ii], &len) != 2) ||
fp->port[ii] <= 0 || fp->port[ii] > G_MAXUINT16)
{
followExit("Invalid address:port pair.");
}
if (strcmp("ip6", host_ip_af(addr)) == 0)
{
if (!get_host_ipaddr6(addr, (struct e_in6_addr *)fp->addrBuf[ii]))
{
followExit("Can't get IPv6 address");
}
SET_ADDRESS(&fp->addr[ii], AT_IPv6, 16, fp->addrBuf[ii]);
}
else
{
if (!get_host_ipaddr(addr, (guint32 *)fp->addrBuf[ii]))
{
followExit("Can't get IPv4 address");
}
SET_ADDRESS(&fp->addr[ii], AT_IPv4, 4, fp->addrBuf[ii]);
}
*opt_argp += len;
}
if (fp->addr[0].type != fp->addr[1].type)
{
followExit("Mismatched IP address types.");
}
fp->stream_index = G_MAXUINT32;
}
}
static void
followArgRange(
const char **opt_argp,
follow_t *fp
)
{
int len;
if (**opt_argp == 0)
{
fp->chunkMin = 1;
fp->chunkMax = G_MAXUINT32;
}
else
{
if (sscanf(*opt_argp, ",%u-%u%n", &fp->chunkMin, &fp->chunkMax, &len) == 2)
{
*opt_argp += len;
}
else if (sscanf(*opt_argp, ",%u%n", &fp->chunkMin, &len) == 1)
{
fp->chunkMax = fp->chunkMin;
*opt_argp += len;
}
else
{
followExit("Invalid range.");
}
if (fp->chunkMin < 1 || fp->chunkMin > fp->chunkMax)
{
followExit("Invalid range value.");
}
}
}
static void
followArgDone(
const char *opt_argp
)
{
if (*opt_argp != 0)
{
followExit("Invalid parameter.");
}
}
static void
followTcp(
const char *opt_argp,
void *userdata _U_
)
{
follow_t *fp;
GString *errp;
opt_argp += strlen(STR_FOLLOW_TCP);
fp = followAlloc(type_TCP);
followArgMode(&opt_argp, fp);
followArgFilter(&opt_argp, fp);
followArgRange(&opt_argp, fp);
followArgDone(opt_argp);
reset_tcp_reassembly();
if (fp->stream_index != G_MAXUINT32)
{
if (!follow_index(TCP_STREAM, fp->stream_index))
{
followExit("Can't follow TCP index.");
}
}
else
{
if (!follow_addr(TCP_STREAM, &fp->addr[0], fp->port[0],
&fp->addr[1], fp->port[1]))
{
followExit("Can't follow TCP address/port pairs.");
}
}
followFileOpen(fp);
errp = register_tap_listener("frame", fp, NULL, 0,
NULL, NULL, followDraw);
if (errp != NULL)
{
followFree(fp);
g_string_free(errp, TRUE);
followExit("Error registering TCP tap listener.");
}
}
static void
followUdp(
const char *opt_argp,
void *userdata _U_
)
{
follow_t *fp;
GString *errp;
opt_argp += strlen(STR_FOLLOW_UDP);
fp = followAlloc(type_UDP);
followArgMode(&opt_argp, fp);
followArgFilter(&opt_argp, fp);
followArgRange(&opt_argp, fp);
followArgDone(opt_argp);
reset_udp_follow();
if (fp->stream_index != G_MAXUINT32)
{
if (!follow_index(UDP_STREAM, fp->stream_index))
{
followExit("Can't follow UDP index.");
}
}
else
{
if (!follow_addr(UDP_STREAM, &fp->addr[0], fp->port[0],
&fp->addr[1], fp->port[1]))
{
followExit("Can't follow UDP address/port pairs.");
}
}
followFileOpen(fp);
errp = register_tap_listener("udp_follow", fp, followStrFilter(fp), 0,
NULL, followUdpPacket, followDraw);
if (errp != NULL)
{
followFree(fp);
g_string_free(errp, TRUE);
followExit("Error registering UDP tap listner.");
}
}
static void
followSsl(
const char *opt_argp,
void *userdata _U_
)
{
follow_t *fp;
GString *errp;
opt_argp += strlen(STR_FOLLOW_SSL);
fp = followAlloc(type_SSL);
followArgMode(&opt_argp, fp);
followArgFilter(&opt_argp, fp);
followArgRange(&opt_argp, fp);
followArgDone(opt_argp);
reset_tcp_reassembly();
if (fp->stream_index == G_MAXUINT32)
{
followExit("SSL only supports index filters.");
}
followFileOpen(fp);
errp = register_tap_listener("ssl", fp, followStrFilter(fp), 0,
NULL, followSslPacket, followDraw);
if (errp != NULL)
{
followFree(fp);
g_string_free(errp, TRUE);
followExit("Error registering SSL tap listener.");
}
}
void
register_tap_listener_follow(void)
{
register_stat_tap_ui(&followTcp_ui, NULL);
register_stat_tap_ui(&followUdp_ui, NULL);
register_stat_tap_ui(&followSsl_ui, NULL);
}
