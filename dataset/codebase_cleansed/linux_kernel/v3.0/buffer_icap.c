u32 buffer_icap_get_status(struct hwicap_drvdata *drvdata)
{
return in_be32(drvdata->base_address + XHI_STATUS_REG_OFFSET);
}
static inline u32 buffer_icap_get_bram(void __iomem *base_address,
u32 offset)
{
return in_be32(base_address + (offset << 2));
}
static inline bool buffer_icap_busy(void __iomem *base_address)
{
u32 status = in_be32(base_address + XHI_STATUS_REG_OFFSET);
return (status & 1) == XHI_NOT_FINISHED;
}
static inline void buffer_icap_set_size(void __iomem *base_address,
u32 data)
{
out_be32(base_address + XHI_SIZE_REG_OFFSET, data);
}
static inline void buffer_icap_set_offset(void __iomem *base_address,
u32 data)
{
out_be32(base_address + XHI_BRAM_OFFSET_REG_OFFSET, data);
}
static inline void buffer_icap_set_rnc(void __iomem *base_address,
u32 data)
{
out_be32(base_address + XHI_RNC_REG_OFFSET, data);
}
static inline void buffer_icap_set_bram(void __iomem *base_address,
u32 offset, u32 data)
{
out_be32(base_address + (offset << 2), data);
}
static int buffer_icap_device_read(struct hwicap_drvdata *drvdata,
u32 offset, u32 count)
{
s32 retries = 0;
void __iomem *base_address = drvdata->base_address;
if (buffer_icap_busy(base_address))
return -EBUSY;
if ((offset + count) > XHI_MAX_BUFFER_INTS)
return -EINVAL;
buffer_icap_set_size(base_address, (count << 2));
buffer_icap_set_offset(base_address, offset);
buffer_icap_set_rnc(base_address, XHI_READBACK);
while (buffer_icap_busy(base_address)) {
retries++;
if (retries > XHI_MAX_RETRIES)
return -EBUSY;
}
return 0;
}
static int buffer_icap_device_write(struct hwicap_drvdata *drvdata,
u32 offset, u32 count)
{
s32 retries = 0;
void __iomem *base_address = drvdata->base_address;
if (buffer_icap_busy(base_address))
return -EBUSY;
if ((offset + count) > XHI_MAX_BUFFER_INTS)
return -EINVAL;
buffer_icap_set_size(base_address, count << 2);
buffer_icap_set_offset(base_address, offset);
buffer_icap_set_rnc(base_address, XHI_CONFIGURE);
while (buffer_icap_busy(base_address)) {
retries++;
if (retries > XHI_MAX_RETRIES)
return -EBUSY;
}
return 0;
}
void buffer_icap_reset(struct hwicap_drvdata *drvdata)
{
out_be32(drvdata->base_address + XHI_STATUS_REG_OFFSET, 0xFEFE);
}
int buffer_icap_set_configuration(struct hwicap_drvdata *drvdata, u32 *data,
u32 size)
{
int status;
s32 buffer_count = 0;
s32 num_writes = 0;
bool dirty = 0;
u32 i;
void __iomem *base_address = drvdata->base_address;
for (i = 0, buffer_count = 0; i < size; i++) {
buffer_icap_set_bram(base_address, buffer_count, data[i]);
dirty = 1;
if (buffer_count < XHI_MAX_BUFFER_INTS - 1) {
buffer_count++;
continue;
}
status = buffer_icap_device_write(
drvdata,
XHI_BUFFER_START,
XHI_MAX_BUFFER_INTS);
if (status != 0) {
buffer_icap_reset(drvdata);
return status;
}
buffer_count = 0;
num_writes++;
dirty = 0;
}
if (dirty) {
status = buffer_icap_device_write(drvdata, XHI_BUFFER_START,
buffer_count);
if (status != 0) {
buffer_icap_reset(drvdata);
}
return status;
}
return 0;
}
int buffer_icap_get_configuration(struct hwicap_drvdata *drvdata, u32 *data,
u32 size)
{
int status;
s32 buffer_count = 0;
s32 read_count = 0;
u32 i;
void __iomem *base_address = drvdata->base_address;
for (i = 0, buffer_count = XHI_MAX_BUFFER_INTS; i < size; i++) {
if (buffer_count == XHI_MAX_BUFFER_INTS) {
u32 words_remaining = size - i;
u32 words_to_read =
words_remaining <
XHI_MAX_BUFFER_INTS ? words_remaining :
XHI_MAX_BUFFER_INTS;
status = buffer_icap_device_read(
drvdata,
XHI_BUFFER_START,
words_to_read);
if (status != 0) {
buffer_icap_reset(drvdata);
return status;
}
buffer_count = 0;
read_count++;
}
data[i] = buffer_icap_get_bram(base_address, buffer_count);
buffer_count++;
}
return 0;
}
