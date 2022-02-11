static void F_1 ( void )
{
unsigned char V_1 ;
F_2 ( 0x87 , V_2 ) ;
F_2 ( 0x87 , V_2 ) ;
F_3 ( 0x20 , V_2 ) ;
V_1 = F_4 ( V_3 ) ;
if ( V_1 == 0x82 ) {
F_2 ( 0x2b , V_2 ) ;
V_1 = ( ( F_5 ( V_3 ) & 0xf7 ) | 0x04 ) ;
F_2 ( 0x2b , V_2 ) ;
F_2 ( V_1 , V_3 ) ;
} else if ( V_1 == 0x88 || V_1 == 0xa0 ) {
F_2 ( 0x2d , V_2 ) ;
V_1 = F_5 ( V_3 ) & ~ 0x01 ;
F_2 ( 0x2d , V_2 ) ;
F_2 ( V_1 , V_3 ) ;
}
F_2 ( 0x07 , V_2 ) ;
F_2 ( 0x08 , V_3 ) ;
F_2 ( 0x30 , V_2 ) ;
F_2 ( 0x01 , V_3 ) ;
}
static void F_6 ( void )
{
F_2 ( 0xAA , V_2 ) ;
}
static void F_7 ( void )
{
unsigned char V_4 ;
F_1 () ;
F_2 ( 0xF6 , V_2 ) ;
V_4 = F_5 ( V_3 ) ;
if ( V_4 != 0 ) {
F_8 (KERN_INFO PFX
L_1 ,
timeout) ;
F_2 ( V_5 , V_3 ) ;
}
F_2 ( 0xF5 , V_2 ) ;
V_4 = F_5 ( V_3 ) ;
V_4 &= ~ 0x0C ;
V_4 |= 0x02 ;
F_2 ( V_4 , V_3 ) ;
F_2 ( 0xF7 , V_2 ) ;
V_4 = F_5 ( V_3 ) ;
V_4 &= ~ 0xC0 ;
F_2 ( V_4 , V_3 ) ;
F_6 () ;
}
static void F_9 ( int V_5 )
{
F_10 ( & V_6 ) ;
F_1 () ;
F_2 ( 0xF6 , V_2 ) ;
F_2 ( V_5 , V_3 ) ;
F_6 () ;
F_11 ( & V_6 ) ;
}
static int F_12 ( void )
{
F_9 ( V_5 ) ;
return 0 ;
}
static int F_13 ( void )
{
F_9 ( 0 ) ;
return 0 ;
}
static int F_14 ( int V_4 )
{
if ( V_4 < 1 || V_4 > 255 )
return - V_7 ;
V_5 = V_4 ;
return 0 ;
}
static T_1 F_15 ( struct V_8 * V_8 , const char T_2 * V_9 ,
T_3 V_10 , T_4 * V_11 )
{
if ( V_10 ) {
if ( ! V_12 ) {
T_3 V_13 ;
V_14 = 0 ;
for ( V_13 = 0 ; V_13 != V_10 ; V_13 ++ ) {
char V_1 ;
if ( F_16 ( V_1 , V_9 + V_13 ) )
return - V_15 ;
if ( V_1 == 'V' )
V_14 = 42 ;
}
}
F_12 () ;
}
return V_10 ;
}
static long F_17 ( struct V_8 * V_8 , unsigned int V_16 , unsigned long V_17 )
{
void T_2 * V_18 = ( void T_2 * ) V_17 ;
int T_2 * V_19 = V_18 ;
int V_20 ;
static const struct V_21 V_22 = {
. V_23 = V_24 | V_25 |
V_26 ,
. V_27 = 1 ,
. V_28 = L_2 ,
} ;
switch ( V_16 ) {
case V_29 :
if ( F_18 ( V_18 , & V_22 , sizeof( V_22 ) ) )
return - V_15 ;
break;
case V_30 :
case V_31 :
return F_19 ( 0 , V_19 ) ;
case V_32 :
{
int V_23 , V_33 = - V_7 ;
if ( F_16 ( V_23 , V_19 ) )
return - V_15 ;
if ( V_23 & V_34 ) {
F_13 () ;
V_33 = 0 ;
}
if ( V_23 & V_35 ) {
F_12 () ;
V_33 = 0 ;
}
return V_33 ;
}
case V_36 :
F_12 () ;
break;
case V_37 :
if ( F_16 ( V_20 , V_19 ) )
return - V_15 ;
if ( F_14 ( V_20 ) )
return - V_7 ;
F_12 () ;
case V_38 :
return F_19 ( V_5 , V_19 ) ;
default:
return - V_39 ;
}
return 0 ;
}
static int F_20 ( struct V_40 * V_40 , struct V_8 * V_8 )
{
if ( F_21 ( 0 , & V_41 ) )
return - V_42 ;
F_12 () ;
return F_22 ( V_40 , V_8 ) ;
}
static int F_23 ( struct V_40 * V_40 , struct V_8 * V_8 )
{
if ( V_14 == 42 )
F_13 () ;
else {
F_8 (KERN_CRIT PFX
L_3 ) ;
F_12 () ;
}
V_14 = 0 ;
F_24 ( 0 , & V_41 ) ;
return 0 ;
}
static int F_25 ( struct V_43 * V_44 , unsigned long V_45 ,
void * V_46 )
{
if ( V_45 == V_47 || V_45 == V_48 )
F_13 () ;
return V_49 ;
}
static int T_5 F_26 ( void )
{
int V_50 ;
F_8 ( V_51 L_4 ) ;
if ( F_14 ( V_5 ) ) {
F_14 ( V_52 ) ;
F_8 (KERN_INFO PFX
L_5 ,
WATCHDOG_TIMEOUT) ;
}
if ( ! F_27 ( V_53 , 1 , V_54 ) ) {
F_8 (KERN_ERR PFX L_6 ,
wdt_io) ;
V_50 = - V_55 ;
goto V_56;
}
F_7 () ;
V_50 = F_28 ( & V_57 ) ;
if ( V_50 != 0 ) {
F_8 (KERN_ERR PFX
L_7 , ret) ;
goto V_58;
}
V_50 = F_29 ( & V_59 ) ;
if ( V_50 != 0 ) {
F_8 (KERN_ERR PFX
L_8 ,
WATCHDOG_MINOR, ret) ;
goto V_60;
}
F_8 (KERN_INFO PFX
L_9 ,
timeout, nowayout) ;
V_56:
return V_50 ;
V_60:
F_30 ( & V_57 ) ;
V_58:
F_31 ( V_53 , 1 ) ;
goto V_56;
}
static void T_6 F_32 ( void )
{
F_33 ( & V_59 ) ;
F_30 ( & V_57 ) ;
F_31 ( V_53 , 1 ) ;
}
