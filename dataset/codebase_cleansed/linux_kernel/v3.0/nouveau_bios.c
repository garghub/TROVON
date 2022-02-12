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
static int
score_vbios(struct drm_device *dev, const uint8_t *data, const bool writeable)
{
if (!(data[0] == 0x55 && data[1] == 0xAA)) {
NV_TRACEWARN(dev, "... BIOS signature not found\n");
return 0;
}
if (nv_cksum(data, data[2] * 512)) {
NV_TRACEWARN(dev, "... BIOS checksum invalid\n");
return writeable ? 2 : 1;
} else
NV_TRACE(dev, "... appears to be valid\n");
return 3;
}
static void load_vbios_prom(struct drm_device *dev, uint8_t *data)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
uint32_t pci_nv_20, save_pci_nv_20;
int pcir_ptr;
int i;
if (dev_priv->card_type >= NV_50)
pci_nv_20 = 0x88050;
else
pci_nv_20 = NV_PBUS_PCI_NV_20;
save_pci_nv_20 = nvReadMC(dev, pci_nv_20);
nvWriteMC(dev, pci_nv_20,
save_pci_nv_20 & ~NV_PBUS_PCI_NV_20_ROM_SHADOW_ENABLED);
if (nv_rd08(dev, NV_PROM_OFFSET) != 0x55 ||
nv_rd08(dev, NV_PROM_OFFSET + 1) != 0xaa)
goto out;
pcir_ptr = nv_rd08(dev, NV_PROM_OFFSET + 0x18) |
nv_rd08(dev, NV_PROM_OFFSET + 0x19) << 8;
if (nv_rd08(dev, NV_PROM_OFFSET + pcir_ptr) != 'P' ||
nv_rd08(dev, NV_PROM_OFFSET + pcir_ptr + 1) != 'C' ||
nv_rd08(dev, NV_PROM_OFFSET + pcir_ptr + 2) != 'I' ||
nv_rd08(dev, NV_PROM_OFFSET + pcir_ptr + 3) != 'R')
goto out;
for (i = 0; i < NV_PROM_SIZE; i++)
data[i] = nv_rd08(dev, NV_PROM_OFFSET + i);
out:
nvWriteMC(dev, pci_nv_20,
save_pci_nv_20 | NV_PBUS_PCI_NV_20_ROM_SHADOW_ENABLED);
}
static void load_vbios_pramin(struct drm_device *dev, uint8_t *data)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
uint32_t old_bar0_pramin = 0;
int i;
if (dev_priv->card_type >= NV_50) {
uint32_t vbios_vram = (nv_rd32(dev, 0x619f04) & ~0xff) << 8;
if (!vbios_vram)
vbios_vram = (nv_rd32(dev, 0x1700) << 16) + 0xf0000;
old_bar0_pramin = nv_rd32(dev, 0x1700);
nv_wr32(dev, 0x1700, vbios_vram >> 16);
}
if (nv_rd08(dev, NV_PRAMIN_OFFSET) != 0x55 ||
nv_rd08(dev, NV_PRAMIN_OFFSET + 1) != 0xaa)
goto out;
for (i = 0; i < NV_PROM_SIZE; i++)
data[i] = nv_rd08(dev, NV_PRAMIN_OFFSET + i);
out:
if (dev_priv->card_type >= NV_50)
nv_wr32(dev, 0x1700, old_bar0_pramin);
}
static void load_vbios_pci(struct drm_device *dev, uint8_t *data)
{
void __iomem *rom = NULL;
size_t rom_len;
int ret;
ret = pci_enable_rom(dev->pdev);
if (ret)
return;
rom = pci_map_rom(dev->pdev, &rom_len);
if (!rom)
goto out;
memcpy_fromio(data, rom, rom_len);
pci_unmap_rom(dev->pdev, rom);
out:
pci_disable_rom(dev->pdev);
}
static void load_vbios_acpi(struct drm_device *dev, uint8_t *data)
{
int i;
int ret;
int size = 64 * 1024;
if (!nouveau_acpi_rom_supported(dev->pdev))
return;
for (i = 0; i < (size / ROM_BIOS_PAGE); i++) {
ret = nouveau_acpi_get_bios_chunk(data,
(i * ROM_BIOS_PAGE),
ROM_BIOS_PAGE);
if (ret <= 0)
break;
}
return;
}
static bool NVShadowVBIOS(struct drm_device *dev, uint8_t *data)
{
struct methods *methods = shadow_methods;
int testscore = 3;
int scores[NUM_SHADOW_METHODS], i;
if (nouveau_vbios) {
for (i = 0; i < NUM_SHADOW_METHODS; i++)
if (!strcasecmp(nouveau_vbios, methods[i].desc))
break;
if (i < NUM_SHADOW_METHODS) {
NV_INFO(dev, "Attempting to use BIOS image from %s\n",
methods[i].desc);
methods[i].loadbios(dev, data);
if (score_vbios(dev, data, methods[i].rw))
return true;
}
NV_ERROR(dev, "VBIOS source \'%s\' invalid\n", nouveau_vbios);
}
for (i = 0; i < NUM_SHADOW_METHODS; i++) {
NV_TRACE(dev, "Attempting to load BIOS image from %s\n",
methods[i].desc);
data[0] = data[1] = 0;
methods[i].loadbios(dev, data);
scores[i] = score_vbios(dev, data, methods[i].rw);
if (scores[i] == testscore)
return true;
}
while (--testscore > 0) {
for (i = 0; i < NUM_SHADOW_METHODS; i++) {
if (scores[i] == testscore) {
NV_TRACE(dev, "Using BIOS image from %s\n",
methods[i].desc);
methods[i].loadbios(dev, data);
return true;
}
}
}
NV_ERROR(dev, "No valid BIOS image found\n");
return false;
}
static void still_alive(void)
{
#if 0
sync();
mdelay(2);
#endif
}
static uint32_t
munge_reg(struct nvbios *bios, uint32_t reg)
{
struct drm_nouveau_private *dev_priv = bios->dev->dev_private;
struct dcb_entry *dcbent = bios->display.output;
if (dev_priv->card_type < NV_50)
return reg;
if (reg & 0x40000000) {
BUG_ON(!dcbent);
reg += (ffs(dcbent->or) - 1) * 0x800;
if ((reg & 0x20000000) && !(dcbent->sorconf.link & 1))
reg += 0x00000080;
}
reg &= ~0x60000000;
return reg;
}
static int
valid_reg(struct nvbios *bios, uint32_t reg)
{
struct drm_nouveau_private *dev_priv = bios->dev->dev_private;
struct drm_device *dev = bios->dev;
if (reg & 0x2 ||
(reg & 0x1 && dev_priv->vbios.chip_version != 0x51))
NV_ERROR(dev, "======= misaligned reg 0x%08X =======\n", reg);
if (reg & 0x1 && dev_priv->vbios.chip_version == 0x51 &&
reg != 0x130d && reg != 0x1311 && reg != 0x60081d)
NV_WARN(dev, "=== C51 misaligned reg 0x%08X not verified ===\n",
reg);
if (reg >= (8*1024*1024)) {
NV_ERROR(dev, "=== reg 0x%08x out of mapped bounds ===\n", reg);
return 0;
}
return 1;
}
static bool
valid_idx_port(struct nvbios *bios, uint16_t port)
{
struct drm_nouveau_private *dev_priv = bios->dev->dev_private;
struct drm_device *dev = bios->dev;
if (dev_priv->card_type < NV_50) {
if (port == NV_CIO_CRX__COLOR)
return true;
if (port == NV_VIO_SRX)
return true;
} else {
if (port == NV_CIO_CRX__COLOR)
return true;
}
NV_ERROR(dev, "========== unknown indexed io port 0x%04X ==========\n",
port);
return false;
}
static bool
valid_port(struct nvbios *bios, uint16_t port)
{
struct drm_device *dev = bios->dev;
if (port == NV_VIO_VSE2)
return true;
NV_ERROR(dev, "========== unknown io port 0x%04X ==========\n", port);
return false;
}
static uint32_t
bios_rd32(struct nvbios *bios, uint32_t reg)
{
uint32_t data;
reg = munge_reg(bios, reg);
if (!valid_reg(bios, reg))
return 0;
if (reg & 0x1)
reg &= ~0x1;
data = nv_rd32(bios->dev, reg);
BIOSLOG(bios, " Read: Reg: 0x%08X, Data: 0x%08X\n", reg, data);
return data;
}
static void
bios_wr32(struct nvbios *bios, uint32_t reg, uint32_t data)
{
struct drm_nouveau_private *dev_priv = bios->dev->dev_private;
reg = munge_reg(bios, reg);
if (!valid_reg(bios, reg))
return;
if (reg & 0x1)
reg &= 0xfffffffe;
LOG_OLD_VALUE(bios_rd32(bios, reg));
BIOSLOG(bios, " Write: Reg: 0x%08X, Data: 0x%08X\n", reg, data);
if (dev_priv->vbios.execute) {
still_alive();
nv_wr32(bios->dev, reg, data);
}
}
static uint8_t
bios_idxprt_rd(struct nvbios *bios, uint16_t port, uint8_t index)
{
struct drm_nouveau_private *dev_priv = bios->dev->dev_private;
struct drm_device *dev = bios->dev;
uint8_t data;
if (!valid_idx_port(bios, port))
return 0;
if (dev_priv->card_type < NV_50) {
if (port == NV_VIO_SRX)
data = NVReadVgaSeq(dev, bios->state.crtchead, index);
else
data = NVReadVgaCrtc(dev, bios->state.crtchead, index);
} else {
uint32_t data32;
data32 = bios_rd32(bios, NV50_PDISPLAY_VGACRTC(index & ~3));
data = (data32 >> ((index & 3) << 3)) & 0xff;
}
BIOSLOG(bios, " Indexed IO read: Port: 0x%04X, Index: 0x%02X, "
"Head: 0x%02X, Data: 0x%02X\n",
port, index, bios->state.crtchead, data);
return data;
}
static void
bios_idxprt_wr(struct nvbios *bios, uint16_t port, uint8_t index, uint8_t data)
{
struct drm_nouveau_private *dev_priv = bios->dev->dev_private;
struct drm_device *dev = bios->dev;
if (!valid_idx_port(bios, port))
return;
if (port == NV_CIO_CRX__COLOR && index == NV_CIO_CRE_44 &&
data != NV_CIO_CRE_44_HEADB)
bios->state.crtchead = 0;
LOG_OLD_VALUE(bios_idxprt_rd(bios, port, index));
BIOSLOG(bios, " Indexed IO write: Port: 0x%04X, Index: 0x%02X, "
"Head: 0x%02X, Data: 0x%02X\n",
port, index, bios->state.crtchead, data);
if (bios->execute && dev_priv->card_type < NV_50) {
still_alive();
if (port == NV_VIO_SRX)
NVWriteVgaSeq(dev, bios->state.crtchead, index, data);
else
NVWriteVgaCrtc(dev, bios->state.crtchead, index, data);
} else
if (bios->execute) {
uint32_t data32, shift = (index & 3) << 3;
still_alive();
data32 = bios_rd32(bios, NV50_PDISPLAY_VGACRTC(index & ~3));
data32 &= ~(0xff << shift);
data32 |= (data << shift);
bios_wr32(bios, NV50_PDISPLAY_VGACRTC(index & ~3), data32);
}
if (port == NV_CIO_CRX__COLOR &&
index == NV_CIO_CRE_44 && data == NV_CIO_CRE_44_HEADB)
bios->state.crtchead = 1;
}
static uint8_t
bios_port_rd(struct nvbios *bios, uint16_t port)
{
uint8_t data, head = bios->state.crtchead;
if (!valid_port(bios, port))
return 0;
data = NVReadPRMVIO(bios->dev, head, NV_PRMVIO0_OFFSET + port);
BIOSLOG(bios, " IO read: Port: 0x%04X, Head: 0x%02X, Data: 0x%02X\n",
port, head, data);
return data;
}
static void
bios_port_wr(struct nvbios *bios, uint16_t port, uint8_t data)
{
int head = bios->state.crtchead;
if (!valid_port(bios, port))
return;
LOG_OLD_VALUE(bios_port_rd(bios, port));
BIOSLOG(bios, " IO write: Port: 0x%04X, Head: 0x%02X, Data: 0x%02X\n",
port, head, data);
if (!bios->execute)
return;
still_alive();
NVWritePRMVIO(bios->dev, head, NV_PRMVIO0_OFFSET + port, data);
}
static bool
io_flag_condition_met(struct nvbios *bios, uint16_t offset, uint8_t cond)
{
uint16_t condptr = bios->io_flag_condition_tbl_ptr + cond * IO_FLAG_CONDITION_SIZE;
uint16_t crtcport = ROM16(bios->data[condptr]);
uint8_t crtcindex = bios->data[condptr + 2];
uint8_t mask = bios->data[condptr + 3];
uint8_t shift = bios->data[condptr + 4];
uint16_t flagarray = ROM16(bios->data[condptr + 5]);
uint8_t flagarraymask = bios->data[condptr + 7];
uint8_t cmpval = bios->data[condptr + 8];
uint8_t data;
BIOSLOG(bios, "0x%04X: Port: 0x%04X, Index: 0x%02X, Mask: 0x%02X, "
"Shift: 0x%02X, FlagArray: 0x%04X, FAMask: 0x%02X, "
"Cmpval: 0x%02X\n",
offset, crtcport, crtcindex, mask, shift, flagarray, flagarraymask, cmpval);
data = bios_idxprt_rd(bios, crtcport, crtcindex);
data = bios->data[flagarray + ((data & mask) >> shift)];
data &= flagarraymask;
BIOSLOG(bios, "0x%04X: Checking if 0x%02X equals 0x%02X\n",
offset, data, cmpval);
return (data == cmpval);
}
static bool
bios_condition_met(struct nvbios *bios, uint16_t offset, uint8_t cond)
{
uint16_t condptr = bios->condition_tbl_ptr + cond * CONDITION_SIZE;
uint32_t reg = ROM32(bios->data[condptr]);
uint32_t mask = ROM32(bios->data[condptr + 4]);
uint32_t cmpval = ROM32(bios->data[condptr + 8]);
uint32_t data;
BIOSLOG(bios, "0x%04X: Cond: 0x%02X, Reg: 0x%08X, Mask: 0x%08X\n",
offset, cond, reg, mask);
data = bios_rd32(bios, reg) & mask;
BIOSLOG(bios, "0x%04X: Checking if 0x%08X equals 0x%08X\n",
offset, data, cmpval);
return (data == cmpval);
}
static bool
io_condition_met(struct nvbios *bios, uint16_t offset, uint8_t cond)
{
uint16_t condptr = bios->io_condition_tbl_ptr + cond * IO_CONDITION_SIZE;
uint16_t io_port = ROM16(bios->data[condptr]);
uint8_t port_index = bios->data[condptr + 2];
uint8_t mask = bios->data[condptr + 3];
uint8_t cmpval = bios->data[condptr + 4];
uint8_t data = bios_idxprt_rd(bios, io_port, port_index) & mask;
BIOSLOG(bios, "0x%04X: Checking if 0x%02X equals 0x%02X\n",
offset, data, cmpval);
return (data == cmpval);
}
static int
nv50_pll_set(struct drm_device *dev, uint32_t reg, uint32_t clk)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
uint32_t reg0 = nv_rd32(dev, reg + 0);
uint32_t reg1 = nv_rd32(dev, reg + 4);
struct nouveau_pll_vals pll;
struct pll_lims pll_limits;
int ret;
ret = get_pll_limits(dev, reg, &pll_limits);
if (ret)
return ret;
clk = nouveau_calc_pll_mnp(dev, &pll_limits, clk, &pll);
if (!clk)
return -ERANGE;
reg0 = (reg0 & 0xfff8ffff) | (pll.log2P << 16);
reg1 = (reg1 & 0xffff0000) | (pll.N1 << 8) | pll.M1;
if (dev_priv->vbios.execute) {
still_alive();
nv_wr32(dev, reg + 4, reg1);
nv_wr32(dev, reg + 0, reg0);
}
return 0;
}
static int
setPLL(struct nvbios *bios, uint32_t reg, uint32_t clk)
{
struct drm_device *dev = bios->dev;
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct pll_lims pll_lim;
struct nouveau_pll_vals pllvals;
int ret;
if (dev_priv->card_type >= NV_50)
return nv50_pll_set(dev, reg, clk);
ret = get_pll_limits(dev, reg > 0x405c ? reg : reg - 4, &pll_lim);
if (ret)
return ret;
clk = nouveau_calc_pll_mnp(dev, &pll_lim, clk, &pllvals);
if (!clk)
return -ERANGE;
if (bios->execute) {
still_alive();
nouveau_hw_setpll(dev, reg, &pllvals);
}
return 0;
}
static int dcb_entry_idx_from_crtchead(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
uint8_t dcb_entry = NVReadVgaCrtc5758(dev, bios->state.crtchead, 0);
if (dcb_entry > bios->dcb.entries) {
NV_ERROR(dev, "CR58 doesn't have a valid DCB entry currently "
"(%02X)\n", dcb_entry);
dcb_entry = 0x7f;
}
return dcb_entry;
}
static int
read_dcb_i2c_entry(struct drm_device *dev, int dcb_version, uint8_t *i2ctable, int index, struct dcb_i2c_entry *i2c)
{
uint8_t dcb_i2c_ver = dcb_version, headerlen = 0, entry_len = 4;
int i2c_entries = DCB_MAX_NUM_I2C_ENTRIES;
int recordoffset = 0, rdofs = 1, wrofs = 0;
uint8_t port_type = 0;
if (!i2ctable)
return -EINVAL;
if (dcb_version >= 0x30) {
if (i2ctable[0] != dcb_version)
NV_WARN(dev,
"DCB I2C table version mismatch (%02X vs %02X)\n",
i2ctable[0], dcb_version);
dcb_i2c_ver = i2ctable[0];
headerlen = i2ctable[1];
if (i2ctable[2] <= DCB_MAX_NUM_I2C_ENTRIES)
i2c_entries = i2ctable[2];
else
NV_WARN(dev,
"DCB I2C table has more entries than indexable "
"(%d entries, max %d)\n", i2ctable[2],
DCB_MAX_NUM_I2C_ENTRIES);
entry_len = i2ctable[3];
}
if (dcb_version < 0x14) {
recordoffset = 2;
rdofs = 0;
wrofs = 1;
}
if (index == 0xf)
return 0;
if (index >= i2c_entries) {
NV_ERROR(dev, "DCB I2C index too big (%d >= %d)\n",
index, i2ctable[2]);
return -ENOENT;
}
if (i2ctable[headerlen + entry_len * index + 3] == 0xff) {
NV_ERROR(dev, "DCB I2C entry invalid\n");
return -EINVAL;
}
if (dcb_i2c_ver >= 0x30) {
port_type = i2ctable[headerlen + recordoffset + 3 + entry_len * index];
if (port_type == 4)
rdofs = wrofs = 1;
if (port_type >= 5)
rdofs = wrofs = 0;
}
if (dcb_i2c_ver >= 0x40) {
if (port_type != 5 && port_type != 6)
NV_WARN(dev, "DCB I2C table has port type %d\n", port_type);
i2c->entry = ROM32(i2ctable[headerlen + recordoffset + entry_len * index]);
}
i2c->port_type = port_type;
i2c->read = i2ctable[headerlen + recordoffset + rdofs + entry_len * index];
i2c->write = i2ctable[headerlen + recordoffset + wrofs + entry_len * index];
return 0;
}
static struct nouveau_i2c_chan *
init_i2c_device_find(struct drm_device *dev, int i2c_index)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct dcb_table *dcb = &dev_priv->vbios.dcb;
if (i2c_index == 0xff) {
int idx = dcb_entry_idx_from_crtchead(dev), shift = 0;
int default_indices = dcb->i2c_default_indices;
if (idx != 0x7f && dcb->entry[idx].i2c_upper_default)
shift = 4;
i2c_index = (default_indices >> shift) & 0xf;
}
if (i2c_index == 0x80)
i2c_index = dcb->i2c_default_indices & 0xf;
else
if (i2c_index == 0x81)
i2c_index = (dcb->i2c_default_indices & 0xf0) >> 4;
if (i2c_index >= DCB_MAX_NUM_I2C_ENTRIES) {
NV_ERROR(dev, "invalid i2c_index 0x%x\n", i2c_index);
return NULL;
}
read_dcb_i2c_entry(dev, dcb->version, dcb->i2c_table,
i2c_index, &dcb->i2c[i2c_index]);
return nouveau_i2c_find(dev, i2c_index);
}
static uint32_t
get_tmds_index_reg(struct drm_device *dev, uint8_t mlv)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
const int pramdac_offset[13] = {
0, 0, 0x8, 0, 0x2000, 0, 0, 0, 0x2008, 0, 0, 0, 0x2000 };
const uint32_t pramdac_table[4] = {
0x6808b0, 0x6808b8, 0x6828b0, 0x6828b8 };
if (mlv >= 0x80) {
int dcb_entry, dacoffset;
dcb_entry = dcb_entry_idx_from_crtchead(dev);
if (dcb_entry == 0x7f)
return 0;
dacoffset = pramdac_offset[bios->dcb.entry[dcb_entry].or];
if (mlv == 0x81)
dacoffset ^= 8;
return 0x6808b0 + dacoffset;
} else {
if (mlv >= ARRAY_SIZE(pramdac_table)) {
NV_ERROR(dev, "Magic Lookup Value too big (%02X)\n",
mlv);
return 0;
}
return pramdac_table[mlv];
}
}
static int
init_io_restrict_prog(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint16_t crtcport = ROM16(bios->data[offset + 1]);
uint8_t crtcindex = bios->data[offset + 3];
uint8_t mask = bios->data[offset + 4];
uint8_t shift = bios->data[offset + 5];
uint8_t count = bios->data[offset + 6];
uint32_t reg = ROM32(bios->data[offset + 7]);
uint8_t config;
uint32_t configval;
int len = 11 + count * 4;
if (!iexec->execute)
return len;
BIOSLOG(bios, "0x%04X: Port: 0x%04X, Index: 0x%02X, Mask: 0x%02X, "
"Shift: 0x%02X, Count: 0x%02X, Reg: 0x%08X\n",
offset, crtcport, crtcindex, mask, shift, count, reg);
config = (bios_idxprt_rd(bios, crtcport, crtcindex) & mask) >> shift;
if (config > count) {
NV_ERROR(bios->dev,
"0x%04X: Config 0x%02X exceeds maximal bound 0x%02X\n",
offset, config, count);
return len;
}
configval = ROM32(bios->data[offset + 11 + config * 4]);
BIOSLOG(bios, "0x%04X: Writing config %02X\n", offset, config);
bios_wr32(bios, reg, configval);
return len;
}
static int
init_repeat(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint8_t count = bios->data[offset + 1];
uint8_t i;
BIOSLOG(bios, "0x%04X: Repeating following segment %d times\n",
offset, count);
iexec->repeat = true;
for (i = 0; i < count - 1; i++)
parse_init_table(bios, offset + 2, iexec);
iexec->repeat = false;
return 2;
}
static int
init_io_restrict_pll(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint16_t crtcport = ROM16(bios->data[offset + 1]);
uint8_t crtcindex = bios->data[offset + 3];
uint8_t mask = bios->data[offset + 4];
uint8_t shift = bios->data[offset + 5];
int8_t io_flag_condition_idx = bios->data[offset + 6];
uint8_t count = bios->data[offset + 7];
uint32_t reg = ROM32(bios->data[offset + 8]);
uint8_t config;
uint16_t freq;
int len = 12 + count * 2;
if (!iexec->execute)
return len;
BIOSLOG(bios, "0x%04X: Port: 0x%04X, Index: 0x%02X, Mask: 0x%02X, "
"Shift: 0x%02X, IO Flag Condition: 0x%02X, "
"Count: 0x%02X, Reg: 0x%08X\n",
offset, crtcport, crtcindex, mask, shift,
io_flag_condition_idx, count, reg);
config = (bios_idxprt_rd(bios, crtcport, crtcindex) & mask) >> shift;
if (config > count) {
NV_ERROR(bios->dev,
"0x%04X: Config 0x%02X exceeds maximal bound 0x%02X\n",
offset, config, count);
return len;
}
freq = ROM16(bios->data[offset + 12 + config * 2]);
if (io_flag_condition_idx > 0) {
if (io_flag_condition_met(bios, offset, io_flag_condition_idx)) {
BIOSLOG(bios, "0x%04X: Condition fulfilled -- "
"frequency doubled\n", offset);
freq *= 2;
} else
BIOSLOG(bios, "0x%04X: Condition not fulfilled -- "
"frequency unchanged\n", offset);
}
BIOSLOG(bios, "0x%04X: Reg: 0x%08X, Config: 0x%02X, Freq: %d0kHz\n",
offset, reg, config, freq);
setPLL(bios, reg, freq * 10);
return len;
}
static int
init_end_repeat(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
if (iexec->repeat)
return 0;
return 1;
}
static int
init_copy(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint32_t reg = ROM32(bios->data[offset + 1]);
uint8_t shift = bios->data[offset + 5];
uint8_t srcmask = bios->data[offset + 6];
uint16_t crtcport = ROM16(bios->data[offset + 7]);
uint8_t crtcindex = bios->data[offset + 9];
uint8_t mask = bios->data[offset + 10];
uint32_t data;
uint8_t crtcdata;
if (!iexec->execute)
return 11;
BIOSLOG(bios, "0x%04X: Reg: 0x%08X, Shift: 0x%02X, SrcMask: 0x%02X, "
"Port: 0x%04X, Index: 0x%02X, Mask: 0x%02X\n",
offset, reg, shift, srcmask, crtcport, crtcindex, mask);
data = bios_rd32(bios, reg);
if (shift < 0x80)
data >>= shift;
else
data <<= (0x100 - shift);
data &= srcmask;
crtcdata = bios_idxprt_rd(bios, crtcport, crtcindex) & mask;
crtcdata |= (uint8_t)data;
bios_idxprt_wr(bios, crtcport, crtcindex, crtcdata);
return 11;
}
static int
init_not(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
if (iexec->execute)
BIOSLOG(bios, "0x%04X: ------ Skipping following commands ------\n", offset);
else
BIOSLOG(bios, "0x%04X: ------ Executing following commands ------\n", offset);
iexec->execute = !iexec->execute;
return 1;
}
static int
init_io_flag_condition(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint8_t cond = bios->data[offset + 1];
if (!iexec->execute)
return 2;
if (io_flag_condition_met(bios, offset, cond))
BIOSLOG(bios, "0x%04X: Condition fulfilled -- continuing to execute\n", offset);
else {
BIOSLOG(bios, "0x%04X: Condition not fulfilled -- skipping following commands\n", offset);
iexec->execute = false;
}
return 2;
}
static int
init_dp_condition(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
struct bit_displayport_encoder_table *dpe = NULL;
struct dcb_entry *dcb = bios->display.output;
struct drm_device *dev = bios->dev;
uint8_t cond = bios->data[offset + 1];
int dummy;
BIOSLOG(bios, "0x%04X: subop 0x%02X\n", offset, cond);
if (!iexec->execute)
return 3;
dpe = nouveau_bios_dp_table(dev, dcb, &dummy);
if (!dpe) {
NV_ERROR(dev, "0x%04X: INIT_3A: no encoder table!!\n", offset);
return 3;
}
switch (cond) {
case 0:
{
struct dcb_connector_table_entry *ent =
&bios->dcb.connector.entry[dcb->connector];
if (ent->type != DCB_CONNECTOR_eDP)
iexec->execute = false;
}
break;
case 1:
case 2:
if (!(dpe->unknown & cond))
iexec->execute = false;
break;
case 5:
{
struct nouveau_i2c_chan *auxch;
int ret;
auxch = nouveau_i2c_find(dev, bios->display.output->i2c_index);
if (!auxch) {
NV_ERROR(dev, "0x%04X: couldn't get auxch\n", offset);
return 3;
}
ret = nouveau_dp_auxch(auxch, 9, 0xd, &cond, 1);
if (ret) {
NV_ERROR(dev, "0x%04X: auxch rd fail: %d\n", offset, ret);
return 3;
}
if (!(cond & 1))
iexec->execute = false;
}
break;
default:
NV_WARN(dev, "0x%04X: unknown INIT_3A op: %d\n", offset, cond);
break;
}
if (iexec->execute)
BIOSLOG(bios, "0x%04X: continuing to execute\n", offset);
else
BIOSLOG(bios, "0x%04X: skipping following commands\n", offset);
return 3;
}
static int
init_op_3b(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint8_t or = ffs(bios->display.output->or) - 1;
uint8_t index = bios->data[offset + 1];
uint8_t data;
if (!iexec->execute)
return 2;
data = bios_idxprt_rd(bios, 0x3d4, index);
bios_idxprt_wr(bios, 0x3d4, index, data & ~(1 << or));
return 2;
}
static int
init_op_3c(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint8_t or = ffs(bios->display.output->or) - 1;
uint8_t index = bios->data[offset + 1];
uint8_t data;
if (!iexec->execute)
return 2;
data = bios_idxprt_rd(bios, 0x3d4, index);
bios_idxprt_wr(bios, 0x3d4, index, data | (1 << or));
return 2;
}
static int
init_idx_addr_latched(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint32_t controlreg = ROM32(bios->data[offset + 1]);
uint32_t datareg = ROM32(bios->data[offset + 5]);
uint32_t mask = ROM32(bios->data[offset + 9]);
uint32_t data = ROM32(bios->data[offset + 13]);
uint8_t count = bios->data[offset + 17];
int len = 18 + count * 2;
uint32_t value;
int i;
if (!iexec->execute)
return len;
BIOSLOG(bios, "0x%04X: ControlReg: 0x%08X, DataReg: 0x%08X, "
"Mask: 0x%08X, Data: 0x%08X, Count: 0x%02X\n",
offset, controlreg, datareg, mask, data, count);
for (i = 0; i < count; i++) {
uint8_t instaddress = bios->data[offset + 18 + i * 2];
uint8_t instdata = bios->data[offset + 19 + i * 2];
BIOSLOG(bios, "0x%04X: Address: 0x%02X, Data: 0x%02X\n",
offset, instaddress, instdata);
bios_wr32(bios, datareg, instdata);
value = bios_rd32(bios, controlreg) & mask;
value |= data;
value |= instaddress;
bios_wr32(bios, controlreg, value);
}
return len;
}
static int
init_io_restrict_pll2(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint16_t crtcport = ROM16(bios->data[offset + 1]);
uint8_t crtcindex = bios->data[offset + 3];
uint8_t mask = bios->data[offset + 4];
uint8_t shift = bios->data[offset + 5];
uint8_t count = bios->data[offset + 6];
uint32_t reg = ROM32(bios->data[offset + 7]);
int len = 11 + count * 4;
uint8_t config;
uint32_t freq;
if (!iexec->execute)
return len;
BIOSLOG(bios, "0x%04X: Port: 0x%04X, Index: 0x%02X, Mask: 0x%02X, "
"Shift: 0x%02X, Count: 0x%02X, Reg: 0x%08X\n",
offset, crtcport, crtcindex, mask, shift, count, reg);
if (!reg)
return len;
config = (bios_idxprt_rd(bios, crtcport, crtcindex) & mask) >> shift;
if (config > count) {
NV_ERROR(bios->dev,
"0x%04X: Config 0x%02X exceeds maximal bound 0x%02X\n",
offset, config, count);
return len;
}
freq = ROM32(bios->data[offset + 11 + config * 4]);
BIOSLOG(bios, "0x%04X: Reg: 0x%08X, Config: 0x%02X, Freq: %dkHz\n",
offset, reg, config, freq);
setPLL(bios, reg, freq);
return len;
}
static int
init_pll2(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint32_t reg = ROM32(bios->data[offset + 1]);
uint32_t freq = ROM32(bios->data[offset + 5]);
if (!iexec->execute)
return 9;
BIOSLOG(bios, "0x%04X: Reg: 0x%04X, Freq: %dkHz\n",
offset, reg, freq);
setPLL(bios, reg, freq);
return 9;
}
static int
init_i2c_byte(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
struct drm_device *dev = bios->dev;
uint8_t i2c_index = bios->data[offset + 1];
uint8_t i2c_address = bios->data[offset + 2] >> 1;
uint8_t count = bios->data[offset + 3];
struct nouveau_i2c_chan *chan;
int len = 4 + count * 3;
int ret, i;
if (!iexec->execute)
return len;
BIOSLOG(bios, "0x%04X: DCBI2CIndex: 0x%02X, I2CAddress: 0x%02X, "
"Count: 0x%02X\n",
offset, i2c_index, i2c_address, count);
chan = init_i2c_device_find(dev, i2c_index);
if (!chan) {
NV_ERROR(dev, "0x%04X: i2c bus not found\n", offset);
return len;
}
for (i = 0; i < count; i++) {
uint8_t reg = bios->data[offset + 4 + i * 3];
uint8_t mask = bios->data[offset + 5 + i * 3];
uint8_t data = bios->data[offset + 6 + i * 3];
union i2c_smbus_data val;
ret = i2c_smbus_xfer(&chan->adapter, i2c_address, 0,
I2C_SMBUS_READ, reg,
I2C_SMBUS_BYTE_DATA, &val);
if (ret < 0) {
NV_ERROR(dev, "0x%04X: i2c rd fail: %d\n", offset, ret);
return len;
}
BIOSLOG(bios, "0x%04X: I2CReg: 0x%02X, Value: 0x%02X, "
"Mask: 0x%02X, Data: 0x%02X\n",
offset, reg, val.byte, mask, data);
if (!bios->execute)
continue;
val.byte &= mask;
val.byte |= data;
ret = i2c_smbus_xfer(&chan->adapter, i2c_address, 0,
I2C_SMBUS_WRITE, reg,
I2C_SMBUS_BYTE_DATA, &val);
if (ret < 0) {
NV_ERROR(dev, "0x%04X: i2c wr fail: %d\n", offset, ret);
return len;
}
}
return len;
}
static int
init_zm_i2c_byte(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
struct drm_device *dev = bios->dev;
uint8_t i2c_index = bios->data[offset + 1];
uint8_t i2c_address = bios->data[offset + 2] >> 1;
uint8_t count = bios->data[offset + 3];
struct nouveau_i2c_chan *chan;
int len = 4 + count * 2;
int ret, i;
if (!iexec->execute)
return len;
BIOSLOG(bios, "0x%04X: DCBI2CIndex: 0x%02X, I2CAddress: 0x%02X, "
"Count: 0x%02X\n",
offset, i2c_index, i2c_address, count);
chan = init_i2c_device_find(dev, i2c_index);
if (!chan) {
NV_ERROR(dev, "0x%04X: i2c bus not found\n", offset);
return len;
}
for (i = 0; i < count; i++) {
uint8_t reg = bios->data[offset + 4 + i * 2];
union i2c_smbus_data val;
val.byte = bios->data[offset + 5 + i * 2];
BIOSLOG(bios, "0x%04X: I2CReg: 0x%02X, Data: 0x%02X\n",
offset, reg, val.byte);
if (!bios->execute)
continue;
ret = i2c_smbus_xfer(&chan->adapter, i2c_address, 0,
I2C_SMBUS_WRITE, reg,
I2C_SMBUS_BYTE_DATA, &val);
if (ret < 0) {
NV_ERROR(dev, "0x%04X: i2c wr fail: %d\n", offset, ret);
return len;
}
}
return len;
}
static int
init_zm_i2c(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
struct drm_device *dev = bios->dev;
uint8_t i2c_index = bios->data[offset + 1];
uint8_t i2c_address = bios->data[offset + 2] >> 1;
uint8_t count = bios->data[offset + 3];
int len = 4 + count;
struct nouveau_i2c_chan *chan;
struct i2c_msg msg;
uint8_t data[256];
int ret, i;
if (!iexec->execute)
return len;
BIOSLOG(bios, "0x%04X: DCBI2CIndex: 0x%02X, I2CAddress: 0x%02X, "
"Count: 0x%02X\n",
offset, i2c_index, i2c_address, count);
chan = init_i2c_device_find(dev, i2c_index);
if (!chan) {
NV_ERROR(dev, "0x%04X: i2c bus not found\n", offset);
return len;
}
for (i = 0; i < count; i++) {
data[i] = bios->data[offset + 4 + i];
BIOSLOG(bios, "0x%04X: Data: 0x%02X\n", offset, data[i]);
}
if (bios->execute) {
msg.addr = i2c_address;
msg.flags = 0;
msg.len = count;
msg.buf = data;
ret = i2c_transfer(&chan->adapter, &msg, 1);
if (ret != 1) {
NV_ERROR(dev, "0x%04X: i2c wr fail: %d\n", offset, ret);
return len;
}
}
return len;
}
static int
init_tmds(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
struct drm_device *dev = bios->dev;
uint8_t mlv = bios->data[offset + 1];
uint32_t tmdsaddr = bios->data[offset + 2];
uint8_t mask = bios->data[offset + 3];
uint8_t data = bios->data[offset + 4];
uint32_t reg, value;
if (!iexec->execute)
return 5;
BIOSLOG(bios, "0x%04X: MagicLookupValue: 0x%02X, TMDSAddr: 0x%02X, "
"Mask: 0x%02X, Data: 0x%02X\n",
offset, mlv, tmdsaddr, mask, data);
reg = get_tmds_index_reg(bios->dev, mlv);
if (!reg) {
NV_ERROR(dev, "0x%04X: no tmds_index_reg\n", offset);
return 5;
}
bios_wr32(bios, reg,
tmdsaddr | NV_PRAMDAC_FP_TMDS_CONTROL_WRITE_DISABLE);
value = (bios_rd32(bios, reg + 4) & mask) | data;
bios_wr32(bios, reg + 4, value);
bios_wr32(bios, reg, tmdsaddr);
return 5;
}
static int
init_zm_tmds_group(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
struct drm_device *dev = bios->dev;
uint8_t mlv = bios->data[offset + 1];
uint8_t count = bios->data[offset + 2];
int len = 3 + count * 2;
uint32_t reg;
int i;
if (!iexec->execute)
return len;
BIOSLOG(bios, "0x%04X: MagicLookupValue: 0x%02X, Count: 0x%02X\n",
offset, mlv, count);
reg = get_tmds_index_reg(bios->dev, mlv);
if (!reg) {
NV_ERROR(dev, "0x%04X: no tmds_index_reg\n", offset);
return len;
}
for (i = 0; i < count; i++) {
uint8_t tmdsaddr = bios->data[offset + 3 + i * 2];
uint8_t tmdsdata = bios->data[offset + 4 + i * 2];
bios_wr32(bios, reg + 4, tmdsdata);
bios_wr32(bios, reg, tmdsaddr);
}
return len;
}
static int
init_cr_idx_adr_latch(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint8_t crtcindex1 = bios->data[offset + 1];
uint8_t crtcindex2 = bios->data[offset + 2];
uint8_t baseaddr = bios->data[offset + 3];
uint8_t count = bios->data[offset + 4];
int len = 5 + count;
uint8_t oldaddr, data;
int i;
if (!iexec->execute)
return len;
BIOSLOG(bios, "0x%04X: Index1: 0x%02X, Index2: 0x%02X, "
"BaseAddr: 0x%02X, Count: 0x%02X\n",
offset, crtcindex1, crtcindex2, baseaddr, count);
oldaddr = bios_idxprt_rd(bios, NV_CIO_CRX__COLOR, crtcindex1);
for (i = 0; i < count; i++) {
bios_idxprt_wr(bios, NV_CIO_CRX__COLOR, crtcindex1,
baseaddr + i);
data = bios->data[offset + 5 + i];
bios_idxprt_wr(bios, NV_CIO_CRX__COLOR, crtcindex2, data);
}
bios_idxprt_wr(bios, NV_CIO_CRX__COLOR, crtcindex1, oldaddr);
return len;
}
static int
init_cr(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint8_t crtcindex = bios->data[offset + 1];
uint8_t mask = bios->data[offset + 2];
uint8_t data = bios->data[offset + 3];
uint8_t value;
if (!iexec->execute)
return 4;
BIOSLOG(bios, "0x%04X: Index: 0x%02X, Mask: 0x%02X, Data: 0x%02X\n",
offset, crtcindex, mask, data);
value = bios_idxprt_rd(bios, NV_CIO_CRX__COLOR, crtcindex) & mask;
value |= data;
bios_idxprt_wr(bios, NV_CIO_CRX__COLOR, crtcindex, value);
return 4;
}
static int
init_zm_cr(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint8_t crtcindex = ROM32(bios->data[offset + 1]);
uint8_t data = bios->data[offset + 2];
if (!iexec->execute)
return 3;
bios_idxprt_wr(bios, NV_CIO_CRX__COLOR, crtcindex, data);
return 3;
}
static int
init_zm_cr_group(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint8_t count = bios->data[offset + 1];
int len = 2 + count * 2;
int i;
if (!iexec->execute)
return len;
for (i = 0; i < count; i++)
init_zm_cr(bios, offset + 2 + 2 * i - 1, iexec);
return len;
}
static int
init_condition_time(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint8_t cond = bios->data[offset + 1];
uint16_t retries = bios->data[offset + 2] * 50;
unsigned cnt;
if (!iexec->execute)
return 3;
if (retries > 100)
retries = 100;
BIOSLOG(bios, "0x%04X: Condition: 0x%02X, Retries: 0x%02X\n",
offset, cond, retries);
if (!bios->execute)
retries = 1;
for (cnt = 0; cnt < retries; cnt++) {
if (bios_condition_met(bios, offset, cond)) {
BIOSLOG(bios, "0x%04X: Condition met, continuing\n",
offset);
break;
} else {
BIOSLOG(bios, "0x%04X: "
"Condition not met, sleeping for 20ms\n",
offset);
mdelay(20);
}
}
if (!bios_condition_met(bios, offset, cond)) {
NV_WARN(bios->dev,
"0x%04X: Condition still not met after %dms, "
"skipping following opcodes\n", offset, 20 * retries);
iexec->execute = false;
}
return 3;
}
static int
init_ltime(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
unsigned time = ROM16(bios->data[offset + 1]);
if (!iexec->execute)
return 3;
BIOSLOG(bios, "0x%04X: Sleeping for 0x%04X milliseconds\n",
offset, time);
mdelay(time);
return 3;
}
static int
init_zm_reg_sequence(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint32_t basereg = ROM32(bios->data[offset + 1]);
uint32_t count = bios->data[offset + 5];
int len = 6 + count * 4;
int i;
if (!iexec->execute)
return len;
BIOSLOG(bios, "0x%04X: BaseReg: 0x%08X, Count: 0x%02X\n",
offset, basereg, count);
for (i = 0; i < count; i++) {
uint32_t reg = basereg + i * 4;
uint32_t data = ROM32(bios->data[offset + 6 + i * 4]);
bios_wr32(bios, reg, data);
}
return len;
}
static int
init_sub_direct(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint16_t sub_offset = ROM16(bios->data[offset + 1]);
if (!iexec->execute)
return 3;
BIOSLOG(bios, "0x%04X: Executing subroutine at 0x%04X\n",
offset, sub_offset);
parse_init_table(bios, sub_offset, iexec);
BIOSLOG(bios, "0x%04X: End of 0x%04X subroutine\n", offset, sub_offset);
return 3;
}
static int
init_jump(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint16_t jmp_offset = ROM16(bios->data[offset + 1]);
if (!iexec->execute)
return 3;
BIOSLOG(bios, "0x%04X: Jump to 0x%04X\n", offset, jmp_offset);
return jmp_offset - offset;
}
static int
init_i2c_if(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint8_t i2c_index = bios->data[offset + 1];
uint8_t i2c_address = bios->data[offset + 2] >> 1;
uint8_t reg = bios->data[offset + 3];
uint8_t mask = bios->data[offset + 4];
uint8_t data = bios->data[offset + 5];
struct nouveau_i2c_chan *chan;
union i2c_smbus_data val;
int ret;
BIOSLOG(bios, "0x%04X: DCBI2CIndex: 0x%02X, I2CAddress: 0x%02X\n",
offset, i2c_index, i2c_address);
chan = init_i2c_device_find(bios->dev, i2c_index);
if (!chan)
return -ENODEV;
ret = i2c_smbus_xfer(&chan->adapter, i2c_address, 0,
I2C_SMBUS_READ, reg,
I2C_SMBUS_BYTE_DATA, &val);
if (ret < 0) {
BIOSLOG(bios, "0x%04X: I2CReg: 0x%02X, Value: [no device], "
"Mask: 0x%02X, Data: 0x%02X\n",
offset, reg, mask, data);
iexec->execute = 0;
return 6;
}
BIOSLOG(bios, "0x%04X: I2CReg: 0x%02X, Value: 0x%02X, "
"Mask: 0x%02X, Data: 0x%02X\n",
offset, reg, val.byte, mask, data);
iexec->execute = ((val.byte & mask) == data);
return 6;
}
static int
init_copy_nv_reg(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint32_t srcreg = *((uint32_t *)(&bios->data[offset + 1]));
uint8_t shift = bios->data[offset + 5];
uint32_t srcmask = *((uint32_t *)(&bios->data[offset + 6]));
uint32_t xor = *((uint32_t *)(&bios->data[offset + 10]));
uint32_t dstreg = *((uint32_t *)(&bios->data[offset + 14]));
uint32_t dstmask = *((uint32_t *)(&bios->data[offset + 18]));
uint32_t srcvalue, dstvalue;
if (!iexec->execute)
return 22;
BIOSLOG(bios, "0x%04X: SrcReg: 0x%08X, Shift: 0x%02X, SrcMask: 0x%08X, "
"Xor: 0x%08X, DstReg: 0x%08X, DstMask: 0x%08X\n",
offset, srcreg, shift, srcmask, xor, dstreg, dstmask);
srcvalue = bios_rd32(bios, srcreg);
if (shift < 0x80)
srcvalue >>= shift;
else
srcvalue <<= (0x100 - shift);
srcvalue = (srcvalue & srcmask) ^ xor;
dstvalue = bios_rd32(bios, dstreg) & dstmask;
bios_wr32(bios, dstreg, dstvalue | srcvalue);
return 22;
}
static int
init_zm_index_io(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint16_t crtcport = ROM16(bios->data[offset + 1]);
uint8_t crtcindex = bios->data[offset + 3];
uint8_t data = bios->data[offset + 4];
if (!iexec->execute)
return 5;
bios_idxprt_wr(bios, crtcport, crtcindex, data);
return 5;
}
static inline void
bios_md32(struct nvbios *bios, uint32_t reg,
uint32_t mask, uint32_t val)
{
bios_wr32(bios, reg, (bios_rd32(bios, reg) & ~mask) | val);
}
static uint32_t
peek_fb(struct drm_device *dev, struct io_mapping *fb,
uint32_t off)
{
uint32_t val = 0;
if (off < pci_resource_len(dev->pdev, 1)) {
uint8_t __iomem *p =
io_mapping_map_atomic_wc(fb, off & PAGE_MASK);
val = ioread32(p + (off & ~PAGE_MASK));
io_mapping_unmap_atomic(p);
}
return val;
}
static void
poke_fb(struct drm_device *dev, struct io_mapping *fb,
uint32_t off, uint32_t val)
{
if (off < pci_resource_len(dev->pdev, 1)) {
uint8_t __iomem *p =
io_mapping_map_atomic_wc(fb, off & PAGE_MASK);
iowrite32(val, p + (off & ~PAGE_MASK));
wmb();
io_mapping_unmap_atomic(p);
}
}
static inline bool
read_back_fb(struct drm_device *dev, struct io_mapping *fb,
uint32_t off, uint32_t val)
{
poke_fb(dev, fb, off, val);
return val == peek_fb(dev, fb, off);
}
static int
nv04_init_compute_mem(struct nvbios *bios)
{
struct drm_device *dev = bios->dev;
uint32_t patt = 0xdeadbeef;
struct io_mapping *fb;
int i;
fb = io_mapping_create_wc(pci_resource_start(dev->pdev, 1),
pci_resource_len(dev->pdev, 1));
if (!fb)
return -ENOMEM;
NVWriteVgaSeq(dev, 0, 1, NVReadVgaSeq(dev, 0, 1) | 0x20);
bios_md32(bios, NV04_PFB_DEBUG_0, 0, NV04_PFB_DEBUG_0_REFRESH_OFF);
bios_md32(bios, NV04_PFB_BOOT_0, ~0,
NV04_PFB_BOOT_0_RAM_AMOUNT_16MB |
NV04_PFB_BOOT_0_RAM_WIDTH_128 |
NV04_PFB_BOOT_0_RAM_TYPE_SGRAM_16MBIT);
for (i = 0; i < 4; i++)
poke_fb(dev, fb, 4 * i, patt);
poke_fb(dev, fb, 0x400000, patt + 1);
if (peek_fb(dev, fb, 0) == patt + 1) {
bios_md32(bios, NV04_PFB_BOOT_0, NV04_PFB_BOOT_0_RAM_TYPE,
NV04_PFB_BOOT_0_RAM_TYPE_SDRAM_16MBIT);
bios_md32(bios, NV04_PFB_DEBUG_0,
NV04_PFB_DEBUG_0_REFRESH_OFF, 0);
for (i = 0; i < 4; i++)
poke_fb(dev, fb, 4 * i, patt);
if ((peek_fb(dev, fb, 0xc) & 0xffff) != (patt & 0xffff))
bios_md32(bios, NV04_PFB_BOOT_0,
NV04_PFB_BOOT_0_RAM_WIDTH_128 |
NV04_PFB_BOOT_0_RAM_AMOUNT,
NV04_PFB_BOOT_0_RAM_AMOUNT_8MB);
} else if ((peek_fb(dev, fb, 0xc) & 0xffff0000) !=
(patt & 0xffff0000)) {
bios_md32(bios, NV04_PFB_BOOT_0,
NV04_PFB_BOOT_0_RAM_WIDTH_128 |
NV04_PFB_BOOT_0_RAM_AMOUNT,
NV04_PFB_BOOT_0_RAM_AMOUNT_4MB);
} else if (peek_fb(dev, fb, 0) != patt) {
if (read_back_fb(dev, fb, 0x800000, patt))
bios_md32(bios, NV04_PFB_BOOT_0,
NV04_PFB_BOOT_0_RAM_AMOUNT,
NV04_PFB_BOOT_0_RAM_AMOUNT_8MB);
else
bios_md32(bios, NV04_PFB_BOOT_0,
NV04_PFB_BOOT_0_RAM_AMOUNT,
NV04_PFB_BOOT_0_RAM_AMOUNT_4MB);
bios_md32(bios, NV04_PFB_BOOT_0, NV04_PFB_BOOT_0_RAM_TYPE,
NV04_PFB_BOOT_0_RAM_TYPE_SGRAM_8MBIT);
} else if (!read_back_fb(dev, fb, 0x800000, patt)) {
bios_md32(bios, NV04_PFB_BOOT_0, NV04_PFB_BOOT_0_RAM_AMOUNT,
NV04_PFB_BOOT_0_RAM_AMOUNT_8MB);
}
bios_md32(bios, NV04_PFB_DEBUG_0, NV04_PFB_DEBUG_0_REFRESH_OFF, 0);
NVWriteVgaSeq(dev, 0, 1, NVReadVgaSeq(dev, 0, 1) & ~0x20);
io_mapping_free(fb);
return 0;
}
static const uint8_t *
nv05_memory_config(struct nvbios *bios)
{
static const uint8_t default_config_tab[][2] = {
{ 0x24, 0x00 },
{ 0x28, 0x00 },
{ 0x24, 0x01 },
{ 0x1f, 0x00 },
{ 0x0f, 0x00 },
{ 0x17, 0x00 },
{ 0x06, 0x00 },
{ 0x00, 0x00 }
};
int i = (bios_rd32(bios, NV_PEXTDEV_BOOT_0) &
NV_PEXTDEV_BOOT_0_RAMCFG) >> 2;
if (bios->legacy.mem_init_tbl_ptr)
return &bios->data[bios->legacy.mem_init_tbl_ptr + 2 * i];
else
return default_config_tab[i];
}
static int
nv05_init_compute_mem(struct nvbios *bios)
{
struct drm_device *dev = bios->dev;
const uint8_t *ramcfg = nv05_memory_config(bios);
uint32_t patt = 0xdeadbeef;
struct io_mapping *fb;
int i, v;
fb = io_mapping_create_wc(pci_resource_start(dev->pdev, 1),
pci_resource_len(dev->pdev, 1));
if (!fb)
return -ENOMEM;
NVWriteVgaSeq(dev, 0, 1, NVReadVgaSeq(dev, 0, 1) | 0x20);
if (bios_rd32(bios, NV04_PFB_BOOT_0) & NV04_PFB_BOOT_0_UMA_ENABLE)
goto out;
bios_md32(bios, NV04_PFB_DEBUG_0, NV04_PFB_DEBUG_0_REFRESH_OFF, 0);
if (bios->legacy.mem_init_tbl_ptr) {
uint32_t *scramble_tab = (uint32_t *)&bios->data[
bios->legacy.mem_init_tbl_ptr + 0x10];
for (i = 0; i < 8; i++)
bios_wr32(bios, NV04_PFB_SCRAMBLE(i),
ROM32(scramble_tab[i]));
}
bios_md32(bios, NV04_PFB_BOOT_0, 0x3f, ramcfg[0]);
if (ramcfg[1] & 0x80)
bios_md32(bios, NV04_PFB_CFG0, 0, NV04_PFB_CFG0_SCRAMBLE);
bios_md32(bios, NV04_PFB_CFG1, 0x700001, (ramcfg[1] & 1) << 20);
bios_md32(bios, NV04_PFB_CFG1, 0, 1);
for (i = 0; i < 4; i++)
poke_fb(dev, fb, 4 * i, patt);
if (peek_fb(dev, fb, 0xc) != patt)
bios_md32(bios, NV04_PFB_BOOT_0,
NV04_PFB_BOOT_0_RAM_WIDTH_128, 0);
v = bios_rd32(bios, NV04_PFB_BOOT_0) & NV04_PFB_BOOT_0_RAM_AMOUNT;
if (v == NV04_PFB_BOOT_0_RAM_AMOUNT_32MB &&
(!read_back_fb(dev, fb, 0x1000000, ++patt) ||
!read_back_fb(dev, fb, 0, ++patt)))
bios_md32(bios, NV04_PFB_BOOT_0, NV04_PFB_BOOT_0_RAM_AMOUNT,
NV04_PFB_BOOT_0_RAM_AMOUNT_16MB);
if (v == NV04_PFB_BOOT_0_RAM_AMOUNT_16MB &&
!read_back_fb(dev, fb, 0x800000, ++patt))
bios_md32(bios, NV04_PFB_BOOT_0, NV04_PFB_BOOT_0_RAM_AMOUNT,
NV04_PFB_BOOT_0_RAM_AMOUNT_8MB);
if (!read_back_fb(dev, fb, 0x400000, ++patt))
bios_md32(bios, NV04_PFB_BOOT_0, NV04_PFB_BOOT_0_RAM_AMOUNT,
NV04_PFB_BOOT_0_RAM_AMOUNT_4MB);
out:
NVWriteVgaSeq(dev, 0, 1, NVReadVgaSeq(dev, 0, 1) & ~0x20);
io_mapping_free(fb);
return 0;
}
static int
nv10_init_compute_mem(struct nvbios *bios)
{
struct drm_device *dev = bios->dev;
struct drm_nouveau_private *dev_priv = bios->dev->dev_private;
const int mem_width[] = { 0x10, 0x00, 0x20 };
const int mem_width_count = (dev_priv->chipset >= 0x17 ? 3 : 2);
uint32_t patt = 0xdeadbeef;
struct io_mapping *fb;
int i, j, k;
fb = io_mapping_create_wc(pci_resource_start(dev->pdev, 1),
pci_resource_len(dev->pdev, 1));
if (!fb)
return -ENOMEM;
bios_wr32(bios, NV10_PFB_REFCTRL, NV10_PFB_REFCTRL_VALID_1);
for (i = 0; i < mem_width_count; i++) {
bios_md32(bios, NV04_PFB_CFG0, 0x30, mem_width[i]);
for (j = 0; j < 4; j++) {
for (k = 0; k < 4; k++)
poke_fb(dev, fb, 0x1c, 0);
poke_fb(dev, fb, 0x1c, patt);
poke_fb(dev, fb, 0x3c, 0);
if (peek_fb(dev, fb, 0x1c) == patt)
goto mem_width_found;
}
}
mem_width_found:
patt <<= 1;
for (i = 0; i < 4; i++) {
int off = bios_rd32(bios, NV04_PFB_FIFO_DATA) - 0x100000;
poke_fb(dev, fb, off, patt);
poke_fb(dev, fb, 0, 0);
peek_fb(dev, fb, 0);
peek_fb(dev, fb, 0);
peek_fb(dev, fb, 0);
peek_fb(dev, fb, 0);
if (peek_fb(dev, fb, off) == patt)
goto amount_found;
}
bios_md32(bios, NV04_PFB_CFG0, 0x1000, 0);
amount_found:
io_mapping_free(fb);
return 0;
}
static int
nv20_init_compute_mem(struct nvbios *bios)
{
struct drm_device *dev = bios->dev;
struct drm_nouveau_private *dev_priv = bios->dev->dev_private;
uint32_t mask = (dev_priv->chipset >= 0x25 ? 0x300 : 0x900);
uint32_t amount, off;
struct io_mapping *fb;
fb = io_mapping_create_wc(pci_resource_start(dev->pdev, 1),
pci_resource_len(dev->pdev, 1));
if (!fb)
return -ENOMEM;
bios_wr32(bios, NV10_PFB_REFCTRL, NV10_PFB_REFCTRL_VALID_1);
bios_md32(bios, NV04_PFB_CFG0, 0, mask);
amount = bios_rd32(bios, NV04_PFB_FIFO_DATA);
for (off = amount; off > 0x2000000; off -= 0x2000000)
poke_fb(dev, fb, off - 4, off);
amount = bios_rd32(bios, NV04_PFB_FIFO_DATA);
if (amount != peek_fb(dev, fb, amount - 4))
bios_md32(bios, NV04_PFB_CFG0, mask, 0);
io_mapping_free(fb);
return 0;
}
static int
init_compute_mem(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
struct drm_nouveau_private *dev_priv = bios->dev->dev_private;
int ret;
if (dev_priv->chipset >= 0x40 ||
dev_priv->chipset == 0x1a ||
dev_priv->chipset == 0x1f)
ret = 0;
else if (dev_priv->chipset >= 0x20 &&
dev_priv->chipset != 0x34)
ret = nv20_init_compute_mem(bios);
else if (dev_priv->chipset >= 0x10)
ret = nv10_init_compute_mem(bios);
else if (dev_priv->chipset >= 0x5)
ret = nv05_init_compute_mem(bios);
else
ret = nv04_init_compute_mem(bios);
if (ret)
return ret;
return 1;
}
static int
init_reset(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint32_t reg = ROM32(bios->data[offset + 1]);
uint32_t value1 = ROM32(bios->data[offset + 5]);
uint32_t value2 = ROM32(bios->data[offset + 9]);
uint32_t pci_nv_19, pci_nv_20;
pci_nv_19 = bios_rd32(bios, NV_PBUS_PCI_NV_19);
bios_wr32(bios, NV_PBUS_PCI_NV_19, pci_nv_19 & ~0xf00);
bios_wr32(bios, reg, value1);
udelay(10);
bios_wr32(bios, reg, value2);
bios_wr32(bios, NV_PBUS_PCI_NV_19, pci_nv_19);
pci_nv_20 = bios_rd32(bios, NV_PBUS_PCI_NV_20);
pci_nv_20 &= ~NV_PBUS_PCI_NV_20_ROM_SHADOW_ENABLED;
bios_wr32(bios, NV_PBUS_PCI_NV_20, pci_nv_20);
return 13;
}
static int
init_configure_mem(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint16_t meminitoffs = bios->legacy.mem_init_tbl_ptr + MEM_INIT_SIZE * (bios_idxprt_rd(bios, NV_CIO_CRX__COLOR, NV_CIO_CRE_SCRATCH4__INDEX) >> 4);
uint16_t seqtbloffs = bios->legacy.sdr_seq_tbl_ptr, meminitdata = meminitoffs + 6;
uint32_t reg, data;
if (bios->major_version > 2)
return 0;
bios_idxprt_wr(bios, NV_VIO_SRX, NV_VIO_SR_CLOCK_INDEX, bios_idxprt_rd(
bios, NV_VIO_SRX, NV_VIO_SR_CLOCK_INDEX) | 0x20);
if (bios->data[meminitoffs] & 1)
seqtbloffs = bios->legacy.ddr_seq_tbl_ptr;
for (reg = ROM32(bios->data[seqtbloffs]);
reg != 0xffffffff;
reg = ROM32(bios->data[seqtbloffs += 4])) {
switch (reg) {
case NV04_PFB_PRE:
data = NV04_PFB_PRE_CMD_PRECHARGE;
break;
case NV04_PFB_PAD:
data = NV04_PFB_PAD_CKE_NORMAL;
break;
case NV04_PFB_REF:
data = NV04_PFB_REF_CMD_REFRESH;
break;
default:
data = ROM32(bios->data[meminitdata]);
meminitdata += 4;
if (data == 0xffffffff)
continue;
}
bios_wr32(bios, reg, data);
}
return 1;
}
static int
init_configure_clk(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint16_t meminitoffs = bios->legacy.mem_init_tbl_ptr + MEM_INIT_SIZE * (bios_idxprt_rd(bios, NV_CIO_CRX__COLOR, NV_CIO_CRE_SCRATCH4__INDEX) >> 4);
int clock;
if (bios->major_version > 2)
return 0;
clock = ROM16(bios->data[meminitoffs + 4]) * 10;
setPLL(bios, NV_PRAMDAC_NVPLL_COEFF, clock);
clock = ROM16(bios->data[meminitoffs + 2]) * 10;
if (bios->data[meminitoffs] & 1)
clock *= 2;
setPLL(bios, NV_PRAMDAC_MPLL_COEFF, clock);
return 1;
}
static int
init_configure_preinit(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint32_t straps = bios_rd32(bios, NV_PEXTDEV_BOOT_0);
uint8_t cr3c = ((straps << 2) & 0xf0) | (straps & 0x40) >> 6;
if (bios->major_version > 2)
return 0;
bios_idxprt_wr(bios, NV_CIO_CRX__COLOR,
NV_CIO_CRE_SCRATCH4__INDEX, cr3c);
return 1;
}
static int
init_io(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
struct drm_nouveau_private *dev_priv = bios->dev->dev_private;
uint16_t crtcport = ROM16(bios->data[offset + 1]);
uint8_t mask = bios->data[offset + 3];
uint8_t data = bios->data[offset + 4];
if (!iexec->execute)
return 5;
BIOSLOG(bios, "0x%04X: Port: 0x%04X, Mask: 0x%02X, Data: 0x%02X\n",
offset, crtcport, mask, data);
if (dev_priv->card_type >= NV_50 && crtcport == 0x3c3 && data == 1) {
int i;
bios_wr32(bios, 0x614100, (bios_rd32(
bios, 0x614100) & 0x0fffffff) | 0x00800000);
bios_wr32(bios, 0x00e18c, bios_rd32(
bios, 0x00e18c) | 0x00020000);
bios_wr32(bios, 0x614900, (bios_rd32(
bios, 0x614900) & 0x0fffffff) | 0x00800000);
bios_wr32(bios, 0x000200, bios_rd32(
bios, 0x000200) & ~0x40000000);
mdelay(10);
bios_wr32(bios, 0x00e18c, bios_rd32(
bios, 0x00e18c) & ~0x00020000);
bios_wr32(bios, 0x000200, bios_rd32(
bios, 0x000200) | 0x40000000);
bios_wr32(bios, 0x614100, 0x00800018);
bios_wr32(bios, 0x614900, 0x00800018);
mdelay(10);
bios_wr32(bios, 0x614100, 0x10000018);
bios_wr32(bios, 0x614900, 0x10000018);
for (i = 0; i < 3; i++)
bios_wr32(bios, 0x614280 + (i*0x800), bios_rd32(
bios, 0x614280 + (i*0x800)) & 0xf0f0f0f0);
for (i = 0; i < 2; i++)
bios_wr32(bios, 0x614300 + (i*0x800), bios_rd32(
bios, 0x614300 + (i*0x800)) & 0xfffff0f0);
for (i = 0; i < 3; i++)
bios_wr32(bios, 0x614380 + (i*0x800), bios_rd32(
bios, 0x614380 + (i*0x800)) & 0xfffff0f0);
for (i = 0; i < 2; i++)
bios_wr32(bios, 0x614200 + (i*0x800), bios_rd32(
bios, 0x614200 + (i*0x800)) & 0xfffffff0);
for (i = 0; i < 2; i++)
bios_wr32(bios, 0x614108 + (i*0x800), bios_rd32(
bios, 0x614108 + (i*0x800)) & 0x0fffffff);
return 5;
}
bios_port_wr(bios, crtcport, (bios_port_rd(bios, crtcport) & mask) |
data);
return 5;
}
static int
init_sub(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint8_t sub = bios->data[offset + 1];
if (!iexec->execute)
return 2;
BIOSLOG(bios, "0x%04X: Calling script %d\n", offset, sub);
parse_init_table(bios,
ROM16(bios->data[bios->init_script_tbls_ptr + sub * 2]),
iexec);
BIOSLOG(bios, "0x%04X: End of script %d\n", offset, sub);
return 2;
}
static int
init_ram_condition(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint8_t mask = bios->data[offset + 1];
uint8_t cmpval = bios->data[offset + 2];
uint8_t data;
if (!iexec->execute)
return 3;
data = bios_rd32(bios, NV04_PFB_BOOT_0) & mask;
BIOSLOG(bios, "0x%04X: Checking if 0x%08X equals 0x%08X\n",
offset, data, cmpval);
if (data == cmpval)
BIOSLOG(bios, "0x%04X: Condition fulfilled -- continuing to execute\n", offset);
else {
BIOSLOG(bios, "0x%04X: Condition not fulfilled -- skipping following commands\n", offset);
iexec->execute = false;
}
return 3;
}
static int
init_nv_reg(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint32_t reg = ROM32(bios->data[offset + 1]);
uint32_t mask = ROM32(bios->data[offset + 5]);
uint32_t data = ROM32(bios->data[offset + 9]);
if (!iexec->execute)
return 13;
BIOSLOG(bios, "0x%04X: Reg: 0x%08X, Mask: 0x%08X, Data: 0x%08X\n",
offset, reg, mask, data);
bios_wr32(bios, reg, (bios_rd32(bios, reg) & mask) | data);
return 13;
}
static int
init_macro(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint8_t macro_index_tbl_idx = bios->data[offset + 1];
uint16_t tmp = bios->macro_index_tbl_ptr + (macro_index_tbl_idx * MACRO_INDEX_SIZE);
uint8_t macro_tbl_idx = bios->data[tmp];
uint8_t count = bios->data[tmp + 1];
uint32_t reg, data;
int i;
if (!iexec->execute)
return 2;
BIOSLOG(bios, "0x%04X: Macro: 0x%02X, MacroTableIndex: 0x%02X, "
"Count: 0x%02X\n",
offset, macro_index_tbl_idx, macro_tbl_idx, count);
for (i = 0; i < count; i++) {
uint16_t macroentryptr = bios->macro_tbl_ptr + (macro_tbl_idx + i) * MACRO_SIZE;
reg = ROM32(bios->data[macroentryptr]);
data = ROM32(bios->data[macroentryptr + 4]);
bios_wr32(bios, reg, data);
}
return 2;
}
static int
init_done(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
return 0;
}
static int
init_resume(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
if (iexec->execute)
return 1;
iexec->execute = true;
BIOSLOG(bios, "0x%04X: ---- Executing following commands ----\n", offset);
return 1;
}
static int
init_time(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
unsigned time = ROM16(bios->data[offset + 1]);
if (!iexec->execute)
return 3;
BIOSLOG(bios, "0x%04X: Sleeping for 0x%04X microseconds\n",
offset, time);
if (time < 1000)
udelay(time);
else
mdelay((time + 900) / 1000);
return 3;
}
static int
init_condition(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint8_t cond = bios->data[offset + 1];
if (!iexec->execute)
return 2;
BIOSLOG(bios, "0x%04X: Condition: 0x%02X\n", offset, cond);
if (bios_condition_met(bios, offset, cond))
BIOSLOG(bios, "0x%04X: Condition fulfilled -- continuing to execute\n", offset);
else {
BIOSLOG(bios, "0x%04X: Condition not fulfilled -- skipping following commands\n", offset);
iexec->execute = false;
}
return 2;
}
static int
init_io_condition(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint8_t cond = bios->data[offset + 1];
if (!iexec->execute)
return 2;
BIOSLOG(bios, "0x%04X: IO condition: 0x%02X\n", offset, cond);
if (io_condition_met(bios, offset, cond))
BIOSLOG(bios, "0x%04X: Condition fulfilled -- continuing to execute\n", offset);
else {
BIOSLOG(bios, "0x%04X: Condition not fulfilled -- skipping following commands\n", offset);
iexec->execute = false;
}
return 2;
}
static int
init_index_io(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint16_t crtcport = ROM16(bios->data[offset + 1]);
uint8_t crtcindex = bios->data[offset + 3];
uint8_t mask = bios->data[offset + 4];
uint8_t data = bios->data[offset + 5];
uint8_t value;
if (!iexec->execute)
return 6;
BIOSLOG(bios, "0x%04X: Port: 0x%04X, Index: 0x%02X, Mask: 0x%02X, "
"Data: 0x%02X\n",
offset, crtcport, crtcindex, mask, data);
value = (bios_idxprt_rd(bios, crtcport, crtcindex) & mask) | data;
bios_idxprt_wr(bios, crtcport, crtcindex, value);
return 6;
}
static int
init_pll(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint32_t reg = ROM32(bios->data[offset + 1]);
uint16_t freq = ROM16(bios->data[offset + 5]);
if (!iexec->execute)
return 7;
BIOSLOG(bios, "0x%04X: Reg: 0x%08X, Freq: %d0kHz\n", offset, reg, freq);
setPLL(bios, reg, freq * 10);
return 7;
}
static int
init_zm_reg(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint32_t reg = ROM32(bios->data[offset + 1]);
uint32_t value = ROM32(bios->data[offset + 5]);
if (!iexec->execute)
return 9;
if (reg == 0x000200)
value |= 1;
bios_wr32(bios, reg, value);
return 9;
}
static int
init_ram_restrict_pll(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
struct drm_device *dev = bios->dev;
uint32_t strap = (bios_rd32(bios, NV_PEXTDEV_BOOT_0) & 0x0000003c) >> 2;
uint8_t index = bios->data[bios->ram_restrict_tbl_ptr + strap];
uint8_t type = bios->data[offset + 1];
uint32_t freq = ROM32(bios->data[offset + 2 + (index * 4)]);
uint8_t *pll_limits = &bios->data[bios->pll_limit_tbl_ptr], *entry;
int len = 2 + bios->ram_restrict_group_count * 4;
int i;
if (!iexec->execute)
return len;
if (!bios->pll_limit_tbl_ptr || (pll_limits[0] & 0xf0) != 0x30) {
NV_ERROR(dev, "PLL limits table not version 3.x\n");
return len;
}
entry = pll_limits + pll_limits[1];
for (i = 0; i < pll_limits[3]; i++, entry += pll_limits[2]) {
if (entry[0] == type) {
uint32_t reg = ROM32(entry[3]);
BIOSLOG(bios, "0x%04X: "
"Type %02x Reg 0x%08x Freq %dKHz\n",
offset, type, reg, freq);
setPLL(bios, reg, freq);
return len;
}
}
NV_ERROR(dev, "PLL type 0x%02x not found in PLL limits table", type);
return len;
}
static int
init_8c(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
return 1;
}
static int
init_8d(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
return 1;
}
static int
init_gpio(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
struct drm_nouveau_private *dev_priv = bios->dev->dev_private;
struct nouveau_gpio_engine *pgpio = &dev_priv->engine.gpio;
const uint32_t nv50_gpio_ctl[2] = { 0xe100, 0xe28c };
int i;
if (dev_priv->card_type < NV_50) {
NV_ERROR(bios->dev, "INIT_GPIO on unsupported chipset\n");
return 1;
}
if (!iexec->execute)
return 1;
for (i = 0; i < bios->dcb.gpio.entries; i++) {
struct dcb_gpio_entry *gpio = &bios->dcb.gpio.entry[i];
uint32_t r, s, v;
BIOSLOG(bios, "0x%04X: Entry: 0x%08X\n", offset, gpio->entry);
BIOSLOG(bios, "0x%04X: set gpio 0x%02x, state %d\n",
offset, gpio->tag, gpio->state_default);
if (bios->execute)
pgpio->set(bios->dev, gpio->tag, gpio->state_default);
r = nv50_gpio_ctl[gpio->line >> 4];
s = (gpio->line & 0x0f);
v = bios_rd32(bios, r) & ~(0x00010001 << s);
switch ((gpio->entry & 0x06000000) >> 25) {
case 1:
v |= (0x00000001 << s);
break;
case 2:
v |= (0x00010000 << s);
break;
default:
break;
}
bios_wr32(bios, r, v);
}
return 1;
}
static int
init_ram_restrict_zm_reg_group(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint32_t reg = ROM32(bios->data[offset + 1]);
uint8_t regincrement = bios->data[offset + 5];
uint8_t count = bios->data[offset + 6];
uint32_t strap_ramcfg, data;
uint16_t blocklen = bios->ram_restrict_group_count * 4;
int len = 7 + count * blocklen;
uint8_t index;
int i;
;
if (!blocklen) {
NV_ERROR(bios->dev,
"0x%04X: Zero block length - has the M table "
"been parsed?\n", offset);
return -EINVAL;
}
if (!iexec->execute)
return len;
strap_ramcfg = (bios_rd32(bios, NV_PEXTDEV_BOOT_0) >> 2) & 0xf;
index = bios->data[bios->ram_restrict_tbl_ptr + strap_ramcfg];
BIOSLOG(bios, "0x%04X: Reg: 0x%08X, RegIncrement: 0x%02X, "
"Count: 0x%02X, StrapRamCfg: 0x%02X, Index: 0x%02X\n",
offset, reg, regincrement, count, strap_ramcfg, index);
for (i = 0; i < count; i++) {
data = ROM32(bios->data[offset + 7 + index * 4 + blocklen * i]);
bios_wr32(bios, reg, data);
reg += regincrement;
}
return len;
}
static int
init_copy_zm_reg(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint32_t srcreg = ROM32(bios->data[offset + 1]);
uint32_t dstreg = ROM32(bios->data[offset + 5]);
if (!iexec->execute)
return 9;
bios_wr32(bios, dstreg, bios_rd32(bios, srcreg));
return 9;
}
static int
init_zm_reg_group_addr_latched(struct nvbios *bios, uint16_t offset,
struct init_exec *iexec)
{
uint32_t reg = ROM32(bios->data[offset + 1]);
uint8_t count = bios->data[offset + 5];
int len = 6 + count * 4;
int i;
if (!iexec->execute)
return len;
for (i = 0; i < count; i++) {
uint32_t data = ROM32(bios->data[offset + 6 + 4 * i]);
bios_wr32(bios, reg, data);
}
return len;
}
static int
init_reserved(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
return 1;
}
static int
init_96(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint16_t xlatptr = bios->init96_tbl_ptr + (bios->data[offset + 7] * 2);
uint32_t reg = ROM32(bios->data[offset + 8]);
uint32_t mask = ROM32(bios->data[offset + 12]);
uint32_t val;
val = bios_rd32(bios, ROM32(bios->data[offset + 1]));
if (bios->data[offset + 5] < 0x80)
val >>= bios->data[offset + 5];
else
val <<= (0x100 - bios->data[offset + 5]);
val &= bios->data[offset + 6];
val = bios->data[ROM16(bios->data[xlatptr]) + val];
val <<= bios->data[offset + 16];
if (!iexec->execute)
return 17;
bios_wr32(bios, reg, (bios_rd32(bios, reg) & mask) | val);
return 17;
}
static int
init_97(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint32_t reg = ROM32(bios->data[offset + 1]);
uint32_t mask = ROM32(bios->data[offset + 5]);
uint32_t add = ROM32(bios->data[offset + 9]);
uint32_t val;
val = bios_rd32(bios, reg);
val = (val & mask) | ((val + add) & ~mask);
if (!iexec->execute)
return 13;
bios_wr32(bios, reg, val);
return 13;
}
static int
init_auxch(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
struct drm_device *dev = bios->dev;
struct nouveau_i2c_chan *auxch;
uint32_t addr = ROM32(bios->data[offset + 1]);
uint8_t count = bios->data[offset + 5];
int len = 6 + count * 2;
int ret, i;
if (!bios->display.output) {
NV_ERROR(dev, "INIT_AUXCH: no active output\n");
return len;
}
auxch = init_i2c_device_find(dev, bios->display.output->i2c_index);
if (!auxch) {
NV_ERROR(dev, "INIT_AUXCH: couldn't get auxch %d\n",
bios->display.output->i2c_index);
return len;
}
if (!iexec->execute)
return len;
offset += 6;
for (i = 0; i < count; i++, offset += 2) {
uint8_t data;
ret = nouveau_dp_auxch(auxch, 9, addr, &data, 1);
if (ret) {
NV_ERROR(dev, "INIT_AUXCH: rd auxch fail %d\n", ret);
return len;
}
data &= bios->data[offset + 0];
data |= bios->data[offset + 1];
ret = nouveau_dp_auxch(auxch, 8, addr, &data, 1);
if (ret) {
NV_ERROR(dev, "INIT_AUXCH: wr auxch fail %d\n", ret);
return len;
}
}
return len;
}
static int
init_zm_auxch(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
struct drm_device *dev = bios->dev;
struct nouveau_i2c_chan *auxch;
uint32_t addr = ROM32(bios->data[offset + 1]);
uint8_t count = bios->data[offset + 5];
int len = 6 + count;
int ret, i;
if (!bios->display.output) {
NV_ERROR(dev, "INIT_ZM_AUXCH: no active output\n");
return len;
}
auxch = init_i2c_device_find(dev, bios->display.output->i2c_index);
if (!auxch) {
NV_ERROR(dev, "INIT_ZM_AUXCH: couldn't get auxch %d\n",
bios->display.output->i2c_index);
return len;
}
if (!iexec->execute)
return len;
offset += 6;
for (i = 0; i < count; i++, offset++) {
ret = nouveau_dp_auxch(auxch, 8, addr, &bios->data[offset], 1);
if (ret) {
NV_ERROR(dev, "INIT_ZM_AUXCH: wr auxch fail %d\n", ret);
return len;
}
}
return len;
}
static int
init_i2c_long_if(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
uint8_t i2c_index = bios->data[offset + 1];
uint8_t i2c_address = bios->data[offset + 2] >> 1;
uint8_t reglo = bios->data[offset + 3];
uint8_t reghi = bios->data[offset + 4];
uint8_t mask = bios->data[offset + 5];
uint8_t data = bios->data[offset + 6];
struct nouveau_i2c_chan *chan;
uint8_t buf0[2] = { reghi, reglo };
uint8_t buf1[1];
struct i2c_msg msg[2] = {
{ i2c_address, 0, 1, buf0 },
{ i2c_address, I2C_M_RD, 1, buf1 },
};
int ret;
BIOSLOG(bios, "0x%04X: DCBI2CIndex: 0x%02X, I2CAddress: 0x%02X\n",
offset, i2c_index, i2c_address);
chan = init_i2c_device_find(bios->dev, i2c_index);
if (!chan)
return -ENODEV;
ret = i2c_transfer(&chan->adapter, msg, 2);
if (ret < 0) {
BIOSLOG(bios, "0x%04X: I2CReg: 0x%02X:0x%02X, Value: [no device], "
"Mask: 0x%02X, Data: 0x%02X\n",
offset, reghi, reglo, mask, data);
iexec->execute = 0;
return 7;
}
BIOSLOG(bios, "0x%04X: I2CReg: 0x%02X:0x%02X, Value: 0x%02X, "
"Mask: 0x%02X, Data: 0x%02X\n",
offset, reghi, reglo, buf1[0], mask, data);
iexec->execute = ((buf1[0] & mask) == data);
return 7;
}
static int
parse_init_table(struct nvbios *bios, uint16_t offset, struct init_exec *iexec)
{
int count = 0, i, ret;
uint8_t id;
while ((offset < bios->length) && (count++ < MAX_TABLE_OPS)) {
id = bios->data[offset];
for (i = 0; itbl_entry[i].name && (itbl_entry[i].id != id); i++)
;
if (!itbl_entry[i].name) {
NV_ERROR(bios->dev,
"0x%04X: Init table command not found: "
"0x%02X\n", offset, id);
return -ENOENT;
}
BIOSLOG(bios, "0x%04X: [ (0x%02X) - %s ]\n", offset,
itbl_entry[i].id, itbl_entry[i].name);
ret = (*itbl_entry[i].handler)(bios, offset, iexec);
if (ret < 0) {
NV_ERROR(bios->dev, "0x%04X: Failed parsing init "
"table opcode: %s %d\n", offset,
itbl_entry[i].name, ret);
}
if (ret <= 0)
break;
offset += ret;
}
if (offset >= bios->length)
NV_WARN(bios->dev,
"Offset 0x%04X greater than known bios image length. "
"Corrupt image?\n", offset);
if (count >= MAX_TABLE_OPS)
NV_WARN(bios->dev,
"More than %d opcodes to a table is unlikely, "
"is the bios image corrupt?\n", MAX_TABLE_OPS);
return 0;
}
static void
parse_init_tables(struct nvbios *bios)
{
int i = 0;
uint16_t table;
struct init_exec iexec = {true, false};
if (bios->old_style_init) {
if (bios->init_script_tbls_ptr)
parse_init_table(bios, bios->init_script_tbls_ptr, &iexec);
if (bios->extra_init_script_tbl_ptr)
parse_init_table(bios, bios->extra_init_script_tbl_ptr, &iexec);
return;
}
while ((table = ROM16(bios->data[bios->init_script_tbls_ptr + i]))) {
NV_INFO(bios->dev,
"Parsing VBIOS init table %d at offset 0x%04X\n",
i / 2, table);
BIOSLOG(bios, "0x%04X: ------ Executing following commands ------\n", table);
parse_init_table(bios, table, &iexec);
i += 2;
}
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
struct dcb_entry *dcbent, int head, bool dl)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
struct init_exec iexec = {true, false};
NV_TRACE(dev, "0x%04X: Parsing digital output script table\n",
scriptptr);
bios_idxprt_wr(bios, NV_CIO_CRX__COLOR, NV_CIO_CRE_44,
head ? NV_CIO_CRE_44_HEADB : NV_CIO_CRE_44_HEADA);
NVWriteVgaCrtc5758(dev, head, 0, dcbent->index);
parse_init_table(bios, scriptptr, &iexec);
nv04_dfp_bind_head(dev, dcbent, head, dl);
}
static int call_lvds_manufacturer_script(struct drm_device *dev, struct dcb_entry *dcbent, int head, enum LVDS_script script)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
uint8_t sub = bios->data[bios->fp.xlated_entry + script] + (bios->fp.link_c_increment && dcbent->or & OUTPUT_C ? 1 : 0);
uint16_t scriptofs = ROM16(bios->data[bios->init_script_tbls_ptr + sub * 2]);
if (!bios->fp.xlated_entry || !sub || !scriptofs)
return -EINVAL;
run_digital_op_script(dev, scriptofs, dcbent, head, bios->fp.dual_link);
if (script == LVDS_PANEL_OFF) {
mdelay(ROM16(bios->data[bios->fp.xlated_entry + 7]));
}
#ifdef __powerpc__
if (script == LVDS_RESET &&
(dev->pci_device == 0x0179 || dev->pci_device == 0x0189 ||
dev->pci_device == 0x0329))
nv_write_tmds(dev, dcbent->or, 0, 0x02, 0x72);
#endif
return 0;
}
static int run_lvds_table(struct drm_device *dev, struct dcb_entry *dcbent, int head, enum LVDS_script script, int pxclk)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
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
NV_ERROR(dev, "Pixel clock comparison table not found\n");
return -ENOENT;
}
scriptptr = clkcmptable(bios, clktable, pxclk);
}
if (!scriptptr) {
NV_ERROR(dev, "LVDS output init script not found\n");
return -ENOENT;
}
run_digital_op_script(dev, scriptptr, dcbent, head, bios->fp.dual_link);
return 0;
}
int call_lvds_script(struct drm_device *dev, struct dcb_entry *dcbent, int head, enum LVDS_script script, int pxclk)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
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
NV_TRACE(dev, "Calling LVDS script %d:\n", script);
sel_clk_binding = bios_rd32(bios, NV_PRAMDAC_SEL_CLK) & 0x50000;
if (lvds_ver < 0x30)
ret = call_lvds_manufacturer_script(dev, dcbent, head, script);
else
ret = run_lvds_table(dev, dcbent, head, script, pxclk);
bios->fp.last_script_invoc = (script << 1 | head);
sel_clk = NVReadRAMDAC(dev, 0, NV_PRAMDAC_SEL_CLK) & ~0x50000;
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_SEL_CLK, sel_clk | sel_clk_binding);
nvWriteMC(dev, NV_PBUS_POWERCTRL_2, 0);
return ret;
}
static int parse_lvds_manufacturer_table_header(struct drm_device *dev, struct nvbios *bios, struct lvdstableheader *lth)
{
uint8_t lvds_ver, headerlen, recordlen;
memset(lth, 0, sizeof(struct lvdstableheader));
if (bios->fp.lvdsmanufacturerpointer == 0x0) {
NV_ERROR(dev, "Pointer to LVDS manufacturer table invalid\n");
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
NV_ERROR(dev, "LVDS table header not understood\n");
return -EINVAL;
}
recordlen = bios->data[bios->fp.lvdsmanufacturerpointer + 2];
break;
case 0x40:
headerlen = bios->data[bios->fp.lvdsmanufacturerpointer + 1];
if (headerlen < 0x7) {
NV_ERROR(dev, "LVDS table header not understood\n");
return -EINVAL;
}
recordlen = bios->data[bios->fp.lvdsmanufacturerpointer + 2];
break;
default:
NV_ERROR(dev,
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
struct drm_nouveau_private *dev_priv = dev->dev_private;
if (bios->major_version < 5 && bios->data[0x48] & 0x4)
return NVReadVgaCrtc5758(dev, 0, 0xf) & 0xf;
if (dev_priv->card_type >= NV_50)
return (bios_rd32(bios, NV_PEXTDEV_BOOT_0) >> 24) & 0xf;
else
return (bios_rd32(bios, NV_PEXTDEV_BOOT_0) >> 16) & 0xf;
}
static int parse_fp_mode_table(struct drm_device *dev, struct nvbios *bios)
{
uint8_t *fptable;
uint8_t fptable_ver, headerlen = 0, recordlen, fpentries = 0xf, fpindex;
int ret, ofs, fpstrapping;
struct lvdstableheader lth;
if (bios->fp.fptablepointer == 0x0) {
#ifndef __powerpc__
NV_ERROR(dev, "Pointer to flat panel table invalid\n");
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
NV_ERROR(dev,
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
NV_ERROR(dev, "Pointer to flat panel xlat table invalid\n");
return -EINVAL;
}
fpstrapping = get_fp_strap(dev, bios);
fpindex = bios->data[bios->fp.fpxlatetableptr +
fpstrapping * bios->fp.xlatwidth];
if (fpindex > fpentries) {
NV_ERROR(dev, "Bad flat panel table index\n");
return -ENOENT;
}
if (lth.lvds_ver > 0x10)
bios->fp_no_ddc = fpstrapping != 0xf || fpindex != 0xf;
if (fpstrapping == 0xf || fpindex == 0xf)
return 0;
bios->fp.mode_ptr = bios->fp.fptablepointer + headerlen +
recordlen * fpindex + ofs;
NV_TRACE(dev, "BIOS FP mode: %dx%d (%dkHz pixel clock)\n",
ROM16(bios->data[bios->fp.mode_ptr + 11]) + 1,
ROM16(bios->data[bios->fp.mode_ptr + 25]) + 1,
ROM16(bios->data[bios->fp.mode_ptr + 7]) * 10);
return 0;
}
bool nouveau_bios_fp_mode(struct drm_device *dev, struct drm_display_mode *mode)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
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
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
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
NV_ERROR(dev, "LVDS table revision not currently supported\n");
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
if (nv_match_device(dev, 0x01d7, 0x1028, 0x01c2))
bios->fp.duallink_transition_clk = 80000;
if (pxclk && (chip_version < 0x25 || chip_version > 0x28))
bios->fp.dual_link = (pxclk >= bios->fp.duallink_transition_clk);
*dl = bios->fp.dual_link;
return 0;
}
static uint8_t *
bios_output_config_match(struct drm_device *dev, struct dcb_entry *dcbent,
uint16_t record, int record_len, int record_nr,
bool match_link)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
uint32_t entry;
uint16_t table;
int i, v;
switch (dcbent->type) {
case OUTPUT_TMDS:
case OUTPUT_LVDS:
case OUTPUT_DP:
break;
default:
match_link = false;
break;
}
for (i = 0; i < record_nr; i++, record += record_len) {
table = ROM16(bios->data[record]);
if (!table)
continue;
entry = ROM32(bios->data[table]);
if (match_link) {
v = (entry & 0x00c00000) >> 22;
if (!(v & dcbent->sorconf.link))
continue;
}
v = (entry & 0x000f0000) >> 16;
if (!(v & dcbent->or))
continue;
v = (entry & 0x000000f0) >> 4;
if (v != dcbent->location)
continue;
v = (entry & 0x0000000f);
if (v != dcbent->type)
continue;
return &bios->data[table];
}
return NULL;
}
void *
nouveau_bios_dp_table(struct drm_device *dev, struct dcb_entry *dcbent,
int *length)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
uint8_t *table;
if (!bios->display.dp_table_ptr) {
NV_ERROR(dev, "No pointer to DisplayPort table\n");
return NULL;
}
table = &bios->data[bios->display.dp_table_ptr];
if (table[0] != 0x20 && table[0] != 0x21) {
NV_ERROR(dev, "DisplayPort table version 0x%02x unknown\n",
table[0]);
return NULL;
}
*length = table[4];
return bios_output_config_match(dev, dcbent,
bios->display.dp_table_ptr + table[1],
table[2], table[3], table[0] >= 0x21);
}
int
nouveau_bios_run_display_table(struct drm_device *dev, struct dcb_entry *dcbent,
uint32_t sub, int pxclk)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
uint8_t *table = &bios->data[bios->display.script_table_ptr];
uint8_t *otable = NULL;
uint16_t script;
int i = 0;
if (!bios->display.script_table_ptr) {
NV_ERROR(dev, "No pointer to output script table\n");
return 1;
}
if (table[0] < 0x20)
return 1;
if (table[0] != 0x20 && table[0] != 0x21) {
NV_ERROR(dev, "Output script table version 0x%02x unknown\n",
table[0]);
return 1;
}
NV_DEBUG_KMS(dev, "Searching for output entry for %d %d %d\n",
dcbent->type, dcbent->location, dcbent->or);
otable = bios_output_config_match(dev, dcbent, table[1] +
bios->display.script_table_ptr,
table[2], table[3], table[0] >= 0x21);
if (!otable) {
NV_DEBUG_KMS(dev, "failed to match any output table\n");
return 1;
}
if (pxclk < -2 || pxclk > 0) {
for (i = 0; i < otable[5]; i++) {
if (ROM16(otable[table[4] + i*6]) == sub)
break;
}
if (i == otable[5]) {
NV_ERROR(dev, "Table 0x%04x not found for %d/%d, "
"using first\n",
sub, dcbent->type, dcbent->or);
i = 0;
}
}
if (pxclk == 0) {
script = ROM16(otable[6]);
if (!script) {
NV_DEBUG_KMS(dev, "output script 0 not found\n");
return 1;
}
NV_DEBUG_KMS(dev, "0x%04X: parsing output script 0\n", script);
nouveau_bios_run_init_table(dev, script, dcbent);
} else
if (pxclk == -1) {
script = ROM16(otable[8]);
if (!script) {
NV_DEBUG_KMS(dev, "output script 1 not found\n");
return 1;
}
NV_DEBUG_KMS(dev, "0x%04X: parsing output script 1\n", script);
nouveau_bios_run_init_table(dev, script, dcbent);
} else
if (pxclk == -2) {
if (table[4] >= 12)
script = ROM16(otable[10]);
else
script = 0;
if (!script) {
NV_DEBUG_KMS(dev, "output script 2 not found\n");
return 1;
}
NV_DEBUG_KMS(dev, "0x%04X: parsing output script 2\n", script);
nouveau_bios_run_init_table(dev, script, dcbent);
} else
if (pxclk > 0) {
script = ROM16(otable[table[4] + i*6 + 2]);
if (script)
script = clkcmptable(bios, script, pxclk);
if (!script) {
NV_DEBUG_KMS(dev, "clock script 0 not found\n");
return 1;
}
NV_DEBUG_KMS(dev, "0x%04X: parsing clock script 0\n", script);
nouveau_bios_run_init_table(dev, script, dcbent);
} else
if (pxclk < 0) {
script = ROM16(otable[table[4] + i*6 + 4]);
if (script)
script = clkcmptable(bios, script, -pxclk);
if (!script) {
NV_DEBUG_KMS(dev, "clock script 1 not found\n");
return 1;
}
NV_DEBUG_KMS(dev, "0x%04X: parsing clock script 1\n", script);
nouveau_bios_run_init_table(dev, script, dcbent);
}
return 0;
}
int run_tmds_table(struct drm_device *dev, struct dcb_entry *dcbent, int head, int pxclk)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
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
NV_ERROR(dev, "Pixel clock comparison table not found\n");
return -EINVAL;
}
scriptptr = clkcmptable(bios, clktable, pxclk);
if (!scriptptr) {
NV_ERROR(dev, "TMDS output init script not found\n");
return -ENOENT;
}
sel_clk_binding = bios_rd32(bios, NV_PRAMDAC_SEL_CLK) & 0x50000;
run_digital_op_script(dev, scriptptr, dcbent, head, pxclk >= 165000);
sel_clk = NVReadRAMDAC(dev, 0, NV_PRAMDAC_SEL_CLK) & ~0x50000;
NVWriteRAMDAC(dev, 0, NV_PRAMDAC_SEL_CLK, sel_clk | sel_clk_binding);
return 0;
}
u32
get_pll_register(struct drm_device *dev, enum pll_types type)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
struct pll_mapping *map;
int i;
if (dev_priv->card_type < NV_40)
map = nv04_pll_mapping;
else
if (dev_priv->card_type < NV_50)
map = nv40_pll_mapping;
else {
u8 *plim = &bios->data[bios->pll_limit_tbl_ptr];
if (plim[0] >= 0x30) {
u8 *entry = plim + plim[1];
for (i = 0; i < plim[3]; i++, entry += plim[2]) {
if (entry[0] == type)
return ROM32(entry[3]);
}
return 0;
}
if (dev_priv->chipset == 0x50)
map = nv50_pll_mapping;
else
map = nv84_pll_mapping;
}
while (map->reg) {
if (map->type == type)
return map->reg;
map++;
}
return 0;
}
int get_pll_limits(struct drm_device *dev, uint32_t limit_match, struct pll_lims *pll_lim)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
int cv = bios->chip_version, pllindex = 0;
uint8_t pll_lim_ver = 0, headerlen = 0, recordlen = 0, entries = 0;
uint32_t crystal_strap_mask, crystal_straps;
if (!bios->pll_limit_tbl_ptr) {
if (cv == 0x30 || cv == 0x31 || cv == 0x35 || cv == 0x36 ||
cv >= 0x40) {
NV_ERROR(dev, "Pointer to PLL limits table invalid\n");
return -EINVAL;
}
} else
pll_lim_ver = bios->data[bios->pll_limit_tbl_ptr];
crystal_strap_mask = 1 << 6;
if (cv > 0x10 && cv != 0x15 && cv != 0x1a && cv != 0x20)
crystal_strap_mask |= 1 << 22;
crystal_straps = nvReadEXTDEV(dev, NV_PEXTDEV_BOOT_0) &
crystal_strap_mask;
switch (pll_lim_ver) {
case 0:
break;
case 0x10:
case 0x11:
headerlen = 1;
recordlen = 0x18;
entries = 1;
pllindex = 0;
break;
case 0x20:
case 0x21:
case 0x30:
case 0x40:
headerlen = bios->data[bios->pll_limit_tbl_ptr + 1];
recordlen = bios->data[bios->pll_limit_tbl_ptr + 2];
entries = bios->data[bios->pll_limit_tbl_ptr + 3];
break;
default:
NV_ERROR(dev, "PLL limits table revision 0x%X not currently "
"supported\n", pll_lim_ver);
return -ENOSYS;
}
memset(pll_lim, 0, sizeof(struct pll_lims));
if (limit_match > PLL_MAX)
pll_lim->reg = limit_match;
else {
pll_lim->reg = get_pll_register(dev, limit_match);
if (!pll_lim->reg)
return -ENOENT;
}
if (pll_lim_ver == 0x10 || pll_lim_ver == 0x11) {
uint8_t *pll_rec = &bios->data[bios->pll_limit_tbl_ptr + headerlen + recordlen * pllindex];
pll_lim->vco1.minfreq = ROM32(pll_rec[0]);
pll_lim->vco1.maxfreq = ROM32(pll_rec[4]);
pll_lim->vco2.minfreq = ROM32(pll_rec[8]);
pll_lim->vco2.maxfreq = ROM32(pll_rec[12]);
pll_lim->vco1.min_inputfreq = ROM32(pll_rec[16]);
pll_lim->vco2.min_inputfreq = ROM32(pll_rec[20]);
pll_lim->vco1.max_inputfreq = pll_lim->vco2.max_inputfreq = INT_MAX;
pll_lim->vco1.min_n = 0x1;
if (cv == 0x36)
pll_lim->vco1.min_n = 0x5;
pll_lim->vco1.max_n = 0xff;
pll_lim->vco1.min_m = 0x1;
pll_lim->vco1.max_m = 0xd;
pll_lim->vco2.min_n = 0x4;
pll_lim->vco2.max_n = 0x28;
if (cv == 0x30 || cv == 0x35)
pll_lim->vco2.max_n = 0x1f;
pll_lim->vco2.min_m = 0x1;
pll_lim->vco2.max_m = 0x4;
pll_lim->max_log2p = 0x7;
pll_lim->max_usable_log2p = 0x6;
} else if (pll_lim_ver == 0x20 || pll_lim_ver == 0x21) {
uint16_t plloffs = bios->pll_limit_tbl_ptr + headerlen;
uint8_t *pll_rec;
int i;
if (ROM32(bios->data[plloffs]))
NV_WARN(dev, "Default PLL limit entry has non-zero "
"register field\n");
for (i = 1; i < entries; i++)
if (ROM32(bios->data[plloffs + recordlen * i]) == pll_lim->reg) {
pllindex = i;
break;
}
if ((dev_priv->card_type >= NV_50) && (pllindex == 0)) {
NV_ERROR(dev, "Register 0x%08x not found in PLL "
"limits table", pll_lim->reg);
return -ENOENT;
}
pll_rec = &bios->data[plloffs + recordlen * pllindex];
BIOSLOG(bios, "Loading PLL limits for reg 0x%08x\n",
pllindex ? pll_lim->reg : 0);
pll_lim->vco1.minfreq = ROM16(pll_rec[4]) * 1000;
pll_lim->vco1.maxfreq = ROM16(pll_rec[6]) * 1000;
pll_lim->vco2.minfreq = ROM16(pll_rec[8]) * 1000;
pll_lim->vco2.maxfreq = ROM16(pll_rec[10]) * 1000;
pll_lim->vco1.min_inputfreq = ROM16(pll_rec[12]) * 1000;
pll_lim->vco2.min_inputfreq = ROM16(pll_rec[14]) * 1000;
pll_lim->vco1.max_inputfreq = ROM16(pll_rec[16]) * 1000;
pll_lim->vco2.max_inputfreq = ROM16(pll_rec[18]) * 1000;
pll_lim->vco1.min_n = pll_rec[20];
pll_lim->vco1.max_n = pll_rec[21];
pll_lim->vco1.min_m = pll_rec[22];
pll_lim->vco1.max_m = pll_rec[23];
pll_lim->vco2.min_n = pll_rec[24];
pll_lim->vco2.max_n = pll_rec[25];
pll_lim->vco2.min_m = pll_rec[26];
pll_lim->vco2.max_m = pll_rec[27];
pll_lim->max_usable_log2p = pll_lim->max_log2p = pll_rec[29];
if (pll_lim->max_log2p > 0x7)
NV_WARN(dev, "Max log2 P value greater than 7 (%d)\n",
pll_lim->max_log2p);
if (cv < 0x60)
pll_lim->max_usable_log2p = 0x6;
pll_lim->log2p_bias = pll_rec[30];
if (recordlen > 0x22)
pll_lim->refclk = ROM32(pll_rec[31]);
if (recordlen > 0x23 && pll_rec[35])
NV_WARN(dev,
"Bits set in PLL configuration byte (%x)\n",
pll_rec[35]);
if (cv == 0x51 && !pll_lim->refclk) {
uint32_t sel_clk = bios_rd32(bios, NV_PRAMDAC_SEL_CLK);
if ((pll_lim->reg == NV_PRAMDAC_VPLL_COEFF && sel_clk & 0x20) ||
(pll_lim->reg == NV_RAMDAC_VPLL2 && sel_clk & 0x80)) {
if (bios_idxprt_rd(bios, NV_CIO_CRX__COLOR, NV_CIO_CRE_CHIP_ID_INDEX) < 0xa3)
pll_lim->refclk = 200000;
else
pll_lim->refclk = 25000;
}
}
} else if (pll_lim_ver == 0x30) {
uint8_t *entry = &bios->data[bios->pll_limit_tbl_ptr + headerlen];
uint8_t *record = NULL;
int i;
BIOSLOG(bios, "Loading PLL limits for register 0x%08x\n",
pll_lim->reg);
for (i = 0; i < entries; i++, entry += recordlen) {
if (ROM32(entry[3]) == pll_lim->reg) {
record = &bios->data[ROM16(entry[1])];
break;
}
}
if (!record) {
NV_ERROR(dev, "Register 0x%08x not found in PLL "
"limits table", pll_lim->reg);
return -ENOENT;
}
pll_lim->vco1.minfreq = ROM16(record[0]) * 1000;
pll_lim->vco1.maxfreq = ROM16(record[2]) * 1000;
pll_lim->vco2.minfreq = ROM16(record[4]) * 1000;
pll_lim->vco2.maxfreq = ROM16(record[6]) * 1000;
pll_lim->vco1.min_inputfreq = ROM16(record[8]) * 1000;
pll_lim->vco2.min_inputfreq = ROM16(record[10]) * 1000;
pll_lim->vco1.max_inputfreq = ROM16(record[12]) * 1000;
pll_lim->vco2.max_inputfreq = ROM16(record[14]) * 1000;
pll_lim->vco1.min_n = record[16];
pll_lim->vco1.max_n = record[17];
pll_lim->vco1.min_m = record[18];
pll_lim->vco1.max_m = record[19];
pll_lim->vco2.min_n = record[20];
pll_lim->vco2.max_n = record[21];
pll_lim->vco2.min_m = record[22];
pll_lim->vco2.max_m = record[23];
pll_lim->max_usable_log2p = pll_lim->max_log2p = record[25];
pll_lim->log2p_bias = record[27];
pll_lim->refclk = ROM32(record[28]);
} else if (pll_lim_ver) {
uint8_t *entry = &bios->data[bios->pll_limit_tbl_ptr + headerlen];
uint8_t *record = NULL;
int i;
BIOSLOG(bios, "Loading PLL limits for register 0x%08x\n",
pll_lim->reg);
for (i = 0; i < entries; i++, entry += recordlen) {
if (ROM32(entry[3]) == pll_lim->reg) {
record = &bios->data[ROM16(entry[1])];
break;
}
}
if (!record) {
NV_ERROR(dev, "Register 0x%08x not found in PLL "
"limits table", pll_lim->reg);
return -ENOENT;
}
pll_lim->vco1.minfreq = ROM16(record[0]) * 1000;
pll_lim->vco1.maxfreq = ROM16(record[2]) * 1000;
pll_lim->vco1.min_inputfreq = ROM16(record[4]) * 1000;
pll_lim->vco1.max_inputfreq = ROM16(record[6]) * 1000;
pll_lim->vco1.min_m = record[8];
pll_lim->vco1.max_m = record[9];
pll_lim->vco1.min_n = record[10];
pll_lim->vco1.max_n = record[11];
pll_lim->min_p = record[12];
pll_lim->max_p = record[13];
pll_lim->refclk = ROM16(entry[9]) * 1000;
}
if (!pll_lim->vco1.maxfreq) {
pll_lim->vco1.minfreq = bios->fminvco;
pll_lim->vco1.maxfreq = bios->fmaxvco;
pll_lim->vco1.min_inputfreq = 0;
pll_lim->vco1.max_inputfreq = INT_MAX;
pll_lim->vco1.min_n = 0x1;
pll_lim->vco1.max_n = 0xff;
pll_lim->vco1.min_m = 0x1;
if (crystal_straps == 0) {
if (cv < 0x11)
pll_lim->vco1.min_m = 0x7;
pll_lim->vco1.max_m = 0xd;
} else {
if (cv < 0x11)
pll_lim->vco1.min_m = 0x8;
pll_lim->vco1.max_m = 0xe;
}
if (cv < 0x17 || cv == 0x1a || cv == 0x20)
pll_lim->max_log2p = 4;
else
pll_lim->max_log2p = 5;
pll_lim->max_usable_log2p = pll_lim->max_log2p;
}
if (!pll_lim->refclk)
switch (crystal_straps) {
case 0:
pll_lim->refclk = 13500;
break;
case (1 << 6):
pll_lim->refclk = 14318;
break;
case (1 << 22):
pll_lim->refclk = 27000;
break;
case (1 << 22 | 1 << 6):
pll_lim->refclk = 25000;
break;
}
NV_DEBUG(dev, "pll.vco1.minfreq: %d\n", pll_lim->vco1.minfreq);
NV_DEBUG(dev, "pll.vco1.maxfreq: %d\n", pll_lim->vco1.maxfreq);
NV_DEBUG(dev, "pll.vco1.min_inputfreq: %d\n", pll_lim->vco1.min_inputfreq);
NV_DEBUG(dev, "pll.vco1.max_inputfreq: %d\n", pll_lim->vco1.max_inputfreq);
NV_DEBUG(dev, "pll.vco1.min_n: %d\n", pll_lim->vco1.min_n);
NV_DEBUG(dev, "pll.vco1.max_n: %d\n", pll_lim->vco1.max_n);
NV_DEBUG(dev, "pll.vco1.min_m: %d\n", pll_lim->vco1.min_m);
NV_DEBUG(dev, "pll.vco1.max_m: %d\n", pll_lim->vco1.max_m);
if (pll_lim->vco2.maxfreq) {
NV_DEBUG(dev, "pll.vco2.minfreq: %d\n", pll_lim->vco2.minfreq);
NV_DEBUG(dev, "pll.vco2.maxfreq: %d\n", pll_lim->vco2.maxfreq);
NV_DEBUG(dev, "pll.vco2.min_inputfreq: %d\n", pll_lim->vco2.min_inputfreq);
NV_DEBUG(dev, "pll.vco2.max_inputfreq: %d\n", pll_lim->vco2.max_inputfreq);
NV_DEBUG(dev, "pll.vco2.min_n: %d\n", pll_lim->vco2.min_n);
NV_DEBUG(dev, "pll.vco2.max_n: %d\n", pll_lim->vco2.max_n);
NV_DEBUG(dev, "pll.vco2.min_m: %d\n", pll_lim->vco2.min_m);
NV_DEBUG(dev, "pll.vco2.max_m: %d\n", pll_lim->vco2.max_m);
}
if (!pll_lim->max_p) {
NV_DEBUG(dev, "pll.max_log2p: %d\n", pll_lim->max_log2p);
NV_DEBUG(dev, "pll.log2p_bias: %d\n", pll_lim->log2p_bias);
} else {
NV_DEBUG(dev, "pll.min_p: %d\n", pll_lim->min_p);
NV_DEBUG(dev, "pll.max_p: %d\n", pll_lim->max_p);
}
NV_DEBUG(dev, "pll.refclk: %d\n", pll_lim->refclk);
return 0;
}
static void parse_bios_version(struct drm_device *dev, struct nvbios *bios, uint16_t offset)
{
bios->major_version = bios->data[offset + 3];
bios->chip_version = bios->data[offset + 2];
NV_TRACE(dev, "Bios version %02x.%02x.%02x.%02x\n",
bios->data[offset + 3], bios->data[offset + 2],
bios->data[offset + 1], bios->data[offset]);
}
static void parse_script_table_pointers(struct nvbios *bios, uint16_t offset)
{
bios->init_script_tbls_ptr = ROM16(bios->data[offset]);
bios->macro_index_tbl_ptr = ROM16(bios->data[offset + 2]);
bios->macro_tbl_ptr = ROM16(bios->data[offset + 4]);
bios->condition_tbl_ptr = ROM16(bios->data[offset + 6]);
bios->io_condition_tbl_ptr = ROM16(bios->data[offset + 8]);
bios->io_flag_condition_tbl_ptr = ROM16(bios->data[offset + 10]);
bios->init_function_tbl_ptr = ROM16(bios->data[offset + 12]);
}
static int parse_bit_A_tbl_entry(struct drm_device *dev, struct nvbios *bios, struct bit_entry *bitentry)
{
uint16_t load_table_ptr;
uint8_t version, headerlen, entrylen, num_entries;
if (bitentry->length != 3) {
NV_ERROR(dev, "Do not understand BIT A table\n");
return -EINVAL;
}
load_table_ptr = ROM16(bios->data[bitentry->offset]);
if (load_table_ptr == 0x0) {
NV_ERROR(dev, "Pointer to BIT loadval table invalid\n");
return -EINVAL;
}
version = bios->data[load_table_ptr];
if (version != 0x10) {
NV_ERROR(dev, "BIT loadval table version %d.%d not supported\n",
version >> 4, version & 0xF);
return -ENOSYS;
}
headerlen = bios->data[load_table_ptr + 1];
entrylen = bios->data[load_table_ptr + 2];
num_entries = bios->data[load_table_ptr + 3];
if (headerlen != 4 || entrylen != 4 || num_entries != 2) {
NV_ERROR(dev, "Do not understand BIT loadval table\n");
return -EINVAL;
}
bios->dactestval = ROM32(bios->data[load_table_ptr + headerlen]) & 0x3ff;
return 0;
}
static int parse_bit_C_tbl_entry(struct drm_device *dev, struct nvbios *bios, struct bit_entry *bitentry)
{
if (bitentry->length < 10) {
NV_ERROR(dev, "Do not understand BIT C table\n");
return -EINVAL;
}
bios->pll_limit_tbl_ptr = ROM16(bios->data[bitentry->offset + 8]);
return 0;
}
static int parse_bit_display_tbl_entry(struct drm_device *dev, struct nvbios *bios, struct bit_entry *bitentry)
{
if (bitentry->length != 4) {
NV_ERROR(dev, "Do not understand BIT display table\n");
return -EINVAL;
}
bios->fp.fptablepointer = ROM16(bios->data[bitentry->offset + 2]);
return 0;
}
static int parse_bit_init_tbl_entry(struct drm_device *dev, struct nvbios *bios, struct bit_entry *bitentry)
{
if (bitentry->length < 14) {
NV_ERROR(dev, "Do not understand init table\n");
return -EINVAL;
}
parse_script_table_pointers(bios, bitentry->offset);
if (bitentry->length >= 16)
bios->some_script_ptr = ROM16(bios->data[bitentry->offset + 14]);
if (bitentry->length >= 18)
bios->init96_tbl_ptr = ROM16(bios->data[bitentry->offset + 16]);
return 0;
}
static int parse_bit_i_tbl_entry(struct drm_device *dev, struct nvbios *bios, struct bit_entry *bitentry)
{
uint16_t daccmpoffset;
uint8_t dacver, dacheaderlen;
if (bitentry->length < 6) {
NV_ERROR(dev, "BIT i table too short for needed information\n");
return -EINVAL;
}
parse_bios_version(dev, bios, bitentry->offset);
bios->feature_byte = bios->data[bitentry->offset + 5];
bios->is_mobile = bios->feature_byte & FEATURE_MOBILE;
if (bitentry->length < 15) {
NV_WARN(dev, "BIT i table not long enough for DAC load "
"detection comparison table\n");
return -EINVAL;
}
daccmpoffset = ROM16(bios->data[bitentry->offset + 13]);
if (!daccmpoffset)
return 0;
dacver = bios->data[daccmpoffset];
dacheaderlen = bios->data[daccmpoffset + 1];
if (dacver != 0x00 && dacver != 0x10) {
NV_WARN(dev, "DAC load detection comparison table version "
"%d.%d not known\n", dacver >> 4, dacver & 0xf);
return -ENOSYS;
}
bios->dactestval = ROM32(bios->data[daccmpoffset + dacheaderlen]);
bios->tvdactestval = ROM32(bios->data[daccmpoffset + dacheaderlen + 4]);
return 0;
}
static int parse_bit_lvds_tbl_entry(struct drm_device *dev, struct nvbios *bios, struct bit_entry *bitentry)
{
if (bitentry->length != 2) {
NV_ERROR(dev, "Do not understand BIT LVDS table\n");
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
uint16_t tmdstableptr, script1, script2;
if (bitentry->length != 2) {
NV_ERROR(dev, "Do not understand BIT TMDS table\n");
return -EINVAL;
}
tmdstableptr = ROM16(bios->data[bitentry->offset]);
if (!tmdstableptr) {
NV_ERROR(dev, "Pointer to TMDS table invalid\n");
return -EINVAL;
}
NV_INFO(dev, "TMDS table version %d.%d\n",
bios->data[tmdstableptr] >> 4, bios->data[tmdstableptr] & 0xf);
if (bios->data[tmdstableptr] != 0x11)
return -ENOSYS;
script1 = ROM16(bios->data[tmdstableptr + 7]);
script2 = ROM16(bios->data[tmdstableptr + 9]);
if (bios->data[script1] != 'q' || bios->data[script2] != 'q')
NV_WARN(dev, "TMDS table script pointers not stubbed\n");
bios->tmds.output0_script_ptr = ROM16(bios->data[tmdstableptr + 11]);
bios->tmds.output1_script_ptr = ROM16(bios->data[tmdstableptr + 13]);
return 0;
}
static int
parse_bit_U_tbl_entry(struct drm_device *dev, struct nvbios *bios,
struct bit_entry *bitentry)
{
uint16_t outputscripttableptr;
if (bitentry->length != 3) {
NV_ERROR(dev, "Do not understand BIT U table\n");
return -EINVAL;
}
outputscripttableptr = ROM16(bios->data[bitentry->offset]);
bios->display.script_table_ptr = outputscripttableptr;
return 0;
}
static int
parse_bit_displayport_tbl_entry(struct drm_device *dev, struct nvbios *bios,
struct bit_entry *bitentry)
{
bios->display.dp_table_ptr = ROM16(bios->data[bitentry->offset]);
return 0;
}
int
bit_table(struct drm_device *dev, u8 id, struct bit_entry *bit)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
u8 entries, *entry;
entries = bios->data[bios->offset + 10];
entry = &bios->data[bios->offset + 12];
while (entries--) {
if (entry[0] == id) {
bit->id = entry[0];
bit->version = entry[1];
bit->length = ROM16(entry[2]);
bit->offset = ROM16(entry[4]);
bit->data = ROMPTR(bios, entry[4]);
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
struct bit_entry bitentry;
if (bit_table(dev, table->id, &bitentry) == 0)
return table->parse_fn(dev, bios, &bitentry);
NV_INFO(dev, "BIT table '%c' not found\n", table->id);
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
ret = parse_bit_table(bios, bitoffset, &BIT_TABLE('C', C));
if (ret)
return ret;
parse_bit_table(bios, bitoffset, &BIT_TABLE('D', display));
ret = parse_bit_table(bios, bitoffset, &BIT_TABLE('I', init));
if (ret)
return ret;
parse_bit_table(bios, bitoffset, &BIT_TABLE('M', M));
parse_bit_table(bios, bitoffset, &BIT_TABLE('L', lvds));
parse_bit_table(bios, bitoffset, &BIT_TABLE('T', tmds));
parse_bit_table(bios, bitoffset, &BIT_TABLE('U', U));
parse_bit_table(bios, bitoffset, &BIT_TABLE('d', displayport));
return 0;
}
static int parse_bmp_structure(struct drm_device *dev, struct nvbios *bios, unsigned int offset)
{
uint8_t *bmp = &bios->data[offset], bmp_version_major, bmp_version_minor;
uint16_t bmplength;
uint16_t legacy_scripts_offset, legacy_i2c_offset;
bios->dcb.i2c[0].write = NV_CIO_CRE_DDC_WR__INDEX;
bios->dcb.i2c[0].read = NV_CIO_CRE_DDC_STATUS__INDEX;
bios->dcb.i2c[1].write = NV_CIO_CRE_DDC0_WR__INDEX;
bios->dcb.i2c[1].read = NV_CIO_CRE_DDC0_STATUS__INDEX;
bios->digital_min_front_porch = 0x4b;
bios->fmaxvco = 256000;
bios->fminvco = 128000;
bios->fp.duallink_transition_clk = 90000;
bmp_version_major = bmp[5];
bmp_version_minor = bmp[6];
NV_TRACE(dev, "BMP version %d.%d\n",
bmp_version_major, bmp_version_minor);
if (bmp_version_major < 5)
*(uint16_t *)&bios->data[0x36] = 0;
if ((bmp_version_major < 5 && bmp_version_minor != 1) || bmp_version_major > 5) {
NV_ERROR(dev, "You have an unsupported BMP version. "
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
NV_ERROR(dev, "Bad BMP checksum\n");
return -EINVAL;
}
bios->feature_byte = bmp[9];
parse_bios_version(dev, bios, offset + 10);
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
if (bios->data[legacy_i2c_offset + 4])
bios->dcb.i2c[0].write = bios->data[legacy_i2c_offset + 4];
if (bios->data[legacy_i2c_offset + 5])
bios->dcb.i2c[0].read = bios->data[legacy_i2c_offset + 5];
if (bios->data[legacy_i2c_offset + 6])
bios->dcb.i2c[1].write = bios->data[legacy_i2c_offset + 6];
if (bios->data[legacy_i2c_offset + 7])
bios->dcb.i2c[1].read = bios->data[legacy_i2c_offset + 7];
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
if (bmplength > 143)
bios->pll_limit_tbl_ptr = ROM16(bmp[142]);
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
static struct dcb_gpio_entry *
new_gpio_entry(struct nvbios *bios)
{
struct drm_device *dev = bios->dev;
struct dcb_gpio_table *gpio = &bios->dcb.gpio;
if (gpio->entries >= DCB_MAX_NUM_GPIO_ENTRIES) {
NV_ERROR(dev, "exceeded maximum number of gpio entries!!\n");
return NULL;
}
return &gpio->entry[gpio->entries++];
}
struct dcb_gpio_entry *
nouveau_bios_gpio_entry(struct drm_device *dev, enum dcb_gpio_tag tag)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
int i;
for (i = 0; i < bios->dcb.gpio.entries; i++) {
if (bios->dcb.gpio.entry[i].tag != tag)
continue;
return &bios->dcb.gpio.entry[i];
}
return NULL;
}
static void
parse_dcb_gpio_table(struct nvbios *bios)
{
struct drm_device *dev = bios->dev;
struct dcb_gpio_entry *e;
u8 headerlen, entries, recordlen;
u8 *dcb, *gpio = NULL, *entry;
int i;
dcb = ROMPTR(bios, bios->data[0x36]);
if (dcb[0] >= 0x30) {
gpio = ROMPTR(bios, dcb[10]);
if (!gpio)
goto no_table;
headerlen = gpio[1];
entries = gpio[2];
recordlen = gpio[3];
} else
if (dcb[0] >= 0x22 && dcb[-1] >= 0x13) {
gpio = ROMPTR(bios, dcb[-15]);
if (!gpio)
goto no_table;
headerlen = 3;
entries = gpio[2];
recordlen = gpio[1];
} else
if (dcb[0] >= 0x22) {
uint8_t *tvdac_gpio = &dcb[-5];
if (tvdac_gpio[0] & 1) {
e = new_gpio_entry(bios);
e->tag = DCB_GPIO_TVDAC0;
e->line = tvdac_gpio[1] >> 4;
e->invert = tvdac_gpio[0] & 2;
}
goto no_table;
} else {
NV_DEBUG(dev, "no/unknown gpio table on DCB 0x%02x\n", dcb[0]);
goto no_table;
}
entry = gpio + headerlen;
for (i = 0; i < entries; i++, entry += recordlen) {
e = new_gpio_entry(bios);
if (!e)
break;
if (gpio[0] < 0x40) {
e->entry = ROM16(entry[0]);
e->tag = (e->entry & 0x07e0) >> 5;
if (e->tag == 0x3f) {
bios->dcb.gpio.entries--;
continue;
}
e->line = (e->entry & 0x001f);
e->invert = ((e->entry & 0xf800) >> 11) != 4;
} else {
e->entry = ROM32(entry[0]);
e->tag = (e->entry & 0x0000ff00) >> 8;
if (e->tag == 0xff) {
bios->dcb.gpio.entries--;
continue;
}
e->line = (e->entry & 0x0000001f) >> 0;
e->state_default = (e->entry & 0x01000000) >> 24;
e->state[0] = (e->entry & 0x18000000) >> 27;
e->state[1] = (e->entry & 0x60000000) >> 29;
}
}
no_table:
if (nv_match_device(dev, 0x0189, 0x10de, 0x0010)) {
e = new_gpio_entry(bios);
if (e) {
e->tag = DCB_GPIO_TVDAC0;
e->line = 4;
}
}
}
struct dcb_connector_table_entry *
nouveau_bios_connector_entry(struct drm_device *dev, int index)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
struct dcb_connector_table_entry *cte;
if (index >= bios->dcb.connector.entries)
return NULL;
cte = &bios->dcb.connector.entry[index];
if (cte->type == 0xff)
return NULL;
return cte;
}
static enum dcb_connector_type
divine_connector_type(struct nvbios *bios, int index)
{
struct dcb_table *dcb = &bios->dcb;
unsigned encoders = 0, type = DCB_CONNECTOR_NONE;
int i;
for (i = 0; i < dcb->entries; i++) {
if (dcb->entry[i].connector == index)
encoders |= (1 << dcb->entry[i].type);
}
if (encoders & (1 << OUTPUT_DP)) {
if (encoders & (1 << OUTPUT_TMDS))
type = DCB_CONNECTOR_DP;
else
type = DCB_CONNECTOR_eDP;
} else
if (encoders & (1 << OUTPUT_TMDS)) {
if (encoders & (1 << OUTPUT_ANALOG))
type = DCB_CONNECTOR_DVI_I;
else
type = DCB_CONNECTOR_DVI_D;
} else
if (encoders & (1 << OUTPUT_ANALOG)) {
type = DCB_CONNECTOR_VGA;
} else
if (encoders & (1 << OUTPUT_LVDS)) {
type = DCB_CONNECTOR_LVDS;
} else
if (encoders & (1 << OUTPUT_TV)) {
type = DCB_CONNECTOR_TV_0;
}
return type;
}
static void
apply_dcb_connector_quirks(struct nvbios *bios, int idx)
{
struct dcb_connector_table_entry *cte = &bios->dcb.connector.entry[idx];
struct drm_device *dev = bios->dev;
if (nv_match_device(dev, 0x0421, 0x1458, 0x344c)) {
if (cte->type == DCB_CONNECTOR_HDMI_1)
cte->type = DCB_CONNECTOR_DVI_I;
}
}
static void
parse_dcb_connector_table(struct nvbios *bios)
{
struct drm_device *dev = bios->dev;
struct dcb_connector_table *ct = &bios->dcb.connector;
struct dcb_connector_table_entry *cte;
uint8_t *conntab = &bios->data[bios->dcb.connector_table_ptr];
uint8_t *entry;
int i;
if (!bios->dcb.connector_table_ptr) {
NV_DEBUG_KMS(dev, "No DCB connector table present\n");
return;
}
NV_INFO(dev, "DCB connector table: VHER 0x%02x %d %d %d\n",
conntab[0], conntab[1], conntab[2], conntab[3]);
if ((conntab[0] != 0x30 && conntab[0] != 0x40) ||
(conntab[3] != 2 && conntab[3] != 4)) {
NV_ERROR(dev, " Unknown! Please report.\n");
return;
}
ct->entries = conntab[2];
entry = conntab + conntab[1];
cte = &ct->entry[0];
for (i = 0; i < conntab[2]; i++, entry += conntab[3], cte++) {
cte->index = i;
if (conntab[3] == 2)
cte->entry = ROM16(entry[0]);
else
cte->entry = ROM32(entry[0]);
cte->type = (cte->entry & 0x000000ff) >> 0;
cte->index2 = (cte->entry & 0x00000f00) >> 8;
cte->gpio_tag = ffs((cte->entry & 0x07033000) >> 12);
cte->gpio_tag = hpd_gpio[cte->gpio_tag];
if (cte->type == 0xff)
continue;
apply_dcb_connector_quirks(bios, i);
NV_INFO(dev, " %d: 0x%08x: type 0x%02x idx %d tag 0x%02x\n",
i, cte->entry, cte->type, cte->index, cte->gpio_tag);
switch (cte->type) {
case DCB_CONNECTOR_VGA:
case DCB_CONNECTOR_TV_0:
case DCB_CONNECTOR_TV_1:
case DCB_CONNECTOR_TV_3:
case DCB_CONNECTOR_DVI_I:
case DCB_CONNECTOR_DVI_D:
case DCB_CONNECTOR_LVDS:
case DCB_CONNECTOR_LVDS_SPWG:
case DCB_CONNECTOR_DP:
case DCB_CONNECTOR_eDP:
case DCB_CONNECTOR_HDMI_0:
case DCB_CONNECTOR_HDMI_1:
break;
default:
cte->type = divine_connector_type(bios, cte->index);
NV_WARN(dev, "unknown type, using 0x%02x\n", cte->type);
break;
}
if (nouveau_override_conntype) {
int type = divine_connector_type(bios, cte->index);
if (type != cte->type)
NV_WARN(dev, " -> type 0x%02x\n", cte->type);
}
}
}
static struct dcb_entry *new_dcb_entry(struct dcb_table *dcb)
{
struct dcb_entry *entry = &dcb->entry[dcb->entries];
memset(entry, 0, sizeof(struct dcb_entry));
entry->index = dcb->entries++;
return entry;
}
static void fabricate_dcb_output(struct dcb_table *dcb, int type, int i2c,
int heads, int or)
{
struct dcb_entry *entry = new_dcb_entry(dcb);
entry->type = type;
entry->i2c_index = i2c;
entry->heads = heads;
if (type != OUTPUT_ANALOG)
entry->location = !DCB_LOC_ON_CHIP;
entry->or = or;
}
static bool
parse_dcb20_entry(struct drm_device *dev, struct dcb_table *dcb,
uint32_t conn, uint32_t conf, struct dcb_entry *entry)
{
entry->type = conn & 0xf;
entry->i2c_index = (conn >> 4) & 0xf;
entry->heads = (conn >> 8) & 0xf;
if (dcb->version >= 0x40)
entry->connector = (conn >> 12) & 0xf;
entry->bus = (conn >> 16) & 0xf;
entry->location = (conn >> 20) & 0x3;
entry->or = (conn >> 24) & 0xf;
switch (entry->type) {
case OUTPUT_ANALOG:
entry->crtconf.maxfreq = (dcb->version < 0x30) ?
(conf & 0xffff) * 10 :
(conf & 0xff) * 10000;
break;
case OUTPUT_LVDS:
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
}
if (conf & mask) {
if (dcb->version >= 0x40)
break;
NV_ERROR(dev, "Unknown LVDS configuration bits, "
"please report\n");
}
break;
}
case OUTPUT_TV:
{
if (dcb->version >= 0x30)
entry->tvconf.has_component_output = conf & (0x8 << 4);
else
entry->tvconf.has_component_output = false;
break;
}
case OUTPUT_DP:
entry->dpconf.sor.link = (conf & 0x00000030) >> 4;
entry->dpconf.link_bw = (conf & 0x00e00000) >> 21;
switch ((conf & 0x0f000000) >> 24) {
case 0xf:
entry->dpconf.link_nr = 4;
break;
case 0x3:
entry->dpconf.link_nr = 2;
break;
default:
entry->dpconf.link_nr = 1;
break;
}
break;
case OUTPUT_TMDS:
if (dcb->version >= 0x40)
entry->tmdsconf.sor.link = (conf & 0x00000030) >> 4;
else if (dcb->version >= 0x30)
entry->tmdsconf.slave_addr = (conf & 0x00000700) >> 8;
else if (dcb->version >= 0x22)
entry->tmdsconf.slave_addr = (conf & 0x00000070) >> 4;
break;
case OUTPUT_EOL:
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
return true;
}
static bool
parse_dcb15_entry(struct drm_device *dev, struct dcb_table *dcb,
uint32_t conn, uint32_t conf, struct dcb_entry *entry)
{
switch (conn & 0x0000000f) {
case 0:
entry->type = OUTPUT_ANALOG;
break;
case 1:
entry->type = OUTPUT_TV;
break;
case 2:
case 4:
if (conn & 0x10)
entry->type = OUTPUT_LVDS;
else
entry->type = OUTPUT_TMDS;
break;
case 3:
entry->type = OUTPUT_LVDS;
break;
default:
NV_ERROR(dev, "Unknown DCB type %d\n", conn & 0x0000000f);
return false;
}
entry->i2c_index = (conn & 0x0003c000) >> 14;
entry->heads = ((conn & 0x001c0000) >> 18) + 1;
entry->or = entry->heads;
entry->location = (conn & 0x01e00000) >> 21;
entry->bus = (conn & 0x0e000000) >> 25;
entry->duallink_possible = false;
switch (entry->type) {
case OUTPUT_ANALOG:
entry->crtconf.maxfreq = (conf & 0xffff) * 10;
break;
case OUTPUT_TV:
entry->tvconf.has_component_output = false;
break;
case OUTPUT_LVDS:
if ((conn & 0x00003f00) >> 8 != 0x10)
entry->lvdsconf.use_straps_for_mode = true;
entry->lvdsconf.use_power_scripts = true;
break;
default:
break;
}
return true;
}
static bool parse_dcb_entry(struct drm_device *dev, struct dcb_table *dcb,
uint32_t conn, uint32_t conf)
{
struct dcb_entry *entry = new_dcb_entry(dcb);
bool ret;
if (dcb->version >= 0x20)
ret = parse_dcb20_entry(dev, dcb, conn, conf, entry);
else
ret = parse_dcb15_entry(dev, dcb, conn, conf, entry);
if (!ret)
return ret;
read_dcb_i2c_entry(dev, dcb->version, dcb->i2c_table,
entry->i2c_index, &dcb->i2c[entry->i2c_index]);
return true;
}
static
void merge_like_dcb_entries(struct drm_device *dev, struct dcb_table *dcb)
{
int i, newentries = 0;
for (i = 0; i < dcb->entries; i++) {
struct dcb_entry *ient = &dcb->entry[i];
int j;
for (j = i + 1; j < dcb->entries; j++) {
struct dcb_entry *jent = &dcb->entry[j];
if (jent->type == 100)
continue;
if (jent->i2c_index == ient->i2c_index &&
jent->type == ient->type &&
jent->location == ient->location &&
jent->or == ient->or) {
NV_TRACE(dev, "Merging DCB entries %d and %d\n",
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
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct dcb_table *dcb = &dev_priv->vbios.dcb;
if (nv_match_device(dev, 0x040d, 0x1028, 0x019b)) {
if (*conn == 0x02026312 && *conf == 0x00000020)
return false;
}
if (nv_match_device(dev, 0x0201, 0x1462, 0x8851)) {
if (*conn == 0xf2005014 && *conf == 0xffffffff) {
fabricate_dcb_output(dcb, OUTPUT_TMDS, 1, 1, 1);
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
return true;
}
static void
fabricate_dcb_encoder_table(struct drm_device *dev, struct nvbios *bios)
{
struct dcb_table *dcb = &bios->dcb;
int all_heads = (nv_two_heads(dev) ? 3 : 1);
#ifdef __powerpc__
if (of_machine_is_compatible("PowerMac4,5")) {
fabricate_dcb_output(dcb, OUTPUT_TMDS, 0, all_heads, 1);
fabricate_dcb_output(dcb, OUTPUT_ANALOG, 1, all_heads, 2);
return;
}
#endif
fabricate_dcb_output(dcb, OUTPUT_ANALOG, LEGACY_I2C_CRT, 1, 1);
if (nv04_tv_identify(dev, bios->legacy.i2c_indices.tv) >= 0)
fabricate_dcb_output(dcb, OUTPUT_TV, LEGACY_I2C_TV,
all_heads, 0);
else if (bios->tmds.output0_script_ptr ||
bios->tmds.output1_script_ptr)
fabricate_dcb_output(dcb, OUTPUT_TMDS, LEGACY_I2C_PANEL,
all_heads, 1);
}
static int
parse_dcb_table(struct drm_device *dev, struct nvbios *bios)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct dcb_table *dcb = &bios->dcb;
uint16_t dcbptr = 0, i2ctabptr = 0;
uint8_t *dcbtable;
uint8_t headerlen = 0x4, entries = DCB_MAX_NUM_ENTRIES;
bool configblock = true;
int recordlength = 8, confofs = 4;
int i;
if (dev_priv->card_type > NV_04) {
dcbptr = ROM16(bios->data[0x36]);
if (dcbptr == 0x0000)
NV_WARN(dev, "No output data (DCB) found in BIOS\n");
}
if (dcbptr == 0x0) {
fabricate_dcb_encoder_table(dev, bios);
return 0;
}
dcbtable = &bios->data[dcbptr];
dcb->version = dcbtable[0];
NV_TRACE(dev, "Found Display Configuration Block version %d.%d\n",
dcb->version >> 4, dcb->version & 0xf);
if (dcb->version >= 0x20) {
uint32_t sig;
if (dcb->version >= 0x30) {
headerlen = dcbtable[1];
entries = dcbtable[2];
recordlength = dcbtable[3];
i2ctabptr = ROM16(dcbtable[4]);
sig = ROM32(dcbtable[6]);
dcb->gpio_table_ptr = ROM16(dcbtable[10]);
dcb->connector_table_ptr = ROM16(dcbtable[20]);
} else {
i2ctabptr = ROM16(dcbtable[2]);
sig = ROM32(dcbtable[4]);
headerlen = 8;
}
if (sig != 0x4edcbdcb) {
NV_ERROR(dev, "Bad Display Configuration Block "
"signature (%08X)\n", sig);
return -EINVAL;
}
} else if (dcb->version >= 0x15) {
char sig[8] = { 0 };
strncpy(sig, (char *)&dcbtable[-7], 7);
i2ctabptr = ROM16(dcbtable[2]);
recordlength = 10;
confofs = 6;
if (strcmp(sig, "DEV_REC")) {
NV_ERROR(dev, "Bad Display Configuration Block "
"signature (%s)\n", sig);
return -EINVAL;
}
} else {
NV_TRACEWARN(dev, "No useful information in BIOS output table; "
"adding all possible outputs\n");
fabricate_dcb_encoder_table(dev, bios);
return 0;
}
if (!i2ctabptr)
NV_WARN(dev, "No pointer to DCB I2C port table\n");
else {
dcb->i2c_table = &bios->data[i2ctabptr];
if (dcb->version >= 0x30)
dcb->i2c_default_indices = dcb->i2c_table[4];
if (dcb->version >= 0x22) {
int idx = (dcb->version >= 0x40 ?
dcb->i2c_default_indices & 0xf :
2);
read_dcb_i2c_entry(dev, dcb->version, dcb->i2c_table,
idx, &dcb->i2c[idx]);
}
}
if (entries > DCB_MAX_NUM_ENTRIES)
entries = DCB_MAX_NUM_ENTRIES;
for (i = 0; i < entries; i++) {
uint32_t connection, config = 0;
connection = ROM32(dcbtable[headerlen + recordlength * i]);
if (configblock)
config = ROM32(dcbtable[headerlen + confofs + recordlength * i]);
if (connection == 0x00000000)
break;
if (connection == 0xffffffff)
break;
if ((connection & 0x0000000f) == 0x0000000f)
continue;
if (!apply_dcb_encoder_quirks(dev, i, &connection, &config))
continue;
NV_TRACEWARN(dev, "Raw DCB entry %d: %08x %08x\n",
dcb->entries, connection, config);
if (!parse_dcb_entry(dev, dcb, connection, config))
break;
}
if (dcb->version < 0x21)
merge_like_dcb_entries(dev, dcb);
if (!dcb->entries)
return -ENXIO;
parse_dcb_gpio_table(bios);
parse_dcb_connector_table(bios);
return 0;
}
static void
fixup_legacy_connector(struct nvbios *bios)
{
struct dcb_table *dcb = &bios->dcb;
int i, i2c, i2c_conn[DCB_MAX_NUM_I2C_ENTRIES] = { };
if (dcb->version >= 0x40)
return;
dcb->connector.entries = 0;
for (i = 0; i < dcb->entries; i++) {
if (dcb->entry[i].type == OUTPUT_TV &&
dcb->entry[i].location == DCB_LOC_ON_CHIP)
dcb->entry[i].i2c_index = 0xf;
i2c = dcb->entry[i].i2c_index;
if (i2c_conn[i2c]) {
dcb->entry[i].connector = i2c_conn[i2c] - 1;
continue;
}
dcb->entry[i].connector = dcb->connector.entries++;
if (i2c != 0xf)
i2c_conn[i2c] = dcb->connector.entries;
}
for (i = 0; i < dcb->connector.entries; i++) {
dcb->connector.entry[i].index = i;
dcb->connector.entry[i].type = divine_connector_type(bios, i);
dcb->connector.entry[i].gpio_tag = 0xff;
}
}
static void
fixup_legacy_i2c(struct nvbios *bios)
{
struct dcb_table *dcb = &bios->dcb;
int i;
for (i = 0; i < dcb->entries; i++) {
if (dcb->entry[i].i2c_index == LEGACY_I2C_CRT)
dcb->entry[i].i2c_index = bios->legacy.i2c_indices.crt;
if (dcb->entry[i].i2c_index == LEGACY_I2C_PANEL)
dcb->entry[i].i2c_index = bios->legacy.i2c_indices.panel;
if (dcb->entry[i].i2c_index == LEGACY_I2C_TV)
dcb->entry[i].i2c_index = bios->legacy.i2c_indices.tv;
}
}
static int load_nv17_hwsq_ucode_entry(struct drm_device *dev, struct nvbios *bios, uint16_t hwsq_offset, int entry)
{
uint8_t bytes_to_write;
uint16_t hwsq_entry_offset;
int i;
if (bios->data[hwsq_offset] <= entry) {
NV_ERROR(dev, "Too few entries in HW sequencer table for "
"requested entry\n");
return -ENOENT;
}
bytes_to_write = bios->data[hwsq_offset + 1];
if (bytes_to_write != 36) {
NV_ERROR(dev, "Unknown HW sequencer entry size\n");
return -EINVAL;
}
NV_TRACE(dev, "Loading NV17 power sequencing microcode\n");
hwsq_entry_offset = hwsq_offset + 2 + entry * bytes_to_write;
bios_wr32(bios, 0x00001304, ROM32(bios->data[hwsq_entry_offset]));
bytes_to_write -= 4;
for (i = 0; i < bytes_to_write; i += 4)
bios_wr32(bios, 0x00001400 + i, ROM32(bios->data[hwsq_entry_offset + i + 4]));
bios_wr32(bios, NV_PBUS_DEBUG_4, bios_rd32(bios, NV_PBUS_DEBUG_4) | 0x18);
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
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
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
NV_TRACE(dev, "Found EDID in BIOS\n");
return bios->fp.edid = &bios->data[offset];
}
void
nouveau_bios_run_init_table(struct drm_device *dev, uint16_t table,
struct dcb_entry *dcbent)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
struct init_exec iexec = { true, false };
spin_lock_bh(&bios->lock);
bios->display.output = dcbent;
parse_init_table(bios, table, &iexec);
bios->display.output = NULL;
spin_unlock_bh(&bios->lock);
}
static bool NVInitVBIOS(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
memset(bios, 0, sizeof(struct nvbios));
spin_lock_init(&bios->lock);
bios->dev = dev;
if (!NVShadowVBIOS(dev, bios->data))
return false;
bios->length = NV_PROM_SIZE;
return true;
}
static int nouveau_parse_vbios_struct(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
const uint8_t bit_signature[] = { 0xff, 0xb8, 'B', 'I', 'T' };
const uint8_t bmp_signature[] = { 0xff, 0x7f, 'N', 'V', 0x0 };
int offset;
offset = findstr(bios->data, bios->length,
bit_signature, sizeof(bit_signature));
if (offset) {
NV_TRACE(dev, "BIT BIOS found\n");
bios->type = NVBIOS_BIT;
bios->offset = offset;
return parse_bit_structure(bios, offset + 6);
}
offset = findstr(bios->data, bios->length,
bmp_signature, sizeof(bmp_signature));
if (offset) {
NV_TRACE(dev, "BMP BIOS found\n");
bios->type = NVBIOS_BMP;
bios->offset = offset;
return parse_bmp_structure(dev, bios, offset);
}
NV_ERROR(dev, "No known BIOS signature found\n");
return -ENODEV;
}
int
nouveau_run_vbios_init(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
int i, ret = 0;
bios->state.crtchead = 0;
if (bios->major_version < 5)
load_nv17_hw_sequencer_ucode(dev, bios);
if (bios->execute) {
bios->fp.last_script_invoc = 0;
bios->fp.lvds_init_run = false;
}
parse_init_tables(bios);
if (bios->some_script_ptr) {
struct init_exec iexec = {true, false};
NV_INFO(dev, "Parsing VBIOS init table at offset 0x%04X\n",
bios->some_script_ptr);
parse_init_table(bios, bios->some_script_ptr, &iexec);
}
if (dev_priv->card_type >= NV_50) {
for (i = 0; i < bios->dcb.entries; i++) {
nouveau_bios_run_display_table(dev,
&bios->dcb.entry[i],
0, 0);
}
}
return ret;
}
static void
nouveau_bios_i2c_devices_takedown(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
struct dcb_i2c_entry *entry;
int i;
entry = &bios->dcb.i2c[0];
for (i = 0; i < DCB_MAX_NUM_I2C_ENTRIES; i++, entry++)
nouveau_i2c_fini(dev, entry);
}
static bool
nouveau_bios_posted(struct drm_device *dev)
{
struct drm_nouveau_private *dev_priv = dev->dev_private;
unsigned htotal;
if (dev_priv->card_type >= NV_50) {
if (NVReadVgaCrtc(dev, 0, 0x00) == 0 &&
NVReadVgaCrtc(dev, 0, 0x1a) == 0)
return false;
return true;
}
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
struct drm_nouveau_private *dev_priv = dev->dev_private;
struct nvbios *bios = &dev_priv->vbios;
int ret;
if (!NVInitVBIOS(dev))
return -ENODEV;
ret = nouveau_parse_vbios_struct(dev);
if (ret)
return ret;
ret = parse_dcb_table(dev, bios);
if (ret)
return ret;
fixup_legacy_i2c(bios);
fixup_legacy_connector(bios);
if (!bios->major_version)
return 0;
bios->execute = false;
if (!nouveau_bios_posted(dev)) {
NV_INFO(dev, "Adaptor not initialised, "
"running VBIOS init tables.\n");
bios->execute = true;
}
if (nouveau_force_post)
bios->execute = true;
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
nouveau_bios_i2c_devices_takedown(dev);
}
