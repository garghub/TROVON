static void F_1 ( void )
{
if ( F_2 ( V_1 , & V_2 ) ) {
F_3 ( V_3 ) ;
F_4 (KERN_INFO SBC7240_PREFIX
L_1 ) ;
}
}
static void F_5 ( void )
{
if ( ! F_6 ( V_1 , & V_2 ) ) {
F_3 ( V_4 ) ;
F_4 (KERN_INFO SBC7240_PREFIX
L_2 ) ;
}
}
static int F_7 ( int V_5 )
{
if ( V_5 < 1 || V_5 > V_6 ) {
F_4 (KERN_ERR SBC7240_PREFIX
L_3 ,
SBC7240_MAX_TIMEOUT) ;
return - 1 ;
}
F_8 ( ( unsigned ) V_5 , V_7 ) ;
V_8 = V_5 ;
F_4 (KERN_INFO SBC7240_PREFIX L_4 , t) ;
return 0 ;
}
static inline void F_9 ( void )
{
if ( F_10 ( V_1 , & V_2 ) )
F_3 ( V_4 ) ;
}
static T_1 F_11 ( struct V_9 * V_9 , const char T_2 * V_10 ,
T_3 V_11 , T_4 * V_12 )
{
T_3 V_13 ;
char V_14 ;
if ( V_11 ) {
if ( ! V_15 ) {
F_12 ( V_16 ,
& V_2 ) ;
for ( V_13 = 0 ; V_13 != V_11 ; V_13 ++ ) {
if ( F_13 ( V_14 , V_10 + V_13 ) )
return - V_17 ;
if ( V_14 == V_18 ) {
F_14 ( V_16 ,
& V_2 ) ;
break;
}
}
}
F_9 () ;
}
return V_11 ;
}
static int F_15 ( struct V_19 * V_19 , struct V_9 * V_9 )
{
if ( F_6 ( V_20 , & V_2 ) )
return - V_21 ;
F_5 () ;
return F_16 ( V_19 , V_9 ) ;
}
static int F_17 ( struct V_19 * V_19 , struct V_9 * V_9 )
{
if ( F_2 ( V_16 , & V_2 )
|| ! V_15 ) {
F_1 () ;
} else {
F_4 (KERN_CRIT SBC7240_PREFIX
L_5 ) ;
F_9 () ;
}
F_12 ( V_20 , & V_2 ) ;
return 0 ;
}
static long F_18 ( struct V_9 * V_9 , unsigned int V_22 , unsigned long V_23 )
{
switch ( V_22 ) {
case V_24 :
return F_19 ( ( void T_2 * ) V_23 , & V_25 , sizeof( V_25 ) )
? - V_17 : 0 ;
case V_26 :
case V_27 :
return F_20 ( 0 , ( int T_2 * ) V_23 ) ;
case V_28 :
{
int V_29 ;
int V_30 = - V_31 ;
if ( F_13 ( V_29 , ( int T_2 * ) V_23 ) )
return - V_17 ;
if ( V_29 & V_32 ) {
F_1 () ;
V_30 = 0 ;
}
if ( V_29 & V_33 ) {
F_5 () ;
V_30 = 0 ;
}
return V_30 ;
}
case V_34 :
F_9 () ;
return 0 ;
case V_35 :
{
int V_36 ;
if ( F_13 ( V_36 , ( int T_2 * ) V_23 ) )
return - V_17 ;
if ( F_7 ( V_36 ) )
return - V_31 ;
}
case V_37 :
return F_20 ( V_8 , ( int T_2 * ) V_23 ) ;
default:
return - V_38 ;
}
}
static int F_21 ( struct V_39 * V_40 , unsigned long V_41 ,
void * V_42 )
{
if ( V_41 == V_43 || V_41 == V_44 )
F_1 () ;
return V_45 ;
}
static void T_5 F_22 ( void )
{
F_4 (KERN_INFO SBC7240_PREFIX L_6 ) ;
F_23 ( & V_46 ) ;
F_24 ( & V_47 ) ;
F_25 ( V_4 , 1 ) ;
}
static int T_6 F_26 ( void )
{
int V_48 = - V_21 ;
if ( ! F_27 ( V_4 , 1 , L_7 ) ) {
F_4 (KERN_ERR SBC7240_PREFIX
L_8 ,
SBC7240_ENABLE_PORT) ;
V_48 = - V_49 ;
goto V_50;
}
if ( V_8 < 1 || V_8 > V_6 ) {
V_8 = V_51 ;
F_4 (KERN_INFO SBC7240_PREFIX
L_9 ,
SBC7240_MAX_TIMEOUT, timeout) ;
}
F_7 ( V_8 ) ;
F_1 () ;
V_48 = F_28 ( & V_47 ) ;
if ( V_48 ) {
F_4 (KERN_ERR SBC7240_PREFIX
L_10 , rc) ;
goto V_52;
}
V_48 = F_29 ( & V_46 ) ;
if ( V_48 ) {
F_4 (KERN_ERR SBC7240_PREFIX
L_11 ,
wdt_miscdev.minor, rc) ;
goto V_53;
}
F_4 (KERN_INFO SBC7240_PREFIX
L_12 ,
nowayout) ;
return 0 ;
V_53:
F_24 ( & V_47 ) ;
V_52:
F_25 ( V_4 , 1 ) ;
V_50:
return V_48 ;
}
