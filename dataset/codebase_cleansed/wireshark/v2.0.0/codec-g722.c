void *codec_g722_init(void) {
struct g722_context *ctx = 0;
ctx = (struct g722_context*)g_malloc0(sizeof(struct g722_context));
ctx->handle = EasyG722_init_decoder();
return ctx;
}
void codec_g722_release(void *context) {
struct g722_context *ctx = (struct g722_context*)context;
if (!ctx) return;
EasyG722_release_decoder(ctx->handle);
g_free(ctx);
}
int codec_g722_decode(void *context, const void *input, int inputSizeBytes, void *output, int *outputSizeBytes) {
struct g722_context *ctx = (struct g722_context*)context;
const unsigned char *bitstream = (const unsigned char*)input;
short *speech = (short*)output;
int decodedBytes = 0;
int i;
if (!ctx) return 0;
if ((inputSizeBytes % L_G722_FRAME_COMPRESSED) != 0)
return 0;
if (!output)
return (inputSizeBytes / L_G722_FRAME_COMPRESSED ) * L_G722_FRAME / 2 * sizeof(short) ;
while ((inputSizeBytes >= L_G722_FRAME_COMPRESSED) &&
((*outputSizeBytes - decodedBytes) >= L_G722_FRAME / 2 * sizeof(short))) {
if (EasyG722_decoder(ctx->handle, (unsigned char*)bitstream, ctx->speach_buffer)) {
int write_index = 0;
for(i = 0; i < L_G722_FRAME; i+=2) {
ctx->speach_buffer[write_index] = ctx->speach_buffer[i];
write_index++;
}
memcpy(speech, ctx->speach_buffer, L_G722_FRAME / 2 * sizeof(short));
speech += L_G722_FRAME / 2;
decodedBytes += L_G722_FRAME / 2 * sizeof(short);
}
bitstream += L_G722_FRAME_COMPRESSED;
inputSizeBytes -= L_G722_FRAME_COMPRESSED;
}
return decodedBytes;
}
