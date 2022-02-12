void *codec_g729a_init(void) {
struct g729a_context *ctx = 0;
ctx = (struct g729a_context*)g_malloc0(sizeof(struct g729a_context));
ctx->handle = EasyG729A_init_decoder();
return ctx;
}
void codec_g729a_release(void *context) {
struct g729a_context *ctx = (struct g729a_context*)context;
if (!ctx) return;
EasyG729A_release_decoder(ctx->handle);
g_free(ctx);
}
int codec_g729a_decode(void *context, const void *input, int inputSizeBytes, void *output, int *outputSizeBytes) {
struct g729a_context *ctx = (struct g729a_context*)context;
const unsigned char *bitstream = (const unsigned char*)input;
short *speech = (short*)output;
int decodedBytes = 0;
if (!ctx) return 0;
if ((inputSizeBytes % L_G729A_FRAME_COMPRESSED) != 0)
return 0;
if (!output)
return (inputSizeBytes / L_G729A_FRAME_COMPRESSED) * L_G729A_FRAME * sizeof(short);
while ((inputSizeBytes >= L_G729A_FRAME_COMPRESSED) &&
((*outputSizeBytes - decodedBytes) >= L_G729A_FRAME * sizeof(short))) {
if (EasyG729A_decoder(ctx->handle, (unsigned char*)bitstream, ctx->speach_buffer)) {
memcpy(speech, ctx->speach_buffer, L_G729A_FRAME * sizeof(short));
speech += L_G729A_FRAME;
decodedBytes += L_G729A_FRAME * sizeof(short);
}
bitstream += L_G729A_FRAME_COMPRESSED;
inputSizeBytes -= L_G729A_FRAME_COMPRESSED;
}
return decodedBytes;
}
