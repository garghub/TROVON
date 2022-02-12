static void b2056_upload_inittab(struct b43_wldev *dev, bool ghz5,
bool ignore_uploadflag, u16 routing,
const struct b2056_inittab_entry *e,
unsigned int length)
{
unsigned int i;
u16 value;
for (i = 0; i < length; i++, e++) {
if (!(e->flags & B2056_INITTAB_ENTRY_OK))
continue;
if ((e->flags & B2056_INITTAB_UPLOAD) || ignore_uploadflag) {
if (ghz5)
value = e->ghz5;
else
value = e->ghz2;
b43_radio_write(dev, routing | i, value);
}
}
}
void b2056_upload_inittabs(struct b43_wldev *dev,
bool ghz5, bool ignore_uploadflag)
{
struct b2056_inittabs_pts *pts;
if (dev->phy.rev >= ARRAY_SIZE(b2056_inittabs)) {
B43_WARN_ON(1);
return;
}
pts = &b2056_inittabs[dev->phy.rev];
b2056_upload_inittab(dev, ghz5, ignore_uploadflag,
B2056_SYN, pts->syn, pts->syn_length);
b2056_upload_inittab(dev, ghz5, ignore_uploadflag,
B2056_TX0, pts->tx, pts->tx_length);
b2056_upload_inittab(dev, ghz5, ignore_uploadflag,
B2056_TX1, pts->tx, pts->tx_length);
b2056_upload_inittab(dev, ghz5, ignore_uploadflag,
B2056_RX0, pts->rx, pts->rx_length);
b2056_upload_inittab(dev, ghz5, ignore_uploadflag,
B2056_RX1, pts->rx, pts->rx_length);
}
const struct b43_nphy_channeltab_entry_rev3 *
b43_nphy_get_chantabent_rev3(struct b43_wldev *dev, u16 freq)
{
const struct b43_nphy_channeltab_entry_rev3 *e;
unsigned int length, i;
switch (dev->phy.rev) {
case 3:
e = b43_nphy_channeltab_rev3;
length = ARRAY_SIZE(b43_nphy_channeltab_rev3);
break;
case 4:
e = b43_nphy_channeltab_rev4;
length = ARRAY_SIZE(b43_nphy_channeltab_rev4);
break;
case 5:
e = b43_nphy_channeltab_rev5;
length = ARRAY_SIZE(b43_nphy_channeltab_rev5);
break;
case 6:
e = b43_nphy_channeltab_rev6;
length = ARRAY_SIZE(b43_nphy_channeltab_rev6);
break;
case 7:
case 9:
e = b43_nphy_channeltab_rev7_9;
length = ARRAY_SIZE(b43_nphy_channeltab_rev7_9);
break;
case 8:
e = b43_nphy_channeltab_rev8;
length = ARRAY_SIZE(b43_nphy_channeltab_rev8);
break;
default:
B43_WARN_ON(1);
return NULL;
}
for (i = 0; i < length; i++, e++) {
if (e->freq == freq)
return e;
}
return NULL;
}
