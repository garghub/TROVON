void s5p_mfc_init_hw_cmds(struct s5p_mfc_dev *dev)
{
if (IS_MFCV6_PLUS(dev))
s5p_mfc_cmds = s5p_mfc_init_hw_cmds_v6();
else
s5p_mfc_cmds = s5p_mfc_init_hw_cmds_v5();
dev->mfc_cmds = s5p_mfc_cmds;
}
