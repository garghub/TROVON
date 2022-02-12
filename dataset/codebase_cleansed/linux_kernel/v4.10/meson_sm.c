static u32 meson_sm_get_cmd(const struct meson_sm_chip *chip,
unsigned int cmd_index)
{
const struct meson_sm_cmd *cmd = chip->cmd;
while (cmd->smc_id && cmd->index != cmd_index)
cmd++;
return cmd->smc_id;
}
static u32 __meson_sm_call(u32 cmd, u32 arg0, u32 arg1, u32 arg2,
u32 arg3, u32 arg4)
{
struct arm_smccc_res res;
arm_smccc_smc(cmd, arg0, arg1, arg2, arg3, arg4, 0, 0, &res);
return res.a0;
}
static void __iomem *meson_sm_map_shmem(u32 cmd_shmem, unsigned int size)
{
u32 sm_phy_base;
sm_phy_base = __meson_sm_call(cmd_shmem, 0, 0, 0, 0, 0);
if (!sm_phy_base)
return 0;
return ioremap_cache(sm_phy_base, size);
}
int meson_sm_call(unsigned int cmd_index, u32 *ret, u32 arg0,
u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
u32 cmd, lret;
if (!fw.chip)
return -ENOENT;
cmd = meson_sm_get_cmd(fw.chip, cmd_index);
if (!cmd)
return -EINVAL;
lret = __meson_sm_call(cmd, arg0, arg1, arg2, arg3, arg4);
if (ret)
*ret = lret;
return 0;
}
int meson_sm_call_read(void *buffer, unsigned int cmd_index, u32 arg0,
u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
u32 size;
if (!fw.chip)
return -ENOENT;
if (!fw.chip->cmd_shmem_out_base)
return -EINVAL;
if (meson_sm_call(cmd_index, &size, arg0, arg1, arg2, arg3, arg4) < 0)
return -EINVAL;
if (!size || size > fw.chip->shmem_size)
return -EINVAL;
if (buffer)
memcpy(buffer, fw.sm_shmem_out_base, size);
return size;
}
int meson_sm_call_write(void *buffer, unsigned int size, unsigned int cmd_index,
u32 arg0, u32 arg1, u32 arg2, u32 arg3, u32 arg4)
{
u32 written;
if (!fw.chip)
return -ENOENT;
if (size > fw.chip->shmem_size)
return -EINVAL;
if (!fw.chip->cmd_shmem_in_base)
return -EINVAL;
memcpy(fw.sm_shmem_in_base, buffer, size);
if (meson_sm_call(cmd_index, &written, arg0, arg1, arg2, arg3, arg4) < 0)
return -EINVAL;
if (!written)
return -EINVAL;
return written;
}
int __init meson_sm_init(void)
{
const struct meson_sm_chip *chip;
const struct of_device_id *matched_np;
struct device_node *np;
np = of_find_matching_node_and_match(NULL, meson_sm_ids, &matched_np);
if (!np)
return -ENODEV;
chip = matched_np->data;
if (!chip) {
pr_err("unable to setup secure-monitor data\n");
goto out;
}
if (chip->cmd_shmem_in_base) {
fw.sm_shmem_in_base = meson_sm_map_shmem(chip->cmd_shmem_in_base,
chip->shmem_size);
if (WARN_ON(!fw.sm_shmem_in_base))
goto out;
}
if (chip->cmd_shmem_out_base) {
fw.sm_shmem_out_base = meson_sm_map_shmem(chip->cmd_shmem_out_base,
chip->shmem_size);
if (WARN_ON(!fw.sm_shmem_out_base))
goto out_in_base;
}
fw.chip = chip;
pr_info("secure-monitor enabled\n");
return 0;
out_in_base:
iounmap(fw.sm_shmem_in_base);
out:
return -EINVAL;
}
