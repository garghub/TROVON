void
sigcomp_init_udvm(void){
gchar *partial_state_str;
guint i;
guint8 *sip_sdp_buff, *presence_buff;
if (state_buffer_table){
g_hash_table_destroy(state_buffer_table);
}
state_buffer_table = g_hash_table_new_full(g_str_hash,
g_str_equal,
g_free,
g_free);
sip_sdp_buff = (guint8 *)g_malloc(SIP_SDP_STATE_LENGTH + 8);
partial_state_str = bytes_to_str(sip_sdp_state_identifier, 6);
memset(sip_sdp_buff, 0, 8);
i = 0;
while ( i < SIP_SDP_STATE_LENGTH ){
sip_sdp_buff[i+8] = sip_sdp_static_dictionaty_for_sigcomp[i];
i++;
}
g_hash_table_insert(state_buffer_table, g_strdup(partial_state_str), sip_sdp_buff);
presence_buff = (guint8 *)g_malloc(PRESENCE_STATE_LENGTH + 8);
partial_state_str = bytes_to_str(presence_state_identifier, 6);
memset(sip_sdp_buff, 0, 8);
i = 0;
while ( i < PRESENCE_STATE_LENGTH ){
presence_buff[i+8] = presence_static_dictionary_for_sigcomp[i];
i++;
}
g_hash_table_insert(state_buffer_table, g_strdup(partial_state_str), presence_buff);
}
int udvm_state_access(tvbuff_t *tvb, proto_tree *tree,guint8 *buff,guint16 p_id_start, guint16 p_id_length, guint16 state_begin, guint16 *state_length,
guint16 *state_address, guint16 *state_instruction,
gint hf_id)
{
int result_code = 0;
guint32 n;
guint16 k;
guint16 byte_copy_right;
guint16 byte_copy_left;
char partial_state[STATE_BUFFER_SIZE];
guint8 *state_buff;
gchar *partial_state_str;
if (( p_id_length < STATE_MIN_ACCESS_LEN ) || ( p_id_length > STATE_BUFFER_SIZE )){
result_code = 1;
return result_code;
}
n = 0;
while ( n < p_id_length && n < STATE_BUFFER_SIZE && p_id_start + n < UDVM_MEMORY_SIZE ){
partial_state[n] = buff[p_id_start + n];
n++;
}
partial_state_str = bytes_to_str(partial_state, p_id_length);
proto_tree_add_text(tree,tvb, 0, -1,"### Accessing state ###");
proto_tree_add_string(tree,hf_id, tvb, 0, 0, partial_state_str);
state_buff = (guint8 *)g_hash_table_lookup(state_buffer_table, partial_state_str);
if ( state_buff == NULL ){
result_code = 2;
return result_code;
}
if ( *state_length == 0 ){
*state_length = state_buff[0] << 8;
*state_length = *state_length | state_buff[1];
}
if ( *state_address == 0 ){
*state_address = state_buff[2] << 8;
*state_address = *state_address | state_buff[3];
}
if ( *state_instruction == 0 ){
*state_instruction = state_buff[4] << 8;
*state_instruction = *state_instruction | state_buff[5];
}
n = state_begin + 8;
k = *state_address;
byte_copy_right = buff[66] << 8;
byte_copy_right = byte_copy_right | buff[67];
byte_copy_left = buff[64] << 8;
byte_copy_left = byte_copy_left | buff[65];
while ( (gint32) n < (state_begin + *state_length + 8) && n < UDVM_MEMORY_SIZE ){
buff[k] = state_buff[n];
k = ( k + 1 ) & 0xffff;
if ( k == byte_copy_right ){
k = byte_copy_left;
}
n++;
}
return 0;
}
void udvm_state_create(guint8 *state_buff,guint8 *state_identifier,guint16 p_id_length){
char partial_state[STATE_BUFFER_SIZE];
guint i;
gchar *partial_state_str;
gchar *dummy_buff;
i = 0;
while ( i < p_id_length && i < STATE_BUFFER_SIZE ){
partial_state[i] = state_identifier[i];
i++;
}
partial_state_str = bytes_to_str(partial_state, p_id_length);
dummy_buff = (gchar *)g_hash_table_lookup(state_buffer_table, partial_state_str);
if ( dummy_buff == NULL ){
g_hash_table_insert(state_buffer_table, g_strdup(partial_state_str), state_buff);
}else{
g_free(state_buff);
}
}
void udvm_state_free(guint8 buff[] _U_,guint16 p_id_start _U_,guint16 p_id_length _U_){
}
void udvm_state_free(guint8 buff[],guint16 p_id_start,guint16 p_id_length){
char partial_state[STATE_BUFFER_SIZE];
guint i;
gchar *partial_state_str;
gchar *dummy_buff;
i = 0;
while ( i < p_id_length && i < STATE_BUFFER_SIZE && p_id_start + i < UDVM_MEMORY_SIZE ){
partial_state[i] = buff[p_id_start + i];
i++;
}
partial_state_str = bytes_to_str(partial_state, p_id_length);
g_warning("State-free on %s ",partial_state_str);
dummy_buff = g_hash_table_lookup(state_buffer_table, partial_state_str);
if ( dummy_buff == NULL ){
g_warning("State-free, state not found %s",partial_state_str);
}else{
g_hash_table_remove (state_buffer_table, partial_state_str);
g_free(dummy_buff);
}
}
