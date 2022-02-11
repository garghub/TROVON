static void F_1 ( void )
{
F_2 ( 1 , V_1 ) ;
}
static void F_3 ( void )
{
F_2 ( 0 , V_1 ) ;
F_4 (KERN_INFO PFX L_1 ) ;
}
static void F_5 ( void )
{
F_2 ( 1 , V_2 ) ;
}
static int F_6 ( struct V_3 * V_3 , struct V_4 * V_4 )
{
if ( V_5 )
return - V_6 ;
if ( V_7 )
F_7 ( V_8 ) ;
F_1 () ;
F_5 () ;
V_5 = 1 ;
F_4 ( V_9 L_2 ) ;
return F_8 ( V_3 , V_4 ) ;
}
static int F_9 ( struct V_3 * V_3 , struct V_4 * V_4 )
{
if ( ! V_7 )
F_3 () ;
V_5 = 0 ;
return 0 ;
}
static T_1 F_10 ( struct V_4 * V_4 , const char T_2 * V_10 ,
T_3 V_11 , T_4 * V_12 )
{
if ( V_11 )
F_5 () ;
return V_11 ;
}
static long F_11 ( struct V_4 * V_4 , unsigned int V_13 ,
unsigned long V_14 )
{
int V_15 , V_16 = - V_17 ;
int T_2 * V_18 = ( void T_2 * ) V_14 ;
static const struct V_19 V_20 = {
. V_15 = V_21 ,
. V_22 = 0 ,
. V_23 = L_3 ,
} ;
switch ( V_13 ) {
case V_24 :
if ( F_12 ( V_18 , & V_20 , sizeof( V_20 ) ) )
return - V_25 ;
return 0 ;
case V_26 :
case V_27 :
return F_13 ( 0 , V_18 ) ;
case V_28 :
if ( F_14 ( V_15 , V_18 ) )
return - V_25 ;
if ( V_15 & V_29 ) {
F_3 () ;
V_16 = 0 ;
}
if ( V_15 & V_30 ) {
F_1 () ;
V_16 = 0 ;
}
return V_16 ;
case V_31 :
F_5 () ;
return 0 ;
case V_32 :
return F_13 ( V_33 , V_18 ) ;
default:
return - V_34 ;
}
}
static int F_15 ( struct V_35 * V_36 , unsigned long V_37 ,
void * V_38 )
{
if ( V_37 == V_39 || V_37 == V_40 )
F_3 () ;
return V_41 ;
}
static int T_5 F_16 ( void )
{
int V_42 ;
if ( ! F_17 ( V_1 , 2 , L_4 ) )
return - V_6 ;
V_42 = F_18 ( & V_43 ) ;
if ( V_42 ) {
F_4 (KERN_ERR PFX L_5
L_6 , ret) ;
goto V_44;
}
V_42 = F_19 ( & V_45 ) ;
if ( V_42 ) {
F_4 (KERN_ERR PFX L_7
L_6 , WATCHDOG_MINOR, ret) ;
F_20 ( & V_43 ) ;
goto V_44;
}
F_4 ( V_46 ) ;
return 0 ;
V_44:
F_21 ( V_1 , 2 ) ;
return V_42 ;
}
static void T_6 F_22 ( void )
{
F_23 ( & V_45 ) ;
F_20 ( & V_43 ) ;
F_21 ( V_1 , 2 ) ;
}
