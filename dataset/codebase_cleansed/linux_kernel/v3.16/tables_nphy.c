static inline void assert_ntab_array_sizes(void)
{
#undef check
#define check(table, size) \
BUILD_BUG_ON(ARRAY_SIZE(b43_ntab_##table) != B43_NTAB_##size##_SIZE)
check(adjustpower0, C0_ADJPLT);
check(adjustpower1, C1_ADJPLT);
check(bdi, BDI);
check(channelest, CHANEST);
check(estimatepowerlt0, C0_ESTPLT);
check(estimatepowerlt1, C1_ESTPLT);
check(framelookup, FRAMELT);
check(framestruct, FRAMESTRUCT);
check(gainctl0, C0_GAINCTL);
check(gainctl1, C1_GAINCTL);
check(intlevel, INTLEVEL);
check(iqlt0, C0_IQLT);
check(iqlt1, C1_IQLT);
check(loftlt0, C0_LOFEEDTH);
check(loftlt1, C1_LOFEEDTH);
check(mcs, MCS);
check(noisevar10, NOISEVAR10);
check(noisevar11, NOISEVAR11);
check(pilot, PILOT);
check(pilotlt, PILOTLT);
check(tdi20a0, TDI20A0);
check(tdi20a1, TDI20A1);
check(tdi40a0, TDI40A0);
check(tdi40a1, TDI40A1);
check(tdtrn, TDTRN);
check(tmap, TMAP);
#undef check
}
u32 b43_ntab_read(struct b43_wldev *dev, u32 offset)
{
u32 type, value;
type = offset & B43_NTAB_TYPEMASK;
offset &= ~B43_NTAB_TYPEMASK;
B43_WARN_ON(offset > 0xFFFF);
switch (type) {
case B43_NTAB_8BIT:
b43_phy_write(dev, B43_NPHY_TABLE_ADDR, offset);
value = b43_phy_read(dev, B43_NPHY_TABLE_DATALO) & 0xFF;
break;
case B43_NTAB_16BIT:
b43_phy_write(dev, B43_NPHY_TABLE_ADDR, offset);
value = b43_phy_read(dev, B43_NPHY_TABLE_DATALO);
break;
case B43_NTAB_32BIT:
b43_phy_write(dev, B43_NPHY_TABLE_ADDR, offset);
value = b43_phy_read(dev, B43_NPHY_TABLE_DATALO);
value |= b43_phy_read(dev, B43_NPHY_TABLE_DATAHI) << 16;
break;
default:
B43_WARN_ON(1);
value = 0;
}
return value;
}
void b43_ntab_read_bulk(struct b43_wldev *dev, u32 offset,
unsigned int nr_elements, void *_data)
{
u32 type;
u8 *data = _data;
unsigned int i;
type = offset & B43_NTAB_TYPEMASK;
offset &= ~B43_NTAB_TYPEMASK;
B43_WARN_ON(offset > 0xFFFF);
b43_phy_write(dev, B43_NPHY_TABLE_ADDR, offset);
for (i = 0; i < nr_elements; i++) {
if (dev->dev->chip_id == 43224 && dev->dev->chip_rev == 1) {
b43_phy_read(dev, B43_NPHY_TABLE_DATALO);
b43_phy_write(dev, B43_NPHY_TABLE_ADDR, offset + i);
}
switch (type) {
case B43_NTAB_8BIT:
*data = b43_phy_read(dev, B43_NPHY_TABLE_DATALO) & 0xFF;
data++;
break;
case B43_NTAB_16BIT:
*((u16 *)data) = b43_phy_read(dev, B43_NPHY_TABLE_DATALO);
data += 2;
break;
case B43_NTAB_32BIT:
*((u32 *)data) =
b43_phy_read(dev, B43_NPHY_TABLE_DATALO);
*((u32 *)data) |=
b43_phy_read(dev, B43_NPHY_TABLE_DATAHI) << 16;
data += 4;
break;
default:
B43_WARN_ON(1);
}
}
}
void b43_ntab_write(struct b43_wldev *dev, u32 offset, u32 value)
{
u32 type;
type = offset & B43_NTAB_TYPEMASK;
offset &= 0xFFFF;
switch (type) {
case B43_NTAB_8BIT:
B43_WARN_ON(value & ~0xFF);
b43_phy_write(dev, B43_NPHY_TABLE_ADDR, offset);
b43_phy_write(dev, B43_NPHY_TABLE_DATALO, value);
break;
case B43_NTAB_16BIT:
B43_WARN_ON(value & ~0xFFFF);
b43_phy_write(dev, B43_NPHY_TABLE_ADDR, offset);
b43_phy_write(dev, B43_NPHY_TABLE_DATALO, value);
break;
case B43_NTAB_32BIT:
b43_phy_write(dev, B43_NPHY_TABLE_ADDR, offset);
b43_phy_write(dev, B43_NPHY_TABLE_DATAHI, value >> 16);
b43_phy_write(dev, B43_NPHY_TABLE_DATALO, value & 0xFFFF);
break;
default:
B43_WARN_ON(1);
}
return;
assert_ntab_array_sizes();
}
void b43_ntab_write_bulk(struct b43_wldev *dev, u32 offset,
unsigned int nr_elements, const void *_data)
{
u32 type, value;
const u8 *data = _data;
unsigned int i;
type = offset & B43_NTAB_TYPEMASK;
offset &= ~B43_NTAB_TYPEMASK;
B43_WARN_ON(offset > 0xFFFF);
b43_phy_write(dev, B43_NPHY_TABLE_ADDR, offset);
for (i = 0; i < nr_elements; i++) {
if ((offset >> 10) == 9 && dev->dev->chip_id == 43224 &&
dev->dev->chip_rev == 1) {
b43_phy_read(dev, B43_NPHY_TABLE_DATALO);
b43_phy_write(dev, B43_NPHY_TABLE_ADDR, offset + i);
}
switch (type) {
case B43_NTAB_8BIT:
value = *data;
data++;
B43_WARN_ON(value & ~0xFF);
b43_phy_write(dev, B43_NPHY_TABLE_DATALO, value);
break;
case B43_NTAB_16BIT:
value = *((u16 *)data);
data += 2;
B43_WARN_ON(value & ~0xFFFF);
b43_phy_write(dev, B43_NPHY_TABLE_DATALO, value);
break;
case B43_NTAB_32BIT:
value = *((u32 *)data);
data += 4;
b43_phy_write(dev, B43_NPHY_TABLE_DATAHI, value >> 16);
b43_phy_write(dev, B43_NPHY_TABLE_DATALO,
value & 0xFFFF);
break;
default:
B43_WARN_ON(1);
}
}
}
static void b43_nphy_tables_init_rev3(struct b43_wldev *dev)
{
struct ssb_sprom *sprom = dev->dev->bus_sprom;
u8 antswlut;
if (b43_current_band(dev->wl) == IEEE80211_BAND_5GHZ)
antswlut = sprom->fem.ghz5.antswlut;
else
antswlut = sprom->fem.ghz2.antswlut;
if (dev->phy.do_full_init) {
ntab_upload(dev, B43_NTAB_FRAMESTRUCT_R3, b43_ntab_framestruct_r3);
ntab_upload(dev, B43_NTAB_PILOT_R3, b43_ntab_pilot_r3);
ntab_upload(dev, B43_NTAB_TMAP_R3, b43_ntab_tmap_r3);
ntab_upload(dev, B43_NTAB_INTLEVEL_R3, b43_ntab_intlevel_r3);
ntab_upload(dev, B43_NTAB_TDTRN_R3, b43_ntab_tdtrn_r3);
ntab_upload(dev, B43_NTAB_NOISEVAR_R3, b43_ntab_noisevar_r3);
ntab_upload(dev, B43_NTAB_MCS_R3, b43_ntab_mcs_r3);
ntab_upload(dev, B43_NTAB_TDI20A0_R3, b43_ntab_tdi20a0_r3);
ntab_upload(dev, B43_NTAB_TDI20A1_R3, b43_ntab_tdi20a1_r3);
ntab_upload(dev, B43_NTAB_TDI40A0_R3, b43_ntab_tdi40a0_r3);
ntab_upload(dev, B43_NTAB_TDI40A1_R3, b43_ntab_tdi40a1_r3);
ntab_upload(dev, B43_NTAB_PILOTLT_R3, b43_ntab_pilotlt_r3);
ntab_upload(dev, B43_NTAB_CHANEST_R3, b43_ntab_channelest_r3);
ntab_upload(dev, B43_NTAB_FRAMELT_R3, b43_ntab_framelookup_r3);
ntab_upload(dev, B43_NTAB_C0_ESTPLT_R3, b43_ntab_estimatepowerlt0_r3);
ntab_upload(dev, B43_NTAB_C1_ESTPLT_R3, b43_ntab_estimatepowerlt1_r3);
ntab_upload(dev, B43_NTAB_C0_ADJPLT_R3, b43_ntab_adjustpower0_r3);
ntab_upload(dev, B43_NTAB_C1_ADJPLT_R3, b43_ntab_adjustpower1_r3);
ntab_upload(dev, B43_NTAB_C0_GAINCTL_R3, b43_ntab_gainctl0_r3);
ntab_upload(dev, B43_NTAB_C1_GAINCTL_R3, b43_ntab_gainctl1_r3);
ntab_upload(dev, B43_NTAB_C0_IQLT_R3, b43_ntab_iqlt0_r3);
ntab_upload(dev, B43_NTAB_C1_IQLT_R3, b43_ntab_iqlt1_r3);
ntab_upload(dev, B43_NTAB_C0_LOFEEDTH_R3, b43_ntab_loftlt0_r3);
ntab_upload(dev, B43_NTAB_C1_LOFEEDTH_R3, b43_ntab_loftlt1_r3);
}
if (antswlut < ARRAY_SIZE(b43_ntab_antswctl_r3))
ntab_upload(dev, B43_NTAB_ANT_SW_CTL_R3,
b43_ntab_antswctl_r3[antswlut]);
else
B43_WARN_ON(1);
}
static void b43_nphy_tables_init_rev0(struct b43_wldev *dev)
{
if (dev->phy.do_full_init) {
ntab_upload(dev, B43_NTAB_FRAMESTRUCT, b43_ntab_framestruct);
ntab_upload(dev, B43_NTAB_FRAMELT, b43_ntab_framelookup);
ntab_upload(dev, B43_NTAB_TMAP, b43_ntab_tmap);
ntab_upload(dev, B43_NTAB_TDTRN, b43_ntab_tdtrn);
ntab_upload(dev, B43_NTAB_INTLEVEL, b43_ntab_intlevel);
ntab_upload(dev, B43_NTAB_PILOT, b43_ntab_pilot);
ntab_upload(dev, B43_NTAB_TDI20A0, b43_ntab_tdi20a0);
ntab_upload(dev, B43_NTAB_TDI20A1, b43_ntab_tdi20a1);
ntab_upload(dev, B43_NTAB_TDI40A0, b43_ntab_tdi40a0);
ntab_upload(dev, B43_NTAB_TDI40A1, b43_ntab_tdi40a1);
ntab_upload(dev, B43_NTAB_CHANEST, b43_ntab_channelest);
ntab_upload(dev, B43_NTAB_MCS, b43_ntab_mcs);
ntab_upload(dev, B43_NTAB_NOISEVAR10, b43_ntab_noisevar10);
ntab_upload(dev, B43_NTAB_NOISEVAR11, b43_ntab_noisevar11);
}
ntab_upload(dev, B43_NTAB_BDI, b43_ntab_bdi);
ntab_upload(dev, B43_NTAB_PILOTLT, b43_ntab_pilotlt);
ntab_upload(dev, B43_NTAB_C0_GAINCTL, b43_ntab_gainctl0);
ntab_upload(dev, B43_NTAB_C1_GAINCTL, b43_ntab_gainctl1);
ntab_upload(dev, B43_NTAB_C0_ESTPLT, b43_ntab_estimatepowerlt0);
ntab_upload(dev, B43_NTAB_C1_ESTPLT, b43_ntab_estimatepowerlt1);
ntab_upload(dev, B43_NTAB_C0_ADJPLT, b43_ntab_adjustpower0);
ntab_upload(dev, B43_NTAB_C1_ADJPLT, b43_ntab_adjustpower1);
ntab_upload(dev, B43_NTAB_C0_IQLT, b43_ntab_iqlt0);
ntab_upload(dev, B43_NTAB_C1_IQLT, b43_ntab_iqlt1);
ntab_upload(dev, B43_NTAB_C0_LOFEEDTH, b43_ntab_loftlt0);
ntab_upload(dev, B43_NTAB_C1_LOFEEDTH, b43_ntab_loftlt1);
}
void b43_nphy_tables_init(struct b43_wldev *dev)
{
if (dev->phy.rev >= 3)
b43_nphy_tables_init_rev3(dev);
else
b43_nphy_tables_init_rev0(dev);
}
static const u32 *b43_nphy_get_ipa_gain_table(struct b43_wldev *dev)
{
if (b43_current_band(dev->wl) == IEEE80211_BAND_2GHZ) {
if (dev->phy.rev >= 6) {
if (dev->dev->chip_id == 47162)
return txpwrctrl_tx_gain_ipa_rev5;
return txpwrctrl_tx_gain_ipa_rev6;
} else if (dev->phy.rev >= 5) {
return txpwrctrl_tx_gain_ipa_rev5;
} else {
return txpwrctrl_tx_gain_ipa;
}
} else {
return txpwrctrl_tx_gain_ipa_5g;
}
}
const u32 *b43_nphy_get_tx_gain_table(struct b43_wldev *dev)
{
enum ieee80211_band band = b43_current_band(dev->wl);
struct ssb_sprom *sprom = dev->dev->bus_sprom;
if (dev->phy.rev < 3)
return b43_ntab_tx_gain_rev0_1_2;
if ((dev->phy.n->ipa2g_on && band == IEEE80211_BAND_2GHZ) ||
(dev->phy.n->ipa5g_on && band == IEEE80211_BAND_5GHZ)) {
return b43_nphy_get_ipa_gain_table(dev);
} else if (b43_current_band(dev->wl) == IEEE80211_BAND_5GHZ) {
if (dev->phy.rev == 3)
return b43_ntab_tx_gain_rev3_5ghz;
if (dev->phy.rev == 4)
return sprom->fem.ghz5.extpa_gain == 3 ?
b43_ntab_tx_gain_rev4_5ghz :
b43_ntab_tx_gain_rev4_5ghz;
else
return b43_ntab_tx_gain_rev5plus_5ghz;
} else {
if (dev->phy.rev >= 5 && sprom->fem.ghz5.extpa_gain == 3)
return b43_ntab_tx_gain_rev3plus_2ghz;
else
return b43_ntab_tx_gain_rev3plus_2ghz;
}
}
struct nphy_gain_ctl_workaround_entry *b43_nphy_get_gain_ctl_workaround_ent(
struct b43_wldev *dev, bool ghz5, bool ext_lna)
{
struct nphy_gain_ctl_workaround_entry *e;
u8 phy_idx;
if (!ghz5 && dev->phy.rev >= 6 && dev->phy.radio_rev == 11)
return &nphy_gain_ctl_wa_phy6_radio11_ghz2;
B43_WARN_ON(dev->phy.rev < 3);
if (dev->phy.rev >= 6)
phy_idx = 3;
else if (dev->phy.rev == 5)
phy_idx = 2;
else if (dev->phy.rev == 4)
phy_idx = 1;
else
phy_idx = 0;
e = &nphy_gain_ctl_workaround[ghz5][phy_idx];
if (ghz5 && dev->phy.rev >= 6) {
if (dev->phy.radio_rev == 11 &&
!b43_channel_type_is_40mhz(dev->phy.channel_type))
e->cliplo_gain = 0x2d;
} else if (!ghz5 && dev->phy.rev >= 5) {
static const int gain_data[] = {0x0062, 0x0064, 0x006a, 0x106a,
0x106c, 0x1074, 0x107c, 0x207c};
u8 tr_iso = dev->dev->bus_sprom->fem.ghz2.tr_iso;
if (ext_lna) {
e->rfseq_init[0] &= ~0x4000;
e->rfseq_init[1] &= ~0x4000;
e->rfseq_init[2] &= ~0x4000;
e->rfseq_init[3] &= ~0x4000;
e->init_gain &= ~0x4000;
}
if (tr_iso > 7)
tr_iso = 3;
e->cliplo_gain = gain_data[tr_iso];
} else if (ghz5 && dev->phy.rev == 4 && ext_lna) {
e->rfseq_init[0] &= ~0x4000;
e->rfseq_init[1] &= ~0x4000;
e->rfseq_init[2] &= ~0x4000;
e->rfseq_init[3] &= ~0x4000;
e->init_gain &= ~0x4000;
e->rfseq_init[0] |= 0x1000;
e->rfseq_init[1] |= 0x1000;
e->rfseq_init[2] |= 0x1000;
e->rfseq_init[3] |= 0x1000;
e->init_gain |= 0x1000;
}
return e;
}
const struct nphy_rf_control_override_rev7 *b43_nphy_get_rf_ctl_over_rev7(
struct b43_wldev *dev, u16 field, u8 override)
{
const struct nphy_rf_control_override_rev7 *e;
u8 size, i;
switch (override) {
case 0:
e = tbl_rf_control_override_rev7_over0;
size = ARRAY_SIZE(tbl_rf_control_override_rev7_over0);
break;
case 1:
e = tbl_rf_control_override_rev7_over1;
size = ARRAY_SIZE(tbl_rf_control_override_rev7_over1);
break;
case 2:
e = tbl_rf_control_override_rev7_over2;
size = ARRAY_SIZE(tbl_rf_control_override_rev7_over2);
break;
default:
b43err(dev->wl, "Invalid override value %d\n", override);
return NULL;
}
for (i = 0; i < size; i++) {
if (e[i].field == field)
return &e[i];
}
return NULL;
}
