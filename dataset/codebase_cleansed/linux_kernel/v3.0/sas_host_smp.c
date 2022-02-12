static void sas_host_smp_discover(struct sas_ha_struct *sas_ha, u8 *resp_data,
u8 phy_id)
{
struct sas_phy *phy;
struct sas_rphy *rphy;
if (phy_id >= sas_ha->num_phys) {
resp_data[2] = SMP_RESP_NO_PHY;
return;
}
resp_data[2] = SMP_RESP_FUNC_ACC;
phy = sas_ha->sas_phy[phy_id]->phy;
resp_data[9] = phy_id;
resp_data[13] = phy->negotiated_linkrate;
memcpy(resp_data + 16, sas_ha->sas_addr, SAS_ADDR_SIZE);
memcpy(resp_data + 24, sas_ha->sas_phy[phy_id]->attached_sas_addr,
SAS_ADDR_SIZE);
resp_data[40] = (phy->minimum_linkrate << 4) |
phy->minimum_linkrate_hw;
resp_data[41] = (phy->maximum_linkrate << 4) |
phy->maximum_linkrate_hw;
if (!sas_ha->sas_phy[phy_id]->port ||
!sas_ha->sas_phy[phy_id]->port->port_dev)
return;
rphy = sas_ha->sas_phy[phy_id]->port->port_dev->rphy;
resp_data[12] = rphy->identify.device_type << 4;
resp_data[14] = rphy->identify.initiator_port_protocols;
resp_data[15] = rphy->identify.target_port_protocols;
}
static void sas_report_phy_sata(struct sas_ha_struct *sas_ha, u8 *resp_data,
u8 phy_id)
{
struct sas_rphy *rphy;
struct dev_to_host_fis *fis;
int i;
if (phy_id >= sas_ha->num_phys) {
resp_data[2] = SMP_RESP_NO_PHY;
return;
}
resp_data[2] = SMP_RESP_PHY_NO_SATA;
if (!sas_ha->sas_phy[phy_id]->port)
return;
rphy = sas_ha->sas_phy[phy_id]->port->port_dev->rphy;
fis = (struct dev_to_host_fis *)
sas_ha->sas_phy[phy_id]->port->port_dev->frame_rcvd;
if (rphy->identify.target_port_protocols != SAS_PROTOCOL_SATA)
return;
resp_data[2] = SMP_RESP_FUNC_ACC;
resp_data[9] = phy_id;
memcpy(resp_data + 16, sas_ha->sas_phy[phy_id]->attached_sas_addr,
SAS_ADDR_SIZE);
if (fis->fis_type != 0x34)
return;
for (i = 0; i < 20; i += 4) {
u8 *dst = resp_data + 24 + i, *src =
&sas_ha->sas_phy[phy_id]->port->port_dev->frame_rcvd[i];
dst[0] = src[3];
dst[1] = src[2];
dst[2] = src[1];
dst[3] = src[0];
}
}
static void sas_phy_control(struct sas_ha_struct *sas_ha, u8 phy_id,
u8 phy_op, enum sas_linkrate min,
enum sas_linkrate max, u8 *resp_data)
{
struct sas_internal *i =
to_sas_internal(sas_ha->core.shost->transportt);
struct sas_phy_linkrates rates;
if (phy_id >= sas_ha->num_phys) {
resp_data[2] = SMP_RESP_NO_PHY;
return;
}
switch (phy_op) {
case PHY_FUNC_NOP:
case PHY_FUNC_LINK_RESET:
case PHY_FUNC_HARD_RESET:
case PHY_FUNC_DISABLE:
case PHY_FUNC_CLEAR_ERROR_LOG:
case PHY_FUNC_CLEAR_AFFIL:
case PHY_FUNC_TX_SATA_PS_SIGNAL:
break;
default:
resp_data[2] = SMP_RESP_PHY_UNK_OP;
return;
}
rates.minimum_linkrate = min;
rates.maximum_linkrate = max;
if (i->dft->lldd_control_phy(sas_ha->sas_phy[phy_id], phy_op, &rates))
resp_data[2] = SMP_RESP_FUNC_FAILED;
else
resp_data[2] = SMP_RESP_FUNC_ACC;
}
int sas_smp_host_handler(struct Scsi_Host *shost, struct request *req,
struct request *rsp)
{
u8 *req_data = NULL, *resp_data = NULL, *buf;
struct sas_ha_struct *sas_ha = SHOST_TO_SAS_HA(shost);
int error = -EINVAL;
if (blk_rq_bytes(req) < 8 || blk_rq_bytes(rsp) < 8)
goto out;
if (bio_offset(req->bio) + blk_rq_bytes(req) > PAGE_SIZE ||
bio_offset(rsp->bio) + blk_rq_bytes(rsp) > PAGE_SIZE) {
shost_printk(KERN_ERR, shost,
"SMP request/response frame crosses page boundary");
goto out;
}
req_data = kzalloc(blk_rq_bytes(req), GFP_KERNEL);
resp_data = kzalloc(max(blk_rq_bytes(rsp), 128U), GFP_KERNEL);
if (!req_data || !resp_data) {
error = -ENOMEM;
goto out;
}
local_irq_disable();
buf = kmap_atomic(bio_page(req->bio), KM_USER0) + bio_offset(req->bio);
memcpy(req_data, buf, blk_rq_bytes(req));
kunmap_atomic(buf - bio_offset(req->bio), KM_USER0);
local_irq_enable();
if (req_data[0] != SMP_REQUEST)
goto out;
error = 0;
resp_data[0] = SMP_RESPONSE;
resp_data[1] = req_data[1];
resp_data[2] = SMP_RESP_FUNC_UNK;
switch (req_data[1]) {
case SMP_REPORT_GENERAL:
req->resid_len -= 8;
rsp->resid_len -= 32;
resp_data[2] = SMP_RESP_FUNC_ACC;
resp_data[9] = sas_ha->num_phys;
break;
case SMP_REPORT_MANUF_INFO:
req->resid_len -= 8;
rsp->resid_len -= 64;
resp_data[2] = SMP_RESP_FUNC_ACC;
memcpy(resp_data + 12, shost->hostt->name,
SAS_EXPANDER_VENDOR_ID_LEN);
memcpy(resp_data + 20, "libsas virt phy",
SAS_EXPANDER_PRODUCT_ID_LEN);
break;
case SMP_READ_GPIO_REG:
break;
case SMP_DISCOVER:
req->resid_len -= 16;
if ((int)req->resid_len < 0) {
req->resid_len = 0;
error = -EINVAL;
goto out;
}
rsp->resid_len -= 56;
sas_host_smp_discover(sas_ha, resp_data, req_data[9]);
break;
case SMP_REPORT_PHY_ERR_LOG:
break;
case SMP_REPORT_PHY_SATA:
req->resid_len -= 16;
if ((int)req->resid_len < 0) {
req->resid_len = 0;
error = -EINVAL;
goto out;
}
rsp->resid_len -= 60;
sas_report_phy_sata(sas_ha, resp_data, req_data[9]);
break;
case SMP_REPORT_ROUTE_INFO:
break;
case SMP_WRITE_GPIO_REG:
break;
case SMP_CONF_ROUTE_INFO:
break;
case SMP_PHY_CONTROL:
req->resid_len -= 44;
if ((int)req->resid_len < 0) {
req->resid_len = 0;
error = -EINVAL;
goto out;
}
rsp->resid_len -= 8;
sas_phy_control(sas_ha, req_data[9], req_data[10],
req_data[32] >> 4, req_data[33] >> 4,
resp_data);
break;
case SMP_PHY_TEST_FUNCTION:
break;
default:
break;
}
local_irq_disable();
buf = kmap_atomic(bio_page(rsp->bio), KM_USER0) + bio_offset(rsp->bio);
memcpy(buf, resp_data, blk_rq_bytes(rsp));
flush_kernel_dcache_page(bio_page(rsp->bio));
kunmap_atomic(buf - bio_offset(rsp->bio), KM_USER0);
local_irq_enable();
out:
kfree(req_data);
kfree(resp_data);
return error;
}
