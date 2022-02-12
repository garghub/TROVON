static int swphy_decode_speed(int speed)
{
switch (speed) {
case 1000:
return SWMII_SPEED_1000;
case 100:
return SWMII_SPEED_100;
case 10:
return SWMII_SPEED_10;
default:
return -EINVAL;
}
}
int swphy_validate_state(const struct fixed_phy_status *state)
{
int err;
if (state->link) {
err = swphy_decode_speed(state->speed);
if (err < 0) {
pr_warn("swphy: unknown speed\n");
return -EINVAL;
}
}
return 0;
}
int swphy_read_reg(int reg, const struct fixed_phy_status *state)
{
int speed_index, duplex_index;
u16 bmsr = BMSR_ANEGCAPABLE;
u16 bmcr = 0;
u16 lpagb = 0;
u16 lpa = 0;
if (reg > MII_REGS_NUM)
return -1;
speed_index = swphy_decode_speed(state->speed);
if (WARN_ON(speed_index < 0))
return 0;
duplex_index = state->duplex ? SWMII_DUPLEX_FULL : SWMII_DUPLEX_HALF;
bmsr |= speed[speed_index].bmsr & duplex[duplex_index].bmsr;
if (state->link) {
bmsr |= BMSR_LSTATUS | BMSR_ANEGCOMPLETE;
bmcr |= speed[speed_index].bmcr & duplex[duplex_index].bmcr;
lpa |= speed[speed_index].lpa & duplex[duplex_index].lpa;
lpagb |= speed[speed_index].lpagb & duplex[duplex_index].lpagb;
if (state->pause)
lpa |= LPA_PAUSE_CAP;
if (state->asym_pause)
lpa |= LPA_PAUSE_ASYM;
}
switch (reg) {
case MII_BMCR:
return bmcr;
case MII_BMSR:
return bmsr;
case MII_PHYSID1:
case MII_PHYSID2:
return 0;
case MII_LPA:
return lpa;
case MII_STAT1000:
return lpagb;
case MII_MMD_CTRL:
case MII_MMD_DATA:
return -1;
default:
return 0xffff;
}
}
