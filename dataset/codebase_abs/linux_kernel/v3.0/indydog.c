static void F_1 ( void )
{
T_1 V_1 ;
F_2 ( & V_2 ) ;
V_1 = V_3 -> V_4 ;
V_1 = V_3 -> V_4 | V_5 ;
V_3 -> V_4 = V_1 ;
F_3 ( & V_2 ) ;
}
static void F_4 ( void )
{
T_1 V_1 ;
F_2 ( & V_2 ) ;
V_1 = V_3 -> V_4 ;
V_1 &= ~ V_5 ;
V_3 -> V_4 = V_1 ;
F_3 ( & V_2 ) ;
F_5 (KERN_INFO PFX L_1 ) ;
}
static void F_6 ( void )
{
V_3 -> V_6 = 0 ;
}
static int F_7 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
if ( F_8 ( 0 , & V_9 ) )
return - V_10 ;
if ( V_11 )
F_9 ( V_12 ) ;
F_1 () ;
F_6 () ;
F_5 ( V_13 L_2 ) ;
return F_10 ( V_7 , V_8 ) ;
}
static int F_11 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
if ( ! V_11 )
F_4 () ;
F_12 ( 0 , & V_9 ) ;
return 0 ;
}
static T_2 F_13 ( struct V_8 * V_8 , const char * V_14 ,
T_3 V_15 , T_4 * V_16 )
{
if ( V_15 )
F_6 () ;
return V_15 ;
}
static long F_14 ( struct V_8 * V_8 , unsigned int V_17 ,
unsigned long V_18 )
{
int V_19 , V_20 = - V_21 ;
static const struct V_22 V_23 = {
. V_19 = V_24 ,
. V_25 = 0 ,
. V_26 = L_3 ,
} ;
switch ( V_17 ) {
case V_27 :
if ( F_15 ( (struct V_22 * ) V_18 ,
& V_23 , sizeof( V_23 ) ) )
return - V_28 ;
return 0 ;
case V_29 :
case V_30 :
return F_16 ( 0 , ( int * ) V_18 ) ;
case V_31 :
{
if ( F_17 ( V_19 , ( int * ) V_18 ) )
return - V_28 ;
if ( V_19 & V_32 ) {
F_4 () ;
V_20 = 0 ;
}
if ( V_19 & V_33 ) {
F_1 () ;
V_20 = 0 ;
}
return V_20 ;
}
case V_34 :
F_6 () ;
return 0 ;
case V_35 :
return F_16 ( V_36 , ( int * ) V_18 ) ;
default:
return - V_37 ;
}
}
static int F_18 ( struct V_38 * V_39 ,
unsigned long V_40 , void * V_41 )
{
if ( V_40 == V_42 || V_40 == V_43 )
F_4 () ;
return V_44 ;
}
static int T_5 F_19 ( void )
{
int V_45 ;
F_20 ( & V_2 ) ;
V_45 = F_21 ( & V_46 ) ;
if ( V_45 ) {
F_5 (KERN_ERR PFX
L_4 , ret) ;
return V_45 ;
}
V_45 = F_22 ( & V_47 ) ;
if ( V_45 ) {
F_5 (KERN_ERR PFX
L_5 ,
WATCHDOG_MINOR, ret) ;
F_23 ( & V_46 ) ;
return V_45 ;
}
F_5 ( V_48 ) ;
return 0 ;
}
static void T_6 F_24 ( void )
{
F_25 ( & V_47 ) ;
F_23 ( & V_46 ) ;
}
