static inline unsigned char F_1 ( int V_1 )
{
return ( V_1 * 10 ) / 6 ;
}
static void F_2 ( void )
{
T_1 V_2 ;
unsigned long V_3 ;
F_3 ( & V_4 , V_3 ) ;
V_2 = F_4 ( F_5 ( V_5 ) ) ;
V_2 &= ~ V_6 ;
F_6 ( V_2 , F_5 ( V_5 ) ) ;
F_7 ( & V_4 , V_3 ) ;
}
static void F_8 ( void )
{
T_1 V_2 ;
unsigned long V_3 ;
F_3 ( & V_4 , V_3 ) ;
V_2 = F_4 ( F_5 ( V_5 ) ) ;
V_2 |= V_6 ;
F_6 ( V_2 , F_5 ( V_5 ) ) ;
F_7 ( & V_4 , V_3 ) ;
}
static void F_9 ( void )
{
unsigned long V_3 ;
F_3 ( & V_4 , V_3 ) ;
F_10 ( 0x01 , F_11 ( V_5 ) ) ;
F_7 ( & V_4 , V_3 ) ;
}
static int F_12 ( int V_7 )
{
int V_8 = 0 ;
unsigned char V_9 ;
unsigned long V_3 ;
T_2 V_2 ;
if ( V_7 < 0 || V_7 > 0x3f )
return - V_10 ;
V_9 = F_1 ( V_7 ) ;
if ( V_9 > 0x3f || V_9 < 0x04 )
return - V_10 ;
F_3 ( & V_4 , V_3 ) ;
V_2 = F_13 ( F_14 ( V_5 ) ) ;
V_2 &= 0xc0 ;
V_2 |= V_9 ;
F_10 ( V_2 , F_14 ( V_5 ) ) ;
V_2 = F_13 ( F_14 ( V_5 ) ) ;
if ( ( V_2 & 0x3f ) != V_9 )
V_8 = - V_10 ;
F_7 ( & V_4 , V_3 ) ;
if ( V_8 )
return V_8 ;
V_11 = V_7 ;
return 0 ;
}
static int F_15 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( F_16 ( 0 , & V_14 ) )
return - V_15 ;
F_9 () ;
F_2 () ;
return F_17 ( V_12 , V_13 ) ;
}
static int F_18 ( struct V_12 * V_12 , struct V_13 * V_13 )
{
if ( V_16 == 42 ) {
F_8 () ;
} else {
F_19 (KERN_CRIT PFX L_1
L_2 ) ;
F_9 () ;
}
F_20 ( 0 , & V_14 ) ;
V_16 = 0 ;
return 0 ;
}
static T_3 F_21 ( struct V_13 * V_13 , const char T_4 * V_17 ,
T_5 V_18 , T_6 * V_19 )
{
if ( V_18 ) {
if ( ! V_20 ) {
T_5 V_21 ;
V_16 = 0 ;
for ( V_21 = 0 ; V_21 != V_18 ; V_21 ++ ) {
char V_22 ;
if ( F_22 ( V_22 , V_17 + V_21 ) )
return - V_23 ;
if ( V_22 == 'V' )
V_16 = 42 ;
}
}
F_9 () ;
}
return V_18 ;
}
static long F_23 ( struct V_13 * V_13 , unsigned int V_24 ,
unsigned long V_25 )
{
int V_26 , V_27 = - V_10 ;
int V_28 ;
void T_4 * V_29 = ( void T_4 * ) V_25 ;
int T_4 * V_30 = V_29 ;
static const struct V_31 V_32 = {
. V_33 = V_34 |
V_35 |
V_36 ,
. V_37 = 0 ,
. V_38 = V_39 ,
} ;
switch ( V_24 ) {
case V_40 :
return F_24 ( V_29 , & V_32 , sizeof( V_32 ) ) ? - V_23 : 0 ;
case V_41 :
case V_42 :
return F_25 ( 0 , V_30 ) ;
case V_43 :
if ( F_22 ( V_26 , V_30 ) )
return - V_23 ;
if ( V_26 & V_44 ) {
F_8 () ;
V_27 = 0 ;
}
if ( V_26 & V_45 ) {
F_9 () ;
F_2 () ;
V_27 = 0 ;
}
return V_27 ;
case V_46 :
F_9 () ;
return 0 ;
case V_47 :
if ( F_22 ( V_28 , V_30 ) )
return - V_23 ;
if ( F_12 ( V_28 ) )
return - V_10 ;
F_9 () ;
case V_48 :
return F_25 ( V_11 , V_30 ) ;
default:
return - V_49 ;
}
}
static unsigned char T_7 F_26 ( void )
{
struct V_50 * V_51 = NULL ;
T_1 V_2 ;
F_27 (dev) {
if ( F_28 ( V_52 , V_51 ) != NULL ) {
V_53 = V_51 ;
break;
}
}
if ( ! V_53 )
return 0 ;
F_29 ( V_53 , 0x64 , & V_2 ) ;
V_2 &= 0xffff ;
if ( V_2 == 0x0001 || V_2 == 0x0000 ) {
F_19 (KERN_ERR PFX L_3 ) ;
return 0 ;
}
V_2 &= 0xff00 ;
V_5 = V_2 + 0x40 ;
if ( ! F_30 ( V_5 , 0x10 , L_4 ) ) {
F_19 (KERN_ERR PFX L_5 ,
tcobase) ;
return 0 ;
}
F_12 ( 30 ) ;
F_9 () ;
F_8 () ;
if ( ! F_30 ( F_31 ( V_5 ) , 4 , L_4 ) ) {
F_19 (KERN_ERR PFX L_5 ,
MCP51_SMI_EN(tcobase)) ;
goto V_54;
}
V_2 = F_4 ( F_31 ( V_5 ) ) ;
V_2 &= ~ V_55 ;
F_6 ( V_2 , F_31 ( V_5 ) ) ;
V_2 = F_4 ( F_31 ( V_5 ) ) ;
F_32 ( F_31 ( V_5 ) , 4 ) ;
if ( V_2 & V_55 ) {
F_19 (KERN_ERR PFX L_6 ) ;
goto V_54;
}
F_29 ( V_53 , V_56 , & V_2 ) ;
V_2 |= V_57 ;
F_33 ( V_53 , V_56 , V_2 ) ;
F_29 ( V_53 , V_56 , & V_2 ) ;
if ( ! ( V_2 & V_57 ) ) {
F_19 (KERN_ERR PFX L_7
L_8 ) ;
goto V_54;
}
return 1 ;
V_54:
F_32 ( V_5 , 0x10 ) ;
return 0 ;
}
static int T_7 F_34 ( struct V_58 * V_51 )
{
int V_8 ;
if ( ! F_26 () )
return - V_59 ;
F_19 (KERN_INFO PFX L_9 ,
inl(TCO_STS(tcobase)) & TCO_STS_TCO2TO_STS ? L_10 : L_11 ) ;
F_6 ( V_60 , F_35 ( V_5 ) ) ;
if ( F_12 ( V_11 ) ) {
V_11 = V_61 ;
F_12 ( V_11 ) ;
F_19 (KERN_INFO PFX L_12
L_13 , heartbeat) ;
}
V_8 = F_36 ( & V_62 ) ;
if ( V_8 != 0 ) {
F_19 (KERN_ERR PFX L_14
L_15 , WATCHDOG_MINOR, ret) ;
goto V_63;
}
F_20 ( 0 , & V_14 ) ;
F_8 () ;
F_19 (KERN_INFO PFX L_16
L_17 , tcobase, heartbeat, nowayout) ;
return 0 ;
V_63:
F_32 ( V_5 , 0x10 ) ;
return V_8 ;
}
static void T_8 F_37 ( void )
{
T_1 V_2 ;
if ( ! V_20 )
F_8 () ;
F_29 ( V_53 , V_56 , & V_2 ) ;
V_2 &= ~ V_57 ;
F_33 ( V_53 , V_56 , V_2 ) ;
F_29 ( V_53 , V_56 , & V_2 ) ;
if ( V_2 & V_57 ) {
F_19 (KERN_CRIT PFX L_18
L_19 ) ;
}
F_38 ( & V_62 ) ;
F_32 ( V_5 , 0x10 ) ;
}
static int T_8 F_39 ( struct V_58 * V_51 )
{
if ( V_5 )
F_37 () ;
return 0 ;
}
static void F_40 ( struct V_58 * V_51 )
{
F_8 () ;
}
static int T_9 F_41 ( void )
{
int V_64 ;
F_19 (KERN_INFO PFX L_20 ,
TCO_VERSION) ;
V_64 = F_42 ( & V_65 ) ;
if ( V_64 )
return V_64 ;
V_66 = F_43 (
V_39 , - 1 , NULL , 0 ) ;
if ( F_44 ( V_66 ) ) {
V_64 = F_45 ( V_66 ) ;
goto V_67;
}
return 0 ;
V_67:
F_46 ( & V_65 ) ;
return V_64 ;
}
static void T_10 F_47 ( void )
{
F_48 ( V_66 ) ;
F_46 ( & V_65 ) ;
F_19 (KERN_INFO PFX L_21 ) ;
}
