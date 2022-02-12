static void asc_prt_asc_dvc_var(ASC_DVC_VAR *h)
{
printk("ASC_DVC_VAR at addr 0x%lx\n", (ulong)h);
printk(" iop_base 0x%x, err_code 0x%x, dvc_cntl 0x%x, bug_fix_cntl "
"%d,\n", h->iop_base, h->err_code, h->dvc_cntl, h->bug_fix_cntl);
printk(" bus_type %d, init_sdtr 0x%x,\n", h->bus_type,
(unsigned)h->init_sdtr);
printk(" sdtr_done 0x%x, use_tagged_qng 0x%x, unit_not_ready 0x%x, "
"chip_no 0x%x,\n", (unsigned)h->sdtr_done,
(unsigned)h->use_tagged_qng, (unsigned)h->unit_not_ready,
(unsigned)h->chip_no);
printk(" queue_full_or_busy 0x%x, start_motor 0x%x, scsi_reset_wait "
"%u,\n", (unsigned)h->queue_full_or_busy,
(unsigned)h->start_motor, (unsigned)h->scsi_reset_wait);
printk(" is_in_int %u, max_total_qng %u, cur_total_qng %u, "
"in_critical_cnt %u,\n", (unsigned)h->is_in_int,
(unsigned)h->max_total_qng, (unsigned)h->cur_total_qng,
(unsigned)h->in_critical_cnt);
printk(" last_q_shortage %u, init_state 0x%x, no_scam 0x%x, "
"pci_fix_asyn_xfer 0x%x,\n", (unsigned)h->last_q_shortage,
(unsigned)h->init_state, (unsigned)h->no_scam,
(unsigned)h->pci_fix_asyn_xfer);
printk(" cfg 0x%lx\n", (ulong)h->cfg);
}
static void asc_prt_asc_dvc_cfg(ASC_DVC_CFG *h)
{
printk("ASC_DVC_CFG at addr 0x%lx\n", (ulong)h);
printk(" can_tagged_qng 0x%x, cmd_qng_enabled 0x%x,\n",
h->can_tagged_qng, h->cmd_qng_enabled);
printk(" disc_enable 0x%x, sdtr_enable 0x%x,\n",
h->disc_enable, h->sdtr_enable);
printk(" chip_scsi_id %d, isa_dma_speed %d, isa_dma_channel %d, "
"chip_version %d,\n", h->chip_scsi_id, h->isa_dma_speed,
h->isa_dma_channel, h->chip_version);
printk(" mcode_date 0x%x, mcode_version %d\n",
h->mcode_date, h->mcode_version);
}
static void asc_prt_adv_dvc_var(ADV_DVC_VAR *h)
{
printk(" ADV_DVC_VAR at addr 0x%lx\n", (ulong)h);
printk(" iop_base 0x%lx, err_code 0x%x, ultra_able 0x%x\n",
(ulong)h->iop_base, h->err_code, (unsigned)h->ultra_able);
printk(" sdtr_able 0x%x, wdtr_able 0x%x\n",
(unsigned)h->sdtr_able, (unsigned)h->wdtr_able);
printk(" start_motor 0x%x, scsi_reset_wait 0x%x\n",
(unsigned)h->start_motor, (unsigned)h->scsi_reset_wait);
printk(" max_host_qng %u, max_dvc_qng %u, carr_freelist 0x%lxn\n",
(unsigned)h->max_host_qng, (unsigned)h->max_dvc_qng,
(ulong)h->carr_freelist);
printk(" icq_sp 0x%lx, irq_sp 0x%lx\n",
(ulong)h->icq_sp, (ulong)h->irq_sp);
printk(" no_scam 0x%x, tagqng_able 0x%x\n",
(unsigned)h->no_scam, (unsigned)h->tagqng_able);
printk(" chip_scsi_id 0x%x, cfg 0x%lx\n",
(unsigned)h->chip_scsi_id, (ulong)h->cfg);
}
static void asc_prt_adv_dvc_cfg(ADV_DVC_CFG *h)
{
printk(" ADV_DVC_CFG at addr 0x%lx\n", (ulong)h);
printk(" disc_enable 0x%x, termination 0x%x\n",
h->disc_enable, h->termination);
printk(" chip_version 0x%x, mcode_date 0x%x\n",
h->chip_version, h->mcode_date);
printk(" mcode_version 0x%x, control_flag 0x%x\n",
h->mcode_version, h->control_flag);
}
static void asc_prt_scsi_host(struct Scsi_Host *s)
{
struct asc_board *boardp = shost_priv(s);
printk("Scsi_Host at addr 0x%p, device %s\n", s, dev_name(boardp->dev));
printk(" host_busy %u, host_no %d,\n",
atomic_read(&s->host_busy), s->host_no);
printk(" base 0x%lx, io_port 0x%lx, irq %d,\n",
(ulong)s->base, (ulong)s->io_port, boardp->irq);
printk(" dma_channel %d, this_id %d, can_queue %d,\n",
s->dma_channel, s->this_id, s->can_queue);
printk(" cmd_per_lun %d, sg_tablesize %d, unchecked_isa_dma %d\n",
s->cmd_per_lun, s->sg_tablesize, s->unchecked_isa_dma);
if (ASC_NARROW_BOARD(boardp)) {
asc_prt_asc_dvc_var(&boardp->dvc_var.asc_dvc_var);
asc_prt_asc_dvc_cfg(&boardp->dvc_cfg.asc_dvc_cfg);
} else {
asc_prt_adv_dvc_var(&boardp->dvc_var.adv_dvc_var);
asc_prt_adv_dvc_cfg(&boardp->dvc_cfg.adv_dvc_cfg);
}
}
static void asc_prt_hex(char *f, uchar *s, int l)
{
int i;
int j;
int k;
int m;
printk("%s: (%d bytes)\n", f, l);
for (i = 0; i < l; i += 32) {
if ((k = (l - i) / 4) >= 8) {
k = 8;
m = 0;
} else {
m = (l - i) % 4;
}
for (j = 0; j < k; j++) {
printk(" %2.2X%2.2X%2.2X%2.2X",
(unsigned)s[i + (j * 4)],
(unsigned)s[i + (j * 4) + 1],
(unsigned)s[i + (j * 4) + 2],
(unsigned)s[i + (j * 4) + 3]);
}
switch (m) {
case 0:
default:
break;
case 1:
printk(" %2.2X", (unsigned)s[i + (j * 4)]);
break;
case 2:
printk(" %2.2X%2.2X",
(unsigned)s[i + (j * 4)],
(unsigned)s[i + (j * 4) + 1]);
break;
case 3:
printk(" %2.2X%2.2X%2.2X",
(unsigned)s[i + (j * 4) + 1],
(unsigned)s[i + (j * 4) + 2],
(unsigned)s[i + (j * 4) + 3]);
break;
}
printk("\n");
}
}
static void asc_prt_asc_scsi_q(ASC_SCSI_Q *q)
{
ASC_SG_HEAD *sgp;
int i;
printk("ASC_SCSI_Q at addr 0x%lx\n", (ulong)q);
printk
(" target_ix 0x%x, target_lun %u, srb_ptr 0x%lx, tag_code 0x%x,\n",
q->q2.target_ix, q->q1.target_lun, (ulong)q->q2.srb_ptr,
q->q2.tag_code);
printk
(" data_addr 0x%lx, data_cnt %lu, sense_addr 0x%lx, sense_len %u,\n",
(ulong)le32_to_cpu(q->q1.data_addr),
(ulong)le32_to_cpu(q->q1.data_cnt),
(ulong)le32_to_cpu(q->q1.sense_addr), q->q1.sense_len);
printk(" cdbptr 0x%lx, cdb_len %u, sg_head 0x%lx, sg_queue_cnt %u\n",
(ulong)q->cdbptr, q->q2.cdb_len,
(ulong)q->sg_head, q->q1.sg_queue_cnt);
if (q->sg_head) {
sgp = q->sg_head;
printk("ASC_SG_HEAD at addr 0x%lx\n", (ulong)sgp);
printk(" entry_cnt %u, queue_cnt %u\n", sgp->entry_cnt,
sgp->queue_cnt);
for (i = 0; i < sgp->entry_cnt; i++) {
printk(" [%u]: addr 0x%lx, bytes %lu\n",
i, (ulong)le32_to_cpu(sgp->sg_list[i].addr),
(ulong)le32_to_cpu(sgp->sg_list[i].bytes));
}
}
}
static void asc_prt_asc_qdone_info(ASC_QDONE_INFO *q)
{
printk("ASC_QDONE_INFO at addr 0x%lx\n", (ulong)q);
printk(" srb_ptr 0x%lx, target_ix %u, cdb_len %u, tag_code %u,\n",
(ulong)q->d2.srb_ptr, q->d2.target_ix, q->d2.cdb_len,
q->d2.tag_code);
printk
(" done_stat 0x%x, host_stat 0x%x, scsi_stat 0x%x, scsi_msg 0x%x\n",
q->d3.done_stat, q->d3.host_stat, q->d3.scsi_stat, q->d3.scsi_msg);
}
static void asc_prt_adv_sgblock(int sgblockno, ADV_SG_BLOCK *b)
{
int i;
printk(" ASC_SG_BLOCK at addr 0x%lx (sgblockno %d)\n",
(ulong)b, sgblockno);
printk(" sg_cnt %u, sg_ptr 0x%lx\n",
b->sg_cnt, (ulong)le32_to_cpu(b->sg_ptr));
BUG_ON(b->sg_cnt > NO_OF_SG_PER_BLOCK);
if (b->sg_ptr != 0)
BUG_ON(b->sg_cnt != NO_OF_SG_PER_BLOCK);
for (i = 0; i < b->sg_cnt; i++) {
printk(" [%u]: sg_addr 0x%lx, sg_count 0x%lx\n",
i, (ulong)b->sg_list[i].sg_addr,
(ulong)b->sg_list[i].sg_count);
}
}
static void asc_prt_adv_scsi_req_q(ADV_SCSI_REQ_Q *q)
{
int sg_blk_cnt;
struct asc_sg_block *sg_ptr;
printk("ADV_SCSI_REQ_Q at addr 0x%lx\n", (ulong)q);
printk(" target_id %u, target_lun %u, srb_ptr 0x%lx, a_flag 0x%x\n",
q->target_id, q->target_lun, (ulong)q->srb_ptr, q->a_flag);
printk(" cntl 0x%x, data_addr 0x%lx, vdata_addr 0x%lx\n",
q->cntl, (ulong)le32_to_cpu(q->data_addr), (ulong)q->vdata_addr);
printk(" data_cnt %lu, sense_addr 0x%lx, sense_len %u,\n",
(ulong)le32_to_cpu(q->data_cnt),
(ulong)le32_to_cpu(q->sense_addr), q->sense_len);
printk
(" cdb_len %u, done_status 0x%x, host_status 0x%x, scsi_status 0x%x\n",
q->cdb_len, q->done_status, q->host_status, q->scsi_status);
printk(" sg_working_ix 0x%x, target_cmd %u\n",
q->sg_working_ix, q->target_cmd);
printk(" scsiq_rptr 0x%lx, sg_real_addr 0x%lx, sg_list_ptr 0x%lx\n",
(ulong)le32_to_cpu(q->scsiq_rptr),
(ulong)le32_to_cpu(q->sg_real_addr), (ulong)q->sg_list_ptr);
if (q->sg_list_ptr != NULL) {
sg_blk_cnt = 0;
while (1) {
sg_ptr =
&(((ADV_SG_BLOCK *)(q->sg_list_ptr))[sg_blk_cnt]);
asc_prt_adv_sgblock(sg_blk_cnt, sg_ptr);
if (sg_ptr->sg_ptr == 0) {
break;
}
sg_blk_cnt++;
}
}
}
static u32 advansys_ptr_to_srb(struct asc_dvc_var *asc_dvc, void *ptr)
{
int i;
void **new_ptr;
for (i = 0; i < asc_dvc->ptr_map_count; i++) {
if (!asc_dvc->ptr_map[i])
goto out;
}
if (asc_dvc->ptr_map_count == 0)
asc_dvc->ptr_map_count = 1;
else
asc_dvc->ptr_map_count *= 2;
new_ptr = krealloc(asc_dvc->ptr_map,
asc_dvc->ptr_map_count * sizeof(void *), GFP_ATOMIC);
if (!new_ptr)
return BAD_SRB;
asc_dvc->ptr_map = new_ptr;
out:
ASC_DBG(3, "Putting ptr %p into array offset %d\n", ptr, i);
asc_dvc->ptr_map[i] = ptr;
return i + 1;
}
static void * advansys_srb_to_ptr(struct asc_dvc_var *asc_dvc, u32 srb)
{
void *ptr;
srb--;
if (srb >= asc_dvc->ptr_map_count) {
printk("advansys: bad SRB %u, max %u\n", srb,
asc_dvc->ptr_map_count);
return NULL;
}
ptr = asc_dvc->ptr_map[srb];
asc_dvc->ptr_map[srb] = NULL;
ASC_DBG(3, "Returning ptr %p from array offset %d\n", ptr, srb);
return ptr;
}
static const char *advansys_info(struct Scsi_Host *shost)
{
static char info[ASC_INFO_SIZE];
struct asc_board *boardp = shost_priv(shost);
ASC_DVC_VAR *asc_dvc_varp;
ADV_DVC_VAR *adv_dvc_varp;
char *busname;
char *widename = NULL;
if (ASC_NARROW_BOARD(boardp)) {
asc_dvc_varp = &boardp->dvc_var.asc_dvc_var;
ASC_DBG(1, "begin\n");
if (asc_dvc_varp->bus_type & ASC_IS_ISA) {
if ((asc_dvc_varp->bus_type & ASC_IS_ISAPNP) ==
ASC_IS_ISAPNP) {
busname = "ISA PnP";
} else {
busname = "ISA";
}
sprintf(info,
"AdvanSys SCSI %s: %s: IO 0x%lX-0x%lX, IRQ 0x%X, DMA 0x%X",
ASC_VERSION, busname,
(ulong)shost->io_port,
(ulong)shost->io_port + ASC_IOADR_GAP - 1,
boardp->irq, shost->dma_channel);
} else {
if (asc_dvc_varp->bus_type & ASC_IS_VL) {
busname = "VL";
} else if (asc_dvc_varp->bus_type & ASC_IS_EISA) {
busname = "EISA";
} else if (asc_dvc_varp->bus_type & ASC_IS_PCI) {
if ((asc_dvc_varp->bus_type & ASC_IS_PCI_ULTRA)
== ASC_IS_PCI_ULTRA) {
busname = "PCI Ultra";
} else {
busname = "PCI";
}
} else {
busname = "?";
shost_printk(KERN_ERR, shost, "unknown bus "
"type %d\n", asc_dvc_varp->bus_type);
}
sprintf(info,
"AdvanSys SCSI %s: %s: IO 0x%lX-0x%lX, IRQ 0x%X",
ASC_VERSION, busname, (ulong)shost->io_port,
(ulong)shost->io_port + ASC_IOADR_GAP - 1,
boardp->irq);
}
} else {
adv_dvc_varp = &boardp->dvc_var.adv_dvc_var;
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC3550) {
widename = "Ultra-Wide";
} else if (adv_dvc_varp->chip_type == ADV_CHIP_ASC38C0800) {
widename = "Ultra2-Wide";
} else {
widename = "Ultra3-Wide";
}
sprintf(info,
"AdvanSys SCSI %s: PCI %s: PCIMEM 0x%lX-0x%lX, IRQ 0x%X",
ASC_VERSION, widename, (ulong)adv_dvc_varp->iop_base,
(ulong)adv_dvc_varp->iop_base + boardp->asc_n_io_port - 1, boardp->irq);
}
BUG_ON(strlen(info) >= ASC_INFO_SIZE);
ASC_DBG(1, "end\n");
return info;
}
static void asc_prt_board_devices(struct seq_file *m, struct Scsi_Host *shost)
{
struct asc_board *boardp = shost_priv(shost);
int chip_scsi_id;
int i;
seq_printf(m,
"\nDevice Information for AdvanSys SCSI Host %d:\n",
shost->host_no);
if (ASC_NARROW_BOARD(boardp)) {
chip_scsi_id = boardp->dvc_cfg.asc_dvc_cfg.chip_scsi_id;
} else {
chip_scsi_id = boardp->dvc_var.adv_dvc_var.chip_scsi_id;
}
seq_printf(m, "Target IDs Detected:");
for (i = 0; i <= ADV_MAX_TID; i++) {
if (boardp->init_tidmask & ADV_TID_TO_TIDMASK(i))
seq_printf(m, " %X,", i);
}
seq_printf(m, " (%X=Host Adapter)\n", chip_scsi_id);
}
static void asc_prt_adv_bios(struct seq_file *m, struct Scsi_Host *shost)
{
struct asc_board *boardp = shost_priv(shost);
ushort major, minor, letter;
seq_printf(m, "\nROM BIOS Version: ");
if (boardp->bios_signature != 0x55AA) {
seq_printf(m, "Disabled or Pre-3.1\n");
seq_printf(m,
"BIOS either disabled or Pre-3.1. If it is pre-3.1, then a newer version\n");
seq_printf(m,
"can be found at the ConnectCom FTP site: ftp://ftp.connectcom.net/pub\n");
} else {
major = (boardp->bios_version >> 12) & 0xF;
minor = (boardp->bios_version >> 8) & 0xF;
letter = (boardp->bios_version & 0xFF);
seq_printf(m, "%d.%d%c\n",
major, minor,
letter >= 26 ? '?' : letter + 'A');
if (major < 3 || (major <= 3 && minor < 1) ||
(major <= 3 && minor <= 1 && letter < ('I' - 'A'))) {
seq_printf(m,
"Newer version of ROM BIOS is available at the ConnectCom FTP site:\n");
seq_printf(m,
"ftp://ftp.connectcom.net/pub\n");
}
}
}
static int asc_get_eeprom_string(ushort *serialnum, uchar *cp)
{
ushort w, num;
if ((serialnum[1] & 0xFE00) != ((ushort)0xAA << 8)) {
return ASC_FALSE;
} else {
w = serialnum[0];
if ((*cp = 'A' + ((w & 0xE000) >> 13)) == 'H') {
*cp += 0x8;
}
cp++;
*cp++ = 'A' + ((w & 0x1C00) >> 10);
num = w & 0x3FF;
*cp++ = '0' + (num / 100);
num %= 100;
*cp++ = '0' + (num / 10);
*cp++ = 'A' + (num % 10);
w = serialnum[1];
if (serialnum[2] & 0x8000) {
*cp++ = '8' + ((w & 0x1C0) >> 6);
} else {
*cp++ = '0' + ((w & 0x1C0) >> 6);
}
num = w & 0x003F;
*cp++ = '0' + num / 10;
num %= 10;
*cp++ = '0' + num;
w = serialnum[2] & 0x7FFF;
*cp++ = 'A' + (w / 1000);
num = w % 1000;
*cp++ = '0' + num / 100;
num %= 100;
*cp++ = '0' + num / 10;
num %= 10;
*cp++ = '0' + num;
*cp = '\0';
return ASC_TRUE;
}
}
static void asc_prt_asc_board_eeprom(struct seq_file *m, struct Scsi_Host *shost)
{
struct asc_board *boardp = shost_priv(shost);
ASC_DVC_VAR *asc_dvc_varp;
ASCEEP_CONFIG *ep;
int i;
#ifdef CONFIG_ISA
int isa_dma_speed[] = { 10, 8, 7, 6, 5, 4, 3, 2 };
#endif
uchar serialstr[13];
asc_dvc_varp = &boardp->dvc_var.asc_dvc_var;
ep = &boardp->eep_config.asc_eep;
seq_printf(m,
"\nEEPROM Settings for AdvanSys SCSI Host %d:\n",
shost->host_no);
if (asc_get_eeprom_string((ushort *)&ep->adapter_info[0], serialstr)
== ASC_TRUE)
seq_printf(m, " Serial Number: %s\n", serialstr);
else if (ep->adapter_info[5] == 0xBB)
seq_printf(m,
" Default Settings Used for EEPROM-less Adapter.\n");
else
seq_printf(m,
" Serial Number Signature Not Present.\n");
seq_printf(m,
" Host SCSI ID: %u, Host Queue Size: %u, Device Queue Size: %u\n",
ASC_EEP_GET_CHIP_ID(ep), ep->max_total_qng,
ep->max_tag_qng);
seq_printf(m,
" cntl 0x%x, no_scam 0x%x\n", ep->cntl, ep->no_scam);
seq_printf(m, " Target ID: ");
for (i = 0; i <= ASC_MAX_TID; i++)
seq_printf(m, " %d", i);
seq_printf(m, "\n");
seq_printf(m, " Disconnects: ");
for (i = 0; i <= ASC_MAX_TID; i++)
seq_printf(m, " %c",
(ep->disc_enable & ADV_TID_TO_TIDMASK(i)) ? 'Y' : 'N');
seq_printf(m, "\n");
seq_printf(m, " Command Queuing: ");
for (i = 0; i <= ASC_MAX_TID; i++)
seq_printf(m, " %c",
(ep->use_cmd_qng & ADV_TID_TO_TIDMASK(i)) ? 'Y' : 'N');
seq_printf(m, "\n");
seq_printf(m, " Start Motor: ");
for (i = 0; i <= ASC_MAX_TID; i++)
seq_printf(m, " %c",
(ep->start_motor & ADV_TID_TO_TIDMASK(i)) ? 'Y' : 'N');
seq_printf(m, "\n");
seq_printf(m, " Synchronous Transfer:");
for (i = 0; i <= ASC_MAX_TID; i++)
seq_printf(m, " %c",
(ep->init_sdtr & ADV_TID_TO_TIDMASK(i)) ? 'Y' : 'N');
seq_printf(m, "\n");
#ifdef CONFIG_ISA
if (asc_dvc_varp->bus_type & ASC_IS_ISA) {
seq_printf(m,
" Host ISA DMA speed: %d MB/S\n",
isa_dma_speed[ASC_EEP_GET_DMA_SPD(ep)]);
}
#endif
}
static void asc_prt_adv_board_eeprom(struct seq_file *m, struct Scsi_Host *shost)
{
struct asc_board *boardp = shost_priv(shost);
ADV_DVC_VAR *adv_dvc_varp;
int i;
char *termstr;
uchar serialstr[13];
ADVEEP_3550_CONFIG *ep_3550 = NULL;
ADVEEP_38C0800_CONFIG *ep_38C0800 = NULL;
ADVEEP_38C1600_CONFIG *ep_38C1600 = NULL;
ushort word;
ushort *wordp;
ushort sdtr_speed = 0;
adv_dvc_varp = &boardp->dvc_var.adv_dvc_var;
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC3550) {
ep_3550 = &boardp->eep_config.adv_3550_eep;
} else if (adv_dvc_varp->chip_type == ADV_CHIP_ASC38C0800) {
ep_38C0800 = &boardp->eep_config.adv_38C0800_eep;
} else {
ep_38C1600 = &boardp->eep_config.adv_38C1600_eep;
}
seq_printf(m,
"\nEEPROM Settings for AdvanSys SCSI Host %d:\n",
shost->host_no);
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC3550) {
wordp = &ep_3550->serial_number_word1;
} else if (adv_dvc_varp->chip_type == ADV_CHIP_ASC38C0800) {
wordp = &ep_38C0800->serial_number_word1;
} else {
wordp = &ep_38C1600->serial_number_word1;
}
if (asc_get_eeprom_string(wordp, serialstr) == ASC_TRUE)
seq_printf(m, " Serial Number: %s\n", serialstr);
else
seq_printf(m, " Serial Number Signature Not Present.\n");
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC3550)
seq_printf(m,
" Host SCSI ID: %u, Host Queue Size: %u, Device Queue Size: %u\n",
ep_3550->adapter_scsi_id,
ep_3550->max_host_qng, ep_3550->max_dvc_qng);
else if (adv_dvc_varp->chip_type == ADV_CHIP_ASC38C0800)
seq_printf(m,
" Host SCSI ID: %u, Host Queue Size: %u, Device Queue Size: %u\n",
ep_38C0800->adapter_scsi_id,
ep_38C0800->max_host_qng,
ep_38C0800->max_dvc_qng);
else
seq_printf(m,
" Host SCSI ID: %u, Host Queue Size: %u, Device Queue Size: %u\n",
ep_38C1600->adapter_scsi_id,
ep_38C1600->max_host_qng,
ep_38C1600->max_dvc_qng);
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC3550) {
word = ep_3550->termination;
} else if (adv_dvc_varp->chip_type == ADV_CHIP_ASC38C0800) {
word = ep_38C0800->termination_lvd;
} else {
word = ep_38C1600->termination_lvd;
}
switch (word) {
case 1:
termstr = "Low Off/High Off";
break;
case 2:
termstr = "Low Off/High On";
break;
case 3:
termstr = "Low On/High On";
break;
default:
case 0:
termstr = "Automatic";
break;
}
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC3550)
seq_printf(m,
" termination: %u (%s), bios_ctrl: 0x%x\n",
ep_3550->termination, termstr,
ep_3550->bios_ctrl);
else if (adv_dvc_varp->chip_type == ADV_CHIP_ASC38C0800)
seq_printf(m,
" termination: %u (%s), bios_ctrl: 0x%x\n",
ep_38C0800->termination_lvd, termstr,
ep_38C0800->bios_ctrl);
else
seq_printf(m,
" termination: %u (%s), bios_ctrl: 0x%x\n",
ep_38C1600->termination_lvd, termstr,
ep_38C1600->bios_ctrl);
seq_printf(m, " Target ID: ");
for (i = 0; i <= ADV_MAX_TID; i++)
seq_printf(m, " %X", i);
seq_printf(m, "\n");
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC3550) {
word = ep_3550->disc_enable;
} else if (adv_dvc_varp->chip_type == ADV_CHIP_ASC38C0800) {
word = ep_38C0800->disc_enable;
} else {
word = ep_38C1600->disc_enable;
}
seq_printf(m, " Disconnects: ");
for (i = 0; i <= ADV_MAX_TID; i++)
seq_printf(m, " %c",
(word & ADV_TID_TO_TIDMASK(i)) ? 'Y' : 'N');
seq_printf(m, "\n");
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC3550) {
word = ep_3550->tagqng_able;
} else if (adv_dvc_varp->chip_type == ADV_CHIP_ASC38C0800) {
word = ep_38C0800->tagqng_able;
} else {
word = ep_38C1600->tagqng_able;
}
seq_printf(m, " Command Queuing: ");
for (i = 0; i <= ADV_MAX_TID; i++)
seq_printf(m, " %c",
(word & ADV_TID_TO_TIDMASK(i)) ? 'Y' : 'N');
seq_printf(m, "\n");
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC3550) {
word = ep_3550->start_motor;
} else if (adv_dvc_varp->chip_type == ADV_CHIP_ASC38C0800) {
word = ep_38C0800->start_motor;
} else {
word = ep_38C1600->start_motor;
}
seq_printf(m, " Start Motor: ");
for (i = 0; i <= ADV_MAX_TID; i++)
seq_printf(m, " %c",
(word & ADV_TID_TO_TIDMASK(i)) ? 'Y' : 'N');
seq_printf(m, "\n");
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC3550) {
seq_printf(m, " Synchronous Transfer:");
for (i = 0; i <= ADV_MAX_TID; i++)
seq_printf(m, " %c",
(ep_3550->sdtr_able & ADV_TID_TO_TIDMASK(i)) ?
'Y' : 'N');
seq_printf(m, "\n");
}
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC3550) {
seq_printf(m, " Ultra Transfer: ");
for (i = 0; i <= ADV_MAX_TID; i++)
seq_printf(m, " %c",
(ep_3550->ultra_able & ADV_TID_TO_TIDMASK(i))
? 'Y' : 'N');
seq_printf(m, "\n");
}
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC3550) {
word = ep_3550->wdtr_able;
} else if (adv_dvc_varp->chip_type == ADV_CHIP_ASC38C0800) {
word = ep_38C0800->wdtr_able;
} else {
word = ep_38C1600->wdtr_able;
}
seq_printf(m, " Wide Transfer: ");
for (i = 0; i <= ADV_MAX_TID; i++)
seq_printf(m, " %c",
(word & ADV_TID_TO_TIDMASK(i)) ? 'Y' : 'N');
seq_printf(m, "\n");
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC38C0800 ||
adv_dvc_varp->chip_type == ADV_CHIP_ASC38C1600) {
seq_printf(m,
" Synchronous Transfer Speed (Mhz):\n ");
for (i = 0; i <= ADV_MAX_TID; i++) {
char *speed_str;
if (i == 0) {
sdtr_speed = adv_dvc_varp->sdtr_speed1;
} else if (i == 4) {
sdtr_speed = adv_dvc_varp->sdtr_speed2;
} else if (i == 8) {
sdtr_speed = adv_dvc_varp->sdtr_speed3;
} else if (i == 12) {
sdtr_speed = adv_dvc_varp->sdtr_speed4;
}
switch (sdtr_speed & ADV_MAX_TID) {
case 0:
speed_str = "Off";
break;
case 1:
speed_str = " 5";
break;
case 2:
speed_str = " 10";
break;
case 3:
speed_str = " 20";
break;
case 4:
speed_str = " 40";
break;
case 5:
speed_str = " 80";
break;
default:
speed_str = "Unk";
break;
}
seq_printf(m, "%X:%s ", i, speed_str);
if (i == 7)
seq_printf(m, "\n ");
sdtr_speed >>= 4;
}
seq_printf(m, "\n");
}
}
static void asc_prt_driver_conf(struct seq_file *m, struct Scsi_Host *shost)
{
struct asc_board *boardp = shost_priv(shost);
int chip_scsi_id;
seq_printf(m,
"\nLinux Driver Configuration and Information for AdvanSys SCSI Host %d:\n",
shost->host_no);
seq_printf(m,
" host_busy %u, max_id %u, max_lun %llu, max_channel %u\n",
atomic_read(&shost->host_busy), shost->max_id,
shost->max_lun, shost->max_channel);
seq_printf(m,
" unique_id %d, can_queue %d, this_id %d, sg_tablesize %u, cmd_per_lun %u\n",
shost->unique_id, shost->can_queue, shost->this_id,
shost->sg_tablesize, shost->cmd_per_lun);
seq_printf(m,
" unchecked_isa_dma %d, use_clustering %d\n",
shost->unchecked_isa_dma, shost->use_clustering);
seq_printf(m,
" flags 0x%x, last_reset 0x%lx, jiffies 0x%lx, asc_n_io_port 0x%x\n",
boardp->flags, boardp->last_reset, jiffies,
boardp->asc_n_io_port);
seq_printf(m, " io_port 0x%lx\n", shost->io_port);
if (ASC_NARROW_BOARD(boardp)) {
chip_scsi_id = boardp->dvc_cfg.asc_dvc_cfg.chip_scsi_id;
} else {
chip_scsi_id = boardp->dvc_var.adv_dvc_var.chip_scsi_id;
}
}
static void asc_prt_asc_board_info(struct seq_file *m, struct Scsi_Host *shost)
{
struct asc_board *boardp = shost_priv(shost);
int chip_scsi_id;
ASC_DVC_VAR *v;
ASC_DVC_CFG *c;
int i;
int renegotiate = 0;
v = &boardp->dvc_var.asc_dvc_var;
c = &boardp->dvc_cfg.asc_dvc_cfg;
chip_scsi_id = c->chip_scsi_id;
seq_printf(m,
"\nAsc Library Configuration and Statistics for AdvanSys SCSI Host %d:\n",
shost->host_no);
seq_printf(m, " chip_version %u, mcode_date 0x%x, "
"mcode_version 0x%x, err_code %u\n",
c->chip_version, c->mcode_date, c->mcode_version,
v->err_code);
seq_printf(m,
" Total Command Pending: %d\n", v->cur_total_qng);
seq_printf(m, " Command Queuing:");
for (i = 0; i <= ASC_MAX_TID; i++) {
if ((chip_scsi_id == i) ||
((boardp->init_tidmask & ADV_TID_TO_TIDMASK(i)) == 0)) {
continue;
}
seq_printf(m, " %X:%c",
i,
(v->use_tagged_qng & ADV_TID_TO_TIDMASK(i)) ? 'Y' : 'N');
}
seq_printf(m, "\n");
seq_printf(m, " Command Queue Pending:");
for (i = 0; i <= ASC_MAX_TID; i++) {
if ((chip_scsi_id == i) ||
((boardp->init_tidmask & ADV_TID_TO_TIDMASK(i)) == 0)) {
continue;
}
seq_printf(m, " %X:%u", i, v->cur_dvc_qng[i]);
}
seq_printf(m, "\n");
seq_printf(m, " Command Queue Limit:");
for (i = 0; i <= ASC_MAX_TID; i++) {
if ((chip_scsi_id == i) ||
((boardp->init_tidmask & ADV_TID_TO_TIDMASK(i)) == 0)) {
continue;
}
seq_printf(m, " %X:%u", i, v->max_dvc_qng[i]);
}
seq_printf(m, "\n");
seq_printf(m, " Command Queue Full:");
for (i = 0; i <= ASC_MAX_TID; i++) {
if ((chip_scsi_id == i) ||
((boardp->init_tidmask & ADV_TID_TO_TIDMASK(i)) == 0)) {
continue;
}
if (boardp->queue_full & ADV_TID_TO_TIDMASK(i))
seq_printf(m, " %X:Y-%d",
i, boardp->queue_full_cnt[i]);
else
seq_printf(m, " %X:N", i);
}
seq_printf(m, "\n");
seq_printf(m, " Synchronous Transfer:");
for (i = 0; i <= ASC_MAX_TID; i++) {
if ((chip_scsi_id == i) ||
((boardp->init_tidmask & ADV_TID_TO_TIDMASK(i)) == 0)) {
continue;
}
seq_printf(m, " %X:%c",
i,
(v->sdtr_done & ADV_TID_TO_TIDMASK(i)) ? 'Y' : 'N');
}
seq_printf(m, "\n");
for (i = 0; i <= ASC_MAX_TID; i++) {
uchar syn_period_ix;
if ((chip_scsi_id == i) ||
((boardp->init_tidmask & ADV_TID_TO_TIDMASK(i)) == 0) ||
((v->init_sdtr & ADV_TID_TO_TIDMASK(i)) == 0)) {
continue;
}
seq_printf(m, " %X:", i);
if ((boardp->sdtr_data[i] & ASC_SYN_MAX_OFFSET) == 0) {
seq_printf(m, " Asynchronous");
} else {
syn_period_ix =
(boardp->sdtr_data[i] >> 4) & (v->max_sdtr_index -
1);
seq_printf(m,
" Transfer Period Factor: %d (%d.%d Mhz),",
v->sdtr_period_tbl[syn_period_ix],
250 / v->sdtr_period_tbl[syn_period_ix],
ASC_TENTHS(250,
v->sdtr_period_tbl[syn_period_ix]));
seq_printf(m, " REQ/ACK Offset: %d",
boardp->sdtr_data[i] & ASC_SYN_MAX_OFFSET);
}
if ((v->sdtr_done & ADV_TID_TO_TIDMASK(i)) == 0) {
seq_printf(m, "*\n");
renegotiate = 1;
} else {
seq_printf(m, "\n");
}
}
if (renegotiate) {
seq_printf(m,
" * = Re-negotiation pending before next command.\n");
}
}
static void asc_prt_adv_board_info(struct seq_file *m, struct Scsi_Host *shost)
{
struct asc_board *boardp = shost_priv(shost);
int i;
ADV_DVC_VAR *v;
ADV_DVC_CFG *c;
AdvPortAddr iop_base;
ushort chip_scsi_id;
ushort lramword;
uchar lrambyte;
ushort tagqng_able;
ushort sdtr_able, wdtr_able;
ushort wdtr_done, sdtr_done;
ushort period = 0;
int renegotiate = 0;
v = &boardp->dvc_var.adv_dvc_var;
c = &boardp->dvc_cfg.adv_dvc_cfg;
iop_base = v->iop_base;
chip_scsi_id = v->chip_scsi_id;
seq_printf(m,
"\nAdv Library Configuration and Statistics for AdvanSys SCSI Host %d:\n",
shost->host_no);
seq_printf(m,
" iop_base 0x%lx, cable_detect: %X, err_code %u\n",
(unsigned long)v->iop_base,
AdvReadWordRegister(iop_base,IOPW_SCSI_CFG1) & CABLE_DETECT,
v->err_code);
seq_printf(m, " chip_version %u, mcode_date 0x%x, "
"mcode_version 0x%x\n", c->chip_version,
c->mcode_date, c->mcode_version);
AdvReadWordLram(iop_base, ASC_MC_TAGQNG_ABLE, tagqng_able);
seq_printf(m, " Queuing Enabled:");
for (i = 0; i <= ADV_MAX_TID; i++) {
if ((chip_scsi_id == i) ||
((boardp->init_tidmask & ADV_TID_TO_TIDMASK(i)) == 0)) {
continue;
}
seq_printf(m, " %X:%c",
i,
(tagqng_able & ADV_TID_TO_TIDMASK(i)) ? 'Y' : 'N');
}
seq_printf(m, "\n");
seq_printf(m, " Queue Limit:");
for (i = 0; i <= ADV_MAX_TID; i++) {
if ((chip_scsi_id == i) ||
((boardp->init_tidmask & ADV_TID_TO_TIDMASK(i)) == 0)) {
continue;
}
AdvReadByteLram(iop_base, ASC_MC_NUMBER_OF_MAX_CMD + i,
lrambyte);
seq_printf(m, " %X:%d", i, lrambyte);
}
seq_printf(m, "\n");
seq_printf(m, " Command Pending:");
for (i = 0; i <= ADV_MAX_TID; i++) {
if ((chip_scsi_id == i) ||
((boardp->init_tidmask & ADV_TID_TO_TIDMASK(i)) == 0)) {
continue;
}
AdvReadByteLram(iop_base, ASC_MC_NUMBER_OF_QUEUED_CMD + i,
lrambyte);
seq_printf(m, " %X:%d", i, lrambyte);
}
seq_printf(m, "\n");
AdvReadWordLram(iop_base, ASC_MC_WDTR_ABLE, wdtr_able);
seq_printf(m, " Wide Enabled:");
for (i = 0; i <= ADV_MAX_TID; i++) {
if ((chip_scsi_id == i) ||
((boardp->init_tidmask & ADV_TID_TO_TIDMASK(i)) == 0)) {
continue;
}
seq_printf(m, " %X:%c",
i,
(wdtr_able & ADV_TID_TO_TIDMASK(i)) ? 'Y' : 'N');
}
seq_printf(m, "\n");
AdvReadWordLram(iop_base, ASC_MC_WDTR_DONE, wdtr_done);
seq_printf(m, " Transfer Bit Width:");
for (i = 0; i <= ADV_MAX_TID; i++) {
if ((chip_scsi_id == i) ||
((boardp->init_tidmask & ADV_TID_TO_TIDMASK(i)) == 0)) {
continue;
}
AdvReadWordLram(iop_base,
ASC_MC_DEVICE_HSHK_CFG_TABLE + (2 * i),
lramword);
seq_printf(m, " %X:%d",
i, (lramword & 0x8000) ? 16 : 8);
if ((wdtr_able & ADV_TID_TO_TIDMASK(i)) &&
(wdtr_done & ADV_TID_TO_TIDMASK(i)) == 0) {
seq_printf(m, "*");
renegotiate = 1;
}
}
seq_printf(m, "\n");
AdvReadWordLram(iop_base, ASC_MC_SDTR_ABLE, sdtr_able);
seq_printf(m, " Synchronous Enabled:");
for (i = 0; i <= ADV_MAX_TID; i++) {
if ((chip_scsi_id == i) ||
((boardp->init_tidmask & ADV_TID_TO_TIDMASK(i)) == 0)) {
continue;
}
seq_printf(m, " %X:%c",
i,
(sdtr_able & ADV_TID_TO_TIDMASK(i)) ? 'Y' : 'N');
}
seq_printf(m, "\n");
AdvReadWordLram(iop_base, ASC_MC_SDTR_DONE, sdtr_done);
for (i = 0; i <= ADV_MAX_TID; i++) {
AdvReadWordLram(iop_base,
ASC_MC_DEVICE_HSHK_CFG_TABLE + (2 * i),
lramword);
lramword &= ~0x8000;
if ((chip_scsi_id == i) ||
((boardp->init_tidmask & ADV_TID_TO_TIDMASK(i)) == 0) ||
((sdtr_able & ADV_TID_TO_TIDMASK(i)) == 0)) {
continue;
}
seq_printf(m, " %X:", i);
if ((lramword & 0x1F) == 0) {
seq_printf(m, " Asynchronous");
} else {
seq_printf(m, " Transfer Period Factor: ");
if ((lramword & 0x1F00) == 0x1100) {
seq_printf(m, "9 (80.0 Mhz),");
} else if ((lramword & 0x1F00) == 0x1000) {
seq_printf(m, "10 (40.0 Mhz),");
} else {
period = (((lramword >> 8) * 25) + 50) / 4;
if (period == 0) {
seq_printf(m, "%d (? Mhz), ", period);
} else {
seq_printf(m,
"%d (%d.%d Mhz),",
period, 250 / period,
ASC_TENTHS(250, period));
}
}
seq_printf(m, " REQ/ACK Offset: %d",
lramword & 0x1F);
}
if ((sdtr_done & ADV_TID_TO_TIDMASK(i)) == 0) {
seq_printf(m, "*\n");
renegotiate = 1;
} else {
seq_printf(m, "\n");
}
}
if (renegotiate) {
seq_printf(m,
" * = Re-negotiation pending before next command.\n");
}
}
static void asc_prt_board_stats(struct seq_file *m, struct Scsi_Host *shost)
{
struct asc_board *boardp = shost_priv(shost);
struct asc_stats *s = &boardp->asc_stats;
seq_printf(m,
"\nLinux Driver Statistics for AdvanSys SCSI Host %d:\n",
shost->host_no);
seq_printf(m,
" queuecommand %u, reset %u, biosparam %u, interrupt %u\n",
s->queuecommand, s->reset, s->biosparam,
s->interrupt);
seq_printf(m,
" callback %u, done %u, build_error %u, build_noreq %u, build_nosg %u\n",
s->callback, s->done, s->build_error,
s->adv_build_noreq, s->adv_build_nosg);
seq_printf(m,
" exe_noerror %u, exe_busy %u, exe_error %u, exe_unknown %u\n",
s->exe_noerror, s->exe_busy, s->exe_error,
s->exe_unknown);
if (s->xfer_cnt > 0) {
seq_printf(m, " xfer_cnt %u, xfer_elem %u, ",
s->xfer_cnt, s->xfer_elem);
seq_printf(m, "xfer_bytes %u.%01u kb\n",
s->xfer_sect / 2, ASC_TENTHS(s->xfer_sect, 2));
seq_printf(m, " avg_num_elem %u.%01u, ",
s->xfer_elem / s->xfer_cnt,
ASC_TENTHS(s->xfer_elem, s->xfer_cnt));
seq_printf(m, "avg_elem_size %u.%01u kb, ",
(s->xfer_sect / 2) / s->xfer_elem,
ASC_TENTHS((s->xfer_sect / 2), s->xfer_elem));
seq_printf(m, "avg_xfer_size %u.%01u kb\n",
(s->xfer_sect / 2) / s->xfer_cnt,
ASC_TENTHS((s->xfer_sect / 2), s->xfer_cnt));
}
}
static int
advansys_show_info(struct seq_file *m, struct Scsi_Host *shost)
{
struct asc_board *boardp = shost_priv(shost);
ASC_DBG(1, "begin\n");
seq_printf(m, "%s\n", (char *)advansys_info(shost));
if (!ASC_NARROW_BOARD(boardp))
asc_prt_adv_bios(m, shost);
asc_prt_board_devices(m, shost);
if (ASC_NARROW_BOARD(boardp))
asc_prt_asc_board_eeprom(m, shost);
else
asc_prt_adv_board_eeprom(m, shost);
asc_prt_driver_conf(m, shost);
#ifdef ADVANSYS_STATS
asc_prt_board_stats(m, shost);
#endif
if (ASC_NARROW_BOARD(boardp))
asc_prt_asc_board_info(m, shost);
else
asc_prt_adv_board_info(m, shost);
return 0;
}
static void asc_scsi_done(struct scsi_cmnd *scp)
{
scsi_dma_unmap(scp);
ASC_STATS(scp->device->host, done);
scp->scsi_done(scp);
}
static void AscSetBank(PortAddr iop_base, uchar bank)
{
uchar val;
val = AscGetChipControl(iop_base) &
(~
(CC_SINGLE_STEP | CC_TEST | CC_DIAG | CC_SCSI_RESET |
CC_CHIP_RESET));
if (bank == 1) {
val |= CC_BANK_ONE;
} else if (bank == 2) {
val |= CC_DIAG | CC_BANK_ONE;
} else {
val &= ~CC_BANK_ONE;
}
AscSetChipControl(iop_base, val);
}
static void AscSetChipIH(PortAddr iop_base, ushort ins_code)
{
AscSetBank(iop_base, 1);
AscWriteChipIH(iop_base, ins_code);
AscSetBank(iop_base, 0);
}
static int AscStartChip(PortAddr iop_base)
{
AscSetChipControl(iop_base, 0);
if ((AscGetChipStatus(iop_base) & CSW_HALTED) != 0) {
return (0);
}
return (1);
}
static int AscStopChip(PortAddr iop_base)
{
uchar cc_val;
cc_val =
AscGetChipControl(iop_base) &
(~(CC_SINGLE_STEP | CC_TEST | CC_DIAG));
AscSetChipControl(iop_base, (uchar)(cc_val | CC_HALT));
AscSetChipIH(iop_base, INS_HALT);
AscSetChipIH(iop_base, INS_RFLAG_WTM);
if ((AscGetChipStatus(iop_base) & CSW_HALTED) == 0) {
return (0);
}
return (1);
}
static int AscIsChipHalted(PortAddr iop_base)
{
if ((AscGetChipStatus(iop_base) & CSW_HALTED) != 0) {
if ((AscGetChipControl(iop_base) & CC_HALT) != 0) {
return (1);
}
}
return (0);
}
static int AscResetChipAndScsiBus(ASC_DVC_VAR *asc_dvc)
{
PortAddr iop_base;
int i = 10;
iop_base = asc_dvc->iop_base;
while ((AscGetChipStatus(iop_base) & CSW_SCSI_RESET_ACTIVE)
&& (i-- > 0)) {
mdelay(100);
}
AscStopChip(iop_base);
AscSetChipControl(iop_base, CC_CHIP_RESET | CC_SCSI_RESET | CC_HALT);
udelay(60);
AscSetChipIH(iop_base, INS_RFLAG_WTM);
AscSetChipIH(iop_base, INS_HALT);
AscSetChipControl(iop_base, CC_CHIP_RESET | CC_HALT);
AscSetChipControl(iop_base, CC_HALT);
mdelay(200);
AscSetChipStatus(iop_base, CIW_CLR_SCSI_RESET_INT);
AscSetChipStatus(iop_base, 0);
return (AscIsChipHalted(iop_base));
}
static int AscFindSignature(PortAddr iop_base)
{
ushort sig_word;
ASC_DBG(1, "AscGetChipSignatureByte(0x%x) 0x%x\n",
iop_base, AscGetChipSignatureByte(iop_base));
if (AscGetChipSignatureByte(iop_base) == (uchar)ASC_1000_ID1B) {
ASC_DBG(1, "AscGetChipSignatureWord(0x%x) 0x%x\n",
iop_base, AscGetChipSignatureWord(iop_base));
sig_word = AscGetChipSignatureWord(iop_base);
if ((sig_word == (ushort)ASC_1000_ID0W) ||
(sig_word == (ushort)ASC_1000_ID0W_FIX)) {
return (1);
}
}
return (0);
}
static void AscEnableInterrupt(PortAddr iop_base)
{
ushort cfg;
cfg = AscGetChipCfgLsw(iop_base);
AscSetChipCfgLsw(iop_base, cfg | ASC_CFG0_HOST_INT_ON);
}
static void AscDisableInterrupt(PortAddr iop_base)
{
ushort cfg;
cfg = AscGetChipCfgLsw(iop_base);
AscSetChipCfgLsw(iop_base, cfg & (~ASC_CFG0_HOST_INT_ON));
}
static uchar AscReadLramByte(PortAddr iop_base, ushort addr)
{
unsigned char byte_data;
unsigned short word_data;
if (isodd_word(addr)) {
AscSetChipLramAddr(iop_base, addr - 1);
word_data = AscGetChipLramData(iop_base);
byte_data = (word_data >> 8) & 0xFF;
} else {
AscSetChipLramAddr(iop_base, addr);
word_data = AscGetChipLramData(iop_base);
byte_data = word_data & 0xFF;
}
return byte_data;
}
static ushort AscReadLramWord(PortAddr iop_base, ushort addr)
{
ushort word_data;
AscSetChipLramAddr(iop_base, addr);
word_data = AscGetChipLramData(iop_base);
return (word_data);
}
static ASC_DCNT AscReadLramDWord(PortAddr iop_base, ushort addr)
{
ushort val_low, val_high;
ASC_DCNT dword_data;
AscSetChipLramAddr(iop_base, addr);
val_low = AscGetChipLramData(iop_base);
val_high = AscGetChipLramData(iop_base);
dword_data = ((ASC_DCNT) val_high << 16) | (ASC_DCNT) val_low;
return (dword_data);
}
static void
AscMemWordSetLram(PortAddr iop_base, ushort s_addr, ushort set_wval, int words)
{
int i;
AscSetChipLramAddr(iop_base, s_addr);
for (i = 0; i < words; i++) {
AscSetChipLramData(iop_base, set_wval);
}
}
static void AscWriteLramWord(PortAddr iop_base, ushort addr, ushort word_val)
{
AscSetChipLramAddr(iop_base, addr);
AscSetChipLramData(iop_base, word_val);
}
static void AscWriteLramByte(PortAddr iop_base, ushort addr, uchar byte_val)
{
ushort word_data;
if (isodd_word(addr)) {
addr--;
word_data = AscReadLramWord(iop_base, addr);
word_data &= 0x00FF;
word_data |= (((ushort)byte_val << 8) & 0xFF00);
} else {
word_data = AscReadLramWord(iop_base, addr);
word_data &= 0xFF00;
word_data |= ((ushort)byte_val & 0x00FF);
}
AscWriteLramWord(iop_base, addr, word_data);
}
static void
AscMemWordCopyPtrToLram(PortAddr iop_base, ushort s_addr,
const uchar *s_buffer, int words)
{
int i;
AscSetChipLramAddr(iop_base, s_addr);
for (i = 0; i < 2 * words; i += 2) {
outpw(iop_base + IOP_RAM_DATA,
((ushort)s_buffer[i + 1] << 8) | s_buffer[i]);
}
}
static void
AscMemDWordCopyPtrToLram(PortAddr iop_base,
ushort s_addr, uchar *s_buffer, int dwords)
{
int i;
AscSetChipLramAddr(iop_base, s_addr);
for (i = 0; i < 4 * dwords; i += 4) {
outpw(iop_base + IOP_RAM_DATA, ((ushort)s_buffer[i + 1] << 8) | s_buffer[i]);
outpw(iop_base + IOP_RAM_DATA, ((ushort)s_buffer[i + 3] << 8) | s_buffer[i + 2]);
}
}
static void
AscMemWordCopyPtrFromLram(PortAddr iop_base,
ushort s_addr, uchar *d_buffer, int words)
{
int i;
ushort word;
AscSetChipLramAddr(iop_base, s_addr);
for (i = 0; i < 2 * words; i += 2) {
word = inpw(iop_base + IOP_RAM_DATA);
d_buffer[i] = word & 0xff;
d_buffer[i + 1] = (word >> 8) & 0xff;
}
}
static ASC_DCNT AscMemSumLramWord(PortAddr iop_base, ushort s_addr, int words)
{
ASC_DCNT sum;
int i;
sum = 0L;
for (i = 0; i < words; i++, s_addr += 2) {
sum += AscReadLramWord(iop_base, s_addr);
}
return (sum);
}
static ushort AscInitLram(ASC_DVC_VAR *asc_dvc)
{
uchar i;
ushort s_addr;
PortAddr iop_base;
ushort warn_code;
iop_base = asc_dvc->iop_base;
warn_code = 0;
AscMemWordSetLram(iop_base, ASC_QADR_BEG, 0,
(ushort)(((int)(asc_dvc->max_total_qng + 2 + 1) *
64) >> 1));
i = ASC_MIN_ACTIVE_QNO;
s_addr = ASC_QADR_BEG + ASC_QBLK_SIZE;
AscWriteLramByte(iop_base, (ushort)(s_addr + ASC_SCSIQ_B_FWD),
(uchar)(i + 1));
AscWriteLramByte(iop_base, (ushort)(s_addr + ASC_SCSIQ_B_BWD),
(uchar)(asc_dvc->max_total_qng));
AscWriteLramByte(iop_base, (ushort)(s_addr + ASC_SCSIQ_B_QNO),
(uchar)i);
i++;
s_addr += ASC_QBLK_SIZE;
for (; i < asc_dvc->max_total_qng; i++, s_addr += ASC_QBLK_SIZE) {
AscWriteLramByte(iop_base, (ushort)(s_addr + ASC_SCSIQ_B_FWD),
(uchar)(i + 1));
AscWriteLramByte(iop_base, (ushort)(s_addr + ASC_SCSIQ_B_BWD),
(uchar)(i - 1));
AscWriteLramByte(iop_base, (ushort)(s_addr + ASC_SCSIQ_B_QNO),
(uchar)i);
}
AscWriteLramByte(iop_base, (ushort)(s_addr + ASC_SCSIQ_B_FWD),
(uchar)ASC_QLINK_END);
AscWriteLramByte(iop_base, (ushort)(s_addr + ASC_SCSIQ_B_BWD),
(uchar)(asc_dvc->max_total_qng - 1));
AscWriteLramByte(iop_base, (ushort)(s_addr + ASC_SCSIQ_B_QNO),
(uchar)asc_dvc->max_total_qng);
i++;
s_addr += ASC_QBLK_SIZE;
for (; i <= (uchar)(asc_dvc->max_total_qng + 3);
i++, s_addr += ASC_QBLK_SIZE) {
AscWriteLramByte(iop_base,
(ushort)(s_addr + (ushort)ASC_SCSIQ_B_FWD), i);
AscWriteLramByte(iop_base,
(ushort)(s_addr + (ushort)ASC_SCSIQ_B_BWD), i);
AscWriteLramByte(iop_base,
(ushort)(s_addr + (ushort)ASC_SCSIQ_B_QNO), i);
}
return warn_code;
}
static ASC_DCNT
AscLoadMicroCode(PortAddr iop_base, ushort s_addr,
const uchar *mcode_buf, ushort mcode_size)
{
ASC_DCNT chksum;
ushort mcode_word_size;
ushort mcode_chksum;
mcode_word_size = (ushort)(mcode_size >> 1);
AscMemWordSetLram(iop_base, s_addr, 0, mcode_word_size);
AscMemWordCopyPtrToLram(iop_base, s_addr, mcode_buf, mcode_word_size);
chksum = AscMemSumLramWord(iop_base, s_addr, mcode_word_size);
ASC_DBG(1, "chksum 0x%lx\n", (ulong)chksum);
mcode_chksum = (ushort)AscMemSumLramWord(iop_base,
(ushort)ASC_CODE_SEC_BEG,
(ushort)((mcode_size -
s_addr - (ushort)
ASC_CODE_SEC_BEG) /
2));
ASC_DBG(1, "mcode_chksum 0x%lx\n", (ulong)mcode_chksum);
AscWriteLramWord(iop_base, ASCV_MCODE_CHKSUM_W, mcode_chksum);
AscWriteLramWord(iop_base, ASCV_MCODE_SIZE_W, mcode_size);
return chksum;
}
static void AscInitQLinkVar(ASC_DVC_VAR *asc_dvc)
{
PortAddr iop_base;
int i;
ushort lram_addr;
iop_base = asc_dvc->iop_base;
AscPutRiscVarFreeQHead(iop_base, 1);
AscPutRiscVarDoneQTail(iop_base, asc_dvc->max_total_qng);
AscPutVarFreeQHead(iop_base, 1);
AscPutVarDoneQTail(iop_base, asc_dvc->max_total_qng);
AscWriteLramByte(iop_base, ASCV_BUSY_QHEAD_B,
(uchar)((int)asc_dvc->max_total_qng + 1));
AscWriteLramByte(iop_base, ASCV_DISC1_QHEAD_B,
(uchar)((int)asc_dvc->max_total_qng + 2));
AscWriteLramByte(iop_base, (ushort)ASCV_TOTAL_READY_Q_B,
asc_dvc->max_total_qng);
AscWriteLramWord(iop_base, ASCV_ASCDVC_ERR_CODE_W, 0);
AscWriteLramWord(iop_base, ASCV_HALTCODE_W, 0);
AscWriteLramByte(iop_base, ASCV_STOP_CODE_B, 0);
AscWriteLramByte(iop_base, ASCV_SCSIBUSY_B, 0);
AscWriteLramByte(iop_base, ASCV_WTM_FLAG_B, 0);
AscPutQDoneInProgress(iop_base, 0);
lram_addr = ASC_QADR_BEG;
for (i = 0; i < 32; i++, lram_addr += 2) {
AscWriteLramWord(iop_base, lram_addr, 0);
}
}
static ushort AscInitMicroCodeVar(ASC_DVC_VAR *asc_dvc)
{
int i;
ushort warn_code;
PortAddr iop_base;
ASC_PADDR phy_addr;
ASC_DCNT phy_size;
struct asc_board *board = asc_dvc_to_board(asc_dvc);
iop_base = asc_dvc->iop_base;
warn_code = 0;
for (i = 0; i <= ASC_MAX_TID; i++) {
AscPutMCodeInitSDTRAtID(iop_base, i,
asc_dvc->cfg->sdtr_period_offset[i]);
}
AscInitQLinkVar(asc_dvc);
AscWriteLramByte(iop_base, ASCV_DISC_ENABLE_B,
asc_dvc->cfg->disc_enable);
AscWriteLramByte(iop_base, ASCV_HOSTSCSI_ID_B,
ASC_TID_TO_TARGET_ID(asc_dvc->cfg->chip_scsi_id));
BUG_ON((unsigned long)asc_dvc->overrun_buf & 7);
asc_dvc->overrun_dma = dma_map_single(board->dev, asc_dvc->overrun_buf,
ASC_OVERRUN_BSIZE, DMA_FROM_DEVICE);
if (dma_mapping_error(board->dev, asc_dvc->overrun_dma)) {
warn_code = -ENOMEM;
goto err_dma_map;
}
phy_addr = cpu_to_le32(asc_dvc->overrun_dma);
AscMemDWordCopyPtrToLram(iop_base, ASCV_OVERRUN_PADDR_D,
(uchar *)&phy_addr, 1);
phy_size = cpu_to_le32(ASC_OVERRUN_BSIZE);
AscMemDWordCopyPtrToLram(iop_base, ASCV_OVERRUN_BSIZE_D,
(uchar *)&phy_size, 1);
asc_dvc->cfg->mcode_date =
AscReadLramWord(iop_base, (ushort)ASCV_MC_DATE_W);
asc_dvc->cfg->mcode_version =
AscReadLramWord(iop_base, (ushort)ASCV_MC_VER_W);
AscSetPCAddr(iop_base, ASC_MCODE_START_ADDR);
if (AscGetPCAddr(iop_base) != ASC_MCODE_START_ADDR) {
asc_dvc->err_code |= ASC_IERR_SET_PC_ADDR;
warn_code = UW_ERR;
goto err_mcode_start;
}
if (AscStartChip(iop_base) != 1) {
asc_dvc->err_code |= ASC_IERR_START_STOP_CHIP;
warn_code = UW_ERR;
goto err_mcode_start;
}
return warn_code;
err_mcode_start:
dma_unmap_single(board->dev, asc_dvc->overrun_dma,
ASC_OVERRUN_BSIZE, DMA_FROM_DEVICE);
err_dma_map:
asc_dvc->overrun_dma = 0;
return warn_code;
}
static ushort AscInitAsc1000Driver(ASC_DVC_VAR *asc_dvc)
{
const struct firmware *fw;
const char fwname[] = "advansys/mcode.bin";
int err;
unsigned long chksum;
ushort warn_code;
PortAddr iop_base;
iop_base = asc_dvc->iop_base;
warn_code = 0;
if ((asc_dvc->dvc_cntl & ASC_CNTL_RESET_SCSI) &&
!(asc_dvc->init_state & ASC_INIT_RESET_SCSI_DONE)) {
AscResetChipAndScsiBus(asc_dvc);
mdelay(asc_dvc->scsi_reset_wait * 1000);
}
asc_dvc->init_state |= ASC_INIT_STATE_BEG_LOAD_MC;
if (asc_dvc->err_code != 0)
return UW_ERR;
if (!AscFindSignature(asc_dvc->iop_base)) {
asc_dvc->err_code = ASC_IERR_BAD_SIGNATURE;
return warn_code;
}
AscDisableInterrupt(iop_base);
warn_code |= AscInitLram(asc_dvc);
if (asc_dvc->err_code != 0)
return UW_ERR;
err = request_firmware(&fw, fwname, asc_dvc->drv_ptr->dev);
if (err) {
printk(KERN_ERR "Failed to load image \"%s\" err %d\n",
fwname, err);
asc_dvc->err_code |= ASC_IERR_MCODE_CHKSUM;
return err;
}
if (fw->size < 4) {
printk(KERN_ERR "Bogus length %zu in image \"%s\"\n",
fw->size, fwname);
release_firmware(fw);
asc_dvc->err_code |= ASC_IERR_MCODE_CHKSUM;
return -EINVAL;
}
chksum = (fw->data[3] << 24) | (fw->data[2] << 16) |
(fw->data[1] << 8) | fw->data[0];
ASC_DBG(1, "_asc_mcode_chksum 0x%lx\n", (ulong)chksum);
if (AscLoadMicroCode(iop_base, 0, &fw->data[4],
fw->size - 4) != chksum) {
asc_dvc->err_code |= ASC_IERR_MCODE_CHKSUM;
release_firmware(fw);
return warn_code;
}
release_firmware(fw);
warn_code |= AscInitMicroCodeVar(asc_dvc);
if (!asc_dvc->overrun_dma)
return warn_code;
asc_dvc->init_state |= ASC_INIT_STATE_END_LOAD_MC;
AscEnableInterrupt(iop_base);
return warn_code;
}
static int AdvLoadMicrocode(AdvPortAddr iop_base, const unsigned char *buf,
int size, int memsize, int chksum)
{
int i, j, end, len = 0;
ADV_DCNT sum;
AdvWriteWordRegister(iop_base, IOPW_RAM_ADDR, 0);
for (i = 253 * 2; i < size; i++) {
if (buf[i] == 0xff) {
unsigned short word = (buf[i + 3] << 8) | buf[i + 2];
for (j = 0; j < buf[i + 1]; j++) {
AdvWriteWordAutoIncLram(iop_base, word);
len += 2;
}
i += 3;
} else if (buf[i] == 0xfe) {
unsigned short word = (buf[i + 2] << 8) | buf[i + 1];
AdvWriteWordAutoIncLram(iop_base, word);
i += 2;
len += 2;
} else {
unsigned int off = buf[i] * 2;
unsigned short word = (buf[off + 1] << 8) | buf[off];
AdvWriteWordAutoIncLram(iop_base, word);
len += 2;
}
}
end = len;
while (len < memsize) {
AdvWriteWordAutoIncLram(iop_base, 0);
len += 2;
}
sum = 0;
AdvWriteWordRegister(iop_base, IOPW_RAM_ADDR, 0);
for (len = 0; len < end; len += 2) {
sum += AdvReadWordAutoIncLram(iop_base);
}
if (sum != chksum)
return ASC_IERR_MCODE_CHKSUM;
return 0;
}
static void AdvBuildCarrierFreelist(struct adv_dvc_var *asc_dvc)
{
ADV_CARR_T *carrp;
ADV_SDCNT buf_size;
ADV_PADDR carr_paddr;
carrp = (ADV_CARR_T *) ADV_16BALIGN(asc_dvc->carrier_buf);
asc_dvc->carr_freelist = NULL;
if (carrp == asc_dvc->carrier_buf) {
buf_size = ADV_CARRIER_BUFSIZE;
} else {
buf_size = ADV_CARRIER_BUFSIZE - sizeof(ADV_CARR_T);
}
do {
carr_paddr = cpu_to_le32(virt_to_bus(carrp));
buf_size -= sizeof(ADV_CARR_T);
carrp->carr_pa = carr_paddr;
carrp->carr_va = cpu_to_le32(ADV_VADDR_TO_U32(carrp));
carrp->next_vpa =
cpu_to_le32(ADV_VADDR_TO_U32(asc_dvc->carr_freelist));
asc_dvc->carr_freelist = carrp;
carrp++;
} while (buf_size > 0);
}
static int
AdvSendIdleCmd(ADV_DVC_VAR *asc_dvc,
ushort idle_cmd, ADV_DCNT idle_cmd_parameter)
{
int result;
ADV_DCNT i, j;
AdvPortAddr iop_base;
iop_base = asc_dvc->iop_base;
AdvWriteWordLram(iop_base, ASC_MC_IDLE_CMD_STATUS, (ushort)0);
AdvWriteDWordLramNoSwap(iop_base, ASC_MC_IDLE_CMD_PARAMETER,
cpu_to_le32(idle_cmd_parameter));
AdvWriteWordLram(iop_base, ASC_MC_IDLE_CMD, idle_cmd);
AdvWriteByteRegister(iop_base, IOPB_TICKLE, ADV_TICKLE_B);
if (asc_dvc->chip_type == ADV_CHIP_ASC3550) {
AdvWriteByteRegister(iop_base, IOPB_TICKLE, ADV_TICKLE_NOP);
}
for (i = 0; i < SCSI_WAIT_100_MSEC; i++) {
for (j = 0; j < SCSI_US_PER_MSEC; j++) {
AdvReadWordLram(iop_base, ASC_MC_IDLE_CMD_STATUS,
result);
if (result != 0)
return result;
udelay(1);
}
}
BUG();
return ADV_ERROR;
}
static int AdvResetSB(ADV_DVC_VAR *asc_dvc)
{
int status;
status = AdvSendIdleCmd(asc_dvc, (ushort)IDLE_CMD_SCSI_RESET_START, 0L);
if (status != ADV_TRUE) {
return status;
}
udelay(ASC_SCSI_RESET_HOLD_TIME_US);
status = AdvSendIdleCmd(asc_dvc, (ushort)IDLE_CMD_SCSI_RESET_END, 0L);
if (status != ADV_TRUE) {
return status;
}
mdelay(asc_dvc->scsi_reset_wait * 1000);
return status;
}
static int AdvInitAsc3550Driver(ADV_DVC_VAR *asc_dvc)
{
const struct firmware *fw;
const char fwname[] = "advansys/3550.bin";
AdvPortAddr iop_base;
ushort warn_code;
int begin_addr;
int end_addr;
ushort code_sum;
int word;
int i;
int err;
unsigned long chksum;
ushort scsi_cfg1;
uchar tid;
ushort bios_mem[ASC_MC_BIOSLEN / 2];
ushort wdtr_able = 0, sdtr_able, tagqng_able;
uchar max_cmd[ADV_MAX_TID + 1];
if (asc_dvc->err_code != 0)
return ADV_ERROR;
if (asc_dvc->chip_type != ADV_CHIP_ASC3550) {
asc_dvc->err_code = ASC_IERR_BAD_CHIPTYPE;
return ADV_ERROR;
}
warn_code = 0;
iop_base = asc_dvc->iop_base;
for (i = 0; i < ASC_MC_BIOSLEN / 2; i++) {
AdvReadWordLram(iop_base, ASC_MC_BIOSMEM + (2 * i),
bios_mem[i]);
}
if (bios_mem[(ASC_MC_BIOS_SIGNATURE - ASC_MC_BIOSMEM) / 2] == 0x55AA) {
ushort bios_version, major, minor;
bios_version =
bios_mem[(ASC_MC_BIOS_VERSION - ASC_MC_BIOSMEM) / 2];
major = (bios_version >> 12) & 0xF;
minor = (bios_version >> 8) & 0xF;
if (major < 3 || (major == 3 && minor == 1)) {
AdvReadWordLram(iop_base, 0x120, wdtr_able);
} else {
AdvReadWordLram(iop_base, ASC_MC_WDTR_ABLE, wdtr_able);
}
}
AdvReadWordLram(iop_base, ASC_MC_SDTR_ABLE, sdtr_able);
AdvReadWordLram(iop_base, ASC_MC_TAGQNG_ABLE, tagqng_able);
for (tid = 0; tid <= ADV_MAX_TID; tid++) {
AdvReadByteLram(iop_base, ASC_MC_NUMBER_OF_MAX_CMD + tid,
max_cmd[tid]);
}
err = request_firmware(&fw, fwname, asc_dvc->drv_ptr->dev);
if (err) {
printk(KERN_ERR "Failed to load image \"%s\" err %d\n",
fwname, err);
asc_dvc->err_code = ASC_IERR_MCODE_CHKSUM;
return err;
}
if (fw->size < 4) {
printk(KERN_ERR "Bogus length %zu in image \"%s\"\n",
fw->size, fwname);
release_firmware(fw);
asc_dvc->err_code = ASC_IERR_MCODE_CHKSUM;
return -EINVAL;
}
chksum = (fw->data[3] << 24) | (fw->data[2] << 16) |
(fw->data[1] << 8) | fw->data[0];
asc_dvc->err_code = AdvLoadMicrocode(iop_base, &fw->data[4],
fw->size - 4, ADV_3550_MEMSIZE,
chksum);
release_firmware(fw);
if (asc_dvc->err_code)
return ADV_ERROR;
for (i = 0; i < ASC_MC_BIOSLEN / 2; i++) {
AdvWriteWordLram(iop_base, ASC_MC_BIOSMEM + (2 * i),
bios_mem[i]);
}
AdvReadWordLram(iop_base, ASC_MC_CODE_BEGIN_ADDR, begin_addr);
AdvReadWordLram(iop_base, ASC_MC_CODE_END_ADDR, end_addr);
code_sum = 0;
AdvWriteWordRegister(iop_base, IOPW_RAM_ADDR, begin_addr);
for (word = begin_addr; word < end_addr; word += 2) {
code_sum += AdvReadWordAutoIncLram(iop_base);
}
AdvWriteWordLram(iop_base, ASC_MC_CODE_CHK_SUM, code_sum);
AdvReadWordLram(iop_base, ASC_MC_VERSION_DATE,
asc_dvc->cfg->mcode_date);
AdvReadWordLram(iop_base, ASC_MC_VERSION_NUM,
asc_dvc->cfg->mcode_version);
AdvWriteWordLram(iop_base, ASC_MC_CHIP_TYPE, ADV_CHIP_ASC3550);
if (asc_dvc->cfg->control_flag & CONTROL_FLAG_IGNORE_PERR) {
AdvReadWordLram(iop_base, ASC_MC_CONTROL_FLAG, word);
word |= CONTROL_FLAG_IGNORE_PERR;
AdvWriteWordLram(iop_base, ASC_MC_CONTROL_FLAG, word);
}
AdvWriteByteRegister(iop_base, IOPB_DMA_CFG0,
START_CTL_EMFU | READ_CMD_MRM);
if ((asc_dvc->bios_ctrl & BIOS_CTRL_RESET_SCSI_BUS) == 0) {
AdvWriteWordLram(iop_base, ASC_MC_WDTR_ABLE,
asc_dvc->wdtr_able);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_ABLE,
asc_dvc->sdtr_able);
}
word = 0;
for (tid = 0; tid <= ADV_MAX_TID; tid++) {
if (ADV_TID_TO_TIDMASK(tid) & asc_dvc->ultra_able) {
word |= (0x3 << (4 * (tid % 4)));
} else {
word |= (0x2 << (4 * (tid % 4)));
}
if (tid == 3) {
AdvWriteWordLram(iop_base, ASC_MC_SDTR_SPEED1, word);
word = 0;
} else if (tid == 7) {
AdvWriteWordLram(iop_base, ASC_MC_SDTR_SPEED2, word);
word = 0;
} else if (tid == 11) {
AdvWriteWordLram(iop_base, ASC_MC_SDTR_SPEED3, word);
word = 0;
} else if (tid == 15) {
AdvWriteWordLram(iop_base, ASC_MC_SDTR_SPEED4, word);
}
}
AdvWriteWordLram(iop_base, ASC_MC_DISC_ENABLE,
asc_dvc->cfg->disc_enable);
AdvWriteWordLram(iop_base, ASC_MC_DEFAULT_SCSI_CFG0,
PARITY_EN | QUEUE_128 | SEL_TMO_LONG | OUR_ID_EN |
asc_dvc->chip_scsi_id);
scsi_cfg1 = AdvReadWordRegister(iop_base, IOPW_SCSI_CFG1);
if ((scsi_cfg1 & CABLE_ILLEGAL_A) == 0 ||
(scsi_cfg1 & CABLE_ILLEGAL_B) == 0) {
asc_dvc->err_code |= ASC_IERR_ILLEGAL_CONNECTION;
return ADV_ERROR;
}
if ((AdvReadWordRegister(iop_base, IOPW_SCSI_CTRL) & 0x3F07) == 0x3F07) {
asc_dvc->err_code |= ASC_IERR_REVERSED_CABLE;
return ADV_ERROR;
}
if ((scsi_cfg1 & DIFF_MODE) && (scsi_cfg1 & DIFF_SENSE) == 0) {
asc_dvc->err_code |= ASC_IERR_SINGLE_END_DEVICE;
return ADV_ERROR;
}
if (asc_dvc->cfg->termination == 0) {
asc_dvc->cfg->termination |= TERM_CTL_SEL;
switch (scsi_cfg1 & CABLE_DETECT) {
case 0x3:
case 0x7:
case 0xB:
case 0xD:
case 0xE:
case 0xF:
asc_dvc->cfg->termination |= (TERM_CTL_H | TERM_CTL_L);
break;
case 0x1:
case 0x5:
case 0x9:
case 0xA:
case 0xC:
asc_dvc->cfg->termination |= TERM_CTL_H;
break;
case 0x2:
case 0x6:
break;
}
}
scsi_cfg1 &= ~TERM_CTL;
scsi_cfg1 |= (TERM_CTL_SEL | (~asc_dvc->cfg->termination & TERM_CTL));
AdvWriteWordLram(iop_base, ASC_MC_DEFAULT_SCSI_CFG1,
FLTR_DISABLE | scsi_cfg1);
AdvWriteWordLram(iop_base, ASC_MC_DEFAULT_MEM_CFG,
BIOS_EN | RAM_SZ_8KB);
AdvWriteWordLram(iop_base, ASC_MC_DEFAULT_SEL_MASK,
ADV_TID_TO_TIDMASK(asc_dvc->chip_scsi_id));
AdvBuildCarrierFreelist(asc_dvc);
if ((asc_dvc->icq_sp = asc_dvc->carr_freelist) == NULL) {
asc_dvc->err_code |= ASC_IERR_NO_CARRIER;
return ADV_ERROR;
}
asc_dvc->carr_freelist = (ADV_CARR_T *)
ADV_U32_TO_VADDR(le32_to_cpu(asc_dvc->icq_sp->next_vpa));
asc_dvc->icq_sp->next_vpa = cpu_to_le32(ASC_CQ_STOPPER);
AdvWriteDWordLramNoSwap(iop_base, ASC_MC_ICQ, asc_dvc->icq_sp->carr_pa);
if ((asc_dvc->irq_sp = asc_dvc->carr_freelist) == NULL) {
asc_dvc->err_code |= ASC_IERR_NO_CARRIER;
return ADV_ERROR;
}
asc_dvc->carr_freelist = (ADV_CARR_T *)
ADV_U32_TO_VADDR(le32_to_cpu(asc_dvc->irq_sp->next_vpa));
asc_dvc->irq_sp->next_vpa = cpu_to_le32(ASC_CQ_STOPPER);
AdvWriteDWordLramNoSwap(iop_base, ASC_MC_IRQ, asc_dvc->irq_sp->carr_pa);
asc_dvc->carr_pending_cnt = 0;
AdvWriteByteRegister(iop_base, IOPB_INTR_ENABLES,
(ADV_INTR_ENABLE_HOST_INTR |
ADV_INTR_ENABLE_GLOBAL_INTR));
AdvReadWordLram(iop_base, ASC_MC_CODE_BEGIN_ADDR, word);
AdvWriteWordRegister(iop_base, IOPW_PC, word);
AdvWriteWordRegister(iop_base, IOPW_RISC_CSR, ADV_RISC_CSR_RUN);
if (asc_dvc->bios_ctrl & BIOS_CTRL_RESET_SCSI_BUS) {
if (bios_mem[(ASC_MC_BIOS_SIGNATURE - ASC_MC_BIOSMEM) / 2] ==
0x55AA) {
AdvWriteWordLram(iop_base, ASC_MC_WDTR_ABLE, wdtr_able);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_ABLE, sdtr_able);
AdvWriteWordLram(iop_base, ASC_MC_TAGQNG_ABLE,
tagqng_able);
for (tid = 0; tid <= ADV_MAX_TID; tid++) {
AdvWriteByteLram(iop_base,
ASC_MC_NUMBER_OF_MAX_CMD + tid,
max_cmd[tid]);
}
} else {
if (AdvResetSB(asc_dvc) != ADV_TRUE) {
warn_code = ASC_WARN_BUSRESET_ERROR;
}
}
}
return warn_code;
}
static int AdvInitAsc38C0800Driver(ADV_DVC_VAR *asc_dvc)
{
const struct firmware *fw;
const char fwname[] = "advansys/38C0800.bin";
AdvPortAddr iop_base;
ushort warn_code;
int begin_addr;
int end_addr;
ushort code_sum;
int word;
int i;
int err;
unsigned long chksum;
ushort scsi_cfg1;
uchar byte;
uchar tid;
ushort bios_mem[ASC_MC_BIOSLEN / 2];
ushort wdtr_able, sdtr_able, tagqng_able;
uchar max_cmd[ADV_MAX_TID + 1];
if (asc_dvc->err_code != 0)
return ADV_ERROR;
if (asc_dvc->chip_type != ADV_CHIP_ASC38C0800) {
asc_dvc->err_code = ASC_IERR_BAD_CHIPTYPE;
return ADV_ERROR;
}
warn_code = 0;
iop_base = asc_dvc->iop_base;
for (i = 0; i < ASC_MC_BIOSLEN / 2; i++) {
AdvReadWordLram(iop_base, ASC_MC_BIOSMEM + (2 * i),
bios_mem[i]);
}
AdvReadWordLram(iop_base, ASC_MC_WDTR_ABLE, wdtr_able);
AdvReadWordLram(iop_base, ASC_MC_SDTR_ABLE, sdtr_able);
AdvReadWordLram(iop_base, ASC_MC_TAGQNG_ABLE, tagqng_able);
for (tid = 0; tid <= ADV_MAX_TID; tid++) {
AdvReadByteLram(iop_base, ASC_MC_NUMBER_OF_MAX_CMD + tid,
max_cmd[tid]);
}
for (i = 0; i < 2; i++) {
AdvWriteByteRegister(iop_base, IOPB_RAM_BIST, PRE_TEST_MODE);
mdelay(10);
byte = AdvReadByteRegister(iop_base, IOPB_RAM_BIST);
if ((byte & RAM_TEST_DONE) == 0
|| (byte & 0x0F) != PRE_TEST_VALUE) {
asc_dvc->err_code = ASC_IERR_BIST_PRE_TEST;
return ADV_ERROR;
}
AdvWriteByteRegister(iop_base, IOPB_RAM_BIST, NORMAL_MODE);
mdelay(10);
if (AdvReadByteRegister(iop_base, IOPB_RAM_BIST)
!= NORMAL_VALUE) {
asc_dvc->err_code = ASC_IERR_BIST_PRE_TEST;
return ADV_ERROR;
}
}
AdvWriteByteRegister(iop_base, IOPB_RAM_BIST, RAM_TEST_MODE);
mdelay(10);
byte = AdvReadByteRegister(iop_base, IOPB_RAM_BIST);
if ((byte & RAM_TEST_DONE) == 0 || (byte & RAM_TEST_STATUS) != 0) {
asc_dvc->bist_err_code = byte;
asc_dvc->err_code = ASC_IERR_BIST_RAM_TEST;
return ADV_ERROR;
}
AdvWriteByteRegister(iop_base, IOPB_RAM_BIST, NORMAL_MODE);
err = request_firmware(&fw, fwname, asc_dvc->drv_ptr->dev);
if (err) {
printk(KERN_ERR "Failed to load image \"%s\" err %d\n",
fwname, err);
asc_dvc->err_code = ASC_IERR_MCODE_CHKSUM;
return err;
}
if (fw->size < 4) {
printk(KERN_ERR "Bogus length %zu in image \"%s\"\n",
fw->size, fwname);
release_firmware(fw);
asc_dvc->err_code = ASC_IERR_MCODE_CHKSUM;
return -EINVAL;
}
chksum = (fw->data[3] << 24) | (fw->data[2] << 16) |
(fw->data[1] << 8) | fw->data[0];
asc_dvc->err_code = AdvLoadMicrocode(iop_base, &fw->data[4],
fw->size - 4, ADV_38C0800_MEMSIZE,
chksum);
release_firmware(fw);
if (asc_dvc->err_code)
return ADV_ERROR;
for (i = 0; i < ASC_MC_BIOSLEN / 2; i++) {
AdvWriteWordLram(iop_base, ASC_MC_BIOSMEM + (2 * i),
bios_mem[i]);
}
AdvReadWordLram(iop_base, ASC_MC_CODE_BEGIN_ADDR, begin_addr);
AdvReadWordLram(iop_base, ASC_MC_CODE_END_ADDR, end_addr);
code_sum = 0;
AdvWriteWordRegister(iop_base, IOPW_RAM_ADDR, begin_addr);
for (word = begin_addr; word < end_addr; word += 2) {
code_sum += AdvReadWordAutoIncLram(iop_base);
}
AdvWriteWordLram(iop_base, ASC_MC_CODE_CHK_SUM, code_sum);
AdvReadWordLram(iop_base, ASC_MC_VERSION_DATE,
asc_dvc->cfg->mcode_date);
AdvReadWordLram(iop_base, ASC_MC_VERSION_NUM,
asc_dvc->cfg->mcode_version);
AdvWriteWordLram(iop_base, ASC_MC_CHIP_TYPE, ADV_CHIP_ASC38C0800);
scsi_cfg1 = AdvReadWordRegister(iop_base, IOPW_SCSI_CFG1);
AdvWriteWordRegister(iop_base, IOPW_SCSI_CFG1,
scsi_cfg1 | DIS_TERM_DRV);
if (asc_dvc->cfg->control_flag & CONTROL_FLAG_IGNORE_PERR) {
AdvReadWordLram(iop_base, ASC_MC_CONTROL_FLAG, word);
word |= CONTROL_FLAG_IGNORE_PERR;
AdvWriteWordLram(iop_base, ASC_MC_CONTROL_FLAG, word);
}
AdvWriteByteRegister(iop_base, IOPB_DMA_CFG0,
BC_THRESH_ENB | FIFO_THRESH_80B | START_CTL_TH |
READ_CMD_MRM);
if ((asc_dvc->bios_ctrl & BIOS_CTRL_RESET_SCSI_BUS) == 0) {
AdvWriteWordLram(iop_base, ASC_MC_WDTR_ABLE,
asc_dvc->wdtr_able);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_ABLE,
asc_dvc->sdtr_able);
}
AdvWriteWordLram(iop_base, ASC_MC_DISC_ENABLE,
asc_dvc->cfg->disc_enable);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_SPEED1, asc_dvc->sdtr_speed1);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_SPEED2, asc_dvc->sdtr_speed2);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_SPEED3, asc_dvc->sdtr_speed3);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_SPEED4, asc_dvc->sdtr_speed4);
AdvWriteWordLram(iop_base, ASC_MC_DEFAULT_SCSI_CFG0,
PARITY_EN | QUEUE_128 | SEL_TMO_LONG | OUR_ID_EN |
asc_dvc->chip_scsi_id);
scsi_cfg1 = AdvReadWordRegister(iop_base, IOPW_SCSI_CFG1);
if ((AdvReadWordRegister(iop_base, IOPW_SCSI_CTRL) & 0x3F07) == 0x3F07) {
asc_dvc->err_code |= ASC_IERR_REVERSED_CABLE;
return ADV_ERROR;
}
if (scsi_cfg1 & HVD) {
asc_dvc->err_code = ASC_IERR_HVD_DEVICE;
return ADV_ERROR;
}
if ((asc_dvc->cfg->termination & TERM_SE) == 0) {
switch (scsi_cfg1 & C_DET_SE) {
case 0x1:
case 0x2:
case 0x3:
asc_dvc->cfg->termination |= TERM_SE;
break;
case 0x0:
asc_dvc->cfg->termination |= TERM_SE_HI;
break;
}
}
if ((asc_dvc->cfg->termination & TERM_LVD) == 0) {
switch (scsi_cfg1 & C_DET_LVD) {
case 0x4:
case 0x8:
case 0xC:
asc_dvc->cfg->termination |= TERM_LVD;
break;
case 0x0:
break;
}
}
scsi_cfg1 &= (~TERM_SE & ~TERM_LVD);
scsi_cfg1 |= (~asc_dvc->cfg->termination & 0xF0);
scsi_cfg1 &= (~BIG_ENDIAN & ~DIS_TERM_DRV & ~TERM_POL & ~HVD_LVD_SE);
AdvWriteWordLram(iop_base, ASC_MC_DEFAULT_SCSI_CFG1, scsi_cfg1);
AdvWriteWordLram(iop_base, ASC_MC_DEFAULT_MEM_CFG,
BIOS_EN | RAM_SZ_16KB);
AdvWriteWordLram(iop_base, ASC_MC_DEFAULT_SEL_MASK,
ADV_TID_TO_TIDMASK(asc_dvc->chip_scsi_id));
AdvBuildCarrierFreelist(asc_dvc);
if ((asc_dvc->icq_sp = asc_dvc->carr_freelist) == NULL) {
asc_dvc->err_code |= ASC_IERR_NO_CARRIER;
return ADV_ERROR;
}
asc_dvc->carr_freelist = (ADV_CARR_T *)
ADV_U32_TO_VADDR(le32_to_cpu(asc_dvc->icq_sp->next_vpa));
asc_dvc->icq_sp->next_vpa = cpu_to_le32(ASC_CQ_STOPPER);
AdvWriteDWordLramNoSwap(iop_base, ASC_MC_ICQ, asc_dvc->icq_sp->carr_pa);
if ((asc_dvc->irq_sp = asc_dvc->carr_freelist) == NULL) {
asc_dvc->err_code |= ASC_IERR_NO_CARRIER;
return ADV_ERROR;
}
asc_dvc->carr_freelist = (ADV_CARR_T *)
ADV_U32_TO_VADDR(le32_to_cpu(asc_dvc->irq_sp->next_vpa));
asc_dvc->irq_sp->next_vpa = cpu_to_le32(ASC_CQ_STOPPER);
AdvWriteDWordLramNoSwap(iop_base, ASC_MC_IRQ, asc_dvc->irq_sp->carr_pa);
asc_dvc->carr_pending_cnt = 0;
AdvWriteByteRegister(iop_base, IOPB_INTR_ENABLES,
(ADV_INTR_ENABLE_HOST_INTR |
ADV_INTR_ENABLE_GLOBAL_INTR));
AdvReadWordLram(iop_base, ASC_MC_CODE_BEGIN_ADDR, word);
AdvWriteWordRegister(iop_base, IOPW_PC, word);
AdvWriteWordRegister(iop_base, IOPW_RISC_CSR, ADV_RISC_CSR_RUN);
if (asc_dvc->bios_ctrl & BIOS_CTRL_RESET_SCSI_BUS) {
if (bios_mem[(ASC_MC_BIOS_SIGNATURE - ASC_MC_BIOSMEM) / 2] ==
0x55AA) {
AdvWriteWordLram(iop_base, ASC_MC_WDTR_ABLE, wdtr_able);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_ABLE, sdtr_able);
AdvWriteWordLram(iop_base, ASC_MC_TAGQNG_ABLE,
tagqng_able);
for (tid = 0; tid <= ADV_MAX_TID; tid++) {
AdvWriteByteLram(iop_base,
ASC_MC_NUMBER_OF_MAX_CMD + tid,
max_cmd[tid]);
}
} else {
if (AdvResetSB(asc_dvc) != ADV_TRUE) {
warn_code = ASC_WARN_BUSRESET_ERROR;
}
}
}
return warn_code;
}
static int AdvInitAsc38C1600Driver(ADV_DVC_VAR *asc_dvc)
{
const struct firmware *fw;
const char fwname[] = "advansys/38C1600.bin";
AdvPortAddr iop_base;
ushort warn_code;
int begin_addr;
int end_addr;
ushort code_sum;
long word;
int i;
int err;
unsigned long chksum;
ushort scsi_cfg1;
uchar byte;
uchar tid;
ushort bios_mem[ASC_MC_BIOSLEN / 2];
ushort wdtr_able, sdtr_able, ppr_able, tagqng_able;
uchar max_cmd[ASC_MAX_TID + 1];
if (asc_dvc->err_code != 0) {
return ADV_ERROR;
}
if (asc_dvc->chip_type != ADV_CHIP_ASC38C1600) {
asc_dvc->err_code = ASC_IERR_BAD_CHIPTYPE;
return ADV_ERROR;
}
warn_code = 0;
iop_base = asc_dvc->iop_base;
for (i = 0; i < ASC_MC_BIOSLEN / 2; i++) {
AdvReadWordLram(iop_base, ASC_MC_BIOSMEM + (2 * i),
bios_mem[i]);
}
AdvReadWordLram(iop_base, ASC_MC_WDTR_ABLE, wdtr_able);
AdvReadWordLram(iop_base, ASC_MC_SDTR_ABLE, sdtr_able);
AdvReadWordLram(iop_base, ASC_MC_PPR_ABLE, ppr_able);
AdvReadWordLram(iop_base, ASC_MC_TAGQNG_ABLE, tagqng_able);
for (tid = 0; tid <= ASC_MAX_TID; tid++) {
AdvReadByteLram(iop_base, ASC_MC_NUMBER_OF_MAX_CMD + tid,
max_cmd[tid]);
}
for (i = 0; i < 2; i++) {
AdvWriteByteRegister(iop_base, IOPB_RAM_BIST, PRE_TEST_MODE);
mdelay(10);
byte = AdvReadByteRegister(iop_base, IOPB_RAM_BIST);
if ((byte & RAM_TEST_DONE) == 0
|| (byte & 0x0F) != PRE_TEST_VALUE) {
asc_dvc->err_code = ASC_IERR_BIST_PRE_TEST;
return ADV_ERROR;
}
AdvWriteByteRegister(iop_base, IOPB_RAM_BIST, NORMAL_MODE);
mdelay(10);
if (AdvReadByteRegister(iop_base, IOPB_RAM_BIST)
!= NORMAL_VALUE) {
asc_dvc->err_code = ASC_IERR_BIST_PRE_TEST;
return ADV_ERROR;
}
}
AdvWriteByteRegister(iop_base, IOPB_RAM_BIST, RAM_TEST_MODE);
mdelay(10);
byte = AdvReadByteRegister(iop_base, IOPB_RAM_BIST);
if ((byte & RAM_TEST_DONE) == 0 || (byte & RAM_TEST_STATUS) != 0) {
asc_dvc->bist_err_code = byte;
asc_dvc->err_code = ASC_IERR_BIST_RAM_TEST;
return ADV_ERROR;
}
AdvWriteByteRegister(iop_base, IOPB_RAM_BIST, NORMAL_MODE);
err = request_firmware(&fw, fwname, asc_dvc->drv_ptr->dev);
if (err) {
printk(KERN_ERR "Failed to load image \"%s\" err %d\n",
fwname, err);
asc_dvc->err_code = ASC_IERR_MCODE_CHKSUM;
return err;
}
if (fw->size < 4) {
printk(KERN_ERR "Bogus length %zu in image \"%s\"\n",
fw->size, fwname);
release_firmware(fw);
asc_dvc->err_code = ASC_IERR_MCODE_CHKSUM;
return -EINVAL;
}
chksum = (fw->data[3] << 24) | (fw->data[2] << 16) |
(fw->data[1] << 8) | fw->data[0];
asc_dvc->err_code = AdvLoadMicrocode(iop_base, &fw->data[4],
fw->size - 4, ADV_38C1600_MEMSIZE,
chksum);
release_firmware(fw);
if (asc_dvc->err_code)
return ADV_ERROR;
for (i = 0; i < ASC_MC_BIOSLEN / 2; i++) {
AdvWriteWordLram(iop_base, ASC_MC_BIOSMEM + (2 * i),
bios_mem[i]);
}
AdvReadWordLram(iop_base, ASC_MC_CODE_BEGIN_ADDR, begin_addr);
AdvReadWordLram(iop_base, ASC_MC_CODE_END_ADDR, end_addr);
code_sum = 0;
AdvWriteWordRegister(iop_base, IOPW_RAM_ADDR, begin_addr);
for (word = begin_addr; word < end_addr; word += 2) {
code_sum += AdvReadWordAutoIncLram(iop_base);
}
AdvWriteWordLram(iop_base, ASC_MC_CODE_CHK_SUM, code_sum);
AdvReadWordLram(iop_base, ASC_MC_VERSION_DATE,
asc_dvc->cfg->mcode_date);
AdvReadWordLram(iop_base, ASC_MC_VERSION_NUM,
asc_dvc->cfg->mcode_version);
AdvWriteWordLram(iop_base, ASC_MC_CHIP_TYPE, ADV_CHIP_ASC38C1600);
scsi_cfg1 = AdvReadWordRegister(iop_base, IOPW_SCSI_CFG1);
AdvWriteWordRegister(iop_base, IOPW_SCSI_CFG1,
scsi_cfg1 | DIS_TERM_DRV);
if (asc_dvc->cfg->control_flag & CONTROL_FLAG_IGNORE_PERR) {
AdvReadWordLram(iop_base, ASC_MC_CONTROL_FLAG, word);
word |= CONTROL_FLAG_IGNORE_PERR;
AdvWriteWordLram(iop_base, ASC_MC_CONTROL_FLAG, word);
}
if ((asc_dvc->bios_ctrl & BIOS_CTRL_AIPP_DIS) == 0) {
AdvReadWordLram(iop_base, ASC_MC_CONTROL_FLAG, word);
word |= CONTROL_FLAG_ENABLE_AIPP;
AdvWriteWordLram(iop_base, ASC_MC_CONTROL_FLAG, word);
}
AdvWriteByteRegister(iop_base, IOPB_DMA_CFG0,
FIFO_THRESH_80B | START_CTL_TH | READ_CMD_MRM);
if ((asc_dvc->bios_ctrl & BIOS_CTRL_RESET_SCSI_BUS) == 0) {
AdvWriteWordLram(iop_base, ASC_MC_WDTR_ABLE,
asc_dvc->wdtr_able);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_ABLE,
asc_dvc->sdtr_able);
}
AdvWriteWordLram(iop_base, ASC_MC_DISC_ENABLE,
asc_dvc->cfg->disc_enable);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_SPEED1, asc_dvc->sdtr_speed1);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_SPEED2, asc_dvc->sdtr_speed2);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_SPEED3, asc_dvc->sdtr_speed3);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_SPEED4, asc_dvc->sdtr_speed4);
AdvWriteWordLram(iop_base, ASC_MC_DEFAULT_SCSI_CFG0,
PARITY_EN | QUEUE_128 | SEL_TMO_LONG | OUR_ID_EN |
asc_dvc->chip_scsi_id);
scsi_cfg1 = AdvReadWordRegister(iop_base, IOPW_SCSI_CFG1);
if ((AdvReadWordRegister(iop_base, IOPW_SCSI_CTRL) & 0x3F07) == 0x3F07) {
asc_dvc->err_code |= ASC_IERR_REVERSED_CABLE;
return ADV_ERROR;
}
if (scsi_cfg1 & HVD) {
asc_dvc->err_code |= ASC_IERR_HVD_DEVICE;
return ADV_ERROR;
}
if ((asc_dvc->cfg->termination & TERM_SE) == 0) {
struct pci_dev *pdev = adv_dvc_to_pdev(asc_dvc);
switch (scsi_cfg1 & C_DET_SE) {
case 0x1:
case 0x2:
case 0x3:
asc_dvc->cfg->termination |= TERM_SE;
break;
case 0x0:
if (PCI_FUNC(pdev->devfn) == 0) {
} else {
asc_dvc->cfg->termination |= TERM_SE_HI;
}
break;
}
}
scsi_cfg1 &= ~TERM_SE;
scsi_cfg1 |= (~asc_dvc->cfg->termination & TERM_SE);
scsi_cfg1 &= (~BIG_ENDIAN & ~DIS_TERM_DRV & ~TERM_POL);
AdvWriteWordLram(iop_base, ASC_MC_DEFAULT_SCSI_CFG1, scsi_cfg1);
AdvWriteWordLram(iop_base, ASC_MC_DEFAULT_MEM_CFG,
BIOS_EN | RAM_SZ_16KB);
AdvWriteWordLram(iop_base, ASC_MC_DEFAULT_SEL_MASK,
ADV_TID_TO_TIDMASK(asc_dvc->chip_scsi_id));
AdvBuildCarrierFreelist(asc_dvc);
if ((asc_dvc->icq_sp = asc_dvc->carr_freelist) == NULL) {
asc_dvc->err_code |= ASC_IERR_NO_CARRIER;
return ADV_ERROR;
}
asc_dvc->carr_freelist = (ADV_CARR_T *)
ADV_U32_TO_VADDR(le32_to_cpu(asc_dvc->icq_sp->next_vpa));
asc_dvc->icq_sp->next_vpa = cpu_to_le32(ASC_CQ_STOPPER);
AdvWriteDWordLramNoSwap(iop_base, ASC_MC_ICQ, asc_dvc->icq_sp->carr_pa);
AdvWriteDWordRegister(iop_base, IOPDW_COMMA,
le32_to_cpu(asc_dvc->icq_sp->carr_pa));
if ((asc_dvc->irq_sp = asc_dvc->carr_freelist) == NULL) {
asc_dvc->err_code |= ASC_IERR_NO_CARRIER;
return ADV_ERROR;
}
asc_dvc->carr_freelist = (ADV_CARR_T *)
ADV_U32_TO_VADDR(le32_to_cpu(asc_dvc->irq_sp->next_vpa));
asc_dvc->irq_sp->next_vpa = cpu_to_le32(ASC_CQ_STOPPER);
AdvWriteDWordLramNoSwap(iop_base, ASC_MC_IRQ, asc_dvc->irq_sp->carr_pa);
asc_dvc->carr_pending_cnt = 0;
AdvWriteByteRegister(iop_base, IOPB_INTR_ENABLES,
(ADV_INTR_ENABLE_HOST_INTR |
ADV_INTR_ENABLE_GLOBAL_INTR));
AdvReadWordLram(iop_base, ASC_MC_CODE_BEGIN_ADDR, word);
AdvWriteWordRegister(iop_base, IOPW_PC, word);
AdvWriteWordRegister(iop_base, IOPW_RISC_CSR, ADV_RISC_CSR_RUN);
if (asc_dvc->bios_ctrl & BIOS_CTRL_RESET_SCSI_BUS) {
if (bios_mem[(ASC_MC_BIOS_SIGNATURE - ASC_MC_BIOSMEM) / 2] ==
0x55AA) {
AdvWriteWordLram(iop_base, ASC_MC_WDTR_ABLE, wdtr_able);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_ABLE, sdtr_able);
AdvWriteWordLram(iop_base, ASC_MC_PPR_ABLE, ppr_able);
AdvWriteWordLram(iop_base, ASC_MC_TAGQNG_ABLE,
tagqng_able);
for (tid = 0; tid <= ASC_MAX_TID; tid++) {
AdvWriteByteLram(iop_base,
ASC_MC_NUMBER_OF_MAX_CMD + tid,
max_cmd[tid]);
}
} else {
if (AdvResetSB(asc_dvc) != ADV_TRUE) {
warn_code = ASC_WARN_BUSRESET_ERROR;
}
}
}
return warn_code;
}
static int AdvResetChipAndSB(ADV_DVC_VAR *asc_dvc)
{
int status;
ushort wdtr_able, sdtr_able, tagqng_able;
ushort ppr_able = 0;
uchar tid, max_cmd[ADV_MAX_TID + 1];
AdvPortAddr iop_base;
ushort bios_sig;
iop_base = asc_dvc->iop_base;
AdvReadWordLram(iop_base, ASC_MC_WDTR_ABLE, wdtr_able);
AdvReadWordLram(iop_base, ASC_MC_SDTR_ABLE, sdtr_able);
if (asc_dvc->chip_type == ADV_CHIP_ASC38C1600) {
AdvReadWordLram(iop_base, ASC_MC_PPR_ABLE, ppr_able);
}
AdvReadWordLram(iop_base, ASC_MC_TAGQNG_ABLE, tagqng_able);
for (tid = 0; tid <= ADV_MAX_TID; tid++) {
AdvReadByteLram(iop_base, ASC_MC_NUMBER_OF_MAX_CMD + tid,
max_cmd[tid]);
}
AdvReadWordLram(iop_base, ASC_MC_BIOS_SIGNATURE, bios_sig);
AdvWriteWordLram(iop_base, ASC_MC_BIOS_SIGNATURE, 0);
AdvWriteWordRegister(iop_base, IOPW_RISC_CSR, ADV_RISC_CSR_STOP);
AdvWriteWordRegister(iop_base, IOPW_CTRL_REG, ADV_CTRL_REG_CMD_RESET);
mdelay(100);
AdvWriteWordRegister(iop_base, IOPW_CTRL_REG,
ADV_CTRL_REG_CMD_WR_IO_REG);
asc_dvc->err_code = 0;
if (asc_dvc->chip_type == ADV_CHIP_ASC38C1600) {
status = AdvInitAsc38C1600Driver(asc_dvc);
} else if (asc_dvc->chip_type == ADV_CHIP_ASC38C0800) {
status = AdvInitAsc38C0800Driver(asc_dvc);
} else {
status = AdvInitAsc3550Driver(asc_dvc);
}
if (status == 0) {
status = ADV_TRUE;
} else {
status = ADV_FALSE;
}
AdvWriteWordLram(iop_base, ASC_MC_BIOS_SIGNATURE, bios_sig);
AdvWriteWordLram(iop_base, ASC_MC_WDTR_ABLE, wdtr_able);
AdvWriteWordLram(iop_base, ASC_MC_SDTR_ABLE, sdtr_able);
if (asc_dvc->chip_type == ADV_CHIP_ASC38C1600) {
AdvWriteWordLram(iop_base, ASC_MC_PPR_ABLE, ppr_able);
}
AdvWriteWordLram(iop_base, ASC_MC_TAGQNG_ABLE, tagqng_able);
for (tid = 0; tid <= ADV_MAX_TID; tid++) {
AdvWriteByteLram(iop_base, ASC_MC_NUMBER_OF_MAX_CMD + tid,
max_cmd[tid]);
}
return status;
}
static void adv_async_callback(ADV_DVC_VAR *adv_dvc_varp, uchar code)
{
switch (code) {
case ADV_ASYNC_SCSI_BUS_RESET_DET:
ASC_DBG(0, "ADV_ASYNC_SCSI_BUS_RESET_DET\n");
break;
case ADV_ASYNC_RDMA_FAILURE:
ASC_DBG(0, "ADV_ASYNC_RDMA_FAILURE\n");
AdvResetChipAndSB(adv_dvc_varp);
break;
case ADV_HOST_SCSI_BUS_RESET:
ASC_DBG(0, "ADV_HOST_SCSI_BUS_RESET\n");
break;
default:
ASC_DBG(0, "unknown code 0x%x\n", code);
break;
}
}
static void adv_isr_callback(ADV_DVC_VAR *adv_dvc_varp, ADV_SCSI_REQ_Q *scsiqp)
{
struct asc_board *boardp;
adv_req_t *reqp;
adv_sgblk_t *sgblkp;
struct scsi_cmnd *scp;
struct Scsi_Host *shost;
ADV_DCNT resid_cnt;
ASC_DBG(1, "adv_dvc_varp 0x%lx, scsiqp 0x%lx\n",
(ulong)adv_dvc_varp, (ulong)scsiqp);
ASC_DBG_PRT_ADV_SCSI_REQ_Q(2, scsiqp);
reqp = (adv_req_t *)ADV_U32_TO_VADDR(scsiqp->srb_ptr);
ASC_DBG(1, "reqp 0x%lx\n", (ulong)reqp);
if (reqp == NULL) {
ASC_PRINT("adv_isr_callback: reqp is NULL\n");
return;
}
scp = reqp->cmndp;
ASC_DBG(1, "scp 0x%p\n", scp);
if (scp == NULL) {
ASC_PRINT
("adv_isr_callback: scp is NULL; adv_req_t dropped.\n");
return;
}
ASC_DBG_PRT_CDB(2, scp->cmnd, scp->cmd_len);
shost = scp->device->host;
ASC_STATS(shost, callback);
ASC_DBG(1, "shost 0x%p\n", shost);
boardp = shost_priv(shost);
BUG_ON(adv_dvc_varp != &boardp->dvc_var.adv_dvc_var);
switch (scsiqp->done_status) {
case QD_NO_ERROR:
ASC_DBG(2, "QD_NO_ERROR\n");
scp->result = 0;
resid_cnt = le32_to_cpu(scsiqp->data_cnt);
if (scsi_bufflen(scp) != 0 && resid_cnt != 0 &&
resid_cnt <= scsi_bufflen(scp)) {
ASC_DBG(1, "underrun condition %lu bytes\n",
(ulong)resid_cnt);
scsi_set_resid(scp, resid_cnt);
}
break;
case QD_WITH_ERROR:
ASC_DBG(2, "QD_WITH_ERROR\n");
switch (scsiqp->host_status) {
case QHSTA_NO_ERROR:
if (scsiqp->scsi_status == SAM_STAT_CHECK_CONDITION) {
ASC_DBG(2, "SAM_STAT_CHECK_CONDITION\n");
ASC_DBG_PRT_SENSE(2, scp->sense_buffer,
SCSI_SENSE_BUFFERSIZE);
scp->result = DRIVER_BYTE(DRIVER_SENSE) |
STATUS_BYTE(scsiqp->scsi_status);
} else {
scp->result = STATUS_BYTE(scsiqp->scsi_status);
}
break;
default:
ASC_DBG(1, "host_status 0x%x\n", scsiqp->host_status);
scp->result = HOST_BYTE(DID_BAD_TARGET);
break;
}
break;
case QD_ABORTED_BY_HOST:
ASC_DBG(1, "QD_ABORTED_BY_HOST\n");
scp->result =
HOST_BYTE(DID_ABORT) | STATUS_BYTE(scsiqp->scsi_status);
break;
default:
ASC_DBG(1, "done_status 0x%x\n", scsiqp->done_status);
scp->result =
HOST_BYTE(DID_ERROR) | STATUS_BYTE(scsiqp->scsi_status);
break;
}
if ((boardp->init_tidmask & ADV_TID_TO_TIDMASK(scp->device->id)) == 0 &&
scsiqp->done_status == QD_NO_ERROR &&
scsiqp->host_status == QHSTA_NO_ERROR) {
boardp->init_tidmask |= ADV_TID_TO_TIDMASK(scp->device->id);
}
asc_scsi_done(scp);
while ((sgblkp = reqp->sgblkp) != NULL) {
reqp->sgblkp = sgblkp->next_sgblkp;
sgblkp->next_sgblkp = boardp->adv_sgblkp;
boardp->adv_sgblkp = sgblkp;
}
reqp->next_reqp = boardp->adv_reqp;
boardp->adv_reqp = reqp;
ASC_DBG(1, "done\n");
}
static int AdvISR(ADV_DVC_VAR *asc_dvc)
{
AdvPortAddr iop_base;
uchar int_stat;
ushort target_bit;
ADV_CARR_T *free_carrp;
ADV_VADDR irq_next_vpa;
ADV_SCSI_REQ_Q *scsiq;
iop_base = asc_dvc->iop_base;
int_stat = AdvReadByteRegister(iop_base, IOPB_INTR_STATUS_REG);
if ((int_stat & (ADV_INTR_STATUS_INTRA | ADV_INTR_STATUS_INTRB |
ADV_INTR_STATUS_INTRC)) == 0) {
return ADV_FALSE;
}
if (int_stat & ADV_INTR_STATUS_INTRB) {
uchar intrb_code;
AdvReadByteLram(iop_base, ASC_MC_INTRB_CODE, intrb_code);
if (asc_dvc->chip_type == ADV_CHIP_ASC3550 ||
asc_dvc->chip_type == ADV_CHIP_ASC38C0800) {
if (intrb_code == ADV_ASYNC_CARRIER_READY_FAILURE &&
asc_dvc->carr_pending_cnt != 0) {
AdvWriteByteRegister(iop_base, IOPB_TICKLE,
ADV_TICKLE_A);
if (asc_dvc->chip_type == ADV_CHIP_ASC3550) {
AdvWriteByteRegister(iop_base,
IOPB_TICKLE,
ADV_TICKLE_NOP);
}
}
}
adv_async_callback(asc_dvc, intrb_code);
}
while (((irq_next_vpa =
le32_to_cpu(asc_dvc->irq_sp->next_vpa)) & ASC_RQ_DONE) != 0) {
scsiq = (ADV_SCSI_REQ_Q *)
ADV_U32_TO_VADDR(le32_to_cpu(asc_dvc->irq_sp->areq_vpa));
if ((irq_next_vpa & ASC_RQ_GOOD) != 0) {
scsiq->done_status = QD_NO_ERROR;
scsiq->host_status = scsiq->scsi_status = 0;
scsiq->data_cnt = 0L;
}
free_carrp = asc_dvc->irq_sp;
asc_dvc->irq_sp = (ADV_CARR_T *)
ADV_U32_TO_VADDR(ASC_GET_CARRP(irq_next_vpa));
free_carrp->next_vpa =
cpu_to_le32(ADV_VADDR_TO_U32(asc_dvc->carr_freelist));
asc_dvc->carr_freelist = free_carrp;
asc_dvc->carr_pending_cnt--;
target_bit = ADV_TID_TO_TIDMASK(scsiq->target_id);
scsiq->cntl = 0;
scsiq->a_flag |= ADV_SCSIQ_DONE;
adv_isr_callback(asc_dvc, scsiq);
}
return ADV_TRUE;
}
static int AscSetLibErrorCode(ASC_DVC_VAR *asc_dvc, ushort err_code)
{
if (asc_dvc->err_code == 0) {
asc_dvc->err_code = err_code;
AscWriteLramWord(asc_dvc->iop_base, ASCV_ASCDVC_ERR_CODE_W,
err_code);
}
return err_code;
}
static void AscAckInterrupt(PortAddr iop_base)
{
uchar host_flag;
uchar risc_flag;
ushort loop;
loop = 0;
do {
risc_flag = AscReadLramByte(iop_base, ASCV_RISC_FLAG_B);
if (loop++ > 0x7FFF) {
break;
}
} while ((risc_flag & ASC_RISC_FLAG_GEN_INT) != 0);
host_flag =
AscReadLramByte(iop_base,
ASCV_HOST_FLAG_B) & (~ASC_HOST_FLAG_ACK_INT);
AscWriteLramByte(iop_base, ASCV_HOST_FLAG_B,
(uchar)(host_flag | ASC_HOST_FLAG_ACK_INT));
AscSetChipStatus(iop_base, CIW_INT_ACK);
loop = 0;
while (AscGetChipStatus(iop_base) & CSW_INT_PENDING) {
AscSetChipStatus(iop_base, CIW_INT_ACK);
if (loop++ > 3) {
break;
}
}
AscWriteLramByte(iop_base, ASCV_HOST_FLAG_B, host_flag);
}
static uchar AscGetSynPeriodIndex(ASC_DVC_VAR *asc_dvc, uchar syn_time)
{
const uchar *period_table;
int max_index;
int min_index;
int i;
period_table = asc_dvc->sdtr_period_tbl;
max_index = (int)asc_dvc->max_sdtr_index;
min_index = (int)asc_dvc->min_sdtr_index;
if ((syn_time <= period_table[max_index])) {
for (i = min_index; i < (max_index - 1); i++) {
if (syn_time <= period_table[i]) {
return (uchar)i;
}
}
return (uchar)max_index;
} else {
return (uchar)(max_index + 1);
}
}
static uchar
AscMsgOutSDTR(ASC_DVC_VAR *asc_dvc, uchar sdtr_period, uchar sdtr_offset)
{
EXT_MSG sdtr_buf;
uchar sdtr_period_index;
PortAddr iop_base;
iop_base = asc_dvc->iop_base;
sdtr_buf.msg_type = EXTENDED_MESSAGE;
sdtr_buf.msg_len = MS_SDTR_LEN;
sdtr_buf.msg_req = EXTENDED_SDTR;
sdtr_buf.xfer_period = sdtr_period;
sdtr_offset &= ASC_SYN_MAX_OFFSET;
sdtr_buf.req_ack_offset = sdtr_offset;
sdtr_period_index = AscGetSynPeriodIndex(asc_dvc, sdtr_period);
if (sdtr_period_index <= asc_dvc->max_sdtr_index) {
AscMemWordCopyPtrToLram(iop_base, ASCV_MSGOUT_BEG,
(uchar *)&sdtr_buf,
sizeof(EXT_MSG) >> 1);
return ((sdtr_period_index << 4) | sdtr_offset);
} else {
sdtr_buf.req_ack_offset = 0;
AscMemWordCopyPtrToLram(iop_base, ASCV_MSGOUT_BEG,
(uchar *)&sdtr_buf,
sizeof(EXT_MSG) >> 1);
return 0;
}
}
static uchar
AscCalSDTRData(ASC_DVC_VAR *asc_dvc, uchar sdtr_period, uchar syn_offset)
{
uchar byte;
uchar sdtr_period_ix;
sdtr_period_ix = AscGetSynPeriodIndex(asc_dvc, sdtr_period);
if (sdtr_period_ix > asc_dvc->max_sdtr_index)
return 0xFF;
byte = (sdtr_period_ix << 4) | (syn_offset & ASC_SYN_MAX_OFFSET);
return byte;
}
static int AscSetChipSynRegAtID(PortAddr iop_base, uchar id, uchar sdtr_data)
{
ASC_SCSI_BIT_ID_TYPE org_id;
int i;
int sta = TRUE;
AscSetBank(iop_base, 1);
org_id = AscReadChipDvcID(iop_base);
for (i = 0; i <= ASC_MAX_TID; i++) {
if (org_id == (0x01 << i))
break;
}
org_id = (ASC_SCSI_BIT_ID_TYPE) i;
AscWriteChipDvcID(iop_base, id);
if (AscReadChipDvcID(iop_base) == (0x01 << id)) {
AscSetBank(iop_base, 0);
AscSetChipSyn(iop_base, sdtr_data);
if (AscGetChipSyn(iop_base) != sdtr_data) {
sta = FALSE;
}
} else {
sta = FALSE;
}
AscSetBank(iop_base, 1);
AscWriteChipDvcID(iop_base, org_id);
AscSetBank(iop_base, 0);
return (sta);
}
static void AscSetChipSDTR(PortAddr iop_base, uchar sdtr_data, uchar tid_no)
{
AscSetChipSynRegAtID(iop_base, tid_no, sdtr_data);
AscPutMCodeSDTRDoneAtID(iop_base, tid_no, sdtr_data);
}
static int AscIsrChipHalted(ASC_DVC_VAR *asc_dvc)
{
EXT_MSG ext_msg;
EXT_MSG out_msg;
ushort halt_q_addr;
int sdtr_accept;
ushort int_halt_code;
ASC_SCSI_BIT_ID_TYPE scsi_busy;
ASC_SCSI_BIT_ID_TYPE target_id;
PortAddr iop_base;
uchar tag_code;
uchar q_status;
uchar halt_qp;
uchar sdtr_data;
uchar target_ix;
uchar q_cntl, tid_no;
uchar cur_dvc_qng;
uchar asyn_sdtr;
uchar scsi_status;
struct asc_board *boardp;
BUG_ON(!asc_dvc->drv_ptr);
boardp = asc_dvc->drv_ptr;
iop_base = asc_dvc->iop_base;
int_halt_code = AscReadLramWord(iop_base, ASCV_HALTCODE_W);
halt_qp = AscReadLramByte(iop_base, ASCV_CURCDB_B);
halt_q_addr = ASC_QNO_TO_QADDR(halt_qp);
target_ix = AscReadLramByte(iop_base,
(ushort)(halt_q_addr +
(ushort)ASC_SCSIQ_B_TARGET_IX));
q_cntl = AscReadLramByte(iop_base,
(ushort)(halt_q_addr + (ushort)ASC_SCSIQ_B_CNTL));
tid_no = ASC_TIX_TO_TID(target_ix);
target_id = (uchar)ASC_TID_TO_TARGET_ID(tid_no);
if (asc_dvc->pci_fix_asyn_xfer & target_id) {
asyn_sdtr = ASYN_SDTR_DATA_FIX_PCI_REV_AB;
} else {
asyn_sdtr = 0;
}
if (int_halt_code == ASC_HALT_DISABLE_ASYN_USE_SYN_FIX) {
if (asc_dvc->pci_fix_asyn_xfer & target_id) {
AscSetChipSDTR(iop_base, 0, tid_no);
boardp->sdtr_data[tid_no] = 0;
}
AscWriteLramWord(iop_base, ASCV_HALTCODE_W, 0);
return (0);
} else if (int_halt_code == ASC_HALT_ENABLE_ASYN_USE_SYN_FIX) {
if (asc_dvc->pci_fix_asyn_xfer & target_id) {
AscSetChipSDTR(iop_base, asyn_sdtr, tid_no);
boardp->sdtr_data[tid_no] = asyn_sdtr;
}
AscWriteLramWord(iop_base, ASCV_HALTCODE_W, 0);
return (0);
} else if (int_halt_code == ASC_HALT_EXTMSG_IN) {
AscMemWordCopyPtrFromLram(iop_base,
ASCV_MSGIN_BEG,
(uchar *)&ext_msg,
sizeof(EXT_MSG) >> 1);
if (ext_msg.msg_type == EXTENDED_MESSAGE &&
ext_msg.msg_req == EXTENDED_SDTR &&
ext_msg.msg_len == MS_SDTR_LEN) {
sdtr_accept = TRUE;
if ((ext_msg.req_ack_offset > ASC_SYN_MAX_OFFSET)) {
sdtr_accept = FALSE;
ext_msg.req_ack_offset = ASC_SYN_MAX_OFFSET;
}
if ((ext_msg.xfer_period <
asc_dvc->sdtr_period_tbl[asc_dvc->min_sdtr_index])
|| (ext_msg.xfer_period >
asc_dvc->sdtr_period_tbl[asc_dvc->
max_sdtr_index])) {
sdtr_accept = FALSE;
ext_msg.xfer_period =
asc_dvc->sdtr_period_tbl[asc_dvc->
min_sdtr_index];
}
if (sdtr_accept) {
sdtr_data =
AscCalSDTRData(asc_dvc, ext_msg.xfer_period,
ext_msg.req_ack_offset);
if ((sdtr_data == 0xFF)) {
q_cntl |= QC_MSG_OUT;
asc_dvc->init_sdtr &= ~target_id;
asc_dvc->sdtr_done &= ~target_id;
AscSetChipSDTR(iop_base, asyn_sdtr,
tid_no);
boardp->sdtr_data[tid_no] = asyn_sdtr;
}
}
if (ext_msg.req_ack_offset == 0) {
q_cntl &= ~QC_MSG_OUT;
asc_dvc->init_sdtr &= ~target_id;
asc_dvc->sdtr_done &= ~target_id;
AscSetChipSDTR(iop_base, asyn_sdtr, tid_no);
} else {
if (sdtr_accept && (q_cntl & QC_MSG_OUT)) {
q_cntl &= ~QC_MSG_OUT;
asc_dvc->sdtr_done |= target_id;
asc_dvc->init_sdtr |= target_id;
asc_dvc->pci_fix_asyn_xfer &=
~target_id;
sdtr_data =
AscCalSDTRData(asc_dvc,
ext_msg.xfer_period,
ext_msg.
req_ack_offset);
AscSetChipSDTR(iop_base, sdtr_data,
tid_no);
boardp->sdtr_data[tid_no] = sdtr_data;
} else {
q_cntl |= QC_MSG_OUT;
AscMsgOutSDTR(asc_dvc,
ext_msg.xfer_period,
ext_msg.req_ack_offset);
asc_dvc->pci_fix_asyn_xfer &=
~target_id;
sdtr_data =
AscCalSDTRData(asc_dvc,
ext_msg.xfer_period,
ext_msg.
req_ack_offset);
AscSetChipSDTR(iop_base, sdtr_data,
tid_no);
boardp->sdtr_data[tid_no] = sdtr_data;
asc_dvc->sdtr_done |= target_id;
asc_dvc->init_sdtr |= target_id;
}
}
AscWriteLramByte(iop_base,
(ushort)(halt_q_addr +
(ushort)ASC_SCSIQ_B_CNTL),
q_cntl);
AscWriteLramWord(iop_base, ASCV_HALTCODE_W, 0);
return (0);
} else if (ext_msg.msg_type == EXTENDED_MESSAGE &&
ext_msg.msg_req == EXTENDED_WDTR &&
ext_msg.msg_len == MS_WDTR_LEN) {
ext_msg.wdtr_width = 0;
AscMemWordCopyPtrToLram(iop_base,
ASCV_MSGOUT_BEG,
(uchar *)&ext_msg,
sizeof(EXT_MSG) >> 1);
q_cntl |= QC_MSG_OUT;
AscWriteLramByte(iop_base,
(ushort)(halt_q_addr +
(ushort)ASC_SCSIQ_B_CNTL),
q_cntl);
AscWriteLramWord(iop_base, ASCV_HALTCODE_W, 0);
return (0);
} else {
ext_msg.msg_type = MESSAGE_REJECT;
AscMemWordCopyPtrToLram(iop_base,
ASCV_MSGOUT_BEG,
(uchar *)&ext_msg,
sizeof(EXT_MSG) >> 1);
q_cntl |= QC_MSG_OUT;
AscWriteLramByte(iop_base,
(ushort)(halt_q_addr +
(ushort)ASC_SCSIQ_B_CNTL),
q_cntl);
AscWriteLramWord(iop_base, ASCV_HALTCODE_W, 0);
return (0);
}
} else if (int_halt_code == ASC_HALT_CHK_CONDITION) {
q_cntl |= QC_REQ_SENSE;
if ((asc_dvc->init_sdtr & target_id) != 0) {
asc_dvc->sdtr_done &= ~target_id;
sdtr_data = AscGetMCodeInitSDTRAtID(iop_base, tid_no);
q_cntl |= QC_MSG_OUT;
AscMsgOutSDTR(asc_dvc,
asc_dvc->
sdtr_period_tbl[(sdtr_data >> 4) &
(uchar)(asc_dvc->
max_sdtr_index -
1)],
(uchar)(sdtr_data & (uchar)
ASC_SYN_MAX_OFFSET));
}
AscWriteLramByte(iop_base,
(ushort)(halt_q_addr +
(ushort)ASC_SCSIQ_B_CNTL), q_cntl);
tag_code = AscReadLramByte(iop_base,
(ushort)(halt_q_addr + (ushort)
ASC_SCSIQ_B_TAG_CODE));
tag_code &= 0xDC;
if ((asc_dvc->pci_fix_asyn_xfer & target_id)
&& !(asc_dvc->pci_fix_asyn_xfer_always & target_id)
) {
tag_code |= (ASC_TAG_FLAG_DISABLE_DISCONNECT
| ASC_TAG_FLAG_DISABLE_ASYN_USE_SYN_FIX);
}
AscWriteLramByte(iop_base,
(ushort)(halt_q_addr +
(ushort)ASC_SCSIQ_B_TAG_CODE),
tag_code);
q_status = AscReadLramByte(iop_base,
(ushort)(halt_q_addr + (ushort)
ASC_SCSIQ_B_STATUS));
q_status |= (QS_READY | QS_BUSY);
AscWriteLramByte(iop_base,
(ushort)(halt_q_addr +
(ushort)ASC_SCSIQ_B_STATUS),
q_status);
scsi_busy = AscReadLramByte(iop_base, (ushort)ASCV_SCSIBUSY_B);
scsi_busy &= ~target_id;
AscWriteLramByte(iop_base, (ushort)ASCV_SCSIBUSY_B, scsi_busy);
AscWriteLramWord(iop_base, ASCV_HALTCODE_W, 0);
return (0);
} else if (int_halt_code == ASC_HALT_SDTR_REJECTED) {
AscMemWordCopyPtrFromLram(iop_base,
ASCV_MSGOUT_BEG,
(uchar *)&out_msg,
sizeof(EXT_MSG) >> 1);
if ((out_msg.msg_type == EXTENDED_MESSAGE) &&
(out_msg.msg_len == MS_SDTR_LEN) &&
(out_msg.msg_req == EXTENDED_SDTR)) {
asc_dvc->init_sdtr &= ~target_id;
asc_dvc->sdtr_done &= ~target_id;
AscSetChipSDTR(iop_base, asyn_sdtr, tid_no);
boardp->sdtr_data[tid_no] = asyn_sdtr;
}
q_cntl &= ~QC_MSG_OUT;
AscWriteLramByte(iop_base,
(ushort)(halt_q_addr +
(ushort)ASC_SCSIQ_B_CNTL), q_cntl);
AscWriteLramWord(iop_base, ASCV_HALTCODE_W, 0);
return (0);
} else if (int_halt_code == ASC_HALT_SS_QUEUE_FULL) {
scsi_status = AscReadLramByte(iop_base,
(ushort)((ushort)halt_q_addr +
(ushort)
ASC_SCSIQ_SCSI_STATUS));
cur_dvc_qng =
AscReadLramByte(iop_base,
(ushort)((ushort)ASC_QADR_BEG +
(ushort)target_ix));
if ((cur_dvc_qng > 0) && (asc_dvc->cur_dvc_qng[tid_no] > 0)) {
scsi_busy = AscReadLramByte(iop_base,
(ushort)ASCV_SCSIBUSY_B);
scsi_busy |= target_id;
AscWriteLramByte(iop_base,
(ushort)ASCV_SCSIBUSY_B, scsi_busy);
asc_dvc->queue_full_or_busy |= target_id;
if (scsi_status == SAM_STAT_TASK_SET_FULL) {
if (cur_dvc_qng > ASC_MIN_TAGGED_CMD) {
cur_dvc_qng -= 1;
asc_dvc->max_dvc_qng[tid_no] =
cur_dvc_qng;
AscWriteLramByte(iop_base,
(ushort)((ushort)
ASCV_MAX_DVC_QNG_BEG
+ (ushort)
tid_no),
cur_dvc_qng);
boardp->queue_full |= target_id;
boardp->queue_full_cnt[tid_no] =
cur_dvc_qng;
}
}
}
AscWriteLramWord(iop_base, ASCV_HALTCODE_W, 0);
return (0);
}
#if CC_VERY_LONG_SG_LIST
else if (int_halt_code == ASC_HALT_HOST_COPY_SG_LIST_TO_RISC) {
uchar q_no;
ushort q_addr;
uchar sg_wk_q_no;
uchar first_sg_wk_q_no;
ASC_SCSI_Q *scsiq;
ASC_SG_HEAD *sg_head;
ASC_SG_LIST_Q scsi_sg_q;
ushort sg_list_dwords;
ushort sg_entry_cnt;
uchar next_qp;
int i;
q_no = AscReadLramByte(iop_base, (ushort)ASCV_REQ_SG_LIST_QP);
if (q_no == ASC_QLINK_END)
return 0;
q_addr = ASC_QNO_TO_QADDR(q_no);
scsiq = (ASC_SCSI_Q *)
ASC_SRB2SCSIQ(ASC_U32_TO_VADDR(AscReadLramDWord(iop_base,
(ushort)
(q_addr +
ASC_SCSIQ_D_SRBPTR))));
sg_wk_q_no = AscReadLramByte(iop_base,
(ushort)(q_addr +
ASC_SCSIQ_B_SG_WK_QP));
first_sg_wk_q_no = AscReadLramByte(iop_base,
(ushort)(q_addr +
ASC_SCSIQ_B_FIRST_SG_WK_QP));
AscWriteLramByte(iop_base,
(ushort)(q_addr +
(ushort)ASC_SCSIQ_B_SG_WK_QP),
first_sg_wk_q_no);
sg_head = scsiq->sg_head;
if (scsiq->remain_sg_entry_cnt > (ASC_MAX_SG_LIST - 1)) {
sg_entry_cnt = ASC_MAX_SG_LIST - 1;
scsiq->remain_sg_entry_cnt -= (ASC_MAX_SG_LIST - 1);
} else {
sg_entry_cnt = scsiq->remain_sg_entry_cnt;
scsiq->remain_sg_entry_cnt = 0;
}
next_qp = first_sg_wk_q_no;
q_addr = ASC_QNO_TO_QADDR(next_qp);
scsi_sg_q.sg_head_qp = q_no;
scsi_sg_q.cntl = QCSG_SG_XFER_LIST;
for (i = 0; i < sg_head->queue_cnt; i++) {
scsi_sg_q.seq_no = i + 1;
if (sg_entry_cnt > ASC_SG_LIST_PER_Q) {
sg_list_dwords = (uchar)(ASC_SG_LIST_PER_Q * 2);
sg_entry_cnt -= ASC_SG_LIST_PER_Q;
scsi_sg_q.sg_list_cnt = ASC_SG_LIST_PER_Q - 1;
scsi_sg_q.sg_cur_list_cnt =
ASC_SG_LIST_PER_Q - 1;
} else {
if (scsiq->remain_sg_entry_cnt != 0) {
scsi_sg_q.cntl |= QCSG_SG_XFER_MORE;
} else {
scsi_sg_q.cntl |= QCSG_SG_XFER_END;
}
sg_list_dwords = sg_entry_cnt << 1;
scsi_sg_q.sg_list_cnt = sg_entry_cnt - 1;
scsi_sg_q.sg_cur_list_cnt = sg_entry_cnt - 1;
sg_entry_cnt = 0;
}
scsi_sg_q.q_no = next_qp;
AscMemWordCopyPtrToLram(iop_base,
q_addr + ASC_SCSIQ_SGHD_CPY_BEG,
(uchar *)&scsi_sg_q,
sizeof(ASC_SG_LIST_Q) >> 1);
AscMemDWordCopyPtrToLram(iop_base,
q_addr + ASC_SGQ_LIST_BEG,
(uchar *)&sg_head->
sg_list[scsiq->next_sg_index],
sg_list_dwords);
scsiq->next_sg_index += ASC_SG_LIST_PER_Q;
if (scsi_sg_q.cntl & QCSG_SG_XFER_END) {
break;
}
next_qp = AscReadLramByte(iop_base,
(ushort)(q_addr +
ASC_SCSIQ_B_FWD));
q_addr = ASC_QNO_TO_QADDR(next_qp);
}
AscWriteLramWord(iop_base, ASCV_HALTCODE_W, 0);
return (0);
}
#endif
return (0);
}
static void
DvcGetQinfo(PortAddr iop_base, ushort s_addr, uchar *inbuf, int words)
{
int i;
ushort word;
AscSetChipLramAddr(iop_base, s_addr);
for (i = 0; i < 2 * words; i += 2) {
if (i == 10) {
continue;
}
word = inpw(iop_base + IOP_RAM_DATA);
inbuf[i] = word & 0xff;
inbuf[i + 1] = (word >> 8) & 0xff;
}
ASC_DBG_PRT_HEX(2, "DvcGetQinfo", inbuf, 2 * words);
}
static uchar
_AscCopyLramScsiDoneQ(PortAddr iop_base,
ushort q_addr,
ASC_QDONE_INFO *scsiq, ASC_DCNT max_dma_count)
{
ushort _val;
uchar sg_queue_cnt;
DvcGetQinfo(iop_base,
q_addr + ASC_SCSIQ_DONE_INFO_BEG,
(uchar *)scsiq,
(sizeof(ASC_SCSIQ_2) + sizeof(ASC_SCSIQ_3)) / 2);
_val = AscReadLramWord(iop_base,
(ushort)(q_addr + (ushort)ASC_SCSIQ_B_STATUS));
scsiq->q_status = (uchar)_val;
scsiq->q_no = (uchar)(_val >> 8);
_val = AscReadLramWord(iop_base,
(ushort)(q_addr + (ushort)ASC_SCSIQ_B_CNTL));
scsiq->cntl = (uchar)_val;
sg_queue_cnt = (uchar)(_val >> 8);
_val = AscReadLramWord(iop_base,
(ushort)(q_addr +
(ushort)ASC_SCSIQ_B_SENSE_LEN));
scsiq->sense_len = (uchar)_val;
scsiq->extra_bytes = (uchar)(_val >> 8);
scsiq->remain_bytes = (((ADV_DCNT)AscReadLramWord(iop_base,
(ushort)(q_addr +
(ushort)
ASC_SCSIQ_W_ALT_DC1)))
<< 16);
scsiq->remain_bytes += AscReadLramWord(iop_base,
(ushort)(q_addr + (ushort)
ASC_SCSIQ_DW_REMAIN_XFER_CNT));
scsiq->remain_bytes &= max_dma_count;
return sg_queue_cnt;
}
static void asc_isr_callback(ASC_DVC_VAR *asc_dvc_varp, ASC_QDONE_INFO *qdonep)
{
struct asc_board *boardp;
struct scsi_cmnd *scp;
struct Scsi_Host *shost;
ASC_DBG(1, "asc_dvc_varp 0x%p, qdonep 0x%p\n", asc_dvc_varp, qdonep);
ASC_DBG_PRT_ASC_QDONE_INFO(2, qdonep);
scp = advansys_srb_to_ptr(asc_dvc_varp, qdonep->d2.srb_ptr);
if (!scp)
return;
ASC_DBG_PRT_CDB(2, scp->cmnd, scp->cmd_len);
shost = scp->device->host;
ASC_STATS(shost, callback);
ASC_DBG(1, "shost 0x%p\n", shost);
boardp = shost_priv(shost);
BUG_ON(asc_dvc_varp != &boardp->dvc_var.asc_dvc_var);
dma_unmap_single(boardp->dev, scp->SCp.dma_handle,
SCSI_SENSE_BUFFERSIZE, DMA_FROM_DEVICE);
switch (qdonep->d3.done_stat) {
case QD_NO_ERROR:
ASC_DBG(2, "QD_NO_ERROR\n");
scp->result = 0;
if (scsi_bufflen(scp) != 0 && qdonep->remain_bytes != 0 &&
qdonep->remain_bytes <= scsi_bufflen(scp)) {
ASC_DBG(1, "underrun condition %u bytes\n",
(unsigned)qdonep->remain_bytes);
scsi_set_resid(scp, qdonep->remain_bytes);
}
break;
case QD_WITH_ERROR:
ASC_DBG(2, "QD_WITH_ERROR\n");
switch (qdonep->d3.host_stat) {
case QHSTA_NO_ERROR:
if (qdonep->d3.scsi_stat == SAM_STAT_CHECK_CONDITION) {
ASC_DBG(2, "SAM_STAT_CHECK_CONDITION\n");
ASC_DBG_PRT_SENSE(2, scp->sense_buffer,
SCSI_SENSE_BUFFERSIZE);
scp->result = DRIVER_BYTE(DRIVER_SENSE) |
STATUS_BYTE(qdonep->d3.scsi_stat);
} else {
scp->result = STATUS_BYTE(qdonep->d3.scsi_stat);
}
break;
default:
ASC_DBG(1, "host_stat 0x%x\n", qdonep->d3.host_stat);
scp->result = HOST_BYTE(DID_BAD_TARGET);
break;
}
break;
case QD_ABORTED_BY_HOST:
ASC_DBG(1, "QD_ABORTED_BY_HOST\n");
scp->result =
HOST_BYTE(DID_ABORT) | MSG_BYTE(qdonep->d3.
scsi_msg) |
STATUS_BYTE(qdonep->d3.scsi_stat);
break;
default:
ASC_DBG(1, "done_stat 0x%x\n", qdonep->d3.done_stat);
scp->result =
HOST_BYTE(DID_ERROR) | MSG_BYTE(qdonep->d3.
scsi_msg) |
STATUS_BYTE(qdonep->d3.scsi_stat);
break;
}
if ((boardp->init_tidmask & ADV_TID_TO_TIDMASK(scp->device->id)) == 0 &&
qdonep->d3.done_stat == QD_NO_ERROR &&
qdonep->d3.host_stat == QHSTA_NO_ERROR) {
boardp->init_tidmask |= ADV_TID_TO_TIDMASK(scp->device->id);
}
asc_scsi_done(scp);
}
static int AscIsrQDone(ASC_DVC_VAR *asc_dvc)
{
uchar next_qp;
uchar n_q_used;
uchar sg_list_qp;
uchar sg_queue_cnt;
uchar q_cnt;
uchar done_q_tail;
uchar tid_no;
ASC_SCSI_BIT_ID_TYPE scsi_busy;
ASC_SCSI_BIT_ID_TYPE target_id;
PortAddr iop_base;
ushort q_addr;
ushort sg_q_addr;
uchar cur_target_qng;
ASC_QDONE_INFO scsiq_buf;
ASC_QDONE_INFO *scsiq;
int false_overrun;
iop_base = asc_dvc->iop_base;
n_q_used = 1;
scsiq = (ASC_QDONE_INFO *)&scsiq_buf;
done_q_tail = (uchar)AscGetVarDoneQTail(iop_base);
q_addr = ASC_QNO_TO_QADDR(done_q_tail);
next_qp = AscReadLramByte(iop_base,
(ushort)(q_addr + (ushort)ASC_SCSIQ_B_FWD));
if (next_qp != ASC_QLINK_END) {
AscPutVarDoneQTail(iop_base, next_qp);
q_addr = ASC_QNO_TO_QADDR(next_qp);
sg_queue_cnt = _AscCopyLramScsiDoneQ(iop_base, q_addr, scsiq,
asc_dvc->max_dma_count);
AscWriteLramByte(iop_base,
(ushort)(q_addr +
(ushort)ASC_SCSIQ_B_STATUS),
(uchar)(scsiq->
q_status & (uchar)~(QS_READY |
QS_ABORTED)));
tid_no = ASC_TIX_TO_TID(scsiq->d2.target_ix);
target_id = ASC_TIX_TO_TARGET_ID(scsiq->d2.target_ix);
if ((scsiq->cntl & QC_SG_HEAD) != 0) {
sg_q_addr = q_addr;
sg_list_qp = next_qp;
for (q_cnt = 0; q_cnt < sg_queue_cnt; q_cnt++) {
sg_list_qp = AscReadLramByte(iop_base,
(ushort)(sg_q_addr
+ (ushort)
ASC_SCSIQ_B_FWD));
sg_q_addr = ASC_QNO_TO_QADDR(sg_list_qp);
if (sg_list_qp == ASC_QLINK_END) {
AscSetLibErrorCode(asc_dvc,
ASCQ_ERR_SG_Q_LINKS);
scsiq->d3.done_stat = QD_WITH_ERROR;
scsiq->d3.host_stat =
QHSTA_D_QDONE_SG_LIST_CORRUPTED;
goto FATAL_ERR_QDONE;
}
AscWriteLramByte(iop_base,
(ushort)(sg_q_addr + (ushort)
ASC_SCSIQ_B_STATUS),
QS_FREE);
}
n_q_used = sg_queue_cnt + 1;
AscPutVarDoneQTail(iop_base, sg_list_qp);
}
if (asc_dvc->queue_full_or_busy & target_id) {
cur_target_qng = AscReadLramByte(iop_base,
(ushort)((ushort)
ASC_QADR_BEG
+ (ushort)
scsiq->d2.
target_ix));
if (cur_target_qng < asc_dvc->max_dvc_qng[tid_no]) {
scsi_busy = AscReadLramByte(iop_base, (ushort)
ASCV_SCSIBUSY_B);
scsi_busy &= ~target_id;
AscWriteLramByte(iop_base,
(ushort)ASCV_SCSIBUSY_B,
scsi_busy);
asc_dvc->queue_full_or_busy &= ~target_id;
}
}
if (asc_dvc->cur_total_qng >= n_q_used) {
asc_dvc->cur_total_qng -= n_q_used;
if (asc_dvc->cur_dvc_qng[tid_no] != 0) {
asc_dvc->cur_dvc_qng[tid_no]--;
}
} else {
AscSetLibErrorCode(asc_dvc, ASCQ_ERR_CUR_QNG);
scsiq->d3.done_stat = QD_WITH_ERROR;
goto FATAL_ERR_QDONE;
}
if ((scsiq->d2.srb_ptr == 0UL) ||
((scsiq->q_status & QS_ABORTED) != 0)) {
return (0x11);
} else if (scsiq->q_status == QS_DONE) {
false_overrun = FALSE;
if (scsiq->extra_bytes != 0) {
scsiq->remain_bytes +=
(ADV_DCNT)scsiq->extra_bytes;
}
if (scsiq->d3.done_stat == QD_WITH_ERROR) {
if (scsiq->d3.host_stat ==
QHSTA_M_DATA_OVER_RUN) {
if ((scsiq->
cntl & (QC_DATA_IN | QC_DATA_OUT))
== 0) {
scsiq->d3.done_stat =
QD_NO_ERROR;
scsiq->d3.host_stat =
QHSTA_NO_ERROR;
} else if (false_overrun) {
scsiq->d3.done_stat =
QD_NO_ERROR;
scsiq->d3.host_stat =
QHSTA_NO_ERROR;
}
} else if (scsiq->d3.host_stat ==
QHSTA_M_HUNG_REQ_SCSI_BUS_RESET) {
AscStopChip(iop_base);
AscSetChipControl(iop_base,
(uchar)(CC_SCSI_RESET
| CC_HALT));
udelay(60);
AscSetChipControl(iop_base, CC_HALT);
AscSetChipStatus(iop_base,
CIW_CLR_SCSI_RESET_INT);
AscSetChipStatus(iop_base, 0);
AscSetChipControl(iop_base, 0);
}
}
if ((scsiq->cntl & QC_NO_CALLBACK) == 0) {
asc_isr_callback(asc_dvc, scsiq);
} else {
if ((AscReadLramByte(iop_base,
(ushort)(q_addr + (ushort)
ASC_SCSIQ_CDB_BEG))
== START_STOP)) {
asc_dvc->unit_not_ready &= ~target_id;
if (scsiq->d3.done_stat != QD_NO_ERROR) {
asc_dvc->start_motor &=
~target_id;
}
}
}
return (1);
} else {
AscSetLibErrorCode(asc_dvc, ASCQ_ERR_Q_STATUS);
FATAL_ERR_QDONE:
if ((scsiq->cntl & QC_NO_CALLBACK) == 0) {
asc_isr_callback(asc_dvc, scsiq);
}
return (0x80);
}
}
return (0);
}
static int AscISR(ASC_DVC_VAR *asc_dvc)
{
ASC_CS_TYPE chipstat;
PortAddr iop_base;
ushort saved_ram_addr;
uchar ctrl_reg;
uchar saved_ctrl_reg;
int int_pending;
int status;
uchar host_flag;
iop_base = asc_dvc->iop_base;
int_pending = FALSE;
if (AscIsIntPending(iop_base) == 0)
return int_pending;
if ((asc_dvc->init_state & ASC_INIT_STATE_END_LOAD_MC) == 0) {
return ERR;
}
if (asc_dvc->in_critical_cnt != 0) {
AscSetLibErrorCode(asc_dvc, ASCQ_ERR_ISR_ON_CRITICAL);
return ERR;
}
if (asc_dvc->is_in_int) {
AscSetLibErrorCode(asc_dvc, ASCQ_ERR_ISR_RE_ENTRY);
return ERR;
}
asc_dvc->is_in_int = TRUE;
ctrl_reg = AscGetChipControl(iop_base);
saved_ctrl_reg = ctrl_reg & (~(CC_SCSI_RESET | CC_CHIP_RESET |
CC_SINGLE_STEP | CC_DIAG | CC_TEST));
chipstat = AscGetChipStatus(iop_base);
if (chipstat & CSW_SCSI_RESET_LATCH) {
if (!(asc_dvc->bus_type & (ASC_IS_VL | ASC_IS_EISA))) {
int i = 10;
int_pending = TRUE;
asc_dvc->sdtr_done = 0;
saved_ctrl_reg &= (uchar)(~CC_HALT);
while ((AscGetChipStatus(iop_base) &
CSW_SCSI_RESET_ACTIVE) && (i-- > 0)) {
mdelay(100);
}
AscSetChipControl(iop_base, (CC_CHIP_RESET | CC_HALT));
AscSetChipControl(iop_base, CC_HALT);
AscSetChipStatus(iop_base, CIW_CLR_SCSI_RESET_INT);
AscSetChipStatus(iop_base, 0);
chipstat = AscGetChipStatus(iop_base);
}
}
saved_ram_addr = AscGetChipLramAddr(iop_base);
host_flag = AscReadLramByte(iop_base,
ASCV_HOST_FLAG_B) &
(uchar)(~ASC_HOST_FLAG_IN_ISR);
AscWriteLramByte(iop_base, ASCV_HOST_FLAG_B,
(uchar)(host_flag | (uchar)ASC_HOST_FLAG_IN_ISR));
if ((chipstat & CSW_INT_PENDING) || (int_pending)) {
AscAckInterrupt(iop_base);
int_pending = TRUE;
if ((chipstat & CSW_HALTED) && (ctrl_reg & CC_SINGLE_STEP)) {
if (AscIsrChipHalted(asc_dvc) == ERR) {
goto ISR_REPORT_QDONE_FATAL_ERROR;
} else {
saved_ctrl_reg &= (uchar)(~CC_HALT);
}
} else {
ISR_REPORT_QDONE_FATAL_ERROR:
if ((asc_dvc->dvc_cntl & ASC_CNTL_INT_MULTI_Q) != 0) {
while (((status =
AscIsrQDone(asc_dvc)) & 0x01) != 0) {
}
} else {
do {
if ((status =
AscIsrQDone(asc_dvc)) == 1) {
break;
}
} while (status == 0x11);
}
if ((status & 0x80) != 0)
int_pending = ERR;
}
}
AscWriteLramByte(iop_base, ASCV_HOST_FLAG_B, host_flag);
AscSetChipLramAddr(iop_base, saved_ram_addr);
AscSetChipControl(iop_base, saved_ctrl_reg);
asc_dvc->is_in_int = FALSE;
return int_pending;
}
static int advansys_reset(struct scsi_cmnd *scp)
{
struct Scsi_Host *shost = scp->device->host;
struct asc_board *boardp = shost_priv(shost);
unsigned long flags;
int status;
int ret = SUCCESS;
ASC_DBG(1, "0x%p\n", scp);
ASC_STATS(shost, reset);
scmd_printk(KERN_INFO, scp, "SCSI bus reset started...\n");
if (ASC_NARROW_BOARD(boardp)) {
ASC_DVC_VAR *asc_dvc = &boardp->dvc_var.asc_dvc_var;
ASC_DBG(1, "before AscInitAsc1000Driver()\n");
status = AscInitAsc1000Driver(asc_dvc);
if (asc_dvc->err_code || !asc_dvc->overrun_dma) {
scmd_printk(KERN_INFO, scp, "SCSI bus reset error: "
"0x%x, status: 0x%x\n", asc_dvc->err_code,
status);
ret = FAILED;
} else if (status) {
scmd_printk(KERN_INFO, scp, "SCSI bus reset warning: "
"0x%x\n", status);
} else {
scmd_printk(KERN_INFO, scp, "SCSI bus reset "
"successful\n");
}
ASC_DBG(1, "after AscInitAsc1000Driver()\n");
spin_lock_irqsave(shost->host_lock, flags);
} else {
ADV_DVC_VAR *adv_dvc = &boardp->dvc_var.adv_dvc_var;
ASC_DBG(1, "before AdvResetChipAndSB()\n");
switch (AdvResetChipAndSB(adv_dvc)) {
case ASC_TRUE:
scmd_printk(KERN_INFO, scp, "SCSI bus reset "
"successful\n");
break;
case ASC_FALSE:
default:
scmd_printk(KERN_INFO, scp, "SCSI bus reset error\n");
ret = FAILED;
break;
}
spin_lock_irqsave(shost->host_lock, flags);
AdvISR(adv_dvc);
}
boardp->last_reset = jiffies;
spin_unlock_irqrestore(shost->host_lock, flags);
ASC_DBG(1, "ret %d\n", ret);
return ret;
}
static int
advansys_biosparam(struct scsi_device *sdev, struct block_device *bdev,
sector_t capacity, int ip[])
{
struct asc_board *boardp = shost_priv(sdev->host);
ASC_DBG(1, "begin\n");
ASC_STATS(sdev->host, biosparam);
if (ASC_NARROW_BOARD(boardp)) {
if ((boardp->dvc_var.asc_dvc_var.dvc_cntl &
ASC_CNTL_BIOS_GT_1GB) && capacity > 0x200000) {
ip[0] = 255;
ip[1] = 63;
} else {
ip[0] = 64;
ip[1] = 32;
}
} else {
if ((boardp->dvc_var.adv_dvc_var.bios_ctrl &
BIOS_CTRL_EXTENDED_XLAT) && capacity > 0x200000) {
ip[0] = 255;
ip[1] = 63;
} else {
ip[0] = 64;
ip[1] = 32;
}
}
ip[2] = (unsigned long)capacity / (ip[0] * ip[1]);
ASC_DBG(1, "end\n");
return 0;
}
static irqreturn_t advansys_interrupt(int irq, void *dev_id)
{
struct Scsi_Host *shost = dev_id;
struct asc_board *boardp = shost_priv(shost);
irqreturn_t result = IRQ_NONE;
ASC_DBG(2, "boardp 0x%p\n", boardp);
spin_lock(shost->host_lock);
if (ASC_NARROW_BOARD(boardp)) {
if (AscIsIntPending(shost->io_port)) {
result = IRQ_HANDLED;
ASC_STATS(shost, interrupt);
ASC_DBG(1, "before AscISR()\n");
AscISR(&boardp->dvc_var.asc_dvc_var);
}
} else {
ASC_DBG(1, "before AdvISR()\n");
if (AdvISR(&boardp->dvc_var.adv_dvc_var)) {
result = IRQ_HANDLED;
ASC_STATS(shost, interrupt);
}
}
spin_unlock(shost->host_lock);
ASC_DBG(1, "end\n");
return result;
}
static int AscHostReqRiscHalt(PortAddr iop_base)
{
int count = 0;
int sta = 0;
uchar saved_stop_code;
if (AscIsChipHalted(iop_base))
return (1);
saved_stop_code = AscReadLramByte(iop_base, ASCV_STOP_CODE_B);
AscWriteLramByte(iop_base, ASCV_STOP_CODE_B,
ASC_STOP_HOST_REQ_RISC_HALT | ASC_STOP_REQ_RISC_STOP);
do {
if (AscIsChipHalted(iop_base)) {
sta = 1;
break;
}
mdelay(100);
} while (count++ < 20);
AscWriteLramByte(iop_base, ASCV_STOP_CODE_B, saved_stop_code);
return (sta);
}
static int
AscSetRunChipSynRegAtID(PortAddr iop_base, uchar tid_no, uchar sdtr_data)
{
int sta = FALSE;
if (AscHostReqRiscHalt(iop_base)) {
sta = AscSetChipSynRegAtID(iop_base, tid_no, sdtr_data);
AscStartChip(iop_base);
}
return sta;
}
static void AscAsyncFix(ASC_DVC_VAR *asc_dvc, struct scsi_device *sdev)
{
char type = sdev->type;
ASC_SCSI_BIT_ID_TYPE tid_bits = 1 << sdev->id;
if (!(asc_dvc->bug_fix_cntl & ASC_BUG_FIX_ASYN_USE_SYN))
return;
if (asc_dvc->init_sdtr & tid_bits)
return;
if ((type == TYPE_ROM) && (strncmp(sdev->vendor, "HP ", 3) == 0))
asc_dvc->pci_fix_asyn_xfer_always |= tid_bits;
asc_dvc->pci_fix_asyn_xfer |= tid_bits;
if ((type == TYPE_PROCESSOR) || (type == TYPE_SCANNER) ||
(type == TYPE_ROM) || (type == TYPE_TAPE))
asc_dvc->pci_fix_asyn_xfer &= ~tid_bits;
if (asc_dvc->pci_fix_asyn_xfer & tid_bits)
AscSetRunChipSynRegAtID(asc_dvc->iop_base, sdev->id,
ASYN_SDTR_DATA_FIX_PCI_REV_AB);
}
static void
advansys_narrow_slave_configure(struct scsi_device *sdev, ASC_DVC_VAR *asc_dvc)
{
ASC_SCSI_BIT_ID_TYPE tid_bit = 1 << sdev->id;
ASC_SCSI_BIT_ID_TYPE orig_use_tagged_qng = asc_dvc->use_tagged_qng;
if (sdev->lun == 0) {
ASC_SCSI_BIT_ID_TYPE orig_init_sdtr = asc_dvc->init_sdtr;
if ((asc_dvc->cfg->sdtr_enable & tid_bit) && sdev->sdtr) {
asc_dvc->init_sdtr |= tid_bit;
} else {
asc_dvc->init_sdtr &= ~tid_bit;
}
if (orig_init_sdtr != asc_dvc->init_sdtr)
AscAsyncFix(asc_dvc, sdev);
}
if (sdev->tagged_supported) {
if (asc_dvc->cfg->cmd_qng_enabled & tid_bit) {
if (sdev->lun == 0) {
asc_dvc->cfg->can_tagged_qng |= tid_bit;
asc_dvc->use_tagged_qng |= tid_bit;
}
scsi_change_queue_depth(sdev,
asc_dvc->max_dvc_qng[sdev->id]);
}
} else {
if (sdev->lun == 0) {
asc_dvc->cfg->can_tagged_qng &= ~tid_bit;
asc_dvc->use_tagged_qng &= ~tid_bit;
}
}
if ((sdev->lun == 0) &&
(orig_use_tagged_qng != asc_dvc->use_tagged_qng)) {
AscWriteLramByte(asc_dvc->iop_base, ASCV_DISC_ENABLE_B,
asc_dvc->cfg->disc_enable);
AscWriteLramByte(asc_dvc->iop_base, ASCV_USE_TAGGED_QNG_B,
asc_dvc->use_tagged_qng);
AscWriteLramByte(asc_dvc->iop_base, ASCV_CAN_TAGGED_QNG_B,
asc_dvc->cfg->can_tagged_qng);
asc_dvc->max_dvc_qng[sdev->id] =
asc_dvc->cfg->max_tag_qng[sdev->id];
AscWriteLramByte(asc_dvc->iop_base,
(ushort)(ASCV_MAX_DVC_QNG_BEG + sdev->id),
asc_dvc->max_dvc_qng[sdev->id]);
}
}
static void
advansys_wide_enable_wdtr(AdvPortAddr iop_base, unsigned short tidmask)
{
unsigned short cfg_word;
AdvReadWordLram(iop_base, ASC_MC_WDTR_ABLE, cfg_word);
if ((cfg_word & tidmask) != 0)
return;
cfg_word |= tidmask;
AdvWriteWordLram(iop_base, ASC_MC_WDTR_ABLE, cfg_word);
AdvReadWordLram(iop_base, ASC_MC_SDTR_DONE, cfg_word);
cfg_word &= ~tidmask;
AdvWriteWordLram(iop_base, ASC_MC_SDTR_DONE, cfg_word);
AdvReadWordLram(iop_base, ASC_MC_WDTR_DONE, cfg_word);
cfg_word &= ~tidmask;
AdvWriteWordLram(iop_base, ASC_MC_WDTR_DONE, cfg_word);
}
static void
advansys_wide_enable_sdtr(AdvPortAddr iop_base, unsigned short tidmask)
{
unsigned short cfg_word;
AdvReadWordLram(iop_base, ASC_MC_SDTR_ABLE, cfg_word);
if ((cfg_word & tidmask) != 0)
return;
cfg_word |= tidmask;
AdvWriteWordLram(iop_base, ASC_MC_SDTR_ABLE, cfg_word);
AdvReadWordLram(iop_base, ASC_MC_SDTR_DONE, cfg_word);
cfg_word &= ~tidmask;
AdvWriteWordLram(iop_base, ASC_MC_SDTR_DONE, cfg_word);
}
static void advansys_wide_enable_ppr(ADV_DVC_VAR *adv_dvc,
AdvPortAddr iop_base, unsigned short tidmask)
{
AdvReadWordLram(iop_base, ASC_MC_PPR_ABLE, adv_dvc->ppr_able);
adv_dvc->ppr_able |= tidmask;
AdvWriteWordLram(iop_base, ASC_MC_PPR_ABLE, adv_dvc->ppr_able);
}
static void
advansys_wide_slave_configure(struct scsi_device *sdev, ADV_DVC_VAR *adv_dvc)
{
AdvPortAddr iop_base = adv_dvc->iop_base;
unsigned short tidmask = 1 << sdev->id;
if (sdev->lun == 0) {
if ((adv_dvc->wdtr_able & tidmask) && sdev->wdtr)
advansys_wide_enable_wdtr(iop_base, tidmask);
if ((adv_dvc->sdtr_able & tidmask) && sdev->sdtr)
advansys_wide_enable_sdtr(iop_base, tidmask);
if (adv_dvc->chip_type == ADV_CHIP_ASC38C1600 && sdev->ppr)
advansys_wide_enable_ppr(adv_dvc, iop_base, tidmask);
if ((adv_dvc->tagqng_able & tidmask) &&
sdev->tagged_supported) {
unsigned short cfg_word;
AdvReadWordLram(iop_base, ASC_MC_TAGQNG_ABLE, cfg_word);
cfg_word |= tidmask;
AdvWriteWordLram(iop_base, ASC_MC_TAGQNG_ABLE,
cfg_word);
AdvWriteByteLram(iop_base,
ASC_MC_NUMBER_OF_MAX_CMD + sdev->id,
adv_dvc->max_dvc_qng);
}
}
if ((adv_dvc->tagqng_able & tidmask) && sdev->tagged_supported)
scsi_change_queue_depth(sdev, adv_dvc->max_dvc_qng);
}
static int advansys_slave_configure(struct scsi_device *sdev)
{
struct asc_board *boardp = shost_priv(sdev->host);
if (ASC_NARROW_BOARD(boardp))
advansys_narrow_slave_configure(sdev,
&boardp->dvc_var.asc_dvc_var);
else
advansys_wide_slave_configure(sdev,
&boardp->dvc_var.adv_dvc_var);
return 0;
}
static __le32 advansys_get_sense_buffer_dma(struct scsi_cmnd *scp)
{
struct asc_board *board = shost_priv(scp->device->host);
scp->SCp.dma_handle = dma_map_single(board->dev, scp->sense_buffer,
SCSI_SENSE_BUFFERSIZE, DMA_FROM_DEVICE);
dma_cache_sync(board->dev, scp->sense_buffer,
SCSI_SENSE_BUFFERSIZE, DMA_FROM_DEVICE);
return cpu_to_le32(scp->SCp.dma_handle);
}
static int asc_build_req(struct asc_board *boardp, struct scsi_cmnd *scp,
struct asc_scsi_q *asc_scsi_q)
{
struct asc_dvc_var *asc_dvc = &boardp->dvc_var.asc_dvc_var;
int use_sg;
memset(asc_scsi_q, 0, sizeof(*asc_scsi_q));
asc_scsi_q->q2.srb_ptr = advansys_ptr_to_srb(asc_dvc, scp);
if (asc_scsi_q->q2.srb_ptr == BAD_SRB) {
scp->result = HOST_BYTE(DID_SOFT_ERROR);
return ASC_ERROR;
}
asc_scsi_q->cdbptr = &scp->cmnd[0];
asc_scsi_q->q2.cdb_len = scp->cmd_len;
asc_scsi_q->q1.target_id = ASC_TID_TO_TARGET_ID(scp->device->id);
asc_scsi_q->q1.target_lun = scp->device->lun;
asc_scsi_q->q2.target_ix =
ASC_TIDLUN_TO_IX(scp->device->id, scp->device->lun);
asc_scsi_q->q1.sense_addr = advansys_get_sense_buffer_dma(scp);
asc_scsi_q->q1.sense_len = SCSI_SENSE_BUFFERSIZE;
if ((asc_dvc->cur_dvc_qng[scp->device->id] > 0) &&
(boardp->reqcnt[scp->device->id] % 255) == 0) {
asc_scsi_q->q2.tag_code = ORDERED_QUEUE_TAG;
} else {
asc_scsi_q->q2.tag_code = SIMPLE_QUEUE_TAG;
}
use_sg = scsi_dma_map(scp);
if (use_sg != 0) {
int sgcnt;
struct scatterlist *slp;
struct asc_sg_head *asc_sg_head;
if (use_sg > scp->device->host->sg_tablesize) {
scmd_printk(KERN_ERR, scp, "use_sg %d > "
"sg_tablesize %d\n", use_sg,
scp->device->host->sg_tablesize);
scsi_dma_unmap(scp);
scp->result = HOST_BYTE(DID_ERROR);
return ASC_ERROR;
}
asc_sg_head = kzalloc(sizeof(asc_scsi_q->sg_head) +
use_sg * sizeof(struct asc_sg_list), GFP_ATOMIC);
if (!asc_sg_head) {
scsi_dma_unmap(scp);
scp->result = HOST_BYTE(DID_SOFT_ERROR);
return ASC_ERROR;
}
asc_scsi_q->q1.cntl |= QC_SG_HEAD;
asc_scsi_q->sg_head = asc_sg_head;
asc_scsi_q->q1.data_cnt = 0;
asc_scsi_q->q1.data_addr = 0;
asc_sg_head->entry_cnt = asc_scsi_q->q1.sg_queue_cnt = use_sg;
ASC_STATS_ADD(scp->device->host, xfer_elem,
asc_sg_head->entry_cnt);
scsi_for_each_sg(scp, slp, use_sg, sgcnt) {
asc_sg_head->sg_list[sgcnt].addr =
cpu_to_le32(sg_dma_address(slp));
asc_sg_head->sg_list[sgcnt].bytes =
cpu_to_le32(sg_dma_len(slp));
ASC_STATS_ADD(scp->device->host, xfer_sect,
DIV_ROUND_UP(sg_dma_len(slp), 512));
}
}
ASC_STATS(scp->device->host, xfer_cnt);
ASC_DBG_PRT_ASC_SCSI_Q(2, asc_scsi_q);
ASC_DBG_PRT_CDB(1, scp->cmnd, scp->cmd_len);
return ASC_NOERROR;
}
static int
adv_get_sglist(struct asc_board *boardp, adv_req_t *reqp, struct scsi_cmnd *scp,
int use_sg)
{
adv_sgblk_t *sgblkp;
ADV_SCSI_REQ_Q *scsiqp;
struct scatterlist *slp;
int sg_elem_cnt;
ADV_SG_BLOCK *sg_block, *prev_sg_block;
ADV_PADDR sg_block_paddr;
int i;
scsiqp = (ADV_SCSI_REQ_Q *)ADV_32BALIGN(&reqp->scsi_req_q);
slp = scsi_sglist(scp);
sg_elem_cnt = use_sg;
prev_sg_block = NULL;
reqp->sgblkp = NULL;
for (;;) {
if ((sgblkp = boardp->adv_sgblkp) == NULL) {
ASC_DBG(1, "no free adv_sgblk_t\n");
ASC_STATS(scp->device->host, adv_build_nosg);
while ((sgblkp = reqp->sgblkp) != NULL) {
reqp->sgblkp = sgblkp->next_sgblkp;
sgblkp->next_sgblkp = boardp->adv_sgblkp;
boardp->adv_sgblkp = sgblkp;
}
return ASC_BUSY;
}
boardp->adv_sgblkp = sgblkp->next_sgblkp;
sgblkp->next_sgblkp = NULL;
sg_block = (ADV_SG_BLOCK *)ADV_8BALIGN(&sgblkp->sg_block);
sg_block_paddr = virt_to_bus(sg_block);
if (reqp->sgblkp == NULL) {
reqp->sgblkp = sgblkp;
scsiqp->sg_list_ptr = sg_block;
scsiqp->sg_real_addr = cpu_to_le32(sg_block_paddr);
} else {
sgblkp->next_sgblkp = reqp->sgblkp;
reqp->sgblkp = sgblkp;
prev_sg_block->sg_ptr = cpu_to_le32(sg_block_paddr);
}
for (i = 0; i < NO_OF_SG_PER_BLOCK; i++) {
sg_block->sg_list[i].sg_addr =
cpu_to_le32(sg_dma_address(slp));
sg_block->sg_list[i].sg_count =
cpu_to_le32(sg_dma_len(slp));
ASC_STATS_ADD(scp->device->host, xfer_sect,
DIV_ROUND_UP(sg_dma_len(slp), 512));
if (--sg_elem_cnt == 0) {
sg_block->sg_cnt = i + 1;
sg_block->sg_ptr = 0L;
return ADV_SUCCESS;
}
slp++;
}
sg_block->sg_cnt = NO_OF_SG_PER_BLOCK;
prev_sg_block = sg_block;
}
}
static int
adv_build_req(struct asc_board *boardp, struct scsi_cmnd *scp,
ADV_SCSI_REQ_Q **adv_scsiqpp)
{
adv_req_t *reqp;
ADV_SCSI_REQ_Q *scsiqp;
int i;
int ret;
int use_sg;
if (boardp->adv_reqp == NULL) {
ASC_DBG(1, "no free adv_req_t\n");
ASC_STATS(scp->device->host, adv_build_noreq);
return ASC_BUSY;
} else {
reqp = boardp->adv_reqp;
boardp->adv_reqp = reqp->next_reqp;
reqp->next_reqp = NULL;
}
scsiqp = (ADV_SCSI_REQ_Q *)ADV_32BALIGN(&reqp->scsi_req_q);
scsiqp->cntl = scsiqp->scsi_cntl = scsiqp->done_status = 0;
scsiqp->srb_ptr = ADV_VADDR_TO_U32(reqp);
reqp->cmndp = scp;
scsiqp->cdb_len = scp->cmd_len;
for (i = 0; i < scp->cmd_len && i < 12; i++) {
scsiqp->cdb[i] = scp->cmnd[i];
}
for (; i < scp->cmd_len; i++) {
scsiqp->cdb16[i - 12] = scp->cmnd[i];
}
scsiqp->target_id = scp->device->id;
scsiqp->target_lun = scp->device->lun;
scsiqp->sense_addr = cpu_to_le32(virt_to_bus(&scp->sense_buffer[0]));
scsiqp->sense_len = SCSI_SENSE_BUFFERSIZE;
use_sg = scsi_dma_map(scp);
if (use_sg == 0) {
reqp->sgblkp = NULL;
scsiqp->data_cnt = 0;
scsiqp->vdata_addr = NULL;
scsiqp->data_addr = 0;
scsiqp->sg_list_ptr = NULL;
scsiqp->sg_real_addr = 0;
} else {
if (use_sg > ADV_MAX_SG_LIST) {
scmd_printk(KERN_ERR, scp, "use_sg %d > "
"ADV_MAX_SG_LIST %d\n", use_sg,
scp->device->host->sg_tablesize);
scsi_dma_unmap(scp);
scp->result = HOST_BYTE(DID_ERROR);
reqp->next_reqp = boardp->adv_reqp;
boardp->adv_reqp = reqp;
return ASC_ERROR;
}
scsiqp->data_cnt = cpu_to_le32(scsi_bufflen(scp));
ret = adv_get_sglist(boardp, reqp, scp, use_sg);
if (ret != ADV_SUCCESS) {
reqp->next_reqp = boardp->adv_reqp;
boardp->adv_reqp = reqp;
return ret;
}
ASC_STATS_ADD(scp->device->host, xfer_elem, use_sg);
}
ASC_STATS(scp->device->host, xfer_cnt);
ASC_DBG_PRT_ADV_SCSI_REQ_Q(2, scsiqp);
ASC_DBG_PRT_CDB(1, scp->cmnd, scp->cmd_len);
*adv_scsiqpp = scsiqp;
return ASC_NOERROR;
}
static int AscSgListToQueue(int sg_list)
{
int n_sg_list_qs;
n_sg_list_qs = ((sg_list - 1) / ASC_SG_LIST_PER_Q);
if (((sg_list - 1) % ASC_SG_LIST_PER_Q) != 0)
n_sg_list_qs++;
return n_sg_list_qs + 1;
}
static uint
AscGetNumOfFreeQueue(ASC_DVC_VAR *asc_dvc, uchar target_ix, uchar n_qs)
{
uint cur_used_qs;
uint cur_free_qs;
ASC_SCSI_BIT_ID_TYPE target_id;
uchar tid_no;
target_id = ASC_TIX_TO_TARGET_ID(target_ix);
tid_no = ASC_TIX_TO_TID(target_ix);
if ((asc_dvc->unit_not_ready & target_id) ||
(asc_dvc->queue_full_or_busy & target_id)) {
return 0;
}
if (n_qs == 1) {
cur_used_qs = (uint) asc_dvc->cur_total_qng +
(uint) asc_dvc->last_q_shortage + (uint) ASC_MIN_FREE_Q;
} else {
cur_used_qs = (uint) asc_dvc->cur_total_qng +
(uint) ASC_MIN_FREE_Q;
}
if ((uint) (cur_used_qs + n_qs) <= (uint) asc_dvc->max_total_qng) {
cur_free_qs = (uint) asc_dvc->max_total_qng - cur_used_qs;
if (asc_dvc->cur_dvc_qng[tid_no] >=
asc_dvc->max_dvc_qng[tid_no]) {
return 0;
}
return cur_free_qs;
}
if (n_qs > 1) {
if ((n_qs > asc_dvc->last_q_shortage)
&& (n_qs <= (asc_dvc->max_total_qng - ASC_MIN_FREE_Q))) {
asc_dvc->last_q_shortage = n_qs;
}
}
return 0;
}
static uchar AscAllocFreeQueue(PortAddr iop_base, uchar free_q_head)
{
ushort q_addr;
uchar next_qp;
uchar q_status;
q_addr = ASC_QNO_TO_QADDR(free_q_head);
q_status = (uchar)AscReadLramByte(iop_base,
(ushort)(q_addr +
ASC_SCSIQ_B_STATUS));
next_qp = AscReadLramByte(iop_base, (ushort)(q_addr + ASC_SCSIQ_B_FWD));
if (((q_status & QS_READY) == 0) && (next_qp != ASC_QLINK_END))
return next_qp;
return ASC_QLINK_END;
}
static uchar
AscAllocMultipleFreeQueue(PortAddr iop_base, uchar free_q_head, uchar n_free_q)
{
uchar i;
for (i = 0; i < n_free_q; i++) {
free_q_head = AscAllocFreeQueue(iop_base, free_q_head);
if (free_q_head == ASC_QLINK_END)
break;
}
return free_q_head;
}
static void
DvcPutScsiQ(PortAddr iop_base, ushort s_addr, uchar *outbuf, int words)
{
int i;
ASC_DBG_PRT_HEX(2, "DvcPutScsiQ", outbuf, 2 * words);
AscSetChipLramAddr(iop_base, s_addr);
for (i = 0; i < 2 * words; i += 2) {
if (i == 4 || i == 20) {
continue;
}
outpw(iop_base + IOP_RAM_DATA,
((ushort)outbuf[i + 1] << 8) | outbuf[i]);
}
}
static int AscPutReadyQueue(ASC_DVC_VAR *asc_dvc, ASC_SCSI_Q *scsiq, uchar q_no)
{
ushort q_addr;
uchar tid_no;
uchar sdtr_data;
uchar syn_period_ix;
uchar syn_offset;
PortAddr iop_base;
iop_base = asc_dvc->iop_base;
if (((asc_dvc->init_sdtr & scsiq->q1.target_id) != 0) &&
((asc_dvc->sdtr_done & scsiq->q1.target_id) == 0)) {
tid_no = ASC_TIX_TO_TID(scsiq->q2.target_ix);
sdtr_data = AscGetMCodeInitSDTRAtID(iop_base, tid_no);
syn_period_ix =
(sdtr_data >> 4) & (asc_dvc->max_sdtr_index - 1);
syn_offset = sdtr_data & ASC_SYN_MAX_OFFSET;
AscMsgOutSDTR(asc_dvc,
asc_dvc->sdtr_period_tbl[syn_period_ix],
syn_offset);
scsiq->q1.cntl |= QC_MSG_OUT;
}
q_addr = ASC_QNO_TO_QADDR(q_no);
if ((scsiq->q1.target_id & asc_dvc->use_tagged_qng) == 0) {
scsiq->q2.tag_code &= ~SIMPLE_QUEUE_TAG;
}
scsiq->q1.status = QS_FREE;
AscMemWordCopyPtrToLram(iop_base,
q_addr + ASC_SCSIQ_CDB_BEG,
(uchar *)scsiq->cdbptr, scsiq->q2.cdb_len >> 1);
DvcPutScsiQ(iop_base,
q_addr + ASC_SCSIQ_CPY_BEG,
(uchar *)&scsiq->q1.cntl,
((sizeof(ASC_SCSIQ_1) + sizeof(ASC_SCSIQ_2)) / 2) - 1);
AscWriteLramWord(iop_base,
(ushort)(q_addr + (ushort)ASC_SCSIQ_B_STATUS),
(ushort)(((ushort)scsiq->q1.
q_no << 8) | (ushort)QS_READY));
return 1;
}
static int
AscPutReadySgListQueue(ASC_DVC_VAR *asc_dvc, ASC_SCSI_Q *scsiq, uchar q_no)
{
int sta;
int i;
ASC_SG_HEAD *sg_head;
ASC_SG_LIST_Q scsi_sg_q;
ASC_DCNT saved_data_addr;
ASC_DCNT saved_data_cnt;
PortAddr iop_base;
ushort sg_list_dwords;
ushort sg_index;
ushort sg_entry_cnt;
ushort q_addr;
uchar next_qp;
iop_base = asc_dvc->iop_base;
sg_head = scsiq->sg_head;
saved_data_addr = scsiq->q1.data_addr;
saved_data_cnt = scsiq->q1.data_cnt;
scsiq->q1.data_addr = (ASC_PADDR) sg_head->sg_list[0].addr;
scsiq->q1.data_cnt = (ASC_DCNT) sg_head->sg_list[0].bytes;
#if CC_VERY_LONG_SG_LIST
if (sg_head->entry_cnt > ASC_MAX_SG_LIST) {
sg_entry_cnt = ASC_MAX_SG_LIST - 1;
scsiq->remain_sg_entry_cnt =
sg_head->entry_cnt - ASC_MAX_SG_LIST;
} else {
#endif
sg_entry_cnt = sg_head->entry_cnt - 1;
#if CC_VERY_LONG_SG_LIST
}
#endif
if (sg_entry_cnt != 0) {
scsiq->q1.cntl |= QC_SG_HEAD;
q_addr = ASC_QNO_TO_QADDR(q_no);
sg_index = 1;
scsiq->q1.sg_queue_cnt = sg_head->queue_cnt;
scsi_sg_q.sg_head_qp = q_no;
scsi_sg_q.cntl = QCSG_SG_XFER_LIST;
for (i = 0; i < sg_head->queue_cnt; i++) {
scsi_sg_q.seq_no = i + 1;
if (sg_entry_cnt > ASC_SG_LIST_PER_Q) {
sg_list_dwords = (uchar)(ASC_SG_LIST_PER_Q * 2);
sg_entry_cnt -= ASC_SG_LIST_PER_Q;
if (i == 0) {
scsi_sg_q.sg_list_cnt =
ASC_SG_LIST_PER_Q;
scsi_sg_q.sg_cur_list_cnt =
ASC_SG_LIST_PER_Q;
} else {
scsi_sg_q.sg_list_cnt =
ASC_SG_LIST_PER_Q - 1;
scsi_sg_q.sg_cur_list_cnt =
ASC_SG_LIST_PER_Q - 1;
}
} else {
#if CC_VERY_LONG_SG_LIST
if (sg_head->entry_cnt > ASC_MAX_SG_LIST) {
scsi_sg_q.cntl |= QCSG_SG_XFER_MORE;
} else {
#endif
scsi_sg_q.cntl |= QCSG_SG_XFER_END;
#if CC_VERY_LONG_SG_LIST
}
#endif
sg_list_dwords = sg_entry_cnt << 1;
if (i == 0) {
scsi_sg_q.sg_list_cnt = sg_entry_cnt;
scsi_sg_q.sg_cur_list_cnt =
sg_entry_cnt;
} else {
scsi_sg_q.sg_list_cnt =
sg_entry_cnt - 1;
scsi_sg_q.sg_cur_list_cnt =
sg_entry_cnt - 1;
}
sg_entry_cnt = 0;
}
next_qp = AscReadLramByte(iop_base,
(ushort)(q_addr +
ASC_SCSIQ_B_FWD));
scsi_sg_q.q_no = next_qp;
q_addr = ASC_QNO_TO_QADDR(next_qp);
AscMemWordCopyPtrToLram(iop_base,
q_addr + ASC_SCSIQ_SGHD_CPY_BEG,
(uchar *)&scsi_sg_q,
sizeof(ASC_SG_LIST_Q) >> 1);
AscMemDWordCopyPtrToLram(iop_base,
q_addr + ASC_SGQ_LIST_BEG,
(uchar *)&sg_head->
sg_list[sg_index],
sg_list_dwords);
sg_index += ASC_SG_LIST_PER_Q;
scsiq->next_sg_index = sg_index;
}
} else {
scsiq->q1.cntl &= ~QC_SG_HEAD;
}
sta = AscPutReadyQueue(asc_dvc, scsiq, q_no);
scsiq->q1.data_addr = saved_data_addr;
scsiq->q1.data_cnt = saved_data_cnt;
return (sta);
}
static int
AscSendScsiQueue(ASC_DVC_VAR *asc_dvc, ASC_SCSI_Q *scsiq, uchar n_q_required)
{
PortAddr iop_base;
uchar free_q_head;
uchar next_qp;
uchar tid_no;
uchar target_ix;
int sta;
iop_base = asc_dvc->iop_base;
target_ix = scsiq->q2.target_ix;
tid_no = ASC_TIX_TO_TID(target_ix);
sta = 0;
free_q_head = (uchar)AscGetVarFreeQHead(iop_base);
if (n_q_required > 1) {
next_qp = AscAllocMultipleFreeQueue(iop_base, free_q_head,
(uchar)n_q_required);
if (next_qp != ASC_QLINK_END) {
asc_dvc->last_q_shortage = 0;
scsiq->sg_head->queue_cnt = n_q_required - 1;
scsiq->q1.q_no = free_q_head;
sta = AscPutReadySgListQueue(asc_dvc, scsiq,
free_q_head);
}
} else if (n_q_required == 1) {
next_qp = AscAllocFreeQueue(iop_base, free_q_head);
if (next_qp != ASC_QLINK_END) {
scsiq->q1.q_no = free_q_head;
sta = AscPutReadyQueue(asc_dvc, scsiq, free_q_head);
}
}
if (sta == 1) {
AscPutVarFreeQHead(iop_base, next_qp);
asc_dvc->cur_total_qng += n_q_required;
asc_dvc->cur_dvc_qng[tid_no]++;
}
return sta;
}
static int AscExeScsiQueue(ASC_DVC_VAR *asc_dvc, ASC_SCSI_Q *scsiq)
{
PortAddr iop_base;
int sta;
int n_q_required;
int disable_syn_offset_one_fix;
int i;
ASC_PADDR addr;
ushort sg_entry_cnt = 0;
ushort sg_entry_cnt_minus_one = 0;
uchar target_ix;
uchar tid_no;
uchar sdtr_data;
uchar extra_bytes;
uchar scsi_cmd;
uchar disable_cmd;
ASC_SG_HEAD *sg_head;
ASC_DCNT data_cnt;
iop_base = asc_dvc->iop_base;
sg_head = scsiq->sg_head;
if (asc_dvc->err_code != 0)
return (ERR);
scsiq->q1.q_no = 0;
if ((scsiq->q2.tag_code & ASC_TAG_FLAG_EXTRA_BYTES) == 0) {
scsiq->q1.extra_bytes = 0;
}
sta = 0;
target_ix = scsiq->q2.target_ix;
tid_no = ASC_TIX_TO_TID(target_ix);
n_q_required = 1;
if (scsiq->cdbptr[0] == REQUEST_SENSE) {
if ((asc_dvc->init_sdtr & scsiq->q1.target_id) != 0) {
asc_dvc->sdtr_done &= ~scsiq->q1.target_id;
sdtr_data = AscGetMCodeInitSDTRAtID(iop_base, tid_no);
AscMsgOutSDTR(asc_dvc,
asc_dvc->
sdtr_period_tbl[(sdtr_data >> 4) &
(uchar)(asc_dvc->
max_sdtr_index -
1)],
(uchar)(sdtr_data & (uchar)
ASC_SYN_MAX_OFFSET));
scsiq->q1.cntl |= (QC_MSG_OUT | QC_URGENT);
}
}
if (asc_dvc->in_critical_cnt != 0) {
AscSetLibErrorCode(asc_dvc, ASCQ_ERR_CRITICAL_RE_ENTRY);
return (ERR);
}
asc_dvc->in_critical_cnt++;
if ((scsiq->q1.cntl & QC_SG_HEAD) != 0) {
if ((sg_entry_cnt = sg_head->entry_cnt) == 0) {
asc_dvc->in_critical_cnt--;
return (ERR);
}
#if !CC_VERY_LONG_SG_LIST
if (sg_entry_cnt > ASC_MAX_SG_LIST) {
asc_dvc->in_critical_cnt--;
return (ERR);
}
#endif
if (sg_entry_cnt == 1) {
scsiq->q1.data_addr =
(ADV_PADDR)sg_head->sg_list[0].addr;
scsiq->q1.data_cnt =
(ADV_DCNT)sg_head->sg_list[0].bytes;
scsiq->q1.cntl &= ~(QC_SG_HEAD | QC_SG_SWAP_QUEUE);
}
sg_entry_cnt_minus_one = sg_entry_cnt - 1;
}
scsi_cmd = scsiq->cdbptr[0];
disable_syn_offset_one_fix = FALSE;
if ((asc_dvc->pci_fix_asyn_xfer & scsiq->q1.target_id) &&
!(asc_dvc->pci_fix_asyn_xfer_always & scsiq->q1.target_id)) {
if (scsiq->q1.cntl & QC_SG_HEAD) {
data_cnt = 0;
for (i = 0; i < sg_entry_cnt; i++) {
data_cnt +=
(ADV_DCNT)le32_to_cpu(sg_head->sg_list[i].
bytes);
}
} else {
data_cnt = le32_to_cpu(scsiq->q1.data_cnt);
}
if (data_cnt != 0UL) {
if (data_cnt < 512UL) {
disable_syn_offset_one_fix = TRUE;
} else {
for (i = 0; i < ASC_SYN_OFFSET_ONE_DISABLE_LIST;
i++) {
disable_cmd =
_syn_offset_one_disable_cmd[i];
if (disable_cmd == 0xFF) {
break;
}
if (scsi_cmd == disable_cmd) {
disable_syn_offset_one_fix =
TRUE;
break;
}
}
}
}
}
if (disable_syn_offset_one_fix) {
scsiq->q2.tag_code &= ~SIMPLE_QUEUE_TAG;
scsiq->q2.tag_code |= (ASC_TAG_FLAG_DISABLE_ASYN_USE_SYN_FIX |
ASC_TAG_FLAG_DISABLE_DISCONNECT);
} else {
scsiq->q2.tag_code &= 0x27;
}
if ((scsiq->q1.cntl & QC_SG_HEAD) != 0) {
if (asc_dvc->bug_fix_cntl) {
if (asc_dvc->bug_fix_cntl & ASC_BUG_FIX_IF_NOT_DWB) {
if ((scsi_cmd == READ_6) ||
(scsi_cmd == READ_10)) {
addr =
(ADV_PADDR)le32_to_cpu(sg_head->
sg_list
[sg_entry_cnt_minus_one].
addr) +
(ADV_DCNT)le32_to_cpu(sg_head->
sg_list
[sg_entry_cnt_minus_one].
bytes);
extra_bytes =
(uchar)((ushort)addr & 0x0003);
if ((extra_bytes != 0)
&&
((scsiq->q2.
tag_code &
ASC_TAG_FLAG_EXTRA_BYTES)
== 0)) {
scsiq->q2.tag_code |=
ASC_TAG_FLAG_EXTRA_BYTES;
scsiq->q1.extra_bytes =
extra_bytes;
data_cnt =
le32_to_cpu(sg_head->
sg_list
[sg_entry_cnt_minus_one].
bytes);
data_cnt -=
(ASC_DCNT) extra_bytes;
sg_head->
sg_list
[sg_entry_cnt_minus_one].
bytes =
cpu_to_le32(data_cnt);
}
}
}
}
sg_head->entry_to_copy = sg_head->entry_cnt;
#if CC_VERY_LONG_SG_LIST
if (sg_entry_cnt > ASC_MAX_SG_LIST) {
sg_entry_cnt = ASC_MAX_SG_LIST;
}
#endif
n_q_required = AscSgListToQueue(sg_entry_cnt);
if ((AscGetNumOfFreeQueue(asc_dvc, target_ix, n_q_required) >=
(uint) n_q_required)
|| ((scsiq->q1.cntl & QC_URGENT) != 0)) {
if ((sta =
AscSendScsiQueue(asc_dvc, scsiq,
n_q_required)) == 1) {
asc_dvc->in_critical_cnt--;
return (sta);
}
}
} else {
if (asc_dvc->bug_fix_cntl) {
if (asc_dvc->bug_fix_cntl & ASC_BUG_FIX_IF_NOT_DWB) {
if ((scsi_cmd == READ_6) ||
(scsi_cmd == READ_10)) {
addr =
le32_to_cpu(scsiq->q1.data_addr) +
le32_to_cpu(scsiq->q1.data_cnt);
extra_bytes =
(uchar)((ushort)addr & 0x0003);
if ((extra_bytes != 0)
&&
((scsiq->q2.
tag_code &
ASC_TAG_FLAG_EXTRA_BYTES)
== 0)) {
data_cnt =
le32_to_cpu(scsiq->q1.
data_cnt);
if (((ushort)data_cnt & 0x01FF)
== 0) {
scsiq->q2.tag_code |=
ASC_TAG_FLAG_EXTRA_BYTES;
data_cnt -= (ASC_DCNT)
extra_bytes;
scsiq->q1.data_cnt =
cpu_to_le32
(data_cnt);
scsiq->q1.extra_bytes =
extra_bytes;
}
}
}
}
}
n_q_required = 1;
if ((AscGetNumOfFreeQueue(asc_dvc, target_ix, 1) >= 1) ||
((scsiq->q1.cntl & QC_URGENT) != 0)) {
if ((sta = AscSendScsiQueue(asc_dvc, scsiq,
n_q_required)) == 1) {
asc_dvc->in_critical_cnt--;
return (sta);
}
}
}
asc_dvc->in_critical_cnt--;
return (sta);
}
static int AdvExeScsiQueue(ADV_DVC_VAR *asc_dvc, ADV_SCSI_REQ_Q *scsiq)
{
AdvPortAddr iop_base;
ADV_PADDR req_paddr;
ADV_CARR_T *new_carrp;
if (scsiq->target_id > ADV_MAX_TID) {
scsiq->host_status = QHSTA_M_INVALID_DEVICE;
scsiq->done_status = QD_WITH_ERROR;
return ADV_ERROR;
}
iop_base = asc_dvc->iop_base;
if ((new_carrp = asc_dvc->carr_freelist) == NULL) {
return ADV_BUSY;
}
asc_dvc->carr_freelist = (ADV_CARR_T *)
ADV_U32_TO_VADDR(le32_to_cpu(new_carrp->next_vpa));
asc_dvc->carr_pending_cnt++;
new_carrp->next_vpa = cpu_to_le32(ASC_CQ_STOPPER);
scsiq->a_flag &= ~ADV_SCSIQ_DONE;
req_paddr = virt_to_bus(scsiq);
BUG_ON(req_paddr & 31);
req_paddr = cpu_to_le32(req_paddr);
scsiq->scsiq_ptr = cpu_to_le32(ADV_VADDR_TO_U32(scsiq));
scsiq->scsiq_rptr = req_paddr;
scsiq->carr_va = cpu_to_le32(ADV_VADDR_TO_U32(asc_dvc->icq_sp));
scsiq->carr_pa = asc_dvc->icq_sp->carr_pa;
asc_dvc->icq_sp->areq_vpa = req_paddr;
asc_dvc->icq_sp->next_vpa = new_carrp->carr_pa;
asc_dvc->icq_sp = new_carrp;
if (asc_dvc->chip_type == ADV_CHIP_ASC3550 ||
asc_dvc->chip_type == ADV_CHIP_ASC38C0800) {
AdvWriteByteRegister(iop_base, IOPB_TICKLE, ADV_TICKLE_A);
if (asc_dvc->chip_type == ADV_CHIP_ASC3550) {
AdvWriteByteRegister(iop_base, IOPB_TICKLE,
ADV_TICKLE_NOP);
}
} else if (asc_dvc->chip_type == ADV_CHIP_ASC38C1600) {
AdvWriteDWordRegister(iop_base, IOPDW_COMMA,
le32_to_cpu(new_carrp->carr_pa));
}
return ADV_SUCCESS;
}
static int asc_execute_scsi_cmnd(struct scsi_cmnd *scp)
{
int ret, err_code;
struct asc_board *boardp = shost_priv(scp->device->host);
ASC_DBG(1, "scp 0x%p\n", scp);
if (ASC_NARROW_BOARD(boardp)) {
ASC_DVC_VAR *asc_dvc = &boardp->dvc_var.asc_dvc_var;
struct asc_scsi_q asc_scsi_q;
ret = asc_build_req(boardp, scp, &asc_scsi_q);
if (ret == ASC_ERROR) {
ASC_STATS(scp->device->host, build_error);
return ASC_ERROR;
}
ret = AscExeScsiQueue(asc_dvc, &asc_scsi_q);
kfree(asc_scsi_q.sg_head);
err_code = asc_dvc->err_code;
} else {
ADV_DVC_VAR *adv_dvc = &boardp->dvc_var.adv_dvc_var;
ADV_SCSI_REQ_Q *adv_scsiqp;
switch (adv_build_req(boardp, scp, &adv_scsiqp)) {
case ASC_NOERROR:
ASC_DBG(3, "adv_build_req ASC_NOERROR\n");
break;
case ASC_BUSY:
ASC_DBG(1, "adv_build_req ASC_BUSY\n");
return ASC_BUSY;
case ASC_ERROR:
default:
ASC_DBG(1, "adv_build_req ASC_ERROR\n");
ASC_STATS(scp->device->host, build_error);
return ASC_ERROR;
}
ret = AdvExeScsiQueue(adv_dvc, adv_scsiqp);
err_code = adv_dvc->err_code;
}
switch (ret) {
case ASC_NOERROR:
ASC_STATS(scp->device->host, exe_noerror);
boardp->reqcnt[scp->device->id]++;
ASC_DBG(1, "ExeScsiQueue() ASC_NOERROR\n");
break;
case ASC_BUSY:
ASC_STATS(scp->device->host, exe_busy);
break;
case ASC_ERROR:
scmd_printk(KERN_ERR, scp, "ExeScsiQueue() ASC_ERROR, "
"err_code 0x%x\n", err_code);
ASC_STATS(scp->device->host, exe_error);
scp->result = HOST_BYTE(DID_ERROR);
break;
default:
scmd_printk(KERN_ERR, scp, "ExeScsiQueue() unknown, "
"err_code 0x%x\n", err_code);
ASC_STATS(scp->device->host, exe_unknown);
scp->result = HOST_BYTE(DID_ERROR);
break;
}
ASC_DBG(1, "end\n");
return ret;
}
static int
advansys_queuecommand_lck(struct scsi_cmnd *scp, void (*done)(struct scsi_cmnd *))
{
struct Scsi_Host *shost = scp->device->host;
int asc_res, result = 0;
ASC_STATS(shost, queuecommand);
scp->scsi_done = done;
asc_res = asc_execute_scsi_cmnd(scp);
switch (asc_res) {
case ASC_NOERROR:
break;
case ASC_BUSY:
result = SCSI_MLQUEUE_HOST_BUSY;
break;
case ASC_ERROR:
default:
asc_scsi_done(scp);
break;
}
return result;
}
static unsigned short AscGetChipBiosAddress(PortAddr iop_base,
unsigned short bus_type)
{
unsigned short cfg_lsw;
unsigned short bios_addr;
if (bus_type & ASC_IS_PCI)
return 0;
if ((bus_type & ASC_IS_EISA) != 0) {
cfg_lsw = AscGetEisaChipCfg(iop_base);
cfg_lsw &= 0x000F;
bios_addr = ASC_BIOS_MIN_ADDR + cfg_lsw * ASC_BIOS_BANK_SIZE;
return bios_addr;
}
cfg_lsw = AscGetChipCfgLsw(iop_base);
if (bus_type == ASC_IS_ISAPNP)
cfg_lsw &= 0x7FFF;
bios_addr = ASC_BIOS_MIN_ADDR + (cfg_lsw >> 12) * ASC_BIOS_BANK_SIZE;
return bios_addr;
}
static uchar AscSetChipScsiID(PortAddr iop_base, uchar new_host_id)
{
ushort cfg_lsw;
if (AscGetChipScsiID(iop_base) == new_host_id) {
return (new_host_id);
}
cfg_lsw = AscGetChipCfgLsw(iop_base);
cfg_lsw &= 0xF8FF;
cfg_lsw |= (ushort)((new_host_id & ASC_MAX_TID) << 8);
AscSetChipCfgLsw(iop_base, cfg_lsw);
return (AscGetChipScsiID(iop_base));
}
static unsigned char AscGetChipScsiCtrl(PortAddr iop_base)
{
unsigned char sc;
AscSetBank(iop_base, 1);
sc = inp(iop_base + IOP_REG_SC);
AscSetBank(iop_base, 0);
return sc;
}
static unsigned char AscGetChipVersion(PortAddr iop_base,
unsigned short bus_type)
{
if (bus_type & ASC_IS_EISA) {
PortAddr eisa_iop;
unsigned char revision;
eisa_iop = (PortAddr) ASC_GET_EISA_SLOT(iop_base) |
(PortAddr) ASC_EISA_REV_IOP_MASK;
revision = inp(eisa_iop);
return ASC_CHIP_MIN_VER_EISA - 1 + revision;
}
return AscGetChipVerNo(iop_base);
}
static void AscEnableIsaDma(uchar dma_channel)
{
if (dma_channel < 4) {
outp(0x000B, (ushort)(0xC0 | dma_channel));
outp(0x000A, dma_channel);
} else if (dma_channel < 8) {
outp(0x00D6, (ushort)(0xC0 | (dma_channel - 4)));
outp(0x00D4, (ushort)(dma_channel - 4));
}
}
static int AscStopQueueExe(PortAddr iop_base)
{
int count = 0;
if (AscReadLramByte(iop_base, ASCV_STOP_CODE_B) == 0) {
AscWriteLramByte(iop_base, ASCV_STOP_CODE_B,
ASC_STOP_REQ_RISC_STOP);
do {
if (AscReadLramByte(iop_base, ASCV_STOP_CODE_B) &
ASC_STOP_ACK_RISC_STOP) {
return (1);
}
mdelay(100);
} while (count++ < 20);
}
return (0);
}
static ASC_DCNT AscGetMaxDmaCount(ushort bus_type)
{
if (bus_type & ASC_IS_ISA)
return ASC_MAX_ISA_DMA_COUNT;
else if (bus_type & (ASC_IS_EISA | ASC_IS_VL))
return ASC_MAX_VL_DMA_COUNT;
return ASC_MAX_PCI_DMA_COUNT;
}
static ushort AscGetIsaDmaChannel(PortAddr iop_base)
{
ushort channel;
channel = AscGetChipCfgLsw(iop_base) & 0x0003;
if (channel == 0x03)
return (0);
else if (channel == 0x00)
return (7);
return (channel + 4);
}
static ushort AscSetIsaDmaChannel(PortAddr iop_base, ushort dma_channel)
{
ushort cfg_lsw;
uchar value;
if ((dma_channel >= 5) && (dma_channel <= 7)) {
if (dma_channel == 7)
value = 0x00;
else
value = dma_channel - 4;
cfg_lsw = AscGetChipCfgLsw(iop_base) & 0xFFFC;
cfg_lsw |= value;
AscSetChipCfgLsw(iop_base, cfg_lsw);
return (AscGetIsaDmaChannel(iop_base));
}
return 0;
}
static uchar AscGetIsaDmaSpeed(PortAddr iop_base)
{
uchar speed_value;
AscSetBank(iop_base, 1);
speed_value = AscReadChipDmaSpeed(iop_base);
speed_value &= 0x07;
AscSetBank(iop_base, 0);
return speed_value;
}
static uchar AscSetIsaDmaSpeed(PortAddr iop_base, uchar speed_value)
{
speed_value &= 0x07;
AscSetBank(iop_base, 1);
AscWriteChipDmaSpeed(iop_base, speed_value);
AscSetBank(iop_base, 0);
return AscGetIsaDmaSpeed(iop_base);
}
static ushort AscInitAscDvcVar(ASC_DVC_VAR *asc_dvc)
{
int i;
PortAddr iop_base;
ushort warn_code;
uchar chip_version;
iop_base = asc_dvc->iop_base;
warn_code = 0;
asc_dvc->err_code = 0;
if ((asc_dvc->bus_type &
(ASC_IS_ISA | ASC_IS_PCI | ASC_IS_EISA | ASC_IS_VL)) == 0) {
asc_dvc->err_code |= ASC_IERR_NO_BUS_TYPE;
}
AscSetChipControl(iop_base, CC_HALT);
AscSetChipStatus(iop_base, 0);
asc_dvc->bug_fix_cntl = 0;
asc_dvc->pci_fix_asyn_xfer = 0;
asc_dvc->pci_fix_asyn_xfer_always = 0;
asc_dvc->sdtr_done = 0;
asc_dvc->cur_total_qng = 0;
asc_dvc->is_in_int = 0;
asc_dvc->in_critical_cnt = 0;
asc_dvc->last_q_shortage = 0;
asc_dvc->use_tagged_qng = 0;
asc_dvc->no_scam = 0;
asc_dvc->unit_not_ready = 0;
asc_dvc->queue_full_or_busy = 0;
asc_dvc->redo_scam = 0;
asc_dvc->res2 = 0;
asc_dvc->min_sdtr_index = 0;
asc_dvc->cfg->can_tagged_qng = 0;
asc_dvc->cfg->cmd_qng_enabled = 0;
asc_dvc->dvc_cntl = ASC_DEF_DVC_CNTL;
asc_dvc->init_sdtr = 0;
asc_dvc->max_total_qng = ASC_DEF_MAX_TOTAL_QNG;
asc_dvc->scsi_reset_wait = 3;
asc_dvc->start_motor = ASC_SCSI_WIDTH_BIT_SET;
asc_dvc->max_dma_count = AscGetMaxDmaCount(asc_dvc->bus_type);
asc_dvc->cfg->sdtr_enable = ASC_SCSI_WIDTH_BIT_SET;
asc_dvc->cfg->disc_enable = ASC_SCSI_WIDTH_BIT_SET;
asc_dvc->cfg->chip_scsi_id = ASC_DEF_CHIP_SCSI_ID;
chip_version = AscGetChipVersion(iop_base, asc_dvc->bus_type);
asc_dvc->cfg->chip_version = chip_version;
asc_dvc->sdtr_period_tbl = asc_syn_xfer_period;
asc_dvc->max_sdtr_index = 7;
if ((asc_dvc->bus_type & ASC_IS_PCI) &&
(chip_version >= ASC_CHIP_VER_PCI_ULTRA_3150)) {
asc_dvc->bus_type = ASC_IS_PCI_ULTRA;
asc_dvc->sdtr_period_tbl = asc_syn_ultra_xfer_period;
asc_dvc->max_sdtr_index = 15;
if (chip_version == ASC_CHIP_VER_PCI_ULTRA_3150) {
AscSetExtraControl(iop_base,
(SEC_ACTIVE_NEGATE | SEC_SLEW_RATE));
} else if (chip_version >= ASC_CHIP_VER_PCI_ULTRA_3050) {
AscSetExtraControl(iop_base,
(SEC_ACTIVE_NEGATE |
SEC_ENABLE_FILTER));
}
}
if (asc_dvc->bus_type == ASC_IS_PCI) {
AscSetExtraControl(iop_base,
(SEC_ACTIVE_NEGATE | SEC_SLEW_RATE));
}
asc_dvc->cfg->isa_dma_speed = ASC_DEF_ISA_DMA_SPEED;
#ifdef CONFIG_ISA
if ((asc_dvc->bus_type & ASC_IS_ISA) != 0) {
if (chip_version >= ASC_CHIP_MIN_VER_ISA_PNP) {
AscSetChipIFC(iop_base, IFC_INIT_DEFAULT);
asc_dvc->bus_type = ASC_IS_ISAPNP;
}
asc_dvc->cfg->isa_dma_channel =
(uchar)AscGetIsaDmaChannel(iop_base);
}
#endif
for (i = 0; i <= ASC_MAX_TID; i++) {
asc_dvc->cur_dvc_qng[i] = 0;
asc_dvc->max_dvc_qng[i] = ASC_MAX_SCSI1_QNG;
asc_dvc->scsiq_busy_head[i] = (ASC_SCSI_Q *)0L;
asc_dvc->scsiq_busy_tail[i] = (ASC_SCSI_Q *)0L;
asc_dvc->cfg->max_tag_qng[i] = ASC_MAX_INRAM_TAG_QNG;
}
return warn_code;
}
static int AscWriteEEPCmdReg(PortAddr iop_base, uchar cmd_reg)
{
int retry;
for (retry = 0; retry < ASC_EEP_MAX_RETRY; retry++) {
unsigned char read_back;
AscSetChipEEPCmd(iop_base, cmd_reg);
mdelay(1);
read_back = AscGetChipEEPCmd(iop_base);
if (read_back == cmd_reg)
return 1;
}
return 0;
}
static void AscWaitEEPRead(void)
{
mdelay(1);
}
static ushort AscReadEEPWord(PortAddr iop_base, uchar addr)
{
ushort read_wval;
uchar cmd_reg;
AscWriteEEPCmdReg(iop_base, ASC_EEP_CMD_WRITE_DISABLE);
AscWaitEEPRead();
cmd_reg = addr | ASC_EEP_CMD_READ;
AscWriteEEPCmdReg(iop_base, cmd_reg);
AscWaitEEPRead();
read_wval = AscGetChipEEPData(iop_base);
AscWaitEEPRead();
return read_wval;
}
static ushort AscGetEEPConfig(PortAddr iop_base, ASCEEP_CONFIG *cfg_buf,
ushort bus_type)
{
ushort wval;
ushort sum;
ushort *wbuf;
int cfg_beg;
int cfg_end;
int uchar_end_in_config = ASC_EEP_MAX_DVC_ADDR - 2;
int s_addr;
wbuf = (ushort *)cfg_buf;
sum = 0;
for (s_addr = 0; s_addr < 2; s_addr++, wbuf++) {
*wbuf = AscReadEEPWord(iop_base, (uchar)s_addr);
sum += *wbuf;
}
if (bus_type & ASC_IS_VL) {
cfg_beg = ASC_EEP_DVC_CFG_BEG_VL;
cfg_end = ASC_EEP_MAX_DVC_ADDR_VL;
} else {
cfg_beg = ASC_EEP_DVC_CFG_BEG;
cfg_end = ASC_EEP_MAX_DVC_ADDR;
}
for (s_addr = cfg_beg; s_addr <= (cfg_end - 1); s_addr++, wbuf++) {
wval = AscReadEEPWord(iop_base, (uchar)s_addr);
if (s_addr <= uchar_end_in_config) {
*wbuf = le16_to_cpu(wval);
} else {
*wbuf = wval;
}
sum += wval;
}
*wbuf = AscReadEEPWord(iop_base, (uchar)s_addr);
return sum;
}
static int AscTestExternalLram(ASC_DVC_VAR *asc_dvc)
{
PortAddr iop_base;
ushort q_addr;
ushort saved_word;
int sta;
iop_base = asc_dvc->iop_base;
sta = 0;
q_addr = ASC_QNO_TO_QADDR(241);
saved_word = AscReadLramWord(iop_base, q_addr);
AscSetChipLramAddr(iop_base, q_addr);
AscSetChipLramData(iop_base, 0x55AA);
mdelay(10);
AscSetChipLramAddr(iop_base, q_addr);
if (AscGetChipLramData(iop_base) == 0x55AA) {
sta = 1;
AscWriteLramWord(iop_base, q_addr, saved_word);
}
return (sta);
}
static void AscWaitEEPWrite(void)
{
mdelay(20);
}
static int AscWriteEEPDataReg(PortAddr iop_base, ushort data_reg)
{
ushort read_back;
int retry;
retry = 0;
while (TRUE) {
AscSetChipEEPData(iop_base, data_reg);
mdelay(1);
read_back = AscGetChipEEPData(iop_base);
if (read_back == data_reg) {
return (1);
}
if (retry++ > ASC_EEP_MAX_RETRY) {
return (0);
}
}
}
static ushort AscWriteEEPWord(PortAddr iop_base, uchar addr, ushort word_val)
{
ushort read_wval;
read_wval = AscReadEEPWord(iop_base, addr);
if (read_wval != word_val) {
AscWriteEEPCmdReg(iop_base, ASC_EEP_CMD_WRITE_ABLE);
AscWaitEEPRead();
AscWriteEEPDataReg(iop_base, word_val);
AscWaitEEPRead();
AscWriteEEPCmdReg(iop_base,
(uchar)((uchar)ASC_EEP_CMD_WRITE | addr));
AscWaitEEPWrite();
AscWriteEEPCmdReg(iop_base, ASC_EEP_CMD_WRITE_DISABLE);
AscWaitEEPRead();
return (AscReadEEPWord(iop_base, addr));
}
return (read_wval);
}
static int AscSetEEPConfigOnce(PortAddr iop_base, ASCEEP_CONFIG *cfg_buf,
ushort bus_type)
{
int n_error;
ushort *wbuf;
ushort word;
ushort sum;
int s_addr;
int cfg_beg;
int cfg_end;
int uchar_end_in_config = ASC_EEP_MAX_DVC_ADDR - 2;
wbuf = (ushort *)cfg_buf;
n_error = 0;
sum = 0;
for (s_addr = 0; s_addr < 2; s_addr++, wbuf++) {
sum += *wbuf;
if (*wbuf != AscWriteEEPWord(iop_base, (uchar)s_addr, *wbuf)) {
n_error++;
}
}
if (bus_type & ASC_IS_VL) {
cfg_beg = ASC_EEP_DVC_CFG_BEG_VL;
cfg_end = ASC_EEP_MAX_DVC_ADDR_VL;
} else {
cfg_beg = ASC_EEP_DVC_CFG_BEG;
cfg_end = ASC_EEP_MAX_DVC_ADDR;
}
for (s_addr = cfg_beg; s_addr <= (cfg_end - 1); s_addr++, wbuf++) {
if (s_addr <= uchar_end_in_config) {
word = cpu_to_le16(*wbuf);
if (word !=
AscWriteEEPWord(iop_base, (uchar)s_addr, word)) {
n_error++;
}
} else {
if (*wbuf !=
AscWriteEEPWord(iop_base, (uchar)s_addr, *wbuf)) {
n_error++;
}
}
sum += *wbuf;
}
*wbuf = sum;
if (sum != AscWriteEEPWord(iop_base, (uchar)s_addr, sum)) {
n_error++;
}
wbuf = (ushort *)cfg_buf;
for (s_addr = 0; s_addr < 2; s_addr++, wbuf++) {
if (*wbuf != AscReadEEPWord(iop_base, (uchar)s_addr)) {
n_error++;
}
}
if (bus_type & ASC_IS_VL) {
cfg_beg = ASC_EEP_DVC_CFG_BEG_VL;
cfg_end = ASC_EEP_MAX_DVC_ADDR_VL;
} else {
cfg_beg = ASC_EEP_DVC_CFG_BEG;
cfg_end = ASC_EEP_MAX_DVC_ADDR;
}
for (s_addr = cfg_beg; s_addr <= (cfg_end - 1); s_addr++, wbuf++) {
if (s_addr <= uchar_end_in_config) {
word =
le16_to_cpu(AscReadEEPWord
(iop_base, (uchar)s_addr));
} else {
word = AscReadEEPWord(iop_base, (uchar)s_addr);
}
if (*wbuf != word) {
n_error++;
}
}
if (AscReadEEPWord(iop_base, (uchar)s_addr) != sum) {
n_error++;
}
return n_error;
}
static int AscSetEEPConfig(PortAddr iop_base, ASCEEP_CONFIG *cfg_buf,
ushort bus_type)
{
int retry;
int n_error;
retry = 0;
while (TRUE) {
if ((n_error = AscSetEEPConfigOnce(iop_base, cfg_buf,
bus_type)) == 0) {
break;
}
if (++retry > ASC_EEP_MAX_RETRY) {
break;
}
}
return n_error;
}
static ushort AscInitFromEEP(ASC_DVC_VAR *asc_dvc)
{
ASCEEP_CONFIG eep_config_buf;
ASCEEP_CONFIG *eep_config;
PortAddr iop_base;
ushort chksum;
ushort warn_code;
ushort cfg_msw, cfg_lsw;
int i;
int write_eep = 0;
iop_base = asc_dvc->iop_base;
warn_code = 0;
AscWriteLramWord(iop_base, ASCV_HALTCODE_W, 0x00FE);
AscStopQueueExe(iop_base);
if ((AscStopChip(iop_base) == FALSE) ||
(AscGetChipScsiCtrl(iop_base) != 0)) {
asc_dvc->init_state |= ASC_INIT_RESET_SCSI_DONE;
AscResetChipAndScsiBus(asc_dvc);
mdelay(asc_dvc->scsi_reset_wait * 1000);
}
if (AscIsChipHalted(iop_base) == FALSE) {
asc_dvc->err_code |= ASC_IERR_START_STOP_CHIP;
return (warn_code);
}
AscSetPCAddr(iop_base, ASC_MCODE_START_ADDR);
if (AscGetPCAddr(iop_base) != ASC_MCODE_START_ADDR) {
asc_dvc->err_code |= ASC_IERR_SET_PC_ADDR;
return (warn_code);
}
eep_config = (ASCEEP_CONFIG *)&eep_config_buf;
cfg_msw = AscGetChipCfgMsw(iop_base);
cfg_lsw = AscGetChipCfgLsw(iop_base);
if ((cfg_msw & ASC_CFG_MSW_CLR_MASK) != 0) {
cfg_msw &= ~ASC_CFG_MSW_CLR_MASK;
warn_code |= ASC_WARN_CFG_MSW_RECOVER;
AscSetChipCfgMsw(iop_base, cfg_msw);
}
chksum = AscGetEEPConfig(iop_base, eep_config, asc_dvc->bus_type);
ASC_DBG(1, "chksum 0x%x\n", chksum);
if (chksum == 0) {
chksum = 0xaa55;
}
if (AscGetChipStatus(iop_base) & CSW_AUTO_CONFIG) {
warn_code |= ASC_WARN_AUTO_CONFIG;
if (asc_dvc->cfg->chip_version == 3) {
if (eep_config->cfg_lsw != cfg_lsw) {
warn_code |= ASC_WARN_EEPROM_RECOVER;
eep_config->cfg_lsw =
AscGetChipCfgLsw(iop_base);
}
if (eep_config->cfg_msw != cfg_msw) {
warn_code |= ASC_WARN_EEPROM_RECOVER;
eep_config->cfg_msw =
AscGetChipCfgMsw(iop_base);
}
}
}
eep_config->cfg_msw &= ~ASC_CFG_MSW_CLR_MASK;
eep_config->cfg_lsw |= ASC_CFG0_HOST_INT_ON;
ASC_DBG(1, "eep_config->chksum 0x%x\n", eep_config->chksum);
if (chksum != eep_config->chksum) {
if (AscGetChipVersion(iop_base, asc_dvc->bus_type) ==
ASC_CHIP_VER_PCI_ULTRA_3050) {
ASC_DBG(1, "chksum error ignored; EEPROM-less board\n");
eep_config->init_sdtr = 0xFF;
eep_config->disc_enable = 0xFF;
eep_config->start_motor = 0xFF;
eep_config->use_cmd_qng = 0;
eep_config->max_total_qng = 0xF0;
eep_config->max_tag_qng = 0x20;
eep_config->cntl = 0xBFFF;
ASC_EEP_SET_CHIP_ID(eep_config, 7);
eep_config->no_scam = 0;
eep_config->adapter_info[0] = 0;
eep_config->adapter_info[1] = 0;
eep_config->adapter_info[2] = 0;
eep_config->adapter_info[3] = 0;
eep_config->adapter_info[4] = 0;
eep_config->adapter_info[5] = 0xBB;
} else {
ASC_PRINT
("AscInitFromEEP: EEPROM checksum error; Will try to re-write EEPROM.\n");
write_eep = 1;
warn_code |= ASC_WARN_EEPROM_CHKSUM;
}
}
asc_dvc->cfg->sdtr_enable = eep_config->init_sdtr;
asc_dvc->cfg->disc_enable = eep_config->disc_enable;
asc_dvc->cfg->cmd_qng_enabled = eep_config->use_cmd_qng;
asc_dvc->cfg->isa_dma_speed = ASC_EEP_GET_DMA_SPD(eep_config);
asc_dvc->start_motor = eep_config->start_motor;
asc_dvc->dvc_cntl = eep_config->cntl;
asc_dvc->no_scam = eep_config->no_scam;
asc_dvc->cfg->adapter_info[0] = eep_config->adapter_info[0];
asc_dvc->cfg->adapter_info[1] = eep_config->adapter_info[1];
asc_dvc->cfg->adapter_info[2] = eep_config->adapter_info[2];
asc_dvc->cfg->adapter_info[3] = eep_config->adapter_info[3];
asc_dvc->cfg->adapter_info[4] = eep_config->adapter_info[4];
asc_dvc->cfg->adapter_info[5] = eep_config->adapter_info[5];
if (!AscTestExternalLram(asc_dvc)) {
if (((asc_dvc->bus_type & ASC_IS_PCI_ULTRA) ==
ASC_IS_PCI_ULTRA)) {
eep_config->max_total_qng =
ASC_MAX_PCI_ULTRA_INRAM_TOTAL_QNG;
eep_config->max_tag_qng =
ASC_MAX_PCI_ULTRA_INRAM_TAG_QNG;
} else {
eep_config->cfg_msw |= 0x0800;
cfg_msw |= 0x0800;
AscSetChipCfgMsw(iop_base, cfg_msw);
eep_config->max_total_qng = ASC_MAX_PCI_INRAM_TOTAL_QNG;
eep_config->max_tag_qng = ASC_MAX_INRAM_TAG_QNG;
}
} else {
}
if (eep_config->max_total_qng < ASC_MIN_TOTAL_QNG) {
eep_config->max_total_qng = ASC_MIN_TOTAL_QNG;
}
if (eep_config->max_total_qng > ASC_MAX_TOTAL_QNG) {
eep_config->max_total_qng = ASC_MAX_TOTAL_QNG;
}
if (eep_config->max_tag_qng > eep_config->max_total_qng) {
eep_config->max_tag_qng = eep_config->max_total_qng;
}
if (eep_config->max_tag_qng < ASC_MIN_TAG_Q_PER_DVC) {
eep_config->max_tag_qng = ASC_MIN_TAG_Q_PER_DVC;
}
asc_dvc->max_total_qng = eep_config->max_total_qng;
if ((eep_config->use_cmd_qng & eep_config->disc_enable) !=
eep_config->use_cmd_qng) {
eep_config->disc_enable = eep_config->use_cmd_qng;
warn_code |= ASC_WARN_CMD_QNG_CONFLICT;
}
ASC_EEP_SET_CHIP_ID(eep_config,
ASC_EEP_GET_CHIP_ID(eep_config) & ASC_MAX_TID);
asc_dvc->cfg->chip_scsi_id = ASC_EEP_GET_CHIP_ID(eep_config);
if (((asc_dvc->bus_type & ASC_IS_PCI_ULTRA) == ASC_IS_PCI_ULTRA) &&
!(asc_dvc->dvc_cntl & ASC_CNTL_SDTR_ENABLE_ULTRA)) {
asc_dvc->min_sdtr_index = ASC_SDTR_ULTRA_PCI_10MB_INDEX;
}
for (i = 0; i <= ASC_MAX_TID; i++) {
asc_dvc->dos_int13_table[i] = eep_config->dos_int13_table[i];
asc_dvc->cfg->max_tag_qng[i] = eep_config->max_tag_qng;
asc_dvc->cfg->sdtr_period_offset[i] =
(uchar)(ASC_DEF_SDTR_OFFSET |
(asc_dvc->min_sdtr_index << 4));
}
eep_config->cfg_msw = AscGetChipCfgMsw(iop_base);
if (write_eep) {
if ((i = AscSetEEPConfig(iop_base, eep_config,
asc_dvc->bus_type)) != 0) {
ASC_PRINT1
("AscInitFromEEP: Failed to re-write EEPROM with %d errors.\n",
i);
} else {
ASC_PRINT
("AscInitFromEEP: Successfully re-wrote EEPROM.\n");
}
}
return (warn_code);
}
static int AscInitGetConfig(struct Scsi_Host *shost)
{
struct asc_board *board = shost_priv(shost);
ASC_DVC_VAR *asc_dvc = &board->dvc_var.asc_dvc_var;
unsigned short warn_code = 0;
asc_dvc->init_state = ASC_INIT_STATE_BEG_GET_CFG;
if (asc_dvc->err_code != 0)
return asc_dvc->err_code;
if (AscFindSignature(asc_dvc->iop_base)) {
warn_code |= AscInitAscDvcVar(asc_dvc);
warn_code |= AscInitFromEEP(asc_dvc);
asc_dvc->init_state |= ASC_INIT_STATE_END_GET_CFG;
if (asc_dvc->scsi_reset_wait > ASC_MAX_SCSI_RESET_WAIT)
asc_dvc->scsi_reset_wait = ASC_MAX_SCSI_RESET_WAIT;
} else {
asc_dvc->err_code = ASC_IERR_BAD_SIGNATURE;
}
switch (warn_code) {
case 0:
break;
case ASC_WARN_IO_PORT_ROTATE:
shost_printk(KERN_WARNING, shost, "I/O port address "
"modified\n");
break;
case ASC_WARN_AUTO_CONFIG:
shost_printk(KERN_WARNING, shost, "I/O port increment switch "
"enabled\n");
break;
case ASC_WARN_EEPROM_CHKSUM:
shost_printk(KERN_WARNING, shost, "EEPROM checksum error\n");
break;
case ASC_WARN_IRQ_MODIFIED:
shost_printk(KERN_WARNING, shost, "IRQ modified\n");
break;
case ASC_WARN_CMD_QNG_CONFLICT:
shost_printk(KERN_WARNING, shost, "tag queuing enabled w/o "
"disconnects\n");
break;
default:
shost_printk(KERN_WARNING, shost, "unknown warning: 0x%x\n",
warn_code);
break;
}
if (asc_dvc->err_code != 0)
shost_printk(KERN_ERR, shost, "error 0x%x at init_state "
"0x%x\n", asc_dvc->err_code, asc_dvc->init_state);
return asc_dvc->err_code;
}
static int AscInitSetConfig(struct pci_dev *pdev, struct Scsi_Host *shost)
{
struct asc_board *board = shost_priv(shost);
ASC_DVC_VAR *asc_dvc = &board->dvc_var.asc_dvc_var;
PortAddr iop_base = asc_dvc->iop_base;
unsigned short cfg_msw;
unsigned short warn_code = 0;
asc_dvc->init_state |= ASC_INIT_STATE_BEG_SET_CFG;
if (asc_dvc->err_code != 0)
return asc_dvc->err_code;
if (!AscFindSignature(asc_dvc->iop_base)) {
asc_dvc->err_code = ASC_IERR_BAD_SIGNATURE;
return asc_dvc->err_code;
}
cfg_msw = AscGetChipCfgMsw(iop_base);
if ((cfg_msw & ASC_CFG_MSW_CLR_MASK) != 0) {
cfg_msw &= ~ASC_CFG_MSW_CLR_MASK;
warn_code |= ASC_WARN_CFG_MSW_RECOVER;
AscSetChipCfgMsw(iop_base, cfg_msw);
}
if ((asc_dvc->cfg->cmd_qng_enabled & asc_dvc->cfg->disc_enable) !=
asc_dvc->cfg->cmd_qng_enabled) {
asc_dvc->cfg->disc_enable = asc_dvc->cfg->cmd_qng_enabled;
warn_code |= ASC_WARN_CMD_QNG_CONFLICT;
}
if (AscGetChipStatus(iop_base) & CSW_AUTO_CONFIG) {
warn_code |= ASC_WARN_AUTO_CONFIG;
}
#ifdef CONFIG_PCI
if (asc_dvc->bus_type & ASC_IS_PCI) {
cfg_msw &= 0xFFC0;
AscSetChipCfgMsw(iop_base, cfg_msw);
if ((asc_dvc->bus_type & ASC_IS_PCI_ULTRA) == ASC_IS_PCI_ULTRA) {
} else {
if ((pdev->device == PCI_DEVICE_ID_ASP_1200A) ||
(pdev->device == PCI_DEVICE_ID_ASP_ABP940)) {
asc_dvc->bug_fix_cntl |= ASC_BUG_FIX_IF_NOT_DWB;
asc_dvc->bug_fix_cntl |=
ASC_BUG_FIX_ASYN_USE_SYN;
}
}
} else
#endif
if (asc_dvc->bus_type == ASC_IS_ISAPNP) {
if (AscGetChipVersion(iop_base, asc_dvc->bus_type)
== ASC_CHIP_VER_ASYN_BUG) {
asc_dvc->bug_fix_cntl |= ASC_BUG_FIX_ASYN_USE_SYN;
}
}
if (AscSetChipScsiID(iop_base, asc_dvc->cfg->chip_scsi_id) !=
asc_dvc->cfg->chip_scsi_id) {
asc_dvc->err_code |= ASC_IERR_SET_SCSI_ID;
}
#ifdef CONFIG_ISA
if (asc_dvc->bus_type & ASC_IS_ISA) {
AscSetIsaDmaChannel(iop_base, asc_dvc->cfg->isa_dma_channel);
AscSetIsaDmaSpeed(iop_base, asc_dvc->cfg->isa_dma_speed);
}
#endif
asc_dvc->init_state |= ASC_INIT_STATE_END_SET_CFG;
switch (warn_code) {
case 0:
break;
case ASC_WARN_IO_PORT_ROTATE:
shost_printk(KERN_WARNING, shost, "I/O port address "
"modified\n");
break;
case ASC_WARN_AUTO_CONFIG:
shost_printk(KERN_WARNING, shost, "I/O port increment switch "
"enabled\n");
break;
case ASC_WARN_EEPROM_CHKSUM:
shost_printk(KERN_WARNING, shost, "EEPROM checksum error\n");
break;
case ASC_WARN_IRQ_MODIFIED:
shost_printk(KERN_WARNING, shost, "IRQ modified\n");
break;
case ASC_WARN_CMD_QNG_CONFLICT:
shost_printk(KERN_WARNING, shost, "tag queuing w/o "
"disconnects\n");
break;
default:
shost_printk(KERN_WARNING, shost, "unknown warning: 0x%x\n",
warn_code);
break;
}
if (asc_dvc->err_code != 0)
shost_printk(KERN_ERR, shost, "error 0x%x at init_state "
"0x%x\n", asc_dvc->err_code, asc_dvc->init_state);
return asc_dvc->err_code;
}
static void AdvWaitEEPCmd(AdvPortAddr iop_base)
{
int eep_delay_ms;
for (eep_delay_ms = 0; eep_delay_ms < ADV_EEP_DELAY_MS; eep_delay_ms++) {
if (AdvReadWordRegister(iop_base, IOPW_EE_CMD) &
ASC_EEP_CMD_DONE) {
break;
}
mdelay(1);
}
if ((AdvReadWordRegister(iop_base, IOPW_EE_CMD) & ASC_EEP_CMD_DONE) ==
0)
BUG();
}
static ushort AdvReadEEPWord(AdvPortAddr iop_base, int eep_word_addr)
{
AdvWriteWordRegister(iop_base, IOPW_EE_CMD,
ASC_EEP_CMD_READ | eep_word_addr);
AdvWaitEEPCmd(iop_base);
return AdvReadWordRegister(iop_base, IOPW_EE_DATA);
}
static void AdvSet3550EEPConfig(AdvPortAddr iop_base,
ADVEEP_3550_CONFIG *cfg_buf)
{
ushort *wbuf;
ushort addr, chksum;
ushort *charfields;
wbuf = (ushort *)cfg_buf;
charfields = (ushort *)&ADVEEP_3550_Config_Field_IsChar;
chksum = 0;
AdvWriteWordRegister(iop_base, IOPW_EE_CMD, ASC_EEP_CMD_WRITE_ABLE);
AdvWaitEEPCmd(iop_base);
for (addr = ADV_EEP_DVC_CFG_BEGIN;
addr < ADV_EEP_DVC_CFG_END; addr++, wbuf++) {
ushort word;
if (*charfields++) {
word = cpu_to_le16(*wbuf);
} else {
word = *wbuf;
}
chksum += *wbuf;
AdvWriteWordRegister(iop_base, IOPW_EE_DATA, word);
AdvWriteWordRegister(iop_base, IOPW_EE_CMD,
ASC_EEP_CMD_WRITE | addr);
AdvWaitEEPCmd(iop_base);
mdelay(ADV_EEP_DELAY_MS);
}
AdvWriteWordRegister(iop_base, IOPW_EE_DATA, chksum);
AdvWriteWordRegister(iop_base, IOPW_EE_CMD, ASC_EEP_CMD_WRITE | addr);
AdvWaitEEPCmd(iop_base);
wbuf++;
charfields++;
for (addr = ADV_EEP_DVC_CTL_BEGIN;
addr < ADV_EEP_MAX_WORD_ADDR; addr++, wbuf++) {
ushort word;
if (*charfields++) {
word = cpu_to_le16(*wbuf);
} else {
word = *wbuf;
}
AdvWriteWordRegister(iop_base, IOPW_EE_DATA, word);
AdvWriteWordRegister(iop_base, IOPW_EE_CMD,
ASC_EEP_CMD_WRITE | addr);
AdvWaitEEPCmd(iop_base);
}
AdvWriteWordRegister(iop_base, IOPW_EE_CMD, ASC_EEP_CMD_WRITE_DISABLE);
AdvWaitEEPCmd(iop_base);
}
static void AdvSet38C0800EEPConfig(AdvPortAddr iop_base,
ADVEEP_38C0800_CONFIG *cfg_buf)
{
ushort *wbuf;
ushort *charfields;
ushort addr, chksum;
wbuf = (ushort *)cfg_buf;
charfields = (ushort *)&ADVEEP_38C0800_Config_Field_IsChar;
chksum = 0;
AdvWriteWordRegister(iop_base, IOPW_EE_CMD, ASC_EEP_CMD_WRITE_ABLE);
AdvWaitEEPCmd(iop_base);
for (addr = ADV_EEP_DVC_CFG_BEGIN;
addr < ADV_EEP_DVC_CFG_END; addr++, wbuf++) {
ushort word;
if (*charfields++) {
word = cpu_to_le16(*wbuf);
} else {
word = *wbuf;
}
chksum += *wbuf;
AdvWriteWordRegister(iop_base, IOPW_EE_DATA, word);
AdvWriteWordRegister(iop_base, IOPW_EE_CMD,
ASC_EEP_CMD_WRITE | addr);
AdvWaitEEPCmd(iop_base);
mdelay(ADV_EEP_DELAY_MS);
}
AdvWriteWordRegister(iop_base, IOPW_EE_DATA, chksum);
AdvWriteWordRegister(iop_base, IOPW_EE_CMD, ASC_EEP_CMD_WRITE | addr);
AdvWaitEEPCmd(iop_base);
wbuf++;
charfields++;
for (addr = ADV_EEP_DVC_CTL_BEGIN;
addr < ADV_EEP_MAX_WORD_ADDR; addr++, wbuf++) {
ushort word;
if (*charfields++) {
word = cpu_to_le16(*wbuf);
} else {
word = *wbuf;
}
AdvWriteWordRegister(iop_base, IOPW_EE_DATA, word);
AdvWriteWordRegister(iop_base, IOPW_EE_CMD,
ASC_EEP_CMD_WRITE | addr);
AdvWaitEEPCmd(iop_base);
}
AdvWriteWordRegister(iop_base, IOPW_EE_CMD, ASC_EEP_CMD_WRITE_DISABLE);
AdvWaitEEPCmd(iop_base);
}
static void AdvSet38C1600EEPConfig(AdvPortAddr iop_base,
ADVEEP_38C1600_CONFIG *cfg_buf)
{
ushort *wbuf;
ushort *charfields;
ushort addr, chksum;
wbuf = (ushort *)cfg_buf;
charfields = (ushort *)&ADVEEP_38C1600_Config_Field_IsChar;
chksum = 0;
AdvWriteWordRegister(iop_base, IOPW_EE_CMD, ASC_EEP_CMD_WRITE_ABLE);
AdvWaitEEPCmd(iop_base);
for (addr = ADV_EEP_DVC_CFG_BEGIN;
addr < ADV_EEP_DVC_CFG_END; addr++, wbuf++) {
ushort word;
if (*charfields++) {
word = cpu_to_le16(*wbuf);
} else {
word = *wbuf;
}
chksum += *wbuf;
AdvWriteWordRegister(iop_base, IOPW_EE_DATA, word);
AdvWriteWordRegister(iop_base, IOPW_EE_CMD,
ASC_EEP_CMD_WRITE | addr);
AdvWaitEEPCmd(iop_base);
mdelay(ADV_EEP_DELAY_MS);
}
AdvWriteWordRegister(iop_base, IOPW_EE_DATA, chksum);
AdvWriteWordRegister(iop_base, IOPW_EE_CMD, ASC_EEP_CMD_WRITE | addr);
AdvWaitEEPCmd(iop_base);
wbuf++;
charfields++;
for (addr = ADV_EEP_DVC_CTL_BEGIN;
addr < ADV_EEP_MAX_WORD_ADDR; addr++, wbuf++) {
ushort word;
if (*charfields++) {
word = cpu_to_le16(*wbuf);
} else {
word = *wbuf;
}
AdvWriteWordRegister(iop_base, IOPW_EE_DATA, word);
AdvWriteWordRegister(iop_base, IOPW_EE_CMD,
ASC_EEP_CMD_WRITE | addr);
AdvWaitEEPCmd(iop_base);
}
AdvWriteWordRegister(iop_base, IOPW_EE_CMD, ASC_EEP_CMD_WRITE_DISABLE);
AdvWaitEEPCmd(iop_base);
}
static ushort AdvGet3550EEPConfig(AdvPortAddr iop_base,
ADVEEP_3550_CONFIG *cfg_buf)
{
ushort wval, chksum;
ushort *wbuf;
int eep_addr;
ushort *charfields;
charfields = (ushort *)&ADVEEP_3550_Config_Field_IsChar;
wbuf = (ushort *)cfg_buf;
chksum = 0;
for (eep_addr = ADV_EEP_DVC_CFG_BEGIN;
eep_addr < ADV_EEP_DVC_CFG_END; eep_addr++, wbuf++) {
wval = AdvReadEEPWord(iop_base, eep_addr);
chksum += wval;
if (*charfields++) {
*wbuf = le16_to_cpu(wval);
} else {
*wbuf = wval;
}
}
*wbuf = AdvReadEEPWord(iop_base, eep_addr);
wbuf++;
charfields++;
for (eep_addr = ADV_EEP_DVC_CTL_BEGIN;
eep_addr < ADV_EEP_MAX_WORD_ADDR; eep_addr++, wbuf++) {
*wbuf = AdvReadEEPWord(iop_base, eep_addr);
if (*charfields++) {
*wbuf = le16_to_cpu(*wbuf);
}
}
return chksum;
}
static ushort AdvGet38C0800EEPConfig(AdvPortAddr iop_base,
ADVEEP_38C0800_CONFIG *cfg_buf)
{
ushort wval, chksum;
ushort *wbuf;
int eep_addr;
ushort *charfields;
charfields = (ushort *)&ADVEEP_38C0800_Config_Field_IsChar;
wbuf = (ushort *)cfg_buf;
chksum = 0;
for (eep_addr = ADV_EEP_DVC_CFG_BEGIN;
eep_addr < ADV_EEP_DVC_CFG_END; eep_addr++, wbuf++) {
wval = AdvReadEEPWord(iop_base, eep_addr);
chksum += wval;
if (*charfields++) {
*wbuf = le16_to_cpu(wval);
} else {
*wbuf = wval;
}
}
*wbuf = AdvReadEEPWord(iop_base, eep_addr);
wbuf++;
charfields++;
for (eep_addr = ADV_EEP_DVC_CTL_BEGIN;
eep_addr < ADV_EEP_MAX_WORD_ADDR; eep_addr++, wbuf++) {
*wbuf = AdvReadEEPWord(iop_base, eep_addr);
if (*charfields++) {
*wbuf = le16_to_cpu(*wbuf);
}
}
return chksum;
}
static ushort AdvGet38C1600EEPConfig(AdvPortAddr iop_base,
ADVEEP_38C1600_CONFIG *cfg_buf)
{
ushort wval, chksum;
ushort *wbuf;
int eep_addr;
ushort *charfields;
charfields = (ushort *)&ADVEEP_38C1600_Config_Field_IsChar;
wbuf = (ushort *)cfg_buf;
chksum = 0;
for (eep_addr = ADV_EEP_DVC_CFG_BEGIN;
eep_addr < ADV_EEP_DVC_CFG_END; eep_addr++, wbuf++) {
wval = AdvReadEEPWord(iop_base, eep_addr);
chksum += wval;
if (*charfields++) {
*wbuf = le16_to_cpu(wval);
} else {
*wbuf = wval;
}
}
*wbuf = AdvReadEEPWord(iop_base, eep_addr);
wbuf++;
charfields++;
for (eep_addr = ADV_EEP_DVC_CTL_BEGIN;
eep_addr < ADV_EEP_MAX_WORD_ADDR; eep_addr++, wbuf++) {
*wbuf = AdvReadEEPWord(iop_base, eep_addr);
if (*charfields++) {
*wbuf = le16_to_cpu(*wbuf);
}
}
return chksum;
}
static int AdvInitFrom3550EEP(ADV_DVC_VAR *asc_dvc)
{
AdvPortAddr iop_base;
ushort warn_code;
ADVEEP_3550_CONFIG eep_config;
iop_base = asc_dvc->iop_base;
warn_code = 0;
if (AdvGet3550EEPConfig(iop_base, &eep_config) != eep_config.check_sum) {
warn_code |= ASC_WARN_EEPROM_CHKSUM;
memcpy(&eep_config, &Default_3550_EEPROM_Config,
sizeof(ADVEEP_3550_CONFIG));
eep_config.serial_number_word3 =
AdvReadEEPWord(iop_base, ADV_EEP_DVC_CFG_END - 1);
eep_config.serial_number_word2 =
AdvReadEEPWord(iop_base, ADV_EEP_DVC_CFG_END - 2);
eep_config.serial_number_word1 =
AdvReadEEPWord(iop_base, ADV_EEP_DVC_CFG_END - 3);
AdvSet3550EEPConfig(iop_base, &eep_config);
}
asc_dvc->wdtr_able = eep_config.wdtr_able;
asc_dvc->sdtr_able = eep_config.sdtr_able;
asc_dvc->ultra_able = eep_config.ultra_able;
asc_dvc->tagqng_able = eep_config.tagqng_able;
asc_dvc->cfg->disc_enable = eep_config.disc_enable;
asc_dvc->max_host_qng = eep_config.max_host_qng;
asc_dvc->max_dvc_qng = eep_config.max_dvc_qng;
asc_dvc->chip_scsi_id = (eep_config.adapter_scsi_id & ADV_MAX_TID);
asc_dvc->start_motor = eep_config.start_motor;
asc_dvc->scsi_reset_wait = eep_config.scsi_reset_delay;
asc_dvc->bios_ctrl = eep_config.bios_ctrl;
asc_dvc->no_scam = eep_config.scam_tolerant;
asc_dvc->cfg->serial1 = eep_config.serial_number_word1;
asc_dvc->cfg->serial2 = eep_config.serial_number_word2;
asc_dvc->cfg->serial3 = eep_config.serial_number_word3;
if (eep_config.max_host_qng > ASC_DEF_MAX_HOST_QNG) {
eep_config.max_host_qng = ASC_DEF_MAX_HOST_QNG;
} else if (eep_config.max_host_qng < ASC_DEF_MIN_HOST_QNG) {
if (eep_config.max_host_qng == 0) {
eep_config.max_host_qng = ASC_DEF_MAX_HOST_QNG;
} else {
eep_config.max_host_qng = ASC_DEF_MIN_HOST_QNG;
}
}
if (eep_config.max_dvc_qng > ASC_DEF_MAX_DVC_QNG) {
eep_config.max_dvc_qng = ASC_DEF_MAX_DVC_QNG;
} else if (eep_config.max_dvc_qng < ASC_DEF_MIN_DVC_QNG) {
if (eep_config.max_dvc_qng == 0) {
eep_config.max_dvc_qng = ASC_DEF_MAX_DVC_QNG;
} else {
eep_config.max_dvc_qng = ASC_DEF_MIN_DVC_QNG;
}
}
if (eep_config.max_dvc_qng > eep_config.max_host_qng) {
eep_config.max_dvc_qng = eep_config.max_host_qng;
}
asc_dvc->max_host_qng = eep_config.max_host_qng;
asc_dvc->max_dvc_qng = eep_config.max_dvc_qng;
if (eep_config.termination == 0) {
asc_dvc->cfg->termination = 0;
} else {
if (eep_config.termination == 1) {
asc_dvc->cfg->termination = TERM_CTL_SEL;
} else if (eep_config.termination == 2) {
asc_dvc->cfg->termination = TERM_CTL_SEL | TERM_CTL_H;
} else if (eep_config.termination == 3) {
asc_dvc->cfg->termination =
TERM_CTL_SEL | TERM_CTL_H | TERM_CTL_L;
} else {
asc_dvc->cfg->termination = 0;
warn_code |= ASC_WARN_EEPROM_TERMINATION;
}
}
return warn_code;
}
static int AdvInitFrom38C0800EEP(ADV_DVC_VAR *asc_dvc)
{
AdvPortAddr iop_base;
ushort warn_code;
ADVEEP_38C0800_CONFIG eep_config;
uchar tid, termination;
ushort sdtr_speed = 0;
iop_base = asc_dvc->iop_base;
warn_code = 0;
if (AdvGet38C0800EEPConfig(iop_base, &eep_config) !=
eep_config.check_sum) {
warn_code |= ASC_WARN_EEPROM_CHKSUM;
memcpy(&eep_config, &Default_38C0800_EEPROM_Config,
sizeof(ADVEEP_38C0800_CONFIG));
eep_config.serial_number_word3 =
AdvReadEEPWord(iop_base, ADV_EEP_DVC_CFG_END - 1);
eep_config.serial_number_word2 =
AdvReadEEPWord(iop_base, ADV_EEP_DVC_CFG_END - 2);
eep_config.serial_number_word1 =
AdvReadEEPWord(iop_base, ADV_EEP_DVC_CFG_END - 3);
AdvSet38C0800EEPConfig(iop_base, &eep_config);
}
asc_dvc->wdtr_able = eep_config.wdtr_able;
asc_dvc->sdtr_speed1 = eep_config.sdtr_speed1;
asc_dvc->sdtr_speed2 = eep_config.sdtr_speed2;
asc_dvc->sdtr_speed3 = eep_config.sdtr_speed3;
asc_dvc->sdtr_speed4 = eep_config.sdtr_speed4;
asc_dvc->tagqng_able = eep_config.tagqng_able;
asc_dvc->cfg->disc_enable = eep_config.disc_enable;
asc_dvc->max_host_qng = eep_config.max_host_qng;
asc_dvc->max_dvc_qng = eep_config.max_dvc_qng;
asc_dvc->chip_scsi_id = (eep_config.adapter_scsi_id & ADV_MAX_TID);
asc_dvc->start_motor = eep_config.start_motor;
asc_dvc->scsi_reset_wait = eep_config.scsi_reset_delay;
asc_dvc->bios_ctrl = eep_config.bios_ctrl;
asc_dvc->no_scam = eep_config.scam_tolerant;
asc_dvc->cfg->serial1 = eep_config.serial_number_word1;
asc_dvc->cfg->serial2 = eep_config.serial_number_word2;
asc_dvc->cfg->serial3 = eep_config.serial_number_word3;
asc_dvc->sdtr_able = 0;
for (tid = 0; tid <= ADV_MAX_TID; tid++) {
if (tid == 0) {
sdtr_speed = asc_dvc->sdtr_speed1;
} else if (tid == 4) {
sdtr_speed = asc_dvc->sdtr_speed2;
} else if (tid == 8) {
sdtr_speed = asc_dvc->sdtr_speed3;
} else if (tid == 12) {
sdtr_speed = asc_dvc->sdtr_speed4;
}
if (sdtr_speed & ADV_MAX_TID) {
asc_dvc->sdtr_able |= (1 << tid);
}
sdtr_speed >>= 4;
}
if (eep_config.max_host_qng > ASC_DEF_MAX_HOST_QNG) {
eep_config.max_host_qng = ASC_DEF_MAX_HOST_QNG;
} else if (eep_config.max_host_qng < ASC_DEF_MIN_HOST_QNG) {
if (eep_config.max_host_qng == 0) {
eep_config.max_host_qng = ASC_DEF_MAX_HOST_QNG;
} else {
eep_config.max_host_qng = ASC_DEF_MIN_HOST_QNG;
}
}
if (eep_config.max_dvc_qng > ASC_DEF_MAX_DVC_QNG) {
eep_config.max_dvc_qng = ASC_DEF_MAX_DVC_QNG;
} else if (eep_config.max_dvc_qng < ASC_DEF_MIN_DVC_QNG) {
if (eep_config.max_dvc_qng == 0) {
eep_config.max_dvc_qng = ASC_DEF_MAX_DVC_QNG;
} else {
eep_config.max_dvc_qng = ASC_DEF_MIN_DVC_QNG;
}
}
if (eep_config.max_dvc_qng > eep_config.max_host_qng) {
eep_config.max_dvc_qng = eep_config.max_host_qng;
}
asc_dvc->max_host_qng = eep_config.max_host_qng;
asc_dvc->max_dvc_qng = eep_config.max_dvc_qng;
if (eep_config.termination_se == 0) {
termination = 0;
} else {
if (eep_config.termination_se == 1) {
termination = 0;
} else if (eep_config.termination_se == 2) {
termination = TERM_SE_HI;
} else if (eep_config.termination_se == 3) {
termination = TERM_SE;
} else {
termination = 0;
warn_code |= ASC_WARN_EEPROM_TERMINATION;
}
}
if (eep_config.termination_lvd == 0) {
asc_dvc->cfg->termination = termination;
} else {
if (eep_config.termination_lvd == 1) {
asc_dvc->cfg->termination = termination;
} else if (eep_config.termination_lvd == 2) {
asc_dvc->cfg->termination = termination | TERM_LVD_HI;
} else if (eep_config.termination_lvd == 3) {
asc_dvc->cfg->termination = termination | TERM_LVD;
} else {
asc_dvc->cfg->termination = termination;
warn_code |= ASC_WARN_EEPROM_TERMINATION;
}
}
return warn_code;
}
static int AdvInitFrom38C1600EEP(ADV_DVC_VAR *asc_dvc)
{
AdvPortAddr iop_base;
ushort warn_code;
ADVEEP_38C1600_CONFIG eep_config;
uchar tid, termination;
ushort sdtr_speed = 0;
iop_base = asc_dvc->iop_base;
warn_code = 0;
if (AdvGet38C1600EEPConfig(iop_base, &eep_config) !=
eep_config.check_sum) {
struct pci_dev *pdev = adv_dvc_to_pdev(asc_dvc);
warn_code |= ASC_WARN_EEPROM_CHKSUM;
memcpy(&eep_config, &Default_38C1600_EEPROM_Config,
sizeof(ADVEEP_38C1600_CONFIG));
if (PCI_FUNC(pdev->devfn) != 0) {
u8 ints;
eep_config.cfg_lsw &= ~ADV_EEPROM_BIOS_ENABLE;
AdvWriteByteRegister(iop_base, IOPB_GPIO_CNTL, 0);
ints = AdvReadByteRegister(iop_base, IOPB_GPIO_DATA);
if ((ints & 0x01) == 0)
eep_config.cfg_lsw &= ~ADV_EEPROM_INTAB;
}
eep_config.serial_number_word3 =
AdvReadEEPWord(iop_base, ADV_EEP_DVC_CFG_END - 1);
eep_config.serial_number_word2 =
AdvReadEEPWord(iop_base, ADV_EEP_DVC_CFG_END - 2);
eep_config.serial_number_word1 =
AdvReadEEPWord(iop_base, ADV_EEP_DVC_CFG_END - 3);
AdvSet38C1600EEPConfig(iop_base, &eep_config);
}
asc_dvc->wdtr_able = eep_config.wdtr_able;
asc_dvc->sdtr_speed1 = eep_config.sdtr_speed1;
asc_dvc->sdtr_speed2 = eep_config.sdtr_speed2;
asc_dvc->sdtr_speed3 = eep_config.sdtr_speed3;
asc_dvc->sdtr_speed4 = eep_config.sdtr_speed4;
asc_dvc->ppr_able = 0;
asc_dvc->tagqng_able = eep_config.tagqng_able;
asc_dvc->cfg->disc_enable = eep_config.disc_enable;
asc_dvc->max_host_qng = eep_config.max_host_qng;
asc_dvc->max_dvc_qng = eep_config.max_dvc_qng;
asc_dvc->chip_scsi_id = (eep_config.adapter_scsi_id & ASC_MAX_TID);
asc_dvc->start_motor = eep_config.start_motor;
asc_dvc->scsi_reset_wait = eep_config.scsi_reset_delay;
asc_dvc->bios_ctrl = eep_config.bios_ctrl;
asc_dvc->no_scam = eep_config.scam_tolerant;
asc_dvc->sdtr_able = 0;
for (tid = 0; tid <= ASC_MAX_TID; tid++) {
if (tid == 0) {
sdtr_speed = asc_dvc->sdtr_speed1;
} else if (tid == 4) {
sdtr_speed = asc_dvc->sdtr_speed2;
} else if (tid == 8) {
sdtr_speed = asc_dvc->sdtr_speed3;
} else if (tid == 12) {
sdtr_speed = asc_dvc->sdtr_speed4;
}
if (sdtr_speed & ASC_MAX_TID) {
asc_dvc->sdtr_able |= (1 << tid);
}
sdtr_speed >>= 4;
}
if (eep_config.max_host_qng > ASC_DEF_MAX_HOST_QNG) {
eep_config.max_host_qng = ASC_DEF_MAX_HOST_QNG;
} else if (eep_config.max_host_qng < ASC_DEF_MIN_HOST_QNG) {
if (eep_config.max_host_qng == 0) {
eep_config.max_host_qng = ASC_DEF_MAX_HOST_QNG;
} else {
eep_config.max_host_qng = ASC_DEF_MIN_HOST_QNG;
}
}
if (eep_config.max_dvc_qng > ASC_DEF_MAX_DVC_QNG) {
eep_config.max_dvc_qng = ASC_DEF_MAX_DVC_QNG;
} else if (eep_config.max_dvc_qng < ASC_DEF_MIN_DVC_QNG) {
if (eep_config.max_dvc_qng == 0) {
eep_config.max_dvc_qng = ASC_DEF_MAX_DVC_QNG;
} else {
eep_config.max_dvc_qng = ASC_DEF_MIN_DVC_QNG;
}
}
if (eep_config.max_dvc_qng > eep_config.max_host_qng) {
eep_config.max_dvc_qng = eep_config.max_host_qng;
}
asc_dvc->max_host_qng = eep_config.max_host_qng;
asc_dvc->max_dvc_qng = eep_config.max_dvc_qng;
if (eep_config.termination_se == 0) {
termination = 0;
} else {
if (eep_config.termination_se == 1) {
termination = 0;
} else if (eep_config.termination_se == 2) {
termination = TERM_SE_HI;
} else if (eep_config.termination_se == 3) {
termination = TERM_SE;
} else {
termination = 0;
warn_code |= ASC_WARN_EEPROM_TERMINATION;
}
}
if (eep_config.termination_lvd == 0) {
asc_dvc->cfg->termination = termination;
} else {
if (eep_config.termination_lvd == 1) {
asc_dvc->cfg->termination = termination;
} else if (eep_config.termination_lvd == 2) {
asc_dvc->cfg->termination = termination | TERM_LVD_HI;
} else if (eep_config.termination_lvd == 3) {
asc_dvc->cfg->termination = termination | TERM_LVD;
} else {
asc_dvc->cfg->termination = termination;
warn_code |= ASC_WARN_EEPROM_TERMINATION;
}
}
return warn_code;
}
static int AdvInitGetConfig(struct pci_dev *pdev, struct Scsi_Host *shost)
{
struct asc_board *board = shost_priv(shost);
ADV_DVC_VAR *asc_dvc = &board->dvc_var.adv_dvc_var;
unsigned short warn_code = 0;
AdvPortAddr iop_base = asc_dvc->iop_base;
u16 cmd;
int status;
asc_dvc->err_code = 0;
asc_dvc->cfg->control_flag = 0;
pci_read_config_word(pdev, PCI_COMMAND, &cmd);
if ((cmd & PCI_COMMAND_PARITY) == 0)
asc_dvc->cfg->control_flag |= CONTROL_FLAG_IGNORE_PERR;
asc_dvc->cfg->chip_version =
AdvGetChipVersion(iop_base, asc_dvc->bus_type);
ASC_DBG(1, "iopb_chip_id_1: 0x%x 0x%x\n",
(ushort)AdvReadByteRegister(iop_base, IOPB_CHIP_ID_1),
(ushort)ADV_CHIP_ID_BYTE);
ASC_DBG(1, "iopw_chip_id_0: 0x%x 0x%x\n",
(ushort)AdvReadWordRegister(iop_base, IOPW_CHIP_ID_0),
(ushort)ADV_CHIP_ID_WORD);
if (AdvFindSignature(iop_base) == 0) {
asc_dvc->err_code = ASC_IERR_BAD_SIGNATURE;
return ADV_ERROR;
} else {
if (asc_dvc->chip_type != ADV_CHIP_ASC3550 &&
asc_dvc->chip_type != ADV_CHIP_ASC38C0800 &&
asc_dvc->chip_type != ADV_CHIP_ASC38C1600) {
asc_dvc->err_code |= ASC_IERR_BAD_CHIPTYPE;
return ADV_ERROR;
}
AdvWriteWordRegister(iop_base, IOPW_CTRL_REG,
ADV_CTRL_REG_CMD_RESET);
mdelay(100);
AdvWriteWordRegister(iop_base, IOPW_CTRL_REG,
ADV_CTRL_REG_CMD_WR_IO_REG);
if (asc_dvc->chip_type == ADV_CHIP_ASC38C1600) {
status = AdvInitFrom38C1600EEP(asc_dvc);
} else if (asc_dvc->chip_type == ADV_CHIP_ASC38C0800) {
status = AdvInitFrom38C0800EEP(asc_dvc);
} else {
status = AdvInitFrom3550EEP(asc_dvc);
}
warn_code |= status;
}
if (warn_code != 0)
shost_printk(KERN_WARNING, shost, "warning: 0x%x\n", warn_code);
if (asc_dvc->err_code)
shost_printk(KERN_ERR, shost, "error code 0x%x\n",
asc_dvc->err_code);
return asc_dvc->err_code;
}
static int advansys_wide_init_chip(struct Scsi_Host *shost)
{
struct asc_board *board = shost_priv(shost);
struct adv_dvc_var *adv_dvc = &board->dvc_var.adv_dvc_var;
int req_cnt = 0;
adv_req_t *reqp = NULL;
int sg_cnt = 0;
adv_sgblk_t *sgp;
int warn_code, err_code;
adv_dvc->carrier_buf = kmalloc(ADV_CARRIER_BUFSIZE, GFP_KERNEL);
ASC_DBG(1, "carrier_buf 0x%p\n", adv_dvc->carrier_buf);
if (!adv_dvc->carrier_buf)
goto kmalloc_failed;
for (req_cnt = adv_dvc->max_host_qng; req_cnt > 0; req_cnt--) {
reqp = kmalloc(sizeof(adv_req_t) * req_cnt, GFP_KERNEL);
ASC_DBG(1, "reqp 0x%p, req_cnt %d, bytes %lu\n", reqp, req_cnt,
(ulong)sizeof(adv_req_t) * req_cnt);
if (reqp)
break;
}
if (!reqp)
goto kmalloc_failed;
adv_dvc->orig_reqp = reqp;
board->adv_sgblkp = NULL;
for (sg_cnt = 0; sg_cnt < ADV_TOT_SG_BLOCK; sg_cnt++) {
sgp = kmalloc(sizeof(adv_sgblk_t), GFP_KERNEL);
if (!sgp)
break;
sgp->next_sgblkp = board->adv_sgblkp;
board->adv_sgblkp = sgp;
}
ASC_DBG(1, "sg_cnt %d * %lu = %lu bytes\n", sg_cnt, sizeof(adv_sgblk_t),
sizeof(adv_sgblk_t) * sg_cnt);
if (!board->adv_sgblkp)
goto kmalloc_failed;
req_cnt--;
reqp[req_cnt].next_reqp = NULL;
for (; req_cnt > 0; req_cnt--) {
reqp[req_cnt - 1].next_reqp = &reqp[req_cnt];
}
board->adv_reqp = &reqp[0];
if (adv_dvc->chip_type == ADV_CHIP_ASC3550) {
ASC_DBG(2, "AdvInitAsc3550Driver()\n");
warn_code = AdvInitAsc3550Driver(adv_dvc);
} else if (adv_dvc->chip_type == ADV_CHIP_ASC38C0800) {
ASC_DBG(2, "AdvInitAsc38C0800Driver()\n");
warn_code = AdvInitAsc38C0800Driver(adv_dvc);
} else {
ASC_DBG(2, "AdvInitAsc38C1600Driver()\n");
warn_code = AdvInitAsc38C1600Driver(adv_dvc);
}
err_code = adv_dvc->err_code;
if (warn_code || err_code) {
shost_printk(KERN_WARNING, shost, "error: warn 0x%x, error "
"0x%x\n", warn_code, err_code);
}
goto exit;
kmalloc_failed:
shost_printk(KERN_ERR, shost, "error: kmalloc() failed\n");
err_code = ADV_ERROR;
exit:
return err_code;
}
static void advansys_wide_free_mem(struct asc_board *board)
{
struct adv_dvc_var *adv_dvc = &board->dvc_var.adv_dvc_var;
kfree(adv_dvc->carrier_buf);
adv_dvc->carrier_buf = NULL;
kfree(adv_dvc->orig_reqp);
adv_dvc->orig_reqp = board->adv_reqp = NULL;
while (board->adv_sgblkp) {
adv_sgblk_t *sgp = board->adv_sgblkp;
board->adv_sgblkp = sgp->next_sgblkp;
kfree(sgp);
}
}
static int advansys_board_found(struct Scsi_Host *shost, unsigned int iop,
int bus_type)
{
struct pci_dev *pdev;
struct asc_board *boardp = shost_priv(shost);
ASC_DVC_VAR *asc_dvc_varp = NULL;
ADV_DVC_VAR *adv_dvc_varp = NULL;
int share_irq, warn_code, ret;
pdev = (bus_type == ASC_IS_PCI) ? to_pci_dev(boardp->dev) : NULL;
if (ASC_NARROW_BOARD(boardp)) {
ASC_DBG(1, "narrow board\n");
asc_dvc_varp = &boardp->dvc_var.asc_dvc_var;
asc_dvc_varp->bus_type = bus_type;
asc_dvc_varp->drv_ptr = boardp;
asc_dvc_varp->cfg = &boardp->dvc_cfg.asc_dvc_cfg;
asc_dvc_varp->iop_base = iop;
} else {
#ifdef CONFIG_PCI
adv_dvc_varp = &boardp->dvc_var.adv_dvc_var;
adv_dvc_varp->drv_ptr = boardp;
adv_dvc_varp->cfg = &boardp->dvc_cfg.adv_dvc_cfg;
if (pdev->device == PCI_DEVICE_ID_ASP_ABP940UW) {
ASC_DBG(1, "wide board ASC-3550\n");
adv_dvc_varp->chip_type = ADV_CHIP_ASC3550;
} else if (pdev->device == PCI_DEVICE_ID_38C0800_REV1) {
ASC_DBG(1, "wide board ASC-38C0800\n");
adv_dvc_varp->chip_type = ADV_CHIP_ASC38C0800;
} else {
ASC_DBG(1, "wide board ASC-38C1600\n");
adv_dvc_varp->chip_type = ADV_CHIP_ASC38C1600;
}
boardp->asc_n_io_port = pci_resource_len(pdev, 1);
boardp->ioremap_addr = pci_ioremap_bar(pdev, 1);
if (!boardp->ioremap_addr) {
shost_printk(KERN_ERR, shost, "ioremap(%lx, %d) "
"returned NULL\n",
(long)pci_resource_start(pdev, 1),
boardp->asc_n_io_port);
ret = -ENODEV;
goto err_shost;
}
adv_dvc_varp->iop_base = (AdvPortAddr)boardp->ioremap_addr;
ASC_DBG(1, "iop_base: 0x%p\n", adv_dvc_varp->iop_base);
boardp->ioport = iop;
ASC_DBG(1, "iopb_chip_id_1 0x%x, iopw_chip_id_0 0x%x\n",
(ushort)inp(iop + 1), (ushort)inpw(iop));
#endif
}
if (ASC_NARROW_BOARD(boardp)) {
switch (asc_dvc_varp->bus_type) {
#ifdef CONFIG_ISA
case ASC_IS_ISA:
shost->unchecked_isa_dma = TRUE;
share_irq = 0;
break;
case ASC_IS_VL:
shost->unchecked_isa_dma = FALSE;
share_irq = 0;
break;
case ASC_IS_EISA:
shost->unchecked_isa_dma = FALSE;
share_irq = IRQF_SHARED;
break;
#endif
#ifdef CONFIG_PCI
case ASC_IS_PCI:
shost->unchecked_isa_dma = FALSE;
share_irq = IRQF_SHARED;
break;
#endif
default:
shost_printk(KERN_ERR, shost, "unknown adapter type: "
"%d\n", asc_dvc_varp->bus_type);
shost->unchecked_isa_dma = TRUE;
share_irq = 0;
break;
}
ASC_DBG(2, "AscInitGetConfig()\n");
ret = AscInitGetConfig(shost) ? -ENODEV : 0;
} else {
#ifdef CONFIG_PCI
shost->unchecked_isa_dma = FALSE;
share_irq = IRQF_SHARED;
ASC_DBG(2, "AdvInitGetConfig()\n");
ret = AdvInitGetConfig(pdev, shost) ? -ENODEV : 0;
#endif
}
if (ret)
goto err_unmap;
if (ASC_NARROW_BOARD(boardp)) {
ASCEEP_CONFIG *ep;
boardp->init_tidmask |=
ADV_TID_TO_TIDMASK(asc_dvc_varp->cfg->chip_scsi_id);
ep = &boardp->eep_config.asc_eep;
ep->init_sdtr = asc_dvc_varp->cfg->sdtr_enable;
ep->disc_enable = asc_dvc_varp->cfg->disc_enable;
ep->use_cmd_qng = asc_dvc_varp->cfg->cmd_qng_enabled;
ASC_EEP_SET_DMA_SPD(ep, asc_dvc_varp->cfg->isa_dma_speed);
ep->start_motor = asc_dvc_varp->start_motor;
ep->cntl = asc_dvc_varp->dvc_cntl;
ep->no_scam = asc_dvc_varp->no_scam;
ep->max_total_qng = asc_dvc_varp->max_total_qng;
ASC_EEP_SET_CHIP_ID(ep, asc_dvc_varp->cfg->chip_scsi_id);
ep->max_tag_qng = asc_dvc_varp->cfg->max_tag_qng[0];
ep->adapter_info[0] = asc_dvc_varp->cfg->adapter_info[0];
ep->adapter_info[1] = asc_dvc_varp->cfg->adapter_info[1];
ep->adapter_info[2] = asc_dvc_varp->cfg->adapter_info[2];
ep->adapter_info[3] = asc_dvc_varp->cfg->adapter_info[3];
ep->adapter_info[4] = asc_dvc_varp->cfg->adapter_info[4];
ep->adapter_info[5] = asc_dvc_varp->cfg->adapter_info[5];
ASC_DBG(2, "AscInitSetConfig()\n");
ret = AscInitSetConfig(pdev, shost) ? -ENODEV : 0;
if (ret)
goto err_unmap;
} else {
ADVEEP_3550_CONFIG *ep_3550;
ADVEEP_38C0800_CONFIG *ep_38C0800;
ADVEEP_38C1600_CONFIG *ep_38C1600;
if (adv_dvc_varp->chip_type == ADV_CHIP_ASC3550) {
ep_3550 = &boardp->eep_config.adv_3550_eep;
ep_3550->adapter_scsi_id = adv_dvc_varp->chip_scsi_id;
ep_3550->max_host_qng = adv_dvc_varp->max_host_qng;
ep_3550->max_dvc_qng = adv_dvc_varp->max_dvc_qng;
ep_3550->termination = adv_dvc_varp->cfg->termination;
ep_3550->disc_enable = adv_dvc_varp->cfg->disc_enable;
ep_3550->bios_ctrl = adv_dvc_varp->bios_ctrl;
ep_3550->wdtr_able = adv_dvc_varp->wdtr_able;
ep_3550->sdtr_able = adv_dvc_varp->sdtr_able;
ep_3550->ultra_able = adv_dvc_varp->ultra_able;
ep_3550->tagqng_able = adv_dvc_varp->tagqng_able;
ep_3550->start_motor = adv_dvc_varp->start_motor;
ep_3550->scsi_reset_delay =
adv_dvc_varp->scsi_reset_wait;
ep_3550->serial_number_word1 =
adv_dvc_varp->cfg->serial1;
ep_3550->serial_number_word2 =
adv_dvc_varp->cfg->serial2;
ep_3550->serial_number_word3 =
adv_dvc_varp->cfg->serial3;
} else if (adv_dvc_varp->chip_type == ADV_CHIP_ASC38C0800) {
ep_38C0800 = &boardp->eep_config.adv_38C0800_eep;
ep_38C0800->adapter_scsi_id =
adv_dvc_varp->chip_scsi_id;
ep_38C0800->max_host_qng = adv_dvc_varp->max_host_qng;
ep_38C0800->max_dvc_qng = adv_dvc_varp->max_dvc_qng;
ep_38C0800->termination_lvd =
adv_dvc_varp->cfg->termination;
ep_38C0800->disc_enable =
adv_dvc_varp->cfg->disc_enable;
ep_38C0800->bios_ctrl = adv_dvc_varp->bios_ctrl;
ep_38C0800->wdtr_able = adv_dvc_varp->wdtr_able;
ep_38C0800->tagqng_able = adv_dvc_varp->tagqng_able;
ep_38C0800->sdtr_speed1 = adv_dvc_varp->sdtr_speed1;
ep_38C0800->sdtr_speed2 = adv_dvc_varp->sdtr_speed2;
ep_38C0800->sdtr_speed3 = adv_dvc_varp->sdtr_speed3;
ep_38C0800->sdtr_speed4 = adv_dvc_varp->sdtr_speed4;
ep_38C0800->tagqng_able = adv_dvc_varp->tagqng_able;
ep_38C0800->start_motor = adv_dvc_varp->start_motor;
ep_38C0800->scsi_reset_delay =
adv_dvc_varp->scsi_reset_wait;
ep_38C0800->serial_number_word1 =
adv_dvc_varp->cfg->serial1;
ep_38C0800->serial_number_word2 =
adv_dvc_varp->cfg->serial2;
ep_38C0800->serial_number_word3 =
adv_dvc_varp->cfg->serial3;
} else {
ep_38C1600 = &boardp->eep_config.adv_38C1600_eep;
ep_38C1600->adapter_scsi_id =
adv_dvc_varp->chip_scsi_id;
ep_38C1600->max_host_qng = adv_dvc_varp->max_host_qng;
ep_38C1600->max_dvc_qng = adv_dvc_varp->max_dvc_qng;
ep_38C1600->termination_lvd =
adv_dvc_varp->cfg->termination;
ep_38C1600->disc_enable =
adv_dvc_varp->cfg->disc_enable;
ep_38C1600->bios_ctrl = adv_dvc_varp->bios_ctrl;
ep_38C1600->wdtr_able = adv_dvc_varp->wdtr_able;
ep_38C1600->tagqng_able = adv_dvc_varp->tagqng_able;
ep_38C1600->sdtr_speed1 = adv_dvc_varp->sdtr_speed1;
ep_38C1600->sdtr_speed2 = adv_dvc_varp->sdtr_speed2;
ep_38C1600->sdtr_speed3 = adv_dvc_varp->sdtr_speed3;
ep_38C1600->sdtr_speed4 = adv_dvc_varp->sdtr_speed4;
ep_38C1600->tagqng_able = adv_dvc_varp->tagqng_able;
ep_38C1600->start_motor = adv_dvc_varp->start_motor;
ep_38C1600->scsi_reset_delay =
adv_dvc_varp->scsi_reset_wait;
ep_38C1600->serial_number_word1 =
adv_dvc_varp->cfg->serial1;
ep_38C1600->serial_number_word2 =
adv_dvc_varp->cfg->serial2;
ep_38C1600->serial_number_word3 =
adv_dvc_varp->cfg->serial3;
}
boardp->init_tidmask |=
ADV_TID_TO_TIDMASK(adv_dvc_varp->chip_scsi_id);
}
shost->max_channel = 0;
if (ASC_NARROW_BOARD(boardp)) {
shost->max_id = ASC_MAX_TID + 1;
shost->max_lun = ASC_MAX_LUN + 1;
shost->max_cmd_len = ASC_MAX_CDB_LEN;
shost->io_port = asc_dvc_varp->iop_base;
boardp->asc_n_io_port = ASC_IOADR_GAP;
shost->this_id = asc_dvc_varp->cfg->chip_scsi_id;
shost->can_queue = asc_dvc_varp->max_total_qng;
} else {
shost->max_id = ADV_MAX_TID + 1;
shost->max_lun = ADV_MAX_LUN + 1;
shost->max_cmd_len = ADV_MAX_CDB_LEN;
shost->io_port = iop;
shost->this_id = adv_dvc_varp->chip_scsi_id;
shost->can_queue = adv_dvc_varp->max_host_qng;
}
shost->cmd_per_lun = 1;
if (ASC_NARROW_BOARD(boardp)) {
shost->sg_tablesize =
(((asc_dvc_varp->max_total_qng - 2) / 2) *
ASC_SG_LIST_PER_Q) + 1;
} else {
shost->sg_tablesize = ADV_MAX_SG_LIST;
}
if (shost->sg_tablesize > SG_ALL) {
shost->sg_tablesize = SG_ALL;
}
ASC_DBG(1, "sg_tablesize: %d\n", shost->sg_tablesize);
if (ASC_NARROW_BOARD(boardp)) {
shost->base = AscGetChipBiosAddress(asc_dvc_varp->iop_base,
asc_dvc_varp->bus_type);
} else {
AdvReadWordLram(adv_dvc_varp->iop_base,
BIOS_SIGNATURE, boardp->bios_signature);
AdvReadWordLram(adv_dvc_varp->iop_base,
BIOS_VERSION, boardp->bios_version);
AdvReadWordLram(adv_dvc_varp->iop_base,
BIOS_CODESEG, boardp->bios_codeseg);
AdvReadWordLram(adv_dvc_varp->iop_base,
BIOS_CODELEN, boardp->bios_codelen);
ASC_DBG(1, "bios_signature 0x%x, bios_version 0x%x\n",
boardp->bios_signature, boardp->bios_version);
ASC_DBG(1, "bios_codeseg 0x%x, bios_codelen 0x%x\n",
boardp->bios_codeseg, boardp->bios_codelen);
if (boardp->bios_signature == 0x55AA) {
shost->base = ((ulong)boardp->bios_codeseg << 4);
} else {
shost->base = 0;
}
}
shost->dma_channel = NO_ISA_DMA;
#ifdef CONFIG_ISA
if (ASC_NARROW_BOARD(boardp)) {
if (asc_dvc_varp->bus_type & ASC_IS_ISA) {
shost->dma_channel = asc_dvc_varp->cfg->isa_dma_channel;
ret = request_dma(shost->dma_channel, DRV_NAME);
if (ret) {
shost_printk(KERN_ERR, shost, "request_dma() "
"%d failed %d\n",
shost->dma_channel, ret);
goto err_unmap;
}
AscEnableIsaDma(shost->dma_channel);
}
}
#endif
ASC_DBG(2, "request_irq(%d, %p)\n", boardp->irq, shost);
ret = request_irq(boardp->irq, advansys_interrupt, share_irq,
DRV_NAME, shost);
if (ret) {
if (ret == -EBUSY) {
shost_printk(KERN_ERR, shost, "request_irq(): IRQ 0x%x "
"already in use\n", boardp->irq);
} else if (ret == -EINVAL) {
shost_printk(KERN_ERR, shost, "request_irq(): IRQ 0x%x "
"not valid\n", boardp->irq);
} else {
shost_printk(KERN_ERR, shost, "request_irq(): IRQ 0x%x "
"failed with %d\n", boardp->irq, ret);
}
goto err_free_dma;
}
if (ASC_NARROW_BOARD(boardp)) {
ASC_DBG(2, "AscInitAsc1000Driver()\n");
asc_dvc_varp->overrun_buf = kzalloc(ASC_OVERRUN_BSIZE, GFP_KERNEL);
if (!asc_dvc_varp->overrun_buf) {
ret = -ENOMEM;
goto err_free_irq;
}
warn_code = AscInitAsc1000Driver(asc_dvc_varp);
if (warn_code || asc_dvc_varp->err_code) {
shost_printk(KERN_ERR, shost, "error: init_state 0x%x, "
"warn 0x%x, error 0x%x\n",
asc_dvc_varp->init_state, warn_code,
asc_dvc_varp->err_code);
if (!asc_dvc_varp->overrun_dma) {
ret = -ENODEV;
goto err_free_mem;
}
}
} else {
if (advansys_wide_init_chip(shost)) {
ret = -ENODEV;
goto err_free_mem;
}
}
ASC_DBG_PRT_SCSI_HOST(2, shost);
ret = scsi_add_host(shost, boardp->dev);
if (ret)
goto err_free_mem;
scsi_scan_host(shost);
return 0;
err_free_mem:
if (ASC_NARROW_BOARD(boardp)) {
if (asc_dvc_varp->overrun_dma)
dma_unmap_single(boardp->dev, asc_dvc_varp->overrun_dma,
ASC_OVERRUN_BSIZE, DMA_FROM_DEVICE);
kfree(asc_dvc_varp->overrun_buf);
} else
advansys_wide_free_mem(boardp);
err_free_irq:
free_irq(boardp->irq, shost);
err_free_dma:
#ifdef CONFIG_ISA
if (shost->dma_channel != NO_ISA_DMA)
free_dma(shost->dma_channel);
#endif
err_unmap:
if (boardp->ioremap_addr)
iounmap(boardp->ioremap_addr);
err_shost:
return ret;
}
static int advansys_release(struct Scsi_Host *shost)
{
struct asc_board *board = shost_priv(shost);
ASC_DBG(1, "begin\n");
scsi_remove_host(shost);
free_irq(board->irq, shost);
#ifdef CONFIG_ISA
if (shost->dma_channel != NO_ISA_DMA) {
ASC_DBG(1, "free_dma()\n");
free_dma(shost->dma_channel);
}
#endif
if (ASC_NARROW_BOARD(board)) {
dma_unmap_single(board->dev,
board->dvc_var.asc_dvc_var.overrun_dma,
ASC_OVERRUN_BSIZE, DMA_FROM_DEVICE);
kfree(board->dvc_var.asc_dvc_var.overrun_buf);
} else {
iounmap(board->ioremap_addr);
advansys_wide_free_mem(board);
}
scsi_host_put(shost);
ASC_DBG(1, "end\n");
return 0;
}
static unsigned int advansys_isa_irq_no(PortAddr iop_base)
{
unsigned short cfg_lsw = AscGetChipCfgLsw(iop_base);
unsigned int chip_irq = ((cfg_lsw >> 2) & 0x03) + 10;
if (chip_irq == 13)
chip_irq = 15;
return chip_irq;
}
static int advansys_isa_probe(struct device *dev, unsigned int id)
{
int err = -ENODEV;
PortAddr iop_base = _asc_def_iop_base[id];
struct Scsi_Host *shost;
struct asc_board *board;
if (!request_region(iop_base, ASC_IOADR_GAP, DRV_NAME)) {
ASC_DBG(1, "I/O port 0x%x busy\n", iop_base);
return -ENODEV;
}
ASC_DBG(1, "probing I/O port 0x%x\n", iop_base);
if (!AscFindSignature(iop_base))
goto release_region;
if (!(AscGetChipVersion(iop_base, ASC_IS_ISA) & ASC_CHIP_VER_ISA_BIT))
goto release_region;
err = -ENOMEM;
shost = scsi_host_alloc(&advansys_template, sizeof(*board));
if (!shost)
goto release_region;
board = shost_priv(shost);
board->irq = advansys_isa_irq_no(iop_base);
board->dev = dev;
err = advansys_board_found(shost, iop_base, ASC_IS_ISA);
if (err)
goto free_host;
dev_set_drvdata(dev, shost);
return 0;
free_host:
scsi_host_put(shost);
release_region:
release_region(iop_base, ASC_IOADR_GAP);
return err;
}
static int advansys_isa_remove(struct device *dev, unsigned int id)
{
int ioport = _asc_def_iop_base[id];
advansys_release(dev_get_drvdata(dev));
release_region(ioport, ASC_IOADR_GAP);
return 0;
}
static unsigned int advansys_vlb_irq_no(PortAddr iop_base)
{
unsigned short cfg_lsw = AscGetChipCfgLsw(iop_base);
unsigned int chip_irq = ((cfg_lsw >> 2) & 0x07) + 9;
if ((chip_irq < 10) || (chip_irq == 13) || (chip_irq > 15))
return 0;
return chip_irq;
}
static int advansys_vlb_probe(struct device *dev, unsigned int id)
{
int err = -ENODEV;
PortAddr iop_base = _asc_def_iop_base[id];
struct Scsi_Host *shost;
struct asc_board *board;
if (!request_region(iop_base, ASC_IOADR_GAP, DRV_NAME)) {
ASC_DBG(1, "I/O port 0x%x busy\n", iop_base);
return -ENODEV;
}
ASC_DBG(1, "probing I/O port 0x%x\n", iop_base);
if (!AscFindSignature(iop_base))
goto release_region;
if (AscGetChipVersion(iop_base, ASC_IS_VL) > ASC_CHIP_MAX_VER_VL)
goto release_region;
err = -ENOMEM;
shost = scsi_host_alloc(&advansys_template, sizeof(*board));
if (!shost)
goto release_region;
board = shost_priv(shost);
board->irq = advansys_vlb_irq_no(iop_base);
board->dev = dev;
err = advansys_board_found(shost, iop_base, ASC_IS_VL);
if (err)
goto free_host;
dev_set_drvdata(dev, shost);
return 0;
free_host:
scsi_host_put(shost);
release_region:
release_region(iop_base, ASC_IOADR_GAP);
return -ENODEV;
}
static unsigned int advansys_eisa_irq_no(struct eisa_device *edev)
{
unsigned short cfg_lsw = inw(edev->base_addr + 0xc86);
unsigned int chip_irq = ((cfg_lsw >> 8) & 0x07) + 10;
if ((chip_irq == 13) || (chip_irq > 15))
return 0;
return chip_irq;
}
static int advansys_eisa_probe(struct device *dev)
{
int i, ioport, irq = 0;
int err;
struct eisa_device *edev = to_eisa_device(dev);
struct eisa_scsi_data *data;
err = -ENOMEM;
data = kzalloc(sizeof(*data), GFP_KERNEL);
if (!data)
goto fail;
ioport = edev->base_addr + 0xc30;
err = -ENODEV;
for (i = 0; i < 2; i++, ioport += 0x20) {
struct asc_board *board;
struct Scsi_Host *shost;
if (!request_region(ioport, ASC_IOADR_GAP, DRV_NAME)) {
printk(KERN_WARNING "Region %x-%x busy\n", ioport,
ioport + ASC_IOADR_GAP - 1);
continue;
}
if (!AscFindSignature(ioport)) {
release_region(ioport, ASC_IOADR_GAP);
continue;
}
inw(ioport + 4);
if (!irq)
irq = advansys_eisa_irq_no(edev);
err = -ENOMEM;
shost = scsi_host_alloc(&advansys_template, sizeof(*board));
if (!shost)
goto release_region;
board = shost_priv(shost);
board->irq = irq;
board->dev = dev;
err = advansys_board_found(shost, ioport, ASC_IS_EISA);
if (!err) {
data->host[i] = shost;
continue;
}
scsi_host_put(shost);
release_region:
release_region(ioport, ASC_IOADR_GAP);
break;
}
if (err)
goto free_data;
dev_set_drvdata(dev, data);
return 0;
free_data:
kfree(data->host[0]);
kfree(data->host[1]);
kfree(data);
fail:
return err;
}
static int advansys_eisa_remove(struct device *dev)
{
int i;
struct eisa_scsi_data *data = dev_get_drvdata(dev);
for (i = 0; i < 2; i++) {
int ioport;
struct Scsi_Host *shost = data->host[i];
if (!shost)
continue;
ioport = shost->io_port;
advansys_release(shost);
release_region(ioport, ASC_IOADR_GAP);
}
kfree(data);
return 0;
}
static void advansys_set_latency(struct pci_dev *pdev)
{
if ((pdev->device == PCI_DEVICE_ID_ASP_1200A) ||
(pdev->device == PCI_DEVICE_ID_ASP_ABP940)) {
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 0);
} else {
u8 latency;
pci_read_config_byte(pdev, PCI_LATENCY_TIMER, &latency);
if (latency < 0x20)
pci_write_config_byte(pdev, PCI_LATENCY_TIMER, 0x20);
}
}
static int advansys_pci_probe(struct pci_dev *pdev,
const struct pci_device_id *ent)
{
int err, ioport;
struct Scsi_Host *shost;
struct asc_board *board;
err = pci_enable_device(pdev);
if (err)
goto fail;
err = pci_request_regions(pdev, DRV_NAME);
if (err)
goto disable_device;
pci_set_master(pdev);
advansys_set_latency(pdev);
err = -ENODEV;
if (pci_resource_len(pdev, 0) == 0)
goto release_region;
ioport = pci_resource_start(pdev, 0);
err = -ENOMEM;
shost = scsi_host_alloc(&advansys_template, sizeof(*board));
if (!shost)
goto release_region;
board = shost_priv(shost);
board->irq = pdev->irq;
board->dev = &pdev->dev;
if (pdev->device == PCI_DEVICE_ID_ASP_ABP940UW ||
pdev->device == PCI_DEVICE_ID_38C0800_REV1 ||
pdev->device == PCI_DEVICE_ID_38C1600_REV1) {
board->flags |= ASC_IS_WIDE_BOARD;
}
err = advansys_board_found(shost, ioport, ASC_IS_PCI);
if (err)
goto free_host;
pci_set_drvdata(pdev, shost);
return 0;
free_host:
scsi_host_put(shost);
release_region:
pci_release_regions(pdev);
disable_device:
pci_disable_device(pdev);
fail:
return err;
}
static void advansys_pci_remove(struct pci_dev *pdev)
{
advansys_release(pci_get_drvdata(pdev));
pci_release_regions(pdev);
pci_disable_device(pdev);
}
static int __init advansys_init(void)
{
int error;
error = isa_register_driver(&advansys_isa_driver,
ASC_IOADR_TABLE_MAX_IX);
if (error)
goto fail;
error = isa_register_driver(&advansys_vlb_driver,
ASC_IOADR_TABLE_MAX_IX);
if (error)
goto unregister_isa;
error = eisa_driver_register(&advansys_eisa_driver);
if (error)
goto unregister_vlb;
error = pci_register_driver(&advansys_pci_driver);
if (error)
goto unregister_eisa;
return 0;
unregister_eisa:
eisa_driver_unregister(&advansys_eisa_driver);
unregister_vlb:
isa_unregister_driver(&advansys_vlb_driver);
unregister_isa:
isa_unregister_driver(&advansys_isa_driver);
fail:
return error;
}
static void __exit advansys_exit(void)
{
pci_unregister_driver(&advansys_pci_driver);
eisa_driver_unregister(&advansys_eisa_driver);
isa_unregister_driver(&advansys_vlb_driver);
isa_unregister_driver(&advansys_isa_driver);
}
