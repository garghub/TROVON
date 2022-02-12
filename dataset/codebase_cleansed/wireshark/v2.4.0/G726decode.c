static inline void *
codec_g726_init(int bit_rate, int packing)
{
g726_state_t *decoder = g726_init(NULL, bit_rate, G726_ENCODING_LINEAR, packing);
if (!decoder) {
return NULL;
}
g726_codec_ctx *state = g_new(g726_codec_ctx, 1);
state->state = decoder;
state->bit_rate = bit_rate;
return state;
}
void *codec_g726_16_init(void) { return codec_g726_init(16000, G726_PACKING_RIGHT); }
void *codec_g726_24_init(void) { return codec_g726_init(24000, G726_PACKING_RIGHT); }
void *codec_g726_32_init(void) { return codec_g726_init(32000, G726_PACKING_RIGHT); }
void *codec_g726_40_init(void) { return codec_g726_init(40000, G726_PACKING_RIGHT); }
void *codec_aal2_g726_16_init(void) { return codec_g726_init(16000, G726_PACKING_LEFT); }
void *codec_aal2_g726_24_init(void) { return codec_g726_init(24000, G726_PACKING_LEFT); }
void *codec_aal2_g726_32_init(void) { return codec_g726_init(32000, G726_PACKING_LEFT); }
void *codec_aal2_g726_40_init(void) { return codec_g726_init(40000, G726_PACKING_LEFT); }
void
codec_g726_release(void *ctx)
{
g726_codec_ctx *state = (g726_codec_ctx *)ctx;
if (!state) {
return;
}
g726_free(state->state);
g_free(state);
}
unsigned
codec_g726_get_channels(void *ctx _U_)
{
return 1;
}
unsigned
codec_g726_get_frequency(void *ctx _U_)
{
return 8000;
}
size_t
codec_g726_decode(void *ctx, const void *input, size_t inputSizeBytes, void *output,
size_t *outputSizeBytes)
{
g726_codec_ctx *state = (g726_codec_ctx *)ctx;
if (!state) {
return 0;
}
if (!output || !outputSizeBytes) {
return inputSizeBytes * 8 / (state->bit_rate / 8000) * 2;
}
*outputSizeBytes = 2 * g726_decode(state->state, (int16_t *)output, (const uint8_t *) input, (int)inputSizeBytes);
return *outputSizeBytes;
}
