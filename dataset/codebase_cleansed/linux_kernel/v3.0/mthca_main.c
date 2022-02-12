static int mthca_tune_pci(struct mthca_dev *mdev)
{
if (!tune_pci)
return 0;
if (pci_find_capability(mdev->pdev, PCI_CAP_ID_PCIX)) {
if (pcix_set_mmrbc(mdev->pdev, pcix_get_max_mmrbc(mdev->pdev))) {
mthca_err(mdev, "Couldn't set PCI-X max read count, "
"aborting.\n");
return -ENODEV;
}
} else if (!(mdev->mthca_flags & MTHCA_FLAG_PCIE))
mthca_info(mdev, "No PCI-X capability, not setting RBC.\n");
if (pci_find_capability(mdev->pdev, PCI_CAP_ID_EXP)) {
if (pcie_set_readrq(mdev->pdev, 4096)) {
mthca_err(mdev, "Couldn't write PCI Express read request, "
"aborting.\n");
return -ENODEV;
}
} else if (mdev->mthca_flags & MTHCA_FLAG_PCIE)
mthca_info(mdev, "No PCI Express capability, "
"not setting Max Read Request Size.\n");
return 0;
}
static int mthca_dev_lim(struct mthca_dev *mdev, struct mthca_dev_lim *dev_lim)
{
int err;
u8 status;
mdev->limits.mtt_seg_size = (1 << log_mtts_per_seg) * 8;
err = mthca_QUERY_DEV_LIM(mdev, dev_lim, &status);
if (err) {
mthca_err(mdev, "QUERY_DEV_LIM command failed, aborting.\n");
return err;
}
if (status) {
mthca_err(mdev, "QUERY_DEV_LIM returned status 0x%02x, "
"aborting.\n", status);
return -EINVAL;
}
if (dev_lim->min_page_sz > PAGE_SIZE) {
mthca_err(mdev, "HCA minimum page size of %d bigger than "
"kernel PAGE_SIZE of %ld, aborting.\n",
dev_lim->min_page_sz, PAGE_SIZE);
return -ENODEV;
}
if (dev_lim->num_ports > MTHCA_MAX_PORTS) {
mthca_err(mdev, "HCA has %d ports, but we only support %d, "
"aborting.\n",
dev_lim->num_ports, MTHCA_MAX_PORTS);
return -ENODEV;
}
if (dev_lim->uar_size > pci_resource_len(mdev->pdev, 2)) {
mthca_err(mdev, "HCA reported UAR size of 0x%x bigger than "
"PCI resource 2 size of 0x%llx, aborting.\n",
dev_lim->uar_size,
(unsigned long long)pci_resource_len(mdev->pdev, 2));
return -ENODEV;
}
mdev->limits.num_ports = dev_lim->num_ports;
mdev->limits.vl_cap = dev_lim->max_vl;
mdev->limits.mtu_cap = dev_lim->max_mtu;
mdev->limits.gid_table_len = dev_lim->max_gids;
mdev->limits.pkey_table_len = dev_lim->max_pkeys;
mdev->limits.local_ca_ack_delay = dev_lim->local_ca_ack_delay;
mdev->limits.max_sg = min_t(int, dev_lim->max_sg,
(dev_lim->max_desc_sz -
sizeof (struct mthca_next_seg) -
(mthca_is_memfree(mdev) ?
sizeof (struct mthca_arbel_ud_seg) :
sizeof (struct mthca_tavor_ud_seg))) /
sizeof (struct mthca_data_seg));
mdev->limits.max_wqes = dev_lim->max_qp_sz;
mdev->limits.max_qp_init_rdma = dev_lim->max_requester_per_qp;
mdev->limits.reserved_qps = dev_lim->reserved_qps;
mdev->limits.max_srq_wqes = dev_lim->max_srq_sz;
mdev->limits.reserved_srqs = dev_lim->reserved_srqs;
mdev->limits.reserved_eecs = dev_lim->reserved_eecs;
mdev->limits.max_desc_sz = dev_lim->max_desc_sz;
mdev->limits.max_srq_sge = mthca_max_srq_sge(mdev);
mdev->limits.max_cqes = dev_lim->max_cq_sz - 1;
mdev->limits.reserved_cqs = dev_lim->reserved_cqs;
mdev->limits.reserved_eqs = dev_lim->reserved_eqs;
mdev->limits.reserved_mtts = dev_lim->reserved_mtts;
mdev->limits.reserved_mrws = dev_lim->reserved_mrws;
mdev->limits.reserved_uars = dev_lim->reserved_uars;
mdev->limits.reserved_pds = dev_lim->reserved_pds;
mdev->limits.port_width_cap = dev_lim->max_port_width;
mdev->limits.page_size_cap = ~(u32) (dev_lim->min_page_sz - 1);
mdev->limits.flags = dev_lim->flags;
if (dev_lim->stat_rate_support)
mdev->limits.stat_rate_support = dev_lim->stat_rate_support;
else if (mdev->mthca_flags & MTHCA_FLAG_SINAI_OPT)
mdev->limits.stat_rate_support = 0xf;
else
mdev->limits.stat_rate_support = 0x3;
mdev->device_cap_flags = IB_DEVICE_CHANGE_PHY_PORT |
IB_DEVICE_PORT_ACTIVE_EVENT |
IB_DEVICE_SYS_IMAGE_GUID |
IB_DEVICE_RC_RNR_NAK_GEN;
if (dev_lim->flags & DEV_LIM_FLAG_BAD_PKEY_CNTR)
mdev->device_cap_flags |= IB_DEVICE_BAD_PKEY_CNTR;
if (dev_lim->flags & DEV_LIM_FLAG_BAD_QKEY_CNTR)
mdev->device_cap_flags |= IB_DEVICE_BAD_QKEY_CNTR;
if (dev_lim->flags & DEV_LIM_FLAG_RAW_MULTI)
mdev->device_cap_flags |= IB_DEVICE_RAW_MULTI;
if (dev_lim->flags & DEV_LIM_FLAG_AUTO_PATH_MIG)
mdev->device_cap_flags |= IB_DEVICE_AUTO_PATH_MIG;
if (dev_lim->flags & DEV_LIM_FLAG_UD_AV_PORT_ENFORCE)
mdev->device_cap_flags |= IB_DEVICE_UD_AV_PORT_ENFORCE;
if (dev_lim->flags & DEV_LIM_FLAG_SRQ)
mdev->mthca_flags |= MTHCA_FLAG_SRQ;
if (mthca_is_memfree(mdev))
if (dev_lim->flags & DEV_LIM_FLAG_IPOIB_CSUM)
mdev->device_cap_flags |= IB_DEVICE_UD_IP_CSUM;
return 0;
}
static int mthca_init_tavor(struct mthca_dev *mdev)
{
s64 size;
u8 status;
int err;
struct mthca_dev_lim dev_lim;
struct mthca_profile profile;
struct mthca_init_hca_param init_hca;
err = mthca_SYS_EN(mdev, &status);
if (err) {
mthca_err(mdev, "SYS_EN command failed, aborting.\n");
return err;
}
if (status) {
mthca_err(mdev, "SYS_EN returned status 0x%02x, "
"aborting.\n", status);
return -EINVAL;
}
err = mthca_QUERY_FW(mdev, &status);
if (err) {
mthca_err(mdev, "QUERY_FW command failed, aborting.\n");
goto err_disable;
}
if (status) {
mthca_err(mdev, "QUERY_FW returned status 0x%02x, "
"aborting.\n", status);
err = -EINVAL;
goto err_disable;
}
err = mthca_QUERY_DDR(mdev, &status);
if (err) {
mthca_err(mdev, "QUERY_DDR command failed, aborting.\n");
goto err_disable;
}
if (status) {
mthca_err(mdev, "QUERY_DDR returned status 0x%02x, "
"aborting.\n", status);
err = -EINVAL;
goto err_disable;
}
err = mthca_dev_lim(mdev, &dev_lim);
if (err) {
mthca_err(mdev, "QUERY_DEV_LIM command failed, aborting.\n");
goto err_disable;
}
profile = hca_profile;
profile.num_uar = dev_lim.uar_size / PAGE_SIZE;
profile.uarc_size = 0;
if (mdev->mthca_flags & MTHCA_FLAG_SRQ)
profile.num_srq = dev_lim.max_srqs;
size = mthca_make_profile(mdev, &profile, &dev_lim, &init_hca);
if (size < 0) {
err = size;
goto err_disable;
}
err = mthca_INIT_HCA(mdev, &init_hca, &status);
if (err) {
mthca_err(mdev, "INIT_HCA command failed, aborting.\n");
goto err_disable;
}
if (status) {
mthca_err(mdev, "INIT_HCA returned status 0x%02x, "
"aborting.\n", status);
err = -EINVAL;
goto err_disable;
}
return 0;
err_disable:
mthca_SYS_DIS(mdev, &status);
return err;
}
static int mthca_load_fw(struct mthca_dev *mdev)
{
u8 status;
int err;
mdev->fw.arbel.fw_icm =
mthca_alloc_icm(mdev, mdev->fw.arbel.fw_pages,
GFP_HIGHUSER | __GFP_NOWARN, 0);
if (!mdev->fw.arbel.fw_icm) {
mthca_err(mdev, "Couldn't allocate FW area, aborting.\n");
return -ENOMEM;
}
err = mthca_MAP_FA(mdev, mdev->fw.arbel.fw_icm, &status);
if (err) {
mthca_err(mdev, "MAP_FA command failed, aborting.\n");
goto err_free;
}
if (status) {
mthca_err(mdev, "MAP_FA returned status 0x%02x, aborting.\n", status);
err = -EINVAL;
goto err_free;
}
err = mthca_RUN_FW(mdev, &status);
if (err) {
mthca_err(mdev, "RUN_FW command failed, aborting.\n");
goto err_unmap_fa;
}
if (status) {
mthca_err(mdev, "RUN_FW returned status 0x%02x, aborting.\n", status);
err = -EINVAL;
goto err_unmap_fa;
}
return 0;
err_unmap_fa:
mthca_UNMAP_FA(mdev, &status);
err_free:
mthca_free_icm(mdev, mdev->fw.arbel.fw_icm, 0);
return err;
}
static int mthca_init_icm(struct mthca_dev *mdev,
struct mthca_dev_lim *dev_lim,
struct mthca_init_hca_param *init_hca,
u64 icm_size)
{
u64 aux_pages;
u8 status;
int err;
err = mthca_SET_ICM_SIZE(mdev, icm_size, &aux_pages, &status);
if (err) {
mthca_err(mdev, "SET_ICM_SIZE command failed, aborting.\n");
return err;
}
if (status) {
mthca_err(mdev, "SET_ICM_SIZE returned status 0x%02x, "
"aborting.\n", status);
return -EINVAL;
}
mthca_dbg(mdev, "%lld KB of HCA context requires %lld KB aux memory.\n",
(unsigned long long) icm_size >> 10,
(unsigned long long) aux_pages << 2);
mdev->fw.arbel.aux_icm = mthca_alloc_icm(mdev, aux_pages,
GFP_HIGHUSER | __GFP_NOWARN, 0);
if (!mdev->fw.arbel.aux_icm) {
mthca_err(mdev, "Couldn't allocate aux memory, aborting.\n");
return -ENOMEM;
}
err = mthca_MAP_ICM_AUX(mdev, mdev->fw.arbel.aux_icm, &status);
if (err) {
mthca_err(mdev, "MAP_ICM_AUX command failed, aborting.\n");
goto err_free_aux;
}
if (status) {
mthca_err(mdev, "MAP_ICM_AUX returned status 0x%02x, aborting.\n", status);
err = -EINVAL;
goto err_free_aux;
}
err = mthca_map_eq_icm(mdev, init_hca->eqc_base);
if (err) {
mthca_err(mdev, "Failed to map EQ context memory, aborting.\n");
goto err_unmap_aux;
}
mdev->limits.reserved_mtts = ALIGN(mdev->limits.reserved_mtts * mdev->limits.mtt_seg_size,
dma_get_cache_alignment()) / mdev->limits.mtt_seg_size;
mdev->mr_table.mtt_table = mthca_alloc_icm_table(mdev, init_hca->mtt_base,
mdev->limits.mtt_seg_size,
mdev->limits.num_mtt_segs,
mdev->limits.reserved_mtts,
1, 0);
if (!mdev->mr_table.mtt_table) {
mthca_err(mdev, "Failed to map MTT context memory, aborting.\n");
err = -ENOMEM;
goto err_unmap_eq;
}
mdev->mr_table.mpt_table = mthca_alloc_icm_table(mdev, init_hca->mpt_base,
dev_lim->mpt_entry_sz,
mdev->limits.num_mpts,
mdev->limits.reserved_mrws,
1, 1);
if (!mdev->mr_table.mpt_table) {
mthca_err(mdev, "Failed to map MPT context memory, aborting.\n");
err = -ENOMEM;
goto err_unmap_mtt;
}
mdev->qp_table.qp_table = mthca_alloc_icm_table(mdev, init_hca->qpc_base,
dev_lim->qpc_entry_sz,
mdev->limits.num_qps,
mdev->limits.reserved_qps,
0, 0);
if (!mdev->qp_table.qp_table) {
mthca_err(mdev, "Failed to map QP context memory, aborting.\n");
err = -ENOMEM;
goto err_unmap_mpt;
}
mdev->qp_table.eqp_table = mthca_alloc_icm_table(mdev, init_hca->eqpc_base,
dev_lim->eqpc_entry_sz,
mdev->limits.num_qps,
mdev->limits.reserved_qps,
0, 0);
if (!mdev->qp_table.eqp_table) {
mthca_err(mdev, "Failed to map EQP context memory, aborting.\n");
err = -ENOMEM;
goto err_unmap_qp;
}
mdev->qp_table.rdb_table = mthca_alloc_icm_table(mdev, init_hca->rdb_base,
MTHCA_RDB_ENTRY_SIZE,
mdev->limits.num_qps <<
mdev->qp_table.rdb_shift, 0,
0, 0);
if (!mdev->qp_table.rdb_table) {
mthca_err(mdev, "Failed to map RDB context memory, aborting\n");
err = -ENOMEM;
goto err_unmap_eqp;
}
mdev->cq_table.table = mthca_alloc_icm_table(mdev, init_hca->cqc_base,
dev_lim->cqc_entry_sz,
mdev->limits.num_cqs,
mdev->limits.reserved_cqs,
0, 0);
if (!mdev->cq_table.table) {
mthca_err(mdev, "Failed to map CQ context memory, aborting.\n");
err = -ENOMEM;
goto err_unmap_rdb;
}
if (mdev->mthca_flags & MTHCA_FLAG_SRQ) {
mdev->srq_table.table =
mthca_alloc_icm_table(mdev, init_hca->srqc_base,
dev_lim->srq_entry_sz,
mdev->limits.num_srqs,
mdev->limits.reserved_srqs,
0, 0);
if (!mdev->srq_table.table) {
mthca_err(mdev, "Failed to map SRQ context memory, "
"aborting.\n");
err = -ENOMEM;
goto err_unmap_cq;
}
}
mdev->mcg_table.table = mthca_alloc_icm_table(mdev, init_hca->mc_base,
MTHCA_MGM_ENTRY_SIZE,
mdev->limits.num_mgms +
mdev->limits.num_amgms,
mdev->limits.num_mgms +
mdev->limits.num_amgms,
0, 0);
if (!mdev->mcg_table.table) {
mthca_err(mdev, "Failed to map MCG context memory, aborting.\n");
err = -ENOMEM;
goto err_unmap_srq;
}
return 0;
err_unmap_srq:
if (mdev->mthca_flags & MTHCA_FLAG_SRQ)
mthca_free_icm_table(mdev, mdev->srq_table.table);
err_unmap_cq:
mthca_free_icm_table(mdev, mdev->cq_table.table);
err_unmap_rdb:
mthca_free_icm_table(mdev, mdev->qp_table.rdb_table);
err_unmap_eqp:
mthca_free_icm_table(mdev, mdev->qp_table.eqp_table);
err_unmap_qp:
mthca_free_icm_table(mdev, mdev->qp_table.qp_table);
err_unmap_mpt:
mthca_free_icm_table(mdev, mdev->mr_table.mpt_table);
err_unmap_mtt:
mthca_free_icm_table(mdev, mdev->mr_table.mtt_table);
err_unmap_eq:
mthca_unmap_eq_icm(mdev);
err_unmap_aux:
mthca_UNMAP_ICM_AUX(mdev, &status);
err_free_aux:
mthca_free_icm(mdev, mdev->fw.arbel.aux_icm, 0);
return err;
}
static void mthca_free_icms(struct mthca_dev *mdev)
{
u8 status;
mthca_free_icm_table(mdev, mdev->mcg_table.table);
if (mdev->mthca_flags & MTHCA_FLAG_SRQ)
mthca_free_icm_table(mdev, mdev->srq_table.table);
mthca_free_icm_table(mdev, mdev->cq_table.table);
mthca_free_icm_table(mdev, mdev->qp_table.rdb_table);
mthca_free_icm_table(mdev, mdev->qp_table.eqp_table);
mthca_free_icm_table(mdev, mdev->qp_table.qp_table);
mthca_free_icm_table(mdev, mdev->mr_table.mpt_table);
mthca_free_icm_table(mdev, mdev->mr_table.mtt_table);
mthca_unmap_eq_icm(mdev);
mthca_UNMAP_ICM_AUX(mdev, &status);
mthca_free_icm(mdev, mdev->fw.arbel.aux_icm, 0);
}
static int mthca_init_arbel(struct mthca_dev *mdev)
{
struct mthca_dev_lim dev_lim;
struct mthca_profile profile;
struct mthca_init_hca_param init_hca;
s64 icm_size;
u8 status;
int err;
err = mthca_QUERY_FW(mdev, &status);
if (err) {
mthca_err(mdev, "QUERY_FW command failed, aborting.\n");
return err;
}
if (status) {
mthca_err(mdev, "QUERY_FW returned status 0x%02x, "
"aborting.\n", status);
return -EINVAL;
}
err = mthca_ENABLE_LAM(mdev, &status);
if (err) {
mthca_err(mdev, "ENABLE_LAM command failed, aborting.\n");
return err;
}
if (status == MTHCA_CMD_STAT_LAM_NOT_PRE) {
mthca_dbg(mdev, "No HCA-attached memory (running in MemFree mode)\n");
mdev->mthca_flags |= MTHCA_FLAG_NO_LAM;
} else if (status) {
mthca_err(mdev, "ENABLE_LAM returned status 0x%02x, "
"aborting.\n", status);
return -EINVAL;
}
err = mthca_load_fw(mdev);
if (err) {
mthca_err(mdev, "Failed to start FW, aborting.\n");
goto err_disable;
}
err = mthca_dev_lim(mdev, &dev_lim);
if (err) {
mthca_err(mdev, "QUERY_DEV_LIM command failed, aborting.\n");
goto err_stop_fw;
}
profile = hca_profile;
profile.num_uar = dev_lim.uar_size / PAGE_SIZE;
profile.num_udav = 0;
if (mdev->mthca_flags & MTHCA_FLAG_SRQ)
profile.num_srq = dev_lim.max_srqs;
icm_size = mthca_make_profile(mdev, &profile, &dev_lim, &init_hca);
if (icm_size < 0) {
err = icm_size;
goto err_stop_fw;
}
err = mthca_init_icm(mdev, &dev_lim, &init_hca, icm_size);
if (err)
goto err_stop_fw;
err = mthca_INIT_HCA(mdev, &init_hca, &status);
if (err) {
mthca_err(mdev, "INIT_HCA command failed, aborting.\n");
goto err_free_icm;
}
if (status) {
mthca_err(mdev, "INIT_HCA returned status 0x%02x, "
"aborting.\n", status);
err = -EINVAL;
goto err_free_icm;
}
return 0;
err_free_icm:
mthca_free_icms(mdev);
err_stop_fw:
mthca_UNMAP_FA(mdev, &status);
mthca_free_icm(mdev, mdev->fw.arbel.fw_icm, 0);
err_disable:
if (!(mdev->mthca_flags & MTHCA_FLAG_NO_LAM))
mthca_DISABLE_LAM(mdev, &status);
return err;
}
static void mthca_close_hca(struct mthca_dev *mdev)
{
u8 status;
mthca_CLOSE_HCA(mdev, 0, &status);
if (mthca_is_memfree(mdev)) {
mthca_free_icms(mdev);
mthca_UNMAP_FA(mdev, &status);
mthca_free_icm(mdev, mdev->fw.arbel.fw_icm, 0);
if (!(mdev->mthca_flags & MTHCA_FLAG_NO_LAM))
mthca_DISABLE_LAM(mdev, &status);
} else
mthca_SYS_DIS(mdev, &status);
}
static int mthca_init_hca(struct mthca_dev *mdev)
{
u8 status;
int err;
struct mthca_adapter adapter;
if (mthca_is_memfree(mdev))
err = mthca_init_arbel(mdev);
else
err = mthca_init_tavor(mdev);
if (err)
return err;
err = mthca_QUERY_ADAPTER(mdev, &adapter, &status);
if (err) {
mthca_err(mdev, "QUERY_ADAPTER command failed, aborting.\n");
goto err_close;
}
if (status) {
mthca_err(mdev, "QUERY_ADAPTER returned status 0x%02x, "
"aborting.\n", status);
err = -EINVAL;
goto err_close;
}
mdev->eq_table.inta_pin = adapter.inta_pin;
if (!mthca_is_memfree(mdev))
mdev->rev_id = adapter.revision_id;
memcpy(mdev->board_id, adapter.board_id, sizeof mdev->board_id);
return 0;
err_close:
mthca_close_hca(mdev);
return err;
}
static int mthca_setup_hca(struct mthca_dev *dev)
{
int err;
u8 status;
MTHCA_INIT_DOORBELL_LOCK(&dev->doorbell_lock);
err = mthca_init_uar_table(dev);
if (err) {
mthca_err(dev, "Failed to initialize "
"user access region table, aborting.\n");
return err;
}
err = mthca_uar_alloc(dev, &dev->driver_uar);
if (err) {
mthca_err(dev, "Failed to allocate driver access region, "
"aborting.\n");
goto err_uar_table_free;
}
dev->kar = ioremap((phys_addr_t) dev->driver_uar.pfn << PAGE_SHIFT, PAGE_SIZE);
if (!dev->kar) {
mthca_err(dev, "Couldn't map kernel access region, "
"aborting.\n");
err = -ENOMEM;
goto err_uar_free;
}
err = mthca_init_pd_table(dev);
if (err) {
mthca_err(dev, "Failed to initialize "
"protection domain table, aborting.\n");
goto err_kar_unmap;
}
err = mthca_init_mr_table(dev);
if (err) {
mthca_err(dev, "Failed to initialize "
"memory region table, aborting.\n");
goto err_pd_table_free;
}
err = mthca_pd_alloc(dev, 1, &dev->driver_pd);
if (err) {
mthca_err(dev, "Failed to create driver PD, "
"aborting.\n");
goto err_mr_table_free;
}
err = mthca_init_eq_table(dev);
if (err) {
mthca_err(dev, "Failed to initialize "
"event queue table, aborting.\n");
goto err_pd_free;
}
err = mthca_cmd_use_events(dev);
if (err) {
mthca_err(dev, "Failed to switch to event-driven "
"firmware commands, aborting.\n");
goto err_eq_table_free;
}
err = mthca_NOP(dev, &status);
if (err || status) {
if (dev->mthca_flags & MTHCA_FLAG_MSI_X) {
mthca_warn(dev, "NOP command failed to generate interrupt "
"(IRQ %d).\n",
dev->eq_table.eq[MTHCA_EQ_CMD].msi_x_vector);
mthca_warn(dev, "Trying again with MSI-X disabled.\n");
} else {
mthca_err(dev, "NOP command failed to generate interrupt "
"(IRQ %d), aborting.\n",
dev->pdev->irq);
mthca_err(dev, "BIOS or ACPI interrupt routing problem?\n");
}
goto err_cmd_poll;
}
mthca_dbg(dev, "NOP command IRQ test passed\n");
err = mthca_init_cq_table(dev);
if (err) {
mthca_err(dev, "Failed to initialize "
"completion queue table, aborting.\n");
goto err_cmd_poll;
}
err = mthca_init_srq_table(dev);
if (err) {
mthca_err(dev, "Failed to initialize "
"shared receive queue table, aborting.\n");
goto err_cq_table_free;
}
err = mthca_init_qp_table(dev);
if (err) {
mthca_err(dev, "Failed to initialize "
"queue pair table, aborting.\n");
goto err_srq_table_free;
}
err = mthca_init_av_table(dev);
if (err) {
mthca_err(dev, "Failed to initialize "
"address vector table, aborting.\n");
goto err_qp_table_free;
}
err = mthca_init_mcg_table(dev);
if (err) {
mthca_err(dev, "Failed to initialize "
"multicast group table, aborting.\n");
goto err_av_table_free;
}
return 0;
err_av_table_free:
mthca_cleanup_av_table(dev);
err_qp_table_free:
mthca_cleanup_qp_table(dev);
err_srq_table_free:
mthca_cleanup_srq_table(dev);
err_cq_table_free:
mthca_cleanup_cq_table(dev);
err_cmd_poll:
mthca_cmd_use_polling(dev);
err_eq_table_free:
mthca_cleanup_eq_table(dev);
err_pd_free:
mthca_pd_free(dev, &dev->driver_pd);
err_mr_table_free:
mthca_cleanup_mr_table(dev);
err_pd_table_free:
mthca_cleanup_pd_table(dev);
err_kar_unmap:
iounmap(dev->kar);
err_uar_free:
mthca_uar_free(dev, &dev->driver_uar);
err_uar_table_free:
mthca_cleanup_uar_table(dev);
return err;
}
static int mthca_enable_msi_x(struct mthca_dev *mdev)
{
struct msix_entry entries[3];
int err;
entries[0].entry = 0;
entries[1].entry = 1;
entries[2].entry = 2;
err = pci_enable_msix(mdev->pdev, entries, ARRAY_SIZE(entries));
if (err) {
if (err > 0)
mthca_info(mdev, "Only %d MSI-X vectors available, "
"not using MSI-X\n", err);
return err;
}
mdev->eq_table.eq[MTHCA_EQ_COMP ].msi_x_vector = entries[0].vector;
mdev->eq_table.eq[MTHCA_EQ_ASYNC].msi_x_vector = entries[1].vector;
mdev->eq_table.eq[MTHCA_EQ_CMD ].msi_x_vector = entries[2].vector;
return 0;
}
static int __mthca_init_one(struct pci_dev *pdev, int hca_type)
{
int ddr_hidden = 0;
int err;
struct mthca_dev *mdev;
printk(KERN_INFO PFX "Initializing %s\n",
pci_name(pdev));
err = pci_enable_device(pdev);
if (err) {
dev_err(&pdev->dev, "Cannot enable PCI device, "
"aborting.\n");
return err;
}
if (!(pci_resource_flags(pdev, 0) & IORESOURCE_MEM) ||
pci_resource_len(pdev, 0) != 1 << 20) {
dev_err(&pdev->dev, "Missing DCS, aborting.\n");
err = -ENODEV;
goto err_disable_pdev;
}
if (!(pci_resource_flags(pdev, 2) & IORESOURCE_MEM)) {
dev_err(&pdev->dev, "Missing UAR, aborting.\n");
err = -ENODEV;
goto err_disable_pdev;
}
if (!(pci_resource_flags(pdev, 4) & IORESOURCE_MEM))
ddr_hidden = 1;
err = pci_request_regions(pdev, DRV_NAME);
if (err) {
dev_err(&pdev->dev, "Cannot obtain PCI resources, "
"aborting.\n");
goto err_disable_pdev;
}
pci_set_master(pdev);
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(64));
if (err) {
dev_warn(&pdev->dev, "Warning: couldn't set 64-bit PCI DMA mask.\n");
err = pci_set_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev, "Can't set PCI DMA mask, aborting.\n");
goto err_free_res;
}
}
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(64));
if (err) {
dev_warn(&pdev->dev, "Warning: couldn't set 64-bit "
"consistent PCI DMA mask.\n");
err = pci_set_consistent_dma_mask(pdev, DMA_BIT_MASK(32));
if (err) {
dev_err(&pdev->dev, "Can't set consistent PCI DMA mask, "
"aborting.\n");
goto err_free_res;
}
}
dma_set_max_seg_size(&pdev->dev, 1024 * 1024 * 1024);
mdev = (struct mthca_dev *) ib_alloc_device(sizeof *mdev);
if (!mdev) {
dev_err(&pdev->dev, "Device struct alloc failed, "
"aborting.\n");
err = -ENOMEM;
goto err_free_res;
}
mdev->pdev = pdev;
mdev->mthca_flags = mthca_hca_table[hca_type].flags;
if (ddr_hidden)
mdev->mthca_flags |= MTHCA_FLAG_DDR_HIDDEN;
err = mthca_reset(mdev);
if (err) {
mthca_err(mdev, "Failed to reset HCA, aborting.\n");
goto err_free_dev;
}
if (mthca_cmd_init(mdev)) {
mthca_err(mdev, "Failed to init command interface, aborting.\n");
goto err_free_dev;
}
err = mthca_tune_pci(mdev);
if (err)
goto err_cmd;
err = mthca_init_hca(mdev);
if (err)
goto err_cmd;
if (mdev->fw_ver < mthca_hca_table[hca_type].latest_fw) {
mthca_warn(mdev, "HCA FW version %d.%d.%03d is old (%d.%d.%03d is current).\n",
(int) (mdev->fw_ver >> 32), (int) (mdev->fw_ver >> 16) & 0xffff,
(int) (mdev->fw_ver & 0xffff),
(int) (mthca_hca_table[hca_type].latest_fw >> 32),
(int) (mthca_hca_table[hca_type].latest_fw >> 16) & 0xffff,
(int) (mthca_hca_table[hca_type].latest_fw & 0xffff));
mthca_warn(mdev, "If you have problems, try updating your HCA FW.\n");
}
if (msi_x && !mthca_enable_msi_x(mdev))
mdev->mthca_flags |= MTHCA_FLAG_MSI_X;
err = mthca_setup_hca(mdev);
if (err == -EBUSY && (mdev->mthca_flags & MTHCA_FLAG_MSI_X)) {
if (mdev->mthca_flags & MTHCA_FLAG_MSI_X)
pci_disable_msix(pdev);
mdev->mthca_flags &= ~MTHCA_FLAG_MSI_X;
err = mthca_setup_hca(mdev);
}
if (err)
goto err_close;
err = mthca_register_device(mdev);
if (err)
goto err_cleanup;
err = mthca_create_agents(mdev);
if (err)
goto err_unregister;
pci_set_drvdata(pdev, mdev);
mdev->hca_type = hca_type;
mdev->active = true;
return 0;
err_unregister:
mthca_unregister_device(mdev);
err_cleanup:
mthca_cleanup_mcg_table(mdev);
mthca_cleanup_av_table(mdev);
mthca_cleanup_qp_table(mdev);
mthca_cleanup_srq_table(mdev);
mthca_cleanup_cq_table(mdev);
mthca_cmd_use_polling(mdev);
mthca_cleanup_eq_table(mdev);
mthca_pd_free(mdev, &mdev->driver_pd);
mthca_cleanup_mr_table(mdev);
mthca_cleanup_pd_table(mdev);
mthca_cleanup_uar_table(mdev);
err_close:
if (mdev->mthca_flags & MTHCA_FLAG_MSI_X)
pci_disable_msix(pdev);
mthca_close_hca(mdev);
err_cmd:
mthca_cmd_cleanup(mdev);
err_free_dev:
ib_dealloc_device(&mdev->ib_dev);
err_free_res:
pci_release_regions(pdev);
err_disable_pdev:
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
return err;
}
static void __mthca_remove_one(struct pci_dev *pdev)
{
struct mthca_dev *mdev = pci_get_drvdata(pdev);
u8 status;
int p;
if (mdev) {
mthca_free_agents(mdev);
mthca_unregister_device(mdev);
for (p = 1; p <= mdev->limits.num_ports; ++p)
mthca_CLOSE_IB(mdev, p, &status);
mthca_cleanup_mcg_table(mdev);
mthca_cleanup_av_table(mdev);
mthca_cleanup_qp_table(mdev);
mthca_cleanup_srq_table(mdev);
mthca_cleanup_cq_table(mdev);
mthca_cmd_use_polling(mdev);
mthca_cleanup_eq_table(mdev);
mthca_pd_free(mdev, &mdev->driver_pd);
mthca_cleanup_mr_table(mdev);
mthca_cleanup_pd_table(mdev);
iounmap(mdev->kar);
mthca_uar_free(mdev, &mdev->driver_uar);
mthca_cleanup_uar_table(mdev);
mthca_close_hca(mdev);
mthca_cmd_cleanup(mdev);
if (mdev->mthca_flags & MTHCA_FLAG_MSI_X)
pci_disable_msix(pdev);
ib_dealloc_device(&mdev->ib_dev);
pci_release_regions(pdev);
pci_disable_device(pdev);
pci_set_drvdata(pdev, NULL);
}
}
int __mthca_restart_one(struct pci_dev *pdev)
{
struct mthca_dev *mdev;
int hca_type;
mdev = pci_get_drvdata(pdev);
if (!mdev)
return -ENODEV;
hca_type = mdev->hca_type;
__mthca_remove_one(pdev);
return __mthca_init_one(pdev, hca_type);
}
static int __devinit mthca_init_one(struct pci_dev *pdev,
const struct pci_device_id *id)
{
int ret;
mutex_lock(&mthca_device_mutex);
printk_once(KERN_INFO "%s", mthca_version);
if (id->driver_data >= ARRAY_SIZE(mthca_hca_table)) {
printk(KERN_ERR PFX "%s has invalid driver data %lx\n",
pci_name(pdev), id->driver_data);
mutex_unlock(&mthca_device_mutex);
return -ENODEV;
}
ret = __mthca_init_one(pdev, id->driver_data);
mutex_unlock(&mthca_device_mutex);
return ret;
}
static void __devexit mthca_remove_one(struct pci_dev *pdev)
{
mutex_lock(&mthca_device_mutex);
__mthca_remove_one(pdev);
mutex_unlock(&mthca_device_mutex);
}
static void __init __mthca_check_profile_val(const char *name, int *pval,
int pval_default)
{
int old_pval = *pval;
if (old_pval <= 0)
*pval = pval_default;
else
*pval = roundup_pow_of_two(old_pval);
if (old_pval != *pval) {
printk(KERN_WARNING PFX "Invalid value %d for %s in module parameter.\n",
old_pval, name);
printk(KERN_WARNING PFX "Corrected %s to %d.\n", name, *pval);
}
}
static void __init mthca_validate_profile(void)
{
mthca_check_profile_val(num_qp, MTHCA_DEFAULT_NUM_QP);
mthca_check_profile_val(rdb_per_qp, MTHCA_DEFAULT_RDB_PER_QP);
mthca_check_profile_val(num_cq, MTHCA_DEFAULT_NUM_CQ);
mthca_check_profile_val(num_mcg, MTHCA_DEFAULT_NUM_MCG);
mthca_check_profile_val(num_mpt, MTHCA_DEFAULT_NUM_MPT);
mthca_check_profile_val(num_mtt, MTHCA_DEFAULT_NUM_MTT);
mthca_check_profile_val(num_udav, MTHCA_DEFAULT_NUM_UDAV);
mthca_check_profile_val(fmr_reserved_mtts, MTHCA_DEFAULT_NUM_RESERVED_MTTS);
if (hca_profile.fmr_reserved_mtts >= hca_profile.num_mtt) {
printk(KERN_WARNING PFX "Invalid fmr_reserved_mtts module parameter %d.\n",
hca_profile.fmr_reserved_mtts);
printk(KERN_WARNING PFX "(Must be smaller than num_mtt %d)\n",
hca_profile.num_mtt);
hca_profile.fmr_reserved_mtts = hca_profile.num_mtt / 2;
printk(KERN_WARNING PFX "Corrected fmr_reserved_mtts to %d.\n",
hca_profile.fmr_reserved_mtts);
}
if ((log_mtts_per_seg < 1) || (log_mtts_per_seg > 5)) {
printk(KERN_WARNING PFX "bad log_mtts_per_seg (%d). Using default - %d\n",
log_mtts_per_seg, ilog2(MTHCA_MTT_SEG_SIZE / 8));
log_mtts_per_seg = ilog2(MTHCA_MTT_SEG_SIZE / 8);
}
}
static int __init mthca_init(void)
{
int ret;
mthca_validate_profile();
ret = mthca_catas_init();
if (ret)
return ret;
ret = pci_register_driver(&mthca_driver);
if (ret < 0) {
mthca_catas_cleanup();
return ret;
}
return 0;
}
static void __exit mthca_cleanup(void)
{
pci_unregister_driver(&mthca_driver);
mthca_catas_cleanup();
}
