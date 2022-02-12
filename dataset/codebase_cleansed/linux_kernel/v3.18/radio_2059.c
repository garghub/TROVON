void r2059_upload_inittabs(struct b43_wldev *dev)
{
struct b43_phy *phy = &dev->phy;
u16 *table = NULL;
u16 size, i;
switch (phy->rev) {
case 1:
table = r2059_phy_rev1_init[0];
size = ARRAY_SIZE(r2059_phy_rev1_init);
break;
default:
B43_WARN_ON(1);
return;
}
for (i = 0; i < size; i++, table += 2)
b43_radio_write(dev, R2059_ALL | table[0], table[1]);
}
const struct b43_phy_ht_channeltab_e_radio2059
*b43_phy_ht_get_channeltab_e_r2059(struct b43_wldev *dev, u16 freq)
{
const struct b43_phy_ht_channeltab_e_radio2059 *e;
unsigned int i;
e = b43_phy_ht_channeltab_radio2059;
for (i = 0; i < ARRAY_SIZE(b43_phy_ht_channeltab_radio2059); i++, e++) {
if (e->freq == freq)
return e;
}
return NULL;
}
