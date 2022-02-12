static char *mv88e6352_probe(struct device *host_dev, int sw_addr)
{
struct mii_bus *bus = dsa_host_dev_to_mii_bus(host_dev);
int ret;
if (bus == NULL)
return NULL;
ret = __mv88e6xxx_reg_read(bus, sw_addr, REG_PORT(0), PORT_SWITCH_ID);
if (ret >= 0) {
if ((ret & 0xfff0) == PORT_SWITCH_ID_6176)
return "Marvell 88E6176";
if (ret == PORT_SWITCH_ID_6352_A0)
return "Marvell 88E6352 (A0)";
if (ret == PORT_SWITCH_ID_6352_A1)
return "Marvell 88E6352 (A1)";
if ((ret & 0xfff0) == PORT_SWITCH_ID_6352)
return "Marvell 88E6352";
}
return NULL;
}
static int mv88e6352_setup_global(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
int i;
REG_WRITE(REG_GLOBAL, 0x04, 0x6000);
REG_WRITE(REG_GLOBAL, 0x0a, 0x0148);
ret = mv88e6xxx_config_prio(ds);
if (ret < 0)
return ret;
REG_WRITE(REG_GLOBAL, 0x1a, (dsa_upstream_port(ds) * 0x1110));
REG_WRITE(REG_GLOBAL, 0x1c, ds->index & 0x1f);
REG_WRITE(REG_GLOBAL2, 0x02, 0xffff);
REG_WRITE(REG_GLOBAL2, 0x03, 0xffff);
REG_WRITE(REG_GLOBAL2, 0x05, 0x00ff);
for (i = 0; i < 32; i++) {
int nexthop = 0x1f;
if (i != ds->index && i < ds->dst->pd->nr_chips)
nexthop = ds->pd->rtable[i] & 0x1f;
REG_WRITE(REG_GLOBAL2, 0x06, 0x8000 | (i << 8) | nexthop);
}
for (i = 0; i < 8; i++)
REG_WRITE(REG_GLOBAL2, 0x07, 0x8000 | (i << 12) | 0x7f);
for (i = 0; i < 16; i++)
REG_WRITE(REG_GLOBAL2, 0x08, 0x8000 | (i << 11));
for (i = 0; i < ps->num_ports; i++)
REG_WRITE(REG_GLOBAL2, 0x09, 0x9000 | (i << 8));
REG_WRITE(REG_GLOBAL2, 0x0b, 0x9000);
for (i = 0; i < 16; i++)
REG_WRITE(REG_GLOBAL2, 0x0f, 0x8000 | (i << 8));
return 0;
}
static int mv88e6352_setup_port(struct dsa_switch *ds, int p)
{
int addr = REG_PORT(p);
u16 val;
if (dsa_is_cpu_port(ds, p) || ds->dsa_port_mask & (1 << p))
REG_WRITE(addr, 0x01, 0x003e);
else
REG_WRITE(addr, 0x01, 0x0003);
REG_WRITE(addr, 0x02, 0x0000);
val = 0x0433;
if (dsa_is_cpu_port(ds, p)) {
if (ds->dst->tag_protocol == DSA_TAG_PROTO_EDSA)
val |= 0x3300;
else
val |= 0x0100;
}
if (ds->dsa_port_mask & (1 << p))
val |= 0x0100;
if (p == dsa_upstream_port(ds))
val |= 0x000c;
REG_WRITE(addr, 0x04, val);
REG_WRITE(addr, 0x08, 0x2080);
REG_WRITE(addr, 0x09, 0x0001);
REG_WRITE(addr, 0x0a, 0x0000);
REG_WRITE(addr, 0x0b, 1 << p);
REG_WRITE(addr, 0x0c, 0x0000);
REG_WRITE(addr, 0x0d, 0x0000);
REG_WRITE(addr, 0x0f, ETH_P_EDSA);
REG_WRITE(addr, 0x18, 0x3210);
REG_WRITE(addr, 0x19, 0x7654);
return mv88e6xxx_setup_port_common(ds, p);
}
static int mv88e6352_get_temp(struct dsa_switch *ds, int *temp)
{
int ret;
*temp = 0;
ret = mv88e6xxx_phy_page_read(ds, 0, 6, 27);
if (ret < 0)
return ret;
*temp = (ret & 0xff) - 25;
return 0;
}
static int mv88e6352_get_temp_limit(struct dsa_switch *ds, int *temp)
{
int ret;
*temp = 0;
ret = mv88e6xxx_phy_page_read(ds, 0, 6, 26);
if (ret < 0)
return ret;
*temp = (((ret >> 8) & 0x1f) * 5) - 25;
return 0;
}
static int mv88e6352_set_temp_limit(struct dsa_switch *ds, int temp)
{
int ret;
ret = mv88e6xxx_phy_page_read(ds, 0, 6, 26);
if (ret < 0)
return ret;
temp = clamp_val(DIV_ROUND_CLOSEST(temp, 5) + 5, 0, 0x1f);
return mv88e6xxx_phy_page_write(ds, 0, 6, 26,
(ret & 0xe0ff) | (temp << 8));
}
static int mv88e6352_get_temp_alarm(struct dsa_switch *ds, bool *alarm)
{
int ret;
*alarm = false;
ret = mv88e6xxx_phy_page_read(ds, 0, 6, 26);
if (ret < 0)
return ret;
*alarm = !!(ret & 0x40);
return 0;
}
static int mv88e6352_setup(struct dsa_switch *ds)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
int i;
ret = mv88e6xxx_setup_common(ds);
if (ret < 0)
return ret;
ps->num_ports = 7;
mutex_init(&ps->eeprom_mutex);
ret = mv88e6xxx_switch_reset(ds, true);
if (ret < 0)
return ret;
ret = mv88e6352_setup_global(ds);
if (ret < 0)
return ret;
for (i = 0; i < ps->num_ports; i++) {
ret = mv88e6352_setup_port(ds, i);
if (ret < 0)
return ret;
}
return 0;
}
static int mv88e6352_read_eeprom_word(struct dsa_switch *ds, int addr)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
mutex_lock(&ps->eeprom_mutex);
ret = mv88e6xxx_reg_write(ds, REG_GLOBAL2, 0x14,
0xc000 | (addr & 0xff));
if (ret < 0)
goto error;
ret = mv88e6xxx_eeprom_busy_wait(ds);
if (ret < 0)
goto error;
ret = mv88e6xxx_reg_read(ds, REG_GLOBAL2, 0x15);
error:
mutex_unlock(&ps->eeprom_mutex);
return ret;
}
static int mv88e6352_get_eeprom(struct dsa_switch *ds,
struct ethtool_eeprom *eeprom, u8 *data)
{
int offset;
int len;
int ret;
offset = eeprom->offset;
len = eeprom->len;
eeprom->len = 0;
eeprom->magic = 0xc3ec4951;
ret = mv88e6xxx_eeprom_load_wait(ds);
if (ret < 0)
return ret;
if (offset & 1) {
int word;
word = mv88e6352_read_eeprom_word(ds, offset >> 1);
if (word < 0)
return word;
*data++ = (word >> 8) & 0xff;
offset++;
len--;
eeprom->len++;
}
while (len >= 2) {
int word;
word = mv88e6352_read_eeprom_word(ds, offset >> 1);
if (word < 0)
return word;
*data++ = word & 0xff;
*data++ = (word >> 8) & 0xff;
offset += 2;
len -= 2;
eeprom->len += 2;
}
if (len) {
int word;
word = mv88e6352_read_eeprom_word(ds, offset >> 1);
if (word < 0)
return word;
*data++ = word & 0xff;
offset++;
len--;
eeprom->len++;
}
return 0;
}
static int mv88e6352_eeprom_is_readonly(struct dsa_switch *ds)
{
int ret;
ret = mv88e6xxx_reg_read(ds, REG_GLOBAL2, 0x14);
if (ret < 0)
return ret;
if (!(ret & 0x0400))
return -EROFS;
return 0;
}
static int mv88e6352_write_eeprom_word(struct dsa_switch *ds, int addr,
u16 data)
{
struct mv88e6xxx_priv_state *ps = ds_to_priv(ds);
int ret;
mutex_lock(&ps->eeprom_mutex);
ret = mv88e6xxx_reg_write(ds, REG_GLOBAL2, 0x15, data);
if (ret < 0)
goto error;
ret = mv88e6xxx_reg_write(ds, REG_GLOBAL2, 0x14,
0xb000 | (addr & 0xff));
if (ret < 0)
goto error;
ret = mv88e6xxx_eeprom_busy_wait(ds);
error:
mutex_unlock(&ps->eeprom_mutex);
return ret;
}
static int mv88e6352_set_eeprom(struct dsa_switch *ds,
struct ethtool_eeprom *eeprom, u8 *data)
{
int offset;
int ret;
int len;
if (eeprom->magic != 0xc3ec4951)
return -EINVAL;
ret = mv88e6352_eeprom_is_readonly(ds);
if (ret)
return ret;
offset = eeprom->offset;
len = eeprom->len;
eeprom->len = 0;
ret = mv88e6xxx_eeprom_load_wait(ds);
if (ret < 0)
return ret;
if (offset & 1) {
int word;
word = mv88e6352_read_eeprom_word(ds, offset >> 1);
if (word < 0)
return word;
word = (*data++ << 8) | (word & 0xff);
ret = mv88e6352_write_eeprom_word(ds, offset >> 1, word);
if (ret < 0)
return ret;
offset++;
len--;
eeprom->len++;
}
while (len >= 2) {
int word;
word = *data++;
word |= *data++ << 8;
ret = mv88e6352_write_eeprom_word(ds, offset >> 1, word);
if (ret < 0)
return ret;
offset += 2;
len -= 2;
eeprom->len += 2;
}
if (len) {
int word;
word = mv88e6352_read_eeprom_word(ds, offset >> 1);
if (word < 0)
return word;
word = (word & 0xff00) | *data++;
ret = mv88e6352_write_eeprom_word(ds, offset >> 1, word);
if (ret < 0)
return ret;
offset++;
len--;
eeprom->len++;
}
return 0;
}
