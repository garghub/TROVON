int bcma_nflash_init(struct bcma_drv_cc *cc)
{
struct bcma_bus *bus = cc->core->bus;
if (bus->chipinfo.id != BCMA_CHIP_ID_BCM4706 &&
cc->core->id.rev != 0x38) {
bcma_err(bus, "NAND flash on unsupported board!\n");
return -ENOTSUPP;
}
if (!(cc->capabilities & BCMA_CC_CAP_NFLASH)) {
bcma_err(bus, "NAND flash not present according to ChipCommon\n");
return -ENODEV;
}
cc->nflash.present = true;
bcma_nflash_dev.dev.platform_data = &cc->nflash;
return 0;
}
