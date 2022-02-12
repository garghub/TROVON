WS_DLL_PUBLIC_NOEXTERN void register_codec_module(void)
{
register_codec("g723", codec_g7231_init, codec_g7231_release, codec_g7231_decode);
register_codec("g729", codec_g729a_init, codec_g729a_release, codec_g729a_decode);
register_codec("g722", codec_g722_init, codec_g722_release, codec_g722_decode);
}
