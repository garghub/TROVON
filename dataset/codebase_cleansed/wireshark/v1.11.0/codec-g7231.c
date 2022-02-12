void *codec_g7231_init(void) {
struct g7231_context *ctx = 0;
ctx = (struct g7231_context*)g_malloc0(sizeof(struct g7231_context));
ctx->handle = -1;
return ctx;
}
void codec_g7231_release(void *context) {
struct g7231_context *ctx = (struct g7231_context*)context;
if (!ctx) return;
EasyG7231_release_decoder(ctx->handle);
g_free(ctx);
}
int codec_g7231_decode(void *context, const void *input, int inputSizeBytes, void *output, int *outputSizeBytes) {
struct g7231_context *ctx = (struct g7231_context*)context;
const unsigned char *bitstream = (const unsigned char*)input;
short *speech = (short*)output;
int decodedBytes = 0;
if (!ctx) return 0;
if ( ctx->handle == -1) {
if ( bitstream[0] & 0x03 ) {
ctx->handle=EasyG7231_init_decoder(FALSE);
ctx->l_g7231_frame_compressed = L_G7231_FRAME_COMPRESSED_53;
} else {
ctx->handle=EasyG7231_init_decoder(TRUE);
ctx->l_g7231_frame_compressed = L_G7231_FRAME_COMPRESSED_63;
}
}
if ((inputSizeBytes % ctx->l_g7231_frame_compressed) != 0)
return 0;
if (!output)
return (inputSizeBytes / ctx->l_g7231_frame_compressed) * L_G7231_FRAME * sizeof(short);
while ((inputSizeBytes >= ctx->l_g7231_frame_compressed) &&
((*outputSizeBytes - decodedBytes) >= L_G7231_FRAME * sizeof(short))) {
if (EasyG7231_decoder(ctx->handle, (unsigned char*)bitstream, ctx->speach_buffer)) {
memcpy(speech, ctx->speach_buffer, L_G7231_FRAME * sizeof(short));
speech += L_G7231_FRAME;
decodedBytes += L_G7231_FRAME * sizeof(short);
}
bitstream += ctx->l_g7231_frame_compressed;
inputSizeBytes -= ctx->l_g7231_frame_compressed;
}
return decodedBytes;
}
