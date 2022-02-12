size_t
decode_rtp_packet(rtp_packet_t *rp, SAMPLE **out_buff, GHashTable *decoders_hash, unsigned *channels_ptr, unsigned *sample_rate_ptr)
{
unsigned int payload_type;
const gchar *p;
rtp_decoder_t *decoder;
SAMPLE *tmp_buff = NULL;
size_t tmp_buff_len;
size_t decoded_bytes = 0;
if ((rp->payload_data == NULL) || (rp->info->info_payload_len == 0) ) {
return 0;
}
payload_type = rp->info->info_payload_type;
decoder = (rtp_decoder_t *)g_hash_table_lookup(decoders_hash, GUINT_TO_POINTER(payload_type));
if (!decoder) {
decoder = g_new(rtp_decoder_t,1);
decoder->handle = NULL;
decoder->context = NULL;
if (rp->info->info_payload_type_str && find_codec(rp->info->info_payload_type_str)) {
p = rp->info->info_payload_type_str;
} else {
p = try_val_to_str_ext(payload_type, &rtp_payload_type_short_vals_ext);
}
if (p) {
decoder->handle = find_codec(p);
if (decoder->handle)
decoder->context = codec_init(decoder->handle);
}
g_hash_table_insert(decoders_hash, GUINT_TO_POINTER(payload_type), decoder);
}
if (decoder->handle) {
tmp_buff_len = codec_decode(decoder->handle, decoder->context, rp->payload_data, rp->info->info_payload_len, NULL, NULL);
tmp_buff = (SAMPLE *)g_malloc(tmp_buff_len);
decoded_bytes = codec_decode(decoder->handle, decoder->context, rp->payload_data, rp->info->info_payload_len, tmp_buff, &tmp_buff_len);
*out_buff = tmp_buff;
if (channels_ptr) {
*channels_ptr = codec_get_channels(decoder->handle, decoder->context);
}
if (sample_rate_ptr) {
*sample_rate_ptr = codec_get_frequency(decoder->handle, decoder->context);
}
return decoded_bytes;
}
*out_buff = NULL;
return 0;
}
static void
rtp_decoder_value_destroy(gpointer dec_arg)
{
rtp_decoder_t *dec = (rtp_decoder_t *)dec_arg;
if (dec->handle)
codec_release(dec->handle, dec->context);
g_free(dec_arg);
}
GHashTable *rtp_decoder_hash_table_new(void)
{
return g_hash_table_new_full(g_direct_hash, g_direct_equal, NULL, rtp_decoder_value_destroy);
}
