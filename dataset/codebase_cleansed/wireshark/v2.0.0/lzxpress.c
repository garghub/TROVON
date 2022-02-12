gssize lzxpress_decompress(const guint8 *input,
guint32 input_size,
guint8 *output,
guint32 max_output_size)
{
guint32 output_index, input_index;
guint32 indicator, indicator_bit;
guint32 length;
guint32 offset;
guint32 nibble_index;
output_index = 0;
input_index = 0;
indicator = 0;
indicator_bit = 0;
nibble_index = 0;
do {
if (indicator_bit == 0) {
indicator = PULL_LE_UINT32(input, input_index);
input_index += (guint32)sizeof(guint32);
indicator_bit = 32;
}
indicator_bit--;
if (((indicator >> indicator_bit) & 1) == 0) {
output[output_index] = input[input_index];
input_index += (guint32)sizeof(guint8);
output_index += (guint32)sizeof(guint8);
} else {
length = PULL_LE_UINT16(input, input_index);
input_index += (guint32)sizeof(guint16);
offset = length / 8;
length = length % 8;
if (length == 7) {
if (nibble_index == 0) {
nibble_index = input_index;
length = input[input_index] % 16;
input_index += (guint32)sizeof(guint8);
} else {
length = input[nibble_index] / 16;
nibble_index = 0;
}
if (length == 15) {
length = input[input_index];
input_index += (guint32)sizeof(guint8);
if (length == 255) {
length = PULL_LE_UINT16(input, input_index);
input_index += (guint32)sizeof(guint16);
length -= (15 + 7);
}
length += 15;
}
length += 7;
}
length += 3;
do {
if ((output_index >= max_output_size) || ((offset + 1) > output_index)) break;
output[output_index] = output[output_index - offset - 1];
output_index += (guint32)sizeof(guint8);
length -= (guint32)sizeof(guint8);
} while (length != 0);
}
} while ((output_index < max_output_size) && (input_index < (input_size)));
return output_index;
}
