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
