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
err = mv88e6xxx_g1_read(chip, GLOBAL_STATUS, &state);
if (err)
return err;
state &= GLOBAL_STATUS_PPU_STATE_MASK;
if (state != GLOBAL_STATUS_PPU_STATE_POLLING)
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
err = mv88e6xxx_g1_read(chip, GLOBAL_STATUS, &state);
if (err)
return err;
state &= GLOBAL_STATUS_PPU_STATE_MASK;
if (state == GLOBAL_STATUS_PPU_STATE_POLLING)
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
err = mv88e6xxx_g1_read(chip, GLOBAL_STATUS, &state);
if (err)
return err;
if (state & GLOBAL_STATUS_PPU_STATE)
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
err = mv88e6xxx_g1_read(chip, GLOBAL_STATUS, &val);
if (err)
return err;
if (val & GLOBAL_STATUS_INIT_READY)
break;
usleep_range(1000, 2000);
}
if (time_after(jiffies, timeout))
return -ETIMEDOUT;
return 0;
}
int mv88e6185_g1_reset(struct mv88e6xxx_chip *chip)
{
u16 val;
int err;
err = mv88e6xxx_g1_read(chip, GLOBAL_CONTROL, &val);
if (err)
return err;
val |= GLOBAL_CONTROL_SW_RESET;
val |= GLOBAL_CONTROL_PPU_ENABLE;
err = mv88e6xxx_g1_write(chip, GLOBAL_CONTROL, val);
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
err = mv88e6xxx_g1_read(chip, GLOBAL_CONTROL, &val);
if (err)
return err;
val |= GLOBAL_CONTROL_SW_RESET;
err = mv88e6xxx_g1_write(chip, GLOBAL_CONTROL, val);
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
err = mv88e6xxx_g1_read(chip, GLOBAL_CONTROL, &val);
if (err)
return err;
val |= GLOBAL_CONTROL_PPU_ENABLE;
err = mv88e6xxx_g1_write(chip, GLOBAL_CONTROL, val);
if (err)
return err;
return mv88e6185_g1_wait_ppu_polling(chip);
}
int mv88e6185_g1_ppu_disable(struct mv88e6xxx_chip *chip)
{
u16 val;
int err;
err = mv88e6xxx_g1_read(chip, GLOBAL_CONTROL, &val);
if (err)
return err;
val &= ~GLOBAL_CONTROL_PPU_ENABLE;
err = mv88e6xxx_g1_write(chip, GLOBAL_CONTROL, val);
if (err)
return err;
return mv88e6185_g1_wait_ppu_disabled(chip);
}
int mv88e6095_g1_set_egress_port(struct mv88e6xxx_chip *chip, int port)
{
u16 reg;
int err;
err = mv88e6xxx_g1_read(chip, GLOBAL_MONITOR_CONTROL, &reg);
if (err)
return err;
reg &= ~(GLOBAL_MONITOR_CONTROL_INGRESS_MASK |
GLOBAL_MONITOR_CONTROL_EGRESS_MASK);
reg |= port << GLOBAL_MONITOR_CONTROL_INGRESS_SHIFT |
port << GLOBAL_MONITOR_CONTROL_EGRESS_SHIFT;
return mv88e6xxx_g1_write(chip, GLOBAL_MONITOR_CONTROL, reg);
}
int mv88e6095_g1_set_cpu_port(struct mv88e6xxx_chip *chip, int port)
{
u16 reg;
int err;
err = mv88e6xxx_g1_read(chip, GLOBAL_MONITOR_CONTROL, &reg);
if (err)
return err;
reg &= ~GLOBAL_MONITOR_CONTROL_ARP_MASK;
reg |= port << GLOBAL_MONITOR_CONTROL_ARP_SHIFT;
return mv88e6xxx_g1_write(chip, GLOBAL_MONITOR_CONTROL, reg);
}
static int mv88e6390_g1_monitor_write(struct mv88e6xxx_chip *chip,
u16 pointer, u8 data)
{
u16 reg;
reg = GLOBAL_MONITOR_CONTROL_UPDATE | pointer | data;
return mv88e6xxx_g1_write(chip, GLOBAL_MONITOR_CONTROL, reg);
}
int mv88e6390_g1_set_egress_port(struct mv88e6xxx_chip *chip, int port)
{
int err;
err = mv88e6390_g1_monitor_write(chip, GLOBAL_MONITOR_CONTROL_INGRESS,
port);
if (err)
return err;
return mv88e6390_g1_monitor_write(chip, GLOBAL_MONITOR_CONTROL_EGRESS,
port);
}
int mv88e6390_g1_set_cpu_port(struct mv88e6xxx_chip *chip, int port)
{
return mv88e6390_g1_monitor_write(chip, GLOBAL_MONITOR_CONTROL_CPU_DEST,
port);
}
int mv88e6390_g1_mgmt_rsvd2cpu(struct mv88e6xxx_chip *chip)
{
int err;
err = mv88e6390_g1_monitor_write(
chip, GLOBAL_MONITOR_CONTROL_0180C280000000XLO, 0xff);
if (err)
return err;
err = mv88e6390_g1_monitor_write(
chip, GLOBAL_MONITOR_CONTROL_0180C280000000XHI, 0xff);
if (err)
return err;
err = mv88e6390_g1_monitor_write(
chip, GLOBAL_MONITOR_CONTROL_0180C280000002XLO, 0xff);
if (err)
return err;
return mv88e6390_g1_monitor_write(
chip, GLOBAL_MONITOR_CONTROL_0180C280000002XHI, 0xff);
}
int mv88e6390_g1_stats_set_histogram(struct mv88e6xxx_chip *chip)
{
u16 val;
int err;
err = mv88e6xxx_g1_read(chip, GLOBAL_CONTROL_2, &val);
if (err)
return err;
val |= GLOBAL_CONTROL_2_HIST_RX_TX;
err = mv88e6xxx_g1_write(chip, GLOBAL_CONTROL_2, val);
return err;
}
int mv88e6xxx_g1_stats_wait(struct mv88e6xxx_chip *chip)
{
return mv88e6xxx_g1_wait(chip, GLOBAL_STATS_OP, GLOBAL_STATS_OP_BUSY);
}
int mv88e6xxx_g1_stats_snapshot(struct mv88e6xxx_chip *chip, int port)
{
int err;
err = mv88e6xxx_g1_write(chip, GLOBAL_STATS_OP,
GLOBAL_STATS_OP_CAPTURE_PORT |
GLOBAL_STATS_OP_HIST_RX_TX | port);
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
err = mv88e6xxx_g1_write(chip, GLOBAL_STATS_OP,
GLOBAL_STATS_OP_CAPTURE_PORT | port);
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
err = mv88e6xxx_g1_write(chip, GLOBAL_STATS_OP,
GLOBAL_STATS_OP_READ_CAPTURED | stat);
if (err)
return;
err = mv88e6xxx_g1_stats_wait(chip);
if (err)
return;
err = mv88e6xxx_g1_read(chip, GLOBAL_STATS_COUNTER_32, &reg);
if (err)
return;
value = reg << 16;
err = mv88e6xxx_g1_read(chip, GLOBAL_STATS_COUNTER_01, &reg);
if (err)
return;
*val = value | reg;
}
