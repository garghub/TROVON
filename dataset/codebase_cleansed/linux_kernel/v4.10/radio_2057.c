void r2057_upload_inittabs(struct b43_wldev *dev)
{
struct b43_phy *phy = &dev->phy;
u16 *table = NULL;
u16 size, i;
switch (phy->rev) {
case 7:
table = r2057_rev4_init[0];
size = ARRAY_SIZE(r2057_rev4_init);
break;
case 8:
if (phy->radio_rev == 5) {
table = r2057_rev5_init[0];
size = ARRAY_SIZE(r2057_rev5_init);
} else if (phy->radio_rev == 7) {
table = r2057_rev7_init[0];
size = ARRAY_SIZE(r2057_rev7_init);
}
break;
case 9:
if (phy->radio_rev == 5) {
table = r2057_rev5a_init[0];
size = ARRAY_SIZE(r2057_rev5a_init);
}
break;
case 16:
if (phy->radio_rev == 9) {
table = r2057_rev9_init[0];
size = ARRAY_SIZE(r2057_rev9_init);
}
break;
case 17:
if (phy->radio_rev == 14) {
table = r2057_rev14_init[0];
size = ARRAY_SIZE(r2057_rev14_init);
}
break;
}
B43_WARN_ON(!table);
if (table) {
for (i = 0; i < size; i++, table += 2)
b43_radio_write(dev, table[0], table[1]);
}
}
void r2057_get_chantabent_rev7(struct b43_wldev *dev, u16 freq,
const struct b43_nphy_chantabent_rev7 **tabent_r7,
const struct b43_nphy_chantabent_rev7_2g **tabent_r7_2g)
{
struct b43_phy *phy = &dev->phy;
const struct b43_nphy_chantabent_rev7 *e_r7 = NULL;
const struct b43_nphy_chantabent_rev7_2g *e_r7_2g = NULL;
unsigned int len, i;
*tabent_r7 = NULL;
*tabent_r7_2g = NULL;
switch (phy->rev) {
case 8:
if (phy->radio_rev == 5) {
e_r7_2g = b43_nphy_chantab_phy_rev8_radio_rev5;
len = ARRAY_SIZE(b43_nphy_chantab_phy_rev8_radio_rev5);
}
break;
case 16:
if (phy->radio_rev == 9) {
e_r7 = b43_nphy_chantab_phy_rev16_radio_rev9;
len = ARRAY_SIZE(b43_nphy_chantab_phy_rev16_radio_rev9);
}
break;
case 17:
if (phy->radio_rev == 14) {
e_r7_2g = b43_nphy_chantab_phy_rev17_radio_rev14;
len = ARRAY_SIZE(b43_nphy_chantab_phy_rev17_radio_rev14);
}
break;
default:
break;
}
if (e_r7) {
for (i = 0; i < len; i++, e_r7++) {
if (e_r7->freq == freq) {
*tabent_r7 = e_r7;
return;
}
}
} else if (e_r7_2g) {
for (i = 0; i < len; i++, e_r7_2g++) {
if (e_r7_2g->freq == freq) {
*tabent_r7_2g = e_r7_2g;
return;
}
}
} else {
B43_WARN_ON(1);
}
}
