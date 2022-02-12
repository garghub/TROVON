short hpi_dsp_code_open(u32 adapter, struct dsp_code *ps_dsp_code,
u32 *pos_error_code)
{
const struct firmware *ps_firmware = ps_dsp_code->ps_firmware;
struct code_header header;
char fw_name[20];
int err;
sprintf(fw_name, "asihpi/dsp%04x.bin", adapter);
err = request_firmware(&ps_firmware, fw_name,
&ps_dsp_code->ps_dev->dev);
if (err != 0) {
dev_printk(KERN_ERR, &ps_dsp_code->ps_dev->dev,
"%d, request_firmware failed for %s\n", err,
fw_name);
goto error1;
}
if (ps_firmware->size < sizeof(header)) {
dev_printk(KERN_ERR, &ps_dsp_code->ps_dev->dev,
"Header size too small %s\n", fw_name);
goto error2;
}
memcpy(&header, ps_firmware->data, sizeof(header));
if (header.adapter != adapter) {
dev_printk(KERN_ERR, &ps_dsp_code->ps_dev->dev,
"Adapter type incorrect %4x != %4x\n", header.adapter,
adapter);
goto error2;
}
if (header.size != ps_firmware->size) {
dev_printk(KERN_ERR, &ps_dsp_code->ps_dev->dev,
"Code size wrong %d != %ld\n", header.size,
(unsigned long)ps_firmware->size);
goto error2;
}
if (header.version / 100 != HPI_VER_DECIMAL / 100) {
dev_printk(KERN_ERR, &ps_dsp_code->ps_dev->dev,
"Incompatible firmware version "
"DSP image %d != Driver %d\n", header.version,
HPI_VER_DECIMAL);
goto error2;
}
if (header.version != HPI_VER_DECIMAL) {
dev_printk(KERN_WARNING, &ps_dsp_code->ps_dev->dev,
"Firmware: release version mismatch DSP image %d != Driver %d\n",
header.version, HPI_VER_DECIMAL);
}
HPI_DEBUG_LOG(DEBUG, "dsp code %s opened\n", fw_name);
ps_dsp_code->ps_firmware = ps_firmware;
ps_dsp_code->block_length = header.size / sizeof(u32);
ps_dsp_code->word_count = sizeof(header) / sizeof(u32);
ps_dsp_code->version = header.version;
ps_dsp_code->crc = header.crc;
return 0;
error2:
release_firmware(ps_firmware);
error1:
ps_dsp_code->ps_firmware = NULL;
ps_dsp_code->block_length = 0;
return HPI_ERROR_DSP_FILE_NOT_FOUND;
}
void hpi_dsp_code_close(struct dsp_code *ps_dsp_code)
{
if (ps_dsp_code->ps_firmware != NULL) {
HPI_DEBUG_LOG(DEBUG, "dsp code closed\n");
release_firmware(ps_dsp_code->ps_firmware);
ps_dsp_code->ps_firmware = NULL;
}
}
void hpi_dsp_code_rewind(struct dsp_code *ps_dsp_code)
{
ps_dsp_code->word_count = sizeof(struct code_header) / sizeof(u32);
}
short hpi_dsp_code_read_word(struct dsp_code *ps_dsp_code, u32 *pword)
{
if (ps_dsp_code->word_count + 1 > ps_dsp_code->block_length)
return HPI_ERROR_DSP_FILE_FORMAT;
*pword = ((u32 *)(ps_dsp_code->ps_firmware->data))[ps_dsp_code->
word_count];
ps_dsp_code->word_count++;
return 0;
}
short hpi_dsp_code_read_block(size_t words_requested,
struct dsp_code *ps_dsp_code, u32 **ppblock)
{
if (ps_dsp_code->word_count + words_requested >
ps_dsp_code->block_length)
return HPI_ERROR_DSP_FILE_FORMAT;
*ppblock =
((u32 *)(ps_dsp_code->ps_firmware->data)) +
ps_dsp_code->word_count;
ps_dsp_code->word_count += words_requested;
return 0;
}
