static s32 ixgbevf_poll_for_msg(struct ixgbe_hw *hw)
{
struct ixgbe_mbx_info *mbx = &hw->mbx;
int countdown = mbx->timeout;
while (countdown && mbx->ops.check_for_msg(hw)) {
countdown--;
udelay(mbx->udelay);
}
if (!countdown)
mbx->timeout = 0;
return countdown ? 0 : IXGBE_ERR_MBX;
}
static s32 ixgbevf_poll_for_ack(struct ixgbe_hw *hw)
{
struct ixgbe_mbx_info *mbx = &hw->mbx;
int countdown = mbx->timeout;
while (countdown && mbx->ops.check_for_ack(hw)) {
countdown--;
udelay(mbx->udelay);
}
if (!countdown)
mbx->timeout = 0;
return countdown ? 0 : IXGBE_ERR_MBX;
}
static s32 ixgbevf_read_posted_mbx(struct ixgbe_hw *hw, u32 *msg, u16 size)
{
struct ixgbe_mbx_info *mbx = &hw->mbx;
s32 ret_val = IXGBE_ERR_MBX;
ret_val = ixgbevf_poll_for_msg(hw);
if (!ret_val)
ret_val = mbx->ops.read(hw, msg, size);
return ret_val;
}
static s32 ixgbevf_write_posted_mbx(struct ixgbe_hw *hw, u32 *msg, u16 size)
{
struct ixgbe_mbx_info *mbx = &hw->mbx;
s32 ret_val;
ret_val = mbx->ops.write(hw, msg, size);
if (!ret_val)
ret_val = ixgbevf_poll_for_ack(hw);
return ret_val;
}
static u32 ixgbevf_read_v2p_mailbox(struct ixgbe_hw *hw)
{
u32 v2p_mailbox = IXGBE_READ_REG(hw, IXGBE_VFMAILBOX);
v2p_mailbox |= hw->mbx.v2p_mailbox;
hw->mbx.v2p_mailbox |= v2p_mailbox & IXGBE_VFMAILBOX_R2C_BITS;
return v2p_mailbox;
}
static s32 ixgbevf_check_for_bit_vf(struct ixgbe_hw *hw, u32 mask)
{
u32 v2p_mailbox = ixgbevf_read_v2p_mailbox(hw);
s32 ret_val = IXGBE_ERR_MBX;
if (v2p_mailbox & mask)
ret_val = 0;
hw->mbx.v2p_mailbox &= ~mask;
return ret_val;
}
static s32 ixgbevf_check_for_msg_vf(struct ixgbe_hw *hw)
{
s32 ret_val = IXGBE_ERR_MBX;
if (!ixgbevf_check_for_bit_vf(hw, IXGBE_VFMAILBOX_PFSTS)) {
ret_val = 0;
hw->mbx.stats.reqs++;
}
return ret_val;
}
static s32 ixgbevf_check_for_ack_vf(struct ixgbe_hw *hw)
{
s32 ret_val = IXGBE_ERR_MBX;
if (!ixgbevf_check_for_bit_vf(hw, IXGBE_VFMAILBOX_PFACK)) {
ret_val = 0;
hw->mbx.stats.acks++;
}
return ret_val;
}
static s32 ixgbevf_check_for_rst_vf(struct ixgbe_hw *hw)
{
s32 ret_val = IXGBE_ERR_MBX;
if (!ixgbevf_check_for_bit_vf(hw, (IXGBE_VFMAILBOX_RSTD |
IXGBE_VFMAILBOX_RSTI))) {
ret_val = 0;
hw->mbx.stats.rsts++;
}
return ret_val;
}
static s32 ixgbevf_obtain_mbx_lock_vf(struct ixgbe_hw *hw)
{
s32 ret_val = IXGBE_ERR_MBX;
IXGBE_WRITE_REG(hw, IXGBE_VFMAILBOX, IXGBE_VFMAILBOX_VFU);
if (ixgbevf_read_v2p_mailbox(hw) & IXGBE_VFMAILBOX_VFU)
ret_val = 0;
return ret_val;
}
static s32 ixgbevf_write_mbx_vf(struct ixgbe_hw *hw, u32 *msg, u16 size)
{
s32 ret_val;
u16 i;
ret_val = ixgbevf_obtain_mbx_lock_vf(hw);
if (ret_val)
goto out_no_write;
ixgbevf_check_for_msg_vf(hw);
ixgbevf_check_for_ack_vf(hw);
for (i = 0; i < size; i++)
IXGBE_WRITE_REG_ARRAY(hw, IXGBE_VFMBMEM, i, msg[i]);
hw->mbx.stats.msgs_tx++;
IXGBE_WRITE_REG(hw, IXGBE_VFMAILBOX, IXGBE_VFMAILBOX_REQ);
out_no_write:
return ret_val;
}
static s32 ixgbevf_read_mbx_vf(struct ixgbe_hw *hw, u32 *msg, u16 size)
{
s32 ret_val = 0;
u16 i;
ret_val = ixgbevf_obtain_mbx_lock_vf(hw);
if (ret_val)
goto out_no_read;
for (i = 0; i < size; i++)
msg[i] = IXGBE_READ_REG_ARRAY(hw, IXGBE_VFMBMEM, i);
IXGBE_WRITE_REG(hw, IXGBE_VFMAILBOX, IXGBE_VFMAILBOX_ACK);
hw->mbx.stats.msgs_rx++;
out_no_read:
return ret_val;
}
static s32 ixgbevf_init_mbx_params_vf(struct ixgbe_hw *hw)
{
struct ixgbe_mbx_info *mbx = &hw->mbx;
mbx->timeout = 0;
mbx->udelay = IXGBE_VF_MBX_INIT_DELAY;
mbx->size = IXGBE_VFMAILBOX_SIZE;
mbx->stats.msgs_tx = 0;
mbx->stats.msgs_rx = 0;
mbx->stats.reqs = 0;
mbx->stats.acks = 0;
mbx->stats.rsts = 0;
return 0;
}
