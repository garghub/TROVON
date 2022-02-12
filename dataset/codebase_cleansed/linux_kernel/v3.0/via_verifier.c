static __inline__ int
eat_words(const uint32_t **buf, const uint32_t *buf_end, unsigned num_words)
{
if ((buf_end - *buf) >= num_words) {
*buf += num_words;
return 0;
}
DRM_ERROR("Illegal termination of DMA command buffer\n");
return 1;
}
static __inline__ drm_local_map_t *via_drm_lookup_agp_map(drm_via_state_t *seq,
unsigned long offset,
unsigned long size,
struct drm_device *dev)
{
struct drm_map_list *r_list;
drm_local_map_t *map = seq->map_cache;
if (map && map->offset <= offset
&& (offset + size) <= (map->offset + map->size)) {
return map;
}
list_for_each_entry(r_list, &dev->maplist, head) {
map = r_list->map;
if (!map)
continue;
if (map->offset <= offset
&& (offset + size) <= (map->offset + map->size)
&& !(map->flags & _DRM_RESTRICTED)
&& (map->type == _DRM_AGP)) {
seq->map_cache = map;
return map;
}
}
return NULL;
}
static __inline__ int finish_current_sequence(drm_via_state_t * cur_seq)
{
switch (cur_seq->unfinished) {
case z_address:
DRM_DEBUG("Z Buffer start address is 0x%x\n", cur_seq->z_addr);
break;
case dest_address:
DRM_DEBUG("Destination start address is 0x%x\n",
cur_seq->d_addr);
break;
case tex_address:
if (cur_seq->agp_texture) {
unsigned start =
cur_seq->tex_level_lo[cur_seq->texture];
unsigned end = cur_seq->tex_level_hi[cur_seq->texture];
unsigned long lo = ~0, hi = 0, tmp;
uint32_t *addr, *pitch, *height, tex;
unsigned i;
int npot;
if (end > 9)
end = 9;
if (start > 9)
start = 9;
addr =
&(cur_seq->t_addr[tex = cur_seq->texture][start]);
pitch = &(cur_seq->pitch[tex][start]);
height = &(cur_seq->height[tex][start]);
npot = cur_seq->tex_npot[tex];
for (i = start; i <= end; ++i) {
tmp = *addr++;
if (tmp < lo)
lo = tmp;
if (i == 0 && npot)
tmp += (*height++ * *pitch++);
else
tmp += (*height++ << *pitch++);
if (tmp > hi)
hi = tmp;
}
if (!via_drm_lookup_agp_map
(cur_seq, lo, hi - lo, cur_seq->dev)) {
DRM_ERROR
("AGP texture is not in allowed map\n");
return 2;
}
}
break;
default:
break;
}
cur_seq->unfinished = no_sequence;
return 0;
}
static __inline__ int
investigate_hazard(uint32_t cmd, hazard_t hz, drm_via_state_t *cur_seq)
{
register uint32_t tmp, *tmp_addr;
if (cur_seq->unfinished && (cur_seq->unfinished != seqs[hz])) {
int ret;
if ((ret = finish_current_sequence(cur_seq)))
return ret;
}
switch (hz) {
case check_for_header2:
if (cmd == HALCYON_HEADER2)
return 1;
return 0;
case check_for_header1:
if ((cmd & HALCYON_HEADER1MASK) == HALCYON_HEADER1)
return 1;
return 0;
case check_for_header2_err:
if (cmd == HALCYON_HEADER2)
return 1;
DRM_ERROR("Illegal DMA HALCYON_HEADER2 command\n");
break;
case check_for_header1_err:
if ((cmd & HALCYON_HEADER1MASK) == HALCYON_HEADER1)
return 1;
DRM_ERROR("Illegal DMA HALCYON_HEADER1 command\n");
break;
case check_for_fire:
if ((cmd & HALCYON_FIREMASK) == HALCYON_FIRECMD)
return 1;
DRM_ERROR("Illegal DMA HALCYON_FIRECMD command\n");
break;
case check_for_dummy:
if (HC_DUMMY == cmd)
return 0;
DRM_ERROR("Illegal DMA HC_DUMMY command\n");
break;
case check_for_dd:
if (0xdddddddd == cmd)
return 0;
DRM_ERROR("Illegal DMA 0xdddddddd command\n");
break;
case check_z_buffer_addr0:
cur_seq->unfinished = z_address;
cur_seq->z_addr = (cur_seq->z_addr & 0xFF000000) |
(cmd & 0x00FFFFFF);
return 0;
case check_z_buffer_addr1:
cur_seq->unfinished = z_address;
cur_seq->z_addr = (cur_seq->z_addr & 0x00FFFFFF) |
((cmd & 0xFF) << 24);
return 0;
case check_z_buffer_addr_mode:
cur_seq->unfinished = z_address;
if ((cmd & 0x0000C000) == 0)
return 0;
DRM_ERROR("Attempt to place Z buffer in system memory\n");
return 2;
case check_destination_addr0:
cur_seq->unfinished = dest_address;
cur_seq->d_addr = (cur_seq->d_addr & 0xFF000000) |
(cmd & 0x00FFFFFF);
return 0;
case check_destination_addr1:
cur_seq->unfinished = dest_address;
cur_seq->d_addr = (cur_seq->d_addr & 0x00FFFFFF) |
((cmd & 0xFF) << 24);
return 0;
case check_destination_addr_mode:
cur_seq->unfinished = dest_address;
if ((cmd & 0x0000C000) == 0)
return 0;
DRM_ERROR
("Attempt to place 3D drawing buffer in system memory\n");
return 2;
case check_texture_addr0:
cur_seq->unfinished = tex_address;
tmp = (cmd >> 24);
tmp_addr = &cur_seq->t_addr[cur_seq->texture][tmp];
*tmp_addr = (*tmp_addr & 0xFF000000) | (cmd & 0x00FFFFFF);
return 0;
case check_texture_addr1:
cur_seq->unfinished = tex_address;
tmp = ((cmd >> 24) - 0x20);
tmp += tmp << 1;
tmp_addr = &cur_seq->t_addr[cur_seq->texture][tmp];
*tmp_addr = (*tmp_addr & 0x00FFFFFF) | ((cmd & 0xFF) << 24);
tmp_addr++;
*tmp_addr = (*tmp_addr & 0x00FFFFFF) | ((cmd & 0xFF00) << 16);
tmp_addr++;
*tmp_addr = (*tmp_addr & 0x00FFFFFF) | ((cmd & 0xFF0000) << 8);
return 0;
case check_texture_addr2:
cur_seq->unfinished = tex_address;
cur_seq->tex_level_lo[tmp = cur_seq->texture] = cmd & 0x3F;
cur_seq->tex_level_hi[tmp] = (cmd & 0xFC0) >> 6;
return 0;
case check_texture_addr3:
cur_seq->unfinished = tex_address;
tmp = ((cmd >> 24) - HC_SubA_HTXnL0Pit);
if (tmp == 0 &&
(cmd & HC_HTXnEnPit_MASK)) {
cur_seq->pitch[cur_seq->texture][tmp] =
(cmd & HC_HTXnLnPit_MASK);
cur_seq->tex_npot[cur_seq->texture] = 1;
} else {
cur_seq->pitch[cur_seq->texture][tmp] =
(cmd & HC_HTXnLnPitE_MASK) >> HC_HTXnLnPitE_SHIFT;
cur_seq->tex_npot[cur_seq->texture] = 0;
if (cmd & 0x000FFFFF) {
DRM_ERROR
("Unimplemented texture level 0 pitch mode.\n");
return 2;
}
}
return 0;
case check_texture_addr4:
cur_seq->unfinished = tex_address;
tmp_addr = &cur_seq->t_addr[cur_seq->texture][9];
*tmp_addr = (*tmp_addr & 0x00FFFFFF) | ((cmd & 0xFF) << 24);
return 0;
case check_texture_addr5:
case check_texture_addr6:
cur_seq->unfinished = tex_address;
return 0;
case check_texture_addr7:
cur_seq->unfinished = tex_address;
tmp_addr = &(cur_seq->height[cur_seq->texture][0]);
tmp_addr[5] = 1 << ((cmd & 0x00F00000) >> 20);
tmp_addr[4] = 1 << ((cmd & 0x000F0000) >> 16);
tmp_addr[3] = 1 << ((cmd & 0x0000F000) >> 12);
tmp_addr[2] = 1 << ((cmd & 0x00000F00) >> 8);
tmp_addr[1] = 1 << ((cmd & 0x000000F0) >> 4);
tmp_addr[0] = 1 << (cmd & 0x0000000F);
return 0;
case check_texture_addr8:
cur_seq->unfinished = tex_address;
tmp_addr = &(cur_seq->height[cur_seq->texture][0]);
tmp_addr[9] = 1 << ((cmd & 0x0000F000) >> 12);
tmp_addr[8] = 1 << ((cmd & 0x00000F00) >> 8);
tmp_addr[7] = 1 << ((cmd & 0x000000F0) >> 4);
tmp_addr[6] = 1 << (cmd & 0x0000000F);
return 0;
case check_texture_addr_mode:
cur_seq->unfinished = tex_address;
if (2 == (tmp = cmd & 0x00000003)) {
DRM_ERROR
("Attempt to fetch texture from system memory.\n");
return 2;
}
cur_seq->agp_texture = (tmp == 3);
cur_seq->tex_palette_size[cur_seq->texture] =
(cmd >> 16) & 0x000000007;
return 0;
case check_for_vertex_count:
cur_seq->vertex_count = cmd & 0x0000FFFF;
return 0;
case check_number_texunits:
cur_seq->multitex = (cmd >> 3) & 1;
return 0;
default:
DRM_ERROR("Illegal DMA data: 0x%x\n", cmd);
return 2;
}
return 2;
}
static __inline__ int
via_check_prim_list(uint32_t const **buffer, const uint32_t * buf_end,
drm_via_state_t *cur_seq)
{
drm_via_private_t *dev_priv =
(drm_via_private_t *) cur_seq->dev->dev_private;
uint32_t a_fire, bcmd, dw_count;
int ret = 0;
int have_fire;
const uint32_t *buf = *buffer;
while (buf < buf_end) {
have_fire = 0;
if ((buf_end - buf) < 2) {
DRM_ERROR
("Unexpected termination of primitive list.\n");
ret = 1;
break;
}
if ((*buf & HC_ACMD_MASK) != HC_ACMD_HCmdB)
break;
bcmd = *buf++;
if ((*buf & HC_ACMD_MASK) != HC_ACMD_HCmdA) {
DRM_ERROR("Expected Vertex List A command, got 0x%x\n",
*buf);
ret = 1;
break;
}
a_fire =
*buf++ | HC_HPLEND_MASK | HC_HPMValidN_MASK |
HC_HE3Fire_MASK;
if (cur_seq->agp && ((bcmd & (0xF << 11)) == 0)) {
DRM_ERROR("Illegal B command vertex data for AGP.\n");
ret = 1;
break;
}
dw_count = 0;
if (bcmd & (1 << 7))
dw_count += (cur_seq->multitex) ? 2 : 1;
if (bcmd & (1 << 8))
dw_count += (cur_seq->multitex) ? 2 : 1;
if (bcmd & (1 << 9))
dw_count++;
if (bcmd & (1 << 10))
dw_count++;
if (bcmd & (1 << 11))
dw_count++;
if (bcmd & (1 << 12))
dw_count++;
if (bcmd & (1 << 13))
dw_count++;
if (bcmd & (1 << 14))
dw_count++;
while (buf < buf_end) {
if (*buf == a_fire) {
if (dev_priv->num_fire_offsets >=
VIA_FIRE_BUF_SIZE) {
DRM_ERROR("Fire offset buffer full.\n");
ret = 1;
break;
}
dev_priv->fire_offsets[dev_priv->
num_fire_offsets++] =
buf;
have_fire = 1;
buf++;
if (buf < buf_end && *buf == a_fire)
buf++;
break;
}
if ((*buf == HALCYON_HEADER2) ||
((*buf & HALCYON_FIREMASK) == HALCYON_FIRECMD)) {
DRM_ERROR("Missing Vertex Fire command, "
"Stray Vertex Fire command or verifier "
"lost sync.\n");
ret = 1;
break;
}
if ((ret = eat_words(&buf, buf_end, dw_count)))
break;
}
if (buf >= buf_end && !have_fire) {
DRM_ERROR("Missing Vertex Fire command or verifier "
"lost sync.\n");
ret = 1;
break;
}
if (cur_seq->agp && ((buf - cur_seq->buf_start) & 0x01)) {
DRM_ERROR("AGP Primitive list end misaligned.\n");
ret = 1;
break;
}
}
*buffer = buf;
return ret;
}
static __inline__ verifier_state_t
via_check_header2(uint32_t const **buffer, const uint32_t *buf_end,
drm_via_state_t *hc_state)
{
uint32_t cmd;
int hz_mode;
hazard_t hz;
const uint32_t *buf = *buffer;
const hazard_t *hz_table;
if ((buf_end - buf) < 2) {
DRM_ERROR
("Illegal termination of DMA HALCYON_HEADER2 sequence.\n");
return state_error;
}
buf++;
cmd = (*buf++ & 0xFFFF0000) >> 16;
switch (cmd) {
case HC_ParaType_CmdVdata:
if (via_check_prim_list(&buf, buf_end, hc_state))
return state_error;
*buffer = buf;
return state_command;
case HC_ParaType_NotTex:
hz_table = table1;
break;
case HC_ParaType_Tex:
hc_state->texture = 0;
hz_table = table2;
break;
case (HC_ParaType_Tex | (HC_SubType_Tex1 << 8)):
hc_state->texture = 1;
hz_table = table2;
break;
case (HC_ParaType_Tex | (HC_SubType_TexGeneral << 8)):
hz_table = table3;
break;
case HC_ParaType_Auto:
if (eat_words(&buf, buf_end, 2))
return state_error;
*buffer = buf;
return state_command;
case (HC_ParaType_Palette | (HC_SubType_Stipple << 8)):
if (eat_words(&buf, buf_end, 32))
return state_error;
*buffer = buf;
return state_command;
case (HC_ParaType_Palette | (HC_SubType_TexPalette0 << 8)):
case (HC_ParaType_Palette | (HC_SubType_TexPalette1 << 8)):
DRM_ERROR("Texture palettes are rejected because of "
"lack of info how to determine their size.\n");
return state_error;
case (HC_ParaType_Palette | (HC_SubType_FogTable << 8)):
DRM_ERROR("Fog factor palettes are rejected because of "
"lack of info how to determine their size.\n");
return state_error;
default:
DRM_ERROR("Invalid or unimplemented HALCYON_HEADER2 "
"DMA subcommand: 0x%x. Previous dword: 0x%x\n",
cmd, *(buf - 2));
*buffer = buf;
return state_error;
}
while (buf < buf_end) {
cmd = *buf++;
if ((hz = hz_table[cmd >> 24])) {
if ((hz_mode = investigate_hazard(cmd, hz, hc_state))) {
if (hz_mode == 1) {
buf--;
break;
}
return state_error;
}
} else if (hc_state->unfinished &&
finish_current_sequence(hc_state)) {
return state_error;
}
}
if (hc_state->unfinished && finish_current_sequence(hc_state))
return state_error;
*buffer = buf;
return state_command;
}
static __inline__ verifier_state_t
via_parse_header2(drm_via_private_t *dev_priv, uint32_t const **buffer,
const uint32_t *buf_end, int *fire_count)
{
uint32_t cmd;
const uint32_t *buf = *buffer;
const uint32_t *next_fire;
int burst = 0;
next_fire = dev_priv->fire_offsets[*fire_count];
buf++;
cmd = (*buf & 0xFFFF0000) >> 16;
VIA_WRITE(HC_REG_TRANS_SET + HC_REG_BASE, *buf++);
switch (cmd) {
case HC_ParaType_CmdVdata:
while ((buf < buf_end) &&
(*fire_count < dev_priv->num_fire_offsets) &&
(*buf & HC_ACMD_MASK) == HC_ACMD_HCmdB) {
while (buf <= next_fire) {
VIA_WRITE(HC_REG_TRANS_SPACE + HC_REG_BASE +
(burst & 63), *buf++);
burst += 4;
}
if ((buf < buf_end)
&& ((*buf & HALCYON_FIREMASK) == HALCYON_FIRECMD))
buf++;
if (++(*fire_count) < dev_priv->num_fire_offsets)
next_fire = dev_priv->fire_offsets[*fire_count];
}
break;
default:
while (buf < buf_end) {
if (*buf == HC_HEADER2 ||
(*buf & HALCYON_HEADER1MASK) == HALCYON_HEADER1 ||
(*buf & VIA_VIDEOMASK) == VIA_VIDEO_HEADER5 ||
(*buf & VIA_VIDEOMASK) == VIA_VIDEO_HEADER6)
break;
VIA_WRITE(HC_REG_TRANS_SPACE + HC_REG_BASE +
(burst & 63), *buf++);
burst += 4;
}
}
*buffer = buf;
return state_command;
}
static __inline__ int verify_mmio_address(uint32_t address)
{
if ((address > 0x3FF) && (address < 0xC00)) {
DRM_ERROR("Invalid VIDEO DMA command. "
"Attempt to access 3D- or command burst area.\n");
return 1;
} else if ((address > 0xCFF) && (address < 0x1300)) {
DRM_ERROR("Invalid VIDEO DMA command. "
"Attempt to access PCI DMA area.\n");
return 1;
} else if (address > 0x13FF) {
DRM_ERROR("Invalid VIDEO DMA command. "
"Attempt to access VGA registers.\n");
return 1;
}
return 0;
}
static __inline__ int
verify_video_tail(uint32_t const **buffer, const uint32_t * buf_end,
uint32_t dwords)
{
const uint32_t *buf = *buffer;
if (buf_end - buf < dwords) {
DRM_ERROR("Illegal termination of video command.\n");
return 1;
}
while (dwords--) {
if (*buf++) {
DRM_ERROR("Illegal video command tail.\n");
return 1;
}
}
*buffer = buf;
return 0;
}
static __inline__ verifier_state_t
via_check_header1(uint32_t const **buffer, const uint32_t * buf_end)
{
uint32_t cmd;
const uint32_t *buf = *buffer;
verifier_state_t ret = state_command;
while (buf < buf_end) {
cmd = *buf;
if ((cmd > ((0x3FF >> 2) | HALCYON_HEADER1)) &&
(cmd < ((0xC00 >> 2) | HALCYON_HEADER1))) {
if ((cmd & HALCYON_HEADER1MASK) != HALCYON_HEADER1)
break;
DRM_ERROR("Invalid HALCYON_HEADER1 command. "
"Attempt to access 3D- or command burst area.\n");
ret = state_error;
break;
} else if (cmd > ((0xCFF >> 2) | HALCYON_HEADER1)) {
if ((cmd & HALCYON_HEADER1MASK) != HALCYON_HEADER1)
break;
DRM_ERROR("Invalid HALCYON_HEADER1 command. "
"Attempt to access VGA registers.\n");
ret = state_error;
break;
} else {
buf += 2;
}
}
*buffer = buf;
return ret;
}
static __inline__ verifier_state_t
via_parse_header1(drm_via_private_t *dev_priv, uint32_t const **buffer,
const uint32_t *buf_end)
{
register uint32_t cmd;
const uint32_t *buf = *buffer;
while (buf < buf_end) {
cmd = *buf;
if ((cmd & HALCYON_HEADER1MASK) != HALCYON_HEADER1)
break;
VIA_WRITE((cmd & ~HALCYON_HEADER1MASK) << 2, *++buf);
buf++;
}
*buffer = buf;
return state_command;
}
static __inline__ verifier_state_t
via_check_vheader5(uint32_t const **buffer, const uint32_t *buf_end)
{
uint32_t data;
const uint32_t *buf = *buffer;
if (buf_end - buf < 4) {
DRM_ERROR("Illegal termination of video header5 command\n");
return state_error;
}
data = *buf++ & ~VIA_VIDEOMASK;
if (verify_mmio_address(data))
return state_error;
data = *buf++;
if (*buf++ != 0x00F50000) {
DRM_ERROR("Illegal header5 header data\n");
return state_error;
}
if (*buf++ != 0x00000000) {
DRM_ERROR("Illegal header5 header data\n");
return state_error;
}
if (eat_words(&buf, buf_end, data))
return state_error;
if ((data & 3) && verify_video_tail(&buf, buf_end, 4 - (data & 3)))
return state_error;
*buffer = buf;
return state_command;
}
static __inline__ verifier_state_t
via_parse_vheader5(drm_via_private_t *dev_priv, uint32_t const **buffer,
const uint32_t *buf_end)
{
uint32_t addr, count, i;
const uint32_t *buf = *buffer;
addr = *buf++ & ~VIA_VIDEOMASK;
i = count = *buf;
buf += 3;
while (i--)
VIA_WRITE(addr, *buf++);
if (count & 3)
buf += 4 - (count & 3);
*buffer = buf;
return state_command;
}
static __inline__ verifier_state_t
via_check_vheader6(uint32_t const **buffer, const uint32_t * buf_end)
{
uint32_t data;
const uint32_t *buf = *buffer;
uint32_t i;
if (buf_end - buf < 4) {
DRM_ERROR("Illegal termination of video header6 command\n");
return state_error;
}
buf++;
data = *buf++;
if (*buf++ != 0x00F60000) {
DRM_ERROR("Illegal header6 header data\n");
return state_error;
}
if (*buf++ != 0x00000000) {
DRM_ERROR("Illegal header6 header data\n");
return state_error;
}
if ((buf_end - buf) < (data << 1)) {
DRM_ERROR("Illegal termination of video header6 command\n");
return state_error;
}
for (i = 0; i < data; ++i) {
if (verify_mmio_address(*buf++))
return state_error;
buf++;
}
data <<= 1;
if ((data & 3) && verify_video_tail(&buf, buf_end, 4 - (data & 3)))
return state_error;
*buffer = buf;
return state_command;
}
static __inline__ verifier_state_t
via_parse_vheader6(drm_via_private_t *dev_priv, uint32_t const **buffer,
const uint32_t *buf_end)
{
uint32_t addr, count, i;
const uint32_t *buf = *buffer;
i = count = *++buf;
buf += 3;
while (i--) {
addr = *buf++;
VIA_WRITE(addr, *buf++);
}
count <<= 1;
if (count & 3)
buf += 4 - (count & 3);
*buffer = buf;
return state_command;
}
int
via_verify_command_stream(const uint32_t * buf, unsigned int size,
struct drm_device * dev, int agp)
{
drm_via_private_t *dev_priv = (drm_via_private_t *) dev->dev_private;
drm_via_state_t *hc_state = &dev_priv->hc_state;
drm_via_state_t saved_state = *hc_state;
uint32_t cmd;
const uint32_t *buf_end = buf + (size >> 2);
verifier_state_t state = state_command;
int cme_video;
int supported_3d;
cme_video = (dev_priv->chipset == VIA_PRO_GROUP_A ||
dev_priv->chipset == VIA_DX9_0);
supported_3d = dev_priv->chipset != VIA_DX9_0;
hc_state->dev = dev;
hc_state->unfinished = no_sequence;
hc_state->map_cache = NULL;
hc_state->agp = agp;
hc_state->buf_start = buf;
dev_priv->num_fire_offsets = 0;
while (buf < buf_end) {
switch (state) {
case state_header2:
state = via_check_header2(&buf, buf_end, hc_state);
break;
case state_header1:
state = via_check_header1(&buf, buf_end);
break;
case state_vheader5:
state = via_check_vheader5(&buf, buf_end);
break;
case state_vheader6:
state = via_check_vheader6(&buf, buf_end);
break;
case state_command:
if ((HALCYON_HEADER2 == (cmd = *buf)) &&
supported_3d)
state = state_header2;
else if ((cmd & HALCYON_HEADER1MASK) == HALCYON_HEADER1)
state = state_header1;
else if (cme_video
&& (cmd & VIA_VIDEOMASK) == VIA_VIDEO_HEADER5)
state = state_vheader5;
else if (cme_video
&& (cmd & VIA_VIDEOMASK) == VIA_VIDEO_HEADER6)
state = state_vheader6;
else if ((cmd == HALCYON_HEADER2) && !supported_3d) {
DRM_ERROR("Accelerated 3D is not supported on this chipset yet.\n");
state = state_error;
} else {
DRM_ERROR
("Invalid / Unimplemented DMA HEADER command. 0x%x\n",
cmd);
state = state_error;
}
break;
case state_error:
default:
*hc_state = saved_state;
return -EINVAL;
}
}
if (state == state_error) {
*hc_state = saved_state;
return -EINVAL;
}
return 0;
}
int
via_parse_command_stream(struct drm_device *dev, const uint32_t *buf,
unsigned int size)
{
drm_via_private_t *dev_priv = (drm_via_private_t *) dev->dev_private;
uint32_t cmd;
const uint32_t *buf_end = buf + (size >> 2);
verifier_state_t state = state_command;
int fire_count = 0;
while (buf < buf_end) {
switch (state) {
case state_header2:
state =
via_parse_header2(dev_priv, &buf, buf_end,
&fire_count);
break;
case state_header1:
state = via_parse_header1(dev_priv, &buf, buf_end);
break;
case state_vheader5:
state = via_parse_vheader5(dev_priv, &buf, buf_end);
break;
case state_vheader6:
state = via_parse_vheader6(dev_priv, &buf, buf_end);
break;
case state_command:
if (HALCYON_HEADER2 == (cmd = *buf))
state = state_header2;
else if ((cmd & HALCYON_HEADER1MASK) == HALCYON_HEADER1)
state = state_header1;
else if ((cmd & VIA_VIDEOMASK) == VIA_VIDEO_HEADER5)
state = state_vheader5;
else if ((cmd & VIA_VIDEOMASK) == VIA_VIDEO_HEADER6)
state = state_vheader6;
else {
DRM_ERROR
("Invalid / Unimplemented DMA HEADER command. 0x%x\n",
cmd);
state = state_error;
}
break;
case state_error:
default:
return -EINVAL;
}
}
if (state == state_error)
return -EINVAL;
return 0;
}
static void
setup_hazard_table(hz_init_t init_table[], hazard_t table[], int size)
{
int i;
for (i = 0; i < 256; ++i)
table[i] = forbidden_command;
for (i = 0; i < size; ++i)
table[init_table[i].code] = init_table[i].hz;
}
void via_init_command_verifier(void)
{
setup_hazard_table(init_table1, table1,
sizeof(init_table1) / sizeof(hz_init_t));
setup_hazard_table(init_table2, table2,
sizeof(init_table2) / sizeof(hz_init_t));
setup_hazard_table(init_table3, table3,
sizeof(init_table3) / sizeof(hz_init_t));
}
