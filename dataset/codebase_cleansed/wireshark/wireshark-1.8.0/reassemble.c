static void LINK_FRAG(fragment_data *fd_head,fragment_data *fd)
{
fragment_data *fd_i;
for(fd_i= fd_head; fd_i->next;fd_i=fd_i->next) {
if (fd->offset < fd_i->next->offset )
break;
}
fd->next=fd_i->next;
fd_i->next=fd;
}
static void *fragment_key_copy(const void *k)
{
const fragment_key* key = (const fragment_key*) k;
fragment_key *new_key = g_slice_new(fragment_key);
COPY_ADDRESS(&new_key->src, &key->src);
COPY_ADDRESS(&new_key->dst, &key->dst);
new_key->id = key->id;
return new_key;
}
static void *dcerpc_fragment_key_copy(const void *k)
{
const dcerpc_fragment_key* key = (const dcerpc_fragment_key*) k;
dcerpc_fragment_key *new_key = g_slice_new(dcerpc_fragment_key);
COPY_ADDRESS(&new_key->src, &key->src);
COPY_ADDRESS(&new_key->dst, &key->dst);
new_key->id = key->id;
new_key->act_id = key->act_id;
return new_key;
}
static gint
fragment_equal(gconstpointer k1, gconstpointer k2)
{
const fragment_key* key1 = (const fragment_key*) k1;
const fragment_key* key2 = (const fragment_key*) k2;
return ( ( (key1->id == key2->id) &&
(ADDRESSES_EQUAL(&key1->src, &key2->src)) &&
(ADDRESSES_EQUAL(&key1->dst, &key2->dst))
) ?
TRUE : FALSE);
}
static guint
fragment_hash(gconstpointer k)
{
const fragment_key* key = (const fragment_key*) k;
guint hash_val;
hash_val = 0;
hash_val += key->id;
return hash_val;
}
static gint
dcerpc_fragment_equal(gconstpointer k1, gconstpointer k2)
{
const dcerpc_fragment_key* key1 = (const dcerpc_fragment_key*) k1;
const dcerpc_fragment_key* key2 = (const dcerpc_fragment_key*) k2;
return (((key1->id == key2->id)
&& (ADDRESSES_EQUAL(&key1->src, &key2->src))
&& (ADDRESSES_EQUAL(&key1->dst, &key2->dst))
&& (memcmp (&key1->act_id, &key2->act_id, sizeof (e_uuid_t)) == 0))
? TRUE : FALSE);
}
static guint
dcerpc_fragment_hash(gconstpointer k)
{
const dcerpc_fragment_key* key = (const dcerpc_fragment_key*) k;
guint hash_val;
hash_val = 0;
hash_val += key->id;
hash_val += key->act_id.Data1;
hash_val += key->act_id.Data2 << 16;
hash_val += key->act_id.Data3;
return hash_val;
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
static gboolean
free_all_fragments(gpointer key_arg _U_, gpointer value, gpointer user_data _U_)
{
fragment_data *fd_head, *tmp_fd;
for (fd_head = value; fd_head != NULL; fd_head = tmp_fd) {
tmp_fd=fd_head->next;
if(fd_head->data && !(fd_head->flags&FD_NOT_MALLOCED))
g_free(fd_head->data);
g_slice_free(fragment_data, fd_head);
}
return TRUE;
}
static fragment_data *new_head(const guint32 flags)
{
fragment_data *fd_head;
fd_head=g_slice_new0(fragment_data);
fd_head->flags=flags;
return fd_head;
}
static gboolean
free_all_reassembled_fragments(gpointer key_arg _U_, gpointer value,
gpointer user_data _U_)
{
fragment_data *fd_head;
for (fd_head = value; fd_head != NULL; fd_head = fd_head->next) {
if(fd_head->data && !(fd_head->flags&FD_NOT_MALLOCED)) {
g_free(fd_head->data);
fd_head->data = NULL;
}
}
return TRUE;
}
static void
fragment_free_key(void *ptr)
{
fragment_key *key = (fragment_key *)ptr;
if(key){
g_free((gpointer)key->src.data);
g_free((gpointer)key->dst.data);
g_slice_free(fragment_key, key);
}
}
static void
dcerpc_fragment_free_key(void *ptr)
{
dcerpc_fragment_key *key = (dcerpc_fragment_key *)ptr;
if(key){
g_free((gpointer)key->src.data);
g_free((gpointer)key->dst.data);
g_slice_free(dcerpc_fragment_key, key);
}
}
void
fragment_table_init(GHashTable **fragment_table)
{
if (*fragment_table != NULL) {
g_hash_table_foreach_remove(*fragment_table,
free_all_fragments, NULL);
} else {
*fragment_table = g_hash_table_new_full(fragment_hash,
fragment_equal, fragment_free_key, NULL);
}
}
void
dcerpc_fragment_table_init(GHashTable **fragment_table)
{
if (*fragment_table != NULL) {
g_hash_table_foreach_remove(*fragment_table,
free_all_fragments, NULL);
} else {
*fragment_table = g_hash_table_new_full(dcerpc_fragment_hash,
dcerpc_fragment_equal, dcerpc_fragment_free_key, NULL);
}
}
void
reassembled_table_init(GHashTable **reassembled_table)
{
if (*reassembled_table != NULL) {
g_hash_table_foreach_remove(*reassembled_table,
free_all_reassembled_fragments, NULL);
} else {
*reassembled_table = g_hash_table_new(reassembled_hash,
reassembled_equal);
}
}
unsigned char *
fragment_delete(const packet_info *pinfo, const guint32 id, GHashTable *fragment_table)
{
fragment_data *fd_head, *fd;
fragment_key key;
unsigned char *data=NULL;
key.src = pinfo->src;
key.dst = pinfo->dst;
key.id = id;
fd_head = g_hash_table_lookup(fragment_table, &key);
if(fd_head==NULL){
return NULL;
}
data=fd_head->data;
for(fd=fd_head->next;fd;){
fragment_data *tmp_fd;
tmp_fd=fd->next;
if( !(fd->flags&FD_NOT_MALLOCED) )
g_free(fd->data);
g_slice_free(fragment_data, fd);
fd=tmp_fd;
}
g_slice_free(fragment_data, fd_head);
g_hash_table_remove(fragment_table, &key);
return data;
}
fragment_data *
fragment_get(const packet_info *pinfo, const guint32 id, GHashTable *fragment_table)
{
fragment_data *fd_head;
fragment_key key;
key.src = pinfo->src;
key.dst = pinfo->dst;
key.id = id;
fd_head = g_hash_table_lookup(fragment_table, &key);
return fd_head;
}
fragment_data *
fragment_get_reassembled(const guint32 id, GHashTable *reassembled_table)
{
fragment_data *fd_head;
reassembled_key key;
key.frame = id;
key.id = id;
fd_head = g_hash_table_lookup(reassembled_table, &key);
return fd_head;
}
fragment_data *
fragment_get_reassembled_id(const packet_info *pinfo, const guint32 id, GHashTable *reassembled_table)
{
fragment_data *fd_head;
reassembled_key key;
key.frame = pinfo->fd->num;
key.id = id;
fd_head = g_hash_table_lookup(reassembled_table, &key);
return fd_head;
}
void
fragment_set_tot_len(const packet_info *pinfo, const guint32 id, GHashTable *fragment_table,
const guint32 tot_len)
{
fragment_data *fd_head;
fragment_key key;
key.src = pinfo->src;
key.dst = pinfo->dst;
key.id = id;
fd_head = g_hash_table_lookup(fragment_table, &key);
if(fd_head){
fd_head->datalen = tot_len;
fd_head->flags |= FD_DATALEN_SET;
}
return;
}
guint32
fragment_get_tot_len(const packet_info *pinfo, const guint32 id, GHashTable *fragment_table)
{
fragment_data *fd_head;
fragment_key key;
key.src = pinfo->src;
key.dst = pinfo->dst;
key.id = id;
fd_head = g_hash_table_lookup(fragment_table, &key);
if(fd_head){
return fd_head->datalen;
}
return 0;
}
void
fragment_set_partial_reassembly(const packet_info *pinfo, const guint32 id, GHashTable *fragment_table)
{
fragment_data *fd_head;
fragment_key key;
key.src = pinfo->src;
key.dst = pinfo->dst;
key.id = id;
fd_head = g_hash_table_lookup(fragment_table, &key);
if(fd_head){
fd_head->flags |= FD_PARTIAL_REASSEMBLY;
}
}
static void
fragment_unhash(GHashTable *fragment_table, fragment_key *key)
{
g_hash_table_remove(fragment_table, key);
}
static void
fragment_reassembled(fragment_data *fd_head, const packet_info *pinfo,
GHashTable *reassembled_table, const guint32 id)
{
reassembled_key *new_key;
fragment_data *fd;
if (fd_head->next == NULL) {
new_key = se_alloc(sizeof(reassembled_key));
new_key->frame = pinfo->fd->num;
new_key->id = id;
g_hash_table_insert(reassembled_table, new_key, fd_head);
} else {
for (fd = fd_head->next; fd != NULL; fd = fd->next){
new_key = se_alloc(sizeof(reassembled_key));
new_key->frame = fd->frame;
new_key->id = id;
g_hash_table_insert(reassembled_table, new_key,
fd_head);
}
}
fd_head->flags |= FD_DEFRAGMENTED;
fd_head->reassembled_in = pinfo->fd->num;
}
static gboolean
fragment_add_work(fragment_data *fd_head, tvbuff_t *tvb, const int offset,
const packet_info *pinfo, const guint32 frag_offset,
const guint32 frag_data_len, const gboolean more_frags)
{
fragment_data *fd;
fragment_data *fd_i;
guint32 max, dfpos;
unsigned char *old_data;
fd = g_slice_new(fragment_data);
fd->next = NULL;
fd->flags = 0;
fd->frame = pinfo->fd->num;
if (fd->frame > fd_head->frame)
fd_head->frame = fd->frame;
fd->offset = frag_offset;
fd->len = frag_data_len;
fd->data = NULL;
if(fd_head->flags & FD_DEFRAGMENTED && (frag_offset+frag_data_len) >= fd_head->datalen &&
fd_head->flags & FD_PARTIAL_REASSEMBLY){
for(fd_i=fd_head->next; fd_i; fd_i=fd_i->next){
if( !fd_i->data ) {
fd_i->data = fd_head->data + fd_i->offset;
fd_i->flags |= FD_NOT_MALLOCED;
}
fd_i->flags &= (~FD_TOOLONGFRAGMENT) & (~FD_MULTIPLETAILS);
}
fd_head->flags &= ~(FD_DEFRAGMENTED|FD_PARTIAL_REASSEMBLY|FD_DATALEN_SET);
fd_head->flags &= (~FD_TOOLONGFRAGMENT) & (~FD_MULTIPLETAILS);
fd_head->datalen=0;
fd_head->reassembled_in=0;
}
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
else if ( memcmp(fd_head->data+fd->offset,
tvb_get_ptr(tvb,offset,fd->len),fd->len) ){
fd->flags |= FD_OVERLAPCONFLICT;
fd_head->flags |= FD_OVERLAPCONFLICT;
}
LINK_FRAG(fd_head,fd);
return TRUE;
}
fd->data = g_malloc(fd->len);
tvb_memcpy(tvb, fd->data, offset, fd->len);
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
if (max > (fd_head->datalen)) {
fd->flags |= FD_TOOLONGFRAGMENT;
fd_head->flags |= FD_TOOLONGFRAGMENT;
}
old_data=fd_head->data;
fd_head->data = g_malloc(max);
for (dfpos=0,fd_i=fd_head;fd_i;fd_i=fd_i->next) {
if (fd_i->len) {
if ( fd_i->offset+fd_i->len > dfpos ) {
if (fd_i->offset+fd_i->len > max)
g_warning("Reassemble error in frame %u: offset %u + len %u > max %u",
pinfo->fd->num, fd_i->offset,
fd_i->len, max);
else if (dfpos < fd_i->offset)
g_warning("Reassemble error in frame %u: dfpos %u < offset %u",
pinfo->fd->num, dfpos, fd_i->offset);
else if (dfpos-fd_i->offset > fd_i->len)
g_warning("Reassemble error in frame %u: dfpos %u - offset %u > len %u",
pinfo->fd->num, dfpos, fd_i->offset,
fd_i->len);
else if (!fd_head->data)
g_warning("Reassemble error in frame %u: no data",
pinfo->fd->num);
else {
if (fd_i->offset < dfpos) {
fd_i->flags |= FD_OVERLAP;
fd_head->flags |= FD_OVERLAP;
if ( memcmp(fd_head->data+fd_i->offset,
fd_i->data,
MIN(fd_i->len,(dfpos-fd_i->offset))
) ) {
fd_i->flags |= FD_OVERLAPCONFLICT;
fd_head->flags |= FD_OVERLAPCONFLICT;
}
}
memcpy(fd_head->data+dfpos,
fd_i->data+(dfpos-fd_i->offset),
fd_i->len-(dfpos-fd_i->offset));
}
} else {
if (fd_i->offset + fd_i->len < fd_i->offset)
g_warning("Reassemble error in frame %u: offset %u + len %u < offset",
pinfo->fd->num, fd_i->offset,
fd_i->len);
}
if( fd_i->flags & FD_NOT_MALLOCED )
fd_i->flags &= ~FD_NOT_MALLOCED;
else
g_free(fd_i->data);
fd_i->data=NULL;
dfpos=MAX(dfpos,(fd_i->offset+fd_i->len));
}
}
g_free(old_data);
fd_head->flags |= FD_DEFRAGMENTED;
fd_head->reassembled_in=pinfo->fd->num;
return TRUE;
}
static fragment_data *
fragment_add_common(tvbuff_t *tvb, const int offset, const packet_info *pinfo, const guint32 id,
GHashTable *fragment_table, const guint32 frag_offset,
const guint32 frag_data_len, const gboolean more_frags,
const gboolean check_already_added)
{
fragment_key key, *new_key;
fragment_data *fd_head;
fragment_data *fd_item;
gboolean already_added=pinfo->fd->flags.visited;
DISSECTOR_ASSERT(tvb_bytes_exist(tvb, offset, frag_data_len));
key.src = pinfo->src;
key.dst = pinfo->dst;
key.id = id;
fd_head = g_hash_table_lookup(fragment_table, &key);
#if 0
if(strcmp(pinfo->current_proto, "DCERPC") == 0) {
printf("proto:%s num:%u id:%u offset:%u len:%u more:%u visited:%u\n",
pinfo->current_proto, pinfo->fd->num, id, frag_offset, frag_data_len, more_frags, pinfo->fd->flags.visited);
if(fd_head != NULL) {
for(fd_item=fd_head->next;fd_item;fd_item=fd_item->next){
printf("fd_frame:%u fd_offset:%u len:%u datalen:%u\n",
fd_item->frame, fd_item->offset, fd_item->len, fd_item->datalen);
}
}
}
#endif
if (!already_added && check_already_added && fd_head != NULL) {
if (pinfo->fd->num <= fd_head->frame) {
for(fd_item=fd_head->next;fd_item;fd_item=fd_item->next){
if(pinfo->fd->num==fd_item->frame && frag_offset==fd_item->offset){
already_added=TRUE;
}
}
}
}
if (already_added) {
if (fd_head != NULL && fd_head->flags & FD_DEFRAGMENTED) {
return fd_head;
} else {
return NULL;
}
}
if (fd_head==NULL){
fd_head = new_head(0);
new_key = g_slice_new(fragment_key);
COPY_ADDRESS(&new_key->src, &key.src);
COPY_ADDRESS(&new_key->dst, &key.dst);
new_key->id = key.id;
g_hash_table_insert(fragment_table, new_key, fd_head);
}
if (fragment_add_work(fd_head, tvb, offset, pinfo, frag_offset,
frag_data_len, more_frags)) {
return fd_head;
} else {
return NULL;
}
}
fragment_data *
fragment_add(tvbuff_t *tvb, const int offset, const packet_info *pinfo, const guint32 id,
GHashTable *fragment_table, const guint32 frag_offset,
const guint32 frag_data_len, const gboolean more_frags)
{
return fragment_add_common(tvb, offset, pinfo, id, fragment_table,
frag_offset, frag_data_len, more_frags, TRUE);
}
fragment_data *
fragment_add_multiple_ok(tvbuff_t *tvb, const int offset, const packet_info *pinfo,
const guint32 id, GHashTable *fragment_table,
const guint32 frag_offset, const guint32 frag_data_len,
const gboolean more_frags)
{
return fragment_add_common(tvb, offset, pinfo, id, fragment_table,
frag_offset, frag_data_len, more_frags, FALSE);
}
fragment_data *
fragment_add_check(tvbuff_t *tvb, const int offset, const packet_info *pinfo,
const guint32 id, GHashTable *fragment_table,
GHashTable *reassembled_table, const guint32 frag_offset,
const guint32 frag_data_len, const gboolean more_frags)
{
reassembled_key reass_key;
fragment_key key, *new_key, *old_key;
gpointer orig_key, value;
fragment_data *fd_head;
if (pinfo->fd->flags.visited) {
reass_key.frame = pinfo->fd->num;
reass_key.id = id;
return g_hash_table_lookup(reassembled_table, &reass_key);
}
key.src = pinfo->src;
key.dst = pinfo->dst;
key.id = id;
if (!g_hash_table_lookup_extended(fragment_table, &key,
&orig_key, &value)) {
fd_head = new_head(0);
new_key = g_slice_new(fragment_key);
COPY_ADDRESS(&new_key->src, &key.src);
COPY_ADDRESS(&new_key->dst, &key.dst);
new_key->id = key.id;
g_hash_table_insert(fragment_table, new_key, fd_head);
orig_key = new_key;
} else {
fd_head = value;
}
if (tvb_reported_length(tvb) > tvb_length(tvb))
return NULL;
if (fragment_add_work(fd_head, tvb, offset, pinfo, frag_offset,
frag_data_len, more_frags)) {
old_key = orig_key;
fragment_unhash(fragment_table, old_key);
fragment_reassembled(fd_head, pinfo, reassembled_table, id);
return fd_head;
} else {
return NULL;
}
}
static void
fragment_defragment_and_free (fragment_data *fd_head, const packet_info *pinfo)
{
fragment_data *fd_i = NULL;
fragment_data *last_fd = NULL;
guint32 dfpos = 0, size = 0;
void *old_data = NULL;
for(fd_i=fd_head->next;fd_i;fd_i=fd_i->next) {
if(!last_fd || last_fd->offset!=fd_i->offset){
size+=fd_i->len;
}
last_fd=fd_i;
}
old_data=fd_head->data;
fd_head->data = g_malloc(size);
fd_head->len = size;
last_fd=NULL;
for (fd_i=fd_head->next; fd_i; fd_i=fd_i->next) {
if (fd_i->len) {
if(!last_fd || last_fd->offset != fd_i->offset) {
memcpy(fd_head->data+dfpos, fd_i->data, fd_i->len);
dfpos += fd_i->len;
} else {
fd_i->flags |= FD_OVERLAP;
fd_head->flags |= FD_OVERLAP;
if(last_fd->len != fd_i->len
|| memcmp(last_fd->data, fd_i->data, last_fd->len) ) {
fd_i->flags |= FD_OVERLAPCONFLICT;
fd_head->flags |= FD_OVERLAPCONFLICT;
}
}
}
last_fd=fd_i;
}
for (fd_i=fd_head->next;fd_i;fd_i=fd_i->next) {
if( fd_i->flags & FD_NOT_MALLOCED )
fd_i->flags &= ~FD_NOT_MALLOCED;
else
g_free(fd_i->data);
fd_i->data=NULL;
}
g_free(old_data);
fd_head->flags |= FD_DEFRAGMENTED;
fd_head->reassembled_in=pinfo->fd->num;
}
static gboolean
fragment_add_seq_work(fragment_data *fd_head, tvbuff_t *tvb, const int offset,
const packet_info *pinfo, const guint32 frag_number,
const guint32 frag_data_len, const gboolean more_frags,
const guint32 flags _U_)
{
fragment_data *fd;
fragment_data *fd_i;
fragment_data *last_fd;
guint32 max, dfpos;
if(fd_head->flags & FD_DEFRAGMENTED && frag_number >= fd_head->datalen &&
fd_head->flags & FD_PARTIAL_REASSEMBLY){
guint32 lastdfpos = 0;
dfpos = 0;
for(fd_i=fd_head->next; fd_i; fd_i=fd_i->next){
if( !fd_i->data ) {
if( fd_i->flags & FD_OVERLAP ) {
fd_i->data = fd_head->data + lastdfpos;
} else {
fd_i->data = fd_head->data + dfpos;
lastdfpos = dfpos;
dfpos += fd_i->len;
}
fd_i->flags |= FD_NOT_MALLOCED;
}
fd_i->flags &= (~FD_TOOLONGFRAGMENT) & (~FD_MULTIPLETAILS);
}
fd_head->flags &= ~(FD_DEFRAGMENTED|FD_PARTIAL_REASSEMBLY|FD_DATALEN_SET);
fd_head->flags &= (~FD_TOOLONGFRAGMENT) & (~FD_MULTIPLETAILS);
fd_head->datalen=0;
fd_head->reassembled_in=0;
}
fd = g_slice_new(fragment_data);
fd->next = NULL;
fd->flags = 0;
fd->frame = pinfo->fd->num;
fd->offset = frag_number;
fd->len = frag_data_len;
fd->data = NULL;
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
if ( memcmp(fd_head->data+dfpos,
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
fd->data = g_malloc(fd->len);
tvb_memcpy(tvb, fd->data, offset, fd->len);
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
fragment_data *
fragment_add_seq(tvbuff_t *tvb, const int offset, const packet_info *pinfo, const guint32 id,
GHashTable *fragment_table, const guint32 frag_number,
const guint32 frag_data_len, const gboolean more_frags)
{
fragment_key key;
key.src = pinfo->src;
key.dst = pinfo->dst;
key.id = id;
return fragment_add_seq_key(tvb, offset, pinfo,
&key, fragment_key_copy,
fragment_table, frag_number,
frag_data_len, more_frags, 0);
}
fragment_data *
fragment_add_dcerpc_dg(tvbuff_t *tvb, const int offset, const packet_info *pinfo, const guint32 id,
void *v_act_id,
GHashTable *fragment_table, const guint32 frag_number,
const guint32 frag_data_len, const gboolean more_frags)
{
e_uuid_t *act_id = (e_uuid_t *)v_act_id;
dcerpc_fragment_key key;
key.src = pinfo->src;
key.dst = pinfo->dst;
key.id = id;
key.act_id = *act_id;
return fragment_add_seq_key(tvb, offset, pinfo,
&key, dcerpc_fragment_key_copy,
fragment_table, frag_number,
frag_data_len, more_frags, 0);
}
fragment_data *
fragment_add_seq_key(tvbuff_t *tvb, const int offset, const packet_info *pinfo,
void *key, fragment_key_copier key_copier,
GHashTable *fragment_table, guint32 frag_number,
const guint32 frag_data_len, const gboolean more_frags,
const guint32 flags)
{
fragment_data *fd_head;
fd_head = g_hash_table_lookup(fragment_table, key);
if (pinfo->fd->flags.visited) {
if (fd_head != NULL && fd_head->flags & FD_DEFRAGMENTED) {
return fd_head;
} else {
return NULL;
}
}
if (fd_head==NULL){
fd_head= new_head(FD_BLOCKSEQUENCE);
if((flags & (REASSEMBLE_FLAGS_NO_FRAG_NUMBER|REASSEMBLE_FLAGS_802_11_HACK))
&& !more_frags) {
fd_head->reassembled_in=pinfo->fd->num;
return fd_head;
}
if(key_copier != NULL)
key = key_copier(key);
g_hash_table_insert(fragment_table, key, fd_head);
if (flags & REASSEMBLE_FLAGS_NO_FRAG_NUMBER)
frag_number = 0;
} else {
if (flags & REASSEMBLE_FLAGS_NO_FRAG_NUMBER) {
fragment_data *fd;
for (fd = fd_head; fd != NULL; fd = fd->next) {
if (fd->next == NULL)
frag_number = fd->offset + 1;
}
}
}
if ((flags & REASSEMBLE_FLAGS_CHECK_DATA_PRESENT) &&
!tvb_bytes_exist(tvb, offset, frag_data_len)) {
if (!more_frags) {
gpointer orig_key;
if (g_hash_table_lookup_extended(fragment_table, key,
&orig_key, NULL)) {
fragment_unhash(fragment_table, (fragment_key *)orig_key);
}
}
fd_head -> flags |= FD_DATA_NOT_PRESENT;
return frag_number == 0 ? fd_head : NULL;
}
if (fragment_add_seq_work(fd_head, tvb, offset, pinfo,
frag_number, frag_data_len, more_frags, flags)) {
return fd_head;
} else {
return NULL;
}
}
static fragment_data *
fragment_add_seq_check_work(tvbuff_t *tvb, const int offset,
const packet_info *pinfo, const guint32 id,
GHashTable *fragment_table,
GHashTable *reassembled_table,
const guint32 frag_number,
const guint32 frag_data_len,
const gboolean more_frags, const guint32 flags)
{
reassembled_key reass_key;
fragment_key key;
fragment_data *fd_head;
if (pinfo->fd->flags.visited) {
reass_key.frame = pinfo->fd->num;
reass_key.id = id;
return g_hash_table_lookup(reassembled_table, &reass_key);
}
key.src = pinfo->src;
key.dst = pinfo->dst;
key.id = id;
fd_head = fragment_add_seq_key(tvb, offset, pinfo,
&key, fragment_key_copy,
fragment_table, frag_number,
frag_data_len, more_frags, flags|REASSEMBLE_FLAGS_CHECK_DATA_PRESENT);
if (fd_head) {
gpointer orig_key;
if(fd_head->flags & FD_DATA_NOT_PRESENT) {
return fd_head;
}
if (g_hash_table_lookup_extended(fragment_table, &key,
&orig_key, NULL)) {
fragment_unhash(fragment_table, (fragment_key *)orig_key);
}
fragment_reassembled(fd_head, pinfo, reassembled_table, id);
return fd_head;
} else {
return NULL;
}
}
fragment_data *
fragment_add_seq_check(tvbuff_t *tvb, const int offset,
const packet_info *pinfo, const guint32 id,
GHashTable *fragment_table,
GHashTable *reassembled_table, const guint32 frag_number,
const guint32 frag_data_len, const gboolean more_frags)
{
return fragment_add_seq_check_work(tvb, offset, pinfo, id,
fragment_table, reassembled_table,
frag_number, frag_data_len,
more_frags, 0);
}
fragment_data *
fragment_add_seq_802_11(tvbuff_t *tvb, const int offset,
const packet_info *pinfo, const guint32 id,
GHashTable *fragment_table,
GHashTable *reassembled_table,
const guint32 frag_number, const guint32 frag_data_len,
const gboolean more_frags)
{
return fragment_add_seq_check_work(tvb, offset, pinfo, id,
fragment_table, reassembled_table,
frag_number, frag_data_len,
more_frags,
REASSEMBLE_FLAGS_802_11_HACK);
}
fragment_data *
fragment_add_seq_next(tvbuff_t *tvb, const int offset, const packet_info *pinfo,
const guint32 id, GHashTable *fragment_table,
GHashTable *reassembled_table, const guint32 frag_data_len,
const gboolean more_frags)
{
return fragment_add_seq_check_work(tvb, offset, pinfo, id,
fragment_table, reassembled_table, 0,
frag_data_len, more_frags,
REASSEMBLE_FLAGS_NO_FRAG_NUMBER);
}
void
fragment_start_seq_check(const packet_info *pinfo, const guint32 id, GHashTable *fragment_table,
const guint32 tot_len)
{
fragment_key key, *new_key;
fragment_data *fd_head;
if (pinfo->fd->flags.visited) {
return;
}
key.src = pinfo->src;
key.dst = pinfo->dst;
key.id = id;
fd_head = g_hash_table_lookup(fragment_table, &key);
if (fd_head == NULL) {
fd_head = g_slice_new(fragment_data);
fd_head->next = NULL;
fd_head->datalen = tot_len;
fd_head->offset = 0;
fd_head->len = 0;
fd_head->flags = FD_BLOCKSEQUENCE|FD_DATALEN_SET;
fd_head->data = NULL;
fd_head->reassembled_in = 0;
new_key = fragment_key_copy(&key);
g_hash_table_insert(fragment_table, new_key, fd_head);
}
}
fragment_data *
fragment_end_seq_next(const packet_info *pinfo, const guint32 id, GHashTable *fragment_table,
GHashTable *reassembled_table)
{
reassembled_key reass_key;
reassembled_key *new_key;
fragment_key key;
fragment_data *fd_head;
if (pinfo->fd->flags.visited) {
reass_key.frame = pinfo->fd->num;
reass_key.id = id;
return g_hash_table_lookup(reassembled_table, &reass_key);
}
key.src = pinfo->src;
key.dst = pinfo->dst;
key.id = id;
fd_head = g_hash_table_lookup (fragment_table, &key);
if (fd_head) {
gpointer orig_key;
if (fd_head->flags & FD_DATA_NOT_PRESENT) {
return NULL;
}
fd_head->datalen = fd_head->offset;
fd_head->flags |= FD_DATALEN_SET;
fragment_defragment_and_free (fd_head, pinfo);
if (g_hash_table_lookup_extended(fragment_table, &key,
&orig_key, NULL)) {
fragment_unhash(fragment_table, (fragment_key *)orig_key);
}
fragment_reassembled(fd_head, pinfo, reassembled_table, id);
if (fd_head->next != NULL) {
new_key = se_alloc(sizeof(reassembled_key));
new_key->frame = pinfo->fd->num;
new_key->id = id;
g_hash_table_insert(reassembled_table, new_key, fd_head);
}
return fd_head;
} else {
return NULL;
}
}
tvbuff_t *
process_reassembled_data(tvbuff_t *tvb, const int offset, packet_info *pinfo,
const char *name, fragment_data *fd_head, const fragment_items *fit,
gboolean *update_col_infop, proto_tree *tree)
{
tvbuff_t *next_tvb;
gboolean update_col_info;
proto_item *frag_tree_item;
if (fd_head != NULL && pinfo->fd->num == fd_head->reassembled_in) {
if (fd_head->next != NULL) {
if (fd_head->flags & FD_BLOCKSEQUENCE) {
next_tvb = tvb_new_real_data(fd_head->data,
fd_head->len, fd_head->len);
} else {
next_tvb = tvb_new_real_data(fd_head->data,
fd_head->datalen, fd_head->datalen);
}
tvb_set_child_real_data_tvbuff(tvb, next_tvb);
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
show_fragment(fragment_data *fd, const int offset, const fragment_items *fit,
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
proto_item_set_text(fi, "%u %s (%u byte%s): ", count, name, tvb_length(tvb),
plurality(tvb_length(tvb), "", "s"));
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
show_fragment_errs_in_col(fragment_data *fd_head, const fragment_items *fit,
packet_info *pinfo)
{
if (fd_head->flags & (FD_OVERLAPCONFLICT
|FD_MULTIPLETAILS|FD_TOOLONGFRAGMENT) ) {
if (check_col(pinfo->cinfo, COL_INFO)) {
col_add_fstr(pinfo->cinfo, COL_INFO,
"[Illegal %s]", fit->tag);
return TRUE;
}
}
return FALSE;
}
gboolean
show_fragment_tree(fragment_data *fd_head, const fragment_items *fit,
proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, proto_item **fi)
{
fragment_data *fd;
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
tvb, 0, 0, tvb_length (tvb));
PROTO_ITEM_SET_GENERATED(fli);
}
return show_fragment_errs_in_col(fd_head, fit, pinfo);
}
gboolean
show_fragment_seq_tree(fragment_data *fd_head, const fragment_items *fit,
proto_tree *tree, packet_info *pinfo, tvbuff_t *tvb, proto_item **fi)
{
guint32 offset, next_offset, count = 0;
fragment_data *fd, *last_fd;
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
tvb, 0, 0, tvb_length (tvb));
PROTO_ITEM_SET_GENERATED(fli);
}
return show_fragment_errs_in_col(fd_head, fit, pinfo);
}
