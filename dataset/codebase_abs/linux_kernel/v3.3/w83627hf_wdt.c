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
static int F_15 ( void )
{
int V_8 ;
F_10 ( & V_6 ) ;
F_1 () ;
F_2 ( 0xF6 , V_2 ) ;
V_8 = F_5 ( V_3 ) ;
F_6 () ;
F_11 ( & V_6 ) ;
return V_8 ;
}
static T_1 F_16 ( struct V_9 * V_9 , const char T_2 * V_10 ,
T_3 V_11 , T_4 * V_12 )
{
if ( V_11 ) {
if ( ! V_13 ) {
T_3 V_14 ;
V_15 = 0 ;
for ( V_14 = 0 ; V_14 != V_11 ; V_14 ++ ) {
char V_1 ;
if ( F_17 ( V_1 , V_10 + V_14 ) )
return - V_16 ;
if ( V_1 == 'V' )
V_15 = 42 ;
}
}
F_12 () ;
}
return V_11 ;
}
static long F_18 ( struct V_9 * V_9 , unsigned int V_17 , unsigned long V_18 )
{
void T_2 * V_19 = ( void T_2 * ) V_18 ;
int T_2 * V_20 = V_19 ;
int V_21 ;
static const struct V_22 V_23 = {
. V_24 = V_25 | V_26 |
V_27 ,
. V_28 = 1 ,
. V_29 = L_2 ,
} ;
switch ( V_17 ) {
case V_30 :
if ( F_19 ( V_19 , & V_23 , sizeof( V_23 ) ) )
return - V_16 ;
break;
case V_31 :
case V_32 :
return F_20 ( 0 , V_20 ) ;
case V_33 :
{
int V_24 , V_34 = - V_7 ;
if ( F_17 ( V_24 , V_20 ) )
return - V_16 ;
if ( V_24 & V_35 ) {
F_13 () ;
V_34 = 0 ;
}
if ( V_24 & V_36 ) {
F_12 () ;
V_34 = 0 ;
}
return V_34 ;
}
case V_37 :
F_12 () ;
break;
case V_38 :
if ( F_17 ( V_21 , V_20 ) )
return - V_16 ;
if ( F_14 ( V_21 ) )
return - V_7 ;
F_12 () ;
case V_39 :
return F_20 ( V_5 , V_20 ) ;
case V_40 :
V_21 = F_15 () ;
return F_20 ( V_21 , V_20 ) ;
default:
return - V_41 ;
}
return 0 ;
}
static int F_21 ( struct V_42 * V_42 , struct V_9 * V_9 )
{
if ( F_22 ( 0 , & V_43 ) )
return - V_44 ;
F_12 () ;
return F_23 ( V_42 , V_9 ) ;
}
static int F_24 ( struct V_42 * V_42 , struct V_9 * V_9 )
{
if ( V_15 == 42 )
F_13 () ;
else {
F_8 (KERN_CRIT PFX
L_3 ) ;
F_12 () ;
}
V_15 = 0 ;
F_25 ( 0 , & V_43 ) ;
return 0 ;
}
static int F_26 ( struct V_45 * V_46 , unsigned long V_47 ,
void * V_48 )
{
if ( V_47 == V_49 || V_47 == V_50 )
F_13 () ;
return V_51 ;
}
static int T_5 F_27 ( void )
{
int V_52 ;
F_8 ( V_53 L_4 ) ;
if ( F_14 ( V_5 ) ) {
F_14 ( V_54 ) ;
F_8 (KERN_INFO PFX
L_5 ,
WATCHDOG_TIMEOUT) ;
}
if ( ! F_28 ( V_55 , 1 , V_56 ) ) {
F_8 (KERN_ERR PFX L_6 ,
wdt_io) ;
V_52 = - V_57 ;
goto V_58;
}
F_7 () ;
V_52 = F_29 ( & V_59 ) ;
if ( V_52 != 0 ) {
F_8 (KERN_ERR PFX
L_7 , ret) ;
goto V_60;
}
V_52 = F_30 ( & V_61 ) ;
if ( V_52 != 0 ) {
F_8 (KERN_ERR PFX
L_8 ,
WATCHDOG_MINOR, ret) ;
goto V_62;
}
F_8 (KERN_INFO PFX
L_9 ,
timeout, nowayout) ;
V_58:
return V_52 ;
V_62:
F_31 ( & V_59 ) ;
V_60:
F_32 ( V_55 , 1 ) ;
goto V_58;
}
static void T_6 F_33 ( void )
{
F_34 ( & V_61 ) ;
F_31 ( & V_59 ) ;
F_32 ( V_55 , 1 ) ;
}
