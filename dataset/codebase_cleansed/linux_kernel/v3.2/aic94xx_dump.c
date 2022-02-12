static void asd_dump_cseq_state(struct asd_ha_struct *asd_ha)
{
int mode;
asd_printk("CSEQ STATE\n");
asd_printk("ARP2 REGISTERS\n");
PRINT_CREG_32bit(asd_ha, ARP2CTL);
PRINT_CREG_32bit(asd_ha, ARP2INT);
PRINT_CREG_32bit(asd_ha, ARP2INTEN);
PRINT_CREG_8bit(asd_ha, MODEPTR);
PRINT_CREG_8bit(asd_ha, ALTMODE);
PRINT_CREG_8bit(asd_ha, FLAG);
PRINT_CREG_8bit(asd_ha, ARP2INTCTL);
PRINT_CREG_16bit(asd_ha, STACK);
PRINT_CREG_16bit(asd_ha, PRGMCNT);
PRINT_CREG_16bit(asd_ha, ACCUM);
PRINT_CREG_16bit(asd_ha, SINDEX);
PRINT_CREG_16bit(asd_ha, DINDEX);
PRINT_CREG_8bit(asd_ha, SINDIR);
PRINT_CREG_8bit(asd_ha, DINDIR);
PRINT_CREG_8bit(asd_ha, JUMLDIR);
PRINT_CREG_8bit(asd_ha, ARP2HALTCODE);
PRINT_CREG_16bit(asd_ha, CURRADDR);
PRINT_CREG_16bit(asd_ha, LASTADDR);
PRINT_CREG_16bit(asd_ha, NXTLADDR);
asd_printk("IOP REGISTERS\n");
PRINT_REG_32bit(asd_ha, BISTCTL1, CBISTCTL);
PRINT_CREG_32bit(asd_ha, MAPPEDSCR);
asd_printk("CIO REGISTERS\n");
for (mode = 0; mode < 9; mode++)
PRINT_MREG_16bit(asd_ha, mode, MnSCBPTR, CMnSCBPTR(mode));
PRINT_MREG_16bit(asd_ha, 15, MnSCBPTR, CMnSCBPTR(15));
for (mode = 0; mode < 9; mode++)
PRINT_MREG_16bit(asd_ha, mode, MnDDBPTR, CMnDDBPTR(mode));
PRINT_MREG_16bit(asd_ha, 15, MnDDBPTR, CMnDDBPTR(15));
for (mode = 0; mode < 8; mode++)
PRINT_MREG_32bit(asd_ha, mode, MnREQMBX, CMnREQMBX(mode));
for (mode = 0; mode < 8; mode++)
PRINT_MREG_32bit(asd_ha, mode, MnRSPMBX, CMnRSPMBX(mode));
for (mode = 0; mode < 8; mode++)
PRINT_MREG_32bit(asd_ha, mode, MnINT, CMnINT(mode));
for (mode = 0; mode < 8; mode++)
PRINT_MREG_32bit(asd_ha, mode, MnINTEN, CMnINTEN(mode));
PRINT_CREG_8bit(asd_ha, SCRATCHPAGE);
for (mode = 0; mode < 8; mode++)
PRINT_MREG_8bit(asd_ha, mode, MnSCRATCHPAGE,
CMnSCRATCHPAGE(mode));
PRINT_REG_32bit(asd_ha, CLINKCON, CLINKCON);
PRINT_REG_8bit(asd_ha, CCONMSK, CCONMSK);
PRINT_REG_8bit(asd_ha, CCONEXIST, CCONEXIST);
PRINT_REG_16bit(asd_ha, CCONMODE, CCONMODE);
PRINT_REG_32bit(asd_ha, CTIMERCALC, CTIMERCALC);
PRINT_REG_8bit(asd_ha, CINTDIS, CINTDIS);
asd_printk("SCRATCH MEMORY\n");
asd_printk("MIP 4 >>>>>\n");
PRINT_MIS_word(asd_ha, Q_EXE_HEAD);
PRINT_MIS_word(asd_ha, Q_EXE_TAIL);
PRINT_MIS_word(asd_ha, Q_DONE_HEAD);
PRINT_MIS_word(asd_ha, Q_DONE_TAIL);
PRINT_MIS_word(asd_ha, Q_SEND_HEAD);
PRINT_MIS_word(asd_ha, Q_SEND_TAIL);
PRINT_MIS_word(asd_ha, Q_DMA2CHIM_HEAD);
PRINT_MIS_word(asd_ha, Q_DMA2CHIM_TAIL);
PRINT_MIS_word(asd_ha, Q_COPY_HEAD);
PRINT_MIS_word(asd_ha, Q_COPY_TAIL);
PRINT_MIS_word(asd_ha, REG0);
PRINT_MIS_word(asd_ha, REG1);
PRINT_MIS_dword(asd_ha, REG2);
PRINT_MIS_byte(asd_ha, LINK_CTL_Q_MAP);
PRINT_MIS_byte(asd_ha, MAX_CSEQ_MODE);
PRINT_MIS_byte(asd_ha, FREE_LIST_HACK_COUNT);
asd_printk("MIP 5 >>>>\n");
PRINT_MIS_qword(asd_ha, EST_NEXUS_REQ_QUEUE);
PRINT_MIS_qword(asd_ha, EST_NEXUS_REQ_COUNT);
PRINT_MIS_word(asd_ha, Q_EST_NEXUS_HEAD);
PRINT_MIS_word(asd_ha, Q_EST_NEXUS_TAIL);
PRINT_MIS_word(asd_ha, NEED_EST_NEXUS_SCB);
PRINT_MIS_byte(asd_ha, EST_NEXUS_REQ_HEAD);
PRINT_MIS_byte(asd_ha, EST_NEXUS_REQ_TAIL);
PRINT_MIS_byte(asd_ha, EST_NEXUS_SCB_OFFSET);
asd_printk("MIP 6 >>>>\n");
PRINT_MIS_word(asd_ha, INT_ROUT_RET_ADDR0);
PRINT_MIS_word(asd_ha, INT_ROUT_RET_ADDR1);
PRINT_MIS_word(asd_ha, INT_ROUT_SCBPTR);
PRINT_MIS_byte(asd_ha, INT_ROUT_MODE);
PRINT_MIS_byte(asd_ha, ISR_SCRATCH_FLAGS);
PRINT_MIS_word(asd_ha, ISR_SAVE_SINDEX);
PRINT_MIS_word(asd_ha, ISR_SAVE_DINDEX);
PRINT_MIS_word(asd_ha, Q_MONIRTT_HEAD);
PRINT_MIS_word(asd_ha, Q_MONIRTT_TAIL);
PRINT_MIS_byte(asd_ha, FREE_SCB_MASK);
PRINT_MIS_word(asd_ha, BUILTIN_FREE_SCB_HEAD);
PRINT_MIS_word(asd_ha, BUILTIN_FREE_SCB_TAIL);
PRINT_MIS_word(asd_ha, EXTENDED_FREE_SCB_HEAD);
PRINT_MIS_word(asd_ha, EXTENDED_FREE_SCB_TAIL);
asd_printk("MIP 7 >>>>\n");
PRINT_MIS_qword(asd_ha, EMPTY_REQ_QUEUE);
PRINT_MIS_qword(asd_ha, EMPTY_REQ_COUNT);
PRINT_MIS_word(asd_ha, Q_EMPTY_HEAD);
PRINT_MIS_word(asd_ha, Q_EMPTY_TAIL);
PRINT_MIS_word(asd_ha, NEED_EMPTY_SCB);
PRINT_MIS_byte(asd_ha, EMPTY_REQ_HEAD);
PRINT_MIS_byte(asd_ha, EMPTY_REQ_TAIL);
PRINT_MIS_byte(asd_ha, EMPTY_SCB_OFFSET);
PRINT_MIS_word(asd_ha, PRIMITIVE_DATA);
PRINT_MIS_dword(asd_ha, TIMEOUT_CONST);
asd_printk("MDP 0 >>>>\n");
asd_printk("%-20s %6s %6s %6s %6s %6s %6s %6s %6s\n",
"Mode: ", "0", "1", "2", "3", "4", "5", "6", "7");
PRINT_CMDP_word(asd_ha, LRM_SAVE_SINDEX);
PRINT_CMDP_word(asd_ha, LRM_SAVE_SCBPTR);
PRINT_CMDP_word(asd_ha, Q_LINK_HEAD);
PRINT_CMDP_word(asd_ha, Q_LINK_TAIL);
PRINT_CMDP_byte(asd_ha, LRM_SAVE_SCRPAGE);
asd_printk("MDP 0 Mode 8 >>>>\n");
PRINT_MIS_word(asd_ha, RET_ADDR);
PRINT_MIS_word(asd_ha, RET_SCBPTR);
PRINT_MIS_word(asd_ha, SAVE_SCBPTR);
PRINT_MIS_word(asd_ha, EMPTY_TRANS_CTX);
PRINT_MIS_word(asd_ha, RESP_LEN);
PRINT_MIS_word(asd_ha, TMF_SCBPTR);
PRINT_MIS_word(asd_ha, GLOBAL_PREV_SCB);
PRINT_MIS_word(asd_ha, GLOBAL_HEAD);
PRINT_MIS_word(asd_ha, CLEAR_LU_HEAD);
PRINT_MIS_byte(asd_ha, TMF_OPCODE);
PRINT_MIS_byte(asd_ha, SCRATCH_FLAGS);
PRINT_MIS_word(asd_ha, HSB_SITE);
PRINT_MIS_word(asd_ha, FIRST_INV_SCB_SITE);
PRINT_MIS_word(asd_ha, FIRST_INV_DDB_SITE);
asd_printk("MDP 1 Mode 8 >>>>\n");
PRINT_MIS_qword(asd_ha, LUN_TO_CLEAR);
PRINT_MIS_qword(asd_ha, LUN_TO_CHECK);
asd_printk("MDP 2 Mode 8 >>>>\n");
PRINT_MIS_qword(asd_ha, HQ_NEW_POINTER);
PRINT_MIS_qword(asd_ha, HQ_DONE_BASE);
PRINT_MIS_dword(asd_ha, HQ_DONE_POINTER);
PRINT_MIS_byte(asd_ha, HQ_DONE_PASS);
}
static void asd_print_lseq_cio_reg(struct asd_ha_struct *asd_ha,
u32 lseq_cio_addr, int i)
{
switch (LSEQmCIOREGS[i].width) {
case 8:
asd_printk("%20s[0x%x]: 0x%02x\n", LSEQmCIOREGS[i].name,
LSEQmCIOREGS[i].offs,
asd_read_reg_byte(asd_ha, lseq_cio_addr +
LSEQmCIOREGS[i].offs));
break;
case 16:
asd_printk("%20s[0x%x]: 0x%04x\n", LSEQmCIOREGS[i].name,
LSEQmCIOREGS[i].offs,
asd_read_reg_word(asd_ha, lseq_cio_addr +
LSEQmCIOREGS[i].offs));
break;
case 32:
asd_printk("%20s[0x%x]: 0x%08x\n", LSEQmCIOREGS[i].name,
LSEQmCIOREGS[i].offs,
asd_read_reg_dword(asd_ha, lseq_cio_addr +
LSEQmCIOREGS[i].offs));
break;
}
}
static void asd_dump_lseq_state(struct asd_ha_struct *asd_ha, int lseq)
{
u32 moffs;
int mode;
asd_printk("LSEQ %d STATE\n", lseq);
asd_printk("LSEQ%d: ARP2 REGISTERS\n", lseq);
PRINT_LREG_32bit(asd_ha, lseq, ARP2CTL);
PRINT_LREG_32bit(asd_ha, lseq, ARP2INT);
PRINT_LREG_32bit(asd_ha, lseq, ARP2INTEN);
PRINT_LREG_8bit(asd_ha, lseq, MODEPTR);
PRINT_LREG_8bit(asd_ha, lseq, ALTMODE);
PRINT_LREG_8bit(asd_ha, lseq, FLAG);
PRINT_LREG_8bit(asd_ha, lseq, ARP2INTCTL);
PRINT_LREG_16bit(asd_ha, lseq, STACK);
PRINT_LREG_16bit(asd_ha, lseq, PRGMCNT);
PRINT_LREG_16bit(asd_ha, lseq, ACCUM);
PRINT_LREG_16bit(asd_ha, lseq, SINDEX);
PRINT_LREG_16bit(asd_ha, lseq, DINDEX);
PRINT_LREG_8bit(asd_ha, lseq, SINDIR);
PRINT_LREG_8bit(asd_ha, lseq, DINDIR);
PRINT_LREG_8bit(asd_ha, lseq, JUMLDIR);
PRINT_LREG_8bit(asd_ha, lseq, ARP2HALTCODE);
PRINT_LREG_16bit(asd_ha, lseq, CURRADDR);
PRINT_LREG_16bit(asd_ha, lseq, LASTADDR);
PRINT_LREG_16bit(asd_ha, lseq, NXTLADDR);
asd_printk("LSEQ%d: IOP REGISTERS\n", lseq);
PRINT_LREG_32bit(asd_ha, lseq, MODECTL);
PRINT_LREG_32bit(asd_ha, lseq, DBGMODE);
PRINT_LREG_32bit(asd_ha, lseq, CONTROL);
PRINT_REG_32bit(asd_ha, BISTCTL0, LmBISTCTL0(lseq));
PRINT_REG_32bit(asd_ha, BISTCTL1, LmBISTCTL1(lseq));
asd_printk("LSEQ%d: CIO REGISTERS\n", lseq);
asd_printk("Mode common:\n");
for (mode = 0; mode < 8; mode++) {
u32 lseq_cio_addr = LmSEQ_PHY_BASE(mode, lseq);
int i;
for (i = 0; LSEQmCIOREGS[i].name; i++)
if (LSEQmCIOREGS[i].mode == MODE_COMMON)
asd_print_lseq_cio_reg(asd_ha,lseq_cio_addr,i);
}
asd_printk("Mode unique:\n");
for (mode = 0; mode < 8; mode++) {
u32 lseq_cio_addr = LmSEQ_PHY_BASE(mode, lseq);
int i;
asd_printk("Mode %d\n", mode);
for (i = 0; LSEQmCIOREGS[i].name; i++) {
if (!(LSEQmCIOREGS[i].mode & (1 << mode)))
continue;
asd_print_lseq_cio_reg(asd_ha, lseq_cio_addr, i);
}
}
asd_printk("SCRATCH MEMORY\n");
asd_printk("LSEQ%d MIP 0 >>>>\n", lseq);
PRINT_LMIP_word(asd_ha, lseq, Q_TGTXFR_HEAD);
PRINT_LMIP_word(asd_ha, lseq, Q_TGTXFR_TAIL);
PRINT_LMIP_byte(asd_ha, lseq, LINK_NUMBER);
PRINT_LMIP_byte(asd_ha, lseq, SCRATCH_FLAGS);
PRINT_LMIP_dword(asd_ha, lseq, CONNECTION_STATE);
PRINT_LMIP_word(asd_ha, lseq, CONCTL);
PRINT_LMIP_byte(asd_ha, lseq, CONSTAT);
PRINT_LMIP_byte(asd_ha, lseq, CONNECTION_MODES);
PRINT_LMIP_word(asd_ha, lseq, REG1_ISR);
PRINT_LMIP_word(asd_ha, lseq, REG2_ISR);
PRINT_LMIP_word(asd_ha, lseq, REG3_ISR);
PRINT_LMIP_qword(asd_ha, lseq,REG0_ISR);
asd_printk("LSEQ%d MIP 1 >>>>\n", lseq);
PRINT_LMIP_word(asd_ha, lseq, EST_NEXUS_SCBPTR0);
PRINT_LMIP_word(asd_ha, lseq, EST_NEXUS_SCBPTR1);
PRINT_LMIP_word(asd_ha, lseq, EST_NEXUS_SCBPTR2);
PRINT_LMIP_word(asd_ha, lseq, EST_NEXUS_SCBPTR3);
PRINT_LMIP_byte(asd_ha, lseq, EST_NEXUS_SCB_OPCODE0);
PRINT_LMIP_byte(asd_ha, lseq, EST_NEXUS_SCB_OPCODE1);
PRINT_LMIP_byte(asd_ha, lseq, EST_NEXUS_SCB_OPCODE2);
PRINT_LMIP_byte(asd_ha, lseq, EST_NEXUS_SCB_OPCODE3);
PRINT_LMIP_byte(asd_ha, lseq, EST_NEXUS_SCB_HEAD);
PRINT_LMIP_byte(asd_ha, lseq, EST_NEXUS_SCB_TAIL);
PRINT_LMIP_byte(asd_ha, lseq, EST_NEXUS_BUF_AVAIL);
PRINT_LMIP_dword(asd_ha, lseq, TIMEOUT_CONST);
PRINT_LMIP_word(asd_ha, lseq, ISR_SAVE_SINDEX);
PRINT_LMIP_word(asd_ha, lseq, ISR_SAVE_DINDEX);
asd_printk("LSEQ%d MIP 2 >>>>\n", lseq);
PRINT_LMIP_word(asd_ha, lseq, EMPTY_SCB_PTR0);
PRINT_LMIP_word(asd_ha, lseq, EMPTY_SCB_PTR1);
PRINT_LMIP_word(asd_ha, lseq, EMPTY_SCB_PTR2);
PRINT_LMIP_word(asd_ha, lseq, EMPTY_SCB_PTR3);
PRINT_LMIP_byte(asd_ha, lseq, EMPTY_SCB_OPCD0);
PRINT_LMIP_byte(asd_ha, lseq, EMPTY_SCB_OPCD1);
PRINT_LMIP_byte(asd_ha, lseq, EMPTY_SCB_OPCD2);
PRINT_LMIP_byte(asd_ha, lseq, EMPTY_SCB_OPCD3);
PRINT_LMIP_byte(asd_ha, lseq, EMPTY_SCB_HEAD);
PRINT_LMIP_byte(asd_ha, lseq, EMPTY_SCB_TAIL);
PRINT_LMIP_byte(asd_ha, lseq, EMPTY_BUFS_AVAIL);
asd_printk("LSEQ%d MIP 3 >>>>\n", lseq);
PRINT_LMIP_dword(asd_ha, lseq, DEV_PRES_TMR_TOUT_CONST);
PRINT_LMIP_dword(asd_ha, lseq, SATA_INTERLOCK_TIMEOUT);
PRINT_LMIP_dword(asd_ha, lseq, SRST_ASSERT_TIMEOUT);
PRINT_LMIP_dword(asd_ha, lseq, RCV_FIS_TIMEOUT);
PRINT_LMIP_dword(asd_ha, lseq, ONE_MILLISEC_TIMEOUT);
PRINT_LMIP_dword(asd_ha, lseq, TEN_MS_COMINIT_TIMEOUT);
PRINT_LMIP_dword(asd_ha, lseq, SMP_RCV_TIMEOUT);
for (mode = 0; mode < 3; mode++) {
asd_printk("LSEQ%d MDP 0 MODE %d >>>>\n", lseq, mode);
moffs = mode * LSEQ_MODE_SCRATCH_SIZE;
asd_printk(STR_16BIT, "RET_ADDR", 0,
asd_read_reg_word(asd_ha, LmSEQ_RET_ADDR(lseq)
+ moffs));
asd_printk(STR_16BIT, "REG0_MODE", 2,
asd_read_reg_word(asd_ha, LmSEQ_REG0_MODE(lseq)
+ moffs));
asd_printk(STR_16BIT, "MODE_FLAGS", 4,
asd_read_reg_word(asd_ha, LmSEQ_MODE_FLAGS(lseq)
+ moffs));
asd_printk(STR_16BIT, "RET_ADDR2", 0x6,
asd_read_reg_word(asd_ha, LmSEQ_RET_ADDR2(lseq)
+ moffs));
asd_printk(STR_16BIT, "RET_ADDR1", 0x8,
asd_read_reg_word(asd_ha, LmSEQ_RET_ADDR1(lseq)
+ moffs));
asd_printk(STR_8BIT, "OPCODE_TO_CSEQ", 0xB,
asd_read_reg_byte(asd_ha, LmSEQ_OPCODE_TO_CSEQ(lseq)
+ moffs));
asd_printk(STR_16BIT, "DATA_TO_CSEQ", 0xC,
asd_read_reg_word(asd_ha, LmSEQ_DATA_TO_CSEQ(lseq)
+ moffs));
}
asd_printk("LSEQ%d MDP 0 MODE 5 >>>>\n", lseq);
moffs = LSEQ_MODE5_PAGE0_OFFSET;
asd_printk(STR_16BIT, "RET_ADDR", 0,
asd_read_reg_word(asd_ha, LmSEQ_RET_ADDR(lseq) + moffs));
asd_printk(STR_16BIT, "REG0_MODE", 2,
asd_read_reg_word(asd_ha, LmSEQ_REG0_MODE(lseq) + moffs));
asd_printk(STR_16BIT, "MODE_FLAGS", 4,
asd_read_reg_word(asd_ha, LmSEQ_MODE_FLAGS(lseq) + moffs));
asd_printk(STR_16BIT, "RET_ADDR2", 0x6,
asd_read_reg_word(asd_ha, LmSEQ_RET_ADDR2(lseq) + moffs));
asd_printk(STR_16BIT, "RET_ADDR1", 0x8,
asd_read_reg_word(asd_ha, LmSEQ_RET_ADDR1(lseq) + moffs));
asd_printk(STR_8BIT, "OPCODE_TO_CSEQ", 0xB,
asd_read_reg_byte(asd_ha, LmSEQ_OPCODE_TO_CSEQ(lseq) + moffs));
asd_printk(STR_16BIT, "DATA_TO_CSEQ", 0xC,
asd_read_reg_word(asd_ha, LmSEQ_DATA_TO_CSEQ(lseq) + moffs));
asd_printk("LSEQ%d MDP 0 MODE 0 >>>>\n", lseq);
PRINT_LMIP_word(asd_ha, lseq, FIRST_INV_DDB_SITE);
PRINT_LMIP_word(asd_ha, lseq, EMPTY_TRANS_CTX);
PRINT_LMIP_word(asd_ha, lseq, RESP_LEN);
PRINT_LMIP_word(asd_ha, lseq, FIRST_INV_SCB_SITE);
PRINT_LMIP_dword(asd_ha, lseq, INTEN_SAVE);
PRINT_LMIP_byte(asd_ha, lseq, LINK_RST_FRM_LEN);
PRINT_LMIP_byte(asd_ha, lseq, LINK_RST_PROTOCOL);
PRINT_LMIP_byte(asd_ha, lseq, RESP_STATUS);
PRINT_LMIP_byte(asd_ha, lseq, LAST_LOADED_SGE);
PRINT_LMIP_byte(asd_ha, lseq, SAVE_SCBPTR);
asd_printk("LSEQ%d MDP 0 MODE 1 >>>>\n", lseq);
PRINT_LMIP_word(asd_ha, lseq, Q_XMIT_HEAD);
PRINT_LMIP_word(asd_ha, lseq, M1_EMPTY_TRANS_CTX);
PRINT_LMIP_word(asd_ha, lseq, INI_CONN_TAG);
PRINT_LMIP_byte(asd_ha, lseq, FAILED_OPEN_STATUS);
PRINT_LMIP_byte(asd_ha, lseq, XMIT_REQUEST_TYPE);
PRINT_LMIP_byte(asd_ha, lseq, M1_RESP_STATUS);
PRINT_LMIP_byte(asd_ha, lseq, M1_LAST_LOADED_SGE);
PRINT_LMIP_word(asd_ha, lseq, M1_SAVE_SCBPTR);
asd_printk("LSEQ%d MDP 0 MODE 2 >>>>\n", lseq);
PRINT_LMIP_word(asd_ha, lseq, PORT_COUNTER);
PRINT_LMIP_word(asd_ha, lseq, PM_TABLE_PTR);
PRINT_LMIP_word(asd_ha, lseq, SATA_INTERLOCK_TMR_SAVE);
PRINT_LMIP_word(asd_ha, lseq, IP_BITL);
PRINT_LMIP_word(asd_ha, lseq, COPY_SMP_CONN_TAG);
PRINT_LMIP_byte(asd_ha, lseq, P0M2_OFFS1AH);
asd_printk("LSEQ%d MDP 0 MODE 4/5 >>>>\n", lseq);
PRINT_LMIP_byte(asd_ha, lseq, SAVED_OOB_STATUS);
PRINT_LMIP_byte(asd_ha, lseq, SAVED_OOB_MODE);
PRINT_LMIP_word(asd_ha, lseq, Q_LINK_HEAD);
PRINT_LMIP_byte(asd_ha, lseq, LINK_RST_ERR);
PRINT_LMIP_byte(asd_ha, lseq, SAVED_OOB_SIGNALS);
PRINT_LMIP_byte(asd_ha, lseq, SAS_RESET_MODE);
PRINT_LMIP_byte(asd_ha, lseq, LINK_RESET_RETRY_COUNT);
PRINT_LMIP_byte(asd_ha, lseq, NUM_LINK_RESET_RETRIES);
PRINT_LMIP_word(asd_ha, lseq, OOB_INT_ENABLES);
PRINT_LMIP_word(asd_ha, lseq, NOTIFY_TIMER_TIMEOUT);
PRINT_LMIP_word(asd_ha, lseq, NOTIFY_TIMER_DOWN_COUNT);
asd_printk("LSEQ%d MDP 1 MODE 0 >>>>\n", lseq);
PRINT_LMIP_qword(asd_ha, lseq, SG_LIST_PTR_ADDR0);
PRINT_LMIP_qword(asd_ha, lseq, SG_LIST_PTR_ADDR1);
asd_printk("LSEQ%d MDP 1 MODE 1 >>>>\n", lseq);
PRINT_LMIP_qword(asd_ha, lseq, M1_SG_LIST_PTR_ADDR0);
PRINT_LMIP_qword(asd_ha, lseq, M1_SG_LIST_PTR_ADDR1);
asd_printk("LSEQ%d MDP 1 MODE 2 >>>>\n", lseq);
PRINT_LMIP_dword(asd_ha, lseq, INVALID_DWORD_COUNT);
PRINT_LMIP_dword(asd_ha, lseq, DISPARITY_ERROR_COUNT);
PRINT_LMIP_dword(asd_ha, lseq, LOSS_OF_SYNC_COUNT);
asd_printk("LSEQ%d MDP 1 MODE 4/5 >>>>\n", lseq);
PRINT_LMIP_dword(asd_ha, lseq, FRAME_TYPE_MASK);
PRINT_LMIP_dword(asd_ha, lseq, HASHED_SRC_ADDR_MASK_PRINT);
PRINT_LMIP_byte(asd_ha, lseq, NUM_FILL_BYTES_MASK);
PRINT_LMIP_word(asd_ha, lseq, TAG_MASK);
PRINT_LMIP_word(asd_ha, lseq, TARGET_PORT_XFER_TAG);
PRINT_LMIP_dword(asd_ha, lseq, DATA_OFFSET);
asd_printk("LSEQ%d MDP 2 MODE 0 >>>>\n", lseq);
PRINT_LMIP_dword(asd_ha, lseq, SMP_RCV_TIMER_TERM_TS);
PRINT_LMIP_byte(asd_ha, lseq, DEVICE_BITS);
PRINT_LMIP_word(asd_ha, lseq, SDB_DDB);
PRINT_LMIP_word(asd_ha, lseq, SDB_NUM_TAGS);
PRINT_LMIP_word(asd_ha, lseq, SDB_CURR_TAG);
asd_printk("LSEQ%d MDP 2 MODE 1 >>>>\n", lseq);
PRINT_LMIP_qword(asd_ha, lseq, TX_ID_ADDR_FRAME);
PRINT_LMIP_dword(asd_ha, lseq, OPEN_TIMER_TERM_TS);
PRINT_LMIP_dword(asd_ha, lseq, SRST_AS_TIMER_TERM_TS);
PRINT_LMIP_dword(asd_ha, lseq, LAST_LOADED_SG_EL);
asd_printk("LSEQ%d MDP 2 MODE 2 >>>>\n", lseq);
PRINT_LMIP_dword(asd_ha, lseq, CLOSE_TIMER_TERM_TS);
PRINT_LMIP_dword(asd_ha, lseq, BREAK_TIMER_TERM_TS);
PRINT_LMIP_dword(asd_ha, lseq, DWS_RESET_TIMER_TERM_TS);
PRINT_LMIP_dword(asd_ha, lseq, SATA_INTERLOCK_TIMER_TERM_TS);
PRINT_LMIP_dword(asd_ha, lseq, MCTL_TIMER_TERM_TS);
asd_printk("LSEQ%d MDP 2 MODE 4/5 >>>>\n", lseq);
PRINT_LMIP_dword(asd_ha, lseq, COMINIT_TIMER_TERM_TS);
PRINT_LMIP_dword(asd_ha, lseq, RCV_ID_TIMER_TERM_TS);
PRINT_LMIP_dword(asd_ha, lseq, RCV_FIS_TIMER_TERM_TS);
PRINT_LMIP_dword(asd_ha, lseq, DEV_PRES_TIMER_TERM_TS);
}
void asd_dump_seq_state(struct asd_ha_struct *asd_ha, u8 lseq_mask)
{
int lseq;
asd_dump_cseq_state(asd_ha);
if (lseq_mask != 0)
for_each_sequencer(lseq_mask, lseq_mask, lseq)
asd_dump_lseq_state(asd_ha, lseq);
}
void asd_dump_frame_rcvd(struct asd_phy *phy,
struct done_list_struct *dl)
{
unsigned long flags;
int i;
switch ((dl->status_block[1] & 0x70) >> 3) {
case SAS_PROTOCOL_STP:
ASD_DPRINTK("STP proto device-to-host FIS:\n");
break;
default:
case SAS_PROTOCOL_SSP:
ASD_DPRINTK("SAS proto IDENTIFY:\n");
break;
}
spin_lock_irqsave(&phy->sas_phy.frame_rcvd_lock, flags);
for (i = 0; i < phy->sas_phy.frame_rcvd_size; i+=4)
ASD_DPRINTK("%02x: %02x %02x %02x %02x\n",
i,
phy->frame_rcvd[i],
phy->frame_rcvd[i+1],
phy->frame_rcvd[i+2],
phy->frame_rcvd[i+3]);
spin_unlock_irqrestore(&phy->sas_phy.frame_rcvd_lock, flags);
}
