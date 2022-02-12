static CsrResult _find_in_slut(card_t *card, symbol_t *psym, u32 *pslut)
{
u32 slut_address;
u16 finger_print;
CsrResult r;
CsrResult csrResult;
if (*pslut == 0xffffffff)
{
r = card_wait_for_firmware_to_start(card, &slut_address);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Firmware hasn't started\n");
return r;
}
*pslut = slut_address;
csrResult = CsrSdioMaxBusClockFrequencySet(card->sdio_if, UNIFI_SDIO_CLOCK_INIT_HZ);
if (csrResult != CSR_RESULT_SUCCESS)
{
r = ConvertCsrSdioToCsrHipResult(card, csrResult);
return r;
}
card->sdio_clock_speed = UNIFI_SDIO_CLOCK_INIT_HZ;
}
else
{
slut_address = *pslut;
}
unifi_trace(card->ospriv, UDBG4, "SLUT addr: 0x%lX\n", slut_address);
unifi_trace(card->ospriv, UDBG4, "Looking for SLUT finger print\n");
finger_print = 0;
r = unifi_card_read16(card, slut_address, &finger_print);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read SLUT finger print\n");
return r;
}
if (finger_print != SLUT_FINGERPRINT)
{
unifi_error(card->ospriv, "Failed to find SLUT fingerprint\n");
return CSR_RESULT_FAILURE;
}
slut_address += 2;
while (1)
{
u16 id;
u32 obj;
r = unifi_card_read16(card, slut_address, &id);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
slut_address += 2;
if (id == CSR_SLT_END)
{
r = CSR_WIFI_HIP_RESULT_RANGE;
break;
}
r = unifi_read32(card, slut_address, &obj);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
slut_address += 4;
unifi_trace(card->ospriv, UDBG3, " found SLUT id %02d.%08lx\n", id, obj);
r = CSR_WIFI_HIP_RESULT_NOT_FOUND;
if (id == psym->id)
{
unifi_trace(card->ospriv, UDBG1, " matched SLUT id %02d.%08lx\n", id, obj);
psym->obj = obj;
r = CSR_RESULT_SUCCESS;
break;
}
}
return r;
}
static CsrResult do_patch_convert_download(card_t *card, void *dlpriv, xbv1_t *pfwinfo)
{
CsrResult r;
u32 slut_base = 0xffffffff;
void *pfw;
u32 psize;
symbol_t sym;
r = unifi_init(card);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv,
"do_patch_convert_download: failed to re-init UniFi\n");
return r;
}
if (card->build_id == 0)
{
u32 ver = 0;
sym.id = CSR_SLT_BUILD_ID_NUMBER;
sym.obj = 0;
unifi_trace(card->ospriv, UDBG1, "Need f/w version\n");
r = _find_in_slut(card, &sym, &slut_base);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to find CSR_SLT_BUILD_ID_NUMBER\n");
return CSR_RESULT_FAILURE;
}
r = unifi_read32(card, sym.obj, &ver);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read f/w id\n");
return CSR_RESULT_FAILURE;
}
card->build_id = ver;
}
pfw = xbv_to_patch(card, unifi_fw_read, dlpriv, pfwinfo, &psize);
if (!pfw)
{
unifi_error(card->ospriv, "Failed to convert f/w to patch");
return CSR_WIFI_HIP_RESULT_NO_MEMORY;
}
else
{
void *desc;
sym.id = CSR_SLT_BOOT_LOADER_CONTROL;
sym.obj = 0;
r = _find_in_slut(card, &sym, &slut_base);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to find BOOT_LOADER_CONTROL\n");
kfree(pfw);
return CSR_RESULT_FAILURE;
}
r = unifi_set_host_state(card, UNIFI_HOST_STATE_AWAKE);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to wake UniFi\n");
}
desc = unifi_fw_open_buffer(card->ospriv, pfw, psize);
if (!desc)
{
kfree(pfw);
return CSR_WIFI_HIP_RESULT_NO_MEMORY;
}
unifi_info(card->ospriv, "Downloading converted f/w as patch\n");
r = unifi_dl_patch(card, desc, sym.obj);
kfree(pfw);
unifi_fw_close_buffer(card->ospriv, desc);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Converted patch download failed\n");
return r;
}
else
{
unifi_trace(card->ospriv, UDBG1, "Converted patch downloaded\n");
}
r = unifi_do_loader_op(card, sym.obj + 6, UNIFI_BOOT_LOADER_RESTART);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write loader restart cmd\n");
}
return r;
}
}
CsrResult unifi_dl_firmware(card_t *card, void *dlpriv)
{
xbv1_t *fwinfo;
CsrResult r;
fwinfo = kmalloc(sizeof(xbv1_t), GFP_KERNEL);
if (fwinfo == NULL)
{
unifi_error(card->ospriv, "Failed to allocate memory for firmware\n");
return CSR_WIFI_HIP_RESULT_NO_MEMORY;
}
r = xbv1_parse(card, unifi_fw_read, dlpriv, fwinfo);
if (r != CSR_RESULT_SUCCESS || fwinfo->mode != xbv_firmware)
{
unifi_error(card->ospriv, "File type is %s, expected firmware.\n",
fwinfo->mode == xbv_patch?"patch" : "unknown");
kfree(fwinfo);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
if (card->chip_id > SDIO_CARD_ID_UNIFI_2)
{
unifi_info(card->ospriv, "Must convert f/w to patch format\n");
r = do_patch_convert_download(card, dlpriv, fwinfo);
}
else
{
unifi_error(card->ospriv, "Only patch downloading supported\n");
r = CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
kfree(fwinfo);
return r;
}
CsrResult unifi_dl_patch(card_t *card, void *dlpriv, u32 boot_ctrl)
{
xbv1_t *fwinfo;
CsrResult r;
unifi_info(card->ospriv, "unifi_dl_patch %p %08x\n", dlpriv, boot_ctrl);
fwinfo = kmalloc(sizeof(xbv1_t), GFP_KERNEL);
if (fwinfo == NULL)
{
unifi_error(card->ospriv, "Failed to allocate memory for patches\n");
return CSR_WIFI_HIP_RESULT_NO_MEMORY;
}
r = xbv1_parse(card, unifi_fw_read, dlpriv, fwinfo);
if (r != CSR_RESULT_SUCCESS || fwinfo->mode != xbv_patch)
{
kfree(fwinfo);
unifi_error(card->ospriv, "Failed to read in patch file\n");
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
if (card->build_id != fwinfo->build_id)
{
unifi_error(card->ospriv, "Wrong patch file for chip (chip = %lu, file = %lu)\n",
card->build_id, fwinfo->build_id);
kfree(fwinfo);
#ifndef CSR_WIFI_IGNORE_PATCH_VERSION_MISMATCH
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
#else
fwinfo = NULL;
dlpriv = NULL;
return CSR_RESULT_SUCCESS;
#endif
}
r = do_patch_download(card, dlpriv, fwinfo, boot_ctrl);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to patch image\n");
}
kfree(fwinfo);
return r;
}
void* unifi_dl_fw_read_start(card_t *card, s8 is_fw)
{
card_info_t card_info;
unifi_card_info(card, &card_info);
unifi_trace(card->ospriv, UDBG5,
"id=%d, ver=0x%x, fw_build=%u, fw_hip=0x%x, block_size=%d\n",
card_info.chip_id, card_info.chip_version,
card_info.fw_build, card_info.fw_hip_version,
card_info.sdio_block_size);
return unifi_fw_read_start(card->ospriv, is_fw, &card_info);
}
static CsrResult safe_read_shared_location(card_t *card, u32 address, u8 *pdata)
{
CsrResult r;
u16 limit = 1000;
u8 b, b2;
*pdata = 0;
r = unifi_read_8_or_16(card, address, &b);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
while (limit--)
{
r = unifi_read_8_or_16(card, address, &b2);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
if (b == b2)
{
*pdata = b;
return CSR_RESULT_SUCCESS;
}
b = b2;
}
return CSR_RESULT_FAILURE;
}
CsrResult unifi_do_loader_op(card_t *card, u32 op_addr, u8 opcode)
{
CsrResult r;
s16 op_retries;
unifi_trace(card->ospriv, UDBG4, "Loader cmd 0x%0x -> 0x%08x\n", opcode, op_addr);
r = unifi_write_8_or_16(card, op_addr, opcode);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write loader copy command\n");
return r;
}
op_retries = 0;
r = CSR_RESULT_SUCCESS;
while (1)
{
u8 op;
r = safe_read_shared_location(card, op_addr, &op);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read loader status\n");
break;
}
if (op == UNIFI_LOADER_IDLE)
{
break;
}
if (op != opcode)
{
unifi_error(card->ospriv, "Error reported by loader: 0x%X\n", op);
r = CSR_RESULT_FAILURE;
break;
}
if (++op_retries >= OPERATION_TIMEOUT_LOOPS)
{
unifi_error(card->ospriv, "Timeout waiting for loader to ack transfer\n");
r = unifi_card_stop_processor(card, UNIFI_PROC_BOTH);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to stop UniFi processors\n");
}
else
{
r = CSR_RESULT_FAILURE;
}
break;
}
CsrThreadSleep(OPERATION_TIMEOUT_DELAY);
}
return r;
}
static CsrResult send_ptdl_to_unifi(card_t *card, void *dlpriv,
const struct PTDL *ptdl, u32 handle,
u32 op_addr)
{
u32 offset;
u8 *buf;
s32 data_len;
u32 write_len;
CsrResult r;
const u16 buf_size = 2 * 1024;
offset = ptdl->dl_offset;
data_len = ptdl->dl_size;
if (data_len > buf_size)
{
unifi_error(card->ospriv, "PTDL block is too large (%u)\n",
ptdl->dl_size);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
buf = kmalloc(buf_size, GFP_KERNEL);
if (buf == NULL)
{
unifi_error(card->ospriv, "Failed to allocate transfer buffer for firmware download\n");
return CSR_WIFI_HIP_RESULT_NO_MEMORY;
}
r = CSR_RESULT_SUCCESS;
if (unifi_fw_read(card->ospriv, dlpriv, offset, buf, data_len) != data_len)
{
unifi_error(card->ospriv, "Failed to read from file\n");
}
else
{
if (card->sdio_io_block_pad)
{
write_len = (data_len + (card->sdio_io_block_size - 1)) &
~(card->sdio_io_block_size - 1);
memset(buf + data_len, 0, write_len - data_len);
}
else
{
write_len = data_len;
}
r = unifi_bulk_rw_noretry(card, handle, buf, write_len, UNIFI_SDIO_WRITE);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "CMD53 failed writing %d bytes to handle %ld\n",
data_len, handle);
}
else
{
r = unifi_do_loader_op(card, op_addr, UNIFI_BOOT_LOADER_PATCH);
}
}
kfree(buf);
if (r != CSR_RESULT_SUCCESS && r != CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
unifi_error(card->ospriv, "Failed to copy block of %u bytes to UniFi\n",
ptdl->dl_size);
}
return r;
}
static CsrResult do_patch_download(card_t *card, void *dlpriv, xbv1_t *pfwinfo, u32 boot_ctrl_addr)
{
CsrResult r;
s32 i;
u16 loader_version;
u16 handle;
u32 total_bytes;
r = unifi_card_read16(card, boot_ctrl_addr, &loader_version);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Patch download: Failed to read loader version\n");
return r;
}
unifi_trace(card->ospriv, UDBG2, "Patch download: boot loader version 0x%04X\n", loader_version);
switch (loader_version)
{
case 0x0000:
break;
default:
unifi_error(card->ospriv, "Patch loader version (0x%04X) is not supported by this driver\n",
loader_version);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
r = unifi_card_read16(card, boot_ctrl_addr + 4, &handle);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Patch download: Failed to read loader handle\n");
return r;
}
if (card->loader_led_mask)
{
r = unifi_card_write16(card, boot_ctrl_addr + 2,
(u16)card->loader_led_mask);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Patch download: Failed to write LED mask\n");
return r;
}
}
total_bytes = 0;
for (i = 0; i < pfwinfo->num_ptdl; i++)
{
unifi_trace(card->ospriv, UDBG3, "Patch download: %d Downloading for %d from offset %d\n",
i,
pfwinfo->ptdl[i].dl_size,
pfwinfo->ptdl[i].dl_offset);
r = send_ptdl_to_unifi(card, dlpriv, &pfwinfo->ptdl[i],
handle, boot_ctrl_addr + 6);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Patch failed after %u bytes\n",
total_bytes);
return r;
}
total_bytes += pfwinfo->ptdl[i].dl_size;
}
return CSR_RESULT_SUCCESS;
}
