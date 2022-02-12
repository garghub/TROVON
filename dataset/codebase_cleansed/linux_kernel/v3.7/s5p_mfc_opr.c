void s5p_mfc_init_hw_ops(struct s5p_mfc_dev *dev)
{
if (IS_MFCV6(dev)) {
s5p_mfc_ops = s5p_mfc_init_hw_ops_v6();
dev->warn_start = S5P_FIMV_ERR_WARNINGS_START_V6;
} else {
s5p_mfc_ops = s5p_mfc_init_hw_ops_v5();
dev->warn_start = S5P_FIMV_ERR_WARNINGS_START;
}
dev->mfc_ops = s5p_mfc_ops;
}
