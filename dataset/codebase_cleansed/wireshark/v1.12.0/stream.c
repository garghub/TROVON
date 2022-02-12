static guint stream_hash_func(gconstpointer k)
{
const stream_key_t *key = (const stream_key_t *)k;
return ((guint)(unsigned long)key->circ.circuit) ^ key->p2p_dir;
}
static gboolean stream_compare_func(gconstpointer a,
gconstpointer b)
{
const stream_key_t *key1 = (const stream_key_t *)a;
const stream_key_t *key2 = (const stream_key_t *)b;
if( key1 -> p2p_dir != key2 -> p2p_dir ||
key1-> is_circuit != key2 -> is_circuit )
return FALSE;
if( key1 -> is_circuit )
return (key1 -> circ.circuit == key2 -> circ.circuit );
else
return (key1 -> circ.conv == key2 -> circ.conv );
}
static void cleanup_stream_hash( void ) {
if( stream_hash != NULL ) {
g_hash_table_destroy( stream_hash );
stream_hash = NULL;
}
}
static void init_stream_hash( void ) {
g_assert(stream_hash==NULL);
stream_hash = g_hash_table_new(stream_hash_func,
stream_compare_func);
}
static stream_t *stream_hash_lookup_circ( const struct circuit *circuit, int p2p_dir )
{
stream_key_t key;
key.is_circuit=TRUE;
key.circ.circuit=circuit;
key.p2p_dir=p2p_dir;
return (stream_t *)g_hash_table_lookup(stream_hash, &key);
}
static stream_t *stream_hash_lookup_conv( const struct conversation *conv, int p2p_dir )
{
stream_key_t key;
key.is_circuit=FALSE;
key.circ.conv = conv;
key.p2p_dir=p2p_dir;
return (stream_t *)g_hash_table_lookup(stream_hash, &key);
}
static stream_t *new_stream( stream_key_t *key )
{
stream_t *val;
val = se_new(stream_t);
val -> key = key;
val -> pdu_counter = 0;
val -> current_pdu = NULL;
val -> lastfrag_framenum = 0;
val -> lastfrag_offset = 0;
g_hash_table_insert(stream_hash, key, val);
return val;
}
static stream_t *stream_hash_insert_circ( const struct circuit *circuit, int p2p_dir )
{
stream_key_t *key;
key = se_new(stream_key_t);
key->is_circuit = TRUE;
key->circ.circuit = circuit;
key->p2p_dir = p2p_dir;
return new_stream(key);
}
static stream_t *stream_hash_insert_conv( const struct conversation *conv, int p2p_dir )
{
stream_key_t *key;
key = se_new(stream_key_t);
key->is_circuit = FALSE;
key->circ.conv = conv;
key->p2p_dir = p2p_dir;
return new_stream(key);
}
static void stream_cleanup_pdu_data(void)
{
}
static void stream_init_pdu_data(void)
{
pdu_counter = 0;
}
static stream_pdu_t *stream_new_pdu(stream_t *stream)
{
stream_pdu_t *pdu;
pdu = se_new(stream_pdu_t);
pdu -> fd_head = NULL;
pdu -> pdu_number = stream -> pdu_counter++;
pdu -> id = pdu_counter++;
return pdu;
}
static guint fragment_hash_func(gconstpointer k)
{
const fragment_key_t *key = (const fragment_key_t *)k;
return ((guint)(unsigned long)key->stream) + ((guint)key -> framenum) + ((guint)key->offset);
}
static gboolean fragment_compare_func(gconstpointer a,
gconstpointer b)
{
const fragment_key_t *key1 = (const fragment_key_t *)a;
const fragment_key_t *key2 = (const fragment_key_t *)b;
return (key1 -> stream == key2 -> stream &&
key1 -> framenum == key2 -> framenum &&
key1 -> offset == key2 -> offset );
}
static void cleanup_fragment_hash( void ) {
if( fragment_hash != NULL ) {
g_hash_table_destroy( fragment_hash );
fragment_hash = NULL;
}
}
static void init_fragment_hash( void ) {
g_assert(fragment_hash==NULL);
fragment_hash = g_hash_table_new(fragment_hash_func,
fragment_compare_func);
}
static stream_pdu_fragment_t *fragment_hash_lookup( const stream_t *stream, guint32 framenum, guint32 offset )
{
fragment_key_t key;
stream_pdu_fragment_t *val;
key.stream = stream;
key.framenum = framenum;
key.offset = offset;
val = (stream_pdu_fragment_t *)g_hash_table_lookup(fragment_hash, &key);
return val;
}
static stream_pdu_fragment_t *fragment_hash_insert( const stream_t *stream, guint32 framenum, guint32 offset,
guint32 length)
{
fragment_key_t *key;
stream_pdu_fragment_t *val;
key = se_new(fragment_key_t);
key->stream = stream;
key->framenum = framenum;
key->offset = offset;
val = se_new(stream_pdu_fragment_t);
val->len = length;
val->pdu = NULL;
val->final_fragment = FALSE;
g_hash_table_insert(fragment_hash, key, val);
return val;
}
stream_t *stream_new_circ ( const struct circuit *circuit, int p2p_dir )
{
stream_t * stream;
stream = stream_hash_lookup_circ(circuit, p2p_dir);
DISSECTOR_ASSERT( stream == NULL );
stream = stream_hash_insert_circ(circuit, p2p_dir);
return stream;
}
stream_t *stream_new_conv ( const struct conversation *conv, int p2p_dir )
{
stream_t * stream;
stream = stream_hash_lookup_conv(conv, p2p_dir);
DISSECTOR_ASSERT( stream == NULL );
stream = stream_hash_insert_conv(conv, p2p_dir);
return stream;
}
stream_t *find_stream_circ ( const struct circuit *circuit, int p2p_dir )
{
return stream_hash_lookup_circ(circuit,p2p_dir);
}
stream_t *find_stream_conv ( const struct conversation *conv, int p2p_dir )
{
return stream_hash_lookup_conv(conv,p2p_dir);
}
void stream_cleanup( void )
{
cleanup_stream_hash();
cleanup_fragment_hash();
stream_cleanup_pdu_data();
}
void stream_init( void )
{
init_stream_hash();
init_fragment_hash();
stream_init_pdu_data();
reassembly_table_init(&stream_reassembly_table,
&addresses_reassembly_table_functions);
}
stream_pdu_fragment_t *stream_find_frag( stream_t *stream, guint32 framenum, guint32 offset )
{
return fragment_hash_lookup( stream, framenum, offset );
}
stream_pdu_fragment_t *stream_add_frag( stream_t *stream, guint32 framenum, guint32 offset,
tvbuff_t *tvb, packet_info *pinfo, gboolean more_frags )
{
fragment_head *fd_head;
stream_pdu_t *pdu;
stream_pdu_fragment_t *frag_data;
DISSECTOR_ASSERT(stream);
DISSECTOR_ASSERT( framenum > stream->lastfrag_framenum ||
(framenum == stream->lastfrag_framenum && offset > stream->lastfrag_offset));
pdu = stream->current_pdu;
if( pdu == NULL ) {
pdu = stream->current_pdu = stream_new_pdu(stream);
}
fd_head = fragment_add_seq_next(&stream_reassembly_table,
tvb, 0, pinfo, pdu->id, NULL,
tvb_reported_length(tvb), more_frags);
frag_data = fragment_hash_insert( stream, framenum, offset, tvb_reported_length(tvb));
frag_data -> pdu = pdu;
if( fd_head != NULL ) {
pdu -> fd_head = fd_head;
stream->current_pdu = NULL;
frag_data -> final_fragment = TRUE;
}
stream -> lastfrag_framenum = framenum;
stream -> lastfrag_offset = offset;
return frag_data;
}
tvbuff_t *stream_process_reassembled(
tvbuff_t *tvb, int offset, packet_info *pinfo,
const char *name, const stream_pdu_fragment_t *frag,
const struct _fragment_items *fit,
gboolean *update_col_infop, proto_tree *tree)
{
stream_pdu_t *pdu;
DISSECTOR_ASSERT(frag);
pdu = frag->pdu;
if(!frag->final_fragment) {
if (pdu->fd_head != NULL && fit->hf_reassembled_in != NULL) {
proto_tree_add_uint(tree,
*(fit->hf_reassembled_in), tvb,
0, 0, pdu->fd_head->reassembled_in);
}
return NULL;
}
return process_reassembled_data(tvb, offset, pinfo, name, pdu->fd_head,
fit, update_col_infop, tree);
}
guint32 stream_get_frag_length( const stream_pdu_fragment_t *frag)
{
DISSECTOR_ASSERT( frag );
return frag->len;
}
fragment_head *stream_get_frag_data( const stream_pdu_fragment_t *frag)
{
DISSECTOR_ASSERT( frag );
return frag->pdu->fd_head;
}
guint32 stream_get_pdu_no( const stream_pdu_fragment_t *frag)
{
DISSECTOR_ASSERT( frag );
return frag->pdu->pdu_number;
}
