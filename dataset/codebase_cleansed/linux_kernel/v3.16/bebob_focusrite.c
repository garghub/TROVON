static inline int
saffire_read_block(struct snd_bebob *bebob, u64 offset,
u32 *buf, unsigned int size)
{
unsigned int i;
int err;
__be32 *tmp = (__be32 *)buf;
err = snd_fw_transaction(bebob->unit, TCODE_READ_BLOCK_REQUEST,
SAFFIRE_ADDRESS_BASE + offset,
tmp, size, 0);
if (err < 0)
goto end;
for (i = 0; i < size / sizeof(u32); i++)
buf[i] = be32_to_cpu(tmp[i]);
end:
return err;
}
static inline int
saffire_read_quad(struct snd_bebob *bebob, u64 offset, u32 *value)
{
int err;
__be32 tmp;
err = snd_fw_transaction(bebob->unit, TCODE_READ_QUADLET_REQUEST,
SAFFIRE_ADDRESS_BASE + offset,
&tmp, sizeof(__be32), 0);
if (err < 0)
goto end;
*value = be32_to_cpu(tmp);
end:
return err;
}
static inline int
saffire_write_quad(struct snd_bebob *bebob, u64 offset, u32 value)
{
__be32 data = cpu_to_be32(value);
return snd_fw_transaction(bebob->unit, TCODE_WRITE_QUADLET_REQUEST,
SAFFIRE_ADDRESS_BASE + offset,
&data, sizeof(__be32), 0);
}
static int
saffirepro_both_clk_freq_get(struct snd_bebob *bebob, unsigned int *rate)
{
u32 id;
int err;
err = saffire_read_quad(bebob, SAFFIREPRO_RATE_NOREBOOT, &id);
if (err < 0)
goto end;
if (id >= ARRAY_SIZE(rates))
err = -EIO;
else
*rate = rates[id];
end:
return err;
}
static int
saffirepro_both_clk_freq_set(struct snd_bebob *bebob, unsigned int rate)
{
u32 id;
for (id = 0; id < ARRAY_SIZE(rates); id++) {
if (rates[id] == rate)
break;
}
if (id == ARRAY_SIZE(rates))
return -EINVAL;
return saffire_write_quad(bebob, SAFFIREPRO_RATE_NOREBOOT, id);
}
static int
saffirepro_both_clk_src_get(struct snd_bebob *bebob, unsigned int *id)
{
int err;
u32 value;
err = saffire_read_quad(bebob, SAFFIREPRO_OFFSET_CLOCK_SOURCE, &value);
if (err < 0)
goto end;
if (bebob->spec->clock->labels == saffirepro_10_clk_src_labels) {
if (value == SAFFIREPRO_CLOCK_SOURCE_WORDCLOCK)
*id = 2;
else if (value == SAFFIREPRO_CLOCK_SOURCE_SPDIF)
*id = 1;
} else if (value > 1) {
*id = value - 1;
}
end:
return err;
}
static int
saffire_both_clk_src_get(struct snd_bebob *bebob, unsigned int *id)
{
int err;
u32 value;
err = saffire_read_quad(bebob, SAFFIRE_OFFSET_CLOCK_SOURCE, &value);
if (err >= 0)
*id = 0xff & value;
return err;
}
static int
saffire_meter_get(struct snd_bebob *bebob, u32 *buf, unsigned int size)
{
struct snd_bebob_meter_spec *spec = bebob->spec->meter;
unsigned int channels;
u64 offset;
int err;
if (spec->labels == saffire_le_meter_labels)
offset = SAFFIRE_LE_OFFSET_METER;
else
offset = SAFFIRE_OFFSET_METER;
channels = spec->num * 2;
if (size < channels * sizeof(u32))
return -EIO;
err = saffire_read_block(bebob, offset, buf, size);
if (err >= 0 && spec->labels == saffire_le_meter_labels) {
swap(buf[1], buf[3]);
swap(buf[2], buf[3]);
swap(buf[3], buf[4]);
swap(buf[7], buf[10]);
swap(buf[8], buf[10]);
swap(buf[9], buf[11]);
swap(buf[11], buf[12]);
swap(buf[15], buf[16]);
}
return err;
}
