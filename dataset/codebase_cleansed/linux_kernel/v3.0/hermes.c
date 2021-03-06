static int hermes_issue_cmd(hermes_t *hw, u16 cmd, u16 param0,
u16 param1, u16 param2)
{
int k = CMD_BUSY_TIMEOUT;
u16 reg;
reg = hermes_read_regn(hw, CMD);
while ((reg & HERMES_CMD_BUSY) && k) {
k--;
udelay(1);
reg = hermes_read_regn(hw, CMD);
}
if (reg & HERMES_CMD_BUSY)
return -EBUSY;
hermes_write_regn(hw, PARAM2, param2);
hermes_write_regn(hw, PARAM1, param1);
hermes_write_regn(hw, PARAM0, param0);
hermes_write_regn(hw, CMD, cmd);
return 0;
}
static int hermes_doicmd_wait(hermes_t *hw, u16 cmd,
u16 parm0, u16 parm1, u16 parm2,
struct hermes_response *resp)
{
int err = 0;
int k;
u16 status, reg;
err = hermes_issue_cmd(hw, cmd, parm0, parm1, parm2);
if (err)
return err;
reg = hermes_read_regn(hw, EVSTAT);
k = CMD_INIT_TIMEOUT;
while ((!(reg & HERMES_EV_CMD)) && k) {
k--;
udelay(10);
reg = hermes_read_regn(hw, EVSTAT);
}
hermes_write_regn(hw, SWSUPPORT0, HERMES_MAGIC);
if (!hermes_present(hw)) {
DEBUG(0, "hermes @ 0x%x: Card removed during reset.\n",
hw->iobase);
err = -ENODEV;
goto out;
}
if (!(reg & HERMES_EV_CMD)) {
printk(KERN_ERR "hermes @ %p: "
"Timeout waiting for card to reset (reg=0x%04x)!\n",
hw->iobase, reg);
err = -ETIMEDOUT;
goto out;
}
status = hermes_read_regn(hw, STATUS);
if (resp) {
resp->status = status;
resp->resp0 = hermes_read_regn(hw, RESP0);
resp->resp1 = hermes_read_regn(hw, RESP1);
resp->resp2 = hermes_read_regn(hw, RESP2);
}
hermes_write_regn(hw, EVACK, HERMES_EV_CMD);
if (status & HERMES_STATUS_RESULT)
err = -EIO;
out:
return err;
}
void hermes_struct_init(hermes_t *hw, void __iomem *address, int reg_spacing)
{
hw->iobase = address;
hw->reg_spacing = reg_spacing;
hw->inten = 0x0;
hw->eeprom_pda = false;
hw->ops = &hermes_ops_local;
}
static int hermes_init(hermes_t *hw)
{
u16 reg;
int err = 0;
int k;
hw->inten = 0x0;
hermes_write_regn(hw, INTEN, 0);
hermes_write_regn(hw, EVACK, 0xffff);
k = CMD_BUSY_TIMEOUT;
reg = hermes_read_regn(hw, CMD);
while (k && (reg & HERMES_CMD_BUSY)) {
if (reg == 0xffff)
return -ENODEV;
k--;
udelay(1);
reg = hermes_read_regn(hw, CMD);
}
reg = hermes_read_regn(hw, EVSTAT);
hermes_write_regn(hw, EVACK, reg);
err = hermes_doicmd_wait(hw, HERMES_CMD_INIT, 0, 0, 0, NULL);
return err;
}
static int hermes_docmd_wait(hermes_t *hw, u16 cmd, u16 parm0,
struct hermes_response *resp)
{
int err;
int k;
u16 reg;
u16 status;
err = hermes_issue_cmd(hw, cmd, parm0, 0, 0);
if (err) {
if (!hermes_present(hw)) {
if (net_ratelimit())
printk(KERN_WARNING "hermes @ %p: "
"Card removed while issuing command "
"0x%04x.\n", hw->iobase, cmd);
err = -ENODEV;
} else
if (net_ratelimit())
printk(KERN_ERR "hermes @ %p: "
"Error %d issuing command 0x%04x.\n",
hw->iobase, err, cmd);
goto out;
}
reg = hermes_read_regn(hw, EVSTAT);
k = CMD_COMPL_TIMEOUT;
while ((!(reg & HERMES_EV_CMD)) && k) {
k--;
udelay(10);
reg = hermes_read_regn(hw, EVSTAT);
}
if (!hermes_present(hw)) {
printk(KERN_WARNING "hermes @ %p: Card removed "
"while waiting for command 0x%04x completion.\n",
hw->iobase, cmd);
err = -ENODEV;
goto out;
}
if (!(reg & HERMES_EV_CMD)) {
printk(KERN_ERR "hermes @ %p: Timeout waiting for "
"command 0x%04x completion.\n", hw->iobase, cmd);
err = -ETIMEDOUT;
goto out;
}
status = hermes_read_regn(hw, STATUS);
if (resp) {
resp->status = status;
resp->resp0 = hermes_read_regn(hw, RESP0);
resp->resp1 = hermes_read_regn(hw, RESP1);
resp->resp2 = hermes_read_regn(hw, RESP2);
}
hermes_write_regn(hw, EVACK, HERMES_EV_CMD);
if (status & HERMES_STATUS_RESULT)
err = -EIO;
out:
return err;
}
static int hermes_allocate(hermes_t *hw, u16 size, u16 *fid)
{
int err = 0;
int k;
u16 reg;
if ((size < HERMES_ALLOC_LEN_MIN) || (size > HERMES_ALLOC_LEN_MAX))
return -EINVAL;
err = hermes_docmd_wait(hw, HERMES_CMD_ALLOC, size, NULL);
if (err)
return err;
reg = hermes_read_regn(hw, EVSTAT);
k = ALLOC_COMPL_TIMEOUT;
while ((!(reg & HERMES_EV_ALLOC)) && k) {
k--;
udelay(10);
reg = hermes_read_regn(hw, EVSTAT);
}
if (!hermes_present(hw)) {
printk(KERN_WARNING "hermes @ %p: "
"Card removed waiting for frame allocation.\n",
hw->iobase);
return -ENODEV;
}
if (!(reg & HERMES_EV_ALLOC)) {
printk(KERN_ERR "hermes @ %p: "
"Timeout waiting for frame allocation\n",
hw->iobase);
return -ETIMEDOUT;
}
*fid = hermes_read_regn(hw, ALLOCFID);
hermes_write_regn(hw, EVACK, HERMES_EV_ALLOC);
return 0;
}
static int hermes_bap_seek(hermes_t *hw, int bap, u16 id, u16 offset)
{
int sreg = bap ? HERMES_SELECT1 : HERMES_SELECT0;
int oreg = bap ? HERMES_OFFSET1 : HERMES_OFFSET0;
int k;
u16 reg;
if ((offset > HERMES_BAP_OFFSET_MAX) || (offset % 2))
return -EINVAL;
k = HERMES_BAP_BUSY_TIMEOUT;
reg = hermes_read_reg(hw, oreg);
while ((reg & HERMES_OFFSET_BUSY) && k) {
k--;
udelay(1);
reg = hermes_read_reg(hw, oreg);
}
if (reg & HERMES_OFFSET_BUSY)
return -ETIMEDOUT;
hermes_write_reg(hw, sreg, id);
hermes_write_reg(hw, oreg, offset);
k = HERMES_BAP_BUSY_TIMEOUT;
reg = hermes_read_reg(hw, oreg);
while ((reg & (HERMES_OFFSET_BUSY | HERMES_OFFSET_ERR)) && k) {
k--;
udelay(1);
reg = hermes_read_reg(hw, oreg);
}
if (reg != offset) {
printk(KERN_ERR "hermes @ %p: BAP%d offset %s: "
"reg=0x%x id=0x%x offset=0x%x\n", hw->iobase, bap,
(reg & HERMES_OFFSET_BUSY) ? "timeout" : "error",
reg, id, offset);
if (reg & HERMES_OFFSET_BUSY)
return -ETIMEDOUT;
return -EIO;
}
return 0;
}
static int hermes_bap_pread(hermes_t *hw, int bap, void *buf, int len,
u16 id, u16 offset)
{
int dreg = bap ? HERMES_DATA1 : HERMES_DATA0;
int err = 0;
if ((len < 0) || (len % 2))
return -EINVAL;
err = hermes_bap_seek(hw, bap, id, offset);
if (err)
goto out;
hermes_read_words(hw, dreg, buf, len/2);
out:
return err;
}
static int hermes_bap_pwrite(hermes_t *hw, int bap, const void *buf, int len,
u16 id, u16 offset)
{
int dreg = bap ? HERMES_DATA1 : HERMES_DATA0;
int err = 0;
if (len < 0)
return -EINVAL;
err = hermes_bap_seek(hw, bap, id, offset);
if (err)
goto out;
hermes_write_bytes(hw, dreg, buf, len);
out:
return err;
}
static int hermes_read_ltv(hermes_t *hw, int bap, u16 rid, unsigned bufsize,
u16 *length, void *buf)
{
int err = 0;
int dreg = bap ? HERMES_DATA1 : HERMES_DATA0;
u16 rlength, rtype;
unsigned nwords;
if (bufsize % 2)
return -EINVAL;
err = hermes_docmd_wait(hw, HERMES_CMD_ACCESS, rid, NULL);
if (err)
return err;
err = hermes_bap_seek(hw, bap, rid, 0);
if (err)
return err;
rlength = hermes_read_reg(hw, dreg);
if (!rlength)
return -ENODATA;
rtype = hermes_read_reg(hw, dreg);
if (length)
*length = rlength;
if (rtype != rid)
printk(KERN_WARNING "hermes @ %p: %s(): "
"rid (0x%04x) does not match type (0x%04x)\n",
hw->iobase, __func__, rid, rtype);
if (HERMES_RECLEN_TO_BYTES(rlength) > bufsize)
printk(KERN_WARNING "hermes @ %p: "
"Truncating LTV record from %d to %d bytes. "
"(rid=0x%04x, len=0x%04x)\n", hw->iobase,
HERMES_RECLEN_TO_BYTES(rlength), bufsize, rid, rlength);
nwords = min((unsigned)rlength - 1, bufsize / 2);
hermes_read_words(hw, dreg, buf, nwords);
return 0;
}
static int hermes_write_ltv(hermes_t *hw, int bap, u16 rid,
u16 length, const void *value)
{
int dreg = bap ? HERMES_DATA1 : HERMES_DATA0;
int err = 0;
unsigned count;
if (length == 0)
return -EINVAL;
err = hermes_bap_seek(hw, bap, rid, 0);
if (err)
return err;
hermes_write_reg(hw, dreg, length);
hermes_write_reg(hw, dreg, rid);
count = length - 1;
hermes_write_bytes(hw, dreg, value, count << 1);
err = hermes_docmd_wait(hw, HERMES_CMD_ACCESS | HERMES_CMD_WRITE,
rid, NULL);
return err;
}
static inline void
hermes_aux_setaddr(hermes_t *hw, u32 addr)
{
hermes_write_reg(hw, HERMES_AUXPAGE, (u16) (addr >> 7));
hermes_write_reg(hw, HERMES_AUXOFFSET, (u16) (addr & 0x7F));
}
static inline int
hermes_aux_control(hermes_t *hw, int enabled)
{
int desired_state = enabled ? HERMES_AUX_ENABLED : HERMES_AUX_DISABLED;
int action = enabled ? HERMES_AUX_ENABLE : HERMES_AUX_DISABLE;
int i;
if (hermes_read_reg(hw, HERMES_CONTROL) == desired_state)
return 0;
hermes_write_reg(hw, HERMES_PARAM0, HERMES_AUX_PW0);
hermes_write_reg(hw, HERMES_PARAM1, HERMES_AUX_PW1);
hermes_write_reg(hw, HERMES_PARAM2, HERMES_AUX_PW2);
hermes_write_reg(hw, HERMES_CONTROL, action);
for (i = 0; i < 20; i++) {
udelay(10);
if (hermes_read_reg(hw, HERMES_CONTROL) ==
desired_state)
return 0;
}
return -EBUSY;
}
static int hermesi_program_init(hermes_t *hw, u32 offset)
{
int err;
hermes_write_regn(hw, EVACK, 0xFFFF);
err = hw->ops->init_cmd_wait(hw,
0x0100 | HERMES_CMD_INIT,
0, 0, 0, NULL);
if (err)
return err;
err = hw->ops->init_cmd_wait(hw,
0x0000 | HERMES_CMD_INIT,
0, 0, 0, NULL);
if (err)
return err;
err = hermes_aux_control(hw, 1);
pr_debug("AUX enable returned %d\n", err);
if (err)
return err;
pr_debug("Enabling volatile, EP 0x%08x\n", offset);
err = hw->ops->init_cmd_wait(hw,
HERMES_PROGRAM_ENABLE_VOLATILE,
offset & 0xFFFFu,
offset >> 16,
0,
NULL);
pr_debug("PROGRAM_ENABLE returned %d\n", err);
return err;
}
static int hermesi_program_end(hermes_t *hw)
{
struct hermes_response resp;
int rc = 0;
int err;
rc = hw->ops->cmd_wait(hw, HERMES_PROGRAM_DISABLE, 0, &resp);
pr_debug("PROGRAM_DISABLE returned %d, "
"r0 0x%04x, r1 0x%04x, r2 0x%04x\n",
rc, resp.resp0, resp.resp1, resp.resp2);
if ((rc == 0) &&
((resp.status & HERMES_STATUS_CMDCODE) != HERMES_CMD_DOWNLD))
rc = -EIO;
err = hermes_aux_control(hw, 0);
pr_debug("AUX disable returned %d\n", err);
hermes_write_regn(hw, EVACK, 0xFFFF);
(void) hw->ops->init_cmd_wait(hw, 0x0000 | HERMES_CMD_INIT,
0, 0, 0, NULL);
return rc ? rc : err;
}
static int hermes_program_bytes(struct hermes *hw, const char *data,
u32 addr, u32 len)
{
hermes_aux_setaddr(hw, addr);
hermes_write_bytes(hw, HERMES_AUXDATA, data, len);
return 0;
}
static int hermes_read_pda(hermes_t *hw, __le16 *pda, u32 pda_addr, u16 pda_len)
{
int ret;
u16 pda_size;
u16 data_len = pda_len;
__le16 *data = pda;
if (hw->eeprom_pda) {
ret = hw->ops->cmd_wait(hw, HERMES_CMD_READMIF, 0, NULL);
if (ret)
return ret;
} else {
pda[0] = cpu_to_le16(pda_len - 2);
pda[1] = cpu_to_le16(0x0800);
data_len = pda_len - 4;
data = pda + 2;
}
ret = hermes_aux_control(hw, 1);
pr_debug("AUX enable returned %d\n", ret);
if (ret)
return ret;
hermes_aux_setaddr(hw, pda_addr);
hermes_read_words(hw, HERMES_AUXDATA, data, data_len / 2);
ret = hermes_aux_control(hw, 0);
pr_debug("AUX disable returned %d\n", ret);
pda_size = le16_to_cpu(pda[0]);
pr_debug("Actual PDA length %d, Max allowed %d\n",
pda_size, pda_len);
if (pda_size > pda_len)
return -EINVAL;
return 0;
}
static void hermes_lock_irqsave(spinlock_t *lock,
unsigned long *flags) __acquires(lock)
{
spin_lock_irqsave(lock, *flags);
}
static void hermes_unlock_irqrestore(spinlock_t *lock,
unsigned long *flags) __releases(lock)
{
spin_unlock_irqrestore(lock, *flags);
}
static void hermes_lock_irq(spinlock_t *lock) __acquires(lock)
{
spin_lock_irq(lock);
}
static void hermes_unlock_irq(spinlock_t *lock) __releases(lock)
{
spin_unlock_irq(lock);
}
