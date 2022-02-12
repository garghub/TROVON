static void
sigint_handler(int signal_num)
{
if (run == 1) {
run = 0;
signal(SIGINT, SIG_DFL);
}
}
static struct subaction *
subaction_create(uint32_t *data, size_t length)
{
struct subaction *sa;
sa = malloc(sizeof *sa - sizeof sa->packet + length);
sa->ack = data[length / 4 - 1];
sa->length = length;
memcpy(&sa->packet, data, length);
return sa;
}
static void
subaction_destroy(struct subaction *sa)
{
free(sa);
}
static struct link_transaction *
link_transaction_lookup(int request_node, int response_node, int tlabel)
{
struct link_transaction *t;
list_for_each_entry(t, &pending_transaction_list, link) {
if (t->request_node == request_node &&
t->response_node == response_node &&
t->tlabel == tlabel)
return t;
}
t = malloc(sizeof *t);
t->request_node = request_node;
t->response_node = response_node;
t->tlabel = tlabel;
list_init(&t->request_list);
list_init(&t->response_list);
list_append(&pending_transaction_list, &t->link);
return t;
}
static void
link_transaction_destroy(struct link_transaction *t)
{
struct subaction *sa;
while (!list_empty(&t->request_list)) {
sa = list_head(&t->request_list, struct subaction, link);
list_remove(&sa->link);
subaction_destroy(sa);
}
while (!list_empty(&t->response_list)) {
sa = list_head(&t->response_list, struct subaction, link);
list_remove(&sa->link);
subaction_destroy(sa);
}
free(t);
}
static void
handle_transaction(struct link_transaction *t)
{
struct subaction *sa;
int i;
if (!t->request) {
printf("BUG in handle_transaction\n");
return;
}
for (i = 0; i < array_length(protocol_decoders); i++)
if (protocol_decoders[i].decode(t))
break;
return;
decode_link_packet(&t->request->packet, t->request->length,
PACKET_FIELD_TRANSACTION, 0);
if (t->response)
decode_link_packet(&t->response->packet, t->request->length,
PACKET_FIELD_TRANSACTION, 0);
else
printf("[no response]");
if (option_verbose) {
list_for_each_entry(sa, &t->request_list, link)
print_packet((uint32_t *) &sa->packet, sa->length);
list_for_each_entry(sa, &t->response_list, link)
print_packet((uint32_t *) &sa->packet, sa->length);
}
printf("\r\n");
link_transaction_destroy(t);
}
static void
clear_pending_transaction_list(void)
{
struct link_transaction *t;
while (!list_empty(&pending_transaction_list)) {
t = list_head(&pending_transaction_list,
struct link_transaction, link);
list_remove(&t->link);
link_transaction_destroy(t);
}
}
static int
handle_request_packet(uint32_t *data, size_t length)
{
struct link_packet *p = (struct link_packet *) data;
struct subaction *sa, *prev;
struct link_transaction *t;
t = link_transaction_lookup(p->common.source, p->common.destination,
p->common.tlabel);
sa = subaction_create(data, length);
t->request = sa;
if (!list_empty(&t->request_list)) {
prev = list_tail(&t->request_list,
struct subaction, link);
if (!ACK_BUSY(prev->ack)) {
}
if (prev->packet.common.tcode != sa->packet.common.tcode ||
prev->packet.common.tlabel != sa->packet.common.tlabel) {
}
}
list_append(&t->request_list, &sa->link);
switch (sa->ack) {
case ACK_COMPLETE:
if (p->common.tcode != TCODE_WRITE_QUADLET_REQUEST &&
p->common.tcode != TCODE_WRITE_BLOCK_REQUEST)
;
list_remove(&t->link);
handle_transaction(t);
break;
case ACK_NO_ACK:
case ACK_DATA_ERROR:
case ACK_TYPE_ERROR:
list_remove(&t->link);
handle_transaction(t);
break;
case ACK_PENDING:
break;
case ACK_BUSY_X:
case ACK_BUSY_A:
case ACK_BUSY_B:
break;
}
return 1;
}
static int
handle_response_packet(uint32_t *data, size_t length)
{
struct link_packet *p = (struct link_packet *) data;
struct subaction *sa, *prev;
struct link_transaction *t;
t = link_transaction_lookup(p->common.destination, p->common.source,
p->common.tlabel);
if (list_empty(&t->request_list)) {
}
sa = subaction_create(data, length);
t->response = sa;
if (!list_empty(&t->response_list)) {
prev = list_tail(&t->response_list, struct subaction, link);
if (!ACK_BUSY(prev->ack)) {
}
if (prev->packet.common.tcode != sa->packet.common.tcode ||
prev->packet.common.tlabel != sa->packet.common.tlabel) {
}
} else {
prev = list_tail(&t->request_list, struct subaction, link);
if (prev->ack != ACK_PENDING) {
}
if (packet_info[prev->packet.common.tcode].response_tcode !=
sa->packet.common.tcode) {
}
}
list_append(&t->response_list, &sa->link);
switch (sa->ack) {
case ACK_COMPLETE:
case ACK_NO_ACK:
case ACK_DATA_ERROR:
case ACK_TYPE_ERROR:
list_remove(&t->link);
handle_transaction(t);
break;
case ACK_PENDING:
break;
case ACK_BUSY_X:
case ACK_BUSY_A:
case ACK_BUSY_B:
break;
}
return 1;
}
static int
handle_packet(uint32_t *data, size_t length)
{
if (length == 0) {
printf("bus reset\r\n");
clear_pending_transaction_list();
} else if (length > sizeof(struct phy_packet)) {
struct link_packet *p = (struct link_packet *) data;
switch (packet_info[p->common.tcode].type) {
case PACKET_REQUEST:
return handle_request_packet(data, length);
case PACKET_RESPONSE:
return handle_response_packet(data, length);
case PACKET_OTHER:
case PACKET_RESERVED:
return 0;
}
}
return 1;
}
static unsigned int
get_bits(struct link_packet *packet, int offset, int width)
{
uint32_t *data = (uint32_t *) packet;
uint32_t index, shift, mask;
index = offset / 32 + 1;
shift = 32 - (offset & 31) - width;
mask = width == 32 ? ~0 : (1 << width) - 1;
return (data[index] >> shift) & mask;
}
static void
dump_data(unsigned char *data, int length)
{
int i, print_length;
if (length > 128)
print_length = 128;
else
print_length = length;
for (i = 0; i < print_length; i++)
printf("%s%02hhx",
(i % 4 == 0 && i != 0) ? " " : "",
data[byte_index(i)]);
if (print_length < length)
printf(" (%d more bytes)", length - print_length);
}
static void
decode_link_packet(struct link_packet *packet, size_t length,
int include_flags, int exclude_flags)
{
const struct packet_info *pi;
int data_length = 0;
int i;
pi = &packet_info[packet->common.tcode];
for (i = 0; i < pi->field_count; i++) {
const struct packet_field *f = &pi->fields[i];
int offset;
if (f->flags & exclude_flags)
continue;
if (include_flags && !(f->flags & include_flags))
continue;
if (f->offset < 0)
offset = length * 8 + f->offset - 32;
else
offset = f->offset;
if (f->value_names != NULL) {
uint32_t bits;
bits = get_bits(packet, offset, f->width);
printf("%s", f->value_names[bits]);
} else if (f->width == 0) {
printf("%s=[", f->name);
dump_data((unsigned char *) packet + (offset / 8 + 4), data_length);
printf("]");
} else {
unsigned long long bits;
int high_width, low_width;
if ((offset & ~31) != ((offset + f->width - 1) & ~31)) {
high_width = ((offset + 31) & ~31) - offset;
low_width = f->width - high_width;
bits = get_bits(packet, offset, high_width);
bits = (bits << low_width) |
get_bits(packet, offset + high_width, low_width);
} else {
bits = get_bits(packet, offset, f->width);
}
printf("%s=0x%0*llx", f->name, (f->width + 3) / 4, bits);
if (f->flags & PACKET_FIELD_DATA_LENGTH)
data_length = bits;
}
if (i < pi->field_count - 1)
printf(", ");
}
}
static void
print_packet(uint32_t *data, size_t length)
{
int i;
printf("%6u ", data[0]);
if (length == 4) {
printf("bus reset");
} else if (length < sizeof(struct phy_packet)) {
printf("short packet: ");
for (i = 1; i < length / 4; i++)
printf("%s%08x", i == 0 ? "[" : " ", data[i]);
printf("]");
} else if (length == sizeof(struct phy_packet) && data[1] == ~data[2]) {
struct phy_packet *pp = (struct phy_packet *) data;
switch (pp->common.identifier) {
case PHY_PACKET_CONFIGURATION:
if (!pp->phy_config.set_root && !pp->phy_config.set_gap_count) {
printf("ext phy config: phy_id=%02x", pp->phy_config.root_id);
} else {
printf("phy config:");
if (pp->phy_config.set_root)
printf(" set_root_id=%02x", pp->phy_config.root_id);
if (pp->phy_config.set_gap_count)
printf(" set_gap_count=%d", pp->phy_config.gap_count);
}
break;
case PHY_PACKET_LINK_ON:
printf("link-on packet, phy_id=%02x", pp->link_on.phy_id);
break;
case PHY_PACKET_SELF_ID:
if (pp->self_id.extended) {
printf("extended self id: phy_id=%02x, seq=%d",
pp->ext_self_id.phy_id, pp->ext_self_id.sequence);
} else {
static const char * const speed_names[] = {
"S100", "S200", "S400", "BETA"
};
printf("self id: phy_id=%02x, link %s, gap_count=%d, speed=%s%s%s",
pp->self_id.phy_id,
(pp->self_id.link_active ? "active" : "not active"),
pp->self_id.gap_count,
speed_names[pp->self_id.phy_speed],
(pp->self_id.contender ? ", irm contender" : ""),
(pp->self_id.initiated_reset ? ", initiator" : ""));
}
break;
default:
printf("unknown phy packet: ");
for (i = 1; i < length / 4; i++)
printf("%s%08x", i == 0 ? "[" : " ", data[i]);
printf("]");
break;
}
} else {
struct link_packet *packet = (struct link_packet *) data;
decode_link_packet(packet, length, 0,
option_verbose ? 0 : PACKET_FIELD_DETAIL);
}
if (option_hex) {
printf(" [");
dump_data((unsigned char *) data + 4, length - 4);
printf("]");
}
printf("\r\n");
}
static void
print_stats(uint32_t *data, size_t length)
{
static int bus_reset_count, short_packet_count, phy_packet_count;
static int tcode_count[16];
static struct timeval last_update;
struct timeval now;
int i;
if (length == 0)
bus_reset_count++;
else if (length < sizeof(struct phy_packet))
short_packet_count++;
else if (length == sizeof(struct phy_packet) && data[1] == ~data[2])
phy_packet_count++;
else {
struct link_packet *packet = (struct link_packet *) data;
tcode_count[packet->common.tcode]++;
}
gettimeofday(&now, NULL);
if (now.tv_sec <= last_update.tv_sec &&
now.tv_usec < last_update.tv_usec + 500000)
return;
last_update = now;
printf(CLEAR HIDE_CURSOR
" bus resets : %8d\n"
" short packets : %8d\n"
" phy packets : %8d\n",
bus_reset_count, short_packet_count, phy_packet_count);
for (i = 0; i < array_length(packet_info); i++)
if (packet_info[i].type != PACKET_RESERVED)
printf(" %-24s: %8d\n", packet_info[i].name, tcode_count[i]);
printf(SHOW_CURSOR "\n");
}
static void
reset_input_mode(void)
{
tcsetattr(STDIN_FILENO, TCSANOW, &saved_attributes);
}
static void
set_input_mode(void)
{
struct termios tattr;
if (!isatty(STDIN_FILENO)) {
fprintf(stderr, "Not a terminal.\n");
exit(EXIT_FAILURE);
}
tcgetattr(STDIN_FILENO, &saved_attributes);
atexit(reset_input_mode);
tcgetattr(STDIN_FILENO, &tattr);
tattr.c_lflag &= ~(ICANON|ECHO);
tattr.c_cc[VMIN] = 1;
tattr.c_cc[VTIME] = 0;
tcsetattr(STDIN_FILENO, TCSAFLUSH, &tattr);
}
int main(int argc, const char *argv[])
{
uint32_t buf[128 * 1024];
uint32_t filter;
int length, retval, view;
int fd = -1;
FILE *output = NULL, *input = NULL;
poptContext con;
char c;
struct pollfd pollfds[2];
sys_sigint_handler = signal(SIGINT, sigint_handler);
con = poptGetContext(NULL, argc, argv, options, 0);
retval = poptGetNextOpt(con);
if (retval < -1) {
poptPrintUsage(con, stdout, 0);
return -1;
}
if (option_version) {
printf("dump tool for nosy sniffer, version %s\n", VERSION);
return 0;
}
if (__BYTE_ORDER != __LITTLE_ENDIAN)
fprintf(stderr, "warning: nosy has only been tested on little "
"endian machines\n");
if (option_input != NULL) {
input = fopen(option_input, "r");
if (input == NULL) {
fprintf(stderr, "Could not open %s, %m\n", option_input);
return -1;
}
} else {
fd = open(option_nosy_device, O_RDWR);
if (fd < 0) {
fprintf(stderr, "Could not open %s, %m\n", option_nosy_device);
return -1;
}
set_input_mode();
}
if (strcmp(option_view, "transaction") == 0)
view = VIEW_TRANSACTION;
else if (strcmp(option_view, "stats") == 0)
view = VIEW_STATS;
else
view = VIEW_PACKET;
if (option_output) {
output = fopen(option_output, "w");
if (output == NULL) {
fprintf(stderr, "Could not open %s, %m\n", option_output);
return -1;
}
}
setvbuf(stdout, NULL, _IOLBF, BUFSIZ);
filter = ~0;
if (!option_iso)
filter &= ~(1 << TCODE_STREAM_DATA);
if (!option_cycle_start)
filter &= ~(1 << TCODE_CYCLE_START);
if (view == VIEW_STATS)
filter = ~(1 << TCODE_CYCLE_START);
ioctl(fd, NOSY_IOC_FILTER, filter);
ioctl(fd, NOSY_IOC_START);
pollfds[0].fd = fd;
pollfds[0].events = POLLIN;
pollfds[1].fd = STDIN_FILENO;
pollfds[1].events = POLLIN;
while (run) {
if (input != NULL) {
if (fread(&length, sizeof length, 1, input) != 1)
return 0;
fread(buf, 1, length, input);
} else {
poll(pollfds, 2, -1);
if (pollfds[1].revents) {
read(STDIN_FILENO, &c, sizeof c);
switch (c) {
case 'q':
if (output != NULL)
fclose(output);
return 0;
}
}
if (pollfds[0].revents)
length = read(fd, buf, sizeof buf);
else
continue;
}
if (output != NULL) {
fwrite(&length, sizeof length, 1, output);
fwrite(buf, 1, length, output);
}
switch (view) {
case VIEW_TRANSACTION:
handle_packet(buf, length);
break;
case VIEW_PACKET:
print_packet(buf, length);
break;
case VIEW_STATS:
print_stats(buf, length);
break;
}
}
if (output != NULL)
fclose(output);
close(fd);
poptFreeContext(con);
return 0;
}
