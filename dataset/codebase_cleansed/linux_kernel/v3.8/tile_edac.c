static void tile_edac_check(struct mem_ctl_info *mci)
{
struct tile_edac_priv *priv = mci->pvt_info;
struct mshim_mem_error mem_error;
if (hv_dev_pread(priv->hv_devhdl, 0, (HV_VirtAddr)&mem_error,
sizeof(struct mshim_mem_error), MSHIM_MEM_ERROR_OFF) !=
sizeof(struct mshim_mem_error)) {
pr_err(DRV_NAME ": MSHIM_MEM_ERROR_OFF pread failure.\n");
return;
}
if (mem_error.sbe_count != priv->ce_count) {
dev_dbg(mci->pdev, "ECC CE err on node %d\n", priv->node);
priv->ce_count = mem_error.sbe_count;
edac_mc_handle_error(HW_EVENT_ERR_CORRECTED, mci, 1,
0, 0, 0,
0, 0, -1,
mci->ctl_name, "");
}
}
static int tile_edac_init_csrows(struct mem_ctl_info *mci)
{
struct csrow_info *csrow = mci->csrows[0];
struct tile_edac_priv *priv = mci->pvt_info;
struct mshim_mem_info mem_info;
struct dimm_info *dimm = csrow->channels[0]->dimm;
if (hv_dev_pread(priv->hv_devhdl, 0, (HV_VirtAddr)&mem_info,
sizeof(struct mshim_mem_info), MSHIM_MEM_INFO_OFF) !=
sizeof(struct mshim_mem_info)) {
pr_err(DRV_NAME ": MSHIM_MEM_INFO_OFF pread failure.\n");
return -1;
}
if (mem_info.mem_ecc)
dimm->edac_mode = EDAC_SECDED;
else
dimm->edac_mode = EDAC_NONE;
switch (mem_info.mem_type) {
case DDR2:
dimm->mtype = MEM_DDR2;
break;
case DDR3:
dimm->mtype = MEM_DDR3;
break;
default:
return -1;
}
dimm->nr_pages = mem_info.mem_size >> PAGE_SHIFT;
dimm->grain = TILE_EDAC_ERROR_GRAIN;
dimm->dtype = DEV_UNKNOWN;
return 0;
}
static int tile_edac_mc_probe(struct platform_device *pdev)
{
char hv_file[32];
int hv_devhdl;
struct mem_ctl_info *mci;
struct edac_mc_layer layers[2];
struct tile_edac_priv *priv;
int rc;
sprintf(hv_file, "mshim/%d", pdev->id);
hv_devhdl = hv_dev_open((HV_VirtAddr)hv_file, 0);
if (hv_devhdl < 0)
return -EINVAL;
layers[0].type = EDAC_MC_LAYER_CHIP_SELECT;
layers[0].size = TILE_EDAC_NR_CSROWS;
layers[0].is_virt_csrow = true;
layers[1].type = EDAC_MC_LAYER_CHANNEL;
layers[1].size = TILE_EDAC_NR_CHANS;
layers[1].is_virt_csrow = false;
mci = edac_mc_alloc(pdev->id, ARRAY_SIZE(layers), layers,
sizeof(struct tile_edac_priv));
if (mci == NULL)
return -ENOMEM;
priv = mci->pvt_info;
priv->node = pdev->id;
priv->hv_devhdl = hv_devhdl;
mci->pdev = &pdev->dev;
mci->mtype_cap = MEM_FLAG_DDR2;
mci->edac_ctl_cap = EDAC_FLAG_SECDED;
mci->mod_name = DRV_NAME;
#ifdef __tilegx__
mci->ctl_name = "TILEGx_Memory_Controller";
#else
mci->ctl_name = "TILEPro_Memory_Controller";
#endif
mci->dev_name = dev_name(&pdev->dev);
mci->edac_check = tile_edac_check;
if (tile_edac_init_csrows(mci)) {
mci->edac_cap = EDAC_FLAG_NONE;
} else {
mci->edac_cap = EDAC_FLAG_SECDED;
}
platform_set_drvdata(pdev, mci);
rc = edac_mc_add_mc(mci);
if (rc) {
dev_err(&pdev->dev, "failed to register with EDAC core\n");
edac_mc_free(mci);
return rc;
}
return 0;
}
static int tile_edac_mc_remove(struct platform_device *pdev)
{
struct mem_ctl_info *mci = platform_get_drvdata(pdev);
edac_mc_del_mc(&pdev->dev);
if (mci)
edac_mc_free(mci);
return 0;
}
static int __init tile_edac_init(void)
{
char hv_file[32];
struct platform_device *pdev;
int i, err, num = 0;
edac_op_state = EDAC_OPSTATE_POLL;
err = platform_driver_register(&tile_edac_mc_driver);
if (err)
return err;
for (i = 0; i < TILE_MAX_MSHIMS; i++) {
sprintf(hv_file, "mshim/%d", i);
if (hv_dev_open((HV_VirtAddr)hv_file, 0) < 0)
continue;
pdev = platform_device_register_simple(DRV_NAME, i, NULL, 0);
if (IS_ERR(pdev))
continue;
mshim_pdev[i] = pdev;
num++;
}
if (num == 0) {
platform_driver_unregister(&tile_edac_mc_driver);
return -ENODEV;
}
return 0;
}
static void __exit tile_edac_exit(void)
{
int i;
for (i = 0; i < TILE_MAX_MSHIMS; i++) {
struct platform_device *pdev = mshim_pdev[i];
if (!pdev)
continue;
platform_set_drvdata(pdev, NULL);
platform_device_unregister(pdev);
}
platform_driver_unregister(&tile_edac_mc_driver);
}
