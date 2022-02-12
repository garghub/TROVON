ChipDescript* ChipHelper_GetVersionSdio(u8 sdio_ver)
{
u32 i;
for (i = 0; i < nelem(chip_ver_to_desc); i++)
{
if (chip_ver_to_desc[i]->chip_version.sdio == sdio_ver)
{
return chip_ver_to_desc[i];
}
}
return &chip_device_desc_null;
}
ChipDescript* ChipHelper_GetVersionAny(u16 from_FF9A, u16 from_FE81)
{
u32 i;
if ((from_FF9A & 0xFF00) != 0)
{
for (i = 0; i < nelem(chip_ver_to_desc); i++)
{
if (chip_ver_to_desc[i]->chip_version.pre_bc7 &&
((from_FF9A & chip_ver_to_desc[i]->chip_version.mask) ==
chip_ver_to_desc[i]->chip_version.result))
{
return chip_ver_to_desc[i];
}
}
}
else
{
for (i = 0; i < nelem(chip_ver_to_desc); i++)
{
if (!chip_ver_to_desc[i]->chip_version.pre_bc7 &&
((from_FE81 & chip_ver_to_desc[i]->chip_version.mask) ==
chip_ver_to_desc[i]->chip_version.result))
{
return chip_ver_to_desc[i];
}
}
}
return &chip_device_desc_null;
}
ChipDescript* ChipHelper_GetVersionUniFi(u16 ver)
{
return ChipHelper_GetVersionAny(0x0000, ver);
}
ChipDescript *ChipHelper_Null(void)
{
return &chip_device_desc_null;
}
ChipDescript* ChipHelper_GetVersionBlueCore(enum chip_helper_bluecore_age bc_age, u16 version)
{
if (bc_age == chip_helper_bluecore_pre_bc7)
{
return ChipHelper_GetVersionAny(version, 0x0000);
}
else
{
return ChipHelper_GetVersionAny(0x0000, version);
}
}
u16 ChipHelper_MapAddress_SPI2HOST(ChipDescript *chip_help, u16 addr)
{
u32 i;
for (i = 0; i < chip_help->map.len; i++)
{
if (chip_help->map.vals[i].spi == addr)
{
return chip_help->map.vals[i].host;
}
}
return addr;
}
u16 ChipHelper_MapAddress_HOST2SPI(ChipDescript *chip_help, u16 addr)
{
u32 i;
for (i = 0; i < chip_help->map.len; i++)
{
if (chip_help->map.vals[i].host == addr)
{
return chip_help->map.vals[i].spi;
}
}
return addr;
}
u16 ChipHelper_WINDOW_ADDRESS(ChipDescript *chip_help,
enum chip_helper_window_index window)
{
if (window < CHIP_HELPER_WINDOW_COUNT &&
chip_help->windows[window] != NULL)
{
return chip_help->windows[window]->address + chip_help->windows[window]->blocked;
}
return 0;
}
u16 ChipHelper_WINDOW_SIZE(ChipDescript *chip_help,
enum chip_helper_window_index window)
{
if (window < CHIP_HELPER_WINDOW_COUNT &&
chip_help->windows[window] != NULL)
{
return chip_help->windows[window]->size - chip_help->windows[window]->blocked;
}
return 0;
}
u32 ChipHelper_ClockStartupSequence(ChipDescript *chip_help,
const struct chip_helper_init_values **val)
{
*val = chip_help->init.vals;
return chip_help->init.len;
}
u32 ChipHelper_HostResetSequence(ChipDescript *chip_help,
const struct chip_helper_reset_values **val)
{
*val = chip_help->reset_prog.vals;
return chip_help->reset_prog.len;
}
s32 ChipHelper_DecodeWindow(ChipDescript *chip_help,
enum chip_helper_window_index window,
enum chip_helper_window_type type,
u32 offset,
u16 *page, u16 *addr, u32 *len)
{
const struct window_info_t *win;
const struct window_shift_info_t *mode;
u16 of, pg;
if (window >= CHIP_HELPER_WINDOW_COUNT)
{
return FALSE;
}
if ((win = chip_help->windows[window]) == NULL)
{
return FALSE;
}
if (type >= CHIP_HELPER_WT_COUNT)
{
return FALSE;
}
if ((mode = &win->mode[type]) == NULL)
{
return FALSE;
}
if (!mode->allowed)
{
return FALSE;
}
pg = (u16)(offset >> mode->page_shift) + mode->page_offset;
of = (u16)(offset & ((1 << mode->page_shift) - 1));
while (of < win->blocked)
{
of += 1 << mode->page_shift;
pg--;
}
*page = pg;
*addr = win->address + of;
*len = win->size - of;
return TRUE;
}
