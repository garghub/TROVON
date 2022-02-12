static bool nv_cksum(const uint8_t *data, unsigned int length)
{
int i;
uint8_t sum = 0;
for (i = 0; i < length; i++)
sum += data[i];
if (sum)
return true;
return false;
}
static uint16_t clkcmptable(struct nvbios *bios, uint16_t clktable, int pxclk)
{
int compare_record_len, i = 0;
uint16_t compareclk, scriptptr = 0;
if (bios->major_version < 5)
compare_record_len = 3;
else
compare_record_len = 4;
do {
compareclk = ROM16(bios->data[clktable + compare_record_len * i]);
if (pxclk >= compareclk * 10) {
if (bios->major_version < 5) {
uint8_t tmdssub = bios->data[clktable + 2 + compare_record_len * i];
scriptptr = ROM16(bios->data[bios->init_script_tbls_ptr + tmdssub * 2]);
} else
scriptptr = ROM16(bios->data[clktable + 2 + compare_record_len * i]);
break;
}
i++;
} while (compareclk);
return scriptptr;
}
static void
run_digital_op_script(struct drm_device *dev, uint16_t scriptptr,
struct dcb_output *dcbent, int head, bool dl)
{
struct nouveau_drm *drm = nouveau_drm(dev);
NV_INFO(drm, "0x%04X: Parsing digital output script table\n",
scriptptr);
NVWriteVgaCrtc(dev, 0, NV_CIO_CRE_44, head ? NV_CIO_CRE_44_HEADB :
NV_CIO_CRE_44_HEADA);
nouveau_bios_run_init_table(dev, scriptptr, dcbent, head);
nv04_dfp_bind_head(dev, dcbent, head, dl);
}
static int call_lvds_manufacturer_script(struct drm_device *dev, struct dcb_output *dcbent, int head, enum LVDS_script script)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvbios *bios = &drm->vbios;
uint8_t sub = bios->data[bios->fp.xlated_entry + script] + (bios->fp.link_c_increment && dcbent->or & DCB_OUTPUT_C ? 1 : 0);
uint16_t scriptofs = ROM16(bios->data[bios->init_script_tbls_ptr + sub * 2]);
if (!bios->fp.xlated_entry || !sub || !scriptofs)
return -EINVAL;
run_digital_op_script(dev, scriptofs, dcbent, head, bios->fp.dual_link);
if (script == LVDS_PANEL_OFF) {
mdelay(ROM16(bios->data[bios->fp.xlated_entry + 7]));
}
#ifdef __powerpc__
if (script == LVDS_RESET &&
(dev->pdev->device == 0x0179 || dev->pdev->device == 0x0189 ||
dev->pdev->device == 0x0329))
nv_write_tmds(dev, dcbent->or, 0, 0x02, 0x72);
#endif
return 0;
}
static int run_lvds_table(struct drm_device *dev, struct dcb_output *dcbent, int head, enum LVDS_script script, int pxclk)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvbios *bios = &drm->vbios;
unsigned int outputset = (dcbent->or == 4) ? 1 : 0;
uint16_t scriptptr = 0, clktable;
switch (script) {
case LVDS_INIT:
return -ENOSYS;
case LVDS_BACKLIGHT_ON:
case LVDS_PANEL_ON:
scriptptr = ROM16(bios->data[bios->fp.lvdsmanufacturerpointer + 7 + outputset * 2]);
break;
case LVDS_BACKLIGHT_OFF:
case LVDS_PANEL_OFF:
scriptptr = ROM16(bios->data[bios->fp.lvdsmanufacturerpointer + 11 + outputset * 2]);
break;
case LVDS_RESET:
clktable = bios->fp.lvdsmanufacturerpointer + 15;
if (dcbent->or == 4)
clktable += 8;
if (dcbent->lvdsconf.use_straps_for_mode) {
if (bios->fp.dual_link)
clktable += 4;
if (bios->fp.if_is_24bit)
clktable += 2;
} else {
int cmpval_24bit = (dcbent->or == 4) ? 4 : 1;
if (bios->fp.dual_link) {
clktable += 4;
cmpval_24bit <<= 1;
}
if (bios->fp.strapless_is_24bit & cmpval_24bit)
clktable += 2;
}
clktable = ROM16(bios->data[clktable]);
if (!clktable) {
NV_ERROR(drm, "Pixel clock comparison table not found\n");
return -ENOENT;
}
scriptptr = clkcmptable(bios, clktable, pxclk);
}
if (!scriptptr) {
NV_ERROR(drm, "LVDS output init script not found\n");
return -ENOENT;
}
run_digital_op_script(dev, scriptptr, dcbent, head, bios->fp.dual_link);
return 0;
}
int call_lvds_script(struct drm_device *dev, struct dcb_output *dcbent, int head, enum LVDS_script script, int pxclk)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvif_object *device = &drm->client.device.object;
struct nvbios *bios = &drm->vbios;
uint8_t lvds_ver = bios->data[bios->fp.lvdsmanufacturerpointer];
uint32_t sel_clk_binding, sel_clk;
int ret;
if (bios->fp.last_script_invoc == (script << 1 | head) || !lvds_ver ||
(lvds_ver >= 0x30 && script == LVDS_INIT))
return 0;
if (!bios->fp.lvds_init_run) {
bios->fp.lvds_init_run = true;
call_lvds_script(dev, dcbent, head, LVDS_INIT, pxclk);
}
if (script == LVDS_PANEL_ON && bios->fp.reset_after_pclk_change)
call_lvds_script(dev, dcbent, head, LVDS_RESET, pxclk);
if (script == LVDS_RESET && bios->fp.power_off_for_reset)
call_lvds_script(dev, dcbent, head, LVDS_PANEL_OFF, pxclk);
NV_INFO(drm, "Calling LVDS script %d:\n", script);
sel_clk_binding = nvif_rd32(device, NV_PRAMDAC_SEL_CLK) & 0x50000;
if (lvds_ver < 0x30)
ret = call_lvds_manufacturer_script(dev, dcbent, head, script);
else
ret = run_lvds_table(dev, dcbent, head, script, pxclk);
bios->fp.last_script_invoc = (script << 1 | head);
sel_clk = NVReadRAMDAC(dev, 0, NV_PRAMDAC_SEL_CLK) & ~0x50000;
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_SEL_CLK, sel_clk | sel_clk_binding);
nvif_wr32(device, NV_PBUS_POWERCTRL_2, 0);
return ret;
}
static int parse_lvds_manufacturer_table_header(struct drm_device *dev, struct nvbios *bios, struct lvdstableheader *lth)
{
struct nouveau_drm *drm = nouveau_drm(dev);
uint8_t lvds_ver, headerlen, recordlen;
memset(lth, 0, sizeof(struct lvdstableheader));
if (bios->fp.lvdsmanufacturerpointer == 0x0) {
NV_ERROR(drm, "Pointer to LVDS manufacturer table invalid\n");
return -EINVAL;
}
lvds_ver = bios->data[bios->fp.lvdsmanufacturerpointer];
switch (lvds_ver) {
case 0x0a:
headerlen = 2;
recordlen = bios->data[bios->fp.lvdsmanufacturerpointer + 1];
break;
case 0x30:
headerlen = bios->data[bios->fp.lvdsmanufacturerpointer + 1];
if (headerlen < 0x1f) {
NV_ERROR(drm, "LVDS table header not understood\n");
return -EINVAL;
}
recordlen = bios->data[bios->fp.lvdsmanufacturerpointer + 2];
break;
case 0x40:
headerlen = bios->data[bios->fp.lvdsmanufacturerpointer + 1];
if (headerlen < 0x7) {
NV_ERROR(drm, "LVDS table header not understood\n");
return -EINVAL;
}
recordlen = bios->data[bios->fp.lvdsmanufacturerpointer + 2];
break;
default:
NV_ERROR(drm,
"LVDS table revision %d.%d not currently supported\n",
lvds_ver >> 4, lvds_ver & 0xf);
return -ENOSYS;
}
lth->lvds_ver = lvds_ver;
lth->headerlen = headerlen;
lth->recordlen = recordlen;
return 0;
}
static int
get_fp_strap(struct drm_device *dev, struct nvbios *bios)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvif_object *device = &drm->client.device.object;
if (bios->major_version < 5 && bios->data[0x48] & 0x4)
return NVReadVgaCrtc5758(dev, 0, 0xf) & 0xf;
if (drm->client.device.info.family >= NV_DEVICE_INFO_V0_MAXWELL)
return nvif_rd32(device, 0x001800) & 0x0000000f;
else
if (drm->client.device.info.family >= NV_DEVICE_INFO_V0_TESLA)
return (nvif_rd32(device, NV_PEXTDEV_BOOT_0) >> 24) & 0xf;
else
return (nvif_rd32(device, NV_PEXTDEV_BOOT_0) >> 16) & 0xf;
}
static int parse_fp_mode_table(struct drm_device *dev, struct nvbios *bios)
{
struct nouveau_drm *drm = nouveau_drm(dev);
uint8_t *fptable;
uint8_t fptable_ver, headerlen = 0, recordlen, fpentries = 0xf, fpindex;
int ret, ofs, fpstrapping;
struct lvdstableheader lth;
if (bios->fp.fptablepointer == 0x0) {
#ifndef __powerpc__
NV_ERROR(drm, "Pointer to flat panel table invalid\n");
#endif
bios->digital_min_front_porch = 0x4b;
return 0;
}
fptable = &bios->data[bios->fp.fptablepointer];
fptable_ver = fptable[0];
switch (fptable_ver) {
case 0x05:
recordlen = 42;
ofs = -1;
break;
case 0x10:
recordlen = 44;
ofs = 0;
break;
case 0x20:
headerlen = fptable[1];
recordlen = fptable[2];
fpentries = fptable[3];
bios->digital_min_front_porch = fptable[4];
ofs = -7;
break;
default:
NV_ERROR(drm,
"FP table revision %d.%d not currently supported\n",
fptable_ver >> 4, fptable_ver & 0xf);
return -ENOSYS;
}
if (!bios->is_mobile)
return 0;
ret = parse_lvds_manufacturer_table_header(dev, bios, &lth);
if (ret)
return ret;
if (lth.lvds_ver == 0x30 || lth.lvds_ver == 0x40) {
bios->fp.fpxlatetableptr = bios->fp.lvdsmanufacturerpointer +
lth.headerlen + 1;
bios->fp.xlatwidth = lth.recordlen;
}
if (bios->fp.fpxlatetableptr == 0x0) {
NV_ERROR(drm, "Pointer to flat panel xlat table invalid\n");
return -EINVAL;
}
fpstrapping = get_fp_strap(dev, bios);
fpindex = bios->data[bios->fp.fpxlatetableptr +
fpstrapping * bios->fp.xlatwidth];
if (fpindex > fpentries) {
NV_ERROR(drm, "Bad flat panel table index\n");
return -ENOENT;
}
if (lth.lvds_ver > 0x10)
bios->fp_no_ddc = fpstrapping != 0xf || fpindex != 0xf;
if (fpstrapping == 0xf || fpindex == 0xf)
return 0;
bios->fp.mode_ptr = bios->fp.fptablepointer + headerlen +
recordlen * fpindex + ofs;
NV_INFO(drm, "BIOS FP mode: %dx%d (%dkHz pixel clock)\n",
ROM16(bios->data[bios->fp.mode_ptr + 11]) + 1,
ROM16(bios->data[bios->fp.mode_ptr + 25]) + 1,
ROM16(bios->data[bios->fp.mode_ptr + 7]) * 10);
return 0;
}
bool nouveau_bios_fp_mode(struct drm_device *dev, struct drm_display_mode *mode)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvbios *bios = &drm->vbios;
uint8_t *mode_entry = &bios->data[bios->fp.mode_ptr];
if (!mode)
return bios->fp.mode_ptr;
memset(mode, 0, sizeof(struct drm_display_mode));
mode->clock = ROM16(mode_entry[7]) * 10;
mode->hdisplay = ROM16(mode_entry[11]) + 1;
mode->hsync_start = ROM16(mode_entry[17]) + 1;
mode->hsync_end = ROM16(mode_entry[19]) + 1;
mode->htotal = ROM16(mode_entry[21]) + 1;
mode->vdisplay = ROM16(mode_entry[25]) + 1;
mode->vsync_start = ROM16(mode_entry[31]) + 1;
mode->vsync_end = ROM16(mode_entry[33]) + 1;
mode->vtotal = ROM16(mode_entry[35]) + 1;
mode->flags |= (mode_entry[37] & 0x10) ?
DRM_MODE_FLAG_PHSYNC : DRM_MODE_FLAG_NHSYNC;
mode->flags |= (mode_entry[37] & 0x1) ?
DRM_MODE_FLAG_PVSYNC : DRM_MODE_FLAG_NVSYNC;
mode->status = MODE_OK;
mode->type = DRM_MODE_TYPE_DRIVER | DRM_MODE_TYPE_PREFERRED;
drm_mode_set_name(mode);
return bios->fp.mode_ptr;
}
int nouveau_bios_parse_lvds_table(struct drm_device *dev, int pxclk, bool *dl, bool *if_is_24bit)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvbios *bios = &drm->vbios;
int fpstrapping = get_fp_strap(dev, bios), lvdsmanufacturerindex = 0;
struct lvdstableheader lth;
uint16_t lvdsofs;
int ret, chip_version = bios->chip_version;
ret = parse_lvds_manufacturer_table_header(dev, bios, &lth);
if (ret)
return ret;
switch (lth.lvds_ver) {
case 0x0a:
lvdsmanufacturerindex = bios->data[
bios->fp.fpxlatemanufacturertableptr +
fpstrapping];
if (!pxclk)
break;
if (chip_version < 0x25) {
lvdsmanufacturerindex =
(bios->legacy.lvds_single_a_script_ptr & 1) ?
2 : 0;
if (pxclk >= bios->fp.duallink_transition_clk)
lvdsmanufacturerindex++;
} else if (chip_version < 0x30) {
lvdsmanufacturerindex = 0;
} else {
lvdsmanufacturerindex = 0;
if (pxclk >= bios->fp.duallink_transition_clk)
lvdsmanufacturerindex = 2;
if (pxclk >= 140000)
lvdsmanufacturerindex = 3;
}
break;
case 0x30:
case 0x40:
lvdsmanufacturerindex = fpstrapping;
break;
default:
NV_ERROR(drm, "LVDS table revision not currently supported\n");
return -ENOSYS;
}
lvdsofs = bios->fp.xlated_entry = bios->fp.lvdsmanufacturerpointer + lth.headerlen + lth.recordlen * lvdsmanufacturerindex;
switch (lth.lvds_ver) {
case 0x0a:
bios->fp.power_off_for_reset = bios->data[lvdsofs] & 1;
bios->fp.reset_after_pclk_change = bios->data[lvdsofs] & 2;
bios->fp.dual_link = bios->data[lvdsofs] & 4;
bios->fp.link_c_increment = bios->data[lvdsofs] & 8;
*if_is_24bit = bios->data[lvdsofs] & 16;
break;
case 0x30:
case 0x40:
bios->fp.power_off_for_reset = true;
bios->fp.reset_after_pclk_change = true;
bios->fp.dual_link = bios->data[lvdsofs] & 1;
bios->fp.if_is_24bit = bios->data[lvdsofs] & 2;
bios->fp.strapless_is_24bit = bios->data[bios->fp.lvdsmanufacturerpointer + 4];
bios->fp.duallink_transition_clk = ROM16(bios->data[bios->fp.lvdsmanufacturerpointer + 5]) * 10;
break;
}
if (pxclk && (chip_version < 0x25 || chip_version > 0x28))
bios->fp.dual_link = (pxclk >= bios->fp.duallink_transition_clk);
*dl = bios->fp.dual_link;
return 0;
}
int run_tmds_table(struct drm_device *dev, struct dcb_output *dcbent, int head, int pxclk)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvif_object *device = &drm->client.device.object;
struct nvbios *bios = &drm->vbios;
int cv = bios->chip_version;
uint16_t clktable = 0, scriptptr;
uint32_t sel_clk_binding, sel_clk;
if (cv >= 0x17 && cv != 0x1a && cv != 0x20 &&
dcbent->location != DCB_LOC_ON_CHIP)
return 0;
switch (ffs(dcbent->or)) {
case 1:
clktable = bios->tmds.output0_script_ptr;
break;
case 2:
case 3:
clktable = bios->tmds.output1_script_ptr;
break;
}
if (!clktable) {
NV_ERROR(drm, "Pixel clock comparison table not found\n");
return -EINVAL;
}
scriptptr = clkcmptable(bios, clktable, pxclk);
if (!scriptptr) {
NV_ERROR(drm, "TMDS output init script not found\n");
return -ENOENT;
}
sel_clk_binding = nvif_rd32(device, NV_PRAMDAC_SEL_CLK) & 0x50000;
run_digital_op_script(dev, scriptptr, dcbent, head, pxclk >= 165000);
sel_clk = NVReadRAMDAC(dev, 0, NV_PRAMDAC_SEL_CLK) & ~0x50000;
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_SEL_CLK, sel_clk | sel_clk_binding);
return 0;
}
static void parse_script_table_pointers(struct nvbios *bios, uint16_t offset)
{
bios->init_script_tbls_ptr = ROM16(bios->data[offset]);
}
static int parse_bit_A_tbl_entry(struct drm_device *dev, struct nvbios *bios, struct bit_entry *bitentry)
{
struct nouveau_drm *drm = nouveau_drm(dev);
uint16_t load_table_ptr;
uint8_t version, headerlen, entrylen, num_entries;
if (bitentry->length != 3) {
NV_ERROR(drm, "Do not understand BIT A table\n");
return -EINVAL;
}
load_table_ptr = ROM16(bios->data[bitentry->offset]);
if (load_table_ptr == 0x0) {
NV_DEBUG(drm, "Pointer to BIT loadval table invalid\n");
return -EINVAL;
}
version = bios->data[load_table_ptr];
if (version != 0x10) {
NV_ERROR(drm, "BIT loadval table version %d.%d not supported\n",
version >> 4, version & 0xF);
return -ENOSYS;
}
headerlen = bios->data[load_table_ptr + 1];
entrylen = bios->data[load_table_ptr + 2];
num_entries = bios->data[load_table_ptr + 3];
if (headerlen != 4 || entrylen != 4 || num_entries != 2) {
NV_ERROR(drm, "Do not understand BIT loadval table\n");
return -EINVAL;
}
bios->dactestval = ROM32(bios->data[load_table_ptr + headerlen]) & 0x3ff;
return 0;
}
static int parse_bit_display_tbl_entry(struct drm_device *dev, struct nvbios *bios, struct bit_entry *bitentry)
{
struct nouveau_drm *drm = nouveau_drm(dev);
if (bitentry->length != 4) {
NV_ERROR(drm, "Do not understand BIT display table\n");
return -EINVAL;
}
bios->fp.fptablepointer = ROM16(bios->data[bitentry->offset + 2]);
return 0;
}
static int parse_bit_init_tbl_entry(struct drm_device *dev, struct nvbios *bios, struct bit_entry *bitentry)
{
struct nouveau_drm *drm = nouveau_drm(dev);
if (bitentry->length < 14) {
NV_ERROR(drm, "Do not understand init table\n");
return -EINVAL;
}
parse_script_table_pointers(bios, bitentry->offset);
return 0;
}
static int parse_bit_i_tbl_entry(struct drm_device *dev, struct nvbios *bios, struct bit_entry *bitentry)
{
struct nouveau_drm *drm = nouveau_drm(dev);
uint16_t daccmpoffset;
uint8_t dacver, dacheaderlen;
if (bitentry->length < 6) {
NV_ERROR(drm, "BIT i table too short for needed information\n");
return -EINVAL;
}
bios->feature_byte = bios->data[bitentry->offset + 5];
bios->is_mobile = bios->feature_byte & FEATURE_MOBILE;
if (bitentry->length < 15) {
NV_WARN(drm, "BIT i table not long enough for DAC load "
"detection comparison table\n");
return -EINVAL;
}
daccmpoffset = ROM16(bios->data[bitentry->offset + 13]);
if (!daccmpoffset)
return 0;
dacver = bios->data[daccmpoffset];
dacheaderlen = bios->data[daccmpoffset + 1];
if (dacver != 0x00 && dacver != 0x10) {
NV_WARN(drm, "DAC load detection comparison table version "
"%d.%d not known\n", dacver >> 4, dacver & 0xf);
return -ENOSYS;
}
bios->dactestval = ROM32(bios->data[daccmpoffset + dacheaderlen]);
bios->tvdactestval = ROM32(bios->data[daccmpoffset + dacheaderlen + 4]);
return 0;
}
static int parse_bit_lvds_tbl_entry(struct drm_device *dev, struct nvbios *bios, struct bit_entry *bitentry)
{
struct nouveau_drm *drm = nouveau_drm(dev);
if (bitentry->length != 2) {
NV_ERROR(drm, "Do not understand BIT LVDS table\n");
return -EINVAL;
}
bios->fp.lvdsmanufacturerpointer = ROM16(bios->data[bitentry->offset]);
return 0;
}
static int
parse_bit_M_tbl_entry(struct drm_device *dev, struct nvbios *bios,
struct bit_entry *bitentry)
{
if (bitentry->length < 0x5)
return 0;
if (bitentry->version < 2) {
bios->ram_restrict_group_count = bios->data[bitentry->offset + 2];
bios->ram_restrict_tbl_ptr = ROM16(bios->data[bitentry->offset + 3]);
} else {
bios->ram_restrict_group_count = bios->data[bitentry->offset + 0];
bios->ram_restrict_tbl_ptr = ROM16(bios->data[bitentry->offset + 1]);
}
return 0;
}
static int parse_bit_tmds_tbl_entry(struct drm_device *dev, struct nvbios *bios, struct bit_entry *bitentry)
{
struct nouveau_drm *drm = nouveau_drm(dev);
uint16_t tmdstableptr, script1, script2;
if (bitentry->length != 2) {
NV_ERROR(drm, "Do not understand BIT TMDS table\n");
return -EINVAL;
}
tmdstableptr = ROM16(bios->data[bitentry->offset]);
if (!tmdstableptr) {
NV_ERROR(drm, "Pointer to TMDS table invalid\n");
return -EINVAL;
}
NV_INFO(drm, "TMDS table version %d.%d\n",
bios->data[tmdstableptr] >> 4, bios->data[tmdstableptr] & 0xf);
if (bios->data[tmdstableptr] != 0x11)
return -ENOSYS;
script1 = ROM16(bios->data[tmdstableptr + 7]);
script2 = ROM16(bios->data[tmdstableptr + 9]);
if (bios->data[script1] != 'q' || bios->data[script2] != 'q')
NV_WARN(drm, "TMDS table script pointers not stubbed\n");
bios->tmds.output0_script_ptr = ROM16(bios->data[tmdstableptr + 11]);
bios->tmds.output1_script_ptr = ROM16(bios->data[tmdstableptr + 13]);
return 0;
}
int
bit_table(struct drm_device *dev, u8 id, struct bit_entry *bit)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvbios *bios = &drm->vbios;
u8 entries, *entry;
if (bios->type != NVBIOS_BIT)
return -ENODEV;
entries = bios->data[bios->offset + 10];
entry = &bios->data[bios->offset + 12];
while (entries--) {
if (entry[0] == id) {
bit->id = entry[0];
bit->version = entry[1];
bit->length = ROM16(entry[2]);
bit->offset = ROM16(entry[4]);
bit->data = ROMPTR(dev, entry[4]);
return 0;
}
entry += bios->data[bios->offset + 9];
}
return -ENOENT;
}
static int
parse_bit_table(struct nvbios *bios, const uint16_t bitoffset,
struct bit_table *table)
{
struct drm_device *dev = bios->dev;
struct nouveau_drm *drm = nouveau_drm(dev);
struct bit_entry bitentry;
if (bit_table(dev, table->id, &bitentry) == 0)
return table->parse_fn(dev, bios, &bitentry);
NV_INFO(drm, "BIT table '%c' not found\n", table->id);
return -ENOSYS;
}
static int
parse_bit_structure(struct nvbios *bios, const uint16_t bitoffset)
{
int ret;
ret = parse_bit_table(bios, bitoffset, &BIT_TABLE('i', i));
if (ret)
return ret;
if (bios->major_version >= 0x60)
parse_bit_table(bios, bitoffset, &BIT_TABLE('A', A));
parse_bit_table(bios, bitoffset, &BIT_TABLE('D', display));
ret = parse_bit_table(bios, bitoffset, &BIT_TABLE('I', init));
if (ret)
return ret;
parse_bit_table(bios, bitoffset, &BIT_TABLE('M', M));
parse_bit_table(bios, bitoffset, &BIT_TABLE('L', lvds));
parse_bit_table(bios, bitoffset, &BIT_TABLE('T', tmds));
return 0;
}
static int parse_bmp_structure(struct drm_device *dev, struct nvbios *bios, unsigned int offset)
{
struct nouveau_drm *drm = nouveau_drm(dev);
uint8_t *bmp = &bios->data[offset], bmp_version_major, bmp_version_minor;
uint16_t bmplength;
uint16_t legacy_scripts_offset, legacy_i2c_offset;
bios->digital_min_front_porch = 0x4b;
bios->fmaxvco = 256000;
bios->fminvco = 128000;
bios->fp.duallink_transition_clk = 90000;
bmp_version_major = bmp[5];
bmp_version_minor = bmp[6];
NV_INFO(drm, "BMP version %d.%d\n",
bmp_version_major, bmp_version_minor);
if (bmp_version_major < 5)
*(uint16_t *)&bios->data[0x36] = 0;
if ((bmp_version_major < 5 && bmp_version_minor != 1) || bmp_version_major > 5) {
NV_ERROR(drm, "You have an unsupported BMP version. "
"Please send in your bios\n");
return -ENOSYS;
}
if (bmp_version_major == 0)
return 0;
else if (bmp_version_major == 1)
bmplength = 44;
else if (bmp_version_major == 2)
bmplength = 48;
else if (bmp_version_major == 3)
bmplength = 54;
else if (bmp_version_major == 4 || bmp_version_minor < 0x1)
bmplength = 62;
else if (bmp_version_minor < 0x6)
bmplength = 67;
else if (bmp_version_minor < 0x10)
bmplength = 75;
else if (bmp_version_minor == 0x10)
bmplength = 89;
else if (bmp_version_minor < 0x14)
bmplength = 118;
else if (bmp_version_minor < 0x24)
bmplength = 123;
else if (bmp_version_minor < 0x27)
bmplength = 144;
else
bmplength = 158;
if (nv_cksum(bmp, 8)) {
NV_ERROR(drm, "Bad BMP checksum\n");
return -EINVAL;
}
bios->feature_byte = bmp[9];
if (bmp_version_major < 5 || bmp_version_minor < 0x10)
bios->old_style_init = true;
legacy_scripts_offset = 18;
if (bmp_version_major < 2)
legacy_scripts_offset -= 4;
bios->init_script_tbls_ptr = ROM16(bmp[legacy_scripts_offset]);
bios->extra_init_script_tbl_ptr = ROM16(bmp[legacy_scripts_offset + 2]);
if (bmp_version_major > 2) {
bios->legacy.mem_init_tbl_ptr = ROM16(bmp[24]);
bios->legacy.sdr_seq_tbl_ptr = ROM16(bmp[26]);
bios->legacy.ddr_seq_tbl_ptr = ROM16(bmp[28]);
}
legacy_i2c_offset = 0x48;
if (bmplength > 61)
legacy_i2c_offset = offset + 54;
bios->legacy.i2c_indices.crt = bios->data[legacy_i2c_offset];
bios->legacy.i2c_indices.tv = bios->data[legacy_i2c_offset + 1];
bios->legacy.i2c_indices.panel = bios->data[legacy_i2c_offset + 2];
if (bmplength > 74) {
bios->fmaxvco = ROM32(bmp[67]);
bios->fminvco = ROM32(bmp[71]);
}
if (bmplength > 88)
parse_script_table_pointers(bios, offset + 75);
if (bmplength > 94) {
bios->tmds.output0_script_ptr = ROM16(bmp[89]);
bios->tmds.output1_script_ptr = ROM16(bmp[91]);
bios->legacy.lvds_single_a_script_ptr = ROM16(bmp[95]);
}
if (bmplength > 108) {
bios->fp.fptablepointer = ROM16(bmp[105]);
bios->fp.fpxlatetableptr = ROM16(bmp[107]);
bios->fp.xlatwidth = 1;
}
if (bmplength > 120) {
bios->fp.lvdsmanufacturerpointer = ROM16(bmp[117]);
bios->fp.fpxlatemanufacturertableptr = ROM16(bmp[119]);
}
#if 0
if (bmplength > 143)
bios->pll_limit_tbl_ptr = ROM16(bmp[142]);
#endif
if (bmplength > 157)
bios->fp.duallink_transition_clk = ROM16(bmp[156]) * 10;
return 0;
}
static uint16_t findstr(uint8_t *data, int n, const uint8_t *str, int len)
{
int i, j;
for (i = 0; i <= (n - len); i++) {
for (j = 0; j < len; j++)
if (data[i + j] != str[j])
break;
if (j == len)
return i;
}
return 0;
}
void *
olddcb_table(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
u8 *dcb = NULL;
if (drm->client.device.info.family > NV_DEVICE_INFO_V0_TNT)
dcb = ROMPTR(dev, drm->vbios.data[0x36]);
if (!dcb) {
NV_WARN(drm, "No DCB data found in VBIOS\n");
return NULL;
}
if (dcb[0] >= 0x42) {
NV_WARN(drm, "DCB version 0x%02x unknown\n", dcb[0]);
return NULL;
} else
if (dcb[0] >= 0x30) {
if (ROM32(dcb[6]) == 0x4edcbdcb)
return dcb;
} else
if (dcb[0] >= 0x20) {
if (ROM32(dcb[4]) == 0x4edcbdcb)
return dcb;
} else
if (dcb[0] >= 0x15) {
if (!memcmp(&dcb[-7], "DEV_REC", 7))
return dcb;
} else {
NV_WARN(drm, "No useful DCB data in VBIOS\n");
return NULL;
}
NV_WARN(drm, "DCB header validation failed\n");
return NULL;
}
void *
olddcb_outp(struct drm_device *dev, u8 idx)
{
u8 *dcb = olddcb_table(dev);
if (dcb && dcb[0] >= 0x30) {
if (idx < dcb[2])
return dcb + dcb[1] + (idx * dcb[3]);
} else
if (dcb && dcb[0] >= 0x20) {
u8 *i2c = ROMPTR(dev, dcb[2]);
u8 *ent = dcb + 8 + (idx * 8);
if (i2c && ent < i2c)
return ent;
} else
if (dcb && dcb[0] >= 0x15) {
u8 *i2c = ROMPTR(dev, dcb[2]);
u8 *ent = dcb + 4 + (idx * 10);
if (i2c && ent < i2c)
return ent;
}
return NULL;
}
int
olddcb_outp_foreach(struct drm_device *dev, void *data,
int (*exec)(struct drm_device *, void *, int idx, u8 *outp))
{
int ret, idx = -1;
u8 *outp = NULL;
while ((outp = olddcb_outp(dev, ++idx))) {
if (ROM32(outp[0]) == 0x00000000)
break;
if (ROM32(outp[0]) == 0xffffffff)
break;
if ((outp[0] & 0x0f) == DCB_OUTPUT_UNUSED)
continue;
if ((outp[0] & 0x0f) == DCB_OUTPUT_EOL)
break;
ret = exec(dev, data, idx, outp);
if (ret)
return ret;
}
return 0;
}
u8 *
olddcb_conntab(struct drm_device *dev)
{
u8 *dcb = olddcb_table(dev);
if (dcb && dcb[0] >= 0x30 && dcb[1] >= 0x16) {
u8 *conntab = ROMPTR(dev, dcb[0x14]);
if (conntab && conntab[0] >= 0x30 && conntab[0] <= 0x40)
return conntab;
}
return NULL;
}
u8 *
olddcb_conn(struct drm_device *dev, u8 idx)
{
u8 *conntab = olddcb_conntab(dev);
if (conntab && idx < conntab[2])
return conntab + conntab[1] + (idx * conntab[3]);
return NULL;
}
static struct dcb_output *new_dcb_entry(struct dcb_table *dcb)
{
struct dcb_output *entry = &dcb->entry[dcb->entries];
memset(entry, 0, sizeof(struct dcb_output));
entry->index = dcb->entries++;
return entry;
}
static void fabricate_dcb_output(struct dcb_table *dcb, int type, int i2c,
int heads, int or)
{
struct dcb_output *entry = new_dcb_entry(dcb);
entry->type = type;
entry->i2c_index = i2c;
entry->heads = heads;
if (type != DCB_OUTPUT_ANALOG)
entry->location = !DCB_LOC_ON_CHIP;
entry->or = or;
}
static bool
parse_dcb20_entry(struct drm_device *dev, struct dcb_table *dcb,
uint32_t conn, uint32_t conf, struct dcb_output *entry)
{
struct nouveau_drm *drm = nouveau_drm(dev);
int link = 0;
entry->type = conn & 0xf;
entry->i2c_index = (conn >> 4) & 0xf;
entry->heads = (conn >> 8) & 0xf;
entry->connector = (conn >> 12) & 0xf;
entry->bus = (conn >> 16) & 0xf;
entry->location = (conn >> 20) & 0x3;
entry->or = (conn >> 24) & 0xf;
switch (entry->type) {
case DCB_OUTPUT_ANALOG:
entry->crtconf.maxfreq = (dcb->version < 0x30) ?
(conf & 0xffff) * 10 :
(conf & 0xff) * 10000;
break;
case DCB_OUTPUT_LVDS:
{
uint32_t mask;
if (conf & 0x1)
entry->lvdsconf.use_straps_for_mode = true;
if (dcb->version < 0x22) {
mask = ~0xd;
entry->lvdsconf.use_straps_for_mode = true;
if (conf & 0x4 || conf & 0x8)
entry->lvdsconf.use_power_scripts = true;
} else {
mask = ~0x7;
if (conf & 0x2)
entry->lvdsconf.use_acpi_for_edid = true;
if (conf & 0x4)
entry->lvdsconf.use_power_scripts = true;
entry->lvdsconf.sor.link = (conf & 0x00000030) >> 4;
link = entry->lvdsconf.sor.link;
}
if (conf & mask) {
if (dcb->version >= 0x40)
break;
NV_ERROR(drm, "Unknown LVDS configuration bits, "
"please report\n");
}
break;
}
case DCB_OUTPUT_TV:
{
if (dcb->version >= 0x30)
entry->tvconf.has_component_output = conf & (0x8 << 4);
else
entry->tvconf.has_component_output = false;
break;
}
case DCB_OUTPUT_DP:
entry->dpconf.sor.link = (conf & 0x00000030) >> 4;
entry->extdev = (conf & 0x0000ff00) >> 8;
switch ((conf & 0x00e00000) >> 21) {
case 0:
entry->dpconf.link_bw = 162000;
break;
case 1:
entry->dpconf.link_bw = 270000;
break;
default:
entry->dpconf.link_bw = 540000;
break;
}
switch ((conf & 0x0f000000) >> 24) {
case 0xf:
case 0x4:
entry->dpconf.link_nr = 4;
break;
case 0x3:
case 0x2:
entry->dpconf.link_nr = 2;
break;
default:
entry->dpconf.link_nr = 1;
break;
}
link = entry->dpconf.sor.link;
break;
case DCB_OUTPUT_TMDS:
if (dcb->version >= 0x40) {
entry->tmdsconf.sor.link = (conf & 0x00000030) >> 4;
entry->extdev = (conf & 0x0000ff00) >> 8;
link = entry->tmdsconf.sor.link;
}
else if (dcb->version >= 0x30)
entry->tmdsconf.slave_addr = (conf & 0x00000700) >> 8;
else if (dcb->version >= 0x22)
entry->tmdsconf.slave_addr = (conf & 0x00000070) >> 4;
break;
case DCB_OUTPUT_EOL:
dcb->entries--;
return false;
default:
break;
}
if (dcb->version < 0x40) {
entry->duallink_possible =
((1 << (ffs(entry->or) - 1)) * 3 == entry->or);
} else {
entry->duallink_possible = (entry->sorconf.link == 3);
}
if (conf & 0x100000)
entry->i2c_upper_default = true;
entry->hasht = (entry->location << 4) | entry->type;
entry->hashm = (entry->heads << 8) | (link << 6) | entry->or;
return true;
}
static bool
parse_dcb15_entry(struct drm_device *dev, struct dcb_table *dcb,
uint32_t conn, uint32_t conf, struct dcb_output *entry)
{
struct nouveau_drm *drm = nouveau_drm(dev);
switch (conn & 0x0000000f) {
case 0:
entry->type = DCB_OUTPUT_ANALOG;
break;
case 1:
entry->type = DCB_OUTPUT_TV;
break;
case 2:
case 4:
if (conn & 0x10)
entry->type = DCB_OUTPUT_LVDS;
else
entry->type = DCB_OUTPUT_TMDS;
break;
case 3:
entry->type = DCB_OUTPUT_LVDS;
break;
default:
NV_ERROR(drm, "Unknown DCB type %d\n", conn & 0x0000000f);
return false;
}
entry->i2c_index = (conn & 0x0003c000) >> 14;
entry->heads = ((conn & 0x001c0000) >> 18) + 1;
entry->or = entry->heads;
entry->location = (conn & 0x01e00000) >> 21;
entry->bus = (conn & 0x0e000000) >> 25;
entry->duallink_possible = false;
switch (entry->type) {
case DCB_OUTPUT_ANALOG:
entry->crtconf.maxfreq = (conf & 0xffff) * 10;
break;
case DCB_OUTPUT_TV:
entry->tvconf.has_component_output = false;
break;
case DCB_OUTPUT_LVDS:
if ((conn & 0x00003f00) >> 8 != 0x10)
entry->lvdsconf.use_straps_for_mode = true;
entry->lvdsconf.use_power_scripts = true;
break;
default:
break;
}
return true;
}
static
void merge_like_dcb_entries(struct drm_device *dev, struct dcb_table *dcb)
{
struct nouveau_drm *drm = nouveau_drm(dev);
int i, newentries = 0;
for (i = 0; i < dcb->entries; i++) {
struct dcb_output *ient = &dcb->entry[i];
int j;
for (j = i + 1; j < dcb->entries; j++) {
struct dcb_output *jent = &dcb->entry[j];
if (jent->type == 100)
continue;
if (jent->i2c_index == ient->i2c_index &&
jent->type == ient->type &&
jent->location == ient->location &&
jent->or == ient->or) {
NV_INFO(drm, "Merging DCB entries %d and %d\n",
i, j);
ient->heads |= jent->heads;
jent->type = 100;
}
}
}
for (i = 0; i < dcb->entries; i++) {
if (dcb->entry[i].type == 100)
continue;
if (newentries != i) {
dcb->entry[newentries] = dcb->entry[i];
dcb->entry[newentries].index = newentries;
}
newentries++;
}
dcb->entries = newentries;
}
static bool
apply_dcb_encoder_quirks(struct drm_device *dev, int idx, u32 *conn, u32 *conf)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct dcb_table *dcb = &drm->vbios.dcb;
if (nv_match_device(dev, 0x040d, 0x1028, 0x019b)) {
if (*conn == 0x02026312 && *conf == 0x00000020)
return false;
}
if (nv_match_device(dev, 0x0201, 0x1462, 0x8851)) {
if (*conn == 0xf2005014 && *conf == 0xffffffff) {
fabricate_dcb_output(dcb, DCB_OUTPUT_TMDS, 1, 1, 1);
return false;
}
}
if (nv_match_device(dev, 0x0ca3, 0x1682, 0x3003)) {
if (idx == 0) {
*conn = 0x02001300;
*conf = 0x00000028;
} else
if (idx == 1) {
*conn = 0x01010312;
*conf = 0x00020030;
} else
if (idx == 2) {
*conn = 0x01010310;
*conf = 0x00000028;
} else
if (idx == 3) {
*conn = 0x02022362;
*conf = 0x00020010;
} else {
*conn = 0x0000000e;
*conf = 0x00000000;
}
}
if (nv_match_device(dev, 0x0615, 0x1682, 0x2605)) {
if (idx == 0) {
*conn = 0x02002300;
*conf = 0x00000028;
} else
if (idx == 1) {
*conn = 0x01010312;
*conf = 0x00020030;
} else
if (idx == 2) {
*conn = 0x04020310;
*conf = 0x00000028;
} else
if (idx == 3) {
*conn = 0x02021322;
*conf = 0x00020010;
} else {
*conn = 0x0000000e;
*conf = 0x00000000;
}
}
if (nv_match_device(dev, 0x0421, 0x3842, 0xc793)) {
if (idx == 0 && *conn == 0x02000300)
*conn = 0x02011300;
else
if (idx == 1 && *conn == 0x04011310)
*conn = 0x04000310;
else
if (idx == 2 && *conn == 0x02011312)
*conn = 0x02000312;
}
return true;
}
static void
fabricate_dcb_encoder_table(struct drm_device *dev, struct nvbios *bios)
{
struct dcb_table *dcb = &bios->dcb;
int all_heads = (nv_two_heads(dev) ? 3 : 1);
#ifdef __powerpc__
if (of_machine_is_compatible("PowerMac4,5")) {
fabricate_dcb_output(dcb, DCB_OUTPUT_TMDS, 0, all_heads, 1);
fabricate_dcb_output(dcb, DCB_OUTPUT_ANALOG, 1, all_heads, 2);
return;
}
#endif
fabricate_dcb_output(dcb, DCB_OUTPUT_ANALOG,
bios->legacy.i2c_indices.crt, 1, 1);
if (nv04_tv_identify(dev, bios->legacy.i2c_indices.tv) >= 0)
fabricate_dcb_output(dcb, DCB_OUTPUT_TV,
bios->legacy.i2c_indices.tv,
all_heads, 0);
else if (bios->tmds.output0_script_ptr ||
bios->tmds.output1_script_ptr)
fabricate_dcb_output(dcb, DCB_OUTPUT_TMDS,
bios->legacy.i2c_indices.panel,
all_heads, 1);
}
static int
parse_dcb_entry(struct drm_device *dev, void *data, int idx, u8 *outp)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct dcb_table *dcb = &drm->vbios.dcb;
u32 conf = (dcb->version >= 0x20) ? ROM32(outp[4]) : ROM32(outp[6]);
u32 conn = ROM32(outp[0]);
bool ret;
if (apply_dcb_encoder_quirks(dev, idx, &conn, &conf)) {
struct dcb_output *entry = new_dcb_entry(dcb);
NV_INFO(drm, "DCB outp %02d: %08x %08x\n", idx, conn, conf);
if (dcb->version >= 0x20)
ret = parse_dcb20_entry(dev, dcb, conn, conf, entry);
else
ret = parse_dcb15_entry(dev, dcb, conn, conf, entry);
if (!ret)
return 1;
if (entry->type == DCB_OUTPUT_TV &&
entry->location == DCB_LOC_ON_CHIP)
entry->i2c_index = 0x0f;
}
return 0;
}
static void
dcb_fake_connectors(struct nvbios *bios)
{
struct dcb_table *dcbt = &bios->dcb;
u8 map[16] = { };
int i, idx = 0;
if (!nv_match_device(bios->dev, 0x0392, 0x107d, 0x20a2)) {
for (i = 0; i < dcbt->entries; i++) {
if (dcbt->entry[i].connector)
return;
}
}
for (i = 0; i < dcbt->entries; i++) {
u8 i2c = dcbt->entry[i].i2c_index;
if (i2c == 0x0f) {
dcbt->entry[i].connector = idx++;
} else {
if (!map[i2c])
map[i2c] = ++idx;
dcbt->entry[i].connector = map[i2c] - 1;
}
}
if (i > 1) {
u8 *conntab = olddcb_conntab(bios->dev);
if (conntab)
conntab[0] = 0x00;
}
}
static int
parse_dcb_table(struct drm_device *dev, struct nvbios *bios)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct dcb_table *dcb = &bios->dcb;
u8 *dcbt, *conn;
int idx;
dcbt = olddcb_table(dev);
if (!dcbt) {
if (bios->type == NVBIOS_BMP) {
fabricate_dcb_encoder_table(dev, bios);
return 0;
}
return -EINVAL;
}
NV_INFO(drm, "DCB version %d.%d\n", dcbt[0] >> 4, dcbt[0] & 0xf);
dcb->version = dcbt[0];
olddcb_outp_foreach(dev, NULL, parse_dcb_entry);
if (dcb->version < 0x21)
merge_like_dcb_entries(dev, dcb);
idx = -1;
while ((conn = olddcb_conn(dev, ++idx))) {
if (conn[0] != 0xff) {
if (olddcb_conntab(dev)[3] < 4)
NV_INFO(drm, "DCB conn %02d: %04x\n",
idx, ROM16(conn[0]));
else
NV_INFO(drm, "DCB conn %02d: %08x\n",
idx, ROM32(conn[0]));
}
}
dcb_fake_connectors(bios);
return 0;
}
static int load_nv17_hwsq_ucode_entry(struct drm_device *dev, struct nvbios *bios, uint16_t hwsq_offset, int entry)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvif_object *device = &drm->client.device.object;
uint8_t bytes_to_write;
uint16_t hwsq_entry_offset;
int i;
if (bios->data[hwsq_offset] <= entry) {
NV_ERROR(drm, "Too few entries in HW sequencer table for "
"requested entry\n");
return -ENOENT;
}
bytes_to_write = bios->data[hwsq_offset + 1];
if (bytes_to_write != 36) {
NV_ERROR(drm, "Unknown HW sequencer entry size\n");
return -EINVAL;
}
NV_INFO(drm, "Loading NV17 power sequencing microcode\n");
hwsq_entry_offset = hwsq_offset + 2 + entry * bytes_to_write;
nvif_wr32(device, 0x00001304, ROM32(bios->data[hwsq_entry_offset]));
bytes_to_write -= 4;
for (i = 0; i < bytes_to_write; i += 4)
nvif_wr32(device, 0x00001400 + i, ROM32(bios->data[hwsq_entry_offset + i + 4]));
nvif_wr32(device, NV_PBUS_DEBUG_4, nvif_rd32(device, NV_PBUS_DEBUG_4) | 0x18);
return 0;
}
static int load_nv17_hw_sequencer_ucode(struct drm_device *dev,
struct nvbios *bios)
{
const uint8_t hwsq_signature[] = { 'H', 'W', 'S', 'Q' };
const int sz = sizeof(hwsq_signature);
int hwsq_offset;
hwsq_offset = findstr(bios->data, bios->length, hwsq_signature, sz);
if (!hwsq_offset)
return 0;
return load_nv17_hwsq_ucode_entry(dev, bios, hwsq_offset + sz, 0);
}
uint8_t *nouveau_bios_embedded_edid(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvbios *bios = &drm->vbios;
const uint8_t edid_sig[] = {
0x00, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x00 };
uint16_t offset = 0;
uint16_t newoffset;
int searchlen = NV_PROM_SIZE;
if (bios->fp.edid)
return bios->fp.edid;
while (searchlen) {
newoffset = findstr(&bios->data[offset], searchlen,
edid_sig, 8);
if (!newoffset)
return NULL;
offset += newoffset;
if (!nv_cksum(&bios->data[offset], EDID1_LEN))
break;
searchlen -= offset;
offset++;
}
NV_INFO(drm, "Found EDID in BIOS\n");
return bios->fp.edid = &bios->data[offset];
}
static bool NVInitVBIOS(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvkm_bios *bios = nvxx_bios(&drm->client.device);
struct nvbios *legacy = &drm->vbios;
memset(legacy, 0, sizeof(struct nvbios));
spin_lock_init(&legacy->lock);
legacy->dev = dev;
legacy->data = bios->data;
legacy->length = bios->size;
legacy->major_version = bios->version.major;
legacy->chip_version = bios->version.chip;
if (bios->bit_offset) {
legacy->type = NVBIOS_BIT;
legacy->offset = bios->bit_offset;
return !parse_bit_structure(legacy, legacy->offset + 6);
} else
if (bios->bmp_offset) {
legacy->type = NVBIOS_BMP;
legacy->offset = bios->bmp_offset;
return !parse_bmp_structure(dev, legacy, legacy->offset);
}
return false;
}
int
nouveau_run_vbios_init(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvbios *bios = &drm->vbios;
int ret = 0;
bios->state.crtchead = 0;
if (bios->major_version < 5)
load_nv17_hw_sequencer_ucode(dev, bios);
if (bios->execute) {
bios->fp.last_script_invoc = 0;
bios->fp.lvds_init_run = false;
}
return ret;
}
static bool
nouveau_bios_posted(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
unsigned htotal;
if (drm->client.device.info.family >= NV_DEVICE_INFO_V0_TESLA)
return true;
htotal = NVReadVgaCrtc(dev, 0, 0x06);
htotal |= (NVReadVgaCrtc(dev, 0, 0x07) & 0x01) << 8;
htotal |= (NVReadVgaCrtc(dev, 0, 0x07) & 0x20) << 4;
htotal |= (NVReadVgaCrtc(dev, 0, 0x25) & 0x01) << 10;
htotal |= (NVReadVgaCrtc(dev, 0, 0x41) & 0x01) << 11;
return (htotal != 0);
}
int
nouveau_bios_init(struct drm_device *dev)
{
struct nouveau_drm *drm = nouveau_drm(dev);
struct nvbios *bios = &drm->vbios;
int ret;
if (!dev->pdev)
return 0;
if (!NVInitVBIOS(dev))
return -ENODEV;
ret = parse_dcb_table(dev, bios);
if (ret)
return ret;
if (!bios->major_version)
return 0;
bios->execute = false;
if (!nouveau_bios_posted(dev)) {
NV_INFO(drm, "Adaptor not initialised, "
"running VBIOS init tables.\n");
bios->execute = true;
}
ret = nouveau_run_vbios_init(dev);
if (ret)
return ret;
if (bios->major_version < 5)
bios->is_mobile = NVReadVgaCrtc(dev, 0, NV_CIO_CRE_4B) & 0x40;
if (bios->is_mobile || bios->major_version >= 5)
ret = parse_fp_mode_table(dev, bios);
bios->execute = true;
return 0;
}
void
nouveau_bios_takedown(struct drm_device *dev)
{
}
