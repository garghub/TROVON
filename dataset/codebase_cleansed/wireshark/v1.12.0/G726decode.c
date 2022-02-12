void *
codec_g726_init(void)
{
memset (&state, 0, sizeof (state));
g726_init(&state, 32000, 0, 1);
return NULL;
}
void
codec_g726_release(void *ctx _U_)
{
}
int
codec_g726_get_channels(void *ctx _U_)
{
return 1;
}
int
codec_g726_get_frequency(void *ctx _U_)
{
return 32000;
}
int
codec_g726_decode(void *ctx _U_, const void *input, int inputSizeBytes, void *output,
int *outputSizeBytes)
{
*outputSizeBytes = 2 * g726_decode(&state, output, (void*) input, inputSizeBytes);
return 0;
}
