static int F_1 ( void )
{
unsigned char V_1 ;
unsigned char V_2 ;
F_2 ( 0x87 , V_3 ) ;
F_2 ( 0x87 , V_3 ) ;
F_3 ( 0x20 , V_3 ) ;
V_2 = F_4 ( V_4 ) ;
if ( V_2 == 0x68 ) {
F_5 (KERN_INFO PFX L_1
L_2 , version, wdt_io) ;
F_2 ( 0x2b , V_3 ) ;
V_1 = F_6 ( V_4 ) ;
V_1 &= ~ 0x04 ;
F_2 ( 0x2b , V_3 ) ;
F_2 ( V_1 , V_4 ) ;
} else {
F_5 (KERN_ERR PFX L_3 ) ;
return - V_5 ;
}
F_2 ( 0x07 , V_3 ) ;
F_2 ( 0x08 , V_4 ) ;
F_2 ( 0x30 , V_3 ) ;
V_1 = F_6 ( V_4 ) ;
F_2 ( V_1 | 0x01 , V_4 ) ;
return 0 ;
}
static void F_7 ( void )
{
F_2 ( 0xAA , V_3 ) ;
}
static int F_8 ( void )
{
int V_6 ;
unsigned char V_7 ;
V_6 = F_1 () ;
if ( V_6 != 0 )
return V_6 ;
F_2 ( 0xF6 , V_3 ) ;
V_7 = F_6 ( V_4 ) ;
if ( V_7 != 0 ) {
F_5 (KERN_INFO PFX L_4
L_5 , timeout) ;
F_2 ( V_8 , V_4 ) ;
}
F_2 ( 0xF5 , V_3 ) ;
V_7 = F_6 ( V_4 ) ;
V_7 &= ~ 0x0C ;
F_2 ( V_7 , V_4 ) ;
F_7 () ;
return 0 ;
}
static void F_9 ( int V_8 )
{
F_10 ( & V_9 ) ;
if ( F_1 () < 0 ) {
F_11 ( & V_9 ) ;
return;
}
F_2 ( 0xF4 , V_3 ) ;
F_2 ( V_8 , V_4 ) ;
F_7 () ;
F_11 ( & V_9 ) ;
}
static int F_12 ( void )
{
F_9 ( V_8 ) ;
return 0 ;
}
static int F_13 ( void )
{
F_9 ( 0 ) ;
return 0 ;
}
static int F_14 ( int V_7 )
{
if ( V_7 < 1 || V_7 > 255 )
return - V_10 ;
V_8 = V_7 ;
return 0 ;
}
static T_1 F_15 ( struct V_11 * V_11 , const char T_2 * V_12 ,
T_3 V_13 , T_4 * V_14 )
{
if ( V_13 ) {
if ( ! V_15 ) {
T_3 V_16 ;
V_17 = 0 ;
for ( V_16 = 0 ; V_16 != V_13 ; V_16 ++ ) {
char V_1 ;
if ( F_16 ( V_1 , V_12 + V_16 ) )
return - V_18 ;
if ( V_1 == 'V' )
V_17 = 42 ;
}
}
F_12 () ;
}
return V_13 ;
}
static long F_17 ( struct V_11 * V_11 , unsigned int V_19 , unsigned long V_20 )
{
void T_2 * V_21 = ( void T_2 * ) V_20 ;
int T_2 * V_22 = V_21 ;
int V_23 ;
static const struct V_24 V_25 = {
. V_26 = V_27 |
V_28 |
V_29 ,
. V_30 = 1 ,
. V_31 = L_6 ,
} ;
switch ( V_19 ) {
case V_32 :
if ( F_18 ( V_21 , & V_25 , sizeof( V_25 ) ) )
return - V_18 ;
break;
case V_33 :
case V_34 :
return F_19 ( 0 , V_22 ) ;
case V_35 :
{
int V_26 , V_36 = - V_10 ;
if ( F_16 ( V_26 , V_22 ) )
return - V_18 ;
if ( V_26 & V_37 ) {
F_13 () ;
V_36 = 0 ;
}
if ( V_26 & V_38 ) {
F_12 () ;
V_36 = 0 ;
}
return V_36 ;
}
case V_39 :
F_12 () ;
break;
case V_40 :
if ( F_16 ( V_23 , V_22 ) )
return - V_18 ;
if ( F_14 ( V_23 ) )
return - V_10 ;
F_12 () ;
case V_41 :
return F_19 ( V_8 , V_22 ) ;
default:
return - V_42 ;
}
return 0 ;
}
static int F_20 ( struct V_43 * V_43 , struct V_11 * V_11 )
{
if ( F_21 ( 0 , & V_44 ) )
return - V_45 ;
F_12 () ;
return F_22 ( V_43 , V_11 ) ;
}
static int F_23 ( struct V_43 * V_43 , struct V_11 * V_11 )
{
if ( V_17 == 42 )
F_13 () ;
else {
F_5 (KERN_CRIT PFX
L_7 ) ;
F_12 () ;
}
V_17 = 0 ;
F_24 ( 0 , & V_44 ) ;
return 0 ;
}
static int F_25 ( struct V_46 * V_47 , unsigned long V_48 ,
void * V_49 )
{
if ( V_48 == V_50 || V_48 == V_51 )
F_13 () ;
return V_52 ;
}
static int T_5 F_26 ( void )
{
int V_6 ;
F_5 ( V_53 L_8 ) ;
if ( F_14 ( V_8 ) ) {
F_14 ( V_54 ) ;
F_5 (KERN_INFO PFX
L_9 ,
WATCHDOG_TIMEOUT) ;
}
if ( ! F_27 ( V_55 , 1 , V_56 ) ) {
F_5 (KERN_ERR PFX L_10 ,
wdt_io) ;
V_6 = - V_57 ;
goto V_58;
}
V_6 = F_8 () ;
if ( V_6 != 0 )
goto V_59;
V_6 = F_28 ( & V_60 ) ;
if ( V_6 != 0 ) {
F_5 (KERN_ERR PFX
L_11 , ret) ;
goto V_59;
}
V_6 = F_29 ( & V_61 ) ;
if ( V_6 != 0 ) {
F_5 (KERN_ERR PFX
L_12 ,
WATCHDOG_MINOR, ret) ;
goto V_62;
}
F_5 (KERN_INFO PFX L_13 ,
timeout, nowayout) ;
V_58:
return V_6 ;
V_62:
F_30 ( & V_60 ) ;
V_59:
F_31 ( V_55 , 1 ) ;
goto V_58;
}
static void T_6 F_32 ( void )
{
F_33 ( & V_61 ) ;
F_30 ( & V_60 ) ;
F_31 ( V_55 , 1 ) ;
}
