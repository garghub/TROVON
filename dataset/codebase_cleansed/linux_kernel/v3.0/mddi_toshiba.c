static void mddi_toshiba_state_transition(mddi_toshiba_state_t a,
mddi_toshiba_state_t b)
{
if (toshiba_state != a) {
MDDI_MSG_ERR("toshiba state trans. (%d->%d) found %d\n", a, b,
toshiba_state);
}
toshiba_state = b;
}
void serigo(uint16 reg, uint8 data)
{
uint32 mddi_val = 0;
mddi_queue_register_read(SSIINTS, &mddi_val, TRUE, 0);
if (mddi_val & (1 << 8))
mddi_wait(1);
mddi_val = 0x90000 | ((0x00FF & reg) << 8) | data;
mddi_queue_register_write(SSITX, mddi_val, TRUE, 0);
}
void gordon_init(void)
{
serigo(GORDON_REG_IMGCTL2, 0x00);
serigo(GORDON_REG_IMGSET1, 0x01);
serigo(GORDON_REG_IMGSET2, 0x12);
serigo(GORDON_REG_LCDIFSET1, 0x00);
mddi_wait(2);
serigo(GORDON_REG_PCCTL, 0x09);
serigo(GORDON_REG_LCDIFCTL2, 0x1B);
mddi_wait(1);
}
void gordon_disp_on(void)
{
serigo(GORDON_REG_TPARAM1, 0x30);
serigo(GORDON_REG_TLCDIF1, 0x00);
serigo(GORDON_REG_TSSPB_ST1, 0x8B);
serigo(GORDON_REG_TSSPB_ED1, 0x93);
mddi_wait(2);
serigo(GORDON_REG_TSCK_ST1, 0x88);
serigo(GORDON_REG_TSCK_WD1, 0x00);
serigo(GORDON_REG_TGSPB_VST1, 0x01);
serigo(GORDON_REG_TGSPB_VED1, 0x02);
mddi_wait(2);
serigo(GORDON_REG_TGSPB_CH1, 0x5E);
serigo(GORDON_REG_TGCK_ST1, 0x80);
serigo(GORDON_REG_TGCK_ED1, 0x3C);
serigo(GORDON_REG_TPCTL_ST1, 0x50);
mddi_wait(2);
serigo(GORDON_REG_TPCTL_ED1, 0x74);
serigo(GORDON_REG_TPCHG_ED1, 0x78);
serigo(GORDON_REG_TCOM_CH1, 0x50);
serigo(GORDON_REG_THBP1, 0x84);
mddi_wait(2);
serigo(GORDON_REG_TPHCTL1, 0x00);
serigo(GORDON_REG_EVPH1, 0x70);
serigo(GORDON_REG_EVPL1, 0x64);
serigo(GORDON_REG_EVNH1, 0x56);
mddi_wait(2);
serigo(GORDON_REG_EVNL1, 0x48);
serigo(GORDON_REG_TBIAS1, 0x88);
mddi_wait(2);
serigo(GORDON_REG_TPARAM2, 0x28);
serigo(GORDON_REG_TLCDIF2, 0x14);
serigo(GORDON_REG_TSSPB_ST2, 0x49);
serigo(GORDON_REG_TSSPB_ED2, 0x4B);
mddi_wait(2);
serigo(GORDON_REG_TSCK_ST2, 0x4A);
serigo(GORDON_REG_TSCK_WD2, 0x02);
serigo(GORDON_REG_TGSPB_VST2, 0x02);
serigo(GORDON_REG_TGSPB_VED2, 0x03);
mddi_wait(2);
serigo(GORDON_REG_TGSPB_CH2, 0x2F);
serigo(GORDON_REG_TGCK_ST2, 0x40);
serigo(GORDON_REG_TGCK_ED2, 0x1E);
serigo(GORDON_REG_TPCTL_ST2, 0x2C);
mddi_wait(2);
serigo(GORDON_REG_TPCTL_ED2, 0x3A);
serigo(GORDON_REG_TPCHG_ED2, 0x3C);
serigo(GORDON_REG_TCOM_CH2, 0x28);
serigo(GORDON_REG_THBP2, 0x4D);
mddi_wait(2);
serigo(GORDON_REG_TPHCTL2, 0x1A);
mddi_wait(2);
serigo(GORDON_REG_IVBP1, 0x02);
serigo(GORDON_REG_IHBP1, 0x90);
serigo(GORDON_REG_IVNUM1, 0xA0);
serigo(GORDON_REG_IHNUM1, 0x78);
mddi_wait(2);
serigo(GORDON_REG_IVBP2, 0x02);
serigo(GORDON_REG_IHBP2, 0x48);
serigo(GORDON_REG_IVNUM2, 0x50);
serigo(GORDON_REG_IHNUM2, 0x3C);
mddi_wait(2);
serigo(GORDON_REG_POWCTL, 0x03);
mddi_wait(15);
serigo(GORDON_REG_POWCTL, 0x07);
mddi_wait(15);
serigo(GORDON_REG_POWCTL, 0x0F);
mddi_wait(15);
serigo(GORDON_REG_AVCTL, 0x03);
mddi_wait(15);
serigo(GORDON_REG_POWCTL, 0x1F);
mddi_wait(15);
serigo(GORDON_REG_POWCTL, 0x5F);
mddi_wait(15);
serigo(GORDON_REG_POWCTL, 0x7F);
mddi_wait(15);
serigo(GORDON_REG_LCDIFCTL1, 0x02);
mddi_wait(15);
serigo(GORDON_REG_IMGCTL1, 0x00);
mddi_wait(15);
serigo(GORDON_REG_LCDIFCTL3, 0x00);
mddi_wait(15);
serigo(GORDON_REG_VALTRAN, 0x01);
mddi_wait(15);
serigo(GORDON_REG_LCDIFCTL1, 0x03);
serigo(GORDON_REG_LCDIFCTL1, 0x03);
mddi_wait(1);
}
void gordon_disp_off(void)
{
serigo(GORDON_REG_LCDIFCTL2, 0x7B);
serigo(GORDON_REG_VALTRAN, 0x01);
serigo(GORDON_REG_LCDIFCTL1, 0x02);
serigo(GORDON_REG_LCDIFCTL3, 0x01);
mddi_wait(20);
serigo(GORDON_REG_VALTRAN, 0x01);
serigo(GORDON_REG_IMGCTL1, 0x01);
serigo(GORDON_REG_LCDIFCTL1, 0x00);
mddi_wait(20);
serigo(GORDON_REG_POWCTL, 0x1F);
mddi_wait(40);
serigo(GORDON_REG_POWCTL, 0x07);
mddi_wait(40);
serigo(GORDON_REG_POWCTL, 0x03);
mddi_wait(40);
serigo(GORDON_REG_POWCTL, 0x00);
mddi_wait(40);
}
void gordon_disp_init(void)
{
gordon_init();
mddi_wait(20);
gordon_disp_on();
}
static void toshiba_common_initial_setup(struct msm_fb_data_type *mfd)
{
if (TM_GET_PID(mfd->panel.id) == LCD_TOSHIBA_2P4_WVGA_PT) {
write_client_reg(DPSET0 , 0x4bec0066, TRUE);
write_client_reg(DPSET1 , 0x00000113, TRUE);
write_client_reg(DPSUS , 0x00000000, TRUE);
write_client_reg(DPRUN , 0x00000001, TRUE);
mddi_wait(5);
write_client_reg(SYSCKENA , 0x00000001, TRUE);
write_client_reg(CLKENB , 0x0000a0e9, TRUE);
write_client_reg(GPIODATA , 0x03FF0000, TRUE);
write_client_reg(GPIODIR , 0x0000024D, TRUE);
write_client_reg(GPIOSEL , 0x00000173, TRUE);
write_client_reg(GPIOPC , 0x03C300C0, TRUE);
write_client_reg(WKREQ , 0x00000000, TRUE);
write_client_reg(GPIOIS , 0x00000000, TRUE);
write_client_reg(GPIOIEV , 0x00000001, TRUE);
write_client_reg(GPIOIC , 0x000003FF, TRUE);
write_client_reg(GPIODATA , 0x00040004, TRUE);
write_client_reg(GPIODATA , 0x00080008, TRUE);
write_client_reg(DRAMPWR , 0x00000001, TRUE);
write_client_reg(CLKENB , 0x0000a0eb, TRUE);
write_client_reg(PWMCR , 0x00000000, TRUE);
mddi_wait(1);
write_client_reg(SSICTL , 0x00060399, TRUE);
write_client_reg(SSITIME , 0x00000100, TRUE);
write_client_reg(CNT_DIS , 0x00000002, TRUE);
write_client_reg(SSICTL , 0x0006039b, TRUE);
write_client_reg(SSITX , 0x00000000, TRUE);
mddi_wait(7);
write_client_reg(SSITX , 0x00000000, TRUE);
mddi_wait(7);
write_client_reg(SSITX , 0x00000000, TRUE);
mddi_wait(7);
write_client_reg(SSITX , 0x000800BA, TRUE);
write_client_reg(SSITX , 0x00000111, TRUE);
write_client_reg(SSITX , 0x00080036, TRUE);
write_client_reg(SSITX , 0x00000100, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x0008003A, TRUE);
write_client_reg(SSITX , 0x00000160, TRUE);
write_client_reg(SSITX , 0x000800B1, TRUE);
write_client_reg(SSITX , 0x0000015D, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800B2, TRUE);
write_client_reg(SSITX , 0x00000133, TRUE);
write_client_reg(SSITX , 0x000800B3, TRUE);
write_client_reg(SSITX , 0x00000122, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800B4, TRUE);
write_client_reg(SSITX , 0x00000102, TRUE);
write_client_reg(SSITX , 0x000800B5, TRUE);
write_client_reg(SSITX , 0x0000011E, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800B6, TRUE);
write_client_reg(SSITX , 0x00000127, TRUE);
write_client_reg(SSITX , 0x000800B7, TRUE);
write_client_reg(SSITX , 0x00000103, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800B9, TRUE);
write_client_reg(SSITX , 0x00000124, TRUE);
write_client_reg(SSITX , 0x000800BD, TRUE);
write_client_reg(SSITX , 0x000001A1, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800BB, TRUE);
write_client_reg(SSITX , 0x00000100, TRUE);
write_client_reg(SSITX , 0x000800BF, TRUE);
write_client_reg(SSITX , 0x00000101, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800BE, TRUE);
write_client_reg(SSITX , 0x00000100, TRUE);
write_client_reg(SSITX , 0x000800C0, TRUE);
write_client_reg(SSITX , 0x00000111, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800C1, TRUE);
write_client_reg(SSITX , 0x00000111, TRUE);
write_client_reg(SSITX , 0x000800C2, TRUE);
write_client_reg(SSITX , 0x00000111, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800C3, TRUE);
write_client_reg(SSITX , 0x00080132, TRUE);
write_client_reg(SSITX , 0x00000132, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800C4, TRUE);
write_client_reg(SSITX , 0x00080132, TRUE);
write_client_reg(SSITX , 0x00000132, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800C5, TRUE);
write_client_reg(SSITX , 0x00080132, TRUE);
write_client_reg(SSITX , 0x00000132, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800C6, TRUE);
write_client_reg(SSITX , 0x00080132, TRUE);
write_client_reg(SSITX , 0x00000132, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800C7, TRUE);
write_client_reg(SSITX , 0x00080164, TRUE);
write_client_reg(SSITX , 0x00000145, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800C8, TRUE);
write_client_reg(SSITX , 0x00000144, TRUE);
write_client_reg(SSITX , 0x000800C9, TRUE);
write_client_reg(SSITX , 0x00000152, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800CA, TRUE);
write_client_reg(SSITX , 0x00000100, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800EC, TRUE);
write_client_reg(SSITX , 0x00080101, TRUE);
write_client_reg(SSITX , 0x000001FC, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800CF, TRUE);
write_client_reg(SSITX , 0x00000101, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800D0, TRUE);
write_client_reg(SSITX , 0x00080110, TRUE);
write_client_reg(SSITX , 0x00000104, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800D1, TRUE);
write_client_reg(SSITX , 0x00000101, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800D2, TRUE);
write_client_reg(SSITX , 0x00080100, TRUE);
write_client_reg(SSITX , 0x00000128, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800D3, TRUE);
write_client_reg(SSITX , 0x00080100, TRUE);
write_client_reg(SSITX , 0x00000128, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800D4, TRUE);
write_client_reg(SSITX , 0x00080126, TRUE);
write_client_reg(SSITX , 0x000001A4, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800D5, TRUE);
write_client_reg(SSITX , 0x00000120, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800EF, TRUE);
write_client_reg(SSITX , 0x00080132, TRUE);
write_client_reg(SSITX , 0x00000100, TRUE);
mddi_wait(1);
write_client_reg(BITMAP0 , 0x032001E0, TRUE);
write_client_reg(BITMAP1 , 0x032001E0, TRUE);
write_client_reg(BITMAP2 , 0x014000F0, TRUE);
write_client_reg(BITMAP3 , 0x014000F0, TRUE);
write_client_reg(BITMAP4 , 0x014000F0, TRUE);
write_client_reg(CLKENB , 0x0000A1EB, TRUE);
write_client_reg(PORT_ENB , 0x00000001, TRUE);
write_client_reg(PORT , 0x00000004, TRUE);
write_client_reg(PXL , 0x00000002, TRUE);
write_client_reg(MPLFBUF , 0x00000000, TRUE);
write_client_reg(HCYCLE , 0x000000FD, TRUE);
write_client_reg(HSW , 0x00000003, TRUE);
write_client_reg(HDE_START , 0x00000007, TRUE);
write_client_reg(HDE_SIZE , 0x000000EF, TRUE);
write_client_reg(VCYCLE , 0x00000325, TRUE);
write_client_reg(VSW , 0x00000001, TRUE);
write_client_reg(VDE_START , 0x00000003, TRUE);
write_client_reg(VDE_SIZE , 0x0000031F, TRUE);
write_client_reg(START , 0x00000001, TRUE);
mddi_wait(32);
write_client_reg(SSITX , 0x000800BC, TRUE);
write_client_reg(SSITX , 0x00000180, TRUE);
write_client_reg(SSITX , 0x0008003B, TRUE);
write_client_reg(SSITX , 0x00000100, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800B0, TRUE);
write_client_reg(SSITX , 0x00000116, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x000800B8, TRUE);
write_client_reg(SSITX , 0x000801FF, TRUE);
write_client_reg(SSITX , 0x000001F5, TRUE);
mddi_wait(1);
write_client_reg(SSITX , 0x00000011, TRUE);
mddi_wait(5);
write_client_reg(SSITX , 0x00000029, TRUE);
return;
}
if (TM_GET_PID(mfd->panel.id) == LCD_SHARP_2P4_VGA) {
write_client_reg(DPSET0, 0x4BEC0066, TRUE);
write_client_reg(DPSET1, 0x00000113, TRUE);
write_client_reg(DPSUS, 0x00000000, TRUE);
write_client_reg(DPRUN, 0x00000001, TRUE);
mddi_wait(14);
write_client_reg(SYSCKENA, 0x00000001, TRUE);
write_client_reg(CLKENB, 0x000000EF, TRUE);
write_client_reg(GPIO_BLOCK_BASE, 0x03FF0000, TRUE);
write_client_reg(GPIODIR, 0x0000024D, TRUE);
write_client_reg(SYSTEM_BLOCK2_BASE, 0x00000173, TRUE);
write_client_reg(GPIOPC, 0x03C300C0, TRUE);
write_client_reg(SYSTEM_BLOCK1_BASE, 0x00000000, TRUE);
write_client_reg(GPIOIS, 0x00000000, TRUE);
write_client_reg(GPIOIEV, 0x00000001, TRUE);
write_client_reg(GPIOIC, 0x000003FF, TRUE);
write_client_reg(GPIO_BLOCK_BASE, 0x00060006, TRUE);
write_client_reg(GPIO_BLOCK_BASE, 0x00080008, TRUE);
write_client_reg(GPIO_BLOCK_BASE, 0x02000200, TRUE);
write_client_reg(DRAMPWR, 0x00000001, TRUE);
write_client_reg(TIMER0CTRL, 0x00000060, TRUE);
write_client_reg(PWM_BLOCK_BASE, 0x00001388, TRUE);
write_client_reg(PWM0OFF, 0x00001387, TRUE);
write_client_reg(TIMER1CTRL, 0x00000060, TRUE);
write_client_reg(TIMER1LOAD, 0x00001388, TRUE);
write_client_reg(PWM1OFF, 0x00001387, TRUE);
write_client_reg(TIMER0CTRL, 0x000000E0, TRUE);
write_client_reg(TIMER1CTRL, 0x000000E0, TRUE);
write_client_reg(PWMCR, 0x00000003, TRUE);
mddi_wait(1);
write_client_reg(SPI_BLOCK_BASE, 0x00063111, TRUE);
write_client_reg(SSITIME, 0x00000100, TRUE);
write_client_reg(SPI_BLOCK_BASE, 0x00063113, TRUE);
mddi_wait(1);
write_client_reg(SSITX, 0x00000000, TRUE);
mddi_wait(1);
write_client_reg(SSITX, 0x00000000, TRUE);
mddi_wait(1);
write_client_reg(SSITX, 0x00000000, TRUE);
mddi_wait(1);
write_client_reg(CLKENB, 0x0000A1EF, TRUE);
write_client_reg(START, 0x00000000, TRUE);
write_client_reg(WRSTB, 0x0000003F, TRUE);
write_client_reg(RDSTB, 0x00000432, TRUE);
write_client_reg(PORT_ENB, 0x00000002, TRUE);
write_client_reg(VSYNIF, 0x00000000, TRUE);
write_client_reg(ASY_DATA, 0x80000000, TRUE);
write_client_reg(ASY_DATB, 0x00000001, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(10);
write_client_reg(ASY_DATA, 0x80000000, TRUE);
write_client_reg(ASY_DATB, 0x80000000, TRUE);
write_client_reg(ASY_DATC, 0x80000000, TRUE);
write_client_reg(ASY_DATD, 0x80000000, TRUE);
write_client_reg(ASY_CMDSET, 0x00000009, TRUE);
write_client_reg(ASY_CMDSET, 0x00000008, TRUE);
write_client_reg(ASY_DATA, 0x80000007, TRUE);
write_client_reg(ASY_DATB, 0x00004005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(20);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x00000000, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
write_client_reg(VSYNIF, 0x00000001, TRUE);
write_client_reg(PORT_ENB, 0x00000001, TRUE);
} else {
write_client_reg(DPSET0, 0x4BEC0066, TRUE);
write_client_reg(DPSET1, 0x00000113, TRUE);
write_client_reg(DPSUS, 0x00000000, TRUE);
write_client_reg(DPRUN, 0x00000001, TRUE);
mddi_wait(14);
write_client_reg(SYSCKENA, 0x00000001, TRUE);
write_client_reg(CLKENB, 0x000000EF, TRUE);
write_client_reg(GPIODATA, 0x03FF0000, TRUE);
write_client_reg(GPIODIR, 0x0000024D, TRUE);
write_client_reg(GPIOSEL, 0x00000173, TRUE);
write_client_reg(GPIOPC, 0x03C300C0, TRUE);
write_client_reg(WKREQ, 0x00000000, TRUE);
write_client_reg(GPIOIS, 0x00000000, TRUE);
write_client_reg(GPIOIEV, 0x00000001, TRUE);
write_client_reg(GPIOIC, 0x000003FF, TRUE);
write_client_reg(GPIODATA, 0x00060006, TRUE);
write_client_reg(GPIODATA, 0x00080008, TRUE);
write_client_reg(GPIODATA, 0x02000200, TRUE);
if (TM_GET_PID(mfd->panel.id) == LCD_TOSHIBA_2P4_WVGA) {
mddi_wait(400);
write_client_reg(DRAMPWR, 0x00000001, TRUE);
write_client_reg(CNT_DIS, 0x00000002, TRUE);
write_client_reg(BITMAP0, 0x01E00320, TRUE);
write_client_reg(PORT_ENB, 0x00000001, TRUE);
write_client_reg(PORT, 0x00000004, TRUE);
write_client_reg(PXL, 0x0000003A, TRUE);
write_client_reg(MPLFBUF, 0x00000000, TRUE);
write_client_reg(HCYCLE, 0x00000253, TRUE);
write_client_reg(HSW, 0x00000003, TRUE);
write_client_reg(HDE_START, 0x00000017, TRUE);
write_client_reg(HDE_SIZE, 0x0000018F, TRUE);
write_client_reg(VCYCLE, 0x000001FF, TRUE);
write_client_reg(VSW, 0x00000001, TRUE);
write_client_reg(VDE_START, 0x00000003, TRUE);
write_client_reg(VDE_SIZE, 0x000001DF, TRUE);
write_client_reg(START, 0x00000001, TRUE);
mddi_wait(1);
write_client_reg(TIMER0CTRL, 0x00000060, TRUE);
write_client_reg(TIMER0LOAD, 0x00001388, TRUE);
write_client_reg(TIMER1CTRL, 0x00000060, TRUE);
write_client_reg(TIMER1LOAD, 0x00001388, TRUE);
write_client_reg(PWM1OFF, 0x00000087, TRUE);
} else {
write_client_reg(DRAMPWR, 0x00000001, TRUE);
write_client_reg(TIMER0CTRL, 0x00000060, TRUE);
write_client_reg(TIMER0LOAD, 0x00001388, TRUE);
write_client_reg(TIMER1CTRL, 0x00000060, TRUE);
write_client_reg(TIMER1LOAD, 0x00001388, TRUE);
write_client_reg(PWM1OFF, 0x00001387, TRUE);
}
write_client_reg(TIMER0CTRL, 0x000000E0, TRUE);
write_client_reg(TIMER1CTRL, 0x000000E0, TRUE);
write_client_reg(PWMCR, 0x00000003, TRUE);
mddi_wait(1);
write_client_reg(SSICTL, 0x00000799, TRUE);
write_client_reg(SSITIME, 0x00000100, TRUE);
write_client_reg(SSICTL, 0x0000079b, TRUE);
write_client_reg(SSITX, 0x00000000, TRUE);
mddi_wait(1);
write_client_reg(SSITX, 0x00000000, TRUE);
mddi_wait(1);
write_client_reg(SSITX, 0x00000000, TRUE);
mddi_wait(1);
write_client_reg(SSITX, 0x000800BA, TRUE);
write_client_reg(SSITX, 0x00000111, TRUE);
write_client_reg(SSITX, 0x00080036, TRUE);
write_client_reg(SSITX, 0x00000100, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800BB, TRUE);
write_client_reg(SSITX, 0x00000100, TRUE);
write_client_reg(SSITX, 0x0008003A, TRUE);
write_client_reg(SSITX, 0x00000160, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800BF, TRUE);
write_client_reg(SSITX, 0x00000100, TRUE);
write_client_reg(SSITX, 0x000800B1, TRUE);
write_client_reg(SSITX, 0x0000015D, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800B2, TRUE);
write_client_reg(SSITX, 0x00000133, TRUE);
write_client_reg(SSITX, 0x000800B3, TRUE);
write_client_reg(SSITX, 0x00000122, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800B4, TRUE);
write_client_reg(SSITX, 0x00000102, TRUE);
write_client_reg(SSITX, 0x000800B5, TRUE);
write_client_reg(SSITX, 0x0000011F, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800B6, TRUE);
write_client_reg(SSITX, 0x00000128, TRUE);
write_client_reg(SSITX, 0x000800B7, TRUE);
write_client_reg(SSITX, 0x00000103, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800B9, TRUE);
write_client_reg(SSITX, 0x00000120, TRUE);
write_client_reg(SSITX, 0x000800BD, TRUE);
write_client_reg(SSITX, 0x00000102, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800BE, TRUE);
write_client_reg(SSITX, 0x00000100, TRUE);
write_client_reg(SSITX, 0x000800C0, TRUE);
write_client_reg(SSITX, 0x00000111, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800C1, TRUE);
write_client_reg(SSITX, 0x00000111, TRUE);
write_client_reg(SSITX, 0x000800C2, TRUE);
write_client_reg(SSITX, 0x00000111, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800C3, TRUE);
write_client_reg(SSITX, 0x0008010A, TRUE);
write_client_reg(SSITX, 0x0000010A, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800C4, TRUE);
write_client_reg(SSITX, 0x00080160, TRUE);
write_client_reg(SSITX, 0x00000160, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800C5, TRUE);
write_client_reg(SSITX, 0x00080160, TRUE);
write_client_reg(SSITX, 0x00000160, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800C6, TRUE);
write_client_reg(SSITX, 0x00080160, TRUE);
write_client_reg(SSITX, 0x00000160, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800C7, TRUE);
write_client_reg(SSITX, 0x00080133, TRUE);
write_client_reg(SSITX, 0x00000143, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800C8, TRUE);
write_client_reg(SSITX, 0x00000144, TRUE);
write_client_reg(SSITX, 0x000800C9, TRUE);
write_client_reg(SSITX, 0x00000133, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800CA, TRUE);
write_client_reg(SSITX, 0x00000100, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800EC, TRUE);
write_client_reg(SSITX, 0x00080102, TRUE);
write_client_reg(SSITX, 0x00000118, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800CF, TRUE);
write_client_reg(SSITX, 0x00000101, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800D0, TRUE);
write_client_reg(SSITX, 0x00080110, TRUE);
write_client_reg(SSITX, 0x00000104, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800D1, TRUE);
write_client_reg(SSITX, 0x00000101, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800D2, TRUE);
write_client_reg(SSITX, 0x00080100, TRUE);
write_client_reg(SSITX, 0x0000013A, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800D3, TRUE);
write_client_reg(SSITX, 0x00080100, TRUE);
write_client_reg(SSITX, 0x0000013A, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800D4, TRUE);
write_client_reg(SSITX, 0x00080124, TRUE);
write_client_reg(SSITX, 0x0000016E, TRUE);
mddi_wait(1);
write_client_reg(SSITX, 0x000800D5, TRUE);
write_client_reg(SSITX, 0x00000124, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800ED, TRUE);
write_client_reg(SSITX, 0x00080101, TRUE);
write_client_reg(SSITX, 0x0000010A, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800D6, TRUE);
write_client_reg(SSITX, 0x00000101, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800D7, TRUE);
write_client_reg(SSITX, 0x00080110, TRUE);
write_client_reg(SSITX, 0x0000010A, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800D8, TRUE);
write_client_reg(SSITX, 0x00000101, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800D9, TRUE);
write_client_reg(SSITX, 0x00080100, TRUE);
write_client_reg(SSITX, 0x00000114, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800DE, TRUE);
write_client_reg(SSITX, 0x00080100, TRUE);
write_client_reg(SSITX, 0x00000114, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800DF, TRUE);
write_client_reg(SSITX, 0x00080112, TRUE);
write_client_reg(SSITX, 0x0000013F, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800E0, TRUE);
write_client_reg(SSITX, 0x0000010B, TRUE);
write_client_reg(SSITX, 0x000800E2, TRUE);
write_client_reg(SSITX, 0x00000101, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800E3, TRUE);
write_client_reg(SSITX, 0x00000136, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800E4, TRUE);
write_client_reg(SSITX, 0x00080100, TRUE);
write_client_reg(SSITX, 0x00000103, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800E5, TRUE);
write_client_reg(SSITX, 0x00080102, TRUE);
write_client_reg(SSITX, 0x00000104, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800E6, TRUE);
write_client_reg(SSITX, 0x00000103, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800E7, TRUE);
write_client_reg(SSITX, 0x00080104, TRUE);
write_client_reg(SSITX, 0x0000010A, TRUE);
mddi_wait(2);
write_client_reg(SSITX, 0x000800E8, TRUE);
write_client_reg(SSITX, 0x00000104, TRUE);
write_client_reg(CLKENB, 0x000001EF, TRUE);
write_client_reg(START, 0x00000000, TRUE);
write_client_reg(WRSTB, 0x0000003F, TRUE);
write_client_reg(RDSTB, 0x00000432, TRUE);
write_client_reg(PORT_ENB, 0x00000002, TRUE);
write_client_reg(VSYNIF, 0x00000000, TRUE);
write_client_reg(ASY_DATA, 0x80000000, TRUE);
write_client_reg(ASY_DATB, 0x00000001, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(10);
write_client_reg(ASY_DATA, 0x80000000, TRUE);
write_client_reg(ASY_DATB, 0x80000000, TRUE);
write_client_reg(ASY_DATC, 0x80000000, TRUE);
write_client_reg(ASY_DATD, 0x80000000, TRUE);
write_client_reg(ASY_CMDSET, 0x00000009, TRUE);
write_client_reg(ASY_CMDSET, 0x00000008, TRUE);
write_client_reg(ASY_DATA, 0x80000007, TRUE);
write_client_reg(ASY_DATB, 0x00004005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(20);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x00000000, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
write_client_reg(VSYNIF, 0x00000001, TRUE);
write_client_reg(PORT_ENB, 0x00000001, TRUE);
}
mddi_toshiba_state_transition(TOSHIBA_STATE_PRIM_SEC_STANDBY,
TOSHIBA_STATE_PRIM_SEC_READY);
}
static void toshiba_prim_start(struct msm_fb_data_type *mfd)
{
if (TM_GET_PID(mfd->panel.id) == LCD_TOSHIBA_2P4_WVGA_PT)
return;
if (TM_GET_PID(mfd->panel.id) == LCD_SHARP_2P4_VGA) {
write_client_reg(BITMAP1, 0x01E000F0, TRUE);
write_client_reg(BITMAP2, 0x01E000F0, TRUE);
write_client_reg(BITMAP3, 0x01E000F0, TRUE);
write_client_reg(BITMAP4, 0x00DC00B0, TRUE);
write_client_reg(CLKENB, 0x000001EF, TRUE);
write_client_reg(PORT_ENB, 0x00000001, TRUE);
write_client_reg(PORT, 0x00000016, TRUE);
write_client_reg(PXL, 0x00000002, TRUE);
write_client_reg(MPLFBUF, 0x00000000, TRUE);
write_client_reg(HCYCLE, 0x00000185, TRUE);
write_client_reg(HSW, 0x00000018, TRUE);
write_client_reg(HDE_START, 0x0000004A, TRUE);
write_client_reg(HDE_SIZE, 0x000000EF, TRUE);
write_client_reg(VCYCLE, 0x0000028E, TRUE);
write_client_reg(VSW, 0x00000004, TRUE);
write_client_reg(VDE_START, 0x00000009, TRUE);
write_client_reg(VDE_SIZE, 0x0000027F, TRUE);
write_client_reg(START, 0x00000001, TRUE);
write_client_reg(SYSTEM_BLOCK1_BASE, 0x00000002, TRUE);
} else{
write_client_reg(VSYNIF, 0x00000001, TRUE);
write_client_reg(PORT_ENB, 0x00000001, TRUE);
write_client_reg(BITMAP1, 0x01E000F0, TRUE);
write_client_reg(BITMAP2, 0x01E000F0, TRUE);
write_client_reg(BITMAP3, 0x01E000F0, TRUE);
write_client_reg(BITMAP4, 0x00DC00B0, TRUE);
write_client_reg(CLKENB, 0x000001EF, TRUE);
write_client_reg(PORT_ENB, 0x00000001, TRUE);
write_client_reg(PORT, 0x00000004, TRUE);
write_client_reg(PXL, 0x00000002, TRUE);
write_client_reg(MPLFBUF, 0x00000000, TRUE);
if (mddi_toshiba_61Hz_refresh) {
write_client_reg(HCYCLE, 0x000000FC, TRUE);
mddi_toshiba_rows_per_second = 39526;
mddi_toshiba_rows_per_refresh = 646;
mddi_toshiba_usecs_per_refresh = 16344;
} else {
write_client_reg(HCYCLE, 0x0000010b, TRUE);
mddi_toshiba_rows_per_second = 37313;
mddi_toshiba_rows_per_refresh = 646;
mddi_toshiba_usecs_per_refresh = 17313;
}
write_client_reg(HSW, 0x00000003, TRUE);
write_client_reg(HDE_START, 0x00000007, TRUE);
write_client_reg(HDE_SIZE, 0x000000EF, TRUE);
write_client_reg(VCYCLE, 0x00000285, TRUE);
write_client_reg(VSW, 0x00000001, TRUE);
write_client_reg(VDE_START, 0x00000003, TRUE);
write_client_reg(VDE_SIZE, 0x0000027F, TRUE);
write_client_reg(START, 0x00000001, TRUE);
mddi_wait(10);
write_client_reg(SSITX, 0x000800BC, TRUE);
write_client_reg(SSITX, 0x00000180, TRUE);
write_client_reg(SSITX, 0x0008003B, TRUE);
write_client_reg(SSITX, 0x00000100, TRUE);
mddi_wait(1);
write_client_reg(SSITX, 0x000800B0, TRUE);
write_client_reg(SSITX, 0x00000116, TRUE);
mddi_wait(1);
write_client_reg(SSITX, 0x000800B8, TRUE);
write_client_reg(SSITX, 0x000801FF, TRUE);
write_client_reg(SSITX, 0x000001F5, TRUE);
mddi_wait(1);
write_client_reg(SSITX, 0x00000011, TRUE);
write_client_reg(SSITX, 0x00000029, TRUE);
write_client_reg(WKREQ, 0x00000000, TRUE);
write_client_reg(WAKEUP, 0x00000000, TRUE);
write_client_reg(INTMSK, 0x00000001, TRUE);
}
mddi_toshiba_state_transition(TOSHIBA_STATE_PRIM_SEC_READY,
TOSHIBA_STATE_PRIM_NORMAL_MODE);
}
static void toshiba_sec_start(struct msm_fb_data_type *mfd)
{
if (TM_GET_PID(mfd->panel.id) == LCD_TOSHIBA_2P4_WVGA_PT)
return;
write_client_reg(VSYNIF, 0x00000000, TRUE);
write_client_reg(PORT_ENB, 0x00000002, TRUE);
write_client_reg(CLKENB, 0x000011EF, TRUE);
write_client_reg(BITMAP0, 0x028001E0, TRUE);
write_client_reg(BITMAP1, 0x00000000, TRUE);
write_client_reg(BITMAP2, 0x00000000, TRUE);
write_client_reg(BITMAP3, 0x00000000, TRUE);
write_client_reg(BITMAP4, 0x00DC00B0, TRUE);
write_client_reg(PORT, 0x00000000, TRUE);
write_client_reg(PXL, 0x00000000, TRUE);
write_client_reg(MPLFBUF, 0x00000004, TRUE);
write_client_reg(HCYCLE, 0x0000006B, TRUE);
write_client_reg(HSW, 0x00000003, TRUE);
write_client_reg(HDE_START, 0x00000007, TRUE);
write_client_reg(HDE_SIZE, 0x00000057, TRUE);
write_client_reg(VCYCLE, 0x000000E6, TRUE);
write_client_reg(VSW, 0x00000001, TRUE);
write_client_reg(VDE_START, 0x00000003, TRUE);
write_client_reg(VDE_SIZE, 0x000000DB, TRUE);
write_client_reg(ASY_DATA, 0x80000001, TRUE);
write_client_reg(ASY_DATB, 0x0000011B, TRUE);
write_client_reg(ASY_DATC, 0x80000002, TRUE);
write_client_reg(ASY_DATD, 0x00000700, TRUE);
write_client_reg(ASY_DATE, 0x80000003, TRUE);
write_client_reg(ASY_DATF, 0x00000230, TRUE);
write_client_reg(ASY_DATG, 0x80000008, TRUE);
write_client_reg(ASY_DATH, 0x00000402, TRUE);
write_client_reg(ASY_CMDSET, 0x00000001, TRUE);
write_client_reg(ASY_CMDSET, 0x00000000, TRUE);
write_client_reg(ASY_DATA, 0x80000009, TRUE);
write_client_reg(ASY_DATB, 0x00000000, TRUE);
write_client_reg(ASY_DATC, 0x8000000B, TRUE);
write_client_reg(ASY_DATD, 0x00000000, TRUE);
write_client_reg(ASY_DATE, 0x8000000C, TRUE);
write_client_reg(ASY_DATF, 0x00000000, TRUE);
write_client_reg(ASY_DATG, 0x8000000D, TRUE);
write_client_reg(ASY_DATH, 0x00000409, TRUE);
write_client_reg(ASY_CMDSET, 0x00000001, TRUE);
write_client_reg(ASY_CMDSET, 0x00000000, TRUE);
write_client_reg(ASY_DATA, 0x8000000E, TRUE);
write_client_reg(ASY_DATB, 0x00000409, TRUE);
write_client_reg(ASY_DATC, 0x80000030, TRUE);
write_client_reg(ASY_DATD, 0x00000000, TRUE);
write_client_reg(ASY_DATE, 0x80000031, TRUE);
write_client_reg(ASY_DATF, 0x00000100, TRUE);
write_client_reg(ASY_DATG, 0x80000032, TRUE);
write_client_reg(ASY_DATH, 0x00000104, TRUE);
write_client_reg(ASY_CMDSET, 0x00000001, TRUE);
write_client_reg(ASY_CMDSET, 0x00000000, TRUE);
write_client_reg(ASY_DATA, 0x80000033, TRUE);
write_client_reg(ASY_DATB, 0x00000400, TRUE);
write_client_reg(ASY_DATC, 0x80000034, TRUE);
write_client_reg(ASY_DATD, 0x00000306, TRUE);
write_client_reg(ASY_DATE, 0x80000035, TRUE);
write_client_reg(ASY_DATF, 0x00000706, TRUE);
write_client_reg(ASY_DATG, 0x80000036, TRUE);
write_client_reg(ASY_DATH, 0x00000707, TRUE);
write_client_reg(ASY_CMDSET, 0x00000001, TRUE);
write_client_reg(ASY_CMDSET, 0x00000000, TRUE);
write_client_reg(ASY_DATA, 0x80000037, TRUE);
write_client_reg(ASY_DATB, 0x00000004, TRUE);
write_client_reg(ASY_DATC, 0x80000038, TRUE);
write_client_reg(ASY_DATD, 0x00000000, TRUE);
write_client_reg(ASY_DATE, 0x80000039, TRUE);
write_client_reg(ASY_DATF, 0x00000000, TRUE);
write_client_reg(ASY_DATG, 0x8000003A, TRUE);
write_client_reg(ASY_DATH, 0x00000001, TRUE);
write_client_reg(ASY_CMDSET, 0x00000001, TRUE);
write_client_reg(ASY_CMDSET, 0x00000000, TRUE);
write_client_reg(ASY_DATA, 0x80000044, TRUE);
write_client_reg(ASY_DATB, 0x0000AF00, TRUE);
write_client_reg(ASY_DATC, 0x80000045, TRUE);
write_client_reg(ASY_DATD, 0x0000DB00, TRUE);
write_client_reg(ASY_DATE, 0x08000042, TRUE);
write_client_reg(ASY_DATF, 0x0000DB00, TRUE);
write_client_reg(ASY_DATG, 0x80000021, TRUE);
write_client_reg(ASY_DATH, 0x00000000, TRUE);
write_client_reg(ASY_CMDSET, 0x00000001, TRUE);
write_client_reg(ASY_CMDSET, 0x00000000, TRUE);
write_client_reg(PXL, 0x0000000C, TRUE);
write_client_reg(VSYNIF, 0x00000001, TRUE);
write_client_reg(ASY_DATA, 0x80000022, TRUE);
write_client_reg(ASY_CMDSET, 0x00000003, TRUE);
write_client_reg(START, 0x00000001, TRUE);
mddi_wait(60);
write_client_reg(PXL, 0x00000000, TRUE);
write_client_reg(VSYNIF, 0x00000000, TRUE);
write_client_reg(START, 0x00000000, TRUE);
write_client_reg(ASY_CMDSET, 0x00000000, TRUE);
write_client_reg(ASY_DATA, 0x80000050, TRUE);
write_client_reg(ASY_DATB, 0x00000000, TRUE);
write_client_reg(ASY_DATC, 0x80000051, TRUE);
write_client_reg(ASY_DATD, 0x00000E00, TRUE);
write_client_reg(ASY_DATE, 0x80000052, TRUE);
write_client_reg(ASY_DATF, 0x00000D01, TRUE);
write_client_reg(ASY_DATG, 0x80000053, TRUE);
write_client_reg(ASY_DATH, 0x00000000, TRUE);
write_client_reg(ASY_CMDSET, 0x00000001, TRUE);
write_client_reg(ASY_CMDSET, 0x00000000, TRUE);
write_client_reg(ASY_DATA, 0x80000058, TRUE);
write_client_reg(ASY_DATB, 0x00000000, TRUE);
write_client_reg(ASY_DATC, 0x8000005A, TRUE);
write_client_reg(ASY_DATD, 0x00000E01, TRUE);
write_client_reg(ASY_CMDSET, 0x00000009, TRUE);
write_client_reg(ASY_CMDSET, 0x00000008, TRUE);
write_client_reg(ASY_DATA, 0x80000011, TRUE);
write_client_reg(ASY_DATB, 0x00000812, TRUE);
write_client_reg(ASY_DATC, 0x80000012, TRUE);
write_client_reg(ASY_DATD, 0x00000003, TRUE);
write_client_reg(ASY_DATE, 0x80000013, TRUE);
write_client_reg(ASY_DATF, 0x00000909, TRUE);
write_client_reg(ASY_DATG, 0x80000010, TRUE);
write_client_reg(ASY_DATH, 0x00000040, TRUE);
write_client_reg(ASY_CMDSET, 0x00000001, TRUE);
write_client_reg(ASY_CMDSET, 0x00000000, TRUE);
mddi_wait(40);
write_client_reg(ASY_DATA, 0x80000010, TRUE);
write_client_reg(ASY_DATB, 0x00000340, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(60);
write_client_reg(ASY_DATA, 0x80000010, TRUE);
write_client_reg(ASY_DATB, 0x00003340, TRUE);
write_client_reg(ASY_DATC, 0x80000007, TRUE);
write_client_reg(ASY_DATD, 0x00004007, TRUE);
write_client_reg(ASY_CMDSET, 0x00000009, TRUE);
write_client_reg(ASY_CMDSET, 0x00000008, TRUE);
mddi_wait(1);
write_client_reg(ASY_DATA, 0x80000007, TRUE);
write_client_reg(ASY_DATB, 0x00004017, TRUE);
write_client_reg(ASY_DATC, 0x8000005B, TRUE);
write_client_reg(ASY_DATD, 0x00000000, TRUE);
write_client_reg(ASY_DATE, 0x80000059, TRUE);
write_client_reg(ASY_DATF, 0x00000011, TRUE);
write_client_reg(ASY_CMDSET, 0x0000000D, TRUE);
write_client_reg(ASY_CMDSET, 0x0000000C, TRUE);
mddi_wait(20);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x00000019, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(20);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x00000079, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(20);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x000003FD, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(20);
mddi_toshiba_state_transition(TOSHIBA_STATE_PRIM_SEC_READY,
TOSHIBA_STATE_SEC_NORMAL_MODE);
}
static void toshiba_prim_lcd_off(struct msm_fb_data_type *mfd)
{
if (TM_GET_PID(mfd->panel.id) == LCD_SHARP_2P4_VGA) {
gordon_disp_off();
} else{
write_client_reg(SSITX, 0x000800BC, TRUE);
write_client_reg(SSITX, 0x00000100, TRUE);
write_client_reg(SSITX, 0x00000028, TRUE);
mddi_wait(1);
write_client_reg(SSITX, 0x000800B8, TRUE);
write_client_reg(SSITX, 0x00000180, TRUE);
write_client_reg(SSITX, 0x00000102, TRUE);
write_client_reg(SSITX, 0x00000010, TRUE);
}
write_client_reg(PORT, 0x00000003, TRUE);
write_client_reg(REGENB, 0x00000001, TRUE);
mddi_wait(1);
write_client_reg(PXL, 0x00000000, TRUE);
write_client_reg(START, 0x00000000, TRUE);
write_client_reg(REGENB, 0x00000001, TRUE);
mddi_wait(3);
if (TM_GET_PID(mfd->panel.id) != LCD_SHARP_2P4_VGA) {
write_client_reg(SSITX, 0x000800B0, TRUE);
write_client_reg(SSITX, 0x00000100, TRUE);
}
mddi_toshiba_state_transition(TOSHIBA_STATE_PRIM_NORMAL_MODE,
TOSHIBA_STATE_PRIM_SEC_STANDBY);
}
static void toshiba_sec_lcd_off(struct msm_fb_data_type *mfd)
{
if (TM_GET_PID(mfd->panel.id) == LCD_TOSHIBA_2P4_WVGA_PT)
return;
write_client_reg(VSYNIF, 0x00000000, TRUE);
write_client_reg(PORT_ENB, 0x00000002, TRUE);
write_client_reg(ASY_DATA, 0x80000007, TRUE);
write_client_reg(ASY_DATB, 0x00004016, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(2);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x00000019, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(2);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x0000000B, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(2);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x00000002, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(4);
write_client_reg(ASY_DATA, 0x80000010, TRUE);
write_client_reg(ASY_DATB, 0x00000300, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(4);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x00000000, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(2);
write_client_reg(ASY_DATA, 0x80000007, TRUE);
write_client_reg(ASY_DATB, 0x00004004, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(2);
write_client_reg(PORT, 0x00000000, TRUE);
write_client_reg(PXL, 0x00000000, TRUE);
write_client_reg(START, 0x00000000, TRUE);
write_client_reg(VSYNIF, 0x00000001, TRUE);
write_client_reg(PORT_ENB, 0x00000001, TRUE);
write_client_reg(REGENB, 0x00000001, TRUE);
mddi_toshiba_state_transition(TOSHIBA_STATE_SEC_NORMAL_MODE,
TOSHIBA_STATE_PRIM_SEC_STANDBY);
}
static void toshiba_sec_cont_update_start(struct msm_fb_data_type *mfd)
{
if (TM_GET_PID(mfd->panel.id) == LCD_TOSHIBA_2P4_WVGA_PT)
return;
write_client_reg(VSYNIF, 0x00000000, TRUE);
write_client_reg(PORT_ENB, 0x00000002, TRUE);
write_client_reg(INTMASK, 0x00000001, TRUE);
write_client_reg(TTBUSSEL, 0x0000000B, TRUE);
write_client_reg(MONI, 0x00000008, TRUE);
write_client_reg(CLKENB, 0x000000EF, TRUE);
write_client_reg(CLKENB, 0x000010EF, TRUE);
write_client_reg(CLKENB, 0x000011EF, TRUE);
write_client_reg(BITMAP4, 0x00DC00B0, TRUE);
write_client_reg(HCYCLE, 0x0000006B, TRUE);
write_client_reg(HSW, 0x00000003, TRUE);
write_client_reg(HDE_START, 0x00000002, TRUE);
write_client_reg(HDE_SIZE, 0x00000057, TRUE);
write_client_reg(VCYCLE, 0x000000E6, TRUE);
write_client_reg(VSW, 0x00000001, TRUE);
write_client_reg(VDE_START, 0x00000003, TRUE);
write_client_reg(VDE_SIZE, 0x000000DB, TRUE);
write_client_reg(WRSTB, 0x00000015, TRUE);
write_client_reg(MPLFBUF, 0x00000004, TRUE);
write_client_reg(ASY_DATA, 0x80000021, TRUE);
write_client_reg(ASY_DATB, 0x00000000, TRUE);
write_client_reg(ASY_DATC, 0x80000022, TRUE);
write_client_reg(ASY_CMDSET, 0x00000007, TRUE);
write_client_reg(PXL, 0x00000089, TRUE);
write_client_reg(VSYNIF, 0x00000001, TRUE);
mddi_wait(2);
}
static void toshiba_sec_cont_update_stop(struct msm_fb_data_type *mfd)
{
if (TM_GET_PID(mfd->panel.id) == LCD_TOSHIBA_2P4_WVGA_PT)
return;
write_client_reg(PXL, 0x00000000, TRUE);
write_client_reg(VSYNIF, 0x00000000, TRUE);
write_client_reg(START, 0x00000000, TRUE);
write_client_reg(ASY_CMDSET, 0x00000000, TRUE);
mddi_wait(3);
write_client_reg(SRST, 0x00000002, TRUE);
mddi_wait(3);
write_client_reg(SRST, 0x00000003, TRUE);
}
static void toshiba_sec_backlight_on(struct msm_fb_data_type *mfd)
{
if (TM_GET_PID(mfd->panel.id) == LCD_TOSHIBA_2P4_WVGA_PT)
return;
write_client_reg(TIMER0CTRL, 0x00000060, TRUE);
write_client_reg(TIMER0LOAD, 0x00001388, TRUE);
write_client_reg(PWM0OFF, 0x00000001, TRUE);
write_client_reg(TIMER1CTRL, 0x00000060, TRUE);
write_client_reg(TIMER1LOAD, 0x00001388, TRUE);
write_client_reg(PWM1OFF, 0x00001387, TRUE);
write_client_reg(TIMER0CTRL, 0x000000E0, TRUE);
write_client_reg(TIMER1CTRL, 0x000000E0, TRUE);
write_client_reg(PWMCR, 0x00000003, TRUE);
}
static void toshiba_sec_sleep_in(struct msm_fb_data_type *mfd)
{
if (TM_GET_PID(mfd->panel.id) == LCD_TOSHIBA_2P4_WVGA_PT)
return;
write_client_reg(VSYNIF, 0x00000000, TRUE);
write_client_reg(PORT_ENB, 0x00000002, TRUE);
write_client_reg(ASY_DATA, 0x80000007, TRUE);
write_client_reg(ASY_DATB, 0x00004016, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(2);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x00000019, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(2);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x0000000B, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(2);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x00000002, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(4);
write_client_reg(ASY_DATA, 0x80000010, TRUE);
write_client_reg(ASY_DATB, 0x00000300, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(4);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x00000000, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(2);
write_client_reg(ASY_DATA, 0x80000007, TRUE);
write_client_reg(ASY_DATB, 0x00004004, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(2);
write_client_reg(PORT, 0x00000000, TRUE);
write_client_reg(PXL, 0x00000000, TRUE);
write_client_reg(START, 0x00000000, TRUE);
write_client_reg(REGENB, 0x00000001, TRUE);
write_client_reg(ASY_DATA, 0x80000010, TRUE);
write_client_reg(ASY_DATB, 0x00000302, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
}
static void toshiba_sec_sleep_out(struct msm_fb_data_type *mfd)
{
if (TM_GET_PID(mfd->panel.id) == LCD_TOSHIBA_2P4_WVGA_PT)
return;
write_client_reg(VSYNIF, 0x00000000, TRUE);
write_client_reg(PORT_ENB, 0x00000002, TRUE);
write_client_reg(ASY_DATA, 0x80000010, TRUE);
write_client_reg(ASY_DATB, 0x00000300, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
write_client_reg(ASY_DATA, 0x80000011, TRUE);
write_client_reg(ASY_DATB, 0x00000812, TRUE);
write_client_reg(ASY_DATC, 0x80000012, TRUE);
write_client_reg(ASY_DATD, 0x00000003, TRUE);
write_client_reg(ASY_DATE, 0x80000013, TRUE);
write_client_reg(ASY_DATF, 0x00000909, TRUE);
write_client_reg(ASY_DATG, 0x80000010, TRUE);
write_client_reg(ASY_DATH, 0x00000040, TRUE);
write_client_reg(ASY_CMDSET, 0x00000001, TRUE);
write_client_reg(ASY_CMDSET, 0x00000000, TRUE);
mddi_wait(4);
write_client_reg(ASY_DATA, 0x80000010, TRUE);
write_client_reg(ASY_DATB, 0x00000340, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(6);
write_client_reg(ASY_DATA, 0x80000010, TRUE);
write_client_reg(ASY_DATB, 0x00003340, TRUE);
write_client_reg(ASY_DATC, 0x80000007, TRUE);
write_client_reg(ASY_DATD, 0x00004007, TRUE);
write_client_reg(ASY_CMDSET, 0x00000009, TRUE);
write_client_reg(ASY_CMDSET, 0x00000008, TRUE);
mddi_wait(1);
write_client_reg(ASY_DATA, 0x80000007, TRUE);
write_client_reg(ASY_DATB, 0x00004017, TRUE);
write_client_reg(ASY_DATC, 0x8000005B, TRUE);
write_client_reg(ASY_DATD, 0x00000000, TRUE);
write_client_reg(ASY_DATE, 0x80000059, TRUE);
write_client_reg(ASY_DATF, 0x00000011, TRUE);
write_client_reg(ASY_CMDSET, 0x0000000D, TRUE);
write_client_reg(ASY_CMDSET, 0x0000000C, TRUE);
mddi_wait(2);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x00000019, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(2);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x00000079, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(2);
write_client_reg(ASY_DATA, 0x80000059, TRUE);
write_client_reg(ASY_DATB, 0x000003FD, TRUE);
write_client_reg(ASY_CMDSET, 0x00000005, TRUE);
write_client_reg(ASY_CMDSET, 0x00000004, TRUE);
mddi_wait(2);
}
static void mddi_toshiba_lcd_set_backlight(struct msm_fb_data_type *mfd)
{
int32 level;
int ret = -EPERM;
int max = mfd->panel_info.bl_max;
int min = mfd->panel_info.bl_min;
if (mddi_toshiba_pdata && mddi_toshiba_pdata->pmic_backlight) {
ret = mddi_toshiba_pdata->pmic_backlight(mfd->bl_level);
if (!ret)
return;
}
if (ret && mddi_toshiba_pdata && mddi_toshiba_pdata->backlight_level) {
level = mddi_toshiba_pdata->backlight_level(mfd->bl_level,
max, min);
if (level < 0)
return;
if (TM_GET_PID(mfd->panel.id) == LCD_SHARP_2P4_VGA)
write_client_reg(TIMER0LOAD, 0x00001388, TRUE);
} else {
if (!max)
level = 0;
else
level = (mfd->bl_level * 4999) / max;
}
write_client_reg(PWM0OFF, level, TRUE);
}
static void mddi_toshiba_vsync_set_handler(msm_fb_vsync_handler_type handler,
void *arg)
{
boolean error = FALSE;
unsigned long flags;
spin_lock_irqsave(&mddi_host_spin_lock, flags);
if (mddi_toshiba_vsync_handler != NULL) {
error = TRUE;
} else {
mddi_toshiba_vsync_handler = handler;
mddi_toshiba_vsync_handler_arg = arg;
}
spin_unlock_irqrestore(&mddi_host_spin_lock, flags);
if (error) {
MDDI_MSG_ERR("MDDI: Previous Vsync handler never called\n");
} else {
mddi_queue_register_write(INTMSK, 0x0000, FALSE, 0);
mddi_toshiba_vsync_attempts = 1;
mddi_vsync_detect_enabled = TRUE;
}
}
static void mddi_toshiba_lcd_vsync_detected(boolean detected)
{
static struct timeval start_time;
static boolean first_time = TRUE;
struct timeval now;
uint32 elapsed_us;
uint32 num_vsyncs;
if ((detected) || (mddi_toshiba_vsync_attempts > 5)) {
if ((detected) && (mddi_toshiba_monitor_refresh_value)) {
if (!first_time) {
jiffies_to_timeval(jiffies, &now);
elapsed_us =
(now.tv_sec - start_time.tv_sec) * 1000000 +
now.tv_usec - start_time.tv_usec;
num_vsyncs = (elapsed_us +
(mddi_toshiba_usecs_per_refresh >>
1)) /
mddi_toshiba_usecs_per_refresh;
mddi_toshiba_rows_per_second =
(mddi_toshiba_rows_per_refresh * 1000 *
num_vsyncs) / (elapsed_us / 1000);
}
first_time = FALSE;
jiffies_to_timeval(jiffies, &start_time);
if (mddi_toshiba_report_refresh_measurements) {
(void)mddi_queue_register_read_int(VPOS,
&mddi_toshiba_curr_vpos);
}
}
if (mddi_toshiba_vsync_handler != NULL) {
(*mddi_toshiba_vsync_handler)
(mddi_toshiba_vsync_handler_arg);
mddi_toshiba_vsync_handler = NULL;
}
mddi_vsync_detect_enabled = FALSE;
mddi_toshiba_vsync_attempts = 0;
if (!mddi_queue_register_write_int(INTMSK, 0x0001))
MDDI_MSG_ERR("Vsync interrupt disable failed!\n");
if (!detected) {
MDDI_MSG_NOTICE("Vsync detection failed!\n");
} else if ((mddi_toshiba_monitor_refresh_value) &&
(mddi_toshiba_report_refresh_measurements)) {
MDDI_MSG_NOTICE(" Last Line Counter=%d!\n",
mddi_toshiba_curr_vpos);
MDDI_MSG_NOTICE(" Lines Per Second=%d!\n",
mddi_toshiba_rows_per_second);
}
if (!mddi_queue_register_write_int(INTFLG, 0x0001))
MDDI_MSG_ERR("Vsync interrupt clear failed!\n");
} else {
mddi_toshiba_vsync_attempts++;
}
}
static void mddi_toshiba_prim_init(struct msm_fb_data_type *mfd)
{
switch (toshiba_state) {
case TOSHIBA_STATE_PRIM_SEC_READY:
break;
case TOSHIBA_STATE_OFF:
toshiba_state = TOSHIBA_STATE_PRIM_SEC_STANDBY;
toshiba_common_initial_setup(mfd);
break;
case TOSHIBA_STATE_PRIM_SEC_STANDBY:
toshiba_common_initial_setup(mfd);
break;
case TOSHIBA_STATE_SEC_NORMAL_MODE:
toshiba_sec_cont_update_stop(mfd);
toshiba_sec_sleep_in(mfd);
toshiba_sec_sleep_out(mfd);
toshiba_sec_lcd_off(mfd);
toshiba_common_initial_setup(mfd);
break;
default:
MDDI_MSG_ERR("mddi_toshiba_prim_init from state %d\n",
toshiba_state);
}
toshiba_prim_start(mfd);
if (TM_GET_PID(mfd->panel.id) == LCD_SHARP_2P4_VGA)
gordon_disp_init();
mddi_host_write_pix_attr_reg(0x00C3);
}
static void mddi_toshiba_sec_init(struct msm_fb_data_type *mfd)
{
switch (toshiba_state) {
case TOSHIBA_STATE_PRIM_SEC_READY:
break;
case TOSHIBA_STATE_PRIM_SEC_STANDBY:
toshiba_common_initial_setup(mfd);
break;
case TOSHIBA_STATE_PRIM_NORMAL_MODE:
toshiba_prim_lcd_off(mfd);
toshiba_common_initial_setup(mfd);
break;
default:
MDDI_MSG_ERR("mddi_toshiba_sec_init from state %d\n",
toshiba_state);
}
toshiba_sec_start(mfd);
toshiba_sec_backlight_on(mfd);
toshiba_sec_cont_update_start(mfd);
mddi_host_write_pix_attr_reg(0x0400);
}
static void mddi_toshiba_lcd_powerdown(struct msm_fb_data_type *mfd)
{
switch (toshiba_state) {
case TOSHIBA_STATE_PRIM_SEC_READY:
mddi_toshiba_prim_init(mfd);
mddi_toshiba_lcd_powerdown(mfd);
return;
case TOSHIBA_STATE_PRIM_SEC_STANDBY:
break;
case TOSHIBA_STATE_PRIM_NORMAL_MODE:
toshiba_prim_lcd_off(mfd);
break;
case TOSHIBA_STATE_SEC_NORMAL_MODE:
toshiba_sec_cont_update_stop(mfd);
toshiba_sec_sleep_in(mfd);
toshiba_sec_sleep_out(mfd);
toshiba_sec_lcd_off(mfd);
break;
default:
MDDI_MSG_ERR("mddi_toshiba_lcd_powerdown from state %d\n",
toshiba_state);
}
}
static int mddi_toshiba_lcd_on(struct platform_device *pdev)
{
struct msm_fb_data_type *mfd;
mfd = platform_get_drvdata(pdev);
if (!mfd)
return -ENODEV;
if (mfd->key != MFD_KEY)
return -EINVAL;
if (TM_GET_DID(mfd->panel.id) == TOSHIBA_VGA_PRIM)
mddi_toshiba_prim_init(mfd);
else
mddi_toshiba_sec_init(mfd);
if (TM_GET_PID(mfd->panel.id) == LCD_SHARP_2P4_VGA) {
if (mddi_sharpgordon_firsttime) {
mddi_sharpgordon_firsttime = 0;
write_client_reg(REGENB, 0x00000001, TRUE);
}
}
return 0;
}
static int mddi_toshiba_lcd_off(struct platform_device *pdev)
{
mddi_toshiba_lcd_powerdown(platform_get_drvdata(pdev));
return 0;
}
static int __init mddi_toshiba_lcd_probe(struct platform_device *pdev)
{
if (pdev->id == 0) {
mddi_toshiba_pdata = pdev->dev.platform_data;
return 0;
}
msm_fb_add_device(pdev);
return 0;
}
int mddi_toshiba_device_register(struct msm_panel_info *pinfo,
u32 channel, u32 panel)
{
struct platform_device *pdev = NULL;
int ret;
if ((channel >= 3) || ch_used[channel])
return -ENODEV;
if ((channel != TOSHIBA_VGA_PRIM) &&
mddi_toshiba_pdata && mddi_toshiba_pdata->panel_num)
if (mddi_toshiba_pdata->panel_num() < 2)
return -ENODEV;
ch_used[channel] = TRUE;
pdev = platform_device_alloc("mddi_toshiba", (panel << 8)|channel);
if (!pdev)
return -ENOMEM;
if (channel == TOSHIBA_VGA_PRIM) {
toshiba_panel_data.set_backlight =
mddi_toshiba_lcd_set_backlight;
if (pinfo->lcd.vsync_enable) {
toshiba_panel_data.set_vsync_notifier =
mddi_toshiba_vsync_set_handler;
mddi_lcd.vsync_detected =
mddi_toshiba_lcd_vsync_detected;
}
} else {
toshiba_panel_data.set_backlight = NULL;
toshiba_panel_data.set_vsync_notifier = NULL;
}
toshiba_panel_data.panel_info = *pinfo;
ret = platform_device_add_data(pdev, &toshiba_panel_data,
sizeof(toshiba_panel_data));
if (ret) {
printk(KERN_ERR
"%s: platform_device_add_data failed!\n", __func__);
goto err_device_put;
}
ret = platform_device_add(pdev);
if (ret) {
printk(KERN_ERR
"%s: platform_device_register failed!\n", __func__);
goto err_device_put;
}
return 0;
err_device_put:
platform_device_put(pdev);
return ret;
}
static int __init mddi_toshiba_lcd_init(void)
{
return platform_driver_register(&this_driver);
}
