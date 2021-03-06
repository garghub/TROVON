WS_NORETURN static void follow_exit(const char *strp)
{
fprintf(stderr, "tshark: follow - %s\n", strp);
exit(1);
}
static const char * follow_str_type(cli_follow_info_t* cli_follow_info)
{
switch (cli_follow_info->show_type)
{
case SHOW_HEXDUMP: return "hex";
case SHOW_ASCII: return "ascii";
case SHOW_EBCDIC: return "ebcdic";
case SHOW_RAW: return "raw";
default:
g_assert_not_reached();
break;
}
g_assert_not_reached();
return "<unknown-mode>";
}
static void
follow_free(follow_info_t *follow_info)
{
cli_follow_info_t* cli_follow_info = (cli_follow_info_t*)follow_info->gui_data;
g_free(cli_follow_info);
g_free(follow_info->filter_out_filter);
g_free(follow_info);
}
static void follow_print_hex(const char *prefixp, guint32 offset, void *datap, int len)
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
static void follow_draw(void *contextp)
{
static const char separator[] =
"===================================================================\n";
follow_info_t *follow_info = (follow_info_t*)contextp;
cli_follow_info_t* cli_follow_info = (cli_follow_info_t*)follow_info->gui_data;
gchar buf[MAX_IP6_STR_LEN];
guint32 global_client_pos = 0, global_server_pos = 0;
guint32 *global_pos;
guint32 ii, jj;
char *buffer;
GList *cur;
follow_record_t *follow_record;
guint chunk;
printf("\n%s", separator);
printf("Follow: %s,%s\n", proto_get_protocol_filter_name(get_follow_proto_id(cli_follow_info->follower)), follow_str_type(cli_follow_info));
printf("Filter: %s\n", follow_info->filter_out_filter);
address_to_str_buf(&follow_info->client_ip, buf, sizeof buf);
if (follow_info->client_ip.type == AT_IPv6)
printf("Node 0: [%s]:%u\n", buf, follow_info->client_port);
else
printf("Node 0: %s:%u\n", buf, follow_info->client_port);
address_to_str_buf(&follow_info->server_ip, buf, sizeof buf);
if (follow_info->client_ip.type == AT_IPv6)
printf("Node 1: [%s]:%u\n", buf, follow_info->server_port);
else
printf("Node 1: %s:%u\n", buf, follow_info->server_port);
for (cur = follow_info->payload, chunk = 0;
cur != NULL;
cur = g_list_next(cur), chunk++)
{
follow_record = (follow_record_t *)cur->data;
if (!follow_record->is_server) {
global_pos = &global_client_pos;
} else {
global_pos = &global_server_pos;
}
if ((chunk < cli_follow_info->chunkMin) || (chunk > cli_follow_info->chunkMax)) {
(*global_pos) += follow_record->data->len;
continue;
}
switch (cli_follow_info->show_type)
{
case SHOW_HEXDUMP:
break;
case SHOW_ASCII:
case SHOW_EBCDIC:
printf("%s%u\n", follow_record->is_server ? "\t" : "", follow_record->data->len);
break;
case SHOW_RAW:
if (follow_record->is_server)
{
putchar('\t');
}
break;
default:
g_assert_not_reached();
}
switch (cli_follow_info->show_type)
{
case SHOW_HEXDUMP:
follow_print_hex(follow_record->is_server ? "\t" : "", *global_pos, follow_record->data->data, follow_record->data->len);
(*global_pos) += follow_record->data->len;
break;
case SHOW_ASCII:
case SHOW_EBCDIC:
buffer = (char *)g_malloc(follow_record->data->len+2);
for (ii = 0; ii < follow_record->data->len; ii++)
{
switch (follow_record->data->data[ii])
{
case '\r':
case '\n':
buffer[ii] = follow_record->data->data[ii];
break;
default:
buffer[ii] = g_ascii_isprint(follow_record->data->data[ii]) ? follow_record->data->data[ii] : '.';
break;
}
}
buffer[ii++] = '\n';
buffer[ii] = 0;
if (cli_follow_info->show_type == SHOW_EBCDIC) {
EBCDIC_to_ASCII(buffer, ii);
}
printf("%s", buffer);
g_free(buffer);
break;
case SHOW_RAW:
buffer = (char *)g_malloc((follow_record->data->len*2)+2);
for (ii = 0, jj = 0; ii < follow_record->data->len; ii++)
{
buffer[jj++] = bin2hex[follow_record->data->data[ii] >> 4];
buffer[jj++] = bin2hex[follow_record->data->data[ii] & 0xf];
}
buffer[jj++] = '\n';
buffer[jj] = 0;
printf("%s", buffer);
g_free(buffer);
break;
default:
g_assert_not_reached();
}
}
printf("%s", separator);
}
static gboolean follow_arg_strncmp(const char **opt_argp, const char *strp)
{
size_t len = strlen(strp);
if (strncmp(*opt_argp, strp, len) == 0)
{
*opt_argp += len;
return TRUE;
}
return FALSE;
}
static void
follow_arg_mode(const char **opt_argp, follow_info_t *follow_info)
{
cli_follow_info_t* cli_follow_info = (cli_follow_info_t*)follow_info->gui_data;
if (follow_arg_strncmp(opt_argp, STR_HEX))
{
cli_follow_info->show_type = SHOW_HEXDUMP;
}
else if (follow_arg_strncmp(opt_argp, STR_ASCII))
{
cli_follow_info->show_type = SHOW_ASCII;
}
else if (follow_arg_strncmp(opt_argp, STR_EBCDIC))
{
cli_follow_info->show_type = SHOW_EBCDIC;
}
else if (follow_arg_strncmp(opt_argp, STR_RAW))
{
cli_follow_info->show_type = SHOW_RAW;
}
else
{
follow_exit("Invalid display mode.");
}
}
static void
follow_arg_filter(const char **opt_argp, follow_info_t *follow_info)
{
int len;
unsigned int ii;
char addr[ADDR_LEN];
cli_follow_info_t* cli_follow_info = (cli_follow_info_t*)follow_info->gui_data;
gboolean is_ipv6;
if (sscanf(*opt_argp, ",%d%n", &cli_follow_info->stream_index, &len) == 1 &&
((*opt_argp)[len] == 0 || (*opt_argp)[len] == ','))
{
*opt_argp += len;
}
else
{
for (ii = 0; ii < sizeof cli_follow_info->addr/sizeof *cli_follow_info->addr; ii++)
{
if (sscanf(*opt_argp, ADDRv6_FMT, addr, &cli_follow_info->port[ii], &len) == 2)
{
is_ipv6 = TRUE;
}
else if (sscanf(*opt_argp, ADDRv4_FMT, addr, &cli_follow_info->port[ii], &len) == 2)
{
is_ipv6 = FALSE;
}
else
{
follow_exit("Invalid address.");
}
if (cli_follow_info->port[ii] <= 0 || cli_follow_info->port[ii] > G_MAXUINT16)
{
follow_exit("Invalid port.");
}
if (is_ipv6)
{
if (!get_host_ipaddr6(addr, (struct e_in6_addr *)cli_follow_info->addrBuf[ii]))
{
follow_exit("Can't get IPv6 address");
}
set_address(&cli_follow_info->addr[ii], AT_IPv6, 16, cli_follow_info->addrBuf[ii]);
}
else
{
if (!get_host_ipaddr(addr, (guint32 *)cli_follow_info->addrBuf[ii]))
{
follow_exit("Can't get IPv4 address");
}
set_address(&cli_follow_info->addr[ii], AT_IPv4, 4, cli_follow_info->addrBuf[ii]);
}
*opt_argp += len;
}
if (cli_follow_info->addr[0].type != cli_follow_info->addr[1].type)
{
follow_exit("Mismatched IP address types.");
}
cli_follow_info->stream_index = -1;
}
}
static void follow_arg_range(const char **opt_argp, cli_follow_info_t* cli_follow_info)
{
int len;
if (**opt_argp == 0)
{
cli_follow_info->chunkMin = 1;
cli_follow_info->chunkMax = G_MAXUINT32;
}
else
{
if (sscanf(*opt_argp, ",%u-%u%n", &cli_follow_info->chunkMin, &cli_follow_info->chunkMax, &len) == 2)
{
*opt_argp += len;
}
else if (sscanf(*opt_argp, ",%u%n", &cli_follow_info->chunkMin, &len) == 1)
{
cli_follow_info->chunkMax = cli_follow_info->chunkMin;
*opt_argp += len;
}
else
{
follow_exit("Invalid range.");
}
if (cli_follow_info->chunkMin < 1 || cli_follow_info->chunkMin > cli_follow_info->chunkMax)
{
follow_exit("Invalid range value.");
}
}
}
static void
follow_arg_done(const char *opt_argp)
{
if (*opt_argp != 0)
{
follow_exit("Invalid parameter.");
}
}
static void follow_stream(const char *opt_argp, void *userdata)
{
follow_info_t *follow_info;
cli_follow_info_t* cli_follow_info;
GString *errp;
register_follow_t* follower = (register_follow_t*)userdata;
follow_index_filter_func index_filter;
follow_address_filter_func address_filter;
opt_argp += strlen(STR_FOLLOW);
opt_argp += strlen(proto_get_protocol_filter_name(get_follow_proto_id(follower)));
cli_follow_info = g_new0(cli_follow_info_t, 1);
follow_info = g_new0(follow_info_t, 1);
follow_info->gui_data = cli_follow_info;
cli_follow_info->follower = follower;
follow_arg_mode(&opt_argp, follow_info);
follow_arg_filter(&opt_argp, follow_info);
follow_arg_range(&opt_argp, cli_follow_info);
follow_arg_done(opt_argp);
if (cli_follow_info->stream_index >= 0)
{
index_filter = get_follow_index_func(follower);
follow_info->filter_out_filter = index_filter(cli_follow_info->stream_index);
if (follow_info->filter_out_filter == NULL)
{
follow_exit("Error creating filter for this stream.");
}
}
else
{
address_filter = get_follow_address_func(follower);
follow_info->filter_out_filter = address_filter(&cli_follow_info->addr[0], &cli_follow_info->addr[1], cli_follow_info->port[0], cli_follow_info->port[1]);
if (follow_info->filter_out_filter == NULL)
{
follow_exit("Error creating filter for this address/port pair.\n");
}
}
errp = register_tap_listener(get_follow_tap_string(follower), follow_info, follow_info->filter_out_filter, 0,
NULL, get_follow_tap_handler(follower), follow_draw);
if (errp != NULL)
{
follow_free(follow_info);
g_string_free(errp, TRUE);
follow_exit("Error registering tap listener.");
}
}
static void
follow_register(gpointer data, gpointer user_data _U_)
{
register_follow_t *follower = (register_follow_t*)data;
stat_tap_ui follow_ui;
follow_ui.group = REGISTER_STAT_GROUP_GENERIC;
follow_ui.title = NULL;
follow_ui.cli_string = follow_get_stat_tap_string(follower);
follow_ui.tap_init_cb = follow_stream;
follow_ui.nparams = 0;
follow_ui.params = NULL;
register_stat_tap_ui(&follow_ui, follower);
}
void
register_tap_listener_follow(void)
{
follow_iterate_followers(follow_register, NULL);
}
