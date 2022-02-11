static void F_1 ( void )
{
F_2 ( & V_1 ) ;
V_2 -> V_3 |= V_4 ;
F_3 ( & V_1 ) ;
}
static void F_4 ( void )
{
F_2 ( & V_1 ) ;
V_2 -> V_3 &= ~ V_4 ;
F_3 ( & V_1 ) ;
F_5 ( L_1 ) ;
}
static void F_6 ( void )
{
V_2 -> V_5 = 0 ;
}
static int F_7 ( struct V_6 * V_6 , struct V_7 * V_7 )
{
if ( F_8 ( 0 , & V_8 ) )
return - V_9 ;
if ( V_10 )
F_9 ( V_11 ) ;
F_1 () ;
F_6 () ;
F_5 ( L_2 ) ;
return F_10 ( V_6 , V_7 ) ;
}
static int F_11 ( struct V_6 * V_6 , struct V_7 * V_7 )
{
if ( ! V_10 )
F_4 () ;
F_12 ( 0 , & V_8 ) ;
return 0 ;
}
static T_1 F_13 ( struct V_7 * V_7 , const char * V_12 ,
T_2 V_13 , T_3 * V_14 )
{
if ( V_13 )
F_6 () ;
return V_13 ;
}
static long F_14 ( struct V_7 * V_7 , unsigned int V_15 ,
unsigned long V_16 )
{
int V_17 , V_18 = - V_19 ;
static const struct V_20 V_21 = {
. V_17 = V_22 ,
. V_23 = 0 ,
. V_24 = L_3 ,
} ;
switch ( V_15 ) {
case V_25 :
if ( F_15 ( (struct V_20 * ) V_16 ,
& V_21 , sizeof( V_21 ) ) )
return - V_26 ;
return 0 ;
case V_27 :
case V_28 :
return F_16 ( 0 , ( int * ) V_16 ) ;
case V_29 :
{
if ( F_17 ( V_17 , ( int * ) V_16 ) )
return - V_26 ;
if ( V_17 & V_30 ) {
F_4 () ;
V_18 = 0 ;
}
if ( V_17 & V_31 ) {
F_1 () ;
V_18 = 0 ;
}
return V_18 ;
}
case V_32 :
F_6 () ;
return 0 ;
case V_33 :
return F_16 ( V_34 , ( int * ) V_16 ) ;
default:
return - V_35 ;
}
}
static int F_18 ( struct V_36 * V_37 ,
unsigned long V_38 , void * V_39 )
{
if ( V_38 == V_40 || V_38 == V_41 )
F_4 () ;
return V_42 ;
}
static int T_4 F_19 ( void )
{
int V_43 ;
V_43 = F_20 ( & V_44 ) ;
if ( V_43 ) {
F_21 ( L_4 , V_43 ) ;
return V_43 ;
}
V_43 = F_22 ( & V_45 ) ;
if ( V_43 ) {
F_21 ( L_5 ,
V_46 , V_43 ) ;
F_23 ( & V_44 ) ;
return V_43 ;
}
F_5 ( L_6 ) ;
return 0 ;
}
static void T_5 F_24 ( void )
{
F_25 ( & V_45 ) ;
F_23 ( & V_44 ) ;
}
