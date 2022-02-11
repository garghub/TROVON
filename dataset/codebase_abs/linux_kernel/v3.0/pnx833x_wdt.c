static void F_1 ( void )
{
F_2 ( V_1 + V_2 ) |= 0x1 ;
F_2 ( V_3 +
V_4 ) = V_5 ;
F_2 ( V_3 +
V_6 ) |= 0x1 ;
F_3 (KERN_INFO PFX L_1 ) ;
}
static void F_4 ( void )
{
F_2 ( V_1 + V_3 ) &= 0xFFFFFFFE ;
F_2 ( V_3 +
V_6 ) &= 0xFFFFFFFE ;
F_3 (KERN_INFO PFX L_2 ) ;
}
static void F_5 ( void )
{
F_2 ( V_3 +
V_4 ) = V_5 ;
}
static int F_6 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
if ( F_7 ( 0 , & V_9 ) )
return - V_10 ;
if ( V_11 )
F_8 ( V_12 ) ;
if ( ! V_13 )
F_1 () ;
F_5 () ;
F_3 ( V_14 L_1 ) ;
return F_9 ( V_7 , V_8 ) ;
}
static int F_10 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
if ( ! V_11 )
F_4 () ;
F_11 ( 0 , & V_9 ) ;
return 0 ;
}
static T_1 F_12 ( struct V_8 * V_8 , const char * V_15 , T_2 V_16 , T_3 * V_17 )
{
if ( V_16 )
F_5 () ;
return V_16 ;
}
static long F_13 ( struct V_8 * V_8 , unsigned int V_18 ,
unsigned long V_19 )
{
int V_20 , V_21 = 0 ;
T_4 V_22 , V_23 = 0 ;
static const struct V_24 V_25 = {
. V_20 = V_26 | V_27 ,
. V_28 = 0 ,
. V_29 = L_3 ,
} ;
switch ( V_18 ) {
default:
return - V_30 ;
case V_31 :
if ( F_14 ( (struct V_24 * ) V_19 ,
& V_25 , sizeof( V_25 ) ) )
return - V_32 ;
return 0 ;
case V_33 :
case V_34 :
return F_15 ( 0 , ( int * ) V_19 ) ;
case V_35 :
if ( F_16 ( V_20 , ( int * ) V_19 ) )
return - V_32 ;
if ( V_20 & V_36 )
F_4 () ;
if ( V_20 & V_37 )
F_1 () ;
return 0 ;
case V_38 :
F_5 () ;
return 0 ;
case V_39 :
{
if ( F_16 ( V_21 , ( int * ) V_19 ) )
return - V_32 ;
V_5 = V_21 ;
F_2 ( V_3 +
V_4 ) = V_21 ;
return F_15 ( V_21 , ( int * ) V_19 ) ;
}
case V_40 :
V_22 = F_2 ( V_3 +
V_4 ) ;
return F_15 ( V_22 , ( int * ) V_19 ) ;
case V_41 :
V_23 = F_2 ( V_3 +
V_42 ) ;
return F_15 ( V_23 , ( int * ) V_19 ) ;
}
}
static int F_17 ( struct V_43 * V_44 ,
unsigned long V_45 , void * V_46 )
{
if ( V_45 == V_47 || V_45 == V_48 )
F_4 () ;
return V_49 ;
}
static int T_5 F_18 ( void )
{
int V_50 , V_51 ;
V_51 = F_2 ( V_1 ) ;
if ( V_51 & 0x80000000 ) {
F_3 (KERN_INFO PFX L_4
L_5 ) ;
}
V_50 = F_19 ( & V_52 ) ;
if ( V_50 ) {
F_3 (KERN_ERR PFX
L_6 , ret) ;
return V_50 ;
}
V_50 = F_20 ( & V_53 ) ;
if ( V_50 ) {
F_3 (KERN_ERR PFX
L_7 ,
WATCHDOG_MINOR, ret) ;
F_21 ( & V_52 ) ;
return V_50 ;
}
F_3 ( V_54 ) ;
if ( V_13 )
F_1 () ;
return 0 ;
}
static void T_6 F_22 ( void )
{
F_23 ( & V_53 ) ;
F_21 ( & V_52 ) ;
}
