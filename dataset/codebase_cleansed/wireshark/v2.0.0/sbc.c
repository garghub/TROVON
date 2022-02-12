void *
codec_sbc_init(void)
{
sbc_t *sbc;
sbc = (sbc_t *) g_malloc(sizeof(sbc_t));
sbc_init(sbc, 0L);
return sbc;
}
void
codec_sbc_release(void *ctx)
{
sbc_t *sbc = (sbc_t *) ctx;
sbc_finish(sbc);
g_free(sbc);
}
unsigned
codec_sbc_get_channels(void *ctx)
{
sbc_t *sbc = (sbc_t *) ctx;
if (sbc->mode == SBC_MODE_MONO)
return 1;
return 2;
}
unsigned
codec_sbc_get_frequency(void *ctx)
{
sbc_t *sbc = (sbc_t *) ctx;
int frequency;
switch (sbc->frequency) {
case SBC_FREQ_16000:
frequency = 16000;
break;
case SBC_FREQ_32000:
frequency = 32000;
break;
case SBC_FREQ_44100:
frequency = 44100;
break;
case SBC_FREQ_48000:
frequency = 48000;
break;
default:
frequency = 0;
}
return frequency;
}
size_t
codec_sbc_decode(void *ctx, const void *input, size_t inputSizeBytes, void *output,
size_t *outputSizeBytes)
{
size_t size_in = (size_t) inputSizeBytes;
size_t size_out = SBC_BUFFER;
size_t len;
size_t framelen;
size_t xframe_pos = 0;
const guint8 *data_in = (const guint8 *) input;
guint8 *data_out = (guint8 *) output;
sbc_t *sbc = (sbc_t *) ctx;
guint8 *i_data;
guint8 tmp;
if (!output || !outputSizeBytes) {
return size_out;
}
sbc->endian = SBC_BE;
*outputSizeBytes = 0;
while (xframe_pos < inputSizeBytes) {
framelen = sbc_decode(sbc, data_in, size_in, data_out, size_out, &len);
xframe_pos += framelen;
data_in += framelen;
*outputSizeBytes += len;
for (i_data = data_out; i_data < data_out + len; i_data += 2) {
tmp = i_data[0];
i_data[0] = i_data[1];
i_data[1] = tmp;
}
data_out += len;
}
return *outputSizeBytes;
}
