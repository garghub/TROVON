static int snprint_line(char *buf, size_t count,
const u8 * data, u32 len, u32 ofs)
{
int out, i, j, l;
char c;
out = snprintf(buf, count, "%08X", ofs);
for (l = 0, i = 0; i < 2; i++) {
out += snprintf(buf + out, count - out, " ");
for (j = 0; j < 8 && l < len; j++, l++)
out += snprintf(buf + out, count - out, "%02X ",
data[(i * 8 + j)]);
for (; j < 8; j++)
out += snprintf(buf + out, count - out, " ");
}
out += snprintf(buf + out, count - out, " ");
for (l = 0, i = 0; i < 2; i++) {
out += snprintf(buf + out, count - out, " ");
for (j = 0; j < 8 && l < len; j++, l++) {
c = data[(i * 8 + j)];
if (!isascii(c) || !isprint(c))
c = '.';
out += snprintf(buf + out, count - out, "%c", c);
}
for (; j < 8; j++)
out += snprintf(buf + out, count - out, " ");
}
return out;
}
static void printk_buf(int level, const u8 * data, u32 len)
{
char line[81];
u32 ofs = 0;
if (!(ipw_debug_level & level))
return;
while (len) {
snprint_line(line, sizeof(line), &data[ofs],
min(len, 16U), ofs);
printk(KERN_DEBUG "%s\n", line);
ofs += 16;
len -= min(len, 16U);
}
}
static int snprintk_buf(u8 * output, size_t size, const u8 * data, size_t len)
{
size_t out = size;
u32 ofs = 0;
int total = 0;
while (size && len) {
out = snprint_line(output, size, &data[ofs],
min_t(size_t, len, 16U), ofs);
ofs += 16;
output += out;
size -= out;
len -= min_t(size_t, len, 16U);
total += out;
}
return total;
}
static inline void ipw_write_reg8(struct ipw_priv *a, u32 b, u8 c)
{
IPW_DEBUG_IO("%s %d: write_indirect8(0x%08X, 0x%08X)\n", __FILE__,
__LINE__, (u32) (b), (u32) (c));
_ipw_write_reg8(a, b, c);
}
static inline void ipw_write_reg16(struct ipw_priv *a, u32 b, u16 c)
{
IPW_DEBUG_IO("%s %d: write_indirect16(0x%08X, 0x%08X)\n", __FILE__,
__LINE__, (u32) (b), (u32) (c));
_ipw_write_reg16(a, b, c);
}
static inline void ipw_write_reg32(struct ipw_priv *a, u32 b, u32 c)
{
IPW_DEBUG_IO("%s %d: write_indirect32(0x%08X, 0x%08X)\n", __FILE__,
__LINE__, (u32) (b), (u32) (c));
_ipw_write_reg32(a, b, c);
}
static inline void _ipw_write8(struct ipw_priv *ipw, unsigned long ofs,
u8 val)
{
writeb(val, ipw->hw_base + ofs);
}
static inline void _ipw_write16(struct ipw_priv *ipw, unsigned long ofs,
u16 val)
{
writew(val, ipw->hw_base + ofs);
}
static inline void _ipw_write32(struct ipw_priv *ipw, unsigned long ofs,
u32 val)
{
writel(val, ipw->hw_base + ofs);
}
static inline u8 _ipw_read8(struct ipw_priv *ipw, unsigned long ofs)
{
return readb(ipw->hw_base + ofs);
}
static inline u16 _ipw_read16(struct ipw_priv *ipw, unsigned long ofs)
{
return readw(ipw->hw_base + ofs);
}
static inline u32 _ipw_read32(struct ipw_priv *ipw, unsigned long ofs)
{
return readl(ipw->hw_base + ofs);
}
static void _ipw_write_reg32(struct ipw_priv *priv, u32 reg, u32 value)
{
IPW_DEBUG_IO(" %p : reg = 0x%8X : value = 0x%8X\n", priv, reg, value);
_ipw_write32(priv, IPW_INDIRECT_ADDR, reg);
_ipw_write32(priv, IPW_INDIRECT_DATA, value);
}
static void _ipw_write_reg8(struct ipw_priv *priv, u32 reg, u8 value)
{
u32 aligned_addr = reg & IPW_INDIRECT_ADDR_MASK;
u32 dif_len = reg - aligned_addr;
IPW_DEBUG_IO(" reg = 0x%8X : value = 0x%8X\n", reg, value);
_ipw_write32(priv, IPW_INDIRECT_ADDR, aligned_addr);
_ipw_write8(priv, IPW_INDIRECT_DATA + dif_len, value);
}
static void _ipw_write_reg16(struct ipw_priv *priv, u32 reg, u16 value)
{
u32 aligned_addr = reg & IPW_INDIRECT_ADDR_MASK;
u32 dif_len = (reg - aligned_addr) & (~0x1ul);
IPW_DEBUG_IO(" reg = 0x%8X : value = 0x%8X\n", reg, value);
_ipw_write32(priv, IPW_INDIRECT_ADDR, aligned_addr);
_ipw_write16(priv, IPW_INDIRECT_DATA + dif_len, value);
}
static u8 _ipw_read_reg8(struct ipw_priv *priv, u32 reg)
{
u32 word;
_ipw_write32(priv, IPW_INDIRECT_ADDR, reg & IPW_INDIRECT_ADDR_MASK);
IPW_DEBUG_IO(" reg = 0x%8X :\n", reg);
word = _ipw_read32(priv, IPW_INDIRECT_DATA);
return (word >> ((reg & 0x3) * 8)) & 0xff;
}
static u32 _ipw_read_reg32(struct ipw_priv *priv, u32 reg)
{
u32 value;
IPW_DEBUG_IO("%p : reg = 0x%08x\n", priv, reg);
_ipw_write32(priv, IPW_INDIRECT_ADDR, reg);
value = _ipw_read32(priv, IPW_INDIRECT_DATA);
IPW_DEBUG_IO(" reg = 0x%4X : value = 0x%4x\n", reg, value);
return value;
}
static void _ipw_read_indirect(struct ipw_priv *priv, u32 addr, u8 * buf,
int num)
{
u32 aligned_addr = addr & IPW_INDIRECT_ADDR_MASK;
u32 dif_len = addr - aligned_addr;
u32 i;
IPW_DEBUG_IO("addr = %i, buf = %p, num = %i\n", addr, buf, num);
if (num <= 0) {
return;
}
if (unlikely(dif_len)) {
_ipw_write32(priv, IPW_INDIRECT_ADDR, aligned_addr);
for (i = dif_len; ((i < 4) && (num > 0)); i++, num--)
*buf++ = _ipw_read8(priv, IPW_INDIRECT_DATA + i);
aligned_addr += 4;
}
_ipw_write32(priv, IPW_AUTOINC_ADDR, aligned_addr);
for (; num >= 4; buf += 4, aligned_addr += 4, num -= 4)
*(u32 *) buf = _ipw_read32(priv, IPW_AUTOINC_DATA);
if (unlikely(num)) {
_ipw_write32(priv, IPW_INDIRECT_ADDR, aligned_addr);
for (i = 0; num > 0; i++, num--)
*buf++ = ipw_read8(priv, IPW_INDIRECT_DATA + i);
}
}
static void _ipw_write_indirect(struct ipw_priv *priv, u32 addr, u8 * buf,
int num)
{
u32 aligned_addr = addr & IPW_INDIRECT_ADDR_MASK;
u32 dif_len = addr - aligned_addr;
u32 i;
IPW_DEBUG_IO("addr = %i, buf = %p, num = %i\n", addr, buf, num);
if (num <= 0) {
return;
}
if (unlikely(dif_len)) {
_ipw_write32(priv, IPW_INDIRECT_ADDR, aligned_addr);
for (i = dif_len; ((i < 4) && (num > 0)); i++, num--, buf++)
_ipw_write8(priv, IPW_INDIRECT_DATA + i, *buf);
aligned_addr += 4;
}
_ipw_write32(priv, IPW_AUTOINC_ADDR, aligned_addr);
for (; num >= 4; buf += 4, aligned_addr += 4, num -= 4)
_ipw_write32(priv, IPW_AUTOINC_DATA, *(u32 *) buf);
if (unlikely(num)) {
_ipw_write32(priv, IPW_INDIRECT_ADDR, aligned_addr);
for (i = 0; num > 0; i++, num--, buf++)
_ipw_write8(priv, IPW_INDIRECT_DATA + i, *buf);
}
}
static void ipw_write_direct(struct ipw_priv *priv, u32 addr, void *buf,
int num)
{
memcpy_toio((priv->hw_base + addr), buf, num);
}
static inline void ipw_set_bit(struct ipw_priv *priv, u32 reg, u32 mask)
{
ipw_write32(priv, reg, ipw_read32(priv, reg) | mask);
}
static inline void ipw_clear_bit(struct ipw_priv *priv, u32 reg, u32 mask)
{
ipw_write32(priv, reg, ipw_read32(priv, reg) & ~mask);
}
static inline void __ipw_enable_interrupts(struct ipw_priv *priv)
{
if (priv->status & STATUS_INT_ENABLED)
return;
priv->status |= STATUS_INT_ENABLED;
ipw_write32(priv, IPW_INTA_MASK_R, IPW_INTA_MASK_ALL);
}
static inline void __ipw_disable_interrupts(struct ipw_priv *priv)
{
if (!(priv->status & STATUS_INT_ENABLED))
return;
priv->status &= ~STATUS_INT_ENABLED;
ipw_write32(priv, IPW_INTA_MASK_R, ~IPW_INTA_MASK_ALL);
}
static inline void ipw_enable_interrupts(struct ipw_priv *priv)
{
unsigned long flags;
spin_lock_irqsave(&priv->irq_lock, flags);
__ipw_enable_interrupts(priv);
spin_unlock_irqrestore(&priv->irq_lock, flags);
}
static inline void ipw_disable_interrupts(struct ipw_priv *priv)
{
unsigned long flags;
spin_lock_irqsave(&priv->irq_lock, flags);
__ipw_disable_interrupts(priv);
spin_unlock_irqrestore(&priv->irq_lock, flags);
}
static char *ipw_error_desc(u32 val)
{
switch (val) {
case IPW_FW_ERROR_OK:
return "ERROR_OK";
case IPW_FW_ERROR_FAIL:
return "ERROR_FAIL";
case IPW_FW_ERROR_MEMORY_UNDERFLOW:
return "MEMORY_UNDERFLOW";
case IPW_FW_ERROR_MEMORY_OVERFLOW:
return "MEMORY_OVERFLOW";
case IPW_FW_ERROR_BAD_PARAM:
return "BAD_PARAM";
case IPW_FW_ERROR_BAD_CHECKSUM:
return "BAD_CHECKSUM";
case IPW_FW_ERROR_NMI_INTERRUPT:
return "NMI_INTERRUPT";
case IPW_FW_ERROR_BAD_DATABASE:
return "BAD_DATABASE";
case IPW_FW_ERROR_ALLOC_FAIL:
return "ALLOC_FAIL";
case IPW_FW_ERROR_DMA_UNDERRUN:
return "DMA_UNDERRUN";
case IPW_FW_ERROR_DMA_STATUS:
return "DMA_STATUS";
case IPW_FW_ERROR_DINO_ERROR:
return "DINO_ERROR";
case IPW_FW_ERROR_EEPROM_ERROR:
return "EEPROM_ERROR";
case IPW_FW_ERROR_SYSASSERT:
return "SYSASSERT";
case IPW_FW_ERROR_FATAL_ERROR:
return "FATAL_ERROR";
default:
return "UNKNOWN_ERROR";
}
}
static void ipw_dump_error_log(struct ipw_priv *priv,
struct ipw_fw_error *error)
{
u32 i;
if (!error) {
IPW_ERROR("Error allocating and capturing error log. "
"Nothing to dump.\n");
return;
}
IPW_ERROR("Start IPW Error Log Dump:\n");
IPW_ERROR("Status: 0x%08X, Config: %08X\n",
error->status, error->config);
for (i = 0; i < error->elem_len; i++)
IPW_ERROR("%s %i 0x%08x 0x%08x 0x%08x 0x%08x 0x%08x\n",
ipw_error_desc(error->elem[i].desc),
error->elem[i].time,
error->elem[i].blink1,
error->elem[i].blink2,
error->elem[i].link1,
error->elem[i].link2, error->elem[i].data);
for (i = 0; i < error->log_len; i++)
IPW_ERROR("%i\t0x%08x\t%i\n",
error->log[i].time,
error->log[i].data, error->log[i].event);
}
static inline int ipw_is_init(struct ipw_priv *priv)
{
return (priv->status & STATUS_INIT) ? 1 : 0;
}
static int ipw_get_ordinal(struct ipw_priv *priv, u32 ord, void *val, u32 * len)
{
u32 addr, field_info, field_len, field_count, total_len;
IPW_DEBUG_ORD("ordinal = %i\n", ord);
if (!priv || !val || !len) {
IPW_DEBUG_ORD("Invalid argument\n");
return -EINVAL;
}
if (!priv->table0_addr || !priv->table1_addr || !priv->table2_addr) {
IPW_DEBUG_ORD("Access ordinals before initialization\n");
return -EINVAL;
}
switch (IPW_ORD_TABLE_ID_MASK & ord) {
case IPW_ORD_TABLE_0_MASK:
ord &= IPW_ORD_TABLE_VALUE_MASK;
if (ord > priv->table0_len) {
IPW_DEBUG_ORD("ordinal value (%i) longer then "
"max (%i)\n", ord, priv->table0_len);
return -EINVAL;
}
if (*len < sizeof(u32)) {
IPW_DEBUG_ORD("ordinal buffer length too small, "
"need %zd\n", sizeof(u32));
return -EINVAL;
}
IPW_DEBUG_ORD("Reading TABLE0[%i] from offset 0x%08x\n",
ord, priv->table0_addr + (ord << 2));
*len = sizeof(u32);
ord <<= 2;
*((u32 *) val) = ipw_read32(priv, priv->table0_addr + ord);
break;
case IPW_ORD_TABLE_1_MASK:
ord &= IPW_ORD_TABLE_VALUE_MASK;
if (ord > priv->table1_len) {
IPW_DEBUG_ORD("ordinal value too long\n");
return -EINVAL;
}
if (*len < sizeof(u32)) {
IPW_DEBUG_ORD("ordinal buffer length too small, "
"need %zd\n", sizeof(u32));
return -EINVAL;
}
*((u32 *) val) =
ipw_read_reg32(priv, (priv->table1_addr + (ord << 2)));
*len = sizeof(u32);
break;
case IPW_ORD_TABLE_2_MASK:
ord &= IPW_ORD_TABLE_VALUE_MASK;
if (ord > priv->table2_len) {
IPW_DEBUG_ORD("ordinal value too long\n");
return -EINVAL;
}
addr = ipw_read_reg32(priv, priv->table2_addr + (ord << 3));
field_info =
ipw_read_reg32(priv,
priv->table2_addr + (ord << 3) +
sizeof(u32));
field_len = *((u16 *) & field_info);
field_count = *(((u16 *) & field_info) + 1);
total_len = field_len * field_count;
if (total_len > *len) {
*len = total_len;
return -EINVAL;
}
*len = total_len;
if (!total_len)
return 0;
IPW_DEBUG_ORD("addr = 0x%08x, total_len = %i, "
"field_info = 0x%08x\n",
addr, total_len, field_info);
ipw_read_indirect(priv, addr, val, total_len);
break;
default:
IPW_DEBUG_ORD("Invalid ordinal!\n");
return -EINVAL;
}
return 0;
}
static void ipw_init_ordinals(struct ipw_priv *priv)
{
priv->table0_addr = IPW_ORDINALS_TABLE_LOWER;
priv->table0_len = ipw_read32(priv, priv->table0_addr);
IPW_DEBUG_ORD("table 0 offset at 0x%08x, len = %i\n",
priv->table0_addr, priv->table0_len);
priv->table1_addr = ipw_read32(priv, IPW_ORDINALS_TABLE_1);
priv->table1_len = ipw_read_reg32(priv, priv->table1_addr);
IPW_DEBUG_ORD("table 1 offset at 0x%08x, len = %i\n",
priv->table1_addr, priv->table1_len);
priv->table2_addr = ipw_read32(priv, IPW_ORDINALS_TABLE_2);
priv->table2_len = ipw_read_reg32(priv, priv->table2_addr);
priv->table2_len &= 0x0000ffff;
IPW_DEBUG_ORD("table 2 offset at 0x%08x, len = %i\n",
priv->table2_addr, priv->table2_len);
}
static u32 ipw_register_toggle(u32 reg)
{
reg &= ~IPW_START_STANDBY;
if (reg & IPW_GATE_ODMA)
reg &= ~IPW_GATE_ODMA;
if (reg & IPW_GATE_IDMA)
reg &= ~IPW_GATE_IDMA;
if (reg & IPW_GATE_ADMA)
reg &= ~IPW_GATE_ADMA;
return reg;
}
static void ipw_led_link_on(struct ipw_priv *priv)
{
unsigned long flags;
u32 led;
if (priv->config & CFG_NO_LED || priv->nic_type == EEPROM_NIC_TYPE_1)
return;
spin_lock_irqsave(&priv->lock, flags);
if (!(priv->status & STATUS_RF_KILL_MASK) &&
!(priv->status & STATUS_LED_LINK_ON)) {
IPW_DEBUG_LED("Link LED On\n");
led = ipw_read_reg32(priv, IPW_EVENT_REG);
led |= priv->led_association_on;
led = ipw_register_toggle(led);
IPW_DEBUG_LED("Reg: 0x%08X\n", led);
ipw_write_reg32(priv, IPW_EVENT_REG, led);
priv->status |= STATUS_LED_LINK_ON;
if (!(priv->status & STATUS_ASSOCIATED))
schedule_delayed_work(&priv->led_link_off,
LD_TIME_LINK_ON);
}
spin_unlock_irqrestore(&priv->lock, flags);
}
static void ipw_bg_led_link_on(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, led_link_on.work);
mutex_lock(&priv->mutex);
ipw_led_link_on(priv);
mutex_unlock(&priv->mutex);
}
static void ipw_led_link_off(struct ipw_priv *priv)
{
unsigned long flags;
u32 led;
if (priv->config & CFG_NO_LED || priv->nic_type == EEPROM_NIC_TYPE_1)
return;
spin_lock_irqsave(&priv->lock, flags);
if (priv->status & STATUS_LED_LINK_ON) {
led = ipw_read_reg32(priv, IPW_EVENT_REG);
led &= priv->led_association_off;
led = ipw_register_toggle(led);
IPW_DEBUG_LED("Reg: 0x%08X\n", led);
ipw_write_reg32(priv, IPW_EVENT_REG, led);
IPW_DEBUG_LED("Link LED Off\n");
priv->status &= ~STATUS_LED_LINK_ON;
if (!(priv->status & STATUS_RF_KILL_MASK) &&
!(priv->status & STATUS_ASSOCIATED))
schedule_delayed_work(&priv->led_link_on,
LD_TIME_LINK_OFF);
}
spin_unlock_irqrestore(&priv->lock, flags);
}
static void ipw_bg_led_link_off(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, led_link_off.work);
mutex_lock(&priv->mutex);
ipw_led_link_off(priv);
mutex_unlock(&priv->mutex);
}
static void __ipw_led_activity_on(struct ipw_priv *priv)
{
u32 led;
if (priv->config & CFG_NO_LED)
return;
if (priv->status & STATUS_RF_KILL_MASK)
return;
if (!(priv->status & STATUS_LED_ACT_ON)) {
led = ipw_read_reg32(priv, IPW_EVENT_REG);
led |= priv->led_activity_on;
led = ipw_register_toggle(led);
IPW_DEBUG_LED("Reg: 0x%08X\n", led);
ipw_write_reg32(priv, IPW_EVENT_REG, led);
IPW_DEBUG_LED("Activity LED On\n");
priv->status |= STATUS_LED_ACT_ON;
cancel_delayed_work(&priv->led_act_off);
schedule_delayed_work(&priv->led_act_off, LD_TIME_ACT_ON);
} else {
cancel_delayed_work(&priv->led_act_off);
schedule_delayed_work(&priv->led_act_off, LD_TIME_ACT_ON);
}
}
static void ipw_led_activity_off(struct ipw_priv *priv)
{
unsigned long flags;
u32 led;
if (priv->config & CFG_NO_LED)
return;
spin_lock_irqsave(&priv->lock, flags);
if (priv->status & STATUS_LED_ACT_ON) {
led = ipw_read_reg32(priv, IPW_EVENT_REG);
led &= priv->led_activity_off;
led = ipw_register_toggle(led);
IPW_DEBUG_LED("Reg: 0x%08X\n", led);
ipw_write_reg32(priv, IPW_EVENT_REG, led);
IPW_DEBUG_LED("Activity LED Off\n");
priv->status &= ~STATUS_LED_ACT_ON;
}
spin_unlock_irqrestore(&priv->lock, flags);
}
static void ipw_bg_led_activity_off(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, led_act_off.work);
mutex_lock(&priv->mutex);
ipw_led_activity_off(priv);
mutex_unlock(&priv->mutex);
}
static void ipw_led_band_on(struct ipw_priv *priv)
{
unsigned long flags;
u32 led;
if (priv->config & CFG_NO_LED ||
priv->nic_type != EEPROM_NIC_TYPE_1 || !priv->assoc_network)
return;
spin_lock_irqsave(&priv->lock, flags);
led = ipw_read_reg32(priv, IPW_EVENT_REG);
if (priv->assoc_network->mode == IEEE_A) {
led |= priv->led_ofdm_on;
led &= priv->led_association_off;
IPW_DEBUG_LED("Mode LED On: 802.11a\n");
} else if (priv->assoc_network->mode == IEEE_G) {
led |= priv->led_ofdm_on;
led |= priv->led_association_on;
IPW_DEBUG_LED("Mode LED On: 802.11g\n");
} else {
led &= priv->led_ofdm_off;
led |= priv->led_association_on;
IPW_DEBUG_LED("Mode LED On: 802.11b\n");
}
led = ipw_register_toggle(led);
IPW_DEBUG_LED("Reg: 0x%08X\n", led);
ipw_write_reg32(priv, IPW_EVENT_REG, led);
spin_unlock_irqrestore(&priv->lock, flags);
}
static void ipw_led_band_off(struct ipw_priv *priv)
{
unsigned long flags;
u32 led;
if (priv->config & CFG_NO_LED || priv->nic_type != EEPROM_NIC_TYPE_1)
return;
spin_lock_irqsave(&priv->lock, flags);
led = ipw_read_reg32(priv, IPW_EVENT_REG);
led &= priv->led_ofdm_off;
led &= priv->led_association_off;
led = ipw_register_toggle(led);
IPW_DEBUG_LED("Reg: 0x%08X\n", led);
ipw_write_reg32(priv, IPW_EVENT_REG, led);
spin_unlock_irqrestore(&priv->lock, flags);
}
static void ipw_led_radio_on(struct ipw_priv *priv)
{
ipw_led_link_on(priv);
}
static void ipw_led_radio_off(struct ipw_priv *priv)
{
ipw_led_activity_off(priv);
ipw_led_link_off(priv);
}
static void ipw_led_link_up(struct ipw_priv *priv)
{
ipw_led_link_on(priv);
}
static void ipw_led_link_down(struct ipw_priv *priv)
{
ipw_led_activity_off(priv);
ipw_led_link_off(priv);
if (priv->status & STATUS_RF_KILL_MASK)
ipw_led_radio_off(priv);
}
static void ipw_led_init(struct ipw_priv *priv)
{
priv->nic_type = priv->eeprom[EEPROM_NIC_TYPE];
priv->led_activity_on = IPW_ACTIVITY_LED;
priv->led_activity_off = ~(IPW_ACTIVITY_LED);
priv->led_association_on = IPW_ASSOCIATED_LED;
priv->led_association_off = ~(IPW_ASSOCIATED_LED);
priv->led_ofdm_on = IPW_OFDM_LED;
priv->led_ofdm_off = ~(IPW_OFDM_LED);
switch (priv->nic_type) {
case EEPROM_NIC_TYPE_1:
priv->led_activity_on = IPW_ASSOCIATED_LED;
priv->led_activity_off = ~(IPW_ASSOCIATED_LED);
priv->led_association_on = IPW_ACTIVITY_LED;
priv->led_association_off = ~(IPW_ACTIVITY_LED);
if (!(priv->config & CFG_NO_LED))
ipw_led_band_on(priv);
return;
case EEPROM_NIC_TYPE_3:
case EEPROM_NIC_TYPE_2:
case EEPROM_NIC_TYPE_4:
case EEPROM_NIC_TYPE_0:
break;
default:
IPW_DEBUG_INFO("Unknown NIC type from EEPROM: %d\n",
priv->nic_type);
priv->nic_type = EEPROM_NIC_TYPE_0;
break;
}
if (!(priv->config & CFG_NO_LED)) {
if (priv->status & STATUS_ASSOCIATED)
ipw_led_link_on(priv);
else
ipw_led_link_off(priv);
}
}
static void ipw_led_shutdown(struct ipw_priv *priv)
{
ipw_led_activity_off(priv);
ipw_led_link_off(priv);
ipw_led_band_off(priv);
cancel_delayed_work(&priv->led_link_on);
cancel_delayed_work(&priv->led_link_off);
cancel_delayed_work(&priv->led_act_off);
}
static ssize_t debug_level_show(struct device_driver *d, char *buf)
{
return sprintf(buf, "0x%08X\n", ipw_debug_level);
}
static ssize_t debug_level_store(struct device_driver *d, const char *buf,
size_t count)
{
char *p = (char *)buf;
u32 val;
if (p[1] == 'x' || p[1] == 'X' || p[0] == 'x' || p[0] == 'X') {
p++;
if (p[0] == 'x' || p[0] == 'X')
p++;
val = simple_strtoul(p, &p, 16);
} else
val = simple_strtoul(p, &p, 10);
if (p == buf)
printk(KERN_INFO DRV_NAME
": %s is not in hex or decimal form.\n", buf);
else
ipw_debug_level = val;
return strnlen(buf, count);
}
static inline u32 ipw_get_event_log_len(struct ipw_priv *priv)
{
return ipw_read_reg32(priv, ipw_read32(priv, IPW_EVENT_LOG));
}
static void ipw_capture_event_log(struct ipw_priv *priv,
u32 log_len, struct ipw_event *log)
{
u32 base;
if (log_len) {
base = ipw_read32(priv, IPW_EVENT_LOG);
ipw_read_indirect(priv, base + sizeof(base) + sizeof(u32),
(u8 *) log, sizeof(*log) * log_len);
}
}
static struct ipw_fw_error *ipw_alloc_error_log(struct ipw_priv *priv)
{
struct ipw_fw_error *error;
u32 log_len = ipw_get_event_log_len(priv);
u32 base = ipw_read32(priv, IPW_ERROR_LOG);
u32 elem_len = ipw_read_reg32(priv, base);
error = kmalloc(sizeof(*error) +
sizeof(*error->elem) * elem_len +
sizeof(*error->log) * log_len, GFP_ATOMIC);
if (!error) {
IPW_ERROR("Memory allocation for firmware error log "
"failed.\n");
return NULL;
}
error->jiffies = jiffies;
error->status = priv->status;
error->config = priv->config;
error->elem_len = elem_len;
error->log_len = log_len;
error->elem = (struct ipw_error_elem *)error->payload;
error->log = (struct ipw_event *)(error->elem + elem_len);
ipw_capture_event_log(priv, log_len, error->log);
if (elem_len)
ipw_read_indirect(priv, base + sizeof(base), (u8 *) error->elem,
sizeof(*error->elem) * elem_len);
return error;
}
static ssize_t show_event_log(struct device *d,
struct device_attribute *attr, char *buf)
{
struct ipw_priv *priv = dev_get_drvdata(d);
u32 log_len = ipw_get_event_log_len(priv);
u32 log_size;
struct ipw_event *log;
u32 len = 0, i;
log_size = PAGE_SIZE / sizeof(*log) > log_len ?
sizeof(*log) * log_len : PAGE_SIZE;
log = kzalloc(log_size, GFP_KERNEL);
if (!log) {
IPW_ERROR("Unable to allocate memory for log\n");
return 0;
}
log_len = log_size / sizeof(*log);
ipw_capture_event_log(priv, log_len, log);
len += snprintf(buf + len, PAGE_SIZE - len, "%08X", log_len);
for (i = 0; i < log_len; i++)
len += snprintf(buf + len, PAGE_SIZE - len,
"\n%08X%08X%08X",
log[i].time, log[i].event, log[i].data);
len += snprintf(buf + len, PAGE_SIZE - len, "\n");
kfree(log);
return len;
}
static ssize_t show_error(struct device *d,
struct device_attribute *attr, char *buf)
{
struct ipw_priv *priv = dev_get_drvdata(d);
u32 len = 0, i;
if (!priv->error)
return 0;
len += snprintf(buf + len, PAGE_SIZE - len,
"%08lX%08X%08X%08X",
priv->error->jiffies,
priv->error->status,
priv->error->config, priv->error->elem_len);
for (i = 0; i < priv->error->elem_len; i++)
len += snprintf(buf + len, PAGE_SIZE - len,
"\n%08X%08X%08X%08X%08X%08X%08X",
priv->error->elem[i].time,
priv->error->elem[i].desc,
priv->error->elem[i].blink1,
priv->error->elem[i].blink2,
priv->error->elem[i].link1,
priv->error->elem[i].link2,
priv->error->elem[i].data);
len += snprintf(buf + len, PAGE_SIZE - len,
"\n%08X", priv->error->log_len);
for (i = 0; i < priv->error->log_len; i++)
len += snprintf(buf + len, PAGE_SIZE - len,
"\n%08X%08X%08X",
priv->error->log[i].time,
priv->error->log[i].event,
priv->error->log[i].data);
len += snprintf(buf + len, PAGE_SIZE - len, "\n");
return len;
}
static ssize_t clear_error(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ipw_priv *priv = dev_get_drvdata(d);
kfree(priv->error);
priv->error = NULL;
return count;
}
static ssize_t show_cmd_log(struct device *d,
struct device_attribute *attr, char *buf)
{
struct ipw_priv *priv = dev_get_drvdata(d);
u32 len = 0, i;
if (!priv->cmdlog)
return 0;
for (i = (priv->cmdlog_pos + 1) % priv->cmdlog_len;
(i != priv->cmdlog_pos) && (len < PAGE_SIZE);
i = (i + 1) % priv->cmdlog_len) {
len +=
snprintf(buf + len, PAGE_SIZE - len,
"\n%08lX%08X%08X%08X\n", priv->cmdlog[i].jiffies,
priv->cmdlog[i].retcode, priv->cmdlog[i].cmd.cmd,
priv->cmdlog[i].cmd.len);
len +=
snprintk_buf(buf + len, PAGE_SIZE - len,
(u8 *) priv->cmdlog[i].cmd.param,
priv->cmdlog[i].cmd.len);
len += snprintf(buf + len, PAGE_SIZE - len, "\n");
}
len += snprintf(buf + len, PAGE_SIZE - len, "\n");
return len;
}
static ssize_t store_rtap_iface(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ipw_priv *priv = dev_get_drvdata(d);
int rc = 0;
if (count < 1)
return -EINVAL;
switch (buf[0]) {
case '0':
if (!rtap_iface)
return count;
if (netif_running(priv->prom_net_dev)) {
IPW_WARNING("Interface is up. Cannot unregister.\n");
return count;
}
ipw_prom_free(priv);
rtap_iface = 0;
break;
case '1':
if (rtap_iface)
return count;
rc = ipw_prom_alloc(priv);
if (!rc)
rtap_iface = 1;
break;
default:
return -EINVAL;
}
if (rc) {
IPW_ERROR("Failed to register promiscuous network "
"device (error %d).\n", rc);
}
return count;
}
static ssize_t show_rtap_iface(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct ipw_priv *priv = dev_get_drvdata(d);
if (rtap_iface)
return sprintf(buf, "%s", priv->prom_net_dev->name);
else {
buf[0] = '-';
buf[1] = '1';
buf[2] = '\0';
return 3;
}
}
static ssize_t store_rtap_filter(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ipw_priv *priv = dev_get_drvdata(d);
if (!priv->prom_priv) {
IPW_ERROR("Attempting to set filter without "
"rtap_iface enabled.\n");
return -EPERM;
}
priv->prom_priv->filter = simple_strtol(buf, NULL, 0);
IPW_DEBUG_INFO("Setting rtap filter to " BIT_FMT16 "\n",
BIT_ARG16(priv->prom_priv->filter));
return count;
}
static ssize_t show_rtap_filter(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct ipw_priv *priv = dev_get_drvdata(d);
return sprintf(buf, "0x%04X",
priv->prom_priv ? priv->prom_priv->filter : 0);
}
static ssize_t show_scan_age(struct device *d, struct device_attribute *attr,
char *buf)
{
struct ipw_priv *priv = dev_get_drvdata(d);
return sprintf(buf, "%d\n", priv->ieee->scan_age);
}
static ssize_t store_scan_age(struct device *d, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ipw_priv *priv = dev_get_drvdata(d);
struct net_device *dev = priv->net_dev;
char buffer[] = "00000000";
unsigned long len =
(sizeof(buffer) - 1) > count ? count : sizeof(buffer) - 1;
unsigned long val;
char *p = buffer;
IPW_DEBUG_INFO("enter\n");
strncpy(buffer, buf, len);
buffer[len] = 0;
if (p[1] == 'x' || p[1] == 'X' || p[0] == 'x' || p[0] == 'X') {
p++;
if (p[0] == 'x' || p[0] == 'X')
p++;
val = simple_strtoul(p, &p, 16);
} else
val = simple_strtoul(p, &p, 10);
if (p == buffer) {
IPW_DEBUG_INFO("%s: user supplied invalid value.\n", dev->name);
} else {
priv->ieee->scan_age = val;
IPW_DEBUG_INFO("set scan_age = %u\n", priv->ieee->scan_age);
}
IPW_DEBUG_INFO("exit\n");
return len;
}
static ssize_t show_led(struct device *d, struct device_attribute *attr,
char *buf)
{
struct ipw_priv *priv = dev_get_drvdata(d);
return sprintf(buf, "%d\n", (priv->config & CFG_NO_LED) ? 0 : 1);
}
static ssize_t store_led(struct device *d, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ipw_priv *priv = dev_get_drvdata(d);
IPW_DEBUG_INFO("enter\n");
if (count == 0)
return 0;
if (*buf == 0) {
IPW_DEBUG_LED("Disabling LED control.\n");
priv->config |= CFG_NO_LED;
ipw_led_shutdown(priv);
} else {
IPW_DEBUG_LED("Enabling LED control.\n");
priv->config &= ~CFG_NO_LED;
ipw_led_init(priv);
}
IPW_DEBUG_INFO("exit\n");
return count;
}
static ssize_t show_status(struct device *d,
struct device_attribute *attr, char *buf)
{
struct ipw_priv *p = dev_get_drvdata(d);
return sprintf(buf, "0x%08x\n", (int)p->status);
}
static ssize_t show_cfg(struct device *d, struct device_attribute *attr,
char *buf)
{
struct ipw_priv *p = dev_get_drvdata(d);
return sprintf(buf, "0x%08x\n", (int)p->config);
}
static ssize_t show_nic_type(struct device *d,
struct device_attribute *attr, char *buf)
{
struct ipw_priv *priv = dev_get_drvdata(d);
return sprintf(buf, "TYPE: %d\n", priv->nic_type);
}
static ssize_t show_ucode_version(struct device *d,
struct device_attribute *attr, char *buf)
{
u32 len = sizeof(u32), tmp = 0;
struct ipw_priv *p = dev_get_drvdata(d);
if (ipw_get_ordinal(p, IPW_ORD_STAT_UCODE_VERSION, &tmp, &len))
return 0;
return sprintf(buf, "0x%08x\n", tmp);
}
static ssize_t show_rtc(struct device *d, struct device_attribute *attr,
char *buf)
{
u32 len = sizeof(u32), tmp = 0;
struct ipw_priv *p = dev_get_drvdata(d);
if (ipw_get_ordinal(p, IPW_ORD_STAT_RTC, &tmp, &len))
return 0;
return sprintf(buf, "0x%08x\n", tmp);
}
static ssize_t show_eeprom_delay(struct device *d,
struct device_attribute *attr, char *buf)
{
struct ipw_priv *p = dev_get_drvdata(d);
int n = p->eeprom_delay;
return sprintf(buf, "%i\n", n);
}
static ssize_t store_eeprom_delay(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ipw_priv *p = dev_get_drvdata(d);
sscanf(buf, "%i", &p->eeprom_delay);
return strnlen(buf, count);
}
static ssize_t show_command_event_reg(struct device *d,
struct device_attribute *attr, char *buf)
{
u32 reg = 0;
struct ipw_priv *p = dev_get_drvdata(d);
reg = ipw_read_reg32(p, IPW_INTERNAL_CMD_EVENT);
return sprintf(buf, "0x%08x\n", reg);
}
static ssize_t store_command_event_reg(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
u32 reg;
struct ipw_priv *p = dev_get_drvdata(d);
sscanf(buf, "%x", &reg);
ipw_write_reg32(p, IPW_INTERNAL_CMD_EVENT, reg);
return strnlen(buf, count);
}
static ssize_t show_mem_gpio_reg(struct device *d,
struct device_attribute *attr, char *buf)
{
u32 reg = 0;
struct ipw_priv *p = dev_get_drvdata(d);
reg = ipw_read_reg32(p, 0x301100);
return sprintf(buf, "0x%08x\n", reg);
}
static ssize_t store_mem_gpio_reg(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
u32 reg;
struct ipw_priv *p = dev_get_drvdata(d);
sscanf(buf, "%x", &reg);
ipw_write_reg32(p, 0x301100, reg);
return strnlen(buf, count);
}
static ssize_t show_indirect_dword(struct device *d,
struct device_attribute *attr, char *buf)
{
u32 reg = 0;
struct ipw_priv *priv = dev_get_drvdata(d);
if (priv->status & STATUS_INDIRECT_DWORD)
reg = ipw_read_reg32(priv, priv->indirect_dword);
else
reg = 0;
return sprintf(buf, "0x%08x\n", reg);
}
static ssize_t store_indirect_dword(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ipw_priv *priv = dev_get_drvdata(d);
sscanf(buf, "%x", &priv->indirect_dword);
priv->status |= STATUS_INDIRECT_DWORD;
return strnlen(buf, count);
}
static ssize_t show_indirect_byte(struct device *d,
struct device_attribute *attr, char *buf)
{
u8 reg = 0;
struct ipw_priv *priv = dev_get_drvdata(d);
if (priv->status & STATUS_INDIRECT_BYTE)
reg = ipw_read_reg8(priv, priv->indirect_byte);
else
reg = 0;
return sprintf(buf, "0x%02x\n", reg);
}
static ssize_t store_indirect_byte(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ipw_priv *priv = dev_get_drvdata(d);
sscanf(buf, "%x", &priv->indirect_byte);
priv->status |= STATUS_INDIRECT_BYTE;
return strnlen(buf, count);
}
static ssize_t show_direct_dword(struct device *d,
struct device_attribute *attr, char *buf)
{
u32 reg = 0;
struct ipw_priv *priv = dev_get_drvdata(d);
if (priv->status & STATUS_DIRECT_DWORD)
reg = ipw_read32(priv, priv->direct_dword);
else
reg = 0;
return sprintf(buf, "0x%08x\n", reg);
}
static ssize_t store_direct_dword(struct device *d,
struct device_attribute *attr,
const char *buf, size_t count)
{
struct ipw_priv *priv = dev_get_drvdata(d);
sscanf(buf, "%x", &priv->direct_dword);
priv->status |= STATUS_DIRECT_DWORD;
return strnlen(buf, count);
}
static int rf_kill_active(struct ipw_priv *priv)
{
if (0 == (ipw_read32(priv, 0x30) & 0x10000)) {
priv->status |= STATUS_RF_KILL_HW;
wiphy_rfkill_set_hw_state(priv->ieee->wdev.wiphy, true);
} else {
priv->status &= ~STATUS_RF_KILL_HW;
wiphy_rfkill_set_hw_state(priv->ieee->wdev.wiphy, false);
}
return (priv->status & STATUS_RF_KILL_HW) ? 1 : 0;
}
static ssize_t show_rf_kill(struct device *d, struct device_attribute *attr,
char *buf)
{
struct ipw_priv *priv = dev_get_drvdata(d);
int val = ((priv->status & STATUS_RF_KILL_SW) ? 0x1 : 0x0) |
(rf_kill_active(priv) ? 0x2 : 0x0);
return sprintf(buf, "%i\n", val);
}
static int ipw_radio_kill_sw(struct ipw_priv *priv, int disable_radio)
{
if ((disable_radio ? 1 : 0) ==
((priv->status & STATUS_RF_KILL_SW) ? 1 : 0))
return 0;
IPW_DEBUG_RF_KILL("Manual SW RF Kill set to: RADIO %s\n",
disable_radio ? "OFF" : "ON");
if (disable_radio) {
priv->status |= STATUS_RF_KILL_SW;
cancel_delayed_work(&priv->request_scan);
cancel_delayed_work(&priv->request_direct_scan);
cancel_delayed_work(&priv->request_passive_scan);
cancel_delayed_work(&priv->scan_event);
schedule_work(&priv->down);
} else {
priv->status &= ~STATUS_RF_KILL_SW;
if (rf_kill_active(priv)) {
IPW_DEBUG_RF_KILL("Can not turn radio back on - "
"disabled by HW switch\n");
cancel_delayed_work(&priv->rf_kill);
schedule_delayed_work(&priv->rf_kill,
round_jiffies_relative(2 * HZ));
} else
schedule_work(&priv->up);
}
return 1;
}
static ssize_t store_rf_kill(struct device *d, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ipw_priv *priv = dev_get_drvdata(d);
ipw_radio_kill_sw(priv, buf[0] == '1');
return count;
}
static ssize_t show_speed_scan(struct device *d, struct device_attribute *attr,
char *buf)
{
struct ipw_priv *priv = dev_get_drvdata(d);
int pos = 0, len = 0;
if (priv->config & CFG_SPEED_SCAN) {
while (priv->speed_scan[pos] != 0)
len += sprintf(&buf[len], "%d ",
priv->speed_scan[pos++]);
return len + sprintf(&buf[len], "\n");
}
return sprintf(buf, "0\n");
}
static ssize_t store_speed_scan(struct device *d, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ipw_priv *priv = dev_get_drvdata(d);
int channel, pos = 0;
const char *p = buf;
while ((channel = simple_strtol(p, NULL, 0))) {
if (pos == MAX_SPEED_SCAN - 1) {
priv->speed_scan[pos] = 0;
break;
}
if (libipw_is_valid_channel(priv->ieee, channel))
priv->speed_scan[pos++] = channel;
else
IPW_WARNING("Skipping invalid channel request: %d\n",
channel);
p = strchr(p, ' ');
if (!p)
break;
while (*p == ' ' || *p == '\t')
p++;
}
if (pos == 0)
priv->config &= ~CFG_SPEED_SCAN;
else {
priv->speed_scan_pos = 0;
priv->config |= CFG_SPEED_SCAN;
}
return count;
}
static ssize_t show_net_stats(struct device *d, struct device_attribute *attr,
char *buf)
{
struct ipw_priv *priv = dev_get_drvdata(d);
return sprintf(buf, "%c\n", (priv->config & CFG_NET_STATS) ? '1' : '0');
}
static ssize_t store_net_stats(struct device *d, struct device_attribute *attr,
const char *buf, size_t count)
{
struct ipw_priv *priv = dev_get_drvdata(d);
if (buf[0] == '1')
priv->config |= CFG_NET_STATS;
else
priv->config &= ~CFG_NET_STATS;
return count;
}
static ssize_t show_channels(struct device *d,
struct device_attribute *attr,
char *buf)
{
struct ipw_priv *priv = dev_get_drvdata(d);
const struct libipw_geo *geo = libipw_get_geo(priv->ieee);
int len = 0, i;
len = sprintf(&buf[len],
"Displaying %d channels in 2.4Ghz band "
"(802.11bg):\n", geo->bg_channels);
for (i = 0; i < geo->bg_channels; i++) {
len += sprintf(&buf[len], "%d: BSS%s%s, %s, Band %s.\n",
geo->bg[i].channel,
geo->bg[i].flags & LIBIPW_CH_RADAR_DETECT ?
" (radar spectrum)" : "",
((geo->bg[i].flags & LIBIPW_CH_NO_IBSS) ||
(geo->bg[i].flags & LIBIPW_CH_RADAR_DETECT))
? "" : ", IBSS",
geo->bg[i].flags & LIBIPW_CH_PASSIVE_ONLY ?
"passive only" : "active/passive",
geo->bg[i].flags & LIBIPW_CH_B_ONLY ?
"B" : "B/G");
}
len += sprintf(&buf[len],
"Displaying %d channels in 5.2Ghz band "
"(802.11a):\n", geo->a_channels);
for (i = 0; i < geo->a_channels; i++) {
len += sprintf(&buf[len], "%d: BSS%s%s, %s.\n",
geo->a[i].channel,
geo->a[i].flags & LIBIPW_CH_RADAR_DETECT ?
" (radar spectrum)" : "",
((geo->a[i].flags & LIBIPW_CH_NO_IBSS) ||
(geo->a[i].flags & LIBIPW_CH_RADAR_DETECT))
? "" : ", IBSS",
geo->a[i].flags & LIBIPW_CH_PASSIVE_ONLY ?
"passive only" : "active/passive");
}
return len;
}
static void notify_wx_assoc_event(struct ipw_priv *priv)
{
union iwreq_data wrqu;
wrqu.ap_addr.sa_family = ARPHRD_ETHER;
if (priv->status & STATUS_ASSOCIATED)
memcpy(wrqu.ap_addr.sa_data, priv->bssid, ETH_ALEN);
else
eth_zero_addr(wrqu.ap_addr.sa_data);
wireless_send_event(priv->net_dev, SIOCGIWAP, &wrqu, NULL);
}
static void ipw_irq_tasklet(struct ipw_priv *priv)
{
u32 inta, inta_mask, handled = 0;
unsigned long flags;
int rc = 0;
spin_lock_irqsave(&priv->irq_lock, flags);
inta = ipw_read32(priv, IPW_INTA_RW);
inta_mask = ipw_read32(priv, IPW_INTA_MASK_R);
if (inta == 0xFFFFFFFF) {
IPW_WARNING("TASKLET INTA == 0xFFFFFFFF\n");
inta = 0;
}
inta &= (IPW_INTA_MASK_ALL & inta_mask);
inta |= priv->isr_inta;
spin_unlock_irqrestore(&priv->irq_lock, flags);
spin_lock_irqsave(&priv->lock, flags);
if (inta & IPW_INTA_BIT_RX_TRANSFER) {
ipw_rx(priv);
handled |= IPW_INTA_BIT_RX_TRANSFER;
}
if (inta & IPW_INTA_BIT_TX_CMD_QUEUE) {
IPW_DEBUG_HC("Command completed.\n");
rc = ipw_queue_tx_reclaim(priv, &priv->txq_cmd, -1);
priv->status &= ~STATUS_HCMD_ACTIVE;
wake_up_interruptible(&priv->wait_command_queue);
handled |= IPW_INTA_BIT_TX_CMD_QUEUE;
}
if (inta & IPW_INTA_BIT_TX_QUEUE_1) {
IPW_DEBUG_TX("TX_QUEUE_1\n");
rc = ipw_queue_tx_reclaim(priv, &priv->txq[0], 0);
handled |= IPW_INTA_BIT_TX_QUEUE_1;
}
if (inta & IPW_INTA_BIT_TX_QUEUE_2) {
IPW_DEBUG_TX("TX_QUEUE_2\n");
rc = ipw_queue_tx_reclaim(priv, &priv->txq[1], 1);
handled |= IPW_INTA_BIT_TX_QUEUE_2;
}
if (inta & IPW_INTA_BIT_TX_QUEUE_3) {
IPW_DEBUG_TX("TX_QUEUE_3\n");
rc = ipw_queue_tx_reclaim(priv, &priv->txq[2], 2);
handled |= IPW_INTA_BIT_TX_QUEUE_3;
}
if (inta & IPW_INTA_BIT_TX_QUEUE_4) {
IPW_DEBUG_TX("TX_QUEUE_4\n");
rc = ipw_queue_tx_reclaim(priv, &priv->txq[3], 3);
handled |= IPW_INTA_BIT_TX_QUEUE_4;
}
if (inta & IPW_INTA_BIT_STATUS_CHANGE) {
IPW_WARNING("STATUS_CHANGE\n");
handled |= IPW_INTA_BIT_STATUS_CHANGE;
}
if (inta & IPW_INTA_BIT_BEACON_PERIOD_EXPIRED) {
IPW_WARNING("TX_PERIOD_EXPIRED\n");
handled |= IPW_INTA_BIT_BEACON_PERIOD_EXPIRED;
}
if (inta & IPW_INTA_BIT_SLAVE_MODE_HOST_CMD_DONE) {
IPW_WARNING("HOST_CMD_DONE\n");
handled |= IPW_INTA_BIT_SLAVE_MODE_HOST_CMD_DONE;
}
if (inta & IPW_INTA_BIT_FW_INITIALIZATION_DONE) {
IPW_WARNING("FW_INITIALIZATION_DONE\n");
handled |= IPW_INTA_BIT_FW_INITIALIZATION_DONE;
}
if (inta & IPW_INTA_BIT_FW_CARD_DISABLE_PHY_OFF_DONE) {
IPW_WARNING("PHY_OFF_DONE\n");
handled |= IPW_INTA_BIT_FW_CARD_DISABLE_PHY_OFF_DONE;
}
if (inta & IPW_INTA_BIT_RF_KILL_DONE) {
IPW_DEBUG_RF_KILL("RF_KILL_DONE\n");
priv->status |= STATUS_RF_KILL_HW;
wiphy_rfkill_set_hw_state(priv->ieee->wdev.wiphy, true);
wake_up_interruptible(&priv->wait_command_queue);
priv->status &= ~(STATUS_ASSOCIATED | STATUS_ASSOCIATING);
cancel_delayed_work(&priv->request_scan);
cancel_delayed_work(&priv->request_direct_scan);
cancel_delayed_work(&priv->request_passive_scan);
cancel_delayed_work(&priv->scan_event);
schedule_work(&priv->link_down);
schedule_delayed_work(&priv->rf_kill, 2 * HZ);
handled |= IPW_INTA_BIT_RF_KILL_DONE;
}
if (inta & IPW_INTA_BIT_FATAL_ERROR) {
IPW_WARNING("Firmware error detected. Restarting.\n");
if (priv->error) {
IPW_DEBUG_FW("Sysfs 'error' log already exists.\n");
if (ipw_debug_level & IPW_DL_FW_ERRORS) {
struct ipw_fw_error *error =
ipw_alloc_error_log(priv);
ipw_dump_error_log(priv, error);
kfree(error);
}
} else {
priv->error = ipw_alloc_error_log(priv);
if (priv->error)
IPW_DEBUG_FW("Sysfs 'error' log captured.\n");
else
IPW_DEBUG_FW("Error allocating sysfs 'error' "
"log.\n");
if (ipw_debug_level & IPW_DL_FW_ERRORS)
ipw_dump_error_log(priv, priv->error);
}
if (priv->ieee->sec.encrypt) {
priv->status &= ~STATUS_ASSOCIATED;
notify_wx_assoc_event(priv);
}
priv->status &= ~STATUS_INIT;
priv->status &= ~STATUS_HCMD_ACTIVE;
wake_up_interruptible(&priv->wait_command_queue);
schedule_work(&priv->adapter_restart);
handled |= IPW_INTA_BIT_FATAL_ERROR;
}
if (inta & IPW_INTA_BIT_PARITY_ERROR) {
IPW_ERROR("Parity error\n");
handled |= IPW_INTA_BIT_PARITY_ERROR;
}
if (handled != inta) {
IPW_ERROR("Unhandled INTA bits 0x%08x\n", inta & ~handled);
}
spin_unlock_irqrestore(&priv->lock, flags);
ipw_enable_interrupts(priv);
}
static char *get_cmd_string(u8 cmd)
{
switch (cmd) {
IPW_CMD(HOST_COMPLETE);
IPW_CMD(POWER_DOWN);
IPW_CMD(SYSTEM_CONFIG);
IPW_CMD(MULTICAST_ADDRESS);
IPW_CMD(SSID);
IPW_CMD(ADAPTER_ADDRESS);
IPW_CMD(PORT_TYPE);
IPW_CMD(RTS_THRESHOLD);
IPW_CMD(FRAG_THRESHOLD);
IPW_CMD(POWER_MODE);
IPW_CMD(WEP_KEY);
IPW_CMD(TGI_TX_KEY);
IPW_CMD(SCAN_REQUEST);
IPW_CMD(SCAN_REQUEST_EXT);
IPW_CMD(ASSOCIATE);
IPW_CMD(SUPPORTED_RATES);
IPW_CMD(SCAN_ABORT);
IPW_CMD(TX_FLUSH);
IPW_CMD(QOS_PARAMETERS);
IPW_CMD(DINO_CONFIG);
IPW_CMD(RSN_CAPABILITIES);
IPW_CMD(RX_KEY);
IPW_CMD(CARD_DISABLE);
IPW_CMD(SEED_NUMBER);
IPW_CMD(TX_POWER);
IPW_CMD(COUNTRY_INFO);
IPW_CMD(AIRONET_INFO);
IPW_CMD(AP_TX_POWER);
IPW_CMD(CCKM_INFO);
IPW_CMD(CCX_VER_INFO);
IPW_CMD(SET_CALIBRATION);
IPW_CMD(SENSITIVITY_CALIB);
IPW_CMD(RETRY_LIMIT);
IPW_CMD(IPW_PRE_POWER_DOWN);
IPW_CMD(VAP_BEACON_TEMPLATE);
IPW_CMD(VAP_DTIM_PERIOD);
IPW_CMD(EXT_SUPPORTED_RATES);
IPW_CMD(VAP_LOCAL_TX_PWR_CONSTRAINT);
IPW_CMD(VAP_QUIET_INTERVALS);
IPW_CMD(VAP_CHANNEL_SWITCH);
IPW_CMD(VAP_MANDATORY_CHANNELS);
IPW_CMD(VAP_CELL_PWR_LIMIT);
IPW_CMD(VAP_CF_PARAM_SET);
IPW_CMD(VAP_SET_BEACONING_STATE);
IPW_CMD(MEASUREMENT);
IPW_CMD(POWER_CAPABILITY);
IPW_CMD(SUPPORTED_CHANNELS);
IPW_CMD(TPC_REPORT);
IPW_CMD(WME_INFO);
IPW_CMD(PRODUCTION_COMMAND);
default:
return "UNKNOWN";
}
}
static int __ipw_send_cmd(struct ipw_priv *priv, struct host_cmd *cmd)
{
int rc = 0;
unsigned long flags;
unsigned long now, end;
spin_lock_irqsave(&priv->lock, flags);
if (priv->status & STATUS_HCMD_ACTIVE) {
IPW_ERROR("Failed to send %s: Already sending a command.\n",
get_cmd_string(cmd->cmd));
spin_unlock_irqrestore(&priv->lock, flags);
return -EAGAIN;
}
priv->status |= STATUS_HCMD_ACTIVE;
if (priv->cmdlog) {
priv->cmdlog[priv->cmdlog_pos].jiffies = jiffies;
priv->cmdlog[priv->cmdlog_pos].cmd.cmd = cmd->cmd;
priv->cmdlog[priv->cmdlog_pos].cmd.len = cmd->len;
memcpy(priv->cmdlog[priv->cmdlog_pos].cmd.param, cmd->param,
cmd->len);
priv->cmdlog[priv->cmdlog_pos].retcode = -1;
}
IPW_DEBUG_HC("%s command (#%d) %d bytes: 0x%08X\n",
get_cmd_string(cmd->cmd), cmd->cmd, cmd->len,
priv->status);
#ifndef DEBUG_CMD_WEP_KEY
if (cmd->cmd == IPW_CMD_WEP_KEY)
IPW_DEBUG_HC("WEP_KEY command masked out for secure.\n");
else
#endif
printk_buf(IPW_DL_HOST_COMMAND, (u8 *) cmd->param, cmd->len);
rc = ipw_queue_tx_hcmd(priv, cmd->cmd, cmd->param, cmd->len, 0);
if (rc) {
priv->status &= ~STATUS_HCMD_ACTIVE;
IPW_ERROR("Failed to send %s: Reason %d\n",
get_cmd_string(cmd->cmd), rc);
spin_unlock_irqrestore(&priv->lock, flags);
goto exit;
}
spin_unlock_irqrestore(&priv->lock, flags);
now = jiffies;
end = now + HOST_COMPLETE_TIMEOUT;
again:
rc = wait_event_interruptible_timeout(priv->wait_command_queue,
!(priv->
status & STATUS_HCMD_ACTIVE),
end - now);
if (rc < 0) {
now = jiffies;
if (time_before(now, end))
goto again;
rc = 0;
}
if (rc == 0) {
spin_lock_irqsave(&priv->lock, flags);
if (priv->status & STATUS_HCMD_ACTIVE) {
IPW_ERROR("Failed to send %s: Command timed out.\n",
get_cmd_string(cmd->cmd));
priv->status &= ~STATUS_HCMD_ACTIVE;
spin_unlock_irqrestore(&priv->lock, flags);
rc = -EIO;
goto exit;
}
spin_unlock_irqrestore(&priv->lock, flags);
} else
rc = 0;
if (priv->status & STATUS_RF_KILL_HW) {
IPW_ERROR("Failed to send %s: Aborted due to RF kill switch.\n",
get_cmd_string(cmd->cmd));
rc = -EIO;
goto exit;
}
exit:
if (priv->cmdlog) {
priv->cmdlog[priv->cmdlog_pos++].retcode = rc;
priv->cmdlog_pos %= priv->cmdlog_len;
}
return rc;
}
static int ipw_send_cmd_simple(struct ipw_priv *priv, u8 command)
{
struct host_cmd cmd = {
.cmd = command,
};
return __ipw_send_cmd(priv, &cmd);
}
static int ipw_send_cmd_pdu(struct ipw_priv *priv, u8 command, u8 len,
void *data)
{
struct host_cmd cmd = {
.cmd = command,
.len = len,
.param = data,
};
return __ipw_send_cmd(priv, &cmd);
}
static int ipw_send_host_complete(struct ipw_priv *priv)
{
if (!priv) {
IPW_ERROR("Invalid args\n");
return -1;
}
return ipw_send_cmd_simple(priv, IPW_CMD_HOST_COMPLETE);
}
static int ipw_send_system_config(struct ipw_priv *priv)
{
return ipw_send_cmd_pdu(priv, IPW_CMD_SYSTEM_CONFIG,
sizeof(priv->sys_config),
&priv->sys_config);
}
static int ipw_send_ssid(struct ipw_priv *priv, u8 * ssid, int len)
{
if (!priv || !ssid) {
IPW_ERROR("Invalid args\n");
return -1;
}
return ipw_send_cmd_pdu(priv, IPW_CMD_SSID, min(len, IW_ESSID_MAX_SIZE),
ssid);
}
static int ipw_send_adapter_address(struct ipw_priv *priv, u8 * mac)
{
if (!priv || !mac) {
IPW_ERROR("Invalid args\n");
return -1;
}
IPW_DEBUG_INFO("%s: Setting MAC to %pM\n",
priv->net_dev->name, mac);
return ipw_send_cmd_pdu(priv, IPW_CMD_ADAPTER_ADDRESS, ETH_ALEN, mac);
}
static void ipw_adapter_restart(void *adapter)
{
struct ipw_priv *priv = adapter;
if (priv->status & STATUS_RF_KILL_MASK)
return;
ipw_down(priv);
if (priv->assoc_network &&
(priv->assoc_network->capability & WLAN_CAPABILITY_IBSS))
ipw_remove_current_network(priv);
if (ipw_up(priv)) {
IPW_ERROR("Failed to up device\n");
return;
}
}
static void ipw_bg_adapter_restart(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, adapter_restart);
mutex_lock(&priv->mutex);
ipw_adapter_restart(priv);
mutex_unlock(&priv->mutex);
}
static void ipw_scan_check(void *data)
{
struct ipw_priv *priv = data;
if (priv->status & STATUS_SCAN_ABORTING) {
IPW_DEBUG_SCAN("Scan completion watchdog resetting "
"adapter after (%dms).\n",
jiffies_to_msecs(IPW_SCAN_CHECK_WATCHDOG));
schedule_work(&priv->adapter_restart);
} else if (priv->status & STATUS_SCANNING) {
IPW_DEBUG_SCAN("Scan completion watchdog aborting scan "
"after (%dms).\n",
jiffies_to_msecs(IPW_SCAN_CHECK_WATCHDOG));
ipw_abort_scan(priv);
schedule_delayed_work(&priv->scan_check, HZ);
}
}
static void ipw_bg_scan_check(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, scan_check.work);
mutex_lock(&priv->mutex);
ipw_scan_check(priv);
mutex_unlock(&priv->mutex);
}
static int ipw_send_scan_request_ext(struct ipw_priv *priv,
struct ipw_scan_request_ext *request)
{
return ipw_send_cmd_pdu(priv, IPW_CMD_SCAN_REQUEST_EXT,
sizeof(*request), request);
}
static int ipw_send_scan_abort(struct ipw_priv *priv)
{
if (!priv) {
IPW_ERROR("Invalid args\n");
return -1;
}
return ipw_send_cmd_simple(priv, IPW_CMD_SCAN_ABORT);
}
static int ipw_set_sensitivity(struct ipw_priv *priv, u16 sens)
{
struct ipw_sensitivity_calib calib = {
.beacon_rssi_raw = cpu_to_le16(sens),
};
return ipw_send_cmd_pdu(priv, IPW_CMD_SENSITIVITY_CALIB, sizeof(calib),
&calib);
}
static int ipw_send_associate(struct ipw_priv *priv,
struct ipw_associate *associate)
{
if (!priv || !associate) {
IPW_ERROR("Invalid args\n");
return -1;
}
return ipw_send_cmd_pdu(priv, IPW_CMD_ASSOCIATE, sizeof(*associate),
associate);
}
static int ipw_send_supported_rates(struct ipw_priv *priv,
struct ipw_supported_rates *rates)
{
if (!priv || !rates) {
IPW_ERROR("Invalid args\n");
return -1;
}
return ipw_send_cmd_pdu(priv, IPW_CMD_SUPPORTED_RATES, sizeof(*rates),
rates);
}
static int ipw_set_random_seed(struct ipw_priv *priv)
{
u32 val;
if (!priv) {
IPW_ERROR("Invalid args\n");
return -1;
}
get_random_bytes(&val, sizeof(val));
return ipw_send_cmd_pdu(priv, IPW_CMD_SEED_NUMBER, sizeof(val), &val);
}
static int ipw_send_card_disable(struct ipw_priv *priv, u32 phy_off)
{
__le32 v = cpu_to_le32(phy_off);
if (!priv) {
IPW_ERROR("Invalid args\n");
return -1;
}
return ipw_send_cmd_pdu(priv, IPW_CMD_CARD_DISABLE, sizeof(v), &v);
}
static int ipw_send_tx_power(struct ipw_priv *priv, struct ipw_tx_power *power)
{
if (!priv || !power) {
IPW_ERROR("Invalid args\n");
return -1;
}
return ipw_send_cmd_pdu(priv, IPW_CMD_TX_POWER, sizeof(*power), power);
}
static int ipw_set_tx_power(struct ipw_priv *priv)
{
const struct libipw_geo *geo = libipw_get_geo(priv->ieee);
struct ipw_tx_power tx_power;
s8 max_power;
int i;
memset(&tx_power, 0, sizeof(tx_power));
tx_power.ieee_mode = IPW_G_MODE;
tx_power.num_channels = geo->bg_channels;
for (i = 0; i < geo->bg_channels; i++) {
max_power = geo->bg[i].max_power;
tx_power.channels_tx_power[i].channel_number =
geo->bg[i].channel;
tx_power.channels_tx_power[i].tx_power = max_power ?
min(max_power, priv->tx_power) : priv->tx_power;
}
if (ipw_send_tx_power(priv, &tx_power))
return -EIO;
tx_power.ieee_mode = IPW_B_MODE;
if (ipw_send_tx_power(priv, &tx_power))
return -EIO;
if (priv->ieee->abg_true) {
tx_power.ieee_mode = IPW_A_MODE;
tx_power.num_channels = geo->a_channels;
for (i = 0; i < tx_power.num_channels; i++) {
max_power = geo->a[i].max_power;
tx_power.channels_tx_power[i].channel_number =
geo->a[i].channel;
tx_power.channels_tx_power[i].tx_power = max_power ?
min(max_power, priv->tx_power) : priv->tx_power;
}
if (ipw_send_tx_power(priv, &tx_power))
return -EIO;
}
return 0;
}
static int ipw_send_rts_threshold(struct ipw_priv *priv, u16 rts)
{
struct ipw_rts_threshold rts_threshold = {
.rts_threshold = cpu_to_le16(rts),
};
if (!priv) {
IPW_ERROR("Invalid args\n");
return -1;
}
return ipw_send_cmd_pdu(priv, IPW_CMD_RTS_THRESHOLD,
sizeof(rts_threshold), &rts_threshold);
}
static int ipw_send_frag_threshold(struct ipw_priv *priv, u16 frag)
{
struct ipw_frag_threshold frag_threshold = {
.frag_threshold = cpu_to_le16(frag),
};
if (!priv) {
IPW_ERROR("Invalid args\n");
return -1;
}
return ipw_send_cmd_pdu(priv, IPW_CMD_FRAG_THRESHOLD,
sizeof(frag_threshold), &frag_threshold);
}
static int ipw_send_power_mode(struct ipw_priv *priv, u32 mode)
{
__le32 param;
if (!priv) {
IPW_ERROR("Invalid args\n");
return -1;
}
switch (mode) {
case IPW_POWER_BATTERY:
param = cpu_to_le32(IPW_POWER_INDEX_3);
break;
case IPW_POWER_AC:
param = cpu_to_le32(IPW_POWER_MODE_CAM);
break;
default:
param = cpu_to_le32(mode);
break;
}
return ipw_send_cmd_pdu(priv, IPW_CMD_POWER_MODE, sizeof(param),
&param);
}
static int ipw_send_retry_limit(struct ipw_priv *priv, u8 slimit, u8 llimit)
{
struct ipw_retry_limit retry_limit = {
.short_retry_limit = slimit,
.long_retry_limit = llimit
};
if (!priv) {
IPW_ERROR("Invalid args\n");
return -1;
}
return ipw_send_cmd_pdu(priv, IPW_CMD_RETRY_LIMIT, sizeof(retry_limit),
&retry_limit);
}
static inline void eeprom_write_reg(struct ipw_priv *p, u32 data)
{
ipw_write_reg32(p, FW_MEM_REG_EEPROM_ACCESS, data);
udelay(p->eeprom_delay);
}
static void eeprom_cs(struct ipw_priv *priv)
{
eeprom_write_reg(priv, 0);
eeprom_write_reg(priv, EEPROM_BIT_CS);
eeprom_write_reg(priv, EEPROM_BIT_CS | EEPROM_BIT_SK);
eeprom_write_reg(priv, EEPROM_BIT_CS);
}
static void eeprom_disable_cs(struct ipw_priv *priv)
{
eeprom_write_reg(priv, EEPROM_BIT_CS);
eeprom_write_reg(priv, 0);
eeprom_write_reg(priv, EEPROM_BIT_SK);
}
static inline void eeprom_write_bit(struct ipw_priv *p, u8 bit)
{
int d = (bit ? EEPROM_BIT_DI : 0);
eeprom_write_reg(p, EEPROM_BIT_CS | d);
eeprom_write_reg(p, EEPROM_BIT_CS | d | EEPROM_BIT_SK);
}
static void eeprom_op(struct ipw_priv *priv, u8 op, u8 addr)
{
int i;
eeprom_cs(priv);
eeprom_write_bit(priv, 1);
eeprom_write_bit(priv, op & 2);
eeprom_write_bit(priv, op & 1);
for (i = 7; i >= 0; i--) {
eeprom_write_bit(priv, addr & (1 << i));
}
}
static u16 eeprom_read_u16(struct ipw_priv *priv, u8 addr)
{
int i;
u16 r = 0;
eeprom_op(priv, EEPROM_CMD_READ, addr);
eeprom_write_reg(priv, EEPROM_BIT_CS);
for (i = 0; i < 16; i++) {
u32 data = 0;
eeprom_write_reg(priv, EEPROM_BIT_CS | EEPROM_BIT_SK);
eeprom_write_reg(priv, EEPROM_BIT_CS);
data = ipw_read_reg32(priv, FW_MEM_REG_EEPROM_ACCESS);
r = (r << 1) | ((data & EEPROM_BIT_DO) ? 1 : 0);
}
eeprom_write_reg(priv, 0);
eeprom_disable_cs(priv);
return r;
}
static void eeprom_parse_mac(struct ipw_priv *priv, u8 * mac)
{
memcpy(mac, &priv->eeprom[EEPROM_MAC_ADDRESS], ETH_ALEN);
}
static void ipw_read_eeprom(struct ipw_priv *priv)
{
int i;
__le16 *eeprom = (__le16 *) priv->eeprom;
IPW_DEBUG_TRACE(">>\n");
for (i = 0; i < 128; i++)
eeprom[i] = cpu_to_le16(eeprom_read_u16(priv, (u8) i));
IPW_DEBUG_TRACE("<<\n");
}
static void ipw_eeprom_init_sram(struct ipw_priv *priv)
{
int i;
IPW_DEBUG_TRACE(">>\n");
if (priv->eeprom[EEPROM_VERSION] != 0) {
IPW_DEBUG_INFO("Writing EEPROM data into SRAM\n");
for (i = 0; i < IPW_EEPROM_IMAGE_SIZE; i++)
ipw_write8(priv, IPW_EEPROM_DATA + i, priv->eeprom[i]);
ipw_write32(priv, IPW_EEPROM_LOAD_DISABLE, 0);
} else {
IPW_DEBUG_INFO("Enabling FW initializationg of SRAM\n");
ipw_write32(priv, IPW_EEPROM_LOAD_DISABLE, 1);
}
IPW_DEBUG_TRACE("<<\n");
}
static void ipw_zero_memory(struct ipw_priv *priv, u32 start, u32 count)
{
count >>= 2;
if (!count)
return;
_ipw_write32(priv, IPW_AUTOINC_ADDR, start);
while (count--)
_ipw_write32(priv, IPW_AUTOINC_DATA, 0);
}
static inline void ipw_fw_dma_reset_command_blocks(struct ipw_priv *priv)
{
ipw_zero_memory(priv, IPW_SHARED_SRAM_DMA_CONTROL,
CB_NUMBER_OF_ELEMENTS_SMALL *
sizeof(struct command_block));
}
static int ipw_fw_dma_enable(struct ipw_priv *priv)
{
IPW_DEBUG_FW(">> :\n");
ipw_fw_dma_reset_command_blocks(priv);
ipw_write_reg32(priv, IPW_DMA_I_CB_BASE, IPW_SHARED_SRAM_DMA_CONTROL);
IPW_DEBUG_FW("<< :\n");
return 0;
}
static void ipw_fw_dma_abort(struct ipw_priv *priv)
{
u32 control = 0;
IPW_DEBUG_FW(">> :\n");
control = DMA_CONTROL_SMALL_CB_CONST_VALUE | DMA_CB_STOP_AND_ABORT;
ipw_write_reg32(priv, IPW_DMA_I_DMA_CONTROL, control);
priv->sram_desc.last_cb_index = 0;
IPW_DEBUG_FW("<<\n");
}
static int ipw_fw_dma_write_command_block(struct ipw_priv *priv, int index,
struct command_block *cb)
{
u32 address =
IPW_SHARED_SRAM_DMA_CONTROL +
(sizeof(struct command_block) * index);
IPW_DEBUG_FW(">> :\n");
ipw_write_indirect(priv, address, (u8 *) cb,
(int)sizeof(struct command_block));
IPW_DEBUG_FW("<< :\n");
return 0;
}
static int ipw_fw_dma_kick(struct ipw_priv *priv)
{
u32 control = 0;
u32 index = 0;
IPW_DEBUG_FW(">> :\n");
for (index = 0; index < priv->sram_desc.last_cb_index; index++)
ipw_fw_dma_write_command_block(priv, index,
&priv->sram_desc.cb_list[index]);
ipw_clear_bit(priv, IPW_RESET_REG,
IPW_RESET_REG_MASTER_DISABLED |
IPW_RESET_REG_STOP_MASTER);
control = DMA_CONTROL_SMALL_CB_CONST_VALUE | DMA_CB_START;
ipw_write_reg32(priv, IPW_DMA_I_DMA_CONTROL, control);
IPW_DEBUG_FW("<< :\n");
return 0;
}
static void ipw_fw_dma_dump_command_block(struct ipw_priv *priv)
{
u32 address;
u32 register_value = 0;
u32 cb_fields_address = 0;
IPW_DEBUG_FW(">> :\n");
address = ipw_read_reg32(priv, IPW_DMA_I_CURRENT_CB);
IPW_DEBUG_FW_INFO("Current CB is 0x%x\n", address);
register_value = ipw_read_reg32(priv, IPW_DMA_I_DMA_CONTROL);
IPW_DEBUG_FW_INFO("IPW_DMA_I_DMA_CONTROL is 0x%x\n", register_value);
cb_fields_address = address;
register_value = ipw_read_reg32(priv, cb_fields_address);
IPW_DEBUG_FW_INFO("Current CB Control Field is 0x%x\n", register_value);
cb_fields_address += sizeof(u32);
register_value = ipw_read_reg32(priv, cb_fields_address);
IPW_DEBUG_FW_INFO("Current CB Source Field is 0x%x\n", register_value);
cb_fields_address += sizeof(u32);
register_value = ipw_read_reg32(priv, cb_fields_address);
IPW_DEBUG_FW_INFO("Current CB Destination Field is 0x%x\n",
register_value);
cb_fields_address += sizeof(u32);
register_value = ipw_read_reg32(priv, cb_fields_address);
IPW_DEBUG_FW_INFO("Current CB Status Field is 0x%x\n", register_value);
IPW_DEBUG_FW(">> :\n");
}
static int ipw_fw_dma_command_block_index(struct ipw_priv *priv)
{
u32 current_cb_address = 0;
u32 current_cb_index = 0;
IPW_DEBUG_FW("<< :\n");
current_cb_address = ipw_read_reg32(priv, IPW_DMA_I_CURRENT_CB);
current_cb_index = (current_cb_address - IPW_SHARED_SRAM_DMA_CONTROL) /
sizeof(struct command_block);
IPW_DEBUG_FW_INFO("Current CB index 0x%x address = 0x%X\n",
current_cb_index, current_cb_address);
IPW_DEBUG_FW(">> :\n");
return current_cb_index;
}
static int ipw_fw_dma_add_command_block(struct ipw_priv *priv,
u32 src_address,
u32 dest_address,
u32 length,
int interrupt_enabled, int is_last)
{
u32 control = CB_VALID | CB_SRC_LE | CB_DEST_LE | CB_SRC_AUTOINC |
CB_SRC_IO_GATED | CB_DEST_AUTOINC | CB_SRC_SIZE_LONG |
CB_DEST_SIZE_LONG;
struct command_block *cb;
u32 last_cb_element = 0;
IPW_DEBUG_FW_INFO("src_address=0x%x dest_address=0x%x length=0x%x\n",
src_address, dest_address, length);
if (priv->sram_desc.last_cb_index >= CB_NUMBER_OF_ELEMENTS_SMALL)
return -1;
last_cb_element = priv->sram_desc.last_cb_index;
cb = &priv->sram_desc.cb_list[last_cb_element];
priv->sram_desc.last_cb_index++;
if (interrupt_enabled)
control |= CB_INT_ENABLED;
if (is_last)
control |= CB_LAST_VALID;
control |= length;
cb->status = control ^ src_address ^ dest_address;
cb->dest_addr = dest_address;
cb->source_addr = src_address;
cb->control = control;
return 0;
}
static int ipw_fw_dma_add_buffer(struct ipw_priv *priv, dma_addr_t *src_address,
int nr, u32 dest_address, u32 len)
{
int ret, i;
u32 size;
IPW_DEBUG_FW(">>\n");
IPW_DEBUG_FW_INFO("nr=%d dest_address=0x%x len=0x%x\n",
nr, dest_address, len);
for (i = 0; i < nr; i++) {
size = min_t(u32, len - i * CB_MAX_LENGTH, CB_MAX_LENGTH);
ret = ipw_fw_dma_add_command_block(priv, src_address[i],
dest_address +
i * CB_MAX_LENGTH, size,
0, 0);
if (ret) {
IPW_DEBUG_FW_INFO(": Failed\n");
return -1;
} else
IPW_DEBUG_FW_INFO(": Added new cb\n");
}
IPW_DEBUG_FW("<<\n");
return 0;
}
static int ipw_fw_dma_wait(struct ipw_priv *priv)
{
u32 current_index = 0, previous_index;
u32 watchdog = 0;
IPW_DEBUG_FW(">> :\n");
current_index = ipw_fw_dma_command_block_index(priv);
IPW_DEBUG_FW_INFO("sram_desc.last_cb_index:0x%08X\n",
(int)priv->sram_desc.last_cb_index);
while (current_index < priv->sram_desc.last_cb_index) {
udelay(50);
previous_index = current_index;
current_index = ipw_fw_dma_command_block_index(priv);
if (previous_index < current_index) {
watchdog = 0;
continue;
}
if (++watchdog > 400) {
IPW_DEBUG_FW_INFO("Timeout\n");
ipw_fw_dma_dump_command_block(priv);
ipw_fw_dma_abort(priv);
return -1;
}
}
ipw_fw_dma_abort(priv);
ipw_set_bit(priv, IPW_RESET_REG,
IPW_RESET_REG_MASTER_DISABLED | IPW_RESET_REG_STOP_MASTER);
IPW_DEBUG_FW("<< dmaWaitSync\n");
return 0;
}
static void ipw_remove_current_network(struct ipw_priv *priv)
{
struct list_head *element, *safe;
struct libipw_network *network = NULL;
unsigned long flags;
spin_lock_irqsave(&priv->ieee->lock, flags);
list_for_each_safe(element, safe, &priv->ieee->network_list) {
network = list_entry(element, struct libipw_network, list);
if (ether_addr_equal(network->bssid, priv->bssid)) {
list_del(element);
list_add_tail(&network->list,
&priv->ieee->network_free_list);
}
}
spin_unlock_irqrestore(&priv->ieee->lock, flags);
}
static inline int ipw_alive(struct ipw_priv *priv)
{
return ipw_read32(priv, 0x90) == 0xd55555d5;
}
static int ipw_poll_bit(struct ipw_priv *priv, u32 addr, u32 mask,
int timeout)
{
int i = 0;
do {
if ((ipw_read32(priv, addr) & mask) == mask)
return i;
mdelay(10);
i += 10;
} while (i < timeout);
return -ETIME;
}
static int ipw_stop_master(struct ipw_priv *priv)
{
int rc;
IPW_DEBUG_TRACE(">>\n");
ipw_set_bit(priv, IPW_RESET_REG, IPW_RESET_REG_STOP_MASTER);
rc = ipw_poll_bit(priv, IPW_RESET_REG,
IPW_RESET_REG_MASTER_DISABLED, 100);
if (rc < 0) {
IPW_ERROR("wait for stop master failed after 100ms\n");
return -1;
}
IPW_DEBUG_INFO("stop master %dms\n", rc);
return rc;
}
static void ipw_arc_release(struct ipw_priv *priv)
{
IPW_DEBUG_TRACE(">>\n");
mdelay(5);
ipw_clear_bit(priv, IPW_RESET_REG, CBD_RESET_REG_PRINCETON_RESET);
mdelay(5);
}
static int ipw_load_ucode(struct ipw_priv *priv, u8 * data, size_t len)
{
int rc = 0, i, addr;
u8 cr = 0;
__le16 *image;
image = (__le16 *) data;
IPW_DEBUG_TRACE(">>\n");
rc = ipw_stop_master(priv);
if (rc < 0)
return rc;
for (addr = IPW_SHARED_LOWER_BOUND;
addr < IPW_REGISTER_DOMAIN1_END; addr += 4) {
ipw_write32(priv, addr, 0);
}
memset(&priv->dino_alive, 0, sizeof(priv->dino_alive));
ipw_write_reg32(priv, IPW_MEM_HALT_AND_RESET, IPW_BIT_HALT_RESET_ON);
ipw_arc_release(priv);
ipw_write_reg32(priv, IPW_MEM_HALT_AND_RESET, IPW_BIT_HALT_RESET_OFF);
mdelay(1);
ipw_write_reg32(priv, IPW_INTERNAL_CMD_EVENT, IPW_BASEBAND_POWER_DOWN);
mdelay(1);
ipw_write_reg32(priv, IPW_INTERNAL_CMD_EVENT, 0);
mdelay(1);
ipw_write_reg8(priv, IPW_BASEBAND_CONTROL_STATUS, 0x0);
ipw_write_reg8(priv, IPW_BASEBAND_CONTROL_STATUS, DINO_ENABLE_CS);
mdelay(1);
for (i = 0; i < len / 2; i++)
ipw_write_reg16(priv, IPW_BASEBAND_CONTROL_STORE,
le16_to_cpu(image[i]));
ipw_write_reg8(priv, IPW_BASEBAND_CONTROL_STATUS, 0);
ipw_write_reg8(priv, IPW_BASEBAND_CONTROL_STATUS, DINO_ENABLE_SYSTEM);
for (i = 0; i < 100; i++) {
cr = ipw_read_reg8(priv, IPW_BASEBAND_CONTROL_STATUS);
if (cr & DINO_RXFIFO_DATA)
break;
mdelay(1);
}
if (cr & DINO_RXFIFO_DATA) {
__le32 response_buffer[(sizeof(priv->dino_alive) + 3) / 4];
for (i = 0; i < ARRAY_SIZE(response_buffer); i++)
response_buffer[i] =
cpu_to_le32(ipw_read_reg32(priv,
IPW_BASEBAND_RX_FIFO_READ));
memcpy(&priv->dino_alive, response_buffer,
sizeof(priv->dino_alive));
if (priv->dino_alive.alive_command == 1
&& priv->dino_alive.ucode_valid == 1) {
rc = 0;
IPW_DEBUG_INFO
("Microcode OK, rev. %d (0x%x) dev. %d (0x%x) "
"of %02d/%02d/%02d %02d:%02d\n",
priv->dino_alive.software_revision,
priv->dino_alive.software_revision,
priv->dino_alive.device_identifier,
priv->dino_alive.device_identifier,
priv->dino_alive.time_stamp[0],
priv->dino_alive.time_stamp[1],
priv->dino_alive.time_stamp[2],
priv->dino_alive.time_stamp[3],
priv->dino_alive.time_stamp[4]);
} else {
IPW_DEBUG_INFO("Microcode is not alive\n");
rc = -EINVAL;
}
} else {
IPW_DEBUG_INFO("No alive response from DINO\n");
rc = -ETIME;
}
ipw_write_reg8(priv, IPW_BASEBAND_CONTROL_STATUS, 0);
return rc;
}
static int ipw_load_firmware(struct ipw_priv *priv, u8 * data, size_t len)
{
int ret = -1;
int offset = 0;
struct fw_chunk *chunk;
int total_nr = 0;
int i;
struct dma_pool *pool;
void **virts;
dma_addr_t *phys;
IPW_DEBUG_TRACE("<< :\n");
virts = kmalloc(sizeof(void *) * CB_NUMBER_OF_ELEMENTS_SMALL,
GFP_KERNEL);
if (!virts)
return -ENOMEM;
phys = kmalloc(sizeof(dma_addr_t) * CB_NUMBER_OF_ELEMENTS_SMALL,
GFP_KERNEL);
if (!phys) {
kfree(virts);
return -ENOMEM;
}
pool = dma_pool_create("ipw2200", &priv->pci_dev->dev, CB_MAX_LENGTH, 0,
0);
if (!pool) {
IPW_ERROR("dma_pool_create failed\n");
kfree(phys);
kfree(virts);
return -ENOMEM;
}
ret = ipw_fw_dma_enable(priv);
BUG_ON(priv->sram_desc.last_cb_index > 0);
do {
u32 chunk_len;
u8 *start;
int size;
int nr = 0;
chunk = (struct fw_chunk *)(data + offset);
offset += sizeof(struct fw_chunk);
chunk_len = le32_to_cpu(chunk->length);
start = data + offset;
nr = (chunk_len + CB_MAX_LENGTH - 1) / CB_MAX_LENGTH;
for (i = 0; i < nr; i++) {
virts[total_nr] = dma_pool_alloc(pool, GFP_KERNEL,
&phys[total_nr]);
if (!virts[total_nr]) {
ret = -ENOMEM;
goto out;
}
size = min_t(u32, chunk_len - i * CB_MAX_LENGTH,
CB_MAX_LENGTH);
memcpy(virts[total_nr], start, size);
start += size;
total_nr++;
BUG_ON(total_nr > CB_NUMBER_OF_ELEMENTS_SMALL);
}
ret = ipw_fw_dma_add_buffer(priv, &phys[total_nr - nr],
nr, le32_to_cpu(chunk->address),
chunk_len);
if (ret) {
IPW_DEBUG_INFO("dmaAddBuffer Failed\n");
goto out;
}
offset += chunk_len;
} while (offset < len);
ret = ipw_fw_dma_kick(priv);
if (ret) {
IPW_ERROR("dmaKick Failed\n");
goto out;
}
ret = ipw_fw_dma_wait(priv);
if (ret) {
IPW_ERROR("dmaWaitSync Failed\n");
goto out;
}
out:
for (i = 0; i < total_nr; i++)
dma_pool_free(pool, virts[i], phys[i]);
dma_pool_destroy(pool);
kfree(phys);
kfree(virts);
return ret;
}
static int ipw_stop_nic(struct ipw_priv *priv)
{
int rc = 0;
ipw_write32(priv, IPW_RESET_REG, IPW_RESET_REG_STOP_MASTER);
rc = ipw_poll_bit(priv, IPW_RESET_REG,
IPW_RESET_REG_MASTER_DISABLED, 500);
if (rc < 0) {
IPW_ERROR("wait for reg master disabled failed after 500ms\n");
return rc;
}
ipw_set_bit(priv, IPW_RESET_REG, CBD_RESET_REG_PRINCETON_RESET);
return rc;
}
static void ipw_start_nic(struct ipw_priv *priv)
{
IPW_DEBUG_TRACE(">>\n");
ipw_clear_bit(priv, IPW_RESET_REG,
IPW_RESET_REG_MASTER_DISABLED |
IPW_RESET_REG_STOP_MASTER |
CBD_RESET_REG_PRINCETON_RESET);
ipw_set_bit(priv, IPW_GP_CNTRL_RW,
IPW_GP_CNTRL_BIT_HOST_ALLOWS_STANDBY);
IPW_DEBUG_TRACE("<<\n");
}
static int ipw_init_nic(struct ipw_priv *priv)
{
int rc;
IPW_DEBUG_TRACE(">>\n");
ipw_set_bit(priv, IPW_GP_CNTRL_RW, IPW_GP_CNTRL_BIT_INIT_DONE);
ipw_write32(priv, IPW_READ_INT_REGISTER,
IPW_BIT_INT_HOST_SRAM_READ_INT_REGISTER);
rc = ipw_poll_bit(priv, IPW_GP_CNTRL_RW,
IPW_GP_CNTRL_BIT_CLOCK_READY, 250);
if (rc < 0)
IPW_DEBUG_INFO("FAILED wait for clock stablization\n");
ipw_set_bit(priv, IPW_RESET_REG, IPW_RESET_REG_SW_RESET);
udelay(10);
ipw_set_bit(priv, IPW_GP_CNTRL_RW, IPW_GP_CNTRL_BIT_INIT_DONE);
IPW_DEBUG_TRACE(">>\n");
return 0;
}
static int ipw_reset_nic(struct ipw_priv *priv)
{
int rc = 0;
unsigned long flags;
IPW_DEBUG_TRACE(">>\n");
rc = ipw_init_nic(priv);
spin_lock_irqsave(&priv->lock, flags);
priv->status &= ~STATUS_HCMD_ACTIVE;
wake_up_interruptible(&priv->wait_command_queue);
priv->status &= ~(STATUS_SCANNING | STATUS_SCAN_ABORTING);
wake_up_interruptible(&priv->wait_state);
spin_unlock_irqrestore(&priv->lock, flags);
IPW_DEBUG_TRACE("<<\n");
return rc;
}
static int ipw_get_fw(struct ipw_priv *priv,
const struct firmware **raw, const char *name)
{
struct ipw_fw *fw;
int rc;
rc = request_firmware(raw, name, &priv->pci_dev->dev);
if (rc < 0) {
IPW_ERROR("%s request_firmware failed: Reason %d\n", name, rc);
return rc;
}
if ((*raw)->size < sizeof(*fw)) {
IPW_ERROR("%s is too small (%zd)\n", name, (*raw)->size);
return -EINVAL;
}
fw = (void *)(*raw)->data;
if ((*raw)->size < sizeof(*fw) + le32_to_cpu(fw->boot_size) +
le32_to_cpu(fw->ucode_size) + le32_to_cpu(fw->fw_size)) {
IPW_ERROR("%s is too small or corrupt (%zd)\n",
name, (*raw)->size);
return -EINVAL;
}
IPW_DEBUG_INFO("Read firmware '%s' image v%d.%d (%zd bytes)\n",
name,
le32_to_cpu(fw->ver) >> 16,
le32_to_cpu(fw->ver) & 0xff,
(*raw)->size - sizeof(*fw));
return 0;
}
static void ipw_rx_queue_reset(struct ipw_priv *priv,
struct ipw_rx_queue *rxq)
{
unsigned long flags;
int i;
spin_lock_irqsave(&rxq->lock, flags);
INIT_LIST_HEAD(&rxq->rx_free);
INIT_LIST_HEAD(&rxq->rx_used);
for (i = 0; i < RX_FREE_BUFFERS + RX_QUEUE_SIZE; i++) {
if (rxq->pool[i].skb != NULL) {
pci_unmap_single(priv->pci_dev, rxq->pool[i].dma_addr,
IPW_RX_BUF_SIZE, PCI_DMA_FROMDEVICE);
dev_kfree_skb(rxq->pool[i].skb);
rxq->pool[i].skb = NULL;
}
list_add_tail(&rxq->pool[i].list, &rxq->rx_used);
}
rxq->read = rxq->write = 0;
rxq->free_count = 0;
spin_unlock_irqrestore(&rxq->lock, flags);
}
static void free_firmware(void)
{
if (fw_loaded) {
release_firmware(raw);
raw = NULL;
fw_loaded = 0;
}
}
static int ipw_load(struct ipw_priv *priv)
{
#ifndef CONFIG_PM
const struct firmware *raw = NULL;
#endif
struct ipw_fw *fw;
u8 *boot_img, *ucode_img, *fw_img;
u8 *name = NULL;
int rc = 0, retries = 3;
switch (priv->ieee->iw_mode) {
case IW_MODE_ADHOC:
name = "ipw2200-ibss.fw";
break;
#ifdef CONFIG_IPW2200_MONITOR
case IW_MODE_MONITOR:
name = "ipw2200-sniffer.fw";
break;
#endif
case IW_MODE_INFRA:
name = "ipw2200-bss.fw";
break;
}
if (!name) {
rc = -EINVAL;
goto error;
}
#ifdef CONFIG_PM
if (!fw_loaded) {
#endif
rc = ipw_get_fw(priv, &raw, name);
if (rc < 0)
goto error;
#ifdef CONFIG_PM
}
#endif
fw = (void *)raw->data;
boot_img = &fw->data[0];
ucode_img = &fw->data[le32_to_cpu(fw->boot_size)];
fw_img = &fw->data[le32_to_cpu(fw->boot_size) +
le32_to_cpu(fw->ucode_size)];
if (!priv->rxq)
priv->rxq = ipw_rx_queue_alloc(priv);
else
ipw_rx_queue_reset(priv, priv->rxq);
if (!priv->rxq) {
IPW_ERROR("Unable to initialize Rx queue\n");
rc = -ENOMEM;
goto error;
}
retry:
ipw_write32(priv, IPW_INTA_MASK_R, ~IPW_INTA_MASK_ALL);
priv->status &= ~STATUS_INT_ENABLED;
ipw_write32(priv, IPW_INTA_RW, IPW_INTA_MASK_ALL);
ipw_stop_nic(priv);
rc = ipw_reset_nic(priv);
if (rc < 0) {
IPW_ERROR("Unable to reset NIC\n");
goto error;
}
ipw_zero_memory(priv, IPW_NIC_SRAM_LOWER_BOUND,
IPW_NIC_SRAM_UPPER_BOUND - IPW_NIC_SRAM_LOWER_BOUND);
rc = ipw_load_firmware(priv, boot_img, le32_to_cpu(fw->boot_size));
if (rc < 0) {
IPW_ERROR("Unable to load boot firmware: %d\n", rc);
goto error;
}
ipw_start_nic(priv);
rc = ipw_poll_bit(priv, IPW_INTA_RW,
IPW_INTA_BIT_FW_INITIALIZATION_DONE, 500);
if (rc < 0) {
IPW_ERROR("device failed to boot initial fw image\n");
goto error;
}
IPW_DEBUG_INFO("initial device response after %dms\n", rc);
ipw_write32(priv, IPW_INTA_RW, IPW_INTA_BIT_FW_INITIALIZATION_DONE);
rc = ipw_load_ucode(priv, ucode_img, le32_to_cpu(fw->ucode_size));
if (rc < 0) {
IPW_ERROR("Unable to load ucode: %d\n", rc);
goto error;
}
ipw_stop_nic(priv);
rc = ipw_load_firmware(priv, fw_img, le32_to_cpu(fw->fw_size));
if (rc < 0) {
IPW_ERROR("Unable to load firmware: %d\n", rc);
goto error;
}
#ifdef CONFIG_PM
fw_loaded = 1;
#endif
ipw_write32(priv, IPW_EEPROM_LOAD_DISABLE, 0);
rc = ipw_queue_reset(priv);
if (rc < 0) {
IPW_ERROR("Unable to initialize queues\n");
goto error;
}
ipw_write32(priv, IPW_INTA_MASK_R, ~IPW_INTA_MASK_ALL);
ipw_write32(priv, IPW_INTA_RW, IPW_INTA_MASK_ALL);
ipw_start_nic(priv);
if (ipw_read32(priv, IPW_INTA_RW) & IPW_INTA_BIT_PARITY_ERROR) {
if (retries > 0) {
IPW_WARNING("Parity error. Retrying init.\n");
retries--;
goto retry;
}
IPW_ERROR("TODO: Handle parity error -- schedule restart?\n");
rc = -EIO;
goto error;
}
rc = ipw_poll_bit(priv, IPW_INTA_RW,
IPW_INTA_BIT_FW_INITIALIZATION_DONE, 500);
if (rc < 0) {
IPW_ERROR("device failed to start within 500ms\n");
goto error;
}
IPW_DEBUG_INFO("device response after %dms\n", rc);
ipw_write32(priv, IPW_INTA_RW, IPW_INTA_BIT_FW_INITIALIZATION_DONE);
priv->eeprom_delay = 1;
ipw_read_eeprom(priv);
ipw_eeprom_init_sram(priv);
ipw_enable_interrupts(priv);
ipw_rx_queue_replenish(priv);
ipw_write32(priv, IPW_RX_READ_INDEX, priv->rxq->read);
ipw_write32(priv, IPW_INTA_RW, IPW_INTA_MASK_ALL);
#ifndef CONFIG_PM
release_firmware(raw);
#endif
return 0;
error:
if (priv->rxq) {
ipw_rx_queue_free(priv, priv->rxq);
priv->rxq = NULL;
}
ipw_tx_queue_free(priv);
release_firmware(raw);
#ifdef CONFIG_PM
fw_loaded = 0;
raw = NULL;
#endif
return rc;
}
static int ipw_rx_queue_space(const struct ipw_rx_queue *q)
{
int s = q->read - q->write;
if (s <= 0)
s += RX_QUEUE_SIZE;
s -= 2;
if (s < 0)
s = 0;
return s;
}
static inline int ipw_tx_queue_space(const struct clx2_queue *q)
{
int s = q->last_used - q->first_empty;
if (s <= 0)
s += q->n_bd;
s -= 2;
if (s < 0)
s = 0;
return s;
}
static inline int ipw_queue_inc_wrap(int index, int n_bd)
{
return (++index == n_bd) ? 0 : index;
}
static void ipw_queue_init(struct ipw_priv *priv, struct clx2_queue *q,
int count, u32 read, u32 write, u32 base, u32 size)
{
q->n_bd = count;
q->low_mark = q->n_bd / 4;
if (q->low_mark < 4)
q->low_mark = 4;
q->high_mark = q->n_bd / 8;
if (q->high_mark < 2)
q->high_mark = 2;
q->first_empty = q->last_used = 0;
q->reg_r = read;
q->reg_w = write;
ipw_write32(priv, base, q->dma_addr);
ipw_write32(priv, size, count);
ipw_write32(priv, read, 0);
ipw_write32(priv, write, 0);
_ipw_read32(priv, 0x90);
}
static int ipw_queue_tx_init(struct ipw_priv *priv,
struct clx2_tx_queue *q,
int count, u32 read, u32 write, u32 base, u32 size)
{
struct pci_dev *dev = priv->pci_dev;
q->txb = kmalloc(sizeof(q->txb[0]) * count, GFP_KERNEL);
if (!q->txb) {
IPW_ERROR("vmalloc for auxiliary BD structures failed\n");
return -ENOMEM;
}
q->bd =
pci_alloc_consistent(dev, sizeof(q->bd[0]) * count, &q->q.dma_addr);
if (!q->bd) {
IPW_ERROR("pci_alloc_consistent(%zd) failed\n",
sizeof(q->bd[0]) * count);
kfree(q->txb);
q->txb = NULL;
return -ENOMEM;
}
ipw_queue_init(priv, &q->q, count, read, write, base, size);
return 0;
}
static void ipw_queue_tx_free_tfd(struct ipw_priv *priv,
struct clx2_tx_queue *txq)
{
struct tfd_frame *bd = &txq->bd[txq->q.last_used];
struct pci_dev *dev = priv->pci_dev;
int i;
if (bd->control_flags.message_type == TX_HOST_COMMAND_TYPE)
return;
if (le32_to_cpu(bd->u.data.num_chunks) > NUM_TFD_CHUNKS) {
IPW_ERROR("Too many chunks: %i\n",
le32_to_cpu(bd->u.data.num_chunks));
return;
}
for (i = 0; i < le32_to_cpu(bd->u.data.num_chunks); i++) {
pci_unmap_single(dev, le32_to_cpu(bd->u.data.chunk_ptr[i]),
le16_to_cpu(bd->u.data.chunk_len[i]),
PCI_DMA_TODEVICE);
if (txq->txb[txq->q.last_used]) {
libipw_txb_free(txq->txb[txq->q.last_used]);
txq->txb[txq->q.last_used] = NULL;
}
}
}
static void ipw_queue_tx_free(struct ipw_priv *priv, struct clx2_tx_queue *txq)
{
struct clx2_queue *q = &txq->q;
struct pci_dev *dev = priv->pci_dev;
if (q->n_bd == 0)
return;
for (; q->first_empty != q->last_used;
q->last_used = ipw_queue_inc_wrap(q->last_used, q->n_bd)) {
ipw_queue_tx_free_tfd(priv, txq);
}
pci_free_consistent(dev, sizeof(txq->bd[0]) * q->n_bd, txq->bd,
q->dma_addr);
kfree(txq->txb);
memset(txq, 0, sizeof(*txq));
}
static void ipw_tx_queue_free(struct ipw_priv *priv)
{
ipw_queue_tx_free(priv, &priv->txq_cmd);
ipw_queue_tx_free(priv, &priv->txq[0]);
ipw_queue_tx_free(priv, &priv->txq[1]);
ipw_queue_tx_free(priv, &priv->txq[2]);
ipw_queue_tx_free(priv, &priv->txq[3]);
}
static void ipw_create_bssid(struct ipw_priv *priv, u8 * bssid)
{
bssid[0] = priv->mac_addr[0];
bssid[1] = priv->mac_addr[1];
bssid[2] = priv->mac_addr[2];
get_random_bytes(&bssid[3], ETH_ALEN - 3);
bssid[0] &= 0xfe;
bssid[0] |= 0x02;
}
static u8 ipw_add_station(struct ipw_priv *priv, u8 * bssid)
{
struct ipw_station_entry entry;
int i;
for (i = 0; i < priv->num_stations; i++) {
if (ether_addr_equal(priv->stations[i], bssid)) {
priv->missed_adhoc_beacons = 0;
if (!(priv->config & CFG_STATIC_CHANNEL))
priv->config &= ~CFG_ADHOC_PERSIST;
return i;
}
}
if (i == MAX_STATIONS)
return IPW_INVALID_STATION;
IPW_DEBUG_SCAN("Adding AdHoc station: %pM\n", bssid);
entry.reserved = 0;
entry.support_mode = 0;
memcpy(entry.mac_addr, bssid, ETH_ALEN);
memcpy(priv->stations[i], bssid, ETH_ALEN);
ipw_write_direct(priv, IPW_STATION_TABLE_LOWER + i * sizeof(entry),
&entry, sizeof(entry));
priv->num_stations++;
return i;
}
static u8 ipw_find_station(struct ipw_priv *priv, u8 * bssid)
{
int i;
for (i = 0; i < priv->num_stations; i++)
if (ether_addr_equal(priv->stations[i], bssid))
return i;
return IPW_INVALID_STATION;
}
static void ipw_send_disassociate(struct ipw_priv *priv, int quiet)
{
int err;
if (priv->status & STATUS_ASSOCIATING) {
IPW_DEBUG_ASSOC("Disassociating while associating.\n");
schedule_work(&priv->disassociate);
return;
}
if (!(priv->status & STATUS_ASSOCIATED)) {
IPW_DEBUG_ASSOC("Disassociating while not associated.\n");
return;
}
IPW_DEBUG_ASSOC("Disassociation attempt from %pM "
"on channel %d.\n",
priv->assoc_request.bssid,
priv->assoc_request.channel);
priv->status &= ~(STATUS_ASSOCIATING | STATUS_ASSOCIATED);
priv->status |= STATUS_DISASSOCIATING;
if (quiet)
priv->assoc_request.assoc_type = HC_DISASSOC_QUIET;
else
priv->assoc_request.assoc_type = HC_DISASSOCIATE;
err = ipw_send_associate(priv, &priv->assoc_request);
if (err) {
IPW_DEBUG_HC("Attempt to send [dis]associate command "
"failed.\n");
return;
}
}
static int ipw_disassociate(void *data)
{
struct ipw_priv *priv = data;
if (!(priv->status & (STATUS_ASSOCIATED | STATUS_ASSOCIATING)))
return 0;
ipw_send_disassociate(data, 0);
netif_carrier_off(priv->net_dev);
return 1;
}
static void ipw_bg_disassociate(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, disassociate);
mutex_lock(&priv->mutex);
ipw_disassociate(priv);
mutex_unlock(&priv->mutex);
}
static void ipw_system_config(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, system_config);
#ifdef CONFIG_IPW2200_PROMISCUOUS
if (priv->prom_net_dev && netif_running(priv->prom_net_dev)) {
priv->sys_config.accept_all_data_frames = 1;
priv->sys_config.accept_non_directed_frames = 1;
priv->sys_config.accept_all_mgmt_bcpr = 1;
priv->sys_config.accept_all_mgmt_frames = 1;
}
#endif
ipw_send_system_config(priv);
}
static const char *ipw_get_status_code(u16 status)
{
int i;
for (i = 0; i < ARRAY_SIZE(ipw_status_codes); i++)
if (ipw_status_codes[i].status == (status & 0xff))
return ipw_status_codes[i].reason;
return "Unknown status value.";
}
static inline void average_init(struct average *avg)
{
memset(avg, 0, sizeof(*avg));
}
static s16 exponential_average(s16 prev_avg, s16 val, u8 depth)
{
return ((depth-1)*prev_avg + val)/depth;
}
static void average_add(struct average *avg, s16 val)
{
avg->sum -= avg->entries[avg->pos];
avg->sum += val;
avg->entries[avg->pos++] = val;
if (unlikely(avg->pos == AVG_ENTRIES)) {
avg->init = 1;
avg->pos = 0;
}
}
static s16 average_value(struct average *avg)
{
if (!unlikely(avg->init)) {
if (avg->pos)
return avg->sum / avg->pos;
return 0;
}
return avg->sum / AVG_ENTRIES;
}
static void ipw_reset_stats(struct ipw_priv *priv)
{
u32 len = sizeof(u32);
priv->quality = 0;
average_init(&priv->average_missed_beacons);
priv->exp_avg_rssi = -60;
priv->exp_avg_noise = -85 + 0x100;
priv->last_rate = 0;
priv->last_missed_beacons = 0;
priv->last_rx_packets = 0;
priv->last_tx_packets = 0;
priv->last_tx_failures = 0;
ipw_get_ordinal(priv, IPW_ORD_STAT_RX_ERR_CRC,
&priv->last_rx_err, &len);
ipw_get_ordinal(priv, IPW_ORD_STAT_TX_FAILURE,
&priv->last_tx_failures, &len);
priv->missed_adhoc_beacons = 0;
priv->missed_beacons = 0;
priv->tx_packets = 0;
priv->rx_packets = 0;
}
static u32 ipw_get_max_rate(struct ipw_priv *priv)
{
u32 i = 0x80000000;
u32 mask = priv->rates_mask;
if (priv->assoc_request.ieee_mode == IPW_B_MODE)
mask &= LIBIPW_CCK_RATES_MASK;
while (i && !(mask & i))
i >>= 1;
switch (i) {
case LIBIPW_CCK_RATE_1MB_MASK:
return 1000000;
case LIBIPW_CCK_RATE_2MB_MASK:
return 2000000;
case LIBIPW_CCK_RATE_5MB_MASK:
return 5500000;
case LIBIPW_OFDM_RATE_6MB_MASK:
return 6000000;
case LIBIPW_OFDM_RATE_9MB_MASK:
return 9000000;
case LIBIPW_CCK_RATE_11MB_MASK:
return 11000000;
case LIBIPW_OFDM_RATE_12MB_MASK:
return 12000000;
case LIBIPW_OFDM_RATE_18MB_MASK:
return 18000000;
case LIBIPW_OFDM_RATE_24MB_MASK:
return 24000000;
case LIBIPW_OFDM_RATE_36MB_MASK:
return 36000000;
case LIBIPW_OFDM_RATE_48MB_MASK:
return 48000000;
case LIBIPW_OFDM_RATE_54MB_MASK:
return 54000000;
}
if (priv->ieee->mode == IEEE_B)
return 11000000;
else
return 54000000;
}
static u32 ipw_get_current_rate(struct ipw_priv *priv)
{
u32 rate, len = sizeof(rate);
int err;
if (!(priv->status & STATUS_ASSOCIATED))
return 0;
if (priv->tx_packets > IPW_REAL_RATE_RX_PACKET_THRESHOLD) {
err = ipw_get_ordinal(priv, IPW_ORD_STAT_TX_CURR_RATE, &rate,
&len);
if (err) {
IPW_DEBUG_INFO("failed querying ordinals.\n");
return 0;
}
} else
return ipw_get_max_rate(priv);
switch (rate) {
case IPW_TX_RATE_1MB:
return 1000000;
case IPW_TX_RATE_2MB:
return 2000000;
case IPW_TX_RATE_5MB:
return 5500000;
case IPW_TX_RATE_6MB:
return 6000000;
case IPW_TX_RATE_9MB:
return 9000000;
case IPW_TX_RATE_11MB:
return 11000000;
case IPW_TX_RATE_12MB:
return 12000000;
case IPW_TX_RATE_18MB:
return 18000000;
case IPW_TX_RATE_24MB:
return 24000000;
case IPW_TX_RATE_36MB:
return 36000000;
case IPW_TX_RATE_48MB:
return 48000000;
case IPW_TX_RATE_54MB:
return 54000000;
}
return 0;
}
static void ipw_gather_stats(struct ipw_priv *priv)
{
u32 rx_err, rx_err_delta, rx_packets_delta;
u32 tx_failures, tx_failures_delta, tx_packets_delta;
u32 missed_beacons_percent, missed_beacons_delta;
u32 quality = 0;
u32 len = sizeof(u32);
s16 rssi;
u32 beacon_quality, signal_quality, tx_quality, rx_quality,
rate_quality;
u32 max_rate;
if (!(priv->status & STATUS_ASSOCIATED)) {
priv->quality = 0;
return;
}
ipw_get_ordinal(priv, IPW_ORD_STAT_MISSED_BEACONS,
&priv->missed_beacons, &len);
missed_beacons_delta = priv->missed_beacons - priv->last_missed_beacons;
priv->last_missed_beacons = priv->missed_beacons;
if (priv->assoc_request.beacon_interval) {
missed_beacons_percent = missed_beacons_delta *
(HZ * le16_to_cpu(priv->assoc_request.beacon_interval)) /
(IPW_STATS_INTERVAL * 10);
} else {
missed_beacons_percent = 0;
}
average_add(&priv->average_missed_beacons, missed_beacons_percent);
ipw_get_ordinal(priv, IPW_ORD_STAT_RX_ERR_CRC, &rx_err, &len);
rx_err_delta = rx_err - priv->last_rx_err;
priv->last_rx_err = rx_err;
ipw_get_ordinal(priv, IPW_ORD_STAT_TX_FAILURE, &tx_failures, &len);
tx_failures_delta = tx_failures - priv->last_tx_failures;
priv->last_tx_failures = tx_failures;
rx_packets_delta = priv->rx_packets - priv->last_rx_packets;
priv->last_rx_packets = priv->rx_packets;
tx_packets_delta = priv->tx_packets - priv->last_tx_packets;
priv->last_tx_packets = priv->tx_packets;
#define BEACON_THRESHOLD 5
beacon_quality = 100 - missed_beacons_percent;
if (beacon_quality < BEACON_THRESHOLD)
beacon_quality = 0;
else
beacon_quality = (beacon_quality - BEACON_THRESHOLD) * 100 /
(100 - BEACON_THRESHOLD);
IPW_DEBUG_STATS("Missed beacon: %3d%% (%d%%)\n",
beacon_quality, missed_beacons_percent);
priv->last_rate = ipw_get_current_rate(priv);
max_rate = ipw_get_max_rate(priv);
rate_quality = priv->last_rate * 40 / max_rate + 60;
IPW_DEBUG_STATS("Rate quality : %3d%% (%dMbs)\n",
rate_quality, priv->last_rate / 1000000);
if (rx_packets_delta > 100 && rx_packets_delta + rx_err_delta)
rx_quality = 100 - (rx_err_delta * 100) /
(rx_packets_delta + rx_err_delta);
else
rx_quality = 100;
IPW_DEBUG_STATS("Rx quality : %3d%% (%u errors, %u packets)\n",
rx_quality, rx_err_delta, rx_packets_delta);
if (tx_packets_delta > 100 && tx_packets_delta + tx_failures_delta)
tx_quality = 100 - (tx_failures_delta * 100) /
(tx_packets_delta + tx_failures_delta);
else
tx_quality = 100;
IPW_DEBUG_STATS("Tx quality : %3d%% (%u errors, %u packets)\n",
tx_quality, tx_failures_delta, tx_packets_delta);
rssi = priv->exp_avg_rssi;
signal_quality =
(100 *
(priv->ieee->perfect_rssi - priv->ieee->worst_rssi) *
(priv->ieee->perfect_rssi - priv->ieee->worst_rssi) -
(priv->ieee->perfect_rssi - rssi) *
(15 * (priv->ieee->perfect_rssi - priv->ieee->worst_rssi) +
62 * (priv->ieee->perfect_rssi - rssi))) /
((priv->ieee->perfect_rssi - priv->ieee->worst_rssi) *
(priv->ieee->perfect_rssi - priv->ieee->worst_rssi));
if (signal_quality > 100)
signal_quality = 100;
else if (signal_quality < 1)
signal_quality = 0;
IPW_DEBUG_STATS("Signal level : %3d%% (%d dBm)\n",
signal_quality, rssi);
quality = min(rx_quality, signal_quality);
quality = min(tx_quality, quality);
quality = min(rate_quality, quality);
quality = min(beacon_quality, quality);
if (quality == beacon_quality)
IPW_DEBUG_STATS("Quality (%d%%): Clamped to missed beacons.\n",
quality);
if (quality == rate_quality)
IPW_DEBUG_STATS("Quality (%d%%): Clamped to rate quality.\n",
quality);
if (quality == tx_quality)
IPW_DEBUG_STATS("Quality (%d%%): Clamped to Tx quality.\n",
quality);
if (quality == rx_quality)
IPW_DEBUG_STATS("Quality (%d%%): Clamped to Rx quality.\n",
quality);
if (quality == signal_quality)
IPW_DEBUG_STATS("Quality (%d%%): Clamped to signal quality.\n",
quality);
priv->quality = quality;
schedule_delayed_work(&priv->gather_stats, IPW_STATS_INTERVAL);
}
static void ipw_bg_gather_stats(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, gather_stats.work);
mutex_lock(&priv->mutex);
ipw_gather_stats(priv);
mutex_unlock(&priv->mutex);
}
static void ipw_handle_missed_beacon(struct ipw_priv *priv,
int missed_count)
{
priv->notif_missed_beacons = missed_count;
if (missed_count > priv->disassociate_threshold &&
priv->status & STATUS_ASSOCIATED) {
IPW_DEBUG(IPW_DL_INFO | IPW_DL_NOTIF |
IPW_DL_STATE | IPW_DL_ASSOC,
"Missed beacon: %d - disassociate\n", missed_count);
priv->status &= ~STATUS_ROAMING;
if (priv->status & STATUS_SCANNING) {
IPW_DEBUG(IPW_DL_INFO | IPW_DL_NOTIF |
IPW_DL_STATE,
"Aborting scan with missed beacon.\n");
schedule_work(&priv->abort_scan);
}
schedule_work(&priv->disassociate);
return;
}
if (priv->status & STATUS_ROAMING) {
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE,
"Missed beacon: %d - roam in progress\n",
missed_count);
return;
}
if (roaming &&
(missed_count > priv->roaming_threshold &&
missed_count <= priv->disassociate_threshold)) {
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE,
"Missed beacon: %d - initiate "
"roaming\n", missed_count);
if (!(priv->status & STATUS_ROAMING)) {
priv->status |= STATUS_ROAMING;
if (!(priv->status & STATUS_SCANNING))
schedule_delayed_work(&priv->request_scan, 0);
}
return;
}
if (priv->status & STATUS_SCANNING &&
missed_count > IPW_MB_SCAN_CANCEL_THRESHOLD) {
IPW_DEBUG(IPW_DL_INFO | IPW_DL_NOTIF | IPW_DL_STATE,
"Aborting scan with missed beacon.\n");
schedule_work(&priv->abort_scan);
}
IPW_DEBUG_NOTIF("Missed beacon: %d\n", missed_count);
}
static void ipw_scan_event(struct work_struct *work)
{
union iwreq_data wrqu;
struct ipw_priv *priv =
container_of(work, struct ipw_priv, scan_event.work);
wrqu.data.length = 0;
wrqu.data.flags = 0;
wireless_send_event(priv->net_dev, SIOCGIWSCAN, &wrqu, NULL);
}
static void handle_scan_event(struct ipw_priv *priv)
{
if (!priv->user_requested_scan) {
schedule_delayed_work(&priv->scan_event,
round_jiffies_relative(msecs_to_jiffies(4000)));
} else {
priv->user_requested_scan = 0;
mod_delayed_work(system_wq, &priv->scan_event, 0);
}
}
static void ipw_rx_notification(struct ipw_priv *priv,
struct ipw_rx_notification *notif)
{
u16 size = le16_to_cpu(notif->size);
IPW_DEBUG_NOTIF("type = %i (%d bytes)\n", notif->subtype, size);
switch (notif->subtype) {
case HOST_NOTIFICATION_STATUS_ASSOCIATED:{
struct notif_association *assoc = &notif->u.assoc;
switch (assoc->state) {
case CMAS_ASSOCIATED:{
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC,
"associated: '%*pE' %pM\n",
priv->essid_len, priv->essid,
priv->bssid);
switch (priv->ieee->iw_mode) {
case IW_MODE_INFRA:
memcpy(priv->ieee->bssid,
priv->bssid, ETH_ALEN);
break;
case IW_MODE_ADHOC:
memcpy(priv->ieee->bssid,
priv->bssid, ETH_ALEN);
priv->num_stations = 0;
IPW_DEBUG_ASSOC
("queueing adhoc check\n");
schedule_delayed_work(
&priv->adhoc_check,
le16_to_cpu(priv->
assoc_request.
beacon_interval));
break;
}
priv->status &= ~STATUS_ASSOCIATING;
priv->status |= STATUS_ASSOCIATED;
schedule_work(&priv->system_config);
#ifdef CONFIG_IPW2200_QOS
#define IPW_GET_PACKET_STYPE(x) WLAN_FC_GET_STYPE( \
le16_to_cpu(((struct ieee80211_hdr *)(x))->frame_control))
if ((priv->status & STATUS_AUTH) &&
(IPW_GET_PACKET_STYPE(&notif->u.raw)
== IEEE80211_STYPE_ASSOC_RESP)) {
if ((sizeof
(struct
libipw_assoc_response)
<= size)
&& (size <= 2314)) {
struct
libipw_rx_stats
stats = {
.len = size - 1,
};
IPW_DEBUG_QOS
("QoS Associate "
"size %d\n", size);
libipw_rx_mgt(priv->
ieee,
(struct
libipw_hdr_4addr
*)
&notif->u.raw, &stats);
}
}
#endif
schedule_work(&priv->link_up);
break;
}
case CMAS_AUTHENTICATED:{
if (priv->
status & (STATUS_ASSOCIATED |
STATUS_AUTH)) {
struct notif_authenticate *auth
= &notif->u.auth;
IPW_DEBUG(IPW_DL_NOTIF |
IPW_DL_STATE |
IPW_DL_ASSOC,
"deauthenticated: '%*pE' %pM: (0x%04X) - %s\n",
priv->essid_len,
priv->essid,
priv->bssid,
le16_to_cpu(auth->status),
ipw_get_status_code
(le16_to_cpu
(auth->status)));
priv->status &=
~(STATUS_ASSOCIATING |
STATUS_AUTH |
STATUS_ASSOCIATED);
schedule_work(&priv->link_down);
break;
}
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC,
"authenticated: '%*pE' %pM\n",
priv->essid_len, priv->essid,
priv->bssid);
break;
}
case CMAS_INIT:{
if (priv->status & STATUS_AUTH) {
struct
libipw_assoc_response
*resp;
resp =
(struct
libipw_assoc_response
*)&notif->u.raw;
IPW_DEBUG(IPW_DL_NOTIF |
IPW_DL_STATE |
IPW_DL_ASSOC,
"association failed (0x%04X): %s\n",
le16_to_cpu(resp->status),
ipw_get_status_code
(le16_to_cpu
(resp->status)));
}
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC,
"disassociated: '%*pE' %pM\n",
priv->essid_len, priv->essid,
priv->bssid);
priv->status &=
~(STATUS_DISASSOCIATING |
STATUS_ASSOCIATING |
STATUS_ASSOCIATED | STATUS_AUTH);
if (priv->assoc_network
&& (priv->assoc_network->
capability &
WLAN_CAPABILITY_IBSS))
ipw_remove_current_network
(priv);
schedule_work(&priv->link_down);
break;
}
case CMAS_RX_ASSOC_RESP:
break;
default:
IPW_ERROR("assoc: unknown (%d)\n",
assoc->state);
break;
}
break;
}
case HOST_NOTIFICATION_STATUS_AUTHENTICATE:{
struct notif_authenticate *auth = &notif->u.auth;
switch (auth->state) {
case CMAS_AUTHENTICATED:
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE,
"authenticated: '%*pE' %pM\n",
priv->essid_len, priv->essid,
priv->bssid);
priv->status |= STATUS_AUTH;
break;
case CMAS_INIT:
if (priv->status & STATUS_AUTH) {
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC,
"authentication failed (0x%04X): %s\n",
le16_to_cpu(auth->status),
ipw_get_status_code(le16_to_cpu
(auth->
status)));
}
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC,
"deauthenticated: '%*pE' %pM\n",
priv->essid_len, priv->essid,
priv->bssid);
priv->status &= ~(STATUS_ASSOCIATING |
STATUS_AUTH |
STATUS_ASSOCIATED);
schedule_work(&priv->link_down);
break;
case CMAS_TX_AUTH_SEQ_1:
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC, "AUTH_SEQ_1\n");
break;
case CMAS_RX_AUTH_SEQ_2:
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC, "AUTH_SEQ_2\n");
break;
case CMAS_AUTH_SEQ_1_PASS:
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC, "AUTH_SEQ_1_PASS\n");
break;
case CMAS_AUTH_SEQ_1_FAIL:
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC, "AUTH_SEQ_1_FAIL\n");
break;
case CMAS_TX_AUTH_SEQ_3:
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC, "AUTH_SEQ_3\n");
break;
case CMAS_RX_AUTH_SEQ_4:
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC, "RX_AUTH_SEQ_4\n");
break;
case CMAS_AUTH_SEQ_2_PASS:
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC, "AUTH_SEQ_2_PASS\n");
break;
case CMAS_AUTH_SEQ_2_FAIL:
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC, "AUT_SEQ_2_FAIL\n");
break;
case CMAS_TX_ASSOC:
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC, "TX_ASSOC\n");
break;
case CMAS_RX_ASSOC_RESP:
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC, "RX_ASSOC_RESP\n");
break;
case CMAS_ASSOCIATED:
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE |
IPW_DL_ASSOC, "ASSOCIATED\n");
break;
default:
IPW_DEBUG_NOTIF("auth: failure - %d\n",
auth->state);
break;
}
break;
}
case HOST_NOTIFICATION_STATUS_SCAN_CHANNEL_RESULT:{
struct notif_channel_result *x =
&notif->u.channel_result;
if (size == sizeof(*x)) {
IPW_DEBUG_SCAN("Scan result for channel %d\n",
x->channel_num);
} else {
IPW_DEBUG_SCAN("Scan result of wrong size %d "
"(should be %zd)\n",
size, sizeof(*x));
}
break;
}
case HOST_NOTIFICATION_STATUS_SCAN_COMPLETED:{
struct notif_scan_complete *x = &notif->u.scan_complete;
if (size == sizeof(*x)) {
IPW_DEBUG_SCAN
("Scan completed: type %d, %d channels, "
"%d status\n", x->scan_type,
x->num_channels, x->status);
} else {
IPW_ERROR("Scan completed of wrong size %d "
"(should be %zd)\n",
size, sizeof(*x));
}
priv->status &=
~(STATUS_SCANNING | STATUS_SCAN_ABORTING);
wake_up_interruptible(&priv->wait_state);
cancel_delayed_work(&priv->scan_check);
if (priv->status & STATUS_EXIT_PENDING)
break;
priv->ieee->scans++;
#ifdef CONFIG_IPW2200_MONITOR
if (priv->ieee->iw_mode == IW_MODE_MONITOR) {
priv->status |= STATUS_SCAN_FORCED;
schedule_delayed_work(&priv->request_scan, 0);
break;
}
priv->status &= ~STATUS_SCAN_FORCED;
#endif
if (priv->status & STATUS_DIRECT_SCAN_PENDING)
schedule_delayed_work(&priv->request_direct_scan, 0);
if (!(priv->status & (STATUS_ASSOCIATED |
STATUS_ASSOCIATING |
STATUS_ROAMING |
STATUS_DISASSOCIATING)))
schedule_work(&priv->associate);
else if (priv->status & STATUS_ROAMING) {
if (x->status == SCAN_COMPLETED_STATUS_COMPLETE)
schedule_work(&priv->roam);
else
priv->status &= ~STATUS_ROAMING;
} else if (priv->status & STATUS_SCAN_PENDING)
schedule_delayed_work(&priv->request_scan, 0);
else if (priv->config & CFG_BACKGROUND_SCAN
&& priv->status & STATUS_ASSOCIATED)
schedule_delayed_work(&priv->request_scan,
round_jiffies_relative(HZ));
if (x->status == SCAN_COMPLETED_STATUS_COMPLETE)
handle_scan_event(priv);
break;
}
case HOST_NOTIFICATION_STATUS_FRAG_LENGTH:{
struct notif_frag_length *x = &notif->u.frag_len;
if (size == sizeof(*x))
IPW_ERROR("Frag length: %d\n",
le16_to_cpu(x->frag_length));
else
IPW_ERROR("Frag length of wrong size %d "
"(should be %zd)\n",
size, sizeof(*x));
break;
}
case HOST_NOTIFICATION_STATUS_LINK_DETERIORATION:{
struct notif_link_deterioration *x =
&notif->u.link_deterioration;
if (size == sizeof(*x)) {
IPW_DEBUG(IPW_DL_NOTIF | IPW_DL_STATE,
"link deterioration: type %d, cnt %d\n",
x->silence_notification_type,
x->silence_count);
memcpy(&priv->last_link_deterioration, x,
sizeof(*x));
} else {
IPW_ERROR("Link Deterioration of wrong size %d "
"(should be %zd)\n",
size, sizeof(*x));
}
break;
}
case HOST_NOTIFICATION_DINO_CONFIG_RESPONSE:{
IPW_ERROR("Dino config\n");
if (priv->hcmd
&& priv->hcmd->cmd != HOST_CMD_DINO_CONFIG)
IPW_ERROR("Unexpected DINO_CONFIG_RESPONSE\n");
break;
}
case HOST_NOTIFICATION_STATUS_BEACON_STATE:{
struct notif_beacon_state *x = &notif->u.beacon_state;
if (size != sizeof(*x)) {
IPW_ERROR
("Beacon state of wrong size %d (should "
"be %zd)\n", size, sizeof(*x));
break;
}
if (le32_to_cpu(x->state) ==
HOST_NOTIFICATION_STATUS_BEACON_MISSING)
ipw_handle_missed_beacon(priv,
le32_to_cpu(x->
number));
break;
}
case HOST_NOTIFICATION_STATUS_TGI_TX_KEY:{
struct notif_tgi_tx_key *x = &notif->u.tgi_tx_key;
if (size == sizeof(*x)) {
IPW_ERROR("TGi Tx Key: state 0x%02x sec type "
"0x%02x station %d\n",
x->key_state, x->security_type,
x->station_index);
break;
}
IPW_ERROR
("TGi Tx Key of wrong size %d (should be %zd)\n",
size, sizeof(*x));
break;
}
case HOST_NOTIFICATION_CALIB_KEEP_RESULTS:{
struct notif_calibration *x = &notif->u.calibration;
if (size == sizeof(*x)) {
memcpy(&priv->calib, x, sizeof(*x));
IPW_DEBUG_INFO("TODO: Calibration\n");
break;
}
IPW_ERROR
("Calibration of wrong size %d (should be %zd)\n",
size, sizeof(*x));
break;
}
case HOST_NOTIFICATION_NOISE_STATS:{
if (size == sizeof(u32)) {
priv->exp_avg_noise =
exponential_average(priv->exp_avg_noise,
(u8) (le32_to_cpu(notif->u.noise.value) & 0xff),
DEPTH_NOISE);
break;
}
IPW_ERROR
("Noise stat is wrong size %d (should be %zd)\n",
size, sizeof(u32));
break;
}
default:
IPW_DEBUG_NOTIF("Unknown notification: "
"subtype=%d,flags=0x%2x,size=%d\n",
notif->subtype, notif->flags, size);
}
}
static int ipw_queue_reset(struct ipw_priv *priv)
{
int rc = 0;
int nTx = 64, nTxCmd = 8;
ipw_tx_queue_free(priv);
rc = ipw_queue_tx_init(priv, &priv->txq_cmd, nTxCmd,
IPW_TX_CMD_QUEUE_READ_INDEX,
IPW_TX_CMD_QUEUE_WRITE_INDEX,
IPW_TX_CMD_QUEUE_BD_BASE,
IPW_TX_CMD_QUEUE_BD_SIZE);
if (rc) {
IPW_ERROR("Tx Cmd queue init failed\n");
goto error;
}
rc = ipw_queue_tx_init(priv, &priv->txq[0], nTx,
IPW_TX_QUEUE_0_READ_INDEX,
IPW_TX_QUEUE_0_WRITE_INDEX,
IPW_TX_QUEUE_0_BD_BASE, IPW_TX_QUEUE_0_BD_SIZE);
if (rc) {
IPW_ERROR("Tx 0 queue init failed\n");
goto error;
}
rc = ipw_queue_tx_init(priv, &priv->txq[1], nTx,
IPW_TX_QUEUE_1_READ_INDEX,
IPW_TX_QUEUE_1_WRITE_INDEX,
IPW_TX_QUEUE_1_BD_BASE, IPW_TX_QUEUE_1_BD_SIZE);
if (rc) {
IPW_ERROR("Tx 1 queue init failed\n");
goto error;
}
rc = ipw_queue_tx_init(priv, &priv->txq[2], nTx,
IPW_TX_QUEUE_2_READ_INDEX,
IPW_TX_QUEUE_2_WRITE_INDEX,
IPW_TX_QUEUE_2_BD_BASE, IPW_TX_QUEUE_2_BD_SIZE);
if (rc) {
IPW_ERROR("Tx 2 queue init failed\n");
goto error;
}
rc = ipw_queue_tx_init(priv, &priv->txq[3], nTx,
IPW_TX_QUEUE_3_READ_INDEX,
IPW_TX_QUEUE_3_WRITE_INDEX,
IPW_TX_QUEUE_3_BD_BASE, IPW_TX_QUEUE_3_BD_SIZE);
if (rc) {
IPW_ERROR("Tx 3 queue init failed\n");
goto error;
}
priv->rx_bufs_min = 0;
priv->rx_pend_max = 0;
return rc;
error:
ipw_tx_queue_free(priv);
return rc;
}
static int ipw_queue_tx_reclaim(struct ipw_priv *priv,
struct clx2_tx_queue *txq, int qindex)
{
u32 hw_tail;
int used;
struct clx2_queue *q = &txq->q;
hw_tail = ipw_read32(priv, q->reg_r);
if (hw_tail >= q->n_bd) {
IPW_ERROR
("Read index for DMA queue (%d) is out of range [0-%d)\n",
hw_tail, q->n_bd);
goto done;
}
for (; q->last_used != hw_tail;
q->last_used = ipw_queue_inc_wrap(q->last_used, q->n_bd)) {
ipw_queue_tx_free_tfd(priv, txq);
priv->tx_packets++;
}
done:
if ((ipw_tx_queue_space(q) > q->low_mark) &&
(qindex >= 0))
netif_wake_queue(priv->net_dev);
used = q->first_empty - q->last_used;
if (used < 0)
used += q->n_bd;
return used;
}
static int ipw_queue_tx_hcmd(struct ipw_priv *priv, int hcmd, void *buf,
int len, int sync)
{
struct clx2_tx_queue *txq = &priv->txq_cmd;
struct clx2_queue *q = &txq->q;
struct tfd_frame *tfd;
if (ipw_tx_queue_space(q) < (sync ? 1 : 2)) {
IPW_ERROR("No space for Tx\n");
return -EBUSY;
}
tfd = &txq->bd[q->first_empty];
txq->txb[q->first_empty] = NULL;
memset(tfd, 0, sizeof(*tfd));
tfd->control_flags.message_type = TX_HOST_COMMAND_TYPE;
tfd->control_flags.control_bits = TFD_NEED_IRQ_MASK;
priv->hcmd_seq++;
tfd->u.cmd.index = hcmd;
tfd->u.cmd.length = len;
memcpy(tfd->u.cmd.payload, buf, len);
q->first_empty = ipw_queue_inc_wrap(q->first_empty, q->n_bd);
ipw_write32(priv, q->reg_w, q->first_empty);
_ipw_read32(priv, 0x90);
return 0;
}
static void ipw_rx_queue_restock(struct ipw_priv *priv)
{
struct ipw_rx_queue *rxq = priv->rxq;
struct list_head *element;
struct ipw_rx_mem_buffer *rxb;
unsigned long flags;
int write;
spin_lock_irqsave(&rxq->lock, flags);
write = rxq->write;
while ((ipw_rx_queue_space(rxq) > 0) && (rxq->free_count)) {
element = rxq->rx_free.next;
rxb = list_entry(element, struct ipw_rx_mem_buffer, list);
list_del(element);
ipw_write32(priv, IPW_RFDS_TABLE_LOWER + rxq->write * RFD_SIZE,
rxb->dma_addr);
rxq->queue[rxq->write] = rxb;
rxq->write = (rxq->write + 1) % RX_QUEUE_SIZE;
rxq->free_count--;
}
spin_unlock_irqrestore(&rxq->lock, flags);
if (rxq->free_count <= RX_LOW_WATERMARK)
schedule_work(&priv->rx_replenish);
if (write != rxq->write)
ipw_write32(priv, IPW_RX_WRITE_INDEX, rxq->write);
}
static void ipw_rx_queue_replenish(void *data)
{
struct ipw_priv *priv = data;
struct ipw_rx_queue *rxq = priv->rxq;
struct list_head *element;
struct ipw_rx_mem_buffer *rxb;
unsigned long flags;
spin_lock_irqsave(&rxq->lock, flags);
while (!list_empty(&rxq->rx_used)) {
element = rxq->rx_used.next;
rxb = list_entry(element, struct ipw_rx_mem_buffer, list);
rxb->skb = alloc_skb(IPW_RX_BUF_SIZE, GFP_ATOMIC);
if (!rxb->skb) {
printk(KERN_CRIT "%s: Can not allocate SKB buffers.\n",
priv->net_dev->name);
break;
}
list_del(element);
rxb->dma_addr =
pci_map_single(priv->pci_dev, rxb->skb->data,
IPW_RX_BUF_SIZE, PCI_DMA_FROMDEVICE);
list_add_tail(&rxb->list, &rxq->rx_free);
rxq->free_count++;
}
spin_unlock_irqrestore(&rxq->lock, flags);
ipw_rx_queue_restock(priv);
}
static void ipw_bg_rx_queue_replenish(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, rx_replenish);
mutex_lock(&priv->mutex);
ipw_rx_queue_replenish(priv);
mutex_unlock(&priv->mutex);
}
static void ipw_rx_queue_free(struct ipw_priv *priv, struct ipw_rx_queue *rxq)
{
int i;
if (!rxq)
return;
for (i = 0; i < RX_QUEUE_SIZE + RX_FREE_BUFFERS; i++) {
if (rxq->pool[i].skb != NULL) {
pci_unmap_single(priv->pci_dev, rxq->pool[i].dma_addr,
IPW_RX_BUF_SIZE, PCI_DMA_FROMDEVICE);
dev_kfree_skb(rxq->pool[i].skb);
}
}
kfree(rxq);
}
static struct ipw_rx_queue *ipw_rx_queue_alloc(struct ipw_priv *priv)
{
struct ipw_rx_queue *rxq;
int i;
rxq = kzalloc(sizeof(*rxq), GFP_KERNEL);
if (unlikely(!rxq)) {
IPW_ERROR("memory allocation failed\n");
return NULL;
}
spin_lock_init(&rxq->lock);
INIT_LIST_HEAD(&rxq->rx_free);
INIT_LIST_HEAD(&rxq->rx_used);
for (i = 0; i < RX_FREE_BUFFERS + RX_QUEUE_SIZE; i++)
list_add_tail(&rxq->pool[i].list, &rxq->rx_used);
rxq->read = rxq->write = 0;
rxq->free_count = 0;
return rxq;
}
static int ipw_is_rate_in_mask(struct ipw_priv *priv, int ieee_mode, u8 rate)
{
rate &= ~LIBIPW_BASIC_RATE_MASK;
if (ieee_mode == IEEE_A) {
switch (rate) {
case LIBIPW_OFDM_RATE_6MB:
return priv->rates_mask & LIBIPW_OFDM_RATE_6MB_MASK ?
1 : 0;
case LIBIPW_OFDM_RATE_9MB:
return priv->rates_mask & LIBIPW_OFDM_RATE_9MB_MASK ?
1 : 0;
case LIBIPW_OFDM_RATE_12MB:
return priv->
rates_mask & LIBIPW_OFDM_RATE_12MB_MASK ? 1 : 0;
case LIBIPW_OFDM_RATE_18MB:
return priv->
rates_mask & LIBIPW_OFDM_RATE_18MB_MASK ? 1 : 0;
case LIBIPW_OFDM_RATE_24MB:
return priv->
rates_mask & LIBIPW_OFDM_RATE_24MB_MASK ? 1 : 0;
case LIBIPW_OFDM_RATE_36MB:
return priv->
rates_mask & LIBIPW_OFDM_RATE_36MB_MASK ? 1 : 0;
case LIBIPW_OFDM_RATE_48MB:
return priv->
rates_mask & LIBIPW_OFDM_RATE_48MB_MASK ? 1 : 0;
case LIBIPW_OFDM_RATE_54MB:
return priv->
rates_mask & LIBIPW_OFDM_RATE_54MB_MASK ? 1 : 0;
default:
return 0;
}
}
switch (rate) {
case LIBIPW_CCK_RATE_1MB:
return priv->rates_mask & LIBIPW_CCK_RATE_1MB_MASK ? 1 : 0;
case LIBIPW_CCK_RATE_2MB:
return priv->rates_mask & LIBIPW_CCK_RATE_2MB_MASK ? 1 : 0;
case LIBIPW_CCK_RATE_5MB:
return priv->rates_mask & LIBIPW_CCK_RATE_5MB_MASK ? 1 : 0;
case LIBIPW_CCK_RATE_11MB:
return priv->rates_mask & LIBIPW_CCK_RATE_11MB_MASK ? 1 : 0;
}
if (ieee_mode == IEEE_B)
return 0;
switch (rate) {
case LIBIPW_OFDM_RATE_6MB:
return priv->rates_mask & LIBIPW_OFDM_RATE_6MB_MASK ? 1 : 0;
case LIBIPW_OFDM_RATE_9MB:
return priv->rates_mask & LIBIPW_OFDM_RATE_9MB_MASK ? 1 : 0;
case LIBIPW_OFDM_RATE_12MB:
return priv->rates_mask & LIBIPW_OFDM_RATE_12MB_MASK ? 1 : 0;
case LIBIPW_OFDM_RATE_18MB:
return priv->rates_mask & LIBIPW_OFDM_RATE_18MB_MASK ? 1 : 0;
case LIBIPW_OFDM_RATE_24MB:
return priv->rates_mask & LIBIPW_OFDM_RATE_24MB_MASK ? 1 : 0;
case LIBIPW_OFDM_RATE_36MB:
return priv->rates_mask & LIBIPW_OFDM_RATE_36MB_MASK ? 1 : 0;
case LIBIPW_OFDM_RATE_48MB:
return priv->rates_mask & LIBIPW_OFDM_RATE_48MB_MASK ? 1 : 0;
case LIBIPW_OFDM_RATE_54MB:
return priv->rates_mask & LIBIPW_OFDM_RATE_54MB_MASK ? 1 : 0;
}
return 0;
}
static int ipw_compatible_rates(struct ipw_priv *priv,
const struct libipw_network *network,
struct ipw_supported_rates *rates)
{
int num_rates, i;
memset(rates, 0, sizeof(*rates));
num_rates = min(network->rates_len, (u8) IPW_MAX_RATES);
rates->num_rates = 0;
for (i = 0; i < num_rates; i++) {
if (!ipw_is_rate_in_mask(priv, network->mode,
network->rates[i])) {
if (network->rates[i] & LIBIPW_BASIC_RATE_MASK) {
IPW_DEBUG_SCAN("Adding masked mandatory "
"rate %02X\n",
network->rates[i]);
rates->supported_rates[rates->num_rates++] =
network->rates[i];
continue;
}
IPW_DEBUG_SCAN("Rate %02X masked : 0x%08X\n",
network->rates[i], priv->rates_mask);
continue;
}
rates->supported_rates[rates->num_rates++] = network->rates[i];
}
num_rates = min(network->rates_ex_len,
(u8) (IPW_MAX_RATES - num_rates));
for (i = 0; i < num_rates; i++) {
if (!ipw_is_rate_in_mask(priv, network->mode,
network->rates_ex[i])) {
if (network->rates_ex[i] & LIBIPW_BASIC_RATE_MASK) {
IPW_DEBUG_SCAN("Adding masked mandatory "
"rate %02X\n",
network->rates_ex[i]);
rates->supported_rates[rates->num_rates++] =
network->rates[i];
continue;
}
IPW_DEBUG_SCAN("Rate %02X masked : 0x%08X\n",
network->rates_ex[i], priv->rates_mask);
continue;
}
rates->supported_rates[rates->num_rates++] =
network->rates_ex[i];
}
return 1;
}
static void ipw_copy_rates(struct ipw_supported_rates *dest,
const struct ipw_supported_rates *src)
{
u8 i;
for (i = 0; i < src->num_rates; i++)
dest->supported_rates[i] = src->supported_rates[i];
dest->num_rates = src->num_rates;
}
static void ipw_add_cck_scan_rates(struct ipw_supported_rates *rates,
u8 modulation, u32 rate_mask)
{
u8 basic_mask = (LIBIPW_OFDM_MODULATION == modulation) ?
LIBIPW_BASIC_RATE_MASK : 0;
if (rate_mask & LIBIPW_CCK_RATE_1MB_MASK)
rates->supported_rates[rates->num_rates++] =
LIBIPW_BASIC_RATE_MASK | LIBIPW_CCK_RATE_1MB;
if (rate_mask & LIBIPW_CCK_RATE_2MB_MASK)
rates->supported_rates[rates->num_rates++] =
LIBIPW_BASIC_RATE_MASK | LIBIPW_CCK_RATE_2MB;
if (rate_mask & LIBIPW_CCK_RATE_5MB_MASK)
rates->supported_rates[rates->num_rates++] = basic_mask |
LIBIPW_CCK_RATE_5MB;
if (rate_mask & LIBIPW_CCK_RATE_11MB_MASK)
rates->supported_rates[rates->num_rates++] = basic_mask |
LIBIPW_CCK_RATE_11MB;
}
static void ipw_add_ofdm_scan_rates(struct ipw_supported_rates *rates,
u8 modulation, u32 rate_mask)
{
u8 basic_mask = (LIBIPW_OFDM_MODULATION == modulation) ?
LIBIPW_BASIC_RATE_MASK : 0;
if (rate_mask & LIBIPW_OFDM_RATE_6MB_MASK)
rates->supported_rates[rates->num_rates++] = basic_mask |
LIBIPW_OFDM_RATE_6MB;
if (rate_mask & LIBIPW_OFDM_RATE_9MB_MASK)
rates->supported_rates[rates->num_rates++] =
LIBIPW_OFDM_RATE_9MB;
if (rate_mask & LIBIPW_OFDM_RATE_12MB_MASK)
rates->supported_rates[rates->num_rates++] = basic_mask |
LIBIPW_OFDM_RATE_12MB;
if (rate_mask & LIBIPW_OFDM_RATE_18MB_MASK)
rates->supported_rates[rates->num_rates++] =
LIBIPW_OFDM_RATE_18MB;
if (rate_mask & LIBIPW_OFDM_RATE_24MB_MASK)
rates->supported_rates[rates->num_rates++] = basic_mask |
LIBIPW_OFDM_RATE_24MB;
if (rate_mask & LIBIPW_OFDM_RATE_36MB_MASK)
rates->supported_rates[rates->num_rates++] =
LIBIPW_OFDM_RATE_36MB;
if (rate_mask & LIBIPW_OFDM_RATE_48MB_MASK)
rates->supported_rates[rates->num_rates++] =
LIBIPW_OFDM_RATE_48MB;
if (rate_mask & LIBIPW_OFDM_RATE_54MB_MASK)
rates->supported_rates[rates->num_rates++] =
LIBIPW_OFDM_RATE_54MB;
}
static int ipw_find_adhoc_network(struct ipw_priv *priv,
struct ipw_network_match *match,
struct libipw_network *network,
int roaming)
{
struct ipw_supported_rates rates;
if ((priv->ieee->iw_mode == IW_MODE_ADHOC &&
!(network->capability & WLAN_CAPABILITY_IBSS))) {
IPW_DEBUG_MERGE("Network '%*pE (%pM)' excluded due to capability mismatch.\n",
network->ssid_len, network->ssid,
network->bssid);
return 0;
}
if (unlikely(roaming)) {
if ((network->ssid_len != match->network->ssid_len) ||
memcmp(network->ssid, match->network->ssid,
network->ssid_len)) {
IPW_DEBUG_MERGE("Network '%*pE (%pM)' excluded because of non-network ESSID.\n",
network->ssid_len, network->ssid,
network->bssid);
return 0;
}
} else {
if ((priv->config & CFG_STATIC_ESSID) &&
((network->ssid_len != priv->essid_len) ||
memcmp(network->ssid, priv->essid,
min(network->ssid_len, priv->essid_len)))) {
IPW_DEBUG_MERGE("Network '%*pE (%pM)' excluded because of ESSID mismatch: '%*pE'.\n",
network->ssid_len, network->ssid,
network->bssid, priv->essid_len,
priv->essid);
return 0;
}
}
if (network->time_stamp[0] < match->network->time_stamp[0]) {
IPW_DEBUG_MERGE("Network '%*pE excluded because newer than current network.\n",
match->network->ssid_len, match->network->ssid);
return 0;
} else if (network->time_stamp[1] < match->network->time_stamp[1]) {
IPW_DEBUG_MERGE("Network '%*pE excluded because newer than current network.\n",
match->network->ssid_len, match->network->ssid);
return 0;
}
if (priv->ieee->scan_age != 0 &&
time_after(jiffies, network->last_scanned + priv->ieee->scan_age)) {
IPW_DEBUG_MERGE("Network '%*pE (%pM)' excluded because of age: %ums.\n",
network->ssid_len, network->ssid,
network->bssid,
jiffies_to_msecs(jiffies -
network->last_scanned));
return 0;
}
if ((priv->config & CFG_STATIC_CHANNEL) &&
(network->channel != priv->channel)) {
IPW_DEBUG_MERGE("Network '%*pE (%pM)' excluded because of channel mismatch: %d != %d.\n",
network->ssid_len, network->ssid,
network->bssid,
network->channel, priv->channel);
return 0;
}
if (((priv->capability & CAP_PRIVACY_ON) ? 1 : 0) !=
((network->capability & WLAN_CAPABILITY_PRIVACY) ? 1 : 0)) {
IPW_DEBUG_MERGE("Network '%*pE (%pM)' excluded because of privacy mismatch: %s != %s.\n",
network->ssid_len, network->ssid,
network->bssid,
priv->
capability & CAP_PRIVACY_ON ? "on" : "off",
network->
capability & WLAN_CAPABILITY_PRIVACY ? "on" :
"off");
return 0;
}
if (ether_addr_equal(network->bssid, priv->bssid)) {
IPW_DEBUG_MERGE("Network '%*pE (%pM)' excluded because of the same BSSID match: %pM.\n",
network->ssid_len, network->ssid,
network->bssid, priv->bssid);
return 0;
}
if (!libipw_is_valid_mode(priv->ieee, network->mode)) {
IPW_DEBUG_MERGE("Network '%*pE (%pM)' excluded because of invalid frequency/mode combination.\n",
network->ssid_len, network->ssid,
network->bssid);
return 0;
}
if (!ipw_compatible_rates(priv, network, &rates)) {
IPW_DEBUG_MERGE("Network '%*pE (%pM)' excluded because configured rate mask excludes AP mandatory rate.\n",
network->ssid_len, network->ssid,
network->bssid);
return 0;
}
if (rates.num_rates == 0) {
IPW_DEBUG_MERGE("Network '%*pE (%pM)' excluded because of no compatible rates.\n",
network->ssid_len, network->ssid,
network->bssid);
return 0;
}
ipw_copy_rates(&match->rates, &rates);
match->network = network;
IPW_DEBUG_MERGE("Network '%*pE (%pM)' is a viable match.\n",
network->ssid_len, network->ssid, network->bssid);
return 1;
}
static void ipw_merge_adhoc_network(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, merge_networks);
struct libipw_network *network = NULL;
struct ipw_network_match match = {
.network = priv->assoc_network
};
if ((priv->status & STATUS_ASSOCIATED) &&
(priv->ieee->iw_mode == IW_MODE_ADHOC)) {
unsigned long flags;
spin_lock_irqsave(&priv->ieee->lock, flags);
list_for_each_entry(network, &priv->ieee->network_list, list) {
if (network != priv->assoc_network)
ipw_find_adhoc_network(priv, &match, network,
1);
}
spin_unlock_irqrestore(&priv->ieee->lock, flags);
if (match.network == priv->assoc_network) {
IPW_DEBUG_MERGE("No better ADHOC in this network to "
"merge to.\n");
return;
}
mutex_lock(&priv->mutex);
if ((priv->ieee->iw_mode == IW_MODE_ADHOC)) {
IPW_DEBUG_MERGE("remove network %*pE\n",
priv->essid_len, priv->essid);
ipw_remove_current_network(priv);
}
ipw_disassociate(priv);
priv->assoc_network = match.network;
mutex_unlock(&priv->mutex);
return;
}
}
static int ipw_best_network(struct ipw_priv *priv,
struct ipw_network_match *match,
struct libipw_network *network, int roaming)
{
struct ipw_supported_rates rates;
if ((priv->ieee->iw_mode == IW_MODE_INFRA &&
!(network->capability & WLAN_CAPABILITY_ESS)) ||
(priv->ieee->iw_mode == IW_MODE_ADHOC &&
!(network->capability & WLAN_CAPABILITY_IBSS))) {
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' excluded due to capability mismatch.\n",
network->ssid_len, network->ssid,
network->bssid);
return 0;
}
if (unlikely(roaming)) {
if ((network->ssid_len != match->network->ssid_len) ||
memcmp(network->ssid, match->network->ssid,
network->ssid_len)) {
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' excluded because of non-network ESSID.\n",
network->ssid_len, network->ssid,
network->bssid);
return 0;
}
} else {
if ((priv->config & CFG_STATIC_ESSID) &&
((network->ssid_len != priv->essid_len) ||
memcmp(network->ssid, priv->essid,
min(network->ssid_len, priv->essid_len)))) {
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' excluded because of ESSID mismatch: '%*pE'.\n",
network->ssid_len, network->ssid,
network->bssid, priv->essid_len,
priv->essid);
return 0;
}
}
if (match->network && match->network->stats.rssi > network->stats.rssi) {
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' excluded because '%*pE (%pM)' has a stronger signal.\n",
network->ssid_len, network->ssid,
network->bssid, match->network->ssid_len,
match->network->ssid, match->network->bssid);
return 0;
}
if (network->last_associate &&
time_after(network->last_associate + (HZ * 3UL), jiffies)) {
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' excluded because of storming (%ums since last assoc attempt).\n",
network->ssid_len, network->ssid,
network->bssid,
jiffies_to_msecs(jiffies -
network->last_associate));
return 0;
}
if (priv->ieee->scan_age != 0 &&
time_after(jiffies, network->last_scanned + priv->ieee->scan_age)) {
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' excluded because of age: %ums.\n",
network->ssid_len, network->ssid,
network->bssid,
jiffies_to_msecs(jiffies -
network->last_scanned));
return 0;
}
if ((priv->config & CFG_STATIC_CHANNEL) &&
(network->channel != priv->channel)) {
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' excluded because of channel mismatch: %d != %d.\n",
network->ssid_len, network->ssid,
network->bssid,
network->channel, priv->channel);
return 0;
}
if (((priv->capability & CAP_PRIVACY_ON) ? 1 : 0) !=
((network->capability & WLAN_CAPABILITY_PRIVACY) ? 1 : 0)) {
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' excluded because of privacy mismatch: %s != %s.\n",
network->ssid_len, network->ssid,
network->bssid,
priv->capability & CAP_PRIVACY_ON ? "on" :
"off",
network->capability &
WLAN_CAPABILITY_PRIVACY ? "on" : "off");
return 0;
}
if ((priv->config & CFG_STATIC_BSSID) &&
!ether_addr_equal(network->bssid, priv->bssid)) {
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' excluded because of BSSID mismatch: %pM.\n",
network->ssid_len, network->ssid,
network->bssid, priv->bssid);
return 0;
}
if (!libipw_is_valid_mode(priv->ieee, network->mode)) {
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' excluded because of invalid frequency/mode combination.\n",
network->ssid_len, network->ssid,
network->bssid);
return 0;
}
if (!libipw_is_valid_channel(priv->ieee, network->channel)) {
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' excluded because of invalid channel in current GEO\n",
network->ssid_len, network->ssid,
network->bssid);
return 0;
}
if (!ipw_compatible_rates(priv, network, &rates)) {
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' excluded because configured rate mask excludes AP mandatory rate.\n",
network->ssid_len, network->ssid,
network->bssid);
return 0;
}
if (rates.num_rates == 0) {
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' excluded because of no compatible rates.\n",
network->ssid_len, network->ssid,
network->bssid);
return 0;
}
ipw_copy_rates(&match->rates, &rates);
match->network = network;
IPW_DEBUG_ASSOC("Network '%*pE (%pM)' is a viable match.\n",
network->ssid_len, network->ssid, network->bssid);
return 1;
}
static void ipw_adhoc_create(struct ipw_priv *priv,
struct libipw_network *network)
{
const struct libipw_geo *geo = libipw_get_geo(priv->ieee);
int i;
switch (libipw_is_valid_channel(priv->ieee, priv->channel)) {
case LIBIPW_52GHZ_BAND:
network->mode = IEEE_A;
i = libipw_channel_to_index(priv->ieee, priv->channel);
BUG_ON(i == -1);
if (geo->a[i].flags & LIBIPW_CH_PASSIVE_ONLY) {
IPW_WARNING("Overriding invalid channel\n");
priv->channel = geo->a[0].channel;
}
break;
case LIBIPW_24GHZ_BAND:
if (priv->ieee->mode & IEEE_G)
network->mode = IEEE_G;
else
network->mode = IEEE_B;
i = libipw_channel_to_index(priv->ieee, priv->channel);
BUG_ON(i == -1);
if (geo->bg[i].flags & LIBIPW_CH_PASSIVE_ONLY) {
IPW_WARNING("Overriding invalid channel\n");
priv->channel = geo->bg[0].channel;
}
break;
default:
IPW_WARNING("Overriding invalid channel\n");
if (priv->ieee->mode & IEEE_A) {
network->mode = IEEE_A;
priv->channel = geo->a[0].channel;
} else if (priv->ieee->mode & IEEE_G) {
network->mode = IEEE_G;
priv->channel = geo->bg[0].channel;
} else {
network->mode = IEEE_B;
priv->channel = geo->bg[0].channel;
}
break;
}
network->channel = priv->channel;
priv->config |= CFG_ADHOC_PERSIST;
ipw_create_bssid(priv, network->bssid);
network->ssid_len = priv->essid_len;
memcpy(network->ssid, priv->essid, priv->essid_len);
memset(&network->stats, 0, sizeof(network->stats));
network->capability = WLAN_CAPABILITY_IBSS;
if (!(priv->config & CFG_PREAMBLE_LONG))
network->capability |= WLAN_CAPABILITY_SHORT_PREAMBLE;
if (priv->capability & CAP_PRIVACY_ON)
network->capability |= WLAN_CAPABILITY_PRIVACY;
network->rates_len = min(priv->rates.num_rates, MAX_RATES_LENGTH);
memcpy(network->rates, priv->rates.supported_rates, network->rates_len);
network->rates_ex_len = priv->rates.num_rates - network->rates_len;
memcpy(network->rates_ex,
&priv->rates.supported_rates[network->rates_len],
network->rates_ex_len);
network->last_scanned = 0;
network->flags = 0;
network->last_associate = 0;
network->time_stamp[0] = 0;
network->time_stamp[1] = 0;
network->beacon_interval = 100;
network->listen_interval = 10;
network->atim_window = 0;
network->wpa_ie_len = 0;
network->rsn_ie_len = 0;
}
static void ipw_send_tgi_tx_key(struct ipw_priv *priv, int type, int index)
{
struct ipw_tgi_tx_key key;
if (!(priv->ieee->sec.flags & (1 << index)))
return;
key.key_id = index;
memcpy(key.key, priv->ieee->sec.keys[index], SCM_TEMPORAL_KEY_LENGTH);
key.security_type = type;
key.station_index = 0;
key.flags = 0;
key.tx_counter[0] = cpu_to_le32(0);
key.tx_counter[1] = cpu_to_le32(0);
ipw_send_cmd_pdu(priv, IPW_CMD_TGI_TX_KEY, sizeof(key), &key);
}
static void ipw_send_wep_keys(struct ipw_priv *priv, int type)
{
struct ipw_wep_key key;
int i;
key.cmd_id = DINO_CMD_WEP_KEY;
key.seq_num = 0;
for (i = 0; i < 4; i++) {
key.key_index = i | type;
if (!(priv->ieee->sec.flags & (1 << i))) {
key.key_size = 0;
continue;
}
key.key_size = priv->ieee->sec.key_sizes[i];
memcpy(key.key, priv->ieee->sec.keys[i], key.key_size);
ipw_send_cmd_pdu(priv, IPW_CMD_WEP_KEY, sizeof(key), &key);
}
}
static void ipw_set_hw_decrypt_unicast(struct ipw_priv *priv, int level)
{
if (priv->ieee->host_encrypt)
return;
switch (level) {
case SEC_LEVEL_3:
priv->sys_config.disable_unicast_decryption = 0;
priv->ieee->host_decrypt = 0;
break;
case SEC_LEVEL_2:
priv->sys_config.disable_unicast_decryption = 1;
priv->ieee->host_decrypt = 1;
break;
case SEC_LEVEL_1:
priv->sys_config.disable_unicast_decryption = 0;
priv->ieee->host_decrypt = 0;
break;
case SEC_LEVEL_0:
priv->sys_config.disable_unicast_decryption = 1;
break;
default:
break;
}
}
static void ipw_set_hw_decrypt_multicast(struct ipw_priv *priv, int level)
{
if (priv->ieee->host_encrypt)
return;
switch (level) {
case SEC_LEVEL_3:
priv->sys_config.disable_multicast_decryption = 0;
break;
case SEC_LEVEL_2:
priv->sys_config.disable_multicast_decryption = 1;
break;
case SEC_LEVEL_1:
priv->sys_config.disable_multicast_decryption = 0;
break;
case SEC_LEVEL_0:
priv->sys_config.disable_multicast_decryption = 1;
break;
default:
break;
}
}
static void ipw_set_hwcrypto_keys(struct ipw_priv *priv)
{
switch (priv->ieee->sec.level) {
case SEC_LEVEL_3:
if (priv->ieee->sec.flags & SEC_ACTIVE_KEY)
ipw_send_tgi_tx_key(priv,
DCT_FLAG_EXT_SECURITY_CCM,
priv->ieee->sec.active_key);
if (!priv->ieee->host_mc_decrypt)
ipw_send_wep_keys(priv, DCW_WEP_KEY_SEC_TYPE_CCM);
break;
case SEC_LEVEL_2:
if (priv->ieee->sec.flags & SEC_ACTIVE_KEY)
ipw_send_tgi_tx_key(priv,
DCT_FLAG_EXT_SECURITY_TKIP,
priv->ieee->sec.active_key);
break;
case SEC_LEVEL_1:
ipw_send_wep_keys(priv, DCW_WEP_KEY_SEC_TYPE_WEP);
ipw_set_hw_decrypt_unicast(priv, priv->ieee->sec.level);
ipw_set_hw_decrypt_multicast(priv, priv->ieee->sec.level);
break;
case SEC_LEVEL_0:
default:
break;
}
}
static void ipw_adhoc_check(void *data)
{
struct ipw_priv *priv = data;
if (priv->missed_adhoc_beacons++ > priv->disassociate_threshold &&
!(priv->config & CFG_ADHOC_PERSIST)) {
IPW_DEBUG(IPW_DL_INFO | IPW_DL_NOTIF |
IPW_DL_STATE | IPW_DL_ASSOC,
"Missed beacon: %d - disassociate\n",
priv->missed_adhoc_beacons);
ipw_remove_current_network(priv);
ipw_disassociate(priv);
return;
}
schedule_delayed_work(&priv->adhoc_check,
le16_to_cpu(priv->assoc_request.beacon_interval));
}
static void ipw_bg_adhoc_check(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, adhoc_check.work);
mutex_lock(&priv->mutex);
ipw_adhoc_check(priv);
mutex_unlock(&priv->mutex);
}
static void ipw_debug_config(struct ipw_priv *priv)
{
IPW_DEBUG_INFO("Scan completed, no valid APs matched "
"[CFG 0x%08X]\n", priv->config);
if (priv->config & CFG_STATIC_CHANNEL)
IPW_DEBUG_INFO("Channel locked to %d\n", priv->channel);
else
IPW_DEBUG_INFO("Channel unlocked.\n");
if (priv->config & CFG_STATIC_ESSID)
IPW_DEBUG_INFO("ESSID locked to '%*pE'\n",
priv->essid_len, priv->essid);
else
IPW_DEBUG_INFO("ESSID unlocked.\n");
if (priv->config & CFG_STATIC_BSSID)
IPW_DEBUG_INFO("BSSID locked to %pM\n", priv->bssid);
else
IPW_DEBUG_INFO("BSSID unlocked.\n");
if (priv->capability & CAP_PRIVACY_ON)
IPW_DEBUG_INFO("PRIVACY on\n");
else
IPW_DEBUG_INFO("PRIVACY off\n");
IPW_DEBUG_INFO("RATE MASK: 0x%08X\n", priv->rates_mask);
}
static void ipw_set_fixed_rate(struct ipw_priv *priv, int mode)
{
struct ipw_fixed_rate fr;
u32 reg;
u16 mask = 0;
u16 new_tx_rates = priv->rates_mask;
switch (priv->ieee->freq_band) {
case LIBIPW_52GHZ_BAND:
if (priv->rates_mask & ~LIBIPW_OFDM_RATES_MASK) {
IPW_DEBUG_WX
("invalid fixed rate mask in ipw_set_fixed_rate\n");
new_tx_rates = 0;
break;
}
new_tx_rates >>= LIBIPW_OFDM_SHIFT_MASK_A;
break;
default:
if (mode == IEEE_B) {
if (new_tx_rates & ~LIBIPW_CCK_RATES_MASK) {
IPW_DEBUG_WX
("invalid fixed rate mask in ipw_set_fixed_rate\n");
new_tx_rates = 0;
}
break;
}
if (new_tx_rates & ~(LIBIPW_CCK_RATES_MASK |
LIBIPW_OFDM_RATES_MASK)) {
IPW_DEBUG_WX
("invalid fixed rate mask in ipw_set_fixed_rate\n");
new_tx_rates = 0;
break;
}
if (LIBIPW_OFDM_RATE_6MB_MASK & new_tx_rates) {
mask |= (LIBIPW_OFDM_RATE_6MB_MASK >> 1);
new_tx_rates &= ~LIBIPW_OFDM_RATE_6MB_MASK;
}
if (LIBIPW_OFDM_RATE_9MB_MASK & new_tx_rates) {
mask |= (LIBIPW_OFDM_RATE_9MB_MASK >> 1);
new_tx_rates &= ~LIBIPW_OFDM_RATE_9MB_MASK;
}
if (LIBIPW_OFDM_RATE_12MB_MASK & new_tx_rates) {
mask |= (LIBIPW_OFDM_RATE_12MB_MASK >> 1);
new_tx_rates &= ~LIBIPW_OFDM_RATE_12MB_MASK;
}
new_tx_rates |= mask;
break;
}
fr.tx_rates = cpu_to_le16(new_tx_rates);
reg = ipw_read32(priv, IPW_MEM_FIXED_OVERRIDE);
ipw_write_reg32(priv, reg, *(u32 *) & fr);
}
static void ipw_abort_scan(struct ipw_priv *priv)
{
int err;
if (priv->status & STATUS_SCAN_ABORTING) {
IPW_DEBUG_HC("Ignoring concurrent scan abort request.\n");
return;
}
priv->status |= STATUS_SCAN_ABORTING;
err = ipw_send_scan_abort(priv);
if (err)
IPW_DEBUG_HC("Request to abort scan failed.\n");
}
static void ipw_add_scan_channels(struct ipw_priv *priv,
struct ipw_scan_request_ext *scan,
int scan_type)
{
int channel_index = 0;
const struct libipw_geo *geo;
int i;
geo = libipw_get_geo(priv->ieee);
if (priv->ieee->freq_band & LIBIPW_52GHZ_BAND) {
int start = channel_index;
for (i = 0; i < geo->a_channels; i++) {
if ((priv->status & STATUS_ASSOCIATED) &&
geo->a[i].channel == priv->channel)
continue;
channel_index++;
scan->channels_list[channel_index] = geo->a[i].channel;
ipw_set_scan_type(scan, channel_index,
geo->a[i].
flags & LIBIPW_CH_PASSIVE_ONLY ?
IPW_SCAN_PASSIVE_FULL_DWELL_SCAN :
scan_type);
}
if (start != channel_index) {
scan->channels_list[start] = (u8) (IPW_A_MODE << 6) |
(channel_index - start);
channel_index++;
}
}
if (priv->ieee->freq_band & LIBIPW_24GHZ_BAND) {
int start = channel_index;
if (priv->config & CFG_SPEED_SCAN) {
int index;
u8 channels[LIBIPW_24GHZ_CHANNELS] = {
[0] = 0
};
u8 channel;
while (channel_index < IPW_SCAN_CHANNELS - 1) {
channel =
priv->speed_scan[priv->speed_scan_pos];
if (channel == 0) {
priv->speed_scan_pos = 0;
channel = priv->speed_scan[0];
}
if ((priv->status & STATUS_ASSOCIATED) &&
channel == priv->channel) {
priv->speed_scan_pos++;
continue;
}
if (channels[channel - 1] != 0)
break;
channels[channel - 1] = 1;
priv->speed_scan_pos++;
channel_index++;
scan->channels_list[channel_index] = channel;
index =
libipw_channel_to_index(priv->ieee, channel);
ipw_set_scan_type(scan, channel_index,
geo->bg[index].
flags &
LIBIPW_CH_PASSIVE_ONLY ?
IPW_SCAN_PASSIVE_FULL_DWELL_SCAN
: scan_type);
}
} else {
for (i = 0; i < geo->bg_channels; i++) {
if ((priv->status & STATUS_ASSOCIATED) &&
geo->bg[i].channel == priv->channel)
continue;
channel_index++;
scan->channels_list[channel_index] =
geo->bg[i].channel;
ipw_set_scan_type(scan, channel_index,
geo->bg[i].
flags &
LIBIPW_CH_PASSIVE_ONLY ?
IPW_SCAN_PASSIVE_FULL_DWELL_SCAN
: scan_type);
}
}
if (start != channel_index) {
scan->channels_list[start] = (u8) (IPW_B_MODE << 6) |
(channel_index - start);
}
}
}
static int ipw_passive_dwell_time(struct ipw_priv *priv)
{
if (priv->status & STATUS_ASSOCIATED
&& priv->assoc_network->beacon_interval > 10)
return priv->assoc_network->beacon_interval - 10;
else
return 120;
}
static int ipw_request_scan_helper(struct ipw_priv *priv, int type, int direct)
{
struct ipw_scan_request_ext scan;
int err = 0, scan_type;
if (!(priv->status & STATUS_INIT) ||
(priv->status & STATUS_EXIT_PENDING))
return 0;
mutex_lock(&priv->mutex);
if (direct && (priv->direct_scan_ssid_len == 0)) {
IPW_DEBUG_HC("Direct scan requested but no SSID to scan for\n");
priv->status &= ~STATUS_DIRECT_SCAN_PENDING;
goto done;
}
if (priv->status & STATUS_SCANNING) {
IPW_DEBUG_HC("Concurrent scan requested. Queuing.\n");
priv->status |= direct ? STATUS_DIRECT_SCAN_PENDING :
STATUS_SCAN_PENDING;
goto done;
}
if (!(priv->status & STATUS_SCAN_FORCED) &&
priv->status & STATUS_SCAN_ABORTING) {
IPW_DEBUG_HC("Scan request while abort pending. Queuing.\n");
priv->status |= direct ? STATUS_DIRECT_SCAN_PENDING :
STATUS_SCAN_PENDING;
goto done;
}
if (priv->status & STATUS_RF_KILL_MASK) {
IPW_DEBUG_HC("Queuing scan due to RF Kill activation\n");
priv->status |= direct ? STATUS_DIRECT_SCAN_PENDING :
STATUS_SCAN_PENDING;
goto done;
}
memset(&scan, 0, sizeof(scan));
scan.full_scan_index = cpu_to_le32(libipw_get_scans(priv->ieee));
if (type == IW_SCAN_TYPE_PASSIVE) {
IPW_DEBUG_WX("use passive scanning\n");
scan_type = IPW_SCAN_PASSIVE_FULL_DWELL_SCAN;
scan.dwell_time[IPW_SCAN_PASSIVE_FULL_DWELL_SCAN] =
cpu_to_le16(ipw_passive_dwell_time(priv));
ipw_add_scan_channels(priv, &scan, scan_type);
goto send_request;
}
if (priv->config & CFG_SPEED_SCAN)
scan.dwell_time[IPW_SCAN_ACTIVE_BROADCAST_SCAN] =
cpu_to_le16(30);
else
scan.dwell_time[IPW_SCAN_ACTIVE_BROADCAST_SCAN] =
cpu_to_le16(20);
scan.dwell_time[IPW_SCAN_ACTIVE_BROADCAST_AND_DIRECT_SCAN] =
cpu_to_le16(20);
scan.dwell_time[IPW_SCAN_PASSIVE_FULL_DWELL_SCAN] =
cpu_to_le16(ipw_passive_dwell_time(priv));
scan.dwell_time[IPW_SCAN_ACTIVE_DIRECT_SCAN] = cpu_to_le16(20);
#ifdef CONFIG_IPW2200_MONITOR
if (priv->ieee->iw_mode == IW_MODE_MONITOR) {
u8 channel;
u8 band = 0;
switch (libipw_is_valid_channel(priv->ieee, priv->channel)) {
case LIBIPW_52GHZ_BAND:
band = (u8) (IPW_A_MODE << 6) | 1;
channel = priv->channel;
break;
case LIBIPW_24GHZ_BAND:
band = (u8) (IPW_B_MODE << 6) | 1;
channel = priv->channel;
break;
default:
band = (u8) (IPW_B_MODE << 6) | 1;
channel = 9;
break;
}
scan.channels_list[0] = band;
scan.channels_list[1] = channel;
ipw_set_scan_type(&scan, 1, IPW_SCAN_PASSIVE_FULL_DWELL_SCAN);
scan.dwell_time[IPW_SCAN_PASSIVE_FULL_DWELL_SCAN] =
cpu_to_le16(2000);
} else {
#endif
if (direct) {
err = ipw_send_ssid(priv, priv->direct_scan_ssid,
priv->direct_scan_ssid_len);
if (err) {
IPW_DEBUG_HC("Attempt to send SSID command "
"failed\n");
goto done;
}
scan_type = IPW_SCAN_ACTIVE_BROADCAST_AND_DIRECT_SCAN;
} else if ((priv->status & STATUS_ROAMING)
|| (!(priv->status & STATUS_ASSOCIATED)
&& (priv->config & CFG_STATIC_ESSID)
&& (le32_to_cpu(scan.full_scan_index) % 2))) {
err = ipw_send_ssid(priv, priv->essid, priv->essid_len);
if (err) {
IPW_DEBUG_HC("Attempt to send SSID command "
"failed.\n");
goto done;
}
scan_type = IPW_SCAN_ACTIVE_BROADCAST_AND_DIRECT_SCAN;
} else
scan_type = IPW_SCAN_ACTIVE_BROADCAST_SCAN;
ipw_add_scan_channels(priv, &scan, scan_type);
#ifdef CONFIG_IPW2200_MONITOR
}
#endif
send_request:
err = ipw_send_scan_request_ext(priv, &scan);
if (err) {
IPW_DEBUG_HC("Sending scan command failed: %08X\n", err);
goto done;
}
priv->status |= STATUS_SCANNING;
if (direct) {
priv->status &= ~STATUS_DIRECT_SCAN_PENDING;
priv->direct_scan_ssid_len = 0;
} else
priv->status &= ~STATUS_SCAN_PENDING;
schedule_delayed_work(&priv->scan_check, IPW_SCAN_CHECK_WATCHDOG);
done:
mutex_unlock(&priv->mutex);
return err;
}
static void ipw_request_passive_scan(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, request_passive_scan.work);
ipw_request_scan_helper(priv, IW_SCAN_TYPE_PASSIVE, 0);
}
static void ipw_request_scan(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, request_scan.work);
ipw_request_scan_helper(priv, IW_SCAN_TYPE_ACTIVE, 0);
}
static void ipw_request_direct_scan(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, request_direct_scan.work);
ipw_request_scan_helper(priv, IW_SCAN_TYPE_ACTIVE, 1);
}
static void ipw_bg_abort_scan(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, abort_scan);
mutex_lock(&priv->mutex);
ipw_abort_scan(priv);
mutex_unlock(&priv->mutex);
}
static int ipw_wpa_enable(struct ipw_priv *priv, int value)
{
priv->ieee->wpa_enabled = value;
return 0;
}
static int ipw_wpa_set_auth_algs(struct ipw_priv *priv, int value)
{
struct libipw_device *ieee = priv->ieee;
struct libipw_security sec = {
.flags = SEC_AUTH_MODE,
};
int ret = 0;
if (value & IW_AUTH_ALG_SHARED_KEY) {
sec.auth_mode = WLAN_AUTH_SHARED_KEY;
ieee->open_wep = 0;
} else if (value & IW_AUTH_ALG_OPEN_SYSTEM) {
sec.auth_mode = WLAN_AUTH_OPEN;
ieee->open_wep = 1;
} else if (value & IW_AUTH_ALG_LEAP) {
sec.auth_mode = WLAN_AUTH_LEAP;
ieee->open_wep = 1;
} else
return -EINVAL;
if (ieee->set_security)
ieee->set_security(ieee->dev, &sec);
else
ret = -EOPNOTSUPP;
return ret;
}
static void ipw_wpa_assoc_frame(struct ipw_priv *priv, char *wpa_ie,
int wpa_ie_len)
{
ipw_wpa_enable(priv, 1);
}
static int ipw_set_rsn_capa(struct ipw_priv *priv,
char *capabilities, int length)
{
IPW_DEBUG_HC("HOST_CMD_RSN_CAPABILITIES\n");
return ipw_send_cmd_pdu(priv, IPW_CMD_RSN_CAPABILITIES, length,
capabilities);
}
static int ipw_wx_set_genie(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
struct libipw_device *ieee = priv->ieee;
u8 *buf;
int err = 0;
if (wrqu->data.length > MAX_WPA_IE_LEN ||
(wrqu->data.length && extra == NULL))
return -EINVAL;
if (wrqu->data.length) {
buf = kmemdup(extra, wrqu->data.length, GFP_KERNEL);
if (buf == NULL) {
err = -ENOMEM;
goto out;
}
kfree(ieee->wpa_ie);
ieee->wpa_ie = buf;
ieee->wpa_ie_len = wrqu->data.length;
} else {
kfree(ieee->wpa_ie);
ieee->wpa_ie = NULL;
ieee->wpa_ie_len = 0;
}
ipw_wpa_assoc_frame(priv, ieee->wpa_ie, ieee->wpa_ie_len);
out:
return err;
}
static int ipw_wx_get_genie(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
struct libipw_device *ieee = priv->ieee;
int err = 0;
if (ieee->wpa_ie_len == 0 || ieee->wpa_ie == NULL) {
wrqu->data.length = 0;
goto out;
}
if (wrqu->data.length < ieee->wpa_ie_len) {
err = -E2BIG;
goto out;
}
wrqu->data.length = ieee->wpa_ie_len;
memcpy(extra, ieee->wpa_ie, ieee->wpa_ie_len);
out:
return err;
}
static int wext_cipher2level(int cipher)
{
switch (cipher) {
case IW_AUTH_CIPHER_NONE:
return SEC_LEVEL_0;
case IW_AUTH_CIPHER_WEP40:
case IW_AUTH_CIPHER_WEP104:
return SEC_LEVEL_1;
case IW_AUTH_CIPHER_TKIP:
return SEC_LEVEL_2;
case IW_AUTH_CIPHER_CCMP:
return SEC_LEVEL_3;
default:
return -1;
}
}
static int ipw_wx_set_auth(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
struct libipw_device *ieee = priv->ieee;
struct iw_param *param = &wrqu->param;
struct lib80211_crypt_data *crypt;
unsigned long flags;
int ret = 0;
switch (param->flags & IW_AUTH_INDEX) {
case IW_AUTH_WPA_VERSION:
break;
case IW_AUTH_CIPHER_PAIRWISE:
ipw_set_hw_decrypt_unicast(priv,
wext_cipher2level(param->value));
break;
case IW_AUTH_CIPHER_GROUP:
ipw_set_hw_decrypt_multicast(priv,
wext_cipher2level(param->value));
break;
case IW_AUTH_KEY_MGMT:
break;
case IW_AUTH_TKIP_COUNTERMEASURES:
crypt = priv->ieee->crypt_info.crypt[priv->ieee->crypt_info.tx_keyidx];
if (!crypt || !crypt->ops->set_flags || !crypt->ops->get_flags)
break;
flags = crypt->ops->get_flags(crypt->priv);
if (param->value)
flags |= IEEE80211_CRYPTO_TKIP_COUNTERMEASURES;
else
flags &= ~IEEE80211_CRYPTO_TKIP_COUNTERMEASURES;
crypt->ops->set_flags(flags, crypt->priv);
break;
case IW_AUTH_DROP_UNENCRYPTED:{
struct libipw_security sec = {
.flags = SEC_ENABLED,
.enabled = param->value,
};
priv->ieee->drop_unencrypted = param->value;
if (!param->value) {
sec.flags |= SEC_LEVEL;
sec.level = SEC_LEVEL_0;
} else {
sec.flags |= SEC_LEVEL;
sec.level = SEC_LEVEL_1;
}
if (priv->ieee->set_security)
priv->ieee->set_security(priv->ieee->dev, &sec);
break;
}
case IW_AUTH_80211_AUTH_ALG:
ret = ipw_wpa_set_auth_algs(priv, param->value);
break;
case IW_AUTH_WPA_ENABLED:
ret = ipw_wpa_enable(priv, param->value);
ipw_disassociate(priv);
break;
case IW_AUTH_RX_UNENCRYPTED_EAPOL:
ieee->ieee802_1x = param->value;
break;
case IW_AUTH_PRIVACY_INVOKED:
ieee->privacy_invoked = param->value;
break;
default:
return -EOPNOTSUPP;
}
return ret;
}
static int ipw_wx_get_auth(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
struct libipw_device *ieee = priv->ieee;
struct lib80211_crypt_data *crypt;
struct iw_param *param = &wrqu->param;
switch (param->flags & IW_AUTH_INDEX) {
case IW_AUTH_WPA_VERSION:
case IW_AUTH_CIPHER_PAIRWISE:
case IW_AUTH_CIPHER_GROUP:
case IW_AUTH_KEY_MGMT:
return -EOPNOTSUPP;
case IW_AUTH_TKIP_COUNTERMEASURES:
crypt = priv->ieee->crypt_info.crypt[priv->ieee->crypt_info.tx_keyidx];
if (!crypt || !crypt->ops->get_flags)
break;
param->value = (crypt->ops->get_flags(crypt->priv) &
IEEE80211_CRYPTO_TKIP_COUNTERMEASURES) ? 1 : 0;
break;
case IW_AUTH_DROP_UNENCRYPTED:
param->value = ieee->drop_unencrypted;
break;
case IW_AUTH_80211_AUTH_ALG:
param->value = ieee->sec.auth_mode;
break;
case IW_AUTH_WPA_ENABLED:
param->value = ieee->wpa_enabled;
break;
case IW_AUTH_RX_UNENCRYPTED_EAPOL:
param->value = ieee->ieee802_1x;
break;
case IW_AUTH_ROAMING_CONTROL:
case IW_AUTH_PRIVACY_INVOKED:
param->value = ieee->privacy_invoked;
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static int ipw_wx_set_encodeext(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
struct iw_encode_ext *ext = (struct iw_encode_ext *)extra;
if (hwcrypto) {
if (ext->alg == IW_ENCODE_ALG_TKIP) {
if (ext->ext_flags & IW_ENCODE_EXT_GROUP_KEY)
priv->ieee->host_mc_decrypt = 1;
else {
priv->ieee->host_encrypt = 0;
priv->ieee->host_encrypt_msdu = 1;
priv->ieee->host_decrypt = 1;
}
} else {
priv->ieee->host_encrypt = 0;
priv->ieee->host_encrypt_msdu = 0;
priv->ieee->host_decrypt = 0;
priv->ieee->host_mc_decrypt = 0;
}
}
return libipw_wx_set_encodeext(priv->ieee, info, wrqu, extra);
}
static int ipw_wx_get_encodeext(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
return libipw_wx_get_encodeext(priv->ieee, info, wrqu, extra);
}
static int ipw_wx_set_mlme(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
struct iw_mlme *mlme = (struct iw_mlme *)extra;
__le16 reason;
reason = cpu_to_le16(mlme->reason_code);
switch (mlme->cmd) {
case IW_MLME_DEAUTH:
break;
case IW_MLME_DISASSOC:
ipw_disassociate(priv);
break;
default:
return -EOPNOTSUPP;
}
return 0;
}
static u8 ipw_qos_current_mode(struct ipw_priv * priv)
{
u8 mode = 0;
if (priv->status & STATUS_ASSOCIATED) {
unsigned long flags;
spin_lock_irqsave(&priv->ieee->lock, flags);
mode = priv->assoc_network->mode;
spin_unlock_irqrestore(&priv->ieee->lock, flags);
} else {
mode = priv->ieee->mode;
}
IPW_DEBUG_QOS("QoS network/card mode %d\n", mode);
return mode;
}
static int ipw_qos_handle_probe_response(struct ipw_priv *priv,
int active_network,
struct libipw_network *network)
{
u32 size = sizeof(struct libipw_qos_parameters);
if (network->capability & WLAN_CAPABILITY_IBSS)
network->qos_data.active = network->qos_data.supported;
if (network->flags & NETWORK_HAS_QOS_MASK) {
if (active_network &&
(network->flags & NETWORK_HAS_QOS_PARAMETERS))
network->qos_data.active = network->qos_data.supported;
if ((network->qos_data.active == 1) && (active_network == 1) &&
(network->flags & NETWORK_HAS_QOS_PARAMETERS) &&
(network->qos_data.old_param_count !=
network->qos_data.param_count)) {
network->qos_data.old_param_count =
network->qos_data.param_count;
schedule_work(&priv->qos_activate);
IPW_DEBUG_QOS("QoS parameters change call "
"qos_activate\n");
}
} else {
if ((priv->ieee->mode == IEEE_B) || (network->mode == IEEE_B))
memcpy(&network->qos_data.parameters,
&def_parameters_CCK, size);
else
memcpy(&network->qos_data.parameters,
&def_parameters_OFDM, size);
if ((network->qos_data.active == 1) && (active_network == 1)) {
IPW_DEBUG_QOS("QoS was disabled call qos_activate\n");
schedule_work(&priv->qos_activate);
}
network->qos_data.active = 0;
network->qos_data.supported = 0;
}
if ((priv->status & STATUS_ASSOCIATED) &&
(priv->ieee->iw_mode == IW_MODE_ADHOC) && (active_network == 0)) {
if (!ether_addr_equal(network->bssid, priv->bssid))
if (network->capability & WLAN_CAPABILITY_IBSS)
if ((network->ssid_len ==
priv->assoc_network->ssid_len) &&
!memcmp(network->ssid,
priv->assoc_network->ssid,
network->ssid_len)) {
schedule_work(&priv->merge_networks);
}
}
return 0;
}
static int ipw_qos_activate(struct ipw_priv *priv,
struct libipw_qos_data *qos_network_data)
{
int err;
struct libipw_qos_parameters qos_parameters[QOS_QOS_SETS];
struct libipw_qos_parameters *active_one = NULL;
u32 size = sizeof(struct libipw_qos_parameters);
u32 burst_duration;
int i;
u8 type;
type = ipw_qos_current_mode(priv);
active_one = &(qos_parameters[QOS_PARAM_SET_DEF_CCK]);
memcpy(active_one, priv->qos_data.def_qos_parm_CCK, size);
active_one = &(qos_parameters[QOS_PARAM_SET_DEF_OFDM]);
memcpy(active_one, priv->qos_data.def_qos_parm_OFDM, size);
if (qos_network_data == NULL) {
if (type == IEEE_B) {
IPW_DEBUG_QOS("QoS activate network mode %d\n", type);
active_one = &def_parameters_CCK;
} else
active_one = &def_parameters_OFDM;
memcpy(&qos_parameters[QOS_PARAM_SET_ACTIVE], active_one, size);
burst_duration = ipw_qos_get_burst_duration(priv);
for (i = 0; i < QOS_QUEUE_NUM; i++)
qos_parameters[QOS_PARAM_SET_ACTIVE].tx_op_limit[i] =
cpu_to_le16(burst_duration);
} else if (priv->ieee->iw_mode == IW_MODE_ADHOC) {
if (type == IEEE_B) {
IPW_DEBUG_QOS("QoS activate IBSS network mode %d\n",
type);
if (priv->qos_data.qos_enable == 0)
active_one = &def_parameters_CCK;
else
active_one = priv->qos_data.def_qos_parm_CCK;
} else {
if (priv->qos_data.qos_enable == 0)
active_one = &def_parameters_OFDM;
else
active_one = priv->qos_data.def_qos_parm_OFDM;
}
memcpy(&qos_parameters[QOS_PARAM_SET_ACTIVE], active_one, size);
} else {
unsigned long flags;
int active;
spin_lock_irqsave(&priv->ieee->lock, flags);
active_one = &(qos_network_data->parameters);
qos_network_data->old_param_count =
qos_network_data->param_count;
memcpy(&qos_parameters[QOS_PARAM_SET_ACTIVE], active_one, size);
active = qos_network_data->supported;
spin_unlock_irqrestore(&priv->ieee->lock, flags);
if (active == 0) {
burst_duration = ipw_qos_get_burst_duration(priv);
for (i = 0; i < QOS_QUEUE_NUM; i++)
qos_parameters[QOS_PARAM_SET_ACTIVE].
tx_op_limit[i] = cpu_to_le16(burst_duration);
}
}
IPW_DEBUG_QOS("QoS sending IPW_CMD_QOS_PARAMETERS\n");
err = ipw_send_qos_params_command(priv, &qos_parameters[0]);
if (err)
IPW_DEBUG_QOS("QoS IPW_CMD_QOS_PARAMETERS failed\n");
return err;
}
static int ipw_qos_set_info_element(struct ipw_priv *priv)
{
int ret = 0;
struct libipw_qos_information_element qos_info;
if (priv == NULL)
return -1;
qos_info.elementID = QOS_ELEMENT_ID;
qos_info.length = sizeof(struct libipw_qos_information_element) - 2;
qos_info.version = QOS_VERSION_1;
qos_info.ac_info = 0;
memcpy(qos_info.qui, qos_oui, QOS_OUI_LEN);
qos_info.qui_type = QOS_OUI_TYPE;
qos_info.qui_subtype = QOS_OUI_INFO_SUB_TYPE;
ret = ipw_send_qos_info_command(priv, &qos_info);
if (ret != 0) {
IPW_DEBUG_QOS("QoS error calling ipw_send_qos_info_command\n");
}
return ret;
}
static int ipw_qos_association(struct ipw_priv *priv,
struct libipw_network *network)
{
int err = 0;
struct libipw_qos_data *qos_data = NULL;
struct libipw_qos_data ibss_data = {
.supported = 1,
.active = 1,
};
switch (priv->ieee->iw_mode) {
case IW_MODE_ADHOC:
BUG_ON(!(network->capability & WLAN_CAPABILITY_IBSS));
qos_data = &ibss_data;
break;
case IW_MODE_INFRA:
qos_data = &network->qos_data;
break;
default:
BUG();
break;
}
err = ipw_qos_activate(priv, qos_data);
if (err) {
priv->assoc_request.policy_support &= ~HC_QOS_SUPPORT_ASSOC;
return err;
}
if (priv->qos_data.qos_enable && qos_data->supported) {
IPW_DEBUG_QOS("QoS will be enabled for this association\n");
priv->assoc_request.policy_support |= HC_QOS_SUPPORT_ASSOC;
return ipw_qos_set_info_element(priv);
}
return 0;
}
static int ipw_qos_association_resp(struct ipw_priv *priv,
struct libipw_network *network)
{
int ret = 0;
unsigned long flags;
u32 size = sizeof(struct libipw_qos_parameters);
int set_qos_param = 0;
if ((priv == NULL) || (network == NULL) ||
(priv->assoc_network == NULL))
return ret;
if (!(priv->status & STATUS_ASSOCIATED))
return ret;
if ((priv->ieee->iw_mode != IW_MODE_INFRA))
return ret;
spin_lock_irqsave(&priv->ieee->lock, flags);
if (network->flags & NETWORK_HAS_QOS_PARAMETERS) {
memcpy(&priv->assoc_network->qos_data, &network->qos_data,
sizeof(struct libipw_qos_data));
priv->assoc_network->qos_data.active = 1;
if ((network->qos_data.old_param_count !=
network->qos_data.param_count)) {
set_qos_param = 1;
network->qos_data.old_param_count =
network->qos_data.param_count;
}
} else {
if ((network->mode == IEEE_B) || (priv->ieee->mode == IEEE_B))
memcpy(&priv->assoc_network->qos_data.parameters,
&def_parameters_CCK, size);
else
memcpy(&priv->assoc_network->qos_data.parameters,
&def_parameters_OFDM, size);
priv->assoc_network->qos_data.active = 0;
priv->assoc_network->qos_data.supported = 0;
set_qos_param = 1;
}
spin_unlock_irqrestore(&priv->ieee->lock, flags);
if (set_qos_param == 1)
schedule_work(&priv->qos_activate);
return ret;
}
static u32 ipw_qos_get_burst_duration(struct ipw_priv *priv)
{
u32 ret = 0;
if ((priv == NULL))
return 0;
if (!(priv->ieee->modulation & LIBIPW_OFDM_MODULATION))
ret = priv->qos_data.burst_duration_CCK;
else
ret = priv->qos_data.burst_duration_OFDM;
return ret;
}
static void ipw_qos_init(struct ipw_priv *priv, int enable,
int burst_enable, u32 burst_duration_CCK,
u32 burst_duration_OFDM)
{
priv->qos_data.qos_enable = enable;
if (priv->qos_data.qos_enable) {
priv->qos_data.def_qos_parm_CCK = &def_qos_parameters_CCK;
priv->qos_data.def_qos_parm_OFDM = &def_qos_parameters_OFDM;
IPW_DEBUG_QOS("QoS is enabled\n");
} else {
priv->qos_data.def_qos_parm_CCK = &def_parameters_CCK;
priv->qos_data.def_qos_parm_OFDM = &def_parameters_OFDM;
IPW_DEBUG_QOS("QoS is not enabled\n");
}
priv->qos_data.burst_enable = burst_enable;
if (burst_enable) {
priv->qos_data.burst_duration_CCK = burst_duration_CCK;
priv->qos_data.burst_duration_OFDM = burst_duration_OFDM;
} else {
priv->qos_data.burst_duration_CCK = 0;
priv->qos_data.burst_duration_OFDM = 0;
}
}
static int ipw_get_tx_queue_number(struct ipw_priv *priv, u16 priority)
{
if (priority > 7 || !priv->qos_data.qos_enable)
priority = 0;
return from_priority_to_tx_queue[priority] - 1;
}
static int ipw_is_qos_active(struct net_device *dev,
struct sk_buff *skb)
{
struct ipw_priv *priv = libipw_priv(dev);
struct libipw_qos_data *qos_data = NULL;
int active, supported;
u8 *daddr = skb->data + ETH_ALEN;
int unicast = !is_multicast_ether_addr(daddr);
if (!(priv->status & STATUS_ASSOCIATED))
return 0;
qos_data = &priv->assoc_network->qos_data;
if (priv->ieee->iw_mode == IW_MODE_ADHOC) {
if (unicast == 0)
qos_data->active = 0;
else
qos_data->active = qos_data->supported;
}
active = qos_data->active;
supported = qos_data->supported;
IPW_DEBUG_QOS("QoS %d network is QoS active %d supported %d "
"unicast %d\n",
priv->qos_data.qos_enable, active, supported, unicast);
if (active && priv->qos_data.qos_enable)
return 1;
return 0;
}
static int ipw_qos_set_tx_queue_command(struct ipw_priv *priv,
u16 priority,
struct tfd_data *tfd)
{
int tx_queue_id = 0;
tx_queue_id = from_priority_to_tx_queue[priority] - 1;
tfd->tx_flags_ext |= DCT_FLAG_EXT_QOS_ENABLED;
if (priv->qos_data.qos_no_ack_mask & (1UL << tx_queue_id)) {
tfd->tx_flags &= ~DCT_FLAG_ACK_REQD;
tfd->tfd.tfd_26.mchdr.qos_ctrl |= cpu_to_le16(CTRL_QOS_NO_ACK);
}
return 0;
}
static void ipw_bg_qos_activate(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, qos_activate);
mutex_lock(&priv->mutex);
if (priv->status & STATUS_ASSOCIATED)
ipw_qos_activate(priv, &(priv->assoc_network->qos_data));
mutex_unlock(&priv->mutex);
}
static int ipw_handle_probe_response(struct net_device *dev,
struct libipw_probe_response *resp,
struct libipw_network *network)
{
struct ipw_priv *priv = libipw_priv(dev);
int active_network = ((priv->status & STATUS_ASSOCIATED) &&
(network == priv->assoc_network));
ipw_qos_handle_probe_response(priv, active_network, network);
return 0;
}
static int ipw_handle_beacon(struct net_device *dev,
struct libipw_beacon *resp,
struct libipw_network *network)
{
struct ipw_priv *priv = libipw_priv(dev);
int active_network = ((priv->status & STATUS_ASSOCIATED) &&
(network == priv->assoc_network));
ipw_qos_handle_probe_response(priv, active_network, network);
return 0;
}
static int ipw_handle_assoc_response(struct net_device *dev,
struct libipw_assoc_response *resp,
struct libipw_network *network)
{
struct ipw_priv *priv = libipw_priv(dev);
ipw_qos_association_resp(priv, network);
return 0;
}
static int ipw_send_qos_params_command(struct ipw_priv *priv, struct libipw_qos_parameters
*qos_param)
{
return ipw_send_cmd_pdu(priv, IPW_CMD_QOS_PARAMETERS,
sizeof(*qos_param) * 3, qos_param);
}
static int ipw_send_qos_info_command(struct ipw_priv *priv, struct libipw_qos_information_element
*qos_param)
{
return ipw_send_cmd_pdu(priv, IPW_CMD_WME_INFO, sizeof(*qos_param),
qos_param);
}
static int ipw_associate_network(struct ipw_priv *priv,
struct libipw_network *network,
struct ipw_supported_rates *rates, int roaming)
{
int err;
if (priv->config & CFG_FIXED_RATE)
ipw_set_fixed_rate(priv, network->mode);
if (!(priv->config & CFG_STATIC_ESSID)) {
priv->essid_len = min(network->ssid_len,
(u8) IW_ESSID_MAX_SIZE);
memcpy(priv->essid, network->ssid, priv->essid_len);
}
network->last_associate = jiffies;
memset(&priv->assoc_request, 0, sizeof(priv->assoc_request));
priv->assoc_request.channel = network->channel;
priv->assoc_request.auth_key = 0;
if ((priv->capability & CAP_PRIVACY_ON) &&
(priv->ieee->sec.auth_mode == WLAN_AUTH_SHARED_KEY)) {
priv->assoc_request.auth_type = AUTH_SHARED_KEY;
priv->assoc_request.auth_key = priv->ieee->sec.active_key;
if (priv->ieee->sec.level == SEC_LEVEL_1)
ipw_send_wep_keys(priv, DCW_WEP_KEY_SEC_TYPE_WEP);
} else if ((priv->capability & CAP_PRIVACY_ON) &&
(priv->ieee->sec.auth_mode == WLAN_AUTH_LEAP))
priv->assoc_request.auth_type = AUTH_LEAP;
else
priv->assoc_request.auth_type = AUTH_OPEN;
if (priv->ieee->wpa_ie_len) {
priv->assoc_request.policy_support = cpu_to_le16(0x02);
ipw_set_rsn_capa(priv, priv->ieee->wpa_ie,
priv->ieee->wpa_ie_len);
}
if (network->mode & priv->ieee->mode & IEEE_A)
priv->assoc_request.ieee_mode = IPW_A_MODE;
else if (network->mode & priv->ieee->mode & IEEE_G)
priv->assoc_request.ieee_mode = IPW_G_MODE;
else if (network->mode & priv->ieee->mode & IEEE_B)
priv->assoc_request.ieee_mode = IPW_B_MODE;
priv->assoc_request.capability = cpu_to_le16(network->capability);
if ((network->capability & WLAN_CAPABILITY_SHORT_PREAMBLE)
&& !(priv->config & CFG_PREAMBLE_LONG)) {
priv->assoc_request.preamble_length = DCT_FLAG_SHORT_PREAMBLE;
} else {
priv->assoc_request.preamble_length = DCT_FLAG_LONG_PREAMBLE;
priv->assoc_request.capability &=
~cpu_to_le16(WLAN_CAPABILITY_SHORT_PREAMBLE);
}
if (priv->ieee->iw_mode == IW_MODE_ADHOC)
priv->assoc_request.capability &=
~cpu_to_le16(WLAN_CAPABILITY_SHORT_SLOT_TIME);
IPW_DEBUG_ASSOC("%ssociation attempt: '%*pE', channel %d, 802.11%c [%d], %s[:%s], enc=%s%s%s%c%c\n",
roaming ? "Rea" : "A",
priv->essid_len, priv->essid,
network->channel,
ipw_modes[priv->assoc_request.ieee_mode],
rates->num_rates,
(priv->assoc_request.preamble_length ==
DCT_FLAG_LONG_PREAMBLE) ? "long" : "short",
network->capability &
WLAN_CAPABILITY_SHORT_PREAMBLE ? "short" : "long",
priv->capability & CAP_PRIVACY_ON ? "on " : "off",
priv->capability & CAP_PRIVACY_ON ?
(priv->capability & CAP_SHARED_KEY ? "(shared)" :
"(open)") : "",
priv->capability & CAP_PRIVACY_ON ? " key=" : "",
priv->capability & CAP_PRIVACY_ON ?
'1' + priv->ieee->sec.active_key : '.',
priv->capability & CAP_PRIVACY_ON ? '.' : ' ');
priv->assoc_request.beacon_interval = cpu_to_le16(network->beacon_interval);
if ((priv->ieee->iw_mode == IW_MODE_ADHOC) &&
(network->time_stamp[0] == 0) && (network->time_stamp[1] == 0)) {
priv->assoc_request.assoc_type = HC_IBSS_START;
priv->assoc_request.assoc_tsf_msw = 0;
priv->assoc_request.assoc_tsf_lsw = 0;
} else {
if (unlikely(roaming))
priv->assoc_request.assoc_type = HC_REASSOCIATE;
else
priv->assoc_request.assoc_type = HC_ASSOCIATE;
priv->assoc_request.assoc_tsf_msw = cpu_to_le32(network->time_stamp[1]);
priv->assoc_request.assoc_tsf_lsw = cpu_to_le32(network->time_stamp[0]);
}
memcpy(priv->assoc_request.bssid, network->bssid, ETH_ALEN);
if (priv->ieee->iw_mode == IW_MODE_ADHOC) {
eth_broadcast_addr(priv->assoc_request.dest);
priv->assoc_request.atim_window = cpu_to_le16(network->atim_window);
} else {
memcpy(priv->assoc_request.dest, network->bssid, ETH_ALEN);
priv->assoc_request.atim_window = 0;
}
priv->assoc_request.listen_interval = cpu_to_le16(network->listen_interval);
err = ipw_send_ssid(priv, priv->essid, priv->essid_len);
if (err) {
IPW_DEBUG_HC("Attempt to send SSID command failed.\n");
return err;
}
rates->ieee_mode = priv->assoc_request.ieee_mode;
rates->purpose = IPW_RATE_CONNECT;
ipw_send_supported_rates(priv, rates);
if (priv->assoc_request.ieee_mode == IPW_G_MODE)
priv->sys_config.dot11g_auto_detection = 1;
else
priv->sys_config.dot11g_auto_detection = 0;
if (priv->ieee->iw_mode == IW_MODE_ADHOC)
priv->sys_config.answer_broadcast_ssid_probe = 1;
else
priv->sys_config.answer_broadcast_ssid_probe = 0;
err = ipw_send_system_config(priv);
if (err) {
IPW_DEBUG_HC("Attempt to send sys config command failed.\n");
return err;
}
IPW_DEBUG_ASSOC("Association sensitivity: %d\n", network->stats.rssi);
err = ipw_set_sensitivity(priv, network->stats.rssi + IPW_RSSI_TO_DBM);
if (err) {
IPW_DEBUG_HC("Attempt to send associate command failed.\n");
return err;
}
priv->channel = network->channel;
memcpy(priv->bssid, network->bssid, ETH_ALEN);
priv->status |= STATUS_ASSOCIATING;
priv->status &= ~STATUS_SECURITY_UPDATED;
priv->assoc_network = network;
#ifdef CONFIG_IPW2200_QOS
ipw_qos_association(priv, network);
#endif
err = ipw_send_associate(priv, &priv->assoc_request);
if (err) {
IPW_DEBUG_HC("Attempt to send associate command failed.\n");
return err;
}
IPW_DEBUG(IPW_DL_STATE, "associating: '%*pE' %pM\n",
priv->essid_len, priv->essid, priv->bssid);
return 0;
}
static void ipw_roam(void *data)
{
struct ipw_priv *priv = data;
struct libipw_network *network = NULL;
struct ipw_network_match match = {
.network = priv->assoc_network
};
if (!(priv->status & (STATUS_ASSOCIATED | STATUS_ROAMING)))
return;
if (priv->status & STATUS_ASSOCIATED) {
unsigned long flags;
u8 rssi = priv->assoc_network->stats.rssi;
priv->assoc_network->stats.rssi = -128;
spin_lock_irqsave(&priv->ieee->lock, flags);
list_for_each_entry(network, &priv->ieee->network_list, list) {
if (network != priv->assoc_network)
ipw_best_network(priv, &match, network, 1);
}
spin_unlock_irqrestore(&priv->ieee->lock, flags);
priv->assoc_network->stats.rssi = rssi;
if (match.network == priv->assoc_network) {
IPW_DEBUG_ASSOC("No better APs in this network to "
"roam to.\n");
priv->status &= ~STATUS_ROAMING;
ipw_debug_config(priv);
return;
}
ipw_send_disassociate(priv, 1);
priv->assoc_network = match.network;
return;
}
ipw_compatible_rates(priv, priv->assoc_network, &match.rates);
ipw_associate_network(priv, priv->assoc_network, &match.rates, 1);
priv->status &= ~STATUS_ROAMING;
}
static void ipw_bg_roam(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, roam);
mutex_lock(&priv->mutex);
ipw_roam(priv);
mutex_unlock(&priv->mutex);
}
static int ipw_associate(void *data)
{
struct ipw_priv *priv = data;
struct libipw_network *network = NULL;
struct ipw_network_match match = {
.network = NULL
};
struct ipw_supported_rates *rates;
struct list_head *element;
unsigned long flags;
if (priv->ieee->iw_mode == IW_MODE_MONITOR) {
IPW_DEBUG_ASSOC("Not attempting association (monitor mode)\n");
return 0;
}
if (priv->status & (STATUS_ASSOCIATED | STATUS_ASSOCIATING)) {
IPW_DEBUG_ASSOC("Not attempting association (already in "
"progress)\n");
return 0;
}
if (priv->status & STATUS_DISASSOCIATING) {
IPW_DEBUG_ASSOC("Not attempting association (in "
"disassociating)\n ");
schedule_work(&priv->associate);
return 0;
}
if (!ipw_is_init(priv) || (priv->status & STATUS_SCANNING)) {
IPW_DEBUG_ASSOC("Not attempting association (scanning or not "
"initialized)\n");
return 0;
}
if (!(priv->config & CFG_ASSOCIATE) &&
!(priv->config & (CFG_STATIC_ESSID | CFG_STATIC_BSSID))) {
IPW_DEBUG_ASSOC("Not attempting association (associate=0)\n");
return 0;
}
spin_lock_irqsave(&priv->ieee->lock, flags);
list_for_each_entry(network, &priv->ieee->network_list, list)
ipw_best_network(priv, &match, network, 0);
network = match.network;
rates = &match.rates;
if (network == NULL &&
priv->ieee->iw_mode == IW_MODE_ADHOC &&
priv->config & CFG_ADHOC_CREATE &&
priv->config & CFG_STATIC_ESSID &&
priv->config & CFG_STATIC_CHANNEL) {
if (list_empty(&priv->ieee->network_free_list)) {
struct libipw_network *oldest = NULL;
struct libipw_network *target;
list_for_each_entry(target, &priv->ieee->network_list, list) {
if ((oldest == NULL) ||
(target->last_scanned < oldest->last_scanned))
oldest = target;
}
list_del(&oldest->list);
target = oldest;
IPW_DEBUG_ASSOC("Expired '%*pE' (%pM) from network list.\n",
target->ssid_len, target->ssid,
target->bssid);
list_add_tail(&target->list,
&priv->ieee->network_free_list);
}
element = priv->ieee->network_free_list.next;
network = list_entry(element, struct libipw_network, list);
ipw_adhoc_create(priv, network);
rates = &priv->rates;
list_del(element);
list_add_tail(&network->list, &priv->ieee->network_list);
}
spin_unlock_irqrestore(&priv->ieee->lock, flags);
if (!network) {
ipw_debug_config(priv);
if (!(priv->status & STATUS_SCANNING)) {
if (!(priv->config & CFG_SPEED_SCAN))
schedule_delayed_work(&priv->request_scan,
SCAN_INTERVAL);
else
schedule_delayed_work(&priv->request_scan, 0);
}
return 0;
}
ipw_associate_network(priv, network, rates, 0);
return 1;
}
static void ipw_bg_associate(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, associate);
mutex_lock(&priv->mutex);
ipw_associate(priv);
mutex_unlock(&priv->mutex);
}
static void ipw_rebuild_decrypted_skb(struct ipw_priv *priv,
struct sk_buff *skb)
{
struct ieee80211_hdr *hdr;
u16 fc;
hdr = (struct ieee80211_hdr *)skb->data;
fc = le16_to_cpu(hdr->frame_control);
if (!(fc & IEEE80211_FCTL_PROTECTED))
return;
fc &= ~IEEE80211_FCTL_PROTECTED;
hdr->frame_control = cpu_to_le16(fc);
switch (priv->ieee->sec.level) {
case SEC_LEVEL_3:
memmove(skb->data + LIBIPW_3ADDR_LEN,
skb->data + LIBIPW_3ADDR_LEN + 8,
skb->len - LIBIPW_3ADDR_LEN - 8);
skb_trim(skb, skb->len - 16);
break;
case SEC_LEVEL_2:
break;
case SEC_LEVEL_1:
memmove(skb->data + LIBIPW_3ADDR_LEN,
skb->data + LIBIPW_3ADDR_LEN + 4,
skb->len - LIBIPW_3ADDR_LEN - 4);
skb_trim(skb, skb->len - 8);
break;
case SEC_LEVEL_0:
break;
default:
printk(KERN_ERR "Unknown security level %d\n",
priv->ieee->sec.level);
break;
}
}
static void ipw_handle_data_packet(struct ipw_priv *priv,
struct ipw_rx_mem_buffer *rxb,
struct libipw_rx_stats *stats)
{
struct net_device *dev = priv->net_dev;
struct libipw_hdr_4addr *hdr;
struct ipw_rx_packet *pkt = (struct ipw_rx_packet *)rxb->skb->data;
netif_trans_update(dev);
if (unlikely((le16_to_cpu(pkt->u.frame.length) + IPW_RX_FRAME_SIZE) >
skb_tailroom(rxb->skb))) {
dev->stats.rx_errors++;
priv->wstats.discard.misc++;
IPW_DEBUG_DROP("Corruption detected! Oh no!\n");
return;
} else if (unlikely(!netif_running(priv->net_dev))) {
dev->stats.rx_dropped++;
priv->wstats.discard.misc++;
IPW_DEBUG_DROP("Dropping packet while interface is not up.\n");
return;
}
skb_reserve(rxb->skb, offsetof(struct ipw_rx_packet, u.frame.data));
skb_put(rxb->skb, le16_to_cpu(pkt->u.frame.length));
IPW_DEBUG_RX("Rx packet of %d bytes.\n", rxb->skb->len);
hdr = (struct libipw_hdr_4addr *)rxb->skb->data;
if (priv->ieee->iw_mode != IW_MODE_MONITOR &&
(is_multicast_ether_addr(hdr->addr1) ?
!priv->ieee->host_mc_decrypt : !priv->ieee->host_decrypt))
ipw_rebuild_decrypted_skb(priv, rxb->skb);
if (!libipw_rx(priv->ieee, rxb->skb, stats))
dev->stats.rx_errors++;
else {
rxb->skb = NULL;
__ipw_led_activity_on(priv);
}
}
static void ipw_handle_data_packet_monitor(struct ipw_priv *priv,
struct ipw_rx_mem_buffer *rxb,
struct libipw_rx_stats *stats)
{
struct net_device *dev = priv->net_dev;
struct ipw_rx_packet *pkt = (struct ipw_rx_packet *)rxb->skb->data;
struct ipw_rx_frame *frame = &pkt->u.frame;
u16 received_channel = frame->received_channel;
u8 antennaAndPhy = frame->antennaAndPhy;
s8 antsignal = frame->rssi_dbm - IPW_RSSI_TO_DBM;
u16 pktrate = frame->rate;
struct ipw_rt_hdr *ipw_rt;
unsigned short len = le16_to_cpu(pkt->u.frame.length);
netif_trans_update(dev);
if (unlikely((le16_to_cpu(pkt->u.frame.length) + IPW_RX_FRAME_SIZE) >
skb_tailroom(rxb->skb))) {
dev->stats.rx_errors++;
priv->wstats.discard.misc++;
IPW_DEBUG_DROP("Corruption detected! Oh no!\n");
return;
} else if (unlikely(!netif_running(priv->net_dev))) {
dev->stats.rx_dropped++;
priv->wstats.discard.misc++;
IPW_DEBUG_DROP("Dropping packet while interface is not up.\n");
return;
}
if (len > IPW_RX_BUF_SIZE - sizeof(struct ipw_rt_hdr)) {
dev->stats.rx_dropped++;
priv->wstats.discard.misc++;
IPW_DEBUG_DROP("Dropping too large packet in monitor\n");
return;
}
memmove(rxb->skb->data + sizeof(struct ipw_rt_hdr),
rxb->skb->data + IPW_RX_FRAME_SIZE, len);
ipw_rt = (struct ipw_rt_hdr *)rxb->skb->data;
ipw_rt->rt_hdr.it_version = PKTHDR_RADIOTAP_VERSION;
ipw_rt->rt_hdr.it_pad = 0;
ipw_rt->rt_hdr.it_len = cpu_to_le16(sizeof(struct ipw_rt_hdr));
ipw_rt->rt_hdr.it_present = cpu_to_le32(
(1 << IEEE80211_RADIOTAP_TSFT) |
(1 << IEEE80211_RADIOTAP_FLAGS) |
(1 << IEEE80211_RADIOTAP_RATE) |
(1 << IEEE80211_RADIOTAP_CHANNEL) |
(1 << IEEE80211_RADIOTAP_DBM_ANTSIGNAL) |
(1 << IEEE80211_RADIOTAP_DBM_ANTNOISE) |
(1 << IEEE80211_RADIOTAP_ANTENNA));
ipw_rt->rt_flags = 0;
ipw_rt->rt_tsf = (u64)(frame->parent_tsf[3] << 24 |
frame->parent_tsf[2] << 16 |
frame->parent_tsf[1] << 8 |
frame->parent_tsf[0]);
ipw_rt->rt_dbmsignal = antsignal;
ipw_rt->rt_dbmnoise = (s8) le16_to_cpu(frame->noise);
ipw_rt->rt_channel = cpu_to_le16(ieee80211chan2mhz(received_channel));
if (received_channel > 14) {
ipw_rt->rt_chbitmask =
cpu_to_le16((IEEE80211_CHAN_OFDM | IEEE80211_CHAN_5GHZ));
} else if (antennaAndPhy & 32) {
ipw_rt->rt_chbitmask =
cpu_to_le16((IEEE80211_CHAN_CCK | IEEE80211_CHAN_2GHZ));
} else {
ipw_rt->rt_chbitmask =
cpu_to_le16(IEEE80211_CHAN_OFDM | IEEE80211_CHAN_2GHZ);
}
switch (pktrate) {
case IPW_TX_RATE_1MB:
ipw_rt->rt_rate = 2;
break;
case IPW_TX_RATE_2MB:
ipw_rt->rt_rate = 4;
break;
case IPW_TX_RATE_5MB:
ipw_rt->rt_rate = 10;
break;
case IPW_TX_RATE_6MB:
ipw_rt->rt_rate = 12;
break;
case IPW_TX_RATE_9MB:
ipw_rt->rt_rate = 18;
break;
case IPW_TX_RATE_11MB:
ipw_rt->rt_rate = 22;
break;
case IPW_TX_RATE_12MB:
ipw_rt->rt_rate = 24;
break;
case IPW_TX_RATE_18MB:
ipw_rt->rt_rate = 36;
break;
case IPW_TX_RATE_24MB:
ipw_rt->rt_rate = 48;
break;
case IPW_TX_RATE_36MB:
ipw_rt->rt_rate = 72;
break;
case IPW_TX_RATE_48MB:
ipw_rt->rt_rate = 96;
break;
case IPW_TX_RATE_54MB:
ipw_rt->rt_rate = 108;
break;
default:
ipw_rt->rt_rate = 0;
break;
}
ipw_rt->rt_antenna = (antennaAndPhy & 3);
if ((antennaAndPhy & 64))
ipw_rt->rt_flags |= IEEE80211_RADIOTAP_F_SHORTPRE;
skb_put(rxb->skb, len + sizeof(struct ipw_rt_hdr));
IPW_DEBUG_RX("Rx packet of %d bytes.\n", rxb->skb->len);
if (!libipw_rx(priv->ieee, rxb->skb, stats))
dev->stats.rx_errors++;
else {
rxb->skb = NULL;
}
}
static void ipw_handle_promiscuous_rx(struct ipw_priv *priv,
struct ipw_rx_mem_buffer *rxb,
struct libipw_rx_stats *stats)
{
struct net_device *dev = priv->prom_net_dev;
struct ipw_rx_packet *pkt = (struct ipw_rx_packet *)rxb->skb->data;
struct ipw_rx_frame *frame = &pkt->u.frame;
struct ipw_rt_hdr *ipw_rt;
struct ieee80211_hdr *hdr;
u16 channel = frame->received_channel;
u8 phy_flags = frame->antennaAndPhy;
s8 signal = frame->rssi_dbm - IPW_RSSI_TO_DBM;
s8 noise = (s8) le16_to_cpu(frame->noise);
u8 rate = frame->rate;
unsigned short len = le16_to_cpu(pkt->u.frame.length);
struct sk_buff *skb;
int hdr_only = 0;
u16 filter = priv->prom_priv->filter;
if (filter & IPW_PROM_NO_RX)
return;
netif_trans_update(dev);
if (unlikely((len + IPW_RX_FRAME_SIZE) > skb_tailroom(rxb->skb))) {
dev->stats.rx_errors++;
IPW_DEBUG_DROP("Corruption detected! Oh no!\n");
return;
}
if (unlikely(!netif_running(dev))) {
dev->stats.rx_dropped++;
IPW_DEBUG_DROP("Dropping packet while interface is not up.\n");
return;
}
if (len > IPW_RX_BUF_SIZE - sizeof(struct ipw_rt_hdr)) {
dev->stats.rx_dropped++;
IPW_DEBUG_DROP("Dropping too large packet in monitor\n");
return;
}
hdr = (void *)rxb->skb->data + IPW_RX_FRAME_SIZE;
if (libipw_is_management(le16_to_cpu(hdr->frame_control))) {
if (filter & IPW_PROM_NO_MGMT)
return;
if (filter & IPW_PROM_MGMT_HEADER_ONLY)
hdr_only = 1;
} else if (libipw_is_control(le16_to_cpu(hdr->frame_control))) {
if (filter & IPW_PROM_NO_CTL)
return;
if (filter & IPW_PROM_CTL_HEADER_ONLY)
hdr_only = 1;
} else if (libipw_is_data(le16_to_cpu(hdr->frame_control))) {
if (filter & IPW_PROM_NO_DATA)
return;
if (filter & IPW_PROM_DATA_HEADER_ONLY)
hdr_only = 1;
}
skb = skb_copy(rxb->skb, GFP_ATOMIC);
if (skb == NULL) {
IPW_ERROR("skb_clone failed for promiscuous copy.\n");
return;
}
ipw_rt = (void *)skb->data;
if (hdr_only)
len = libipw_get_hdrlen(le16_to_cpu(hdr->frame_control));
memcpy(ipw_rt->payload, hdr, len);
ipw_rt->rt_hdr.it_version = PKTHDR_RADIOTAP_VERSION;
ipw_rt->rt_hdr.it_pad = 0;
ipw_rt->rt_hdr.it_len = cpu_to_le16(sizeof(*ipw_rt));
skb_put(skb, sizeof(*ipw_rt) + len);
ipw_rt->rt_hdr.it_present = cpu_to_le32(
(1 << IEEE80211_RADIOTAP_TSFT) |
(1 << IEEE80211_RADIOTAP_FLAGS) |
(1 << IEEE80211_RADIOTAP_RATE) |
(1 << IEEE80211_RADIOTAP_CHANNEL) |
(1 << IEEE80211_RADIOTAP_DBM_ANTSIGNAL) |
(1 << IEEE80211_RADIOTAP_DBM_ANTNOISE) |
(1 << IEEE80211_RADIOTAP_ANTENNA));
ipw_rt->rt_flags = 0;
ipw_rt->rt_tsf = (u64)(frame->parent_tsf[3] << 24 |
frame->parent_tsf[2] << 16 |
frame->parent_tsf[1] << 8 |
frame->parent_tsf[0]);
ipw_rt->rt_dbmsignal = signal;
ipw_rt->rt_dbmnoise = noise;
ipw_rt->rt_channel = cpu_to_le16(ieee80211chan2mhz(channel));
if (channel > 14) {
ipw_rt->rt_chbitmask =
cpu_to_le16((IEEE80211_CHAN_OFDM | IEEE80211_CHAN_5GHZ));
} else if (phy_flags & (1 << 5)) {
ipw_rt->rt_chbitmask =
cpu_to_le16((IEEE80211_CHAN_CCK | IEEE80211_CHAN_2GHZ));
} else {
ipw_rt->rt_chbitmask =
cpu_to_le16(IEEE80211_CHAN_OFDM | IEEE80211_CHAN_2GHZ);
}
switch (rate) {
case IPW_TX_RATE_1MB:
ipw_rt->rt_rate = 2;
break;
case IPW_TX_RATE_2MB:
ipw_rt->rt_rate = 4;
break;
case IPW_TX_RATE_5MB:
ipw_rt->rt_rate = 10;
break;
case IPW_TX_RATE_6MB:
ipw_rt->rt_rate = 12;
break;
case IPW_TX_RATE_9MB:
ipw_rt->rt_rate = 18;
break;
case IPW_TX_RATE_11MB:
ipw_rt->rt_rate = 22;
break;
case IPW_TX_RATE_12MB:
ipw_rt->rt_rate = 24;
break;
case IPW_TX_RATE_18MB:
ipw_rt->rt_rate = 36;
break;
case IPW_TX_RATE_24MB:
ipw_rt->rt_rate = 48;
break;
case IPW_TX_RATE_36MB:
ipw_rt->rt_rate = 72;
break;
case IPW_TX_RATE_48MB:
ipw_rt->rt_rate = 96;
break;
case IPW_TX_RATE_54MB:
ipw_rt->rt_rate = 108;
break;
default:
ipw_rt->rt_rate = 0;
break;
}
ipw_rt->rt_antenna = (phy_flags & 3);
if (phy_flags & (1 << 6))
ipw_rt->rt_flags |= IEEE80211_RADIOTAP_F_SHORTPRE;
IPW_DEBUG_RX("Rx packet of %d bytes.\n", skb->len);
if (!libipw_rx(priv->prom_priv->ieee, skb, stats)) {
dev->stats.rx_errors++;
dev_kfree_skb_any(skb);
}
}
static int is_network_packet(struct ipw_priv *priv,
struct libipw_hdr_4addr *header)
{
switch (priv->ieee->iw_mode) {
case IW_MODE_ADHOC:
if (ether_addr_equal(header->addr2, priv->net_dev->dev_addr))
return 0;
if (is_multicast_ether_addr(header->addr1))
return ether_addr_equal(header->addr3, priv->bssid);
return ether_addr_equal(header->addr1,
priv->net_dev->dev_addr);
case IW_MODE_INFRA:
if (ether_addr_equal(header->addr3, priv->net_dev->dev_addr))
return 0;
if (is_multicast_ether_addr(header->addr1))
return ether_addr_equal(header->addr2, priv->bssid);
return ether_addr_equal(header->addr1,
priv->net_dev->dev_addr);
}
return 1;
}
static int is_duplicate_packet(struct ipw_priv *priv,
struct libipw_hdr_4addr *header)
{
u16 sc = le16_to_cpu(header->seq_ctl);
u16 seq = WLAN_GET_SEQ_SEQ(sc);
u16 frag = WLAN_GET_SEQ_FRAG(sc);
u16 *last_seq, *last_frag;
unsigned long *last_time;
switch (priv->ieee->iw_mode) {
case IW_MODE_ADHOC:
{
struct list_head *p;
struct ipw_ibss_seq *entry = NULL;
u8 *mac = header->addr2;
int index = mac[5] % IPW_IBSS_MAC_HASH_SIZE;
list_for_each(p, &priv->ibss_mac_hash[index]) {
entry =
list_entry(p, struct ipw_ibss_seq, list);
if (ether_addr_equal(entry->mac, mac))
break;
}
if (p == &priv->ibss_mac_hash[index]) {
entry = kmalloc(sizeof(*entry), GFP_ATOMIC);
if (!entry) {
IPW_ERROR
("Cannot malloc new mac entry\n");
return 0;
}
memcpy(entry->mac, mac, ETH_ALEN);
entry->seq_num = seq;
entry->frag_num = frag;
entry->packet_time = jiffies;
list_add(&entry->list,
&priv->ibss_mac_hash[index]);
return 0;
}
last_seq = &entry->seq_num;
last_frag = &entry->frag_num;
last_time = &entry->packet_time;
break;
}
case IW_MODE_INFRA:
last_seq = &priv->last_seq_num;
last_frag = &priv->last_frag_num;
last_time = &priv->last_packet_time;
break;
default:
return 0;
}
if ((*last_seq == seq) &&
time_after(*last_time + IPW_PACKET_RETRY_TIME, jiffies)) {
if (*last_frag == frag)
goto drop;
if (*last_frag + 1 != frag)
goto drop;
} else
*last_seq = seq;
*last_frag = frag;
*last_time = jiffies;
return 0;
drop:
return 1;
}
static void ipw_handle_mgmt_packet(struct ipw_priv *priv,
struct ipw_rx_mem_buffer *rxb,
struct libipw_rx_stats *stats)
{
struct sk_buff *skb = rxb->skb;
struct ipw_rx_packet *pkt = (struct ipw_rx_packet *)skb->data;
struct libipw_hdr_4addr *header = (struct libipw_hdr_4addr *)
(skb->data + IPW_RX_FRAME_SIZE);
libipw_rx_mgt(priv->ieee, header, stats);
if (priv->ieee->iw_mode == IW_MODE_ADHOC &&
((WLAN_FC_GET_STYPE(le16_to_cpu(header->frame_ctl)) ==
IEEE80211_STYPE_PROBE_RESP) ||
(WLAN_FC_GET_STYPE(le16_to_cpu(header->frame_ctl)) ==
IEEE80211_STYPE_BEACON))) {
if (ether_addr_equal(header->addr3, priv->bssid))
ipw_add_station(priv, header->addr2);
}
if (priv->config & CFG_NET_STATS) {
IPW_DEBUG_HC("sending stat packet\n");
skb_put(skb, le16_to_cpu(pkt->u.frame.length) +
IPW_RX_FRAME_SIZE);
skb_pull(skb, IPW_RX_FRAME_SIZE);
memcpy(skb_push(skb, sizeof(*stats)), stats, sizeof(*stats));
skb->dev = priv->ieee->dev;
skb_reset_mac_header(skb);
skb->pkt_type = PACKET_OTHERHOST;
skb->protocol = cpu_to_be16(ETH_P_80211_STATS);
memset(skb->cb, 0, sizeof(rxb->skb->cb));
netif_rx(skb);
rxb->skb = NULL;
}
}
static void ipw_rx(struct ipw_priv *priv)
{
struct ipw_rx_mem_buffer *rxb;
struct ipw_rx_packet *pkt;
struct libipw_hdr_4addr *header;
u32 r, w, i;
u8 network_packet;
u8 fill_rx = 0;
r = ipw_read32(priv, IPW_RX_READ_INDEX);
w = ipw_read32(priv, IPW_RX_WRITE_INDEX);
i = priv->rxq->read;
if (ipw_rx_queue_space (priv->rxq) > (RX_QUEUE_SIZE / 2))
fill_rx = 1;
while (i != r) {
rxb = priv->rxq->queue[i];
if (unlikely(rxb == NULL)) {
printk(KERN_CRIT "Queue not allocated!\n");
break;
}
priv->rxq->queue[i] = NULL;
pci_dma_sync_single_for_cpu(priv->pci_dev, rxb->dma_addr,
IPW_RX_BUF_SIZE,
PCI_DMA_FROMDEVICE);
pkt = (struct ipw_rx_packet *)rxb->skb->data;
IPW_DEBUG_RX("Packet: type=%02X seq=%02X bits=%02X\n",
pkt->header.message_type,
pkt->header.rx_seq_num, pkt->header.control_bits);
switch (pkt->header.message_type) {
case RX_FRAME_TYPE: {
struct libipw_rx_stats stats = {
.rssi = pkt->u.frame.rssi_dbm -
IPW_RSSI_TO_DBM,
.signal =
pkt->u.frame.rssi_dbm -
IPW_RSSI_TO_DBM + 0x100,
.noise =
le16_to_cpu(pkt->u.frame.noise),
.rate = pkt->u.frame.rate,
.mac_time = jiffies,
.received_channel =
pkt->u.frame.received_channel,
.freq =
(pkt->u.frame.
control & (1 << 0)) ?
LIBIPW_24GHZ_BAND :
LIBIPW_52GHZ_BAND,
.len = le16_to_cpu(pkt->u.frame.length),
};
if (stats.rssi != 0)
stats.mask |= LIBIPW_STATMASK_RSSI;
if (stats.signal != 0)
stats.mask |= LIBIPW_STATMASK_SIGNAL;
if (stats.noise != 0)
stats.mask |= LIBIPW_STATMASK_NOISE;
if (stats.rate != 0)
stats.mask |= LIBIPW_STATMASK_RATE;
priv->rx_packets++;
#ifdef CONFIG_IPW2200_PROMISCUOUS
if (priv->prom_net_dev && netif_running(priv->prom_net_dev))
ipw_handle_promiscuous_rx(priv, rxb, &stats);
#endif
#ifdef CONFIG_IPW2200_MONITOR
if (priv->ieee->iw_mode == IW_MODE_MONITOR) {
#ifdef CONFIG_IPW2200_RADIOTAP
ipw_handle_data_packet_monitor(priv,
rxb,
&stats);
#else
ipw_handle_data_packet(priv, rxb,
&stats);
#endif
break;
}
#endif
header =
(struct libipw_hdr_4addr *)(rxb->skb->
data +
IPW_RX_FRAME_SIZE);
network_packet =
is_network_packet(priv, header);
if (network_packet && priv->assoc_network) {
priv->assoc_network->stats.rssi =
stats.rssi;
priv->exp_avg_rssi =
exponential_average(priv->exp_avg_rssi,
stats.rssi, DEPTH_RSSI);
}
IPW_DEBUG_RX("Frame: len=%u\n",
le16_to_cpu(pkt->u.frame.length));
if (le16_to_cpu(pkt->u.frame.length) <
libipw_get_hdrlen(le16_to_cpu(
header->frame_ctl))) {
IPW_DEBUG_DROP
("Received packet is too small. "
"Dropping.\n");
priv->net_dev->stats.rx_errors++;
priv->wstats.discard.misc++;
break;
}
switch (WLAN_FC_GET_TYPE
(le16_to_cpu(header->frame_ctl))) {
case IEEE80211_FTYPE_MGMT:
ipw_handle_mgmt_packet(priv, rxb,
&stats);
break;
case IEEE80211_FTYPE_CTL:
break;
case IEEE80211_FTYPE_DATA:
if (unlikely(!network_packet ||
is_duplicate_packet(priv,
header)))
{
IPW_DEBUG_DROP("Dropping: "
"%pM, "
"%pM, "
"%pM\n",
header->addr1,
header->addr2,
header->addr3);
break;
}
ipw_handle_data_packet(priv, rxb,
&stats);
break;
}
break;
}
case RX_HOST_NOTIFICATION_TYPE:{
IPW_DEBUG_RX
("Notification: subtype=%02X flags=%02X size=%d\n",
pkt->u.notification.subtype,
pkt->u.notification.flags,
le16_to_cpu(pkt->u.notification.size));
ipw_rx_notification(priv, &pkt->u.notification);
break;
}
default:
IPW_DEBUG_RX("Bad Rx packet of type %d\n",
pkt->header.message_type);
break;
}
if (rxb->skb != NULL) {
dev_kfree_skb_any(rxb->skb);
rxb->skb = NULL;
}
pci_unmap_single(priv->pci_dev, rxb->dma_addr,
IPW_RX_BUF_SIZE, PCI_DMA_FROMDEVICE);
list_add_tail(&rxb->list, &priv->rxq->rx_used);
i = (i + 1) % RX_QUEUE_SIZE;
if (fill_rx) {
priv->rxq->read = i;
ipw_rx_queue_replenish(priv);
}
}
priv->rxq->read = i;
ipw_rx_queue_restock(priv);
}
static int ipw_sw_reset(struct ipw_priv *priv, int option)
{
int band, modulation;
int old_mode = priv->ieee->iw_mode;
priv->config = 0;
if (!led_support)
priv->config |= CFG_NO_LED;
if (associate)
priv->config |= CFG_ASSOCIATE;
else
IPW_DEBUG_INFO("Auto associate disabled.\n");
if (auto_create)
priv->config |= CFG_ADHOC_CREATE;
else
IPW_DEBUG_INFO("Auto adhoc creation disabled.\n");
priv->config &= ~CFG_STATIC_ESSID;
priv->essid_len = 0;
memset(priv->essid, 0, IW_ESSID_MAX_SIZE);
if (disable && option) {
priv->status |= STATUS_RF_KILL_SW;
IPW_DEBUG_INFO("Radio disabled.\n");
}
if (default_channel != 0) {
priv->config |= CFG_STATIC_CHANNEL;
priv->channel = default_channel;
IPW_DEBUG_INFO("Bind to static channel %d\n", default_channel);
}
#ifdef CONFIG_IPW2200_QOS
ipw_qos_init(priv, qos_enable, qos_burst_enable,
burst_duration_CCK, burst_duration_OFDM);
#endif
switch (network_mode) {
case 1:
priv->ieee->iw_mode = IW_MODE_ADHOC;
priv->net_dev->type = ARPHRD_ETHER;
break;
#ifdef CONFIG_IPW2200_MONITOR
case 2:
priv->ieee->iw_mode = IW_MODE_MONITOR;
#ifdef CONFIG_IPW2200_RADIOTAP
priv->net_dev->type = ARPHRD_IEEE80211_RADIOTAP;
#else
priv->net_dev->type = ARPHRD_IEEE80211;
#endif
break;
#endif
default:
case 0:
priv->net_dev->type = ARPHRD_ETHER;
priv->ieee->iw_mode = IW_MODE_INFRA;
break;
}
if (hwcrypto) {
priv->ieee->host_encrypt = 0;
priv->ieee->host_encrypt_msdu = 0;
priv->ieee->host_decrypt = 0;
priv->ieee->host_mc_decrypt = 0;
}
IPW_DEBUG_INFO("Hardware crypto [%s]\n", hwcrypto ? "on" : "off");
priv->ieee->host_open_frag = 0;
if ((priv->pci_dev->device == 0x4223) ||
(priv->pci_dev->device == 0x4224)) {
if (option == 1)
printk(KERN_INFO DRV_NAME
": Detected Intel PRO/Wireless 2915ABG Network "
"Connection\n");
priv->ieee->abg_true = 1;
band = LIBIPW_52GHZ_BAND | LIBIPW_24GHZ_BAND;
modulation = LIBIPW_OFDM_MODULATION |
LIBIPW_CCK_MODULATION;
priv->adapter = IPW_2915ABG;
priv->ieee->mode = IEEE_A | IEEE_G | IEEE_B;
} else {
if (option == 1)
printk(KERN_INFO DRV_NAME
": Detected Intel PRO/Wireless 2200BG Network "
"Connection\n");
priv->ieee->abg_true = 0;
band = LIBIPW_24GHZ_BAND;
modulation = LIBIPW_OFDM_MODULATION |
LIBIPW_CCK_MODULATION;
priv->adapter = IPW_2200BG;
priv->ieee->mode = IEEE_G | IEEE_B;
}
priv->ieee->freq_band = band;
priv->ieee->modulation = modulation;
priv->rates_mask = LIBIPW_DEFAULT_RATES_MASK;
priv->disassociate_threshold = IPW_MB_DISASSOCIATE_THRESHOLD_DEFAULT;
priv->roaming_threshold = IPW_MB_ROAMING_THRESHOLD_DEFAULT;
priv->rts_threshold = DEFAULT_RTS_THRESHOLD;
priv->short_retry_limit = DEFAULT_SHORT_RETRY_LIMIT;
priv->long_retry_limit = DEFAULT_LONG_RETRY_LIMIT;
priv->power_mode = IPW_POWER_AC;
priv->tx_power = IPW_TX_POWER_DEFAULT;
return old_mode == priv->ieee->iw_mode;
}
static int ipw_set_channel(struct ipw_priv *priv, u8 channel)
{
if (channel == 0) {
IPW_DEBUG_INFO("Setting channel to ANY (0)\n");
priv->config &= ~CFG_STATIC_CHANNEL;
IPW_DEBUG_ASSOC("Attempting to associate with new "
"parameters.\n");
ipw_associate(priv);
return 0;
}
priv->config |= CFG_STATIC_CHANNEL;
if (priv->channel == channel) {
IPW_DEBUG_INFO("Request to set channel to current value (%d)\n",
channel);
return 0;
}
IPW_DEBUG_INFO("Setting channel to %i\n", (int)channel);
priv->channel = channel;
#ifdef CONFIG_IPW2200_MONITOR
if (priv->ieee->iw_mode == IW_MODE_MONITOR) {
int i;
if (priv->status & STATUS_SCANNING) {
IPW_DEBUG_SCAN("Scan abort triggered due to "
"channel change.\n");
ipw_abort_scan(priv);
}
for (i = 1000; i && (priv->status & STATUS_SCANNING); i--)
udelay(10);
if (priv->status & STATUS_SCANNING)
IPW_DEBUG_SCAN("Still scanning...\n");
else
IPW_DEBUG_SCAN("Took %dms to abort current scan\n",
1000 - i);
return 0;
}
#endif
IPW_DEBUG_ASSOC("[re]association triggered due to channel change.\n");
if (!ipw_disassociate(priv))
ipw_associate(priv);
return 0;
}
static int ipw_wx_set_freq(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
const struct libipw_geo *geo = libipw_get_geo(priv->ieee);
struct iw_freq *fwrq = &wrqu->freq;
int ret = 0, i;
u8 channel, flags;
int band;
if (fwrq->m == 0) {
IPW_DEBUG_WX("SET Freq/Channel -> any\n");
mutex_lock(&priv->mutex);
ret = ipw_set_channel(priv, 0);
mutex_unlock(&priv->mutex);
return ret;
}
if (fwrq->e == 1) {
channel = libipw_freq_to_channel(priv->ieee, fwrq->m);
if (channel == 0)
return -EINVAL;
} else
channel = fwrq->m;
if (!(band = libipw_is_valid_channel(priv->ieee, channel)))
return -EINVAL;
if (priv->ieee->iw_mode == IW_MODE_ADHOC) {
i = libipw_channel_to_index(priv->ieee, channel);
if (i == -1)
return -EINVAL;
flags = (band == LIBIPW_24GHZ_BAND) ?
geo->bg[i].flags : geo->a[i].flags;
if (flags & LIBIPW_CH_PASSIVE_ONLY) {
IPW_DEBUG_WX("Invalid Ad-Hoc channel for 802.11a\n");
return -EINVAL;
}
}
IPW_DEBUG_WX("SET Freq/Channel -> %d\n", fwrq->m);
mutex_lock(&priv->mutex);
ret = ipw_set_channel(priv, channel);
mutex_unlock(&priv->mutex);
return ret;
}
static int ipw_wx_get_freq(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
wrqu->freq.e = 0;
mutex_lock(&priv->mutex);
if (priv->config & CFG_STATIC_CHANNEL ||
priv->status & (STATUS_ASSOCIATING | STATUS_ASSOCIATED)) {
int i;
i = libipw_channel_to_index(priv->ieee, priv->channel);
BUG_ON(i == -1);
wrqu->freq.e = 1;
switch (libipw_is_valid_channel(priv->ieee, priv->channel)) {
case LIBIPW_52GHZ_BAND:
wrqu->freq.m = priv->ieee->geo.a[i].freq * 100000;
break;
case LIBIPW_24GHZ_BAND:
wrqu->freq.m = priv->ieee->geo.bg[i].freq * 100000;
break;
default:
BUG();
}
} else
wrqu->freq.m = 0;
mutex_unlock(&priv->mutex);
IPW_DEBUG_WX("GET Freq/Channel -> %d\n", priv->channel);
return 0;
}
static int ipw_wx_set_mode(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
int err = 0;
IPW_DEBUG_WX("Set MODE: %d\n", wrqu->mode);
switch (wrqu->mode) {
#ifdef CONFIG_IPW2200_MONITOR
case IW_MODE_MONITOR:
#endif
case IW_MODE_ADHOC:
case IW_MODE_INFRA:
break;
case IW_MODE_AUTO:
wrqu->mode = IW_MODE_INFRA;
break;
default:
return -EINVAL;
}
if (wrqu->mode == priv->ieee->iw_mode)
return 0;
mutex_lock(&priv->mutex);
ipw_sw_reset(priv, 0);
#ifdef CONFIG_IPW2200_MONITOR
if (priv->ieee->iw_mode == IW_MODE_MONITOR)
priv->net_dev->type = ARPHRD_ETHER;
if (wrqu->mode == IW_MODE_MONITOR)
#ifdef CONFIG_IPW2200_RADIOTAP
priv->net_dev->type = ARPHRD_IEEE80211_RADIOTAP;
#else
priv->net_dev->type = ARPHRD_IEEE80211;
#endif
#endif
free_firmware();
priv->ieee->iw_mode = wrqu->mode;
schedule_work(&priv->adapter_restart);
mutex_unlock(&priv->mutex);
return err;
}
static int ipw_wx_get_mode(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
wrqu->mode = priv->ieee->iw_mode;
IPW_DEBUG_WX("Get MODE -> %d\n", wrqu->mode);
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_get_range(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
struct iw_range *range = (struct iw_range *)extra;
const struct libipw_geo *geo = libipw_get_geo(priv->ieee);
int i = 0, j;
wrqu->data.length = sizeof(*range);
memset(range, 0, sizeof(*range));
range->throughput = 27 * 1000 * 1000;
range->max_qual.qual = 100;
range->max_qual.level = 0;
range->max_qual.noise = 0;
range->max_qual.updated = 7;
range->avg_qual.qual = 70;
range->avg_qual.level = 0;
range->avg_qual.noise = 0;
range->avg_qual.updated = 7;
mutex_lock(&priv->mutex);
range->num_bitrates = min(priv->rates.num_rates, (u8) IW_MAX_BITRATES);
for (i = 0; i < range->num_bitrates; i++)
range->bitrate[i] = (priv->rates.supported_rates[i] & 0x7F) *
500000;
range->max_rts = DEFAULT_RTS_THRESHOLD;
range->min_frag = MIN_FRAG_THRESHOLD;
range->max_frag = MAX_FRAG_THRESHOLD;
range->encoding_size[0] = 5;
range->encoding_size[1] = 13;
range->num_encoding_sizes = 2;
range->max_encoding_tokens = WEP_KEYS;
range->we_version_compiled = WIRELESS_EXT;
range->we_version_source = 18;
i = 0;
if (priv->ieee->mode & (IEEE_B | IEEE_G)) {
for (j = 0; j < geo->bg_channels && i < IW_MAX_FREQUENCIES; j++) {
if ((priv->ieee->iw_mode == IW_MODE_ADHOC) &&
(geo->bg[j].flags & LIBIPW_CH_PASSIVE_ONLY))
continue;
range->freq[i].i = geo->bg[j].channel;
range->freq[i].m = geo->bg[j].freq * 100000;
range->freq[i].e = 1;
i++;
}
}
if (priv->ieee->mode & IEEE_A) {
for (j = 0; j < geo->a_channels && i < IW_MAX_FREQUENCIES; j++) {
if ((priv->ieee->iw_mode == IW_MODE_ADHOC) &&
(geo->a[j].flags & LIBIPW_CH_PASSIVE_ONLY))
continue;
range->freq[i].i = geo->a[j].channel;
range->freq[i].m = geo->a[j].freq * 100000;
range->freq[i].e = 1;
i++;
}
}
range->num_channels = i;
range->num_frequency = i;
mutex_unlock(&priv->mutex);
range->event_capa[0] = (IW_EVENT_CAPA_K_0 |
IW_EVENT_CAPA_MASK(SIOCGIWTHRSPY) |
IW_EVENT_CAPA_MASK(SIOCGIWAP) |
IW_EVENT_CAPA_MASK(SIOCGIWSCAN));
range->event_capa[1] = IW_EVENT_CAPA_K_1;
range->enc_capa = IW_ENC_CAPA_WPA | IW_ENC_CAPA_WPA2 |
IW_ENC_CAPA_CIPHER_TKIP | IW_ENC_CAPA_CIPHER_CCMP;
range->scan_capa = IW_SCAN_CAPA_ESSID | IW_SCAN_CAPA_TYPE;
IPW_DEBUG_WX("GET Range\n");
return 0;
}
static int ipw_wx_set_wap(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
if (wrqu->ap_addr.sa_family != ARPHRD_ETHER)
return -EINVAL;
mutex_lock(&priv->mutex);
if (is_broadcast_ether_addr(wrqu->ap_addr.sa_data) ||
is_zero_ether_addr(wrqu->ap_addr.sa_data)) {
IPW_DEBUG_WX("Setting AP BSSID to ANY\n");
priv->config &= ~CFG_STATIC_BSSID;
IPW_DEBUG_ASSOC("Attempting to associate with new "
"parameters.\n");
ipw_associate(priv);
mutex_unlock(&priv->mutex);
return 0;
}
priv->config |= CFG_STATIC_BSSID;
if (ether_addr_equal(priv->bssid, wrqu->ap_addr.sa_data)) {
IPW_DEBUG_WX("BSSID set to current BSSID.\n");
mutex_unlock(&priv->mutex);
return 0;
}
IPW_DEBUG_WX("Setting mandatory BSSID to %pM\n",
wrqu->ap_addr.sa_data);
memcpy(priv->bssid, wrqu->ap_addr.sa_data, ETH_ALEN);
IPW_DEBUG_ASSOC("[re]association triggered due to BSSID change.\n");
if (!ipw_disassociate(priv))
ipw_associate(priv);
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_get_wap(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
if (priv->config & CFG_STATIC_BSSID ||
priv->status & (STATUS_ASSOCIATED | STATUS_ASSOCIATING)) {
wrqu->ap_addr.sa_family = ARPHRD_ETHER;
memcpy(wrqu->ap_addr.sa_data, priv->bssid, ETH_ALEN);
} else
eth_zero_addr(wrqu->ap_addr.sa_data);
IPW_DEBUG_WX("Getting WAP BSSID: %pM\n",
wrqu->ap_addr.sa_data);
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_set_essid(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
int length;
mutex_lock(&priv->mutex);
if (!wrqu->essid.flags)
{
IPW_DEBUG_WX("Setting ESSID to ANY\n");
ipw_disassociate(priv);
priv->config &= ~CFG_STATIC_ESSID;
ipw_associate(priv);
mutex_unlock(&priv->mutex);
return 0;
}
length = min((int)wrqu->essid.length, IW_ESSID_MAX_SIZE);
priv->config |= CFG_STATIC_ESSID;
if (priv->essid_len == length && !memcmp(priv->essid, extra, length)
&& (priv->status & (STATUS_ASSOCIATED | STATUS_ASSOCIATING))) {
IPW_DEBUG_WX("ESSID set to current ESSID.\n");
mutex_unlock(&priv->mutex);
return 0;
}
IPW_DEBUG_WX("Setting ESSID: '%*pE' (%d)\n", length, extra, length);
priv->essid_len = length;
memcpy(priv->essid, extra, priv->essid_len);
IPW_DEBUG_ASSOC("[re]association triggered due to ESSID change.\n");
if (!ipw_disassociate(priv))
ipw_associate(priv);
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_get_essid(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
if (priv->config & CFG_STATIC_ESSID ||
priv->status & (STATUS_ASSOCIATED | STATUS_ASSOCIATING)) {
IPW_DEBUG_WX("Getting essid: '%*pE'\n",
priv->essid_len, priv->essid);
memcpy(extra, priv->essid, priv->essid_len);
wrqu->essid.length = priv->essid_len;
wrqu->essid.flags = 1;
} else {
IPW_DEBUG_WX("Getting essid: ANY\n");
wrqu->essid.length = 0;
wrqu->essid.flags = 0;
}
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_set_nick(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
IPW_DEBUG_WX("Setting nick to '%s'\n", extra);
if (wrqu->data.length > IW_ESSID_MAX_SIZE)
return -E2BIG;
mutex_lock(&priv->mutex);
wrqu->data.length = min_t(size_t, wrqu->data.length, sizeof(priv->nick));
memset(priv->nick, 0, sizeof(priv->nick));
memcpy(priv->nick, extra, wrqu->data.length);
IPW_DEBUG_TRACE("<<\n");
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_get_nick(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
IPW_DEBUG_WX("Getting nick\n");
mutex_lock(&priv->mutex);
wrqu->data.length = strlen(priv->nick);
memcpy(extra, priv->nick, wrqu->data.length);
wrqu->data.flags = 1;
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_set_sens(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
int err = 0;
IPW_DEBUG_WX("Setting roaming threshold to %d\n", wrqu->sens.value);
IPW_DEBUG_WX("Setting disassociate threshold to %d\n", 3*wrqu->sens.value);
mutex_lock(&priv->mutex);
if (wrqu->sens.fixed == 0)
{
priv->roaming_threshold = IPW_MB_ROAMING_THRESHOLD_DEFAULT;
priv->disassociate_threshold = IPW_MB_DISASSOCIATE_THRESHOLD_DEFAULT;
goto out;
}
if ((wrqu->sens.value > IPW_MB_ROAMING_THRESHOLD_MAX) ||
(wrqu->sens.value < IPW_MB_ROAMING_THRESHOLD_MIN)) {
err = -EINVAL;
goto out;
}
priv->roaming_threshold = wrqu->sens.value;
priv->disassociate_threshold = 3*wrqu->sens.value;
out:
mutex_unlock(&priv->mutex);
return err;
}
static int ipw_wx_get_sens(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
wrqu->sens.fixed = 1;
wrqu->sens.value = priv->roaming_threshold;
mutex_unlock(&priv->mutex);
IPW_DEBUG_WX("GET roaming threshold -> %s %d\n",
wrqu->power.disabled ? "OFF" : "ON", wrqu->power.value);
return 0;
}
static int ipw_wx_set_rate(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
u32 target_rate = wrqu->bitrate.value;
u32 fixed, mask;
if (target_rate == -1) {
fixed = 0;
mask = LIBIPW_DEFAULT_RATES_MASK;
goto apply;
}
mask = 0;
fixed = wrqu->bitrate.fixed;
if (target_rate == 1000000 || !fixed)
mask |= LIBIPW_CCK_RATE_1MB_MASK;
if (target_rate == 1000000)
goto apply;
if (target_rate == 2000000 || !fixed)
mask |= LIBIPW_CCK_RATE_2MB_MASK;
if (target_rate == 2000000)
goto apply;
if (target_rate == 5500000 || !fixed)
mask |= LIBIPW_CCK_RATE_5MB_MASK;
if (target_rate == 5500000)
goto apply;
if (target_rate == 6000000 || !fixed)
mask |= LIBIPW_OFDM_RATE_6MB_MASK;
if (target_rate == 6000000)
goto apply;
if (target_rate == 9000000 || !fixed)
mask |= LIBIPW_OFDM_RATE_9MB_MASK;
if (target_rate == 9000000)
goto apply;
if (target_rate == 11000000 || !fixed)
mask |= LIBIPW_CCK_RATE_11MB_MASK;
if (target_rate == 11000000)
goto apply;
if (target_rate == 12000000 || !fixed)
mask |= LIBIPW_OFDM_RATE_12MB_MASK;
if (target_rate == 12000000)
goto apply;
if (target_rate == 18000000 || !fixed)
mask |= LIBIPW_OFDM_RATE_18MB_MASK;
if (target_rate == 18000000)
goto apply;
if (target_rate == 24000000 || !fixed)
mask |= LIBIPW_OFDM_RATE_24MB_MASK;
if (target_rate == 24000000)
goto apply;
if (target_rate == 36000000 || !fixed)
mask |= LIBIPW_OFDM_RATE_36MB_MASK;
if (target_rate == 36000000)
goto apply;
if (target_rate == 48000000 || !fixed)
mask |= LIBIPW_OFDM_RATE_48MB_MASK;
if (target_rate == 48000000)
goto apply;
if (target_rate == 54000000 || !fixed)
mask |= LIBIPW_OFDM_RATE_54MB_MASK;
if (target_rate == 54000000)
goto apply;
IPW_DEBUG_WX("invalid rate specified, returning error\n");
return -EINVAL;
apply:
IPW_DEBUG_WX("Setting rate mask to 0x%08X [%s]\n",
mask, fixed ? "fixed" : "sub-rates");
mutex_lock(&priv->mutex);
if (mask == LIBIPW_DEFAULT_RATES_MASK) {
priv->config &= ~CFG_FIXED_RATE;
ipw_set_fixed_rate(priv, priv->ieee->mode);
} else
priv->config |= CFG_FIXED_RATE;
if (priv->rates_mask == mask) {
IPW_DEBUG_WX("Mask set to current mask.\n");
mutex_unlock(&priv->mutex);
return 0;
}
priv->rates_mask = mask;
IPW_DEBUG_ASSOC("[re]association triggered due to rates change.\n");
if (!ipw_disassociate(priv))
ipw_associate(priv);
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_get_rate(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
wrqu->bitrate.value = priv->last_rate;
wrqu->bitrate.fixed = (priv->config & CFG_FIXED_RATE) ? 1 : 0;
mutex_unlock(&priv->mutex);
IPW_DEBUG_WX("GET Rate -> %d\n", wrqu->bitrate.value);
return 0;
}
static int ipw_wx_set_rts(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
if (wrqu->rts.disabled || !wrqu->rts.fixed)
priv->rts_threshold = DEFAULT_RTS_THRESHOLD;
else {
if (wrqu->rts.value < MIN_RTS_THRESHOLD ||
wrqu->rts.value > MAX_RTS_THRESHOLD) {
mutex_unlock(&priv->mutex);
return -EINVAL;
}
priv->rts_threshold = wrqu->rts.value;
}
ipw_send_rts_threshold(priv, priv->rts_threshold);
mutex_unlock(&priv->mutex);
IPW_DEBUG_WX("SET RTS Threshold -> %d\n", priv->rts_threshold);
return 0;
}
static int ipw_wx_get_rts(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
wrqu->rts.value = priv->rts_threshold;
wrqu->rts.fixed = 0;
wrqu->rts.disabled = (wrqu->rts.value == DEFAULT_RTS_THRESHOLD);
mutex_unlock(&priv->mutex);
IPW_DEBUG_WX("GET RTS Threshold -> %d\n", wrqu->rts.value);
return 0;
}
static int ipw_wx_set_txpow(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
int err = 0;
mutex_lock(&priv->mutex);
if (ipw_radio_kill_sw(priv, wrqu->power.disabled)) {
err = -EINPROGRESS;
goto out;
}
if (!wrqu->power.fixed)
wrqu->power.value = IPW_TX_POWER_DEFAULT;
if (wrqu->power.flags != IW_TXPOW_DBM) {
err = -EINVAL;
goto out;
}
if ((wrqu->power.value > IPW_TX_POWER_MAX) ||
(wrqu->power.value < IPW_TX_POWER_MIN)) {
err = -EINVAL;
goto out;
}
priv->tx_power = wrqu->power.value;
err = ipw_set_tx_power(priv);
out:
mutex_unlock(&priv->mutex);
return err;
}
static int ipw_wx_get_txpow(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
wrqu->power.value = priv->tx_power;
wrqu->power.fixed = 1;
wrqu->power.flags = IW_TXPOW_DBM;
wrqu->power.disabled = (priv->status & STATUS_RF_KILL_MASK) ? 1 : 0;
mutex_unlock(&priv->mutex);
IPW_DEBUG_WX("GET TX Power -> %s %d\n",
wrqu->power.disabled ? "OFF" : "ON", wrqu->power.value);
return 0;
}
static int ipw_wx_set_frag(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
if (wrqu->frag.disabled || !wrqu->frag.fixed)
priv->ieee->fts = DEFAULT_FTS;
else {
if (wrqu->frag.value < MIN_FRAG_THRESHOLD ||
wrqu->frag.value > MAX_FRAG_THRESHOLD) {
mutex_unlock(&priv->mutex);
return -EINVAL;
}
priv->ieee->fts = wrqu->frag.value & ~0x1;
}
ipw_send_frag_threshold(priv, wrqu->frag.value);
mutex_unlock(&priv->mutex);
IPW_DEBUG_WX("SET Frag Threshold -> %d\n", wrqu->frag.value);
return 0;
}
static int ipw_wx_get_frag(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
wrqu->frag.value = priv->ieee->fts;
wrqu->frag.fixed = 0;
wrqu->frag.disabled = (wrqu->frag.value == DEFAULT_FTS);
mutex_unlock(&priv->mutex);
IPW_DEBUG_WX("GET Frag Threshold -> %d\n", wrqu->frag.value);
return 0;
}
static int ipw_wx_set_retry(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
if (wrqu->retry.flags & IW_RETRY_LIFETIME || wrqu->retry.disabled)
return -EINVAL;
if (!(wrqu->retry.flags & IW_RETRY_LIMIT))
return 0;
if (wrqu->retry.value < 0 || wrqu->retry.value >= 255)
return -EINVAL;
mutex_lock(&priv->mutex);
if (wrqu->retry.flags & IW_RETRY_SHORT)
priv->short_retry_limit = (u8) wrqu->retry.value;
else if (wrqu->retry.flags & IW_RETRY_LONG)
priv->long_retry_limit = (u8) wrqu->retry.value;
else {
priv->short_retry_limit = (u8) wrqu->retry.value;
priv->long_retry_limit = (u8) wrqu->retry.value;
}
ipw_send_retry_limit(priv, priv->short_retry_limit,
priv->long_retry_limit);
mutex_unlock(&priv->mutex);
IPW_DEBUG_WX("SET retry limit -> short:%d long:%d\n",
priv->short_retry_limit, priv->long_retry_limit);
return 0;
}
static int ipw_wx_get_retry(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
wrqu->retry.disabled = 0;
if ((wrqu->retry.flags & IW_RETRY_TYPE) == IW_RETRY_LIFETIME) {
mutex_unlock(&priv->mutex);
return -EINVAL;
}
if (wrqu->retry.flags & IW_RETRY_LONG) {
wrqu->retry.flags = IW_RETRY_LIMIT | IW_RETRY_LONG;
wrqu->retry.value = priv->long_retry_limit;
} else if (wrqu->retry.flags & IW_RETRY_SHORT) {
wrqu->retry.flags = IW_RETRY_LIMIT | IW_RETRY_SHORT;
wrqu->retry.value = priv->short_retry_limit;
} else {
wrqu->retry.flags = IW_RETRY_LIMIT;
wrqu->retry.value = priv->short_retry_limit;
}
mutex_unlock(&priv->mutex);
IPW_DEBUG_WX("GET retry -> %d\n", wrqu->retry.value);
return 0;
}
static int ipw_wx_set_scan(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
struct iw_scan_req *req = (struct iw_scan_req *)extra;
struct delayed_work *work = NULL;
mutex_lock(&priv->mutex);
priv->user_requested_scan = 1;
if (wrqu->data.length == sizeof(struct iw_scan_req)) {
if (wrqu->data.flags & IW_SCAN_THIS_ESSID) {
int len = min((int)req->essid_len,
(int)sizeof(priv->direct_scan_ssid));
memcpy(priv->direct_scan_ssid, req->essid, len);
priv->direct_scan_ssid_len = len;
work = &priv->request_direct_scan;
} else if (req->scan_type == IW_SCAN_TYPE_PASSIVE) {
work = &priv->request_passive_scan;
}
} else {
work = &priv->request_scan;
}
mutex_unlock(&priv->mutex);
IPW_DEBUG_WX("Start scan\n");
schedule_delayed_work(work, 0);
return 0;
}
static int ipw_wx_get_scan(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
return libipw_wx_get_scan(priv->ieee, info, wrqu, extra);
}
static int ipw_wx_set_encode(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *key)
{
struct ipw_priv *priv = libipw_priv(dev);
int ret;
u32 cap = priv->capability;
mutex_lock(&priv->mutex);
ret = libipw_wx_set_encode(priv->ieee, info, wrqu, key);
if (cap != priv->capability &&
priv->ieee->iw_mode == IW_MODE_ADHOC &&
priv->status & STATUS_ASSOCIATED)
ipw_disassociate(priv);
mutex_unlock(&priv->mutex);
return ret;
}
static int ipw_wx_get_encode(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *key)
{
struct ipw_priv *priv = libipw_priv(dev);
return libipw_wx_get_encode(priv->ieee, info, wrqu, key);
}
static int ipw_wx_set_power(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
int err;
mutex_lock(&priv->mutex);
if (wrqu->power.disabled) {
priv->power_mode = IPW_POWER_LEVEL(priv->power_mode);
err = ipw_send_power_mode(priv, IPW_POWER_MODE_CAM);
if (err) {
IPW_DEBUG_WX("failed setting power mode.\n");
mutex_unlock(&priv->mutex);
return err;
}
IPW_DEBUG_WX("SET Power Management Mode -> off\n");
mutex_unlock(&priv->mutex);
return 0;
}
switch (wrqu->power.flags & IW_POWER_MODE) {
case IW_POWER_ON:
case IW_POWER_MODE:
case IW_POWER_ALL_R:
break;
default:
IPW_DEBUG_WX("SET PM Mode: %X not supported.\n",
wrqu->power.flags);
mutex_unlock(&priv->mutex);
return -EOPNOTSUPP;
}
if (IPW_POWER_LEVEL(priv->power_mode) == IPW_POWER_AC)
priv->power_mode = IPW_POWER_ENABLED | IPW_POWER_BATTERY;
else
priv->power_mode = IPW_POWER_ENABLED | priv->power_mode;
err = ipw_send_power_mode(priv, IPW_POWER_LEVEL(priv->power_mode));
if (err) {
IPW_DEBUG_WX("failed setting power mode.\n");
mutex_unlock(&priv->mutex);
return err;
}
IPW_DEBUG_WX("SET Power Management Mode -> 0x%02X\n", priv->power_mode);
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_get_power(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
if (!(priv->power_mode & IPW_POWER_ENABLED))
wrqu->power.disabled = 1;
else
wrqu->power.disabled = 0;
mutex_unlock(&priv->mutex);
IPW_DEBUG_WX("GET Power Management Mode -> %02X\n", priv->power_mode);
return 0;
}
static int ipw_wx_set_powermode(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
int mode = *(int *)extra;
int err;
mutex_lock(&priv->mutex);
if ((mode < 1) || (mode > IPW_POWER_LIMIT))
mode = IPW_POWER_AC;
if (IPW_POWER_LEVEL(priv->power_mode) != mode) {
err = ipw_send_power_mode(priv, mode);
if (err) {
IPW_DEBUG_WX("failed setting power mode.\n");
mutex_unlock(&priv->mutex);
return err;
}
priv->power_mode = IPW_POWER_ENABLED | mode;
}
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_get_powermode(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
int level = IPW_POWER_LEVEL(priv->power_mode);
char *p = extra;
p += snprintf(p, MAX_WX_STRING, "Power save level: %d ", level);
switch (level) {
case IPW_POWER_AC:
p += snprintf(p, MAX_WX_STRING - (p - extra), "(AC)");
break;
case IPW_POWER_BATTERY:
p += snprintf(p, MAX_WX_STRING - (p - extra), "(BATTERY)");
break;
default:
p += snprintf(p, MAX_WX_STRING - (p - extra),
"(Timeout %dms, Period %dms)",
timeout_duration[level - 1] / 1000,
period_duration[level - 1] / 1000);
}
if (!(priv->power_mode & IPW_POWER_ENABLED))
p += snprintf(p, MAX_WX_STRING - (p - extra), " OFF");
wrqu->data.length = p - extra + 1;
return 0;
}
static int ipw_wx_set_wireless_mode(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
int mode = *(int *)extra;
u8 band = 0, modulation = 0;
if (mode == 0 || mode & ~IEEE_MODE_MASK) {
IPW_WARNING("Attempt to set invalid wireless mode: %d\n", mode);
return -EINVAL;
}
mutex_lock(&priv->mutex);
if (priv->adapter == IPW_2915ABG) {
priv->ieee->abg_true = 1;
if (mode & IEEE_A) {
band |= LIBIPW_52GHZ_BAND;
modulation |= LIBIPW_OFDM_MODULATION;
} else
priv->ieee->abg_true = 0;
} else {
if (mode & IEEE_A) {
IPW_WARNING("Attempt to set 2200BG into "
"802.11a mode\n");
mutex_unlock(&priv->mutex);
return -EINVAL;
}
priv->ieee->abg_true = 0;
}
if (mode & IEEE_B) {
band |= LIBIPW_24GHZ_BAND;
modulation |= LIBIPW_CCK_MODULATION;
} else
priv->ieee->abg_true = 0;
if (mode & IEEE_G) {
band |= LIBIPW_24GHZ_BAND;
modulation |= LIBIPW_OFDM_MODULATION;
} else
priv->ieee->abg_true = 0;
priv->ieee->mode = mode;
priv->ieee->freq_band = band;
priv->ieee->modulation = modulation;
init_supported_rates(priv, &priv->rates);
IPW_DEBUG_ASSOC("[re]association triggered due to mode change.\n");
if (!ipw_disassociate(priv)) {
ipw_send_supported_rates(priv, &priv->rates);
ipw_associate(priv);
}
ipw_led_band_on(priv);
IPW_DEBUG_WX("PRIV SET MODE: %c%c%c\n",
mode & IEEE_A ? 'a' : '.',
mode & IEEE_B ? 'b' : '.', mode & IEEE_G ? 'g' : '.');
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_get_wireless_mode(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
switch (priv->ieee->mode) {
case IEEE_A:
strncpy(extra, "802.11a (1)", MAX_WX_STRING);
break;
case IEEE_B:
strncpy(extra, "802.11b (2)", MAX_WX_STRING);
break;
case IEEE_A | IEEE_B:
strncpy(extra, "802.11ab (3)", MAX_WX_STRING);
break;
case IEEE_G:
strncpy(extra, "802.11g (4)", MAX_WX_STRING);
break;
case IEEE_A | IEEE_G:
strncpy(extra, "802.11ag (5)", MAX_WX_STRING);
break;
case IEEE_B | IEEE_G:
strncpy(extra, "802.11bg (6)", MAX_WX_STRING);
break;
case IEEE_A | IEEE_B | IEEE_G:
strncpy(extra, "802.11abg (7)", MAX_WX_STRING);
break;
default:
strncpy(extra, "unknown", MAX_WX_STRING);
break;
}
extra[MAX_WX_STRING - 1] = '\0';
IPW_DEBUG_WX("PRIV GET MODE: %s\n", extra);
wrqu->data.length = strlen(extra) + 1;
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_set_preamble(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
int mode = *(int *)extra;
mutex_lock(&priv->mutex);
if (mode == 1) {
if (!(priv->config & CFG_PREAMBLE_LONG)) {
priv->config |= CFG_PREAMBLE_LONG;
IPW_DEBUG_ASSOC
("[re]association triggered due to preamble change.\n");
if (!ipw_disassociate(priv))
ipw_associate(priv);
}
goto done;
}
if (mode == 0) {
priv->config &= ~CFG_PREAMBLE_LONG;
goto done;
}
mutex_unlock(&priv->mutex);
return -EINVAL;
done:
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_get_preamble(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
mutex_lock(&priv->mutex);
if (priv->config & CFG_PREAMBLE_LONG)
snprintf(wrqu->name, IFNAMSIZ, "long (1)");
else
snprintf(wrqu->name, IFNAMSIZ, "auto (0)");
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_set_monitor(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
int *parms = (int *)extra;
int enable = (parms[0] > 0);
mutex_lock(&priv->mutex);
IPW_DEBUG_WX("SET MONITOR: %d %d\n", enable, parms[1]);
if (enable) {
if (priv->ieee->iw_mode != IW_MODE_MONITOR) {
#ifdef CONFIG_IPW2200_RADIOTAP
priv->net_dev->type = ARPHRD_IEEE80211_RADIOTAP;
#else
priv->net_dev->type = ARPHRD_IEEE80211;
#endif
schedule_work(&priv->adapter_restart);
}
ipw_set_channel(priv, parms[1]);
} else {
if (priv->ieee->iw_mode != IW_MODE_MONITOR) {
mutex_unlock(&priv->mutex);
return 0;
}
priv->net_dev->type = ARPHRD_ETHER;
schedule_work(&priv->adapter_restart);
}
mutex_unlock(&priv->mutex);
return 0;
}
static int ipw_wx_reset(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
IPW_DEBUG_WX("RESET\n");
schedule_work(&priv->adapter_restart);
return 0;
}
static int ipw_wx_sw_reset(struct net_device *dev,
struct iw_request_info *info,
union iwreq_data *wrqu, char *extra)
{
struct ipw_priv *priv = libipw_priv(dev);
union iwreq_data wrqu_sec = {
.encoding = {
.flags = IW_ENCODE_DISABLED,
},
};
int ret;
IPW_DEBUG_WX("SW_RESET\n");
mutex_lock(&priv->mutex);
ret = ipw_sw_reset(priv, 2);
if (!ret) {
free_firmware();
ipw_adapter_restart(priv);
}
ipw_radio_kill_sw(priv, priv->status & STATUS_RF_KILL_SW);
mutex_unlock(&priv->mutex);
libipw_wx_set_encode(priv->ieee, info, &wrqu_sec, NULL);
mutex_lock(&priv->mutex);
if (!(priv->status & STATUS_RF_KILL_MASK)) {
IPW_DEBUG_ASSOC("[re]association triggered due to sw "
"reset.\n");
if (!ipw_disassociate(priv))
ipw_associate(priv);
}
mutex_unlock(&priv->mutex);
return 0;
}
static struct iw_statistics *ipw_get_wireless_stats(struct net_device *dev)
{
struct ipw_priv *priv = libipw_priv(dev);
struct iw_statistics *wstats;
wstats = &priv->wstats;
if (!(priv->status & STATUS_ASSOCIATED)) {
wstats->miss.beacon = 0;
wstats->discard.retries = 0;
wstats->qual.qual = 0;
wstats->qual.level = 0;
wstats->qual.noise = 0;
wstats->qual.updated = 7;
wstats->qual.updated |= IW_QUAL_NOISE_INVALID |
IW_QUAL_QUAL_INVALID | IW_QUAL_LEVEL_INVALID;
return wstats;
}
wstats->qual.qual = priv->quality;
wstats->qual.level = priv->exp_avg_rssi;
wstats->qual.noise = priv->exp_avg_noise;
wstats->qual.updated = IW_QUAL_QUAL_UPDATED | IW_QUAL_LEVEL_UPDATED |
IW_QUAL_NOISE_UPDATED | IW_QUAL_DBM;
wstats->miss.beacon = average_value(&priv->average_missed_beacons);
wstats->discard.retries = priv->last_tx_failures;
wstats->discard.code = priv->ieee->ieee_stats.rx_discards_undecryptable;
return wstats;
}
static void init_sys_config(struct ipw_sys_config *sys_config)
{
memset(sys_config, 0, sizeof(struct ipw_sys_config));
sys_config->bt_coexistence = 0;
sys_config->answer_broadcast_ssid_probe = 0;
sys_config->accept_all_data_frames = 0;
sys_config->accept_non_directed_frames = 1;
sys_config->exclude_unicast_unencrypted = 0;
sys_config->disable_unicast_decryption = 1;
sys_config->exclude_multicast_unencrypted = 0;
sys_config->disable_multicast_decryption = 1;
if (antenna < CFG_SYS_ANTENNA_BOTH || antenna > CFG_SYS_ANTENNA_B)
antenna = CFG_SYS_ANTENNA_BOTH;
sys_config->antenna_diversity = antenna;
sys_config->pass_crc_to_host = 0;
sys_config->dot11g_auto_detection = 0;
sys_config->enable_cts_to_self = 0;
sys_config->bt_coexist_collision_thr = 0;
sys_config->pass_noise_stats_to_host = 1;
sys_config->silence_threshold = 0x1e;
}
static int ipw_net_open(struct net_device *dev)
{
IPW_DEBUG_INFO("dev->open\n");
netif_start_queue(dev);
return 0;
}
static int ipw_net_stop(struct net_device *dev)
{
IPW_DEBUG_INFO("dev->close\n");
netif_stop_queue(dev);
return 0;
}
static int ipw_tx_skb(struct ipw_priv *priv, struct libipw_txb *txb,
int pri)
{
struct libipw_hdr_3addrqos *hdr = (struct libipw_hdr_3addrqos *)
txb->fragments[0]->data;
int i = 0;
struct tfd_frame *tfd;
#ifdef CONFIG_IPW2200_QOS
int tx_id = ipw_get_tx_queue_number(priv, pri);
struct clx2_tx_queue *txq = &priv->txq[tx_id];
#else
struct clx2_tx_queue *txq = &priv->txq[0];
#endif
struct clx2_queue *q = &txq->q;
u8 id, hdr_len, unicast;
int fc;
if (!(priv->status & STATUS_ASSOCIATED))
goto drop;
hdr_len = libipw_get_hdrlen(le16_to_cpu(hdr->frame_ctl));
switch (priv->ieee->iw_mode) {
case IW_MODE_ADHOC:
unicast = !is_multicast_ether_addr(hdr->addr1);
id = ipw_find_station(priv, hdr->addr1);
if (id == IPW_INVALID_STATION) {
id = ipw_add_station(priv, hdr->addr1);
if (id == IPW_INVALID_STATION) {
IPW_WARNING("Attempt to send data to "
"invalid cell: %pM\n",
hdr->addr1);
goto drop;
}
}
break;
case IW_MODE_INFRA:
default:
unicast = !is_multicast_ether_addr(hdr->addr3);
id = 0;
break;
}
tfd = &txq->bd[q->first_empty];
txq->txb[q->first_empty] = txb;
memset(tfd, 0, sizeof(*tfd));
tfd->u.data.station_number = id;
tfd->control_flags.message_type = TX_FRAME_TYPE;
tfd->control_flags.control_bits = TFD_NEED_IRQ_MASK;
tfd->u.data.cmd_id = DINO_CMD_TX;
tfd->u.data.len = cpu_to_le16(txb->payload_size);
if (priv->assoc_request.ieee_mode == IPW_B_MODE)
tfd->u.data.tx_flags_ext |= DCT_FLAG_EXT_MODE_CCK;
else
tfd->u.data.tx_flags_ext |= DCT_FLAG_EXT_MODE_OFDM;
if (priv->assoc_request.preamble_length == DCT_FLAG_SHORT_PREAMBLE)
tfd->u.data.tx_flags |= DCT_FLAG_SHORT_PREAMBLE;
fc = le16_to_cpu(hdr->frame_ctl);
hdr->frame_ctl = cpu_to_le16(fc & ~IEEE80211_FCTL_MOREFRAGS);
memcpy(&tfd->u.data.tfd.tfd_24.mchdr, hdr, hdr_len);
if (likely(unicast))
tfd->u.data.tx_flags |= DCT_FLAG_ACK_REQD;
if (txb->encrypted && !priv->ieee->host_encrypt) {
switch (priv->ieee->sec.level) {
case SEC_LEVEL_3:
tfd->u.data.tfd.tfd_24.mchdr.frame_ctl |=
cpu_to_le16(IEEE80211_FCTL_PROTECTED);
if (!unicast)
tfd->u.data.tx_flags |= DCT_FLAG_ACK_REQD;
tfd->u.data.tx_flags &= ~DCT_FLAG_NO_WEP;
tfd->u.data.tx_flags_ext |= DCT_FLAG_EXT_SECURITY_CCM;
tfd->u.data.key_index = 0;
tfd->u.data.key_index |= DCT_WEP_INDEX_USE_IMMEDIATE;
break;
case SEC_LEVEL_2:
tfd->u.data.tfd.tfd_24.mchdr.frame_ctl |=
cpu_to_le16(IEEE80211_FCTL_PROTECTED);
tfd->u.data.tx_flags &= ~DCT_FLAG_NO_WEP;
tfd->u.data.tx_flags_ext |= DCT_FLAG_EXT_SECURITY_TKIP;
tfd->u.data.key_index = DCT_WEP_INDEX_USE_IMMEDIATE;
break;
case SEC_LEVEL_1:
tfd->u.data.tfd.tfd_24.mchdr.frame_ctl |=
cpu_to_le16(IEEE80211_FCTL_PROTECTED);
tfd->u.data.key_index = priv->ieee->crypt_info.tx_keyidx;
if (priv->ieee->sec.key_sizes[priv->ieee->crypt_info.tx_keyidx] <=
40)
tfd->u.data.key_index |= DCT_WEP_KEY_64Bit;
else
tfd->u.data.key_index |= DCT_WEP_KEY_128Bit;
break;
case SEC_LEVEL_0:
break;
default:
printk(KERN_ERR "Unknown security level %d\n",
priv->ieee->sec.level);
break;
}
} else
tfd->u.data.tx_flags |= DCT_FLAG_NO_WEP;
#ifdef CONFIG_IPW2200_QOS
if (fc & IEEE80211_STYPE_QOS_DATA)
ipw_qos_set_tx_queue_command(priv, pri, &(tfd->u.data));
#endif
tfd->u.data.num_chunks = cpu_to_le32(min((u8) (NUM_TFD_CHUNKS - 2),
txb->nr_frags));
IPW_DEBUG_FRAG("%i fragments being sent as %i chunks.\n",
txb->nr_frags, le32_to_cpu(tfd->u.data.num_chunks));
for (i = 0; i < le32_to_cpu(tfd->u.data.num_chunks); i++) {
IPW_DEBUG_FRAG("Adding fragment %i of %i (%d bytes).\n",
i, le32_to_cpu(tfd->u.data.num_chunks),
txb->fragments[i]->len - hdr_len);
IPW_DEBUG_TX("Dumping TX packet frag %i of %i (%d bytes):\n",
i, tfd->u.data.num_chunks,
txb->fragments[i]->len - hdr_len);
printk_buf(IPW_DL_TX, txb->fragments[i]->data + hdr_len,
txb->fragments[i]->len - hdr_len);
tfd->u.data.chunk_ptr[i] =
cpu_to_le32(pci_map_single
(priv->pci_dev,
txb->fragments[i]->data + hdr_len,
txb->fragments[i]->len - hdr_len,
PCI_DMA_TODEVICE));
tfd->u.data.chunk_len[i] =
cpu_to_le16(txb->fragments[i]->len - hdr_len);
}
if (i != txb->nr_frags) {
struct sk_buff *skb;
u16 remaining_bytes = 0;
int j;
for (j = i; j < txb->nr_frags; j++)
remaining_bytes += txb->fragments[j]->len - hdr_len;
printk(KERN_INFO "Trying to reallocate for %d bytes\n",
remaining_bytes);
skb = alloc_skb(remaining_bytes, GFP_ATOMIC);
if (skb != NULL) {
tfd->u.data.chunk_len[i] = cpu_to_le16(remaining_bytes);
for (j = i; j < txb->nr_frags; j++) {
int size = txb->fragments[j]->len - hdr_len;
printk(KERN_INFO "Adding frag %d %d...\n",
j, size);
skb_put_data(skb,
txb->fragments[j]->data + hdr_len,
size);
}
dev_kfree_skb_any(txb->fragments[i]);
txb->fragments[i] = skb;
tfd->u.data.chunk_ptr[i] =
cpu_to_le32(pci_map_single
(priv->pci_dev, skb->data,
remaining_bytes,
PCI_DMA_TODEVICE));
le32_add_cpu(&tfd->u.data.num_chunks, 1);
}
}
q->first_empty = ipw_queue_inc_wrap(q->first_empty, q->n_bd);
ipw_write32(priv, q->reg_w, q->first_empty);
if (ipw_tx_queue_space(q) < q->high_mark)
netif_stop_queue(priv->net_dev);
return NETDEV_TX_OK;
drop:
IPW_DEBUG_DROP("Silently dropping Tx packet.\n");
libipw_txb_free(txb);
return NETDEV_TX_OK;
}
static int ipw_net_is_queue_full(struct net_device *dev, int pri)
{
struct ipw_priv *priv = libipw_priv(dev);
#ifdef CONFIG_IPW2200_QOS
int tx_id = ipw_get_tx_queue_number(priv, pri);
struct clx2_tx_queue *txq = &priv->txq[tx_id];
#else
struct clx2_tx_queue *txq = &priv->txq[0];
#endif
if (ipw_tx_queue_space(&txq->q) < txq->q.high_mark)
return 1;
return 0;
}
static void ipw_handle_promiscuous_tx(struct ipw_priv *priv,
struct libipw_txb *txb)
{
struct libipw_rx_stats dummystats;
struct ieee80211_hdr *hdr;
u8 n;
u16 filter = priv->prom_priv->filter;
int hdr_only = 0;
if (filter & IPW_PROM_NO_TX)
return;
memset(&dummystats, 0, sizeof(dummystats));
hdr = (void *)txb->fragments[0]->data;
if (libipw_is_management(le16_to_cpu(hdr->frame_control))) {
if (filter & IPW_PROM_NO_MGMT)
return;
if (filter & IPW_PROM_MGMT_HEADER_ONLY)
hdr_only = 1;
} else if (libipw_is_control(le16_to_cpu(hdr->frame_control))) {
if (filter & IPW_PROM_NO_CTL)
return;
if (filter & IPW_PROM_CTL_HEADER_ONLY)
hdr_only = 1;
} else if (libipw_is_data(le16_to_cpu(hdr->frame_control))) {
if (filter & IPW_PROM_NO_DATA)
return;
if (filter & IPW_PROM_DATA_HEADER_ONLY)
hdr_only = 1;
}
for(n=0; n<txb->nr_frags; ++n) {
struct sk_buff *src = txb->fragments[n];
struct sk_buff *dst;
struct ieee80211_radiotap_header *rt_hdr;
int len;
if (hdr_only) {
hdr = (void *)src->data;
len = libipw_get_hdrlen(le16_to_cpu(hdr->frame_control));
} else
len = src->len;
dst = alloc_skb(len + sizeof(*rt_hdr) + sizeof(u16)*2, GFP_ATOMIC);
if (!dst)
continue;
rt_hdr = skb_put(dst, sizeof(*rt_hdr));
rt_hdr->it_version = PKTHDR_RADIOTAP_VERSION;
rt_hdr->it_pad = 0;
rt_hdr->it_present = 0;
rt_hdr->it_present |= cpu_to_le32(1 << IEEE80211_RADIOTAP_CHANNEL);
*(__le16*)skb_put(dst, sizeof(u16)) = cpu_to_le16(
ieee80211chan2mhz(priv->channel));
if (priv->channel > 14)
*(__le16*)skb_put(dst, sizeof(u16)) =
cpu_to_le16(IEEE80211_CHAN_OFDM |
IEEE80211_CHAN_5GHZ);
else if (priv->ieee->mode == IEEE_B)
*(__le16*)skb_put(dst, sizeof(u16)) =
cpu_to_le16(IEEE80211_CHAN_CCK |
IEEE80211_CHAN_2GHZ);
else
*(__le16*)skb_put(dst, sizeof(u16)) =
cpu_to_le16(IEEE80211_CHAN_OFDM |
IEEE80211_CHAN_2GHZ);
rt_hdr->it_len = cpu_to_le16(dst->len);
skb_copy_from_linear_data(src, skb_put(dst, len), len);
if (!libipw_rx(priv->prom_priv->ieee, dst, &dummystats))
dev_kfree_skb_any(dst);
}
}
static netdev_tx_t ipw_net_hard_start_xmit(struct libipw_txb *txb,
struct net_device *dev, int pri)
{
struct ipw_priv *priv = libipw_priv(dev);
unsigned long flags;
netdev_tx_t ret;
IPW_DEBUG_TX("dev->xmit(%d bytes)\n", txb->payload_size);
spin_lock_irqsave(&priv->lock, flags);
#ifdef CONFIG_IPW2200_PROMISCUOUS
if (rtap_iface && netif_running(priv->prom_net_dev))
ipw_handle_promiscuous_tx(priv, txb);
#endif
ret = ipw_tx_skb(priv, txb, pri);
if (ret == NETDEV_TX_OK)
__ipw_led_activity_on(priv);
spin_unlock_irqrestore(&priv->lock, flags);
return ret;
}
static void ipw_net_set_multicast_list(struct net_device *dev)
{
}
static int ipw_net_set_mac_address(struct net_device *dev, void *p)
{
struct ipw_priv *priv = libipw_priv(dev);
struct sockaddr *addr = p;
if (!is_valid_ether_addr(addr->sa_data))
return -EADDRNOTAVAIL;
mutex_lock(&priv->mutex);
priv->config |= CFG_CUSTOM_MAC;
memcpy(priv->mac_addr, addr->sa_data, ETH_ALEN);
printk(KERN_INFO "%s: Setting MAC to %pM\n",
priv->net_dev->name, priv->mac_addr);
schedule_work(&priv->adapter_restart);
mutex_unlock(&priv->mutex);
return 0;
}
static void ipw_ethtool_get_drvinfo(struct net_device *dev,
struct ethtool_drvinfo *info)
{
struct ipw_priv *p = libipw_priv(dev);
char vers[64];
char date[32];
u32 len;
strlcpy(info->driver, DRV_NAME, sizeof(info->driver));
strlcpy(info->version, DRV_VERSION, sizeof(info->version));
len = sizeof(vers);
ipw_get_ordinal(p, IPW_ORD_STAT_FW_VERSION, vers, &len);
len = sizeof(date);
ipw_get_ordinal(p, IPW_ORD_STAT_FW_DATE, date, &len);
snprintf(info->fw_version, sizeof(info->fw_version), "%s (%s)",
vers, date);
strlcpy(info->bus_info, pci_name(p->pci_dev),
sizeof(info->bus_info));
}
static u32 ipw_ethtool_get_link(struct net_device *dev)
{
struct ipw_priv *priv = libipw_priv(dev);
return (priv->status & STATUS_ASSOCIATED) != 0;
}
static int ipw_ethtool_get_eeprom_len(struct net_device *dev)
{
return IPW_EEPROM_IMAGE_SIZE;
}
static int ipw_ethtool_get_eeprom(struct net_device *dev,
struct ethtool_eeprom *eeprom, u8 * bytes)
{
struct ipw_priv *p = libipw_priv(dev);
if (eeprom->offset + eeprom->len > IPW_EEPROM_IMAGE_SIZE)
return -EINVAL;
mutex_lock(&p->mutex);
memcpy(bytes, &p->eeprom[eeprom->offset], eeprom->len);
mutex_unlock(&p->mutex);
return 0;
}
static int ipw_ethtool_set_eeprom(struct net_device *dev,
struct ethtool_eeprom *eeprom, u8 * bytes)
{
struct ipw_priv *p = libipw_priv(dev);
int i;
if (eeprom->offset + eeprom->len > IPW_EEPROM_IMAGE_SIZE)
return -EINVAL;
mutex_lock(&p->mutex);
memcpy(&p->eeprom[eeprom->offset], bytes, eeprom->len);
for (i = 0; i < IPW_EEPROM_IMAGE_SIZE; i++)
ipw_write8(p, i + IPW_EEPROM_DATA, p->eeprom[i]);
mutex_unlock(&p->mutex);
return 0;
}
static irqreturn_t ipw_isr(int irq, void *data)
{
struct ipw_priv *priv = data;
u32 inta, inta_mask;
if (!priv)
return IRQ_NONE;
spin_lock(&priv->irq_lock);
if (!(priv->status & STATUS_INT_ENABLED)) {
goto none;
}
inta = ipw_read32(priv, IPW_INTA_RW);
inta_mask = ipw_read32(priv, IPW_INTA_MASK_R);
if (inta == 0xFFFFFFFF) {
IPW_WARNING("IRQ INTA == 0xFFFFFFFF\n");
goto none;
}
if (!(inta & (IPW_INTA_MASK_ALL & inta_mask))) {
goto none;
}
__ipw_disable_interrupts(priv);
inta &= (IPW_INTA_MASK_ALL & inta_mask);
ipw_write32(priv, IPW_INTA_RW, inta);
priv->isr_inta = inta;
tasklet_schedule(&priv->irq_tasklet);
spin_unlock(&priv->irq_lock);
return IRQ_HANDLED;
none:
spin_unlock(&priv->irq_lock);
return IRQ_NONE;
}
static void ipw_rf_kill(void *adapter)
{
struct ipw_priv *priv = adapter;
unsigned long flags;
spin_lock_irqsave(&priv->lock, flags);
if (rf_kill_active(priv)) {
IPW_DEBUG_RF_KILL("RF Kill active, rescheduling GPIO check\n");
schedule_delayed_work(&priv->rf_kill, 2 * HZ);
goto exit_unlock;
}
if (!(priv->status & STATUS_RF_KILL_MASK)) {
IPW_DEBUG_RF_KILL("HW RF Kill no longer active, restarting "
"device\n");
schedule_work(&priv->adapter_restart);
} else
IPW_DEBUG_RF_KILL("HW RF Kill deactivated. SW RF Kill still "
"enabled\n");
exit_unlock:
spin_unlock_irqrestore(&priv->lock, flags);
}
static void ipw_bg_rf_kill(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, rf_kill.work);
mutex_lock(&priv->mutex);
ipw_rf_kill(priv);
mutex_unlock(&priv->mutex);
}
static void ipw_link_up(struct ipw_priv *priv)
{
priv->last_seq_num = -1;
priv->last_frag_num = -1;
priv->last_packet_time = 0;
netif_carrier_on(priv->net_dev);
cancel_delayed_work(&priv->request_scan);
cancel_delayed_work(&priv->request_direct_scan);
cancel_delayed_work(&priv->request_passive_scan);
cancel_delayed_work(&priv->scan_event);
ipw_reset_stats(priv);
priv->last_rate = ipw_get_current_rate(priv);
ipw_gather_stats(priv);
ipw_led_link_up(priv);
notify_wx_assoc_event(priv);
if (priv->config & CFG_BACKGROUND_SCAN)
schedule_delayed_work(&priv->request_scan, HZ);
}
static void ipw_bg_link_up(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, link_up);
mutex_lock(&priv->mutex);
ipw_link_up(priv);
mutex_unlock(&priv->mutex);
}
static void ipw_link_down(struct ipw_priv *priv)
{
ipw_led_link_down(priv);
netif_carrier_off(priv->net_dev);
notify_wx_assoc_event(priv);
cancel_delayed_work(&priv->request_scan);
cancel_delayed_work(&priv->request_direct_scan);
cancel_delayed_work(&priv->request_passive_scan);
cancel_delayed_work(&priv->adhoc_check);
cancel_delayed_work(&priv->gather_stats);
ipw_reset_stats(priv);
if (!(priv->status & STATUS_EXIT_PENDING)) {
schedule_delayed_work(&priv->request_scan, 0);
} else
cancel_delayed_work(&priv->scan_event);
}
static void ipw_bg_link_down(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, link_down);
mutex_lock(&priv->mutex);
ipw_link_down(priv);
mutex_unlock(&priv->mutex);
}
static int ipw_setup_deferred_work(struct ipw_priv *priv)
{
int ret = 0;
init_waitqueue_head(&priv->wait_command_queue);
init_waitqueue_head(&priv->wait_state);
INIT_DELAYED_WORK(&priv->adhoc_check, ipw_bg_adhoc_check);
INIT_WORK(&priv->associate, ipw_bg_associate);
INIT_WORK(&priv->disassociate, ipw_bg_disassociate);
INIT_WORK(&priv->system_config, ipw_system_config);
INIT_WORK(&priv->rx_replenish, ipw_bg_rx_queue_replenish);
INIT_WORK(&priv->adapter_restart, ipw_bg_adapter_restart);
INIT_DELAYED_WORK(&priv->rf_kill, ipw_bg_rf_kill);
INIT_WORK(&priv->up, ipw_bg_up);
INIT_WORK(&priv->down, ipw_bg_down);
INIT_DELAYED_WORK(&priv->request_scan, ipw_request_scan);
INIT_DELAYED_WORK(&priv->request_direct_scan, ipw_request_direct_scan);
INIT_DELAYED_WORK(&priv->request_passive_scan, ipw_request_passive_scan);
INIT_DELAYED_WORK(&priv->scan_event, ipw_scan_event);
INIT_DELAYED_WORK(&priv->gather_stats, ipw_bg_gather_stats);
INIT_WORK(&priv->abort_scan, ipw_bg_abort_scan);
INIT_WORK(&priv->roam, ipw_bg_roam);
INIT_DELAYED_WORK(&priv->scan_check, ipw_bg_scan_check);
INIT_WORK(&priv->link_up, ipw_bg_link_up);
INIT_WORK(&priv->link_down, ipw_bg_link_down);
INIT_DELAYED_WORK(&priv->led_link_on, ipw_bg_led_link_on);
INIT_DELAYED_WORK(&priv->led_link_off, ipw_bg_led_link_off);
INIT_DELAYED_WORK(&priv->led_act_off, ipw_bg_led_activity_off);
INIT_WORK(&priv->merge_networks, ipw_merge_adhoc_network);
#ifdef CONFIG_IPW2200_QOS
INIT_WORK(&priv->qos_activate, ipw_bg_qos_activate);
#endif
tasklet_init(&priv->irq_tasklet, (void (*)(unsigned long))
ipw_irq_tasklet, (unsigned long)priv);
return ret;
}
static void shim__set_security(struct net_device *dev,
struct libipw_security *sec)
{
struct ipw_priv *priv = libipw_priv(dev);
int i;
for (i = 0; i < 4; i++) {
if (sec->flags & (1 << i)) {
priv->ieee->sec.encode_alg[i] = sec->encode_alg[i];
priv->ieee->sec.key_sizes[i] = sec->key_sizes[i];
if (sec->key_sizes[i] == 0)
priv->ieee->sec.flags &= ~(1 << i);
else {
memcpy(priv->ieee->sec.keys[i], sec->keys[i],
sec->key_sizes[i]);
priv->ieee->sec.flags |= (1 << i);
}
priv->status |= STATUS_SECURITY_UPDATED;
} else if (sec->level != SEC_LEVEL_1)
priv->ieee->sec.flags &= ~(1 << i);
}
if (sec->flags & SEC_ACTIVE_KEY) {
if (sec->active_key <= 3) {
priv->ieee->sec.active_key = sec->active_key;
priv->ieee->sec.flags |= SEC_ACTIVE_KEY;
} else
priv->ieee->sec.flags &= ~SEC_ACTIVE_KEY;
priv->status |= STATUS_SECURITY_UPDATED;
} else
priv->ieee->sec.flags &= ~SEC_ACTIVE_KEY;
if ((sec->flags & SEC_AUTH_MODE) &&
(priv->ieee->sec.auth_mode != sec->auth_mode)) {
priv->ieee->sec.auth_mode = sec->auth_mode;
priv->ieee->sec.flags |= SEC_AUTH_MODE;
if (sec->auth_mode == WLAN_AUTH_SHARED_KEY)
priv->capability |= CAP_SHARED_KEY;
else
priv->capability &= ~CAP_SHARED_KEY;
priv->status |= STATUS_SECURITY_UPDATED;
}
if (sec->flags & SEC_ENABLED && priv->ieee->sec.enabled != sec->enabled) {
priv->ieee->sec.flags |= SEC_ENABLED;
priv->ieee->sec.enabled = sec->enabled;
priv->status |= STATUS_SECURITY_UPDATED;
if (sec->enabled)
priv->capability |= CAP_PRIVACY_ON;
else
priv->capability &= ~CAP_PRIVACY_ON;
}
if (sec->flags & SEC_ENCRYPT)
priv->ieee->sec.encrypt = sec->encrypt;
if (sec->flags & SEC_LEVEL && priv->ieee->sec.level != sec->level) {
priv->ieee->sec.level = sec->level;
priv->ieee->sec.flags |= SEC_LEVEL;
priv->status |= STATUS_SECURITY_UPDATED;
}
if (!priv->ieee->host_encrypt && (sec->flags & SEC_ENCRYPT))
ipw_set_hwcrypto_keys(priv);
#if 0
if ((priv->status & (STATUS_ASSOCIATED | STATUS_ASSOCIATING)) &&
(((priv->assoc_request.capability &
cpu_to_le16(WLAN_CAPABILITY_PRIVACY)) && !sec->enabled) ||
(!(priv->assoc_request.capability &
cpu_to_le16(WLAN_CAPABILITY_PRIVACY)) && sec->enabled))) {
IPW_DEBUG_ASSOC("Disassociating due to capability "
"change.\n");
ipw_disassociate(priv);
}
#endif
}
static int init_supported_rates(struct ipw_priv *priv,
struct ipw_supported_rates *rates)
{
memset(rates, 0, sizeof(*rates));
switch (priv->ieee->freq_band) {
case LIBIPW_52GHZ_BAND:
rates->ieee_mode = IPW_A_MODE;
rates->purpose = IPW_RATE_CAPABILITIES;
ipw_add_ofdm_scan_rates(rates, LIBIPW_CCK_MODULATION,
LIBIPW_OFDM_DEFAULT_RATES_MASK);
break;
default:
rates->ieee_mode = IPW_G_MODE;
rates->purpose = IPW_RATE_CAPABILITIES;
ipw_add_cck_scan_rates(rates, LIBIPW_CCK_MODULATION,
LIBIPW_CCK_DEFAULT_RATES_MASK);
if (priv->ieee->modulation & LIBIPW_OFDM_MODULATION) {
ipw_add_ofdm_scan_rates(rates, LIBIPW_CCK_MODULATION,
LIBIPW_OFDM_DEFAULT_RATES_MASK);
}
break;
}
return 0;
}
static int ipw_config(struct ipw_priv *priv)
{
if (ipw_set_tx_power(priv))
goto error;
if (ipw_send_adapter_address(priv, priv->net_dev->dev_addr))
goto error;
init_sys_config(&priv->sys_config);
if (bt_coexist) {
unsigned char bt_caps = priv->eeprom[EEPROM_SKU_CAPABILITY];
if (bt_caps & EEPROM_SKU_CAP_BT_CHANNEL_SIG)
priv->sys_config.bt_coexistence
|= CFG_BT_COEXISTENCE_SIGNAL_CHNL;
if (bt_caps & EEPROM_SKU_CAP_BT_OOB)
priv->sys_config.bt_coexistence
|= CFG_BT_COEXISTENCE_OOB;
}
#ifdef CONFIG_IPW2200_PROMISCUOUS
if (priv->prom_net_dev && netif_running(priv->prom_net_dev)) {
priv->sys_config.accept_all_data_frames = 1;
priv->sys_config.accept_non_directed_frames = 1;
priv->sys_config.accept_all_mgmt_bcpr = 1;
priv->sys_config.accept_all_mgmt_frames = 1;
}
#endif
if (priv->ieee->iw_mode == IW_MODE_ADHOC)
priv->sys_config.answer_broadcast_ssid_probe = 1;
else
priv->sys_config.answer_broadcast_ssid_probe = 0;
if (ipw_send_system_config(priv))
goto error;
init_supported_rates(priv, &priv->rates);
if (ipw_send_supported_rates(priv, &priv->rates))
goto error;
if (priv->rts_threshold) {
if (ipw_send_rts_threshold(priv, priv->rts_threshold))
goto error;
}
#ifdef CONFIG_IPW2200_QOS
IPW_DEBUG_QOS("QoS: call ipw_qos_activate\n");
ipw_qos_activate(priv, NULL);
#endif
if (ipw_set_random_seed(priv))
goto error;
if (ipw_send_host_complete(priv))
goto error;
priv->status |= STATUS_INIT;
ipw_led_init(priv);
ipw_led_radio_on(priv);
priv->notif_missed_beacons = 0;
if ((priv->capability & CAP_PRIVACY_ON) &&
(priv->ieee->sec.level == SEC_LEVEL_1) &&
!(priv->ieee->host_encrypt || priv->ieee->host_decrypt))
ipw_set_hwcrypto_keys(priv);
return 0;
error:
return -EIO;
}
static void ipw_set_geo(struct ipw_priv *priv)
{
int j;
for (j = 0; j < ARRAY_SIZE(ipw_geos); j++) {
if (!memcmp(&priv->eeprom[EEPROM_COUNTRY_CODE],
ipw_geos[j].name, 3))
break;
}
if (j == ARRAY_SIZE(ipw_geos)) {
IPW_WARNING("SKU [%c%c%c] not recognized.\n",
priv->eeprom[EEPROM_COUNTRY_CODE + 0],
priv->eeprom[EEPROM_COUNTRY_CODE + 1],
priv->eeprom[EEPROM_COUNTRY_CODE + 2]);
j = 0;
}
libipw_set_geo(priv->ieee, &ipw_geos[j]);
}
static int ipw_up(struct ipw_priv *priv)
{
int rc, i;
if (priv->suspend_time) {
libipw_networks_age(priv->ieee, priv->suspend_time);
priv->suspend_time = 0;
}
if (priv->status & STATUS_EXIT_PENDING)
return -EIO;
if (cmdlog && !priv->cmdlog) {
priv->cmdlog = kcalloc(cmdlog, sizeof(*priv->cmdlog),
GFP_KERNEL);
if (priv->cmdlog == NULL) {
IPW_ERROR("Error allocating %d command log entries.\n",
cmdlog);
return -ENOMEM;
} else {
priv->cmdlog_len = cmdlog;
}
}
for (i = 0; i < MAX_HW_RESTARTS; i++) {
rc = ipw_load(priv);
if (rc) {
IPW_ERROR("Unable to load firmware: %d\n", rc);
return rc;
}
ipw_init_ordinals(priv);
if (!(priv->config & CFG_CUSTOM_MAC))
eeprom_parse_mac(priv, priv->mac_addr);
memcpy(priv->net_dev->dev_addr, priv->mac_addr, ETH_ALEN);
ipw_set_geo(priv);
if (priv->status & STATUS_RF_KILL_SW) {
IPW_WARNING("Radio disabled by module parameter.\n");
return 0;
} else if (rf_kill_active(priv)) {
IPW_WARNING("Radio Frequency Kill Switch is On:\n"
"Kill switch must be turned off for "
"wireless networking to work.\n");
schedule_delayed_work(&priv->rf_kill, 2 * HZ);
return 0;
}
rc = ipw_config(priv);
if (!rc) {
IPW_DEBUG_INFO("Configured device on count %i\n", i);
schedule_delayed_work(&priv->request_scan, 0);
return 0;
}
IPW_DEBUG_INFO("Device configuration failed: 0x%08X\n", rc);
IPW_DEBUG_INFO("Failed to config device on retry %d of %d\n",
i, MAX_HW_RESTARTS);
ipw_down(priv);
}
IPW_ERROR("Unable to initialize device after %d attempts.\n", i);
return -EIO;
}
static void ipw_bg_up(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, up);
mutex_lock(&priv->mutex);
ipw_up(priv);
mutex_unlock(&priv->mutex);
}
static void ipw_deinit(struct ipw_priv *priv)
{
int i;
if (priv->status & STATUS_SCANNING) {
IPW_DEBUG_INFO("Aborting scan during shutdown.\n");
ipw_abort_scan(priv);
}
if (priv->status & STATUS_ASSOCIATED) {
IPW_DEBUG_INFO("Disassociating during shutdown.\n");
ipw_disassociate(priv);
}
ipw_led_shutdown(priv);
for (i = 1000; i && (priv->status &
(STATUS_DISASSOCIATING |
STATUS_ASSOCIATED | STATUS_SCANNING)); i--)
udelay(10);
if (priv->status & (STATUS_DISASSOCIATING |
STATUS_ASSOCIATED | STATUS_SCANNING))
IPW_DEBUG_INFO("Still associated or scanning...\n");
else
IPW_DEBUG_INFO("Took %dms to de-init\n", 1000 - i);
ipw_send_card_disable(priv, 0);
priv->status &= ~STATUS_INIT;
}
static void ipw_down(struct ipw_priv *priv)
{
int exit_pending = priv->status & STATUS_EXIT_PENDING;
priv->status |= STATUS_EXIT_PENDING;
if (ipw_is_init(priv))
ipw_deinit(priv);
if (!exit_pending)
priv->status &= ~STATUS_EXIT_PENDING;
ipw_disable_interrupts(priv);
priv->status &= STATUS_RF_KILL_MASK | STATUS_EXIT_PENDING;
netif_carrier_off(priv->net_dev);
ipw_stop_nic(priv);
ipw_led_radio_off(priv);
}
static void ipw_bg_down(struct work_struct *work)
{
struct ipw_priv *priv =
container_of(work, struct ipw_priv, down);
mutex_lock(&priv->mutex);
ipw_down(priv);
mutex_unlock(&priv->mutex);
}
static int ipw_wdev_init(struct net_device *dev)
{
int i, rc = 0;
struct ipw_priv *priv = libipw_priv(dev);
const struct libipw_geo *geo = libipw_get_geo(priv->ieee);
struct wireless_dev *wdev = &priv->ieee->wdev;
memcpy(wdev->wiphy->perm_addr, priv->mac_addr, ETH_ALEN);
if (geo->bg_channels) {
struct ieee80211_supported_band *bg_band = &priv->ieee->bg_band;
bg_band->band = NL80211_BAND_2GHZ;
bg_band->n_channels = geo->bg_channels;
bg_band->channels = kcalloc(geo->bg_channels,
sizeof(struct ieee80211_channel),
GFP_KERNEL);
if (!bg_band->channels) {
rc = -ENOMEM;
goto out;
}
for (i = 0; i < geo->bg_channels; i++) {
bg_band->channels[i].band = NL80211_BAND_2GHZ;
bg_band->channels[i].center_freq = geo->bg[i].freq;
bg_band->channels[i].hw_value = geo->bg[i].channel;
bg_band->channels[i].max_power = geo->bg[i].max_power;
if (geo->bg[i].flags & LIBIPW_CH_PASSIVE_ONLY)
bg_band->channels[i].flags |=
IEEE80211_CHAN_NO_IR;
if (geo->bg[i].flags & LIBIPW_CH_NO_IBSS)
bg_band->channels[i].flags |=
IEEE80211_CHAN_NO_IR;
if (geo->bg[i].flags & LIBIPW_CH_RADAR_DETECT)
bg_band->channels[i].flags |=
IEEE80211_CHAN_RADAR;
}
bg_band->bitrates = ipw2200_bg_rates;
bg_band->n_bitrates = ipw2200_num_bg_rates;
wdev->wiphy->bands[NL80211_BAND_2GHZ] = bg_band;
}
if (geo->a_channels) {
struct ieee80211_supported_band *a_band = &priv->ieee->a_band;
a_band->band = NL80211_BAND_5GHZ;
a_band->n_channels = geo->a_channels;
a_band->channels = kcalloc(geo->a_channels,
sizeof(struct ieee80211_channel),
GFP_KERNEL);
if (!a_band->channels) {
rc = -ENOMEM;
goto out;
}
for (i = 0; i < geo->a_channels; i++) {
a_band->channels[i].band = NL80211_BAND_5GHZ;
a_band->channels[i].center_freq = geo->a[i].freq;
a_band->channels[i].hw_value = geo->a[i].channel;
a_band->channels[i].max_power = geo->a[i].max_power;
if (geo->a[i].flags & LIBIPW_CH_PASSIVE_ONLY)
a_band->channels[i].flags |=
IEEE80211_CHAN_NO_IR;
if (geo->a[i].flags & LIBIPW_CH_NO_IBSS)
a_band->channels[i].flags |=
IEEE80211_CHAN_NO_IR;
if (geo->a[i].flags & LIBIPW_CH_RADAR_DETECT)
a_band->channels[i].flags |=
IEEE80211_CHAN_RADAR;
}
a_band->bitrates = ipw2200_a_rates;
a_band->n_bitrates = ipw2200_num_a_rates;
wdev->wiphy->bands[NL80211_BAND_5GHZ] = a_band;
}
wdev->wiphy->cipher_suites = ipw_cipher_suites;
wdev->wiphy->n_cipher_suites = ARRAY_SIZE(ipw_cipher_suites);
set_wiphy_dev(wdev->wiphy, &priv->pci_dev->dev);
if (wiphy_register(wdev->wiphy))
rc = -EIO;
out:
return rc;
}
static int ipw_prom_open(struct net_device *dev)
{
struct ipw_prom_priv *prom_priv = libipw_priv(dev);
struct ipw_priv *priv = prom_priv->priv;
IPW_DEBUG_INFO("prom dev->open\n");
netif_carrier_off(dev);
if (priv->ieee->iw_mode != IW_MODE_MONITOR) {
priv->sys_config.accept_all_data_frames = 1;
priv->sys_config.accept_non_directed_frames = 1;
priv->sys_config.accept_all_mgmt_bcpr = 1;
priv->sys_config.accept_all_mgmt_frames = 1;
ipw_send_system_config(priv);
}
return 0;
}
static int ipw_prom_stop(struct net_device *dev)
{
struct ipw_prom_priv *prom_priv = libipw_priv(dev);
struct ipw_priv *priv = prom_priv->priv;
IPW_DEBUG_INFO("prom dev->stop\n");
if (priv->ieee->iw_mode != IW_MODE_MONITOR) {
priv->sys_config.accept_all_data_frames = 0;
priv->sys_config.accept_non_directed_frames = 0;
priv->sys_config.accept_all_mgmt_bcpr = 0;
priv->sys_config.accept_all_mgmt_frames = 0;
ipw_send_system_config(priv);
}
return 0;
}
static netdev_tx_t ipw_prom_hard_start_xmit(struct sk_buff *skb,
struct net_device *dev)
{
IPW_DEBUG_INFO("prom dev->xmit\n");
dev_kfree_skb(skb);
return NETDEV_TX_OK;
}
static int ipw_prom_alloc(struct ipw_priv *priv)
{
int rc = 0;
if (priv->prom_net_dev)
return -EPERM;
priv->prom_net_dev = alloc_libipw(sizeof(struct ipw_prom_priv), 1);
if (priv->prom_net_dev == NULL)
return -ENOMEM;
priv->prom_priv = libipw_priv(priv->prom_net_dev);
priv->prom_priv->ieee = netdev_priv(priv->prom_net_dev);
priv->prom_priv->priv = priv;
strcpy(priv->prom_net_dev->name, "rtap%d");
memcpy(priv->prom_net_dev->dev_addr, priv->mac_addr, ETH_ALEN);
priv->prom_net_dev->type = ARPHRD_IEEE80211_RADIOTAP;
priv->prom_net_dev->netdev_ops = &ipw_prom_netdev_ops;
priv->prom_net_dev->min_mtu = 68;
priv->prom_net_dev->max_mtu = LIBIPW_DATA_LEN;
priv->prom_priv->ieee->iw_mode = IW_MODE_MONITOR;
SET_NETDEV_DEV(priv->prom_net_dev, &priv->pci_dev->dev);
rc = register_netdev(priv->prom_net_dev);
if (rc) {
free_libipw(priv->prom_net_dev, 1);
priv->prom_net_dev = NULL;
return rc;
}
return 0;
}
static void ipw_prom_free(struct ipw_priv *priv)
{
if (!priv->prom_net_dev)
return;
unregister_netdev(priv->prom_net_dev);
free_libipw(priv->prom_net_dev, 1);
priv->prom_net_dev = NULL;
}
static int ipw_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int err = 0;
struct net_device *net_dev;
void __iomem *base;
u32 length, val;
struct ipw_priv *priv;
int i;
net_dev = alloc_libipw(sizeof(struct ipw_priv), 0);
if (net_dev == NULL) {
err = -ENOMEM;
goto out;
}
priv = libipw_priv(net_dev);
priv->ieee = netdev_priv(net_dev);
priv->net_dev = net_dev;
priv->pci_dev = pdev;
ipw_debug_level = debug;
spin_lock_init(&priv->irq_lock);
spin_lock_init(&priv->lock);
for (i = 0; i < IPW_IBSS_MAC_HASH_SIZE; i++)
INIT_LIST_HEAD(&priv->ibss_mac_hash[i]);
mutex_init(&priv->mutex);
if (pci_enable_device(pdev)) {
err = -ENODEV;
goto out_free_libipw;
}
pci_set_master(pdev);
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (!err)
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
printk(KERN_WARNING DRV_NAME ": No suitable DMA available.\n");
goto out_pci_disable_device;
}
pci_set_drvdata(pdev, priv);
err = pci_request_regions(pdev, DRV_NAME);
if (err)
goto out_pci_disable_device;
pci_read_config_dword(pdev, 0x40, &val);
if ((val & 0x0000ff00) != 0)
pci_write_config_dword(pdev, 0x40, val & 0xffff00ff);
length = pci_resource_len(pdev, 0);
priv->hw_len = length;
base = pci_ioremap_bar(pdev, 0);
if (!base) {
err = -ENODEV;
goto out_pci_release_regions;
}
priv->hw_base = base;
IPW_DEBUG_INFO("pci_resource_len = 0x%08x\n", length);
IPW_DEBUG_INFO("pci_resource_base = %p\n", base);
err = ipw_setup_deferred_work(priv);
if (err) {
IPW_ERROR("Unable to setup deferred work\n");
goto out_iounmap;
}
ipw_sw_reset(priv, 1);
err = request_irq(pdev->irq, ipw_isr, IRQF_SHARED, DRV_NAME, priv);
if (err) {
IPW_ERROR("Error allocating IRQ %d\n", pdev->irq);
goto out_iounmap;
}
SET_NETDEV_DEV(net_dev, &pdev->dev);
mutex_lock(&priv->mutex);
priv->ieee->hard_start_xmit = ipw_net_hard_start_xmit;
priv->ieee->set_security = shim__set_security;
priv->ieee->is_queue_full = ipw_net_is_queue_full;
#ifdef CONFIG_IPW2200_QOS
priv->ieee->is_qos_active = ipw_is_qos_active;
priv->ieee->handle_probe_response = ipw_handle_beacon;
priv->ieee->handle_beacon = ipw_handle_probe_response;
priv->ieee->handle_assoc_response = ipw_handle_assoc_response;
#endif
priv->ieee->perfect_rssi = -20;
priv->ieee->worst_rssi = -85;
net_dev->netdev_ops = &ipw_netdev_ops;
priv->wireless_data.spy_data = &priv->ieee->spy_data;
net_dev->wireless_data = &priv->wireless_data;
net_dev->wireless_handlers = &ipw_wx_handler_def;
net_dev->ethtool_ops = &ipw_ethtool_ops;
net_dev->min_mtu = 68;
net_dev->max_mtu = LIBIPW_DATA_LEN;
err = sysfs_create_group(&pdev->dev.kobj, &ipw_attribute_group);
if (err) {
IPW_ERROR("failed to create sysfs device attributes\n");
mutex_unlock(&priv->mutex);
goto out_release_irq;
}
if (ipw_up(priv)) {
mutex_unlock(&priv->mutex);
err = -EIO;
goto out_remove_sysfs;
}
mutex_unlock(&priv->mutex);
err = ipw_wdev_init(net_dev);
if (err) {
IPW_ERROR("failed to register wireless device\n");
goto out_remove_sysfs;
}
err = register_netdev(net_dev);
if (err) {
IPW_ERROR("failed to register network device\n");
goto out_unregister_wiphy;
}
#ifdef CONFIG_IPW2200_PROMISCUOUS
if (rtap_iface) {
err = ipw_prom_alloc(priv);
if (err) {
IPW_ERROR("Failed to register promiscuous network "
"device (error %d).\n", err);
unregister_netdev(priv->net_dev);
goto out_unregister_wiphy;
}
}
#endif
printk(KERN_INFO DRV_NAME ": Detected geography %s (%d 802.11bg "
"channels, %d 802.11a channels)\n",
priv->ieee->geo.name, priv->ieee->geo.bg_channels,
priv->ieee->geo.a_channels);
return 0;
out_unregister_wiphy:
wiphy_unregister(priv->ieee->wdev.wiphy);
kfree(priv->ieee->a_band.channels);
kfree(priv->ieee->bg_band.channels);
out_remove_sysfs:
sysfs_remove_group(&pdev->dev.kobj, &ipw_attribute_group);
out_release_irq:
free_irq(pdev->irq, priv);
out_iounmap:
iounmap(priv->hw_base);
out_pci_release_regions:
pci_release_regions(pdev);
out_pci_disable_device:
pci_disable_device(pdev);
out_free_libipw:
free_libipw(priv->net_dev, 0);
out:
return err;
}
static void ipw_pci_remove(struct pci_dev *pdev)
{
struct ipw_priv *priv = pci_get_drvdata(pdev);
struct list_head *p, *q;
int i;
if (!priv)
return;
mutex_lock(&priv->mutex);
priv->status |= STATUS_EXIT_PENDING;
ipw_down(priv);
sysfs_remove_group(&pdev->dev.kobj, &ipw_attribute_group);
mutex_unlock(&priv->mutex);
unregister_netdev(priv->net_dev);
if (priv->rxq) {
ipw_rx_queue_free(priv, priv->rxq);
priv->rxq = NULL;
}
ipw_tx_queue_free(priv);
if (priv->cmdlog) {
kfree(priv->cmdlog);
priv->cmdlog = NULL;
}
cancel_delayed_work_sync(&priv->adhoc_check);
cancel_work_sync(&priv->associate);
cancel_work_sync(&priv->disassociate);
cancel_work_sync(&priv->system_config);
cancel_work_sync(&priv->rx_replenish);
cancel_work_sync(&priv->adapter_restart);
cancel_delayed_work_sync(&priv->rf_kill);
cancel_work_sync(&priv->up);
cancel_work_sync(&priv->down);
cancel_delayed_work_sync(&priv->request_scan);
cancel_delayed_work_sync(&priv->request_direct_scan);
cancel_delayed_work_sync(&priv->request_passive_scan);
cancel_delayed_work_sync(&priv->scan_event);
cancel_delayed_work_sync(&priv->gather_stats);
cancel_work_sync(&priv->abort_scan);
cancel_work_sync(&priv->roam);
cancel_delayed_work_sync(&priv->scan_check);
cancel_work_sync(&priv->link_up);
cancel_work_sync(&priv->link_down);
cancel_delayed_work_sync(&priv->led_link_on);
cancel_delayed_work_sync(&priv->led_link_off);
cancel_delayed_work_sync(&priv->led_act_off);
cancel_work_sync(&priv->merge_networks);
for (i = 0; i < IPW_IBSS_MAC_HASH_SIZE; i++) {
list_for_each_safe(p, q, &priv->ibss_mac_hash[i]) {
list_del(p);
kfree(list_entry(p, struct ipw_ibss_seq, list));
}
}
kfree(priv->error);
priv->error = NULL;
#ifdef CONFIG_IPW2200_PROMISCUOUS
ipw_prom_free(priv);
#endif
free_irq(pdev->irq, priv);
iounmap(priv->hw_base);
pci_release_regions(pdev);
pci_disable_device(pdev);
wiphy_unregister(priv->ieee->wdev.wiphy);
kfree(priv->ieee->a_band.channels);
kfree(priv->ieee->bg_band.channels);
free_libipw(priv->net_dev, 0);
free_firmware();
}
static int ipw_pci_suspend(struct pci_dev *pdev, pm_message_t state)
{
struct ipw_priv *priv = pci_get_drvdata(pdev);
struct net_device *dev = priv->net_dev;
printk(KERN_INFO "%s: Going into suspend...\n", dev->name);
ipw_down(priv);
netif_device_detach(dev);
pci_save_state(pdev);
pci_disable_device(pdev);
pci_set_power_state(pdev, pci_choose_state(pdev, state));
priv->suspend_at = get_seconds();
return 0;
}
static int ipw_pci_resume(struct pci_dev *pdev)
{
struct ipw_priv *priv = pci_get_drvdata(pdev);
struct net_device *dev = priv->net_dev;
int err;
u32 val;
printk(KERN_INFO "%s: Coming out of suspend...\n", dev->name);
pci_set_power_state(pdev, PCI_D0);
err = pci_enable_device(pdev);
if (err) {
printk(KERN_ERR "%s: pci_enable_device failed on resume\n",
dev->name);
return err;
}
pci_restore_state(pdev);
pci_read_config_dword(pdev, 0x40, &val);
if ((val & 0x0000ff00) != 0)
pci_write_config_dword(pdev, 0x40, val & 0xffff00ff);
netif_device_attach(dev);
priv->suspend_time = get_seconds() - priv->suspend_at;
schedule_work(&priv->up);
return 0;
}
static void ipw_pci_shutdown(struct pci_dev *pdev)
{
struct ipw_priv *priv = pci_get_drvdata(pdev);
ipw_down(priv);
pci_disable_device(pdev);
}
static int __init ipw_init(void)
{
int ret;
printk(KERN_INFO DRV_NAME ": " DRV_DESCRIPTION ", " DRV_VERSION "\n");
printk(KERN_INFO DRV_NAME ": " DRV_COPYRIGHT "\n");
ret = pci_register_driver(&ipw_driver);
if (ret) {
IPW_ERROR("Unable to initialize PCI module\n");
return ret;
}
ret = driver_create_file(&ipw_driver.driver, &driver_attr_debug_level);
if (ret) {
IPW_ERROR("Unable to create driver sysfs file\n");
pci_unregister_driver(&ipw_driver);
return ret;
}
return ret;
}
static void __exit ipw_exit(void)
{
driver_remove_file(&ipw_driver.driver, &driver_attr_debug_level);
pci_unregister_driver(&ipw_driver);
}
