static CsrResult retrying_read8(card_t *card, s16 funcnum, u32 addr, u8 *pdata)
{
CsrSdioFunction *sdio = card->sdio_if;
CsrResult r = CSR_RESULT_SUCCESS;
s16 retries;
CsrResult csrResult = CSR_RESULT_SUCCESS;
retries = 0;
while (retries++ < SDIO_RETRIES)
{
if (funcnum == 0)
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
unifi_debug_log_to_buf("r0@%02X", addr);
#endif
csrResult = CsrSdioF0Read8(sdio, addr, pdata);
}
else
{
#ifdef CSR_WIFI_TRANSPORT_CSPI
unifi_error(card->ospriv,
"retrying_read_f0_8: F1 8-bit reads are not allowed.\n");
return CSR_RESULT_FAILURE;
#else
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
unifi_debug_log_to_buf("r@%02X", addr);
#endif
csrResult = CsrSdioRead8(sdio, addr, pdata);
#endif
}
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_debug_log_to_buf("error=%X\n", csrResult);
}
else
{
unifi_debug_log_to_buf("=%X\n", *pdata);
}
#endif
if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
return CSR_WIFI_HIP_RESULT_NO_DEVICE;
}
if (!retryable_sdio_error(csrResult))
{
#ifdef CSR_WIFI_HIP_DATA_PLANE_PROFILE
card->cmd_prof.cmd52_count++;
#endif
break;
}
unifi_trace(card->ospriv, UDBG2, "retryable SDIO error reading F%d 0x%lX\n", funcnum, addr);
}
if ((csrResult == CSR_RESULT_SUCCESS) && (retries > 1))
{
unifi_warning(card->ospriv, "Read succeeded after %d attempts\n", retries);
}
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read from UniFi (addr 0x%lX) after %d tries\n",
addr, retries - 1);
r = CSR_RESULT_FAILURE;
}
return r;
}
static CsrResult retrying_write8(card_t *card, s16 funcnum, u32 addr, u8 data)
{
CsrSdioFunction *sdio = card->sdio_if;
CsrResult r = CSR_RESULT_SUCCESS;
s16 retries;
CsrResult csrResult = CSR_RESULT_SUCCESS;
retries = 0;
while (retries++ < SDIO_RETRIES)
{
if (funcnum == 0)
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
unifi_debug_log_to_buf("w0@%02X=%X", addr, data);
#endif
csrResult = CsrSdioF0Write8(sdio, addr, data);
}
else
{
#ifdef CSR_WIFI_TRANSPORT_CSPI
unifi_error(card->ospriv,
"retrying_write_f0_8: F1 8-bit writes are not allowed.\n");
return CSR_RESULT_FAILURE;
#else
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
unifi_debug_log_to_buf("w@%02X=%X", addr, data);
#endif
csrResult = CsrSdioWrite8(sdio, addr, data);
#endif
}
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_debug_log_to_buf(",error=%X", csrResult);
}
unifi_debug_string_to_buf("\n");
#endif
if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
return CSR_WIFI_HIP_RESULT_NO_DEVICE;
}
if (!retryable_sdio_error(csrResult))
{
#ifdef CSR_WIFI_HIP_DATA_PLANE_PROFILE
card->cmd_prof.cmd52_count++;
#endif
break;
}
unifi_trace(card->ospriv, UDBG2, "retryable SDIO error writing %02X to F%d 0x%lX\n",
data, funcnum, addr);
}
if ((csrResult == CSR_RESULT_SUCCESS) && (retries > 1))
{
unifi_warning(card->ospriv, "Write succeeded after %d attempts\n", retries);
}
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write to UniFi (addr 0x%lX) after %d tries\n",
addr, retries - 1);
r = CSR_RESULT_FAILURE;
}
return r;
}
static CsrResult retrying_read16(card_t *card, s16 funcnum,
u32 addr, u16 *pdata)
{
CsrSdioFunction *sdio = card->sdio_if;
CsrResult r = CSR_RESULT_SUCCESS;
s16 retries;
CsrResult csrResult = CSR_RESULT_SUCCESS;
retries = 0;
while (retries++ < SDIO_RETRIES)
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
unifi_debug_log_to_buf("r@%02X", addr);
#endif
csrResult = CsrSdioRead16(sdio, addr, pdata);
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_debug_log_to_buf("error=%X\n", csrResult);
}
else
{
unifi_debug_log_to_buf("=%X\n", *pdata);
}
#endif
if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
return CSR_WIFI_HIP_RESULT_NO_DEVICE;
}
if (!retryable_sdio_error(csrResult))
{
#ifdef CSR_WIFI_HIP_DATA_PLANE_PROFILE
card->cmd_prof.cmd52_count++;
#endif
break;
}
unifi_trace(card->ospriv, UDBG2, "retryable SDIO error reading F%d 0x%lX\n", funcnum, addr);
}
if ((csrResult == CSR_RESULT_SUCCESS) && (retries > 1))
{
unifi_warning(card->ospriv, "Read succeeded after %d attempts\n", retries);
}
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read from UniFi (addr 0x%lX) after %d tries\n",
addr, retries - 1);
r = CSR_RESULT_FAILURE;
}
return r;
}
static CsrResult retrying_write16(card_t *card, s16 funcnum,
u32 addr, u16 data)
{
CsrSdioFunction *sdio = card->sdio_if;
CsrResult r = CSR_RESULT_SUCCESS;
s16 retries;
CsrResult csrResult = CSR_RESULT_SUCCESS;
retries = 0;
while (retries++ < SDIO_RETRIES)
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
unifi_debug_log_to_buf("w@%02X=%X", addr, data);
#endif
csrResult = CsrSdioWrite16(sdio, addr, data);
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_debug_log_to_buf(",error=%X", csrResult);
}
unifi_debug_string_to_buf("\n");
#endif
if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
return CSR_WIFI_HIP_RESULT_NO_DEVICE;
}
if (!retryable_sdio_error(csrResult))
{
#ifdef CSR_WIFI_HIP_DATA_PLANE_PROFILE
card->cmd_prof.cmd52_count++;
#endif
break;
}
unifi_trace(card->ospriv, UDBG2, "retryable SDIO error writing %02X to F%d 0x%lX\n",
data, funcnum, addr);
}
if ((csrResult == CSR_RESULT_SUCCESS) && (retries > 1))
{
unifi_warning(card->ospriv, "Write succeeded after %d attempts\n", retries);
}
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write to UniFi (addr 0x%lX) after %d tries\n",
addr, retries - 1);
r = CSR_RESULT_FAILURE;
}
return r;
}
CsrResult sdio_read_f0(card_t *card, u32 addr, u8 *pdata)
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
card->cmd_prof.cmd52_f0_r_count++;
#endif
return retrying_read8(card, 0, addr, pdata);
}
CsrResult sdio_write_f0(card_t *card, u32 addr, u8 data)
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
card->cmd_prof.cmd52_f0_w_count++;
#endif
return retrying_write8(card, 0, addr, data);
}
CsrResult unifi_read_direct_8_or_16(card_t *card, u32 addr, u8 *pdata)
{
#ifdef CSR_WIFI_TRANSPORT_CSPI
u16 w;
CsrResult r;
r = retrying_read16(card, card->function, addr, &w);
*pdata = (u8)(w & 0xFF);
return r;
#else
return retrying_read8(card, card->function, addr, pdata);
#endif
}
CsrResult unifi_write_direct_8_or_16(card_t *card, u32 addr, u8 data)
{
if (addr & 1)
{
unifi_warning(card->ospriv,
"Warning: Byte write to an odd address (0x%lX) is dangerous\n",
addr);
}
#ifdef CSR_WIFI_TRANSPORT_CSPI
return retrying_write16(card, card->function, addr, (u16)data);
#else
return retrying_write8(card, card->function, addr, data);
#endif
}
CsrResult unifi_read_direct16(card_t *card, u32 addr, u16 *pdata)
{
return retrying_read16(card, card->function, addr, pdata);
}
CsrResult unifi_write_direct16(card_t *card, u32 addr, u16 data)
{
return retrying_write16(card, card->function, addr, data);
}
CsrResult unifi_read_direct32(card_t *card, u32 addr, u32 *pdata)
{
CsrResult r;
u16 w0, w1;
r = retrying_read16(card, card->function, addr, &w0);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
r = retrying_read16(card, card->function, addr + 2, &w1);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
*pdata = ((u32)w1 << 16) | (u32)w0;
return CSR_RESULT_SUCCESS;
}
static CsrResult unifi_read_directn_match(card_t *card, u32 addr, void *pdata, u16 len, s8 m, u32 *num)
{
CsrResult r;
u32 i;
u8 *cptr;
u16 w;
*num = 0;
cptr = (u8 *)pdata;
for (i = 0; i < len; i += 2)
{
r = retrying_read16(card, card->function, addr, &w);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
*cptr++ = ((u8)w & 0xFF);
if ((m >= 0) && (((s8)w & 0xFF) == m))
{
break;
}
if (i + 1 == len)
{
break;
}
*cptr++ = ((u8)(w >> 8) & 0xFF);
if ((m >= 0) && (((s8)(w >> 8) & 0xFF) == m))
{
break;
}
addr += 2;
}
*num = (s32)(cptr - (u8 *)pdata);
return CSR_RESULT_SUCCESS;
}
CsrResult unifi_read_directn(card_t *card, u32 addr, void *pdata, u16 len)
{
u32 num;
return unifi_read_directn_match(card, addr, pdata, len, -1, &num);
}
CsrResult unifi_write_directn(card_t *card, u32 addr, void *pdata, u16 len)
{
CsrResult r;
u8 *cptr;
s16 signed_len;
cptr = (u8 *)pdata;
signed_len = (s16)len;
while (signed_len > 0)
{
r = retrying_write16(card, card->function, addr, *cptr);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
cptr += 2;
addr += 2;
signed_len -= 2;
}
return CSR_RESULT_SUCCESS;
}
static CsrResult set_dmem_page(card_t *card, u32 dmem_addr, u32 *paddr)
{
u16 page, addr;
u32 len;
CsrResult r;
*paddr = 0;
if (!ChipHelper_DecodeWindow(card->helper,
CHIP_HELPER_WINDOW_3,
CHIP_HELPER_WT_SHARED,
dmem_addr / 2,
&page, &addr, &len))
{
unifi_error(card->ospriv, "Failed to decode SHARED_DMEM_PAGE %08lx\n", dmem_addr);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
if (page != card->dmem_page)
{
unifi_trace(card->ospriv, UDBG6, "setting dmem page=0x%X, addr=0x%lX\n", page, addr);
r = unifi_write_direct16(card, ChipHelper_HOST_WINDOW3_PAGE(card->helper) * 2, page);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write SHARED_DMEM_PAGE\n");
return r;
}
card->dmem_page = page;
}
*paddr = ((s32)addr * 2) + (dmem_addr & 1);
return CSR_RESULT_SUCCESS;
}
static CsrResult set_pmem_page(card_t *card, u32 pmem_addr,
enum chip_helper_window_type mem_type, u32 *paddr)
{
u16 page, addr;
u32 len;
CsrResult r;
*paddr = 0;
if (!ChipHelper_DecodeWindow(card->helper,
CHIP_HELPER_WINDOW_2,
mem_type,
pmem_addr / 2,
&page, &addr, &len))
{
unifi_error(card->ospriv, "Failed to decode PROG MEM PAGE %08lx %d\n", pmem_addr, mem_type);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
if (page != card->pmem_page)
{
unifi_trace(card->ospriv, UDBG6, "setting pmem page=0x%X, addr=0x%lX\n", page, addr);
r = unifi_write_direct16(card, ChipHelper_HOST_WINDOW2_PAGE(card->helper) * 2, page);
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write PROG MEM PAGE\n");
return r;
}
card->pmem_page = page;
}
*paddr = ((s32)addr * 2) + (pmem_addr & 1);
return CSR_RESULT_SUCCESS;
}
static CsrResult set_page(card_t *card, u32 generic_addr, u32 *paddr)
{
s32 space;
u32 addr;
CsrResult r = CSR_RESULT_SUCCESS;
if (!paddr)
{
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
*paddr = 0;
space = UNIFI_GP_SPACE(generic_addr);
addr = UNIFI_GP_OFFSET(generic_addr);
switch (space)
{
case UNIFI_SH_DMEM:
r = set_dmem_page(card, addr, paddr);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
break;
case UNIFI_EXT_FLASH:
if (!ChipHelper_HasFlash(card->helper))
{
unifi_error(card->ospriv, "Bad address space for chip in generic pointer 0x%08lX (helper=0x%x)\n",
generic_addr, card->helper);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
r = set_pmem_page(card, addr, CHIP_HELPER_WT_FLASH, paddr);
break;
case UNIFI_EXT_SRAM:
if (!ChipHelper_HasExtSram(card->helper))
{
unifi_error(card->ospriv, "Bad address space for chip in generic pointer 0x%08l (helper=0x%x)\n",
generic_addr, card->helper);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
r = set_pmem_page(card, addr, CHIP_HELPER_WT_EXT_SRAM, paddr);
break;
case UNIFI_REGISTERS:
*paddr = addr;
break;
case UNIFI_PHY_DMEM:
r = unifi_set_proc_select(card, UNIFI_PROC_PHY);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
*paddr = ChipHelper_DATA_MEMORY_RAM_OFFSET(card->helper) * 2 + addr;
break;
case UNIFI_MAC_DMEM:
r = unifi_set_proc_select(card, UNIFI_PROC_MAC);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
*paddr = ChipHelper_DATA_MEMORY_RAM_OFFSET(card->helper) * 2 + addr;
break;
case UNIFI_BT_DMEM:
if (!ChipHelper_HasBt(card->helper))
{
unifi_error(card->ospriv, "Bad address space for chip in generic pointer 0x%08lX (helper=0x%x)\n",
generic_addr, card->helper);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
r = unifi_set_proc_select(card, UNIFI_PROC_BT);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
*paddr = ChipHelper_DATA_MEMORY_RAM_OFFSET(card->helper) * 2 + addr;
break;
case UNIFI_PHY_PMEM:
r = unifi_set_proc_select(card, UNIFI_PROC_PHY);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
r = set_pmem_page(card, addr, CHIP_HELPER_WT_CODE_RAM, paddr);
break;
case UNIFI_MAC_PMEM:
r = unifi_set_proc_select(card, UNIFI_PROC_MAC);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
r = set_pmem_page(card, addr, CHIP_HELPER_WT_CODE_RAM, paddr);
break;
case UNIFI_BT_PMEM:
if (!ChipHelper_HasBt(card->helper))
{
unifi_error(card->ospriv, "Bad address space for chip in generic pointer 0x%08lX (helper=0x%x)\n",
generic_addr, card->helper);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
r = unifi_set_proc_select(card, UNIFI_PROC_BT);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
r = set_pmem_page(card, addr, CHIP_HELPER_WT_CODE_RAM, paddr);
break;
case UNIFI_PHY_ROM:
if (!ChipHelper_HasRom(card->helper))
{
unifi_error(card->ospriv, "Bad address space for chip in generic pointer 0x%08lX (helper=0x%x)\n",
generic_addr, card->helper);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
r = unifi_set_proc_select(card, UNIFI_PROC_PHY);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
r = set_pmem_page(card, addr, CHIP_HELPER_WT_ROM, paddr);
break;
case UNIFI_MAC_ROM:
if (!ChipHelper_HasRom(card->helper))
{
unifi_error(card->ospriv, "Bad address space for chip in generic pointer 0x%08lX (helper=0x%x)\n",
generic_addr, card->helper);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
r = unifi_set_proc_select(card, UNIFI_PROC_MAC);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
r = set_pmem_page(card, addr, CHIP_HELPER_WT_ROM, paddr);
break;
case UNIFI_BT_ROM:
if (!ChipHelper_HasRom(card->helper) || !ChipHelper_HasBt(card->helper))
{
unifi_error(card->ospriv, "Bad address space for chip in generic pointer 0x%08lX (helper=0x%x)\n",
generic_addr, card->helper);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
r = unifi_set_proc_select(card, UNIFI_PROC_BT);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
r = set_pmem_page(card, addr, CHIP_HELPER_WT_ROM, paddr);
break;
default:
unifi_error(card->ospriv, "Bad address space %d in generic pointer 0x%08lX (helper=0x%x)\n",
space, generic_addr, card->helper);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
return r;
}
CsrResult unifi_set_proc_select(card_t *card, enum unifi_dbg_processors_select select)
{
CsrResult r;
switch (select)
{
case UNIFI_PROC_MAC:
case UNIFI_PROC_PHY:
case UNIFI_PROC_BOTH:
break;
default:
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
if (card->proc_select != (u32)select)
{
r = unifi_write_direct16(card,
ChipHelper_DBG_HOST_PROC_SELECT(card->helper) * 2,
(u8)select);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write to Proc Select register\n");
return r;
}
card->proc_select = (u32)select;
}
return CSR_RESULT_SUCCESS;
}
CsrResult unifi_read_8_or_16(card_t *card, u32 unifi_addr, u8 *pdata)
{
u32 sdio_addr;
CsrResult r;
#ifdef CSR_WIFI_TRANSPORT_CSPI
u16 w;
#endif
r = set_page(card, unifi_addr, &sdio_addr);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
card->cmd_prof.cmd52_r8or16_count++;
#endif
#ifdef CSR_WIFI_TRANSPORT_CSPI
r = retrying_read16(card, card->function, sdio_addr, &w);
*pdata = (u8)(w & 0xFF);
return r;
#else
return retrying_read8(card, card->function, sdio_addr, pdata);
#endif
}
CsrResult unifi_write_8_or_16(card_t *card, u32 unifi_addr, u8 data)
{
u32 sdio_addr;
CsrResult r;
#ifdef CSR_WIFI_TRANSPORT_CSPI
u16 w;
#endif
r = set_page(card, unifi_addr, &sdio_addr);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
if (sdio_addr & 1)
{
unifi_warning(card->ospriv,
"Warning: Byte write to an odd address (0x%lX) is dangerous\n",
sdio_addr);
}
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
card->cmd_prof.cmd52_w8or16_count++;
#endif
#ifdef CSR_WIFI_TRANSPORT_CSPI
w = data;
return retrying_write16(card, card->function, sdio_addr, w);
#else
return retrying_write8(card, card->function, sdio_addr, data);
#endif
}
CsrResult unifi_card_read16(card_t *card, u32 unifi_addr, u16 *pdata)
{
u32 sdio_addr;
CsrResult r;
r = set_page(card, unifi_addr, &sdio_addr);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
card->cmd_prof.cmd52_r16_count++;
#endif
return unifi_read_direct16(card, sdio_addr, pdata);
}
CsrResult unifi_card_write16(card_t *card, u32 unifi_addr, u16 data)
{
u32 sdio_addr;
CsrResult r;
r = set_page(card, unifi_addr, &sdio_addr);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
card->cmd_prof.cmd52_w16_count++;
#endif
return unifi_write_direct16(card, sdio_addr, data);
}
CsrResult unifi_read32(card_t *card, u32 unifi_addr, u32 *pdata)
{
u32 sdio_addr;
CsrResult r;
r = set_page(card, unifi_addr, &sdio_addr);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
card->cmd_prof.cmd52_r32_count++;
#endif
return unifi_read_direct32(card, sdio_addr, pdata);
}
CsrResult unifi_readn_match(card_t *card, u32 unifi_addr, void *pdata, u16 len, s8 match)
{
u32 sdio_addr;
CsrResult r;
u32 num;
r = set_page(card, unifi_addr, &sdio_addr);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
r = unifi_read_directn_match(card, sdio_addr, pdata, len, match, &num);
return r;
}
CsrResult unifi_card_readn(card_t *card, u32 unifi_addr, void *pdata, u16 len)
{
return unifi_readn_match(card, unifi_addr, pdata, len, -1);
}
CsrResult unifi_readnz(card_t *card, u32 unifi_addr, void *pdata, u16 len)
{
return unifi_readn_match(card, unifi_addr, pdata, len, 0);
}
s32 unifi_read_shared_count(card_t *card, u32 addr)
{
u8 b;
#define SHARED_READ_RETRY_LIMIT 10
s32 i;
for (i = 0; i < SHARED_READ_RETRY_LIMIT; i++)
{
CsrResult r;
r = unifi_read_8_or_16(card, addr, &b);
if (r != CSR_RESULT_SUCCESS)
{
return -1;
}
if (!(b & 0x80))
{
return (s32)(b & 0xff);
}
}
return -1;
}
CsrResult unifi_writen(card_t *card, u32 unifi_addr, void *pdata, u16 len)
{
u32 sdio_addr;
CsrResult r;
r = set_page(card, unifi_addr, &sdio_addr);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
return unifi_write_directn(card, sdio_addr, pdata, len);
}
static CsrResult csr_sdio_block_rw(card_t *card, s16 funcnum,
u32 addr, u8 *pdata,
u16 count, s16 dir_is_write)
{
CsrResult csrResult;
if (dir_is_write == UNIFI_SDIO_READ)
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
unifi_debug_log_to_buf("r@%02X#%X=", addr, count);
#endif
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
unifi_debug_log_to_buf("R");
#endif
csrResult = CsrSdioRead(card->sdio_if, addr, pdata, count);
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
unifi_debug_log_to_buf("<");
#endif
}
else
{
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
unifi_debug_log_to_buf("w@%02X#%X=", addr, count);
unifi_debug_hex_to_buf(pdata, count > CSR_WIFI_HIP_SDIO_TRACE_DATA_LENGTH?CSR_WIFI_HIP_SDIO_TRACE_DATA_LENGTH : count);
#endif
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
unifi_debug_log_to_buf("W");
#endif
csrResult = CsrSdioWrite(card->sdio_if, addr, pdata, count);
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_DATA_PLANE_PROFILE)
unifi_debug_log_to_buf(">");
#endif
}
#ifdef CSR_WIFI_HIP_DATA_PLANE_PROFILE
card->cmd_prof.cmd53_count++;
#endif
#if defined (CSR_WIFI_HIP_DEBUG_OFFLINE) && defined (CSR_WIFI_HIP_SDIO_TRACE)
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_debug_log_to_buf("error=%X", csrResult);
}
else if (dir_is_write == UNIFI_SDIO_READ)
{
unifi_debug_hex_to_buf(pdata, count > CSR_WIFI_HIP_SDIO_TRACE_DATA_LENGTH?CSR_WIFI_HIP_SDIO_TRACE_DATA_LENGTH : count);
}
unifi_debug_string_to_buf("\n");
#endif
return csrResult;
}
CsrResult unifi_bulk_rw(card_t *card, u32 handle, void *pdata,
u32 len, s16 direction)
{
#define CMD53_RETRIES 3
#define REWIND_RETRIES 15
#define REWIND_POLLING_RETRIES 5
#define REWIND_DELAY 1
CsrResult csrResult;
CsrResult r = CSR_RESULT_SUCCESS;
s16 retries = CMD53_RETRIES;
s16 stat_retries;
u8 stat;
s16 dump_read;
#ifdef UNIFI_DEBUG
u8 *pdata_lsb = ((u8 *)&pdata) + card->lsb;
#endif
#ifdef CSR_WIFI_MAKE_FAKE_CMD53_ERRORS
static s16 fake_error;
#endif
dump_read = 0;
#ifdef UNIFI_DEBUG
if (*pdata_lsb & 1)
{
unifi_notice(card->ospriv, "CD53 request on a unaligned buffer (addr: 0x%X) dir %s-Host\n",
pdata, (direction == UNIFI_SDIO_READ)?"To" : "From");
if (direction == UNIFI_SDIO_WRITE)
{
dump(pdata, (u16)len);
}
else
{
dump_read = 1;
}
}
#endif
if (!pdata)
{
unifi_error(card->ospriv, "Null pdata for unifi_bulk_rw() len: %d\n", len);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
if ((len & 1) || (len > 0xffff))
{
unifi_error(card->ospriv, "Impossible CMD53 length requested: %d\n", len);
return CSR_WIFI_HIP_RESULT_INVALID_VALUE;
}
while (1)
{
csrResult = csr_sdio_block_rw(card, card->function, handle,
(u8 *)pdata, (u16)len,
direction);
if (csrResult == CSR_SDIO_RESULT_NO_DEVICE)
{
return CSR_WIFI_HIP_RESULT_NO_DEVICE;
}
#ifdef CSR_WIFI_MAKE_FAKE_CMD53_ERRORS
if (++fake_error > 100)
{
fake_error = 90;
unifi_warning(card->ospriv, "Faking a CMD53 error,\n");
if (csrResult == CSR_RESULT_SUCCESS)
{
csrResult = CSR_RESULT_FAILURE;
}
}
#endif
if (csrResult == CSR_RESULT_SUCCESS)
{
if (dump_read)
{
dump(pdata, (u16)len);
}
break;
}
if (card->chip_id <= SDIO_CARD_ID_UNIFI_2)
{
(void)unifi_set_host_state(card, UNIFI_HOST_STATE_AWAKE);
}
if (!retryable_sdio_error(csrResult))
{
unifi_error(card->ospriv, "Fatal error in a CMD53 transfer\n");
break;
}
if (--retries == 0)
{
break;
}
unifi_trace(card->ospriv, UDBG4,
"Error in a CMD53 transfer, retrying (h:%d,l:%u)...\n",
(s16)handle & 0xff, len);
r = unifi_write_8_or_16(card, card->sdio_ctrl_addr + 8,
(u8)(handle & 0xff));
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to write REWIND cmd\n");
return r;
}
r = CardGenInt(card);
if (r != CSR_RESULT_SUCCESS)
{
return r;
}
stat_retries = REWIND_RETRIES;
while (1)
{
r = unifi_read_8_or_16(card, card->sdio_ctrl_addr + 8, &stat);
if (r == CSR_WIFI_HIP_RESULT_NO_DEVICE)
{
return r;
}
if (r != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Failed to read REWIND status\n");
return CSR_RESULT_FAILURE;
}
if (stat == 0)
{
break;
}
if (--stat_retries == 0)
{
unifi_error(card->ospriv, "Timeout waiting for REWIND ready\n");
return CSR_RESULT_FAILURE;
}
if (stat_retries < REWIND_RETRIES - REWIND_POLLING_RETRIES)
{
CsrThreadSleep(REWIND_DELAY);
}
}
}
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Block %s failed after %d retries\n",
(direction == UNIFI_SDIO_READ)?"read" : "write",
CMD53_RETRIES - retries);
return CSR_RESULT_FAILURE;
}
if (direction == UNIFI_SDIO_READ)
{
card->sdio_bytes_read += len;
}
else
{
card->sdio_bytes_written += len;
}
return CSR_RESULT_SUCCESS;
}
CsrResult unifi_bulk_rw_noretry(card_t *card, u32 handle, void *pdata,
u32 len, s16 direction)
{
CsrResult csrResult;
csrResult = csr_sdio_block_rw(card, card->function, handle,
(u8 *)pdata, (u16)len, direction);
if (csrResult != CSR_RESULT_SUCCESS)
{
unifi_error(card->ospriv, "Block %s failed\n",
(direction == UNIFI_SDIO_READ)?"read" : "write");
return csrResult;
}
return CSR_RESULT_SUCCESS;
}
