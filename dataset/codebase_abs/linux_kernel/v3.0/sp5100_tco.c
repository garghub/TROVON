static void F_1 ( void )
{
T_1 V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
V_1 = F_3 ( F_4 ( V_4 ) ) ;
V_1 |= V_5 ;
F_5 ( V_1 , F_4 ( V_4 ) ) ;
F_6 ( & V_3 , V_2 ) ;
}
static void F_7 ( void )
{
T_1 V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
V_1 = F_3 ( F_4 ( V_4 ) ) ;
V_1 &= ~ V_5 ;
F_5 ( V_1 , F_4 ( V_4 ) ) ;
F_6 ( & V_3 , V_2 ) ;
}
static void F_8 ( void )
{
T_1 V_1 ;
unsigned long V_2 ;
F_2 ( & V_3 , V_2 ) ;
V_1 = F_3 ( F_4 ( V_4 ) ) ;
V_1 |= V_6 ;
F_5 ( V_1 , F_4 ( V_4 ) ) ;
F_6 ( & V_3 , V_2 ) ;
}
static int F_9 ( int V_7 )
{
unsigned long V_2 ;
if ( V_7 < 0 || V_7 > 0xffff )
return - V_8 ;
F_2 ( & V_3 , V_2 ) ;
F_5 ( V_7 , F_10 ( V_4 ) ) ;
F_6 ( & V_3 , V_2 ) ;
V_9 = V_7 ;
return 0 ;
}
static int F_11 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
if ( F_12 ( 0 , & V_12 ) )
return - V_13 ;
F_1 () ;
F_8 () ;
return F_13 ( V_10 , V_11 ) ;
}
static int F_14 ( struct V_10 * V_10 , struct V_11 * V_11 )
{
if ( V_14 == 42 ) {
F_7 () ;
} else {
F_15 (KERN_CRIT PFX
L_1 ) ;
F_8 () ;
}
F_16 ( 0 , & V_12 ) ;
V_14 = 0 ;
return 0 ;
}
static T_2 F_17 ( struct V_11 * V_11 , const char T_3 * V_15 ,
T_4 V_16 , T_5 * V_17 )
{
if ( V_16 ) {
if ( ! V_18 ) {
T_4 V_19 ;
V_14 = 0 ;
for ( V_19 = 0 ; V_19 != V_16 ; V_19 ++ ) {
char V_20 ;
if ( F_18 ( V_20 , V_15 + V_19 ) )
return - V_21 ;
if ( V_20 == 'V' )
V_14 = 42 ;
}
}
F_8 () ;
}
return V_16 ;
}
static long F_19 ( struct V_11 * V_11 , unsigned int V_22 ,
unsigned long V_23 )
{
int V_24 , V_25 = - V_8 ;
int V_26 ;
void T_3 * V_27 = ( void T_3 * ) V_23 ;
int T_3 * V_28 = V_27 ;
static const struct V_29 V_30 = {
. V_31 = V_32 |
V_33 |
V_34 ,
. V_35 = 0 ,
. V_36 = V_37 ,
} ;
switch ( V_22 ) {
case V_38 :
return F_20 ( V_27 , & V_30 ,
sizeof( V_30 ) ) ? - V_21 : 0 ;
case V_39 :
case V_40 :
return F_21 ( 0 , V_28 ) ;
case V_41 :
if ( F_18 ( V_24 , V_28 ) )
return - V_21 ;
if ( V_24 & V_42 ) {
F_7 () ;
V_25 = 0 ;
}
if ( V_24 & V_43 ) {
F_1 () ;
F_8 () ;
V_25 = 0 ;
}
return V_25 ;
case V_44 :
F_8 () ;
return 0 ;
case V_45 :
if ( F_18 ( V_26 , V_28 ) )
return - V_21 ;
if ( F_9 ( V_26 ) )
return - V_8 ;
F_8 () ;
case V_46 :
return F_21 ( V_9 , V_28 ) ;
default:
return - V_47 ;
}
}
static unsigned char T_6 F_22 ( void )
{
struct V_48 * V_49 = NULL ;
T_1 V_1 ;
F_23 (dev) {
if ( F_24 ( V_50 , V_49 ) != NULL ) {
V_51 = V_49 ;
break;
}
}
if ( ! V_51 )
return 0 ;
V_52 = V_53 ;
if ( ! F_25 ( V_52 , V_54 , L_2 ) ) {
F_15 (KERN_ERR PFX L_3 ,
pm_iobase) ;
goto exit;
}
F_26 ( V_55 , V_53 ) ;
V_1 = F_27 ( V_56 ) ;
F_26 ( V_57 , V_53 ) ;
V_1 = V_1 << 8 | F_27 ( V_56 ) ;
F_26 ( V_58 , V_53 ) ;
V_1 = V_1 << 8 | F_27 ( V_56 ) ;
F_26 ( V_59 , V_53 ) ;
V_1 = V_1 << 8 | ( F_27 ( V_56 ) & 0xf8 ) ;
if ( ! F_28 ( V_1 , V_60 ,
L_2 ) ) {
F_15 (KERN_ERR PFX L_4 ,
val) ;
goto V_61;
}
V_62 = V_1 ;
V_4 = F_29 ( V_1 , V_60 ) ;
if ( V_4 == 0 ) {
F_15 (KERN_ERR PFX L_5 ) ;
goto V_63;
}
F_30 ( V_51 ,
V_64 ,
& V_1 ) ;
V_1 |= V_65 ;
F_31 ( V_51 ,
V_64 ,
V_1 ) ;
F_26 ( V_66 , V_53 ) ;
V_1 = F_27 ( V_56 ) ;
V_1 |= V_67 ;
V_1 &= ~ V_68 ;
F_26 ( V_1 , V_56 ) ;
V_1 = F_3 ( F_4 ( V_4 ) ) ;
V_1 &= ~ V_69 ;
F_5 ( V_1 , F_4 ( V_4 ) ) ;
F_9 ( V_9 ) ;
F_7 () ;
return 1 ;
V_63:
F_32 ( V_62 , V_60 ) ;
V_61:
F_33 ( V_52 , V_54 ) ;
exit:
return 0 ;
}
static int T_6 F_34 ( struct V_70 * V_49 )
{
int V_71 ;
T_1 V_1 ;
if ( ! F_22 () )
return - V_72 ;
F_15 (KERN_INFO PFX L_6 ,
readl(SP5100_WDT_CONTROL(tcobase)) & SP5100_PM_WATCHDOG_FIRED ?
L_7 : L_8 ) ;
V_1 = F_3 ( F_4 ( V_4 ) ) ;
V_1 &= ~ V_73 ;
F_5 ( V_1 , F_4 ( V_4 ) ) ;
if ( F_9 ( V_9 ) ) {
V_9 = V_74 ;
F_9 ( V_9 ) ;
}
V_71 = F_35 ( & V_75 ) ;
if ( V_71 != 0 ) {
F_15 (KERN_ERR PFX L_9
L_10 ,
WATCHDOG_MINOR, ret) ;
goto exit;
}
F_16 ( 0 , & V_12 ) ;
F_15 (KERN_INFO PFX L_11
L_12 ,
tcobase, heartbeat, nowayout) ;
return 0 ;
exit:
F_36 ( V_4 ) ;
F_32 ( V_62 , V_60 ) ;
F_33 ( V_52 , V_54 ) ;
return V_71 ;
}
static void T_7 F_37 ( void )
{
if ( ! V_18 )
F_7 () ;
F_38 ( & V_75 ) ;
F_36 ( V_4 ) ;
F_32 ( V_62 , V_60 ) ;
F_33 ( V_52 , V_54 ) ;
}
static int T_7 F_39 ( struct V_70 * V_49 )
{
if ( V_4 )
F_37 () ;
return 0 ;
}
static void F_40 ( struct V_70 * V_49 )
{
F_7 () ;
}
static int T_8 F_41 ( void )
{
int V_76 ;
F_15 (KERN_INFO PFX L_13 ,
TCO_VERSION) ;
V_76 = F_42 ( & V_77 ) ;
if ( V_76 )
return V_76 ;
V_78 = F_43 (
V_37 , - 1 , NULL , 0 ) ;
if ( F_44 ( V_78 ) ) {
V_76 = F_45 ( V_78 ) ;
goto V_79;
}
return 0 ;
V_79:
F_46 ( & V_77 ) ;
return V_76 ;
}
static void T_9 F_47 ( void )
{
F_48 ( V_78 ) ;
F_46 ( & V_77 ) ;
F_15 (KERN_INFO PFX L_14 ) ;
}
