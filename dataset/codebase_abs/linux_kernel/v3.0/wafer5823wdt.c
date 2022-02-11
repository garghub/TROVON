static void F_1 ( void )
{
F_2 ( & V_1 ) ;
F_3 ( V_2 ) ;
F_3 ( V_3 ) ;
F_4 ( & V_1 ) ;
}
static void F_5 ( void )
{
F_6 ( V_4 , V_3 ) ;
F_3 ( V_3 ) ;
}
static void F_7 ( void )
{
F_3 ( V_2 ) ;
}
static T_1 F_8 ( struct V_5 * V_5 , const char T_2 * V_6 ,
T_3 V_7 , T_4 * V_8 )
{
if ( V_7 ) {
if ( ! V_9 ) {
T_3 V_10 ;
V_11 = 0 ;
for ( V_10 = 0 ; V_10 != V_7 ; V_10 ++ ) {
char V_12 ;
if ( F_9 ( V_12 , V_6 + V_10 ) )
return - V_13 ;
if ( V_12 == 'V' )
V_11 = 42 ;
}
}
F_1 () ;
}
return V_7 ;
}
static long F_10 ( struct V_5 * V_5 , unsigned int V_14 ,
unsigned long V_15 )
{
int V_16 ;
void T_2 * V_17 = ( void T_2 * ) V_15 ;
int T_2 * V_18 = V_17 ;
static const struct V_19 V_20 = {
. V_21 = V_22 | V_23 |
V_24 ,
. V_25 = 1 ,
. V_26 = L_1 ,
} ;
switch ( V_14 ) {
case V_27 :
if ( F_11 ( V_17 , & V_20 , sizeof( V_20 ) ) )
return - V_13 ;
break;
case V_28 :
case V_29 :
return F_12 ( 0 , V_18 ) ;
case V_30 :
{
int V_21 , V_31 = - V_32 ;
if ( F_9 ( V_21 , V_18 ) )
return - V_13 ;
if ( V_21 & V_33 ) {
F_5 () ;
V_31 = 0 ;
}
if ( V_21 & V_34 ) {
F_7 () ;
V_31 = 0 ;
}
return V_31 ;
}
case V_35 :
F_1 () ;
break;
case V_36 :
if ( F_9 ( V_16 , V_18 ) )
return - V_13 ;
if ( ( V_16 < 1 ) || ( V_16 > 255 ) )
return - V_32 ;
V_4 = V_16 ;
F_7 () ;
F_5 () ;
case V_37 :
return F_12 ( V_4 , V_18 ) ;
default:
return - V_38 ;
}
return 0 ;
}
static int F_13 ( struct V_39 * V_39 , struct V_5 * V_5 )
{
if ( F_14 ( 0 , & V_40 ) )
return - V_41 ;
F_5 () ;
return F_15 ( V_39 , V_5 ) ;
}
static int F_16 ( struct V_39 * V_39 , struct V_5 * V_5 )
{
if ( V_11 == 42 )
F_7 () ;
else {
F_17 (KERN_CRIT PFX
L_2 ) ;
F_1 () ;
}
F_18 ( 0 , & V_40 ) ;
V_11 = 0 ;
return 0 ;
}
static int F_19 ( struct V_42 * V_43 , unsigned long V_44 ,
void * V_45 )
{
if ( V_44 == V_46 || V_44 == V_47 )
F_7 () ;
return V_48 ;
}
static int T_5 F_20 ( void )
{
int V_49 ;
F_17 ( V_50
L_3 ) ;
if ( V_4 < 1 || V_4 > 255 ) {
V_4 = V_51 ;
F_17 (KERN_INFO PFX
L_4 ,
timeout) ;
}
if ( V_2 != V_3 ) {
if ( ! F_21 ( V_2 , 1 , L_1 ) ) {
F_17 (KERN_ERR PFX
L_5 ,
wdt_stop) ;
V_49 = - V_52 ;
goto error;
}
}
if ( ! F_21 ( V_3 , 1 , L_1 ) ) {
F_17 (KERN_ERR PFX L_5 ,
wdt_start) ;
V_49 = - V_52 ;
goto V_53;
}
V_49 = F_22 ( & V_54 ) ;
if ( V_49 != 0 ) {
F_17 (KERN_ERR PFX
L_6 , ret) ;
goto V_55;
}
V_49 = F_23 ( & V_56 ) ;
if ( V_49 != 0 ) {
F_17 (KERN_ERR PFX
L_7 ,
WATCHDOG_MINOR, ret) ;
goto V_57;
}
F_17 (KERN_INFO PFX L_8 ,
timeout, nowayout) ;
return V_49 ;
V_57:
F_24 ( & V_54 ) ;
V_55:
F_25 ( V_3 , 1 ) ;
V_53:
if ( V_2 != V_3 )
F_25 ( V_2 , 1 ) ;
error:
return V_49 ;
}
static void T_6 F_26 ( void )
{
F_27 ( & V_56 ) ;
F_24 ( & V_54 ) ;
if ( V_2 != V_3 )
F_25 ( V_2 , 1 ) ;
F_25 ( V_3 , 1 ) ;
}
