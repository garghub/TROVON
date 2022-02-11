static void F_1 ( void )
{
F_2 ( V_1 , V_2 ) ;
}
static void F_3 ( void )
{
F_4 ( V_3 ) ;
}
static int F_5 ( int V_4 )
{
if ( V_4 < 1 || V_4 > 63 )
return - V_5 ;
V_1 = V_4 ;
return 0 ;
}
static T_1 F_6 ( struct V_6 * V_6 , const char T_2 * V_7 ,
T_3 V_8 , T_4 * V_9 )
{
if ( V_8 ) {
if ( ! V_10 ) {
T_3 V_11 ;
V_12 = 0 ;
for ( V_11 = 0 ; V_11 != V_8 ; V_11 ++ ) {
char V_13 ;
if ( F_7 ( V_13 , V_7 + V_11 ) )
return - V_14 ;
if ( V_13 == 'V' )
V_12 = 42 ;
}
}
F_1 () ;
}
return V_8 ;
}
static long F_8 ( struct V_6 * V_6 , unsigned int V_15 , unsigned long V_16 )
{
int V_17 ;
void T_2 * V_18 = ( void T_2 * ) V_16 ;
int T_2 * V_19 = V_18 ;
static const struct V_20 V_21 = {
. V_22 = V_23 |
V_24 |
V_25 ,
. V_26 = 1 ,
. V_27 = V_28 ,
} ;
switch ( V_15 ) {
case V_29 :
if ( F_9 ( V_18 , & V_21 , sizeof( V_21 ) ) )
return - V_14 ;
break;
case V_30 :
case V_31 :
return F_10 ( 0 , V_19 ) ;
case V_32 :
{
int V_22 , V_33 = - V_5 ;
if ( F_7 ( V_22 , V_19 ) )
return - V_14 ;
if ( V_22 & V_34 ) {
F_3 () ;
V_33 = 0 ;
}
if ( V_22 & V_35 ) {
F_1 () ;
V_33 = 0 ;
}
return V_33 ;
}
case V_36 :
F_1 () ;
break;
case V_37 :
if ( F_7 ( V_17 , V_19 ) )
return - V_14 ;
if ( F_5 ( V_17 ) )
return - V_5 ;
F_1 () ;
case V_38 :
return F_10 ( V_1 , V_19 ) ;
default:
return - V_39 ;
}
return 0 ;
}
static int F_11 ( struct V_40 * V_40 , struct V_6 * V_6 )
{
if ( F_12 ( 0 , & V_41 ) )
return - V_42 ;
F_1 () ;
return F_13 ( V_40 , V_6 ) ;
}
static int F_14 ( struct V_40 * V_40 , struct V_6 * V_6 )
{
if ( V_12 == 42 ) {
F_3 () ;
} else {
F_15 (KERN_CRIT PFX
L_1 ) ;
F_1 () ;
}
F_16 ( 0 , & V_41 ) ;
V_12 = 0 ;
return 0 ;
}
static int T_5 F_17 ( struct V_43 * V_44 )
{
int V_45 ;
if ( V_3 != V_2 ) {
if ( ! F_18 ( V_3 , 1 , V_28 ) ) {
F_15 (KERN_ERR PFX
L_2 ,
wdt_stop) ;
V_45 = - V_46 ;
goto V_47;
}
}
if ( ! F_18 ( V_2 , 1 , V_28 ) ) {
F_15 (KERN_ERR PFX
L_2 ,
wdt_start) ;
V_45 = - V_46 ;
goto V_48;
}
if ( F_5 ( V_1 ) ) {
F_5 ( V_49 ) ;
F_15 (KERN_INFO PFX
L_3 , timeout) ;
}
V_45 = F_19 ( & V_50 ) ;
if ( V_45 != 0 ) {
F_15 (KERN_ERR PFX
L_4 ,
WATCHDOG_MINOR, ret) ;
goto V_51;
}
F_15 (KERN_INFO PFX L_5 ,
timeout, nowayout) ;
V_47:
return V_45 ;
V_51:
F_20 ( V_2 , 1 ) ;
V_48:
if ( V_3 != V_2 )
F_20 ( V_3 , 1 ) ;
goto V_47;
}
static int T_6 F_21 ( struct V_43 * V_44 )
{
F_22 ( & V_50 ) ;
F_20 ( V_2 , 1 ) ;
if ( V_3 != V_2 )
F_20 ( V_3 , 1 ) ;
return 0 ;
}
static void F_23 ( struct V_43 * V_44 )
{
F_3 () ;
}
static int T_7 F_24 ( void )
{
int V_52 ;
F_15 ( V_53
L_6 ) ;
V_52 = F_25 ( & V_54 ) ;
if ( V_52 )
return V_52 ;
V_55 = F_26 ( V_56 ,
- 1 , NULL , 0 ) ;
if ( F_27 ( V_55 ) ) {
V_52 = F_28 ( V_55 ) ;
goto V_57;
}
return 0 ;
V_57:
F_29 ( & V_54 ) ;
return V_52 ;
}
static void T_8 F_30 ( void )
{
F_31 ( V_55 ) ;
F_29 ( & V_54 ) ;
F_15 (KERN_INFO PFX L_7 ) ;
}
