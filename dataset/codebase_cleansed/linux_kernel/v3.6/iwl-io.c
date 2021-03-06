static inline void __iwl_set_bit(struct iwl_trans *trans, u32 reg, u32 mask)
{
iwl_write32(trans, reg, iwl_read32(trans, reg) | mask);
}
static inline void __iwl_clear_bit(struct iwl_trans *trans, u32 reg, u32 mask)
{
iwl_write32(trans, reg, iwl_read32(trans, reg) & ~mask);
}
void iwl_set_bit(struct iwl_trans *trans, u32 reg, u32 mask)
{
unsigned long flags;
spin_lock_irqsave(&trans->reg_lock, flags);
__iwl_set_bit(trans, reg, mask);
spin_unlock_irqrestore(&trans->reg_lock, flags);
}
void iwl_clear_bit(struct iwl_trans *trans, u32 reg, u32 mask)
{
unsigned long flags;
spin_lock_irqsave(&trans->reg_lock, flags);
__iwl_clear_bit(trans, reg, mask);
spin_unlock_irqrestore(&trans->reg_lock, flags);
}
void iwl_set_bits_mask(struct iwl_trans *trans, u32 reg, u32 mask, u32 value)
{
unsigned long flags;
u32 v;
#ifdef CONFIG_IWLWIFI_DEBUG
WARN_ON_ONCE(value & ~mask);
#endif
spin_lock_irqsave(&trans->reg_lock, flags);
v = iwl_read32(trans, reg);
v &= ~mask;
v |= value;
iwl_write32(trans, reg, v);
spin_unlock_irqrestore(&trans->reg_lock, flags);
}
int iwl_poll_bit(struct iwl_trans *trans, u32 addr,
u32 bits, u32 mask, int timeout)
{
int t = 0;
do {
if ((iwl_read32(trans, addr) & mask) == (bits & mask))
return t;
udelay(IWL_POLL_INTERVAL);
t += IWL_POLL_INTERVAL;
} while (t < timeout);
return -ETIMEDOUT;
}
int iwl_grab_nic_access_silent(struct iwl_trans *trans)
{
int ret;
lockdep_assert_held(&trans->reg_lock);
__iwl_set_bit(trans, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ);
ret = iwl_poll_bit(trans, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_VAL_MAC_ACCESS_EN,
(CSR_GP_CNTRL_REG_FLAG_MAC_CLOCK_READY |
CSR_GP_CNTRL_REG_FLAG_GOING_TO_SLEEP), 15000);
if (ret < 0) {
iwl_write32(trans, CSR_RESET, CSR_RESET_REG_FLAG_FORCE_NMI);
return -EIO;
}
return 0;
}
bool iwl_grab_nic_access(struct iwl_trans *trans)
{
int ret = iwl_grab_nic_access_silent(trans);
if (unlikely(ret)) {
u32 val = iwl_read32(trans, CSR_GP_CNTRL);
WARN_ONCE(1, "Timeout waiting for hardware access "
"(CSR_GP_CNTRL 0x%08x)\n", val);
return false;
}
return true;
}
void iwl_release_nic_access(struct iwl_trans *trans)
{
lockdep_assert_held(&trans->reg_lock);
__iwl_clear_bit(trans, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ);
mmiowb();
}
u32 iwl_read_direct32(struct iwl_trans *trans, u32 reg)
{
u32 value;
unsigned long flags;
spin_lock_irqsave(&trans->reg_lock, flags);
iwl_grab_nic_access(trans);
value = iwl_read32(trans, reg);
iwl_release_nic_access(trans);
spin_unlock_irqrestore(&trans->reg_lock, flags);
return value;
}
void iwl_write_direct32(struct iwl_trans *trans, u32 reg, u32 value)
{
unsigned long flags;
spin_lock_irqsave(&trans->reg_lock, flags);
if (likely(iwl_grab_nic_access(trans))) {
iwl_write32(trans, reg, value);
iwl_release_nic_access(trans);
}
spin_unlock_irqrestore(&trans->reg_lock, flags);
}
int iwl_poll_direct_bit(struct iwl_trans *trans, u32 addr, u32 mask,
int timeout)
{
int t = 0;
do {
if ((iwl_read_direct32(trans, addr) & mask) == mask)
return t;
udelay(IWL_POLL_INTERVAL);
t += IWL_POLL_INTERVAL;
} while (t < timeout);
return -ETIMEDOUT;
}
static inline u32 __iwl_read_prph(struct iwl_trans *trans, u32 reg)
{
iwl_write32(trans, HBUS_TARG_PRPH_RADDR, reg | (3 << 24));
return iwl_read32(trans, HBUS_TARG_PRPH_RDAT);
}
static inline void __iwl_write_prph(struct iwl_trans *trans, u32 addr, u32 val)
{
iwl_write32(trans, HBUS_TARG_PRPH_WADDR,
((addr & 0x0000FFFF) | (3 << 24)));
iwl_write32(trans, HBUS_TARG_PRPH_WDAT, val);
}
u32 iwl_read_prph(struct iwl_trans *trans, u32 reg)
{
unsigned long flags;
u32 val;
spin_lock_irqsave(&trans->reg_lock, flags);
iwl_grab_nic_access(trans);
val = __iwl_read_prph(trans, reg);
iwl_release_nic_access(trans);
spin_unlock_irqrestore(&trans->reg_lock, flags);
return val;
}
void iwl_write_prph(struct iwl_trans *trans, u32 addr, u32 val)
{
unsigned long flags;
spin_lock_irqsave(&trans->reg_lock, flags);
if (likely(iwl_grab_nic_access(trans))) {
__iwl_write_prph(trans, addr, val);
iwl_release_nic_access(trans);
}
spin_unlock_irqrestore(&trans->reg_lock, flags);
}
void iwl_set_bits_prph(struct iwl_trans *trans, u32 reg, u32 mask)
{
unsigned long flags;
spin_lock_irqsave(&trans->reg_lock, flags);
if (likely(iwl_grab_nic_access(trans))) {
__iwl_write_prph(trans, reg,
__iwl_read_prph(trans, reg) | mask);
iwl_release_nic_access(trans);
}
spin_unlock_irqrestore(&trans->reg_lock, flags);
}
void iwl_set_bits_mask_prph(struct iwl_trans *trans, u32 reg,
u32 bits, u32 mask)
{
unsigned long flags;
spin_lock_irqsave(&trans->reg_lock, flags);
if (likely(iwl_grab_nic_access(trans))) {
__iwl_write_prph(trans, reg,
(__iwl_read_prph(trans, reg) & mask) | bits);
iwl_release_nic_access(trans);
}
spin_unlock_irqrestore(&trans->reg_lock, flags);
}
void iwl_clear_bits_prph(struct iwl_trans *trans, u32 reg, u32 mask)
{
unsigned long flags;
u32 val;
spin_lock_irqsave(&trans->reg_lock, flags);
if (likely(iwl_grab_nic_access(trans))) {
val = __iwl_read_prph(trans, reg);
__iwl_write_prph(trans, reg, (val & ~mask));
iwl_release_nic_access(trans);
}
spin_unlock_irqrestore(&trans->reg_lock, flags);
}
void _iwl_read_targ_mem_dwords(struct iwl_trans *trans, u32 addr,
void *buf, int dwords)
{
unsigned long flags;
int offs;
u32 *vals = buf;
spin_lock_irqsave(&trans->reg_lock, flags);
if (likely(iwl_grab_nic_access(trans))) {
iwl_write32(trans, HBUS_TARG_MEM_RADDR, addr);
for (offs = 0; offs < dwords; offs++)
vals[offs] = iwl_read32(trans, HBUS_TARG_MEM_RDAT);
iwl_release_nic_access(trans);
}
spin_unlock_irqrestore(&trans->reg_lock, flags);
}
u32 iwl_read_targ_mem(struct iwl_trans *trans, u32 addr)
{
u32 value;
_iwl_read_targ_mem_dwords(trans, addr, &value, 1);
return value;
}
int _iwl_write_targ_mem_dwords(struct iwl_trans *trans, u32 addr,
void *buf, int dwords)
{
unsigned long flags;
int offs, result = 0;
u32 *vals = buf;
spin_lock_irqsave(&trans->reg_lock, flags);
if (likely(iwl_grab_nic_access(trans))) {
iwl_write32(trans, HBUS_TARG_MEM_WADDR, addr);
for (offs = 0; offs < dwords; offs++)
iwl_write32(trans, HBUS_TARG_MEM_WDAT, vals[offs]);
iwl_release_nic_access(trans);
} else
result = -EBUSY;
spin_unlock_irqrestore(&trans->reg_lock, flags);
return result;
}
int iwl_write_targ_mem(struct iwl_trans *trans, u32 addr, u32 val)
{
return _iwl_write_targ_mem_dwords(trans, addr, &val, 1);
}
