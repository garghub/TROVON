u32 b43_lcntab_read(struct b43_wldev *dev, u32 offset)
{
u32 type, value;
type = offset & B43_LCNTAB_TYPEMASK;
offset &= ~B43_LCNTAB_TYPEMASK;
B43_WARN_ON(offset > 0xFFFF);
switch (type) {
case B43_LCNTAB_8BIT:
b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
value = b43_phy_read(dev, B43_PHY_LCN_TABLE_DATALO) & 0xFF;
break;
case B43_LCNTAB_16BIT:
b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
value = b43_phy_read(dev, B43_PHY_LCN_TABLE_DATALO);
break;
case B43_LCNTAB_32BIT:
b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
value = b43_phy_read(dev, B43_PHY_LCN_TABLE_DATALO);
value |= (b43_phy_read(dev, B43_PHY_LCN_TABLE_DATAHI) << 16);
break;
default:
B43_WARN_ON(1);
value = 0;
}
return value;
}
void b43_lcntab_read_bulk(struct b43_wldev *dev, u32 offset,
unsigned int nr_elements, void *_data)
{
u32 type;
u8 *data = _data;
unsigned int i;
type = offset & B43_LCNTAB_TYPEMASK;
offset &= ~B43_LCNTAB_TYPEMASK;
B43_WARN_ON(offset > 0xFFFF);
b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
for (i = 0; i < nr_elements; i++) {
switch (type) {
case B43_LCNTAB_8BIT:
*data = b43_phy_read(dev,
B43_PHY_LCN_TABLE_DATALO) & 0xFF;
data++;
break;
case B43_LCNTAB_16BIT:
*((u16 *)data) = b43_phy_read(dev,
B43_PHY_LCN_TABLE_DATALO);
data += 2;
break;
case B43_LCNTAB_32BIT:
*((u32 *)data) = b43_phy_read(dev,
B43_PHY_LCN_TABLE_DATALO);
*((u32 *)data) |= (b43_phy_read(dev,
B43_PHY_LCN_TABLE_DATAHI) << 16);
data += 4;
break;
default:
B43_WARN_ON(1);
}
}
}
void b43_lcntab_write(struct b43_wldev *dev, u32 offset, u32 value)
{
u32 type;
type = offset & B43_LCNTAB_TYPEMASK;
offset &= 0xFFFF;
switch (type) {
case B43_LCNTAB_8BIT:
B43_WARN_ON(value & ~0xFF);
b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
b43_phy_write(dev, B43_PHY_LCN_TABLE_DATALO, value);
break;
case B43_LCNTAB_16BIT:
B43_WARN_ON(value & ~0xFFFF);
b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
b43_phy_write(dev, B43_PHY_LCN_TABLE_DATALO, value);
break;
case B43_LCNTAB_32BIT:
b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
b43_phy_write(dev, B43_PHY_LCN_TABLE_DATAHI, value >> 16);
b43_phy_write(dev, B43_PHY_LCN_TABLE_DATALO, value & 0xFFFF);
break;
default:
B43_WARN_ON(1);
}
return;
}
void b43_lcntab_write_bulk(struct b43_wldev *dev, u32 offset,
unsigned int nr_elements, const void *_data)
{
u32 type, value;
const u8 *data = _data;
unsigned int i;
type = offset & B43_LCNTAB_TYPEMASK;
offset &= ~B43_LCNTAB_TYPEMASK;
B43_WARN_ON(offset > 0xFFFF);
b43_phy_write(dev, B43_PHY_LCN_TABLE_ADDR, offset);
for (i = 0; i < nr_elements; i++) {
switch (type) {
case B43_LCNTAB_8BIT:
value = *data;
data++;
B43_WARN_ON(value & ~0xFF);
b43_phy_write(dev, B43_PHY_LCN_TABLE_DATALO, value);
break;
case B43_LCNTAB_16BIT:
value = *((u16 *)data);
data += 2;
B43_WARN_ON(value & ~0xFFFF);
b43_phy_write(dev, B43_PHY_LCN_TABLE_DATALO, value);
break;
case B43_LCNTAB_32BIT:
value = *((u32 *)data);
data += 4;
b43_phy_write(dev, B43_PHY_LCN_TABLE_DATAHI,
value >> 16);
b43_phy_write(dev, B43_PHY_LCN_TABLE_DATALO,
value & 0xFFFF);
break;
default:
B43_WARN_ON(1);
}
}
}
static void b43_phy_lcn_upload_static_tables(struct b43_wldev *dev)
{
lcntab_upload(dev, B43_LCNTAB16(0x02, 0), b43_lcntab_0x02);
lcntab_upload(dev, B43_LCNTAB16(0x01, 0), b43_lcntab_0x01);
lcntab_upload(dev, B43_LCNTAB32(0x0b, 0), b43_lcntab_0x0b);
lcntab_upload(dev, B43_LCNTAB32(0x0c, 0), b43_lcntab_0x0c);
lcntab_upload(dev, B43_LCNTAB32(0x0d, 0), b43_lcntab_0x0d);
lcntab_upload(dev, B43_LCNTAB16(0x0e, 0), b43_lcntab_0x0e);
lcntab_upload(dev, B43_LCNTAB16(0x0f, 0), b43_lcntab_0x0f);
lcntab_upload(dev, B43_LCNTAB16(0x10, 0), b43_lcntab_0x10);
lcntab_upload(dev, B43_LCNTAB16(0x11, 0), b43_lcntab_0x11);
lcntab_upload(dev, B43_LCNTAB32(0x12, 0), b43_lcntab_0x12);
lcntab_upload(dev, B43_LCNTAB16(0x14, 0), b43_lcntab_0x14);
lcntab_upload(dev, B43_LCNTAB16(0x17, 0), b43_lcntab_0x17);
lcntab_upload(dev, B43_LCNTAB16(0x00, 0), b43_lcntab_0x00);
lcntab_upload(dev, B43_LCNTAB32(0x18, 0), b43_lcntab_0x18);
}
static void b43_phy_lcn_load_tx_gain_tab(struct b43_wldev *dev,
const struct b43_lcntab_tx_gain_tbl_entry *gain_table)
{
u32 i;
u32 val;
u16 pa_gain = 0x70;
if (dev->dev->bus_sprom->boardflags_lo & B43_BFL_FEM)
pa_gain = 0x10;
for (i = 0; i < B43_LCNTAB_TX_GAIN_SIZE; i++) {
val = ((pa_gain << 24) |
(gain_table[i].pad << 16) |
(gain_table[i].pga << 8) |
gain_table[i].gm);
b43_lcntab_write(dev, B43_LCNTAB32(0x7, 0xc0 + i), val);
val = b43_lcntab_read(dev, B43_LCNTAB32(0x7, 0x140 + i));
val &= 0x000fffff;
val |= ((gain_table[i].dac << 28) |
(gain_table[i].bb_mult << 20));
b43_lcntab_write(dev, B43_LCNTAB32(0x7, 0x140 + i), val);
}
}
static void b43_phy_lcn_load_rfpower(struct b43_wldev *dev)
{
u32 bbmult, rfgain;
u8 i;
for (i = 0; i < 128; i++) {
bbmult = b43_lcntab_read(dev, B43_LCNTAB32(0x7, 0x140 + i));
bbmult >>= 20;
rfgain = b43_lcntab_read(dev, B43_LCNTAB32(0x7, 0xc0 + i));
}
}
static void b43_phy_lcn_rewrite_rfpower_table(struct b43_wldev *dev)
{
int i;
u32 tmp;
for (i = 0; i < 128; i++) {
tmp = b43_lcntab_read(dev, B43_LCNTAB32(0x7, 0x240 + i));
b43_lcntab_write(dev, B43_LCNTAB32(0x7, 0x240 + i), tmp);
}
}
static void b43_phy_lcn_clean_papd_comp_table(struct b43_wldev *dev)
{
u8 i;
for (i = 0; i < 0x80; i++)
b43_lcntab_write(dev, B43_LCNTAB32(0x18, i), 0x80000);
}
void b43_phy_lcn_tables_init(struct b43_wldev *dev)
{
struct ssb_sprom *sprom = dev->dev->bus_sprom;
b43_phy_lcn_upload_static_tables(dev);
if (b43_current_band(dev->wl) == IEEE80211_BAND_2GHZ) {
if (sprom->boardflags_lo & B43_BFL_FEM)
b43_phy_lcn_load_tx_gain_tab(dev,
b43_lcntab_tx_gain_tbl_2ghz_ext_pa_rev0);
else
b43err(dev->wl,
"TX gain table unknown for this card\n");
}
if (sprom->boardflags_lo & B43_BFL_FEM &&
!(sprom->boardflags_hi & B43_BFH_FEM_BT))
b43_lcntab_write_bulk(dev, B43_LCNTAB16(0xf, 0),
ARRAY_SIZE(b43_lcntab_sw_ctl_4313_epa_rev0),
b43_lcntab_sw_ctl_4313_epa_rev0);
else
b43err(dev->wl, "SW ctl table is unknown for this card\n");
b43_phy_lcn_load_rfpower(dev);
b43_phy_lcn_rewrite_rfpower_table(dev);
b43_phy_lcn_clean_papd_comp_table(dev);
}
