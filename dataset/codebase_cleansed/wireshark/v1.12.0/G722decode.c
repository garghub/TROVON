void *
codec_g722_init(void)
{
memset (&state, 0, sizeof (state));
g722_decode_init(&state, 64000, 0);
return NULL;
}
void
codec_g722_release(void *ctx _U_)
{
}
int
codec_g722_get_channels(void *ctx _U_)
{
return 1;
}
int
codec_g722_get_frequency(void *ctx _U_)
{
return 64000;
}
int
codec_g722_decode(void *ctx _U_, const void *input, int inputSizeBytes, void *output,
int *outputSizeBytes)
{
*outputSizeBytes = g722_decode(&state, output, input, inputSizeBytes);
return 0;
}
