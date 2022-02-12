void b2062_upload_init_table(struct b43_wldev *dev)
{
const struct b206x_init_tab_entry *e;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(b2062_init_tab); i++) {
e = &b2062_init_tab[i];
if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ) {
if (!(e->flags & B206X_FLAG_G))
continue;
b43_radio_write(dev, e->offset, e->value_g);
} else {
if (!(e->flags & B206X_FLAG_A))
continue;
b43_radio_write(dev, e->offset, e->value_a);
}
}
}
void b2063_upload_init_table(struct b43_wldev *dev)
{
const struct b206x_init_tab_entry *e;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(b2063_init_tab); i++) {
e = &b2063_init_tab[i];
if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ) {
if (!(e->flags & B206X_FLAG_G))
continue;
b43_radio_write(dev, e->offset, e->value_g);
} else {
if (!(e->flags & B206X_FLAG_A))
continue;
b43_radio_write(dev, e->offset, e->value_a);
}
}
}
u32 b43_lptab_read(struct b43_wldev *dev, u32 offset)
{
u32 type, value;
type = offset & B43_LPTAB_TYPEMASK;
offset &= ~B43_LPTAB_TYPEMASK;
B43_WARN_ON(offset > 0xFFFF);
switch (type) {
case B43_LPTAB_8BIT:
b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
value = b43_phy_read(dev, B43_LPPHY_TABLEDATALO) & 0xFF;
break;
case B43_LPTAB_16BIT:
b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
value = b43_phy_read(dev, B43_LPPHY_TABLEDATALO);
break;
case B43_LPTAB_32BIT:
b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
value = b43_phy_read(dev, B43_LPPHY_TABLEDATAHI);
value <<= 16;
value |= b43_phy_read(dev, B43_LPPHY_TABLEDATALO);
break;
default:
B43_WARN_ON(1);
value = 0;
}
return value;
}
void b43_lptab_read_bulk(struct b43_wldev *dev, u32 offset,
unsigned int nr_elements, void *_data)
{
u32 type;
u8 *data = _data;
unsigned int i;
type = offset & B43_LPTAB_TYPEMASK;
offset &= ~B43_LPTAB_TYPEMASK;
B43_WARN_ON(offset > 0xFFFF);
b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
for (i = 0; i < nr_elements; i++) {
switch (type) {
case B43_LPTAB_8BIT:
*data = b43_phy_read(dev, B43_LPPHY_TABLEDATALO) & 0xFF;
data++;
break;
case B43_LPTAB_16BIT:
*((u16 *)data) = b43_phy_read(dev, B43_LPPHY_TABLEDATALO);
data += 2;
break;
case B43_LPTAB_32BIT:
*((u32 *)data) = b43_phy_read(dev, B43_LPPHY_TABLEDATAHI);
*((u32 *)data) <<= 16;
*((u32 *)data) |= b43_phy_read(dev, B43_LPPHY_TABLEDATALO);
data += 4;
break;
default:
B43_WARN_ON(1);
}
}
}
void b43_lptab_write(struct b43_wldev *dev, u32 offset, u32 value)
{
u32 type;
type = offset & B43_LPTAB_TYPEMASK;
offset &= ~B43_LPTAB_TYPEMASK;
B43_WARN_ON(offset > 0xFFFF);
switch (type) {
case B43_LPTAB_8BIT:
B43_WARN_ON(value & ~0xFF);
b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
b43_phy_write(dev, B43_LPPHY_TABLEDATALO, value);
break;
case B43_LPTAB_16BIT:
B43_WARN_ON(value & ~0xFFFF);
b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
b43_phy_write(dev, B43_LPPHY_TABLEDATALO, value);
break;
case B43_LPTAB_32BIT:
b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
b43_phy_write(dev, B43_LPPHY_TABLEDATAHI, value >> 16);
b43_phy_write(dev, B43_LPPHY_TABLEDATALO, value);
break;
default:
B43_WARN_ON(1);
}
}
void b43_lptab_write_bulk(struct b43_wldev *dev, u32 offset,
unsigned int nr_elements, const void *_data)
{
u32 type, value;
const u8 *data = _data;
unsigned int i;
type = offset & B43_LPTAB_TYPEMASK;
offset &= ~B43_LPTAB_TYPEMASK;
B43_WARN_ON(offset > 0xFFFF);
b43_phy_write(dev, B43_LPPHY_TABLE_ADDR, offset);
for (i = 0; i < nr_elements; i++) {
switch (type) {
case B43_LPTAB_8BIT:
value = *data;
data++;
B43_WARN_ON(value & ~0xFF);
b43_phy_write(dev, B43_LPPHY_TABLEDATALO, value);
break;
case B43_LPTAB_16BIT:
value = *((u16 *)data);
data += 2;
B43_WARN_ON(value & ~0xFFFF);
b43_phy_write(dev, B43_LPPHY_TABLEDATALO, value);
break;
case B43_LPTAB_32BIT:
value = *((u32 *)data);
data += 4;
b43_phy_write(dev, B43_LPPHY_TABLEDATAHI, value >> 16);
b43_phy_write(dev, B43_LPPHY_TABLEDATALO, value);
break;
default:
B43_WARN_ON(1);
}
}
}
void lpphy_rev0_1_table_init(struct b43_wldev *dev)
{
B43_WARN_ON(dev->phy.rev >= 2);
b43_lptab_write_bulk(dev, B43_LPTAB8(2, 0),
ARRAY_SIZE(lpphy_min_sig_sq_table), lpphy_min_sig_sq_table);
b43_lptab_write_bulk(dev, B43_LPTAB16(1, 0),
ARRAY_SIZE(lpphy_rev01_noise_scale_table), lpphy_rev01_noise_scale_table);
b43_lptab_write_bulk(dev, B43_LPTAB16(14, 0),
ARRAY_SIZE(lpphy_crs_gain_nft_table), lpphy_crs_gain_nft_table);
b43_lptab_write_bulk(dev, B43_LPTAB16(8, 0),
ARRAY_SIZE(lpphy_rev01_filter_control_table), lpphy_rev01_filter_control_table);
b43_lptab_write_bulk(dev, B43_LPTAB32(9, 0),
ARRAY_SIZE(lpphy_rev01_ps_control_table), lpphy_rev01_ps_control_table);
b43_lptab_write_bulk(dev, B43_LPTAB8(6, 0),
ARRAY_SIZE(lpphy_pll_fraction_table), lpphy_pll_fraction_table);
b43_lptab_write_bulk(dev, B43_LPTAB16(0, 0),
ARRAY_SIZE(lpphy_iqlo_cal_table), lpphy_iqlo_cal_table);
if (dev->phy.rev == 0) {
b43_lptab_write_bulk(dev, B43_LPTAB16(13, 0),
ARRAY_SIZE(lpphy_rev0_ofdm_cck_gain_table), lpphy_rev0_ofdm_cck_gain_table);
b43_lptab_write_bulk(dev, B43_LPTAB16(12, 0),
ARRAY_SIZE(lpphy_rev0_ofdm_cck_gain_table), lpphy_rev0_ofdm_cck_gain_table);
} else {
b43_lptab_write_bulk(dev, B43_LPTAB16(13, 0),
ARRAY_SIZE(lpphy_rev1_ofdm_cck_gain_table), lpphy_rev1_ofdm_cck_gain_table);
b43_lptab_write_bulk(dev, B43_LPTAB16(12, 0),
ARRAY_SIZE(lpphy_rev1_ofdm_cck_gain_table), lpphy_rev1_ofdm_cck_gain_table);
}
b43_lptab_write_bulk(dev, B43_LPTAB16(15, 0),
ARRAY_SIZE(lpphy_gain_delta_table), lpphy_gain_delta_table);
b43_lptab_write_bulk(dev, B43_LPTAB32(10, 0),
ARRAY_SIZE(lpphy_tx_power_control_table), lpphy_tx_power_control_table);
}
void lpphy_rev2plus_table_init(struct b43_wldev *dev)
{
int i;
B43_WARN_ON(dev->phy.rev < 2);
for (i = 0; i < 704; i++)
b43_lptab_write(dev, B43_LPTAB32(7, i), 0);
b43_lptab_write_bulk(dev, B43_LPTAB8(2, 0),
ARRAY_SIZE(lpphy_min_sig_sq_table), lpphy_min_sig_sq_table);
b43_lptab_write_bulk(dev, B43_LPTAB16(1, 0),
ARRAY_SIZE(lpphy_rev2plus_noise_scale_table), lpphy_rev2plus_noise_scale_table);
b43_lptab_write_bulk(dev, B43_LPTAB32(11, 0),
ARRAY_SIZE(lpphy_rev2plus_filter_control_table), lpphy_rev2plus_filter_control_table);
b43_lptab_write_bulk(dev, B43_LPTAB32(12, 0),
ARRAY_SIZE(lpphy_rev2plus_ps_control_table), lpphy_rev2plus_ps_control_table);
b43_lptab_write_bulk(dev, B43_LPTAB32(13, 0),
ARRAY_SIZE(lpphy_gain_idx_table), lpphy_gain_idx_table);
b43_lptab_write_bulk(dev, B43_LPTAB16(14, 0),
ARRAY_SIZE(lpphy_aux_gain_idx_table), lpphy_aux_gain_idx_table);
b43_lptab_write_bulk(dev, B43_LPTAB16(15, 0),
ARRAY_SIZE(lpphy_sw_control_table), lpphy_sw_control_table);
b43_lptab_write_bulk(dev, B43_LPTAB8(16, 0),
ARRAY_SIZE(lpphy_hf_table), lpphy_hf_table);
b43_lptab_write_bulk(dev, B43_LPTAB32(17, 0),
ARRAY_SIZE(lpphy_gain_value_table), lpphy_gain_value_table);
b43_lptab_write_bulk(dev, B43_LPTAB16(18, 0),
ARRAY_SIZE(lpphy_gain_table), lpphy_gain_table);
b43_lptab_write_bulk(dev, B43_LPTAB8(6, 0),
ARRAY_SIZE(lpphy_pll_fraction_table), lpphy_pll_fraction_table);
b43_lptab_write_bulk(dev, B43_LPTAB16(0, 0),
ARRAY_SIZE(lpphy_iqlo_cal_table), lpphy_iqlo_cal_table);
b43_lptab_write_bulk(dev, B43_LPTAB32(9, 0),
ARRAY_SIZE(lpphy_papd_eps_table), lpphy_papd_eps_table);
b43_lptab_write_bulk(dev, B43_LPTAB32(10, 0),
ARRAY_SIZE(lpphy_papd_mult_table), lpphy_papd_mult_table);
if ((dev->dev->chip_id == 0x4325) && (dev->dev->chip_rev == 0)) {
b43_lptab_write_bulk(dev, B43_LPTAB32(13, 0),
ARRAY_SIZE(lpphy_a0_gain_idx_table), lpphy_a0_gain_idx_table);
b43_lptab_write_bulk(dev, B43_LPTAB16(14, 0),
ARRAY_SIZE(lpphy_a0_aux_gain_idx_table), lpphy_a0_aux_gain_idx_table);
b43_lptab_write_bulk(dev, B43_LPTAB32(17, 0),
ARRAY_SIZE(lpphy_a0_gain_value_table), lpphy_a0_gain_value_table);
b43_lptab_write_bulk(dev, B43_LPTAB16(18, 0),
ARRAY_SIZE(lpphy_a0_gain_table), lpphy_a0_gain_table);
}
}
static void lpphy_rev0_1_write_gain_table(struct b43_wldev *dev, int offset,
struct lpphy_tx_gain_table_entry data)
{
u32 tmp;
B43_WARN_ON(dev->phy.rev >= 2);
tmp = data.pad << 11;
tmp |= data.pga << 7;
tmp |= data.gm << 4;
tmp |= data.dac;
b43_lptab_write(dev, B43_LPTAB32(10, 0xC0 + offset), tmp);
tmp = data.bb_mult << 20;
b43_lptab_write(dev, B43_LPTAB32(10, 0x140 + offset), tmp);
}
static void lpphy_rev2plus_write_gain_table(struct b43_wldev *dev, int offset,
struct lpphy_tx_gain_table_entry data)
{
u32 tmp;
B43_WARN_ON(dev->phy.rev < 2);
tmp = data.pad << 16;
tmp |= data.pga << 8;
tmp |= data.gm;
if (dev->phy.rev >= 3) {
if (b43_current_band(dev->wl) == NL80211_BAND_5GHZ)
tmp |= 0x10 << 24;
else
tmp |= 0x70 << 24;
} else {
if (b43_current_band(dev->wl) == NL80211_BAND_5GHZ)
tmp |= 0x14 << 24;
else
tmp |= 0x7F << 24;
}
b43_lptab_write(dev, B43_LPTAB32(7, 0xC0 + offset), tmp);
tmp = data.bb_mult << 20;
tmp |= data.dac << 28;
b43_lptab_write(dev, B43_LPTAB32(7, 0x140 + offset), tmp);
}
void lpphy_write_gain_table(struct b43_wldev *dev, int offset,
struct lpphy_tx_gain_table_entry data)
{
if (dev->phy.rev >= 2)
lpphy_rev2plus_write_gain_table(dev, offset, data);
else
lpphy_rev0_1_write_gain_table(dev, offset, data);
}
void lpphy_write_gain_table_bulk(struct b43_wldev *dev, int offset, int count,
struct lpphy_tx_gain_table_entry *table)
{
int i;
for (i = offset; i < count; i++)
lpphy_write_gain_table(dev, i, table[i]);
}
void lpphy_init_tx_gain_table(struct b43_wldev *dev)
{
struct ssb_sprom *sprom = dev->dev->bus_sprom;
switch (dev->phy.rev) {
case 0:
if ((sprom->boardflags_hi & B43_BFH_NOPA) ||
(sprom->boardflags_lo & B43_BFL_HGPA))
lpphy_write_gain_table_bulk(dev, 0, 128,
lpphy_rev0_nopa_tx_gain_table);
else if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ)
lpphy_write_gain_table_bulk(dev, 0, 128,
lpphy_rev0_2ghz_tx_gain_table);
else
lpphy_write_gain_table_bulk(dev, 0, 128,
lpphy_rev0_5ghz_tx_gain_table);
break;
case 1:
if ((sprom->boardflags_hi & B43_BFH_NOPA) ||
(sprom->boardflags_lo & B43_BFL_HGPA))
lpphy_write_gain_table_bulk(dev, 0, 128,
lpphy_rev1_nopa_tx_gain_table);
else if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ)
lpphy_write_gain_table_bulk(dev, 0, 128,
lpphy_rev1_2ghz_tx_gain_table);
else
lpphy_write_gain_table_bulk(dev, 0, 128,
lpphy_rev1_5ghz_tx_gain_table);
break;
default:
if (sprom->boardflags_hi & B43_BFH_NOPA)
lpphy_write_gain_table_bulk(dev, 0, 128,
lpphy_rev2_nopa_tx_gain_table);
else if (b43_current_band(dev->wl) == NL80211_BAND_2GHZ)
lpphy_write_gain_table_bulk(dev, 0, 128,
lpphy_rev2_2ghz_tx_gain_table);
else
lpphy_write_gain_table_bulk(dev, 0, 128,
lpphy_rev2_5ghz_tx_gain_table);
}
}
