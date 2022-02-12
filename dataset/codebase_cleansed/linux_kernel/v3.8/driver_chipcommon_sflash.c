static void bcma_sflash_cmd(struct bcma_drv_cc *cc, u32 opcode)
{
int i;
bcma_cc_write32(cc, BCMA_CC_FLASHCTL,
BCMA_CC_FLASHCTL_START | opcode);
for (i = 0; i < 1000; i++) {
if (!(bcma_cc_read32(cc, BCMA_CC_FLASHCTL) &
BCMA_CC_FLASHCTL_BUSY))
return;
cpu_relax();
}
bcma_err(cc->core->bus, "SFLASH control command failed (timeout)!\n");
}
int bcma_sflash_init(struct bcma_drv_cc *cc)
{
struct bcma_bus *bus = cc->core->bus;
struct bcma_sflash *sflash = &cc->sflash;
struct bcma_sflash_tbl_e *e;
u32 id, id2;
switch (cc->capabilities & BCMA_CC_CAP_FLASHT) {
case BCMA_CC_FLASHT_STSER:
bcma_sflash_cmd(cc, BCMA_CC_FLASHCTL_ST_DP);
bcma_cc_write32(cc, BCMA_CC_FLASHADDR, 0);
bcma_sflash_cmd(cc, BCMA_CC_FLASHCTL_ST_RES);
id = bcma_cc_read32(cc, BCMA_CC_FLASHDATA);
bcma_cc_write32(cc, BCMA_CC_FLASHADDR, 1);
bcma_sflash_cmd(cc, BCMA_CC_FLASHCTL_ST_RES);
id2 = bcma_cc_read32(cc, BCMA_CC_FLASHDATA);
switch (id) {
case 0xbf:
for (e = bcma_sflash_sst_tbl; e->name; e++) {
if (e->id == id2)
break;
}
break;
case 0x13:
return -ENOTSUPP;
default:
for (e = bcma_sflash_st_tbl; e->name; e++) {
if (e->id == id)
break;
}
break;
}
if (!e->name) {
bcma_err(bus, "Unsupported ST serial flash (id: 0x%X, id2: 0x%X)\n", id, id2);
return -ENOTSUPP;
}
break;
case BCMA_CC_FLASHT_ATSER:
bcma_sflash_cmd(cc, BCMA_CC_FLASHCTL_AT_STATUS);
id = bcma_cc_read32(cc, BCMA_CC_FLASHDATA) & 0x3c;
for (e = bcma_sflash_at_tbl; e->name; e++) {
if (e->id == id)
break;
}
if (!e->name) {
bcma_err(bus, "Unsupported Atmel serial flash (id: 0x%X)\n", id);
return -ENOTSUPP;
}
break;
default:
bcma_err(bus, "Unsupported flash type\n");
return -ENOTSUPP;
}
sflash->window = BCMA_SOC_FLASH2;
sflash->blocksize = e->blocksize;
sflash->numblocks = e->numblocks;
sflash->size = sflash->blocksize * sflash->numblocks;
sflash->present = true;
bcma_info(bus, "Found %s serial flash (size: %dKiB, blocksize: 0x%X, blocks: %d)\n",
e->name, sflash->size / 1024, sflash->blocksize,
sflash->numblocks);
bcma_sflash_dev.resource[0].end = bcma_sflash_dev.resource[0].start +
sflash->size;
bcma_sflash_dev.dev.platform_data = sflash;
return 0;
}
