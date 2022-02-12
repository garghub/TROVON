static guint
fragment_addresses_hash(gconstpointer k)
{
const fragment_addresses_key* key = (const fragment_addresses_key*) k;
guint hash_val;
hash_val = 0;
hash_val += key->id;
return hash_val;
}
static gint
fragment_addresses_equal(gconstpointer k1, gconstpointer k2)
{
const fragment_addresses_key* key1 = (const fragment_addresses_key*) k1;
const fragment_addresses_key* key2 = (const fragment_addresses_key*) k2;
return (key1->id == key2->id) &&
(addresses_equal(&key1->src, &key2->src)) &&
(addresses_equal(&key1->dst, &key2->dst));
}
static gpointer
fragment_addresses_temporary_key(const packet_info *pinfo, const guint32 id,
const void *data _U_)
{
fragment_addresses_key *key = g_slice_new(fragment_addresses_key);
copy_address_shallow(&key->src, &pinfo->src);
copy_address_shallow(&key->dst, &pinfo->dst);
key->id = id;
return (gpointer)key;
}
static gpointer
fragment_addresses_persistent_key(const packet_info *pinfo, const guint32 id,
const void *data _U_)
{
fragment_addresses_key *key = g_slice_new(fragment_addresses_key);
copy_address(&key->src, &pinfo->src);
copy_address(&key->dst, &pinfo->dst);
key->id = id;
return (gpointer)key;
}
static void
fragment_addresses_free_temporary_key(gpointer ptr)
{
fragment_addresses_key *key = (fragment_addresses_key *)ptr;
if(key)
g_slice_free(fragment_addresses_key, key);
}
static void
fragment_addresses_free_persistent_key(gpointer ptr)
{
fragment_addresses_key *key = (fragment_addresses_key *)ptr;
if(key){
free_address(&key->src);
free_address(&key->dst);
g_slice_free(fragment_addresses_key, key);
}
}
static guint
fragment_addresses_ports_hash(gconstpointer k)
{
const fragment_addresses_ports_key* key = (const fragment_addresses_ports_key*) k;
guint hash_val;
hash_val = 0;
hash_val += key->id;
return hash_val;
}
static gint
fragment_addresses_ports_equal(gconstpointer k1, gconstpointer k2)
{
const fragment_addresses_ports_key* key1 = (const fragment_addresses_ports_key*) k1;
const fragment_addresses_ports_key* key2 = (const fragment_addresses_ports_key*) k2;
return (key1->id == key2->id) &&
(addresses_equal(&key1->src_addr, &key2->src_addr)) &&
(addresses_equal(&key1->dst_addr, &key2->dst_addr)) &&
(key1->src_port == key2->src_port) &&
(key1->dst_port == key2->dst_port);
}
static gpointer
fragment_addresses_ports_temporary_key(const packet_info *pinfo, const guint32 id,
const void *data _U_)
{
fragment_addresses_ports_key *key = g_slice_new(fragment_addresses_ports_key);
copy_address_shallow(&key->src_addr, &pinfo->src);
copy_address_shallow(&key->dst_addr, &pinfo->dst);
key->src_port = pinfo->srcport;
key->dst_port = pinfo->destport;
key->id = id;
return (gpointer)key;
}
static gpointer
fragment_addresses_ports_persistent_key(const packet_info *pinfo,
const guint32 id, const void *data _U_)
{
fragment_addresses_ports_key *key = g_slice_new(fragment_addresses_ports_key);
copy_address(&key->src_addr, &pinfo->src);
copy_address(&key->dst_addr, &pinfo->dst);
key->src_port = pinfo->srcport;
key->dst_port = pinfo->destport;
key->id = id;
return (gpointer)key;
}
static void
fragment_addresses_ports_free_temporary_key(gpointer ptr)
{
fragment_addresses_ports_key *key = (fragment_addresses_ports_key *)ptr;
if(key)
g_slice_free(fragment_addresses_ports_key, key);
}
static void
fragment_addresses_ports_free_persistent_key(gpointer ptr)
{
fragment_addresses_ports_key *key = (fragment_addresses_ports_key *)ptr;
if(key){
free_address(&key->src_addr);
free_address(&key->dst_addr);
g_slice_free(fragment_addresses_ports_key, key);
}
}
static gint
reassembled_equal(gconstpointer k1, gconstpointer k2)
{
const reassembled_key* key1 = (const reassembled_key*) k1;
const reassembled_key* key2 = (const reassembled_key*) k2;
return key1->frame == key2->frame && key1->id == key2->id;
}
static guint
reassembled_hash(gconstpointer k)
{
const reassembled_key* key = (const reassembled_key*) k;
return key->frame;
}
static void
reassembled_key_free(gpointer ptr)
{
g_slice_free(reassembled_key, (reassembled_key *)ptr);
}
static gboolean
free_all_fragments(gpointer key_arg _U_, gpointer value, gpointer user_data _U_)
{
fragment_head *fd_head;
fragment_item *tmp_fd;
for (fd_head = (fragment_head *)value; fd_head != NULL; fd_head = tmp_fd) {
tmp_fd=fd_head->next;
if(fd_head->tvb_data && !(fd_head->flags&FD_SUBSET_TVB))
tvb_free(fd_head->tvb_data);
g_slice_free(fragment_item, fd_head);
}
return TRUE;
}
static fragment_head *new_head(const guint32 flags)
{
fragment_head *fd_head;
fd_head=g_slice_new0(fragment_head);
fd_head->flags=flags;
return fd_head;
}
static gboolean
free_all_reassembled_fragments(gpointer key_arg _U_, gpointer value,
gpointer user_data)
{
GPtrArray *allocated_fragments = (GPtrArray *) user_data;
fragment_head *fd_head;
for (fd_head = (fragment_head *)value; fd_head != NULL; fd_head = fd_head->next) {
if (fd_head->flags != FD_VISITED_FREE) {
if (fd_head->flags & FD_SUBSET_TVB)
fd_head->tvb_data = NULL;
g_ptr_array_add(allocated_fragments, fd_head);
fd_head->flags = FD_VISITED_FREE;
}
}
return TRUE;
}
static void
free_fragments(gpointer data, gpointer user_data _U_)
{
fragment_item *fd_head = (fragment_item *) data;
if (fd_head->tvb_data)
tvb_free(fd_head->tvb_data);
g_slice_free(fragment_item, fd_head);
}
void
reassembly_table_register(reassembly_table *table,
const reassembly_table_functions *funcs)
{
register_reassembly_table_t* reg_table;
DISSECTOR_ASSERT(table);
DISSECTOR_ASSERT(funcs);
reg_table = g_new(register_reassembly_table_t,1);
reg_table->table = table;
reg_table->funcs = funcs;
reassembly_table_list = g_list_prepend(reassembly_table_list, reg_table);
}
void
reassembly_table_init(reassembly_table *table,
const reassembly_table_functions *funcs)
{
if (table->temporary_key_func == NULL)
table->temporary_key_func = funcs->temporary_key_func;
if (table->persistent_key_func == NULL)
table->persistent_key_func = funcs->persistent_key_func;
if (table->free_temporary_key_func == NULL)
table->free_temporary_key_func = funcs->free_temporary_key_func;
if (table->fragment_table != NULL) {
g_hash_table_foreach_remove(table->fragment_table,
free_all_fragments, NULL);
} else {
table->fragment_table = g_hash_table_new_full(funcs->hash_func,
funcs->equal_func, funcs->free_persistent_key_func, NULL);
}
if (table->reassembled_table != NULL) {
GPtrArray *allocated_fragments;
allocated_fragments = g_ptr_array_new();
g_hash_table_foreach_remove(table->reassembled_table,
free_all_reassembled_fragments, allocated_fragments);
g_ptr_array_foreach(allocated_fragments, free_fragments, NULL);
g_ptr_array_free(allocated_fragments, TRUE);
} else {
table->reassembled_table = g_hash_table_new_full(reassembled_hash,
reassembled_equal, reassembled_key_free, NULL);
}
}
void
reassembly_table_destroy(reassembly_table *table)
{
table->temporary_key_func = NULL;
table->persistent_key_func = NULL;
table->free_temporary_key_func = NULL;
if (table->fragment_table != NULL) {
g_hash_table_foreach_remove(table->fragment_table,
free_all_fragments, NULL);
g_hash_table_destroy(table->fragment_table);
table->fragment_table = NULL;
}
if (table->reassembled_table != NULL) {
GPtrArray *allocated_fragments;
allocated_fragments = g_ptr_array_new();
g_hash_table_foreach_remove(table->reassembled_table,
free_all_reassembled_fragments, allocated_fragments);
g_ptr_array_foreach(allocated_fragments, free_fragments, NULL);
g_ptr_array_free(allocated_fragments, TRUE);
g_hash_table_destroy(table->reassembled_table);
table->reassembled_table = NULL;
}
}
static fragment_head *
lookup_fd_head(reassembly_table *table, const packet_info *pinfo,
const guint32 id, const void *data, gpointer *orig_keyp)
{
gpointer key;
gpointer value;
key = table->temporary_key_func(pinfo, id, data);
if (!g_hash_table_lookup_extended(table->fragment_table, key, orig_keyp,
&value))
value = NULL;
table->free_temporary_key_func(key);
return (fragment_head *)value;
}
static gpointer
insert_fd_head(reassembly_table *table, fragment_head *fd_head,
const packet_info *pinfo, const guint32 id, const void *data)
{
gpointer key;
key = table->persistent_key_func(pinfo, id, data);
g_hash_table_insert(table->fragment_table, key, fd_head);
return key;
}
tvbuff_t *
fragment_delete(reassembly_table *table, const packet_info *pinfo,
const guint32 id, const void *data)
{
fragment_head *fd_head;
fragment_item *fd;
tvbuff_t *fd_tvb_data=NULL;
gpointer key;
fd_head = lookup_fd_head(table, pinfo, id, data, &key);
if(fd_head==NULL){
return NULL;
}
fd_tvb_data=fd_head->tvb_data;
for(fd=fd_head->next;fd;){
fragment_item *tmp_fd;
tmp_fd=fd->next;
if (fd->tvb_data && !(fd->flags & FD_SUBSET_TVB))
tvb_free(fd->tvb_data);
g_slice_free(fragment_item, fd);
fd=tmp_fd;
}
g_slice_free(fragment_head, fd_head);
g_hash_table_remove(table->fragment_table, key);
return fd_tvb_data;
}
fragment_head *
fragment_get(reassembly_table *table, const packet_info *pinfo,
const guint32 id, const void *data)
{
return lookup_fd_head(table, pinfo, id, data, NULL);
}
fragment_head *
fragment_get_reassembled(reassembly_table *table, const guint32 id)
{
fragment_head *fd_head;
reassembled_key key;
key.frame = id;
key.id = id;
fd_head = (fragment_head *)g_hash_table_lookup(table->reassembled_table, &key);
return fd_head;
}
fragment_head *
fragment_get_reassembled_id(reassembly_table *table, const packet_info *pinfo,
const guint32 id)
{
fragment_head *fd_head;
reassembled_key key;
key.frame = pinfo->num;
key.id = id;
fd_head = (fragment_head *)g_hash_table_lookup(table->reassembled_table, &key);
return fd_head;
}
void
fragment_add_seq_offset(reassembly_table *table, const packet_info *pinfo, const guint32 id,
const void *data, const guint32 fragment_offset)
{
fragment_head *fd_head;
fd_head = lookup_fd_head(table, pinfo, id, data, NULL);
if (!fd_head)
return;
if ( fd_head->fragment_nr_offset != 0 )
return;
fd_head->fragment_nr_offset = fragment_offset;
}
void
fragment_set_tot_len(reassembly_table *table, const packet_info *pinfo,
const guint32 id, const void *data, const guint32 tot_len)
{
fragment_head *fd_head;
fragment_item *fd;
guint32 max_offset = 0;
fd_head = lookup_fd_head(table, pinfo, id, data, NULL);
if (!fd_head)
return;
fd = fd_head;
if (fd_head->flags & FD_BLOCKSEQUENCE) {
while (fd) {
if (fd->offset > max_offset) {
max_offset = fd->offset;
if (max_offset > tot_len) {
fd_head->error = "Bad total reassembly block count";
THROW_MESSAGE(ReassemblyError, fd_head->error);
}
}
fd = fd->next;
}
}
if (fd_head->flags & FD_DEFRAGMENTED) {
if (max_offset != tot_len) {
fd_head->error = "Defragmented complete but total length not satisfied";
THROW_MESSAGE(ReassemblyError, fd_head->error);
}
}
fd_head->datalen = tot_len;
fd_head->flags |= FD_DATALEN_SET;
}
guint32
fragment_get_tot_len(reassembly_table *table, const packet_info *pinfo,
const guint32 id, const void *data)
{
fragment_head *fd_head;
fd_head = lookup_fd_head(table, pinfo, id, data, NULL);
if(fd_head){
return fd_head->datalen;
}
return 0;
}
void
fragment_set_partial_reassembly(reassembly_table *table,
const packet_info *pinfo, const guint32 id,
const void *data)
{
fragment_head *fd_head;
fd_head = lookup_fd_head(table, pinfo, id, data, NULL);
if(fd_head){
fd_head->flags |= FD_PARTIAL_REASSEMBLY;
}
}
static void
fragment_unhash(reassembly_table *table, gpointer key)
{
g_hash_table_remove(table->fragment_table, key);
}
static void
fragment_reassembled(reassembly_table *table, fragment_head *fd_head,
const packet_info *pinfo, const guint32 id)
{
reassembled_key *new_key;
fragment_item *fd;
if (fd_head->next == NULL) {
new_key = g_slice_new(reassembled_key);
new_key->frame = pinfo->num;
new_key->id = id;
g_hash_table_insert(table->reassembled_table, new_key, fd_head);
} else {
for (fd = fd_head->next; fd != NULL; fd = fd->next){
new_key = g_slice_new(reassembled_key);
new_key->frame = fd->frame;
new_key->id = id;
g_hash_table_insert(table->reassembled_table, new_key,
fd_head);
}
}
fd_head->flags |= FD_DEFRAGMENTED;
fd_head->reassembled_in = pinfo->num;
fd_head->reas_in_layer_num = pinfo->curr_layer_num;
}
static void
fragment_reassembled_single(reassembly_table *table, fragment_head *fd_head,
const packet_info *pinfo, const guint32 id)
{
reassembled_key *new_key;
fragment_item *fd;
if (fd_head->next == NULL) {
new_key = g_slice_new(reassembled_key);
new_key->frame = pinfo->num;
new_key->id = id;
g_hash_table_insert(table->reassembled_table, new_key, fd_head);
} else {
for (fd = fd_head->next; fd != NULL; fd = fd->next){
new_key = g_slice_new(reassembled_key);
new_key->frame = fd->frame;
new_key->id = id + fd->offset;
g_hash_table_insert(table->reassembled_table, new_key,
fd_head);
}
}
fd_head->flags |= FD_DEFRAGMENTED;
fd_head->reassembled_in = pinfo->num;
fd_head->reas_in_layer_num = pinfo->curr_layer_num;
}
static void
LINK_FRAG(fragment_head *fd_head,fragment_item *fd)
{
fragment_item *fd_i;
for(fd_i= fd_head; fd_i->next;fd_i=fd_i->next) {
if (fd->offset < fd_i->next->offset )
break;
}
fd->next=fd_i->next;
fd_i->next=fd;
}
static void
MERGE_FRAG(fragment_head *fd_head, fragment_item *fd)
{
fragment_item *fd_i, *tmp;
if (fd == NULL) return;
for(fd_i = fd_head; fd_i->next; fd_i=fd_i->next) {
if (fd->offset < fd_i->next->offset) {
tmp = fd_i->next;
fd_i->next = fd;
fd = tmp;
}
}
fd_i->next = fd;
}
static gboolean
fragment_add_work(fragment_head *fd_head, tvbuff_t *tvb, const int offset,
const packet_info *pinfo, const guint32 frag_offset,
const guint32 frag_data_len, const gboolean more_frags)
{
fragment_item *fd;
fragment_item *fd_i;
guint32 max, dfpos, fraglen;
tvbuff_t *old_tvb_data;
guint8 *data;
fd = g_slice_new(fragment_item);
fd->next = NULL;
fd->flags = 0;
fd->frame = pinfo->num;
fd->offset = frag_offset;
fd->fragment_nr_offset = 0;
fd->len = frag_data_len;
fd->tvb_data = NULL;
fd->error = NULL;
if (fd_head->flags & FD_DEFRAGMENTED) {
if (frag_offset + frag_data_len >= fd_head->datalen) {
if (fd_head->flags & FD_PARTIAL_REASSEMBLY) {
for(fd_i=fd_head->next; fd_i; fd_i=fd_i->next){
if( !fd_i->tvb_data ) {
fd_i->tvb_data = tvb_new_subset_remaining(fd_head->tvb_data, fd_i->offset);
fd_i->flags |= FD_SUBSET_TVB;
}
fd_i->flags &= (~FD_TOOLONGFRAGMENT) & (~FD_MULTIPLETAILS);
}
fd_head->flags &= ~(FD_DEFRAGMENTED|FD_PARTIAL_REASSEMBLY|FD_DATALEN_SET);
fd_head->flags &= (~FD_TOOLONGFRAGMENT) & (~FD_MULTIPLETAILS);
fd_head->datalen=0;
fd_head->reassembled_in=0;
fd_head->reas_in_layer_num = 0;
} else {
g_slice_free(fragment_item, fd);
if (frag_offset >= fd_head->datalen) {
THROW_MESSAGE(ReassemblyError, "New fragment past old data limits");
} else {
THROW_MESSAGE(ReassemblyError, "New fragment overlaps old data (retransmission?)");
}
}
} else {
g_slice_free(fragment_item, fd);
THROW_MESSAGE(ReassemblyError, "New fragment overlaps old data (retransmission?)");
}
}
if (fd->frame > fd_head->frame)
fd_head->frame = fd->frame;
if (!more_frags) {
if (fd_head->flags & FD_DATALEN_SET) {
if (fd_head->datalen != (fd->offset + fd->len) ){
fd->flags |= FD_MULTIPLETAILS;
fd_head->flags |= FD_MULTIPLETAILS;
}
} else {
fd_head->datalen = fd->offset + fd->len;
fd_head->flags |= FD_DATALEN_SET;
}
}
if (fd_head->flags & FD_DEFRAGMENTED) {
guint32 end_offset = fd->offset + fd->len;
fd->flags |= FD_OVERLAP;
fd_head->flags |= FD_OVERLAP;
if (end_offset > fd_head->datalen || end_offset < fd->offset || end_offset < fd->len) {
fd->flags |= FD_TOOLONGFRAGMENT;
fd_head->flags |= FD_TOOLONGFRAGMENT;
}
else if ( tvb_memeql(fd_head->tvb_data, fd->offset,
tvb_get_ptr(tvb,offset,fd->len),fd->len) ){
fd->flags |= FD_OVERLAPCONFLICT;
fd_head->flags |= FD_OVERLAPCONFLICT;
}
LINK_FRAG(fd_head,fd);
return TRUE;
}
if (!tvb_bytes_exist(tvb, offset, fd->len)) {
g_slice_free(fragment_item, fd);
THROW(BoundsError);
}
fd->tvb_data = tvb_clone_offset_len(tvb, offset, fd->len);
LINK_FRAG(fd_head,fd);
if( !(fd_head->flags & FD_DATALEN_SET) ){
return FALSE;
}
max = 0;
for (fd_i=fd_head->next;fd_i;fd_i=fd_i->next) {
if ( ((fd_i->offset)<=max) &&
((fd_i->offset+fd_i->len)>max) ){
max = fd_i->offset+fd_i->len;
}
}
if (max < (fd_head->datalen)) {
return FALSE;
}
old_tvb_data=fd_head->tvb_data;
data = (guint8 *) g_malloc(fd_head->datalen);
fd_head->tvb_data = tvb_new_real_data(data, fd_head->datalen, fd_head->datalen);
tvb_set_free_cb(fd_head->tvb_data, g_free);
for (dfpos=0,fd_i=fd_head;fd_i;fd_i=fd_i->next) {
if (fd_i->len) {
if (fd_i->offset + fd_i->len > dfpos) {
if (fd_i->offset >= fd_head->datalen) {
fd_i->flags |= FD_TOOLONGFRAGMENT;
fd_head->flags |= FD_TOOLONGFRAGMENT;
} else if (dfpos < fd_i->offset) {
fd_head->error = "dfpos < offset";
} else if (dfpos - fd_i->offset > fd_i->len)
fd_head->error = "dfpos - offset > len";
else if (!fd_head->tvb_data)
fd_head->error = "no data";
else {
fraglen = fd_i->len;
if (fd_i->offset + fraglen > fd_head->datalen) {
fd_i->flags |= FD_TOOLONGFRAGMENT;
fd_head->flags |= FD_TOOLONGFRAGMENT;
fraglen = fd_head->datalen - fd_i->offset;
}
if (fd_i->offset < dfpos) {
guint32 cmp_len = MIN(fd_i->len,(dfpos-fd_i->offset));
fd_i->flags |= FD_OVERLAP;
fd_head->flags |= FD_OVERLAP;
if ( memcmp(data + fd_i->offset,
tvb_get_ptr(fd_i->tvb_data, 0, cmp_len),
cmp_len)
) {
fd_i->flags |= FD_OVERLAPCONFLICT;
fd_head->flags |= FD_OVERLAPCONFLICT;
}
}
if (fraglen < dfpos - fd_i->offset) {
fd_head->error = "fraglen < dfpos - offset";
} else {
memcpy(data+dfpos,
tvb_get_ptr(fd_i->tvb_data, (dfpos-fd_i->offset), fraglen-(dfpos-fd_i->offset)),
fraglen-(dfpos-fd_i->offset));
dfpos=MAX(dfpos, (fd_i->offset + fraglen));
}
}
} else {
if (fd_i->offset + fd_i->len < fd_i->offset) {
fd_head->error = "offset + len < offset";
}
}
if (fd_i->flags & FD_SUBSET_TVB)
fd_i->flags &= ~FD_SUBSET_TVB;
else if (fd_i->tvb_data)
tvb_free(fd_i->tvb_data);
fd_i->tvb_data=NULL;
}
}
if (old_tvb_data)
tvb_add_to_chain(tvb, old_tvb_data);
fd_head->flags |= FD_DEFRAGMENTED;
fd_head->reassembled_in=pinfo->num;
fd_head->reas_in_layer_num = pinfo->curr_layer_num;
if (fd_head->error) {
THROW_MESSAGE(ReassemblyError, fd_head->error);
}
return TRUE;
}
static fragment_head *
fragment_add_common(reassembly_table *table, tvbuff_t *tvb, const int offset,
const packet_info *pinfo, const guint32 id,
const void *data, const guint32 frag_offset,
const guint32 frag_data_len, const gboolean more_frags,
const gboolean check_already_added)
{
fragment_head *fd_head;
fragment_item *fd_item;
gboolean already_added;
DISSECTOR_ASSERT(tvb_bytes_exist(tvb, offset, frag_data_len));
fd_head = lookup_fd_head(table, pinfo, id, data, NULL);
#if 0
if(strcmp(pinfo->current_proto, "DCERPC") == 0) {
printf("proto:%s num:%u id:%u offset:%u len:%u more:%u visited:%u\n",
pinfo->current_proto, pinfo->num, id, frag_offset, frag_data_len, more_frags, pinfo->fd->flags.visited);
if(fd_head != NULL) {
for(fd_item=fd_head->next;fd_item;fd_item=fd_item->next){
printf("fd_frame:%u fd_offset:%u len:%u datalen:%u\n",
fd_item->frame, fd_item->offset, fd_item->len, fd_item->datalen);
}
}
}
#endif
if (!pinfo->fd->flags.visited) {
if (check_already_added && fd_head != NULL) {
if (pinfo->num <= fd_head->frame) {
already_added = FALSE;
for (fd_item = fd_head->next; fd_item;
fd_item = fd_item->next) {
if (pinfo->num == fd_item->frame &&
frag_offset == fd_item->offset) {
already_added = TRUE;
break;
}
}
if (already_added) {
if (fd_head->flags & FD_DEFRAGMENTED) {
THROW_MESSAGE(ReassemblyError,
"Frame already added in first pass");
} else {
return NULL;
}
}
}
}
} else {
if (fd_head != NULL && fd_head->flags & FD_DEFRAGMENTED) {
if (fd_head->error)
THROW_MESSAGE(ReassemblyError, fd_head->error);
if (pinfo->num > fd_head->frame) {
THROW_MESSAGE(ReassemblyError, "New fragment overlaps old data (retransmission?)");
}
if (frag_offset + frag_data_len > fd_head->datalen) {
if (frag_offset >= fd_head->datalen) {
THROW_MESSAGE(ReassemblyError, "New fragment past old data limits");
} else {
THROW_MESSAGE(ReassemblyError, "New fragment overlaps old data (retransmission?)");
}
}
return fd_head;
} else {
return NULL;
}
}
if (fd_head==NULL){
fd_head = new_head(0);
insert_fd_head(table, fd_head, pinfo, id, data);
}
if (fragment_add_work(fd_head, tvb, offset, pinfo, frag_offset,
frag_data_len, more_frags)) {
return fd_head;
} else {
return NULL;
}
}
fragment_head *
fragment_add(reassembly_table *table, tvbuff_t *tvb, const int offset,
const packet_info *pinfo, const guint32 id, const void *data,
const guint32 frag_offset, const guint32 frag_data_len,
const gboolean more_frags)
{
return fragment_add_common(table, tvb, offset, pinfo, id, data,
frag_offset, frag_data_len, more_frags, TRUE);
}
fragment_head *
fragment_add_multiple_ok(reassembly_table *table, tvbuff_t *tvb,
const int offset, const packet_info *pinfo,
const guint32 id, const void *data,
const guint32 frag_offset,
const guint32 frag_data_len, const gboolean more_frags)
{
return fragment_add_common(table, tvb, offset, pinfo, id, data,
frag_offset, frag_data_len, more_frags, FALSE);
}
fragment_head *
fragment_add_check(reassembly_table *table, tvbuff_t *tvb, const int offset,
const packet_info *pinfo, const guint32 id,
const void *data, const guint32 frag_offset,
const guint32 frag_data_len, const gboolean more_frags)
{
reassembled_key reass_key;
fragment_head *fd_head;
gpointer orig_key;
if (pinfo->fd->flags.visited) {
reass_key.frame = pinfo->num;
reass_key.id = id;
return (fragment_head *)g_hash_table_lookup(table->reassembled_table, &reass_key);
}
fd_head = lookup_fd_head(table, pinfo, id, data, &orig_key);
if (fd_head == NULL) {
fd_head = new_head(0);
orig_key = insert_fd_head(table, fd_head, pinfo, id, data);
}
if (tvb_reported_length(tvb) > tvb_captured_length(tvb))
return NULL;
if (fragment_add_work(fd_head, tvb, offset, pinfo, frag_offset,
frag_data_len, more_frags)) {
fragment_unhash(table, orig_key);
fragment_reassembled(table, fd_head, pinfo, id);
return fd_head;
} else {
return NULL;
}
}
static void
fragment_defragment_and_free (fragment_head *fd_head, const packet_info *pinfo)
{
fragment_item *fd_i = NULL;
fragment_item *last_fd = NULL;
guint32 dfpos = 0, size = 0;
tvbuff_t *old_tvb_data = NULL;
guint8 *data;
for(fd_i=fd_head->next;fd_i;fd_i=fd_i->next) {
if(!last_fd || last_fd->offset!=fd_i->offset){
size+=fd_i->len;
}
last_fd=fd_i;
}
old_tvb_data=fd_head->tvb_data;
data = (guint8 *) g_malloc(size);
fd_head->tvb_data = tvb_new_real_data(data, size, size);
tvb_set_free_cb(fd_head->tvb_data, g_free);
fd_head->len = size;
last_fd=NULL;
for (fd_i=fd_head->next; fd_i; fd_i=fd_i->next) {
if (fd_i->len) {
if(!last_fd || last_fd->offset != fd_i->offset) {
memcpy(data+dfpos, tvb_get_ptr(fd_i->tvb_data, 0, fd_i->len), fd_i->len);
dfpos += fd_i->len;
} else {
fd_i->flags |= FD_OVERLAP;
fd_head->flags |= FD_OVERLAP;
if(last_fd->len != fd_i->len
|| tvb_memeql(last_fd->tvb_data, 0, tvb_get_ptr(fd_i->tvb_data, 0, last_fd->len), last_fd->len) ) {
fd_i->flags |= FD_OVERLAPCONFLICT;
fd_head->flags |= FD_OVERLAPCONFLICT;
}
}
}
last_fd=fd_i;
}
for (fd_i=fd_head->next;fd_i;fd_i=fd_i->next) {
if (fd_i->flags & FD_SUBSET_TVB)
fd_i->flags &= ~FD_SUBSET_TVB;
else if (fd_i->tvb_data)
tvb_free(fd_i->tvb_data);
fd_i->tvb_data=NULL;
}
if (old_tvb_data)
tvb_free(old_tvb_data);
fd_head->flags |= FD_DEFRAGMENTED;
fd_head->reassembled_in=pinfo->num;
fd_head->reas_in_layer_num = pinfo->curr_layer_num;
}
static gboolean
fragment_add_seq_work(fragment_head *fd_head, tvbuff_t *tvb, const int offset,
const packet_info *pinfo, const guint32 frag_number,
const guint32 frag_data_len, const gboolean more_frags)
{
fragment_item *fd;
fragment_item *fd_i;
fragment_item *last_fd;
guint32 max, dfpos;
guint32 frag_number_work;
frag_number_work = frag_number;
if ( fd_head->fragment_nr_offset != 0 )
if ( frag_number_work >= fd_head->fragment_nr_offset )
frag_number_work = frag_number - fd_head->fragment_nr_offset;
if(fd_head->flags & FD_DEFRAGMENTED && frag_number_work >= fd_head->datalen &&
fd_head->flags & FD_PARTIAL_REASSEMBLY){
guint32 lastdfpos = 0;
dfpos = 0;
for(fd_i=fd_head->next; fd_i; fd_i=fd_i->next){
if( !fd_i->tvb_data ) {
if( fd_i->flags & FD_OVERLAP ) {
fd_i->tvb_data = tvb_new_subset_remaining(fd_head->tvb_data, lastdfpos);
} else {
fd_i->tvb_data = tvb_new_subset_remaining(fd_head->tvb_data, dfpos);
lastdfpos = dfpos;
dfpos += fd_i->len;
}
fd_i->flags |= FD_SUBSET_TVB;
}
fd_i->flags &= (~FD_TOOLONGFRAGMENT) & (~FD_MULTIPLETAILS);
}
fd_head->flags &= ~(FD_DEFRAGMENTED|FD_PARTIAL_REASSEMBLY|FD_DATALEN_SET);
fd_head->flags &= (~FD_TOOLONGFRAGMENT) & (~FD_MULTIPLETAILS);
fd_head->datalen=0;
fd_head->reassembled_in=0;
fd_head->reas_in_layer_num = 0;
}
fd = g_slice_new(fragment_item);
fd->next = NULL;
fd->flags = 0;
fd->frame = pinfo->num;
fd->offset = frag_number_work;
fd->len = frag_data_len;
fd->tvb_data = NULL;
fd->error = NULL;
if (fd->frame > fd_head->frame)
fd_head->frame = fd->frame;
if (!more_frags) {
if (fd_head->flags&FD_DATALEN_SET) {
if (fd_head->datalen != fd->offset ){
fd->flags |= FD_MULTIPLETAILS;
fd_head->flags |= FD_MULTIPLETAILS;
}
} else {
fd_head->datalen = fd->offset;
fd_head->flags |= FD_DATALEN_SET;
}
}
if (fd_head->flags & FD_DEFRAGMENTED) {
fd->flags |= FD_OVERLAP;
fd_head->flags |= FD_OVERLAP;
if (fd->offset > fd_head->datalen) {
fd->flags |= FD_TOOLONGFRAGMENT;
fd_head->flags |= FD_TOOLONGFRAGMENT;
LINK_FRAG(fd_head,fd);
return TRUE;
}
dfpos=0;
last_fd=NULL;
for (fd_i=fd_head->next;fd_i && (fd_i->offset!=fd->offset);fd_i=fd_i->next) {
if (!last_fd || last_fd->offset!=fd_i->offset){
dfpos += fd_i->len;
}
last_fd=fd_i;
}
if(fd_i){
if(fd_i->len!=fd->len){
fd->flags |= FD_OVERLAPCONFLICT;
fd_head->flags |= FD_OVERLAPCONFLICT;
LINK_FRAG(fd_head,fd);
return TRUE;
}
DISSECTOR_ASSERT(fd_head->len >= dfpos + fd->len);
if (tvb_memeql(fd_head->tvb_data, dfpos,
tvb_get_ptr(tvb,offset,fd->len),fd->len) ){
fd->flags |= FD_OVERLAPCONFLICT;
fd_head->flags |= FD_OVERLAPCONFLICT;
LINK_FRAG(fd_head,fd);
return TRUE;
}
LINK_FRAG(fd_head,fd);
return TRUE;
} else {
LINK_FRAG(fd_head,fd);
return TRUE;
}
}
if (fd->len) {
if (!tvb_bytes_exist(tvb, offset, fd->len)) {
g_slice_free(fragment_item, fd);
return FALSE;
}
fd->tvb_data = tvb_clone_offset_len(tvb, offset, fd->len);
}
LINK_FRAG(fd_head,fd);
if( !(fd_head->flags & FD_DATALEN_SET) ){
return FALSE;
}
max = 0;
for(fd_i=fd_head->next;fd_i;fd_i=fd_i->next) {
if ( fd_i->offset==max ){
max++;
}
}
if (max <= fd_head->datalen) {
return FALSE;
}
if (max > (fd_head->datalen+1)) {
fd->flags |= FD_TOOLONGFRAGMENT;
fd_head->flags |= FD_TOOLONGFRAGMENT;
}
fragment_defragment_and_free(fd_head, pinfo);
return TRUE;
}
static fragment_head *
fragment_add_seq_common(reassembly_table *table, tvbuff_t *tvb,
const int offset, const packet_info *pinfo,
const guint32 id, const void *data,
guint32 frag_number, const guint32 frag_data_len,
const gboolean more_frags, const guint32 flags,
gpointer *orig_keyp)
{
fragment_head *fd_head;
gpointer orig_key;
fd_head = lookup_fd_head(table, pinfo, id, data, &orig_key);
if (pinfo->fd->flags.visited) {
if (fd_head != NULL && fd_head->flags & FD_DEFRAGMENTED) {
if (orig_keyp != NULL)
*orig_keyp = orig_key;
return fd_head;
} else {
return NULL;
}
}
if (fd_head==NULL){
fd_head= new_head(FD_BLOCKSEQUENCE);
if((flags & (REASSEMBLE_FLAGS_NO_FRAG_NUMBER|REASSEMBLE_FLAGS_802_11_HACK))
&& !more_frags) {
if (orig_keyp != NULL)
*orig_keyp = NULL;
fd_head->reassembled_in=pinfo->num;
fd_head->reas_in_layer_num = pinfo->curr_layer_num;
return fd_head;
}
orig_key = insert_fd_head(table, fd_head, pinfo, id, data);
if (orig_keyp != NULL)
*orig_keyp = orig_key;
if (flags & REASSEMBLE_FLAGS_NO_FRAG_NUMBER)
frag_number = 0;
} else {
if (orig_keyp != NULL)
*orig_keyp = orig_key;
if (flags & REASSEMBLE_FLAGS_NO_FRAG_NUMBER) {
fragment_item *fd;
for (fd = fd_head; fd != NULL; fd = fd->next) {
if (fd->next == NULL)
frag_number = fd->offset + 1;
}
}
}
if (fragment_add_seq_work(fd_head, tvb, offset, pinfo,
frag_number, frag_data_len, more_frags)) {
return fd_head;
} else {
return NULL;
}
}
fragment_head *
fragment_add_seq(reassembly_table *table, tvbuff_t *tvb, const int offset,
const packet_info *pinfo, const guint32 id, const void *data,
const guint32 frag_number, const guint32 frag_data_len,
const gboolean more_frags, const guint32 flags)
{
return fragment_add_seq_common(table, tvb, offset, pinfo, id, data,
frag_number, frag_data_len,
more_frags, flags, NULL);
}
static fragment_head *
fragment_add_seq_check_work(reassembly_table *table, tvbuff_t *tvb,
const int offset, const packet_info *pinfo,
const guint32 id, const void *data,
const guint32 frag_number,
const guint32 frag_data_len,
const gboolean more_frags, const guint32 flags)
{
reassembled_key reass_key;
fragment_head *fd_head;
gpointer orig_key;
if (pinfo->fd->flags.visited) {
reass_key.frame = pinfo->num;
reass_key.id = id;
return (fragment_head *)g_hash_table_lookup(table->reassembled_table, &reass_key);
}
fd_head = fragment_add_seq_common(table, tvb, offset, pinfo, id, data,
frag_number, frag_data_len,
more_frags,
flags,
&orig_key);
if (fd_head) {
if (orig_key != NULL)
fragment_unhash(table, orig_key);
fragment_reassembled(table, fd_head, pinfo, id);
return fd_head;
} else {
return NULL;
}
}
fragment_head *
fragment_add_seq_check(reassembly_table *table, tvbuff_t *tvb, const int offset,
const packet_info *pinfo, const guint32 id,
const void *data,
const guint32 frag_number, const guint32 frag_data_len,
const gboolean more_frags)
{
return fragment_add_seq_check_work(table, tvb, offset, pinfo, id, data,
frag_number, frag_data_len,
more_frags, 0);
}
fragment_head *
fragment_add_seq_802_11(reassembly_table *table, tvbuff_t *tvb,
const int offset, const packet_info *pinfo,
const guint32 id, const void *data,
const guint32 frag_number, const guint32 frag_data_len,
const gboolean more_frags)
{
return fragment_add_seq_check_work(table, tvb, offset, pinfo, id, data,
frag_number, frag_data_len,
more_frags,
REASSEMBLE_FLAGS_802_11_HACK);
}
fragment_head *
fragment_add_seq_next(reassembly_table *table, tvbuff_t *tvb, const int offset,
const packet_info *pinfo, const guint32 id,
const void *data, const guint32 frag_data_len,
const gboolean more_frags)
{
return fragment_add_seq_check_work(table, tvb, offset, pinfo, id, data,
0, frag_data_len, more_frags,
REASSEMBLE_FLAGS_NO_FRAG_NUMBER);
}
static void
fragment_add_seq_single_move(reassembly_table *table, const packet_info *pinfo,
const guint32 id, const void *data,
const guint32 offset)
{
fragment_head *fh, *new_fh;
fragment_item *fd, *prev_fd;
tvbuff_t *old_tvb_data;
if (offset == 0) {
return;
}
fh = lookup_fd_head(table, pinfo, id, data, NULL);
if (fh == NULL) {
g_assert_not_reached();
return;
}
if (fh->flags & FD_DATALEN_SET && fh->datalen <= offset) {
return;
}
new_fh = lookup_fd_head(table, pinfo, id+offset, data, NULL);
if (new_fh != NULL) {
for(prev_fd = fh; prev_fd->next != NULL; prev_fd=prev_fd->next) {}
fd = new_fh->next;
if (fd && fd->offset != 0) {
prev_fd->next = fd;
for (; fd; fd=fd->next) {
fd->offset += offset;
if (fh->frame < fd->frame) {
fh->frame = fd->frame;
}
}
if (new_fh->flags & FD_DATALEN_SET) {
fh->flags |= FD_DATALEN_SET;
fh->datalen = new_fh->datalen + offset;
}
new_fh->next = NULL;
old_tvb_data = fragment_delete(table, pinfo, id+offset, data);
if (old_tvb_data)
tvb_free(old_tvb_data);
}
}
}
static fragment_head *
fragment_add_seq_single_work(reassembly_table *table, tvbuff_t *tvb,
const int offset, const packet_info *pinfo,
const guint32 id, const void* data,
const guint32 frag_data_len,
const gboolean first, const gboolean last,
const guint32 max_frags, const guint32 max_age,
const guint32 flags)
{
reassembled_key reass_key;
tvbuff_t *old_tvb_data;
gpointer orig_key;
fragment_head *fh, *new_fh;
fragment_item *fd, *prev_fd;
guint32 frag_number, tmp_offset;
if (pinfo->fd->flags.visited) {
reass_key.frame = pinfo->num;
reass_key.id = id;
fh = (fragment_head *)g_hash_table_lookup(table->reassembled_table, &reass_key);
return fh;
}
fh = NULL;
if (first) {
frag_number = 0;
fh = lookup_fd_head(table, pinfo, id-frag_number, data, NULL);
if ((flags & REASSEMBLE_FLAGS_AGING) &&
fh && ((fh->frame + max_age) < pinfo->num)) {
old_tvb_data = fragment_delete(table, pinfo, id-frag_number, data);
if (old_tvb_data)
tvb_free(old_tvb_data);
fh = NULL;
}
if (fh == NULL) {
fh = new_head(FD_BLOCKSEQUENCE);
insert_fd_head(table, fh, pinfo, id-frag_number, data);
}
fd = NULL;
for (frag_number=1; frag_number < max_frags; frag_number++) {
new_fh = lookup_fd_head(table, pinfo, id-frag_number, data, NULL);
if (new_fh != NULL) {
prev_fd = new_fh;
new_fh->frame = 0;
for (fd=new_fh->next; fd && fd->offset < frag_number; fd=fd->next) {
prev_fd = fd;
if (new_fh->frame < fd->frame) {
new_fh->frame = fd->frame;
}
}
prev_fd->next = NULL;
break;
}
}
if (fd != NULL) {
tmp_offset = 0;
for (prev_fd = fd; prev_fd; prev_fd = prev_fd->next) {
prev_fd->offset -= frag_number;
tmp_offset = prev_fd->offset;
if (fh->frame < prev_fd->frame) {
fh->frame = prev_fd->frame;
}
}
MERGE_FRAG(fh, fd);
if (new_fh != NULL) {
if (new_fh->flags & FD_DATALEN_SET &&
new_fh->datalen >= frag_number) {
fh->flags |= FD_DATALEN_SET;
fh->datalen = new_fh->datalen - frag_number;
new_fh->flags &= ~FD_DATALEN_SET;
new_fh->datalen = 0;
}
if (new_fh->next == NULL) {
old_tvb_data = fragment_delete(table, pinfo, id-frag_number, data);
if (old_tvb_data)
tvb_free(old_tvb_data);
}
} else {
fragment_add_seq_single_move(table, pinfo, id,
data, tmp_offset);
}
}
frag_number = 0;
} else {
for (frag_number=1; frag_number < max_frags; frag_number++) {
fh = lookup_fd_head(table, pinfo, id-frag_number, data, NULL);
if ((flags & REASSEMBLE_FLAGS_AGING) &&
fh && ((fh->frame + max_age) < pinfo->num)) {
old_tvb_data = fragment_delete(table, pinfo, id-frag_number, data);
if (old_tvb_data)
tvb_free(old_tvb_data);
fh = NULL;
}
if (fh != NULL) {
if (fh->flags & FD_DATALEN_SET &&
fh->datalen < frag_number) {
fh = NULL;
}
break;
}
}
if (fh == NULL) {
frag_number = 1;
fh = new_head(FD_BLOCKSEQUENCE);
insert_fd_head(table, fh, pinfo, id-frag_number, data);
}
}
if (last) {
prev_fd = fh;
for (fd=fh->next; fd && fd->offset <= frag_number; fd=fd->next) {
prev_fd = fd;
}
if (fd != NULL) {
prev_fd->next = NULL;
fh->frame = 0;
for (prev_fd=fh->next; prev_fd; prev_fd=prev_fd->next) {
if (fh->frame < prev_fd->frame) {
fh->frame = prev_fd->frame;
}
}
while (fd && fd->offset == frag_number+1) {
fragment_item *tmp_fd;
tmp_fd=fd->next;
if (fd->tvb_data && !(fd->flags & FD_SUBSET_TVB))
tvb_free(fd->tvb_data);
g_slice_free(fragment_item, fd);
fd=tmp_fd;
}
}
if (fd != NULL) {
new_fh = lookup_fd_head(table, pinfo, id+1, data, NULL);
if (new_fh==NULL) {
new_fh = new_head(FD_BLOCKSEQUENCE);
insert_fd_head(table, new_fh, pinfo, id+1, data);
}
tmp_offset = 0;
for (prev_fd = fd; prev_fd; prev_fd = prev_fd->next) {
prev_fd->offset -= (frag_number+1);
tmp_offset = prev_fd->offset;
if (new_fh->frame < fd->frame) {
new_fh->frame = fd->frame;
}
}
MERGE_FRAG(new_fh, fd);
if (fh->flags & FD_DATALEN_SET &&
fh->datalen > frag_number) {
new_fh->flags |= FD_DATALEN_SET;
new_fh->datalen = fh->datalen - (frag_number+1);
fh->flags &= ~FD_DATALEN_SET;
fh->datalen = 0;
} else {
fragment_add_seq_single_move(table, pinfo, id+1,
data, tmp_offset);
}
}
} else {
fragment_add_seq_single_move(table, pinfo, id-frag_number, data,
frag_number+1);
}
fh = fragment_add_seq_common(table, tvb, offset, pinfo,
id-frag_number, data,
frag_number, frag_data_len,
!last, 0, &orig_key);
if (fh) {
if (orig_key != NULL)
fragment_unhash(table, orig_key);
fragment_reassembled_single(table, fh, pinfo, id-frag_number);
return fh;
} else {
return NULL;
}
}
fragment_head *
fragment_add_seq_single(reassembly_table *table, tvbuff_t *tvb,
const int offset, const packet_info *pinfo,
const guint32 id, const void* data,
const guint32 frag_data_len,
const gboolean first, const gboolean last,
const guint32 max_frags)
{
return fragment_add_seq_single_work(table, tvb, offset, pinfo,
id, data, frag_data_len,
first, last, max_frags, 0, 0);
}
fragment_head *
fragment_add_seq_single_aging(reassembly_table *table, tvbuff_t *tvb,
const int offset, const packet_info *pinfo,
const guint32 id, const void* data,
const guint32 frag_data_len,
const gboolean first, const gboolean last,
const guint32 max_frags, const guint32 max_age)
{
return fragment_add_seq_single_work(table, tvb, offset, pinfo,
id, data, frag_data_len,
first, last, max_frags, max_age,
REASSEMBLE_FLAGS_AGING);
}
void
fragment_start_seq_check(reassembly_table *table, const packet_info *pinfo,
const guint32 id, const void *data,
const guint32 tot_len)
{
fragment_head *fd_head;
if (pinfo->fd->flags.visited) {
return;
}
fd_head = lookup_fd_head(table, pinfo, id, data, NULL);
if (fd_head == NULL) {
fd_head = g_slice_new(fragment_head);
fd_head->next = NULL;
fd_head->frame = 0;
fd_head->offset = 0;
fd_head->len = 0;
fd_head->fragment_nr_offset = 0;
fd_head->datalen = tot_len;
fd_head->reassembled_in = 0;
fd_head->reas_in_layer_num = 0;
fd_head->flags = FD_BLOCKSEQUENCE|FD_DATALEN_SET;
fd_head->tvb_data = NULL;
fd_head->error = NULL;
insert_fd_head(table, fd_head, pinfo, id, data);
}
}
fragment_head *
fragment_end_seq_next(reassembly_table *table, const packet_info *pinfo,
const guint32 id, const void *data)
{
reassembled_key reass_key;
reassembled_key *new_key;
fragment_head *fd_head;
gpointer orig_key;
if (pinfo->fd->flags.visited) {
reass_key.frame = pinfo->num;
reass_key.id = id;
return (fragment_head *)g_hash_table_lookup(table->reassembled_table, &reass_key);
}
fd_head = lookup_fd_head(table, pinfo, id, data, &orig_key);
if (fd_head) {
fd_head->datalen = fd_head->offset;
fd_head->flags |= FD_DATALEN_SET;
fragment_defragment_and_free (fd_head, pinfo);
fragment_unhash(table, orig_key);
fragment_reassembled(table, fd_head, pinfo, id);
if (fd_head->next != NULL) {
new_key = g_slice_new(reassembled_key);
new_key->frame = pinfo->num;
new_key->id = id;
g_hash_table_insert(table->reassembled_table, new_key, fd_head);
}
return fd_head;
} else {
return NULL;
}
}
tvbuff_t *
process_reassembled_data(tvbuff_t *tvb, const int offset, packet_info *pinfo,
const char *name, fragment_head *fd_head, const fragment_items *fit,
gboolean *update_col_infop, proto_tree *tree)
{
tvbuff_t *next_tvb;
gboolean update_col_info;
proto_item *frag_tree_item;
if (fd_head != NULL && pinfo->num == fd_head->reassembled_in && pinfo->curr_layer_num == fd_head->reas_in_layer_num) {
if (fd_head->next != NULL) {
next_tvb = tvb_new_chain(tvb, fd_head->tvb_data);
add_new_data_source(pinfo, next_tvb, name);
if (fd_head->flags & FD_BLOCKSEQUENCE) {
update_col_info = !show_fragment_seq_tree(
fd_head, fit, tree, pinfo, next_tvb, &frag_tree_item);
} else {
update_col_info = !show_fragment_tree(fd_head,
fit, tree, pinfo, next_tvb, &frag_tree_item);
}
} else {
next_tvb = tvb_new_subset_remaining(tvb, offset);
pinfo->fragmented = FALSE;
update_col_info = TRUE;
}
if (update_col_infop != NULL)
*update_col_infop = update_col_info;
} else {
next_tvb = NULL;
if (fd_head != NULL && fit->hf_reassembled_in != NULL) {
proto_tree_add_uint(tree,
*(fit->hf_reassembled_in), tvb,
0, 0, fd_head->reassembled_in);
}
}
return next_tvb;
}
static void
show_fragment(fragment_item *fd, const int offset, const fragment_items *fit,
proto_tree *ft, proto_item *fi, const gboolean first_frag,
const guint32 count, tvbuff_t *tvb, packet_info *pinfo)
{
proto_item *fei=NULL;
int hf;
if (first_frag) {
gchar *name;
if (count == 1) {
name = g_strdup(proto_registrar_get_name(*(fit->hf_fragment)));
} else {
name = g_strdup(proto_registrar_get_name(*(fit->hf_fragments)));
}
proto_item_set_text(fi, "%u %s (%u byte%s): ", count, name, tvb_captured_length(tvb),
plurality(tvb_captured_length(tvb), "", "s"));
g_free(name);
} else {
proto_item_append_text(fi, ", ");
}
proto_item_append_text(fi, "#%u(%u)", fd->frame, fd->len);
if (fd->flags & (FD_OVERLAPCONFLICT
|FD_MULTIPLETAILS|FD_TOOLONGFRAGMENT) ) {
hf = *(fit->hf_fragment_error);
} else {
hf = *(fit->hf_fragment);
}
if (fd->len == 0) {
fei = proto_tree_add_uint_format(ft, hf,
tvb, offset, fd->len,
fd->frame,
"Frame: %u (no data)",
fd->frame);
} else {
fei = proto_tree_add_uint_format(ft, hf,
tvb, offset, fd->len,
fd->frame,
"Frame: %u, payload: %u-%u (%u byte%s)",
fd->frame,
offset,
offset+fd->len-1,
fd->len,
plurality(fd->len, "", "s"));
}
PROTO_ITEM_SET_GENERATED(fei);
mark_frame_as_depended_upon(pinfo, fd->frame);
if (fd->flags & (FD_OVERLAP|FD_OVERLAPCONFLICT
|FD_MULTIPLETAILS|FD_TOOLONGFRAGMENT) ) {
proto_tree *fet=NULL;
fet = proto_item_add_subtree(fei, *(fit->ett_fragment));
if (fd->flags&FD_OVERLAP) {
fei=proto_tree_add_boolean(fet,
*(fit->hf_fragment_overlap),
tvb, 0, 0,
TRUE);
PROTO_ITEM_SET_GENERATED(fei);
}
if (fd->flags&FD_OVERLAPCONFLICT) {
fei=proto_tree_add_boolean(fet,
*(fit->hf_fragment_overlap_conflict),
tvb, 0, 0,
TRUE);
PROTO_ITEM_SET_GENERATED(fei);
}
if (fd->flags&FD_MULTIPLETAILS) {
fei=proto_tree_add_boolean(fet,
*(fit->hf_fragment_multiple_tails),
tvb, 0, 0,
TRUE);
PROTO_ITEM_SET_GENERATED(fei);
}
if (fd->flags&FD_TOOLONGFRAGMENT) {
fei=proto_tree_add_boolean(fet,
*(fit->hf_fragment_too_long_fragment),
tvb, 0, 0,
TRUE);
PROTO_ITEM_SET_GENERATED(fei);
}
}
}
static gboolean
show_fragment_errs_in_col(fragment_head *fd_head, const fragment_items *fit,
packet_info *pinfo)
{
if (fd_head->flags & (FD_OVERLAPCONFLICT
|FD_MULTIPLETAILS|FD_TOOLONGFRAGMENT) ) {
col_add_fstr(pinfo->cinfo, COL_INFO, "[Illegal %s]", fit->tag);
return TRUE;
}
return FALSE;
}
gboolean
show_fragment_tree(fragment_head *fd_head, const fragment_items *fit,
proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, proto_item **fi)
{
fragment_item *fd;
proto_tree *ft;
gboolean first_frag;
guint32 count = 0;
pinfo->fragmented = FALSE;
*fi = proto_tree_add_item(tree, *(fit->hf_fragments), tvb, 0, -1, ENC_NA);
PROTO_ITEM_SET_GENERATED(*fi);
ft = proto_item_add_subtree(*fi, *(fit->ett_fragments));
first_frag = TRUE;
for (fd = fd_head->next; fd != NULL; fd = fd->next) {
count++;
}
for (fd = fd_head->next; fd != NULL; fd = fd->next) {
show_fragment(fd, fd->offset, fit, ft, *fi, first_frag, count, tvb, pinfo);
first_frag = FALSE;
}
if (fit->hf_fragment_count) {
proto_item *fli = proto_tree_add_uint(ft, *(fit->hf_fragment_count),
tvb, 0, 0, count);
PROTO_ITEM_SET_GENERATED(fli);
}
if (fit->hf_reassembled_length) {
proto_item *fli = proto_tree_add_uint(ft, *(fit->hf_reassembled_length),
tvb, 0, 0, tvb_captured_length (tvb));
PROTO_ITEM_SET_GENERATED(fli);
}
if (fit->hf_reassembled_data) {
proto_item *fli = proto_tree_add_item(ft, *(fit->hf_reassembled_data),
tvb, 0, tvb_captured_length(tvb), ENC_NA);
PROTO_ITEM_SET_GENERATED(fli);
}
return show_fragment_errs_in_col(fd_head, fit, pinfo);
}
gboolean
show_fragment_seq_tree(fragment_head *fd_head, const fragment_items *fit,
proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, proto_item **fi)
{
guint32 offset, next_offset, count = 0;
fragment_item *fd, *last_fd;
proto_tree *ft;
gboolean first_frag;
pinfo->fragmented = FALSE;
*fi = proto_tree_add_item(tree, *(fit->hf_fragments), tvb, 0, -1, ENC_NA);
PROTO_ITEM_SET_GENERATED(*fi);
ft = proto_item_add_subtree(*fi, *(fit->ett_fragments));
offset = 0;
next_offset = 0;
last_fd = NULL;
first_frag = TRUE;
for (fd = fd_head->next; fd != NULL; fd = fd->next){
count++;
}
for (fd = fd_head->next; fd != NULL; fd = fd->next){
if (last_fd == NULL || last_fd->offset != fd->offset) {
offset = next_offset;
next_offset += fd->len;
}
last_fd = fd;
show_fragment(fd, offset, fit, ft, *fi, first_frag, count, tvb, pinfo);
first_frag = FALSE;
}
if (fit->hf_fragment_count) {
proto_item *fli = proto_tree_add_uint(ft, *(fit->hf_fragment_count),
tvb, 0, 0, count);
PROTO_ITEM_SET_GENERATED(fli);
}
if (fit->hf_reassembled_length) {
proto_item *fli = proto_tree_add_uint(ft, *(fit->hf_reassembled_length),
tvb, 0, 0, tvb_captured_length (tvb));
PROTO_ITEM_SET_GENERATED(fli);
}
if (fit->hf_reassembled_data) {
proto_item *fli = proto_tree_add_item(ft, *(fit->hf_reassembled_data),
tvb, 0, tvb_captured_length(tvb), ENC_NA);
PROTO_ITEM_SET_GENERATED(fli);
}
return show_fragment_errs_in_col(fd_head, fit, pinfo);
}
static void
reassembly_table_init_reg_table(gpointer p, gpointer user_data _U_)
{
register_reassembly_table_t* reg_table = (register_reassembly_table_t*)p;
reassembly_table_init(reg_table->table, reg_table->funcs);
}
static void
reassembly_table_init_reg_tables(void)
{
g_list_foreach(reassembly_table_list, reassembly_table_init_reg_table, NULL);
}
static void
reassembly_table_cleanup_reg_table(gpointer p, gpointer user_data _U_)
{
register_reassembly_table_t* reg_table = (register_reassembly_table_t*)p;
reassembly_table_destroy(reg_table->table);
}
static void
reassembly_table_cleanup_reg_tables(void)
{
g_list_foreach(reassembly_table_list, reassembly_table_cleanup_reg_table, NULL);
}
void reassembly_tables_init(void)
{
register_init_routine(&reassembly_table_init_reg_tables);
register_cleanup_routine(&reassembly_table_cleanup_reg_tables);
}
static void
reassembly_table_free(gpointer p, gpointer user_data _U_)
{
register_reassembly_table_t* reg_table = (register_reassembly_table_t*)p;
reassembly_table_destroy(reg_table->table);
g_free(reg_table);
}
void
reassembly_table_cleanup(void)
{
g_list_foreach(reassembly_table_list, reassembly_table_free, NULL);
g_list_free(reassembly_table_list);
}
