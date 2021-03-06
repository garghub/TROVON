static int asd_read_ocm_seg(struct asd_ha_struct *asd_ha, void *buffer,
u32 offs, int size)
{
u8 *p = buffer;
if (unlikely(asd_ha->iospace))
asd_read_reg_string(asd_ha, buffer, offs+OCM_BASE_ADDR, size);
else {
for ( ; size > 0; size--, offs++, p++)
*p = asd_read_ocm_byte(asd_ha, offs);
}
return size;
}
static int asd_read_ocm_dir(struct asd_ha_struct *asd_ha,
struct asd_ocm_dir *dir, u32 offs)
{
int err = asd_read_ocm_seg(asd_ha, dir, offs, sizeof(*dir));
if (err) {
ASD_DPRINTK("couldn't read ocm segment\n");
return err;
}
if (dir->sig[0] != 'M' || dir->sig[1] != 'O') {
ASD_DPRINTK("no valid dir signature(%c%c) at start of OCM\n",
dir->sig[0], dir->sig[1]);
return -ENOENT;
}
if (dir->major != 0) {
asd_printk("unsupported major version of ocm dir:0x%x\n",
dir->major);
return -ENOENT;
}
dir->num_de &= 0xf;
return 0;
}
static void asd_write_ocm_seg(struct asd_ha_struct *asd_ha, void *buffer,
u32 offs, int size)
{
u8 *p = buffer;
if (unlikely(asd_ha->iospace))
asd_write_reg_string(asd_ha, buffer, offs+OCM_BASE_ADDR, size);
else {
for ( ; size > 0; size--, offs++, p++)
asd_write_ocm_byte(asd_ha, offs, *p);
}
return;
}
static int asd_find_dir_entry(struct asd_ocm_dir *dir, u8 type,
u32 *offs, u32 *size)
{
int i;
struct asd_ocm_dir_ent *ent;
for (i = 0; i < dir->num_de; i++) {
if (dir->entry[i].type == type)
break;
}
if (i >= dir->num_de)
return -ENOENT;
ent = &dir->entry[i];
*offs = (u32) THREE_TO_NUM(ent->offs);
*size = (u32) THREE_TO_NUM(ent->size);
return 0;
}
static int asd_get_bios_chim(struct asd_ha_struct *asd_ha,
struct asd_ocm_dir *dir)
{
int err;
struct asd_bios_chim_struct *bc_struct;
u32 offs, size;
err = asd_find_dir_entry(dir, OCM_BIOS_CHIM_DE, &offs, &size);
if (err) {
ASD_DPRINTK("couldn't find BIOS_CHIM dir ent\n");
goto out;
}
err = -ENOMEM;
bc_struct = kmalloc(sizeof(*bc_struct), GFP_KERNEL);
if (!bc_struct) {
asd_printk("no memory for bios_chim struct\n");
goto out;
}
err = asd_read_ocm_seg(asd_ha, (void *)bc_struct, offs,
sizeof(*bc_struct));
if (err) {
ASD_DPRINTK("couldn't read ocm segment\n");
goto out2;
}
if (strncmp(bc_struct->sig, "SOIB", 4)
&& strncmp(bc_struct->sig, "IPSA", 4)) {
ASD_DPRINTK("BIOS_CHIM entry has no valid sig(%c%c%c%c)\n",
bc_struct->sig[0], bc_struct->sig[1],
bc_struct->sig[2], bc_struct->sig[3]);
err = -ENOENT;
goto out2;
}
if (bc_struct->major != 1) {
asd_printk("BIOS_CHIM unsupported major version:0x%x\n",
bc_struct->major);
err = -ENOENT;
goto out2;
}
if (bc_struct->flags & BC_BIOS_PRESENT) {
asd_ha->hw_prof.bios.present = 1;
asd_ha->hw_prof.bios.maj = bc_struct->bios_major;
asd_ha->hw_prof.bios.min = bc_struct->bios_minor;
asd_ha->hw_prof.bios.bld = le32_to_cpu(bc_struct->bios_build);
ASD_DPRINTK("BIOS present (%d,%d), %d\n",
asd_ha->hw_prof.bios.maj,
asd_ha->hw_prof.bios.min,
asd_ha->hw_prof.bios.bld);
}
asd_ha->hw_prof.ue.num = le16_to_cpu(bc_struct->ue_num);
asd_ha->hw_prof.ue.size= le16_to_cpu(bc_struct->ue_size);
ASD_DPRINTK("ue num:%d, ue size:%d\n", asd_ha->hw_prof.ue.num,
asd_ha->hw_prof.ue.size);
size = asd_ha->hw_prof.ue.num * asd_ha->hw_prof.ue.size;
if (size > 0) {
err = -ENOMEM;
asd_ha->hw_prof.ue.area = kmalloc(size, GFP_KERNEL);
if (!asd_ha->hw_prof.ue.area)
goto out2;
err = asd_read_ocm_seg(asd_ha, (void *)asd_ha->hw_prof.ue.area,
offs + sizeof(*bc_struct), size);
if (err) {
kfree(asd_ha->hw_prof.ue.area);
asd_ha->hw_prof.ue.area = NULL;
asd_ha->hw_prof.ue.num = 0;
asd_ha->hw_prof.ue.size = 0;
ASD_DPRINTK("couldn't read ue entries(%d)\n", err);
}
}
out2:
kfree(bc_struct);
out:
return err;
}
static void
asd_hwi_initialize_ocm_dir (struct asd_ha_struct *asd_ha)
{
int i;
for (i = 0; i < OCM_MAX_SIZE; i += 4)
asd_write_ocm_dword(asd_ha, i, 0);
asd_write_ocm_seg(asd_ha, &OCMDirInit, 0,
sizeof(struct asd_ocm_dir));
for (i = 0; i < OCM_INIT_DIR_ENTRIES; i++)
asd_write_ocm_seg(asd_ha, &OCMDirEntriesInit[i],
sizeof(struct asd_ocm_dir) +
(i * sizeof(struct asd_ocm_dir_ent))
, sizeof(struct asd_ocm_dir_ent));
}
static int
asd_hwi_check_ocm_access (struct asd_ha_struct *asd_ha)
{
struct pci_dev *pcidev = asd_ha->pcidev;
u32 reg;
int err = 0;
u32 v;
reg = asd_read_reg_dword(asd_ha, EXSICNFGR);
if (!(reg & OCMINITIALIZED)) {
err = pci_read_config_dword(pcidev, PCIC_INTRPT_STAT, &v);
if (err) {
asd_printk("couldn't access PCIC_INTRPT_STAT of %s\n",
pci_name(pcidev));
goto out;
}
printk(KERN_INFO "OCM is not initialized by BIOS,"
"reinitialize it and ignore it, current IntrptStatus"
"is 0x%x\n", v);
if (v)
err = pci_write_config_dword(pcidev,
PCIC_INTRPT_STAT, v);
if (err) {
asd_printk("couldn't write PCIC_INTRPT_STAT of %s\n",
pci_name(pcidev));
goto out;
}
asd_hwi_initialize_ocm_dir(asd_ha);
}
out:
return err;
}
int asd_read_ocm(struct asd_ha_struct *asd_ha)
{
int err;
struct asd_ocm_dir *dir;
if (asd_hwi_check_ocm_access(asd_ha))
return -1;
dir = kmalloc(sizeof(*dir), GFP_KERNEL);
if (!dir) {
asd_printk("no memory for ocm dir\n");
return -ENOMEM;
}
err = asd_read_ocm_dir(asd_ha, dir, 0);
if (err)
goto out;
err = asd_get_bios_chim(asd_ha, dir);
out:
kfree(dir);
return err;
}
static int asd_poll_flash(struct asd_ha_struct *asd_ha)
{
int c;
u8 d;
for (c = 5000; c > 0; c--) {
d = asd_read_reg_byte(asd_ha, asd_ha->hw_prof.flash.bar);
d ^= asd_read_reg_byte(asd_ha, asd_ha->hw_prof.flash.bar);
if (!d)
return 0;
udelay(5);
}
return -ENOENT;
}
static int asd_reset_flash(struct asd_ha_struct *asd_ha)
{
int err;
err = asd_poll_flash(asd_ha);
if (err)
return err;
asd_write_reg_byte(asd_ha, asd_ha->hw_prof.flash.bar, FLASH_RESET);
err = asd_poll_flash(asd_ha);
return err;
}
static int asd_read_flash_seg(struct asd_ha_struct *asd_ha,
void *buffer, u32 offs, int size)
{
asd_read_reg_string(asd_ha, buffer, asd_ha->hw_prof.flash.bar+offs,
size);
return 0;
}
static int asd_find_flash_dir(struct asd_ha_struct *asd_ha,
struct asd_flash_dir *flash_dir)
{
u32 v;
for (v = 0; v < ASD_FLASH_SIZE; v += FLASH_NEXT_ENTRY_OFFS) {
asd_read_flash_seg(asd_ha, flash_dir, v,
sizeof(FLASH_DIR_COOKIE)-1);
if (memcmp(flash_dir->cookie, FLASH_DIR_COOKIE,
sizeof(FLASH_DIR_COOKIE)-1) == 0) {
asd_ha->hw_prof.flash.dir_offs = v;
asd_read_flash_seg(asd_ha, flash_dir, v,
sizeof(*flash_dir));
return 1;
}
}
return 0;
}
static int asd_flash_getid(struct asd_ha_struct *asd_ha)
{
int err = 0;
u32 reg;
reg = asd_read_reg_dword(asd_ha, EXSICNFGR);
if (pci_read_config_dword(asd_ha->pcidev, PCI_CONF_FLSH_BAR,
&asd_ha->hw_prof.flash.bar)) {
asd_printk("couldn't read PCI_CONF_FLSH_BAR of %s\n",
pci_name(asd_ha->pcidev));
return -ENOENT;
}
asd_ha->hw_prof.flash.present = 1;
asd_ha->hw_prof.flash.wide = reg & FLASHW ? 1 : 0;
err = asd_reset_flash(asd_ha);
if (err) {
ASD_DPRINTK("couldn't reset flash(%d)\n", err);
return err;
}
return 0;
}
static u16 asd_calc_flash_chksum(u16 *p, int size)
{
u16 chksum = 0;
while (size-- > 0)
chksum += *p++;
return chksum;
}
static int asd_find_flash_de(struct asd_flash_dir *flash_dir, u32 entry_type,
u32 *offs, u32 *size)
{
int i;
struct asd_flash_de *de;
for (i = 0; i < FLASH_MAX_DIR_ENTRIES; i++) {
u32 type = le32_to_cpu(flash_dir->dir_entry[i].type);
type &= FLASH_DE_TYPE_MASK;
if (type == entry_type)
break;
}
if (i >= FLASH_MAX_DIR_ENTRIES)
return -ENOENT;
de = &flash_dir->dir_entry[i];
*offs = le32_to_cpu(de->offs);
*size = le32_to_cpu(de->pad_size);
return 0;
}
static int asd_validate_ms(struct asd_manuf_sec *ms)
{
if (ms->sig[0] != 'S' || ms->sig[1] != 'M') {
ASD_DPRINTK("manuf sec: no valid sig(%c%c)\n",
ms->sig[0], ms->sig[1]);
return -ENOENT;
}
if (ms->maj != 0) {
asd_printk("unsupported manuf. sector. major version:%x\n",
ms->maj);
return -ENOENT;
}
ms->offs_next = le16_to_cpu((__force __le16) ms->offs_next);
ms->chksum = le16_to_cpu((__force __le16) ms->chksum);
ms->size = le16_to_cpu((__force __le16) ms->size);
if (asd_calc_flash_chksum((u16 *)ms, ms->size/2)) {
asd_printk("failed manuf sector checksum\n");
}
return 0;
}
static int asd_ms_get_sas_addr(struct asd_ha_struct *asd_ha,
struct asd_manuf_sec *ms)
{
memcpy(asd_ha->hw_prof.sas_addr, ms->sas_addr, SAS_ADDR_SIZE);
return 0;
}
static int asd_ms_get_pcba_sn(struct asd_ha_struct *asd_ha,
struct asd_manuf_sec *ms)
{
memcpy(asd_ha->hw_prof.pcba_sn, ms->pcba_sn, ASD_PCBA_SN_SIZE);
asd_ha->hw_prof.pcba_sn[ASD_PCBA_SN_SIZE] = '\0';
return 0;
}
static void *asd_find_ll_by_id(void * const start, const u8 id0, const u8 id1)
{
struct asd_ll_el *el = start;
do {
switch (id1) {
default:
if (el->id1 == id1)
case 0xFF:
if (el->id0 == id0)
return el;
}
el = start + le16_to_cpu(el->next);
} while (el != start);
return NULL;
}
static int asd_ms_get_phy_params(struct asd_ha_struct *asd_ha,
struct asd_manuf_sec *manuf_sec)
{
int i;
int en_phys = 0;
int rep_phys = 0;
struct asd_manuf_phy_param *phy_param;
struct asd_manuf_phy_param dflt_phy_param;
phy_param = asd_find_ll_by_id(manuf_sec, 'P', 'M');
if (!phy_param) {
ASD_DPRINTK("ms: no phy parameters found\n");
ASD_DPRINTK("ms: Creating default phy parameters\n");
dflt_phy_param.sig[0] = 'P';
dflt_phy_param.sig[1] = 'M';
dflt_phy_param.maj = 0;
dflt_phy_param.min = 2;
dflt_phy_param.num_phy_desc = 8;
dflt_phy_param.phy_desc_size = sizeof(struct asd_manuf_phy_desc);
for (i =0; i < ASD_MAX_PHYS; i++) {
dflt_phy_param.phy_desc[i].state = 0;
dflt_phy_param.phy_desc[i].phy_id = i;
dflt_phy_param.phy_desc[i].phy_control_0 = 0xf6;
dflt_phy_param.phy_desc[i].phy_control_1 = 0x10;
dflt_phy_param.phy_desc[i].phy_control_2 = 0x43;
dflt_phy_param.phy_desc[i].phy_control_3 = 0xeb;
}
phy_param = &dflt_phy_param;
}
if (phy_param->maj != 0) {
asd_printk("unsupported manuf. phy param major version:0x%x\n",
phy_param->maj);
return -ENOENT;
}
ASD_DPRINTK("ms: num_phy_desc: %d\n", phy_param->num_phy_desc);
asd_ha->hw_prof.enabled_phys = 0;
for (i = 0; i < phy_param->num_phy_desc; i++) {
struct asd_manuf_phy_desc *pd = &phy_param->phy_desc[i];
switch (pd->state & 0xF) {
case MS_PHY_STATE_HIDDEN:
ASD_DPRINTK("ms: phy%d: HIDDEN\n", i);
continue;
case MS_PHY_STATE_REPORTED:
ASD_DPRINTK("ms: phy%d: REPORTED\n", i);
asd_ha->hw_prof.enabled_phys &= ~(1 << i);
rep_phys++;
continue;
case MS_PHY_STATE_ENABLED:
ASD_DPRINTK("ms: phy%d: ENABLED\n", i);
asd_ha->hw_prof.enabled_phys |= (1 << i);
en_phys++;
break;
}
asd_ha->hw_prof.phy_desc[i].phy_control_0 = pd->phy_control_0;
asd_ha->hw_prof.phy_desc[i].phy_control_1 = pd->phy_control_1;
asd_ha->hw_prof.phy_desc[i].phy_control_2 = pd->phy_control_2;
asd_ha->hw_prof.phy_desc[i].phy_control_3 = pd->phy_control_3;
}
asd_ha->hw_prof.max_phys = rep_phys + en_phys;
asd_ha->hw_prof.num_phys = en_phys;
ASD_DPRINTK("ms: max_phys:0x%x, num_phys:0x%x\n",
asd_ha->hw_prof.max_phys, asd_ha->hw_prof.num_phys);
ASD_DPRINTK("ms: enabled_phys:0x%x\n", asd_ha->hw_prof.enabled_phys);
return 0;
}
static int asd_ms_get_connector_map(struct asd_ha_struct *asd_ha,
struct asd_manuf_sec *manuf_sec)
{
struct asd_ms_conn_map *cm;
cm = asd_find_ll_by_id(manuf_sec, 'M', 'C');
if (!cm) {
ASD_DPRINTK("ms: no connector map found\n");
return 0;
}
if (cm->maj != 0) {
ASD_DPRINTK("ms: unsupported: connector map major version 0x%x"
"\n", cm->maj);
return -ENOENT;
}
return 0;
}
static int asd_process_ms(struct asd_ha_struct *asd_ha,
struct asd_flash_dir *flash_dir)
{
int err;
struct asd_manuf_sec *manuf_sec;
u32 offs, size;
err = asd_find_flash_de(flash_dir, FLASH_DE_MS, &offs, &size);
if (err) {
ASD_DPRINTK("Couldn't find the manuf. sector\n");
goto out;
}
if (size == 0)
goto out;
err = -ENOMEM;
manuf_sec = kmalloc(size, GFP_KERNEL);
if (!manuf_sec) {
ASD_DPRINTK("no mem for manuf sector\n");
goto out;
}
err = asd_read_flash_seg(asd_ha, (void *)manuf_sec, offs, size);
if (err) {
ASD_DPRINTK("couldn't read manuf sector at 0x%x, size 0x%x\n",
offs, size);
goto out2;
}
err = asd_validate_ms(manuf_sec);
if (err) {
ASD_DPRINTK("couldn't validate manuf sector\n");
goto out2;
}
err = asd_ms_get_sas_addr(asd_ha, manuf_sec);
if (err) {
ASD_DPRINTK("couldn't read the SAS_ADDR\n");
goto out2;
}
ASD_DPRINTK("manuf sect SAS_ADDR %llx\n",
SAS_ADDR(asd_ha->hw_prof.sas_addr));
err = asd_ms_get_pcba_sn(asd_ha, manuf_sec);
if (err) {
ASD_DPRINTK("couldn't read the PCBA SN\n");
goto out2;
}
ASD_DPRINTK("manuf sect PCBA SN %s\n", asd_ha->hw_prof.pcba_sn);
err = asd_ms_get_phy_params(asd_ha, manuf_sec);
if (err) {
ASD_DPRINTK("ms: couldn't get phy parameters\n");
goto out2;
}
err = asd_ms_get_connector_map(asd_ha, manuf_sec);
if (err) {
ASD_DPRINTK("ms: couldn't get connector map\n");
goto out2;
}
out2:
kfree(manuf_sec);
out:
return err;
}
static int asd_process_ctrla_phy_settings(struct asd_ha_struct *asd_ha,
struct asd_ctrla_phy_settings *ps)
{
int i;
for (i = 0; i < ps->num_phys; i++) {
struct asd_ctrla_phy_entry *pe = &ps->phy_ent[i];
if (!PHY_ENABLED(asd_ha, i))
continue;
if (*(u64 *)pe->sas_addr == 0) {
asd_ha->hw_prof.enabled_phys &= ~(1 << i);
continue;
}
memcpy(asd_ha->hw_prof.phy_desc[i].sas_addr, pe->sas_addr,
SAS_ADDR_SIZE);
asd_ha->hw_prof.phy_desc[i].max_sas_lrate =
(pe->sas_link_rates & 0xF0) >> 4;
asd_ha->hw_prof.phy_desc[i].min_sas_lrate =
(pe->sas_link_rates & 0x0F);
asd_ha->hw_prof.phy_desc[i].max_sata_lrate =
(pe->sata_link_rates & 0xF0) >> 4;
asd_ha->hw_prof.phy_desc[i].min_sata_lrate =
(pe->sata_link_rates & 0x0F);
asd_ha->hw_prof.phy_desc[i].flags = pe->flags;
ASD_DPRINTK("ctrla: phy%d: sas_addr: %llx, sas rate:0x%x-0x%x,"
" sata rate:0x%x-0x%x, flags:0x%x\n",
i,
SAS_ADDR(asd_ha->hw_prof.phy_desc[i].sas_addr),
asd_ha->hw_prof.phy_desc[i].max_sas_lrate,
asd_ha->hw_prof.phy_desc[i].min_sas_lrate,
asd_ha->hw_prof.phy_desc[i].max_sata_lrate,
asd_ha->hw_prof.phy_desc[i].min_sata_lrate,
asd_ha->hw_prof.phy_desc[i].flags);
}
return 0;
}
static int asd_process_ctrl_a_user(struct asd_ha_struct *asd_ha,
struct asd_flash_dir *flash_dir)
{
int err, i;
u32 offs, size;
struct asd_ll_el *el = NULL;
struct asd_ctrla_phy_settings *ps;
struct asd_ctrla_phy_settings dflt_ps;
err = asd_find_flash_de(flash_dir, FLASH_DE_CTRL_A_USER, &offs, &size);
if (err) {
ASD_DPRINTK("couldn't find CTRL-A user settings section\n");
ASD_DPRINTK("Creating default CTRL-A user settings section\n");
dflt_ps.id0 = 'h';
dflt_ps.num_phys = 8;
for (i =0; i < ASD_MAX_PHYS; i++) {
memcpy(dflt_ps.phy_ent[i].sas_addr,
asd_ha->hw_prof.sas_addr, SAS_ADDR_SIZE);
dflt_ps.phy_ent[i].sas_link_rates = 0x98;
dflt_ps.phy_ent[i].flags = 0x0;
dflt_ps.phy_ent[i].sata_link_rates = 0x0;
}
size = sizeof(struct asd_ctrla_phy_settings);
ps = &dflt_ps;
goto out_process;
}
if (size == 0)
goto out;
err = -ENOMEM;
el = kmalloc(size, GFP_KERNEL);
if (!el) {
ASD_DPRINTK("no mem for ctrla user settings section\n");
goto out;
}
err = asd_read_flash_seg(asd_ha, (void *)el, offs, size);
if (err) {
ASD_DPRINTK("couldn't read ctrla phy settings section\n");
goto out2;
}
err = -ENOENT;
ps = asd_find_ll_by_id(el, 'h', 0xFF);
if (!ps) {
ASD_DPRINTK("couldn't find ctrla phy settings struct\n");
goto out2;
}
out_process:
err = asd_process_ctrla_phy_settings(asd_ha, ps);
if (err) {
ASD_DPRINTK("couldn't process ctrla phy settings\n");
goto out2;
}
out2:
kfree(el);
out:
return err;
}
int asd_read_flash(struct asd_ha_struct *asd_ha)
{
int err;
struct asd_flash_dir *flash_dir;
err = asd_flash_getid(asd_ha);
if (err)
return err;
flash_dir = kmalloc(sizeof(*flash_dir), GFP_KERNEL);
if (!flash_dir)
return -ENOMEM;
err = -ENOENT;
if (!asd_find_flash_dir(asd_ha, flash_dir)) {
ASD_DPRINTK("couldn't find flash directory\n");
goto out;
}
if (le32_to_cpu(flash_dir->rev) != 2) {
asd_printk("unsupported flash dir version:0x%x\n",
le32_to_cpu(flash_dir->rev));
goto out;
}
err = asd_process_ms(asd_ha, flash_dir);
if (err) {
ASD_DPRINTK("couldn't process manuf sector settings\n");
goto out;
}
err = asd_process_ctrl_a_user(asd_ha, flash_dir);
if (err) {
ASD_DPRINTK("couldn't process CTRL-A user settings\n");
goto out;
}
out:
kfree(flash_dir);
return err;
}
int asd_verify_flash_seg(struct asd_ha_struct *asd_ha,
const void *src, u32 dest_offset, u32 bytes_to_verify)
{
const u8 *src_buf;
u8 flash_char;
int err;
u32 nv_offset, reg, i;
reg = asd_ha->hw_prof.flash.bar;
src_buf = NULL;
err = FLASH_OK;
nv_offset = dest_offset;
src_buf = (const u8 *)src;
for (i = 0; i < bytes_to_verify; i++) {
flash_char = asd_read_reg_byte(asd_ha, reg + nv_offset + i);
if (flash_char != src_buf[i]) {
err = FAIL_VERIFY;
break;
}
}
return err;
}
int asd_write_flash_seg(struct asd_ha_struct *asd_ha,
const void *src, u32 dest_offset, u32 bytes_to_write)
{
const u8 *src_buf;
u32 nv_offset, reg, i;
int err;
reg = asd_ha->hw_prof.flash.bar;
src_buf = NULL;
err = asd_check_flash_type(asd_ha);
if (err) {
ASD_DPRINTK("couldn't find the type of flash. err=%d\n", err);
return err;
}
nv_offset = dest_offset;
err = asd_erase_nv_sector(asd_ha, nv_offset, bytes_to_write);
if (err) {
ASD_DPRINTK("Erase failed at offset:0x%x\n",
nv_offset);
return err;
}
err = asd_reset_flash(asd_ha);
if (err) {
ASD_DPRINTK("couldn't reset flash. err=%d\n", err);
return err;
}
src_buf = (const u8 *)src;
for (i = 0; i < bytes_to_write; i++) {
switch (asd_ha->hw_prof.flash.method) {
case FLASH_METHOD_A:
{
asd_write_reg_byte(asd_ha,
(reg + 0xAAA), 0xAA);
asd_write_reg_byte(asd_ha,
(reg + 0x555), 0x55);
asd_write_reg_byte(asd_ha,
(reg + 0xAAA), 0xA0);
asd_write_reg_byte(asd_ha,
(reg + nv_offset + i),
(*(src_buf + i)));
break;
}
case FLASH_METHOD_B:
{
asd_write_reg_byte(asd_ha,
(reg + 0x555), 0xAA);
asd_write_reg_byte(asd_ha,
(reg + 0x2AA), 0x55);
asd_write_reg_byte(asd_ha,
(reg + 0x555), 0xA0);
asd_write_reg_byte(asd_ha,
(reg + nv_offset + i),
(*(src_buf + i)));
break;
}
default:
break;
}
if (asd_chk_write_status(asd_ha,
(nv_offset + i), 0) != 0) {
ASD_DPRINTK("aicx: Write failed at offset:0x%x\n",
reg + nv_offset + i);
return FAIL_WRITE_FLASH;
}
}
err = asd_reset_flash(asd_ha);
if (err) {
ASD_DPRINTK("couldn't reset flash. err=%d\n", err);
return err;
}
return 0;
}
int asd_chk_write_status(struct asd_ha_struct *asd_ha,
u32 sector_addr, u8 erase_flag)
{
u32 reg;
u32 loop_cnt;
u8 nv_data1, nv_data2;
u8 toggle_bit1;
reg = asd_ha->hw_prof.flash.bar;
for (loop_cnt = 0; loop_cnt < 50000; loop_cnt++) {
nv_data1 = asd_read_reg_byte(asd_ha, reg);
nv_data2 = asd_read_reg_byte(asd_ha, reg);
toggle_bit1 = ((nv_data1 & FLASH_STATUS_BIT_MASK_DQ6)
^ (nv_data2 & FLASH_STATUS_BIT_MASK_DQ6));
if (toggle_bit1 == 0) {
return 0;
} else {
if (nv_data2 & FLASH_STATUS_BIT_MASK_DQ5) {
nv_data1 = asd_read_reg_byte(asd_ha,
reg);
nv_data2 = asd_read_reg_byte(asd_ha,
reg);
toggle_bit1 =
((nv_data1 & FLASH_STATUS_BIT_MASK_DQ6)
^ (nv_data2 & FLASH_STATUS_BIT_MASK_DQ6));
if (toggle_bit1 == 0)
return 0;
}
}
if (erase_flag) {
udelay(FLASH_STATUS_ERASE_DELAY_COUNT);
} else {
udelay(FLASH_STATUS_WRITE_DELAY_COUNT);
}
}
return -1;
}
int asd_erase_nv_sector(struct asd_ha_struct *asd_ha, u32 flash_addr, u32 size)
{
u32 reg;
u32 sector_addr;
reg = asd_ha->hw_prof.flash.bar;
sector_addr = flash_addr & FLASH_SECTOR_SIZE_MASK;
while (sector_addr < flash_addr+size) {
switch (asd_ha->hw_prof.flash.method) {
case FLASH_METHOD_A:
asd_write_reg_byte(asd_ha, (reg + 0xAAA), 0xAA);
asd_write_reg_byte(asd_ha, (reg + 0x555), 0x55);
asd_write_reg_byte(asd_ha, (reg + 0xAAA), 0x80);
asd_write_reg_byte(asd_ha, (reg + 0xAAA), 0xAA);
asd_write_reg_byte(asd_ha, (reg + 0x555), 0x55);
asd_write_reg_byte(asd_ha, (reg + sector_addr), 0x30);
break;
case FLASH_METHOD_B:
asd_write_reg_byte(asd_ha, (reg + 0x555), 0xAA);
asd_write_reg_byte(asd_ha, (reg + 0x2AA), 0x55);
asd_write_reg_byte(asd_ha, (reg + 0x555), 0x80);
asd_write_reg_byte(asd_ha, (reg + 0x555), 0xAA);
asd_write_reg_byte(asd_ha, (reg + 0x2AA), 0x55);
asd_write_reg_byte(asd_ha, (reg + sector_addr), 0x30);
break;
default:
break;
}
if (asd_chk_write_status(asd_ha, sector_addr, 1) != 0)
return FAIL_ERASE_FLASH;
sector_addr += FLASH_SECTOR_SIZE;
}
return 0;
}
int asd_check_flash_type(struct asd_ha_struct *asd_ha)
{
u8 manuf_id;
u8 dev_id;
u8 sec_prot;
u32 inc;
u32 reg;
int err;
reg = asd_ha->hw_prof.flash.bar;
err = asd_reset_flash(asd_ha);
if (err) {
ASD_DPRINTK("couldn't reset flash. err=%d\n", err);
return err;
}
asd_ha->hw_prof.flash.method = FLASH_METHOD_UNKNOWN;
asd_ha->hw_prof.flash.manuf = FLASH_MANUF_ID_UNKNOWN;
asd_ha->hw_prof.flash.dev_id = FLASH_DEV_ID_UNKNOWN;
inc = asd_ha->hw_prof.flash.wide ? 2 : 1;
asd_write_reg_byte(asd_ha, reg + 0xAAA, 0xAA);
asd_write_reg_byte(asd_ha, reg + 0x555, 0x55);
asd_write_reg_byte(asd_ha, reg + 0xAAA, 0x90);
manuf_id = asd_read_reg_byte(asd_ha, reg);
dev_id = asd_read_reg_byte(asd_ha, reg + inc);
sec_prot = asd_read_reg_byte(asd_ha, reg + inc + inc);
err = asd_reset_flash(asd_ha);
if (err) {
ASD_DPRINTK("couldn't reset flash. err=%d\n", err);
return err;
}
ASD_DPRINTK("Flash MethodA manuf_id(0x%x) dev_id(0x%x) "
"sec_prot(0x%x)\n", manuf_id, dev_id, sec_prot);
err = asd_reset_flash(asd_ha);
if (err != 0)
return err;
switch (manuf_id) {
case FLASH_MANUF_ID_AMD:
switch (sec_prot) {
case FLASH_DEV_ID_AM29LV800DT:
case FLASH_DEV_ID_AM29LV640MT:
case FLASH_DEV_ID_AM29F800B:
asd_ha->hw_prof.flash.method = FLASH_METHOD_A;
break;
default:
break;
}
break;
case FLASH_MANUF_ID_ST:
switch (sec_prot) {
case FLASH_DEV_ID_STM29W800DT:
case FLASH_DEV_ID_STM29LV640:
asd_ha->hw_prof.flash.method = FLASH_METHOD_A;
break;
default:
break;
}
break;
case FLASH_MANUF_ID_FUJITSU:
switch (sec_prot) {
case FLASH_DEV_ID_MBM29LV800TE:
case FLASH_DEV_ID_MBM29DL800TA:
asd_ha->hw_prof.flash.method = FLASH_METHOD_A;
break;
}
break;
case FLASH_MANUF_ID_MACRONIX:
switch (sec_prot) {
case FLASH_DEV_ID_MX29LV800BT:
asd_ha->hw_prof.flash.method = FLASH_METHOD_A;
break;
}
break;
}
if (asd_ha->hw_prof.flash.method == FLASH_METHOD_UNKNOWN) {
err = asd_reset_flash(asd_ha);
if (err) {
ASD_DPRINTK("couldn't reset flash. err=%d\n", err);
return err;
}
asd_write_reg_byte(asd_ha, (reg + 0x555), 0xAA);
asd_write_reg_byte(asd_ha, (reg + 0x2AA), 0x55);
asd_write_reg_byte(asd_ha, (reg + 0x555), 0x90);
manuf_id = asd_read_reg_byte(asd_ha, reg);
dev_id = asd_read_reg_byte(asd_ha, reg + inc);
sec_prot = asd_read_reg_byte(asd_ha, reg + inc + inc);
ASD_DPRINTK("Flash MethodB manuf_id(0x%x) dev_id(0x%x) sec_prot"
"(0x%x)\n", manuf_id, dev_id, sec_prot);
err = asd_reset_flash(asd_ha);
if (err != 0) {
ASD_DPRINTK("couldn't reset flash. err=%d\n", err);
return err;
}
switch (manuf_id) {
case FLASH_MANUF_ID_AMD:
switch (dev_id) {
case FLASH_DEV_ID_AM29LV008BT:
asd_ha->hw_prof.flash.method = FLASH_METHOD_B;
break;
default:
break;
}
break;
case FLASH_MANUF_ID_ST:
switch (dev_id) {
case FLASH_DEV_ID_STM29008:
asd_ha->hw_prof.flash.method = FLASH_METHOD_B;
break;
default:
break;
}
break;
case FLASH_MANUF_ID_FUJITSU:
switch (dev_id) {
case FLASH_DEV_ID_MBM29LV008TA:
asd_ha->hw_prof.flash.method = FLASH_METHOD_B;
break;
}
break;
case FLASH_MANUF_ID_INTEL:
switch (dev_id) {
case FLASH_DEV_ID_I28LV00TAT:
asd_ha->hw_prof.flash.method = FLASH_METHOD_B;
break;
}
break;
case FLASH_MANUF_ID_MACRONIX:
switch (dev_id) {
case FLASH_DEV_ID_I28LV00TAT:
asd_ha->hw_prof.flash.method = FLASH_METHOD_B;
break;
}
break;
default:
return FAIL_FIND_FLASH_ID;
}
}
if (asd_ha->hw_prof.flash.method == FLASH_METHOD_UNKNOWN)
return FAIL_FIND_FLASH_ID;
asd_ha->hw_prof.flash.manuf = manuf_id;
asd_ha->hw_prof.flash.dev_id = dev_id;
asd_ha->hw_prof.flash.sec_prot = sec_prot;
return 0;
}
