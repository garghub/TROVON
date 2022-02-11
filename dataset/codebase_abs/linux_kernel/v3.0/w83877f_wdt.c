static void F_1 ( unsigned long V_1 )
{
if ( F_2 ( V_2 , V_3 ) ) {
F_3 ( & V_4 ) ;
F_4 ( V_5 ) ;
F_5 ( & V_6 , V_2 + V_7 ) ;
F_6 ( & V_4 ) ;
} else
F_7 (KERN_WARNING PFX
L_1 ) ;
}
static void F_8 ( int V_8 )
{
unsigned long V_9 ;
F_9 ( & V_4 , V_9 ) ;
F_4 ( V_5 ) ;
F_10 ( V_10 , V_11 ) ;
F_10 ( V_10 , V_11 ) ;
F_10 ( V_12 , V_11 ) ;
F_10 ( V_8 , V_11 + 1 ) ;
F_10 ( V_13 , V_11 ) ;
F_11 ( & V_4 , V_9 ) ;
}
static void F_12 ( void )
{
V_3 = V_2 + ( V_14 * V_15 ) ;
F_5 ( & V_6 , V_2 + V_7 ) ;
F_8 ( V_16 ) ;
F_7 (KERN_INFO PFX L_2 ) ;
}
static void F_13 ( void )
{
F_14 ( & V_6 ) ;
F_8 ( V_17 ) ;
F_7 (KERN_INFO PFX L_3 ) ;
}
static void F_15 ( void )
{
V_3 = V_2 + ( V_14 * V_15 ) ;
}
static T_1 F_16 ( struct V_18 * V_18 , const char T_2 * V_19 ,
T_3 V_20 , T_4 * V_21 )
{
if ( V_20 ) {
if ( ! V_22 ) {
T_3 V_23 ;
V_24 = 0 ;
for ( V_23 = 0 ; V_23 != V_20 ; V_23 ++ ) {
char V_25 ;
if ( F_17 ( V_25 , V_19 + V_23 ) )
return - V_26 ;
if ( V_25 == 'V' )
V_24 = 42 ;
}
}
F_15 () ;
}
return V_20 ;
}
static int F_18 ( struct V_27 * V_27 , struct V_18 * V_18 )
{
if ( F_19 ( 0 , & V_28 ) )
return - V_29 ;
F_12 () ;
return F_20 ( V_27 , V_18 ) ;
}
static int F_21 ( struct V_27 * V_27 , struct V_18 * V_18 )
{
if ( V_24 == 42 )
F_13 () ;
else {
F_14 ( & V_6 ) ;
F_7 (KERN_CRIT PFX
L_4 ) ;
}
F_22 ( 0 , & V_28 ) ;
V_24 = 0 ;
return 0 ;
}
static long F_23 ( struct V_18 * V_18 , unsigned int V_30 , unsigned long V_31 )
{
void T_2 * V_32 = ( void T_2 * ) V_31 ;
int T_2 * V_33 = V_32 ;
static const struct V_34 V_35 = {
. V_36 = V_37 | V_38
| V_39 ,
. V_40 = 1 ,
. V_41 = L_5 ,
} ;
switch ( V_30 ) {
case V_42 :
return F_24 ( V_32 , & V_35 , sizeof( V_35 ) ) ? - V_26 : 0 ;
case V_43 :
case V_44 :
return F_25 ( 0 , V_33 ) ;
case V_45 :
{
int V_46 , V_47 = - V_48 ;
if ( F_17 ( V_46 , V_33 ) )
return - V_26 ;
if ( V_46 & V_49 ) {
F_13 () ;
V_47 = 0 ;
}
if ( V_46 & V_50 ) {
F_12 () ;
V_47 = 0 ;
}
return V_47 ;
}
case V_51 :
F_15 () ;
return 0 ;
case V_52 :
{
int V_53 ;
if ( F_17 ( V_53 , V_33 ) )
return - V_26 ;
if ( V_53 < 1 || V_53 > 3600 )
return - V_48 ;
V_14 = V_53 ;
F_15 () ;
}
case V_54 :
return F_25 ( V_14 , V_33 ) ;
default:
return - V_55 ;
}
}
static int F_26 ( struct V_56 * V_57 , unsigned long V_58 ,
void * V_59 )
{
if ( V_58 == V_60 || V_58 == V_61 )
F_13 () ;
return V_62 ;
}
static void T_5 F_27 ( void )
{
F_13 () ;
F_28 ( & V_63 ) ;
F_29 ( & V_64 ) ;
F_30 ( V_5 , 1 ) ;
F_30 ( V_11 , 2 ) ;
}
static int T_6 F_31 ( void )
{
int V_65 = - V_29 ;
if ( V_14 < 1 || V_14 > 3600 ) {
V_14 = V_66 ;
F_7 (KERN_INFO PFX
L_6 ,
timeout) ;
}
if ( ! F_32 ( V_11 , 2 , L_7 ) ) {
F_7 (KERN_ERR PFX L_8 ,
ENABLE_W83877F_PORT) ;
V_65 = - V_67 ;
goto V_68;
}
if ( ! F_32 ( V_5 , 1 , L_9 ) ) {
F_7 (KERN_ERR PFX L_8 ,
WDT_PING) ;
V_65 = - V_67 ;
goto V_69;
}
V_65 = F_33 ( & V_64 ) ;
if ( V_65 ) {
F_7 (KERN_ERR PFX
L_10 , rc) ;
goto V_70;
}
V_65 = F_34 ( & V_63 ) ;
if ( V_65 ) {
F_7 (KERN_ERR PFX
L_11 ,
wdt_miscdev.minor, rc) ;
goto V_71;
}
F_7 (KERN_INFO PFX
L_12 ,
timeout, nowayout) ;
return 0 ;
V_71:
F_29 ( & V_64 ) ;
V_70:
F_30 ( V_5 , 1 ) ;
V_69:
F_30 ( V_11 , 2 ) ;
V_68:
return V_65 ;
}
