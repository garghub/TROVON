static inline void __iwl_set_bit(struct iwl_priv *priv, u32 reg, u32 mask)
{
iwl_write32(priv, reg, iwl_read32(priv, reg) | mask);
}
static inline void __iwl_clear_bit(struct iwl_priv *priv, u32 reg, u32 mask)
{
iwl_write32(priv, reg, iwl_read32(priv, reg) & ~mask);
}
void iwl_set_bit(struct iwl_priv *priv, u32 reg, u32 mask)
{
unsigned long flags;
spin_lock_irqsave(&priv->reg_lock, flags);
__iwl_set_bit(priv, reg, mask);
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
void iwl_clear_bit(struct iwl_priv *priv, u32 reg, u32 mask)
{
unsigned long flags;
spin_lock_irqsave(&priv->reg_lock, flags);
__iwl_clear_bit(priv, reg, mask);
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
int iwl_poll_bit(struct iwl_priv *priv, u32 addr,
u32 bits, u32 mask, int timeout)
{
int t = 0;
do {
if ((iwl_read32(priv, addr) & mask) == (bits & mask))
return t;
udelay(IWL_POLL_INTERVAL);
t += IWL_POLL_INTERVAL;
} while (t < timeout);
return -ETIMEDOUT;
}
int iwl_grab_nic_access_silent(struct iwl_priv *priv)
{
int ret;
lockdep_assert_held(&priv->reg_lock);
__iwl_set_bit(priv, CSR_GP_CNTRL, CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ);
ret = iwl_poll_bit(priv, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_VAL_MAC_ACCESS_EN,
(CSR_GP_CNTRL_REG_FLAG_MAC_CLOCK_READY |
CSR_GP_CNTRL_REG_FLAG_GOING_TO_SLEEP), 15000);
if (ret < 0) {
iwl_write32(priv, CSR_RESET, CSR_RESET_REG_FLAG_FORCE_NMI);
return -EIO;
}
return 0;
}
int iwl_grab_nic_access(struct iwl_priv *priv)
{
int ret = iwl_grab_nic_access_silent(priv);
if (ret) {
u32 val = iwl_read32(priv, CSR_GP_CNTRL);
IWL_ERR(priv,
"MAC is in deep sleep!. CSR_GP_CNTRL = 0x%08X\n", val);
}
return ret;
}
void iwl_release_nic_access(struct iwl_priv *priv)
{
lockdep_assert_held(&priv->reg_lock);
__iwl_clear_bit(priv, CSR_GP_CNTRL,
CSR_GP_CNTRL_REG_FLAG_MAC_ACCESS_REQ);
}
u32 iwl_read_direct32(struct iwl_priv *priv, u32 reg)
{
u32 value;
unsigned long flags;
spin_lock_irqsave(&priv->reg_lock, flags);
iwl_grab_nic_access(priv);
value = iwl_read32(priv, reg);
iwl_release_nic_access(priv);
spin_unlock_irqrestore(&priv->reg_lock, flags);
return value;
}
void iwl_write_direct32(struct iwl_priv *priv, u32 reg, u32 value)
{
unsigned long flags;
spin_lock_irqsave(&priv->reg_lock, flags);
if (!iwl_grab_nic_access(priv)) {
iwl_write32(priv, reg, value);
iwl_release_nic_access(priv);
}
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
int iwl_poll_direct_bit(struct iwl_priv *priv, u32 addr, u32 mask,
int timeout)
{
int t = 0;
do {
if ((iwl_read_direct32(priv, addr) & mask) == mask)
return t;
udelay(IWL_POLL_INTERVAL);
t += IWL_POLL_INTERVAL;
} while (t < timeout);
return -ETIMEDOUT;
}
static inline u32 __iwl_read_prph(struct iwl_priv *priv, u32 reg)
{
iwl_write32(priv, HBUS_TARG_PRPH_RADDR, reg | (3 << 24));
rmb();
return iwl_read32(priv, HBUS_TARG_PRPH_RDAT);
}
static inline void __iwl_write_prph(struct iwl_priv *priv, u32 addr, u32 val)
{
iwl_write32(priv, HBUS_TARG_PRPH_WADDR,
((addr & 0x0000FFFF) | (3 << 24)));
wmb();
iwl_write32(priv, HBUS_TARG_PRPH_WDAT, val);
}
u32 iwl_read_prph(struct iwl_priv *priv, u32 reg)
{
unsigned long flags;
u32 val;
spin_lock_irqsave(&priv->reg_lock, flags);
iwl_grab_nic_access(priv);
val = __iwl_read_prph(priv, reg);
iwl_release_nic_access(priv);
spin_unlock_irqrestore(&priv->reg_lock, flags);
return val;
}
void iwl_write_prph(struct iwl_priv *priv, u32 addr, u32 val)
{
unsigned long flags;
spin_lock_irqsave(&priv->reg_lock, flags);
if (!iwl_grab_nic_access(priv)) {
__iwl_write_prph(priv, addr, val);
iwl_release_nic_access(priv);
}
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
void iwl_set_bits_prph(struct iwl_priv *priv, u32 reg, u32 mask)
{
unsigned long flags;
spin_lock_irqsave(&priv->reg_lock, flags);
iwl_grab_nic_access(priv);
__iwl_write_prph(priv, reg, __iwl_read_prph(priv, reg) | mask);
iwl_release_nic_access(priv);
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
void iwl_set_bits_mask_prph(struct iwl_priv *priv, u32 reg,
u32 bits, u32 mask)
{
unsigned long flags;
spin_lock_irqsave(&priv->reg_lock, flags);
iwl_grab_nic_access(priv);
__iwl_write_prph(priv, reg,
(__iwl_read_prph(priv, reg) & mask) | bits);
iwl_release_nic_access(priv);
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
void iwl_clear_bits_prph(struct iwl_priv *priv, u32 reg, u32 mask)
{
unsigned long flags;
u32 val;
spin_lock_irqsave(&priv->reg_lock, flags);
iwl_grab_nic_access(priv);
val = __iwl_read_prph(priv, reg);
__iwl_write_prph(priv, reg, (val & ~mask));
iwl_release_nic_access(priv);
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
void _iwl_read_targ_mem_words(struct iwl_priv *priv, u32 addr,
void *buf, int words)
{
unsigned long flags;
int offs;
u32 *vals = buf;
spin_lock_irqsave(&priv->reg_lock, flags);
iwl_grab_nic_access(priv);
iwl_write32(priv, HBUS_TARG_MEM_RADDR, addr);
rmb();
for (offs = 0; offs < words; offs++)
vals[offs] = iwl_read32(priv, HBUS_TARG_MEM_RDAT);
iwl_release_nic_access(priv);
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
u32 iwl_read_targ_mem(struct iwl_priv *priv, u32 addr)
{
u32 value;
_iwl_read_targ_mem_words(priv, addr, &value, 1);
return value;
}
void iwl_write_targ_mem(struct iwl_priv *priv, u32 addr, u32 val)
{
unsigned long flags;
spin_lock_irqsave(&priv->reg_lock, flags);
if (!iwl_grab_nic_access(priv)) {
iwl_write32(priv, HBUS_TARG_MEM_WADDR, addr);
wmb();
iwl_write32(priv, HBUS_TARG_MEM_WDAT, val);
iwl_release_nic_access(priv);
}
spin_unlock_irqrestore(&priv->reg_lock, flags);
}
