static gboolean
check_for_codec_plugin(GModule *handle)
{
gpointer gp;
void (*register_codec_module)(void);
codec_plugin *plugin;
if (!g_module_symbol(handle, "register_codec_module", &gp)) {
return FALSE;
}
register_codec_module = (void (*)(void))gp;
plugin = (codec_plugin *)g_malloc(sizeof (codec_plugin));
plugin->register_codec_module = register_codec_module;
codec_plugins = g_slist_append(codec_plugins, plugin);
return TRUE;
}
void
codec_register_plugin_types(void)
{
add_plugin_type("codec", check_for_codec_plugin);
}
static void
register_codec_plugin(gpointer data, gpointer user_data _U_)
{
codec_plugin *plugin = (codec_plugin *)data;
(plugin->register_codec_module)();
}
void
register_all_codecs(void)
{
register_codec("g711U", codec_g711u_init, codec_g711u_release,
codec_g711u_get_channels, codec_g711u_get_frequency, codec_g711u_decode);
register_codec("g711A", codec_g711a_init, codec_g711a_release,
codec_g711a_get_channels, codec_g711a_get_frequency, codec_g711a_decode);
#ifdef HAVE_SPANDSP
register_codec("g722", codec_g722_init, codec_g722_release,
codec_g722_get_channels, codec_g722_get_frequency, codec_g722_decode);
register_codec("g726", codec_g726_init, codec_g726_release,
codec_g726_get_channels, codec_g726_get_frequency, codec_g726_decode);
#endif
#ifdef HAVE_SBC
register_codec("SBC", codec_sbc_init, codec_sbc_release,
codec_sbc_get_channels, codec_sbc_get_frequency, codec_sbc_decode);
#endif
g_slist_foreach(codec_plugins, register_codec_plugin, NULL);
}
codec_handle_t
find_codec(const char *name)
{
return (registered_codecs) ? (codec_handle_t)g_hash_table_lookup(registered_codecs, name) : NULL;
}
gboolean
register_codec(const char *name, codec_init_fn init_fn, codec_release_fn release_fn,
codec_get_channels_fn channels_fn, codec_get_frequency_fn frequency_fn,
codec_decode_fn decode_fn)
{
struct codec_handle *handle;
if (registered_codecs == NULL)
registered_codecs = g_hash_table_new(g_str_hash, g_str_equal);
if (g_hash_table_lookup(registered_codecs, name) != NULL)
return FALSE;
handle = (struct codec_handle *)g_malloc(sizeof (struct codec_handle));
handle->name = name;
handle->init_fn = init_fn;
handle->release_fn = release_fn;
handle->channels_fn = channels_fn;
handle->frequency_fn = frequency_fn;
handle->decode_fn = decode_fn;
g_hash_table_insert(registered_codecs, (gpointer)name, (gpointer) handle);
return TRUE;
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
int codec_get_channels(codec_handle_t codec, void *context)
{
if (!codec) return 0;
return (codec->channels_fn)(context);
}
int codec_get_frequency(codec_handle_t codec, void *context)
{
if (!codec) return 0;
return (codec->frequency_fn)(context);
}
int codec_decode(codec_handle_t codec, void *context, const void *input, int inputSizeBytes, void *output, int *outputSizeBytes)
{
if (!codec) return 0;
return (codec->decode_fn)(context, input, inputSizeBytes, output, outputSizeBytes);
}
