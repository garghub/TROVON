static void ssb_sflash_cmd(struct ssb_chipcommon *cc, u32 opcode)
{
int i;
chipco_write32(cc, SSB_CHIPCO_FLASHCTL,
SSB_CHIPCO_FLASHCTL_START | opcode);
for (i = 0; i < 1000; i++) {
if (!(chipco_read32(cc, SSB_CHIPCO_FLASHCTL) &
SSB_CHIPCO_FLASHCTL_BUSY))
return;
cpu_relax();
}
pr_err("SFLASH control command failed (timeout)!\n");
}
int ssb_sflash_init(struct ssb_chipcommon *cc)
{
struct ssb_sflash *sflash = &cc->dev->bus->mipscore.sflash;
const struct ssb_sflash_tbl_e *e;
u32 id, id2;
switch (cc->capabilities & SSB_CHIPCO_CAP_FLASHT) {
case SSB_CHIPCO_FLASHT_STSER:
ssb_sflash_cmd(cc, SSB_CHIPCO_FLASHCTL_ST_DP);
chipco_write32(cc, SSB_CHIPCO_FLASHADDR, 0);
ssb_sflash_cmd(cc, SSB_CHIPCO_FLASHCTL_ST_RES);
id = chipco_read32(cc, SSB_CHIPCO_FLASHDATA);
chipco_write32(cc, SSB_CHIPCO_FLASHADDR, 1);
ssb_sflash_cmd(cc, SSB_CHIPCO_FLASHCTL_ST_RES);
id2 = chipco_read32(cc, SSB_CHIPCO_FLASHDATA);
switch (id) {
case 0xbf:
for (e = ssb_sflash_sst_tbl; e->name; e++) {
if (e->id == id2)
break;
}
break;
case 0x13:
return -ENOTSUPP;
default:
for (e = ssb_sflash_st_tbl; e->name; e++) {
if (e->id == id)
break;
}
break;
}
if (!e->name) {
pr_err("Unsupported ST serial flash (id: 0x%X, id2: 0x%X)\n",
id, id2);
return -ENOTSUPP;
}
break;
case SSB_CHIPCO_FLASHT_ATSER:
ssb_sflash_cmd(cc, SSB_CHIPCO_FLASHCTL_AT_STATUS);
id = chipco_read32(cc, SSB_CHIPCO_FLASHDATA) & 0x3c;
for (e = ssb_sflash_at_tbl; e->name; e++) {
if (e->id == id)
break;
}
if (!e->name) {
pr_err("Unsupported Atmel serial flash (id: 0x%X)\n",
id);
return -ENOTSUPP;
}
break;
default:
pr_err("Unsupported flash type\n");
return -ENOTSUPP;
}
sflash->window = SSB_FLASH2;
sflash->blocksize = e->blocksize;
sflash->numblocks = e->numblocks;
sflash->size = sflash->blocksize * sflash->numblocks;
sflash->present = true;
pr_info("Found %s serial flash (size: %dKiB, blocksize: 0x%X, blocks: %d)\n",
e->name, sflash->size / 1024, e->blocksize, e->numblocks);
ssb_sflash_dev.resource[0].end = ssb_sflash_dev.resource[0].start +
sflash->size;
ssb_sflash_dev.dev.platform_data = sflash;
return 0;
}
