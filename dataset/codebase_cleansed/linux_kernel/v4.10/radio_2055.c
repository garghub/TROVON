void b2055_upload_inittab(struct b43_wldev *dev,
bool ghz5, bool ignore_uploadflag)
{
const struct b2055_inittab_entry *e;
unsigned int i, writes = 0;
u16 value;
for (i = 0; i < ARRAY_SIZE(b2055_inittab); i++) {
e = &(b2055_inittab[i]);
if (!(e->flags & B2055_INITTAB_ENTRY_OK))
continue;
if ((e->flags & B2055_INITTAB_UPLOAD) || ignore_uploadflag) {
if (ghz5)
value = e->ghz5;
else
value = e->ghz2;
b43_radio_write16(dev, i, value);
if (++writes % 4 == 0)
b43_read32(dev, B43_MMIO_MACCTL);
}
}
}
const struct b43_nphy_channeltab_entry_rev2 *
b43_nphy_get_chantabent_rev2(struct b43_wldev *dev, u8 channel)
{
const struct b43_nphy_channeltab_entry_rev2 *e;
unsigned int i;
for (i = 0; i < ARRAY_SIZE(b43_nphy_channeltab_rev2); i++) {
e = &(b43_nphy_channeltab_rev2[i]);
if (e->channel == channel)
return e;
}
return NULL;
}
