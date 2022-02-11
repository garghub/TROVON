static inline void F_1 ( void )
{
F_2 ( V_1 , V_2 ) ;
F_2 ( V_3 , V_2 ) ;
}
static int F_3 ( void )
{
T_1 V_4 ;
F_4 ( & V_5 ) ;
F_1 () ;
F_2 ( V_6 , V_2 ) ;
V_4 = V_7 | ( V_8 ? V_9 : 0x00 ) ;
F_5 ( V_10 , V_11 , V_4 ) ;
F_6 ( & V_5 ) ;
return 0 ;
}
static int F_7 ( void )
{
T_1 V_4 ;
F_4 ( & V_5 ) ;
F_1 () ;
F_2 ( V_6 , V_2 ) ;
F_5 ( V_10 , V_11 , 0x0 ) ;
F_8 ( V_10 , V_11 , & V_4 ) ;
F_6 ( & V_5 ) ;
return V_4 & V_7 ;
}
static void F_9 ( void )
{
F_4 ( & V_5 ) ;
F_1 () ;
F_2 ( V_6 , V_2 ) ;
F_6 ( & V_5 ) ;
}
static int F_10 ( int time )
{
T_2 V_4 ;
if ( time < 0x1 || time > ( 2 * 0x03ff ) )
return - V_12 ;
F_4 ( & V_5 ) ;
V_4 = time << 9 ;
F_1 () ;
F_11 ( V_4 , V_13 ) ;
F_1 () ;
F_11 ( V_4 , V_14 ) ;
F_1 () ;
F_2 ( V_6 , V_2 ) ;
V_15 = time ;
F_6 ( & V_5 ) ;
return 0 ;
}
static int F_12 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
if ( F_13 ( 0 , & V_18 ) )
return - V_19 ;
F_3 () ;
return F_14 ( V_16 , V_17 ) ;
}
static int F_15 ( struct V_16 * V_16 , struct V_17 * V_17 )
{
if ( V_20 == 42 )
F_7 () ;
else {
F_16 (KERN_CRIT PFX
L_1 ) ;
F_9 () ;
}
F_17 ( 0 , & V_18 ) ;
V_20 = 0 ;
return 0 ;
}
static T_3 F_18 ( struct V_17 * V_17 , const char T_4 * V_21 ,
T_5 V_22 , T_6 * V_23 )
{
if ( V_22 ) {
if ( ! V_8 ) {
T_5 V_24 ;
V_20 = 0 ;
for ( V_24 = 0 ; V_24 != V_22 ; V_24 ++ ) {
char V_25 ;
if ( F_19 ( V_25 , V_21 + V_24 ) )
return - V_26 ;
if ( V_25 == 'V' )
V_20 = 42 ;
}
}
F_9 () ;
}
return V_22 ;
}
static long F_20 ( struct V_17 * V_17 , unsigned int V_27 , unsigned long V_28 )
{
int V_29 , V_30 = - V_12 ;
int V_31 ;
void T_4 * V_32 = ( void T_4 * ) V_28 ;
int T_4 * V_33 = V_32 ;
static const struct V_34 V_35 = {
. V_36 = V_37 |
V_38 |
V_39 ,
. V_40 = 0 ,
. V_41 = V_42 ,
} ;
switch ( V_27 ) {
case V_43 :
return F_21 ( V_32 , & V_35 ,
sizeof( V_35 ) ) ? - V_26 : 0 ;
case V_44 :
return F_22 ( 0 , V_33 ) ;
case V_45 :
return F_22 ( V_46 , V_33 ) ;
case V_47 :
{
if ( F_19 ( V_29 , V_33 ) )
return - V_26 ;
if ( V_29 & V_48 ) {
F_7 () ;
V_30 = 0 ;
}
if ( V_29 & V_49 ) {
F_3 () ;
V_30 = 0 ;
}
return V_30 ;
}
case V_50 :
F_9 () ;
return 0 ;
case V_51 :
{
if ( F_19 ( V_31 , V_33 ) )
return - V_26 ;
if ( F_10 ( V_31 ) )
return - V_12 ;
F_9 () ;
}
case V_52 :
return F_22 ( V_15 , V_33 ) ;
default:
return - V_53 ;
}
}
static unsigned char T_7 F_23 ( struct V_54 * V_55 )
{
if ( F_24 ( V_55 ) ) {
F_16 (KERN_ERR PFX L_2 ) ;
goto V_56;
}
if ( F_25 ( V_55 , 0 , V_42 ) ) {
F_16 (KERN_ERR PFX L_3 ) ;
goto V_57;
}
V_58 = F_26 ( V_55 , 0 ) ;
if ( V_58 == NULL ) {
F_16 (KERN_ERR PFX L_4 ) ;
goto V_59;
}
V_10 = V_55 ;
return 1 ;
V_59:
F_27 ( V_55 , 0 ) ;
V_57:
F_28 ( V_55 ) ;
V_56:
return 0 ;
}
static void T_7 F_29 ( void )
{
T_1 V_60 ;
T_8 V_61 ;
F_30 ( V_10 , V_62 , 0x0003 ) ;
F_8 ( V_10 , V_11 , & V_60 ) ;
if ( V_60 & V_9 )
F_16 (KERN_WARNING PFX L_5 ) ;
F_5 ( V_10 , V_11 , 0x00 ) ;
F_1 () ;
V_61 = F_31 ( V_2 ) ;
if ( V_61 & V_63 )
V_46 = V_64 ;
F_1 () ;
F_2 ( ( V_63 | V_6 ) , V_2 ) ;
F_10 ( V_15 ) ;
}
static int T_7 F_32 ( struct V_54 * V_55 ,
const struct V_65 * V_66 )
{
int V_67 ;
V_68 ++ ;
if ( V_68 == 1 )
F_16 (KERN_INFO PFX L_6 ,
ESB_VERSION) ;
if ( V_68 > 1 ) {
F_16 (KERN_ERR PFX L_7 ) ;
return - V_69 ;
}
if ( ! F_23 ( V_55 ) || V_10 == NULL )
return - V_69 ;
if ( V_15 < 0x1 || V_15 > 2 * 0x03ff ) {
V_15 = V_70 ;
F_16 (KERN_INFO PFX
L_8 ,
heartbeat) ;
}
F_29 () ;
V_67 = F_33 ( & V_71 ) ;
if ( V_67 != 0 ) {
F_16 (KERN_ERR PFX
L_9 ,
WATCHDOG_MINOR, ret) ;
goto V_72;
}
F_16 (KERN_INFO PFX
L_10 ,
BASEADDR, heartbeat, nowayout) ;
return 0 ;
V_72:
F_34 ( V_58 ) ;
F_27 ( V_10 , 0 ) ;
F_28 ( V_10 ) ;
V_10 = NULL ;
return V_67 ;
}
static void T_9 F_35 ( struct V_54 * V_55 )
{
if ( ! V_8 )
F_7 () ;
F_36 ( & V_71 ) ;
F_34 ( V_58 ) ;
F_27 ( V_10 , 0 ) ;
F_28 ( V_10 ) ;
V_10 = NULL ;
}
static void F_37 ( struct V_54 * V_55 )
{
F_7 () ;
}
static int T_10 F_38 ( void )
{
return F_39 ( & V_73 ) ;
}
static void T_11 F_40 ( void )
{
F_41 ( & V_73 ) ;
F_16 (KERN_INFO PFX L_11 ) ;
}
