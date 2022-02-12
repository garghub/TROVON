void irlan_filter_request(struct irlan_cb *self, struct sk_buff *skb)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return;);
if ((self->provider.filter_type == IRLAN_DIRECTED) &&
(self->provider.filter_operation == DYNAMIC))
{
pr_debug("Giving peer a dynamic Ethernet address\n");
self->provider.mac_address[0] = 0x40;
self->provider.mac_address[1] = 0x00;
self->provider.mac_address[2] = 0x00;
self->provider.mac_address[3] = 0x00;
if (self->provider.access_type == ACCESS_PEER) {
self->provider.mac_address[4] =
self->provider.send_arb_val & 0xff;
self->provider.mac_address[5] =
(self->provider.send_arb_val >> 8) & 0xff;
} else {
get_random_bytes(self->provider.mac_address+4, 1);
get_random_bytes(self->provider.mac_address+5, 1);
}
skb->data[0] = 0x00;
skb->data[1] = 0x03;
irlan_insert_string_param(skb, "FILTER_MODE", "NONE");
irlan_insert_short_param(skb, "MAX_ENTRY", 0x0001);
irlan_insert_array_param(skb, "FILTER_ENTRY",
self->provider.mac_address, 6);
return;
}
if ((self->provider.filter_type == IRLAN_DIRECTED) &&
(self->provider.filter_mode == FILTER))
{
pr_debug("Directed filter on\n");
skb->data[0] = 0x00;
skb->data[1] = 0x00;
return;
}
if ((self->provider.filter_type == IRLAN_DIRECTED) &&
(self->provider.filter_mode == NONE))
{
pr_debug("Directed filter off\n");
skb->data[0] = 0x00;
skb->data[1] = 0x00;
return;
}
if ((self->provider.filter_type == IRLAN_BROADCAST) &&
(self->provider.filter_mode == FILTER))
{
pr_debug("Broadcast filter on\n");
skb->data[0] = 0x00;
skb->data[1] = 0x00;
return;
}
if ((self->provider.filter_type == IRLAN_BROADCAST) &&
(self->provider.filter_mode == NONE))
{
pr_debug("Broadcast filter off\n");
skb->data[0] = 0x00;
skb->data[1] = 0x00;
return;
}
if ((self->provider.filter_type == IRLAN_MULTICAST) &&
(self->provider.filter_mode == FILTER))
{
pr_debug("Multicast filter on\n");
skb->data[0] = 0x00;
skb->data[1] = 0x00;
return;
}
if ((self->provider.filter_type == IRLAN_MULTICAST) &&
(self->provider.filter_mode == NONE))
{
pr_debug("Multicast filter off\n");
skb->data[0] = 0x00;
skb->data[1] = 0x00;
return;
}
if ((self->provider.filter_type == IRLAN_MULTICAST) &&
(self->provider.filter_operation == GET))
{
pr_debug("Multicast filter get\n");
skb->data[0] = 0x00;
skb->data[1] = 0x02;
irlan_insert_string_param(skb, "FILTER_MODE", "NONE");
irlan_insert_short_param(skb, "MAX_ENTRY", 16);
return;
}
skb->data[0] = 0x00;
skb->data[1] = 0x00;
pr_debug("Not implemented!\n");
}
void irlan_check_command_param(struct irlan_cb *self, char *param, char *value)
{
IRDA_ASSERT(self != NULL, return;);
IRDA_ASSERT(self->magic == IRLAN_MAGIC, return;);
pr_debug("%s, %s\n", param, value);
if (strcmp(param, "MODE") == 0) {
self->use_udata = TRUE;
return;
}
if (strcmp(param, "FILTER_TYPE") == 0) {
if (strcmp(value, "DIRECTED") == 0) {
self->provider.filter_type = IRLAN_DIRECTED;
return;
}
if (strcmp(value, "MULTICAST") == 0) {
self->provider.filter_type = IRLAN_MULTICAST;
return;
}
if (strcmp(value, "BROADCAST") == 0) {
self->provider.filter_type = IRLAN_BROADCAST;
return;
}
}
if (strcmp(param, "FILTER_MODE") == 0) {
if (strcmp(value, "ALL") == 0) {
self->provider.filter_mode = ALL;
return;
}
if (strcmp(value, "FILTER") == 0) {
self->provider.filter_mode = FILTER;
return;
}
if (strcmp(value, "NONE") == 0) {
self->provider.filter_mode = FILTER;
return;
}
}
if (strcmp(param, "FILTER_OPERATION") == 0) {
if (strcmp(value, "DYNAMIC") == 0) {
self->provider.filter_operation = DYNAMIC;
return;
}
if (strcmp(value, "GET") == 0) {
self->provider.filter_operation = GET;
return;
}
}
}
void irlan_print_filter(struct seq_file *seq, int filter_type)
{
static struct {
int mask;
const char *str;
} filter_mask2str[] = {
MASK2STR(IRLAN_DIRECTED, "DIRECTED"),
MASK2STR(IRLAN_FUNCTIONAL, "FUNCTIONAL"),
MASK2STR(IRLAN_GROUP, "GROUP"),
MASK2STR(IRLAN_MAC_FRAME, "MAC_FRAME"),
MASK2STR(IRLAN_MULTICAST, "MULTICAST"),
MASK2STR(IRLAN_BROADCAST, "BROADCAST"),
MASK2STR(IRLAN_IPX_SOCKET, "IPX_SOCKET"),
MASK2STR(0, NULL)
}, *p;
for (p = filter_mask2str; p->str; p++) {
if (filter_type & p->mask)
seq_printf(seq, "%s ", p->str);
}
seq_putc(seq, '\n');
}
