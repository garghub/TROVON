static void F_1 ( struct V_1 * V_2 , T_1 V_3 ,
T_1 V_4 )
{
F_2 ( V_2 , V_5 , V_3 ) ;
F_2 ( V_2 , V_6 , V_4 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
bool V_7 )
{
T_1 V_4 ;
V_4 = F_4 ( V_2 , V_8 ) ;
V_4 |= V_9 ;
V_4 &= ~ V_10 ;
if ( V_7 ) {
V_4 &= ~ V_9 ;
V_4 |= V_10 ;
}
F_2 ( V_2 , ( V_8 ) , V_4 ) ;
return F_4 ( V_2 , V_8 ) ;
}
static void F_5 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_5 , 0x844 ) ;
F_2 ( V_2 , V_6 , 0x883c883c ) ;
F_2 ( V_2 , V_5 , 0x848 ) ;
F_2 ( V_2 , V_6 , 0x88648864 ) ;
F_2 ( V_2 , V_5 , 0x84C ) ;
F_2 ( V_2 , V_6 , 0x90039003 ) ;
}
static void F_6 ( struct V_1 * V_2 )
{
T_2 V_11 = V_2 -> V_12 -> V_13 . V_14 ;
T_1 V_15 ;
if ( V_11 < 2 || V_11 == 10 || V_11 > 13 )
return;
F_2 ( V_2 , V_5 ,
V_16 ) ;
V_15 = F_4 ( V_2 , V_6 ) ;
if ( V_15 & V_17 ) {
F_5 ( V_2 ) ;
V_15 |= V_17 ;
F_2 ( V_2 , V_5 ,
V_16 ) ;
F_2 ( V_2 , V_6 , V_15 ) ;
F_2 ( V_2 , V_18 ,
V_19 ) ;
F_7 ( 1000 , 2000 ) ;
F_2 ( V_2 , V_18 ,
V_20 ) ;
F_7 ( 1000 , 2000 ) ;
}
}
static void F_8 ( struct V_1 * V_2 )
{
T_2 V_11 = V_2 -> V_12 -> V_13 . V_14 ;
bool V_21 , V_22 ;
V_21 = V_11 == 7 || V_11 == 9 || V_11 == 11 ;
V_22 = V_11 == 5 || V_11 == 7 || V_11 == 8 ||
V_11 == 9 || V_11 == 11 ;
if ( ! V_21 && ! V_22 )
return;
#if 0
pcie2_set32(pcie2, BCMA_CORE_PCIE2_CLK_CONTROL,
PCIE_DISABLE_L1CLK_GATING);
#if 0
pcie2_write32(pcie2, BCMA_CORE_PCIE2_CONFIGINDADDR,
PCIEGEN2_COE_PVT_TL_CTRL_0);
pcie2_mask32(pcie2, BCMA_CORE_PCIE2_CONFIGINDDATA,
~(1 << COE_PVT_TL_CTRL_0_PM_DIS_L1_REENTRY_BIT));
#endif
#endif
}
static void F_9 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_5 , V_23 ) ;
F_10 ( V_2 , V_6 , 0x1f ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_2 ( V_2 , V_5 , V_24 ) ;
F_2 ( V_2 , V_6 , 1 << 0 ) ;
}
static void F_12 ( struct V_1 * V_2 )
{
struct V_25 * V_26 = & V_2 -> V_12 -> V_27 -> V_26 ;
T_2 V_11 = V_2 -> V_12 -> V_13 . V_14 ;
T_1 V_28 , V_29 ;
if ( V_11 <= 13 ) {
V_28 = F_13 ( V_26 ) / 1000 ;
V_29 = ( 1000000 * 2 ) / V_28 ;
F_2 ( V_2 , V_5 ,
V_30 ) ;
F_2 ( V_2 , V_6 , V_29 ) ;
}
}
void F_14 ( struct V_1 * V_2 )
{
struct V_31 * V_32 = & V_2 -> V_12 -> V_27 -> V_33 ;
T_1 V_34 ;
V_34 = F_4 ( V_2 , F_15 ( 54 ) ) ;
if ( ( V_34 & 0xe ) >> 1 == 2 )
F_1 ( V_2 , 0x4e0 , 0x17 ) ;
if ( V_32 -> V_13 == V_35 && V_32 -> V_14 > 3 )
F_3 ( V_2 , true ) ;
F_6 ( V_2 ) ;
F_8 ( V_2 ) ;
F_12 ( V_2 ) ;
F_9 ( V_2 ) ;
F_11 ( V_2 ) ;
}
