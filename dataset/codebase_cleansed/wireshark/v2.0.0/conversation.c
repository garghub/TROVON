static conversation_t *
conversation_create_from_template(conversation_t *conversation, const address *addr2, const guint32 port2)
{
if(conversation->options & CONVERSATION_TEMPLATE &&
conversation->key_ptr->ptype != PT_UDP)
{
conversation_t *new_conversation_from_template;
guint options = conversation->options & ~(CONVERSATION_TEMPLATE | NO_ADDR2 | NO_PORT2);
if(conversation->options & NO_ADDR2 &&
conversation->options & NO_PORT2)
{
new_conversation_from_template =
conversation_new(conversation->setup_frame,
&conversation->key_ptr->addr1, addr2,
conversation->key_ptr->ptype, conversation->key_ptr->port1,
port2, options);
}
else if(conversation->options & NO_PORT2)
{
new_conversation_from_template =
conversation_new(conversation->setup_frame,
&conversation->key_ptr->addr1, &conversation->key_ptr->addr2,
conversation->key_ptr->ptype, conversation->key_ptr->port1,
port2, options);
}
else if(conversation->options & NO_ADDR2)
{
new_conversation_from_template =
conversation_new(conversation->setup_frame,
&conversation->key_ptr->addr1, addr2,
conversation->key_ptr->ptype, conversation->key_ptr->port1,
conversation->key_ptr->port2, options);
}
else
{
return conversation;
}
new_conversation_from_template->dissector_tree = conversation->dissector_tree;
return new_conversation_from_template;
}
else
{
return conversation;
}
}
static guint
conversation_hash_exact(gconstpointer v)
{
const conversation_key *key = (const conversation_key *)v;
guint hash_val;
address tmp_addr;
hash_val = 0;
tmp_addr.len = 4;
ADD_ADDRESS_TO_HASH(hash_val, &key->addr1);
tmp_addr.data = &key->port1;
ADD_ADDRESS_TO_HASH(hash_val, &tmp_addr);
ADD_ADDRESS_TO_HASH(hash_val, &key->addr2);
tmp_addr.data = &key->port2;
ADD_ADDRESS_TO_HASH(hash_val, &tmp_addr);
hash_val += ( hash_val << 3 );
hash_val ^= ( hash_val >> 11 );
hash_val += ( hash_val << 15 );
return hash_val;
}
static gint
conversation_match_exact(gconstpointer v, gconstpointer w)
{
const conversation_key *v1 = (const conversation_key *)v;
const conversation_key *v2 = (const conversation_key *)w;
if (v1->ptype != v2->ptype)
return 0;
if (v1->port1 == v2->port1 &&
v1->port2 == v2->port2 &&
ADDRESSES_EQUAL(&v1->addr1, &v2->addr1) &&
ADDRESSES_EQUAL(&v1->addr2, &v2->addr2)) {
return 1;
}
if (v1->port2 == v2->port1 &&
v1->port1 == v2->port2 &&
ADDRESSES_EQUAL(&v1->addr2, &v2->addr1) &&
ADDRESSES_EQUAL(&v1->addr1, &v2->addr2)) {
return 1;
}
return 0;
}
static guint
conversation_hash_no_addr2(gconstpointer v)
{
const conversation_key *key = (const conversation_key *)v;
guint hash_val;
address tmp_addr;
hash_val = 0;
tmp_addr.len = 4;
ADD_ADDRESS_TO_HASH(hash_val, &key->addr1);
tmp_addr.data = &key->port1;
ADD_ADDRESS_TO_HASH(hash_val, &tmp_addr);
tmp_addr.data = &key->port2;
ADD_ADDRESS_TO_HASH(hash_val, &tmp_addr);
hash_val += ( hash_val << 3 );
hash_val ^= ( hash_val >> 11 );
hash_val += ( hash_val << 15 );
return hash_val;
}
static gint
conversation_match_no_addr2(gconstpointer v, gconstpointer w)
{
const conversation_key *v1 = (const conversation_key *)v;
const conversation_key *v2 = (const conversation_key *)w;
if (v1->ptype != v2->ptype)
return 0;
if (v1->port1 == v2->port1 &&
v1->port2 == v2->port2 &&
ADDRESSES_EQUAL(&v1->addr1, &v2->addr1)) {
return 1;
}
return 0;
}
static guint
conversation_hash_no_port2(gconstpointer v)
{
const conversation_key *key = (const conversation_key *)v;
guint hash_val;
address tmp_addr;
hash_val = 0;
tmp_addr.len = 4;
ADD_ADDRESS_TO_HASH(hash_val, &key->addr1);
tmp_addr.data = &key->port1;
ADD_ADDRESS_TO_HASH(hash_val, &tmp_addr);
ADD_ADDRESS_TO_HASH(hash_val, &key->addr2);
hash_val += ( hash_val << 3 );
hash_val ^= ( hash_val >> 11 );
hash_val += ( hash_val << 15 );
return hash_val;
}
static gint
conversation_match_no_port2(gconstpointer v, gconstpointer w)
{
const conversation_key *v1 = (const conversation_key *)v;
const conversation_key *v2 = (const conversation_key *)w;
if (v1->ptype != v2->ptype)
return 0;
if (v1->port1 == v2->port1 &&
ADDRESSES_EQUAL(&v1->addr1, &v2->addr1) &&
ADDRESSES_EQUAL(&v1->addr2, &v2->addr2)) {
return 1;
}
return 0;
}
static guint
conversation_hash_no_addr2_or_port2(gconstpointer v)
{
const conversation_key *key = (const conversation_key *)v;
guint hash_val;
address tmp_addr;
hash_val = 0;
tmp_addr.len = 4;
ADD_ADDRESS_TO_HASH(hash_val, &key->addr1);
tmp_addr.data = &key->port1;
ADD_ADDRESS_TO_HASH(hash_val, &tmp_addr);
hash_val += ( hash_val << 3 );
hash_val ^= ( hash_val >> 11 );
hash_val += ( hash_val << 15 );
return hash_val;
}
static gint
conversation_match_no_addr2_or_port2(gconstpointer v, gconstpointer w)
{
const conversation_key *v1 = (const conversation_key *)v;
const conversation_key *v2 = (const conversation_key *)w;
if (v1->ptype != v2->ptype)
return 0;
if (v1->port1 == v2->port1 &&
ADDRESSES_EQUAL(&v1->addr1, &v2->addr1)) {
return 1;
}
return 0;
}
static void
free_data_list(gpointer value)
{
conversation_t *conv = (conversation_t *)value;
g_slist_free(conv->data_list);
conv->data_list = NULL;
}
void
conversation_cleanup(void)
{
conversation_keys = NULL;
if (conversation_hashtable_exact != NULL) {
g_hash_table_destroy(conversation_hashtable_exact);
}
if (conversation_hashtable_no_addr2 != NULL) {
g_hash_table_destroy(conversation_hashtable_no_addr2);
}
if (conversation_hashtable_no_port2 != NULL) {
g_hash_table_destroy(conversation_hashtable_no_port2);
}
if (conversation_hashtable_no_addr2_or_port2 != NULL) {
g_hash_table_destroy(conversation_hashtable_no_addr2_or_port2);
}
conversation_hashtable_exact = NULL;
conversation_hashtable_no_addr2 = NULL;
conversation_hashtable_no_port2 = NULL;
conversation_hashtable_no_addr2_or_port2 = NULL;
}
void
conversation_init(void)
{
conversation_hashtable_exact =
g_hash_table_new_full(conversation_hash_exact,
conversation_match_exact, NULL, free_data_list);
conversation_hashtable_no_addr2 =
g_hash_table_new_full(conversation_hash_no_addr2,
conversation_match_no_addr2, NULL, free_data_list);
conversation_hashtable_no_port2 =
g_hash_table_new_full(conversation_hash_no_port2,
conversation_match_no_port2, NULL, free_data_list);
conversation_hashtable_no_addr2_or_port2 =
g_hash_table_new_full(conversation_hash_no_addr2_or_port2,
conversation_match_no_addr2_or_port2, NULL, free_data_list);
new_index = 0;
}
static void
conversation_insert_into_hashtable(GHashTable *hashtable, conversation_t *conv)
{
conversation_t *chain_head, *chain_tail, *cur, *prev;
chain_head = (conversation_t *)g_hash_table_lookup(hashtable, conv->key_ptr);
if (NULL==chain_head) {
conv->next = NULL;
conv->last = conv;
g_hash_table_insert(hashtable, conv->key_ptr, conv);
DPRINT(("created a new conversation chain"));
}
else {
DPRINT(("there's an existing conversation chain"));
chain_tail = chain_head->last;
if(conv->setup_frame >= chain_tail->setup_frame) {
conv->next = NULL;
conv->last = NULL;
chain_tail->next = conv;
chain_head->last = conv;
}
else {
cur = chain_head;
prev = NULL;
for (; (conv->setup_frame > cur->setup_frame) && cur->next; prev=cur, cur=cur->next)
;
if (NULL==prev) {
conv->next = chain_head;
conv->last = chain_tail;
chain_head->last = NULL;
g_hash_table_insert(hashtable, conv->key_ptr, conv);
}
else {
conv->next = cur;
conv->last = NULL;
prev->next = conv;
}
}
}
}
static void
conversation_remove_from_hashtable(GHashTable *hashtable, conversation_t *conv)
{
conversation_t *chain_head, *cur, *prev;
chain_head = (conversation_t *)g_hash_table_lookup(hashtable, conv->key_ptr);
if (conv == chain_head) {
if (NULL == conv->next) {
g_hash_table_steal(hashtable, conv->key_ptr);
}
else {
chain_head = conv->next;
chain_head->last = conv->last;
if (conv->latest_found == conv)
chain_head->latest_found = NULL;
else
chain_head->latest_found = conv->latest_found;
g_hash_table_insert(hashtable, chain_head->key_ptr, chain_head);
}
}
else {
cur = chain_head->next;
prev = chain_head;
for (; (cur != conv) && cur->next; prev=cur, cur=cur->next)
;
if (cur != conv) {
return;
}
prev->next = conv->next;
if (NULL == conv->next) {
chain_head->last = prev;
}
if (chain_head->latest_found == conv)
chain_head->latest_found = prev;
}
}
conversation_t *
conversation_new(const guint32 setup_frame, const address *addr1, const address *addr2, const port_type ptype,
const guint32 port1, const guint32 port2, const guint options)
{
GHashTable* hashtable;
conversation_t *conversation=NULL;
conversation_key *new_key;
DPRINT(("creating conversation for frame #%d: %s:%d -> %s:%d (ptype=%d)",
setup_frame, address_to_str(wmem_packet_scope(), addr1), port1,
address_to_str(wmem_packet_scope(), addr2), port2, ptype));
if (options & NO_ADDR2) {
if (options & (NO_PORT2|NO_PORT2_FORCE)) {
hashtable = conversation_hashtable_no_addr2_or_port2;
} else {
hashtable = conversation_hashtable_no_addr2;
}
} else {
if (options & (NO_PORT2|NO_PORT2_FORCE)) {
hashtable = conversation_hashtable_no_port2;
} else {
hashtable = conversation_hashtable_exact;
}
}
new_key = wmem_new(wmem_file_scope(), struct conversation_key);
new_key->next = conversation_keys;
conversation_keys = new_key;
WMEM_COPY_ADDRESS(wmem_file_scope(), &new_key->addr1, addr1);
WMEM_COPY_ADDRESS(wmem_file_scope(), &new_key->addr2, addr2);
new_key->ptype = ptype;
new_key->port1 = port1;
new_key->port2 = port2;
conversation = wmem_new(wmem_file_scope(), conversation_t);
memset(conversation, 0, sizeof(conversation_t));
conversation->index = new_index;
conversation->setup_frame = conversation->last_frame = setup_frame;
conversation->data_list = NULL;
conversation->dissector_tree = wmem_tree_new(wmem_file_scope());
conversation->options = options;
conversation->key_ptr = new_key;
new_index++;
DINDENT();
conversation_insert_into_hashtable(hashtable, conversation);
DENDENT();
return conversation;
}
void
conversation_set_port2(conversation_t *conv, const guint32 port)
{
DISSECTOR_ASSERT_HINT(!(conv->options & CONVERSATION_TEMPLATE),
"Use the conversation_create_from_template function when the CONVERSATION_TEMPLATE bit is set in the options mask");
DPRINT(("called for port=%d", port));
if ((!(conv->options & NO_PORT2)) || (conv->options & NO_PORT2_FORCE))
return;
DINDENT();
if (conv->options & NO_ADDR2) {
conversation_remove_from_hashtable(conversation_hashtable_no_addr2_or_port2, conv);
} else {
conversation_remove_from_hashtable(conversation_hashtable_no_port2, conv);
}
conv->options &= ~NO_PORT2;
conv->key_ptr->port2 = port;
if (conv->options & NO_ADDR2) {
conversation_insert_into_hashtable(conversation_hashtable_no_addr2, conv);
} else {
conversation_insert_into_hashtable(conversation_hashtable_exact, conv);
}
DENDENT();
}
void
conversation_set_addr2(conversation_t *conv, const address *addr)
{
char* addr_str;
DISSECTOR_ASSERT_HINT(!(conv->options & CONVERSATION_TEMPLATE),
"Use the conversation_create_from_template function when the CONVERSATION_TEMPLATE bit is set in the options mask");
addr_str = address_to_str(NULL, addr);
DPRINT(("called for addr=%s", addr_str));
wmem_free(NULL, addr_str);
if (!(conv->options & NO_ADDR2))
return;
DINDENT();
if (conv->options & NO_PORT2) {
conversation_remove_from_hashtable(conversation_hashtable_no_addr2_or_port2, conv);
} else {
conversation_remove_from_hashtable(conversation_hashtable_no_port2, conv);
}
conv->options &= ~NO_ADDR2;
WMEM_COPY_ADDRESS(wmem_file_scope(), &conv->key_ptr->addr2, addr);
if (conv->options & NO_PORT2) {
conversation_insert_into_hashtable(conversation_hashtable_no_port2, conv);
} else {
conversation_insert_into_hashtable(conversation_hashtable_exact, conv);
}
DENDENT();
}
static conversation_t *
conversation_lookup_hashtable(GHashTable *hashtable, const guint32 frame_num, const address *addr1, const address *addr2,
const port_type ptype, const guint32 port1, const guint32 port2)
{
conversation_t* convo=NULL;
conversation_t* match=NULL;
conversation_t* chain_head=NULL;
conversation_key key;
key.addr1 = *addr1;
key.addr2 = *addr2;
key.ptype = ptype;
key.port1 = port1;
key.port2 = port2;
chain_head = (conversation_t *)g_hash_table_lookup(hashtable, &key);
if (chain_head && (chain_head->setup_frame <= frame_num)) {
match = chain_head;
if((chain_head->last)&&(chain_head->last->setup_frame<=frame_num))
return chain_head->last;
if((chain_head->latest_found)&&(chain_head->latest_found->setup_frame<=frame_num))
match = chain_head->latest_found;
for (convo = match; convo && convo->setup_frame <= frame_num; convo = convo->next) {
if (convo->setup_frame > match->setup_frame) {
match = convo;
}
}
}
if (match)
chain_head->latest_found = match;
return match;
}
conversation_t *
find_conversation(const guint32 frame_num, const address *addr_a, const address *addr_b, const port_type ptype,
const guint32 port_a, const guint32 port_b, const guint options)
{
conversation_t *conversation;
if (!(options & (NO_ADDR_B|NO_PORT_B))) {
DPRINT(("trying exact match"));
conversation =
conversation_lookup_hashtable(conversation_hashtable_exact,
frame_num, addr_a, addr_b, ptype,
port_a, port_b);
if (conversation == NULL) {
DPRINT(("trying opposite direction"));
conversation =
conversation_lookup_hashtable(conversation_hashtable_exact,
frame_num, addr_b, addr_a, ptype,
port_b, port_a);
}
if ((conversation == NULL) && (addr_a->type == AT_FC)) {
conversation =
conversation_lookup_hashtable(conversation_hashtable_exact,
frame_num, addr_b, addr_a, ptype,
port_a, port_b);
}
DPRINT(("exact match %sfound",conversation?"":"not "));
if (conversation != NULL)
return conversation;
}
if (!(options & NO_PORT_B)) {
DPRINT(("trying wildcarded dest address"));
conversation =
conversation_lookup_hashtable(conversation_hashtable_no_addr2,
frame_num, addr_a, addr_b, ptype, port_a, port_b);
if ((conversation == NULL) && (addr_a->type == AT_FC)) {
conversation =
conversation_lookup_hashtable(conversation_hashtable_no_addr2,
frame_num, addr_b, addr_a, ptype,
port_a, port_b);
}
if (conversation != NULL) {
DPRINT(("wildcarded dest address match found"));
if (!(conversation->options & NO_ADDR_B) && ptype != PT_UDP)
{
if(!(conversation->options & CONVERSATION_TEMPLATE))
{
conversation_set_addr2(conversation, addr_b);
}
else
{
conversation =
conversation_create_from_template(conversation, addr_b, 0);
}
}
return conversation;
}
if (!(options & NO_ADDR_B)) {
DPRINT(("trying dest addr:port as source addr:port with wildcarded dest addr"));
conversation =
conversation_lookup_hashtable(conversation_hashtable_no_addr2,
frame_num, addr_b, addr_a, ptype, port_b, port_a);
if (conversation != NULL) {
DPRINT(("match found"));
if (ptype != PT_UDP) {
if(!(conversation->options & CONVERSATION_TEMPLATE))
{
conversation_set_addr2(conversation, addr_a);
}
else
{
conversation =
conversation_create_from_template(conversation, addr_a, 0);
}
}
return conversation;
}
}
}
if (!(options & NO_ADDR_B)) {
DPRINT(("trying wildcarded dest port"));
conversation =
conversation_lookup_hashtable(conversation_hashtable_no_port2,
frame_num, addr_a, addr_b, ptype, port_a, port_b);
if ((conversation == NULL) && (addr_a->type == AT_FC)) {
conversation =
conversation_lookup_hashtable(conversation_hashtable_no_port2,
frame_num, addr_b, addr_a, ptype, port_a, port_b);
}
if (conversation != NULL) {
DPRINT(("match found"));
if (!(conversation->options & NO_PORT_B) && ptype != PT_UDP)
{
if(!(conversation->options & CONVERSATION_TEMPLATE))
{
conversation_set_port2(conversation, port_b);
}
else
{
conversation =
conversation_create_from_template(conversation, 0, port_b);
}
}
return conversation;
}
if (!(options & NO_PORT_B)) {
DPRINT(("trying dest addr:port as source addr:port and wildcarded dest port"));
conversation =
conversation_lookup_hashtable(conversation_hashtable_no_port2,
frame_num, addr_b, addr_a, ptype, port_b, port_a);
if (conversation != NULL) {
DPRINT(("match found"));
if (ptype != PT_UDP)
{
if(!(conversation->options & CONVERSATION_TEMPLATE))
{
conversation_set_port2(conversation, port_a);
}
else
{
conversation =
conversation_create_from_template(conversation, 0, port_a);
}
}
return conversation;
}
}
}
DPRINT(("trying wildcarding dest addr:port"));
conversation =
conversation_lookup_hashtable(conversation_hashtable_no_addr2_or_port2,
frame_num, addr_a, addr_b, ptype, port_a, port_b);
if (conversation != NULL) {
DPRINT(("match found"));
if (ptype != PT_UDP)
{
if(!(conversation->options & CONVERSATION_TEMPLATE))
{
if (!(conversation->options & NO_ADDR_B))
conversation_set_addr2(conversation, addr_b);
if (!(conversation->options & NO_PORT_B))
conversation_set_port2(conversation, port_b);
}
else
{
conversation =
conversation_create_from_template(conversation, addr_b, port_b);
}
}
return conversation;
}
DPRINT(("trying dest addr:port as source addr:port and wildcarding dest addr:port"));
if (addr_a->type == AT_FC)
conversation =
conversation_lookup_hashtable(conversation_hashtable_no_addr2_or_port2,
frame_num, addr_b, addr_a, ptype, port_a, port_b);
else
conversation =
conversation_lookup_hashtable(conversation_hashtable_no_addr2_or_port2,
frame_num, addr_b, addr_a, ptype, port_b, port_a);
if (conversation != NULL) {
DPRINT(("match found"));
if (ptype != PT_UDP)
{
if(!(conversation->options & CONVERSATION_TEMPLATE))
{
conversation_set_addr2(conversation, addr_a);
conversation_set_port2(conversation, port_a);
}
else
{
conversation = conversation_create_from_template(conversation, addr_a, port_a);
}
}
return conversation;
}
DPRINT(("no matches found"));
return NULL;
}
static gint
p_compare(gconstpointer a, gconstpointer b)
{
const conv_proto_data *ap = (const conv_proto_data *)a;
const conv_proto_data *bp = (const conv_proto_data *)b;
if (ap->proto > bp->proto)
return 1;
else if (ap->proto == bp->proto)
return 0;
else
return -1;
}
void
conversation_add_proto_data(conversation_t *conv, const int proto, void *proto_data)
{
conv_proto_data *p1 = wmem_new(wmem_file_scope(), conv_proto_data);
p1->proto = proto;
p1->proto_data = proto_data;
conv->data_list = g_slist_insert_sorted(conv->data_list, (gpointer *)p1,
p_compare);
}
void *
conversation_get_proto_data(const conversation_t *conv, const int proto)
{
conv_proto_data temp, *p1;
GSList *item;
temp.proto = proto;
temp.proto_data = NULL;
item = g_slist_find_custom(conv->data_list, (gpointer *)&temp,
p_compare);
if (item != NULL) {
p1 = (conv_proto_data *)item->data;
return p1->proto_data;
}
return NULL;
}
void
conversation_delete_proto_data(conversation_t *conv, const int proto)
{
conv_proto_data temp;
GSList *item;
temp.proto = proto;
temp.proto_data = NULL;
item = g_slist_find_custom(conv->data_list, (gpointer *)&temp,
p_compare);
while(item){
conv->data_list = g_slist_remove(conv->data_list, item->data);
item=item->next;
}
}
void
conversation_set_dissector_from_frame_number(conversation_t *conversation,
const guint32 starting_frame_num, const dissector_handle_t handle)
{
wmem_tree_insert32(conversation->dissector_tree, starting_frame_num, (void *)handle);
}
void
conversation_set_dissector(conversation_t *conversation, const dissector_handle_t handle)
{
conversation_set_dissector_from_frame_number(conversation, 0, handle);
}
dissector_handle_t
conversation_get_dissector(conversation_t *conversation, const guint32 frame_num)
{
return (dissector_handle_t)wmem_tree_lookup32_le(conversation->dissector_tree, frame_num);
}
gboolean
try_conversation_dissector(const address *addr_a, const address *addr_b, const port_type ptype,
const guint32 port_a, const guint32 port_b, tvbuff_t *tvb, packet_info *pinfo,
proto_tree *tree, void* data)
{
conversation_t *conversation;
conversation = find_conversation(pinfo->fd->num, addr_a, addr_b, ptype, port_a,
port_b, 0);
if (conversation != NULL) {
int ret;
dissector_handle_t handle = (dissector_handle_t)wmem_tree_lookup32_le(conversation->dissector_tree, pinfo->fd->num);
if (handle == NULL)
return FALSE;
ret=call_dissector_only(handle, tvb, pinfo, tree, data);
if(!ret) {
return FALSE;
}
return TRUE;
}
return FALSE;
}
conversation_t *
find_or_create_conversation(packet_info *pinfo)
{
conversation_t *conv=NULL;
DPRINT(("called for frame #%d: %s:%d -> %s:%d (ptype=%d)",
pinfo->fd->num, address_to_str(wmem_packet_scope(), &pinfo->src), pinfo->srcport,
address_to_str(wmem_packet_scope(), &pinfo->dst), pinfo->destport, pinfo->ptype));
DINDENT();
if((conv = find_conversation(pinfo->fd->num, &pinfo->src, &pinfo->dst,
pinfo->ptype, pinfo->srcport,
pinfo->destport, 0)) != NULL) {
DPRINT(("found previous conversation for frame #%d (last_frame=%d)",
pinfo->fd->num, conv->last_frame));
if (pinfo->fd->num > conv->last_frame) {
conv->last_frame = pinfo->fd->num;
}
} else {
DPRINT(("did not find previous conversation for frame #%d",
pinfo->fd->num));
DINDENT();
conv = conversation_new(pinfo->fd->num, &pinfo->src,
&pinfo->dst, pinfo->ptype,
pinfo->srcport, pinfo->destport, 0);
DENDENT();
}
DENDENT();
return conv;
}
GHashTable *
get_conversation_hashtable_exact(void)
{
return conversation_hashtable_exact;
}
GHashTable *
get_conversation_hashtable_no_addr2(void)
{
return conversation_hashtable_no_addr2;
}
GHashTable *
get_conversation_hashtable_no_port2(void)
{
return conversation_hashtable_no_port2;
}
GHashTable *
get_conversation_hashtable_no_addr2_or_port2(void)
{
return conversation_hashtable_no_addr2_or_port2;
}
