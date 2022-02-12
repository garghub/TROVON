short hpi_dsp_code_open(u32 adapter, void *os_data, struct dsp_code *dsp_code,
u32 *os_error_code)
{
const struct firmware *firmware;
struct pci_dev *dev = os_data;
struct code_header header;
char fw_name[20];
short err_ret = HPI_ERROR_DSP_FILE_NOT_FOUND;
int err;
sprintf(fw_name, "asihpi/dsp%04x.bin", adapter);
err = request_firmware(&firmware, fw_name, &dev->dev);
if (err || !firmware) {
dev_printk(KERN_ERR, &dev->dev,
"%d, request_firmware failed for %s\n", err,
fw_name);
goto error1;
}
if (firmware->size < sizeof(header)) {
dev_printk(KERN_ERR, &dev->dev, "Header size too small %s\n",
fw_name);
goto error2;
}
memcpy(&header, firmware->data, sizeof(header));
if ((header.type != 0x45444F43) ||
(header.adapter != adapter)
|| (header.size != firmware->size)) {
dev_printk(KERN_ERR, &dev->dev, "Invalid firmware file\n");
goto error2;
}
if ((header.version / 100 & ~1) != (HPI_VER_DECIMAL / 100 & ~1)) {
dev_printk(KERN_ERR, &dev->dev,
"Incompatible firmware version "
"DSP image %d != Driver %d\n", header.version,
HPI_VER_DECIMAL);
goto error2;
}
if (header.version != HPI_VER_DECIMAL) {
dev_printk(KERN_WARNING, &dev->dev,
"Firmware: release version mismatch DSP image %d != Driver %d\n",
header.version, HPI_VER_DECIMAL);
}
HPI_DEBUG_LOG(DEBUG, "dsp code %s opened\n", fw_name);
dsp_code->pvt = kmalloc(sizeof(*dsp_code->pvt), GFP_KERNEL);
if (!dsp_code->pvt) {
err_ret = HPI_ERROR_MEMORY_ALLOC;
goto error2;
}
dsp_code->pvt->dev = dev;
dsp_code->pvt->firmware = firmware;
dsp_code->header = header;
dsp_code->block_length = header.size / sizeof(u32);
dsp_code->word_count = sizeof(header) / sizeof(u32);
return 0;
error2:
release_firmware(firmware);
error1:
dsp_code->block_length = 0;
return err_ret;
}
void hpi_dsp_code_close(struct dsp_code *dsp_code)
{
if (dsp_code->pvt->firmware) {
HPI_DEBUG_LOG(DEBUG, "dsp code closed\n");
release_firmware(dsp_code->pvt->firmware);
dsp_code->pvt->firmware = NULL;
}
kfree(dsp_code->pvt);
}
void hpi_dsp_code_rewind(struct dsp_code *dsp_code)
{
dsp_code->word_count = sizeof(struct code_header) / sizeof(u32);
}
short hpi_dsp_code_read_word(struct dsp_code *dsp_code, u32 *pword)
{
if (dsp_code->word_count + 1 > dsp_code->block_length)
return HPI_ERROR_DSP_FILE_FORMAT;
*pword = ((u32 *)(dsp_code->pvt->firmware->data))[dsp_code->
word_count];
dsp_code->word_count++;
return 0;
}
short hpi_dsp_code_read_block(size_t words_requested,
struct dsp_code *dsp_code, u32 **ppblock)
{
if (dsp_code->word_count + words_requested > dsp_code->block_length)
return HPI_ERROR_DSP_FILE_FORMAT;
*ppblock =
((u32 *)(dsp_code->pvt->firmware->data)) +
dsp_code->word_count;
dsp_code->word_count += words_requested;
return 0;
}
