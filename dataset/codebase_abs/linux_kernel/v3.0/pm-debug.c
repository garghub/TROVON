void F_1 ( int V_1 , int V_2 , unsigned int V_3 )
{
struct V_4 {
const char * V_5 ;
T_1 V_6 ;
} V_7 [ 32 ] ;
int V_8 = 0 , V_9 ;
const char * V_10 = NULL , * V_11 = NULL ;
if ( ! V_2 ) {
#if 0
DUMP_PRM_MOD_REG(OCP_MOD, OMAP2_PRM_IRQENABLE_MPU_OFFSET);
DUMP_CM_MOD_REG(MPU_MOD, OMAP2_CM_CLKSTCTRL);
DUMP_PRM_MOD_REG(MPU_MOD, OMAP2_PM_PWSTCTRL);
DUMP_PRM_MOD_REG(MPU_MOD, OMAP2_PM_PWSTST);
DUMP_PRM_MOD_REG(MPU_MOD, PM_WKDEP);
#endif
#if 0
DUMP_INTC_REG(INTC_MIR0, 0x0084);
DUMP_INTC_REG(INTC_MIR1, 0x00a4);
DUMP_INTC_REG(INTC_MIR2, 0x00c4);
#endif
#if 0
DUMP_CM_MOD_REG(CORE_MOD, CM_FCLKEN1);
if (cpu_is_omap24xx()) {
DUMP_CM_MOD_REG(CORE_MOD, OMAP24XX_CM_FCLKEN2);
DUMP_PRM_MOD_REG(OMAP24XX_GR_MOD,
OMAP2_PRCM_CLKEMUL_CTRL_OFFSET);
DUMP_PRM_MOD_REG(OMAP24XX_GR_MOD,
OMAP2_PRCM_CLKSRC_CTRL_OFFSET);
}
DUMP_CM_MOD_REG(WKUP_MOD, CM_FCLKEN);
DUMP_CM_MOD_REG(CORE_MOD, CM_ICLKEN1);
DUMP_CM_MOD_REG(CORE_MOD, CM_ICLKEN2);
DUMP_CM_MOD_REG(WKUP_MOD, CM_ICLKEN);
DUMP_CM_MOD_REG(PLL_MOD, CM_CLKEN);
DUMP_CM_MOD_REG(PLL_MOD, CM_AUTOIDLE);
DUMP_PRM_MOD_REG(CORE_MOD, OMAP2_PM_PWSTST);
#endif
#if 0
if (cpu_is_omap24xx()) {
DUMP_CM_MOD_REG(OMAP24XX_DSP_MOD, CM_FCLKEN);
DUMP_CM_MOD_REG(OMAP24XX_DSP_MOD, CM_ICLKEN);
DUMP_CM_MOD_REG(OMAP24XX_DSP_MOD, CM_IDLEST);
DUMP_CM_MOD_REG(OMAP24XX_DSP_MOD, CM_AUTOIDLE);
DUMP_CM_MOD_REG(OMAP24XX_DSP_MOD, CM_CLKSEL);
DUMP_CM_MOD_REG(OMAP24XX_DSP_MOD, OMAP2_CM_CLKSTCTRL);
DUMP_PRM_MOD_REG(OMAP24XX_DSP_MOD, OMAP2_RM_RSTCTRL);
DUMP_PRM_MOD_REG(OMAP24XX_DSP_MOD, OMAP2_RM_RSTST);
DUMP_PRM_MOD_REG(OMAP24XX_DSP_MOD, OMAP2_PM_PWSTCTRL);
DUMP_PRM_MOD_REG(OMAP24XX_DSP_MOD, OMAP2_PM_PWSTST);
}
#endif
} else {
F_2 ( V_12 , V_13 ) ;
if ( F_3 () )
F_2 ( V_12 , V_14 ) ;
F_2 ( V_15 , V_16 ) ;
F_2 ( V_17 , V_18 ) ;
#if 1
F_4 ( V_19 , 0x0098 ) ;
F_4 ( V_20 , 0x00b8 ) ;
F_4 ( V_21 , 0x00d8 ) ;
#endif
}
switch ( V_1 ) {
case 0 :
V_10 = L_1 ;
V_11 = L_2 ;
break;
case 1 :
V_10 = L_3 ;
V_11 = L_2 ;
break;
case 2 :
V_10 = L_3 ;
V_11 = L_4 ;
break;
}
if ( ! V_2 )
#ifdef F_5
F_6 ( V_22
L_5 , V_10 , V_11 ,
F_7 ( F_8 ( V_23 ) -
V_23 ) ) ;
#else
F_6 ( V_22 L_6 , V_10 , V_11 ) ;
#endif
else
F_6 ( V_22 L_7 ,
V_3 / 1000 , V_3 % 1000 ) ;
for ( V_9 = 0 ; V_9 < V_8 ; V_9 ++ )
F_6 ( V_22 L_8 , V_7 [ V_9 ] . V_5 , V_7 [ V_9 ] . V_6 ) ;
}
void F_9 ( T_1 V_24 , T_1 V_25 )
{
T_1 V_26 , V_27 ;
if ( ! V_24 && ! V_25 )
return;
V_26 = F_10 ( F_11 ( V_28 ) ) ;
V_27 = V_26 * V_24 + V_26 * V_25 / 1000 ;
F_12 ( V_28 ) ;
F_13 ( V_28 , 0 , 0xffffffff - V_27 ) ;
F_14 ( L_9
L_10 ,
V_24 , V_25 , V_27 , V_26 ) ;
}
static int F_15 ( void )
{
static int V_29 ;
if ( V_29 == 0 ) {
int V_9 = 0 ;
while ( V_30 [ V_9 ] . V_5 [ 0 ] != 0 ) {
V_29 += V_30 [ V_9 ] . V_31 +
4 - V_30 [ V_9 ] . V_32 ;
V_9 ++ ;
}
}
return V_29 ;
}
static int F_16 ( struct V_33 * V_34 , void * V_35 )
{
int V_9 , V_36 ;
unsigned long V_6 ;
int V_37 = ( int ) V_34 -> V_38 ;
T_1 * V_39 ;
void * V_40 = NULL ;
int V_7 ;
int V_41 ;
if ( V_37 == 0 ) {
V_40 = F_17 ( F_15 () , V_42 ) ;
V_39 = V_40 ;
F_18 ( V_39 ) ;
} else {
V_39 = V_43 [ V_37 - 1 ] ;
}
V_9 = 0 ;
while ( V_30 [ V_9 ] . V_5 [ 0 ] != 0 ) {
V_7 = 0 ;
V_41 = 0 ;
if ( V_30 [ V_9 ] . type == V_44 )
F_19 ( V_34 , L_11 ,
V_30 [ V_9 ] . V_5 ,
( T_1 ) ( V_45 +
V_30 [ V_9 ] . V_46 ) ) ;
else
F_19 ( V_34 , L_12 ,
V_30 [ V_9 ] . V_5 ,
( T_1 ) ( V_47 +
V_30 [ V_9 ] . V_46 ) ) ;
for ( V_36 = V_30 [ V_9 ] . V_32 ;
V_36 <= V_30 [ V_9 ] . V_31 ; V_36 += 4 ) {
V_6 = * ( V_39 ++ ) ;
if ( V_6 != 0 ) {
V_7 ++ ;
if ( V_41 ) {
F_19 ( V_34 , L_13 ) ;
V_41 = 0 ;
}
F_19 ( V_34 , L_14 , V_36 , V_6 ) ;
if ( V_7 % 4 == 0 )
V_41 = 1 ;
}
}
F_19 ( V_34 , L_13 ) ;
V_9 ++ ;
}
if ( V_40 != NULL )
F_20 ( V_40 ) ;
return 0 ;
}
static void F_18 ( T_1 * V_39 )
{
int V_9 , V_36 ;
T_1 V_6 ;
V_9 = 0 ;
while ( V_30 [ V_9 ] . V_5 [ 0 ] != 0 ) {
for ( V_36 = V_30 [ V_9 ] . V_32 ;
V_36 <= V_30 [ V_9 ] . V_31 ; V_36 += 4 ) {
if ( V_30 [ V_9 ] . type == V_44 )
V_6 = F_21 (
V_30 [ V_9 ] . V_46 , V_36 ) ;
else
V_6 = F_22 (
V_30 [ V_9 ] . V_46 , V_36 ) ;
* ( V_39 ++ ) = V_6 ;
}
V_9 ++ ;
}
}
int F_23 ( int V_37 )
{
if ( V_43 [ V_37 - 1 ] == NULL )
return - V_48 ;
F_18 ( V_43 [ V_37 - 1 ] ) ;
return 0 ;
}
void F_24 ( struct V_49 * V_50 , int V_51 )
{
T_2 V_52 ;
if ( ! V_53 )
return ;
V_52 = F_25 () ;
V_50 -> V_54 [ V_51 ] += V_52 - V_50 -> V_55 ;
V_50 -> V_55 = V_52 ;
}
static int F_26 ( struct V_56 * V_57 , void * V_58 )
{
struct V_33 * V_34 = (struct V_33 * ) V_58 ;
if ( strcmp ( V_57 -> V_5 , L_15 ) == 0 ||
strcmp ( V_57 -> V_5 , L_16 ) == 0 ||
strncmp ( V_57 -> V_5 , L_17 , 4 ) == 0 )
return 0 ;
F_19 ( V_34 , L_18 , V_57 -> V_5 ,
V_57 -> V_50 . V_39 -> V_5 ,
F_27 ( & V_57 -> V_59 ) ) ;
F_19 ( V_34 , L_13 ) ;
return 0 ;
}
static int F_28 ( struct V_49 * V_50 , void * V_58 )
{
struct V_33 * V_34 = (struct V_33 * ) V_58 ;
int V_9 ;
if ( strcmp ( V_50 -> V_5 , L_19 ) == 0 ||
strcmp ( V_50 -> V_5 , L_20 ) == 0 ||
strncmp ( V_50 -> V_5 , L_17 , 4 ) == 0 )
return 0 ;
if ( V_50 -> V_60 != F_29 ( V_50 ) )
F_6 ( V_61 L_21 ,
V_50 -> V_5 , V_50 -> V_60 , F_29 ( V_50 ) ) ;
F_19 ( V_34 , L_22 , V_50 -> V_5 ,
V_62 [ V_50 -> V_60 ] ) ;
for ( V_9 = 0 ; V_9 < V_63 ; V_9 ++ )
F_19 ( V_34 , L_23 , V_62 [ V_9 ] ,
V_50 -> V_64 [ V_9 ] ) ;
F_19 ( V_34 , L_24 , V_50 -> V_65 ) ;
for ( V_9 = 0 ; V_9 < V_50 -> V_66 ; V_9 ++ )
F_19 ( V_34 , L_25 , V_9 + 1 ,
V_50 -> V_67 [ V_9 ] ) ;
F_19 ( V_34 , L_13 ) ;
return 0 ;
}
static int F_30 ( struct V_49 * V_50 , void * V_58 )
{
struct V_33 * V_34 = (struct V_33 * ) V_58 ;
int V_9 ;
if ( strcmp ( V_50 -> V_5 , L_19 ) == 0 ||
strcmp ( V_50 -> V_5 , L_20 ) == 0 ||
strncmp ( V_50 -> V_5 , L_17 , 4 ) == 0 )
return 0 ;
F_31 ( V_50 ) ;
F_19 ( V_34 , L_22 , V_50 -> V_5 ,
V_62 [ V_50 -> V_60 ] ) ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ )
F_19 ( V_34 , L_26 , V_62 [ V_9 ] ,
V_50 -> V_54 [ V_9 ] ) ;
F_19 ( V_34 , L_13 ) ;
return 0 ;
}
static int F_32 ( struct V_33 * V_34 , void * V_35 )
{
F_33 ( F_28 , V_34 ) ;
F_34 ( F_26 , V_34 ) ;
return 0 ;
}
static int F_35 ( struct V_33 * V_34 , void * V_35 )
{
F_33 ( F_30 , V_34 ) ;
return 0 ;
}
static int F_36 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
switch ( ( int ) V_68 -> V_70 ) {
case V_71 :
return F_37 ( V_69 , F_32 ,
& V_68 -> V_70 ) ;
case V_72 :
default:
return F_37 ( V_69 , F_35 ,
& V_68 -> V_70 ) ;
} ;
}
static int F_38 ( struct V_68 * V_68 , struct V_69 * V_69 )
{
return F_37 ( V_69 , F_16 , V_68 -> V_70 ) ;
}
int F_39 ( int V_37 )
{
char V_5 [ 2 ] ;
if ( ! V_53 )
F_40 () ;
if ( V_37 < 1 || V_37 > V_73 ||
V_43 [ V_37 - 1 ] != NULL )
return - V_48 ;
V_43 [ V_37 - 1 ] =
F_17 ( F_15 () , V_42 ) ;
if ( V_43 [ V_37 - 1 ] == NULL )
return - V_74 ;
if ( V_75 != NULL ) {
sprintf ( V_5 , L_27 , V_37 ) ;
( void ) F_41 ( V_5 , V_76 ,
V_75 , ( void * ) V_37 , & V_77 ) ;
}
return 0 ;
}
static int F_42 ( void * V_78 , T_3 * V_6 )
{
int V_79 = - V_48 ;
if ( F_43 () )
V_79 = F_44 ( (struct V_49 * ) V_78 ) ;
* V_6 = V_79 ;
if ( V_79 >= 0 )
return 0 ;
return * V_6 ;
}
static int F_45 ( void * V_78 , T_3 V_6 )
{
if ( F_43 () )
return F_46 (
(struct V_49 * ) V_78 , ( int ) V_6 ) ;
return - V_48 ;
}
static int T_4 F_47 ( struct V_49 * V_50 , void * V_80 )
{
int V_9 ;
T_2 V_52 ;
struct V_81 * V_82 ;
V_52 = F_25 () ;
for ( V_9 = 0 ; V_9 < 4 ; V_9 ++ )
V_50 -> V_54 [ V_9 ] = 0 ;
V_50 -> V_55 = V_52 ;
if ( strncmp ( V_50 -> V_5 , L_17 , 4 ) == 0 )
return 0 ;
V_82 = F_48 ( V_50 -> V_5 , (struct V_81 * ) V_80 ) ;
( void ) F_41 ( L_28 , V_76 | V_83 , V_82 ,
( void * ) V_50 , & V_84 ) ;
return 0 ;
}
static int F_49 ( void * V_78 , T_3 * V_6 )
{
T_1 * V_85 = V_78 ;
* V_6 = * V_85 ;
return 0 ;
}
static int F_50 ( void * V_78 , T_3 V_6 )
{
T_1 * V_85 = V_78 ;
if ( V_85 == & V_86 && V_6 >= 1000 )
return - V_48 ;
* V_85 = V_6 ;
if ( V_85 == & V_87 ) {
if ( V_6 )
F_51 () ;
else
F_52 () ;
if ( F_43 () )
F_53 ( V_6 ) ;
}
return 0 ;
}
static int F_40 ( void )
{
int V_9 ;
struct V_81 * V_82 ;
char V_5 [ 2 ] ;
if ( V_53 )
return 0 ;
if ( F_43 () )
V_30 = V_88 ;
else {
F_6 ( V_61 L_29 , V_89 ) ;
return - V_90 ;
}
V_82 = F_48 ( L_30 , NULL ) ;
if ( F_54 ( V_82 ) )
return F_55 ( V_82 ) ;
( void ) F_41 ( L_31 , V_76 ,
V_82 , ( void * ) V_71 , & V_91 ) ;
( void ) F_41 ( L_32 , V_76 ,
V_82 , ( void * ) V_72 , & V_91 ) ;
F_33 ( F_47 , ( void * ) V_82 ) ;
V_75 = F_48 ( L_33 , V_82 ) ;
if ( F_54 ( V_75 ) )
return F_55 ( V_75 ) ;
( void ) F_41 ( L_34 , V_76 ,
V_75 , ( void * ) 0 , & V_77 ) ;
for ( V_9 = 0 ; V_9 < V_73 ; V_9 ++ )
if ( V_43 [ V_9 ] != NULL ) {
sprintf ( V_5 , L_27 , V_9 + 1 ) ;
( void ) F_41 ( V_5 , V_76 ,
V_75 , ( void * ) ( V_9 + 1 ) , & V_77 ) ;
}
( void ) F_41 ( L_35 , V_76 | V_83 , V_82 ,
& V_87 , & V_92 ) ;
( void ) F_41 ( L_36 , V_76 | V_83 , V_82 ,
& V_93 , & V_92 ) ;
( void ) F_41 ( L_37 , V_76 | V_83 , V_82 ,
& V_94 , & V_92 ) ;
( void ) F_41 ( L_38 ,
V_76 | V_83 , V_82 , & V_86 ,
& V_92 ) ;
V_53 = 1 ;
return 0 ;
}
