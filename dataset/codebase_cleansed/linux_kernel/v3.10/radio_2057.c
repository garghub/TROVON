void r2057_upload_inittabs(struct b43_wldev *dev)
{
struct b43_phy *phy = &dev->phy;
u16 *table = NULL;
u16 size, i;
if (phy->rev == 7) {
table = r2057_rev4_init[0];
size = ARRAY_SIZE(r2057_rev4_init);
} else if (phy->rev == 8 || phy->rev == 9) {
if (phy->radio_rev == 5) {
if (phy->radio_rev == 8) {
table = r2057_rev5_init[0];
size = ARRAY_SIZE(r2057_rev5_init);
} else {
table = r2057_rev5a_init[0];
size = ARRAY_SIZE(r2057_rev5a_init);
}
} else if (phy->radio_rev == 7) {
table = r2057_rev7_init[0];
size = ARRAY_SIZE(r2057_rev7_init);
} else if (phy->radio_rev == 9) {
table = r2057_rev8_init[0];
size = ARRAY_SIZE(r2057_rev8_init);
}
}
if (table) {
for (i = 0; i < 10; i++) {
pr_info("radio_write 0x%X ", *table);
table++;
pr_info("0x%X\n", *table);
table++;
}
}
}
