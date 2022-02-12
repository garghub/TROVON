static const struct b2056_inittabs_pts
*b43_nphy_get_inittabs_rev3(struct b43_wldev *dev)
{
struct b43_phy *phy = &dev->phy;
switch (dev->phy.rev) {
case 3:
return &b2056_inittab_phy_rev3;
case 4:
return &b2056_inittab_phy_rev4;
default:
switch (phy->radio_rev) {
case 5:
return &b2056_inittab_radio_rev5;
case 6:
return &b2056_inittab_radio_rev6;
case 7:
case 9:
return &b2056_inittab_radio_rev7_9;
case 8:
return &b2056_inittab_radio_rev8;
case 11:
return &b2056_inittab_radio_rev11;
}
}
return NULL;
}
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
const struct b2056_inittabs_pts *pts;
pts = b43_nphy_get_inittabs_rev3(dev);
if (!pts) {
B43_WARN_ON(1);
return;
}
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
void b2056_upload_syn_pll_cp2(struct b43_wldev *dev, bool ghz5)
{
const struct b2056_inittabs_pts *pts;
const struct b2056_inittab_entry *e;
pts = b43_nphy_get_inittabs_rev3(dev);
if (!pts) {
B43_WARN_ON(1);
return;
}
e = &pts->syn[B2056_SYN_PLL_CP2];
b43_radio_write(dev, B2056_SYN_PLL_CP2, ghz5 ? e->ghz5 : e->ghz2);
}
const struct b43_nphy_channeltab_entry_rev3 *
b43_nphy_get_chantabent_rev3(struct b43_wldev *dev, u16 freq)
{
struct b43_phy *phy = &dev->phy;
const struct b43_nphy_channeltab_entry_rev3 *e;
unsigned int length, i;
switch (phy->rev) {
case 3:
e = b43_nphy_channeltab_phy_rev3;
length = ARRAY_SIZE(b43_nphy_channeltab_phy_rev3);
break;
case 4:
e = b43_nphy_channeltab_phy_rev4;
length = ARRAY_SIZE(b43_nphy_channeltab_phy_rev4);
break;
default:
switch (phy->radio_rev) {
case 5:
e = b43_nphy_channeltab_radio_rev5;
length = ARRAY_SIZE(b43_nphy_channeltab_radio_rev5);
break;
case 6:
e = b43_nphy_channeltab_radio_rev6;
length = ARRAY_SIZE(b43_nphy_channeltab_radio_rev6);
break;
case 7:
case 9:
e = b43_nphy_channeltab_radio_rev7_9;
length = ARRAY_SIZE(b43_nphy_channeltab_radio_rev7_9);
break;
case 8:
e = b43_nphy_channeltab_radio_rev8;
length = ARRAY_SIZE(b43_nphy_channeltab_radio_rev8);
break;
case 11:
e = b43_nphy_channeltab_radio_rev11;
length = ARRAY_SIZE(b43_nphy_channeltab_radio_rev11);
break;
default:
B43_WARN_ON(1);
return NULL;
}
}
for (i = 0; i < length; i++, e++) {
if (e->freq == freq)
return e;
}
return NULL;
}
