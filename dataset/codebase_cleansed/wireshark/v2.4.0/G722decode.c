void *
codec_g722_init(void)
{
g722_decode_state_t *state;
state = g722_decode_init(NULL, 64000, 0);
return state;
}
void
codec_g722_release(void *ctx)
{
g722_decode_state_t *state = (g722_decode_state_t *)ctx;
if (!state) {
return;
}
g722_decode_free(state);
}
unsigned
codec_g722_get_channels(void *ctx _U_)
{
return 1;
}
unsigned
codec_g722_get_frequency(void *ctx _U_)
{
return 16000;
}
size_t
codec_g722_decode(void *ctx, const void *input, size_t inputSizeBytes, void *output,
size_t *outputSizeBytes)
{
g722_decode_state_t *state = (g722_decode_state_t *)ctx;
if (!state) {
return 0;
}
if (!output || !outputSizeBytes) {
return 4 * inputSizeBytes;
}
*outputSizeBytes = 2 * g722_decode(state, (int16_t *)output, (const uint8_t *)input, (int)inputSizeBytes);
return *outputSizeBytes;
}
