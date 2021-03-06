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
static u8 *to_sas_gpio_gp_bit(unsigned int od, u8 *data, u8 index, u8 count, u8 *bit)
{
unsigned int reg;
u8 byte;
if (index == 0)
return NULL;
index--;
if (od < index * 32)
return NULL;
od -= index * 32;
reg = od >> 5;
if (reg >= count)
return NULL;
od &= (1 << 5) - 1;
byte = 3 - (od >> 3);
*bit = od & ((1 << 3) - 1);
return &data[reg * 4 + byte];
}
int try_test_sas_gpio_gp_bit(unsigned int od, u8 *data, u8 index, u8 count)
{
u8 *byte;
u8 bit;
byte = to_sas_gpio_gp_bit(od, data, index, count, &bit);
if (!byte)
return -1;
return (*byte >> bit) & 1;
}
static int sas_host_smp_write_gpio(struct sas_ha_struct *sas_ha, u8 *resp_data,
u8 reg_type, u8 reg_index, u8 reg_count,
u8 *req_data)
{
struct sas_internal *i = to_sas_internal(sas_ha->core.shost->transportt);
int written;
if (i->dft->lldd_write_gpio == NULL) {
resp_data[2] = SMP_RESP_FUNC_UNK;
return 0;
}
written = i->dft->lldd_write_gpio(sas_ha, reg_type, reg_index,
reg_count, req_data);
if (written < 0) {
resp_data[2] = SMP_RESP_FUNC_FAILED;
written = 0;
} else
resp_data[2] = SMP_RESP_FUNC_ACC;
return written;
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
struct asd_sas_phy *asd_phy;
if (phy_id >= sas_ha->num_phys) {
resp_data[2] = SMP_RESP_NO_PHY;
return;
}
asd_phy = sas_ha->sas_phy[phy_id];
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
if (phy_op == PHY_FUNC_LINK_RESET && sas_try_ata_reset(asd_phy) == 0) {
resp_data[2] = SMP_RESP_FUNC_ACC;
return;
}
if (i->dft->lldd_control_phy(asd_phy, phy_op, &rates))
resp_data[2] = SMP_RESP_FUNC_FAILED;
else
resp_data[2] = SMP_RESP_FUNC_ACC;
}
void sas_smp_host_handler(struct bsg_job *job, struct Scsi_Host *shost)
{
struct sas_ha_struct *sas_ha = SHOST_TO_SAS_HA(shost);
u8 *req_data, *resp_data;
unsigned int reslen = 0;
int error = -EINVAL;
if (job->request_payload.payload_len < 8 ||
job->reply_payload.payload_len < 8)
goto out;
error = -ENOMEM;
req_data = kzalloc(job->request_payload.payload_len, GFP_KERNEL);
if (!req_data)
goto out;
sg_copy_to_buffer(job->request_payload.sg_list,
job->request_payload.sg_cnt, req_data,
job->request_payload.payload_len);
resp_data = kzalloc(max(job->reply_payload.payload_len, 128U),
GFP_KERNEL);
if (!resp_data)
goto out_free_req;
error = -EINVAL;
if (req_data[0] != SMP_REQUEST)
goto out_free_resp;
resp_data[0] = SMP_RESPONSE;
resp_data[1] = req_data[1];
resp_data[2] = SMP_RESP_FUNC_UNK;
switch (req_data[1]) {
case SMP_REPORT_GENERAL:
resp_data[2] = SMP_RESP_FUNC_ACC;
resp_data[9] = sas_ha->num_phys;
reslen = 32;
break;
case SMP_REPORT_MANUF_INFO:
resp_data[2] = SMP_RESP_FUNC_ACC;
memcpy(resp_data + 12, shost->hostt->name,
SAS_EXPANDER_VENDOR_ID_LEN);
memcpy(resp_data + 20, "libsas virt phy",
SAS_EXPANDER_PRODUCT_ID_LEN);
reslen = 64;
break;
case SMP_READ_GPIO_REG:
break;
case SMP_DISCOVER:
if (job->request_payload.payload_len < 16)
goto out_free_resp;
sas_host_smp_discover(sas_ha, resp_data, req_data[9]);
reslen = 56;
break;
case SMP_REPORT_PHY_ERR_LOG:
break;
case SMP_REPORT_PHY_SATA:
if (job->request_payload.payload_len < 16)
goto out_free_resp;
sas_report_phy_sata(sas_ha, resp_data, req_data[9]);
reslen = 60;
break;
case SMP_REPORT_ROUTE_INFO:
break;
case SMP_WRITE_GPIO_REG: {
const int base_frame_size = 11;
int to_write = req_data[4];
if (job->request_payload.payload_len <
base_frame_size + to_write * 4) {
resp_data[2] = SMP_RESP_INV_FRM_LEN;
break;
}
to_write = sas_host_smp_write_gpio(sas_ha, resp_data, req_data[2],
req_data[3], to_write, &req_data[8]);
reslen = 8;
break;
}
case SMP_CONF_ROUTE_INFO:
break;
case SMP_PHY_CONTROL:
if (job->request_payload.payload_len < 44)
goto out_free_resp;
sas_phy_control(sas_ha, req_data[9], req_data[10],
req_data[32] >> 4, req_data[33] >> 4,
resp_data);
reslen = 8;
break;
case SMP_PHY_TEST_FUNCTION:
break;
default:
break;
}
sg_copy_from_buffer(job->reply_payload.sg_list,
job->reply_payload.sg_cnt, resp_data,
job->reply_payload.payload_len);
error = 0;
out_free_resp:
kfree(resp_data);
out_free_req:
kfree(req_data);
out:
bsg_job_done(job, error, reslen);
}
