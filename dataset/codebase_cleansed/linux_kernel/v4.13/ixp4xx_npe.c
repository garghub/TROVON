int npe_running(struct npe *npe)
{
return (__raw_readl(&npe->regs->exec_status_cmd) & STAT_RUN) != 0;
}
static void npe_cmd_write(struct npe *npe, u32 addr, int cmd, u32 data)
{
__raw_writel(data, &npe->regs->exec_data);
__raw_writel(addr, &npe->regs->exec_addr);
__raw_writel(cmd, &npe->regs->exec_status_cmd);
}
static u32 npe_cmd_read(struct npe *npe, u32 addr, int cmd)
{
__raw_writel(addr, &npe->regs->exec_addr);
__raw_writel(cmd, &npe->regs->exec_status_cmd);
__raw_readl(&npe->regs->exec_data);
__raw_readl(&npe->regs->exec_data);
return __raw_readl(&npe->regs->exec_data);
}
static void npe_clear_active(struct npe *npe, u32 reg)
{
u32 val = npe_cmd_read(npe, reg, CMD_RD_ECS_REG);
npe_cmd_write(npe, reg, CMD_WR_ECS_REG, val & ~ECS_REG_0_ACTIVE);
}
static void npe_start(struct npe *npe)
{
npe_clear_active(npe, ECS_PRI_1_CTXT_REG_0);
npe_clear_active(npe, ECS_PRI_2_CTXT_REG_0);
npe_clear_active(npe, ECS_DBG_CTXT_REG_0);
__raw_writel(CMD_NPE_CLR_PIPE, &npe->regs->exec_status_cmd);
__raw_writel(CMD_NPE_START, &npe->regs->exec_status_cmd);
}
static void npe_stop(struct npe *npe)
{
__raw_writel(CMD_NPE_STOP, &npe->regs->exec_status_cmd);
__raw_writel(CMD_NPE_CLR_PIPE, &npe->regs->exec_status_cmd);
}
static int __must_check npe_debug_instr(struct npe *npe, u32 instr, u32 ctx,
u32 ldur)
{
u32 wc;
int i;
npe_cmd_write(npe, ECS_DBG_CTXT_REG_0, CMD_WR_ECS_REG,
ECS_REG_0_ACTIVE | (ldur << ECS_REG_0_LDUR_BITS));
npe_cmd_write(npe, ECS_DBG_CTXT_REG_1, CMD_WR_ECS_REG,
(ctx << ECS_REG_1_CCTXT_BITS) |
(ctx << ECS_REG_1_SELCTXT_BITS));
__raw_writel(CMD_NPE_CLR_PIPE, &npe->regs->exec_status_cmd);
npe_cmd_write(npe, ECS_INSTRUCT_REG, CMD_WR_ECS_REG, instr);
wc = __raw_readl(&npe->regs->watch_count);
__raw_writel(CMD_NPE_STEP, &npe->regs->exec_status_cmd);
for (i = 0; i < MAX_RETRIES; i++) {
if (wc != __raw_readl(&npe->regs->watch_count))
return 0;
udelay(1);
}
print_npe(KERN_ERR, npe, "reset: npe_debug_instr(): timeout\n");
return -ETIMEDOUT;
}
static int __must_check npe_logical_reg_write8(struct npe *npe, u32 addr,
u8 val, u32 ctx)
{
u32 instr = INSTR_WR_REG_BYTE |
addr << 9 |
(val & 0x1F) << 4 |
(val & ~0x1F) << (18 - 5);
return npe_debug_instr(npe, instr, ctx, 1);
}
static int __must_check npe_logical_reg_write16(struct npe *npe, u32 addr,
u16 val, u32 ctx)
{
u32 instr = INSTR_WR_REG_SHORT |
addr << 9 |
(val & 0x1F) << 4 |
(val & ~0x1F) << (18 - 5);
return npe_debug_instr(npe, instr, ctx, 1);
}
static int __must_check npe_logical_reg_write32(struct npe *npe, u32 addr,
u32 val, u32 ctx)
{
if (npe_logical_reg_write16(npe, addr, val >> 16, ctx))
return -ETIMEDOUT;
return npe_logical_reg_write16(npe, addr + 2, val & 0xFFFF, ctx);
}
static int npe_reset(struct npe *npe)
{
u32 val, ctl, exec_count, ctx_reg2;
int i;
ctl = (__raw_readl(&npe->regs->messaging_control) | 0x3F000000) &
0x3F3FFFFF;
__raw_writel(ctl & 0x3F00FFFF, &npe->regs->messaging_control);
exec_count = __raw_readl(&npe->regs->exec_count);
__raw_writel(0, &npe->regs->exec_count);
ctx_reg2 = npe_cmd_read(npe, ECS_DBG_CTXT_REG_2, CMD_RD_ECS_REG);
npe_cmd_write(npe, ECS_DBG_CTXT_REG_2, CMD_WR_ECS_REG, ctx_reg2 |
ECS_DBG_REG_2_IF | ECS_DBG_REG_2_IE);
while (__raw_readl(&npe->regs->watchpoint_fifo) & WFIFO_VALID)
;
while (__raw_readl(&npe->regs->messaging_status) & MSGSTAT_OFNE)
print_npe(KERN_DEBUG, npe, "npe_reset: read FIFO = 0x%X\n",
__raw_readl(&npe->regs->in_out_fifo));
while (__raw_readl(&npe->regs->messaging_status) & MSGSTAT_IFNE)
if (npe_debug_instr(npe, INSTR_RD_FIFO, 0, 0))
return -ETIMEDOUT;
__raw_writel(RESET_MBOX_STAT, &npe->regs->mailbox_status);
if (npe_debug_instr(npe, INSTR_RESET_MBOX, 0, 0))
return -ETIMEDOUT;
for (val = 0; val < NPE_PHYS_REG; val++) {
if (npe_logical_reg_write16(npe, NPE_REGMAP, val >> 1, 0))
return -ETIMEDOUT;
if (npe_logical_reg_write32(npe, (val & 1) * 4, 0, 0))
return -ETIMEDOUT;
}
val = npe_cmd_read(npe, ECS_BG_CTXT_REG_0, CMD_RD_ECS_REG);
val &= ~ECS_REG_0_NEXTPC_MASK;
val |= (0 << 16) & ECS_REG_0_NEXTPC_MASK;
npe_cmd_write(npe, ECS_BG_CTXT_REG_0, CMD_WR_ECS_REG, val);
for (i = 0; i < 16; i++) {
if (i) {
if (npe_logical_reg_write8(npe, NPE_STEVT, 0x80, i))
return -ETIMEDOUT;
if (npe_logical_reg_write16(npe, NPE_STARTPC, 0, i))
return -ETIMEDOUT;
}
if (npe_logical_reg_write16(npe, NPE_REGMAP, 0x820, i))
return -ETIMEDOUT;
if (npe_logical_reg_write8(npe, NPE_CINDEX, 0, i))
return -ETIMEDOUT;
}
npe_cmd_write(npe, ECS_DBG_CTXT_REG_0, CMD_WR_ECS_REG, 0);
__raw_writel(CMD_NPE_CLR_PIPE, &npe->regs->exec_status_cmd);
__raw_writel(exec_count, &npe->regs->exec_count);
npe_cmd_write(npe, ECS_DBG_CTXT_REG_2, CMD_WR_ECS_REG, ctx_reg2);
for (val = 0; val < ARRAY_SIZE(ecs_reset); val++)
npe_cmd_write(npe, ecs_reset[val].reg, CMD_WR_ECS_REG,
ecs_reset[val].val);
__raw_writel(CMD_CLR_PROFILE_CNT, &npe->regs->exec_status_cmd);
__raw_writel(0, &npe->regs->exec_count);
__raw_writel(0, &npe->regs->action_points[0]);
__raw_writel(0, &npe->regs->action_points[1]);
__raw_writel(0, &npe->regs->action_points[2]);
__raw_writel(0, &npe->regs->action_points[3]);
__raw_writel(0, &npe->regs->watch_count);
val = ixp4xx_read_feature_bits();
ixp4xx_write_feature_bits(val &
~(IXP4XX_FEATURE_RESET_NPEA << npe->id));
ixp4xx_write_feature_bits(val |
(IXP4XX_FEATURE_RESET_NPEA << npe->id));
for (i = 0; i < MAX_RETRIES; i++) {
if (ixp4xx_read_feature_bits() &
(IXP4XX_FEATURE_RESET_NPEA << npe->id))
break;
udelay(1);
}
if (i == MAX_RETRIES)
return -ETIMEDOUT;
npe_stop(npe);
__raw_writel(ctl, &npe->regs->messaging_control);
return 0;
}
int npe_send_message(struct npe *npe, const void *msg, const char *what)
{
const u32 *send = msg;
int cycles = 0;
debug_msg(npe, "Trying to send message %s [%08X:%08X]\n",
what, send[0], send[1]);
if (__raw_readl(&npe->regs->messaging_status) & MSGSTAT_IFNE) {
debug_msg(npe, "NPE input FIFO not empty\n");
return -EIO;
}
__raw_writel(send[0], &npe->regs->in_out_fifo);
if (!(__raw_readl(&npe->regs->messaging_status) & MSGSTAT_IFNF)) {
debug_msg(npe, "NPE input FIFO full\n");
return -EIO;
}
__raw_writel(send[1], &npe->regs->in_out_fifo);
while ((cycles < MAX_RETRIES) &&
(__raw_readl(&npe->regs->messaging_status) & MSGSTAT_IFNE)) {
udelay(1);
cycles++;
}
if (cycles == MAX_RETRIES) {
debug_msg(npe, "Timeout sending message\n");
return -ETIMEDOUT;
}
#if DEBUG_MSG > 1
debug_msg(npe, "Sending a message took %i cycles\n", cycles);
#endif
return 0;
}
int npe_recv_message(struct npe *npe, void *msg, const char *what)
{
u32 *recv = msg;
int cycles = 0, cnt = 0;
debug_msg(npe, "Trying to receive message %s\n", what);
while (cycles < MAX_RETRIES) {
if (__raw_readl(&npe->regs->messaging_status) & MSGSTAT_OFNE) {
recv[cnt++] = __raw_readl(&npe->regs->in_out_fifo);
if (cnt == 2)
break;
} else {
udelay(1);
cycles++;
}
}
switch(cnt) {
case 1:
debug_msg(npe, "Received [%08X]\n", recv[0]);
break;
case 2:
debug_msg(npe, "Received [%08X:%08X]\n", recv[0], recv[1]);
break;
}
if (cycles == MAX_RETRIES) {
debug_msg(npe, "Timeout waiting for message\n");
return -ETIMEDOUT;
}
#if DEBUG_MSG > 1
debug_msg(npe, "Receiving a message took %i cycles\n", cycles);
#endif
return 0;
}
int npe_send_recv_message(struct npe *npe, void *msg, const char *what)
{
int result;
u32 *send = msg, recv[2];
if ((result = npe_send_message(npe, msg, what)) != 0)
return result;
if ((result = npe_recv_message(npe, recv, what)) != 0)
return result;
if ((recv[0] != send[0]) || (recv[1] != send[1])) {
debug_msg(npe, "Message %s: unexpected message received\n",
what);
return -EIO;
}
return 0;
}
int npe_load_firmware(struct npe *npe, const char *name, struct device *dev)
{
const struct firmware *fw_entry;
struct dl_block {
u32 type;
u32 offset;
} *blk;
struct dl_image {
u32 magic;
u32 id;
u32 size;
union {
u32 data[0];
struct dl_block blocks[0];
};
} *image;
struct dl_codeblock {
u32 npe_addr;
u32 size;
u32 data[0];
} *cb;
int i, j, err, data_size, instr_size, blocks, table_end;
u32 cmd;
if ((err = request_firmware(&fw_entry, name, dev)) != 0)
return err;
err = -EINVAL;
if (fw_entry->size < sizeof(struct dl_image)) {
print_npe(KERN_ERR, npe, "incomplete firmware file\n");
goto err;
}
image = (struct dl_image*)fw_entry->data;
#if DEBUG_FW
print_npe(KERN_DEBUG, npe, "firmware: %08X %08X %08X (0x%X bytes)\n",
image->magic, image->id, image->size, image->size * 4);
#endif
if (image->magic == swab32(FW_MAGIC)) {
image->id = swab32(image->id);
image->size = swab32(image->size);
} else if (image->magic != FW_MAGIC) {
print_npe(KERN_ERR, npe, "bad firmware file magic: 0x%X\n",
image->magic);
goto err;
}
if ((image->size * 4 + sizeof(struct dl_image)) != fw_entry->size) {
print_npe(KERN_ERR, npe,
"inconsistent size of firmware file\n");
goto err;
}
if (((image->id >> 24) & 0xF ) != npe->id) {
print_npe(KERN_ERR, npe, "firmware file NPE ID mismatch\n");
goto err;
}
if (image->magic == swab32(FW_MAGIC))
for (i = 0; i < image->size; i++)
image->data[i] = swab32(image->data[i]);
if (cpu_is_ixp42x() && ((image->id >> 28) & 0xF )) {
print_npe(KERN_INFO, npe, "IXP43x/IXP46x firmware ignored on "
"IXP42x\n");
goto err;
}
if (npe_running(npe)) {
print_npe(KERN_INFO, npe, "unable to load firmware, NPE is "
"already running\n");
err = -EBUSY;
goto err;
}
#if 0
npe_stop(npe);
npe_reset(npe);
#endif
print_npe(KERN_INFO, npe, "firmware functionality 0x%X, "
"revision 0x%X:%X\n", (image->id >> 16) & 0xFF,
(image->id >> 8) & 0xFF, image->id & 0xFF);
if (cpu_is_ixp42x()) {
if (!npe->id)
instr_size = NPE_A_42X_INSTR_SIZE;
else
instr_size = NPE_B_AND_C_42X_INSTR_SIZE;
data_size = NPE_42X_DATA_SIZE;
} else {
instr_size = NPE_46X_INSTR_SIZE;
data_size = NPE_46X_DATA_SIZE;
}
for (blocks = 0; blocks * sizeof(struct dl_block) / 4 < image->size;
blocks++)
if (image->blocks[blocks].type == FW_BLOCK_TYPE_EOF)
break;
if (blocks * sizeof(struct dl_block) / 4 >= image->size) {
print_npe(KERN_INFO, npe, "firmware EOF block marker not "
"found\n");
goto err;
}
#if DEBUG_FW
print_npe(KERN_DEBUG, npe, "%i firmware blocks found\n", blocks);
#endif
table_end = blocks * sizeof(struct dl_block) / 4 + 1 ;
for (i = 0, blk = image->blocks; i < blocks; i++, blk++) {
if (blk->offset > image->size - sizeof(struct dl_codeblock) / 4
|| blk->offset < table_end) {
print_npe(KERN_INFO, npe, "invalid offset 0x%X of "
"firmware block #%i\n", blk->offset, i);
goto err;
}
cb = (struct dl_codeblock*)&image->data[blk->offset];
if (blk->type == FW_BLOCK_TYPE_INSTR) {
if (cb->npe_addr + cb->size > instr_size)
goto too_big;
cmd = CMD_WR_INS_MEM;
} else if (blk->type == FW_BLOCK_TYPE_DATA) {
if (cb->npe_addr + cb->size > data_size)
goto too_big;
cmd = CMD_WR_DATA_MEM;
} else {
print_npe(KERN_INFO, npe, "invalid firmware block #%i "
"type 0x%X\n", i, blk->type);
goto err;
}
if (blk->offset + sizeof(*cb) / 4 + cb->size > image->size) {
print_npe(KERN_INFO, npe, "firmware block #%i doesn't "
"fit in firmware image: type %c, start 0x%X,"
" length 0x%X\n", i,
blk->type == FW_BLOCK_TYPE_INSTR ? 'I' : 'D',
cb->npe_addr, cb->size);
goto err;
}
for (j = 0; j < cb->size; j++)
npe_cmd_write(npe, cb->npe_addr + j, cmd, cb->data[j]);
}
npe_start(npe);
if (!npe_running(npe))
print_npe(KERN_ERR, npe, "unable to start\n");
release_firmware(fw_entry);
return 0;
too_big:
print_npe(KERN_INFO, npe, "firmware block #%i doesn't fit in NPE "
"memory: type %c, start 0x%X, length 0x%X\n", i,
blk->type == FW_BLOCK_TYPE_INSTR ? 'I' : 'D',
cb->npe_addr, cb->size);
err:
release_firmware(fw_entry);
return err;
}
struct npe *npe_request(unsigned id)
{
if (id < NPE_COUNT)
if (npe_tab[id].valid)
if (try_module_get(THIS_MODULE))
return &npe_tab[id];
return NULL;
}
void npe_release(struct npe *npe)
{
module_put(THIS_MODULE);
}
static int __init npe_init_module(void)
{
int i, found = 0;
for (i = 0; i < NPE_COUNT; i++) {
struct npe *npe = &npe_tab[i];
if (!(ixp4xx_read_feature_bits() &
(IXP4XX_FEATURE_RESET_NPEA << i)))
continue;
if (!(npe->mem_res = request_mem_region(npe->regs_phys,
REGS_SIZE,
npe_name(npe)))) {
print_npe(KERN_ERR, npe,
"failed to request memory region\n");
continue;
}
if (npe_reset(npe))
continue;
npe->valid = 1;
found++;
}
if (!found)
return -ENODEV;
return 0;
}
static void __exit npe_cleanup_module(void)
{
int i;
for (i = 0; i < NPE_COUNT; i++)
if (npe_tab[i].mem_res) {
npe_reset(&npe_tab[i]);
release_resource(npe_tab[i].mem_res);
}
}
