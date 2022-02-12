static void
sym_fw1_patch(struct Scsi_Host *shost)
{
struct sym_hcb *np = sym_get_hcb(shost);
struct sym_fw1a_scr *scripta0;
struct sym_fw1b_scr *scriptb0;
scripta0 = (struct sym_fw1a_scr *) np->scripta0;
scriptb0 = (struct sym_fw1b_scr *) np->scriptb0;
if (!(np->features & FE_LED0)) {
scripta0->idle[0] = cpu_to_scr(SCR_NO_OP);
scripta0->reselected[0] = cpu_to_scr(SCR_NO_OP);
scripta0->start[0] = cpu_to_scr(SCR_NO_OP);
}
#ifdef SYM_CONF_IARB_SUPPORT
if (!SYM_CONF_SET_IARB_ON_ARB_LOST)
scripta0->ungetjob[0] = cpu_to_scr(SCR_NO_OP);
#endif
scriptb0->startpos[0] = cpu_to_scr(np->squeue_ba);
scriptb0->done_pos[0] = cpu_to_scr(np->dqueue_ba);
scriptb0->targtbl[0] = cpu_to_scr(np->targtbl_ba);
}
static void
sym_fw2_patch(struct Scsi_Host *shost)
{
struct sym_data *sym_data = shost_priv(shost);
struct pci_dev *pdev = sym_data->pdev;
struct sym_hcb *np = sym_data->ncb;
struct sym_fw2a_scr *scripta0;
struct sym_fw2b_scr *scriptb0;
scripta0 = (struct sym_fw2a_scr *) np->scripta0;
scriptb0 = (struct sym_fw2b_scr *) np->scriptb0;
if (!(np->features & FE_LED0)) {
scripta0->idle[0] = cpu_to_scr(SCR_NO_OP);
scripta0->reselected[0] = cpu_to_scr(SCR_NO_OP);
scripta0->start[0] = cpu_to_scr(SCR_NO_OP);
}
#if SYM_CONF_DMA_ADDRESSING_MODE == 2
if (!use_dac(np)) {
scripta0->is_dmap_dirty[0] = cpu_to_scr(SCR_NO_OP);
scripta0->is_dmap_dirty[1] = 0;
scripta0->is_dmap_dirty[2] = cpu_to_scr(SCR_NO_OP);
scripta0->is_dmap_dirty[3] = 0;
}
#endif
#ifdef SYM_CONF_IARB_SUPPORT
if (!SYM_CONF_SET_IARB_ON_ARB_LOST)
scripta0->ungetjob[0] = cpu_to_scr(SCR_NO_OP);
#endif
scriptb0->startpos[0] = cpu_to_scr(np->squeue_ba);
scriptb0->done_pos[0] = cpu_to_scr(np->dqueue_ba);
scriptb0->targtbl[0] = cpu_to_scr(np->targtbl_ba);
if (!(np->features & FE_C10)) {
scripta0->resel_scntl4[0] = cpu_to_scr(SCR_NO_OP);
scripta0->resel_scntl4[1] = cpu_to_scr(0);
}
if (!(pdev->device == PCI_DEVICE_ID_LSI_53C1010_66 &&
pdev->revision < 0x1 &&
np->pciclk_khz < 60000)) {
scripta0->datao_phase[0] = cpu_to_scr(SCR_NO_OP);
scripta0->datao_phase[1] = cpu_to_scr(0);
}
if (!(pdev->device == PCI_DEVICE_ID_LSI_53C1010_33 )) {
scripta0->sel_done[0] = cpu_to_scr(SCR_NO_OP);
scripta0->sel_done[1] = cpu_to_scr(0);
}
scriptb0->pm0_data_addr[0] =
cpu_to_scr(np->scripta_ba +
offsetof(struct sym_fw2a_scr, pm0_data));
scriptb0->pm1_data_addr[0] =
cpu_to_scr(np->scripta_ba +
offsetof(struct sym_fw2a_scr, pm1_data));
}
static void
sym_fw_fill_data (u32 *in, u32 *out)
{
int i;
for (i = 0; i < SYM_CONF_MAX_SG; i++) {
*in++ = SCR_CHMOV_TBL ^ SCR_DATA_IN;
*in++ = offsetof (struct sym_dsb, data[i]);
*out++ = SCR_CHMOV_TBL ^ SCR_DATA_OUT;
*out++ = offsetof (struct sym_dsb, data[i]);
}
}
static void
sym_fw_setup_bus_addresses(struct sym_hcb *np, struct sym_fw *fw)
{
u32 *pa;
u_short *po;
int i;
po = (u_short *) fw->a_ofs;
pa = (u32 *) &np->fwa_bas;
for (i = 0 ; i < sizeof(np->fwa_bas)/sizeof(u32) ; i++)
pa[i] = np->scripta_ba + po[i];
po = (u_short *) fw->b_ofs;
pa = (u32 *) &np->fwb_bas;
for (i = 0 ; i < sizeof(np->fwb_bas)/sizeof(u32) ; i++)
pa[i] = np->scriptb_ba + po[i];
po = (u_short *) fw->z_ofs;
pa = (u32 *) &np->fwz_bas;
for (i = 0 ; i < sizeof(np->fwz_bas)/sizeof(u32) ; i++)
pa[i] = np->scriptz_ba + po[i];
}
static void
sym_fw1_setup(struct sym_hcb *np, struct sym_fw *fw)
{
struct sym_fw1a_scr *scripta0;
struct sym_fw1b_scr *scriptb0;
scripta0 = (struct sym_fw1a_scr *) np->scripta0;
scriptb0 = (struct sym_fw1b_scr *) np->scriptb0;
sym_fw_fill_data(scripta0->data_in, scripta0->data_out);
sym_fw_setup_bus_addresses(np, fw);
}
static void
sym_fw2_setup(struct sym_hcb *np, struct sym_fw *fw)
{
struct sym_fw2a_scr *scripta0;
struct sym_fw2b_scr *scriptb0;
scripta0 = (struct sym_fw2a_scr *) np->scripta0;
scriptb0 = (struct sym_fw2b_scr *) np->scriptb0;
sym_fw_fill_data(scripta0->data_in, scripta0->data_out);
sym_fw_setup_bus_addresses(np, fw);
}
struct sym_fw *
sym_find_firmware(struct sym_chip *chip)
{
if (chip->features & FE_LDSTR)
return &sym_fw2;
#if SYM_CONF_GENERIC_SUPPORT
else if (!(chip->features & (FE_PFEN|FE_NOPM|FE_DAC)))
return &sym_fw1;
#endif
else
return NULL;
}
void sym_fw_bind_script(struct sym_hcb *np, u32 *start, int len)
{
u32 opcode, new, old, tmp1, tmp2;
u32 *end, *cur;
int relocs;
cur = start;
end = start + len/4;
while (cur < end) {
opcode = *cur;
if (opcode == 0) {
printf ("%s: ERROR0 IN SCRIPT at %d.\n",
sym_name(np), (int) (cur-start));
++cur;
continue;
};
if (opcode == SCR_DATA_ZERO) {
*cur++ = 0;
continue;
}
if (DEBUG_FLAGS & DEBUG_SCRIPT)
printf ("%d: <%x>\n", (int) (cur-start),
(unsigned)opcode);
switch (opcode >> 28) {
case 0xf:
relocs = 0;
break;
case 0xe:
relocs = 1;
break;
case 0xc:
relocs = 2;
tmp1 = cur[1];
tmp2 = cur[2];
if ((tmp1 ^ tmp2) & 3) {
printf ("%s: ERROR1 IN SCRIPT at %d.\n",
sym_name(np), (int) (cur-start));
}
if ((opcode & SCR_NO_FLUSH) &&
!(np->features & FE_PFEN)) {
opcode = (opcode & ~SCR_NO_FLUSH);
}
break;
case 0x0:
if (!(np->features & FE_WIDE))
opcode = (opcode | OPC_MOVE);
relocs = 1;
break;
case 0x1:
if (!(np->features & FE_WIDE))
opcode = (opcode | OPC_MOVE);
relocs = 0;
break;
#ifdef SYM_CONF_TARGET_ROLE_SUPPORT
case 0x2:
opcode &= ~0x20000000;
if (!(np->features & FE_WIDE))
opcode = (opcode & ~OPC_TCHMOVE);
relocs = 1;
break;
case 0x3:
opcode &= ~0x20000000;
if (!(np->features & FE_WIDE))
opcode = (opcode & ~OPC_TCHMOVE);
relocs = 0;
break;
#endif
case 0x8:
if (opcode & 0x00800000)
relocs = 0;
else if ((opcode & 0xf8400000) == 0x80400000)
relocs = 2;
else
relocs = 1;
break;
case 0x4:
case 0x5:
case 0x6:
case 0x7:
relocs = 1;
break;
default:
relocs = 0;
break;
};
*cur++ = cpu_to_scr(opcode);
if (!relocs) {
*cur = cpu_to_scr(*cur);
++cur;
continue;
}
while (relocs--) {
old = *cur;
switch (old & RELOC_MASK) {
case RELOC_REGISTER:
new = (old & ~RELOC_MASK) + np->mmio_ba;
break;
case RELOC_LABEL_A:
new = (old & ~RELOC_MASK) + np->scripta_ba;
break;
case RELOC_LABEL_B:
new = (old & ~RELOC_MASK) + np->scriptb_ba;
break;
case RELOC_SOFTC:
new = (old & ~RELOC_MASK) + np->hcb_ba;
break;
case 0:
if (old == 0) {
new = old;
break;
}
default:
new = 0;
panic("sym_fw_bind_script: "
"weird relocation %x\n", old);
break;
}
*cur++ = cpu_to_scr(new);
}
};
}
