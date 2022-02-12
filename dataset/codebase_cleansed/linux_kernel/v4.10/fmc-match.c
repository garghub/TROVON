void *fru_alloc(size_t size)
{
return kzalloc(size, GFP_KERNEL);
}
int fmc_match(struct device *dev, struct device_driver *drv)
{
struct fmc_driver *fdrv = to_fmc_driver(drv);
struct fmc_device *fdev = to_fmc_device(dev);
struct fmc_fru_id *fid;
int i, matched = 0;
fid = fdrv->id_table.fru_id;
if (!fid) {
dev_warn(&fdev->dev, "Driver has no ID: matches all\n");
matched = 1;
} else {
if (!fdev->id.manufacturer || !fdev->id.product_name)
return 0;
for (i = 0; i < fdrv->id_table.fru_id_nr; i++, fid++) {
if (fid->manufacturer &&
strcmp(fid->manufacturer, fdev->id.manufacturer))
continue;
if (fid->product_name &&
strcmp(fid->product_name, fdev->id.product_name))
continue;
matched = 1;
break;
}
}
return matched;
}
int fmc_fill_id_info(struct fmc_device *fmc)
{
struct fru_common_header *h;
struct fru_board_info_area *bia;
int ret, allocated = 0;
if (fmc->eeprom_len && !fmc->eeprom) {
fmc->eeprom = kzalloc(fmc->eeprom_len, GFP_KERNEL);
if (!fmc->eeprom)
return -ENOMEM;
allocated = 1;
ret = fmc->op->read_ee(fmc, 0, fmc->eeprom, fmc->eeprom_len);
if (ret < 0)
goto out;
}
if (!fmc->eeprom)
return 0;
dev_info(fmc->hwdev, "mezzanine %i\n", fmc->slot_id);
h = (void *)fmc->eeprom;
if (h->format != 1) {
pr_info(" EEPROM has no FRU information\n");
goto out;
}
if (!fru_header_cksum_ok(h)) {
pr_info(" FRU: wrong header checksum\n");
goto out;
}
bia = fru_get_board_area(h);
if (!fru_bia_cksum_ok(bia)) {
pr_info(" FRU: wrong board area checksum\n");
goto out;
}
fmc->id.manufacturer = fru_get_board_manufacturer(h);
fmc->id.product_name = fru_get_product_name(h);
pr_info(" Manufacturer: %s\n", fmc->id.manufacturer);
pr_info(" Product name: %s\n", fmc->id.product_name);
fmc->mezzanine_name = kstrdup(fmc->id.product_name, GFP_KERNEL);
out:
if (allocated) {
kfree(fmc->eeprom);
fmc->eeprom = NULL;
}
return 0;
}
void fmc_free_id_info(struct fmc_device *fmc)
{
kfree(fmc->mezzanine_name);
kfree(fmc->id.manufacturer);
kfree(fmc->id.product_name);
}
