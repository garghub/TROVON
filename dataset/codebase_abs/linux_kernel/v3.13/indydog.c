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
F_5 ( L_1 ) ;
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
F_5 ( L_2 ) ;
return F_10 ( V_7 , V_8 ) ;
}
static int F_11 ( struct V_7 * V_7 , struct V_8 * V_8 )
{
if ( ! V_11 )
F_4 () ;
F_12 ( 0 , & V_9 ) ;
return 0 ;
}
static T_2 F_13 ( struct V_8 * V_8 , const char * V_13 ,
T_3 V_14 , T_4 * V_15 )
{
if ( V_14 )
F_6 () ;
return V_14 ;
}
static long F_14 ( struct V_8 * V_8 , unsigned int V_16 ,
unsigned long V_17 )
{
int V_18 , V_19 = - V_20 ;
static const struct V_21 V_22 = {
. V_18 = V_23 ,
. V_24 = 0 ,
. V_25 = L_3 ,
} ;
switch ( V_16 ) {
case V_26 :
if ( F_15 ( (struct V_21 * ) V_17 ,
& V_22 , sizeof( V_22 ) ) )
return - V_27 ;
return 0 ;
case V_28 :
case V_29 :
return F_16 ( 0 , ( int * ) V_17 ) ;
case V_30 :
{
if ( F_17 ( V_18 , ( int * ) V_17 ) )
return - V_27 ;
if ( V_18 & V_31 ) {
F_4 () ;
V_19 = 0 ;
}
if ( V_18 & V_32 ) {
F_1 () ;
V_19 = 0 ;
}
return V_19 ;
}
case V_33 :
F_6 () ;
return 0 ;
case V_34 :
return F_16 ( V_35 , ( int * ) V_17 ) ;
default:
return - V_36 ;
}
}
static int F_18 ( struct V_37 * V_38 ,
unsigned long V_39 , void * V_40 )
{
if ( V_39 == V_41 || V_39 == V_42 )
F_4 () ;
return V_43 ;
}
static int T_5 F_19 ( void )
{
int V_44 ;
V_44 = F_20 ( & V_45 ) ;
if ( V_44 ) {
F_21 ( L_4 , V_44 ) ;
return V_44 ;
}
V_44 = F_22 ( & V_46 ) ;
if ( V_44 ) {
F_21 ( L_5 ,
V_47 , V_44 ) ;
F_23 ( & V_45 ) ;
return V_44 ;
}
F_5 ( L_6 ) ;
return 0 ;
}
static void T_6 F_24 ( void )
{
F_25 ( & V_46 ) ;
F_23 ( & V_45 ) ;
}
