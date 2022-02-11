static void F_1 ( void )
{
T_1 V_1 ;
F_2 ( & V_2 ) ;
F_3 ( V_3 , 0xCC , & V_1 ) ;
V_1 &= ~ 0x3F ;
V_1 |= ( 1 << 25 ) | V_4 ;
F_4 ( V_3 , 0xCC , V_1 ) ;
F_5 ( & V_2 ) ;
}
static void F_6 ( void )
{
T_1 V_1 ;
F_2 ( & V_2 ) ;
F_3 ( V_3 , 0xCC , & V_1 ) ;
V_1 &= ~ 0x3F ;
V_1 &= ~ ( 1 << 25 ) ;
F_4 ( V_3 , 0xCC , V_1 ) ;
F_5 ( & V_2 ) ;
}
static void F_7 ( void )
{
F_1 () ;
}
static int F_8 ( int V_5 )
{
if ( V_5 < 0 )
return - V_6 ;
else if ( V_5 < 60 )
V_4 = V_5 | ( 1 << 6 ) ;
else if ( V_5 < 3600 )
V_4 = ( V_5 / 60 ) | ( 1 << 7 ) ;
else if ( V_5 < 18000 )
V_4 = ( V_5 / 300 ) | ( 1 << 6 ) | ( 1 << 7 ) ;
else
return - V_6 ;
V_7 = V_5 ;
return 0 ;
}
static T_2 F_9 ( struct V_8 * V_8 , const char T_3 * V_9 ,
T_4 V_10 , T_5 * V_11 )
{
if ( V_10 ) {
if ( ! V_12 ) {
T_4 V_13 ;
V_14 = 0 ;
for ( V_13 = 0 ; V_13 != V_10 ; V_13 ++ ) {
char V_15 ;
if ( F_10 ( V_15 , V_9 + V_13 ) )
return - V_16 ;
if ( V_15 == 'V' )
V_14 = 42 ;
}
}
F_1 () ;
}
return V_10 ;
}
static long F_11 ( struct V_8 * V_8 , unsigned int V_17 , unsigned long V_18 )
{
void T_3 * V_19 = ( void T_3 * ) V_18 ;
int T_3 * V_20 = V_19 ;
static const struct V_21 V_22 = {
. V_23 = V_24 |
V_25 |
V_26 ,
. V_27 = 0 ,
. V_28 = L_1 ,
} ;
switch ( V_17 ) {
case V_29 :
return F_12 ( V_19 , & V_22 , sizeof( V_22 ) ) ? - V_16 : 0 ;
case V_30 :
case V_31 :
return F_13 ( 0 , V_20 ) ;
case V_32 :
{
int V_33 , V_34 = - V_6 ;
if ( F_10 ( V_33 , V_20 ) )
return - V_16 ;
if ( V_33 & V_35 ) {
F_6 () ;
V_34 = 0 ;
}
if ( V_33 & V_36 ) {
F_1 () ;
V_34 = 0 ;
}
return V_34 ;
}
case V_37 :
F_7 () ;
return 0 ;
case V_38 :
{
int V_39 ;
if ( F_10 ( V_39 , V_20 ) )
return - V_16 ;
if ( F_8 ( V_39 ) )
return - V_6 ;
F_7 () ;
}
case V_40 :
return F_13 ( V_7 , V_20 ) ;
default:
return - V_41 ;
}
}
static int F_14 ( struct V_42 * V_42 , struct V_8 * V_8 )
{
if ( F_15 ( 0 , & V_43 ) )
return - V_44 ;
F_1 () ;
return F_16 ( V_42 , V_8 ) ;
}
static int F_17 ( struct V_42 * V_42 , struct V_8 * V_8 )
{
if ( V_14 == 42 )
F_6 () ;
else {
F_18 (KERN_CRIT PFX
L_2 ) ;
F_7 () ;
}
F_19 ( 0 , & V_43 ) ;
V_14 = 0 ;
return 0 ;
}
static int F_20 ( struct V_45 * V_46 ,
unsigned long V_47 , void * V_48 )
{
if ( V_47 == V_49 || V_47 == V_50 )
F_6 () ;
return V_51 ;
}
static int T_6 F_21 ( void )
{
struct V_52 * V_53 ;
T_1 V_54 ;
V_53 = F_22 ( V_55 , 0x1535 , NULL ) ;
if ( V_53 == NULL )
V_53 = F_22 ( V_55 , 0x1533 , NULL ) ;
if ( V_53 == NULL )
return - V_56 ;
F_23 ( V_53 ) ;
V_53 = F_22 ( V_55 , 0x7101 , NULL ) ;
if ( V_53 == NULL )
return - V_56 ;
if ( F_24 ( V_53 ) ) {
F_23 ( V_53 ) ;
return - V_57 ;
}
V_3 = V_53 ;
F_3 ( V_53 , 0xCC , & V_54 ) ;
V_54 &= ~ 0x3F ;
V_54 &= ~ ( ( 1 << 27 ) | ( 1 << 26 ) | ( 1 << 25 ) | ( 1 << 24 ) ) ;
V_54 &= ~ ( ( 1 << 16 ) | ( 1 << 13 ) | ( 1 << 12 ) | ( 1 << 11 ) | ( 1 << 10 ) | ( 1 << 9 ) ) ;
F_4 ( V_53 , 0xCC , V_54 ) ;
return 0 ;
}
static int T_6 F_25 ( void )
{
int V_58 ;
if ( F_21 () != 0 )
return - V_56 ;
if ( V_7 < 1 || V_7 >= 18000 ) {
V_7 = V_59 ;
F_18 (KERN_INFO PFX
L_3 ,
timeout) ;
}
F_8 ( V_7 ) ;
V_58 = F_26 ( & V_60 ) ;
if ( V_58 != 0 ) {
F_18 (KERN_ERR PFX
L_4 , ret) ;
goto V_61;
}
V_58 = F_27 ( & V_62 ) ;
if ( V_58 != 0 ) {
F_18 (KERN_ERR PFX
L_5 ,
WATCHDOG_MINOR, ret) ;
goto V_63;
}
F_18 (KERN_INFO PFX L_6 ,
timeout, nowayout) ;
V_61:
return V_58 ;
V_63:
F_28 ( & V_60 ) ;
goto V_61;
}
static void T_7 F_29 ( void )
{
F_6 () ;
F_30 ( & V_62 ) ;
F_28 ( & V_60 ) ;
F_23 ( V_3 ) ;
}
