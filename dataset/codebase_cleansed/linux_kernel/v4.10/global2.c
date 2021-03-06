static int mv88e6xxx_g2_read(struct mv88e6xxx_chip *chip, int reg, u16 *val)
{
return mv88e6xxx_read(chip, ADDR_GLOBAL2, reg, val);
}
static int mv88e6xxx_g2_write(struct mv88e6xxx_chip *chip, int reg, u16 val)
{
return mv88e6xxx_write(chip, ADDR_GLOBAL2, reg, val);
}
static int mv88e6xxx_g2_update(struct mv88e6xxx_chip *chip, int reg, u16 update)
{
return mv88e6xxx_update(chip, ADDR_GLOBAL2, reg, update);
}
static int mv88e6xxx_g2_wait(struct mv88e6xxx_chip *chip, int reg, u16 mask)
{
return mv88e6xxx_wait(chip, ADDR_GLOBAL2, reg, mask);
}
int mv88e6095_g2_mgmt_rsvd2cpu(struct mv88e6xxx_chip *chip)
{
int err;
if (mv88e6xxx_has(chip, MV88E6XXX_FLAG_G2_MGMT_EN_2X)) {
err = mv88e6xxx_g2_write(chip, GLOBAL2_MGMT_EN_2X, 0xffff);
if (err)
return err;
}
if (mv88e6xxx_has(chip, MV88E6XXX_FLAG_G2_MGMT_EN_0X))
return mv88e6xxx_g2_write(chip, GLOBAL2_MGMT_EN_0X, 0xffff);
return 0;
}
static int mv88e6xxx_g2_device_mapping_write(struct mv88e6xxx_chip *chip,
int target, int port)
{
u16 val = (target << 8) | (port & 0xf);
return mv88e6xxx_g2_update(chip, GLOBAL2_DEVICE_MAPPING, val);
}
static int mv88e6xxx_g2_set_device_mapping(struct mv88e6xxx_chip *chip)
{
int target, port;
int err;
for (target = 0; target < 32; ++target) {
port = 0xf;
if (target < DSA_MAX_SWITCHES) {
port = chip->ds->rtable[target];
if (port == DSA_RTABLE_NONE)
port = 0xf;
}
err = mv88e6xxx_g2_device_mapping_write(chip, target, port);
if (err)
break;
}
return err;
}
static int mv88e6xxx_g2_trunk_mask_write(struct mv88e6xxx_chip *chip, int num,
bool hask, u16 mask)
{
const u16 port_mask = BIT(mv88e6xxx_num_ports(chip)) - 1;
u16 val = (num << 12) | (mask & port_mask);
if (hask)
val |= GLOBAL2_TRUNK_MASK_HASK;
return mv88e6xxx_g2_update(chip, GLOBAL2_TRUNK_MASK, val);
}
static int mv88e6xxx_g2_trunk_mapping_write(struct mv88e6xxx_chip *chip, int id,
u16 map)
{
const u16 port_mask = BIT(mv88e6xxx_num_ports(chip)) - 1;
u16 val = (id << 11) | (map & port_mask);
return mv88e6xxx_g2_update(chip, GLOBAL2_TRUNK_MAPPING, val);
}
static int mv88e6xxx_g2_clear_trunk(struct mv88e6xxx_chip *chip)
{
const u16 port_mask = BIT(mv88e6xxx_num_ports(chip)) - 1;
int i, err;
for (i = 0; i < 8; ++i) {
err = mv88e6xxx_g2_trunk_mask_write(chip, i, false, port_mask);
if (err)
return err;
}
for (i = 0; i < 16; ++i) {
err = mv88e6xxx_g2_trunk_mapping_write(chip, i, 0);
if (err)
return err;
}
return 0;
}
static int mv88e6xxx_g2_clear_irl(struct mv88e6xxx_chip *chip)
{
int port, err;
for (port = 0; port < mv88e6xxx_num_ports(chip); ++port) {
err = mv88e6xxx_g2_write(chip, GLOBAL2_IRL_CMD,
GLOBAL2_IRL_CMD_OP_INIT_ALL |
(port << 8));
if (err)
break;
err = mv88e6xxx_g2_wait(chip, GLOBAL2_IRL_CMD,
GLOBAL2_IRL_CMD_BUSY);
if (err)
break;
}
return err;
}
static int mv88e6xxx_g2_switch_mac_write(struct mv88e6xxx_chip *chip,
unsigned int pointer, u8 data)
{
u16 val = (pointer << 8) | data;
return mv88e6xxx_g2_update(chip, GLOBAL2_SWITCH_MAC, val);
}
int mv88e6xxx_g2_set_switch_mac(struct mv88e6xxx_chip *chip, u8 *addr)
{
int i, err;
for (i = 0; i < 6; i++) {
err = mv88e6xxx_g2_switch_mac_write(chip, i, addr[i]);
if (err)
break;
}
return err;
}
static int mv88e6xxx_g2_pot_write(struct mv88e6xxx_chip *chip, int pointer,
u8 data)
{
u16 val = (pointer << 8) | (data & 0x7);
return mv88e6xxx_g2_update(chip, GLOBAL2_PRIO_OVERRIDE, val);
}
static int mv88e6xxx_g2_clear_pot(struct mv88e6xxx_chip *chip)
{
int i, err;
for (i = 0; i < 16; i++) {
err = mv88e6xxx_g2_pot_write(chip, i, 0);
if (err)
break;
}
return err;
}
static int mv88e6xxx_g2_eeprom_wait(struct mv88e6xxx_chip *chip)
{
return mv88e6xxx_g2_wait(chip, GLOBAL2_EEPROM_CMD,
GLOBAL2_EEPROM_CMD_BUSY |
GLOBAL2_EEPROM_CMD_RUNNING);
}
static int mv88e6xxx_g2_eeprom_cmd(struct mv88e6xxx_chip *chip, u16 cmd)
{
int err;
err = mv88e6xxx_g2_write(chip, GLOBAL2_EEPROM_CMD, cmd);
if (err)
return err;
return mv88e6xxx_g2_eeprom_wait(chip);
}
static int mv88e6xxx_g2_eeprom_read16(struct mv88e6xxx_chip *chip,
u8 addr, u16 *data)
{
u16 cmd = GLOBAL2_EEPROM_CMD_OP_READ | addr;
int err;
err = mv88e6xxx_g2_eeprom_wait(chip);
if (err)
return err;
err = mv88e6xxx_g2_eeprom_cmd(chip, cmd);
if (err)
return err;
return mv88e6xxx_g2_read(chip, GLOBAL2_EEPROM_DATA, data);
}
static int mv88e6xxx_g2_eeprom_write16(struct mv88e6xxx_chip *chip,
u8 addr, u16 data)
{
u16 cmd = GLOBAL2_EEPROM_CMD_OP_WRITE | addr;
int err;
err = mv88e6xxx_g2_eeprom_wait(chip);
if (err)
return err;
err = mv88e6xxx_g2_write(chip, GLOBAL2_EEPROM_DATA, data);
if (err)
return err;
return mv88e6xxx_g2_eeprom_cmd(chip, cmd);
}
int mv88e6xxx_g2_get_eeprom16(struct mv88e6xxx_chip *chip,
struct ethtool_eeprom *eeprom, u8 *data)
{
unsigned int offset = eeprom->offset;
unsigned int len = eeprom->len;
u16 val;
int err;
eeprom->len = 0;
if (offset & 1) {
err = mv88e6xxx_g2_eeprom_read16(chip, offset >> 1, &val);
if (err)
return err;
*data++ = (val >> 8) & 0xff;
offset++;
len--;
eeprom->len++;
}
while (len >= 2) {
err = mv88e6xxx_g2_eeprom_read16(chip, offset >> 1, &val);
if (err)
return err;
*data++ = val & 0xff;
*data++ = (val >> 8) & 0xff;
offset += 2;
len -= 2;
eeprom->len += 2;
}
if (len) {
err = mv88e6xxx_g2_eeprom_read16(chip, offset >> 1, &val);
if (err)
return err;
*data++ = val & 0xff;
offset++;
len--;
eeprom->len++;
}
return 0;
}
int mv88e6xxx_g2_set_eeprom16(struct mv88e6xxx_chip *chip,
struct ethtool_eeprom *eeprom, u8 *data)
{
unsigned int offset = eeprom->offset;
unsigned int len = eeprom->len;
u16 val;
int err;
err = mv88e6xxx_g2_read(chip, GLOBAL2_EEPROM_CMD, &val);
if (err)
return err;
if (!(val & GLOBAL2_EEPROM_CMD_WRITE_EN))
return -EROFS;
eeprom->len = 0;
if (offset & 1) {
err = mv88e6xxx_g2_eeprom_read16(chip, offset >> 1, &val);
if (err)
return err;
val = (*data++ << 8) | (val & 0xff);
err = mv88e6xxx_g2_eeprom_write16(chip, offset >> 1, val);
if (err)
return err;
offset++;
len--;
eeprom->len++;
}
while (len >= 2) {
val = *data++;
val |= *data++ << 8;
err = mv88e6xxx_g2_eeprom_write16(chip, offset >> 1, val);
if (err)
return err;
offset += 2;
len -= 2;
eeprom->len += 2;
}
if (len) {
err = mv88e6xxx_g2_eeprom_read16(chip, offset >> 1, &val);
if (err)
return err;
val = (val & 0xff00) | *data++;
err = mv88e6xxx_g2_eeprom_write16(chip, offset >> 1, val);
if (err)
return err;
offset++;
len--;
eeprom->len++;
}
return 0;
}
static int mv88e6xxx_g2_smi_phy_wait(struct mv88e6xxx_chip *chip)
{
return mv88e6xxx_g2_wait(chip, GLOBAL2_SMI_PHY_CMD,
GLOBAL2_SMI_PHY_CMD_BUSY);
}
static int mv88e6xxx_g2_smi_phy_cmd(struct mv88e6xxx_chip *chip, u16 cmd)
{
int err;
err = mv88e6xxx_g2_write(chip, GLOBAL2_SMI_PHY_CMD, cmd);
if (err)
return err;
return mv88e6xxx_g2_smi_phy_wait(chip);
}
int mv88e6xxx_g2_smi_phy_read(struct mv88e6xxx_chip *chip, int addr, int reg,
u16 *val)
{
u16 cmd = GLOBAL2_SMI_PHY_CMD_OP_22_READ_DATA | (addr << 5) | reg;
int err;
err = mv88e6xxx_g2_smi_phy_wait(chip);
if (err)
return err;
err = mv88e6xxx_g2_smi_phy_cmd(chip, cmd);
if (err)
return err;
return mv88e6xxx_g2_read(chip, GLOBAL2_SMI_PHY_DATA, val);
}
int mv88e6xxx_g2_smi_phy_write(struct mv88e6xxx_chip *chip, int addr, int reg,
u16 val)
{
u16 cmd = GLOBAL2_SMI_PHY_CMD_OP_22_WRITE_DATA | (addr << 5) | reg;
int err;
err = mv88e6xxx_g2_smi_phy_wait(chip);
if (err)
return err;
err = mv88e6xxx_g2_write(chip, GLOBAL2_SMI_PHY_DATA, val);
if (err)
return err;
return mv88e6xxx_g2_smi_phy_cmd(chip, cmd);
}
static void mv88e6xxx_g2_irq_mask(struct irq_data *d)
{
struct mv88e6xxx_chip *chip = irq_data_get_irq_chip_data(d);
unsigned int n = d->hwirq;
chip->g2_irq.masked |= (1 << n);
}
static void mv88e6xxx_g2_irq_unmask(struct irq_data *d)
{
struct mv88e6xxx_chip *chip = irq_data_get_irq_chip_data(d);
unsigned int n = d->hwirq;
chip->g2_irq.masked &= ~(1 << n);
}
static irqreturn_t mv88e6xxx_g2_irq_thread_fn(int irq, void *dev_id)
{
struct mv88e6xxx_chip *chip = dev_id;
unsigned int nhandled = 0;
unsigned int sub_irq;
unsigned int n;
int err;
u16 reg;
mutex_lock(&chip->reg_lock);
err = mv88e6xxx_g2_read(chip, GLOBAL2_INT_SOURCE, &reg);
mutex_unlock(&chip->reg_lock);
if (err)
goto out;
for (n = 0; n < 16; ++n) {
if (reg & (1 << n)) {
sub_irq = irq_find_mapping(chip->g2_irq.domain, n);
handle_nested_irq(sub_irq);
++nhandled;
}
}
out:
return (nhandled > 0 ? IRQ_HANDLED : IRQ_NONE);
}
static void mv88e6xxx_g2_irq_bus_lock(struct irq_data *d)
{
struct mv88e6xxx_chip *chip = irq_data_get_irq_chip_data(d);
mutex_lock(&chip->reg_lock);
}
static void mv88e6xxx_g2_irq_bus_sync_unlock(struct irq_data *d)
{
struct mv88e6xxx_chip *chip = irq_data_get_irq_chip_data(d);
mv88e6xxx_g2_write(chip, GLOBAL2_INT_MASK, ~chip->g2_irq.masked);
mutex_unlock(&chip->reg_lock);
}
static int mv88e6xxx_g2_irq_domain_map(struct irq_domain *d,
unsigned int irq,
irq_hw_number_t hwirq)
{
struct mv88e6xxx_chip *chip = d->host_data;
irq_set_chip_data(irq, d->host_data);
irq_set_chip_and_handler(irq, &chip->g2_irq.chip, handle_level_irq);
irq_set_noprobe(irq);
return 0;
}
void mv88e6xxx_g2_irq_free(struct mv88e6xxx_chip *chip)
{
int irq, virq;
free_irq(chip->device_irq, chip);
irq_dispose_mapping(chip->device_irq);
for (irq = 0; irq < 16; irq++) {
virq = irq_find_mapping(chip->g2_irq.domain, irq);
irq_dispose_mapping(virq);
}
irq_domain_remove(chip->g2_irq.domain);
}
int mv88e6xxx_g2_irq_setup(struct mv88e6xxx_chip *chip)
{
int err, irq, virq;
if (!chip->dev->of_node)
return -EINVAL;
chip->g2_irq.domain = irq_domain_add_simple(
chip->dev->of_node, 16, 0, &mv88e6xxx_g2_irq_domain_ops, chip);
if (!chip->g2_irq.domain)
return -ENOMEM;
for (irq = 0; irq < 16; irq++)
irq_create_mapping(chip->g2_irq.domain, irq);
chip->g2_irq.chip = mv88e6xxx_g2_irq_chip;
chip->g2_irq.masked = ~0;
chip->device_irq = irq_find_mapping(chip->g1_irq.domain,
GLOBAL_STATUS_IRQ_DEVICE);
if (chip->device_irq < 0) {
err = chip->device_irq;
goto out;
}
err = request_threaded_irq(chip->device_irq, NULL,
mv88e6xxx_g2_irq_thread_fn,
IRQF_ONESHOT, "mv88e6xxx-g1", chip);
if (err)
goto out;
return 0;
out:
for (irq = 0; irq < 16; irq++) {
virq = irq_find_mapping(chip->g2_irq.domain, irq);
irq_dispose_mapping(virq);
}
irq_domain_remove(chip->g2_irq.domain);
return err;
}
int mv88e6xxx_g2_setup(struct mv88e6xxx_chip *chip)
{
u16 reg;
int err;
reg = GLOBAL2_SWITCH_MGMT_FORCE_FLOW_CTRL_PRI | (0x7 << 4);
if (mv88e6xxx_has(chip, MV88E6XXX_FLAG_G2_MGMT_EN_0X) ||
mv88e6xxx_has(chip, MV88E6XXX_FLAG_G2_MGMT_EN_2X))
reg |= GLOBAL2_SWITCH_MGMT_RSVD2CPU | 0x7;
err = mv88e6xxx_g2_write(chip, GLOBAL2_SWITCH_MGMT, reg);
if (err)
return err;
err = mv88e6xxx_g2_set_device_mapping(chip);
if (err)
return err;
err = mv88e6xxx_g2_clear_trunk(chip);
if (err)
return err;
if (mv88e6xxx_has(chip, MV88E6XXX_FLAGS_IRL)) {
err = mv88e6xxx_g2_clear_irl(chip);
if (err)
return err;
}
if (mv88e6xxx_has(chip, MV88E6XXX_FLAGS_PVT)) {
err = mv88e6xxx_g2_write(chip, GLOBAL2_PVT_ADDR,
GLOBAL2_PVT_ADDR_OP_INIT_ONES);
if (err)
return err;
}
if (mv88e6xxx_has(chip, MV88E6XXX_FLAG_G2_POT)) {
err = mv88e6xxx_g2_clear_pot(chip);
if (err)
return err;
}
return 0;
}
