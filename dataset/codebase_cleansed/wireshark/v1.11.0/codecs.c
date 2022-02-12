codec_handle_t
find_codec(const char *name)
{
return (registered_codecs) ? (codec_handle_t)g_hash_table_lookup(registered_codecs, name) : NULL;
}
void
register_codec(const char *name, codec_init_fn init_fn, codec_release_fn release_fn, codec_decode_fn decode_fn)
{
struct codec_handle *handle;
if (registered_codecs == NULL) {
registered_codecs = g_hash_table_new(g_str_hash, g_str_equal);
g_assert(registered_codecs != NULL);
}
g_assert(g_hash_table_lookup(registered_codecs, name) == NULL);
handle = (struct codec_handle *)g_malloc(sizeof (struct codec_handle));
handle->name = name;
handle->init_fn = init_fn;
handle->release_fn = release_fn;
handle->decode_fn = decode_fn;
g_hash_table_insert(registered_codecs, (gpointer)name, (gpointer) handle);
}
void *codec_init(codec_handle_t codec)
{
if (!codec) return NULL;
return (codec->init_fn)();
}
void codec_release(codec_handle_t codec, void *context)
{
if (!codec) return;
(codec->release_fn)(context);
}
int codec_decode(codec_handle_t codec, void *context, const void *input, int inputSizeBytes, void *output, int *outputSizeBytes)
{
if (!codec) return 0;
return (codec->decode_fn)(context, input, inputSizeBytes, output, outputSizeBytes);
}
