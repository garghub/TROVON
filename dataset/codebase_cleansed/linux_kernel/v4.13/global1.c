int mv88e6xxx_g1_read(struct mv88e6xxx_chip *chip, int reg, u16 *val)
{
int addr = chip->info->global1_addr;
return mv88e6xxx_read(chip, addr, reg, val);
}
int mv88e6xxx_g1_write(struct mv88e6xxx_chip *chip, int reg, u16 val)
{
int addr = chip->info->global1_addr;
return mv88e6xxx_write(chip, addr, reg, val);
}
int mv88e6xxx_g1_wait(struct mv88e6xxx_chip *chip, int reg, u16 mask)
{
return mv88e6xxx_wait(chip, chip->info->global1_addr, reg, mask);
}
static int mv88e6185_g1_wait_ppu_disabled(struct mv88e6xxx_chip *chip)
{
u16 state;
int i, err;
for (i = 0; i < 16; i++) {
err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STS, &state);
if (err)
return err;
state &= MV88E6185_G1_STS_PPU_STATE_MASK;
if (state != MV88E6185_G1_STS_PPU_STATE_POLLING)
return 0;
usleep_range(1000, 2000);
}
return -ETIMEDOUT;
}
static int mv88e6185_g1_wait_ppu_polling(struct mv88e6xxx_chip *chip)
{
u16 state;
int i, err;
for (i = 0; i < 16; ++i) {
err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STS, &state);
if (err)
return err;
state &= MV88E6185_G1_STS_PPU_STATE_MASK;
if (state == MV88E6185_G1_STS_PPU_STATE_POLLING)
return 0;
usleep_range(1000, 2000);
}
return -ETIMEDOUT;
}
static int mv88e6352_g1_wait_ppu_polling(struct mv88e6xxx_chip *chip)
{
u16 state;
int i, err;
for (i = 0; i < 16; ++i) {
err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STS, &state);
if (err)
return err;
if (state & MV88E6352_G1_STS_PPU_STATE)
return 0;
usleep_range(1000, 2000);
}
return -ETIMEDOUT;
}
static int mv88e6xxx_g1_wait_init_ready(struct mv88e6xxx_chip *chip)
{
const unsigned long timeout = jiffies + 1 * HZ;
u16 val;
int err;
while (time_before(jiffies, timeout)) {
err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STS, &val);
if (err)
return err;
if (val & MV88E6XXX_G1_STS_INIT_READY)
break;
usleep_range(1000, 2000);
}
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
return 0;
}
int mv88e6xxx_g1_set_switch_mac(struct mv88e6xxx_chip *chip, u8 *addr)
{
u16 reg;
int err;
reg = (addr[0] << 8) | addr[1];
err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_MAC_01, reg);
if (err)
return err;
reg = (addr[2] << 8) | addr[3];
err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_MAC_23, reg);
if (err)
return err;
reg = (addr[4] << 8) | addr[5];
err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_MAC_45, reg);
if (err)
return err;
return 0;
}
int mv88e6185_g1_reset(struct mv88e6xxx_chip *chip)
{
u16 val;
int err;
err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_CTL1, &val);
if (err)
return err;
val |= MV88E6XXX_G1_CTL1_SW_RESET;
val |= MV88E6XXX_G1_CTL1_PPU_ENABLE;
err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_CTL1, val);
if (err)
return err;
err = mv88e6xxx_g1_wait_init_ready(chip);
if (err)
return err;
return mv88e6185_g1_wait_ppu_polling(chip);
}
int mv88e6352_g1_reset(struct mv88e6xxx_chip *chip)
{
u16 val;
int err;
err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_CTL1, &val);
if (err)
return err;
val |= MV88E6XXX_G1_CTL1_SW_RESET;
err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_CTL1, val);
if (err)
return err;
err = mv88e6xxx_g1_wait_init_ready(chip);
if (err)
return err;
return mv88e6352_g1_wait_ppu_polling(chip);
}
int mv88e6185_g1_ppu_enable(struct mv88e6xxx_chip *chip)
{
u16 val;
int err;
err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_CTL1, &val);
if (err)
return err;
val |= MV88E6XXX_G1_CTL1_PPU_ENABLE;
err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_CTL1, val);
if (err)
return err;
return mv88e6185_g1_wait_ppu_polling(chip);
}
int mv88e6185_g1_ppu_disable(struct mv88e6xxx_chip *chip)
{
u16 val;
int err;
err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_CTL1, &val);
if (err)
return err;
val &= ~MV88E6XXX_G1_CTL1_PPU_ENABLE;
err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_CTL1, val);
if (err)
return err;
return mv88e6185_g1_wait_ppu_disabled(chip);
}
int mv88e6095_g1_set_egress_port(struct mv88e6xxx_chip *chip, int port)
{
u16 reg;
int err;
err = mv88e6xxx_g1_read(chip, MV88E6185_G1_MONITOR_CTL, &reg);
if (err)
return err;
reg &= ~(MV88E6185_G1_MONITOR_CTL_INGRESS_DEST_MASK |
MV88E6185_G1_MONITOR_CTL_EGRESS_DEST_MASK);
reg |= port << __bf_shf(MV88E6185_G1_MONITOR_CTL_INGRESS_DEST_MASK) |
port << __bf_shf(MV88E6185_G1_MONITOR_CTL_EGRESS_DEST_MASK);
return mv88e6xxx_g1_write(chip, MV88E6185_G1_MONITOR_CTL, reg);
}
int mv88e6095_g1_set_cpu_port(struct mv88e6xxx_chip *chip, int port)
{
u16 reg;
int err;
err = mv88e6xxx_g1_read(chip, MV88E6185_G1_MONITOR_CTL, &reg);
if (err)
return err;
reg &= ~MV88E6185_G1_MONITOR_CTL_ARP_DEST_MASK;
reg |= port << __bf_shf(MV88E6185_G1_MONITOR_CTL_ARP_DEST_MASK);
return mv88e6xxx_g1_write(chip, MV88E6185_G1_MONITOR_CTL, reg);
}
static int mv88e6390_g1_monitor_write(struct mv88e6xxx_chip *chip,
u16 pointer, u8 data)
{
u16 reg;
reg = MV88E6390_G1_MONITOR_MGMT_CTL_UPDATE | pointer | data;
return mv88e6xxx_g1_write(chip, MV88E6390_G1_MONITOR_MGMT_CTL, reg);
}
int mv88e6390_g1_set_egress_port(struct mv88e6xxx_chip *chip, int port)
{
u16 ptr;
int err;
ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_INGRESS_DEST;
err = mv88e6390_g1_monitor_write(chip, ptr, port);
if (err)
return err;
ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_EGRESS_DEST;
err = mv88e6390_g1_monitor_write(chip, ptr, port);
if (err)
return err;
return 0;
}
int mv88e6390_g1_set_cpu_port(struct mv88e6xxx_chip *chip, int port)
{
u16 ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_CPU_DEST;
return mv88e6390_g1_monitor_write(chip, ptr, port);
}
int mv88e6390_g1_mgmt_rsvd2cpu(struct mv88e6xxx_chip *chip)
{
u16 ptr;
int err;
ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_0180C280000000XLO;
err = mv88e6390_g1_monitor_write(chip, ptr, 0xff);
if (err)
return err;
ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_0180C280000000XHI;
err = mv88e6390_g1_monitor_write(chip, ptr, 0xff);
if (err)
return err;
ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_0180C280000002XLO;
err = mv88e6390_g1_monitor_write(chip, ptr, 0xff);
if (err)
return err;
ptr = MV88E6390_G1_MONITOR_MGMT_CTL_PTR_0180C280000002XHI;
err = mv88e6390_g1_monitor_write(chip, ptr, 0xff);
if (err)
return err;
return 0;
}
int mv88e6390_g1_stats_set_histogram(struct mv88e6xxx_chip *chip)
{
u16 val;
int err;
err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_CTL2, &val);
if (err)
return err;
val |= MV88E6XXX_G1_CTL2_HIST_RX_TX;
err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_CTL2, val);
return err;
}
int mv88e6xxx_g1_stats_wait(struct mv88e6xxx_chip *chip)
{
return mv88e6xxx_g1_wait(chip, MV88E6XXX_G1_STATS_OP,
MV88E6XXX_G1_STATS_OP_BUSY);
}
int mv88e6xxx_g1_stats_snapshot(struct mv88e6xxx_chip *chip, int port)
{
int err;
err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_STATS_OP,
MV88E6XXX_G1_STATS_OP_BUSY |
MV88E6XXX_G1_STATS_OP_CAPTURE_PORT |
MV88E6XXX_G1_STATS_OP_HIST_RX_TX | port);
if (err)
return err;
return mv88e6xxx_g1_stats_wait(chip);
}
int mv88e6320_g1_stats_snapshot(struct mv88e6xxx_chip *chip, int port)
{
port = (port + 1) << 5;
return mv88e6xxx_g1_stats_snapshot(chip, port);
}
int mv88e6390_g1_stats_snapshot(struct mv88e6xxx_chip *chip, int port)
{
int err;
port = (port + 1) << 5;
err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_STATS_OP,
MV88E6XXX_G1_STATS_OP_BUSY |
MV88E6XXX_G1_STATS_OP_CAPTURE_PORT | port);
if (err)
return err;
return mv88e6xxx_g1_stats_wait(chip);
}
void mv88e6xxx_g1_stats_read(struct mv88e6xxx_chip *chip, int stat, u32 *val)
{
u32 value;
u16 reg;
int err;
*val = 0;
err = mv88e6xxx_g1_write(chip, MV88E6XXX_G1_STATS_OP,
MV88E6XXX_G1_STATS_OP_BUSY |
MV88E6XXX_G1_STATS_OP_READ_CAPTURED | stat);
if (err)
return;
err = mv88e6xxx_g1_stats_wait(chip);
if (err)
return;
err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STATS_COUNTER_32, &reg);
if (err)
return;
value = reg << 16;
err = mv88e6xxx_g1_read(chip, MV88E6XXX_G1_STATS_COUNTER_01, &reg);
if (err)
return;
*val = value | reg;
}
