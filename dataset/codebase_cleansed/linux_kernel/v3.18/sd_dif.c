void sd_dif_config_host(struct scsi_disk *sdkp)
{
struct scsi_device *sdp = sdkp->device;
struct gendisk *disk = sdkp->disk;
u8 type = sdkp->protection_type;
int dif, dix;
dif = scsi_host_dif_capable(sdp->host, type);
dix = scsi_host_dix_capable(sdp->host, type);
if (!dix && scsi_host_dix_capable(sdp->host, 0)) {
dif = 0; dix = 1;
}
if (!dix)
return;
if (scsi_host_get_guard(sdkp->device->host) & SHOST_DIX_GUARD_IP) {
if (type == SD_DIF_TYPE3_PROTECTION)
blk_integrity_register(disk, &t10_pi_type3_ip);
else
blk_integrity_register(disk, &t10_pi_type1_ip);
disk->integrity->flags |= BLK_INTEGRITY_IP_CHECKSUM;
} else
if (type == SD_DIF_TYPE3_PROTECTION)
blk_integrity_register(disk, &t10_pi_type3_crc);
else
blk_integrity_register(disk, &t10_pi_type1_crc);
sd_printk(KERN_NOTICE, sdkp,
"Enabling DIX %s protection\n", disk->integrity->name);
if (dif && type) {
disk->integrity->flags |= BLK_INTEGRITY_DEVICE_CAPABLE;
if (!sdkp)
return;
if (type == SD_DIF_TYPE3_PROTECTION)
disk->integrity->tag_size = sizeof(u16) + sizeof(u32);
else
disk->integrity->tag_size = sizeof(u16);
sd_printk(KERN_NOTICE, sdkp, "DIF application tag size %u\n",
disk->integrity->tag_size);
}
}
void sd_dif_prepare(struct scsi_cmnd *scmd)
{
const int tuple_sz = sizeof(struct t10_pi_tuple);
struct bio *bio;
struct scsi_disk *sdkp;
struct t10_pi_tuple *pi;
u32 phys, virt;
sdkp = scsi_disk(scmd->request->rq_disk);
if (sdkp->protection_type == SD_DIF_TYPE3_PROTECTION)
return;
phys = scsi_prot_ref_tag(scmd);
__rq_for_each_bio(bio, scmd->request) {
struct bio_integrity_payload *bip = bio_integrity(bio);
struct bio_vec iv;
struct bvec_iter iter;
unsigned int j;
if (bip->bip_flags & BIP_MAPPED_INTEGRITY)
break;
virt = bip_get_seed(bip) & 0xffffffff;
bip_for_each_vec(iv, bip, iter) {
pi = kmap_atomic(iv.bv_page) + iv.bv_offset;
for (j = 0; j < iv.bv_len; j += tuple_sz, pi++) {
if (be32_to_cpu(pi->ref_tag) == virt)
pi->ref_tag = cpu_to_be32(phys);
virt++;
phys++;
}
kunmap_atomic(pi);
}
bip->bip_flags |= BIP_MAPPED_INTEGRITY;
}
}
void sd_dif_complete(struct scsi_cmnd *scmd, unsigned int good_bytes)
{
const int tuple_sz = sizeof(struct t10_pi_tuple);
struct scsi_disk *sdkp;
struct bio *bio;
struct t10_pi_tuple *pi;
unsigned int j, intervals;
u32 phys, virt;
sdkp = scsi_disk(scmd->request->rq_disk);
if (sdkp->protection_type == SD_DIF_TYPE3_PROTECTION || good_bytes == 0)
return;
intervals = good_bytes / scsi_prot_interval(scmd);
phys = scsi_prot_ref_tag(scmd);
__rq_for_each_bio(bio, scmd->request) {
struct bio_integrity_payload *bip = bio_integrity(bio);
struct bio_vec iv;
struct bvec_iter iter;
virt = bip_get_seed(bip) & 0xffffffff;
bip_for_each_vec(iv, bip, iter) {
pi = kmap_atomic(iv.bv_page) + iv.bv_offset;
for (j = 0; j < iv.bv_len; j += tuple_sz, pi++) {
if (intervals == 0) {
kunmap_atomic(pi);
return;
}
if (be32_to_cpu(pi->ref_tag) == phys)
pi->ref_tag = cpu_to_be32(virt);
virt++;
phys++;
intervals--;
}
kunmap_atomic(pi);
}
}
}
